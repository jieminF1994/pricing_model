
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
#include "ModelClass\adco_asset_udf.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
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

ofstream& ADCOFile = *new ofstream;
xstring tempString;

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
#ifndef adco_asset_TableDefs
#define adco_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection ADCO_ASSET::TTHC;
void ADCO_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double ADCO_ASSET_UDF::adco_asset_cal_mth(int t) {
//^^^



//^^^

#line 1 "cal_mth.ADCO_ASSET.for"
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
double ADCO_ASSET_UDF::adco_asset_cal_yr(int t) {
//^^^



//^^^

#line 1 "cal_yr.ADCO_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double ADCO_ASSET_UDF::adco_asset_cal_yr_relative(int t) {
//^^^



//^^^

#line 1 "cal_yr_relative.ADCO_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double ADCO_ASSET_UDF::adco_asset_date(int t) {
//^^^



//^^^

#line 1 "date.ADCO_ASSET.for"
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
double ADCO_ASSET_UDF::adco_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.ADCO_ASSET.for"
//Delete maps for each scenario
map <string, CHistData>::iterator HistIt;
CHistData * pHist;
for (HistIt = HistData.begin(); HistIt != HistData.end(); HistIt++)
	{
    pHist = &((*HistIt).second);
	delete pHist->Rates;
	}
HistData.clear();

if (is_last_proj_task_loop)
	{
	if (pAdcoSystem != NULL)
		adco_DestroySystem(static_cast <CAdcoSys*> (pAdcoSystem));
	
	pAdcoSystem = NULL;
	
	ADCOFile.close();
	delete &ADCOFile;
	}

return 0.0;

}


//@@ END

//@@ START - get_prepmt_rate
// Get Prepayment Rate                                                                                             
// Column:GET_PREPMT_RATE
//========================================================
double ADCO_ASSET_UDF::adco_asset_get_prepmt_rate(int t) {
//^^^



//^^^

#line 1 "get_prepmt_rate.ADCO_ASSET.for"
return prepmt_rates[t];

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double ADCO_ASSET_UDF::adco_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.ADCO_ASSET.for"
static int first_time = 1;
static int loaded_proj_task_loop = -999;

if (first_time)
	{
	pAdcoSystem = adco_CreateSystem();

	// create adco detail report file
	if (asset_detail_rpt_defn == YES)
		{
		xstring output_name = "";
		xstring output_file_name = replaceWildcards(output_location());
		output_file_name = xstring(output_file_name(0 , output_file_name.find_first_of("~")));

		xstring adco_detail_full_file_name
		= output_file_name
		  + "_ADCoDetail.csv";

		ADCOFile.open(adco_detail_full_file_name);
		ADCOFile.setf(ios::fixed, ios::floatfield);
		ADCOFile.precision(12);

		if (!ADCOFile)
			{
			xstring message 
			= "Cannot open " + adco_detail_full_file_name + 
			  + ". Check that the directory has been created and that you have permission to write to the directory.";

			throw FatalError(message);
			}
		else
			ADCOFile << endl
					<< "Andrew Davidson Prepayment Detail Report For "
					<< output_file << endl;
		}
	first_time = 0;
	}

if (isMainModel)
	{
	if (loaded_proj_task_loop != proj_task_loop_num)
		rates->initialize(t);
	}
	
if (isMainModel)
	setup_prepmt_rates(t);

loaded_proj_task_loop = proj_task_loop_num;
	
return 1.0;

}


//@@ END

//@@ START - process_adco_detail
// Process ADCo detail                                                                                             
// Column:PROCESS_ADCO_DETAIL
//========================================================
double ADCO_ASSET_UDF::adco_asset_process_adco_detail(int t) {
//^^^



//^^^

#line 1 "process_adco_detail.ADCO_ASSET.for"
if (asset_detail_rpt_flag == YES
	&& (t >= asset_detail_rpt_start_period
		&& t <= asset_detail_rpt_final_period))
	return 1.0;

return 0.0;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double ADCO_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.ADCO_ASSET.for"
#if 0 // START_HEADER
#ifndef ADCO_H_
#define ADCO_H_

//MBS defines
#ifndef max_maturity
#define max_maturity        600
#define months_in_yr        12
#define maximum_lag		 4
#define lag_wght_vecsize   (maximum_lag + 1)
#define curr_cpn_vecsize   (600 + maximum_lag)
#define balloon_7yr_mat     84
#define balloon_5yr_mat     60
#define balloon_10yr_mat	120
#define balloon_3yr_mat	 36
#endif

//ABS defines
#ifndef abs_mh_maxlag
#define abs_mh_maxlag	4
#define abs_max_maturity	600
#endif

// MBS
#ifndef mbs_enums
#define mbs_enums

typedef enum typeofloan
{
FNMA_30YR,
FNMA_15YR,
FNMAB_5YR,
FNMAB_7YR,
FRDG_30YR,
FRDG_20YR,
FRDG_15YR,
FRDGB_5YR,
FRDGB_7YR,
GNMA_30YR,
GNMA_15YR,
GNMA2_30YR,
FNMA_20YR,
WHOLE_30YR,
WHOLE_15YR,
RELO_30YR,
RELO_15YR,
FNMA_10YR,
FRDG_10YR,
GNMA2_15YR,
WHOLEB_5YR,
WHOLEB_7YR,
FNMAB_10YR,
FRDGB_10YR,
FNMAB_3YR,
FRDGB_3YR,
ALT_A_15YR,
ALT_A_30YR,
MBS_RESERVE0,
MBS_RESERVE1,
MBS_RESERVE2,
MBS_RESERVE3,
MBS_RESERVE4,
MBS_RESERVE5,
MBS_RESERVE6,
MBS_RESERVE7,
MBS_RESERVE8,
MBS_RESERVE9,
MAX_LOANTYPE
} loantype;

typedef enum typeofarm
{
FNMA_1YR_NONC,
FNMA_1YR_CONV,
FRDH_1YR_NONC,
FRDH_1YR_CONV,
FNMA_3YR,
FRDH_3YR,
GNMA_1YR,
D11_COFI,
ARM_RESERVE0,
ARM_RESERVE1,
ARM_RESERVE2,
ARM_RESERVE3,
ARM_RESERVE4,
ARM_RESERVE5,
ARM_RESERVE6,
ARM_RESERVE7,
ARM_RESERVE8,
ARM_RESERVE9,
NUM_ARMTYPES
} armtype;

typedef enum typeofarmindex
{
PAR_TSY_1YR,
PAR_LIBOR_6M,
PAR_LIBOR_1YR,
MTA_12,
PAR_TSY_3YR,
PAR_TSY_5YR,
COFI_11D
} armtypeindex;

typedef enum typeofissuer
{
FANNIE_MAE,
FREDDIE_MAC,
GINNIE_MAE,
NONAGENCY_SUBPRIME,
NONAGENCY_PRIME,
NONAGENCY_OTHER
} issuertype;

typedef enum errorcodetype
{
ADCOPP_OK,
ILLEGAL_LOAN_TYPE,
LICENSE_EXPIRED,
DATAFILE_MISSING,
ILLEGAL_DATE,
NO_MEMORY,
DATAFILE_ERROR,
ADCOPP_FPE
#ifdef AD_LICKEYFILE 
,KEYFILE_FAILURE
#endif
} errorcode;
#endif

// ABS
#ifndef abs_enums
#define abs_enums
typedef enum abserrcode
{
ADCO_ABS_OK,
ADCO_ABS_INVALID_TYPE,
ADCO_ABS_LICENSE_EXPIRED,
ADCO_ABS_DATAFILE_MISSING,
ADCO_ABS_ILLEGAL_DATE,
ADCO_ABS_NO_MEMORY,
ADCO_ABS_DATAFILE_ERROR,
ADCO_ABS_ADCOPP_FPE,
ADCO_ABS_MAXERRORNO
} abs_errorcode;

// Auto Loans 
typedef enum abs_autot
{	
ADCO_AUTO_ALL,
ADCO_AUTO_STRAT,
ADCO_AUTO_MAXTYPE		
} abs_auto_type;

// Manufactured Houseing Enums 
typedef enum abs_mh_uset
{
ADCO_MH_RENTAL,
ADCO_MH_TRAILER,
ADCO_MH_OWNER,
ADCO_MH_UNKUSE,
ADCO_MH_MAXUSE
} abs_mh_use_type;

typedef enum abs_mh_widtht
{
ADCO_MH_SINGLE,
ADCO_MH_DOUBLE,
ADCO_MH_UNKWDTH,
ADCO_MH_MAXWIDTH
} abs_mh_width_type;

typedef enum abs_mh_vintt
{
ADCO_MH_NEW,
ADCO_MH_OLD,
ADCO_MH_UNKVINT,
ADCO_MH_MAXVINT
} abs_mh_vint_type;

typedef enum abs_termtype
{
ADCO_ABS_5YR,
ADCO_ABS_15YR,
ADCO_ABS_30YR,
ADCO_ABS_MAXTERM
} abs_term_type;	

// Home Equity Loans 
typedef enum abs_heliss
{		
ADCO_HEL_UNK,			
ADCO_HEL_AFC,			
ADCO_HEL_ADV,			
ADCO_HEL_EC,
ADCO_HEL_GE,	
ADCO_HEL_MON,	
ADCO_HEL_UFC,
ADCO_HEL_INM,	
ADCO_HEL_CON,		
ADCO_HEL_MAXTYPE	
} abs_hel_issuer;
#endif

#ifndef abs_enums2
#define abs_enums2
// Added for New ARM-HEL model 
typedef enum adco_mtfra
{ 
ADCO_ABS_ARMHEL_6,
ADCO_ABS_ARMHEL_12,
ADCO_ABS_ARMHEL_24,
ADCO_ABS_ARMHEL_36,
ADCO_ABS_ARMHEL_UNKNOWN,
ADCO_ABS_ARMHEL_MAXRESET
} adco_armhel_reset;
#endif

#define ALLOCATE_ADCO
// start of EnumConst.h
#ifndef ADPPMDLAPI_H
#define ADPPMDLAPI_H

// Stuff To Make Win32 DLL Import/Export Happen Automatically
#ifdef WIN32
// Force structure alignment to 32-bit so legacy
// applications ported from 16-bit Windows don't mess up structure
// alignments (esp. of adco_CParam)
#pragma pack( push, inside_adppmdlapi, 8)
#ifdef WINDOWS_STATIC
#define ADPPMDL_API
#else
#ifdef MAKE_ADPPMDL
#define ADPPMDL_API __declspec(dllexport)
#else
#define ADPPMDL_API __declspec(dllimport)
#endif
#endif
#define EXTERN extern ADPPMDL_API
#define THROWS( errorclass )
#else
#define ADPPMDL_API
#define EXTERN extern
// #define THROWS( errorclass ) throw errorclass
#define THROWS( errorclass )
#endif

//Some Useful Defines
#define minimum(a,b) ((a) < (b) ? (a) : (b))
#define maximum(a,b) ((a) < (b) ? (b) : (a))
#ifndef NULL
#define NULL 0
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1300)
#define DATEADD(m, y, d)                        \
    (y) = (y) + ((d) / 12);                     \
    (m) = (m) + ((d) % 12);                     \
    if((m) < 1) { --(y); (m) += 12;}            \
    if((m) > 12) { ++(y); (m) -= 12;}           \
#define DATEDIFF(sy, sm, ey, em)                \
    ((ey) - (sy)) * 12 + ((em) - (sm));
#else
inline void DATEADD(int& m, int& y, int d){
    y = y + (d / 12);
    m = m + (d % 12);
    if( m < 1 ) { --y; m += 12;}
    if( m > 12 ) { ++y; m -= 12;}
}
inline int DATEDIFF(int sy, int sm, int ey, int em){
    return (ey - sy) * 12 + (em - sm);
}
#endif

#ifdef __unix
#ifdef __sun
#if __SUNPRO_CC == 0x420
#ifndef bool
#define bool short
#define true 1
#define false 0
#endif
#endif
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// All the dynamism of this model comes from lists of enumerated constants
// represented by adco_cEnumElem and adco_cEnumeration
/////////////////////////////////////////////////////////////////////////////
class ADPPMDL_API adco_cEnumElem;
class ADPPMDL_API adco_cEnumeration;

// All Thrown Errors are subclassed off this class
class ADPPMDL_API adco_cError;

// Data Classes for Getting Stuff in and out of models
class ADPPMDL_API adco_CParam;
class ADPPMDL_API adco_TimeSeries;
class ADPPMDL_API adco_CString;
struct ADPPMDL_API vecspec;

// All Models are Subclasses of CAdppmdl.  Instantiation is done by the object
// Factory
class ADPPMDL_API CAdppmdl;
class ADPPMDL_API CAdcoSys;

enum ADCO_DATA_TYPE
{
    AD_TYPE_INTEGER = 0,
    AD_TYPE_DOUBLE,
    AD_TYPE_STRING,
    AD_TYPE_ENUMTYPE,
    AD_TYPE_TIMESERIES,
    AD_TYPE_UDPTRTYPE,
    AD_TYPE_LISTTYPE,
    AD_TYPE_E_INFOONLY,
    AD_TYPE_E_WARNING,
    AD_TYPE_E_ERROR,
    AD_TYPE_NTYPE,  // NULL type
    AD_TYPE_VECLIST,
    AD_TYPE_CONDLIST
};

/////////////////////////////////////////////////////////////////////////////
// Interfaces
/////////////////////////////////////////////////////////////////////////////
class ADPPMDL_API adco_cEnumeration {
public:
    virtual void Initialize( void ) const = 0;
    virtual const char* name() const = 0;
    virtual const char* description() const = 0;
    virtual unsigned int idx( const char* ename ) const = 0;
    virtual const char* elem_name ( unsigned int n ) const = 0;
    virtual adco_cEnumElem element( unsigned int n ) const = 0;
    virtual adco_cEnumElem element( const char* ename ) const = 0;
    virtual const char* elem_desc ( unsigned int n ) const = 0;
    virtual const char* elem_desc ( const char* ename ) const = 0;
    virtual const adco_cEnumElem elem_class ( unsigned int n ) const = 0;
    virtual const adco_cEnumElem elem_class ( const char* ename ) const = 0;
    virtual unsigned int elem_count () const = 0;
    bool operator==( const adco_cEnumeration& elist ) const { return this == &elist; }
    bool operator!=( const adco_cEnumeration& elist ) const { return this != &elist; }
    virtual bool contains( const adco_cEnumElem& e ) const = 0;
    virtual bool contains( const char* ename ) const = 0;
    virtual unsigned int idx( const adco_CParam& ParamElem ) const;
    virtual const char * sub_name ( unsigned int n ) const
    { throw("adco_cEnumeration.sub_name() not supported"); return (char *) 0;};
    virtual const char * sub_name ( const char* ename ) const
    { throw("adco_cEnumeration.sub_name() not supported"); return (char *) 0;};
    virtual enum ADCO_DATA_TYPE elem_type(unsigned int n) const;
}; /* class adco_cEnumeration */

class ADPPMDL_API adco_cEnumElem {
protected:
    const adco_cEnumeration* mList;
    unsigned int mIdx;
public:
    // Constructors
    adco_cEnumElem(){};
    adco_cEnumElem( const adco_cEnumeration& elist, unsigned int elem_idx );
    adco_cEnumElem( const adco_cEnumeration& elist, const char* elem_name );
    // Copy Constructor
adco_cEnumElem( const adco_cEnumElem& ee)
    : mList( ee.adco_cEnumElem::list() )
        , mIdx( ee.adco_cEnumElem::idx() ) {}
    // Copy by assignment
    adco_cEnumElem& operator=( const adco_cEnumElem& ee )
        { mList = ee.list(); mIdx = ee.idx(); return *this; }
    // Parent List
    const adco_cEnumeration* list() const { return mList; }
    // Numeric Idx in Parent List
    unsigned int idx() const { return mIdx; }
    operator unsigned int(void) const { return mIdx; }
    virtual const char* name() const { return mList->elem_name( mIdx ); }
    virtual const char* description() const { return mList->elem_desc( mIdx ); }
    virtual const adco_cEnumElem classification() const
    { return mList->elem_class( mIdx ); }
    virtual bool operator==( const adco_cEnumElem& ee ) const
    { return ( mList == ee.mList && mIdx == ee.mIdx ); }
    virtual bool operator!=( const adco_cEnumElem& ee ) const
    { return ( mList != ee.mList || mIdx != ee.mIdx ); }
    virtual const char * sub_name() const
    { return mList->sub_name( mIdx ); }
    virtual enum ADCO_DATA_TYPE elem_type() const
    { return mList->elem_type(mIdx); }
}; /* class adco_cEnumElem */

// Base class for all thrown adco model errors
// When a specific error is thrown, it's copy constructor
// is used to copy the the error from the error context to the heap.
// After the stack is cut back, destroying the original error instance,
// the base copy constructor is used to copy a BASE CLASS adco_cError
// instance into the error handler (catch block) context.
// This base class instance will contain an mRealMe that points
// to the heap copy of the real error.
// When the handler context is exited, the heap copy of the real error
// and the base class instance in the handler context are destroyed.
// For this reason, the base copy constructor is smart.  An attempt to
// copy a base class error instance out of the handler will yield a
// mRealMe that points to itself, and the original error info is lost.
class ADPPMDL_API adco_cError
{
protected:
    const adco_cError* mRealMe;
    adco_cError() { mRealMe = this; }
public:
    adco_cError( const adco_cError& e);
    virtual adco_cEnumElem severity() const;
    virtual const char* message() const;
    virtual unsigned int msglen() const;
    virtual adco_cEnumElem msgelement() const; // in Global System ERRORDEFS list, or NULL_ELEM
}; /* class ADPPMDL_API adco_cError */

struct  vecspec
{
    double forward_final;
    double forward_value;
    double backward_final;
    double backward_value;
    vecspec(){};
    vecspec(double modeltune, double tune)
    {
        forward_final = tune;
        forward_value = modeltune * tune;
        backward_final = 1.0;
        backward_value = modeltune;
    }
    vecspec(double modeltune, double tune, double fbtune)
    {
        forward_final = tune * fbtune;
        forward_value = modeltune * tune * fbtune;
        backward_final = fbtune;
        backward_value = modeltune*fbtune;
    }
    void addset(double modeltune, double tune)
    {
        forward_final = tune;
        forward_value = modeltune + tune;
        backward_final = 0.0;
        backward_value = modeltune;
    }
    void addset(double modeltune, double tune, double fbtune)
    {
        forward_final = tune + fbtune;
        forward_value = modeltune + tune + fbtune;
        backward_final = fbtune;
        backward_value = modeltune + fbtune;
    }
};

class ADPPMDL_API adco_TimeSeries
{
public:
    // Constructors & Desctructors
    // Use Internal Storage Vector if Values = NULL
    // Defaults:
    //              freq = ADCO_MONTHLY
    //              Values = NULL (Internal Storage)
    //              maxobs = 0 => TSALLOCINCREMENT
    //              newlength = 0 => same length as source
    //              newlength > 0 => set length, copy nobs=min(old length, new length)
    adco_TimeSeries( int NumObs, int SYear, int SPeriod,
                     adco_cEnumElem freq, double* Values = NULL,
                     int maxobs = 0  );
    // Copies are always deep
    adco_TimeSeries( const adco_TimeSeries& ts, int newlength = 0 );
    adco_TimeSeries& operator=( const adco_TimeSeries& tsval );
    ~adco_TimeSeries();

    // Public Interface
    adco_cEnumElem frequency() const { return mFrequency; }
    int StartPeriod() const { return mStartPeriod; }
    int StartYear() const { return mStartYear; }
    int LastYear() const;
    int LastPeriod() const;
    int Nobs() const { return mNobs; }
    int Length() const { return mLength; }
    double* Values() const { return mValues; }
    int GetIdx( int year, int period ) const;
    int GetRawIdx( int year, int period ) const;
    double GetVal( int year, int period ) const; // Can Throw Invalid Index
    void GetVal( int year, int period, double* vec, int NumObs ) const;
    void ShallowSetVal( int year, int period, double* vec, int NumObs );
    void SetVal( int year, int period, double value, int NumObs = 1 );
    void SetVal( int year, int period, double* vec, int NumObs );
    void SetVal( int year, int period, const adco_TimeSeries& TS, int NumObs = 0 );
    // Set from list of nobs/value pairs terminated by a zero pair
    void SetValFromList( int year, int period, const double* vec );
    //Extend repeats first/last value as needed
    void Extend( int SYear, int SPeriod, int NumObs );
    void Extend( int SYear, int SPeriod, int EYear, int EPeriod );
    void Truncate( int NumObs );
    void Truncate( int EYear, int EPeriod );
    bool InternalStore() const { return mInternalStore; }

protected:
    int PerYear() const;

    adco_cEnumElem mFrequency;
    int mStartPeriod;
    int mStartYear;
    int mNobs;
    int mLength;
    double* mValues;
    bool mInternalStore;
}; /* class ADPPMDL_API adco_TimeSeries */

//
// Parameter Class for moving data in and out of models
//

// add the sizeof(unsigned int) - 1 in case of a remainder in division
#define ADCO_EE_SIZE ( ( (sizeof(adco_cEnumeration*) + sizeof(unsigned int) - 1)/ sizeof(unsigned int) ) + 1 )

#include "stdio.h"
class ADPPMDL_API adco_CParam
{
protected:
    adco_cEnumElem TypeNum( const unsigned int tn_ ) const;

public:
    const adco_cEnumElem& VarType() const
    { return mVarType; }

    //Public Constructors
    adco_CParam(  ){};
    adco_CParam( int ival );
    adco_CParam( double dval );
    adco_CParam( const char* sval );
    adco_CParam( const adco_cEnumElem& eval );
    adco_CParam( adco_TimeSeries& tsval );
    adco_CParam( vecspec & tsval );
    adco_CParam( void* pval );
    // Copy Constructor and Assignment
    adco_CParam( const adco_CParam& cpval );
    adco_CParam& operator=( const adco_CParam& cpval );
    // Extract:  Caution - may throw conversion error
    operator int(void) const;
    operator double(void) const;
    // operator adco_CString(void) const;
    operator const char *(void) const;
    operator adco_cEnumElem(void) const;
    operator adco_TimeSeries&(void) const;
    operator vecspec&(void) const;
    operator void*(void) const;

private:
    adco_cEnumElem mVarType;
    union ADPPMDL_API uparamval {
        double dblval;
        int intval;
        const char* strval;
        const adco_cEnumeration* enumvall;
        unsigned int enumvali[ADCO_EE_SIZE];
        adco_TimeSeries* tsval;
        void* ptrval;
    uparamval() : dblval(0) {}
    } mParamVal;

}; /* class ADPPMDL_API adco_CParam */

//
// The Generic Model Class.  All Specific Model Types derived from this
//
class ADPPMDL_API CAdppmdl
{
public:
    // All Models have at least these 3 lists:
    // LISTS:  The list of available lists
    // INPUTS: The list of input parameters
    // RESULTS:The list of output values
    virtual const adco_cEnumeration& GetList( const char* listname = 0) = 0;

    // Both current setting of items in the INPUTS list
    // and results of the PrecCalc and Forecast calls
    // are retrieved with GetParam
    virtual adco_CParam GetParam( const adco_cEnumElem Parameter ) = 0;
    adco_CParam GetParam( const adco_cEnumeration& ParamList, const char* ParamName );
    virtual adco_CParam GetParam( const char* ParamName );

    // Items in the INPUTS list can be set with SetParam
    virtual void SetParam( const adco_cEnumElem Parameter, adco_CParam Value ) = 0;
    virtual void UnSetParam( const adco_cEnumElem Parameter ) = 0;

    // Set elements via "ParamName=Value, ..." string
    virtual void ParseParams( const char* ParamString ) = 0;

    // These actually run the models
    virtual void PreCalc() = 0;
    virtual void Forecast() = 0;
    virtual CAdppmdl* Duplicate() = 0;

    // CAdppmdl( void );
    virtual ~CAdppmdl() {};
}; /* class ADPPMDL_API CAdppmdl */

//
// The Model Factory Class.  Use this to create instances of CAdppmdl
//
class ADPPMDL_API CAdcoSys
{
protected:
    CAdcoSys();
    ~CAdcoSys();

public:
    // Create PPModel Objects for users
    virtual CAdppmdl& Adppmdl_factory( const adco_cEnumElem& model ) THROWS(adco_cError) = 0 ;
    virtual CAdppmdl& Adppmdl_factory( const char* modelname ) THROWS(adco_cError) = 0;
    virtual void Adppmdl_recycle( CAdppmdl& model ) = 0;

    // Control Generic Model defaults & behaviors
    virtual const adco_cEnumeration& ParamList() = 0;
    virtual const adco_cEnumeration& ModelList() = 0;
    virtual void SetParam( const adco_cEnumElem& Param, const adco_CParam& value ) = 0;
    virtual void SetParam( const char* ParamName, const adco_CParam& value ) = 0;
    virtual adco_CParam GetParam( const adco_cEnumElem& Param ) = 0;
    virtual adco_CParam GetParam( const char* ParamName ) = 0;
    virtual const adco_cEnumeration& ErrorList() = 0;
};
// Some of the models have a "TuneBack" parameter of type void*.  If you set
// this to the address of a adco_ppmodel_callback_func,  The model will call
// back this function at the beginning of each processing stage (Currently
// PreCalc(0) or Forecast(1)).  Why?  Some 3rd party cashflow generators allow
// for a prepayment model callback function pointer.  They are supposed to
// pass this to us so you can step in at each call to the prepayment model.

#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif
typedef void STDCALL adco_ppmodel_callback_func(
    int stage,
    void* adco_50_tuning_ptr,
    char* datafile_path,
    int* no_forecast_callback,
    void* ppmdl
    );

#ifdef WIN32
#pragma pack( pop, inside_adppmdlapi)
#endif

#endif
#ifndef ADPPMDLXTERN_H
#define ADPPMDLXTERN_H

EXTERN const adco_cEnumElem NULL_ELEM;
EXTERN const adco_cEnumeration* pNullList;

EXTERN const adco_cEnumeration* pErrorClass;

EXTERN const adco_cEnumElem ADCO_E_INFOONLY;
EXTERN const adco_cEnumElem ADCO_E_WARNING;
EXTERN const adco_cEnumElem ADCO_E_ERROR;

EXTERN const adco_cEnumeration* pAdco_PPModel_Types;
EXTERN const adco_cEnumElem POOLTYPE;
EXTERN const adco_cEnumElem LOANTYPE;
EXTERN const adco_cEnumElem UTILITYTYPE;

// Time Series Frequencies
// EXTERN const adco_cEnumeration* pAdco_Obs_Frequency;
EXTERN const adco_cEnumElem ADCO_MONTHLY; // Only one defined as of v5.0

// Parameter Types
EXTERN const adco_cEnumeration* pAdco_ParamTypes;
EXTERN const adco_cEnumElem ADCO_INTTYPE;
EXTERN const adco_cEnumElem ADCO_DBLTYPE;
EXTERN const adco_cEnumElem ADCO_STRTYPE;
EXTERN const adco_cEnumElem ADCO_ENUMTYPE;
EXTERN const adco_cEnumElem ADCO_TSTYPE;
EXTERN const adco_cEnumElem ADCO_UDPTRTYPE;

ADPPMDL_API CAdcoSys* adco_CreateSystem( void );
ADPPMDL_API void adco_DestroySystem( CAdcoSys* pSys );
ADPPMDL_API void addseasonality(adco_TimeSeries *pforecast, adco_TimeSeries *phistory, int firstoffset);

#ifdef _WIN32
#define  DEFAULTDATAFILEDIR     "c:\\adco\\ppmodel\\"
#define  DIRPATHSEPARATOR       '\\'
#else
#define  DEFAULTDATAFILEDIR     "./"
#define  DIRPATHSEPARATOR       '/'
#endif
const char DIRPATHSEPSTRING[2] = {DIRPATHSEPARATOR,0};

const int TUNETYPE_STRLEN = 32;

#endif

#endif
#endif // END_HEADER

#if 0 // START_EXTERNS
ofstream& ADCOFile = *new ofstream;
xstring tempString;
#endif // END_EXTERNS

#if 0 // START_CLASS
int valuation_period;
int loaded_proj_task_loop;
double arm_margin;
SmartArray <double> arm_wac_rates;

CAdcoSys * pAdcoSystem;

struct CHistData 
{
adco_TimeSeries * Rates;
};

map <string, CHistData> HistData;

inline void AddMonthToDate(int &y, int &m, const int offset)
{
if (abs(offset)<=12)
	m += offset;
else
	{
	y += (offset / 12);
	m += (offset % 12);
	}
		
if (m > 12) 
	{
	++y;
	m -= 12;
	}
else if (m < 1) 
	{
	--y;
	m += 12;
	}
}
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
valuation_period = -1;
loaded_proj_task_loop = -1;
pAdcoSystem = NULL;

arm_margin = 0.0;
if (arm_wac_rates.size() < max_maturity)
	arm_wac_rates.resize(max_maturity);
for (int i = 0; i < max_maturity; i++)
	arm_wac_rates[i] = 0.0;
#endif // END_CONSTRUCTOR

if (isMainModel)
	{
	loaded_proj_task_loop = proj_task_loop_num;

	log_screen.setf(ios::fixed);
	log_screen.precision(12);

	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	// set stoch_flag for rates loading
	stoch_flag = true;
	}

return 0.0;

}


