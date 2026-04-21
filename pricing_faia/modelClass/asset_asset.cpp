
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
#include "ModelClass\asset_asset_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
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

sowmpoutput proxy_bond_output;
sowmpoutput proxy_bond_sch_output;
sowmpoutput bond_state_of_world_mp_output;
sowmpoutput mtg_state_of_world_mp_output;
sowmpoutput sec_state_of_world_mp_output;
sowmpoutput ird_state_of_world_mp_output;
sowmpoutput re_state_of_world_mp_output;
sowmpoutput eqt_state_of_world_mp_output;
sowmpoutput eio_state_of_world_mp_output;
sowmpoutput epa_state_of_world_mp_output;

static bool first_time = true;
static int counter_asset = 1;
bool initialize_purch_asset_maps = true;

bool intex_detail_wanted = false;
bool intex_fatal_error = false;
bool adco_fatal_error = false;

extern int model_t_low;
extern int model_t_high;
extern int maximum_t_high_value;
extern int minimum_t_low_value;

ofstream& SALFile = * new ofstream;
bool is_asset_initialize = false;

// Present value calculation variables
int PVCounter;
ofstream& PVCFile = * new ofstream;
ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;

// yield maintenance detail
ofstream& YMFile = * new ofstream;

#if defined (__BOND_ASSET_H_) || defined (__MTG_ASSET_H_) || defined (__SEC_ASSET_H_)
int pv_months = 0;
int pv_last_cash_flow_month = 0;
int pv_asset_defn = -1;
int pv_model_point = -1;
double pv_initial_years_to_payment = 0;
double pv_initial_accrued_interest = 0;
double pv_initial_par_value = 0;
double pv_interest_savings_monthly_refinancing_rate = 0;
bool pv_par_val_per_unit_of_par_calculation = false;
bool pv_initialize_interest_savings_table = false;
SmartArray <double>& pv_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_interest_savings_after_prepayments = * new SmartArray <double>;

#if defined (__BOND_ASSET_H_) || defined (__MTG_ASSET_H_)
bool pv_initialize_yield_maintenance_table = false;
SmartArray <double>& pv_yield_maintenance_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_yield_maintenance_par_plus_accrued = * new SmartArray <double>;
#endif

// Bond option pricing tables and other bond tables
#if defined(__BOND_ASSET_H_)
SmartArray <double>& pv_accumulated_cash_flows = * new SmartArray <double>; 
SmartArray <double>& pv_discount_factors = * new SmartArray <double>;
SmartArray <double>& pv_discounted_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_time_weighted_discounted_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_call_amount = * new SmartArray <double>;
SmartArray <double>& pv_put_amount = * new SmartArray <double>;
SmartArray <double>& pv_scheduled_principal_payments = * new SmartArray <double>; // for WAL calculation
#endif

#if defined(__SEC_ASSET_H_)
int pv_cp_asset_defn = -1;
int pv_cp_model_point = -1;
#endif

#endif

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
#ifndef asset_asset_TableDefs
#define asset_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection ASSET_ASSET::TTHC;
void ASSET_ASSET::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_adco)
		sm_adco = 0;

	if(modelToRemove == sm_intex)
		sm_intex = 0;

}		

//@@ START - asset_detail_rpt_flag
// Asset Detail Report Flag                                                                                             
// Column:ASSET_DETAIL_RPT_FLAG
//========================================================
double ASSET_ASSET_UDF::asset_asset_asset_detail_rpt_flag(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"asset_detail_rpt_flag",t);
}



//^^^

#line 1 "asset_detail_rpt_flag.ASSET_ASSET.for"
if (t >= asset_detail_rpt_start_period
	&& t <= asset_detail_rpt_final_period)
	return 1;

return 0;

}


//@@ END

//@@ START - asset_detail_rpt_inv_strat_flag
// Asset Detail Report Investment Strategy Flag                                                                                             
// Column:ASSET_DETAIL_RPT_INV_STRAT_FLAG
//========================================================
double ASSET_ASSET_UDF::asset_asset_asset_detail_rpt_inv_strat_flag(int t) {
//^^^



//^^^

#line 1 "asset_detail_rpt_inv_strat_flag.ASSET_ASSET.for"
if (t < 0)
	return NO_AVG;

if (asset_detail_rpt_inv_strat_defn == YES 
	&& asset_detail_rpt_flag(t))
	return 1.0;

return NO_AVG;

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double ASSET_ASSET_UDF::asset_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.ASSET_ASSET.for"
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
double ASSET_ASSET_UDF::asset_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.ASSET_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double ASSET_ASSET_UDF::asset_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.ASSET_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double ASSET_ASSET_UDF::asset_asset_date(int t) {
//^^^



//^^^

#line 1 "date.ASSET_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double ASSET_ASSET_UDF::asset_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.ASSET_ASSET.for"
#if defined(__BOND_ASSET_H_)
if (sm_bond.size() > num_bonds_init)
	sm_bond.resize(num_bonds_init);
#endif
	
#if defined(__MTG_ASSET_H_)
if (sm_mtg.size() > num_mtgs_init)
	sm_mtg.resize(num_mtgs_init);
#endif
	
#if defined(__SEC_ASSET_H_)
if (sm_sec.size() > num_secs_init)
	sm_sec.resize(num_secs_init);
#endif
	
#if defined(__IRD_ASSET_H_)
if (sm_ird.size() > num_irds_init)
	sm_ird.resize(num_irds_init);
#endif
	
#if defined(__RE_ASSET_H_)
if (sm_re.size() > num_res_init)
	sm_re.resize(num_res_init);
#endif
	
#if defined(__EQT_ASSET_H_)
if (sm_eqt.size() > num_eqts_init)
	sm_eqt.resize(num_eqts_init);
#endif

#if defined(__EIO_ASSET_H_)
if (sm_eio.size() > num_eios_init)
	sm_eio.resize(num_eios_init);
#endif

#if defined(__EPA_ASSET_H_)
if (sm_epa.size() > num_epas_init)
	sm_epa.resize(num_epas_init);
#endif

#if defined(__ADCO_ASSET_H_)
if (adco)
	adco->finalize(last_proj_period);
#endif

return 1;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double ASSET_ASSET_UDF::asset_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.ASSET_ASSET.for"
// initialize existing asset information
static bool initialize_asset_data_once = true;

// create psa_base_rate
setup_psa_base_rate();
	
if (initialize_asset_data_once)
	{
	initialize_asset_data_once = false;

	// Initialize asset sub portfolio map
	set_asset_sub_port_map();
	}

if (asset_detail_rpt_pv_defn == YES)
	{
	xstring output_name = "";
	xstring output_file_name = replaceWildcards(output_location());
	output_file_name = xstring(output_file_name(0 , output_file_name.find_first_of("~")));


	asset_detail_rpt_id
	= output_file_name
	  + "_AssetPVDetail.csv";

	PVCFile.open((xstring)asset_detail_rpt_id);
	PVCFile.setf(ios::fixed, ios::floatfield);
	PVCFile.precision(12);

	if (!PVCFile)
		throw FatalError("Cannot open asset detail report file = " + asset_detail_rpt_id
		                 + ". Check that the directory has been created and that you have permission to write it.");
	else
		PVCFile << endl
				<<"Present Value Detail Report for "
				<< get_file_name(output_location()) << endl;

	xstring yld_maint_rpt_id
	= output_file_name
	  + "_AssetYMDetail.csv";

	YMFile.open(yld_maint_rpt_id);
	YMFile.setf(ios::fixed, ios::floatfield);
	YMFile.precision(12);
	
	if (!YMFile)
		throw FatalError("Error: Cannot open yield maintenance detail file = ."	+ yld_maint_rpt_id
						  +	". Check that the directory has been created and that you have permission to write it");
	else
		YMFile << endl
				<<"Yield Maintenance Detail Report for "
				<< get_file_name(output_location()) << endl;
	}

// initial values
int mp = 0;
static bool intex_databases_open = false;

#if defined(__INTEX_ASSET_H_)
if (intex_defn == YES)
	{
	if (!intex)
		throw FatalError("You have selected to use Intex but the 'intex' submodel is not valid.");

	intex->initialize(0);
	}
#endif

// capture initial number of asset elements
#if defined(__BOND_ASSET_H_)
if (num_bonds_init == -1)
	num_bonds_init = sm_bond.size();
#endif
#if defined(__MTG_ASSET_H_)
if (num_mtgs_init == -1)
	num_mtgs_init = sm_mtg.size();
#endif
#if defined(__SEC_ASSET_H_)
if (num_secs_init == -1)
	num_secs_init = sm_sec.size();
#endif
#if defined(__IRD_ASSET_H_)
if (num_irds_init == -1)
	num_irds_init = sm_ird.size();
#endif
#if defined(__RE_ASSET_H_)
if (num_res_init == -1)
	num_res_init = sm_re.size();
#endif
#if defined(__EQT_ASSET_H_)
if (num_eqts_init == -1)
	num_eqts_init = sm_eqt.size();
#endif
#if defined(__EIO_ASSET_H_)	
if (num_eios_init == -1)
	num_eios_init = sm_eio.size();
#endif
#if defined(__EPA_ASSET_H_)	
if (num_epas_init == -1)
	num_epas_init = sm_epa.size();
#endif

asset_mp_maps_reset();

return 1.0;

}


//@@ END

//@@ START - mths_to_asset_sale
// Months to Asset Sale                                                                                             
// Column:MTHS_TO_ASSET_SALE
//========================================================
double ASSET_ASSET_UDF::asset_asset_mths_to_asset_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"mths_to_asset_sale",t);
}



//^^^

#line 1 "mths_to_asset_sale.ASSET_ASSET.for"
if (t < 0)
	return NO_AVG;

if (mkt_val_calc_freq_sale == AT_ASSET_FREQUENCY)	
	return mths_to_next_mkt_val_calc(t);

if (mkt_val_calc_freq_sale == WHENEVER_NEEDED)
	return 0.0;

return NO_AVG;

}


//@@ END

//@@ START - mths_to_next_mkt_val_calc
// Months to Next Market Value Calculation                                                                                             
// Column:MTHS_TO_NEXT_MKT_VAL_CALC
//========================================================
double ASSET_ASSET_UDF::asset_asset_mths_to_next_mkt_val_calc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"mths_to_next_mkt_val_calc",t);
}



//^^^

#line 1 "mths_to_next_mkt_val_calc.ASSET_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t == 0)
	{
	if (mkt_val_calc_freq == BEGINNING_AND_END_OF_PROJECTION)
		return 9999;

	if (mkt_val_calc_freq == MONTHLY)
		return 1;

	if (mkt_val_calc_freq == QUARTERLY_MAR_JUN_SEP_DEC_)
		return (3 - ((proj_start_mth - 1) % 3));

	if (mkt_val_calc_freq == SEMIANNUALLY_JUN_DEC_)
		return (6 - ((proj_start_mth - 1) % 6));

	if (mkt_val_calc_freq == ANNUALLY_DEC_)
		return (12 - ((proj_start_mth - 1) % 12));

	if (mkt_val_calc_freq == EVERY_NTH_YEAR_DEC_)
		return (12 * mkt_val_calc_freq_yrs 
				- proj_start_mth +  1);
	}

if (t == last_model_period)	
	return 0;  

if (mths_to_next_mkt_val_calc(t - 1) > 0)	
	return mths_to_next_mkt_val_calc(t - 1) - 1;
else // if (mths_to_next_mkt_val_calc(t - 1) == 0
	{
	if (mkt_val_calc_freq == MONTHLY)	
		return 0;

	if (mkt_val_calc_freq == QUARTERLY_MAR_JUN_SEP_DEC_)
		return 2;

	if (mkt_val_calc_freq == SEMIANNUALLY_JUN_DEC_)
		return 5;

	if (mkt_val_calc_freq == ANNUALLY_DEC_)
		return 11;

	if (mkt_val_calc_freq == EVERY_NTH_YEAR_DEC_)
		return 12 * mkt_val_calc_freq_yrs - 1;
	}

return NO_AVG;

}


//@@ END

//@@ START - mths_to_sec_yld_calc
// Months to SEC Yield Calculation                                                                                             
// Column:MTHS_TO_SEC_YLD_CALC
//========================================================
double ASSET_ASSET_UDF::asset_asset_mths_to_sec_yld_calc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"mths_to_sec_yld_calc",t);
}



//^^^

#line 1 "mths_to_sec_yld_calc.ASSET_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t == 0)
	{
	if (mkt_val_calc_freq_sec_net_yld == AT_ASSET_FREQUENCY)
		return mths_to_next_mkt_val_calc(t);

	if (mkt_val_calc_freq_sec_net_yld == MONTHLY)
		return 1;

	if (mkt_val_calc_freq_sec_net_yld == QUARTERLY_MAR_JUN_SEP_DEC_)
		return 3 - ((proj_start_mth - 1) % 3);

	if (mkt_val_calc_freq_sec_net_yld == SEMIANNUALLY_JUN_DEC_)
		return 6 - ((proj_start_mth - 1) % 6);

	if (mkt_val_calc_freq_sec_net_yld == ANNUALLY_DEC_)
		return 12 - ((proj_start_mth - 1) % 12);
	}

if (mths_to_sec_yld_calc(t - 1) > 0)
	return mths_to_sec_yld_calc(t - 1) - 1;

if (mths_to_sec_yld_calc(t - 1) == 0
	&& mkt_val_calc_freq_sec_net_yld == AT_ASSET_FREQUENCY)
	return mths_to_next_mkt_val_calc(t);

if (mths_to_sec_yld_calc(t - 1) == 0
	&& mkt_val_calc_freq_sec_net_yld == MONTHLY)
	return 0;

if (mths_to_sec_yld_calc(t - 1) == 0
	&& mkt_val_calc_freq_sec_net_yld == QUARTERLY_MAR_JUN_SEP_DEC_)
	return 2;

