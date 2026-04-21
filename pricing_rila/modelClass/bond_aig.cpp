
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
#include "ModelClass\bond_aig_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
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
#ifndef bond_aig_TableDefs
#define bond_aig_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection BOND_AIG::TTHC;
void BOND_AIG::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - asset_amt_matured_aig
// Asset Amount Matured, End of Period                                                                                             
// Column:ASSET_AMT_MATURED_AIG
//========================================================
double BOND_AIG_UDF::bond_aig_asset_amt_matured_aig(int t) {
//^^^



//^^^

#line 1 "asset_amt_matured_aig.BOND_AIG.for"
/*! AIG Bond Asset Maturity Amount
	==============================
	@author Michael Ching
	@date 20181119
 
	This function determines if any assets have matured at period t. The way this works is that asset amounts
	purchased at prior t's are stored in this column: BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_new_aig(). Their corresponding
	maturity dates are stored in this column: bond_aig_asset_maturity_period_aig(). These two columns create
	an asset amount/maturity date pair.

	This column will iterate backwards in time and read asset amount/maturity date pairs. If a pair matures at the
	current t, it has reached maturity "now" and the corresponding asset amount will be returned. 

	If there are multiple bonds, asset amounts are prorated by bond count.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period ||	t > final_period || !fia_bond_portfolio_aig->initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	return NO_AVG;
}

if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->avg_coupon_rt_aig at period " << t << MSG_USER;
}

double asset_amt_matured = 0.0;

for (int asset_idx = commencement_period; asset_idx < t; asset_idx++)
{
	if (asset_maturity_period_aig(asset_idx) == t)
	{
		asset_amt_matured += fia_bond_portfolio_aig->asset_amt_new_aig(asset_idx) * prop_bond_portfolio;
	}
}

return asset_amt_matured;

}


//@@ END

//@@ START - asset_maturity_period_aig
// Asset Maturity Period                                                                                             
// Column:ASSET_MATURITY_PERIOD_AIG
//========================================================
double BOND_AIG_UDF::bond_aig_asset_maturity_period_aig(int t) {
//^^^



//^^^

#line 1 "asset_maturity_period_aig.BOND_AIG.for"
/*! AIG Bond Asset Maturity Date
	============================
	@author Michael Ching
	@date 20181119
 
	This function determines new asset maturity period by using the bond's new asset duration and
	performing a cubic spline lookup against the new asset duration curve to get an appropriate tenor.
	The maturity date is then rounded down.

	- The cubic spline interpolation is performed by RATES_ECONOMY::cubic_spline_interpolation_aig(),
	- The new asset duration is calculated in bond_aig_duration_new_asset_aig(), and
	- The new asset duration curve is calculated in BOND_PORTFOLIO_AIG::initialize_new_asset_durations_aig().
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period ||	t > final_period || !fia_bond_portfolio_aig->initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	return NO_AVG;
}

if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->asset_maturity_date_aig at period " << t << MSG_USER;
}

// Get new asset duration
double new_asset_duration = duration_new_asset_aig(t);

if (new_asset_duration > SMALL_DOUBLE)
{
	// Get new asset duration curve
	vector <double> new_asset_duration_curve = fia_bond_portfolio_aig->get_new_asset_duration_curve_aig(t);

	// Get maturity via lookup
	//double maturity_period = rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, new_asset_rate_tenors);
	double maturity_period = 0.0;
	
	if (gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		maturity_period = fia_rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, new_asset_rate_tenors);
	else
		maturity_period = rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, new_asset_rate_tenors);//WTW - Gen2 - New formula for default spline parameters

	// 20181212 MTC - Bugfix to add months to months instead of months to years
	maturity_period += t;

	// Divide by coupon frequency to produce either months or years
	maturity_period /= fia_bond_portfolio_aig->coupon_freq_aig;

	// Round, then multiply by coupon frequency to get months. This ensures maturities occur on a coupon payment.
	maturity_period = round(maturity_period, 0) * fia_bond_portfolio_aig->coupon_freq_aig;

	return maturity_period;
}
else
{
	return 0.0;
}

}


//@@ END

//@@ START - asset_yld_aig
// Asset Yield                                                                                             
// Column:ASSET_YLD_AIG
//========================================================
double BOND_AIG_UDF::bond_aig_asset_yld_aig(int t) {
//^^^



//^^^

#line 1 "asset_yld_aig.BOND_AIG.for"
/*! AIG Bond Asset Yield
	====================
	@author Michael Ching
	@date 20181119
 
	The asset yield for a single bond is calculated as a lookup on the par yield curve with an adjustment.
	For a given period,

	-# Use the bond's new asset duration to find the par yield (coupon rate) via cubic 
	spline interpolation on the new asset duration curve and the par yield curve. The new asset duration is
	calculated from bond_aig_duration_new_asset_aig(), the par yield curve is calculated from 
	BOND_PORTFOLIO_AIG::initialize_par_yields_aig(), and the new asset duration curve is calculated from
	BOND_PORTFOLIO_AIG::initialize_new_asset_durations_aig(). Cubic spline interpolation is provided by
	RATES_ECONOMY::cubic_spline_interpolation_aig().
	-# Adjust the par yield for the portfolio's asset yield adjustment:

	   \f[
	   asset\,yield_{t} = new\,asset\,coupon\,rate_{t} + asset\,yield\,adjustment
	   \f]

	   Where,
	   -# \f$asset\,yield_{t}\f$ is the asset yield and period \f$t\f$
	   -# \f$new\,asset\,coupon\,rate_{t}\f$ is the coupon rate derived from the cubic spline
	      interpolation described above, and
	   -# \f$asset\,yield\,adjustment\f$ is an input
	.

	If the new asset duration is 0, then use the prior coupon rate.
 
	Related Inputs:
	---------------
	-# **UI** `asset_yld_addn_aig` - Asset yield addition, as a percentage.
 
	@return Nothing.
*/
if (t < commencement_period ||	t > final_period || !fia_bond_portfolio_aig->initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	return NO_AVG;
}

if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->asset_yld_aig at period " << t << MSG_USER;
}

