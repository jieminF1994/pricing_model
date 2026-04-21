
#ifndef __EPA_ASSET_UDF_H_
#define __EPA_ASSET_UDF_H_

#include "ModelClass\epa_asset.h"

class EPA_ASSET_UDF : public EPA_ASSET {

	friend class EPA_ASSET;

//constructor 
EPA_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: EPA_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
EPA_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : EPA_ASSET(columnCount, mocd, persObj) {}


// Accrued Income 
double epa_asset_accr_inc(int t);

// Accrued Interest 
double epa_asset_accr_int(int t);

// Accrued Interest After Defaults 
double epa_asset_accr_int_aft_dflt(int t);

// Accrued Interest Before Fund Value Matching Asset Sales 
double epa_asset_accr_int_bef_fund_match_sale(int t);

// Accrued Interest Before Negative Cash Flow Sales 
double epa_asset_accr_int_bef_neg_cash_flow_sale(int t);

// Accrued Interest Before Rebalancing Sales 
double epa_asset_accr_int_bef_rebal_sale(int t);

// Accrued Interest Before Sales 
double epa_asset_accr_int_bef_sale(int t);

// Accrued Interest Defaults 
double epa_asset_accr_int_dflt(int t);

// Accrued Interest Rent 
double epa_asset_accr_int_rent(int t);

// Accrued Interest Sold 
double epa_asset_accr_int_sold(int t);

// Asset Minimum Size Sale Flag 
double epa_asset_asset_min_size_sale_flag(int t);

// AVR Basic Contribution 
double epa_asset_avr_basic_contribn(int t);

// AVR Basic Contribution Before Sales 
double epa_asset_avr_basic_contribn_bef_sale(int t);

// AVR Maximum 
double epa_asset_avr_max(int t);

// AVR Maximum Before Sales 
double epa_asset_avr_max_bef_sale(int t);

// AVR Objective 
double epa_asset_avr_obj(int t);

// AVR Objective Before Sales 
double epa_asset_avr_obj_bef_sale(int t);

// AVR Realized Capital Gain 
double epa_asset_avr_realzd_cap_gain(int t);

// Book Value 
double epa_asset_bk_val(int t);

// Book Value Before Fund Value Matching Asset Sales 
double epa_asset_bk_val_bef_fund_match_sale(int t);

// Book Value Before Negative Cash Flow Sales 
double epa_asset_bk_val_bef_neg_cash_flow_sale(int t);

// Book Value Before Rebalancing Sales 
double epa_asset_bk_val_bef_rebal_sale(int t);

// Book Value Before Sales 
double epa_asset_bk_val_bef_sale(int t);

// Book Value Plus Accrued Interest Before Rebalancing Sales 
double epa_asset_bk_val_plus_accr_int_bef_rebal_sale(int t);

// Calendar Month 
double epa_asset_cal_mth(int t);

// Calendar Year 
double epa_asset_cal_yr(int t);

// Calendar Year Relative 
double epa_asset_cal_yr_relative(int t);

// Capital Gains Before Sales 
double epa_asset_cap_gain_bef_sale(int t);

// Capital Gains from Sales 
double epa_asset_cap_gain_from_sale(int t);

// Cash Flow 
double epa_asset_cash_flow(int t);

// Cost Basis 
double epa_asset_cost_basis(int t);

// Cost Basis Accrual 
double epa_asset_cost_basis_accrual(int t);

// Cost Basis After Defaults 
double epa_asset_cost_basis_aft_dflt(int t);

// Cost Basis Before Sales 
double epa_asset_cost_basis_bef_sale(int t);

// Cost Basis Default 
double epa_asset_cost_basis_dflt(int t);

// Cost Basis Sold 
double epa_asset_cost_basis_sold(int t);

// Date 
double epa_asset_date(int t);

// Default Amount 
double epa_asset_dflt_amt(int t);

// Default Percent 
double epa_asset_dflt_pct(int t);

// Duration Value 
double epa_asset_dur_val(int t);

// Effective Duration 
double epa_asset_eff_dur(int t);

// Externally Projected Assets Percent Remaining 
double epa_asset_epa_pct_remaining(int t);

// Finalize 
double epa_asset_finalize(int t);

// GAAP Income Book Value 
double epa_asset_gaap_inc_bk_val(int t);

// GAAP Income Unrealized Capital Gain 
double epa_asset_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Surplus Book Value 
double epa_asset_gaap_surp_bk_val(int t);

// GAAP Unrealized Capital Gain Increase 
double epa_asset_gaap_unrealzd_cap_gain_incr(int t);

// Interest Maintenance Reserve Realized Capital Gain 
double epa_asset_imr_realzd_cap_gain(int t);

// Interest Maintenance Reserve Realized Capital Gains from Sales 
double epa_asset_imr_realzd_cap_gain_from_sale(int t);

// Interest Maintenance Reserve Years to Maturity 
double epa_asset_imr_yrs_to_maturity(int t);

// Initialize 
double epa_asset_initialize(int t);

// Interest Dividend and Rent 
double epa_asset_int_div_and_rent(int t);

// Interest Payment 
double epa_asset_int_pmt(int t);

// Market to Book Ratio 
double epa_asset_mkt_to_bk_ratio(int t);

// Market Value 
double epa_asset_mkt_val(int t);

// Market Value Before Fund Value Matching Asset Sales 
double epa_asset_mkt_val_bef_fund_match_sale(int t);

// Market Value Before Negative Cash Flow Sales 
double epa_asset_mkt_val_bef_neg_cash_flow_sale(int t);

// Market Value Before Rebalancing Sales 
double epa_asset_mkt_val_bef_rebal_sale(int t);

// Market Value Before Sales 
double epa_asset_mkt_val_bef_sale(int t);

// Market Value for Duration Before Negative Cash Flow Sales 
double epa_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t);

