
#ifndef __COMP_COMP_UDF_H_
#define __COMP_COMP_UDF_H_

#include "ModelClass\comp_comp.h"

class COMP_COMP_UDF : public COMP_COMP {

	friend class COMP_COMP;

//constructor 
COMP_COMP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: COMP_COMP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
COMP_COMP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : COMP_COMP(columnCount, mocd, persObj) {}


// Accrued Income 
double comp_comp_accr_inc(int t);

// Accrued Income Investment Assets 
double comp_comp_accr_inc_inv(int t);

// Accrued Interest 
double comp_comp_accr_int(int t);

// Accrued Interest After Default 
double comp_comp_accr_int_aft_dflt(int t);

// Accrued Interest Default Amount 
double comp_comp_accr_int_dflt(int t);

// Acquisition Expenses 
double comp_comp_acq_exp(int t);

// Annuity Benefits Beginning of Month 
double comp_comp_ann_benefits_bom(int t);

// Annuity Benefits End of Month 
double comp_comp_ann_benefits_eom(int t);

// Annuitization Consideration 
double comp_comp_annuitzn_consideration(int t);

// Annuitization Count Monthly 
double comp_comp_annuitzn_count_aig(int t);

// Annuitization Income 
double comp_comp_annuitzn_inc(int t);

// Annuitization Value Released 
double comp_comp_annuitzn_val_released(int t);

// Asset Cash Flow 
double comp_comp_asset_cash_flow(int t);

// Asset Cash Flow Before Investment 
double comp_comp_asset_cash_flow_bef_inv(int t);

// Asset Cash Flow Before Sales 
double comp_comp_asset_cash_flow_bef_sale(int t);

// Assets Less Liabilities And Surplus 
double comp_comp_asset_less_liab_and_surp(int t);

// Assets Separate Account 
double comp_comp_asset_sa(int t);

// Asset Yield 
double comp_comp_asset_yld(int t);

// Asset Yield Denominator 
double comp_comp_asset_yld_denom(int t);

// Asset Yield Denominator for Investment Asset 
double comp_comp_asset_yld_denom_inv(int t);

// Asset Yield on Investment Assets 
double comp_comp_asset_yld_inv(int t);

// Asset Yield on Investment Assets, with Duration Weighted Adjustment 
double comp_comp_asset_yld_inv_adj_aig(int t);

// Asset Yield Less Default 
double comp_comp_asset_yld_less_dflt(int t);

// Asset Yield Less Default on Investment Assets 
double comp_comp_asset_yld_less_dflt_inv(int t);

// Asset Yield Less Default Numerator 
double comp_comp_asset_yld_less_dflt_numer(int t);

// Asset Yield Less Default Numerator for Investment Assets 
double comp_comp_asset_yld_less_dflt_numer_inv(int t);

// Asset Yield Numerator 
double comp_comp_asset_yld_numer(int t);

// Asset Yield Numerator for Investment Asset 
double comp_comp_asset_yld_numer_inv(int t);

// Asset Yld Vm21 Reinv Rate 
double comp_comp_asset_yld_vm21_reinv_rate(int t);

// AVR 
double comp_comp_avr(int t);

// AVR Before Sales 
double comp_comp_avr_bef_sale(int t);

// AVR Bond 
double comp_comp_avr_bond(int t);

// AVR Bond Before Sales 
double comp_comp_avr_bond_bef_sale(int t);

// AVR Bond Beginning of Calendar Year 
double comp_comp_avr_bond_bocy(int t);

// AVR Default 
double comp_comp_avr_dflt(int t);

// AVR Default Before Sales 
double comp_comp_avr_dflt_bef_sale(int t);

// AVR Equity 
double comp_comp_avr_eqt(int t);

// AVR Equity Before Sales 
double comp_comp_avr_eqt_bef_sale(int t);

// AVR Increase 
double comp_comp_avr_incr(int t);

// AVR Mortgage 
double comp_comp_avr_mtg(int t);

// AVR Mortgage Before Sales 
double comp_comp_avr_mtg_bef_sale(int t);

// AVR Mortgage Beginning of Calendar Year 
double comp_comp_avr_mtg_bocy(int t);

// AVR Other 
double comp_comp_avr_other(int t);

// AVR Other Before Sales 
double comp_comp_avr_other_bef_sale(int t);

// AVR Other Beginning of Calendar Year 
double comp_comp_avr_other_bocy(int t);

// AVR Stock 
double comp_comp_avr_stock(int t);

// AVR Stock Before Sales 
double comp_comp_avr_stock_bef_sale(int t);

// AVR Stock Beginning of Calendar Year 
double comp_comp_avr_stock_bocy(int t);

// AVR Unrealized Capital Gain Equity Beginning of Calendar Year 
double comp_comp_avr_unrealzd_cap_gain_eqt_bocy(int t);

// AVR Unrealized Capital Gain Non Equity Beginning of Calendar Year 
double comp_comp_avr_unrealzd_cap_gain_non_eqt_bocy(int t);

// Before Tax Yield 
double comp_comp_bef_tax_yld(int t);

// Book Profit After Tax 
double comp_comp_bk_prof_aft_tax(int t);

// Book Profit After Tax Before Sales 
double comp_comp_bk_prof_aft_tax_bef_sale(int t);

// Book Profit After Tax for Present Values 
double comp_comp_bk_prof_aft_tax_for_pv(int t);

// Book Profit After Tax for IRR 
double comp_comp_bk_prof_aft_tax_irr(int t);

// Book Profit After Tax Calendar Quarter to Date 
double comp_comp_bk_prof_aft_tax_qtd(int t);

// Book Profit After Tax Calendar Year to Date 
double comp_comp_bk_prof_aft_tax_ytd(int t);

// Book Profit Before Tax 
double comp_comp_bk_prof_bef_tax(int t);

// Book Profit Before Tax Before Sales 
double comp_comp_bk_prof_bef_tax_bef_sale(int t);

// Book Profit Before Tax for Present Values 
double comp_comp_bk_prof_bef_tax_for_pv(int t);

// Book Profit Before Tax Calendar Quarter to Date 
double comp_comp_bk_prof_bef_tax_qtd(int t);

// Book Profit Before Tax Calendar Year to Date 
double comp_comp_bk_prof_bef_tax_ytd(int t);

// Book Profit By Source Before Tax 
double comp_comp_bk_prof_by_source_bef_tax(int t);

// Book Value 
double comp_comp_bk_val(int t);

// Book Value Investment Assets 
double comp_comp_bk_val_inv(int t);

// Borrowing 
double comp_comp_borrowing(int t);

// Borrowing Interest 
double comp_comp_borrowing_int(int t);

// Calendar Month 
double comp_comp_cal_mth(int t);

// Calendar Year 
double comp_comp_cal_yr(int t);

// Calendar Year Relative 
double comp_comp_cal_yr_relative(int t);

// Capital Gains 
double comp_comp_cap_gain(int t);

// Capital Gains Before Sales 
double comp_comp_cap_gain_bef_sale(int t);

// Capital Gains on Free Surplus 
double comp_comp_cap_gain_free_surp(int t);

// Capital Gains on Free Surplus Before Sales 
double comp_comp_cap_gain_free_surp_bef_sale(int t);

// Capital Gains from Sales 
double comp_comp_cap_gain_from_sale(int t);

// Capital Gains on Reserve 
double comp_comp_cap_gain_res(int t);

// Capital Gains on Reserve Before Sales 
double comp_comp_cap_gain_res_bef_sale(int t);

// Capital Gains on Target Capital 
double comp_comp_cap_gain_tgt_cap(int t);

// Capital Gains on Target Capital Before Sales 
double comp_comp_cap_gain_tgt_cap_bef_sale(int t);

// Capital Gains on Undistributed Earnings 
double comp_comp_cap_gain_undistrib_earnings(int t);

// Capital Gains on Undistributed Earnings Before Sales 
double comp_comp_cap_gain_undistrib_earnings_bef_sale(int t);

// Cash 
double comp_comp_cash(int t);

// Cash Flow For Investment 
double comp_comp_cash_flow_for_inv(int t);

// Cash Flow Interest 
double comp_comp_cash_flow_int(int t);

// Cash Flow Invested 
double comp_comp_cash_flow_invested(int t);

// Cash Interest 
double comp_comp_cash_int(int t);

// Cash Interest For Asset Yield Investment 
double comp_comp_cash_int_inv(int t);

// Cash Value 
double comp_comp_cash_val(int t);

// Claim Paid 
double comp_comp_claim_paid(int t);

// Commissions Beginning of Month 
double comp_comp_comm_bom(int t);

// Commission Chargeback 
double comp_comp_comm_chargeback(int t);

// Commissions End of Month 
double comp_comp_comm_eom(int t);

// Conversion Cost 
double comp_comp_conversion_cost(int t);

// Cost Basis Accrual 
double comp_comp_cost_basis_accrual(int t);

// Cost Basis Increase Appreciation 
double comp_comp_cost_basis_incr_appreciation(int t);

// Cost Basis Purchase 
double comp_comp_cost_basis_purch(int t);

// Cost Basis Sale 
double comp_comp_cost_basis_sale(int t);

// Credited Interest 
double comp_comp_credited_int(int t);

// Date 
double comp_comp_date(int t);

// Deferred Gross Premium 
double comp_comp_deferred_gross_prem(int t);

// Deferred Gross Premium Increase 
double comp_comp_deferred_gross_prem_incr(int t);

// Deferred Net Premium 
double comp_comp_deferred_net_prem(int t);

// Delta Hedge Investment Amount 
double comp_comp_delta_hedge_inv_amt(int t);

// Delta Hedge Market Value of Assets 
double comp_comp_delta_hedge_mkt_val(int t);

// Delta Hedge Market Value of Assets Increase 
double comp_comp_delta_hedge_mkt_val_incr(int t);

// Delta Hedge Derivative Payment 
double comp_comp_delta_hedge_pmt(int t);

// Delta Hedge Profit 
double comp_comp_delta_hedge_prof(int t);

// Delta Hedge Sale Amount 
double comp_comp_delta_hedge_sale_amt(int t);

// Delta Hedge Transaction Cost 
double comp_comp_delta_hedge_transaction_cost(int t);

// Default Amount 
double comp_comp_dflt_amt(int t);

// Direct Cash Flow Beginning of Month 
double comp_comp_direct_cash_flow_bom(int t);

// Direct Cash Flow End of Month 
double comp_comp_direct_cash_flow_eom(int t);

// Direct Cash Flow Interest 
double comp_comp_direct_cash_flow_int(int t);

// Discount Rate 1 
double comp_comp_disc_rate_1(int t);

// Discount Rate 2 
double comp_comp_disc_rate_2(int t);

// Discount Rate 3 
double comp_comp_disc_rate_3(int t);

// Discount Rate for AIG discounting.  This is risk-free rate plus Internal Capital UEL spread. 
double comp_comp_disc_rate_aig_curve_ic_uel_aig(int t);

// Discount Rate for AIG discounting.  This is risk-free rate plus non-UEL spread. 
double comp_comp_disc_rate_aig_curve_no_uel_aig(int t);

// Discount Rate for AIG discounting.  This is risk-free rate plus UEL spread, or the "AIG curve". 
double comp_comp_disc_rate_aig_curve_uel_aig(int t);

// Discount Rate Portfolio Yield 
double comp_comp_disc_rate_port_yld(int t);

// Discount Rate Portfolio Ylield Definition Value 
double comp_comp_disc_rate_port_yld_defn_val(int t);

// Discount Rate for risk-free discounting.  This is risk-free rate without the spread. 
double comp_comp_disc_rate_risk_free_aig(int t);

// Distributable Earnings 
double comp_comp_distrib_earnings(int t);

// Distributable Earnings Break-Even 
double comp_comp_distrib_earnings_be(int t);

// Distributable Earnings Before Sales 
double comp_comp_distrib_earnings_bef_sale(int t);

// Distributable Earnings Cumulative 
double comp_comp_distrib_earnings_cum(int t);

// Distributable Earnings for IRR 
double comp_comp_distrib_earnings_irr(int t);

// Distributable Earnings for month 1 for strain 
double comp_comp_distrib_earnings_strain(int t);

// Dividend Applied 
double comp_comp_div_applied(int t);

// Dividend Liability 
double comp_comp_div_liab(int t);

// Dividend Liability Increase 
double comp_comp_div_liab_incr(int t);

// Dividend Paid 
double comp_comp_div_paid(int t);

// Death Benefit In Force 
double comp_comp_dth_ben_inf(int t);

// Death Benefits 
double comp_comp_dth_benefits(int t);

// Death Count Monthly 
double comp_comp_dth_count_aig(int t);

// Accumulated Earnings 
double comp_comp_earnings_accum(int t);

// Economic Cash Amount 
double comp_comp_econ_cash(int t);

// Interest Earned on Economic Cash Amount 
double comp_comp_econ_cash_int(int t);

// Economic Profit 
double comp_comp_econ_prof(int t);

// Unhedged Economic Profit 
double comp_comp_econ_prof_unhedged(int t);

// Economic Reserve: Present Value of Claims - Present Value of Charges 
double comp_comp_econ_res(int t);

// Economic Reserve Increase 
double comp_comp_econ_res_incr(int t);

// Interest Earned on Economic Reserve 
double comp_comp_econ_res_int(int t);

// Endowment Benefits 
double comp_comp_endow_benefits(int t);

// Finalize 
double comp_comp_finalize(int t);

// Free Surplus 
double comp_comp_free_surp(int t);

// Free Surplus at Market 
double comp_comp_free_surp_at_mkt(int t);

// Free Surplus at Market Ending 
double comp_comp_free_surp_at_mkt_ending(int t);

// Free Surplus Before Shareholder Dividend 
double comp_comp_free_surp_bef_shldr_div(int t);

// Free Surplus Increase 
double comp_comp_free_surp_incr(int t);

// Fund Value released on Annuitization 
double comp_comp_fund_released_ann(int t);

// Fund Value released on Death 
double comp_comp_fund_released_dth(int t);

// Fund Value released on Maturity 
double comp_comp_fund_released_maturity(int t);

// Fund Value released on Surrender 
double comp_comp_fund_released_surr(int t);

// Fund Value released on Withdrawal 
double comp_comp_fund_released_withdrl(int t);

// Fund Value Fixed Account 
double comp_comp_fund_val_fixed(int t);

// Fund Value Separate Account 
double comp_comp_fund_val_sa(int t);

// Fund Weighted Cap Spread Rate Aig 
double comp_comp_fund_weighted_cap_spread_fix_rt_aig(int t);

// Fund Weighted Par Rate Aig 
double comp_comp_fund_weighted_par_rate_aig(int t);

// Fund Weighted Pri Spread Aig 
double comp_comp_fund_weighted_pri_spread_aig(int t);

// GAAP Accumulation Benefit Claim Cost 
double comp_comp_gaap_accum_ben_claim_cost(int t);

// GAAP Acquisition Expenses 
double comp_comp_gaap_acq_exp(int t);

// GAAP Annuity Claim Cost 
double comp_comp_gaap_ann_claim_cost(int t);

// GAAP Benefit Reserve 
double comp_comp_gaap_ben_res(int t);

// GAAP Benefit Reserve Increase 
double comp_comp_gaap_ben_res_incr(int t);

// GAAP Capital Gains on Capital 
double comp_comp_gaap_cap_gain_cap(int t);

// GAAP Capital Gain on Reserves 
double comp_comp_gaap_cap_gain_res(int t);

// GAAP Capitalized Acquisition Expenses 
double comp_comp_gaap_capzd_acq_exp(int t);

// GAAP Capitalized Commissions BOM 
double comp_comp_gaap_capzd_comm_bom(int t);

// GAAP Capitalized Commissions EOM 
double comp_comp_gaap_capzd_comm_eom(int t);

// GAAP Capitalized Premium Bonus 
double comp_comp_gaap_capzd_prem_bonus(int t);

// GAAP Capitalized Reinsurance YRT Cost 
double comp_comp_gaap_capzd_reins_yrt_cost(int t);

// GAAP Cash Flow Interest 
double comp_comp_gaap_cash_flow_int(int t);

// GAAP Charges Income 
double comp_comp_gaap_chg_inc(int t);

// GAAP Claim Reserve 
double comp_comp_gaap_claim_res(int t);

// GAAP Claim Reserve Increase 
double comp_comp_gaap_claim_res_incr(int t);

// GAAP Commission Excess BOM 
double comp_comp_gaap_comm_excess_bom(int t);

// GAAP Commission Excess EOM 
double comp_comp_gaap_comm_excess_eom(int t);

// GAAP Commission Trail BOM 
double comp_comp_gaap_comm_trail_bom(int t);

// GAAP Commission Trail EOM 
double comp_comp_gaap_comm_trail_eom(int t);

// GAAP Conersion Cost 
double comp_comp_gaap_conversion_cost(int t);

// GAAP Credited Interest 
double comp_comp_gaap_credited_int(int t);

// GAAP DAC 
double comp_comp_gaap_dac(int t);

// GAAP DAC Increase 
double comp_comp_gaap_dac_incr(int t);

// GAAP Deferred Maintenance Expenses 
double comp_comp_gaap_deferred_maint_exp(int t);

// GAAP Deferred Profit Liability 
double comp_comp_gaap_deferred_prof_liab(int t);

// GAAP Deferred Profit Liability Increase 
double comp_comp_gaap_deferred_prof_liab_incr(int t);

// GAAP Deferred Tax Liability 
double comp_comp_gaap_deferred_tax_liab(int t);

// GAAP Deferred Tax Liability Increase 
double comp_comp_gaap_deferred_tax_liab_incr(int t);

// GAAP Dividend Applied 
double comp_comp_gaap_div_applied(int t);

// GAAP Dividend Liability 
double comp_comp_gaap_div_liab(int t);

// GAAP Dividend Liability Increase 
double comp_comp_gaap_div_liab_incr(int t);

// GAAP Dividend Paid 
double comp_comp_gaap_div_paid(int t);

// GAAP Death Claim Cost 
double comp_comp_gaap_dth_claim_cost(int t);

// GAAP Endowment Claim Cost 
double comp_comp_gaap_endow_claim_cost(int t);

// GAAP Free Surplus 
double comp_comp_gaap_free_surp(int t);

// GAAP Gross Premium 
double comp_comp_gaap_gross_prem(int t);

// GAAP Hedge Cost 
double comp_comp_gaap_hedge_cost(int t);

// GAAP Hedge Market Value 
double comp_comp_gaap_hedge_mkt_val(int t);

// GAAP Hedge Market Value Increase 
double comp_comp_gaap_hedge_mkt_val_incr(int t);

// GAAP Health Claim Cost 
double comp_comp_gaap_hlth_claim_cost(int t);

// GAAP Income After Tax 
double comp_comp_gaap_inc_aft_tax(int t);

// GAAP Income After Tax Calendar Quarter to Date 
double comp_comp_gaap_inc_aft_tax_qtd(int t);

// GAAP Income After Tax Calendar Year to Date 
double comp_comp_gaap_inc_aft_tax_ytd(int t);

// GAAP Income Before Tax 
double comp_comp_gaap_inc_bef_tax(int t);

// GAAP Income Before Tax Calendar Quarter to Date 
double comp_comp_gaap_inc_bef_tax_qtd(int t);

// GAAP Income Before Tax Calendar Year to Date 
double comp_comp_gaap_inc_bef_tax_ytd(int t);

// GAAP Income Benefit Claim Cost 
double comp_comp_gaap_inc_ben_claim_cost(int t);

// GAAP Income Deferred Tax Liability 
double comp_comp_gaap_inc_deferred_tax_liab(int t);

// GAAP Income Invested Assets 
double comp_comp_gaap_inc_inv_asset(int t);

// GAAP Income Unrealized Capital Gain 
double comp_comp_gaap_inc_unrealzd_cap_gain(int t);

// GAAP Income Unrealized Capital Gain Increase 
double comp_comp_gaap_inc_unrealzd_cap_gain_incr(int t);

// GAAP Invested Assets 
double comp_comp_gaap_inv_asset(int t);

// GAAP Invested Assets - Available for Sale 
double comp_comp_gaap_inv_asset_available(int t);

// GAAP Invested Assets - Held to Maturity 
double comp_comp_gaap_inv_asset_held(int t);

// GAAP Invested Assets - Not Assigned 
double comp_comp_gaap_inv_asset_not_assigned(int t);

// GAAP Invested Assets - Trading 
double comp_comp_gaap_inv_asset_trading(int t);

// GAAP Investment Income on Capital 
double comp_comp_gaap_inv_inc_cap(int t);

// GAAP Investment Income on Reserves 
double comp_comp_gaap_inv_inc_res(int t);

// GAAP Liability Net of DAC 
double comp_comp_gaap_liab_net(int t);

// GAAP Liability Net of DAC Net 
double comp_comp_gaap_liab_net_net(int t);

// GAAP Loads Deducted 
double comp_comp_gaap_loads_deducted(int t);

// GAAP Loads Deferred 
double comp_comp_gaap_loads_deferred(int t);

// GAAP Letter of Credit Cost 
double comp_comp_gaap_loc_cost(int t);

// GAAP Maintenance Expenses BOM 
double comp_comp_gaap_maint_exp_bom(int t);

// GAAP Maintenance Expenses EOM 
double comp_comp_gaap_maint_exp_eom(int t);

// GAAP Maintenance Expense Reserve 
double comp_comp_gaap_maint_exp_res(int t);

// GAAP Maintenance Expense Reserve Increase 
double comp_comp_gaap_maint_exp_res_incr(int t);

// GAAP Maturity Claim Cost 
double comp_comp_gaap_maturity_claim_cost(int t);

// GAAP Premium Bonus 
double comp_comp_gaap_prem_bonus(int t);

// GAAP Premium Taxes 
double comp_comp_gaap_prem_tax(int t);

// GAAP Premium Waiver Reserve 
double comp_comp_gaap_prem_waiver_res(int t);

// GAAP Premium Waiver Reserve Increase 
double comp_comp_gaap_prem_waiver_res_incr(int t);

// GAAP Profit After Tax for Present Values 
double comp_comp_gaap_prof_aft_tax_for_pv(int t);

// GAAP Profit Before Tax for Present Values 
double comp_comp_gaap_prof_bef_tax_for_pv(int t);

// GAAP Reinsurance YRT Cost 
double comp_comp_gaap_reins_yrt_cost(int t);

// GAAP Required Capital 
double comp_comp_gaap_req_cap(int t);

// GAAP SFAS 133 Liability 
double comp_comp_gaap_sfas133_liab(int t);

// GAAP SFAS 133 Liability Increase 
double comp_comp_gaap_sfas133_liab_incr(int t);

// GAAP SOP 03-1 Additional Liability 
double comp_comp_gaap_sop031_addl_liab(int t);

// GAAP SOP 03-1 Additional Liability Increase 
double comp_comp_gaap_sop031_addl_liab_incr(int t);

// GAAP Surplus Increase 
double comp_comp_gaap_surp_incr(int t);

// GAAP Surplus Unrealized Capital Gain 
double comp_comp_gaap_surp_unrealzd_cap_gain(int t);

// GAAP Surplus Unrealized Capital Gain Increase 
double comp_comp_gaap_surp_unrealzd_cap_gain_incr(int t);

// GAAP Surrender Claim Cost 
double comp_comp_gaap_surr_claim_cost(int t);

// GAAP Surrender Income 
double comp_comp_gaap_surr_inc(int t);

// GAAP Terminal Dividends 
double comp_comp_gaap_terminal_div(int t);

// GAAP Unearned Revenue Liability 
double comp_comp_gaap_unearn_rev_liab(int t);

// GAAP Unearned Revenue Released 
double comp_comp_gaap_unearn_rev_released(int t);

// GAAP Unrealized Capital Gain Increase 
double comp_comp_gaap_unrealzd_cap_gain_incr(int t);

// GAAP Withdrawal Benefit Claim Cost 
double comp_comp_gaap_withdrl_ben_claim_cost(int t);

// Gamma Hedge Investment Amount 
double comp_comp_gamma_hedge_inv_amt(int t);

// Gamma Hedge Market Value of Assets 
double comp_comp_gamma_hedge_mkt_val(int t);

// Gamma Hedge Market Value of Assets Increase 
double comp_comp_gamma_hedge_mkt_val_incr(int t);

// Gamma Hedge Derivative Payment 
double comp_comp_gamma_hedge_pmt(int t);

// Gamma Hedge Profit 
double comp_comp_gamma_hedge_prof(int t);

// Gamma Hedge Sale Amount 
double comp_comp_gamma_hedge_sale_amt(int t);

// Gamma Hedge Transaction Cost 
double comp_comp_gamma_hedge_transaction_cost(int t);

// GMWB Rider charge 
double comp_comp_gmwb_chg(int t);

// Annuity GMWB Base 
double comp_comp_gmwb_inf(int t);

// Gross Premium Annualized 
double comp_comp_gross_prem_annualzd(int t);

// Hedge Cash Flow 
double comp_comp_hedge_cash_flow(int t);

// Hedge Cost 
double comp_comp_hedge_cost(int t);

// Hedge Cost Before Sale 
double comp_comp_hedge_cost_bef_sale(int t);

// Hedge Cost Charge 
double comp_comp_hedge_cost_charge(int t);

// Hedge Expenses 
double comp_comp_hedge_exp(int t);

// Hedge Interest Payment 
double comp_comp_hedge_int_pmt(int t);

// Hedge Investment Amount Beginning of Month 
double comp_comp_hedge_inv_amt_bom(int t);

// Hedge Investment Amount End of Month 
double comp_comp_hedge_inv_amt_eom(int t);

// Hedged Liability GMXB Claims 
double comp_comp_hedge_liab_claims(int t);

// Hedge Market Value 
double comp_comp_hedge_mkt_val(int t);

// Hedge Market Value Increase 
double comp_comp_hedge_mkt_val_incr(int t);

// Hedge Option Payment 
double comp_comp_hedge_opt_pmt(int t);

// RILA trading cost 
double comp_comp_hedge_rila_trading_cost_aig(int t);

// Hedge Sale Amount 
double comp_comp_hedge_sale_amt(int t);

// IMR 
double comp_comp_imr(int t);

// IMR Before Sales 
double comp_comp_imr_bef_sale(int t);

// IMR Impact on Free Surplus 
double comp_comp_imr_impact_free_surp(int t);

// IMR Impact on Free Surplus Before Sales 
double comp_comp_imr_impact_free_surp_bef_sale(int t);

// IMR Impact on Reserves 
double comp_comp_imr_impact_res(int t);

// IMR Impact on Reserve Before Sales 
double comp_comp_imr_impact_res_bef_sale(int t);

// IMR Impact on Target Capital 
double comp_comp_imr_impact_tgt_cap(int t);

// IMR Impact on Target Capital Before Sales 
double comp_comp_imr_impact_tgt_cap_bef_sale(int t);

// IMR Increase 
double comp_comp_imr_incr(int t);

// IMR Increase Before Sales 
double comp_comp_imr_incr_bef_sale(int t);

// Initialize 
double comp_comp_initialize(int t);

// Interest Payment 
double comp_comp_int_pmt(int t);

// Interim Cash 
double comp_comp_interim_cash(int t);

// Interim Cash Interest 
double comp_comp_interim_cash_int(int t);

// Invested Assets 
double comp_comp_inv_asset(int t);

// Investment Cash Flow Interest Dividend and Rent 
double comp_comp_inv_cash_flow_int_div_and_rent(int t);

// Investment Cash Flow Principal Payment 
double comp_comp_inv_cash_flow_prin_pmt(int t);

// Investment Expenses 
double comp_comp_inv_exp(int t);

// Investment Fee Refund 
double comp_comp_inv_fee_ref(int t);

// Investment Income 
double comp_comp_inv_inc(int t);

// Investment Income For Book Profit 
double comp_comp_inv_inc_bk_prof(int t);

// Investment Income For Book Profit Before Sales 
double comp_comp_inv_inc_bk_prof_bef_sale(int t);

// Investment Income on Accumulated Earnings 
double comp_comp_inv_inc_earnings_accum(int t);

// Investment Income on Free Surplus 
double comp_comp_inv_inc_free_surp(int t);

// Investment Income on Fixed Fund Value 
double comp_comp_inv_inc_fund(int t);

// Investment Income on Invested Assets 
double comp_comp_inv_inc_on_invested_assets(int t);

// Investment Income on Reserves 
double comp_comp_inv_inc_res(int t);

// Investment Income on Target Capital 
double comp_comp_inv_inc_tgt_cap(int t);

// Investment Income on Undistributed Earnings 
double comp_comp_inv_inc_undistrib_earnings(int t);

// Invested Asset Sales 
double comp_comp_invested_asset_sale(int t);

// Internal Rate of Return 
double comp_comp_irr(int t);

// Internal Rate of Return 
double comp_comp_irr2_aig(int t);

// IRR Without Target Capital 
double comp_comp_irr_wo_tgt_cap(int t);

// Lapse Count Monthly 
double comp_comp_lapse_count_aig(int t);

// Last Period Indicator 
double comp_comp_last_period_indicator(int t);

// Liabilities and Surplus Net of Reinsurance 
double comp_comp_liab_and_surp(int t);

// Liability Cash Flow 
double comp_comp_liab_cash_flow(int t);

// Liability Cash Flow Beginning of Month 
double comp_comp_liab_cash_flow_bom(int t);

// Liability Cash Flow End of Month 
double comp_comp_liab_cash_flow_eom(int t);

// Letter of Credit Asset 
double comp_comp_loc_asset(int t);

// LOC Asset Increase 
double comp_comp_loc_asset_incr(int t);

// LOC Cost 
double comp_comp_loc_cost(int t);

// Maintenance Expenses Beginning of Month 
double comp_comp_maint_exp_bom(int t);

// Maintenance Expenses End of Month 
double comp_comp_maint_exp_eom(int t);

// Maturity Benefits 
double comp_comp_maturity_benefits(int t);

// Market Value 
double comp_comp_mkt_val(int t);

// Market Value Sale 
double comp_comp_mkt_val_sale(int t);

// Notional Amount 
double comp_comp_notional_amt(int t);

// Option Budget Amount 
double comp_comp_opt_budget_amt(int t);

// Option Income 
double comp_comp_opt_inc(int t);

// Option Payoff AIG 
double comp_comp_opt_payoff_aig(int t);

// Option Payment 
double comp_comp_opt_pmt(int t);

// Policy Loan 
double comp_comp_pol_loan(int t);

// Policy Loan Expense 
double comp_comp_pol_loan_exp(int t);

// Policy Loan Income 
double comp_comp_pol_loan_inc(int t);

// Policy Loan Interest 
double comp_comp_pol_loan_int(int t);

// Policy Loan Proceeds 
double comp_comp_pol_loan_proceeds(int t);

// Policy Month 
double comp_comp_pol_mth_aig(int t);

// Policy Year 
double comp_comp_pol_yr_aig(int t);

// Policies In Force 
double comp_comp_policies_inf(int t);

// Policies Issued 
double comp_comp_policies_issued(int t);

// Portfolio Yield 
double comp_comp_port_yld(int t);

// Portfolio Yield After Tax 
double comp_comp_port_yld_aft_tax(int t);

// Portfolio Yield Denominator 
double comp_comp_port_yld_denom(int t);

// Portfolio Yield Less Default 
double comp_comp_port_yld_less_dflt(int t);

// Premium Bonus 
double comp_comp_prem_bonus(int t);

// Premium Issued 
double comp_comp_prem_issued(int t);

// Premiums Paid 
double comp_comp_prem_paid(int t);

// Premium Taxes 
double comp_comp_prem_tax(int t);

// Premium Waiver Benefits 
double comp_comp_prem_waiver_benefits(int t);

// Projection Target - Hedging Statement Calculations 
double comp_comp_proj_tgt_hedge_stmt(int t);

// Proxy Bond Generation 
double comp_comp_proxy_bond_generation(int t);

// RBC 
double comp_comp_rbc(int t);

// RBC Before Sales 
double comp_comp_rbc_bef_sale(int t);

// RBC C1 
double comp_comp_rbc_c1(int t);

// RBC C1 Before Sales 
double comp_comp_rbc_c1_bef_sale(int t);

// RBC C1 Equity 
double comp_comp_rbc_c1_eqt(int t);

// RBC C1 Equity Before Sales 
double comp_comp_rbc_c1_eqt_bef_sale(int t);

// RBC C2 
double comp_comp_rbc_c2(int t);

// RBC C3 
double comp_comp_rbc_c3(int t);

// RBC C4 
double comp_comp_rbc_c4(int t);

// Realized Capital Gains 
double comp_comp_realzd_cap_gain(int t);

// Realized Capital Gains Before Sales 
double comp_comp_realzd_cap_gain_bef_sale(int t);

// Realized Capital Gains on Free Surplus 
double comp_comp_realzd_cap_gain_free_surp(int t);

// Realized Capital Gains on Free Surplus Before Sales 
double comp_comp_realzd_cap_gain_free_surp_bef_sale(int t);

// Realized Capital Gains on Free Surplus Calendar Year to Date 
double comp_comp_realzd_cap_gain_free_surp_ytd(int t);

// Realized Capital Gains on Free Surplus Calendar Year to Date Before Sales 
double comp_comp_realzd_cap_gain_free_surp_ytd_bef_sale(int t);

// Realized Capital Gains on Fixed Fund Value 
double comp_comp_realzd_cap_gain_fund(int t);

// Realized Capital Gains on Reserve 
double comp_comp_realzd_cap_gain_res(int t);

// Realized Capital Gains on Reserve Before Sales 
double comp_comp_realzd_cap_gain_res_bef_sale(int t);

// Realized Capital Gains on Reserves Calendar Year to Date 
double comp_comp_realzd_cap_gain_res_ytd(int t);

// Realized Capital Gains on Reserves Calendar Year to Date Before Sales 
double comp_comp_realzd_cap_gain_res_ytd_bef_sale(int t);

// Realized Capital Gains from Sales 
double comp_comp_realzd_cap_gain_sale(int t);

// Realized Capital Gains on Target Capital 
double comp_comp_realzd_cap_gain_tgt_cap(int t);

// Realized Capital Gains on Target Capital Before Sales 
double comp_comp_realzd_cap_gain_tgt_cap_bef_sale(int t);

// Realized Capital Gains on Target Capital Calendar Year to Date 
double comp_comp_realzd_cap_gain_tgt_cap_ytd(int t);

// Realized Capital Gains Target Capital on Calendar Year to Date Before Sales 
double comp_comp_realzd_cap_gain_tgt_cap_ytd_bef_sale(int t);

// Realized Capital Gains on Undistributed Earnings 
double comp_comp_realzd_cap_gain_undistrib_earnings(int t);

// Realized Capital Gains on Undistributed Earnings Before Sales 
double comp_comp_realzd_cap_gain_undistrib_earnings_bef_sale(int t);

// Realized Capital Gains on Undistributed Earnings Calendar Year to Date 
double comp_comp_realzd_cap_gain_undistrib_earnings_ytd(int t);

// Realized Capital Gains on Undistributed Earnings Calendar Year to Date Before Sale 
double comp_comp_realzd_cap_gain_undistrib_earnings_ytd_bef_sale(int t);

// Reinsurance Annuity Benefits Beginning of Month 
double comp_comp_reins_ann_benefits_bom(int t);

// Reinsurance Annuity Benefits End of Month 
double comp_comp_reins_ann_benefits_eom(int t);

// Reinsurance Capital Gains on Reserve 
double comp_comp_reins_cap_gain_res(int t);

// Reinsurance Capital Gains on Reserve Before Sales 
double comp_comp_reins_cap_gain_res_bef_sale(int t);

// Reinsurance Cash Flow Beginning of Month 
double comp_comp_reins_cash_flow_bom(int t);

// Reinsurance Cash Flow End of Month 
double comp_comp_reins_cash_flow_eom(int t);

// Reinsurance Cash Flow Interest 
double comp_comp_reins_cash_flow_int(int t);

// Reinsurance Cash Value 
double comp_comp_reins_cash_val(int t);

// Reinsurance Claim Paid 
double comp_comp_reins_claim_paid(int t);

// Reinsurance Commission Chargeback Reimbursement 
double comp_comp_reins_comm_chargeback_reimb(int t);

// Reinsurance Commission Reimbursed 
double comp_comp_reins_comm_reimb(int t);

// Reinsurance Commission Reimbursement Beginning of Month 
double comp_comp_reins_comm_reimb_bom(int t);

// Reinsurance Commission Reimbursement End of Month 
double comp_comp_reins_comm_reimb_eom(int t);

// Reinsurance Deferred Gross Premium 
double comp_comp_reins_deferred_gross_prem(int t);

// Reinsurance Deferred Gross Premium Increase 
double comp_comp_reins_deferred_gross_prem_incr(int t);

// Reinsurance Deferred Net Premium 
double comp_comp_reins_deferred_net_prem(int t);

// Reinsurance Dividend Applied 
double comp_comp_reins_div_applied(int t);

// Reinsurance Dividend Liability 
double comp_comp_reins_div_liab(int t);

// Reinsurance Dividend Liability Increase 
double comp_comp_reins_div_liab_incr(int t);

// Reinsurance Dividend Paid 
double comp_comp_reins_div_paid(int t);

// Reinsured Death Benefit In Force 
double comp_comp_reins_dth_ben_inf(int t);

// Reinsurance Death Benefits 
double comp_comp_reins_dth_benefits(int t);

// Reinsurance Expense Allowance 
double comp_comp_reins_ea(int t);

// Reinsurance Expense Allowance Chargeback 
double comp_comp_reins_ea_chargeback(int t);

// Reinsurance Endowment Benefits 
double comp_comp_reins_endow_benefits(int t);

// Reinsurance Expense 
double comp_comp_reins_exp(int t);

// Reinsurance Expense Reimbursed 
double comp_comp_reins_exp_reimb(int t);

// Reinsurance Expense Reimbursed Beginning of Month 
double comp_comp_reins_exp_reimb_bom(int t);

// Reinsurance Expense Reimbursed End of Month 
double comp_comp_reins_exp_reimb_eom(int t);

// Reinsurance GAAP Benefit Reserve 
double comp_comp_reins_gaap_ben_res(int t);

// Reinsurance GAAP Benefit Reserve Increase 
double comp_comp_reins_gaap_ben_res_incr(int t);

// Reinsurance GAAP Capital Gain on Reserves 
double comp_comp_reins_gaap_cap_gain_res(int t);

// Reinsurance GAAP Capitalized Commissions BOM 
double comp_comp_reins_gaap_capzd_comm_bom(int t);

// Reinsurance GAAP Capitalized Commissions EOM 
double comp_comp_reins_gaap_capzd_comm_eom(int t);

// Reinsurance GAAP Capitalized Premium Bonus 
double comp_comp_reins_gaap_capzd_prem_bonus(int t);

// Reinsurance GAAP Cash Flow Interest 
double comp_comp_reins_gaap_cash_flow_int(int t);

// Reinsurance GAAP Charges Income 
double comp_comp_reins_gaap_chg_inc(int t);

// Reinsurance GAAP Claim Reserve 
double comp_comp_reins_gaap_claim_res(int t);

// Reinsurance GAAP Claim Reserve Increase 
double comp_comp_reins_gaap_claim_res_incr(int t);

// Reinsurance GAAP Commission Excess BOM 
double comp_comp_reins_gaap_comm_excess_bom(int t);

// Reinsurance GAAP Commission Excess EOM 
double comp_comp_reins_gaap_comm_excess_eom(int t);

// Reinsurance GAAP Commission Trail BOM 
double comp_comp_reins_gaap_comm_trail_bom(int t);

// Reinsurance GAAP Commission Trail EOM 
double comp_comp_reins_gaap_comm_trail_eom(int t);

// Reinsurance GAAP Cost 
double comp_comp_reins_gaap_cost(int t);

// Reinsurance GAAP Credited Interest 
double comp_comp_reins_gaap_credited_int(int t);

// Reinsurance GAAP DAC 
double comp_comp_reins_gaap_dac(int t);

// Reinsurance GAAP DAC Increase 
double comp_comp_reins_gaap_dac_incr(int t);

// Reinsurance GAAP Deferred Maintenance Expense 
double comp_comp_reins_gaap_deferred_maint_exp(int t);

// Reinsurance GAAP Deferred Profit Liability 
double comp_comp_reins_gaap_deferred_prof_liab(int t);

// Reinsurance GAAP Deferred Profit Liability Increase 
double comp_comp_reins_gaap_deferred_prof_liab_incr(int t);

// Reinsurance GAAP Dividend Applied 
double comp_comp_reins_gaap_div_applied(int t);

// Reinsurance GAAP Dividend Liability 
double comp_comp_reins_gaap_div_liab(int t);

// Reinsurance GAAP Dividend Liability Increase 
double comp_comp_reins_gaap_div_liab_incr(int t);

// Reinsurance GAAP Dividend Paid 
double comp_comp_reins_gaap_div_paid(int t);

// Reinsurance GAAP Death Claim Cost 
double comp_comp_reins_gaap_dth_claim_cost(int t);

// Reinsurance GAAP Investment Income on Reserves 
double comp_comp_reins_gaap_inv_inc_res(int t);

// Reinsurance GAAP Recoverables Net of DAC 
double comp_comp_reins_gaap_liab_net(int t);

// Reinsurance GAAP Loads Deducted 
double comp_comp_reins_gaap_loads_deducted(int t);

// Reinsurance GAAP Loads Deferred 
double comp_comp_reins_gaap_loads_deferred(int t);

// Reinsurance GAAP Maintenance Expenses BOM 
double comp_comp_reins_gaap_maint_exp_bom(int t);

// Reinsurance GAAP Maintenance Expenses EOM 
double comp_comp_reins_gaap_maint_exp_eom(int t);

// Reinsurance GAAP Maintenance Expense Reserve 
double comp_comp_reins_gaap_maint_exp_res(int t);

// Reinsurance GAAP Maintenance Expense Reserve Increase 
double comp_comp_reins_gaap_maint_exp_res_incr(int t);

// Reinsurance GAAP Modco Liability 
double comp_comp_reins_gaap_modco_liab(int t);

// Reinsurance GAAP Modco Liability Increase 
double comp_comp_reins_gaap_modco_liab_incr(int t);

// Reinsurance GAAP Modco Reserve Adjustment 
double comp_comp_reins_gaap_modco_res_adj(int t);

// Reinsurance GAAP Premium 
double comp_comp_reins_gaap_prem(int t);

// Reinsurance GAAP Premium Bonus 
double comp_comp_reins_gaap_prem_bonus(int t);

// Reinsurance GAAP Premium Taxes 
double comp_comp_reins_gaap_prem_tax(int t);

// Reinsurance GAAP Premium Waiver Reserve 
double comp_comp_reins_gaap_prem_waiver_res(int t);

// Reinsurance GAAP Premium Waiver Reserve Increase 
double comp_comp_reins_gaap_prem_waiver_res_incr(int t);

// Reinsurance GAAP Recoveries 
double comp_comp_reins_gaap_recoveries(int t);

// Reinsurance GAAP Refund 
double comp_comp_reins_gaap_refund(int t);

// Reinsurance GAAP SFAS 133 Liability 
double comp_comp_reins_gaap_sfas133_liab(int t);

// Reinsurance GAAP SFAS 133 Liability Increase 
double comp_comp_reins_gaap_sfas133_liab_incr(int t);

// Reinsurance GAAP SOP 03-1 Additional Liability 
double comp_comp_reins_gaap_sop031_addl_liab(int t);

// Reinsurance GAAP SOP 03-1 Additional Liability Increase 
double comp_comp_reins_gaap_sop031_addl_liab_incr(int t);

// Reinsurance GAAP Surrender Income 
double comp_comp_reins_gaap_surr_inc(int t);

// Reinsurance GAAP Terminal Dividends 
double comp_comp_reins_gaap_terminal_div(int t);

// Reinsurance GAAP Unearned Revenue Liability 
double comp_comp_reins_gaap_unearn_rev_liab(int t);

// Reinsurance GAAP Unearned Revenue Released 
double comp_comp_reins_gaap_unearn_rev_released(int t);

// Reinsurance GAAP Unrealized Cap Gain Increase 
double comp_comp_reins_gaap_unrealzd_cap_gain_incr(int t);

// Reinsurance IMR Impact on Reserves 
double comp_comp_reins_imr_impact_res(int t);

// Reinsurance IMR Impact on Reserves Before Sales 
double comp_comp_reins_imr_impact_res_bef_sale(int t);

// Reinsurance Investment Fee Refund 
double comp_comp_reins_inv_fee_ref(int t);

// Reinsurance Investment Income Reserve 
double comp_comp_reins_inv_inc_res(int t);

// Reinsurance Maturity Benefits 
double comp_comp_reins_maturity_benefits(int t);

// Modified Coinsurance Reserve Adjustment 
double comp_comp_reins_modco_res_adj(int t);

// Reinsurance Premium 
double comp_comp_reins_prem(int t);

// Reinsurance Premium Tax 
double comp_comp_reins_prem_tax(int t);

// Reinsurance Premium Waiver Benefits 
double comp_comp_reins_prem_waiver_benefits(int t);

// Reinsurance Realized Capital Gains on Reserve 
double comp_comp_reins_realzd_cap_gain_res(int t);

// Reinsurance Realized Capital Gains on Reserve Before Sales 
double comp_comp_reins_realzd_cap_gain_res_bef_sale(int t);

// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date 
double comp_comp_reins_realzd_cap_gain_res_ytd(int t);

// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date Before Sales 
double comp_comp_reins_realzd_cap_gain_res_ytd_bef_sale(int t);

// Reinsurance Refund 
double comp_comp_reins_ref(int t);

// Reinsurance Statutory Claim Reserve 
double comp_comp_reins_stat_claim_res(int t);

// Reinsurance Statutory Claim Reserve Increase 
double comp_comp_reins_stat_claim_res_incr(int t);

// Reinsurance Statutory Cost 
double comp_comp_reins_stat_cost(int t);

// Reinsurance Statutory Cost Before Sales 
double comp_comp_reins_stat_cost_bef_sale(int t);

// Reinsurance Statutory Loading 
double comp_comp_reins_stat_loading(int t);

// Reinsurance Statutory Loading Increase 
double comp_comp_reins_stat_loading_incr(int t);

// Reinsurance Statutory Premium Waiver Reserve 
double comp_comp_reins_stat_prem_waiver_res(int t);

// Reinsurance Statutory Premium Waiver Reserve Increase 
double comp_comp_reins_stat_prem_waiver_res_incr(int t);

// Reinsurance Statutory Reserve 
double comp_comp_reins_stat_res(int t);

// Reinsurance Statutory Reserve Increase 
double comp_comp_reins_stat_res_incr(int t);

// Reinsurance Statutory Unearned Premium Reserve 
double comp_comp_reins_stat_unearn_prem_res(int t);

// Reinsurance Statutory Unearned Premium Reserve Increase 
double comp_comp_reins_stat_unearn_prem_res_incr(int t);

// Reinsurance Surrender Benefits 
double comp_comp_reins_surr_benefits(int t);

// ReinsuranceTax Claim Reserve 
double comp_comp_reins_tax_claim_res(int t);

// Reinsurance Tax Claim Reserve Increase 
double comp_comp_reins_tax_claim_res_incr(int t);

// Reinsurance Tax Deferred Net Premium 
double comp_comp_reins_tax_deferred_net_prem(int t);

// Reinsurance Tax Dividend Liability 
double comp_comp_reins_tax_div_liab(int t);

// Reinsurance Tax Dividend Liability Increase 
double comp_comp_reins_tax_div_liab_incr(int t);

// Reinsurance Tax Loading 
double comp_comp_reins_tax_loading(int t);

// Reinsurance Tax Loading Increase 
double comp_comp_reins_tax_loading_incr(int t);

// Reinsurance Tax Premium Waiver Reserve 
double comp_comp_reins_tax_prem_waiver_res(int t);

// Reinsurance Tax Premium Waiver Reserve Increase 
double comp_comp_reins_tax_prem_waiver_res_incr(int t);

// Reinsurance Tax Reserve 
double comp_comp_reins_tax_res(int t);

// Reinsurance Tax Reserve Increase 
double comp_comp_reins_tax_res_incr(int t);

// Reinsurance Tax Unearned Premium Reserve 
double comp_comp_reins_tax_unearn_prem_res(int t);

// Reinsurance Tax Unearned Premium Reserve Increase 
double comp_comp_reins_tax_unearn_prem_res_incr(int t);

// Reinsurance Terminal Dividends 
double comp_comp_reins_terminal_div(int t);

// Reinsurance Withdrawal Benefits 
double comp_comp_reins_withdrl_benefits(int t);

// Rho Convexity Hedge Investment Amount 
double comp_comp_rho_convex_hedge_inv_amt(int t);

// Rho Convexity Hedge Market Value of Assets 
double comp_comp_rho_convex_hedge_mkt_val(int t);

// Rho Convexity Hedge Market Value of Assets 
double comp_comp_rho_convex_hedge_mkt_val_incr(int t);

// Rho Convexity Derivative Payment 
double comp_comp_rho_convex_hedge_pmt(int t);

// Rho Convexity Hedge Profit 
double comp_comp_rho_convex_hedge_prof(int t);

// Rho Convexity Hedge Sale Amount 
double comp_comp_rho_convex_hedge_sale_amt(int t);

// Rho Convexity Hedge Transaction Cost 
double comp_comp_rho_convex_hedge_transaction_cost(int t);

// Rho Hedge Investment Amount 
double comp_comp_rho_hedge_inv_amt(int t);

// Rho Hedge Market Value of Assets 
double comp_comp_rho_hedge_mkt_val(int t);

// Rho Hedge Market Value of Assets Increase 
double comp_comp_rho_hedge_mkt_val_incr(int t);

// Rho Hedge Derivative Payment 
double comp_comp_rho_hedge_pmt(int t);

// Rho Hedge Profit 
double comp_comp_rho_hedge_prof(int t);

// Rho Hedge Sale Amount 
double comp_comp_rho_hedge_sale_amt(int t);

// Rho Hedge Transaction Cost 
double comp_comp_rho_hedge_transaction_cost(int t);

// Risk Free Rate with no AIG spread 
double comp_comp_risk_free_rate_no_sprd_aig(int t);

// Risk Free Rate with Internal Capital UEL spread 
double comp_comp_risk_free_rate_with_ic_uel_sprd_aig(int t);

// Risk Free Rate with non-UEL AIG spread 
double comp_comp_risk_free_rate_with_no_uel_sprd_aig(int t);

// Risk Free Rate with UEL AIG spread 
double comp_comp_risk_free_rate_with_uel_sprd_aig(int t);

// Sale Income 
double comp_comp_sale_inc(int t);

// Scheduled Principal Payment 
double comp_comp_sched_prin_pmt(int t);

// Shareholder Dividend 
double comp_comp_shldr_div(int t);

// Startup 
virtual double virtual_startup(int t);

// Statutory Claim Expense Reserve 
double comp_comp_stat_claim_exp_res(int t);

// Statutory Claim Expense Reserve Increase 
double comp_comp_stat_claim_exp_res_incr(int t);

// Statutory Claim Incurred 
double comp_comp_stat_claim_incurred(int t);

// Statutory Claim Reserve 
double comp_comp_stat_claim_res(int t);

// Statutory Claim Reserve Increase 
double comp_comp_stat_claim_res_incr(int t);

// Statutory Loading 
double comp_comp_stat_loading(int t);

// Statutory Loading Increase 
double comp_comp_stat_loading_incr(int t);

// Statutory Premium Waiver Expense Reserve 
double comp_comp_stat_prem_waiver_exp_res(int t);

// Statutory Premium Waiver Expense Reserve Increase 
double comp_comp_stat_prem_waiver_exp_res_incr(int t);

// Statutory Premium Waiver Reserve 
double comp_comp_stat_prem_waiver_res(int t);

// Statutory Premium Waiver Reserve Increase 
double comp_comp_stat_prem_waiver_res_incr(int t);

// Statutory Reserve 
double comp_comp_stat_res(int t);

// Base Stat Res 
double comp_comp_stat_res_carvm_base_aig(int t);

// WB Stat Res 
double comp_comp_stat_res_carvm_wb_aig(int t);

// Statutory Excess Reserve 
double comp_comp_stat_res_excess(int t);

// Statutory Reserve Increase 
double comp_comp_stat_res_incr(int t);

// Statutory Policy Reserve 
double comp_comp_stat_res_mp(int t);

// Statutory Reserve Separate Account 
double comp_comp_stat_res_sa(int t);

// Statutory Reserve Separate Account Expense Allowance 
double comp_comp_stat_res_sa_exp_allow(int t);

// XOL Statutory Reserve 
double comp_comp_stat_res_xol_carvm_aig(int t);

// XOL excess reserve 
double comp_comp_stat_res_xol_excess_res_aig(int t);

// XOL new business economic reserve 
double comp_comp_stat_res_xol_nb_eco_res_aig(int t);

// PV of NB Ending XOL Amount 
double comp_comp_stat_res_xol_pv_nb_ending_amount_aig(int t);

// Statutory Unearned Premium Reserve 
double comp_comp_stat_unearn_prem_res(int t);

// Statutory Unearned Premium Reserve Increase 
double comp_comp_stat_unearn_prem_res_incr(int t);

// Surrender Benefits 
double comp_comp_surr_benefits(int t);

// Tax 
double comp_comp_tax(int t);

// Tax Before Sales 
double comp_comp_tax_bef_sale(int t);

// Tax on Book Profit 
double comp_comp_tax_bk_prof(int t);

// Tax on Book Profit Before Sales 
double comp_comp_tax_bk_prof_bef_sale(int t);

// Tax on Book Profit Calendar Year to Date 
double comp_comp_tax_bk_prof_ytd(int t);

// Tax on Book Profit Calendar Year to Date Before Sales 
double comp_comp_tax_bk_prof_ytd_bef_sale(int t);

// Tax Capitalized Premium 
double comp_comp_tax_capzd_prem(int t);

// Tax Capitalized Premium Amortization 
double comp_comp_tax_capzd_prem_amortzn(int t);

// Tax Capitalized Premium Unamortized 
double comp_comp_tax_capzd_prem_unamortzd(int t);

// Tax Claim Expense Reserve 
double comp_comp_tax_claim_exp_res(int t);

// Tax Claim Reserve 
double comp_comp_tax_claim_res(int t);

// Tax Claim Reserve Increase 
double comp_comp_tax_claim_res_incr(int t);

// Tax Deferred Net Premium 
double comp_comp_tax_deferred_net_prem(int t);

// Tax Dividend Liability 
double comp_comp_tax_div_liab(int t);

// Tax Dividend Liability Increase 
double comp_comp_tax_div_liab_incr(int t);

// Tax on Accumulated Earnings 
double comp_comp_tax_earnings_accum(int t);

// Tax on Accumulated Earnings Calendar Year to Date 
double comp_comp_tax_earnings_accum_ytd(int t);

// Tax Exempt Income 
double comp_comp_tax_exempt_inc(int t);

// Tax Exempt Income Book Profit 
double comp_comp_tax_exempt_inc_bk_prof(int t);

// Tax Exempt Income Free Surplus 
double comp_comp_tax_exempt_inc_free_surp(int t);

// Tax Exempt Income Target Capital 
double comp_comp_tax_exempt_inc_tgt_cap(int t);

// Tax on Free Surplus Income 
double comp_comp_tax_free_surp(int t);

// Tax on Free Surplus Income Before Sales 
double comp_comp_tax_free_surp_bef_sale(int t);

// Tax on Free Surplus Income Calendar Year to Date 
double comp_comp_tax_free_surp_ytd(int t);

// Tax on Free Surplus Income Calendar Year to Date Before Sales 
double comp_comp_tax_free_surp_ytd_bef_sale(int t);

// Tax Loading 
double comp_comp_tax_loading(int t);

// Tax Loading Increase 
double comp_comp_tax_loading_incr(int t);

// Tax Premium Waiver Expense Reserve 
double comp_comp_tax_prem_waiver_exp_res(int t);

// Tax Premium Waiver Reserve 
double comp_comp_tax_prem_waiver_res(int t);

// Tax Premium Waiver Reserve Increase 
double comp_comp_tax_prem_waiver_res_incr(int t);

// Tax Reserve 
double comp_comp_tax_res(int t);

// Tax Reserve Increase 
double comp_comp_tax_res_incr(int t);

// Tax on Target Capital Income 
double comp_comp_tax_tgt_cap(int t);

// Tax on Target Capital Income Before Sale 
double comp_comp_tax_tgt_cap_bef_sale(int t);

// Tax on Target Capital Income Calendar Year to Date 
double comp_comp_tax_tgt_cap_ytd(int t);

// Tax on Target Capital Income Calendar Year to Date Before Sales 
double comp_comp_tax_tgt_cap_ytd_bef_sale(int t);

// Tax Transfers to Separate Account Net 
double comp_comp_tax_transfer_to_sa_net(int t);

// Tax Unearned Premium Reserve 
double comp_comp_tax_unearn_prem_res(int t);

// Tax Unearned Premium Reserve Increase 
double comp_comp_tax_unearn_prem_res_incr(int t);

// Taxable Income Addition 
double comp_comp_taxable_inc_addn(int t);

// Taxable Income Book Profit 
double comp_comp_taxable_inc_bk_prof(int t);

// Taxable Income Book Profit Before Sales 
double comp_comp_taxable_inc_bk_prof_bef_sale(int t);

// Taxable Income Book Profit Calendar Year to Date 
double comp_comp_taxable_inc_bk_prof_ytd(int t);

// Taxable Income Book Profit Calendar Year to Date Before Sales 
double comp_comp_taxable_inc_bk_prof_ytd_bef_sale(int t);

// Taxable Income Carry Forward Addition Calendar Year to Date 
double comp_comp_taxable_inc_carryfwd_addn_ytd(int t);

// Taxable Income Carry Forward Applied Calendar Year to Date 
double comp_comp_taxable_inc_carryfwd_applied_ytd(int t);

// Taxable Income Carry Forward Available 
double comp_comp_taxable_inc_carryfwd_avail(int t);

// Taxable Income Accumulated Earnings 
double comp_comp_taxable_inc_earnings_accum(int t);

// Taxable Income Accumulated Earnings Calendar Year to Date 
double comp_comp_taxable_inc_earnings_accum_ytd(int t);

// Taxable Income Free Surplus 
double comp_comp_taxable_inc_free_surp(int t);

// Taxable Income Free Surplus Before Sales 
double comp_comp_taxable_inc_free_surp_bef_sale(int t);

// Taxable Income Free Surplus Calendar Year to Date 
double comp_comp_taxable_inc_free_surp_ytd(int t);

// Taxable Income Free Surplus Calendar Year to Date Before Sales 
double comp_comp_taxable_inc_free_surp_ytd_bef_sale(int t);

// Taxable Income Target Capital 
double comp_comp_taxable_inc_tgt_cap(int t);

// Taxable Income Target Capital Before Sale 
double comp_comp_taxable_inc_tgt_cap_bef_sale(int t);

// Taxable Income Target Capital Calendar Year to Date 
double comp_comp_taxable_inc_tgt_cap_ytd(int t);

// Taxable Income Target Captial Calendar Year to Date Before Sales 
double comp_comp_taxable_inc_tgt_cap_ytd_bef_sale(int t);

// Terminal Dividends 
double comp_comp_terminal_div(int t);

// Target Capital 
double comp_comp_tgt_cap(int t);

// Target Capital Before Sales 
double comp_comp_tgt_cap_bef_sale(int t);

// Target Capital Effect 
double comp_comp_tgt_cap_effect(int t);

// Target Capital Effect Before Sales 
double comp_comp_tgt_cap_effect_bef_sale(int t);

// Target Capital Increase 
double comp_comp_tgt_cap_incr(int t);

// Target Capital Increase Before Sales 
double comp_comp_tgt_cap_incr_bef_sale(int t);

// Transfer Cash Flow Separate Account Beginning of Month 
double comp_comp_transfer_cash_flow_sa_bom(int t);

// Transfer Cash Flow Separate Account End of Month 
double comp_comp_transfer_cash_flow_sa_eom(int t);

// Transfers to Separate Account Net 
double comp_comp_transfer_to_sa_net(int t);

// Undistributed Earnings 
double comp_comp_undistrib_earnings(int t);

// Unrealized Capital Gain Increase 
double comp_comp_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Increase Before Sales 
double comp_comp_unrealzd_cap_gain_incr_bef_sale(int t);

// Unrealized Capital Gain Released on Sale 
double comp_comp_unrealzd_cap_gain_released_on_sale(int t);

// Valuation Target - Ag38 8D Reserve 
double comp_comp_valn_tgt_ag38_8d(int t);

// Valuation Target - GAAP SFAS 120 
double comp_comp_valn_tgt_gaap_sfas120(int t);

// Valuation Target - GAAP SFAS 91 
double comp_comp_valn_tgt_gaap_sfas91(int t);

// Valuation Target - GAAP SFAS 97 Retrospective Deposit 
double comp_comp_valn_tgt_gaap_sfas97rd(int t);

// Valuation Target - GAAP SOP 03-1 
double comp_comp_valn_tgt_gaap_sop031(int t);

// Valuation Target - Hedging Final 
double comp_comp_valn_tgt_hedge_final(int t);

// Valuation Target - Hedging Shock 
double comp_comp_valn_tgt_hedge_shock(int t);

// Valuation Target - PBA Policy Reserve 
double comp_comp_valn_tgt_pba_pol_res(int t);

// Valuation Target - PBA RBC Standard Scenario Step 2 
double comp_comp_valn_tgt_pba_rbc_std_scen_step2(int t);

// Valuation Target - PBA Scenario Amount 
double comp_comp_valn_tgt_pba_scen_amt(int t);

// Vega Hedge Investment Amount 
double comp_comp_vega_hedge_inv_amt(int t);

// Vega Hedge Market Value of Assets 
double comp_comp_vega_hedge_mkt_val(int t);

// Vega Hedge Market Value of Assets Increase 
double comp_comp_vega_hedge_mkt_val_incr(int t);

// Vega Hedge Derivative Payment 
double comp_comp_vega_hedge_pmt(int t);

// Vega Hedge Profit 
double comp_comp_vega_hedge_prof(int t);

// Vega Hedge Sale Amount 
double comp_comp_vega_hedge_sale_amt(int t);

// Vega Hedge Transaction Cost 
double comp_comp_vega_hedge_transaction_cost(int t);

// Withdrawal Benefits 
double comp_comp_withdrl_benefits(int t);

// XOL Amount 
double comp_comp_xol_amount_aig(int t);

// XOL Prem Aig 
double comp_comp_xol_prem_aig(int t);

// Months Since Projection Start At Projection Date 
int  comp_comp_elapsed_mths_aig();

// Final Period 
int  comp_comp_final_period();

// Product Type Indicator 
int  comp_comp_prod_type_indicator();

// Projection Date Adjusted 
xstring  comp_comp_proj_date_adj();

// Projection Start Date 
int  comp_comp_proj_start_date();

// Projection Start Mth 
int  comp_comp_proj_start_mth();

// Projection Start Yr 
int  comp_comp_proj_start_yr();

// Reinsurance Flag 
int  comp_comp_reins_flag();

// Start Period 
int  comp_comp_start_period();

// State Of World Financial File Path 
xstring  comp_comp_state_of_world_financial_file_path();


};
#endif
