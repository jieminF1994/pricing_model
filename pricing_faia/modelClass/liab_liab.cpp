
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
#include "ModelClass\liab_liab_udf.h"
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

sowmpoutput ul_state_of_world_mp_output;
sowmpoutput vul_state_of_world_mp_output;
sowmpoutput iul_state_of_world_mp_output;
sowmpoutput term_state_of_world_mp_output;
sowmpoutput trad_state_of_world_mp_output;
sowmpoutput va_state_of_world_mp_output;
sowmpoutput fa_state_of_world_mp_output;
sowmpoutput fia_state_of_world_mp_output;
sowmpoutput pa_state_of_world_mp_output;
sowmpoutput pa_state_of_world_benefits_mp_output;
sowmpoutput ltc_state_of_world_mp_output;
sowmpoutput ul_state_of_world_reins_mp_output;
sowmpoutput vul_state_of_world_reins_mp_output;
sowmpoutput iul_state_of_world_reins_mp_output;
sowmpoutput term_state_of_world_reins_mp_output;
sowmpoutput trad_state_of_world_reins_mp_output;
sowmpoutput ltc_state_of_world_reins_mp_output;
sowmpoutput ul_state_of_world_rider_mp_output;
sowmpoutput vul_state_of_world_rider_mp_output;
sowmpoutput iul_state_of_world_rider_mp_output;
sowmpoutput term_state_of_world_rider_mp_output;
sowmpoutput trad_state_of_world_rider_mp_output;

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
#ifndef liab_liab_TableDefs
#define liab_liab_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection LIAB_LIAB::TTHC;
void LIAB_LIAB::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double LIAB_LIAB_UDF::liab_liab_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.LIAB_LIAB.for"
return 1.0;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double LIAB_LIAB_UDF::liab_liab_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.LIAB_LIAB.for"
if (model_point_fatal_error_issued)
	throw FatalError("Model Point Fatal Errors have occurred. Please review your data.");

if (t == 0 && independent_mp_defn == YES) 
	{
	if (!hedge_valn_flag)
		log_screen << ".... Beginning Independent Model Point Processing" << MSG_USER;

	#if defined(__UL_LIAB_H_)
	running_parallel_flag = false;
	sm_ul.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_ul.runParallel();
	#endif

	#if defined(__VUL_LIAB_H_)
	running_parallel_flag = false;
	sm_vul.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_vul.runParallel();
	#endif

	#if defined(__IUL_LIAB_H_)
	running_parallel_flag = false;
	sm_iul.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_iul.runParallel();
	#endif

	#if defined(__TERM_LIAB_H_)
	running_parallel_flag = false;
	sm_term.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_term.runParallel();
	#endif

	#if defined(__TRAD_LIAB_H_)
	running_parallel_flag = false;
	sm_trad.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_trad.runParallel();
	#endif

	#if defined(__VA_LIAB_H_)
	running_parallel_flag = false;
	sm_va.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	if (!hedge_valn_shock_flag)
		sm_va.runParallel();
	#endif

	#if defined(__FA_LIAB_H_)
	running_parallel_flag = false;
	sm_fa.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_fa.runParallel();
	#endif

	#if defined(__FIA_LIAB_H_)
	running_parallel_flag = false;
	sm_fia.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_fia.runParallel();
	#endif

	#if defined(__PA_LIAB_H_)
	running_parallel_flag = false;
	sm_pa.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_pa.runParallel();
	#endif

	#if defined(__LTC_LIAB_H_)
	running_parallel_flag = false;
	sm_ltc.runSeriatim("seriatim_run_tgt", 0, 0, true);
	running_parallel_flag = true;
	sm_ltc.runParallel();
	#endif

	if (!hedge_valn_flag)
		log_screen << ".... Completed Independent Model Point Processing" << MSG_USER;
	}

return 1.0;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double LIAB_LIAB_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.LIAB_LIAB.for"
#if 0 // START_EXTERNS
sowmpoutput ul_state_of_world_mp_output;
sowmpoutput vul_state_of_world_mp_output;
sowmpoutput iul_state_of_world_mp_output;
sowmpoutput term_state_of_world_mp_output;
sowmpoutput trad_state_of_world_mp_output;
sowmpoutput va_state_of_world_mp_output;
sowmpoutput fa_state_of_world_mp_output;
sowmpoutput fia_state_of_world_mp_output;
sowmpoutput pa_state_of_world_mp_output;
sowmpoutput pa_state_of_world_benefits_mp_output;
sowmpoutput ltc_state_of_world_mp_output;
sowmpoutput ul_state_of_world_reins_mp_output;
sowmpoutput vul_state_of_world_reins_mp_output;
sowmpoutput iul_state_of_world_reins_mp_output;
sowmpoutput term_state_of_world_reins_mp_output;
sowmpoutput trad_state_of_world_reins_mp_output;
sowmpoutput ltc_state_of_world_reins_mp_output;
sowmpoutput ul_state_of_world_rider_mp_output;
sowmpoutput vul_state_of_world_rider_mp_output;
sowmpoutput iul_state_of_world_rider_mp_output;
sowmpoutput term_state_of_world_rider_mp_output;
sowmpoutput trad_state_of_world_rider_mp_output;
#endif // END_EXTERNS

