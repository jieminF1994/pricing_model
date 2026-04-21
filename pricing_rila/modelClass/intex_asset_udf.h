
#ifndef __INTEX_ASSET_UDF_H_
#define __INTEX_ASSET_UDF_H_

#include "ModelClass\intex_asset.h"

class INTEX_ASSET_UDF : public INTEX_ASSET {

	friend class INTEX_ASSET;

//constructor 
INTEX_ASSET_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: INTEX_ASSET(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
INTEX_ASSET_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : INTEX_ASSET(columnCount, mocd, persObj) {}


// Active Tranche Flag 
double intex_asset_active_tranche_flag(int t);

// Calendar Month 
double intex_asset_cal_mth(int t);

// Calendar Year 
double intex_asset_cal_yr(int t);

// Calendar Year Relative 
double intex_asset_cal_yr_relative(int t);

// Date 
double intex_asset_date(int t);

// Finalize 
double intex_asset_finalize(int t);

// Get Collateral Prepayment 
double intex_asset_get_collateral_prepmt(int t);

// Get Tranche Accrued Interest 
double intex_asset_get_tranche_accr_int(int t);

// Get Tranche Accrued Interest Before Prepayments 
double intex_asset_get_tranche_accr_int_bef_prepmt(int t);

// Get Tranche Bal 
double intex_asset_get_tranche_bal(int t);

// Get Tranche Cash Flow 
double intex_asset_get_tranche_cash_flow(int t);

// Get Tranche Interest Payment 
double intex_asset_get_tranche_int_pmt(int t);

// Get Tranche Months to Reset 
double intex_asset_get_tranche_mths_to_reset(int t);

// Get Tranche Principal Payment 
double intex_asset_get_tranche_prin_pmt(int t);

// Initialize 
double intex_asset_initialize(int t);

// Startup 
virtual double virtual_startup(int t);

// Detail Report Flag 
int  intex_asset_asset_detail_rpt_flag();

// Commencement Period 
int  intex_asset_commencement_period();

// Final Period 
int  intex_asset_final_period();

// Get Collateral Number of Pools 
int  intex_asset_get_collateral_num_of_pools();

// Get Tranche Cdu Months Offset 
int  intex_asset_get_tranche_cdu_mths_offset();

// Get Tranche Days Accrued 
int  intex_asset_get_tranche_days_accr();

// Get Tranche Frequency 
int  intex_asset_get_tranche_freqs();

// Get Tranche Maturity Day 
int  intex_asset_get_tranche_maturity_day();

// Get Tranche Maturity Period 
int  intex_asset_get_tranche_maturity_period();

// Output File 
xstring  intex_asset_output_file();

// Output Path 
xstring  intex_asset_output_path();

// Projection Date Adjusted 
xstring  intex_asset_proj_date_adj();

// Projection Start Mth 
int  intex_asset_proj_start_mth();

// Projection Start Yr 
int  intex_asset_proj_start_yr();

// Start Period 
int  intex_asset_start_period();

// Tranche Rate Definition 
int  intex_asset_tranche_rate_defn();

// Use End of Month Scenario Rates? 
int  intex_asset_use_eom_scen_rates();


};
#endif
