
//MODELCLASS BEGIN
//MODELCLASS adco_asset
//MODELCLASS ann_pba_pba
//MODELCLASS asset_asset
//MODELCLASS automation
//MODELCLASS a_subport_asset
//MODELCLASS bond_aig
//MODELCLASS bond_asset
//MODELCLASS bond_cf_asset
//MODELCLASS bond_portfolio_aig
//MODELCLASS comp_comp
//MODELCLASS eio_asset
//MODELCLASS epa_asset
//MODELCLASS epl_liab
//MODELCLASS fiaafund_liab
//MODELCLASS fiacarvm_liab
//MODELCLASS fia_liab
//MODELCLASS hdg_grp_comp
//MODELCLASS intex_asset
//MODELCLASS invstrat_asset
//MODELCLASS liab_liab
//MODELCLASS mtg_asset
//MODELCLASS mtg_cf_asset
//MODELCLASS rates_economy
//MODELCLASS seg_comp
//MODELCLASS sfas133_gaap
//MODELCLASS sfas97rd_gaap
//MODELCLASS util_rafm
//MODELCLASS END

#if defined(MICROSOFT)
#define access _access
#define mkdir _mkdir
#include <io.h>
#include <direct.h>
#endif


#include <math.h>
#include "xstring.h"
#include "Locator.h"
#include "circtabl.h"
#include "message.h"
#include "MULTIDIST.h"
#include "mystring.H"
#include "parmfile.h"
#include "xstring.h"
#include "svector.h"
#include "hvector.h"
#include "collectn.h"
#include "newcashflow.h"
#include "monivalu.h"
#include "monitabl.h"
#include "ratetbl.h"
#include "fmlstack.h"
#include "useful.h"
#include "RafmSchedule.h"
#include "DBTable.h"
#include "VariantTable.h"
#include "hashobject.h"
#include "memcount.h"
#include "mvisitor.h"
#include "infdbf.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "msxmldom.h"
#ifdef USEMEMCOUNT
#include "memcount.h"
extern MemCount gMem;
#endif

#define ifkey(x)  if (strcmp(key.c_str(), (x))==0)
extern MY_DLL Parmfile *p;
#include "column2.h"
#include "ModelClass\a_subport_asset_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\bond_aig.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\bond_portfolio_aig.h"
#include "ModelClass\comp_comp.h"
#include "ModelClass\eio_asset.h"
#include "ModelClass\epa_asset.h"
#include "ModelClass\epl_liab.h"
#include "ModelClass\fiaafund_liab.h"
#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fia_liab.h"
#include "ModelClass\hdg_grp_comp.h"
#include "ModelClass\intex_asset.h"
#include "ModelClass\invstrat_asset.h"
#include "ModelClass\liab_liab.h"
#include "ModelClass\mtg_asset.h"
#include "ModelClass\mtg_cf_asset.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"
#include "ModelClass\sfas133_gaap.h"
#include "ModelClass\sfas97rd_gaap.h"
#include "ModelClass\util_rafm.h"
#pragma optimize( "gs", on )

#include "generatedCppHeader.h"

#line 1 "All Model Classes.extern"
#ifndef __UTILITIES_H_
#define __UTILITIES_H_
//Redundant includes only for snip test:
//iomanip included for "setprecision()"
#include <iomanip>
#include <strstream> //WTW - Gen2
typedef vector<vector<string>> sowfinput;
typedef vector<string> sowfcols;
typedef map <xstring, long, less <xstring> > sowfmap;
typedef sowfmap::iterator sowfmapiter;
typedef ofstream sowfoutput;
typedef ofstream sowmpoutput;
typedef vector<vector<string>> deptaskinput;
typedef vector<string> deptaskcols;
typedef map <xstring, long, less <xstring> > deptaskmap;
typedef deptaskmap::iterator deptaskmapiter;
//extern MY_DLL strstream log_screen; //WTW - Gen2 - MY_DLL is not supported
const int EFFECTIVE_RATE = 0;
const int EFFECTIVE_ANNUAL = 1;
const int NOMINAL_SEMIANNUAL = 2;
const int NOMINAL_QUARTERLY = 4;
const int NOMINAL_MONTHLY = 12;
const int ACTUAL_SEMIANNUAL = -2;
const int ACTUAL_QUARTERLY = -4;
const int ACTUAL_MONTHLY = -12;
const double SHORT_TERM_RATE_TERM =  1.0 / 12.0;
const int MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS = 2700;
const int MAXIMUM_NUMBER_OF_MONTHS = 32400;
const int MAXIMUM_SCENARIO_HEADER_RECORD_LENGTH = 4000;
const int MAXIMUM_NUMBER_OF_SPLINE_COLUMNS = 10;
const double LEAST_ANNUAL_GROWTH_RATE = -0.9999;
const double LEAST_BOND_EQUIVALENT_RATE = 0.0001;
const double SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION = 0.0001;
const double ONE_MILLION = 1000000.0;
//WTW - Gen2 - Move Extern definitions to rates header
//const double MINIMUM_MONTHLY_YIELD_RATIO = -0.9; // annual yield = (1.0-0.9)^12 = 1.0e-12
//const double MAXIMUM_MONTHLY_YIELD_RATIO	 = 999999999.0; // annual yield = (1.0+999999999.0)^12 = 1.0e+120
const int DECIMALS_TO_ROUND = 6;
const int ROUND_NEGATIVE_TOZERO = 0;
const int ROUND_NEAR = 1;
const double USLIB_MIN_DOUBLE = -999999999999999.0;
const double USLIB_MAX_DOUBLE =  999999999999999.0;
const double USLIB_MINIMUM_YIELD = -0.9999;
const double USLIB_MINIMUM_YIELD_RATIO = -0.99;
const int SUM_OVER_ALL = -99;
const int SUM_OVER_POSITIVE = -100;
const int SUM_OVER_NEGATIVE = -101;
const int TIER = -98;
const int ANY_GROUP = -99;
const bool DO_NOT_ISSUE_WARNINGS = false;
//WTW - Gen2 - Move Extern definitions to rates header
//const int CALL_CODE = 1; 
//const int PUT_CODE = 2; 
//const int CONTINUOUS_PAYOUT_CODE = 3;
//const int FUTURES_CODE = 4;
// Model point type
const int NEW_PURCH = 0;
const int INIT_MP = 1;
const int PRIOR_PURCH = 2;
const int PROXY_BOND = 3;
// Sum over segment commands
const int CORPORATE_SEGMENT = 0;
const int BUSINESS_SEGMENTS = 1;
// Sum over asset commands
const int BEFORE_BOM_PURCH = 0;
const int BEFORE_SALE = 1;
const int BEFORE_PM_SALE = 2;
const int BEFORE_NCF_SALE = 3;
const int BEFORE_EOM_PURCH = 4;
const int END_OF_PERIOD = 5;
// asset items
const int SEC_MINIMUM_NET_YIELD_MONTH = 5;
const int ALL_EXCEPT_INDEX_ASSET = -2;
const int ANY_ASSET_TYPE         = -1;
const int BOND_CODE              =  0;
const int MORTGAGE_CODE          =  1;
const int SEC_CODE               =  2;
const int REAL_ESTATE_CODE       =  3;
const int EQUITY_CODE            =  4;
const int IRD_CODE               =  5;
const int INDEX_OPTION_CODE      =  7;
const int EPA_CODE	             =  8;
const int MAXIMUM_NUMBER_OF_ASSET_TYPES = 9;
const int MAXIMUM_NUMBER_OF_SALES_CLASSES = 4;
const double ASSET_ACTIVE_THRESHOLD = 0.001;
const int SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS = 10;
const double SOLVE_FOR_SPREAD_TOLERANCE = 0.25;
const double SOLVE_FOR_SPREAD_TOLERANCE_MULTIPLE_FOR_AMORTIZATION_WARNINGS = 4;
const double SOLVE_FOR_SPREAD_HIGHEST_SPREAD = 4.6332495807107996982298654733414;
const double SOLVE_FOR_SPREAD_LOWEST_SPREAD = -1.3675444679663241336002212911135;
const double GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE = 9999999999.0;
const int INVESTMENT_FUND_INDEX = 0;
const int HEDGING_FUND_INDEX = 1;
const int MAXIMUM_NUMBER_OF_ASSET_FUNDS = 2;
const int MP_ACTIVE_CODE = 1;
const int MP_INACTIVE_CODE = 2;
const int MP_NEXT_CODE = 3;
const int MP_RESET_CODE = 4;
const int MP_EOM_ADJUSTMENTS_CODE = 5;
// Pregen hedge arrays
const int HEDGE_CASH_FLOW = 0;
const int HEDGE_MKT_VAL = 1;
const int HEDGE_ARRAY_SIZE = 2;
// global calculation flags
//extern bool pricing_flag;//WTW - Gen2 - Move Extern definitions to rates header
extern bool factors_flag;
extern bool nb_flag;
extern bool alm_flag;
extern bool tcm_flag;
extern bool vm21_reinv_rate_flag;
extern bool avr_flag;
extern bool imr_flag;
extern bool gaap_flag;
extern bool tgt_cap_flag;
extern bool stoch_flag;
extern bool valn_flag;
extern bool time_step_flag;
extern bool sfas133_valn_flag;
extern bool sop031_valn_flag;
extern bool sfas97rd_valn_flag;
extern bool sfas97lp_valn_flag;
extern bool sfas97lp_gpr_valn_flag;
extern bool sfas91_valn_flag;
extern bool sfas60_valn_flag;
extern bool sfas60_gpr_valn_flag;
extern bool sfas120_nlp_valn_flag;
extern bool sfas120_valn_flag;
extern bool sfas120_gpr_valn_flag;
extern bool loc_gpr_valn_flag;
extern bool pba_valn_flag;
extern bool pba_scen_amt_valn_flag;
extern bool rbc_scen_amt_valn_flag;
extern bool res_scen_amt_valn_flag;
extern bool res_det_res_valn_flag;
extern bool res_ag38_8d_valn_flag;
extern bool std_scen_valn_flag;
extern bool rbc_std_scen_valn_flag;
extern bool rbc_std_scen_step2_valn_flag;
extern bool res_std_scen_valn_flag;
extern bool res_stat_tax_valn_flag;
extern bool hedge_valn_flag;
extern bool hedge_valn_shock_flag;
extern bool hedge_valn_final_flag;
extern bool hedge_proj_stmt_flag;
extern bool investing_flag;
extern bool investing_bom_flag;
extern bool intex_proj_flag;
extern bool proxy_bond_gen_flag;
extern bool running_parallel_flag;
// global comparison values
extern int last_proj_period;
extern int valn_period;
extern int investment_period;
extern bool model_point_fatal_error_issued;
extern double aggregate_amount_threshold;
extern double model_point_amount_threshold;
extern double rate_ratio_threshold;
extern vector<string> valn_periods;
// utility functions - elaborated in rates/economy externs
//WTW - Gen2 - Move Extern definitions to rates header
/*extern double round_result(int rounding, int negative, double x, int n);
extern double factorial(int n);
extern int n_choose_k(int n, int k);
extern xstring check_date_format(const xstring &date);
extern int get_mth_from_date(const xstring &date);
extern int get_yr_from_date(const xstring &date);
extern int get_day_from_date(const xstring &date);
extern int month_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported MonthFromDayNumber() function
extern int year_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported YearFromDayNumber() function
extern int day_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported DayFromDayNumber() function
extern int month_number_from_date(int year, int month); //WTW - Gen2 - add new formula to replace unsupported MonthNumberFromDate() function
extern int day_number_from_date(int nYear, int nMonth, int nDay); //WTW - Gen2 - add new formula to replace unsupported DayNumberFromDate() function
extern int get_end_of_mth_day(int yr, int mth);
extern xstring add_mths_to_date(const xstring &date, int mths);
extern int get_mth_from_adj_date(const xstring &date, int mths);
extern double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern long int determine_tbl_size(int sNumberOfDims, ...);
extern xstring get_file_name(const xstring &source_file);
extern xstring get_file_path(const xstring &source_file);
extern xstring get_base_group_name(const xstring &tag, bool seriatim_flag = false);
extern xstring get_string_of_date(double date);
extern xstring get_string_of_enum_val(StrEnum::EnumValue type);
extern int date_diff(xstring first_date, xstring second_date);
extern int number_of_decimals(double xxx, int digits);//WTW - Gen2 - replace preprocessor #define with formula
extern xstring write_string(double value, int string_length, int significant_digits);
extern xstring write_array_to_string(SmartArray <double> value_array, int low, int high);
extern void read_from_string(xstring temp_string, SmartArray <double> &temp_array);
extern void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters);
extern void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters, const string& dash);
//extern void split_string_usl_comma_dash(const string& str, vector<string>& tokens, const string& delimiters, const string& dash);
extern void query_run_time(const xstring &caller, const xstring &file_name);
// financial functions
extern double annual_yld(double monthly_numerator, double monthly_denominator, int return_frequency);
extern double vtothen(double rate_per_period, int num_periods);
extern double a_angle_n(double rate_per_period, int num_periods);
extern void cte_calc(SmartArray <SmartArray <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio);
extern double bs_highest_gain_freq_mult(double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val(double strike_price, double yrs_to_expiry, double underlying_price, double vol, double risk_free_rate, double payout_rate, int call_or_put, int formula_code);
extern double bs_opt_val_asian(int call_or_put, double current_price, double observed_average_price, double strike_price, double length_of_averaging_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_levy_asian(double strike_price, double yrs_to_expiry, double underlying_price, double average_price, double vol, double risk_free_rate, double payout_rate);
extern double bs_opt_val_continuous_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_mthly_sum_cap(int crediting_mths, int known_index_vals, double sum_capped_amts,  double mthly_cap_rate, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double cumul_bivariate_normal_distribn(double x, double y, double rho);
extern double cumul_normal_distribn(double x);*/

