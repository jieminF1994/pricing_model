
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
#include "ModelClass\automation_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
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
#ifndef automation_TableDefs
#define automation_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection AUTOMATION::TTHC;
void AUTOMATION::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - postprocess_aig
// PostProcess                                                                                             
// Column:POSTPROCESS_AIG
//========================================================
double AUTOMATION_UDF::automation_postprocess_aig(int t) {
//^^^



//^^^

#line 1 "postprocess_aig.AUTOMATION.for"
/*
	Target column for executing post-processing routines.

	- Initial implementation. MCHING 1-26-2022
	- Refactor and enhancement to track found model output files. MCHING 3-29-2022
*/

// Read in file list and register each file
xstring file_manifest_file_path = replaceWildcards("<*working_data*>file_manifest_<*proj_set_loop_num*>_<*proj_set_sub_loop_num*>.txt");
std::vector< std::string > model_output_file_paths;

log_strm << "Reading file manifest: " << file_manifest_file_path << std::endl;

if (file_exists_aig(file_manifest_file_path))
{
	std::ifstream file_manifest(
		file_manifest_file_path
	);

	std::string file_path;
	while(std::getline(file_manifest, file_path))
	{
		// Calling replaceWildcards "registers" the output file and allows it to appear
		// in the vGrid filesystem
		xstring full_file_path(
			replaceWildcards( file_path )
		);

		log_strm << "Registering possible output file: " << full_file_path << " ..." << std::endl;

		if ( file_exists_aig( full_file_path ) )
		{
			log_strm << "Output file found: " << full_file_path << std::endl;

			model_output_file_paths.push_back(
				xstring_to_string_aig(
					full_file_path
				)
			);
		}
		else
		{
			log_strm << "Output file not found: " << full_file_path << std::endl;
		}

	}

	file_manifest.close();
}
else
{
	throw FatalError("Unable to find file manifest at this location: " + file_manifest_file_path);
}

// Write post-processing XML parameter file
std::string xml_file_path(
	xstring_to_string_aig(
		replaceWildcards("<*working_data*>extract_config_<*proj_set_loop_num*>_<*proj_set_sub_loop_num*>.xml")
	)
);

XmlWriter xml_writer = XmlWriter(xml_file_path);

XmlNode* wildcard_set_node = xml_writer.root_node->append_child_node("WildcardSet");

// proj_set_loop_num Wildcard
std::string proj_set_loop_num(
	xstring_to_string_aig(
		replaceWildcards("<*proj_set_loop_num*>")
	)
);

append_wildcard_node_aig(
	wildcard_set_node,
	"proj_set_loop_num",
	proj_set_loop_num
);

// proj_set_sub_loop_num Wildcard
std::string proj_set_sub_loop_num(
	xstring_to_string_aig(
		replaceWildcards("<*proj_set_sub_loop_num*>")
	)
);

append_wildcard_node_aig(
	wildcard_set_node,
	"proj_set_sub_loop_num",
	proj_set_sub_loop_num
);

// file_name_prefix Wildcard
xstring output_file_path(
	replaceWildcards(
		model_output_file_prefix_aig
	)
);

xstring file_name_prefix(
	get_file_name_aig(
		output_file_path
	)
);

append_wildcard_node_aig(
	wildcard_set_node,
	"file_name_prefix",
	xstring_to_string_aig(
		file_name_prefix
	)
);

// Write XML parameter file to disk
log_strm << "Writing post-processing configuration XML: " << xml_file_path << std::endl;

xml_writer.write();

// Print directory for diagnostics
log_strm << "Column Output Directory contents: " << std::endl;

xstring column_output_directory(
	replaceWildcards("<*column_output_directory*>")
);

list_dir_aig( column_output_directory );

// Execute post-processing tool
std::vector< xstring > args = {
	replaceWildcards("<*column_output_directory*>"),
	replaceWildcards("<*column_output_directory*>"),
	replaceWildcards("<*global*>cpp-rafm-model-output-extract.xml"),
	replaceWildcards("<*working_data*>extract_config_<*proj_set_loop_num*>_<*proj_set_sub_loop_num*>.xml"),
	"/Q"
};

create_process_aig(
	replaceWildcards("<*global*>cpp-rafm-model-output-extract.exe"),
	args
);  // The post-processing binary returns a non-zero exit code if it can't find any model 
	// output files, which in turn triggers a FatalError.

// Wipe model output using the file manifest. The post-processing tool has logic to delete 
// (not clear) model output, but vGrid requires us to use this method.
if (clear_model_output_defn_aig == YES)
{
	for (
		std::vector< std::string >::iterator model_output_file_path = model_output_file_paths.begin();
		model_output_file_path != model_output_file_paths.end();
		model_output_file_path++
	)
	{
		log_strm << "Clearing output file: " << model_output_file_path->c_str() << std::endl;

		std::ofstream model_output_file;

		model_output_file.open(
			model_output_file_path->c_str(),
			std::ios_base::trunc
		);

		model_output_file.close();
	}
}

return NO_AVG;


}