if (mths_to_sec_yld_calc(t - 1) == 0
	&& mkt_val_calc_freq_sec_net_yld == SEMIANNUALLY_JUN_DEC_)
	return 5;

if (mths_to_sec_yld_calc(t - 1) == 0
	&& mkt_val_calc_freq_sec_net_yld == ANNUALLY_DEC_)
	return 11;

return NO_AVG;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double ASSET_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.ASSET_ASSET.for"
#if 0 // START_HEADER
#include <sstream> // for ostringstream
#include <utility> // for pair templates
#endif // END_HEADER

#if 0 // START_EXTERNS
sowmpoutput proxy_bond_output;
sowmpoutput proxy_bond_sch_output;
sowmpoutput bond_state_of_world_mp_output;
sowmpoutput mtg_state_of_world_mp_output;
sowmpoutput sec_state_of_world_mp_output;
sowmpoutput ird_state_of_world_mp_output;
sowmpoutput re_state_of_world_mp_output;
sowmpoutput eqt_state_of_world_mp_output;
sowmpoutput eio_state_of_world_mp_output;
sowmpoutput epa_state_of_world_mp_output;

static bool first_time = true;
static int counter_asset = 1;
bool initialize_purch_asset_maps = true;

bool intex_detail_wanted = false;
bool intex_fatal_error = false;
bool adco_fatal_error = false;

extern int model_t_low;
extern int model_t_high;
extern int maximum_t_high_value;
extern int minimum_t_low_value;

ofstream& SALFile = * new ofstream;
bool is_asset_initialize = false;

// Present value calculation variables
int PVCounter;
ofstream& PVCFile = * new ofstream;
ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;

// yield maintenance detail
ofstream& YMFile = * new ofstream;

#if defined (__BOND_ASSET_H_) || defined (__MTG_ASSET_H_) || defined (__SEC_ASSET_H_)
int pv_months = 0;
int pv_last_cash_flow_month = 0;
int pv_asset_defn = -1;
int pv_model_point = -1;
double pv_initial_years_to_payment = 0;
double pv_initial_accrued_interest = 0;
double pv_initial_par_value = 0;
double pv_interest_savings_monthly_refinancing_rate = 0;
bool pv_par_val_per_unit_of_par_calculation = false;
bool pv_initialize_interest_savings_table = false;
SmartArray <double>& pv_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_interest_savings_after_prepayments = * new SmartArray <double>;

#if defined (__BOND_ASSET_H_) || defined (__MTG_ASSET_H_)
bool pv_initialize_yield_maintenance_table = false;
SmartArray <double>& pv_yield_maintenance_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_yield_maintenance_par_plus_accrued = * new SmartArray <double>;
#endif

// Bond option pricing tables and other bond tables
#if defined(__BOND_ASSET_H_)
SmartArray <double>& pv_accumulated_cash_flows = * new SmartArray <double>; 
SmartArray <double>& pv_discount_factors = * new SmartArray <double>;
SmartArray <double>& pv_discounted_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_time_weighted_discounted_cash_flows = * new SmartArray <double>;
SmartArray <double>& pv_call_amount = * new SmartArray <double>;
SmartArray <double>& pv_put_amount = * new SmartArray <double>;
SmartArray <double>& pv_scheduled_principal_payments = * new SmartArray <double>; // for WAL calculation
#endif

#if defined(__SEC_ASSET_H_)
int pv_cp_asset_defn = -1;
int pv_cp_model_point = -1;
#endif

#endif
#endif // END_EXTERNS

#if 0 // START_CLASS
xstring asset_detail_rpt_id;
xstring yld_maint_rpt_id;

// Asset sub portfolio map
typedef map <xstring, int, less<xstring> > asubportmap;
asubportmap asset_sub_port_map;
asubportmap::iterator asset_sub_port_map_iter;

// Existing asset sequence number map
typedef map <xstring, int, less<xstring> > seqmap;
seqmap existing_asset_sequence_num_map;

// Asset category map
typedef map <xstring, int, less<xstring> > acatmap;
acatmap asset_category_map;

// Initial cash account_id balance maps
typedef map <xstring, double, less<xstring> > icbmap;
icbmap init_cash_bal_map;
icbmap::iterator init_cash_bal_map_iter;

typedef map <int, long, less <int> > mpmap;

int asset_mp_sequence_num;
int purch_asset_mp_num;
int maximum_spot_rate_term;

int num_bonds_init;
int num_mtgs_init;
int num_secs_init;
int num_irds_init;
int num_res_init;
int num_eqts_init;
int num_eios_init;
int num_epas_init;

double purch_asset_yrs_to_maturity;
int purch_asset_mths_to_first_reset;

// Asset subports vector
vector <string> asset_sub_ports;

SmartArray <double> psa_base_rate;

const char *zAssetFund[2];
const char *zSalesClass[5];
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
asset_detail_rpt_id = "";

// Initialize flag variables
purch_asset_mp_num = -1;
maximum_spot_rate_term = 0;

num_bonds_init = -1;
num_mtgs_init = -1;
num_secs_init = -1;
num_irds_init = -1;
num_res_init = -1;
num_eqts_init = -1;
num_eios_init = -1;
num_epas_init = -1;

purch_asset_yrs_to_maturity = 0.0;
purch_asset_mths_to_first_reset = 0;

zAssetFund[0] = "Investment";
zAssetFund[1] = "Hedge";
zSalesClass[0] = "Unknown";
zSalesClass[1] = "NotAssigned";
zSalesClass[2] = "AvailForSale";
zSalesClass[3] = "Trading";
zSalesClass[4] = "HeldToMaturity";

#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
proxy_bond_output.close();
bond_state_of_world_mp_output.close();
mtg_state_of_world_mp_output.close();
sec_state_of_world_mp_output.close();
ird_state_of_world_mp_output.close();
re_state_of_world_mp_output.close();
eqt_state_of_world_mp_output.close();
eio_state_of_world_mp_output.close();
epa_state_of_world_mp_output.close();
#endif // END_TERMINATOR

model_t_low = t_low;
model_t_high = t_high;

if (asset_detail_rpt_pv_defn != NO)
	PVCText.setf(ios::fixed);

if (overall_is_first_proj_task_loop || overall_num_of_proj_task_loops == 0)
	init_cash_bal_map.clear();

// Initialize values
investing_flag = false;
investment_period = -1;

if (alm_flag)
	{
	// Create asset sub portfolios vector
	asset_sub_ports.resize(0);

	if (asset_sub_ports_selected != "NONE")
		split_string_usl(asset_sub_ports_selected.c_str(), asset_sub_ports, ",");//WTW - Gen2 - split_tring internal RAFM function
	else
		throw FatalError ("No asset sub portfolios have been specified. Please correct asset_sub_ports_selected input variable.");

	sm_asset_sub_port.resize(company->sm_seg.size());

	for (int seg = 0; seg < sm_asset_sub_port.size(); seg++)
		{
		sm_asset_sub_port[seg].resize(asset_sub_ports.size());
		
		for (int sub_port = 0; sub_port < sm_asset_sub_port[seg].size(); sub_port++) 
            sm_asset_sub_port[seg][sub_port].resize(3); 
		}
	}

