
#ifndef __EIO_ASSET_UDF_H_
#define __EIO_ASSET_UDF_H_

#include "ModelClass\eio_asset.h"

class EIO_ASSET_UDF : public EIO_ASSET {

	friend class EIO_ASSET;

//constructor 
EIO_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: EIO_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
EIO_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : EIO_ASSET(columnCount, mocd, persObj) {}


// Accrued Income 
double eio_asset_accr_inc(int t);

// Detail Present Value Flag 
double eio_asset_asset_detail_pv_flag(int t);

// Asset Minimum Size Sale Flag 
double eio_asset_asset_min_size_sale_flag(int t);

// AVR Basic Contribution 
double eio_asset_avr_basic_contribn(int t);

// AVR Basic Contribution Before Sales 
double eio_asset_avr_basic_contribn_bef_sale(int t);

// AVR Maximum 
double eio_asset_avr_max(int t);

// AVR Maximum Before Sales 
double eio_asset_avr_max_bef_sale(int t);

// AVR Objective 
double eio_asset_avr_obj(int t);

// AVR Objective Before Sales 
double eio_asset_avr_obj_bef_sale(int t);

// AVR Realized Capital Gain 
double eio_asset_avr_realzd_cap_gain(int t);

// AVR Realized Capital Gain from Sales 
double eio_asset_avr_realzd_cap_gain_from_sale(int t);

// AVR Unrealized Capital Gain 
double eio_asset_avr_unrealzd_cap_gain(int t);

// AVR Unrealized Capital Gain Before Sales 
double eio_asset_avr_unrealzd_cap_gain_bef_sale(int t);

// AVR Unrealized Capital Gain Released on Sale 
double eio_asset_avr_unrealzd_cap_gain_released_on_sale(int t);

// Book Value 
double eio_asset_bk_val(int t);

// Book Value Before Fund Value Matching Asset Sales 
double eio_asset_bk_val_bef_fund_match_sale(int t);

// Book Value Before Negative Cash Flow Sales 
double eio_asset_bk_val_bef_neg_cash_flow_sale(int t);

// Book Value Before Rebalancing Sales 
double eio_asset_bk_val_bef_rebal_sale(int t);

// Book Value Before Sales 
double eio_asset_bk_val_bef_sale(int t);

// Book Value Plus Accrued Interest 
double eio_asset_bk_val_plus_accr_int(int t);

// Book Value Plus Accrued Interest Before Negative Cash Flow Sales 
double eio_asset_bk_val_plus_accr_int_bef_neg_cash_flow_sale(int t);

// Book Value Plus Accrued Interest Before Rebalancing Sales 
double eio_asset_bk_val_plus_accr_int_bef_rebal_sale(int t);

// Book Value Purchase 
double eio_asset_bk_val_purch(int t);

// Calendar Month 
double eio_asset_cal_mth(int t);

// Calendar Year 
double eio_asset_cal_yr(int t);

// Calendar Year Relative 
double eio_asset_cal_yr_relative(int t);

// Capital Gains Before Sales 
double eio_asset_cap_gain_bef_sale(int t);

// Capital Gains from Sales 
double eio_asset_cap_gain_from_sale(int t);

// Cash Flow 
double eio_asset_cash_flow(int t);

// Cost Basis 
double eio_asset_cost_basis(int t);

// Cost Basis Accrual 
double eio_asset_cost_basis_accrual(int t);

// Cost Basis Before Sales 
double eio_asset_cost_basis_bef_sale(int t);

// Cost Basis Increase from Appreciation 
double eio_asset_cost_basis_incr_appreciation(int t);

// Cost Basis Purchase 
double eio_asset_cost_basis_purch(int t);

// Cost Basis Sold 
double eio_asset_cost_basis_sold(int t);

// Date 
double eio_asset_date(int t);

// Duration Value 
double eio_asset_dur_val(int t);

// Finalize 
double eio_asset_finalize(int t);

// GAAP Income Book Value 
double eio_asset_gaap_inc_bk_val(int t);

// GAAP Income Unrealized Capital Gain 
double eio_asset_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Surplus Book Value 
double eio_asset_gaap_surp_bk_val(int t);

// GAAP Unrealized Capital Gain Increase 
double eio_asset_gaap_unrealzd_cap_gain_incr(int t);

// Index Units Owned 
double eio_asset_index_units_owned(int t);

// Index Units Owned Before Sales 
double eio_asset_index_units_owned_bef_sale(int t);

// Index Value 
double eio_asset_index_val(int t);

// Index Value at Expiry Anniversary 
double eio_asset_index_val_at_expiry_anniv(int t);

// Initialize 
double eio_asset_initialize(int t);

// Lookback Index Value 
double eio_asset_lookback_index_val(int t);

// Market to Book Ratio 
double eio_asset_mkt_to_bk_ratio(int t);

// Market Value 
double eio_asset_mkt_val(int t);

// Market Value Before Fund Value Matching Asset Sales 
double eio_asset_mkt_val_bef_fund_match_sale(int t);

// Market Value Before Negative Cash Flow Sales 
double eio_asset_mkt_val_bef_neg_cash_flow_sale(int t);

// Market Value Before Rebalancing Sales 
double eio_asset_mkt_val_bef_rebal_sale(int t);

// Market Value Before Sales 
double eio_asset_mkt_val_bef_sale(int t);

// Market Value Purchase 
double eio_asset_mkt_val_purch(int t);

// Market Value Sold 
double eio_asset_mkt_val_sold(int t);

// Months to Next Market Value Calculation 
double eio_asset_mths_to_next_mkt_val_calc(int t);

// Notional Amount 
double eio_asset_notional_amt(int t);

// Notional Amount Before Fund Value Matching Asset Sales 
double eio_asset_notional_amt_bef_fund_match_sale(int t);

// Notional Amount Before Negative Cash Flow Sales 
double eio_asset_notional_amt_bef_neg_cash_flow_sale(int t);

// Notional Amount Before Rebalancing Sales 
double eio_asset_notional_amt_bef_rebal_sale(int t);

// Notional Amount Before Sales 
double eio_asset_notional_amt_bef_sale(int t);

// Notional Amount Purchase 
double eio_asset_notional_amt_purch(int t);

// Notional Amount Sold 
double eio_asset_notional_amt_sold(int t);

// Option Payment 
double eio_asset_opt_pmt(int t);

// Option Value Asset Down 1 
double eio_asset_opt_val_asset_down_1(int t);

// Option Value Asset Down 1 Before Sales 
double eio_asset_opt_val_asset_down_1_bef_sale(int t);

// Option Value Asset Up 1 
double eio_asset_opt_val_asset_up_1(int t);

// Option Value Asset Up 1 Before Sales 
double eio_asset_opt_val_asset_up_1_bef_sale(int t);

// Option Value Baseline 
double eio_asset_opt_val_baseline(int t);

// Option Value Baseline Before Sale 
double eio_asset_opt_val_baseline_bef_sale(int t);

// Option Value Interest Down 1 
double eio_asset_opt_val_int_down_1(int t);

// Option Value Interest Down 1 Before Sale 
double eio_asset_opt_val_int_down_1_bef_sale(int t);

// Option Value Interest Key Rate 10 Down 1 
double eio_asset_opt_val_int_key_rate_10_down_1(int t);

// Option Value Interest Key Rate 10 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_10_down_1_bef_sale(int t);

// Option Value Interest Key Rate 10 Up 1 
double eio_asset_opt_val_int_key_rate_10_up_1(int t);

// Option Value Interest Key Rate 10 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_10_up_1_bef_sale(int t);

// Option Value Interest Key Rate 1 Down 1 
double eio_asset_opt_val_int_key_rate_1_down_1(int t);

// Option Value Interest Key Rate 1 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_1_down_1_bef_sale(int t);

// Option Value Interest Key Rate 1 Up 1 
double eio_asset_opt_val_int_key_rate_1_up_1(int t);

// Option Value Interest Key Rate 1 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_1_up_1_bef_sale(int t);

// Option Value Interest Key Rate 2 Down 1 
double eio_asset_opt_val_int_key_rate_2_down_1(int t);

// Option Value Interest Key Rate 2 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_2_down_1_bef_sale(int t);

// Option Value Interest Key Rate 2 Up 1 
double eio_asset_opt_val_int_key_rate_2_up_1(int t);

// Option Value Interest Key Rate 2 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_2_up_1_bef_sale(int t);

// Option Value Interest Key Rate 3 Down 1 
double eio_asset_opt_val_int_key_rate_3_down_1(int t);

// Option Value Interest Key Rate 3 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_3_down_1_bef_sale(int t);

// Option Value Interest Key Rate 3 Up 1 
double eio_asset_opt_val_int_key_rate_3_up_1(int t);

// Option Value Interest Key Rate 3 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_3_up_1_bef_sale(int t);

// Option Value Interest Key Rate 4 Down 1 
double eio_asset_opt_val_int_key_rate_4_down_1(int t);

// Option Value Interest Key Rate 4 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_4_down_1_bef_sale(int t);

// Option Value Interest Key Rate 4 Up 1 
double eio_asset_opt_val_int_key_rate_4_up_1(int t);

// Option Value Interest Key Rate 4 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_4_up_1_bef_sale(int t);

// Option Value Interest Key Rate 5 Down 1 
double eio_asset_opt_val_int_key_rate_5_down_1(int t);

// Option Value Interest Key Rate 5 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_5_down_1_bef_sale(int t);

// Option Value Interest Key Rate 5 Up 1 
double eio_asset_opt_val_int_key_rate_5_up_1(int t);

// Option Value Interest Key Rate 5 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_5_up_1_bef_sale(int t);

// Option Value Interest Key Rate 6 Down 1 
double eio_asset_opt_val_int_key_rate_6_down_1(int t);

// Option Value Interest Key Rate 6 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_6_down_1_bef_sale(int t);

// Option Value Interest Key Rate 6 Up 1 
double eio_asset_opt_val_int_key_rate_6_up_1(int t);

// Option Value Interest Key Rate 6 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_6_up_1_bef_sale(int t);

// Option Value Interest Key Rate 7 Down 1 
double eio_asset_opt_val_int_key_rate_7_down_1(int t);

// Option Value Interest Key Rate 7 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_7_down_1_bef_sale(int t);

// Option Value Interest Key Rate 7 Up 1 
double eio_asset_opt_val_int_key_rate_7_up_1(int t);

// Option Value Interest Key Rate 7 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_7_up_1_bef_sale(int t);

// Option Value Interest Key Rate 8 Down 1 
double eio_asset_opt_val_int_key_rate_8_down_1(int t);

// Option Value Interest Key Rate 8 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_8_down_1_bef_sale(int t);

// Option Value Interest Key Rate 8 Up 1 
double eio_asset_opt_val_int_key_rate_8_up_1(int t);

// Option Value Interest Key Rate 8 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_8_up_1_bef_sale(int t);

// Option Value Interest Key Rate 9 Down 1 
double eio_asset_opt_val_int_key_rate_9_down_1(int t);

// Option Value Interest Key Rate 9 Down 1 Before Sale 
double eio_asset_opt_val_int_key_rate_9_down_1_bef_sale(int t);

// Option Value Interest Key Rate 9 Up 1 
double eio_asset_opt_val_int_key_rate_9_up_1(int t);

// Option Value Interest Key Rate 9 Up 1 Before Sale 
double eio_asset_opt_val_int_key_rate_9_up_1_bef_sale(int t);

// Option Value Interest Up 1 
double eio_asset_opt_val_int_up_1(int t);

// Option Value Interest Up 1 Before Sale 
double eio_asset_opt_val_int_up_1_bef_sale(int t);

// Option Value Volatility Down 1 
double eio_asset_opt_val_vol_down_1(int t);

// Option Value Volatility Down 1 Before Sales 
double eio_asset_opt_val_vol_down_1_bef_sale(int t);

// Option Value Volatility Term 1 Down 1 
double eio_asset_opt_val_vol_term_1_down_1(int t);

// Option Value Volatility Term 1 Down 1 Before Sales 
double eio_asset_opt_val_vol_term_1_down_1_bef_sale(int t);

// Option Value Volatility Term 1 Up 1 
double eio_asset_opt_val_vol_term_1_up_1(int t);

// Option Value Volatility Term 1 Up 1 Before Sales 
double eio_asset_opt_val_vol_term_1_up_1_bef_sale(int t);

// Option Value Volatility Term 2 Down 1 
double eio_asset_opt_val_vol_term_2_down_1(int t);

// Option Value Volatility Term 2 Down 1 Before Sales 
double eio_asset_opt_val_vol_term_2_down_1_bef_sale(int t);

// Option Value Volatility Term 1 Up 1 
double eio_asset_opt_val_vol_term_2_up_1(int t);

// Option Value Volatility Term 2 Up 1 Before Sales 
double eio_asset_opt_val_vol_term_2_up_1_bef_sale(int t);

// Option Value Volatility Term 3 Down 1 
double eio_asset_opt_val_vol_term_3_down_1(int t);

// Option Value Volatility Term 3 Down 1 Before Sales 
double eio_asset_opt_val_vol_term_3_down_1_bef_sale(int t);

// Option Value Volatility Term 3 Up 1 
double eio_asset_opt_val_vol_term_3_up_1(int t);

// Option Value Volatility Term 3 Up 1 Before Sales 
double eio_asset_opt_val_vol_term_3_up_1_bef_sale(int t);

// Option Value Volatility Up 1 
double eio_asset_opt_val_vol_up_1(int t);

// Option Value Volatility Up 1 Before Sales 
double eio_asset_opt_val_vol_up_1_bef_sale(int t);

// Risk Based Capital C1 
double eio_asset_rbc_c1(int t);

// Risk Based Capital C1 Before Sales 
double eio_asset_rbc_c1_bef_sale(int t);

// Realized Capital Gain 
double eio_asset_realzd_cap_gain(int t);

// Realized Capital Gain from Option Payment 
double eio_asset_realzd_cap_gain_opt_pmt(int t);

// Realized Capital Gain from Sales 
double eio_asset_realzd_cap_gain_sale(int t);

// Sold Percent 
double eio_asset_sold_pct(int t);

// Sold Percent Fund Value Matching 
double eio_asset_sold_pct_fund_match(int t);

// Sold Percent Negative Cash Flow 
double eio_asset_sold_pct_neg_cash_flow(int t);

// Sold Percent Planned 
double eio_asset_sold_pct_planned(int t);

// Sold Percent Rebalancing 
double eio_asset_sold_pct_rebal(int t);

// Spot Spread Adjustment 
double eio_asset_spot_sprd_adj(int t);

// Startup 
virtual double virtual_startup(int t);

// Asset Sub Portfolio Identification 
double eio_asset_sub_port_id(int t);

// Unrealized Capital Gain 
double eio_asset_unrealzd_cap_gain(int t);

// Unrealized Capital Gain Before Fund Value Matching Asset Sales 
double eio_asset_unrealzd_cap_gain_bef_fund_match_sale(int t);

// Unrealized Capital Gain Before Negative Cash Flow Sales 
double eio_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t);

