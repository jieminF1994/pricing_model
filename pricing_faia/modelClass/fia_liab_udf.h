
#ifndef __FIA_LIAB_UDF_H_
#define __FIA_LIAB_UDF_H_

#include "ModelClass\fia_liab.h"

class FIA_LIAB_UDF : public FIA_LIAB {

	friend class FIA_LIAB;

//constructor 
FIA_LIAB_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: FIA_LIAB(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
FIA_LIAB_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : FIA_LIAB(columnCount, mocd, persObj) {}


// Acquisition Expenses 
double fia_liab_acq_exp(int t);
// Administration Fee 
double fia_liab_admin_fee(int t);
// Age Last Birthday at Previous Policy Anniversary 
double fia_liab_age_last(int t);
// Annuity Benefits 
double fia_liab_ann_benefits_eom(int t);
// Annuity Claims - GMWB 
double fia_liab_ann_claims_gmwb(int t);
// Gmwb Claim Cash Flow Crbg 
double fia_liab_ann_gmwb_cash_flow_crbg(int t);
// year when gmwb claim begins 
double fia_liab_ann_gmwb_claim_yr_crbg(int t);
// pip pct for gmwb claim 
double fia_liab_ann_gmwb_pip_pct_crbg(int t);
// ann_gmwb_wdl_grossed_up_crbg 
double fia_liab_ann_gmwb_wdl_grossed_up_crbg(int t);
// Annuitization Rate 
double fia_liab_annuitzn_rate(int t);
// Annuitization Rate Monthly 
double fia_liab_annuitzn_rate_mthly(int t);
// Asset Yield 
double fia_liab_asset_yld(int t);
// Asset Yld Fa Rate Setting Crbg 
double fia_liab_asset_yld_fa_rate_setting_crbg(int t);
// Asset Yield for Investment Assets 
double fia_liab_asset_yld_inv(int t);
// Asset Yield for Investment Assets 
double fia_liab_asset_yld_inv_adj_crbg(int t);
// Asset Yield Less Default 
double fia_liab_asset_yld_less_dflt(int t);
// Asset Yield Less Default for Investment Assets 
double fia_liab_asset_yld_less_dflt_inv(int t);
// Attained Age 
double fia_liab_attained_age(int t);
// Avg Coupon Rt Crbg 
double fia_liab_avg_coupon_rt_crbg(int t);
// Before Tax Yield 
double fia_liab_bef_tax_yld(int t);
// Book Profit After Tax 
double fia_liab_bk_prof_aft_tax(int t);
// Book Profit After Tax for Present Values 
double fia_liab_bk_prof_aft_tax_for_pv(int t);
// Book Profit After Tax for IRR 
double fia_liab_bk_prof_aft_tax_irr(int t);
// Book Profit After Tax Calendar Quarter to Date 
double fia_liab_bk_prof_aft_tax_qtd(int t);
// Book Profit After Tax Calendar Year to Date 
double fia_liab_bk_prof_aft_tax_ytd(int t);
// Book Profit Before Tax 
double fia_liab_bk_prof_bef_tax(int t);
// Book Profit Before Tax for Present Values 
double fia_liab_bk_prof_bef_tax_for_pv(int t);
// Book Profit Before Tax Calendar Quarter to Date 
double fia_liab_bk_prof_bef_tax_qtd(int t);
// Book Profit Before Tax Calendar Year to Date 
double fia_liab_bk_prof_bef_tax_ytd(int t);
// Book Profit By Source Before Tax 
double fia_liab_bk_prof_by_source_bef_tax(int t);
// Calendar Month 
double fia_liab_cal_mth(int t);
// Calendar Year 
double fia_liab_cal_yr(int t);
// Calendar Year Relative 
double fia_liab_cal_yr_relative(int t);
// Cash Value 
double fia_liab_cash_val(int t);
// Cash Value End of Month Before Claims 
double fia_liab_cash_val_bef(int t);
// Cash Value Without MVA 
double fia_liab_cash_val_wo_mva(int t);
// Commissions Beginning of Month 
double fia_liab_comm_bom(int t);
// Commission Chargeback 
double fia_liab_comm_chargeback(int t);
// Commission End of Month 
double fia_liab_comm_eom(int t);
// Commission Fund Based 
double fia_liab_comm_fund_based(int t);
// Commission Premium Based 
double fia_liab_comm_prem_based(int t);
// Commission Subject to Chargeback 
double fia_liab_comm_subject_to_chargeback(int t);
// Commission Subject to Chargeback End of Month 
double fia_liab_comm_subject_to_chargeback_e(int t);
// Contract Value at End of Period 
double fia_liab_contract_val(int t);
// Contract Value at End of Period Before Claims 
double fia_liab_contract_val_bef(int t);
// Covered Person Status Crbg 
double fia_liab_covered_person_status_crbg(int t);
// Credited Interest 
double fia_liab_credited_int(int t);
// Competitor Credited Interest Numerator 
double fia_liab_credited_int_comp_numer(int t);
// Crediting Rate 
double fia_liab_crediting_rate(int t);
// Crediting Rate Cumul Crbg 
double fia_liab_crediting_rate_cumul_crbg(int t);
// Fixed Crediting Rate For Fund Value 
double fia_liab_crediting_rate_fix(int t);
// Crediting Rate Partial Crbg 
double fia_liab_crediting_rate_partial_crbg(int t);
// Date 
double fia_liab_date(int t);
// Direct Cash Flow Beginning of Month 
double fia_liab_direct_cash_flow_bom(int t);
// Direct Cash Flow End of Month 
double fia_liab_direct_cash_flow_eom(int t);
// Direct Cash Flow Interest 
double fia_liab_direct_cash_flow_int(int t);
// Discount Rate 1 
double fia_liab_disc_rate_1(int t);
// Discount Rate 2 
double fia_liab_disc_rate_2(int t);
// Discount Rate 3 
double fia_liab_disc_rate_3(int t);
// Discount Rate Portfolio Yield 
double fia_liab_disc_rate_port_yld(int t);
// Discount Rate Portfolio Ylield Definition Value 
double fia_liab_disc_rate_port_yld_defn_val(int t);
// Discount Rate risk free 
double fia_liab_disc_rate_rf_crbg(int t);
// Discount Rate risk free IC UEL sprd 
double fia_liab_disc_rate_rf_sprd_ic_uel_crbg(int t);
// Discount Rate risk free no UEL sprd 
double fia_liab_disc_rate_rf_sprd_no_uel_crbg(int t);
// Discount Rate risk free UEL sprd 
double fia_liab_disc_rate_rf_sprd_uel_crbg(int t);
// Distributable Earnings 
double fia_liab_distrib_earnings(int t);
// Distributable Earnings for IRR 
double fia_liab_distrib_earnings_irr(int t);
// Death Benefit In Force 
double fia_liab_dth_ben_inf(int t);
// Death Benefit In Force Before Decrements 
double fia_liab_dth_ben_inf_bef(int t);
// Death Benefits 
double fia_liab_dth_benefits(int t);
// Death Claim Rate Monthly 
double fia_liab_dth_claim_rate_mthly(int t);
// Dth Rate Female Crbg 
double fia_liab_dth_rate_female_crbg(int t);
// Dth Rate Male Crbg 
double fia_liab_dth_rate_male_crbg(int t);
// Dth Rate Blended Crbg 
double fia_liab_dth_rate_mthly_blended_crbg(int t);
// Dth Claim Rate Mthly Crbg 
double fia_liab_dth_rate_mthly_crbg(int t);
// Dth Rate Female mthly 
double fia_liab_dth_rate_mthly_female_crbg(int t);
// Dth Rate Mthly Last Survivor Crbg 
double fia_liab_dth_rate_mthly_last_survivor_crbg(int t);
// Dth Rate Male mthly 
double fia_liab_dth_rate_mthly_male_crbg(int t);
// Accumulated Earnings 
double fia_liab_earnings_accum(int t);
// Enh Inc Confined Mth Female Crbg 
double fia_liab_enh_inc_confined_mth_female_crbg(int t);
// Enh Inc Confined Mth Male Crbg 
double fia_liab_enh_inc_confined_mth_male_crbg(int t);
// Enh Inc Confined Status AGGr Crbg 
double fia_liab_enh_inc_confined_status_aggr_crbg(int t);
// Enh Inc Confined Status Female Crbg 
double fia_liab_enh_inc_confined_status_female_crbg(int t);
// Enh Inc Confined Status Male Crbg 
double fia_liab_enh_inc_confined_status_male_crbg(int t);
// Enh Inc eligibility flag 
double fia_liab_enh_inc_eligibility_flag_crbg(int t);
// Enh Inc Exercise Cumul Yrs Crbg 
double fia_liab_enh_inc_exercise_cumul_yrs_crbg(int t);
// Enh Inc exercise Flag 
double fia_liab_enh_inc_exercise_flag_crbg(int t);
// Enh Inc Indirect Exercise Crbg 
double fia_liab_enh_inc_indirect_exercise_crbg(int t);
// Enh Inc Rand exercise 
double fia_liab_enh_inc_rand_exercise_crbg(int t);
// Enh Inc Rand Female 
double fia_liab_enh_inc_rand_female_crbg(int t);
// Enh Inc Rand Male 
double fia_liab_enh_inc_rand_male_crbg(int t);
// EPRS SFC ben 
double fia_liab_eprs_sfc_ben_crbg(int t);
// EPRS SFC gross ben 
double fia_liab_eprs_sfc_ben_gross_crbg(int t);
// EPRS Charge partial 
double fia_liab_eprs_strat_fee_partial_bef_crbg(int t);
// EPRS Charge partial 
double fia_liab_eprs_strat_fee_partial_e_crbg(int t);
// Finalize 
double fia_liab_finalize(int t);
// Fund Released on Annuitization 
double fia_liab_fund_released_ann(int t);
// Fund Released on Death 
double fia_liab_fund_released_dth(int t);
// Fund Released on Maturity 
double fia_liab_fund_released_maturity(int t);
// Fund Released on Surrender 
double fia_liab_fund_released_surr(int t);
// Fund Released on Withdrawal 
double fia_liab_fund_released_withdrl(int t);
// Fund Value After Outflow - BOM 
double fia_liab_fund_val_b(int t);
// Fund Value Before Outflow BOM 
double fia_liab_fund_val_b_bef(int t);
// fund_val_boy_b_crbg 
double fia_liab_fund_val_boy_b_crbg(int t);
// Fund Val Boy E Crbg 
double fia_liab_fund_val_boy_e_crbg(int t);
// Fund Value Decrement Amount 
double fia_liab_fund_val_decrem(int t);
// Fund Value Before Outflow EOM 
double fia_liab_fund_val_e_bef(int t);
// Fund Value End of Month 
double fia_liab_fund_val_fixed(int t);
// GAAP Acquisition Expenses 
double fia_liab_gaap_acq_exp(int t);
// GAAP Benefit Reserve 
double fia_liab_gaap_ben_res(int t);
// GAAP Capitalized Acquisition Expenses 
double fia_liab_gaap_capzd_acq_exp(int t);
// GAAP Capitalized Commissions BOM 
double fia_liab_gaap_capzd_comm_bom(int t);
// GAAP Capitalized Commissions EOM 
double fia_liab_gaap_capzd_comm_eom(int t);
// GAAP Capitalized Premium Bonus 
double fia_liab_gaap_capzd_prem_bonus(int t);
// GAAP Cash Flow Interest 
double fia_liab_gaap_cash_flow_int(int t);
// GAAP Charges Income 
double fia_liab_gaap_chg_inc(int t);
// GAAP Commissions Excess BOM 
double fia_liab_gaap_comm_excess_bom(int t);
// GAAP Commissions Excess EOM 
double fia_liab_gaap_comm_excess_eom(int t);
// GAAP Commissions Trail BOM 
double fia_liab_gaap_comm_trail_bom(int t);
// GAAP Commissions Trail EOM 
double fia_liab_gaap_comm_trail_eom(int t);
// GAAP Credited Interest 
double fia_liab_gaap_credited_int(int t);
// GAAP DAC 
double fia_liab_gaap_dac(int t);
// GAAP DAC Increase 
double fia_liab_gaap_dac_incr(int t);
// GAAP Deferred Tax Liability 
double fia_liab_gaap_deferred_tax_liab(int t);
// GAAP Deferred Tax Liability Increase 
double fia_liab_gaap_deferred_tax_liab_incr(int t);
// GAAP Death Claim Cost 
double fia_liab_gaap_dth_claim_cost(int t);
// GAAP Income After Tax 
double fia_liab_gaap_inc_aft_tax(int t);
// GAAP Income After Tax Calendar Quarter to Date 
double fia_liab_gaap_inc_aft_tax_qtd(int t);
// GAAP Income After Tax Calendar Year to Date 
double fia_liab_gaap_inc_aft_tax_ytd(int t);
// GAAP Income Before Tax 
double fia_liab_gaap_inc_bef_tax(int t);
// GAAP Income Before Tax Calendar Quarter to Date 
double fia_liab_gaap_inc_bef_tax_qtd(int t);
// GAAP Income Before Tax Calendar Year to Date 
double fia_liab_gaap_inc_bef_tax_ytd(int t);
// GAAP Invested Assets 
double fia_liab_gaap_inv_asset(int t);
// GAAP Investment Income on Capital 
double fia_liab_gaap_inv_inc_cap(int t);
// GAAP Investment Income on Reserves 
double fia_liab_gaap_inv_inc_res(int t);
// GAAP Liability Net of DAC 
double fia_liab_gaap_liab_net(int t);
// GAAP Loads Deducted 
double fia_liab_gaap_loads_deducted(int t);
// GAAP Maintenance Expenses BOM 
double fia_liab_gaap_maint_exp_bom(int t);
// GAAP Maintenance Expenses EOM 
double fia_liab_gaap_maint_exp_eom(int t);
// GAAP Market Risk Benefits Liability 
double fia_liab_gaap_mrb_liab(int t);
// GAAP Market Risk Benefits Liability Increase 
double fia_liab_gaap_mrb_liab_incr(int t);
// GAAP Premium Bonus 
double fia_liab_gaap_prem_bonus(int t);
// GAAP Premium Taxes 
double fia_liab_gaap_prem_tax(int t);
// GAAP Profit After Tax for Present Values 
double fia_liab_gaap_prof_aft_tax_for_pv(int t);
// GAAP Profit Before Tax for Present Values 
double fia_liab_gaap_prof_bef_tax_for_pv(int t);
// GAAP Required Capital 
double fia_liab_gaap_req_cap(int t);
// GAAP SFAS 133 Liability 
double fia_liab_gaap_sfas133_liab(int t);
// GAAP SFAS 133 Liability Increase 
double fia_liab_gaap_sfas133_liab_incr(int t);
// GAAP Surplus Increase 
double fia_liab_gaap_surp_incr(int t);
// GAAP Surrender Income 
double fia_liab_gaap_surr_inc(int t);
// Gmab Chg Crbg 
double fia_liab_gmab_chg_crbg(int t);
// Gmab Chg Crbg 
double fia_liab_gmab_chg_partial_e_bef_crbg(int t);
// Gmab Chg Crbg 
double fia_liab_gmab_chg_partial_e_crbg(int t);
// Gmab Global Payoff Crbg 
double fia_liab_gmab_global_payoff_crbg(int t);
// Gmab Payoff Crbg 
double fia_liab_gmab_payoff_crbg(int t);
// GMWB Charge 
double fia_liab_gmwb_chg(int t);
// GMWB Charge partial 
double fia_liab_gmwb_chg_partial_bef_crbg(int t);
// GMWB Charge partial 
double fia_liab_gmwb_chg_partial_e_crbg(int t);
// Gmwb Entitlement Remaining BOM 
double fia_liab_gmwb_entitlement_remaining_b_crbg(int t);
// Gmwb Entitlement Remaining E 
double fia_liab_gmwb_entitlement_remaining_e_crbg(int t);
// Gmwb Exercise Yrs Crbg 
double fia_liab_gmwb_exercise_yrs_crbg(int t);
// GMWB Fund Value Base End of Month 
double fia_liab_gmwb_fund_val_inf(int t);
// GMWB Fund Value Base End of Month Before Claims 
double fia_liab_gmwb_fund_val_inf_bef(int t);
// GMWB Income Base Beg of Month 
double fia_liab_gmwb_income_base_b_bef_crbg(int t);
// GMWB Income Base BOM after income credit 
double fia_liab_gmwb_income_base_b_crbg(int t);
// GMWB Income Base End of Month Before Claims 
double fia_liab_gmwb_income_base_e_bef_crbg(int t);
// GMWB Income Base End of Month 
double fia_liab_gmwb_income_base_e_crbg(int t);
// Gmwb Income Base Reduction Fct Crbg 
double fia_liab_gmwb_income_base_reduction_fct_crbg(int t);
// GMWB Income Credit 
double fia_liab_gmwb_income_credit_b_crbg(int t);
// Gmwb Income Credit Base E Bef Crbg 
double fia_liab_gmwb_income_credit_base_e_bef_crbg(int t);
// Gmwb Income Credit Base E Crbg 
double fia_liab_gmwb_income_credit_base_e_crbg(int t);
// GMWB In Force End of Month 
double fia_liab_gmwb_inf(int t);
// GMWB In Force End of Month Before Claims 
double fia_liab_gmwb_inf_bef(int t);
// GMWB In The Money 
double fia_liab_gmwb_itm(int t);
// Gmwb Max Annual Wdl Pct Crbg 
double fia_liab_gmwb_max_ann_wdl_pct_crbg(int t);
// GMWB Guaranteed Maximum Withdrawal Amount 
double fia_liab_gmwb_max_wdl_amt(int t);
// Gmwb Min Income Base Bef Crbg 
double fia_liab_gmwb_min_income_base_bef_crbg(int t);
// Gmwb Pipp Stepup Ind Crbg 
double fia_liab_gmwb_pipp_stepup_ind_crbg(int t);
// GMWB Roll-Up Cap End of Month 
double fia_liab_gmwb_rollup_cap_inf(int t);
// GMWB Roll-Up Cap End of Month Before Claims 
double fia_liab_gmwb_rollup_cap_inf_bef(int t);
// Gmwb Wdl Amt Taken 
double fia_liab_gmwb_wdl_amt_e_bef_crbg(int t);
// Gmwb Wdl Amt that's excess withdrl 
double fia_liab_gmwb_wdl_amt_excess_bef_crbg(int t);
// Gmwb Wdl Excess Ind E Crbg 
double fia_liab_gmwb_wdl_excess_ind_e_crbg(int t);
// Gmwb Wdl Uti Level Crbg 
double fia_liab_gmwb_wdl_uti_level_crbg(int t);
// Gmwb Wdl Util Pct Crbg 
double fia_liab_gmwb_wdl_util_pct_crbg(int t);
// Uniform Rands Gmwb Util Crbg 
double fia_liab_gmwb_wdl_util_rand_num_crbg(int t);
// Gross Premium Annualized 
double fia_liab_gross_prem_annualzd(int t);
// Gwl Acq Exp Allow Crbg 
double fia_liab_gwl_acq_exp_allow_crbg(int t);
// Gwl Ceding Exp Allow Crbg 
double fia_liab_gwl_ceding_exp_allow_crbg(int t);
// Gwl Maint Exp Allow Crbg 
double fia_liab_gwl_maint_exp_allow_crbg(int t);
// Hedge Cash Flows 
double fia_liab_hedge_cash_flow(int t);
// Hedge Cost 
double fia_liab_hedge_cost(int t);
// Hedge Inv Amt Bom 
double fia_liab_hedge_inv_amt_bom(int t);
// Market Value of Hedges 
double fia_liab_hedge_mkt_val(int t);
// Hedge Market Value Growth 
double fia_liab_hedge_mkt_val_growth(int t);
// Increase in Market Value of Hedges 
double fia_liab_hedge_mkt_val_incr(int t);
// Hedge Sale Amt 
double fia_liab_hedge_sale_amt(int t);
// Income Phase Crbg 
double fia_liab_income_phase_bef_crbg(int t);
// Inflation Cumulative 
double fia_liab_infl_cumul(int t);
// Initialize 
double fia_liab_initialize(int t);
// Invested Assets 
double fia_liab_inv_asset(int t);
// Investment Income 
double fia_liab_inv_inc(int t);
// Investment Income For Book Profit 
double fia_liab_inv_inc_bk_prof(int t);
// Investment Income on Accumulated Earnings 
double fia_liab_inv_inc_earnings_accum(int t);
// Investment Income on Fund 
double fia_liab_inv_inc_fund(int t);
// Investment Income on Invested Assets 
double fia_liab_inv_inc_on_invested_assets(int t);
// Investment Income on Reserves 
double fia_liab_inv_inc_res(int t);
// Investment Income on Target Capital 
double fia_liab_inv_inc_tgt_cap(int t);
// Investment Income on Undistributed Earnings 
double fia_liab_inv_inc_undistrib_earnings(int t);
// Internal Rate of Return 
double fia_liab_irr(int t);
// IRR Without Target Capital 
double fia_liab_irr_wo_tgt_cap(int t);
// Issue Age Crbg 
double fia_liab_issue_age_col_crbg(int t);
// Itm Positive Indicator 
double fia_liab_itm_is_positive_crbg(int t);
// Lapse Dyn Add Myga Crbg 
double fia_liab_lapse_dyn_add_myga_crbg(int t);
// Lapse Dyn Addn Crbg 
double fia_liab_lapse_dyn_addn_crbg(int t);
// Lapse Dyn Arctan Mult Crbg 
double fia_liab_lapse_dyn_arctan_mult_crbg(int t);
// Lapse Dyn Base Prod Crbg 
double fia_liab_lapse_dyn_base_prod_crbg(int t);
// Lapse Dyn Crediting Rt 
double fia_liab_lapse_dyn_crediting_rt_crbg(int t);
// Lapse Dyn Fa Mult Crbg 
double fia_liab_lapse_dyn_fa_mult_crbg(int t);
// Lapse Dyn Isl Crbg 
double fia_liab_lapse_dyn_isl_crbg(int t);
// Lapse Dyn Mult Crbg 
double fia_liab_lapse_dyn_mult_crbg(int t);
// Lapse Dyn Sfc Mult Crbg 
double fia_liab_lapse_dyn_sfc_mult_crbg(int t);
// Lapse Rate 
double fia_liab_lapse_rate(int t);
// Base Lapse Rate 
double fia_liab_lapse_rate_base(int t);
// Lapse Rate Base adj Crbg 
double fia_liab_lapse_rate_base_adj_crbg(int t);
// Lapse Rate Monthly 
double fia_liab_lapse_rate_mthly(int t);
// Lapse Rate Mthly Skew2025 Crbg 
double fia_liab_lapse_rate_mthly_skew2025_crbg(int t);
// Lapse Rate Planned Numerator 
double fia_liab_lapse_rate_planned_numer(int t);
// Lapse Skew Cumul Fct Fa Crbg 
double fia_liab_lapse_skew_cumul_fct_fa_crbg(int t);
// Lapse Skew Fct Fa Crbg 
double fia_liab_lapse_skew_fct_fa_crbg(int t);
// Last Period Indicator 
double fia_liab_last_period_indicator(int t);
// Liabilities and Surplus Net of Reinsurance 
double fia_liab_liab_and_surp(int t);
// Maintenance Expenses Beginning of Month 
double fia_liab_maint_exp_bom(int t);
// Maintenance Expenses End of Month 
double fia_liab_maint_exp_eom(int t);
// Maturity Benefits 
double fia_liab_maturity_benefits(int t);
// Min Accum Val B bef Crbg 
double fia_liab_min_accum_val_b_bef_crbg(int t);
// Min Accum Val E bef Crbg 
double fia_liab_min_accum_val_e_bef_crbg(int t);
// Min Accum Val E Crbg 
double fia_liab_min_accum_val_e_crbg(int t);
// Minimum Contract Value at EOP 
double fia_liab_min_contract_val(int t);
// Minimum Contract Value Before Claims 
double fia_liab_min_contract_val_bef(int t);
// Min Wdl Val 
double fia_liab_min_wdl_val_b_crbg(int t);
// Min Wdl Val E Bef Crbg 
double fia_liab_min_wdl_val_e_bef_crbg(int t);
// Min Wdl Val 
double fia_liab_min_wdl_val_e_crbg(int t);
// Mort Rate Experience 
double fia_liab_mort_rate_exp(int t);
// Mort Rate GMWB 
double fia_liab_mort_rate_gmwb(int t);
// Months Since Issue 
double fia_liab_mths_since_issue(int t);
// MTT Call Gen2classic Cols 
double fia_liab_mtt_call_gen2classic_cols(int t);
// Call columns for MBVNB 
double fia_liab_mtt_call_mbvnb_crbg(int t);
// MTT Call Vectorized Cols 
double fia_liab_mtt_call_vectorized_cols(int t);
// MTT IRR 
double fia_liab_mtt_irr(int t);
// Target All 
double fia_liab_mtt_target_all(int t);
// March Through Time Target Column 
double fia_liab_mtt_tgt_distrib_earnings(int t);
// March Through Time Target Column 
double fia_liab_mtt_tgt_gaap_inc_aft_tax(int t);
// March Through Time Target Column 
double fia_liab_mtt_valn_tgt_gaap_mrb(int t);
// March Through Time Target Column - Valuation SFAS97RD 
double fia_liab_mtt_valn_tgt_gaap_sfas97rd(int t);
// March Through Time Target Column - Valuation PBA Scenario Amount 
double fia_liab_mtt_valn_tgt_pba_scen_amt(int t);
// MTT Valuation Stat/Tax 
double fia_liab_mtt_valn_tgt_stat_tax(int t);
// Mva Amt Crbg 
double fia_liab_mva_amt_bef_crbg(int t);
// Mva Amt Crbg 
double fia_liab_mva_amt_crbg(int t);
// Mva Amt due to excess withdrawal 
double fia_liab_mva_amt_excess_withdrl_crbg(int t);
// Competitor MVA Rate Numerator 
double fia_liab_mva_comp_num(int t);
// Competitor MVA Rate 
double fia_liab_mva_comp_rate(int t);
// Mva Current Term Crbg 
double fia_liab_mva_current_term_crbg(int t);
// Mva Factor Crbg 
double fia_liab_mva_factor_bef_crbg(int t);
// Mva Factor Crbg 
double fia_liab_mva_factor_crbg(int t);
// MVA Guarantee Years Remaining 
double fia_liab_mva_guar_yrs_remaining(int t);
// Market Value Adjustment Ratio End of Month 
double fia_liab_mva_ratio(int t);
// Market Value Adjustment Ratio Before Claims 
double fia_liab_mva_ratio_bef(int t);
// Myga Current Term Crbg 
double fia_liab_myga_current_term_crbg(int t);
// Myga Term Mth Elapsed Eom 
double fia_liab_myga_term_mth_elapsed_eom_crbg(int t);
// mrm ga yield plus matrix spread 
double fia_liab_new_money_rate_crbg(int t);
// Nmr 7Yr Govt Plus Sprd 
double fia_liab_nmr_7yr_govt_plus_sprd_crbg(int t);
// Notinal Amount to Hedge 
double fia_liab_notional_to_hedge(int t);
// Notional Amount to Hedge Cap 
double fia_liab_notional_to_hedge_cap(int t);
// Notional Amount to Hedge Index 
double fia_liab_notional_to_hedge_index(int t);
// Notional Amount to Hedge Long Strike 
double fia_liab_notional_to_hedge_long_strike(int t);
// Notional Amount to Hedge Net 
double fia_liab_notional_to_hedge_net(int t);
// Available Option Budget 
double fia_liab_opt_budget(int t);
// Option Budget Amount 
double fia_liab_opt_budget_amt(int t);
// Option Payoff 
double fia_liab_opt_payoff(int t);
// PBA Rollforward Base 
double fia_liab_pba_rollforward_base(int t);
// PBA Rollforward Base At Issue 
double fia_liab_pba_rollforward_base_issued(int t);
// PBA Rollforward Factor 
double fia_liab_pba_rollforward_factor(int t);
// Penalty Free Withdrawal Entitlement 
double fia_liab_pfwd_entitlement(int t);
// Penalty Free Withdrawal Entitlement Remaining Beginning of Month 
double fia_liab_pfwd_entitlement_remaining_bom(int t);
// Penalty Free Withdrawal Entitlement Remaining End of Month 
double fia_liab_pfwd_entitlement_remaining_e(int t);
// Penalty Free Withdrawal Rate Dynamic 
double fia_liab_pfwd_rate_dynamic(int t);
// Penalty Free Withdrawal Rate Monthly Percent Fund Value 
double fia_liab_pfwd_rate_mthly_fund_val(int t);
// Penalty Free Withdrawal Contract Value 
double fia_liab_pfwd_surr_contract_val(int t);
// Penalty Free Withdrawal Cumulative 
double fia_liab_pfwd_surr_cumul(int t);
// Penalty Free Withdrawal Cumulative Beginning of Month 
double fia_liab_pfwd_surr_cumul_bom(int t);
// Penalty Free Withdrawal Current Policy Year 
double fia_liab_pfwd_surr_curr_pol_yr(int t);
// Penalty Free Withdrawal Fund Value 
double fia_liab_pfwd_surr_fund_val(int t);
// Pfwd Use Crbg 
double fia_liab_pfwd_use_crbg(int t);
// Policy Month 
double fia_liab_pol_mth(int t);
// Policy Year 
double fia_liab_pol_yr(int t);
// Policies In Force Beginning of Month 
double fia_liab_policies_b(int t);
// Policies Female 
double fia_liab_policies_female_inf_crbg(int t);
// Policies In Force 
double fia_liab_policies_inf(int t);
// Policies Issued 
double fia_liab_policies_issued(int t);
// Policies: Joint 
double fia_liab_policies_joint_inf_crbg(int t);
// Policies: Last Survivor 
double fia_liab_policies_last_survivor_inf_crbg(int t);
// Policies Male 
double fia_liab_policies_male_inf_crbg(int t);
// Portfolio Yield After Tax 
double fia_liab_port_yld_aft_tax(int t);
// Premium Bonus 
double fia_liab_prem_bonus(int t);
// Prem Bonus Base E Bef Crbg 
double fia_liab_prem_bonus_base_e_bef_crbg(int t);
// Prem Bonus Base E Crbg 
double fia_liab_prem_bonus_base_e_crbg(int t);
// Prem Bonus Base Reduction Fct Crbg 
double fia_liab_prem_bonus_base_reduction_fct_crbg(int t);
// Prem Bonus Recap E Bef Crbg 
double fia_liab_prem_bonus_recap_e_bef_crbg(int t);
// Prem Bonus Recap E Crbg 
double fia_liab_prem_bonus_recap_e_crbg(int t);
// Premium Cumulative End of Month 
double fia_liab_prem_cumul(int t);
// Premium Cumulative End of Month Before Claims 
double fia_liab_prem_cumul_bef(int t);
// Prem Cumul Net Wdl Bef Crbg 
double fia_liab_prem_cumul_net_wdl_bef_crbg(int t);
// Prem Cumul Net Wdl Crbg 
double fia_liab_prem_cumul_net_wdl_crbg(int t);
// Prem Cumul Prop Wdl Bef Crbg 
double fia_liab_prem_cumul_prop_wdl_bef_crbg(int t);
// Prem Cumul Prop Wdl Crbg 
double fia_liab_prem_cumul_prop_wdl_crbg(int t);
// Premium Issued 
double fia_liab_prem_issued(int t);
// Premium Paid 
double fia_liab_prem_paid(int t);
// Premium Paid Net 
double fia_liab_prem_paid_net(int t);
// Premium Tax 
double fia_liab_prem_tax(int t);
// Pv Eom Cf Disc Rf Crbg 
double fia_liab_pv_ann_ben_disc_uel_crbg(int t);
// Pv Bom Cf Disc Rf Crbg 
double fia_liab_pv_bom_cf_disc_uel_crbg(int t);
// Pv Eom Cf Disc Rf Crbg 
double fia_liab_pv_eom_cf_disc_uel_crbg(int t);
// Pv Gmwb Benefit using current swap rate 
double fia_liab_pv_gmwb_ben_itm_current_crbg(int t);
// Pv Gmwb Benefit using initial swap rate 
double fia_liab_pv_gmwb_ben_itm_init_rate_crbg(int t);
// PV of GMWB Benefit for ITM 
double fia_liab_pv_gmwb_benefit_itm(int t);
// mawp for PV calc 
double fia_liab_pv_gmwb_mawp_crbg(int t);
// pip pct for PV calc 
double fia_liab_pv_gmwb_pip_pct_crbg(int t);
// Pv Sfc Ben Itm Crbg 
double fia_liab_pv_sfc_ben_itm_crbg(int t);
// Rand Num Non Us Return 
double fia_liab_rand_num_non_us_return_crbg(int t);
// RBC 
double fia_liab_rbc(int t);
// RBC C1 
double fia_liab_rbc_c1(int t);
// RBC C2 
double fia_liab_rbc_c2(int t);
// RBC C2 Net Amount at Risk 
double fia_liab_rbc_c2_nar(int t);
// RBC C3 
double fia_liab_rbc_c3(int t);
// RBC C3 Base Annuity High Risk 
double fia_liab_rbc_c3_base_ann_high_risk(int t);
// RBC C3 Base Annuity Low Risk 
double fia_liab_rbc_c3_base_ann_low_risk(int t);
// RBC C3 Base Annuity Medium Risk 
double fia_liab_rbc_c3_base_ann_medium_risk(int t);
// RBC C3 Policy Amount 
double fia_liab_rbc_c3_mp(int t);
// RBC C3 Stochastic Amount 
double fia_liab_rbc_c3_stoch_amt(int t);
// RBC C3 Stochastic Amount Unhedged 
double fia_liab_rbc_c3_stoch_amt_unhedged(int t);
// RBC C3 Unhedged 
double fia_liab_rbc_c3_unhedged(int t);
// RBC C4 
double fia_liab_rbc_c4(int t);
// Reinsurance Annuity Benefits EOM 
double fia_liab_reins_ann_benefits_eom(int t);
// Reinsurance Annuity Claims - GMWB 
double fia_liab_reins_ann_claims_gmwb(int t);
// Reinsurance Cash Flow Beginning of Month 
double fia_liab_reins_cash_flow_bom(int t);
// Reinsurance Cash Flow End of Month 
double fia_liab_reins_cash_flow_eom(int t);
// Reinsurance Cash Flow Interest 
double fia_liab_reins_cash_flow_int(int t);
// Reinsurance Cash Value 
double fia_liab_reins_cash_val(int t);
// Reinsurance Commission Chargeback Reimbursed 
double fia_liab_reins_comm_chargeback_reimb(int t);
// Reinsurance Commission Reimbursed 
double fia_liab_reins_comm_reimb(int t);
// Reinsurance Commission Reimbursement Beginning of Month 
double fia_liab_reins_comm_reimb_bom(int t);
// Reinsurance Commission Reimbursement End of Month 
double fia_liab_reins_comm_reimb_eom(int t);
// Reinsurance Death Benefit In Force 
double fia_liab_reins_dth_ben_inf(int t);
// Reinsurance Death Benefits 
double fia_liab_reins_dth_benefits(int t);
// Reinsurance Administration Expense 
double fia_liab_reins_exp(int t);
// Reinsurance Expense Reimbursed 
double fia_liab_reins_exp_reimb(int t);
// Reinsurance Expense Reimbursed Beginning of Month 
double fia_liab_reins_exp_reimb_bom(int t);
// Reinsurance Expense Reimbursed End of Month 
double fia_liab_reins_exp_reimb_eom(int t);
// Reinsurance GAAP Benefit Reserve 
double fia_liab_reins_gaap_ben_res(int t);
// Reinsurance GAAP Capitalized Commissions BOM 
double fia_liab_reins_gaap_capzd_comm_bom(int t);
// Reinsurance GAAP Capitalized Commissions EOM 
double fia_liab_reins_gaap_capzd_comm_eom(int t);
// Reinsurance GAAP Capitalized Premium Bonus 
double fia_liab_reins_gaap_capzd_prem_bonus(int t);
// Reinsurance GAAP Cash Flow Interest 
double fia_liab_reins_gaap_cash_flow_int(int t);
// Reinsurance GAAP Charges Income 
double fia_liab_reins_gaap_chg_inc(int t);
// Reinsurance GAAP Commissions Excess BOM 
double fia_liab_reins_gaap_comm_excess_bom(int t);
// Reinsurance GAAP Commissions Excess EOM 
double fia_liab_reins_gaap_comm_excess_eom(int t);
// Reinsurance GAAP Commissions Trail BOM 
double fia_liab_reins_gaap_comm_trail_bom(int t);
// Reinsurance GAAP Commissions Trail EOM 
double fia_liab_reins_gaap_comm_trail_eom(int t);
// Reinsurance GAAP Cost 
double fia_liab_reins_gaap_cost(int t);
// Reinsurance GAAP Credited Interest 
double fia_liab_reins_gaap_credited_int(int t);
// Reinsurance GAAP DAC 
double fia_liab_reins_gaap_dac(int t);
// Reinsurance GAAP DAC Increase 
double fia_liab_reins_gaap_dac_incr(int t);
// Reinsurance GAAP Investment Income on Reserves 
double fia_liab_reins_gaap_inv_inc_res(int t);
// Reinsurance GAAP Recoverables Net of DAC 
double fia_liab_reins_gaap_liab_net(int t);
// Reinsurance GAAP Loads Deducted 
double fia_liab_reins_gaap_loads_deducted(int t);
// Reinsurance GAAP Maintenance Expenses BOM 
double fia_liab_reins_gaap_maint_exp_bom(int t);
// Reinsurance GAAP Maintenance Expenses EOM 
double fia_liab_reins_gaap_maint_exp_eom(int t);
// Reinsurance GAAP Market Risk Benefits Liability 
double fia_liab_reins_gaap_mrb_liab(int t);
// Reinsurance GAAP Market Risk Benefits Liability Increase 
double fia_liab_reins_gaap_mrb_liab_incr(int t);
// Reinsurance GAAP Premium Bonus 
double fia_liab_reins_gaap_prem_bonus(int t);
// Reinsurance GAAP Premium Taxes 
double fia_liab_reins_gaap_prem_tax(int t);
// Reinsurance GAAP Recoveries 
double fia_liab_reins_gaap_recoveries(int t);
// Reinsurance GAAP SFAS133 Liability 
double fia_liab_reins_gaap_sfas133_liab(int t);
// Reinsurance GAAP SFAS 133 Liability Increase 
double fia_liab_reins_gaap_sfas133_liab_incr(int t);
// Reinsurance GAAP Surrender Income 
double fia_liab_reins_gaap_surr_inc(int t);
// Reinsurance Investment Income Reserve 
double fia_liab_reins_inv_inc_res(int t);
// Reinsurance Maturity Benefits 
double fia_liab_reins_maturity_benefits(int t);
// Reinsurance Premium 
double fia_liab_reins_prem(int t);
// Reinsurance Premium - Base 
double fia_liab_reins_prem_base(int t);
// Reinsurance Premium - GMWB 
double fia_liab_reins_prem_gmwb(int t);
// Reinsurance Premium Tax 
double fia_liab_reins_prem_tax(int t);
// Reinsurance Statutory Cost 
double fia_liab_reins_stat_cost(int t);
// Reinsurance Statutory Reserve 
double fia_liab_reins_stat_res(int t);
// Reinsurance Statutory Reserve Increase 
double fia_liab_reins_stat_res_incr(int t);
// Reinsurance Statutory Policy Reserve 
double fia_liab_reins_stat_res_mp(int t);
// Reinsurance Statutory Net Premium Reserve 
double fia_liab_reins_stat_res_npr(int t);
// Reinsurance Statutory Reserve Unhedged 
double fia_liab_reins_stat_res_unhedged(int t);
// Reinsurance Surrender Benefits 
double fia_liab_reins_surr_benefits(int t);
// Reinsurance Tax Reserve 
double fia_liab_reins_tax_res(int t);
// Reinsurance Tax Reserve Increase 
double fia_liab_reins_tax_res_incr(int t);
// Reinsurance Tax Policy Reserve 
double fia_liab_reins_tax_res_mp(int t);
// Reinsurance Withdrawal Benefits 
double fia_liab_reins_withdrl_benefits(int t);
// Shock Lapse Phase Crbg 
double fia_liab_shock_lapse_phase_crbg(int t);
// Shock Lapse Yr Ind Crbg 
double fia_liab_shock_lapse_yr_ind_crbg(int t);
// Startup 
virtual double virtual_startup(int t);
// Statutory Reserve 
double fia_liab_stat_res(int t);
// Statutory CARVM Reserve 
double fia_liab_stat_res_carvm(int t);
// Statutory CARVM Reserve Net 
double fia_liab_stat_res_carvm_net(int t);
// Statutory Reserve Excess 
double fia_liab_stat_res_excess(int t);
// Statutory Reserve Excess Unhedged 
double fia_liab_stat_res_excess_unhedged(int t);
// Statutory Reserve Increase 
double fia_liab_stat_res_incr(int t);
// Statutory Policy Reserve 
double fia_liab_stat_res_mp(int t);
// Statutory Policy Reserve Unhedged 
double fia_liab_stat_res_mp_unhedged(int t);
// Net Statutory Reserve 
double fia_liab_stat_res_net(int t);
// Statutory Net Reserve Excess 
double fia_liab_stat_res_net_excess(int t);
// Statutory Net Reserve Excess Unhedged 
double fia_liab_stat_res_net_excess_unhedged(int t);
// Net Statutory Policy Reserve 
double fia_liab_stat_res_net_mp(int t);
// Net Statutory Policy Reserve Unhedged 
double fia_liab_stat_res_net_mp_unhedged(int t);
// Net Statutory Net Premium Reserve 
double fia_liab_stat_res_net_npr(int t);
// Net Statutory Net Premium Reserve Unhedged 
double fia_liab_stat_res_net_npr_unhedged(int t);
// Net Statutory Reserve Stochastic Reserve 
double fia_liab_stat_res_net_stoch_res(int t);
// Net Statutory Reserve Stochastic Reserve Unhedged 
double fia_liab_stat_res_net_stoch_res_unhedged(int t);
// Net Statutory Reserve Unhedged 
double fia_liab_stat_res_net_unhedged(int t);
// Statutory Net Premium Reserve 
double fia_liab_stat_res_npr(int t);
// Statutory Net Premium Reserve Unhedged 
double fia_liab_stat_res_npr_unhedged(int t);
// Statutory Reserve Stochastic Reserve 
double fia_liab_stat_res_stoch_res(int t);
// Statutory Reserve Stochastic Reserve Unhedged 
double fia_liab_stat_res_stoch_res_unhedged(int t);
// Statutory Reserve Unhedged 
double fia_liab_stat_res_unhedged(int t);
// Surrender Benefits 
double fia_liab_surr_benefits(int t);
// Surrender Charge 
double fia_liab_surr_chg(int t);
// Surr chg due to excess withdrawal 
double fia_liab_surr_chg_excess_withdrl_crbg(int t);
// Surrender Charge Inforce End of Month 
double fia_liab_surr_chg_inf(int t);
// Surrender Charge Inforce End of Month Before Claims 
double fia_liab_surr_chg_inf_bef(int t);
// Surrender Charge Without MVA Inforce End of Month 
double fia_liab_surr_chg_inf_wo_mva(int t);
// Surrender Charge Without MVA Inforce End of Month Before Claims 
double fia_liab_surr_chg_inf_wo_mva_bef(int t);
// Surr Chg Pct Crbg 
double fia_liab_surr_chg_pct_crbg(int t);
// Proportion of Initial Life In Force 
double fia_liab_surv(int t);
// Probability of Survival for the Period 
double fia_liab_surv_period(int t);
// Tax on Book Profit 
double fia_liab_tax_bk_prof(int t);
// Tax on Book Profit Calendar Year to Date 
double fia_liab_tax_bk_prof_ytd(int t);
// Tax Capitalized Premium 
double fia_liab_tax_capzd_prem(int t);
// Tax Capitalized Premium Amortization 
double fia_liab_tax_capzd_prem_amortzn(int t);
// Tax Capitalized Premium Unamortized 
double fia_liab_tax_capzd_prem_unamortzd(int t);
// Tax on Accumulated Earnings 
double fia_liab_tax_earnings_accum(int t);
// Tax on Accumulated Earnings Calendar Year to Date 
double fia_liab_tax_earnings_accum_ytd(int t);
// Tax Reserve 
double fia_liab_tax_res(int t);
// Tax CARVM Reserve 
double fia_liab_tax_res_carvm(int t);
// Tax CARVM Reserve Net 
double fia_liab_tax_res_carvm_net(int t);
// Tax Reserve Increase 
double fia_liab_tax_res_incr(int t);
// Tax Policy Reserve 
double fia_liab_tax_res_mp(int t);
// Tax on Target Capital Income 
double fia_liab_tax_tgt_cap(int t);
// Tax on Target Capital Income Calendar Year to Date 
double fia_liab_tax_tgt_cap_ytd(int t);
// Taxable Income Book Profit 
double fia_liab_taxable_inc_bk_prof(int t);
// Taxable Income Book Profit Calendar Year to Date 
double fia_liab_taxable_inc_bk_prof_ytd(int t);
// Taxable Income Carry Forward Addition Calendar Year to Date 
double fia_liab_taxable_inc_carryfwd_addn_ytd(int t);
// Taxable Income Carry Forward Applied Calendar Year to Date 
double fia_liab_taxable_inc_carryfwd_applied_ytd(int t);
// Taxable Income Carry Forward Available 
double fia_liab_taxable_inc_carryfwd_avail(int t);
// Taxable Income Accumulated Earnings 
double fia_liab_taxable_inc_earnings_accum(int t);
// Taxable Income Accumulated Earnings Calendar Year to Date 
double fia_liab_taxable_inc_earnings_accum_ytd(int t);
// Taxable Income Target Capital 
double fia_liab_taxable_inc_tgt_cap(int t);
// Taxable Income Target Capital Calendar Year to Date 
double fia_liab_taxable_inc_tgt_cap_ytd(int t);
// Target Capital 
double fia_liab_tgt_cap(int t);
// Target Capital Effect 
double fia_liab_tgt_cap_effect(int t);
// Target Capital Increase 
double fia_liab_tgt_cap_incr(int t);
// Undistributed Earnings 
double fia_liab_undistrib_earnings(int t);
// Valuation Target - GAAP Market Risk Benefits 
double fia_liab_valn_tgt_gaap_mrb(int t);
// Valuation Target - GAAP SFAS 97 Retrospective Deposit 
double fia_liab_valn_tgt_gaap_sfas97rd(int t);
// Valuation Target - PBA Scenario Amount 
double fia_liab_valn_tgt_pba_scen_amt(int t);
// Valuation Target - Stat and Tax Reserves 
double fia_liab_valn_tgt_stat_tax(int t);
// Partial Withdrawal Benefit 
double fia_liab_withdrl_benefits(int t);
// Gross withdrl 
double fia_liab_withdrl_benefits_gross_crbg(int t);
// Cash Value Without MVA Before Claims 
double fia_liab_zz_cash_val_wo_mva_bef(int t);
// Tax Capitalized Premium Amortization Schedule 
double fia_liab_tax_capzd_prem_amortzn_sched(int t, int c);
// Audit detail flag 
int  fia_liab_audit_detail_flag();
// Period t in which Policy Commences 
int  fia_liab_commencement_period();
// Data File Name 
xstring  fia_liab_data_file_name();
// Months Since Issue At Projection Date 
int  fia_liab_elapsed_mths();
// Final Period 
int  fia_liab_final_period();
// GMWB Flag 
int  fia_liab_gmwb_flag();
// GMWB Required Years to Wait 
int  fia_liab_gmwb_req_yrs_wait();
// Inflation start mth 
int  fia_liab_infl_start_mth();
// Inflation start period 
int  fia_liab_infl_start_period();
// Inflation start year 
int  fia_liab_infl_start_yr();
// Issue Age 
int  fia_liab_issue_age();
// Issue Date 
int  fia_liab_issue_date();
// Issue Day 
double  fia_liab_issue_day();
// Issue Mth 
double  fia_liab_issue_mth();
// Issue Year for Model Point 
int  fia_liab_issue_yr();
// ITM Period Discount Rate 
double  fia_liab_itm_period_disc_rate();
// Lapse Shock Year Crbg 
int  fia_liab_lapse_shock_year_crbg();
// Lipm Ind 
int  fia_liab_lipm_ind_crbg();
// Maturity Age 
int  fia_liab_maturity_age();
// Period t in which Policy Matures 
int  fia_liab_maturity_period();
// max of mva and sc period 
int  fia_liab_max_mva_sc_period_crbg();
// Mort Impr Time Elapsed 
double  fia_liab_mort_impr_time_elapsed();
// Mva Comp Rate Issue 
double  fia_liab_mva_comp_rate_issue();
// Projection Date Adjusted 
xstring  fia_liab_proj_date_adj();
// Projection Start Date 
int  fia_liab_proj_start_date();
// Projection Start Mth 
int  fia_liab_proj_start_mth();
// Projection Start Yr 
int  fia_liab_proj_start_yr();
// Reinsurance Flag 
int  fia_liab_reins_flag();
// Projection start period 
int  fia_liab_start_period();
// State of World Financial File Path 
xstring  fia_liab_state_of_world_financial_file_path();
// Tax Capitalized Premium Amortization Years 
int  fia_liab_tax_capzd_prem_amortzn_yrs();
// Term (in Years) at Inception to Omega Age for Mortality Rates 
int  fia_liab_term_to_omega_age();
// Term (in Years) at Inception to Omega Age for Mortality Rates 
int  fia_liab_term_to_omega_age_f_crbg();
// Term (in Years) at Inception to Omega Age for Mortality Rates 
int  fia_liab_term_to_omega_age_m_crbg();

};
#endif
