
#ifndef __BOND_ASSET_UDF_H_
#define __BOND_ASSET_UDF_H_

#include "ModelClass\bond_asset.h"

class BOND_ASSET_UDF : public BOND_ASSET {

	friend class BOND_ASSET;

//constructor 
BOND_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: BOND_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
BOND_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : BOND_ASSET(columnCount, mocd, persObj) {}


// Accrued Income 
double bond_asset_accr_inc(int t);

// Accrued Interest 
double bond_asset_accr_int(int t);

// Accrued Interest After Defaults 
double bond_asset_accr_int_aft_dflt(int t);

// Accrued Interest After Puts 
double bond_asset_accr_int_aft_put(int t);

// Accrued Interest Before Call 
double bond_asset_accr_int_bef_call(int t);

// Accrued Interest Before Fund Value Matching Asset Sales 
double bond_asset_accr_int_bef_fund_match_sale(int t);

// Accrued Interest Before Negative Cash Flow Sales 
double bond_asset_accr_int_bef_neg_cash_flow_sale(int t);

// Accrued Interest Before Rebalancing Sales 
double bond_asset_accr_int_bef_rebal_sale(int t);

// Accrued Interest Before Sales 
double bond_asset_accr_int_bef_sale(int t);

// Accrued Interest Defaults 
double bond_asset_accr_int_dflt(int t);

// Accrued Interest Purchase 
double bond_asset_accr_int_purch(int t);

// Accrued Interest Rent 
double bond_asset_accr_int_rent(int t);

// Accrued Interest Sold 
double bond_asset_accr_int_sold(int t);

// Asset Detail Report Present Value Flag 
double bond_asset_asset_detail_rpt_pv_flag(int t);

// Asset Minimum Size Sale Flag 
double bond_asset_asset_min_size_sale_flag(int t);

// AVR Basic Contribution 
double bond_asset_avr_basic_contribn(int t);

// AVR Basic Contribution Before Sales 
double bond_asset_avr_basic_contribn_bef_sale(int t);

// AVR Maximum 
double bond_asset_avr_max(int t);

// AVR Maximum Before Sales 
double bond_asset_avr_max_bef_sale(int t);

// AVR Objective 
double bond_asset_avr_obj(int t);

// AVR Objective Before Sales 
double bond_asset_avr_obj_bef_sale(int t);

// AVR Realized Capital Gain 
double bond_asset_avr_realzd_cap_gain(int t);

// Base Income Before Call 
double bond_asset_base_inc_bef_call(int t);

// Book Value 
double bond_asset_bk_val(int t);

// Book Value After Defaults 
double bond_asset_bk_val_aft_dflt(int t);

// Book Value After Puts 
double bond_asset_bk_val_aft_put(int t);

// Book Value Before Call 
double bond_asset_bk_val_bef_call(int t);

// Book Value Before Fund Value Matching Asset Sales 
double bond_asset_bk_val_bef_fund_match_sale(int t);

// Book Value Before Negative Cash Flow Sales 
double bond_asset_bk_val_bef_neg_cash_flow_sale(int t);

// Book Value Before Rebalancingt Sales 
double bond_asset_bk_val_bef_rebal_sale(int t);

// Book Value Before Sales 
double bond_asset_bk_val_bef_sale(int t);

// Book Value Plus Accrued Interest Before Rebalancing Sales 
double bond_asset_bk_val_plus_accr_int_bef_rebal_sale(int t);

// Book Value Purchase 
double bond_asset_bk_val_purch(int t);

// Calendar Month 
double bond_asset_cal_mth(int t);

// Calendar Year 
double bond_asset_cal_yr(int t);

// Calendar Year Relative 
double bond_asset_cal_yr_relative(int t);

// Capital Gains Before Sales 
double bond_asset_cap_gain_bef_sale(int t);

// Capital Gains from Sales 
double bond_asset_cap_gain_from_sale(int t);

// Cash Flow 
double bond_asset_cash_flow(int t);

// Cost Basis 
double bond_asset_cost_basis(int t);

// Cost Basis Accrual 
double bond_asset_cost_basis_accrual(int t);

// Cost Basis After Defaults 
double bond_asset_cost_basis_aft_dflt(int t);

// Cost Basis After Puts 
double bond_asset_cost_basis_aft_put(int t);

// Cost Basis Before Call 
double bond_asset_cost_basis_bef_call(int t);

// Cost Basis Before Sales 
double bond_asset_cost_basis_bef_sale(int t);

// Cost Basis Default 
double bond_asset_cost_basis_dflt(int t);

// Cost Basis Increase from Appreciation 
double bond_asset_cost_basis_incr_appreciation(int t);

// Cost Basis Purchase 
double bond_asset_cost_basis_purch(int t);

// Cost Basis Scheduled Principal Payment 
double bond_asset_cost_basis_sched_prin_pmt(int t);

// Cost Basis Sold 
double bond_asset_cost_basis_sold(int t);

// Date 
double bond_asset_date(int t);

// Default Amount 
double bond_asset_dflt_amt(int t);

// Default Percent 
double bond_asset_dflt_pct(int t);

// Duration Value 
double bond_asset_dur_val(int t);

// Effective Duration 
double bond_asset_eff_dur(int t);

// Finalize 
double bond_asset_finalize(int t);

// GAAP Income Book Value 
double bond_asset_gaap_inc_bk_val(int t);

// GAAP Income Unrealized Capital Gain 
double bond_asset_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Surplus Book Value 
double bond_asset_gaap_surp_bk_val(int t);

// GAAP Unrealized Capital Gain Increase 
double bond_asset_gaap_unrealzd_cap_gain_incr(int t);

// Interest Maintenance Reserve Realized Capital Gain 
double bond_asset_imr_realzd_cap_gain(int t);

// Interest Maintenance Reserve Realized Capital Gains from Sales 
double bond_asset_imr_realzd_cap_gain_from_sale(int t);

// Interest Maintenance Reserve Years to Maturity 
double bond_asset_imr_yrs_to_maturity(int t);

// Initialize 
double bond_asset_initialize(int t);

// Interest Dividend and Rent 
double bond_asset_int_div_and_rent(int t);

// Interest Payment 
double bond_asset_int_pmt(int t);

// Market Risk Spread 
double bond_asset_mkt_risk_sprd(int t);

// Market Spread 
double bond_asset_mkt_sprd(int t);

// Market to Book Ratio 
double bond_asset_mkt_to_bk_ratio(int t);

// Market Value 
double bond_asset_mkt_val(int t);

// Market Value Before Fund Value Matching Asset Sales 
double bond_asset_mkt_val_bef_fund_match_sale(int t);

// Market Value Before Negative Cash Flow Sales 
double bond_asset_mkt_val_bef_neg_cash_flow_sale(int t);

// Market Value Before Rebalancing Sales 
double bond_asset_mkt_val_bef_rebal_sale(int t);

// Market Value Before Sales 
double bond_asset_mkt_val_bef_sale(int t);

// Market Value for Duration Before Negative Cash Flow Sales 
double bond_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t);

