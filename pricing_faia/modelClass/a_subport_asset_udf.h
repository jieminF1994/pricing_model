
#ifndef __A_SUBPORT_ASSET_UDF_H_
#define __A_SUBPORT_ASSET_UDF_H_

#include "ModelClass\a_subport_asset.h"

class A_SUBPORT_ASSET_UDF : public A_SUBPORT_ASSET {

	friend class A_SUBPORT_ASSET;

//constructor 
A_SUBPORT_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: A_SUBPORT_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
A_SUBPORT_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : A_SUBPORT_ASSET(columnCount, mocd, persObj) {}


// Accrued Dividend 
double a_subport_asset_accr_div(int t);

// Accrued Income 
double a_subport_asset_accr_inc(int t);

// Accrued Interest After Default 
double a_subport_asset_accr_int_aft_dflt(int t);

// Accrued Interest Default 
double a_subport_asset_accr_int_dflt(int t);

// Accrued Interest Rent 
double a_subport_asset_accr_int_rent(int t);

// Accrued Interest Rent Investment Assets 
double a_subport_asset_accr_int_rent_inv(int t);

// Asset Yield 
double a_subport_asset_asset_yld(int t);

// Asset Yield Denominator 
double a_subport_asset_asset_yld_denom(int t);

// Asset Yield Numerator 
double a_subport_asset_asset_yld_numer(int t);

// Base Cost Basis 
double a_subport_asset_base_cost_basis(int t);

// Book Value 
double a_subport_asset_bk_val(int t);

// Book Value Increase 
double a_subport_asset_bk_val_incr(int t);

// Book Value Investment Assets 
double a_subport_asset_bk_val_inv(int t);

// Book Value Plus Accrued Interest 
double a_subport_asset_bk_val_plus_accr_int(int t);

// Calendar Month 
double a_subport_asset_cal_mth(int t);

// Calendar Year 
double a_subport_asset_cal_yr(int t);

// Calendar Year Relative 
double a_subport_asset_cal_yr_relative(int t);

// Capital Gains 
double a_subport_asset_cap_gain(int t);

// Capital Gains Before Sales 
double a_subport_asset_cap_gain_bef_sale(int t);

// Capital Gains From Sales 
double a_subport_asset_cap_gain_from_sale(int t);

// Cash Flow 
double a_subport_asset_cash_flow(int t);

// Cost Basis 
double a_subport_asset_cost_basis(int t);

// Cost Basis Accrual 
double a_subport_asset_cost_basis_accrual(int t);

// Cost Basis Default 
double a_subport_asset_cost_basis_dflt(int t);

// Cost Basis Growth 
double a_subport_asset_cost_basis_growth(int t);

// Cost Basis Increase Accrued Dividend 
double a_subport_asset_cost_basis_incr_accr_div(int t);

// Cost Basis Increase from Appreciation 
double a_subport_asset_cost_basis_incr_appreciation(int t);

// Cost Basis Increase Index Asset Turnover 
double a_subport_asset_cost_basis_incr_index_asset_turnover(int t);

// Cost Basis Option Payment 
double a_subport_asset_cost_basis_opt_pmt(int t);

// Cost Basis Purchase 
double a_subport_asset_cost_basis_purch(int t);

// Cost Basis Sale 
double a_subport_asset_cost_basis_sale(int t);

// Cost Basis Scheduled Principal Payment 
double a_subport_asset_cost_basis_sched_prin_pmt(int t);

// Cost Basis Transaction 
double a_subport_asset_cost_basis_transaction(int t);

// Cost Basis Transfer 
double a_subport_asset_cost_basis_transfer(int t);

// Depreciation 
double a_subport_asset_depreciation(int t);

// Default Amount 
double a_subport_asset_dflt_amt(int t);

// Effective Duration 
double a_subport_asset_eff_dur(int t);

// Initialize 
double a_subport_asset_initialize(int t);

// Interest Dividend and Rent 
double a_subport_asset_int_div_and_rent(int t);

// Interest Net 
double a_subport_asset_int_net(int t);

// Investment Expenses 
double a_subport_asset_inv_exp(int t);

// Investment Expenses Investment Assets 
double a_subport_asset_inv_exp_inv(int t);

// Investment Expenses Tax Exempt Assets 
double a_subport_asset_inv_exp_tax_exempt(int t);

// Market Value 
double a_subport_asset_mkt_val(int t);

// Market Value Cost Basis Increase 
double a_subport_asset_mkt_val_cost_basis_incr(int t);

// Market Value for Effective Duration 
double a_subport_asset_mkt_val_for_eff_dur(int t);

// Market Value Times Effective Duration 
double a_subport_asset_mkt_val_times_eff_dur(int t);

// Notional Amount 
double a_subport_asset_notional_amt(int t);

// Option Income 
double a_subport_asset_opt_inc(int t);

// Option Payment 
double a_subport_asset_opt_pmt(int t);

// Realized Capital Gain 
double a_subport_asset_realzd_cap_gain(int t);

// Realized Capital Gain Net 
double a_subport_asset_realzd_cap_gain_net(int t);

// Realized Capital Gain from Option Payment 
double a_subport_asset_realzd_cap_gain_opt_pmt(int t);

// Realized Capital Gain from Principal Payment 
double a_subport_asset_realzd_cap_gain_prin_pmt(int t);

// Realized Capital Gain from Sales 
double a_subport_asset_realzd_cap_gain_sale(int t);

// Realized Capital Gain from Turnover 
double a_subport_asset_realzd_cap_gain_turnover(int t);

// Sale Income 
double a_subport_asset_sale_inc(int t);

// Scheduled Principal Payment 
double a_subport_asset_sched_prin_pmt(int t);

// Startup 
virtual double virtual_startup(int t);

// Unrealized Capital Gain 
double a_subport_asset_unrealzd_cap_gain(int t);

// Unrealized Capital Gain Hidden 
double a_subport_asset_unrealzd_cap_gain_hidden(int t);

// Unrealized Capital Gain Increase 
double a_subport_asset_unrealzd_cap_gain_incr(int t);

// Unrealized Capital Gain Released from Sales 
double a_subport_asset_unrealzd_cap_gain_released_on_sale(int t);


};
#endif
