
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
#include "ModelClass\util_rafm_udf.h"
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
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"
#include "ModelClass\sfas133_gaap.h"
#include "ModelClass\sfas97rd_gaap.h"
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

//typedef ifstream mpinput;//Gen2 - 9/6/2024 - comment out typedef
ifstream copy_mp_data;//Gen2 - 9/6/2024 - replace mpinput with full definition
sowfoutput custom_file_naming;

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
#ifndef util_rafm_TableDefs
#define util_rafm_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection UTIL_RAFM::TTHC;
void UTIL_RAFM::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - copy_data_files
// Copy data files                                                                                             
// Column:COPY_DATA_FILES
//========================================================
double UTIL_RAFM_UDF::util_rafm_copy_data_files(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"copy_data_files",t);
}



//^^^

#line 1 "copy_data_files.UTIL_RAFM.for"
xstring input_data_file_name = replaceWildcards(input_data_filename + ".csv");
xstring working_data_file_name = replaceWildcards(working_data_filename + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv");

struct stat buffer;
int stat_val = stat(input_data_file_name.c_str(), &buffer);

//20220613 STW: stop the run if the job name is greater than the threshold
xstring job_name = replaceWildcards("<*job_name*>");
int job_name_length = job_name.length();

//20220721 JYL: check length for the total of file path and job name
xstring path = replaceWildcards("<*project_directory*>");
int path_length = path.length();

if ((job_name_length + path_length) > max_path_job_name_length_aig)
{
	throw FatalError("Path and Job name is longer than the threshold, 'max_path_job_name_length_aig', please rename the run and submit again.");
}
//END 20220721 JYL

// Return Error if data file does not exist
if (stat_val < 0)
	throw FatalError("The data file specified in the field 'input_data_filename' does not exist for projection set loop " + xstring(proj_set_loop_num) + ", sub loop: " + xstring(proj_set_sub_loop_num) + ". Please check your data: " + input_data_file_name);

// 20190424 STW add code fix from WTW
// WTW - ADDED TO CREATE DIRECTORY ON-THE-FLY FOR INPUT DATA FILES
int check = CreateDirectory(get_file_path(working_data_file_name), NULL);

if (check == 0 && GetLastError() != ERROR_ALREADY_EXISTS)
       throw FatalError("Working data directory could not be created.");
//END OF ADDED CODE 4-9-2019

//Must use I/O streams to copy data, as this allows RAFM to 'recognize' the file and use for grid computing
if (!copy_mp_data.is_open())
	{
   	copy_mp_data.setf(ios::fixed);
	copy_mp_data.precision(12);
	copy_mp_data.open(input_data_file_name, ios::in);
	
	string line = "";

	while (getline(copy_mp_data, line))
		mp_data.push_back(line);

	copy_mp_data.close();
	}

if (!custom_file_naming.is_open())
	{
   	custom_file_naming.setf(ios::fixed);
	custom_file_naming.precision(12);
	custom_file_naming.open(working_data_file_name);

	for (int i = 0; i < mp_data.size(); i++)
		custom_file_naming << mp_data[i] <<endl;

	custom_file_naming.close();
	}

mp_data.resize(0);

return NO_AVG;

}


//@@ END

//@@ START - copy_output_files
// Copy Output Files                                                                                             
// Column:COPY_OUTPUT_FILES
//========================================================
double UTIL_RAFM_UDF::util_rafm_copy_output_files(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"copy_output_files",t);
}



//^^^

#line 1 "copy_output_files.UTIL_RAFM.for"
xstring working_output_file_name = "";
xstring final_output_file_name = "";
xstring model_class_extension = "";
xstring short_model_class_extension = "";	//20190212	STW: initialize a short version of extension

//Added missing file detection and failure.  MCHING 20220317
bool found_model_output = false; 