// RAFM SQLite
#ifndef _RAFMSQLITE_H_
#define _RAFMSQLITE_H_

#include <string>
#include <vector>

using namespace std;

// 20210614 STW: upgrade to RAFM 2.9
/*
extern void openDatabase(string dbPath);
extern void closeDatabase();
extern string readCsvFile(string csvPath);
extern void executeQuery(string sql, vector<string>& columns, vector<vector<string>>& results);
*/
#endif
#endif
extern int trace_wanted;


extern MY_DLL double msPhase2Tolerance;
extern MY_DLL int last_model_period;
extern MY_DLL Message_handler *eh;

extern MY_DLL long scenario_number;
extern MY_DLL long layer;
extern MY_DLL2 int write_submodels;
extern MY_DLL int check_rebasing;
extern MY_DLL bool stripWanted;
extern MY_DLL2 bool iterationLoopRun;
extern const int& first_proj_task_loop;
extern const int& last_proj_task_loop;
extern const int& proj_task_loop_num;
extern const int& num_of_proj_task_loops;

extern MY_DLL2 int use_overlay_code;
extern MY_DLL int trace_level_wanted;
extern MY_DLL int trace_level;
extern MY_DLL bool bEmitTurboDebugger;
extern MY_DLL Parmfile *  p;

 // Tables...
#ifndef a_subport_asset_TableDefs
#define a_subport_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection A_SUBPORT_ASSET::TTHC;
void A_SUBPORT_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - accr_div
// Accrued Dividend                                                                                             
// Column:ACCR_DIV
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_div",t);
}



//^^^

#line 1 "accr_div.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_div", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_inc", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Default                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_aft_dflt(int t) {
//^^^



//^^^

#line 1 "accr_int_aft_dflt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_int_aft_dflt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - accr_int_dflt
// Accrued Interest Default                                                                                             
// Column:ACCR_INT_DFLT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_dflt(int t) {
//^^^



//^^^

#line 1 "accr_int_dflt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return dflt_amt(t)
	   - cost_basis_dflt(t);

}


//@@ END

//@@ START - accr_int_rent
// Accrued Interest Rent                                                                                             
// Column:ACCR_INT_RENT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_rent(int t) {
//^^^



//^^^

#line 1 "accr_int_rent.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_int_rent", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);


}


//@@ END

//@@ START - accr_int_rent_inv
// Accrued Interest Rent Investment Assets                                                                                             
// Column:ACCR_INT_RENT_INV
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_rent_inv(int t) {
//^^^



//^^^

#line 1 "accr_int_rent_inv.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_int_rent", t, current_sub_port, asset_source_type, INVESTMENT_FUND_INDEX, END_OF_PERIOD);


}


//@@ END

//@@ START - asset_yld
// Asset Yield                                                                                             
// Column:ASSET_YLD
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"asset_yld",t);
}



//^^^

#line 1 "asset_yld.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

if ((fabs(asset_yld_numer(t)
		  + asset_yld_denom(t)) < aggregate_amount_threshold) 
	|| (fabs(asset_yld_denom(t)) < aggregate_amount_threshold))
	return 0.0;

double calculated_yield_local
= annual_yld(asset_yld_numer(t),
			asset_yld_denom(t),
			EFFECTIVE_ANNUAL);

return min(max(calculated_yield_local, USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);

}


//@@ END

//@@ START - asset_yld_denom
// Asset Yield Denominator                                                                                             
// Column:ASSET_YLD_DENOM
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld_denom(int t) {
//^^^



//^^^

#line 1 "asset_yld_denom.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("yld_denom", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - asset_yld_numer
// Asset Yield Numerator                                                                                             
// Column:ASSET_YLD_NUMER
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld_numer(int t) {
//^^^



//^^^

#line 1 "asset_yld_numer.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("yld_numer", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE)
       - inv_exp(t);

}


//@@ END

//@@ START - base_cost_basis
// Base Cost Basis                                                                                             
// Column:BASE_COST_BASIS
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_base_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"base_cost_basis",t);
}



//^^^

