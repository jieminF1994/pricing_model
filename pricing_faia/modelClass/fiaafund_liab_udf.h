
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
// Crediting Part Rate (Solved from Call Spread) 
double fiaafund_liab_crediting_part_rate(int t);
// Monthly Crediting Rate 
double fiaafund_liab_crediting_rate(int t);
// Crediting Rate Cumul Crbg 
double fiaafund_liab_crediting_rate_cumul_crbg(int t);
// Fixed Crediting Rate For Fund Value 
double fiaafund_liab_crediting_rate_fix(int t);
// Crediting Spread Rate 
double fiaafund_liab_crediting_sprd_rate_crbg(int t);
// Crediting Trigger Rate Crbg 
double fiaafund_liab_crediting_trigger_rate_crbg(int t);
// Crediting Part Rate Enhanced 
double fiaafund_liab_enhanced_part_rate_crbg(int t);
// Eprs Sfc Ben 
double fiaafund_liab_eprs_sfc_ben_crbg(int t);
// Eprs Sfc Ben Gross Crbg 
double fiaafund_liab_eprs_sfc_ben_gross_crbg(int t);
// Eprs Strat Fee Crbg 
double fiaafund_liab_eprs_strat_fee_crbg(int t);
// Eprs Strat Fee Crbg partial 
double fiaafund_liab_eprs_strat_fee_partial_bef_crbg(int t);
// Eprs Strat Fee Crbg partial 
double fiaafund_liab_eprs_strat_fee_partial_e_crbg(int t);
// Fa Crediting Rate Crbg 
double fiaafund_liab_fa_crediting_rate_crbg(int t);
// Fa Pricing Rate Crbg 
double fiaafund_liab_fa_pricing_rate_crbg(int t);
// Fa Reference Rate Crbg 
double fiaafund_liab_fa_reference_rate_crbg(int t);
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
// fund val Beg Term Crbg 
double fiaafund_liab_fund_val_beg_term_crbg(int t);
// fund val Beg Term Crbg 
double fiaafund_liab_fund_val_beg_term_e_crbg(int t);
// Fund Value Decrement Amount 
double fiaafund_liab_fund_val_decrem(int t);
// Fund Value End of Month 
double fiaafund_liab_fund_val_e(int t);
// Fund Value Before Outflow EOM 
double fiaafund_liab_fund_val_e_bef(int t);
// Rebalancing Transfer to Account 
double fiaafund_liab_fund_val_rebal(int t);
// Gmab Av B Crbg 
double fiaafund_liab_gmab_av_b_crbg(int t);
// Gmab Av E Bef Crbg 
double fiaafund_liab_gmab_av_e_bef_crbg(int t);
// Gmab Av E Crbg 
double fiaafund_liab_gmab_av_e_crbg(int t);
// Gmab Chg Crbg 
double fiaafund_liab_gmab_chg_crbg(int t);
// Gmab Chg Partial E Bef Crbg 
double fiaafund_liab_gmab_chg_partial_e_bef_crbg(int t);
// Gmab Chg Partial E Crbg 
double fiaafund_liab_gmab_chg_partial_e_crbg(int t);
// Gmab Global Payoff Crbg 
double fiaafund_liab_gmab_global_payoff_crbg(int t);
// Gmab Payoff Crbg 
double fiaafund_liab_gmab_payoff_crbg(int t);
// GMWB Charge 
double fiaafund_liab_gmwb_chg(int t);
// GMWB Charge Partial 
double fiaafund_liab_gmwb_chg_partial_bef_crbg(int t);
// GMWB Charge Partial 
double fiaafund_liab_gmwb_chg_partial_e_crbg(int t);
// Hedge Cash Flows 
double fiaafund_liab_hedge_cash_flow(int t);
// Hedge Investment Amount BOM 
double fiaafund_liab_hedge_inv_amt_bom(int t);
// Market Value of Hedges 
double fiaafund_liab_hedge_mkt_val(int t);
// Hedge Market Value Growth 
double fiaafund_liab_hedge_mkt_val_growth(int t);
// Hedge Market Value Per Unit Notional 
double fiaafund_liab_hedge_mkt_val_per_unit_notional(int t);
// Hedge Sale Amount Beginning of Month 
double fiaafund_liab_hedge_sale_amt_bom(int t);
// Hedge Sale Amount End of Month 
double fiaafund_liab_hedge_sale_amt_eom(int t);
// Index Term Elapsed Pct Crbg 
double fiaafund_liab_index_term_elapsed_pct_crbg(int t);
// Index Term Return Crbg 
double fiaafund_liab_index_term_return_crbg(int t);
// Index Value 
double fiaafund_liab_index_val(int t);
// Index Val Beg Term Crbg 
double fiaafund_liab_index_val_beg_term_crbg(int t);
// Index Value Beginning of Month 
double fiaafund_liab_index_val_bom(int t);
// Initialize 
double fiaafund_liab_initialize(int t);
// Lapse Dyn Crediting Rt 
double fiaafund_liab_lapse_dyn_crediting_rt_crbg(int t);
// Notional Amount Required 
double fiaafund_liab_notional_amt_required(int t);
// Notional Amount Required Before Decrements 
double fiaafund_liab_notional_amt_required_bef(int t);
// Notional  Amount to Hedge 
double fiaafund_liab_notional_to_hedge(int t);
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
// Option Budget Amount 
double fiaafund_liab_opt_budget_amt(int t);
// Opt Budget Eprs Crbg 
double fiaafund_liab_opt_budget_eprs_crbg(int t);
// Opt Cost Atm Crbg 
double fiaafund_liab_opt_cost_atm_crbg(int t);
// Beg term option cost 
double fiaafund_liab_opt_cost_beg_term_crbg(int t);
// Opt Cost Bs Bom Crbg 
double fiaafund_liab_opt_cost_bs_bom_crbg(int t);
// Opt Cost Bs Eom Crbg 
double fiaafund_liab_opt_cost_bs_eom_crbg(int t);
// Current option cost  BOM 
double fiaafund_liab_opt_cost_by_grid_bom_crbg(int t);
// Option Payoff 
double fiaafund_liab_opt_payoff(int t);
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
// Prorated Strategy Return Crbg 
double fiaafund_liab_prorated_strategy_return_crbg(int t);
// Startup 
virtual double virtual_startup(int t);
// Strategy return, or intrinsic value 
double fiaafund_liab_strategy_return_crbg(int t);
// Commencement Period 
int  fiaafund_liab_commencement_period();
// Months Since Issue 
int  fiaafund_liab_elapsed_mths();
// Lookback Months 
int  fiaafund_liab_lookback_mths();
// Lookback Sampling Months 
int  fiaafund_liab_lookback_sampling_mths();
// Maturity Period 
int  fiaafund_liab_maturity_period();
// Initial Opt Budget - New Business 
double  fiaafund_liab_nb_opt_budget_calc_crbg();

};
#endif