for (int i = 1; i <= 10; i++)
	{
	//i = 1: company output
	//i = 2: seg output
	//i = 3: fia output
	//i = 4: fia_account output
	//i = 5: fia_bond_portfolio_aig output
	//i = 6: bond output	
	//i = 7: bond_cf output
	//i = 8: mtg output
	//i = 9: mtg_cf output
	//i = 10: inv_strategy output
	//Add more submodel output as needed
	switch (i)
		{
		case 1: 
			{
			model_class_extension = "~company.csv";
			short_model_class_extension = "~company.csv";	//20190212	STW: assign value to short version of extension
			}
			break;
		case 2: 
			{
			model_class_extension = "~company~seg.csv";
			short_model_class_extension = "~seg.csv";	//20190212	STW: assign value to short version of extension
			}
			break;
		case 3: 
			{
			model_class_extension = "~company~liab~fia.csv";
			short_model_class_extension = "~fia.csv";	//20190212	STW: assign value to short version of extension
			}
			break;
		case 4: 
			{
			model_class_extension = "~company~liab~fia~fia_account.csv";
			short_model_class_extension = "~fia_account.csv";	//20190212	STW: assign value to short version of extension
			}
			break;
		case 5: 
			{
			model_class_extension = "~company~liab~fia~fia_bond_portfolio_aig.csv";
			short_model_class_extension = "~fia_bond_portfolio_aig.csv";	//20190212	STW: assign value to short version of extension
			}
			break;
		case 6://JYL 20230405: add bond, bond_cf, mtg, mtg_cf, and inv_strategy levels to print AVG and PVDE output
			{
			model_class_extension = "~company~asset~bond.csv";
			short_model_class_extension = "~bond.csv";
			break;
			}
		case 7:
			{
			model_class_extension = "~company~asset~bond~bond_cf.csv";
			short_model_class_extension = "~bond_cf.csv";
			break;
			}
		case 8:
			{
			model_class_extension = "~company~asset~mtg.csv";
			short_model_class_extension = "~mtg.csv";
			break;
			}
		case 9:
			{
			model_class_extension = "~company~asset~mtg~mtg_cf.csv";
			short_model_class_extension = "~mtg_cf.csv";
			break;
			}
		case 10:
			{
			model_class_extension = "~company~inv_strategy.csv";
			short_model_class_extension = "~inv_strategy.csv";
			break;
			}
		}

	working_output_file_name
	= replaceWildcards(output_location_aig + "@" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + model_class_extension);

	final_output_file_name
	= replaceWildcards(base_output_filename + short_model_class_extension);	//20190212	STW: attach short version of extension to output file name

	struct stat buffer;
	int stat_val = stat(working_output_file_name.c_str(), &buffer);

	//Added missing file detection and failure.  MCHING 20220317
	if (stat_val < 0) //model class output is not produced, skip
	{
		if ( i == 3 ) // fia_liab
		{
			makeRunLogYellow();
			log_strm << "Warning: Could not find economic liability model output file: " << working_output_file_name << endl;
		}

		continue;
	}
	else
	{		
		found_model_output = true;
	}
	// END MCHING 20220317

	// 20190212 STW (START): Stop creating new folder for output inside the job folder
	/*
	//Required to write output files to a different directory on-the-fly
	int check = CreateDirectory(replaceWildcards(custom_output_directory), NULL);

	if (check == 0 && GetLastError() != ERROR_ALREADY_EXISTS)
		throw FatalError("Output directory could not be created.");
	*/
	// 20190212 STW (END)

	// 20200723 MTC - vGrid update
	working_output_file_name.to_lower();
	final_output_file_name.to_lower();
	// 20200723 MTC END

	int error_code = CopyFile(working_output_file_name, final_output_file_name, FALSE);

	if (error_code == 0)
		throw FatalError("Could not copy output file, " + working_output_file_name + ", to working file directory.");

	if (!custom_file_naming.is_open())//Required for local node input/output processing
		{
		custom_file_naming.open(final_output_file_name, ios::app);
		custom_file_naming << "" << endl;
		custom_file_naming.close();
		}


	// 20190206 STW (START) : aggregate results to produce AGGCF and PVDE
	string working_output_dir(working_output_file_name);
	string final_output_dir(final_output_file_name);	//20190212	STW: convert wildcard to string
	post_process_file_aig(final_output_dir, working_output_dir);	//20190212	STW: add final output file name as another function input
	// 20190206 STW (END)

	/*
	// 20190212 STW (START) : Delete standard naming output files
	int status = remove(working_output_dir.c_str());
	if (status != 0)
	{
		throw FatalError("Standard naming output file could not be deleted. Details: " + working_output_file_name);
	}
	// 20190212 STW (END)
	*/
	// 20200723 MTC END

	// 20190906 STW (START) : Delete RAFM output to save hard drive space
	if (output_delete_switch == "Yes")
	{
		// 20200723 MTC - vGrid update
		ofstream ofs;
		ofs.open(working_output_dir);
		ofs.close();

		int status2 = remove(final_output_file_name.c_str());
		if (status2 != 0)
		{
			throw FatalError("Customized naming output file could not be deleted. Details: " + final_output_file_name);
		}
	}
	// 20190906 STW (END)

	}

