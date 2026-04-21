
#ifndef __MTG_CF_ASSET_UDF_H_
#define __MTG_CF_ASSET_UDF_H_

#include "ModelClass\mtg_cf_asset.h"

class MTG_CF_ASSET_UDF : public MTG_CF_ASSET {

	friend class MTG_CF_ASSET;

//constructor 
MTG_CF_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: MTG_CF_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
MTG_CF_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : MTG_CF_ASSET(columnCount, mocd, persObj) {}


// Accrued Interest 
double mtg_cf_asset_accr_int(int t);

// Accrued Interest After Defaults 
double mtg_cf_asset_accr_int_aft_dflt(int t);

// Accrued Interest After Prepayments 
double mtg_cf_asset_accr_int_aft_prepmt(int t);

// Accrued Interest Before Prepayments 
double mtg_cf_asset_accr_int_bef_prepmt(int t);

// Accrued Interest Before Sales 
double mtg_cf_asset_accr_int_bef_sale(int t);

// ADCo Prepayment Forecast 
double mtg_cf_asset_adco_prepmt_forecast(int t);

// Balloon Payment 
double mtg_cf_asset_balloon_pmt(int t);

// Balloon Payment Income 
double mtg_cf_asset_balloon_pmt_inc(int t);

// Interest Payment 
double mtg_cf_asset_int_pmt(int t);

// Interest Savings Present Value After Prepayments 
double mtg_cf_asset_int_savings_pv_aft_prepmt(int t);

// Interest Savings Present Value Before Prepayments 
double mtg_cf_asset_int_savings_pv_bef_prepmt(int t);

// Intex Payment Processed 
double mtg_cf_asset_intex_pmt_processed(int t);

// Months Since Issue 
double mtg_cf_asset_mths_since_issue(int t);

// Par Value 
double mtg_cf_asset_par_val(int t);

// Par Value After Defaults 
double mtg_cf_asset_par_val_aft_dflt(int t);

// Par Value After Prepayments 
double mtg_cf_asset_par_val_aft_prepmt(int t);

// Par Value After Scheduled Payments 
double mtg_cf_asset_par_val_aft_sched_pmt(int t);

// Par Value Before Sales 
double mtg_cf_asset_par_val_bef_sale(int t);

// Par Value for Balloon Payment After Defaults 
double mtg_cf_asset_par_val_for_balloon_pmt_aft_dflt(int t);

// Par Value for Balloon Payment Before Sales 
double mtg_cf_asset_par_val_for_balloon_pmt_bef_sale(int t);

// Payment Amount After Defaults 
double mtg_cf_asset_pmt_amt_aft_dflt(int t);

// Payment Amount After Scheduled Payments Amount 
double mtg_cf_asset_pmt_amt_aft_sched_payment(int t);

// Payment Amount Before Sales 
double mtg_cf_asset_pmt_amt_bef_sale(int t);

// Payment Rate 
double mtg_cf_asset_pmt_rate(int t);

// Prepayment Amount 
double mtg_cf_asset_prepmt_amt(int t);

// Prepayment Income 
double mtg_cf_asset_prepmt_inc(int t);

// Prepayment Percent 
double mtg_cf_asset_prepmt_pct(int t);

// Prepayment Percent Monthly 
double mtg_cf_asset_prepmt_pct_mthly(int t);

// Prepayment Penalty 
double mtg_cf_asset_prepmt_penalty(int t);

// Refinancing Rate 
double mtg_cf_asset_refinancing_rate(int t);

// Remaining Percent After Defaults 
double mtg_cf_asset_remaining_pct_aft_dflt(int t);

// Remaining Percent After Scheduled Payments 
double mtg_cf_asset_remaining_pct_aft_sched_pmt(int t);

// Renewal Rate 
double mtg_cf_asset_renewal_rate(int t);

// Scheduled Principal Payment 
double mtg_cf_asset_sched_prin_pmt(int t);

// Since Foreclosure Interest Multiple 
double mtg_cf_asset_since_foreclosure_int_mult(int t);

// Since Foreclosure Principal Payment Multiple 
double mtg_cf_asset_since_foreclosure_prin_pmt_mult(int t);

// Since Restructure Interest Multiple 
double mtg_cf_asset_since_restructure_int_mult(int t);

// Since Restructure Principal Payment Multiple 
double mtg_cf_asset_since_restructure_prin_pmt_mult(int t);

// Startup 
virtual double virtual_startup(int t);

// Tranche Portion 
double mtg_cf_asset_tranche_portion(int t);

// Tranche Portion After Defaults 
double mtg_cf_asset_tranche_portion_aft_dflt(int t);

// Tranche Portion Before Sales 
double mtg_cf_asset_tranche_portion_bef_sale(int t);

// Yield Maintenance Cash Flow Percent Before Prepayments 
double mtg_cf_asset_yld_maint_cash_flow_pct_bef_prepmt(int t);

// Yield Maintenance Cost Percent 
double mtg_cf_asset_yld_maint_cost_pct(int t);

// Yield Maintenance Rate 
double mtg_cf_asset_yld_maint_rate(int t);


};
#endif
