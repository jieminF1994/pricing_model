
#ifndef __SEG_COMP_UDF_H_
#define __SEG_COMP_UDF_H_

#include "ModelClass\seg_comp.h"

class SEG_COMP_UDF : public SEG_COMP {

	friend class SEG_COMP;

//constructor 
SEG_COMP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: SEG_COMP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
SEG_COMP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : SEG_COMP(columnCount, mocd, persObj) {}


// Accrued Income 
double seg_comp_accr_inc(int t);

// Accrued Income Investment Assets 
double seg_comp_accr_inc_inv(int t);

// Accrued Interest 
double seg_comp_accr_int(int t);

// Accrued Interest After Defaults 
double seg_comp_accr_int_aft_dflt(int t);

// Accrued Interest Default 
double seg_comp_accr_int_dflt(int t);

// Acquisition Expenses 
double seg_comp_acq_exp(int t);

// AG48 Net Premium Reserve Net 
double seg_comp_ag48_npr_net(int t);

// AG48 Reserve Excess Net 
double seg_comp_ag48_res_excess_net(int t);

// AG48 Reserve Net 
double seg_comp_ag48_res_net(int t);

// AG48 Unearned Premium Reserve Net 
double seg_comp_ag48_unearn_prem_res_npr_net(int t);

// Annuity Benefits Beginning of Month 
double seg_comp_ann_benefits_bom(int t);

// Annuity Benefits End of Month 
double seg_comp_ann_benefits_eom(int t);

// Annuitization Consideration 
double seg_comp_annuitzn_consideration(int t);

// Annuitization Count Monthly 
double seg_comp_annuitzn_count_aig(int t);

// Annuitization Income 
double seg_comp_annuitzn_inc(int t);

// Annuitization Value Released 
double seg_comp_annuitzn_val_released(int t);

// Asset Cash Flow 
double seg_comp_asset_cash_flow(int t);

// Asset Cash Flow Before Investments 
double seg_comp_asset_cash_flow_bef_inv(int t);

// Asset Cash Flow Before Sales 
double seg_comp_asset_cash_flow_bef_sale(int t);

// Assets Less Liabilities And Surplus 
double seg_comp_asset_less_liab_and_surp(int t);

// Asset Model Points Count 
double seg_comp_asset_mp_count(int t);

// Assets Separate Account 
double seg_comp_asset_sa(int t);

// Asset Yield 
double seg_comp_asset_yld(int t);

// Asset Yield Denominator 
double seg_comp_asset_yld_denom(int t);

// Asset Yield Denominator for Investment Asset 
double seg_comp_asset_yld_denom_inv(int t);

// Asset Yield on Investment Assets 
double seg_comp_asset_yld_inv(int t);

// Asset Yield with duration weighted adj 
double seg_comp_asset_yld_inv_adj_aig(int t);

// Asset Yield Less Default 
double seg_comp_asset_yld_less_dflt(int t);

// Asset Yield Less Default on Investment Assets 
double seg_comp_asset_yld_less_dflt_inv(int t);

// Asset Yield Less Default Numerator 
double seg_comp_asset_yld_less_dflt_numer(int t);

// Asset Yield Less Default Numerator for Investment Assets 
double seg_comp_asset_yld_less_dflt_numer_inv(int t);

// Asset Yield Numerator 
double seg_comp_asset_yld_numer(int t);

// Asset Yield Numerator for Investment Asset 
double seg_comp_asset_yld_numer_inv(int t);

// Asset Yield Numerator with duration weighted adj 
double seg_comp_asset_yld_numer_inv_adj_aig(int t);

// AVR 
double seg_comp_avr(int t);

// AVR Before Sales 
double seg_comp_avr_bef_sale(int t);

// AVR Bond 
double seg_comp_avr_bond(int t);

// AVR Bond Before Sales 
double seg_comp_avr_bond_bef_sale(int t);

// AVR Bond Beginning of Calendar Year 
double seg_comp_avr_bond_bocy(int t);

// AVR Detail Log Flag 
double seg_comp_avr_detail_log_flag(int t);

// AVR Default 
double seg_comp_avr_dflt(int t);

// AVR Default Before Sales 
double seg_comp_avr_dflt_bef_sale(int t);

// AVR Equity 
double seg_comp_avr_eqt(int t);

// AVR Equity Before Sales 
double seg_comp_avr_eqt_bef_sale(int t);

// AVR Increase 
double seg_comp_avr_incr(int t);

// AVR Mortgage 
double seg_comp_avr_mtg(int t);

// AVR Mortgage Before Sales 
double seg_comp_avr_mtg_bef_sale(int t);

// AVR Mortgage Beginning of Calendar Year 
double seg_comp_avr_mtg_bocy(int t);

// AVR Other 
double seg_comp_avr_other(int t);

// AVR Other Before Sales 
double seg_comp_avr_other_bef_sale(int t);

// AVR Other Beginning of Calendar Year 
double seg_comp_avr_other_bocy(int t);

// AVR Stock 
double seg_comp_avr_stock(int t);

// AVR Stock Before Sales 
double seg_comp_avr_stock_bef_sale(int t);

// AVR Stock Beginning of Calendar Year 
double seg_comp_avr_stock_bocy(int t);

// AVR Unrealized Capital Gain Equity Beginning of Calendar Year 
double seg_comp_avr_unrealzd_cap_gain_eqt_bocy(int t);

// AVR Unrealized Capital Gain Non Equity Beginning of Calendar Year 
double seg_comp_avr_unrealzd_cap_gain_non_eqt_bocy(int t);

// Before Tax Yield 
double seg_comp_bef_tax_yld(int t);

// Book Profit After Tax 
double seg_comp_bk_prof_aft_tax(int t);

// Book Profit After Tax Before Sales 
double seg_comp_bk_prof_aft_tax_bef_sale(int t);

// Book Profit After Tax Calendar Quarter to Date 
double seg_comp_bk_prof_aft_tax_qtd(int t);

// Book Profit After Tax Calendar Year to Date 
double seg_comp_bk_prof_aft_tax_ytd(int t);

// Book Profit Before Tax 
double seg_comp_bk_prof_bef_tax(int t);

// Book Profit Before Tax Before Sales 
double seg_comp_bk_prof_bef_tax_bef_sale(int t);

// Book Profit Before Tax Calendar Quarter to Date 
double seg_comp_bk_prof_bef_tax_qtd(int t);

// Book Profit Before Tax Calendar Year to Date 
double seg_comp_bk_prof_bef_tax_ytd(int t);

// Book Profit By Source Before Tax 
double seg_comp_bk_prof_by_source_bef_tax(int t);

// Book Value 
double seg_comp_bk_val(int t);

// Book Value Investment Assets 
double seg_comp_bk_val_inv(int t);

// Borrowing 
double seg_comp_borrowing(int t);

// Borrowing Interest 
double seg_comp_borrowing_int(int t);

// Borrowing Rate 
double seg_comp_borrowing_rate(int t);

// Calendar Month 
double seg_comp_cal_mth(int t);

// Calendar Year 
double seg_comp_cal_yr(int t);

// Calendar Year Relative 
double seg_comp_cal_yr_relative(int t);

// Capital Gains 
double seg_comp_cap_gain(int t);

// Capital Gains Before Sales 
double seg_comp_cap_gain_bef_sale(int t);

// Capital Gains on Free Surplus 
double seg_comp_cap_gain_free_surp(int t);

// Capital Gains on Free Surplus Before Sales 
double seg_comp_cap_gain_free_surp_bef_sale(int t);

// Capital Gains from Sales 
double seg_comp_cap_gain_from_sale(int t);

// Capital Gains on Reserve 
double seg_comp_cap_gain_res(int t);

// Capital Gains on Reserve Before Sales 
double seg_comp_cap_gain_res_bef_sale(int t);

// Capital Gains on Target Capital 
double seg_comp_cap_gain_tgt_cap(int t);

// Capital Gains on Target Capital Before Sales 
double seg_comp_cap_gain_tgt_cap_bef_sale(int t);

// Capital Gains on Undistributed Earnings 
double seg_comp_cap_gain_undistrib_earnings(int t);

// Capital Gains on Undistributed Earnings Before Sales 
double seg_comp_cap_gain_undistrib_earnings_bef_sale(int t);

// Cash 
double seg_comp_cash(int t);

// Cash Flow for Investment 
double seg_comp_cash_flow_for_inv(int t);

// Cash Flow Interest 
double seg_comp_cash_flow_int(int t);

// Cash Flow Invested 
double seg_comp_cash_flow_invested(int t);

// Cash Flow Rate Monthly 
double seg_comp_cash_flow_rate_mthly(int t);

// Cash from Sales 
double seg_comp_cash_from_sale(int t);

// Cash Interest 
double seg_comp_cash_int(int t);

// Cash Interest For Asset Yield Investment 
double seg_comp_cash_int_inv(int t);

// Cash Rate 
double seg_comp_cash_rate(int t);

// Cash Value 
double seg_comp_cash_val(int t);

// Claim Paid 
double seg_comp_claim_paid(int t);

// Commissions Beginning of Month 
double seg_comp_comm_bom(int t);

// Commission Chargeback 
double seg_comp_comm_chargeback(int t);

// Commissions End of Month 
double seg_comp_comm_eom(int t);

// Contribution From Business Segments 
double seg_comp_contribn_from_business_seg(int t);

// Contribution From Business Segment Before Sale 
double seg_comp_contribn_from_business_seg_bef_sale(int t);

// Conversion Cost 
double seg_comp_conversion_cost(int t);

// Cost Basis Accrual 
double seg_comp_cost_basis_accrual(int t);

// Cost Basis Increase Appreciation 
double seg_comp_cost_basis_incr_appreciation(int t);

// Cost Basis Purchase 
double seg_comp_cost_basis_purch(int t);

// Cost Basis Sale 
double seg_comp_cost_basis_sale(int t);

// Credited Interest 
double seg_comp_credited_int(int t);

// Date 
double seg_comp_date(int t);

// Deferred Gross Premium 
double seg_comp_deferred_gross_prem(int t);

// Deferred Gross Premium Increase 
double seg_comp_deferred_gross_prem_incr(int t);

// Deferred Net Premium 
double seg_comp_deferred_net_prem(int t);

// Deferred Net Premium Net 
double seg_comp_deferred_net_prem_net(int t);

// Deferred Net Premium NPR 
double seg_comp_deferred_net_prem_npr(int t);

// Deferred Net Premium NPR Net 
double seg_comp_deferred_net_prem_npr_net(int t);

// Delta Hedge Investment Amount 
double seg_comp_delta_hedge_inv_amt(int t);

// Delta Hedge Market Value of Assets 
double seg_comp_delta_hedge_mkt_val(int t);

// Delta Hedge Market Value of Assets Increase 
double seg_comp_delta_hedge_mkt_val_incr(int t);

// Delta Hedge Derivative Payment 
double seg_comp_delta_hedge_pmt(int t);

// Delta Hedge Prof 
double seg_comp_delta_hedge_prof(int t);

// Delta Hedge Sale Amount 
double seg_comp_delta_hedge_sale_amt(int t);

// Delta Hedge Transaction Cost 
double seg_comp_delta_hedge_transaction_cost(int t);

// Default Amount 
double seg_comp_dflt_amt(int t);

// Direct Cash Flow Beginning of Month 
double seg_comp_direct_cash_flow_bom(int t);

// Direct Cash Flow End of Month 
double seg_comp_direct_cash_flow_eom(int t);

// Direct Cash Flow Interest 
double seg_comp_direct_cash_flow_int(int t);

// Distributable Earnings 
double seg_comp_distrib_earnings(int t);

// Distributable Earnings Before Sales 
double seg_comp_distrib_earnings_bef_sale(int t);

// Distribution 
double seg_comp_distribn(int t);

// Distribution Before Sales 
double seg_comp_distribn_bef_sale(int t);

// Dividend Applied 
double seg_comp_div_applied(int t);

// Dividend Liability 
double seg_comp_div_liab(int t);

// Dividend Liability Increase 
double seg_comp_div_liab_incr(int t);

// Dividend Paid 
double seg_comp_div_paid(int t);

// Death Benefit In Force 
double seg_comp_dth_ben_inf(int t);

// Death Benefits 
double seg_comp_dth_benefits(int t);

// Death Count Monthly 
double seg_comp_dth_count_aig(int t);

// Accumulated Earnings 
double seg_comp_earnings_accum(int t);

// Economic Cash Amount 
double seg_comp_econ_cash(int t);

// Interest Earned on Economic Cash Amount 
double seg_comp_econ_cash_int(int t);

// Economic Profit 
double seg_comp_econ_prof(int t);

// Unhedged Economic Profit 
double seg_comp_econ_prof_unhedged(int t);

// Economic Reserve: Present Value of Claims - Present Value of Charges 
double seg_comp_econ_res(int t);

// Economic Reserve Increase 
double seg_comp_econ_res_incr(int t);

// Interest Earned on Economic Reserve 
double seg_comp_econ_res_int(int t);

// Effective Capital Gains Rate 
double seg_comp_eff_cap_gains_rate(int t);

// Endowment Benefits 
double seg_comp_endow_benefits(int t);

// Finalize 
double seg_comp_finalize(int t);

// Free Surplus 
double seg_comp_free_surp(int t);

// Free Surplus at Market 
double seg_comp_free_surp_at_mkt(int t);

// Free Surplus at Market Ending 
double seg_comp_free_surp_at_mkt_ending(int t);

// Free Surplus Before Distribution 
double seg_comp_free_surp_bef_distribn(int t);

// Free Surplus Increase 
double seg_comp_free_surp_incr(int t);

// Fund Value released on Annuitization 
double seg_comp_fund_released_ann(int t);

// Fund Value released on Death 
double seg_comp_fund_released_dth(int t);

// Fund Value released on Maturity 
double seg_comp_fund_released_maturity(int t);

// Fund Value released on Surrender 
double seg_comp_fund_released_surr(int t);

// Fund Value released on Withdrawal 
double seg_comp_fund_released_withdrl(int t);

// Fund Val Bom 
double seg_comp_fund_val_b(int t);

// Fund Value Fixed Account 
double seg_comp_fund_val_fixed(int t);

// Fund Value Separate Account 
double seg_comp_fund_val_sa(int t);

// Fund Weighted Cap Spread Rate Aig 
double seg_comp_fund_weighted_cap_spread_fix_rt_aig(int t);

// Fund Weighted Par Rate Aig 
double seg_comp_fund_weighted_par_rate_aig(int t);

// Fund Weighted Pri Spread Aig 
double seg_comp_fund_weighted_pri_spread_aig(int t);

// GAAP Accumulation Benefit Claim Cost 
double seg_comp_gaap_accum_ben_claim_cost(int t);

// GAAP Acquisition Expenses 
double seg_comp_gaap_acq_exp(int t);

// GAAP Annuity Claim Cost 
double seg_comp_gaap_ann_claim_cost(int t);

// GAAP Benefit Reserve 
double seg_comp_gaap_ben_res(int t);

// GAAP Benefit Reserve Increase 
double seg_comp_gaap_ben_res_incr(int t);

// GAAP Capital Gains on Capital 
double seg_comp_gaap_cap_gain_cap(int t);

// GAAP Capital Gain on Reserves 
double seg_comp_gaap_cap_gain_res(int t);

// GAAP Capitalized Acquisition Expenses 
double seg_comp_gaap_capzd_acq_exp(int t);

// GAAP Capitalized Commissions BOM 
double seg_comp_gaap_capzd_comm_bom(int t);

// GAAP Capitalized Commissions EOM 
double seg_comp_gaap_capzd_comm_eom(int t);

// GAAP Capitalized Premium Bonus 
double seg_comp_gaap_capzd_prem_bonus(int t);

// GAAP Capitalized Reinsurance YRT Cost 
double seg_comp_gaap_capzd_reins_yrt_cost(int t);

// GAAP Cash Flow Interest 
double seg_comp_gaap_cash_flow_int(int t);

// GAAP Charges Income 
double seg_comp_gaap_chg_inc(int t);

// GAAP Claim Reserve 
double seg_comp_gaap_claim_res(int t);

// GAAP Claim Reserve Increase 
double seg_comp_gaap_claim_res_incr(int t);

// GAAP Commission Excess BOM 
double seg_comp_gaap_comm_excess_bom(int t);

// GAAP Commission Excess EOM 
double seg_comp_gaap_comm_excess_eom(int t);

// GAAP Commission Trail BOM 
double seg_comp_gaap_comm_trail_bom(int t);

// GAAP Commission Trail EOM 
double seg_comp_gaap_comm_trail_eom(int t);

// GAAP Conersion Cost 
double seg_comp_gaap_conversion_cost(int t);

// GAAP Credited Interest 
double seg_comp_gaap_credited_int(int t);

// GAAP DAC 
double seg_comp_gaap_dac(int t);

// GAAP DAC Increase 
double seg_comp_gaap_dac_incr(int t);

// GAAP Deferred Maintenance Expenses 
double seg_comp_gaap_deferred_maint_exp(int t);

// GAAP Deferred Profit Liability 
double seg_comp_gaap_deferred_prof_liab(int t);

// GAAP Deferred Profit Liability Increase 
double seg_comp_gaap_deferred_prof_liab_incr(int t);

// GAAP Deferred Tax Liability 
double seg_comp_gaap_deferred_tax_liab(int t);

// GAAP Deferred Tax Liability Increase 
double seg_comp_gaap_deferred_tax_liab_incr(int t);

// GAAP Dividend Applied 
double seg_comp_gaap_div_applied(int t);

// GAAP Dividend Liability 
double seg_comp_gaap_div_liab(int t);

// GAAP Dividend Liability Increase 
double seg_comp_gaap_div_liab_incr(int t);

// GAAP Dividend Paid 
double seg_comp_gaap_div_paid(int t);

// GAAP Death Claim Cost 
double seg_comp_gaap_dth_claim_cost(int t);

// GAAP Endowment Claim Cost 
double seg_comp_gaap_endow_claim_cost(int t);

// GAAP Free Surplus 
double seg_comp_gaap_free_surp(int t);

// GAAP Gross Premium 
double seg_comp_gaap_gross_prem(int t);

// GAAP Hedge Cost 
double seg_comp_gaap_hedge_cost(int t);

// GAAP Hedge Market Value 
double seg_comp_gaap_hedge_mkt_val(int t);

// GAAP Hedge Market Value Increase 
double seg_comp_gaap_hedge_mkt_val_incr(int t);

// GAAP Health Claim Cost 
double seg_comp_gaap_hlth_claim_cost(int t);

// GAAP Income After Tax 
double seg_comp_gaap_inc_aft_tax(int t);

// GAAP Income After Tax Calendar Quarter to Date 
double seg_comp_gaap_inc_aft_tax_qtd(int t);

// GAAP Income After Tax Calendar Year to Date 
double seg_comp_gaap_inc_aft_tax_ytd(int t);

// GAAP Income Before Tax 
double seg_comp_gaap_inc_bef_tax(int t);

// GAAP Income Before Tax Calendar Quarter to Date 
double seg_comp_gaap_inc_bef_tax_qtd(int t);

// GAAP Income Before Tax Calendar Year to Date 
double seg_comp_gaap_inc_bef_tax_ytd(int t);

// GAAP Income Benefit Claim Cost 
double seg_comp_gaap_inc_ben_claim_cost(int t);

// GAAP Income Deferred Tax Liability 
double seg_comp_gaap_inc_deferred_tax_liab(int t);

// GAAP Income Invested Assets 
double seg_comp_gaap_inc_inv_asset(int t);

// GAAP Income Unrealized Capital Gain 
double seg_comp_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Income Unrealized Capital Gain Increase 
double seg_comp_gaap_inc_unrealzd_cap_gain_incr(int t);

// GAAP Invested Assets 
double seg_comp_gaap_inv_asset(int t);

// GAAP Invested Assets - Available for Sale 
double seg_comp_gaap_inv_asset_available(int t);

// GAAP Invested Assets - Held to Maturity 
double seg_comp_gaap_inv_asset_held(int t);

// GAAP Invested Assets - Not Assigned 
double seg_comp_gaap_inv_asset_not_assigned(int t);

// GAAP Invested Assets - Trading 
double seg_comp_gaap_inv_asset_trading(int t);

// GAAP Investment Income on Capital 
double seg_comp_gaap_inv_inc_cap(int t);

// GAAP Investment Income on Reserves 
double seg_comp_gaap_inv_inc_res(int t);

// GAAP Liability Net of DAC 
double seg_comp_gaap_liab_net(int t);

// GAAP Liability Net of DAC Net 
double seg_comp_gaap_liab_net_net(int t);

// GAAP Loads Deducted 
double seg_comp_gaap_loads_deducted(int t);

// GAAP Loads Deferred 
double seg_comp_gaap_loads_deferred(int t);

// GAAP Letter of Credit Cost 
double seg_comp_gaap_loc_cost(int t);

// GAAP Maintenance Expenses BOM 
double seg_comp_gaap_maint_exp_bom(int t);

// GAAP Maintenance Expenses EOM 
double seg_comp_gaap_maint_exp_eom(int t);

// GAAP Maintenance Expense Reserve 
double seg_comp_gaap_maint_exp_res(int t);

// GAAP Maintenance Expense Reserve Increase 
double seg_comp_gaap_maint_exp_res_incr(int t);

// GAAP Maturity Claim Cost 
double seg_comp_gaap_maturity_claim_cost(int t);

// GAAP Premium Bonus 
double seg_comp_gaap_prem_bonus(int t);

// GAAP Premium Taxes 
double seg_comp_gaap_prem_tax(int t);

// GAAP Premium Waiver Reserve 
double seg_comp_gaap_prem_waiver_res(int t);

// GAAP Premium Waiver Reserve Increase 
double seg_comp_gaap_prem_waiver_res_incr(int t);

// GAAP Profit After Tax for Present Values 
double seg_comp_gaap_prof_aft_tax_for_pv(int t);

// GAAP Profit Before Tax for Present Values 
double seg_comp_gaap_prof_bef_tax_for_pv(int t);

// GAAP Reinsurance YRT Cost 
double seg_comp_gaap_reins_yrt_cost(int t);

// GAAP Required Capital 
double seg_comp_gaap_req_cap(int t);

// GAAP SFAS 133 Liability 
double seg_comp_gaap_sfas133_liab(int t);

// GAAP SFAS 133 Liability Increase 
double seg_comp_gaap_sfas133_liab_incr(int t);

// GAAP SOP 03-1 Additional Liability 
double seg_comp_gaap_sop031_addl_liab(int t);

// GAAP SOP 03-1 Additional Liability Increase 
double seg_comp_gaap_sop031_addl_liab_incr(int t);

// GAAP Surplus Increase 
double seg_comp_gaap_surp_incr(int t);

// GAAP Surplus Unrealized Capital Gain 
double seg_comp_gaap_surp_unrealzd_cap_gain(int t);

// GAAP Surplus Unrealized Capital Gain Increase 
double seg_comp_gaap_surp_unrealzd_cap_gain_incr(int t);

// GAAP Surrender Claim Cost 
double seg_comp_gaap_surr_claim_cost(int t);

// GAAP Surrender Income 
double seg_comp_gaap_surr_inc(int t);

// GAAP Terminal Dividends 
double seg_comp_gaap_terminal_div(int t);

// GAAP Unearned Revenue Liability 
double seg_comp_gaap_unearn_rev_liab(int t);

// GAAP Unearned Revenue Released 
double seg_comp_gaap_unearn_rev_released(int t);

// GAAP Unrealized Capital Gain Increase 
double seg_comp_gaap_unrealzd_cap_gain_incr(int t);

// GAAP Withdrawal Benefit Claim Cost 
double seg_comp_gaap_withdrl_ben_claim_cost(int t);

// Gamma Hedge Investment Amount 
double seg_comp_gamma_hedge_inv_amt(int t);

// Gamma Hedge Market Value of Assets 
double seg_comp_gamma_hedge_mkt_val(int t);

// Gamma Hedge Market Value of Assets Increase 
double seg_comp_gamma_hedge_mkt_val_incr(int t);

// Gamma Hedge Derivative Payment 
double seg_comp_gamma_hedge_pmt(int t);

// Gamma Hedge Profit 
double seg_comp_gamma_hedge_prof(int t);

// Gamma Hedge Sale Amount 
double seg_comp_gamma_hedge_sale_amt(int t);

// Gamma Hedge Transaction Cost 
double seg_comp_gamma_hedge_transaction_cost(int t);

// GMWB Rider charge 
double seg_comp_gmwb_chg(int t);

// Annuity GMWB Base 
double seg_comp_gmwb_inf(int t);

// Gross Premium Annualized 
double seg_comp_gross_prem_annualzd(int t);

// Hedge Cash Flow 
double seg_comp_hedge_cash_flow(int t);

// Hedge Cost 
double seg_comp_hedge_cost(int t);

// Hedge Cost Before Sale 
double seg_comp_hedge_cost_bef_sale(int t);

// Hedge Cost Charge 
double seg_comp_hedge_cost_charge(int t);

// Hedge Expense 
double seg_comp_hedge_exp(int t);

// Hedge Interest Payment 
double seg_comp_hedge_int_pmt(int t);

// Hedge Investment Amount Beginning of Month 
double seg_comp_hedge_inv_amt_bom(int t);

// Hedge Investment Amount End of Month 
double seg_comp_hedge_inv_amt_eom(int t);

// Hedged Liability GMXB Claims 
double seg_comp_hedge_liab_claims(int t);

// Hedge Market Value 
double seg_comp_hedge_mkt_val(int t);

// Hedge Market Value Growth 
double seg_comp_hedge_mkt_val_growth(int t);

// Hedge Market Value Increase 
double seg_comp_hedge_mkt_val_incr(int t);

// Hedge Option Payment 
double seg_comp_hedge_opt_pmt(int t);

// rila trading cost 
double seg_comp_hedge_rila_trading_cost_aig(int t);

// Hedge Sale Amount 
double seg_comp_hedge_sale_amt(int t);

// IMR 
double seg_comp_imr(int t);

// IMR Amortization adjustment for Month 
double seg_comp_imr_amortzn_adj(int t);

// IMR Amortization for Month 
double seg_comp_imr_amortzn_for_mth(int t);

// IMR Amortization for Month Before Sales 
double seg_comp_imr_amortzn_for_mth_bef_sale(int t);

// IMR Before Sales 
double seg_comp_imr_bef_sale(int t);

// IMR Capital Gain 
double seg_comp_imr_cap_gain(int t);

// IMR Capital Gain Before Sales 
double seg_comp_imr_cap_gain_bef_sale(int t);

// IMR Capital Gain Net of Taxes 
double seg_comp_imr_cap_gain_net(int t);

// IMR Capital Gain Net of Taxes Before Sales 
double seg_comp_imr_cap_gain_net_bef_sale(int t);

// IMR Capital Gains Tax 
double seg_comp_imr_cap_gain_tax(int t);

// IMR Capital Gains Tax Before Sales 
double seg_comp_imr_cap_gain_tax_bef_sale(int t);

// IMR Impact on Free Surplus 
double seg_comp_imr_impact_free_surp(int t);

// IMR Impact on Free Surplus Before Sales 
double seg_comp_imr_impact_free_surp_bef_sale(int t);

// IMR Impact on Reserves 
double seg_comp_imr_impact_res(int t);

// IMR Impact on Reserve Before Sales 
double seg_comp_imr_impact_res_bef_sale(int t);

// IMR Impact on Target Capital 
double seg_comp_imr_impact_tgt_cap(int t);

// IMR Impact on Target Capital Before Sales 
double seg_comp_imr_impact_tgt_cap_bef_sale(int t);

// IMR Increase 
double seg_comp_imr_incr(int t);

// IMR Increase Before Sales 
double seg_comp_imr_incr_bef_sale(int t);

// Inflation Cumulative 
double seg_comp_infl_cumul(int t);

// Initialize 
double seg_comp_initialize(int t);

// Interest Payment 
double seg_comp_int_pmt(int t);

// Interim Cash 
double seg_comp_interim_cash(int t);

// Interim Cash Interest 
double seg_comp_interim_cash_int(int t);

// Interim Cash Rate 
double seg_comp_interim_cash_rate(int t);

// Invested Assets 
double seg_comp_inv_asset(int t);

// Investment Cash Flow Interest Dividend and Rent 
double seg_comp_inv_cash_flow_int_div_and_rent(int t);

// Investment Cash Flow Principal Payment 
double seg_comp_inv_cash_flow_prin_pmt(int t);

// Investment Expenses 
double seg_comp_inv_exp(int t);

// Investment Fee Refund 
double seg_comp_inv_fee_ref(int t);

// Investment Income 
double seg_comp_inv_inc(int t);

// Investment Income For Book Profit 
double seg_comp_inv_inc_bk_prof(int t);

// Investment Income For Book Profit Before Sales 
double seg_comp_inv_inc_bk_prof_bef_sale(int t);

// Investment Income on Accumulated Earnings 
double seg_comp_inv_inc_earnings_accum(int t);

// Investment Income on Free Surplus 
double seg_comp_inv_inc_free_surp(int t);

// Investment Income on Fixed Fund Value 
double seg_comp_inv_inc_fund(int t);

// Investment Income on Invested Assets 
double seg_comp_inv_inc_on_invested_assets(int t);

// Investment Income on Reserves 
double seg_comp_inv_inc_res(int t);

// Investment Income on Target Capital 
double seg_comp_inv_inc_tgt_cap(int t);

// Investment Income on Undistributed Earnings 
double seg_comp_inv_inc_undistrib_earnings(int t);

// Invested Asset Sales 
double seg_comp_invested_asset_sale(int t);

// Lapse Count Monthly 
double seg_comp_lapse_count_aig(int t);

// Last Period Indicator 
double seg_comp_last_period_indicator(int t);

// Liabilities and Surplus Net of Reinsurance 
double seg_comp_liab_and_surp(int t);

// Liability Cash Flow 
double seg_comp_liab_cash_flow(int t);

// Liability Cash Flow Beginning of Month 
double seg_comp_liab_cash_flow_bom(int t);

// Liability Cash Flow End of Month 
double seg_comp_liab_cash_flow_eom(int t);

// Letter of Credit Asset 
double seg_comp_loc_asset(int t);

// LOC Asset Increase 
double seg_comp_loc_asset_incr(int t);

// LOC Cost 
double seg_comp_loc_cost(int t);

// Maintenance Expenses Beginning of Month 
double seg_comp_maint_exp_bom(int t);

// Maintenance Expenses End of Month 
double seg_comp_maint_exp_eom(int t);

// Maintenance Expenses Fixed 
double seg_comp_maint_exp_fixed(int t);

// Maturity Benefits 
double seg_comp_maturity_benefits(int t);

// Market Value 
double seg_comp_mkt_val(int t);

// Market Value Sale 
double seg_comp_mkt_val_sale(int t);

// Months to Next Market Value Calculation 
double seg_comp_mths_to_next_mkt_val_calc(int t);

// Notional Amount 
double seg_comp_notional_amt(int t);

// Option Budget Amount 
double seg_comp_opt_budget_amt(int t);

// Option Income 
double seg_comp_opt_inc(int t);

// Option Payoff AIG 
double seg_comp_opt_payoff_aig(int t);

// Option Payment 
double seg_comp_opt_pmt(int t);

// PBA Rollforward Base 
double seg_comp_pba_rollforward_base(int t);

// PBA Rollforward Factor 
double seg_comp_pba_rollforward_factor(int t);

// Policy Loan 
double seg_comp_pol_loan(int t);

// Policy Loan Expense 
double seg_comp_pol_loan_exp(int t);

// Policy Loan Income 
double seg_comp_pol_loan_inc(int t);

// Policy Loan Interest 
double seg_comp_pol_loan_int(int t);

// Policy Loan Proceeds 
double seg_comp_pol_loan_proceeds(int t);

// Policies In Force 
double seg_comp_policies_inf(int t);

// Policies Issued 
double seg_comp_policies_issued(int t);

// Portfolio Yield 
double seg_comp_port_yld(int t);

// Portfolio Yield After Tax 
double seg_comp_port_yld_aft_tax(int t);

// Portfolio Yield Denominator 
double seg_comp_port_yld_denom(int t);

// Portfolio Yield Less Default 
double seg_comp_port_yld_less_dflt(int t);

// Premium Bonus 
double seg_comp_prem_bonus(int t);

// Premium Issued 
double seg_comp_prem_issued(int t);

// Premiums Paid 
double seg_comp_prem_paid(int t);

// Premium Taxes 
double seg_comp_prem_tax(int t);

// Premium Waiver Benefits 
double seg_comp_prem_waiver_benefits(int t);

// Projection Target - Hedging Statement Calculations 
double seg_comp_proj_tgt_hedge_stmt(int t);

// RBC 
double seg_comp_rbc(int t);

// RBC Before Sales 
double seg_comp_rbc_bef_sale(int t);

// RBC C1 
double seg_comp_rbc_c1(int t);

// RBC C1 Before Sales 
double seg_comp_rbc_c1_bef_sale(int t);

// RBC C1 Equity 
double seg_comp_rbc_c1_eqt(int t);

// RBC C1 Equity Before Sales 
double seg_comp_rbc_c1_eqt_bef_sale(int t);

// RBC C1 Non Equity 
double seg_comp_rbc_c1_non_eqt(int t);

// RBC C1 Non Equity Before Sales 
double seg_comp_rbc_c1_non_eqt_bef_sale(int t);

// RBC C1 Unearned Premium Reserve Deficiency 
double seg_comp_rbc_c1_unearn_prem_res_def(int t);

// RBC C2 
double seg_comp_rbc_c2(int t);

// RBC C2 Incurred Claim 
double seg_comp_rbc_c2_claim(int t);

// RBC C2 Incurred Claim Previous Year 
double seg_comp_rbc_c2_claim_prev_yr(int t);

// RBC C2 Loss Ratio 
double seg_comp_rbc_c2_loss_ratio(int t);

// RBC C2 Net Amount at Risk 
double seg_comp_rbc_c2_nar(int t);

// RBC C2 Earned Premium 
double seg_comp_rbc_c2_prem(int t);

// RBC C2 Earned Premium Previous Year 
double seg_comp_rbc_c2_prem_prev_yr(int t);

// RBC C3 
double seg_comp_rbc_c3(int t);

// RBC C3 Hedge Offset 
double seg_comp_rbc_c3_hedge_offset(int t);

// RBC C3 Policy Amount 
double seg_comp_rbc_c3_mp(int t);

// RBC C3 Standard Scenario Amount 
double seg_comp_rbc_c3_std_scen_amt(int t);

// RBC C3 Standard Scenario Amount Unhedged 
double seg_comp_rbc_c3_std_scen_amt_unhedged(int t);

// RBC C3 Stochastic Amount 
double seg_comp_rbc_c3_stoch_amt(int t);

// RBC C3 Stochastic Amount Unhedged 
double seg_comp_rbc_c3_stoch_amt_unhedged(int t);

// RBC C3 Unhedged 
double seg_comp_rbc_c3_unhedged(int t);

// RBC C4 
double seg_comp_rbc_c4(int t);

// RBC Cash Amount 
double seg_comp_rbc_cash(int t);

// RBC Cash Before Sales 
double seg_comp_rbc_cash_bef_sale(int t);

// Realized Capital Gains 
double seg_comp_realzd_cap_gain(int t);

// Realized Capital Gains Before Sales 
double seg_comp_realzd_cap_gain_bef_sale(int t);

// Realized Capital Gains on Free Surplus 
double seg_comp_realzd_cap_gain_free_surp(int t);

// Realized Capital Gains on Free Surplus Before Sales 
double seg_comp_realzd_cap_gain_free_surp_bef_sale(int t);

// Realized Capital Gains on Free Surplus Calendar Year to Date 
double seg_comp_realzd_cap_gain_free_surp_ytd(int t);

// Realized Capital Gains on Free Surplus Calendar Year to Date Before Sales 
double seg_comp_realzd_cap_gain_free_surp_ytd_bef_sale(int t);

// Realized Capital Gains on Fixed Fund Value 
double seg_comp_realzd_cap_gain_fund(int t);

// Realized Capital Gains on Reserve 
double seg_comp_realzd_cap_gain_res(int t);

// Realized Capital Gains on Reserve Before Sales 
double seg_comp_realzd_cap_gain_res_bef_sale(int t);

// Realized Capital Gains on Reserves Calendar Year to Date 
double seg_comp_realzd_cap_gain_res_ytd(int t);

// Realized Capital Gains on Reserves Calendar Year to Date Before Sales 
double seg_comp_realzd_cap_gain_res_ytd_bef_sale(int t);

// Realized Capital Gains from Sales 
double seg_comp_realzd_cap_gain_sale(int t);

// Realized Capital Gains on Target Capital 
double seg_comp_realzd_cap_gain_tgt_cap(int t);

// Realized Capital Gains on Target Capital Before Sales 
double seg_comp_realzd_cap_gain_tgt_cap_bef_sale(int t);

// Realized Capital Gains on Target Capital Calendar Year to Date 
double seg_comp_realzd_cap_gain_tgt_cap_ytd(int t);

// Realized Capital Gains Target Capital on Calendar Year to Date Before Sales 
double seg_comp_realzd_cap_gain_tgt_cap_ytd_bef_sale(int t);

// Realized Capital Gains on Undistributed Earnings 
double seg_comp_realzd_cap_gain_undistrib_earnings(int t);

// Realized Capital Gains on Undistributed Earnings Before Sales 
double seg_comp_realzd_cap_gain_undistrib_earnings_bef_sale(int t);

// Realized Capital Gains on Undistributed Earnings Calendar Year to Date 
double seg_comp_realzd_cap_gain_undistrib_earnings_ytd(int t);

// Realized Capital Gains on Undistributed Earnings Calendar Year to Date Before Sale 
double seg_comp_realzd_cap_gain_undistrib_earnings_ytd_bef_sale(int t);

// Reinsurance Annuity Benefits Beginning of Month 
double seg_comp_reins_ann_benefits_bom(int t);

// Reinsurance Annuity Benefits End of Month 
double seg_comp_reins_ann_benefits_eom(int t);

// Reinsurance Capital Gains on Reserve 
double seg_comp_reins_cap_gain_res(int t);

// Reinsurance Capital Gains on Reserve Before Sales 
double seg_comp_reins_cap_gain_res_bef_sale(int t);

// Reinsurance Cash Flow Beginning of Month 
double seg_comp_reins_cash_flow_bom(int t);

// Reinsurance Cash Flow End of Month 
double seg_comp_reins_cash_flow_eom(int t);

// Reinsurance Cash Flow Interest 
double seg_comp_reins_cash_flow_int(int t);

// Reinsurance Cash Value 
double seg_comp_reins_cash_val(int t);

// Reinsurance Claim Paid 
double seg_comp_reins_claim_paid(int t);

// Reinsurance Commission Chargeback Reimbursement 
double seg_comp_reins_comm_chargeback_reimb(int t);

// Reinsurance Commission Reimbursed 
double seg_comp_reins_comm_reimb(int t);

// Reinsurance Commission Reimbursement Beginning of Month 
double seg_comp_reins_comm_reimb_bom(int t);

// Reinsurance Commission Reimbursement End of Month 
double seg_comp_reins_comm_reimb_eom(int t);

// Reinsurance Deferred Gross Premium 
double seg_comp_reins_deferred_gross_prem(int t);

// Reinsurance Deferred Gross Premium Increase 
double seg_comp_reins_deferred_gross_prem_incr(int t);

// Reinsurance Deferred Net Premium 
double seg_comp_reins_deferred_net_prem(int t);

// Reinsurance Dividend Applied 
double seg_comp_reins_div_applied(int t);

// Reinsurance Dividend Liability 
double seg_comp_reins_div_liab(int t);

// Reinsurance Dividend Liability Increase 
double seg_comp_reins_div_liab_incr(int t);

// Reinsurance Dividend Paid 
double seg_comp_reins_div_paid(int t);

// Reinsured Death Benefit In Force 
double seg_comp_reins_dth_ben_inf(int t);

// Reinsurance Death Benefits 
double seg_comp_reins_dth_benefits(int t);

// Reinsurance Expense Allowance 
double seg_comp_reins_ea(int t);

// Reinsurance Expense Allowance Chargeback 
double seg_comp_reins_ea_chargeback(int t);

// Reinsurance Endowment Benefits 
double seg_comp_reins_endow_benefits(int t);

// Reinsurance Expense 
double seg_comp_reins_exp(int t);

// Reinsurance Expense Reimbursed 
double seg_comp_reins_exp_reimb(int t);

// Reinsurance Expense Reimbursed Beginning of Month 
double seg_comp_reins_exp_reimb_bom(int t);

// Reinsurance Expense Reimbursed End of Month 
double seg_comp_reins_exp_reimb_eom(int t);

// Reinsurance GAAP Benefit Reserve 
double seg_comp_reins_gaap_ben_res(int t);

// Reinsurance GAAP Benefit Reserve Increase 
double seg_comp_reins_gaap_ben_res_incr(int t);

// Reinsurance GAAP Capital Gain on Reserves 
double seg_comp_reins_gaap_cap_gain_res(int t);

// Reinsurance GAAP Capitalized Commissions BOM 
double seg_comp_reins_gaap_capzd_comm_bom(int t);

// Reinsurance GAAP Capitalized Commissions EOM 
double seg_comp_reins_gaap_capzd_comm_eom(int t);

// Reinsurance GAAP Capitalized Premium Bonus 
double seg_comp_reins_gaap_capzd_prem_bonus(int t);

// Reinsurance GAAP Cash Flow Interest 
double seg_comp_reins_gaap_cash_flow_int(int t);

// Reinsurance GAAP Charges Income 
double seg_comp_reins_gaap_chg_inc(int t);

// Reinsurance GAAP Claim Reserve 
double seg_comp_reins_gaap_claim_res(int t);

// Reinsurance GAAP Claim Reserve Increase 
double seg_comp_reins_gaap_claim_res_incr(int t);

// Reinsurance GAAP Commission Excess BOM 
double seg_comp_reins_gaap_comm_excess_bom(int t);

// Reinsurance GAAP Commission Excess EOM 
double seg_comp_reins_gaap_comm_excess_eom(int t);

// Reinsurance GAAP Commission Trail BOM 
double seg_comp_reins_gaap_comm_trail_bom(int t);

// Reinsurance GAAP Commission Trail EOM 
double seg_comp_reins_gaap_comm_trail_eom(int t);

// Reinsurance GAAP Cost 
double seg_comp_reins_gaap_cost(int t);

// Reinsurance GAAP Credited Interest 
double seg_comp_reins_gaap_credited_int(int t);

// Reinsurance GAAP DAC 
double seg_comp_reins_gaap_dac(int t);

// Reinsurance GAAP DAC Increase 
double seg_comp_reins_gaap_dac_incr(int t);

// Reinsurance GAAP Deferred Maintenance Expense 
double seg_comp_reins_gaap_deferred_maint_exp(int t);

// Reinsurance GAAP Deferred Profit Liability 
double seg_comp_reins_gaap_deferred_prof_liab(int t);

// Reinsurance GAAP Deferred Profit Liability Increase 
double seg_comp_reins_gaap_deferred_prof_liab_incr(int t);

// Reinsurance GAAP Dividend Applied 
double seg_comp_reins_gaap_div_applied(int t);

// Reinsurance GAAP Dividend Liability 
double seg_comp_reins_gaap_div_liab(int t);

// Reinsurance GAAP Dividend Liability Increase 
double seg_comp_reins_gaap_div_liab_incr(int t);

// Reinsurance GAAP Dividend Paid 
double seg_comp_reins_gaap_div_paid(int t);

// Reinsurance GAAP Death Claim Cost 
double seg_comp_reins_gaap_dth_claim_cost(int t);

// Reinsurance GAAP Investment Income on Reserves 
double seg_comp_reins_gaap_inv_inc_res(int t);

// Reinsurance GAAP Recoverables Net of DAC 
double seg_comp_reins_gaap_liab_net(int t);

// Reinsurance GAAP Loads Deducted 
double seg_comp_reins_gaap_loads_deducted(int t);

// Reinsurance GAAP Loads Deferred 
double seg_comp_reins_gaap_loads_deferred(int t);

// Reinsurance GAAP Maintenance Expenses BOM 
double seg_comp_reins_gaap_maint_exp_bom(int t);

// Reinsurance GAAP Maintenance Expenses EOM 
double seg_comp_reins_gaap_maint_exp_eom(int t);

// Reinsurance GAAP Maintenance Expense Reserve 
double seg_comp_reins_gaap_maint_exp_res(int t);

// Reinsurance GAAP Maintenance Expense Reserve Increase 
double seg_comp_reins_gaap_maint_exp_res_incr(int t);

// Reinsurance GAAP Modco Liability 
double seg_comp_reins_gaap_modco_liab(int t);

// Reinsurance GAAP Modco Liability Increase 
double seg_comp_reins_gaap_modco_liab_incr(int t);

// Reinsurance GAAP Modco Reserve Adjustment 
double seg_comp_reins_gaap_modco_res_adj(int t);

// Reinsurance GAAP Premium 
double seg_comp_reins_gaap_prem(int t);

// Reinsurance GAAP Premium Bonus 
double seg_comp_reins_gaap_prem_bonus(int t);

// Reinsurance GAAP Premium Taxes 
double seg_comp_reins_gaap_prem_tax(int t);

// Reinsurance GAAP Premium Waiver Reserve 
double seg_comp_reins_gaap_prem_waiver_res(int t);

// Reinsurance GAAP Premium Waiver Reserve Increase 
double seg_comp_reins_gaap_prem_waiver_res_incr(int t);

// Reinsurance GAAP Recoveries 
double seg_comp_reins_gaap_recoveries(int t);

// Reinsurance GAAP Refund 
double seg_comp_reins_gaap_refund(int t);

// Reinsurance GAAP SFAS 133 Liability 
double seg_comp_reins_gaap_sfas133_liab(int t);

// Reinsurance GAAP SFAS 133 Liability Increase 
double seg_comp_reins_gaap_sfas133_liab_incr(int t);

// Reinsurance GAAP SOP 03-1 Additional Liability 
double seg_comp_reins_gaap_sop031_addl_liab(int t);

// Reinsurance GAAP SOP 03-1 Additional Liability Increase 
double seg_comp_reins_gaap_sop031_addl_liab_incr(int t);

// Reinsurance GAAP Surrender Income 
double seg_comp_reins_gaap_surr_inc(int t);

// Reinsurance GAAP Terminal Dividends 
double seg_comp_reins_gaap_terminal_div(int t);

// Reinsurance GAAP Unearned Revenue Liability 
double seg_comp_reins_gaap_unearn_rev_liab(int t);

// Reinsurance GAAP Unearned Revenue Released 
double seg_comp_reins_gaap_unearn_rev_released(int t);

// Reinsurance GAAP Unrealized Cap Gain Increase 
double seg_comp_reins_gaap_unrealzd_cap_gain_incr(int t);

// Reinsurance IMR Impact on Reserves 
double seg_comp_reins_imr_impact_res(int t);

// Reinsurance IMR Impact on Reserves Before Sales 
double seg_comp_reins_imr_impact_res_bef_sale(int t);

// Reinsurance Investment Fee Refund 
double seg_comp_reins_inv_fee_ref(int t);

// Reinsurance Investment Income Reserve 
double seg_comp_reins_inv_inc_res(int t);

// Reinsurance Maturity Benefits 
double seg_comp_reins_maturity_benefits(int t);

// Modified Coinsurance Reserve Adjustment 
double seg_comp_reins_modco_res_adj(int t);

// Reinsurance Premium 
double seg_comp_reins_prem(int t);

// Reinsurance Premium Tax 
double seg_comp_reins_prem_tax(int t);

// Reinsurance Premium Waiver Benefits 
double seg_comp_reins_prem_waiver_benefits(int t);

// Reinsurance Realized Capital Gains on Reserve 
double seg_comp_reins_realzd_cap_gain_res(int t);

// Reinsurance Realized Capital Gains on Reserve Before Sales 
double seg_comp_reins_realzd_cap_gain_res_bef_sale(int t);

// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date 
double seg_comp_reins_realzd_cap_gain_res_ytd(int t);

// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date Before Sales 
double seg_comp_reins_realzd_cap_gain_res_ytd_bef_sale(int t);

// Reinsurance Refund 
double seg_comp_reins_ref(int t);

// Reinsurance Statutory Claim Reserve 
double seg_comp_reins_stat_claim_res(int t);

// Reinsurance Statutory Claim Reserve Increase 
double seg_comp_reins_stat_claim_res_incr(int t);

// Reinsurance Statutory Cost 
double seg_comp_reins_stat_cost(int t);

// Reinsurance Statutory Cost Before Sales 
double seg_comp_reins_stat_cost_bef_sale(int t);

// Reinsurance Statutory Loading 
double seg_comp_reins_stat_loading(int t);

// Reinsurance Statutory Loading Increase 
double seg_comp_reins_stat_loading_incr(int t);

// Reinsurance Statutory Premium Waiver Reserve 
double seg_comp_reins_stat_prem_waiver_res(int t);

// Reinsurance Statutory Premium Waiver Reserve Increase 
double seg_comp_reins_stat_prem_waiver_res_incr(int t);

// Reinsurance Statutory Reserve 
double seg_comp_reins_stat_res(int t);

// Reinsurance Statutory Reserve Increase 
double seg_comp_reins_stat_res_incr(int t);

// Reinsurance Statutory Policy Reserve 
double seg_comp_reins_stat_res_mp(int t);

// Reinsurance Statutory Net Premium Reserve 
double seg_comp_reins_stat_res_npr(int t);

// Reinsurance Statutory Reserve Unhedged 
double seg_comp_reins_stat_res_unhedged(int t);

// Reinsurance Statutory Unearned Premium Reserve 
double seg_comp_reins_stat_unearn_prem_res(int t);

// Reinsurance Statutory Unearned Premium Reserve Increase 
double seg_comp_reins_stat_unearn_prem_res_incr(int t);

// Reinsurance Surrender Benefits 
double seg_comp_reins_surr_benefits(int t);

// ReinsuranceTax Claim Reserve 
double seg_comp_reins_tax_claim_res(int t);

// Reinsurance Tax Claim Reserve Increase 
double seg_comp_reins_tax_claim_res_incr(int t);

// Reinsurance Tax Deferred Net Premium 
double seg_comp_reins_tax_deferred_net_prem(int t);

// Reinsurance Tax Dividend Liability 
double seg_comp_reins_tax_div_liab(int t);

// Reinsurance Tax Dividend Liability Increase 
double seg_comp_reins_tax_div_liab_incr(int t);

// Reinsurance Tax Loading 
double seg_comp_reins_tax_loading(int t);

// Reinsurance Tax Loading Increase 
double seg_comp_reins_tax_loading_incr(int t);

// Reinsurance Tax Prem Waiver Reserve 
double seg_comp_reins_tax_prem_waiver_res(int t);

// Reinsurance Tax Premium Waiver Reserve Increase 
double seg_comp_reins_tax_prem_waiver_res_incr(int t);

// Reinsurance Tax Reserve 
double seg_comp_reins_tax_res(int t);

// Reinsurance Tax Reserve Increase 
double seg_comp_reins_tax_res_incr(int t);

// Reinsurance Tax Policy Reserve 
double seg_comp_reins_tax_res_mp(int t);

// Reinsurance Tax Unearned Premium Reserve 
double seg_comp_reins_tax_unearn_prem_res(int t);

// Reinsurance Tax Unearned Premium Reserve Increase 
double seg_comp_reins_tax_unearn_prem_res_incr(int t);

// Reinsurance Terminal Dividends 
double seg_comp_reins_terminal_div(int t);

// Reinsurance Withdrawal Benefits 
double seg_comp_reins_withdrl_benefits(int t);

// Rho Convexity Hedge Investment Amount 
double seg_comp_rho_convex_hedge_inv_amt(int t);

// Rho Convexity Hedge Market Value of Assets 
double seg_comp_rho_convex_hedge_mkt_val(int t);

// Rho Convexity Hedge Market Value of Assets Increase 
double seg_comp_rho_convex_hedge_mkt_val_incr(int t);

// Rho Convexity Hedge Derivative Payment 
double seg_comp_rho_convex_hedge_pmt(int t);

// Rho Convexity Hedge Profit 
double seg_comp_rho_convex_hedge_prof(int t);

// Rho Convexity Hedge Sale Amount 
double seg_comp_rho_convex_hedge_sale_amt(int t);

// Rho Convexity Hedge Transaction Cost 
double seg_comp_rho_convex_hedge_transaction_cost(int t);

// Rho Hedge Investment Amount 
double seg_comp_rho_hedge_inv_amt(int t);

// Rho Hedge Market Value of Assets 
double seg_comp_rho_hedge_mkt_val(int t);

// Rho Hedge Market Value of Assets 
double seg_comp_rho_hedge_mkt_val_incr(int t);

// Rho Hedge Derivative Payment 
double seg_comp_rho_hedge_pmt(int t);

// Rho Hedge Profit 
double seg_comp_rho_hedge_prof(int t);

// Rho Hedge Sale Amount 
double seg_comp_rho_hedge_sale_amt(int t);

// Rho Hedge Transaction Cost 
double seg_comp_rho_hedge_transaction_cost(int t);

// rila trading cost 
double seg_comp_rila_interim_value_dapv_e_aig(int t);

// rila trading cost 
double seg_comp_rila_interim_value_fiapv_e_aig(int t);

// rila trading cost 
double seg_comp_rila_interim_value_tc_e_aig(int t);

// Sale Interest Maintenance Reserve Asset Valuation Reserve Flag 
double seg_comp_sale_imr_avr_flag(int t);

// Sale Income 
double seg_comp_sale_inc(int t);

// Sale Possible Interest Maintenance Reserve Asset Valuation Reserve Flag 
double seg_comp_sale_possible_imr_avr_flag(int t);

// Scheduled Principal Payment 
double seg_comp_sched_prin_pmt(int t);

// Startup 
virtual double virtual_startup(int t);

// Statutory Claim Expense Reserve 
double seg_comp_stat_claim_exp_res(int t);

// Statutory Claim Expense Reserve Increase 
double seg_comp_stat_claim_exp_res_incr(int t);

// Statutory Claim Incurred 
double seg_comp_stat_claim_incurred(int t);

// Statutory Claim Reserve 
double seg_comp_stat_claim_res(int t);

// Statutory Claim Reserve Increase 
double seg_comp_stat_claim_res_incr(int t);

// Statutory Loading 
double seg_comp_stat_loading(int t);

// Statutory Loading Increase 
double seg_comp_stat_loading_incr(int t);

// Statutory Premium Waiver Expense Reserve 
double seg_comp_stat_prem_waiver_exp_res(int t);

// Statutory Premium Waiver Expense Reserve Increase 
double seg_comp_stat_prem_waiver_exp_res_incr(int t);

// Statutory Premium Waiver Reserve 
double seg_comp_stat_prem_waiver_res(int t);

// Statutory Premium Waiver Reserve Increase 
double seg_comp_stat_prem_waiver_res_incr(int t);

// Statutory Reserve 
double seg_comp_stat_res(int t);

// Statutory Ag38 8d Reserve 
double seg_comp_stat_res_ag38_8d(int t);

// Base Stat Res 
double seg_comp_stat_res_carvm_base_aig(int t);

// WB Stat Res 
double seg_comp_stat_res_carvm_wb_aig(int t);

// Stat Res Cte Adj 
double seg_comp_stat_res_cte_adj(int t);

// Stat Res Cte Adj Unfloored 
double seg_comp_stat_res_cte_adj_unfloored(int t);

// stat_res_cte_adj_unfloored_unhedged 
double seg_comp_stat_res_cte_adj_unfloored_unhedged(int t);

// Stat Res Cte Be 
double seg_comp_stat_res_cte_be(int t);

// Stat Res Cte Buffer 
double seg_comp_stat_res_cte_buffer(int t);

// Stat Res Cte Buffer Unhedged 
double seg_comp_stat_res_cte_buffer_unhedged(int t);

// Statutory Deterministic Reserve 
double seg_comp_stat_res_det_res(int t);

// Statutory Deterministic Reserve Unhedged 
double seg_comp_stat_res_det_res_unhedged(int t);

// Statutory Excess Reserve 
double seg_comp_stat_res_excess(int t);

// Statutory Excess Reserve Unhedged 
double seg_comp_stat_res_excess_unhedged(int t);

// Statutory Reserve Increase 
double seg_comp_stat_res_incr(int t);

// Statutory Policy Reserve 
double seg_comp_stat_res_mp(int t);

// Statutory Policy Reserve Unhedged 
double seg_comp_stat_res_mp_unhedged(int t);

// Net Statutory Reserve 
double seg_comp_stat_res_net(int t);

// Net Statutory Ag38 8d Reserve 
double seg_comp_stat_res_net_ag38_8d(int t);

// Stat Res Net Cte Adj 
double seg_comp_stat_res_net_cte_adj(int t);

// Stat Res Net Cte Adj Unfloored 
double seg_comp_stat_res_net_cte_adj_unfloored(int t);

// Stat Res Net Cte Adj Unfloored Unhedged 
double seg_comp_stat_res_net_cte_adj_unfloored_unhedged(int t);

// Stat Res Net Cte Be 
double seg_comp_stat_res_net_cte_be(int t);

// Stat Res Net Cte Buffer 
double seg_comp_stat_res_net_cte_buffer(int t);

// Stat Res Net Cte Buffer Unhedged 
double seg_comp_stat_res_net_cte_buffer_unhedged(int t);

// Net Statutory Deterministic Reserve 
double seg_comp_stat_res_net_det_res(int t);

// Net Statutory Deterministic Reserve Unhedged 
double seg_comp_stat_res_net_det_res_unhedged(int t);

// Statutory Net Reserve Excess 
double seg_comp_stat_res_net_excess(int t);

// Statutory Net Reserve Excess Unhedged 
double seg_comp_stat_res_net_excess_unhedged(int t);

// Net Statutory Policy Reserve 
double seg_comp_stat_res_net_mp(int t);

// Net Statutory Policy Reserve Unhedged 
double seg_comp_stat_res_net_mp_unhedged(int t);

// Net Statutory Net Premium Reserve 
double seg_comp_stat_res_net_npr(int t);

// Net Statutory Net Premium Reserve Unhedged 
double seg_comp_stat_res_net_npr_unhedged(int t);

// Net Statutory Reserve Separate Account 
double seg_comp_stat_res_net_sa(int t);

// Net Statutory Reserve Stochastic Reserve 
double seg_comp_stat_res_net_stoch_res(int t);

// Net Statutory Reserve Stochastic Reserve Unhedged 
double seg_comp_stat_res_net_stoch_res_unhedged(int t);

// Net Statutory Reserve Unhedged 
double seg_comp_stat_res_net_unhedged(int t);

// Statutory Net Premium Reserve 
double seg_comp_stat_res_npr(int t);

// Statutory Net Premium Reserve Unhedged 
double seg_comp_stat_res_npr_unhedged(int t);

// Statutory Reserve Separate Account 
double seg_comp_stat_res_sa(int t);

// Statutory Reserve Separate Account Expense Allowance 
double seg_comp_stat_res_sa_exp_allow(int t);

// Statutory Reserve Stochastic Reserve 
double seg_comp_stat_res_stoch_res(int t);

// Statutory Reserve Stochastic Reserve Unhedged 
double seg_comp_stat_res_stoch_res_unhedged(int t);

// Statutory Reserve Unhedged 
double seg_comp_stat_res_unhedged(int t);

// XOL Statutory Reserve 
double seg_comp_stat_res_xol_carvm_aig(int t);

// XOL excess reserve 
double seg_comp_stat_res_xol_excess_res_aig(int t);

// XOL new business economic reserve 
double seg_comp_stat_res_xol_nb_eco_res_aig(int t);

// PV of NB Ending XOL Amount 
double seg_comp_stat_res_xol_pv_nb_ending_amount_aig(int t);

// Statutory Unearned Premium Reserve 
double seg_comp_stat_unearn_prem_res(int t);

// Statutory Unearned Premium Reserve Increase 
double seg_comp_stat_unearn_prem_res_incr(int t);

// Statutory Unearned Premium Reserve Net 
double seg_comp_stat_unearn_prem_res_net(int t);

// Statutory Unearned Premium Reserve NPR 
double seg_comp_stat_unearn_prem_res_npr(int t);

// Statutory Unearned Premium Reserve NPR Net 
double seg_comp_stat_unearn_prem_res_npr_net(int t);

// Surrender Benefits 
double seg_comp_surr_benefits(int t);

// Tax 
double seg_comp_tax(int t);

// Tax Before Sales 
double seg_comp_tax_bef_sale(int t);

// Tax on Book Profit 
double seg_comp_tax_bk_prof(int t);

// Tax on Book Profit Before Sales 
double seg_comp_tax_bk_prof_bef_sale(int t);

// Tax on Book Profit Calendar Year to Date 
double seg_comp_tax_bk_prof_ytd(int t);

// Tax on Book Profit Calendar Year to Date Before Sales 
double seg_comp_tax_bk_prof_ytd_bef_sale(int t);

// Tax Capitalized Premium 
double seg_comp_tax_capzd_prem(int t);

// Tax Capitalized Premium Amortization 
double seg_comp_tax_capzd_prem_amortzn(int t);

// Tax Capitalized Premium Unamortized 
double seg_comp_tax_capzd_prem_unamortzd(int t);

// Tax Claim Expense Reserve 
double seg_comp_tax_claim_exp_res(int t);

// Tax Claim Reserve 
double seg_comp_tax_claim_res(int t);

// Tax Claim Reserve Increase 
double seg_comp_tax_claim_res_incr(int t);

// Tax Deferred Net Premium 
double seg_comp_tax_deferred_net_prem(int t);

// Tax Dividend Liability 
double seg_comp_tax_div_liab(int t);

// Tax Dividend Liability Increase 
double seg_comp_tax_div_liab_incr(int t);

// Tax on Accumulated Earnings 
double seg_comp_tax_earnings_accum(int t);

// Tax on Accumulated Earnings Calendar Year to Date 
double seg_comp_tax_earnings_accum_ytd(int t);

// Tax Exempt Income 
double seg_comp_tax_exempt_inc(int t);

// Tax Exempt Income Book Profit 
double seg_comp_tax_exempt_inc_bk_prof(int t);

// Tax Exempt Income Free Surplus 
double seg_comp_tax_exempt_inc_free_surp(int t);

// Tax Exempt Income Target Capital 
double seg_comp_tax_exempt_inc_tgt_cap(int t);

// Tax on Free Surplus Income 
double seg_comp_tax_free_surp(int t);

// Tax on Free Surplus Income Before Sales 
double seg_comp_tax_free_surp_bef_sale(int t);

// Tax on Free Surplus Income Calendar Year to Date 
double seg_comp_tax_free_surp_ytd(int t);

// Tax on Free Surplus Income Calendar Year to Date Before Sales 
double seg_comp_tax_free_surp_ytd_bef_sale(int t);

// Tax Loading 
double seg_comp_tax_loading(int t);

// Tax Loading Increase 
double seg_comp_tax_loading_incr(int t);

// Tax Premium Waiver Expense Reserve 
double seg_comp_tax_prem_waiver_exp_res(int t);

// Tax Premium Waiver Reserve 
double seg_comp_tax_prem_waiver_res(int t);

// Tax Premium Waiver Reserve Increase 
double seg_comp_tax_prem_waiver_res_incr(int t);

// Tax Reserve 
double seg_comp_tax_res(int t);

// Tax Reserve Increase 
double seg_comp_tax_res_incr(int t);

// Tax Policy Reserve 
double seg_comp_tax_res_mp(int t);

// Tax on Target Capital Income 
double seg_comp_tax_tgt_cap(int t);

// Tax on Target Capital Income Before Sale 
double seg_comp_tax_tgt_cap_bef_sale(int t);

// Tax on Target Capital Income Calendar Year to Date 
double seg_comp_tax_tgt_cap_ytd(int t);

// Tax on Target Capital Income Calendar Year to Date Before Sales 
double seg_comp_tax_tgt_cap_ytd_bef_sale(int t);

// Tax Transfers to Separate Account Net 
double seg_comp_tax_transfer_to_sa_net(int t);

// Tax Unearned Premium Reserve 
double seg_comp_tax_unearn_prem_res(int t);

// Tax Unearned Premium Reserve Increase 
double seg_comp_tax_unearn_prem_res_incr(int t);

// Taxable Income Addition 
double seg_comp_taxable_inc_addn(int t);

// Taxable Income Book Profit 
double seg_comp_taxable_inc_bk_prof(int t);

// Taxable Income Book Profit Before Sales 
double seg_comp_taxable_inc_bk_prof_bef_sale(int t);

// Taxable Income Book Profit Calendar Year to Date 
double seg_comp_taxable_inc_bk_prof_ytd(int t);

// Taxable Income Book Profit Calendar Year to Date Before Sales 
double seg_comp_taxable_inc_bk_prof_ytd_bef_sale(int t);

// Taxable Income Carry Forward Addition Calendar Year to Date 
double seg_comp_taxable_inc_carryfwd_addn_ytd(int t);

// Taxable Income Carry Forward Applied Calendar Year to Date 
double seg_comp_taxable_inc_carryfwd_applied_ytd(int t);

// Taxable Income Carry Forward Available 
double seg_comp_taxable_inc_carryfwd_avail(int t);

// Taxable Income Accumulated Earnings 
double seg_comp_taxable_inc_earnings_accum(int t);

// Taxable Income Acumulated Earnings Calendar Year to Date 
double seg_comp_taxable_inc_earnings_accum_ytd(int t);

// Taxable Income Free Surplus 
double seg_comp_taxable_inc_free_surp(int t);

// Taxable Income Free Surplus Before Sales 
double seg_comp_taxable_inc_free_surp_bef_sale(int t);

// Taxable Income Free Surplus Calendar Year to Date 
double seg_comp_taxable_inc_free_surp_ytd(int t);

// Taxable Income Free Surplus Calendar Year to Date Before Sales 
double seg_comp_taxable_inc_free_surp_ytd_bef_sale(int t);

// Taxable Income Target Capital 
double seg_comp_taxable_inc_tgt_cap(int t);

// Taxable Income Target Capital Before Sale 
double seg_comp_taxable_inc_tgt_cap_bef_sale(int t);

// Taxable Income Target Capital Calendar Year to Date 
double seg_comp_taxable_inc_tgt_cap_ytd(int t);

// Taxable Income Target Captial Calendar Year to Date Before Sales 
double seg_comp_taxable_inc_tgt_cap_ytd_bef_sale(int t);

// Terminal Dividends 
double seg_comp_terminal_div(int t);

// Target Capital 
double seg_comp_tgt_cap(int t);

// Target Capital Before Sales 
double seg_comp_tgt_cap_bef_sale(int t);

// Target Capital Effect 
double seg_comp_tgt_cap_effect(int t);

// Target Capital Effect Before Sales 
double seg_comp_tgt_cap_effect_bef_sale(int t);

// Target Capital Increase 
double seg_comp_tgt_cap_incr(int t);

// Target Capital Increase Before Sales 
double seg_comp_tgt_cap_incr_bef_sale(int t);

// Transfer Cash Flow Separate Account Beginning of Month 
double seg_comp_transfer_cash_flow_sa_bom(int t);

// Transfer Cash Flow Separate Account End of Month 
double seg_comp_transfer_cash_flow_sa_eom(int t);

// Transfers to Separate Account Net 
double seg_comp_transfer_to_sa_net(int t);

// Undistributed Earnings 
double seg_comp_undistrib_earnings(int t);

// Unrealized Capital Gain Increase 
double seg_comp_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Increase Before Sales 
double seg_comp_unrealzd_cap_gain_incr_bef_sale(int t);

// Unrealized Capital Gain Released on Sale 
double seg_comp_unrealzd_cap_gain_released_on_sale(int t);

// Valuation Target - Ag38 8D Reserve 
double seg_comp_valn_tgt_ag38_8d(int t);

// Valuation Target - GAAP SFAS 120 
double seg_comp_valn_tgt_gaap_sfas120(int t);

// Valuation Target - GAAP SFAS 91 
double seg_comp_valn_tgt_gaap_sfas91(int t);

// Valuation Target - GAAP SFAS 97 Retrospective Deposit 
double seg_comp_valn_tgt_gaap_sfas97rd(int t);

// Valuation Target - GAAP SOP 03-1 
double seg_comp_valn_tgt_gaap_sop031(int t);

// Valuation Target - Final Hedging 
double seg_comp_valn_tgt_hedge_final(int t);

// Valuation Target - Hedging Shock 
double seg_comp_valn_tgt_hedge_shock(int t);

// Valuation Target - PBA Policy Reserve 
double seg_comp_valn_tgt_pba_pol_res(int t);

// Valuation Target - PBA RBC Standard Scenario Step 2 
double seg_comp_valn_tgt_pba_rbc_std_scen_step2(int t);

// Valuation Target - PBA Scenario Amount 
double seg_comp_valn_tgt_pba_scen_amt(int t);

// Vega Hedge Investment Amount 
double seg_comp_vega_hedge_inv_amt(int t);

// Vega Hedge Market Value of Assets 
double seg_comp_vega_hedge_mkt_val(int t);

// Vega Hedge Market Value of Assets Increase 
double seg_comp_vega_hedge_mkt_val_incr(int t);

// Vega Hedge Derivative Payment 
double seg_comp_vega_hedge_pmt(int t);

// Vega Hedge Profit 
double seg_comp_vega_hedge_prof(int t);

// Vega Hedge Sale Amount 
double seg_comp_vega_hedge_sale_amt(int t);

// Vega Hedge Transaction Cost 
double seg_comp_vega_hedge_transaction_cost(int t);

// Vm21 Pv Claims Deterministic Crbg 
double seg_comp_vm21_pv_claims_deterministic_crbg(int t);

// Withdrawal Benefits 
double seg_comp_withdrl_benefits(int t);

// XOL Amount 
double seg_comp_xol_amount_aig(int t);

// XOL Prem 
double seg_comp_xol_prem_aig(int t);

// AVR Components 
double seg_comp_avr_components(int t, int c);

// AVR Components Before Sales 
double seg_comp_avr_components_bef_sale(int t, int c);

// IMR After Tax Realized Capital Gains Bonds 
double seg_comp_imr_aft_tax_realzd_cap_gains_bonds(int t, int c);

// IMR After Tax Realized Capital Gains Bonds Before Sales 
double seg_comp_imr_aft_tax_realzd_cap_gains_bonds_bef_sale(int t, int c);

// IMR After Tax Realized Capital Gains Mortgages 
double seg_comp_imr_aft_tax_realzd_cap_gains_mortgages(int t, int c);

// IMR After Tax Realized Capital Gains Mortgages Before Sales 
double seg_comp_imr_aft_tax_realzd_cap_gains_mortgages_bef_sale(int t, int c);

// IMR After Tax Realized Capital Gains Other 
double seg_comp_imr_aft_tax_realzd_cap_gains_other(int t, int c);

// IMR After Tax Realized Capital Gains Other Before Sales 
double seg_comp_imr_aft_tax_realzd_cap_gains_other_bef_sale(int t, int c);

// IMR After Tax Realized Capital Gains Residential Mortgages 
double seg_comp_imr_aft_tax_realzd_cap_gains_rml(int t, int c);

// IMR After Tax Realized Capital Gains Residential Mortgages Before Sales 
double seg_comp_imr_aft_tax_realzd_cap_gains_rml_bef_sale(int t, int c);

// IMR Amortization Amount Table 
double seg_comp_imr_amortzn_amt_tbl(int t, int c);

// IMR Amortization Amount Table Before Sales 
double seg_comp_imr_amortzn_amt_tbl_bef_sale(int t, int c);

// IMR First Yr Amortization For Month 
double seg_comp_imr_fy_amortzn_for_mth(int t, int c);

// IMR First Yr Amortization For Month Before Sales 
double seg_comp_imr_fy_amortzn_for_mth_bef_sale(int t, int c);

// Tax Capitalized Premium Amortization Schedule 
double seg_comp_tax_capzd_prem_amortzn_sched(int t, int c);

// Asset Yield for AG38 8D calculation 
double  seg_comp_asset_yld_ag38_8d();

// Business Segment Flag 
int  seg_comp_business_seg_flag();

// Corporate Segment Flag 
int  seg_comp_corp_seg_flag();

// Existing Asset Percent to Use 
double  seg_comp_existing_asset_pct_to_use();

// Final Period 
int  seg_comp_final_period();

// GAAP Amortization Period 
int  seg_comp_gaap_amortzn_period();

// IMR Maximum Amortization Years 
int  seg_comp_imr_max_amortzn_yrs();

// IMR Maximum Years to Maturity 
int  seg_comp_imr_max_yrs_to_maturity();

// Inflation start mth 
int  seg_comp_infl_start_mth();

// Inflation start period 
int  seg_comp_infl_start_period();

// Inflation start year 
int  seg_comp_infl_start_yr();

// Initial Cash for AG38 8D Calculation 
double  seg_comp_init_cash_ag38_8d();

// Letter of Credit AG 48 Flag 
int  seg_comp_loc_ag48_flag();

// Letter of Credit Flag 
int  seg_comp_loc_flag();

// Letter of Credit Gross Premium Reserve Flag 
int  seg_comp_loc_gpr_flag();

// PBA Tax Flag 
int  seg_comp_pba_tax_flag();

// Projection Date Adjusted 
xstring  seg_comp_proj_date_adj();

// Projection Start Date 
int  seg_comp_proj_start_date();

// Projection Start Mth 
int  seg_comp_proj_start_mth();

// Projection Start Yr 
int  seg_comp_proj_start_yr();

// Reinsurance Flag 
int  seg_comp_reins_flag();

// Reinsurance Percent Ag38 8d 
double  seg_comp_reins_pct_ag38_8d();

// Segment Number 
int  seg_comp_seg_num();

// Start Period 
int  seg_comp_start_period();

// State of World Financial File Path 
xstring  seg_comp_state_of_world_financial_file_path();

// Tax Capitalized Premium Amortization Years 
int  seg_comp_tax_capzd_prem_amortzn_yrs();

// Vm21 Reinv Rate Seg Flag 
int  seg_comp_vm21_reinv_rate_seg_flag();


};
#endif