// Market Value for Duration Before Rebalancing Sales 
double bond_asset_mkt_val_for_dur_bef_rebal_sale(int t);

// Market Value for Duration Sold 
double bond_asset_mkt_val_for_dur_sold(int t);

// Market Value for Effective Duration 
double bond_asset_mkt_val_for_eff_dur(int t);

// Market Value Purchase 
double bond_asset_mkt_val_purch(int t);

// Market Value Shifted 
double bond_asset_mkt_val_shifted(int t);

// Market Value Sold 
double bond_asset_mkt_val_sold(int t);

// Market Value Times Duration Before Negative Cash Flow Sales 
double bond_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t);

// Market Value Times Duration Before Rebalancing Sales 
double bond_asset_mkt_val_times_dur_bef_rebal_sale(int t);

// Market Value Times Effective Duration 
double bond_asset_mkt_val_times_eff_dur(int t);

// Months to Next Market Value Calculation 
double bond_asset_mths_to_next_mkt_val_calc(int t);

// Net Yield 
double bond_asset_net_yld(int t);

// Notional Amount 
double bond_asset_notional_amt(int t);

// Notional Amount Before Fund Value Matching Asset Sales 
double bond_asset_notional_amt_bef_fund_match_sale(int t);

// Notional Amount Before Negative Cash Flow Sales 
double bond_asset_notional_amt_bef_neg_cash_flow_sale(int t);

