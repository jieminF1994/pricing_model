
#ifndef __ASSET_ASSET_UDF_H_
#define __ASSET_ASSET_UDF_H_

#include "ModelClass\asset_asset.h"

class ASSET_ASSET_UDF : public ASSET_ASSET {

	friend class ASSET_ASSET;

//constructor 
ASSET_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: ASSET_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
ASSET_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : ASSET_ASSET(columnCount, mocd, persObj) {}


// Asset Detail Report Flag 
double asset_asset_asset_detail_rpt_flag(int t);

// Asset Detail Report Investment Strategy Flag 
double asset_asset_asset_detail_rpt_inv_strat_flag(int t);

// Calendar Month 
double asset_asset_cal_mth(int t);

// Calendar Year 
double asset_asset_cal_yr(int t);

// Calendar Year Relative 
double asset_asset_cal_yr_relative(int t);

// Date 
double asset_asset_date(int t);

// Finalize 
double asset_asset_finalize(int t);

// Initialize 
double asset_asset_initialize(int t);

// Months to Asset Sale 
double asset_asset_mths_to_asset_sale(int t);

// Months to Next Market Value Calculation 
double asset_asset_mths_to_next_mkt_val_calc(int t);

// Months to SEC Yield Calculation 
double asset_asset_mths_to_sec_yld_calc(int t);

// Startup 
virtual double virtual_startup(int t);

// Final Period 
int  asset_asset_final_period();

// Projection Date Adjusted 
xstring  asset_asset_proj_date_adj();

// Projection Start Date 
int  asset_asset_proj_start_date();

// Projection Start Mth 
int  asset_asset_proj_start_mth();

// Projection Start Yr 
int  asset_asset_proj_start_yr();

// Scenario Day 
int  asset_asset_scen_day();

// Start Period 
int  asset_asset_start_period();


};
#endif