// Unrealized Capital Gain Before Rebalancing Sales 
double eio_asset_unrealzd_cap_gain_bef_rebal_sale(int t);

// Unrealized Capital Gain Before Sales 
double eio_asset_unrealzd_cap_gain_bef_sale(int t);

// Unrealized Capital Gain GAAP Surplus 
double eio_asset_unrealzd_cap_gain_gaap_surp(int t);

// Unrealized Capital Gain Increase 
double eio_asset_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Released on Sale 
double eio_asset_unrealzd_cap_gain_released_on_sale(int t);

// Unrealized Capital Gain to Book Ratio 
double eio_asset_unrealzd_cap_gain_to_bk_ratio(int t);

// Volatility Spread Adjustment 
double eio_asset_volatility_sprd_adj(int t);

// Yield Denominator 
double eio_asset_yld_denom(int t);

// Yield Numerator 
double eio_asset_yld_numer(int t);

// Detail Report Flag 
int  eio_asset_asset_detail_rpt_flag();

// Asset Fund Index 
int  eio_asset_asset_fund_index();

// Book Value Before Expiry 
double  eio_asset_bk_val_bef_expiry();

// Commencement Period 
int  eio_asset_commencement_period();

// Cost Basis Before Expiry 
double  eio_asset_cost_basis_bef_expiry();

