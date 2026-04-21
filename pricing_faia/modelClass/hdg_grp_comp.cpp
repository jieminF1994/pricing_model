
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
#include "ModelClass\hdg_grp_comp_udf.h"
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

deptaskinput valn_hedge_input;
deptaskcols valn_hedge_input_cols;
deptaskmap valn_hedge_input_pos;
deptaskmapiter valn_hedge_input_pos_iter;

deptaskinput valn_hedge_final_input;
deptaskcols valn_hedge_final_input_cols;
deptaskmap valn_hedge_final_input_pos;
deptaskmapiter valn_hedge_final_input_pos_iter;

// define sum over command, END_OF_PERIOD is defined globally
const int BEG_OF_PERIOD = 0;
int AVG_PV_CLAIMS = 1;
int AVG_PV_CHARGES = 2;
int VALN_RESULTS_SIZE = 3;

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
#ifndef hdg_grp_comp_TableDefs
#define hdg_grp_comp_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection HDG_GRP_COMP::TTHC;
void HDG_GRP_COMP::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.HDG_GRP_COMP.for"
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
double HDG_GRP_COMP_UDF::hdg_grp_comp_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.HDG_GRP_COMP.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.HDG_GRP_COMP.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_rate
// Cap Rate                                                                                             
// Column:CAP_RATE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_cap_rate(int t) {
//^^^



//^^^

#line 1 "cap_rate.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

//force call for reporting
opt_budget(t);
opt_budget_amt(t);
part_rate(t);
index_val(t);
opt_payoff(t);

if (fabs(notional_to_hedge(t)) < rate_ratio_threshold)
	return NO_AVG;

return (notional_amt_to_hedge_cap(t) / notional_to_hedge(t) - 1.0);

}


//@@ END

//@@ START - delta_hedge_flag
// Delta Hedge Flag                                                                                             
// Column:DELTA_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_flag(int t) {
//^^^



//^^^

#line 1 "delta_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_delta_hedge_defn == NO)
	return 0;

if (t > 0 && (t % hedge_grp_delta_hedge_rebal_freq) != 0)
	return 0;

// Check for existing delta hedge assets. If they exist, delta hedge strategy is not executed at t == 0
if (t == 0)
	{
	#if defined(__EIO_ASSET_H_)
	int mp = 0;
	mpmap::iterator mp_map_iter;
	EIO_ASSET *eio_element = NULL;

	if (eio_mp_map_active.size() > 0)
		{
		for (mp_map_iter = eio_mp_map_active.begin();
			 mp_map_iter != eio_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (eio_element->hdg_grp_code.find("Delta") < string::npos)
				return 0;
			}			         
		}
	#endif
	}

return 1.0;

}


//@@ END

//@@ START - delta_hedge_inv_amt
// Delta Hedge Investment Amount                                                                                             
// Column:DELTA_HEDGE_INV_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_inv_amt.HDG_GRP_COMP.for"
if (!delta_hedge_flag(t))
	return 0.0;
	
// Must first call delta hedge sales
delta_hedge_sale_amt(t);

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Delta Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Determine the asset deltas for each index
calc_asset_greeks(t, DELTA, PURCH);

double inv_amt = 0.0;
map <xstring, double> delta_hedge_coeff;
map <xstring, double> index_val;
map <xstring, double> notional_to_purch;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
if (hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC)
	index_loops = company->delta_gamma_hedge_index_list.size();

for (int index = 0; index < index_loops; index++)
	{
	// set lookup key
	if (hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
		hedge_grp_index_name = "Parallel";
	else
		hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];

	xstring greek_map_index = "Delta_Purchase_" + hedge_grp_index_name + "_" + xstring(t);
	double delta_asset_purch = asset_greeks[greek_map_index];

	// Asset greek needed has been updates for sales
	xstring greek_needed_map_index = "Delta_" + hedge_grp_index_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	if (fabs(delta_asset_purch) > model_point_amount_threshold)
		delta_hedge_coeff[greek_needed_map_index] = greek_needed / delta_asset_purch; 

	xstring hedge_grp_code = hedge_grp_id + "|Delta|" + hedge_grp_index_name;

	xstring map_index = hedge_grp_index_name + "_" + xstring(t);
	xstring index_name = get_purch_asset_index_name(seg_num, hedge_grp_index_name, hedge_grp_delta_hedge_asset_id);

	index_val[greek_needed_map_index] = rates->get_index_val(t, index_name);
	notional_to_purch[greek_needed_map_index] = index_val[greek_needed_map_index] * delta_hedge_coeff[greek_needed_map_index];
	double notional_inv = notional_to_purch[greek_needed_map_index];

	if (fabs(notional_inv) > model_point_amount_threshold)
		{
		inv_amt += company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		YES, //save_assets
																		HEDGING,
																		new_mp_num,
																		hedge_grp_code,
																		hedge_grp_delta_hedge_asset_id,
																		notional_inv,
																		1.0,
																		1.0);

		// Add new element to the hedge group eio map
		if (new_mp_num < 0)
			throw FatalError("Unable to invest in new delta hedge asset for hedge group " + hedge_grp_id + ". "
							 + "Please review your delta hedge strategy data.");

		eio_mp_map_active[new_mp_num] = new_mp_num;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Delta Hedge Investments Summary" << endl;
	seg->SALFile << "IndexName,IndexVal,DeltaNeeded,AssetDelta,HedgeCoeff,NotionalPurch" << endl;

	for (int index = 0; index < index_loops; index++)
		{
		if (hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
			hedge_grp_index_name = "Parallel";
		else
			hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];

		// Asset greek needed has been updates for sales
		xstring greek_needed_map_index = "Delta_" + hedge_grp_index_name + "_" + xstring(t);
		xstring greek_map_index = "Delta_Purchase_" + hedge_grp_index_name + "_" + xstring(t);
		seg->SALFile << hedge_grp_index_name << ","
		             << index_val[greek_needed_map_index] << ","
		             << asset_greeks_needed[greek_needed_map_index] << ","
					 << asset_greeks[greek_map_index] << ","	
		             << delta_hedge_coeff[greek_needed_map_index] << ","
		             << notional_to_purch[greek_needed_map_index] << endl;
		}
	}

delta_hedge_coeff.clear();
index_val.clear();
notional_to_purch.clear();

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Delta Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return inv_amt;

}


//@@ END

//@@ START - delta_hedge_mkt_val
// Delta Hedge Market Value of Assets                                                                                             
// Column:DELTA_HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "delta_hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, DELTA, END_OF_PERIOD);

}


//@@ END

//@@ START - delta_hedge_mkt_val_incr
// Delta Hedge Market Value of Assets Increase                                                                                             
// Column:DELTA_HEDGE_MKT_VAL_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "delta_hedge_mkt_val_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return delta_hedge_mkt_val(t) - delta_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - delta_hedge_pmt
// Delta Hedge Derivative Payment                                                                                             
// Column:DELTA_HEDGE_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("opt_pmt", t, DELTA, BEFORE_SALE);

}


//@@ END

//@@ START - delta_hedge_prof
// Delta Hedge Profit                                                                                             
// Column:DELTA_HEDGE_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_prof(int t) {
//^^^



//^^^

#line 1 "delta_hedge_prof.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_delta_hedge_defn == NO)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

return delta_hedge_pmt(t)
	   + delta_hedge_sale_amt(t)
	   - delta_hedge_inv_amt(t)
	   - delta_hedge_transaction_cost(t)
	   + delta_hedge_mkt_val_incr(t);

}


//@@ END

//@@ START - delta_hedge_sale_amt
// Delta Hedge Sale Amount                                                                                             
// Column:DELTA_HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_sale_amt.HDG_GRP_COMP.for"
if (!delta_hedge_flag(t))
	return 0.0;

// Must first call delta hedge strategy to setup strategy
delta_hedge_strat(t);

#if defined(__EIO_ASSET_H_)
// Do not process sales if there are no assets in the active map
if (!eio_mp_map_active.size())
	return 0.0;

// Do not process sales if there are no Delta assets in the active map
int mp = 0;
bool delta_hedges = false;
mpmap::iterator mp_map_iter;
EIO_ASSET *eio_element = NULL;
for (mp_map_iter = eio_mp_map_active.begin();
	mp_map_iter != eio_mp_map_active.end();
	mp_map_iter++)
	{
	mp = mp_map_iter->first;
	eio_element = company->sm_asset->sm_eio[mp];

	if (eio_element->hdg_grp_code.find("Delta") < string::npos)
		{
		delta_hedges = true;
		break;
		}
	}

if (!delta_hedges)
	return 0.0;
#endif

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Delta Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

double sales_amt = 0.0;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
if (hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC) // Just one loop for parallel hedging
	index_loops = company->delta_gamma_hedge_index_list.size();

for (int index = 0; index < index_loops; index++)
	{
	int mp = 0;
	mpmap::iterator mp_map_iter;
	xstring index_name;
	if (hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
		index_name = "Parallel";
	else
		index_name = company->delta_gamma_hedge_index_list[index];

	// Asset greek needed from original strategy setup
	xstring greek_needed_map_index = "Delta_" + index_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	xstring asset_greek_map_index = "Delta_BefSale_" + index_name + "_" + xstring(t);
	double delta_asset = asset_greeks[asset_greek_map_index];
	double delta_diff = - (delta_asset - greek_needed);
	double delta_asset_remaining = delta_asset;
	double delta_indv_asset = 0.0;
	double delta_sold = 0.0;
	double delta_sold_total = 0.0;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << "Processing Hedge Sales for Index " << index_name << endl;
		seg->SALFile << "DeltaNeeded," << greek_needed << endl
					 << "DeltaAsset," << delta_asset << endl
					 << "DeltaDiff," << delta_diff << endl;

		seg->SALFile << endl;
		seg->SALFile << "AssetID,HedgeGrpCode,DeltaAsset,SoldPct,NotionalSold,MktValSold,DeltaSold" << endl;
		}

	#if defined(__EIO_ASSET_H_)
	EIO_ASSET *eio_element = NULL;

	if (eio_mp_map_active.size() > 0)
		{
		int col_num_sold_pct_fund_match
		= asset->sm_eio[0]->Column("sold_pct_fund_match").Number();

		for (mp_map_iter = eio_mp_map_active.begin();
				mp_map_iter != eio_mp_map_active.end();
				mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (eio_element->hdg_grp_code.find("Delta") == string::npos)
				continue;

			if (hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC
				&& eio_element->hdg_grp_code.find(index_name) == string::npos)
				continue;

			if (t < eio_element->commencement_period
				|| (t == eio_element->commencement_period
					&& eio_element->purchased_bom_flag)
				|| (t > max(0, eio_element->commencement_period)
					&& (fabs(eio_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
						|| eio_element->Column(col_num_sold_pct_fund_match).Exists(t)))
				continue;

			// calculate delta for asset. Option values have already been determined in the strategy setup
			delta_indv_asset = (eio_element->opt_val_asset_up_1_bef_sale(t) - eio_element->opt_val_asset_down_1_bef_sale(t))
								* asset->sm_eio[mp]->pct_to_use;	

			double sold_pct = 0.0;

			// Delta liab is negative and delta_diff is negative, sell long positions
			if (greek_needed < 0.0 && delta_diff < 0.0 && delta_indv_asset > 0.0)
				{
				if (delta_asset_remaining - delta_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (delta_asset_remaining - greek_needed) / delta_indv_asset;
				}
			// Delta liab is negative and delta_diff is positive, sell short positions
			else if (greek_needed < 0.0 && delta_diff > 0.0 && delta_indv_asset < 0.0)
				{
				if (delta_asset_remaining - delta_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (delta_asset_remaining - greek_needed) / delta_indv_asset;
				}
			// Delta liab is positive and delta_diff is positive, sell short positions
			else if (greek_needed > 0.0 && delta_diff > 0.0 && delta_indv_asset < 0.0)
				{
				if (delta_asset_remaining - delta_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (delta_asset_remaining - greek_needed) / delta_indv_asset;
				}
			// Delta liab is positive and delta_diff is negative, sell long positions
			else if (greek_needed > 0.0 && delta_diff < 0.0 && delta_indv_asset > 0.0)
				{
				if (delta_asset_remaining - delta_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (delta_asset_remaining - greek_needed) / delta_indv_asset;
				}

			delta_sold = delta_indv_asset * sold_pct;
			eio_element->Column(col_num_sold_pct_fund_match).SetValue(t, sold_pct); 

			delta_sold_total += delta_sold;
			delta_asset_remaining -= delta_sold;

			sales_amt += eio_element->mkt_val_sold(t)
			             * eio_element->pct_to_use;

			if (hedge_strat_detail_flag)
				{
				seg->SALFile << eio_element->asset_id << ","
				             << eio_element->hdg_grp_code << ","
							 << delta_indv_asset << ","
							 << sold_pct << ","
							 << eio_element->notional_amt_sold(t) * eio_element->pct_to_use << ","
							 << eio_element->mkt_val_sold(t) * eio_element->pct_to_use << ","
							 << delta_sold << endl;
				}
			}			         
		}
	#endif

	// Erase existing map item and set new item
	asset_greeks_needed.erase(greek_needed_map_index);
	delta_diff = - (delta_asset - delta_sold_total - greek_needed);
	asset_greeks_needed[greek_needed_map_index] = delta_diff;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << "Sales Summary" << endl;
		seg->SALFile << "DeltaNeeded," << greek_needed << endl
					 << "DeltaAsset," << delta_asset << endl
		             << "DeltaSold," << delta_sold_total << endl
					 << "DeltaRemaining," << delta_diff << endl;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Delta Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return sales_amt;


}


//@@ END

//@@ START - delta_hedge_transaction_cost
// Delta Hedge Transaction Cost                                                                                             
// Column:DELTA_HEDGE_TRANSACTION_COST
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "delta_hedge_transaction_cost.HDG_GRP_COMP.for"
if (!delta_hedge_flag(t))
	return 0.0;

// Force call delta_hedge_inv_amt
delta_hedge_inv_amt(t);

double transaction_cost = 0.0;
double notional_amt_purch = 0.0;
double notional_amt_sold = 0.0;
int mp = 0;
mpmap::iterator mp_map_iter;

#if defined(__EIO_ASSET_H_)
EIO_ASSET *eio_element = NULL;

if (eio_mp_map_active.size() > 0)
	{
	for (mp_map_iter = eio_mp_map_active.begin();
		 mp_map_iter != eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		eio_element = company->sm_asset->sm_eio[mp];

		if (t < eio_element->commencement_period
			|| (t == eio_element->commencement_period
				&& eio_element->purchased_bom_flag)
			|| (t > max(0, eio_element->commencement_period)
				&& fabs(eio_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
			|| eio_element->hdg_grp_code.find("Delta") == string::npos)
			continue;

		notional_amt_sold = eio_element->notional_amt_sold(t) * eio_element->pct_to_use;
		notional_amt_purch = eio_element->notional_amt_purch(t) * eio_element->pct_to_use;		

		transaction_cost += (fabs(notional_amt_sold) + fabs(notional_amt_purch)) 
		                   * hedge_grp_delta_hedge_transaction_costs_bps / 10000.0;
		}			         
	}
#endif

return transaction_cost;

}


//@@ END

//@@ START - delta_index_1
// Delta Index 1                                                                                             
// Column:DELTA_INDEX_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_1(int t) {
//^^^



//^^^

#line 1 "delta_index_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 1)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_index_2
// Delta Index 2                                                                                             
// Column:DELTA_INDEX_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_2(int t) {
//^^^



//^^^

#line 1 "delta_index_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 2)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_index_3
// Delta Index 3                                                                                             
// Column:DELTA_INDEX_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_3(int t) {
//^^^



//^^^

#line 1 "delta_index_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 3)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_index_4
// Delta Index 4                                                                                             
// Column:DELTA_INDEX_4
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_4(int t) {
//^^^



//^^^

#line 1 "delta_index_4.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 4)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[3] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_index_5
// Delta Index 5                                                                                             
// Column:DELTA_INDEX_5
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_5(int t) {
//^^^



//^^^

#line 1 "delta_index_5.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 5)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[4] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_index_6
// Delta Index 6                                                                                             
// Column:DELTA_INDEX_6
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_6(int t) {
//^^^



//^^^

#line 1 "delta_index_6.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 6)
	return NO_AVG;

greek_index = "Delta_" + company->delta_gamma_hedge_index_list[5] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - delta_parallel
// Delta Parallel                                                                                             
// Column:DELTA_PARALLEL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_delta_parallel(int t) {
//^^^



//^^^

#line 1 "delta_parallel.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

greek_index = "Delta_Parallel_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - econ_cash
// Economic Cash Amount                                                                                             
// Column:ECON_CASH
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash(int t) {
//^^^



//^^^

#line 1 "econ_cash.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return econ_res(t) - hedge_mkt_val(t);

}


//@@ END

//@@ START - econ_cash_int
// Interest Earned on Economic Cash Amount                                                                                             
// Column:ECON_CASH_INT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash_int(int t) {
//^^^



//^^^

#line 1 "econ_cash_int.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return econ_cash(t - 1)
	* (pow(1.0 + econ_cash_int_rate(t), 1.0 / 12.0) - 1.0);

}


//@@ END

//@@ START - econ_cash_int_rate
// Economic Cash Interest Rate                                                                                             
// Column:ECON_CASH_INT_RATE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash_int_rate(int t) {
//^^^



//^^^

#line 1 "econ_cash_int_rate.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return rates->get_int_rate(((t == 0 && valn_period == 0)? t : t - 1),
                           "Govt",
                           GET_YIELD_RATE,
                           SHORT_TERM_RATE_TERM,
                           0.0,
                           EFFECTIVE_ANNUAL,
                           NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END

//@@ START - econ_prof
// Economic Profit                                                                                             
// Column:ECON_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_prof(int t) {
//^^^



//^^^

#line 1 "econ_prof.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return delta_hedge_prof(t)
	   + gamma_hedge_prof(t)
	   + vega_hedge_prof(t)
	   + rho_hedge_prof(t)
	   + rho_convex_hedge_prof(t)
	   + econ_cash_int(t)
	   + hedge_cost_charge(t)
	   - hedge_liab_claims(t)
	   - econ_res_incr(t);

}


//@@ END

//@@ START - econ_prof_unhedged
// Unhedged Economic Profit                                                                                             
// Column:ECON_PROF_UNHEDGED
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_prof_unhedged(int t) {
//^^^



//^^^

#line 1 "econ_prof_unhedged.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return econ_res_int(t)
	   + hedge_cost_charge(t)
	   - hedge_liab_claims(t)
	   - econ_res_incr(t);

}


//@@ END

//@@ START - econ_res
// Economic Reserve: Present Value of Claims - Present Value of Charges                                                                                             
// Column:ECON_RES
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res(int t) {
//^^^



//^^^

#line 1 "econ_res.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return this->pv_claims(0) - this->pv_charges(0);

xstring greek_index;

greek_index = "Baseline_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - econ_res_incr
// Economic Reserve Increase                                                                                             
// Column:ECON_RES_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res_incr(int t) {
//^^^



//^^^

#line 1 "econ_res_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return econ_res(t) - econ_res(t - 1);

}


//@@ END

//@@ START - econ_res_int
// Interest Earned on Economic Reserve                                                                                             
// Column:ECON_RES_INT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res_int(int t) {
//^^^



//^^^

#line 1 "econ_res_int.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return econ_res(t - 1) 
	   * (pow(1.0 + econ_cash_int_rate(t), 1.0 / 12.0) - 1.0);

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.HDG_GRP_COMP.for"
return 1.0;

}


//@@ END

//@@ START - fund_val_decrem
// Fund Value Decrements                                                                                             
// Column:FUND_VAL_DECREM
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_decrem(int t) {
//^^^



//^^^

#line 1 "fund_val_decrem.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_liabilities("fund_val_decrem", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - fund_val_decrem_cumul
// Fund Value Decrements Cumulative                                                                                             
// Column:FUND_VAL_DECREM_CUMUL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_decrem_cumul(int t) {
//^^^



//^^^

#line 1 "fund_val_decrem_cumul.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if ((t + valn_period) % hedge_grp_rebal_freq == 1 
	|| hedge_grp_rebal_freq == 1)	
	return fund_val_decrem(t);

return fund_val_decrem_cumul(t - 1)
       + fund_val_decrem(t);

}


//@@ END

//@@ START - fund_val_fixed
// Fund Value EOM                                                                                             
// Column:FUND_VAL_FIXED
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_fixed(int t) {
//^^^



//^^^

#line 1 "fund_val_fixed.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
return sum_over_liabilities("fund_val_e", t, END_OF_PERIOD)
       + sum_over_liabilities("fund_val_aft_pol_loan", t, END_OF_PERIOD);

}


//@@ END

//@@ START - gamma_hedge_flag
// Gamma Hedge Flag                                                                                             
// Column:GAMMA_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_flag(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || !gamma_vega_hedge_flag(t))
	return 0;

if (hedge_grp_gamma_vega_hedge_type_defn == VEGA)
	return 0;

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
	throw FatalError("Invalid GAMMA liab shock definition 'Index Term Specific'. Please correct your data.");

// Check for existing gamma hedge assets. If they exist, gamma hedge strategy is not executed at t == 0
if (t == 0)
	{
	#if defined(__EIO_ASSET_H_)
	int mp = 0;
	mpmap::iterator mp_map_iter;
	EIO_ASSET *eio_element = NULL;

	if (eio_mp_map_active.size() > 0)
		{
		for (mp_map_iter = eio_mp_map_active.begin();
			 mp_map_iter != eio_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (eio_element->hdg_grp_code.find("Gamma") < string::npos)
				return 0;
			}			         
		}
	#endif
	}

return 1.0;

}


//@@ END

//@@ START - gamma_hedge_inv_amt
// Gamma Hedge Investment Amount                                                                                             
// Column:GAMMA_HEDGE_INV_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_inv_amt.HDG_GRP_COMP.for"
if (!gamma_hedge_flag(t))
	return 0.0;
	
// Must first call delta hedge sales
gamma_hedge_sale_amt(t);

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Gamma Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Determine the asset gamma for each index
calc_asset_greeks(t, GAMMA, PURCH);

double inv_amt = 0.0;
map <xstring, double> gamma_hedge_coeff;
map <xstring, double> notional_to_purch;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC) // Just one loop for parallel hedging
	index_loops = company->delta_gamma_hedge_index_list.size();

for (int index = 0; index < index_loops; index++)
	{
	xstring index_name;

	// set lookup key
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
		hedge_grp_index_name = "Parallel";
	else
		hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];

	hedge_grp_index_term = "AllTerms";

	xstring greek_map_index = "Gamma_Purchase_" + hedge_grp_index_name + "_" + xstring(t);
	double gamma_asset_purch = asset_greeks[greek_map_index];

	// Asset greek needed has been updates for sales
	xstring greek_needed_map_index = "Gamma_" + hedge_grp_index_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	if (fabs(gamma_asset_purch) > model_point_amount_threshold)
		gamma_hedge_coeff[greek_needed_map_index] = greek_needed / gamma_asset_purch; 

	xstring hedge_grp_code = hedge_grp_id + "|Gamma|" + hedge_grp_index_name;

	xstring map_index = hedge_grp_index_name + "_" + xstring(t);
	xstring purch_hedge_index_name = get_purch_asset_index_name(seg_num, hedge_grp_index_name, hedge_grp_gamma_vega_hedge_asset_id);

	notional_to_purch[greek_needed_map_index] = ONE_MILLION * gamma_hedge_coeff[greek_needed_map_index];
	double notional_inv = notional_to_purch[greek_needed_map_index];

	if (fabs(notional_inv) > model_point_amount_threshold)
		{
		inv_amt += company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		YES, //save_assets
																		HEDGING,
																		new_mp_num,
																		hedge_grp_code,
																		hedge_grp_gamma_vega_hedge_asset_id,
																		notional_inv,
																		-1.0,
																		-1.0);

		// Add new element to the hedge group eio map
		if (new_mp_num < 0)
			throw FatalError("Unable to invest in new gamma hedge asset for hedge group " + hedge_grp_id + ". "
							 + "Please review your gamma hedge strategy data.");

		eio_mp_map_active[new_mp_num] = new_mp_num;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Gamma Hedge Investments Summary" << endl;
	seg->SALFile << "IndexName,GammaNeeded,AssetGamma,HedgeCoeff,NotionalPurch" << endl;

	for (int index = 0; index < index_loops; index++)
		{
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
			hedge_grp_index_name = "Parallel";
		else
			hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];

		// Asset greek needed has been updates for sales
		xstring greek_needed_map_index = "Gamma_" + hedge_grp_index_name + "_" + xstring(t);
		xstring greek_map_index = "Gamma_Purchase_" + hedge_grp_index_name + "_" + xstring(t);
		seg->SALFile << hedge_grp_index_name << ","
		             << asset_greeks_needed[greek_needed_map_index] << ","
					 << asset_greeks[greek_map_index] << ","
		             << gamma_hedge_coeff[greek_needed_map_index] << ","
		             << notional_to_purch[greek_needed_map_index] << endl;
		}
	}

gamma_hedge_coeff.clear();
notional_to_purch.clear();

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Gamma Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return inv_amt;

}


//@@ END

//@@ START - gamma_hedge_mkt_val
// Gamma Hedge Market Value of Assets                                                                                             
// Column:GAMMA_HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, GAMMA, END_OF_PERIOD);

}


//@@ END

//@@ START - gamma_hedge_mkt_val_incr
// Gamma Hedge Market Value of Assets Increase                                                                                             
// Column:GAMMA_HEDGE_MKT_VAL_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_mkt_val_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return gamma_hedge_mkt_val(t) - gamma_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - gamma_hedge_pmt
// Gamma Hedge Derivative Payment                                                                                             
// Column:GAMMA_HEDGE_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("opt_pmt", t, GAMMA, BEFORE_SALE);

}


//@@ END

//@@ START - gamma_hedge_prof
// Gamma Hedge Profit                                                                                             
// Column:GAMMA_HEDGE_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_prof(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_prof.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_gamma_vega_hedge_defn == NO || hedge_grp_gamma_vega_hedge_type_defn == VEGA)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

return gamma_hedge_pmt(t)
	   + gamma_hedge_sale_amt(t)
	   - gamma_hedge_inv_amt(t)
	   - gamma_hedge_transaction_cost(t)
	   + gamma_hedge_mkt_val_incr(t);

}


//@@ END

//@@ START - gamma_hedge_sale_amt
// Gamma Hedge Sale Amount                                                                                             
// Column:GAMMA_HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_sale_amt.HDG_GRP_COMP.for"
if (!gamma_hedge_flag(t))
	return 0.0;

// Must first call gamma hedge strategy to setup strategy
gamma_hedge_strat(t);

#if defined(__EIO_ASSET_H_)
// Do not process sales if there are no assets in the active map
if (!eio_mp_map_active.size())
	return 0.0;

// Do not process sales if there are no Gamma assets in the active map
int mp = 0;
bool gamma_hedges = false;
mpmap::iterator mp_map_iter;
EIO_ASSET *eio_element = NULL;
for (mp_map_iter = eio_mp_map_active.begin();
	mp_map_iter != eio_mp_map_active.end();
	mp_map_iter++)
	{
	mp = mp_map_iter->first;
	eio_element = company->sm_asset->sm_eio[mp];

	if (eio_element->hdg_grp_code.find("Gamma") < string::npos)
		{
		gamma_hedges = true;
		break;
		}
	}

if (!gamma_hedges)
	return 0.0;
#endif

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Gamma Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

double sales_amt = 0.0;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC) // Just one loop for parallel hedging
	index_loops = company->delta_gamma_hedge_index_list.size();

for (int index = 0; index < index_loops; index++)
	{
	int mp = 0;
	mpmap::iterator mp_map_iter;
	xstring index_name;
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
		index_name = "Parallel";
	else
		index_name = company->delta_gamma_hedge_index_list[index];

	// Asset greek needed from original strategy setup
	xstring greek_needed_map_index = "Gamma_" + index_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	xstring asset_greek_map_index = "Gamma_BefSale_" + index_name + "_" + xstring(t);
	double gamma_asset = asset_greeks[asset_greek_map_index];
	double gamma_diff = - (gamma_asset - greek_needed);
	double gamma_asset_remaining = gamma_asset;
	double gamma_indv_asset = 0.0;
	double gamma_sold = 0.0;
	double gamma_sold_total = 0.0;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << "Processing Hedge Sales for Index " << index_name << endl;
		seg->SALFile << "GammaNeeded," << greek_needed << endl
					 << "GammaAsset," << gamma_asset << endl
					 << "GammaDiff," << gamma_diff << endl;

		seg->SALFile << endl;
		seg->SALFile << "AssetID,HedgeGrpCode,GammaAsset,SoldPct,NotionalSold,MktValSold,GammaSold" << endl;

		}

	#if defined(__EIO_ASSET_H_)
	EIO_ASSET *eio_element = NULL;

	if (eio_mp_map_active.size() > 0)
		{
		int col_num_sold_pct_fund_match
		= asset->sm_eio[0]->Column("sold_pct_fund_match").Number();

		for (mp_map_iter = eio_mp_map_active.begin();
				mp_map_iter != eio_mp_map_active.end();
				mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (eio_element->hdg_grp_code.find("Gamma") == string::npos)
				continue;

			if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
				&& eio_element->hdg_grp_code.find(index_name) == string::npos)
				continue;

			if (t < eio_element->commencement_period
				|| (t == eio_element->commencement_period
					&& eio_element->purchased_bom_flag)
				|| (t > max(0, eio_element->commencement_period)
					&& (fabs(eio_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
						|| eio_element->Column(col_num_sold_pct_fund_match).Exists(t)))
				continue;

			// calculate gamma for asset. Option values have already been determined in the strategy setup
			gamma_indv_asset = (eio_element->opt_val_asset_up_1_bef_sale(t) + eio_element->opt_val_asset_down_1_bef_sale(t)
			                    - eio_element->opt_val_baseline_bef_sale(t) * 2.0)
								* asset->sm_eio[mp]->pct_to_use;	

			double sold_pct = 0.0;

			// gamma liab is negative and gamma_diff is negative, sell long positions
			if (greek_needed < 0.0 && gamma_diff < 0.0 && gamma_indv_asset > 0.0)
				{
				if (gamma_asset_remaining - gamma_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (gamma_asset_remaining - greek_needed) / gamma_indv_asset;
				}
			// gamma liab is negative and gamma_diff is positive, sell short positions
			else if (greek_needed < 0.0 && gamma_diff > 0.0 && gamma_indv_asset < 0.0)
				{
				if (gamma_asset_remaining - gamma_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (gamma_asset_remaining - greek_needed) / gamma_indv_asset;
				}
			// gamma liab is positive and gamma_diff is positive, sell short positions
			else if (greek_needed > 0.0 && gamma_diff > 0.0 && gamma_indv_asset < 0.0)
				{
				if (gamma_asset_remaining - gamma_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (gamma_asset_remaining - greek_needed) / gamma_indv_asset;
				}
			// gamma liab is positive and gamma_diff is negative, sell long positions
			else if (greek_needed > 0.0 && gamma_diff < 0.0 && gamma_indv_asset > 0.0)
				{
				if (gamma_asset_remaining - gamma_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (gamma_asset_remaining - greek_needed) / gamma_indv_asset;
				}

			gamma_sold = gamma_indv_asset * sold_pct;
			eio_element->Column(col_num_sold_pct_fund_match).SetValue(t, sold_pct); 

			gamma_sold_total += gamma_sold;
			gamma_asset_remaining -= gamma_sold;

			sales_amt += eio_element->mkt_val_sold(t)
			             * eio_element->pct_to_use;

			if (hedge_strat_detail_flag)
				{
				seg->SALFile << eio_element->asset_id << ","
				             << eio_element->hdg_grp_code << ","
							 << gamma_indv_asset << ","
							 << sold_pct << ","
							 << eio_element->notional_amt_sold(t) * eio_element->pct_to_use << ","
							 << eio_element->mkt_val_sold(t) * eio_element->pct_to_use << ","
							 << gamma_sold << endl;
				}
			}			         
		}
	#endif

	// Erase existing map item and set new item
	asset_greeks_needed.erase(greek_needed_map_index);
	gamma_diff = - (gamma_asset - gamma_sold_total - greek_needed);
	asset_greeks_needed[greek_needed_map_index] = gamma_diff;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << "Sales Summary" << endl;
		seg->SALFile << "GammaNeeded," << greek_needed << endl
					 << "GammaAsset," << gamma_asset << endl
		             << "GammaSold," << gamma_sold_total << endl
					 << "GammaRemaining," << gamma_diff << endl;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Gamma Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return sales_amt;


}


//@@ END

//@@ START - gamma_hedge_transaction_cost
// Gamma Hedge Transaction Cost                                                                                             
// Column:GAMMA_HEDGE_TRANSACTION_COST
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_transaction_cost.HDG_GRP_COMP.for"
if (!gamma_hedge_flag(t))
	return 0.0;

// Force call gaam_hedge_inv_amt
gamma_hedge_inv_amt(t);

double transaction_cost = 0.0;
double notional_amt_purch = 0.0;
double notional_amt_sold = 0.0;
int mp = 0;
mpmap::iterator mp_map_iter;

#if defined(__EIO_ASSET_H_)
EIO_ASSET *eio_element = NULL;

if (eio_mp_map_active.size() > 0)
	{
	for (mp_map_iter = eio_mp_map_active.begin();
		 mp_map_iter != eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		eio_element = company->sm_asset->sm_eio[mp];

		if (t < eio_element->commencement_period
			|| (t == eio_element->commencement_period
				&& eio_element->purchased_bom_flag)
			|| (t > max(0, eio_element->commencement_period)
				&& fabs(eio_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
			|| eio_element->hdg_grp_code.find("Gamma") < string:: npos)
			continue;

		notional_amt_sold = eio_element->notional_amt_sold(t) * eio_element->pct_to_use;
		notional_amt_purch = eio_element->notional_amt_purch(t) * eio_element->pct_to_use;		

		transaction_cost += (fabs(notional_amt_sold) + fabs(notional_amt_purch)) 
		                   * hedge_grp_gamma_vega_hedge_transaction_costs_bps / 10000.0;
		}			         
	}
#endif

return transaction_cost;

}


//@@ END

//@@ START - gamma_index_1
// Gamma Index 1                                                                                             
// Column:GAMMA_INDEX_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_1(int t) {
//^^^



//^^^

#line 1 "gamma_index_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 1)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_index_2
// Gamma Index 2                                                                                             
// Column:GAMMA_INDEX_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_2(int t) {
//^^^



//^^^

#line 1 "gamma_index_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 2)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_index_3
// Gamma Index 3                                                                                             
// Column:GAMMA_INDEX_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_3(int t) {
//^^^



//^^^

#line 1 "gamma_index_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 3)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_index_4
// Gamma Index 4                                                                                             
// Column:GAMMA_INDEX_4
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_4(int t) {
//^^^



//^^^

#line 1 "gamma_index_4.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 4)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[3] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_index_5
// Gamma Index 5                                                                                             
// Column:GAMMA_INDEX_5
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_5(int t) {
//^^^



//^^^

#line 1 "gamma_index_5.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 5)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[4] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_index_6
// Gamma Index 6                                                                                             
// Column:GAMMA_INDEX_6
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_6(int t) {
//^^^



//^^^

#line 1 "gamma_index_6.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->delta_gamma_hedge_index_list.size() < 6)
	return NO_AVG;

greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[5] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_parallel
// Gamma Parallel                                                                                             
// Column:GAMMA_PARALLEL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_parallel(int t) {
//^^^



//^^^

#line 1 "gamma_parallel.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

greek_index = "Gamma_Parallel_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - gamma_vega_hedge_flag
// Gamma Vega Hedge Flag                                                                                             
// Column:GAMMA_VEGA_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_vega_hedge_flag(int t) {
//^^^



//^^^

#line 1 "gamma_vega_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_gamma_vega_hedge_defn == NO)
	return 0;

if (t > 0 && (t % hedge_grp_gamma_vega_hedge_rebal_freq) != 0)
	return 0;

return 1.0;

}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flow                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call liability cash flow columns
liab_cash_flow_bom(t);
liab_cash_flow_eom(t);

// Control order of processing
// All these occur before ANY standard investment process
// Step 1: Purchase new hedges at bom
// Step 2: Obtain cash flow from hedging during month
// Step 3: Sell hedges for rebalancing eom
// Step 4: Process hedge sales and investments
// Step 5: Calculation transaction costs
double inv_amt_bom = hedge_inv_amt_bom(t);
double int_pmt = hedge_int_pmt(t);
double opt_pmt = hedge_opt_pmt(t);

// First, must process greek hedging in specific order to account for greek residuals
double gamma_inv_amt = gamma_hedge_inv_amt(t);
double vega_inv_amt = vega_hedge_inv_amt(t);
double delta_inv_amt = delta_hedge_inv_amt(t);
double rho_convex_inv_amt = rho_convex_hedge_inv_amt(t);
double rho_inv_amt = rho_hedge_inv_amt(t);

// Now, we can capture total sales and investment amounts and calculate expenses
double sale_amt = hedge_sale_amt(t);
double inv_amt_eom = hedge_inv_amt_eom(t);
double exp = hedge_exp(t);

return - inv_amt_bom
       + int_pmt
	   + opt_pmt
       + sale_amt
	   - inv_amt_eom
	   - exp;

}


//@@ END

//@@ START - hedge_cost_charge
// Hedge Cost Charge                                                                                             
// Column:HEDGE_COST_CHARGE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_cost_charge(int t) {
//^^^



//^^^

#line 1 "hedge_cost_charge.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_liabilities("gmab_chg", t, BEG_OF_PERIOD)
    + sum_over_liabilities("gmdb_chg", t, BEG_OF_PERIOD)
	+ sum_over_liabilities("gmib_chg", t, BEG_OF_PERIOD)
	+ sum_over_liabilities("gmwb_chg", t, BEG_OF_PERIOD);


}


//@@ END

//@@ START - hedge_exp
// Hedge Expense                                                                                             
// Column:HEDGE_EXP
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_exp(int t) {
//^^^



//^^^

#line 1 "hedge_exp.HDG_GRP_COMP.for"
double hedge_exp 
= delta_hedge_transaction_cost(t)
  + gamma_hedge_transaction_cost(t)
  + vega_hedge_transaction_cost(t)
  + rho_hedge_transaction_cost(t)
  + rho_convex_hedge_transaction_cost(t);

return hedge_exp;

}


//@@ END

//@@ START - hedge_int_pmt
// Hedge Interest Payment                                                                                             
// Column:HEDGE_INT_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_int_pmt(int t) {
//^^^



//^^^

#line 1 "hedge_int_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("int_pmt", t, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - hedge_inv_amt_bom
// Hedge Investment Amount Beginning of Month                                                                                             
// Column:HEDGE_INV_AMT_BOM
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_inv_amt_bom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_bom.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (fabs(notional_amt_to_hedge(t)) < aggregate_amount_threshold)
	return NO_AVG;

int bucket_size = seg->sm_hedge_grp[getElementNumber(0)].size();
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
xstring hedge_grp_code = hedge_grp_id;
investing_bom_flag = true;

if (bucket_size > 1)
	{
	xstring bucket_str = (getElementNumber(1) < 10) ? "0" + xstring(getElementNumber(1)) : xstring(getElementNumber(1));
	hedge_grp_code += "|Bucket_" + bucket_str;
	}

double inv_amt = company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
														YES, //save_assets
														HEDGING,
														new_mp_num,
														hedge_grp_code,
														hedge_grp_asset_id,
														notional_amt_to_hedge(t),
														long_strike(t),
														short_strike(t));

/*log_screen<<"t= "<<t
<<" hedge_grp_code= "<<hedge_grp_code
<<" notional_amt_to_hedge(t)= "<<notional_amt_to_hedge(t)
<<" long_strike(t)= "<<long_strike(t)
<<" short_strike(t)= "<<short_strike(t)
<<" inv_amt= "<<inv_amt
<<MSG_USER;*/
investing_bom_flag = false;

// Add new element to the hedge group eio map
if (new_mp_num < 0)
	throw FatalError("Unable to invest in new hedge asset for hedge group " + hedge_grp_code + ". "
	                 + "Please review your hedge group data.");

eio_mp_map_active[new_mp_num] = new_mp_num;

return inv_amt;


}


//@@ END

//@@ START - hedge_inv_amt_eom
// Hedge Investment Amount End of Month                                                                                             
// Column:HEDGE_INV_AMT_EOM
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_inv_amt_eom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_eom.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

double hedge_inv_amt
= delta_hedge_inv_amt(t)
  + gamma_hedge_inv_amt(t)
  + vega_hedge_inv_amt(t)
  + rho_hedge_inv_amt(t)
  + rho_convex_hedge_inv_amt(t);

return hedge_inv_amt;

}


//@@ END

//@@ START - hedge_liab_claims
// Hedge Liability GMXB Claims                                                                                             
// Column:HEDGE_LIAB_CLAIMS
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_liab_claims(int t) {
//^^^



//^^^

#line 1 "hedge_liab_claims.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_liabilities("maturity_claims_gmab", t, END_OF_PERIOD)
  	   + sum_over_liabilities("dth_claims_gmdb", t, END_OF_PERIOD)
	   + sum_over_liabilities("ann_claims_gmib", t, END_OF_PERIOD)
	   + sum_over_liabilities("ann_claims_gmwb", t, END_OF_PERIOD);

}


//@@ END

//@@ START - hedge_mkt_val
// Hedge Market Value                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - hedge_notional_amt
// Hedge Notional Amount                                                                                             
// Column:HEDGE_NOTIONAL_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_notional_amt(int t) {
//^^^



//^^^

#line 1 "hedge_notional_amt.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("notional_amt", t, SUM_OVER_ALL, END_OF_PERIOD);

}


//@@ END

//@@ START - hedge_notional_amt_available
// Hedge Notional Amount Available                                                                                             
// Column:HEDGE_NOTIONAL_AMT_AVAILABLE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_notional_amt_available(int t) {
//^^^



//^^^

#line 1 "hedge_notional_amt_available.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("notional_amt_bef_fund_match_sale", t, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - hedge_opt_pmt
// Hedge Option Payment                                                                                             
// Column:HEDGE_OPT_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_opt_pmt(int t) {
//^^^



//^^^

#line 1 "hedge_opt_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("opt_pmt", t, SUM_OVER_ALL, BEFORE_SALE);

}