// Market Value for Duration Before Rebalancing Sales 
double epa_asset_mkt_val_for_dur_bef_rebal_sale(int t);

// Market Value for Duration Sold 
double epa_asset_mkt_val_for_dur_sold(int t);

// Market Value for Effective Duration 
double epa_asset_mkt_val_for_eff_dur(int t);

// Market Value Sold 
double epa_asset_mkt_val_sold(int t);

// Market Value Times Duration Before Negative Cash Flow Sales 
double epa_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t);

// Market Value Times Duration Before Rebalancing Sales 
double epa_asset_mkt_val_times_dur_bef_rebal_sale(int t);

// Market Value Times Effective Duration 
double epa_asset_mkt_val_times_eff_dur(int t);

// Notional Amount 
double epa_asset_notional_amt(int t);

// Notional Amount Before Fund Value Matching Asset Sales 
double epa_asset_notional_amt_bef_fund_match_sale(int t);

// Notional Amount Before Negative Cash Flow Sales 
double epa_asset_notional_amt_bef_neg_cash_flow_sale(int t);

// Notional Amount Before Rebalancing Sales 
double epa_asset_notional_amt_bef_rebal_sale(int t);

// Notional Amount Before Sales 
double epa_asset_notional_amt_bef_sale(int t);

// Option Income 
double epa_asset_opt_inc(int t);

// Option Payment 
double epa_asset_opt_pmt(int t);

// Risk Based Capital C1 
double epa_asset_rbc_c1(int t);

// Risk Based Capital C1 Before Sales 
double epa_asset_rbc_c1_bef_sale(int t);

// Realized Capital Gain 
double epa_asset_realzd_cap_gain(int t);

// Realized Capital Gain from Option Payment 
double epa_asset_realzd_cap_gain_opt_pmt(int t);

// Realized Capital Gain from Sales 
double epa_asset_realzd_cap_gain_sale(int t);

// Realized Capital Loss from Default 
double epa_asset_realzd_cap_loss_dflt(int t);

// Remaining Percent After Defaults 
double epa_asset_remaining_pct_aft_dflt(int t);

// Scheduled Principal Payment 
double epa_asset_sched_prin_pmt(int t);

// Sold Percent 
double epa_asset_sold_pct(int t);

// Sold Percent Fund Value Matching 
double epa_asset_sold_pct_fund_match(int t);

// Sold Percent Negative Cash Flow 
double epa_asset_sold_pct_neg_cash_flow(int t);

// Sold Percent Planned 
double epa_asset_sold_pct_planned(int t);

// Sold Percent Rebalancing 
double epa_asset_sold_pct_rebal(int t);

// Startup 
virtual double virtual_startup(int t);

// Asset Sub Portfolio Identification 
double epa_asset_sub_port_id(int t);

// Tax Exempt Income 
double epa_asset_tax_exempt_inc(int t);

// Unrealized Capital Gain 
double epa_asset_unrealzd_cap_gain(int t);

// Unrealized Capital Gain Before Fund Value Matching Asset Sales 
double epa_asset_unrealzd_cap_gain_bef_fund_match_sale(int t);

// Unrealized Capital Gain Before Negative Cash Flow Sales 
double epa_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t);

// Unrealized Capital Gain Before Rebalancing Sales 
double epa_asset_unrealzd_cap_gain_bef_rebal_sale(int t);

// Unrealized Capital Gain Before Sales 
double epa_asset_unrealzd_cap_gain_bef_sale(int t);

// Unrealized Capital Gain GAAP Surplus 
double epa_asset_unrealzd_cap_gain_gaap_surp(int t);

// Unrealized Capital Gain Increase 
double epa_asset_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Released on Sale 
double epa_asset_unrealzd_cap_gain_released_on_sale(int t);

// Unrealized Capital Gain to Book Ratio 
double epa_asset_unrealzd_cap_gain_to_bk_ratio(int t);

// Weighted Average Life 
double epa_asset_weighted_avg_life(int t);

// Yield Denominator 
double epa_asset_yld_denom(int t);

// Yield Numerator 
double epa_asset_yld_numer(int t);

// Asset Fund Index 
int  epa_asset_asset_fund_index();

// Commencement Period 
int  epa_asset_commencement_period();

// Data Group Identification 
xstring  epa_asset_data_grp_id();

// GAAP Income Definition 
int  epa_asset_gaap_inc_defn();

// GAAP Value Definition 
int  epa_asset_gaap_val_defn();

// Maturity Period 
int  epa_asset_maturity_period();

// Negative Asset Flag 
int  epa_asset_neg_asset_flag();

// Percent to Use 
double  epa_asset_pct_to_use();

// Planned Sale Period 
int  epa_asset_planned_sale_period();

// Projection Date Adjusted 
xstring  epa_asset_proj_date_adj();

// Projection Date Offset 
int  epa_asset_proj_date_offset();

// Projection Start Date 
int  epa_asset_proj_start_date();

// Projection Start Mth 
int  epa_asset_proj_start_mth();

// Projection Start Yr 
int  epa_asset_proj_start_yr();

// Sale Class Identification 
int  epa_asset_sale_class_id();

// Segment Number 
int  epa_asset_seg_num();

// Start Period 
int  epa_asset_start_period();


};
#endif
