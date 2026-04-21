
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

// PV CF using discount rate 1 
double fia_liab_acq_exp_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_acq_exp_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_acq_exp_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_acq_exp_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Administration Fee 
double fia_liab_admin_fee(int t);

// Age Last Birthday at Previous Policy Anniversary 
double fia_liab_age_last(int t);

// Annuity Benefits 
double fia_liab_ann_benefits_eom(int t);

// PV CF using discount rate 1 
double fia_liab_ann_benefits_eom_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_ann_benefits_eom_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_ann_benefits_eom_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_ann_benefits_eom_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Annuity Claims - GMWB 
double fia_liab_ann_claims_gmwb(int t);

// Annuity Claims - GMWB before check against maturity 
double fia_liab_ann_claims_gmwb_bef_maturity_aig(int t);

// PV CF using discount rate 1 
double fia_liab_ann_claims_gmwb_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_ann_claims_gmwb_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_ann_claims_gmwb_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_ann_claims_gmwb_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Number of policies that have annuitized 
double fia_liab_annuitzn_count_aig(int t);

// PV CF using discount rate 1 
double fia_liab_annuitzn_count_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_annuitzn_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_annuitzn_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_annuitzn_count_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Annuitization Rate 
double fia_liab_annuitzn_rate(int t);

// Annuitization Rate Monthly 
double fia_liab_annuitzn_rate_mthly(int t);

// Asset Yield 
double fia_liab_asset_yld(int t);

// Asset Yield for Investment Assets 
double fia_liab_asset_yld_inv(int t);

// Asset Yield including duration weighted adj, used for renewal rate setting only 
double fia_liab_asset_yld_inv_adj_aig(int t);

// Asset Yield Less Default 
double fia_liab_asset_yld_less_dflt(int t);

// Asset Yield Less Default for Investment Assets 
double fia_liab_asset_yld_less_dflt_inv(int t);

// Attained Age 
double fia_liab_attained_age(int t);

// Attained Age Female Aig 
double fia_liab_attained_age_female_aig(int t);

// Attained Age Male Aig 
double fia_liab_attained_age_male_aig(int t);

// Average Coupon Rate, End of Period 
double fia_liab_avg_coupon_rt_aig(int t);

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

// Cal Quarter Aig 
double fia_liab_cal_quarter_aig(int t);

// Calendar Year 
double fia_liab_cal_yr(int t);

// Calendar Year Relative 
double fia_liab_cal_yr_relative(int t);

// Cash Flow Percentage 
double fia_liab_cash_flow_pct_aig(int t);

// Cash Value 
double fia_liab_cash_val(int t);

// Cash Value End of Month Before Claims 
double fia_liab_cash_val_bef(int t);

// Cash Value without MVA, this column is created for tax reserve calculation 
double fia_liab_cash_val_no_mva_aig(int t);

// PV CF using discount rate 1 
double fia_liab_cash_val_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_cash_val_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_cash_val_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_cash_val_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Commissions Beginning of Month 
double fia_liab_comm_bom(int t);

// PV CF using discount rate 1 
double fia_liab_comm_bom_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_comm_bom_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_comm_bom_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_comm_bom_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Commission Chargeback 
double fia_liab_comm_chargeback(int t);

// PV CF using discount rate 1 
double fia_liab_comm_chargeback_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_comm_chargeback_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_comm_chargeback_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_comm_chargeback_pv_cf_disc_rate_aig_curve_uel_aig(int t);

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

// Comp Lookup Aig Gen2 
double fia_liab_comp_lookup_aig_gen2(int t);

// Contract Value at End of Period 
double fia_liab_contract_val(int t);

// Contract Value at End of Period Before Claims 
double fia_liab_contract_val_bef(int t);

// Covered person status code: 
double fia_liab_covered_person_status_col_e_bef_aig(int t);

// Credited Interest 
double fia_liab_credited_int(int t);

// Competitor Credited Interest Numerator 
double fia_liab_credited_int_comp_numer(int t);

// PV CF using discount rate 1 
double fia_liab_credited_int_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_credited_int_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_credited_int_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_credited_int_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Crediting Asset Yld Sprd Aig 
double fia_liab_crediting_asset_yld_sprd_aig(int t);

// crediting_cap_spr_fix_tri_index0_aig 
double fia_liab_crediting_cap_spr_fix_tri_index0_aig(int t);

// crediting part rate before additional par rate from fee4rate/ fee plus 
double fia_liab_crediting_part_rate_base_index0_aig(int t);

// Crediting Participation Rate for Index 0 
double fia_liab_crediting_part_rate_index0_aig(int t);

// Crediting Rate 
double fia_liab_crediting_rate(int t);

// Fixed Crediting Rate For Fund Value 
double fia_liab_crediting_rate_fix(int t);

// Crediting Rate, Partial, End of Month Before Claims 
double fia_liab_crediting_rate_partial_e_bef_aig(int t);

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

// Discount Rate for AIG discounting.  This is risk-free rate plus Internal Capital UEL spread. 
double fia_liab_disc_rate_aig_curve_ic_uel_aig(int t);

// Discount Rate for AIG discounting.  This is risk-free rate plus non-UEL spread. 
double fia_liab_disc_rate_aig_curve_no_uel_aig(int t);

// Discount Rate for AIG discounting.  This is risk-free rate plus UEL spread, or the "AIG curve". 
double fia_liab_disc_rate_aig_curve_uel_aig(int t);

// Discount Rate Portfolio Yield 
double fia_liab_disc_rate_port_yld(int t);

// Discount Rate Portfolio Ylield Definition Value 
double fia_liab_disc_rate_port_yld_defn_val(int t);

// Discount Rate for risk-free discounting.  This is risk-free rate without the spread. 
double fia_liab_disc_rate_risk_free_aig(int t);

// AIG liquidity spread: 
double fia_liab_disc_rate_sprd_uel_col_aig(int t);

// Distributable Earnings 
double fia_liab_distrib_earnings(int t);

// Distributable Earnings for IRR 
double fia_liab_distrib_earnings_irr(int t);

// Death Benefit In Force 
double fia_liab_dth_ben_inf(int t);

// Death Benefit In Force Before Decrements 
double fia_liab_dth_ben_inf_bef(int t);

// Death Benefit Net Amount At Risk Before Decrements 
double fia_liab_dth_ben_naar_bef_aig(int t);