//@@ END

//@@ START - hedge_sale_amt
// Hedge Sales Amount                                                                                             
// Column:HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "hedge_sale_amt.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (hedge_proj_stmt_flag) // Hedging is for VA greeks
	{
	double hedge_sale_amt 
	= delta_hedge_sale_amt(t)
	  + gamma_hedge_sale_amt(t)
	  + vega_hedge_sale_amt(t)
	  + rho_hedge_sale_amt(t)
	  + rho_convex_hedge_sale_amt(t);

	return hedge_sale_amt;
	}
// else hedging is for FIA/IUL option budget notional amounts
if (t == start_period || (t + valn_period) % hedge_grp_rebal_freq != 0)
	return NO_AVG;

if (hedge_notional_amt_available(t) < notional_amt_required(t))
	return NO_AVG;

if (fabs(hedge_notional_amt_available(t) - notional_amt_required(t)) < aggregate_amount_threshold)
	return NO_AVG; 

if (fabs(hedge_notional_amt_available(t)) < aggregate_amount_threshold)
	return NO_AVG;

int seg_num = seg->getElementNumber();

return company->sm_inv_strategy[seg_num]->sell_assets_hedges(t, eio_mp_map_active, 
											    hedge_notional_amt_available(t), 
												notional_amt_required(t),
												hedge_grp_id);

}


//@@ END

//@@ START - index_val
// Underlying Equity Index                                                                                             
// Column:INDEX_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_index_val(int t) {
//^^^



//^^^

#line 1 "index_val.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;
	
if (fabs(notional_to_hedge(t)) < rate_ratio_threshold)
	return NO_AVG;

return notional_amt_to_hedge_index (t) / notional_to_hedge(t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.HDG_GRP_COMP.for"
// clear asset elements out of memory from hedge_grp map
eio_mp_map_active.clear();
ird_mp_map_active.clear(); 

int hedge_grp_liab_counter = 0;
int hedge_grp_asset_counter = 0;
int bucket_size = 1;

#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
if (!hedge_valn_flag)
	{
	if (hedge_grp_crediting_defn != POINT_TO_POINT
		&& hedge_grp_crediting_defn != MOVING_AVERAGE)
		throw FatalError("Only hedging for crediting method of point to point and moving average is supported.");
	}
#endif

vector <string> plan_codes;
plan_codes.clear();

// parse and stores plan codes into vector
split_string_usl(hedge_grp_plan_codes.c_str(), plan_codes, ",");//WTW - Gen2 - split_tring internal RAFM function

//liability mapping (begin)
#if defined(__VA_LIAB_H_)
if (independent_mp_defn == YES)
	hedge_grp_liab_counter = hedge_grp_liab_counter + 1;
for (int mp = 0; mp < liab->sm_va.size(); mp++) 
	{
	// mapping process starts		
	int in_hedge_group = 0;
	for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
		{
		xstring mp_plan_code = xstring(liab->sm_va[mp]->plan_code);
		
		if ((xstring(plan_codes[plan_count]) == "ALL" 
			|| eq(mp_plan_code, xstring(plan_codes[plan_count]))))
			{
			//liab->sm_va[mp]->hedge_grp_code = hedge_grp_id; 
			hedge_grp_liab_counter = hedge_grp_liab_counter + 1;
			in_hedge_group = 1;
			}
		}
	liab->sm_va[mp]->hedge_grp_code[hedge_grp_count_id] = in_hedge_group;
	}
#endif	

#if defined(__FIA_LIAB_H_)
for (int mp = 0; mp < liab->sm_fia.size(); mp++) 
	{
	liab->sm_fia[mp]->pol_yr_lookup_gen2 = liab->sm_fia[mp]->pol_yr(0); //WTW - Gen2 - add working variable for lookups that vary by time for character input

	int sub_fv_size = liab->sm_fia[mp]->sm_fia_account.size();
	for (int sub_fv = 0; sub_fv < sub_fv_size; sub_fv++)
		{
		xstring mp_plan_code = xstring(liab->sm_fia[mp]->plan_code);
		int mp_fia_cred_defn = liab->sm_fia[mp]->sm_fia_account[sub_fv]->crediting_rate_defn;
		int mp_fia_cred_mths = liab->sm_fia[mp]->sm_fia_account[sub_fv]->crediting_mths;
		int mp_fia_dyn_lever = liab->sm_fia[mp]->sm_fia_account[sub_fv]->crediting_dyn_lever;//WTW - Gen2 - character input that varies by time
		xstring mp_fia_index = liab->sm_fia[mp]->sm_fia_account[sub_fv]->crediting_eqt_index;
		xstring mp_hedge_grp = liab->sm_fia[mp]->sm_fia_account[sub_fv]->hedge_grp_code;
		
		// mapping process starts		
		for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
			{
			if ((xstring(plan_codes[plan_count]) == "ALL" 
				|| eq(mp_plan_code, xstring(plan_codes[plan_count]))) // case insensitive 
				&& mp_fia_cred_defn == hedge_grp_crediting_defn
				&& mp_fia_cred_mths == hedge_grp_crediting_mths
				&& mp_fia_dyn_lever == hedge_grp_dyn_lever 
				&& mp_fia_index == hedge_grp_index)
				{
				liab->sm_fia[mp]->sm_fia_account[sub_fv]->hedge_grp_code = hedge_grp_id;
				hedge_grp_liab_counter = hedge_grp_liab_counter + 1;
				}
			}
		}				
	}
#endif	

#if defined(__IUL_LIAB_H_)
// For IUL hedging, bucket_size for hedge_grp must always be the hedge crediting months
bucket_size = hedge_grp_crediting_mths;

for (int mp = 0; mp < liab->sm_iul.size(); mp++) 
	{
	int sub_fv_size = liab->sm_iul[mp]->sm_iul_account.size();

	for (int sub_fv = 0; sub_fv < sub_fv_size; sub_fv++)
		{
		if (liab->sm_iul[mp]->sm_iul_account[sub_fv][0]->fund_type == FIXED_FUND)
			continue;

		int iul_account_bucket_size = liab->sm_iul[mp]->sm_iul_account[sub_fv].size(); 

		xstring mp_plan_code = xstring(liab->sm_iul[mp]->plan_code);
		int mp_iul_cred_defn = liab->sm_iul[mp]->sm_iul_account[sub_fv][0]->crediting_rate_defn;
		int mp_iul_cred_mths = liab->sm_iul[mp]->sm_iul_account[sub_fv][0]->crediting_mths;
		xstring mp_iul_index = liab->sm_iul[mp]->sm_iul_account[sub_fv][0]->crediting_eqt_index;
		xstring mp_hedge_grp = liab->sm_iul[mp]->sm_iul_account[sub_fv][0]->hedge_grp_code;

		// mapping process starts		
		for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
			{
			if ((xstring(plan_codes[plan_count]) == "ALL" 
				|| eq(mp_plan_code, xstring(plan_codes[plan_count]))) // case insensitive 
				&& mp_iul_cred_defn == hedge_grp_crediting_defn
				&& mp_iul_cred_mths == hedge_grp_crediting_mths
				&& mp_iul_index == hedge_grp_index)
				{
				for (int bucket = 0; bucket < iul_account_bucket_size; bucket++)
					{
					int bucket_num = liab->sm_iul[mp]->sm_iul_account[sub_fv][bucket]->bucket_num;
					xstring bucket_str = (bucket_num < 10) ? "0" + xstring(bucket_num) : xstring(bucket_num);
					liab->sm_iul[mp]->sm_iul_account[sub_fv][bucket]->hedge_grp_code = hedge_grp_id + "|Bucket_" + bucket_str;
					}

				hedge_grp_liab_counter = hedge_grp_liab_counter + 1;
				}
			}
		}				
	}
#endif
//liability mapping (end)

//asset - eio mapping (begin)
#if defined(__EIO_ASSET_H_)
vector <string> eio_hedge_grp;
for (int mp = 0; mp < asset->sm_eio.size(); mp++) 
	{
	eio_hedge_grp.clear();

	if (asset->sm_eio[mp]->port_defn != HEDGING)
		continue;

	// parse and stores separate hedge group and bucket number into string vector
	split_string_usl(asset->sm_eio[mp]->hdg_grp_code.c_str(), eio_hedge_grp, "|");//WTW - Gen2 - split_tring internal RAFM function
	if (eio_hedge_grp.size() <= 1) // No buckets or greek information, simple mapping of assets to hedge groups
		{
		xstring mp_hedge_grp = asset->sm_eio[mp]->hdg_grp_code;

		// mapping process starts		
		if (mp_hedge_grp == hedge_grp_id)
			{
			hedge_grp_asset_counter += 1;
			eio_mp_map_active[mp] = mp;
			}			
		}
	else if (eio_hedge_grp[1].find("Bucket") == string::npos) // No buckets, but greek hedge information
		{
		xstring mp_hedge_grp = eio_hedge_grp[0];

		// mapping process starts		
		if (mp_hedge_grp == hedge_grp_id)
			{
			hedge_grp_asset_counter += 1;
			eio_mp_map_active[mp] = mp;
			}			
		}
	else // index options are mapped to each bucket for IUL hedging
		{
		xstring mp_hedge_grp = eio_hedge_grp[0];
		int hedge_bucket = atoi(eio_hedge_grp[1].substr(eio_hedge_grp[1].find_last_of("_") + 1).c_str());

		// mapping process starts		
		if (mp_hedge_grp == hedge_grp_id && getElementNumber(1) == hedge_bucket)
			{
			hedge_grp_asset_counter += 1;
			eio_mp_map_active[mp] = mp;
			}			
		}
	}
#endif
//asset - eio mapping (end)

//asset - ird mapping (begin)
#if defined(__IRD_ASSET_H_)
vector <string> ird_hedge_grp;
for (int mp = 0; mp < asset->sm_ird.size(); mp++) 
	{
	ird_hedge_grp.clear();

	if (asset->sm_ird[mp]->port_defn != HEDGING)
		continue;

	// parse and stores separate hedge group and bucket number into string vector
	split_string_usl(asset->sm_ird[mp]->hdg_grp_code.c_str(), ird_hedge_grp, "|");//WTW - Gen2 - split_tring internal RAFM function
	if (ird_hedge_grp.size() <= 1) // No buckets or greek information, simple mapping of assets to hedge groups
		{
		xstring mp_hedge_grp = asset->sm_ird[mp]->hdg_grp_code;

		// mapping process starts		
		if (mp_hedge_grp == hedge_grp_id)
			{
			hedge_grp_asset_counter += 1;
			ird_mp_map_active[mp] = mp;
			}			
		}
	else // greek information is included
		{
		xstring mp_hedge_grp = ird_hedge_grp[0];

		// mapping process starts		
		if (mp_hedge_grp == hedge_grp_id)
			{
			hedge_grp_asset_counter += 1;
			ird_mp_map_active[mp] = mp;
			}			
		}
	}
#endif
//asset - ird mapping (end)

// set hedge_grp id as group name, crucial as this will be used as the key id to retrieve values from the output files
if (hedge_grp_liab_counter + hedge_grp_asset_counter > 0)
	{	
	xstring hedge_grp_group = hedge_grp_id;

	if (bucket_size > 1)
		{
		xstring bucket_str = (getElementNumber(1) < 10) ? "0" + xstring(getElementNumber(1)) : xstring(getElementNumber(1));
		hedge_grp_group += "|Bucket_" + bucket_str;
		}

	if (hedge_valn_shock_flag)
		{
		xstring shock_group_name_full = company->hedge_valn_shock_list[proj_task_loop_num - 1];
		xstring shock_group_name;
		shock_group_name = shock_group_name_full(0, shock_group_name_full.find("|TaskLoopIncr-"));

		hedge_grp_group += "|" + shock_group_name;
		}

	if (hedge_valn_final_flag)
		{
		xstring shock_list_id = company->hedge_valn_shock_list[hedge_grp_bucket_id];
		hedge_grp_group += "|" + shock_list_id;
		}

	this->setGroup(hedge_grp_group);
	}	
	
// Update counters in segment
seg->hedge_grp_asset_counter = hedge_grp_asset_counter;
seg->hedge_grp_liab_counter = hedge_grp_liab_counter;

if (hedge_valn_final_flag)
	get_hedge_valn_results();

if (hedge_proj_stmt_flag)
	get_hedge_valn_final_results();

return 1.0;

}


//@@ END

//@@ START - liab_cash_flow_bom
// Liability Cash Flow Beginning of Month                                                                                             
// Column:LIAB_CASH_FLOW_BOM
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_liab_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "liab_cash_flow_bom.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_liabilities("direct_cash_flow_bom", t, BEG_OF_PERIOD)
       - sum_over_liabilities("reins_cash_flow_bom", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - liab_cash_flow_eom
// Liability Cash Flow End of Month                                                                                             
// Column:LIAB_CASH_FLOW_EOM
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_liab_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "liab_cash_flow_eom.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_liabilities("direct_cash_flow_eom", t, END_OF_PERIOD)
       - sum_over_liabilities("reins_cash_flow_eom", t, END_OF_PERIOD);

}


//@@ END

//@@ START - long_strike
// Long Strike                                                                                             
// Column:LONG_STRIKE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_long_strike(int t) {
//^^^



//^^^

#line 1 "long_strike.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

if (fabs(notional_to_hedge(t)) < rate_ratio_threshold)
	return NO_AVG;

return notional_amt_to_hedge_long_strike(t) / notional_to_hedge(t);

}


//@@ END

//@@ START - notional_amt_required
// Notional Amount Required                                                                                             
// Column:NOTIONAL_AMT_REQUIRED
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_required(int t) {
//^^^



//^^^

#line 1 "notional_amt_required.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return hedge_notional_amt_available(t) - fund_val_decrem_cumul(t);

}


//@@ END

//@@ START - notional_amt_to_hedge
// Notional Amount To Hedge                                                                                             
// Column:NOTIONAL_AMT_TO_HEDGE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge(int t) {
//^^^



//^^^

#line 1 "notional_amt_to_hedge.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("notional_to_hedge_net", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - notional_amt_to_hedge_cap
// Notional Amount To Hedge Cap                                                                                             
// Column:NOTIONAL_AMT_TO_HEDGE_CAP
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_cap(int t) {
//^^^



//^^^

#line 1 "notional_amt_to_hedge_cap.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("notional_to_hedge_cap", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - notional_amt_to_hedge_index
// Notional Amount To Hedge Index                                                                                             
// Column:NOTIONAL_AMT_TO_HEDGE_INDEX
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_index(int t) {
//^^^



//^^^

#line 1 "notional_amt_to_hedge_index.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("notional_to_hedge_index", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - notional_amt_to_hedge_long_strike
// Notional Amount To Hedge Long Strike                                                                                             
// Column:NOTIONAL_AMT_TO_HEDGE_LONG_STRIKE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_long_strike(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"notional_amt_to_hedge_long_strike",t);
}



//^^^

#line 1 "notional_amt_to_hedge_long_strike.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("notional_to_hedge_long_strike", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - notional_to_hedge
// Notional To Hedge                                                                                             
// Column:NOTIONAL_TO_HEDGE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_notional_to_hedge(int t) {
//^^^



//^^^

#line 1 "notional_to_hedge.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("notional_to_hedge", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - opt_budget
// Option Budget                                                                                             
// Column:OPT_BUDGET
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_opt_budget(int t) {
//^^^



//^^^

#line 1 "opt_budget.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;
	
if (fabs(notional_to_hedge(t)) < rate_ratio_threshold)
	return NO_AVG;

return opt_budget_amt(t) / notional_to_hedge(t);

}


//@@ END

//@@ START - opt_budget_amt
// Option Budget Amount                                                                                             
// Column:OPT_BUDGET_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_opt_budget_amt(int t) {
//^^^



//^^^

#line 1 "opt_budget_amt.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("opt_budget_amt", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - opt_payoff
// Option Payoff                                                                                             
// Column:OPT_PAYOFF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_opt_payoff(int t) {
//^^^



//^^^

#line 1 "opt_payoff.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return sum_over_liabilities("opt_payoff", t, BEG_OF_PERIOD);

}


//@@ END

//@@ START - part_rate
// Participation Rate                                                                                             
// Column:PART_RATE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_part_rate(int t) {
//^^^



//^^^

#line 1 "part_rate.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

if (fabs( notional_to_hedge(t)) < rate_ratio_threshold)
	return NO_AVG;

return  notional_amt_to_hedge(t) / notional_to_hedge(t);

}


//@@ END

//@@ START - proj_tgt_hedge_stmt
// Projection Target - Hedging Statement Calculations                                                                                             
// Column:PROJ_TGT_HEDGE_STMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_proj_tgt_hedge_stmt(int t) {
//^^^



//^^^

#line 1 "proj_tgt_hedge_stmt.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

econ_res(t);

delta_index_1(t);
delta_index_2(t);
delta_index_3(t);
delta_index_4(t);
delta_index_5(t);
delta_index_6(t);
delta_parallel(t);

gamma_index_1(t);
gamma_index_2(t);
gamma_index_3(t);
gamma_index_4(t);
gamma_index_5(t);
gamma_index_6(t);
gamma_parallel(t);

rho_key_rate_1(t);
rho_key_rate_2(t);
rho_key_rate_3(t);
rho_key_rate_4(t);
rho_key_rate_5(t);
rho_key_rate_6(t);
rho_key_rate_7(t);
rho_key_rate_8(t);
rho_key_rate_9(t);
rho_key_rate_10(t);
rho_parallel(t);

rho_convex_key_rate_1(t);
rho_convex_key_rate_2(t);
rho_convex_key_rate_3(t);
rho_convex_key_rate_4(t);
rho_convex_key_rate_5(t);
rho_convex_key_rate_6(t);
rho_convex_key_rate_7(t);
rho_convex_key_rate_8(t);
rho_convex_key_rate_9(t);
rho_convex_key_rate_10(t);
rho_convex_parallel(t);

vega_index_1_term_1(t);
vega_index_1_term_2(t);
vega_index_1_term_3(t);
vega_index_2_term_1(t);
vega_index_2_term_2(t);
vega_index_2_term_3(t);
vega_index_3_term_1(t);
vega_index_3_term_2(t);
vega_index_3_term_3(t);
vega_index_4_term_1(t);
vega_index_4_term_2(t);
vega_index_4_term_3(t);
vega_index_5_term_1(t);
vega_index_5_term_2(t);
vega_index_5_term_3(t);
vega_index_6_term_1(t);
vega_index_6_term_2(t);
vega_index_6_term_3(t);

vega_index_1(t);
vega_index_2(t);
vega_index_3(t);
vega_index_4(t);
vega_index_5(t);
vega_index_6(t);

vega_parallel(t);

// Force call the columns to execute the hedge statement calculations
hedge_cash_flow(t);
hedge_mkt_val(t);

econ_prof(t);
econ_prof_unhedged(t);

// Force call to reporting elements in submodel
sum_over_liabilities("gmab_inf", t, END_OF_PERIOD);
sum_over_liabilities("gmdb_inf", t, END_OF_PERIOD);
sum_over_liabilities("gmib_inf", t, END_OF_PERIOD);
sum_over_liabilities("gmdb_inf", t, END_OF_PERIOD);

return 1.0;

}


//@@ END

//@@ START - pv_charges
// Present Value of Charges                                                                                             
// Column:PV_CHARGES
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_pv_charges(int t) {
//^^^



//^^^

#line 1 "pv_charges.HDG_GRP_COMP.for"
if (!hedge_valn_flag || t > 0)
	return NO_AVG;

if (hedge_valn_final_flag)
	return hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CHARGES];

vector <string> plan_codes;
plan_codes.clear();

// parse and stores plan codes into vector
split_string_usl(hedge_grp_plan_codes.c_str(), plan_codes, ",");//WTW - Gen2 - split_tring internal RAFM function

double hedge_group_pv_charges = 0.0;
xstring index;

for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
	{	
	if (hedge_grp_gmab_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMAB_Fees";
		hedge_group_pv_charges += seg->va_hedge_vals[index];		
		}

	if (hedge_grp_gmdb_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMDB_Fees";
		hedge_group_pv_charges += seg->va_hedge_vals[index];		
		}
							
	if (hedge_grp_gmib_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMIB_Fees";
		hedge_group_pv_charges += seg->va_hedge_vals[index];		
		}

	if (hedge_grp_gmwb_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMWB_Fees";
		hedge_group_pv_charges += seg->va_hedge_vals[index];		
		}
	}
return hedge_group_pv_charges;

}


//@@ END

//@@ START - pv_claims
// Present Value of Claims                                                                                             
// Column:PV_CLAIMS
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_pv_claims(int t) {
//^^^



//^^^

#line 1 "pv_claims.HDG_GRP_COMP.for"
if (!hedge_valn_flag || t > 0)
	return NO_AVG;

if (hedge_valn_final_flag)
	return hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CLAIMS];

vector <string> plan_codes;
plan_codes.clear();

// parse and stores plan codes into vector
split_string_usl(hedge_grp_plan_codes.c_str(), plan_codes, ",");//WTW - Gen2 - split_tring internal RAFM function

double hedge_group_pv_claims = 0.0;
xstring index;

for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
	{

	if (hedge_grp_gmab_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMAB_Claims";
		hedge_group_pv_claims += seg->va_hedge_vals[index];		
		}

	if (hedge_grp_gmdb_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMDB_Claims";
		hedge_group_pv_claims += seg->va_hedge_vals[index];		
		}
							
	if (hedge_grp_gmib_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMIB_Claims";
		hedge_group_pv_claims += seg->va_hedge_vals[index];		
		}

	if (hedge_grp_gmwb_defn == YES)
		{
		index = xstring(plan_codes[plan_count]) + "_GMWB_Claims";
		hedge_group_pv_claims += seg->va_hedge_vals[index];		
		}
	}

return hedge_group_pv_claims;

}


//@@ END

//@@ START - rho_convex_hedge_flag
// Rho Convexity Hedge Flag                                                                                             
// Column:RHO_CONVEX_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_flag(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_rho_convex_hedge_defn == NO)
	return 0;

if (t > 0 && (t % hedge_grp_rho_convex_hedge_rebal_freq) != 0)
	return 0;

// Check for existing rho convex hedge assets. If they exist, rho convex hedge strategy is not executed at t == 0
if (t == 0)
	{
	#if defined(__IRD_ASSET_H_)
	int mp = 0;
	mpmap::iterator mp_map_iter;
	IRD_ASSET *ird_element = NULL;

	if (ird_mp_map_active.size() > 0)
		{
		for (mp_map_iter = ird_mp_map_active.begin();
			 mp_map_iter != ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if (ird_element->hdg_grp_code.find("RhoConvexity") < string::npos)
				return 0;
			}			         
		}
	#endif
	}

return 1;

}


//@@ END

//@@ START - rho_convex_hedge_inv_amt
// Rho Convexity Hedge Investment Amount                                                                                             
// Column:RHO_CONVEX_HEDGE_INV_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_inv_amt.HDG_GRP_COMP.for"
if (!rho_convex_hedge_flag(t))
	return 0.0;
	
// Must first call rho convexity hedge sales
rho_convex_hedge_sale_amt(t);

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Rho Convexity Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Determine the asset rho convexity for each key rate
calc_asset_greeks(t, RHO_CONVEXITY, PURCH);

double inv_amt = 0.0;
map <xstring, double> rho_convex_hedge_coeff;
map <xstring, double> notional_to_purch;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int key_rate_loops = 1;

if (hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC)
	key_rate_loops = company->rho_hedge_key_rate_list.size();

for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
	{
	// set lookup key
	if (hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL)
		hedge_grp_key_rate = "Parallel";
	else
		hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

	xstring greek_map_index = "RhoConvexity_Purchase_" + hedge_grp_key_rate + "_" + xstring(t);
	double rho_convex_asset_purch = asset_greeks[greek_map_index];

	// Asset greek needed has been updates for sales
	xstring greek_needed_map_index = "RhoConvexity_" + hedge_grp_key_rate + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	if (fabs(rho_convex_asset_purch) > model_point_amount_threshold)
		rho_convex_hedge_coeff[greek_needed_map_index] = greek_needed / rho_convex_asset_purch; 

	xstring hedge_grp_code = hedge_grp_id + "|RhoConvexity|" + hedge_grp_key_rate;

	notional_to_purch[greek_needed_map_index] = ONE_MILLION * rho_convex_hedge_coeff[greek_needed_map_index];
	double notional_inv = notional_to_purch[greek_needed_map_index];

	if (fabs(notional_inv) > model_point_amount_threshold)
		{
		inv_amt += company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		YES, //save_assets
																		HEDGING,
																		new_mp_num,
																		hedge_grp_code,
																		hedge_grp_rho_convex_hedge_asset_id,
																		notional_inv,
																		-1.0,
																		-1.0);

		// Add new element to the hedge group ird map
		if (new_mp_num < 0)
			throw FatalError("Unable to invest in new rho convexity hedge asset for hedge group " + hedge_grp_id + ". "
								+ "Please review your rho convexity hedge strategy data.");

		ird_mp_map_active[new_mp_num] = new_mp_num;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Rho Convexity Hedge Investments Summary" << endl;
	seg->SALFile << "KeyRateTermName,RhoConvexNeeded,AssetRhoConvex,HedgeCoeff,NotionalPurch" << endl;

	for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
		{
		// set lookup key
		if (hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL)
			hedge_grp_key_rate = "Parallel";
		else
			hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

		// Asset greek needed has been updates for sales
		xstring greek_needed_map_index = "RhoConvexity_" + hedge_grp_key_rate + "_" + xstring(t);
		xstring greek_map_index = "RhoConvexity_Purchase_" + hedge_grp_key_rate + "_" + xstring(t);
		seg->SALFile << hedge_grp_key_rate << ","
		             << asset_greeks_needed[greek_needed_map_index] << ","
					 << asset_greeks[greek_map_index] << ","
		             << rho_convex_hedge_coeff[greek_needed_map_index] << ","
		             << notional_to_purch[greek_needed_map_index] << endl;
		}
	}

rho_convex_hedge_coeff.clear();
notional_to_purch.clear();

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Rho Convexity Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return inv_amt;

}


//@@ END

//@@ START - rho_convex_hedge_mkt_val
// Rho Convexity Hedge Market Value of Assets                                                                                             
// Column:RHO_CONVEX_HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, RHO_CONVEXITY, END_OF_PERIOD);

}


//@@ END

//@@ START - rho_convex_hedge_mkt_val_incr
// Rho Convexity Hedge Market Value of Assets Increase                                                                                             
// Column:RHO_CONVEX_HEDGE_MKT_VAL_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_mkt_val_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return rho_convex_hedge_mkt_val(t) - rho_convex_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - rho_convex_hedge_pmt
// Rho Convexity Hedge Derivative Payment                                                                                             
// Column:RHO_CONVEX_HEDGE_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("int_pmt", t, RHO_CONVEXITY, BEFORE_SALE);

}


//@@ END

//@@ START - rho_convex_hedge_prof
// Rho Convexity Hedge Profit                                                                                             
// Column:RHO_CONVEX_HEDGE_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_prof(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_prof.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_rho_convex_hedge_defn == NO)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

return rho_convex_hedge_pmt(t)
	   + rho_convex_hedge_sale_amt(t)
	   - rho_convex_hedge_inv_amt(t)
	   - rho_convex_hedge_transaction_cost(t)
	   + rho_convex_hedge_mkt_val_incr(t); 

}


//@@ END

//@@ START - rho_convex_hedge_sale_amt
// Rho Convexity Hedge Sale Amount                                                                                             
// Column:RHO_CONVEX_HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_sale_amt.HDG_GRP_COMP.for"
if (!rho_convex_hedge_flag(t))
	return 0.0;

// Must first call rho convexity hedge strategy to setup strategy
rho_convex_hedge_strat(t);

#if defined(__IRD_ASSET_H_)
// Do not process sales if there are no assets in the active map
if (!ird_mp_map_active.size())
	return 0.0;

// Do not process sales if there are no Rho convexity assets in the active map
int mp = 0;
bool rho_convex_hedges = false;
mpmap::iterator mp_map_iter;
IRD_ASSET *ird_element = NULL;
for (mp_map_iter = ird_mp_map_active.begin();
	mp_map_iter != ird_mp_map_active.end();
	mp_map_iter++)
	{
	mp = mp_map_iter->first;
	ird_element = company->sm_asset->sm_ird[mp];

	if (ird_element->hdg_grp_code.find("RhoConvexity") < string::npos)
		{
		rho_convex_hedges = true;
		break;
		}
	}

if (!rho_convex_hedges)
	return 0.0;
#endif

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Rho Convexity Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

double sales_amt = 0.0;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int key_rate_loops = 1;
if (hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC) // Just one loop for parallel hedging
	key_rate_loops = company->rho_hedge_key_rate_list.size();

