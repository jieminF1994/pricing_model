
#ifndef __FIACARVM_LIAB_UDF_H_
#define __FIACARVM_LIAB_UDF_H_

#include "ModelClass\fiacarvm_liab.h"

class FIACARVM_LIAB_UDF : public FIACARVM_LIAB {

	friend class FIACARVM_LIAB;

//constructor 
FIACARVM_LIAB_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: FIACARVM_LIAB(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
FIACARVM_LIAB_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : FIACARVM_LIAB(columnCount, mocd, persObj) {}


// Administration Fee 
double fiacarvm_liab_admin_fee(int t);

// Age Last Birthday at Policy Anniversary 
double fiacarvm_liab_age_last(int t);

// Annuity Benefits 
double fiacarvm_liab_ann_benefits(int t);

// PV of Annuitization Benefits 
double fiacarvm_liab_ann_benefits_pv(int t);

// Annuity Factor Current Basis 
double fiacarvm_liab_ann_purch_factor_curr(int t);

// Annuity Factor Guaranteed Basis 
double fiacarvm_liab_ann_purch_factor_guar(int t);

// Annuity Valuation Factor 
double fiacarvm_liab_ann_valn_factor(int t);

// Attained Age 
double fiacarvm_liab_attained_age(int t);

// Discount Factor for CARVM Annuitization Benefit Reserves: 
double fiacarvm_liab_carvm_ann_disc_factor(int t);

// Discount Factor for CARVM Annuitization Elective Benefit Reserves 
double fiacarvm_liab_carvm_disc_factor_elect_annuitzn(int t);

// Discount Factor for CARVM Elective Benefits 
double fiacarvm_liab_carvm_disc_factor_elect_cash_val(int t);

// Discount Factor for CARVM Non-Elective Benefits 
double fiacarvm_liab_carvm_disc_factor_non_elect(int t);

// Discount Factor for CARVM Non Elective GMWB Benefits 
double fiacarvm_liab_carvm_disc_factor_non_elect_gmwb(int t);

// Cash value: 
double fiacarvm_liab_cash_val_b_aig(int t);

// Cash value: 
double fiacarvm_liab_cash_val_b_bef_aig(int t);

// Cash Surrender Value 
double fiacarvm_liab_cash_val_e_aig(int t);

// Cash value: 
double fiacarvm_liab_cash_val_e_bef_aig(int t);

// Present Value of Cash Surrender Value 
double fiacarvm_liab_cash_val_pv(int t);

// Contract value at beginning of year after discrete cashflows: 
double fiacarvm_liab_contract_val_b_aig(int t);

// Contract value at beginning of year: 
double fiacarvm_liab_contract_val_b_bef_aig(int t);

// Contract Value Before Surrender Charge 
double fiacarvm_liab_contract_val_e_aig(int t);

// Contract Value Before Penalty Free Withdrawal 
double fiacarvm_liab_contract_val_e_bef_aig(int t);

// Credited Interest 
double fiacarvm_liab_credited_int(int t);

// Crediting Rate 
double fiacarvm_liab_crediting_rate(int t);

// Crediting Rate (Black Scholes): 
double fiacarvm_liab_crediting_rate_black_scholes_aig(int t);

// Crediting Rate Index0 Aig 
double fiacarvm_liab_crediting_rate_index0_aig(int t);

// Death benefits: 
double fiacarvm_liab_dth_benefits_b_bef_aig(int t);

// Death Benefit 
double fiacarvm_liab_dth_benefits_e_aig(int t);

// Present Value of Death Benefits 
double fiacarvm_liab_dth_benefits_pv(int t);

// Death Claim Rate Blended on Experience Basis: 
double fiacarvm_liab_dth_claim_rate_blended_experience_aig(int t);

// Death Claim Rate under Experience Basis for the Policy: 
double fiacarvm_liab_dth_claim_rate_experience_aig(int t);

// Death Claim Rate Female on Experience Basis: 
double fiacarvm_liab_dth_claim_rate_female_experience_aig(int t);

// Death Claim Rate Monthly Joint on Experience Basis: 
double fiacarvm_liab_dth_claim_rate_last_survivor_experience_aig(int t);

// Death Claim Rate Male on Experience Basis: 
double fiacarvm_liab_dth_claim_rate_male_experience_aig(int t);

// Fund value at beginning of period after administration fee and withdrawal: 
double fiacarvm_liab_fund_val_b_aig(int t);

// Fund value at beginning of year: 
double fiacarvm_liab_fund_val_b_bef_aig(int t);

// Fund value after GLB charge: 
double fiacarvm_liab_fund_val_e_aig(int t);

// Fund value after interest credit: 
double fiacarvm_liab_fund_val_e_bef_aig(int t);

// GMAB BOY 
double fiacarvm_liab_gmab_av_b_aig(int t);

// GMAB EOY 
double fiacarvm_liab_gmab_av_e_aig(int t);

// GMWB Annuitization Benefits 
double fiacarvm_liab_gmwb_ann_benefits(int t);

// PV of GMWB Annuitization Benefits 
double fiacarvm_liab_gmwb_ann_benefits_pv(int t);

// GMWB Rider Charge 
double fiacarvm_liab_gmwb_chg(int t);

// GLB flex factor 
double fiacarvm_liab_gmwb_flex_mawp_adj_aig(int t);

// GLB base at beginning of year, after discrete charges/credits: 
double fiacarvm_liab_gmwb_income_base_b_aig(int t);

// GLB base at beginning of year: 
double fiacarvm_liab_gmwb_income_base_b_bef_aig(int t);

// GMWB income base at end of year: 
double fiacarvm_liab_gmwb_income_base_e_aig(int t);

// GLB income base at end of year, before deaths, surrenders, and withdrawals but after interest: 
double fiacarvm_liab_gmwb_income_base_e_bef_aig(int t);

// NYIA GLB base: 
double fiacarvm_liab_gmwb_income_base_ny_b_aig(int t);

// NYIA GLB base: 
double fiacarvm_liab_gmwb_income_base_ny_b_bef_aig(int t);

// NYIA GLB base: 
double fiacarvm_liab_gmwb_income_base_ny_e_aig(int t);

// NYIA GLB base: 
double fiacarvm_liab_gmwb_income_base_ny_e_bef_aig(int t);

// GLB income credit base at beginning of year after discrete charges/credits: 
double fiacarvm_liab_gmwb_income_credit_base_b_aig(int t);

// GLB income credit base at beginning of year: 
double fiacarvm_liab_gmwb_income_credit_base_b_bef_aig(int t);

// GLB income credit base at end of year: 
double fiacarvm_liab_gmwb_income_credit_base_e_aig(int t);

// GLB income credit base after interest and before deaths, surrenders, and withdrawals: 
double fiacarvm_liab_gmwb_income_credit_base_e_bef_aig(int t);

// GLB income credit at end of year before deaths, surrenders, and withdrawals: 
double fiacarvm_liab_gmwb_income_credit_e_bef_aig(int t);

// GLB base: 
double fiacarvm_liab_gmwb_inf_b_aig(int t);

// GLB base: 
double fiacarvm_liab_gmwb_inf_b_bef_aig(int t);

// GLB base: 
double fiacarvm_liab_gmwb_inf_e_aig(int t);

// GLB base: 
double fiacarvm_liab_gmwb_inf_e_bef_aig(int t);

// MAWP: 
double fiacarvm_liab_gmwb_max_annual_wdl_pct_aig(int t);

// MAWA at beginning of the year: 
double fiacarvm_liab_gmwb_max_wdl_amt_aig(int t);

// Minimum income base at end of year: 
double fiacarvm_liab_gmwb_min_income_base_e_bef_aig(int t);

// GMWB PIP Annual Wdl Pct 
double fiacarvm_liab_gmwb_pip_annual_wdl_pct_aig(int t);

// Guaranteed Minimum Contract Value 
double fiacarvm_liab_guar_min_contract_val(int t);

// Index Term Cap Rate Min Aig 
double fiacarvm_liab_index_term_cap_rate_min_aig(int t);

// index_term_par_rate_min_aig 
double fiacarvm_liab_index_term_par_rate_min_aig(int t);

// index_term_sprd_rate_max_aig 
double fiacarvm_liab_index_term_sprd_rate_max_aig(int t);

// Index Term Trigger Rate Min Aig 
double fiacarvm_liab_index_term_trigger_rate_min_aig(int t);

// Initialize 
double fiacarvm_liab_initialize(int t);

// Minimum accumulation value: 
double fiacarvm_liab_min_accum_val_b_aig(int t);

// NYIA Minimum accumulation value: 
double fiacarvm_liab_min_accum_val_b_bef_aig(int t);

// Minimum accumulation value: 
double fiacarvm_liab_min_accum_val_e_aig(int t);

// Minimum accumulation value: 
double fiacarvm_liab_min_accum_val_e_bef_aig(int t);

// Minimum Withdrawal Value Base at BOM 
double fiacarvm_liab_min_wdl_val_alt_b_aig(int t);

// Minimum Withdrawal Value Base at BOM before Charges: 
double fiacarvm_liab_min_wdl_val_alt_base_b_aig(int t);

// Alternate Minimum Withdrawal Value Base at EOM After Decrements: 
double fiacarvm_liab_min_wdl_val_alt_base_e_aig(int t);

// Alternate Minimum Withdrawal Value Base at EOM Before Decrements: 
double fiacarvm_liab_min_wdl_val_alt_base_e_bef_aig(int t);

// Alternate Minimum Withdrawal Value at EOM After Decrements: 
double fiacarvm_liab_min_wdl_val_alt_e_aig(int t);

// Alternate Minimum Withdrawal Value at EOM Before Decrements: 
double fiacarvm_liab_min_wdl_val_alt_e_bef_aig(int t);

// Minimum withdrawal value: 
double fiacarvm_liab_min_wdl_val_b_aig(int t);

// Minimum withdrawal value: 
double fiacarvm_liab_min_wdl_val_b_bef_aig(int t);

// Minimum Withdrawal Value After PFWD 
double fiacarvm_liab_min_wdl_val_e_aig(int t);

// Minimum Withdrawal Value Before PFWD 
double fiacarvm_liab_min_wdl_val_e_bef_aig(int t);

// Minimum Withdrawal Value at the beginning of the month 
double fiacarvm_liab_min_wdl_val_final_b_aig(int t);

// Minimum Withdrawal Value at the end of the month 
double fiacarvm_liab_min_wdl_val_final_e_aig(int t);

// Minimum Withdrawal Value at the end of the month, before claims (and survivorship) 
double fiacarvm_liab_min_wdl_val_final_e_bef_aig(int t);

// PV Nursing Home Benefits 
double fiacarvm_liab_nh_benefits_pv(int t);

// Nursing Home Incidence Rate 
double fiacarvm_liab_nh_incid_rate(int t);

// FPW entitlement at beginning of year after discrete cashflows: 
double fiacarvm_liab_pfwd_entitlement_b_aig(int t);

// FPW available at beginning of year: 
double fiacarvm_liab_pfwd_entitlement_b_bef_aig(int t);

// Partial Free Withdrawal Entitlement After Withdrawals: 
double fiacarvm_liab_pfwd_entitlement_e_aig(int t);

// Penalty Free Withdrawal Entitlement 
double fiacarvm_liab_pfwd_entitlement_e_bef_aig(int t);

// Free partial withdrawal percentage: 
double fiacarvm_liab_pfwd_pct_aig(int t);

// Withdrawal amount at beginning of year: 
double fiacarvm_liab_pfwd_surr_aig(int t);

// Cumulative FPWs taken: 
double fiacarvm_liab_pfwd_surr_cumul_aig(int t);

// Present Value of Penalty Free Withdrawals 
double fiacarvm_liab_pfwd_surr_pv(int t);

// Policy Month (relative to issue): 
double fiacarvm_liab_pol_mth_aig(int t);

// Policy Year 
double fiacarvm_liab_pol_yr(int t);

// End-Of-Month Policies In Force With Only Female Alive, Experience Mortality 
double fiacarvm_liab_policies_female_experience_aig(int t);

// End-Of-Month Policies In Force With Joint Status, Experience Mortality 
double fiacarvm_liab_policies_joint_experience_aig(int t);

// End-Of-Month Policies With Last Survivor Status, Experience Mortality 
double fiacarvm_liab_policies_last_survivor_experience_aig(int t);

// End-Of-Month Policies In Force With Only Male Alive, Experience Mortality 
double fiacarvm_liab_policies_male_experience_aig(int t);

// Premium Bonus Recapture: 
double fiacarvm_liab_prem_bonus_recapture_aig(int t);

// prem reduced proportionally by wdl 
double fiacarvm_liab_prem_cumul_prop_wdl_aig(int t);

// Integrated Reserve 
double fiacarvm_liab_res_integrated(int t);

// Integrated annuitization benefit reserve 
double fiacarvm_liab_res_integrated_annuitzn(int t);

// Integrated cash value reserve 
double fiacarvm_liab_res_integrated_cash_val(int t);

// Startup 
virtual double virtual_startup(int t);

// Surrender charge: 
double fiacarvm_liab_surr_chg_b_aig(int t);

// Surrender charge: 
double fiacarvm_liab_surr_chg_b_bef_aig(int t);

// Surrender Charge After Withdrawals: 
double fiacarvm_liab_surr_chg_e_aig(int t);

// Surrender Charge 
double fiacarvm_liab_surr_chg_e_bef_aig(int t);

// Surrender Charge Percent 
double fiacarvm_liab_surr_chg_pct(int t);

// Survivors 
double fiacarvm_liab_surv(int t);

// Carvm Annuitzn Test Number 
int  fiacarvm_liab_carvm_annuitzn_test_num();

// Lookup key: not sure why `carvm_cont_defn` input variable doesn't work: 
xstring  fiacarvm_liab_carvm_cont_defn_aig();

// Have GLB withdrawals begun in the outer loop? 
xstring  fiacarvm_liab_glb_withdrls_have_begun_aig();

// Interest Guarantee Duration: 
int  fiacarvm_liab_int_guar_dur();

// Issue Date: 
int  fiacarvm_liab_issue_date();

// Maximum Period to Calc Reserves 
int  fiacarvm_liab_max_calc_period();

// Months in the First Projection Period 
double  fiacarvm_liab_mths_in_first_year();

// Penalty Free Withdrawal Model Definition: 
xstring  fiacarvm_liab_pfwd_model();

// Cumulative Premium 
double  fiacarvm_liab_prem_cumul();


};
#endif