double new_asset_duration = duration_new_asset_aig(t);

if (new_asset_duration > SMALL_DOUBLE)
{
	// Initialize
	vector <double> new_asset_duration_curve = fia_bond_portfolio_aig->get_new_asset_duration_curve_aig(t);
	vector <double> par_yield_curve = fia_bond_portfolio_aig->get_par_yield_curve_aig(t);

	//double asset_yld = rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, par_yield_curve) + fia_bond_portfolio_aig->asset_yld_addn_aig;

	double asset_yld = 0.0;

	if (gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		asset_yld = fia_rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, par_yield_curve) + fia_bond_portfolio_aig->asset_yld_addn_aig; 
	else
		asset_yld = rates->cubic_spline_interpolation_aig(new_asset_duration, new_asset_duration_curve, par_yield_curve) + fia_bond_portfolio_aig->asset_yld_addn_aig;//WTW - Gen2 - New formula for default spline parameters

	return asset_yld;
}
else
{
	return asset_yld_aig(t - 1);
}

}


//@@ END

//@@ START - duration_new_asset_aig
// New Asset Duration                                                                                             
// Column:DURATION_NEW_ASSET_AIG
//========================================================
double BOND_AIG_UDF::bond_aig_duration_new_asset_aig(int t) {
//^^^



//^^^

#line 1 "duration_new_asset_aig.BOND_AIG.for"
/*! AIG Bond New Asset Duration
	===========================
	@author Michael Ching
	@date 20181119
 
	For now, this just returns the new asset duration from the portfolio level:

	BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_new_asset_aig();

	We'd probably want to update this for multiple bonds in the future.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t < commencement_period ||	t > final_period || !fia_bond_portfolio_aig->initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	return NO_AVG;
}

if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->duration_new_asset_aig at period " << t << MSG_USER;
}

if (fia_bond_portfolio_aig->bond_count_aig > 1)
{
	throw FatalError("bond_aig->duration_new_asset_aig cannot handle multiple bonds!");
}

return fia_bond_portfolio_aig->duration_new_asset_aig(t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double BOND_AIG_UDF::bond_aig_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.BOND_AIG.for"
// This column sets the group name for printing output
if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->initialize at period " << t << MSG_USER;
}

// Add model class to output file list. MCHING 1-26-2022
// Bugfix to vGrid race condition. MCHING 2-15-2022
if (is_first_modelpoint && overall_is_first_proj_task_loop)
{
	fia_automation->append_to_file_manifest_aig(output_location());
}

//WTW - Gen2 - move to parent startup() for performance
//xstring group_name = bond_id_aig;
//setGroup(group_name);

return 1.0;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double BOND_AIG_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.BOND_AIG.for"
#if 0 // START_CLASS
vector <double> new_asset_rate_tenors;
double prop_bond_portfolio;
#endif // END_CLASS

if (fia_bond_portfolio_aig->print_debug_output_defn_aig == YES)
{
	log_screen << "bond_aig->startup at period " << t << MSG_USER;
}

// Calculate proportion of this bond in the total bond portfolio. This is approximated by count.
prop_bond_portfolio = 1.0 / double(fia_bond_portfolio_aig->bond_count_aig);

return 1.0;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int BOND_AIG_UDF::bond_aig_commencement_period() {
//^^^


#line 1 "commencement_period.BOND_AIG.for"
return fia_bond_portfolio_aig->commencement_period;

}


//@@ END

//@@ START - final_period
// WTW Gen2 final_period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int BOND_AIG_UDF::bond_aig_final_period() {
//^^^


#line 1 "final_period.BOND_AIG.for"
return fia_bond_portfolio_aig->final_period;

}


//@@ END

//@@ START - maturity_period
// Period t in which Policy Matures                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int BOND_AIG_UDF::bond_aig_maturity_period() {
//^^^


#line 1 "maturity_period.BOND_AIG.for"
return fia_bond_portfolio_aig->maturity_period;

}


//@@ END


	static BOND_AIG_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (BOND_AIG_UDF::*dPXi) (int);
typedef double (BOND_AIG_UDF::*dPXid) (int, double);
typedef double (BOND_AIG_UDF::*dPF) ();
typedef double (BOND_AIG_UDF::*dPFd) (double);
typedef int (BOND_AIG_UDF::*iPF) ();
typedef int (BOND_AIG_UDF::*iPFi) (int);
typedef xstring (BOND_AIG_UDF::*sPF) ();
typedef xstring (BOND_AIG_UDF::*sPFs) (xstring);

const CashFlowCommonData BOND_AIG::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "asset_amt_matured_aig", "bond_aig_asset_amt_matured_aig",  "asset_amt_matured_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::bond_aig_asset_amt_matured_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_amt_matured_aig),
	CashFlowCommonData(2, "asset_maturity_period_aig", "bond_aig_asset_maturity_period_aig",  "asset_maturity_period_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::bond_aig_asset_maturity_period_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_maturity_period_aig),
	CashFlowCommonData(3, "asset_yld_aig", "bond_aig_asset_yld_aig",  "asset_yld_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::bond_aig_asset_yld_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_yld_aig),
	CashFlowCommonData(4, "duration_new_asset_aig", "bond_aig_duration_new_asset_aig",  "duration_new_asset_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::bond_aig_duration_new_asset_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->duration_new_asset_aig),
	CashFlowCommonData(5, "initialize", "bond_aig_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::bond_aig_initialize, 'E','Y', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(6, "startup", "bond_aig_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_AIG_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* BOND_AIG::mCFStaticData[] = {
	&BOND_AIG::mCFStaticData_0[0],
	&BOND_AIG::mCFStaticData_0[1],
	&BOND_AIG::mCFStaticData_0[2],
	&BOND_AIG::mCFStaticData_0[3],
	&BOND_AIG::mCFStaticData_0[4],
	&BOND_AIG::mCFStaticData_0[5],
	&BOND_AIG::mCFStaticData_0[6],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for gen2_defn                                                                                       
	const ChoicePair gen2_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gen2_defnEnumList(2, gen2_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace BOND_AIG_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(BOND_AIG::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(BOND_AIG::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace BOND_AIG_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void BOND_AIG::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> BOND_AIG::mgr_;

	Attribute::Descriptor BOND_AIG::descriptor_0[] = {
	Descriptor(0, Attribute::STRING,	"bond_id_aig", -1, (size_t)&modelOffset->bond_id_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STR_ENUM,	"gen2_defn", -1, (size_t)&modelOffset->gen2_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen2_defnEnumList, Feature(true)),
	Descriptor(2, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_AIG_UDF::bond_aig_commencement_period)),
	Descriptor(4, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_AIG_UDF::bond_aig_final_period)),
	Descriptor(5, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_AIG_UDF::bond_aig_maturity_period)),
	};

	Attribute::Descriptor* BOND_AIG::descriptorTable[] = {
	&BOND_AIG::descriptor_0[0],
	&BOND_AIG::descriptor_0[1],
	&BOND_AIG::descriptor_0[2],
	&BOND_AIG::descriptor_0[3],
	&BOND_AIG::descriptor_0[4],
	&BOND_AIG::descriptor_0[5],
	nullptr};
	const size_t BOND_AIG::sDescriptorCount = 6;

//factory
BOND_AIG* BOND_AIG::makeThis(int isSubmodel, ModelClass* owner, BOND_AIG* peer, 
						int mainRebase, const xstring &name, BOND_AIG_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_AIG::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_AIG");
#endif
	BOND_AIG* newP = (BOND_AIG*)new BOND_AIG_UDF
   	  ("bond_aig", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
BOND_AIG_persistent_object* BOND_AIG_persistent_object::makeThis(int isSubmodel, ModelClass* owner, BOND_AIG* peer, 
							int mainRebase, const xstring &name, BOND_AIG_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_AIG_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_AIG_persistent_object");
#endif
	BOND_AIG_persistent_object* newP = (BOND_AIG_persistent_object*)new BOND_AIG_persistent_object
   	  ("bond_aig", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			BOND_AIG_persistent_object* pd = dynamic_cast<BOND_AIG_persistent_object*>(product);
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

typedef double (BOND_AIG_UDF::*dPF) ();
typedef double (BOND_AIG_UDF::*dPFd) (double);
typedef int (BOND_AIG_UDF::*iPF) ();
typedef int (BOND_AIG_UDF::*iPFi) (int);
typedef xstring (BOND_AIG_UDF::*sPF) ();
typedef xstring (BOND_AIG_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
BOND_AIG::BOND_AIG(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_AIG_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
BOND_AIG::BOND_AIG(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(6, BOND_AIG::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
	, rates(company_rates)
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

#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
       company_liab_fia_fia_automation = 0;
#endif
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
       company_liab_fia_fia_bond_portfolio_aig = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_liab_fia_fia_rates = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
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

	for (int cf_no = 1; cf_no <= 6; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_AIG_UDF::*dPXi2) (int, int);
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


 void BOND_AIG::copy_names() {

#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
		company_liab_fia_fia_automation = (AUTOMATION*)(findUnique("company|liab|fia|fia_automation"));
#endif
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
		company_liab_fia_fia_bond_portfolio_aig = (BOND_PORTFOLIO_AIG*)(findUnique("company|liab|fia|fia_bond_portfolio_aig"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_liab_fia_fia_rates = (RATES_ECONOMY*)(findUnique("company|liab|fia|fia_rates"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
 }
//copy_names END@2


 void BOND_AIG::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int BOND_AIG_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& BOND_AIG_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double BOND_AIG_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int BOND_AIG_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double BOND_AIG_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double BOND_AIG_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void BOND_AIG_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_AIG_persistent_object::write(long include_submodels) {
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

	void BOND_AIG_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_AIG_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_AIG_persistent_object::write(const xstring& key, long include_submodels) {
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




	BOND_AIG_persistent_object::~BOND_AIG_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool BOND_AIG_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void BOND_AIG_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void BOND_AIG_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void BOND_AIG_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_AIG_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_AIG_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* BOND_AIG_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* BOND_AIG_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* BOND_AIG_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char BOND_AIG_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void BOND_AIG_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
BOND_AIG_persistent_object::BOND_AIG_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			BOND_AIG(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(BOND_AIG::sm_bond_is)
	, sm_bond_pv(BOND_AIG::sm_bond_pv)
	, sm_bond_ym(BOND_AIG::sm_bond_ym)
	, sm_mtg_is(BOND_AIG::sm_mtg_is)
	, sm_mtg_pv(BOND_AIG::sm_mtg_pv)
	, sm_mtg_ym(BOND_AIG::sm_mtg_ym)

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
BOND_AIG::~BOND_AIG() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void BOND_AIG::findTargetColumns() {

}
//findTargetColumns END@2
void BOND_AIG::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void BOND_AIG::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void BOND_AIG::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void BOND_AIG::start_of_projection() {
}
//start_of_projection END@2

void BOND_AIG::end_of_projection() {
}
//end_of_projection END@2

void BOND_AIG::start_of_layer() {
}


void BOND_AIG::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void BOND_AIG::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void BOND_AIG::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void BOND_AIG::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> BOND_AIG::ddfVector;
BitArray BOND_AIG::dataVariables(6);
bool BOND_AIG::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool BOND_AIG::writeClassInfo = true;

void BOND_AIG::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, BOND_AIG::descriptor_0>::dT = BOND_AIG::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, BOND_AIG::descriptor_0>::dT = BOND_AIG::descriptor_0;

