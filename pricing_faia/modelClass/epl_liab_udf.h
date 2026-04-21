
#ifndef __EPL_LIAB_UDF_H_
#define __EPL_LIAB_UDF_H_

#include "ModelClass\epl_liab.h"

class EPL_LIAB_UDF : public EPL_LIAB {

	friend class EPL_LIAB;

//constructor 
EPL_LIAB_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: EPL_LIAB(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
EPL_LIAB_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : EPL_LIAB(columnCount, mocd, persObj) {}


// Acquisition Expenses 
double epl_liab_acq_exp(int t);

// AG48 Net Premium Reserve Net 
double epl_liab_ag48_npr_net(int t);

// AG48 Unearned Premium Reserve NPR Net 
double epl_liab_ag48_unearn_prem_res_npr_net(int t);

// Annuity Benefits Beginning of Month 
double epl_liab_ann_benefits_bom(int t);

// Annuity Benefits End of Month 
double epl_liab_ann_benefits_eom(int t);

// Annuity PBA Reinsurance Reserve 
double epl_liab_ann_pba_reins_res(int t);

// Annuity PBA Working Reserve 
double epl_liab_ann_pba_working_res(int t);

// Annuitization Consideration 
double epl_liab_annuitzn_consideration(int t);

// Annuitization Value Released 
double epl_liab_annuitzn_val_released(int t);

// Cash Value 
double epl_liab_cash_val(int t);

// Claim Paid 
double epl_liab_claim_paid(int t);

// Commissions Beginning of Month 
double epl_liab_comm_bom(int t);

// Commission Chargeback 
double epl_liab_comm_chargeback(int t);

// Commissions End of Month 
double epl_liab_comm_eom(int t);

// Conversion Cost 
double epl_liab_conversion_cost(int t);

// Deferred Gross Premium 
double epl_liab_deferred_gross_prem(int t);

// Deferred Net Premium 
double epl_liab_deferred_net_prem(int t);

// Deferred Net Premium Net 
double epl_liab_deferred_net_prem_net(int t);

// Deferred Net Premium NPR 
double epl_liab_deferred_net_prem_npr(int t);

// Deferred Net Premium NPR Net 
double epl_liab_deferred_net_prem_npr_net(int t);

// Dividend Applied 
double epl_liab_div_applied(int t);

// Dividend Liability 
double epl_liab_div_liab(int t);

// Dividend Paid 
double epl_liab_div_paid(int t);

// Death Benefit In Force 
double epl_liab_dth_ben_inf(int t);

// Death Benefits 
double epl_liab_dth_benefits(int t);

// Endowment Benefits 
double epl_liab_endow_benefits(int t);

// Fund Value Fixed Account 
double epl_liab_fund_val_fixed(int t);

// Fund Value Separate Account 
double epl_liab_fund_val_sa(int t);

// Gross Premium Annualized 
double epl_liab_gross_prem_annualzd(int t);

// Hedge Cash Flows 
double epl_liab_hedge_cash_flow(int t);

// Market Value of Hedges 
double epl_liab_hedge_mkt_val(int t);

// Hedge Market Value Growth 
double epl_liab_hedge_mkt_val_growth(int t);

// Investment Fee Refund 
double epl_liab_inv_fee_ref(int t);

// Life PBA AG48 Net Premium Reserve Net 
double epl_liab_life_pba_ag48_npr_net(int t);

// Life PBA AG48 Unearned Premium Reserve NPR Net 
double epl_liab_life_pba_ag48_unearn_prem_res_npr_net(int t);

// Life PBA Asset Separate Account 
double epl_liab_life_pba_asset_sa(int t);

// Life PBA Direct Cash Flow Beginning of Month 
double epl_liab_life_pba_direct_cash_flow_bom(int t);

// Life PBA Direct Cash Flow End of Month 
double epl_liab_life_pba_direct_cash_flow_eom(int t);

// Life PBA Gross Premium Reserve Ceded 
double epl_liab_life_pba_gpr_ceded(int t);

// Life PBA Gross Premium Reserve Gross 
double epl_liab_life_pba_gpr_gross(int t);

// Life PBA Gross Premium Reserve Units in Force 
double epl_liab_life_pba_gpr_units_inf(int t);

// Life PBA Policy Loan 
double epl_liab_life_pba_pol_loan(int t);

// Life PBA Policy Loan Interest 
double epl_liab_life_pba_pol_loan_int(int t);

// Life PBA Reinsurance Cash Flow Beginning of Month 
double epl_liab_life_pba_reins_cash_flow_bom(int t);

// Life PBA Reinsurance Cash Flow End of Month 
double epl_liab_life_pba_reins_cash_flow_eom(int t);

// Life PBA Reinsurance Reserve 
double epl_liab_life_pba_reins_res(int t);

// Life PBA Reinsurance Reserve Separate Account 
double epl_liab_life_pba_reins_res_sa(int t);

// Life PBA Statutory Reserve Model Point 
double epl_liab_life_pba_stat_res_mp(int t);

// Life PBA Statutory Reserve Net Model Point 
double epl_liab_life_pba_stat_res_net_mp(int t);

// Life PBA Statutory Unearned Premium Reserve 
double epl_liab_life_pba_stat_unearn_prem_res(int t);

// Life PBA Statutory Unearned Premium Reserve Net 
double epl_liab_life_pba_stat_unearn_prem_res_net(int t);

// Life PBA Statutory Unearned Premium Reserve NPR Net 
double epl_liab_life_pba_stat_unearn_prem_res_npr_net(int t);

// Life PBA Working Reserve 
double epl_liab_life_pba_working_res(int t);

// Maintenance Expenses Beginning of Month 
double epl_liab_maint_exp_bom(int t);

// Maintenance Expenses End of Month 
double epl_liab_maint_exp_eom(int t);

// Maturity Benefits 
double epl_liab_maturity_benefits(int t);

// PBA Rollforward Base 
double epl_liab_pba_rollforward_base(int t);

// Policy Loan 
double epl_liab_pol_loan(int t);

// Policy Loan Expense 
double epl_liab_pol_loan_exp(int t);

// Policy Loan Interest 
double epl_liab_pol_loan_int(int t);

// Policy Loan Proceeds 
double epl_liab_pol_loan_proceeds(int t);

// Policies In Force Beginning of Month 
double epl_liab_policies_b(int t);

// Policies In Force 
double epl_liab_policies_inf(int t);

// Policies Issued 
double epl_liab_policies_issued(int t);

// Premium Issued 
double epl_liab_prem_issued(int t);

// Premiums Paid 
double epl_liab_prem_paid(int t);

// Premium Paid Net 
double epl_liab_prem_paid_net(int t);

// Premium Taxes 
double epl_liab_prem_tax(int t);

// Premium Waiver Benefits 
double epl_liab_prem_waiver_benefits(int t);

// RBC C1 Unearned Premium Reserve Deficiency 
double epl_liab_rbc_c1_unearn_prem_res_def(int t);

// RBC C2 Incurred Claim 
double epl_liab_rbc_c2_claim(int t);

// RBC C2 Incurred Claim Previous Year 
double epl_liab_rbc_c2_claim_prev_yr(int t);

// RBC C2 Earned Premium 
double epl_liab_rbc_c2_prem(int t);

// RBC C2 Earned Premium Previous Year 
double epl_liab_rbc_c2_prem_prev_yr(int t);

// RBC C3 Base Annuity High Risk 
double epl_liab_rbc_c3_base_ann_high_risk(int t);

// RBC C3 Base Annuity Low Risk 
double epl_liab_rbc_c3_base_ann_low_risk(int t);

// RBC C3 Base Annuity Medium Risk 
double epl_liab_rbc_c3_base_ann_medium_risk(int t);

// RBC C3 Base Life 
double epl_liab_rbc_c3_base_life(int t);

// RBC C3 Policy Amount 
double epl_liab_rbc_c3_mp(int t);

// RBC C4 
double epl_liab_rbc_c4(int t);

// Reinsurance Annuity Benefits BOM 
double epl_liab_reins_ann_benefits_bom(int t);

// Reinsurance Annuity Benefits EOM 
double epl_liab_reins_ann_benefits_eom(int t);

// Reinsurance Cash Value 
double epl_liab_reins_cash_val(int t);

// Reinsurance Claim Paid 
double epl_liab_reins_claim_paid(int t);

// Reinsurance Commission Chargeback Reimbursement 
double epl_liab_reins_comm_chargeback_reimb(int t);

// Reinsurance Commission Reimbursement Beginning of Month 
double epl_liab_reins_comm_reimb_bom(int t);

// Reinsurance Commission Reimbursement End of Month 
double epl_liab_reins_comm_reimb_eom(int t);

// Reinsurance Deferred Gross Premium 
double epl_liab_reins_deferred_gross_prem(int t);

// Reinsurance Deferred Net Premium 
double epl_liab_reins_deferred_net_prem(int t);

// Reinsurance Dividend Applied 
double epl_liab_reins_div_applied(int t);

// Reinsurance Dividend Liability 
double epl_liab_reins_div_liab(int t);

// Reinsurance Dividend Paid 
double epl_liab_reins_div_paid(int t);

// Reinsured Death Benefit In Force 
double epl_liab_reins_dth_ben_inf(int t);

// Reinsurance Death Benefits 
double epl_liab_reins_dth_benefits(int t);

// Reinsurance Expense Allowance 
double epl_liab_reins_ea(int t);

// Reinsurance Expense Allowance Chargeback 
double epl_liab_reins_ea_chargeback(int t);

// Reinsurance Endowment Benefits 
double epl_liab_reins_endow_benefits(int t);

// Reinsurance Expense 
double epl_liab_reins_exp(int t);

// Reinsurance Expense Reimbursed Beginning of Month 
double epl_liab_reins_exp_reimb_bom(int t);

// Reinsurance Expense Reimbursed End of Month 
double epl_liab_reins_exp_reimb_eom(int t);

// Reinsurance Investment Fee Refund 
double epl_liab_reins_inv_fee_ref(int t);

// Reinsurance Maturity Benefits 
double epl_liab_reins_maturity_benefits(int t);

// Modified Coinsurance Reserve Adjustment 
double epl_liab_reins_modco_res_adj(int t);

// Reinsurance Premium 
double epl_liab_reins_prem(int t);

// Reinsurance Premium Tax 
double epl_liab_reins_prem_tax(int t);

// Reinsurance Premium Waiver Benefits 
double epl_liab_reins_prem_waiver_benefits(int t);

// Reinsurance Refund 
double epl_liab_reins_ref(int t);

// Reinsurance Statutory Claim Reserve 
double epl_liab_reins_stat_claim_res(int t);

// Reinsurance Statutory Loading 
double epl_liab_reins_stat_loading(int t);

// Reinsurance Statutory Premium Waiver Reserve 
double epl_liab_reins_stat_prem_waiver_res(int t);

// Reinsurance Statutory Policy Reserve 
double epl_liab_reins_stat_res_mp(int t);

// Reinsurance Statutory Net Premium Reserve 
double epl_liab_reins_stat_res_npr(int t);

// Reinsurance Statutory Unearned Premium Reserve 
double epl_liab_reins_stat_unearn_prem_res(int t);

// Reinsurance Surrender Benefits 
double epl_liab_reins_surr_benefits(int t);

// Reinsurance Tax Claim Reserve 
double epl_liab_reins_tax_claim_res(int t);

// Reinsurance Tax Deferred Net Premium 
double epl_liab_reins_tax_deferred_net_prem(int t);

// Reinsurance Tax Loading 
double epl_liab_reins_tax_loading(int t);

// Reinsurance Tax Premium Waiver Reserve 
double epl_liab_reins_tax_prem_waiver_res(int t);

// Reinsurance Tax Policy Reserve 
double epl_liab_reins_tax_res_mp(int t);

// Reinsurance Tax Unearned Premium Reserve 
double epl_liab_reins_tax_unearn_prem_res(int t);

// Reinsurance Terminal Dividends 
double epl_liab_reins_terminal_div(int t);

// Reinsurance Withdrawal Benefits 
double epl_liab_reins_withdrl_benefits(int t);

// SFAS120 Ceded Acquisition Expenses 
double epl_liab_sfas120_ceded_acq_exp(int t);

// SFAS120 Ceded Benefits 
double epl_liab_sfas120_ceded_benefits(int t);

// SFAS120 Ceded Capitalized Acquisition Expenses 
double epl_liab_sfas120_ceded_capzd_acq_exp(int t);

// SFAS120 Ceded Capitalized Commissions Beginning of Month 
double epl_liab_sfas120_ceded_capzd_comm_bom(int t);

// SFAS120 Ceded Capitalized Commissions Chargeback 
double epl_liab_sfas120_ceded_capzd_comm_chargeback(int t);

// SFAS120 Ceded Capitalized Commissions End of Month 
double epl_liab_sfas120_ceded_capzd_comm_eom(int t);

// SFAS120 Ceded Cash Flow Beginning of Month 
double epl_liab_sfas120_ceded_cash_flow_bom(int t);

// SFAS120 Ceded Commission Chargeback 
double epl_liab_sfas120_ceded_comm_chargeback(int t);

// SFAS120 Ceded Commissions Excess BOM 
double epl_liab_sfas120_ceded_comm_excess_bom(int t);

// SFAS120 Ceded Commissions Excess EOM 
double epl_liab_sfas120_ceded_comm_excess_eom(int t);

// SFAS120 Ceded Commissions Trail BOM 
double epl_liab_sfas120_ceded_comm_trail_bom(int t);

// SFAS120 Ceded Commissions Trail BOM Base Plan 
double epl_liab_sfas120_ceded_comm_trail_bom_base_plan(int t);

// SFAS120 Ceded Commissions Trail BOM Rider 
double epl_liab_sfas120_ceded_comm_trail_bom_rider(int t);

// SFAS120 Ceded Commissions Trail EOM 
double epl_liab_sfas120_ceded_comm_trail_eom(int t);

// SFAS120 Ceded Conversion Cost 
double epl_liab_sfas120_ceded_conversion_cost(int t);

// SFAS120 Ceded Dividends Applied 
double epl_liab_sfas120_ceded_div_applied(int t);

// SFAS120 Ceded Dividend Liability 
double epl_liab_sfas120_ceded_div_liab(int t);

// SFAS120 Ceded Dividend Option Reserve 
double epl_liab_sfas120_ceded_div_opt_res(int t);

// SFAS120 Ceded Annual Dividends Paid 
double epl_liab_sfas120_ceded_div_paid(int t);

// SFAS120 Ceded Death Claim Cost 
double epl_liab_sfas120_ceded_dth_claim_cost(int t);

// SFAS120 Ceded EGM Acquisition Expense 
double epl_liab_sfas120_ceded_egm_acq_exp(int t);

// SFAS120 Ceded EGM Commissions 
double epl_liab_sfas120_ceded_egm_comm(int t);

// SFAS120 Ceded EGM Dividend Applied 
double epl_liab_sfas120_ceded_egm_div_applied(int t);

// SFAS120 Ceded EGM Dividends Paid 
double epl_liab_sfas120_ceded_egm_div_paid(int t);

// SFAS120 Ceded EGM Death Benefits 
double epl_liab_sfas120_ceded_egm_dth_benefits(int t);

// SFAS120 Ceded EGM Endowment Benefits 
double epl_liab_sfas120_ceded_egm_endow_benefits(int t);

// SFAS120 Ceded EGM Maintenance Expense 
double epl_liab_sfas120_ceded_egm_maint_exp(int t);

// SFAS120 Ceded EGM Maturity Benefits 
double epl_liab_sfas120_ceded_egm_maturity_benefits(int t);

// SFAS120 Ceded EGM Premium Paid 
double epl_liab_sfas120_ceded_egm_prem_paid(int t);

// SFAS120 Ceded EGM Premium Tax 
double epl_liab_sfas120_ceded_egm_prem_tax(int t);

// SFAS120 Ceded EGM Surrender Benefits 
double epl_liab_sfas120_ceded_egm_surr_benefits(int t);

// SFAS120 Ceded Endowment Claim Cost 
double epl_liab_sfas120_ceded_endow_claim_cost(int t);

// SFAS120 Ceded Gross Premium Reserve 
double epl_liab_sfas120_ceded_gpr(int t);

// SFAS120 Ceded Gross Premium Reserve Units in Force 
double epl_liab_sfas120_ceded_gpr_units_inf(int t);

// SFAS120 Ceded Gross Premium 
double epl_liab_sfas120_ceded_gross_prem(int t);

// SFAS120 Ceded Letter of Credit Cost 
double epl_liab_sfas120_ceded_loc_cost(int t);

// SFAS120 Ceded Maintenance Expenses Beginning of Month 
double epl_liab_sfas120_ceded_maint_exp_bom(int t);

// SFAS120 Ceded Maintenance Expenses End of Month 
double epl_liab_sfas120_ceded_maint_exp_eom(int t);

// SFAS120 Ceded Maturity Claim Cost 
double epl_liab_sfas120_ceded_maturity_claim_cost(int t);

// SFAS120 Ceded Modco Liability 
double epl_liab_sfas120_ceded_modco_liab(int t);

// SFAS120 Ceded Modified Coinsurance Reserve Adjustment 
double epl_liab_sfas120_ceded_modco_res_adj(int t);

// SFAS120 Ceded Net Level Premium Reserve Net Premium 
double epl_liab_sfas120_ceded_nlp_res_net_prem2(int t);

// SFAS120 Ceded Net Level Premium Reserve Preliminary 
double epl_liab_sfas120_ceded_nlp_res_prelim(int t);

// SFAS120 Ceded Premium Tax 
double epl_liab_sfas120_ceded_prem_tax(int t);

// SFAS120 Ceded Reinsurance Refund 
double epl_liab_sfas120_ceded_refund(int t);

// SFAS120 Ceded Reinsurance EA Excess 
double epl_liab_sfas120_ceded_reins_ea_excess(int t);

// SFAS120 Ceded Reinsurance EA Trail 
double epl_liab_sfas120_ceded_reins_ea_trail(int t);

// SFAS120 Ceded Surrender Claim Cost 
double epl_liab_sfas120_ceded_surr_claim_cost(int t);

// SFAS120 Ceded Terminal Dividends 
double epl_liab_sfas120_ceded_terminal_div(int t);

// SFAS120 Gross Acquisition Expenses 
double epl_liab_sfas120_gross_acq_exp(int t);

// SFAS120 Gross Benefits 
double epl_liab_sfas120_gross_benefits(int t);

// SFAS120 Gross Capitalized Acquisition Expenses 
double epl_liab_sfas120_gross_capzd_acq_exp(int t);

// SFAS120 Gross Capitalized Commissions Beginning of Month 
double epl_liab_sfas120_gross_capzd_comm_bom(int t);

// SFAS120 Gross Capitalized Commissions Chargeback 
double epl_liab_sfas120_gross_capzd_comm_chargeback(int t);

// SFAS120 Gross Capitalized Commissions End of Month 
double epl_liab_sfas120_gross_capzd_comm_eom(int t);

// SFAS120 Gross Capitalized YRT Reinsurance Cost 
double epl_liab_sfas120_gross_capzd_reins_yrt_cost(int t);

// SFAS120 Gross Cash Flow Beginning of Month 
double epl_liab_sfas120_gross_cash_flow_bom(int t);

// SFAS120 Gross Commission Chargeback 
double epl_liab_sfas120_gross_comm_chargeback(int t);

// SFAS120 Gross Commissions Excess BOM 
double epl_liab_sfas120_gross_comm_excess_bom(int t);

// SFAS120 Gross Commissions Excess EOM 
double epl_liab_sfas120_gross_comm_excess_eom(int t);

// SFAS120 Gross Commissions Trail BOM 
double epl_liab_sfas120_gross_comm_trail_bom(int t);

// SFAS120 Gross Commissions Trail BOM Base Plan 
double epl_liab_sfas120_gross_comm_trail_bom_base_plan(int t);

// SFAS120 Gross Commissions Trail BOM Rider 
double epl_liab_sfas120_gross_comm_trail_bom_rider(int t);

// SFAS120 Gross Commissions Trail EOM 
double epl_liab_sfas120_gross_comm_trail_eom(int t);

// SFAS120 Gross Conversion Cost 
double epl_liab_sfas120_gross_conversion_cost(int t);

// SFAS120 Gross Dividends Applied 
double epl_liab_sfas120_gross_div_applied(int t);

// SFAS120 Gross Dividend Liability 
double epl_liab_sfas120_gross_div_liab(int t);

// SFAS120 Gross Dividend Option Reserve 
double epl_liab_sfas120_gross_div_opt_res(int t);

// SFAS120 Gross Annual Dividends Paid 
double epl_liab_sfas120_gross_div_paid(int t);

// SFAS120 Gross Death Claim Cost 
double epl_liab_sfas120_gross_dth_claim_cost(int t);

// SFAS120 Gross EGM Acquisition Expense 
double epl_liab_sfas120_gross_egm_acq_exp(int t);

// SFAS120 Gross EGM Commissions 
double epl_liab_sfas120_gross_egm_comm(int t);

// SFAS120 Gross EGM Dividend Applied 
double epl_liab_sfas120_gross_egm_div_applied(int t);

// SFAS120 Gross EGM Dividends Paid 
double epl_liab_sfas120_gross_egm_div_paid(int t);

// SFAS120 Gross EGM Death Benefits 
double epl_liab_sfas120_gross_egm_dth_benefits(int t);

// SFAS120 Gross EGM Endowment Benefits 
double epl_liab_sfas120_gross_egm_endow_benefits(int t);

// SFAS120 Gross EGM Maintenance Expense 
double epl_liab_sfas120_gross_egm_maint_exp(int t);

// SFAS120 Gross EGM Maturity Benefits 
double epl_liab_sfas120_gross_egm_maturity_benefits(int t);

// SFAS120 Gross EGM Premium Paid 
double epl_liab_sfas120_gross_egm_prem_paid(int t);

// SFAS120 Gross EGM Premium Tax 
double epl_liab_sfas120_gross_egm_prem_tax(int t);

// SFAS120 Gross EGM Reinsurance Cost 
double epl_liab_sfas120_gross_egm_reins_cost(int t);

// SFAS120 Gross EGM Surrender Benefits 
double epl_liab_sfas120_gross_egm_surr_benefits(int t);

// SFAS120 Gross Endowment Claim Cost 
double epl_liab_sfas120_gross_endow_claim_cost(int t);

// SFAS120 Gross Gross Premium Reserve 
double epl_liab_sfas120_gross_gpr(int t);

// SFAS120 Gross Gross Premium Reserve Units in Force 
double epl_liab_sfas120_gross_gpr_units_inf(int t);

// SFAS120 Gross Gross Premium 
double epl_liab_sfas120_gross_gross_prem(int t);

// SFAS120 Gross Letter of Credit Cost 
double epl_liab_sfas120_gross_loc_cost(int t);

// SFAS120 Gross Maintenance Expenses Beginning of Month 
double epl_liab_sfas120_gross_maint_exp_bom(int t);

// SFAS120 Gross Maintenance Expenses End of Month 
double epl_liab_sfas120_gross_maint_exp_eom(int t);

// SFAS120 Gross Maturity Claim Cost 
double epl_liab_sfas120_gross_maturity_claim_cost(int t);

// SFAS120 Gross Net Level Premium Reserve Net Premium 
double epl_liab_sfas120_gross_nlp_res_net_prem(int t);

// SFAS120 Gross Net Level Premium Reserve Preliminary 
double epl_liab_sfas120_gross_nlp_res_prelim(int t);

// SFAS120 Gross Policy Loan 
double epl_liab_sfas120_gross_pol_loan(int t);

// SFAS120 Gross Policy Loan Income 
double epl_liab_sfas120_gross_pol_loan_inc(int t);

// SFAS120 Gross Premium Tax 
double epl_liab_sfas120_gross_prem_tax(int t);

// SFAS120 Gross YRT Reinsurance Cost 
double epl_liab_sfas120_gross_reins_yrt_cost(int t);

// SFAS120 Statutory Reserve for Riders 
double epl_liab_sfas120_gross_stat_res_rider(int t);

// SFAS120 Gross Surrender Claim Cost 
double epl_liab_sfas120_gross_surr_claim_cost(int t);

// SFAS120 GrossTerminal Dividends 
double epl_liab_sfas120_gross_terminal_div(int t);

// SFAS60 Ceded Acquisition Expenses 
double epl_liab_sfas60_ceded_acq_exp(int t);

// SFAS60 Ceded Benefit Reserve Accrual Valuation Basis 
double epl_liab_sfas60_ceded_ben_res_accrual_valn_basis(int t);

// SFAS60 Ceded Benefit Reserve Interest Valuation Basis 
double epl_liab_sfas60_ceded_ben_res_int_valn_basis(int t);

// SFAS60 Ceded Benefit Reserve Preliminary 
double epl_liab_sfas60_ceded_ben_res_prelim(int t);

// SFAS60 Ceded Benefits Valuation Basis 
double epl_liab_sfas60_ceded_benefits_valn_basis(int t);

// SFAS60 Ceded Capitalized Acquisition Expenses 
double epl_liab_sfas60_ceded_capzd_acq_exp(int t);

// SFAS60 Ceded Capitalized Acquisition Expenses Valuation Basis 
double epl_liab_sfas60_ceded_capzd_acq_exp_valn_basis(int t);

// SFAS60 Ceded Capitalized Commission BOM 
double epl_liab_sfas60_ceded_capzd_comm_bom(int t);

// SFAS60 Ceded Capitalized Commission Chargeback 
double epl_liab_sfas60_ceded_capzd_comm_chargeback(int t);

// SFAS60 Ceded Capitalized Commission EOM 
double epl_liab_sfas60_ceded_capzd_comm_eom(int t);

// SFAS60 Ceded Capitalized Commission Valuation Basis 
double epl_liab_sfas60_ceded_capzd_comm_valn_basis(int t);

// SFAS60 Ceded Cash Flow BOM 
double epl_liab_sfas60_ceded_cash_flow_bom(int t);

// SFAS60 Ceded Claim Reserve 
double epl_liab_sfas60_ceded_claim_res(int t);

// SFAS60 Ceded Commission Chargeback 
double epl_liab_sfas60_ceded_comm_chargeback(int t);

// SFAS60 Ceded Commissions Excess BOM 
double epl_liab_sfas60_ceded_comm_excess_bom(int t);

// SFAS60 Ceded Commissions Excess EOM 
double epl_liab_sfas60_ceded_comm_excess_eom(int t);

// SFAS60 Ceded Commissions Trail BOM 
double epl_liab_sfas60_ceded_comm_trail_bom(int t);

// SFAS60 Ceded Commissions Trail BOM Base Plan 
double epl_liab_sfas60_ceded_comm_trail_bom_base_plan(int t);

// SFAS60 Ceded Commissions Trail BOM Rider 
double epl_liab_sfas60_ceded_comm_trail_bom_rider(int t);

// SFAS60 Ceded Commissions Trail EOM 
double epl_liab_sfas60_ceded_comm_trail_eom(int t);

// SFAS60 Ceded Conversion Cost 
double epl_liab_sfas60_ceded_conversion_cost(int t);

// SFAS60 Ceded DAC Amortization Valuation Basis 
double epl_liab_sfas60_ceded_dac_amortzn_valn_basis(int t);

// SFAS60 Ceded DAC Interest Valuation Basis 
double epl_liab_sfas60_ceded_dac_int_valn_basis(int t);

// SFAS60 Ceded DAC Preliminary 
double epl_liab_sfas60_ceded_dac_prelim(int t);

// SFAS60 Ceded Dividends Applied 
double epl_liab_sfas60_ceded_div_applied(int t);

// SFAS60 Ceded Annual Dividends Paid 
double epl_liab_sfas60_ceded_div_paid(int t);

// SFAS60 Ceded Annual Dividends Valuation Basis 
double epl_liab_sfas60_ceded_div_valn_basis(int t);

// SFAS60 Ceded Death Claim Cost 
double epl_liab_sfas60_ceded_dth_claim_cost(int t);

// SFAS60 Ceded Endowment Claim Cost 
double epl_liab_sfas60_ceded_endow_claim_cost(int t);

// SFAS60 Ceded Expenses Valuation Basis 
double epl_liab_sfas60_ceded_exp_valn_basis(int t);

// SFAS60 Ceded Gross Premium Reserve 
double epl_liab_sfas60_ceded_gpr(int t);

// SFAS60 Ceded Gross Premium Reserve Units in Force 
double epl_liab_sfas60_ceded_gpr_units_inf(int t);

// SFAS60 Ceded Gross Premium 
double epl_liab_sfas60_ceded_gross_prem(int t);

// SFAS60 Ceded Health Claim Cost 
double epl_liab_sfas60_ceded_hlth_claim_cost(int t);

// SFAS60 Ceded Letter of Credit Cost 
double epl_liab_sfas60_ceded_loc_cost(int t);

// SFAS60 Ceded Maintenance Expenses Beginning of Month 
double epl_liab_sfas60_ceded_maint_exp_bom(int t);

// SFAS60 Ceded Maintenance Expenses End of Month 
double epl_liab_sfas60_ceded_maint_exp_eom(int t);

// SFAS60 Ceded Maintenance Expense Reserve Accrual Valuation Basis 
double epl_liab_sfas60_ceded_maint_exp_res_accrual_valn_basis(int t);

// SFAS60 Ceded Maintenance Expense Reserve Interest Valuation Basis 
double epl_liab_sfas60_ceded_maint_exp_res_int_valn_basis(int t);

// SFAS60 Ceded Maintenance Expense Reserve Preliminary 
double epl_liab_sfas60_ceded_maint_exp_res_prelim(int t);

// SFAS60 Ceded Maturity Claim Cost 
double epl_liab_sfas60_ceded_maturity_claim_cost(int t);

// SFAS60 Ceded Modco Liability 
double epl_liab_sfas60_ceded_modco_liab(int t);

// SFAS60 Ceded Modified Coinsurance Reserve Adjustment 
double epl_liab_sfas60_ceded_modco_res_adj(int t);

// SFAS60 Ceded Premium Tax 
double epl_liab_sfas60_ceded_prem_tax(int t);

// SFAS60 Ceded Premium Waiver Reserve 
double epl_liab_sfas60_ceded_prem_waiver_res(int t);

// SFAS60 Ceded Reinsurance Refund 
double epl_liab_sfas60_ceded_refund(int t);

// SFAS60 Ceded Surrender Benefits Valuation Basis 
double epl_liab_sfas60_ceded_surr_ben_valn_basis(int t);

// SFAS60 Ceded Surrender Claim Cost 
double epl_liab_sfas60_ceded_surr_claim_cost(int t);

// SFAS60 Ceded Terminal Dividends 
double epl_liab_sfas60_ceded_terminal_div(int t);

// SFAS60 Gross Acquisition Expenses 
double epl_liab_sfas60_gross_acq_exp(int t);

// SFAS60 Gross Benefit Reserve Accrual Valuation Basis 
double epl_liab_sfas60_gross_ben_res_accrual_valn_basis(int t);

// SFAS60 Gross Benefit Reserve Interest Valuation Basis 
double epl_liab_sfas60_gross_ben_res_int_valn_basis(int t);

// SFAS60 Gross Benefit Reserve Preliminary 
double epl_liab_sfas60_gross_ben_res_prelim(int t);

// SFAS60 Gross Benefits Valuation Basis 
double epl_liab_sfas60_gross_benefits_valn_basis(int t);

// SFAS60 Gross Capitalized Acquisition Expenses 
double epl_liab_sfas60_gross_capzd_acq_exp(int t);

// SFAS60 Gross Capitalized Acquisition Expenses Valuation Basis 
double epl_liab_sfas60_gross_capzd_acq_exp_valn_basis(int t);

// SFAS60 Gross Capitalized Commission BOM 
double epl_liab_sfas60_gross_capzd_comm_bom(int t);

// SFAS60 Gross Capitalized Commission Chargeback 
double epl_liab_sfas60_gross_capzd_comm_chargeback(int t);

// SFAS60 Gross Capitalized Commission EOM 
double epl_liab_sfas60_gross_capzd_comm_eom(int t);

// SFAS60 Gross Capitalized Commission Valuation Basis 
double epl_liab_sfas60_gross_capzd_comm_valn_basis(int t);

// SFAS60 Gross Capitalized YRT Reinsurance Cost 
double epl_liab_sfas60_gross_capzd_reins_yrt_cost(int t);

// SFAS60 Gross Cash Flow BOM 
double epl_liab_sfas60_gross_cash_flow_bom(int t);

// SFAS60 Gross Claim Reserve 
double epl_liab_sfas60_gross_claim_res(int t);

// SFAS60 Gross Commission Chargeback 
double epl_liab_sfas60_gross_comm_chargeback(int t);

// SFAS60 Gross Commissions Excess BOM 
double epl_liab_sfas60_gross_comm_excess_bom(int t);

// SFAS60 Gross Commissions Excess EOM 
double epl_liab_sfas60_gross_comm_excess_eom(int t);

// SFAS60 Gross Commissions Trail BOM 
double epl_liab_sfas60_gross_comm_trail_bom(int t);

// SFAS60 Gross Commissions Trail BOM Base Plan 
double epl_liab_sfas60_gross_comm_trail_bom_base_plan(int t);

// SFAS60 Gross Commissions Trail BOM Rider 
double epl_liab_sfas60_gross_comm_trail_bom_rider(int t);

// SFAS60 Gross Commissions Trail EOM 
double epl_liab_sfas60_gross_comm_trail_eom(int t);

// SFAS60 Gross Conversion Cost 
double epl_liab_sfas60_gross_conversion_cost(int t);

// SFAS60 Gross DAC Amortization Valuation Basis 
double epl_liab_sfas60_gross_dac_amortzn_valn_basis(int t);

// SFAS60 Gross DAC Interest Valuation Basis 
double epl_liab_sfas60_gross_dac_int_valn_basis(int t);

// SFAS60 Gross DAC Preliminary 
double epl_liab_sfas60_gross_dac_prelim(int t);

// SFAS60 Gross Reinsurance YRT Asset Amortization Valuation Basis 
double epl_liab_sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis(int t);

// SFAS60 Gross Reinsurance YRT Asset Interest Valuation Basis 
double epl_liab_sfas60_gross_dac_reins_yrt_asset_int_valn_basis(int t);

// SFAS60 Gross DAC Reinsurance YRT Asset Preliminary 
double epl_liab_sfas60_gross_dac_reins_yrt_asset_prelim(int t);

// SFAS60 Gross Dividends Applied 
double epl_liab_sfas60_gross_div_applied(int t);

// SFAS60 Gross Annual Dividends Paid 
double epl_liab_sfas60_gross_div_paid(int t);

// SFAS60 Gross Annual Dividends Valuation Basis 
double epl_liab_sfas60_gross_div_valn_basis(int t);

// SFAS60 Gross Death Claim Cost 
double epl_liab_sfas60_gross_dth_claim_cost(int t);

// SFAS60 Gross Endowment Claim Cost 
double epl_liab_sfas60_gross_endow_claim_cost(int t);

// SFAS60 Gross Expenses Valuation Basis 
double epl_liab_sfas60_gross_exp_valn_basis(int t);

// SFAS60 Gross Gross Premium Reserve 
double epl_liab_sfas60_gross_gpr(int t);

// SFAS60 Gross Gross Premium Reserve Units in Force 
double epl_liab_sfas60_gross_gpr_units_inf(int t);

// SFAS60 Gross Gross Premium 
double epl_liab_sfas60_gross_gross_prem(int t);

// SFAS60 Gross Health Claim Cost 
double epl_liab_sfas60_gross_hlth_claim_cost(int t);

// SFAS60 Gross Letter of Credit Cost 
double epl_liab_sfas60_gross_loc_cost(int t);

// SFAS60 Gross Maintenance Expenses Beginning of Month 
double epl_liab_sfas60_gross_maint_exp_bom(int t);

// SFAS60 Gross Maintenance Expenses End of Month 
double epl_liab_sfas60_gross_maint_exp_eom(int t);

// SFAS60 Gross Maintenance Expense Reserve Accrual Valuation Basis 
double epl_liab_sfas60_gross_maint_exp_res_accrual_valn_basis(int t);

// SFAS60 Gross Maintenance Expense Reserve Interest Valuation Basis 
double epl_liab_sfas60_gross_maint_exp_res_int_valn_basis(int t);

// SFAS60 Gross Maintenance Reserve Preliminary 
double epl_liab_sfas60_gross_maint_exp_res_prelim(int t);

// SFAS60 Gross Maturity Claim Cost 
double epl_liab_sfas60_gross_maturity_claim_cost(int t);

// SFAS60 Gross Policy Loan 
double epl_liab_sfas60_gross_pol_loan(int t);

// SFAS60 Gross Policy Loan Income 
double epl_liab_sfas60_gross_pol_loan_inc(int t);

// SFAS60 Gross Premium Tax 
double epl_liab_sfas60_gross_prem_tax(int t);

// SFAS60 Gross Premium Waiver Reserve 
double epl_liab_sfas60_gross_prem_waiver_res(int t);

// SFAS60 Gross YRT Reinsurance Cost 
double epl_liab_sfas60_gross_reins_yrt_cost(int t);

// SFAS60 Gross Reinsurance YRT Cost Valuation Basis 
double epl_liab_sfas60_gross_reins_yrt_cost_valn_basis(int t);

// SFAS60 Statutory Reserve for Riders 
double epl_liab_sfas60_gross_stat_res_rider(int t);

// SFAS60 Gross Surrender Benefits Valuation Basis 
double epl_liab_sfas60_gross_surr_ben_valn_basis(int t);

// SFAS60 Gross Surrender Claim Cost 
double epl_liab_sfas60_gross_surr_claim_cost(int t);

// SFAS60 GrossTerminal Dividends 
double epl_liab_sfas60_gross_terminal_div(int t);

// SFAS91 Ceded Acquisition Expenses 
double epl_liab_sfas91_ceded_acq_exp(int t);

// SFAS91 Ceded Annuity Benefits Beginning of Month 
double epl_liab_sfas91_ceded_ann_benefits_bom(int t);

// SFAS91 Ceded Annuity Benefits End of Month 
double epl_liab_sfas91_ceded_ann_benefits_eom(int t);

// SFAS91 Ceded Benefit and Maintenance Expense Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_bom(int t);

// SFAS91 Ceded Benefit and Maintenance Expense Reserve Cash Flow End of Month 
double epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_eom(int t);

// SFAS91 Ceded Benefit Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_ceded_ben_res_cash_flow_bom(int t);

// SFAS91 Ceded Benefit Reserve Cash Flow End of Month 
double epl_liab_sfas91_ceded_ben_res_cash_flow_eom(int t);

// SFAS91 Ceded Capitalized Acquisition Expenses 
double epl_liab_sfas91_ceded_capzd_acq_exp(int t);

// SFAS91 Ceded Capitalized Commissions Beginning of Month 
double epl_liab_sfas91_ceded_capzd_comm_bom(int t);

// SFAS91 Ceded Cash Flow Beginning of Month 
double epl_liab_sfas91_ceded_cash_flow_bom(int t);

// SFAS91 Ceded Commission Excess Beginning of Month 
double epl_liab_sfas91_ceded_comm_excess_bom(int t);

// SFAS91 Ceded Deferred Maintenance Expenses 
double epl_liab_sfas91_ceded_deferred_maint_exp(int t);

// SFAS91 Ceded Death Benefits 
double epl_liab_sfas91_ceded_dth_benefits(int t);

// SFAS91 Ceded Maintenance Expenses Beginning of Month 
double epl_liab_sfas91_ceded_maint_exp_bom(int t);

// SFAS91 Ceded Maintenance Expenses End of Month 
double epl_liab_sfas91_ceded_maint_exp_eom(int t);

// SFAS91 Ceded Maintenance Expense Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_ceded_maint_exp_res_cash_flow_bom(int t);

// SFAS91 Ceded Maintenance Expense Reserve Cash Flow End of Month 
double epl_liab_sfas91_ceded_maint_exp_res_cash_flow_eom(int t);

// SFAS91 Ceded Net Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_ceded_net_res_cash_flow_bom(int t);

// SFAS91 Ceded Net Reserve Cash Flow End of Month 
double epl_liab_sfas91_ceded_net_res_cash_flow_eom(int t);

// SFAS91 Ceded Non-Capitalized Acquisition Expenses 
double epl_liab_sfas91_ceded_noncapzd_acq_exp(int t);

// SFAS91 Ceded Policies In Force Beginning of Month 
double epl_liab_sfas91_ceded_policies_b(int t);

// SFAS91 Ceded Premium Paid 
double epl_liab_sfas91_ceded_prem_paid(int t);

// SFAS91 Ceded Premium Tax 
double epl_liab_sfas91_ceded_prem_tax(int t);

// SFAS91 Ceded Annuity Benefits for Reserves 
double epl_liab_sfas91_ceded_res_ann_benefits(int t);

// SFAS91 Ceded Death Benefits for Reserves 
double epl_liab_sfas91_ceded_res_dth_benefits(int t);

// SFAS91 Gross Acquisition Expenses 
double epl_liab_sfas91_gross_acq_exp(int t);

// SFAS91 Gross Annuity Benefits Beginning of Month 
double epl_liab_sfas91_gross_ann_benefits_bom(int t);

// SFAS91 Gross Annuity Benefits End of Month 
double epl_liab_sfas91_gross_ann_benefits_eom(int t);

// SFAS91 Gross Benefit and Maintenance Expense Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_bom(int t);

// SFAS91 Gross Benefit and Maintenance Expense Reserve Cash Flow End of Month 
double epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_eom(int t);

// SFAS91 Gross Benefit Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_gross_ben_res_cash_flow_bom(int t);

// SFAS91 Gross Benefit Reserve Cash Flow End of Month 
double epl_liab_sfas91_gross_ben_res_cash_flow_eom(int t);

// SFAS91 Gross Capitalized Acquisition Expenses 
double epl_liab_sfas91_gross_capzd_acq_exp(int t);

// SFAS91 Gross Capitalized Commissions Beginning of Month 
double epl_liab_sfas91_gross_capzd_comm_bom(int t);

// SFAS91 Gross Cash Flow Beginning of Month 
double epl_liab_sfas91_gross_cash_flow_bom(int t);

// SFAS91 Gross Commission Excess Beginning of Month 
double epl_liab_sfas91_gross_comm_excess_bom(int t);

// SFAS91 Gross Deferred Maintenance Expenses 
double epl_liab_sfas91_gross_deferred_maint_exp(int t);

// SFAS91 Gross Death Benefits 
double epl_liab_sfas91_gross_dth_benefits(int t);

// SFAS91 Gross Maintenance Expenses Beginning of Month 
double epl_liab_sfas91_gross_maint_exp_bom(int t);

// SFAS91 Gross Maintenance Expenses End of Month 
double epl_liab_sfas91_gross_maint_exp_eom(int t);

// SFAS91 Gross Maintenance Expense Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_gross_maint_exp_res_cash_flow_bom(int t);

// SFAS91 Gross Maintenance Expense Reserve Cash Flow End of Month 
double epl_liab_sfas91_gross_maint_exp_res_cash_flow_eom(int t);

// SFAS91 Gross Net Reserve Cash Flow Beginning of Month 
double epl_liab_sfas91_gross_net_res_cash_flow_bom(int t);

// SFAS91 Gross Net Reserve Cash Flow End of Month 
double epl_liab_sfas91_gross_net_res_cash_flow_eom(int t);

// SFAS91 Gross Non-Capitalized Acquisition Expenses 
double epl_liab_sfas91_gross_noncapzd_acq_exp(int t);

// SFAS91 Gross Policies In Force Beginning of Month 
double epl_liab_sfas91_gross_policies_b(int t);

// SFAS91 Gross Premium Paid 
double epl_liab_sfas91_gross_prem_paid(int t);

// SFAS91 Gross Premium Tax 
double epl_liab_sfas91_gross_prem_tax(int t);

// SFAS91 Gross Annuity Benefits for Reserves 
double epl_liab_sfas91_gross_res_ann_benefits(int t);

// SFAS91 Gross Death Benefits for Reserves 
double epl_liab_sfas91_gross_res_dth_benefits(int t);

// SFAS97 Limited Pay Ceded Acquisition Expenses 
double epl_liab_sfas97lp_ceded_acq_exp(int t);

// SFAS97 Limited Pay Ceded Annuity Claim Cost 
double epl_liab_sfas97lp_ceded_ann_claim_cost(int t);

// SFAS97LP Ceded Benefit Reserve Accrual Valuation Basis 
double epl_liab_sfas97lp_ceded_ben_res_accrual_valn_basis(int t);

// SFAS97LP Ceded Benefit Reserve Interest Valuation Basis 
double epl_liab_sfas97lp_ceded_ben_res_int_valn_basis(int t);

// SFAS97 Limited Pay Ceded Benefit Reserve Preliminary 
double epl_liab_sfas97lp_ceded_ben_res_prelim(int t);

// SFAS97LP Ceded Benefits Valuation Basis 
double epl_liab_sfas97lp_ceded_benefits_valn_basis(int t);

// SFAS97 Limited Pay Ceded Capitalized Acquisition Expenses 
double epl_liab_sfas97lp_ceded_capzd_acq_exp(int t);

// SFAS97 Limited Pay Ceded Capitalized Acquisition Expenses Valuation Basis 
double epl_liab_sfas97lp_ceded_capzd_acq_exp_valn_basis(int t);

// SFAS97 Limited Pay Ceded Capitalized Commissions BOM 
double epl_liab_sfas97lp_ceded_capzd_comm_bom(int t);

// SFAS97 Limited Pay Ceded Capitalized Commission Chargeback 
double epl_liab_sfas97lp_ceded_capzd_comm_chargeback(int t);

// SFAS97 Limited Pay Ceded Capitalized Commission EOM 
double epl_liab_sfas97lp_ceded_capzd_comm_eom(int t);

// SFAS97LP Ceded Capitalized Commission Valuation Basis 
double epl_liab_sfas97lp_ceded_capzd_comm_valn_basis(int t);

// SFAS97 Limited Pay Ceded Cash Flow BOM 
double epl_liab_sfas97lp_ceded_cash_flow_bom(int t);

// SFAS97 Limited Pay Ceded Claim Reserve 
double epl_liab_sfas97lp_ceded_claim_res(int t);

// SFAS97 Limited Pay Ceded Commission Chargeback 
double epl_liab_sfas97lp_ceded_comm_chargeback(int t);

// SFAS97 Limited Pay Ceded Commissions Excess BOM 
double epl_liab_sfas97lp_ceded_comm_excess_bom(int t);

// SFAS97 Limited Pay Ceded Commissions Excess EOM 
double epl_liab_sfas97lp_ceded_comm_excess_eom(int t);

// SFAS97 Limited Pay Ceded Commissions Trail BOM 
double epl_liab_sfas97lp_ceded_comm_trail_bom(int t);

// SFAS97 Limited Pay Ceded Commissions Trail BOM Base Plan 
double epl_liab_sfas97lp_ceded_comm_trail_bom_base_plan(int t);

// SFAS97 Limited Pay Ceded Commissions Trail BOM Rider 
double epl_liab_sfas97lp_ceded_comm_trail_bom_rider(int t);

// SFAS97 Limited Pay Ceded Commissions Trail EOM 
double epl_liab_sfas97lp_ceded_comm_trail_eom(int t);

// SFAS97 Limited Pay Ceded Conversion Cost 
double epl_liab_sfas97lp_ceded_conversion_cost(int t);

// SFAS97LP Ceded DAC Amortization Valuation Basis 
double epl_liab_sfas97lp_ceded_dac_amortzn_valn_basis(int t);

// SFAS97LP Ceded DAC Interest Valuation Basis 
double epl_liab_sfas97lp_ceded_dac_int_valn_basis(int t);

// SFAS97 Limited Pay Ceded DAC Preliminary 
double epl_liab_sfas97lp_ceded_dac_prelim(int t);

// SFAS97LP Ceded Deferred Profit Amortization Valuation Basis 
double epl_liab_sfas97lp_ceded_deferred_prof_amortzn_valn_basis(int t);

// SFAS97LP Ceded Deferred Profit Interest Valuation Basis 
double epl_liab_sfas97lp_ceded_deferred_prof_int_valn_basis(int t);

// SFAS97 Limited Pay Ceded Deferred Profit Liability Preliminary 
double epl_liab_sfas97lp_ceded_deferred_prof_liab_prelim(int t);

// SFAS97LP Ceded Deferred Profit Valuation Basis 
double epl_liab_sfas97lp_ceded_deferred_prof_valn_basis(int t);

// SFAS97 Limited Pay Ceded Dividends Applied 
double epl_liab_sfas97lp_ceded_div_applied(int t);

// SFAS97 Limited Pay Ceded Annual Dividends Paid 
double epl_liab_sfas97lp_ceded_div_paid(int t);

// SFAS97LP Ceded Annual Dividends Valuation Basis 
double epl_liab_sfas97lp_ceded_div_valn_basis(int t);

// SFAS97 Limited Pay Ceded Death Claim Cost 
double epl_liab_sfas97lp_ceded_dth_claim_cost(int t);

// SFAS97 Limited Pay Ceded Endowment Claim Cost 
double epl_liab_sfas97lp_ceded_endow_claim_cost(int t);

// SFAS97LP Ceded Expenses Valuation Basis 
double epl_liab_sfas97lp_ceded_exp_valn_basis(int t);

// SFAS97 Limited Pay Ceded Gross Premium Reserve 
double epl_liab_sfas97lp_ceded_gpr(int t);

// SFAS97 Limited Pay Ceded Gross Premium Reserve Units in Force 
double epl_liab_sfas97lp_ceded_gpr_units_inf(int t);

// SFAS97 Limited Pay Ceded Gross Premium 
double epl_liab_sfas97lp_ceded_gross_prem(int t);

// SFAS97 Limited Pay Ceded Health Claim Cost 
double epl_liab_sfas97lp_ceded_hlth_claim_cost(int t);

// SFAS97 Limited Pay Ceded Letter of Credit Cost 
double epl_liab_sfas97lp_ceded_loc_cost(int t);

// SFAS97 Limited Pay Ceded Maintenance Expenses Beginning of Month 
double epl_liab_sfas97lp_ceded_maint_exp_bom(int t);

// SFAS97 Limited Pay Ceded Maintenance Expenses End of Month 
double epl_liab_sfas97lp_ceded_maint_exp_eom(int t);

// SFAS97LP Ceded Maintenance Expense Reserve Accrual Valuation Basis 
double epl_liab_sfas97lp_ceded_maint_exp_res_accrual_valn_basis(int t);

// SFAS97LP Ceded Maintenance Expense Reserve Interest Valuation Basis 
double epl_liab_sfas97lp_ceded_maint_exp_res_int_valn_basis(int t);

// SFAS97 Limited Pay Ceded Maintenance Expense Reserve Preliminary 
double epl_liab_sfas97lp_ceded_maint_exp_res_prelim(int t);

// SFAS97 Limited Pay Ceded Maturity Claim Cost 
double epl_liab_sfas97lp_ceded_maturity_claim_cost(int t);

// SFAS97 Limited Pay Ceded Modco Liability 
double epl_liab_sfas97lp_ceded_modco_liab(int t);

// SFAS97 Limited Pay Ceded Modified Coinsurance Reserve Adjustment 
double epl_liab_sfas97lp_ceded_modco_res_adj(int t);

// SFAS97 Limited Pay Ceded Premium Tax 
double epl_liab_sfas97lp_ceded_prem_tax(int t);

// SFAS97 Limited Pay Ceded Premium Waiver Reserve 
double epl_liab_sfas97lp_ceded_prem_waiver_res(int t);

// SFAS97 Limited Pay Ceded Reinsurance Refund 
double epl_liab_sfas97lp_ceded_refund(int t);

// SFAS97LP Ceded Surrender Benefits Valuation Basis 
double epl_liab_sfas97lp_ceded_surr_ben_valn_basis(int t);

// SFAS97 Limited Pay Ceded Surrender Claim Cost 
double epl_liab_sfas97lp_ceded_surr_claim_cost(int t);

// SFAS97 Limited Pay Ceded Terminal Dividends 
double epl_liab_sfas97lp_ceded_terminal_div(int t);

// SFAS97 Limited Pay Gross Acquisition Expenses 
double epl_liab_sfas97lp_gross_acq_exp(int t);

// SFAS97 Limited Pay Gross Annuity Claim Cost 
double epl_liab_sfas97lp_gross_ann_claim_cost(int t);

// SFAS97LP Gross Benefit Reserve Accrual Valuation Basis 
double epl_liab_sfas97lp_gross_ben_res_accrual_valn_basis(int t);

// SFAS97LP Gross Benefit Reserve Interest Valuation Basis 
double epl_liab_sfas97lp_gross_ben_res_int_valn_basis(int t);

// SFAS97 Limited Pay Gross Benefit Reserve Preliminary 
double epl_liab_sfas97lp_gross_ben_res_prelim(int t);

// SFAS97LP Gross Benefits Valuation Basis 
double epl_liab_sfas97lp_gross_benefits_valn_basis(int t);

// SFAS97 Limited Pay Gross Capitalized Acquisition Expenses 
double epl_liab_sfas97lp_gross_capzd_acq_exp(int t);

// SFAS97LP Gross Capitalized Acquisition Expenses Valuation Basis 
double epl_liab_sfas97lp_gross_capzd_acq_exp_valn_basis(int t);

// SFAS97 Limited Pay Gross Capitalized Commission BOM 
double epl_liab_sfas97lp_gross_capzd_comm_bom(int t);

// SFAS97 Limited Pay Gross Capitalized Commission Chargeback 
double epl_liab_sfas97lp_gross_capzd_comm_chargeback(int t);

// SFAS97 Limited Pay Gross Capitalized Commission EOM 
double epl_liab_sfas97lp_gross_capzd_comm_eom(int t);

// SFAS97LP Gross Capitalized Commission Valuation Basis 
double epl_liab_sfas97lp_gross_capzd_comm_valn_basis(int t);

// SFAS97 Limited Pay Gross Capitalized YRT Reinsurance Cost 
double epl_liab_sfas97lp_gross_capzd_reins_yrt_cost(int t);

// SFAS97 Limited Pay Gross Cash Flow BOM 
double epl_liab_sfas97lp_gross_cash_flow_bom(int t);

// SFAS97 Limited Pay Gross Claim Reserve 
double epl_liab_sfas97lp_gross_claim_res(int t);

// SFAS97 Limited Pay Gross Commission Chargeback 
double epl_liab_sfas97lp_gross_comm_chargeback(int t);

// SFAS97 Limited Pay Gross Commissions Excess BOM 
double epl_liab_sfas97lp_gross_comm_excess_bom(int t);

// SFAS97 Limited Pay Gross Commissions Excess EOM 
double epl_liab_sfas97lp_gross_comm_excess_eom(int t);

// SFAS97 Limited Pay Gross Commissions Trail BOM 
double epl_liab_sfas97lp_gross_comm_trail_bom(int t);

// SFAS97 Limited Pay Gross Commissions Trail BOM Base Plan 
double epl_liab_sfas97lp_gross_comm_trail_bom_base_plan(int t);

// SFAS97 Limited Pay Gross Commissions Trail BOM Rider 
double epl_liab_sfas97lp_gross_comm_trail_bom_rider(int t);

// SFAS97 Limited Pay Gross Commissions Trail EOM 
double epl_liab_sfas97lp_gross_comm_trail_eom(int t);

// SFAS97 Limited Pay Gross Conversion Cost 
double epl_liab_sfas97lp_gross_conversion_cost(int t);

// SFAS97LP Gross DAC Amortization Valuation Basis 
double epl_liab_sfas97lp_gross_dac_amortzn_valn_basis(int t);

// SFAS97LP Gross DAC Interest Valuation Basis 
double epl_liab_sfas97lp_gross_dac_int_valn_basis(int t);

// SFAS97 Limited Pay Gross DAC Preliminary 
double epl_liab_sfas97lp_gross_dac_prelim(int t);

// SFAS97LP Gross Reinsurance YRT Asset Amortization Valuation Basis 
double epl_liab_sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis(int t);

// SFAS97LP Gross Reinsurance YRT Asset Interest Valuation Basis 
double epl_liab_sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis(int t);

// SFAS97 Limited Pay Gross DAC Reinsurance YRT Asset Preliminary 
double epl_liab_sfas97lp_gross_dac_reins_yrt_asset_prelim(int t);

// SFAS97LP Gross Deferred Profit Amortization Valuation Basis 
double epl_liab_sfas97lp_gross_deferred_prof_amortzn_valn_basis(int t);

// SFAS97LP Gross Deferred Profit Interest Valuation Basis 
double epl_liab_sfas97lp_gross_deferred_prof_int_valn_basis(int t);

// SFAS97 Limited Pay Gross Deferred Profit Liability Preliminary 
double epl_liab_sfas97lp_gross_deferred_prof_liab_prelim(int t);

// SFAS97LP Gross Deferred Profit Valuation Basis 
double epl_liab_sfas97lp_gross_deferred_prof_valn_basis(int t);

// SFAS97 Limited Pay Gross Dividends Applied 
double epl_liab_sfas97lp_gross_div_applied(int t);

// SFAS97 Limited Pay Gross Annual Dividends Paid 
double epl_liab_sfas97lp_gross_div_paid(int t);

// SFAS97LP Gross Annual Dividends Valuation Basis 
double epl_liab_sfas97lp_gross_div_valn_basis(int t);

// SFAS97 Limited Pay Gross Death Claim Cost 
double epl_liab_sfas97lp_gross_dth_claim_cost(int t);

// SFAS97 Limited Pay Gross Endowment Claim Cost 
double epl_liab_sfas97lp_gross_endow_claim_cost(int t);

// SFAS97LP Gross Expenses Valuation Basis 
double epl_liab_sfas97lp_gross_exp_valn_basis(int t);

// SFAS97 Limited Pay Gross Gross Premium Reserve 
double epl_liab_sfas97lp_gross_gpr(int t);

// SFAS97 Limited Pay Gross Gross Premium Reserve Units in Force 
double epl_liab_sfas97lp_gross_gpr_units_inf(int t);

// SFAS97 Limited Pay Gross Gross Premium 
double epl_liab_sfas97lp_gross_gross_prem(int t);

// SFAS97 Limited Pay Gross Health Claim Cost 
double epl_liab_sfas97lp_gross_hlth_claim_cost(int t);

// SFAS97 Limited Pay Gross Letter of Credit Cost 
double epl_liab_sfas97lp_gross_loc_cost(int t);

// SFAS97 Limited Pay Gross Maintenance Expenses Beginning of Month 
double epl_liab_sfas97lp_gross_maint_exp_bom(int t);

// SFAS97 Limited Pay Gross Maintenance Expenses End of Month 
double epl_liab_sfas97lp_gross_maint_exp_eom(int t);

// SFAS97LP Gross Maintenance Expense Reserve Accrual Valuation Basis 
double epl_liab_sfas97lp_gross_maint_exp_res_accrual_valn_basis(int t);

// SFAS97LP Gross Maintenance Expense Reserve Interest Valuation Basis 
double epl_liab_sfas97lp_gross_maint_exp_res_int_valn_basis(int t);

// SFAS97 Limited Pay Gross Maintenance Expense Reserve Preliminary 
double epl_liab_sfas97lp_gross_maint_exp_res_prelim(int t);

// SFAS97 Limited Pay Gross Maturity Claim Cost 
double epl_liab_sfas97lp_gross_maturity_claim_cost(int t);

// SFAS97 Limited Pay Gross Policy Loan 
double epl_liab_sfas97lp_gross_pol_loan(int t);

// SFAS97 Limited Pay Gross Policy Loan Income 
double epl_liab_sfas97lp_gross_pol_loan_inc(int t);

// SFAS97 Limited Pay Gross Premium Tax 
double epl_liab_sfas97lp_gross_prem_tax(int t);

// SFAS97 Limited Pay Gross Premium Waiver Reserve 
double epl_liab_sfas97lp_gross_prem_waiver_res(int t);

// SFAS97 Limited Pay Gross YRT Reinsurance Cost 
double epl_liab_sfas97lp_gross_reins_yrt_cost(int t);

// SFAS97LP Gross Reinsurance YRT Cost Valuation Basis 
double epl_liab_sfas97lp_gross_reins_yrt_cost_valn_basis(int t);

// SFAS97 Limited Pay Statutory Reserve for Riders 
double epl_liab_sfas97lp_gross_stat_res_rider(int t);

// SFAS97LP Gross Surrender Benefits Valuation Basis 
double epl_liab_sfas97lp_gross_surr_ben_valn_basis(int t);

// SFAS97 Limited Pay Gross Surrender Claim Cost 
double epl_liab_sfas97lp_gross_surr_claim_cost(int t);

// SFAS97 Limited Pay GrossTerminal Dividends 
double epl_liab_sfas97lp_gross_terminal_div(int t);

// SFAS97RD Ceded Acquisition Expenses 
double epl_liab_sfas97rd_ceded_acq_exp(int t);

// SFAS97RD Ceded Capital Gain on Fund 
double epl_liab_sfas97rd_ceded_cap_gain_fund(int t);

// SFAS97RD Ceded Capitalized Acquisition Expenses 
double epl_liab_sfas97rd_ceded_capzd_acq_exp(int t);

// SFAS97RD Ceded Capitalized Commissions BOM 
double epl_liab_sfas97rd_ceded_capzd_comm_bom(int t);

// SFAS97RD Ceded Capitalized Commissions Chargeback 
double epl_liab_sfas97rd_ceded_capzd_comm_chargeback(int t);

// SFAS97RD Ceded Capitalized Commissions EOM 
double epl_liab_sfas97rd_ceded_capzd_comm_eom(int t);

// SFAS97RD Ceded Capitalized Premium Bonus 
double epl_liab_sfas97rd_ceded_capzd_prem_bonus(int t);

// SFAS97RD Ceded Cash Flow BOM 
double epl_liab_sfas97rd_ceded_cash_flow_bom(int t);

// SFAS97RD Ceded Charges 
double epl_liab_sfas97rd_ceded_charges(int t);

// SFAS97RD Ceded Commission Chargeback 
double epl_liab_sfas97rd_ceded_comm_chargeback(int t);

// SFAS97RD Ceded Commissions Excess BOM 
double epl_liab_sfas97rd_ceded_comm_excess_bom(int t);

// SFAS97RD Ceded Commissions Trail BOM 
double epl_liab_sfas97rd_ceded_comm_trail_bom(int t);

// SFAS97RD Ceded Credited Interest 
double epl_liab_sfas97rd_ceded_credited_int(int t);

// SFAS97RD Ceded Deferred Loads 
double epl_liab_sfas97rd_ceded_deferred_loads(int t);

// SFAS97RD Ceded Death Claim Cost 
double epl_liab_sfas97rd_ceded_dth_claim_cost(int t);

// SFAS97RD Ceded EGP Investment Gain 
double epl_liab_sfas97rd_ceded_egp_gain_inv(int t);

// SFAS97RD Ceded EGP Mortality Gain 
double epl_liab_sfas97rd_ceded_egp_gain_mort(int t);

// SFAS97RD Ceded EGP Surrender Gain 
double epl_liab_sfas97rd_ceded_egp_gain_surr(int t);

// SFAS97RD Ceded Embedded derivative cash flow 
double epl_liab_sfas97rd_ceded_embed_deriv_cash_flow(int t);

// SFAS97RD Ceded Fund Value After Interest 
double epl_liab_sfas97rd_ceded_fund_val_aft_int(int t);

// SFAS97RD Ceded Fund Value Before Interest 
double epl_liab_sfas97rd_ceded_fund_val_bef_int(int t);

// SFAS97RD Ceded Fund Value Fixed Account 
double epl_liab_sfas97rd_ceded_fund_val_fixed(int t);

// SFAS97RD Ceded Fund Value Separate Account 
double epl_liab_sfas97rd_ceded_fund_val_sa(int t);

// SFAS97RD Ceded GMAB Benefits 
double epl_liab_sfas97rd_ceded_gmab_ben(int t);

// SFAS97RD Ceded GMDB Benefits 
double epl_liab_sfas97rd_ceded_gmdb_ben(int t);

// SFAS97RD Ceded GMIB Benefits 
double epl_liab_sfas97rd_ceded_gmib_ben(int t);

// SFAS97RD Ceded GMWB Benefits 
double epl_liab_sfas97rd_ceded_gmwb_ben(int t);

// SFAS97RD Ceded Hedge Cash Flow 
double epl_liab_sfas97rd_ceded_hedge_cash_flow(int t);

// SFAS97RD Ceded Hedge Market Value 
double epl_liab_sfas97rd_ceded_hedge_mkt_val(int t);

// SFAS97RD Ceded Host Contract Credited Interest 
double epl_liab_sfas97rd_ceded_host_contract_cred_int(int t);

// SFAS97RD Ceded Host Contract Value 
double epl_liab_sfas97rd_ceded_host_contract_val(int t);

// SFAS97RD Ceded Host Contract Value - Before Decrements 
double epl_liab_sfas97rd_ceded_host_contract_val_bef(int t);

// SFAS97RD Ceded Investment Income on Fund 
double epl_liab_sfas97rd_ceded_inv_inc_fund(int t);

// SFAS97RD Ceded Loads 
double epl_liab_sfas97rd_ceded_loads(int t);

// SFAS97RD Ceded Letter of Credit Cost 
double epl_liab_sfas97rd_ceded_loc_cost(int t);

// SFAS97RD Ceded Maintenance Expenses Beginning of Month 
double epl_liab_sfas97rd_ceded_maint_exp_bom(int t);

// SFAS97RD Ceded Maintenance Expenses End of Month 
double epl_liab_sfas97rd_ceded_maint_exp_eom(int t);

// SFAS97RD Ceded Modco Liability 
double epl_liab_sfas97rd_ceded_modco_liab(int t);

// SFAS97RD Ceded Modco Reserve Adjustment 
double epl_liab_sfas97rd_ceded_modco_res_adj(int t);

// SFAS97RD Ceded Persistency Bonus/Refunds 
double epl_liab_sfas97rd_ceded_persist_bon_ref(int t);

// SFAS97RD Ceded Policies In Force Beginning of Month 
double epl_liab_sfas97rd_ceded_policies_b(int t);

// SFAS97RD Ceded Premium Bonus 
double epl_liab_sfas97rd_ceded_prem_bonus(int t);

// SFAS97RD Ceded Premium Taxes 
double epl_liab_sfas97rd_ceded_prem_tax(int t);

// SFAS97RD Ceded Reinsurance Refund 
double epl_liab_sfas97rd_ceded_refund(int t);

// SFAS97RD Ceded Rider Charges 
double epl_liab_sfas97rd_ceded_rider_charges(int t);

// SFAS97RD Ceded SFAS 133 GMAB Liability 
double epl_liab_sfas97rd_ceded_sfas133_gmab_liab(int t);

// SFAS97RD Ceded SFAS 133 GMIB Liability 
double epl_liab_sfas97rd_ceded_sfas133_gmib_liab(int t);

// SFAS97RD Ceded SFAS 133 GMWB Liability 
double epl_liab_sfas97rd_ceded_sfas133_gmwb_liab(int t);

// SFAS97RD Ceded SOP 03-1 Assessments 
double epl_liab_sfas97rd_ceded_sop031_assess(int t);

// SFAS97RD Ceded SOP 03-1 COI Assessments 
double epl_liab_sfas97rd_ceded_sop031_coi_assess(int t);

// SFAS97RD Ceded SOP 03-1 COI Benefit 
double epl_liab_sfas97rd_ceded_sop031_coi_ben(int t);

// SFAS97RD Ceded SOP 03-1 Persistency Bonus/Refunds 
double epl_liab_sfas97rd_ceded_sop031_pbr(int t);

// SFAS97RD Ceded SOP 03-1 Persistency Bonus/Refund Fund Value 
double epl_liab_sfas97rd_ceded_sop031_pbr_fund_val(int t);

// SFAS97RD Ceded ULSG Benefits 
double epl_liab_sfas97rd_ceded_ulsg_ben(int t);

// SFAS97RD Gross Acquisition Expenses 
double epl_liab_sfas97rd_gross_acq_exp(int t);

// SFAS97RD Gross Capital Gain on Fund 
double epl_liab_sfas97rd_gross_cap_gain_fund(int t);

// SFAS97RD Gross Capitalized Acquisition Expenses 
double epl_liab_sfas97rd_gross_capzd_acq_exp(int t);

// SFAS97RD Gross Capitalized Commissions BOM 
double epl_liab_sfas97rd_gross_capzd_comm_bom(int t);

// SFAS97RD Gross Capitalized Commissions Chargeback 
double epl_liab_sfas97rd_gross_capzd_comm_chargeback(int t);

// SFAS97RD Gross Capitalized Commissions EOM 
double epl_liab_sfas97rd_gross_capzd_comm_eom(int t);

// SFAS97RD Gross Capitalized Premium Bonus 
double epl_liab_sfas97rd_gross_capzd_prem_bonus(int t);

// SFAS97RD Gross Capitalized YRT Reinsurance Cost 
double epl_liab_sfas97rd_gross_capzd_reins_yrt_cost(int t);

// SFAS97RD Gross Cash Flow BOM 
double epl_liab_sfas97rd_gross_cash_flow_bom(int t);

// SFAS97RD Gross Charges 
double epl_liab_sfas97rd_gross_charges(int t);

// SFAS97RD Gross Commission Chargeback 
double epl_liab_sfas97rd_gross_comm_chargeback(int t);

// SFAS97RD Gross Commissions Excess BOM 
double epl_liab_sfas97rd_gross_comm_excess_bom(int t);

// SFAS97RD Gross Commissions Trail BOM 
double epl_liab_sfas97rd_gross_comm_trail_bom(int t);

// SFAS97RD Gross Credited Interest 
double epl_liab_sfas97rd_gross_credited_int(int t);

// SFAS97RD Gross Deferred Loads 
double epl_liab_sfas97rd_gross_deferred_loads(int t);

// SFAS97RD Gross Death Claim Cost 
double epl_liab_sfas97rd_gross_dth_claim_cost(int t);

// SFAS97RD Gross EGP Investment Gain 
double epl_liab_sfas97rd_gross_egp_gain_inv(int t);

// SFAS97RD Gross EGP Mortality Gain 
double epl_liab_sfas97rd_gross_egp_gain_mort(int t);

// SFAS97RD Gross EGP Surrender Gain 
double epl_liab_sfas97rd_gross_egp_gain_surr(int t);

// SFAS97RD Gross Embedded derivative cash flow 
double epl_liab_sfas97rd_gross_embed_deriv_cash_flow(int t);

// SFAS97RD Gross Fund Value After Interest 
double epl_liab_sfas97rd_gross_fund_val_aft_int(int t);

// SFAS97RD Gross Fund Value Before Interest 
double epl_liab_sfas97rd_gross_fund_val_bef_int(int t);

// SFAS97RD Gross Fund Value Fixed Account 
double epl_liab_sfas97rd_gross_fund_val_fixed(int t);

// SFAS97RD Gross Fund Value Separate Account 
double epl_liab_sfas97rd_gross_fund_val_sa(int t);

// SFAS97RD Gross GMAB Benefits 
double epl_liab_sfas97rd_gross_gmab_ben(int t);

// SFAS97RD Gross GMDB Benefits 
double epl_liab_sfas97rd_gross_gmdb_ben(int t);

// SFAS97RD Gross GMIB Benefits 
double epl_liab_sfas97rd_gross_gmib_ben(int t);

// SFAS97RD Gross GMWB Benefits 
double epl_liab_sfas97rd_gross_gmwb_ben(int t);

// SFAS97RD Gross Hedge Cash Flow 
double epl_liab_sfas97rd_gross_hedge_cash_flow(int t);

// SFAS97RD Gross Hedge Market Value 
double epl_liab_sfas97rd_gross_hedge_mkt_val(int t);

// SFAS97RD Gross Host Contract Credited Interest 
double epl_liab_sfas97rd_gross_host_contract_cred_int(int t);

// SFAS97RD Gross Host Contract Value 
double epl_liab_sfas97rd_gross_host_contract_val(int t);

// SFAS97RD Gross Host Contract Value - Before Decrements 
double epl_liab_sfas97rd_gross_host_contract_val_bef(int t);

// SFAS97RD Gross Investment Income on Fund 
double epl_liab_sfas97rd_gross_inv_inc_fund(int t);

// SFAS97RD Gross Loads 
double epl_liab_sfas97rd_gross_loads(int t);

// SFAS97RD Gross Letter of Credit Cost 
double epl_liab_sfas97rd_gross_loc_cost(int t);

// SFAS97RD Gross Maintenance Expenses Beginning of Month 
double epl_liab_sfas97rd_gross_maint_exp_bom(int t);

// SFAS97RD Gross Maintenance Expenses End of Month 
double epl_liab_sfas97rd_gross_maint_exp_eom(int t);

// SFAS97RD Gross Persistency Bonus/Refunds 
double epl_liab_sfas97rd_gross_persist_bon_ref(int t);

// SFAS97RD Gross Policy Loan 
double epl_liab_sfas97rd_gross_pol_loan(int t);

// SFAS97RD Gross Policy Loan Income 
double epl_liab_sfas97rd_gross_pol_loan_inc(int t);

// SFAS97RD Gross Policies In Force Beginning of Month 
double epl_liab_sfas97rd_gross_policies_b(int t);

// SFAS97RD Gross Premium Bonus 
double epl_liab_sfas97rd_gross_prem_bonus(int t);

// SFAS97RD Gross Premium Taxes 
double epl_liab_sfas97rd_gross_prem_tax(int t);

// SFAS97RD Gross YRT Reinsurance Cost 
double epl_liab_sfas97rd_gross_reins_yrt_cost(int t);

// SFAS97RD Gross Rider Charges 
double epl_liab_sfas97rd_gross_rider_charges(int t);

// SFAS97RD Gross SFAS 133 GMAB Liability 
double epl_liab_sfas97rd_gross_sfas133_gmab_liab(int t);

// SFAS97RD Gross SFAS 133 GMIB Liability 
double epl_liab_sfas97rd_gross_sfas133_gmib_liab(int t);

// SFAS97RD Gross SFAS 133 GMWB Liability 
double epl_liab_sfas97rd_gross_sfas133_gmwb_liab(int t);

// SFAS97RD Gross SOP 03-1 Assessments 
double epl_liab_sfas97rd_gross_sop031_assess(int t);

// SFAS97RD Gross SOP 03-1 COI Assessments 
double epl_liab_sfas97rd_gross_sop031_coi_assess(int t);

// SFAS97RD Gross SOP 03-1 COI Benefit 
double epl_liab_sfas97rd_gross_sop031_coi_ben(int t);

// SFAS97RD Gross SOP 03-1 Persistency Bonus/Refunds 
double epl_liab_sfas97rd_gross_sop031_pbr(int t);

// SFAS97RD Gross SOP 03-1 Persistency Bonus/Refund Fund Value 
double epl_liab_sfas97rd_gross_sop031_pbr_fund_val(int t);

// SFAS97 Retrospective Deposit Statutory Reserve for Riders 
double epl_liab_sfas97rd_gross_stat_res_rider(int t);

// SFAS97RD Gross ULSG Benefits 
double epl_liab_sfas97rd_gross_ulsg_ben(int t);

// Startup 
virtual double virtual_startup(int t);

// Statutory Claim Expense Reserve 
double epl_liab_stat_claim_exp_res(int t);

// Statutory Claim Reserve 
double epl_liab_stat_claim_res(int t);

// Statutory Loading 
double epl_liab_stat_loading(int t);

// Statutory Premium Waiver Expense Reserve 
double epl_liab_stat_prem_waiver_exp_res(int t);

// Statutory Premium Waiver Reserve 
double epl_liab_stat_prem_waiver_res(int t);

// Statutory Policy Reserve 
double epl_liab_stat_res_mp(int t);

// Statutory Policy Reserve Unhedged 
double epl_liab_stat_res_mp_unhedged(int t);

// Net Statutory Policy Reserve 
double epl_liab_stat_res_net_mp(int t);

// Net Statutory Policy Reserve Unhedged 
double epl_liab_stat_res_net_mp_unhedged(int t);

// Net Statutory Net Premium Reserve 
double epl_liab_stat_res_net_npr(int t);

// Net Statutory Net Premium Reserve Unhedged 
double epl_liab_stat_res_net_npr_unhedged(int t);

// Net Statutory Reserve Separate Account 
double epl_liab_stat_res_net_sa(int t);

// Statutory Net Premium Reserve 
double epl_liab_stat_res_npr(int t);

// Statutory Net Premium Reserve Unhedged 
double epl_liab_stat_res_npr_unhedged(int t);

// Statutory Reserve Separate Account 
double epl_liab_stat_res_sa(int t);

// Statutory Reserve Separate Account Expense Allowance 
double epl_liab_stat_res_sa_exp_allow(int t);

// Statutory Unearned Premium Reserve 
double epl_liab_stat_unearn_prem_res(int t);

// Statutory Unearned Premium Reserve Net 
double epl_liab_stat_unearn_prem_res_net(int t);

// Statutory Unearned Premium Reserve NPR 
double epl_liab_stat_unearn_prem_res_npr(int t);

// Statutory Unearned Premium Reserve NPR Net 
double epl_liab_stat_unearn_prem_res_npr_net(int t);

// Surrender Benefits 
double epl_liab_surr_benefits(int t);

// Tax Capitalized Premium 
double epl_liab_tax_capzd_prem(int t);

// Tax Claim Expense Reserve 
double epl_liab_tax_claim_exp_res(int t);

// Tax Claim Reserve 
double epl_liab_tax_claim_res(int t);

// Tax Deferred Net Premium 
double epl_liab_tax_deferred_net_prem(int t);

// Tax Loading 
double epl_liab_tax_loading(int t);

// Tax Premium Waiver Expense Reserve 
double epl_liab_tax_prem_waiver_exp_res(int t);

// Tax Premium Waiver Reserve 
double epl_liab_tax_prem_waiver_res(int t);

// Tax Policy Reserve 
double epl_liab_tax_res_mp(int t);

// Tax Transfers to Separate Account Net 
double epl_liab_tax_transfer_to_sa_net(int t);

// Tax Unearned Premium Reserve 
double epl_liab_tax_unearn_prem_res(int t);

// Terminal Dividends 
double epl_liab_terminal_div(int t);

// Transfer Cash Flow Separate Account Beginning of Month 
double epl_liab_transfer_cash_flow_sa_bom(int t);

// Transfer Cash Flow Separate Account End of Month 
double epl_liab_transfer_cash_flow_sa_eom(int t);

// Transfers to Separate Account Net 
double epl_liab_transfer_to_sa_net(int t);

// VA PBA Assets Separate Account 
double epl_liab_va_pba_asset_sa(int t);

// VA PBA Standard Scenario Benefit Costs - Ceded Capital 
double epl_liab_va_pba_ceded_cap_std_scen_ben_costs(int t);

// VA PBA Standard Scenario Margin - Ceded Capital 
double epl_liab_va_pba_ceded_cap_std_scen_margin(int t);

// VA PBA Standard Scenario Benefit Costs - Ceded Reserve 
double epl_liab_va_pba_ceded_res_std_scen_ben_costs(int t);

// VA PBA Standard Scenario Margin - Ceded Reserve 
double epl_liab_va_pba_ceded_res_std_scen_margin(int t);

// VA PBA Standard Scenario Benefit Costs - Gross Capital 
double epl_liab_va_pba_gross_cap_std_scen_ben_costs(int t);

// VA PBA Standard Scenario Margin - Gross Capital 
double epl_liab_va_pba_gross_cap_std_scen_margin(int t);

// VA PBA Standard Scenario Benefit Costs - Gross Reserve 
double epl_liab_va_pba_gross_res_std_scen_ben_costs(int t);

// VA PBA Standard Scenario Margin - Gross Reserve 
double epl_liab_va_pba_gross_res_std_scen_margin(int t);

// VA PBA Working Reserve 
double epl_liab_va_pba_working_res(int t);

// Withdrawal Benefits 
double epl_liab_withdrl_benefits(int t);

// Period t in which Policy Commences 
int  epl_liab_commencement_period();

// Period t in which Policy Matures 
int  epl_liab_maturity_period();

// Projection Date Offset 
int  epl_liab_proj_date_offset();

// Reinsurance Flag 
int  epl_liab_reins_flag();


};
#endif