for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
	{
	int mp = 0;
	mpmap::iterator mp_map_iter;
	xstring key_rate_name;
	if (hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL)
		key_rate_name = "Parallel";
	else
		key_rate_name = company->rho_hedge_key_rate_list[key_rate];

	// Asset greek needed from original strategy setup
	xstring greek_needed_map_index = "RhoConvexity_" + key_rate_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	xstring asset_greek_map_index = "RhoConvexity_BefSale_" + key_rate_name + "_" + xstring(t);
	double rho_convex_asset = asset_greeks[asset_greek_map_index];
	double rho_convex_diff = - (rho_convex_asset - greek_needed);
	double rho_convex_asset_remaining = rho_convex_asset;
	double rho_convex_indv_asset = 0.0;
	double rho_convex_sold = 0.0;
	double rho_convex_sold_total = 0.0;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << "Processing Hedge Sales for Key Rate Term " << key_rate_name << endl;
		seg->SALFile << "RhoConvexNeeded," << greek_needed << endl
					 << "RhoConvexAsset," << rho_convex_asset << endl
					 << "RhoConvexDiff," << rho_convex_diff << endl;

		seg->SALFile << endl;
		seg->SALFile << "AssetID,HedgeGrpCode,RhoConvexAsset,SoldPct,NotionalSold,MktValSold,RhoConvexSold" << endl;
		}

	#if defined(__IRD_ASSET_H_)
	IRD_ASSET *ird_element = NULL;

	if (ird_mp_map_active.size() > 0)
		{
		int col_num_sold_pct_fund_match
		= asset->sm_ird[0]->Column("sold_pct_fund_match").Number();

		for (mp_map_iter = ird_mp_map_active.begin();
			 mp_map_iter != ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if (ird_element->hdg_grp_code.find("RhoConvexity|") == string::npos)
				continue;

			if (ird_element->hdg_grp_code.find(key_rate_name) == string::npos)
				continue;

			if (t < ird_element->commencement_period
				|| (t > max(0, ird_element->commencement_period)
					&& (fabs(ird_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
						|| ird_element->Column(col_num_sold_pct_fund_match).Exists(t)))
				continue;

			// calculate Rho for asset. Option values have already been determined in the strategy setup
			if (key_rate_name == "Parallel")
				rho_convex_indv_asset = (ird_element->opt_val_int_up_1_bef_sale(t) + ird_element->opt_val_int_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_eio[mp]->pct_to_use;	
			else if (key_rate == 0)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_1_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_1_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 1)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_2_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_2_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 2)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_3_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_3_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 3)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_4_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_4_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 4)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_5_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_5_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 5)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_6_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_6_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 6)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_7_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_7_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 7)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_8_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_8_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 8)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_9_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_9_down_1_bef_sale(t)
										  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
										 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 9)
				rho_convex_indv_asset = (ird_element->opt_val_int_key_rate_10_up_1_bef_sale(t) + ird_element->opt_val_int_key_rate_10_down_1_bef_sale(t)
									  - 2.0 * ird_element->opt_val_baseline_bef_sale(t))
									 * asset->sm_ird[mp]->pct_to_use;	

			double sold_pct = 0.0;

			// rho convexity liab is negative and rho_convex_diff is negative, sell long positions
			if (greek_needed < 0.0 && rho_convex_diff < 0.0 && rho_convex_indv_asset > 0.0)
				{
				if (rho_convex_asset_remaining - rho_convex_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_convex_asset_remaining - greek_needed) / rho_convex_indv_asset;
				}
			// rho convexity liab is negative and rho_convex_diff is positive, sell short positions
			else if (greek_needed < 0.0 && rho_convex_diff > 0.0 && rho_convex_indv_asset < 0.0)
				{
				if (rho_convex_asset_remaining - rho_convex_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_convex_asset_remaining - greek_needed) / rho_convex_indv_asset;
				}
			// rho convexity liab is positive and rho_convex_diff is positive, sell short positions
			else if (greek_needed > 0.0 && rho_convex_diff > 0.0 && rho_convex_indv_asset < 0.0)
				{
				if (rho_convex_asset_remaining - rho_convex_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_convex_asset_remaining - greek_needed) / rho_convex_indv_asset;
				}
			// rho convexity liab is positive and rho_convex_diff is negative, sell long positions
			else if (greek_needed > 0.0 && rho_convex_diff < 0.0 && rho_convex_indv_asset > 0.0)
				{
				if (rho_convex_asset_remaining - rho_convex_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_convex_asset_remaining - greek_needed) / rho_convex_indv_asset;
				}

			rho_convex_sold = rho_convex_indv_asset * sold_pct;
			ird_element->Column(col_num_sold_pct_fund_match).SetValue(t, sold_pct); 

			rho_convex_sold_total += rho_convex_sold;
			rho_convex_asset_remaining -= rho_convex_sold;

			sales_amt += ird_element->mkt_val_sold(t)
						 * ird_element->pct_to_use;

			if (hedge_strat_detail_flag)
				{
				seg->SALFile << ird_element->asset_id << ","
				             << ird_element->hdg_grp_code << ","
							 << rho_convex_indv_asset << ","
							 << sold_pct << ","
							 << ird_element->notional_amt_sold(t) * ird_element->pct_to_use << ","
							 << ird_element->mkt_val_sold(t) * ird_element->pct_to_use << ","
							 << rho_convex_sold << endl;
				}
			}			         
		}
	#endif

	// Erase existing map item and set new item
	asset_greeks_needed.erase(greek_needed_map_index);
	rho_convex_diff = - (rho_convex_asset - rho_convex_sold_total - greek_needed);
	asset_greeks_needed[greek_needed_map_index] = rho_convex_diff;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << "Sales Summary" << endl;
		seg->SALFile << "RhoConvexNeeded," << greek_needed << endl
					 << "RhoConvexAsset," << rho_convex_asset << endl
		             << "RhoConvexSold," << rho_convex_sold_total << endl
					 << "RhoConvexRemaining," << rho_convex_diff << endl;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Rho Convexity Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return sales_amt;


}


//@@ END

//@@ START - rho_convex_hedge_transaction_cost
// Rho Convexity Hedge Transaction Cost                                                                                             
// Column:RHO_CONVEX_HEDGE_TRANSACTION_COST
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_transaction_cost.HDG_GRP_COMP.for"
if (!rho_convex_hedge_flag(t))
	return 0.0;

// Force call rho_hedge_inv_amt
rho_convex_hedge_inv_amt(t);

double transaction_cost = 0.0;
double notional_amt_purch = 0.0;
double notional_amt_sold = 0.0;
int mp = 0;
mpmap::iterator mp_map_iter;

#if defined(__IRD_ASSET_H_)
IRD_ASSET *ird_element = NULL;

if (ird_mp_map_active.size() > 0)
	{
	for (mp_map_iter = ird_mp_map_active.begin();
		 mp_map_iter != ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		ird_element = company->sm_asset->sm_ird[mp];

		if (t < ird_element->commencement_period
			|| (t > max(0, ird_element->commencement_period)
				&& fabs(ird_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
			|| ird_element->hdg_grp_code.find("RhoConvexity|") == string::npos)
			continue;

		notional_amt_sold = ird_element->notional_amt_sold(t) * ird_element->pct_to_use;
		notional_amt_purch = ird_element->notional_amt_purch(t) * ird_element->pct_to_use;		

		transaction_cost += (fabs(notional_amt_sold) + fabs(notional_amt_purch)) 
		                   * hedge_grp_rho_hedge_transaction_costs_bps / 10000.0;
		}			         
	}
#endif

return transaction_cost;

}


//@@ END

//@@ START - rho_convex_key_rate_1
// Rho Convexity Key Rate 1                                                                                             
// Column:RHO_CONVEX_KEY_RATE_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_1(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 1)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_10
// Rho Convexity Key Rate 10                                                                                             
// Column:RHO_CONVEX_KEY_RATE_10
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_10(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_10.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 10)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[9] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_2
// Rho Convexity Key Rate 2                                                                                             
// Column:RHO_CONVEX_KEY_RATE_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_2(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 2)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_3
// Rho Convexity Key Rate 3                                                                                             
// Column:RHO_CONVEX_KEY_RATE_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_3(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 3)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_4
// Rho Convexity Key Rate 4                                                                                             
// Column:RHO_CONVEX_KEY_RATE_4
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_4(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_4.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 4)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[3] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_5
// Rho Convexity Key Rate 1                                                                                             
// Column:RHO_CONVEX_KEY_RATE_5
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_5(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_5.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 5)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[4] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_6
// Rho Convexity Key Rate 6                                                                                             
// Column:RHO_CONVEX_KEY_RATE_6
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_6(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_6.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 6)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[5] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_7
// Rho Convexity Key Rate 7                                                                                             
// Column:RHO_CONVEX_KEY_RATE_7
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_7(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_7.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 7)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[6] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_8
// Rho Convexity Key Rate 8                                                                                             
// Column:RHO_CONVEX_KEY_RATE_8
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_8(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_8.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 8)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[7] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_key_rate_9
// Rho Convexity Key Rate 9                                                                                             
// Column:RHO_CONVEX_KEY_RATE_9
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_9(int t) {
//^^^



//^^^

#line 1 "rho_convex_key_rate_9.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 9)
	return NO_AVG;

greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[8] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_convex_parallel
// Rho Convexity Parallel                                                                                             
// Column:RHO_CONVEX_PARALLEL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_parallel(int t) {
//^^^



//^^^

#line 1 "rho_convex_parallel.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

greek_index = "RhoConvexity_Parallel_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_hedge_flag
// Rho Hedge Flag                                                                                             
// Column:RHO_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_flag(int t) {
//^^^



//^^^

#line 1 "rho_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_rho_hedge_defn == NO)
	return 0;

if (t > 0 && (t % hedge_grp_rho_hedge_rebal_freq) != 0)
	return 0;

// Check for existing rho hedge assets. If they exist, rho hedge strategy is not executed at t == 0
if (t == 0)
	{
	#if defined(__IRD_ASSET_H_)
	int mp = 0;
	mpmap::iterator mp_map_iter;
	IRD_ASSET *ird_element = NULL;

	if (ird_mp_map_active.size() > 0)
		{
		for (mp_map_iter = ird_mp_map_active.begin();
			 mp_map_iter != ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if (ird_element->hdg_grp_code.find("Rho|") < string::npos)
				return 0;
			}			         
		}
	#endif
	}

return 1;

}


//@@ END

//@@ START - rho_hedge_inv_amt
// Rho Hedge Investment Amount                                                                                             
// Column:RHO_HEDGE_INV_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_inv_amt.HDG_GRP_COMP.for"
if (!rho_hedge_flag(t))
	return 0.0;
	
// Must first call rho hedge sales
rho_hedge_sale_amt(t);

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Rho Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Determine the asset rho for each key rate
calc_asset_greeks(t, RHO, PURCH);

double inv_amt = 0.0;
map <xstring, double> rho_hedge_coeff;
map <xstring, double> notional_to_purch;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int key_rate_loops = 1;

if (hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC)
	key_rate_loops = company->rho_hedge_key_rate_list.size();

for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
	{
	// set lookup key
	if (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
		hedge_grp_key_rate = "Parallel";
	else
		hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

	xstring greek_map_index = "Rho_Purchase_" + hedge_grp_key_rate + "_" + xstring(t);
	double rho_asset_purch = asset_greeks[greek_map_index];

	// Asset greek needed has been updates for sales
	xstring greek_needed_map_index = "Rho_" + hedge_grp_key_rate + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	if (fabs(rho_asset_purch) > model_point_amount_threshold)
		rho_hedge_coeff[greek_needed_map_index] = greek_needed / rho_asset_purch; 

	xstring hedge_grp_code = hedge_grp_id + "|Rho|" + hedge_grp_key_rate;

	notional_to_purch[greek_needed_map_index] = ONE_MILLION * rho_hedge_coeff[greek_needed_map_index];
	double notional_inv = notional_to_purch[greek_needed_map_index];

	if (fabs(notional_inv) > model_point_amount_threshold)
		{
		inv_amt += company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		YES, //save_assets
																		HEDGING,
																		new_mp_num,
																		hedge_grp_code,
																		hedge_grp_rho_hedge_asset_id,
																		notional_inv,
																		-1.0,
																		-1.0);

		// Add new element to the hedge group ird map
		if (new_mp_num < 0)
			throw FatalError("Unable to invest in new rho hedge asset for hedge group " + hedge_grp_id + ". "
								+ "Please review your rho hedge strategy data.");

		ird_mp_map_active[new_mp_num] = new_mp_num;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Rho Hedge Investments Summary" << endl;
	seg->SALFile << "KeyRateTermName,RhoNeeded,AssetRho,HedgeCoeff,NotionalPurch" << endl;

	for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
		{
		// set lookup key
		if (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
			hedge_grp_key_rate = "Parallel";
		else
			hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

		// Asset greek needed has been updates for sales
		xstring greek_needed_map_index = "Rho_" + hedge_grp_key_rate + "_" + xstring(t);
		xstring greek_map_index = "Rho_Purchase_" + hedge_grp_key_rate + "_" + xstring(t);
		seg->SALFile << hedge_grp_key_rate << ","
		             << asset_greeks_needed[greek_needed_map_index] << ","
					 << asset_greeks[greek_map_index] << ","
		             << rho_hedge_coeff[greek_needed_map_index] << ","
		             << notional_to_purch[greek_needed_map_index] << endl;
		}
	}

rho_hedge_coeff.clear();
notional_to_purch.clear();

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Rho Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return inv_amt;

}


//@@ END

//@@ START - rho_hedge_mkt_val
// Rho Hedge Market Value of Assets                                                                                             
// Column:RHO_HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "rho_hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, RHO, END_OF_PERIOD);

}


//@@ END

//@@ START - rho_hedge_mkt_val_incr
// Rho Hedge Market Value of Assets Increase                                                                                             
// Column:RHO_HEDGE_MKT_VAL_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "rho_hedge_mkt_val_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return rho_hedge_mkt_val(t) - rho_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - rho_hedge_pmt
// Rho Hedge Derivative Payment                                                                                             
// Column:RHO_HEDGE_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("int_pmt", t, RHO, BEFORE_SALE);

}


//@@ END

//@@ START - rho_hedge_prof
// Rho Hedge Profit                                                                                             
// Column:RHO_HEDGE_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_prof(int t) {
//^^^



//^^^

#line 1 "rho_hedge_prof.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_rho_hedge_defn == NO)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

return rho_hedge_pmt(t)
	   + rho_hedge_sale_amt(t)
	   - rho_hedge_inv_amt(t)
	   - rho_hedge_transaction_cost(t)
	   + rho_hedge_mkt_val_incr(t);

}


//@@ END

//@@ START - rho_hedge_sale_amt
// Rho Hedge Sale Amount                                                                                             
// Column:RHO_HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_sale_amt.HDG_GRP_COMP.for"
if (!rho_hedge_flag(t))
	return 0.0;

// Must first call rho hedge strategy to setup strategy
rho_hedge_strat(t);

#if defined(__IRD_ASSET_H_)
// Do not process sales if there are no assets in the active map
if (!ird_mp_map_active.size())
	return 0.0;

// Do not process sales if there are no Rho assets in the active map
int mp = 0;
bool rho_hedges = false;
mpmap::iterator mp_map_iter;
IRD_ASSET *ird_element = NULL;
for (mp_map_iter = ird_mp_map_active.begin();
	mp_map_iter != ird_mp_map_active.end();
	mp_map_iter++)
	{
	mp = mp_map_iter->first;
	ird_element = company->sm_asset->sm_ird[mp];

	if (ird_element->hdg_grp_code.find("Rho|") < string::npos)
		{
		rho_hedges = true;
		break;
		}
	}

if (!rho_hedges)
	return 0.0;
#endif

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Rho Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

double sales_amt = 0.0;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int key_rate_loops = 1;
if (hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC) // Just one loop for parallel hedging
	key_rate_loops = company->rho_hedge_key_rate_list.size();

for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
	{
	int mp = 0;
	mpmap::iterator mp_map_iter;
	xstring key_rate_name;
	if (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
		key_rate_name = "Parallel";
	else
		key_rate_name = company->rho_hedge_key_rate_list[key_rate];

	// Asset greek needed from original strategy setup
	xstring greek_needed_map_index = "Rho_" + key_rate_name + "_" + xstring(t);
	double greek_needed = asset_greeks_needed[greek_needed_map_index];

	xstring asset_greek_map_index = "Rho_BefSale_" + key_rate_name + "_" + xstring(t);
	double rho_asset = asset_greeks[asset_greek_map_index];
	double rho_diff = - (rho_asset - greek_needed);
	double rho_asset_remaining = rho_asset;
	double rho_indv_asset = 0.0;
	double rho_sold = 0.0;
	double rho_sold_total = 0.0;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << "Processing Hedge Sales for Key Rate Term " << key_rate_name << endl;
		seg->SALFile << "RhoNeeded," << greek_needed << endl
					 << "RhoAsset," << rho_asset << endl
					 << "RhoDiff," << rho_diff << endl;

		seg->SALFile << endl;
		seg->SALFile << "AssetID,HedgeGrpCode,RhoAsset,SoldPct,NotionalSold,MktValSold,RhoSold" << endl;
		}

	#if defined(__IRD_ASSET_H_)
	IRD_ASSET *ird_element = NULL;

	if (ird_mp_map_active.size() > 0)
		{
		int col_num_sold_pct_fund_match
		= asset->sm_ird[0]->Column("sold_pct_fund_match").Number();

		for (mp_map_iter = ird_mp_map_active.begin();
			 mp_map_iter != ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if (ird_element->hdg_grp_code.find("Rho|") == string::npos)
				continue;

			if (ird_element->hdg_grp_code.find(key_rate_name) == string::npos)
				continue;

			if (t < ird_element->commencement_period
				|| (t > max(0, ird_element->commencement_period)
					&& (fabs(ird_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
						|| ird_element->Column(col_num_sold_pct_fund_match).Exists(t)))
				continue;

			// calculate Rho for asset. Option values have already been determined in the strategy setup
			if (key_rate_name == "Parallel")
				rho_indv_asset = (ird_element->opt_val_int_up_1_bef_sale(t) - ird_element->opt_val_int_down_1_bef_sale(t))
								 * asset->sm_eio[mp]->pct_to_use;	
			else if (key_rate == 0)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_1_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_1_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 1)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_2_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_2_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 2)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_3_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_3_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 3)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_4_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_4_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 4)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_5_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_5_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 5)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_6_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_6_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 6)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_7_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_7_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 7)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_8_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_8_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 8)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_9_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_9_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	
			else if (key_rate == 9)
				rho_indv_asset = (ird_element->opt_val_int_key_rate_10_up_1_bef_sale(t) - ird_element->opt_val_int_key_rate_10_down_1_bef_sale(t))
								 * asset->sm_ird[mp]->pct_to_use;	

			double sold_pct = 0.0;

			// rho liab is negative and rho_diff is negative, sell long positions
			if (greek_needed < 0.0 && rho_diff < 0.0 && rho_indv_asset > 0.0)
				{
				if (rho_asset_remaining - rho_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_asset_remaining - greek_needed) / rho_indv_asset;
				}
			// rho liab is negative and rho_diff is positive, sell short positions
			else if (greek_needed < 0.0 && rho_diff > 0.0 && rho_indv_asset < 0.0)
				{
				if (rho_asset_remaining - rho_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_asset_remaining - greek_needed) / rho_indv_asset;
				}
			// rho liab is positive and rho_diff is positive, sell short positions
			else if (greek_needed > 0.0 && rho_diff > 0.0 && rho_indv_asset < 0.0)
				{
				if (rho_asset_remaining - rho_indv_asset < greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_asset_remaining - greek_needed) / rho_indv_asset;
				}
			// rho liab is positive and rho_diff is negative, sell long positions
			else if (greek_needed > 0.0 && rho_diff < 0.0 && rho_indv_asset > 0.0)
				{
				if (rho_asset_remaining - rho_indv_asset > greek_needed)
					sold_pct = 1.0;
				else
					sold_pct = (rho_asset_remaining - greek_needed) / rho_indv_asset;
				}

			rho_sold = rho_indv_asset * sold_pct;
			ird_element->Column(col_num_sold_pct_fund_match).SetValue(t, sold_pct); 

			rho_sold_total += rho_sold;
			rho_asset_remaining -= rho_sold;

			sales_amt += ird_element->mkt_val_sold(t)
						 * ird_element->pct_to_use;

			if (hedge_strat_detail_flag)
				{
				seg->SALFile << ird_element->asset_id << ","
				             << ird_element->hdg_grp_code << ","
							 << rho_indv_asset << ","
							 << sold_pct << ","
							 << ird_element->notional_amt_sold(t) * ird_element->pct_to_use << ","
							 << ird_element->mkt_val_sold(t) * ird_element->pct_to_use << ","
							 << rho_sold << endl;
				}
			}			         
		}
	#endif

	// Erase existing map item and set new item
	asset_greeks_needed.erase(greek_needed_map_index);
	rho_diff = - (rho_asset - rho_sold_total - greek_needed);
	asset_greeks_needed[greek_needed_map_index] = rho_diff;

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << "Sales Summary" << endl;
		seg->SALFile << "RhoNeeded," << greek_needed << endl
					 << "RhoAsset," << rho_asset << endl
		             << "RhoSold," << rho_sold_total << endl
					 << "RhoRemaining," << rho_diff << endl;
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Rho Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return sales_amt;


}


//@@ END

//@@ START - rho_hedge_transaction_cost
// Rho Hedge Transaction Cost                                                                                             
// Column:RHO_HEDGE_TRANSACTION_COST
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "rho_hedge_transaction_cost.HDG_GRP_COMP.for"
if (!rho_hedge_flag(t))
	return 0.0;

// Force call rho_hedge_inv_amt
rho_hedge_inv_amt(t);

double transaction_cost = 0.0;
double notional_amt_purch = 0.0;
double notional_amt_sold = 0.0;
int mp = 0;
mpmap::iterator mp_map_iter;

#if defined(__IRD_ASSET_H_)
IRD_ASSET *ird_element = NULL;

if (ird_mp_map_active.size() > 0)
	{
	for (mp_map_iter = ird_mp_map_active.begin();
		 mp_map_iter != ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		ird_element = company->sm_asset->sm_ird[mp];

		if (t < ird_element->commencement_period
			|| (t > max(0, ird_element->commencement_period)
				&& fabs(ird_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
			|| ird_element->hdg_grp_code.find("Rho|") == string::npos)
			continue;

		notional_amt_sold = ird_element->notional_amt_sold(t) * ird_element->pct_to_use;
		notional_amt_purch = ird_element->notional_amt_purch(t) * ird_element->pct_to_use;		

		transaction_cost += (fabs(notional_amt_sold) + fabs(notional_amt_purch)) 
		                   * hedge_grp_rho_hedge_transaction_costs_bps / 10000.0;
		}			         
	}
#endif

return transaction_cost;

}


//@@ END

//@@ START - rho_key_rate_1
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_1(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 1)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_10
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_10
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_10(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_10.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 10)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[9] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_2
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_2(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 2)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_3
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_3(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 3)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_4
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_4
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_4(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_4.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 4)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[3] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_5
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_5
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_5(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_5.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 5)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[4] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_6
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_6
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_6(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_6.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 6)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[5] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_7
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_7
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_7(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_7.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 7)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[6] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_8
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_8
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_8(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_8.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 8)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[7] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_key_rate_9
// Rho Key Rate 1                                                                                             
// Column:RHO_KEY_RATE_9
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_9(int t) {
//^^^



//^^^

#line 1 "rho_key_rate_9.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->rho_hedge_key_rate_list.size() < 9)
	return NO_AVG;

greek_index = "Rho_" + company->rho_hedge_key_rate_list[8] + "_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - rho_parallel
// Rho Parallel                                                                                             
// Column:RHO_PARALLEL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_rho_parallel(int t) {
//^^^



//^^^

#line 1 "rho_parallel.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

greek_index = "Rho_Parallel_" + xstring(t);

return liab_greeks[greek_index];


}


//@@ END

//@@ START - short_strike
// Short Strike                                                                                             
// Column:SHORT_STRIKE
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_short_strike(int t) {
//^^^



//^^^

#line 1 "short_strike.HDG_GRP_COMP.for"
if (t <= start_period)
	return NO_AVG;

return index_val(t) * (1.0 + cap_rate(t));

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double HDG_GRP_COMP_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.HDG_GRP_COMP.for"
#if 0 // START_EXTERNS
deptaskinput valn_hedge_input;
deptaskcols valn_hedge_input_cols;
deptaskmap valn_hedge_input_pos;
deptaskmapiter valn_hedge_input_pos_iter;

deptaskinput valn_hedge_final_input;
deptaskcols valn_hedge_final_input_cols;
deptaskmap valn_hedge_final_input_pos;
deptaskmapiter valn_hedge_final_input_pos_iter;

// define sum over command, END_OF_PERIOD is defined globally
const int BEG_OF_PERIOD = 0;
int AVG_PV_CLAIMS = 1;
int AVG_PV_CHARGES = 2;
int VALN_RESULTS_SIZE = 3;
#endif // END_EXTERNS

#if 0 // START_CLASS
typedef map <int, long, less <int> > mpmap;
mpmap fia_mp_map;
mpmap iul_mp_map;
mpmap va_mp_map;
mpmap eio_mp_map_active;
mpmap ird_mp_map_active;
map <xstring, double> liab_greeks;
map <xstring, double> asset_greeks;
map <xstring, double> asset_greeks_needed;

int hedge_group_count;
SmartArray < SmartArray <double> >  hedge_valn_array;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
hedge_group_count = 0;
#endif // END_CONSTRUCTOR

// clear the hedging maps
liab_greeks.clear();
asset_greeks.clear();
asset_greeks_needed.clear();

return 1.0;

}


//@@ END

//@@ START - valn_tgt_hedge_final
// Valuation Target Hedge Final                                                                                             
// Column:VALN_TGT_HEDGE_FINAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_valn_tgt_hedge_final(int t) {
//^^^



//^^^

#line 1 "valn_tgt_hedge_final.HDG_GRP_COMP.for"
if (!hedge_valn_final_flag)
	return NO_AVG;

this->pv_charges(0);
this->pv_claims(0);
this->econ_res(0);

return 1.0;


}


//@@ END

//@@ START - valn_tgt_hedge_shock
// Valuation Target Hedge Shock                                                                                             
// Column:VALN_TGT_HEDGE_SHOCK
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_valn_tgt_hedge_shock(int t) {
//^^^



//^^^

#line 1 "valn_tgt_hedge_shock.HDG_GRP_COMP.for"
if (!hedge_valn_flag)
	return NO_AVG;

#if defined(__VA_LIAB_H_)
int mp = 0;
mpmap::iterator mp_map_iter;
VA_LIAB *current_va_element;
VA_AFUND_LIAB * current_va_account;

// Determine the Shock ID
vector<string> shock_string_parts;
xstring shock_string = company->hedge_valn_shock_list[proj_task_loop_num - 1];
split_string_usl(shock_string.c_str(), shock_string_parts, "|");//WTW - Gen2 - split_tring internal RAFM function
shock_id = shock_string_parts[0];
int current_plan_code_integer = 0;

if (hedge_grp_count_id == 0 && independent_mp_defn == NO)
	{
	if (time_step_flag && valn_period != 0 && (valn_period % shock_freq != 0))//Shock is not required in this valuation period
		{
		this->pv_charges(0);
		this->pv_claims(0);
		return 1.0;
		}
	
	// Clear va_hedge_vals for each Hedge Grp
	seg->va_hedge_vals.clear();	
	
	//perform PV calculations for all model points in first hedge group. Store hedge values by product code and rider type
	//to allow for hedge group summation based on hedge workbook settings

	// Loops over each MP within a given Segment & Hedge
	for (mp_map_iter = seg->va_mp_map.begin();
		 mp_map_iter != seg->va_mp_map.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		current_va_element = liab->sm_va[mp];	
		
		if (valn_scens_defn == MODEL_POINT_SPECIFIC)
			{
			// Determine the Scenario we want to run
			xstring hedge_valn_shock_full_id = company->hedge_valn_shock_list[proj_task_loop_num - 1];
			// The task loop starts at the position after the last dash "-" of the hedge_valn_shock_id
			int task_loop_start_pos = hedge_valn_shock_full_id.find_last_of("-");
			int hedge_task_loop_num = atoi(hedge_valn_shock_full_id(task_loop_start_pos + 1));
	
			// Adjusted by the starting point for each MP
			double scen_mod_1 = mod(current_va_element->hedge_valn_scen_start_num, rates->gen_scenarios);
			double scen_mod_2 = 0.0;
			if (mod(scen_mod_1 + hedge_task_loop_num - 1, rates->gen_scenarios) == 0)
				scen_mod_2 = rates->gen_scenarios;
			else 
				scen_mod_2 = mod(scen_mod_1 + hedge_task_loop_num - 1, rates->gen_scenarios);		
	
			rates->scen_rates_load(scen_mod_2);
		}

		double disc_claim_amt_ab_mp = 0.0;
		double disc_claim_amt_db_mp = 0.0;
		double disc_claim_amt_ib_mp = 0.0;
		double disc_claim_amt_wb_mp = 0.0;

		double disc_claim_fee_ab_mp = 0.0;
		double disc_claim_fee_db_mp = 0.0;
		double disc_claim_fee_ib_mp = 0.0;
		double disc_claim_fee_wb_mp = 0.0;
	
		// Set up Equity Price Shock for each MP
		int num_of_funds = current_va_element->sm_va_account.size();
		for (int fund = 0; fund < num_of_funds; fund++)
			{
			if (current_va_element->sm_va_account[fund]->fund_type != SEPARATE || eqt_price_shock_defn == NO)
				current_va_element->sm_va_account[fund]->shock_size = 0.0;
			else
				{
				hedge_grp_index_name = current_va_element->sm_va_account[fund]->index_name;
		
				double asset_shock = eqt_price_shock;
				current_va_element->sm_va_account[fund]->shock_size = asset_shock;
				}
			}	

		// Set up Policyholder Shock for each MP - Lapse
		if (phldr_shock_defn == NO)
			current_va_element->lapse_shock_size = 0.0;	
		else
			{
			decrem_id = "Lapse";
			double lapse_shock = phldr_shock;
			current_va_element->lapse_shock_size = lapse_shock;
			}
			
		calc_pv_claims_charges(mp, disc_claim_amt_ab_mp, disc_claim_amt_db_mp, 
								   disc_claim_amt_ib_mp, disc_claim_amt_wb_mp,
							       disc_claim_fee_ab_mp, disc_claim_fee_db_mp,
								   disc_claim_fee_ib_mp, disc_claim_fee_wb_mp);
		
		xstring index;
		
		//Store GMAB Claims and Charges by Product
		index = current_va_element->plan_code + "_" + "GMAB" + "_" + "Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_ab_mp;

		index = current_va_element->plan_code + "_" + "GMAB" + "_" + "Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_ab_mp;

		//Store GMAB Claims and Charges in Aggregate
		index = "ALL_GMAB_Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_ab_mp;

		index = "ALL_GMAB_Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_ab_mp;

		//Store GMDB Claims and Charges by Product
		index = current_va_element->plan_code + "_" + "GMDB" + "_" + "Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_db_mp;

		index = current_va_element->plan_code + "_" + "GMDB" + "_" + "Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_db_mp;

		//Store GMDB Claims and Charges in Aggregate
		index = "ALL_GMDB_Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_db_mp;

		index = "ALL_GMDB_Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_db_mp;

		//Store GMIB Claims and Charges by Product
		index = current_va_element->plan_code + "_" + "GMIB" + "_" + "Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_ib_mp;

		index = current_va_element->plan_code + "_" + "GMIB" + "_" + "Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_ib_mp;

		//Store GMIB Claims and Charges in Aggregate
		index = "ALL_GMIB_Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_ib_mp;

		index = "ALL_GMIB_Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_ib_mp;

		//Store GMWB Claims and Charges by Product
		index = current_va_element->plan_code + "_" + "GMWB" + "_" + "Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_wb_mp;

		index = current_va_element->plan_code + "_" + "GMWB" + "_" + "Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_wb_mp;

		//Store GMWB Claims and Charges in Aggregate
		index = "ALL_GMWB_Claims";
		seg->va_hedge_vals[index] += disc_claim_amt_wb_mp;

		index = "ALL_GMWB_Fees";
		seg->va_hedge_vals[index] += disc_claim_fee_wb_mp;
		}
	}


this->pv_charges(0);
this->pv_claims(0);
#endif

return 1.0;

}


//@@ END

//@@ START - vega_hedge_flag
// Vega Hedge Flag                                                                                             
// Column:VEGA_HEDGE_FLAG
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_flag(int t) {
//^^^



//^^^

#line 1 "vega_hedge_flag.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || !gamma_vega_hedge_flag(t))
	return 0;

if (hedge_grp_gamma_vega_hedge_type_defn == GAMMA)
	return 0;

// Check for existing vega hedge assets. If they exist, vega hedge strategy is not executed at t == 0
if (t == 0)
	{
	#if defined(__EIO_ASSET_H_)
	int mp = 0;
	mpmap::iterator mp_map_iter;
	EIO_ASSET *eio_element = NULL;

	if (eio_mp_map_active.size() > 0)
		{
		for (mp_map_iter = eio_mp_map_active.begin();
			 mp_map_iter != eio_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (eio_element->hdg_grp_code.find("Vega") < string::npos)
				return 0;
			}			         
		}
	#endif
	}

return 1.0;

}


//@@ END

//@@ START - vega_hedge_inv_amt
// Vega Hedge Investment Amount                                                                                             
// Column:VEGA_HEDGE_INV_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_inv_amt.HDG_GRP_COMP.for"
if (!vega_hedge_flag(t))
	return 0.0;
	
// Must first call vega hedge sales
vega_hedge_sale_amt(t);

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Vega Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Determine the asset vega for each index
calc_asset_greeks(t, VEGA, PURCH);

double inv_amt = 0.0;
map <xstring, double> vega_hedge_coeff;
map <xstring, double> notional_to_purch;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
int index_term_loops = 1;

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
	|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
	index_loops = company->vega_hedge_index_list.size();

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
	index_term_loops = company->vega_hedge_term_list.size();	

for (int index = 0; index < index_loops; index++)
	{
	// set lookup key
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
		hedge_grp_index_name = "Parallel";
	else
		hedge_grp_index_name = company->vega_hedge_index_list[index];

	for (int index_term = 0; index_term < index_term_loops; index_term++)
		{
		// set lookup key
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL
			|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
			hedge_grp_index_term = "AllTerms";
		else
			hedge_grp_index_term = company->vega_hedge_term_list[index_term];

		xstring greek_map_index = "Vega_Purchase_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
		double vega_asset_purch = asset_greeks[greek_map_index];

		// Asset greek needed has been updates for sales
		xstring greek_needed_map_index = "Vega_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
		double greek_needed = asset_greeks_needed[greek_needed_map_index];

		if (fabs(vega_asset_purch) > model_point_amount_threshold)
			vega_hedge_coeff[greek_needed_map_index] = greek_needed / vega_asset_purch; 

		xstring hedge_grp_code = hedge_grp_id + "|Vega|" + hedge_grp_index_name + "|" + hedge_grp_index_term;

		notional_to_purch[greek_needed_map_index] = ONE_MILLION * vega_hedge_coeff[greek_needed_map_index];
		double notional_inv = notional_to_purch[greek_needed_map_index]; 

		if (fabs(notional_inv) > model_point_amount_threshold)
			{
			inv_amt += company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																			YES, //save_assets
																			HEDGING,
																			new_mp_num,
																			hedge_grp_code,
																			hedge_grp_gamma_vega_hedge_asset_id,
																			notional_inv,
																			-1.0,
																			-1.0);

			// Add new element to the hedge group eio map
			if (new_mp_num < 0)
				throw FatalError("Unable to invest in new vega hedge asset for hedge group " + hedge_grp_id + ". "
								 + "Please review your vega hedge strategy data.");

			eio_mp_map_active[new_mp_num] = new_mp_num;
			}
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Vega Hedge Investments Summary" << endl;
	seg->SALFile << "IndexName,IndexTermName,VegaNeeded,AssetVega,HedgeCoeff,NotionalPurch" << endl;

	for (int index = 0; index < index_loops; index++)
		{
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
			hedge_grp_index_name = "Parallel";
		else
			hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];

		for (int index_term = 0; index_term < index_term_loops; index_term++)
			{
			// set lookup key
			if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL
				|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
				hedge_grp_index_term = "AllTerms";
			else
				hedge_grp_index_term = company->vega_hedge_term_list[index_term];

			// Asset greek needed has been updates for sales
			xstring greek_needed_map_index = "Vega_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
			xstring greek_map_index = "Vega_Purchase_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
			seg->SALFile << hedge_grp_index_name << ","
						 << hedge_grp_index_term << ","
						 << asset_greeks_needed[greek_needed_map_index] << ","
						 << asset_greeks[greek_map_index] << ","
						 << vega_hedge_coeff[greek_needed_map_index] << ","
						 << notional_to_purch[greek_needed_map_index] << endl;
			}
		}
	}

vega_hedge_coeff.clear();
notional_to_purch.clear();

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Vega Hedge Investments for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}


return inv_amt;

}


//@@ END

//@@ START - vega_hedge_mkt_val
// Vega Hedge Market Value of Assets                                                                                             
// Column:VEGA_HEDGE_MKT_VAL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "vega_hedge_mkt_val.HDG_GRP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls
fund_val_fixed(t);

return sum_over_assets("mkt_val", t, VEGA, END_OF_PERIOD);

}


//@@ END

//@@ START - vega_hedge_mkt_val_incr
// Vega Hedge Market Value of Assets Increase                                                                                             
// Column:VEGA_HEDGE_MKT_VAL_INCR
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "vega_hedge_mkt_val_incr.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return vega_hedge_mkt_val(t) - vega_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - vega_hedge_pmt
// Vega Hedge Derivative Payment                                                                                             
// Column:VEGA_HEDGE_PMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_pmt.HDG_GRP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_assets("opt_pmt", t, VEGA, BEFORE_SALE);

}


//@@ END

//@@ START - vega_hedge_prof
// Vega Hedge Profit                                                                                             
// Column:VEGA_HEDGE_PROF
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_prof(int t) {
//^^^



//^^^

#line 1 "vega_hedge_prof.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag || hedge_grp_gamma_vega_hedge_defn == NO || hedge_grp_gamma_vega_hedge_type_defn == GAMMA)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

return vega_hedge_pmt(t)
	   + vega_hedge_sale_amt(t)
	   - vega_hedge_inv_amt(t)
	   - vega_hedge_transaction_cost(t)
	   + vega_hedge_mkt_val_incr(t);

}


//@@ END

//@@ START - vega_hedge_sale_amt
// Vega Hedge Sale Amount                                                                                             
// Column:VEGA_HEDGE_SALE_AMT
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_sale_amt.HDG_GRP_COMP.for"
if (!vega_hedge_flag(t))
	return 0.0;

// Must first call vega hedge strategy to setup strategy
vega_hedge_strat(t);

#if defined(__EIO_ASSET_H_)
// Do not process sales if there are no assets in the active map
if (!eio_mp_map_active.size())
	return 0.0;

// Do not process sales if there are no Vega assets in the active map
int mp = 0;
bool vega_hedges = false;
mpmap::iterator mp_map_iter;
EIO_ASSET *eio_element = NULL;
for (mp_map_iter = eio_mp_map_active.begin();
	mp_map_iter != eio_mp_map_active.end();
	mp_map_iter++)
	{
	mp = mp_map_iter->first;
	eio_element = company->sm_asset->sm_eio[mp];

	if (eio_element->hdg_grp_code.find("Vega") < string::npos)
		{
		vega_hedges = true;
		break;
		}
	}