#if 0 // START_TERMINATOR
ul_state_of_world_mp_output.close();
vul_state_of_world_mp_output.close();
iul_state_of_world_mp_output.close();
term_state_of_world_mp_output.close();
trad_state_of_world_mp_output.close();
va_state_of_world_mp_output.close();
fa_state_of_world_mp_output.close();
fia_state_of_world_mp_output.close();
pa_state_of_world_mp_output.close();
pa_state_of_world_benefits_mp_output.close();
ltc_state_of_world_mp_output.close();
ul_state_of_world_reins_mp_output.close();
vul_state_of_world_reins_mp_output.close();
iul_state_of_world_reins_mp_output.close();
term_state_of_world_reins_mp_output.close();
trad_state_of_world_reins_mp_output.close();
ltc_state_of_world_reins_mp_output.close();
ul_state_of_world_rider_mp_output.close();
vul_state_of_world_rider_mp_output.close();
iul_state_of_world_rider_mp_output.close();
term_state_of_world_rider_mp_output.close();
trad_state_of_world_rider_mp_output.close();
#endif // END_TERMINATOR

#if defined(__UNIT_TEST_LIAB_H_)
// Setup testing liability model points
if ((num_of_proj_task_loops == 0 || is_first_proj_task_loop)
	|| restore_variables_ind == 1)
	{
	sm_testliab.resize(1);

	vector<string> mps_to_run;
	split_string_usl(sm_testliab[0]->mps_selected.c_str(), mps_to_run, ",");//WTW - Gen2 - split_tring internal RAFM function
	int mp_count = mps_to_run.size();

	if (mp_count > sm_testliab.size())
		sm_testliab.resize(mp_count);
	}
#endif

#if defined(__UL_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_ul.getPersistentObject()->sm_ul_ireins.setModelPointFileId(sm_ul.getPersistentObject()->ms_ul_ireins_readfile, "keyfield");
	sm_ul.getPersistentObject()->sm_ul_ireins.gotoRec(1);
	sm_ul.getPersistentObject()->sm_ul_irider.setModelPointFileId(sm_ul.getPersistentObject()->ms_ul_irider_readfile, "keyfield");
	sm_ul.getPersistentObject()->sm_ul_irider.gotoRec(1);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_vul.getPersistentObject()->sm_vul_ireins.setModelPointFileId(sm_vul.getPersistentObject()->ms_vul_ireins_readfile, "keyfield");
	sm_vul.getPersistentObject()->sm_vul_ireins.gotoRec(1);
	sm_vul.getPersistentObject()->sm_vul_irider.setModelPointFileId(sm_vul.getPersistentObject()->ms_vul_irider_readfile, "keyfield");
	sm_vul.getPersistentObject()->sm_vul_irider.gotoRec(1);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_iul.getPersistentObject()->sm_iul_ireins.setModelPointFileId(sm_iul.getPersistentObject()->ms_iul_ireins_readfile, "keyfield");
	sm_iul.getPersistentObject()->sm_iul_ireins.gotoRec(1);
	sm_iul.getPersistentObject()->sm_iul_irider.setModelPointFileId(sm_iul.getPersistentObject()->ms_iul_irider_readfile, "keyfield");
	sm_iul.getPersistentObject()->sm_iul_irider.gotoRec(1);
	}
#endif

#if defined(__TERM_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_term.getPersistentObject()->sm_term_ireins.setModelPointFileId(sm_term.getPersistentObject()->ms_term_ireins_readfile, "keyfield");
	sm_term.getPersistentObject()->sm_term_ireins.gotoRec(1);
	sm_term.getPersistentObject()->sm_term_irider.setModelPointFileId(sm_term.getPersistentObject()->ms_term_irider_readfile, "keyfield");
	sm_term.getPersistentObject()->sm_term_irider.gotoRec(1);
	}
#endif

