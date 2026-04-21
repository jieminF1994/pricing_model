
#ifndef __MTG_ASSET_UDF_H_
#define __MTG_ASSET_UDF_H_

#include "ModelClass\mtg_asset.h"

class MTG_ASSET_UDF : public MTG_ASSET {

	friend class MTG_ASSET;

//constructor 
MTG_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: MTG_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
MTG_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : MTG_ASSET(columnCount, mocd, persObj) {}


// Accrued Income 
double mtg_asset_accr_inc(int t);

// Accrued Interest 
double mtg_asset_accr_int(int t);

// Accrued Interest After Defaults 
double mtg_asset_accr_int_aft_dflt(int t);

// Accrued Interest After Prepayments 
double mtg_asset_accr_int_aft_prepmt(int t);

// Accrued Interest Before Fund Value Matching Asset Sales 
double mtg_asset_accr_int_bef_fund_match_sale(int t);

// Accrued Interest Before Negative Cash Flow Sales 
double mtg_asset_accr_int_bef_neg_cash_flow_sale(int t);

// Accrued Interest Before Prepayments 
double mtg_asset_accr_int_bef_prepmt(int t);

// Accrued Interest Before Rebalancing Sales 
double mtg_asset_accr_int_bef_rebal_sale(int t);

// Accrued Interest Before Sales 
double mtg_asset_accr_int_bef_sale(int t);

// Accrued Interest Defaults 
double mtg_asset_accr_int_dflt(int t);

// Accrued Interest Purchase 
double mtg_asset_accr_int_purch(int t);

// Accrued Interest Rent 
double mtg_asset_accr_int_rent(int t);

// Accrued Interest Sold 
double mtg_asset_accr_int_sold(int t);

// Detail Present Value Flag 
double mtg_asset_asset_detail_pv_flag(int t);

// Asset Minimum Size Sale Flag 
double mtg_asset_asset_min_size_sale_flag(int t);

// AVR Basic Contribution 
double mtg_asset_avr_basic_contribn(int t);

// AVR Basic Contribution Before Sales 
double mtg_asset_avr_basic_contribn_bef_sale(int t);

// AVR Maximum 
double mtg_asset_avr_max(int t);

// AVR Maximum Before Sales 
double mtg_asset_avr_max_bef_sale(int t);

// AVR Objective 
double mtg_asset_avr_obj(int t);

// AVR Objective Before Sales 
double mtg_asset_avr_obj_bef_sale(int t);

// AVR Realized Capital Gain 
double mtg_asset_avr_realzd_cap_gain(int t);

// Balloon Schedule Base 
double mtg_asset_balloon_sch_base(int t);

// Base Income Before Prepayments 
double mtg_asset_base_inc_bef_prepmt(int t);

// Book Value 
double mtg_asset_bk_val(int t);

// Book Value After Defaults 
double mtg_asset_bk_val_aft_dflt(int t);

// Book Value After Prepayment 
double mtg_asset_bk_val_aft_prepmt(int t);

// Book Value Before Fund Value Matching Asset Sales 
double mtg_asset_bk_val_bef_fund_match_sale(int t);

// Book Value Before Negative Cash Flow Sales 
double mtg_asset_bk_val_bef_neg_cash_flow_sale(int t);

// Book Value Before Prepayments 
double mtg_asset_bk_val_bef_prepmt(int t);

// Book Value Before Rebalancing Sales 
double mtg_asset_bk_val_bef_rebal_sale(int t);

// Book Value Before Sales 
double mtg_asset_bk_val_bef_sale(int t);

// Book Value Plus Accrued Interest Before Rebalancing Sales 
double mtg_asset_bk_val_plus_accr_int_bef_rebal_sale(int t);

// Book Value Purchase 
double mtg_asset_bk_val_purch(int t);

// Calendar Month 
double mtg_asset_cal_mth(int t);

// Calendar Year 
double mtg_asset_cal_yr(int t);

// Calendar Year Relative 
double mtg_asset_cal_yr_relative(int t);

// Capital Gain Adjustment Foreclosure Principal Payment 
double mtg_asset_cap_gain_adj_foreclosure_prin_pmt(int t);

// Capital Gain Adjustment Restructure Principal Payment 
double mtg_asset_cap_gain_adj_restructure_prin_pmt(int t);

// Capital Gains Before Sales 
double mtg_asset_cap_gain_bef_sale(int t);

// Capital Gains from Sales 
double mtg_asset_cap_gain_from_sale(int t);

// Cash Flow 
double mtg_asset_cash_flow(int t);

// Cost Basis 
double mtg_asset_cost_basis(int t);

// Cost Basis Accrual 
double mtg_asset_cost_basis_accrual(int t);

// Cost Basis After Defaults 
double mtg_asset_cost_basis_aft_dflt(int t);

// Cost Basis After Prepayments 
double mtg_asset_cost_basis_aft_prepmt(int t);

// Cost Basis Before Prepayments 
double mtg_asset_cost_basis_bef_prepmt(int t);

// Cost Basis Before Sales 
double mtg_asset_cost_basis_bef_sale(int t);

// Cost Basis Default 
double mtg_asset_cost_basis_dflt(int t);

// Cost Basis Increase from Appreciation 
double mtg_asset_cost_basis_incr_appreciation(int t);

// Cost Basis Purchase 
double mtg_asset_cost_basis_purch(int t);

// Cost Basis Scheduled Principal Payment 
double mtg_asset_cost_basis_sched_prin_pmt(int t);

// Cost Basis Sold 
double mtg_asset_cost_basis_sold(int t);

// Date 
double mtg_asset_date(int t);

// Decrease Percent 
double mtg_asset_decr_pct(int t);

// Decrease Rate 
double mtg_asset_decr_rate(int t);

// Default Amount 
double mtg_asset_dflt_amt(int t);

// Default Percent 
double mtg_asset_dflt_pct(int t);

// Default Rate 
double mtg_asset_dflt_rate(int t);

// Duration Value 
double mtg_asset_dur_val(int t);

// Effective Duration 
double mtg_asset_eff_dur(int t);

// Finalize 
double mtg_asset_finalize(int t);

// Foreclosure Accrued Interest Net Write Down 
double mtg_asset_foreclosure_accr_int_net_write_down(int t);

// Foreclosure Book Value Net Write Down 
double mtg_asset_foreclosure_bk_val_net_write_down(int t);

// Foreclosure Cost Basis Net Write Down 
double mtg_asset_foreclosure_cost_basis_net_write_down(int t);

// Foreclosure Percent 
double mtg_asset_foreclosure_pct(int t);

// Foreclosure Principal Net Write Down 
double mtg_asset_foreclosure_prin_net_write_down(int t);

// Foreclosure Rate 
double mtg_asset_foreclosure_rate(int t);

// GAAP Income Book Value 
double mtg_asset_gaap_inc_bk_val(int t);

// GAAP Income Unrealized Capital Gain 
double mtg_asset_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Surplus Book Value 
double mtg_asset_gaap_surp_bk_val(int t);

// GAAP Unrealized Capital Gain Increase 
double mtg_asset_gaap_unrealzd_cap_gain_incr(int t);

// Interest Maintenance Reserve Realized Capital Gain 
double mtg_asset_imr_realzd_cap_gain(int t);

// Interest Maintenance Reserve Realized Capital Gains from Sales 
double mtg_asset_imr_realzd_cap_gain_from_sale(int t);

// Interest Maintenance Reserve Realized Capital Gain for Residential Mortgage 
double mtg_asset_imr_realzd_cap_gain_rml(int t);

// Interest Maintenance Reserve Realized Capital Gains from Sales for Residential Mortgage 
double mtg_asset_imr_realzd_cap_gain_rml_from_sale(int t);

// Interest Maintenance Reserve Years to Maturity 
double mtg_asset_imr_yrs_to_maturity(int t);

// Initialize 
double mtg_asset_initialize(int t);

// Interest Dividend and Rent 
double mtg_asset_int_div_and_rent(int t);

// Interest Payment 
double mtg_asset_int_pmt(int t);

// Intex Accrued Interest Adjustment 
double mtg_asset_intex_accr_int_adj(int t);

// Intex Percent Remaining 
double mtg_asset_intex_pct_remaining(int t);

// Intex Target 
double mtg_asset_intex_tgt(int t);

// Market Risk Spread 
double mtg_asset_mkt_risk_sprd(int t);

// Market Spread 
double mtg_asset_mkt_sprd(int t);

// Market to Book Ratio 
double mtg_asset_mkt_to_bk_ratio(int t);

// Market Value 
double mtg_asset_mkt_val(int t);

// Market Value Before Fund Value Matching Asset Sales 
double mtg_asset_mkt_val_bef_fund_match_sale(int t);

// Market Value Before Negative Cash Flow Sales 
double mtg_asset_mkt_val_bef_neg_cash_flow_sale(int t);

// Market Value Before Rebalancing Sales 
double mtg_asset_mkt_val_bef_rebal_sale(int t);

// Market Value Before Sales 
double mtg_asset_mkt_val_bef_sale(int t);

// Market Value for Duration Before Negative Cash Flow Sales 
double mtg_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t);

