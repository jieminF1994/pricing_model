
#ifndef __BOND_PORTFOLIO_AIG_UDF_H_
#define __BOND_PORTFOLIO_AIG_UDF_H_

#include "ModelClass\bond_portfolio_aig.h"

class BOND_PORTFOLIO_AIG_UDF : public BOND_PORTFOLIO_AIG {

	friend class BOND_PORTFOLIO_AIG;

//constructor 
BOND_PORTFOLIO_AIG_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: BOND_PORTFOLIO_AIG(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
BOND_PORTFOLIO_AIG_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : BOND_PORTFOLIO_AIG(columnCount, mocd, persObj) {}


// Bond Asset Amount, Beginning of Period 
double bond_portfolio_aig_asset_amt_b_aig(int t);

// Bond Asset Amount, End of Period 
double bond_portfolio_aig_asset_amt_e_aig(int t);

// Asset Amount Matured, End of Period 
double bond_portfolio_aig_asset_amt_matured_aig(int t);

// New Asset Amount Purchased, End of Period 
double bond_portfolio_aig_asset_amt_new_aig(int t);

// Average Coupon Rate, End of Period 
double bond_portfolio_aig_avg_coupon_rt_aig(int t);

// Cash Flow Percentage 
double bond_portfolio_aig_cash_flow_pct_aig(int t);

// Coupon Amount 
double bond_portfolio_aig_coupon_amt_aig(int t);

// Current Asset Duration 
double bond_portfolio_aig_duration_curr_asset_aig(int t);

// New Asset Duration 
double bond_portfolio_aig_duration_new_asset_aig(int t);

// Target Asset Duration (Months) 
double bond_portfolio_aig_duration_target_asset_aig(int t);

// Initialize 
double bond_portfolio_aig_initialize(int t);

// New Money Rate 
double bond_portfolio_aig_new_money_rate_aig(int t);

// Policy Year 
double bond_portfolio_aig_pol_yr(int t);

// Startup 
virtual double virtual_startup(int t);

// Commencement Period 
int  bond_portfolio_aig_commencement_period();

// Number of Periods Between Coupons 
int  bond_portfolio_aig_coupon_freq_aig();

// WTW - Gen2 - final period for time guards 
int  bond_portfolio_aig_final_period();

// Initialize Bond Portfolio? 
int  bond_portfolio_aig_initialize_bond_portfolio_aig();

// Period t in which Policy Matures 
int  bond_portfolio_aig_maturity_period();


};
#endif