#if defined(__TRAD_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_trad.getPersistentObject()->sm_trad_ireins.setModelPointFileId(sm_trad.getPersistentObject()->ms_trad_ireins_readfile, "keyfield");
	sm_trad.getPersistentObject()->sm_trad_ireins.gotoRec(1);
	sm_trad.getPersistentObject()->sm_trad_irider.setModelPointFileId(sm_trad.getPersistentObject()->ms_trad_irider_readfile, "keyfield");
	sm_trad.getPersistentObject()->sm_trad_irider.gotoRec(1);
	}
#endif

#if defined(__PA_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_pa.getPersistentObject()->sm_pa_benefits.setModelPointFileId(sm_pa.getPersistentObject()->ms_pa_benefits_readfile, "keyfield");
	sm_pa.getPersistentObject()->sm_pa_benefits.gotoRec(1);
	}
#endif

#if defined(__LTC_LIAB_H_)
if (independent_mp_defn == YES && num_of_proj_task_loops > 1 && !is_first_proj_task_loop)
	{
	sm_ltc.getPersistentObject()->sm_ltc_ireins.setModelPointFileId(sm_ltc.getPersistentObject()->ms_ltc_ireins_readfile, "keyfield");
	sm_ltc.getPersistentObject()->sm_ltc_ireins.gotoRec(1);
	}
#endif

return 1.0;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring LIAB_LIAB_UDF::liab_liab_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.LIAB_LIAB.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int LIAB_LIAB_UDF::liab_liab_proj_start_date() {
//^^^


#line 1 "proj_start_date.LIAB_LIAB.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int LIAB_LIAB_UDF::liab_liab_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.LIAB_LIAB.for"
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
int LIAB_LIAB_UDF::liab_liab_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.LIAB_LIAB.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END


void LIAB_LIAB::Terminator()
{

ul_state_of_world_mp_output.close();
vul_state_of_world_mp_output.close();
iul_state_of_world_mp_output.close();
term_state_of_world_mp_output.close();
trad_state_of_world_mp_output.close();
va_state_of_world_mp_output.close();
fa_state_of_world_mp_output.close();
fia_state_of_world_mp_output.close();
pa_state_of_world_mp_output.close();
pa_state_of_world_benefits_mp_output.close();
ltc_state_of_world_mp_output.close();
ul_state_of_world_reins_mp_output.close();
vul_state_of_world_reins_mp_output.close();
iul_state_of_world_reins_mp_output.close();
term_state_of_world_reins_mp_output.close();
trad_state_of_world_reins_mp_output.close();
ltc_state_of_world_reins_mp_output.close();
ul_state_of_world_rider_mp_output.close();
vul_state_of_world_rider_mp_output.close();
iul_state_of_world_rider_mp_output.close();
term_state_of_world_rider_mp_output.close();
trad_state_of_world_rider_mp_output.close();

}

FunctionPtr LIAB_LIAB::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static LIAB_LIAB_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (LIAB_LIAB_UDF::*dPXi) (int);
typedef double (LIAB_LIAB_UDF::*dPXid) (int, double);
typedef double (LIAB_LIAB_UDF::*dPF) ();
typedef double (LIAB_LIAB_UDF::*dPFd) (double);
typedef int (LIAB_LIAB_UDF::*iPF) ();
typedef int (LIAB_LIAB_UDF::*iPFi) (int);
typedef xstring (LIAB_LIAB_UDF::*sPF) ();
typedef xstring (LIAB_LIAB_UDF::*sPFs) (xstring);

const CashFlowCommonData LIAB_LIAB::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "finalize", "liab_liab_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&LIAB_LIAB_UDF::liab_liab_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(2, "initialize", "liab_liab_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&LIAB_LIAB_UDF::liab_liab_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(3, "startup", "liab_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&LIAB_LIAB_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* LIAB_LIAB::mCFStaticData[] = {
	&LIAB_LIAB::mCFStaticData_0[0],
	&LIAB_LIAB::mCFStaticData_0[1],
	&LIAB_LIAB::mCFStaticData_0[2],
	&LIAB_LIAB::mCFStaticData_0[3],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for independent_mp_defn                                                                                       
	const ChoicePair independent_mp_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList independent_mp_defnEnumList(2, independent_mp_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace LIAB_LIAB_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(LIAB_LIAB::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(LIAB_LIAB::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace LIAB_LIAB_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void LIAB_LIAB::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> LIAB_LIAB::mgr_;

	Attribute::Descriptor LIAB_LIAB::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"independent_mp_defn", -1, (size_t)&modelOffset->independent_mp_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &independent_mp_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STRING,	"ms_epl_readfile", -1, (size_t)&modelOffset->ms_epl_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STRING,	"ms_fia_readfile", -1, (size_t)&modelOffset->ms_fia_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&LIAB_LIAB_UDF::liab_liab_proj_date_adj)),
	Descriptor(6, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&LIAB_LIAB_UDF::liab_liab_proj_start_date)),
	Descriptor(7, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&LIAB_LIAB_UDF::liab_liab_proj_start_mth)),
	Descriptor(8, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&LIAB_LIAB_UDF::liab_liab_proj_start_yr)),
	};

	Attribute::Descriptor* LIAB_LIAB::descriptorTable[] = {
	&LIAB_LIAB::descriptor_0[0],
	&LIAB_LIAB::descriptor_0[1],
	&LIAB_LIAB::descriptor_0[2],
	&LIAB_LIAB::descriptor_0[3],
	&LIAB_LIAB::descriptor_0[4],
	&LIAB_LIAB::descriptor_0[5],
	&LIAB_LIAB::descriptor_0[6],
	&LIAB_LIAB::descriptor_0[7],
	&LIAB_LIAB::descriptor_0[8],
	nullptr};
	const size_t LIAB_LIAB::sDescriptorCount = 9;