// Market Value for Duration Before Rebalancing Sales 
double mtg_asset_mkt_val_for_dur_bef_rebal_sale(int t);

// Market Value for Duration Sold 
double mtg_asset_mkt_val_for_dur_sold(int t);

// Market Value for Effective Duration 
double mtg_asset_mkt_val_for_eff_dur(int t);

// Market Value Purchase 
double mtg_asset_mkt_val_purch(int t);

// Market Value Shifted 
double mtg_asset_mkt_val_shifted(int t);

// Market Value Sold 
double mtg_asset_mkt_val_sold(int t);

// Market Value Times Duration Before Negative Cash Flow Sales 
double mtg_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t);

// Market Value Times Duration Before Rebalancing Sales 
double mtg_asset_mkt_val_times_dur_bef_rebal_sale(int t);

// Market Value Times Effective Duration 
double mtg_asset_mkt_val_times_eff_dur(int t);

// Months Before Maturity 
double mtg_asset_mths_bef_maturity(int t);

// Months Since Issue 
double mtg_asset_mths_since_issue(int t);

// Months to Next Market Value Calculation 
double mtg_asset_mths_to_next_mkt_val_calc(int t);

// Net Yield 
double mtg_asset_net_yld(int t);

// Notional Amount 
double mtg_asset_notional_amt(int t);