//@@ END

//@@ START - asset_detail_rpt_flag
// Detail Report Flag                                                                                             
// Calculated Variable:ASSET_DETAIL_RPT_FLAG
//========================================================
int ADCO_ASSET_UDF::adco_asset_asset_detail_rpt_flag() {
//^^^


#line 1 "asset_detail_rpt_flag.ADCO_ASSET.for"
if (asset_detail_rpt_defn == YES
	&& (eq(asset_detail_rpt_cusip_id, "ALL")
	    || inlist(asset_id, asset_detail_rpt_cusip_id)))
	return YES;

return NO;

}


//@@ END

//@@ START - index
// Underlying  index                                                                                             
// Calculated Variable:INDEX
//========================================================
int ADCO_ASSET_UDF::adco_asset_index() {
//^^^


#line 1 "index.ADCO_ASSET.for"
if (arm_flag != YES)// Setup only for unified model which currently only supports arm's
	return -1;

if (asset_proj_defn != INTEX)
	{
	if (arm_reset_scen_yr <= 1.0)
	return static_cast <int> (PAR_TSY_1YR);
	
	if (arm_reset_scen_yr <= 3.0) //else if (1.0 < adj_reset_scen_yr <= 3.0)
	return static_cast <int> (PAR_TSY_3YR);
	
	//else 3 < adj_reset_scen_yr
    return static_cast <int> (PAR_TSY_5YR);
	}		
else //asset_proj_defn == INTEX
	{
	switch(arm_index_name)
    	{
         case LIBOR_1_MONTH: // Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_LIBOR_6M);                   
                 break;
         case LIBOR_3_MONTH: // Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_LIBOR_6M);                 
                 break;
         case LIBOR_6_MONTH:
                 return static_cast <int> (PAR_LIBOR_6M);                   
                 break;   
         case LIBOR_1_YEAR:
                 return static_cast <int> (PAR_LIBOR_1YR);                   
                 break; 
         case GOVT_3_MONTH:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_TSY_1YR);                   
                 break; 
         case GOVT_6_MONTH:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_TSY_1YR);                 
                 break; 
         case GOVT_1_YEAR:
                 return static_cast <int> (PAR_TSY_1YR);                    
                 break; 
         case GOVT_2_YEAR:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_TSY_3YR);                  
                 break; 
         case GOVT_3_YEAR:
                 return static_cast <int> (PAR_TSY_3YR);                   
                 break; 
         case GOVT_5_YEAR:
                 return static_cast <int> (PAR_TSY_5YR);                   
                 break;
         case GOVT_7_YEAR:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_TSY_5YR);                    
                 break;
         case GOVT_10_YEAR:// Adco does not support so remap to a valid adco index
                return static_cast <int> (PAR_TSY_5YR);                   
                 break;
         case GOVT_30_YEAR:// Adco does not support so remap to a valid adco index
                return static_cast <int> (PAR_TSY_5YR);               
                 break;
         case CD_6_MONTH:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (PAR_LIBOR_6M);                      
                 break;
         case COF_11_DIST:
                 return static_cast <int> (COFI_11D);                   
                 break;
         case GEN_COF:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (COFI_11D);                   
                 break;
         case BANK_PRIME:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (MTA_12);                 
                 break;
         case GEN_CONTRACT:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (MTA_12);                 
                 break;
         case MONEY_MKT:// Adco does not support so remap to a valid adco index
                 return static_cast <int> (MTA_12);                  
                 break;
         case UNKNOWN:// Adco does not support so remap to a valid adco index
                 return MTA_12;                  
                 break;
         default:
                 return -1;
    }
    }
return -1;

}


//@@ END

//@@ START - issuer
// Loan issuer                                                                                             
// Calculated Variable:ISSUER
//========================================================
int ADCO_ASSET_UDF::adco_asset_issuer() {
//^^^


#line 1 "issuer.ADCO_ASSET.for"
// This scalar is used for the unified model
if (prepmt_model_defn == MBS)
	{
	switch (mbs_collateral_defn)
		{
		case FNMA:
			return static_cast <int> (FANNIE_MAE);				
		case GNMA:
			return static_cast <int> (GINNIE_MAE);
		case GNMA2:
			return static_cast <int> (GINNIE_MAE);		
		case FHLMC:
			return static_cast <int> (FREDDIE_MAC);	
		case WHOLE_LOAN:
			if (subprime_defn == PRIME_COLLATERAL)
		    	return static_cast <int> (NONAGENCY_PRIME);
			//else
				return static_cast <int> (NONAGENCY_SUBPRIME);		
		case ALT_A:
			if (subprime_defn == PRIME_COLLATERAL)
		    	return static_cast <int> (NONAGENCY_PRIME);
			//else
				return static_cast <int> (NONAGENCY_SUBPRIME);		
		case RELO:
			if (subprime_defn == PRIME_COLLATERAL)
		    	return static_cast <int> (NONAGENCY_PRIME);
			//else
				return static_cast <int> (NONAGENCY_SUBPRIME);		
		default: 
		    return -1;
		}	
	}

if (prepmt_model_defn == ABS 
	&& abs_prepmt_defn == ARM_HOME_EQUITY_LOAN)
	{
	// HELOC's are generally considered Non agency loans
	if (subprime_defn == PRIME_COLLATERAL)
		return static_cast <int> (NONAGENCY_PRIME);
	//else
		return static_cast <int> (NONAGENCY_SUBPRIME);		
	}	
	
return -1;

}


//@@ END

//@@ START - loan_type
// Loan Type                                                                                             
// Calculated Variable:LOAN_TYPE
//========================================================
int ADCO_ASSET_UDF::adco_asset_loan_type() {
//^^^


#line 1 "loan_type.ADCO_ASSET.for"
if (prepmt_model_defn == MBS)
	{
	int ballflag;
	int armflag;
	
	// Determine if ARM
	if (mbs_prepmt_defn == ARM)
		armflag = 1;
	else
		armflag = 0;
	
	// Determine if Balloon mortgage
	if (balloon_term > 0)
		ballflag = 1;
	else
		ballflag = 0;
	
	switch (mbs_collateral_defn)
		{
		case FNMA:
			if (ballflag /* balloon */)
				{
				if (balloon_term >= 108)
					return static_cast <int> (FNMAB_10YR);
				else if (balloon_term >= 72)
					return static_cast <int> (FNMAB_7YR);
				else if (balloon_term >= 48)
					return static_cast <int> (FNMAB_5YR);
				//else 
					return static_cast <int> (FNMAB_3YR);
				}
			else // Not a Balloon Mortgage
				{
				if (armflag /* ARM */)
					{
					if (arm_reset_period >= 24 && arm_reset_period < 48)
						return static_cast <int> (FNMA_3YR);
					else if (arm_reset_period > 0 && arm_reset_period < 24)
						{
						if (adjustable_rate_defn == CONVERTIBLE)
							return static_cast <int> (FNMA_1YR_CONV);
						else if (adjustable_rate_defn == NON_CONVERTIBLE)
							return static_cast <int> (FNMA_1YR_NONC);
						}
					else // Map to balloon type with balloon term equal to reset
						{
						if (arm_reset_period >= 108)
							return static_cast <int> (FNMAB_10YR);
						else if (arm_reset_period >= 72)
							return static_cast <int> (FNMAB_7YR);
						else if (arm_reset_period >= 48)
							return static_cast <int> (FNMAB_5YR);
						}
					}

				else // Fixed Rate non-balloon mortgage
					{
					if (original_term >= 300)
						return static_cast <int> (FNMA_30YR);
					else if (original_term >= 216)
						return static_cast <int> (FNMA_20YR);
					else if (original_term >= 156)
						return static_cast <int> (FNMA_15YR);
					//else 
						return static_cast <int> (FNMA_10YR);
					}
				}
		case GNMA:
			if (ballflag /* Balloon */)
				{
				log_screen << "Error. Balloons for GNMA collateral not supported by Andrew Davidson. "
				           << " Asset ID=" << asset_id << MSG_ERROR;
				return -1;
				}
			else
				{
				if (armflag /* ARM */)
					{
					if (arm_reset_period > 0)
						return static_cast <int> (GNMA_1YR);
					else // Not supported, issue error message
						{
						log_screen << "Error. ARM reset period not supported by Andrew Davidson. "
						           << " Asset ID=" << asset_id << MSG_ERROR;
						return -1;
						}
			        }
				else // Fixed Rate mortgage
					{
					if (original_term >= 216)
						return static_cast <int> (GNMA_30YR);
					//else 
						return static_cast <int> (GNMA_15YR);
					}
				}
		case GNMA2:
			if (ballflag /* Balloon */)
				{
				log_screen << "Error. Balloons for GNMA2 collateral not supported by Andrew Davidson. "
				           << " Asset ID=" << asset_id << MSG_ERROR;
				return -1;
				}
			else
				{
				if (armflag /* ARM */)
					{
					if (arm_reset_period > 0)
						return static_cast <int> (GNMA_1YR);
					else // Not supported, issue error message
						{
						log_screen << "Error. ARM reset period not supported by Andrew Davidson. "
						           << " Asset ID=" << asset_id << MSG_ERROR;
						return -1;
						}
					}
				else // Fixed Rate mortgage
					{
					if (original_term >= 216)
						return static_cast <int> (GNMA2_30YR);
					//else 
						return static_cast <int> (GNMA2_15YR);
					}
				}
		case FHLMC:
			if (ballflag  /* Balloon */)
				{
				if (balloon_term >= 108)
					return static_cast <int> (FRDGB_10YR);
				else if (balloon_term >= 72)
					return static_cast <int> (FRDGB_7YR);
				else if (balloon_term >= 48)
					return static_cast <int> (FRDGB_5YR);
				//else 
					return static_cast <int> (FRDGB_3YR);
				}
			else // Not a Balloon Mortgage
				{
				if (armflag /* ARM */)
					{
					if (arm_reset_period >= 24 && arm_reset_period < 48)
						return static_cast <int> (FRDH_3YR);
					else if (arm_reset_period > 0 && arm_reset_period < 24)
						{
						if (adjustable_rate_defn == CONVERTIBLE)
							return static_cast <int> (FRDH_1YR_CONV);
						else if (adjustable_rate_defn == NON_CONVERTIBLE)
							return static_cast <int> (FRDH_1YR_NONC);
						}
					else // Map to balloon type with balloon term equal to reset
						{
						if (arm_reset_period >= 108)
						    return static_cast <int> (FRDGB_10YR);
						else if (arm_reset_period >= 72)
						    return static_cast <int> (FRDGB_7YR);
						else if (arm_reset_period >= 48)
							return static_cast <int> (FRDGB_5YR);
						}
					}
				else // Fixed Rate non-balloon mortgage
					{	
					if (original_term >= 300)
						return static_cast <int> (FRDG_30YR);
					else if (original_term >= 216)
						return static_cast <int> (FRDG_20YR);
					else if (original_term >= 156)
						return static_cast <int> (FRDG_15YR);
					//else 
						return static_cast <int> (FRDG_10YR);
					}
				}
		case WHOLE_LOAN:
			if (ballflag /* Balloon */)
				{
				if (balloon_term >= 72)
					return static_cast <int> (WHOLEB_7YR);
				//else 
					return static_cast <int> (WHOLEB_5YR);
				}
			else // Not a Balloon Mortgage
				{
				if (original_term >= 216)
					return static_cast <int> (WHOLE_30YR);
				//else 
					return static_cast <int> (WHOLE_15YR);
				}
		case RELO:
			if (ballflag /* Balloon */)
				{
				log_screen << "Error. Balloons for RELO collateral not supportd by Andrew Davidson. "
				           << "Asset ID=" << asset_id << MSG_ERROR;
				return -1;
				}
			else // Not Balloon Mortgage
				{
                if (original_term >= 216)
					return static_cast <int> (RELO_30YR);
				//else 
					return static_cast <int> (RELO_15YR);
				}
		case ALT_A:
			if (ballflag /*Balloon */)
				{
				log_screen << "Error. Balloons for ALT A collateral not supportd by Andrew Davidson. "
				           << " Asset ID=" << asset_id << MSG_ERROR;
				return -1;	
				}
			else // Not Balloon Mortgage
				{
				if (original_term >= 216)
					return static_cast <int> (ALT_A_30YR);						
				//else
					return static_cast <int> (ALT_A_15YR);
				}
		case COFI: //COFI
			if (ballflag /*Balloon */)
				{
				log_screen << "Error. Balloons for COFI collateral not supportd by Andrew Davidson. "
				           << " Asset ID=" << asset_id << MSG_ERROR;
				return -1;	
				}
			else // Not Balloon Mortgage
				{
				if (!armflag /* Not ARM */)
					{
					log_screen << "Error. Fixed COFI loans not supported by Andrew Davidson. "
					           << " Asset ID=" << asset_id << MSG_ERROR;
					return -1;	
					}
				else // ARM Non Balloon Mortgage
					return static_cast <int> (D11_COFI);
				}

		default: 
			return -1;
		} // end switch
	}

else // prepmt_model_defn == ABS
	{
	switch (abs_prepmt_defn)
		{
		case AUTO:
			return static_cast <int> (ADCO_AUTO_STRAT);

		case FIXED_HOME_EQUITY_LOAN:
			if (hel_issuer == AFC)
				return static_cast <int> (ADCO_HEL_AFC);

			if (hel_issuer == ADV)
				return static_cast <int> (ADCO_HEL_ADV);

			if (hel_issuer == EC)
				return static_cast <int> (ADCO_HEL_EC);

			if (hel_issuer == GE)
				return static_cast <int> (ADCO_HEL_GE);

			if (hel_issuer == MON)
				return static_cast <int> (ADCO_HEL_MON);

			if (hel_issuer == UFC)
				return static_cast <int> (ADCO_HEL_UFC);

			if (hel_issuer == INM)
				return static_cast <int> (ADCO_HEL_INM);
				
			if (hel_issuer == CON)
				return static_cast <int> (ADCO_HEL_CON);

			return static_cast <int> (ADCO_HEL_UNK);

		case ARM_HOME_EQUITY_LOAN: // ARM HEL
			if (arm_reset_period <= 0)
				return static_cast <int> (ADCO_ABS_ARMHEL_UNKNOWN);

			if (arm_reset_period > 0 && arm_reset_period <= 9)
				return static_cast <int> (ADCO_ABS_ARMHEL_6);

			if (arm_reset_period > 9 && arm_reset_period <= 18)
				return static_cast <int> (ADCO_ABS_ARMHEL_12);

			if (arm_reset_period > 18 && arm_reset_period <= 30)
				return static_cast <int> (ADCO_ABS_ARMHEL_24);

			if (arm_reset_period > 30 && arm_reset_period <= 36)
				return static_cast <int> (ADCO_ABS_ARMHEL_36);

			return static_cast <int> (arm_reset_period);

		case MANUFACTURED_HOUSING:
			// there are no single "types" for manuhouse, but a combination of
			// loan characteristics
			return -1; 

		default:
			return -1;
		} // end switch statement
	}

return -1;

}


//@@ END

//@@ START - orig_proj_start_mth
// Original Projection Start Mth                                                                                             
// Calculated Variable:ORIG_PROJ_START_MTH
//========================================================
int ADCO_ASSET_UDF::adco_asset_orig_proj_start_mth() {
//^^^


#line 1 "orig_proj_start_mth.ADCO_ASSET.for"
int proj_mth = get_mth_from_date(proj_date);

if (proj_mth == 12)
	return 1;
	
return proj_mth + 1;

}


//@@ END

//@@ START - orig_proj_start_yr
// Original Projection Start Yr                                                                                             
// Calculated Variable:ORIG_PROJ_START_YR
//========================================================
int ADCO_ASSET_UDF::adco_asset_orig_proj_start_yr() {
//^^^


#line 1 "orig_proj_start_yr.ADCO_ASSET.for"
int proj_mth = get_mth_from_date(proj_date);

if (proj_mth == 12)
	return get_yr_from_date(proj_date) + 1;
	
return get_yr_from_date(proj_date);

}


//@@ END

//@@ START - output_file
// Output File                                                                                             
// Calculated Variable:OUTPUT_FILE
//========================================================
xstring ADCO_ASSET_UDF::adco_asset_output_file() {
//^^^


#line 1 "output_file.ADCO_ASSET.for"
return get_file_name(output_location());

}


//@@ END

