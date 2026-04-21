
#ifndef __SFAS133_GAAP_UDF_H_
#define __SFAS133_GAAP_UDF_H_

#include "ModelClass\sfas133_gaap.h"

class SFAS133_GAAP_UDF : public SFAS133_GAAP {

	friend class SFAS133_GAAP;

//constructor 
SFAS133_GAAP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: SFAS133_GAAP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
SFAS133_GAAP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : SFAS133_GAAP(columnCount, mocd, persObj) {}


// Calendar Month 
double sfas133_gaap_cal_mth(int t);

// Calendar Year 
double sfas133_gaap_cal_yr(int t);

// Calendar Year Relative 
double sfas133_gaap_cal_yr_relative(int t);

// Credit Risk 
double sfas133_gaap_credit_risk_calc(int t);

// Date 
double sfas133_gaap_date(int t);

// Fund Value 
double sfas133_gaap_fund_val(int t);

// GAAP Interest Rate 
double sfas133_gaap_gaap_int_rate(int t);

// GMAB Charge 
double sfas133_gaap_gmab_chg(int t);

// GMAB Econ Claim 
double sfas133_gaap_gmab_claim(int t);

// GMAB Liability 
double sfas133_gaap_gmab_liab(int t);

// GMAB Required Profit Charge 
double sfas133_gaap_gmab_req_prof_chg(int t);

// GMIB Charge 
double sfas133_gaap_gmib_chg(int t);

// GMIB Econ Claim 
double sfas133_gaap_gmib_claim(int t);

// GMIB Liability 
double sfas133_gaap_gmib_liab(int t);

// GMIB Required Profit Charge 
double sfas133_gaap_gmib_req_prof_chg(int t);

// GMWB Charge 
double sfas133_gaap_gmwb_chg(int t);

// GMWB Econ Claim 
double sfas133_gaap_gmwb_claim(int t);

// GMWB Liability 
double sfas133_gaap_gmwb_liab(int t);

// GMWB Required Profit Charge 
double sfas133_gaap_gmwb_req_prof_chg(int t);

// Initialize 
double sfas133_gaap_initialize(int t);

// Policies In Force 
double sfas133_gaap_policies_inf(int t);

// PV of GMAB Charges 
double sfas133_gaap_pv_gmab_chg(int t);

// PV of GMAB Claim 
double sfas133_gaap_pv_gmab_claim(int t);

// PV of GMIB Charges 
double sfas133_gaap_pv_gmib_chg(int t);

// PV of GMIB Claim 
double sfas133_gaap_pv_gmib_claim(int t);

// PV of GMWB Charges 
double sfas133_gaap_pv_gmwb_chg(int t);

// PV of GMWB Claim 
double sfas133_gaap_pv_gmwb_claim(int t);

// Startup 
virtual double virtual_startup(int t);

// Final Period 
int  sfas133_gaap_final_period();

// GMIB Definition 
int  sfas133_gaap_gmib_defn();

// GMIB SFAS133 Flag 
int  sfas133_gaap_gmib_sfas133_flag();

// GMWB Definition 
int  sfas133_gaap_gmwb_defn();

// GMWB SFAS133 Flag 
int  sfas133_gaap_gmwb_sfas133_flag();

// Projection Date Adjusted 
xstring  sfas133_gaap_proj_date_adj();

// Projection Start Date 
int  sfas133_gaap_proj_start_date();

// Projection Start Mth 
int  sfas133_gaap_proj_start_mth();

// Projection Start Yr 
int  sfas133_gaap_proj_start_yr();

// Reinsurance Flag 
int  sfas133_gaap_reins_flag();

// Start Period 
int  sfas133_gaap_start_period();


};
#endif