if (!vega_hedges)
	return 0.0;
#endif

bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Start Vega Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

double sales_amt = 0.0;
int new_mp_num = -1;
int seg_num = seg->getElementNumber();
int index_loops = 1;
int index_term_loops = 1;
if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
	|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC) // Just one loop for parallel hedging
	index_loops = company->vega_hedge_index_list.size();

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
	index_term_loops = company->vega_hedge_term_list.size();

for (int index = 0; index < index_loops; index++)
	{
	int mp = 0;
	mpmap::iterator mp_map_iter;
	xstring index_name;
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
		index_name = "Parallel";
	else
		index_name = company->vega_hedge_index_list[index];

	for (int index_term = 0; index_term < index_term_loops; index_term++)
		{
		xstring index_term_name;
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL
			|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
			index_term_name = "AllTerms";
		else
			{
			if (index_term_name == "AllTerms")
				continue;

			index_term_name = company->vega_hedge_term_list[index_term];
			}							

		// Asset greek needed from original strategy setup
		xstring greek_needed_map_index = "Vega_" + index_name + "_" + index_term_name + "_" + xstring(t);
		double greek_needed = asset_greeks_needed[greek_needed_map_index];

		xstring asset_greek_map_index = "Vega_BefSale_" + index_name + "_" + index_term_name + "_" + xstring(t);
		double vega_asset = asset_greeks[asset_greek_map_index];
		double vega_diff = - (vega_asset - greek_needed);
		double vega_asset_remaining = vega_asset;
		double vega_indv_asset = 0.0;
		double vega_sold = 0.0;
		double vega_sold_total = 0.0;

		if (hedge_strat_detail_flag)
			{
			seg->SALFile << endl;
			seg->SALFile << "Processing Hedge Sales for Index " << index_name << " Index Term " << index_term_name << endl;
			seg->SALFile << "VegaNeeded," << greek_needed << endl
						 << "VegaAsset," << vega_asset << endl
						 << "VegaDiff," << vega_diff << endl;

			seg->SALFile << endl;
			seg->SALFile << "AssetID,HedgeGrpCode,VegaAsset,SoldPct,NotionalSold,MktValSold,VegaSold" << endl;
			}

		#if defined(__EIO_ASSET_H_)
		EIO_ASSET *eio_element = NULL;

		if (eio_mp_map_active.size() > 0)
			{
			int col_num_sold_pct
			= asset->sm_eio[0]->Column("sold_pct").Number();

			for (mp_map_iter = eio_mp_map_active.begin();
					mp_map_iter != eio_mp_map_active.end();
					mp_map_iter++)
				{
				mp = mp_map_iter->first;
				eio_element = company->sm_asset->sm_eio[mp];

				if (eio_element->hdg_grp_code.find("Vega") == string::npos)
					continue;

				if ((hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
					 || hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
					&& eio_element->hdg_grp_code.find(index_name) == string::npos)
					continue;

				if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC
					&& eio_element->hdg_grp_code.find(index_term_name) == string::npos)
					continue;

				if (t < eio_element->commencement_period
					|| (t == eio_element->commencement_period
						&& eio_element->purchased_bom_flag)
					|| (t > max(0, eio_element->commencement_period)
						&& (fabs(eio_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
							|| eio_element->Column(col_num_sold_pct).Exists(t)))
					continue;

				// calculate Vega for asset. Option values have already been determined in the strategy setup
				if (index_term_name == "AllTerms")
					vega_indv_asset = (eio_element->opt_val_vol_up_1_bef_sale(t) - eio_element->opt_val_vol_down_1_bef_sale(t))
									  * asset->sm_eio[mp]->pct_to_use;	
				else if (index_term == 0)
					vega_indv_asset = (eio_element->opt_val_vol_term_1_up_1_bef_sale(t) - eio_element->opt_val_vol_term_1_down_1_bef_sale(t))
									  * asset->sm_eio[mp]->pct_to_use;	
				else if (index_term == 1)
					vega_indv_asset = (eio_element->opt_val_vol_term_2_up_1_bef_sale(t) - eio_element->opt_val_vol_term_2_down_1_bef_sale(t))
									  * asset->sm_eio[mp]->pct_to_use;	
				else if (index_term == 2)
					vega_indv_asset = (eio_element->opt_val_vol_term_3_up_1_bef_sale(t) - eio_element->opt_val_vol_term_3_down_1_bef_sale(t))
									  * asset->sm_eio[mp]->pct_to_use;	

				double sold_pct = 0.0;

				// vega liab is negative and vega_diff is negative, sell long positions
				if (greek_needed < 0.0 && vega_diff < 0.0 && vega_indv_asset > 0.0)
					{
					if (vega_asset_remaining - vega_indv_asset > greek_needed)
						sold_pct = 1.0;
					else
						sold_pct = (vega_asset_remaining - greek_needed) / vega_indv_asset;
					}
				// vega liab is negative and vega_diff is positive, sell short positions
				else if (greek_needed < 0.0 && vega_diff > 0.0 && vega_indv_asset < 0.0)
					{
					if (vega_asset_remaining - vega_indv_asset < greek_needed)
						sold_pct = 1.0;
					else
						sold_pct = (vega_asset_remaining - greek_needed) / vega_indv_asset;
					}
				// vega liab is positive and vega_diff is positive, sell short positions
				else if (greek_needed > 0.0 && vega_diff > 0.0 && vega_indv_asset < 0.0)
					{
					if (vega_asset_remaining - vega_indv_asset < greek_needed)
						sold_pct = 1.0;
					else
						sold_pct = (vega_asset_remaining - greek_needed) / vega_indv_asset;
					}
				// vega liab is positive and vega_diff is negative, sell long positions
				else if (greek_needed > 0.0 && vega_diff < 0.0 && vega_indv_asset > 0.0)
					{
					if (vega_asset_remaining - vega_indv_asset > greek_needed)
						sold_pct = 1.0;
					else
						sold_pct = (vega_asset_remaining - greek_needed) / vega_indv_asset;
					}

				vega_sold = vega_indv_asset * sold_pct;
				eio_element->Column(col_num_sold_pct).SetValue(t, sold_pct); 

				vega_sold_total += vega_sold;
				vega_asset_remaining -= vega_sold;

				sales_amt += eio_element->mkt_val_sold(t)
							 * eio_element->pct_to_use;

				if (hedge_strat_detail_flag)
					{
					seg->SALFile << eio_element->asset_id << ","
								 << eio_element->hdg_grp_code << ","
								 << vega_indv_asset << ","
								 << sold_pct << ","
								 << eio_element->notional_amt_sold(t) * eio_element->pct_to_use << ","
								 << eio_element->mkt_val_sold(t) * eio_element->pct_to_use << ","
								 << vega_sold << endl;
					}
				}			         
			}
		#endif

		// Erase existing map item and set new item
		asset_greeks_needed.erase(greek_needed_map_index);
		vega_diff = - (vega_asset - vega_sold_total - greek_needed);
		asset_greeks_needed[greek_needed_map_index] = vega_diff;

		if (hedge_strat_detail_flag)
			{
			seg->SALFile << "Sales Summary" << endl;
			seg->SALFile << "VegaNeeded," << greek_needed << endl
						 << "VegaAsset," << vega_asset << endl
						 << "VegaSold," << vega_sold_total << endl
						 << "VegaRemaining," << vega_diff << endl;
			}
		}
	}

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "End Vega Hedge Sales for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

return sales_amt;


}


//@@ END

//@@ START - vega_hedge_transaction_cost
// Vega Hedge Transaction Cost                                                                                             
// Column:VEGA_HEDGE_TRANSACTION_COST
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "vega_hedge_transaction_cost.HDG_GRP_COMP.for"
if (!vega_hedge_flag(t))
	return 0.0;

//For call vega_hedge_inv_amt
vega_hedge_inv_amt(t);

double transaction_cost = 0.0;
double notional_amt_purch = 0.0;
double notional_amt_sold = 0.0;
int mp = 0;
mpmap::iterator mp_map_iter;

#if defined(__EIO_ASSET_H_)
EIO_ASSET *eio_element = NULL;

if (eio_mp_map_active.size() > 0)
	{
	for (mp_map_iter = eio_mp_map_active.begin();
		 mp_map_iter != eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		eio_element = company->sm_asset->sm_eio[mp];

		if (t < eio_element->commencement_period
			|| (t == eio_element->commencement_period
				&& eio_element->purchased_bom_flag)
			|| (t > max(0, eio_element->commencement_period)
				&& fabs(eio_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
			|| eio_element->hdg_grp_code.find("Vega") < string:: npos)
			continue;

		notional_amt_sold = eio_element->notional_amt_sold(t) * eio_element->pct_to_use;
		notional_amt_purch = eio_element->notional_amt_purch(t) * eio_element->pct_to_use;		

		transaction_cost += (fabs(notional_amt_sold) + fabs(notional_amt_purch)) 
		                   * hedge_grp_gamma_vega_hedge_transaction_costs_bps / 10000.0;
		}			         
	}
#endif

return transaction_cost;

}


//@@ END

//@@ START - vega_index_1
// Vega Index 1 All Terms                                                                                             
// Column:VEGA_INDEX_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1(int t) {
//^^^



//^^^

#line 1 "vega_index_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[0] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_1_term_1
// Vega Index 1 Term 1                                                                                             
// Column:VEGA_INDEX_1_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_1_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 1)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[0] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_1_term_2
// Vega Index 1 Term 1                                                                                             
// Column:VEGA_INDEX_1_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_1_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 1)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[0] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_1_term_3
// Vega Index 1 Term 1                                                                                             
// Column:VEGA_INDEX_1_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_1_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 1)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[0] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_2
// Vega Index 2 All Terms                                                                                             
// Column:VEGA_INDEX_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2(int t) {
//^^^



//^^^

#line 1 "vega_index_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[1] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_2_term_1
// Vega Index 2 Term 1                                                                                             
// Column:VEGA_INDEX_2_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_2_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 2)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[1] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_2_term_2
// Vega Index 2 Term 2                                                                                             
// Column:VEGA_INDEX_2_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_2_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 2)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[1] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_2_term_3
// Vega Index 2 Term 3                                                                                             
// Column:VEGA_INDEX_2_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_2_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 2)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[1] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_3
// Vega Index 3 All Terms                                                                                             
// Column:VEGA_INDEX_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3(int t) {
//^^^



//^^^

#line 1 "vega_index_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[2] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_3_term_1
// Vega Index 3 Term 1                                                                                             
// Column:VEGA_INDEX_3_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_3_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 3)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[2] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_3_term_2
// Vega Index 3 Term 2                                                                                             
// Column:VEGA_INDEX_3_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_3_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 3)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[2] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_3_term_3
// Vega Index 3 Term 3                                                                                             
// Column:VEGA_INDEX_3_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_3_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 3)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[2] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_4
// Vega Index 4 All Terms                                                                                             
// Column:VEGA_INDEX_4
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4(int t) {
//^^^



//^^^

#line 1 "vega_index_4.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 4)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[3] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_4_term_1
// Vega Index 4 Term 1                                                                                             
// Column:VEGA_INDEX_4_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_4_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 4)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[3] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_4_term_2
// Vega Index 4 Term 2                                                                                             
// Column:VEGA_INDEX_4_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_4_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 4)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[3] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_4_term_3
// Vega Index 4 Term 3                                                                                             
// Column:VEGA_INDEX_4_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_4_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 4)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[3] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_5
// Vega Index 5 All Terms                                                                                             
// Column:VEGA_INDEX_5
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5(int t) {
//^^^



//^^^

#line 1 "vega_index_5.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 5)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[4] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_5_term_1
// Vega Index 5 Term 1                                                                                             
// Column:VEGA_INDEX_5_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_5_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 5)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[4] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_5_term_2
// Vega Index 5 Term 2                                                                                             
// Column:VEGA_INDEX_5_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_5_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 5)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[4] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_5_term_3
// Vega Index 5 Term 1                                                                                             
// Column:VEGA_INDEX_5_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_5_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 5)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[4] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_6
// Vega Index 6 All Terms                                                                                             
// Column:VEGA_INDEX_6
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6(int t) {
//^^^



//^^^

#line 1 "vega_index_6.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 6)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[5] + "_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_6_term_1
// Vega Index 6 Term 1                                                                                             
// Column:VEGA_INDEX_6_TERM_1
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_1(int t) {
//^^^



//^^^

#line 1 "vega_index_6_term_1.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 6)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 1)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[5] + "_" + company->vega_hedge_term_list[0] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_6_term_2
// Vega Index 6 Term 2                                                                                             
// Column:VEGA_INDEX_6_TERM_2
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_2(int t) {
//^^^



//^^^

#line 1 "vega_index_6_term_2.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 6)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 2)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[5] + "_" + company->vega_hedge_term_list[1] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_index_6_term_3
// Vega Index 6 Term 3                                                                                             
// Column:VEGA_INDEX_6_TERM_3
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_3(int t) {
//^^^



//^^^

#line 1 "vega_index_6_term_3.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

if (company->vega_hedge_index_list.size() < 6)
	return NO_AVG;

if (company->vega_hedge_term_list.size() < 3)
	return NO_AVG;

greek_index = "Vega_" + company->vega_hedge_index_list[5] + "_" + company->vega_hedge_term_list[2] + "_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - vega_parallel
// Vega Parallel                                                                                             
// Column:VEGA_PARALLEL
//========================================================
double HDG_GRP_COMP_UDF::hdg_grp_comp_vega_parallel(int t) {
//^^^



//^^^

#line 1 "vega_parallel.HDG_GRP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

xstring greek_index;

greek_index = "Vega_Parallel_AllTerms_" + xstring(t);

return liab_greeks[greek_index];

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int HDG_GRP_COMP_UDF::hdg_grp_comp_final_period() {
//^^^


#line 1 "final_period.HDG_GRP_COMP.for"
return last_proj_period;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring HDG_GRP_COMP_UDF::hdg_grp_comp_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.HDG_GRP_COMP.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_date() {
//^^^


#line 1 "proj_start_date.HDG_GRP_COMP.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.HDG_GRP_COMP.for"
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
int HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.HDG_GRP_COMP.for"
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
int HDG_GRP_COMP_UDF::hdg_grp_comp_start_period() {
//^^^


#line 1 "start_period.HDG_GRP_COMP.for"
return 0;

}


//@@ END


#line 1 "calc_asset_greeks.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::calc_asset_greeks(int t, int greek_type, int greek_timing)
{
// The parameters for this function are defined as follows: 
//     t:                       The time period for the calculation
//     greek_type:              The type of greek to calculate, e.g. DELTA
//     greek_timing:            The timing for the greek calculation, e.g. BEFORE_SALE
//
// The following table lists valid greek_type values.  
//   = DELTA           for delta calculations
//   = GAMMA           for gamma calculations
//   = VEGA            for vega calculations
//   = RHO             for rho calculations
//   = RHO_CONVEXITY   for rho convexity calculations
//
// The following table lists valid greek_timing values.  
//   = BEFORE_SALE     for before sale calculations
//   = PURCH           for purchase asset calculations
//   = END_OF_PERIOD   for end of period calculations

xstring greek_type_string;
if (greek_type == DELTA)
	greek_type_string = "Delta";
else if (greek_type == GAMMA)
	greek_type_string = "Gamma";
else if (greek_type == VEGA)
	greek_type_string = "Vega";
else if (greek_type == RHO)
	greek_type_string = "Rho";
else if (greek_type == RHO_CONVEXITY)
	greek_type_string = "RhoConvexity";
else
	throw FatalError("Invalid 'greek_type' passed to 'calc_asset_greeks' function.");	

xstring greek_timing_string;
if (greek_timing == BEFORE_SALE)
	greek_timing_string = "BefSale";
else if (greek_timing == PURCH)
	greek_timing_string = "Purchase";
else if (greek_timing == END_OF_PERIOD)
	greek_timing_string = "EndOfPeriod";
else
	throw FatalError("Invalid 'greek_timing' passed to 'calc_asset_greeks' function.");	

// Force order of processing of greeks hedging in order to consider residuals
if (greek_type == DELTA)
	{
	gamma_hedge_inv_amt(t);
	vega_hedge_inv_amt(t);
	}
else if (greek_type == RHO_CONVEXITY)
	{
	gamma_hedge_inv_amt(t);
	vega_hedge_inv_amt(t);
	delta_hedge_inv_amt(t);
	}
else if (greek_type == RHO)
	{
	gamma_hedge_inv_amt(t);
	vega_hedge_inv_amt(t);
	delta_hedge_inv_amt(t);
	rho_convex_hedge_inv_amt(t);
	}

// Force call hedging investment amount columns to ensure that asset maps are updated to end of month
if (greek_timing == END_OF_PERIOD)
	{
	gamma_hedge_inv_amt(t);
	vega_hedge_inv_amt(t);
	delta_hedge_inv_amt(t);
	rho_convex_hedge_inv_amt(t);
	rho_hedge_inv_amt(t);
	}

int BASELINE = 0;
int UP = 1;
int DOWN = 2;
int shock_direction;
xstring shock_index;
xstring detail_shock_id;
SmartArray <SmartArray<double> > opt_val_baseline;
SmartArray <SmartArray<double> > opt_val_up_1;
SmartArray <SmartArray<double> > opt_val_down_1;
// The parallel option values will be stored in the last element of the array
if (greek_type == DELTA || greek_type == GAMMA)
	{
	int index_list_size = max(1, company->delta_gamma_hedge_index_list.size());
	opt_val_baseline.resize(index_list_size);
	opt_val_up_1.resize(index_list_size);
	opt_val_down_1.resize(index_list_size);

	// resize the second dimension to 1 and initialize at 0
	for (int i = 0; i < index_list_size; i++)
		{
		opt_val_baseline[i].resize(1, 0.0);
		opt_val_up_1[i].resize(1, 0.0);
		opt_val_down_1[i].resize(1, 0.0);
		}
	}
else if (greek_type == VEGA)
	{
	int index_list_size = max(1, company->vega_hedge_index_list.size());
	opt_val_baseline.resize(index_list_size);
	opt_val_up_1.resize(index_list_size);
	opt_val_down_1.resize(index_list_size);

	// resize the second dimension to 1 and initialize at 0
	int vol_terms_size = max(1, company->vega_hedge_term_list.size());
	for (int i = 0; i < index_list_size; i++)
		{
		opt_val_baseline[i].resize(vol_terms_size, 0.0);
		opt_val_up_1[i].resize(vol_terms_size, 0.0);
		opt_val_down_1[i].resize(vol_terms_size, 0.0);
		}
	}
else if (greek_type == RHO || greek_type == RHO_CONVEXITY)
	{
	int key_rate_list_size = max(1, company->rho_hedge_key_rate_list.size());
	opt_val_baseline.resize(key_rate_list_size);
	opt_val_up_1.resize(key_rate_list_size);
	opt_val_down_1.resize(key_rate_list_size);

	// resize the second dimension to 1 and initialize at 0
	for (int i = 0; i < key_rate_list_size; i++)
		{
		opt_val_baseline[i].resize(1, 0.0);
		opt_val_up_1[i].resize(1, 0.0);
		opt_val_down_1[i].resize(1, 0.0);
		}
	}

int seg_num = seg->getElementNumber();
xstring hedge_grp_code = hedge_grp_id;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);
double opt_val_baseline_detail = 0.0;
double opt_val_shock_detail = 0.0;

int num_eio_elements = 0;
int num_eio_elements_in_hedge_grp = 0;
int num_ird_elements = 0;
int num_ird_elements_in_hedge_grp = 0;
#if defined(__EIO_ASSET_H_)
num_eio_elements = asset->sm_eio.size();
num_eio_elements_in_hedge_grp = eio_mp_map_active.size();
#endif
#if defined(__IRD_ASSET_H_)
num_ird_elements = asset->sm_ird.size();
num_ird_elements_in_hedge_grp = ird_mp_map_active.size();
#endif

xstring notional_amt_col_name_base = "notional_amt";
xstring opt_val_baseline_col_name_base = "opt_val_baseline";
xstring opt_val_asset_col_name_base = "opt_val_asset";
xstring opt_val_int_col_name_base = "opt_val_int";
xstring opt_val_vol_col_name_base = "opt_val_vol";
xstring notional_amt_col_name = notional_amt_col_name_base;
xstring opt_val_col_name = "";

if (greek_type == DELTA || greek_type == GAMMA)
	{
	if (greek_timing != PURCH && num_eio_elements_in_hedge_grp == 0)
		hedge_strat_detail_flag = false; // No detail when there are no hedges in the group

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << greek_type_string << " Calculation for "
					 << "Hedge Group=" << hedge_grp_id << " " 
					 << "Calc Timing=" << greek_timing_string << " " 	
					 << "Period=" << t << " "
					 << "Year=" << xint(cal_yr(t)) << " "
					 << "Month=" << xint(cal_mth(t)) << endl;

		seg->SALFile << endl;
		seg->SALFile << "ShockId,AssetId,HedgeGroupCode,NotAmt,OptVal" << endl;
		}

	rates->clear_shifted_rates_maps();

	int index_loops = 1;
	if ((greek_type == DELTA && hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC)
		|| (greek_type == GAMMA && hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC))
		index_loops = company->delta_gamma_hedge_index_list.size();

	int shock_start_num = 1;
	if (greek_type == GAMMA)
		shock_start_num = 0; // process the baseline shock
		
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock;
	for (shock = shock_start_num; shock <= company->delta_gamma_hedge_shock_list.size(); shock++)
		{
		if (shock == 0)
			{
			shock_direction = BASELINE;
			shock_index = "Baseline";
			detail_shock_id = shock_index;
			opt_val_col_name = opt_val_baseline_col_name_base;
			}
		else
			{
			opt_val_col_name = opt_val_asset_col_name_base;

			// set lookup key
			shock_id = company->delta_gamma_hedge_shock_list[shock - 1];
			detail_shock_id = shock_id;
			shock_index = shock_id(0, shock_id.find("EqtPrice"));

			// Skip the shock(s) not needed based on the delta hedging liability shock definition
			if (greek_type == DELTA
				&& (hedge_grp_delta_hedge_liab_shock_defn == PARALLEL && shock_index != "Parallel"
					|| hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC && shock_index == "Parallel"))
				continue;

			// Skip the shock(s) not needed based on the delta hedging liability shock definition
			if (greek_type == GAMMA
				&& (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL && shock_index != "Parallel"
					|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC && shock_index == "Parallel"))
				continue;

			if (shock_id.find("Up") < string::npos)
				{
				shock_direction = UP;
				opt_val_col_name += "_up_1";
				}
			else
				{
				shock_direction = DOWN;
				opt_val_col_name += "_down_1";
				}
			}

		for (int index = 0; index < index_loops; index++)
			{
			xstring index_name;
			if ((greek_type == DELTA && hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
				|| (greek_type == GAMMA && hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL))
				index_name = "Parallel"; 
			else
				index_name = company->delta_gamma_hedge_index_list[index];

			if (shock > 0)
				{
				// Only process the parallel index when running the parallel shock
				if (shock_index == "Parallel" && index_name != "Parallel")
					continue;

				// Only process the single requested index when not running the parallel shock
				if (shock_index != "Parallel" && shock_index != index_name)
					continue;

				// setup the shifted rates map
				if (shock_index == "Parallel")
					{
					// For parallel, need to loop over all indexes specified in the equity price shock table 
					double eqt_price_shock_tbl_count = 0.0;
					ExtSrcValTable eqt_price_shock_tbl;
					eqt_price_shock_tbl_count = GetColumnKeyValuesCount(eqt_price_shock);
					eqt_price_shock_tbl = GetColumnKeyValues(eqt_price_shock);
					if (eqt_price_shock_tbl_count > 0)
						{
						// Start at column zero since we don't have any blank columns
						for (int col = 0; col < eqt_price_shock_tbl_count; col++)
							{
							// Set lookup key
							hedge_grp_index_name = eqt_price_shock_tbl[0][col].AsString();

							rates->index_val_shifts[hedge_grp_index_name] = eqt_price_shock;
							}
						}
					}
				else
					{
					hedge_grp_index_name = index_name;
					rates->index_val_shifts[hedge_grp_index_name] = eqt_price_shock;
					}
				}

			// Finalize lookup keys
			hedge_grp_index_name = index_name;
			hedge_grp_index_term = "AllTerms";

			if (greek_timing == BEFORE_SALE || greek_timing == END_OF_PERIOD)
				{
				// calculate the option values for the assets in the map
				int mp = 0;
				mpmap::iterator mp_map_iter;

				#if defined(__EIO_ASSET_H_)
				EIO_ASSET *eio_element = NULL;

				if (eio_mp_map_active.size() > 0)
					{
					for (mp_map_iter = eio_mp_map_active.begin();
						 mp_map_iter != eio_mp_map_active.end();
						 mp_map_iter++)
						{
						mp = mp_map_iter->first;
						eio_element = company->sm_asset->sm_eio[mp];
						xstring notional_amt_col_name_final = notional_amt_col_name;
						xstring opt_val_col_name_final = opt_val_col_name;

						hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_index_name;
						// Skip any equity futures in the group for the GAMMA hedging
						// For Delta hedging, need to consider all equity options for delta residuals
						if (greek_type == GAMMA && eio_element->hdg_grp_code != hedge_grp_code)
							continue;

						// For Delta, when the asset is not linked to the index, we skip it
						if (greek_type == DELTA && shock_index != "Parallel"
							&& eio_element->hdg_grp_code.find(hedge_grp_index_name) == string::npos)
							continue;

						// For Delta, we check the notional_amt value for the GAMMA assets since they may have been sold
						if (greek_type == DELTA && eio_element->hdg_grp_code.find("Gamma") < string::npos
							&& (t > max(0, eio_element->commencement_period)
								&& fabs(eio_element->notional_amt(t)) < ASSET_ACTIVE_THRESHOLD))
							continue;

						if (t < eio_element->commencement_period
							|| (t == eio_element->commencement_period
								&& eio_element->purchased_bom_flag)
							|| (t > max(0, eio_element->commencement_period)
								&& fabs(eio_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD))
							continue;

						if (greek_timing == BEFORE_SALE	&& eio_element->hdg_grp_code.find(greek_type_string) < string::npos)
							{
							notional_amt_col_name_final += "_bef_sale";
							opt_val_col_name_final += "_bef_sale";
							}

						if (shock_direction == BASELINE)
							opt_val_baseline[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
															                     * eio_element->pct_to_use;
						else if (shock_direction == UP)
							opt_val_up_1[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
													                         * eio_element->pct_to_use;
						else if (shock_direction == DOWN)
							opt_val_down_1[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
							                                                   * eio_element->pct_to_use;
						if (hedge_strat_detail_flag)
							seg->SALFile << detail_shock_id << "," 
										 << eio_element->asset_id << ","
										 << eio_element->hdg_grp_code << ","
										 << eio_element->Column(notional_amt_col_name_final).Value(t) * eio_element->pct_to_use << ","
										 << opt_val_shock_detail << endl;
						}			         
					}
				#endif
				}
			else if (greek_timing == PURCH)
				{
				// calculate the option values for the possible purchase assets
				int new_mp_num = -1;
				hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_index_name;

				xstring hedge_asset_id;
				if (greek_type == DELTA)
					hedge_asset_id = hedge_grp_delta_hedge_asset_id;
				else
					hedge_asset_id = hedge_grp_gamma_vega_hedge_asset_id;

				xstring purch_hedge_index_name = get_purch_asset_index_name(seg_num, index_name, hedge_asset_id);
				
				double notional_amt_to_purch = 0.0;

				if (greek_type == DELTA)
					notional_amt_to_purch = rates->get_index_val(t, purch_hedge_index_name);
				else
					notional_amt_to_purch = ONE_MILLION;

				company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																	  NO, //save_assets
																	  HEDGING,
																	  new_mp_num,
																	  hedge_grp_code,
																	  hedge_asset_id,
																	  notional_amt_to_purch,
																	  -1.0,
																	  -1.0);

				xstring notional_amt_col_name_final = notional_amt_col_name + "_bef_sale";
				xstring opt_val_col_name_final = opt_val_col_name + "_bef_sale";

				#if defined(__EIO_ASSET_H_)
				EIO_ASSET *eio_element = NULL;
				eio_element = asset->sm_eio[new_mp_num];

				if (shock_direction == BASELINE)
					opt_val_baseline[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t);
				else if (shock_direction == UP)
					opt_val_up_1[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t);
				else if (shock_direction == DOWN)
					opt_val_down_1[index][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t);

				if (hedge_strat_detail_flag)
					{
					if (hedge_strat_detail_flag)
						seg->SALFile << detail_shock_id << "," 
									 << eio_element->asset_id << ","
									 << eio_element->hdg_grp_code << ","
									 << eio_element->Column(notional_amt_col_name_final).Value(t) << ","
									 << opt_val_shock_detail << endl;
					}

				// Remove the temporarily created index option model point
				asset->sm_eio.resize(num_eio_elements);
				#endif
				}

			// Clear the shifted rates maps
			rates->clear_shifted_rates_maps();
			}
		}

	if (shock > 0) // only process for non baseline shock
		{
		if (hedge_strat_detail_flag)
			{
			seg->SALFile << endl << greek_type_string << " " << greek_timing_string << " Results" << endl;
			seg->SALFile << "IndexName," << greek_type_string << endl;
			}

		for (int index = 0; index < index_loops; index++)
			{
			xstring index_name;
			if ((greek_type == DELTA && hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
				|| (greek_type == GAMMA && hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL))
				index_name = "Parallel"; 
			else
				index_name = company->delta_gamma_hedge_index_list[index];

			xstring map_index = greek_type_string + "_" + greek_timing_string + "_" + index_name + "_" + xstring(t);

			if (greek_type == DELTA)
				asset_greeks[map_index] = opt_val_up_1[index][0] - opt_val_down_1[index][0];
			else // greek_type == GAMMA
				asset_greeks[map_index] = opt_val_up_1[index][0] + opt_val_down_1[index][0] - 2.0 * opt_val_baseline[index][0];

			if (hedge_strat_detail_flag)
				seg->SALFile << index_name << ","
							 << asset_greeks[map_index] << endl;
			}
		}
	}
else if (greek_type == VEGA)
	{
	if (greek_timing != PURCH && num_eio_elements_in_hedge_grp == 0)
		hedge_strat_detail_flag = false; // No detail when there are no hedges in the group

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << greek_type_string << " Calculation for "
					 << "Hedge Group=" << hedge_grp_id << " " 
					 << "Calc Timing=" << greek_timing_string << " " 	
					 << "Period=" << t << " "
					 << "Year=" << xint(cal_yr(t)) << " "
					 << "Month=" << xint(cal_mth(t)) << endl;

		seg->SALFile << endl;
		seg->SALFile << "ShockId,AssetId,HedgeGroupCode,NotAmt,OptVal" << endl;
		}

	rates->clear_shifted_rates_maps();

	int index_loops = 1;
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
		|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
		index_loops = company->vega_hedge_index_list.size();

	int index_term_loops = 1;
	if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC)
		index_term_loops = company->vega_hedge_term_list.size();	

	for (int shock = 0; shock < company->vega_hedge_shock_list.size(); shock++)
		{
		opt_val_col_name = opt_val_vol_col_name_base;

		// set lookup key
		shock_id = company->vega_hedge_shock_list[shock];
		detail_shock_id = shock_id;
		shock_index = shock_id(0, shock_id.find("EqtVol"));

		// Skip the shock(s) not needed based on the gamma vega hedging liability shock definition
		if ((hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL && shock_index != "Parallel")
			|| (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC && shock_index == "Parallel")
			|| (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC && shock_index == "Parallel"))
			continue;

		// Skip the AllTerms shocks if the gamma vega hedging liability shock definition is Index Term Specific
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC && shock_id.find("AllTerms") < string::npos)
			continue;

		// Skip the Term specific shocks if the gamma vega hedging liability shock definition is Index Specific
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC && shock_id.find("AllTerms") == string::npos)
			continue;

		if (shock_id.find("Up") < string::npos)
			shock_direction = UP;
		else
			shock_direction = DOWN;

		for (int index = 0; index < index_loops; index++)
			{
			// set lookup key
			if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
				hedge_grp_index_name = "Parallel";
			else
				hedge_grp_index_name = company->vega_hedge_index_list[index];

			// Only process the single requested index
			if (shock_index != hedge_grp_index_name)
				continue;

			// Populate the volatility shift map
			for (int term = 0; term <= 600; term++)
				{
				// Set rate term lookup keys
				hedge_grp_rate_term = term / 12.0; // term is the month, rate_term is the year

				// setup the shifted rates map
				xstring map_index = hedge_grp_index_name + "_" + xstring(term);
				rates->index_vols_shifts[map_index] = eqt_vol_shock;
				}

			for (int index_term = 0; index_term < index_term_loops; index_term++)
				{
				if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL
					|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
					hedge_grp_index_term = "AllTerms";
				else
					hedge_grp_index_term = company->vega_hedge_term_list[index_term]; 

				// Only process the AllTerms index term when running the parallel shock
				if (shock_index == "Parallel" && hedge_grp_index_term != "AllTerms")
					continue;

				// Only process the AllTerms index term when the liab shock defn is Index Specific
				if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC && hedge_grp_index_term != "AllTerms")
					continue;

				if (greek_timing == BEFORE_SALE || greek_timing == END_OF_PERIOD)
					{
					// calculate the option values for the assets in the map
					int mp = 0;
					mpmap::iterator mp_map_iter;

					#if defined(__EIO_ASSET_H_)
					EIO_ASSET *eio_element = NULL;

					if (eio_mp_map_active.size() > 0)
						{
						for (mp_map_iter = eio_mp_map_active.begin();
							 mp_map_iter != eio_mp_map_active.end();
							 mp_map_iter++)
							{
							mp = mp_map_iter->first;
							eio_element = company->sm_asset->sm_eio[mp];
							xstring notional_amt_col_name_final = notional_amt_col_name;
							xstring opt_val_col_name_final = opt_val_col_name;

							hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_index_name + "|" + hedge_grp_index_term;
							if (eio_element->hdg_grp_code != hedge_grp_code)
								continue;

							if (t < eio_element->commencement_period
								|| (t == eio_element->commencement_period
									&& eio_element->purchased_bom_flag)
								|| (t > max(0, eio_element->commencement_period)
									&& fabs(eio_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD))
								continue;

							if (hedge_grp_index_term != "AllTerms")
							   opt_val_col_name_final += "_term_" + xstring(index_term + 1);

							if (shock_direction == UP)
								opt_val_col_name_final += "_up_1";
							else // if (shock_direction == DOWN)
								opt_val_col_name_final += "_down_1";

							if (greek_timing == BEFORE_SALE	&& eio_element->hdg_grp_code.find(greek_type_string) < string::npos)
								{
								notional_amt_col_name_final += "_bef_sale";
								opt_val_col_name_final += "_bef_sale";
								}

							if (shock_direction == UP)
								opt_val_up_1[index][index_term] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
																                          * eio_element->pct_to_use;
							else // if (shock_direction == DOWN)
								opt_val_down_1[index][index_term] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
																                            * eio_element->pct_to_use;

							if (hedge_strat_detail_flag)
								seg->SALFile << detail_shock_id << "," 
											 << eio_element->asset_id << ","
											 << eio_element->hdg_grp_code << ","
											 << eio_element->Column(notional_amt_col_name_final).Value(t) * eio_element->pct_to_use << ","
											 << opt_val_shock_detail << endl;
							}			         
						}
					#endif
					}

				if (greek_timing == PURCH)
					{
					// calculate the option values for the possible purchase assets
					int new_mp_num = -1;
					hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_index_name + "|" + hedge_grp_index_term;

					// Setup purchase asset. Will create new index option model point
					double notional_amt_to_purch = ONE_MILLION;

					company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		  NO, //save_assets
																		  HEDGING,
																		  new_mp_num,
																		  hedge_grp_code,
																		  hedge_grp_gamma_vega_hedge_asset_id,
																		  notional_amt_to_purch,
																		  -1.0,
																		  -1.0);

					xstring notional_amt_col_name_final = notional_amt_col_name + "_bef_sale";
					xstring opt_val_col_name_final = opt_val_col_name;

					if (hedge_grp_index_term != "AllTerms")
					   opt_val_col_name_final += "_term_" + xstring(index_term + 1);

					if (shock_direction == UP)
						opt_val_col_name_final += "_up_1_bef_sale";
					else // if (shock_direction == DOWN)
						opt_val_col_name_final += "_down_1_bef_sale";

					#if defined(__EIO_ASSET_H_)
					EIO_ASSET *eio_element = NULL;
					eio_element = asset->sm_eio[new_mp_num];

					if (shock_direction == UP)
						opt_val_up_1[index][index_term] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t);
					else // if (shock_direction == DOWN)
						opt_val_down_1[index][index_term] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t);

					if (hedge_strat_detail_flag)
						seg->SALFile << detail_shock_id << "," 
									 << eio_element->asset_id << ","
									 << eio_element->hdg_grp_code << ","
									 << eio_element->Column(notional_amt_col_name_final).Value(t) * eio_element->pct_to_use << ","
									 << opt_val_shock_detail << endl;

					// Remove the temporarily created index option model point
					asset->sm_eio.resize(num_eio_elements);
					#endif
					}
				}
			// Clear the shifted rates maps
			rates->clear_shifted_rates_maps();
			}
		}

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl << greek_type_string << " " << greek_timing_string << " Results" << endl;
		seg->SALFile << "IndexName,IndexTermName" << greek_type_string << endl;
		}

	for (int index = 0; index < index_loops; index++)
		{
		xstring index_name;
		if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
			index_name = "Parallel";
		else
			index_name = company->vega_hedge_index_list[index];

		xstring index_term_name;
		for (int index_term = 0; index_term < index_term_loops; index_term++)
			{
			if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL
				|| hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
				index_term_name = "AllTerms";
			else
				index_term_name = company->vega_hedge_term_list[index_term]; 

			xstring map_index = greek_type_string + "_" + greek_timing_string + "_" + index_name + "_" + index_term_name + "_" + xstring(t);
			asset_greeks[map_index] = opt_val_up_1[index][index_term] - opt_val_down_1[index][index_term];

			if (hedge_strat_detail_flag)
				seg->SALFile << index_name << ","
							 << index_term_name << ","				
							 << asset_greeks[map_index] << endl;
			}
		}
	}
else if (greek_type == RHO || greek_type == RHO_CONVEXITY)
	{
	if (greek_timing != PURCH && num_ird_elements_in_hedge_grp == 0
		&& num_eio_elements_in_hedge_grp == 0)
		hedge_strat_detail_flag = false; // No detail when there are no hedges in the group

	if (hedge_strat_detail_flag)
		{
		seg->SALFile << endl;
		seg->SALFile << greek_type_string << " Calculation for "
					 << "Hedge Group=" << hedge_grp_id << " " 
					 << "Calc Timing=" << greek_timing_string << " " 	
					 << "Period=" << t << " "
					 << "Year=" << xint(cal_yr(t)) << " "
					 << "Month=" << xint(cal_mth(t)) << endl;

		seg->SALFile << endl;
		seg->SALFile << "ShockId,AssetId,HedgeGroupCode,NotAmt,OptVal" << endl;
		}

	rates->clear_shifted_rates_maps();

	int key_rate_loops = 1;
	if ((greek_type == RHO && hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC)
		|| (greek_type == RHO_CONVEXITY && hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC))
		key_rate_loops = company->rho_hedge_key_rate_list.size();

	int shock_start_num = 1;
	if (greek_type == RHO_CONVEXITY)
		shock_start_num = 0;
		
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock;
	for (shock = shock_start_num; shock <= company->rho_hedge_shock_list.size(); shock++)
		{
		if (shock == 0)
			{
			shock_direction = BASELINE;
			shock_index = "Baseline";
			detail_shock_id = shock_index;
			opt_val_col_name = opt_val_baseline_col_name_base;
			}
		else
			{
			opt_val_col_name = opt_val_int_col_name_base;

			// set lookup key
			shock_id = company->rho_hedge_shock_list[shock - 1];
			detail_shock_id = shock_id;
			shock_index = shock_id(0, shock_id.find("IntRate"));

			// Skip the shock(s) not needed based on the rho hedging liability shock definition
			if (greek_type == RHO 
				&& (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL && shock_index != "Parallel")
					|| (hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC && shock_index == "Parallel"))
				continue;

			// Skip the shock(s) not needed based on the rho convexity hedging liability shock definition
			if (greek_type == RHO_CONVEXITY 
				&& (hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL && shock_index != "Parallel")
					|| (hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC && shock_index == "Parallel"))
				continue;

			if (shock_id.find("Up") < string::npos)
				shock_direction = UP;
			else
				shock_direction = DOWN;
			}

		for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
			{
			// set lookup key
			if ((greek_type == RHO && hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
				|| (greek_type == RHO_CONVEXITY && hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL))
				hedge_grp_key_rate = "Parallel";
			else
				hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

			if (shock > 0) // only check when not running the baseline shock
				{
				// Only process the single requested interest rate shift
				if (shock_index != hedge_grp_key_rate)
					continue;

				// set yield curve lookup key
				hedge_grp_yld_curve_id = "Govt";

				// Populate the Govt yield rate shift map
				for (int term = 0; term <= 600; term++)
					{
					// Set rate term lookup keys
					hedge_grp_rate_term = term / 12.0; // term is the month, rate_term is the year

					// setup the shifted rates map
					xstring map_index = "Govt_" + xstring(term);
					rates->yld_rates_shifts[map_index] = int_rate_shock;
					}
				}

			if (greek_timing == BEFORE_SALE || greek_timing == END_OF_PERIOD)
				{
				// calculate the option values for the assets in the map
				int mp = 0;
				mpmap::iterator mp_map_iter;

				// Process Index options for rho convexity and rho residuals
				#if defined(__EIO_ASSET_H_) 
				EIO_ASSET *eio_element = NULL;

				if (eio_mp_map_active.size() > 0)
					{
					for (mp_map_iter = eio_mp_map_active.begin();
						 mp_map_iter != eio_mp_map_active.end();
						 mp_map_iter++)
						{
						mp = mp_map_iter->first;
						eio_element = company->sm_asset->sm_eio[mp];
						xstring notional_amt_col_name_final = notional_amt_col_name;
						xstring opt_val_col_name_final = opt_val_col_name;

						// Check the notional_amt value for the Delta and Gamma assets since they may have been sold
						if ((eio_element->hdg_grp_code.find("Gamma") < string::npos
							 || eio_element->hdg_grp_code.find("Delta") < string::npos)
							&& (t > max(0, eio_element->commencement_period)
								&& fabs(eio_element->notional_amt(t)) < ASSET_ACTIVE_THRESHOLD))
							continue;

						if (shock_direction == BASELINE)
							opt_val_col_name_final = opt_val_baseline_col_name_base;
						else
							{	
							if (hedge_grp_key_rate != "Parallel")
							   opt_val_col_name_final += "_key_rate_" + xstring(key_rate + 1);
							
							if (shock_direction == UP)
								opt_val_col_name_final += "_up_1";
							else // if (shock_direction == DOWN)
								opt_val_col_name_final += "_down_1";
							}

						if (greek_timing == BEFORE_SALE	&& eio_element->hdg_grp_code.find(greek_type_string) < string::npos)
							{
							notional_amt_col_name_final += "_bef_sale";
							opt_val_col_name_final += "_bef_sale";
							}
	
						if (shock_direction == BASELINE)
							opt_val_baseline[key_rate][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
															                        * eio_element->pct_to_use;
						else if (shock_direction == UP)
							opt_val_up_1[key_rate][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
														                        * eio_element->pct_to_use;
						else if (shock_direction == DOWN)
							opt_val_down_1[key_rate][0] += opt_val_shock_detail = eio_element->Column(opt_val_col_name_final).Value(t)
														                          * eio_element->pct_to_use;

						if (hedge_strat_detail_flag)
							{
							seg->SALFile << detail_shock_id << "," 
										 << eio_element->asset_id << ","
										 << eio_element->hdg_grp_code << ","
										 << eio_element->Column(notional_amt_col_name_final).Value(t) * eio_element->pct_to_use << ","
										 << opt_val_shock_detail << endl;
							}
						}
				   }
				#endif

				#if defined(__IRD_ASSET_H_)
				IRD_ASSET *ird_element = NULL;

				if (ird_mp_map_active.size() > 0)
					{
					for (mp_map_iter = ird_mp_map_active.begin();
						mp_map_iter != ird_mp_map_active.end();
						mp_map_iter++)
						{
						mp = mp_map_iter->first;
						ird_element = company->sm_asset->sm_ird[mp];
						xstring notional_amt_col_name_final = notional_amt_col_name;
						xstring opt_val_col_name_final = opt_val_col_name;

						hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_key_rate;
						if (greek_type == RHO_CONVEXITY && ird_element->hdg_grp_code != hedge_grp_code)
							continue;

						// For Rho, we check the notional_amt value for the RhoConvexity assets since they may have been sold
						if (greek_type == RHO && ird_element->hdg_grp_code.find("RhoConvexity") < string::npos
							&& (t > max(0, ird_element->commencement_period)
								&& fabs(ird_element->notional_amt(t)) < ASSET_ACTIVE_THRESHOLD))
							continue;

						if (t < ird_element->commencement_period
							|| (t > max(0, ird_element->commencement_period)
								&& fabs(ird_element->notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD))
							continue;

						if (shock_direction == BASELINE)
							opt_val_col_name_final = opt_val_baseline_col_name_base;
						else
							{	
							if (hedge_grp_key_rate != "Parallel")
							   opt_val_col_name_final += "_key_rate_" + xstring(key_rate + 1);
							
							if (shock_direction == UP)
								opt_val_col_name_final += "_up_1";
							else // if (shock_direction == DOWN)
								opt_val_col_name_final += "_down_1";
							}

						if (greek_type == RHO && greek_timing == BEFORE_SALE
							&& ird_element->hdg_grp_code.find("RhoConvexity") < string::npos)
							{
							; // Use after sale results from RhoConvexity assets
							}								
						else if (greek_timing == BEFORE_SALE && ird_element->hdg_grp_code.find(greek_type_string) < string::npos)
							{
							notional_amt_col_name_final += "_bef_sale";
							opt_val_col_name_final += "_bef_sale";
							}
	
						if (shock_direction == BASELINE)
							opt_val_baseline[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t)
															                        * ird_element->pct_to_use;
						else if (shock_direction == UP)
							opt_val_up_1[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t)
														                        * ird_element->pct_to_use;
						else if (shock_direction == DOWN)
							opt_val_down_1[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t)
														                          * ird_element->pct_to_use;

						if (hedge_strat_detail_flag)
							{
							seg->SALFile << detail_shock_id << "," 
										 << ird_element->asset_id << ","
										 << ird_element->hdg_grp_code << ","
										 << ird_element->Column(notional_amt_col_name_final).Value(t) * ird_element->pct_to_use << ","
										 << opt_val_shock_detail << endl;
							}
						}
					}
				#endif
				}

			if (greek_timing == PURCH)
				{
				// calculate the option values for the possible purchase assets
				int new_mp_num = -1;
				hedge_grp_code = hedge_grp_id + "|" + greek_type_string + "|" + hedge_grp_key_rate;

				xstring hedge_asset_id;
				if (greek_type == RHO)
					hedge_asset_id = hedge_grp_rho_hedge_asset_id;
				else
					hedge_asset_id = hedge_grp_rho_convex_hedge_asset_id;

				// Setup purchase asset. Will create new interest rate derivative model point
				double notional_amt_to_purch = ONE_MILLION;

				company->sm_inv_strategy[seg_num]->buy_assets_hedging(t, 
																		NO, //save_assets
																		HEDGING,
																		new_mp_num,
																		hedge_grp_code,
																		hedge_asset_id,
																		notional_amt_to_purch,
																		-1.0,
																		-1.0);

				#if defined(__IRD_ASSET_H_)
				IRD_ASSET * ird_element;
				ird_element = asset->sm_ird[new_mp_num];

				// Turn on pricing swap flag
				if (ird_element->contract_defn == SWAP)
					ird_element->price_new_purch_swap_contract_flag = true;

				xstring notional_amt_col_name_final = notional_amt_col_name + "_bef_sale";
				xstring opt_val_col_name_final = opt_val_col_name;

				if (shock_direction == BASELINE)
					opt_val_col_name_final = opt_val_baseline_col_name_base + "_bef_sale";
				else
					{	
					if (hedge_grp_key_rate != "Parallel")
					   opt_val_col_name_final += "_key_rate_" + xstring(key_rate + 1);
					
					if (shock_direction == UP)
						opt_val_col_name_final += "_up_1_bef_sale";
					else // if (shock_direction == DOWN)
						opt_val_col_name_final += "_down_1_bef_sale";
					}

				if (shock_direction == BASELINE)
					opt_val_baseline[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t);
				else if (shock_direction == UP)
					opt_val_up_1[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t);
				else if (shock_direction == DOWN)
					opt_val_down_1[key_rate][0] += opt_val_shock_detail = ird_element->Column(opt_val_col_name_final).Value(t);

				if (hedge_strat_detail_flag)
					{
					seg->SALFile << detail_shock_id << "," 
							     << ird_element->asset_id << ","
								 << ird_element->hdg_grp_code << ","
								 << ird_element->Column(notional_amt_col_name_final).Value(t) * ird_element->pct_to_use << ","
								 << opt_val_shock_detail << endl;
					}

				// Turn off pricing swap flag
				if (ird_element->contract_defn == SWAP)
					ird_element->price_new_purch_swap_contract_flag = false;

				// Remove the temporarily created interest rate derivative model point
				asset->sm_ird.resize(num_ird_elements);
				#endif
				}

			// Clear the shifted rates maps
			rates->clear_shifted_rates_maps();
			}
		}

	if (shock > 0) // only process for non baseline shock
		{
		if (hedge_strat_detail_flag)
			{
			seg->SALFile << endl << greek_type_string << " " << greek_timing_string << " Results" << endl;
			seg->SALFile << "KeyRateTermName," << greek_type_string << endl;
			}

		xstring key_rate_term_name;
		for (int key_rate = 0; key_rate < key_rate_loops; key_rate++)
			{
			if (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
				key_rate_term_name = "Parallel";
			else
				key_rate_term_name = company->rho_hedge_key_rate_list[key_rate]; 

			xstring map_index = greek_type_string + "_" + greek_timing_string + "_" + key_rate_term_name + "_" + xstring(t);

			if (greek_type == RHO)
				asset_greeks[map_index] = opt_val_up_1[key_rate][0] - opt_val_down_1[key_rate][0];
			else // greek_type == RHO_CONVEXITY
				asset_greeks[map_index] = opt_val_up_1[key_rate][0] + opt_val_down_1[key_rate][0] - 2.0 * opt_val_baseline[key_rate][0];

			if (hedge_strat_detail_flag)
				seg->SALFile << key_rate_term_name << ","
							 << asset_greeks[map_index] << endl;
			}
		}
	}
else
	throw FatalError("Invalid 'greek_type' passed to 'calc_asset_greeks' function.");	

// Erase local memory
for (int i = 0; i < opt_val_baseline.size(); i++)
	{
	opt_val_baseline[i].resize(0);
	opt_val_up_1[i].resize(0);
	opt_val_down_1[i].resize(0);
	}

opt_val_baseline.resize(0);
opt_val_up_1.resize(0);
opt_val_down_1.resize(0);

return;
}



#line 1 "calc_pv_claims_charges.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::calc_pv_claims_charges(int mp, double &disc_claim_amt_ab_mp, double &disc_claim_amt_db_mp, 
								   double &disc_claim_amt_ib_mp, double &disc_claim_amt_wb_mp,
							       double &disc_claim_fee_ab_mp, double &disc_claim_fee_db_mp,
								   double &disc_claim_fee_ib_mp, double &disc_claim_fee_wb_mp)
{
#if defined(__VA_LIAB_H_)
// These items are the references to the VA model point values
// The values for these items MUST match the values from the VA startup declarations
static int POLICIES_MP = 6;
static int ANN_CLAIMS_GMWB_MP = 37;
static int ANN_CLAIMS_GMIB_MP = 38;
static int GMDB_CHG_MP = 21;
static int GMIB_CHG_MP = 22;
static int GMWB_CHG_MP = 23;
static int GMAB_CHG_MP = 24;
static int GMAB_MATURITIES_MP = 39;
static int DTH_CLAIMS_GMDB_MP = 40;

double disc_factor = 1.0;
double disc_factor_mthly = 0.0;
if (hedge_disc_rate_defn == DETERMINISTIC)
	disc_factor_mthly = 1.0 / pow(1.0 + hedge_disc_rate_fixed, 1.0 / 12.0);

 //Force calculations till last projection period for PV
for (int time = 0; time <= final_period; time++)
	{
	// Reset claim_amt and claim_fee
	double claim_amt_t_gmab = 0.0;
	double claim_fee_t_gmab = 0.0;
	double disc_claim_amt_t_gmab = 0.0;
	double disc_claim_fee_t_gmab = 0.0;
	double claim_amt_t_gmdb = 0.0;
	double claim_fee_t_gmdb = 0.0;
	double disc_claim_amt_t_gmdb = 0.0;
	double disc_claim_fee_t_gmdb = 0.0;
	double claim_amt_t_gmib = 0.0;
	double claim_fee_t_gmib = 0.0;
	double disc_claim_amt_t_gmib = 0.0;
	double disc_claim_fee_t_gmib = 0.0;
	double claim_amt_t_gmwb = 0.0;
	double claim_fee_t_gmwb = 0.0;
	double disc_claim_amt_t_gmwb = 0.0;
	double disc_claim_fee_t_gmwb = 0.0;

	if (time < liab->sm_va[mp]->commencement_period
		|| time > liab->sm_va[mp]->maturity_period)
		continue;

	// Skip new issue commencement period
	if (liab->sm_va[mp]->elapsed_mths <= 0
		&& time == liab->sm_va[mp]->commencement_period)
		continue;

	if (time > liab->sm_va[mp]->commencement_period + 1
		&& fabs(liab->sm_va[mp]->va_mp_vals[POLICIES_MP][time - 1]) < rate_ratio_threshold)
		continue;

	//Terminate calculations when GMAB has matured		
	if (time > liab->sm_va[mp]->commencement_period + 1
		&& int((time + liab->sm_va[mp]->elapsed_mths - 1) / 12.0 + 1) > liab->sm_va[mp]->gmab_period
		&& !liab->sm_va[mp]->gmdb_flag
		&& !liab->sm_va[mp]->gmib_flag
		&& !liab->sm_va[mp]->gmwb_flag)
		break;

	liab->sm_va[mp]->mp_processed(time);

	if (liab->sm_va[mp]->gmdb_flag)
		{
		claim_amt_t_gmdb += liab->sm_va[mp]->va_mp_vals[DTH_CLAIMS_GMDB_MP][time]; 
		claim_fee_t_gmdb += liab->sm_va[mp]->va_mp_vals[GMDB_CHG_MP][time];
		}
				
	if (liab->sm_va[mp]->gmab_flag)
		{
		claim_amt_t_gmab += liab->sm_va[mp]->va_mp_vals[GMAB_MATURITIES_MP][time]; 
		claim_fee_t_gmab += liab->sm_va[mp]->va_mp_vals[GMAB_CHG_MP][time];
		}
				
	if (liab->sm_va[mp]->gmib_flag)
		{
		claim_amt_t_gmib += liab->sm_va[mp]->va_mp_vals[ANN_CLAIMS_GMIB_MP][time];
		claim_fee_t_gmib += liab->sm_va[mp]->va_mp_vals[GMIB_CHG_MP][time];
		}

	if (liab->sm_va[mp]->gmwb_flag) 
		{
		claim_amt_t_gmwb += liab->sm_va[mp]->va_mp_vals[ANN_CLAIMS_GMWB_MP][time];
		claim_fee_t_gmwb += liab->sm_va[mp]->va_mp_vals[GMWB_CHG_MP][time];
		}
	
	//Calculate discount rate
	if (time == 0)
		disc_factor = 1.0;
	else
		{
		if (hedge_disc_rate_defn == COMPETITOR_RATE)
			disc_factor_mthly = 1.0 / (pow(1.0 + company->get_comp_rate(hedge_disc_rate_comp_id, time), 1.0 / 12.0));
		else if (hedge_disc_rate_defn == BETA_RATE)
			disc_factor_mthly = 1.0 / (pow(1.0 + rates->get_misc_rate(time, "BetaRate", EFFECTIVE_ANNUAL), 1.0 / 12.0));
			
		disc_factor *= disc_factor_mthly;
		}

	//discount claims
	disc_claim_amt_ab_mp += claim_amt_t_gmab * disc_factor;
	disc_claim_fee_ab_mp += claim_fee_t_gmab * disc_factor;

	disc_claim_amt_db_mp += claim_amt_t_gmdb * disc_factor;
	disc_claim_fee_db_mp += claim_fee_t_gmdb * disc_factor;

	disc_claim_amt_ib_mp += claim_amt_t_gmib * disc_factor;
	disc_claim_fee_ib_mp += claim_fee_t_gmib * disc_factor;

	disc_claim_amt_wb_mp += claim_amt_t_gmwb * disc_factor;
	disc_claim_fee_wb_mp += claim_fee_t_gmwb * disc_factor;
	}
#endif

return;
}



#line 1 "delta_hedge_strat.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::delta_hedge_strat(int t)
{
double delta_liab = 0.0;
double delta_asset = 0.0;
double delta_asset_max = 0.0;
double delta_asset_min = 0.0;
double delta_tolerance_liab = 0.0;
double delta_tolerance_dollar = 0.0;
double delta_hedge_pct = 0.0;
double delta_asset_purch = 0.0;
double delta_needed = 0.0;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);

// Determine the asset deltas for each index
calc_asset_greeks(t, DELTA, BEFORE_SALE);

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Delta Hedge Strategy Setup for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Write detail header
if (hedge_strat_detail_flag)
	seg->SALFile << "IndexName,DeltaLiab,DeltaTolPctLiab,DeltaTolDollar,DeltaAssetMax,DeltaAssetMin,DeltaAsset,DeltaHedgePct,AssetDeltaNeeded" << endl;

if (hedge_grp_delta_hedge_liab_shock_defn == PARALLEL)
	{
	// Find the parallel shock from the delta_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->delta_gamma_hedge_shock_list.size(); shock_element++)
		{
		xstring shock_string = company->delta_gamma_hedge_shock_list[shock_element]; 
		if (shock_string.find("Parallel") < string::npos)
			{
			// Set lookup key
			shock_id = shock_string;
			break;
			}
		}

	if (shock_element == company->delta_gamma_hedge_shock_list.size())
		{
		xstring message = xstring("Processing Delta hedge for parallel shock. ")
		                  + xstring("However, no parallel price shock exists in the hedge shock table. ")
						  + xstring("Please correct your data."); 

		throw FatalError(message);
		}


	// Set lookup key
	hedge_grp_index_name = "Parallel";

	delta_tolerance_liab = hedge_grp_delta_hedge_tolerance_pct_liab_delta;
	delta_tolerance_dollar = hedge_grp_delta_hedge_tolerance_dollar;
	delta_hedge_pct = hedge_grp_delta_hedge_pct;

	xstring liab_greek_map_index = "Delta_Parallel_" + xstring(t);
	delta_liab = delta_hedge_pct * liab_greeks[liab_greek_map_index];

	if (delta_liab < 0.0)
		{
		delta_asset_max = delta_liab * (1.0 - delta_tolerance_liab) + delta_tolerance_dollar;
		delta_asset_min = delta_liab * (1.0 + delta_tolerance_liab) - delta_tolerance_dollar;
		}
	else
		{
		delta_asset_max = delta_liab * (1.0 + delta_tolerance_liab) + delta_tolerance_dollar;
		delta_asset_min = delta_liab * (1.0 - delta_tolerance_liab) - delta_tolerance_dollar;
		}

	xstring asset_greek_map_index = "Delta_BeforeSale_Parallel_" + xstring(t);
	delta_asset = asset_greeks[asset_greek_map_index];

	xstring greek_needed_map = "Delta_Parallel_" + xstring(t);
	if (delta_asset > delta_asset_max || delta_asset < delta_asset_min)
		asset_greeks_needed[greek_needed_map] = delta_liab;
	else //Delta Asset is within tolerance and should remain as is
		asset_greeks_needed[greek_needed_map] = delta_asset;	

	if (hedge_strat_detail_flag)
		seg->SALFile << "Parallel," 
			         << delta_liab << ","
					 << delta_tolerance_liab << ","
					 << delta_tolerance_dollar << ","
					 << delta_asset_max << ","
					 << delta_asset_min << ","
					 << delta_asset << ","	
					 << delta_hedge_pct << ","
					 << asset_greeks_needed[greek_needed_map] << endl;
	}
else // hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC
	{
	for (int index = 0; index < company->delta_gamma_hedge_index_list.size(); index++)
		{
		// Set lookup key
		hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];
	
		if (hedge_grp_index_name == "Parallel")
			continue;

		// Find the index shock from the delta_hedge_shock_list
		// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
		int shock_element;
		for (shock_element = 0; shock_element < company->delta_gamma_hedge_shock_list.size(); shock_element++)
			{
			xstring shock_string = company->delta_gamma_hedge_shock_list[shock_element]; 
			if (shock_string.find(hedge_grp_index_name) < string::npos)
				{
				// Set lookup key
				shock_id = shock_string;
				break;
				}
			}

		if (shock_element == company->delta_gamma_hedge_shock_list.size())
			{
			xstring message = "Processing Delta hedge for index shock " + hedge_grp_index_name + ". "
			                  + xstring("However, no shock exist for this index in the hedge shock table. ")
							  + xstring("Please correct your data.");

			throw FatalError(message);
			}

		delta_tolerance_liab = hedge_grp_delta_hedge_tolerance_pct_liab_delta;
		delta_tolerance_dollar = hedge_grp_delta_hedge_tolerance_dollar;
		delta_hedge_pct = hedge_grp_delta_hedge_pct;

		xstring liab_greek_map_index = "Delta_" + hedge_grp_index_name + "_" + xstring(t);
		delta_liab = delta_hedge_pct * liab_greeks[liab_greek_map_index];

		if (delta_liab < 0.0)
			{
			delta_asset_max = delta_liab * (1.0 - delta_tolerance_liab) + delta_tolerance_dollar;
			delta_asset_min = delta_liab * (1.0 + delta_tolerance_liab) - delta_tolerance_dollar;
			}
		else
			{
			delta_asset_max = delta_liab * (1.0 + delta_tolerance_liab) + delta_tolerance_dollar;
			delta_asset_min = delta_liab * (1.0 - delta_tolerance_liab) - delta_tolerance_dollar;
			}

		xstring asset_greek_map_index = "Delta_BeforeSale_" + hedge_grp_index_name + "_" + xstring(t);
		delta_asset = asset_greeks[asset_greek_map_index];

		xstring greek_needed_map = "Delta_" + hedge_grp_index_name + "_" + xstring(t);
		if (delta_asset > delta_asset_max || delta_asset < delta_asset_min)
			asset_greeks_needed[greek_needed_map] = delta_liab; 
		else //Delta Asset is within tolerance and should remain as is
			asset_greeks_needed[greek_needed_map] = delta_asset;	

		if (hedge_strat_detail_flag)
			seg->SALFile << hedge_grp_index_name << "," 
						 << delta_liab << ","
						 << delta_tolerance_liab << ","
						 << delta_tolerance_dollar << ","
						 << delta_asset_max << ","
						 << delta_asset_min << ","
						 << delta_asset << ","
						 << delta_hedge_pct << ","
						 << asset_greeks_needed[greek_needed_map] << endl;
		}
	}

return;
}



#line 1 "gamma_hedge_strat.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::gamma_hedge_strat(int t)
{
double gamma_liab = 0.0;
double gamma_asset = 0.0;
double gamma_asset_max = 0.0;
double gamma_asset_min = 0.0;
double gamma_tolerance_liab = 0.0;
double gamma_tolerance_dollar = 0.0;
double gamma_hedge_pct = 0.0;
double gamma_asset_purch = 0.0;
double gamma_needed = 0.0;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);

// Determine the asset gammas for each index
calc_asset_greeks(t, GAMMA, BEFORE_SALE);

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Gamma Hedge Strategy Setup for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Write detail header
if (hedge_strat_detail_flag)
	seg->SALFile << "IndexName,GammaLiab,GammaTolPctLiab,GammaTolDollar,GammaAssetMax,GammaAssetMin,GammaAsset,GammaHedgePct,AssetGammaNeeded" << endl;

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
	{
	// Find the parallel shock from the gamma_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->delta_gamma_hedge_shock_list.size(); shock_element++)
		{
		xstring shock_string = company->delta_gamma_hedge_shock_list[shock_element]; 
		if (shock_string.find("Parallel") < string::npos)
			{
			// Set lookup key
			shock_id = shock_string;
			break;
			}
		}

	if (shock_element == company->delta_gamma_hedge_shock_list.size())
		{
		xstring message = xstring("Processing Gamma hedge for parallel shock. ")
		                  + xstring("However, no parallel price shock exists in the hedge shock table. ")
						  + xstring("Please correct your data."); 

		throw FatalError(message);
		}

	// set lookup keys
	hedge_grp_index_name = "Parallel";
	hedge_grp_index_term = "AllTerms";

	gamma_tolerance_liab = hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
	gamma_tolerance_dollar = hedge_grp_gamma_vega_hedge_tolerance_dollar;
	gamma_hedge_pct = hedge_grp_gamma_vega_hedge_pct;

	xstring liab_greek_map_index = "Gamma_Parallel_" + xstring(t);
	gamma_liab = gamma_hedge_pct * liab_greeks[liab_greek_map_index];

	if (gamma_liab < 0.0)
		{
		gamma_asset_max = gamma_liab * (1.0 - gamma_tolerance_liab) + gamma_tolerance_dollar;
		gamma_asset_min = gamma_liab * (1.0 + gamma_tolerance_liab) - gamma_tolerance_dollar;
		}
	else
		{
		gamma_asset_max = gamma_liab * (1.0 + gamma_tolerance_liab) + gamma_tolerance_dollar;
		gamma_asset_min = gamma_liab * (1.0 - gamma_tolerance_liab) - gamma_tolerance_dollar;
		}

	xstring asset_greek_map_index = "Gamma_BefSale_Parallel_" + xstring(t);
	gamma_asset = asset_greeks[asset_greek_map_index];

	xstring greek_needed_map = "Gamma_Parallel_" + xstring(t);
	if (gamma_asset > gamma_asset_max || gamma_asset < gamma_asset_min)
		asset_greeks_needed[greek_needed_map] = gamma_liab; 
	else //Gamma Asset is within tolerance and should remain as is
		asset_greeks_needed[greek_needed_map] = gamma_asset;	

	if (hedge_strat_detail_flag)
		seg->SALFile << "Parallel," 
			         << gamma_liab << ","
					 << gamma_tolerance_liab << ","
					 << gamma_tolerance_dollar << ","
					 << gamma_asset_max << ","
					 << gamma_asset_min << ","
					 << gamma_asset << ","
					 << gamma_hedge_pct << ","
					 << asset_greeks_needed[greek_needed_map] << endl;
	}
else // hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC
	{
	for (int index = 0; index < company->delta_gamma_hedge_index_list.size(); index++)
		{
		// Set lookup keys
		hedge_grp_index_name = company->delta_gamma_hedge_index_list[index];
		hedge_grp_index_term = "AllTerms";
	
		// Find the index shock from the delta_gamma_hedge_shock_list
		// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
		int shock_element;
		for (shock_element = 0; shock_element < company->delta_gamma_hedge_shock_list.size(); shock_element++)
			{
			xstring shock_string = company->delta_gamma_hedge_shock_list[shock_element]; 
			if (shock_string.find(hedge_grp_index_name) < string::npos)
				{
				// Set lookup key
				shock_id = shock_string;
				break;
				}
			}

		if (shock_element == company->delta_gamma_hedge_shock_list.size())
			{
			xstring message = "Processing Gamma hedge for index shock " + hedge_grp_index_name + ". "
			                  + xstring("However, no shock exist for this index in the hedge shock table. ")
							  + xstring("Please correct your data.");

			throw FatalError(message);
			}

		gamma_tolerance_liab = hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
		gamma_tolerance_dollar = hedge_grp_gamma_vega_hedge_tolerance_dollar;
		gamma_hedge_pct = hedge_grp_gamma_vega_hedge_pct;

		xstring liab_greek_map_index = "Gamma_" + hedge_grp_index_name + "_" + xstring(t);
		gamma_liab = gamma_hedge_pct * liab_greeks[liab_greek_map_index];

		if (gamma_liab < 0.0)
			{
			gamma_asset_max = gamma_liab * (1.0 - gamma_tolerance_liab) + gamma_tolerance_dollar;
			gamma_asset_min = gamma_liab * (1.0 + gamma_tolerance_liab) - gamma_tolerance_dollar;
			}
		else
			{
			gamma_asset_max = gamma_liab * (1.0 + gamma_tolerance_liab) + gamma_tolerance_dollar;
			gamma_asset_min = gamma_liab * (1.0 - gamma_tolerance_liab) - gamma_tolerance_dollar;
			}

		xstring asset_greek_map_index = "Gamma_BefSale_" + hedge_grp_index_name + "_" + xstring(t);
		gamma_asset = asset_greeks[asset_greek_map_index];

		xstring greek_needed_map = "Gamma_" + hedge_grp_index_name + "_" + xstring(t);
		if (gamma_asset > gamma_asset_max || gamma_asset < gamma_asset_min)
			asset_greeks_needed[greek_needed_map] = gamma_liab; 
		else //Gamma Asset is within tolerance and should remain as is
			asset_greeks_needed[greek_needed_map] = gamma_asset;	

		if (hedge_strat_detail_flag)
			seg->SALFile << hedge_grp_index_name << "," 
						 << gamma_liab << ","
						 << gamma_tolerance_liab << ","
						 << gamma_tolerance_dollar << ","
						 << gamma_asset_max << ","
						 << gamma_asset_min << ","
						 << gamma_asset << ","
						 << gamma_hedge_pct << ","
						 << asset_greeks_needed[greek_needed_map] << endl;
		}
	}
return;
}



#line 1 "get_hedge_valn_final_results.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::get_hedge_valn_final_results(void)
{
if (hedge_proj_stmt_flag)
	{
	xstring file_name = xstring(replaceWildcards(valn_hedge_final_results));

	static bool first_time = true;
	xstring proj_task_loop_num_string = to_string(proj_task_loop_num);

	if (first_time)
		{
		first_time = false;

		string database_name = working_directory() + "hedge_grp_get_hedge_valn_final_results.db";
		openDatabase(database_name);
		string table_name = readCsvFile(file_name.getStdStr());

		// Retrieve valuation results
		xstring report_columns = xstring("_econ_res");
		
		xstring select_concat = xstring("SELECT (TRIM(_group) | TRIM(_period)) AS vgroup, ");
		
		xstring sql = (xstring)"SELECT TRIM(_group) AS vgroup, "
					  + (xstring)"CAST(_task_loop AS INTEGER) AS vtaskloop, "
					  + (xstring)"CAST(_period AS INTEGER) AS vperiod, "
					  + report_columns
					  + (xstring)" FROM '"
					  + table_name
					  + (xstring)"' ORDER BY vgroup, vperiod";
		
		executeQuery(sql.getStdStr(), valn_hedge_final_input_cols, valn_hedge_final_input);
		closeDatabase();
		remove(database_name.c_str());

		if (!valn_hedge_final_input_cols.size())
			{
			throw FatalError("Could not read Hedge Final file: " 
							  + file_name + " "
							  + "Please check your data.");
			}
		
		xstring output_group_name;
		xstring output_period;
		xstring output_task_loop;
		xstring storage_index;

		for (int row = 0; row < valn_hedge_final_input.size(); row++)
			{

			output_group_name = xstring(valn_hedge_final_input[row][0]);
			output_task_loop = xstring(valn_hedge_final_input[row][1]);
			output_period = xstring(valn_hedge_final_input[row][2]);
			storage_index = output_task_loop + "|" + output_group_name + "|" + output_period;

			seg->va_hedge_final_vals[storage_index] = atof(valn_hedge_final_input[row][3].c_str());
			}
		}

	xstring hedge_group_name;
	xstring econ_res_lookup;
	xstring time_period;
	xstring greek_index;

	int element = 0;
	int time = 0;
	
	double econ_res_up = 0.;
	double econ_res_down = 0.;
	double baseline = 0.;

	hedge_group_name = proj_task_loop_num_string + "|" + seg_id + "|" + group;

	for (time = 0; time <= last_proj_period; time++)
		{
		//Add Baseline values by time period
		econ_res_lookup = "Baseline";

		econ_res_lookup = hedge_group_name + "|Baseline|" + xstring(time);
		greek_index = "Baseline_" + xstring(time);

		liab_greeks[greek_index] = seg->va_hedge_final_vals[econ_res_lookup];
		baseline = liab_greeks[greek_index];

		if (hedge_grp_delta_hedge_defn == YES)//Calculate Group Delta Values by time period
			{
			if (hedge_grp_delta_hedge_liab_shock_defn == INDEX_SPECIFIC)
				{
				for (int i = 0; i < company->delta_gamma_hedge_index_list.size(); i++)
					{					
					//Up Shock
					econ_res_lookup = hedge_group_name + "|" + company->delta_gamma_hedge_index_list[i] + "EqtPriceUp|" + xstring(time);
					econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

					//Down Shock
					econ_res_lookup = hedge_group_name + "|" + company->delta_gamma_hedge_index_list[i] + "EqtPriceDown|" + xstring(time);
					econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

					greek_index = "Delta_" + company->delta_gamma_hedge_index_list[i] + "_" + xstring(time);
					liab_greeks[greek_index] = econ_res_up - econ_res_down;
					}				
				}
			else//Parallel
				{
				//Up Shock
				econ_res_lookup = hedge_group_name + "|ParallelEqtPriceUp|" + xstring(time);
				econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

				//Down Shock
				econ_res_lookup = hedge_group_name + "|ParallelEqtPriceDown|" + xstring(time);
				econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

				greek_index = "Delta_Parallel_" + xstring(time);
				liab_greeks[greek_index] = econ_res_up - econ_res_down;
				}
			}
		
		if (hedge_grp_gamma_vega_hedge_defn == YES)//Calculate Group Gamma/Vega Values by time period
			{
			if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
				{
				if (hedge_grp_gamma_vega_hedge_type_defn == GAMMA)
					{
					for (int i = 0; i < company->delta_gamma_hedge_index_list.size(); i++)
						{					
						//Up Shock
						econ_res_lookup = hedge_group_name + "|" + company->delta_gamma_hedge_index_list[i] + "EqtPriceUp" + "|" + xstring(time);
						econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

						//Down Shock
						econ_res_lookup = hedge_group_name + "|" + company->delta_gamma_hedge_index_list[i] + "EqtPriceDown" + "|" + xstring(time);
						econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

						greek_index = "Gamma_" + company->delta_gamma_hedge_index_list[i] + "_" + xstring(time);
						liab_greeks[greek_index] = econ_res_up + econ_res_down - baseline * 2.0;
						}				
					}
				else//Vega
					{
					for (int i = 0; i < company->vega_hedge_index_term_list.size(); i++)
						{					
						if (company->vega_hedge_index_term_list[i].find("AllTerms") < string::npos)//Only Calculate AllTerms
							{
							//Up Shock
							econ_res_lookup = hedge_group_name + "|" + company->vega_hedge_index_term_list[i] + "Up|" + xstring(time);
							econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

							//Down Shock
							econ_res_lookup = hedge_group_name + "|" + company->vega_hedge_index_term_list[i] + "Down|" + xstring(time);
							econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

							xstring index = company->vega_hedge_index_term_list[i](0,company->vega_hedge_index_term_list[i].find("EqtVolAllTerms"));
							
							greek_index = "Vega_" + index + "_AllTerms_" + xstring(time);
							liab_greeks[greek_index] = econ_res_up - econ_res_down;
							}
						}				
					}
				}
			else if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC && hedge_grp_gamma_vega_hedge_type_defn == VEGA)
				{
				for (int i = 0; i < company->vega_hedge_index_term_list.size(); i++)
					{										
					if (company->vega_hedge_index_term_list[i].find("AllTerms") == string::npos)//Only calculate term specific
						{
						//Up Shock
						econ_res_lookup = hedge_group_name + "|" + company->vega_hedge_index_term_list[i] + "Up|" + xstring(time);
						econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

						//Down Shock
						econ_res_lookup = hedge_group_name + "|" + company->vega_hedge_index_term_list[i] + "Down|" + xstring(time);
						econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

						int EqtVolPos = company->vega_hedge_index_term_list[i].find("EqtVol") + 6;
						int length = company->vega_hedge_index_term_list[i].length();

						xstring index = company->vega_hedge_index_term_list[i](0, company->vega_hedge_index_term_list[i].find("EqtVol"));
						xstring term = company->vega_hedge_index_term_list[i](EqtVolPos, length-EqtVolPos);

						greek_index = "Vega_" + index + "_" + term + "_" + xstring(time);
						liab_greeks[greek_index] = econ_res_up - econ_res_down;
						}
					}		
				}
			else//Parallel
				{
				xstring econ_res_lookup_shock;

				if (hedge_grp_gamma_vega_hedge_type_defn == GAMMA)
					econ_res_lookup_shock = "EqtPrice";
				else
					econ_res_lookup_shock = "EqtVol";

				//Up Shock
				econ_res_lookup = hedge_group_name + "|Parallel" + econ_res_lookup_shock + "Up|" + xstring(time);
				econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

				//Down Shock
				econ_res_lookup = hedge_group_name + "|Parallel" + econ_res_lookup_shock + "Down|" + xstring(time);
				econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

				greek_index = hedge_grp_gamma_vega_hedge_type_defn + "_Parallel_" + xstring(time);

				if (hedge_grp_gamma_vega_hedge_type_defn == GAMMA)
					liab_greeks[greek_index] = econ_res_up + econ_res_down - baseline * 2.;
				else
					liab_greeks[greek_index] = econ_res_up - econ_res_down;
				}
			}

		if (hedge_grp_rho_hedge_defn == YES)//Calculate Group Rho Values by time period
			{
			if (hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC)
				{
				for (int i = 0; i < company->rho_hedge_key_rate_list.size(); i++)
					{					
					//Up Shock
					econ_res_lookup = hedge_group_name + "|" + company->rho_hedge_key_rate_list[i] + "IntRateUp|" + xstring(time);
					econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

					//Down Shock
					econ_res_lookup = hedge_group_name + "|" + company->rho_hedge_key_rate_list[i] + "IntRateDown|" + xstring(time);
					econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

					greek_index = "Rho_" + company->rho_hedge_key_rate_list[i] + "_" + xstring(time);
					liab_greeks[greek_index] = econ_res_up - econ_res_down;
					}				
				}
			else//Parallel
				{
				//Up Shock
				econ_res_lookup = hedge_group_name + "|ParallelIntRateUp|" + xstring(time);
				econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

				//Down Shock
				econ_res_lookup = hedge_group_name + "|ParallelIntRateDown|" + xstring(time);
				econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

				greek_index = "Rho_Parallel_" + xstring(time);
				liab_greeks[greek_index] = econ_res_up - econ_res_down;
				}
			}

		if (hedge_grp_rho_convex_hedge_defn == YES)//Calculate Group Rho Convexity Values by time period
			{
			if (hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC)
				{
				for (int i = 0; i < company->rho_hedge_key_rate_list.size(); i++)
					{					
					//Up Shock
					econ_res_lookup = hedge_group_name + "|" + company->rho_hedge_key_rate_list[i] + "IntRateUp|" + xstring(time);
					econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

					//Down Shock
					econ_res_lookup = hedge_group_name + "|" + company->rho_hedge_key_rate_list[i] + "IntRateDown|" + xstring(time);
					econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

					greek_index = "RhoConvexity_" + company->rho_hedge_key_rate_list[i] + "_" + xstring(time);
					liab_greeks[greek_index] = econ_res_up + econ_res_down - baseline * 2.0;
					}				
				}
			else//Parallel
				{
				//Up Shock
				econ_res_lookup = hedge_group_name + "|ParallelIntRateUp|" + xstring(time);
				econ_res_up = seg->va_hedge_final_vals[econ_res_lookup];

				//Down Shock
				econ_res_lookup = hedge_group_name + "|ParallelIntRateDown|" + xstring(time);
				econ_res_down = seg->va_hedge_final_vals[econ_res_lookup];

				greek_index = "RhoConvexity_Parallel_" + xstring(time);
				liab_greeks[greek_index] = econ_res_up + econ_res_down - baseline * 2.0;
				}
			}
		}//End of Time Period Loop
	}
//
return;
}



#line 1 "get_hedge_valn_results.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::get_hedge_valn_results(void)
{
if (hedge_valn_final_flag || !valn_flag)
	{
	xstring file_name = xstring(replaceWildcards(valn_hedge_results));

	resize_hedge_valn_array();

	static bool first_time = true;

	if (first_time)
		{
		first_time = false;

		string database_name = working_directory() + "hedge_grp_get_hedge_valn_results.db";
		openDatabase(database_name);
		string table_name = readCsvFile(file_name.getStdStr());

		// Retrieve valuation results
		xstring report_columns = xstring("_pv_claims, _pv_charges");

		xstring sql = (xstring)"SELECT TRIM(_group) AS vgroup, "
					  + (xstring)"CAST(_period AS INTEGER) AS vperiod, "
					  + report_columns
					  + (xstring)" FROM '"
					  + table_name 
		   			  + (xstring)"' WHERE vperiod == 0 ORDER BY vgroup";

		executeQuery(sql.getStdStr(), valn_hedge_input_cols, valn_hedge_input);
		closeDatabase();
		remove(database_name.c_str());

		if (!valn_hedge_input_cols.size())
			{
			throw FatalError("Could not read Hedge valuation file: " 
							  + file_name + " "
							  + "Please check your data.");
			}

		// Create map of group start positions, group is column 0 of query results
		// Strip any leading "|" character
		xstring output_group_name;
		output_group_name = xstring(valn_hedge_input[0][0]);

		if (output_group_name(0, 1) == "|")
			output_group_name = output_group_name(1, output_group_name.length()-1);   

		valn_hedge_input_pos[output_group_name] = 0;

		for (int row = 1; row < valn_hedge_input.size(); row++)
			{
			if (!eq(valn_hedge_input[row][0], valn_hedge_input[row - 1][0]))
				{
				output_group_name = xstring(valn_hedge_input[row][0]);

				if (output_group_name(0, 1) == "|")
					output_group_name = output_group_name(1, output_group_name.length()-1);   

				valn_hedge_input_pos[output_group_name] = row;
				}
			}
		}
	
	xstring group_name;
	group_name = seg_id + "|" + group;
	
	// Find group start position
	int valn_hedge_input_row = 0;
	int valn_hedge_next_input_row = valn_hedge_input.size();	
	if ((valn_hedge_input_pos_iter 
		 = valn_hedge_input_pos.find(group_name)) != valn_hedge_input_pos.end())
		{
		valn_hedge_input_row = valn_hedge_input_pos_iter->second;

		// Determine the number of rows for the group
		deptaskmapiter temp_iter;
		for (temp_iter = valn_hedge_input_pos.begin();
			 temp_iter != valn_hedge_input_pos.end();
			 temp_iter++) 
			 {
			 if (temp_iter->second > valn_hedge_input_row)
				valn_hedge_next_input_row = min(valn_hedge_next_input_row, temp_iter->second);
			 }

		int start_row = valn_hedge_input_row;
		int end_row = valn_hedge_next_input_row;
		int proj_task_loops = 0;

		// Initialize the array values to 0
		hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CLAIMS] = 0.0;
		hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CHARGES] = 0.0;		
		
		for (int row = start_row; row < end_row; row++)
			{
			proj_task_loops += 1;
			hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CLAIMS] += atof(valn_hedge_input[row][2].c_str());
			hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CHARGES] += atof(valn_hedge_input[row][3].c_str());	
			}

		if (proj_task_loops > 0)
			{
			hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CLAIMS] /= proj_task_loops;
			hedge_valn_array[hedge_grp_bucket_id][AVG_PV_CHARGES] /= proj_task_loops;
			}
		}	
	}
return;
}



#line 1 "get_purch_asset_index_name.HDG_GRP_COMP.for"                                                                                   
xstring HDG_GRP_COMP::get_purch_asset_index_name(int seg_num, xstring index_name, xstring hedge_asset_id)
{
if (index_name != "Parallel")
	return index_name;

// else must get index from the purchase asset information
company->sm_inv_strategy[seg_num]->set_asset_defn(HEDGING);

for (int panum = 0; panum < company->sm_inv_strategy[seg_num]->purch_asset_max_num; panum++)
	{
	if (company->sm_inv_strategy[seg_num]->purch_assets_port_defn[panum] == HEDGING)
		{
		xstring purch_assets_id = company->sm_inv_strategy[seg_num]->purch_assets_id[panum];	
		if (purch_assets_id == hedge_grp_delta_hedge_asset_id)
			{
			// Set lookup key
			company->sm_inv_strategy[seg_num]->purch_asset_id = purch_assets_id;

			return company->sm_inv_strategy[seg_num]->inv_strategy->purch_eio_asset_index;
			}
		}
	}

return "Undefined";
}



#line 1 "resize_hedge_valn_array.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::resize_hedge_valn_array(void)
{
 // Size hedge results array
int num_of_shocks = company->hedge_valn_shock_list.size();

if (hedge_valn_array.size() < num_of_shocks)
	{
	// Size first dimension
	hedge_valn_array.resize(num_of_shocks);
	for (int j = 0; j < num_of_shocks; j++)
		{
		// Size third dimension
		hedge_valn_array[j].resize(VALN_RESULTS_SIZE);
	
		for (int m = 0; m < hedge_valn_array[j].size(); m++)
			hedge_valn_array[j][m] = 0.0;
		}	
	}
   return;
}



#line 1 "rho_convex_hedge_strat.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::rho_convex_hedge_strat(int t)
{
double rho_convex_liab = 0.0;
double rho_convex_asset = 0.0;
double rho_convex_asset_max = 0.0;
double rho_convex_asset_min = 0.0;
double rho_convex_tolerance_liab = 0.0;
double rho_convex_tolerance_dollar = 0.0;
double rho_convex_hedge_pct = 0.0;
double rho_convex_asset_purch = 0.0;
double rho_convex_needed = 0.0;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);

// Determine the asset rho convexities for each key rate shock
calc_asset_greeks(t, RHO_CONVEXITY, BEFORE_SALE);

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Rho Convexity Hedge Strategy Setup for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Write detail header
if (hedge_strat_detail_flag)
	seg->SALFile << "KeyRateTermName,RhoConvexLiab,RhoConvexTolPctLiab,RhoConvexTolDollar,RhoConvexAssetMax,RhoConvexAssetMin,RhoConvexAsset,RhoConvexHedgePct,AssetRhoConvexNeeded" << endl;

if (hedge_grp_rho_convex_hedge_liab_shock_defn == PARALLEL)
	{
	// Find the parallel shock from the rho_convex_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->rho_hedge_shock_list.size(); shock_element++)
		{
		xstring shock_string = company->rho_hedge_shock_list[shock_element]; 
		if (shock_string.find("Parallel") < string::npos)
			{
			// Set lookup key
			shock_id = shock_string;
			break;
			}
		}

	if (shock_element == company->rho_hedge_shock_list.size())
		{
		xstring message = xstring("Processing Rho Convexity hedge for parallel shock. ")
		                  + xstring("However, no parallel interest rate shock exists in the hedge shock table. ")
						  + xstring("Please correct your data."); 

		throw FatalError(message);
		}

	// set lookup key
	hedge_grp_key_rate = "Parallel";

	rho_convex_tolerance_liab = hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex;
	rho_convex_tolerance_dollar = hedge_grp_rho_convex_hedge_tolerance_dollar;
	rho_convex_hedge_pct = hedge_grp_rho_convex_hedge_pct;

	xstring liab_greek_map_index = "RhoConvexity_Parallel_" + xstring(t);
	rho_convex_liab = rho_convex_hedge_pct * liab_greeks[liab_greek_map_index];

	if (rho_convex_liab < 0.0)
		{
		rho_convex_asset_max = rho_convex_liab * (1.0 - rho_convex_tolerance_liab) + rho_convex_tolerance_dollar;
		rho_convex_asset_min = rho_convex_liab * (1.0 + rho_convex_tolerance_liab) - rho_convex_tolerance_dollar;
		}
	else
		{
		rho_convex_asset_max = rho_convex_liab * (1.0 + rho_convex_tolerance_liab) + rho_convex_tolerance_dollar;
		rho_convex_asset_min = rho_convex_liab * (1.0 - rho_convex_tolerance_liab) - rho_convex_tolerance_dollar;
		}

	xstring asset_greek_map_index = "RhoConvexity_BefSale_Parallel_" + xstring(t);
	rho_convex_asset = asset_greeks[asset_greek_map_index];

	xstring greek_needed_map = "RhoConvexity_Parallel_" + xstring(t);
	if (rho_convex_asset > rho_convex_asset_max || rho_convex_asset < rho_convex_asset_min)
		asset_greeks_needed[greek_needed_map] = rho_convex_liab; 
	else //Rho Convexity Asset is within tolerance and should remain as is
		asset_greeks_needed[greek_needed_map] = rho_convex_asset;

	if (hedge_strat_detail_flag)
		seg->SALFile << "Parallel," 
			         << rho_convex_liab << ","
					 << rho_convex_tolerance_liab << ","
					 << rho_convex_tolerance_dollar << ","
					 << rho_convex_asset_max << ","
					 << rho_convex_asset_min << ","
					 << rho_convex_asset << ","
					 << rho_convex_hedge_pct << ","
					 << asset_greeks_needed[greek_needed_map] << endl;
	}
else // hedge_grp_rho_convex_hedge_liab_shock_defn == KEY_RATE_SPECIFIC
	{
	for (int key_rate = 0; key_rate < company->rho_hedge_key_rate_list.size(); key_rate++)
		{
		hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

		// Find the interest rate shock from the rho_hedge_shock_list
		// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
		int shock_element;
		for (shock_element = 0; shock_element < company->rho_hedge_shock_list.size(); shock_element++)
			{
			xstring shock_string = company->rho_hedge_shock_list[shock_element]; 
			if (shock_string.find(hedge_grp_key_rate) < string::npos)
				{
				// Set lookup key
				shock_id = shock_string;
				break;
				}
			}

		if (shock_element == company->rho_hedge_shock_list.size())
			{
			xstring message = "Processing Rho Convexity hedge for key rate shock " + hedge_grp_key_rate + ". "
			                  + xstring("However, no shock exist for this key rate in the hedge shock table. ")
							  + xstring("Please correct your data.");

			throw FatalError(message);
			}

		rho_convex_tolerance_liab = hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex;
		rho_convex_tolerance_dollar = hedge_grp_rho_convex_hedge_tolerance_dollar;
		rho_convex_hedge_pct = hedge_grp_rho_convex_hedge_pct;

		xstring liab_greek_map_index = "RhoConvexity_" + hedge_grp_key_rate + "_" + xstring(t);
		rho_convex_liab = rho_convex_hedge_pct * liab_greeks[liab_greek_map_index];

		if (rho_convex_liab < 0.0)
			{
			rho_convex_asset_max = rho_convex_liab * (1.0 - rho_convex_tolerance_liab) + rho_convex_tolerance_dollar;
			rho_convex_asset_min = rho_convex_liab * (1.0 + rho_convex_tolerance_liab) - rho_convex_tolerance_dollar;
			}
		else
			{
			rho_convex_asset_max = rho_convex_liab * (1.0 + rho_convex_tolerance_liab) + rho_convex_tolerance_dollar;
			rho_convex_asset_min = rho_convex_liab * (1.0 - rho_convex_tolerance_liab) - rho_convex_tolerance_dollar;
			}

		xstring asset_greek_map_index = "RhoConvexity_BefSale_" + hedge_grp_key_rate + "_" + xstring(t);
		rho_convex_asset = asset_greeks[asset_greek_map_index];

		xstring greek_needed_map = "RhoConvexity_" + hedge_grp_key_rate + "_" + xstring(t);
		if (rho_convex_asset > rho_convex_asset_max || rho_convex_asset < rho_convex_asset_min)
			asset_greeks_needed[greek_needed_map] = rho_convex_liab; 
		else //Rho Convexity Asset is within tolerance and should remain as is
			asset_greeks_needed[greek_needed_map] = rho_convex_asset;

		if (hedge_strat_detail_flag)
			seg->SALFile << hedge_grp_key_rate << "," 
						 << rho_convex_liab << ","
						 << rho_convex_tolerance_liab << ","
						 << rho_convex_tolerance_dollar << ","
						 << rho_convex_asset_max << ","
						 << rho_convex_asset_min << ","
						 << rho_convex_asset << ","
						 << rho_convex_hedge_pct << ","
						 << asset_greeks_needed[greek_needed_map] << endl;
		}
	}
return;
}