// Death Benefits 
double fia_liab_dth_benefits(int t);

// PV CF using discount rate 1 
double fia_liab_dth_benefits_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_dth_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_dth_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_dth_benefits_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Death Claim Rate Monthly 
double fia_liab_dth_claim_rate_mthly(int t);

// Death Claim Rate Blended on Experience Basis: 
double fia_liab_dth_claim_rate_mthly_blended_experience_aig(int t);

// Dth Claim Rate Mthly Experience Aig 
double fia_liab_dth_claim_rate_mthly_experience_aig(int t);

// Death Claim Rate Female on Confinement Basis, Non-Confined: 
double fia_liab_dth_claim_rate_mthly_female_confinement_non_confined_aig(int t);

// Death Claim Rate Female on Experience Basis: 
double fia_liab_dth_claim_rate_mthly_female_experience_aig(int t);

// Death Claim Rate Monthly Female on GMWB Basis: 
double fia_liab_dth_claim_rate_mthly_female_gmwb_aig(int t);

// Death Claim Rate Monthly Joint on Experience Basis: 
double fia_liab_dth_claim_rate_mthly_last_survivor_experience_aig(int t);

// Death Claim Rate Monthly Joint on GMWB Basis: 
double fia_liab_dth_claim_rate_mthly_last_survivor_gmwb_aig(int t);

// Death Claim Rate Monthly Last Survivor Experience (Spousal 2019): 
double fia_liab_dth_claim_rate_mthly_last_survivor_spousal_2019_aig(int t);

// Death Claim Rate Male on Confinement Basis, Non-Confined: 
double fia_liab_dth_claim_rate_mthly_male_confinement_non_confined_aig(int t);

// Death Claim Rate Male on Experience Basis: 
double fia_liab_dth_claim_rate_mthly_male_experience_aig(int t);

// Death Claim Rate Monthly Male on GMWB Basis: 
double fia_liab_dth_claim_rate_mthly_male_gmwb_aig(int t);

// Policies that have died 
double fia_liab_dth_count_aig(int t);

// PV CF using discount rate 1 
double fia_liab_dth_count_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_dth_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_dth_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_dth_count_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Accumulated Earnings 
double fia_liab_earnings_accum(int t);

// Enhanced Income Cumulative Benefit Duration in Years, BOM 
double fia_liab_enhanced_income_benefit_cumul_yrs_aig(int t);

// Indicates if/when the benefit can be exercised: 
double fia_liab_enhanced_income_benefit_eligibility_flag_aig(int t);

// Enhanced Income Benefit Exercised? 
double fia_liab_enhanced_income_benefit_exercise_flag_aig(int t);

// Enhanced Income Benefit Indirect Exercise Flag: 
double fia_liab_enhanced_income_benefit_indirect_exercise_flag_aig(int t);

// Enhanced Income Confinement Month, Female Covered Person, EOM 
double fia_liab_enhanced_income_confinement_mth_female_e_aig(int t);

// Enhanced Income Confinement Month, Male Covered Person, EOM 
double fia_liab_enhanced_income_confinement_mth_male_e_aig(int t);

// Enhanced Income Confinement State, All Covered Persons, BOM 
double fia_liab_enhanced_income_confinement_state_b_aig(int t);

// Enhanced Income Confinement State, Female Covered Person, BOM 
double fia_liab_enhanced_income_confinement_state_female_b_aig(int t);

// Enhanced Income Confinement State, Male Covered Person, BOM 
double fia_liab_enhanced_income_confinement_state_male_b_aig(int t);

// Enhanced Income Random Number Draw, Female Covered Person 
double fia_liab_enhanced_income_rand_female_aig(int t);

// Enhanced Income Random Number Draw, Male Covered Person 
double fia_liab_enhanced_income_rand_male_aig(int t);

// Uniform random variate: 
double fia_liab_enhanced_income_utilization_rand_aig(int t);

// Finalize 
double fia_liab_finalize(int t);

// Fund Released on Annuitization 
double fia_liab_fund_released_ann(int t);

// PV CF using discount rate 1 
double fia_liab_fund_released_ann_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_released_ann_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_released_ann_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_released_ann_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Released on Death 
double fia_liab_fund_released_dth(int t);

// PV CF using discount rate 1 
double fia_liab_fund_released_dth_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_released_dth_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_released_dth_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_released_dth_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Released on Maturity 
double fia_liab_fund_released_maturity(int t);

// PV CF using discount rate 1 
double fia_liab_fund_released_maturity_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_released_maturity_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_released_maturity_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_released_maturity_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Released on Surrender 
double fia_liab_fund_released_surr(int t);

// PV CF using discount rate 1 
double fia_liab_fund_released_surr_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_released_surr_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_released_surr_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_released_surr_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Released on Withdrawal 
double fia_liab_fund_released_withdrl(int t);

// PV CF using discount rate 1 
double fia_liab_fund_released_withdrl_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_released_withdrl_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_released_withdrl_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_released_withdrl_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Value After Outflow - BOM 
double fia_liab_fund_val_b(int t);

// Fund Value Before Outflow BOM 
double fia_liab_fund_val_b_bef(int t);

// PV CF using discount rate 1 
double fia_liab_fund_val_b_bef_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_val_b_bef_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_val_b_bef_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_val_b_bef_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// PV CF using discount rate 1 
double fia_liab_fund_val_b_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_val_b_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_val_b_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_val_b_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund value at beginning of projection year: 
double fia_liab_fund_val_boy_b_aig(int t);

// Fund value at beginning of projection year: 
double fia_liab_fund_val_boy_e_aig(int t);

// Fund Value Decrement Amount 
double fia_liab_fund_val_decrem(int t);

// Fund Value Before Outflow EOM 
double fia_liab_fund_val_e_bef(int t);

// Fund Value End of Month, before maturity 
double fia_liab_fund_val_e_bef_maturity_aig(int t);

// Fund Value End of Month 
double fia_liab_fund_val_fixed(int t);

// PV CF using discount rate 1 
double fia_liab_fund_val_fixed_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_fund_val_fixed_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_fund_val_fixed_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_fund_val_fixed_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Fund Weighted Cap Spread Rate Aig 
double fia_liab_fund_weighted_cap_spread_fix_rt_aig(int t);

// Fund value * pricing spread: 
double fia_liab_fund_weighted_crediting_asset_yld_sprd_aig(int t);

