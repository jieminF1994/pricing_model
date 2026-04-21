
#ifndef __ANN_PBA_PBA_UDF_H_
#define __ANN_PBA_PBA_UDF_H_

#include "ModelClass\ann_pba_pba.h"

class ANN_PBA_PBA_UDF : public ANN_PBA_PBA {

	friend class ANN_PBA_PBA;

//constructor 
ANN_PBA_PBA_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: ANN_PBA_PBA(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
ANN_PBA_PBA_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : ANN_PBA_PBA(columnCount, mocd, persObj) {}


// Asset Yield Monthly 
double ann_pba_pba_asset_yld_mthly(int t);

// Accumulated Assets 
double ann_pba_pba_assets_accum(int t);

// Calendar Month 
double ann_pba_pba_cal_mth(int t);

// Calendar Year 
double ann_pba_pba_cal_yr(int t);

// Calendar Year Relative 
double ann_pba_pba_cal_yr_relative(int t);

// Capital Gains 
double ann_pba_pba_cap_gain(int t);

// Cash Flow 
double ann_pba_pba_cash_flow(int t);

// Cash Flow Interest 
double ann_pba_pba_cash_flow_int(int t);

// Cash Flow Rate Monthly 
double ann_pba_pba_cash_flow_rate_mthly(int t);

// Date 
double ann_pba_pba_date(int t);

// Accumulated Deficiency 
double ann_pba_pba_def_accum(int t);

// Direct Capital Gains 
double ann_pba_pba_direct_cap_gain(int t);

// Direct Cash Flow 
double ann_pba_pba_direct_cash_flow(int t);

// Direct Cash Flow Interest 
double ann_pba_pba_direct_cash_flow_int(int t);

// Direct IMR Increase 
double ann_pba_pba_direct_imr_incr(int t);

// Direct Investment Income 
double ann_pba_pba_direct_inv_inc(int t);

// Direct Profit 
double ann_pba_pba_direct_prof(int t);

// Direct Reserve Increase 
double ann_pba_pba_direct_res_incr(int t);

// Direct Tax 
double ann_pba_pba_direct_tax(int t);

// Discount Rate Accumulation 
double ann_pba_pba_disc_rate_accum(int t);

// Discount Rate Monthly 
double ann_pba_pba_disc_rate_mthly(int t);

// Effective Capital Gains Rate 
double ann_pba_pba_eff_cap_gains_rate(int t);

// Hedge Cash Flow 
double ann_pba_pba_hedge_cash_flow(int t);

// Hedging Cost 
double ann_pba_pba_hedge_cost(int t);

// Hedge Market Value 
double ann_pba_pba_hedge_mkt_val(int t);

// Hedge Market Value Increase 
double ann_pba_pba_hedge_mkt_val_incr(int t);

// Hedging e Factor 
double ann_pba_pba_hedging_e_factor(int t);

// IMR 
double ann_pba_pba_imr(int t);

// IMR Increase 
double ann_pba_pba_imr_incr(int t);

// Initialize 
double ann_pba_pba_initialize(int t);

// Investment Income 
double ann_pba_pba_inv_inc(int t);

// Pre Tax IMR Adjustment Factor 
double ann_pba_pba_pimr_adj_factor(int t);

// Realized Capital Gain 
double ann_pba_pba_realzd_cap_gain(int t);

// Realized Capital Gain Before Sales 
double ann_pba_pba_realzd_cap_gain_bef_sale(int t);

// Reinsurance Capital Gains 
double ann_pba_pba_reins_cap_gain(int t);

// Reinsurance Cash Flow 
double ann_pba_pba_reins_cash_flow(int t);

// Reinsurance Cash Flow Interest 
double ann_pba_pba_reins_cash_flow_int(int t);

// Reinsurance Cost 
double ann_pba_pba_reins_cost(int t);

// Reinsurance IMR Increase 
double ann_pba_pba_reins_imr_incr(int t);

// Reinsurance Investment Income 
double ann_pba_pba_reins_inv_inc(int t);

// Reinsurance Reserve 
double ann_pba_pba_reins_res(int t);

// Reinsurance Reserve Increase 
double ann_pba_pba_reins_res_incr(int t);

// Reinsurance Tax Res 
double ann_pba_pba_reins_tax_res(int t);

// Reinsurance Tax Reserve Increase 
double ann_pba_pba_reins_tax_res_incr(int t);

// Scenario Amount 
double ann_pba_pba_scen_amt(int t);

// Scenario Greatest Present Value 
double ann_pba_pba_scen_greatest_pv(int t);

// Starting Assets 
double ann_pba_pba_starting_assets(int t);

// Startup 
virtual double virtual_startup(int t);

// Stochastic Amount 
double ann_pba_pba_stoch_amt(int t);

// Tax 
double ann_pba_pba_tax(int t);

// Tax Adjustment Ratio 
double ann_pba_pba_tax_adj_ratio(int t);

// Tax Capitalized Premium 
double ann_pba_pba_tax_capzd_prem(int t);

// Tax Capitalized Premium Amortization 
double ann_pba_pba_tax_capzd_prem_amortzn(int t);

// Tax Cash Flow 
double ann_pba_pba_tax_cash_flow(int t);

// Tax Cash Flow Before Sales 
double ann_pba_pba_tax_cash_flow_bef_sale(int t);

// Tax Res 
double ann_pba_pba_tax_res(int t);

// Tax Reserve Increase 
double ann_pba_pba_tax_res_incr(int t);

// Tax Year to Date 
double ann_pba_pba_tax_ytd(int t);

// Tax Year to Date Before Sales 
double ann_pba_pba_tax_ytd_bef_sale(int t);

// Taxable Income 
double ann_pba_pba_taxable_inc(int t);

// Taxable Income Before Sales 
double ann_pba_pba_taxable_inc_bef_sale(int t);

// Taxable Income Year to Date 
double ann_pba_pba_taxable_inc_ytd(int t);

// Taxable Income Year to Date Before Sales 
double ann_pba_pba_taxable_inc_ytd_bef_sale(int t);

// Working Reserve 
double ann_pba_pba_working_res(int t);

// CTE Percentage 
double  ann_pba_pba_cte_pct();

// Discount Scenario Rate Multiple 
double  ann_pba_pba_disc_rate_mult_fixed();

// Final Period 
int  ann_pba_pba_final_period();

// Hedging Flag 
int  ann_pba_pba_hedging_flag();

// Hedging Output File Best Estimate 
xstring  ann_pba_pba_hedging_output_file_best_estimate();

// Hedging Output File Existing Hedges 
xstring  ann_pba_pba_hedging_output_file_existing_hedges();

// Hedging Statutory Scale Factor Max 
double  ann_pba_pba_hedging_stat_scale_factor_max();

// Projection Date Adjusted 
xstring  ann_pba_pba_proj_date_adj();

// Projection Start Date 
int  ann_pba_pba_proj_start_date();

// Projection Start Mth 
int  ann_pba_pba_proj_start_mth();

// Projection Start Yr 
int  ann_pba_pba_proj_start_yr();

// Reinsurance Adjustment 
double  ann_pba_pba_reins_adj();

// Reinsurance Flag 
int  ann_pba_pba_reins_flag();

// Reinsurance Percent 
double  ann_pba_pba_reins_pct();

// Start Period 
int  ann_pba_pba_start_period();

// Tax Capitalized Premium Amortization Years 
int  ann_pba_pba_tax_capzd_prem_amortzn_yrs();

// Tax Flag 
int  ann_pba_pba_tax_flag();

// Valuation Results Scenario Amounts 
xstring  ann_pba_pba_valn_results_scen_amt();

// Working Reserve Definition 
int  ann_pba_pba_working_res_defn();


};
#endif
