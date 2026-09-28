
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
// Calendar Year 
double fiacarvm_liab_cal_yr(int t);
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
// Cash Surrender Value 
double fiacarvm_liab_cash_val(int t);
// Present Value of Cash Surrender Value 
double fiacarvm_liab_cash_val_pv(int t);
// Contract Value Before Penalty Free Withdrawal 
double fiacarvm_liab_contract_val_bef_pfwd(int t);
// Contract Value Before Surrender Charge 
double fiacarvm_liab_contract_val_bef_surr(int t);
// Credited Interest 
double fiacarvm_liab_credited_int(int t);
// Crediting Rate 
double fiacarvm_liab_crediting_rate(int t);
// Fixed Crediting Rate for Fund Value 
double fiacarvm_liab_crediting_rate_fund_value_fixed(int t);
// Death Benefit 
double fiacarvm_liab_dth_benefits(int t);
// Present Value of Death Benefits 
double fiacarvm_liab_dth_benefits_pv(int t);
// Fund Value After PFWD 
double fiacarvm_liab_fund_val_aft_pfwd(int t);
// Fund Value Beginning of Period 
double fiacarvm_liab_fund_val_b(int t);
// Fund Value Before PFWD 
double fiacarvm_liab_fund_val_bef_pfwd(int t);
// GMWB Annuitization Benefits 
double fiacarvm_liab_gmwb_ann_benefits(int t);
// PV of GMWB Annuitization Benefits 
double fiacarvm_liab_gmwb_ann_benefits_pv(int t);
// GMWB Rider Charge 
double fiacarvm_liab_gmwb_chg(int t);
// GMWB Fund Value End of Period after FPWs 
double fiacarvm_liab_gmwb_fund_val_aft_pfwd(int t);
// GMWB Fund Value End of Period before FPWs 
double fiacarvm_liab_gmwb_fund_val_bef_pfwd(int t);
// GMWB In Force End of Month Before Claims 
double fiacarvm_liab_gmwb_inf_bef(int t);
// GMWB Maximum Withdrawal Amount 
double fiacarvm_liab_gmwb_max_wdl_amt(int t);
// GMWB Premium End of Period after FPWs 
double fiacarvm_liab_gmwb_prem_aft_pfwd(int t);
// GMWB Premium Base nd of Period before FPWs 
double fiacarvm_liab_gmwb_prem_bef_pfwd(int t);
// GMWB Roll-Up Cap End of Month after pfw 
double fiacarvm_liab_gmwb_rollup_cap_aft_pfwd(int t);
// GMWB Roll-Up Cap End of Month Before pfw 
double fiacarvm_liab_gmwb_rollup_cap_bef_pfwd(int t);
// Guaranteed Minimum Contract Value 
double fiacarvm_liab_guar_min_contract_val(int t);
// Mort Rate Current Purchase Rate 
double fiacarvm_liab_mort_rate_ann_purch_curr(int t);
// Mort Rate Guaranteed Purchase Rate 
double fiacarvm_liab_mort_rate_ann_purch_guar(int t);
// Mortality rates for CARVM calculations. 
double fiacarvm_liab_mort_rate_carvm(int t);
// Mortality rate for annuity benefit CARVM valuations. 
double fiacarvm_liab_mort_rate_carvm_annuitzn(int t);
// Mortality rates for CARVM GMWB calculations 
double fiacarvm_liab_mort_rate_carvm_gmwb(int t);
// Mortality base rate used for CARVM in order to calculate omega age. 
double fiacarvm_liab_mort_rate_carvm_omega(int t);
// Market Value Adjustment Ratio 
double fiacarvm_liab_mva_ratio(int t);
// PV Nursing Home Benefits 
double fiacarvm_liab_nh_benefits_pv(int t);
// Nursing Home Incidence Rate 
double fiacarvm_liab_nh_incid_rate(int t);
// Penalty Free Withdrawal Entitlement 
double fiacarvm_liab_pfwd_entitlement(int t);
// Penalty Free Withdrawal 
double fiacarvm_liab_pfwd_surr(int t);
// Cumulative Penalty Free Withdrawal 
double fiacarvm_liab_pfwd_surr_cumul(int t);
// Present Value of Penalty Free Withdrawals 
double fiacarvm_liab_pfwd_surr_pv(int t);
// Policy Year 
double fiacarvm_liab_pol_yr(int t);
// Purchase Rate Current Spread 
double fiacarvm_liab_purch_rate_curr_sprd(int t);
// Integrated Reserve 
double fiacarvm_liab_res_integrated(int t);
// Integrated annuitization benefit reserve 
double fiacarvm_liab_res_integrated_annuitzn(int t);
// Integrated cash value reserve 
double fiacarvm_liab_res_integrated_cash_val(int t);
// Startup 
virtual double virtual_startup(int t);
// Surrender Charge 
double fiacarvm_liab_surr_chg(int t);
// Surrender Charge Percent 
double fiacarvm_liab_surr_chg_pct(int t);
// Surrender Charge Perent Column for Lookup 
double fiacarvm_liab_surr_chg_pct_col(int t);
// Survivors 
double fiacarvm_liab_surv(int t);
// CARVM annuitization stream test number 
int  fiacarvm_liab_carvm_annuitzn_test_num();
// Gender 
xstring  fiacarvm_liab_gender();
// Interest Guarantee Duration: 
int  fiacarvm_liab_int_guar_dur();
// Issue Age 
int  fiacarvm_liab_issue_age();
// Issue Date: 
int  fiacarvm_liab_issue_date();
// Issue Year 
int  fiacarvm_liab_issue_yr();
// Maximum Period to Calc Reserves 
int  fiacarvm_liab_max_calc_period();
// Months in the First Projection Period 
double  fiacarvm_liab_mths_in_first_period();
// Mva Comp Rate Issue 
double  fiacarvm_liab_mva_comp_rate_issue();
// Penalty Free Withdrawal Model Definition: 
xstring  fiacarvm_liab_pfwd_model();
// Cumulative Premium 
double  fiacarvm_liab_prem_cumul();

};
#endif