// Fund Weighted Par Rate Aig 
double fia_liab_fund_weighted_par_rate_aig(int t);

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

// GAAP SOP 03-1 Additional Liability 
double fia_liab_gaap_sop031_addl_liab(int t);

// GAAP SOP 03-1 Additional Liability Increase 
double fia_liab_gaap_sop031_addl_liab_incr(int t);

// GAAP Surplus Increase 
double fia_liab_gaap_surp_incr(int t);

// GAAP Surrender Income 
double fia_liab_gaap_surr_inc(int t);

// Gender: 
double fia_liab_gender_col_e_bef_aig(int t);

// GMAB chg partial 
double fia_liab_gmab_chg_partial_e_aig(int t);

// GMAB chg partial 
double fia_liab_gmab_chg_partial_e_bef_aig(int t);

// GMAB global payoff 
double fia_liab_gmab_global_payoff_crbg(int t);

// PV CF AIG Curve UEL for gim global payoff 
double fia_liab_gmab_global_payoff_crbg_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// GMAB benefits payoff 
double fia_liab_gmab_payoff_crbg(int t);

// PV CF AIG Curve UEL for gim benefits payoff 
double fia_liab_gmab_payoff_crbg_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// GMWB Charge 
double fia_liab_gmwb_chg(int t);

// GMWB Charge At Surrender For Inforce End of Month 
double fia_liab_gmwb_chg_at_surr_aig(int t);

// GMWB Charge At Surrender For Inforce End of Month Before Claims 
double fia_liab_gmwb_chg_at_surr_bef_aig(int t);

// PV CF using discount rate 1 
double fia_liab_gmwb_chg_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_gmwb_chg_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_gmwb_chg_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_gmwb_chg_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// GMWB claim start t 
double fia_liab_gmwb_claim_start_duration_aig(int t);

// Remaining GMWB entitlement in the current year: 
double fia_liab_gmwb_entitlement_remaining_e_aig(int t);

// Remaining GMWB entitlement for the current year: 
double fia_liab_gmwb_entitlement_remaining_e_bef_aig(int t);

// GMWB Exercise Years 
double fia_liab_gmwb_exercise_yrs_aig(int t);

// GMWB Flex Covered Person Change Expense: 
double fia_liab_gmwb_flex_covered_person_change_expense_aig(int t);

// PV CF using discount rate 1 
double fia_liab_gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// GLB Flex exercise month: 
double fia_liab_gmwb_flex_exercise_mth_aig(int t);

// GMWB Income Base, BOM after Income Credit 
double fia_liab_gmwb_income_base_b_aig(int t);

// GMWB Income Base Cap, BOM 
double fia_liab_gmwb_income_base_cap_b_aig(int t);

// GMWB Income Base Cap, EOM 
double fia_liab_gmwb_income_base_cap_e_aig(int t);

// GMWB Income Base Cap, EOM before claims 
double fia_liab_gmwb_income_base_cap_e_bef_aig(int t);

// GMWB Income Base Cap Premium Base, BOM 
double fia_liab_gmwb_income_base_cap_prem_base_b_aig(int t);

// GMWB Income Base Cap Premium Base, EOM 
double fia_liab_gmwb_income_base_cap_prem_base_e_aig(int t);

// GMWB Income Base Cap Premium Base, EOM before claims 
double fia_liab_gmwb_income_base_cap_prem_base_e_bef_aig(int t);

// GMWB Income Base, EOM 
double fia_liab_gmwb_income_base_e_aig(int t);

// GMWB Income Base, EOM before claims 
double fia_liab_gmwb_income_base_e_bef_aig(int t);

// Auxilliary income base floor used to floor model MAWA: 
double fia_liab_gmwb_income_base_floor_e_aig(int t);

// Auxilliary floor to the model's MAWA amount: 
double fia_liab_gmwb_income_base_floor_e_bef_aig(int t);

// Gmwb Income Base Floor Premium Percentage for Policy Month t 
double fia_liab_gmwb_income_base_floor_prem_pct_col_aig(int t);

// GLB income base for NYIA: 
double fia_liab_gmwb_income_base_ny_b_aig(int t);

// GLB income base for NYIA: 
double fia_liab_gmwb_income_base_ny_b_bef_aig(int t);

// GLB income base for NYIA: 
double fia_liab_gmwb_income_base_ny_e_aig(int t);

// GLB income base for NYIA: 
double fia_liab_gmwb_income_base_ny_e_bef_aig(int t);

// Cumulative reduction factor for excess withdrawals taken: 
double fia_liab_gmwb_income_base_reduction_fct_cumul_e_bef_aig(int t);

// Income base reduction factor (for excess withdrawals): 
double fia_liab_gmwb_income_base_reduction_fct_e_bef_aig(int t);

// GLIA reduction factor for excess withdrawals: 
double fia_liab_gmwb_income_base_reduction_fct_ny_e_bef_aig(int t);

// GMWB Income Credit Base, EOM 
double fia_liab_gmwb_income_credit_base_e_aig(int t);

// GMWB Income Credit Base, EOM before claims 
double fia_liab_gmwb_income_credit_base_e_bef_aig(int t);

// GMWB Income Credit, EOM before claims 
double fia_liab_gmwb_income_credit_e_bef_aig(int t);

// Duration (in months) at which outer loop GLB income begins: 
double fia_liab_gmwb_income_start_duration_aig(int t);

// GMWB In Force End of Month 
double fia_liab_gmwb_inf(int t);

// GMWB In Force End of Month Before Claims 
double fia_liab_gmwb_inf_bef(int t);

// GMWB In The Money 
double fia_liab_gmwb_itm(int t);

// GMWB Mawa Auxilliary Floor: 
double fia_liab_gmwb_mawa_floor_e_aig(int t);

// Auxilliary Floor to the model MAWA: 
double fia_liab_gmwb_mawa_floor_e_bef_aig(int t);

// GMWB Maximum Annual Withdrawal Percent 
double fia_liab_gmwb_max_annual_wdl_pct_aig(int t);

// GMWB Guaranteed Maximum Withdrawal Amount Before Utilization Is Applied 
double fia_liab_gmwb_max_wdl_amt_bef_utilization_aig(int t);

// GMWB Guaranteed Maximum Withdrawal Amount 
double fia_liab_gmwb_max_wdl_amt_utilized(int t);