//Added missing file detection and failure.  MCHING 20220317
if ( !found_model_output )
{
	xstring model_output_prefix = replaceWildcards(output_location_aig);
	throw FatalError("No model output selected for post-processing found in path: " + model_output_prefix + "*");
}

return NO_AVG;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double UTIL_RAFM_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.UTIL_RAFM.for"
#if 0 // START_HEADER
#include <sstream> // for ostringstream
#include <sys/stat.h> // for file access
#include <deque> //WTW - Gen2 - add library to use deque
#endif // END_HEADER

#if 0 // START_EXTERNS
//typedef ifstream mpinput;//Gen2 - 9/6/2024 - comment out typedef
ifstream copy_mp_data;//Gen2 - 9/6/2024 - replace mpinput with full definition
sowfoutput custom_file_naming;
#endif // END_EXTERNS

#if 0 // START_CLASS
SmartArray <xstring> mp_data;
#endif // END_CLASS

#if 0 // START_TERMINATOR
copy_mp_data.close();
custom_file_naming.close();
#endif // END_TERMINATOR

return 1.0;

}


//@@ END

//@@ START - custom_output_directory
// Custom Output Directory                                                                                             
// Calculated Variable:CUSTOM_OUTPUT_DIRECTORY
//========================================================
xstring UTIL_RAFM_UDF::util_rafm_custom_output_directory() {
//^^^


#line 1 "custom_output_directory.UTIL_RAFM.for"
return base_output_filename.substr(0, base_output_filename.find_last_of("/\\"));

}


//@@ END

//@@ START - post_processing_set_lookup_aig
// Table look-up for file post-processing behavior:                                                                                             
// Calculated Variable:POST_PROCESSING_SET_LOOKUP_AIG
//========================================================
xstring UTIL_RAFM_UDF::util_rafm_post_processing_set_lookup_aig() {
//^^^


#line 1 "post_processing_set_lookup_aig.UTIL_RAFM.for"
return post_processing_set_aig; // 20201216 DTL

}


//@@ END


#line 1 "avg_row_key_found_aig.UTIL_RAFM.for"                                                                                   
bool UTIL_RAFM::avg_row_key_found_aig(string row_key)
{
	vector<string> row_key_columns;
	split_string_usl(row_key, row_key_columns, ",");//WTW - Gen2 - split_tring internal RAFM function
	string time_column_value = row_key_columns[time_column_index_aig - 1];

	bool text_chars_found = has_non_numeric_characters_aig(time_column_value);

	if (!text_chars_found)
	{  // if we don't have text chars in the time column, then we're looking at one month of data and not a PV/summary row
		return true;
	}

	vector<string> pvde_row_keys;
	split_string_usl(pvde_row_filters_aig.c_str(), pvde_row_keys, ",");//WTW - Gen2 - split_tring internal RAFM function

	for (const auto key : pvde_row_keys)
	{
		if (row_key.find(key) != string::npos)
		{
			return true;
		}
	}

	return false;
}



#line 1 "has_non_numeric_characters_aig.UTIL_RAFM.for"                                                                                   
bool UTIL_RAFM::has_non_numeric_characters_aig(string test_text)
{
	regex character_text( "([A-Za-z]+)" );
	smatch match_result;

	bool match_found = regex_search(test_text, match_result, character_text);

	return match_found;
}