//@@ START - output_path
// Output Path                                                                                             
// Calculated Variable:OUTPUT_PATH
//========================================================
xstring ADCO_ASSET_UDF::adco_asset_output_path() {
//^^^


#line 1 "output_path.ADCO_ASSET.for"
return get_file_path(output_location());

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring ADCO_ASSET_UDF::adco_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.ADCO_ASSET.for"
// Always use the original projection date for the time step experience projection
if (time_step_flag && !valn_flag)
	return proj_date;

return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int ADCO_ASSET_UDF::adco_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.ADCO_ASSET.for"
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
int ADCO_ASSET_UDF::adco_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.ADCO_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int ADCO_ASSET_UDF::adco_asset_start_period() {
//^^^


#line 1 "start_period.ADCO_ASSET.for"
return max(0, commencement_period);

}


//@@ END


#line 1 "abs_auto_setup.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::abs_auto_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast)
{
int month = 0;
const adco_cEnumeration& SysParamList = pAdcoSystem->ParamList();
const adco_cEnumElem DirParam = SysParamList.element("DATAFILEDIR");
pAdcoSystem->SetParam(DirParam, ADDataFileDir);

//Get List of Known Models
const adco_cEnumeration& ModelList = pAdcoSystem->ModelList();

//Make Enum Element for MBS Fixed Model type (only do name lookup once)
const adco_cEnumElem AbsAutoMdlType = ModelList.element("ABSAUTO");

try {
	// Get an ABS Auto prepayment model
	CAdppmdl& Mdl = pAdcoSystem->Adppmdl_factory(AbsAutoMdlType);

	const adco_cEnumeration& AbsAutoInputs = Mdl.GetList("INPUTS");
	const adco_cEnumeration& AbsAutoResults = Mdl.GetList("RESULTS");

	// Collateral Description Inputs - required
	adco_cEnumElem AbsAutoType = AbsAutoInputs.element("Type");
    const adco_cEnumeration& AbsAutoTypes = Mdl.GetList(AbsAutoType.classification().name());

	switch (ad_loan_type)
		{
		case ADCO_AUTO_ALL:
			Mdl.SetParam(AbsAutoType, AbsAutoTypes.element("All") );
			break;
		case ADCO_AUTO_STRAT:
			Mdl.SetParam(AbsAutoType, AbsAutoTypes.element("Strat") );
			break;
		default:
			throw FatalError("ADCO Model Failure: Unknown Auto Type.");
			break;
		}	
	
	Mdl.SetParam(AbsAutoInputs.element("WAC"), (double) coupon);
	Mdl.SetParam(AbsAutoInputs.element("Age"), (int) age);
	
	// Initial State Inputs - required
	Mdl.SetParam(AbsAutoInputs.element("FirstForecastMonth"), histmth);
	Mdl.SetParam(AbsAutoInputs.element("FirstForecastYear"), histyr);
	Mdl.SetParam(AbsAutoInputs.element("RemainingTerm"), max_maturity);
	
    //***These parameters are in the ADCO interface, but will not be used. ***
	// Miscellaneous parameters that are not needed
	//adco_cEnumElem FixedDumpFile = FixedResults.element("DUMPFILE")
	//****************************************************************************

	try	{Mdl.PreCalc();}

	catch(adco_cError &error_detail)
		{
		error_processing(error_detail.message());
		return;
		}

	try {Mdl.Forecast();}

	catch(adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return ;
		}

	adco_CParam SMMrslt = Mdl.GetParam(AbsAutoResults.element("SMM"));
	adco_TimeSeries* SMM = &(adco_TimeSeries&) SMMrslt;

	int tempidx = SMM->GetIdx(histyr, histmth);	
	double* SMMptr = SMM->Values() + tempidx;

	assert(sizeof(smm_forecast) >= max_maturity);

	for (month = 0; month < max_maturity && month < SMM->Length() + tempidx; month++)
  		smm_forecast[month] = SMMptr[month];

	if (process_adco_detail(t))
		{
		string version = Mdl.GetParam(AbsAutoResults.element("VERSION"));
		xstring loan_type = "";
		int pvcalc = 0;
		int nycalc = 0;
		int mvcalc = 0;
	
		if (prepmt_forecast_defn != EXPERIENCE)
			pvcalc = 1;
	
		if (prepmt_forecast_defn == MARKET_VALUE)
			mvcalc = 1;
	
		if (prepmt_forecast_defn == NET_YIELD)
			nycalc = 1;
	
		switch (ad_loan_type)
			{
			case ADCO_AUTO_ALL:
				loan_type = "Auto All";
				break;
			case ADCO_AUTO_STRAT:
				loan_type = "Auto Strat";
				break;
			default:
				loan_type = "Undefined";
				break;
			}
	
		ADCOFile << endl
				 << "ADCO Prepayment Detail" << endl
				 << "Asset ID," << asset_id << endl
				 << "Category," << category_id << endl
				 << "Model Type,ABS Auto Loan" << endl
				 << "ADCO Version," << version << endl
				 << "ProjTaskLoop," << proj_task_loop_num << endl
				 << "CalYr," << cal_yr << endl
				 << "CalMth," << cal_mth << endl
				 << "PVCalc," << pvcalc << endl
				 << "NYCalc," << nycalc << endl
				 << "MVCalc," << mvcalc<< endl
				 << "ShftdYldCv," << shift_defn << endl
				 << "LoanType," << loan_type << endl
				 << "Age," << age << endl
				 << "Remterm," << max_maturity << endl
				 << "HistYr," << histyr << endl
				 << "HistMth," << histmth << endl
				 << "Offset," << offset << endl
				 << "FMth,Coupon,SmmForecast" << endl;
	
		for (month = 0; month < max_maturity; month++)
			ADCOFile << month << ","
					 << coupon << ","
					 << smm_forecast[month] << endl;
		} //endif detail

	pAdcoSystem->Adppmdl_recycle(Mdl);
	} // Global Try

catch (adco_cError &error_detail) 
	{
	error_processing(error_detail.message());
	return; 
	}
}



#line 1 "abs_hel_setup.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::abs_hel_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast)
{
int term_type = 0;
int msdmth = orig_proj_start_mth;
int msdyr = orig_proj_start_yr;
double origspread = 0.0;
double cur_mtg_cpn = 0.0;
double spread = 0.0;
double twoyr_forecast[curr_cpn_vecsize];
double tenyr_forecast[curr_cpn_vecsize];
char * loan_type = "";

memset(twoyr_forecast, 0, curr_cpn_vecsize * sizeof(double));
memset(tenyr_forecast, 0, curr_cpn_vecsize * sizeof(double));

assert(pAdcoSystem != NULL);

if (original_term > 240) // term per Intex instructions re from Eknath at ADCO
	term_type = ADCO_ABS_30YR;
else if(original_term > 120)
	term_type = ADCO_ABS_15YR;
else 	
    term_type = ADCO_ABS_5YR;

const adco_cEnumeration& SysParamList = pAdcoSystem->ParamList();
const adco_cEnumElem DirParam = SysParamList.element("DATAFILEDIR");

pAdcoSystem->SetParam(DirParam, ADDataFileDir);

const adco_cEnumeration& ModelList = pAdcoSystem->ModelList();
const adco_cEnumElem AbsHelMdlType = ModelList.element("ABSHEL");
	
try 
	{
	// Setup a ABS HEL prepayment model
	CAdppmdl& Mdl = pAdcoSystem->Adppmdl_factory(AbsHelMdlType);

	const adco_cEnumeration& AbsHelInputs = Mdl.GetList("INPUTS");
	const adco_cEnumeration& AbsHelResults = Mdl.GetList("RESULTS");
	const adco_cEnumeration& AbsHelCCYHistMap = Mdl.GetList("CCYHISTMAP");
	const adco_cEnumeration& AbsHelCCYTypeMap = Mdl.GetList("CCYTYPEMAP");
	const adco_cEnumeration& AbsHelHPITypeMap = Mdl.GetList("HPITYPEMAP");
	
    // determine loan type
    switch (term_type)
		{
		case ADCO_ABS_30YR:
			loan_type = "25Yr-30Yr";
			break;
		case ADCO_ABS_15YR:
			loan_type = "15Yr-20Yr";
			break;
		case ADCO_ABS_5YR:
			loan_type = "5Yr-10Yr";
			break;
		default:
			loan_type = "Undefined";
			break;
		}
		
	// Collateral Description Inputs & Initial State Inputs- required	
	Mdl.SetParam(AbsHelInputs.element("Term"), loan_type);
	Mdl.SetParam(AbsHelInputs.element("WAC"), (double) coupon);
	Mdl.SetParam(AbsHelInputs.element("RemainingTerm"), (int) remaining_term);
	Mdl.SetParam(AbsHelInputs.element("Age"), (int) age );
	Mdl.SetParam(AbsHelInputs.element("FirstForecastYear"), (int) histyr);
	Mdl.SetParam(AbsHelInputs.element("FirstForecastMonth"), (int) histmth);
	
	// Other advanced inputs - optional
	
	// face value is set to par value of loan at issue 
	Mdl.SetParam(AbsHelInputs.element("Orig_Face"), (double) original_face);
	Mdl.SetParam(AbsHelInputs.element("Orig_LTV"), (double) original_ltv);
	
    //***These parameters are in the ADCO interface, but will not be used. ***
	
	// Tuning Inputs - optional
    // Andrew Davidson strongly recommends that their File based tuning only be utilized,  
    // and that the end user should not concern themselves with passing tuning parameters 
    // to the interface. However, if the user wishes to pass their own tuning parameters 
    // the below code can be uncommented and used. It should be noted that the second
    // parameter being passed to "SetParam" will need to be created as MoSes variables.

	// Sensitivity Tuning Factors -- affects only Forecast() (only future projection)	
	//Mdl.SetParam(AbsHelInputs.element("TuningStartMonth"), (int) tuning_start_mth);
	//Mdl.SetParam(AbsHelInputs.element("TuningStartYear"), (int) tuning_start_yr);
	//Mdl.SetParam(AbsHelInputs.element("TuningEndMonth"), (int) tuning_end_mth);
	//Mdl.SetParam(AbsHelInputs.element("TuningEndYear"), (int) tuning_end_yr);
    //Mdl.SetParam(AbsHelInputs.element("TuningRampMonths"), (int) tuning_ramp_months);
    //Mdl.SetParam(AbsHelInputs.element("TuningFadeMonths"), (int) tuning_fade_months);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneScale"), (double) smm_tune_scale);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneBurnout"), (double) smm_tune_burnout);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneLag"), (double) smm_tune_lag);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneSlide"), (double) smm_tune_slide);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneTurnOver"), (double) smm_tune_turn_over);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneRefi"), (double) smm_tune_refi);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneCashout"), (double) smm_tune_cashout);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneCure"), (double) smm_tune_cure);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneAge"), (double) smm_tune_age);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneSATO"), (double) smm_tune_sato);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneCATO"), (double) smm_tune_cato);
	//Mdl.SetParam(AbsHelInputs.element("Cashout_RM"), (double) cashout_rm);
	//Mdl.SetParam(AbsHelInputs.element("Cure_RM"), (double) cure_rm);
	//Mdl.SetParam(AbsHelInputs.element("Refi_RM"), (double) refi_rm);
	//Mdl.SetParam(AbsHelInputs.element("Turnover_RM"), (double) turnover_rm);
	//Mdl.SetParam(AbsHelInputs.element("Psi0"), (double) (double) psi_0);
	//Mdl.SetParam(AbsHelInputs.element("PsiT"), (double) (double) psi_T);
		
	// Model Tuning Factors -- affects both PreCalc()and Forecast() 
	// (History and future projection) These are obsolete.
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneScaleModel"), (double) smm_tune_scale_model);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneBurnoutModel"), (double) smm_tune_burnout_model);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneLagModel"), (double) smm_tune_lag_model);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneSlideModel"), (double) smm_tune_slide_model);
    //Mdl.SetParam(AbsHelInputs.element("SmmTuneTurnOverModel"), (double) smm_tune_turn_over_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneRefiModel"), (double) smm_tune_refi_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneCashoutModel"), (double) smm_tune_cashout_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneCureModel"), (double) smm_tune_cure_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneAgeModel"), (double) smm_tune_age_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneSATOModel"), (double) smm_tune_sato_model);
	//Mdl.SetParam(AbsHelInputs.element("SmmTuneCATOModel"), (double) smm_tune_cato_model);

    // Old Names for FirstForecastYear and FirstForecastMonth. These are obsolete.
	//adco_cEnumElem AbsHelAsOfYear = AbsHelInputs.element("AsOfYear");
	//adco_cEnumElem AbsHelAsOfMonth = AbsHelInputs.element("AsOfMonth");
	
	// These input parameters are not needed since the US Library has already handled projection 
    // length and valuation period offset. 
    // adco_cEnumElem AbsHelForecastMonths = AbsHelInputs.element("ForecastMonths");
	// adco_cEnumElem AbsHelForecastOffset = AbsHelInputs.element("ForecastOffset");
	
	// Deprecated
    //adco_cEnumElem AbsHelHPIForecast = AbsHelInputs.element("HPIForecast"); 
	//adco_cEnumElem AbsHelHPIRvsnval = AbsHelInputs.element("HPIRvsnVal");
	//adco_cEnumElem AbsHelOrigSprd = AbsHelInputs.element("Original_Spread");
	//adco_cEnumElem AbsHelHPIRvsnMnths = AbsHelInputs.element("HPI_Rvsn_Mnths");
    //adco_cEnumElem AbsHelOrigVal = AbsHelInputs.element("Orig_Val");
    //adco_cEnumElem AbsHelCurVal = AbsHelInputs.element("Cur_Val");
    //adco_cEnumElem AbsHelOrigYear = AbsHelInputs.element("OriginationYear");
    //adco_cEnumElem AbsHelOrigMonth = AbsHelInputs.element("OriginationMonth");
    //adco_cEnumElem AbsHelOrigState = AbsHelInputs.element("State");
    //const adco_cEnumeration& AbsHelStates = Mdl.GetList(AbsHelOrigState.classification().name());

	// Forecast Results that are not needed
	//adco_cEnumElem AbsHelMaxLag = AbsHelResults.element("MaxLag");
	//adco_cEnumElem AbsHelForecastCount = AbsHelResults.element("ForecastCount");
	//adco_cEnumElem AbsHelModel = AbsHelResults.element("Model");
    //adco_cEnumElem AbsHelLicense = AbsHelResults

	// Miscellaneous parameters that are not needed
	//adco_cEnumElem AbsHelDealID = AbsHelInputs.element("DealID");
	//adco_cEnumElem AbsHelPoolID = AbsHelInputs.element("PoolID");
	//adco_cEnumElem AbsHelZeroVectorsFlag = AbsHelInputs.element("ZeroVectorsFlag");
	//adco_cEnumElem AbsHelTuneString = AbsHelInputs.element("TuneString");
    //adco_cEnumElem AbsHelTuningShelf = AbsHelInputs.element("TuningShelf");
	//adco_cEnumElem AbsHelTuningShelf1 = AbsHelInputs.element("TuningShelf1");
	//adco_cEnumElem AbsHelTuningShelf2 = AbsHelInputs.element("TuningShelf2");
	//adco_cEnumElem AbsHelTuningShelf3 = AbsHelInputs.element("TuningShelf3");
	//adco_cEnumElem AbsHelTuningShelf4 = AbsHelInputs.element("TuningShelf4");	
	//****************************************************************************

	// Get Coupon History
	adco_TimeSeries * myCCYHist = NULL;

	get_history(t, loan_type, Mdl, myCCYHist, AbsHelResults,
			    histmth, histyr, msdyr, msdmth);

	adco_CParam CCYHistP(*myCCYHist);
	Mdl.SetParam(AbsHelInputs.element("CCYHistory"), CCYHistP);

	// Calculate spread at origination
	int CCYidx = myCCYHist->GetRawIdx(origination_yr, origination_mth);
	double origspread = coupon - myCCYHist->Values()[CCYidx < 0 ? 0 : CCYidx];

	adco_CParam OrigSpreadP(origspread);
	Mdl.SetParam(AbsHelInputs.element("Original_Spread"), OrigSpreadP);

	// Capture current mortgage rate from history 
	int idx = myCCYHist->GetIdx(histyr, histmth);
	cur_mtg_cpn = myCCYHist->Values()[idx - 1];

	try {Mdl.PreCalc();}
		 
	catch(adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return;
		}

	// Get the CCY Forecast
	const adco_cEnumElem& eeCCYType = AbsHelCCYTypeMap.element(loan_type).classification();

	// Forecast the CCY rate
	adco_TimeSeries * myCCYForecast = NULL;

	ccy_rate_forecast(t, offset, histyr, histmth, eeCCYType,
	                  cur_mtg_cpn, myCCYForecast, twoyr_forecast, tenyr_forecast, spread);

	// Parameterize the ABSHel Model with the CCY Forecast
	adco_CParam CCYfcst(*myCCYForecast);
	Mdl.SetParam(AbsHelInputs.element("CCYForecast"), CCYfcst);

	try {Mdl.Forecast();}

	catch(adco_cError &error_detail)
		{
		error_processing(error_detail.message());
		return;
		}

	adco_CParam SMMrslt = Mdl.GetParam(AbsHelResults.element("SMM"));
	adco_TimeSeries* SMM = &(adco_TimeSeries&) SMMrslt;

	int tempidx = SMM->GetIdx(histyr, histmth);	 //This offset is often zero, but could be non-zero.
	double* SMMptr = SMM->Values() + tempidx;

	int month = 0; //, i = 0, idx = 0, error = 0;
	assert(sizeof(smm_forecast) >= max_maturity);
	
    // Save to SMM array
	for (month = 0; month < max_maturity && month < SMM->Length() - tempidx; month++)
  		smm_forecast[month] = SMMptr[month];
	
	// Setup cashout incentive SMM vector
	SMMrslt = Mdl.GetParam(AbsHelResults.element("CashoutSMM"));
	adco_TimeSeries* CashoutSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = CashoutSMM->GetIdx(histyr, histmth);	 
	double* CashoutSMMptr = CashoutSMM->Values() + tempidx;
	    
	for (month = 0; month < max_maturity && month < CashoutSMM->Length() - tempidx; month++)
  	   smm_cashout_forecast[month] = CashoutSMMptr[month];
        
    // Setup credit cure SMM vector
	SMMrslt = Mdl.GetParam(AbsHelResults.element("CreditCureSMM"));
	adco_TimeSeries* CreditCureSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = CreditCureSMM->GetIdx(histyr, histmth);	 
	double* CreditCureSMMptr = CreditCureSMM->Values() + tempidx;
	
	for (month = 0; month < max_maturity && month < CreditCureSMM->Length() - tempidx; month++)
  	   smm_credit_cure_forecast[month] = CreditCureSMMptr[month];

	// Setup refinance incentive SMM vector
	SMMrslt = Mdl.GetParam(AbsHelResults.element("RefiSMM"));
	adco_TimeSeries* RefiSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = RefiSMM->GetIdx(histyr, histmth);	 
	double* RefiSMMptr = RefiSMM->Values() + tempidx;
	    
	for (month = 0; month < max_maturity && month < RefiSMM->Length() - tempidx; month++)
  	   smm_refi_forecast[month] = RefiSMMptr[month];
        
    // Setup Turnover SMM vector
	SMMrslt = Mdl.GetParam(AbsHelResults.element("TurnoverSMM"));
	adco_TimeSeries* TurnoverSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = TurnoverSMM->GetIdx(histyr, histmth);	 
	double* TurnoverSMMptr = TurnoverSMM->Values() + tempidx;
	
	for (month = 0; month < max_maturity && month < TurnoverSMM->Length() - tempidx; month++)
  	   smm_turnover_forecast[month] = TurnoverSMMptr[month];
	
	if (process_adco_detail(t))
		{
		string version = Mdl.GetParam(AbsHelResults.element("VERSION"));
		
		// Setup HPI Forecast vector
		adco_CParam HPIFcst = Mdl.GetParam(AbsHelInputs.element("HPIForecast"));
		adco_TimeSeries* HPIFcstTS = &(adco_TimeSeries&) HPIFcst;
		tempidx = HPIFcstTS->GetIdx(histyr, histmth);	 
		double* HPIFcstptr = HPIFcstTS->Values() + tempidx;
		
		char * loan_type, *zterm_type;
		int pvcalc = 0;
		int nycalc = 0;
		int mvcalc = 0;

		adco_CParam CCYfcst = Mdl.GetParam(AbsHelInputs.element("CCYForecast"));
		adco_TimeSeries* CCY = &(adco_TimeSeries&) CCYfcst;
	
		int CCYidx = CCY->GetIdx(histyr, histmth);
	
		if (prepmt_forecast_defn != EXPERIENCE)
			pvcalc = 1;
	
		if (prepmt_forecast_defn == MARKET_VALUE)
			mvcalc = 1;
	
		if (prepmt_forecast_defn == NET_YIELD)
			nycalc = 1;
	
		switch (term_type)
			{
			case ADCO_ABS_30YR:
				zterm_type = "30 Year";
				break;
			case ADCO_ABS_15YR:
				zterm_type = "15 Year";
				break;
			case ADCO_ABS_5YR:
				zterm_type = "5 Year";
				break;	
			default:
				zterm_type = "Undefined";
				break;
			}
	
		switch (ad_loan_type)
			{
			case ADCO_HEL_AFC:
				loan_type = "HEL AFC";
				break;
			case ADCO_HEL_ADV:
				loan_type = "HEL ADV";
				break;
			case ADCO_HEL_EC:
				loan_type = "HEL EC";
				break;
			case ADCO_HEL_GE:
				loan_type = "HEL GE";
				break;
			case ADCO_HEL_MON:
				loan_type = "HEL MON";
				break;
			case ADCO_HEL_UFC:
				loan_type = "HEL UFC";
				break;
			case ADCO_HEL_INM:
				loan_type = "HEL INM";
				break;
			case ADCO_HEL_CON:
				loan_type = "HEL CON";
				break;
			case ADCO_HEL_UNK:
				loan_type = "HEL UNK";
				break;
			default:
				loan_type = "Undefined";
				break;
			}
	    
		ADCOFile << endl
				 << "ADCO Prepayment Detail" << endl
				 << "Asset ID," << asset_id << endl
				 << "Category," << category_id << endl
				 << "Model Type,ABS Fixed Home Equity Loan" << endl
				 << "ADCO Version," << version << endl
				 << "ProjTaskLoop," << proj_task_loop_num << endl
				 << "CalYr," << cal_yr << endl
				 << "CalMth," << cal_mth << endl
				 << "PVCalc," << pvcalc << endl
				 << "NYCalc," << nycalc << endl
				 << "MVCalc," << mvcalc << endl
				 << "ShftdYldCv," << shift_defn << endl
				 << "LoanType," << loan_type << endl
				 << "TermType," << zterm_type << endl
				 << "Age," << age << endl
				 << "RemTerm," << remaining_term << endl
				 << "Spread," << spread << endl
				 << "OrigYear," << origination_yr << endl
				 << "OrigMonth," << origination_mth << endl
				 << "OrigSpread," << origspread << endl
				 << "HistYr," << histyr << endl
				 << "HistMth," << histmth << endl
				 << "Offset," << offset << endl
				 << "FMth,Coupon,2YrRate,10YrRate,MtgCpn,HPIForecast,SmmForecast,SmmCashForecast,SmmCureForecast,SmmRefiForecast,SmmTurnForecast" << endl;
	
		for (month = 0; month < remaining_term; month++)
			{
			double dCCY;
			int idx = CCYidx + month;
			
			if (idx >= 0)
				dCCY = CCY->Values()[idx];
			else 
				dCCY = 0.0;

			ADCOFile << month << ","
					 << coupon << ","
					 << twoyr_forecast[month] << ","
					 << tenyr_forecast[month] << ","
					 << dCCY << ","
					 << HPIFcstptr[month] << ","
					 << smm_forecast[month] << ","
					 << smm_cashout_forecast[month] << ","
					 << smm_credit_cure_forecast[month] << ","
					 << smm_refi_forecast[month] << ","
					 << smm_turnover_forecast[month] << endl;
			} // endfor
		} //endif detail
	
	// Recycle the model
	pAdcoSystem->Adppmdl_recycle(Mdl);
	} // Global Try

catch (adco_cError &error_detail)
	{
	error_processing(error_detail.message());
	return;
	}
}