// GMWB Minimum Income Base, EOM before claims 
double fia_liab_gmwb_min_income_base_e_bef_aig(int t);

// Gmwb Pipp Stepup indicator Aig 
double fia_liab_gmwb_pipp_stepup_ind_aig(int t);

// Current GLB Utilization Level: 
double fia_liab_gmwb_wdl_utilization_level_e_bef_aig(int t);

// GMWB Withdrawal Utilization Rate (without exercising enhanced income benefit): 
double fia_liab_gmwb_wdl_utilization_pct_aig(int t);

// Gmwb Withdrawal Rate Indexing Addition, BOM 
double fia_liab_gmwb_withdrl_rate_indexing_addn_b_aig(int t);

// Gmwb Withdrawal Rate Indexing Assessment Max Reference Rate, BOM 
double fia_liab_gmwb_withdrl_rate_indexing_assessment_max_ref_rate_b_aig(int t);

// Gmwb Withdrawal Rate Indexing Assessment Max Reference Rate, EOM 
double fia_liab_gmwb_withdrl_rate_indexing_assessment_max_ref_rate_e_bef_aig(int t);

// Gmwb Withdrawal Rate Indexing Assessment Stepup Indicator, BOM 
double fia_liab_gmwb_withdrl_rate_indexing_assessment_stepup_ind_b_aig(int t);

// Gmwb Withdrawal Rate Indexing Policy Issue Reference Rate: 
double fia_liab_gmwb_withdrl_rate_indexing_policy_issue_ref_rate_aig(int t);

// Gmwb Withdrawal Rate Indexing Reference Rate: 
double fia_liab_gmwb_withdrl_rate_indexing_ref_rate_aig(int t);

// grop_flag 
double fia_liab_grop_flag(int t);

// GROP Base, End of Month 
double fia_liab_grop_inf_aig(int t);

// GROP Base, End of Month Before Claims 
double fia_liab_grop_inf_bef_aig(int t);

// Gross Premium Annualized 
double fia_liab_gross_prem_annualzd(int t);

// SFC amount before offset by AV 
double fia_liab_gross_sfc_ben_aig(int t);

// GWL Acquisition Expenses Allowance AIG 
double fia_liab_gwl_acq_exp_allow_aig(int t);

// GWL Ceding Expenses Allowance AIG 
double fia_liab_gwl_ceding_exp_allow_aig(int t);

// GWL Maintenance Expenses Allowance AIG 
double fia_liab_gwl_maint_exp_allow_aig(int t);

// GWL Make Whole Settlement Adj AIG 
double fia_liab_gwl_make_whole_settlement_adj_aig(int t);

// Hedge Cash Flows 
double fia_liab_hedge_cash_flow(int t);

// PV CF using discount rate 1 
double fia_liab_hedge_cash_flow_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_hedge_cash_flow_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_hedge_cash_flow_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_hedge_cash_flow_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Hedge Cost 
double fia_liab_hedge_cost(int t);

// Hedge Market Value Per Unit Notional 
double fia_liab_hedge_cost_per_unit_notional_aig(int t);

// PV CF using discount rate 1 
double fia_liab_hedge_cost_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_hedge_cost_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_hedge_cost_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_hedge_cost_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Hedge Invested Amount BOM 
double fia_liab_hedge_inv_amt_bom(int t);

// Market Value of Hedges 
double fia_liab_hedge_mkt_val(int t);

// Hedge Market Value Growth 
double fia_liab_hedge_mkt_val_growth(int t);

// Increase in Market Value of Hedges 
double fia_liab_hedge_mkt_val_incr(int t);

// Hedge Sale Amount 
double fia_liab_hedge_sale_amt(int t);

// PV CF using discount rate 1 
double fia_liab_hedge_sale_amt_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_hedge_sale_amt_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_hedge_sale_amt_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_hedge_sale_amt_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Index Term Index Return: 
double fia_liab_index_term_index_return_aig(int t);

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

// PV of GLB using Current Swap Rate: 
double fia_liab_isl_2019_pv_gmwb_benefit_aig(int t);

// PV of GLB using At-Issue Swap Rates: 
double fia_liab_isl_2019_pv_gmwb_benefit_at_issue_aig(int t);

// Issue age: 
double fia_liab_issue_age_col_e_bef_aig(int t);

// Issue Age Lookup Gen2 
double fia_liab_issue_age_mp_lookup_gen2(int t);

// itmness_lookup_aig_gen2 
double fia_liab_itmness_lookup_aig_gen2(int t);

// Number of policies that have lapsed 
double fia_liab_lapse_count_aig(int t);

// PV CF using discount rate 1 
double fia_liab_lapse_count_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_lapse_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_lapse_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_lapse_count_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Excess Lapse Rate for renewable myga 
double fia_liab_lapse_dyn_add_myga_aig(int t);

// Dynamic lapse addition 
double fia_liab_lapse_dyn_addn_aig(int t);

// Alt Model Dynamic Lapse Monthly Addition 
double fia_liab_lapse_dyn_alt_model_mthly_addn_aig(int t);

// Alt Model Dynamic Lapse Multiplier 
double fia_liab_lapse_dyn_alt_model_mult_aig(int t);

// ArcTan 2019 Dynamic Lapse Multiplier 
double fia_liab_lapse_dyn_arctan_2019_mult_aig(int t);

// ArcTan Dynamic Lapse Multiplier 
double fia_liab_lapse_dyn_arctan_mult_aig(int t);

// Base Product Dynamic Lapse Addition 
double fia_liab_lapse_dyn_base_prod_aig(int t);

// Base Product Dynamic Lapse crediting rate 
double fia_liab_lapse_dyn_base_prod_crediting_rt_aig(int t);

// Beta Dynamic Lapse Multiplier 
double fia_liab_lapse_dyn_beta_mult_aig(int t);

// Lapse Dyn FA Multiplier 
double fia_liab_lapse_dyn_fa_mult_aig(int t);

// Dynamic lapse monthly addition 
double fia_liab_lapse_dyn_mthly_addn_aig(int t);

// Dynamic lapse multiplier 
double fia_liab_lapse_dyn_mult_aig(int t);

// Additional Lapse Due to ISL 2019: 
double fia_liab_lapse_dyn_rate_add_isl_2019_aig(int t);

// Lapse Dyn SFC Mult Aig 
double fia_liab_lapse_dyn_sfc_mult_aig(int t);

