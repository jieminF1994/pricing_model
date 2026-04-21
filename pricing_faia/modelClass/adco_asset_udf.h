
#ifndef __ADCO_ASSET_UDF_H_
#define __ADCO_ASSET_UDF_H_

#include "ModelClass\adco_asset.h"

class ADCO_ASSET_UDF : public ADCO_ASSET {

	friend class ADCO_ASSET;

//constructor 
ADCO_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: ADCO_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
ADCO_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : ADCO_ASSET(columnCount, mocd, persObj) {}


// Calendar Month 
double adco_asset_cal_mth(int t);

// Calendar Year 
double adco_asset_cal_yr(int t);

// Calendar Year Relative 
double adco_asset_cal_yr_relative(int t);

// Date 
double adco_asset_date(int t);

// Finalize 
double adco_asset_finalize(int t);

// Get Prepayment Rate 
double adco_asset_get_prepmt_rate(int t);

// Initialize 
double adco_asset_initialize(int t);

// Process ADCo detail 
double adco_asset_process_adco_detail(int t);

// Startup 
virtual double virtual_startup(int t);

// Detail Report Flag 
int  adco_asset_asset_detail_rpt_flag();

// Underlying  index 
int  adco_asset_index();

// Loan issuer 
int  adco_asset_issuer();

// Loan Type 
int  adco_asset_loan_type();

// Original Projection Start Mth 
int  adco_asset_orig_proj_start_mth();

// Original Projection Start Yr 
int  adco_asset_orig_proj_start_yr();

// Output File 
xstring  adco_asset_output_file();

// Output Path 
xstring  adco_asset_output_path();

// Projection Date Adjusted 
xstring  adco_asset_proj_date_adj();

// Projection Start Mth 
int  adco_asset_proj_start_mth();

// Projection Start Yr 
int  adco_asset_proj_start_yr();

// Start Period 
int  adco_asset_start_period();


};
#endif
