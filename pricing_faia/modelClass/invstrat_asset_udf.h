
#ifndef __INVSTRAT_ASSET_UDF_H_
#define __INVSTRAT_ASSET_UDF_H_

#include "ModelClass\invstrat_asset.h"

class INVSTRAT_ASSET_UDF : public INVSTRAT_ASSET {

	friend class INVSTRAT_ASSET;

//constructor 
INVSTRAT_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: INVSTRAT_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
INVSTRAT_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : INVSTRAT_ASSET(columnCount, mocd, persObj) {}


// Calendar Month 
double invstrat_asset_cal_mth(int t);

// Calendar Year 
double invstrat_asset_cal_yr(int t);

// Calendar Year Relative 
double invstrat_asset_cal_yr_relative(int t);

// Cash 
double invstrat_asset_cash(int t);

// Cash Flow for Asset Purchases 
double invstrat_asset_cash_flow_for_asset_purch(int t);

// Cash Flow for Investment 
double invstrat_asset_cash_flow_for_inv(int t);

// Cash Flow for Investment Before Rebalancing 
double invstrat_asset_cash_flow_for_inv_bef_rebal(int t);

// Cash Flow Hedge Sales 
double invstrat_asset_cash_flow_hedge_sale(int t);

// Cash Flow Planned Sales 
double invstrat_asset_cash_flow_planned_sale(int t);

// Cash Flow Rebalancing 
double invstrat_asset_cash_flow_rebal(int t);

// Cash Flow Rebalancing Estimate 
double invstrat_asset_cash_flow_rebal_estimate(int t);

// Cash Increase 
double invstrat_asset_cash_incr(int t);

// Cash from Investemnt Asset Sales Net 
double invstrat_asset_cash_investment_sale_net(int t);

// Cash from INvestment Asset Sales Net Preliminary 
double invstrat_asset_cash_investment_sale_net_prelim(int t);

// Cash Net Negative Cash Flow Sales 
double invstrat_asset_cash_net_neg_cash_flow_sale(int t);

// Date 
double invstrat_asset_date(int t);

// Duration Before Match 
double invstrat_asset_dur_bef_match(int t);

// Duration Final Portfolio 
double invstrat_asset_dur_final_port(int t);

// Duration Matching Flag 
double invstrat_asset_dur_match_flag(int t);

// Duration Matching Target 
double invstrat_asset_dur_match_tgt(int t);

// Duration Matching Tolerance 
double invstrat_asset_dur_match_tolerance(int t);

// Finalize 
double invstrat_asset_finalize(int t);

// Foreclosure Book Value Net Write Down 
double invstrat_asset_foreclosure_bk_val_net_write_down(int t);

// Foreclosure Book Value Net Write Down Negative Asset 
double invstrat_asset_foreclosure_bk_val_net_write_down_neg_asset(int t);

// Foreclosure Cost Basis Net Write Down 
double invstrat_asset_foreclosure_cost_basis_net_write_down(int t);

// Foreclosure Cost Basis Net Write Down Negative Asset 
double invstrat_asset_foreclosure_cost_basis_net_write_down_neg_asset(int t);

// Foreclosure Principal Net Write Down 
double invstrat_asset_foreclosure_prin_net_write_down(int t);

// Foreclosure Principal Net Write Down Negative Asset 
double invstrat_asset_foreclosure_prin_net_write_down_neg_asset(int t);

// Initialize 
double invstrat_asset_initialize(int t);

// Initialize Sale and Investment Variables End of Month 
double invstrat_asset_initialize_sale_and_inv_vars_eom(int t);

// Initialize Asset Sub Portfolio Sales Variables End of Month 
double invstrat_asset_initialize_sub_port_sale_vars_eom(int t);

// Interim Cash 
double invstrat_asset_interim_cash(int t);

// Investment Amount 
double invstrat_asset_inv_amt(int t);

// Investment Deficit 
double invstrat_asset_inv_deficit(int t);

// Investment End of Month Flag 
double invstrat_asset_inv_eom_flag(int t);

// Investable Assets Before Rebalancing 
double invstrat_asset_investable_assets_bef_rebal(int t);

// Market Value for Duration Before Duration Matching 
double invstrat_asset_mkt_val_for_dur_bef_dur_match(int t);

// Market Value Purchase for Duration Matching 
double invstrat_asset_mkt_val_purch_for_dur_match(int t);

// Market Value Sale 
double invstrat_asset_mkt_val_sale(int t);

// Market Value Sale for Duration Matching 
double invstrat_asset_mkt_val_sale_for_dur_match(int t);

// Market Value Times Duration Before Duration Matching 
double invstrat_asset_mkt_val_times_dur_bef_dur_match(int t);

// Months to Rebalancing 
double invstrat_asset_mths_to_rebal(int t);

// Refinance Book Value 
double invstrat_asset_refinance_bk_val(int t);

// Refinance Book Value on Negative Assets 
double invstrat_asset_refinance_bk_val_neg_assets(int t);

// Refinance Cost Basis 
double invstrat_asset_refinance_cost_basis(int t);

// Refinance Cost Basis on Negative Asset 
double invstrat_asset_refinance_cost_basis_neg_asset(int t);

// Refinance Principal 
double invstrat_asset_refinance_prin(int t);

// Refinance Principal on Negative Asset 
double invstrat_asset_refinance_prin_neg_asset(int t);

// Restructure Book Value Net Write Down 
double invstrat_asset_restructure_bk_val_net_write_down(int t);

// Restructure Book Value Net Write Down Negative Asset 
double invstrat_asset_restructure_bk_val_net_write_down_neg_asset(int t);

// Restructure Cost Basis Net Write Down 
double invstrat_asset_restructure_cost_basis_net_write_down(int t);

// Restructure Cost Basis Net Write Down Negative Asset 
double invstrat_asset_restructure_cost_basis_net_write_down_neg_asset(int t);

// Restructure Principal Net Write Down 
double invstrat_asset_restructure_prin_net_write_down(int t);

// Restructure Principal Net Write Down Negative Asset 
double invstrat_asset_restructure_prin_net_write_down_neg_asset(int t);

// Sale Planned Or Minimum Size Flag 
double invstrat_asset_sale_planned_or_min_size_flag(int t);

// Sale Possible Interest Maintenance Reserve Asset Valuation Reserve Flag 
double invstrat_asset_sale_possible_imr_avr_flag(int t);

// Startup 
virtual double virtual_startup(int t);

// Use Duration Matching Strategy 
double invstrat_asset_use_dur_match_strat(int t);

// Final Period 
int  invstrat_asset_final_period();

// Foreclosure Asset Identification 
int  invstrat_asset_foreclosure_asset_id();

// Projection Date Adjusted 
xstring  invstrat_asset_proj_date_adj();

// Projection Start Date 
int  invstrat_asset_proj_start_date();

// Projection Start Mth 
int  invstrat_asset_proj_start_mth();

// Projection Start Yr 
int  invstrat_asset_proj_start_yr();

// Rebalance Sales Priority Class Maximum 
int  invstrat_asset_rebal_sales_priority_class_max();

// Refinance Asset Identification 
int  invstrat_asset_refinance_asset_id();

// Restructure Asset Identification 
int  invstrat_asset_restructure_asset_id();

// Sales Priority Sub Portfolio Maximum 
int  invstrat_asset_sales_priority_sub_port_max();

// Segment Number 
int  invstrat_asset_seg_num();

// Start Period 
int  invstrat_asset_start_period();


};
#endif