// Lapse Rate 
double fia_liab_lapse_rate(int t);

// Base Lapse Rate 
double fia_liab_lapse_rate_base(int t);

// Base Lapse Rate for FA 
double fia_liab_lapse_rate_base_fa_aig(int t);

// Lapse Rate Monthly 
double fia_liab_lapse_rate_mthly(int t);

// Lapse Skew 2025 
double fia_liab_lapse_rate_mthly_skew2025_crbg(int t);

// Lapse Rate Planned Numerator 
double fia_liab_lapse_rate_planned_numer(int t);

// Cumul lapse skew factor 
double fia_liab_lapse_skew_cumul_fct_fa_aig(int t);

// Lapse skew factor for fixed annuity 
double fia_liab_lapse_skew_fct_fa_aig(int t);

// Last Period Indicator 
double fia_liab_last_period_indicator(int t);

// Liabilities and Surplus Net of Reinsurance 
double fia_liab_liab_and_surp(int t);

// Maintenance Expenses Beginning of Month 
double fia_liab_maint_exp_bom(int t);

// Maintenance Expenses End of Month 
double fia_liab_maint_exp_eom(int t);

// PV CF using discount rate 1 
double fia_liab_maint_exp_eom_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_maint_exp_eom_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_maint_exp_eom_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_maint_exp_eom_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Maturity Benefits 
double fia_liab_maturity_benefits(int t);

// PV CF using discount rate 1 
double fia_liab_maturity_benefits_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_maturity_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_maturity_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_maturity_benefits_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Market-based pre-tax cash flow 
double fia_liab_mb_pre_tax_cash_flow_aig(int t);

// PV CF using discount rate 1 
double fia_liab_mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// NYIA: minimum accumulation value 
double fia_liab_min_accum_val_b_aig(int t);

// NYIA: Minimum accumulation value: 
double fia_liab_min_accum_val_b_bef_aig(int t);

// NYIA: minimum accumulation value 
double fia_liab_min_accum_val_e_aig(int t);

// NYIA: minimum accumulation value 
double fia_liab_min_accum_val_e_bef_aig(int t);

// Minimum accumulation value before maturity payment: 
double fia_liab_min_accum_val_e_bef_maturity_aig(int t);

// Minimum Contract Value at EOP 
double fia_liab_min_contract_val(int t);

// Minimum Contract Value Before Claims 
double fia_liab_min_contract_val_bef(int t);

// Minimum Withdrawal Value Base at BOM before Charges: 
double fia_liab_min_wdl_val_alt_base_b_aig(int t);

// Alternate Minimum Withdrawal Value Base at EOM After Decrements: 
double fia_liab_min_wdl_val_alt_base_e_aig(int t);

// Alternate Minimum Withdrawal Value Base at EOM Before Decrements: 
double fia_liab_min_wdl_val_alt_base_e_bef_aig(int t);

// Alternate Minimum Withdrawal Value Base at EOM After Decrements, Before Maturity: 
double fia_liab_min_wdl_val_alt_base_e_bef_maturity_aig(int t);

// Alternate Minimum Withdrawal Value at EOM After Decrements: 
double fia_liab_min_wdl_val_alt_e_aig(int t);

// Alternate Minimum Withdrawal Value at EOM Before Decrements: 
double fia_liab_min_wdl_val_alt_e_bef_aig(int t);

// Minimum Withdrawal Value at BOM: 
double fia_liab_min_wdl_val_b_aig(int t);

// Minimum Withdrawal Value at EOM: 
double fia_liab_min_wdl_val_e_aig(int t);

// Minimum Withdrawal Value at EOM: 
double fia_liab_min_wdl_val_e_bef_aig(int t);

// Minimum Withdrawal Value at EOM, before maturity: 
double fia_liab_min_wdl_val_e_bef_maturity_aig(int t);

// Minimum Withdrawal Value at the end of the month 
double fia_liab_min_wdl_val_final_e_aig(int t);

// Minimum Withdrawal Value at the end of the month, before claims (and survivorship) 
double fia_liab_min_wdl_val_final_e_bef_aig(int t);

// Minimum Withdrawal Value at the end of the month, before maturity 
double fia_liab_min_wdl_val_final_e_bef_maturity_aig(int t);

// Months Since Issue 
double fia_liab_mths_since_issue(int t);

// MVA amount for full surrenders at the end of the month, current basis 
double fia_liab_mva_amt_full_surr_cash_val_aig(int t);

// PV CF using discount rate 1 
double fia_liab_mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// MVA amount for full surrenders at the end of the month, before claims and survivorship, current basis 
double fia_liab_mva_amt_full_surr_cash_val_bef_aig(int t);

// PV CF using discount rate 1 
double fia_liab_mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// MVA amount for full surrenders at the end of the month, current basis, before maturity 
double fia_liab_mva_amt_full_surr_cash_val_bef_maturity_aig(int t);

// MVA for partial withdrawals: 
double fia_liab_mva_amt_partial_wdl_aig(int t);

// current term length for mva 
double fia_liab_mva_current_term_aig(int t);

// MVA rate for full surrenders at the end of the month, current basis 
double fia_liab_mva_rate_full_surr_cash_val_aig(int t);

// MVA rate for full surrenders at the end of the month, before claims and survivorship, current basis 
double fia_liab_mva_rate_full_surr_cash_val_bef_aig(int t);

// MVA rate for full surrenders at the end of the month, current basis, before maturity 
double fia_liab_mva_rate_full_surr_cash_val_bef_maturity_aig(int t);

// current term length for myga 
double fia_liab_myga_current_term_aig(int t);

// mths elapsed since beginning of the current myga term 
double fia_liab_myga_term_mth_elapsed_eom_aig(int t);

// New Money Rate, End of Month 
double fia_liab_new_money_rate_aig(int t);

// The competitor rate also referred to as the new money rate (NMR) should be estimated by the Seven Year Treasury plus 65bps spread 
double fia_liab_nmr_7yr_govt_plus_sprd_aig(int t);

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

// PV CF using discount rate 1 
double fia_liab_opt_budget_amt_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_opt_budget_amt_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_opt_budget_amt_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_opt_budget_amt_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Opt Budget Cost Index0 AIG 
double fia_liab_opt_budget_cost_index0_aig(int t);

// Opt Budget Cost Index1 AIG 
double fia_liab_opt_budget_cost_index1_aig(int t);