// Data Group Identification 
xstring  eio_asset_data_grp_id();

// Existing Asset Indicator 
int  eio_asset_existing_asset_indicator();

// GAAP Income Definition 
int  eio_asset_gaap_inc_defn();

// GAAP Value Definition 
int  eio_asset_gaap_val_defn();

// Initial Market Value Calculated 
double  eio_asset_init_mkt_val_calc();

// Lookback Months 
int  eio_asset_lookback_mths();

// Lookback Sampling Months 
int  eio_asset_lookback_sampling_mths();

// Maturity Period 
int  eio_asset_maturity_period();

// Market Value at Issue 
double  eio_asset_mkt_val_at_issue();

// Market Value Before Expiry 
double  eio_asset_mkt_val_bef_expiry();

// Negative Asset Flag 
double  eio_asset_neg_asset_flag();

// Notional Amount at Issue 
double  eio_asset_notional_amt_at_issue();

// Percent to Use 
double  eio_asset_pct_to_use();

// Planned Sale Period 
int  eio_asset_planned_sale_period();

// Projection Date Adjusted 
xstring  eio_asset_proj_date_adj();

// Projection Start Date 
int  eio_asset_proj_start_date();

// Projection Start Mth 
int  eio_asset_proj_start_mth();

// Projection Start Yr 
int  eio_asset_proj_start_yr();

// Sale Class Identification 
int  eio_asset_sale_class_id();

// Segment Number 
int  eio_asset_seg_num();

// Start Period 
int  eio_asset_start_period();


};
#endif
