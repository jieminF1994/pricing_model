
//MODELCLASS BEGIN
//MODELCLASS adco_asset
//MODELCLASS ann_pba_pba
//MODELCLASS asset_asset
//MODELCLASS automation
//MODELCLASS a_subport_asset
//MODELCLASS bond_asset
//MODELCLASS bond_cf_asset
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
#include "ModelClass\rates_economy_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
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
#line 1 "Rates Only.extern"
// global calculation flags
//bool pricing_flag = false;//WTW - Gen2 - Move Extern definitions to rates header
bool factors_flag = false;
bool nb_flag = false;
bool alm_flag = false;
bool tcm_flag = false;
bool avr_flag = false;
bool imr_flag = false;
bool gaap_flag = false;
bool tgt_cap_flag = false;
bool stoch_flag = false;
bool valn_flag = false;
bool time_step_flag = false;
bool sfas133_valn_flag = false;
bool sop031_valn_flag = false;
bool sfas97rd_valn_flag = false;
bool sfas97lp_valn_flag = false;
bool sfas97lp_gpr_valn_flag = false;
bool sfas91_valn_flag = false;
bool sfas60_valn_flag = false;
bool sfas60_gpr_valn_flag = false;
bool sfas120_nlp_valn_flag = false;
bool sfas120_valn_flag = false;
bool sfas120_gpr_valn_flag = false;
bool loc_gpr_valn_flag = false;
bool pba_valn_flag = false;
bool pba_scen_amt_valn_flag = false;
bool rbc_scen_amt_valn_flag = false;
bool res_scen_amt_valn_flag = false;
bool res_det_res_valn_flag = false;
bool res_ag38_8d_valn_flag = false;
bool std_scen_valn_flag = false;
bool rbc_std_scen_valn_flag = false;
bool rbc_std_scen_step2_valn_flag = false;
bool res_std_scen_valn_flag = false;
bool res_stat_tax_valn_flag = false;
bool hedge_valn_flag = false;
bool hedge_valn_shock_flag = false;
bool hedge_valn_final_flag = false;
bool hedge_proj_stmt_flag = false;
bool investing_flag = false;
bool investing_bom_flag = false;
bool intex_proj_flag = false;
bool proxy_bond_gen_flag = false;
bool running_parallel_flag = true;
// global comparison values
int last_proj_period = 0;
int valn_period = 0;
int investment_period = -1;
bool model_point_fatal_error_issued = false;
double aggregate_amount_threshold = 1.0e-02;
double model_point_amount_threshold = 1.0e-06;
double rate_ratio_threshold = 1.0e-10;
vector<string> valn_periods;
// utility function elaborations
////////////////////////////////////////
//WTW - Gen2 - Move Extern definitions to rates header

/*double round_result(int rounding, int negative, double x, int n)
{
if (x == 0.0)
	return 0.0;
int loop = 0;
char buff[20] = {0};
const double tenth[15]
= {1, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001,
0.00000001, 0.000000001, 0.0000000001, 0.00000000001,
0.000000000001, 0.0000000000001, 0.00000000000001};
const double ten[15]
= {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0,
100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0,
10000000000000.0, 100000000000000.0};
double adj = 0.0;
// Note: do not increase the number of nines below.  The result of the round
// (see formula at the bottom of the routine) added to the number of 9's must
// not exceed 16 digits.
const int ROUND_NEGATIVE_TOZERO = 0;
const int ROUND_NEGATIVE_FROMZERO = 1;
const int ROUND_LOW = 0;
const int ROUND_NEAR = 1;
const int ROUND_HIGH = 2;
// ad_hoc adjustment factor  0.000000001
const double positive_high = 0.999999999;
const double positive_low  = 0.0;
const double positive_near = 0.500000001;
const double negative_high = 0.0;
const double negative_low  = 0.999999999;
const double negative_near = 0.499999999;
// The below "rounding" is to deal with floats that were converted to doubles,
// and thus have a loss of information past 6 places
//  To truncate x to 5 decimal places: sprintf() %.6lf to avoid rounding at the
//  5th decimal position then get rid of the last digit.
if (rounding >= 3)
	{
	sprintf(buff,"%.6lf",x);
	buff[strlen(buff)-1]='\0';
	x = strtod(buff, NULL);
	rounding-=3;
	}
if (n < 0 || n > 14)
	return(x);
if (x < (double) 0  && negative == ROUND_NEGATIVE_TOZERO)
	{
	if (rounding==ROUND_HIGH)
		adj = negative_high;
	else if (rounding==ROUND_NEAR)
		adj = negative_near;
	}
else if (x < (double) 0  && negative == ROUND_NEGATIVE_FROMZERO
	     && rounding==ROUND_LOW)
	adj = negative_low;
else
	{
	// ***************************************************
	// x < 0 with negative==tozero and rounding==low
	// x < 0 with negative==fromzero and rounding==high
	// x < 0 with negative==fromzero and rounding==near
	// x > 0
	// ***************************************************
	if (rounding == ROUND_HIGH)
		adj = positive_high;
	else if (rounding == ROUND_NEAR)
		adj = positive_near;
	else if (rounding == ROUND_LOW)
		adj = positive_low;
	}
if (x < (double) 0)
	return(-1 * floor(x * ten[n] * -1 + adj) * tenth[n]);
return(floor(x * ten[n] + adj) * tenth[n]);
}
//////////////////////////////////////////////////////
double factorial(int n)
{
if (n <= 1)
	return 1;

double result = 1.0;

for (int i = 1; i <= n; i++)
	result = result * i;

return result;
}
//////////////////////////////////////////////////////
int n_choose_k(int n, int k)
{
if (k < 0 || k > n)
	return 0;

if (k < 1)
	return 1;

if (k == n)
	return 1;

return n_choose_k(n - 1, k) + n_choose_k(n - 1, k - 1);
}
//////////////////////////////////////////////////////
xstring check_date_format(const xstring &date)
{
// Check for format
char* endptr;
double date_serial_number = strtod(date, &endptr);
if (!*endptr 
	&& date_serial_number >= 1 
	&& date_serial_number <= 2958465) // input date is a date_serial_number
	return "DSN";

// input date is not a date_serial_number, treat it like a regular string	
int date_length = date.length();
xstring date_format = "USLIB";
if (date_length < 6 || date_length > 10)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted.");

if (date.substr(4, 1) != "/" && date(date.find_last_of("/") + 1).length() != 4)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Two digit years are not supported.");

if (date(date.find_last_of("/") + 1).length() == 4)
	{
	// date is US format
	date_format = "US";
	// date is m/yyyy, m/d/yyyy, m/dd/yyyy, mm/yyyy, mm/d/yyyy or mm/dd/yyyy
	if (date.find_first_of("/") > 2)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
else
	{
	date_format = "USLIB";
	// date is yyyy/m, yyyy/m/d, yyyy/m/dd, yyyy/mm, yyyy/mm/d, or yyyy/mm/dd
	if (date.find_last_of("/") > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 9)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
return date_format;
}
/////////////////////////////////////////////////////
int get_mth_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	return month_from_day_number(atoi(date));
	//return MonthFromDayNumber(atof(date));

// date_format != "DSN"
int mth = 0;
// find where mth information starts and ends
int mth_start_idx = 0;
int mth_end_idx = 0;
if (date_format == "USLIB")
	{
	mth_start_idx = date.find_first_of("/") + 1;
	mth_end_idx = date.find_last_of("/");
	
	if (mth_end_idx == mth_start_idx) // there is no day in the date
		mth = atoi(date.substr(mth_start_idx));
	else
		mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
else // date_format == "US" 
	{
	mth_start_idx = 0;
	mth_end_idx = date.find_first_of("/");
	mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
// validate month entry
if (mth < 1 || mth > 12)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid month value (" + xstring(mth) + ") in date.");	
return mth;
}
///////////////////////////////////////////////
int month_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported MonthFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 2;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return j + 2 - ( 12 * l );
}
/////////////////////////////////////////////////////
int month_number_from_date(int year, int month) //WTW - Gen2 - add new formula to replace unsupported MonthNumberFromDate() function
{
return 12 * year + month - 1;
}
/////////////////////////////////////////////////////
int day_number_from_date(int nYear, int nMonth, int nDay) //WTW - Gen2 - add new formula to replace unsupported DayNumberFromDate() function
{
    // Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
    // leap year, but Excel/Lotus 123 think it is...
    if (nDay == 29 && nMonth == 02 && nYear==1900)
        return 60;

    // DMY to Modified Julian calculated with an extra subtraction of 2415019.
    long nSerialDate = 
            int(( 1461 * ( nYear + 4800 + int(( nMonth - 14 ) / 12) ) ) / 4) +
            int(( 367 * ( nMonth - 2 - 12 * ( ( nMonth - 14 ) / 12 ) ) ) / 12) -
            int(( 3 * ( int(( nYear + 4900 + int(( nMonth - 14 ) / 12) ) / 100) ) ) / 4) +
            nDay - 2415019 - 32075;

    if (nSerialDate < 60)
    {
        // Because of the 29-02-1900 bug, any serial date 
        // under 60 is one off... Compensate.
        nSerialDate--;
    }

    return (int)nSerialDate;
}
/////////////////////////////////////////////////////
int get_yr_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return YearFromDayNumber(atof(date));
	return year_from_day_number(atoi(date));

// date_format != "DSN"
// find where yr information start and ends
int yr_start_idx = 0;
int yr_end_idx = 0;
if (date_format == "USLIB")
	{
	yr_start_idx = 0; // yr information will always start at the beginning
	yr_end_idx = date.find_first_of("/");
	}
else // date_format == "US" 
	{
	yr_start_idx = date.find_last_of("/") + 1;
	yr_end_idx = date.length();
	}
int yr = atoi(date.substr(yr_start_idx, yr_end_idx));
return yr;
}
//////////////////////////////////////////////////
int year_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported YearFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 1900;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return 100 * ( n - 49 ) + i + l;
}
/////////////////////////////////////////////////////
int get_day_from_date(const xstring &date) 
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return DayFromDayNumber(atof(date));
	return day_from_day_number(atoi(date));

// date_format != "DSN"
// find where day information starts and ends
int day_start_idx = 0;
int day_end_idx = 0;
if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	day_end_idx = date.length(); // day always ends at the end
	if (day_start_idx == 5) // there is no day in the date, assume day is 1
		return 1;
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		return 1;
	}
int day = atoi(date.substr(day_start_idx, day_end_idx - day_start_idx));
// validate day entry
if (day < 1 || day > 31)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid day value (" + xstring(day) + ") in date.");
return day;
}
//////////////////////////////////////////////////
int day_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported DayFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 29;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);
    
return l - int(( 2447 * j ) / 80);
}
/////////////////////////////////////////////////////
int get_end_of_mth_day(int yr, int mth)
{
bool leap_yr = false;
int day = 31;

if ((mod(yr, 4) == 0 && mod(yr, 100) != 0)
	|| mod(yr, 400) == 0)
	leap_yr = true;		 	

switch (mth)
	{
	case 2:
		if (leap_yr)
			day = 29;
		else
			day = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	default:
		day = 31;
	}

return day;
}
//////////////////////////////////////////////////
xstring add_mths_to_date(const xstring &date, int mths)
{
// Check for format
xstring date_format = check_date_format(date);

// get date information
int mth = get_mth_from_date(date);
int yr = get_yr_from_date(date);

int addition_to_mth = 0;
int addition_to_yr = 0;
if (mths == 0)
	{
	addition_to_mth = 0;
	addition_to_yr = 0;
	}
else
	{
	addition_to_mth = (mths % 12);
	addition_to_yr = floor((mth + mths - 1) / 12.0);
	}

int new_mth = 0;
if (mth + addition_to_mth <= 0)
	new_mth = mth + addition_to_mth + 12;
else if (mth + addition_to_mth <= 12)
	new_mth = mth + addition_to_mth;
else
	new_mth = mth + addition_to_mth - 12;

int new_yr = (yr + addition_to_yr);

int day_start_idx = 0;
int day_end_idx = 0;
int day = 0;
xstring new_date = "";

if (date_format == "DSN")
	{
	day = get_day_from_date(date);
	new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
	}
else if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	if (day_start_idx == 5) // there is no day in the date, ignore
		new_date = xstring(new_yr) + "/" + xstring(new_mth);
	else
		{
		day = get_day_from_date(date);
		new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
		}
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		new_date = xstring(new_mth) + "/" + xstring(new_yr);
	else // DSN will always be here
		{
		day = get_day_from_date(date);
		new_date = xstring(new_mth) + "/" + xstring(day) + "/" + xstring(new_yr);
		}
	}
return new_date;
}
////////////////////////////////////
int get_mth_from_adj_date(const xstring &date, int mths)
{
//Get month from a date, adjusted for mths
int mth = 0;
mth = get_mth_from_date(date);
mth = mth + mths;

if (mth <= 0)
	{
	if (mth <= -12)
		mth = mth % 12;

	mth += 12;
	}
else if (mth > 12)
	{
	mth = mth % 12;

	if (mth == 0)
		mth = 12;
	}

return mth;
}
////////////////////////////////////
double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis) - 1.0;
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate, orig_rate_basis / new_rate_basis) - 1.0;//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
////////////////////////////////////
double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis);
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate, orig_rate_basis / new_rate_basis);//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
long int determine_tbl_size(int sNumberOfDims, ...)
{
//#define DIMT_MAX_DIMS 10
static constexpr int DIMT_MAX_DIMS = 10;//WTW - Gen2 - replace #define preprocessor statement
if (sNumberOfDims > DIMT_MAX_DIMS)
	throw FatalError("Multidimensional table too large. Cannot continue.");
int psIndecies[DIMT_MAX_DIMS] = {0};
int psMaxs[DIMT_MAX_DIMS] = {0};
int sLoop = 0;
long int sRetval = 0;
int sFactor = 1;
va_list vlArg_Ptr;
va_start(vlArg_Ptr, sNumberOfDims); // get first argument
for (sLoop = 0; sLoop < sNumberOfDims; sLoop++)
	psIndecies[sLoop] = va_arg(vlArg_Ptr, int); // get indexes
for (sLoop = 0; sLoop < sNumberOfDims ; sLoop++)
	psMaxs[sLoop]=va_arg(vlArg_Ptr, int); // get indexes
// loop backwards, for efficiency purposes, and to make the
// right-most index the "lowest" one.
for (sLoop = sNumberOfDims - 1; sLoop >= 0; sLoop--)
	{
	sRetval += (psIndecies[sLoop] - 1) * sFactor;
	if (sLoop > 0) // sFactor not needed last time through the loop
		sFactor *= psMaxs[sLoop];
	}
va_end(vlArg_Ptr);
return sRetval;
}
////////////////////////////////////
xstring get_file_name(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\");
if (path_end < 0)
	throw FatalError("Unrecognized File name '" + id + "'.");
xstring name = id(path_end + 1);
int name_end = name.find(".");
if (name_end == 0)
	throw FatalError("'.' cannot be the first character of the file name '" + id + "'.");
if (name_end > 0)
	return name(0, name_end);
return name;
}
///////////////////////////////////////////////////
xstring get_file_path(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\") + 1;
if (path_end > 0)
	return id(0, path_end);
throw FatalError("Unrecognized Data File name '" + id + "'.");
}
////////////////////////////////////////////////////////
xstring get_base_group_name(const xstring &tag, bool seriatim_flag)
{
// must strip "ProjTaskLoop ### " from group because RAFM prepends this to user's group tag
xstring xxx = tag.strip();

int pos = 0;
if (xxx(0, 2) == "0 ")
	return xxx(2);
if (xxx(0, 13) == "ProjTaskLoop ")
	{
	xxx = xxx(13);
	if (pricing_flag || seriatim_flag)
		pos = xxx.find("|");  // RAFM uses ProjTaskLoop XXX|Group when product is top model
	else
		pos = xxx.find(" ");
	if (pos > 0)
		xxx = xxx(pos + 1);
	else
		xxx = tag;
	}
else if ((pos = xxx.find(" #")) > 0)
	xxx = xxx(0, pos);
return xxx;
}
////////////////////////////////////////////////////////
xstring get_string_of_date(double date)
{
return xstring(get_yr_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_mth_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_day_from_date(xstring(date)));
}
////////////////////////////////////////////////////////
xstring get_string_of_enum_val(StrEnum::EnumValue type)
{
xstring type_string = "";

switch (type)
	{
	#if defined(__ASSET_ASSET_H_)
	case BOND: type_string = "Bond"; break;
	case MORTGAGE: type_string = "Mortgage"; break;
	case SECURITIZED_ASSET: type_string = "Securitized Asset"; break;
	case INTEREST_RATE_DERIVATIVE: type_string = "Interest Rate Derivative"; break;
	case REAL_ESTATE: type_string = "Real Estate"; break;
	case EQUITY: type_string = "Equity"; break;
	case INDEX_OPTION: type_string = "Index Option"; break;

	case BOOK: type_string = "Book"; break;
	case CASH: type_string = "Cash"; break;

	case NO: type_string = "No"; break;
	case YES: type_string = "Yes"; break;

	#if defined(__BOND_ASSET_H_)
	case HEDGING: type_string = "Hedging"; break;
	case INVESTMENT: type_string = "Investment"; break;
	case COLLATERAL_POOL: type_string = "Collateral Pool"; break;

	case AMERICAN: type_string = "American"; break;
	case EUROPEAN: type_string = "European"; break;

	case ANNUAL: type_string = "Annual"; break;
	case MONTHLY: type_string = "Monthly"; break;
	case QUARTERLY: type_string = "Quarterly"; break;
	case SEMI_ANNUAL: type_string = "Semi-Annual"; break;

	case CALL: type_string = "Call"; break;
	case CASH_FLOW_MAINTENANCE: type_string = "Cash Flow Maintenance"; break;
	case YIELD_MAINTENANCE: type_string = "Yield Maintenance"; break;

	case FIXED_RATE: type_string = "Fixed Rate"; break;
	case FLOATING_RATE: type_string = "Floating Rate"; break;

	case NOT_APPLICABLE: type_string = "Not Applicable"; break;
	case NOT_ASSIGNED: type_string = "Not Assigned"; break;
	case HELD_TO_MATURITY: type_string = "Held to Maturity"; break;
	case AVAILABLE_FOR_SALE: type_string = "Available for Sale"; break;
	case TRADING: type_string = "Trading"; break;

	case PRICE_SCHEDULE: type_string = "Price Schedule"; break;
	#endif

	#if defined(__MTG_ASSET_H_)
	case PENALTY_PERCENT: type_string = "Penalty Percent"; break;
	case YES_PER_SCHEDULE: type_string = "Yes Per Schedule"; break;
	#endif

	#if defined(__SEC_ASSET_H_)
	case ACCRUAL_ONLY: type_string = "Accrual Only"; break;
	case AFTER_PAC2: type_string = "After PAC2"; break;
	case BEFORE_PAC2: type_string = "Before PAC2"; break;
	case BOTH: type_string = "Both"; break;
	case IO: type_string = "IO"; break;
	case JUMP: type_string = "Jump"; break;
	case JUMP_STICK: type_string = "Jump/Stick"; break;
	case NON_ACCRUAL: type_string = "Non Accrual"; break;
	case PAC2A: type_string = "PAC2A"; break;
	case PO: type_string = "PO"; break;
	case TRANCHE_A: type_string = "Tranche A"; break;
	case TRANCHE_B: type_string = "Tranche B"; break;
	case TRANCHE_C: type_string = "Tranche C"; break;
	case TRANCHE_Z: type_string = "Tranche Z"; break;
	case Z_PAC: type_string = "Z PAC"; break;
	#endif

	#if defined(__IRD_ASSET_H_)
	case ALWAYS: type_string = "Always"; break;
	case IF_POSITIVE: type_string = "If Positive"; break;
	#endif

	#if defined(__EIO_ASSET_H_)
	case PUT: type_string = "Put"; break;
	case FUTURES: type_string = "Futures"; break;

	case NONE: type_string = "None"; break;
	case ASIAN: type_string = "Asian"; break;
	case HIGHEST_GAIN: type_string = "Highest Gain"; break;

	case SEMIANNUAL: type_string = "Semiannual"; break;
	#endif

	#if defined(__EPA_ASSET_H_)
	case SCHEDULE_FILE: type_string = "Schedule File"; break;
	case TAS_EPA_FILE: type_string = "TAS EPA File"; break;
	#endif

	#endif

	default: type_string = "Unknown";
	}

return type_string;
}
////////////////////////////////////////////////////////
int date_diff(xstring first_date, xstring second_date)
{
// Return difference in mths between first and second date
int first_yr = get_yr_from_date(first_date);
int second_yr = get_yr_from_date(second_date);
int first_mth = get_mth_from_date(first_date);
int second_mth = get_mth_from_date(second_date);

return (first_yr - second_yr) * 12 + first_mth - second_mth;
}
////////////////////////////////////////////////////////
//WTW - Gen2 - New external formula instead of preprocessing statement where #define is not allowed
int number_of_decimals(double xxx, int digits) 
{
return (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))));
}
////////////////////////////////////////////////////////
xstring write_string(double value, int string_length, int significant_digits)
{
// save value to at least 'significant_digits' significant digits.
//#define NUMBER_OF_DECIMALS(xxx,digits) (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))))
//int decimals = NUMBER_OF_DECIMALS(value, significant_digits);
int decimals = number_of_decimals(value, significant_digits);//WTW - Gen2 - replace preprocessor w formula
xstring string_value = "";
ostringstream message;
message.setf(ios::fixed);
message << setprecision(decimals) << value;
string_value = message.str();
if (string_value.length() <= string_length)
	return string_value;
// else output in scientific notation
if (string_length > 10)
	{
	ostringstream message2;
	message2.setf(ios_base::scientific, ios_base::floatfield);
	message2 << setprecision(string_length - 7) << value;
	string_value = message2.str();
	return string_value;
	}
// else output asterisks
ostringstream message2;
message2 << setw(string_length) << setfill('*') << "";
string_value = message2.str();
return string_value;
}
//////////////////////////////////////////////////////////////
// write_array_to_string - This functions takes an array and writes it to a string.
xstring write_array_to_string(SmartArray <double> value_array, int low, int high)
{
xstring temp_string = "";
int j = 0;
for (j=low; j <= high ; j++)
{
	temp_string += xstring(value_array[j]) + "|";
}
return temp_string;
}
////////////////////////////////////////////////////////////
void read_from_string(xstring temp_string, SmartArray <double> &temp_array)
{
int j = 0;
double new_entry = 0.0;
char* copyString = new char[ temp_string.length() + 1 ];
strcpy( copyString, temp_string.c_str() );				
char* fragment = strtok(copyString, "|");
while (fragment)
	{
	new_entry = atof(fragment);
	temp_array.push_back(new_entry);
	fragment = strtok(NULL, "|");
	}
}
/////////////////////////////////////
void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters)
{
// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
while (string::npos != pos || string::npos != lastPos)
	{
	// Found a token, trim and add it to the vector.
	string new_string = str.substr(lastPos, pos - lastPos);
	
	string::size_type startpos = new_string.find_first_not_of(" \t");
	string::size_type endpos = new_string.find_last_not_of(" \t");
	// if all spaces or empty return an empty string
	if((string::npos == startpos ) || ( string::npos == endpos))
		new_string = "";
	else
		{
		new_string = new_string.substr(startpos, endpos - startpos + 1);
		tokens.push_back(new_string);
		}	
	// Skip delimiters.  Note the "not_of"
	lastPos = str.find_first_not_of(delimiters, pos);
	// Find next "non-delimiter"
	pos = str.find_first_of(delimiters, lastPos);
	}
}
void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters, const string& dash)
{
//Perform comma search first and if dash is within commas add integers within range

// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
if (string::npos != pos || string::npos != lastPos)//If comma has been located
	{
	while (string::npos != pos || string::npos != lastPos)
		{
		// Found a token, trim and add it to the vector.
		string new_string = str.substr(lastPos, pos - lastPos);
	
		string::size_type startpos = new_string.find_first_not_of(" \t");
		string::size_type endpos = new_string.find_last_not_of(" \t");
		// if all spaces or empty return an empty string
		if((string::npos == startpos ) || ( string::npos == endpos))
			new_string = "";
		else
			{
			new_string = new_string.substr(startpos, endpos - startpos + 1);
		
			string::size_type found = new_string.find(dash);
		
			if (found != string::npos)//if dash is found, add values within range
				{
				xstring start = new_string.substr(0,found);
				xstring end = new_string.substr(found+1, new_string.size()-found-1);
				int start_range = atoi(start);
				int end_range = atoi(end);

				std::string push_value;

				for (int i = start_range; i <= end_range; i++)
					{
					push_value = std::to_string(i);
					tokens.push_back(push_value);
					}
				}
			else//otherwise add single value
				tokens.push_back(new_string);
			}	
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
		}
	}
else//No comma has been located
	{
	string::size_type found = str.find(dash);
		
	if (found != string::npos)//if dash is found, add values within range
		{
		xstring start = str.substr(0,found);
		xstring end = str.substr(found+1, str.size()-found-1);
		int start_range = atoi(start);
		int end_range = atoi(end);

		std::string push_value;

		for (int i = start_range; i <= end_range; i++)
			{
			push_value = std::to_string(i);
			tokens.push_back(push_value);
			}
		}	
	}
}

/////////////////////////////////////////////////
void query_run_time(const xstring &caller, const xstring &file_name)
{
static LARGE_INTEGER QRTFreq;
static LARGE_INTEGER QRTStartTime;
static LARGE_INTEGER QRTRestartTime;
static LARGE_INTEGER QRTEndTime;
static ofstream& QRTFile = * new ofstream;
static bool first = true;
if (first)
	{
	first = false;
	xstring query_run_time_file_name
	= get_file_path(file_name) + get_file_name(file_name) + "~QueryRunTime.TXT";
	QRTFile.open(query_run_time_file_name);
	QueryPerformanceFrequency((LARGE_INTEGER *)&QRTFreq);
	QRTFile.setf(ios::fixed, ios::floatfield);
	QRTFile << "Query Run Time output for " << get_file_name(file_name)
			<< endl;
	QRTFile << "QRTime: -Increment ---Total-- - " << caller
			<< " Frequency: " << (float)(QRTFreq.QuadPart)
			<< endl;
	QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
	//QRTStartTime = QRTRestartTime;
	QRTStartTime.QuadPart = QRTRestartTime.QuadPart;//WTW - Gen2 - Index out of range
	return;
	}
QueryPerformanceCounter((LARGE_INTEGER *)&QRTEndTime);
QRTFile << "QRTime: " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTRestartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTStartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << caller
		<< endl;
QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
return;
}
/////////////////////////////////////////////////////
// financial functions
double annual_yld(double monthly_numerator, double monthly_denominator, int return_frequency)
{
if (fabs(monthly_denominator) < 1.0e-02)
	return 0;
if (monthly_numerator == 0)
	return 0;
if (monthly_numerator > 0)
	{
	if (monthly_denominator > 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO > monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator < 0
		{
		if (monthly_numerator > MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
else // monthly_numerator < 0
	{
	if (monthly_denominator < 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO < monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator > 0
		{
		if (monthly_numerator < MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
return (pow_legacy(1.0 + (monthly_numerator / monthly_denominator),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
	   * return_frequency;
}
// V to the n
double vtothen(double rate_per_period, int num_periods)
{
return pow_legacy((1.0 / (1.0 + rate_per_period)), (double) num_periods);//WTW - Gen2 - use of undeclared identifier
}
// a angle n
double a_angle_n(double rate_per_period, int num_periods)
{
double temp_a_angle_n;
if (rate_per_period > 0.0)
	temp_a_angle_n = (1.0 - vtothen(rate_per_period, num_periods))
/ rate_per_period;
else
	temp_a_angle_n = (double) num_periods;
return temp_a_angle_n;
}
// cte calc
void cte_calc(SmartArray <SmartArray <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio)
{
int i = 0;
int j = 0;
int cte_index = 0;
double scen_amt_sum = 0.0;
double tax_avg_ratio_amt_sum = 0.0;
double scen_amt_temp_element = 0.0;
double tax_avg_ratio_temp_element = 0.0;
if (value_array[0].size() != value_array[1].size())
	{
	//WTW - Gen2 - log_screen not supported in Externs
	//log_screen.setf(ios::fixed, ios::floatfield);
	//log_screen << "Warning. The number of arrays for the scenario amount does not equal the number of arrays for the tax average ratio array."
	//			<< MSG_ERROR;
	}
if (value_array[0].size() == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
// first sort the array highest to lowest
for(i = 1; i < value_array[0].size(); i++)
	{
	for (j = i; j > 0; j--)
		{
	if (value_array[0][j] > value_array[0][j-1])
			{
			scen_amt_temp_element = value_array[0][j - 1]; // SCEN_AMT
			tax_avg_ratio_temp_element = value_array[1][j - 1]; // TAX_AVG_RATIO
			value_array[0][j - 1] = value_array[0][j];
			value_array[1][j - 1] = value_array[1][j];
			value_array[0][j] = scen_amt_temp_element;
			value_array[1][j] = tax_avg_ratio_temp_element;
			}
		}
	}
cte_index
= value_array[0].size() - ceil(cte_percentage * value_array[0].size());
if (cte_index == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
if (value_array[0].size() == 1 || cte_index == 1)
	{
	cte_amt = value_array[0][0];
	tax_avg_ratio = value_array[1][0];
	return;
	}
for (i = 0; i < cte_index; i++)
	{
	scen_amt_sum += value_array[0][i];
	tax_avg_ratio_amt_sum += value_array[1][i];
	}
cte_amt = scen_amt_sum / cte_index;
tax_avg_ratio = tax_avg_ratio_amt_sum / cte_index;
return;
}
// Black Scholes Highest Gain Frequency Multiple
double bs_highest_gain_freq_mult(double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int tn = 0;
double ta = 0.0;
double freq = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double tm = 0.0;
double h = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double v2 = 0.0;
double tsqrt = 0.0;
double sqrt2pi = 0.0;
double mu = 0.0;
double mutsqrt = 0.0;
double delta = 0.0;
double gamma = 0.0;
double alpha = 0.0;
double lambda = 0.0;
double highest_gain_freq_factor = 0.0;
// length_of_sampling_period (ta)
// sampling_freq             (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
//  yrs_to_expiry            (tee)
//  risk_free_rate           (r)
//  init_div_yld             (b)
//  index_vol                (v)
//
ta = length_of_sampling_period;
freq = sampling_freq;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
{
b = 0.0000001;
// Temporary until we calculate the limit of M2
// as b approaches zero.
}
if (fabs(freq) < 0.000001)
highest_gain_freq_factor = 1.0;
else
{   // Discrete sampling.
tm = min(tee, ta);
h = 1.0 / freq;
tn = ((int) (ta * freq)) + 1;
b1 = 0.5826;
b2 = 0.425;
v2 = v * v;
tsqrt = pow_legacy(tm, 0.5);//WTW - Gen2 - use of undeclared identifier
sqrt2pi = 2.50662827463100; // square root of 2  * Pi
mu = r - v2 / 2;
mutsqrt = mu * tsqrt;
delta = mutsqrt * (cumul_normal_distribn(mutsqrt / v) - 0.5);
gamma = (v * exp(-mutsqrt * mutsqrt * 0.5 / v2) / sqrt2pi + delta) * 0.5;
alpha = (gamma * tsqrt + b2 * v2 * tm * 0.5) / tn;
volatile double exparg = b1 * v * (pow_legacy(h, 0.5));//WTW - Gen2 - use of undeclared identifier
lambda = exp(exparg) / exp(alpha);
highest_gain_freq_factor = lambda;
}
return highest_gain_freq_factor;
}
// Black Scholes Option Value
double bs_opt_val(double strike_price, double yrs_to_expiry, double underlying_price, double vol, double risk_free_rate, double payout_rate, int call_or_put, int formula_code)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
//
// formula_code - CONTINUOUS_PAYOUT_CODE  for Continuous Payout (Merton's modification)
//                FUTURES_CODE            for Futures           (Black's modification)//
//
// Comments:  This approximation was taken from Table 3-6 ("European Option
// Valuation Formulas") on pages 117-118 of "Financial Options" by Figlewski,
// et. al., Business One Erwin, Homewood, Illinois.
//
// The major assumptions of the Black-Scholes option XModel are:  i) the
// asset price follows a geometric Brownian motion with constant variance
// v^2, ii) the asset returns follow a lognormal distribution, iii) there
// are no transaction costs or taxes, iv) securities are infinitely
// divisible and may be traded at all times, and v) there are no
// restrictions on short selling.  Under these assumptions the European
// option prices on an asset with discrete cash payouts are
//
//   Call Price =  S * N[ d1] * exp( -q * T ) - X * N[ d2] * exp( -r * T )
//   Put Price  = -S * N[-d1] * exp( -q * T ) + X * N[-d2] * exp( -r * T )
//
// where S = price of underlying asset minus present value of all cash paid
//           out prior to expiration
//           (For a bond the price of the bond and the present value of the
//            cash paid out is based on the Treasury spot curve plus a credit
//            spread and is calculated under the assumption that the bond is
//            neither callable nor putable.)
//        X     = option exercise price
//                 (For a bond this is the call or put amount plus accurued
//                  interest at time T.)
//        T     = time to option expiry
//        r     = riskless continuously conpounded yield to option expiry
//        q     = continuously conpounded payout rate
//        v     = annual price volatility
//        d1    = [ ln( S/X ) + ( r - q + (v^2) / 2 ) * T ] / [ v * ( T^.5 ) ]
//        d2    = d1 - [ v * ( T^.5 ) ]
//        N[.]  = cumulative normal distribution function
double d1 = 0;
double d2 = 0;
double opt_price = 0;
double continuous_risk_free_rate = 0;
double continuous_payout_rate = 0;
double d1_divisor = 0;
if (formula_code == CONTINUOUS_PAYOUT_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		continuous_risk_free_rate = 2.0 * log(1.0 + risk_free_rate / 2.0);
		continuous_payout_rate = log(1.0 + payout_rate);
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		d1 = (log(underlying_price / strike_price)
			  + (continuous_risk_free_rate - continuous_payout_rate
			  + (vol * vol) / 2.0)
				* yrs_to_expiry) / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * cumul_normal_distribn(d1)
			  * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			  - strike_price
			    * cumul_normal_distribn(d2)
			    * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= -underlying_price
			   * cumul_normal_distribn(-d1)
			   * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			   + strike_price
			     * cumul_normal_distribn(-d2)
			     * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
if (formula_code == FUTURES_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		d1 = (log(underlying_price / strike_price)
			  + ((vol * vol) / 2.0) * yrs_to_expiry)
			  / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= (underlying_price
			   * cumul_normal_distribn(d1)
			   - strike_price
			     * cumul_normal_distribn(d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= (-underlying_price
			   * cumul_normal_distribn(-d1)
			   + strike_price
				 * cumul_normal_distribn(-d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
return opt_price;
}
// Black Scholes Option Value Asian
double bs_opt_val_asian(int call_or_put, double current_price, double observed_average_price, double strike_price, double length_of_averaging_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int freq = 0;
int tn = 0;
int pn = 0;
int fn = 0;
double s = 0.0;
double savg = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double fr = 0.0;
double pr = 0.0;
double tr = 0.0;
double m1 = 0.0;
double b2v = 0.0;
double m2 = 0.0;
double h = 0.0;
double bv = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double f3 = 0.0;
double f4 = 0.0;
double f5 = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double b3 = 0.0;
double b4 = 0.0;
double var = 0.0;
double vavg = 0.0;
double xp = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double callprice = 0.0;
double asian_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price                    (s)
// observed_average_price           (savg)
// strike_price                     (x)
// length_of_averaging_period       (ta)
// sampling_freq                    (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry                    (t)
// risk_free_rate                   (r)
// init_div_yld                     (d)
// index_vol                        (v)
//
// Description.  This formula set assumes that the Asian values are based
//   on sample points at the beginnings and ends of sample months.  To
//   sample ends of months, execute this formula set with the length of the
//   averaging period reduced by one sample period.  The reduction does not
//   apply to continuous sampling.
// This is a modification by Phelim Boyle of the approximation
// that appears on in Levy's paper on "Pricing European average
// rate currency options", Journal of International Money and
// Finance (1992), 11, 474-491.
//
// The Phelim's modification consists of eliminating the formulas
// for the case where we are within the averaging period by
// using the formulas for the case before we enter the averaging
// period to value a similar option on an average over the
// future averaging points.  This modifications greatly
// simplifies the calculations without any loss of accuracy.
//
// Phelim also considers the case where the option pays with
// certainty.
//
// If b is zero, b is reset to 0.00001 because we have not been
// able to determine the limit of the second moment (M2) of the
// average distribution as b tends toward zero.
// Initialize variables.
s = current_price;
savg = observed_average_price;
x = strike_price;
ta = length_of_averaging_period;
freq = sampling_freq;
tee = yrs_to_expiry;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
v = index_vol;
// Calculate first and second moments of average distribution
// and fractional parts of sampling period.
//
//   |<----------Ta-------------------------------------->|
//                       |<----------Fn*h---------------->|
//                           |<----------tee------------->|
//   |-------------------|---:--|-------------------------|
//   0                   m   t m+1                        N
//   0                   5      6                        10
//
// b     = cost of carry (= r - d)
// m1    = first moment of average distribution
// m2    = second moment of average distribution
// h     = time between sampling points         (discrete case only)
// fn    = number of future sampling points     (discrete case only)
// pn    = number of observed sampling points   (discrete case only)
// tn    = Total number of sampling points      (discrete case only)
// fr    = portion of average period remaining
// pr    = portion of average period already observed
// tr    = length of average period remaining
b = r - d; // cost of carry
if (b == 0)
	{
	b = 0.0001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (freq == 0)
	{   //Continuous sampling.
	if (tee > ta)
		fr = 1.0;
	else
		fr = tee / ta;
	pr = 1.0 - fr;
	tr = min(ta, tee);
	m1 = (s / tr) * exp(b * (tee - tr))
		 * (exp(b * tr) - 1.0) / b;
	b2v = 2.0 * b + v * v;
	m2 = 2.0 * (pow_legacy((s / tr), 2.0) / (b + v * v))//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - tr))
		 * ((exp(b2v * tr) - 1.0) / b2v - (exp(b * tr) - 1.0) / b);
	}
else
	{   // Discrete sampling.
	h = 1.0 / freq;
	tn = ((int) (freq * ta)) + 1;
	if (tee <= ta)
		pn = ((int) (freq * (ta - tee))) + 1;
	else
		pn = 0;
	fn = tn - pn;
	fr = fn / ((double) tn);
	pr = 1.0 - fr;
	// Calculate first moment.
	m1 = (s / fn) * exp(b * (tee - (fn - 1) * h))
		 * (exp(b * fn * h) - 1.0)
		 / (exp(b * h) - 1.0);
	//Calculate second moment.
	bv = b + v * v;
	b2v = b + bv;
	f1 = exp(b2v * fn * h);
	f2 = exp(b * h);
	f3 = exp(b2v * h);
	f4 = exp(b * fn * h);
	f5 = exp(bv * h);
	b1 = (1.0 - f1) / ((1.0 - f2) * (1.0 - f3));
	b2 = (f4 - f1) / ((1.0 - f2) * (1.0 - f5));
	b3 = (f2 - f4) / ((1.0 - f2) * (1.0 - f5));
	b4 = (f3 - f1) / ((1.0 - f5) * (1.0 - f3));
	m2 = pow_legacy((s / fn), 2.0)//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - (fn - 1) * h))
		 * (b1 - b2 + b3 - b4);
	}
var = log(m2) - 2.0 * log(m1);
vavg = pow_legacy((max(var, 0.0)), 0.5);//WTW - Gen2 - use of undeclared identifier
// Calculate call option price.
// xp = strike price adjusted to value average over unsampled points
xp = (x - pr * savg) / fr;
if (xp > 0)
	{
	d1 = (0.5 * log(m2) - log(xp)) / vavg;
	d2 = d1 - vavg;
	callprice = exp(-r * tee)
				* (m1 * cumul_normal_distribn(d1)
				  - xp * cumul_normal_distribn(d2)) * fr;
	if (call_or_put == CALL_CODE)
		asian_opt_val = callprice;
	else
		asian_opt_val = callprice - (m1 - xp) * exp(-r * tee) * fr;
	}
else
	{   // the option pays with certainty
	if (call_or_put == CALL_CODE)
		asian_opt_val = exp(-r * tee) * (fr * m1 + pr * savg - x);
	else
		asian_opt_val = 0.0;
	}
return asian_opt_val;
}
// Black Scholes Option Value Levy Asian
double bs_opt_val_levy_asian(double strike_price, double yrs_to_expiry, double underlying_price, double average_price, double vol, double risk_free_rate, double payout_rate)
{
double tte = 0.0;
double K = 0.0;
double S = 0.0;
double rf = 0.0;
double q = 0.0;
double sigma = 0.0;
double Average = 0.0;
double levy_asian = 0.0;
double SE = 0.0;
double SV = 0.0;
double XStar = 0.0;
double m = 0.0;
double d = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double TERM = 1;
// Initialize variables.
tte = yrs_to_expiry;
K = strike_price;
S = underlying_price;
rf = risk_free_rate;
q = payout_rate;
sigma = vol;
Average = average_price;

if (tte <= 0.0)
	levy_asian =  max(0.0, Average - K);
SE = S / (TERM * (rf - q)) * (exp(((rf - q) - rf) * tte) - exp(-rf * tte));
m = 2.0 * pow_legacy(S,2.0) / ((rf - q) + pow_legacy(sigma,2.0)) * ((exp((2.0 * (rf - q) + pow_legacy(sigma,2.0)) * tte) - 1.0) /
	(2.0 * (rf - q) + pow_legacy(sigma,2.0)) - (exp((rf - q) * tte) - 1.0) / (rf - q));//WTW - Gen2 - use of undeclared identifier
d = m / pow_legacy(TERM,2.0);	//WTW - Gen2 - use of undeclared identifier
SV = log(d) - 2.0 * (rf * tte + log(SE));
if (SV < 0.0)
	levy_asian = max(0.0, Average - K);
else if (K < (TERM - tte) / TERM * Average)
	levy_asian = Average - K;
else 
{
	XStar = K - (TERM - tte) / TERM * Average;
	d1 = 1.0 / pow_legacy(SV,0.5) * (log(d) / 2.0 - log(XStar));//WTW - Gen2 - use of undeclared identifier
	d2 = d1 - pow_legacy(SV,0.5);//WTW - Gen2 - use of undeclared identifier
	
	levy_asian = SE * cumul_normal_distribn(d1) - XStar * exp(-rf * tte) * cumul_normal_distribn(d2);
}
return levy_asian;
}
// Black Scholes Option Value Continuous Highest Gain
double bs_opt_val_continuous_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
double s = 0.0;
double smax = 0.0;
double smin = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double mx = 0.0;
double e1 = 0.0;
double e2 = 0.0;
double t1 = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double highest_gain_continuous_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)      for call
// observed_min               (smin)      for put
// strike_price               (x)
// length_of_sampling_period  (ta)
// yrs_to_expiry              (t)
// yrs_to_expiry              (r)
// init_div_yld               (b)
// index_vol                  (v)
s = current_price;
smax = observed_max;
smin = observed_min;
x = strike_price;
ta = length_of_sampling_period;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
	* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
	* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
	{
	b = 0.0000001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (tee <= ta)
	{   // within sampling period
	if (call_or_put == CALL_CODE)
		mx = max(smax, x);
else
		mx = min(smin, x);
	e1 = (log(s / mx) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(tee, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
= exp(-r * tee)
			  * (mx - x)
			  + s * exp((b - r) * tee)
				  * cumul_normal_distribn(e1)
			  - mx * exp(-r * tee)
				  * cumul_normal_distribn(e2)
			  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2.0 * b))
				  * (-pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
				  * cumul_normal_distribn(e1 - 2 * b / v * pow_legacy(tee, 0.5))
			  + exp(b * tee)
				  * cumul_normal_distribn(e1));//WTW - Gen2 - use of undeclared identifier
	else
		highest_gain_continuous_opt_val
		= exp(-r * tee)
		  * (x - mx)
		  - s * exp((b - r) * tee)
			   * cumul_normal_distribn(-e1)
		  + mx * exp(-r * tee)
			   * cumul_normal_distribn(-e1 + v * pow_legacy(tee, 0.5))
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
			  * cumul_normal_distribn(-e1 + 2 * b / v * pow_legacy(tee,0.5))
		  - exp(b * tee)
			* cumul_normal_distribn(-e1));//WTW - Gen2 - use of undeclared identifier
}
else
{
// before sampling period
//
//  |<--------------tee---------------------------------->|
//  |<------t1-------->|<---------Ta--------------------->|
//  |------------------|----------------------------------|
//
	t1 = tee - ta;
	d1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));
	d2 = d1 - v * pow_legacy(tee, 0.5);
	e1 = ((b + pow_legacy(v, 2) / 2.0) * ta) / (v * pow_legacy(ta, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(ta, 0.5);
	f1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * t1) / (v * pow_legacy(t1, 0.5));//WTW - Gen2 - use of undeclared identifier
	f2 = f1 - v * pow_legacy(t1, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
		= s * exp((b - r) * tee)
		    * cumul_normal_distribn(d1)
		  - exp(-r * tee) * x
		    * cumul_normal_distribn(d2)
		  + s * exp(-r * tee) * (pow_legacy(v,2) / (2 * b))
		      * (-pow_legacy((s / x), (-2 * b / pow_legacy(v,2)))
		      * cumul_bivariate_normal_distribn(d1 - 2 * b * pow_legacy(tee, 0.5) / v,
							-f1 + 2 * b * pow_legacy(t1, 0.5) / v,
							-pow_legacy((t1 / tee), 0.5))
		  + exp(b * tee)
			* cumul_bivariate_normal_distribn(e1, d1, pow_legacy((1 - t1 / tee), 0.5)))
		  - s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(-e1, d1, -pow_legacy((1 - t1 / tee), 0.5))
		  - x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(f2, -d2, -pow_legacy((t1 / tee), 0.5))
		  + exp(-b * (ta)) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(f1)
			* cumul_normal_distribn(-e2);//WTW - Gen2 - use of undeclared identifier
else // "Put"
		highest_gain_continuous_opt_val
		= x * exp(-r * tee)
			* cumul_normal_distribn(-d2)
		  - s * exp((b - r) * tee)
			  * cumul_normal_distribn(-d1)
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / x), (-2 * b / pow_legacy(v, 2)))
			  * cumul_bivariate_normal_distribn(-d1 + 2 * b * pow_legacy(tee, 0.5) / v,
						f1 - 2 * b * pow_legacy(t1, 0.5) / v,
						-pow_legacy((t1 / tee), 0.5))
		  - exp(b * tee)
			* cumul_bivariate_normal_distribn(-e1, -d1, pow_legacy((1 - t1 / tee), 0.5)))
		  + s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(e1, -d1, -pow_legacy((1 - t1 / tee), 0.5))
		  + x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(-f2, d2, -pow_legacy((t1 / tee), 0.5))
		  - exp(-b * ta) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(-f1)
			* cumul_normal_distribn(e2);//WTW - Gen2 - use of undeclared identifier
}
return highest_gain_continuous_opt_val;
}
// Black Scholes Option Value Highest Gain
double bs_opt_val_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)
// observed_min               (smin)
// strike_price               (x)
// length_of_sampling_period  (ta)
// sampling_freq              (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry              (t)
// risk_free_rate             (r)
// init_div_yld               (b)
// index_vol                  (v)
//
// Description.  This formula set assumes that the high watermark values
//   are based on sample points at the beginnings and ends of sample
//   months.  To sample ends of months, execute this formula set with the
//   length of the sampling period reduced by one sample period.  The
//   reduction does not apply to continuous sampling.
double highest_gain_opt_val = 0.0;
if (sampling_freq == 0) // "Continuous"
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				observed_max,
				observed_min,
				strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
else // discrete sampling
	{
	double adjustment_factor
	= bs_highest_gain_freq_mult(length_of_sampling_period,
				sampling_freq,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
	double adj_max = observed_max * adjustment_factor;
	double adj_min = observed_min * adjustment_factor;
	double adj_strike_price = strike_price * adjustment_factor;
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				adj_max,
				adj_min,
				adj_strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq)
		/ adjustment_factor;
	}
return highest_gain_opt_val;
}
// Black Scholes Option Value Monthly Sum Cap
double bs_opt_val_mthly_sum_cap(int crediting_mths, int known_index_vals, double sum_capped_amts,  double mthly_cap_rate, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int n = 0.0;
int mo = 0.0;
int n_rem = 0.0;
double I = 0.0;
double D = 0.0;
double sigma = 0.0;
double m = 0.0;
double X = 0.0;
double mu = 0.0;
double p = 0.0;
double d = 0.0;
double M = 0.0;
double V = 0.0;
double sqrtV = 0.0;
double Evy = 0.0;
double Evy2 = 0.0;
double EvM = 0.0;
double VarM = 0.0;
double c1 = 0.0;
double c2 = 0.0;
double a = 0.0;
double b = 0.0;
double mthly_sum_cap_opt_val = 0.0;

n = crediting_mths;
mo = known_index_vals;
n_rem = n - mo;

I = log(1.0 + risk_free_rate / scen_int_freq)
    * scen_int_freq;
D = log(1.0 + init_div_yld / scen_index_freq)
    * scen_index_freq;
sigma = index_vol;
m = mthly_cap_rate;
mu = I - D;

M = (mu - (sigma * sigma) / 2.0) / 12.0;
X = (1.0 + m);
V = (sigma * sigma) / 12.0;
sqrtV = pow_legacy(V, 0.5);//WTW - Gen2 - use of undeclared identifier

p = cumul_normal_distribn(pow_legacy(12.0, 0.5) / sigma * (log(X) - M));//WTW - Gen2 - use of undeclared identifier

d = (M + V - log(X)) / sqrtV;

Evy = exp(M + V / 2.0) * cumul_normal_distribn(-d) 
       - X * cumul_normal_distribn(-d + sqrtV);  

Evy2 = exp(2 * M + 2 * V) * cumul_normal_distribn(-d - sqrtV)
       - 2 * X * exp(M + V / 2.0) * cumul_normal_distribn(-d)
	   + X * X * cumul_normal_distribn(-d + sqrtV); 

EvM = m + Evy; 
VarM = Evy2 - pow_legacy(Evy, 2.0);//WTW - Gen2 - use of undeclared identifier

c1 = (EvM - m * (1.0 - p)) / p;
c2 = (VarM  + EvM * EvM - m * m * (1.0 - p)) / p;

a = pow_legacy(12.0 * (c2 - (c1 * c1)), 0.5);//WTW - Gen2 - use of undeclared identifier
b = c1 - a / 2.0;

if (n_rem == 0)
	return sum_capped_amts;

double sum = 0.0;
for (int k = 0; k <= n_rem; k++)
	{
	double sumi = 0.0;
	for (int v = 0; v <= k; v++)
		{
		double vali1 = pow_legacy(-1, k - v);//WTW - Gen2 - use of undeclared identifier
		double vali2 = n_choose_k(k, v);
		double vali3 = pow_legacy(max(v * a + k * b + (n_rem - k) * m + sum_capped_amts, 0.0), k + 1);	//WTW - Gen2 - use of undeclared identifier		
		double vali = vali1 * vali2 * vali3;
		sumi += vali;
		}
	
	double valo1 = n_choose_k(n_rem, k);
	double valo2 = pow_legacy(p, k) * pow_legacy(1.0 - p, n_rem - k);//WTW - Gen2 - use of undeclared identifier
	double valo3 = pow_legacy(a, k) * factorial(k + 1);//WTW - Gen2 - use of undeclared identifier
	double valo = (valo1 * valo2) / valo3;
	sum += sumi * valo;
	}

mthly_sum_cap_opt_val 
= sum * exp(- I * yrs_to_expiry);

return mthly_sum_cap_opt_val;
}
// Cumulative Bivariate Normal Distribution
double cumul_bivariate_normal_distribn(double x, double y, double rho)
{
// This approximation for the cumulative bivariate normal distributions is
// described in appendix A, page 191, of Espen Haug's book titled "The
// Complete Guide To Option Pricing Formulas".
int i = 0;
int j = 0;
double x1 = 0.0;
double y1 = 0.0;
double rho1 = 0.0;
double rho2 = 0.0;
double delta = 0.0;
double pi = 0.0;
double signx = 0.0;
double signy = 0.0;
double cumulative_bivariate_normal_val = 0.0;
static double xx[5] = { 0.24840615, 0.39233107, 0.21141819, 0.03324666, 0.00082485334 };
static double yy[5] = { 0.10024215, 0.48281397, 1.0609498, 1.7797294, 2.6697604 };
x1 = x / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
y1 = y / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
pi = 3.14159265358979;
if (x < 0.0)
	signx = -1.0;
else if (x > 0.0)
	signx = 1.0;
else
	signx = 0.0;
if (y < 0.0)
	signy = -1.0;
else if (y > 0.0)
	signy = 1.0;
else
	signy = 0.0;
if (x <= 0 && y <= 0 && rho <= 0)
{
	double sum = 0.0;
	for (i = 0; i < 5; i++)
		{
		for (j = 0; j < 5; j = j + 1)
			{
			sum
			= sum
			  + xx[i] * xx[j]
			  * exp(x1 * (2 * yy[i] - x1)
					+ y1 * (2 * yy[j] - y1)
					+ 2 * rho * (yy[i] - x1) * (yy[j] - y1));
			}
		}
	cumulative_bivariate_normal_val = pow_legacy((1 - pow_legacy(rho, 2)), 0.5) / pi * sum;//WTW - Gen2 - use of undeclared identifier
	}
else
	{
	if (x <= 0 && y >= 0 && rho >= 0)
		cumulative_bivariate_normal_val
		= cumul_normal_distribn(x)
		  - cumul_bivariate_normal_distribn(x, -y, -rho);
	else
		{
		if (x >= 0 && y <= 0 && rho >= 0)
			cumulative_bivariate_normal_val
			= cumul_normal_distribn(y)
			  - cumul_bivariate_normal_distribn(-x, y, -rho);
		else
			{
			if (x >= 0 && y >= 0 && rho <= 0)
				cumulative_bivariate_normal_val
				= cumul_normal_distribn(x)
				  + cumul_normal_distribn(y) - 1
				  + cumul_bivariate_normal_distribn(-x, -y, rho);
			else
				{
				if (x * y * rho > 0)
					{
					rho1 = (rho * x - y) * signx
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					rho2 = (rho * y - x) * signy
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					delta = (1 - signx * signy) / 4.0;
					cumulative_bivariate_normal_val
					= cumul_bivariate_normal_distribn(x, 0, rho1)
					  + cumul_bivariate_normal_distribn(y, 0, rho2)
					  - delta;
					}
				}
			}
		}
	}
return cumulative_bivariate_normal_val;
}
// Cumulative Normal Distribution
double cumul_normal_distribn(double x)
{
//Comments:  This approximation for the cummualtive normal distribution is taken
//from formula 26.2.17, page 932, of the "Handbook of Mathematical Function",
//National Bureau of Standards, Applied Mathematics Series 55, U.S.  Government
//Printing Office, Washington, D.C., 1964.  This approximation is accurate to 7
//decimal places.
//This routine calculates the cummulative normal distribution, N(x), as follows:
//For x >= 0
//N(x) = 1 - exp( -(x^2)/2 ) * (a*t + b*t^2 + c*t^3 + d*t^4 + e*t^5) / 2.5066
//28274 63100
//where  t = 1 / (1 + p*x)
//p =  0.23164 19
//a =  0.31938 1530
//b = -0.35656 3782
//c =  1.78147 7937
//d = -1.82125 5978
//e =  1.33027 4429
//For x < 0
//N(x) = 1 - N(-x)

double p =  0.2316419;
double a =  0.319381530;
double b = -0.356563782;
double c =  1.781477937;
double d = -1.821255978;
double e =  1.330274429;
double t = 1.0 / (1.0 + p * fabs(x));
if (x >= 0)
	{
	if (((x * x) / 2.0) < 225)
		return 1.0 - exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	return 1.0;
	}
else
	{
	if (((x * x) / 2.0) < 225)
		return exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	}
return 0.0;
}*/


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
#ifndef rates_economy_TableDefs
#define rates_economy_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection RATES_ECONOMY::TTHC;
void RATES_ECONOMY::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double RATES_ECONOMY_UDF::rates_economy_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.RATES_ECONOMY.for"
if (t == 0)
	return get_mth_from_date(proj_date_adj);

return proj_start_mth + t - 1
	   - 12 * floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double RATES_ECONOMY_UDF::rates_economy_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.RATES_ECONOMY.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.RATES_ECONOMY.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_date(int t) {
//^^^



//^^^

#line 1 "date.RATES_ECONOMY.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

//return DayNumberFromDate(year, month, day);
return day_number_from_date(year, month, day);//WTW - Gen2 - DayNumberFromDate() unsupported function

}


//@@ END

//@@ START - equity_market_value_growth_us
// US Equity Market Value Growth                                                                                             
// Column:EQUITY_MARKET_VALUE_GROWTH_US
//========================================================
double RATES_ECONOMY_UDF::rates_economy_equity_market_value_growth_us(int t) {
//^^^



//^^^

#line 1 "equity_market_value_growth_us.RATES_ECONOMY.for"
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

// Return NO_AVG if index is not found
if (find(index_list.begin(), index_list.end(), "US") == index_list.end())
	return NO_AVG;

return get_index_rate(t, "US", GET_GROWTH_RATE, EFFECTIVE_ANNUAL);

}


//@@ END

//@@ START - equity_scenario_total_return_us
// US Equity Scenario Total Return                                                                                             
// Column:EQUITY_SCENARIO_TOTAL_RETURN_US
//========================================================
double RATES_ECONOMY_UDF::rates_economy_equity_scenario_total_return_us(int t) {
//^^^



//^^^

#line 1 "equity_scenario_total_return_us.RATES_ECONOMY.for"
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

// Return NO_AVG if index is not found
if (find(index_list.begin(), index_list.end(), "US") == index_list.end())
	return NO_AVG;

return get_index_rate(t, "US", GET_TOTAL_RETURN, EFFECTIVE_ANNUAL);

}


//@@ END

//@@ START - exact_date
// Exact Date                                                                                             
// Column:EXACT_DATE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_exact_date(int t) {
//^^^



//^^^

#line 1 "exact_date.RATES_ECONOMY.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899

int year = cal_yr(t);
int month = cal_mth(t);
int day = get_day_from_date(proj_date);

//return DayNumberFromDate(year, month, day);
return day_number_from_date(year, month, day);//WTW - Gen2 - DayNumberFromDate() unsupported function

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.RATES_ECONOMY.for"
return 0.0;

}


//@@ END

//@@ START - generate
// Generate Scenarios                                                                                             
// Column:GENERATE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_generate(int t) {
//^^^



//^^^

#line 1 "generate.RATES_ECONOMY.for"
if (t != 0)
	return NO_AVG;

// Do not generate when inner loop valuation period is 0 and not generating for the initial period
// unless we are generating the shocked scenarios
if (time_step_flag && valn_period == 0
	&& gen_initial_valn_period == NO
	&& gen_defn != SHOCKED_SCENARIOS)
	return 0;

if (gen_defn == SHOCKED_SCENARIOS)
	{
	setup_shock_gen_list();

	// Do not generate when inner loop valuation period is not consistent with shock frequency
	if (time_step_flag && valn_period > 0)
		{
		// set lookup key 
		shock_id = shock_gen_list[proj_task_loop_num - 1];

		if ((valn_period % shock_freq) != 0)
			return 0;
		}
	}

setup_generation_parameters(t);
setup_economy_data(t);
setup_calibration_criteria(t);

econ_err_code = Econ->Generate(GenData, EconData, CalibData, 0);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);	

// Clean up Generation, Economy Data, Calibration Data, and Economy objects
if (GenData != NULL)
    {
    GenerationData::Release(GenData);
    GenData = NULL;
    }

if (EconData != NULL)
    {
    EconomyData::Release(EconData);
    EconData = NULL;
    }

if (CalibData != NULL)
    {
    CalibrationData::Release(CalibData);
    CalibData = NULL;
    }

if (Econ != NULL)
    {
    Economy::Release(Econ);
    Econ = NULL;
    }

return 1.0;

}


//@@ END

//@@ START - infl_rate_annual
// Inflation Rate Annual                                                                                             
// Column:INFL_RATE_ANNUAL
//========================================================
double RATES_ECONOMY_UDF::rates_economy_infl_rate_annual(int t) {
//^^^



//^^^

#line 1 "infl_rate_annual.RATES_ECONOMY.for"
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return get_infl_rate(t, EFFECTIVE_ANNUAL);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double RATES_ECONOMY_UDF::rates_economy_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.RATES_ECONOMY.for"
//WTW - Gen2 - Move to rates->startup()
if (!stoch_flag)
	return 1.0;

/*if (hedge_valn_flag)
	{
	// Determine the initial scenario to load for hedge valuation
	// Scenarios will be reloaded using a call to scen_rate_load from the hedging valuation process
	// per the start scenario for the model point and the task loop increment
	if (hedge_valn_final_flag)
		scen_rates_load(proj_task_loop_num);
	else 
		{
		xstring hedge_valn_shock_id_full = hedge_valn_shock_list[proj_task_loop_num - 1];
		xstring hedge_valn_shock_id = hedge_valn_shock_id_full(0, hedge_valn_shock_id_full.find("|TaskLoopIncr"));

		// Do not load scenario rates if shock is not being run
		if (time_step_flag && valn_period > 0)
			{
			// set lookup key
			shock_id = hedge_valn_shock_id;
			if ((valn_period % shock_freq) != 0)
				return 1;
			}

		// The task loop starts at the position after the last dash "-" of the hedge_valn_shock_id
		int task_loop_start_pos = hedge_valn_shock_id_full.find_last_of("-");
		int hedge_task_loop_num = atoi(hedge_valn_shock_id_full(task_loop_start_pos + 1));

		scen_rates_load(hedge_task_loop_num);
		}
	}
else if (!time_step_flag)
	{
	// if generating outside of a nested projection, always load scenario 1 to get initial rates
	if (target_column.find("generate") < string::npos) 
		scen_rates_load(1);
	else
		scen_rates_load(proj_task_loop_num);
	}
else if (valn_flag && !isMainModel)
	scen_rates_load(proj_task_loop_num);
else
	scen_rates_load(proj_set_loop_num);*/

return 1.0;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double RATES_ECONOMY_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.RATES_ECONOMY.for"
#if 0 // START_HEADER
#include <sstream> // For ostringstream
#include <sys/stat.h> // For file access
#include <vector>
#include <cmath>  // For floor()
#include <random> // 20200214 STW: import package for random number generation
				  // 20200303 MTC - Ported VA PRNG code for Flex

#pragma once
// Common elements from the Economy interface  -- enums, constants

#ifdef ECONOMY_EXPORTS
#define ECONOMY_API __declspec(dllexport)
//#else
//#define ECONOMY_API __declspec(dllimport)//WTW - Gen2 - replace attribute below with direct 
#endif

#define NOMINMAX

//WTW - Gen2
// 20181217 MTC - Refactored cubic spline
#ifndef CUBIC_SPLINE_AIG//WTW - Gen2
struct cubic_spline_params_aig
{
	cubic_spline_params_aig(): initialized(false),
						       n(0),
							   h(vector<double>()),
							   alpha(vector<double>()),
							   l(vector<double>()),
							   mu(vector<double>()),
							   z(vector<double>()),
							   c(vector<double>()),
							   b(vector<double>()),
							   d(vector<double>()) {}
	bool initialized;
	int n;
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;
};

const cubic_spline_params_aig default_cubic_spline_params_aig = cubic_spline_params_aig();
// 20181217 MTC END
#define CUBIC_SPLINE_AIG//WTW - Gen2
#endif//WTW - Gen2

const int MAX_ERR_LEN = 200;
const int MAX_DESC_LEN = 100;
const int MAX_ID_LEN = 150;
const int MAX_MAT_LEN = 4;
const int MAX_PATH_LEN = 300;
const int MAX_TERM = 600;

enum CalibrationOption
{
No = 0,
Yes = 1
};    

enum CalibrationType
{
InterestRates = 0,
Spread = 1,
WealthFactors = 2
};

enum CalibrationIntSource
{
SwaptionVolatility = 0,
BondVolatility = 1
};

enum GenerationCalibrationProjType
{
Constant = 0,
TermStructure = 1
};

enum CalibrationIndexCallPut
{
Call = 0,
Put = 1
};

enum /*ECONOMY_API*/ __declspec(dllimport)  GenerationApproachType//WTW - Gen2
{
Stochastic=1,
MeanReversion = 2,
MeanReversionWithIndexSpread = 3,
StochasticExclusionTest = 4
};

enum /*ECONOMY_API*/ __declspec(dllimport) RWGenerationStochDefn//WTW - Gen2
{
RandomScenarios = 1,
AcademySelectedScenarios = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationRNMethod//WTW - Gen2
{
QuickGeneration=1,
CompleteGeneration= 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationMethod//WTW - Gen2
{
StandAlone=1,
OnTheFly = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationAudit//WTW - Gen2
{
AuditNo = 0,
AuditYes = 1
};

enum /*ECONOMY_API*/ __declspec(dllimport) YieldCurveTreatmentType//WTW - Gen2
{
ReleaseFromMemory = 1,
KeepInMemory = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) DateTreatmentType//WTW - Gen2
{
Actual = 1,
Relative = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenSetType//WTW - Gen2
{
Outer = 1,
Inner = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) EconErrorCodeType//WTW - Gen2
{
ECON_OK = 1,
ECON_WARNING = 2,
ECON_ERROR = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenarioBasisType//WTW - Gen2
{
RealWorld = 1,
RiskNeutral = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ValuationScenType//WTW - Gen2
{
AllRates = 1,
IndexRatesOnly = 2,
NoRatesReused = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenarioDefnType//WTW - Gen2
{
UnShocked = 1,
Shocked = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) MonthsPerPeriodType//WTW - Gen2
{
MonthlyRates = 1,
AnnualRates = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) YieldRateType//WTW - Gen2
{
Bond = 1,
Spot = 2,
Forward = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) CurrencyQuoteType//WTW - Gen2
{
Direct = 1,
Indirect = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) MissingValType//WTW - Gen2
{
Interpolate = 1,
Previous = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) RateReturnFreqType//WTW - Gen2
{
EffectiveAnnual = 1,
NominalSemiannual = 2,
NominalQuarterly = 4,
NominalMonthly = 12,
Semiannual = -2,
Quarterly = -4,
Monthly = -12
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockMethod//WTW - Gen2
{
Baseline = 1,
ParallelShock = 2,
SpecificShock = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockBasisType//WTW - Gen2
{
YieldCurveShock = 1,
IndexShock = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockType//WTW - Gen2
{
RateorPriceShock = 1,
VolatilityShock = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) EquityRateType//WTW - Gen2
{
GrowthRate = 1,
IncomeReturn = 2,
TotalReturn = 3,
DividendYield = 4,
IndexValue = 5
};

class /*ECONOMY_API*/ __declspec(dllimport) YieldTermData//WTW - Gen2
{
private:
    double Maturity;
    double Moneyness;
    double Vol;
    double MeanRevYieldRate;
	double InitYieldShock;

public:
    WINAPI YieldTermData();
    WINAPI YieldTermData(double maturity, double itmpct, double vol);
    virtual ~YieldTermData();
    virtual EconErrorCodeType WINAPI set_Maturity(double maturity);
    virtual EconErrorCodeType WINAPI set_Moneyness(double itmpct);
    virtual EconErrorCodeType WINAPI set_Vol(double vol);
    virtual EconErrorCodeType WINAPI set_MeanRevRate(double yld_rate);
	virtual EconErrorCodeType WINAPI set_InitYieldShock(double init_yld_shock);
    virtual EconErrorCodeType WINAPI get_Maturity(double & maturity);
    virtual EconErrorCodeType WINAPI get_Moneyness(double &itmpct);
    virtual EconErrorCodeType WINAPI get_Vol(double &vol);
    virtual EconErrorCodeType WINAPI get_MeanRevRate(double &yld_rate);
	virtual EconErrorCodeType WINAPI get_InitYieldShock(double &init_yld_shock);
    static  YieldTermData * YieldTermData::Create();
    static void YieldTermData::Release(YieldTermData *ytd);
};

class /*ECONOMY_API*/ __declspec(dllimport) YieldCurveData//WTW - Gen2
{
private:
    char                       ID[MAX_ID_LEN + 1];
    std::vector <YieldTermData> YTData;
    char                       errMessage[MAX_ERR_LEN + 1];
public:
    WINAPI YieldCurveData();

    YieldCurveData(char* id);
    virtual ~YieldCurveData();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_YieldTermData(YieldTermData &ytData);
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_YieldTermData(double maturity, double moneyness, YieldTermData &ytData);
    virtual bool WINAPI IsYieldTermDataEmpty();   // Is the YCdata vector empty?
    virtual EconErrorCodeType WINAPI ClearYieldTermData();  // Clear the YCdata vector
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static  YieldCurveData* YieldCurveData::Create();
    static void YieldCurveData::Release(YieldCurveData* ycd);
};

class /*ECONOMY_API*/ __declspec(dllimport) EcoCurrency//WTW - Gen2
{
private:
    char                      ID[MAX_ID_LEN+1];
    CurrencyQuoteType         QuoteType;
public:
    EcoCurrency();
    EcoCurrency(char* id);
    EcoCurrency(char* id, CurrencyQuoteType quoteType);
    virtual ~EcoCurrency();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_QuoteType(CurrencyQuoteType quoteType);
    virtual EconErrorCodeType WINAPI get_ID(char* &id);
    virtual EconErrorCodeType WINAPI get_QuoteType(CurrencyQuoteType &quoteType);
    static  EcoCurrency* EcoCurrency::Create();
    static void EcoCurrency::Release(EcoCurrency* ec);
};

class /*ECONOMY_API*/ __declspec(dllimport) AssetIndexTenorData//WTW - Gen2
{
private:
    double Tenor;
    double Moneyness;
    double Vol;
	double InitVolShock;
    double MeanRevIncomeRate;
    double MeanRevGrowthRate;
    double Spread;
public:
    WINAPI AssetIndexTenorData();
    WINAPI AssetIndexTenorData(double tenor, double itmpct, double vol);
    virtual ~AssetIndexTenorData();
    virtual EconErrorCodeType WINAPI set_Vol(double vol);
    virtual EconErrorCodeType WINAPI set_Moneyness(double itmpct);
    virtual EconErrorCodeType WINAPI set_Tenor(double tenor);
    virtual EconErrorCodeType WINAPI set_MeanRevIncomeRate(double inc_rate);
    virtual EconErrorCodeType WINAPI set_MeanRevGrowthRate(double grth_rate);
    virtual EconErrorCodeType WINAPI set_Spread(double sprd);
	virtual EconErrorCodeType WINAPI set_InitVolShock(double init_vol_shock);
    virtual EconErrorCodeType WINAPI get_Vol(double &vol);
    virtual EconErrorCodeType WINAPI get_Moneyness(double &itmpct);
    virtual EconErrorCodeType WINAPI get_Tenor(double &tenor);
    virtual EconErrorCodeType WINAPI get_MeanRevIncomeRate(double &inc_rate);
    virtual EconErrorCodeType WINAPI get_MeanRevGrowthRate(double &grth_rate);
    virtual EconErrorCodeType WINAPI get_Spread(double &sprd);
	virtual EconErrorCodeType WINAPI get_InitVolShock(double &init_vol_shock);
    static AssetIndexTenorData* AssetIndexTenorData::Create();
    static void AssetIndexTenorData::Release(AssetIndexTenorData* aitd);
};

class /*ECONOMY_API*/ __declspec(dllimport) AssetIndexData//WTW - Gen2
{
private:
      char                                  ID[MAX_ID_LEN+1];
      std::vector <AssetIndexTenorData>     INDXData;
      char                                  errMessage[MAX_ERR_LEN+1];
public:
    WINAPI AssetIndexData();
    WINAPI AssetIndexData(char* id);
    virtual ~AssetIndexData();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_AssetIndexTenorData(AssetIndexTenorData &indxData); // Add Equitydata object to the EQData vector
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_Size(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexTenorData(int indx, AssetIndexTenorData &indxData);
    virtual EconErrorCodeType WINAPI get_AssetIndexTenorDataUnique(int tenor, double moneyness, AssetIndexTenorData &indxData);
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    virtual EconErrorCodeType WINAPI clear(){INDXData.clear();return ECON_OK;};
    static  AssetIndexData* AssetIndexData::Create();
    static void AssetIndexData::Release(AssetIndexData* aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) MiscRateData//WTW - Gen2
{
private:
      char   ID[MAX_ID_LEN+1];
      double MeanRevRate;
      char errMessage[MAX_ERR_LEN+1];
public:
      WINAPI MiscRateData();
      virtual ~MiscRateData();
      virtual EconErrorCodeType WINAPI set_ID(char* id);
      virtual EconErrorCodeType WINAPI set_MeanRevRate(double rate);
      virtual EconErrorCodeType WINAPI get_ID(char* id);
      virtual EconErrorCodeType WINAPI get_MeanRevRate(double &rate);
      virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
      static  MiscRateData* MiscRateData::Create();
      static  void MiscRateData::Release(MiscRateData* mrd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationSwapData//WTW - Gen2
{
private:
	double Maturity;
	double Tenor;
	double Vol;
	double Wght;

public:
	WINAPI CalibrationSwapData();
	WINAPI CalibrationSwapData(double maturity, double tenor, double vol, double wght);
	virtual ~CalibrationSwapData();
	virtual EconErrorCodeType WINAPI set_Maturity(double maturity);
	virtual EconErrorCodeType WINAPI set_Tenor(double tenor);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI get_Maturity(double &maturity);
	virtual EconErrorCodeType WINAPI get_Tenor(double &tenor);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	static CalibrationSwapData * CalibrationSwapData::Create();
	static void CalibrationSwapData::Release(CalibrationSwapData *csd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationBondData//WTW - Gen2
{
private:
	double Term;
	double Vol;
	double Wght;

public:
	WINAPI CalibrationBondData();
	WINAPI CalibrationBondData(double term, double vol, double wght);
	virtual ~CalibrationBondData();
	virtual EconErrorCodeType WINAPI set_Term(double term);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI get_Term(double &term);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	static CalibrationBondData * CalibrationBondData::Create();
	static void CalibrationBondData::Release(CalibrationBondData *cbd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationYieldCurveData//WTW - Gen2
{
private:
	char						        ID[MAX_ID_LEN + 1];
	bool								CalibrationInterestNormalizeWghts;
	CalibrationIntSource				CalibrationInterestSource;
	GenerationCalibrationProjType		CalibrationInterestProjDefn;
	std::vector<CalibrationSwapData>	CalibrationSwapDataVector;
	std::vector<CalibrationBondData>	CalibrationBondDataVector;
	char						        errMessage[MAX_ERR_LEN + 1];

public:
	WINAPI CalibrationYieldCurveData();
	virtual ~CalibrationYieldCurveData();
	virtual EconErrorCodeType WINAPI set_ID(char *id);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestNormalizeWghts(bool calintnormalize);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestSource(CalibrationIntSource calintsource);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestProjDefn(GenerationCalibrationProjType calintproj);
	virtual EconErrorCodeType WINAPI set_CalibrationSwapData(CalibrationSwapData &csdata);
	virtual EconErrorCodeType WINAPI set_CalibrationBondData(CalibrationBondData &cbdata);
	virtual bool WINAPI IsCalibrationSwapDataEmpty();
	virtual bool WINAPI IsCalibrationBondDataEmpty();
	virtual EconErrorCodeType WINAPI get_ID(char *id);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestNormalizeWghts(bool &calintnormalize);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestSource(CalibrationIntSource &calintsource);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestProjDefn(GenerationCalibrationProjType &calintproj);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapData(int indx, CalibrationSwapData &csdata);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapMaturityArray(std::vector<double> &csmatarray);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapTenorArray(std::vector<double> &cstenorarray);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapVolAndWght(double maturity, double tenor, double &vol, double &wght);
	virtual EconErrorCodeType WINAPI get_CalibrationBondDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationBondData(int indx, CalibrationBondData &cbdata);
	virtual EconErrorCodeType WINAPI get_CalibrationBondTermArray(std::vector<double> &cbtermarray);
	virtual EconErrorCodeType WINAPI get_CalibrationBondVolAndWght(double term, double &vol, double &wght);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static CalibrationYieldCurveData * CalibrationYieldCurveData::Create();
	static void CalibrationYieldCurveData::Release(CalibrationYieldCurveData *cbd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationAssetIndexVolData//WTW - Gen2
{
private:
	double Moneyness;
	double Term;
	double Vol;
	double Wght;

public:
	CalibrationAssetIndexVolData();
	CalibrationAssetIndexVolData(double maturity, double tenor, double vol, double wght);
	virtual ~CalibrationAssetIndexVolData();
	virtual EconErrorCodeType WINAPI set_Moneyness(double moneyness);
	virtual EconErrorCodeType WINAPI set_Term(double tenor);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI set_InitVolShock(double init_vol_shock);
	virtual EconErrorCodeType WINAPI get_Moneyness(double &moneyness);
	virtual EconErrorCodeType WINAPI get_Term(double &tenor);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	virtual EconErrorCodeType WINAPI get_InitVolShock(double &init_vol_shock);
	static CalibrationAssetIndexVolData * CalibrationAssetIndexVolData::Create();
	static void CalibrationAssetIndexVolData::Release(CalibrationAssetIndexVolData *caivd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationAssetIndexData//WTW - Gen2
{
private:
	char						                   ID[MAX_ID_LEN + 1];
	bool								           CalibrationAssetIndexNormalizeWghts;
	double                                         CalibrationAssetIndexDivYld;  
	GenerationCalibrationProjType				   CalibrationAssetIndexProjDefn;
	CalibrationIndexCallPut                        CalibrationAssetIndexCallPutDefn;
	std::vector <CalibrationAssetIndexVolData>     CalibrationAssetIndexVolVector;
	char									       errMessage[MAX_ERR_LEN + 1];

public:
	WINAPI CalibrationAssetIndexData();
	virtual ~CalibrationAssetIndexData();
	virtual EconErrorCodeType WINAPI set_ID(char *id);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexNormalizeWghts(bool calindxnoramlize);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexDivYld(double divyld);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexProjDefn(GenerationCalibrationProjType calindxproj);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut calindxcallput);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexVolData(CalibrationAssetIndexVolData &indxData);  
	virtual bool WINAPI IsCalibrationAssetIndexVolDataEmpty();
	virtual EconErrorCodeType WINAPI get_ID(char *id);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexNormalizeWghts(bool &calindxnoramlize);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexDivYld(double &divyld);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexProjDefn(GenerationCalibrationProjType &calindxproj);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut &calindxcallput);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexVolDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexVolData(int indx, CalibrationAssetIndexVolData &indxData);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptMoneynessArray(std::vector<double> &caimonarray);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptTermArray(std::vector<double> &caitermarray);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptVolWghtAndShock(double moneyness, double term, double &vol, double &wght, double &shock);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static CalibrationAssetIndexData * CalibrationAssetIndexData::Create();
	static void CalibrationAssetIndexData::Release(CalibrationAssetIndexData * caid);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationPointData//WTW - Gen2
{
private:
    char   ID[MAX_ID_LEN+1];    // This is to allow to specify which Wealth Factors will be calibrated. Default 
								//  should be US for the US S&P500 fund in the RW generator.
    CalibrationType  CalType;   //  This aids in the separation of logic for the three different calibration processes.
    double Maturity;            // This specify what the maturity on the yield curve that the stats are collected.
	double TargetTime;          // This specifies the target year where the stats are collected 1 year, 5 year, 10 year, 20
								// year or 30 year
    double Percentile;          // This specifies which target percentile is collected (5% or 95% etc.)
    double PercentileTarget;    //  This is the actual target value, that can be adjusted by Tolerances
    double LowerTolerance;      //  This corresponds to the AAA A tolerance factor for interest rates.  This should be 
								//  set to zero when implementing the AG43 limits for the S&P500 fund.
								// when modeling spreads this will be the offset value.  
    double UpperTolerance;      //  The corresponds to the AAA B tolerance factor for interest ratesThis should be 
								//  set to zero when implementing the AG43 limits for the S&P500 fund.  When 
								//  modeling spreads this should be set to zero.
    char    errMessage[MAX_ERR_LEN+1];
public:
    CalibrationPointData();
    CalibrationPointData(char* id);
    CalibrationPointData(char* id, CalibrationType caltype);
    virtual ~CalibrationPointData();
    virtual EconErrorCodeType WINAPI set_ID(char* id); 
    virtual EconErrorCodeType WINAPI set_CalibrationType(CalibrationType caltype);
    virtual EconErrorCodeType WINAPI set_Maturity(double matur);
	virtual EconErrorCodeType WINAPI set_TargetTime(double ttime);
    virtual EconErrorCodeType WINAPI set_Percentile(double percnt);
    virtual EconErrorCodeType WINAPI set_PercentileTarget(double pcttarget);
    virtual EconErrorCodeType WINAPI set_LowerTolerance(double ltol);
    virtual EconErrorCodeType WINAPI set_UpperTolerance(double utol);
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_CalibrationType(CalibrationType &caltype);
    virtual EconErrorCodeType WINAPI get_Maturity(double &matur);
    virtual EconErrorCodeType WINAPI get_TargetTime(double &ttime);
    virtual EconErrorCodeType WINAPI get_Percentile(double &percnt);
    virtual EconErrorCodeType WINAPI get_PercentileTarget(double &pcttarget);
    virtual EconErrorCodeType WINAPI get_LowerTolerance(double &ltol);
    virtual EconErrorCodeType WINAPI get_UpperTolerance(double &utol);
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static  CalibrationPointData* CalibrationPointData::Create();
    static void CalibrationPointData::Release(CalibrationPointData* aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationData//WTW - Gen2
{
private:
	CalibrationOption					   CalibrationChoice;
	int									   CalibrationAttempts;
	int									   CalibrationAuditReport;
	std::vector<CalibrationPointData>      CalibrationVector; // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	double								   PassingPercentageInterest;  // This will allow the user to specify how many tests must pass before acceptance.
	double								   PassingPercentageSpread;    // This will allow the user to specify how many tests must pass before acceptance.
	double								   PassingPercentageEquity;    // This will allow the user to specify how many tests must pass before acceptance.
	std::vector<CalibrationYieldCurveData> CalibrationYCData;          // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	std::vector<CalibrationAssetIndexData> CalibrationAIData;          // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	char								errMessage[MAX_ERR_LEN + 1];
public:
	CalibrationData();
	virtual ~CalibrationData();

	virtual EconErrorCodeType WINAPI set_CalibrationChoice(CalibrationOption calobj);
	virtual EconErrorCodeType WINAPI set_CalibrationAttempts(int calatmp);
	virtual EconErrorCodeType WINAPI set_CalibrationAuditReport(int calrep);
	virtual EconErrorCodeType WINAPI set_CalibrationPointsData(CalibrationPointData caldata);
	virtual EconErrorCodeType WINAPI add_CalibrationPointsData(CalibrationPointData &caldata);
	virtual EconErrorCodeType WINAPI set_PassingPercentageInterest(double passperc);
	virtual EconErrorCodeType WINAPI set_PassingPercentageSpread(double passperc);
	virtual EconErrorCodeType WINAPI set_PassingPercentageEquity(double passperc);
	virtual EconErrorCodeType WINAPI set_CalibrationYieldCurveData(CalibrationYieldCurveData &cycdata);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexData(CalibrationAssetIndexData &caidata);
	virtual bool WINAPI IsCalibrationPointsDataEmpty();
	virtual bool WINAPI IsCalibrationYieldCurveDataEmpty();
	virtual bool WINAPI IsCalibrationAssetIndexDataEmpty();
	virtual EconErrorCodeType WINAPI get_CalibrationChoice(CalibrationOption &calobj);
	virtual EconErrorCodeType WINAPI get_CalibrationAttempts(int &calatmp);
	virtual EconErrorCodeType WINAPI get_CalibrationAuditReport(int &repflag);
	virtual EconErrorCodeType WINAPI get_CalibrationPointDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationPointDataID(int indx, char * ID);
	virtual EconErrorCodeType WINAPI get_CalibrationPointData(int indx, CalibrationPointData * caldata);
	virtual EconErrorCodeType WINAPI get_CalibrationPointData(char * ID, double matur, double ttime,
	CalibrationType caltype, double prctile, CalibrationPointData * caldata);
	virtual EconErrorCodeType WINAPI span_CalibrationPointData(char * ID, double matur, double ttime,
	CalibrationType caltype, CalibrationPointData * caldata, int &linkindex);
	virtual EconErrorCodeType WINAPI get_PassingPercentageInterest(double &passperc);
	virtual EconErrorCodeType WINAPI get_PassingPercentageSpread(double &passperc);
	virtual EconErrorCodeType WINAPI get_PassingPercentageEquity(double &passperc);
	virtual EconErrorCodeType WINAPI get_CalibrationYieldCurveDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationYieldCurveData(int indx, CalibrationYieldCurveData &cycdata);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexData(int indx, CalibrationAssetIndexData &caidata);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static  CalibrationData  * CalibrationData::Create();
	static  void CalibrationData::Release(CalibrationData * aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) EconomyData//WTW - Gen2
{
private:
    char BaseCurrency[MAX_ID_LEN + 1];
    std::vector <YieldCurveData> YieldCurvesVol;
    std::vector <AssetIndexData> AssetIndicesVol;
    std::vector <MiscRateData> msRatesData;
    std::vector <std::vector <double>> Correl;
    int ProcessCount;
    char errMessage[MAX_ERR_LEN + 1];
public:
    WINAPI EconomyData();
    virtual ~EconomyData();
	virtual EconErrorCodeType WINAPI set_BaseCurrency(char* baseCurrency);
	virtual EconErrorCodeType WINAPI set_YieldCurveData(YieldCurveData &yc);
    virtual EconErrorCodeType WINAPI set_AssetIndexData(AssetIndexData &index);
    virtual EconErrorCodeType WINAPI set_MiscRateData(MiscRateData &mr);
    virtual EconErrorCodeType WINAPI set_Correl(char* id1, char* id2, double correl);
    virtual EconErrorCodeType WINAPI get_YCID_Loc(char* id, int &loc);
    virtual EconErrorCodeType WINAPI get_AIID_Loc(char* id, int &loc);
	virtual EconErrorCodeType WINAPI get_YieldCurveData(char* id, YieldCurveData &yc);
    virtual EconErrorCodeType WINAPI get_YieldCurveDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_YieldCurveDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_AssetIndexDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexData(char* id, AssetIndexData &index);
    virtual EconErrorCodeType WINAPI get_MiscRateDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_MiscRateDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_MiscRateData(char* id, MiscRateData &mr);
	virtual EconErrorCodeType WINAPI get_Correl(char* id1, char* id2, double &correl);
	virtual EconErrorCodeType WINAPI get_ProcessCount(int &proccount);
	virtual EconErrorCodeType WINAPI Init_Correl();
	virtual EconErrorCodeType WINAPI clear_CurrencyData();
    virtual EconErrorCodeType WINAPI clear_YieldCurveData();
    virtual EconErrorCodeType WINAPI clear_AssetIndexData();
    virtual EconErrorCodeType WINAPI clear_MiscRatesData();
	virtual EconErrorCodeType WINAPI clear_Correl();
	virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static EconomyData* EconomyData::Create();
    static void EconomyData::Release(EconomyData* ed);
};

class /*ECONOMY_API*/ __declspec(dllimport) GenerationData//WTW - Gen2
{
private:
        long				GenDate;					// The date for the generation in the form yyyymmdd
		int 				GenDuration;				// The relative duration (months) from the projection date for the generation, i.e. 0, 12, 24, 36, etc
		int 				GenOuterLoopScenNum;		// The scenario number of the outer loop which is the basis for the generation
		double              GenMRPMean1HistYrs;         // This allows the user to pass the number of years to calculate the mean compotent of the AAA MRP.  (3 for both AAA and NAIC)
		double              GenMRPMean2HistYrs;         // This allows the user to pass the number of years to calculated the second mean required in the NAIC MRP formula. (10 for NAIC)
		double              GenMRPMedianHistYrs;        // This allows the user to pass the median number of years that is used to calculate the MRP for the RW scenarios. (50 years for both AAA and NAIC).
		GenerationMethod	GenMethod;				  // Standalone means the generation is standalone and the results of the generation should be written to the disk and all classes, etc 
														// created during the generation should be cleaned up following the process.
														// OnTheFly means the generation is 'on-the-fly' and the results of the generation 
														// should be created in memory. The scenario collections created (both historical 
														// and projected) should be kept around so that rates from the new scenarios can be retrieved. The SelectScenSet method is used for this case. 
		char GenHistFileName[MAX_PATH_LEN + 1];		 // The path and name for the newly created historical rates file
        char GenScenFileName[MAX_PATH_LEN + 1];		 // The path and name for the newly created scenario rates file
		ScenarioBasisType   GenBasis;				   // RW/RN	
		GenerationRNMethod GenRNMethod;				 // "QuickGeneration" CompleteGeneration"	"QuickGeneration means to do the 
														// quick generation RN approach
														// CompleteGeneration means to do a complete RN generation"
		GenerationApproachType GenApproach;			 // "Stochastic" or "MeanReversion"	"Stochastic means that the generation is a stochastic process
														// MeanReversion means that initial rates are linearly reverted back to a specific reversion rate 
														// over a specified number of months"
														// Stochastic Exclusion Test added 1/24/2011
		RWGenerationStochDefn  GenRWStochDefn;          // Option for RandomScenarios or using the AcademySelectScenarios when selecting scenarios to use in generation
		long				   GenRandomSeed;		   // Random seed used in RN scenario generation
	    GenerationCalibrationProjType GenIntProjDefn;   // Constant or Term Structure
		int                    GenMRMths;			   // The number of months for the mean reversion 
														// to the specified mean reversion rates
		int 				   GenScenarios;		    // The number of scenarios to generate
		int 				   GenHistMths;			 // The number of months back from the generation 
													    // period to create new historical rates for. The 
														// minimum possible value for this field is 0 which means to create a 
														// historical file with rates at the generation date.
	    int 				   GenScenMths;			 // The number of months of rates to generate for the scenarios
		MonthsPerPeriodType    GenScenMthsPerPeriod;	// MonthsPerPeriodType	"MonthlyRates", AnnualRates"	
														// "MonthlyRates means the generated scenario file contains monthly rates
														// AnnualRates means the generation scenario file contains annual rates
														// Note: The new historical file should ALWAYS contain monthly rates. 
														// Also, if the GenScenMths value is not evenly divisible by the integer 
														// representing the months per period type (1 or 12), then the number of 
														// months is INCREASED to the next evenly divisible value."
		DateTreatmentType      GenScenDateTreatment;	// DateTreatmentType	"Actual" Relative"	
														// "Actual means the scenario file uses actual dates for the economic conditions
														// "Relative" means the scenario file uses relative dates for the economic conditions
														// Note: The new historical file should ALWAYS use actual dates"
	    ValuationScenType      GenValnScenReuse;		// enum ValuationScenType	"AllRates" IndexRatesOnly"	
														// "AllRates means the generation should reuse all rates from the specified valuation scenario file
														// "InterestRates" means the generation should reuse just the index rates from the specified valuation 
														// scenario file
														// When AllRates is specified, all the generation needs to do is create the new historical rates file and then create a new file which is a copy of the specified valuation scenario file with the name of the new scenario file.
														// Note: If no valuation scenario file is provided in the GenValnScenFile property then the 
														// generation should generate all new rates."
		GenerationAudit  GenAuditDefn;                  // Set to yes to create the Generation Audit Report 
		int              GenAuditScen;                  // Set to the specified generated scenario to audit.
		char          GenValnScenFile[MAX_PATH_LEN + 1];// The path and name of an SOA ESML file which contains rates to be used in the generation process. This field is not required.
		char        		errMessage[MAX_ERR_LEN + 1];
		std::vector <double> GenBondTerms;               // This allows the addition of bond terms to be used in the generate process.
   
public:
		WINAPI GenerationData();
		virtual ~GenerationData();
		virtual EconErrorCodeType WINAPI set_BondTerm(double bondterm);
		virtual EconErrorCodeType WINAPI set_GenApproach(GenerationApproachType approach);
		virtual EconErrorCodeType WINAPI set_GenRWStochDefn(RWGenerationStochDefn genRWStochDefn);
		virtual EconErrorCodeType WINAPI set_GenDate(long date);
		virtual EconErrorCodeType WINAPI set_GenDuration(int duration);
		virtual EconErrorCodeType WINAPI set_GenerationBasis(ScenarioBasisType basis);
		virtual EconErrorCodeType WINAPI set_GenHistMths(int histmths);
		virtual EconErrorCodeType WINAPI set_GenMethod(GenerationMethod method);	
		virtual EconErrorCodeType WINAPI set_GenRandomSeed(long rndseed);
		virtual EconErrorCodeType WINAPI set_GenScenMths(int scenmths);
		virtual EconErrorCodeType WINAPI set_HistFileName(char* filename);
		virtual EconErrorCodeType WINAPI set_GenIntProjDefn(GenerationCalibrationProjType genintprojdefn);
		virtual EconErrorCodeType WINAPI set_MeanRevMths(int mrmths);
		virtual EconErrorCodeType WINAPI set_MRPMean1HistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_MRPMean2HistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_MRPMedianHistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_OuterLoopScenNum(int scennum);	
		virtual EconErrorCodeType WINAPI set_ProjFileName(char* filename);
		virtual EconErrorCodeType WINAPI set_RNMethod(GenerationRNMethod rnmethod);
		virtual EconErrorCodeType WINAPI set_Scenarios(int scennum);
		virtual EconErrorCodeType WINAPI set_ScenDateTreatment(DateTreatmentType GenScenDateTreatment);
		virtual EconErrorCodeType WINAPI set_ScenMthsPerPeriod(MonthsPerPeriodType scenmthsperperiod);
		virtual EconErrorCodeType WINAPI set_ValnScenReuse(ValuationScenType GenValnScenReuse);
		virtual EconErrorCodeType WINAPI set_ValnScenFile(char* valnscenfilename);
		virtual EconErrorCodeType WINAPI set_GenAuditDefn(GenerationAudit genauditdefn);
		virtual EconErrorCodeType WINAPI set_GenAuditScen(int genauditscen);
		virtual EconErrorCodeType WINAPI clear_BondTerms();
		virtual EconErrorCodeType WINAPI get_BondTerm(int loc, double &bondterm);
		virtual EconErrorCodeType WINAPI get_BondTermSize(int &size);
		virtual EconErrorCodeType WINAPI get_ErrMessage(char* errmessage);
		virtual EconErrorCodeType WINAPI get_GenApproach(GenerationApproachType &approach);
		virtual EconErrorCodeType WINAPI get_GenRWStochDefn(RWGenerationStochDefn &genRWStochDefn);
		virtual EconErrorCodeType WINAPI get_GenDate(long &date);
		virtual EconErrorCodeType WINAPI get_GenDuration(int &duration);
		virtual EconErrorCodeType WINAPI get_GenerationBasis(ScenarioBasisType &basis);
		virtual EconErrorCodeType WINAPI get_GenHistMths(int &histmths);
		virtual EconErrorCodeType WINAPI get_GenMethod(GenerationMethod &method);	
		virtual EconErrorCodeType WINAPI get_GenRandomSeed(long &rndseed);
		virtual EconErrorCodeType WINAPI get_GenScenMths(int &scenmths);
		virtual EconErrorCodeType WINAPI get_HistFileName(char* filename);
		virtual EconErrorCodeType WINAPI get_GenIntProjDefn(GenerationCalibrationProjType &genintprojdefn);
		virtual EconErrorCodeType WINAPI get_MeanRevMths(int &mrmths);
		virtual EconErrorCodeType WINAPI get_MRPMean1HistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_MRPMean2HistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_MRPMedianHistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_OuterLoopScenNum(int &scennum);	
		virtual EconErrorCodeType WINAPI get_ProjFileName(char* filename);
		virtual EconErrorCodeType WINAPI get_RNMethod(GenerationRNMethod &rnmethod);
		virtual EconErrorCodeType WINAPI get_Scenarios(int &scennum);
		virtual EconErrorCodeType WINAPI get_ScenMthsPerPeriod(MonthsPerPeriodType &scenmthsperperiod);
		virtual EconErrorCodeType WINAPI get_ScenDateTreatment(DateTreatmentType &GenScenDateTreatment);
		virtual EconErrorCodeType WINAPI get_ValnScenReuse(ValuationScenType &GenValnScenReuse);
		virtual EconErrorCodeType WINAPI get_ValnScenFile(char* valnscenfilename);
		virtual EconErrorCodeType WINAPI get_GenAuditDefn(GenerationAudit &genauditdefn);
		virtual EconErrorCodeType WINAPI get_GenAuditScen(int &genauditscen);
        static GenerationData* GenerationData::Create();
        static void GenerationData::Release(GenerationData* gd);
};

class RAScenario;

class /*ECONOMY_API*/ __declspec(dllimport) Economy//WTW - Gen2
{
private:
    YieldCurveTreatmentType YCTreatmentType;
    MissingValType          MissValType;
    ValuationScenType       ValnScenType;
    DateTreatmentType       DTTreatmentType;
    ScenSetType             ScenSet;
    long                    ProjYr;
    long                    ProjMth;
	long                    ProjDay;   
    char                    errMessage[MAX_ERR_LEN+1];
    int                     CSVOpenRetryAttempts;
	int						ValnPeriod; //VC++ 2017 Econ DLL
    void Economy::GetErrMessage();
    EconErrorCodeType Economy::GetErrMessage(EconErrorCodeType ok);
    RAScenario* RAScen;
    RAScenario* RAScenOuter;
    RAScenario* RAScenInner;

public:
    WINAPI Economy();
    ~Economy();
    virtual EconErrorCodeType WINAPI GetScenSet(ScenSetType &scensettype);
    virtual EconErrorCodeType WINAPI SelectScenSet(ScenSetType scensettype);
    virtual EconErrorCodeType WINAPI set_YCTreatmentType(YieldCurveTreatmentType ycTreatmentType);
    virtual EconErrorCodeType WINAPI set_MissValType(MissingValType missValType);
    virtual EconErrorCodeType WINAPI set_ValnScenType(ValuationScenType valnScenType);
    virtual EconErrorCodeType WINAPI set_DateTreatmentType(DateTreatmentType dttreattyp);
    virtual EconErrorCodeType WINAPI set_ProjDate(long projYr,long projMth);
    virtual EconErrorCodeType WINAPI set_ProjDate(long projYr,long projMth, long projDay);
    virtual EconErrorCodeType WINAPI set_ProjYear(long projYr);
    virtual EconErrorCodeType WINAPI set_ProjMonth(long projMth);
    virtual EconErrorCodeType WINAPI set_ProjDay(long projDay);
	virtual EconErrorCodeType WINAPI set_ValnPeriod(int valnPeriod); //VC++ 2017 Econ DLL
    virtual EconErrorCodeType WINAPI set_EconFilesRetryAttempts(int cnt);
    virtual EconErrorCodeType WINAPI get_ProjDate(long &projYr,long &projMth, long &projDay);
    virtual EconErrorCodeType WINAPI get_ProjYear(long &projYr);
    virtual EconErrorCodeType WINAPI get_ProjMonth(long &projMth);
    virtual EconErrorCodeType WINAPI get_ProjDay(long &projDay);
	virtual EconErrorCodeType WINAPI get_ValnPeriod(int &valnPeriod); //VC++ 2017 Econ DLL
    virtual EconErrorCodeType WINAPI get_DateTreatmentType(DateTreatmentType &dttreattyp);
    virtual EconErrorCodeType WINAPI get_YCTreatmentType(YieldCurveTreatmentType &ycTreatmentType);
    virtual EconErrorCodeType WINAPI get_MissValType(MissingValType &missValType);
    virtual EconErrorCodeType WINAPI get_ValnScenType(ValuationScenType &valnScenType);
    virtual EconErrorCodeType WINAPI get_ErrorMessage(char* errmessage);
    virtual EconErrorCodeType WINAPI ScenSetInfoLoad(char* pszProjFile, char* pszHistFile);
    virtual EconErrorCodeType WINAPI get_YieldCurveInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_IndexVolInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_MiscRateInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_EquityTypeInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_CurrencyInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_CountryInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_YieldCurveInfo(int listid,char* ID, char* Name, char* QualityScale, char* QualityLevel, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolInfo(int listid,char* ID, char* Name, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_IndexVolatilityInfo(int listid,char* ID, char* Name, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_MiscRateInfo(int listid, char* ID, char* Name);
    virtual EconErrorCodeType WINAPI get_EquityTypeInfo(int listid, char* ID, char* Name);
    virtual EconErrorCodeType WINAPI get_CurrencyInfo(int listid, char* ID, char* Name, char* Quotation);
    virtual EconErrorCodeType WINAPI get_CountryInfo(int listid, char* CountryName);
    virtual EconErrorCodeType WINAPI get_YieldCurveID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_IndexVolID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_MiscRateID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_EquityID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_CurrencyID(int listid,char* ID);
    virtual EconErrorCodeType WINAPI get_CountryID(int listid,char* ID);
    virtual EconErrorCodeType WINAPI ScenLoadProjRates(int scenID);
    virtual EconErrorCodeType WINAPI GetInterestRate(long date, char* country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestRate(int Year, int Month, int Day, char* Country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestRate(int duration, char* country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(long date, char* country, char* rateQuality, YieldRateType yieldRateType, int volPeriod,  double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(int Year, int Month, int Day, char* Country, char* rateQuality, YieldRateType yieldRateType, int volPeriod, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(int duration, char* country, char* rateQuality, YieldRateType yieldRateType, int volPeriod, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(long date, char* country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(int Year, int Month, int Day, char* Country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(int duration, char* country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(long date, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(int Year, int Month, int Day, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(int duration, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(int duration, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(long date, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(int Year, int Month, int Day, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetIndexRate(long date, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexRate(int Year, int Month, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexRate(int duration, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
	virtual EconErrorCodeType WINAPI GetIndexValue(long date, char * country, char *equityID, double &value);
	virtual EconErrorCodeType WINAPI GetIndexValue(int Year, int Month, int Day, char * country, char *equityID, double &value);
	virtual EconErrorCodeType WINAPI GetIndexValue(int duration, char * country, char *equityID, double &value);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(long date, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(int Year, int Month, int Day, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(int duration, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(long date, char* country,  char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(int Year, int Month, int Day, char* country, char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(int duration, char* country,  char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(long date, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(int Year, int Month, int Day, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(int duration, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(long date, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(int Year, int Month, int Day, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(int duration, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(long date, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(int Year, int Month, int Day, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(int duration, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI Generate(GenerationData* gendata, EconomyData* econdata,CalibrationData* caldata, int first=0);
    static Economy* Economy::Create();
    static void Economy::Release(Economy* ecdat);
  };

//WTW - Gen2 - Move Extern definitions to rates header
static bool pricing_flag = false;
const int CALL_CODE = 1;
const int PUT_CODE = 2; 
const int CONTINUOUS_PAYOUT_CODE = 3;
const int FUTURES_CODE = 4;const double MINIMUM_MONTHLY_YIELD_RATIO = -0.9; // annual yield = (1.0-0.9)^12 = 1.0e-12
const double MAXIMUM_MONTHLY_YIELD_RATIO	 = 999999999.0; // annual yield = (1.0+999999999.0)^12 = 1.0e+120

static double round_result(int rounding, int negative, double x, int n)
{
if (x == 0.0)
	return 0.0;
int loop = 0;
char buff[20] = {0};
const double tenth[15]
= {1, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001,
0.00000001, 0.000000001, 0.0000000001, 0.00000000001,
0.000000000001, 0.0000000000001, 0.00000000000001};
const double ten[15]
= {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0,
100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0,
10000000000000.0, 100000000000000.0};
double adj = 0.0;
// Note: do not increase the number of nines below.  The result of the round
// (see formula at the bottom of the routine) added to the number of 9's must
// not exceed 16 digits.
const int ROUND_NEGATIVE_TOZERO = 0;
const int ROUND_NEGATIVE_FROMZERO = 1;
const int ROUND_LOW = 0;
const int ROUND_NEAR = 1;
const int ROUND_HIGH = 2;
// ad_hoc adjustment factor  0.000000001
const double positive_high = 0.999999999;
const double positive_low  = 0.0;
const double positive_near = 0.500000001;
const double negative_high = 0.0;
const double negative_low  = 0.999999999;
const double negative_near = 0.499999999;
// The below "rounding" is to deal with floats that were converted to doubles,
// and thus have a loss of information past 6 places
//  To truncate x to 5 decimal places: sprintf() %.6lf to avoid rounding at the
//  5th decimal position then get rid of the last digit.
if (rounding >= 3)
	{
	sprintf(buff,"%.6lf",x);
	buff[strlen(buff)-1]='\0';
	x = strtod(buff, NULL);
	rounding-=3;
	}
if (n < 0 || n > 14)
	return(x);
if (x < (double) 0  && negative == ROUND_NEGATIVE_TOZERO)
	{
	if (rounding==ROUND_HIGH)
		adj = negative_high;
	else if (rounding==ROUND_NEAR)
		adj = negative_near;
	}
else if (x < (double) 0  && negative == ROUND_NEGATIVE_FROMZERO
	     && rounding==ROUND_LOW)
	adj = negative_low;
else
	{
	// ***************************************************
	// x < 0 with negative==tozero and rounding==low
	// x < 0 with negative==fromzero and rounding==high
	// x < 0 with negative==fromzero and rounding==near
	// x > 0
	// ***************************************************
	if (rounding == ROUND_HIGH)
		adj = positive_high;
	else if (rounding == ROUND_NEAR)
		adj = positive_near;
	else if (rounding == ROUND_LOW)
		adj = positive_low;
	}
if (x < (double) 0)
	return(-1 * floor(x * ten[n] * -1 + adj) * tenth[n]);
return(floor(x * ten[n] + adj) * tenth[n]);
}
//////////////////////////////////////////////////////
static double factorial(int n)
{
if (n <= 1)
	return 1;

double result = 1.0;

for (int i = 1; i <= n; i++)
	result = result * i;

return result;
}
//////////////////////////////////////////////////////
static int n_choose_k(int n, int k)
{
if (k < 0 || k > n)
	return 0;

if (k < 1)
	return 1;

if (k == n)
	return 1;

return n_choose_k(n - 1, k) + n_choose_k(n - 1, k - 1);
}
//////////////////////////////////////////////////////
static xstring check_date_format(const xstring &date)
{
// Check for format
char* endptr;
double date_serial_number = strtod(date, &endptr);
if (!*endptr 
	&& date_serial_number >= 1 
	&& date_serial_number <= 2958465) // input date is a date_serial_number
	return "DSN";

// input date is not a date_serial_number, treat it like a regular string	
int date_length = date.length();
xstring date_format = "USLIB";
if (date_length < 6 || date_length > 10)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted.");

if (date.substr(4, 1) != "/" && date(date.find_last_of("/") + 1).length() != 4)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Two digit years are not supported.");

if (date(date.find_last_of("/") + 1).length() == 4)
	{
	// date is US format
	date_format = "US";
	// date is m/yyyy, m/d/yyyy, m/dd/yyyy, mm/yyyy, mm/d/yyyy or mm/dd/yyyy
	if (date.find_first_of("/") > 2)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
else
	{
	date_format = "USLIB";
	// date is yyyy/m, yyyy/m/d, yyyy/m/dd, yyyy/mm, yyyy/mm/d, or yyyy/mm/dd
	if (date.find_last_of("/") > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 9)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
return date_format;
}
/////////////////////////////////////////////////////
static int month_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported MonthFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 2;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return j + 2 - ( 12 * l );
}
/////////////////////////////////////////////////////
static int get_mth_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	return month_from_day_number(atoi(date));
	//return MonthFromDayNumber(atof(date));

// date_format != "DSN"
int mth = 0;
// find where mth information starts and ends
int mth_start_idx = 0;
int mth_end_idx = 0;
if (date_format == "USLIB")
	{
	mth_start_idx = date.find_first_of("/") + 1;
	mth_end_idx = date.find_last_of("/");
	
	if (mth_end_idx == mth_start_idx) // there is no day in the date
		mth = atoi(date.substr(mth_start_idx));
	else
		mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
else // date_format == "US" 
	{
	mth_start_idx = 0;
	mth_end_idx = date.find_first_of("/");
	mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
// validate month entry
if (mth < 1 || mth > 12)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid month value (" + xstring(mth) + ") in date.");	
return mth;
}
///////////////////////////////////////////////
static int month_number_from_date(int year, int month) //WTW - Gen2 - add new formula to replace unsupported MonthNumberFromDate() function
{
return 12 * year + month - 1;
}
/////////////////////////////////////////////////////
static int day_number_from_date(int nYear, int nMonth, int nDay) //WTW - Gen2 - add new formula to replace unsupported DayNumberFromDate() function
{
    // Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
    // leap year, but Excel/Lotus 123 think it is...
    if (nDay == 29 && nMonth == 02 && nYear==1900)
        return 60;

    // DMY to Modified Julian calculated with an extra subtraction of 2415019.
    long nSerialDate = 
            int(( 1461 * ( nYear + 4800 + int(( nMonth - 14 ) / 12) ) ) / 4) +
            int(( 367 * ( nMonth - 2 - 12 * ( ( nMonth - 14 ) / 12 ) ) ) / 12) -
            int(( 3 * ( int(( nYear + 4900 + int(( nMonth - 14 ) / 12) ) / 100) ) ) / 4) +
            nDay - 2415019 - 32075;

    if (nSerialDate < 60)
    {
        // Because of the 29-02-1900 bug, any serial date 
        // under 60 is one off... Compensate.
        nSerialDate--;
    }

    return (int)nSerialDate;
}
/////////////////////////////////////////////////////
static int year_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported YearFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 1900;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return 100 * ( n - 49 ) + i + l;
}
/////////////////////////////////////////////////////
static int get_yr_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return YearFromDayNumber(atof(date));
	return year_from_day_number(atoi(date));

// date_format != "DSN"
// find where yr information start and ends
int yr_start_idx = 0;
int yr_end_idx = 0;
if (date_format == "USLIB")
	{
	yr_start_idx = 0; // yr information will always start at the beginning
	yr_end_idx = date.find_first_of("/");
	}
else // date_format == "US" 
	{
	yr_start_idx = date.find_last_of("/") + 1;
	yr_end_idx = date.length();
	}
int yr = atoi(date.substr(yr_start_idx, yr_end_idx));
return yr;
}
//////////////////////////////////////////////////
static int day_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported DayFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 29;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);
    
return l - int(( 2447 * j ) / 80);
}
/////////////////////////////////////////////////////
static int get_day_from_date(const xstring &date) 
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return DayFromDayNumber(atof(date));
	return day_from_day_number(atoi(date));

// date_format != "DSN"
// find where day information starts and ends
int day_start_idx = 0;
int day_end_idx = 0;
if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	day_end_idx = date.length(); // day always ends at the end
	if (day_start_idx == 5) // there is no day in the date, assume day is 1
		return 1;
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		return 1;
	}
int day = atoi(date.substr(day_start_idx, day_end_idx - day_start_idx));
// validate day entry
if (day < 1 || day > 31)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid day value (" + xstring(day) + ") in date.");
return day;
}
//////////////////////////////////////////////////
static int get_end_of_mth_day(int yr, int mth)
{
bool leap_yr = false;
int day = 31;

/*if ((mod(yr, 4) == 0 && mod(yr, 100) != 0)
	|| mod(yr, 400) == 0)
	leap_yr = true;	*/	

//WTW - Gen2 - use of RAFM specific function in START_HEADER
//20240822 ZL: Fixed the issue due to U.S. library Gen2 updates not handling leap year properly in rate->startup
if ((yr % 4 == 0 && yr % 100 != 0) 
	|| yr % 400 == 0)
	leap_yr = true;	

switch (mth)
	{
	case 2:
		if (leap_yr)
			day = 29;
		else
			day = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	default:
		day = 31;
	}

return day;
}
//////////////////////////////////////////////////
static xstring add_mths_to_date(const xstring &date, int mths)
{
// Check for format
xstring date_format = check_date_format(date);

// get date information
int mth = get_mth_from_date(date);
int yr = get_yr_from_date(date);

int addition_to_mth = 0;
int addition_to_yr = 0;
if (mths == 0)
	{
	addition_to_mth = 0;
	addition_to_yr = 0;
	}
else
	{
	addition_to_mth = (mths % 12);
	addition_to_yr = floor((mth + mths - 1) / 12.0);
	}

int new_mth = 0;
if (mth + addition_to_mth <= 0)
	new_mth = mth + addition_to_mth + 12;
else if (mth + addition_to_mth <= 12)
	new_mth = mth + addition_to_mth;
else
	new_mth = mth + addition_to_mth - 12;

int new_yr = (yr + addition_to_yr);

int day_start_idx = 0;
int day_end_idx = 0;
int day = 0;
xstring new_date = "";

if (date_format == "DSN")
	{
	day = get_day_from_date(date);
	new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
	}
else if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	if (day_start_idx == 5) // there is no day in the date, ignore
		new_date = xstring(new_yr) + "/" + xstring(new_mth);
	else
		{
		day = get_day_from_date(date);
		new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
		}
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		new_date = xstring(new_mth) + "/" + xstring(new_yr);
	else // DSN will always be here
		{
		day = get_day_from_date(date);
		new_date = xstring(new_mth) + "/" + xstring(day) + "/" + xstring(new_yr);
		}
	}
return new_date;
}
////////////////////////////////////
static int get_mth_from_adj_date(const xstring &date, int mths)
{
//Get month from a date, adjusted for mths
int mth = 0;
mth = get_mth_from_date(date);
mth = mth + mths;

if (mth <= 0)
	{
	if (mth <= -12)
		mth = mth % 12;

	mth += 12;
	}
else if (mth > 12)
	{
	mth = mth % 12;

	if (mth == 0)
		mth = 12;
	}

return mth;
}
////////////////////////////////////
static double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis) - 1.0;
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate, orig_rate_basis / new_rate_basis) - 1.0;//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
////////////////////////////////////
static double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis);
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate, orig_rate_basis / new_rate_basis);//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
static long int determine_tbl_size(int sNumberOfDims, ...)
{
//#define DIMT_MAX_DIMS 10
static constexpr int DIMT_MAX_DIMS = 10;//WTW - Gen2 - replace #define preprocessor statement
if (sNumberOfDims > DIMT_MAX_DIMS)
	throw FatalError("Multidimensional table too large. Cannot continue.");
int psIndecies[DIMT_MAX_DIMS] = {0};
int psMaxs[DIMT_MAX_DIMS] = {0};
int sLoop = 0;
long int sRetval = 0;
int sFactor = 1;
va_list vlArg_Ptr;
va_start(vlArg_Ptr, sNumberOfDims); // get first argument
for (sLoop = 0; sLoop < sNumberOfDims; sLoop++)
	psIndecies[sLoop] = va_arg(vlArg_Ptr, int); // get indexes
for (sLoop = 0; sLoop < sNumberOfDims ; sLoop++)
	psMaxs[sLoop]=va_arg(vlArg_Ptr, int); // get indexes
// loop backwards, for efficiency purposes, and to make the
// right-most index the "lowest" one.
for (sLoop = sNumberOfDims - 1; sLoop >= 0; sLoop--)
	{
	sRetval += (psIndecies[sLoop] - 1) * sFactor;
	if (sLoop > 0) // sFactor not needed last time through the loop
		sFactor *= psMaxs[sLoop];
	}
va_end(vlArg_Ptr);
return sRetval;
}
////////////////////////////////////
static xstring get_file_name(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\");
if (path_end < 0)
	throw FatalError("Unrecognized File name '" + id + "'.");
xstring name = id(path_end + 1);
int name_end = name.find(".");
if (name_end == 0)
	throw FatalError("'.' cannot be the first character of the file name '" + id + "'.");
if (name_end > 0)
	return name(0, name_end);
return name;
}
///////////////////////////////////////////////////
static xstring get_file_path(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\") + 1;
if (path_end > 0)
	return id(0, path_end);
throw FatalError("Unrecognized Data File name '" + id + "'.");
}
////////////////////////////////////////////////////////
static xstring get_base_group_name(const xstring &tag, bool seriatim_flag)
{
// must strip "ProjTaskLoop ### " from group because RAFM prepends this to user's group tag
xstring xxx = tag.strip();

int pos = 0;
if (xxx(0, 2) == "0 ")
	return xxx(2);
if (xxx(0, 13) == "ProjTaskLoop ")
	{
	xxx = xxx(13);
	if (pricing_flag || seriatim_flag)
		pos = xxx.find("|");  // RAFM uses ProjTaskLoop XXX|Group when product is top model
	else
		pos = xxx.find(" ");
	if (pos > 0)
		xxx = xxx(pos + 1);
	else
		xxx = tag;
	}
else if ((pos = xxx.find(" #")) > 0)
	xxx = xxx(0, pos);
return xxx;
}
////////////////////////////////////////////////////////
static xstring get_string_of_date(double date)
{
return xstring(get_yr_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_mth_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_day_from_date(xstring(date)));
}
////////////////////////////////////////////////////////
static xstring get_string_of_enum_val(int type)
{
xstring type_string = "";

switch (type)
	{
	#if defined(__ASSET_ASSET_H_)
	case BOND: type_string = "Bond"; break;
	case MORTGAGE: type_string = "Mortgage"; break;
	case SECURITIZED_ASSET: type_string = "Securitized Asset"; break;
	case INTEREST_RATE_DERIVATIVE: type_string = "Interest Rate Derivative"; break;
	case REAL_ESTATE: type_string = "Real Estate"; break;
	case EQUITY: type_string = "Equity"; break;
	case INDEX_OPTION: type_string = "Index Option"; break;

	case BOOK: type_string = "Book"; break;
	case CASH: type_string = "Cash"; break;

	case NO: type_string = "No"; break;
	case YES: type_string = "Yes"; break;

	#if defined(__BOND_ASSET_H_)
	case HEDGING: type_string = "Hedging"; break;
	case INVESTMENT: type_string = "Investment"; break;
	case COLLATERAL_POOL: type_string = "Collateral Pool"; break;

	case AMERICAN: type_string = "American"; break;
	case EUROPEAN: type_string = "European"; break;

	case ANNUAL: type_string = "Annual"; break;
	case MONTHLY: type_string = "Monthly"; break;
	case QUARTERLY: type_string = "Quarterly"; break;
	case SEMI_ANNUAL: type_string = "Semi-Annual"; break;

	case CALL: type_string = "Call"; break;
	case CASH_FLOW_MAINTENANCE: type_string = "Cash Flow Maintenance"; break;
	case YIELD_MAINTENANCE: type_string = "Yield Maintenance"; break;

	case FIXED_RATE: type_string = "Fixed Rate"; break;
	case FLOATING_RATE: type_string = "Floating Rate"; break;

	case NOT_APPLICABLE: type_string = "Not Applicable"; break;
	case NOT_ASSIGNED: type_string = "Not Assigned"; break;
	case HELD_TO_MATURITY: type_string = "Held to Maturity"; break;
	case AVAILABLE_FOR_SALE: type_string = "Available for Sale"; break;
	case TRADING: type_string = "Trading"; break;

	case PRICE_SCHEDULE: type_string = "Price Schedule"; break;
	#endif

	#if defined(__MTG_ASSET_H_)
	case PENALTY_PERCENT: type_string = "Penalty Percent"; break;
	case YES_PER_SCHEDULE: type_string = "Yes Per Schedule"; break;
	#endif

	#if defined(__SEC_ASSET_H_)
	case ACCRUAL_ONLY: type_string = "Accrual Only"; break;
	case AFTER_PAC2: type_string = "After PAC2"; break;
	case BEFORE_PAC2: type_string = "Before PAC2"; break;
	case BOTH: type_string = "Both"; break;
	case IO: type_string = "IO"; break;
	case JUMP: type_string = "Jump"; break;
	case JUMP_STICK: type_string = "Jump/Stick"; break;
	case NON_ACCRUAL: type_string = "Non Accrual"; break;
	case PAC2A: type_string = "PAC2A"; break;
	case PO: type_string = "PO"; break;
	case TRANCHE_A: type_string = "Tranche A"; break;
	case TRANCHE_B: type_string = "Tranche B"; break;
	case TRANCHE_C: type_string = "Tranche C"; break;
	case TRANCHE_Z: type_string = "Tranche Z"; break;
	case Z_PAC: type_string = "Z PAC"; break;
	#endif

	#if defined(__IRD_ASSET_H_)
	case ALWAYS: type_string = "Always"; break;
	case IF_POSITIVE: type_string = "If Positive"; break;
	#endif

	#if defined(__EIO_ASSET_H_)
	case PUT: type_string = "Put"; break;
	case FUTURES: type_string = "Futures"; break;

	case NONE: type_string = "None"; break;
	case ASIAN: type_string = "Asian"; break;
	case HIGHEST_GAIN: type_string = "Highest Gain"; break;

	case SEMIANNUAL: type_string = "Semiannual"; break;
	#endif

	#if defined(__EPA_ASSET_H_)
	case SCHEDULE_FILE: type_string = "Schedule File"; break;
	case TAS_EPA_FILE: type_string = "TAS EPA File"; break;
	#endif

	#endif

	default: type_string = "Unknown";
	}

return type_string;
}
////////////////////////////////////////////////////////
static int date_diff(xstring first_date, xstring second_date)
{
// Return difference in mths between first and second date
int first_yr = get_yr_from_date(first_date);
int second_yr = get_yr_from_date(second_date);
int first_mth = get_mth_from_date(first_date);
int second_mth = get_mth_from_date(second_date);

return (first_yr - second_yr) * 12 + first_mth - second_mth;
}
////////////////////////////////////////////////////////
//WTW - Gen2 - New external formula instead of preprocessing statement where #define is not allowed
static int number_of_decimals(double xxx, int digits) 
{
return (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))));
}
////////////////////////////////////////////////////////
static xstring write_string(double value, int string_length, int significant_digits)
{
// save value to at least 'significant_digits' significant digits.
//#define NUMBER_OF_DECIMALS(xxx,digits) (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))))
//int decimals = NUMBER_OF_DECIMALS(value, significant_digits);
int decimals = number_of_decimals(value, significant_digits);//WTW - Gen2 - replace preprocessor w formula
xstring string_value = "";
ostringstream message;
message.setf(ios::fixed);
message << setprecision(decimals) << value;
string_value = message.str();
if (string_value.length() <= string_length)
	return string_value;
// else output in scientific notation
if (string_length > 10)
	{
	ostringstream message2;
	message2.setf(ios_base::scientific, ios_base::floatfield);
	message2 << setprecision(string_length - 7) << value;
	string_value = message2.str();
	return string_value;
	}
// else output asterisks
ostringstream message2;
message2 << setw(string_length) << setfill('*') << "";
string_value = message2.str();
return string_value;
}
//////////////////////////////////////////////////////////////
// write_array_to_string - This functions takes an array and writes it to a string.
//static xstring write_array_to_string(SmartArray <double> value_array, int low, int high)
static xstring write_array_to_string(std::vector <double> value_array, int low, int high)//WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
xstring temp_string = "";
int j = 0;
for (j=low; j <= high ; j++)
{
	temp_string += xstring(value_array[j]) + "|";
}
return temp_string;
}
////////////////////////////////////////////////////////////
//static void read_from_string(xstring temp_string, SmartArray <double> &temp_array)
static void read_from_string(xstring temp_string, std::vector <double> &temp_array) //WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
int j = 0;
double new_entry = 0.0;
char* copyString = new char[ temp_string.length() + 1 ];
strcpy( copyString, temp_string.c_str() );				
char* fragment = strtok(copyString, "|");
while (fragment)
	{
	new_entry = atof(fragment);
	temp_array.push_back(new_entry);
	fragment = strtok(NULL, "|");
	}
}
/////////////////////////////////////
static void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters)//WTW - Gen2 - split_tring internal RAFM function
{
// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
while (string::npos != pos || string::npos != lastPos)
	{
	// Found a token, trim and add it to the vector.
	string new_string = str.substr(lastPos, pos - lastPos);
	
	string::size_type startpos = new_string.find_first_not_of(" \t");
	string::size_type endpos = new_string.find_last_not_of(" \t");
	// if all spaces or empty return an empty string
	if((string::npos == startpos ) || ( string::npos == endpos))
		new_string = "";
	else
		{
		new_string = new_string.substr(startpos, endpos - startpos + 1);
		tokens.push_back(new_string);
		}	
	// Skip delimiters.  Note the "not_of"
	lastPos = str.find_first_not_of(delimiters, pos);
	// Find next "non-delimiter"
	pos = str.find_first_of(delimiters, lastPos);
	}
}
static void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters, const string& dash)//WTW - Gen2 - split_tring internal RAFM function
{
//Perform comma search first and if dash is within commas add integers within range

// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
if (string::npos != pos || string::npos != lastPos)//If comma has been located
	{
	while (string::npos != pos || string::npos != lastPos)
		{
		// Found a token, trim and add it to the vector.
		string new_string = str.substr(lastPos, pos - lastPos);
	
		string::size_type startpos = new_string.find_first_not_of(" \t");
		string::size_type endpos = new_string.find_last_not_of(" \t");
		// if all spaces or empty return an empty string
		if((string::npos == startpos ) || ( string::npos == endpos))
			new_string = "";
		else
			{
			new_string = new_string.substr(startpos, endpos - startpos + 1);
		
			string::size_type found = new_string.find(dash);
		
			if (found != string::npos)//if dash is found, add values within range
				{
				xstring start = new_string.substr(0,found);
				xstring end = new_string.substr(found+1, new_string.size()-found-1);
				int start_range = atoi(start);
				int end_range = atoi(end);

				std::string push_value;

				for (int i = start_range; i <= end_range; i++)
					{
					push_value = std::to_string(i);
					tokens.push_back(push_value);
					}
				}
			else//otherwise add single value
				tokens.push_back(new_string);
			}	
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
		}
	}
else//No comma has been located
	{
	string::size_type found = str.find(dash);
		
	if (found != string::npos)//if dash is found, add values within range
		{
		xstring start = str.substr(0,found);
		xstring end = str.substr(found+1, str.size()-found-1);
		int start_range = atoi(start);
		int end_range = atoi(end);

		std::string push_value;

		for (int i = start_range; i <= end_range; i++)
			{
			push_value = std::to_string(i);
			tokens.push_back(push_value);
			}
		}	
	}
}

/////////////////////////////////////////////////
static void query_run_time(const xstring &caller, const xstring &file_name)
{
static LARGE_INTEGER QRTFreq;
static LARGE_INTEGER QRTStartTime;
static LARGE_INTEGER QRTRestartTime;
static LARGE_INTEGER QRTEndTime;
static ofstream& QRTFile = * new ofstream;
static bool first = true;
if (first)
	{
	first = false;
	xstring query_run_time_file_name
	= get_file_path(file_name) + get_file_name(file_name) + "~QueryRunTime.TXT";
	QRTFile.open(query_run_time_file_name);
	QueryPerformanceFrequency((LARGE_INTEGER *)&QRTFreq);
	QRTFile.setf(ios::fixed, ios::floatfield);
	QRTFile << "Query Run Time output for " << get_file_name(file_name)
			<< endl;
	QRTFile << "QRTime: -Increment ---Total-- - " << caller
			<< " Frequency: " << (float)(QRTFreq.QuadPart)
			<< endl;
	QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
	QRTStartTime = QRTRestartTime;
	return;
	}
QueryPerformanceCounter((LARGE_INTEGER *)&QRTEndTime);
QRTFile << "QRTime: " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTRestartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTStartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << caller
		<< endl;
QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
return;
}
/////////////////////////////////////////////////////
// financial functions
static double annual_yld(double monthly_numerator, double monthly_denominator, int return_frequency)
{
if (fabs(monthly_denominator) < 1.0e-02)
	return 0;
if (monthly_numerator == 0)
	return 0;
if (monthly_numerator > 0)
	{
	if (monthly_denominator > 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO > monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator < 0
		{
		if (monthly_numerator > MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
else // monthly_numerator < 0
	{
	if (monthly_denominator < 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO < monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator > 0
		{
		if (monthly_numerator < MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
return (pow_legacy(1.0 + (monthly_numerator / monthly_denominator),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
	   * return_frequency;
}
// V to the n
static double vtothen(double rate_per_period, int num_periods)
{
return pow_legacy((1.0 / (1.0 + rate_per_period)), (double) num_periods);//WTW - Gen2 - use of undeclared identifier
}
// a angle n
static double a_angle_n(double rate_per_period, int num_periods)
{
double temp_a_angle_n;
if (rate_per_period > 0.0)
	temp_a_angle_n = (1.0 - vtothen(rate_per_period, num_periods))
/ rate_per_period;
else
	temp_a_angle_n = (double) num_periods;
return temp_a_angle_n;
}
// Cumulative Normal Distribution
static double cumul_normal_distribn(double x)
{
//Comments:  This approximation for the cummualtive normal distribution is taken
//from formula 26.2.17, page 932, of the "Handbook of Mathematical Function",
//National Bureau of Standards, Applied Mathematics Series 55, U.S.  Government
//Printing Office, Washington, D.C., 1964.  This approximation is accurate to 7
//decimal places.
//This routine calculates the cummulative normal distribution, N(x), as follows:
//For x >= 0
//N(x) = 1 - exp( -(x^2)/2 ) * (a*t + b*t^2 + c*t^3 + d*t^4 + e*t^5) / 2.5066
//28274 63100
//where  t = 1 / (1 + p*x)
//p =  0.23164 19
//a =  0.31938 1530
//b = -0.35656 3782
//c =  1.78147 7937
//d = -1.82125 5978
//e =  1.33027 4429
//For x < 0
//N(x) = 1 - N(-x)

double p =  0.2316419;
double a =  0.319381530;
double b = -0.356563782;
double c =  1.781477937;
double d = -1.821255978;
double e =  1.330274429;
double t = 1.0 / (1.0 + p * fabs(x));
if (x >= 0)
	{
	if (((x * x) / 2.0) < 225)
		return 1.0 - exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	return 1.0;
	}
else
	{
	if (((x * x) / 2.0) < 225)
		return exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	}
return 0.0;
}
// Cumulative Bivariate Normal Distribution
static double cumul_bivariate_normal_distribn(double x, double y, double rho)
{
// This approximation for the cumulative bivariate normal distributions is
// described in appendix A, page 191, of Espen Haug's book titled "The
// Complete Guide To Option Pricing Formulas".
int i = 0;
int j = 0;
double x1 = 0.0;
double y1 = 0.0;
double rho1 = 0.0;
double rho2 = 0.0;
double delta = 0.0;
double pi = 0.0;
double signx = 0.0;
double signy = 0.0;
double cumulative_bivariate_normal_val = 0.0;
static double xx[5] = { 0.24840615, 0.39233107, 0.21141819, 0.03324666, 0.00082485334 };
static double yy[5] = { 0.10024215, 0.48281397, 1.0609498, 1.7797294, 2.6697604 };
x1 = x / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
y1 = y / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
pi = 3.14159265358979;
if (x < 0.0)
	signx = -1.0;
else if (x > 0.0)
	signx = 1.0;
else
	signx = 0.0;
if (y < 0.0)
	signy = -1.0;
else if (y > 0.0)
	signy = 1.0;
else
	signy = 0.0;
if (x <= 0 && y <= 0 && rho <= 0)
{
	double sum = 0.0;
	for (i = 0; i < 5; i++)
		{
		for (j = 0; j < 5; j = j + 1)
			{
			sum
			= sum
			  + xx[i] * xx[j]
			  * exp(x1 * (2 * yy[i] - x1)
					+ y1 * (2 * yy[j] - y1)
					+ 2 * rho * (yy[i] - x1) * (yy[j] - y1));
			}
		}
	cumulative_bivariate_normal_val = pow_legacy((1 - pow_legacy(rho, 2)), 0.5) / pi * sum;//WTW - Gen2 - use of undeclared identifier
	}
else
	{
	if (x <= 0 && y >= 0 && rho >= 0)
		cumulative_bivariate_normal_val
		= cumul_normal_distribn(x)
		  - cumul_bivariate_normal_distribn(x, -y, -rho);
	else
		{
		if (x >= 0 && y <= 0 && rho >= 0)
			cumulative_bivariate_normal_val
			= cumul_normal_distribn(y)
			  - cumul_bivariate_normal_distribn(-x, y, -rho);
		else
			{
			if (x >= 0 && y >= 0 && rho <= 0)
				cumulative_bivariate_normal_val
				= cumul_normal_distribn(x)
				  + cumul_normal_distribn(y) - 1
				  + cumul_bivariate_normal_distribn(-x, -y, rho);
			else
				{
				if (x * y * rho > 0)
					{
					rho1 = (rho * x - y) * signx
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					rho2 = (rho * y - x) * signy
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					delta = (1 - signx * signy) / 4.0;
					cumulative_bivariate_normal_val
					= cumul_bivariate_normal_distribn(x, 0, rho1)
					  + cumul_bivariate_normal_distribn(y, 0, rho2)
					  - delta;
					}
				}
			}
		}
	}
return cumulative_bivariate_normal_val;
}
// cte calc
//static void cte_calc(SmartArray <SmartArray <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio)
static void cte_calc(std::vector <std::vector <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio)//WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
int i = 0;
int j = 0;
int cte_index = 0;
double scen_amt_sum = 0.0;
double tax_avg_ratio_amt_sum = 0.0;
double scen_amt_temp_element = 0.0;
double tax_avg_ratio_temp_element = 0.0;
if (value_array[0].size() != value_array[1].size())
	{
	//WTW - Gen2 - log_screen not supported in Externs
	//log_screen.setf(ios::fixed, ios::floatfield);
	//log_screen << "Warning. The number of arrays for the scenario amount does not equal the number of arrays for the tax average ratio array."
	//			<< MSG_ERROR;
	}
if (value_array[0].size() == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
// first sort the array highest to lowest
for(i = 1; i < value_array[0].size(); i++)
	{
	for (j = i; j > 0; j--)
		{
	if (value_array[0][j] > value_array[0][j-1])
			{
			scen_amt_temp_element = value_array[0][j - 1]; // SCEN_AMT
			tax_avg_ratio_temp_element = value_array[1][j - 1]; // TAX_AVG_RATIO
			value_array[0][j - 1] = value_array[0][j];
			value_array[1][j - 1] = value_array[1][j];
			value_array[0][j] = scen_amt_temp_element;
			value_array[1][j] = tax_avg_ratio_temp_element;
			}
		}
	}
cte_index
= value_array[0].size() - ceil(cte_percentage * value_array[0].size());
if (cte_index == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
if (value_array[0].size() == 1 || cte_index == 1)
	{
	cte_amt = value_array[0][0];
	tax_avg_ratio = value_array[1][0];
	return;
	}
for (i = 0; i < cte_index; i++)
	{
	scen_amt_sum += value_array[0][i];
	tax_avg_ratio_amt_sum += value_array[1][i];
	}
cte_amt = scen_amt_sum / cte_index;
tax_avg_ratio = tax_avg_ratio_amt_sum / cte_index;
return;
}
// Black Scholes Highest Gain Frequency Multiple
static double bs_highest_gain_freq_mult(double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int tn = 0;
double ta = 0.0;
double freq = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double tm = 0.0;
double h = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double v2 = 0.0;
double tsqrt = 0.0;
double sqrt2pi = 0.0;
double mu = 0.0;
double mutsqrt = 0.0;
double delta = 0.0;
double gamma = 0.0;
double alpha = 0.0;
double lambda = 0.0;
double highest_gain_freq_factor = 0.0;
// length_of_sampling_period (ta)
// sampling_freq             (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
//  yrs_to_expiry            (tee)
//  risk_free_rate           (r)
//  init_div_yld             (b)
//  index_vol                (v)
//
ta = length_of_sampling_period;
freq = sampling_freq;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
{
b = 0.0000001;
// Temporary until we calculate the limit of M2
// as b approaches zero.
}
if (fabs(freq) < 0.000001)
highest_gain_freq_factor = 1.0;
else
{   // Discrete sampling.
tm = min(tee, ta);
h = 1.0 / freq;
tn = ((int) (ta * freq)) + 1;
b1 = 0.5826;
b2 = 0.425;
v2 = v * v;
tsqrt = pow_legacy(tm, 0.5);//WTW - Gen2 - use of undeclared identifier
sqrt2pi = 2.50662827463100; // square root of 2  * Pi
mu = r - v2 / 2;
mutsqrt = mu * tsqrt;
delta = mutsqrt * (cumul_normal_distribn(mutsqrt / v) - 0.5);
gamma = (v * exp(-mutsqrt * mutsqrt * 0.5 / v2) / sqrt2pi + delta) * 0.5;
alpha = (gamma * tsqrt + b2 * v2 * tm * 0.5) / tn;
volatile double exparg = b1 * v * (pow_legacy(h, 0.5));//WTW - Gen2 - use of undeclared identifier
lambda = exp(exparg) / exp(alpha);
highest_gain_freq_factor = lambda;
}
return highest_gain_freq_factor;
}
// Black Scholes Option Value
static double bs_opt_val(double strike_price, double yrs_to_expiry, double underlying_price, double vol, double risk_free_rate, double payout_rate, int call_or_put, int formula_code)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
//
// formula_code - CONTINUOUS_PAYOUT_CODE  for Continuous Payout (Merton's modification)
//                FUTURES_CODE            for Futures           (Black's modification)//
//
// Comments:  This approximation was taken from Table 3-6 ("European Option
// Valuation Formulas") on pages 117-118 of "Financial Options" by Figlewski,
// et. al., Business One Erwin, Homewood, Illinois.
//
// The major assumptions of the Black-Scholes option XModel are:  i) the
// asset price follows a geometric Brownian motion with constant variance
// v^2, ii) the asset returns follow a lognormal distribution, iii) there
// are no transaction costs or taxes, iv) securities are infinitely
// divisible and may be traded at all times, and v) there are no
// restrictions on short selling.  Under these assumptions the European
// option prices on an asset with discrete cash payouts are
//
//   Call Price =  S * N[ d1] * exp( -q * T ) - X * N[ d2] * exp( -r * T )
//   Put Price  = -S * N[-d1] * exp( -q * T ) + X * N[-d2] * exp( -r * T )
//
// where S = price of underlying asset minus present value of all cash paid
//           out prior to expiration
//           (For a bond the price of the bond and the present value of the
//            cash paid out is based on the Treasury spot curve plus a credit
//            spread and is calculated under the assumption that the bond is
//            neither callable nor putable.)
//        X     = option exercise price
//                 (For a bond this is the call or put amount plus accurued
//                  interest at time T.)
//        T     = time to option expiry
//        r     = riskless continuously conpounded yield to option expiry
//        q     = continuously conpounded payout rate
//        v     = annual price volatility
//        d1    = [ ln( S/X ) + ( r - q + (v^2) / 2 ) * T ] / [ v * ( T^.5 ) ]
//        d2    = d1 - [ v * ( T^.5 ) ]
//        N[.]  = cumulative normal distribution function
double d1 = 0;
double d2 = 0;
double opt_price = 0;
double continuous_risk_free_rate = 0;
double continuous_payout_rate = 0;
double d1_divisor = 0;
if (formula_code == CONTINUOUS_PAYOUT_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		continuous_risk_free_rate = 2.0 * log(1.0 + risk_free_rate / 2.0);
		continuous_payout_rate = log(1.0 + payout_rate);
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		if (fabs(d1_divisor) <  1.0e-10)//WTW - Gen2 - avoid divide by 0
			d1 = 0.0;
		else
			d1 = (log(underlying_price / strike_price)
				  + (continuous_risk_free_rate - continuous_payout_rate
				  + (vol * vol) / 2.0)
					* yrs_to_expiry) / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * cumul_normal_distribn(d1)
			  * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			  - strike_price
			    * cumul_normal_distribn(d2)
			    * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= -underlying_price
			   * cumul_normal_distribn(-d1)
			   * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			   + strike_price
			     * cumul_normal_distribn(-d2)
			     * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
if (formula_code == FUTURES_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		if (fabs(d1_divisor) < 1.0e-10)//WTW - Gen2 - avoid divide by 0
			d1 = 0.0;
		else
			d1 = (log(underlying_price / strike_price)
				  + ((vol * vol) / 2.0) * yrs_to_expiry)
				  / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= (underlying_price
			   * cumul_normal_distribn(d1)
			   - strike_price
			     * cumul_normal_distribn(d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= (-underlying_price
			   * cumul_normal_distribn(-d1)
			   + strike_price
				 * cumul_normal_distribn(-d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
return opt_price;
}
// Black Scholes Option Value Asian
static double bs_opt_val_asian(int call_or_put, double current_price, double observed_average_price, double strike_price, double length_of_averaging_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int freq = 0;
int tn = 0;
int pn = 0;
int fn = 0;
double s = 0.0;
double savg = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double fr = 0.0;
double pr = 0.0;
double tr = 0.0;
double m1 = 0.0;
double b2v = 0.0;
double m2 = 0.0;
double h = 0.0;
double bv = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double f3 = 0.0;
double f4 = 0.0;
double f5 = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double b3 = 0.0;
double b4 = 0.0;
double var = 0.0;
double vavg = 0.0;
double xp = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double callprice = 0.0;
double asian_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price                    (s)
// observed_average_price           (savg)
// strike_price                     (x)
// length_of_averaging_period       (ta)
// sampling_freq                    (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry                    (t)
// risk_free_rate                   (r)
// init_div_yld                     (d)
// index_vol                        (v)
//
// Description.  This formula set assumes that the Asian values are based
//   on sample points at the beginnings and ends of sample months.  To
//   sample ends of months, execute this formula set with the length of the
//   averaging period reduced by one sample period.  The reduction does not
//   apply to continuous sampling.
// This is a modification by Phelim Boyle of the approximation
// that appears on in Levy's paper on "Pricing European average
// rate currency options", Journal of International Money and
// Finance (1992), 11, 474-491.
//
// The Phelim's modification consists of eliminating the formulas
// for the case where we are within the averaging period by
// using the formulas for the case before we enter the averaging
// period to value a similar option on an average over the
// future averaging points.  This modifications greatly
// simplifies the calculations without any loss of accuracy.
//
// Phelim also considers the case where the option pays with
// certainty.
//
// If b is zero, b is reset to 0.00001 because we have not been
// able to determine the limit of the second moment (M2) of the
// average distribution as b tends toward zero.
// Initialize variables.
s = current_price;
savg = observed_average_price;
x = strike_price;
ta = length_of_averaging_period;
freq = sampling_freq;
tee = yrs_to_expiry;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
v = index_vol;
// Calculate first and second moments of average distribution
// and fractional parts of sampling period.
//
//   |<----------Ta-------------------------------------->|
//                       |<----------Fn*h---------------->|
//                           |<----------tee------------->|
//   |-------------------|---:--|-------------------------|
//   0                   m   t m+1                        N
//   0                   5      6                        10
//
// b     = cost of carry (= r - d)
// m1    = first moment of average distribution
// m2    = second moment of average distribution
// h     = time between sampling points         (discrete case only)
// fn    = number of future sampling points     (discrete case only)
// pn    = number of observed sampling points   (discrete case only)
// tn    = Total number of sampling points      (discrete case only)
// fr    = portion of average period remaining
// pr    = portion of average period already observed
// tr    = length of average period remaining
b = r - d; // cost of carry
if (b == 0)
	{
	b = 0.0001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (freq == 0)
	{   //Continuous sampling.
	if (tee > ta)
		fr = 1.0;
	else
		fr = tee / ta;
	pr = 1.0 - fr;
	tr = min(ta, tee);
	m1 = (s / tr) * exp(b * (tee - tr))
		 * (exp(b * tr) - 1.0) / b;
	b2v = 2.0 * b + v * v;
	m2 = 2.0 * (pow_legacy((s / tr), 2.0) / (b + v * v))//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - tr))
		 * ((exp(b2v * tr) - 1.0) / b2v - (exp(b * tr) - 1.0) / b);
	}
else
	{   // Discrete sampling.
	h = 1.0 / freq;
	tn = ((int) (freq * ta)) + 1;
	if (tee <= ta)
		pn = ((int) (freq * (ta - tee))) + 1;
	else
		pn = 0;
	fn = tn - pn;
	fr = fn / ((double) tn);
	pr = 1.0 - fr;
	// Calculate first moment.
	m1 = (s / fn) * exp(b * (tee - (fn - 1) * h))
		 * (exp(b * fn * h) - 1.0)
		 / (exp(b * h) - 1.0);
	//Calculate second moment.
	bv = b + v * v;
	b2v = b + bv;
	f1 = exp(b2v * fn * h);
	f2 = exp(b * h);
	f3 = exp(b2v * h);
	f4 = exp(b * fn * h);
	f5 = exp(bv * h);
	b1 = (1.0 - f1) / ((1.0 - f2) * (1.0 - f3));
	b2 = (f4 - f1) / ((1.0 - f2) * (1.0 - f5));
	b3 = (f2 - f4) / ((1.0 - f2) * (1.0 - f5));
	b4 = (f3 - f1) / ((1.0 - f5) * (1.0 - f3));
	m2 = pow_legacy((s / fn), 2.0)//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - (fn - 1) * h))
		 * (b1 - b2 + b3 - b4);
	}
var = log(m2) - 2.0 * log(m1);
vavg = pow_legacy((max(var, 0.0)), 0.5);//WTW - Gen2 - use of undeclared identifier
// Calculate call option price.
// xp = strike price adjusted to value average over unsampled points
xp = (x - pr * savg) / fr;
if (xp > 0)
	{
	d1 = (0.5 * log(m2) - log(xp)) / vavg;
	d2 = d1 - vavg;
	callprice = exp(-r * tee)
				* (m1 * cumul_normal_distribn(d1)
				  - xp * cumul_normal_distribn(d2)) * fr;
	if (call_or_put == CALL_CODE)
		asian_opt_val = callprice;
	else
		asian_opt_val = callprice - (m1 - xp) * exp(-r * tee) * fr;
	}
else
	{   // the option pays with certainty
	if (call_or_put == CALL_CODE)
		asian_opt_val = exp(-r * tee) * (fr * m1 + pr * savg - x);
	else
		asian_opt_val = 0.0;
	}
return asian_opt_val;
}
// Black Scholes Option Value Levy Asian
static double bs_opt_val_levy_asian(double strike_price, double yrs_to_expiry, double underlying_price, double average_price, double vol, double risk_free_rate, double payout_rate)
{
double tte = 0.0;
double K = 0.0;
double S = 0.0;
double rf = 0.0;
double q = 0.0;
double sigma = 0.0;
double Average = 0.0;
double levy_asian = 0.0;
double SE = 0.0;
double SV = 0.0;
double XStar = 0.0;
double m = 0.0;
double d = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double TERM = 1;
// Initialize variables.
tte = yrs_to_expiry;
K = strike_price;
S = underlying_price;
rf = risk_free_rate;
q = payout_rate;
sigma = vol;
Average = average_price;

if (tte <= 0.0)
	levy_asian =  max(0.0, Average - K);
SE = S / (TERM * (rf - q)) * (exp(((rf - q) - rf) * tte) - exp(-rf * tte));
m = 2.0 * pow_legacy(S,2.0) / ((rf - q) + pow_legacy(sigma,2.0)) * ((exp((2.0 * (rf - q) + pow_legacy(sigma,2.0)) * tte) - 1.0) /
	(2.0 * (rf - q) + pow_legacy(sigma,2.0)) - (exp((rf - q) * tte) - 1.0) / (rf - q));//WTW - Gen2 - use of undeclared identifier
d = m / pow_legacy(TERM,2.0);	//WTW - Gen2 - use of undeclared identifier
SV = log(d) - 2.0 * (rf * tte + log(SE));
if (SV < 0.0)
	levy_asian = max(0.0, Average - K);
else if (K < (TERM - tte) / TERM * Average)
	levy_asian = Average - K;
else 
{
	XStar = K - (TERM - tte) / TERM * Average;
	d1 = 1.0 / pow_legacy(SV,0.5) * (log(d) / 2.0 - log(XStar));//WTW - Gen2 - use of undeclared identifier
	d2 = d1 - pow_legacy(SV,0.5);//WTW - Gen2 - use of undeclared identifier
	
	levy_asian = SE * cumul_normal_distribn(d1) - XStar * exp(-rf * tte) * cumul_normal_distribn(d2);
}
return levy_asian;
}
// Black Scholes Option Value Continuous Highest Gain
static double bs_opt_val_continuous_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
double s = 0.0;
double smax = 0.0;
double smin = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double mx = 0.0;
double e1 = 0.0;
double e2 = 0.0;
double t1 = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double highest_gain_continuous_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)      for call
// observed_min               (smin)      for put
// strike_price               (x)
// length_of_sampling_period  (ta)
// yrs_to_expiry              (t)
// yrs_to_expiry              (r)
// init_div_yld               (b)
// index_vol                  (v)
s = current_price;
smax = observed_max;
smin = observed_min;
x = strike_price;
ta = length_of_sampling_period;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
	* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
	* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
	{
	b = 0.0000001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (tee <= ta)
	{   // within sampling period
	if (call_or_put == CALL_CODE)
		mx = max(smax, x);
else
		mx = min(smin, x);
	e1 = (log(s / mx) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(tee, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
= exp(-r * tee)
			  * (mx - x)
			  + s * exp((b - r) * tee)
				  * cumul_normal_distribn(e1)
			  - mx * exp(-r * tee)
				  * cumul_normal_distribn(e2)
			  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2.0 * b))
				  * (-pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
				  * cumul_normal_distribn(e1 - 2 * b / v * pow_legacy(tee, 0.5))
			  + exp(b * tee)
				  * cumul_normal_distribn(e1));//WTW - Gen2 - use of undeclared identifier
	else
		highest_gain_continuous_opt_val
		= exp(-r * tee)
		  * (x - mx)
		  - s * exp((b - r) * tee)
			   * cumul_normal_distribn(-e1)
		  + mx * exp(-r * tee)
			   * cumul_normal_distribn(-e1 + v * pow_legacy(tee, 0.5))
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
			  * cumul_normal_distribn(-e1 + 2 * b / v * pow_legacy(tee,0.5))
		  - exp(b * tee)
			* cumul_normal_distribn(-e1));//WTW - Gen2 - use of undeclared identifier
}
else
{
// before sampling period
//
//  |<--------------tee---------------------------------->|
//  |<------t1-------->|<---------Ta--------------------->|
//  |------------------|----------------------------------|
//
	t1 = tee - ta;
	d1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));
	d2 = d1 - v * pow_legacy(tee, 0.5);
	e1 = ((b + pow_legacy(v, 2) / 2.0) * ta) / (v * pow_legacy(ta, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(ta, 0.5);
	f1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * t1) / (v * pow_legacy(t1, 0.5));//WTW - Gen2 - use of undeclared identifier
	f2 = f1 - v * pow_legacy(t1, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
		= s * exp((b - r) * tee)
		    * cumul_normal_distribn(d1)
		  - exp(-r * tee) * x
		    * cumul_normal_distribn(d2)
		  + s * exp(-r * tee) * (pow_legacy(v,2) / (2 * b))
		      * (-pow_legacy((s / x), (-2 * b / pow_legacy(v,2)))
		      * cumul_bivariate_normal_distribn(d1 - 2 * b * pow_legacy(tee, 0.5) / v,
							-f1 + 2 * b * pow_legacy(t1, 0.5) / v,
							-pow_legacy((t1 / tee), 0.5))
		  + exp(b * tee)
			* cumul_bivariate_normal_distribn(e1, d1, pow_legacy((1 - t1 / tee), 0.5)))
		  - s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(-e1, d1, -pow_legacy((1 - t1 / tee), 0.5))
		  - x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(f2, -d2, -pow_legacy((t1 / tee), 0.5))
		  + exp(-b * (ta)) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(f1)
			* cumul_normal_distribn(-e2);//WTW - Gen2 - use of undeclared identifier
else // "Put"
		highest_gain_continuous_opt_val
		= x * exp(-r * tee)
			* cumul_normal_distribn(-d2)
		  - s * exp((b - r) * tee)
			  * cumul_normal_distribn(-d1)
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / x), (-2 * b / pow_legacy(v, 2)))
			  * cumul_bivariate_normal_distribn(-d1 + 2 * b * pow_legacy(tee, 0.5) / v,
						f1 - 2 * b * pow_legacy(t1, 0.5) / v,
						-pow_legacy((t1 / tee), 0.5))
		  - exp(b * tee)
			* cumul_bivariate_normal_distribn(-e1, -d1, pow_legacy((1 - t1 / tee), 0.5)))
		  + s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(e1, -d1, -pow_legacy((1 - t1 / tee), 0.5))
		  + x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(-f2, d2, -pow_legacy((t1 / tee), 0.5))
		  - exp(-b * ta) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(-f1)
			* cumul_normal_distribn(e2);//WTW - Gen2 - use of undeclared identifier
}
return highest_gain_continuous_opt_val;
}
// Black Scholes Option Value Highest Gain
static double bs_opt_val_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)
// observed_min               (smin)
// strike_price               (x)
// length_of_sampling_period  (ta)
// sampling_freq              (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry              (t)
// risk_free_rate             (r)
// init_div_yld               (b)
// index_vol                  (v)
//
// Description.  This formula set assumes that the high watermark values
//   are based on sample points at the beginnings and ends of sample
//   months.  To sample ends of months, execute this formula set with the
//   length of the sampling period reduced by one sample period.  The
//   reduction does not apply to continuous sampling.
double highest_gain_opt_val = 0.0;
if (sampling_freq == 0) // "Continuous"
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				observed_max,
				observed_min,
				strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
else // discrete sampling
	{
	double adjustment_factor
	= bs_highest_gain_freq_mult(length_of_sampling_period,
				sampling_freq,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
	double adj_max = observed_max * adjustment_factor;
	double adj_min = observed_min * adjustment_factor;
	double adj_strike_price = strike_price * adjustment_factor;
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				adj_max,
				adj_min,
				adj_strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq)
		/ adjustment_factor;
	}
return highest_gain_opt_val;
}
// Black Scholes Option Value Monthly Sum Cap
static double bs_opt_val_mthly_sum_cap(int crediting_mths, int known_index_vals, double sum_capped_amts,  double mthly_cap_rate, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int n = 0.0;
int mo = 0.0;
int n_rem = 0.0;
double I = 0.0;
double D = 0.0;
double sigma = 0.0;
double m = 0.0;
double X = 0.0;
double mu = 0.0;
double p = 0.0;
double d = 0.0;
double M = 0.0;
double V = 0.0;
double sqrtV = 0.0;
double Evy = 0.0;
double Evy2 = 0.0;
double EvM = 0.0;
double VarM = 0.0;
double c1 = 0.0;
double c2 = 0.0;
double a = 0.0;
double b = 0.0;
double mthly_sum_cap_opt_val = 0.0;

n = crediting_mths;
mo = known_index_vals;
n_rem = n - mo;

I = log(1.0 + risk_free_rate / scen_int_freq)
    * scen_int_freq;
D = log(1.0 + init_div_yld / scen_index_freq)
    * scen_index_freq;
sigma = index_vol;
m = mthly_cap_rate;
mu = I - D;

M = (mu - (sigma * sigma) / 2.0) / 12.0;
X = (1.0 + m);
V = (sigma * sigma) / 12.0;
sqrtV = pow_legacy(V, 0.5);//WTW - Gen2 - use of undeclared identifier

p = cumul_normal_distribn(pow_legacy(12.0, 0.5) / sigma * (log(X) - M));//WTW - Gen2 - use of undeclared identifier

d = (M + V - log(X)) / sqrtV;

Evy = exp(M + V / 2.0) * cumul_normal_distribn(-d) 
       - X * cumul_normal_distribn(-d + sqrtV);  

Evy2 = exp(2 * M + 2 * V) * cumul_normal_distribn(-d - sqrtV)
       - 2 * X * exp(M + V / 2.0) * cumul_normal_distribn(-d)
	   + X * X * cumul_normal_distribn(-d + sqrtV); 

EvM = m + Evy; 
VarM = Evy2 - pow_legacy(Evy, 2.0);//WTW - Gen2 - use of undeclared identifier

c1 = (EvM - m * (1.0 - p)) / p;
c2 = (VarM  + EvM * EvM - m * m * (1.0 - p)) / p;

a = pow_legacy(12.0 * (c2 - (c1 * c1)), 0.5);//WTW - Gen2 - use of undeclared identifier
b = c1 - a / 2.0;

if (n_rem == 0)
	return sum_capped_amts;

double sum = 0.0;
for (int k = 0; k <= n_rem; k++)
	{
	double sumi = 0.0;
	for (int v = 0; v <= k; v++)
		{
		double vali1 = pow_legacy(-1, k - v);//WTW - Gen2 - use of undeclared identifier
		double vali2 = n_choose_k(k, v);
		double vali3 = pow_legacy(max(v * a + k * b + (n_rem - k) * m + sum_capped_amts, 0.0), k + 1);	//WTW - Gen2 - use of undeclared identifier		
		double vali = vali1 * vali2 * vali3;
		sumi += vali;
		}
	
	double valo1 = n_choose_k(n_rem, k);
	double valo2 = pow_legacy(p, k) * pow_legacy(1.0 - p, n_rem - k);//WTW - Gen2 - use of undeclared identifier
	double valo3 = pow_legacy(a, k) * factorial(k + 1);//WTW - Gen2 - use of undeclared identifier
	double valo = (valo1 * valo2) / valo3;
	sum += sumi * valo;
	}

mthly_sum_cap_opt_val 
= sum * exp(- I * yrs_to_expiry);

return mthly_sum_cap_opt_val;
}

#endif // END_HEADER

#if 0 // START_CLASS
Economy* Econ;
EconomyData* EconData;
GenerationData* GenData;
CalibrationData* CalibData;
//EconErrorCodeType econ_err_code;
int econ_err_code;//WTW - Gen2 - user defined enum 
vector <xstring> country_list;
vector <xstring> currency_list;
vector <xstring> yld_curve_list;
vector <xstring> index_list;
vector <xstring> misc_list;
vector <xstring> correl_list;
vector <string> econ_data_yld_curve_list;
vector <string> econ_data_yld_curve_term_list;
vector <string> econ_data_yld_curve_vol_mr_term_list;
vector <string> econ_data_index_rate_list;
vector <string> econ_data_index_rate_tenor_list;
vector <string> econ_data_index_rate_moneyness_list;
vector <string> econ_data_misc_rates_list;
vector <string> calib_yld_curve_list;
vector <string> calib_data_swap_maturity_list;
vector <string> calib_data_swap_tenor_list;
vector <string> calib_data_bond_term_list;
vector <string> calib_index_rate_list;
vector <string> calib_data_index_moneyness_list;
vector <string> calib_data_index_term_list;
multimap <xstring, double> yld_curve_vol_surface_list;
multimap <xstring, double> index_vol_surface_list;
multimap <xstring, double>::iterator iter;
pair<multimap<xstring, double>::iterator, multimap<xstring, double>::iterator> range_pair;
map <xstring, double> spot_rates;
map <xstring, double> spot_rates_shifted;
map <xstring, double> yld_rates;
map <xstring, double> yld_rates_shifted;
map <xstring, double> int_vols;
map <xstring, double> index_rates;
map <xstring, double> index_vols;
map <xstring, double> index_vols_shifted;
map <xstring, double> fx_rates;
map <xstring, double> dflt_rates;
map <xstring, double> infl_rates;
map <xstring, double> misc_rates;
map <xstring, double> yld_rates_shifts;
map <xstring, double> index_val_shifts;
map <xstring, double> index_vols_shifts;
vector <xstring> shock_gen_list;
vector <xstring> hedge_valn_shock_list;
xstring hedge_valn_shock_id_prev;

vector <double> swap_curve_tenors_aig;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
Econ = NULL;
EconData = NULL;
GenData = NULL;
CalibData = NULL;
hedge_valn_shock_id_prev = "Undefined";
#endif // END_CONSTRUCTOR

#if 0 // START_DESTRUCTOR
if (Econ != NULL)
    {
    Economy::Release(Econ);
    Econ = NULL;
    }

if (EconData != NULL)
    {
    EconomyData::Release(EconData);
    EconData = NULL;
    }

if (GenData != NULL)
    {
    GenerationData::Release(GenData);
    GenData = NULL;
    }

if (CalibData != NULL)
    {
    CalibrationData::Release(CalibData);
    CalibData = NULL;
    }

#endif // END_DESTRUCTOR

if (isMainModel 
	&& !(target_column.find("generate")< string::npos))
	throw FatalError("Target column must be set equal to 'generate' when rates/economy is the top model.");

static bool first_time = true;
static bool load_scen_file = true;

// Allow for resetting and reloading of Econ object and scenario file when generation is running multiple projection taks loops
if (target_column.find("generate") < string::npos)
	{
	first_time = true;
	load_scen_file = true;
	}

// For hedging shock runs, need to determine if scenario file needs to be loaded based on hedge_valn_shock_list item being run
if (hedge_valn_shock_flag) 
	{
	xstring hedge_valn_shock_id_full = hedge_valn_shock_list[proj_task_loop_num - 1];
	xstring hedge_valn_shock_id = hedge_valn_shock_id_full(0, hedge_valn_shock_id_full.find("|TaskLoopIncr"));

	if (!eq(hedge_valn_shock_id, hedge_valn_shock_id_prev))
		load_scen_file = true;
	else
		load_scen_file = false;

	hedge_valn_shock_id_prev = hedge_valn_shock_id;

	// Do not load scenarios if shock is not being run
	if (time_step_flag && valn_period > 0)
		{
		// set lookup key
		shock_id = hedge_valn_shock_id;
		if ((valn_period % shock_freq) != 0)
			return 1;
		}
	}

if (first_time || load_scen_file || restore_variables_ind)
	{
	if (isMainModel)
		stoch_flag = true;

	if (isMainModel && overall_num_of_proj_set_sub_loops > 0
		&& time_step_defn == YES) // 20190208 WTW - Automation enhancement
		{
		time_step_flag = true;
		
		split_string_usl(valn_periods_selected.c_str(), valn_periods, ",", "-");//WTW - Gen2 - split_tring internal RAFM function
		
		if (valn_periods.size() < overall_num_of_proj_set_sub_loops)
			throw FatalError("Inner loop valuation period must be defined for each projection set sub loop.");
		
		valn_period = atoi(xstring(valn_periods[proj_set_sub_loop_num - 1]));
		}

	if (first_time && stoch_flag)
		{
		Econ = Economy::Create();
	
		YieldCurveTreatmentType yc_treat_type;
		MissingValType miss_val_type;
		ValuationScenType valn_scen_type;
			
		if (missing_val_defn == PREVIOUS)
			miss_val_type = MissingValType::Previous;
		else	
			miss_val_type = MissingValType::Interpolate;
	
		if (inner_loop_valn_scen_reuse_defn == ALL_RATES)
			valn_scen_type = ValuationScenType::AllRates;
		else if (inner_loop_valn_scen_reuse_defn == INDEX_RATES_ONLY)
			valn_scen_type = ValuationScenType::IndexRatesOnly;
		else
			valn_scen_type = ValuationScenType::NoRatesReused;

		if (yld_curve_mem_defn == RELEASE)
			yc_treat_type = YieldCurveTreatmentType::ReleaseFromMemory;
		else
			yc_treat_type = YieldCurveTreatmentType::KeepInMemory;	

		xstring force_scalar_calc_date = proj_date_adj;	
	
		Econ->set_YCTreatmentType(yc_treat_type);
		Econ->set_MissValType(miss_val_type);
		Econ->set_ValnScenType(valn_scen_type);
		Econ->set_DateTreatmentType(DateTreatmentType::Relative);
		Econ->set_EconFilesRetryAttempts(open_file_retry_attempts);
		Econ->set_ValnPeriod(valn_period); //VC++ 2017 Econ DLL

		if ((valn_flag && !hedge_valn_final_flag) && valn_period > 0)
			{
			int proj_yr = get_yr_from_date(proj_date_adj);
			int proj_mth = get_mth_from_date(proj_date_adj);

			Econ->set_ProjYear(proj_yr);
			Econ->set_ProjMonth(proj_mth);

			if (xstring(proj_date_adj).length() > 7) // date field contains a day
				Econ->set_ProjDay(get_day_from_date(proj_date_adj));
			else
				Econ->set_ProjDay(get_end_of_mth_day(proj_yr, proj_mth));
			}
		else // for outer loop and generate, pass Economy the unadjusted proj_date
			{
			int proj_yr = get_yr_from_date(proj_date);
			int proj_mth = get_mth_from_date(proj_date);

			Econ->set_ProjYear(proj_yr);
			Econ->set_ProjMonth(proj_mth);

			if (proj_date.length() > 7) // date field contains a day
				Econ->set_ProjDay(get_day_from_date(proj_date));
			else
				Econ->set_ProjDay(get_end_of_mth_day(proj_yr, proj_mth));
			}
		}

	if (load_scen_file && stoch_flag)
		scen_set_info_load();
		
	first_time = false;
	load_scen_file = false;
	}

/*****************************************************************************/
swap_curve_tenors_aig.clear();

vector <string> swap_curve_tenors_str;
split_string_usl(swap_curve_tenors_input_aig.c_str(), swap_curve_tenors_str, ",");//WTW - Gen2 - split_tring internal RAFM function

// Check swap curve tenors
if (swap_curve_tenors_str.size() <= 1)
{
	throw FatalError("Not enough tenors selected for swap_curve_tenors_aig!");
}

// Convert swap curve tenors to double
for (int i = 0; i < swap_curve_tenors_str.size(); i++)
{
	swap_curve_tenors_aig.push_back(stod(swap_curve_tenors_str[i]));
}
/*****************************************************************************/
//WTW - Gen2 - Move from initialize()
if (!stoch_flag)
	return 0.0;

if (hedge_valn_flag)
	{
	// Determine the initial scenario to load for hedge valuation
	// Scenarios will be reloaded using a call to scen_rate_load from the hedging valuation process
	// per the start scenario for the model point and the task loop increment
	if (hedge_valn_final_flag)
		scen_rates_load(proj_task_loop_num);
	else 
		{
		xstring hedge_valn_shock_id_full = hedge_valn_shock_list[proj_task_loop_num - 1];
		xstring hedge_valn_shock_id = hedge_valn_shock_id_full(0, hedge_valn_shock_id_full.find("|TaskLoopIncr"));

		// Do not load scenario rates if shock is not being run
		if (time_step_flag && valn_period > 0)
			{
			// set lookup key
			shock_id = hedge_valn_shock_id;
			if ((valn_period % shock_freq) != 0)
				return 1;
			}

		// The task loop starts at the position after the last dash "-" of the hedge_valn_shock_id
		int task_loop_start_pos = hedge_valn_shock_id_full.find_last_of("-");
		int hedge_task_loop_num = atoi(hedge_valn_shock_id_full(task_loop_start_pos + 1));

		scen_rates_load(hedge_task_loop_num);
		}
	}
else if (!time_step_flag)
	{
	// if generating outside of a nested projection, always load scenario 1 to get initial rates
	if (target_column.find("generate") < string::npos) 
		scen_rates_load(1);
	else
		scen_rates_load(proj_task_loop_num);
	}
else if (valn_flag && !isMainModel)
	scen_rates_load(proj_task_loop_num);
else
	scen_rates_load(proj_set_loop_num);


return 0.0;

}


//@@ END

//@@ START - ten_year_treasury_annualized_return_cumul_max_aig
// Maximum 10-year treasury rate to date:                                                                                             
// Column:TEN_YEAR_TREASURY_ANNUALIZED_RETURN_CUMUL_MAX_AIG
//========================================================
double RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_cumul_max_aig(int t) {
//^^^



//^^^

#line 1 "ten_year_treasury_annualized_return_cumul_max_aig.RATES_ECONOMY.for"
// 20200515 DTL
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}

double ten_year_treasury_annualized_return_cumul_max_cv;
if (t == 0)
{
	ten_year_treasury_annualized_return_cumul_max_cv = ten_year_treasury_annualized_return_max_aig(t);
}
else
{
	double ten_year_treasury_annualized_return_cumul_max_prev = ten_year_treasury_annualized_return_cumul_max_aig(t - 1);
	double ten_year_treasury_annualized_return_max_cv		  = ten_year_treasury_annualized_return_max_aig(t);
	ten_year_treasury_annualized_return_cumul_max_cv		  = max(ten_year_treasury_annualized_return_max_cv, ten_year_treasury_annualized_return_cumul_max_prev);
}

return ten_year_treasury_annualized_return_cumul_max_cv;

}


//@@ END

//@@ START - ten_year_treasury_annualized_return_max_aig
// Ten year treasury return monthly maximum:                                                                                             
// Column:TEN_YEAR_TREASURY_ANNUALIZED_RETURN_MAX_AIG
//========================================================
double RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_max_aig(int t) {
//^^^



//^^^

#line 1 "ten_year_treasury_annualized_return_max_aig.RATES_ECONOMY.for"
// 20200515 DTL
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}

const int TREASURY_RATE_TENOR = 10;
if (t == 0)
{
	//WTW - Gen2 - "Govt" does not exist on scenario file, so code does alot of extra work to create it
	//Update code to skip calls if "Govt" doesn't exist
	double current_rate = 0.0;
	
	if (find(yld_curve_list.begin(), yld_curve_list.end(), "Govt") != yld_curve_list.end())
		current_rate = get_int_rate(t, "Govt", GET_YIELD_RATE, TREASURY_RATE_TENOR, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	 
	return current_rate;
}
//WTW - Gen2 - "Govt" does not exist on scenario file, so code does alot of extra work to create it
//Update code to skip calls if "Govt" doesn't exist
double yld_rate_prior = 0.0;
double yld_rate_curr = 0.0;

if (find(yld_curve_list.begin(), yld_curve_list.end(), "Govt") != yld_curve_list.end())
	{
	yld_rate_prior = get_int_rate(t - 1, "Govt", GET_YIELD_RATE, TREASURY_RATE_TENOR, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	yld_rate_curr  = get_int_rate(t, "Govt", GET_YIELD_RATE, TREASURY_RATE_TENOR, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	}

double annual_vol	  = get_misc_rate(t, "Govt_120_Vol", EFFECTIVE_ANNUAL);
double u			  = get_misc_rate(t, "Uniform_RV_01", EFFECTIVE_ANNUAL);
double yld_rate_hwm	  = brownian_bridge_max_calc_normal_aig(yld_rate_prior, yld_rate_curr, annual_vol, u);

return yld_rate_hwm;

}


//@@ END

//@@ START - ten_year_treasury_annualized_return_three_mth_avg_aig
// Average 10-year treasury rate over 3 months:                                                                                             
// Column:TEN_YEAR_TREASURY_ANNUALIZED_RETURN_THREE_MTH_AVG_AIG
//========================================================
double RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_three_mth_avg_aig(int t) {
//^^^



//^^^

#line 1 "ten_year_treasury_annualized_return_three_mth_avg_aig.RATES_ECONOMY.for"
// 20200515 DTL

/*
	Inputs:
		+ previous 3 months' 10-year treasury rates (annualized)

	Outputs:
		+ 3-month average (annualized)
*/
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

const double TREASURY_RATE_TENOR = 10.0;
const int MTHS_TO_AVG = 3;

vector<double> treasury_rates;

/* version 0
int current_mth = t;
int start_mth = max(0, current_mth - MTHS_TO_AVG);
int end_mth = current_mth;

for (int rate_lookup_month = start_mth; rate_lookup_month <= end_mth; rate_lookup_month++)
{
	double treasury_rate = get_int_rate(rate_lookup_month, "Govt", GET_YIELD_RATE, TREASURY_RATE_TENOR, 0, EFFECTIVE_ANNUAL, NO_SHIFT);
	treasury_rates.push_back(treasury_rate);
}
*/

const int MTH_ZERO = 0;
int current_mth = t;
for (int i = 0; i <= MTHS_TO_AVG; i++)
{
	//WTW - Gen2 - "Govt" does not exist on scenario file, so code does alot of extra work to create it
	//Update code to skip calls if "Govt" doesn't exist
	int rate_lookup_mth = max(MTH_ZERO, current_mth - i);
	double rate = 0.0;
	if (find(yld_curve_list.begin(), yld_curve_list.end(), "Govt") != yld_curve_list.end())
		rate = get_int_rate(rate_lookup_mth, "Govt", GET_YIELD_RATE, TREASURY_RATE_TENOR, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	treasury_rates.push_back(rate);
}

double ten_year_avg_cv = trapezoidal_rule_avg_height_calc_aig(treasury_rates);

return ten_year_avg_cv;

}


//@@ END

//@@ START - yield_rate_10_year
// Yield Rate 10 Year                                                                                             
// Column:YIELD_RATE_10_YEAR
//========================================================
double RATES_ECONOMY_UDF::rates_economy_yield_rate_10_year(int t) {
//^^^



//^^^

#line 1 "yield_rate_10_year.RATES_ECONOMY.for"
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (!stoch_flag)
	return NO_AVG;


return get_int_rate(t, "Govt", GET_YIELD_RATE, 10.0, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END

//@@ START - yield_rate_90_day
// Yield Rate 90 Day                                                                                             
// Column:YIELD_RATE_90_DAY
//========================================================
double RATES_ECONOMY_UDF::rates_economy_yield_rate_90_day(int t) {
//^^^



//^^^

#line 1 "yield_rate_90_day.RATES_ECONOMY.for"
if (t < 0 || t > last_model_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (!stoch_flag)
	return NO_AVG;

return get_int_rate(t, "Govt", GET_YIELD_RATE, 0.25, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END

//@@ START - gen_scen_file_path
// Generated Scenarios File Path                                                                                             
// Calculated Variable:GEN_SCEN_FILE_PATH
//========================================================
xstring RATES_ECONOMY_UDF::rates_economy_gen_scen_file_path() {
//^^^


#line 1 "gen_scen_file_path.RATES_ECONOMY.for"
return "<*scen_gen*>";

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring RATES_ECONOMY_UDF::rates_economy_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.RATES_ECONOMY.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_date_offset
// Projection Date Offset                                                                                             
// Calculated Variable:PROJ_DATE_OFFSET
//========================================================
int RATES_ECONOMY_UDF::rates_economy_proj_date_offset() {
//^^^


#line 1 "proj_date_offset.RATES_ECONOMY.for"
if ((time_step_flag && valn_flag && !hedge_valn_final_flag)
	|| !time_step_flag)
	return 0;

return valn_period;

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int RATES_ECONOMY_UDF::rates_economy_proj_start_date() {
//^^^


#line 1 "proj_start_date.RATES_ECONOMY.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int RATES_ECONOMY_UDF::rates_economy_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.RATES_ECONOMY.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return 1;
	
return proj_mth + 1;

}


//@@ END

//@@ START - proj_start_yr
// Projection Start Yr                                                                                             
// Calculated Variable:PROJ_START_YR
//========================================================
int RATES_ECONOMY_UDF::rates_economy_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.RATES_ECONOMY.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END


#line 1 "brownian_bridge_max_calc_normal_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::brownian_bridge_max_calc_normal_aig(double val_bom, double val_eom, double annual_vol, double u)
{
	// 20200515 MTC - New Normal Brownian Bridge for withdrawal rate indexing
	double val_max;

	// Convert annual vol to monthly
	double annual_var							= pow(annual_vol, 2.0);
	double mthly_vol							= pow(annual_var / 12.0, 0.5);

	if (mthly_vol > SMALL_DOUBLE)
	{
		// Calculate HWM growth
		double b								= (val_eom - val_bom) / mthly_vol;
		double brownian_bridge_max				= (b + pow(pow(b, 2.0) - 2.0 * log(1.0 - u), 0.5)) / 2.0;
		double hwm_growth						= brownian_bridge_max * mthly_vol;

		val_max									= val_bom + hwm_growth;
	}
	else
	{
		// When there's no vol, the max is deterministic, return greater of EOM/BOM, although theoretically if there's no vol EOM and BOM should be the same
		val_max									= max(val_bom, val_eom);
	}
	
	return val_max;
}



#line 1 "calc_forward_from_swap_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::calc_forward_from_swap_aig(int swap_rate_tenor, int t1, int t2)		
{		
	/*!Forward Rate Calculation	
	   ========================	
	   @author Michael Ching	
	   @date 20171206	
		
	   We derive the forward rate from the swap rate. Swap rates are read in through the economic scenario file as	
	   effective annual rates. Per <a href="https://en.wikipedia.org/wiki/Forward_rate">Wikipedia</a>:	
		
	   \f[	
	   e ^ {r_{1} * t_{1}} * e ^ {r_{1,2} * (t_{2} - t_{1})} = e ^ {r_{2} * t_{2}}	
	   \f]	
		
	   Where:	
	   -# \f$r_{1}\f$ is the swap rate from the earlier time period,	
	   -# \f$t_{1}\f$ is the earlier time period,	
	   -# \f$r_{2}\f$ is the swap rate from the later time period,	
	   -# \f$t_{2}\f$ is the later time period, and	
	   -# \f$r_{1,2}\f$ is the forward rate	
	   .	
		
	   @warning The call to Economy.dll is always getting the `SWAP_XX_MiscRate` column. If we want to change the column name in the economic scenario file, we will have to	
	   change the code here.	
		
	   @param[in] swap_rate_tenor The desired swap rate tenor.	
	   @param[in] t1 The earlier time period.	
	   @param[in] t2 The later time period.	
		
	   Related Inputs:	
	   ---------------	
	   None.	
		
	   @return Continous forward rate given the swap rate tenor and desired time periods.	
	*/	
  		
	// Initialize	
	double forward_rate = 0.0;	
	double r1 = 0.0;	
	double r2 = 0.0;	
		
	if (t2 - t1 == 0){	
		// Check for divide by zero; return zero if that is the case
		//forward_rate = get_misc_rate(t1 - proj_date_offset, "SWAP_" + xstring(swap_rate_tenor), EFFECTIVE_ANNUAL);

		forward_rate = get_int_rate(t1 - proj_date_offset,
									swap_curve_rate_id_aig,
									GET_YIELD_RATE,
									swap_rate_tenor / 12.0,
									0,
									EFFECTIVE_ANNUAL,
									NO_SHIFT,0); // 20181217 MTC - Updated Swaps to be a yield curve //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
									
		forward_rate = log(1 + forward_rate); // 20181023 MTC - Fix to convert annual effective rate to continuous
	}	
	else if (t2 < t1){	
		// Throw fatal error if requested t2 is less than t1
		throw FatalError("Requested t2 is less than t1 when calculating forward rates.");
	}	
	else {	
		// Get swap data from Economy.dll
		//r1 = get_misc_rate(t1 - proj_date_offset, "SWAP_" + xstring(swap_rate_tenor), EFFECTIVE_ANNUAL);
		//r2 = get_misc_rate(t2 - proj_date_offset, "SWAP_" + xstring(swap_rate_tenor), EFFECTIVE_ANNUAL);

		r1 = get_int_rate(t1 - proj_date_offset,
						  swap_curve_rate_id_aig,
						  GET_YIELD_RATE,
						  swap_rate_tenor / 12.0,
						  0,
						  EFFECTIVE_ANNUAL,
						  NO_SHIFT,0); // 20181217 MTC - Updated Swaps to be a yield curve //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
						  
		r2 = get_int_rate(t2 - proj_date_offset,
						  swap_curve_rate_id_aig,
						  GET_YIELD_RATE,
						  swap_rate_tenor / 12.0,
						  0,
						  EFFECTIVE_ANNUAL,
						  NO_SHIFT,0); // 20181217 MTC - Updated Swaps to be a yield curve //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		
		// Convert rates from effective annual to continuous
		// 20181017 - Reverted scenario file rates to annual effective
		r1 = log(1 + r1);
		r2 = log(1 + r2);
		
		// Calculate the continuous forward rate
		forward_rate = (r2 * t2 - r1 * t1) / (t2 - t1);

	}	
  		
	return forward_rate;	
}		




#line 1 "calc_spot_from_yld.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::calc_spot_from_yld(int t, const xstring &quality_id, double term, int shift_type, double portfolio_sprd_adj_aig)
{
//    The parameters for this function are defined as follows: 
//        t:                       The time period for the rate
//        quality_id:              The quality grade used in the scenario file, e.g. "Govt", "AA", "B"
//        term:                    Yield curve term for the rate. e.g. 0.25, 1.0, 5.0
//        shift_type               The type of shift to apply, e.g. YIELD_SHIFT
//
// The following table lists valid shift_type values.  
//   = NO_SHIFT                 no shift applies
//   = SPOT_SHIFT               spot rate shifts are specified
//   = YIELD_SHIFT              yield rate shifts are specified

if (term == 0)
	return 0.0;
 
xstring map_index = quality_id + "_" + xstring(t) 
                    + "_" + xstring(xint(term * 12))
					+ "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX


int i = 0;
int first_coupon_mth = 0;
int f = 0;
double period = 0;
double pv_factor = 0.0;
// Use 6 annuity factors, one for each number of months
// until the first future coupon payment
double annuity_factor[6];
double bey = 0.0;
double bond_val = 0.0;
double spot_rates_eff[MAX_TERM + 1];
double yld_rates_eff[MAX_TERM + 1];
double rate = 0.0;

// First capture the yield rates
for (i = 0; i <= MAX_TERM; i++)
	{
	period = i / 12.0;

	yld_rates_eff[i] = get_int_rate(t, quality_id, GET_YIELD_RATE, period, 0, EFFECTIVE_ANNUAL, shift_type, portfolio_sprd_adj_aig); //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	// save bond equivalent yield rate to map
	xstring yld_map_index = quality_id + "_" + xstring(t) 
						     + "_" + xstring(i)
							 + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

	if (shift_type != NO_SHIFT)
		yld_rates_shifted[yld_map_index] 
		= convert_rate_basis(yld_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	else
		yld_rates[yld_map_index] 
		= convert_rate_basis(yld_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	}

// If there is only one coupon payment left, the spot rate equals the yield rate.
for (i = 0; i < 7; i++)
	{
	period = i / 12.0;

	spot_rates_eff[i] = yld_rates_eff[i];

	// save bond equivalent spot rate to map
	xstring spot_map_index = quality_id + "_" + xstring(t) 
				             + "_" + xstring(i)
							 + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

	if (shift_type != NO_SHIFT)
		spot_rates_shifted[spot_map_index] 
		= yld_rates_shifted[spot_map_index];	
	else
		spot_rates[spot_map_index] 
		= yld_rates[spot_map_index];	
	}

// Create the effective annual spot rates from the yield rates
for (i = 0; i < 6; i++)
	annuity_factor[i] = 0.0;

for (i = 7; i <= MAX_TERM; i++)
	{
	period = i / 12.0;

	pv_factor = pow(1.0 + spot_rates_eff[i - 6], -(period - 0.5));

	first_coupon_mth = 1.0 + ((i - 1) % 6);

	// f is used as an index to the annuityFactor[] array
	f = first_coupon_mth - 1;
	annuity_factor[f] = annuity_factor[f] + pv_factor / 2.0;

	// The bond value in between coupon dates is the accrued interest
	// based on the current yield rate.
	bey = 2.0 * (pow(1.0 + yld_rates_eff[i], 0.5) - 1.0);
	bond_val = pow(1.0 + bey / 2.0, (6 - first_coupon_mth) / 6.0);

	pv_factor = (bond_val - annuity_factor[f] * bey) / (1.0 + bey / 2.0);

	// Adjust for negative pv_factor
	if (pv_factor >= 0.0)
		spot_rates_eff[i] = pow(pv_factor, (-1.0 / period)) - 1.0;
	else
		spot_rates_eff[i] = spot_rates_eff[i - 1];

	// save bond equivalent spot rates to the map 
	xstring spot_map_index = quality_id + "_" + xstring(t) 
				             + "_" + xstring(i)
							 + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

	if (shift_type != NO_SHIFT)
		spot_rates_shifted[spot_map_index] 
		= convert_rate_basis(spot_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	else
		spot_rates[spot_map_index] 
		= convert_rate_basis(spot_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	}

if (shift_type != NO_SHIFT)
	rate = spot_rates_shifted[map_index];
else
	rate = spot_rates[map_index];

return rate;
}



#line 1 "calc_yld_from_spot.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::calc_yld_from_spot(int t, const xstring &quality_id, double term, int shift_type, double portfolio_sprd_adj_aig)
{
//    The parameters for this function are defined as follows: 
//        t:                       The time period for the rate
//        quality_id:              The quality grade used in the scenario file, e.g. "Govt", "AA", "B"
//        term:                    Yield curve term for the rate. e.g. 0.25, 1.0, 5.0
//        shift_type               The type of shift to apply, e.g. YIELD_SHIFT
//
// The following table lists valid shift_type values.  
//   = NO_SHIFT                 no shift applies
//   = SPOT_SHIFT               spot rate shifts are specified
//   = YIELD_SHIFT              yield rate shifts are specified

if (term == 0)
	return 0.0;

xstring map_index = quality_id + "_" + xstring(t) 
                    + "_" + xstring(xint(term * 12))
					+ "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

int i = 0;
int first_coupon_mth = 0;
int f = 0;
double period = 0;
double pv_factor = 0.0;
// Use 6 annuity factors, one for each number of months
// until the first future coupon payment
double annuity_factor[6];
double bey = 0.0;
double bond_val = 0.0;
double spot_rates_eff[MAX_TERM + 1];
double yld_rates_eff[MAX_TERM + 1];
double rate = 0.0;

// First capture the spot rates
for (i = 0; i <= MAX_TERM; i++)
	{
	period = i / 12.0;

	spot_rates_eff[i] 
	= get_int_rate(t, quality_id, GET_SPOT_RATE, period, 0, EFFECTIVE_ANNUAL, shift_type, portfolio_sprd_adj_aig); //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	// save bond equivalent spot rate to map
	xstring spot_map_index = quality_id + "_" + xstring(t) 
						     + "_" + xstring(i)
							 + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

	if (shift_type != NO_SHIFT)
		spot_rates_shifted[spot_map_index] 
		= convert_rate_basis(spot_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	else
		spot_rates[spot_map_index] 
		= convert_rate_basis(spot_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	}

// If there is only one coupon payment left, the yield rate equals the spot rate.
for (i = 0; i < 7; i++)
	{
	period = i / 12.0;

	yld_rates_eff[i] = spot_rates_eff[i];

	// save bond equivalent spot rate to map
	xstring yld_map_index = quality_id + "_" + xstring(t) 
				        + "_" + xstring(i)
					    + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX


	if (shift_type != NO_SHIFT)
		yld_rates_shifted[yld_map_index] 
		= spot_rates_shifted[yld_map_index];	
	else
		yld_rates[yld_map_index] 
		= spot_rates[yld_map_index];	
	}

// Create the effective annual yield rates from the spot rates
for (i = 0; i < 6; i++)
	annuity_factor[i] = 0.0;

for (i = 7; i <= MAX_TERM; i++)
	{
	period = i / 12.0;

	pv_factor = pow(1.0 + spot_rates_eff[i - 6], -(period - 0.5));

	first_coupon_mth = 1.0 + ((i - 1) % 6);

	// f is used as an index to the annuityFactor[] array
	f = first_coupon_mth - 1;
	annuity_factor[f] = annuity_factor[f] + pv_factor / 2.0;

	// The bond value in between coupon dates is the accrued interest
	// based on the current yield rate, which is the rate being determined.
	// To calculate the bond value exactly creates a very complicated formula
	// for determining the yield rate. As a simplification, we estimate 
	// in between coupon date bond value using the spot rate
	bey = 2.0 * (pow(1.0 + spot_rates_eff[i], 0.5) - 1.0);
	bond_val = pow(1.0 + bey / 2.0, (6 - first_coupon_mth) / 6.0);

	pv_factor = pow(1.0  + spot_rates_eff[i], -period);

	bey = (bond_val - pv_factor) / (0.5 * pv_factor + annuity_factor[f]);

	// Convert the yield rate to an annual-equivalent yield
	yld_rates_eff[i] = pow(1.0  + bey / 2.0, 2.0) - 1.0;

	// save bond equivalent yield rates to the map 
	xstring yld_map_index = quality_id + "_" + xstring(t) 
						     + "_" + xstring(i)
							 + "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

	if (shift_type != NO_SHIFT)
		yld_rates_shifted[yld_map_index] 
		= convert_rate_basis(yld_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	else
		yld_rates[yld_map_index] 
		= convert_rate_basis(yld_rates_eff[i], EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);	
	}

if (shift_type != NO_SHIFT)
	rate = yld_rates_shifted[map_index];
else
	rate = yld_rates[map_index];

return rate;
}



#line 1 "clear_shifted_rates_maps.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::clear_shifted_rates_maps(void)
{
// Clear shocked rate maps
yld_rates_shifts.clear();
index_val_shifts.clear();
index_vols_shifts.clear();
spot_rates_shifted.clear();
yld_rates_shifted.clear();
index_vols_shifted.clear();

return;
}



#line 1 "cubic_spline_interpolated_curve_aig.RATES_ECONOMY.for"                                                                                   
vector<double> RATES_ECONOMY::cubic_spline_interpolated_curve_aig(double start_mth, double end_mth, vector <double> lookups, vector <double> values, cubic_spline_params_aig cubic_spline_params_input )
{
	/*! Natural Cubic Spline Interpolation
		==================================
		@author Michael Ching
		@date 20181119
 
		This function is the natural cubic spline interpolation algorithm described on P.149 in the 9th edition of
		Richard L. Burden & J. Douglas Faires' <a href="https://www.cengage.com/c/numerical-analysis-10e-#">Numerical Analysis</a>.
		A less thorough (but freely accessible) document is available on P.22 <a href="http://facstaff.cbu.edu/wschrein/media/M329%20Notes/M329C3.pdf">here</a>.
		Please reference the text for a more thorough understanding of this algorithm.
 
		@param[in] lookup_value A lookup value.
		@param[in] lookups A vector of lookup indices.
		@param[in] values A vector that contains values over which it interpolate.
 
		Related Inputs:
		---------------
		None.
 
		@return A value resulting from the cubic spline interpolation lookup algorithm.
	*/

	if(cubic_spline_enhancement_wtw_switch_aig == YES)
	{
		// Initialize
		const cubic_spline_params_aig& cubic_spline_params = cubic_spline_params_create(cubic_spline_params_input, lookups, values);

		vector<double> x = lookups;
		vector<double> a = values;

		//WTW - Gen2 - DevTeam Feedback - 2/22/2022
		const int& n = cubic_spline_params.n;
		const vector<double>& h = cubic_spline_params.h;
		const vector<double>& alpha = cubic_spline_params.alpha;
		const vector<double>& l = cubic_spline_params.l;
		const vector<double>& mu = cubic_spline_params.mu;
		const vector<double>& z = cubic_spline_params.z;
		const vector<double>& c = cubic_spline_params.c;
		const vector<double>& b = cubic_spline_params.b;
		const vector<double>& d = cubic_spline_params.d;
		vector<double> s;

		for (int mth = start_mth; mth < end_mth; mth++) //20220203 MQ add the loop to get the entire curve
		{
		// Find appropriate kth line segment
			int k = -1;

			if (mth <= x[0])
			{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
				k = 0;
			}
			else if (mth > x[n - 1])
			{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
				k = n - 1;
			}
			else
			{
				for (int j = 0; j < (n - 1); j++)
				{
					if ((mth > x[j]) && (mth <= x[j + 1]))
					{
						k = j;
					break;
					}
				}
			}

			// Calculate interpolated value
			double S_x = a[k] +
						 b[k] * (mth - x[k]) + 
						 c[k] * pow(mth - x[k], 2.0) + 
						 d[k] * pow(mth - x[k], 3.0);

			s.push_back(S_x);
		}

		return s;
	}
	else
	{
		// Initialize
		cubic_spline_params_aig cubic_spline_params;

		if (!cubic_spline_params_input.initialized)
		{
			cubic_spline_params_calc_aig(cubic_spline_params, lookups, values);
		}
		else
		{
			cubic_spline_params = cubic_spline_params_input;
		}

		vector<double> x = lookups;
		vector<double> a = values;
		//WTW - Gen2 - DevTeam Feedback - 2/22/2022
		int n = cubic_spline_params.n;
		vector<double> h = cubic_spline_params.h;
		vector<double> alpha = cubic_spline_params.alpha;
		vector<double> l = cubic_spline_params.l;
		vector<double> mu = cubic_spline_params.mu;
		vector<double> z = cubic_spline_params.z;
		vector<double> c = cubic_spline_params.c;
		vector<double> b = cubic_spline_params.b;
		vector<double> d = cubic_spline_params.d;
		vector<double> s;

		for (int mth = start_mth; mth < end_mth; mth++) //20220203 MQ add the loop to get the entire curve
		{
		// Find appropriate kth line segment
			int k = -1;

			if (mth <= x[0])
			{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
				k = 0;
			}
			else if (mth > x[n - 1])
			{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
				k = n - 1;
			}
			else
			{
				for (int j = 0; j < (n - 1); j++)
				{
					if ((mth > x[j]) && (mth <= x[j + 1]))
					{
						k = j;
					break;
					}
				}
			}

			// Calculate interpolated value
			double S_x = a[k] +
						 b[k] * (mth - x[k]) + 
						 c[k] * pow(mth - x[k], 2.0) + 
						 d[k] * pow(mth - x[k], 3.0);

			s.push_back(S_x);
		}

		return s;
	}
}



#line 1 "cubic_spline_interpolation_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::cubic_spline_interpolation_aig(double lookup_value, vector <double> lookups, vector <double> values, cubic_spline_params_aig cubic_spline_params_input )
{
	/*! Natural Cubic Spline Interpolation
		==================================
		@author Michael Ching
		@date 20181119
 
		This function is the natural cubic spline interpolation algorithm described on P.149 in the 9th edition of
		Richard L. Burden & J. Douglas Faires' <a href="https://www.cengage.com/c/numerical-analysis-10e-#">Numerical Analysis</a>.
		A less thorough (but freely accessible) document is available on P.22 <a href="http://facstaff.cbu.edu/wschrein/media/M329%20Notes/M329C3.pdf">here</a>.
		Please reference the text for a more thorough understanding of this algorithm.
 
		@param[in] lookup_value A lookup value.
		@param[in] lookups A vector of lookup indices.
		@param[in] values A vector that contains values over which it interpolate.
 
		Related Inputs:
		---------------
		None.
 
		@return A value resulting from the cubic spline interpolation lookup algorithm.
	*/
	
		
	if(cubic_spline_enhancement_wtw_switch_aig == YES)
	{
		// Initialize
		//WTW - Gen2 - DevTeam Feedback - 2/22/2022
		const cubic_spline_params_aig& cubic_spline_params = cubic_spline_params_create(cubic_spline_params_input, lookups, values);

		vector<double> x = lookups;
		vector<double> a = values;

		//WTW - Gen2 - DevTeam Feedback - 2/22/2022
		const int& n = cubic_spline_params.n;
		const vector<double>& h = cubic_spline_params.h;
		const vector<double>& alpha = cubic_spline_params.alpha;
		const vector<double>& l = cubic_spline_params.l;
		const vector<double>& mu = cubic_spline_params.mu;
		const vector<double>& z = cubic_spline_params.z;
		const vector<double>& c = cubic_spline_params.c;
		const vector<double>& b = cubic_spline_params.b;
		const vector<double>& d = cubic_spline_params.d;

		// Find appropriate kth line segment
		int k = -1;

		if (lookup_value <= x[0])
		{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
			k = 0;
		}
		else if (lookup_value > x[n - 1])
		{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
			k = n - 1;
		}
		else
		{
			for (int j = 0; j < (n - 1); j++)
			{
				if ((lookup_value > x[j]) && (lookup_value <= x[j + 1]))
				{
					k = j;
					break;
				}
			}
		}

		// Calculate interpolated value
		double S_x = a[k] +
					 b[k] * (lookup_value - x[k]) + 
					 c[k] * pow(lookup_value - x[k], 2.0) + 
					 d[k] * pow(lookup_value - x[k], 3.0);

		return S_x;
	}
	else
	{
		// Initialize
		cubic_spline_params_aig cubic_spline_params;

		if (!cubic_spline_params_input.initialized)
		{
			cubic_spline_params_calc_aig(cubic_spline_params, lookups, values);
		}
		else
		{
			cubic_spline_params = cubic_spline_params_input;
		}
		
		vector<double> x = lookups;
		vector<double> a = values;

		int n = cubic_spline_params.n;
		vector<double> h = cubic_spline_params.h;
		vector<double> alpha = cubic_spline_params.alpha;
		vector<double> l = cubic_spline_params.l;
		vector<double> mu = cubic_spline_params.mu;
		vector<double> z = cubic_spline_params.z;
		vector<double> c = cubic_spline_params.c;
		vector<double> b = cubic_spline_params.b;
		vector<double> d = cubic_spline_params.d;

		// Find appropriate kth line segment
		int k = -1;

		if (lookup_value <= x[0])
		{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
			k = 0;
		}
		else if (lookup_value > x[n - 1])
		{
			// TODO: What do we intend to do for extrapolation? Our original implementation needs to be revisited.
			k = n - 1;
		}
		else
		{
			for (int j = 0; j < (n - 1); j++)
			{
				if ((lookup_value > x[j]) && (lookup_value <= x[j + 1]))
				{
					k = j;
					break;
				}
			}
		}

		// Calculate interpolated value
		double S_x = a[k] +
					 b[k] * (lookup_value - x[k]) + 
					 c[k] * pow(lookup_value - x[k], 2.0) + 
					 d[k] * pow(lookup_value - x[k], 3.0);

		return S_x;
	}
}



#line 1 "cubic_spline_params_calc_aig.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::cubic_spline_params_calc_aig(cubic_spline_params_aig& return_parameters, vector <double> lookups, vector <double> values)
{
	/*! Natural Cubic Spline Interpolation Parameters
		=============================================
		@author Michael Ching
		@date 20181217
 
		This function calculates the parameters described in P.149 in the 9th edition of
		Richard L. Burden & J. Douglas Faires' <a href="https://www.cengage.com/c/numerical-analysis-10e-#">Numerical Analysis</a>.
		A less thorough (but freely accessible) document is available on P.22 <a href="http://facstaff.cbu.edu/wschrein/media/M329%20Notes/M329C3.pdf">here</a>.
		Please reference the text for a more thorough understanding of this algorithm.
 
		@param[in] lookup_value A lookup value.
		@param[in] lookups A vector of lookup indices.
		@param[in] values A vector that contains values over which it interpolate.
 
		Related Inputs:
		---------------
		None.
 
		@return A set of parameters used in the cubic spline interpolation lookup algorithm.
	*/

	// Initialize
	vector<double> x = lookups;
	vector<double> a = values;
	int n = x.size();
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;

	// Check input vectors
	if (n != a.size())
	{
		throw FatalError("Requested lookups and values are different sizes in cubic_spline_lookup_aig!");
	}
	
	// Step 1
	for (int i = 0; i < (n - 1); i++)
	{
		double h_i = x[i + 1] - x[i];
		h.push_back(h_i);
	}

	// Step 2
	alpha.push_back(NULL);

	for (int i = 1; i < (n - 1); i++)
	{
		double alpha_i = (3.0 / h[i]) * (a[i + 1] - a[i]) - 
						 (3.0 / h[i - 1]) * (a[i] - a[i - 1]);
		alpha.push_back(alpha_i);
	}

	// Step 3
	const double l_0 = 1.0;
	l.push_back(l_0);

	const double mu_0 = 0.0;
	mu.push_back(mu_0);

	const double z_0 = 0.0;
	z.push_back(z_0);

	// Step 4
	for (int i = 1; i < (n - 1); i++)
	{
		double l_i = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
		l.push_back(l_i);

		double mu_i = h[i] / l[i];
		mu.push_back(mu_i);

		double z_i = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
		z.push_back(z_i);
	}

	// Step 5
	const double l_n = 1.0;
	l.resize(n);
	l[n - 1] = l_n;

	const double z_n = 0.0;
	z.resize(n);
	z[n - 1] = z_n;

	const double c_n = 0.0;
	c.resize(n);
	c[n - 1] = c_n;

	// Step 6
	b.resize(n);
	d.resize(n);

	for (int j = (n - 2); j >= 0; j--)
	{
		double c_j = z[j] - mu[j] * c[j + 1];
		c[j] = c_j;

		double b_j = (a[j + 1] - a[j]) / h[j] -
					 (h[j] * (c[j + 1] + 2.0 * c[j])) / 3.0;
		b[j] = b_j;

		double d_j = (c[j + 1] - c[j]) / (3.0 * h[j]);
		d[j] = d_j;
	}

	// Set return parameter values
	return_parameters.initialized = true;
	return_parameters.n = n;
	return_parameters.h = h;
	return_parameters.alpha = alpha;
	return_parameters.l = l;
	return_parameters.mu = mu;
	return_parameters.z = z;
	return_parameters.c = c;
	return_parameters.b = b;
	return_parameters.d = d;

	return;
}



#line 1 "cubic_spline_params_create.RATES_ECONOMY.for"                                                                                   
const cubic_spline_params_aig& RATES_ECONOMY::cubic_spline_params_create(const cubic_spline_params_aig& cubic_spline_params_input, const vector<double>& lookups, const vector<double>& values)
{
	if (cubic_spline_params_input.initialized)
		return cubic_spline_params_input;

	cubic_spline_params_aig cubic_spline_params;
	cubic_spline_params_calc_aig(cubic_spline_params, lookups, values);
	
	return cubic_spline_params;
}



#line 1 "disc_rate_1.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::disc_rate_1(int t, double scenario_year)
{
//WTW - Gen2 - "Govt" does not exist on scenario file, so code does alot of extra work to create it
//Update code to skip calls if "Govt" doesn't exist
double current_rate = 0.0;
	
if (find(yld_curve_list.begin(), yld_curve_list.end(), "Govt") != yld_curve_list.end())
	current_rate = get_int_rate(t, "Govt", GET_YIELD_RATE, scenario_year, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	 
return current_rate;

}



#line 1 "econ_error_processing.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::econ_error_processing(int econ_err_code)//WTW - Gen2 - user defined enum 
{
char err_mess[MAX_ERR_LEN + 1];
//EconErrorCodeType err_code;
int err_code;//WTW - Gen2 - user defined enum 

err_code = Econ->get_ErrorMessage(err_mess);

if (err_code == ECON_ERROR)
	throw FatalError("Unable to retrieve error message from Economy DLL.");

if (econ_err_code == ECON_ERROR)
	throw FatalError(err_mess);
	
// Else issue just a warning
log_screen << "Warning: " + xstring(err_mess) + "." << MSG_USER;

if (gen2_defn == NO)
	makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported

return;
}



#line 1 "econ_rate_error_processing.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::econ_rate_error_processing(int t, xstring id, int econ_err_code)//WTW - Gen2 - user defined enum 
{
char err_mess[MAX_ERR_LEN + 1];
xstring error;
//EconErrorCodeType err_code;
int err_code;//WTW - Gen2 - user defined enum

err_code = Econ->get_ErrorMessage(err_mess);

error = xstring(err_mess) + " for ID='" + xstring(id) + "' Period=" + xstring(t);

if (err_code == ECON_ERROR)
	throw FatalError("Unable to retrieve error message from Economy DLL.");

if (econ_err_code == ECON_ERROR)
	throw FatalError(error);
	
// Else issue just a warning
log_screen << "Warning: " + xstring(error) + "." << MSG_USER;

// Only turn run log yellow if warning is not because of a zero rate
// or not because of a spot rate not calculated warning
/*xstring err_mess_string = xstring(error);
if (!(err_mess_string.find("The value of the rate is zero") < string::npos)
	&& !(err_mess_string.find("spot rate cannot be calculated") < string::npos))*/

if (gen2_defn == NO)
	makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported

return;
}



#line 1 "get_dflt_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_dflt_rate(int t, const xstring &quality_id_input, int return_rate_basis)
{
// The parameters for this function are defined as follows: 
// t:                 The time period for the rate
// quality_id_input:  The quality grade for the rate
// return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY

char qual_id[MAX_ID_LEN + 1];
double dflt_rate = 0.0;

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		break;
	case NOMINAL_SEMIANNUAL:
		break;
	case NOMINAL_QUARTERLY:
		break;
	case NOMINAL_MONTHLY:
		break;
	case ACTUAL_SEMIANNUAL:
		break;
	case ACTUAL_QUARTERLY:
		break;
	case ACTUAL_MONTHLY:
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'return_rate_basis' passed to 'get_dflt_rate' function.");
		break;	 	
	}
	
if (quality_id_input == "Govt")
	return 0.0;

// Set lookup key	
quality_id = quality_id_input;

// Get deterministic default rate
date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
dflt_rate += dflt_rate_deterministic;

// Get stochastic default rate
double dflt_rate_stoch = 0.0;
double mult = 0.0;

for (int yld_curve = 0; yld_curve < yld_curve_list.size(); yld_curve++)
	{
	// Set lookup key
	yld_curve_id = xstring(yld_curve_list[yld_curve]);
	quality_id = quality_id_input;//WTW - Gen2 - Mutating Lookup term

	// lookup keys: date(t), yld_curve_id, and quality_id	
	mult = dflt_rate_stoch_mult; 
	
	if (fabs(mult) > rate_ratio_threshold)
		{
		xstring map_index = yld_curve_id + "_" + xstring(t);

		if (dflt_rates.find(map_index) != dflt_rates.end())
			dflt_rate_stoch = dflt_rates[map_index];
		else
			{
			char row_id[MAX_ID_LEN + 1];
			strncpy(row_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);
	
			econ_err_code 
			= Econ->GetDefaultRate(t + proj_date_offset, 
								   "USA", 
								   row_id, 
								   RateReturnFreqType::EffectiveAnnual, 
								   dflt_rate_stoch);
		
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id, econ_err_code);

			dflt_rates[map_index] = dflt_rate_stoch;
			}

		dflt_rate += mult * dflt_rate_stoch;
		}
	}

if (return_rate_basis == EFFECTIVE_ANNUAL 
	|| fabs(dflt_rate) < rate_ratio_threshold)
	return dflt_rate;

return convert_rate_basis(dflt_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_fx_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_fx_rate(int t, const xstring &base_country, const xstring &alt_country, double fwd_mths, int curr_quote_type)
{
// The parameters for this function are defined as follows: 
//     t:               The time period for the rate
//     base_country:    The base country name used in the scenario file, e.g. "USA", "GBR", "EUR"
//     alt_country:     The alternate country name used in the scenario file, e.g. "USA", "GBR", "EUR"
//     fwd_mths:        Months forward for the exchange rate (0 for current)
//     curr_quote_type: Quote basis for the exchange rate, e.g. DIRECT
//
// The following table lists valid curr_quote_type values.  
//   = DIRECT    units of alternative currency per unit of base
//   = INDIRECT  units of base currency per unit of alternative
//
// Countries are supplied to this function and to the Economy method.
// A country to currency mapping is performed inside the Economy DLL.

CurrencyQuoteType currQuoteType;

switch (curr_quote_type)
	{
	case DIRECT:
		currQuoteType = CurrencyQuoteType::Direct;
		break;		
	case INDIRECT:
		currQuoteType = CurrencyQuoteType::Indirect;
		break;
	default:
		throw FatalError("Invalid 'curr_quote_type' passed to 'get_fx_rate' function.");
		break;	 	
	}

char base_cntry[MAX_ID_LEN + 1];
char alt_cntry[MAX_ID_LEN + 1];
double fx_rate = 0.0;

// Return 1.0 if base country is not included in scenario file
if (find(country_list.begin(), country_list.end(), base_country) == country_list.end())
	{
	log_screen << "Warning: Base country is not included in scenario file. Exchange rate for period " << t << " is 1.0." << MSG_USER;
	return 1.0;
	}

// Return 1.0 if alternative country is not included in scenario file
if (find(country_list.begin(), country_list.end(), alt_country) == country_list.end())
	{
	log_screen << "Warning: Alternative country is not included in scenario file. Exchange rate for period " << t << " is 1.0." << MSG_USER;
	return 1.0;
	}

xstring map_index 
		= xstring(base_country) + "_" 
		  + xstring(alt_country) + "_" 
		  + xstring(fwd_mths) + "_" 
		  + xstring(curr_quote_type) + "_" 
		  + xstring(t);

if (fx_rates.find(map_index) != fx_rates.end())
	fx_rate = fx_rates[map_index];
else
	{
	strncpy(base_cntry, base_country.c_str(), MAX_ID_LEN + 1);
	strncpy(alt_cntry, alt_country.c_str(), MAX_ID_LEN + 1);
	
	econ_err_code 
	= Econ->GetExchangeRate(t + proj_date_offset, 
							base_cntry, 
							alt_cntry, 
							fwd_mths, 
							currQuoteType, 
							fx_rate);
		
	if (econ_err_code != ECON_OK)
		econ_rate_error_processing(t, base_country, econ_err_code);

	fx_rates[map_index] = fx_rate;
	}

return fx_rate;
}



#line 1 "get_index_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_index_rate(int t, const xstring &index_id, int rate_type, int return_rate_basis)
{
// The parameters for this function are defined as follows: 
//     t:                 The time period for the rate
//     index_id:          The index name used in the scenario file, e.g. "Aggr", "US", "Small"
//     rate_type:         The type of rate to retrieve, e.g. GET_GROWTH_RATE
//     return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//
// The following table lists valid rate_type values.  
//   = GET_GROWTH_RATE                for index growth 
//   = GET_TOTAL_RETURN               for index total return
//   = GET_INCOME_RETURN              for index income rate
//   = GET_DIVIDEND_YIELD             for dividend yield
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY

EquityRateType rateType;
xstring rate_type_string;

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		break;
	case NOMINAL_SEMIANNUAL:
		break;
	case NOMINAL_QUARTERLY:
		break;
	case NOMINAL_MONTHLY:
		break;
	case ACTUAL_SEMIANNUAL:
		break;
	case ACTUAL_QUARTERLY:
		break;
	case ACTUAL_MONTHLY:
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'return_rate_basis' passed to 'get_index_rate' function.");
		break;	 	
	}

switch (rate_type)
	{
	case GET_GROWTH_RATE:
		rateType = EquityRateType::GrowthRate;
		rate_type_string = "GR";
		break;
	case GET_TOTAL_RETURN:
		rateType = EquityRateType::TotalReturn;
		rate_type_string = "TR";
		break;
	case GET_INCOME_RETURN:
		rateType = EquityRateType::IncomeReturn;
		rate_type_string = "IR";
		break;
	case GET_DIVIDEND_YIELD:
		rateType = EquityRateType::DividendYield;
		rate_type_string = "DY";
		break;
	default:
		throw FatalError("Invalid 'rate_type' passed to 'get_index_rate' function.");							
		break;
	}

char indx_id[MAX_ID_LEN + 1];
double index_rate = 0.0;

// Return 0.0 if index not in scenario file
if (find(index_list.begin(), index_list.end(), index_id) == index_list.end())
	{
	log_screen << "Warning: Index " + index_id + " not included in index rates list. "
	           << "A zero rate has been returned. Please check your historic rates file." << MSG_USER;	

	if (gen2_defn == NO)
		makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported

	return 0.0;
	}

xstring map_index = index_id + "_" + rate_type_string + "_" + xstring(t);

if (index_rates.find(map_index) != index_rates.end())
	index_rate = index_rates[map_index];
else
	{	
	strncpy(indx_id, index_id.c_str(), MAX_ID_LEN + 1);
	
	econ_err_code 
	= Econ->GetIndexRate(t + proj_date_offset, 
						 "USA", 
						 indx_id, 
						 rateType, 
						 RateReturnFreqType::EffectiveAnnual, 
						 index_rate);
		
	if (econ_err_code != ECON_OK)
		econ_rate_error_processing(t, index_id, econ_err_code);

	index_rates[map_index] = index_rate;
	}

if (return_rate_basis == EFFECTIVE_ANNUAL) 
	return index_rate;

return convert_rate_basis(index_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_index_val.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_index_val(int t, const xstring &index_id)
{
// The parameters for this function are defined as follows: 
//     t:                 The time period for the value
//     index_id:          The index name for the rate, e.g."Aggr", "US", "Small"

char indx_id[MAX_ID_LEN + 1];
double index_val = 0.0;

// Return 0.0 if index not in scenario file
if (find(index_list.begin(), index_list.end(), index_id) == index_list.end())
	{
	log_screen << "Warning: Index " + index_id + " not included in index rates list. "
	           << "A zero rate has been returned. Please check your historic rates file." << MSG_USER;	

	makeRunLogYellow();

	return 0.0;
	}

xstring map_index = index_id + "_VAL_" + xstring(t);

if (index_rates.find(map_index) != index_rates.end())
	index_val = index_rates[map_index];
else
	{	
	strncpy(indx_id, index_id.c_str(), MAX_ID_LEN + 1);
	
	econ_err_code 
	= Econ->GetIndexValue(t + proj_date_offset, 
						 "USA", 
						 indx_id, 
						 index_val);
		
	if (econ_err_code != ECON_OK)
		econ_rate_error_processing(t, index_id, econ_err_code);

	index_rates[map_index] = index_val;
	}

return index_val;
}



#line 1 "get_index_vol.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_index_vol(int t, const xstring &index_id_input, double moneyness_input, double rate_term_input, int return_rate_basis, int shift_type)
{
// The parameters for this function are defined as follows: 
//     t:                 The time period for the rate
//     index_id:          The index name for the rate, e.g."Aggr", "US", "Small"
//     moneyness_input:   Moneyness level for the volatility, e.g. 1.00, 0.95, 1.05
//     rate_term_input:   Tenor for the volatility, e.g. 0.25, 1.0, 5.0
//     return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//     shift_type:        The type of shift to apply, e.g. VOL_SHIFT
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY
//
// The following table lists valid shift_type values.  
//   = NO_SHIFT                 no shift applies
//   = VOL_SHIFT                volatility shifts are specified

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		break;
	case NOMINAL_SEMIANNUAL:
		break;
	case NOMINAL_QUARTERLY:
		break;
	case NOMINAL_MONTHLY:
		break;
	case ACTUAL_SEMIANNUAL:
		break;
	case ACTUAL_QUARTERLY:
		break;
	case ACTUAL_MONTHLY:
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'return_rate_basis' passed to 'get_index_vol' function.");
		break;	 	
	}

char idx_id[MAX_ID_LEN + 1];
double vol_rate = 0.0;
xstring map_index;

if (fabs(rate_term_input) < rate_ratio_threshold)
	return 0.0;

xstring vol_id;

// Set lookup key	
index_id = index_id_input;
moneyness = moneyness_input;
rate_term = rate_term_input;

if (index_vol_surface_list.find(index_id) != index_vol_surface_list.end())
	{
	strncpy(idx_id, index_id.c_str(), MAX_ID_LEN + 1);

	range_pair = index_vol_surface_list.equal_range(index_id);

	double high_moneyness = 99.0;
	double low_moneyness = 0.0;
	double moneyness_val = 0.0;
	
	for (iter = range_pair.first; iter != range_pair.second; iter++)
		{
		moneyness_val = iter->second;

		if (fabs(moneyness_input - moneyness_val) < rate_ratio_threshold)
			break;

		if (moneyness_input > moneyness_val
			&& low_moneyness < moneyness_val)
			low_moneyness = moneyness_val;
			
		if (moneyness_input < moneyness_val
			&& high_moneyness > moneyness_val)
			high_moneyness = moneyness_val;	
		}

	if (fabs(moneyness_val - moneyness_input) < rate_ratio_threshold)
		{ // Exact match, retrieve result
		map_index 
		= index_id + "_" 
		  + xstring(moneyness_input) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (shift_type == NO_SHIFT
			&& index_vols.find(map_index) != index_vols.end())
			vol_rate = index_vols[map_index];

		else if (index_vols_shifted.find(map_index) != index_vols_shifted.end())
			vol_rate = index_vols_shifted[map_index];

		else // must retrieve a rate
			{
			econ_err_code 
			= Econ->GetIndexVolatility(t + proj_date_offset, 
									   "USA", 
									   idx_id, 
									   moneyness_input, 
									   rate_term_input, 
									   RateReturnFreqType::EffectiveAnnual, 
									   vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, index_id, econ_err_code);

			if (shift_type == VOL_SHIFT)
				{
				// apply the shift
				xstring shift_map_index = index_id_input + "_" + xstring(xint(rate_term_input * 12));
				double shift = index_vols_shifts[shift_map_index];
				vol_rate = max(0.0, vol_rate + shift);

				index_vols_shifted[map_index] = vol_rate;
				}
			else
				index_vols[map_index] = vol_rate;
			}
		}						
	else if (high_moneyness == 99.0)
		{ // Use highest moneyness level
		map_index 
		= index_id + "_" 
		  + xstring(low_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (shift_type == NO_SHIFT
			&& index_vols.find(map_index) != index_vols.end())
			vol_rate = index_vols[map_index];

		else if (index_vols_shifted.find(map_index) != index_vols_shifted.end())
			vol_rate = index_vols_shifted[map_index];

		else // must retrieve a rate
			{
			econ_err_code 
			= Econ->GetIndexVolatility(t + proj_date_offset, 
									   "USA", 
									   idx_id, 
									   low_moneyness, 
									   rate_term_input, 
									   RateReturnFreqType::EffectiveAnnual, 
									   vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, index_id, econ_err_code);

			if (shift_type == VOL_SHIFT)
				{
				// apply the shift
				xstring shift_map_index = index_id_input + xstring(xint(rate_term_input * 12));
				double shift = index_vols_shifts[shift_map_index];
				vol_rate = max(0.0, vol_rate + shift);

				index_vols_shifted[map_index] = vol_rate;
				}
			else
				index_vols[map_index] = vol_rate;
			}
		}
	else if (fabs(low_moneyness) < rate_ratio_threshold)
		{ // Use lowest moneyness level
		map_index 
		= index_id + "_" 
		  + xstring(high_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (shift_type == NO_SHIFT
			&& index_vols.find(map_index) != index_vols.end())
			vol_rate = index_vols[map_index];

		else if (index_vols_shifted.find(map_index) != index_vols_shifted.end())
			vol_rate = index_vols_shifted[map_index];

		else // must retrieve a rate
			{
			econ_err_code 
			= Econ->GetIndexVolatility(t + proj_date_offset, 
										  "USA", 
										  idx_id, 
										  high_moneyness, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, index_id, econ_err_code);

			if (shift_type == VOL_SHIFT)
				{
				// apply the shift
				xstring shift_map_index = index_id_input + xstring(xint(rate_term_input * 12));
				double shift = index_vols_shifts[shift_map_index];
				vol_rate = max(0.0, vol_rate + shift);

				index_vols_shifted[map_index] = vol_rate;
				}
			else
				index_vols[map_index] = vol_rate;
			}
		}
	else // Interpolate between two specified levels
		{
		double vol_rate1 = 0.0;
		double vol_rate2 = 0.0;

		map_index 
		= index_id + "_" 
		  + xstring(high_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (shift_type == NO_SHIFT
			&& index_vols.find(map_index) != index_vols.end())
			vol_rate1 = index_vols[map_index];

		else if (index_vols_shifted.find(map_index) != index_vols_shifted.end())
			vol_rate1 = index_vols_shifted[map_index];

		else // must retrieve a rate
			{
			econ_err_code 
			= Econ->GetIndexVolatility(t + proj_date_offset, 
									   "USA", 
									   idx_id, 
									   high_moneyness, 
									   rate_term_input, 
									   RateReturnFreqType::EffectiveAnnual, 
									   vol_rate1);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, index_id, econ_err_code);

			if (shift_type == VOL_SHIFT)
				{
				// apply the shift
				xstring shift_map_index = index_id_input + xstring(xint(rate_term_input * 12));
				double shift = index_vols_shifts[shift_map_index];
				vol_rate1 = max(0.0, vol_rate1 + shift);

				index_vols_shifted[map_index] = vol_rate1;
				}
			else
				index_vols[map_index] = vol_rate1;
			}

		map_index 
		= index_id + "_" 
		  + xstring(low_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (shift_type == NO_SHIFT
			&& index_vols.find(map_index) != index_vols.end())
			vol_rate2 = index_vols[map_index];

		else if (index_vols_shifted.find(map_index) != index_vols_shifted.end())
			vol_rate2 = index_vols_shifted[map_index];

		else // must retrieve a rate
			{
			econ_err_code 
			= Econ->GetIndexVolatility(t + proj_date_offset, 
									   "USA", 
									   idx_id, 
									   low_moneyness, 
									   rate_term_input, 
									   RateReturnFreqType::EffectiveAnnual, 
									   vol_rate2);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, index_id, econ_err_code);

			if (shift_type == VOL_SHIFT)
				{
				// apply the shift
				xstring shift_map_index = index_id_input + xstring(xint(rate_term_input * 12));
				double shift = index_vols_shifts[shift_map_index];
				vol_rate2 = max(0.0, vol_rate2 + shift);

				index_vols_shifted[map_index] = vol_rate2;
				}
			else
				index_vols[map_index] = vol_rate2;
			}

		vol_rate 
		= (vol_rate2 
		   * (high_moneyness - moneyness_input)
		   + vol_rate1
		     * (moneyness_input - low_moneyness))
		   / (high_moneyness - low_moneyness);
		}
	}
else // Use user specified volatilities
	{
	// Deterministic volatility rate - lookup keys: date(t), index_id, term, and moneyness
	date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
	index_id = index_id_input;//WTW - Gen2 - Mutating Lookup Term
	moneyness = moneyness_input;//WTW - Gen2 - Mutating Lookup Term
	rate_term = rate_term_input;//WTW - Gen2 - Mutating Lookup Term
	vol_rate = index_vol_deterministic; 

	// Get stochastic volatilities
	double vol_stoch = 0.0;
	double mult = 0.0;

	for (int index = 0; index < index_list.size(); index++)
		{
		// Set lookup key
		scen_index_id = xstring(index_list[index]);
		
		// Lookup keys: scen_index_id, and index_id
		index_id = index_id_input;//WTW - Gen2 - Mutating Lookup Term
		mult = index_vol_stoch_mult; 
	
		if (fabs(mult) > rate_ratio_threshold)
			{
			// Save lookup key
			xstring index_id_saved = index_id;
			
			vol_stoch = get_index_vol(t, scen_index_id, moneyness_input, rate_term_input, EFFECTIVE_ANNUAL, NO_SHIFT);

			// Restore lookup key
			index_id = index_id_saved;

			vol_rate += mult * vol_stoch;
			}
		}

	if (shift_type == VOL_SHIFT)
		{
		// apply the shift
		xstring shift_map_index = index_id_input + "_" + xstring(xint(rate_term_input * 12));
		double shift = index_vols_shifts[shift_map_index];
		vol_rate = max(0.0, vol_rate + shift);
		}
	}

if (return_rate_basis == EFFECTIVE_ANNUAL || fabs(vol_rate) < rate_ratio_threshold)
	return vol_rate;

return convert_rate_basis(vol_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_infl_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_infl_rate(int t, int return_rate_basis)
{
// The parameters for this function are defined as follows: 
//     t:                 The time period for the rate
//     return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY

RateReturnFreqType rateBasis;

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		rateBasis = RateReturnFreqType::EffectiveAnnual;
		break;
	case NOMINAL_SEMIANNUAL:
		rateBasis = RateReturnFreqType::NominalSemiannual;
		break;
	case NOMINAL_QUARTERLY:
		rateBasis = RateReturnFreqType::NominalQuarterly;
		break;
	case NOMINAL_MONTHLY:
		rateBasis = RateReturnFreqType::NominalMonthly;
		break;
	case ACTUAL_SEMIANNUAL:
		rateBasis = RateReturnFreqType::Semiannual;
		break;
	case ACTUAL_QUARTERLY:
		rateBasis = RateReturnFreqType::Quarterly;
		break;
	case ACTUAL_MONTHLY:
		rateBasis = RateReturnFreqType::Monthly;
		break;
	case -1:	
		rateBasis = RateReturnFreqType::EffectiveAnnual;
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'rate_return_basis' passed to 'get_infl_rate'");
		break;	 	
	}

double infl_rate = 0.0;
date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable

if (infl_defn == DETERMINISTIC)
	infl_rate = infl_deterministic;

else // alm_flag || infl_defn == STOCHASTIC
	{	
	if (find(misc_list.begin(), misc_list.end(), "Infl") == misc_list.end())
		return 0.0;
	
	xstring map_index = "Infl_" + xstring(t);
	
	if (infl_rates.find(map_index) != infl_rates.end())
		infl_rate = infl_rates[map_index];
	else
		{
		econ_err_code 
		= Econ->GetInflationRate(t + proj_date_offset, 
								 "USA", 
								 "Infl", 
								 RateReturnFreqType::EffectiveAnnual, 
								 infl_rate);
		
		if (econ_err_code != ECON_OK)
			econ_rate_error_processing(t, "Infl", econ_err_code);
	
		infl_rates[map_index] = infl_rate;
		}
	}

if (return_rate_basis == EFFECTIVE_ANNUAL || fabs(infl_rate) < rate_ratio_threshold)
	return infl_rate;

return convert_rate_basis(infl_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_int_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_int_rate(int t, const xstring &quality_id_input, int rate_type, double rate_term_input, double fwd_term, int return_rate_basis, int shift_type, double portfolio_sprd_adj_aig )//AIG - PORTFOLIO SPREAD ADJ //WTW - Gen2 - no default parameters
{
// The parameters for this function are defined as follows: 
//     t:                       The time period for the rate
//     quality_id_input:        The quality grade used in the scenario file, e.g. "Govt", "AA", "B"
//     rate_type:               The type of rate to retrieve, e.g. GET_YIELD_RATE
//     rate_term_input:         Yield curve term for the rate. e.g. 0.25, 1.0, 5.0
//     fwd_rate:                Yield curve term for the forward rate, e.g. 0.25, 1.0, 5.0 
//                                 (pass zero if rate_type != GET_FORWARD_RATE)
//     return_rate_basis:       Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//     shift_type               The type of shift to apply, e.g. YIELD_SHIFT
//
// The following table lists valid rate_type values.  
//   = GET_YIELD_RATE                 for yield rate (requires term to maturity)
//   = GET_SPOT_RATE                  for spot rate (requires term to maturity)
//   = GET_FORWARD_RATE               for forward rate (requires term to maturity, and forward term)
//   = GET_SPOT_SPREAD                for spot spread to risk free bond equivalent (BE) spot rates (requires term to maturity)
//   = GET_YIELD_SPREAD               for yield spread to risk free bond equivalent (BE) yield rates (requires term to maturity)
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY
//
// The following table lists valid shift_type values.  
//   = NO_SHIFT                 no shift applies
//   = SPOT_SHIFT               spot rate shifts are specified
//   = YIELD_SHIFT              yield rate shifts are specified

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		break;
	case NOMINAL_SEMIANNUAL:
		break;
	case NOMINAL_QUARTERLY:
		break;
	case NOMINAL_MONTHLY:
		break;
	case ACTUAL_SEMIANNUAL:
		break;
	case ACTUAL_QUARTERLY:
		break;
	case ACTUAL_MONTHLY:
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'return_rate_basis' passed to 'get_int_rate' function.");
		break;	 	
	}

char qual_id[MAX_ID_LEN + 1];

if (fabs(rate_term_input) < rate_ratio_threshold)
	return 0.0;

strncpy(qual_id, quality_id_input.c_str(), MAX_ID_LEN + 1);

xstring map_index = quality_id_input + "_" + xstring(t) 
                    + "_" + xstring(xint(rate_term_input * 12))
					+ "_" + xstring(round(portfolio_sprd_adj_aig,6)); //AIG - ADD PORTFOLIO ADJUSTMENT TO MAP INDEX

// Set lookup keys
rate_term = rate_term_input;
quality_id = quality_id_input;
double credit_sprd_intercept_aig_local = credit_sprd_intercept_aig; //WTW - Gen2 - Mutating Lookup Term used in expression
rate_term = rate_term_input;
quality_id = quality_id_input;
double credit_sprd_slope_aig_local = credit_sprd_slope_aig;//WTW - Gen2 - Mutating Lookup Term used in expression

if (rate_type == GET_SPOT_SPREAD)
	{
	double sprd = 0.0;
	double risk_free_rate = 0.0;
	double risk_adj_rate = 0.0;

	if (quality_id_input == "Govt")
		{
		sprd = 0.0;

		if (shift_type == SPOT_SHIFT)
			sprd += SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION;
		}
	else if (credit_sprd_defn == SPOT_SPREADS)
		{
		if (find(yld_curve_list.begin(), yld_curve_list.end(), quality_id_input) != yld_curve_list.end())
			{
			econ_err_code 
			= Econ->GetInterestRate(t + proj_date_offset, 
									"USA", 
									qual_id, 
									YieldRateType::Spot, 
									rate_term_input, 
									RateReturnFreqType::NominalSemiannual, 
									risk_adj_rate);

			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			econ_err_code 
			= Econ->GetInterestRate(t + proj_date_offset, 
									"USA", 
									"Govt", 
									YieldRateType::Spot, 
									rate_term_input, 
									RateReturnFreqType::NominalSemiannual, 
									risk_free_rate);

			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			sprd = risk_adj_rate - risk_free_rate;
			}
		else // Get user specified spot spread
			{
			// Deterministic risk spread - lookup keys: date(t), term, and quality_id
			//sprd = credit_sprd_deterministic; //AIG - ORIGINAL CODE
			//AIG - CALCULATE REINVESTMENT SPREAD USING SLOPE, INTERCEPT, AND TREAS	
			if (yld_curve_list.size() > 0)
				{
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										"Govt", 
										YieldRateType::Spot, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										risk_free_rate);
	
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);	
				}

			quality_id = quality_id_input;//WTW - Gen2 - Mutating Lookup Term
			rate_term = rate_term_input;//WTW - Gen2 - Mutating Lookup Term
			sprd = risk_free_rate * (credit_sprd_slope_aig_local - 1.0) 
					+ credit_sprd_intercept_aig_local
					+ portfolio_sprd_adj_aig;

			// Get stochastic credit spread
			if (yld_curve_list.size() > 0)
				{
				double mult = 0.0;
	
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										"Govt", 
										YieldRateType::Spot, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										risk_free_rate);
	
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);
		
				for (int yld_curve = 0; yld_curve < yld_curve_list.size(); yld_curve++)
					{
					// Set lookup key
					yld_curve_id = xstring(yld_curve_list[yld_curve]);
				
					// Lookup keys: date(t), yield_curve_id, and quality_id
					quality_id = quality_id_input;//WTW - Gen2 - Mutating Lookup Term
					mult = credit_sprd_stoch_mult; 

					if (fabs(mult) > rate_ratio_threshold)
						{
						char row_id[MAX_ID_LEN + 1];
						strncpy(row_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);

						econ_err_code 
						= Econ->GetInterestRate(t + proj_date_offset, 
												"USA", 
												row_id, 
												YieldRateType::Spot, 
												rate_term_input, 
												RateReturnFreqType::NominalSemiannual, 
												risk_adj_rate);
			
						if (econ_err_code != ECON_OK)
							econ_rate_error_processing(t, quality_id_input, econ_err_code);
		
						sprd += mult * (risk_adj_rate - risk_free_rate);
						}
					}
				}
			}

		if (shift_type == SPOT_SHIFT)
			sprd += SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION;
		}
	else // credit_sprd_defn == YIELD_SPREADS
		{
		risk_adj_rate = calc_spot_from_yld(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig); 
	
		risk_free_rate = calc_spot_from_yld(t, "Govt", rate_term_input, shift_type, 0); 

		sprd = risk_adj_rate - risk_free_rate;
		}

	if (return_rate_basis == NOMINAL_SEMIANNUAL || fabs(sprd) < rate_ratio_threshold)
		return sprd;

	return convert_rate_basis(sprd, NOMINAL_SEMIANNUAL, return_rate_basis);
	}	
else if (rate_type == GET_YIELD_SPREAD)
	{
	double sprd = 0.0;
	double risk_free_rate = 0.0;
	double risk_adj_rate = 0.0;

	if (quality_id_input == "Govt")
		{
		sprd = 0.0;
		}
	else if (credit_sprd_defn == YIELD_SPREADS)
		{
		if (find(yld_curve_list.begin(), yld_curve_list.end(), quality_id_input) != yld_curve_list.end())
			{
			econ_err_code 
			= Econ->GetInterestRate(t + proj_date_offset, 
									"USA", 
									qual_id, 
									YieldRateType::Bond, 
									rate_term_input, 
									RateReturnFreqType::NominalSemiannual, 
									risk_adj_rate);

			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			econ_err_code 
			= Econ->GetInterestRate(t + proj_date_offset, 
									"USA", 
									"Govt", 
									YieldRateType::Bond, 
									rate_term_input, 
									RateReturnFreqType::NominalSemiannual, 
									risk_free_rate);

			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			sprd = risk_adj_rate - risk_free_rate;
			}
		else // Get user specified yield spread
			{
			// Deterministic risk spread - lookup keys: date(t), term, and quality_id
			//sprd = credit_sprd_deterministic; //AIG - ORIGINAL CODE
			//AIG - CALCULATE REINVESTMENT SPREAD USING SLOPE, INTERCEPT, AND TREAS			
			if (yld_curve_list.size() > 0)
				{
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										"Govt", 
										YieldRateType::Bond, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										risk_free_rate);
	
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);
				}
			
			quality_id = quality_id_input;//WTW - Gen2 - Mutating Lookup Term
			rate_term = rate_term_input;//WTW - Gen2 - Mutating Lookup Term
			sprd = risk_free_rate * (credit_sprd_slope_aig_local - 1.0) 
					+ credit_sprd_intercept_aig_local
					+ portfolio_sprd_adj_aig;

			// Get stochastic credit spread
			if (yld_curve_list.size() > 0)
				{
				double mult = 0.0;
	
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										"Govt", 
										YieldRateType::Bond, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										risk_free_rate);
	
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);
		
				for (int yld_curve = 0; yld_curve < yld_curve_list.size(); yld_curve++)
					{
					// Set lookup key
					quality_id = quality_id_input;//WTW - Gen2 - Mutating Lookup Term
					yld_curve_id = xstring(yld_curve_list[yld_curve]);
				
					// Lookup keys: date(t), yield_curve_id, and quality_id
					mult = credit_sprd_stoch_mult; 

					if (fabs(mult) > rate_ratio_threshold)
						{
						char row_id[MAX_ID_LEN + 1];
						strncpy(row_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);

						econ_err_code 
						= Econ->GetInterestRate(t + proj_date_offset, 
												"USA", 
												row_id, 
												YieldRateType::Bond, 
												rate_term_input, 
												RateReturnFreqType::NominalSemiannual, 
												risk_adj_rate);
			
						if (econ_err_code != ECON_OK)
							econ_rate_error_processing(t, quality_id_input, econ_err_code);
		
						sprd += mult * (risk_adj_rate - risk_free_rate);
						}
					}
				}
			}
		}
	else // credit_sprd_defn == SPOT_SPREADS
		{
		risk_adj_rate = calc_yld_from_spot(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig); 
	
		risk_free_rate = calc_yld_from_spot(t, "Govt", rate_term_input, shift_type, 0); 

		sprd = risk_adj_rate - risk_free_rate;
		}

	if (return_rate_basis == NOMINAL_SEMIANNUAL || fabs(sprd) < rate_ratio_threshold)
		return sprd;

	return convert_rate_basis(sprd, NOMINAL_SEMIANNUAL, return_rate_basis);
	}	
else if (rate_type == GET_YIELD_RATE)
	{
	double rate = 0.0;

	if (shift_type == NO_SHIFT
		&& yld_rates.find(map_index) != yld_rates.end())
		rate = yld_rates[map_index];

	else if (shift_type != NO_SHIFT
		     && yld_rates_shifted.find(map_index) != yld_rates_shifted.end())
		rate = yld_rates_shifted[map_index];

	else // Must retrieve rate
		{
		double risk_free_rate = 0.0;
		double sprd = 0.0;
		double yld_rate = 0.0;
	
		if (find(yld_curve_list.begin(), yld_curve_list.end(), quality_id_input) != yld_curve_list.end())
			{
			if (shift_type == NO_SHIFT || shift_type == YIELD_SHIFT)
				{
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										qual_id, 
										YieldRateType::Bond, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										yld_rate);
		
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);
	
				if (shift_type == YIELD_SHIFT)
					{
					xstring shift_map_index = "Govt_" + xstring(xint(rate_term_input * 12));
					double shift = yld_rates_shifts[shift_map_index];

					double yld_rate_eff = convert_rate_basis(yld_rate, NOMINAL_SEMIANNUAL, EFFECTIVE_ANNUAL);
					double yld_rate_shifted = max(0.0, yld_rate_eff + shift);
					double yld_rate_bey = convert_rate_basis(yld_rate_shifted, EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);

					rate = yld_rate_bey;
					yld_rates_shifted[map_index] = rate;
					}
				else
					{
					rate = yld_rate;

					yld_rates[map_index] = rate;
					}
				}
			else // shift_type == SPOT_SHIFT, create full yield curve from shifted spot curve
				{
				rate = calc_yld_from_spot(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig);

				// rate is already saved to map inside calc_yld_from_spot
				}
			}
		else // user defined yield curve
			{
			if (credit_sprd_defn == YIELD_SPREADS)
				{
				if (shift_type == NO_SHIFT || shift_type == YIELD_SHIFT)
					{
					econ_err_code 
					= Econ->GetInterestRate(t + proj_date_offset, 
											"USA", 
											"Govt", 
											YieldRateType::Bond, 
											rate_term_input, 
											RateReturnFreqType::NominalSemiannual, 
											risk_free_rate);
	
					if (econ_err_code != ECON_OK)
						econ_rate_error_processing(t, quality_id_input, econ_err_code);

					if (shift_type == YIELD_SHIFT)
						{
						xstring shift_map_index = "Govt_" + xstring(xint(rate_term_input * 12));
						double shift = yld_rates_shifts[shift_map_index];

						double yld_rate_eff = convert_rate_basis(risk_free_rate, NOMINAL_SEMIANNUAL, EFFECTIVE_ANNUAL);
						double yld_rate_shifted = max(0.0, yld_rate_eff + shift);
						double yld_rate_bey = convert_rate_basis(yld_rate_shifted, EFFECTIVE_ANNUAL, NOMINAL_SEMIANNUAL);

						risk_free_rate = yld_rate_bey;
						}
	
					sprd = get_int_rate(t, quality_id_input, GET_YIELD_SPREAD, rate_term_input, 0, NOMINAL_SEMIANNUAL, NO_SHIFT, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					rate = risk_free_rate + sprd;
	
					if (shift_type == YIELD_SHIFT)
						yld_rates_shifted[map_index] = rate;
					else // shift_type == NO_SHIFT
						yld_rates[map_index] = rate;
					}
				else // shift_type == SPOT_SHIFT, create the full yield curve from the shifted spot curve
					{
					// Create shifted risk free yield rate from shifted risk free spot rate, then add credit spread	
					risk_free_rate = get_int_rate(t, "Govt", GET_YIELD_RATE, rate_term_input, 0, NOMINAL_SEMIANNUAL, shift_type, 0); //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					sprd = get_int_rate(t, quality_id_input, GET_YIELD_SPREAD, rate_term_input, 0, NOMINAL_SEMIANNUAL, NO_SHIFT, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					rate = risk_free_rate + sprd;

					yld_rates_shifted[map_index] = rate;
					}
				}
			else // credit_sprd_defn == SPOT_SPREADS, create the full yield curve from the spot curve
				{				
				rate = calc_yld_from_spot(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig);

				// rate is already saved to map inside calc_yld_from_spot
				}
			}
		}

	if (return_rate_basis == NOMINAL_SEMIANNUAL || fabs(rate) < rate_ratio_threshold)
		return rate;

	return convert_rate_basis(rate, NOMINAL_SEMIANNUAL, return_rate_basis);
	}
else if (rate_type == GET_SPOT_RATE)
	{
	double rate = 0.0;
	
	if (shift_type == NO_SHIFT
		&& spot_rates.find(map_index) != spot_rates.end())
		rate = spot_rates[map_index];


	else if (shift_type != NO_SHIFT
		     && spot_rates_shifted.find(map_index) != spot_rates_shifted.end())
		rate = spot_rates_shifted[map_index];

	else // Must retrieve rate
		{
		double risk_free_rate = 0.0;
		double sprd = 0.0;

		if (find(yld_curve_list.begin(), yld_curve_list.end(), quality_id_input) != yld_curve_list.end())
			{
			if (shift_type == NO_SHIFT || shift_type == SPOT_SHIFT)
				{
				econ_err_code 
				= Econ->GetInterestRate(t + proj_date_offset, 
										"USA", 
										qual_id, 
										YieldRateType::Spot, 
										rate_term_input, 
										RateReturnFreqType::NominalSemiannual, 
										rate);
		
				if (econ_err_code != ECON_OK)
					econ_rate_error_processing(t, quality_id_input, econ_err_code);

				if (shift_type == SPOT_SHIFT)
					{
					rate += SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION; 

					spot_rates_shifted[map_index] = rate;
					}
				else // shift_type == NO_SHIFT
					spot_rates[map_index] = rate;
				}
			else // shift_type == YIELD_SHIFT, create shifted spot curve from shifted yield curve
				{
				rate = calc_spot_from_yld(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig);

				// rate is already saved to map inside calc_spot_from_yld
				}
			}
		else // user defined yield curve
			{
			if (credit_sprd_defn == SPOT_SPREADS)
				{
				if (shift_type == NO_SHIFT || shift_type == SPOT_SHIFT)
					{
					econ_err_code 
					= Econ->GetInterestRate(t + proj_date_offset, 
											"USA", 
											"Govt", 
											YieldRateType::Spot, 
											rate_term_input, 
											RateReturnFreqType::NominalSemiannual, 
											risk_free_rate);
					
					if (econ_err_code != ECON_OK)
						econ_rate_error_processing(t, quality_id_input, econ_err_code);
	
					sprd = get_int_rate(t, quality_id_input, GET_SPOT_SPREAD, rate_term_input, 0, NOMINAL_SEMIANNUAL, NO_SHIFT, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					rate = risk_free_rate + sprd;
	
					if (shift_type == SPOT_SHIFT)
						{
						rate += SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION;
		
						spot_rates_shifted[map_index] = rate;
						}
					else // shift_type == NO_SHIFT
						spot_rates[map_index] = rate;
					}	
				else // shift_type == YIELD_SHIFT so create the full spot curve from the shifted yield curve
					{
					// Create shifted risk free spot rate from shifted risk free yield rate, then add credit spread	
					risk_free_rate = get_int_rate(t, "Govt", GET_SPOT_RATE, rate_term_input, 0, NOMINAL_SEMIANNUAL, shift_type, 0); //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					sprd = get_int_rate(t, quality_id_input, GET_SPOT_SPREAD, rate_term_input, 0, NOMINAL_SEMIANNUAL, NO_SHIFT, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

					rate = risk_free_rate + sprd;

					spot_rates_shifted[map_index] = rate;
					}
				}
			else // credit_sprd_defn == YIELD_SPREADS, create the full spot curve from the risk adjusted yield curve
				{
				rate = calc_spot_from_yld(t, quality_id_input, rate_term_input, shift_type, portfolio_sprd_adj_aig);
				}
			// rate is already saved to map inside calc_spot_from_yld
			}
		}

	if (return_rate_basis == NOMINAL_SEMIANNUAL || fabs(rate) < rate_ratio_threshold)
		return rate;

	return convert_rate_basis(rate, NOMINAL_SEMIANNUAL, return_rate_basis);
	}
else if (rate_type == GET_FORWARD_RATE)
	{
	if (fwd_term == 0)
		return 0.0;
	
	double rate = 0.0;
	double rate_start_term = 0.0;
	double rate_end_term = 0.0;

	rate_start_term
	= get_int_rate(t, quality_id_input, GET_SPOT_RATE, rate_term_input, 0, NOMINAL_SEMIANNUAL, shift_type, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
	rate_end_term
	= get_int_rate(t, quality_id_input, GET_SPOT_RATE, rate_term_input + fwd_term, 0, NOMINAL_SEMIANNUAL, shift_type, portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
	rate = (pow(pow(1.0 + rate_end_term
						  / NOMINAL_SEMIANNUAL,
					rate_term_input + fwd_term)
				/ pow(1.0 + rate_start_term
							/ NOMINAL_SEMIANNUAL,
					  rate_term_input),
				1.0 / fwd_term) - 1.0)
		   * NOMINAL_SEMIANNUAL;

	if (return_rate_basis == NOMINAL_SEMIANNUAL || fabs(rate) < rate_ratio_threshold)
		return rate;

	return convert_rate_basis(rate, NOMINAL_SEMIANNUAL, return_rate_basis);
	}
else
	throw FatalError("Invalid 'rate_type' passed to 'get_int_rate' function.");

//return 0.0;//WTW - Gen2 - return will never get called
}



#line 1 "get_int_vol.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_int_vol(int t, const xstring &quality_id_input, double moneyness_input, double rate_term_input, int return_rate_basis)
{
// The parameters for this function are defined as follows: 
//     t:                 The time period for the rate
//     quality_id_input:  The quality grade used in the scenario file, e.g. "Govt", "AA", "B"
//     moneyness_input:   Moneyness level for the volatility, e.g. 1.00, 0.95, 1.05
//     rate_term_input:   Yield curve term for the volatility, e.g. 0.25, 1.0, 5.0
//     return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		break;
	case NOMINAL_SEMIANNUAL:
		break;
	case NOMINAL_QUARTERLY:
		break;
	case NOMINAL_MONTHLY:
		break;
	case ACTUAL_SEMIANNUAL:
		break;
	case ACTUAL_QUARTERLY:
		break;
	case ACTUAL_MONTHLY:
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		break;
	default:
		throw FatalError("Invalid 'return_rate_basis' passed to 'get_int_vol' function.");
		break;	 	
	}

char qual_id[MAX_ID_LEN + 1];
double vol_rate = 0.0;
xstring map_index;

if (fabs(rate_term_input) < rate_ratio_threshold)
	return 0.0;

xstring vol_id;

// Set lookup key	
quality_id = quality_id_input;
moneyness = moneyness_input;
rate_term = rate_term_input;

if (yld_curve_vol_surface_list.find(quality_id_input) != yld_curve_vol_surface_list.end())
	{
	strncpy(qual_id, quality_id_input.c_str(), MAX_ID_LEN + 1);

	range_pair = yld_curve_vol_surface_list.equal_range(quality_id_input);

	double high_moneyness = 99.0;
	double low_moneyness = 0.0;
	double moneyness_val = 0.0;
	
	for (iter = range_pair.first; iter != range_pair.second; iter++)
		{
		moneyness_val = iter->second;

		if (fabs(moneyness_input - moneyness_val) < rate_ratio_threshold)
			break;

		if (moneyness_input > moneyness_val
			&& low_moneyness < moneyness_val)
			low_moneyness = moneyness_val;
			
		if (moneyness_input < moneyness_val
			&& high_moneyness > moneyness_val)
			high_moneyness = moneyness_val;	
		}

	if (fabs(moneyness_val - moneyness_input) < rate_ratio_threshold)
		{ // Exact match, retrieve result
		map_index 
		= quality_id_input + "_" 
		  + xstring(moneyness_input) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (int_vols.find(map_index) != int_vols.end())
			vol_rate = int_vols[map_index];
		else
			{
			econ_err_code 
			= Econ->GetInterestVolatility(t + proj_date_offset, 
										  "USA", 
										  qual_id, 
										  moneyness_input, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);
			
			int_vols[map_index] = vol_rate;	
			}
		}						
	else if (high_moneyness == 99.0)
		{ // Use highest moneyness level
		map_index 
		= quality_id_input + "_" 
		  + xstring(low_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (int_vols.find(map_index) != int_vols.end())
			vol_rate = int_vols[map_index];
		else
			{
			econ_err_code 
			= Econ->GetInterestVolatility(t + proj_date_offset, 
										  "USA", 
										  qual_id, 
										  low_moneyness, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			int_vols[map_index] = vol_rate;
			}
		}
	else if (fabs(low_moneyness) < rate_ratio_threshold)
		{ // Use lowest moneyness level
		map_index 
		= quality_id_input + "_" 
		  + xstring(high_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (int_vols.find(map_index) != int_vols.end())
			vol_rate = int_vols[map_index];
		else
			{
			econ_err_code 
			= Econ->GetInterestVolatility(t + proj_date_offset, 
										  "USA", 
										  qual_id, 
										  high_moneyness, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			int_vols[map_index] = vol_rate;
			}
		}
	else // Interpolate between two specified levels
		{
		double vol_rate1 = 0.0;
		double vol_rate2 = 0.0;

		map_index 
		= quality_id_input + "_" 
		  + xstring(high_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (int_vols.find(map_index) != int_vols.end())
			vol_rate1 = int_vols[map_index];
		else
			{
			econ_err_code 
			= Econ->GetInterestVolatility(t + proj_date_offset, 
										  "USA", 
										  qual_id, 
										  high_moneyness, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate1);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			int_vols[map_index] = vol_rate1;
			}

		map_index 
		= quality_id_input + "_" 
		  + xstring(low_moneyness) + "_" 
		  + xstring(rate_term_input) + "_" 
		  + xstring(t);

		if (int_vols.find(map_index) != int_vols.end())
			vol_rate2 = int_vols[map_index];
		else
			{
			econ_err_code 
			= Econ->GetInterestVolatility(t + proj_date_offset, 
										  "USA", 
										  qual_id, 
										  low_moneyness, 
										  rate_term_input, 
										  RateReturnFreqType::EffectiveAnnual, 
										  vol_rate2);
	
			if (econ_err_code != ECON_OK)
				econ_rate_error_processing(t, quality_id_input, econ_err_code);

			int_vols[map_index] = vol_rate2;
			}

		vol_rate 
		= (vol_rate2 
		   * (high_moneyness - moneyness_input)
		   + vol_rate1	
		     * (moneyness_input - low_moneyness))
		   / (high_moneyness - low_moneyness);
		}
	}
else // Use user specified volatilities
	{
	// Deterministic volatility rate - lookup keys: date(t), quality_id, rate_term, and moneyness
	date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
	quality_id = quality_id_input; //WTW - Gen2 - Mutating Lookup Term
	moneyness = moneyness_input; //WTW - Gen2 - Mutating Lookup Term
	rate_term = rate_term_input; //WTW - Gen2 - Mutating Lookup Term
	vol_rate = int_vol_deterministic; //WTW - Gen2 - Mutating Lookup Term

	// Get stochastic volatilities
	double vol_stoch = 0.0;
	double mult = 0.0;

	for (int yld_curve = 0; yld_curve < yld_curve_list.size(); yld_curve++)
		{
		// Set lookup key
		yld_curve_id = xstring(yld_curve_list[yld_curve]);
		
		// lookup keys: yield_curve_id, and quality_id		
		quality_id = quality_id_input; //WTW - Gen2 - Mutating Lookup Term
		mult = int_vol_stoch_mult; 

		if (fabs(mult) > rate_ratio_threshold)
			{
			// Save lookup key
			xstring quality_id_saved = quality_id;

			vol_stoch = get_int_vol(t, yld_curve_id, moneyness_input, rate_term_input, EFFECTIVE_ANNUAL);

			// Restore lookup key
			quality_id = quality_id_saved;

			vol_rate += mult * vol_stoch;
			}
		}
	}

if (return_rate_basis == EFFECTIVE_ANNUAL || fabs(vol_rate) < rate_ratio_threshold)
	return vol_rate;

return convert_rate_basis(vol_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_misc_rate.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_misc_rate(int t, const xstring &misc_rate_id, int return_rate_basis)
{
// This function is used to retrieve specific miscellaneous rates from
// the SOA ESML scenario structures.
//
// The parameters for this function are defined as follows: 
//     t:                 The time period for the rate
//     return_rate_basis: Return basis for the rate, e.g. EFFECTIVE_ANNUAL
//
// The following table lists valid return_rate_basis values and their
// corresponding system variables.  These system variables can be used
// in place of the listed basis values.  
//
// Basis Value  Description         System Variable
// -----------  ------------------  ---------------------
//       1      effective annual    EFFECTIVE_ANNUAL
//       2      nominal semiannual  NOMINAL_SEMIANNUAL
//       4      nominal quarterly   NOMINAL_QUARTERLY
//      12      nominal monthly     NOMINAL_MONTHLY
//      -2      semiannual		    ACTUAL_SEMIANNUAL
//      -4      quarterly           ACTUAL_QUARTERLY  
//     -12      monthly             ACTUAL_MONTHLY

// Note: When retrieving the beta factor, you should always use a return_rate_basis of EFFECTIVE_ANNUAL.
//       Conversion of the beta is not appropriate since the beta represents a monthly accumulation factor 
//       and not a rate.


RateReturnFreqType rateBasis;

switch (return_rate_basis)
	{
	case EFFECTIVE_ANNUAL:
		rateBasis = RateReturnFreqType::EffectiveAnnual;
		break;
	case NOMINAL_SEMIANNUAL:
		rateBasis = RateReturnFreqType::NominalSemiannual;
		break;
	case NOMINAL_QUARTERLY:
		rateBasis = RateReturnFreqType::NominalQuarterly;
		break;
	case NOMINAL_MONTHLY:
		rateBasis = RateReturnFreqType::NominalMonthly;
		break;
	case ACTUAL_SEMIANNUAL:
		rateBasis = RateReturnFreqType::Semiannual;
		break;
	case ACTUAL_QUARTERLY:
		rateBasis = RateReturnFreqType::Quarterly;
		break;
	case ACTUAL_MONTHLY:
		rateBasis = RateReturnFreqType::Monthly;
		break;
	case -1:
		return_rate_basis = EFFECTIVE_ANNUAL;
		rateBasis = RateReturnFreqType::EffectiveAnnual;
		break;
	default:
		throw FatalError("Invalid 'rate_return_basis' passed to 'get_misc_rate'");
		break;	 	
	}

double misc_rate = 0.0;

xstring map_index = misc_rate_id + "_" + xstring(t);

if (misc_rates.find(map_index) != misc_rates.end())
	misc_rate = misc_rates[map_index];
else
	{
	char misc_id[MAX_ID_LEN + 1];
	strncpy(misc_id, misc_rate_id.c_str(), MAX_ID_LEN + 1);
	
	econ_err_code 
	= Econ->GetMiscRate(t + proj_date_offset, 
						"USA", 
						misc_id, 
						RateReturnFreqType::EffectiveAnnual, 
						misc_rate);
	
	if (econ_err_code != ECON_OK)
		econ_rate_error_processing(t, misc_rate_id, econ_err_code);

	misc_rates[map_index] = misc_rate;
	}

if (return_rate_basis == EFFECTIVE_ANNUAL || fabs(misc_rate) < rate_ratio_threshold)
	return misc_rate;

return convert_rate_basis(misc_rate, EFFECTIVE_ANNUAL, return_rate_basis);
}



#line 1 "get_risk_free_rate_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::get_risk_free_rate_aig(int t)
{
	// 20180626 MTC
	double monthly_effective_risk_free_rate = get_misc_rate(t, "RiskFree", ACTUAL_MONTHLY);
  
	return monthly_effective_risk_free_rate;
}



#line 1 "linear_interpolation_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::linear_interpolation_aig(double lookup_value, vector <double> lookups, vector <double> values)
{
	/*! Linear Interpolation
		====================
		@author Michael Ching
		@date 20181217
 
		This function is a <a href="https://en.wikipedia.org/wiki/Linear_interpolation">linear interpolation</a> 
		and <a href="https://en.wikipedia.org/wiki/Extrapolation">linear extrapolation</a>.
 
		@param[in] lookup_value A lookup value.
		@param[in] lookups A vector of lookup indices.
		@param[in] values A vector that contains values over which it interpolate.
 
		Related Inputs:
		---------------
		None.
 
		@return A value resulting from the linear interpolation algorithm.
	*/

	/*THIS ALGORITHM IS NEITHER TESTED NOR USED. DO NOT USE WITHOUT TESTING*/

	// Initialize
	vector<double> x_elements = lookups;
	vector<double> y_elements = values;
	double x = lookup_value;

	int x_element_count = x_elements.size();
	int y_element_count = y_elements.size();

	// Check number of interpolation points
	if (x_element_count < 2)
	{
		throw FatalError("Requested an interpolation with less than two points in rates->linear_interpolation_aig!");
	}

	// Check lookup and value points
	if (x_element_count != y_element_count)
	{
		throw FatalError("Requested lookups and values are different sizes in rates->linear_interpolation_aig!");
	}

	// Check for monotonically increasing x
	for (int i = 0; i < x_element_count - 1; i ++)
	{
		if (x_elements[i] <= x_elements[i + 1])
		{
			throw FatalError("Requested lookups are not monotonically increasing in rates->linear_interpolation_aig!");
		}
	}

	// Determine lookup values
	double x_0;
	double x_1;
	double y_0;
	double y_1;

	if (x <= x_elements[0])
	{
		// Get first and second elements
		x_0 = x_elements[0];
		x_1 = x_elements[1];
		y_0 = y_elements[0];
		y_1 = y_elements[1];
	}
	else if (x > x_elements[x_element_count])
	{
		// Get last and second-to-last elements
		x_0 = x_elements[x_element_count - 1];
		x_1 = x_elements[x_element_count];
		y_0 = y_elements[x_element_count - 1];
		y_1 = y_elements[x_element_count];
	}
	else
	{
		// Get elements somewhere in between
		bool found_segment = false;

		for (int i = 0; i < x_element_count - 1; i++)
		{
			x_0 = x_elements[i];
			x_1 = x_elements[i + 1];
			y_0 = y_elements[i];
			y_1 = y_elements[i + 1];

			if (x > x_0 && x <= x_1)
			{
				found_segment = true;
				break;
			}
		}

		if (!found_segment)
		{
			throw FatalError("Linear interpolation failed to find segment in rates->linear_interpolation_aig!");
		}
	}

	// Calculate interpolation
	double y = (y_0 * (x_1 - x) + y_1 * (x - x_0)) /
			   (x_1 - x_0);
	
	return y;
}



#line 1 "scen_rates_load.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::scen_rates_load(int scen_num)
{
// Clear base rate maps
yld_rates_shifts.clear();
index_vols_shifts.clear();
spot_rates.clear();
spot_rates_shifted.clear();
yld_rates.clear();
yld_rates_shifted.clear();
int_vols.clear();
index_rates.clear();
index_vols.clear();
index_vols_shifted.clear();
fx_rates.clear();
infl_rates.clear();
dflt_rates.clear();
misc_rates.clear();

econ_err_code = Econ->ScenLoadProjRates(scen_num);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

return;
}



#line 1 "scen_set_info_load.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::scen_set_info_load(void)
{
char scen_file[MAX_PATH_LEN];
char hist_file[MAX_PATH_LEN];

// Copy data from historic_rates_id to inner_loop_historic_rates_id
// since the historic rates information must be the same
inner_loop_historic_rates_id = historic_rates_id;

xstring file_path;
xstring file_name;
xstring file_addn = "";
xstring new_file_name;
xstring new_hist_id;
xstring new_scen_id;

if (!time_step_flag
	|| (time_step_flag && (!valn_flag || hedge_valn_final_flag)))
	{	
	if (!hedge_valn_shock_flag) // use specified files
		{
		strncpy(hist_file, replaceWildcards(historic_rates_id.c_str()), MAX_PATH_LEN);
		strncpy(scen_file, replaceWildcards(scen_id.c_str()), MAX_PATH_LEN);
		}
	else // hedge_valn_shock_flag - use special shocked scenario files, stored in 'Scenarios\Generated' folder
		{
		xstring hedge_valn_shock_id_full = hedge_valn_shock_list[proj_task_loop_num - 1];
		xstring hedge_valn_shock_id = hedge_valn_shock_id_full(0, hedge_valn_shock_id_full.find("|TaskLoopIncr"));

		// set lookup key and retrieve scen_file_name_addn
		shock_id = hedge_valn_shock_id;
		file_addn = "_" + scen_file_name_addn;

		// Create new historic rates file name
		file_path = replaceWildcards(gen_scen_file_path);
		file_name = get_file_name(replaceWildcards(historic_rates_id));
		new_file_name = file_name + file_addn;
		new_hist_id = file_path + new_file_name + ".csv"; 

		// Create new scenario file name
		file_path = replaceWildcards(gen_scen_file_path);
		file_name = get_file_name(scen_id);
		new_file_name = file_name + file_addn;
		new_scen_id = file_path + new_file_name + ".csv"; 

		// register the files
		new_hist_id = replaceWildcards(new_hist_id);
		new_scen_id = replaceWildcards(new_scen_id);

		// Create new scenario and historical file names
		strncpy(hist_file, new_hist_id.c_str(), MAX_PATH_LEN);
		strncpy(scen_file, new_scen_id.c_str(), MAX_PATH_LEN);
		}
	}
else
	{	
	if (valn_period > 0 
		|| (valn_period == 0 && gen_initial_valn_period == YES)
		|| hedge_valn_shock_flag)
		{
		if (hedge_valn_shock_flag) // capture scenario file name addition
			{
			xstring hedge_valn_shock_id_full = hedge_valn_shock_list[proj_task_loop_num - 1];
			xstring hedge_valn_shock_id = hedge_valn_shock_id_full(0, hedge_valn_shock_id_full.find("|TaskLoopIncr"));

			// set lookup key and retrieve scen_file_name_addn
			shock_id = hedge_valn_shock_id;
			file_addn = "_" + scen_file_name_addn;
			}
		
		if (hedge_valn_final_flag)//Reference Baseline timestep file names
			file_addn = "_Baseline";
			
		// Create new historic rates file name
		file_path = replaceWildcards(gen_scen_file_path);
		file_name = get_file_name(inner_loop_historic_rates_id);

		if (save_time_step_scen_files_defn == YES)
			new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);
		else
			new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num);

		new_hist_id = file_path + new_file_name + ".csv"; 
	
		// Create new scenario file name
		file_path = replaceWildcards(gen_scen_file_path);
		file_name = get_file_name(inner_loop_valn_scen_id);

		if (save_time_step_scen_files_defn == YES)
			new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);
		else
			new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num);

		// Always use new scenario files for hedge valuations
		if (inner_loop_valn_scen_reuse_defn != ALL_RATES || hedge_valn_shock_flag) 
			new_scen_id = file_path + new_file_name + ".csv"; 
		else
			// Always reference the specified inner loop scenario file
			new_scen_id = inner_loop_valn_scen_id;

		// register the files
		new_hist_id = replaceWildcards(new_hist_id);
		new_scen_id = replaceWildcards(new_scen_id);
		}
	else
		{
		// Use the names specified in the input fields for the first inner loop valuation
		new_hist_id = replaceWildcards(inner_loop_historic_rates_id);
		new_scen_id = replaceWildcards(inner_loop_valn_scen_id);
		}

	// Create new scenario and historical file names
	strncpy(hist_file, new_hist_id.c_str(), MAX_PATH_LEN);
	strncpy(scen_file, new_scen_id.c_str(), MAX_PATH_LEN);
	}

// Determine if historic rates file exists. Raise error if it doesn't.
struct stat buffer;
int stat_val;
stat_val = stat(hist_file, &buffer);
if (stat_val != 0)
	{
	xstring mess = "Cannot locate historic rates file " + xstring(hist_file) + ". A valid historic rates file must be specified.";
	throw FatalError(mess);
	}	

econ_err_code = Econ->ScenSetInfoLoad(scen_file, hist_file);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

// Capture list of countries, currencies, yield curves, indexes, and misc rates
country_list.clear();
currency_list.clear();
yld_curve_list.clear();
yld_curve_vol_surface_list.clear();
index_list.clear();
index_vol_surface_list.clear();
misc_list.clear();

int size = 0;
int count = 0;
char item_id[MAX_ID_LEN + 1];

// Country list
econ_err_code = Econ->get_CountryInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_CountryID(count, item_id);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	country_list.push_back(xstring(item_id));
	}

// Currency list
econ_err_code = Econ->get_CurrencyInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_CurrencyID(count, item_id);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	currency_list.push_back(xstring(item_id));
	}

// Yield curve list
econ_err_code = Econ->get_YieldCurveInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_YieldCurveID(count, item_id);
	
	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	
	yld_curve_list.push_back(xstring(item_id));
	}

// Yield Curve Volatility list
econ_err_code = Econ->get_YieldCurveVolInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_YieldCurveVolID(count, item_id);
	
	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	
	yld_curve_vol_surface_list.insert(make_pair(xstring(item_id), 1.0));
	}

// Index list
econ_err_code = Econ->get_EquityTypeInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_EquityID(count, item_id);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	index_list.push_back(xstring(item_id));
	}

// Index Volatility list
econ_err_code = Econ->get_IndexVolInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_IndexVolID(count, item_id);

	xstring index_vol_id = xstring(item_id);
	size_t loc = index_vol_id.find("_");
	xstring index_name = index_vol_id.substr(0, loc);
	xstring moneyness_id = index_vol_id.substr(loc + 1, index_vol_id.length());
	
	if (loc != string::npos)
		index_vol_surface_list.insert(make_pair(index_name, atof(moneyness_id) / 100.0));
	}

// Miscellaneous rates list
econ_err_code = Econ->get_MiscRateInfoSize(size);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

for (count = 0; count < size; count++)
	{
	econ_err_code = Econ->get_MiscRateID(count, item_id);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	
	misc_list.push_back(xstring(item_id));
	}

return;
}



#line 1 "select_scen_set.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::select_scen_set(int scen_set_type)
{
switch (scen_set_type)
	{
	case OUTER_LOOP:
		econ_err_code = Econ->SelectScenSet(ScenSetType::Outer);
		break;
	case INNER_LOOP:
		econ_err_code = Econ->SelectScenSet(ScenSetType::Inner);
		break;
	default:
		throw FatalError("Invalid 'scen_set_type' passed to 'select_scen_set' function.");
		break;
	}

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);
}



#line 1 "setup_calibration_criteria.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::setup_calibration_criteria(int t)
{
int calib_yld_curve_rates_num_of_tests = 16;
int calib_yld_curve_sprds_num_of_tests = 2;
int calib_index_rates_num_of_tests = 22;

CalibData = CalibrationData::Create();
CalibData->clear();

if (gen_calib_defn == YES)
	{
	CalibData->set_CalibrationChoice(CalibrationOption::Yes);

	if (gen_basis_defn == REAL_WORLD
		&& gen_approach_defn == STOCHASTIC)
		{
		// Set up calibration criteria
		CalibData->set_CalibrationAttempts(gen_calib_retry_attempts);
	
		if (gen_calib_detail_defn == YES)
			CalibData->set_CalibrationAuditReport(1);
		else
			CalibData->set_CalibrationAuditReport(0);

		CalibData->set_PassingPercentageInterest(calib_yld_curve_rates_pass_pct);
		CalibData->set_PassingPercentageSpread(calib_yld_curve_sprds_pass_pct);
		CalibData->set_PassingPercentageEquity(calib_index_rates_pass_pct);
	
		CalibrationPointData * CPData;
		CPData = CalibrationPointData::Create();
	
		int test_num = 0;
		int yld_curve = 0;
		int index = 0;
		char row_id[MAX_ID_LEN + 1];
		char col_id[MAX_ID_LEN + 1];
	
		// Yield curves calibration criteria
		for (yld_curve = 0; yld_curve < yld_curve_list.size(); yld_curve++) 
			{
			// Set lookup key
			yld_curve_id = xstring(yld_curve_list[yld_curve]);

			// No calibration testing for credit yield curves
			if (yld_curve_id != "Govt")
				continue;

			strncpy(col_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);
			
			// Yield curve interest rate calibration criteria
			for (test_num = 1; test_num <= calib_yld_curve_rates_num_of_tests; test_num++)
				{
				CPData->set_ID(col_id);
				CPData->set_CalibrationType(CalibrationType::InterestRates);
	
				// Set lookup key
				calib_test_num = test_num;

				// Lookup keys: date(t), yld_curve_id, and calib_test_num
				date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double rate_term = calib_yld_curve_rates_rate_term;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double tgt_horizon = calib_yld_curve_rates_tgt_horizon;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double percentile = calib_yld_curve_rates_percentile;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double percentile_tgt = calib_yld_curve_rates_percentile_tgt;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double rate_adj_a = calib_yld_curve_rates_rate_adj_a;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double rate_adj_b = calib_yld_curve_rates_rate_adj_b;
	
				// Add calibration test if tgt_horizon is greater than 0
				if (fabs(tgt_horizon) > rate_ratio_threshold)
					{			
					CPData->set_Maturity(rate_term);
					CPData->set_TargetTime(tgt_horizon);
					CPData->set_Percentile(percentile);
					CPData->set_PercentileTarget(percentile_tgt);
					CPData->set_LowerTolerance(rate_adj_a);
					CPData->set_UpperTolerance(rate_adj_b);
		
					CalibData->add_CalibrationPointsData(*CPData);
					}
				}
	
			// Yield curve spreads calibration criteria
			for (test_num = 1; test_num <= calib_yld_curve_sprds_num_of_tests; test_num++)
				{
				CPData->set_ID(col_id);
				CPData->set_CalibrationType(CalibrationType::Spread);
	
				// Set lookup key
				calib_test_num = test_num;

				// Lookup keys: date(t), yld_curve_id, and calib_test_num
				date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double tgt_horizon = calib_yld_curve_sprds_tgt_horizon;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double percentile = calib_yld_curve_sprds_percentile;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double percentile_tgt = calib_yld_curve_sprds_percentile_tgt;
				date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
				calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
				yld_curve_id = xstring(yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup term
				double sprd_adj = calib_yld_curve_sprds_sprd_adj;
	
				// Add calibration test if tgt_horizon is greater than 0
				if (fabs(tgt_horizon) > rate_ratio_threshold)
					{
					CPData->set_TargetTime(tgt_horizon);
					CPData->set_Percentile(percentile);
					CPData->set_PercentileTarget(percentile_tgt);
					CPData->set_LowerTolerance(sprd_adj);
					CPData->set_UpperTolerance(0.0);
		
					CalibData->add_CalibrationPointsData(*CPData);
					}
				}
			}
	
		// Index calibration data, only calibrate the indexes being requested in the generation
		for (index = 0; index < econ_data_index_rate_list.size(); index++)
			{
			// Set lookup key
			index_id = xstring(econ_data_index_rate_list[index]);

			if (find(index_list.begin(), index_list.end(), index_id) != index_list.end())
				{
				strncpy(col_id, index_id.c_str(), MAX_ID_LEN + 1);
			
				// Index rate calibration criteria
				for (test_num = 1; test_num <= calib_index_rates_num_of_tests; test_num++)
					{
					CPData->set_ID(col_id);
					CPData->set_CalibrationType(CalibrationType::WealthFactors);
	
					// Set lookup key
					calib_test_num = test_num;

					// Lookup keys: date(t), index_id, and calib_test_num
					date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
					index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - Mutating Lookup term
					double tgt_horizon = calib_index_rates_tgt_horizon;
					date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
					calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
					index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - Mutating Lookup term
					double percentile = calib_index_rates_percentile;
					date_lookup_gen2 = date(t);//WTW - Gen2 - Mutating Lookup term
					calib_test_num = test_num;//WTW - Gen2 - Mutating Lookup term
					index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - Mutating Lookup term
					double percentile_tgt = calib_index_rates_percentile_tgt;
	
					// Add calibration test if tgt_horizon is greater than 0
					if (fabs(tgt_horizon) > rate_ratio_threshold)
						{
						CPData->set_TargetTime(tgt_horizon);
						CPData->set_Percentile(percentile);
						CPData->set_PercentileTarget(percentile_tgt);
						CPData->set_LowerTolerance(0.0);
						CPData->set_UpperTolerance(0.0);
		
						CalibData->add_CalibrationPointsData(*CPData);
						}
					}
				}
			}

		CalibrationPointData::Release(CPData);
		}
	else if (gen_basis_defn == RISK_NEUTRAL
			 && gen_approach_defn == STOCHASTIC)
		{
		int yld_curve = 0;
		int index = 0;
		char row_id[MAX_ID_LEN + 1];
		char col_id[MAX_ID_LEN + 1];

		calib_yld_curve_list.clear();
		calib_data_swap_maturity_list.clear();
		calib_data_swap_tenor_list.clear();
		calib_data_bond_term_list.clear();
		calib_index_rate_list.clear();
		calib_data_index_moneyness_list.clear();
		calib_data_index_term_list.clear();

		// Setup Yield Curve Calibration
		CalibrationYieldCurveData *CYCData;
		CYCData = CalibrationYieldCurveData::Create();
		CalibrationSwapData *CSData;
		CSData = CalibrationSwapData::Create();
		CalibrationBondData *CBData;
		CBData = CalibrationBondData::Create();
		bool one_swaption_vol_is_zero = false;
		bool one_bond_vol_is_zero = false;

		// Create the calibration yield curve list
		if (calib_yld_curve_selected != "NONE")
			split_string_usl(calib_yld_curve_selected.c_str(), calib_yld_curve_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Create the calibration yield curve swap maturities list
		if (calib_yld_curve_swap_maturities_selected != "NONE")
			split_string_usl(calib_yld_curve_swap_maturities_selected.c_str(), calib_data_swap_maturity_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Create the calibration yield curve swap tenors list
		if (calib_yld_curve_swap_tenors_selected != "NONE")
			split_string_usl(calib_yld_curve_swap_tenors_selected.c_str(), calib_data_swap_tenor_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Create the calibration yield curve bond terms list
		if (calib_yld_curve_bond_terms_selected != "NONE")
			split_string_usl(calib_yld_curve_bond_terms_selected.c_str(), calib_data_bond_term_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Yield curves calibration criteria using the interest rate list
		for (yld_curve = 0; yld_curve < calib_yld_curve_list.size(); yld_curve++) 
			{
			// Set lookup key
			yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);

			// No calibration testing for credit yield curves
			if (yld_curve_id != "Govt")
				continue;

			strncpy(col_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);

			CYCData->set_ID(col_id);
	
			yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);
			if (calib_yld_curve_normalize_wghts_defn == YES)
				CYCData->set_CalibrationInterestNormalizeWghts(true);
			else	
				CYCData->set_CalibrationInterestNormalizeWghts(false);
				
			yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - mutating Lookup Term
			if (calib_yld_curve_data_source_defn == SWAPTION_VOLATILITY)
				{
				CYCData->set_CalibrationInterestSource(CalibrationIntSource::SwaptionVolatility);
				CYCData->set_CalibrationInterestProjDefn(GenerationCalibrationProjType::TermStructure);
				
				// Reset GenData parameter to "Term Structure"
				econ_err_code = GenData->set_GenIntProjDefn(GenerationCalibrationProjType::TermStructure);

				if (econ_err_code != ECON_OK)
					econ_error_processing(econ_err_code);
				}
			else
				{
				CYCData->set_CalibrationInterestSource(CalibrationIntSource::BondVolatility);
				CYCData->set_CalibrationInterestProjDefn(GenerationCalibrationProjType::Constant);

				// Reset GenData parameter to "Constant"
				econ_err_code = GenData->set_GenIntProjDefn(GenerationCalibrationProjType::Constant);

				if (econ_err_code != ECON_OK)
					econ_error_processing(econ_err_code);
				}

			// Capture the swaption volatility and weights
			for (int maturity_index = 0; maturity_index < calib_data_swap_maturity_list.size(); maturity_index++)
				{
				double maturity = atof(xstring(calib_data_swap_maturity_list[maturity_index]));

				for (int tenor_index = 0; tenor_index < calib_data_swap_tenor_list.size(); tenor_index++)
					{
					double tenor = atof(xstring(calib_data_swap_tenor_list[tenor_index]));

					// set lookup keys
					swap_maturity = maturity;
					swap_tenor = tenor;
					
					yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - mutating Lookup Term
					// lookup keys are yld_curve_id, swap_maturity, and swap_tenor
					double vol = calib_yld_curve_swaption_vol;
					
					swap_maturity = maturity;//WTW - Gen2 - Mutating Lookup Term
					swap_tenor = tenor;//WTW - Gen2 - Mutating Lookup Term
					yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - mutating Lookup Term
					double wght = calib_yld_curve_swaption_wght;
					
					CSData->set_Maturity(maturity);
					CSData->set_Tenor(tenor);
					CSData->set_Vol(vol);
					CSData->set_Wght(wght);

					CYCData->set_CalibrationSwapData(*CSData);

					if (!one_swaption_vol_is_zero && fabs(vol) < rate_ratio_threshold)
						one_swaption_vol_is_zero = true;
					}
				}

			// Capture the bond volatility and weights
			for (int term_index = 0; term_index < calib_data_bond_term_list.size(); term_index++)
				{
				double term = atof(xstring(calib_data_bond_term_list[term_index]));

				// set lookup key
				rate_term = term;

				// lookup keys are yld_curve_id and rate_term
				yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup Term
				double vol = calib_yld_curve_bond_vol;
				yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup Term
				rate_term = term;//WTW - Gen2 - Mutating Lookup Term
				double wght = calib_yld_curve_bond_wght;

				CBData->set_Term(term);
				CBData->set_Vol(vol);
				CBData->set_Wght(wght);

				CYCData->set_CalibrationBondData(*CBData);

				if (!one_bond_vol_is_zero && fabs(vol) < rate_ratio_threshold)
					one_bond_vol_is_zero = true;
				}

			CalibData->set_CalibrationYieldCurveData(*CYCData);
			}

		CalibrationSwapData::Release(CSData);
		CalibrationBondData::Release(CBData);
		CalibrationYieldCurveData::Release(CYCData);
		
		yld_curve_id = xstring(calib_yld_curve_list[yld_curve]);//WTW - Gen2 - Mutating Lookup Term
		if (calib_yld_curve_data_source_defn == SWAPTION_VOLATILITY && one_swaption_vol_is_zero)
			throw FatalError("You have requested to calibrate to Swaption volatilities for the Interest Rate calibration. However, one volatility is zero. Please correct your data.");
		else if (calib_yld_curve_data_source_defn == BOND_VOLATILITY && one_bond_vol_is_zero)
			throw FatalError("You have requested to calibrate to Bond volatilities for the Interest Rate calibration. However, one volatility is zero. Please correct your data.");

		// Setup Asset Index Calibration
		CalibrationAssetIndexData *CAIData;
		CalibrationAssetIndexVolData *CAIVolData;

		// Create the calibration index list
		if (calib_index_rate_selected != "NONE")
			split_string_usl(calib_index_rate_selected.c_str(), calib_index_rate_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Create the calibration index moneyness list
		if (calib_index_rate_moneyness_selected != "NONE")
			split_string_usl(calib_index_rate_moneyness_selected.c_str(), calib_data_index_moneyness_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		// Create the calibration index term list
		if (calib_index_rate_terms_selected != "NONE")
			split_string_usl(calib_index_rate_terms_selected.c_str(), calib_data_index_term_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

		for (int asset_index = 0; asset_index < calib_index_rate_list.size(); asset_index++)
			{
			// Set lookup key
			index_id = xstring(calib_index_rate_list[asset_index]);

			CAIData = CalibrationAssetIndexData::Create();
			CAIVolData = CalibrationAssetIndexVolData::Create();
			bool one_index_vol_is_zero = false;

			strncpy_s(col_id, index_id.c_str(), MAX_ID_LEN + 1);

			CAIData->set_ID(col_id);

			index_id = xstring(calib_index_rate_list[asset_index]);//WTW - Gen2 - Mutating Lookup Term
			if (calib_index_rate_normalize_wghts_defn == YES)
				CAIData->set_CalibrationAssetIndexNormalizeWghts(true);
			else
				CAIData->set_CalibrationAssetIndexNormalizeWghts(false);

			// Always use Term Structure for asset indexes
			CAIData->set_CalibrationAssetIndexProjDefn(GenerationCalibrationProjType::TermStructure);

			index_id = xstring(calib_index_rate_list[asset_index]);//WTW - Gen2 - Mutating Lookup Term
			if (calib_index_rate_opt_defn == CALL)
				CAIData->set_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut::Call);
			else
				CAIData->set_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut::Put);

			index_id = xstring(calib_index_rate_list[asset_index]);//WTW - Gen2 - Mutating Lookup Term
			CAIData->set_CalibrationAssetIndexDivYld(calib_index_rate_div_yld);

			for (int moneyness_index = 0; moneyness_index < calib_data_index_moneyness_list.size(); moneyness_index++)
				{
				double moneyness_level = atof(xstring(calib_data_index_moneyness_list[moneyness_index]));

				for (int term_index = 0; term_index < calib_data_index_term_list.size(); term_index++)
					{
					double term = atof(xstring(calib_data_index_term_list[term_index]));

					// set lookup keys
					moneyness = moneyness_level;
					rate_term = term;

					// lookup keys are index_id, moneyness, and rate_term
					index_id = xstring(calib_index_rate_list[asset_index]);//WTW - Gen2 - Mutating Lookup Term
					double vol = calib_index_rate_opt_vol;
					
					moneyness = moneyness_level;//WTW - Gen2 - Mutating Lookup Term
					rate_term = term;//WTW - Gen2 - Mutating Lookup Term
					index_id = xstring(calib_index_rate_list[asset_index]);//WTW - Gen2 - Mutating Lookup Term
					double wght = calib_index_rate_opt_wght;

					CAIVolData->set_Moneyness(moneyness);
					CAIVolData->set_Term(term);
					CAIVolData->set_Vol(vol);
					CAIVolData->set_Wght(wght);

					if (!one_index_vol_is_zero && fabs(vol) < rate_ratio_threshold)
						one_index_vol_is_zero = true;

					// If generating for shocked scenarios, add shock to asset calibration data
					if (gen_defn == SHOCKED_SCENARIOS)
						{
						StrEnum::EnumValue shock_defn;
						xstring eqt_shock_id;
						double shock = 0.0;

						// set lookup key 
						shock_id = shock_gen_list[proj_task_loop_num - 1];
						
						shock_defn = eqt_vol_shock_defn; 
						eqt_shock_id = eqt_vol_shock_id;

						// lookup keys are eqt_vol_shock_id, index_id, and rate_term
						if (shock_defn == YES && eqt_shock_id != "NONE")
							shock = eqt_vol_shock;

						CAIVolData->set_InitVolShock(shock);
						}

					CAIData->set_CalibrationAssetIndexVolData(*CAIVolData);
					}

				if (one_index_vol_is_zero)
					{
					xstring error_mess = " You have requested to calibrate the index option volatilities for the " + index_id 
											+ " index calibration. However, one of the volatilities is zero. Please correct your data.";
					throw FatalError(error_mess);
					}
				}

			CalibData->set_CalibrationAssetIndexData(*CAIData);
			CalibrationAssetIndexVolData::Release(CAIVolData);
			CalibrationAssetIndexData::Release(CAIData);
			}
		}
	else // Not a valid generation method for calibration
		CalibData->set_CalibrationChoice(CalibrationOption::No);
	}
else // gen_calib_defn == NO
	CalibData->set_CalibrationChoice(CalibrationOption::No);

return;
}



#line 1 "setup_economy_data.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::setup_economy_data(int t)
{
EconData =  EconomyData::Create();

EconData->clear_CurrencyData();
EconData->clear_YieldCurveData();
EconData->clear_AssetIndexData();
EconData->clear_MiscRatesData();
EconData->set_BaseCurrency("USD");

econ_data_yld_curve_list.clear();
econ_data_yld_curve_term_list.clear();
econ_data_yld_curve_vol_mr_term_list.clear();
econ_data_index_rate_list.clear();
econ_data_index_rate_tenor_list.clear();
econ_data_index_rate_moneyness_list.clear();
econ_data_misc_rates_list.clear();
correl_list.clear();

YieldCurveData *YCData;
YCData = YieldCurveData::Create();
YieldTermData *YTData;
YTData = YieldTermData::Create();
AssetIndexData *AIData;
AIData = AssetIndexData::Create();
AssetIndexTenorData *AITData;
AITData = AssetIndexTenorData::Create();
MiscRateData *MRData;
MRData = MiscRateData::Create();

int col, row;
int yld_curve, index, tenor_ct, moneyness_ct;
int term_index, moneyness_index, misc_index;
xstring row_name;
xstring col_name;
char row_id[MAX_ID_LEN + 1];
char col_id[MAX_ID_LEN + 1];

// Create the yield curve rates list
if (econ_data_yld_curve_selected != "NONE")
	split_string_usl(econ_data_yld_curve_selected.c_str(), econ_data_yld_curve_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

// Create the index rates list
if (econ_data_index_rate_selected != "NONE")
	split_string_usl(econ_data_index_rate_selected.c_str(), econ_data_index_rate_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

// Create the miscellaneous rates list
if (econ_data_misc_rates_selected != "NONE")
	split_string_usl(econ_data_misc_rates_selected.c_str(), econ_data_misc_rates_list, ",");//WTW - Gen2 - split_tring internal RAFM function
else // Must always have one element in the misc rates list
	econ_data_misc_rates_list.push_back("DEFAULT");

// Build the correlation list from the yield curve and index rates list
for (yld_curve = 0; yld_curve < econ_data_yld_curve_list.size(); yld_curve++)
	correl_list.push_back(econ_data_yld_curve_list[yld_curve]);

for (index = 0; index < econ_data_index_rate_list.size(); index++)
	correl_list.push_back(econ_data_index_rate_list[index]);

// Create the yield curve term vector
if (econ_data_yld_curve_term_selected != "NONE")
	split_string_usl(econ_data_yld_curve_term_selected.c_str(), econ_data_yld_curve_term_list, ",");	//WTW - Gen2 - split_tring internal RAFM function
			
// Create the yield curve volatilty and mean reversion term vector
if (econ_data_yld_curve_term_selected != "NONE")
	split_string_usl(econ_data_yld_curve_vol_mr_term_selected.c_str(), econ_data_yld_curve_vol_mr_term_list, ",");	//WTW - Gen2 - split_tring internal RAFM function

// Create the index rate tenor vector
if (econ_data_index_rate_tenor_selected != "NONE")
	split_string_usl(econ_data_index_rate_tenor_selected.c_str(), econ_data_index_rate_tenor_list, ",");//WTW - Gen2 - split_tring internal RAFM function
		
// Create the index rate moneyness vector
if (econ_data_index_rate_moneyness_selected != "NONE")
	split_string_usl(econ_data_index_rate_moneyness_selected.c_str(), econ_data_index_rate_moneyness_list, ",");//WTW - Gen2 - split_tring internal RAFM function

// Setup yield curves data
for (yld_curve = 0; yld_curve < econ_data_yld_curve_list.size(); yld_curve++)
	{
	// Set lookup key
	yld_curve_id = xstring(econ_data_yld_curve_list[yld_curve]);

	if (find(yld_curve_list.begin(), yld_curve_list.end(), yld_curve_id) != yld_curve_list.end())
		{
		strncpy(col_id, yld_curve_id.c_str(), MAX_ID_LEN + 1);
		
		YCData->set_ID(col_id);

		int yld_curve_vol_term_size = econ_data_yld_curve_vol_mr_term_list.size();
		double yld_curve_vol_term_max = atof(econ_data_yld_curve_vol_mr_term_list[yld_curve_vol_term_size - 1].c_str());
		double yld_curve_vol_term_min = atof(econ_data_yld_curve_vol_mr_term_list[0].c_str());

		for (term_index = 0; term_index < econ_data_yld_curve_term_list.size(); term_index++)
			{
			double yld_curve_term = atof(xstring(econ_data_yld_curve_term_list[term_index]));

			// Set lookup key for mr rate
			rate_term = yld_curve_term;
			// Lookup keys: date(t), yld_curve_id, and rate term			
			date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
			yld_curve_id = xstring(econ_data_yld_curve_list[yld_curve]);//WTW - Gen2 - mutating lookup term
			double rate = econ_data_yld_curve_mr_rates; 

			YTData->set_Maturity(rate_term);
			YTData->set_MeanRevRate(rate);
			YTData->set_Moneyness(1.0); // Moneyness is always 1.0

			double yld_curve_vol_term = 0.0;
			int term_vol_index = 0;

			if (yld_curve_term >= yld_curve_vol_term_max)
				yld_curve_vol_term = yld_curve_vol_term_max;

			else if (yld_curve_term <= yld_curve_vol_term_min)
				yld_curve_vol_term = yld_curve_vol_term_min;				

			else
				{
				for (int i = 1; i < yld_curve_vol_term_size; i++)
					{
					yld_curve_vol_term = atof(econ_data_yld_curve_vol_mr_term_list[i].c_str());
					if (yld_curve_term <= yld_curve_vol_term)
						break;
					}	
				}

			// Set lookup key for vol
			rate_term = yld_curve_vol_term;

			// Lookup keys: date(t), yld_curve_id, and rate_term
			date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
			yld_curve_id = xstring(econ_data_yld_curve_list[yld_curve]);//WTW - Gen2 - mutating lookup term
			double vol = econ_data_yld_curve_vol; 

			YTData->set_Vol(vol);

			// reset rate_term lookup key
			rate_term = yld_curve_term;

			// If generating for shocked scenarios, add shock to yield term data
			if (gen_defn == SHOCKED_SCENARIOS)
				{
				StrEnum::EnumValue shock_defn;
				xstring int_shock_id;
				double shock = 0.0;

				// set lookup key 
				shock_id = shock_gen_list[proj_task_loop_num - 1];

				shock_defn = int_rate_shock_defn; 
				int_shock_id = int_rate_shock_id;

				// lookup keys are int_rate_shock_id, yld_curve_id, and rate_term
				if (shock_defn == YES && int_shock_id != "NONE")
					shock = int_rate_shock;

				YTData->set_InitYieldShock(shock);
				}

			YCData->set_YieldTermData(*YTData);
			}
		EconData->set_YieldCurveData(*YCData);	
		}			
	}
YieldCurveData::Release(YCData);
YieldTermData::Release(YTData);

// Setup index rates data
for (index = 0; index < econ_data_index_rate_list.size(); index++)
	{
	// Set lookup key
	index_id = xstring(econ_data_index_rate_list[index]);

	if (find(index_list.begin(), index_list.end(), index_id) != index_list.end())
		{
		strncpy(col_id, index_id.c_str(), MAX_ID_LEN + 1);

		AIData->set_ID(col_id);

		if (gen_approach_defn == MEAN_REVERSION_WITH_INDEX_SPREAD)
			{
			// Lookup keys: date(t) and index_id
			date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
			index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - mutating lookup term
			double rate_term = econ_data_index_rate_mr_term; 
			date_lookup_gen2 = date(t);//WTW - Gen2 - mutating lookup term
			index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - mutating lookup term
			double sprd = econ_data_index_rate_mr_sprd; 

			AITData->set_Tenor(rate_term);
			AITData->set_Spread(sprd);

			AIData->set_AssetIndexTenorData(*AITData);
			}
		else // if (gen_approach_defn != MEAN_REVERSION_WITH_INDEX_SPREAD)
			{
			// Lookup keys: date(t) and index_id
			date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
			index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - mutating lookup term
			double inc_rate = econ_data_index_rate_mr_inc_ret; 
			date_lookup_gen2 = date(t);//WTW - Gen2 - mutating lookup term
			index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - mutating lookup term
			double grwth_rate = econ_data_index_rate_mr_grwth;	

			AITData->set_MeanRevIncomeRate(inc_rate);
			AITData->set_MeanRevGrowthRate(grwth_rate);

			for (tenor_ct = 0; tenor_ct < econ_data_index_rate_tenor_list.size(); tenor_ct++)
				{
				double tenor = atof(xstring(econ_data_index_rate_tenor_list[tenor_ct]));

				for (moneyness_ct = 0; moneyness_ct < econ_data_index_rate_moneyness_list.size(); moneyness_ct++)
					{
					double moneyness_level = atof(xstring(econ_data_index_rate_moneyness_list[moneyness_ct]));

					// Set lookup key
					rate_term = tenor;
					moneyness = moneyness_level;

					// Lookup keys: date(t), rate_term, and moneyness
					date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
					index_id = xstring(econ_data_index_rate_list[index]);//WTW - Gen2 - mutating lookup term
					double vol = econ_data_index_rate_vol; 

					AITData->set_Tenor(tenor);
					AITData->set_Moneyness(moneyness_level);
					AITData->set_Vol(vol);

					// If generating for shocked scenarios, add shock to asset index tenor data
					if (gen_defn == SHOCKED_SCENARIOS)
						{
						StrEnum::EnumValue shock_defn;
						xstring eqt_shock_id;
						double shock = 0.0;

						// set lookup key 
						shock_id = shock_gen_list[proj_task_loop_num - 1];
						
						shock_defn = eqt_vol_shock_defn; 
						eqt_shock_id = eqt_vol_shock_id;

						// lookup keys are eqt_vol_shock_id, index_id, and rate_term
						if (shock_defn == YES && eqt_shock_id != "NONE")
							shock = eqt_vol_shock;

						AITData->set_InitVolShock(shock);
						}
					AIData->set_AssetIndexTenorData(*AITData);
					}
				}
			}
		EconData->set_AssetIndexData(*AIData);	
		AIData->clear();
		}
	}

AssetIndexData::Release(AIData);
AssetIndexTenorData::Release(AITData);
	
if (gen_basis_defn == REAL_WORLD)
	{
	// Setup miscellaneous rates data
	for (misc_index = 0; misc_index < econ_data_misc_rates_list.size(); misc_index++)
		{
		// Set lookup key
		index_id = xstring(econ_data_misc_rates_list[misc_index]);

		if (find(misc_list.begin(), misc_list.end(), index_id) != misc_list.end())
			{
			strncpy(col_id, index_id.c_str(), MAX_ID_LEN + 1);

			// Lookup keys: date(t), index_id			
			date_lookup_gen2 = date(t);//WTW - Gen2 - date lookup since cannot use t-based lookup in variable
			index_id = xstring(econ_data_misc_rates_list[misc_index]);//WTW - Gen2 - mutating lookup term
			double misc_rate = econ_data_misc_rates; 
	
			MRData->set_ID(col_id);
			MRData->set_MeanRevRate(misc_rate);
			}

		EconData->set_MiscRateData(*MRData);	
		}
	MiscRateData::Release(MRData);
	}

// Setup initial correlation data
EconData->Init_Correl();

for (row = 0; row < correl_list.size(); row++)
	{
	xstring row_name = xstring(correl_list[row]);

	for (col = row + 1; col < correl_list.size(); col++)
		{
		xstring col_name = xstring(correl_list[col]);
			
		if (!eq(row_name, col_name))
			{
			strncpy(row_id, row_name.c_str(), MAX_ID_LEN + 1);
			strncpy(col_id, col_name.c_str(), MAX_ID_LEN + 1);

			// Set lookup key
			correl_id1 = row_name;
			correl_id2 = col_name;

			// Lookup keys: row_name and col_name
			double correl = econ_data_correlation; 

			if (correl < -1)
				continue;
				
			EconData->set_Correl(row_id, col_id, correl);
			}
		}
	}

return;
}



#line 1 "setup_generation_parameters.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::setup_generation_parameters(int t)
{
GenData = GenerationData::Create();

if (isMainModel)
	econ_err_code = GenData->set_GenMethod(GenerationMethod::StandAlone);
else
	econ_err_code = GenData->set_GenMethod(GenerationMethod::OnTheFly);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

econ_err_code = GenData->set_ScenDateTreatment(DateTreatmentType::Relative);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

if (!time_step_flag)
	{
	econ_err_code = GenData->set_GenDuration(t);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	int gen_yr = 0;
	int gen_mth = 0;
	int gen_day = 1;
	long gen_date = 0;

	gen_yr = get_yr_from_date(proj_date_adj);
	gen_mth = get_mth_from_date(proj_date_adj);

	if (xstring(proj_date_adj).length() > 7) // date field contains a day
		gen_day = get_day_from_date(proj_date_adj);
	else
		gen_day = get_end_of_mth_day(gen_yr, gen_mth);

	gen_date = 10000 * gen_yr + 100 * gen_mth + gen_day;

	econ_err_code = GenData->set_GenDate(gen_date);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	// Always use the first scenario for a standalone generation
	econ_err_code = GenData->set_OuterLoopScenNum(1);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}
else
	{
	econ_err_code = GenData->set_GenDuration(valn_period);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	int gen_yr = 0;
	int gen_mth = 0;
	int gen_day = 1;
	long gen_date = 0;

	gen_yr = get_yr_from_date(proj_date_adj);
	gen_mth = get_mth_from_date(proj_date_adj);

	if (xstring(proj_date_adj).length() > 7) // date field contains a day
		gen_day = get_day_from_date(proj_date_adj);
	else
		gen_day = get_end_of_mth_day(gen_yr, gen_mth);

	gen_date = 10000 * gen_yr + 100 * gen_mth + gen_day;

	econ_err_code = GenData->set_GenDate(gen_date);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_OuterLoopScenNum(proj_set_loop_num);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}

xstring file_path;
xstring file_name;
xstring file_addn;
xstring new_file_name;
xstring new_hist_id;
xstring new_scen_id;
char new_hist_file[MAX_PATH_LEN];
char new_scen_file[MAX_PATH_LEN];

// If generating for shocked scenarios, get the scenario file name from the hedge control grid
file_addn = "";
if (gen_defn == SHOCKED_SCENARIOS)
	{
	// set lookup key
	shock_id = shock_gen_list[proj_task_loop_num - 1];
	file_addn = "_" + scen_file_name_addn;
	}

// Create new historic rates file name
file_path = replaceWildcards(gen_scen_file_path);
if (time_step_flag)
	{
	file_name = get_file_name(replaceWildcards(inner_loop_historic_rates_id));

	if (save_time_step_scen_files_defn == YES)
		new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);
	else
		new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num);
	}
else 
	{
	file_name = get_file_name(replaceWildcards(historic_rates_id));
	new_file_name = file_name + file_addn;
	}

new_hist_id = file_path + new_file_name + ".csv"; 
strncpy(new_hist_file, new_hist_id.c_str(), MAX_PATH_LEN);

econ_err_code = GenData->set_HistFileName(new_hist_file);	

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

// Create new scenario file name
file_path = replaceWildcards(gen_scen_file_path);

if (time_step_flag)
	{
	file_name = get_file_name(replaceWildcards(inner_loop_valn_scen_id));

	if (save_time_step_scen_files_defn == YES)
		new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);
	else
		new_file_name = file_name + file_addn + "_" + xstring(proj_set_loop_num);
	}
else
	{
	file_name = get_file_name(replaceWildcards(scen_id));
	new_file_name = file_name + file_addn;
	}

new_scen_id = file_path + new_file_name + ".csv"; 
strncpy(new_scen_file, new_scen_id.c_str(), MAX_PATH_LEN);

econ_err_code = GenData->set_ProjFileName(new_scen_file);	

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

// Basic generation parameters
econ_err_code = GenData->set_GenScenMths(gen_mths);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);
	
econ_err_code = GenData->set_GenRandomSeed((long)gen_random_seed);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

if (gen_rates_freq == MONTHLY)
	econ_err_code = GenData->set_ScenMthsPerPeriod(MonthsPerPeriodType::MonthlyRates);
else
	econ_err_code = GenData->set_ScenMthsPerPeriod(MonthsPerPeriodType::AnnualRates);

if (econ_err_code != ECON_OK)
	econ_error_processing(econ_err_code);

if (gen_detail_defn == YES)
	{
	econ_err_code = GenData->set_GenAuditDefn(GenerationAudit::AuditYes);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_GenAuditScen(gen_detail_scen);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}
else
	{
	econ_err_code = GenData->set_GenAuditDefn(GenerationAudit::AuditNo);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}

if (time_step_flag)
	{
	if (inner_loop_valn_scen_reuse_defn == ALL_RATES)
		econ_err_code = GenData->set_ValnScenReuse(ValuationScenType::AllRates);	
	else if (inner_loop_valn_scen_reuse_defn == INDEX_RATES_ONLY)
		econ_err_code = GenData->set_ValnScenReuse(ValuationScenType::IndexRatesOnly);
	else // NONE
		econ_err_code = GenData->set_ValnScenReuse(ValuationScenType::NoRatesReused);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	if (inner_loop_valn_scen_reuse_defn == ALL_RATES
		|| inner_loop_valn_scen_reuse_defn == INDEX_RATES_ONLY)
		{	
		char valn_scen_file[MAX_PATH_LEN];
		strncpy(valn_scen_file, replaceWildcards(inner_loop_valn_scen_id.c_str()), MAX_PATH_LEN);
		econ_err_code = GenData->set_ValnScenFile(valn_scen_file);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	else
		{
		econ_err_code = GenData->set_ValnScenFile("NONE");

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	}
else
	{
	econ_err_code = GenData->set_ValnScenReuse(ValuationScenType::NoRatesReused);
	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}

// Real World versus Risk Neutral
if (gen_basis_defn == REAL_WORLD)
	{
	int gen_rw_mrp_mths_max 
	= max(max(gen_rw_mrp_mean_yrs_1, gen_rw_mrp_mean_yrs_2),
	      gen_rw_mrp_median_yrs) * 12;
	          
	if (gen_rw_mrp_mean_yrs_2 > 0) // NAIC approach needs extra 12 months of history
		econ_err_code = GenData->set_GenHistMths(max(gen_hist_mths, gen_rw_mrp_mths_max) + 12);
	else // AAA approach
		econ_err_code = GenData->set_GenHistMths(max(gen_hist_mths, gen_rw_mrp_mths_max));
	
	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_GenerationBasis(ScenarioBasisType::RealWorld);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	if (gen_approach_defn == STOCHASTIC)
		{
		econ_err_code = GenData->set_GenApproach(GenerationApproachType::Stochastic);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		if (gen_rw_stoch_defn == ACADEMY_SELECTED_SCENARIOS)
			econ_err_code = GenData->set_GenRWStochDefn(RWGenerationStochDefn::AcademySelectedScenarios);
		else // gen_rw_stoch_defn == RANDOM_SCENARIOS
			econ_err_code = GenData->set_GenRWStochDefn(RWGenerationStochDefn::RandomScenarios);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		econ_err_code = GenData->set_Scenarios(gen_scenarios);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	else if (gen_approach_defn == MEAN_REVERSION)
		{
		econ_err_code = GenData->set_GenApproach(GenerationApproachType::MeanReversion);
	
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		econ_err_code = GenData->set_MeanRevMths(gen_mean_reversion_mths);
			
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
	
		econ_err_code = GenData->set_Scenarios(1); // Always just 1 scenario for mean reversion

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	else if (gen_approach_defn == MEAN_REVERSION_WITH_INDEX_SPREAD)
		{
		econ_err_code = GenData->set_GenApproach(GenerationApproachType::MeanReversionWithIndexSpread);
	
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		econ_err_code = GenData->set_MeanRevMths(gen_mean_reversion_mths);
			
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
	
		econ_err_code = GenData->set_Scenarios(1); // Always just 1 scenario for mean reversion

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	else // gen_approach_defn == STOCHASTIC_EXCLUSION_TEST
		{
		econ_err_code = GenData->set_GenApproach(GenerationApproachType::StochasticExclusionTest);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		econ_err_code = GenData->set_Scenarios(16); // Always 16 scenarios for stochastic exclusion test

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}

	// Set up the MRP parameters
	econ_err_code = GenData->set_MRPMean1HistYrs(gen_rw_mrp_mean_yrs_1);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_MRPMean2HistYrs(gen_rw_mrp_mean_yrs_2);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_MRPMedianHistYrs(gen_rw_mrp_median_yrs);	

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);
	}
else // gen_basis_defn == RISK_NEUTRAL
	{
	if (gen_rn_int_proj_defn == CONSTANT)
		{
		econ_err_code = GenData->set_GenIntProjDefn(GenerationCalibrationProjType::Constant);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	else // gen_rn_int_proj_defn == TERM_STRUCTURE
		{
		econ_err_code = GenData->set_GenIntProjDefn(GenerationCalibrationProjType::TermStructure);

		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}

	econ_err_code = GenData->set_GenHistMths(gen_hist_mths);
	
	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_GenerationBasis(ScenarioBasisType::RiskNeutral);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_GenApproach(GenerationApproachType::Stochastic);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	econ_err_code = GenData->set_Scenarios(gen_scenarios);

	if (econ_err_code != ECON_OK)
		econ_error_processing(econ_err_code);

	if (gen_rn_defn == QUICK_GENERATION)
		{
		econ_err_code = GenData->set_RNMethod(GenerationRNMethod::QuickGeneration);
	
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
	
		econ_err_code = GenData->clear_BondTerms();
		
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);

		for (int i = 0; i < gen_rn_bonds_term.size(); i++)
			{
			if (i > 0 && (gen_rn_bonds_term[i] == gen_rn_bonds_term[i - 1]))
				continue;
	
			econ_err_code = GenData->set_BondTerm(gen_rn_bonds_term[i]);
			
			if (econ_err_code != ECON_OK)
				econ_error_processing(econ_err_code);
			}
		}	
	else // Complete RN generation
		{
		econ_err_code = GenData->set_RNMethod(GenerationRNMethod::CompleteGeneration);
	
		if (econ_err_code != ECON_OK)
			econ_error_processing(econ_err_code);
		}
	}

return;
}



#line 1 "setup_shock_gen_list.RATES_ECONOMY.for"                                                                                   
void RATES_ECONOMY::setup_shock_gen_list(void)
{
// This function sets up the shock generation list
shock_gen_list.clear();
map <xstring, xstring> shock_scen_file_name_addn; // Map to check for duplicate scenario file name additions
double overall_proj_task_loops_to_run = overall_num_of_proj_task_loops;

double hedge_valn_control_row_count = 0.0;
ExtSrcValTable hedge_valn_control_tbl;

#if defined(__HDG_GRP_COMP_H_)//WTW - Gen2 - ignore this code for liab only 'GetRowKeyValues' functions not supported
hedge_valn_control_row_count = GetRowKeyValuesCount(int_rate_shock_defn);
hedge_valn_control_tbl = GetRowKeyValues(int_rate_shock_defn);
#endif

// Start at index 1 since we have a blank row in the lookup grid
for (int row = 1; row < hedge_valn_control_row_count; row++)
	{
	xstring shock_id_string;

	// Set lookup key and perform lookups
	shock_id_string = hedge_valn_control_tbl[row][0].AsString();
	shock_id = shock_id_string;
	
	if (eqt_price_shock_defn == NO && int_rate_shock_defn == NO && eqt_vol_shock_defn == NO && phldr_shock_defn == NO)
		{
		if (shock_scen_file_name_addn.find(scen_file_name_addn) == shock_scen_file_name_addn.end())
			{
			shock_gen_list.push_back(shock_id_string); // This is the Baseline shock
			shock_scen_file_name_addn[scen_file_name_addn] = scen_file_name_addn;
			}
		}
	else if (int_rate_shock_defn == YES || eqt_vol_shock_defn == YES)
		{		
		if (shock_scen_file_name_addn.find(scen_file_name_addn) == shock_scen_file_name_addn.end())
			{
			shock_gen_list.push_back(shock_id_string); // This shock requires new scenarios
			shock_scen_file_name_addn[scen_file_name_addn] = scen_file_name_addn;
			}
		}
	}

// Check count of shock_gen_list against projection task loops
if (shock_gen_list.size() < overall_proj_task_loops_to_run)
	{
	xstring message = xstring("Error: Number of specified projection task loops (") 
	                  + xstring(overall_proj_task_loops_to_run) 
					  + xstring(") cannot exceed the requested shock scenarios to generate (")
					  + xstring(shock_gen_list.size())
					  + xstring("). Please correct your data.");

	throw FatalError(message);
	}

return;
}



#line 1 "swap_curve_init_cubic_spline_params_aig.RATES_ECONOMY.for"                                                                                   
vector<double> RATES_ECONOMY::swap_curve_init_cubic_spline_params_aig(int t, cubic_spline_params_aig& swap_curve_cubic_spline_params)
// 20190728 MTC - ITM iLoop refactor
{
	// Get swap rates
	vector<double> swap_curve;

	for (int i = 0; i < swap_curve_tenors_aig.size(); i++)
	{
		int current_tenor = swap_curve_tenors_aig[i] / 12.0;
		double spot_rate = get_int_rate(t, swap_curve_rate_id_aig, GET_YIELD_RATE, current_tenor, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0); //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ


		swap_curve.push_back(spot_rate);
	}

	// Calculate cubic spline parameters
	cubic_spline_params_calc_aig(swap_curve_cubic_spline_params, swap_curve_tenors_aig, swap_curve);

	return swap_curve;
}



#line 1 "trapezoidal_rule_avg_height_calc_aig.RATES_ECONOMY.for"                                                                                   
double RATES_ECONOMY::trapezoidal_rule_avg_height_calc_aig(vector<double> f_x)
{
	// 20200515 MTC - Refactored VIX
	/*
		https://en.wikipedia.org/wiki/Trapezoidal_rule
	*/

	double height;
	size_t N						= f_x.size() - 1;

	if (N > SIZE_MAX)
	{
		throw FatalError("Number of points exceeds SIZE_MAX in trapezoidal_rule_avg_height_calc_aig!");
	}
	else if (f_x.empty())
	{
		throw FatalError("No points have been provided in trapezoidal_rule_avg_height_calc_aig!");
	}
	else if (N == 0)
	{
		height						= f_x[N];
	}
	else
	{
		double area					= 0.0;
		double width				= 0.0;

		for (size_t k = 1; k <= N; k++)
		{
			area					+= (f_x[k] + f_x[k - 1]) /
									   2.0;

			width					++;
		}

		height						= area / width;
	}

	return height;
}



	static RATES_ECONOMY_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (RATES_ECONOMY_UDF::*dPXi) (int);
typedef double (RATES_ECONOMY_UDF::*dPXid) (int, double);
typedef double (RATES_ECONOMY_UDF::*dPF) ();
typedef double (RATES_ECONOMY_UDF::*dPFd) (double);
typedef int (RATES_ECONOMY_UDF::*iPF) ();
typedef int (RATES_ECONOMY_UDF::*iPFi) (int);
typedef xstring (RATES_ECONOMY_UDF::*sPF) ();
typedef xstring (RATES_ECONOMY_UDF::*sPFs) (xstring);

const CashFlowCommonData RATES_ECONOMY::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "cal_mth", "rates_economy_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(2, "cal_yr", "rates_economy_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(3, "cal_yr_relative", "rates_economy_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(4, "date", "rates_economy_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(5, "equity_market_value_growth_us", "rates_economy_equity_market_value_growth_us",  "equity_market_value_growth_us",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_equity_market_value_growth_us, 'E','N', '3', 'P', (size_t)&modelOffset->equity_market_value_growth_us),
	CashFlowCommonData(6, "equity_scenario_total_return_us", "rates_economy_equity_scenario_total_return_us",  "equity_scenario_total_return_us",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_equity_scenario_total_return_us, 'E','N', '3', 'P', (size_t)&modelOffset->equity_scenario_total_return_us),
	CashFlowCommonData(7, "exact_date", "rates_economy_exact_date",  "exact_date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_exact_date, 'E','N', '3', 'P', (size_t)&modelOffset->exact_date),
	CashFlowCommonData(8, "finalize", "rates_economy_finalize",  "finalize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(9, "generate", "rates_economy_generate",  "generate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_generate, 'E','N', '3', 'P', (size_t)&modelOffset->generate),
	CashFlowCommonData(10, "infl_rate_annual", "rates_economy_infl_rate_annual",  "infl_rate_annual",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_infl_rate_annual, 'E','N', '3', 'P', (size_t)&modelOffset->infl_rate_annual),
	CashFlowCommonData(11, "initialize", "rates_economy_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(12, "startup", "rates_economy_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(13, "ten_year_treasury_annualized_return_cumul_max_aig", "rates_economy_ten_year_treasury_annualized_return_cumul_max_aig",  "ten_year_treasury_annualized_return_cumul_max_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_cumul_max_aig, 'E','N', '3', 'P', (size_t)&modelOffset->ten_year_treasury_annualized_return_cumul_max_aig),
	CashFlowCommonData(14, "ten_year_treasury_annualized_return_max_aig", "rates_economy_ten_year_treasury_annualized_return_max_aig",  "ten_year_treasury_annualized_return_max_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_max_aig, 'E','N', '3', 'P', (size_t)&modelOffset->ten_year_treasury_annualized_return_max_aig),
	CashFlowCommonData(15, "ten_year_treasury_annualized_return_three_mth_avg_aig", "rates_economy_ten_year_treasury_annualized_return_three_mth_avg_aig",  "ten_year_treasury_annualized_return_three_mth_avg_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_ten_year_treasury_annualized_return_three_mth_avg_aig, 'E','N', '3', 'P', (size_t)&modelOffset->ten_year_treasury_annualized_return_three_mth_avg_aig),
	CashFlowCommonData(16, "yield_rate_10_year", "rates_economy_yield_rate_10_year",  "yield_rate_10_year",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_yield_rate_10_year, 'E','N', '3', 'P', (size_t)&modelOffset->yield_rate_10_year),
	CashFlowCommonData(17, "yield_rate_90_day", "rates_economy_yield_rate_90_day",  "yield_rate_90_day",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&RATES_ECONOMY_UDF::rates_economy_yield_rate_90_day, 'E','N', '3', 'P', (size_t)&modelOffset->yield_rate_90_day)
};
const CashFlowCommonData* RATES_ECONOMY::mCFStaticData[] = {
	&RATES_ECONOMY::mCFStaticData_0[0],
	&RATES_ECONOMY::mCFStaticData_0[1],
	&RATES_ECONOMY::mCFStaticData_0[2],
	&RATES_ECONOMY::mCFStaticData_0[3],
	&RATES_ECONOMY::mCFStaticData_0[4],
	&RATES_ECONOMY::mCFStaticData_0[5],
	&RATES_ECONOMY::mCFStaticData_0[6],
	&RATES_ECONOMY::mCFStaticData_0[7],
	&RATES_ECONOMY::mCFStaticData_0[8],
	&RATES_ECONOMY::mCFStaticData_0[9],
	&RATES_ECONOMY::mCFStaticData_0[10],
	&RATES_ECONOMY::mCFStaticData_0[11],
	&RATES_ECONOMY::mCFStaticData_0[12],
	&RATES_ECONOMY::mCFStaticData_0[13],
	&RATES_ECONOMY::mCFStaticData_0[14],
	&RATES_ECONOMY::mCFStaticData_0[15],
	&RATES_ECONOMY::mCFStaticData_0[16],
	&RATES_ECONOMY::mCFStaticData_0[17],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for calib_index_rate_normalize_wghts_defn                                                                                       
	const ChoicePair calib_index_rate_normalize_wghts_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList calib_index_rate_normalize_wghts_defnEnumList(2, calib_index_rate_normalize_wghts_defnChoicePairs);

	// EnumList for calib_index_rate_opt_defn                                                                                       
	const ChoicePair calib_index_rate_opt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "Call")
		,ChoicePair(StrEnum::PUT, "Put")
	};
	const EnumList calib_index_rate_opt_defnEnumList(2, calib_index_rate_opt_defnChoicePairs);

	// EnumList for calib_yld_curve_data_source_defn                                                                                       
	const ChoicePair calib_yld_curve_data_source_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SWAPTION_VOLATILITY, "Swaption Volatility")
		,ChoicePair(StrEnum::BOND_VOLATILITY, "Bond Volatility")
	};
	const EnumList calib_yld_curve_data_source_defnEnumList(2, calib_yld_curve_data_source_defnChoicePairs);

	// EnumList for calib_yld_curve_normalize_wghts_defn                                                                                       
	const ChoicePair calib_yld_curve_normalize_wghts_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList calib_yld_curve_normalize_wghts_defnEnumList(2, calib_yld_curve_normalize_wghts_defnChoicePairs);

	// EnumList for credit_sprd_defn                                                                                       
	const ChoicePair credit_sprd_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SPOT_SPREADS, "Spot Spreads")
		,ChoicePair(StrEnum::YIELD_SPREADS, "Yield Spreads")
	};
	const EnumList credit_sprd_defnEnumList(2, credit_sprd_defnChoicePairs);

	// EnumList for cubic_spline_enhancement_wtw_switch_aig                                                                                       
	const ChoicePair cubic_spline_enhancement_wtw_switch_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList cubic_spline_enhancement_wtw_switch_aigEnumList(2, cubic_spline_enhancement_wtw_switch_aigChoicePairs);

	// EnumList for eqt_price_shock_defn                                                                                       
	const ChoicePair eqt_price_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList eqt_price_shock_defnEnumList(2, eqt_price_shock_defnChoicePairs);

	// EnumList for eqt_vol_shock_defn                                                                                       
	const ChoicePair eqt_vol_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList eqt_vol_shock_defnEnumList(2, eqt_vol_shock_defnChoicePairs);

	// EnumList for gen2_defn                                                                                       
	const ChoicePair gen2_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gen2_defnEnumList(2, gen2_defnChoicePairs);

	// EnumList for gen_approach_defn                                                                                       
	const ChoicePair gen_approach_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::STOCHASTIC, "Stochastic")
		,ChoicePair(StrEnum::MEAN_REVERSION, "Mean Reversion")
		,ChoicePair(StrEnum::MEAN_REVERSION_WITH_INDEX_SPREAD, "Mean Reversion With Index Spread")
		,ChoicePair(StrEnum::STOCHASTIC_EXCLUSION_TEST, "Stochastic Exclusion Test")
	};
	const EnumList gen_approach_defnEnumList(4, gen_approach_defnChoicePairs);

	// EnumList for gen_basis_defn                                                                                       
	const ChoicePair gen_basis_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REAL_WORLD, "Real World")
		,ChoicePair(StrEnum::RISK_NEUTRAL, "Risk Neutral")
	};
	const EnumList gen_basis_defnEnumList(2, gen_basis_defnChoicePairs);

	// EnumList for gen_calib_defn                                                                                       
	const ChoicePair gen_calib_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gen_calib_defnEnumList(2, gen_calib_defnChoicePairs);

	// EnumList for gen_calib_detail_defn                                                                                       
	const ChoicePair gen_calib_detail_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gen_calib_detail_defnEnumList(2, gen_calib_detail_defnChoicePairs);

	// EnumList for gen_defn                                                                                       
	const ChoicePair gen_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NORMAL_SCENARIOS, "Normal Scenarios")
		,ChoicePair(StrEnum::SHOCKED_SCENARIOS, "Shocked Scenarios")
	};
	const EnumList gen_defnEnumList(2, gen_defnChoicePairs);

	// EnumList for gen_detail_defn                                                                                       
	const ChoicePair gen_detail_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gen_detail_defnEnumList(2, gen_detail_defnChoicePairs);

	// EnumList for gen_initial_valn_period                                                                                       
	const ChoicePair gen_initial_valn_periodChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gen_initial_valn_periodEnumList(2, gen_initial_valn_periodChoicePairs);

	// EnumList for gen_rates_freq                                                                                       
	const ChoicePair gen_rates_freqChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList gen_rates_freqEnumList(2, gen_rates_freqChoicePairs);

	// EnumList for gen_rn_defn                                                                                       
	const ChoicePair gen_rn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::QUICK_GENERATION, "Quick Generation")
		,ChoicePair(StrEnum::COMPLETE_GENERATION, "Complete Generation")
	};
	const EnumList gen_rn_defnEnumList(2, gen_rn_defnChoicePairs);

	// EnumList for gen_rn_int_proj_defn                                                                                       
	const ChoicePair gen_rn_int_proj_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CONSTANT, "Constant")
		,ChoicePair(StrEnum::TERM_STRUCTURE, "Term Structure")
	};
	const EnumList gen_rn_int_proj_defnEnumList(2, gen_rn_int_proj_defnChoicePairs);

	// EnumList for gen_rw_stoch_defn                                                                                       
	const ChoicePair gen_rw_stoch_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::RANDOM_SCENARIOS, "Random Scenarios")
		,ChoicePair(StrEnum::ACADEMY_SELECTED_SCENARIOS, "Academy Selected Scenarios")
	};
	const EnumList gen_rw_stoch_defnEnumList(2, gen_rw_stoch_defnChoicePairs);

	// EnumList for get_fx_rate_defn                                                                                       
	const ChoicePair get_fx_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DIRECT, "Direct")
		,ChoicePair(StrEnum::INDIRECT, "Indirect")
	};
	const EnumList get_fx_rate_defnEnumList(2, get_fx_rate_defnChoicePairs);

	// EnumList for get_index_rate_defn                                                                                       
	const ChoicePair get_index_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GET_GROWTH_RATE, "Get Growth Rate")
		,ChoicePair(StrEnum::GET_TOTAL_RETURN, "Get Total Return")
		,ChoicePair(StrEnum::GET_INCOME_RETURN, "Get Income Return")
		,ChoicePair(StrEnum::GET_DIVIDEND_YIELD, "Get Dividend Yield")
	};
	const EnumList get_index_rate_defnEnumList(4, get_index_rate_defnChoicePairs);

	// EnumList for get_index_val_shift_defn                                                                                       
	const ChoicePair get_index_val_shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::PRICE_SHIFT, "Price Shift")
	};
	const EnumList get_index_val_shift_defnEnumList(2, get_index_val_shift_defnChoicePairs);

	// EnumList for get_index_vol_shift_defn                                                                                       
	const ChoicePair get_index_vol_shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::VOL_SHIFT, "Vol Shift")
	};
	const EnumList get_index_vol_shift_defnEnumList(2, get_index_vol_shift_defnChoicePairs);

	// EnumList for get_int_rate_defn                                                                                       
	const ChoicePair get_int_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GET_YIELD_RATE, "Get Yield Rate")
		,ChoicePair(StrEnum::GET_SPOT_RATE, "Get Spot Rate")
		,ChoicePair(StrEnum::GET_FORWARD_RATE, "Get Forward Rate")
		,ChoicePair(StrEnum::GET_SPOT_SPREAD, "Get Spot Spread")
		,ChoicePair(StrEnum::GET_YIELD_SPREAD, "Get Yield Spread")
	};
	const EnumList get_int_rate_defnEnumList(5, get_int_rate_defnChoicePairs);

	// EnumList for get_int_rate_shift_defn                                                                                       
	const ChoicePair get_int_rate_shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::SPOT_SHIFT, "Spot Shift")
		,ChoicePair(StrEnum::YIELD_SHIFT, "Yield Shift")
	};
	const EnumList get_int_rate_shift_defnEnumList(3, get_int_rate_shift_defnChoicePairs);

	// EnumList for get_scen_set_defn                                                                                       
	const ChoicePair get_scen_set_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::OUTER_LOOP, "Outer Loop")
		,ChoicePair(StrEnum::INNER_LOOP, "Inner Loop")
	};
	const EnumList get_scen_set_defnEnumList(2, get_scen_set_defnChoicePairs);

	// EnumList for infl_defn                                                                                       
	const ChoicePair infl_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::STOCHASTIC, "Stochastic")
		,ChoicePair(StrEnum::DETERMINISTIC, "Deterministic")
	};
	const EnumList infl_defnEnumList(2, infl_defnChoicePairs);

	// EnumList for inner_loop_valn_scen_reuse_defn                                                                                       
	const ChoicePair inner_loop_valn_scen_reuse_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ALL_RATES, "All Rates")
		,ChoicePair(StrEnum::INDEX_RATES_ONLY, "Index Rates Only")
		,ChoicePair(StrEnum::NONE, "None")
	};
	const EnumList inner_loop_valn_scen_reuse_defnEnumList(3, inner_loop_valn_scen_reuse_defnChoicePairs);

	// EnumList for int_rate_shock_defn                                                                                       
	const ChoicePair int_rate_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList int_rate_shock_defnEnumList(2, int_rate_shock_defnChoicePairs);

	// EnumList for missing_val_defn                                                                                       
	const ChoicePair missing_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PREVIOUS, "Previous")
		,ChoicePair(StrEnum::INTERPOLATE, "Interpolate")
	};
	const EnumList missing_val_defnEnumList(2, missing_val_defnChoicePairs);

	// EnumList for phldr_shock_defn                                                                                       
	const ChoicePair phldr_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList phldr_shock_defnEnumList(2, phldr_shock_defnChoicePairs);

	// EnumList for save_time_step_scen_files_defn                                                                                       
	const ChoicePair save_time_step_scen_files_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList save_time_step_scen_files_defnEnumList(2, save_time_step_scen_files_defnChoicePairs);

	// EnumList for time_step_defn                                                                                       
	const ChoicePair time_step_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList time_step_defnEnumList(2, time_step_defnChoicePairs);

	// EnumList for use_shifted_yld_curve_defn                                                                                       
	const ChoicePair use_shifted_yld_curve_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList use_shifted_yld_curve_defnEnumList(2, use_shifted_yld_curve_defnChoicePairs);

	// EnumList for yld_curve_mem_defn                                                                                       
	const ChoicePair yld_curve_mem_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::RELEASE, "Release")
		,ChoicePair(StrEnum::RETAIN, "Retain")
	};
	const EnumList yld_curve_mem_defnEnumList(2, yld_curve_mem_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace RATES_ECONOMY_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(RATES_ECONOMY::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(RATES_ECONOMY::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace RATES_ECONOMY_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void RATES_ECONOMY::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> RATES_ECONOMY::mgr_;

	Attribute::Descriptor RATES_ECONOMY::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"calib_index_rate_div_yld", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rate_div_yld,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STRING,	"calib_index_rate_moneyness_selected", -1, (size_t)&modelOffset->calib_index_rate_moneyness_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STR_ENUM,	"calib_index_rate_normalize_wghts_defn", -1, (size_t)&modelOffset->calib_index_rate_normalize_wghts_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calib_index_rate_normalize_wghts_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::STR_ENUM,	"calib_index_rate_opt_defn", -1, (size_t)&modelOffset->calib_index_rate_opt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calib_index_rate_opt_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"calib_index_rate_opt_vol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rate_opt_vol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"calib_index_rate_opt_wght", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rate_opt_wght,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"calib_index_rate_selected", -1, (size_t)&modelOffset->calib_index_rate_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"calib_index_rate_terms_selected", -1, (size_t)&modelOffset->calib_index_rate_terms_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"calib_index_rates_pass_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rates_pass_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"calib_index_rates_percentile", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rates_percentile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"calib_index_rates_percentile_tgt", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_index_rates_percentile_tgt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::INT,	"calib_index_rates_tgt_horizon", -1, (size_t)&modelOffset->calib_index_rates_tgt_horizon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::INT,	"calib_test_num", -1, (size_t)&modelOffset->calib_test_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STRING,	"calib_yld_curve_bond_terms_selected", -1, (size_t)&modelOffset->calib_yld_curve_bond_terms_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"calib_yld_curve_bond_vol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_bond_vol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::DOUBLE,	"calib_yld_curve_bond_wght", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_bond_wght,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STR_ENUM,	"calib_yld_curve_data_source_defn", -1, (size_t)&modelOffset->calib_yld_curve_data_source_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calib_yld_curve_data_source_defnEnumList, Feature(true)),
	Descriptor(17, Attribute::STR_ENUM,	"calib_yld_curve_normalize_wghts_defn", -1, (size_t)&modelOffset->calib_yld_curve_normalize_wghts_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calib_yld_curve_normalize_wghts_defnEnumList, Feature(true)),
	Descriptor(18, Attribute::DOUBLE,	"calib_yld_curve_rates_pass_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_rates_pass_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"calib_yld_curve_rates_percentile", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_rates_percentile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"calib_yld_curve_rates_percentile_tgt", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_rates_percentile_tgt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"calib_yld_curve_rates_rate_adj_a", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_rates_rate_adj_a,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"calib_yld_curve_rates_rate_adj_b", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_rates_rate_adj_b,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::INT,	"calib_yld_curve_rates_rate_term", -1, (size_t)&modelOffset->calib_yld_curve_rates_rate_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::INT,	"calib_yld_curve_rates_tgt_horizon", -1, (size_t)&modelOffset->calib_yld_curve_rates_tgt_horizon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STRING,	"calib_yld_curve_selected", -1, (size_t)&modelOffset->calib_yld_curve_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"calib_yld_curve_sprds_pass_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_sprds_pass_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::DOUBLE,	"calib_yld_curve_sprds_percentile", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_sprds_percentile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::DOUBLE,	"calib_yld_curve_sprds_percentile_tgt", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_sprds_percentile_tgt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"calib_yld_curve_sprds_sprd_adj", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_sprds_sprd_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::INT,	"calib_yld_curve_sprds_tgt_horizon", -1, (size_t)&modelOffset->calib_yld_curve_sprds_tgt_horizon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"calib_yld_curve_swap_maturities_selected", -1, (size_t)&modelOffset->calib_yld_curve_swap_maturities_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STRING,	"calib_yld_curve_swap_tenors_selected", -1, (size_t)&modelOffset->calib_yld_curve_swap_tenors_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::DOUBLE,	"calib_yld_curve_swaption_vol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_swaption_vol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::DOUBLE,	"calib_yld_curve_swaption_wght", Descriptor::NOT_INDEXED, (size_t)&modelOffset->calib_yld_curve_swaption_wght,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STRING,	"correl_id1", -1, (size_t)&modelOffset->correl_id1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::STRING,	"correl_id2", -1, (size_t)&modelOffset->correl_id2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::STR_ENUM,	"credit_sprd_defn", -1, (size_t)&modelOffset->credit_sprd_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &credit_sprd_defnEnumList, Feature(true)),
	Descriptor(38, Attribute::DOUBLE,	"credit_sprd_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_sprd_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::DOUBLE,	"credit_sprd_intercept_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_sprd_intercept_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"credit_sprd_slope_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_sprd_slope_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"credit_sprd_stoch_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_sprd_stoch_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::STR_ENUM,	"cubic_spline_enhancement_wtw_switch_aig", -1, (size_t)&modelOffset->cubic_spline_enhancement_wtw_switch_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cubic_spline_enhancement_wtw_switch_aigEnumList, Feature(true)),
	Descriptor(43, Attribute::INT,	"date_lookup_gen2", -1, (size_t)&modelOffset->date_lookup_gen2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::DOUBLE,	"dflt_rate_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dflt_rate_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::DOUBLE,	"dflt_rate_stoch_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dflt_rate_stoch_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::DOUBLE,	"econ_data_correlation", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_correlation,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::STRING,	"econ_data_index_rate_moneyness_selected", -1, (size_t)&modelOffset->econ_data_index_rate_moneyness_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::DOUBLE,	"econ_data_index_rate_mr_grwth", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_index_rate_mr_grwth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::DOUBLE,	"econ_data_index_rate_mr_inc_ret", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_index_rate_mr_inc_ret,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::DOUBLE,	"econ_data_index_rate_mr_sprd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_index_rate_mr_sprd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::DOUBLE,	"econ_data_index_rate_mr_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_index_rate_mr_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::STRING,	"econ_data_index_rate_selected", -1, (size_t)&modelOffset->econ_data_index_rate_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::STRING,	"econ_data_index_rate_tenor_selected", -1, (size_t)&modelOffset->econ_data_index_rate_tenor_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::DOUBLE,	"econ_data_index_rate_vol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_index_rate_vol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::DOUBLE,	"econ_data_misc_rates", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_misc_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::STRING,	"econ_data_misc_rates_selected", -1, (size_t)&modelOffset->econ_data_misc_rates_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::DOUBLE,	"econ_data_yld_curve_mr_rates", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_yld_curve_mr_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STRING,	"econ_data_yld_curve_selected", -1, (size_t)&modelOffset->econ_data_yld_curve_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::STRING,	"econ_data_yld_curve_term_selected", -1, (size_t)&modelOffset->econ_data_yld_curve_term_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::DOUBLE,	"econ_data_yld_curve_vol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->econ_data_yld_curve_vol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::STRING,	"econ_data_yld_curve_vol_mr_term_selected", -1, (size_t)&modelOffset->econ_data_yld_curve_vol_mr_term_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::STR_ENUM,	"eqt_price_shock_defn", -1, (size_t)&modelOffset->eqt_price_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &eqt_price_shock_defnEnumList, Feature(true)),
	Descriptor(63, Attribute::DOUBLE,	"eqt_vol_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eqt_vol_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(64, Attribute::STR_ENUM,	"eqt_vol_shock_defn", -1, (size_t)&modelOffset->eqt_vol_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &eqt_vol_shock_defnEnumList, Feature(true)),
	Descriptor(65, Attribute::STRING,	"eqt_vol_shock_id", -1, (size_t)&modelOffset->eqt_vol_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::STR_ENUM,	"gen_approach_defn", -1, (size_t)&modelOffset->gen_approach_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_approach_defnEnumList, Feature(true)),
	Descriptor(67, Attribute::STR_ENUM,	"gen_basis_defn", -1, (size_t)&modelOffset->gen_basis_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_basis_defnEnumList, Feature(true)),
	Descriptor(68, Attribute::STR_ENUM,	"gen_calib_defn", -1, (size_t)&modelOffset->gen_calib_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_calib_defnEnumList, Feature(true)),
	Descriptor(69, Attribute::STR_ENUM,	"gen_calib_detail_defn", -1, (size_t)&modelOffset->gen_calib_detail_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_calib_detail_defnEnumList, Feature(true)),
	Descriptor(70, Attribute::INT,	"gen_calib_retry_attempts", -1, (size_t)&modelOffset->gen_calib_retry_attempts,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(71, Attribute::STR_ENUM,	"gen_defn", -1, (size_t)&modelOffset->gen_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_defnEnumList, Feature(true)),
	Descriptor(72, Attribute::STR_ENUM,	"gen_detail_defn", -1, (size_t)&modelOffset->gen_detail_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_detail_defnEnumList, Feature(true)),
	Descriptor(73, Attribute::INT,	"gen_detail_scen", -1, (size_t)&modelOffset->gen_detail_scen,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(74, Attribute::INT,	"gen_hist_mths", -1, (size_t)&modelOffset->gen_hist_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::STR_ENUM,	"gen_initial_valn_period", -1, (size_t)&modelOffset->gen_initial_valn_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_initial_valn_periodEnumList, Feature(true)),
	Descriptor(76, Attribute::INT,	"gen_mean_reversion_mths", -1, (size_t)&modelOffset->gen_mean_reversion_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::INT,	"gen_mths", -1, (size_t)&modelOffset->gen_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::INT,	"gen_random_seed", -1, (size_t)&modelOffset->gen_random_seed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::STR_ENUM,	"gen_rates_freq", -1, (size_t)&modelOffset->gen_rates_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_rates_freqEnumList, Feature(true)),
	Descriptor(80, Attribute::ARRAY_DOUBLE,	"gen_rn_bonds_term", -1, (size_t)&modelOffset->gen_rn_bonds_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(4)),
	Descriptor(81, Attribute::STR_ENUM,	"gen_rn_defn", -1, (size_t)&modelOffset->gen_rn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_rn_defnEnumList, Feature(true)),
	Descriptor(82, Attribute::STR_ENUM,	"gen_rn_int_proj_defn", -1, (size_t)&modelOffset->gen_rn_int_proj_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_rn_int_proj_defnEnumList, Feature(true)),
	Descriptor(83, Attribute::DOUBLE,	"gen_rw_mrp_mean_yrs_1", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gen_rw_mrp_mean_yrs_1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(84, Attribute::DOUBLE,	"gen_rw_mrp_mean_yrs_2", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gen_rw_mrp_mean_yrs_2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(85, Attribute::DOUBLE,	"gen_rw_mrp_median_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gen_rw_mrp_median_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(86, Attribute::STR_ENUM,	"gen_rw_stoch_defn", -1, (size_t)&modelOffset->gen_rw_stoch_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen_rw_stoch_defnEnumList, Feature(true)),
	Descriptor(87, Attribute::INT,	"gen_scenarios", -1, (size_t)&modelOffset->gen_scenarios,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(88, Attribute::STR_ENUM,	"gen2_defn", -1, (size_t)&modelOffset->gen2_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen2_defnEnumList, Feature(true)),
	Descriptor(89, Attribute::STR_ENUM,	"get_fx_rate_defn", -1, (size_t)&modelOffset->get_fx_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_fx_rate_defnEnumList, Feature(true)),
	Descriptor(90, Attribute::STR_ENUM,	"get_index_rate_defn", -1, (size_t)&modelOffset->get_index_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_index_rate_defnEnumList, Feature(true)),
	Descriptor(91, Attribute::STR_ENUM,	"get_index_val_shift_defn", -1, (size_t)&modelOffset->get_index_val_shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_index_val_shift_defnEnumList, Feature(true)),
	Descriptor(92, Attribute::STR_ENUM,	"get_index_vol_shift_defn", -1, (size_t)&modelOffset->get_index_vol_shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_index_vol_shift_defnEnumList, Feature(true)),
	Descriptor(93, Attribute::STR_ENUM,	"get_int_rate_defn", -1, (size_t)&modelOffset->get_int_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_int_rate_defnEnumList, Feature(true)),
	Descriptor(94, Attribute::STR_ENUM,	"get_int_rate_shift_defn", -1, (size_t)&modelOffset->get_int_rate_shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_int_rate_shift_defnEnumList, Feature(true)),
	Descriptor(95, Attribute::STR_ENUM,	"get_scen_set_defn", -1, (size_t)&modelOffset->get_scen_set_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &get_scen_set_defnEnumList, Feature(true)),
	Descriptor(96, Attribute::STRING,	"historic_rates_id", -1, (size_t)&modelOffset->historic_rates_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(97, Attribute::STRING,	"index_id", -1, (size_t)&modelOffset->index_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(98, Attribute::DOUBLE,	"index_vol_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_vol_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(99, Attribute::DOUBLE,	"index_vol_stoch_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_vol_stoch_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(100, Attribute::STR_ENUM,	"infl_defn", -1, (size_t)&modelOffset->infl_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &infl_defnEnumList, Feature(true)),
	Descriptor(101, Attribute::DOUBLE,	"infl_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->infl_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(102, Attribute::STRING,	"inner_loop_historic_rates_id", -1, (size_t)&modelOffset->inner_loop_historic_rates_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(103, Attribute::STRING,	"inner_loop_valn_scen_id", -1, (size_t)&modelOffset->inner_loop_valn_scen_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(104, Attribute::STR_ENUM,	"inner_loop_valn_scen_reuse_defn", -1, (size_t)&modelOffset->inner_loop_valn_scen_reuse_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inner_loop_valn_scen_reuse_defnEnumList, Feature(true)),
	Descriptor(105, Attribute::DOUBLE,	"int_rate_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(106, Attribute::STR_ENUM,	"int_rate_shock_defn", -1, (size_t)&modelOffset->int_rate_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &int_rate_shock_defnEnumList, Feature(true)),
	Descriptor(107, Attribute::STRING,	"int_rate_shock_id", -1, (size_t)&modelOffset->int_rate_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(108, Attribute::DOUBLE,	"int_vol_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_vol_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(109, Attribute::DOUBLE,	"int_vol_stoch_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_vol_stoch_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(110, Attribute::STRING,	"investment_set_aig", -1, (size_t)&modelOffset->investment_set_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(111, Attribute::STRING,	"liquidity_spread_set_aig", -1, (size_t)&modelOffset->liquidity_spread_set_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(112, Attribute::STR_ENUM,	"missing_val_defn", -1, (size_t)&modelOffset->missing_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &missing_val_defnEnumList, Feature(true)),
	Descriptor(113, Attribute::DOUBLE,	"moneyness", Descriptor::NOT_INDEXED, (size_t)&modelOffset->moneyness,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(114, Attribute::INT,	"open_file_retry_attempts", -1, (size_t)&modelOffset->open_file_retry_attempts,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(115, Attribute::STR_ENUM,	"phldr_shock_defn", -1, (size_t)&modelOffset->phldr_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &phldr_shock_defnEnumList, Feature(true)),
	Descriptor(116, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(117, Attribute::STRING,	"quality_id", -1, (size_t)&modelOffset->quality_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(118, Attribute::STRING,	"rate_setting_cycle_aig", -1, (size_t)&modelOffset->rate_setting_cycle_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(119, Attribute::DOUBLE,	"rate_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rate_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(120, Attribute::STR_ENUM,	"save_time_step_scen_files_defn", -1, (size_t)&modelOffset->save_time_step_scen_files_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &save_time_step_scen_files_defnEnumList, Feature(true)),
	Descriptor(121, Attribute::INT,	"scen_eof_period_aig", -1, (size_t)&modelOffset->scen_eof_period_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(122, Attribute::STRING,	"scen_file_name_addn", -1, (size_t)&modelOffset->scen_file_name_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(123, Attribute::STRING,	"scen_id", -1, (size_t)&modelOffset->scen_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(124, Attribute::STRING,	"scen_index_id", -1, (size_t)&modelOffset->scen_index_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(125, Attribute::INT,	"shock_freq", -1, (size_t)&modelOffset->shock_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(126, Attribute::STRING,	"shock_id", -1, (size_t)&modelOffset->shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(127, Attribute::STRING,	"swap_curve_rate_id_aig", -1, (size_t)&modelOffset->swap_curve_rate_id_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(128, Attribute::STRING,	"swap_curve_tenors_input_aig", -1, (size_t)&modelOffset->swap_curve_tenors_input_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(129, Attribute::DOUBLE,	"swap_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->swap_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(130, Attribute::DOUBLE,	"swap_tenor", Descriptor::NOT_INDEXED, (size_t)&modelOffset->swap_tenor,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(131, Attribute::STR_ENUM,	"time_step_defn", -1, (size_t)&modelOffset->time_step_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &time_step_defnEnumList, Feature(true)),
	Descriptor(132, Attribute::STR_ENUM,	"use_shifted_yld_curve_defn", -1, (size_t)&modelOffset->use_shifted_yld_curve_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_shifted_yld_curve_defnEnumList, Feature(true)),
	Descriptor(133, Attribute::STRING,	"valn_periods_selected", -1, (size_t)&modelOffset->valn_periods_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(134, Attribute::STRING,	"yld_curve_id", -1, (size_t)&modelOffset->yld_curve_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(135, Attribute::STR_ENUM,	"yld_curve_mem_defn", -1, (size_t)&modelOffset->yld_curve_mem_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &yld_curve_mem_defnEnumList, Feature(true)),
	Descriptor(136, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(137, Attribute::SCALAR_STRING,	"gen_scen_file_path", -1, (size_t)&modelOffset->gen_scen_file_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&RATES_ECONOMY_UDF::rates_economy_gen_scen_file_path)),
	Descriptor(138, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&RATES_ECONOMY_UDF::rates_economy_proj_date_adj)),
	Descriptor(139, Attribute::SCALAR_INT,	"proj_date_offset", -1, (size_t)&modelOffset->proj_date_offset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&RATES_ECONOMY_UDF::rates_economy_proj_date_offset)),
	Descriptor(140, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&RATES_ECONOMY_UDF::rates_economy_proj_start_date)),
	Descriptor(141, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&RATES_ECONOMY_UDF::rates_economy_proj_start_mth)),
	Descriptor(142, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&RATES_ECONOMY_UDF::rates_economy_proj_start_yr)),
	};

	Attribute::Descriptor* RATES_ECONOMY::descriptorTable[] = {
	&RATES_ECONOMY::descriptor_0[0],
	&RATES_ECONOMY::descriptor_0[1],
	&RATES_ECONOMY::descriptor_0[2],
	&RATES_ECONOMY::descriptor_0[3],
	&RATES_ECONOMY::descriptor_0[4],
	&RATES_ECONOMY::descriptor_0[5],
	&RATES_ECONOMY::descriptor_0[6],
	&RATES_ECONOMY::descriptor_0[7],
	&RATES_ECONOMY::descriptor_0[8],
	&RATES_ECONOMY::descriptor_0[9],
	&RATES_ECONOMY::descriptor_0[10],
	&RATES_ECONOMY::descriptor_0[11],
	&RATES_ECONOMY::descriptor_0[12],
	&RATES_ECONOMY::descriptor_0[13],
	&RATES_ECONOMY::descriptor_0[14],
	&RATES_ECONOMY::descriptor_0[15],
	&RATES_ECONOMY::descriptor_0[16],
	&RATES_ECONOMY::descriptor_0[17],
	&RATES_ECONOMY::descriptor_0[18],
	&RATES_ECONOMY::descriptor_0[19],
	&RATES_ECONOMY::descriptor_0[20],
	&RATES_ECONOMY::descriptor_0[21],
	&RATES_ECONOMY::descriptor_0[22],
	&RATES_ECONOMY::descriptor_0[23],
	&RATES_ECONOMY::descriptor_0[24],
	&RATES_ECONOMY::descriptor_0[25],
	&RATES_ECONOMY::descriptor_0[26],
	&RATES_ECONOMY::descriptor_0[27],
	&RATES_ECONOMY::descriptor_0[28],
	&RATES_ECONOMY::descriptor_0[29],
	&RATES_ECONOMY::descriptor_0[30],
	&RATES_ECONOMY::descriptor_0[31],
	&RATES_ECONOMY::descriptor_0[32],
	&RATES_ECONOMY::descriptor_0[33],
	&RATES_ECONOMY::descriptor_0[34],
	&RATES_ECONOMY::descriptor_0[35],
	&RATES_ECONOMY::descriptor_0[36],
	&RATES_ECONOMY::descriptor_0[37],
	&RATES_ECONOMY::descriptor_0[38],
	&RATES_ECONOMY::descriptor_0[39],
	&RATES_ECONOMY::descriptor_0[40],
	&RATES_ECONOMY::descriptor_0[41],
	&RATES_ECONOMY::descriptor_0[42],
	&RATES_ECONOMY::descriptor_0[43],
	&RATES_ECONOMY::descriptor_0[44],
	&RATES_ECONOMY::descriptor_0[45],
	&RATES_ECONOMY::descriptor_0[46],
	&RATES_ECONOMY::descriptor_0[47],
	&RATES_ECONOMY::descriptor_0[48],
	&RATES_ECONOMY::descriptor_0[49],
	&RATES_ECONOMY::descriptor_0[50],
	&RATES_ECONOMY::descriptor_0[51],
	&RATES_ECONOMY::descriptor_0[52],
	&RATES_ECONOMY::descriptor_0[53],
	&RATES_ECONOMY::descriptor_0[54],
	&RATES_ECONOMY::descriptor_0[55],
	&RATES_ECONOMY::descriptor_0[56],
	&RATES_ECONOMY::descriptor_0[57],
	&RATES_ECONOMY::descriptor_0[58],
	&RATES_ECONOMY::descriptor_0[59],
	&RATES_ECONOMY::descriptor_0[60],
	&RATES_ECONOMY::descriptor_0[61],
	&RATES_ECONOMY::descriptor_0[62],
	&RATES_ECONOMY::descriptor_0[63],
	&RATES_ECONOMY::descriptor_0[64],
	&RATES_ECONOMY::descriptor_0[65],
	&RATES_ECONOMY::descriptor_0[66],
	&RATES_ECONOMY::descriptor_0[67],
	&RATES_ECONOMY::descriptor_0[68],
	&RATES_ECONOMY::descriptor_0[69],
	&RATES_ECONOMY::descriptor_0[70],
	&RATES_ECONOMY::descriptor_0[71],
	&RATES_ECONOMY::descriptor_0[72],
	&RATES_ECONOMY::descriptor_0[73],
	&RATES_ECONOMY::descriptor_0[74],
	&RATES_ECONOMY::descriptor_0[75],
	&RATES_ECONOMY::descriptor_0[76],
	&RATES_ECONOMY::descriptor_0[77],
	&RATES_ECONOMY::descriptor_0[78],
	&RATES_ECONOMY::descriptor_0[79],
	&RATES_ECONOMY::descriptor_0[80],
	&RATES_ECONOMY::descriptor_0[81],
	&RATES_ECONOMY::descriptor_0[82],
	&RATES_ECONOMY::descriptor_0[83],
	&RATES_ECONOMY::descriptor_0[84],
	&RATES_ECONOMY::descriptor_0[85],
	&RATES_ECONOMY::descriptor_0[86],
	&RATES_ECONOMY::descriptor_0[87],
	&RATES_ECONOMY::descriptor_0[88],
	&RATES_ECONOMY::descriptor_0[89],
	&RATES_ECONOMY::descriptor_0[90],
	&RATES_ECONOMY::descriptor_0[91],
	&RATES_ECONOMY::descriptor_0[92],
	&RATES_ECONOMY::descriptor_0[93],
	&RATES_ECONOMY::descriptor_0[94],
	&RATES_ECONOMY::descriptor_0[95],
	&RATES_ECONOMY::descriptor_0[96],
	&RATES_ECONOMY::descriptor_0[97],
	&RATES_ECONOMY::descriptor_0[98],
	&RATES_ECONOMY::descriptor_0[99],
	&RATES_ECONOMY::descriptor_0[100],
	&RATES_ECONOMY::descriptor_0[101],
	&RATES_ECONOMY::descriptor_0[102],
	&RATES_ECONOMY::descriptor_0[103],
	&RATES_ECONOMY::descriptor_0[104],
	&RATES_ECONOMY::descriptor_0[105],
	&RATES_ECONOMY::descriptor_0[106],
	&RATES_ECONOMY::descriptor_0[107],
	&RATES_ECONOMY::descriptor_0[108],
	&RATES_ECONOMY::descriptor_0[109],
	&RATES_ECONOMY::descriptor_0[110],
	&RATES_ECONOMY::descriptor_0[111],
	&RATES_ECONOMY::descriptor_0[112],
	&RATES_ECONOMY::descriptor_0[113],
	&RATES_ECONOMY::descriptor_0[114],
	&RATES_ECONOMY::descriptor_0[115],
	&RATES_ECONOMY::descriptor_0[116],
	&RATES_ECONOMY::descriptor_0[117],
	&RATES_ECONOMY::descriptor_0[118],
	&RATES_ECONOMY::descriptor_0[119],
	&RATES_ECONOMY::descriptor_0[120],
	&RATES_ECONOMY::descriptor_0[121],
	&RATES_ECONOMY::descriptor_0[122],
	&RATES_ECONOMY::descriptor_0[123],
	&RATES_ECONOMY::descriptor_0[124],
	&RATES_ECONOMY::descriptor_0[125],
	&RATES_ECONOMY::descriptor_0[126],
	&RATES_ECONOMY::descriptor_0[127],
	&RATES_ECONOMY::descriptor_0[128],
	&RATES_ECONOMY::descriptor_0[129],
	&RATES_ECONOMY::descriptor_0[130],
	&RATES_ECONOMY::descriptor_0[131],
	&RATES_ECONOMY::descriptor_0[132],
	&RATES_ECONOMY::descriptor_0[133],
	&RATES_ECONOMY::descriptor_0[134],
	&RATES_ECONOMY::descriptor_0[135],
	&RATES_ECONOMY::descriptor_0[136],
	&RATES_ECONOMY::descriptor_0[137],
	&RATES_ECONOMY::descriptor_0[138],
	&RATES_ECONOMY::descriptor_0[139],
	&RATES_ECONOMY::descriptor_0[140],
	&RATES_ECONOMY::descriptor_0[141],
	&RATES_ECONOMY::descriptor_0[142],
	nullptr};
	const size_t RATES_ECONOMY::sDescriptorCount = 143;

//factory
RATES_ECONOMY* RATES_ECONOMY::makeThis(int isSubmodel, ModelClass* owner, RATES_ECONOMY* peer, 
						int mainRebase, const xstring &name, RATES_ECONOMY_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("RATES_ECONOMY::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor RATES_ECONOMY");
#endif
	RATES_ECONOMY* newP = (RATES_ECONOMY*)new RATES_ECONOMY_UDF
   	  ("rates_economy", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
RATES_ECONOMY_persistent_object* RATES_ECONOMY_persistent_object::makeThis(int isSubmodel, ModelClass* owner, RATES_ECONOMY* peer, 
							int mainRebase, const xstring &name, RATES_ECONOMY_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("RATES_ECONOMY_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor RATES_ECONOMY_persistent_object");
#endif
	RATES_ECONOMY_persistent_object* newP = (RATES_ECONOMY_persistent_object*)new RATES_ECONOMY_persistent_object
   	  ("rates_economy", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			RATES_ECONOMY_persistent_object* pd = dynamic_cast<RATES_ECONOMY_persistent_object*>(product);
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

typedef double (RATES_ECONOMY_UDF::*dPF) ();
typedef double (RATES_ECONOMY_UDF::*dPFd) (double);
typedef int (RATES_ECONOMY_UDF::*iPF) ();
typedef int (RATES_ECONOMY_UDF::*iPFi) (int);
typedef xstring (RATES_ECONOMY_UDF::*sPF) ();
typedef xstring (RATES_ECONOMY_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
RATES_ECONOMY::RATES_ECONOMY(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas133(company_liab_fia_fia_sfas133)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, hedge_grp(company_seg_hedge_grp)
	, intex(company_asset_intex)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (RATES_ECONOMY_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
RATES_ECONOMY::RATES_ECONOMY(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(17, RATES_ECONOMY::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas133(company_liab_fia_fia_sfas133)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, hedge_grp(company_seg_hedge_grp)
	, intex(company_asset_intex)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
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
#ifdef __CREATE_ADCO_ASSET_CLASS_
       company_asset_adco = 0;
#endif
#ifdef __CREATE_A_SUBPORT_ASSET_CLASS_
       company_asset_asset_sub_port = 0;
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
       company_asset_bond = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_is = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_pv = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_ym = 0;
#endif
#ifdef __CREATE_EIO_ASSET_CLASS_
       company_asset_eio = 0;
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
       company_asset_epa = 0;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
       company_asset_intex = 0;
#endif
#ifdef __CREATE_MTG_ASSET_CLASS_
       company_asset_mtg = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_mtg_is = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_mtg_pv = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_mtg_ym = 0;
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
       company_inv_strategy = 0;
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
       company_liab_fia_carvm_stat = 0;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
       company_liab_fia_carvm_tax = 0;
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
       company_liab_fia_fia_account = 0;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_liab_fia_fia_ann_pba = 0;
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
       company_liab_fia_fia_automation = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_liab_fia_fia_rates = 0;
#endif
#ifdef __CREATE_SFAS133_GAAP_CLASS_
       company_liab_fia_fia_sfas133 = 0;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
       company_liab_fia_fia_sfas97rd = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_seg_ann_pba = 0;
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
       company_seg_hedge_grp = 0;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
       company_seg_sfas97rd = 0;
#endif
#ifdef __CREATE_UTIL_RAFM_CLASS_
       util = 0;
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

	for (int cf_no = 1; cf_no <= 17; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (RATES_ECONOMY_UDF::*dPXi2) (int, int);
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

	

 void RATES_ECONOMY::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_A_SUBPORT_ASSET_CLASS_
		company_asset_asset_sub_port = (A_SUBPORT_ASSET*)(findUnique("company|asset|asset_sub_port"));
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
		company_asset_bond = (BOND_ASSET*)(findUnique("company|asset|bond"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_is = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_is"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_pv = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_pv"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_ym = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_ym"));
#endif
#ifdef __CREATE_EIO_ASSET_CLASS_
		company_asset_eio = (EIO_ASSET*)(findUnique("company|asset|eio"));
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
		company_asset_epa = (EPA_ASSET*)(findUnique("company|asset|epa"));
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
		company_asset_intex = (INTEX_ASSET*)(findUnique("company|asset|intex"));
#endif
#ifdef __CREATE_MTG_ASSET_CLASS_
		company_asset_mtg = (MTG_ASSET*)(findUnique("company|asset|mtg"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_mtg_is = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_is"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_mtg_pv = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_pv"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_mtg_ym = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_ym"));
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
		company_inv_strategy = (INVSTRAT_ASSET*)(findUnique("company|inv_strategy"));
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
		company_liab = (LIAB_LIAB*)(findUnique("company|liab"));
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
		company_liab_fia_carvm_stat = (FIACARVM_LIAB*)(findUnique("company|liab|fia|carvm_stat"));
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
		company_liab_fia_carvm_tax = (FIACARVM_LIAB*)(findUnique("company|liab|fia|carvm_tax"));
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
		company_liab_fia_fia_account = (FIAAFUND_LIAB*)(findUnique("company|liab|fia|fia_account"));
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_liab_fia_fia_ann_pba = (ANN_PBA_PBA*)(findUnique("company|liab|fia|fia_ann_pba"));
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
		company_liab_fia_fia_automation = (AUTOMATION*)(findUnique("company|liab|fia|fia_automation"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_liab_fia_fia_rates = (RATES_ECONOMY*)(findUnique("company|liab|fia|fia_rates"));
#endif
#ifdef __CREATE_SFAS133_GAAP_CLASS_
		company_liab_fia_fia_sfas133 = (SFAS133_GAAP*)(findUnique("company|liab|fia|fia_sfas133"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_liab_fia_fia_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|liab|fia|fia_sfas97rd"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_seg_ann_pba = (ANN_PBA_PBA*)(findUnique("company|seg|ann_pba"));
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
		company_seg_hedge_grp = (HDG_GRP_COMP*)(findUnique("company|seg|hedge_grp"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
#ifdef __CREATE_UTIL_RAFM_CLASS_
		util = (UTIL_RAFM*)(findUnique("util"));
#endif
 }
//copy_names END@2


 void RATES_ECONOMY::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int RATES_ECONOMY_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& RATES_ECONOMY_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double RATES_ECONOMY_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int RATES_ECONOMY_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double RATES_ECONOMY_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double RATES_ECONOMY_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void RATES_ECONOMY_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void RATES_ECONOMY_persistent_object::write(long include_submodels) {
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

	void RATES_ECONOMY_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void RATES_ECONOMY_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void RATES_ECONOMY_persistent_object::write(const xstring& key, long include_submodels) {
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




	RATES_ECONOMY_persistent_object::~RATES_ECONOMY_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool RATES_ECONOMY_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void RATES_ECONOMY_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void RATES_ECONOMY_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void RATES_ECONOMY_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void RATES_ECONOMY_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void RATES_ECONOMY_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* RATES_ECONOMY_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* RATES_ECONOMY_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* RATES_ECONOMY_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char RATES_ECONOMY_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void RATES_ECONOMY_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
RATES_ECONOMY_persistent_object::RATES_ECONOMY_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			RATES_ECONOMY(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(RATES_ECONOMY::sm_bond_is)
	, sm_bond_pv(RATES_ECONOMY::sm_bond_pv)
	, sm_bond_ym(RATES_ECONOMY::sm_bond_ym)
	, sm_mtg_is(RATES_ECONOMY::sm_mtg_is)
	, sm_mtg_pv(RATES_ECONOMY::sm_mtg_pv)
	, sm_mtg_ym(RATES_ECONOMY::sm_mtg_ym)

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
RATES_ECONOMY::~RATES_ECONOMY() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void RATES_ECONOMY::findTargetColumns() {

}
//findTargetColumns END@2
void RATES_ECONOMY::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void RATES_ECONOMY::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void RATES_ECONOMY::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void RATES_ECONOMY::start_of_projection() {
}
//start_of_projection END@2

void RATES_ECONOMY::end_of_projection() {
}
//end_of_projection END@2

void RATES_ECONOMY::start_of_layer() {
}


void RATES_ECONOMY::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void RATES_ECONOMY::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void RATES_ECONOMY::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void RATES_ECONOMY::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> RATES_ECONOMY::ddfVector;
BitArray RATES_ECONOMY::dataVariables(143);
bool RATES_ECONOMY::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool RATES_ECONOMY::writeClassInfo = true;

void RATES_ECONOMY::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, RATES_ECONOMY::descriptor_0>::dT = RATES_ECONOMY::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, RATES_ECONOMY::descriptor_0>::dT = RATES_ECONOMY::descriptor_0;