//@@ END

//@@ START - preprocess_aig
// PreProcess                                                                                             
// Column:PREPROCESS_AIG
//========================================================
double AUTOMATION_UDF::automation_preprocess_aig(int t) {
//^^^



//^^^

#line 1 "preprocess_aig.AUTOMATION.for"
/*
	Target column for executing pre-processing routines.

	- Initial implementation. MCHING 1-26-2022
*/

// Create working directory
xstring working_directory_path(
	replaceWildcards("<*working_data*>")
);

log_strm << "Creating working directory: " << working_directory_path << std::endl;

if (
		!CreateDirectory(working_directory_path, NULL) && 
		GetLastError() != ERROR_ALREADY_EXISTS
)
{
	throw FatalError("Failed to create directory at this location: " + working_directory_path);
}

// Copy model point file
xstring mp_file_path(
	replaceWildcards(mp_file_path_aig + ".csv")
);

xstring mp_tmp_file_path(
	replaceWildcards(mp_tmp_file_prefix_aig + "_<*proj_set_loop_num*>_<*proj_set_sub_loop_num*>.csv")
);

copy_file_aig(
	mp_file_path,
	mp_tmp_file_path
);

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

return NO_AVG;


}


//@@ END

//@@ START - startup
//                                                                                              
// Column:STARTUP
//========================================================
double AUTOMATION_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.AUTOMATION.for"
#if 0 // START_HEADER

/*
	A very simple XML writer library, mainly for use in RiskAgility FM.

	- Initial implementation. MCHING 1-26-2022
*/


class XmlNode
{
private:
	std::vector< XmlNode* > children;
	unsigned long long rank;

	std::string indent;


	void set_indent(void)
	{
		this->indent = "";

		for (unsigned long long rank = 0; rank < this->rank; rank++)
		{
			this->indent += "\t";
		}
	}


public:
	std::string name;
	std::string value;


	std::string to_string(void)
	{
		std::string xml = "\n";

		if (children.empty())
		{
			// This is the highest-rank node
			if (value.empty())
			{
				xml += this->indent + "</" + this->name + ">";
			}
			else
			{
				xml += this->indent + "<" + this->name + ">" + this->value + "</" + this->name + ">";
			}
		}
		else
		{
			// Write out children
			if (value.empty())
			{
				xml += this->indent + "<" + this->name + ">";
			}
			else
			{
				xml += this->indent + "<" + this->name + ">" + this->value;
			}

			for (XmlNode* child : children)
			{
				xml += child->to_string();
			}

			xml += "\n" + this->indent + "</" + this->name + ">";
		}

		return xml;
	}


	XmlNode* append_child_node(
		const std::string& name
	)
	{
		XmlNode* child = new XmlNode(
			this->rank + 1,
			name
		);

		this->children.push_back(child);

		return child;
	}