#line 1 "abs_mh_setup.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::abs_mh_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast)
{
int term_type = 0;
int msdmth = orig_proj_start_mth;
int msdyr = orig_proj_start_yr;
double cur_mtg_cpn = 0.0;
double spread = 0.0;
double twoyr_forecast[curr_cpn_vecsize];
double tenyr_forecast[curr_cpn_vecsize];
char * loan_type = "";

memset(twoyr_forecast, 0, curr_cpn_vecsize * sizeof(double));
memset(tenyr_forecast, 0, curr_cpn_vecsize * sizeof(double));

assert(pAdcoSystem != NULL);

if (original_term >= 240) // term per Intex instructions re from Eknath at ADCO
	term_type = ADCO_ABS_30YR;
else
	term_type = ADCO_ABS_15YR;

switch (term_type)
	{
	case ADCO_ABS_30YR:
		loan_type = "30";
		break;
	case ADCO_ABS_15YR:
		loan_type = "15";
		break;
	default:
		loan_type = "Undefined";
		break;
	}

const adco_cEnumeration& SysParamList = pAdcoSystem->ParamList();
const adco_cEnumElem DirParam = SysParamList.element("DATAFILEDIR");
pAdcoSystem->SetParam(DirParam, ADDataFileDir);

const adco_cEnumeration& ModelList = pAdcoSystem->ModelList();

const adco_cEnumElem AbsMHMdlType = ModelList.element("ABSMH");

try 
	{
	CAdppmdl& Mdl = pAdcoSystem->Adppmdl_factory(AbsMHMdlType);

	const adco_cEnumeration& AbsMHInputs = Mdl.GetList("INPUTS");
	const adco_cEnumeration& AbsMHResults = Mdl.GetList("RESULTS");
	const adco_cEnumeration& AbsMHCCYHistMap = Mdl.GetList("CCYHISTMAP");
	const adco_cEnumeration& AbsMHCCYTypeMap = Mdl.GetList("CCYTYPEMAP");

	// Collateral Description Inputs - required
	Mdl.SetParam(AbsMHInputs.element("Term"), loan_type);
	Mdl.SetParam(AbsMHInputs.element("WAC"), (double) coupon);
	Mdl.SetParam(AbsMHInputs.element("RemainingTerm"), max_maturity);

	// Initial State Inputs - required
	Mdl.SetParam(AbsMHInputs.element("Age"), (int) age);
	Mdl.SetParam(AbsMHInputs.element("FirstForecastYear"), (int) histyr);
	Mdl.SetParam(AbsMHInputs.element("FirstForecastMonth"), (int) histmth);
    
    // Setup use type
    adco_cEnumElem AbsMHUse = AbsMHInputs.element("Use");
	const adco_cEnumeration& AbsMHUses = Mdl.GetList(AbsMHUse.classification().name());
	
	switch (abs_mh_defn)
			{
			case RENTAL:
				Mdl.SetParam(AbsMHUse, AbsMHUses.element("Rental"));
				break;
			case TRAILER:
				Mdl.SetParam(AbsMHUse, AbsMHUses.element("Trailer"));
				break;
			case OWNER:
				Mdl.SetParam(AbsMHUse, AbsMHUses.element("Owner"));
				break;
			default:
					Mdl.SetParam(AbsMHUse, AbsMHUses.element("Unknown"));
				break;
			}
	
	//Setup Vintage type				
	adco_cEnumElem AbsMHVintage = AbsMHInputs.element("Vintage");
	const adco_cEnumeration& AbsMHVintages = Mdl.GetList(AbsMHVintage.classification().name());
	
	switch (abs_mh_vintage_defn)
			{
			case NEW:
				Mdl.SetParam(AbsMHVintage, AbsMHVintages.element("New"));
				break;
			case OLD:
				Mdl.SetParam(AbsMHVintage, AbsMHVintages.element("Old"));
				break;
			default:
					Mdl.SetParam(AbsMHVintage, AbsMHVintages.element("Unknown"));
				break;
			}
	
	//Setup width type				
	adco_cEnumElem AbsMHWidth = AbsMHInputs.element("Width");
	const adco_cEnumeration& AbsMHWidths = Mdl.GetList(AbsMHWidth.classification().name());
	
	switch (abs_mh_width_defn)
			{
			case SINGLE_SIZE:
				Mdl.SetParam(AbsMHWidth, AbsMHWidths.element("Single"));
				break;
			case DOUBLE_SIZE:
				Mdl.SetParam(AbsMHWidth, AbsMHWidths.element("Double"));
				break;
			default:
					Mdl.SetParam(AbsMHWidth, AbsMHWidths.element("Unknown"));
				break;
			}
							
	// Get Coupon History
	adco_TimeSeries * myCCYHist	= NULL;

	get_history(t, loan_type, Mdl, myCCYHist, AbsMHResults,
				histmth, histyr, msdyr, msdmth);

	adco_CParam CCYHistP(*myCCYHist);
	Mdl.SetParam(AbsMHInputs.element("CCYHistory"), CCYHistP);

	// Capture current mortgage rate from history 
	int idx = myCCYHist->GetIdx(histyr, histmth);
	cur_mtg_cpn = myCCYHist->Values()[idx - 1];

	try {Mdl.PreCalc();}
		
	catch(adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return;
		}

	// Get the CCY Forecast
	const adco_cEnumElem& eeCCYType = AbsMHCCYTypeMap.element(loan_type).classification();

	// Forecast the CCY rate
	adco_TimeSeries * myCCYForecast	= NULL;

	ccy_rate_forecast(t, offset, histyr, histmth, eeCCYType,
	                  cur_mtg_cpn, myCCYForecast, twoyr_forecast, tenyr_forecast, spread);

	// Parameterize the ABSMH Model with the CCY Forecast
	adco_CParam CCYfcst(*myCCYForecast);

	Mdl.SetParam(AbsMHInputs.element("CCYForecast"), CCYfcst);

	try {Mdl.Forecast();}

	catch (adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return;
		}

	adco_CParam SMMrslt = Mdl.GetParam(AbsMHResults.element("SMM"));
	adco_TimeSeries* SMM = &(adco_TimeSeries&) SMMrslt;

	int tempidx = SMM->GetIdx(histyr, histmth);	 //This offset is often zero, but could be non-zero.
	double* SMMptr = SMM->Values() + tempidx;

	int month = 0; 
	assert(sizeof(smm_forecast) >= max_maturity);

	for (month = 0; month < max_maturity && month < SMM->Length() - tempidx; month++)
  		smm_forecast[month] = SMMptr[month];

	if (process_adco_detail(t))
		{
		string version = Mdl.GetParam(AbsMHResults.element("VERSION"));
		char * loan_type;
		int pvcalc = 0;
		int nycalc = 0;
		int mvcalc = 0;

		int CCYHistidx = myCCYHist->GetIdx(histyr, histmth);

		CCYfcst = Mdl.GetParam(AbsMHInputs.element("CCYForecast"));
		adco_TimeSeries* CCY = &(adco_TimeSeries&) CCYfcst;
		int CCYidx = CCY->GetIdx(histyr, histmth);
	
		if (prepmt_forecast_defn != EXPERIENCE)
			pvcalc = 1;
	
		if (prepmt_forecast_defn == MARKET_VALUE)
			mvcalc = 1;
	
		if (prepmt_forecast_defn == NET_YIELD)
			nycalc = 1;
	
		switch (term_type)
			{
			case ADCO_ABS_30YR:
				loan_type = "30 Year";
				break;
			case ADCO_ABS_15YR:
				loan_type = "15 Year";
				break;
			default:
					loan_type = "Undefined";
				break;
			}
	
		ADCOFile << endl
				 << "ADCO Prepayment Detail" << endl
				 << "Asset ID," << asset_id << endl
				 << "Category," << category_id << endl
				 << "Model Type,ABS Manufactured Housing" << endl
				 << "ADCO Version," << version << endl
				 << "ProjTaskLoop," << proj_task_loop_num << endl
				 << "CalYr," << cal_yr << endl
				 << "CalMth," << cal_mth << endl
				 << "PVCalc," << pvcalc << endl
				 << "NYCalc," << nycalc << endl
				 << "MVCalc," << mvcalc << endl
				 << "ShftdYldCv," << shift_defn << endl
				 << "LoanType," << loan_type << endl
				 << "Age," << age << endl
				 << "RemTerm," << max_maturity << endl
				 << "Spread," << spread << endl
				 << "HistYr," << histyr << endl
				 << "HistMth," << histmth << endl
				 << "Offset," << offset << endl
				 << "FMth,Coupon,2YrRate,10YrRate,MtgCpn,SmmForecast" << endl;
	
		for (month = -4; month < max_maturity; month++)
			{
			if (month < 0)
				{
				int dCCYHistidx = CCYHistidx + month;
				double dCCYHist = myCCYHist->Values()[dCCYHistidx];

				ADCOFile << month << " "
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << dCCYHist << "," 
						 << 0.0 << endl;
				}
			else
				{
				int idx = 0;
				double dCCY = 0.0;

				idx = CCYidx + month;
				if (idx >= 0)
					dCCY = CCY->Values()[idx];

				ADCOFile << month << ","
						 << coupon << ","
						 << twoyr_forecast[month] << ","
						 << tenyr_forecast[month] << ","
						 << dCCY << ","
						 << smm_forecast[month] << endl;
				}
			} // endfor
		} //endif detail
	// Recycle the model
	pAdcoSystem->Adppmdl_recycle(Mdl);
	} // Global Try

catch (adco_cError &error_detail) 
	{
	error_processing(error_detail.message());
	return;
	}
}



