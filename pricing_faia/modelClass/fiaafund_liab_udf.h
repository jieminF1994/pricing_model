
#ifndef __FIAAFUND_LIAB_UDF_H_
#define __FIAAFUND_LIAB_UDF_H_

#include "ModelClass\fiaafund_liab.h"

class FIAAFUND_LIAB_UDF : public FIAAFUND_LIAB {

	friend class FIAAFUND_LIAB;

//constructor 
FIAAFUND_LIAB_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: FIAAFUND_LIAB(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
FIAAFUND_LIAB_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : FIAAFUND_LIAB(columnCount, mocd, persObj) {}


// Administration Fee 
double fiaafund_liab_admin_fee(int t);

// Credited Interest 
double fiaafund_liab_credited_int(int t);

// Crediting Cap Rate (Solved from Call Spread) 
double fiaafund_liab_crediting_cap_rate(int t);

// Crediting Cap Rate 2Nd Strat Crbg 
double fiaafund_liab_crediting_cap_rate_2nd_strat_crbg(int t);

// Crediting Part Rate (Solved from Call Spread) 
double fiaafund_liab_crediting_part_rate(int t);

// Apply renewal strategy to par rate 
double fiaafund_liab_crediting_part_rate_aig(int t);

// crediting par rate before addtional par rate from fee4rate/ fee plus 
double fiaafund_liab_crediting_part_rate_base_aig(int t);

// Crediting Pricing Spread 
double fiaafund_liab_crediting_pri_sprd_aig(int t);

// Monthly Crediting Rate 
double fiaafund_liab_crediting_rate(int t);

// Cumulative crediting rate 
double fiaafund_liab_crediting_rate_cumul_aig(int t);

// Fixed Crediting Rate For Fund Value 
double fiaafund_liab_crediting_rate_fix(int t);

// Cumulative fixed crediting rate 
double fiaafund_liab_crediting_rate_fix_cumul_aig(int t);

// Crediting Spread Rate: 
double fiaafund_liab_crediting_spread_rate_aig(int t);

// Crediting Trigger Rate Aig 
double fiaafund_liab_crediting_trigger_rate_aig(int t);

// Flag to indicate a dynamic change to the crediting type: 
double fiaafund_liab_crediting_type_dyn_trigger_aig(int t);

// flag for first year after dynamic switch 
double fiaafund_liab_crediting_type_dyn_zero_threshold_flag_aig(int t);

// Cumul Return Sc Period Crbg 
double fiaafund_liab_cumul_return_sc_period_crbg(int t);

// cost percentage of EPRS features 
double fiaafund_liab_eprs_cost_rate_aig(int t);

// final crediting rate for fixed annuity 
double fiaafund_liab_fa_crediting_rate_aig(int t);

// Preliminary crediting rate for fixed annuity 
double fiaafund_liab_fa_pricing_rate_aig(int t);

// reference rate for fixed annuity 
double fiaafund_liab_fa_reference_rate_aig(int t);

// Fund Released on Annuitization 
double fiaafund_liab_fund_released_ann(int t);

// Fund Released on Death 
double fiaafund_liab_fund_released_dth(int t);

// Fund Released on Maturity 
double fiaafund_liab_fund_released_maturity(int t);

// Fund Released on Surrender 
double fiaafund_liab_fund_released_surr(int t);

// Fund Released on Withdrawal 
double fiaafund_liab_fund_released_withdrl(int t);

// Fund Value After Outflow - BOM 
double fiaafund_liab_fund_val_b(int t);

// Fund Value Before Outflow BOM 
double fiaafund_liab_fund_val_b_bef(int t);

// Fund Value Decrement Amount 
double fiaafund_liab_fund_val_decrem(int t);

// Fund Value End of Month 
double fiaafund_liab_fund_val_e(int t);

// Fund Value Before Outflow EOM 
double fiaafund_liab_fund_val_e_bef(int t);

// Fund Value End of Month, before maturity 
double fiaafund_liab_fund_val_e_bef_maturity_aig(int t);

// Rebalancing Transfer to Account 
double fiaafund_liab_fund_val_rebal(int t);

// Fund value * pricing spread: 
double fiaafund_liab_fund_weighted_crediting_pri_sprd_aig(int t);

// GMAB BOM 
double fiaafund_liab_gmab_av_b_aig(int t);

// GMAB EOM 
double fiaafund_liab_gmab_av_e_aig(int t);

// GMAB EOM 
double fiaafund_liab_gmab_av_e_bef_aig(int t);

// GMAB rider chg 
double fiaafund_liab_gmab_chg_aig(int t);

// GMAB rider chg partial 
double fiaafund_liab_gmab_chg_partial_e_aig(int t);

// GMAB rider chg partial 
double fiaafund_liab_gmab_chg_partial_e_bef_aig(int t);

// GMAB global payoff to reflect Max (0, Min(GMAB cap * Premium less wdl, GMAB AV) –  AV without GMAB) 
double fiaafund_liab_gmab_global_payoff_crbg(int t);

// GMAB benefits Payoff to reflect the difference in the GMAB AV and the AV before GMAB application 
double fiaafund_liab_gmab_payoff_crbg(int t);

// GMWB Charge 
double fiaafund_liab_gmwb_chg(int t);

// GMWB Charge At Surrender For Inforce End of Month 
double fiaafund_liab_gmwb_chg_at_surr_aig(int t);

// GMWB Charge At Surrender For Inforce End of Month Before Claims 
double fiaafund_liab_gmwb_chg_at_surr_bef_aig(int t);

// A per account proration factor for use in mid-crediting period partial crediting: 
double fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_at_wdl_aig(int t);

// Proration factor for GMWB partial income crediting, End of Month: 
double fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_aig(int t);

// Proration factor for GMWB partial income crediting, End of Month Before Claims: 
double fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_bef_aig(int t);

// Hedge Cash Flows 
double fiaafund_liab_hedge_cash_flow(int t);

// Hedge Investment Amount BOM 
double fiaafund_liab_hedge_inv_amt_bom(int t);

// Market Value of Hedges 
double fiaafund_liab_hedge_mkt_val(int t);

// Hedge Market Value: 
double fiaafund_liab_hedge_mkt_val_aig(int t);

// Option Mkt Val Estimate Gmab 
double fiaafund_liab_hedge_mkt_val_estimate_gmab_crbg(int t);

// Hedge Market Value Growth 
double fiaafund_liab_hedge_mkt_val_growth(int t);

// Hedge Market Value Per Unit Notional 
double fiaafund_liab_hedge_mkt_val_per_unit_notional(int t);

// Hedge Market Value Per Unit Notional: 
double fiaafund_liab_hedge_mkt_val_per_unit_notional_aig(int t);

// alpha value to calculate option values in hedging 
double fiaafund_liab_hedge_option_val_alpha_col_aig(int t);

// Hedge Sale Amount Beginning of Month 
double fiaafund_liab_hedge_sale_amt_bom(int t);

// Hedge Sale Amount End of Month 
double fiaafund_liab_hedge_sale_amt_eom(int t);

// Index Term: 
double fiaafund_liab_index_term_aig(int t);

// Index Term Beginning Index Value: 
double fiaafund_liab_index_term_beginning_index_val_bom_aig(int t);

// Index term cap for crediting: 
double fiaafund_liab_index_term_cap_rate_max_col_aig(int t);

// Index term minimum cap for crediting: 
double fiaafund_liab_index_term_cap_rate_min_col_aig(int t);

// Index Term Elapsed Months: 
double fiaafund_liab_index_term_elapsed_mths_eom_aig(int t);

// Index Term Elapsed Percent EOM: 
double fiaafund_liab_index_term_elapsed_pct_eom_aig(int t);

// Index Term End Duration (Month): 
double fiaafund_liab_index_term_end_duration_aig(int t);

// Index term floor to crediting rate: 
double fiaafund_liab_index_term_floor_col_aig(int t);

// Index Term Index Return: 
double fiaafund_liab_index_term_index_return_aig(int t);

// Initial crediting cap adjusted for index term period: 
double fiaafund_liab_index_term_init_cap_rate_aig(int t);

// Initial participation rate adjusted for index term: 
double fiaafund_liab_index_term_init_part_rate_aig(int t);

// Initial spread rate adjusted for index term period: 
double fiaafund_liab_index_term_init_spread_rate_aig(int t);

// Months in an index term: 
double fiaafund_liab_index_term_mths_aig(int t);

// Index term maximum participation rate: 
double fiaafund_liab_index_term_part_rate_max_col_aig(int t);

// Index term minimum participation rate: 
double fiaafund_liab_index_term_part_rate_min_col_aig(int t);

// Index term maximum spread for crediting: 
double fiaafund_liab_index_term_sprd_rate_max_col_aig(int t);

// Index term spread rate for crediting: 
double fiaafund_liab_index_term_sprd_rate_min_col_aig(int t);

// Index Term Start Duration: 
double fiaafund_liab_index_term_start_duration_aig(int t);

// Index Value 
double fiaafund_liab_index_val(int t);

// Index Value Beginning of Month 
double fiaafund_liab_index_val_bom(int t);

// Initialize 
double fiaafund_liab_initialize(int t);

// Base Product Dynamic Lapse crediting rate 
double fiaafund_liab_lapse_dyn_base_prod_crediting_rt_aig(int t);

// NYIA: minimum accumulation value 
double fiaafund_liab_min_accum_val_b_aig(int t);

// NYIA: minimum accumulation value 
double fiaafund_liab_min_accum_val_b_bef_aig(int t);

// NYIA: minimum accumulation value 
double fiaafund_liab_min_accum_val_e_aig(int t);

// NYIA: minimum accumulation value 
double fiaafund_liab_min_accum_val_e_bef_aig(int t);

// Minimum accumulation value before maturity payment: 
double fiaafund_liab_min_accum_val_e_bef_maturity_aig(int t);

// Net Crediting Rate Aig 
double fiaafund_liab_net_crediting_rate_aig(int t);

// Notional Amount Required 
double fiaafund_liab_notional_amt_required(int t);

// Notional Amount Required Before Decrements 
double fiaafund_liab_notional_amt_required_bef(int t);

// Notional Amt Seccap Gmab Bef Crbg 
double fiaafund_liab_notional_amt_seccap_gmab_bef_crbg(int t);

// Notional Amt Seccap Gmab Crbg 
double fiaafund_liab_notional_amt_seccap_gmab_crbg(int t);

// Notional  Amount to Hedge 
double fiaafund_liab_notional_to_hedge(int t);

// Notional Amount To Hedge: 
double fiaafund_liab_notional_to_hedge_aig(int t);

// Notional Amount to Hedge Cap 
double fiaafund_liab_notional_to_hedge_cap(int t);

// Notional Amount to Hedge Index 
double fiaafund_liab_notional_to_hedge_index(int t);

// Notional Amount to Hedge Long Strike 
double fiaafund_liab_notional_to_hedge_long_strike(int t);

// Notional Amount to Hedge Net 
double fiaafund_liab_notional_to_hedge_net(int t);

// Available Option Budget 
double fiaafund_liab_opt_budget(int t);

// Option budget for 2nd strategy 
double fiaafund_liab_opt_budget_2nd_strat_aig(int t);

// Option Budget Amount 
double fiaafund_liab_opt_budget_amt(int t);

// Opt Budget Cost Aig 
double fiaafund_liab_opt_budget_cost_aig(int t);

// Opt Budget for EPRS 
double fiaafund_liab_opt_budget_eprs_aig(int t);

// Option budget for the initial strategy 
double fiaafund_liab_opt_budget_renewal_aig(int t);

// Available Option Budget at Strategy Term Renewal 
double fiaafund_liab_opt_budget_strategy_term_renewal_aig(int t);

// target opt budget for 2nd strategy 
double fiaafund_liab_opt_budget_tgt_2nd_strat_aig(int t);

// Option budget: 
double fiaafund_liab_opt_budget_tgt_aig(int t);

// ATM Opt Cost. Created when Solving for Particiaption Rate for Fee4rate Phase 2 
double fiaafund_liab_opt_cost_atm_aig(int t);

// Option Payoff 
double fiaafund_liab_opt_payoff(int t);

// Option Payoff: 
double fiaafund_liab_opt_payoff_aig(int t);

// Option Strike Price 
double fiaafund_liab_opt_strike_price(int t);

// Net Option Value Numerator 
double fiaafund_liab_opt_value_net_numer(int t);

// Penalty Free Withdrawal Fund Value 
double fiaafund_liab_pfwd_surr_fund_val(int t);

// Premium Allocated to Account (incl. Premium Bonus) 
double fiaafund_liab_prem_alloc(int t);

// Premium Bonus 
double fiaafund_liab_prem_bonus(int t);

// SFAS133 GMWB Charge 
double fiaafund_liab_sfas133_gmwb_chg(int t);

// Startup 
virtual double virtual_startup(int t);

// Monthly Strategy Return 
double fiaafund_liab_strategy_return_aig(int t);

// Cumulative Strategy Return 
double fiaafund_liab_strategy_return_cumul_aig(int t);

// Prorated strategy return: 
double fiaafund_liab_strategy_return_prorated_aig(int t);

// Strategy Term: 
double fiaafund_liab_strategy_term_aig(int t);

// Strategy Term Beginning Index Value BOM: 
double fiaafund_liab_strategy_term_beginning_index_val_bom_aig(int t);

// Strategy Term Elapsed Months EOM: 
double fiaafund_liab_strategy_term_elapsed_mths_eom_aig(int t);

// Strategy Term Elapsed Percentage EOM: 
double fiaafund_liab_strategy_term_elapsed_pct_eom_aig(int t);

// Strategy term floor for crediting: 
double fiaafund_liab_strategy_term_floor_col_aig(int t);

// Strategy Term Index Return: 
double fiaafund_liab_strategy_term_index_return_aig(int t);

// Months in the current strategy term: 
double fiaafund_liab_strategy_term_mths_aig(int t);

// Tier Number 
double fiaafund_liab_tier_number_aig(int t);

// Participation Rate Enhancement Strategy Fee 
double fiaafund_liab_tier_strat_fee_aig(int t);

// Tier Strat Fee  At Surrender For Inforce End of Month 
double fiaafund_liab_tier_strat_fee_at_surr_aig(int t);

// Tier Strat Fee At Surrender For Inforce End of Month Before Claims 
double fiaafund_liab_tier_strat_fee_at_surr_bef_aig(int t);

// Commencement Period 
int  fiaafund_liab_commencement_period();

// Months Since Issue 
int  fiaafund_liab_elapsed_mths();

// Final Period 
double  fiaafund_liab_final_period();

// Lookback Months 
int  fiaafund_liab_lookback_mths();

// Lookback Sampling Months 
int  fiaafund_liab_lookback_sampling_mths();

// Maturity Period 
int  fiaafund_liab_maturity_period();


};
#endif