	XmlNode* append_child_node(
		const std::string& name,
		const std::string& value
	)
	{
		XmlNode* child = new XmlNode(
			this->rank + 1,
			name,
			value
		);

		this->children.push_back(child);

		return child;
	}


	XmlNode(
		const size_t& rank,
		const std::string& name
	)
	{
		this->rank = rank;
		this->name = name;

		this->set_indent();
	}


	XmlNode(
		const size_t& rank,
		const std::string& name,
		const std::string& value
	)
	{
		this->rank = rank;
		this->name = name;
		this->value = value;

		this->set_indent();
	}
};


class XmlWriter
{
public:
	const std::string PROLOGUE = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

	std::string xml_file_path;
	XmlNode* root_node;


	void write(void)
	{
		std::string xml = this->PROLOGUE + this->root_node->to_string();

		std::ofstream output_file;
		output_file.open(this->xml_file_path);
		output_file << xml;
		output_file.close();
	}


	XmlWriter(
		const std::string& xml_file_path
	)
	{
		this->xml_file_path = xml_file_path;
		this->root_node = new XmlNode(0, "root");
	}
};

#endif // END_HEADER

return 0.0;

}


//@@ END


#line 1 "append_to_file_manifest_aig.AUTOMATION.for"                                                                                   
void AUTOMATION::append_to_file_manifest_aig(
	const xstring& model_class_output_location
)
{
	/*
		Adds a line to the "file manifest". This manifest is used to directly reference any model output files.
	*/

	xstring file_name(
		get_file_name_aig(model_class_output_location)
	);

	xstring file_path(
		"<*column_output_directory*>" + file_name
	);
	
	xstring file_manifest_file_path(
		replaceWildcards("<*working_data*>file_manifest_<*proj_set_loop_num*>_<*proj_set_sub_loop_num*>.txt")
	);

	std::ofstream file_manifest(
		file_manifest_file_path, 
		std::ios_base::app
	);

	log_strm << "Appending file path:" << file_path << std::endl;
	log_strm << "To file manifest: " << file_manifest_file_path << std::endl;
	file_manifest << file_path << std::endl;

	file_manifest.close();
}



#line 1 "append_wildcard_node_aig.AUTOMATION.for"                                                                                   
void AUTOMATION::append_wildcard_node_aig(
	XmlNode* wildcard_set_node,
	const std::string& name,
	const std::string& value
)
{
	/*
		Convenience function to add a `Wildcard` child node to a `WildcardSet` node.

		- Initial implementation. MCHING 1-26-2022
	*/

	XmlNode* wildcard_node = wildcard_set_node->append_child_node("Wildcard");

	wildcard_node->append_child_node(
		"Name", 
		name
	);

	wildcard_node->append_child_node(
		"Value", 
		value
	);
}



#line 1 "copy_file_aig.AUTOMATION.for"                                                                                   
void AUTOMATION::copy_file_aig(
	const xstring& source_file_path,
	const xstring& target_file_path
)
{
	/*
		Copies a file using streams. This is necessary for vGrid to "detect" the file.
		It is unknown why this behavior occurs; simply referencing the file using 
		`replaceWildcards` allows it to appear in the vGrid filesystem.  However,
		the subsequent projection has trouble referencing it.
		
		- Initial implementation. MCHING 1-26-2022
	*/

	if ( GetFileAttributes(source_file_path) == INVALID_FILE_ATTRIBUTES )
	{
		throw FatalError("Failed to access copy source file at this location: " + source_file_path);
	}

	log_strm << "Copying source file: " << source_file_path << std::endl;
	log_strm << "To destination: " << target_file_path << std::endl;

	std::ifstream source_file(
		source_file_path
	);

	source_file.setf(ios::fixed);
	source_file.precision(16);

	std::ofstream target_file(
		target_file_path
	);

	target_file.setf(ios::fixed);
	target_file.precision(16);

	char c = source_file.get();

	while(source_file.good())
	{
		target_file << c;
		c = source_file.get();
	}

	source_file.close();
	target_file.close();
}