#line 1 "ccy_rate_forecast.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::ccy_rate_forecast(int t, int offset, int histyr, int histmth, const adco_cEnumElem& eeCCYType, double cur_mtg_cpn, adco_TimeSeries *& myCCYForecast, double * twoyr_forecast, double * tenyr_forecast, double & spread)
{
// Get a CCYCALC model
CAdppmdl& ccycalc = pAdcoSystem->Adppmdl_factory("CCYCALC");

const adco_cEnumeration& CCYInputs = ccycalc.GetList("INPUTS");
const adco_cEnumeration& CCYResults = ccycalc.GetList("RESULTS");
const adco_cEnumeration& CCYTypes = ccycalc.GetList("CCY_TYPES");
const adco_cEnumeration& CCYCurves = ccycalc.GetList("CURVE_TYPES");

adco_cEnumElem CCYType = CCYInputs.element("CCY_Type");
adco_cEnumElem CCYCurveType = CCYInputs.element("Curve_Type");
adco_cEnumElem CCYCur2Yr = CCYInputs.element("Cur_2Yr");
adco_cEnumElem CCYCur10Yr = CCYInputs.element("Cur_10Yr");
adco_cEnumElem CCYCurMtg = CCYInputs.element("Cur_Mtg");
adco_cEnumElem CCYSprdMth = CCYInputs.element("Sprd_Mnth");
adco_cEnumElem CCYSprdYr = CCYInputs.element("Sprd_Yr");
adco_cEnumElem CCYSprd = CCYInputs.element("Spread");
adco_cEnumElem CCY2YrFrcst = CCYInputs.element("2Yr_Fcst");
adco_cEnumElem CCY10YrFrcst = CCYInputs.element("10Yr_Fcst");
adco_cEnumElem CCYForecast = CCYResults.element("CCYForecast"); 

twoyr_forecast[0]
= rates->get_int_rate(t - offset,
        "Govt",
		GET_YIELD_RATE,
		2.0,
		0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

tenyr_forecast[0]
= rates->get_int_rate(t - offset,
		"Govt",
		GET_YIELD_RATE,
		10.0,
		0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

// Determine spread year and month which is the period previous to histyr and histmth
int sprdmth = histmth;
int sprdyr = histyr;
AddMonthToDate(sprdyr, sprdmth, -1);	

// Set the CCY initial parameters
ccycalc.SetParam(CCYType, CCYTypes.element(eeCCYType.name()));
ccycalc.SetParam(CCYCurveType, CCYCurves.element("PAR_TSY"));
ccycalc.SetParam(CCYCur2Yr, twoyr_forecast[0]);
ccycalc.SetParam(CCYCur10Yr, tenyr_forecast[0]);
ccycalc.SetParam(CCYCurMtg, cur_mtg_cpn);
ccycalc.SetParam(CCYSprdMth, sprdmth); 
ccycalc.SetParam(CCYSprdYr, sprdyr); 
 
try {ccycalc.PreCalc();}

catch(adco_cError &error_detail) 
	{
	error_processing(error_detail.message());
	return;
	}

// Capture the spread at period before histyr and histmth
spread = (double) ccycalc.GetParam(CCYSprd);

// Forecast future two year treasury rates
scen_rate_forecast(t, prepmt_forecast_defn,
			 2.0, offset, 0, curr_cpn_vecsize, twoyr_forecast,
			 shift_defn);

adco_TimeSeries Fcst2yr(curr_cpn_vecsize, histyr, histmth, ADCO_MONTHLY);
Fcst2yr.SetVal(histyr, histmth, twoyr_forecast, curr_cpn_vecsize);

// Forecast future ten year treasury rates
scen_rate_forecast(t, prepmt_forecast_defn,
			 10.0, offset, 0, curr_cpn_vecsize, tenyr_forecast,
			 shift_defn);

adco_TimeSeries Fcst10yr(curr_cpn_vecsize, histyr, histmth, ADCO_MONTHLY);
Fcst10yr.SetVal(histyr, histmth, tenyr_forecast, curr_cpn_vecsize);

// Set the CCY forecast parameters
ccycalc.SetParam(CCY2YrFrcst, Fcst2yr);
ccycalc.SetParam(CCY10YrFrcst, Fcst10yr);

try {ccycalc.Forecast();}

catch (adco_cError &error_detail) 
	{
	error_processing(error_detail.message());
	return;
	}

// Save the CCYForecast to an array
adco_CParam CCYfcst = ccycalc.GetParam(CCYForecast);

adco_TimeSeries *CCY = &(adco_TimeSeries &) CCYfcst;
myCCYForecast =	new adco_TimeSeries(*CCY);

pAdcoSystem->Adppmdl_recycle(ccycalc);
}



#line 1 "error_processing.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::error_processing(xstring error_detail)
{
xstring error = "ADCO Model Failure - ";
error += error_detail;

throw FatalError(error);
}



#line 1 "get_history.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::get_history(int t, char *loan_type, CAdppmdl& Mdl, adco_TimeSeries *& hist_rates, const adco_cEnumeration& FixedResults, int histmth, int histyr, int msdyr, int msdmth)
{
//If history has been previously obtained, just retrieve from cache.
int last_hist_month = msdmth;
int last_hist_year = msdyr;
AddMonthToDate(last_hist_year, last_hist_month, curr_cpn_vecsize + max_maturity);

//NOTE: history needs to be rebuilt for each scenario (iteration).
string storename;
storename = loan_type;

map <string, CHistData>::iterator HistIt;
CHistData * pHist;
adco_TimeSeries * myHist;
string hist_name = "";

long errorcode = 0;

HistIt = HistData.find(storename);  //use find instead of [] in case it is already loaded.

if (HistIt != HistData.end()) //if exists
    pHist = &((*HistIt).second);	
else //if !exists load, else just keep the current one.
	{
    char *HistType = "";
	int month = 0;
	int year = 0;
    double rate_history[curr_cpn_vecsize + max_maturity];
	double twoyr_forecast[curr_cpn_vecsize + max_maturity];
	double tenyr_forecast[curr_cpn_vecsize + max_maturity];

	// Create 'Future' History for non HPI rates
	// Get a HistCache model for pulling historical timeseries from datafiles
	CAdppmdl& histcache = pAdcoSystem->Adppmdl_factory("HISTCACHE");

	if (eq(loan_type, "6MTHLIBOR"))
		{
	    HistType = "PAR_LIBOR_6M_MAVG";
		hist_name = "6MTHLIBOR";
		double rate_term = 0.5;

	    //Get reference to CCYHistory timeseries from Histcache model
	    adco_CParam histParam = histcache.GetParam(HistType);
	    adco_TimeSeries * Hist = &(adco_TimeSeries&) histParam;

	    myHist = new adco_TimeSeries(*Hist);

       	// extend the timeseries forward holding the last rate constant
        myHist->Extend(myHist->StartYear(), 
				       myHist->StartPeriod(), 
   		               last_hist_year, last_hist_month);

		for (month = 0; month < curr_cpn_vecsize + max_maturity; month++)
	        rate_history[month]
	        = (rates->get_int_rate(month - valn_period, 
				                   "Govt",
				                   GET_YIELD_RATE,
						           rate_term,
						           0.0,
						           NOMINAL_SEMIANNUAL,
						           NO_SHIFT,0) * 100.0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			  * 1.067413 + 0.391367;

		myHist->SetVal(msdyr, msdmth, rate_history, curr_cpn_vecsize + max_maturity);	

		pHist = &HistData[storename];
		pHist->Rates = myHist;			
		}
	else if (eq(loan_type, "2YRLIBOR"))
		{
	    HistType = "PAR_LIBOR_2YR_LAST";
		hist_name = "2YRLIBOR";
		double rate_term = 2.0;

	    //Get reference to CCYHistory timeseries from Histcache model
	    adco_CParam histParam = histcache.GetParam(HistType);
	    adco_TimeSeries * Hist = &(adco_TimeSeries&) histParam;

	    myHist = new adco_TimeSeries(*Hist);

        // extend the timeseries forward holding the last rate constant
        myHist->Extend(myHist->StartYear(), 
				       myHist->StartPeriod(), 
   		            last_hist_year, last_hist_month);

		for (month = 0; month < curr_cpn_vecsize + max_maturity; month++)
	        rate_history[month]
	        = (rates->get_int_rate(month - valn_period, 
				                   "Govt",
				                   GET_YIELD_RATE,
						           rate_term,
						           0.0,
						           NOMINAL_SEMIANNUAL,
						           NO_SHIFT,0) * 100.0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			  * 1.012891 + 0.343203;

		myHist->SetVal(msdyr, msdmth, rate_history, curr_cpn_vecsize + max_maturity);	

		pHist = &HistData[storename];
		pHist->Rates = myHist;			
		}
	else if (eq(loan_type, "10YRLIBOR"))
		{
	    HistType = "PAR_LIBOR_10YR_LAST";
		hist_name = "10YRLIBOR";
		double rate_term = 10.0;

	    //Get reference to CCYHistory timeseries from Histcache model
	    adco_CParam histParam = histcache.GetParam(HistType);
	    adco_TimeSeries * Hist = &(adco_TimeSeries&) histParam;

	    myHist = new adco_TimeSeries(*Hist);

        // extend the timeseries forward holding the last rate constant
        myHist->Extend(myHist->StartYear(), 
				       myHist->StartPeriod(), 
   		            last_hist_year, last_hist_month);

		for (month = 0; month < curr_cpn_vecsize + max_maturity; month++)
	        rate_history[month]
	        = (rates->get_int_rate(month - valn_period, 
				                   "Govt",
				                   GET_YIELD_RATE,
						           rate_term,
						           0.0,
						           NOMINAL_SEMIANNUAL,
						           NO_SHIFT,0) * 100.0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			  * 1.069434 + 0.092266;

		myHist->SetVal(msdyr, msdmth, rate_history, curr_cpn_vecsize + max_maturity);	

		pHist = &HistData[storename];
		pHist->Rates = myHist;			
		}	
	else if (eq(loan_type, "1YRTREAS")
		 	|| eq(loan_type, "2YRTREAS")
			 || eq(loan_type, "10YRTREAS"))
		{
		double rate_term = 0.0;

		if (eq(loan_type, "1YRTREAS"))
			{
		    HistType = "PAR_TSY_1YR_MAVG";
			hist_name = "1YRTREAS";
			rate_term = 1.0;
			}
		else if (eq(loan_type, "2YRTREAS"))
			{
			HistType = "PAR_TSY_2YR_LAST";
			hist_name = "2YRTREAS";
			rate_term = 2.0;
			}			
		else if (eq(loan_type, "10YRTREAS"))
			{
			HistType = "PAR_TSY_10YR_MAVG";
			hist_name = "10YRTREAS";
			rate_term = 10.0;
			}

	    //Get reference to CCYHistory timeseries from Histcache model
	    adco_CParam histParam = histcache.GetParam(HistType);
	    adco_TimeSeries * Hist = &(adco_TimeSeries&) histParam;

	    myHist = new adco_TimeSeries(*Hist);

        // we are just going to extend the timeseries forward holding the last rate constant
        myHist->Extend(myHist->StartYear(), 
				       myHist->StartPeriod(), 
   		            last_hist_year, last_hist_month);

		for (month = 0; month < curr_cpn_vecsize + max_maturity; month++)
	    	rate_history[month]
	        = rates->get_int_rate(month - valn_period,
	                              "Govt",
				                  GET_YIELD_RATE,
						          rate_term,
						          0.0,
						          NOMINAL_SEMIANNUAL,
						          NO_SHIFT,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		
		myHist->SetVal(msdyr, msdmth, rate_history, curr_cpn_vecsize + max_maturity);	

		pHist = &HistData[storename];
		pHist->Rates = myHist;			
		}
	else // other loan types
		{	
		// Get mapping from loantype to ccy history type, used to pull
		// correct history from histcache
		const adco_cEnumeration& HistMap = Mdl.GetList("CCYHISTMAP");
		const adco_cEnumeration& CCYTypeMap = Mdl.GetList("CCYTYPEMAP");
	
    	//Get reference to CCYHistory timeseries from Histcache model
		// -- unique for each loan_type
		const adco_cEnumElem& eeCCYType = CCYTypeMap.element(loan_type).classification();
	    const adco_cEnumElem HistElem = HistMap.elem_class(loan_type);

		hist_name = HistElem.name();
	
	    adco_CParam histParam = histcache.GetParam(HistElem);
	    adco_TimeSeries * Hist = &(adco_TimeSeries&)histParam;

	    myHist = new adco_TimeSeries(*Hist);

        // we are just going to extend the timeseries forward holding the last rate constant
        myHist->Extend(myHist->StartYear(), 
				       myHist->StartPeriod(), 
		               last_hist_year, last_hist_month);

		// Capture current mortgage rate from history 
		int idx = myHist->GetIdx(msdyr, msdmth);
		assert(idx > 0);
		double cur_mtg_cpn = myHist->Values()[idx - 1];
	
		// Use the CCYCALC model to create the CCY forecast

		// Get a CCYCALC model
		CAdppmdl& ccycalc = pAdcoSystem->Adppmdl_factory("CCYCALC");
	
		const adco_cEnumeration& CCYInputs = ccycalc.GetList("INPUTS");
		const adco_cEnumeration& CCYResults = ccycalc.GetList("RESULTS");
		const adco_cEnumeration& CCYTypes = ccycalc.GetList("CCY_TYPES");
		const adco_cEnumeration& CCYCurves = ccycalc.GetList("CURVE_TYPES");

		adco_cEnumElem CCYSprd = CCYInputs.element("Spread");
		
		// Get initial 2 and 10 year rates
        twoyr_forecast[month]
        = rates->get_int_rate(0 - valn_period, 
			            "Govt",
			            GET_YIELD_RATE,
			            2.0,
			            0.0,
			            NOMINAL_SEMIANNUAL,
			            NO_SHIFT,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
        tenyr_forecast[month]
        = rates->get_int_rate(0 - valn_period,
                        "Govt",
			            GET_YIELD_RATE,
			            10.0,
			            0.0,
			            NOMINAL_SEMIANNUAL,
			            NO_SHIFT,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

		// Set the CCY initial parameters
		ccycalc.SetParam(CCYInputs.element("CCY_Type"), CCYTypes.element(eeCCYType.name()));
		ccycalc.SetParam(CCYInputs.element("Curve_Type"), CCYCurves.element("PAR_TSY"));
		ccycalc.SetParam(CCYInputs.element("Cur_2Yr"), twoyr_forecast[0]);
		ccycalc.SetParam(CCYInputs.element("Cur_10Yr"), tenyr_forecast[0]);
		ccycalc.SetParam(CCYInputs.element("Cur_Mtg"), cur_mtg_cpn);
		ccycalc.SetParam(CCYInputs.element("Sprd_Mnth"), msdmth); 
		ccycalc.SetParam(CCYInputs.element("Sprd_Yr"), msdyr); 
		 
		try {ccycalc.PreCalc();}
		
		catch(adco_cError &error_detail) 
			{
			error_processing(error_detail.message());
			return;
			}
	
		// Create 2yr and 10yr Forecasts
		for (month = 0; month < curr_cpn_vecsize + max_maturity; month++)
			{
			twoyr_forecast[month]
			= rates->get_int_rate(month - valn_period,
			        "Govt",
					GET_YIELD_RATE,
					2.0,
					0.0,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
			tenyr_forecast[month]
			= rates->get_int_rate(month - valn_period,
			        "Govt",
					GET_YIELD_RATE,
					10.0,
					0.0,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			}

		adco_TimeSeries Fcst2yr(curr_cpn_vecsize, msdyr, msdmth, ADCO_MONTHLY);
		Fcst2yr.SetVal(msdyr, msdmth, twoyr_forecast, curr_cpn_vecsize + max_maturity);
	
		adco_TimeSeries Fcst10yr(curr_cpn_vecsize, msdyr, msdmth, ADCO_MONTHLY);
		Fcst10yr.SetVal(msdyr, msdmth, tenyr_forecast, curr_cpn_vecsize + max_maturity);
	
		// Set the CCY forecast parameters
		ccycalc.SetParam(CCYInputs.element("2Yr_Fcst"), Fcst2yr);
		ccycalc.SetParam(CCYInputs.element("10Yr_Fcst"), Fcst10yr);
	
		try {ccycalc.Forecast();}
	
		catch(adco_cError &error_detail) 
			{
			error_processing(error_detail.message());
			return;
			}
			
		// Get the CCY Forecast TimeSeries.
		adco_CParam CCYfcst = ccycalc.GetParam(CCYResults.element("CCYForecast"));
		adco_TimeSeries *CCY = &(adco_TimeSeries &) CCYfcst;
	
		// Copy CCYfcst to myCCYHist, starting at the msd.
		myHist->SetVal(msdyr, msdmth, *CCY, curr_cpn_vecsize + max_maturity);

		pHist = &HistData[storename];
		pHist->Rates = myHist;			

		pAdcoSystem->Adppmdl_recycle(ccycalc);
		}

	try
		{
		if (process_adco_detail(t))
			{
			int start_index = myHist->GetIdx(msdyr - 1, msdmth);
		
		    ADCOFile << endl
					 << "ADCO History Setup" << endl 
					 << "LoanType," << loan_type << endl
					 << "ProjTaskLoop," << proj_task_loop_num << endl
					 << "MSDYr," << msdyr << endl 
					 << "MSDMth," << msdmth << endl
					 << "HistName," << hist_name << endl << endl
					 << "Yr,Mth,Rate" << endl;
		
			int yr = msdyr - 1;
			int mth = msdmth;	
				
			for (int month = 0; month < curr_cpn_vecsize + max_maturity + 12; month++)
				{
				ADCOFile << yr << "," << mth << "," << myHist->Values()[start_index + month] << endl;
		
				// Increment mth and yr
				mth++;
				
				if (mth == 13)
					{
					mth = 1;
					yr++;
					}
				}
			}
		}
		
	catch (adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return;
		}
	}

hist_rates = pHist->Rates;

/* Check age, and extend array backwards if necessary */
int hist_year = histyr;
int hist_month = histmth;

AddMonthToDate(hist_year, hist_month, -(age+maximum_lag));  //The lag is needed for mbs_fixed.

// extend the timeseries backwards
if (hist_year<hist_rates->StartYear() || (hist_year==hist_rates->StartYear() && hist_month<=hist_rates->StartPeriod()))
	hist_rates->Extend(hist_year, hist_month,
               hist_rates->LastYear(), 
		       hist_rates->LastPeriod());

}



#line 1 "mbs_fixed_rate_setup.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::mbs_fixed_rate_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histmth, int histyr, char *ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast)
{
//NOTE: histyr/mth is the proj start date for existing assets or the month prior to the issue date for inv. assets.
int tempidx = 0;
int month = 0;
int msdmth = orig_proj_start_mth;
int msdyr = orig_proj_start_yr;
double cur_mtg_cpn = 0.0;
double spread = 0.0;
double ccy_history [curr_cpn_vecsize + max_maturity];
double twoyr_forecast[curr_cpn_vecsize];
double tenyr_forecast[curr_cpn_vecsize];

memset(twoyr_forecast, 0, curr_cpn_vecsize * sizeof(double));
memset(tenyr_forecast, 0, curr_cpn_vecsize * sizeof(double));

assert(pAdcoSystem != NULL);

const adco_cEnumeration& SysParamList = pAdcoSystem->ParamList();
const adco_cEnumElem DirParam = SysParamList.element("DATAFILEDIR");
pAdcoSystem->SetParam(DirParam, ADDataFileDir);

// Get List of Known Models
const adco_cEnumeration& ModelList = pAdcoSystem->ModelList();

// Make Enum Element for MBS Fixed Model type (only do name lookup once)
const adco_cEnumElem FixMdlType = ModelList.element("FIXEDMBS");

try 
	{
	// Get a fixed-rate prepayment model
	CAdppmdl& Mdl = pAdcoSystem->Adppmdl_factory(FixMdlType);

	const adco_cEnumeration& FixedInputs = Mdl.GetList("INPUTS");
	const adco_cEnumeration& FixedResults = Mdl.GetList("RESULTS");
	const adco_cEnumeration& FixedCCYTypeMap = Mdl.GetList("CCYTYPEMAP");
    const adco_cEnumeration& SwitchList = Mdl.GetList("SWITCH");

	char * loan_type;
	
    //determine loan type
	switch (ad_loan_type)
		{
		case FNMAB_3YR:
			loan_type = "FNMAB_3YR";
			break;
		case FNMAB_5YR:
			loan_type = "FNMAB_5YR";
			break;
		case FNMAB_7YR:
			loan_type = "FNMAB_7YR";
			break;
		case FNMAB_10YR:
			loan_type = "FNMAB_10YR";
			break;
		case FNMA_10YR:
			loan_type = "FNMA_10YR";
			break;
		case FNMA_15YR:
			loan_type = "FNMA_15YR";
			break;
		case FNMA_20YR:
			loan_type = "FNMA_20YR";
			break;
		case FNMA_30YR:
			loan_type = "FNMA_30YR";
			break;
		case GNMA_15YR:
			loan_type = "GNMA_15YR";
			break;
		case GNMA_30YR:
			loan_type = "GNMA_30YR";
			break;
		case GNMA2_15YR:
			loan_type = "GNMA2_15YR";
			break;
		case GNMA2_30YR:
			loan_type = "GNMA2_30YR";
			break;
		case FRDGB_3YR:
			loan_type = "FHLB_3YR";
			break;
		case FRDGB_5YR:
			loan_type = "FHLB_5YR";
			break;
		case FRDGB_7YR:
			loan_type = "FHLB_7YR";
			break;
		case FRDGB_10YR:
			loan_type = "FHLB_10YR";
			break;
		case FRDG_10YR:
			loan_type = "FHL_10YR";
			break;
		case FRDG_20YR:
			loan_type = "FHL_20YR";
			break;
		case FRDG_15YR:
			loan_type = "FHL_15YR";
			break;
		case FRDG_30YR:
			loan_type = "FHL_30YR";
			break;
		case WHOLEB_5YR:
			loan_type = "WHOLEB_5YR";
			break;
		case WHOLEB_7YR:
			loan_type = "WHOLEB_7YR";
			break;
		case WHOLE_15YR:
			loan_type = "WHOLE_15YR";
			break;
		case WHOLE_30YR:
			loan_type = "WHOLE_30YR";
			break;
		case RELO_15YR:
			loan_type = "RELO_15YR";
			break;
		case RELO_30YR:
			loan_type = "RELO_30YR";
			break;
		case ALT_A_15YR:
			loan_type = "ALT_A_15YR";
			break;
		case ALT_A_30YR:
			loan_type = "ALT_A_30YR";
			break;
		default:
			loan_type = "Undefined";
			break;
		}
    	
    // Initial State Inputs - required
	Mdl.SetParam(FixedInputs.element("LoanType"), loan_type);
    Mdl.SetParam(FixedInputs.element("WAC"), (double) coupon);
	Mdl.SetParam(FixedInputs.element("Age"), (int) age);
	Mdl.SetParam(FixedInputs.element("FirstForecastMonth"), histmth);
	Mdl.SetParam(FixedInputs.element("FirstForecastYear"), histyr);
	Mdl.SetParam(FixedInputs.element("RemainingTerm"), (int) remaining_term);
	
	// Setup Fixed Curve Type
	Mdl.SetParam(FixedInputs.element("Curve_Type"), "PAR_TSY");
	
	if (historical_loan_size_effect_defn == YES) 
    	Mdl.SetParam(FixedInputs.element("UseHistoricalLoanSize"), 
                                         SwitchList.element("ON"));
	else 
        Mdl.SetParam(FixedInputs.element("UseHistoricalLoanSize"), 
                                         SwitchList.element("OFF"));

	// Other advanced inputs - optional

    // face value is set to par value of loan at issue 
	Mdl.SetParam(FixedInputs.element("Orig_Face"), (double) original_face);
	
	double local_states[53];
	
	for (int state = 0; state < 53; state++) 
        local_states[state] = states[state];

	double local_property_types[3];
	
	for (int type = 0; type < 3; type++) 
        local_property_types[type] = property_types[type];
    
    double local_loan_purpose[3];

    for (int type = 0; type < 3; type++) 
        local_loan_purpose[type] = loan_purp[type];

    double local_occupancy[3];

    for (int type = 0; type < 3; type++) 
        local_occupancy[type] = occupancy[type];

	Mdl.SetParam(FixedInputs.element("Credit_Score"), (double) credit_score);
	Mdl.SetParam(FixedInputs.element("Original_LTV"), (double) original_ltv);
	Mdl.SetParam(FixedInputs.element("Regional_HPI"), (double) regional_hpi);
	Mdl.SetParam(FixedInputs.element("State"), local_states);
    Mdl.SetParam(FixedInputs.element("Property_Type"), local_property_types);
    Mdl.SetParam(FixedInputs.element("Loan_Purpose"), local_loan_purpose);
	Mdl.SetParam(FixedInputs.element("Occupancy"), local_occupancy);
	
	//***These parameters are in the ADCO interface, but will not be used. ***
	
	// Tuning Inputs - optional
    // Andrew Davidson strongly recommends that their File based tuning only be utilized,  
    // and that the end user should not concern themselves with passing tuning parameters 
    // to the interface. However, if the user wishes to pass their own tuning parameters 
    // the below code can be uncommented and used. It should be noted that the second
    // parameter being passed to "SetParam" will need to be created as MoSes variables.

	// Sensitivity Tuning Factors -- affects only Forecast() (only future projection)	
	//Mdl.SetParam(FixedInputs.element("TuningStartMonth"), (int) tuning_start_mth);
	//Mdl.SetParam(FixedInputs.element("TuningStartYear"), (int) tuning_start_yr);
	//Mdl.SetParam(FixedInputs.element("TuningEndMonth"), (int) tuning_end_mth);
	//Mdl.SetParam(FixedInputs.element("TuningEndYear"), (int) tuning_end_yr);
    //Mdl.SetParam(FixedInputs.element("TuningRampMonths"), (int) tuning_ramp_months);
    //Mdl.SetParam(FixedInputs.element("TuningFadeMonths"), (int) tuning_fade_months);
    //Mdl.SetParam(FixedInputs.element("SmmTuneScale"), (double) smm_tune_scale);
	//Mdl.SetParam(FixedInputs.element("SmmTuneBurnout"), (double) smm_tune_burnout);
	//Mdl.SetParam(FixedInputs.element("SmmTuneLag"), (double) smm_tune_lag);
    //Mdl.SetParam(FixedInputs.element("SmmTuneSlide"), (double) smm_tune_slide);
	//Mdl.SetParam(FixedInputs.element("SmmTuneTurnOver"), (double) smm_tune_turn_over);
    //Mdl.SetParam(FixedInputs.element("SmmTuneRefi"), (double) smm_tune_refi);
    //Mdl.SetParam(FixedInputs.element("SmmTuneCashout"), (double) smm_tune_cashout);
	//Mdl.SetParam(FixedInputs.element("SmmTuneCure"), (double) smm_tune_cure);
    //Mdl.SetParam(FixedInputs.element("SmmTuneAge"), (double) smm_tune_age);
	//Mdl.SetParam(FixedInputs.element("SmmTuneSATO"), (double) smm_tune_sato);
	//Mdl.SetParam(FixedInputs.element("SmmTuneCATO"), (double) smm_tune_cato);
	//Mdl.SetParam(FixedInputs.element("Cashout_RM"), (double) cashout_rm);
	//Mdl.SetParam(FixedInputs.element("Cure_RM"), (double) cure_rm);
	//Mdl.SetParam(FixedInputs.element("Refi_RM"), (double) refi_rm);
	//Mdl.SetParam(FixedInputs.element("Turnover_RM"), (double) turnover_rm);
	//Mdl.SetParam(FixedInputs.element("Psi0"), (double) (double) psi_0);
	//Mdl.SetParam(FixedInputs.element("PsiT"), (double) (double) psi_T);
		
	// Model Tuning Factors -- affects both PreCalc()and Forecast() 
	// (History and future projection) These are obsolete.
    //Mdl.SetParam(FixedInputs.element("SmmTuneScaleModel"), (double) smm_tune_scale_model);
    //Mdl.SetParam(FixedInputs.element("SmmTuneBurnoutModel"), (double) smm_tune_burnout_model);
    //Mdl.SetParam(FixedInputs.element("SmmTuneLagModel"), (double) smm_tune_lag_model);
    //Mdl.SetParam(FixedInputs.element("SmmTuneSlideModel"), (double) smm_tune_slide_model);
    //Mdl.SetParam(FixedInputs.element("SmmTuneTurnOverModel"), (double) smm_tune_turn_over_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneRefiModel"), (double) smm_tune_refi_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneCashoutModel"), (double) smm_tune_cashout_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneCureModel"), (double) smm_tune_cure_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneAgeModel"), (double) smm_tune_age_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneSATOModel"), (double) smm_tune_sato_model);
	//Mdl.SetParam(FixedInputs.element("SmmTuneCATOModel"), (double) smm_tune_cato_model);
	
	// Deprecated items use FirstForecastYear and FirstForecastMonth instead.
	//adco_cEnumElem FixedOrigYear = FixedInputs.element("OriginationYear");
    //adco_cEnumElem FixedOrigMonth = FixedInputs.element("OriginationMonth");
    
    // Old Names for FirstForecastYear and FirstForecastMonth. These are obsolete.
	//adco_cEnumElem FixedAsOfYear = FixedInputs.element("AsOfYear");
	//adco_cEnumElem FixedAsOfMonth = FixedInputs.element("AsOfMonth");
	
	// These input parameters are not needed since the US Library has already handled projection 
    // length and valuation period offset. 
    // adco_cEnumElem FixedForecastMonths = FixedInputs.element("ForecastMonths");
	// adco_cEnumElem FixedForecastOffset = FixedInputs.element("ForecastOffset");
	
	// Forecast Results that are not needed
	//adco_cEnumElem FixedMaxLag = FixedResults.element("MaxLag");
	//adco_cEnumElem FixedForecastCount = FixedResults.element("ForecastCount");
	//adco_cEnumElem FixedModel = FixedResults.element("Model");
    //adco_cEnumElem FixedLicense = FixedResults.element("License");

    // Obsolete and have no effect on the projection
    //adco_cEnumElem FixedHPIForecast = FixedInputs.element("HPIForecast"); 
	//adco_cEnumElem FixedHPIRvsnval = FixedInputs.element("HPIRvsnVal");
	
	// Miscellaneous parameters that are not needed
	//adco_cEnumElem FixedDealID = FixedInputs.element("DealID");
	//adco_cEnumElem FixedPoolID = FixedInputs.element("PoolID");
	//adco_cEnumElem FixedZeroVectorsFlag = FixedInputs.element("ZeroVectorsFlag");
	//adco_cEnumElem FixedTuneString = FixedInputs.element("TuneString");
    //adco_cEnumElem FixedTuningShelf = FixedInputs.element("TuningShelf");
	//adco_cEnumElem FixedTuningShelf1 = FixedInputs.element("TuningShelf1");
	//adco_cEnumElem FixedTuningShelf2 = FixedInputs.element("TuningShelf2");
	//adco_cEnumElem FixedTuningShelf3 = FixedInputs.element("TuningShelf3");
	//adco_cEnumElem FixedTuningShelf4 = FixedInputs.element("TuningShelf4");	
	//adco_cEnumElem FixedDumpFile = FixedResults.element("DUMPFILE")
	//****************************************************************************

	// CCY History
	adco_TimeSeries * myCCYHist = NULL;

	get_history(t, loan_type, Mdl, myCCYHist, FixedResults,
				   histmth, histyr, msdyr, msdmth);

	adco_CParam CCYHistP(*myCCYHist);
	Mdl.SetParam(FixedInputs.element("CCYHistory"), CCYHistP);

	// Capture current mortgage rate from history 
	int idx = myCCYHist->GetIdx(histyr, histmth);
	assert(idx > 0);
	cur_mtg_cpn = myCCYHist->Values()[idx - 1];

	try {Mdl.PreCalc();}
    
	catch(adco_cError & error_detail)
		{
		error_processing(error_detail.message());
		return;
		}
		
	// Set CCY Type
	const adco_cEnumElem& eeCCYType = FixedCCYTypeMap.element(loan_type).classification();

	// Forecast the CCY rate
	adco_TimeSeries * myCCYForecast = NULL;

	ccy_rate_forecast(t, offset, histyr, histmth, eeCCYType,
	                  cur_mtg_cpn, myCCYForecast, twoyr_forecast, tenyr_forecast, spread);

	// Parameterize the Fixed Model with the CCY Forecast TimeSeries.
	adco_CParam CCYfcst(*myCCYForecast);
	Mdl.SetParam(FixedInputs.element("CCYForecast"), CCYfcst);

	// Determine prepayment forecast
	try {Mdl.Forecast();}

	catch(adco_cError &error_detail) 
		{
		error_processing(error_detail.message());
		return;
		}

	// Save the SMM results to a timeseries
	adco_CParam SMMrslt = Mdl.GetParam(FixedResults.element("SMM"));
	adco_TimeSeries* SMM = &(adco_TimeSeries&) SMMrslt;

	tempidx = SMM->GetIdx(histyr, histmth);	 //This offset is often zero, but could be non-zero.
	double* SMMptr = SMM->Values() + tempidx;

	int month = 0; 
	assert(sizeof(smm_forecast) >= max_maturity);
    
    // Save to SMM array
	for (month = 0; month < max_maturity && month < SMM->Length() - tempidx; month++)
  		smm_forecast[month] = SMMptr[month];
    
    // Setup cashout incentive SMM vector
	SMMrslt = Mdl.GetParam(FixedResults.element("CashoutSMM"));
	adco_TimeSeries* CashoutSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = CashoutSMM->GetIdx(histyr, histmth);	 
	double* CashoutSMMptr = CashoutSMM->Values() + tempidx;
	    
	for (month = 0; month < max_maturity && month < CashoutSMM->Length() - tempidx; month++)
  	   smm_cashout_forecast[month] = CashoutSMMptr[month];
        
    // Setup credit cure SMM vector
	SMMrslt = Mdl.GetParam(FixedResults.element("CreditCureSMM"));
	adco_TimeSeries* CreditCureSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = CreditCureSMM->GetIdx(histyr, histmth);	 
	double* CreditCureSMMptr = CreditCureSMM->Values() + tempidx;
	
	for (month = 0; month < max_maturity && month < CreditCureSMM->Length() - tempidx; month++)
  	   smm_credit_cure_forecast[month] = CreditCureSMMptr[month];

	// Setup refinance incentive SMM vector
	SMMrslt = Mdl.GetParam(FixedResults.element("RefiSMM"));
	adco_TimeSeries* RefiSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = RefiSMM->GetIdx(histyr, histmth);	 
	double* RefiSMMptr = RefiSMM->Values() + tempidx;
	    
	for (month = 0; month < max_maturity && month < RefiSMM->Length() - tempidx; month++)
  	   smm_refi_forecast[month] = RefiSMMptr[month];
        
    // Setup Turnover SMM vector
	SMMrslt = Mdl.GetParam(FixedResults.element("TurnoverSMM"));
	adco_TimeSeries* TurnoverSMM = &(adco_TimeSeries&) SMMrslt;
	tempidx = TurnoverSMM->GetIdx(histyr, histmth);	 
	double* TurnoverSMMptr = TurnoverSMM->Values() + tempidx;
	
	for (month = 0; month < max_maturity && month < TurnoverSMM->Length() - tempidx; month++)
  	   smm_turnover_forecast[month] = TurnoverSMMptr[month];

	if (process_adco_detail(t))
	    {
		string version = Mdl.GetParam(FixedResults.element("VERSION"));

		// Setup HPI Forecast vector
		adco_CParam HPIFcst = Mdl.GetParam(FixedInputs.element("HPIForecast"));
		adco_TimeSeries* HPIFcstTS = &(adco_TimeSeries&) HPIFcst;
		tempidx = HPIFcstTS->GetIdx(histyr, histmth);	 
		double* HPIFcstptr = HPIFcstTS->Values() + tempidx;

		xstring loan_type;
		int pvcalc = 0;
		int nycalc = 0;
		int mvcalc = 0;
     
		int CCYHistidx = myCCYHist->GetIdx(histyr, histmth);
		
		CCYfcst = Mdl.GetParam(FixedInputs.element("CCYForecast"));
		adco_TimeSeries *CCY = &(adco_TimeSeries &) CCYfcst;
		int CCYidx = CCY->GetIdx(histyr, histmth);

		if (prepmt_forecast_defn != EXPERIENCE)
			pvcalc = 1;

		if (prepmt_forecast_defn == MARKET_VALUE)
			mvcalc = 1;

		if (prepmt_forecast_defn == NET_YIELD)
			nycalc = 1;

		switch (ad_loan_type)
			{
			case FNMAB_3YR:
				loan_type = "FNMA 3YR Balloon";
				break;
			case FNMAB_5YR:
				loan_type = "FNMA 5YR Balloon";
				break;
			case FNMAB_7YR:
				loan_type = "FNMA 7YR Balloon";
				break;
			case FNMAB_10YR:
				loan_type = "FNMA 10YR Balloon";
				break;
			case FNMA_10YR:
				loan_type = "FNMA 10YR";
				break;
			case FNMA_15YR:
				loan_type = "FNMA 15YR";
				break;
			case FNMA_20YR:
				loan_type ="FNMA 20YR";
				break;
			case FNMA_30YR:
				loan_type ="FNMA 30YR";
				break;
			case GNMA_15YR:
				loan_type = "GNMA 15YR";
				break;
			case GNMA_30YR:
				loan_type = "GNMA 30YR";
				break;
			case GNMA2_15YR:
				loan_type = "GNMA2 15YR";
				break;
			case GNMA2_30YR:
				loan_type = "GNMA2 30YR";
				break;
			case FRDGB_3YR:
				loan_type = "FHLMC 3YR Balloon";
				break;
			case FRDGB_5YR:
				loan_type = "FHLMC 5YR Balloon";
				break;
			case FRDGB_7YR:
				loan_type = "FHLMC 7YR Balloon";
				break;
			case FRDGB_10YR:
				loan_type = "FHLMC 10YR Balloon";
				break;
			case FRDG_10YR:
				loan_type = "FHLMC 10YR";
				break;
			case FRDG_15YR:
				loan_type = "FHLMC 15YR";
				break;
			case FRDG_20YR:
				loan_type = "FHLMC 20YR";
				break;
			case FRDG_30YR:
				loan_type = "FHLMC 30YR";
				break;
			case WHOLEB_5YR:
				loan_type = "WL 5YR Balloon";
				break;
			case WHOLEB_7YR:
				loan_type = "WL 7YR Balloon";
				break;
			case WHOLE_15YR:
				loan_type = "WL 15YR";
				break;
			case WHOLE_30YR:
				loan_type = "WL 30YR";
				break;
			case RELO_15YR:
				loan_type = "RELO 15YR";
				break;
			case RELO_30YR:
				loan_type = "RELO 30YR";
				break;
			case ALT_A_15YR:
				loan_type ="ALT A 15YR";
				break;
			case ALT_A_30YR:
				loan_type = "ALT A 30YR";
				break;
			default:
				loan_type = "Undefined";
				break;
			} 
			
		ADCOFile << endl
				 << "ADCO Prepayment Detail" << endl
				 << "AssetID," << asset_id << endl
				 << "Category," << category_id << endl
				 << "ADCOPrepaymentModelType,MBS Fixed Rate Mortgage" << endl
				 << "ADCOVersion," << version << endl
				 << "ProjTaskLoop," << proj_task_loop_num << endl
				 << "CalYr," << cal_yr  << endl
				 << "CalMth," << cal_mth << endl
				 << "PVCalc," << pvcalc << endl
				 << "NYCalc," << nycalc << endl
				 << "MVCalc," << mvcalc << endl
				 << "ShftdYldCv," << shift_defn << endl
				 << "LoanType," << loan_type << endl
				 << "Age," << age << endl
				 << "RemTerm," << remaining_term << endl
				 << "Spread," << spread << endl
				 << "HPIType,Conforming Loans" << endl
				 << "HistYr," << histyr << endl
				 << "HistMth," << histmth << endl
				 << "Offset," << offset << endl << endl
				 << "FMth,Coupon,2YrRate,10YrRate,MtgCpn,HPIForecast,SmmForecast,SmmCashForecast,SmmCureForecast,SmmRefiForecast,SmmTurnForecast" << endl;

		int month = 0;
		
		for (month = -4; month < remaining_term; month++)
			{
			if (month < 0)
				{
				int dCCYHistidx = CCYHistidx + month;
				double dCCYHist = myCCYHist->Values()[dCCYHistidx];

				ADCOFile << month << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << dCCYHist << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << ","
						 << 0.0 << endl;				
				}
			else
				{
				int idx = 0;
				double dCCY = 0.0;

				idx = CCYidx + month;
				
				if (idx >= 0)
					dCCY = CCY->Values()[idx];

				ADCOFile << month << ","
						 << coupon << ","
						 << twoyr_forecast[month] << ","
						 << tenyr_forecast[month] << ","
						 << dCCY << ","
						 << HPIFcstptr[month] << ","
						 << smm_forecast[month] << ","
						 << smm_cashout_forecast[month] << ","
						 << smm_credit_cure_forecast[month] << ","
						 << smm_refi_forecast[month] << ","
						 << smm_turnover_forecast[month] << ","
						 << endl;
				}
			} // endfor
		} //endif detail

	// Recycle the model
	pAdcoSystem->Adppmdl_recycle(Mdl);
	}
catch (adco_cError &error_detail) 
	{
	error_processing(error_detail.message());
	return;
	}
}



#line 1 "scen_rate_forecast.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::scen_rate_forecast(int t, int forecast_type, double rateterm, int offset, int startidx, int loopend, double* rateforecast, int shift_defn)
{
///////////////////////////////////////////////////////////////////////////////////
// NOTE: Rates captured differ by purpose as follows:
//
//        Purpose                             Rate
//        =========================           =============================
//        Initial Prepayment Setup:           Future actual scenario rates.
//        Net Yield Calculations:             Past actual rates up to offset period
//                                            then level at current scenario rate.
//        Market Value Calculations:          Past actual rates up to offset period
//                                            then forward rates.
////////////////////////////////////////////////////////////////////////////////////
int loop;

for(loop = 0; loop < loopend; loop++)
	{
	if (forecast_type != EXPERIENCE)
		{
		if (forecast_type == NET_YIELD)
			{
			if (loop < offset) // use past actual scenario rates
				rateforecast[startidx+loop]
				= rates->get_int_rate(t - offset + loop,
				            "Govt",
							GET_YIELD_RATE,
							rateterm,
							0.0, 
							NOMINAL_SEMIANNUAL,
							shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			else // use current scenario rate level
				rateforecast[startidx+loop]
				= rates->get_int_rate(t,
                            "Govt",				  
							GET_YIELD_RATE,
							rateterm,
							0.0, 
							NOMINAL_SEMIANNUAL,
							shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
             }

		else // MV Calculations
			{
			if (loop < offset) // use past actual scenario rates
				rateforecast[startidx+loop]
				= rates->get_int_rate(t - offset + loop,
				            "Govt",
							GET_YIELD_RATE,
							rateterm,
							0.0, 
							NOMINAL_SEMIANNUAL,
							shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			else // use forward scenario rates
				rateforecast[startidx+loop]
				= rates->get_int_rate(t,
				            "Govt",
				            GET_FORWARD_RATE, 
							(loop + 1.0 - offset) * (1.0 / 12.0),
							rateterm,
							NOMINAL_SEMIANNUAL,
							shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			}
		}

	else // Initial setup - use actual scenario rates 
		rateforecast[startidx+loop] 
		= rates->get_int_rate(t - offset + loop,
		            "Govt",
					GET_YIELD_RATE,
					rateterm,
					0.0,
					NOMINAL_SEMIANNUAL,
					shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	} // End for future treasury rates

return;
}



#line 1 "setup_prepmt_rates.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::setup_prepmt_rates(int t)
{
if (t < t_low)
	{
	log_screen << "Error. The 'Proj Period Min' property"
			<< " on the Projection Property Run Control panel"
			<< " must be reset to " << t
			<< " or less before this projection task will run."
			<< MSG_ERROR;

	throw FatalError("");
	}

int cal_yr = cal_yr_relative(t);
int cal_mth = xint(this->cal_mth(t));
int idx = 0;
int histyr = 0;
int histmth = 0;
int issmth = 0;
int issyr = 0;
int offset = 0;
int purch_proj_mth = 0;
int valn_period_offset = 0.0;
double smm[max_maturity];
double smm_cashout[max_maturity];
double smm_credit_cure[max_maturity];
double smm_refi[max_maturity];
double smm_turnover[max_maturity];

xstring ADDataFileDir;

xstring proj_task_loop = xstring(proj_task_loop_num);

// Resize and initialize smm vector
if (prepmt_rates.size() < 601)
	prepmt_rates.resize(601);
	
for(int i = 0; i < 601; i++)
	prepmt_rates[i] = 0.0;
			
memset(smm, 0, max_maturity * sizeof(double));
memset(smm_cashout, 0, max_maturity * sizeof(double));
memset(smm_credit_cure, 0, max_maturity * sizeof(double));
memset(smm_refi, 0, max_maturity * sizeof(double));
memset(smm_turnover, 0, max_maturity * sizeof(double));

// Must offset for valuation period in nested experience projection
if (time_step_flag && !valn_flag && valn_period > 0)
	valn_period_offset = valn_period;

if (existing_asset_indicator == INIT_MP)
	{
	ADDataFileDir = history_directory;

	if (asset_proj_defn == USLIB)
		offset = t;
	else
		offset = offset_mths;

	histmth = proj_start_mth 
	         + ((12 - (valn_date_offset_mths % 12)) % 12);

	if (histmth > 12)
		histmth -= 12;

	histyr = floor(proj_start_yr 
 		    + (proj_start_mth - valn_date_offset_mths - 1) / 12.0);
	}
else if (existing_asset_indicator == PRIOR_PURCH)
	{
	ADDataFileDir = history_directory;

	purch_proj_mth = commencement_period + 1; 
	offset = t + 1 - purch_proj_mth;

	histyr =  proj_start_yr + ((proj_start_mth + purch_proj_mth  - 2) / 12);
	histmth = 1 + ((proj_start_mth + purch_proj_mth - 2) % 12);
	}
else // Purchase asset
	{	
	// Create prefix based on the extension used for the scenario file.
	ADDataFileDir = history_directory;

	purch_proj_mth = commencement_period + 1; 
	offset = t + 1 - purch_proj_mth;

	histyr =  proj_start_yr + ((proj_start_mth + purch_proj_mth  - 2) / 12);
	histmth = 1 + ((proj_start_mth + purch_proj_mth - 2) % 12);
	}

if (prepmt_model_defn == MBS)
	{
	if (mbs_prepmt_defn == FIXED_RATE)
		mbs_fixed_rate_setup(t, cal_yr, cal_mth,
				             loan_type, offset + valn_period_offset, histmth, histyr, 
				             const_cast <char *> (ADDataFileDir.c_str()), 
				             smm, smm_cashout, smm_credit_cure, smm_refi, smm_turnover);

	else if (mbs_prepmt_defn == ARM)
		unified_setup(t, cal_yr, cal_mth, 
			          issuer, offset + valn_period_offset, histmth, histyr,
               	   const_cast <char *> (ADDataFileDir.c_str()),
                      smm, smm_cashout, smm_credit_cure, smm_refi, smm_turnover);

    else if (mbs_prepmt_defn == HYBRID)
		unified_setup(t, cal_yr, cal_mth, 
			          issuer, offset + valn_period_offset, histmth, histyr,
                      const_cast <char *> (ADDataFileDir.c_str()),
                      smm, smm_cashout, smm_credit_cure, smm_refi, smm_turnover);
	else
		throw FatalError("Invalid MSB prepayment type. Please check your data for Asset "
				         + asset_id);
	}
else // prepayment model type == ABS
	{
	if (abs_prepmt_defn == AUTO)
		abs_auto_setup(t, cal_yr, cal_mth,
				       loan_type, offset + valn_period_offset, histyr, histmth,
		               const_cast <char *> (ADDataFileDir.c_str()), smm);
		
	else if (abs_prepmt_defn == FIXED_HOME_EQUITY_LOAN)
		abs_hel_setup(t, cal_yr, cal_mth,
			          loan_type, offset + valn_period_offset, histyr, histmth,
				      const_cast <char *> (ADDataFileDir.c_str()), 
				      smm, smm_cashout, smm_credit_cure, smm_refi, smm_turnover);

	else if (abs_prepmt_defn == ARM_HOME_EQUITY_LOAN)
         unified_setup(t, cal_yr, cal_mth, 
			           issuer, offset + valn_period_offset, histmth, histyr,
           	        const_cast <char *> (ADDataFileDir.c_str()),
                       smm, smm_cashout, smm_credit_cure, smm_refi, smm_turnover);

	else if (abs_prepmt_defn == MANUFACTURED_HOUSING)
		abs_mh_setup(t, cal_yr, cal_mth,
			         loan_type, offset + valn_period_offset, histyr, histmth,
				     const_cast <char *> (ADDataFileDir.c_str()), smm);

	else
		throw FatalError("Invalid ABS prepayment type. Please check your data for Asset "
				         + asset_id);
	}

// Check and make sure smm components add up to total smm
if (!(prepmt_model_defn == ABS  // All 5.2h models except these use the smm components
    && (abs_prepmt_defn == AUTO || abs_prepmt_defn == MANUFACTURED_HOUSING)))
	{
	bool issue_warning = false;
	int month = 0;

	for (idx = 1; idx <= max_maturity; idx++)
		{
		if (fabs(smm[idx - 1] - 1.0) > rate_ratio_threshold // there is only an error if smm is not equal to 1.0
			&& (fabs(smm[idx - 1] - smm_cashout[idx - 1] 
		        - smm_credit_cure[idx - 1] - smm_refi[idx - 1] - smm_turnover[idx - 1]) 
		        > rate_ratio_threshold))  
		 	{
			 issue_warning = true;
			 month = idx;
			 break;
			 }
		}
	
	if (issue_warning)
		{
		if (!process_adco_detail(t))
			{
			makeRunLogYellow();
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << setprecision(6);
		    log_screen << "Warning: ADCO component prepayment rates do not sum up to the "
		           	<< "total SMM prepayment rate starting in month " << month 
		           	<< " for Asset "<< asset_id << "."
				       << MSG_ERROR;
			log_screen << "Run an ADCO detail report to view all SMM prepayment rates. " 
		           	<< MSG_ERROR;
			log_screen << setprecision(6);
			log_screen.unsetf(ios::fixed);   
			}
		else
			{
			makeRunLogYellow();
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << setprecision(6);
		    log_screen << "Warning: ADCO component prepayment rates do not sum up to the "
		           	<< "total SMM prepayment rate starting in month " << month 
		           	<< " for Asset "<< asset_id << "."
		           	<< MSG_ERROR;
			log_screen << setprecision(6);
			log_screen.unsetf(ios::fixed);   
			}		 			
		}
	}
			
// Copy from smm vector to prepayment_rates array
for (idx = 1; idx <= max_maturity; idx++)
	prepmt_rates[idx] = smm[idx - 1];
}



#line 1 "unified_setup.ADCO_ASSET.for"                                                                                   
void ADCO_ASSET::unified_setup(int t, int cal_yr, int cal_mth, int issuer_type, int offset, int histmth, short histyr, char* ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast)
{
/////////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: This function sets up the ADCO UNIFIED Model interface for the adppmdl.dll version 5.2h:
// 
// At the time of development the unified model only supports all ARM loan types.       
// ADCO intends to add other prepayment models to the UNIFIED model 
// (MBSFIXED, for example) in future releases. Future versions of the adppmdl.dll may 
// require this setup procedure to be modified.
//
/////////////////////////////////////////////////////////////////////////////////////////////////	
int month = 0;
int msdmth = orig_proj_start_mth;
int msdyr = orig_proj_start_yr;
int lag_month = histmth;
int lag_year = histyr;
int last_hist_month = histmth;
int last_hist_year = histyr;
int idx;

AddMonthToDate(last_hist_year, last_hist_month, curr_cpn_vecsize);

double libor2yr_forecast[max_maturity];
double libor10yr_forecast[max_maturity];
double index_forecast[max_maturity];

memset(libor2yr_forecast, 0, (max_maturity) * sizeof(double));
memset(libor10yr_forecast, 0, (max_maturity) * sizeof(double));
memset(index_forecast, 0, (max_maturity) * sizeof(double));

adco_TimeSeries * myYr2Hist = NULL;
adco_TimeSeries * myYr10Hist = NULL;

const adco_cEnumeration& SysParamList = pAdcoSystem->ParamList();
const adco_cEnumElem DirParam = SysParamList.element("DATAFILEDIR");
pAdcoSystem->SetParam(DirParam, ADDataFileDir);

//Get List of Known Models
const adco_cEnumeration& ModelList = pAdcoSystem->ModelList();

//Make Enum Element for UNIFIED Model type (only do name lookup once)
const adco_cEnumElem UnifiedMdlType = ModelList.element("UNIFIED");

try 
	{
	// Get a unified model
	CAdppmdl& Mdl = pAdcoSystem->Adppmdl_factory(UnifiedMdlType);

	const adco_cEnumeration& UnifiedInputs = Mdl.GetList("INPUTS");
	const adco_cEnumeration& UnifiedResults = Mdl.GetList("RESULTS");
    
    char * issuer_type_name = "";
    
	switch (issuer_type)// use issuer scalar 
		{
		case FANNIE_MAE:
			issuer_type_name = "FANNIE_MAE";
			break;
		case GINNIE_MAE:
	        issuer_type_name = "GINNIE_MAE";
			break;
		case FREDDIE_MAC:
	        issuer_type_name = "FREDDIE_MAC";
			break;
		case NONAGENCY_PRIME:
    	    issuer_type_name = "NONAGENCY_PRIME";
			break;
		case NONAGENCY_SUBPRIME:
	        issuer_type_name = "NONAGENCY_SUBPRIME";
			break;
		default:
			throw FatalError("ADCO Model Failure: Unknown Issuer of loan.");
			break;
		}
		
	/********* Required non-TIMESERIES parameters ********/
	Mdl.SetParam(UnifiedInputs.element("Issuer"), issuer_type_name);
    Mdl.SetParam(UnifiedInputs.element("RemainingTerm"),(int) remaining_term);
	Mdl.SetParam(UnifiedInputs.element("Age"), (int) age);
	Mdl.SetParam(UnifiedInputs.element("FirstForecastYear"), histyr);
	Mdl.SetParam(UnifiedInputs.element("FirstForecastMonth"), histmth);
	Mdl.SetParam(UnifiedInputs.element("FirstResetAge"), (int) arm_first_reset_age);
	Mdl.SetParam(UnifiedInputs.element("MonthsBetweenReset"), (int) arm_reset_mths);
	Mdl.SetParam(UnifiedInputs.element("GrossMargin"), (double) arm_margin);
	Mdl.SetParam(UnifiedInputs.element("WAC"), (double) coupon);
	
	if (arm_flag == YES)
    	Mdl.SetParam(UnifiedInputs.element("WacIsFixed"), (int) 0);
	else // Fixed
	    Mdl.SetParam(UnifiedInputs.element("WacIsFixed"), (int) 1);
	
	if (subprime_defn == PRIME_COLLATERAL)
    	Mdl.SetParam(UnifiedInputs.element("IsSubprime"),(int) 0);        
    else // Subprime collateral
        Mdl.SetParam(UnifiedInputs.element("IsSubprime"),(int) 1); 

	/********* Optional non-TIMESERIES Parameters ********/
	Mdl.SetParam(UnifiedInputs.element("OriginalTerm"), (int) original_term);
    Mdl.SetParam(UnifiedInputs.element("ServicingFee"), (double) servicing_fee);
    Mdl.SetParam(UnifiedInputs.element("StartingWac"), (double) coupon);    
    Mdl.SetParam(UnifiedInputs.element("Cur_Face"), (double) current_face); 

	if (adjustable_rate_defn == NON_CONVERTIBLE)
    	Mdl.SetParam(UnifiedInputs.element("IsConvertible"), (int) 0);
	else // CONVERTIBLE
	    Mdl.SetParam(UnifiedInputs.element("IsConvertible"), (int) 1);
	
	if (mbs_collateral_defn != RELO)
    	Mdl.SetParam(UnifiedInputs.element("IsRelo"), (int) 0);
	else // RELO Loan
	    Mdl.SetParam(UnifiedInputs.element("IsRelo"), (int) 1);
	
	// Optional ARM Parameters 
    Mdl.SetParam(UnifiedInputs.element("LifeCap"), (double) arm_max_rate);
    Mdl.SetParam(UnifiedInputs.element("LifeFloor"), (double) arm_min_rate);
    Mdl.SetParam(UnifiedInputs.element("FirstResetCap"), (double) arm_max_reset_period_rate);
    Mdl.SetParam(UnifiedInputs.element("FirstResetFloor"), (double) arm_min_reset_period_rate);	
    Mdl.SetParam(UnifiedInputs.element("PayResetFreq"), (int) arm_reset_mths);

    // Parameters that depend on if intex is being used
    if (asset_proj_defn != INTEX)
    	{
        switch (index)// use index scalar 
			{
			case PAR_TSY_1YR:
		   	 	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_1YR"); 
					break;
			case PAR_TSY_3YR:
		   	 	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_3YR"); 
					break;	
			case PAR_TSY_5YR:
					Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_5YR"); 
					break;			
			default:
					throw FatalError("ADCO Model Failure: Unknown ARM Index Type.");
					break;
			}
			
        Mdl.SetParam(UnifiedInputs.element("PeriodicCap"), (double) arm_max_reset_period_rate);
        Mdl.SetParam(UnifiedInputs.element("PeriodicFloor"), (double) arm_min_reset_period_rate);
        Mdl.SetParam(UnifiedInputs.element("IOMonths"), (int) interest_only_mths);
        Mdl.SetParam(UnifiedInputs.element("PPMonths"), (int) prepmt_penalty_mths);		
        }
    else //asset_proj_defn == INTEX 
		{
        switch (index)// use index scalar
			{
			case PAR_LIBOR_6M:
		   	  	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_LIBOR_6M"); 
				 	break;
			case PAR_LIBOR_1YR:
		   	 	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_LIBOR_1YR"); 
					break;
			case PAR_TSY_1YR:
		   	 	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_1YR"); 
					break;	
			case PAR_TSY_3YR:
		   	 	Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_3YR"); 
					break;
			case PAR_TSY_5YR:
					Mdl.SetParam(UnifiedInputs.element("Index"), "PAR_TSY_5YR"); 
					break;		
			case COFI_11D:
					Mdl.SetParam(UnifiedInputs.element("Index"), "COFI_11D"); 
					break;		
			case MTA_12:
					Mdl.SetParam(UnifiedInputs.element("Index"), "MTA_12"); 
					break;
			default:
					throw FatalError("ADCO Model Failure: Unknown Index Type.");
					break;
			}
			
		Mdl.SetParam(UnifiedInputs.element("LookBackMonths"), (int) arm_lookback_mths);	
        Mdl.SetParam(UnifiedInputs.element("PeriodicCap"), (double) arm_max_reset_period_rate);
        Mdl.SetParam(UnifiedInputs.element("PeriodicFloor"), (double) arm_min_reset_period_rate);
		}
		
    //Enhanced Optional inputs
    Mdl.SetParam(UnifiedInputs.element("Original_LTV"), (double) original_ltv);
    Mdl.SetParam(UnifiedInputs.element("Orig_Face"), (double) original_face);

    double local_states[53];
	
	for (int state = 0; state < 53; state++) 
        local_states[state] = states[state];

	double local_property_types[3];
	
	for (int type = 0; type < 3; type++) 
        local_property_types[type] = property_types[type];
    
    double local_loan_purpose[3];

    for (int type = 0; type < 3; type++) 
        local_loan_purpose[type] = loan_purp[type];

    double local_occupancy[4];

    for (int type = 0; type < 3; type++) 
        local_occupancy[type] = occupancy[type];

	Mdl.SetParam(UnifiedInputs.element("Credit_Score"), (double) credit_score);
	Mdl.SetParam(UnifiedInputs.element("State"), local_states);
    Mdl.SetParam(UnifiedInputs.element("Property_Type"), local_property_types);
    Mdl.SetParam(UnifiedInputs.element("Loan_Purpose"), local_loan_purpose);
	Mdl.SetParam(UnifiedInputs.element("Occupancy"), local_occupancy);
	 
	if (balloon_term > 0)
		Mdl.SetParam(UnifiedInputs.element("BalloonMonths"), (int) balloon_term);
	else
		Mdl.UnSetParam(UnifiedInputs.element("BalloonMonths")); 
	 
	//***These parameters are in the ADCO UNIFIED interface, but will not be used. ***
	
	// Tuning Inputs - optional
    // Andrew Davidson strongly recommends that their File based tuning only be utilized,  
    // and that the end user should not concern themselves with passing tuning parameters 
    // to the interface. However, if the user wishes to pass their own tuning parameters 
    // the below code can be uncommented and used. It should be noted that the second
    // parameter being passed to "SetParam" will need to be created as MoSes variables.

	// Sensitivity Tuning Factors -- affects only Forecast() (only future projection)	
	//Mdl.SetParam(UnifiedInputs.element("TuningStartMonth"), (int) tuning_start_mth);
	//Mdl.SetParam(UnifiedInputs.element("TuningStartYear"), (int) tuning_start_yr);
	//Mdl.SetParam(UnifiedInputs.element("TuningEndMonth"), (int) tuning_end_mth);
	//Mdl.SetParam(UnifiedInputs.element("TuningEndYear"), (int) tuning_end_yr);
    //Mdl.SetParam(UnifiedInputs.element("TuningRampMonths"), (int) tuning_ramp_months);
    //Mdl.SetParam(UnifiedInputs.element("TuningFadeMonths"), (int) tuning_fade_months);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneScale"), (double) smm_tune_scale);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneBurnout"), (double) smm_tune_burnout);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneLag"), (double) smm_tune_lag);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneSlide"), (double) smm_tune_slide);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneTurnOver"), (double) smm_tune_turn_over);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneRefi"), (double) smm_tune_refi);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCashout"), (double) smm_tune_cashout);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCure"), (double) smm_tune_cure);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneAge"), (double) smm_tune_age);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneSATO"), (double) smm_tune_sato);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCATO"), (double) smm_tune_cato);
    //Mdl.SetParam(UnifiedInputs.element("Cashout_RM"), (double) cashout_rm);
    //Mdl.SetParam(UnifiedInputs.element("Cure_RM"), (double) cure_rm);
    //Mdl.SetParam(UnifiedInputs.element("Refi_RM"), (double) refi_rm);
    //Mdl.SetParam(UnifiedInputs.element("Turnover_RM"), (double) turnover_rm);
    //Mdl.SetParam(UnifiedInputs.element("Psi0"), (double) (double) psi_0);
    //Mdl.SetParam(UnifiedInputs.element("PsiT"), (double) (double) psi_T);

    // Model Tuning Factors -- affects both PreCalc()and Forecast()
    // (History and future projection) These are obsolete.
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneScaleModel"), (double) smm_tune_scale_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneBurnoutModel"), (double) smm_tune_burnout_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneLagModel"), (double) smm_tune_lag_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneSlideModel"), (double) smm_tune_slide_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneTurnOverModel"), (double) smm_tune_turn_over_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneRefiModel"), (double) smm_tune_refi_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCashoutModel"), (double) smm_tune_cashout_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCureModel"), (double) smm_tune_cure_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneAgeModel"), (double) smm_tune_age_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneSATOModel"), (double) smm_tune_sato_model);
    //Mdl.SetParam(UnifiedInputs.element("SmmTuneCATOModel"), (double) smm_tune_cato_model);     
	
	// These input parameters are not needed since the US Library has already handled projection 
    // length and valuation period offset. 
    // adco_cEnumElem UnifiedForecastMonths = UnifiedInputs.element("ForecastMonths");
	// adco_cEnumElem UnifiedForecastOffset = UnifiedInputs.element("ForecastOffset");
	// adco_cEnumElem UnifiedGuarantyFee = UnifiedInputs.element("GuarantyFee");
	// adco_cEnumElem UnifiedCurLtv = UnifiedInputs.element("Cur_LTV");
	// adco_cEnumElem UnifiedZipCode = UnifiedInputs.element("ZipCode");
	// adco_cEnumElem UnifiedCurFico = UnifiedInputs.element("CurFICO");
	// adco_cEnumElem UnifiedIsSecondMortgage = UnifiedInputs.element("IsSecondMortgage");
	// adco_cEnumElem UnifiedPrepayPenaltyPercent = UnifiedInputs.element("PrepayPenaltyPercent");
	// adco_cEnumElem UnifiedPoints = UnifiedInputs.element("Points");
	// adco_cEnumElem UnifiedCurveType = UnifiedInputs.element("Curve_Type");
	// adco_cEnumElem UnifiedHasOptionalPayment = UnifiedInputs.element("HasOptionalPayment");
	// adco_cEnumElem UnifiedPostResetScale = UnifiedInputs.element("PostResetScale");
	// adco_cEnumElem UnifiedPostResetScaleModel = UnifiedInputs.element("PostResetScaleModel");
	// For the non intex case: adco_cEnumElem UnifiedLookBackMonths = UnifiedInputs.element("LookBackMonths");
	// adco_cEnumElem UnifiedCurMinimumPayment = UnifiedInputs.element("CurMinimumPayment");
	// adco_cEnumElem UnifiedRecastPeriod = UnifiedInputs.element("RecastPeriod");
	// adco_cEnumElem UnifiedPayCap = UnifiedInputs.element("PayCap");
	// adco_cEnumElem UnifiedMaxNegAm = UnifiedInputs.element("MaxNegAm");
	// adco_cEnumElem UnifiedGenerateCashflows = UnifiedInputs.element("GenerateCashflows");
	// adco_cEnumElem UnifiedResetScale = UnifiedInputs.element("ResetScale");
	// adco_cEnumElem UnifiedResetScaleModel = UnifiedInputs.element("ResetScaleModel");
	// adco_cEnumElem UnifiedDealID = UnifiedInputs.element("DealID");
	// adco_cEnumElem UnifiedPoolID = UnifiedInputs.element("PoolID");
	// adco_cEnumElem UnifiedZeroVectorsFlag = UnifiedInputs.element("ZeroVectorsFlag");
	//****************************************************************************
	
    try 
    	{
        const adco_cEnumeration& LoanTypes = Mdl.GetList("LOANTYPES");
		xstring loan_type = LoanTypes.elem_name((int) Mdl.GetParam(UnifiedInputs.element("LoanType")));
        
        // Determine if CCY history is needed.
        CAdppmdl& histcache = pAdcoSystem->Adppmdl_factory("HISTCACHE");
	    const adco_cEnumeration& HistMap = Mdl.GetList("CCYHISTMAP");
	    const adco_cEnumElem HistElem = HistMap.elem_class((char *)loan_type.c_str());
	
	    adco_CParam histParam = histcache.GetParam(HistElem);
	    adco_TimeSeries * CCYHist = &(adco_TimeSeries&)histParam;
	    adco_TimeSeries * myCCYHist;
        myCCYHist = new adco_TimeSeries(*CCYHist);
        
        int ccy_last_hist_yr = myCCYHist->LastYear();
        int ccy_last_hist_mth = myCCYHist->LastPeriod();
       
        if (MonthNumberFromDate(histyr, histmth)  // if starting history date falls after
             > MonthNumberFromDate(ccy_last_hist_yr, ccy_last_hist_mth)) // last date of available CCY history data
        	{
            // Then we need to extend the CCY History, so call get_history()
            adco_TimeSeries * myCCYHist = NULL;

	        get_history(t, (char *)loan_type.c_str(), Mdl, myCCYHist, UnifiedResults,
					    histmth, histyr, msdyr, msdmth);
	
			adco_CParam CCYHistP(*myCCYHist);
			Mdl.SetParam(UnifiedInputs.element("CCYHistory"), CCYHistP);      
			}
       
		// Get 2 Year Libor/Swap rate History
		get_history(t, "2YRLIBOR", Mdl, myYr2Hist, UnifiedResults,
		       	 histmth, histyr, msdyr, msdmth);

		adco_CParam Yr2HistP(*myYr2Hist);
    	Mdl.SetParam(UnifiedInputs.element("2Yr_Hist"), Yr2HistP);

		// Get 10 Year Libor/Swap rate History
		get_history(t, "10YRLIBOR", Mdl, myYr10Hist, UnifiedResults,
					histmth, histyr, msdyr, msdmth);

		adco_CParam Yr10HistP(*myYr10Hist);
    	Mdl.SetParam(UnifiedInputs.element("10Yr_Hist"), Yr10HistP);
		}
		
	catch (adco_cError &error_detail)
		{throw;}
		
	try {Mdl.PreCalc();}
	
	catch(adco_cError &error_detail)
		{
		error_processing(error_detail.message());
		return;
		}
		
	// Forecast the two year libor rate			
    scen_rate_forecast(t, prepmt_forecast_defn,
				   2.0, offset, 0, max_maturity, libor2yr_forecast, 
				   shift_defn);

    for (idx = 0; idx < max_maturity; idx++)
		libor2yr_forecast[idx] = libor2yr_forecast[idx] * 1.012891 + 0.343203;
							
	adco_TimeSeries Fcst2YrLibor(curr_cpn_vecsize, lag_year, lag_month, ADCO_MONTHLY);
	
	try {Fcst2YrLibor.SetVal(lag_year, lag_month, libor2yr_forecast, curr_cpn_vecsize);}
	
	catch (adco_cError &error_detail)
		{throw;}
		
    adco_CParam Fcst2YrLiborP(Fcst2YrLibor);
	Mdl.SetParam(UnifiedInputs.element("2Yr_Fcst"), Fcst2YrLiborP);
	
	// Forecast the ten year libor rate			
    scen_rate_forecast(t, prepmt_forecast_defn,
				   10.0, offset, 0, max_maturity, libor10yr_forecast, 
				   shift_defn);
	
	for (idx = 0; idx < max_maturity; idx++)
		libor10yr_forecast[idx] = libor10yr_forecast[idx] * 1.069434 + 0.092266;	
						
	adco_TimeSeries Fcst10YrLibor(curr_cpn_vecsize, lag_year, lag_month, ADCO_MONTHLY);
	
	try {Fcst10YrLibor.SetVal(lag_year, lag_month, libor10yr_forecast, curr_cpn_vecsize);}
	
	catch (adco_cError &error_detail)
		{throw;}
		
    adco_CParam Fcst10YrLiborP(Fcst10YrLibor);
	Mdl.SetParam(UnifiedInputs.element("10Yr_Fcst"), Fcst10YrLiborP);
	
	// Forecast the index rate		
	if (asset_proj_defn != INTEX)
		{
		switch (index)// use index scalar 
			{
			case PAR_TSY_1YR:
		   	     scen_rate_forecast(t, prepmt_forecast_defn, 1.0, 
		                            offset, 0, max_maturity, index_forecast, 
		                            shift_defn); 
					break;
			case PAR_TSY_3YR:
		   	 	scen_rate_forecast(t, prepmt_forecast_defn, 3.0, 
		                            offset, 0, max_maturity, index_forecast, 
		                            shift_defn); 
					break;	
			case PAR_TSY_5YR:
					scen_rate_forecast(t, prepmt_forecast_defn, 5.0, 
		                            offset, 0, max_maturity, index_forecast, 
		                            shift_defn);  
					break;			
			default:
					throw FatalError("ADCO Model Failure: Unknown Index Type.");
					break;
			}	
		}
	else //asset_proj_defn == INTEX
		{
		switch (index)// use index scalar
			{
			case PAR_LIBOR_6M:
		   	     scen_rate_forecast(t, prepmt_forecast_defn, 0.5, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn); 
		
		             for (idx = 0; idx < max_maturity; idx++)
		             	index_forecast[idx] = index_forecast[idx] * 1.067413 + 0.391367;
		
				     break;
			case PAR_LIBOR_1YR:
		   	 	 scen_rate_forecast(t, prepmt_forecast_defn, 1.0, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn); 
		
		             for (idx = 0; idx < max_maturity; idx++)
		             	index_forecast[idx] = index_forecast[idx] * 1.039623 + 0.705342;
		
				     break;
			case PAR_TSY_1YR:
			case MTA_12:
		   	 	 scen_rate_forecast(t, prepmt_forecast_defn, 1.0, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn);  
					break;	
			case PAR_TSY_3YR:
		   	 	 scen_rate_forecast(t, prepmt_forecast_defn, 3.0, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn);  
					break;
			case PAR_TSY_5YR:
					 scen_rate_forecast(t, prepmt_forecast_defn, 5.0, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn);  
					break;		
			case COFI_11D:
					scen_rate_forecast(t, prepmt_forecast_defn, 0.25, 
		                               offset, 0, max_maturity, index_forecast, 
		                               shift_defn); 
		            
		            for (idx = 0; idx < max_maturity; idx++)
		             	index_forecast[idx] = index_forecast[idx] *  0.262146765 + 3.472036;
					break;		
			default:
					throw FatalError("ADCO Model Failure: Unknown Index Type.");
					break;
			}
		}	
    					
	adco_TimeSeries FcstIndex(curr_cpn_vecsize, lag_year, lag_month, ADCO_MONTHLY);
	
	try {FcstIndex.SetVal(lag_year, lag_month, index_forecast, curr_cpn_vecsize);}
	
	catch (adco_cError &error_detail)
		{throw;}
		
    adco_CParam FcstIndexP(FcstIndex);
	Mdl.SetParam(UnifiedInputs.element("IndexForecast"), FcstIndexP);
	
	// Forecast the WAC rates
	adco_TimeSeries * myWACForecast;
	myWACForecast = new adco_TimeSeries(max_maturity + 0, histyr, histmth, ADCO_MONTHLY);

	int idx = myWACForecast->GetIdx(histyr, histmth);	//should always be zero

	assert(idx == 0);

	double* WACptr = myWACForecast->Values() + idx;

	for (month = 0; month < max_maturity; month++)
		WACptr[month] = arm_wac_rates[month];
		
	adco_CParam WACfcst(*myWACForecast);
	Mdl.SetParam(UnifiedInputs.element("WacForecast"), WACfcst);
	
	try {Mdl.Forecast();}

	catch(adco_cError &error_detail)
		{
		error_processing(error_detail.message());
		return;
		}
	
	// Save the SMM results to a timeseries
	adco_CParam SMMrslt = Mdl.GetParam(UnifiedResults.element("SMM"));
	adco_TimeSeries* SMM = &(adco_TimeSeries&) SMMrslt;

	idx = SMM->GetIdx(histyr, histmth);	 //This offset is often zero, but could be non-zero.
	double* SMMptr = SMM->Values() + idx;

	int month = 0; 
	
	assert(sizeof(smm_forecast) >= max_maturity);
    
    // Save to SMM array
	for (month = 0; month < max_maturity && month < SMM->Length() - idx; month++)
  		smm_forecast[month] = SMMptr[month];
	
	// Setup cashout incentive SMM vector
	SMMrslt = Mdl.GetParam(UnifiedResults.element("CashoutSMM"));
	adco_TimeSeries* CashoutSMM = &(adco_TimeSeries&) SMMrslt;
	idx = CashoutSMM->GetIdx(histyr, histmth);	 
	double* CashoutSMMptr = CashoutSMM->Values() + idx;
	    
	for (month = 0; month < max_maturity && month < CashoutSMM->Length() - idx; month++)
  	   smm_cashout_forecast[month] = CashoutSMMptr[month];
        
    // Setup credit cure SMM vector
	SMMrslt = Mdl.GetParam(UnifiedResults.element("CreditCureSMM"));
	adco_TimeSeries* CreditCureSMM = &(adco_TimeSeries&) SMMrslt;
	idx = CreditCureSMM->GetIdx(histyr, histmth);	 
	double* CreditCureSMMptr = CreditCureSMM->Values() + idx;
	
	for (month = 0; month < max_maturity && month < CreditCureSMM->Length() - idx; month++)
  	   smm_credit_cure_forecast[month] = CreditCureSMMptr[month];

	// Setup refinance incentive SMM vector
	SMMrslt = Mdl.GetParam(UnifiedResults.element("RefiSMM"));
	adco_TimeSeries* RefiSMM = &(adco_TimeSeries&) SMMrslt;
	idx = RefiSMM->GetIdx(histyr, histmth);	 
	double* RefiSMMptr = RefiSMM->Values() + idx;
	    
	for (month = 0; month < max_maturity && month < RefiSMM->Length() - idx; month++)
  	   smm_refi_forecast[month] = RefiSMMptr[month];
        
    // Setup Turnover SMM vector
	SMMrslt = Mdl.GetParam(UnifiedResults.element("TurnoverSMM"));
	adco_TimeSeries* TurnoverSMM = &(adco_TimeSeries&) SMMrslt;
	idx = TurnoverSMM->GetIdx(histyr, histmth);	 
	double* TurnoverSMMptr = TurnoverSMM->Values() + idx;
	
	for (month = 0; month < max_maturity && month < TurnoverSMM->Length() - idx; month++)
  	   smm_turnover_forecast[month] = TurnoverSMMptr[month];
	
	if (process_adco_detail(t))
	    {
		string version = Mdl.GetParam(UnifiedResults.element("VERSION"));
		
		int pvcalc = 0;
		int nycalc = 0;
		int mvcalc = 0;
		
		if (prepmt_forecast_defn != EXPERIENCE)
			pvcalc = 1;
	
		if (prepmt_forecast_defn == MARKET_VALUE)
			mvcalc = 1;
	
		if (prepmt_forecast_defn == NET_YIELD)
			nycalc = 1;

		const adco_cEnumeration& LoanTypes = Mdl.GetList("LOANTYPES");
		xstring unified_loan_type = LoanTypes.elem_name((int)Mdl.GetParam(UnifiedInputs.element("LoanType")));
		xstring index_name = "";
		
        switch (index)// use index scalar 
			{
			case PAR_TSY_1YR:
				index_name = "PAR_TSY_1YR"; 
				break;
			case PAR_TSY_3YR:
				index_name = "PAR_TSY_3YR"; 
				break;	
			case PAR_TSY_5YR:
				index_name = "PAR_TSY_5YR"; 
				break;			
			case PAR_LIBOR_6M:
				index_name = "PAR_LIBOR_6M"; 
			 	break;
			case PAR_LIBOR_1YR:
				index_name = "PAR_LIBOR_1YR"; 
				break;
			case COFI_11D:
				index_name = "COFI_11D"; 
				break;		
			case MTA_12:
				index_name = "MTA_12"; 
				break;
			default:
				index_name = "Unknown";
				break;
			}

		xstring collat_type;
		
		if (subprime_defn == PRIME_COLLATERAL)
			collat_type = "Prime";
		else
			collat_type = "SubPrime";

		ADCOFile << endl
				 << "ADCO Prepayment Detail" << endl
				 << "AssetID," << asset_id << endl
				 << "Category," << category_id << endl
				 << "ModelType,Unified" << endl
				 << "ADCOVersion," << version << endl
				 << "ProjTaskLoop," << proj_task_loop_num << endl
				 << "CalYr," << cal_yr << endl
				 << "CalMth," << cal_mth << endl
				 << "PVCalc," << pvcalc << endl
				 << "NYCalc," << nycalc << endl
				 << "MVCalc," << mvcalc << endl
				 << "ShftdYldCv," << shift_defn << endl
				 << "UnifiedLoanType," << unified_loan_type << endl
				 << "Issuer," << issuer_type_name << endl
				 << "Index," << index_name << endl
				 << "CollatType," << collat_type << endl
				 << "OriginalFace," << original_face << endl
				 << "CurrentFace," << current_face << endl
				 << "OriginalLTV," << original_ltv << endl
				 << "RemTerm," << remaining_term << endl
				 << "Age," << age << endl
				 << "BalloonMths," << balloon_term << endl;
		
		if (asset_proj_defn != INTEX) // These are calculated values from regular proj, currently Intex does not supply this data
			ADCOFile << "PrepayPenaltyMths," << prepmt_penalty_mths << endl
					 << "InterestOnlyMonths," << interest_only_mths << endl;
		
		if (arm_flag == YES)
			ADCOFile << "ARMFirstResetAge," << arm_first_reset_age << endl
					 << "ARMMthsBetweenResets," << arm_reset_mths << endl
					 << "ARMMargin," << arm_margin << endl
					 << "ARMLifeCap," << arm_max_rate << endl
					 << "ARMLifeFloor," << arm_min_rate << endl
			         << "ARMResetCap," << arm_max_reset_period_rate << endl
			         << "ARMResetFloor," << arm_min_reset_period_rate << endl;
			
		ADCOFile << "HistYr," << histyr << endl
				 << "HistMth," << histmth << endl
				 << "Offset," << offset << endl
				 << "FMth,Coupon,2YrLiborRate,10YrLiborRate,SmmForecast,SmmCashForecast,SmmCureForecast,SmmRefiForecast,SmmTurnForecast" << endl;

		int month = 0;
		
		for (month = 0; month < remaining_term; month++)
			ADCOFile << month << ","
					 << arm_wac_rates[month] << ","
					 << libor2yr_forecast[month] << ","
					 << libor10yr_forecast[month] << ","
					 << smm_forecast[month] << ","
					 << smm_cashout_forecast[month] << ","
					 << smm_credit_cure_forecast[month] << ","
					 << smm_refi_forecast[month] << ","
					 << smm_turnover_forecast[month] << endl;
		} //endif detail
	
	// Recycle the model
	pAdcoSystem->Adppmdl_recycle(Mdl);
	
	} // Global Try

catch (adco_cError &error_detail)
	{
	error_processing(error_detail.message());
	return;
	}
}



	static ADCO_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (ADCO_ASSET_UDF::*dPXi) (int);
typedef double (ADCO_ASSET_UDF::*dPXid) (int, double);
typedef double (ADCO_ASSET_UDF::*dPF) ();
typedef double (ADCO_ASSET_UDF::*dPFd) (double);
typedef int (ADCO_ASSET_UDF::*iPF) ();
typedef int (ADCO_ASSET_UDF::*iPFi) (int);
typedef xstring (ADCO_ASSET_UDF::*sPF) ();
typedef xstring (ADCO_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData ADCO_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "cal_mth", "adco_asset_cal_mth",  "cal_mth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_cal_mth, 'E','N', '3', 'P', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(2, "cal_yr", "adco_asset_cal_yr",  "cal_yr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_cal_yr, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(3, "cal_yr_relative", "adco_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_cal_yr_relative, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(4, "date", "adco_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(5, "finalize", "adco_asset_finalize",  "finalize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_finalize, 'E','Y', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(6, "get_prepmt_rate", "adco_asset_get_prepmt_rate",  "get_prepmt_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_get_prepmt_rate, 'E','Y', '3', 'P', (size_t)&modelOffset->get_prepmt_rate),
	CashFlowCommonData(7, "initialize", "adco_asset_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_initialize, 'E','Y', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(8, "process_adco_detail", "adco_asset_process_adco_detail",  "process_adco_detail",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::adco_asset_process_adco_detail, 'E','Y', '3', 'P', (size_t)&modelOffset->process_adco_detail),
	CashFlowCommonData(9, "startup", "adco_asset_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ADCO_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* ADCO_ASSET::mCFStaticData[] = {
	&ADCO_ASSET::mCFStaticData_0[0],
	&ADCO_ASSET::mCFStaticData_0[1],
	&ADCO_ASSET::mCFStaticData_0[2],
	&ADCO_ASSET::mCFStaticData_0[3],
	&ADCO_ASSET::mCFStaticData_0[4],
	&ADCO_ASSET::mCFStaticData_0[5],
	&ADCO_ASSET::mCFStaticData_0[6],
	&ADCO_ASSET::mCFStaticData_0[7],
	&ADCO_ASSET::mCFStaticData_0[8],
	&ADCO_ASSET::mCFStaticData_0[9],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for abs_mh_defn                                                                                       
	const ChoicePair abs_mh_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::RENTAL, "Rental")
		,ChoicePair(StrEnum::TRAILER, "Trailer")
		,ChoicePair(StrEnum::OWNER, "Owner")
		,ChoicePair(StrEnum::UNKNOWN, "Unknown")
	};
	const EnumList abs_mh_defnEnumList(4, abs_mh_defnChoicePairs);

	// EnumList for abs_mh_vintage_defn                                                                                       
	const ChoicePair abs_mh_vintage_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NEW, "New")
		,ChoicePair(StrEnum::OLD, "Old")
		,ChoicePair(StrEnum::UNKNOWN, "Unknown")
	};
	const EnumList abs_mh_vintage_defnEnumList(3, abs_mh_vintage_defnChoicePairs);

	// EnumList for abs_mh_width_defn                                                                                       
	const ChoicePair abs_mh_width_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SINGLE_SIZE, "Single Size")
		,ChoicePair(StrEnum::DOUBLE_SIZE, "Double Size")
		,ChoicePair(StrEnum::UNKNOWN, "Unknown")
	};
	const EnumList abs_mh_width_defnEnumList(3, abs_mh_width_defnChoicePairs);

	// EnumList for abs_prepmt_defn                                                                                       
	const ChoicePair abs_prepmt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AUTO, "Auto")
		,ChoicePair(StrEnum::FIXED_HOME_EQUITY_LOAN, "Fixed Home Equity Loan")
		,ChoicePair(StrEnum::ARM_HOME_EQUITY_LOAN, "ARM Home Equity Loan")
		,ChoicePair(StrEnum::MANUFACTURED_HOUSING, "Manufactured Housing")
	};
	const EnumList abs_prepmt_defnEnumList(4, abs_prepmt_defnChoicePairs);

	// EnumList for adjustable_rate_defn                                                                                       
	const ChoicePair adjustable_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NON_CONVERTIBLE, "Non Convertible")
		,ChoicePair(StrEnum::CONVERTIBLE, "Convertible")
	};
	const EnumList adjustable_rate_defnEnumList(2, adjustable_rate_defnChoicePairs);

	// EnumList for arm_flag                                                                                       
	const ChoicePair arm_flagChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList arm_flagEnumList(2, arm_flagChoicePairs);

	// EnumList for arm_index_name                                                                                       
	const ChoicePair arm_index_nameChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::LIBOR_1_MONTH, "LIBOR 1 Month")
		,ChoicePair(StrEnum::LIBOR_3_MONTH, "LIBOR 3 Month")
		,ChoicePair(StrEnum::LIBOR_6_MONTH, "LIBOR 6 Month")
		,ChoicePair(StrEnum::LIBOR_1_YEAR, "LIBOR 1 Year")
		,ChoicePair(StrEnum::GOVT_3_MONTH, "Govt 3 Month")
		,ChoicePair(StrEnum::GOVT_1_YEAR, "Govt 1 Year")
		,ChoicePair(StrEnum::GOVT_5_YEAR, "Govt 5 Year")
		,ChoicePair(StrEnum::GOVT_7_YEAR, "Govt 7 Year")
		,ChoicePair(StrEnum::GOVT_10_YEAR, "Govt 10 Year")
		,ChoicePair(StrEnum::COF_11_DIST, "COF 11 Dist")
		,ChoicePair(StrEnum::BANK_PRIME, "Bank Prime")
		,ChoicePair(StrEnum::GOVT_3_YEAR, "Govt 3 Year")
		,ChoicePair(StrEnum::GOVT_2_YEAR, "Govt 2 Year")
		,ChoicePair(StrEnum::GOVT_6_MONTH, "Govt 6 Month")
		,ChoicePair(StrEnum::GOVT_30_YEAR, "Govt 30 Year")
		,ChoicePair(StrEnum::GEN_CONTRACT, "Gen Contract")
		,ChoicePair(StrEnum::GEN_COF, "Gen COF")
		,ChoicePair(StrEnum::CD_6_MONTH, "CD 6 Month")
		,ChoicePair(StrEnum::MONEY_MKT, "Money Mkt")
		,ChoicePair(StrEnum::UNKNOWN, "Unknown")
	};
	const EnumList arm_index_nameEnumList(20, arm_index_nameChoicePairs);

	// EnumList for asset_detail_rpt_defn                                                                                       
	const ChoicePair asset_detail_rpt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList asset_detail_rpt_defnEnumList(2, asset_detail_rpt_defnChoicePairs);

	// EnumList for asset_proj_defn                                                                                       
	const ChoicePair asset_proj_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::USLIB, "USLIB")
		,ChoicePair(StrEnum::INTEX, "Intex")
	};
	const EnumList asset_proj_defnEnumList(2, asset_proj_defnChoicePairs);

	// EnumList for hel_issuer                                                                                       
	const ChoicePair hel_issuerChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AFC, "AFC")
		,ChoicePair(StrEnum::ADV, "ADV")
		,ChoicePair(StrEnum::EC, "EC")
		,ChoicePair(StrEnum::GE, "GE")
		,ChoicePair(StrEnum::MON, "MON")
		,ChoicePair(StrEnum::UFC, "UFC")
		,ChoicePair(StrEnum::INM, "INM")
		,ChoicePair(StrEnum::CON, "CON")
		,ChoicePair(StrEnum::UNK, "UNK")
	};
	const EnumList hel_issuerEnumList(9, hel_issuerChoicePairs);

	// EnumList for historical_loan_size_effect_defn                                                                                       
	const ChoicePair historical_loan_size_effect_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList historical_loan_size_effect_defnEnumList(2, historical_loan_size_effect_defnChoicePairs);

	// EnumList for mbs_collateral_defn                                                                                       
	const ChoicePair mbs_collateral_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FNMA, "FNMA")
		,ChoicePair(StrEnum::GNMA, "GNMA")
		,ChoicePair(StrEnum::GNMA2, "GNMA2")
		,ChoicePair(StrEnum::FHLMC, "FHLMC")
		,ChoicePair(StrEnum::WHOLE_LOAN, "Whole Loan")
		,ChoicePair(StrEnum::RELO, "RELO")
		,ChoicePair(StrEnum::ALT_A, "ALT A")
		,ChoicePair(StrEnum::COFI, "COFI")
	};
	const EnumList mbs_collateral_defnEnumList(8, mbs_collateral_defnChoicePairs);

	// EnumList for mbs_prepmt_defn                                                                                       
	const ChoicePair mbs_prepmt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::ARM, "ARM")
		,ChoicePair(StrEnum::HYBRID, "Hybrid")
	};
	const EnumList mbs_prepmt_defnEnumList(3, mbs_prepmt_defnChoicePairs);

	// EnumList for prepmt_forecast_defn                                                                                       
	const ChoicePair prepmt_forecast_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EXPERIENCE, "Experience")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
	};
	const EnumList prepmt_forecast_defnEnumList(3, prepmt_forecast_defnChoicePairs);

	// EnumList for prepmt_model_defn                                                                                       
	const ChoicePair prepmt_model_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MBS, "MBS")
		,ChoicePair(StrEnum::ABS, "ABS")
	};
	const EnumList prepmt_model_defnEnumList(2, prepmt_model_defnChoicePairs);

	// EnumList for pv_timing                                                                                       
	const ChoicePair pv_timingChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::END_OF_MONTH, "End of Month")
		,ChoicePair(StrEnum::BEFORE_PREPAYMENTS, "Before Prepayments")
		,ChoicePair(StrEnum::AFTER_PREPAYMENTS, "After Prepayments")
		,ChoicePair(StrEnum::AFTER_PREPAYMENTS_AND_DECREMENTS, "After Prepayments and Decrements")
	};
	const EnumList pv_timingEnumList(4, pv_timingChoicePairs);

	// EnumList for shift_defn                                                                                       
	const ChoicePair shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::SPOT_SHIFT, "Spot Shift")
		,ChoicePair(StrEnum::YIELD_SHIFT, "Yield Shift")
	};
	const EnumList shift_defnEnumList(3, shift_defnChoicePairs);

	// EnumList for subprime_defn                                                                                       
	const ChoicePair subprime_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SUBPRIME_COLLATERAL, "Subprime Collateral")
		,ChoicePair(StrEnum::PRIME_COLLATERAL, "Prime Collateral")
	};
	const EnumList subprime_defnEnumList(2, subprime_defnChoicePairs);

	// EnumList for use_eom_scen_rates                                                                                       
	const ChoicePair use_eom_scen_ratesChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_eom_scen_ratesEnumList(2, use_eom_scen_ratesChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace ADCO_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(ADCO_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(ADCO_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace ADCO_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void ADCO_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> ADCO_ASSET::mgr_;

	Attribute::Descriptor ADCO_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"abs_mh_defn", -1, (size_t)&modelOffset->abs_mh_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &abs_mh_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"abs_mh_vintage_defn", -1, (size_t)&modelOffset->abs_mh_vintage_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &abs_mh_vintage_defnEnumList, Feature(true)),
	Descriptor(2, Attribute::STR_ENUM,	"abs_mh_width_defn", -1, (size_t)&modelOffset->abs_mh_width_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &abs_mh_width_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::STR_ENUM,	"abs_prepmt_defn", -1, (size_t)&modelOffset->abs_prepmt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &abs_prepmt_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::STR_ENUM,	"adjustable_rate_defn", -1, (size_t)&modelOffset->adjustable_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &adjustable_rate_defnEnumList, Feature(true)),
	Descriptor(5, Attribute::INT,	"age", -1, (size_t)&modelOffset->age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"arm_first_reset_age", -1, (size_t)&modelOffset->arm_first_reset_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STR_ENUM,	"arm_flag", -1, (size_t)&modelOffset->arm_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &arm_flagEnumList, Feature(true)),
	Descriptor(8, Attribute::STR_ENUM,	"arm_index_name", -1, (size_t)&modelOffset->arm_index_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &arm_index_nameEnumList, Feature(true)),
	Descriptor(9, Attribute::INT,	"arm_lookback_mths", -1, (size_t)&modelOffset->arm_lookback_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"arm_max_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arm_max_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"arm_max_reset_period_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arm_max_reset_period_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"arm_min_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arm_min_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"arm_min_reset_period_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arm_min_reset_period_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::INT,	"arm_reset_mths", -1, (size_t)&modelOffset->arm_reset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::INT,	"arm_reset_period", -1, (size_t)&modelOffset->arm_reset_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::DOUBLE,	"arm_reset_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arm_reset_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STRING,	"asset_detail_rpt_cusip_id", -1, (size_t)&modelOffset->asset_detail_rpt_cusip_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STR_ENUM,	"asset_detail_rpt_defn", -1, (size_t)&modelOffset->asset_detail_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"asset_proj_defn", -1, (size_t)&modelOffset->asset_proj_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_proj_defnEnumList, Feature(true)),
	Descriptor(23, Attribute::INT,	"balloon_term", -1, (size_t)&modelOffset->balloon_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"coupon", Descriptor::NOT_INDEXED, (size_t)&modelOffset->coupon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::DOUBLE,	"credit_score", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_score,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::DOUBLE,	"current_face", Descriptor::NOT_INDEXED, (size_t)&modelOffset->current_face,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::INT,	"existing_asset_indicator", -1, (size_t)&modelOffset->existing_asset_indicator,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STR_ENUM,	"hel_issuer", -1, (size_t)&modelOffset->hel_issuer,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hel_issuerEnumList, Feature(true)),
	Descriptor(31, Attribute::STR_ENUM,	"historical_loan_size_effect_defn", -1, (size_t)&modelOffset->historical_loan_size_effect_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &historical_loan_size_effect_defnEnumList, Feature(true)),
	Descriptor(32, Attribute::STRING,	"history_directory", -1, (size_t)&modelOffset->history_directory,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::INT,	"interest_only_mths", -1, (size_t)&modelOffset->interest_only_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::STRING,	"intex_dealname", -1, (size_t)&modelOffset->intex_dealname,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::ARRAY_DOUBLE,	"loan_purp", -1, (size_t)&modelOffset->loan_purp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(3)),
	Descriptor(36, Attribute::STR_ENUM,	"mbs_collateral_defn", -1, (size_t)&modelOffset->mbs_collateral_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mbs_collateral_defnEnumList, Feature(true)),
	Descriptor(37, Attribute::STR_ENUM,	"mbs_prepmt_defn", -1, (size_t)&modelOffset->mbs_prepmt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mbs_prepmt_defnEnumList, Feature(true)),
	Descriptor(38, Attribute::ARRAY_DOUBLE,	"occupancy", -1, (size_t)&modelOffset->occupancy,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(4)),
	Descriptor(39, Attribute::INT,	"offset_mths", -1, (size_t)&modelOffset->offset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"original_face", Descriptor::NOT_INDEXED, (size_t)&modelOffset->original_face,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"original_ltv", Descriptor::NOT_INDEXED, (size_t)&modelOffset->original_ltv,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::INT,	"original_term", -1, (size_t)&modelOffset->original_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::INT,	"origination_mth", -1, (size_t)&modelOffset->origination_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::INT,	"origination_yr", -1, (size_t)&modelOffset->origination_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::INT,	"pool_id", -1, (size_t)&modelOffset->pool_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STR_ENUM,	"prepmt_forecast_defn", -1, (size_t)&modelOffset->prepmt_forecast_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_forecast_defnEnumList, Feature(true)),
	Descriptor(47, Attribute::STR_ENUM,	"prepmt_model_defn", -1, (size_t)&modelOffset->prepmt_model_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_model_defnEnumList, Feature(true)),
	Descriptor(48, Attribute::INT,	"prepmt_penalty_mths", -1, (size_t)&modelOffset->prepmt_penalty_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::ARRAY_DOUBLE,	"prepmt_rates", -1, (size_t)&modelOffset->prepmt_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(1)),
	Descriptor(50, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::ARRAY_DOUBLE,	"property_types", -1, (size_t)&modelOffset->property_types,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(3)),
	Descriptor(52, Attribute::STR_ENUM,	"pv_timing", -1, (size_t)&modelOffset->pv_timing,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pv_timingEnumList, Feature(true)),
	Descriptor(53, Attribute::DOUBLE,	"regional_hpi", Descriptor::NOT_INDEXED, (size_t)&modelOffset->regional_hpi,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::INT,	"remaining_term", -1, (size_t)&modelOffset->remaining_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::DOUBLE,	"servicing_fee", Descriptor::NOT_INDEXED, (size_t)&modelOffset->servicing_fee,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::STR_ENUM,	"shift_defn", -1, (size_t)&modelOffset->shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &shift_defnEnumList, Feature(true)),
	Descriptor(57, Attribute::ARRAY_DOUBLE,	"states", -1, (size_t)&modelOffset->states,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(53)),
	Descriptor(58, Attribute::STR_ENUM,	"subprime_defn", -1, (size_t)&modelOffset->subprime_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &subprime_defnEnumList, Feature(true)),
	Descriptor(59, Attribute::STR_ENUM,	"use_eom_scen_rates", -1, (size_t)&modelOffset->use_eom_scen_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_eom_scen_ratesEnumList, Feature(true)),
	Descriptor(60, Attribute::INT,	"valn_date_offset_mths", -1, (size_t)&modelOffset->valn_date_offset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::SCALAR_INT,	"asset_detail_rpt_flag", -1, (size_t)&modelOffset->asset_detail_rpt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_asset_detail_rpt_flag)),
	Descriptor(63, Attribute::SCALAR_INT,	"index", -1, (size_t)&modelOffset->index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_index)),
	Descriptor(64, Attribute::SCALAR_INT,	"issuer", -1, (size_t)&modelOffset->issuer,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_issuer)),
	Descriptor(65, Attribute::SCALAR_INT,	"loan_type", -1, (size_t)&modelOffset->loan_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_loan_type)),
	Descriptor(66, Attribute::SCALAR_INT,	"orig_proj_start_mth", -1, (size_t)&modelOffset->orig_proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_orig_proj_start_mth)),
	Descriptor(67, Attribute::SCALAR_INT,	"orig_proj_start_yr", -1, (size_t)&modelOffset->orig_proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_orig_proj_start_yr)),
	Descriptor(68, Attribute::SCALAR_STRING,	"output_file", -1, (size_t)&modelOffset->output_file,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ADCO_ASSET_UDF::adco_asset_output_file)),
	Descriptor(69, Attribute::SCALAR_STRING,	"output_path", -1, (size_t)&modelOffset->output_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ADCO_ASSET_UDF::adco_asset_output_path)),
	Descriptor(70, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ADCO_ASSET_UDF::adco_asset_proj_date_adj)),
	Descriptor(71, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_proj_start_mth)),
	Descriptor(72, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_proj_start_yr)),
	Descriptor(73, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ADCO_ASSET_UDF::adco_asset_start_period)),
	};

	Attribute::Descriptor* ADCO_ASSET::descriptorTable[] = {
	&ADCO_ASSET::descriptor_0[0],
	&ADCO_ASSET::descriptor_0[1],
	&ADCO_ASSET::descriptor_0[2],
	&ADCO_ASSET::descriptor_0[3],
	&ADCO_ASSET::descriptor_0[4],
	&ADCO_ASSET::descriptor_0[5],
	&ADCO_ASSET::descriptor_0[6],
	&ADCO_ASSET::descriptor_0[7],
	&ADCO_ASSET::descriptor_0[8],
	&ADCO_ASSET::descriptor_0[9],
	&ADCO_ASSET::descriptor_0[10],
	&ADCO_ASSET::descriptor_0[11],
	&ADCO_ASSET::descriptor_0[12],
	&ADCO_ASSET::descriptor_0[13],
	&ADCO_ASSET::descriptor_0[14],
	&ADCO_ASSET::descriptor_0[15],
	&ADCO_ASSET::descriptor_0[16],
	&ADCO_ASSET::descriptor_0[17],
	&ADCO_ASSET::descriptor_0[18],
	&ADCO_ASSET::descriptor_0[19],
	&ADCO_ASSET::descriptor_0[20],
	&ADCO_ASSET::descriptor_0[21],
	&ADCO_ASSET::descriptor_0[22],
	&ADCO_ASSET::descriptor_0[23],
	&ADCO_ASSET::descriptor_0[24],
	&ADCO_ASSET::descriptor_0[25],
	&ADCO_ASSET::descriptor_0[26],
	&ADCO_ASSET::descriptor_0[27],
	&ADCO_ASSET::descriptor_0[28],
	&ADCO_ASSET::descriptor_0[29],
	&ADCO_ASSET::descriptor_0[30],
	&ADCO_ASSET::descriptor_0[31],
	&ADCO_ASSET::descriptor_0[32],
	&ADCO_ASSET::descriptor_0[33],
	&ADCO_ASSET::descriptor_0[34],
	&ADCO_ASSET::descriptor_0[35],
	&ADCO_ASSET::descriptor_0[36],
	&ADCO_ASSET::descriptor_0[37],
	&ADCO_ASSET::descriptor_0[38],
	&ADCO_ASSET::descriptor_0[39],
	&ADCO_ASSET::descriptor_0[40],
	&ADCO_ASSET::descriptor_0[41],
	&ADCO_ASSET::descriptor_0[42],
	&ADCO_ASSET::descriptor_0[43],
	&ADCO_ASSET::descriptor_0[44],
	&ADCO_ASSET::descriptor_0[45],
	&ADCO_ASSET::descriptor_0[46],
	&ADCO_ASSET::descriptor_0[47],
	&ADCO_ASSET::descriptor_0[48],
	&ADCO_ASSET::descriptor_0[49],
	&ADCO_ASSET::descriptor_0[50],
	&ADCO_ASSET::descriptor_0[51],
	&ADCO_ASSET::descriptor_0[52],
	&ADCO_ASSET::descriptor_0[53],
	&ADCO_ASSET::descriptor_0[54],
	&ADCO_ASSET::descriptor_0[55],
	&ADCO_ASSET::descriptor_0[56],
	&ADCO_ASSET::descriptor_0[57],
	&ADCO_ASSET::descriptor_0[58],
	&ADCO_ASSET::descriptor_0[59],
	&ADCO_ASSET::descriptor_0[60],
	&ADCO_ASSET::descriptor_0[61],
	&ADCO_ASSET::descriptor_0[62],
	&ADCO_ASSET::descriptor_0[63],
	&ADCO_ASSET::descriptor_0[64],
	&ADCO_ASSET::descriptor_0[65],
	&ADCO_ASSET::descriptor_0[66],
	&ADCO_ASSET::descriptor_0[67],
	&ADCO_ASSET::descriptor_0[68],
	&ADCO_ASSET::descriptor_0[69],
	&ADCO_ASSET::descriptor_0[70],
	&ADCO_ASSET::descriptor_0[71],
	&ADCO_ASSET::descriptor_0[72],
	&ADCO_ASSET::descriptor_0[73],
	nullptr};
	const size_t ADCO_ASSET::sDescriptorCount = 74;