// option budget for EPRS. Created when Solving for Particiaption Rate for EPRS 
double fia_liab_opt_budget_eprs_aig(int t);

// PV CF using discount rate 1 
double fia_liab_opt_budget_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_opt_budget_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_opt_budget_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_opt_budget_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// ATM Opt Cost. Created when Solving for Particiaption Rate for Fee4rate Phase 2 
double fia_liab_opt_cost_atm_aig(int t);

// Option Payoff 
double fia_liab_opt_payoff(int t);

// Option Payoff: 
double fia_liab_opt_payoff_aig(int t);

// PV CF using discount rate 1 
double fia_liab_opt_payoff_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_opt_payoff_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_opt_payoff_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_opt_payoff_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// PV CF using discount rate 1 
double fia_liab_opt_payoff_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_opt_payoff_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_opt_payoff_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_opt_payoff_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// PBA Rollforward Base 
double fia_liab_pba_rollforward_base(int t);

// PBA Rollforward Base At Issue 
double fia_liab_pba_rollforward_base_issued(int t);

// PBA Rollforward Factor 
double fia_liab_pba_rollforward_factor(int t);

// Penalty Free Withdrawal Entitlement 
double fia_liab_pfwd_entitlement(int t);

// Penalty Free Withdrawal Entitlement Remaining End of Month 
double fia_liab_pfwd_entitlement_remaining_e(int t);

// Penalty Free Withdrawal Entitlement Remaining Beginning of Month 
double fia_liab_pfwd_entitlement_remaining_e_bef(int t);

// Penalty Free Withdrawal Rate Dynamic 
double fia_liab_pfwd_rate_dynamic(int t);

// Penalty Free Withdrawal Rate Monthly Percent Fund Value 
double fia_liab_pfwd_rate_mthly_fund_val(int t);

// PFWD rate for the NYIA MAV: 
double fia_liab_pfwd_rate_mthly_min_accum_val_aig(int t);

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

// Penalty free withdrawal rate 
double fia_liab_pfwd_use_aig(int t);

// Policy Month 
double fia_liab_pol_mth(int t);

// Policy Year 
double fia_liab_pol_yr(int t);

// Policies In Force Beginning of Month 
double fia_liab_policies_b(int t);

// PV CF using discount rate 1 
double fia_liab_policies_b_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_policies_b_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_policies_b_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_policies_b_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// End-Of-Month Policies In Force With Only Female Alive, Experience Mortality 
double fia_liab_policies_female_experience_aig(int t);

// End-Of-Month Policies In Force With Only Female Alive, GMWB Mortality 
double fia_liab_policies_female_gmwb_aig(int t);

// Policies In Force 
double fia_liab_policies_inf(int t);

// Policies Issued 
double fia_liab_policies_issued(int t);

// End-Of-Month Policies In Force With Joint Status, Experience Mortality 
double fia_liab_policies_joint_experience_aig(int t);

// End-Of-Month Policies In Force With Joint Status, GMWB Mortality 
double fia_liab_policies_joint_gmwb_aig(int t);

// End-Of-Month Policies With Last Survivor Status, Experience Mortality 
double fia_liab_policies_last_survivor_experience_aig(int t);

// End-Of-Month Policies With Last Survivor Status, GMWB Mortality 
double fia_liab_policies_last_survivor_gmwb_aig(int t);

// End-Of-Month Policies In Force With Only Male Alive, Experience Mortality 
double fia_liab_policies_male_experience_aig(int t);

// End-Of-Month Policies In Force With Only Male Alive, GMWB Mortality 
double fia_liab_policies_male_gmwb_aig(int t);

// Portfolio Yield After Tax 
double fia_liab_port_yld_aft_tax(int t);

// Pre-tax liability cash flow, EOM 
double fia_liab_pre_tax_cash_flow_liab_eom_aig(int t);

// PV CF using discount rate 1 
double fia_liab_pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Time-weighted pre-tax cash flow for Macaulay Duration calculation 
double fia_liab_pre_tax_cash_flow_liab_weighted_eom_aig(int t);

// PV CF using discount rate 1 
double fia_liab_pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Premium Bonus 
double fia_liab_prem_bonus(int t);

// Premium Bonus Base at the End of Month: 
double fia_liab_prem_bonus_base_e_aig(int t);

// Premium bonus amount before decrements: 
double fia_liab_prem_bonus_base_e_bef_aig(int t);

// Premium bonus recapture base reduction factor: 
double fia_liab_prem_bonus_recapture_base_reduction_fct_aig(int t);

// Premium Bonus Recapture Inforce Amount at the End of the Month after decrements: 
double fia_liab_prem_bonus_recapture_e_aig(int t);

// Premium Bonus Recaputure Amount at the End of the Month before decrements: 
double fia_liab_prem_bonus_recapture_e_bef_aig(int t);

// Premium Cumulative End of Month 
double fia_liab_prem_cumul(int t);

// Premium Cumulative End of Month Before Claims 
double fia_liab_prem_cumul_bef(int t);

// Premium Cumulative Net of Gross Withdrawals End of Month 
double fia_liab_prem_cumul_net_wdl_aig(int t);

// Premium Cumulative Net of Gross Withdrawals End of Month Before Claims 
double fia_liab_prem_cumul_net_wdl_bef_aig(int t);

// Premium Cumulative Net of Pre-Income Withdrawals End of Month 
double fia_liab_prem_cumul_net_wdl_pre_income_aig(int t);

// Premium Cumulative Net of Pre-Income Withdrawals End of Month Before Claims 
double fia_liab_prem_cumul_net_wdl_pre_income_bef_aig(int t);

// Net premiums with interest: 
double fia_liab_prem_cumul_net_wdl_with_int_e_aig(int t);

// Net premiums with interest: 
double fia_liab_prem_cumul_net_wdl_with_int_e_bef_aig(int t);

// Premium Cumulative Net of proportional Withdrawals End of Month 
double fia_liab_prem_cumul_proportional_wdl_aig(int t);

// Premium Cumulative net of proportional Withdrawals End of Month Before Claims 
double fia_liab_prem_cumul_proportional_wdl_bef_aig(int t);

// Premium Issued 
double fia_liab_prem_issued(int t);

// Premium Paid 
double fia_liab_prem_paid(int t);

// Premium Paid Net 
double fia_liab_prem_paid_net(int t);