//factory
LIAB_LIAB* LIAB_LIAB::makeThis(int isSubmodel, ModelClass* owner, LIAB_LIAB* peer, 
						int mainRebase, const xstring &name, LIAB_LIAB_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("LIAB_LIAB::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor LIAB_LIAB");
#endif
	LIAB_LIAB* newP = (LIAB_LIAB*)new LIAB_LIAB_UDF
   	  ("liab_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	newP->sm_fia.setPersistentObject(FIA_LIAB_persistent_object::makeThis(1, newP, (FIA_LIAB*)(peer?peer->sm_fia.getPersistentObject():0), mainRebase, name + "|fia", arrayTemplate?arrayTemplate->sm_fia.getPersistentObject():0, false));

	newP->sm_epl.setPersistentObject(EPL_LIAB_persistent_object::makeThis(1, newP, (EPL_LIAB*)(peer?peer->sm_epl.getPersistentObject():0), mainRebase, name + "|epl", arrayTemplate?arrayTemplate->sm_epl.getPersistentObject():0, false));


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
LIAB_LIAB_persistent_object* LIAB_LIAB_persistent_object::makeThis(int isSubmodel, ModelClass* owner, LIAB_LIAB* peer, 
							int mainRebase, const xstring &name, LIAB_LIAB_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("LIAB_LIAB_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor LIAB_LIAB_persistent_object");
#endif
	LIAB_LIAB_persistent_object* newP = (LIAB_LIAB_persistent_object*)new LIAB_LIAB_persistent_object
   	  ("liab_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			LIAB_LIAB_persistent_object* pd = dynamic_cast<LIAB_LIAB_persistent_object*>(product);
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
	newP->sm_fia.setPersistentObject(FIA_LIAB_persistent_object::makeThis(1, newP, (FIA_LIAB*)(peer?peer->sm_fia.getPersistentObject():0), mainRebase, name + "|fia", arrayTemplate?arrayTemplate->sm_fia.getPersistentObject():0, false));

	newP->sm_epl.setPersistentObject(EPL_LIAB_persistent_object::makeThis(1, newP, (EPL_LIAB*)(peer?peer->sm_epl.getPersistentObject():0), mainRebase, name + "|epl", arrayTemplate?arrayTemplate->sm_epl.getPersistentObject():0, false));

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (LIAB_LIAB_UDF::*dPF) ();
typedef double (LIAB_LIAB_UDF::*dPFd) (double);
typedef int (LIAB_LIAB_UDF::*iPF) ();
typedef int (LIAB_LIAB_UDF::*iPFi) (int);
typedef xstring (LIAB_LIAB_UDF::*sPF) ();
typedef xstring (LIAB_LIAB_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
LIAB_LIAB::LIAB_LIAB(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_epl(0, 0, 0)
  , sm_fia(0, 0, 0)
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

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (LIAB_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
LIAB_LIAB::LIAB_LIAB(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(3, LIAB_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_epl(0, 0, 0)
  , sm_fia(0, 0, 0)
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
	RegisterTerminatorOnce();

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

		adopt(&sm_epl);
		adopt(&sm_fia);

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

	for (int cf_no = 1; cf_no <= 3; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (LIAB_LIAB_UDF::*dPXi2) (int, int);
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


 void LIAB_LIAB::copy_names() {

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


 void LIAB_LIAB::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int LIAB_LIAB_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& LIAB_LIAB_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double LIAB_LIAB_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int LIAB_LIAB_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double LIAB_LIAB_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double LIAB_LIAB_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void LIAB_LIAB_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void LIAB_LIAB_persistent_object::write(long include_submodels) {
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

	void LIAB_LIAB_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void LIAB_LIAB_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void LIAB_LIAB_persistent_object::write(const xstring& key, long include_submodels) {
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




	LIAB_LIAB_persistent_object::~LIAB_LIAB_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool LIAB_LIAB_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void LIAB_LIAB_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void LIAB_LIAB_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void LIAB_LIAB_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void LIAB_LIAB_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void LIAB_LIAB_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* LIAB_LIAB_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* LIAB_LIAB_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* LIAB_LIAB_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char LIAB_LIAB_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void LIAB_LIAB_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
LIAB_LIAB_persistent_object::LIAB_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			LIAB_LIAB(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(LIAB_LIAB::sm_bond_is)
	, sm_bond_pv(LIAB_LIAB::sm_bond_pv)
	, sm_bond_ym(LIAB_LIAB::sm_bond_ym)
	, sm_mtg_is(LIAB_LIAB::sm_mtg_is)
	, sm_mtg_pv(LIAB_LIAB::sm_mtg_pv)
	, sm_mtg_ym(LIAB_LIAB::sm_mtg_ym)

	, sm_epl(LIAB_LIAB::sm_epl)
	, sm_fia(LIAB_LIAB::sm_fia)
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
LIAB_LIAB::~LIAB_LIAB() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
//	ModelClass* epl_persObj = sm_epl.getPersistentObject();
//	doAdopt(epl_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_epl.IsValidSubModelOfBaseModelClass()){
		sm_epl.resize(0);
		delete sm_epl.getPersistentObject();
		sm_epl.mPersistentObj = 0;
	}

//	ModelClass* fia_persObj = sm_fia.getPersistentObject();
//	doAdopt(fia_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia.IsValidSubModelOfBaseModelClass()){
		sm_fia.resize(0);
		delete sm_fia.getPersistentObject();
		sm_fia.mPersistentObj = 0;
	}

}
//destructor END@2
void LIAB_LIAB::findTargetColumns() {

}
//findTargetColumns END@2
void LIAB_LIAB::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void LIAB_LIAB::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void LIAB_LIAB::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void LIAB_LIAB::start_of_projection() {
}
//start_of_projection END@2

void LIAB_LIAB::end_of_projection() {
}
//end_of_projection END@2

void LIAB_LIAB::start_of_layer() {
}


void LIAB_LIAB::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void LIAB_LIAB::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void LIAB_LIAB::after_startup(int decrement) {
// Call startup for submodels
	   sm_fia.doBeforeStartupProcessing(decrement);

   if (sm_epl.isDataDrivenHolder() && sm_epl.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_epl.ms_ReadArray(false);
		if(sm_epl.gotoRec(1))
			sm_epl.readFileWithStartup();
	}
   else
	   sm_epl.doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void LIAB_LIAB::ms_BeforeStartup() {
	if (modelNameNosub() == "company|liab" && sm_fia.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_fia.ms_ReadArray(false);
  		sm_fia.setModelPointFileId(ms_fia_readfile);

		sm_fia.setSearchFields(sm_fia.getPersistentObject()->SearchFields);

  		sm_fia.resize(0);
  		if(sm_fia.gotoRec(1))
  			sm_fia.readFile();

	}
	if (modelNameNosub() == "company|liab" && sm_epl.ms_ReadArray()) {
		if (!sm_epl.isDataDrivenHolder() && iterationLoopRun) // don't read array next time
			sm_epl.ms_ReadArray(false);
  		sm_epl.setModelPointFileId(ms_epl_readfile);

		sm_epl.setSearchFields(sm_epl.getPersistentObject()->SearchFields);

  		sm_epl.resize(0);
  		if(!sm_epl.isDataDrivenHolder() && sm_epl.gotoRec(1))
  			sm_epl.readFile();

	}
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> LIAB_LIAB::ddfVector;
BitArray LIAB_LIAB::dataVariables(9);
bool LIAB_LIAB::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool LIAB_LIAB::writeClassInfo = true;

void LIAB_LIAB::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, LIAB_LIAB::descriptor_0>::dT = LIAB_LIAB::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, LIAB_LIAB::descriptor_0>::dT = LIAB_LIAB::descriptor_0;