#line 1 "rho_hedge_strat.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::rho_hedge_strat(int t)
{
double rho_liab = 0.0;
double rho_asset = 0.0;
double rho_asset_max = 0.0;
double rho_asset_min = 0.0;
double rho_tolerance_liab = 0.0;
double rho_tolerance_dollar = 0.0;
double rho_hedge_pct = 0.0;
double rho_asset_purch = 0.0;
double rho_needed = 0.0;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);

// Determine the asset rhos for each index
calc_asset_greeks(t, RHO, BEFORE_SALE);

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Rho Hedge Strategy Setup for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Write detail header
if (hedge_strat_detail_flag)
	seg->SALFile << "KeyRateTermName,RhoLiab,RhoTolPctLiab,RhoTolDollar,RhoAssetMax,RhoAssetMin,RhoAsset,RhoHedgePct,AssetRhoNeeded" << endl;

if (hedge_grp_rho_hedge_liab_shock_defn == PARALLEL)
	{
	// Find the parallel shock from the rho_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->rho_hedge_shock_list.size(); shock_element++)
		{
		xstring shock_string = company->rho_hedge_shock_list[shock_element]; 
		if (shock_string.find("Parallel") < string::npos)
			{
			// Set lookup key
			shock_id = shock_string;
			break;
			}
		}

	if (shock_element == company->rho_hedge_shock_list.size())
		{
		xstring message = xstring("Processing Rho hedge for parallel shock. ")
		                  + xstring("However, no parallel interest rate shock exists in the hedge shock table. ")
						  + xstring("Please correct your data."); 

		throw FatalError(message);
		}

	// set lookup key
	hedge_grp_key_rate = "Parallel";

	rho_tolerance_liab = hedge_grp_rho_hedge_tolerance_pct_liab_rho;
	rho_tolerance_dollar = hedge_grp_rho_hedge_tolerance_dollar;
	rho_hedge_pct = hedge_grp_rho_hedge_pct;

	xstring liab_greek_map_index = "Rho_Parallel_" + xstring(t);
	rho_liab = rho_hedge_pct * liab_greeks[liab_greek_map_index];

	if (rho_liab < 0.0)
		{
		rho_asset_max = rho_liab * (1.0 - rho_tolerance_liab) + rho_tolerance_dollar;
		rho_asset_min = rho_liab * (1.0 + rho_tolerance_liab) - rho_tolerance_dollar;
		}
	else
		{
		rho_asset_max = rho_liab * (1.0 + rho_tolerance_liab) + rho_tolerance_dollar;
		rho_asset_min = rho_liab * (1.0 - rho_tolerance_liab) - rho_tolerance_dollar;
		}

	xstring asset_greek_map_index = "Rho_BefSale_Parallel_" + xstring(t);
	rho_asset = asset_greeks[asset_greek_map_index];

	xstring greek_needed_map = "Rho_Parallel_" + xstring(t);
	if (rho_asset > rho_asset_max || rho_asset < rho_asset_min)
		asset_greeks_needed[greek_needed_map] = rho_liab; 
	else //Rho Asset is within tolerance and should remain as is
		asset_greeks_needed[greek_needed_map] = rho_asset;

	if (hedge_strat_detail_flag)
		seg->SALFile << "Parallel," 
			         << rho_liab << ","
					 << rho_tolerance_liab << ","
					 << rho_tolerance_dollar << ","
					 << rho_asset_max << ","
					 << rho_asset_min << ","
					 << rho_asset << ","
					 << rho_hedge_pct << ","
					 << asset_greeks_needed[greek_needed_map] << endl;
	}