// Notional Amount Before Fund Value Matching Asset Sales 
double mtg_asset_notional_amt_bef_fund_match_sale(int t);

// Notional Amount Before Negative Cash Flow Sales 
double mtg_asset_notional_amt_bef_neg_cash_flow_sale(int t);

// Notional Amount Before Rebalancing Sales 
double mtg_asset_notional_amt_bef_rebal_sale(int t);

// Notional Amount Before Sales 
double mtg_asset_notional_amt_bef_sale(int t);

// Option Income 
double mtg_asset_opt_inc(int t);

// Option Payment 
double mtg_asset_opt_pmt(int t);

// Risk Based Capital C1 
double mtg_asset_rbc_c1(int t);

// Risk Based Capital C1 Before Sales 
double mtg_asset_rbc_c1_bef_sale(int t);

// Realized Capital Gain 
double mtg_asset_realzd_cap_gain(int t);

// Realized Capital Gain from Option Payment 
double mtg_asset_realzd_cap_gain_opt_pmt(int t);

// Realized Capital Gain from Prepayment 
double mtg_asset_realzd_cap_gain_prepmt(int t);

// Realized Capital Gain from Sales 
double mtg_asset_realzd_cap_gain_sale(int t);

// Realized Capital Loss from Default 
double mtg_asset_realzd_cap_loss_dflt(int t);