// Notional Amount Before Rebalancing Sales 
double bond_asset_notional_amt_bef_rebal_sale(int t);

// Notional Amount Before Sales 
double bond_asset_notional_amt_bef_sale(int t);

// Option Income 
double bond_asset_opt_inc(int t);

// Option Payment 
double bond_asset_opt_pmt(int t);

// Option Spread 
double bond_asset_opt_sprd(int t);

// Risk Based Capital C1 
double bond_asset_rbc_c1(int t);

// Risk Based Capital C1 Before Sales 
double bond_asset_rbc_c1_bef_sale(int t);

// Realized Capital Gain 
double bond_asset_realzd_cap_gain(int t);

// Realized Capital Gain from Option Payment 
double bond_asset_realzd_cap_gain_opt_pmt(int t);

// Realized Capital Gain from Sales 
double bond_asset_realzd_cap_gain_sale(int t);

// Realized Capital Loss from Default 
double bond_asset_realzd_cap_loss_dflt(int t);

// Risk Spread 
double bond_asset_risk_sprd(int t);

// Risk Spread Shifted 
double bond_asset_risk_sprd_shifted(int t);

// Scheduled Principal Payment 
double bond_asset_sched_prin_pmt(int t);

// Sinking Fund Schedule Base 
double bond_asset_sinking_fund_sch_base(int t);

// Sold Percent 
double bond_asset_sold_pct(int t);

// Sold Percent Fund Value Matching 
double bond_asset_sold_pct_fund_match(int t);

// Sold Percent Negative Cash Flow 
double bond_asset_sold_pct_neg_cash_flow(int t);

// Sold Percent Planned 
double bond_asset_sold_pct_planned(int t);

// Sold Percent Rebalancing 
double bond_asset_sold_pct_rebal(int t);

// Startup 
virtual double virtual_startup(int t);

// Asset Sub Portfolio Identification 
double bond_asset_sub_port_id(int t);

// Tax Exempt Income 
double bond_asset_tax_exempt_inc(int t);

// Unrealized Capital Gain 
double bond_asset_unrealzd_cap_gain(int t);

// Unrealized Capital Gain Before Fund Value Matching Asset Sales 
double bond_asset_unrealzd_cap_gain_bef_fund_match_sale(int t);

// Unrealized Capital Gain Before Negative Cash Flow Sales 
double bond_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t);

// Unrealized Capital Gain Before Rebalancing Sales 
double bond_asset_unrealzd_cap_gain_bef_rebal_sale(int t);

// Unrealized Capital Gain Before Sales 
double bond_asset_unrealzd_cap_gain_bef_sale(int t);

// Unrealized Capital Gain GAAP Surplus 
double bond_asset_unrealzd_cap_gain_gaap_surp(int t);

// Unrealized Capital Gain Increase 
double bond_asset_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Released on Sale 
double bond_asset_unrealzd_cap_gain_released_on_sale(int t);

// Unrealized Capital Gain to Book Ratio 
double bond_asset_unrealzd_cap_gain_to_bk_ratio(int t);

// Weighted Average Life 
double bond_asset_weighted_avg_life(int t);

// Weighted Average Life Option Sensitivity 
double bond_asset_weighted_avg_life_opt_sensitivity(int t);

// Yield Denominator 
double bond_asset_yld_denom(int t);

// Yield Numerator 
double bond_asset_yld_numer(int t);

