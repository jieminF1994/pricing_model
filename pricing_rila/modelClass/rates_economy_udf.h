
#ifndef __RATES_ECONOMY_UDF_H_
#define __RATES_ECONOMY_UDF_H_

#include "ModelClass\rates_economy.h"

class RATES_ECONOMY_UDF : public RATES_ECONOMY {

	friend class RATES_ECONOMY;

//constructor 
RATES_ECONOMY_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: RATES_ECONOMY(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
RATES_ECONOMY_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : RATES_ECONOMY(columnCount, mocd, persObj) {}


// Calendar Month 
double rates_economy_cal_mth(int t);

// Calendar Year 
double rates_economy_cal_yr(int t);

// Calendar Year Relative 
double rates_economy_cal_yr_relative(int t);

// Date 
double rates_economy_date(int t);

// US Equity Market Value Growth 
double rates_economy_equity_market_value_growth_us(int t);

// US Equity Scenario Total Return 
double rates_economy_equity_scenario_total_return_us(int t);

// Exact Date 
double rates_economy_exact_date(int t);

// Finalize 
double rates_economy_finalize(int t);

// Generate Scenarios 
double rates_economy_generate(int t);

// Generate deterministic scenario 
double rates_economy_generate_deterministic_scen(int t);

// Inflation Rate Annual 
double rates_economy_infl_rate_annual(int t);

// Initialize 
double rates_economy_initialize(int t);

// Startup 
virtual double virtual_startup(int t);

// Maximum 10-year treasury rate to date: 
double rates_economy_ten_year_treasury_annualized_return_cumul_max_aig(int t);

// Ten year treasury return monthly maximum: 
double rates_economy_ten_year_treasury_annualized_return_max_aig(int t);

// Average 10-year treasury rate over 3 months: 
double rates_economy_ten_year_treasury_annualized_return_three_mth_avg_aig(int t);

// Yield Rate 10 Year 
double rates_economy_yield_rate_10_year(int t);

// Yield Rate 90 Day 
double rates_economy_yield_rate_90_day(int t);

// Generated Scenarios File Path 
xstring  rates_economy_gen_scen_file_path();

// Projection Date Adjusted 
xstring  rates_economy_proj_date_adj();

// Projection Date Offset 
int  rates_economy_proj_date_offset();

// Projection Start Date 
int  rates_economy_proj_start_date();

// Projection Start Mth 
int  rates_economy_proj_start_mth();

// Projection Start Yr 
int  rates_economy_proj_start_yr();


};
#endif