// Realized Capital Loss from Foreclosure 
double mtg_asset_realzd_cap_loss_foreclosure(int t);

// Realized Capital Loss from Restructure 
double mtg_asset_realzd_cap_loss_restructure(int t);

// Refinance Accrued Interest 
double mtg_asset_refinance_accr_int(int t);

// Refinance Book Value 
double mtg_asset_refinance_bk_val(int t);

// Refinance Cost Basis 
double mtg_asset_refinance_cost_basis(int t);

// Refinance Percent 
double mtg_asset_refinance_pct(int t);

// Refinance Principal 
double mtg_asset_refinance_prin(int t);

// Refinance Rate 
double mtg_asset_refinance_rate(int t);

// Restructure Accrued Interest Net Write Down 
double mtg_asset_restructure_accr_int_net_write_down(int t);

// Restructure Book Value Net Write Down 
double mtg_asset_restructure_bk_val_net_write_down(int t);

// Restructure Cost Basis Net Write Down 
double mtg_asset_restructure_cost_basis_net_write_down(int t);

// Restructure Percent 
double mtg_asset_restructure_pct(int t);

// Restructure Principal Net Write Down 
double mtg_asset_restructure_prin_net_write_down(int t);

// Restructure Rate 
double mtg_asset_restructure_rate(int t);

// Scheduled Principal Payment 
double mtg_asset_sched_prin_pmt(int t);

// Sold Percent 
double mtg_asset_sold_pct(int t);

// Sold Percent Fund Value Matching 
double mtg_asset_sold_pct_fund_match(int t);

// Sold Percent Negative Cash Flow 
double mtg_asset_sold_pct_neg_cash_flow(int t);

// Sold Percent Planned 
double mtg_asset_sold_pct_planned(int t);

// Sold Percent Rebalancing 
double mtg_asset_sold_pct_rebal(int t);

// Startup 
virtual double virtual_startup(int t);

// Asset Sub Portfolio Identification 
double mtg_asset_sub_port_id(int t);

// Unrealized Capital Gain 
double mtg_asset_unrealzd_cap_gain(int t);

// Unrealized Capital Gain Before Fund Value Matching Asset Sales 
double mtg_asset_unrealzd_cap_gain_bef_fund_match_sale(int t);

// Unrealized Capital Gain Before Negative Cash Flow Sales 
double mtg_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t);

// Unrealized Capital Gain Before Rebalancing Sales 
double mtg_asset_unrealzd_cap_gain_bef_rebal_sale(int t);

// Unrealized Capital Gain Before Sales 
double mtg_asset_unrealzd_cap_gain_bef_sale(int t);

// Unrealized Capital Gain GAAP Surplus 
double mtg_asset_unrealzd_cap_gain_gaap_surp(int t);

// Unrealized Capital Gain Increase 
double mtg_asset_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Released on Sale 
double mtg_asset_unrealzd_cap_gain_released_on_sale(int t);

// Unrealized Capital Gain to Book Ratio 
double mtg_asset_unrealzd_cap_gain_to_bk_ratio(int t);

// Unrealized Capital Loss From Default 
double mtg_asset_unrealzd_cap_loss_from_dflt(int t);

// Weighted Average Life 
double mtg_asset_weighted_avg_life(int t);

// Write Down 
double mtg_asset_write_down(int t);

// Yield Denominator 
double mtg_asset_yld_denom(int t);

// Yield Numerator 
double mtg_asset_yld_numer(int t);

// Yield Numerator Capital with duration weighted adjustment 
double mtg_asset_yld_numer_adj_aig(int t);

// Accrued Interest Per Par Value Unit 
double  mtg_asset_accr_int_per_par_unit();