//factory
ADCO_ASSET* ADCO_ASSET::makeThis(int isSubmodel, ModelClass* owner, ADCO_ASSET* peer, 
						int mainRebase, const xstring &name, ADCO_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ADCO_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ADCO_ASSET");
#endif
	ADCO_ASSET* newP = (ADCO_ASSET*)new ADCO_ASSET_UDF
   	  ("adco_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
ADCO_ASSET_persistent_object* ADCO_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, ADCO_ASSET* peer, 
							int mainRebase, const xstring &name, ADCO_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ADCO_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ADCO_ASSET_persistent_object");
#endif
	ADCO_ASSET_persistent_object* newP = (ADCO_ASSET_persistent_object*)new ADCO_ASSET_persistent_object
   	  ("adco_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			ADCO_ASSET_persistent_object* pd = dynamic_cast<ADCO_ASSET_persistent_object*>(product);
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

typedef double (ADCO_ASSET_UDF::*dPF) ();
typedef double (ADCO_ASSET_UDF::*dPFd) (double);
typedef int (ADCO_ASSET_UDF::*iPF) ();
typedef int (ADCO_ASSET_UDF::*iPFi) (int);
typedef xstring (ADCO_ASSET_UDF::*sPF) ();
typedef xstring (ADCO_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
ADCO_ASSET::ADCO_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, epl(company_liab_epl)
	, intex(company_asset_intex)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ADCO_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
ADCO_ASSET::ADCO_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(9, ADCO_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, epl(company_liab_epl)
	, intex(company_asset_intex)
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

#ifdef __CREATE_INTEX_ASSET_CLASS_
       company_asset_intex = 0;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
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

	for (int cf_no = 1; cf_no <= 9; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ADCO_ASSET_UDF::*dPXi2) (int, int);
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

	  void ADCO_ASSET::Set_loan_purp(const long index, const double &value) { loan_purp[index] = value; } // set Lapse rates for loan_purp
	  void ADCO_ASSET::Set_occupancy(const long index, const double &value) { occupancy[index] = value; } // set Lapse rates for occupancy
	  void ADCO_ASSET::Set_prepmt_rates(const long index, const double &value) { prepmt_rates[index] = value; } // set Lapse rates for prepmt_rates
	  void ADCO_ASSET::Set_property_types(const long index, const double &value) { property_types[index] = value; } // set Lapse rates for property_types
	  void ADCO_ASSET::Set_states(const long index, const double &value) { states[index] = value; } // set Lapse rates for states

 void ADCO_ASSET::copy_names() {

#ifdef __CREATE_INTEX_ASSET_CLASS_
		company_asset_intex = (INTEX_ASSET*)(findUnique("company|asset|intex"));
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
 }
//copy_names END@2


 void ADCO_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int ADCO_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& ADCO_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double ADCO_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int ADCO_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double ADCO_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double ADCO_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void ADCO_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ADCO_ASSET_persistent_object::write(long include_submodels) {
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

	void ADCO_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ADCO_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ADCO_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	ADCO_ASSET_persistent_object::~ADCO_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool ADCO_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void ADCO_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void ADCO_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void ADCO_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ADCO_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ADCO_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* ADCO_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* ADCO_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* ADCO_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char ADCO_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void ADCO_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
ADCO_ASSET_persistent_object::ADCO_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			ADCO_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(ADCO_ASSET::sm_bond_is)
	, sm_bond_pv(ADCO_ASSET::sm_bond_pv)
	, sm_bond_ym(ADCO_ASSET::sm_bond_ym)
	, sm_mtg_is(ADCO_ASSET::sm_mtg_is)
	, sm_mtg_pv(ADCO_ASSET::sm_mtg_pv)
	, sm_mtg_ym(ADCO_ASSET::sm_mtg_ym)

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
ADCO_ASSET::~ADCO_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void ADCO_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void ADCO_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void ADCO_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void ADCO_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void ADCO_ASSET::start_of_projection() {
}
//start_of_projection END@2

void ADCO_ASSET::end_of_projection() {
}
//end_of_projection END@2

void ADCO_ASSET::start_of_layer() {
}


void ADCO_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void ADCO_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void ADCO_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void ADCO_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> ADCO_ASSET::ddfVector;
BitArray ADCO_ASSET::dataVariables(74);
bool ADCO_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool ADCO_ASSET::writeClassInfo = true;

void ADCO_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, ADCO_ASSET::descriptor_0>::dT = ADCO_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, ADCO_ASSET::descriptor_0>::dT = ADCO_ASSET::descriptor_0;

