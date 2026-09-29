
#ifndef __MRB_GAAP_UDF_H_
#define __MRB_GAAP_UDF_H_

#include "ModelClass\mrb_gaap.h"

class MRB_GAAP_UDF : public MRB_GAAP {

	friend class MRB_GAAP;

//constructor 
MRB_GAAP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: MRB_GAAP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
MRB_GAAP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : MRB_GAAP(columnCount, mocd, persObj) {}


// Calendar Month 
double mrb_gaap_cal_mth(int t);
// Calendar Year 
double mrb_gaap_cal_yr(int t);
// Calendar Year Relative 
double mrb_gaap_cal_yr_relative(int t);
// Credit Risk Column Calulation 
double mrb_gaap_credit_risk_col(int t);
// Date 
double mrb_gaap_date(int t);
// Fund Value 
double mrb_gaap_fund_val(int t);
// GAAP Interest Rate 
double mrb_gaap_gaap_int_rate(int t);
// GMAB Charge 
double mrb_gaap_gmab_chg(int t);
// GMAB Econ Claim 
double mrb_gaap_gmab_claim(int t);
// GMAB Liability 
double mrb_gaap_gmab_liab(int t);
// GMAB Required Profit Charge 
double mrb_gaap_gmab_req_prof_chg(int t);
// GMDB Charge 
double mrb_gaap_gmdb_chg(int t);
// GMDB Claim 
double mrb_gaap_gmdb_claim(int t);
// GMDB Liability 
double mrb_gaap_gmdb_liab(int t);
// GMDB Required Profit Charge 
double mrb_gaap_gmdb_req_prof_chg(int t);
// GMIB Charge 
double mrb_gaap_gmib_chg(int t);
// GMIB Econ Claim 
double mrb_gaap_gmib_claim(int t);
// GMIB Liability 
double mrb_gaap_gmib_liab(int t);
// GMIB Required Profit Charge 
double mrb_gaap_gmib_req_prof_chg(int t);
// GMWB Charge 
double mrb_gaap_gmwb_chg(int t);
// GMWB Econ Claim 
double mrb_gaap_gmwb_claim(int t);
// GMWB Liability 
double mrb_gaap_gmwb_liab(int t);
// GMWB Required Profit Charge 
double mrb_gaap_gmwb_req_prof_chg(int t);
// Initialize 
double mrb_gaap_initialize(int t);
// Policies In Force 
double mrb_gaap_policies_inf(int t);
// PV of GMAB Charges 
double mrb_gaap_pv_gmab_chg(int t);
// PV of GMAB Claim 
double mrb_gaap_pv_gmab_claim(int t);
// PV of GMDB Charges 
double mrb_gaap_pv_gmdb_chg(int t);
// PV of GMDB Claim 
double mrb_gaap_pv_gmdb_claim(int t);
// PV of GMIB Charges 
double mrb_gaap_pv_gmib_chg(int t);
// PV of GMIB Claim 
double mrb_gaap_pv_gmib_claim(int t);
// PV of GMWB Charges 
double mrb_gaap_pv_gmwb_chg(int t);
// PV of GMWB Claim 
double mrb_gaap_pv_gmwb_claim(int t);
// Startup 
virtual double virtual_startup(int t);
// Final Period 
int  mrb_gaap_final_period();
// Projection Date Adjusted 
xstring  mrb_gaap_proj_date_adj();
// Projection Start Date 
int  mrb_gaap_proj_start_date();
// Projection Start Mth 
int  mrb_gaap_proj_start_mth();
// Projection Start Yr 
int  mrb_gaap_proj_start_yr();
// Reinsurance Flag 
int  mrb_gaap_reins_flag();
// Start Period 
int  mrb_gaap_start_period();

};
#endif
