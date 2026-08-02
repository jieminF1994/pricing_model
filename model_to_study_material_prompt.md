# Instruction: Turn pricing_model Code into Study Material

Reusable prompt for converting a formula/calculation inside a `pricing_model` UDF source
file (`modelClass/*.cpp`, e.g. `pricing_faia`, `pricing_rila`) into a self-contained HTML
study page, in the style of the Coaching Actuaries "Learn" manuals (Introduction →
Explain the Calculation → Coach's Remark → Summary → Concept Checker).

Paste this whole file as the system/task instruction, then tell me:
- **Model file(s):** path(s) to the source, e.g.
  `pricing_faia/modelClass/fiaafund_liab.cpp` (pass more than one path when the same
  column should be compared across models, e.g. `pricing_faia` vs. `pricing_rila`)
- **Target formula/concept:** the column name(s) or UDF name(s) to explain (e.g.
  `crediting_rate`, `strategy_return_aig`)

---

## 1. Role

Act as an instructor writing an exam-prep-quality study page that explains **one
self-contained calculation** taken from a real model's source code. The audience already
knows calculus/probability but has never seen this specific model file. The goal is to
turn code (loops, if/else, array indexing, helper-function calls) into standard
mathematical notation, and to explain *why* the formula is built that way, not just what
it computes.

## 2. Process before writing

1. Locate the requested formula(s) in the model file. `pricing_model`'s `modelClass/*.cpp`
   files use one consistent convention: each column is a plain C++ function named
   `<TABLE>_UDF::<table>_<column>(int t)`, bracketed by `//@@ START - <column>` /
   `//@@ END` comments and a `#line 1 "<column>.<TABLE>.for"` pragma marking where the
   original DSL-generated body begins — read that body verbatim, it's already plain text,
   nothing to unescape. Path-dependence shows up as **explicit recursion**: the function
   calling itself with `(t - 1)` (e.g. `strategy_return_aig(index_term_start_duration_aig(t) - 1)`),
   or calling a sibling `*_cumul_aig`/`*_bom_aig` column that itself recurses on `t - 1`.
   Treat a leading `if (t <= commencement_period ...) return NO_AVG;` (or similar
   period-window guard) as a domain restriction, not a base case, unless a distinct branch
   sets a genuine initial value (e.g. `if (t == commencement_period + 1) return 1;`). A
   leading `if (isRebaseClone && sm_peer_model && t <= rebase_period) return
   rebase_value(...);` block is infrastructure for mid-projection model rebasing, not part
   of the economic formula — mention it exists but don't dwell on it, and don't display it
   as a numbered equation. Trace the *whole* calculation chain: a column formula often
   calls a UDF, which calls another UDF, which reads another column, possibly defined in a
   sibling file (e.g. a `crbg`-suffixed column added on a feature branch) — follow all of
   it before writing anything.
   **Cross-model comparison:** when the same column name is requested from more than one
   model directory (e.g. `pricing_faia` vs. `pricing_rila`), trace and present each
   separately, but explicitly note where one is a strict superset, refactor, or special
   case of the other (e.g. "the RILA version delegates to a shared `_index_aig` helper
   and adds a `rila_ind` branch that FAIA doesn't have") rather than treating them as
   unrelated formulas.
2. Identify:
   - What real-world quantity this formula represents (a price, a rate, a trigger
     condition, a projected cashflow, a calibration input, etc.)
   - Its inputs — trace each to a model `<input>`, another column, a UDF parameter, or a
     hardcoded constant
   - Any branching logic (`if/elif/else`, `switch/case`) — these become piecewise
     definitions
   - Any loops over an index (`$row`, `$index`, `for i = 0 to N`) — these become
     summations, products, or vector/array notation with a subscript
   - Any recursion (e.g. `gmab_binomial` calling itself) — flag this explicitly; it needs
     a recursive definition, not a closed form
3. Do not silently "clean up" or simplify the logic. If the code has a quirk (e.g. a
   magic number, an odd interpolation choice, a placeholder), keep it and explain it in
   the Coach's Remark rather than smoothing it over.

## 3. Code → math translation rules

| Code pattern | Math notation |
|---|---|
| `for (int i = 0; i < N; i++) result[i] = ...` | Define the sequence/vector element-wise: $x_i$ for $i = 0, \dots, N-1$ |
| `for (...) sum += ...` | $\sum_{i} (\cdot)$ |
| `if (cond) { A } else { B }` | Piecewise, LHS-label-then-brace-then-cases (see the `.piecewise` HTML pattern in §5 — the label such as $x_t =$ must sit to the **left** of the brace, not trail after the cases) |
| `switch (idx) { case FOO: ... case BAR: ... }` / chained `if (x == ENUM_A) ... else if (x == ENUM_B) ...` | Piecewise indexed by the enum's name (e.g. "Dynamic Cap", "Dynamic Trigger") rather than its raw integer value |
| array `x[i]` / `x[i][j]` | Subscript: $x_{i,j}$ or, for a named tenor/value pair, $x(t_i)$ |
| `interp1` / `interp1_constant` / a hand-rolled bracketing-tenor lookup | Standard piecewise-linear interpolation formula between the two bracketing tenor points, with flat extrapolation stated explicitly if that's what the code does |
| `erf`, `compute_black_scholes`, `Φ`-style normal CDF via `erf` | Rewrite using $\Phi(\cdot)$, the standard normal CDF, and state the identity $\Phi(x) = \tfrac{1}{2}\left(1+\operatorname{erf}(x/\sqrt2)\right)$ once, in a Coach's Remark, rather than repeating it |
| a column calling itself, e.g. `strategy_return_aig(t - 1)` or `strategy_return_aig(index_term_start_duration_aig(t) - 1)` | Define recursively: $V(t) = f(t, V(t-1))$ or similar, with the base/guard case spelled out |
| projection index `t`, a duration/count column like `pol_yr(t)`, `elapsed_mths` | Use consistent subscripts: projection month $\to$ $t$, a helper duration $\to$ $s$ or a named label |
| named constants (`0.083333`, `1e-6`, `SMALL_DOUBLE`) | Keep the numeric value but say what it represents (e.g. "$1/12$, one month in years") |
| a model input accessed via `fia->x` or a bare descriptor-table field (e.g. `crediting_rate_defn`, `prog_trigger_barrier_level_crbg`) | Introduce it as a named model parameter the first time it appears, and reuse that name afterward |

Keep one notation convention per document and state it once near the top (e.g. "obligor/step
index $n$, time $t$, calibrated parameters in Greek letters, model outputs in Latin
letters").

## 4. Output format

Deliver a single self-contained HTML file (no external CDN/script dependencies — this
must render offline; a small inline `<script>` with plain vanilla JS and no external
libraries is fine, and is required for the code window's drag-to-resize handle — CSS-only
`:checked ~` tricks cover the tabs/theme-switch/hide-show toggle, but there's no CSS-only
way to make an entire edge draggable). The page is a two-column layout: the study content on the left,
and a sticky, **hideable** **original-code side panel** on the right showing the actual
source the page is explaining — so the reader can check every equation against its
source line by line without leaving the page, or hide it entirely to read the content at
full width. Structure:

```html
<input class="rail-switch" type="checkbox" id="code-toggle">
<div class="layout">
  <div class="content">
    <section id="introduction">...</section>
    <section id="explain-the-calculation">...</section>
    <!-- one or more "coach's-remark" boxes appear inline, wherever a subtlety needs it -->
    <section id="summary">...</section>
    <section id="concept-checker">...</section>
  </div>
  <div class="code-rail">
    <!-- .rail-drag (resize handle), .rail-toolbar (theme swatches + hide/show button),
         then .code-box, see below -->
  </div>
</div>
```

`#code-toggle` must be a sibling of `.layout` (both children of `<body>`, in that order)
so `#code-toggle:checked ~ .layout` can reach descendants on either side at once. The
hide/show button lives in `.rail-toolbar`, the header row **at the top of the code
window itself, to the right of the theme swatches** — not in `.content` — and toggling
it hides the `.theme-switch`, `.code-box` (tabs + source), and `.rail-hint` together as
one unit, so the whole code window — theme control included — collapses in sync. The
button itself is the one child of `.rail-toolbar` that's never targeted by the hidden
selector, so it's always there to bring the panel back; if the checked state hid the
whole `.code-rail` instead, the only control that could re-check the checkbox would
disappear with it. `.content` still reclaims most of the freed width once the rail's
contents are gone (see §5) — `.code-rail` itself just shrinks down to the button's
width rather than vanishing. The button reads "Hide code ▸" by default and swaps to
"Show code ◂" once
checked.

`.code-rail` must be a **direct flex child of `.layout`** — never nest it inside an
intermediate wrapper `<div>`. A `position: sticky` element's travel range (how far it can
stay pinned while the page scrolls) is bounded by its **containing block**, which for a
sticky element is its nearest block-level ancestor. If `.code-rail` is a direct child of
`.layout`, that ancestor is `.layout` itself — which is exactly as tall as `.content`
(the flex container's height tracks its tallest child), giving the sticky panel a long
runway to stay pinned near the top of the viewport while the reader scrolls through the
much longer study content. Wrap `.code-rail` in its own `<div>` and that wrapper becomes
the containing block instead; since the wrapper's own height collapses to exactly match
`.code-rail`'s height (nothing else inside it takes up room), sticky has zero travel room
left and the "sticky" panel just scrolls away with the page like a normal block — this
produces no error, only a panel that silently stops following the scroll. See "Resizing
the code window" below for why this matters even for the resize handle (it's tempting to
introduce a wrapper specifically to solve the handle's clipping problem — don't; there's
a wrapper-free fix).

### Equation layout — self-contained, non-wrapping, independently scrollable (required)

Every display equation — piecewise, derivation, or plain — must be wrapped in its own
bordered `.equation-frame` box with its own horizontal scrollbar (see the `.eq-scroll`
pattern in §5), exactly like a miniature version of the code panel. This matters because
`.code-rail` is user-resizable (drag-anywhere-on-the-left-edge, see "Resizing the code
window" below) and `.content` shrinks to accommodate it — without an independent
scroll container, a long piecewise table or a wide algebraic step gets visually squeezed
and wraps mid-expression as the reader drags the code panel wider. With
`.equation-frame`, each formula keeps its natural
(non-wrapping) width and reveals a horizontal scrollbar only when it doesn't fit, instead
of reflowing. The equation number stays pinned to the frame's top-right corner (outside
the scrolling region) so it's visible even when the reader has scrolled the formula body
sideways.

### Original-code side panel (required)

- Include the **verbatim, unescaped** source for every column formula and UDF discussed
  on the page — not a paraphrase. If more than one code block is relevant (e.g. a column
  formula plus the UDF(s) it calls), put each in its own CSS-only tab (radio-button
  tabs, no JS needed) inside the same panel so the reader can flip between them.
  Label each tab with the formula/UDF name, and put the table name and file path in a
  small header above the tabs.
  **Row-group choice:** per §2, when a tabbed column has both an `rg1` and an
  `rg2`-or-later definition, the tab shows the **rg2-or-later (general/recursive)**
  source by default — it's what the "Explain the Calculation" text is actually walking
  through. If `rg1` sets a real initial condition worth showing verbatim, either fold it
  into the same tab as a one-line "day-1 seed: `<code>`" note above the recursive code,
  or give it its own small tab labeled e.g. "`account_val_par_rate_5y` (t=0 seed)" — don't
  silently drop it, and don't let it replace the rg2 formula as the tab's main content.
  **Markup gotcha (verified the hard way):** the `#tabN:checked ~ .code-panes #paneN`
  sibling selector only works if the `<input type="radio">` elements are *direct
  siblings of* `.code-panes` (i.e. both direct children of `.code-box`). Do **not**
  nest the radios inside `.code-tabs` alongside the `<label>`s — the `~` combinator
  can't reach across that extra nesting level and the panes silently never show. Keep
  the `<label>`s inside `.code-tabs` for layout, but the `<input>`s must sit as
  siblings of `.code-panes`, before it in document order. Structure:
  `.code-box > .code-head, input#tab1, input#tab2, ..., .code-tabs (labels only), .code-panes`.
  After writing this panel, mentally trace the CSS selector against the actual DOM
  nesting before moving on — this bug produces no error, just a permanently-empty panel.
- **Second markup gotcha, same root cause:** hiding the radio inputs with a
  *descendant* selector like `.code-tabs input { display: none }` breaks the moment the
  inputs move out of `.code-tabs` (per the gotcha above) — the raw radio buttons then
  render on the page as literal dots, one of which shows the browser's native
  "checked" color depending on which tab/theme is active. Give every CSS-only
  radio a dedicated class (e.g. `.rail-switch`) and hide it with a selector that does
  **not** depend on nesting: `.rail-switch { position: fixed; top: 0; left: 0; opacity: 0;
  width: 0; height: 0; pointer-events: none; }` — use `fixed` with explicit `top`/`left`,
  not `absolute` with none; see the **third markup gotcha** below for why. Same applies
  to the *active-tab/theme highlight*:
  since the input and its label are no longer adjacent siblings, don't rely on
  `input:checked + label` — instead use the combined-combinator form
  `#tab1:checked ~ .code-tabs label[for="tab1"] { ... }`, which is valid CSS (the `~`
  only needs to reach `.code-tabs`; the label lookup inside it is an ordinary
  descendant selector). This is what naturally shows which formula/theme is active —
  a bold color + underline on the corresponding label — with no visible form control
  at all.
- **Third markup gotcha (verified the hard way):** `.rail-switch { position: absolute; }`
  with no explicit offsets leaves each hidden input at its *static* position in the
  document flow — and `#code-toggle` in particular is the very first element in `<body>`,
  before `.layout`, so its static position is the very top of the page. Clicking any
  `<label for="...">` focuses the associated input for accessibility, and a browser will
  scroll a newly-focused element into view if it isn't already visible. With `position:
  absolute` and no offsets, that meant clicking the hide/show button — or a theme
  swatch, or a code tab, anywhere on the page — silently snapped the whole page back to
  the top, discarding the reader's scroll position. `position: fixed` with explicit
  `top: 0; left: 0;` pins every hidden input to a fixed viewport coordinate that's
  always "in view," so focusing it never triggers a scroll. This bug produces no error
  and no visual artifact on the control itself — it only shows up as an unexplained
  jump-to-top on click — so specifically test "click a toggle/tab/swatch while scrolled
  partway down the page" after adding any new CSS-only radio or checkbox.
- Preserve original line breaks and indentation from the unescaped source, and apply
  syntax coloring with plain `<span>` classes (no JS syntax highlighter) so the code
  reads at a glance rather than as a wall of uniform monospace text. Use four classes,
  consistently, on every code block in the panel:
  - `.cm` — comments (`//...`, `/* ... */`), dimmed and italic
  - `.kw` — control-flow keywords: `if` `then` `elif` `else` `end` `for` `to` `return`
    (also `switch`/`case` if the DSL uses them)
  - `.nm` — function calls: both user-defined UDFs (`gmab_binomial`,
    `undiscounted_black_scholes`, `SafeDivide`, ...) and built-in math functions
    (`max`, `min`, `sqrt`, `log`, `exp`, `round`, `abs`, `interp1_constant`, ...) — one
    color is enough to distinguish "a function is being called" from a plain variable
  - `.bl` — boolean literals `True`/`False`, bolded, in their own accent color distinct
    from `.kw` and `.nm` — small but it measurably helps scanning branch conditions
  Numeric literals and variable names stay uncolored (the default `--code-fg`) — coloring
  every token defeats the purpose; the goal is to make keywords/comments/calls/booleans
  pop against plain variable references, not to fully tokenize the language.
- The panel is `position: sticky` on wide viewports so it stays visible while the reader
  scrolls the explanation; it must stack below the content (not disappear) on narrow
  viewports via a media query — never hide it entirely.
- When "Explain the Calculation" references a specific branch or loop (e.g. "see the
  `for k = 0 to n+1` loop"), phrase it so the reader can find that literal text in the
  side panel — this is what makes the panel useful rather than decorative.
- **Theme switch (required):** offer exactly 3 curated color themes for the code panel,
  selectable via small circular swatch buttons (not native radio buttons) above the
  panel: a light "Paper" theme matching the page background (default), "Solarized
  Light" (warm cream, classic blue/gold accents), and a dark "Nord" theme (cool
  blue-gray, frost-cyan accents) for readers who prefer higher contrast on code
  specifically. Implement with CSS custom properties: define `--code-bg`,
  `--code-border`, `--code-fg`, `--code-head-bg`, `--code-head-fg`, `--code-tab-fg`,
  `--code-tab-active-fg`, `--code-tab-active-border`, `--code-cm`, `--code-kw`,
  `--code-nm` on `.code-box` as the Paper defaults, then override the full set with
  `#theme-solarized:checked ~ .code-box { --code-bg: ...; ... }` and
  `#theme-nord:checked ~ .code-box { ... }` — since custom properties inherit, every
  rule that already references `var(--code-bg)` etc. repaints automatically without
  needing per-theme copies of the structural CSS. The 3 theme radios go through the
  same `.rail-switch` treatment as the tab radios above, and must sit as direct
  siblings of `.code-box` (both inside `.code-rail`) for the `~` selector to reach it.
- **Resizing the code window (required):** the reader must be able to drag **anywhere
  along the code window's left edge** to resize it — not just a single corner handle.
  Dragging left enlarges the code window (shrinking the study content); dragging right
  shrinks it (enlarging the study content). This needs a small script (`mousedown` /
  `mousemove` / `mouseup`, plus the `touch*` equivalents) since CSS's native `resize`
  property only ever offers a bottom-right (or bottom, for `resize: vertical`) corner
  handle — there's no CSS-only way to make an entire left edge draggable. The handle
  (`.rail-drag`) is a plain child of `.code-rail`, absolutely positioned at `left: -6px`
  so it hangs off the panel's left border — **do not** solve its clipping-by-overflow
  problem by wrapping `.code-rail` in a separate box (that breaks the sticky panel, per
  the note above); instead set `.code-rail`'s own `overflow: visible` (the actual
  code-scrolling still happens via `.code-panes`'s independent `overflow: auto` further
  in, so nothing is lost). See "Resizable code window" in §5 for the full CSS and the
  script. The hide/show button (above) must still always win: its CSS rule collapsing
  `.code-rail` needs `!important` on `width`/`min-width` so it overrides whatever inline
  `width` the drag script has set, guaranteeing the study content returns to full width
  every time the panel is hidden, regardless of how the reader last resized it.

Visual language to imitate (see reusable CSS block in §5):
- A title bar with the concept name and an estimated read time.
- Section headers in bold, sentence case, dark navy/black on white.
- Sub-subsection headers in smaller bold ALL CAPS (mirrors "HETEROGENEOUS FACTOR LOADINGS"
  style) when a section splits into named cases.
- Every derived formula gets a numbered, centered display equation, numbered
  sequentially within the page (e.g. `(1)`, `(2)`, ...). Later text refers back to
  equation numbers ("Using Equation (3), ...").
- Multi-line derivations align the `=` signs, one step per line, exactly like a textbook
  worked example — don't compress algebra into one line if the code took multiple steps.
  **This applies everywhere algebra appears, including inside Coach's Remark boxes** —
  it's tempting to compress a "quick aside" derivation into a single sentence like
  "substituting X gives Y, so Z," but that's exactly the kind of jump a reader can't
  follow without redoing the algebra themselves. Any time you go from one expression to
  another via more than one algebraic move (substitution, expansion, rearrangement,
  dividing through, splitting a fraction, etc.), show **every intermediate line**, using
  the `.derivation` pattern in §5 — one step per row, with a short right-aligned
  annotation naming the move (e.g. "substitute M₁ = F+1", "expand (F+1)²", "split the
  fraction"). A good test: if you had to write "since ... , substituting gives ..." to
  describe the jump in prose, that jump needs its own derivation block instead.
- Definition lists after every new symbol: "where: • $x$ is ... • $y$ is ...".
- Interpretation bullets after each result ("A higher `spread` implies...", "When
  `run_shocksos` is true, this branch returns 0 because...").
- **Coach's Remark** callout boxes (light tinted background, left border accent, bold
  "Coach's Remark" label) used specifically for:
  - Contrasting this formula with a similar one elsewhere in the model (don't let the
    reader confuse them)
  - Demystifying notation that looks scary but is mechanical (e.g. vector/matrix
    notation, recursive definitions)
  - Flagging when a derivation is included for completeness but isn't essential to
    remember — tell the reader what to actually retain
  - Explaining *why* the code branches the way it does (a business/product reason, not
    just "because the if-statement says so")
- Math notation itself: since the artifact must be self-contained (no MathJax/KaTeX from
  a CDN), typeset equations with styled HTML — italic serif for variables (`<i>`), `<sub>`/`<sup>`
  for subscripts/superscripts, and real Unicode symbols (√ Σ ∫ Φ ρ σ λ θ ξ ε ≤ ≥ → ·) rather than
  LaTeX source. Only use HTML entities that are real named/numeric entities (e.g. `&minus;`,
  `&thinsp;`, `&middot;`) — never invent pseudo-entities like `&binom;` or `&big;`, they render
  as literal text. For binomial coefficients, write `C(n, k)` (matching a `combination(n, k)`
  helper if the code has one) rather than attempting a stacked fraction. For large paired
  brackets, use plain `[` `]` `(` `)` — don't try to fake taller brackets. Keep a consistent
  "equation" CSS class so every display formula lines up and is centered with consistent spacing.

## 5. Reusable CSS skeleton

Use this as the starting `<style>` block (adjust colors/fonts to taste, keep the
structural classes):

```css
* { box-sizing: border-box; }
body { font-family: Georgia, "Times New Roman", serif; line-height: 1.6; color: #1a1a1a; max-width: 1280px; margin: 0 auto; padding: 2rem; }
.layout { display: flex; gap: 2.2rem; align-items: flex-start; }
.content { flex: 1 1 700px; min-width: 0; max-width: 800px; position: relative; transition: max-width .2s ease; }
/* .code-rail is a DIRECT flex child of .layout — do not nest it in an intermediate
   wrapper <div>. A position:sticky element's travel range is bounded by its containing
   block (nearest block-level ancestor); keeping that ancestor as .layout itself (which
   is as tall as .content) is what gives the sticky panel room to stay pinned while the
   reader scrolls the much longer study content. Wrapping .code-rail in its own box was
   tried and reverted — verified the hard way: the wrapper's own height collapses to
   exactly match .code-rail's height (nothing else inside it takes up room), so sticky
   gets zero travel room and the panel silently just scrolls away with the page instead
   of staying put. No error, no warning — the only symptom is "the sticky panel doesn't
   stick." overflow: visible (not auto) on .code-rail is what then lets .rail-drag hang
   off the panel's left edge without being clipped by an overflow-clipping ancestor —
   the actual code-scrolling still happens via .code-panes' own overflow: auto further
   down (see the tabbed-panel CSS below), so nothing is lost by not clipping here. */
.code-rail { flex: 0 0 auto; width: 420px; min-width: 300px; max-width: 720px; position: sticky; top: 1.2rem; max-height: calc(100vh - 2.4rem); display: flex; flex-direction: column; overflow: visible; }
.rail-hint { font-family: sans-serif; font-size: .68rem; color: #b0aa96; text-align: right; margin: .25rem .1rem 0; }
/* Full-height strip hanging off .code-rail's left edge; JS (see the matching HTML/script
   below) does the actual resizing on mousedown/mousemove/mouseup (+ touch equivalents).
   Dragging left (mouse moves to smaller clientX) enlarges the code window; dragging
   right shrinks it — opposite sign from a right-edge/corner handle, because this edge is
   on the panel's LEFT side. Being a plain child of the sticky .code-rail (not a sibling
   in some wrapper), it automatically moves together with the panel as it sticks/unsticks
   — no separate positioning logic needed. */
.rail-drag { position: absolute; top: 0; bottom: 0; left: -6px; width: 12px; cursor: ew-resize; z-index: 5; touch-action: none; }
.rail-drag::after { content: ""; position: absolute; top: 0; bottom: 0; left: 5px; width: 2px; background: transparent; transition: background .15s; }
.rail-drag:hover::after, .rail-drag.dragging::after { background: #c9c2ac; } /* visible hairline only on hover/drag, not at rest */
@media (max-width: 1050px) {
  .layout { flex-direction: column; }
  .code-rail { position: static; width: 100% !important; max-width: 100%; max-height: 480px; order: -1; }
  .content { max-width: 100%; }
  .rail-drag { display: none; } /* layout stacks vertically here; a left-edge width-drag is meaningless */
}
h1 { font-size: 1.4rem; border-bottom: 2px solid #1a2b4c; padding-bottom: .5rem; }
h2 { font-size: 1.15rem; color: #1a2b4c; margin-top: 2.2rem; }
h3.subcase { font-size: .9rem; letter-spacing: .04em; text-transform: uppercase; color: #444; }
.readtime { float: right; font-family: sans-serif; font-size: .85rem; color: #666; }

/* Code-panel show/hide toggle. #code-toggle must be a sibling of .layout (both direct
   children of <body>) so this single checkbox can reach descendants on either side.
   .rail-toolbar holds the theme swatches AND this button. Toggling hides the theme
   switch together with .code-box/.rail-hint (per the user's ask: the whole code window,
   including its theme control, hides as one unit) — but the button itself, not wrapped
   in the hidden selector, never disappears, so it's always there to re-open the panel.
   The button uses margin-left: auto rather than justify-content: space-between on the
   parent, so it still pins to the right edge of .rail-toolbar even after .theme-switch
   is display:none and it's the only child left. */
.rail-toolbar { display: flex; align-items: center; gap: .6rem; margin-bottom: .5rem; }
.code-toggle-btn { display: inline-block; font-family: sans-serif; font-size: .72rem; letter-spacing: .02em; padding: .4rem .8rem; border-radius: 20px; border: 1px solid #1a2b4c; background: #fff; color: #1a2b4c; cursor: pointer; flex: 0 0 auto; margin-left: auto; user-select: none; }
.code-toggle-btn .lbl-show { display: none; }
#code-toggle:checked ~ .layout .code-toggle-btn .lbl-hide { display: none; }
#code-toggle:checked ~ .layout .code-toggle-btn .lbl-show { display: inline; }
#code-toggle:checked ~ .layout .code-rail .theme-switch,
#code-toggle:checked ~ .layout .code-rail .code-box,
#code-toggle:checked ~ .layout .code-rail .rail-hint,
#code-toggle:checked ~ .layout .code-rail .rail-drag { display: none; }
/* !important beats the inline width the drag script (below) sets on .code-rail, so
   hiding the code panel always restores the study content to full width regardless of
   whatever custom width the reader last dragged it to. */
#code-toggle:checked ~ .layout .code-rail { width: auto !important; min-width: 0 !important; }
#code-toggle:checked ~ .layout .content { max-width: 1100px; }

/* Equations: every display formula lives inside its own bordered, independently
   scrollable frame, so widening/narrowing .code-rail (or a long piecewise/derivation
   line) never squeezes or wraps the math — it grows a horizontal scrollbar instead. */
.equation-frame { position: relative; border: 1px solid #e2ddcf; border-radius: 6px; background: #fbfaf6; margin: 1.2rem 0; overflow: hidden; }
.eq-scroll { overflow-x: auto; overflow-y: hidden; padding: .9rem 2.6rem .9rem 1.1rem; }
.equation { display: inline-block; min-width: 100%; text-align: center; font-style: italic; font-size: 1.05rem; white-space: nowrap; margin: 0; }
.equation-frame .eqnum { position: absolute; top: .6rem; right: .8rem; font-style: normal; color: #666; background: inherit; padding-left: .3rem; }
/* piecewise definitions: LHS label + brace must come BEFORE the cases table in the DOM,
   since .piecewise is a flex row and visual order follows document order. Putting the
   label after the table (even with margin tricks) puts "x_t =" on the wrong side.
   align-items: stretch (not center) makes every flex item -- including the brace --
   take the row's full height, which is set by the tallest item (the cases table). The
   label is pulled back to vertical center with align-self so only the brace stretches. */
.piecewise { display: inline-flex; align-items: stretch; gap: .5rem; text-align: left; white-space: nowrap; }
.piecewise .pw-label { font-style: italic; align-self: center; }
/* the brace is an SVG, not a "{" glyph -- a fixed-size glyph cannot lengthen itself to
   cover a 2-row vs. an 8-row cases table. preserveAspectRatio="none" on the <svg> lets
   its height:100% match the stretched flex item while the path's viewBox coordinates
   restretch vertically to fill it, so the brace always spans exactly the case rows next
   to it, however many there are. */
.piecewise .pw-brace { display: flex; align-self: stretch; flex: 0 0 auto; }
.piecewise .pw-brace svg { width: 14px; height: 100%; display: block; }
.piecewise .pw-brace path { fill: none; stroke: currentColor; stroke-width: 2.2; stroke-linecap: round; }
.piecewise table { border-collapse: collapse; }
.piecewise td { padding: .12rem .6rem; text-align: left; font-style: italic; white-space: nowrap; }
.piecewise td.cond { font-style: normal; color: #555; font-size: .92rem; }
/* aligned multi-step algebra — use whenever a jump between two expressions takes more
   than one algebraic move; never compress these into prose, even inside a .coach box */
.derivation table { border-collapse: collapse; margin: 0 auto; }
.derivation td { padding: .18rem .3rem; font-style: italic; white-space: nowrap; }
.derivation td.lhs { text-align: right; } /* left side, blank after the first row */
.derivation td.eq { text-align: center; width: 1.4rem; }
.derivation td.rhs { text-align: left; }
.derivation td.why { font-style: normal; color: #777; font-size: .82rem; padding-left: .9rem; }
.definitions { margin: .5rem 0 1rem 1.2rem; }
.coach { background: #f4f6fb; border-left: 4px solid #1a2b4c; padding: .8rem 1rem; margin: 1.2rem 0; border-radius: 0 4px 4px 0; }
.coach .label { font-weight: bold; color: #1a2b4c; display: block; margin-bottom: .4rem; }
.concept-checker ol { padding-left: 1.4rem; }
.concept-checker li { margin-bottom: .6rem; }
details.answer summary { cursor: pointer; color: #1a2b4c; font-weight: bold; }

/* original-code side panel: 3 selectable themes via CSS custom properties.
   Every CSS-only radio (tabs, theme switch, AND the #code-toggle checkbox) gets this
   class — hidden regardless of DOM nesting, unlike a descendant selector such as
   ".code-tabs input". Use position: fixed with explicit top/left, NOT position:
   absolute with no offsets — verified the hard way: absolute-with-no-offsets leaves
   each hidden input at its *static* position in the document flow, and #code-toggle in
   particular sits at the very top of <body> (it's the first element, before .layout).
   Clicking any <label for="...">, including the theme swatches deep inside .code-rail,
   focuses that input for accessibility — and a browser will scroll a newly-focused
   element into view if it isn't already. With absolute positioning that meant every
   click on the hide/show button (or a theme swatch) silently snapped the whole page
   back to the top, discarding the reader's scroll position. Fixed positioning pins the
   input to a viewport coordinate that's always "in view," so focusing it never
   triggers a scroll — check this specifically after adding any new CSS-only
   radio/checkbox toggle, since the bug produces no error and only shows up as an
   unexplained jump-to-top on click. */
.rail-switch { position: fixed; top: 0; left: 0; opacity: 0; width: 0; height: 0; pointer-events: none; }

/* base = "Paper" theme (default, matches page background) */
.code-box {
  --code-bg: #f7f5ef; --code-border: #e2ddcf; --code-fg: #33302a;
  --code-head-bg: #efeadd; --code-head-fg: #8a8371;
  --code-tab-fg: #948c78; --code-tab-active-fg: #1a2b4c; --code-tab-active-border: #1a2b4c;
  --code-cm: #96907c; --code-kw: #8a4b3b; --code-nm: #1a2b4c; --code-bl: #6b4b8a;
  background: var(--code-bg); color: var(--code-fg); border: 1px solid var(--code-border);
  border-radius: 8px; overflow: hidden; font-family: sans-serif; display: flex; flex-direction: column;
  flex: 1 1 auto; min-height: 0;
}
/* "Solarized Light" theme */
#theme-solarized:checked ~ .code-box {
  --code-bg: #fdf6e3; --code-border: #eee8d5; --code-fg: #586e75;
  --code-head-bg: #eee8d5; --code-head-fg: #93a1a1;
  --code-tab-fg: #93a1a1; --code-tab-active-fg: #073642; --code-tab-active-border: #268bd2;
  --code-cm: #93a1a1; --code-kw: #268bd2; --code-nm: #b58900; --code-bl: #6c71c4;
}
/* "Nord" dark theme */
#theme-nord:checked ~ .code-box {
  --code-bg: #2e3440; --code-border: #434c5e; --code-fg: #d8dee9;
  --code-head-bg: #3b4252; --code-head-fg: #8892a8;
  --code-tab-fg: #7b8394; --code-tab-active-fg: #eceff4; --code-tab-active-border: #88c0d0;
  --code-cm: #6b7489; --code-kw: #81a1c1; --code-nm: #88c0d0; --code-bl: #b48ead;
}

.code-box .code-head { padding: .6rem .9rem; background: var(--code-head-bg); font-size: .78rem; color: var(--code-head-fg); border-bottom: 1px solid var(--code-border); }
.code-tabs { display: flex; background: var(--code-head-bg); }
.code-tabs label { flex: 1; text-align: center; padding: .55rem .4rem; font-size: .78rem; cursor: pointer; color: var(--code-tab-fg); border-bottom: 2px solid transparent; }
/* combined-combinator highlight: input is a sibling of .code-tabs, label is a descendant of it */
#tab1:checked ~ .code-tabs label[for="tab1"],
#tab2:checked ~ .code-tabs label[for="tab2"] { color: var(--code-tab-active-fg); font-weight: bold; border-bottom: 2px solid var(--code-tab-active-border); background: var(--code-bg); }
.code-panes { position: relative; flex: 1 1 auto; min-height: 0; overflow: auto; }
.code-pane { display: none; padding: .9rem 1rem; margin: 0; font-family: "SF Mono", Menlo, Consolas, monospace; font-size: .74rem; line-height: 1.55; white-space: pre; overflow-x: auto; color: var(--code-fg); }
/* repeat the #tabN:checked ~ .code-panes #paneN rule below for each tab added */
#tab1:checked ~ .code-panes #pane1,
#tab2:checked ~ .code-panes #pane2 { display: block; }
.cm { color: var(--code-cm); font-style: italic; } /* comments */
.kw { color: var(--code-kw); } /* keywords: if/then/elif/else/end/for/to/return */
.nm { color: var(--code-nm); font-weight: bold; } /* function/UDF names, built-in or user-defined */
.bl { color: var(--code-bl); font-weight: bold; } /* boolean literals: True/False */

/* theme switch: 3 swatch dots, no native radio UI visible. Because .theme-switch lives
   inside .rail-toolbar rather than being a direct sibling of the #theme-* radios, the
   highlight selector below must route through .rail-toolbar too -- `~ .theme-switch`
   alone silently never matches (no error, the active swatch just never gets a border).
   Same gotcha family as the tab-pane sibling rule earlier in this file: whenever a
   :checked ~ target moves one level deeper in the DOM, every selector reaching for it
   has to grow an extra descendant hop to match. */
.theme-switch { display: flex; align-items: center; gap: .45rem; font-family: sans-serif; }
.theme-switch-label { font-size: .68rem; color: #8a8371; letter-spacing: .02em; text-transform: uppercase; }
.swatch { width: 17px; height: 17px; border-radius: 50%; cursor: pointer; display: inline-block; border: 2px solid transparent; box-shadow: 0 0 0 1px rgba(0,0,0,.18) inset; transition: box-shadow .15s, border-color .15s; }
.swatch-paper { background: #f7f5ef; }
.swatch-solarized { background: #fdf6e3; }
.swatch-nord { background: #2e3440; }
#theme-paper:checked ~ .rail-toolbar .theme-switch label[for="theme-paper"],
#theme-solarized:checked ~ .rail-toolbar .theme-switch label[for="theme-solarized"],
#theme-nord:checked ~ .rail-toolbar .theme-switch label[for="theme-nord"] { border-color: #1a2b4c; box-shadow: 0 0 0 1px #1a2b4c; }
```

Matching HTML skeleton for the page shell — `#code-toggle` sits directly before
`.layout`, both direct children of `<body>`, so it can reach into either side of the
layout; `.code-rail` is a **direct child of `.layout`** (per the sticky-containing-block
note above — no intermediate wrapper), and `.rail-drag`, the theme radios/swatches, and
`.code-box` are all direct children of it, so every `:checked ~` rule from §5 can reach
`.code-box`:

```html
<input class="rail-switch" type="checkbox" id="code-toggle">
<div class="layout">
  <div class="content">
    <!-- sections... -->
  </div>
  <div class="code-rail">
    <div class="rail-drag" title="Drag to resize: left widens the code window, right shrinks it"></div>
    <input class="rail-switch" type="radio" name="theme" id="theme-paper" checked>
    <input class="rail-switch" type="radio" name="theme" id="theme-solarized">
    <input class="rail-switch" type="radio" name="theme" id="theme-nord">
    <div class="rail-toolbar">
      <div class="theme-switch">
        <span class="theme-switch-label">theme</span>
        <label for="theme-paper" class="swatch swatch-paper" title="Paper (light)"></label>
        <label for="theme-solarized" class="swatch swatch-solarized" title="Solarized Light"></label>
        <label for="theme-nord" class="swatch swatch-nord" title="Nord (dark)"></label>
      </div>
      <label for="code-toggle" class="code-toggle-btn">
        <span class="lbl-hide">Hide code ▸</span>
        <span class="lbl-show">Show code ◂</span>
      </label>
    </div>
    <div class="code-box">
      <div class="code-head">Original model code &middot; &lt;file path&gt;</div>
      <input class="rail-switch" type="radio" name="codetab" id="tab1" checked>
      <input class="rail-switch" type="radio" name="codetab" id="tab2">
      <div class="code-tabs">
        <label for="tab1">&lt;formula name&gt;</label>
        <label for="tab2">&lt;UDF name&gt;</label>
      </div>
      <div class="code-panes">
        <pre class="code-pane" id="pane1"><!-- verbatim source --></pre>
        <pre class="code-pane" id="pane2"><!-- verbatim source --></pre>
      </div>
    </div>
    <div class="rail-hint">↔ drag anywhere on the left edge to resize</div>
  </div>
</div>
<script>
(function () {
  var rail = document.querySelector(".code-rail");
  var handle = document.querySelector(".rail-drag");
  var toggle = document.getElementById("code-toggle");
  if (!rail || !handle || !toggle) return;

  var MIN_WIDTH = 300, MAX_WIDTH = 720; // match .code-rail's min-width/max-width
  var startX = 0, startWidth = 0;

  function clientX(e) { return e.touches ? e.touches[0].clientX : e.clientX; }

  function onMove(e) {
    var delta = clientX(e) - startX;
    // dragging LEFT (delta negative) widens the code window; dragging RIGHT shrinks it
    // -- opposite sign from a right-edge handle, since this handle is on the left side.
    var newWidth = Math.max(MIN_WIDTH, Math.min(MAX_WIDTH, startWidth - delta));
    rail.style.width = newWidth + "px";
    e.preventDefault();
  }
  function onUp() {
    handle.classList.remove("dragging");
    document.removeEventListener("mousemove", onMove);
    document.removeEventListener("mouseup", onUp);
    document.removeEventListener("touchmove", onMove);
    document.removeEventListener("touchend", onUp);
    document.body.style.userSelect = "";
  }
  function onDown(e) {
    if (toggle.checked) return; // code panel is hidden, nothing to resize
    startX = clientX(e);
    startWidth = rail.getBoundingClientRect().width;
    handle.classList.add("dragging");
    document.addEventListener("mousemove", onMove);
    document.addEventListener("mouseup", onUp);
    document.addEventListener("touchmove", onMove, { passive: false });
    document.addEventListener("touchend", onUp);
    document.body.style.userSelect = "none";
    e.preventDefault();
  }
  handle.addEventListener("mousedown", onDown);
  handle.addEventListener("touchstart", onDown, { passive: false });
})();
</script>
```

The panel background (`#f7f5ef`) is a shade of the body's paper tone by default, not a
dark IDE theme — it should read as "part of the same document," not a foreign inset;
the other two curated themes are one click away via the swatch dots. `.rail-drag`
(dragged via the script above) lets the reader resize from **anywhere along the left
edge**, not just one corner — dragging left widens the panel, dragging right narrows it.
`white-space: pre` + `overflow-x: auto` on `.code-pane` means long lines scroll
horizontally instead of wrapping mid-token or mid-indentation. Add a small `.rail-hint`
line below the panel (e.g. "↔ drag anywhere on the left edge to resize") so the
affordance isn't hidden. On narrow/mobile viewports the layout stacks vertically and
`.rail-drag` is hidden (a left-edge width-drag is meaningless once the panel is
full-width and stacked above the content). The "Hide code ▸" / "Show code ◂" button
lives in `.rail-toolbar`, at the top of the code window next to the theme swatches —
collapsing `.theme-switch` and `.code-box` together (and letting `.content` reclaim most
of the freed width via the `!important` rule in §5, which always wins over whatever
inline width the drag script set) without ever hiding the button itself, since hiding
the rail must not hide its own toggle.

Use `<details><summary>Reveal answer</summary>...</details>` for each concept-checker
question so answers stay collapsed by default, mirroring the "Reveal Correct Answer"
behavior.

Matching HTML for a piecewise equation (label and brace **before** the cases table —
`.piecewise` is a flex row, so document order is visual order; verified by checking each
child's rendered `left` offset increases label → brace → table, not the reverse). Every
equation — piecewise or plain — is wrapped in `.equation-frame > .eq-scroll > .equation`
per §4, so it scrolls horizontally as its own unit instead of wrapping when `.content`
narrows:

```html
<div class="equation-frame">
  <div class="eq-scroll">
    <div class="equation">
      <span class="piecewise">
        <span class="pw-label"><i>x</i><sub>t</sub> =</span>
        <span class="pw-brace"><svg viewBox="0 0 16 100" preserveAspectRatio="none"><path d="M14,2 C6,2 6,10 6,20 C6,32 0,34 0,50 C0,66 6,68 6,80 C6,90 6,98 14,98"/></svg></span>
        <table>
          <tr><td>&lt;case A&gt;</td><td class="cond">if &lt;condition A&gt;</td></tr>
          <tr><td>&lt;case B&gt;</td><td class="cond">if &lt;condition B&gt;</td></tr>
          <tr><td>&lt;case C&gt;</td><td class="cond">otherwise</td></tr>
        </table>
      </span>
    </div>
  </div>
  <span class="eqnum">(N)</span>
</div>
```

The brace is drawn as an SVG path, not typed as a literal `{` character — a text glyph is
a fixed size and cannot lengthen itself to match a 2-row vs. an 8-row cases table. Because
`.pw-brace` stretches to the flex row's height (set by §5's `align-items: stretch`) and
the `<svg>` inside it is `height: 100%` with `preserveAspectRatio="none"`, the brace
always spans exactly the height of the cases table next to it, however many rows that
table has — no manual sizing per equation.

Matching HTML for a multi-step algebraic derivation (one row per step; leave `td.lhs`
blank after the first row so the `=` signs visually align down the page; the `.why`
column is optional per row but should appear whenever the move isn't obvious). Same
`.equation-frame > .eq-scroll` wrapping applies:

```html
<div class="equation-frame">
  <div class="eq-scroll">
    <div class="equation derivation">
      <table>
        <tr><td class="lhs"><i>Var</i>(<i>X</i>)</td><td class="eq">=</td><td class="rhs"><i>M</i><sub>2</sub> &minus; <i>M</i><sub>1</sub><sup>2</sup></td><td class="why">definition of variance</td></tr>
        <tr><td class="lhs"></td><td class="eq">=</td><td class="rhs"><i>M</i><sub>2</sub> &minus; (<i>F</i>+1)<sup>2</sup></td><td class="why">substitute <i>M</i><sub>1</sub> = <i>F</i>+1</td></tr>
        <tr><td class="lhs"></td><td class="eq">=</td><td class="rhs"><i>M</i><sub>2</sub> &minus; <i>F</i><sup>2</sup> &minus; 2<i>F</i> &minus; 1</td><td class="why">expand (<i>F</i>+1)<sup>2</sup></td></tr>
      </table>
    </div>
  </div>
  <span class="eqnum">(N)</span>
</div>
```

A plain (non-piecewise, non-derivation) equation uses the same frame with just the
formula and no inner table — don't skip the frame just because the formula is short; a
short formula referenced by a long variable name can still overflow a narrowed
`.content` column.

If the derivation continues across a rearrangement (e.g. moving terms between sides) or
a fresh definition (e.g. introducing `ratio = ...`), start a **new** `.derivation` block
rather than mixing two different LHS quantities in one table — each block should read as
one continuous chain of `=`.

## 6. The five sections, in detail

### Introduction
- 1–2 short paragraphs. State what family this calculation belongs to (e.g. "this is an
  index-crediting formula for a fixed-indexed-annuity strategy" / "this is a GMWB
  withdrawal-benefit rider calculation"), where it sits in the model (table name, e.g.
  `FIAAFUND_LIAB`, and file path), and why it exists (what product feature or risk it's
  modeling).
- If this formula depends on / relates to another concept already covered elsewhere in
  the model, say so up front, the way the sample material says "In the previous sections
  we covered...".

### Explain the Calculation
- The core of the document. Walk through the code top to bottom, converting each step
  into an equation per §3, with definitions and interpretation bullets after each one.
- If the formula has named branches/cases (e.g. per-index-asset switch, or "last year vs.
  more than one year remaining"), give each its own `<h3 class="subcase">` block.
- End with the fully assembled formula as it would appear in the model's output (i.e.,
  the actual column formula in closed form, cross-referencing the equation numbers used
  to build it).

### Coach's Remark
- Not a separate block at the end — these are inline `.coach` boxes placed at the exact
  point in "Explain the Calculation" where the subtlety arises. When writing the
  Summary, you may also add one Coach's Remark box if there's an over-arching pitfall
  worth restating.
- Typical content: notation hand-holding, "don't confuse X with Y", "you won't need to
  memorize this closed form, but you should recognize its shape", or a business-logic
  explanation for a branch/threshold in the code.

### Summary
- A condensed, re-derivation-free restatement: just the final formulas, each symbol's
  meaning, and the one-line interpretation — organized under the same subheadings used in
  "Explain the Calculation". This section should be usable as a standalone reference
  without reading the rest of the page.

### Concept Checker
- A numbered list of questions (no answers inline) that test the material in the order
  it was presented, so a reader can locate the relevant subsection to check their answer.
- Follow with a **collapsed** answer per question (`<details>`), written concisely (1–3
  sentences, or the requested formula).
- Mix conceptual questions ("Why does this branch return 0 when `run_shocksos` is
  true?") with formula-recall questions ("Write the formula for X").

## 7. Style rules carried over from the sample material

- Prefer short paragraphs and bullet lists over long prose blocks.
- Bold the first mention of a new named concept (a model term, a distribution family, a
  named parameter).
- Every equation that's referenced again later must be numbered; equations used once and
  never referenced again can stay unnumbered if that keeps the numbering cleaner.
- Don't editorialize about code quality — the job is to explain the model as it is, not
  to critique or refactor it.
- If a derivation is long but not essential to remember (e.g. a full multivariate density
  derivation), keep it, but add a Coach's Remark telling the reader what's actually worth
  retaining — don't cut content the sample material would have kept.