else // hedge_grp_rho_hedge_liab_shock_defn == KEY_RATE_SPECIFIC
	{
	for (int key_rate = 0; key_rate < company->rho_hedge_key_rate_list.size(); key_rate++)
		{
		hedge_grp_key_rate = company->rho_hedge_key_rate_list[key_rate];

		// Find the interest rate shock from the rho_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->rho_hedge_shock_list.size(); shock_element++)
			{
			xstring shock_string = company->rho_hedge_shock_list[shock_element]; 
			if (shock_string.find(hedge_grp_key_rate) < string::npos)
				{
				// Set lookup key
				shock_id = shock_string;
				break;
				}
			}

		if (shock_element == company->rho_hedge_shock_list.size())
			{
			xstring message = "Processing Rho hedge for key rate shock " + hedge_grp_key_rate + ". "
			                  + xstring("However, no shock exist for this key rate in the hedge shock table. ")
							  + xstring("Please correct your data.");

			throw FatalError(message);
			}

		rho_tolerance_liab = hedge_grp_rho_hedge_tolerance_pct_liab_rho;
		rho_tolerance_dollar = hedge_grp_rho_hedge_tolerance_dollar;
		rho_hedge_pct = hedge_grp_rho_hedge_pct;

		xstring liab_greek_map_index = "Rho_" + hedge_grp_key_rate + "_" + xstring(t);
		rho_liab = rho_hedge_pct * liab_greeks[liab_greek_map_index];

		if (rho_liab < 0.0)
			{
			rho_asset_max = rho_liab * (1.0 - rho_tolerance_liab) + rho_tolerance_dollar;
			rho_asset_min = rho_liab * (1.0 + rho_tolerance_liab) - rho_tolerance_dollar;
			}
		else
			{
			rho_asset_max = rho_liab * (1.0 + rho_tolerance_liab) + rho_tolerance_dollar;
			rho_asset_min = rho_liab * (1.0 - rho_tolerance_liab) - rho_tolerance_dollar;
			}

		xstring asset_greek_map_index = "Rho_BefSale_" + hedge_grp_key_rate + "_" + xstring(t);
		rho_asset = asset_greeks[asset_greek_map_index];

		xstring greek_needed_map = "Rho_" + hedge_grp_key_rate + "_" + xstring(t);
		if (rho_asset > rho_asset_max || rho_asset < rho_asset_min)
			asset_greeks_needed[greek_needed_map] = rho_liab; 
		else //Rho Asset is within tolerance and should remain as is
			asset_greeks_needed[greek_needed_map] = rho_asset;

		if (hedge_strat_detail_flag)
			seg->SALFile << hedge_grp_key_rate << ","
						 << rho_liab << ","
						 << rho_tolerance_liab << ","
						 << rho_tolerance_dollar << ","
						 << rho_asset_max << ","
						 << rho_asset_min << ","
						 << rho_asset << ","
						 << rho_hedge_pct << ","
						 << asset_greeks_needed[greek_needed_map] << endl;
		}
	}
return;
}



