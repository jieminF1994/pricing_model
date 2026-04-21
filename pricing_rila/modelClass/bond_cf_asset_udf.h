
#ifndef __BOND_CF_ASSET_UDF_H_
#define __BOND_CF_ASSET_UDF_H_

#include "ModelClass\bond_cf_asset.h"

class BOND_CF_ASSET_UDF : public BOND_CF_ASSET {

	friend class BOND_CF_ASSET;

//constructor 
BOND_CF_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: BOND_CF_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
BOND_CF_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : BOND_CF_ASSET(columnCount, mocd, persObj) {}


// Accrued Interest 
double bond_cf_asset_accr_int(int t);

// Accrued Interest After Defaults 
double bond_cf_asset_accr_int_aft_dflt(int t);

// Accrued Interest After Puts 
double bond_cf_asset_accr_int_aft_put(int t);

// Accrued Interest Before Call 
double bond_cf_asset_accr_int_bef_call(int t);

// Accrued Interest Before Sales 
double bond_cf_asset_accr_int_bef_sale(int t);

// Call Amount 
double bond_cf_asset_call_amt(int t);

// Call Income 
double bond_cf_asset_call_inc(int t);

// Call Percent 
double bond_cf_asset_call_pct(int t);

// Call Percent Monthly 
double bond_cf_asset_call_pct_mthly(int t);

// Call Price Percent 
double bond_cf_asset_call_price_pct(int t);

// Interest Payment 
double bond_cf_asset_int_pmt(int t);

// Interest Rate for Call Option 
double bond_cf_asset_int_rate_for_call_opt(int t);

// Interest Savings Present Value Before Call 
double bond_cf_asset_int_savings_pv_bef_call(int t);

// Par Value 
double bond_cf_asset_par_val(int t);

// Par Value After Call 
double bond_cf_asset_par_val_aft_call(int t);

// Par Value After Defaults 
double bond_cf_asset_par_val_aft_dflt(int t);

// Par Value After Puts 
double bond_cf_asset_par_val_aft_put(int t);

// Par Value After Scheduled Payments 
double bond_cf_asset_par_val_aft_sched_pmt(int t);

// Par Value Before Sales 
double bond_cf_asset_par_val_bef_sale(int t);

// Payment Rate 
double bond_cf_asset_pmt_rate(int t);

// Put Amount 
double bond_cf_asset_put_amt(int t);

// Put Income 
double bond_cf_asset_put_inc(int t);

// Put Percent 
double bond_cf_asset_put_pct(int t);

// Put Percent Monthly 
double bond_cf_asset_put_pct_mthly(int t);

// Put Price Percent 
double bond_cf_asset_put_price_pct(int t);

// Refinancing Rate 
double bond_cf_asset_refinancing_rate(int t);

// Remaining Percent After Defaults 
double bond_cf_asset_remaining_pct_aft_dflt(int t);

// Remaining Percent After Scheduled Paymentss 
double bond_cf_asset_remaining_pct_aft_sched_pmt(int t);

// Renewal Rate 
double bond_cf_asset_renewal_rate(int t);

// Scheduled Principal Payment 
double bond_cf_asset_sched_prin_pmt(int t);

// Sinking Fund Payment 
double bond_cf_asset_sinking_fund_pmt(int t);

// Sinking Fund Payment Income 
double bond_cf_asset_sinking_fund_pmt_inc(int t);

// Startup 
virtual double virtual_startup(int t);

// Yield Maintenance Cash Flow Percent Before Call 
double bond_cf_asset_yld_maint_cash_flow_pct_bef_call(int t);

// Yield Maintenance Cost Percent 
double bond_cf_asset_yld_maint_cost_pct(int t);

// Yield Maintenance Rate 
double bond_cf_asset_yld_maint_rate(int t);

// Projection Start Date 
int  bond_cf_asset_proj_start_date();


};
#endif