// Amortization Cost Period 
int  mtg_asset_amortzn_cost_period();

// Amortization Period 
int  mtg_asset_amortzn_period();

// Detail Report Flag 
int  mtg_asset_asset_detail_rpt_flag();

// Asset Fund Index 
int  mtg_asset_asset_fund_index();

// Balloon Payment Flag 
int  mtg_asset_balloon_pmt_flag();

// Balloon Payment Period 
int  mtg_asset_balloon_pmt_period();

// Commencement Period 
int  mtg_asset_commencement_period();

// Data Group Identification 
xstring  mtg_asset_data_grp_id();

// Existing Asset Indicator 
int  mtg_asset_existing_asset_indicator();

// Foreclosure Asset Identification 
int  mtg_asset_foreclosure_asset_id();

// Foreclosure Write Down Percentage Calculated 
double  mtg_asset_foreclosure_write_down_pct_calc();

// GAAP Income Definition 
int  mtg_asset_gaap_inc_defn();

// GAAP Value Definition 
int  mtg_asset_gaap_val_defn();

// Initial Months Since Issue 
int  mtg_asset_init_mths_since_issue();

// Maturity Months from Next Reset 
int  mtg_asset_maturity_mths_from_next_reset();

// Maturity Period 
int  mtg_asset_maturity_period();

// Market Value Per Unit of Par Value 
double  mtg_asset_mkt_val_per_unit_par();

// Negative Asset Flag 
double  mtg_asset_neg_asset_flag();

// Par Value at Issue 
double  mtg_asset_par_val_at_issue();

// Percent to Use 
double  mtg_asset_pct_to_use();

// Planned Sale Period 
double  mtg_asset_planned_sale_period();

// Payment Frequency 
int  mtg_asset_pmt_freq();

// Payment Period Months 
int  mtg_asset_pmt_mths();

// Payment Rate at Issue 
double  mtg_asset_pmt_rate_at_issue();

// Payment Rate Definition 
int  mtg_asset_pmt_rate_defn();

// Payment Rate Definition 
xstring  mtg_asset_pmt_rate_defn_string();

// Payment Reset First Period 
int  mtg_asset_pmt_reset_first_period();

// Prepayment First Period 
int  mtg_asset_prepmt_first_period();

// Prepayment at Par Value First Period 
int  mtg_asset_prepmt_par_first_period();

// Prepayment Penalty Grading Months 
int  mtg_asset_prepmt_penalty_grading_mths();

// Prepayment Penalty Related to Payment Rate 
double  mtg_asset_prepmt_penalty_related_to_pmt_rate();

// Projection Date Adjusted 
xstring  mtg_asset_proj_date_adj();

// Projection Start Date 
int  mtg_asset_proj_start_date();

// Projection Start Mth 
int  mtg_asset_proj_start_mth();

// Projection Start Yr 
int  mtg_asset_proj_start_yr();

// Refinance Asset Identification 
int  mtg_asset_refinance_asset_id();

// Refinancing Rate Definition Calculated 
int  mtg_asset_refinancing_rate_defn_calc();

// Restructure Asset Identification 
int  mtg_asset_restructure_asset_id();

// Restructure Write Down Percentage Calculated 
double  mtg_asset_restructure_write_down_pct_calc();

// Sale Class Identification 
int  mtg_asset_sale_class_id();

// Schedule Array Size 
int  mtg_asset_sch_array_size();

// Segment Number 
int  mtg_asset_seg_num();

// Start Period 
int  mtg_asset_start_period();

// Use Andrew Davidson 
int  mtg_asset_use_andrew_davidson();

// Use Intex Databases? 
int  mtg_asset_use_intex_databases_for_mtg();

// Write Schedule File Flag 
int  mtg_asset_write_sch_file_flag();

// Years Since Last Payment 
double  mtg_asset_yrs_since_last_pmt();


};
#endif