// PV CF using discount rate 1 
double fia_liab_prem_paid_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_prem_paid_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_prem_paid_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_prem_paid_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Premium Tax 
double fia_liab_prem_tax(int t);

// Proj Csv For Interpolation Aig 
double fia_liab_proj_csv_for_interpolation_aig(int t);

// PV of GMWB and Death Benefits for ITM 
double fia_liab_pv_benefit_itm_aig(int t);

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

// Reinsurance GAAP SOP 03-1 Additional Liability 
double fia_liab_reins_gaap_sop031_addl_liab(int t);

// Reinsurance GAAP SOP 03-1 Additional Liability Increase 
double fia_liab_reins_gaap_sop031_addl_liab_incr(int t);

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

// Remaining Preferred Withdrawal Amount EOM: 
double fia_liab_remaining_preferred_wdl_amt_e_aig(int t);

// Remaining Preferred Withdrawal Amount EOM, Before Claims: 
double fia_liab_remaining_preferred_wdl_amt_e_bef_aig(int t);

// Risk Free Rate with no AIG spread 
double fia_liab_risk_free_rate_no_sprd_aig(int t);

// Risk Free Rate with Internal Capital UEL spread 
double fia_liab_risk_free_rate_with_ic_uel_sprd_aig(int t);

// Risk Free Rate with non-UEL AIG spread 
double fia_liab_risk_free_rate_with_no_uel_sprd_aig(int t);

// Risk Free Rate with UEL AIG spread 
double fia_liab_risk_free_rate_with_uel_sprd_aig(int t);

// Seriatim Run Target 
double fia_liab_seriatim_run_tgt(int t);

// column to output sfc Annual Hedge Cost 
double fia_liab_sfc_annual_hedge_cost_col_aig(int t);

// SFC Benefit from fee for rate or fee plus feature 
double fia_liab_sfc_ben_aig(int t);

// SFC Itm Aig 
double fia_liab_sfc_itm_aig(int t);

// Is this shock lapse year 
double fia_liab_shock_lapse_yr_ind_crbg(int t);

// shock_phase_lookup_aig_gen2 
double fia_liab_shock_phase_lookup_aig_gen2(int t);

// SNFL Prospective functionality (CA specific) for fund_val_fixed 
double fia_liab_snfl_prospective_e_aig(int t);

// SNFL Prospective functionality (CA specific) for fund_val_e_bef 
double fia_liab_snfl_prospective_e_bef_aig(int t);

// Startup 
virtual double virtual_startup(int t);

// Statutory Reserve 
double fia_liab_stat_res(int t);

// Statutory CARVM Reserve 
double fia_liab_stat_res_carvm(int t);

// Stat Res Carvm Base 
double fia_liab_stat_res_carvm_base_aig(int t);

// Statutory CARVM Reserve 
double fia_liab_stat_res_carvm_base_full_wd_aig(int t);

// Statutory CARVM Reserve 
double fia_liab_stat_res_carvm_base_no_wd_aig(int t);

// Statutory CARVM Reserve Net 
double fia_liab_stat_res_carvm_net(int t);

// Withdrawal Benefit Stat Res 
double fia_liab_stat_res_carvm_wb_aig(int t);

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

// Stat Res Released Xol Aig 
double fia_liab_stat_res_released_xol_aig(int t);

// Statutory Reserve Stochastic Reserve 
double fia_liab_stat_res_stoch_res(int t);

// Statutory Reserve Stochastic Reserve Unhedged 
double fia_liab_stat_res_stoch_res_unhedged(int t);

// Statutory Reserve Unhedged 
double fia_liab_stat_res_unhedged(int t);

// XOL Stat Res Carvm 
double fia_liab_stat_res_xol_carvm_aig(int t);

// XOL Excess Res 
double fia_liab_stat_res_xol_excess_res_aig(int t);

// XOL New Business Economic Reserve 
double fia_liab_stat_res_xol_nb_eco_res_aig(int t);

// PV of NB Ending XOL Amount 
double fia_liab_stat_res_xol_pv_nb_ending_amount_aig(int t);

// Surrender Benefits 
double fia_liab_surr_benefits(int t);

// PV CF using discount rate 1 
double fia_liab_surr_benefits_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_surr_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_surr_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_surr_benefits_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// Surrender Charge 
double fia_liab_surr_chg(int t);

// Surrender Charge Inforce End of Month 
double fia_liab_surr_chg_inf(int t);

// Surrender Charge Inforce End of Month Before Claims 
double fia_liab_surr_chg_inf_bef(int t);

// Surrender Charge Inforce End of Month, before maturity 
double fia_liab_surr_chg_inf_bef_maturity_aig(int t);

// Surrender Charge Inforce End of Month Before Claims, No GMWB Charge 
double fia_liab_surr_chg_inf_bef_no_gmwb_chg_aig(int t);

// Surrender Charge Inforce End of Month, No GMWB Charge 
double fia_liab_surr_chg_inf_no_gmwb_chg_aig(int t);

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

// Maximum 10-year treasury rate to date: 
double fia_liab_ten_year_treasury_annualized_return_cumul_max_aig(int t);

// Average 10-year treasury rate over 3 months: 
double fia_liab_ten_year_treasury_annualized_return_three_mth_avg_aig(int t);

// Target Capital 
double fia_liab_tgt_cap(int t);

// Target Capital Effect 
double fia_liab_tgt_cap_effect(int t);

// Target Capital Increase 
double fia_liab_tgt_cap_incr(int t);

// Tier Number 
double fia_liab_tier_number_aig(int t);

// Participation Rate Enhancement Strategy Fee 
double fia_liab_tier_strat_fee_aig(int t);

// Tier Strat Fee  At Surrender For Inforce End of Month 
double fia_liab_tier_strat_fee_at_surr_aig(int t);

// Tier Strat Fee At Surrender For Inforce End of Month Before Claims 
double fia_liab_tier_strat_fee_at_surr_bef_aig(int t);

// Undistributed Earnings 
double fia_liab_undistrib_earnings(int t);

// Uniform Random Number Variable Stream 1: 
double fia_liab_uniform_rands_1_aig(int t);

// Uniform Random Number Variable Stream 2: 
double fia_liab_uniform_rands_2_aig(int t);

// Uniform Random Variates: 
double fia_liab_uniform_rands_3_aig(int t);

// Valuation Target - GAAP SFAS133 
double fia_liab_valn_tgt_gaap_sfas133(int t);