#line 1 "sum_over_assets.HDG_GRP_COMP.for"                                                                                   
double HDG_GRP_COMP::sum_over_assets(const xstring &colname, int t, int greek_type, int sum_over_timing)
{
// The following table lists valid greek_type values.  
//   = DELTA           for delta  hedge assets
//   = GAMMA           for gamma  hedge assets
//   = VEGA            for vega  hedge assets
//   = RHO             for rho  hedge assets
//   = RHO_CONVEXITY   for rho convexity hedge assets
//   = SUM_OVER_ALL	   for all hedge assets

double total = 0.0;
double col_val = 0.0;
int colnum = 0;
int mp = 0;
xstring greek_type_string;
mpmap::iterator mp_map_iter;

// ensure order of asset processing
if (sum_over_timing >= BEFORE_SALE && t > start_period)
	{
	hedge_mkt_val(t - 1);
	hedge_inv_amt_bom(t);
	}

if (sum_over_timing >= END_OF_PERIOD)
	{
	hedge_sale_amt(t);
	hedge_inv_amt_eom(t);
	}

if (greek_type != SUM_OVER_ALL)
	{
	if (greek_type == DELTA)
		greek_type_string = "|Delta|";
	else if (greek_type == RHO)
		greek_type_string = "|Rho|";
	else if (greek_type == RHO_CONVEXITY)
		greek_type_string = "|RhoConvexity|";
	else if (greek_type == GAMMA)
		greek_type_string = "|Gamma|";
	else if (greek_type == VEGA)
		greek_type_string = "|Vega|";
	else
		throw FatalError("Invalid 'greek_type' passed to 'sum_over_assets(hedge_grp_comp)' function.");
	}

#if defined(__EIO_ASSET_H_)
EIO_ASSET *eio_element = NULL;
if (eio_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_eio[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = eio_mp_map_active.begin();
			 mp_map_iter != eio_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			eio_element = company->sm_asset->sm_eio[mp];

			if (t < eio_element->commencement_period
				|| (t == eio_element->commencement_period
					&& eio_element->purchased_bom_flag)
				|| (t > max(0, eio_element->commencement_period)
					&& fabs(eio_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if (greek_type != SUM_OVER_ALL && eio_element->hdg_grp_code.find(greek_type_string) == string::npos)
				continue;
					
			col_val = eio_element->Column(colnum).Value(t);
			col_val *= eio_element->pct_to_use;

			total += col_val;
			}			         
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
IRD_ASSET *ird_element = NULL;
if (ird_mp_map_active.size() > 0)
	{
	colnum = company->sm_asset->sm_ird[0]->Column(colname).Number();
	if (colnum >= 0)
		{
		for (mp_map_iter = ird_mp_map_active.begin();
			 mp_map_iter != ird_mp_map_active.end();
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;
			ird_element = company->sm_asset->sm_ird[mp];

			if (t < ird_element->commencement_period
				|| (t > max(0, ird_element->commencement_period)
					&& fabs(ird_element->notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD))
				continue;

			if (greek_type != SUM_OVER_ALL && ird_element->hdg_grp_code.find(greek_type_string) == string::npos)
				continue;

			col_val = ird_element->Column(colnum).Value(t);
			col_val *= ird_element->pct_to_use;

			total += col_val;
			}			         
		}
	}
#endif
	 
return total;
}



#line 1 "sum_over_liabilities.HDG_GRP_COMP.for"                                                                                   
double HDG_GRP_COMP::sum_over_liabilities(const xstring &colname, int t, int sum_timing)
{ 
double total = 0.0;
int mp = 0;
int colnum = 0;
mpmap::iterator mp_map_iter;

#if defined(__FIA_LIAB_H_)
if (seg->fia_mp_map.size())
	{
	FIA_LIAB *current_fia_element;
	colnum = liab->sm_fia[0]->sm_fia_account[0]->Column(colname).Number();	

	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->fia_mp_map.begin();
		     mp_map_iter != seg->fia_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_fia_element = liab->sm_fia[mp];

			if (t < current_fia_element->commencement_period
				|| t > current_fia_element->maturity_period)
				continue;

			// Skip new issue commencement period
			if (current_fia_element->elapsed_mths <= 0
				&& t == current_fia_element->commencement_period)
				continue;

			if (t != current_fia_element->commencement_period
				&& fabs(current_fia_element->policies_b(t)) < rate_ratio_threshold)
				continue;
			
			for (int account = 0; account < current_fia_element->sm_fia_account.size(); account++)
				{
				if (current_fia_element->sm_fia_account[account]->hedge_grp_code == hedge_grp_id)
					total += current_fia_element->sm_fia_account[account]->Column(colnum).Value(t);
				}
			}
		}
	}
#endif

#if defined(__IUL_LIAB_H_)
double units_basis = 0.0;

if (seg->iul_mp_map.size())
	{
	IUL_LIAB *current_iul_element;
	colnum = liab->sm_iul[0]->sm_iul_account[0][0]->Column(colname).Number();	

	int bucket_num = getElementNumber(1);
	xstring bucket_str = (bucket_num < 10) ? "0" + xstring(bucket_num) : xstring(bucket_num);
	xstring hedge_grp_code = hedge_grp_id + "|Bucket_" + bucket_str;

	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->iul_mp_map.begin();
		     mp_map_iter != seg->iul_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_iul_element = liab->sm_iul[mp];

			if (t < current_iul_element->commencement_period
				|| t > current_iul_element->maturity_period)
				continue;

			// Skip new issues commencement period
			if (current_iul_element->commencement_period >= 0
				&& t == current_iul_element->commencement_period)
				continue;

			if (t > current_iul_element->start_period
				&& fabs(current_iul_element->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (sum_timing == BEG_OF_PERIOD)
				units_basis = current_iul_element->units_inf(t - 1);
			else
				units_basis = current_iul_element->units_inf(t);
			
			for (int account = 0; account < current_iul_element->sm_iul_account.size(); account++)
				{
				for (int bucket = 0; bucket < current_iul_element->sm_iul_account[account].size(); bucket++)
					{
					// amounts from iul account buckets are "per unit"
					// validate that bucket is linked to hedge group
					if (current_iul_element->sm_iul_account[account][bucket]->hedge_grp_code == hedge_grp_code)
						{
						total += current_iul_element->sm_iul_account[account][bucket]->Column(colnum).Value(t)
								 * units_basis;
						}
					}
				}
			}
		}
	}
#endif

#if defined(__VA_LIAB_H_)
if (seg->va_mp_map.size())
	{
	VA_LIAB *current_va_element;
	colnum = liab->sm_va[0]->Column(colname).Number();	

	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->va_mp_map.begin();
		     mp_map_iter != seg->va_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_va_element = liab->sm_va[mp];

			if (t < current_va_element->commencement_period
				|| t > current_va_element->maturity_period)
				continue;

			// Skip new issue commencement period
			if (current_va_element->elapsed_mths <= 0
				&& t == current_va_element->commencement_period)
				continue;

			if (t != current_va_element->commencement_period
				&& fabs(current_va_element->policies_b(t)) < rate_ratio_threshold)
				continue;

			if (hedge_grp_plan_codes == "ALL" || hedge_grp_plan_codes.find(current_va_element->plan_code) < string::npos)
				{
				if (hedge_grp_gmab_defn == YES && current_va_element->gmab_ind && colname.find("gmab") < string::npos)
					total += current_va_element->Column(colnum).Value(t);
				else if (hedge_grp_gmdb_defn == YES && current_va_element->gmdb_ind && colname.find("gmdb") < string::npos)
					total += current_va_element->Column(colnum).Value(t);
				else if (hedge_grp_gmib_defn == YES && current_va_element->gmib_ind && colname.find("gmib") < string::npos)
					total += current_va_element->Column(colnum).Value(t);
				else if (hedge_grp_gmwb_defn == YES && current_va_element->gmwb_ind && colname.find("gmwb") < string::npos)
					total += current_va_element->Column(colnum).Value(t);
				else
					continue;
				}
			else
				continue;			
			}
		}
	}
#endif

return total;
}



#line 1 "vega_hedge_strat.HDG_GRP_COMP.for"                                                                                   
void HDG_GRP_COMP::vega_hedge_strat(int t)
{
double vega_liab = 0.0;
double vega_asset = 0.0;
double vega_asset_max = 0.0;
double vega_asset_min = 0.0;
double vega_tolerance_liab = 0.0;
double vega_tolerance_dollar = 0.0;
double vega_hedge_pct = 0.0;
double vega_asset_purch = 0.0;
double vega_needed = 0.0;
bool hedge_strat_detail_flag = asset->asset_detail_rpt_inv_strat_flag(t);

// Determine the asset vegas for each index
calc_asset_greeks(t, VEGA, BEFORE_SALE);

if (hedge_strat_detail_flag)
	{
	seg->SALFile << endl;
	seg->SALFile << "Vega Hedge Strategy Setup for "
				 << "Hedge Group=" << hedge_grp_id << " " 
	             << "Period=" << t << " "
				 << "Year=" << xint(cal_yr(t)) << " "
				 << "Month=" << xint(cal_mth(t)) << endl;
	}

// Write detail header
if (hedge_strat_detail_flag)
	seg->SALFile << "IndexName,IndexTermName,VegaLiab,VegaTolPctLiab,VegaTolDollar,VegaAssetMax,VegaAssetMin,VegaAsset,VegaHedgePct,AssetVegaNeeded" << endl;

if (hedge_grp_gamma_vega_hedge_liab_shock_defn == PARALLEL)
	{
	// Find the parallel shock from the vega_hedge_shock_list
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int shock_element;
	for (shock_element = 0; shock_element < company->vega_hedge_shock_list.size(); shock_element++)
		{
		xstring shock_string = company->vega_hedge_shock_list[shock_element]; 
		if (shock_string.find("Parallel") < string::npos)
			{
			// Set lookup key
			shock_id = shock_string;
			break;
			}
		}

	if (shock_element == company->vega_hedge_shock_list.size())
		{
		xstring message = xstring("Processing Vega hedge for parallel all terms volatility shock. ")
		                  + xstring("However, no parallel all terms volatility shock exists in the hedge shock table. ")
						  + xstring("Please correct your data."); 

		throw FatalError(message);
		}

	// set lookup keys
	hedge_grp_index_name = "Parallel";
	hedge_grp_index_term = "AllTerms";

	vega_tolerance_liab = hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
	vega_tolerance_dollar = hedge_grp_gamma_vega_hedge_tolerance_dollar;
	vega_hedge_pct = hedge_grp_gamma_vega_hedge_pct;

	xstring liab_greek_map_index = "Vega_Parallel_AllTerms_" + xstring(t);
	vega_liab = vega_hedge_pct * liab_greeks[liab_greek_map_index];

	if (vega_liab < 0.0)
		{
		vega_asset_max = vega_liab * (1.0 - vega_tolerance_liab) + vega_tolerance_dollar;
		vega_asset_min = vega_liab * (1.0 + vega_tolerance_liab) - vega_tolerance_dollar;
		}
	else
		{
		vega_asset_max = vega_liab * (1.0 + vega_tolerance_liab) + vega_tolerance_dollar;
		vega_asset_min = vega_liab * (1.0 - vega_tolerance_liab) - vega_tolerance_dollar;
		}

	xstring asset_greek_map_index = "Vega_BefSale_Parallel_" + xstring(t);
	vega_asset = asset_greeks[asset_greek_map_index];

	xstring greek_needed_map = "Vega_Parallel_" + xstring(t);
	if (vega_asset > vega_asset_max || vega_asset < vega_asset_min)
		asset_greeks_needed[greek_needed_map] = vega_liab; 
	else //Vega Asset is within tolerance and should remain as is
		asset_greeks_needed[greek_needed_map] = vega_asset; 

	if (hedge_strat_detail_flag)
		seg->SALFile << "Parallel,AllTerms" 
			         << vega_liab << ","
					 << vega_tolerance_liab << ","
					 << vega_tolerance_dollar << ","
					 << vega_asset_max << ","
					 << vega_asset_min << ","
					 << vega_asset << ","
					 << vega_hedge_pct << ","
					 << asset_greeks_needed[greek_needed_map] << endl;
	}
else if (hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_SPECIFIC)
	{
	for (int index = 0; index < company->vega_hedge_index_list.size(); index++)
		{
		xstring index_name = company->vega_hedge_index_list[index];

		// Find the index shock from the vega_hedge_shock_list
		// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
		int shock_element;
		for (shock_element = 0; shock_element < company->vega_hedge_shock_list.size(); shock_element++)
			{
			xstring shock_string = company->vega_hedge_shock_list[shock_element]; 
			xstring search_string = index_name + "EqtVolAllTerms";
			if (shock_string.find(search_string) < string::npos)
				{
				// Set lookup key
				shock_id = shock_string;
				break;
				}
			}

		if (shock_element == company->vega_hedge_shock_list.size())
			{
			xstring message = "Processing Vega hedge for " + index_name + " AllTerms volatility shock. "
			                  + xstring("However, no volatility shock exists for this index and term combination in the hedge shock table. ")
							  + xstring("Please correct your data.");

			throw FatalError(message);
			}

		// set lookup keys
		hedge_grp_index_name = company->vega_hedge_index_list[index];
		hedge_grp_index_term = "AllTerms";

		vega_tolerance_liab = hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
		vega_tolerance_dollar = hedge_grp_gamma_vega_hedge_tolerance_dollar;
		vega_hedge_pct = hedge_grp_gamma_vega_hedge_pct;

		xstring liab_greek_map_index = "Vega_" + hedge_grp_index_name + "_AllTerms_" + xstring(t);
		vega_liab = vega_hedge_pct * liab_greeks[liab_greek_map_index];

		if (vega_liab < 0.0)
			{
			vega_asset_max = vega_liab * (1.0 - vega_tolerance_liab) + vega_tolerance_dollar;
			vega_asset_min = vega_liab * (1.0 + vega_tolerance_liab) - vega_tolerance_dollar;
			}
		else
			{
			vega_asset_max = vega_liab * (1.0 + vega_tolerance_liab) + vega_tolerance_dollar;
			vega_asset_min = vega_liab * (1.0 - vega_tolerance_liab) - vega_tolerance_dollar;
			}

		xstring asset_greek_map_index = "Vega_BefSale_" + hedge_grp_index_name + "_AllTerms_" + xstring(t);
		vega_asset = asset_greeks[asset_greek_map_index];

		xstring greek_needed_map = "Vega_" + hedge_grp_index_name + "_AllTerms_" + xstring(t);
		if (vega_asset > vega_asset_max || vega_asset < vega_asset_min)
			asset_greeks_needed[greek_needed_map] = vega_liab; 
		else //Vega Asset is within tolerance and should remain as is
			asset_greeks_needed[greek_needed_map] = vega_asset; 

		if (hedge_strat_detail_flag)
			seg->SALFile << hedge_grp_index_name << ","
						 << "AllTerms," 
						 << vega_liab << ","
						 << vega_tolerance_liab << ","
						 << vega_tolerance_dollar << ","
						 << vega_asset_max << ","
						 << vega_asset_min << ","
						 << vega_asset << ","
						 << vega_hedge_pct << ","
						 << asset_greeks_needed[greek_needed_map] << endl;
		}
	}
else // hedge_grp_gamma_vega_hedge_liab_shock_defn == INDEX_TERM_SPECIFIC
	{
	for (int index = 0; index < company->vega_hedge_index_list.size(); index++)
		{
		xstring index_name = company->vega_hedge_index_list[index];

		for (int index_term = 0; index_term < company->vega_hedge_term_list.size(); index_term++)
			{
			xstring index_term_name = company->vega_hedge_term_list[index_term];

			// Skip the AllTerms index name
			if (index_term_name == "AllTerms")
				continue;

			// Find the index and term shock from the vega_hedge_shock_list
			// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
			int shock_element;
			for (shock_element = 0; shock_element < company->vega_hedge_shock_list.size(); shock_element++)
				{
				xstring shock_string = company->vega_hedge_shock_list[shock_element]; 
				xstring search_string = index_name + "EqtVol" + index_term_name;
				if (shock_string.find(search_string) < string::npos)
					{
					// Set lookup key
					shock_id = shock_string;
					break;
					}
				}

			if (shock_element == company->vega_hedge_shock_list.size())
				{
				xstring message = "Processing Vega hedge for " + index_name + " " + index_term_name + " volatility shock. "
								  + xstring("However, no shock exists for this index and term combination in the hedge shock table. ")
								  + xstring("Please correct your data.");

				throw FatalError(message);
				}

			// set lookup keys
			hedge_grp_index_name = company->vega_hedge_index_list[index];
			hedge_grp_index_term = company->vega_hedge_term_list[index_term];

			vega_tolerance_liab = hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
			vega_tolerance_dollar = hedge_grp_gamma_vega_hedge_tolerance_dollar;
			vega_hedge_pct = hedge_grp_gamma_vega_hedge_pct;

			xstring liab_greek_map_index = "Vega_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
			vega_liab = vega_hedge_pct * liab_greeks[liab_greek_map_index];

			if (vega_liab < 0.0)
				{
				vega_asset_max = vega_liab * (1.0 - vega_tolerance_liab) + vega_tolerance_dollar;
				vega_asset_min = vega_liab * (1.0 + vega_tolerance_liab) - vega_tolerance_dollar;
				}
			else
				{
				vega_asset_max = vega_liab * (1.0 + vega_tolerance_liab) + vega_tolerance_dollar;
				vega_asset_min = vega_liab * (1.0 - vega_tolerance_liab) - vega_tolerance_dollar;
				}

			xstring asset_greek_map_index = "Vega_BefSale_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
			vega_asset = asset_greeks[asset_greek_map_index];

			xstring greek_needed_map = "Vega_" + hedge_grp_index_name + "_" + hedge_grp_index_term + "_" + xstring(t);
			if (vega_asset > vega_asset_max || vega_asset < vega_asset_min)
				asset_greeks_needed[greek_needed_map] = vega_liab; 
			else //Vega Asset is within tolerance and should remain as is
				asset_greeks_needed[greek_needed_map] = vega_asset; 

			if (hedge_strat_detail_flag)
				seg->SALFile << hedge_grp_index_name << ","
							 << hedge_grp_index_term << ","
							 << vega_liab << ","
							 << vega_tolerance_liab << ","
							 << vega_tolerance_dollar << ","
							 << vega_asset_max << ","
							 << vega_asset_min << ","
							 << vega_asset << ","
							 << vega_hedge_pct << ","
							 << asset_greeks_needed[greek_needed_map] << endl;
			}
		}
	}

return;
}



	static HDG_GRP_COMP_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (HDG_GRP_COMP_UDF::*dPXi) (int);
typedef double (HDG_GRP_COMP_UDF::*dPXid) (int, double);
typedef double (HDG_GRP_COMP_UDF::*dPF) ();
typedef double (HDG_GRP_COMP_UDF::*dPFd) (double);
typedef int (HDG_GRP_COMP_UDF::*iPF) ();
typedef int (HDG_GRP_COMP_UDF::*iPFi) (int);
typedef xstring (HDG_GRP_COMP_UDF::*sPF) ();
typedef xstring (HDG_GRP_COMP_UDF::*sPFs) (xstring);

const CashFlowCommonData HDG_GRP_COMP::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "cal_mth", "hdg_grp_comp_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(2, "cal_yr", "hdg_grp_comp_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(3, "cal_yr_relative", "hdg_grp_comp_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(4, "cap_rate", "hdg_grp_comp_cap_rate",  "cap_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_cap_rate, 'E','N', '3', 'P', (size_t)&modelOffset->cap_rate),
	CashFlowCommonData(5, "delta_hedge_flag", "hdg_grp_comp_delta_hedge_flag",  "delta_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_flag),
	CashFlowCommonData(6, "delta_hedge_inv_amt", "hdg_grp_comp_delta_hedge_inv_amt",  "delta_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_inv_amt),
	CashFlowCommonData(7, "delta_hedge_mkt_val", "hdg_grp_comp_delta_hedge_mkt_val",  "delta_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->delta_hedge_mkt_val),
	CashFlowCommonData(8, "delta_hedge_mkt_val_incr", "hdg_grp_comp_delta_hedge_mkt_val_incr",  "delta_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_mkt_val_incr),
	CashFlowCommonData(9, "delta_hedge_pmt", "hdg_grp_comp_delta_hedge_pmt",  "delta_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_pmt),
	CashFlowCommonData(10, "delta_hedge_prof", "hdg_grp_comp_delta_hedge_prof",  "delta_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_prof),
	CashFlowCommonData(11, "delta_hedge_sale_amt", "hdg_grp_comp_delta_hedge_sale_amt",  "delta_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_sale_amt),
	CashFlowCommonData(12, "delta_hedge_transaction_cost", "hdg_grp_comp_delta_hedge_transaction_cost",  "delta_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_transaction_cost),
	CashFlowCommonData(13, "delta_index_1", "hdg_grp_comp_delta_index_1",  "delta_index_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_1, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_1),
	CashFlowCommonData(14, "delta_index_2", "hdg_grp_comp_delta_index_2",  "delta_index_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_2, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_2),
	CashFlowCommonData(15, "delta_index_3", "hdg_grp_comp_delta_index_3",  "delta_index_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_3, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_3),
	CashFlowCommonData(16, "delta_index_4", "hdg_grp_comp_delta_index_4",  "delta_index_4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_4, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_4),
	CashFlowCommonData(17, "delta_index_5", "hdg_grp_comp_delta_index_5",  "delta_index_5",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_5, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_5),
	CashFlowCommonData(18, "delta_index_6", "hdg_grp_comp_delta_index_6",  "delta_index_6",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_index_6, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_index_6),
	CashFlowCommonData(19, "delta_parallel", "hdg_grp_comp_delta_parallel",  "delta_parallel",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_delta_parallel, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_parallel),
	CashFlowCommonData(20, "econ_cash", "hdg_grp_comp_econ_cash",  "econ_cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash, 'E','N', '3', 'P', (size_t)&modelOffset->econ_cash),
	CashFlowCommonData(21, "econ_cash_int", "hdg_grp_comp_econ_cash_int",  "econ_cash_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash_int, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_cash_int),
	CashFlowCommonData(22, "econ_cash_int_rate", "hdg_grp_comp_econ_cash_int_rate",  "econ_cash_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_cash_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->econ_cash_int_rate),
	CashFlowCommonData(23, "econ_prof", "hdg_grp_comp_econ_prof",  "econ_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_prof),
	CashFlowCommonData(24, "econ_prof_unhedged", "hdg_grp_comp_econ_prof_unhedged",  "econ_prof_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_prof_unhedged, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_prof_unhedged),
	CashFlowCommonData(25, "econ_res", "hdg_grp_comp_econ_res",  "econ_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res, 'E','N', '3', 'P', (size_t)&modelOffset->econ_res),
	CashFlowCommonData(26, "econ_res_incr", "hdg_grp_comp_econ_res_incr",  "econ_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res_incr, 'E','N', '3', 'P', (size_t)&modelOffset->econ_res_incr),
	CashFlowCommonData(27, "econ_res_int", "hdg_grp_comp_econ_res_int",  "econ_res_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_econ_res_int, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_res_int),
	CashFlowCommonData(28, "finalize", "hdg_grp_comp_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(29, "fund_val_decrem", "hdg_grp_comp_fund_val_decrem",  "fund_val_decrem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_decrem, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_decrem),
	CashFlowCommonData(30, "fund_val_decrem_cumul", "hdg_grp_comp_fund_val_decrem_cumul",  "fund_val_decrem_cumul",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_decrem_cumul, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_decrem_cumul),
	CashFlowCommonData(31, "fund_val_fixed", "hdg_grp_comp_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_fund_val_fixed, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(32, "gamma_hedge_flag", "hdg_grp_comp_gamma_hedge_flag",  "gamma_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_flag),
	CashFlowCommonData(33, "gamma_hedge_inv_amt", "hdg_grp_comp_gamma_hedge_inv_amt",  "gamma_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_inv_amt),
	CashFlowCommonData(34, "gamma_hedge_mkt_val", "hdg_grp_comp_gamma_hedge_mkt_val",  "gamma_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->gamma_hedge_mkt_val),
	CashFlowCommonData(35, "gamma_hedge_mkt_val_incr", "hdg_grp_comp_gamma_hedge_mkt_val_incr",  "gamma_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_mkt_val_incr),
	CashFlowCommonData(36, "gamma_hedge_pmt", "hdg_grp_comp_gamma_hedge_pmt",  "gamma_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_pmt),
	CashFlowCommonData(37, "gamma_hedge_prof", "hdg_grp_comp_gamma_hedge_prof",  "gamma_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_prof),
	CashFlowCommonData(38, "gamma_hedge_sale_amt", "hdg_grp_comp_gamma_hedge_sale_amt",  "gamma_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_sale_amt),
	CashFlowCommonData(39, "gamma_hedge_transaction_cost", "hdg_grp_comp_gamma_hedge_transaction_cost",  "gamma_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_transaction_cost),
	CashFlowCommonData(40, "gamma_index_1", "hdg_grp_comp_gamma_index_1",  "gamma_index_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_1, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_1),
	CashFlowCommonData(41, "gamma_index_2", "hdg_grp_comp_gamma_index_2",  "gamma_index_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_2, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_2),
	CashFlowCommonData(42, "gamma_index_3", "hdg_grp_comp_gamma_index_3",  "gamma_index_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_3, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_3),
	CashFlowCommonData(43, "gamma_index_4", "hdg_grp_comp_gamma_index_4",  "gamma_index_4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_4, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_4),
	CashFlowCommonData(44, "gamma_index_5", "hdg_grp_comp_gamma_index_5",  "gamma_index_5",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_5, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_5),
	CashFlowCommonData(45, "gamma_index_6", "hdg_grp_comp_gamma_index_6",  "gamma_index_6",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_index_6, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_index_6),
	CashFlowCommonData(46, "gamma_parallel", "hdg_grp_comp_gamma_parallel",  "gamma_parallel",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_parallel, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_parallel),
	CashFlowCommonData(47, "gamma_vega_hedge_flag", "hdg_grp_comp_gamma_vega_hedge_flag",  "gamma_vega_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_gamma_vega_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_vega_hedge_flag),
	CashFlowCommonData(48, "hedge_cash_flow", "hdg_grp_comp_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(49, "hedge_cost_charge", "hdg_grp_comp_hedge_cost_charge",  "hedge_cost_charge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_cost_charge, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost_charge),
	CashFlowCommonData(50, "hedge_exp", "hdg_grp_comp_hedge_exp",  "hedge_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_exp),
	CashFlowCommonData(51, "hedge_int_pmt", "hdg_grp_comp_hedge_int_pmt",  "hedge_int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_int_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_int_pmt),
	CashFlowCommonData(52, "hedge_inv_amt_bom", "hdg_grp_comp_hedge_inv_amt_bom",  "hedge_inv_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_inv_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_bom),
	CashFlowCommonData(53, "hedge_inv_amt_eom", "hdg_grp_comp_hedge_inv_amt_eom",  "hedge_inv_amt_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_inv_amt_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_eom),
	CashFlowCommonData(54, "hedge_liab_claims", "hdg_grp_comp_hedge_liab_claims",  "hedge_liab_claims",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_liab_claims, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_liab_claims),
	CashFlowCommonData(55, "hedge_mkt_val", "hdg_grp_comp_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(56, "hedge_notional_amt", "hdg_grp_comp_hedge_notional_amt",  "hedge_notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_notional_amt, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_notional_amt),
	CashFlowCommonData(57, "hedge_notional_amt_available", "hdg_grp_comp_hedge_notional_amt_available",  "hedge_notional_amt_available",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_notional_amt_available, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_notional_amt_available),
	CashFlowCommonData(58, "hedge_opt_pmt", "hdg_grp_comp_hedge_opt_pmt",  "hedge_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_opt_pmt),
	CashFlowCommonData(59, "hedge_sale_amt", "hdg_grp_comp_hedge_sale_amt",  "hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt),
	CashFlowCommonData(60, "index_val", "hdg_grp_comp_index_val",  "index_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_index_val, 'E','N', '3', 'P', (size_t)&modelOffset->index_val),
	CashFlowCommonData(61, "initialize", "hdg_grp_comp_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(62, "liab_cash_flow_bom", "hdg_grp_comp_liab_cash_flow_bom",  "liab_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_liab_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->liab_cash_flow_bom),
	CashFlowCommonData(63, "liab_cash_flow_eom", "hdg_grp_comp_liab_cash_flow_eom",  "liab_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_liab_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->liab_cash_flow_eom),
	CashFlowCommonData(64, "long_strike", "hdg_grp_comp_long_strike",  "long_strike",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_long_strike, 'E','N', '3', 'P', (size_t)&modelOffset->long_strike),
	CashFlowCommonData(65, "notional_amt_required", "hdg_grp_comp_notional_amt_required",  "notional_amt_required",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_required, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_required),
	CashFlowCommonData(66, "notional_amt_to_hedge", "hdg_grp_comp_notional_amt_to_hedge",  "notional_amt_to_hedge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_to_hedge),
	CashFlowCommonData(67, "notional_amt_to_hedge_cap", "hdg_grp_comp_notional_amt_to_hedge_cap",  "notional_amt_to_hedge_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_cap, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_to_hedge_cap),
	CashFlowCommonData(68, "notional_amt_to_hedge_index", "hdg_grp_comp_notional_amt_to_hedge_index",  "notional_amt_to_hedge_index",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_index, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_to_hedge_index),
	CashFlowCommonData(69, "notional_amt_to_hedge_long_strike", "hdg_grp_comp_notional_amt_to_hedge_long_strike",  "notional_amt_to_hedge_long_strike",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_amt_to_hedge_long_strike, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_amt_to_hedge_long_strike),
	CashFlowCommonData(70, "notional_to_hedge", "hdg_grp_comp_notional_to_hedge",  "notional_to_hedge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_notional_to_hedge, 'E','N', '3', 'P', (size_t)&modelOffset->notional_to_hedge),
	CashFlowCommonData(71, "opt_budget", "hdg_grp_comp_opt_budget",  "opt_budget",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_opt_budget, 'E','N', '3', 'P', (size_t)&modelOffset->opt_budget),
	CashFlowCommonData(72, "opt_budget_amt", "hdg_grp_comp_opt_budget_amt",  "opt_budget_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_opt_budget_amt, 'E','N', '3', 'P', (size_t)&modelOffset->opt_budget_amt),
	CashFlowCommonData(73, "opt_payoff", "hdg_grp_comp_opt_payoff",  "opt_payoff",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_opt_payoff, 'E','N', '3', 'P', (size_t)&modelOffset->opt_payoff),
	CashFlowCommonData(74, "part_rate", "hdg_grp_comp_part_rate",  "part_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_part_rate, 'E','N', '3', 'P', (size_t)&modelOffset->part_rate),
	CashFlowCommonData(75, "proj_tgt_hedge_stmt", "hdg_grp_comp_proj_tgt_hedge_stmt",  "proj_tgt_hedge_stmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_proj_tgt_hedge_stmt, 'E','N', '3', 'P', (size_t)&modelOffset->proj_tgt_hedge_stmt),
	CashFlowCommonData(76, "pv_charges", "hdg_grp_comp_pv_charges",  "pv_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_pv_charges, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_charges),
	CashFlowCommonData(77, "pv_claims", "hdg_grp_comp_pv_claims",  "pv_claims",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_pv_claims, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_claims),
	CashFlowCommonData(78, "rho_convex_hedge_flag", "hdg_grp_comp_rho_convex_hedge_flag",  "rho_convex_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_flag),
	CashFlowCommonData(79, "rho_convex_hedge_inv_amt", "hdg_grp_comp_rho_convex_hedge_inv_amt",  "rho_convex_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_inv_amt),
	CashFlowCommonData(80, "rho_convex_hedge_mkt_val", "hdg_grp_comp_rho_convex_hedge_mkt_val",  "rho_convex_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_mkt_val),
	CashFlowCommonData(81, "rho_convex_hedge_mkt_val_incr", "hdg_grp_comp_rho_convex_hedge_mkt_val_incr",  "rho_convex_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_mkt_val_incr),
	CashFlowCommonData(82, "rho_convex_hedge_pmt", "hdg_grp_comp_rho_convex_hedge_pmt",  "rho_convex_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_pmt),
	CashFlowCommonData(83, "rho_convex_hedge_prof", "hdg_grp_comp_rho_convex_hedge_prof",  "rho_convex_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_prof),
	CashFlowCommonData(84, "rho_convex_hedge_sale_amt", "hdg_grp_comp_rho_convex_hedge_sale_amt",  "rho_convex_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_sale_amt),
	CashFlowCommonData(85, "rho_convex_hedge_transaction_cost", "hdg_grp_comp_rho_convex_hedge_transaction_cost",  "rho_convex_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_transaction_cost),
	CashFlowCommonData(86, "rho_convex_key_rate_1", "hdg_grp_comp_rho_convex_key_rate_1",  "rho_convex_key_rate_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_1, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_1),
	CashFlowCommonData(87, "rho_convex_key_rate_10", "hdg_grp_comp_rho_convex_key_rate_10",  "rho_convex_key_rate_10",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_10, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_10),
	CashFlowCommonData(88, "rho_convex_key_rate_2", "hdg_grp_comp_rho_convex_key_rate_2",  "rho_convex_key_rate_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_2, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_2),
	CashFlowCommonData(89, "rho_convex_key_rate_3", "hdg_grp_comp_rho_convex_key_rate_3",  "rho_convex_key_rate_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_3, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_3),
	CashFlowCommonData(90, "rho_convex_key_rate_4", "hdg_grp_comp_rho_convex_key_rate_4",  "rho_convex_key_rate_4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_4, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_4),
	CashFlowCommonData(91, "rho_convex_key_rate_5", "hdg_grp_comp_rho_convex_key_rate_5",  "rho_convex_key_rate_5",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_5, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_5),
	CashFlowCommonData(92, "rho_convex_key_rate_6", "hdg_grp_comp_rho_convex_key_rate_6",  "rho_convex_key_rate_6",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_6, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_6),
	CashFlowCommonData(93, "rho_convex_key_rate_7", "hdg_grp_comp_rho_convex_key_rate_7",  "rho_convex_key_rate_7",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_7, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_7),
	CashFlowCommonData(94, "rho_convex_key_rate_8", "hdg_grp_comp_rho_convex_key_rate_8",  "rho_convex_key_rate_8",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_8, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_8),
	CashFlowCommonData(95, "rho_convex_key_rate_9", "hdg_grp_comp_rho_convex_key_rate_9",  "rho_convex_key_rate_9",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_key_rate_9, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_key_rate_9),
	CashFlowCommonData(96, "rho_convex_parallel", "hdg_grp_comp_rho_convex_parallel",  "rho_convex_parallel",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_convex_parallel, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_parallel),
	CashFlowCommonData(97, "rho_hedge_flag", "hdg_grp_comp_rho_hedge_flag",  "rho_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_flag),
	CashFlowCommonData(98, "rho_hedge_inv_amt", "hdg_grp_comp_rho_hedge_inv_amt",  "rho_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_inv_amt),
	CashFlowCommonData(99, "rho_hedge_mkt_val", "hdg_grp_comp_rho_hedge_mkt_val",  "rho_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->rho_hedge_mkt_val),
	CashFlowCommonData(100, "rho_hedge_mkt_val_incr", "hdg_grp_comp_rho_hedge_mkt_val_incr",  "rho_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_mkt_val_incr),
	CashFlowCommonData(101, "rho_hedge_pmt", "hdg_grp_comp_rho_hedge_pmt",  "rho_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_pmt),
	CashFlowCommonData(102, "rho_hedge_prof", "hdg_grp_comp_rho_hedge_prof",  "rho_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_prof),
	CashFlowCommonData(103, "rho_hedge_sale_amt", "hdg_grp_comp_rho_hedge_sale_amt",  "rho_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_sale_amt),
	CashFlowCommonData(104, "rho_hedge_transaction_cost", "hdg_grp_comp_rho_hedge_transaction_cost",  "rho_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_transaction_cost),
	CashFlowCommonData(105, "rho_key_rate_1", "hdg_grp_comp_rho_key_rate_1",  "rho_key_rate_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_1, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_1),
	CashFlowCommonData(106, "rho_key_rate_10", "hdg_grp_comp_rho_key_rate_10",  "rho_key_rate_10",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_10, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_10),
	CashFlowCommonData(107, "rho_key_rate_2", "hdg_grp_comp_rho_key_rate_2",  "rho_key_rate_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_2, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_2),
	CashFlowCommonData(108, "rho_key_rate_3", "hdg_grp_comp_rho_key_rate_3",  "rho_key_rate_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_3, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_3),
	CashFlowCommonData(109, "rho_key_rate_4", "hdg_grp_comp_rho_key_rate_4",  "rho_key_rate_4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_4, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_4),
	CashFlowCommonData(110, "rho_key_rate_5", "hdg_grp_comp_rho_key_rate_5",  "rho_key_rate_5",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_5, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_5),
	CashFlowCommonData(111, "rho_key_rate_6", "hdg_grp_comp_rho_key_rate_6",  "rho_key_rate_6",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_6, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_6),
	CashFlowCommonData(112, "rho_key_rate_7", "hdg_grp_comp_rho_key_rate_7",  "rho_key_rate_7",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_7, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_7),
	CashFlowCommonData(113, "rho_key_rate_8", "hdg_grp_comp_rho_key_rate_8",  "rho_key_rate_8",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_8, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_8),
	CashFlowCommonData(114, "rho_key_rate_9", "hdg_grp_comp_rho_key_rate_9",  "rho_key_rate_9",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_key_rate_9, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_key_rate_9),
	CashFlowCommonData(115, "rho_parallel", "hdg_grp_comp_rho_parallel",  "rho_parallel",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_rho_parallel, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_parallel),
	CashFlowCommonData(116, "short_strike", "hdg_grp_comp_short_strike",  "short_strike",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_short_strike, 'E','N', '3', 'P', (size_t)&modelOffset->short_strike),
	CashFlowCommonData(117, "startup", "hdg_grp_comp_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(118, "valn_tgt_hedge_final", "hdg_grp_comp_valn_tgt_hedge_final",  "valn_tgt_hedge_final",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_valn_tgt_hedge_final, 'E','Y', '3', 'P', (size_t)&modelOffset->valn_tgt_hedge_final),
	CashFlowCommonData(119, "valn_tgt_hedge_shock", "hdg_grp_comp_valn_tgt_hedge_shock",  "valn_tgt_hedge_shock",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_valn_tgt_hedge_shock, 'E','Y', '3', 'P', (size_t)&modelOffset->valn_tgt_hedge_shock),
	CashFlowCommonData(120, "vega_hedge_flag", "hdg_grp_comp_vega_hedge_flag",  "vega_hedge_flag",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_flag, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_flag),
	CashFlowCommonData(121, "vega_hedge_inv_amt", "hdg_grp_comp_vega_hedge_inv_amt",  "vega_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_inv_amt),
	CashFlowCommonData(122, "vega_hedge_mkt_val", "hdg_grp_comp_vega_hedge_mkt_val",  "vega_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->vega_hedge_mkt_val),
	CashFlowCommonData(123, "vega_hedge_mkt_val_incr", "hdg_grp_comp_vega_hedge_mkt_val_incr",  "vega_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_mkt_val_incr),
	CashFlowCommonData(124, "vega_hedge_pmt", "hdg_grp_comp_vega_hedge_pmt",  "vega_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_pmt),
	CashFlowCommonData(125, "vega_hedge_prof", "hdg_grp_comp_vega_hedge_prof",  "vega_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_prof),
	CashFlowCommonData(126, "vega_hedge_sale_amt", "hdg_grp_comp_vega_hedge_sale_amt",  "vega_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_sale_amt),
	CashFlowCommonData(127, "vega_hedge_transaction_cost", "hdg_grp_comp_vega_hedge_transaction_cost",  "vega_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_transaction_cost),
	CashFlowCommonData(128, "vega_index_1", "hdg_grp_comp_vega_index_1",  "vega_index_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_1),
	CashFlowCommonData(129, "vega_index_1_term_1", "hdg_grp_comp_vega_index_1_term_1",  "vega_index_1_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_1_term_1),
	CashFlowCommonData(130, "vega_index_1_term_2", "hdg_grp_comp_vega_index_1_term_2",  "vega_index_1_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_1_term_2),
	CashFlowCommonData(131, "vega_index_1_term_3", "hdg_grp_comp_vega_index_1_term_3",  "vega_index_1_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_1_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_1_term_3),
	CashFlowCommonData(132, "vega_index_2", "hdg_grp_comp_vega_index_2",  "vega_index_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_2),
	CashFlowCommonData(133, "vega_index_2_term_1", "hdg_grp_comp_vega_index_2_term_1",  "vega_index_2_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_2_term_1),
	CashFlowCommonData(134, "vega_index_2_term_2", "hdg_grp_comp_vega_index_2_term_2",  "vega_index_2_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_2_term_2),
	CashFlowCommonData(135, "vega_index_2_term_3", "hdg_grp_comp_vega_index_2_term_3",  "vega_index_2_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_2_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_2_term_3),
	CashFlowCommonData(136, "vega_index_3", "hdg_grp_comp_vega_index_3",  "vega_index_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_3),
	CashFlowCommonData(137, "vega_index_3_term_1", "hdg_grp_comp_vega_index_3_term_1",  "vega_index_3_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_3_term_1),
	CashFlowCommonData(138, "vega_index_3_term_2", "hdg_grp_comp_vega_index_3_term_2",  "vega_index_3_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_3_term_2),
	CashFlowCommonData(139, "vega_index_3_term_3", "hdg_grp_comp_vega_index_3_term_3",  "vega_index_3_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_3_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_3_term_3),
	CashFlowCommonData(140, "vega_index_4", "hdg_grp_comp_vega_index_4",  "vega_index_4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_4),
	CashFlowCommonData(141, "vega_index_4_term_1", "hdg_grp_comp_vega_index_4_term_1",  "vega_index_4_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_4_term_1),
	CashFlowCommonData(142, "vega_index_4_term_2", "hdg_grp_comp_vega_index_4_term_2",  "vega_index_4_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_4_term_2),
	CashFlowCommonData(143, "vega_index_4_term_3", "hdg_grp_comp_vega_index_4_term_3",  "vega_index_4_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_4_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_4_term_3),
	CashFlowCommonData(144, "vega_index_5", "hdg_grp_comp_vega_index_5",  "vega_index_5",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_5),
	CashFlowCommonData(145, "vega_index_5_term_1", "hdg_grp_comp_vega_index_5_term_1",  "vega_index_5_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_5_term_1),
	CashFlowCommonData(146, "vega_index_5_term_2", "hdg_grp_comp_vega_index_5_term_2",  "vega_index_5_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_5_term_2),
	CashFlowCommonData(147, "vega_index_5_term_3", "hdg_grp_comp_vega_index_5_term_3",  "vega_index_5_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_5_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_5_term_3),
	CashFlowCommonData(148, "vega_index_6", "hdg_grp_comp_vega_index_6",  "vega_index_6",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_6),
	CashFlowCommonData(149, "vega_index_6_term_1", "hdg_grp_comp_vega_index_6_term_1",  "vega_index_6_term_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_1, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_6_term_1),
	CashFlowCommonData(150, "vega_index_6_term_2", "hdg_grp_comp_vega_index_6_term_2",  "vega_index_6_term_2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_2, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_6_term_2),
	CashFlowCommonData(151, "vega_index_6_term_3", "hdg_grp_comp_vega_index_6_term_3",  "vega_index_6_term_3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_index_6_term_3, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_index_6_term_3),
	CashFlowCommonData(152, "vega_parallel", "hdg_grp_comp_vega_parallel",  "vega_parallel",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&HDG_GRP_COMP_UDF::hdg_grp_comp_vega_parallel, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_parallel)
};
const CashFlowCommonData* HDG_GRP_COMP::mCFStaticData[] = {
	&HDG_GRP_COMP::mCFStaticData_0[0],
	&HDG_GRP_COMP::mCFStaticData_0[1],
	&HDG_GRP_COMP::mCFStaticData_0[2],
	&HDG_GRP_COMP::mCFStaticData_0[3],
	&HDG_GRP_COMP::mCFStaticData_0[4],
	&HDG_GRP_COMP::mCFStaticData_0[5],
	&HDG_GRP_COMP::mCFStaticData_0[6],
	&HDG_GRP_COMP::mCFStaticData_0[7],
	&HDG_GRP_COMP::mCFStaticData_0[8],
	&HDG_GRP_COMP::mCFStaticData_0[9],
	&HDG_GRP_COMP::mCFStaticData_0[10],
	&HDG_GRP_COMP::mCFStaticData_0[11],
	&HDG_GRP_COMP::mCFStaticData_0[12],
	&HDG_GRP_COMP::mCFStaticData_0[13],
	&HDG_GRP_COMP::mCFStaticData_0[14],
	&HDG_GRP_COMP::mCFStaticData_0[15],
	&HDG_GRP_COMP::mCFStaticData_0[16],
	&HDG_GRP_COMP::mCFStaticData_0[17],
	&HDG_GRP_COMP::mCFStaticData_0[18],
	&HDG_GRP_COMP::mCFStaticData_0[19],
	&HDG_GRP_COMP::mCFStaticData_0[20],
	&HDG_GRP_COMP::mCFStaticData_0[21],
	&HDG_GRP_COMP::mCFStaticData_0[22],
	&HDG_GRP_COMP::mCFStaticData_0[23],
	&HDG_GRP_COMP::mCFStaticData_0[24],
	&HDG_GRP_COMP::mCFStaticData_0[25],
	&HDG_GRP_COMP::mCFStaticData_0[26],
	&HDG_GRP_COMP::mCFStaticData_0[27],
	&HDG_GRP_COMP::mCFStaticData_0[28],
	&HDG_GRP_COMP::mCFStaticData_0[29],
	&HDG_GRP_COMP::mCFStaticData_0[30],
	&HDG_GRP_COMP::mCFStaticData_0[31],
	&HDG_GRP_COMP::mCFStaticData_0[32],
	&HDG_GRP_COMP::mCFStaticData_0[33],
	&HDG_GRP_COMP::mCFStaticData_0[34],
	&HDG_GRP_COMP::mCFStaticData_0[35],
	&HDG_GRP_COMP::mCFStaticData_0[36],
	&HDG_GRP_COMP::mCFStaticData_0[37],
	&HDG_GRP_COMP::mCFStaticData_0[38],
	&HDG_GRP_COMP::mCFStaticData_0[39],
	&HDG_GRP_COMP::mCFStaticData_0[40],
	&HDG_GRP_COMP::mCFStaticData_0[41],
	&HDG_GRP_COMP::mCFStaticData_0[42],
	&HDG_GRP_COMP::mCFStaticData_0[43],
	&HDG_GRP_COMP::mCFStaticData_0[44],
	&HDG_GRP_COMP::mCFStaticData_0[45],
	&HDG_GRP_COMP::mCFStaticData_0[46],
	&HDG_GRP_COMP::mCFStaticData_0[47],
	&HDG_GRP_COMP::mCFStaticData_0[48],
	&HDG_GRP_COMP::mCFStaticData_0[49],
	&HDG_GRP_COMP::mCFStaticData_0[50],
	&HDG_GRP_COMP::mCFStaticData_0[51],
	&HDG_GRP_COMP::mCFStaticData_0[52],
	&HDG_GRP_COMP::mCFStaticData_0[53],
	&HDG_GRP_COMP::mCFStaticData_0[54],
	&HDG_GRP_COMP::mCFStaticData_0[55],
	&HDG_GRP_COMP::mCFStaticData_0[56],
	&HDG_GRP_COMP::mCFStaticData_0[57],
	&HDG_GRP_COMP::mCFStaticData_0[58],
	&HDG_GRP_COMP::mCFStaticData_0[59],
	&HDG_GRP_COMP::mCFStaticData_0[60],
	&HDG_GRP_COMP::mCFStaticData_0[61],
	&HDG_GRP_COMP::mCFStaticData_0[62],
	&HDG_GRP_COMP::mCFStaticData_0[63],
	&HDG_GRP_COMP::mCFStaticData_0[64],
	&HDG_GRP_COMP::mCFStaticData_0[65],
	&HDG_GRP_COMP::mCFStaticData_0[66],
	&HDG_GRP_COMP::mCFStaticData_0[67],
	&HDG_GRP_COMP::mCFStaticData_0[68],
	&HDG_GRP_COMP::mCFStaticData_0[69],
	&HDG_GRP_COMP::mCFStaticData_0[70],
	&HDG_GRP_COMP::mCFStaticData_0[71],
	&HDG_GRP_COMP::mCFStaticData_0[72],
	&HDG_GRP_COMP::mCFStaticData_0[73],
	&HDG_GRP_COMP::mCFStaticData_0[74],
	&HDG_GRP_COMP::mCFStaticData_0[75],
	&HDG_GRP_COMP::mCFStaticData_0[76],
	&HDG_GRP_COMP::mCFStaticData_0[77],
	&HDG_GRP_COMP::mCFStaticData_0[78],
	&HDG_GRP_COMP::mCFStaticData_0[79],
	&HDG_GRP_COMP::mCFStaticData_0[80],
	&HDG_GRP_COMP::mCFStaticData_0[81],
	&HDG_GRP_COMP::mCFStaticData_0[82],
	&HDG_GRP_COMP::mCFStaticData_0[83],
	&HDG_GRP_COMP::mCFStaticData_0[84],
	&HDG_GRP_COMP::mCFStaticData_0[85],
	&HDG_GRP_COMP::mCFStaticData_0[86],
	&HDG_GRP_COMP::mCFStaticData_0[87],
	&HDG_GRP_COMP::mCFStaticData_0[88],
	&HDG_GRP_COMP::mCFStaticData_0[89],
	&HDG_GRP_COMP::mCFStaticData_0[90],
	&HDG_GRP_COMP::mCFStaticData_0[91],
	&HDG_GRP_COMP::mCFStaticData_0[92],
	&HDG_GRP_COMP::mCFStaticData_0[93],
	&HDG_GRP_COMP::mCFStaticData_0[94],
	&HDG_GRP_COMP::mCFStaticData_0[95],
	&HDG_GRP_COMP::mCFStaticData_0[96],
	&HDG_GRP_COMP::mCFStaticData_0[97],
	&HDG_GRP_COMP::mCFStaticData_0[98],
	&HDG_GRP_COMP::mCFStaticData_0[99],
	&HDG_GRP_COMP::mCFStaticData_0[100],
	&HDG_GRP_COMP::mCFStaticData_0[101],
	&HDG_GRP_COMP::mCFStaticData_0[102],
	&HDG_GRP_COMP::mCFStaticData_0[103],
	&HDG_GRP_COMP::mCFStaticData_0[104],
	&HDG_GRP_COMP::mCFStaticData_0[105],
	&HDG_GRP_COMP::mCFStaticData_0[106],
	&HDG_GRP_COMP::mCFStaticData_0[107],
	&HDG_GRP_COMP::mCFStaticData_0[108],
	&HDG_GRP_COMP::mCFStaticData_0[109],
	&HDG_GRP_COMP::mCFStaticData_0[110],
	&HDG_GRP_COMP::mCFStaticData_0[111],
	&HDG_GRP_COMP::mCFStaticData_0[112],
	&HDG_GRP_COMP::mCFStaticData_0[113],
	&HDG_GRP_COMP::mCFStaticData_0[114],
	&HDG_GRP_COMP::mCFStaticData_0[115],
	&HDG_GRP_COMP::mCFStaticData_0[116],
	&HDG_GRP_COMP::mCFStaticData_0[117],
	&HDG_GRP_COMP::mCFStaticData_0[118],
	&HDG_GRP_COMP::mCFStaticData_0[119],
	&HDG_GRP_COMP::mCFStaticData_0[120],
	&HDG_GRP_COMP::mCFStaticData_0[121],
	&HDG_GRP_COMP::mCFStaticData_0[122],
	&HDG_GRP_COMP::mCFStaticData_0[123],
	&HDG_GRP_COMP::mCFStaticData_0[124],
	&HDG_GRP_COMP::mCFStaticData_0[125],
	&HDG_GRP_COMP::mCFStaticData_0[126],
	&HDG_GRP_COMP::mCFStaticData_0[127],
	&HDG_GRP_COMP::mCFStaticData_0[128],
	&HDG_GRP_COMP::mCFStaticData_0[129],
	&HDG_GRP_COMP::mCFStaticData_0[130],
	&HDG_GRP_COMP::mCFStaticData_0[131],
	&HDG_GRP_COMP::mCFStaticData_0[132],
	&HDG_GRP_COMP::mCFStaticData_0[133],
	&HDG_GRP_COMP::mCFStaticData_0[134],
	&HDG_GRP_COMP::mCFStaticData_0[135],
	&HDG_GRP_COMP::mCFStaticData_0[136],
	&HDG_GRP_COMP::mCFStaticData_0[137],
	&HDG_GRP_COMP::mCFStaticData_0[138],
	&HDG_GRP_COMP::mCFStaticData_0[139],
	&HDG_GRP_COMP::mCFStaticData_0[140],
	&HDG_GRP_COMP::mCFStaticData_0[141],
	&HDG_GRP_COMP::mCFStaticData_0[142],
	&HDG_GRP_COMP::mCFStaticData_0[143],
	&HDG_GRP_COMP::mCFStaticData_0[144],
	&HDG_GRP_COMP::mCFStaticData_0[145],
	&HDG_GRP_COMP::mCFStaticData_0[146],
	&HDG_GRP_COMP::mCFStaticData_0[147],
	&HDG_GRP_COMP::mCFStaticData_0[148],
	&HDG_GRP_COMP::mCFStaticData_0[149],
	&HDG_GRP_COMP::mCFStaticData_0[150],
	&HDG_GRP_COMP::mCFStaticData_0[151],
	&HDG_GRP_COMP::mCFStaticData_0[152],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for calc_asset_greeks_defn                                                                                       
	const ChoicePair calc_asset_greeks_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DELTA, "Delta")
		,ChoicePair(StrEnum::GAMMA, "Gamma")
		,ChoicePair(StrEnum::VEGA, "Vega")
		,ChoicePair(StrEnum::RHO, "Rho")
		,ChoicePair(StrEnum::RHO_CONVEXITY, "Rho Convexity")
	};
	const EnumList calc_asset_greeks_defnEnumList(5, calc_asset_greeks_defnChoicePairs);

	// EnumList for calc_asset_greeks_timing_defn                                                                                       
	const ChoicePair calc_asset_greeks_timing_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PURCH, "Purch")
	};
	const EnumList calc_asset_greeks_timing_defnEnumList(1, calc_asset_greeks_timing_defnChoicePairs);

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

	// EnumList for hedge_disc_rate_defn                                                                                       
	const ChoicePair hedge_disc_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DETERMINISTIC, "Deterministic")
		,ChoicePair(StrEnum::COMPETITOR_RATE, "Competitor Rate")
		,ChoicePair(StrEnum::BETA_RATE, "Beta Rate")
	};
	const EnumList hedge_disc_rate_defnEnumList(3, hedge_disc_rate_defnChoicePairs);

	// EnumList for hedge_grp_crediting_defn                                                                                       
	const ChoicePair hedge_grp_crediting_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::POINT_TO_POINT, "Point to Point")
		,ChoicePair(StrEnum::MOVING_AVERAGE, "Moving Average")
		,ChoicePair(StrEnum::MONTHLY_SUM_CAP, "Monthly Sum Cap")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
	};
	const EnumList hedge_grp_crediting_defnEnumList(4, hedge_grp_crediting_defnChoicePairs);

	// EnumList for hedge_grp_delta_hedge_defn                                                                                       
	const ChoicePair hedge_grp_delta_hedge_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList hedge_grp_delta_hedge_defnEnumList(2, hedge_grp_delta_hedge_defnChoicePairs);

	// EnumList for hedge_grp_delta_hedge_liab_shock_defn                                                                                       
	const ChoicePair hedge_grp_delta_hedge_liab_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INDEX_SPECIFIC, "Index Specific")
		,ChoicePair(StrEnum::PARALLEL, "Parallel")
	};
	const EnumList hedge_grp_delta_hedge_liab_shock_defnEnumList(2, hedge_grp_delta_hedge_liab_shock_defnChoicePairs);

	// EnumList for hedge_grp_delta_hedge_strat_defn                                                                                       
	const ChoicePair hedge_grp_delta_hedge_strat_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EQUITY_FUTURES, "Equity Futures")
	};
	const EnumList hedge_grp_delta_hedge_strat_defnEnumList(1, hedge_grp_delta_hedge_strat_defnChoicePairs);

	// EnumList for hedge_grp_dyn_lever                                                                                       
	const ChoicePair hedge_grp_dyn_leverChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DYNAMIC_CAP, "Dynamic Cap")
		,ChoicePair(StrEnum::DYNAMIC_PARTICIPATION, "Dynamic Participation")
	};
	const EnumList hedge_grp_dyn_leverEnumList(2, hedge_grp_dyn_leverChoicePairs);

	// EnumList for hedge_grp_gamma_vega_hedge_defn                                                                                       
	const ChoicePair hedge_grp_gamma_vega_hedge_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList hedge_grp_gamma_vega_hedge_defnEnumList(2, hedge_grp_gamma_vega_hedge_defnChoicePairs);

	// EnumList for hedge_grp_gamma_vega_hedge_liab_shock_defn                                                                                       
	const ChoicePair hedge_grp_gamma_vega_hedge_liab_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INDEX_SPECIFIC, "Index Specific")
		,ChoicePair(StrEnum::INDEX_TERM_SPECIFIC, "Index Term Specific")
		,ChoicePair(StrEnum::PARALLEL, "Parallel")
	};
	const EnumList hedge_grp_gamma_vega_hedge_liab_shock_defnEnumList(3, hedge_grp_gamma_vega_hedge_liab_shock_defnChoicePairs);

	// EnumList for hedge_grp_gamma_vega_hedge_strat_defn                                                                                       
	const ChoicePair hedge_grp_gamma_vega_hedge_strat_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EQUITY_FUTURES, "Equity Futures")
	};
	const EnumList hedge_grp_gamma_vega_hedge_strat_defnEnumList(1, hedge_grp_gamma_vega_hedge_strat_defnChoicePairs);

	// EnumList for hedge_grp_gamma_vega_hedge_type_defn                                                                                       
	const ChoicePair hedge_grp_gamma_vega_hedge_type_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GAMMA, "Gamma")
		,ChoicePair(StrEnum::VEGA, "Vega")
	};
	const EnumList hedge_grp_gamma_vega_hedge_type_defnEnumList(2, hedge_grp_gamma_vega_hedge_type_defnChoicePairs);

	// EnumList for hedge_grp_gmab_defn                                                                                       
	const ChoicePair hedge_grp_gmab_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList hedge_grp_gmab_defnEnumList(2, hedge_grp_gmab_defnChoicePairs);

	// EnumList for hedge_grp_gmdb_defn                                                                                       
	const ChoicePair hedge_grp_gmdb_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList hedge_grp_gmdb_defnEnumList(2, hedge_grp_gmdb_defnChoicePairs);

	// EnumList for hedge_grp_gmib_defn                                                                                       
	const ChoicePair hedge_grp_gmib_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList hedge_grp_gmib_defnEnumList(2, hedge_grp_gmib_defnChoicePairs);

	// EnumList for hedge_grp_gmwb_defn                                                                                       
	const ChoicePair hedge_grp_gmwb_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList hedge_grp_gmwb_defnEnumList(2, hedge_grp_gmwb_defnChoicePairs);

	// EnumList for hedge_grp_rho_convex_hedge_defn                                                                                       
	const ChoicePair hedge_grp_rho_convex_hedge_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList hedge_grp_rho_convex_hedge_defnEnumList(2, hedge_grp_rho_convex_hedge_defnChoicePairs);

	// EnumList for hedge_grp_rho_convex_hedge_liab_shock_defn                                                                                       
	const ChoicePair hedge_grp_rho_convex_hedge_liab_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::KEY_RATE_SPECIFIC, "Key Rate Specific")
		,ChoicePair(StrEnum::PARALLEL, "Parallel")
	};
	const EnumList hedge_grp_rho_convex_hedge_liab_shock_defnEnumList(2, hedge_grp_rho_convex_hedge_liab_shock_defnChoicePairs);

	// EnumList for hedge_grp_rho_convex_hedge_strat_defn                                                                                       
	const ChoicePair hedge_grp_rho_convex_hedge_strat_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EQUITY_FUTURES, "Equity Futures")
	};
	const EnumList hedge_grp_rho_convex_hedge_strat_defnEnumList(1, hedge_grp_rho_convex_hedge_strat_defnChoicePairs);

	// EnumList for hedge_grp_rho_hedge_defn                                                                                       
	const ChoicePair hedge_grp_rho_hedge_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList hedge_grp_rho_hedge_defnEnumList(2, hedge_grp_rho_hedge_defnChoicePairs);

	// EnumList for hedge_grp_rho_hedge_liab_shock_defn                                                                                       
	const ChoicePair hedge_grp_rho_hedge_liab_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::KEY_RATE_SPECIFIC, "Key Rate Specific")
		,ChoicePair(StrEnum::PARALLEL, "Parallel")
	};
	const EnumList hedge_grp_rho_hedge_liab_shock_defnEnumList(2, hedge_grp_rho_hedge_liab_shock_defnChoicePairs);

	// EnumList for hedge_grp_rho_hedge_strat_defn                                                                                       
	const ChoicePair hedge_grp_rho_hedge_strat_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EQUITY_FUTURES, "Equity Futures")
	};
	const EnumList hedge_grp_rho_hedge_strat_defnEnumList(1, hedge_grp_rho_hedge_strat_defnChoicePairs);

	// EnumList for independent_mp_defn                                                                                       
	const ChoicePair independent_mp_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList independent_mp_defnEnumList(2, independent_mp_defnChoicePairs);

	// EnumList for int_rate_shock_defn                                                                                       
	const ChoicePair int_rate_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList int_rate_shock_defnEnumList(2, int_rate_shock_defnChoicePairs);

	// EnumList for phldr_shock_defn                                                                                       
	const ChoicePair phldr_shock_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList phldr_shock_defnEnumList(2, phldr_shock_defnChoicePairs);

	// EnumList for valn_scens_defn                                                                                       
	const ChoicePair valn_scens_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MODEL_POINT_SPECIFIC, "Model Point Specific")
		,ChoicePair(StrEnum::BLOCK_SPECIFIC, "Block Specific")
	};
	const EnumList valn_scens_defnEnumList(2, valn_scens_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace HDG_GRP_COMP_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(HDG_GRP_COMP::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(HDG_GRP_COMP::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace HDG_GRP_COMP_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void HDG_GRP_COMP::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> HDG_GRP_COMP::mgr_;

	Attribute::Descriptor HDG_GRP_COMP::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"calc_asset_greeks_defn", -1, (size_t)&modelOffset->calc_asset_greeks_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calc_asset_greeks_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"calc_asset_greeks_timing_defn", -1, (size_t)&modelOffset->calc_asset_greeks_timing_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calc_asset_greeks_timing_defnEnumList, Feature(true)),
	Descriptor(2, Attribute::STRING,	"decrem_id", -1, (size_t)&modelOffset->decrem_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"eqt_price_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eqt_price_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STR_ENUM,	"eqt_price_shock_defn", -1, (size_t)&modelOffset->eqt_price_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &eqt_price_shock_defnEnumList, Feature(true)),
	Descriptor(5, Attribute::STRING,	"eqt_price_shock_id", -1, (size_t)&modelOffset->eqt_price_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"eqt_vol_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eqt_vol_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STR_ENUM,	"eqt_vol_shock_defn", -1, (size_t)&modelOffset->eqt_vol_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &eqt_vol_shock_defnEnumList, Feature(true)),
	Descriptor(8, Attribute::STRING,	"eqt_vol_shock_id", -1, (size_t)&modelOffset->eqt_vol_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"hedge_disc_rate_comp_id", -1, (size_t)&modelOffset->hedge_disc_rate_comp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::STR_ENUM,	"hedge_disc_rate_defn", -1, (size_t)&modelOffset->hedge_disc_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_disc_rate_defnEnumList, Feature(true)),
	Descriptor(11, Attribute::DOUBLE,	"hedge_disc_rate_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_disc_rate_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STRING,	"hedge_grp_asset_id", -1, (size_t)&modelOffset->hedge_grp_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::INT,	"hedge_grp_bucket_id", -1, (size_t)&modelOffset->hedge_grp_bucket_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::INT,	"hedge_grp_count_id", -1, (size_t)&modelOffset->hedge_grp_count_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"hedge_grp_crediting_defn", -1, (size_t)&modelOffset->hedge_grp_crediting_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_crediting_defnEnumList, Feature(true)),
	Descriptor(16, Attribute::INT,	"hedge_grp_crediting_mths", -1, (size_t)&modelOffset->hedge_grp_crediting_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STRING,	"hedge_grp_delta_hedge_asset_id", -1, (size_t)&modelOffset->hedge_grp_delta_hedge_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STR_ENUM,	"hedge_grp_delta_hedge_defn", -1, (size_t)&modelOffset->hedge_grp_delta_hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_delta_hedge_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::STR_ENUM,	"hedge_grp_delta_hedge_liab_shock_defn", -1, (size_t)&modelOffset->hedge_grp_delta_hedge_liab_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_delta_hedge_liab_shock_defnEnumList, Feature(true)),
	Descriptor(20, Attribute::DOUBLE,	"hedge_grp_delta_hedge_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_delta_hedge_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::INT,	"hedge_grp_delta_hedge_rebal_freq", -1, (size_t)&modelOffset->hedge_grp_delta_hedge_rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"hedge_grp_delta_hedge_strat_defn", -1, (size_t)&modelOffset->hedge_grp_delta_hedge_strat_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_delta_hedge_strat_defnEnumList, Feature(true)),
	Descriptor(23, Attribute::DOUBLE,	"hedge_grp_delta_hedge_tolerance_dollar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_delta_hedge_tolerance_dollar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::DOUBLE,	"hedge_grp_delta_hedge_tolerance_pct_liab_delta", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_delta_hedge_tolerance_pct_liab_delta,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::DOUBLE,	"hedge_grp_delta_hedge_transaction_costs_bps", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_delta_hedge_transaction_costs_bps,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STR_ENUM,	"hedge_grp_dyn_lever", -1, (size_t)&modelOffset->hedge_grp_dyn_lever,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_dyn_leverEnumList, Feature(true)),
	Descriptor(27, Attribute::STRING,	"hedge_grp_gamma_vega_hedge_asset_id", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::STR_ENUM,	"hedge_grp_gamma_vega_hedge_defn", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gamma_vega_hedge_defnEnumList, Feature(true)),
	Descriptor(29, Attribute::STR_ENUM,	"hedge_grp_gamma_vega_hedge_liab_shock_defn", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_liab_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gamma_vega_hedge_liab_shock_defnEnumList, Feature(true)),
	Descriptor(30, Attribute::DOUBLE,	"hedge_grp_gamma_vega_hedge_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::INT,	"hedge_grp_gamma_vega_hedge_rebal_freq", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STR_ENUM,	"hedge_grp_gamma_vega_hedge_strat_defn", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_strat_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gamma_vega_hedge_strat_defnEnumList, Feature(true)),
	Descriptor(33, Attribute::DOUBLE,	"hedge_grp_gamma_vega_hedge_tolerance_dollar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_tolerance_dollar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::DOUBLE,	"hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::DOUBLE,	"hedge_grp_gamma_vega_hedge_transaction_costs_bps", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_transaction_costs_bps,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::STR_ENUM,	"hedge_grp_gamma_vega_hedge_type_defn", -1, (size_t)&modelOffset->hedge_grp_gamma_vega_hedge_type_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gamma_vega_hedge_type_defnEnumList, Feature(true)),
	Descriptor(37, Attribute::STR_ENUM,	"hedge_grp_gmab_defn", -1, (size_t)&modelOffset->hedge_grp_gmab_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gmab_defnEnumList, Feature(true)),
	Descriptor(38, Attribute::STR_ENUM,	"hedge_grp_gmdb_defn", -1, (size_t)&modelOffset->hedge_grp_gmdb_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gmdb_defnEnumList, Feature(true)),
	Descriptor(39, Attribute::STR_ENUM,	"hedge_grp_gmib_defn", -1, (size_t)&modelOffset->hedge_grp_gmib_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gmib_defnEnumList, Feature(true)),
	Descriptor(40, Attribute::STR_ENUM,	"hedge_grp_gmwb_defn", -1, (size_t)&modelOffset->hedge_grp_gmwb_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_gmwb_defnEnumList, Feature(true)),
	Descriptor(41, Attribute::STRING,	"hedge_grp_id", -1, (size_t)&modelOffset->hedge_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::STRING,	"hedge_grp_index", -1, (size_t)&modelOffset->hedge_grp_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::STRING,	"hedge_grp_index_name", -1, (size_t)&modelOffset->hedge_grp_index_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::STRING,	"hedge_grp_index_term", -1, (size_t)&modelOffset->hedge_grp_index_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::STRING,	"hedge_grp_key_rate", -1, (size_t)&modelOffset->hedge_grp_key_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STRING,	"hedge_grp_plan_codes", -1, (size_t)&modelOffset->hedge_grp_plan_codes,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::DOUBLE,	"hedge_grp_rate_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rate_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::INT,	"hedge_grp_rebal_freq", -1, (size_t)&modelOffset->hedge_grp_rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::STRING,	"hedge_grp_rho_convex_hedge_asset_id", -1, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::STR_ENUM,	"hedge_grp_rho_convex_hedge_defn", -1, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_convex_hedge_defnEnumList, Feature(true)),
	Descriptor(51, Attribute::STR_ENUM,	"hedge_grp_rho_convex_hedge_liab_shock_defn", -1, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_liab_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_convex_hedge_liab_shock_defnEnumList, Feature(true)),
	Descriptor(52, Attribute::DOUBLE,	"hedge_grp_rho_convex_hedge_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::INT,	"hedge_grp_rho_convex_hedge_rebal_freq", -1, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::STR_ENUM,	"hedge_grp_rho_convex_hedge_strat_defn", -1, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_strat_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_convex_hedge_strat_defnEnumList, Feature(true)),
	Descriptor(55, Attribute::DOUBLE,	"hedge_grp_rho_convex_hedge_tolerance_dollar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_tolerance_dollar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::DOUBLE,	"hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::DOUBLE,	"hedge_grp_rho_convex_hedge_transaction_costs_bps", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_convex_hedge_transaction_costs_bps,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STRING,	"hedge_grp_rho_hedge_asset_id", -1, (size_t)&modelOffset->hedge_grp_rho_hedge_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::STR_ENUM,	"hedge_grp_rho_hedge_defn", -1, (size_t)&modelOffset->hedge_grp_rho_hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_hedge_defnEnumList, Feature(true)),
	Descriptor(60, Attribute::STR_ENUM,	"hedge_grp_rho_hedge_liab_shock_defn", -1, (size_t)&modelOffset->hedge_grp_rho_hedge_liab_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_hedge_liab_shock_defnEnumList, Feature(true)),
	Descriptor(61, Attribute::DOUBLE,	"hedge_grp_rho_hedge_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_hedge_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::INT,	"hedge_grp_rho_hedge_rebal_freq", -1, (size_t)&modelOffset->hedge_grp_rho_hedge_rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::STR_ENUM,	"hedge_grp_rho_hedge_strat_defn", -1, (size_t)&modelOffset->hedge_grp_rho_hedge_strat_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_grp_rho_hedge_strat_defnEnumList, Feature(true)),
	Descriptor(64, Attribute::DOUBLE,	"hedge_grp_rho_hedge_tolerance_dollar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_hedge_tolerance_dollar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::DOUBLE,	"hedge_grp_rho_hedge_tolerance_pct_liab_rho", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_hedge_tolerance_pct_liab_rho,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::DOUBLE,	"hedge_grp_rho_hedge_transaction_costs_bps", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_grp_rho_hedge_transaction_costs_bps,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(67, Attribute::STRING,	"hedge_grp_yld_curve_id", -1, (size_t)&modelOffset->hedge_grp_yld_curve_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(68, Attribute::STR_ENUM,	"independent_mp_defn", -1, (size_t)&modelOffset->independent_mp_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &independent_mp_defnEnumList, Feature(true)),
	Descriptor(69, Attribute::DOUBLE,	"int_rate_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(70, Attribute::STR_ENUM,	"int_rate_shock_defn", -1, (size_t)&modelOffset->int_rate_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &int_rate_shock_defnEnumList, Feature(true)),
	Descriptor(71, Attribute::STRING,	"int_rate_shock_id", -1, (size_t)&modelOffset->int_rate_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(72, Attribute::DOUBLE,	"phldr_shock", Descriptor::NOT_INDEXED, (size_t)&modelOffset->phldr_shock,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::STR_ENUM,	"phldr_shock_defn", -1, (size_t)&modelOffset->phldr_shock_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &phldr_shock_defnEnumList, Feature(true)),
	Descriptor(74, Attribute::STRING,	"phldr_shock_id", -1, (size_t)&modelOffset->phldr_shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::STRING,	"scen_file_name_addn", -1, (size_t)&modelOffset->scen_file_name_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::INT,	"shock_freq", -1, (size_t)&modelOffset->shock_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::STRING,	"shock_id", -1, (size_t)&modelOffset->shock_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(80, Attribute::STRING,	"valn_hedge_final_results", -1, (size_t)&modelOffset->valn_hedge_final_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(81, Attribute::STRING,	"valn_hedge_results", -1, (size_t)&modelOffset->valn_hedge_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(82, Attribute::STR_ENUM,	"valn_scens_defn", -1, (size_t)&modelOffset->valn_scens_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_scens_defnEnumList, Feature(true)),
	Descriptor(83, Attribute::INT,	"valn_scens_to_run", -1, (size_t)&modelOffset->valn_scens_to_run,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(84, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(85, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&HDG_GRP_COMP_UDF::hdg_grp_comp_final_period)),
	Descriptor(86, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&HDG_GRP_COMP_UDF::hdg_grp_comp_proj_date_adj)),
	Descriptor(87, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_date)),
	Descriptor(88, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_mth)),
	Descriptor(89, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&HDG_GRP_COMP_UDF::hdg_grp_comp_proj_start_yr)),
	Descriptor(90, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&HDG_GRP_COMP_UDF::hdg_grp_comp_start_period)),
	};

	Attribute::Descriptor* HDG_GRP_COMP::descriptorTable[] = {
	&HDG_GRP_COMP::descriptor_0[0],
	&HDG_GRP_COMP::descriptor_0[1],
	&HDG_GRP_COMP::descriptor_0[2],
	&HDG_GRP_COMP::descriptor_0[3],
	&HDG_GRP_COMP::descriptor_0[4],
	&HDG_GRP_COMP::descriptor_0[5],
	&HDG_GRP_COMP::descriptor_0[6],
	&HDG_GRP_COMP::descriptor_0[7],
	&HDG_GRP_COMP::descriptor_0[8],
	&HDG_GRP_COMP::descriptor_0[9],
	&HDG_GRP_COMP::descriptor_0[10],
	&HDG_GRP_COMP::descriptor_0[11],
	&HDG_GRP_COMP::descriptor_0[12],
	&HDG_GRP_COMP::descriptor_0[13],
	&HDG_GRP_COMP::descriptor_0[14],
	&HDG_GRP_COMP::descriptor_0[15],
	&HDG_GRP_COMP::descriptor_0[16],
	&HDG_GRP_COMP::descriptor_0[17],
	&HDG_GRP_COMP::descriptor_0[18],
	&HDG_GRP_COMP::descriptor_0[19],
	&HDG_GRP_COMP::descriptor_0[20],
	&HDG_GRP_COMP::descriptor_0[21],
	&HDG_GRP_COMP::descriptor_0[22],
	&HDG_GRP_COMP::descriptor_0[23],
	&HDG_GRP_COMP::descriptor_0[24],
	&HDG_GRP_COMP::descriptor_0[25],
	&HDG_GRP_COMP::descriptor_0[26],
	&HDG_GRP_COMP::descriptor_0[27],
	&HDG_GRP_COMP::descriptor_0[28],
	&HDG_GRP_COMP::descriptor_0[29],
	&HDG_GRP_COMP::descriptor_0[30],
	&HDG_GRP_COMP::descriptor_0[31],
	&HDG_GRP_COMP::descriptor_0[32],
	&HDG_GRP_COMP::descriptor_0[33],
	&HDG_GRP_COMP::descriptor_0[34],
	&HDG_GRP_COMP::descriptor_0[35],
	&HDG_GRP_COMP::descriptor_0[36],
	&HDG_GRP_COMP::descriptor_0[37],
	&HDG_GRP_COMP::descriptor_0[38],
	&HDG_GRP_COMP::descriptor_0[39],
	&HDG_GRP_COMP::descriptor_0[40],
	&HDG_GRP_COMP::descriptor_0[41],
	&HDG_GRP_COMP::descriptor_0[42],
	&HDG_GRP_COMP::descriptor_0[43],
	&HDG_GRP_COMP::descriptor_0[44],
	&HDG_GRP_COMP::descriptor_0[45],
	&HDG_GRP_COMP::descriptor_0[46],
	&HDG_GRP_COMP::descriptor_0[47],
	&HDG_GRP_COMP::descriptor_0[48],
	&HDG_GRP_COMP::descriptor_0[49],
	&HDG_GRP_COMP::descriptor_0[50],
	&HDG_GRP_COMP::descriptor_0[51],
	&HDG_GRP_COMP::descriptor_0[52],
	&HDG_GRP_COMP::descriptor_0[53],
	&HDG_GRP_COMP::descriptor_0[54],
	&HDG_GRP_COMP::descriptor_0[55],
	&HDG_GRP_COMP::descriptor_0[56],
	&HDG_GRP_COMP::descriptor_0[57],
	&HDG_GRP_COMP::descriptor_0[58],
	&HDG_GRP_COMP::descriptor_0[59],
	&HDG_GRP_COMP::descriptor_0[60],
	&HDG_GRP_COMP::descriptor_0[61],
	&HDG_GRP_COMP::descriptor_0[62],
	&HDG_GRP_COMP::descriptor_0[63],
	&HDG_GRP_COMP::descriptor_0[64],
	&HDG_GRP_COMP::descriptor_0[65],
	&HDG_GRP_COMP::descriptor_0[66],
	&HDG_GRP_COMP::descriptor_0[67],
	&HDG_GRP_COMP::descriptor_0[68],
	&HDG_GRP_COMP::descriptor_0[69],
	&HDG_GRP_COMP::descriptor_0[70],
	&HDG_GRP_COMP::descriptor_0[71],
	&HDG_GRP_COMP::descriptor_0[72],
	&HDG_GRP_COMP::descriptor_0[73],
	&HDG_GRP_COMP::descriptor_0[74],
	&HDG_GRP_COMP::descriptor_0[75],
	&HDG_GRP_COMP::descriptor_0[76],
	&HDG_GRP_COMP::descriptor_0[77],
	&HDG_GRP_COMP::descriptor_0[78],
	&HDG_GRP_COMP::descriptor_0[79],
	&HDG_GRP_COMP::descriptor_0[80],
	&HDG_GRP_COMP::descriptor_0[81],
	&HDG_GRP_COMP::descriptor_0[82],
	&HDG_GRP_COMP::descriptor_0[83],
	&HDG_GRP_COMP::descriptor_0[84],
	&HDG_GRP_COMP::descriptor_0[85],
	&HDG_GRP_COMP::descriptor_0[86],
	&HDG_GRP_COMP::descriptor_0[87],
	&HDG_GRP_COMP::descriptor_0[88],
	&HDG_GRP_COMP::descriptor_0[89],
	&HDG_GRP_COMP::descriptor_0[90],
	nullptr};
	const size_t HDG_GRP_COMP::sDescriptorCount = 91;

//factory
HDG_GRP_COMP* HDG_GRP_COMP::makeThis(int isSubmodel, ModelClass* owner, HDG_GRP_COMP* peer, 
						int mainRebase, const xstring &name, HDG_GRP_COMP_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("HDG_GRP_COMP::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor HDG_GRP_COMP");
#endif
	HDG_GRP_COMP* newP = (HDG_GRP_COMP*)new HDG_GRP_COMP_UDF
   	  ("hdg_grp_comp", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
HDG_GRP_COMP_persistent_object* HDG_GRP_COMP_persistent_object::makeThis(int isSubmodel, ModelClass* owner, HDG_GRP_COMP* peer, 
							int mainRebase, const xstring &name, HDG_GRP_COMP_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("HDG_GRP_COMP_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor HDG_GRP_COMP_persistent_object");
#endif
	HDG_GRP_COMP_persistent_object* newP = (HDG_GRP_COMP_persistent_object*)new HDG_GRP_COMP_persistent_object
   	  ("hdg_grp_comp", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			HDG_GRP_COMP_persistent_object* pd = dynamic_cast<HDG_GRP_COMP_persistent_object*>(product);
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

typedef double (HDG_GRP_COMP_UDF::*dPF) ();
typedef double (HDG_GRP_COMP_UDF::*dPFd) (double);
typedef int (HDG_GRP_COMP_UDF::*iPF) ();
typedef int (HDG_GRP_COMP_UDF::*iPFi) (int);
typedef xstring (HDG_GRP_COMP_UDF::*sPF) ();
typedef xstring (HDG_GRP_COMP_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
HDG_GRP_COMP::HDG_GRP_COMP(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (HDG_GRP_COMP_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
HDG_GRP_COMP::HDG_GRP_COMP(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(152, HDG_GRP_COMP::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_seg_ann_pba = 0;
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

	for (int cf_no = 1; cf_no <= 152; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (HDG_GRP_COMP_UDF::*dPXi2) (int, int);
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


 void HDG_GRP_COMP::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_seg_ann_pba = (ANN_PBA_PBA*)(findUnique("company|seg|ann_pba"));
#endif
 }
//copy_names END@2


 void HDG_GRP_COMP::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int HDG_GRP_COMP_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& HDG_GRP_COMP_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double HDG_GRP_COMP_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int HDG_GRP_COMP_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double HDG_GRP_COMP_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double HDG_GRP_COMP_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void HDG_GRP_COMP_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void HDG_GRP_COMP_persistent_object::write(long include_submodels) {
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

	void HDG_GRP_COMP_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void HDG_GRP_COMP_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void HDG_GRP_COMP_persistent_object::write(const xstring& key, long include_submodels) {
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




	HDG_GRP_COMP_persistent_object::~HDG_GRP_COMP_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool HDG_GRP_COMP_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void HDG_GRP_COMP_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void HDG_GRP_COMP_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void HDG_GRP_COMP_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void HDG_GRP_COMP_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void HDG_GRP_COMP_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* HDG_GRP_COMP_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* HDG_GRP_COMP_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* HDG_GRP_COMP_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char HDG_GRP_COMP_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void HDG_GRP_COMP_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
HDG_GRP_COMP_persistent_object::HDG_GRP_COMP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			HDG_GRP_COMP(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(HDG_GRP_COMP::sm_bond_is)
	, sm_bond_pv(HDG_GRP_COMP::sm_bond_pv)
	, sm_bond_ym(HDG_GRP_COMP::sm_bond_ym)
	, sm_mtg_is(HDG_GRP_COMP::sm_mtg_is)
	, sm_mtg_pv(HDG_GRP_COMP::sm_mtg_pv)
	, sm_mtg_ym(HDG_GRP_COMP::sm_mtg_ym)

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
HDG_GRP_COMP::~HDG_GRP_COMP() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void HDG_GRP_COMP::findTargetColumns() {

}
//findTargetColumns END@2
void HDG_GRP_COMP::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void HDG_GRP_COMP::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void HDG_GRP_COMP::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void HDG_GRP_COMP::start_of_projection() {
}
//start_of_projection END@2

void HDG_GRP_COMP::end_of_projection() {
}
//end_of_projection END@2

void HDG_GRP_COMP::start_of_layer() {
}


void HDG_GRP_COMP::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void HDG_GRP_COMP::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void HDG_GRP_COMP::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void HDG_GRP_COMP::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> HDG_GRP_COMP::ddfVector;
BitArray HDG_GRP_COMP::dataVariables(91);
bool HDG_GRP_COMP::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool HDG_GRP_COMP::writeClassInfo = true;

void HDG_GRP_COMP::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, HDG_GRP_COMP::descriptor_0>::dT = HDG_GRP_COMP::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, HDG_GRP_COMP::descriptor_0>::dT = HDG_GRP_COMP::descriptor_0;