#line 1 "create_process_aig.AUTOMATION.for"                                                                                   
void AUTOMATION::create_process_aig(
	const xstring& exe_path,
	const std::vector< xstring >& args
)
{
	/*
		Creates a child process and redirects standard IO:

		https://docs.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN

		- Initial implementation. MCHING 1-26-2022
		- Bugfix to error code printing. MCHING 3-29-2022
	*/

	HANDLE process_in_read = NULL;
	HANDLE process_in_write = NULL;
	HANDLE process_out_read = NULL;
	HANDLE process_out_write = NULL;

	SECURITY_ATTRIBUTES security_attr;

	// Set the bInheritHandle flag so pipe handles are inherited
	security_attr.nLength = sizeof(SECURITY_ATTRIBUTES); 
	security_attr.bInheritHandle = TRUE; 
	security_attr.lpSecurityDescriptor = NULL; 

	// Create a pipe for the child process's STDOUT. 
	if (
			!CreatePipe(
				&process_out_read, 
				&process_out_write, 
				&security_attr, 
				NULL
			)
	)
	{
		log_strm << "GetLastError code: " << GetLastError() << std::endl;
		throw FatalError("Failed to create STDOUT pipe to child process.");
	}

	// Ensure the read handle to the pipe for STDOUT is not inherited.
	if (
			!SetHandleInformation(
				process_out_read, 
				HANDLE_FLAG_INHERIT, 
				NULL
			)
	)
	{
		log_strm << "GetLastError code: " << GetLastError() << std::endl;
		throw FatalError("Failed to ensure read handle for STDOUT pipe is not inherited."); 
	}

	// Create a pipe for the child process's STDIN. 
	if (
			!CreatePipe(
				&process_in_read, 
				&process_in_write, 
				&security_attr, 
				NULL
			)
	) 
	{
		log_strm << "GetLastError code: " << GetLastError() << std::endl;
		throw FatalError("Failed to create STDIN pipe to child process.");
	}
	
	// Ensure the write handle to the pipe for STDIN is not inherited. 
	if (
			!SetHandleInformation(
				process_in_write,
				HANDLE_FLAG_INHERIT,
				0
			)
	)
	{
		log_strm << "GetLastError code: " << GetLastError() << std::endl;
		throw FatalError("Failed to ensure write handle for STDIN pipe is not inherited.");
	}

	// Initialize info structures
	STARTUPINFO startup_info;

	ZeroMemory(
		&startup_info, 
		sizeof( startup_info )
	);

	startup_info.cb = sizeof(startup_info);
	startup_info.hStdError = process_out_write;
	startup_info.hStdOutput = process_out_write;
	startup_info.hStdInput = process_in_read;
	startup_info.dwFlags |= STARTF_USESTDHANDLES;

	PROCESS_INFORMATION process_info;

	ZeroMemory(
		&process_info, 
		sizeof( process_info )
	);

	// Spawn process
	std::string command_s(
		"\"" + xstring_to_string_aig(exe_path) + "\""
	);

	for (size_t index = 0; index < args.size(); index++)
	{
		std::string parsed_arg(
			xstring_to_string_aig(args[index])
		);

		if (ends_with_aig( parsed_arg, "\\" ))
		{
			parsed_arg += "\\";
		}

		command_s += " \"" + parsed_arg + "\"";
	}

	LPSTR command_p = new TCHAR[command_s.size() + 1];
	std::strcpy(command_p, command_s.c_str());

	if(
			CreateProcess(
				NULL,					// No module name
				command_p,				// Command line
				NULL,					// Process handle not inheritable
				NULL,					// Thread handle not inheritable
				TRUE,					// Set handle inheritance to TRUE; handles are inherited
				0,						// No creation flags
				NULL,					// Use parent's environment block
				NULL,					// Use parent's starting directory 
				&startup_info,			// Pointer to STARTUPINFO structure
				&process_info			// Pointer to PROCESS_INFORMATION structure
			)
	) 
	{
		log_strm << "Started child process: " << xstring(command_s) << std::endl;
	}
	else
	{
		log_strm << "GetLastError code: " << GetLastError() << std::endl;
		throw FatalError("Failed to create child process: " + xstring(command_s));
	}

	// Wait until child process exits
	WaitForSingleObject(
		process_info.hProcess,
		INFINITE
	);

	// Get return code
	DWORD exit_code;

	GetExitCodeProcess(
		process_info.hProcess,
		&exit_code
	);

	// Close process and thread handles
	CloseHandle( process_info.hProcess );
	CloseHandle( process_info.hThread );

	// Close handles to the stdin and stdout pipes no longer needed by the child process.
	// If they are not explicitly closed, there is no way to recognize that the child process has ended.
	CloseHandle( process_out_write );
	CloseHandle( process_in_read );

	// Write contents of pipe to log
	log_strm << "Child process output:" << std::endl << std::endl;

	DWORD buffer_bytes_read;
	char buffer[BUFSIZ];

	while(
			ReadFile(
				process_out_read,
				buffer,
				BUFSIZ,
				&buffer_bytes_read,
				NULL
			)
	)
	{
		if ( buffer_bytes_read )
		{
			std::string to_stream(
				buffer,
				buffer_bytes_read
			);

			log_strm << to_stream;
		}
	}

	// Error Handling
	std::ostringstream exit_code_sstream;  // Need to do pre-C++11 style cast for DWORD. Refactor this if we go to a newer version of C++.
	exit_code_sstream << exit_code;

	if (!exit_code)
	{
		log_strm << "Child process completed with exit code: " << xstring(exit_code_sstream.str()) << std::endl;
	}
	else
	{
		throw FatalError("Child process failed with exit code: " + xstring(exit_code_sstream.str()));
	}
}