// Valuation Target - GAAP SFAS 97 Retrospective Deposit 
double fia_liab_valn_tgt_gaap_sfas97rd(int t);

// Valuation Target - GAAP SOP 03-1 
double fia_liab_valn_tgt_gaap_sop031(int t);

// Valuation Target - PBA Scenario Amount 
double fia_liab_valn_tgt_pba_scen_amt(int t);

// Valuation Target - Stat and Tax Reserves 
double fia_liab_valn_tgt_stat_tax(int t);

// Weighted Ending Strategy Return 
double fia_liab_weighted_ending_strategy_return_aig(int t);

// Weighted Ending Strategy Return for GMWB rollup rate 
double fia_liab_weighted_ending_strategy_return_gmwb_rollup_aig(int t);

// Weighted EPRS Cost percentage 
double fia_liab_weighted_eprs_cost_aig(int t);

// Prorated strategy return: 
double fia_liab_weighted_prorated_strategy_return_aig(int t);

// Weighted Strategy Return 
double fia_liab_weighted_strategy_return_aig(int t);

// Partial Withdrawal Benefit 
double fia_liab_withdrl_benefits(int t);

// Partial withdrawal charge: 
double fia_liab_withdrl_benefits_chg_aig(int t);

// Gross (of withdrawal charges) partial withdrawal: 
double fia_liab_withdrl_benefits_gross_aig(int t);

// Cumulative withdrawals taken in the current projection year: 
double fia_liab_withdrl_benefits_gross_cumul_yr_e_aig(int t);

// Cumulative gross withdrawals in current projection year: 
double fia_liab_withdrl_benefits_gross_cumul_yr_e_bef_aig(int t);

// Cumulative amount of excess withdrawals taken: 
double fia_liab_withdrl_benefits_gross_excess_cumul_e_aig(int t);

// Cumulative amount of excess withdrawals taken: 
double fia_liab_withdrl_benefits_gross_excess_cumul_e_bef_aig(int t);

// Excess withdrawal: 
double fia_liab_withdrl_benefits_gross_excess_e_bef_aig(int t);

// Withdrawal Benefits Gross Excess Indicator: 
double fia_liab_withdrl_benefits_gross_excess_ind_e_aig(int t);

// Withdrawal Benefits Gross Excess Indicator: 
double fia_liab_withdrl_benefits_gross_excess_ind_e_bef_aig(int t);

// Partial interest credit: 
double fia_liab_withdrl_benefits_gross_excess_int_credit_e_bef_aig(int t);

// Regular withdrawals (not excess): 
double fia_liab_withdrl_benefits_gross_regular_e_bef_aig(int t);

// Full interest earnings: 
double fia_liab_withdrl_benefits_gross_regular_int_credit_e_bef_aig(int t);

// PV CF using discount rate 1 
double fia_liab_withdrl_benefits_pv_cf_disc_rate_1(int t);

// PV CF using AIG Curve IC UEL 
double fia_liab_withdrl_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig(int t);

// PV CF using AIG Curve No UEL 
double fia_liab_withdrl_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig(int t);

// PV CF AIG Curve UEL 
double fia_liab_withdrl_benefits_pv_cf_disc_rate_aig_curve_uel_aig(int t);

// XOL Amount 
double fia_liab_xol_amount_aig(int t);

// XOL Annuity Claims - GMWB before check against maturity or XOL deal duration 
double fia_liab_xol_gmwb_claim_crbg(int t);

// XOL Premium 
double fia_liab_xol_prem_aig(int t);

// Tax Capitalized Premium Amortization Schedule 
double fia_liab_tax_capzd_prem_amortzn_sched(int t, int c);

// Audit detail flag 
int  fia_liab_audit_detail_flag();

// Period t in which Policy Commences 
int  fia_liab_commencement_period();

// Number of Periods Between Coupons 
int  fia_liab_coupon_freq_aig();

// Months Since Issue At Projection Date 
int  fia_liab_elapsed_mths();

// Enhanced Income Rider Flag 
int  fia_liab_enhanced_income_flag_aig();

// Final Period 
int  fia_liab_final_period();

// 1 for annual, 4 for quarterly, etc.: 
double  fia_liab_gmwb_chg_freq_per_yr_aig();

// GMWB Flag 
int  fia_liab_gmwb_flag();

// GMWB Minimum Income Base/Rollup Max Years 
int  fia_liab_gmwb_mib_rollup_max_yrs_aig();

// GMWB Required Years to Wait 
int  fia_liab_gmwb_req_yrs_wait();

// Independent Model Point Flag 
int  fia_liab_independent_flag();

// Inflation start mth 
int  fia_liab_infl_start_mth();

// Inflation start period 
int  fia_liab_infl_start_period();

// Inflation start year 
int  fia_liab_infl_start_yr();

// Initial policy count for female lives (Spousal 2019) 
double  fia_liab_init_policies_female_spousal_2019_calc_aig();

// Initial policy count for joint lives (Experience) 
double  fia_liab_init_policies_joint_experience_calc_aig();

// Initial policy count for joint lives (Spousal 2019) 
double  fia_liab_init_policies_joint_spousal_2019_calc_aig();

// Initial policy count for male lives (Spousal 2019) 
double  fia_liab_init_policies_male_spousal_2019_calc_aig();

// Interest Guarantee Duration: 
int  fia_liab_int_guar_dur();

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

// Last year in the surrender charge table 
int  fia_liab_lapse_shock_year_aig();

// Maturity Age 
int  fia_liab_maturity_age();

// Period t in which Policy Maturity Benefits are calculated 
int  fia_liab_maturity_benefits_period_aig();

// Period t in which Policy Matures 
int  fia_liab_maturity_period();

// Greater of surrender charge period and MVA period: 
int  fia_liab_max_mva_surr_chg_period_aig();

// MVA flag for rate table look-ups: 
xstring  fia_liab_mva_defn_lookup_aig();

// Primary Tail Period 
int  fia_liab_primary_tail_period_aig();

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

// Tax Res Equals Stat Flag 
double  fia_liab_tax_res_equals_stat_flag();

// Term (in Years) at Inception to Omega Age for Mortality Rates 
int  fia_liab_term_to_omega_age();

// Frequency of PFWD withdrawals: 
double  fia_liab_wdl_period_mths_aig();


};
#endif