#line 1 "post_process_file_aig.UTIL_RAFM.for"                                                                                   
void UTIL_RAFM::post_process_file_aig (string output_file_path, string working_file_path)	// 20190212 STW : add output_file_path as an input
{
	/******************************************************************************
	This function is created by Danial Lalimo and modified by David Sun
	******************************************************************************/

	ifstream src_file(working_file_path);	// 20190212 STW : change the source according to input rename
	if (src_file.is_open())
	{
		// initialization of variables for later use
		string line;
		vector<string> row_key_copies;
		map<string, deque<double>> month_data;
		deque<string> pvde_data;	
		string header_line = "";
		int scenario_count = 0;		// total number of scenarios, save for dividing when calculating of average
		int current_scenario = 0;
		int totol_rows_in_scen = 0;
		int scen_row_count = 0;
		// 20190222 STW START: duplicate information for PVDE calculation
		vector<string> row_key_copies_pvde;
		map<string, deque<double>> month_data_pvde;
		// 20190222 STW END

		// 20190318 STW START: add variables for error handling
		bool bad_row_flag = false;
		string bad_row_number = "";
		int total_row_count = 0;
		// 20190318


		// reading in data line by line
		while (getline(src_file, line))
		{
			total_row_count ++;			// 20190318 STW: keep track of total number of rows in output file

			if (header_line == "")		// record header line only at the beginning
			{
				header_line = line;
				continue;
			}
			
			stringstream line_strm(line);
			deque<string> line_tokens;
			string token;
			while (getline(line_strm, token, ','))	// allocate data within the line into an array, data is separated by comma
			{
				line_tokens.push_back(token);
			}
			
			// 20190318 STW START: error handling - record line number and continue
			if(line_tokens.size() != 0)
			{
				if (line_tokens.size() < index_columns_count_aig)
				{
					bad_row_flag = true;
					bad_row_number += to_string(total_row_count);
					bad_row_number += ",";
					continue;
				}
			}
			else
			{
				continue;
			}
			// 20190318 STW END
			


			string row_index = "";

			// 20190222 STW START: duplicate information for PVDE calculation
			deque<string> line_tokens_pvde = line_tokens;	
			string row_index_pvde = "";
			// 20190222 STW END



			// 20190222 STW : change from create keys for non-pvde entries to create keys for all entries
			// keys contain original information of first few columns and 
			//a dummy as a placeholder for the averaged item to keep format of output same as the original file
			for (unsigned int i = 0; i < index_columns_count_aig; i++)
			{
				if (i != scen_column_index_aig - 1)
				{
					// add information to keys
					row_index += line_tokens.front();
					row_index += ",";
				}
				else
				{
					// add dummy to keys
					int scenario_number = stoi(line_tokens.front());
					row_index += "*,";		
					scen_row_count++;

						
					// for loop below is to throw an error message if there's a missing row in a random scenario
					if (current_scenario != scenario_number)
					{
						if (totol_rows_in_scen < 2)
						{
							totol_rows_in_scen = scen_row_count;
						}
						else if (totol_rows_in_scen != scen_row_count && current_scenario > 1)
						{
							xstring message = xstring("There is a missing row in scenario number ") + xstring(current_scenario) + xstring(". Please check the data.");		
							throw FatalError(message);
						}						
						scen_row_count = 0; // reset scenario row count to 0 
						current_scenario = scenario_number;
						++scenario_count;
					}

				}
				line_tokens.pop_front();
			}

			// 20190222 STW START:	Make a new set of keys for PVDE entries
			if (line_tokens_pvde[pvde_column_index_aig - 1] != to_string(-1)
				|| line_tokens_pvde[pvde_column_index_aig] == to_string(0))//WTW - Gen2 - Need time 0 for column PVs
			{
				for (unsigned int i = 0; i < index_columns_count_aig; i++)
				{
					if (i != mp_column_index_aig - 1)
					{
						// add information to keys
						row_index_pvde += line_tokens_pvde.front();
						row_index_pvde += ",";
					}
					else
					{
						// add dummy to keys
						row_index_pvde += "*,";
					}
					line_tokens_pvde.pop_front();
				}
			}
			// 20190222 STW END

			// 20190222 STW : perform aggregate cash flow calculation on all entries instead of non-pv entries
			if(avg_row_key_found_aig(row_index))
			{
				if (month_data.find(row_index) == month_data.end())
				{
					// put data with new keys to a list
					deque<double> new_list;
					month_data.insert(map<string, deque<double>>::value_type(row_index, new_list));
					row_key_copies.push_back(row_index);

					deque<double>& existing_list = month_data.find(row_index)->second;
					while (line_tokens.size() > 0)
					{
						string string_value = line_tokens.front();
						line_tokens.pop_front();

						if (string_value == "")
						{
							existing_list.push_back(0.0);
						}
						else
						{
							existing_list.push_back(stod(string_value));
						}
					}
				}
				else
				{
					// add data with existing keys to existing data
					deque<double>& existing_list = month_data.find(row_index)->second;
					for (unsigned int i = 0; i < line_tokens.size(); i++)
					{
						string string_value = line_tokens[i];
						if (string_value != "")
						{
							existing_list[i] += stod(string_value);
						}
					}
				}
			}

			if (pvde_row_key_found_aig(row_index_pvde))
			{
				if (month_data_pvde.find(row_index_pvde) == month_data_pvde.end())
				{
					// put data with new keys to a list
					deque<double> new_list;
					month_data_pvde.insert(map<string, deque<double>>::value_type(row_index_pvde, new_list));
					row_key_copies_pvde.push_back(row_index_pvde);

					deque<double>& existing_list_pvde = month_data_pvde.find(row_index_pvde)->second;
					while (line_tokens_pvde.size() > 0)
					{
						string string_value = line_tokens_pvde.front();
						line_tokens_pvde.pop_front();

						if (string_value == "")
						{
							existing_list_pvde.push_back(0.0);	// TODO: try to push "" to end
						}
						else
						{
							existing_list_pvde.push_back(stod(string_value));
						}
					}
				}
				else
				{
					// add data with existing keys to existing data
					deque<double>& existing_list_pvde = month_data_pvde.find(row_index_pvde)->second;
					for (unsigned int i = 0; i < line_tokens_pvde.size(); i++)
					{
						string string_value = line_tokens_pvde[i];
						if (string_value != "")
						{
							existing_list_pvde[i] += stod(string_value);
						}
					}
				}
			}
			// 20190222 STW END
		}


		// 20190318 STW START: error handling
		if(bad_row_flag)
		{
			xstring message = xstring("The following rows are problematic: ") + xstring(bad_row_number) + xstring(" please check the RAFM output.");		
			throw FatalError(message);
		}
		// 20190318 STW END

		
		// prepare output name for the two outputs
		string aggcf_path = output_file_path;	// 20190212 STW : change the source according to input rename
		string pvde_path = output_file_path;	// 20190212 STW : change the source according to input rename
		// 20190322 STW START: let users know that the scenario numxbers are not matching	
		//string file_name_addision_agg = to_string(scenario_count) + xstring(aggcf_prefix_aig);
		//string file_name_addision_pvde = to_string(scenario_count) + xstring(pvde_prefix_aig);
		string file_name_addision_agg = to_string(scenario_count) + aggcf_prefix_aig.c_str();//WTW - Gen2
		string file_name_addision_pvde = to_string(scenario_count) + pvde_prefix_aig.c_str();//WTW - Gen2
		// 20190322 STW END
		// 20190212 STW (START): change the aggregation output naming rules

		// 20200723 MTC - vGrid update
		xstring run_page_name_aig_lower = run_page_name_aig;
		run_page_name_aig_lower.to_lower();

		xstring working_file_path_lower = working_file_path;
		working_file_path_lower.to_lower();

		int file_ext_pos = working_file_path_lower.find(run_page_name_aig_lower);
		// 20200723 MTC END

		aggcf_path.insert(file_ext_pos, file_name_addision_agg);	// 20190212 STW : change the prefix to read-in variable
		pvde_path.insert(file_ext_pos, file_name_addision_pvde);	// 20190212 STW : change the prefix to read-in variable
		// 20190212 STW (END)


		// generate file for AGGCF
		ofstream tgt_file;
		tgt_file.open(aggcf_path, ios::trunc);
		if (tgt_file.is_open())
		{
			tgt_file << header_line << endl;

			vector<string>::iterator row_key_iter = row_key_copies.begin();
			while (row_key_iter != row_key_copies.end())
			{
				
				string line = *row_key_iter;
				deque<double>& existing_list = month_data[*row_key_iter];

				for (unsigned int i = 0; i < existing_list.size(); i++)
				{
					double number_value = existing_list[i];
					number_value /= scenario_count;
					string string_value = to_string(number_value); 
					line += string_value + ",";
				}
				
				line.pop_back();
				tgt_file << line << endl;

				row_key_iter++;
			}
			tgt_file.close();
		}
		
		// generate file for PVDE
		// 20190222 STW START: change pvde output logic from output everything to output averaged result
		tgt_file.open(pvde_path, ios::trunc);
		if (tgt_file.is_open())
		{
			tgt_file << header_line << endl;

			vector<string>::iterator row_key_iter = row_key_copies_pvde.begin();
			while (row_key_iter != row_key_copies_pvde.end())
			{
				
				string line = *row_key_iter;
				deque<double>& existing_list = month_data_pvde[*row_key_iter];

				for (unsigned int i = 0; i < existing_list.size(); i++)
				{
					line += to_string(existing_list[i]) + ",";
				}
				
				line.pop_back();
				tgt_file << line << endl;

				row_key_iter++;
			}
			tgt_file.close();
		}
	}
}