// Yield Numerator with duration weighted adjustment 
double bond_asset_yld_numer_adj_aig(int t);

// Accrued Interest Per Par Value Unit 
double  bond_asset_accr_int_per_par_unit();

// Amortization Cost Period 
int  bond_asset_amortzn_cost_period();

// Asset Detail Report Flag 
int  bond_asset_asset_detail_rpt_flag();

// Asset Fund Index 
int  bond_asset_asset_fund_index();

// Call First Period 
int  bond_asset_call_first_period();

// Call at Par Value First Period 
int  bond_asset_call_par_first_period();

// Call Premium Grading Months 
int  bond_asset_call_prem_grading_mths();

// Call Premium Related to Coupon Rate 
double  bond_asset_call_prem_related_to_coupon_rate();

// Call Price Schedule Flag 
int  bond_asset_call_price_sch_flag();

// Commencement Period 
int  bond_asset_commencement_period();

// Coupon Rate at Issue 
double  bond_asset_coupon_rate_at_issue();

// Data File Name 
xstring  bond_asset_data_file_name();

// Data Group Identification 
xstring  bond_asset_data_grp_id();

// Existing Asset Indicator 
int  bond_asset_existing_asset_indicator();

// GAAP Income Definition 
int  bond_asset_gaap_inc_defn();

// GAAP Value Definition 
int  bond_asset_gaap_val_defn();

// Maturity Months from Next Reset 
int  bond_asset_maturity_mths_from_next_reset();

// Maturity Period 
int  bond_asset_maturity_period();

// Market Value Per Unit of Par Value 
double  bond_asset_mkt_val_per_unit_par();

// Negative Asset Flag 
int  bond_asset_neg_asset_flag();

// Net Yield at Issue 
double  bond_asset_net_yld_at_issue();

// Net Yield at Issue Flag 
int  bond_asset_net_yld_at_issue_flag();

// Percent to Use 
double  bond_asset_pct_to_use();

// Planned Sale Period 
int  bond_asset_planned_sale_period();

// Payment Frequency 
int  bond_asset_pmt_freq();

// Payment Period Months 
int  bond_asset_pmt_mths();

// Payment Rate Definition 
int  bond_asset_pmt_rate_defn();

// Payment Rate Definition 
xstring  bond_asset_pmt_rate_defn_string();

// Payment Reset first_Period 
int  bond_asset_pmt_reset_first_period();

// Projection Date Adjusted 
xstring  bond_asset_proj_date_adj();

// Projection Start Date 
int  bond_asset_proj_start_date();

// Projection Start Mth 
int  bond_asset_proj_start_mth();

// Projection Start Yr 
int  bond_asset_proj_start_yr();

// Put First Period 
int  bond_asset_put_first_period();

// Put at Par Value First Period 
int  bond_asset_put_par_first_period();

// Put Premium Grading Months 
int  bond_asset_put_prem_grading_mths();

// Put Premium Related to Coupon Rate 
double  bond_asset_put_prem_related_to_coupon_rate();

// Put Price Schedule Flag 
int  bond_asset_put_price_sch_flag();

// Refinancing Rate Definition Calculated 
int  bond_asset_refinancing_rate_defn_calc();

// Refinancing Rate Option Spread 
double  bond_asset_refinancing_rate_opt_sprd();

// Sale Class Identification 
int  bond_asset_sale_class_id();

// Schedule Array Size 
int  bond_asset_sch_array_size();

// Schedule Start Period 
int  bond_asset_sch_start_period();

// Segment Number 
int  bond_asset_seg_num();

// Start Period 
int  bond_asset_start_period();

// Tax Exempt Percent 
double  bond_asset_tax_exempt_pct();

// Use End of Month Scenario Rates? 
int  bond_asset_use_eom_scen_rates();

// Write Schedule File Flag 
int  bond_asset_write_sch_file_flag();

// Years Since Last Payment 
double  bond_asset_yrs_since_last_pmt();


};
#endif