return 1.0;

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int ASSET_ASSET_UDF::asset_asset_final_period() {
//^^^


#line 1 "final_period.ASSET_ASSET.for"
return last_proj_period;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring ASSET_ASSET_UDF::asset_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.ASSET_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int ASSET_ASSET_UDF::asset_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.ASSET_ASSET.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int ASSET_ASSET_UDF::asset_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.ASSET_ASSET.for"
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
int ASSET_ASSET_UDF::asset_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.ASSET_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - scen_day
// Scenario Day                                                                                             
// Calculated Variable:SCEN_DAY
//========================================================
int ASSET_ASSET_UDF::asset_asset_scen_day() {
//^^^


#line 1 "scen_day.ASSET_ASSET.for"
return 29;

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int ASSET_ASSET_UDF::asset_asset_start_period() {
//^^^


#line 1 "start_period.ASSET_ASSET.for"
return 0;

}


//@@ END


#line 1 "asset_detail_log_rebase_reset.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::asset_detail_log_rebase_reset(int t, const xstring &rebase_model, const xstring &caller, const xstring &identifier, const xstring &id_submodel_name)
{
PVCText << "," << rebase_model
		<< " at t = " << t
		<< " in " << caller
		<< " " << identifier
		<< " |" << id_submodel_name;

asset_detail_rpt_pv_output();

return;
}



#line 1 "asset_detail_rpt_pv_output.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::asset_detail_rpt_pv_output()
{
// This function outputs PVCText.str() to the PVCFile or to the run log file.
// PVCText must be initialized before a call to this function.
// This function clears the PVCText variable.

if (asset_detail_rpt_pv_defn == YES)
	PVCFile << endl << PVCText.str() << endl;
else // "Summary to Run Log"
	log_screen << "PVSum: " << PVCText.str() << MSG_USER;

PVCText.str("");

return;
}



#line 1 "asset_mp_maps_reset.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::asset_mp_maps_reset()
{
int mp = -1;
int seg_num = -1;

for (seg_num = 0; seg_num < company->sm_seg.size(); seg_num++)
	{
	#if defined(__BOND_ASSET_H_)
	company->sm_seg[seg_num]->bond_mp_map_active.clear();
	company->sm_seg[seg_num]->bond_mp_map_inactive.clear();
	#endif
	#if defined(__MTG_ASSET_H_)
	company->sm_seg[seg_num]->mtg_mp_map_active.clear();
	company->sm_seg[seg_num]->mtg_mp_map_inactive.clear();
	#endif
	#if defined(__SEC_ASSET_H_)
	company->sm_seg[seg_num]->sec_mp_map_active.clear();
	company->sm_seg[seg_num]->sec_mp_map_inactive.clear();
	#endif
	#if defined(__IRD_ASSET_H_)
	company->sm_seg[seg_num]->ird_mp_map_active.clear();
	company->sm_seg[seg_num]->ird_mp_map_inactive.clear();
	#endif
	#if defined(__RE_ASSET_H_)
	company->sm_seg[seg_num]->re_mp_map_active.clear();
	company->sm_seg[seg_num]->re_mp_map_inactive.clear();
	#endif
	#if defined(__EQT_ASSET_H_)
	company->sm_seg[seg_num]->eqt_mp_map_active.clear();
	company->sm_seg[seg_num]->eqt_mp_map_inactive.clear();
	#endif
	#if defined(__EIO_ASSET_H_)
	company->sm_seg[seg_num]->eio_mp_map_active.clear();
	company->sm_seg[seg_num]->eio_mp_map_inactive.clear();
	#endif
	#if defined(__EPA_ASSET_H_)
	company->sm_seg[seg_num]->epa_mp_map_active.clear();
	company->sm_seg[seg_num]->epa_mp_map_inactive.clear();
	#endif
	}

#if defined(__BOND_ASSET_H_)
for (mp = num_bonds_init; mp < sm_bond.size(); mp++)
	{
	BOND_ASSET *current_bond_element;
	current_bond_element = sm_bond[mp];
	seg_num = current_bond_element->seg_num;
	company->sm_seg[seg_num]->bond_mp_map_inactive[mp] = mp;

	current_bond_element->purch_asset_id = "NONE";

	if(!current_bond_element->bond_pv->isShrunk)
		current_bond_element->bond_pv->shrink();
	if(!current_bond_element->bond_is->isShrunk)
		current_bond_element->bond_is->shrink();
	if(!current_bond_element->bond_ym->isShrunk)
		current_bond_element->bond_ym->shrink();
	}
#endif
#if defined(__MTG_ASSET_H_)
for (mp = num_mtgs_init; mp < sm_mtg.size(); mp++)
	{
	MTG_ASSET *current_mortgage_element;
	current_mortgage_element = sm_mtg[mp];
	seg_num = current_mortgage_element->seg_num;
	company->sm_seg[seg_num]->mtg_mp_map_inactive[mp] = mp;

	current_mortgage_element->purch_asset_id = "NONE";

	if(!current_mortgage_element->mtg_pv->isShrunk)
		current_mortgage_element->mtg_pv->shrink();
	if(!current_mortgage_element->mtg_is->isShrunk)
		current_mortgage_element->mtg_is->shrink();
	if(!current_mortgage_element->mtg_ym->isShrunk)
		current_mortgage_element->mtg_ym->shrink();
	}
#endif
#if defined(__SEC_ASSET_H_)
for (mp = num_secs_init; mp < sm_sec.size(); mp++)
	{
	SEC_ASSET *current_sec_element;
	current_sec_element = sm_sec[mp];
	seg_num = current_sec_element->seg_num;
	company->sm_seg[seg_num]->sec_mp_map_inactive[mp] = mp;

	current_sec_element->purch_asset_id = "NONE";
	current_sec_element->cp_mp_num = -1;

	if(!current_sec_element->sec_pv->isShrunk)
		current_sec_element->sec_pv->shrink();
	}
#endif
#if defined(__IRD_ASSET_H_)
for (mp = num_irds_init; mp < sm_ird.size(); mp++)
	{
	IRD_ASSET *current_ird_element;
	current_ird_element = sm_ird[mp];
	seg_num = current_ird_element->seg_num;
	company->sm_seg[seg_num]->ird_mp_map_inactive[mp] = mp;

	current_ird_element->purch_asset_id = "NONE";
	}
#endif
#if defined(__RE_ASSET_H_)
for (mp = num_res_init; mp < sm_re.size(); mp++)
	{
	RE_ASSET *current_re_element;
	current_re_element = sm_re[mp];
	seg_num = current_re_element->seg_num;
	company->sm_seg[seg_num]->re_mp_map_inactive[mp] = mp;

	current_re_element->purch_asset_id = "NONE";
	}
#endif
#if defined(__EQT_ASSET_H_)
for (mp = num_eqts_init; mp < sm_eqt.size(); mp++)
	{
	EQT_ASSET *current_eqt_element;
	current_eqt_element = sm_eqt[mp];
	seg_num = current_eqt_element->seg_num;
	company->sm_seg[seg_num]->eqt_mp_map_inactive[mp] = mp;

	current_eqt_element->purch_asset_id = "NONE";
	}
#endif
#if defined(__EIO_ASSET_H_)
for (mp = num_eios_init; mp < sm_eio.size(); mp++)
	{
	EIO_ASSET *current_eio_element;
	current_eio_element = sm_eio[mp];
	seg_num = current_eio_element->seg_num;
	company->sm_seg[seg_num]->eio_mp_map_inactive[mp] = mp;

	current_eio_element->purch_asset_id = "NONE";
	}
#endif
#if defined(__EPA_ASSET_H_)
for (mp = num_epas_init; mp < sm_epa.size(); mp++)
	{
	EPA_ASSET *current_epa_element;
	current_epa_element = sm_epa[mp];
	seg_num = current_epa_element->seg_num;
	company->sm_seg[seg_num]->epa_mp_map_inactive[mp] = mp;
	}
#endif

return;
}



#line 1 "asset_sub_port_assign.ASSET_ASSET.for"                                                                                   
int ASSET_ASSET::asset_sub_port_assign(int t, int new_asset, xstring asset_type, StrEnum::EnumValue port_defn, xstring category_id, int existing_asset_flag, double dur_for_transfer, int sub_port_id_prev)
{
if (new_asset // Existing asset at projection date or new purchase
	|| (mths_to_next_mkt_val_calc(t) == 0
		|| asset_sub_port_assign_dur_defn == YEARS_TO_MATURITY))
	{
	for (int row = 0; row < asset_sub_ports.size(); row++)
		{
		// Set lookup key
		asset_sub_port_id = asset_sub_ports[row];

		// split the comma separated list of asset categories
		vector <string> sub_port_assign_cats;
		split_string_usl(asset_sub_port_categories.c_str(), sub_port_assign_cats, ",");//WTW - Gen2 - split_tring internal RAFM function
	
		if (asset_sub_port_asset_type == asset_type
			&& asset_sub_port_port_defn == port_defn
			&& (asset_sub_port_categories == "ALL"
				|| find(sub_port_assign_cats.begin(), sub_port_assign_cats.end(), category_id) != sub_port_assign_cats.end())
			&& (asset_sub_port_existing_or_purch_defn == "Both"
				|| (asset_sub_port_existing_or_purch_defn == "Existing"
					&& existing_asset_flag)
				|| (asset_sub_port_existing_or_purch_defn == "Purchased"
					&& !existing_asset_flag)))	
			{
			// These asset types do not have a duration value
			if (asset_type == "Real Estate"
				|| asset_type == "Equity"
				|| asset_type == "Index Option")
				return row;				
				
			if ((asset_sub_port_dur_min <= dur_for_transfer
				&& dur_for_transfer < asset_sub_port_dur_max)
				//20220613 STW: add a condition for model efficiency improvement
				|| fast_stat_calc_aig == YES)
				return row;  				
			}
		}

	if (sub_port_id_prev < 0)
		{
		log_screen << "Asset cannot be assigned to a sub portfolio. Please check asset sub portfolio assignment definitions." << MSG_ERROR;
		log_screen << "Assignment criteria:" << MSG_ERROR;		
		log_screen << " New asset: " << new_asset << MSG_ERROR;
		log_screen << " Asset type: " << asset_type << MSG_ERROR;
		log_screen << " Portfolio Definition: " << port_defn << MSG_ERROR;
		log_screen << " Category: " << category_id << MSG_ERROR;
		log_screen << " Existing asset flag: " << existing_asset_flag << MSG_ERROR;
		log_screen << " Duration: " << dur_for_transfer << MSG_ERROR;
		log_screen << " Previous asset sub portfolio: " << sub_port_id_prev << MSG_ERROR;
		throw FatalError("");	
		}

	if (new_asset)
		{
		makeRunLogYellow();
		log_screen << "Warning: New purchase asset does not match any asset sub portfolio criteria. Please correct your input." 
			       << MSG_ERROR;
		}
	}

return sub_port_id_prev;
}



#line 1 "get_mp_grp.ASSET_ASSET.for"                                                                                   
xstring ASSET_ASSET::get_mp_grp(const xstring &tag)
{
// must strip "ProjTaskLoop ### " from group because the system automatically prepends this to user's group tag
xstring xxx = tag.strip();
int pos = 0;

if (xxx(0, 13) == "ProjTaskLoop ")
	{
	xxx = xxx(13);
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



#line 1 "set_asset_sub_port_map.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::set_asset_sub_port_map()
{
int asset_sub_port_num = -1;

static bool initialize_asset_sub_port_map = true; // only initialize once

if (!initialize_asset_sub_port_map)
	return;

initialize_asset_sub_port_map = false;

for (int sub_port = 0; sub_port < asset_sub_ports.size(); sub_port++)
	{
	// Asset sub portfolios are specified in the array extracted from asset_sub_ports_selected input variable
	
	 asset_sub_port_id = asset_sub_ports[sub_port];

	// Set up map of asset sub portfolio names and asset sub portfolio nums
	if ((asset_sub_port_map_iter = asset_sub_port_map.find(asset_sub_port_id)) == asset_sub_port_map.end())
		{
		asset_sub_port_num = asset_sub_port_num + 1;

		// Create asset_sub_port_map entry
		asset_sub_port_map[asset_sub_port_id] = asset_sub_port_num;
		}
	else
		throw FatalError ("Duplicate asset sub portfolio name, " + asset_sub_port_id
		                  + ". Please correct asset_sub_ports_selected input variable.");
	}

return;
}



#line 1 "set_mp_grp.ASSET_ASSET.for"                                                                                   
xstring ASSET_ASSET::set_mp_grp(int t, int model_point_num, const xstring &seg_id, const xstring &mp_grp_tag, const xstring &asset_id, int sequence_id, StrEnum::EnumValue purchase_timing)
{
if (asset_detail_rpt_cusip_id == "ALL"
	|| inlist(asset_id, asset_detail_rpt_cusip_id))
	{
	ostringstream message;
	message.setf(ios::fixed);

	message << seg_id
            << " "
	        << mp_grp_tag
			<< " #" << sequence_id
			<< " " << setw(11) << asset_id;
	if (purchase_timing == END_OF_MONTH)
		message << setw(3) << t << " " << "eom";

	return message.str();
	}

return mp_grp_tag;
}



#line 1 "setup_psa_base_rate.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::setup_psa_base_rate()
{
psa_base_rate.resize(31);

psa_base_rate[0] = 0.0;

for (int month = 1; month <= 30; month++)
	psa_base_rate[month]
	= psa_base_rate[month - 1] + .002;

return;
}



#line 1 "valid_t_low_t_high.ASSET_ASSET.for"                                                                                   
bool ASSET_ASSET::valid_t_low_t_high(int calculated_t_low, int calculated_t_high)
{
if (is_first_proj_task_loop)
	{
	if (calculated_t_low < model_t_low
		|| calculated_t_high > model_t_high)
		{
		minimum_t_low_value = min(minimum_t_low_value, calculated_t_low);
		maximum_t_high_value = max(maximum_t_high_value, calculated_t_high);

		return false;
		}

	if (minimum_t_low_value < model_t_low
		|| maximum_t_high_value > model_t_high)
		return false;
	}

return true;
}



#line 1 "write_proxy_bond.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::write_proxy_bond(void)
{
// check bond file size
int bond_size = 0;
int mtg_size = 0;

#if defined(__BOND_ASSET_H_)
bond_size = sm_bond.size();

#if defined(__MTG_ASSET_H_)
mtg_size = sm_mtg.size();
#endif

if (bond_size + mtg_size <= 0)
	{
	makeRunLogYellow();
	log_screen << "Warning: The proxy bond creation process has been requested. "
	           << "However, there are no bond or mortgage assets included in the projection. " 
	           << "No proxy bonds will be created." << MSG_ERROR;
	return;
	}

xstring data_file_name;
if (bond_size > 0)
	data_file_name = sm_bond[0]->dataFileName();
else if (mtg_size > 0)
	data_file_name = sm_mtg[0]->dataFileName();

xstring mp_file_search_string;
xstring mp_file_replace_string;
xstring mp_file_replace_string_first_pass;
xstring sch_file_search_string;
xstring sch_file_replace_string;
xstring sch_file_replace_string_first_pass;
if (time_step_flag)
	{
	mp_file_search_string = "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";
	mp_file_replace_string = "_proxy_bond_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";
	mp_file_replace_string_first_pass = "_proxy_bond_1_1.csv";
	sch_file_search_string = "_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";
	sch_file_replace_string = "_proxy_bond_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";
	sch_file_replace_string_first_pass = "_proxy_bond_sch_1_1.csv";
	}
else
	{
	mp_file_search_string = ".csv";	
	mp_file_replace_string = "_proxy_bond.csv";
	mp_file_replace_string_first_pass = "_proxy_bond.csv";
	sch_file_search_string = "_sch.csv";	
	sch_file_replace_string = "_proxy_bond_sch.csv";
	sch_file_replace_string_first_pass = "_proxy_bond_sch.csv";
	}

xstring proxy_bond_mp_file
= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
  + mp_file_replace_string;

xstring proxy_bond_sch_file
= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
  + sch_file_replace_string;

// remove any old file that is hanging around
if (first_time)
	{
	first_time = false;
	struct stat buffer;
	int stat_val;
	stat_val = stat(proxy_bond_mp_file.c_str(), &buffer);

	// if file exists, delete, as we want to create fresh
	if (stat_val == 0)
		{
		xstring mp_file_name;
		xstring sch_file_name;
		
		if (time_step_flag)
			{
			mp_file_name
			= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
			  + "_proxy_bond_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);

			sch_file_name
			= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
			  + "_proxy_bond_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num);
			}
		else
			{
			mp_file_name
			= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
			  + "_proxy_bond";

			sch_file_name
			= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
			  + "_proxy_bond_sch";
			}

		remove(mp_file_name + ".csv");
		remove(sch_file_name + ".csv");
		}
	}
	
// Determine if we are at the beginning of new outer loop. 
if (time_step_flag && valn_flag && proj_set_loop_num > 1)
	{
	xstring initial_proxy_bond_mp_file
	= xstring(data_file_name(0, data_file_name.find(mp_file_search_string)))
	  + mp_file_replace_string_first_pass;

	xstring initial_proxy_bond_sch_file
	= xstring(data_file_name(0, data_file_name.find(sch_file_search_string)))
	  + sch_file_replace_string_first_pass;

	return; 
	}
	
// Create proxy bond mp file
if (!proxy_bond_output.is_open())
	{
   	proxy_bond_output.setf(ios::fixed);
	proxy_bond_output.precision(12);
	proxy_bond_output.open(proxy_bond_mp_file);

	// Write header
	proxy_bond_output						
	<< "product" << ","						
	<< "group" << ","						
    << "seg_id_mp" << ","					
	<< "asset_id_mp" << ","					
	<< "use_mp" << ","						
	<< "category_id_mp" << ","				
	<< "port_defn_mp" << ","				
	<< "sale_class_mp" << ","				
	<< "issue_date_mp" << ","				
	<< "maturity_date_mp" << ","			
	<< "planned_sale_date_mp" << ","		
	<< "init_par_val_mp" << ","				
	<< "init_cost_basis_mp" << ","			
	<< "init_bk_val_mp" << ","				
	<< "init_mkt_val_mp" << ","				
	<< "pmt_mode_mp" << ","					
	<< "init_pmt_rate_mp" << ","			
	<< "par_val_at_issue_mp" << ","
	<< "taxable_pct_mp" << ","				
	<< "call_opt_first_date_mp" << ","		
	<< "call_price_defn_mp" << ","			
	<< "call_defn_mp" << ","				
	<< "yld_maint_addn_mp" << ","			
	<< "put_opt_first_date_mp" << ","		
	<< "put_defn_mp" << ","					
	<< "sinking_fund_defn_mp" << ","
	<< "adj_reset_category_id_mp" << ","		
	<< "adj_reset_scen_yr_mp" << ","		
	<< "adj_reset_scen_mult_mp" << ","		
	<< "adj_reset_renewal_addn_mp" << ","	
	<< "adj_next_reset_date_mp" << ","		
	<< "adj_reset_mths_mp" << ","			
	<< "adj_max_incr_per_reset_mp" << ","	
	<< "adj_max_decr_per_reset_mp" << ","	
	<< "adj_min_rate_mp" << ","				
	<< "adj_max_rate_mp" << ","				
	<< "avr_contribn_pct_mp" << ","			
	<< "avr_max_pct_mp" << ","				
	<< "avr_obj_pct_mp" << ","				
	<< "rbc_c1_pct_mp" << endl;				
	}

// Define and initialize local variables to be written
xstring group = ""; // Update below
xstring seg_id = ""; // Update below
xstring asset_id = ""; // Update below
xstring use_mp = "Yes";
xstring category_id = ""; // Update below
xstring port_defn = "Investment";
xstring sale_class = ""; // Update below
xstring issue_date = "9999/01/01"; // Update below
xstring maturity_date = "9999/01/01"; // Update below
xstring planned_sale_date = "9999/01/01"; // Update below
double notional_amt = 0.0; // Update below
double cost_basis = 0.0; // Update below
double bk_val = 0.0; // Update below
double mkt_val = 0.0;
xstring pmt_mode = "Monthly";
double pmt_rate = 0.0; // Update below
double par_val_at_issue = 0.0; // Update below
double taxable_pct = 0.0; // Update below
xstring call_opt_first_date = "9999/01/01"; // Update below
xstring call_price_defn = "Price Schedule";
xstring call_defn = ""; // Update below
double yld_maint_addn = 0.0;
xstring put_opt_first_date = "9999/01/01";
xstring put_defn = "Not Applicable";
xstring sinking_fund_defn = "Yes";
xstring adj_reset_category_id = "Govt";
double adj_reset_scen_yr = 0.25;
double adj_reset_scen_mult = 0.0;
double adj_reset_renewal_addn = 0.0;
xstring adj_next_reset_date = "9999/01/01";
int adj_reset_mths = 12;
double adj_max_incr_per_reset = 1.0;
double adj_max_decr_per_reset = 1.0;
double adj_min_rate = 0.0;
double adj_max_rate = 1.0;
double avr_contribn_pct = 0.0;
double avr_max_pct = 0.0;
double avr_obj_pct = 0.0;
double rbc_c1_pct = 0.0;

static int counter_asset = 1;

xstring asset_id_non = ""; 
xstring asset_id_call = "";

// issue date and maturity date
xstring earliest_issue_date_non = "9999/12/31";
xstring earliest_issue_date_call = "9999/12/31";
xstring latest_maturity_date_non = "1900/01/01";
xstring latest_maturity_date_call = "1900/01/01";

// book value, par value, cost basis
double local_bk_val_non = 0.0;
double local_bk_val_call = 0.0;
double total_bk_val_non = 0.0;
double total_bk_val_call = 0.0;
double local_cost_basis_non = 0.0;
double local_cost_basis_call = 0.0;
double total_cost_basis_non = 0.0;
double total_cost_basis_call = 0.0;
double local_par_val_non = 0.0;
double local_par_val_call = 0.0;
double local_par_val_at_issue_non = 0.0;
double local_par_val_at_issue_call = 0.0;
double local_taxable_pct_non_nom = 0.0;
double local_taxable_pct_call_nom = 0.0;
double total_par_val_non = 0.0;
double total_par_val_call = 0.0;
double total_par_val_at_issue_non = 0.0;
double total_par_val_at_issue_call = 0.0;
double total_taxable_pct_non_nom = 0.0;
double total_taxable_pct_call_nom = 0.0;

// coupon rate 
double local_total_pmt_non = 0.0;
double local_total_pmt_call = 0.0;
double local_WAL_non = 0.0;
double local_WAL_call = 0.0;
double local_coup_rate_non = 0.0;
double local_coup_rate_call = 0.0;
double total_pmt_non = 0.0;
double total_pmt_call = 0.0;
double total_coup_num_non = 0.0;
double total_coup_num_call = 0.0;
double total_coup_denom_non = 0.0;
double total_coup_denom_call = 0.0;

// sinking fund
double local_int_rate = 0.0;
double local_int_pmt = 0.0;
double angle_n = 0.0;
static SmartArray <double> local_par_val_array_non;
static SmartArray <double> local_par_val_array_call;
static SmartArray <double> local_par_val_call_base;
static SmartArray <double> local_pmt_amt_non;
static SmartArray <double> local_pmt_amt_call;
double local_balloon_amt_non = 0.0;
double local_balloon_amt_call = 0.0;
double local_sched_prin_pmt = 0.0;
double local_sink_amt_non = 0.0;
double local_sink_amt_call = 0.0;
double total_sink_amt_non = 0.0;
double total_sink_amt_call = 0.0;
static SmartArray <double> sink_fund_value_non;
static SmartArray <double> sink_fund_value_call;
static SmartArray <double> sink_fund_sch_base_non;
static SmartArray <double> sink_fund_sch_base_call;
static SmartArray <double> local_sink_fund_base_non;
static SmartArray <double> local_sink_fund_base_call;
xstring earliest_sink_fund_date_non = "9999/01/01";
xstring earliest_sink_fund_date_call = "9999/01/01";

// call schedule
double local_call_sch_amt = 0.0;
double total_call_sch_amt = 0.0;
static SmartArray <double> call_sch_value;
xstring earliest_call_sch_date = "9999/01/01";
xstring latest_call_sch_par_date = "1000/01/01";
int earliest_call_first_period = 9999;
int call_year;
static SmartArray <double> call_first_date;
static SmartArray <double> total_par_val_call_base;

for (int seg_num = 0; seg_num < company->sm_seg.size(); seg_num++)
	{
	SEG_COMP *seg_element = company->sm_seg[seg_num];
	int a_sub_port_size = sm_asset_sub_port[seg_num].size();
	seg_id = seg_element->seg_id;
	int bond_mp_size = seg_element->bond_mp_map_active_init.size();
	int mtg_mp_size = seg_element->mtg_mp_map_active_init.size();

	for (int sub_port_num = 0; sub_port_num < a_sub_port_size; sub_port_num++)
		{
		// non_callable bond for segment 1, asset group 2 will be Proxy1S1G2
		// callable bond for segment 2, asset group 3 will be Proxy2S2G3
		asset_id_non = "Proxy1S" + xstring(seg_num) + "G" + xstring(sub_port_num);
		asset_id_call = "Proxy2S" + xstring(seg_num) + "G" + xstring(sub_port_num);

		asset_sub_port_id = asset_sub_ports[sub_port_num];
		category_id = asset_sub_port_proxy_bond_category;
		sale_class = asset_sub_port_proxy_bond_sale_class;
	
		if (asset_sub_port_asset_type != "Bond" && asset_sub_port_asset_type != "Mortgage")
			continue;
		else 
			{
			mpmap::iterator mp_map_iter;
			if (asset_sub_port_asset_type == "Bond" && bond_mp_size > 0)
				{
				if (sink_fund_sch_base_non.size() < bond_mp_size)
					sink_fund_sch_base_non.resize(bond_mp_size);
				if (local_sink_fund_base_non.size() < bond_mp_size)
					local_sink_fund_base_non.resize(bond_mp_size);

				if (proxy_bond_defn == CALLABLE_SEPARATE) 
					{
					if (sink_fund_sch_base_call.size() < bond_mp_size)
						sink_fund_sch_base_call.resize(bond_mp_size);
					if (local_sink_fund_base_call.size() < bond_mp_size)
						local_sink_fund_base_call.resize(bond_mp_size);
					if (call_first_date.size() < bond_mp_size)
						call_first_date.resize(bond_mp_size);
					}

				for (mp_map_iter = seg_element->bond_mp_map_active_init.begin();
					 mp_map_iter != seg_element->bond_mp_map_active_init.end();
					 mp_map_iter++)
					{
					int mp = mp_map_iter->first;
					BOND_ASSET *bond_element = sm_bond[mp];

					if (bond_element->sub_port_id(last_proj_period) != sub_port_num)
						continue;	

					bool non_callable = true;
					if (proxy_bond_defn == CALLABLE_SEPARATE) 
						{
						call_year = get_yr_from_date(bond_element->call_opt_first_date);
						if (call_year < 9999)
							non_callable = false;
						}

					if (non_callable)
						{
						// issue_date and maturity date
						if (date_diff(bond_element->issue_date, earliest_issue_date_non) < 0)
							earliest_issue_date_non = bond_element->issue_date;

						if (date_diff(bond_element->maturity_date, latest_maturity_date_non) > 0)
							latest_maturity_date_non = bond_element->maturity_date;

						// book value
						local_bk_val_non = bond_element->bk_val(last_proj_period);
						local_bk_val_non *= bond_element->pct_to_use;
						total_bk_val_non += local_bk_val_non;
						
						// cost basis
						local_cost_basis_non = bond_element->cost_basis(last_proj_period);
						local_cost_basis_non *= bond_element->pct_to_use;
						total_cost_basis_non += local_cost_basis_non;
						
						// par value and par value at issue
						local_par_val_non = bond_element->notional_amt(last_proj_period);
						local_par_val_non *= bond_element->pct_to_use;
						
						if (bond_element->init_par_val > rate_ratio_threshold) 
							total_par_val_at_issue_non += bond_element->init_par_val;
						else 
							total_par_val_at_issue_non += local_par_val_non;

						total_par_val_non += local_par_val_non;

						// taxable pct
						local_taxable_pct_non_nom = bond_element->taxable_pct * bond_element->cost_basis(last_proj_period) ;
						local_taxable_pct_non_nom *= bond_element->pct_to_use;
						total_taxable_pct_non_nom += local_taxable_pct_non_nom;
						
						//pmt rate
						local_coup_rate_non = bond_element->sm_bond_cf->pmt_rate(last_proj_period);
						local_WAL_non = bond_element->weighted_avg_life(last_proj_period);
						local_total_pmt_non = local_coup_rate_non * local_par_val_non * local_WAL_non;
						total_coup_num_non += local_total_pmt_non;
						total_coup_denom_non += local_par_val_non * local_WAL_non;
						
						// sinking fund
						if (bond_element->sinking_fund_defn == YES)
							sink_fund_sch_base_non[mp] = bond_element->sinking_fund_sch_base(last_proj_period);
						else
							sink_fund_sch_base_non[mp] = 1.0;

						if (sink_fund_sch_base_non[mp] > rate_ratio_threshold)
							local_sink_fund_base_non[mp] = bond_element->notional_amt(last_proj_period) / sink_fund_sch_base_non[mp];
						}
					else // callable
						{
						//issue_date and maturity date
						if (date_diff(bond_element->issue_date, earliest_issue_date_call) < 0)
							earliest_issue_date_call = bond_element->issue_date;

						if (date_diff(bond_element->maturity_date, latest_maturity_date_call) > 0)
							latest_maturity_date_call = bond_element->maturity_date;

						// book value
						local_bk_val_call = bond_element->bk_val(last_proj_period);
						local_bk_val_call *= bond_element->pct_to_use;
						total_bk_val_call += local_bk_val_call;
						
						// cost basis
						local_cost_basis_call = bond_element->cost_basis(last_proj_period);
						local_cost_basis_call *= bond_element->pct_to_use;
						total_cost_basis_call += local_cost_basis_call;
						
						// par value and par value at issue
						local_par_val_call = bond_element->notional_amt(last_proj_period);
						local_par_val_call *= bond_element->pct_to_use;
						
						if (bond_element->init_par_val > rate_ratio_threshold) 
							total_par_val_at_issue_call += bond_element->init_par_val;
						else 
							total_par_val_at_issue_call += local_par_val_call;

						total_par_val_call += local_par_val_call;
						
						// taxable pct
						local_taxable_pct_call_nom = bond_element->taxable_pct * bond_element->cost_basis(last_proj_period);
						local_taxable_pct_call_nom *= bond_element->pct_to_use;
						total_taxable_pct_call_nom += local_taxable_pct_call_nom;

						// pmt rate
						local_coup_rate_call = bond_element->sm_bond_cf->pmt_rate(last_proj_period);
						local_WAL_call = bond_element->weighted_avg_life(last_proj_period);
						local_total_pmt_call = local_coup_rate_call * local_par_val_call * local_WAL_call;
						total_coup_num_call += local_total_pmt_call;
						total_coup_denom_call += local_par_val_call * local_WAL_call;
						
						// sinking fund
						if (bond_element->sinking_fund_defn == YES)
							sink_fund_sch_base_call[mp] = bond_element->sinking_fund_sch_base(last_proj_period);
						else
							sink_fund_sch_base_call[mp] = 1.0;

						if (sink_fund_sch_base_call[mp] > rate_ratio_threshold)
							local_sink_fund_base_call[mp] = bond_element->notional_amt(last_proj_period) / sink_fund_sch_base_call[mp];

						// call schedule dates
						if (date_diff(bond_element->call_opt_first_date, earliest_call_sch_date) < 0)
							earliest_call_sch_date = bond_element->call_opt_first_date;
						
						if (bond_element->call_first_period < earliest_call_first_period)
							earliest_call_first_period = bond_element->call_first_period;
						} // if (non_callable)
					} // for (mp_map_iter

				// set the sinking fund payment for the non callable proxy bond
				if (total_bk_val_non > rate_ratio_threshold)
					{		
					local_coup_rate_non = total_coup_num_non / total_coup_denom_non;	
					int maturity_months = date_diff(latest_maturity_date_non, proj_date_adj);
					
					if (sink_fund_value_non.size() < maturity_months - last_proj_period + 1)
						sink_fund_value_non.resize(maturity_months - last_proj_period + 1);	
					
					// set sinking fund schedule
					for (int month = last_proj_period; month <= maturity_months; month++) // new schedule only start from new proj date
						{
						for (mp_map_iter = seg_element->bond_mp_map_active_init.begin();
							 mp_map_iter != seg_element->bond_mp_map_active_init.end();
							 mp_map_iter++)
							{
							int mp = mp_map_iter->first;
							BOND_ASSET *bond_element = sm_bond[mp];
							
							if (bond_element->sub_port_id(last_proj_period) != sub_port_num)
								continue;
							
							int sch_start_period = bond_element->start_period;
							
							bool non_callable = true;
							if (proxy_bond_defn == CALLABLE_SEPARATE) 
								{
								call_year = get_yr_from_date(bond_element->call_opt_first_date);
								if (call_year < 9999)
									non_callable = false;
								}

							if (!non_callable)
								continue;

							if (bond_element->sinking_fund_defn == YES
								&& month < bond_element->sinking_fund_sch.size())
								{
								local_sink_amt_non = bond_element->sinking_fund_sch[month - sch_start_period] * local_sink_fund_base_non[mp];
								sink_fund_sch_base_non[mp] -= bond_element->sinking_fund_sch[month - sch_start_period];									
								}
							else if (month == bond_element->maturity_period)
								local_sink_amt_non = sink_fund_sch_base_non[mp] * local_sink_fund_base_non[mp];
							else 
								local_sink_amt_non = 0.0;
								
							total_sink_amt_non += local_sink_amt_non;														
							} // for (mp_map_iter

						if (total_par_val_non > rate_ratio_threshold)
							sink_fund_value_non[month - last_proj_period] = total_sink_amt_non / total_par_val_non;
						
						local_sink_amt_non = 0.0;
						total_sink_amt_non = 0.0;
	 					} // for month

					if (call_sch_value.size() > 0) // No call shcedule for non_callable bond
						call_sch_value.resize(0);

					write_proxy_bond_sch(asset_id_non, proxy_bond_sch_file, call_sch_value, sink_fund_value_non);
					} // if (total_bk_val_non > rate_ratio_threshold)

				// set the sinking fund payment and call schedule for the callable proxy bond
				if (total_bk_val_call > rate_ratio_threshold)
					{
					local_coup_rate_call = total_coup_num_call / total_coup_denom_call;
				
					// sinking fund amount for callable
					int maturity_months = date_diff(latest_maturity_date_call, proj_date_adj);

					if (call_sch_value.size() < maturity_months - last_proj_period + 1)
					    call_sch_value.resize(maturity_months - last_proj_period + 1);

					if (sink_fund_value_call.size() < maturity_months - last_proj_period + 1)
						sink_fund_value_call.resize(maturity_months - last_proj_period + 1);
					
					for (int month = last_proj_period; month <= maturity_months; month++)
						{
						for (mp_map_iter = seg_element->bond_mp_map_active_init.begin();
							mp_map_iter != seg_element->bond_mp_map_active_init.end();
						 	mp_map_iter++)
							{
							int mp = mp_map_iter->first;
							BOND_ASSET *bond_element = sm_bond[mp];
							
							if (bond_element->sub_port_id(last_proj_period) != sub_port_num)
								continue;
							
							call_year = get_yr_from_date(bond_element->call_opt_first_date);														
							if (call_year == 9999)
								continue;
							
							int sch_start_period = bond_element->start_period;

							// call
							if (month < bond_element->call_price_sch.size()
								&& month >= earliest_call_first_period)
								{
								int period = max(month, bond_element->call_first_period);
								local_call_sch_amt = bond_element->call_price_sch[period - sch_start_period] * local_par_val_call;	
								}
							else
								local_call_sch_amt = 0.0;								 

							total_call_sch_amt += local_call_sch_amt;

							// sinking fund
							if (bond_element->sinking_fund_defn == YES
								&& month < bond_element->sinking_fund_sch.size())
								{
								local_sink_amt_call = bond_element->sinking_fund_sch[month] * local_sink_fund_base_call[mp];
								sink_fund_sch_base_call[mp] -= bond_element->sinking_fund_sch[month - sch_start_period];
								}
							else if (month == bond_element->maturity_period)
								local_sink_amt_non = sink_fund_sch_base_call[mp] * local_sink_fund_base_call[mp];
							else 
								local_sink_amt_non = 0.0;
								
							total_sink_amt_call += local_sink_amt_call;
							} // for (mp_map_iter

							if (total_par_val_call > rate_ratio_threshold)
								{
								call_sch_value[month - last_proj_period] = total_call_sch_amt / total_par_val_call;
								sink_fund_value_call[month - last_proj_period] = total_sink_amt_call / total_par_val_call;
								}
							
							total_call_sch_amt = 0.0;
							total_sink_amt_call = 0.0;
							local_sink_amt_call = 0.0;
					 	} // for (int month

					write_proxy_bond_sch(asset_id_call, proxy_bond_sch_file, call_sch_value, sink_fund_value_call);
					} // if (total_bk_val_call > rate_ratio_threshold)
				} // if (asset_sub_port_asset_type == "Bond")

			#if defined(__MTG_ASSET_H_)
			if (asset_sub_port_asset_type == "Mortgage" && mtg_mp_size > 0)
				{
				if (local_par_val_array_non.size() < mtg_mp_size)
					local_par_val_array_non.resize(mtg_mp_size);
				if (local_pmt_amt_non.size() < mtg_mp_size)
					local_pmt_amt_non.resize(mtg_mp_size);
				if (local_par_val_call_base.size() < mtg_mp_size)
					local_par_val_call_base.resize(mtg_mp_size);				

				if (proxy_bond_defn == CALLABLE_SEPARATE) 
					{
					if (local_par_val_array_call.size() < mtg_mp_size)
						local_par_val_array_call.resize(mtg_mp_size);
					if (local_pmt_amt_call.size() < mtg_mp_size)
						local_pmt_amt_call.resize(mtg_mp_size);
					}

				for (mp_map_iter = seg_element->mtg_mp_map_active_init.begin();
					 mp_map_iter != seg_element->mtg_mp_map_active_init.end();
					 mp_map_iter++)
					{	
					int mp = mp_map_iter->first;
					MTG_ASSET *mtg_element = sm_mtg[mp];
					
					if (mtg_element->sub_port_id(last_proj_period) != sub_port_num)
						continue;

					bool non_callable = true;
					if (proxy_bond_defn == CALLABLE_SEPARATE
						&& mtg_element->prepmt_first_period < mtg_element->maturity_period)
						non_callable = false;

					if (non_callable)
						{
						// issue_date and maturity date
						if (date_diff(mtg_element->issue_date, earliest_issue_date_non) < 0)
							earliest_issue_date_non = mtg_element->issue_date;

						if (date_diff(mtg_element->maturity_date, latest_maturity_date_non) > 0)
							latest_maturity_date_non = mtg_element->maturity_date;
							
						// book value
						local_bk_val_non = mtg_element->bk_val(last_proj_period);
						local_bk_val_non *= mtg_element->pct_to_use;
						total_bk_val_non += local_bk_val_non;
						
						// cost basis
						local_cost_basis_non = mtg_element->cost_basis(last_proj_period);
						local_cost_basis_non *= mtg_element->pct_to_use;
						total_cost_basis_non += local_cost_basis_non;
						
						// par value and par value at issue
						local_par_val_non = mtg_element->notional_amt(last_proj_period);
						local_par_val_non *= mtg_element->pct_to_use;

						if (mtg_element->init_par_val > rate_ratio_threshold) 
							total_par_val_at_issue_non += mtg_element->init_par_val;
						else 
							total_par_val_at_issue_non += local_par_val_non;

						total_par_val_non += local_par_val_non;
						
						// taxable pct will be 1 for mortgage records												
						total_taxable_pct_non_nom = total_cost_basis_non;

						// pmt rate
						local_coup_rate_non = mtg_element->sm_mtg_cf->pmt_rate(last_proj_period) + mtg_element->servicing_fee;
						local_WAL_non = mtg_element->weighted_avg_life(last_proj_period);
						local_total_pmt_non = local_coup_rate_non * local_par_val_non * local_WAL_non;
						total_coup_num_non += local_total_pmt_non;
						total_coup_denom_non += local_par_val_non * local_WAL_non;
						
						// pmt amt array at last_proj_period
						local_int_rate = mtg_element->sm_mtg_cf->pmt_rate(last_proj_period) + mtg_element->servicing_fee;
						angle_n = (1.0 - pow(1.0 / (1.0 + local_int_rate / 12.0),
						 		   (double) (mtg_element->maturity_period - last_proj_period)))
			  						/ (local_int_rate / 12.0);
						local_pmt_amt_non[mp] = local_par_val_non / angle_n;
						local_par_val_array_non[mp] = local_par_val_non;
						}
					else // callable
						{
						// issue_date and maturity date
						if (date_diff(mtg_element->issue_date, earliest_issue_date_call) < 0)
							earliest_issue_date_call = mtg_element->issue_date;

						if (date_diff(mtg_element->maturity_date, latest_maturity_date_call) > 0)
							latest_maturity_date_call = mtg_element->maturity_date;
							
						// book value
						local_bk_val_call = mtg_element->bk_val(last_proj_period);
						local_bk_val_call *= mtg_element->pct_to_use;
						total_bk_val_call += local_bk_val_call;
						
						// cost basis
						local_cost_basis_call = mtg_element->cost_basis(last_proj_period);
						local_cost_basis_call *= mtg_element->pct_to_use;
						total_cost_basis_call += local_cost_basis_call;
						
						// par value and par value at issue
						local_par_val_call = mtg_element->notional_amt(last_proj_period);
						local_par_val_call*= mtg_element->pct_to_use;
						
						if (mtg_element->init_par_val != 0.0) 
							total_par_val_at_issue_call += mtg_element->init_par_val;
						else 
							total_par_val_at_issue_call += local_par_val_call;

						total_par_val_call += local_par_val_call;
						
						// taxable pct will be 1 for mortgage records
						total_taxable_pct_call_nom = total_cost_basis_call;

						// pmt rate
						local_coup_rate_call = mtg_element->sm_mtg_cf->pmt_rate(last_proj_period) + mtg_element->servicing_fee;
						local_WAL_call = mtg_element->weighted_avg_life(last_proj_period);
						local_total_pmt_call = local_coup_rate_call * local_par_val_call * local_WAL_call;
						total_coup_num_call += local_total_pmt_call;
						total_coup_denom_call += local_par_val_call * local_WAL_call;
						
						// pmt amt array at last_proj_period
						local_int_rate = mtg_element->sm_mtg_cf->pmt_rate(last_proj_period) + mtg_element->servicing_fee;
						angle_n = (1.0 - pow(1.0 / (1.0 + local_int_rate / 12.0),
								   (double) (mtg_element->maturity_period - last_proj_period)))
				  					/ (local_int_rate / 12.0);
						local_pmt_amt_call[mp]=  local_par_val_call / angle_n;
						local_par_val_array_call[mp] = local_par_val_call;
						local_par_val_call_base[mp] = local_par_val_call;
						} // if (non_callable)
					} // for (mp_map_iter

				// set the sinking fund payment for the non callable proxy bond
				if (total_bk_val_non > rate_ratio_threshold)
					{	
					local_coup_rate_non = total_coup_num_non / total_coup_denom_non;
						 
					// sinking fund amount
					int maturity_months = date_diff(latest_maturity_date_non, proj_date_adj);
						
					if (sink_fund_value_non.size() < maturity_months - last_proj_period + 2)
						sink_fund_value_non.resize(maturity_months - last_proj_period + 2);

					for (int month = last_proj_period; month <= maturity_months; month++) // new schedule only start from new proj date
						{   
						for (mp_map_iter = seg_element->mtg_mp_map_active_init.begin();
							mp_map_iter != seg_element->mtg_mp_map_active_init.end();
							mp_map_iter++)
							{
							int mp = mp_map_iter->first;
							MTG_ASSET *mtg_element = sm_mtg[mp];
								
							if (mtg_element->sub_port_id(last_proj_period) != sub_port_num)
								continue;

							if (proxy_bond_defn == CALLABLE_SEPARATE 
								&& mtg_element->prepmt_first_period < mtg_element->maturity_period) // callable
								continue;
								
							int sch_start_period = mtg_element->start_period;
									
							local_par_val_non = mtg_element->notional_amt(last_proj_period);
								
							// balloon amt
							if (mtg_element->balloon_pmt_flag == YES)
								{
								local_balloon_amt_non = mtg_element->sm_mtg_cf->balloon_pmt(month);
								local_par_val_array_non[mp] -= local_balloon_amt_non;
								}
							else if (month == mtg_element->maturity_period)
								local_balloon_amt_non = local_par_val_array_non[mp];
							else
								local_balloon_amt_non = 0.0;
								
							// principal amt
							if (local_par_val_array_non[mp] > rate_ratio_threshold)
								{
								local_int_rate = mtg_element->sm_mtg_cf->pmt_rate(month) + mtg_element->servicing_fee;
								local_int_pmt = local_par_val_array_non[mp] * local_int_rate / 12.0;
								local_sched_prin_pmt = local_pmt_amt_non[mp] - local_int_pmt;
								}
							else 
								local_sched_prin_pmt = 0.0;
								
							total_sink_amt_non += local_balloon_amt_non + local_sched_prin_pmt;
							local_par_val_array_non[mp] = local_par_val_array_non[mp] - local_sched_prin_pmt;
							} // for (mp_map_iter
		
						if (total_par_val_non > rate_ratio_threshold)
							sink_fund_value_non[month - last_proj_period + 1] = total_sink_amt_non / total_par_val_non;

						local_balloon_amt_non = 0.0;
						local_sched_prin_pmt = 0.0;
						total_sink_amt_non = 0.0;
			 			} // for (int month

					if (call_sch_value.size() > 0)
						call_sch_value.resize(0);

					write_proxy_bond_sch(asset_id_non, proxy_bond_sch_file, call_sch_value, sink_fund_value_non);
					} // if (total_bk_val_non > rate_ratio_threshold)

				// set the sinking fund payment and call schedule for the callable proxy bond
				if (total_bk_val_call > rate_ratio_threshold)
					{
					local_coup_rate_call = total_coup_num_call / total_coup_denom_call;
						
					// sinking fund amount
					int maturity_months = date_diff(latest_maturity_date_call, proj_date_adj);
						
					if (sink_fund_value_call.size() < maturity_months - last_proj_period + 2)
						sink_fund_value_call.resize(maturity_months - last_proj_period + 2);

					if (call_sch_value.size() < maturity_months - last_proj_period + 1)
						call_sch_value.resize(maturity_months - last_proj_period + 1);
						
					if (total_par_val_call_base.size() < maturity_months - last_proj_period + 1)
						total_par_val_call_base.resize(maturity_months - last_proj_period + 1);

					for (int month = last_proj_period; month <= maturity_months; month++) // new schedule only start from new proj date
						{   
						for (mp_map_iter = seg_element->mtg_mp_map_active_init.begin();
							mp_map_iter != seg_element->mtg_mp_map_active_init.end();
							mp_map_iter++)
							{
							int mp = mp_map_iter->first;
							MTG_ASSET *mtg_element = sm_mtg[mp];
								
							if (mtg_element->sub_port_id(last_proj_period) != sub_port_num)
								continue;
								
							if (mtg_element->prepmt_first_period >= mtg_element->maturity_period ) // non_callable
								continue;
								
							int sch_start_period = mtg_element->start_period;
								 
							// call schedule
							local_par_val_non = local_par_val_call_base[mp];
							 	
							// starting period is earlier than first entry in the table
							if (month < mtg_element->prepmt_penalty_sch.size()
								&& month >= earliest_call_first_period)
							 	{
								int period = max(month, mtg_element->prepmt_first_period);
								// convert prepmt premium factor into call schdule
								local_call_sch_amt = (1.0 + mtg_element->prepmt_penalty_sch[period - sch_start_period]) * local_par_val_call; 
								}
							else
								local_call_sch_amt = 0.0;								 
									
							local_par_val_call_base[mp] = mtg_element->notional_amt(last_proj_period);
							total_call_sch_amt += local_call_sch_amt;
							total_par_val_call_base[month - last_proj_period] += local_par_val_call;
								
							// balloon amt
							if (month == mtg_element->balloon_pmt_period)
								{
								local_balloon_amt_call = mtg_element->sm_mtg_cf->balloon_pmt(month);
								local_par_val_array_call[mp] -= local_balloon_amt_call;									
								}
							else if (month == mtg_element->maturity_period)
								local_balloon_amt_call = local_par_val_array_call[mp];
							else
								local_balloon_amt_call = 0.0;
									
							// principal amt
							if (local_par_val_array_call[mp] > rate_ratio_threshold)
								{
								local_int_rate = mtg_element->sm_mtg_cf->pmt_rate(month) + mtg_element->servicing_fee;
								local_int_pmt = local_par_val_array_call[mp] * local_int_rate / 12.0;
								local_sched_prin_pmt = local_pmt_amt_call[mp] - local_int_pmt;
								}
							else 
								local_sched_prin_pmt = 0.0;

							total_sink_amt_call += local_balloon_amt_non + local_sched_prin_pmt;
							local_par_val_array_call[mp] = local_par_val_array_call[mp] - local_sched_prin_pmt;
							} // for (mp_map_iter
	
						if (total_par_val_call > rate_ratio_threshold)
							sink_fund_value_call[month - last_proj_period + 1] = total_sink_amt_call / total_par_val_call;
							
						if (total_par_val_call_base[month - last_proj_period] > rate_ratio_threshold)
							call_sch_value[month - last_proj_period] 
							= total_call_sch_amt / total_par_val_call_base[month - last_proj_period];
						else 
							call_sch_value[month - last_proj_period] = 1.0;
								
						total_call_sch_amt = 0.0;					
						local_balloon_amt_call = 0.0;
						local_sched_prin_pmt = 0.0;
						total_sink_amt_call = 0.0;
						local_par_val_call = 0.0;
						total_par_val_call_base[month - last_proj_period] = 0.0;
						} // for (int month

					write_proxy_bond_sch(asset_id_call, proxy_bond_sch_file, call_sch_value, sink_fund_value_call);
					} // if (total_bk_val_call > rate_ratio_threshold)
				} // if (asset_sub_port_asset_type == "Mortgage" && mtg_mp_size > 0)
			#endif

			// Write model point data
			for (int mp_type = 1; mp_type <= 2; mp_type++) // 1 for non_callable; 2 for callable
				{
				bool non_callable = true;
				if (mp_type == 2)
					non_callable = false;
				
				if (non_callable && total_bk_val_non < rate_ratio_threshold)
					continue;

				if (!non_callable && total_bk_val_call < rate_ratio_threshold)
					continue;

				if (non_callable)
					{
					group = "not_callable";
					asset_id = asset_id_non;
					issue_date = earliest_issue_date_non;
					maturity_date = latest_maturity_date_non;
					notional_amt = total_par_val_non;
					cost_basis = total_cost_basis_non;
					bk_val = total_bk_val_non;
					pmt_rate = local_coup_rate_non;
					par_val_at_issue = total_par_val_at_issue_non;
					taxable_pct = total_taxable_pct_non_nom / total_cost_basis_non;
					call_defn = "Not Applicable";
					}
				else
					{
					group = "callable";
					asset_id = asset_id_call;
					issue_date = earliest_issue_date_call;
					maturity_date = latest_maturity_date_call;
					notional_amt = total_par_val_call;
					cost_basis = total_cost_basis_call;
					bk_val = total_bk_val_call;
					pmt_rate = local_coup_rate_call;
					par_val_at_issue = total_par_val_at_issue_call;
					taxable_pct = total_taxable_pct_call_nom / total_cost_basis_call;
					call_defn = "American";
					}

				proxy_bond_output
				<< "bond" << ","
				<< group << ","
				<< seg_id << ","
				<< asset_id << ","
				<< use_mp << ","
				<< category_id << ","
				<< port_defn << ","
				<< sale_class << ","
				<< issue_date << ","
				<< maturity_date << ","
				<< planned_sale_date << ","
				<< notional_amt << ","
				<< cost_basis << ","
				<< bk_val << ","
				<< mkt_val << ","
				<< pmt_mode << ","
				<< pmt_rate << ","
				<< par_val_at_issue << ","
				<< taxable_pct << ","
				<< call_opt_first_date << ","
				<< call_price_defn << ","
				<< call_defn << ","
				<< yld_maint_addn << ","
				<< put_opt_first_date << ","
				<< put_defn << ","
				<< sinking_fund_defn << ","
				<< adj_reset_category_id << ","
				<< adj_reset_scen_yr << ","
				<< adj_reset_scen_mult << ","
				<< adj_reset_renewal_addn << ","
				<< adj_next_reset_date << ","
				<< adj_reset_mths << ","
				<< adj_max_incr_per_reset << ","
				<< adj_max_decr_per_reset << ","
				<< adj_min_rate << ","
				<< adj_max_rate << ","
				<< avr_contribn_pct << ","
				<< avr_max_pct << ","
				<< avr_obj_pct << ","
				<< rbc_c1_pct << endl;
			
				counter_asset++;
				} // for (int mp_type

			total_coup_num_non = 0.0;
			total_coup_denom_non = 0.0; // clear temp variable totals		
			earliest_issue_date_non = "9999/01/01";
			latest_maturity_date_non = "1900/01/01";
			total_par_val_non = 0.0;
			total_cost_basis_non = 0.0;
			total_bk_val_non = 0.0;
			total_par_val_at_issue_non = 0.0;
			total_taxable_pct_non_nom = 0.0;
			total_coup_num_call = 0.0;
			total_coup_denom_call = 0.0; // clear temp variable totals
			earliest_issue_date_call = "9999/01/01";
			latest_maturity_date_call = "1900/01/01";
			total_par_val_call = 0;
			total_cost_basis_call = 0.0;
			total_bk_val_call = 0.0;
			total_par_val_at_issue_call = 0.0;
			total_taxable_pct_call_nom = 0.0;
			earliest_call_sch_date = "9999/01/01";
			earliest_call_first_period = 9999;
			} // if (asset_sub_port_asset_type != "Bond" && asset_sub_port_asset_type != "Mortgage")
		} // for (int sub_port_num
	} // for (int seg_num
#endif		

return;
}



#line 1 "write_proxy_bond_sch.ASSET_ASSET.for"                                                                                   
void ASSET_ASSET::write_proxy_bond_sch(xstring asset_id, xstring sch_file, SmartArray <double> call_sch, SmartArray <double> sinking_fund_sch)
{
// Open state of world file and write header
if (!proxy_bond_sch_output.is_open())
	{
	proxy_bond_sch_output.setf(ios::fixed);
	proxy_bond_sch_output.precision(12);
	proxy_bond_sch_output.open(sch_file);

	// Write header
	proxy_bond_sch_output 
	<< "asset_id" << ","					// col 0 = asset_id
	<< "date" << ","						// col 1 = date
    << "call_price_pct" << ","              // col 2 = call_price_pct
    << "put_price_pct" << ","               // col 3 = put_price_pct
	<< "sinking_fund_prin_pmt_pct" << endl; // col 4 = sinking_fund_prin_pmt_pct
	}

int array_size = max(call_sch.size(), sinking_fund_sch.size());

double curr_call_price_pct = 0.0;
double curr_put_price_pct = 0.0;
double curr_sinking_fund_prin_pmt_pct = 0.0;
double prev_call_price_pct = 0.0;
double prev_sinking_fund_prin_pmt_pct = 0.0;
bool new_data_flag = true;

for (int month = last_proj_period; month < last_proj_period + array_size; month++)
	{
	xstring curr_date = get_string_of_date(date(month));

	if (month < last_proj_period + call_sch.size())
		{
		curr_call_price_pct = call_sch[month - last_proj_period];
		if (abs(curr_call_price_pct - prev_call_price_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_call_price_pct = curr_call_price_pct;
		}

	if (month < last_proj_period + sinking_fund_sch.size())
		{
		curr_sinking_fund_prin_pmt_pct = sinking_fund_sch[month - last_proj_period];
		if (curr_sinking_fund_prin_pmt_pct > rate_ratio_threshold
			|| abs(curr_sinking_fund_prin_pmt_pct - prev_sinking_fund_prin_pmt_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_sinking_fund_prin_pmt_pct = curr_sinking_fund_prin_pmt_pct;
		}

	// Only write out if data changed except the first record
	if (new_data_flag)
		proxy_bond_sch_output
		<< asset_id << ","
		<< curr_date << ","
		<< curr_call_price_pct << ","
		<< curr_put_price_pct << ","
		<< curr_sinking_fund_prin_pmt_pct << endl;

	// By updating this flag at end instead of beginning of loop,
	// We make sure the first record always gets written
	new_data_flag = false;
	}

return;
}



void ASSET_ASSET::Terminator()
{

proxy_bond_output.close();
bond_state_of_world_mp_output.close();
mtg_state_of_world_mp_output.close();
sec_state_of_world_mp_output.close();
ird_state_of_world_mp_output.close();
re_state_of_world_mp_output.close();
eqt_state_of_world_mp_output.close();
eio_state_of_world_mp_output.close();
epa_state_of_world_mp_output.close();

}

FunctionPtr ASSET_ASSET::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static ASSET_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (ASSET_ASSET_UDF::*dPXi) (int);
typedef double (ASSET_ASSET_UDF::*dPXid) (int, double);
typedef double (ASSET_ASSET_UDF::*dPF) ();
typedef double (ASSET_ASSET_UDF::*dPFd) (double);
typedef int (ASSET_ASSET_UDF::*iPF) ();
typedef int (ASSET_ASSET_UDF::*iPFi) (int);
typedef xstring (ASSET_ASSET_UDF::*sPF) ();
typedef xstring (ASSET_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData ASSET_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "asset_detail_rpt_flag", "asset_asset_asset_detail_rpt_flag",  "asset_detail_rpt_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_asset_detail_rpt_flag, 'E','N', '3', 'C', (size_t)&modelOffset->asset_detail_rpt_flag),
	CashFlowCommonData(2, "asset_detail_rpt_inv_strat_flag", "asset_asset_asset_detail_rpt_inv_strat_flag",  "asset_detail_rpt_inv_strat_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_asset_detail_rpt_inv_strat_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_detail_rpt_inv_strat_flag),
	CashFlowCommonData(3, "cal_mth", "asset_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(4, "cal_yr", "asset_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(5, "cal_yr_relative", "asset_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(6, "date", "asset_asset_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_date, 'E','Y', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(7, "finalize", "asset_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(8, "initialize", "asset_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(9, "mths_to_asset_sale", "asset_asset_mths_to_asset_sale",  "mths_to_asset_sale",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_mths_to_asset_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_asset_sale),
	CashFlowCommonData(10, "mths_to_next_mkt_val_calc", "asset_asset_mths_to_next_mkt_val_calc",  "mths_to_next_mkt_val_calc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_mths_to_next_mkt_val_calc, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_next_mkt_val_calc),
	CashFlowCommonData(11, "mths_to_sec_yld_calc", "asset_asset_mths_to_sec_yld_calc",  "mths_to_sec_yld_calc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::asset_asset_mths_to_sec_yld_calc, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_sec_yld_calc),
	CashFlowCommonData(12, "startup", "asset_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ASSET_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* ASSET_ASSET::mCFStaticData[] = {
	&ASSET_ASSET::mCFStaticData_0[0],
	&ASSET_ASSET::mCFStaticData_0[1],
	&ASSET_ASSET::mCFStaticData_0[2],
	&ASSET_ASSET::mCFStaticData_0[3],
	&ASSET_ASSET::mCFStaticData_0[4],
	&ASSET_ASSET::mCFStaticData_0[5],
	&ASSET_ASSET::mCFStaticData_0[6],
	&ASSET_ASSET::mCFStaticData_0[7],
	&ASSET_ASSET::mCFStaticData_0[8],
	&ASSET_ASSET::mCFStaticData_0[9],
	&ASSET_ASSET::mCFStaticData_0[10],
	&ASSET_ASSET::mCFStaticData_0[11],
	&ASSET_ASSET::mCFStaticData_0[12],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for asset_detail_rpt_inv_strat_defn                                                                                       
	const ChoicePair asset_detail_rpt_inv_strat_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList asset_detail_rpt_inv_strat_defnEnumList(2, asset_detail_rpt_inv_strat_defnChoicePairs);

	// EnumList for asset_detail_rpt_output_defn                                                                                       
	const ChoicePair asset_detail_rpt_output_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::HEADER, "Header")
		,ChoicePair(StrEnum::PURCHASED, "Purchased")
		,ChoicePair(StrEnum::VIRTUAL_PURCHASE, "Virtual Purchase")
		,ChoicePair(StrEnum::NOT_PURCHASED, "Not Purchased")
		,ChoicePair(StrEnum::ASSET_DATA, "Asset Data")
	};
	const EnumList asset_detail_rpt_output_defnEnumList(5, asset_detail_rpt_output_defnChoicePairs);

	// EnumList for asset_detail_rpt_pv_defn                                                                                       
	const ChoicePair asset_detail_rpt_pv_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList asset_detail_rpt_pv_defnEnumList(2, asset_detail_rpt_pv_defnChoicePairs);

	// EnumList for asset_mkt_sprd_use_defn                                                                                       
	const ChoicePair asset_mkt_sprd_use_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::HOLD_LEVEL, "Hold Level")
		,ChoicePair(StrEnum::GRADE_TO_ZERO, "Grade to Zero")
		,ChoicePair(StrEnum::SET_TO_ZERO, "Set to Zero")
	};
	const EnumList asset_mkt_sprd_use_defnEnumList(3, asset_mkt_sprd_use_defnChoicePairs);

	// EnumList for asset_sub_port_asset_type                                                                                       
	const ChoicePair asset_sub_port_asset_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BOND, "Bond")
		,ChoicePair(StrEnum::MORTGAGE, "Mortgage")
		,ChoicePair(StrEnum::SECURITIZED_ASSET, "Securitized Asset")
		,ChoicePair(StrEnum::INTEREST_RATE_DERIVATIVE, "Interest Rate Derivative")
		,ChoicePair(StrEnum::EQUITY, "Equity")
		,ChoicePair(StrEnum::REAL_ESTATE, "Real Estate")
		,ChoicePair(StrEnum::INDEX_OPTION, "Index Option")
	};
	const EnumList asset_sub_port_asset_typeEnumList(7, asset_sub_port_asset_typeChoicePairs);

	// EnumList for asset_sub_port_assign_dur_defn                                                                                       
	const ChoicePair asset_sub_port_assign_dur_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EFFECTIVE_DURATION, "Effective Duration")
		,ChoicePair(StrEnum::YEARS_TO_MATURITY, "Years to Maturity")
		,ChoicePair(StrEnum::WEIGHTED_AVERAGE_LIFE, "Weighted Average Life")
	};
	const EnumList asset_sub_port_assign_dur_defnEnumList(3, asset_sub_port_assign_dur_defnChoicePairs);

	// EnumList for asset_sub_port_existing_or_purch_defn                                                                                       
	const ChoicePair asset_sub_port_existing_or_purch_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BOTH, "Both")
		,ChoicePair(StrEnum::EXISTING, "Existing")
		,ChoicePair(StrEnum::PURCHASED, "Purchased")
	};
	const EnumList asset_sub_port_existing_or_purch_defnEnumList(3, asset_sub_port_existing_or_purch_defnChoicePairs);

	// EnumList for asset_sub_port_port_defn                                                                                       
	const ChoicePair asset_sub_port_port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList asset_sub_port_port_defnEnumList(2, asset_sub_port_port_defnChoicePairs);

	// EnumList for asset_sub_port_proxy_bond_sale_class                                                                                       
	const ChoicePair asset_sub_port_proxy_bond_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList asset_sub_port_proxy_bond_sale_classEnumList(4, asset_sub_port_proxy_bond_sale_classChoicePairs);

	// EnumList for asset_sub_port_rpt_defn                                                                                       
	const ChoicePair asset_sub_port_rpt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList asset_sub_port_rpt_defnEnumList(2, asset_sub_port_rpt_defnChoicePairs);

	// EnumList for fast_stat_calc_aig                                                                                       
	const ChoicePair fast_stat_calc_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList fast_stat_calc_aigEnumList(2, fast_stat_calc_aigChoicePairs);

	// EnumList for intex_defn                                                                                       
	const ChoicePair intex_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList intex_defnEnumList(2, intex_defnChoicePairs);

	// EnumList for mkt_val_calc_freq                                                                                       
	const ChoicePair mkt_val_calc_freqChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEGINNING_AND_END_OF_PROJECTION, "Beginning and End of Projection")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY_MAR_JUN_SEP_DEC_, "Quarterly (Mar - Jun - Sep & Dec)")
		,ChoicePair(StrEnum::SEMIANNUALLY_JUN_DEC_, "Semiannually (Jun & Dec)")
		,ChoicePair(StrEnum::ANNUALLY_DEC_, "Annually (Dec)")
		,ChoicePair(StrEnum::EVERY_NTH_YEAR_DEC_, "Every Nth Year (Dec)")
	};
	const EnumList mkt_val_calc_freqEnumList(6, mkt_val_calc_freqChoicePairs);

	// EnumList for mkt_val_calc_freq_sale                                                                                       
	const ChoicePair mkt_val_calc_freq_saleChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AT_ASSET_FREQUENCY, "At Asset Frequency")
		,ChoicePair(StrEnum::WHENEVER_NEEDED, "Whenever Needed")
	};
	const EnumList mkt_val_calc_freq_saleEnumList(2, mkt_val_calc_freq_saleChoicePairs);

	// EnumList for mkt_val_calc_freq_sec_net_yld                                                                                       
	const ChoicePair mkt_val_calc_freq_sec_net_yldChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AT_ASSET_FREQUENCY, "At Asset Frequency")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY_MAR_JUN_SEP_DEC_, "Quarterly (Mar - Jun - Sep & Dec)")
		,ChoicePair(StrEnum::SEMIANNUALLY_JUN_DEC_, "Semiannually (Jun & Dec)")
		,ChoicePair(StrEnum::ANNUALLY_DEC_, "Annually (Dec)")
	};
	const EnumList mkt_val_calc_freq_sec_net_yldEnumList(5, mkt_val_calc_freq_sec_net_yldChoicePairs);

	// EnumList for proxy_bond_defn                                                                                       
	const ChoicePair proxy_bond_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::SINGLE_NON_CALLABLE, "Single Non Callable")
		,ChoicePair(StrEnum::CALLABLE_SEPARATE, "Callable Separate")
	};
	const EnumList proxy_bond_defnEnumList(3, proxy_bond_defnChoicePairs);

	// EnumList for rebase_pv_clone_defn                                                                                       
	const ChoicePair rebase_pv_clone_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRESENT_VALUE, "Present Value")
		,ChoicePair(StrEnum::INTEREST_SAVINGS, "Interest Savings")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
	};
	const EnumList rebase_pv_clone_defnEnumList(3, rebase_pv_clone_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace ASSET_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(ASSET_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(ASSET_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace ASSET_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void ASSET_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> ASSET_ASSET::mgr_;

	Attribute::Descriptor ASSET_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STRING,	"asset_detail_rpt_cusip_id", -1, (size_t)&modelOffset->asset_detail_rpt_cusip_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STR_ENUM,	"asset_detail_rpt_inv_strat_defn", -1, (size_t)&modelOffset->asset_detail_rpt_inv_strat_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_inv_strat_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::STR_ENUM,	"asset_detail_rpt_output_defn", -1, (size_t)&modelOffset->asset_detail_rpt_output_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_output_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::STR_ENUM,	"asset_detail_rpt_pv_defn", -1, (size_t)&modelOffset->asset_detail_rpt_pv_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_pv_defnEnumList, Feature(true)),
	Descriptor(5, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"asset_detail_rpt_sum_asset_defn", -1, (size_t)&modelOffset->asset_detail_rpt_sum_asset_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STR_ENUM,	"asset_mkt_sprd_use_defn", -1, (size_t)&modelOffset->asset_mkt_sprd_use_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_mkt_sprd_use_defnEnumList, Feature(true)),
	Descriptor(8, Attribute::STR_ENUM,	"asset_sub_port_asset_type", -1, (size_t)&modelOffset->asset_sub_port_asset_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_asset_typeEnumList, Feature(true)),
	Descriptor(9, Attribute::STR_ENUM,	"asset_sub_port_assign_dur_defn", -1, (size_t)&modelOffset->asset_sub_port_assign_dur_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_assign_dur_defnEnumList, Feature(true)),
	Descriptor(10, Attribute::STRING,	"asset_sub_port_categories", -1, (size_t)&modelOffset->asset_sub_port_categories,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STRING,	"asset_sub_port_dur_match_defn", -1, (size_t)&modelOffset->asset_sub_port_dur_match_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"asset_sub_port_dur_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_dur_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"asset_sub_port_dur_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_dur_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STR_ENUM,	"asset_sub_port_existing_or_purch_defn", -1, (size_t)&modelOffset->asset_sub_port_existing_or_purch_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_existing_or_purch_defnEnumList, Feature(true)),
	Descriptor(15, Attribute::STRING,	"asset_sub_port_id", -1, (size_t)&modelOffset->asset_sub_port_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::DOUBLE,	"asset_sub_port_inv_exp_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_inv_exp_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"asset_sub_port_min_size", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_min_size,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STR_ENUM,	"asset_sub_port_port_defn", -1, (size_t)&modelOffset->asset_sub_port_port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_port_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::STRING,	"asset_sub_port_proxy_bond_category", -1, (size_t)&modelOffset->asset_sub_port_proxy_bond_category,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::STR_ENUM,	"asset_sub_port_proxy_bond_sale_class", -1, (size_t)&modelOffset->asset_sub_port_proxy_bond_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_proxy_bond_sale_classEnumList, Feature(true)),
	Descriptor(21, Attribute::DOUBLE,	"asset_sub_port_rebal_pct_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_rebal_pct_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"asset_sub_port_rebal_pct_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_rebal_pct_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"asset_sub_port_rebal_tolerance_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_rebal_tolerance_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STR_ENUM,	"asset_sub_port_rpt_defn", -1, (size_t)&modelOffset->asset_sub_port_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sub_port_rpt_defnEnumList, Feature(true)),
	Descriptor(25, Attribute::INT,	"asset_sub_port_sale_priority", -1, (size_t)&modelOffset->asset_sub_port_sale_priority,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STRING,	"asset_sub_ports_selected", -1, (size_t)&modelOffset->asset_sub_ports_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STR_ENUM,	"fast_stat_calc_aig", -1, (size_t)&modelOffset->fast_stat_calc_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fast_stat_calc_aigEnumList, Feature(true)),
	Descriptor(28, Attribute::STR_ENUM,	"intex_defn", -1, (size_t)&modelOffset->intex_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &intex_defnEnumList, Feature(true)),
	Descriptor(29, Attribute::STRING,	"inv_assump_set_id", -1, (size_t)&modelOffset->inv_assump_set_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STR_ENUM,	"mkt_val_calc_freq", -1, (size_t)&modelOffset->mkt_val_calc_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freqEnumList, Feature(true)),
	Descriptor(31, Attribute::STR_ENUM,	"mkt_val_calc_freq_sale", -1, (size_t)&modelOffset->mkt_val_calc_freq_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freq_saleEnumList, Feature(true)),
	Descriptor(32, Attribute::STR_ENUM,	"mkt_val_calc_freq_sec_net_yld", -1, (size_t)&modelOffset->mkt_val_calc_freq_sec_net_yld,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freq_sec_net_yldEnumList, Feature(true)),
	Descriptor(33, Attribute::INT,	"mkt_val_calc_freq_yrs", -1, (size_t)&modelOffset->mkt_val_calc_freq_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STR_ENUM,	"proxy_bond_defn", -1, (size_t)&modelOffset->proxy_bond_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &proxy_bond_defnEnumList, Feature(true)),
	Descriptor(36, Attribute::STR_ENUM,	"rebase_pv_clone_defn", -1, (size_t)&modelOffset->rebase_pv_clone_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &rebase_pv_clone_defnEnumList, Feature(true)),
	Descriptor(37, Attribute::STRING,	"ms_bond_readfile", -1, (size_t)&modelOffset->ms_bond_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::STRING,	"ms_eio_readfile", -1, (size_t)&modelOffset->ms_eio_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STRING,	"ms_epa_readfile", -1, (size_t)&modelOffset->ms_epa_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::STRING,	"ms_mtg_readfile", -1, (size_t)&modelOffset->ms_mtg_readfile,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_final_period)),
	Descriptor(43, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ASSET_ASSET_UDF::asset_asset_proj_date_adj)),
	Descriptor(44, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_proj_start_date)),
	Descriptor(45, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_proj_start_mth)),
	Descriptor(46, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_proj_start_yr)),
	Descriptor(47, Attribute::SCALAR_INT,	"scen_day", -1, (size_t)&modelOffset->scen_day,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_scen_day)),
	Descriptor(48, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ASSET_ASSET_UDF::asset_asset_start_period)),
	};

	Attribute::Descriptor* ASSET_ASSET::descriptorTable[] = {
	&ASSET_ASSET::descriptor_0[0],
	&ASSET_ASSET::descriptor_0[1],
	&ASSET_ASSET::descriptor_0[2],
	&ASSET_ASSET::descriptor_0[3],
	&ASSET_ASSET::descriptor_0[4],
	&ASSET_ASSET::descriptor_0[5],
	&ASSET_ASSET::descriptor_0[6],
	&ASSET_ASSET::descriptor_0[7],
	&ASSET_ASSET::descriptor_0[8],
	&ASSET_ASSET::descriptor_0[9],
	&ASSET_ASSET::descriptor_0[10],
	&ASSET_ASSET::descriptor_0[11],
	&ASSET_ASSET::descriptor_0[12],
	&ASSET_ASSET::descriptor_0[13],
	&ASSET_ASSET::descriptor_0[14],
	&ASSET_ASSET::descriptor_0[15],
	&ASSET_ASSET::descriptor_0[16],
	&ASSET_ASSET::descriptor_0[17],
	&ASSET_ASSET::descriptor_0[18],
	&ASSET_ASSET::descriptor_0[19],
	&ASSET_ASSET::descriptor_0[20],
	&ASSET_ASSET::descriptor_0[21],
	&ASSET_ASSET::descriptor_0[22],
	&ASSET_ASSET::descriptor_0[23],
	&ASSET_ASSET::descriptor_0[24],
	&ASSET_ASSET::descriptor_0[25],
	&ASSET_ASSET::descriptor_0[26],
	&ASSET_ASSET::descriptor_0[27],
	&ASSET_ASSET::descriptor_0[28],
	&ASSET_ASSET::descriptor_0[29],
	&ASSET_ASSET::descriptor_0[30],
	&ASSET_ASSET::descriptor_0[31],
	&ASSET_ASSET::descriptor_0[32],
	&ASSET_ASSET::descriptor_0[33],
	&ASSET_ASSET::descriptor_0[34],
	&ASSET_ASSET::descriptor_0[35],
	&ASSET_ASSET::descriptor_0[36],
	&ASSET_ASSET::descriptor_0[37],
	&ASSET_ASSET::descriptor_0[38],
	&ASSET_ASSET::descriptor_0[39],
	&ASSET_ASSET::descriptor_0[40],
	&ASSET_ASSET::descriptor_0[41],
	&ASSET_ASSET::descriptor_0[42],
	&ASSET_ASSET::descriptor_0[43],
	&ASSET_ASSET::descriptor_0[44],
	&ASSET_ASSET::descriptor_0[45],
	&ASSET_ASSET::descriptor_0[46],
	&ASSET_ASSET::descriptor_0[47],
	&ASSET_ASSET::descriptor_0[48],
	nullptr};
	const size_t ASSET_ASSET::sDescriptorCount = 49;

