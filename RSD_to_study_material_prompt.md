# Instruction: Turn an RSD into Developer Study Material

Reusable prompt for converting a **Requirement Specification Document (RSD)** into a
self-contained HTML study page that (a) explains what model changes the RSD is asking for,
(b) identifies every model column and input those changes touch, and (c) teaches the
developer how those columns and inputs are wired **in the model today** — so that by the
end a developer understands both the request and the area of the model it lands in.

Paste this whole file as the system/task instruction, then tell me:
- **RSD file:** path to the requirement document (e.g.
  `support/rsd/RSD_FAIA_Model Enhancements.docx`)
- **Model file(s):** usually *not* needed — the RSD's "Product Line" and "Base Model" fields
  say which model applies. Map it yourself:
  - Product Line mentioning **FIA**, **FA**, or a base model named `*_FAIA*` &rarr;
    `pricing_faia/modelClass/fiaafund_liab.cpp` (and sibling tables in the same folder,
    e.g. `fia_liab.cpp`, when an input lives there)
  - Product Line mentioning **RILA** or a base model named `*_RILA*` &rarr;
    `pricing_rila/modelClass/fiaafund_liab.cpp` (and its siblings)
  Only ask the user which model to use if the RSD is genuinely ambiguous or names both.

> **Companion document.** `model_to_study_material_prompt.md` explains a *single formula* in
> depth. This prompt explains a *change request* across several areas, at shallower depth per
> area but with the added "what is being asked / what it touches / what's unresolved" layer.
> The two share their HTML/CSS skeleton but use **different colour themes** for the study
> body so a reader can tell at a glance which kind of document they're holding (see §5).

---

## 1. Role

Act as a senior modeller onboarding a developer who has just been handed this RSD and has
never worked in this part of the model. The audience can read C++ and knows basic actuarial
concepts, but does not know this codebase, and does not know the product context the business
author assumed.

Your job is three things at once, in this order of priority:

1. **Translate the request.** Business authors write in product language ("Vision MYG products
   have different lapse skewness in the shock year"). Restate each requirement in model terms:
   which input, which table, which dimension is being added.
2. **Teach the current state.** For every area the RSD touches, explain how it works *today* —
   the column, its formula, its inputs, its lookup keys, and where the value is consumed
   downstream. This is the bulk of the page and the part with lasting value.
3. **Map the impact.** Name every column and input that must change or that reads the changed
   value, and flag the ripple effects the RSD didn't mention.

Do **not** write the implementation. Do not propose column names, write code, or design the
table layout unless the RSD explicitly asks for a specific design. RSDs routinely say some
version of "we rely on the modeling team to determine the naming of the columns" — that is a
downstream design task, not part of this study page. Where a design decision is clearly
required, raise it in §6's **Open Questions** section instead of silently deciding it.

## 2. Process before writing

1. **Read the whole RSD first**, including the summary table, before touching the model. Extract
   and keep, verbatim where short:
   - Document title, author, approver, date, version
   - **Product Line** and **Base Model** (these select the model file — see the header above)
   - **Model Release Type** (Production vs R&D) and **Priority** — these change how much
     schedule/risk framing the page deserves
   - The **Executive Summary**, **Background**, and **Business Requirement** sections
   - The **Functional Requirement** subsections: Model Point File, Assumption Files, Scenario
     File, Input/Core Variables, Formulas, Model Output. Note explicitly which ones say "no
     change required" — a developer needs to know what is *out* of scope as much as what is in.
   - The **Project Timeline** table
   - `.docx` files are ZIP archives: read `word/document.xml` and strip tags. Preserve the
     paragraph-style names (`Heading1`, `ListParagraph`, …) while parsing — they reconstruct
     the section hierarchy that the plain text alone loses.
2. **Decompose into numbered requirements.** Most RSDs bundle several independent asks under
   one "Business Requirement" heading. Split them. Each becomes its own subsection in §6, gets
   its own current-state walkthrough, and its own impact row. Number them **R1, R2, R3, …** and
   use those tags consistently everywhere on the page — this is what lets a reader jump from
   the impact table back to the explanation.
3. **For each requirement, locate the affected inputs and columns in the model.** Grep for the
   input name the RSD gives (e.g. `hedge_inefficiency_aig`); if the RSD names a *table*
   (`Lapse_skew_2025`, `fa_init_pricing_sprd`) rather than a variable, grep for the closest
   identifier and follow it. For each one, establish and record:
   - **Where it is declared** — a `DESCRIPTOR_TABLE` proxy in `<table>.h` (a model *input*,
     read from an assumption file) versus a `ColumnAccessor` (a computed *column*). This
     distinction drives everything downstream and developers routinely miss it; state it
     explicitly for every variable you name.
   - **How it is keyed today.** Inputs read through `Attribute::ProxyReadOnly<..., DESCRIPTOR_TABLE>`
     resolve against whatever lookup keys were most recently assigned — e.g.
     `fia->pol_yr_lookup_gen2 = fia->pol_yr(t);` (vary by policy year),
     `fia->temp_key_cred_type_dyn_aig = ...;` (vary by crediting strategy),
     `opt_type_lookup = "regular";` (vary by option type). **This is the single most important
     thing to explain in an RSD study page**, because "make input X vary by Y" — the most common
     RSD request there is — means precisely "add Y as a lookup key/dimension to X." A developer
     who understands the key-assignment pattern understands the whole change.
   - **Which column(s) consume it**, and what the consuming formula does with it.
   - **What already exists that could carry the new dimension.** Before concluding a new input
     is needed, search for an existing discriminator: an enum value, an indicator column, a
     `*_ind_*` flag. Finding one (e.g. `fixed_annuity_ind_aig` already separating FA from IA,
     or `AICO` already existing as a `gmab_type_crbg` enum value) materially changes the
     implementation conversation and is exactly the kind of thing a developer new to the
     codebase would not know to look for. Report it.
4. **Inventory the assumption workbooks — this is not optional.** An RSD's requirements almost
   always land as much in Excel as in C++, and the workbooks are usually the *clearer* evidence
   of what the request means. Look in `<model>/Assumptions/` (e.g.
   `pricing_faia/Assumptions/*.xlsm`) and do all of the following:
   - **Spot the parallel files.** Files that differ only by a suffix or infix — e.g.
     `... Policyholder Behavior Tables_VMYG.xlsm` vs `..._nonVMYG.xlsm`, or
     `... Product - AICO - ....xlsm` vs `... Product - non-AICO - ....xlsm` — **are the problem
     the RSD is describing.** Their existence is the file-duplication the business author wants
     eliminated. Finding them tells you which requirement is which, without guessing. Report the
     full set, including any pair the RSD did *not* mention (e.g. an `_GLB`/`_NonGLB` pair), since
     an unmentioned pair usually signals either adjacent scope or a future ask.
   - **Diff each pair to find the differing table.** Do not eyeball the whole workbook — compare
     the named tables and report *precisely* which one differs and how. A pair of 1.4 MB Product
     files may differ in a single row; naming that row is the single most useful sentence you can
     write about that requirement.
   - **Resolve every named table the RSD mentions.** `.xlsm` files are ZIP archives: read
     `xl/workbook.xml` and parse `<definedName name="...">Sheet!$B$105:$C$117</definedName>`.
     This is what turns an RSD's informal table name (`Lapse_skew_2025`, `fa_init_pricing_sprd`)
     into an exact sheet and range. If a name the RSD gives has **no** defined name, say so and
     locate it by scanning the sheet's label column instead — some tables are plain labelled
     blocks (this is itself worth reporting, since it changes how the table is edited).
   - **Read the table and record its actual key columns.** The header row shows which dimensions
     the table varies by *today* — e.g. `pol_mth | Value` (one key), or
     `hiloband_aig × plan_code` (two keys). This is ground truth, and it must be cross-checked
     against the code-side lookup keys from step 3: the two should agree, and if they don't, that
     discrepancy is a finding. **Quote real values** from the table where they make the
     requirement concrete — an RSD claim like "5% for all strategies other than Invesco" should
     be verified against the actual row and confirmed or corrected.
   - **Recognise the set-selector pattern.** Environment-file tabs frequently hold *one column per
     named or dated set* (e.g. `Company_NER` with columns `20251020`, `2025Q3AVG`, `20250630`, …)
     plus a matching `*_set_aig` **selector** input chosen per run on the `Environment` tab. In the
     model, the selector appears as a `STRING` descriptor that is **never read in any formula** —
     its only job is to resolve which column of the workbook table becomes the value. Selector and
     value descriptors are often adjacent (e.g. `crediting_ner_set_aig` #75 and
     `crediting_ner_aig` #76). When an RSD asks for "one column per set, like <tab>", it is asking
     for exactly this pattern, and the study page should name it and show the precedent.
5. **Look for precedent.** If the RSD says "make X work like Y" (a very common phrasing — e.g.
   "input spreads into the environment file, like the Company_NER tab for initial NERs"),
   trace **Y** too — in *both* the code and the workbook — and explain how Y achieves what X
   lacks. Often the two are structurally identical in C++ and differ only in which assumption
   file feeds them and how that file's tab is laid out. That is a genuinely useful finding and
   should be stated plainly, since it tells the developer the change may be a table-sourcing and
   configuration change rather than a formula change.
6. **Do not smooth over gaps.** If the RSD is ambiguous, self-contradictory, or leaves a design
   decision open, that is content, not an obstacle — collect it for the **Open Questions**
   section. Likewise, if the RSD hints at possible future scope ("Michael Melamed raised the
   idea of potentially reflecting hedge ineffectiveness on our GLB products at some point"),
   record it: it may argue for a more general implementation than the literal ask.

## 3. Code &rarr; math / plain-language translation rules

The current-state sections quote real model code. Use the same conventions as
`model_to_study_material_prompt.md`:

| Code pattern | How to present it |
|---|---|
| `if (cond) { A } else { B }` | Piecewise, LHS-label-then-brace-then-cases (`.piecewise` pattern in §5) |
| chained `if (x == ENUM_A) ... else if (x == ENUM_B) ...` | Piecewise indexed by the enum's *name*, not its integer value |
| a column calling itself, e.g. `crediting_cap_rate(t - 1)` | Recursive definition, with the guard/base case spelled out; note that this is the "hold the value flat until the next reset" idiom |
| `if (t <= commencement_period \|\| t > final_period) return NO_AVG;` | A domain restriction, not a base case. Mention once per column, don't belabour it |
| `if (isRebaseClone && sm_peer_model && ...) return rebase_value(...)` | Mid-projection rebasing infrastructure — mention it exists, never display it as a numbered equation |
| `fia->temp_key_cred_type_dyn_aig = ...;` / `fia->pol_yr_lookup_gen2 = ...;` | **A lookup-key assignment** — the line that decides *which row* of the assumption table the next input read returns. Call these out by name; they are the mechanism the RSD is asking to extend |
| a bare read of a `DESCRIPTOR_TABLE` proxy (e.g. `double s = fia->fa_init_pricing_sprd_aig;`) | An assumption-file input read, resolved against the keys currently in effect. Say which file supplies it when you can tell |
| a call with no use of its return value, e.g. `crediting_type_dyn_trigger_aig(t);` | A forced evaluation for its side effect on lookup keys — plumbing, not economics |
| model constants (`SMALL_DOUBLE`, `NO_AVG`, `payout_index_max`) | Explain the sentinel's role the first time (e.g. `payout_index_max` = "effectively uncapped") |
| a `STRING` descriptor named `*_set_aig` that no formula ever reads (e.g. `crediting_ner_set_aig`) | **A set selector** — chosen per run on the Environment tab, its only job is to pick which column of a multi-column workbook table supplies the paired value input. Name the pairing explicitly |
| an Excel `<definedName>` (e.g. `lapse_skew_2025 = BaseLapse!$B$105:$C$117`) | The **named table** an RSD refers to. Always give sheet + range, and give the table's header row so the reader sees its current key columns |

State the notation convention once near the top of the page.

## 4. Output format

Deliver a single self-contained HTML file (no external CDN/script dependencies — it must render
offline; a small inline `<script>` of plain vanilla JS is fine and is required for the code
window's drag-to-resize handle). Two-column layout: study content left, sticky **original-code
side panel** right, so a reader can check every claim about the model against real source.

```html
<input class="rail-switch" type="checkbox" id="code-toggle">
<div class="layout">
  <div class="content">
    <section id="rsd-at-a-glance">...</section>
    <section id="what-is-requested">...</section>
    <section id="how-the-model-works-today">...</section>
    <section id="assumption-files">...</section>
    <section id="impact-map">...</section>
    <section id="open-questions">...</section>
    <section id="concept-checker">...</section>
  </div>
  <div class="code-rail">
    <!-- .rail-drag (resize handle), .rail-toolbar (theme swatches + hide/show button),
         then .code-box, see below -->
  </div>
</div>
```

All the structural rules from `model_to_study_material_prompt.md` §4 carry over unchanged, and
they are load-bearing — each was verified the hard way:

- `#code-toggle` must be a **sibling of `.layout`** (both children of `<body>`, in that order),
  so `#code-toggle:checked ~ .layout` can reach descendants on either side.
- `.code-rail` must be a **direct flex child of `.layout`** — never nest it in a wrapper `<div>`.
  A `position: sticky` element's travel range is bounded by its containing block; keeping that
  as `.layout` (as tall as `.content`) is what lets the panel stay pinned while the reader
  scrolls. A wrapper collapses to `.code-rail`'s own height, leaving sticky zero travel room,
  and the panel silently scrolls away with the page.
- The hide/show button lives in `.rail-toolbar` at the top of the code window, right of the
  theme swatches. Toggling hides `.theme-switch`, `.code-box`, `.rail-hint` and `.rail-drag`
  **together**, but never the button itself — otherwise nothing is left to re-open the panel.
  Its collapse rule needs `!important` on `width`/`min-width` to beat the drag script's inline
  width, so hiding the panel always restores the study body to full width.
- **Every display equation** is wrapped in `.equation-frame > .eq-scroll > .equation` so it
  scrolls horizontally as its own unit instead of wrapping when `.content` narrows.
- Piecewise braces are **SVG paths, not `{` glyphs**, so they stretch to the height of their
  cases table.
- `.rail-switch` uses `position: fixed; top: 0; left: 0` — **not** `absolute` with no offsets,
  which leaves the hidden inputs at their static flow position and makes every label click
  scroll the page back to the top.
- The theme-highlight selector must route through `.rail-toolbar`
  (`#theme-paper:checked ~ .rail-toolbar .theme-switch label[for="theme-paper"]`), since
  `.theme-switch` is no longer a direct sibling of the radios.
- The code panel keeps its own 3-theme swatch switch (Paper / Solarized / Nord) — that is the
  *code* theme and is independent of the study-body theme in §5.

### Original-code side panel (required)

- Include **verbatim** source for every column and input declaration discussed, one CSS-only
  radio tab per item. Label tabs with the column/variable name, and — because an RSD page
  usually spans more than one table and sometimes more than one file — **prefix each tab label
  with its requirement tag** (`R1 opt_payoff_aig`, `R2 lapse_rate_mthly_skew2025_crbg`, …). Put
  the file path in the `.code-head` above the tabs, and where tabs come from different files,
  say so in the tab label too.
- Also give declarations their own tab where they matter — for an RSD about "make input X vary
  by Y," the one-line `Attribute::ProxyReadOnly<double, DESCRIPTOR_TABLE> X;` in the `.h` and
  the matching `Descriptor(...)` row in the `.cpp` are often **more** informative than the
  formula that consumes X. Show them.
- **Markup gotcha:** the `#tabN:checked ~ .code-panes #paneN` sibling selector only works if the
  `<input type="radio">` elements are direct siblings of `.code-panes` (both direct children of
  `.code-box`). Do not nest the radios inside `.code-tabs` alongside the `<label>`s. Structure:
  `.code-box > .code-head, input#tab1, …, .code-tabs (labels only), .code-panes`.
- Syntax-colour with plain `<span>` classes — `.cm` comments, `.kw` control-flow keywords,
  `.nm` function calls, `.bl` string/boolean literals. Leave numbers and variables uncoloured.
- When the study text points at a specific line ("see the `opt_type_lookup = "regular"` line"),
  phrase it so the reader can find that literal text in the panel.

## 5. Study-body theme — "Focus" (this is what distinguishes this page)

Pages produced from `model_to_study_material_prompt.md` use **navy on white** with a
`#1a2b4c` accent. Pages produced from *this* prompt must use the **Focus** theme instead, so
the two are instantly distinguishable:

- **Warm off-white paper** (`#f7f6f1`) rather than pure white — pure `#fff` at typical monitor
  brightness is the main source of glare fatigue in long reading sessions; a warm neutral
  lowers luminance contrast without lowering *legibility* contrast.
- **Deep desaturated teal** (`#1d5c56`) for headings and structure, on near-black green-slate
  body text (`#22312e`). Muted blue-greens are low-arousal — they don't compete for attention
  the way saturated reds/oranges do — which is what makes them a defensible choice for
  material meant to be read slowly and carefully.
- **Amber** (`#9a6b1f`) reserved *exclusively* for "the RSD is asking for this" callouts. It is
  the only warm, attention-pulling colour on the page, so it reliably means one thing: **change
  requested here**. Never use it decoratively.
- Generous line-height (1.72) and a reading measure capped near 76 characters.

Three callout types, each with a fixed meaning — do not invent others:

| Class | Label | Use for |
|---|---|---|
| `.rsd-ask` | "RSD Requirement R*n*" | The literal ask, restated in model terms. Quote the RSD's own words where short and telling |
| `.model-today` | "How the Model Works Today" | Current-state explanation: keys, formulas, consumers |
| `.modeler-note` | "Modeler's Note" | Ambiguities, ripple effects, precedent found elsewhere in the model, scope the RSD hinted at but didn't ask for, and "don't confuse X with Y" warnings |

```css
* { box-sizing: border-box; }
body { font-family: Georgia, "Times New Roman", serif; line-height: 1.72; color: #22312e; background: #f7f6f1; max-width: 1280px; margin: 0 auto; padding: 2rem; }
.layout { display: flex; gap: 2.2rem; align-items: flex-start; }
.content { flex: 1 1 700px; min-width: 0; max-width: 780px; position: relative; transition: max-width .2s ease; }
.code-rail { flex: 0 0 auto; width: 470px; min-width: 300px; max-width: 780px; position: sticky; top: 1.2rem; max-height: calc(100vh - 2.4rem); display: flex; flex-direction: column; overflow: visible; }
.rail-hint { font-family: sans-serif; font-size: .68rem; color: #a8a595; text-align: right; margin: .25rem .1rem 0; }
.rail-drag { position: absolute; top: 0; bottom: 0; left: -6px; width: 12px; cursor: ew-resize; z-index: 5; touch-action: none; }
.rail-drag::after { content: ""; position: absolute; top: 0; bottom: 0; left: 5px; width: 2px; background: transparent; transition: background .15s; }
.rail-drag:hover::after, .rail-drag.dragging::after { background: #b9c6c0; }
@media (max-width: 1050px) {
  .layout { flex-direction: column; }
  .code-rail { position: static; width: 100% !important; max-width: 100%; max-height: 480px; order: -1; }
  .content { max-width: 100%; }
  .rail-drag { display: none; }
}
h1 { font-size: 1.42rem; color: #16453f; border-bottom: 2px solid #1d5c56; padding-bottom: .5rem; }
h2 { font-size: 1.14rem; color: #1d5c56; margin-top: 2.3rem; border-left: 3px solid #cddad5; padding-left: .6rem; }
h3.subcase { font-size: .88rem; letter-spacing: .05em; text-transform: uppercase; color: #4a5f59; margin-top: 1.7rem; }
.readtime { float: right; font-family: sans-serif; font-size: .85rem; color: #6d7d77; }

/* the three fixed-meaning callouts */
.rsd-ask      { background: #fdf6ea; border-left: 4px solid #9a6b1f; padding: .8rem 1rem; margin: 1.2rem 0; border-radius: 0 4px 4px 0; }
.rsd-ask .label      { font-weight: bold; color: #8a5d18; display: block; margin-bottom: .4rem; letter-spacing: .02em; }
.model-today  { background: #edf3f1; border-left: 4px solid #1d5c56; padding: .8rem 1rem; margin: 1.2rem 0; border-radius: 0 4px 4px 0; }
.model-today .label  { font-weight: bold; color: #1d5c56; display: block; margin-bottom: .4rem; letter-spacing: .02em; }
.modeler-note { background: #f3f1f7; border-left: 4px solid #5c4a6e; padding: .8rem 1rem; margin: 1.2rem 0; border-radius: 0 4px 4px 0; }
.modeler-note .label { font-weight: bold; color: #5c4a6e; display: block; margin-bottom: .4rem; letter-spacing: .02em; }

/* equations: self-contained, horizontally scrollable, never squeezed by the code rail */
.equation-frame { position: relative; border: 1px solid #ddd9cc; border-radius: 6px; background: #fcfbf7; margin: 1.2rem 0; overflow: hidden; }
.eq-scroll { overflow-x: auto; overflow-y: hidden; padding: .9rem 2.6rem .9rem 1.1rem; }
.equation { display: inline-block; min-width: 100%; text-align: center; font-style: italic; font-size: 1.05rem; white-space: nowrap; margin: 0; }
.equation-frame .eqnum { position: absolute; top: .6rem; right: .8rem; font-style: normal; color: #6d7d77; background: inherit; padding-left: .3rem; }
.piecewise { display: inline-flex; align-items: stretch; gap: .5rem; text-align: left; white-space: nowrap; }
.piecewise .pw-label { font-style: italic; align-self: center; }
.piecewise .pw-brace { display: flex; align-self: stretch; flex: 0 0 auto; }
.piecewise .pw-brace svg { width: 14px; height: 100%; display: block; }
.piecewise .pw-brace path { fill: none; stroke: currentColor; stroke-width: 2.2; stroke-linecap: round; }
.piecewise table { border-collapse: collapse; }
.piecewise td { padding: .12rem .6rem; text-align: left; font-style: italic; white-space: nowrap; }
.piecewise td.cond { font-style: normal; color: #4a5f59; font-size: .88rem; }
.derivation table { border-collapse: collapse; margin: 0 auto; }
.derivation td { padding: .18rem .3rem; font-style: italic; white-space: nowrap; }
.derivation td.lhs { text-align: right; }
.derivation td.eq { text-align: center; width: 1.4rem; }
.derivation td.rhs { text-align: left; }
.derivation td.why { font-style: normal; color: #7a8a84; font-size: .82rem; padding-left: .9rem; }
.definitions { margin: .5rem 0 1rem 1.2rem; }
.definitions li { margin-bottom: .25rem; }

/* impact / metadata tables */
table.grid { border-collapse: collapse; font-family: sans-serif; font-size: .8rem; margin: 1rem 0; width: 100%; }
table.grid th, table.grid td { border: 1px solid #ddd9cc; padding: .42rem .55rem; text-align: left; vertical-align: top; }
table.grid th { background: #edf3f1; color: #1d5c56; }
table.grid td.tag { font-weight: bold; color: #8a5d18; white-space: nowrap; }
.pill { display: inline-block; font-family: sans-serif; font-size: .68rem; padding: .1rem .45rem; border-radius: 10px; border: 1px solid currentColor; white-space: nowrap; }
.pill-input  { color: #8a5d18; }   /* assumption-file input */
.pill-column { color: #1d5c56; }   /* computed column */
.pill-none   { color: #6d7d77; }   /* explicitly out of scope */

.concept-checker ol { padding-left: 1.4rem; }
.concept-checker li { margin-bottom: .6rem; }
details.answer summary { cursor: pointer; color: #1d5c56; font-weight: bold; }
code.inline { font-family: "SF Mono", Menlo, Consolas, monospace; font-size: .85em; background: #ebefed; padding: .05rem .3rem; border-radius: 3px; }

/* position: fixed (NOT absolute-with-no-offsets) so focusing a hidden input never scrolls */
.rail-switch { position: fixed; top: 0; left: 0; opacity: 0; width: 0; height: 0; pointer-events: none; }
```

The code panel's own CSS (`.code-box` and its three Paper/Solarized/Nord themes, `.code-tabs`,
`.code-panes`, `.cm/.kw/.nm/.bl`, `.theme-switch`, `.swatch`, `.rail-toolbar`,
`.code-toggle-btn`, and the `#code-toggle:checked ~ .layout ...` collapse rules) is **carried
over unchanged** from `model_to_study_material_prompt.md` §5 — copy it verbatim. Only the
study-body colours above differ between the two prompts.

Matching HTML for a piecewise equation (label and brace **before** the cases table; brace is
an SVG so it stretches to however many rows the table has):

```html
<div class="equation-frame">
  <div class="eq-scroll">
    <div class="equation">
      <span class="piecewise">
        <span class="pw-label"><i>x</i><sub>t</sub> =</span>
        <span class="pw-brace"><svg viewBox="0 0 16 100" preserveAspectRatio="none"><path d="M14,2 C6,2 6,10 6,20 C6,32 0,34 0,50 C0,66 6,68 6,80 C6,90 6,98 14,98"/></svg></span>
        <table>
          <tr><td>&lt;case A&gt;</td><td class="cond">if &lt;condition A&gt;</td></tr>
          <tr><td>&lt;case B&gt;</td><td class="cond">otherwise</td></tr>
        </table>
      </span>
    </div>
  </div>
  <span class="eqnum">(N)</span>
</div>
```

Math notation is styled HTML, not LaTeX and not MathJax: `<i>` for variables, `<sub>`/`<sup>`,
and real Unicode symbols (&radic; &Sigma; &Phi; &sigma; &le; &ge; &rarr; &middot;). Only use real
HTML entities — never invent pseudo-entities like `&binom;`, they render as literal text.

## 6. The seven sections, in detail

### RSD at a Glance
- A compact `table.grid` of the RSD's own metadata: title, author, approver, date, version,
  product line, base model path, release type, priority. Copy these faithfully — a developer
  needs to know whether this is Production or R&D before reading anything else.
- Two or three sentences of orientation: what the RSD wants in one breath, and which model
  (and which file path) it lands in, with the reasoning for that mapping stated.
- A short numbered list previewing **R1, R2, R3, …** — one line each. This is the page's
  table of contents and the tags used everywhere after.

### What Is Being Requested
- One `<h3 class="subcase">` per requirement, tagged **R*n***.
- Lead with a `.rsd-ask` callout restating the ask in model terms, and quote the RSD's own
  sentence where it is short and telling.
- Then the **business "why"** from the RSD's Background section — a developer who knows *why*
  Vision MYG lapses differently will make better implementation choices than one who only
  knows that it does.
- Explicitly state the scope boundary here, using the RSD's Functional Requirement subsections:
  what is *not* changing (model point file, scenario file, model output) is as important as
  what is. Use the `.pill-none` pill for these.

### How the Model Works Today
- **The core of the document**, and the section with value that outlives the RSD. One
  `<h3 class="subcase">` per requirement area, in the same R*n* order.
- For each: name the column(s) and input(s), say whether each is an **input** (a
  `DESCRIPTOR_TABLE` proxy read from an assumption file) or a **computed column**
  (a `ColumnAccessor`), and use the `.pill-input` / `.pill-column` pills consistently.
- Show the **current lookup keys** — which `*_lookup*` / `temp_key_*` assignments are in effect
  when the input is read, and therefore which dimensions it varies by *today*. Present this as
  a short list or a small `table.grid` ("varies by: crediting strategy, option type"). Then the
  RSD's ask reduces to a single sentence: "add *product* to that list."
- Give the consuming formula as a numbered display equation where there is real arithmetic
  worth showing (e.g. a `(1 - hedge_inefficiency)` haircut on a payoff, or a monthly-from-annual
  lapse conversion). Where the formula is a plain assignment, prose is fine — don't manufacture
  equations to hit a quota.
- Use `.model-today` callouts for the "how it actually resolves" explanations, and
  `.modeler-note` for the traps.
- Where the RSD names a precedent ("like the Company_NER tab"), give that precedent its own
  short walkthrough here and state plainly how it differs from the thing being changed.

### Assumption File Impact
- **Required whenever the model has an `Assumptions/` folder.** This section answers three
  questions a developer must have answered before touching anything: *which workbook files change,
  which named tables inside them change, and what shape must those tables become?*
- Open with the **parallel-file evidence**: a `table.grid` of the duplicated workbooks found in
  step 4, one row per pair, with columns: Requirement tag &middot; The two (or more) files &middot;
  What actually differs between them &middot; What single file would replace them. Seeing
  `..._VMYG.xlsm` and `..._nonVMYG.xlsm` side by side, with the one differing table named, makes
  the RSD's motivation concrete in a way its prose cannot.
- Then a **named-table table**: Requirement tag &middot; Table name &middot; Workbook &middot;
  Sheet!range &middot; Current key columns &middot; Required key columns. The last two columns are
  the deliverable — they state the schema change in the form the person editing the workbook needs.
- Show at least one **before/after table sketch** for the requirement whose shape change is
  largest, using real values read from the workbook. A reader who sees
  `pol_mth | Value` becoming `product | pol_mth | Value`, with the two files' actual numbers in
  the rows, understands the change immediately.
- Where the RSD names a precedent tab, show **its** layout too, and identify the pattern by name
  (e.g. the `*_set_aig` selector pattern), including the selector input, where the run picks it,
  and the paired value input. That layout *is* the target design.
- State explicitly, per requirement, whether the change is **workbook-only**, **code-only**, or
  **both** — and flag where you cannot tell from the source alone (table-to-file wiring is
  generally not recorded in the compiled model) so it becomes an Open Question rather than an
  assumption.

### Impact Map
- A single `table.grid` listing **every** column and input touched, one row each, with columns:
  Requirement tag &middot; Name &middot; Input/Column pill &middot; File &middot; Where declared &middot;
  What must change.
- Follow it with a short **ripple** subsection: columns that *read* the changed values and will
  therefore see different results even though their own code doesn't change. This is the part
  developers most often miss and testers most need.
- If a requirement is likely satisfiable **without a code change** (a pure assumption-file or
  table-sourcing change), say so explicitly and loudly — it is the single most valuable
  conclusion a study page like this can reach.

### Open Questions
- A numbered list of decisions the RSD leaves to the modelling team, each phrased as a question
  with the trade-off sketched in one or two sentences, and a recommendation where you have a
  defensible one.
- Include design-generality questions the RSD itself raised in passing (future scope hints), and
  any place where the literal ask and the stated intent point at different implementations.
- Do **not** resolve these silently in the earlier sections. This section existing is what keeps
  the rest of the page honest.

### Concept Checker
- A numbered list of questions testing the material in presentation order, mixing:
  - **RSD comprehension** ("Which of the three requirements requires no model output change?")
  - **Current-model concepts** ("What decides which row of the assumption table
    `hedge_inefficiency_aig` returns?")
  - **Assumption-file literacy** ("Which two workbooks exist today only because one table lacks a
    product dimension, and which table is it?" / "In the `*_set_aig` pattern, what selects which
    column of the table is active, and where is it set?")
  - **Impact reasoning** ("Name one column that will produce different values after R1 even
    though its own code is unchanged.")
- Each answer in a collapsed `<details>`, 1–3 sentences.

## 7. Style rules

- Short paragraphs and bullets over prose blocks. Bold the first mention of each named input,
  column, table, or product.
- Use the R*n* tags relentlessly — every callout, table row, and code tab should be traceable
  to a requirement.
- Quote the RSD rather than paraphrasing when its own wording is short and precise, and mark it
  as a quote. Paraphrase when it is long or written in pure product language.
- **Never invent product facts.** If the RSD says Vision MYG lapses differently but doesn't say
  by how much, do not supply a number. Say the RSD does not specify it and put it in Open
  Questions. **But do read it out of the workbook if it is there** — a value quoted from a real
  named table, with its file and range cited, is evidence, not invention, and is exactly what
  turns a vague requirement into a testable one.
- **Verify the RSD's own factual claims against the workbooks** and say so either way. When an RSD
  asserts "the current value of this input is 0% for all strategies… 5% for AICO other than
  Invesco," check the table and confirm it, or report what you actually found. Business authors
  write these from memory; a quiet correction here saves a wrong implementation later.
- Distinguish **workbook-side** from **code-side** vocabulary consistently. A *named table* /
  *tab* / *workbook* lives in Excel; an *input* / *column* / *descriptor* lives in the model. An
  RSD sentence usually mixes both, and separating them is most of the translation work.
- Don't editorialise about code quality, and don't propose refactors. Explain the model as it
  is; the RSD is the only source of what should change.
- Keep the developer's end state in view: after reading, they should be able to (1) restate each
  requirement in model terms, (2) name every input and column involved and say how each is keyed
  today, and (3) list what they still need to ask the business author.