#line 1 "ends_with_aig.AUTOMATION.for"                                                                                   
bool AUTOMATION::ends_with_aig(
	std::string const& target,
	std::string const& value
)
{
	/*
		Checks if a string ends with another string.

		https://stackoverflow.com/a/874160
		
		- Initial implementation. MCHING 1-26-2022
	*/

	if (target.length() >= value.length())
	{
		bool ends_with;

		if (
				target.compare(
					target.length() - value.length(),
					value.length(),
					value
				) == 0
		)
		{
			return true;
		}
		else
		{
			return false;
		}
    }
	else
	{
        return false;
    }

}



#line 1 "file_exists_aig.AUTOMATION.for"                                                                                   
bool AUTOMATION::file_exists_aig(
	const xstring& file_path
)
{
	/*
		Detects whether or not a file exists.

		- Initial implementation. MCHING 1-26-2022
	*/

	LPWIN32_FIND_DATAA found_file_data = new WIN32_FIND_DATAA();
	HANDLE file_handle;

	file_handle = FindFirstFile(
		file_path,
		found_file_data
	);

	if (file_handle != INVALID_HANDLE_VALUE)
	{
		return true;
	}
	else
	{
		return false;
	}
}




#line 1 "get_file_name_aig.AUTOMATION.for"                                                                                   
xstring AUTOMATION::get_file_name_aig(
	const xstring& file_path
)
{
	/*
		Gets a file name from a file path.

		- Initial implementation. MCHING 1-26-2022
	*/

	xstring file_name(
		file_path.substr(
			file_path.find_last_of("/\\") + 1
		)
	);

	return file_name;
}