//factory
ASSET_ASSET* ASSET_ASSET::makeThis(int isSubmodel, ModelClass* owner, ASSET_ASSET* peer, 
						int mainRebase, const xstring &name, ASSET_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ASSET_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ASSET_ASSET");
#endif
	ASSET_ASSET* newP = (ASSET_ASSET*)new ASSET_ASSET_UDF
   	  ("asset_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	newP->sm_asset_sub_port.setPersistentObject(A_SUBPORT_ASSET_persistent_object::makeThis(1, newP, (A_SUBPORT_ASSET*)(peer?peer->sm_asset_sub_port.getPersistentObject():0), mainRebase, name + "|asset_sub_port", arrayTemplate?arrayTemplate->sm_asset_sub_port.getPersistentObject():0, false));

	newP->sm_bond.setPersistentObject(BOND_ASSET_persistent_object::makeThis(1, newP, (BOND_ASSET*)(peer?peer->sm_bond.getPersistentObject():0), mainRebase, name + "|bond", arrayTemplate?arrayTemplate->sm_bond.getPersistentObject():0, false));

	newP->sm_mtg.setPersistentObject(MTG_ASSET_persistent_object::makeThis(1, newP, (MTG_ASSET*)(peer?peer->sm_mtg.getPersistentObject():0), mainRebase, name + "|mtg", arrayTemplate?arrayTemplate->sm_mtg.getPersistentObject():0, false));

	newP->sm_eio.setPersistentObject(EIO_ASSET_persistent_object::makeThis(1, newP, (EIO_ASSET*)(peer?peer->sm_eio.getPersistentObject():0), mainRebase, name + "|eio", arrayTemplate?arrayTemplate->sm_eio.getPersistentObject():0, false));

	newP->sm_epa.setPersistentObject(EPA_ASSET_persistent_object::makeThis(1, newP, (EPA_ASSET*)(peer?peer->sm_epa.getPersistentObject():0), mainRebase, name + "|epa", arrayTemplate?arrayTemplate->sm_epa.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|adco") == unusedModels.end()) {
	newP->sm_adco = ADCO_ASSET::makeThis(1, newP, peer?peer->sm_adco:0, mainRebase, name + "|adco", (ADCO_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_adco:0));
	newP->adopt(newP->sm_adco);
	}

	if (find(unusedModels.begin(), unusedModels.end(), name + "|intex") == unusedModels.end()) {
	newP->sm_intex = INTEX_ASSET::makeThis(1, newP, peer?peer->sm_intex:0, mainRebase, name + "|intex", (INTEX_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_intex:0));
	newP->adopt(newP->sm_intex);
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
ASSET_ASSET_persistent_object* ASSET_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, ASSET_ASSET* peer, 
							int mainRebase, const xstring &name, ASSET_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ASSET_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ASSET_ASSET_persistent_object");
#endif
	ASSET_ASSET_persistent_object* newP = (ASSET_ASSET_persistent_object*)new ASSET_ASSET_persistent_object
   	  ("asset_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			ASSET_ASSET_persistent_object* pd = dynamic_cast<ASSET_ASSET_persistent_object*>(product);
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
	newP->sm_asset_sub_port.setPersistentObject(A_SUBPORT_ASSET_persistent_object::makeThis(1, newP, (A_SUBPORT_ASSET*)(peer?peer->sm_asset_sub_port.getPersistentObject():0), mainRebase, name + "|asset_sub_port", arrayTemplate?arrayTemplate->sm_asset_sub_port.getPersistentObject():0, false));

	newP->sm_bond.setPersistentObject(BOND_ASSET_persistent_object::makeThis(1, newP, (BOND_ASSET*)(peer?peer->sm_bond.getPersistentObject():0), mainRebase, name + "|bond", arrayTemplate?arrayTemplate->sm_bond.getPersistentObject():0, false));

	newP->sm_mtg.setPersistentObject(MTG_ASSET_persistent_object::makeThis(1, newP, (MTG_ASSET*)(peer?peer->sm_mtg.getPersistentObject():0), mainRebase, name + "|mtg", arrayTemplate?arrayTemplate->sm_mtg.getPersistentObject():0, false));

	newP->sm_eio.setPersistentObject(EIO_ASSET_persistent_object::makeThis(1, newP, (EIO_ASSET*)(peer?peer->sm_eio.getPersistentObject():0), mainRebase, name + "|eio", arrayTemplate?arrayTemplate->sm_eio.getPersistentObject():0, false));

	newP->sm_epa.setPersistentObject(EPA_ASSET_persistent_object::makeThis(1, newP, (EPA_ASSET*)(peer?peer->sm_epa.getPersistentObject():0), mainRebase, name + "|epa", arrayTemplate?arrayTemplate->sm_epa.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|adco") == unusedModels.end()) {
	newP->sm_adco = (ADCO_ASSET*)ADCO_ASSET_persistent_object::makeThis(1, newP, peer?peer->sm_adco:0, mainRebase, name + "|adco", (ADCO_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_adco:0), fixedArray);
	newP->adopt(newP->sm_adco);
	}

	if (find(unusedModels.begin(), unusedModels.end(), name + "|intex") == unusedModels.end()) {
	newP->sm_intex = (INTEX_ASSET*)INTEX_ASSET_persistent_object::makeThis(1, newP, peer?peer->sm_intex:0, mainRebase, name + "|intex", (INTEX_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_intex:0), fixedArray);
	newP->adopt(newP->sm_intex);
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (ASSET_ASSET_UDF::*dPF) ();
typedef double (ASSET_ASSET_UDF::*dPFd) (double);
typedef int (ASSET_ASSET_UDF::*iPF) ();
typedef int (ASSET_ASSET_UDF::*iPFi) (int);
typedef xstring (ASSET_ASSET_UDF::*sPF) ();
typedef xstring (ASSET_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
ASSET_ASSET::ASSET_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_adco(0)
  , sm_asset_sub_port(0, 0, 0)
  , sm_bond(0, 0, 0)
  , sm_eio(0, 0, 0)
  , sm_epa(0, 0, 0)
  , sm_intex(0)
  , sm_mtg(0, 0, 0)
	, adco(company_asset_adco)
	, asset(company_asset)
	, bond(company_asset_bond)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ASSET_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
ASSET_ASSET::ASSET_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(12, ASSET_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_adco(0)
  , sm_asset_sub_port(0, 0, 0)
  , sm_bond(0, 0, 0)
  , sm_eio(0, 0, 0)
  , sm_epa(0, 0, 0)
  , sm_intex(0)
  , sm_mtg(0, 0, 0)
	, adco(company_asset_adco)
	, asset(company_asset)
	, bond(company_asset_bond)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
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

		adopt(&sm_asset_sub_port);
		adopt(&sm_bond);
		adopt(&sm_eio);
		adopt(&sm_epa);
		adopt(&sm_mtg);

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
#ifdef __CREATE_BOND_ASSET_CLASS_
       company_asset_bond = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_is = 0;
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
       company_asset_mtg_mtg_cf_mtg_pv = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_mtg_ym = 0;
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

	for (int cf_no = 1; cf_no <= 12; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ASSET_ASSET_UDF::*dPXi2) (int, int);
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


 void ASSET_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
		company_asset_bond = (BOND_ASSET*)(findUnique("company|asset|bond"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_is = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_is"));
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
		company_asset_mtg_mtg_cf_mtg_pv = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_pv"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_mtg_ym = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_ym"));
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
 }
//copy_names END@2


 void ASSET_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int ASSET_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& ASSET_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double ASSET_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int ASSET_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double ASSET_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double ASSET_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void ASSET_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ASSET_ASSET_persistent_object::write(long include_submodels) {
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

	void ASSET_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ASSET_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ASSET_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	ASSET_ASSET_persistent_object::~ASSET_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool ASSET_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void ASSET_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void ASSET_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void ASSET_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ASSET_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ASSET_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* ASSET_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* ASSET_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* ASSET_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char ASSET_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void ASSET_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
ASSET_ASSET_persistent_object::ASSET_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			ASSET_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(ASSET_ASSET::sm_bond_is)
	, sm_bond_pv(ASSET_ASSET::sm_bond_pv)
	, sm_bond_ym(ASSET_ASSET::sm_bond_ym)
	, sm_mtg_is(ASSET_ASSET::sm_mtg_is)
	, sm_mtg_pv(ASSET_ASSET::sm_mtg_pv)
	, sm_mtg_ym(ASSET_ASSET::sm_mtg_ym)

	, sm_adco(ASSET_ASSET::sm_adco)
	, sm_asset_sub_port(ASSET_ASSET::sm_asset_sub_port)
	, sm_bond(ASSET_ASSET::sm_bond)
	, sm_eio(ASSET_ASSET::sm_eio)
	, sm_epa(ASSET_ASSET::sm_epa)
	, sm_intex(ASSET_ASSET::sm_intex)
	, sm_mtg(ASSET_ASSET::sm_mtg)
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
ASSET_ASSET::~ASSET_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
//	ModelClass* asset_sub_port_persObj = sm_asset_sub_port.getPersistentObject();
//	doAdopt(asset_sub_port_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_asset_sub_port.IsValidSubModelOfBaseModelClass()){
		sm_asset_sub_port.resize(0);
		delete sm_asset_sub_port.getPersistentObject();
		sm_asset_sub_port.mPersistentObj = 0;
	}

//	ModelClass* bond_persObj = sm_bond.getPersistentObject();
//	doAdopt(bond_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_bond.IsValidSubModelOfBaseModelClass()){
		sm_bond.resize(0);
		delete sm_bond.getPersistentObject();
		sm_bond.mPersistentObj = 0;
	}

//	ModelClass* eio_persObj = sm_eio.getPersistentObject();
//	doAdopt(eio_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_eio.IsValidSubModelOfBaseModelClass()){
		sm_eio.resize(0);
		delete sm_eio.getPersistentObject();
		sm_eio.mPersistentObj = 0;
	}

//	ModelClass* epa_persObj = sm_epa.getPersistentObject();
//	doAdopt(epa_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_epa.IsValidSubModelOfBaseModelClass()){
		sm_epa.resize(0);
		delete sm_epa.getPersistentObject();
		sm_epa.mPersistentObj = 0;
	}

//	ModelClass* mtg_persObj = sm_mtg.getPersistentObject();
//	doAdopt(mtg_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_mtg.IsValidSubModelOfBaseModelClass()){
		sm_mtg.resize(0);
		delete sm_mtg.getPersistentObject();
		sm_mtg.mPersistentObj = 0;
	}

}
//destructor END@2
void ASSET_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void ASSET_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void ASSET_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void ASSET_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void ASSET_ASSET::start_of_projection() {
}
//start_of_projection END@2

void ASSET_ASSET::end_of_projection() {
}
//end_of_projection END@2

void ASSET_ASSET::start_of_layer() {
}


void ASSET_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void ASSET_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void ASSET_ASSET::after_startup(int decrement) {
// Call startup for submodels
	   sm_asset_sub_port.doBeforeStartupProcessing(decrement);

	   sm_bond.doBeforeStartupProcessing(decrement);

	   sm_mtg.doBeforeStartupProcessing(decrement);

	   sm_eio.doBeforeStartupProcessing(decrement);

	   sm_epa.doBeforeStartupProcessing(decrement);

  if(sm_adco)
   sm_adco->doBeforeStartupProcessing(decrement);

  if(sm_intex)
   sm_intex->doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void ASSET_ASSET::ms_BeforeStartup() {
	if (modelNameNosub() == "company|asset" && sm_bond.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_bond.ms_ReadArray(false);
  		sm_bond.setModelPointFileId(ms_bond_readfile);

		sm_bond.setSearchFields(sm_bond.getPersistentObject()->SearchFields);

  		sm_bond.resize(0);
  		if(sm_bond.gotoRec(1))
  			sm_bond.readFile();

	}
	if (modelNameNosub() == "company|asset" && sm_mtg.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_mtg.ms_ReadArray(false);
  		sm_mtg.setModelPointFileId(ms_mtg_readfile);

		sm_mtg.setSearchFields(sm_mtg.getPersistentObject()->SearchFields);

  		sm_mtg.resize(0);
  		if(sm_mtg.gotoRec(1))
  			sm_mtg.readFile();

	}
	if (modelNameNosub() == "company|asset" && sm_eio.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_eio.ms_ReadArray(false);
  		sm_eio.setModelPointFileId(ms_eio_readfile);

		sm_eio.setSearchFields(sm_eio.getPersistentObject()->SearchFields);

  		sm_eio.resize(0);
  		if(sm_eio.gotoRec(1))
  			sm_eio.readFile();

	}
	if (modelNameNosub() == "company|asset" && sm_epa.ms_ReadArray()) {
		if (iterationLoopRun) // don't read array next time
			sm_epa.ms_ReadArray(false);
  		sm_epa.setModelPointFileId(ms_epa_readfile);

		sm_epa.setSearchFields(sm_epa.getPersistentObject()->SearchFields);

  		sm_epa.resize(0);
  		if(sm_epa.gotoRec(1))
  			sm_epa.readFile();

	}
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> ASSET_ASSET::ddfVector;
BitArray ASSET_ASSET::dataVariables(49);
bool ASSET_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool ASSET_ASSET::writeClassInfo = true;

void ASSET_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, ASSET_ASSET::descriptor_0>::dT = ASSET_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, ASSET_ASSET::descriptor_0>::dT = ASSET_ASSET::descriptor_0;