#line 1 "base_cost_basis.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("base_cost_basis", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - bk_val
// Book Value                                                                                             
// Column:BK_VAL
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val(int t) {
//^^^



//^^^

#line 1 "bk_val.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

// force call to net realized capital gains after all sales and reporting
realzd_cap_gain_net(t);
cap_gain(t);
accr_inc(t);
unrealzd_cap_gain_released_on_sale(t);
sale_inc(t);

return sum_over_assets_subport("bk_val", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - bk_val_incr
// Book Value Increase                                                                                             
// Column:BK_VAL_INCR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_incr(int t) {
//^^^



//^^^

#line 1 "bk_val_incr.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return bk_val(t)
	   - bk_val(t - 1);

}


//@@ END

//@@ START - bk_val_inv
// Book Value Investment Assets                                                                                             
// Column:BK_VAL_INV
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_inv(int t) {
//^^^



//^^^

#line 1 "bk_val_inv.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("bk_val", t, current_sub_port, asset_source_type, INVESTMENT_FUND_INDEX, END_OF_PERIOD);

}


//@@ END

//@@ START - bk_val_plus_accr_int
// Book Value Plus Accrued Interest                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_plus_accr_int(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

return bk_val(t)
	   + accr_int_rent(t);

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cal_mth(int t) {
//^^^



//^^^

#line 1 "cal_mth.A_SUBPORT_ASSET.for"
return seg->cal_mth(t);

}


//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cal_yr(int t) {
//^^^



//^^^

#line 1 "cal_yr.A_SUBPORT_ASSET.for"
return seg->cal_yr(t);

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cal_yr_relative(int t) {
//^^^



//^^^

#line 1 "cal_yr_relative.A_SUBPORT_ASSET.for"
return seg->cal_yr_relative(t);

}


//@@ END

//@@ START - cap_gain
// Capital Gains                                                                                             
// Column:CAP_GAIN
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain(int t) {
//^^^



//^^^

#line 1 "cap_gain.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return cap_gain_bef_sale(t) + cap_gain_from_sale(t);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "cap_gain_bef_sale.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return realzd_cap_gain(t)	
	   + unrealzd_cap_gain_incr(t);

}


//@@ END

//@@ START - cap_gain_from_sale
// Capital Gains From Sales                                                                                             
// Column:CAP_GAIN_FROM_SALE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain_from_sale(int t) {
//^^^



//^^^

#line 1 "cap_gain_from_sale.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cap_gain_from_sale", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cash_flow
// Cash Flow                                                                                             
// Column:CASH_FLOW
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cash_flow(int t) {
//^^^



//^^^

#line 1 "cash_flow.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cash_flow", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis
// Cost Basis                                                                                             
// Column:COST_BASIS
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis(int t) {
//^^^



//^^^

#line 1 "cost_basis.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

cost_basis_transfer(t);
cost_basis_transaction(t);
cost_basis_incr_appreciation(t);

return sum_over_assets_subport("cost_basis", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - cost_basis_accrual
// Cost Basis Accrual                                                                                             
// Column:COST_BASIS_ACCRUAL
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_accrual(int t) {
//^^^



//^^^

#line 1 "cost_basis_accrual.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cost_basis_accrual", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_dflt
// Cost Basis Default                                                                                             
// Column:COST_BASIS_DFLT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_dflt(int t) {
//^^^



//^^^

#line 1 "cost_basis_dflt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cost_basis_dflt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_growth
// Cost Basis Growth                                                                                             
// Column:COST_BASIS_GROWTH
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_growth(int t) {
//^^^



//^^^

#line 1 "cost_basis_growth.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return cost_basis_accrual(t)
	   + mkt_val_cost_basis_incr(t)
	   - depreciation(t)
	   + cost_basis_incr_index_asset_turnover(t);

}


//@@ END

//@@ START - cost_basis_incr_accr_div
// Cost Basis Increase Accrued Dividend                                                                                             
// Column:COST_BASIS_INCR_ACCR_DIV
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_accr_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"cost_basis_incr_accr_div",t);
}



//^^^

#line 1 "cost_basis_incr_accr_div.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cost_basis_incr_accr_div", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_incr_appreciation
// Cost Basis Increase from Appreciation                                                                                             
// Column:COST_BASIS_INCR_APPRECIATION
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_appreciation(int t) {
//^^^



//^^^

#line 1 "cost_basis_incr_appreciation.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cost_basis_incr_appreciation", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_incr_index_asset_turnover
// Cost Basis Increase Index Asset Turnover                                                                                             
// Column:COST_BASIS_INCR_INDEX_ASSET_TURNOVER
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_index_asset_turnover(int t) {
//^^^



//^^^

#line 1 "cost_basis_incr_index_asset_turnover.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("realzd_cap_gain_turnover", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_opt_pmt
// Cost Basis Option Payment                                                                                             
// Column:COST_BASIS_OPT_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_opt_pmt(int t) {
//^^^



//^^^

#line 1 "cost_basis_opt_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("opt_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE)
	   - sum_over_assets_subport("realzd_cap_gain_opt_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_purch
// Cost Basis Purchase                                                                                             
// Column:COST_BASIS_PURCH
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_purch(int t) {
//^^^



//^^^

#line 1 "cost_basis_purch.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);
int current_asset_source = getElementNumber();
int mp = 0;
double total = 0.0;
mpmap::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
BOND_ASSET *current_bond_element;
if (seg->bond_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->bond_mp_map_active.begin();
		 mp_map_iter != seg->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_bond_element = asset->sm_bond[mp];

		if (current_asset_source == 1)
			continue;

		if (current_bond_element->existing_asset_indicator
			|| current_bond_element->purch_asset_sub_port != current_sub_port
			|| current_bond_element->commencement_period < t)
			continue;

		total += current_bond_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
MTG_ASSET *current_mtg_element;
if (seg->mtg_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->mtg_mp_map_active.begin();
		 mp_map_iter != seg->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_mtg_element = asset->sm_mtg[mp];

		if (current_asset_source == 1)
			continue;

		if (current_mtg_element->existing_asset_indicator
			|| current_mtg_element->purch_asset_sub_port != current_sub_port
			|| current_mtg_element->commencement_period < t)
			continue;

		total += current_mtg_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
SEC_ASSET *current_sec_element;
if (seg->sec_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->sec_mp_map_active.begin();
		 mp_map_iter != seg->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_sec_element = asset->sm_sec[mp];

		if (current_asset_source == 1)
			continue;

		if (current_sec_element->existing_asset_indicator
			|| current_sec_element->purch_asset_sub_port != current_sub_port
			|| current_sec_element->commencement_period < t)
			continue;

		total += current_sec_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
IRD_ASSET *current_ird_element;
if (seg->ird_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->ird_mp_map_active.begin();
		 mp_map_iter != seg->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_ird_element = asset->sm_ird[mp];

		if (current_asset_source == 1)
			continue;

		if (current_ird_element->existing_asset_indicator
			|| current_ird_element->purch_asset_sub_port != current_sub_port
			|| current_ird_element->commencement_period < t)
			continue;

		total += current_ird_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__RE_ASSET_H_)
RE_ASSET *current_re_element;
if (seg->re_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->re_mp_map_active.begin();
		 mp_map_iter != seg->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_re_element = asset->sm_re[mp];

		if (current_asset_source == 1)
			continue;

		if (current_re_element->existing_asset_indicator
			|| current_re_element->purch_asset_sub_port != current_sub_port
			|| current_re_element->commencement_period < t)
			continue;

		total += current_re_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
EQT_ASSET *current_eqt_element;
if (seg->eqt_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->eqt_mp_map_active.begin();
		 mp_map_iter != seg->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_eqt_element = asset->sm_eqt[mp];

		if (current_asset_source == 1)
			continue;

		if (current_eqt_element->existing_asset_indicator
			|| current_eqt_element->purch_asset_sub_port != current_sub_port
			|| current_eqt_element->commencement_period < t)
			continue;

		total += current_eqt_element->cost_basis_purch(t);
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
EIO_ASSET *current_eio_element;
if (seg->eio_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->eio_mp_map_active.begin();
		 mp_map_iter != seg->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_eio_element = asset->sm_eio[mp];

		if (current_asset_source == 1)
			continue;

		if (current_eio_element->existing_asset_indicator
			|| current_eio_element->purch_asset_sub_port != current_sub_port
			|| current_eio_element->commencement_period + current_eio_element->purchased_bom_flag < t)
			continue;

		total += current_eio_element->cost_basis_purch(t);
		}
	}
#endif

return total;

}


//@@ END

//@@ START - cost_basis_sale
// Cost Basis Sale                                                                                             
// Column:COST_BASIS_SALE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_sale.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("cost_basis_sold", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - cost_basis_sched_prin_pmt
// Cost Basis Scheduled Principal Payment                                                                                             
// Column:COST_BASIS_SCHED_PRIN_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_sched_prin_pmt(int t) {
//^^^



//^^^

#line 1 "cost_basis_sched_prin_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("sched_prin_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - cost_basis_transaction
// Cost Basis Transaction                                                                                             
// Column:COST_BASIS_TRANSACTION
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_transaction(int t) {
//^^^



//^^^

#line 1 "cost_basis_transaction.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return cost_basis_purch(t)
	   - cost_basis_sched_prin_pmt(t)
	   - cost_basis_opt_pmt(t)
	   - cost_basis_sale(t)
	   - cost_basis_dflt(t)
	   + cost_basis_transfer(t);

}


//@@ END

//@@ START - cost_basis_transfer
// Cost Basis Transfer                                                                                             
// Column:COST_BASIS_TRANSFER
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_transfer(int t) {
//^^^



//^^^

#line 1 "cost_basis_transfer.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);
int current_asset_source = getElementNumber();
double result = 0.0;
int mp;
double total = 0.0;
mpmap::iterator mp_map_iter;
	
#if defined(__BOND_ASSET_H_)
BOND_ASSET *current_bond_element;
if (seg->bond_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->bond_mp_map_active.begin();
		 mp_map_iter != seg->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_bond_element = asset->sm_bond[mp];

		if (current_asset_source == 2
			&& (current_bond_element->existing_asset_indicator == INIT_MP 
			 ||current_bond_element->existing_asset_indicator == PROXY_BOND))
			continue;

		if (current_asset_source == 1
			&& (current_bond_element->existing_asset_indicator == NEW_PURCH
			    || current_bond_element->existing_asset_indicator == PRIOR_PURCH))
			continue;
					
		if ((current_bond_element->commencement_period < t
			 && current_bond_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_bond_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_bond_element->commencement_period)
			{
			if (current_sub_port == current_bond_element->purch_asset_sub_port
				&& current_sub_port != current_bond_element->sub_port_id(t))
				total -= current_bond_element->cost_basis_purch(t);

			else if (current_sub_port != current_bond_element->purch_asset_sub_port
					 && current_sub_port == current_bond_element->sub_port_id(t))
				total += current_bond_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_bond_element->sub_port_id(t - 1)
				&& current_sub_port != current_bond_element->sub_port_id(t))
				total -= current_bond_element->cost_basis(t);

			else if (current_sub_port != current_bond_element->sub_port_id(t - 1)
					 && current_sub_port == current_bond_element->sub_port_id(t))
				total += current_bond_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
MTG_ASSET *current_mtg_element;
if (seg->mtg_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->mtg_mp_map_active.begin();
		 mp_map_iter != seg->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_mtg_element = asset->sm_mtg[mp];

		if (current_asset_source == 2
			&& current_mtg_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_mtg_element->existing_asset_indicator == NEW_PURCH
			    || current_mtg_element->existing_asset_indicator == PRIOR_PURCH))
			continue;

		if ((current_mtg_element->commencement_period < t
			 && current_mtg_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_mtg_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_mtg_element->commencement_period)
			{
			if (current_sub_port == current_mtg_element->purch_asset_sub_port
				&& current_sub_port != current_mtg_element->sub_port_id(t))
				total -= current_mtg_element->cost_basis_purch(t);

			else if (current_sub_port != current_mtg_element->purch_asset_sub_port
					 && current_sub_port == current_mtg_element->sub_port_id(t))
				total += current_mtg_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_mtg_element->sub_port_id(t - 1)
				&& current_sub_port != current_mtg_element->sub_port_id(t))
				total -= current_mtg_element->cost_basis(t);

			else if (current_sub_port != current_mtg_element->sub_port_id(t - 1)
					 && current_sub_port == current_mtg_element->sub_port_id(t))
				total += current_mtg_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
SEC_ASSET *current_sec_element;
if (seg->sec_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->sec_mp_map_active.begin();
		 mp_map_iter != seg->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_sec_element = asset->sm_sec[mp];

		if (current_asset_source == 2
			&& current_sec_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_sec_element->existing_asset_indicator == NEW_PURCH
			    || current_sec_element->existing_asset_indicator == PRIOR_PURCH))
			continue;

		if ((current_sec_element->commencement_period < t
			 && current_sec_element->notional_amt(t - 1) < model_point_amount_threshold)
			|| current_sec_element->notional_amt_bef_sale(t) < model_point_amount_threshold)
			continue;

		if (current_sec_element->commencement_period)
			{
			if (current_sub_port == current_sec_element->purch_asset_sub_port
				&& current_sub_port != current_sec_element->sub_port_id(t))
				total -= current_sec_element->cost_basis_purch(t);

			else if (current_sub_port != current_sec_element->purch_asset_sub_port
					 && current_sub_port == current_sec_element->sub_port_id(t))
				total += current_sec_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_sec_element->sub_port_id(t - 1)
				&& current_sub_port != current_sec_element->sub_port_id(t))
				total -= current_sec_element->cost_basis(t);

			else if (current_sub_port != current_sec_element->sub_port_id(t - 1)
					 && current_sub_port == current_sec_element->sub_port_id(t))
				total += current_sec_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
IRD_ASSET *current_ird_element;
if (seg->ird_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->ird_mp_map_active.begin();
		 mp_map_iter != seg->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_ird_element = asset->sm_ird[mp];

		if (current_asset_source == 2
			&& current_ird_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_ird_element->existing_asset_indicator == NEW_PURCH
			    || current_ird_element->existing_asset_indicator == PRIOR_PURCH))
			continue;
		
		if ((current_ird_element->commencement_period < t
			&& current_ird_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_ird_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_ird_element->commencement_period)
			{
			if (current_sub_port == current_ird_element->purch_asset_sub_port
				&& current_sub_port != current_ird_element->sub_port_id(t))
				total -= current_ird_element->cost_basis_purch(t);

			else if (current_sub_port != current_ird_element->purch_asset_sub_port
					 && current_sub_port == current_ird_element->sub_port_id(t))
				total += current_ird_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_ird_element->sub_port_id(t - 1)
				&& current_sub_port != current_ird_element->sub_port_id(t))
				total -= current_ird_element->cost_basis(t);

			else if (current_sub_port != current_ird_element->sub_port_id(t - 1)
					 && current_sub_port == current_ird_element->sub_port_id(t))
				total += current_ird_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__RE_ASSET_H_)
RE_ASSET *current_re_element;
// (no transfers for real estate)
if (seg->re_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->re_mp_map_active.begin();
		 mp_map_iter != seg->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_re_element = asset->sm_re[mp];

		if (current_asset_source == 2
			&& current_re_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_re_element->existing_asset_indicator == NEW_PURCH
			    || current_re_element->existing_asset_indicator == PRIOR_PURCH))
			continue;

		if ((current_re_element->commencement_period < t
			&& current_re_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_re_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_re_element->commencement_period)
			{
			if (current_sub_port == current_re_element->purch_asset_sub_port
				&& current_sub_port != current_re_element->sub_port_id(t))
				total -= current_re_element->cost_basis_purch(t);

			else if (current_sub_port != current_re_element->purch_asset_sub_port
					 && current_sub_port == current_re_element->sub_port_id(t))
				total += current_re_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_re_element->sub_port_id(t - 1)
				&& current_sub_port != current_re_element->sub_port_id(t))
				total -= current_re_element->cost_basis(t);

			else if (current_sub_port != current_re_element->sub_port_id(t - 1)
					 && current_sub_port == current_re_element->sub_port_id(t))
				total += current_re_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
EQT_ASSET *current_eqt_element;
// (no transfers for equities)
if (seg->eqt_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->eqt_mp_map_active.begin();
		 mp_map_iter != seg->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_eqt_element = asset->sm_eqt[mp];

		if (current_asset_source == 2
			&& current_eqt_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_eqt_element->existing_asset_indicator == NEW_PURCH
			    || current_eqt_element->existing_asset_indicator == PRIOR_PURCH))
			continue;

		if ((current_eqt_element->commencement_period < t
			&& current_eqt_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_eqt_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_eqt_element->commencement_period)
			{
			if (current_sub_port == current_eqt_element->purch_asset_sub_port
				&& current_sub_port != current_eqt_element->sub_port_id(t))
				total -= current_eqt_element->cost_basis_purch(t);

			else if (current_sub_port != current_eqt_element->purch_asset_sub_port
					 && current_sub_port == current_eqt_element->sub_port_id(t))
				total += current_eqt_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_eqt_element->sub_port_id(t - 1)
				&& current_sub_port != current_eqt_element->sub_port_id(t))
				total -= current_eqt_element->cost_basis(t);

			else if (current_sub_port != current_eqt_element->sub_port_id(t - 1)
					 && current_sub_port == current_eqt_element->sub_port_id(t))
				total += current_eqt_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
EIO_ASSET *current_eio_element;
if (seg->eio_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->eio_mp_map_active.begin();
		 mp_map_iter != seg->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_eio_element = asset->sm_eio[mp];

		if (current_asset_source == 2
			&& current_eio_element->existing_asset_indicator == INIT_MP)
			continue;

		if (current_asset_source == 1
			&& (current_eio_element->existing_asset_indicator == NEW_PURCH
			    || current_eio_element->existing_asset_indicator == PRIOR_PURCH))
			continue;
					
		if ((current_eio_element->commencement_period < t
			&& current_eio_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_eio_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_eio_element->commencement_period)
			{
			if (current_sub_port == current_eio_element->purch_asset_sub_port
				&& current_sub_port != current_eio_element->sub_port_id(t))
				total -= current_eio_element->cost_basis_purch(t);

			else if (current_sub_port != current_eio_element->purch_asset_sub_port
					 && current_sub_port == current_eio_element->sub_port_id(t))
				total += current_eio_element->cost_basis_purch(t);
			}
		else
			{
			if (current_sub_port == current_eio_element->sub_port_id(t - 1)
				&& current_sub_port != current_eio_element->sub_port_id(t))
				total -= current_eio_element->cost_basis(t);

			else if (current_sub_port != current_eio_element->sub_port_id(t - 1)
					 && current_sub_port == current_eio_element->sub_port_id(t))
				total += current_eio_element->cost_basis(t);
			}
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
EPA_ASSET *current_epa_element;
if (seg->epa_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->epa_mp_map_active.begin();
		 mp_map_iter != seg->epa_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_epa_element = asset->sm_epa[mp];

		if (current_asset_source == 2)
			continue;

		if ((current_epa_element->commencement_period < t
			&& current_epa_element->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| current_epa_element->notional_amt_bef_sale(t) < ASSET_ACTIVE_THRESHOLD)
			continue;

		if (current_sub_port == current_epa_element->sub_port_id(t - 1)
			&& current_sub_port != current_epa_element->sub_port_id(t))
			total -= current_epa_element->cost_basis(t);

		else if (current_sub_port != current_epa_element->sub_port_id(t - 1)
				 && current_sub_port == current_epa_element->sub_port_id(t))
			total += current_epa_element->cost_basis(t);
		}
	}
#endif

return total;

}


//@@ END

//@@ START - depreciation
// Depreciation                                                                                             
// Column:DEPRECIATION
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_depreciation(int t) {
//^^^



//^^^

#line 1 "depreciation.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("depreciation", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - dflt_amt
// Default Amount                                                                                             
// Column:DFLT_AMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_dflt_amt(int t) {
//^^^



//^^^

#line 1 "dflt_amt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("dflt_amt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - eff_dur
// Effective Duration                                                                                             
// Column:EFF_DUR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_eff_dur(int t) {
//^^^



//^^^

#line 1 "eff_dur.A_SUBPORT_ASSET.for"
if (t < 0
	//20220613 STW: add a condition for model efficiency improvement
	|| fast_stat_calc_aig == YES)
	return NO_AVG;

if ((mkt_val_times_eff_dur(t) + mkt_val_for_eff_dur(t))== 0
	|| mkt_val_for_eff_dur(t) == 0)
	return NO_AVG;

return mkt_val_times_eff_dur(t)
	   / mkt_val_for_eff_dur(t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.A_SUBPORT_ASSET.for"
xstring sub_port_group = seg_id + "|" + asset_type + "|" + asset_source_type + "|" + sub_port_id;

this->setGroup(sub_port_group);

return 1.0;

}


//@@ END

//@@ START - int_div_and_rent
// Interest Dividend and Rent                                                                                             
// Column:INT_DIV_AND_RENT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_int_div_and_rent(int t) {
//^^^



//^^^

#line 1 "int_div_and_rent.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("int_div_and_rent", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - int_net
// Interest Net                                                                                             
// Column:INT_NET
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_int_net(int t) {
//^^^



//^^^

#line 1 "int_net.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

//force a call to default of accrued interest
accr_int_dflt(t);

return int_div_and_rent(t)
	   - inv_exp(t);

}


//@@ END

//@@ START - inv_exp
// Investment Expenses                                                                                             
// Column:INV_EXP
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp(int t) {
//^^^



//^^^

#line 1 "inv_exp.A_SUBPORT_ASSET.for"
if (t <= 0 )
	return NO_AVG;

return (bk_val_plus_accr_int(t - 1))
	   * inv_exp_pct
	   * (1.0 / 12.0);

}


//@@ END

//@@ START - inv_exp_inv
// Investment Expenses Investment Assets                                                                                             
// Column:INV_EXP_INV
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp_inv(int t) {
//^^^



//^^^

#line 1 "inv_exp_inv.A_SUBPORT_ASSET.for"
if (t <= 0 )
	return NO_AVG;

return (bk_val_inv(t - 1)
		+ accr_int_rent_inv(t - 1))
	   * inv_exp_pct
	   * (1.0 / 12.0);

}


//@@ END

//@@ START - inv_exp_tax_exempt
// Investment Expenses Tax Exempt Assets                                                                                             
// Column:INV_EXP_TAX_EXEMPT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp_tax_exempt(int t) {
//^^^



//^^^

#line 1 "inv_exp_tax_exempt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

// force calls to ensure order of calculations
bk_val_plus_accr_int(t - 1);

int sub_port_t = max(t - 1, 0);
int sub_port_id = getElementNumber(1);
int exist_asset_status = asset_source_type;
int asset_fund_index = SUM_OVER_ALL;

double bk_val = 0.0;
double accr_int = 0.0;
double inv_exp_tax_exempt = 0.0;

#if defined(__BOND_ASSET_H_)
int mp = 0;
BOND_ASSET *bond_element = NULL;
mpmap::iterator mp_map_iter;

if (seg->bond_mp_map_active.size() > 0)
	{
	for (mp_map_iter = seg->bond_mp_map_active.begin();
		 mp_map_iter != seg->bond_mp_map_active.end();
	 	 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		bond_element = company->sm_asset->sm_bond[mp];

		if ((t == bond_element->commencement_period && sub_port_t < t)
			|| (t > max(0,bond_element->commencement_period)
				&& fabs(bond_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
			continue;

		if (fabs(bond_element->tax_exempt_pct) < rate_ratio_threshold)
			continue; 

		if ((sub_port_id == SUM_OVER_ALL
				|| sub_port_id == xint(bond_element->sub_port_id(sub_port_t)))
			&& (asset_fund_index == SUM_OVER_ALL
				|| asset_fund_index == bond_element->asset_fund_index)
			&& (exist_asset_status == TOTAL
			|| (exist_asset_status == EXISTING 
				&& (bond_element->existing_asset_indicator == INIT_MP 
					|| bond_element->existing_asset_indicator == PROXY_BOND)) 
			|| (exist_asset_status == PURCH 
			    && (bond_element->existing_asset_indicator == NEW_PURCH
				    || bond_element->existing_asset_indicator == PRIOR_PURCH))))
			{
			bk_val = bond_element->bk_val(t - 1);
			accr_int = bond_element->accr_int(t - 1); 	

			inv_exp_tax_exempt 
			+= (bk_val + accr_int)
				* bond_element->tax_exempt_pct
				* inv_exp_pct / 12.0;
			}
		}			         
	}
#endif

return inv_exp_tax_exempt;

}


//@@ END

//@@ START - mkt_val
// Market Value                                                                                             
// Column:MKT_VAL
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val(int t) {
//^^^



//^^^

#line 1 "mkt_val.A_SUBPORT_ASSET.for"
if (t > 0 && asset->mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("mkt_val", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - mkt_val_cost_basis_incr
// Market Value Cost Basis Increase                                                                                             
// Column:MKT_VAL_COST_BASIS_INCR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_cost_basis_incr(int t) {
//^^^



//^^^

#line 1 "mkt_val_cost_basis_incr.A_SUBPORT_ASSET.for"
return cost_basis_incr_appreciation(t)
	   + cost_basis_incr_accr_div(t);

}


//@@ END

//@@ START - mkt_val_for_eff_dur
// Market Value for Effective Duration                                                                                             
// Column:MKT_VAL_FOR_EFF_DUR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_for_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"mkt_val_for_eff_dur",t);
}



//^^^

#line 1 "mkt_val_for_eff_dur.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t > 0 && asset->mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("mkt_val_for_eff_dur", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - mkt_val_times_eff_dur
// Market Value Times Effective Duration                                                                                             
// Column:MKT_VAL_TIMES_EFF_DUR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_times_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"mkt_val_times_eff_dur",t);
}



//^^^

#line 1 "mkt_val_times_eff_dur.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t > 0 && asset->mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("mkt_val_times_eff_dur", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_notional_amt(int t) {
//^^^



//^^^

#line 1 "notional_amt.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("notional_amt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - opt_inc
// Option Income                                                                                             
// Column:OPT_INC
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_opt_inc(int t) {
//^^^



//^^^

#line 1 "opt_inc.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("opt_inc", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_opt_pmt(int t) {
//^^^



//^^^

#line 1 "opt_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);
 
return sum_over_assets_subport("opt_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - realzd_cap_gain
// Realized Capital Gain                                                                                             
// Column:REALZD_CAP_GAIN
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("realzd_cap_gain", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - realzd_cap_gain_net
// Realized Capital Gain Net                                                                                             
// Column:REALZD_CAP_GAIN_NET
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_net(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_net.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return realzd_cap_gain_prin_pmt(t)
	   + realzd_cap_gain_opt_pmt(t)
	   + realzd_cap_gain_turnover(t)
	   + realzd_cap_gain_sale(t)
	   - dflt_amt(t);

}


//@@ END

//@@ START - realzd_cap_gain_opt_pmt
// Realized Capital Gain from Option Payment                                                                                             
// Column:REALZD_CAP_GAIN_OPT_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_opt_pmt(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_opt_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("realzd_cap_gain_opt_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - realzd_cap_gain_prin_pmt
// Realized Capital Gain from Principal Payment                                                                                             
// Column:REALZD_CAP_GAIN_PRIN_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_prin_pmt(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_prin_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return sched_prin_pmt(t)
	   - cost_basis_sched_prin_pmt(t);

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gain from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_sale(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_sale.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("realzd_cap_gain_sale", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_EOM_PURCH);

}


//@@ END

//@@ START - realzd_cap_gain_turnover
// Realized Capital Gain from Turnover                                                                                             
// Column:REALZD_CAP_GAIN_TURNOVER
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_turnover(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_turnover.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("realzd_cap_gain_turnover", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - sale_inc
// Sale Income                                                                                             
// Column:SALE_INC
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_sale_inc(int t) {
//^^^



//^^^

#line 1 "sale_inc.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("accr_int_sold", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_EOM_PURCH)
	   + sum_over_assets_subport("accr_rent_sold", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_EOM_PURCH);

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_sched_prin_pmt(int t) {
//^^^



//^^^

#line 1 "sched_prin_pmt.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("sched_prin_pmt", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double A_SUBPORT_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.A_SUBPORT_ASSET.for"
#if 0 // START_CLASS
typedef map <int, long, less <int> > mpmap;
xstring asset_sub_port_description;
double min_size_existing;
double min_size_purchase;
int sale_priority;
double rebal_tolerance_pct;
double rebal_annual_turnover_pct_max;
double rebal_annual_turnover_pct_min;
double inv_exp_pct;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
min_size_existing = 0.0;
min_size_purchase = 0.0;
sale_priority = 0;
rebal_tolerance_pct = 0.0;
rebal_annual_turnover_pct_max = 0.0;
rebal_annual_turnover_pct_min = 0.0;
inv_exp_pct = 0.0;
#endif // END_CONSTRUCTOR

int asset_source_dimension = getElementNumber();

if (asset_source_dimension == 0)
	asset_source_type = TOTAL; 
else if (asset_source_dimension == 1)
	asset_source_type = EXISTING;
else
	asset_source_type = PURCH;

return 1.0;

}


//@@ END

//@@ START - unrealzd_cap_gain
// Unrealized Capital Gain                                                                                             
// Column:UNREALZD_CAP_GAIN
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("unrealzd_cap_gain", t, current_sub_port, asset_source_type, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - unrealzd_cap_gain_hidden
// Unrealized Capital Gain Hidden                                                                                             
// Column:UNREALZD_CAP_GAIN_HIDDEN
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_hidden(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_hidden.A_SUBPORT_ASSET.for"
if (t < 0)
	return NO_AVG;

if (asset->mths_to_next_mkt_val_calc(t) != 0 && t != 0)
	return NO_AVG;

return mkt_val(t)
	   - bk_val(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_incr(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_incr.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("unrealzd_cap_gain_incr", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released from Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_released_on_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.A_SUBPORT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int current_sub_port = getElementNumber(1);

return sum_over_assets_subport("unrealzd_cap_gain_released_on_sale", t, current_sub_port, asset_source_type, SUM_OVER_ALL, BEFORE_EOM_PURCH);

}


//@@ END


#line 1 "remove_chars_from_string.A_SUBPORT_ASSET.for"                                                                                   
xstring A_SUBPORT_ASSET::remove_chars_from_string(const xstring asset_sub_port_desc, const xstring chars_to_remove )
{
// colons are special characters in a sub portfolio field
xstring xxx = asset_sub_port_desc.strip();
xstring beg, end, next_char;
int pos = 0;

for (int ndx = 0; ndx < chars_to_remove.length(); ndx++)
	{
	next_char = chars_to_remove(ndx,1);

	while ((pos = xxx.find(next_char)) > 0)
		{
		beg = xxx(0,pos);
		end = xxx(pos+1);
		xxx = beg + end;
		}
	}

return xxx;
}



#line 1 "sub_port_rpt_requested.A_SUBPORT_ASSET.for"                                                                                   
xstring A_SUBPORT_ASSET::sub_port_rpt_requested()
{
int col_num = 0;
bool has_output = 0;

col_num = Column("accr_int_rent").Number();
has_output = Column(col_num).hasOutput();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cy_act").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("asset_yld").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cy_act").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("bk_val").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cal_yr").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cal_mth").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_growth").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_purch").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("asset_yld_numer").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("asset_yld_denom").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_sale").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_transfer").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_dflt").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("eff_dur").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("unrealzd_cap_gain_hidden").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("inv_exp").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("mkt_val").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("int_net").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("realzd_cap_gain").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("realzd_cap_gain_sale").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_sched_prin_pmt").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("unrealzd_cap_gain").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("cost_basis_incr_appreciation").Number();
if (!Column(col_num).hasOutput())
	return "No";

col_num = Column("int_div_and_rent").Number();
if (!Column(col_num).hasOutput())
	return "No";

return "Yes";
}



#line 1 "sum_over_assets_subport.A_SUBPORT_ASSET.for"                                                                                   
double A_SUBPORT_ASSET::sum_over_assets_subport(const xstring &colname, int t, int sub_port_id, int exist_asset_status, int asset_fund_index, int sum_over_timing)
{

// sub_port_id SUM_OVER_ALL for all; otherwise 0,1,2,3,..
// exist_asset_status: TOTAL
//					   EXISTING 
//					   PURCH
//  SUM_OVER_ALL is set to -99 in External Dlls

double total = 0.0;
double col_val = 0.0;
int sub_port_t = max(t - 1, 0);
int colnum = 0;
int mp = 0;
mpmap::iterator mp_map_iter;

if (sum_over_timing >= BEFORE_BOM_PURCH && t > seg->start_period)
	{
	seg->asset_less_liab_and_surp(t - 1);
	seg->cash(t - 1);
	seg->borrowing(t - 1);
	}

if (sum_over_timing >= BEFORE_SALE && t > seg->start_period)
	{
	seg->hedge_inv_amt_bom(t); // beginning of month investment
	seg->hedge_rila_trading_cost_aig(t); //20240529 MQ add rila trading cost
	}

if (sum_over_timing >= BEFORE_PM_SALE && t > seg->start_period)
	{
	company->sm_inv_strategy[seg->seg_num]->cash_flow_planned_sale(t);
	seg->hedge_sale_amt(t);
	seg->hedge_inv_amt_eom(t);
	seg->hedge_exp(t);
	}	

if (sum_over_timing >= BEFORE_NCF_SALE && t > seg->start_period)
	company->sm_inv_strategy[seg->seg_num]->cash_flow_rebal(t);

if (sum_over_timing >= BEFORE_EOM_PURCH && t > seg->start_period)
	company->sm_inv_strategy[seg->seg_num]->cash_net_neg_cash_flow_sale(t);

if (sum_over_timing >= END_OF_PERIOD)
	{
	sub_port_t = t; // after sub portfolio transfers
	company->sm_inv_strategy[seg->seg_num]->inv_amt(t);
	}

#if defined(__BOND_ASSET_H_)
BOND_ASSET *bond_element = NULL;

if (seg->bond_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_bond[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->bond_mp_map_active.begin();
			 mp_map_iter != seg->bond_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			bond_element = company->sm_asset->sm_bond[mp];

			if ((t == bond_element->commencement_period && sub_port_t < t)
				|| (t > max(0,bond_element->commencement_period)
					&& fabs(bond_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(bond_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == bond_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && (bond_element->existing_asset_indicator == INIT_MP || 
					bond_element->existing_asset_indicator == PROXY_BOND)) 
				|| (exist_asset_status == PURCH && (bond_element->existing_asset_indicator == NEW_PURCH
					|| bond_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = bond_element->Column(colnum).Value(t);
				col_val *= bond_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
MTG_ASSET *mtg_element = NULL;
if (seg->mtg_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_mtg[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->mtg_mp_map_active.begin();
			 mp_map_iter != seg->mtg_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			mtg_element = company->sm_asset->sm_mtg[mp];

			if ((t == mtg_element->commencement_period && sub_port_t < t)
				|| (t > max(0,mtg_element->commencement_period)
					&& fabs(mtg_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(mtg_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == mtg_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && mtg_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (mtg_element->existing_asset_indicator == NEW_PURCH
					|| mtg_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = mtg_element->Column(colnum).Value(t);
				col_val *= mtg_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
SEC_ASSET *sec_element = NULL;
if (seg->sec_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_sec[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->sec_mp_map_active.begin();
			 mp_map_iter != seg->sec_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			sec_element = company->sm_asset->sm_sec[mp];

			if ((t == sec_element->commencement_period && sub_port_t < t)
				|| (t > max(0,sec_element->commencement_period)
					&& fabs(sec_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(sec_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == sec_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && sec_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (sec_element->existing_asset_indicator == NEW_PURCH
					|| sec_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = sec_element->Column(colnum).Value(t);
				col_val *= sec_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
IRD_ASSET *ird_element = NULL;
if (seg->ird_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_ird[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->ird_mp_map_active.begin();
			 mp_map_iter != seg->ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if ((t == ird_element->commencement_period && sub_port_t < t)
				|| (t > max(0,ird_element->commencement_period)
					&& fabs(ird_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(ird_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == ird_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && ird_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (ird_element->existing_asset_indicator == NEW_PURCH
					|| ird_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = ird_element->Column(colnum).Value(t);
				col_val *= ird_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__RE_ASSET_H_)
RE_ASSET *re_element = NULL;
if (seg->re_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_re[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->re_mp_map_active.begin();
			 mp_map_iter != seg->re_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			re_element = company->sm_asset->sm_re[mp];

			if ((t == re_element->commencement_period && sub_port_t < t)
				|| (t > max(0,re_element->commencement_period)
					&& fabs(re_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(re_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == re_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && re_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (re_element->existing_asset_indicator == NEW_PURCH
					|| re_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = re_element->Column(colnum).Value(t);
				col_val *= re_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
EQT_ASSET *eqt_element = NULL;
if (seg->eqt_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_eqt[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->eqt_mp_map_active.begin();
			 mp_map_iter != seg->eqt_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eqt_element = company->sm_asset->sm_eqt[mp];

			if ((t == eqt_element->commencement_period && sub_port_t < t)
				|| (t > max(0,eqt_element->commencement_period)
					&& fabs(eqt_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(eqt_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == eqt_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && eqt_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (eqt_element->existing_asset_indicator == NEW_PURCH
					|| eqt_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = eqt_element->Column(colnum).Value(t);
				col_val *= eqt_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
EIO_ASSET *eio_element = NULL;
if (seg->eio_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_eio[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->eio_mp_map_active.begin();
			 mp_map_iter != seg->eio_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if ((t == eio_element->commencement_period && sub_port_t < t)
				|| (t > max(0,eio_element->commencement_period)
					&& fabs(eio_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(eio_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == eio_element->asset_fund_index)
				&& (exist_asset_status == TOTAL
				|| (exist_asset_status == EXISTING && eio_element->existing_asset_indicator == INIT_MP) 
				|| (exist_asset_status == PURCH && (eio_element->existing_asset_indicator == NEW_PURCH
					|| eio_element->existing_asset_indicator == PRIOR_PURCH))))
				{
				col_val = eio_element->Column(colnum).Value(t);
				col_val *= eio_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
EPA_ASSET *epa_element = NULL;
if (seg->epa_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_epa[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = seg->epa_mp_map_active.begin();
			 mp_map_iter != seg->epa_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			epa_element = company->sm_asset->sm_epa[mp];

			if ((t == epa_element->commencement_period && sub_port_t < t)
				|| (t > max(0,epa_element->commencement_period)
					&& fabs(epa_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if ((sub_port_id == SUM_OVER_ALL
				 || sub_port_id == xint(epa_element->sub_port_id(sub_port_t)))
				&& (asset_fund_index == SUM_OVER_ALL
					|| asset_fund_index == epa_element->asset_fund_index)
				&& ((exist_asset_status == TOTAL)
				|| (exist_asset_status == EXISTING)))
				{
				col_val = epa_element->Column(colnum).Value(t);
				col_val *= epa_element->pct_to_use;

				total += col_val;
				}
			}			         
		}
	}
#endif

/*
#if defined(UNIT_TEST)
if (business_seg_flag)
	total += asset_vals.getvalue(t, colname, 1);
#endif
*/ 
return total;
}



	static A_SUBPORT_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (A_SUBPORT_ASSET_UDF::*dPXi) (int);
typedef double (A_SUBPORT_ASSET_UDF::*dPXid) (int, double);
typedef double (A_SUBPORT_ASSET_UDF::*dPF) ();
typedef double (A_SUBPORT_ASSET_UDF::*dPFd) (double);
typedef int (A_SUBPORT_ASSET_UDF::*iPF) ();
typedef int (A_SUBPORT_ASSET_UDF::*iPFi) (int);
typedef xstring (A_SUBPORT_ASSET_UDF::*sPF) ();
typedef xstring (A_SUBPORT_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData A_SUBPORT_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_div", "a_subport_asset_accr_div",  "accr_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_div, 'E','N', '3', 'C', (size_t)&modelOffset->accr_div),
	CashFlowCommonData(2, "accr_inc", "a_subport_asset_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_inc, 'E','N', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(3, "accr_int_aft_dflt", "a_subport_asset_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_aft_dflt, 'E','Y', '3', 'P', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(4, "accr_int_dflt", "a_subport_asset_accr_int_dflt",  "accr_int_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_dflt, 'E','Y', '3', 'P', (size_t)&modelOffset->accr_int_dflt),
	CashFlowCommonData(5, "accr_int_rent", "a_subport_asset_accr_int_rent",  "accr_int_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_rent, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_rent),
	CashFlowCommonData(6, "accr_int_rent_inv", "a_subport_asset_accr_int_rent_inv",  "accr_int_rent_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_accr_int_rent_inv, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_rent_inv),
	CashFlowCommonData(7, "asset_yld", "a_subport_asset_asset_yld",  "asset_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld),
	CashFlowCommonData(8, "asset_yld_denom", "a_subport_asset_asset_yld_denom",  "asset_yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld_denom, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_denom),
	CashFlowCommonData(9, "asset_yld_numer", "a_subport_asset_asset_yld_numer",  "asset_yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_asset_yld_numer, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_yld_numer),
	CashFlowCommonData(10, "base_cost_basis", "a_subport_asset_base_cost_basis",  "base_cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_base_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->base_cost_basis),
	CashFlowCommonData(11, "bk_val", "a_subport_asset_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(12, "bk_val_incr", "a_subport_asset_bk_val_incr",  "bk_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->bk_val_incr),
	CashFlowCommonData(13, "bk_val_inv", "a_subport_asset_bk_val_inv",  "bk_val_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_inv, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_inv),
	CashFlowCommonData(14, "bk_val_plus_accr_int", "a_subport_asset_bk_val_plus_accr_int",  "bk_val_plus_accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_bk_val_plus_accr_int, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int),
	CashFlowCommonData(15, "cal_mth", "a_subport_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cal_mth, 'E','N', '3', 'P', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(16, "cal_yr", "a_subport_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cal_yr, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(17, "cal_yr_relative", "a_subport_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cal_yr_relative, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(18, "cap_gain", "a_subport_asset_cap_gain",  "cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain),
	CashFlowCommonData(19, "cap_gain_bef_sale", "a_subport_asset_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain_bef_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(20, "cap_gain_from_sale", "a_subport_asset_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cap_gain_from_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(21, "cash_flow", "a_subport_asset_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(22, "cost_basis", "a_subport_asset_cost_basis",  "cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis),
	CashFlowCommonData(23, "cost_basis_accrual", "a_subport_asset_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_accrual, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(24, "cost_basis_dflt", "a_subport_asset_cost_basis_dflt",  "cost_basis_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_dflt, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_dflt),
	CashFlowCommonData(25, "cost_basis_growth", "a_subport_asset_cost_basis_growth",  "cost_basis_growth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_growth, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_growth),
	CashFlowCommonData(26, "cost_basis_incr_accr_div", "a_subport_asset_cost_basis_incr_accr_div",  "cost_basis_incr_accr_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_accr_div, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_incr_accr_div),
	CashFlowCommonData(27, "cost_basis_incr_appreciation", "a_subport_asset_cost_basis_incr_appreciation",  "cost_basis_incr_appreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_appreciation, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_incr_appreciation),
	CashFlowCommonData(28, "cost_basis_incr_index_asset_turnover", "a_subport_asset_cost_basis_incr_index_asset_turnover",  "cost_basis_incr_index_asset_turnover",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_incr_index_asset_turnover, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_incr_index_asset_turnover),
	CashFlowCommonData(29, "cost_basis_opt_pmt", "a_subport_asset_cost_basis_opt_pmt",  "cost_basis_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_opt_pmt),
	CashFlowCommonData(30, "cost_basis_purch", "a_subport_asset_cost_basis_purch",  "cost_basis_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_purch, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_purch),
	CashFlowCommonData(31, "cost_basis_sale", "a_subport_asset_cost_basis_sale",  "cost_basis_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_sale),
	CashFlowCommonData(32, "cost_basis_sched_prin_pmt", "a_subport_asset_cost_basis_sched_prin_pmt",  "cost_basis_sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_sched_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_sched_prin_pmt),
	CashFlowCommonData(33, "cost_basis_transaction", "a_subport_asset_cost_basis_transaction",  "cost_basis_transaction",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_transaction, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_transaction),
	CashFlowCommonData(34, "cost_basis_transfer", "a_subport_asset_cost_basis_transfer",  "cost_basis_transfer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_cost_basis_transfer, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_transfer),
	CashFlowCommonData(35, "depreciation", "a_subport_asset_depreciation",  "depreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_depreciation, 'E','Y', '3', 'P', (size_t)&modelOffset->depreciation),
	CashFlowCommonData(36, "dflt_amt", "a_subport_asset_dflt_amt",  "dflt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_dflt_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->dflt_amt),
	CashFlowCommonData(37, "eff_dur", "a_subport_asset_eff_dur",  "eff_dur",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_eff_dur, 'E','N', '3', 'P', (size_t)&modelOffset->eff_dur),
	CashFlowCommonData(38, "initialize", "a_subport_asset_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(39, "int_div_and_rent", "a_subport_asset_int_div_and_rent",  "int_div_and_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_int_div_and_rent, 'E','Y', '3', 'P', (size_t)&modelOffset->int_div_and_rent),
	CashFlowCommonData(40, "int_net", "a_subport_asset_int_net",  "int_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_int_net, 'E','Y', '3', 'P', (size_t)&modelOffset->int_net),
	CashFlowCommonData(41, "inv_exp", "a_subport_asset_inv_exp",  "inv_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_exp),
	CashFlowCommonData(42, "inv_exp_inv", "a_subport_asset_inv_exp_inv",  "inv_exp_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp_inv, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_exp_inv),
	CashFlowCommonData(43, "inv_exp_tax_exempt", "a_subport_asset_inv_exp_tax_exempt",  "inv_exp_tax_exempt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_inv_exp_tax_exempt, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_exp_tax_exempt),
	CashFlowCommonData(44, "mkt_val", "a_subport_asset_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(45, "mkt_val_cost_basis_incr", "a_subport_asset_mkt_val_cost_basis_incr",  "mkt_val_cost_basis_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_cost_basis_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_cost_basis_incr),
	CashFlowCommonData(46, "mkt_val_for_eff_dur", "a_subport_asset_mkt_val_for_eff_dur",  "mkt_val_for_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_for_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_eff_dur),
	CashFlowCommonData(47, "mkt_val_times_eff_dur", "a_subport_asset_mkt_val_times_eff_dur",  "mkt_val_times_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_mkt_val_times_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_times_eff_dur),
	CashFlowCommonData(48, "notional_amt", "a_subport_asset_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_notional_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(49, "opt_inc", "a_subport_asset_opt_inc",  "opt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_opt_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_inc),
	CashFlowCommonData(50, "opt_pmt", "a_subport_asset_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(51, "realzd_cap_gain", "a_subport_asset_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(52, "realzd_cap_gain_net", "a_subport_asset_realzd_cap_gain_net",  "realzd_cap_gain_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_net, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_net),
	CashFlowCommonData(53, "realzd_cap_gain_opt_pmt", "a_subport_asset_realzd_cap_gain_opt_pmt",  "realzd_cap_gain_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_opt_pmt),
	CashFlowCommonData(54, "realzd_cap_gain_prin_pmt", "a_subport_asset_realzd_cap_gain_prin_pmt",  "realzd_cap_gain_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_prin_pmt),
	CashFlowCommonData(55, "realzd_cap_gain_sale", "a_subport_asset_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(56, "realzd_cap_gain_turnover", "a_subport_asset_realzd_cap_gain_turnover",  "realzd_cap_gain_turnover",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_realzd_cap_gain_turnover, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_turnover),
	CashFlowCommonData(57, "sale_inc", "a_subport_asset_sale_inc",  "sale_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_sale_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->sale_inc),
	CashFlowCommonData(58, "sched_prin_pmt", "a_subport_asset_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_sched_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(59, "startup", "a_subport_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(60, "unrealzd_cap_gain", "a_subport_asset_unrealzd_cap_gain",  "unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain),
	CashFlowCommonData(61, "unrealzd_cap_gain_hidden", "a_subport_asset_unrealzd_cap_gain_hidden",  "unrealzd_cap_gain_hidden",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_hidden, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_hidden),
	CashFlowCommonData(62, "unrealzd_cap_gain_incr", "a_subport_asset_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(63, "unrealzd_cap_gain_released_on_sale", "a_subport_asset_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&A_SUBPORT_ASSET_UDF::a_subport_asset_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale)
};
const CashFlowCommonData* A_SUBPORT_ASSET::mCFStaticData[] = {
	&A_SUBPORT_ASSET::mCFStaticData_0[0],
	&A_SUBPORT_ASSET::mCFStaticData_0[1],
	&A_SUBPORT_ASSET::mCFStaticData_0[2],
	&A_SUBPORT_ASSET::mCFStaticData_0[3],
	&A_SUBPORT_ASSET::mCFStaticData_0[4],
	&A_SUBPORT_ASSET::mCFStaticData_0[5],
	&A_SUBPORT_ASSET::mCFStaticData_0[6],
	&A_SUBPORT_ASSET::mCFStaticData_0[7],
	&A_SUBPORT_ASSET::mCFStaticData_0[8],
	&A_SUBPORT_ASSET::mCFStaticData_0[9],
	&A_SUBPORT_ASSET::mCFStaticData_0[10],
	&A_SUBPORT_ASSET::mCFStaticData_0[11],
	&A_SUBPORT_ASSET::mCFStaticData_0[12],
	&A_SUBPORT_ASSET::mCFStaticData_0[13],
	&A_SUBPORT_ASSET::mCFStaticData_0[14],
	&A_SUBPORT_ASSET::mCFStaticData_0[15],
	&A_SUBPORT_ASSET::mCFStaticData_0[16],
	&A_SUBPORT_ASSET::mCFStaticData_0[17],
	&A_SUBPORT_ASSET::mCFStaticData_0[18],
	&A_SUBPORT_ASSET::mCFStaticData_0[19],
	&A_SUBPORT_ASSET::mCFStaticData_0[20],
	&A_SUBPORT_ASSET::mCFStaticData_0[21],
	&A_SUBPORT_ASSET::mCFStaticData_0[22],
	&A_SUBPORT_ASSET::mCFStaticData_0[23],
	&A_SUBPORT_ASSET::mCFStaticData_0[24],
	&A_SUBPORT_ASSET::mCFStaticData_0[25],
	&A_SUBPORT_ASSET::mCFStaticData_0[26],
	&A_SUBPORT_ASSET::mCFStaticData_0[27],
	&A_SUBPORT_ASSET::mCFStaticData_0[28],
	&A_SUBPORT_ASSET::mCFStaticData_0[29],
	&A_SUBPORT_ASSET::mCFStaticData_0[30],
	&A_SUBPORT_ASSET::mCFStaticData_0[31],
	&A_SUBPORT_ASSET::mCFStaticData_0[32],
	&A_SUBPORT_ASSET::mCFStaticData_0[33],
	&A_SUBPORT_ASSET::mCFStaticData_0[34],
	&A_SUBPORT_ASSET::mCFStaticData_0[35],
	&A_SUBPORT_ASSET::mCFStaticData_0[36],
	&A_SUBPORT_ASSET::mCFStaticData_0[37],
	&A_SUBPORT_ASSET::mCFStaticData_0[38],
	&A_SUBPORT_ASSET::mCFStaticData_0[39],
	&A_SUBPORT_ASSET::mCFStaticData_0[40],
	&A_SUBPORT_ASSET::mCFStaticData_0[41],
	&A_SUBPORT_ASSET::mCFStaticData_0[42],
	&A_SUBPORT_ASSET::mCFStaticData_0[43],
	&A_SUBPORT_ASSET::mCFStaticData_0[44],
	&A_SUBPORT_ASSET::mCFStaticData_0[45],
	&A_SUBPORT_ASSET::mCFStaticData_0[46],
	&A_SUBPORT_ASSET::mCFStaticData_0[47],
	&A_SUBPORT_ASSET::mCFStaticData_0[48],
	&A_SUBPORT_ASSET::mCFStaticData_0[49],
	&A_SUBPORT_ASSET::mCFStaticData_0[50],
	&A_SUBPORT_ASSET::mCFStaticData_0[51],
	&A_SUBPORT_ASSET::mCFStaticData_0[52],
	&A_SUBPORT_ASSET::mCFStaticData_0[53],
	&A_SUBPORT_ASSET::mCFStaticData_0[54],
	&A_SUBPORT_ASSET::mCFStaticData_0[55],
	&A_SUBPORT_ASSET::mCFStaticData_0[56],
	&A_SUBPORT_ASSET::mCFStaticData_0[57],
	&A_SUBPORT_ASSET::mCFStaticData_0[58],
	&A_SUBPORT_ASSET::mCFStaticData_0[59],
	&A_SUBPORT_ASSET::mCFStaticData_0[60],
	&A_SUBPORT_ASSET::mCFStaticData_0[61],
	&A_SUBPORT_ASSET::mCFStaticData_0[62],
	&A_SUBPORT_ASSET::mCFStaticData_0[63],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for asset_source_type                                                                                       
	const ChoicePair asset_source_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TOTAL, "Total")
		,ChoicePair(StrEnum::EXISTING, "Existing")
		,ChoicePair(StrEnum::PURCH, "Purch")
	};
	const EnumList asset_source_typeEnumList(3, asset_source_typeChoicePairs);

	// EnumList for asset_type                                                                                       
	const ChoicePair asset_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BOND, "Bond")
		,ChoicePair(StrEnum::MORTGAGE, "Mortgage")
		,ChoicePair(StrEnum::SECURITIZED_ASSET, "Securitized Asset")
		,ChoicePair(StrEnum::INTEREST_RATE_DERIVATIVE, "Interest Rate Derivative")
		,ChoicePair(StrEnum::EQUITY, "Equity")
		,ChoicePair(StrEnum::REAL_ESTATE, "Real Estate")
		,ChoicePair(StrEnum::INDEX_OPTION, "Index Option")
	};
	const EnumList asset_typeEnumList(7, asset_typeChoicePairs);

	// EnumList for dur_match_defn                                                                                       
	const ChoicePair dur_match_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList dur_match_defnEnumList(2, dur_match_defnChoicePairs);

	// EnumList for fast_stat_calc_aig                                                                                       
	const ChoicePair fast_stat_calc_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList fast_stat_calc_aigEnumList(2, fast_stat_calc_aigChoicePairs);

	// EnumList for port_defn                                                                                       
	const ChoicePair port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList port_defnEnumList(2, port_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace A_SUBPORT_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(A_SUBPORT_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(A_SUBPORT_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace A_SUBPORT_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void A_SUBPORT_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> A_SUBPORT_ASSET::mgr_;

	Attribute::Descriptor A_SUBPORT_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"asset_source_type", -1, (size_t)&modelOffset->asset_source_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_source_typeEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"asset_type", -1, (size_t)&modelOffset->asset_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_typeEnumList, Feature(true)),
	Descriptor(2, Attribute::STR_ENUM,	"dur_match_defn", -1, (size_t)&modelOffset->dur_match_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &dur_match_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::STR_ENUM,	"fast_stat_calc_aig", -1, (size_t)&modelOffset->fast_stat_calc_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fast_stat_calc_aigEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"inv_tgt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_tgt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"inv_tgt_pct_curr_strat", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_tgt_pct_curr_strat,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"inv_tgt_pct_dur_match", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_tgt_pct_dur_match,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STR_ENUM,	"port_defn", -1, (size_t)&modelOffset->port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &port_defnEnumList, Feature(true)),
	Descriptor(8, Attribute::DOUBLE,	"purch_asset_weight_sum", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"purch_asset_weight_sum_curr_strat", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum_curr_strat,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"purch_asset_weight_sum_dur_match", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum_dur_match,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"purch_asset_weight_sum_normalzd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum_normalzd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"purch_asset_weight_sum_normalzd_curr_strat", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum_normalzd_curr_strat,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"purch_asset_weight_sum_normalzd_dur_match", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight_sum_normalzd_dur_match,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STRING,	"sub_port_id", -1, (size_t)&modelOffset->sub_port_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::INT,	"sub_port_updated_flag", -1, (size_t)&modelOffset->sub_port_updated_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::INT,	"sub_ports_to_initialize_for_sale", -1, (size_t)&modelOffset->sub_ports_to_initialize_for_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::INT,	"sub_ports_to_sell", -1, (size_t)&modelOffset->sub_ports_to_sell,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"total_weights_fund_match", Descriptor::NOT_INDEXED, (size_t)&modelOffset->total_weights_fund_match,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	};

	Attribute::Descriptor* A_SUBPORT_ASSET::descriptorTable[] = {
	&A_SUBPORT_ASSET::descriptor_0[0],
	&A_SUBPORT_ASSET::descriptor_0[1],
	&A_SUBPORT_ASSET::descriptor_0[2],
	&A_SUBPORT_ASSET::descriptor_0[3],
	&A_SUBPORT_ASSET::descriptor_0[4],
	&A_SUBPORT_ASSET::descriptor_0[5],
	&A_SUBPORT_ASSET::descriptor_0[6],
	&A_SUBPORT_ASSET::descriptor_0[7],
	&A_SUBPORT_ASSET::descriptor_0[8],
	&A_SUBPORT_ASSET::descriptor_0[9],
	&A_SUBPORT_ASSET::descriptor_0[10],
	&A_SUBPORT_ASSET::descriptor_0[11],
	&A_SUBPORT_ASSET::descriptor_0[12],
	&A_SUBPORT_ASSET::descriptor_0[13],
	&A_SUBPORT_ASSET::descriptor_0[14],
	&A_SUBPORT_ASSET::descriptor_0[15],
	&A_SUBPORT_ASSET::descriptor_0[16],
	&A_SUBPORT_ASSET::descriptor_0[17],
	&A_SUBPORT_ASSET::descriptor_0[18],
	&A_SUBPORT_ASSET::descriptor_0[19],
	&A_SUBPORT_ASSET::descriptor_0[20],
	nullptr};
	const size_t A_SUBPORT_ASSET::sDescriptorCount = 21;

//factory
A_SUBPORT_ASSET* A_SUBPORT_ASSET::makeThis(int isSubmodel, ModelClass* owner, A_SUBPORT_ASSET* peer, 
						int mainRebase, const xstring &name, A_SUBPORT_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("A_SUBPORT_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor A_SUBPORT_ASSET");
#endif
	A_SUBPORT_ASSET* newP = (A_SUBPORT_ASSET*)new A_SUBPORT_ASSET_UDF
   	  ("a_subport_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

	if (!CP) // first time around, CP wil be zero, store top_model pointer
   	CP = newP;
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray
	if (arrayTemplate) {
   	newP->meta = arrayTemplate->meta;
		newP->ms_Total((ModelClass*)arrayTemplate); // share total with persistent object
		newP->groupExpr = arrayTemplate->groupExpr;
	}
	else 
		newP->ms_Total(new TotalObject); // make a new total

		setVisitorPointersAndMap(name, newP, 'N');

	// create submodels of this model here

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
A_SUBPORT_ASSET_persistent_object* A_SUBPORT_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, A_SUBPORT_ASSET* peer, 
							int mainRebase, const xstring &name, A_SUBPORT_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("A_SUBPORT_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor A_SUBPORT_ASSET_persistent_object");
#endif
	A_SUBPORT_ASSET_persistent_object* newP = (A_SUBPORT_ASSET_persistent_object*)new A_SUBPORT_ASSET_persistent_object
   	  ("a_subport_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			A_SUBPORT_ASSET_persistent_object* pd = dynamic_cast<A_SUBPORT_ASSET_persistent_object*>(product);
			if (pd)
			{
				newP->SearchFields = product->SearchFields;
			}
		}
	}

	if (arrayTemplate) {
   	newP->meta = arrayTemplate->meta;
		newP->ms_Total((ModelClass*)arrayTemplate); // share total with persistent object
		newP->groupExpr = arrayTemplate->groupExpr;
	}
	else 
		newP->ms_Total(new TotalObject); // make a new total

	if (!fixedArray)
		setVisitorPointersAndMap(name, newP, 'N');

	// create submodels of this model here
	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (A_SUBPORT_ASSET_UDF::*dPF) ();
typedef double (A_SUBPORT_ASSET_UDF::*dPFd) (double);
typedef int (A_SUBPORT_ASSET_UDF::*iPF) ();
typedef int (A_SUBPORT_ASSET_UDF::*iPFi) (int);
typedef xstring (A_SUBPORT_ASSET_UDF::*sPF) ();
typedef xstring (A_SUBPORT_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
A_SUBPORT_ASSET::A_SUBPORT_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, epl(company_liab_epl)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (A_SUBPORT_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
A_SUBPORT_ASSET::A_SUBPORT_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(63, A_SUBPORT_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, epl(company_liab_epl)
	, rates(company_rates)
	, seg(company_seg)
 // Tables...
 // Generic Tables ...
{

#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	if (bEmitTurboDebugger)
	{
		bEmitTurboDebugger = false;
	}

	normalModel=true;
   mCFCD = mCFStaticData;
   static std::unordered_multimap<std::string, int> CFStaticDataFinder = createCashFlowFinder(mCFStaticData);
   mCFCDFinder = &CFStaticDataFinder;
   mMOCD = descriptorTable;


		ModelClassName = modelClassName;
       isSubmodel = isSm;
       isMainModel = !isSm;
		modelName = name;

#ifdef __CREATE_COMP_COMP_CLASS_
       company = 0;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
       company_asset = 0;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif

#ifdef VOCAL1
	log_strm << "Constructing model called " << name << "\n";
	log_strm << "    this = " << this << "\n";
	log_strm << "     " << this << "::modelClass = " << ModelClassName << "\n";
	log_strm << "     " << this << "::isSubmodel = " << isSubmodel << "\n";
	log_strm << "     " << this << "::isMainModel = " << isMainModel << "\n";
	log_strm << "     " << this << "::rebase_period = " << rebase_period << "\n";
#endif

   	pddfVector = &ddfVector;
	isDataVariable_ = &dataVariables;
	pHasBeenWritten = &hasBeenWritten;

	setSlidingSpace();

	for (int cf_no = 1; cf_no <= 63; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (A_SUBPORT_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

	sm_calling_model = owner;  // owner = 0 for main model
	sm_peer_model = peer;  // peer = 0 for rebase main model and its submodels
	isMainRebase = mainRebase;
	isRebaseClone = ! mainRebase;
	isForceRestoreModel = 1;
	main_rebase_model = (isMainRebase && rebasing_wanted);

#ifdef VOCAL1
	log_strm << "     " << this << "::sm_calling_model = " << sm_calling_model << "\n";
	log_strm << "     " << this << "::sm_peer_model = " << sm_peer_model << "\n";
	log_strm << "     " << this << "::isMainRebase = " << isMainRebase << "\n";
	log_strm << "     " << this << "::isRebaseClone = " << isRebaseClone << "\n";
	log_strm << "     " << this << "::isForceRestoreModel = " << isForceRestoreModel << "\n";
	log_strm << "     " << this << "::main_rebase_model = " << main_rebase_model << "\n";
#endif


	if (isMainRebase)
		CPPeer = this;
	else
		CPPeer = sm_peer_model;


}
//Constructor End@2


 void A_SUBPORT_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
 }
//copy_names END@2


 void A_SUBPORT_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int A_SUBPORT_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& A_SUBPORT_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double A_SUBPORT_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
		ModelClass::verifyColumnNumber(columnNumber, t);
		Functor3<double, const int, const int> pFunctor(this, (Functor3<double, const int, const int>::pTNodeFunc)&ModelClass::ms_columnValue, columnNumber, t);
		NavigatorDouble navList(&pFunctor, 0, t);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	int A_SUBPORT_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double A_SUBPORT_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
	int columnNumber = ModelClass::verifyColumnName(columnName, t);
		Functor3<double, const int, const int> pFunctor(this, (Functor3<double, const int, const int>::pTNodeFunc)&ModelClass::ms_columnValue, columnNumber, t);
		NavigatorDouble navList(&pFunctor, 0, t);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	double A_SUBPORT_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
		// The name of the functor does seem to be inappropiate - has nothing to do with Col
		Functor2<double, const Attribute::Descriptor&>
			pFunctor(this, (Functor2<double, const Descriptor&>::pTNodeFunc)&ModelClass::ms_valueAsDouble, descriptor);
		NavigatorDouble navList(&pFunctor, 0, 0);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	void A_SUBPORT_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void A_SUBPORT_ASSET_persistent_object::write(long include_submodels) {
		// check if there are any aggregate processes in the write() statement
		if (callbackList->contains(::_Default) || callbackList->contains(::SUM))
			arrayWriteError();

		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::write , include_submodels);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void A_SUBPORT_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void A_SUBPORT_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void A_SUBPORT_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
		// check if there are any aggregate processes in the write() statement
		if (callbackList->contains(::_Default) || callbackList->contains(::SUM))
			arrayWriteError();

		VoidFunctor2<const xstring&, long> pFunctor(this, (VoidFunctor2<const xstring&, long>::pTNodeFunc)&ModelClass::write , key, include_submodels);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}




	A_SUBPORT_ASSET_persistent_object::~A_SUBPORT_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool A_SUBPORT_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void A_SUBPORT_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void A_SUBPORT_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void A_SUBPORT_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void A_SUBPORT_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void A_SUBPORT_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* A_SUBPORT_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* A_SUBPORT_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* A_SUBPORT_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char A_SUBPORT_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void A_SUBPORT_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
A_SUBPORT_ASSET_persistent_object::A_SUBPORT_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			A_SUBPORT_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(A_SUBPORT_ASSET::sm_bond_is)
	, sm_bond_pv(A_SUBPORT_ASSET::sm_bond_pv)
	, sm_bond_ym(A_SUBPORT_ASSET::sm_bond_ym)
	, sm_mtg_is(A_SUBPORT_ASSET::sm_mtg_is)
	, sm_mtg_pv(A_SUBPORT_ASSET::sm_mtg_pv)
	, sm_mtg_ym(A_SUBPORT_ASSET::sm_mtg_ym)

	{


	normalModel = false;
   mModelType = ARRAY_FIXED; 

	sm_calling_model = owner;  // owner = 0 for main model
	sm_peer_model = peer;  // peer = 0 for rebase main model and its submodels
	isMainRebase = mainRebase;
	isRebaseClone = ! mainRebase;
	isForceRestoreModel = 1;
	main_rebase_model = (isMainRebase && rebasing_wanted);

	shrink();
}


//destructor
A_SUBPORT_ASSET::~A_SUBPORT_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void A_SUBPORT_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void A_SUBPORT_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void A_SUBPORT_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void A_SUBPORT_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void A_SUBPORT_ASSET::start_of_projection() {
}
//start_of_projection END@2

void A_SUBPORT_ASSET::end_of_projection() {
}
//end_of_projection END@2

void A_SUBPORT_ASSET::start_of_layer() {
}


void A_SUBPORT_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void A_SUBPORT_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void A_SUBPORT_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void A_SUBPORT_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> A_SUBPORT_ASSET::ddfVector;
BitArray A_SUBPORT_ASSET::dataVariables(21);
bool A_SUBPORT_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool A_SUBPORT_ASSET::writeClassInfo = true;

void A_SUBPORT_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, A_SUBPORT_ASSET::descriptor_0>::dT = A_SUBPORT_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, A_SUBPORT_ASSET::descriptor_0>::dT = A_SUBPORT_ASSET::descriptor_0;