#line 1 "list_dir_aig.AUTOMATION.for"                                                                                   
void AUTOMATION::list_dir_aig(
	const xstring& dir_path
)
{
	/*
		Lists file in a directory.  Used for diagnostic purposes.
		
		- Initial implementation. MCHING 1-26-2022
	*/

	LPWIN32_FIND_DATAA found_file_data = new WIN32_FIND_DATAA();
	HANDLE file_handle;

	xstring dir_path_wildcard = dir_path + "*";

	file_handle = FindFirstFile(
		dir_path_wildcard,
		found_file_data
	);

	if (file_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(found_file_data->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				xstring file_name(found_file_data->cFileName);
				xstring full_file_path(dir_path + file_name);

				log_strm << "File: " << full_file_path << std::endl;
			}
		}
		while (	FindNextFile(file_handle, found_file_data) );

		if (GetLastError() != ERROR_NO_MORE_FILES)
		{
			throw FatalError("Error iterating through directory: " + dir_path);
		}
	}
	else
	{
		log_strm << "No files found at this location: " << dir_path;
	}
}



#line 1 "xstring_to_string_aig.AUTOMATION.for"                                                                                   
std::string AUTOMATION::xstring_to_string_aig(
	const xstring& source
)
{
	/*
		Converst a RAFM xstring into a std::string.

		- Initial implementation. MCHING 1-26-2022
	*/

	std::string target;

	for (size_t index = 0; index < source.length(); index++)
	{
		target += source[index];
	}

	return target;
}



	static AUTOMATION_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (AUTOMATION_UDF::*dPXi) (int);
typedef double (AUTOMATION_UDF::*dPXid) (int, double);
typedef double (AUTOMATION_UDF::*dPF) ();
typedef double (AUTOMATION_UDF::*dPFd) (double);
typedef int (AUTOMATION_UDF::*iPF) ();
typedef int (AUTOMATION_UDF::*iPFi) (int);
typedef xstring (AUTOMATION_UDF::*sPF) ();
typedef xstring (AUTOMATION_UDF::*sPFs) (xstring);

