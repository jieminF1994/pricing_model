
#ifndef __HDG_GRP_COMP_UDF_H_
#define __HDG_GRP_COMP_UDF_H_

#include "ModelClass\hdg_grp_comp.h"

class HDG_GRP_COMP_UDF : public HDG_GRP_COMP {

	friend class HDG_GRP_COMP;

//constructor 
HDG_GRP_COMP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: HDG_GRP_COMP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
HDG_GRP_COMP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : HDG_GRP_COMP(columnCount, mocd, persObj) {}


// Calendar Month 
double hdg_grp_comp_cal_mth(int t);

// Calendar Year 
double hdg_grp_comp_cal_yr(int t);

// Calendar Year Relative 
double hdg_grp_comp_cal_yr_relative(int t);

// Cap Rate 
double hdg_grp_comp_cap_rate(int t);

// Delta Hedge Flag 
double hdg_grp_comp_delta_hedge_flag(int t);

// Delta Hedge Investment Amount 
double hdg_grp_comp_delta_hedge_inv_amt(int t);

// Delta Hedge Market Value of Assets 
double hdg_grp_comp_delta_hedge_mkt_val(int t);

// Delta Hedge Market Value of Assets Increase 
double hdg_grp_comp_delta_hedge_mkt_val_incr(int t);

// Delta Hedge Derivative Payment 
double hdg_grp_comp_delta_hedge_pmt(int t);

// Delta Hedge Profit 
double hdg_grp_comp_delta_hedge_prof(int t);

// Delta Hedge Sale Amount 
double hdg_grp_comp_delta_hedge_sale_amt(int t);

// Delta Hedge Transaction Cost 
double hdg_grp_comp_delta_hedge_transaction_cost(int t);

// Delta Index 1 
double hdg_grp_comp_delta_index_1(int t);

// Delta Index 2 
double hdg_grp_comp_delta_index_2(int t);

// Delta Index 3 
double hdg_grp_comp_delta_index_3(int t);

// Delta Index 4 
double hdg_grp_comp_delta_index_4(int t);

// Delta Index 5 
double hdg_grp_comp_delta_index_5(int t);

// Delta Index 6 
double hdg_grp_comp_delta_index_6(int t);

// Delta Parallel 
double hdg_grp_comp_delta_parallel(int t);

// Economic Cash Amount 
double hdg_grp_comp_econ_cash(int t);

// Interest Earned on Economic Cash Amount 
double hdg_grp_comp_econ_cash_int(int t);

// Economic Cash Interest Rate 
double hdg_grp_comp_econ_cash_int_rate(int t);

// Economic Profit 
double hdg_grp_comp_econ_prof(int t);

// Unhedged Economic Profit 
double hdg_grp_comp_econ_prof_unhedged(int t);

// Economic Reserve: Present Value of Claims - Present Value of Charges 
double hdg_grp_comp_econ_res(int t);

// Economic Reserve Increase 
double hdg_grp_comp_econ_res_incr(int t);

// Interest Earned on Economic Reserve 
double hdg_grp_comp_econ_res_int(int t);

// Finalize 
double hdg_grp_comp_finalize(int t);

// Fund Value Decrements 
double hdg_grp_comp_fund_val_decrem(int t);

// Fund Value Decrements Cumulative 
double hdg_grp_comp_fund_val_decrem_cumul(int t);

// Fund Value EOM 
double hdg_grp_comp_fund_val_fixed(int t);

// Gamma Hedge Flag 
double hdg_grp_comp_gamma_hedge_flag(int t);

// Gamma Hedge Investment Amount 
double hdg_grp_comp_gamma_hedge_inv_amt(int t);

// Gamma Hedge Market Value of Assets 
double hdg_grp_comp_gamma_hedge_mkt_val(int t);

// Gamma Hedge Market Value of Assets Increase 
double hdg_grp_comp_gamma_hedge_mkt_val_incr(int t);

// Gamma Hedge Derivative Payment 
double hdg_grp_comp_gamma_hedge_pmt(int t);

// Gamma Hedge Profit 
double hdg_grp_comp_gamma_hedge_prof(int t);

// Gamma Hedge Sale Amount 
double hdg_grp_comp_gamma_hedge_sale_amt(int t);

// Gamma Hedge Transaction Cost 
double hdg_grp_comp_gamma_hedge_transaction_cost(int t);

// Gamma Index 1 
double hdg_grp_comp_gamma_index_1(int t);

// Gamma Index 2 
double hdg_grp_comp_gamma_index_2(int t);

// Gamma Index 3 
double hdg_grp_comp_gamma_index_3(int t);

// Gamma Index 4 
double hdg_grp_comp_gamma_index_4(int t);

// Gamma Index 5 
double hdg_grp_comp_gamma_index_5(int t);

// Gamma Index 6 
double hdg_grp_comp_gamma_index_6(int t);

// Gamma Parallel 
double hdg_grp_comp_gamma_parallel(int t);

// Gamma Vega Hedge Flag 
double hdg_grp_comp_gamma_vega_hedge_flag(int t);

// Hedge Cash Flow 
double hdg_grp_comp_hedge_cash_flow(int t);

// Hedge Cost Charge 
double hdg_grp_comp_hedge_cost_charge(int t);

// Hedge Expense 
double hdg_grp_comp_hedge_exp(int t);

// Hedge Interest Payment 
double hdg_grp_comp_hedge_int_pmt(int t);

// Hedge Investment Amount Beginning of Month 
double hdg_grp_comp_hedge_inv_amt_bom(int t);

// Hedge Investment Amount End of Month 
double hdg_grp_comp_hedge_inv_amt_eom(int t);

// Hedge Liability GMXB Claims 
double hdg_grp_comp_hedge_liab_claims(int t);

// Hedge Market Value 
double hdg_grp_comp_hedge_mkt_val(int t);

// Hedge Notional Amount 
double hdg_grp_comp_hedge_notional_amt(int t);

// Hedge Notional Amount Available 
double hdg_grp_comp_hedge_notional_amt_available(int t);

// Hedge Option Payment 
double hdg_grp_comp_hedge_opt_pmt(int t);

// Hedge Sales Amount 
double hdg_grp_comp_hedge_sale_amt(int t);

// Underlying Equity Index 
double hdg_grp_comp_index_val(int t);

// Initialize 
double hdg_grp_comp_initialize(int t);

// Liability Cash Flow Beginning of Month 
double hdg_grp_comp_liab_cash_flow_bom(int t);

// Liability Cash Flow End of Month 
double hdg_grp_comp_liab_cash_flow_eom(int t);

// Long Strike 
double hdg_grp_comp_long_strike(int t);

// Notional Amount Required 
double hdg_grp_comp_notional_amt_required(int t);

// Notional Amount To Hedge 
double hdg_grp_comp_notional_amt_to_hedge(int t);

// Notional Amount To Hedge Cap 
double hdg_grp_comp_notional_amt_to_hedge_cap(int t);

// Notional Amount To Hedge Index 
double hdg_grp_comp_notional_amt_to_hedge_index(int t);

// Notional Amount To Hedge Long Strike 
double hdg_grp_comp_notional_amt_to_hedge_long_strike(int t);

// Notional To Hedge 
double hdg_grp_comp_notional_to_hedge(int t);

// Option Budget 
double hdg_grp_comp_opt_budget(int t);

// Option Budget Amount 
double hdg_grp_comp_opt_budget_amt(int t);

// Option Payoff 
double hdg_grp_comp_opt_payoff(int t);

// Participation Rate 
double hdg_grp_comp_part_rate(int t);

// Projection Target - Hedging Statement Calculations 
double hdg_grp_comp_proj_tgt_hedge_stmt(int t);

// Present Value of Charges 
double hdg_grp_comp_pv_charges(int t);

// Present Value of Claims 
double hdg_grp_comp_pv_claims(int t);

// Rho Convexity Hedge Flag 
double hdg_grp_comp_rho_convex_hedge_flag(int t);

// Rho Convexity Hedge Investment Amount 
double hdg_grp_comp_rho_convex_hedge_inv_amt(int t);

// Rho Convexity Hedge Market Value of Assets 
double hdg_grp_comp_rho_convex_hedge_mkt_val(int t);

// Rho Convexity Hedge Market Value of Assets Increase 
double hdg_grp_comp_rho_convex_hedge_mkt_val_incr(int t);

// Rho Convexity Hedge Derivative Payment 
double hdg_grp_comp_rho_convex_hedge_pmt(int t);

// Rho Convexity Hedge Profit 
double hdg_grp_comp_rho_convex_hedge_prof(int t);

// Rho Convexity Hedge Sale Amount 
double hdg_grp_comp_rho_convex_hedge_sale_amt(int t);

// Rho Convexity Hedge Transaction Cost 
double hdg_grp_comp_rho_convex_hedge_transaction_cost(int t);

// Rho Convexity Key Rate 1 
double hdg_grp_comp_rho_convex_key_rate_1(int t);

// Rho Convexity Key Rate 10 
double hdg_grp_comp_rho_convex_key_rate_10(int t);

// Rho Convexity Key Rate 2 
double hdg_grp_comp_rho_convex_key_rate_2(int t);

// Rho Convexity Key Rate 3 
double hdg_grp_comp_rho_convex_key_rate_3(int t);

// Rho Convexity Key Rate 4 
double hdg_grp_comp_rho_convex_key_rate_4(int t);

// Rho Convexity Key Rate 1 
double hdg_grp_comp_rho_convex_key_rate_5(int t);

// Rho Convexity Key Rate 6 
double hdg_grp_comp_rho_convex_key_rate_6(int t);

// Rho Convexity Key Rate 7 
double hdg_grp_comp_rho_convex_key_rate_7(int t);

// Rho Convexity Key Rate 8 
double hdg_grp_comp_rho_convex_key_rate_8(int t);

// Rho Convexity Key Rate 9 
double hdg_grp_comp_rho_convex_key_rate_9(int t);

// Rho Convexity Parallel 
double hdg_grp_comp_rho_convex_parallel(int t);

// Rho Hedge Flag 
double hdg_grp_comp_rho_hedge_flag(int t);

// Rho Hedge Investment Amount 
double hdg_grp_comp_rho_hedge_inv_amt(int t);

// Rho Hedge Market Value of Assets 
double hdg_grp_comp_rho_hedge_mkt_val(int t);

// Rho Hedge Market Value of Assets Increase 
double hdg_grp_comp_rho_hedge_mkt_val_incr(int t);

// Rho Hedge Derivative Payment 
double hdg_grp_comp_rho_hedge_pmt(int t);

// Rho Hedge Profit 
double hdg_grp_comp_rho_hedge_prof(int t);

// Rho Hedge Sale Amount 
double hdg_grp_comp_rho_hedge_sale_amt(int t);

// Rho Hedge Transaction Cost 
double hdg_grp_comp_rho_hedge_transaction_cost(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_1(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_10(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_2(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_3(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_4(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_5(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_6(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_7(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_8(int t);

// Rho Key Rate 1 
double hdg_grp_comp_rho_key_rate_9(int t);

// Rho Parallel 
double hdg_grp_comp_rho_parallel(int t);

// Short Strike 
double hdg_grp_comp_short_strike(int t);

// Startup 
virtual double virtual_startup(int t);

// Valuation Target Hedge Final 
double hdg_grp_comp_valn_tgt_hedge_final(int t);

// Valuation Target Hedge Shock 
double hdg_grp_comp_valn_tgt_hedge_shock(int t);

// Vega Hedge Flag 
double hdg_grp_comp_vega_hedge_flag(int t);

// Vega Hedge Investment Amount 
double hdg_grp_comp_vega_hedge_inv_amt(int t);

// Vega Hedge Market Value of Assets 
double hdg_grp_comp_vega_hedge_mkt_val(int t);

// Vega Hedge Market Value of Assets Increase 
double hdg_grp_comp_vega_hedge_mkt_val_incr(int t);

// Vega Hedge Derivative Payment 
double hdg_grp_comp_vega_hedge_pmt(int t);

// Vega Hedge Profit 
double hdg_grp_comp_vega_hedge_prof(int t);

// Vega Hedge Sale Amount 
double hdg_grp_comp_vega_hedge_sale_amt(int t);

// Vega Hedge Transaction Cost 
double hdg_grp_comp_vega_hedge_transaction_cost(int t);

// Vega Index 1 All Terms 
double hdg_grp_comp_vega_index_1(int t);

// Vega Index 1 Term 1 
double hdg_grp_comp_vega_index_1_term_1(int t);

// Vega Index 1 Term 1 
double hdg_grp_comp_vega_index_1_term_2(int t);

// Vega Index 1 Term 1 
double hdg_grp_comp_vega_index_1_term_3(int t);

// Vega Index 2 All Terms 
double hdg_grp_comp_vega_index_2(int t);

// Vega Index 2 Term 1 
double hdg_grp_comp_vega_index_2_term_1(int t);

// Vega Index 2 Term 2 
double hdg_grp_comp_vega_index_2_term_2(int t);

// Vega Index 2 Term 3 
double hdg_grp_comp_vega_index_2_term_3(int t);

// Vega Index 3 All Terms 
double hdg_grp_comp_vega_index_3(int t);

// Vega Index 3 Term 1 
double hdg_grp_comp_vega_index_3_term_1(int t);

// Vega Index 3 Term 2 
double hdg_grp_comp_vega_index_3_term_2(int t);

// Vega Index 3 Term 3 
double hdg_grp_comp_vega_index_3_term_3(int t);

// Vega Index 4 All Terms 
double hdg_grp_comp_vega_index_4(int t);

// Vega Index 4 Term 1 
double hdg_grp_comp_vega_index_4_term_1(int t);

// Vega Index 4 Term 2 
double hdg_grp_comp_vega_index_4_term_2(int t);

// Vega Index 4 Term 3 
double hdg_grp_comp_vega_index_4_term_3(int t);

// Vega Index 5 All Terms 
double hdg_grp_comp_vega_index_5(int t);

// Vega Index 5 Term 1 
double hdg_grp_comp_vega_index_5_term_1(int t);

// Vega Index 5 Term 2 
double hdg_grp_comp_vega_index_5_term_2(int t);

// Vega Index 5 Term 1 
double hdg_grp_comp_vega_index_5_term_3(int t);

// Vega Index 6 All Terms 
double hdg_grp_comp_vega_index_6(int t);

// Vega Index 6 Term 1 
double hdg_grp_comp_vega_index_6_term_1(int t);

// Vega Index 6 Term 2 
double hdg_grp_comp_vega_index_6_term_2(int t);

// Vega Index 6 Term 3 
double hdg_grp_comp_vega_index_6_term_3(int t);

// Vega Parallel 
double hdg_grp_comp_vega_parallel(int t);

// Final Period 
int  hdg_grp_comp_final_period();

// Projection Date Adjusted 
xstring  hdg_grp_comp_proj_date_adj();

// Projection Start Date 
int  hdg_grp_comp_proj_start_date();

// Projection Start Mth 
int  hdg_grp_comp_proj_start_mth();

// Projection Start Yr 
int  hdg_grp_comp_proj_start_yr();

// Start Period 
int  hdg_grp_comp_start_period();


};
#endif