#line 1 "pvde_row_key_found_aig.UTIL_RAFM.for"                                                                                   
bool UTIL_RAFM::pvde_row_key_found_aig(string row_key)
{
	vector<string> pvde_row_keys;
	split_string_usl(pvde_row_filters_aig.c_str(), pvde_row_keys, ",");//WTW - Gen2 - split_tring internal RAFM function

	for (const auto key : pvde_row_keys)
	{
		if (row_key.find(key) != string::npos)
		{
			return true;
		}
	}

	return false;
}



void UTIL_RAFM::Terminator()
{

copy_mp_data.close();
custom_file_naming.close();

}

FunctionPtr UTIL_RAFM::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static UTIL_RAFM_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (UTIL_RAFM_UDF::*dPXi) (int);
typedef double (UTIL_RAFM_UDF::*dPXid) (int, double);
typedef double (UTIL_RAFM_UDF::*dPF) ();
typedef double (UTIL_RAFM_UDF::*dPFd) (double);
typedef int (UTIL_RAFM_UDF::*iPF) ();
typedef int (UTIL_RAFM_UDF::*iPFi) (int);
typedef xstring (UTIL_RAFM_UDF::*sPF) ();
typedef xstring (UTIL_RAFM_UDF::*sPFs) (xstring);

const CashFlowCommonData UTIL_RAFM::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "copy_data_files", "util_rafm_copy_data_files",  "copy_data_files",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&UTIL_RAFM_UDF::util_rafm_copy_data_files, 'E','N', '3', 'C', (size_t)&modelOffset->copy_data_files),
	CashFlowCommonData(2, "copy_output_files", "util_rafm_copy_output_files",  "copy_output_files",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&UTIL_RAFM_UDF::util_rafm_copy_output_files, 'E','N', '3', 'C', (size_t)&modelOffset->copy_output_files),
	CashFlowCommonData(3, "startup", "util_rafm_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&UTIL_RAFM_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* UTIL_RAFM::mCFStaticData[] = {
	&UTIL_RAFM::mCFStaticData_0[0],
	&UTIL_RAFM::mCFStaticData_0[1],
	&UTIL_RAFM::mCFStaticData_0[2],
	&UTIL_RAFM::mCFStaticData_0[3],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for post_processing_set_aig                                                                                       
	const ChoicePair post_processing_set_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MBVONB, "MBVoNB")
		,ChoicePair(StrEnum::STATUTORY, "Statutory")
	};
	const EnumList post_processing_set_aigEnumList(2, post_processing_set_aigChoicePairs);

	// EnumList for run_page_name_aig                                                                                       
	const ChoicePair run_page_name_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::STANDARD_SERIATIM, "Standard Seriatim")
		,ChoicePair(StrEnum::STANDARD_PORTFOLIO, "Standard Portfolio")
	};
	const EnumList run_page_name_aigEnumList(2, run_page_name_aigChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace UTIL_RAFM_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(UTIL_RAFM::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(UTIL_RAFM::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace UTIL_RAFM_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void UTIL_RAFM::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> UTIL_RAFM::mgr_;

	Attribute::Descriptor UTIL_RAFM::descriptor_0[] = {
	Descriptor(0, Attribute::STRING,	"aggcf_prefix_aig", -1, (size_t)&modelOffset->aggcf_prefix_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STRING,	"base_output_filename", -1, (size_t)&modelOffset->base_output_filename,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::INT,	"index_columns_count_aig", -1, (size_t)&modelOffset->index_columns_count_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STRING,	"input_data_filename", -1, (size_t)&modelOffset->input_data_filename,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::INT,	"max_path_job_name_length_aig", -1, (size_t)&modelOffset->max_path_job_name_length_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::INT,	"mp_column_index_aig", -1, (size_t)&modelOffset->mp_column_index_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"output_delete_switch", -1, (size_t)&modelOffset->output_delete_switch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"output_location_aig", -1, (size_t)&modelOffset->output_location_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"post_processing_set_aig", -1, (size_t)&modelOffset->post_processing_set_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &post_processing_set_aigEnumList, Feature(true)),
	Descriptor(9, Attribute::INT,	"pvde_column_index_aig", -1, (size_t)&modelOffset->pvde_column_index_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::INT,	"pvde_indicator_aig", -1, (size_t)&modelOffset->pvde_indicator_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STRING,	"pvde_prefix_aig", -1, (size_t)&modelOffset->pvde_prefix_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STRING,	"pvde_row_filters_aig", -1, (size_t)&modelOffset->pvde_row_filters_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STR_ENUM,	"run_page_name_aig", -1, (size_t)&modelOffset->run_page_name_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &run_page_name_aigEnumList, Feature(true)),
	Descriptor(14, Attribute::INT,	"scen_column_index_aig", -1, (size_t)&modelOffset->scen_column_index_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::INT,	"time_column_index_aig", -1, (size_t)&modelOffset->time_column_index_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STRING,	"working_data_filename", -1, (size_t)&modelOffset->working_data_filename,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::SCALAR_STRING,	"custom_output_directory", -1, (size_t)&modelOffset->custom_output_directory,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&UTIL_RAFM_UDF::util_rafm_custom_output_directory)),
	Descriptor(19, Attribute::SCALAR_STRING,	"post_processing_set_lookup_aig", -1, (size_t)&modelOffset->post_processing_set_lookup_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&UTIL_RAFM_UDF::util_rafm_post_processing_set_lookup_aig)),
	};

	Attribute::Descriptor* UTIL_RAFM::descriptorTable[] = {
	&UTIL_RAFM::descriptor_0[0],
	&UTIL_RAFM::descriptor_0[1],
	&UTIL_RAFM::descriptor_0[2],
	&UTIL_RAFM::descriptor_0[3],
	&UTIL_RAFM::descriptor_0[4],
	&UTIL_RAFM::descriptor_0[5],
	&UTIL_RAFM::descriptor_0[6],
	&UTIL_RAFM::descriptor_0[7],
	&UTIL_RAFM::descriptor_0[8],
	&UTIL_RAFM::descriptor_0[9],
	&UTIL_RAFM::descriptor_0[10],
	&UTIL_RAFM::descriptor_0[11],
	&UTIL_RAFM::descriptor_0[12],
	&UTIL_RAFM::descriptor_0[13],
	&UTIL_RAFM::descriptor_0[14],
	&UTIL_RAFM::descriptor_0[15],
	&UTIL_RAFM::descriptor_0[16],
	&UTIL_RAFM::descriptor_0[17],
	&UTIL_RAFM::descriptor_0[18],
	&UTIL_RAFM::descriptor_0[19],
	nullptr};
	const size_t UTIL_RAFM::sDescriptorCount = 20;

//factory
UTIL_RAFM* UTIL_RAFM::makeThis(int isSubmodel, ModelClass* owner, UTIL_RAFM* peer, 
						int mainRebase, const xstring &name, UTIL_RAFM_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("UTIL_RAFM::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor UTIL_RAFM");
#endif
	UTIL_RAFM* newP = (UTIL_RAFM*)new UTIL_RAFM_UDF
   	  ("util_rafm", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
UTIL_RAFM_persistent_object* UTIL_RAFM_persistent_object::makeThis(int isSubmodel, ModelClass* owner, UTIL_RAFM* peer, 
							int mainRebase, const xstring &name, UTIL_RAFM_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("UTIL_RAFM_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor UTIL_RAFM_persistent_object");
#endif
	UTIL_RAFM_persistent_object* newP = (UTIL_RAFM_persistent_object*)new UTIL_RAFM_persistent_object
   	  ("util_rafm", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			UTIL_RAFM_persistent_object* pd = dynamic_cast<UTIL_RAFM_persistent_object*>(product);
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

typedef double (UTIL_RAFM_UDF::*dPF) ();
typedef double (UTIL_RAFM_UDF::*dPFd) (double);
typedef int (UTIL_RAFM_UDF::*iPF) ();
typedef int (UTIL_RAFM_UDF::*iPFi) (int);
typedef xstring (UTIL_RAFM_UDF::*sPF) ();
typedef xstring (UTIL_RAFM_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
UTIL_RAFM::UTIL_RAFM(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia_rates(company_liab_fia_fia_rates)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (UTIL_RAFM_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
UTIL_RAFM::UTIL_RAFM(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(3, UTIL_RAFM::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia_rates(company_liab_fia_fia_rates)
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


		ModelClassName = modelClassName;
       isSubmodel = isSm;
       isMainModel = !isSm;
		modelName = name;

#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_liab_fia_fia_rates = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
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
	typedef double (UTIL_RAFM_UDF::*dPXi2) (int, int);
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


 void UTIL_RAFM::copy_names() {

#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_liab_fia_fia_rates = (RATES_ECONOMY*)(findUnique("company|liab|fia|fia_rates"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_UTIL_RAFM_CLASS_
		util = (UTIL_RAFM*)(findUnique("util"));
#endif
 }
//copy_names END@2


 void UTIL_RAFM::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int UTIL_RAFM_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& UTIL_RAFM_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double UTIL_RAFM_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int UTIL_RAFM_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double UTIL_RAFM_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double UTIL_RAFM_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void UTIL_RAFM_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void UTIL_RAFM_persistent_object::write(long include_submodels) {
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

	void UTIL_RAFM_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void UTIL_RAFM_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void UTIL_RAFM_persistent_object::write(const xstring& key, long include_submodels) {
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




	UTIL_RAFM_persistent_object::~UTIL_RAFM_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool UTIL_RAFM_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void UTIL_RAFM_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void UTIL_RAFM_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void UTIL_RAFM_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void UTIL_RAFM_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void UTIL_RAFM_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* UTIL_RAFM_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* UTIL_RAFM_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* UTIL_RAFM_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char UTIL_RAFM_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void UTIL_RAFM_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
UTIL_RAFM_persistent_object::UTIL_RAFM_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			UTIL_RAFM(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(UTIL_RAFM::sm_bond_is)
	, sm_bond_pv(UTIL_RAFM::sm_bond_pv)
	, sm_bond_ym(UTIL_RAFM::sm_bond_ym)
	, sm_mtg_is(UTIL_RAFM::sm_mtg_is)
	, sm_mtg_pv(UTIL_RAFM::sm_mtg_pv)
	, sm_mtg_ym(UTIL_RAFM::sm_mtg_ym)

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
UTIL_RAFM::~UTIL_RAFM() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void UTIL_RAFM::findTargetColumns() {

}
//findTargetColumns END@2
void UTIL_RAFM::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void UTIL_RAFM::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void UTIL_RAFM::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void UTIL_RAFM::start_of_projection() {
}
//start_of_projection END@2

void UTIL_RAFM::end_of_projection() {
}
//end_of_projection END@2

void UTIL_RAFM::start_of_layer() {
}


void UTIL_RAFM::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void UTIL_RAFM::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void UTIL_RAFM::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void UTIL_RAFM::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> UTIL_RAFM::ddfVector;
BitArray UTIL_RAFM::dataVariables(20);
bool UTIL_RAFM::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool UTIL_RAFM::writeClassInfo = true;

void UTIL_RAFM::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, UTIL_RAFM::descriptor_0>::dT = UTIL_RAFM::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, UTIL_RAFM::descriptor_0>::dT = UTIL_RAFM::descriptor_0;