const CashFlowCommonData AUTOMATION::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "postprocess_aig", "automation_postprocess_aig",  "postprocess_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&AUTOMATION_UDF::automation_postprocess_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->postprocess_aig),
	CashFlowCommonData(2, "preprocess_aig", "automation_preprocess_aig",  "preprocess_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&AUTOMATION_UDF::automation_preprocess_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->preprocess_aig),
	CashFlowCommonData(3, "startup", "automation_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&AUTOMATION_UDF::virtual_startup, 'B','Y', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* AUTOMATION::mCFStaticData[] = {
	&AUTOMATION::mCFStaticData_0[0],
	&AUTOMATION::mCFStaticData_0[1],
	&AUTOMATION::mCFStaticData_0[2],
	&AUTOMATION::mCFStaticData_0[3],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for clear_model_output_defn_aig                                                                                       
	const ChoicePair clear_model_output_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList clear_model_output_defn_aigEnumList(2, clear_model_output_defn_aigChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace AUTOMATION_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(AUTOMATION::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(AUTOMATION::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace AUTOMATION_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void AUTOMATION::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> AUTOMATION::mgr_;

	Attribute::Descriptor AUTOMATION::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"clear_model_output_defn_aig", -1, (size_t)&modelOffset->clear_model_output_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &clear_model_output_defn_aigEnumList, Feature(true)),
	Descriptor(1, Attribute::INT,	"max_path_job_name_length_aig", -1, (size_t)&modelOffset->max_path_job_name_length_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STRING,	"model_output_file_prefix_aig", -1, (size_t)&modelOffset->model_output_file_prefix_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STRING,	"mp_file_path_aig", -1, (size_t)&modelOffset->mp_file_path_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STRING,	"mp_tmp_file_prefix_aig", -1, (size_t)&modelOffset->mp_tmp_file_prefix_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	};

	Attribute::Descriptor* AUTOMATION::descriptorTable[] = {
	&AUTOMATION::descriptor_0[0],
	&AUTOMATION::descriptor_0[1],
	&AUTOMATION::descriptor_0[2],
	&AUTOMATION::descriptor_0[3],
	&AUTOMATION::descriptor_0[4],
	&AUTOMATION::descriptor_0[5],
	nullptr};
	const size_t AUTOMATION::sDescriptorCount = 6;

//factory
AUTOMATION* AUTOMATION::makeThis(int isSubmodel, ModelClass* owner, AUTOMATION* peer, 
						int mainRebase, const xstring &name, AUTOMATION_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("AUTOMATION::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor AUTOMATION");
#endif
	AUTOMATION* newP = (AUTOMATION*)new AUTOMATION_UDF
   	  ("automation", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
AUTOMATION_persistent_object* AUTOMATION_persistent_object::makeThis(int isSubmodel, ModelClass* owner, AUTOMATION* peer, 
							int mainRebase, const xstring &name, AUTOMATION_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("AUTOMATION_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor AUTOMATION_persistent_object");
#endif
	AUTOMATION_persistent_object* newP = (AUTOMATION_persistent_object*)new AUTOMATION_persistent_object
   	  ("automation", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			AUTOMATION_persistent_object* pd = dynamic_cast<AUTOMATION_persistent_object*>(product);
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

typedef double (AUTOMATION_UDF::*dPF) ();
typedef double (AUTOMATION_UDF::*dPFd) (double);
typedef int (AUTOMATION_UDF::*iPF) ();
typedef int (AUTOMATION_UDF::*iPFi) (int);
typedef xstring (AUTOMATION_UDF::*sPF) ();
typedef xstring (AUTOMATION_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
AUTOMATION::AUTOMATION(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
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
	typedef double (AUTOMATION_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
AUTOMATION::AUTOMATION(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(3, AUTOMATION::descriptorTable, arrayPersistentObj), Variable(*this)
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

	for (int cf_no = 1; cf_no <= 3; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (AUTOMATION_UDF::*dPXi2) (int, int);
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


 void AUTOMATION::copy_names() {

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


 void AUTOMATION::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int AUTOMATION_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& AUTOMATION_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double AUTOMATION_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int AUTOMATION_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double AUTOMATION_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double AUTOMATION_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void AUTOMATION_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void AUTOMATION_persistent_object::write(long include_submodels) {
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

	void AUTOMATION_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void AUTOMATION_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void AUTOMATION_persistent_object::write(const xstring& key, long include_submodels) {
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




	AUTOMATION_persistent_object::~AUTOMATION_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool AUTOMATION_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void AUTOMATION_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void AUTOMATION_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void AUTOMATION_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void AUTOMATION_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void AUTOMATION_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* AUTOMATION_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* AUTOMATION_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* AUTOMATION_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char AUTOMATION_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void AUTOMATION_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
AUTOMATION_persistent_object::AUTOMATION_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			AUTOMATION(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(AUTOMATION::sm_bond_is)
	, sm_bond_pv(AUTOMATION::sm_bond_pv)
	, sm_bond_ym(AUTOMATION::sm_bond_ym)
	, sm_mtg_is(AUTOMATION::sm_mtg_is)
	, sm_mtg_pv(AUTOMATION::sm_mtg_pv)
	, sm_mtg_ym(AUTOMATION::sm_mtg_ym)

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
AUTOMATION::~AUTOMATION() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void AUTOMATION::findTargetColumns() {

}
//findTargetColumns END@2
void AUTOMATION::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void AUTOMATION::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void AUTOMATION::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void AUTOMATION::start_of_projection() {
}
//start_of_projection END@2

void AUTOMATION::end_of_projection() {
}
//end_of_projection END@2

void AUTOMATION::start_of_layer() {
}


void AUTOMATION::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void AUTOMATION::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void AUTOMATION::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void AUTOMATION::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> AUTOMATION::ddfVector;
BitArray AUTOMATION::dataVariables(6);
bool AUTOMATION::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool AUTOMATION::writeClassInfo = true;

void AUTOMATION::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, AUTOMATION::descriptor_0>::dT = AUTOMATION::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, AUTOMATION::descriptor_0>::dT = AUTOMATION::descriptor_0;

