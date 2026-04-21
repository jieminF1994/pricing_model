
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
#include "ModelClass\ann_pba_pba_udf.h"
#include "ModelClass\adco_asset.h"
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

deptaskinput ann_pba_scen_amt_valn_input;
deptaskcols ann_pba_scen_amt_valn_input_cols;
deptaskmap ann_pba_scen_amt_valn_input_pos;
deptaskmapiter ann_pba_scen_amt_valn_input_pos_iter;
const int SCEN_AMT = 0;
const int TAX_AVG_RATIO = 1;

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
#ifndef ann_pba_pba_TableDefs
#define ann_pba_pba_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection ANN_PBA_PBA::TTHC;
void ANN_PBA_PBA::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - asset_yld_mthly
// Asset Yield Monthly                                                                                             
// Column:ASSET_YLD_MTHLY
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_asset_yld_mthly(int t) {
//^^^



//^^^

#line 1 "asset_yld_mthly.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return (pow(1.0 + seg->asset_yld_inv(t), 1.0 / 12.0) - 1.0);

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return (pow(1.0 + fa->asset_yld(t), 1.0 / 12.0) - 1.0);
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return (pow(1.0 + fia->asset_yld_inv(t), 1.0 / 12.0) - 1.0);
#endif	
	
#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return (pow(1.0 + pa->asset_yld(t), 1.0 / 12.0) - 1.0);
#endif	
	
return NO_AVG;

}


//@@ END

//@@ START - assets_accum
// Accumulated Assets                                                                                             
// Column:ASSETS_ACCUM
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_assets_accum(int t) {
//^^^



//^^^

#line 1 "assets_accum.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

double starting_assets = 0.0;

if (this == ann_pba)
	{
	if (alm_flag)
		return hedge_mkt_val(t)
		       + (seg->cash(t)
			       + seg->borrowing(t)
		    	   + seg->bk_val(t)
		      	   + seg->accr_int(t)
		           - seg->imr(t)
				     * pimr_adj_factor(t))
		         * reins_adj;

	if (nb_flag && valn_period == 0)
		{
		if (t == start_period)
			return NO_AVG;

		if (t == start_period + 1)
			{
			starting_assets 
			= init_assets 
			  * init_asset_pct
			  * reins_adj;

			return starting_assets
	        	   + cash_flow(t)
	               + hedge_cash_flow(t)
	     	      + cash_flow_int(t)
	         	  + inv_inc(t)
	          	 + cap_gain(t)
	           	- imr_incr(t)
	           	- tax(t);
			}
		}

	if (t == start_period)
		return init_assets 
			   * init_asset_pct
			   * reins_adj;

	return assets_accum(t - 1)
    	   + cash_flow(t)
           + hedge_cash_flow(t)
    	   + cash_flow_int(t)
	       + inv_inc(t)
    	   + cap_gain(t)
	       - imr_incr(t)
    	   - tax(t);
	}
	
// pricing calculations
if (pricing_flag && valn_period == 0)
	{
	if (t == start_period)
		return NO_AVG;
		
	if (t == start_period + 1)
		return init_assets 
		       * init_asset_pct
		       * reins_adj
		       + cash_flow(t)
		       + hedge_cash_flow(t)
		       + cash_flow_int(t)
	           + inv_inc(t)
	           - tax(t);	
	}

if (t == start_period)	
	return init_assets
	       * init_asset_pct
	       * reins_adj;

return assets_accum(t - 1) 
       + cash_flow(t) 
       + hedge_cash_flow(t)
       + cash_flow_int(t)
       + inv_inc(t)
       - tax(t);

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.ANN_PBA_PBA.for"
if (t == start_period)
	return get_mth_from_date(proj_date);

return proj_start_mth + t - 1
	   - 12 * floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.ANN_PBA_PBA.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.ANN_PBA_PBA.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain
// Capital Gains                                                                                             
// Column:CAP_GAIN
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cap_gain(int t) {
//^^^



//^^^

#line 1 "cap_gain.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return seg->cap_gain(t)
       * reins_adj;

}


//@@ END

//@@ START - cash_flow
// Cash Flow                                                                                             
// Column:CASH_FLOW
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow(int t) {
//^^^



//^^^

#line 1 "cash_flow.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return direct_cash_flow(t)
       - reins_cash_flow(t);

}


//@@ END

//@@ START - cash_flow_int
// Cash Flow Interest                                                                                             
// Column:CASH_FLOW_INT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"cash_flow_int",t);
}



//^^^

#line 1 "cash_flow_int.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return direct_cash_flow_int(t)
       - reins_cash_flow_int(t);

}


//@@ END

//@@ START - cash_flow_rate_mthly
// Cash Flow Rate Monthly                                                                                             
// Column:CASH_FLOW_RATE_MTHLY
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow_rate_mthly(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"cash_flow_rate_mthly",t);
}



//^^^

#line 1 "cash_flow_rate_mthly.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->cash_flow_rate_mthly(t);

return asset_yld_mthly(t);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_date(int t) {
//^^^



//^^^

#line 1 "date.ANN_PBA_PBA.for"
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

//@@ START - def_accum
// Accumulated Deficiency                                                                                             
// Column:DEF_ACCUM
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_def_accum(int t) {
//^^^



//^^^

#line 1 "def_accum.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return (working_res(t) - reins_res(t))
	        - (assets_accum(t) + hedge_mkt_val(t));

// force calls for reporting
assets_accum(t);
	
return def_accum(t - 1)
       - direct_prof(t)
       + reins_cost(t)
       + hedge_cost(t);

}


//@@ END

//@@ START - direct_cap_gain
// Direct Capital Gains                                                                                             
// Column:DIRECT_CAP_GAIN
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_cap_gain(int t) {
//^^^



//^^^

#line 1 "direct_cap_gain.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return cap_gain(t) + reins_cap_gain(t);

}


//@@ END

//@@ START - direct_cash_flow
// Direct Cash Flow                                                                                             
// Column:DIRECT_CASH_FLOW
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_cash_flow(int t) {
//^^^



//^^^

#line 1 "direct_cash_flow.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->direct_cash_flow_bom(t) 
		   + seg->direct_cash_flow_eom(t);

#if defined(__FA_LIAB_H_)	
if (this == fa_ann_pba)
	return fa->direct_cash_flow_bom(t) 
    	   + fa->direct_cash_flow_eom(t);
#endif

#if defined(__FIA_LIAB_H_)	
if (this == fia_ann_pba)
	return fia->direct_cash_flow_bom(t) 
    	   + fia->direct_cash_flow_eom(t);
#endif

#if defined(__PA_LIAB_H_)	
if (this == pa_ann_pba)
	return pa->direct_cash_flow_bom(t) 
    	   + pa->direct_cash_flow_eom(t);
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - direct_cash_flow_int
// Direct Cash Flow Interest                                                                                             
// Column:DIRECT_CASH_FLOW_INT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"direct_cash_flow_int",t);
}



//^^^

#line 1 "direct_cash_flow_int.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->direct_cash_flow_bom(t) 
	       * cash_flow_rate_mthly(t);

#if defined(__FA_LIAB_H_)	
if (this == fa_ann_pba)
	return fa->direct_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif

#if defined(__FIA_LIAB_H_)	
if (this == fia_ann_pba)
	return fia->direct_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif

#if defined(__PA_LIAB_H_)	
if (this == pa_ann_pba)
	return pa->direct_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - direct_imr_incr
// Direct IMR Increase                                                                                             
// Column:DIRECT_IMR_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_imr_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"direct_imr_incr",t);
}



//^^^

#line 1 "direct_imr_incr.ANN_PBA_PBA.for"
if (!alm_flag || !imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return imr_incr(t) + reins_imr_incr(t);

}


//@@ END

//@@ START - direct_inv_inc
// Direct Investment Income                                                                                             
// Column:DIRECT_INV_INC
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_inv_inc(int t) {
//^^^



//^^^

#line 1 "direct_inv_inc.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)	
	return NO_AVG;

return inv_inc(t) + reins_inv_inc(t);

}


//@@ END

//@@ START - direct_prof
// Direct Profit                                                                                             
// Column:DIRECT_PROF
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_prof(int t) {
//^^^



//^^^

#line 1 "direct_prof.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return direct_cash_flow(t)
       + direct_cash_flow_int(t) 
       + direct_inv_inc(t)
       + direct_cap_gain(t)
       - direct_imr_incr(t)
	   - direct_res_incr(t)
	   - direct_tax(t);

}


//@@ END

//@@ START - direct_res_incr
// Direct Reserve Increase                                                                                             
// Column:DIRECT_RES_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_res_incr(int t) {
//^^^



//^^^

#line 1 "direct_res_incr.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return working_res(t) - working_res(t - 1);

}


//@@ END

//@@ START - direct_tax
// Direct Tax                                                                                             
// Column:DIRECT_TAX
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_direct_tax(int t) {
//^^^



//^^^

#line 1 "direct_tax.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax(t);

}


//@@ END

//@@ START - disc_rate_accum
// Discount Rate Accumulation                                                                                             
// Column:DISC_RATE_ACCUM
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_accum(int t) {
//^^^



//^^^

#line 1 "disc_rate_accum.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return 1.0;

return disc_rate_accum(t - 1)
       / disc_rate_mthly(t);

}


//@@ END

//@@ START - disc_rate_mthly
// Discount Rate Monthly                                                                                             
// Column:DISC_RATE_MTHLY
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_mthly(int t) {
//^^^



//^^^

#line 1 "disc_rate_mthly.ANN_PBA_PBA.for"
if (!pba_scen_amt_valn_flag && !res_det_res_valn_flag)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

if (rbc_scen_amt_valn_flag)
	{
	double tax_rate = 0.0;
	
	if (this == ann_pba)
		tax_rate = company->tax_rate;
	#if defined (__FA_LIAB_H_)
	else
		tax_rate = fa->tax_rate;
	#endif
	#if defined (__FIA_LIAB_H_)
	else
		tax_rate = fia->tax_rate;
	#endif
	#if defined (__PA_LIAB_H_)
	else
		tax_rate = pa->tax_rate;
	#endif
				
	double one_yr_scen_rate
	= rates->get_int_rate(t, "Govt", GET_YIELD_RATE, 1.0, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ 
	  * disc_rate_mult_fixed
	  * (1.0 - tax_rate);

	return pow(1.0 + one_yr_scen_rate, 1.0 / 12.0);
	}

if (res_scen_amt_valn_flag)
	{
	double one_yr_scen_rate
	= rates->get_int_rate(t, "Govt", GET_YIELD_RATE, 1.0, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0) //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	  * disc_rate_mult_fixed;
	
	return pow(1.0 + one_yr_scen_rate, 1.0 / 12.0);
	}
	
return NO_AVG;

}


//@@ END

//@@ START - eff_cap_gains_rate
// Effective Capital Gains Rate                                                                                             
// Column:EFF_CAP_GAINS_RATE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_eff_cap_gains_rate(int t) {
//^^^



//^^^

#line 1 "eff_cap_gains_rate.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (fabs(seg->inv_asset(t - 1)) < rate_ratio_threshold)
	return NO_AVG;

double cap_gain_rate 
= (seg->cap_gain(t) - imr_incr(t)) / seg->inv_asset(t - 1);
	
return max(cap_gain_rate, USLIB_MINIMUM_YIELD);

}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flow                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.ANN_PBA_PBA.for"
if (hedging_defn == UNHEDGED || t <= start_period || t > final_period)
	return NO_AVG;

return hedge_cash_flow_array[t];

}


//@@ END

//@@ START - hedge_cost
// Hedging Cost                                                                                             
// Column:HEDGE_COST
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedge_cost(int t) {
//^^^



//^^^

#line 1 "hedge_cost.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)	
	return NO_AVG;

return - (hedge_cash_flow(t)
          + hedge_mkt_val_incr(t));

}


//@@ END

//@@ START - hedge_mkt_val
// Hedge Market Value                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.ANN_PBA_PBA.for"
if (hedging_defn == UNHEDGED || t < start_period || t > final_period)
	return NO_AVG;

return hedge_mkt_val_array[t];

}


//@@ END

//@@ START - hedge_mkt_val_incr
// Hedge Market Value Increase                                                                                             
// Column:HEDGE_MKT_VAL_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_incr.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return hedge_mkt_val(t) - hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - hedging_e_factor
// Hedging e Factor                                                                                             
// Column:HEDGING_E_FACTOR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedging_e_factor(int t) {
//^^^



//^^^

#line 1 "hedging_e_factor.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return hedging_e_factor_stoch_res;

if (pba_code == STOCH_CAP)
	return hedging_e_factor_stoch_cap;

return 0.0;

}


//@@ END

//@@ START - imr
// IMR                                                                                             
// Column:IMR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_imr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"imr",t);
}



//^^^

#line 1 "imr.ANN_PBA_PBA.for"
if (!alm_flag || !imr_flag || t < start_period || t > final_period)
	return NO_AVG;

return seg->imr(t) 
       * pimr_adj_factor(t)
       * reins_adj;

}


//@@ END

//@@ START - imr_incr
// IMR Increase                                                                                             
// Column:IMR_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_imr_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"imr_incr",t);
}



//^^^

#line 1 "imr_incr.ANN_PBA_PBA.for"
if (!alm_flag || !imr_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return imr(t) - imr(t - 1);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.ANN_PBA_PBA.for"
return 0.0;

}


//@@ END

//@@ START - inv_inc
// Investment Income                                                                                             
// Column:INV_INC
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_inv_inc(int t) {
//^^^



//^^^

#line 1 "inv_inc.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)	
	return NO_AVG;

if (alm_flag)
	return seg->inv_inc_on_invested_assets(t)
	       * reins_adj;

return assets_accum(t - 1) * asset_yld_mthly(t);

}


//@@ END

//@@ START - pimr_adj_factor
// Pre Tax IMR Adjustment Factor                                                                                             
// Column:PIMR_ADJ_FACTOR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_pimr_adj_factor(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"pimr_adj_factor",t);
}



//^^^

#line 1 "pimr_adj_factor.ANN_PBA_PBA.for"
if (!alm_flag || tax_flag)
	return 1.0;

return 1.0 / (1.0 - company->tax_rate_cap_gain);

}


//@@ END

//@@ START - realzd_cap_gain
// Realized Capital Gain                                                                                             
// Column:REALZD_CAP_GAIN
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_realzd_cap_gain(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return seg->realzd_cap_gain(t)
       * reins_adj;

}


//@@ END

//@@ START - realzd_cap_gain_bef_sale
// Realized Capital Gain Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_BEF_SALE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_realzd_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_bef_sale.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return seg->realzd_cap_gain_bef_sale(t)
       * reins_adj;

}


//@@ END

//@@ START - reins_cap_gain
// Reinsurance Capital Gains                                                                                             
// Column:REINS_CAP_GAIN
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_cap_gain(int t) {
//^^^



//^^^

#line 1 "reins_cap_gain.ANN_PBA_PBA.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_res(t - 1) 
       * (pow(1.0 + eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);

}


//@@ END

//@@ START - reins_cash_flow
// Reinsurance Cash Flow                                                                                             
// Column:REINS_CASH_FLOW
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_cash_flow(int t) {
//^^^



//^^^

#line 1 "reins_cash_flow.ANN_PBA_PBA.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->reins_cash_flow_bom(t) 
    	   + seg->reins_cash_flow_eom(t);

#if defined(__FA_LIAB_H_)	
if (this == fa_ann_pba)
	return fa->reins_cash_flow_bom(t)
		   + fa->reins_cash_flow_eom(t);
#endif

#if defined(__FIA_LIAB_H_)	
if (this == fia_ann_pba)
	return fia->reins_cash_flow_bom(t)
		   + fia->reins_cash_flow_eom(t);
#endif

#if defined(__PA_LIAB_H_)	
if (this == pa_ann_pba)
	return pa->reins_cash_flow_bom(t)
		   + pa->reins_cash_flow_eom(t);
#endif
		
return NO_AVG;

}


//@@ END

//@@ START - reins_cash_flow_int
// Reinsurance Cash Flow Interest                                                                                             
// Column:REINS_CASH_FLOW_INT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"reins_cash_flow_int",t);
}



//^^^

#line 1 "reins_cash_flow_int.ANN_PBA_PBA.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->reins_cash_flow_bom(t)
		   * cash_flow_rate_mthly(t);

#if defined(__FA_LIAB_H_)		
if (this == fa_ann_pba)
	return fa->reins_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif
	
#if defined(__FIA_LIAB_H_)		
if (this == fia_ann_pba)
	return fia->reins_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif
	
#if defined(__PA_LIAB_H_)		
if (this == pa_ann_pba)
	return pa->reins_cash_flow_bom(t)
	       * cash_flow_rate_mthly(t);
#endif

return NO_AVG;

}


//@@ END

//@@ START - reins_cost
// Reinsurance Cost                                                                                             
// Column:REINS_COST
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_cost(int t) {
//^^^



//^^^

#line 1 "reins_cost.ANN_PBA_PBA.for"
if (!reins_flag || t <= start_period || t > final_period)	
	return NO_AVG;

return reins_cash_flow(t)
	   + reins_cash_flow_int(t)
	   + reins_inv_inc(t)
       + reins_cap_gain(t)
       - reins_imr_incr(t)
       - reins_res_incr(t);

}


//@@ END

//@@ START - reins_imr_incr
// Reinsurance IMR Increase                                                                                             
// Column:REINS_IMR_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_imr_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"reins_imr_incr",t);
}



//^^^

#line 1 "reins_imr_incr.ANN_PBA_PBA.for"
if (!alm_flag || !reins_flag || !imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (fabs(assets_accum(t - 1)) < model_point_amount_threshold)
	return 0.0;

return imr_incr(t) 
       * reins_res(t - 1)
       / assets_accum(t - 1);

}


//@@ END

//@@ START - reins_inv_inc
// Reinsurance Investment Income                                                                                             
// Column:REINS_INV_INC
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_inv_inc(int t) {
//^^^



//^^^

#line 1 "reins_inv_inc.ANN_PBA_PBA.for"
if (!reins_flag || t <= start_period || t > final_period)	
	return NO_AVG;

return reins_res(t - 1) * asset_yld_mthly(t);

}


//@@ END

//@@ START - reins_res
// Reinsurance Reserve                                                                                             
// Column:REINS_RES
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_res(int t) {
//^^^



//^^^

#line 1 "reins_res.ANN_PBA_PBA.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	{
	if (working_res_defn == ZERO)
		return 0.0;

	return sum_over_pba("reins_res", t);
	}

return working_res(t) 
       * reins_pct;

}


//@@ END

//@@ START - reins_res_incr
// Reinsurance Reserve Increase                                                                                             
// Column:REINS_RES_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_res_incr(int t) {
//^^^



//^^^

#line 1 "reins_res_incr.ANN_PBA_PBA.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_res(t)
       - reins_res(t - 1);

}


//@@ END

//@@ START - reins_tax_res
// Reinsurance Tax Res                                                                                             
// Column:REINS_TAX_RES
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_tax_res(int t) {
//^^^



//^^^

#line 1 "reins_tax_res.ANN_PBA_PBA.for"
if (!tax_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (tax_defn_stoch_cap == USE_WORKING_RESERVE)
	return reins_res(t);
	
// if (tax_defn_stoch_cap == CALCULATE_TAX_RESERVE)
if (this == ann_pba)
	return seg->reins_tax_res_mp(t);

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return fa->reins_tax_res_mp(t);	
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return fia->reins_tax_res_mp(t);	
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return pa->reins_tax_res_mp(t);	
#endif

return NO_AVG;

}


//@@ END

//@@ START - reins_tax_res_incr
// Reinsurance Tax Reserve Increase                                                                                             
// Column:REINS_TAX_RES_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"reins_tax_res_incr",t);
}



//^^^

#line 1 "reins_tax_res_incr.ANN_PBA_PBA.for"
if (!tax_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_tax_res(t)
	   - reins_tax_res(t - 1);

}


//@@ END

//@@ START - scen_amt
// Scenario Amount                                                                                             
// Column:SCEN_AMT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_scen_amt(int t) {
//^^^



//^^^

#line 1 "scen_amt.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (hedging_defn == HEDGED)
	get_hedge_items();

for (int tt = 0; tt <= final_period; tt++)
	def_accum(tt);

return scen_greatest_pv(start_period)
       + starting_assets(start_period);

}


//@@ END

//@@ START - scen_greatest_pv
// Scenario Greatest Present Value                                                                                             
// Column:SCEN_GREATEST_PV
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_scen_greatest_pv(int t) {
//^^^



//^^^

#line 1 "scen_greatest_pv.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == final_period)
	{
	scen_greatest_pv_period = t;
	
	return def_accum(t);
	}

// force call disc_rate_accum
disc_rate_accum(t + 1);

double scen_greatest_pv = 0.0;
	
if (t % 12 == 0)
	{
	scen_greatest_pv 
	= max(def_accum(t), this->scen_greatest_pv(t + 1) / disc_rate_mthly(t + 1));
	
	if (def_accum(t) > (this->scen_greatest_pv(t + 1) / disc_rate_mthly(t + 1)))
		scen_greatest_pv_period = t;
	}	
else
	scen_greatest_pv = this->scen_greatest_pv(t + 1) / disc_rate_mthly(t + 1);

return scen_greatest_pv;

}


//@@ END

//@@ START - starting_assets
// Starting Assets                                                                                             
// Column:STARTING_ASSETS
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_starting_assets(int t) {
//^^^



//^^^

#line 1 "starting_assets.ANN_PBA_PBA.for"
if (t != start_period)
	return NO_AVG;

if (this == ann_pba)
	{
	if (alm_flag)
		return hedge_mkt_val(t)
           	   + (seg->cash(t) 
                  + seg->borrowing(t) 
	              + seg->bk_val(t) 
    	          + seg->accr_int(t)
        	      - seg->imr(t)
				    * pimr_adj_factor(t))
                * reins_adj;

	return hedge_mkt_val(t)
    	   + init_assets 
             * init_asset_pct
             * reins_adj;
	}

return hedge_mkt_val(t)
       + init_assets 
         * init_asset_pct
         * reins_adj;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double ANN_PBA_PBA_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.ANN_PBA_PBA.for"
#if 0 // START_EXTERNS
deptaskinput ann_pba_scen_amt_valn_input;
deptaskcols ann_pba_scen_amt_valn_input_cols;
deptaskmap ann_pba_scen_amt_valn_input_pos;
deptaskmapiter ann_pba_scen_amt_valn_input_pos_iter;
const int SCEN_AMT = 0;
const int TAX_AVG_RATIO = 1;
#endif // END_EXTERNS

#if 0 // START_CLASS
//typedef map <int, long, less <int> > mpmap; //Gen2 - 9/6/2024 - comment out typedef
int scen_greatest_pv_period;
double init_assets;
double init_asset_pct;
SmartArray <double> hedge_cash_flow_array;
SmartArray <double> hedge_mkt_val_array;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
init_assets = 0.0;
init_asset_pct = 1.0;
scen_greatest_pv_period = -1;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
#endif // END_TERMINATOR

// Set hidden variables equal to input variables
//res_cap_calc_defn = xstring(res_cap_calc_defn_input);
//reins_defn = xstring(reins_defn_input);
//hedging_defn = xstring(hedging_defn_input);

//WTW - Gen2 - removed xstring casting
res_cap_calc_defn = res_cap_calc_defn_input;
reins_defn = reins_defn_input;
hedging_defn = hedging_defn_input;

// Initialize class variables equal to input variables
init_assets = init_assets_input;
init_asset_pct = init_asset_pct_input;

if (valn_flag)
	scen_greatest_pv_period = last_proj_period;

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	{
	t_low = min(0, start_period);	 
	t_high = fa->maturity_period;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	{
	t_low = min(0, start_period);	 
	t_high = fia->maturity_period;
	}
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	{
	t_low = min(0, start_period);	 
	t_high = pa->maturity_period;
	}
#endif
		
return 0.0;

}


//@@ END

//@@ START - stoch_amt
// Stochastic Amount                                                                                             
// Column:STOCH_AMT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_stoch_amt(int t) {
//^^^



//^^^

#line 1 "stoch_amt.ANN_PBA_PBA.for"
if (t != start_period)
	return NO_AVG;	

//SmartArray <SmartArray <double> > scen_amt_array;
vector <vector <double> > scen_amt_array;//WTW - Gen2

xstring file_name = xstring(replaceWildcards(valn_results_scen_amt));

static int proj_task_loops = -1;

// Only read the file if the file name has changed since the last read
static xstring file_name_read = "NONE";
bool read_file = true;
if (eq(file_name, file_name_read))
	read_file = false;

if (read_file)
	{
	ann_pba_scen_amt_valn_input_cols.clear();
	ann_pba_scen_amt_valn_input.clear();

	file_name_read = file_name;

	//string database_name = working_directory() + "ann_pba_stoch_amt.db";
	xstring database_name = working_directory() + "ann_pba_stoch_amt.db";
	openDatabase(database_name.getStdStr());//WTW - Gen2 - add ".getStdStr()"
	string table_name = readCsvFile(file_name.getStdStr());

	// Determine the number of projection task loops in valuation result file
	xstring sql = (xstring)"SELECT DISTINCT _task_loop AS vloop, "
	              + (xstring)"CAST(_period AS INTEGER) AS vperiod"
	              + " FROM '"
	              + table_name
	              + (xstring)"' WHERE vperiod == 0 "
				  + (xstring)"AND _time NOT LIKE 'PV%' AND _time NOT LIKE 'IRR%'";

	deptaskinput proj_task_loop_results;
	deptaskcols proj_task_loop_cols;

	executeQuery(sql.getStdStr(), proj_task_loop_cols, proj_task_loop_results);

	if (!proj_task_loop_cols.size())
		{
		throw FatalError("Could not read scenario amount valuation file: " 
			              + file_name + " "
			              + "Please check your data.");
		}

	proj_task_loops = proj_task_loop_results.size();

	// Retrieve valuation results
	sql = (xstring)"SELECT TRIM(_group) AS vgroup, "
	       + (xstring)"CAST(_period AS INTEGER) AS vperiod, _working_res, _reins_res, _scen_amt, _tax_adj_ratio"
	       + (xstring)" FROM '" 
	       + table_name 
		   + (xstring)"' WHERE vperiod == 0 "
		   + (xstring)"AND _time NOT LIKE 'PV%' AND _time NOT LIKE 'IRR%'"
		   + (xstring)" ORDER BY vgroup";

	executeQuery(sql.getStdStr(), ann_pba_scen_amt_valn_input_cols, ann_pba_scen_amt_valn_input);
	closeDatabase();
	remove(database_name.c_str());

	if (!ann_pba_scen_amt_valn_input_cols.size())
		{
		throw FatalError("Could not read scenario amount valuation file: " 
			              + file_name + " "
			              + "Please check your data.");
		}

	// Create map of group start positions, group is column 0 of query results
	ann_pba_scen_amt_valn_input_pos[xstring(ann_pba_scen_amt_valn_input[0][0])] = 0;

	for (int row = 1; row < ann_pba_scen_amt_valn_input.size(); row++)
		{
		if (!eq(ann_pba_scen_amt_valn_input[row][0], ann_pba_scen_amt_valn_input[row - 1][0]))
			ann_pba_scen_amt_valn_input_pos[ann_pba_scen_amt_valn_input[row][0]] = row;
		}
	}

xstring group_name = "";

#if defined(__FA_LIAB_H_)
if (fa->isMainModel && pricing_flag)
	group_name = fa->mp_id
	             + "|"
	             + res_cap_calc_defn 
	             + "|" 
    	         + reins_defn
			     + "|" 
			     + hedging_defn;
else
#endif
#if defined(__FIA_LIAB_H_)
if (fia->isMainModel && pricing_flag)
	group_name = fia->mp_id
	             + "|"
	             + res_cap_calc_defn 
	             + "|" 
    	         + reins_defn
			     + "|" 
			     + hedging_defn;
else
#endif
#if defined(__PA_LIAB_H_)
if (pa->isMainModel && pricing_flag)
	group_name = pa->mp_id
	             + "|"
	             + res_cap_calc_defn 
	             + "|" 
    	         + reins_defn
			     + "|" 
			     + hedging_defn;
else
#endif
	group_name = seg_id
				 + "|"
				 + res_cap_calc_defn
	             + "|" 
    	         + reins_defn
			     + "|" 
			     + hedging_defn;

if (hedging_defn == HEDGED)
	group_name = group_name + "|" + hedging_cash_flow_defn;

if (proj_task_loops == 0)
	return NO_AVG;

double init_working_res = 0.0;
double init_reins_res = 0.0;
scen_amt_array.resize(2);
scen_amt_array[0].resize(proj_task_loops);
scen_amt_array[1].resize(proj_task_loops);

// Find group start position
int ann_pba_scen_amt_valn_input_row = 0;
if ((ann_pba_scen_amt_valn_input_pos_iter 
     = ann_pba_scen_amt_valn_input_pos.find(group_name)) != ann_pba_scen_amt_valn_input_pos.end())
	ann_pba_scen_amt_valn_input_row = ann_pba_scen_amt_valn_input_pos_iter->second;

int proj_task_loop = 0;
for (int row = ann_pba_scen_amt_valn_input_row; row < ann_pba_scen_amt_valn_input_row + proj_task_loops; row++)
	{
	proj_task_loop++;

	// Only need to get working reserve and reinsurance reserve one time
	if (row == ann_pba_scen_amt_valn_input_row)
		{
		init_working_res = atof(ann_pba_scen_amt_valn_input[row][2].c_str()); 
		init_reins_res = atof(ann_pba_scen_amt_valn_input[row][3].c_str()); 
		}

	scen_amt_array[SCEN_AMT][proj_task_loop - 1] = atof(ann_pba_scen_amt_valn_input[row][4].c_str());
	scen_amt_array[TAX_AVG_RATIO][proj_task_loop - 1] = atof(ann_pba_scen_amt_valn_input[row][5].c_str());
	}

double cte_amt = 0.0;
double tax_avg_ratio = 0.0;
double init_tax_res = 0.0;
double reins_tax_res = 0.0;

cte_calc(scen_amt_array, cte_pct, cte_amt, tax_avg_ratio);

double tax_res_adj = 0.0;

if (res_cap_calc_defn == CAPITAL && tax_defn_stoch_cap == USE_WORKING_RESERVE)
	{ // Adjust working reserve and tax reserve to be on consistent/requested basis
	double tax_rate = 0.0;

	if (this == ann_pba)
		{
		tax_rate = company->tax_rate;
		init_tax_res = seg->tax_res(t);
		reins_tax_res = seg->reins_tax_res(t);
		}
	#if defined(__FA_LIAB_H_)
	else if (this == fa_ann_pba)
		{
		tax_rate = fa->tax_rate;
		init_tax_res = fa->tax_res(t);
		reins_tax_res = fa->reins_tax_res(t);
		}
	#endif
	#if defined(__FIA_LIAB_H_)
	else if (this == fia_ann_pba)
		{
		tax_rate = fia->tax_rate;
		init_tax_res = fia->tax_res(t);
		reins_tax_res = fia->reins_tax_res(t);
		}
	#endif
	#if defined(__PA_LIAB_H_)
	else if (this == pa_ann_pba)
		{
		tax_rate = pa->tax_rate;
		init_tax_res = pa->tax_res(t);
		reins_tax_res = pa->reins_tax_res(t);
		}
	#endif

	if (reins_defn == GROSS)
		tax_res_adj 
		= (init_working_res - init_tax_res) 
		  * tax_rate 
		  * (1.0 - tax_avg_ratio);
	else // reins_defn == NET
		tax_res_adj 
		= ((init_working_res - init_reins_res)
		    - (init_tax_res - reins_tax_res))
		  * tax_rate 
		  * (1.0 - tax_avg_ratio);
	}

return cte_amt + tax_res_adj;

}


//@@ END

//@@ START - tax
// Tax                                                                                             
// Column:TAX
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax(int t) {
//^^^



//^^^

#line 1 "tax.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (t % 12 == 1)
	return tax_ytd(t);

return tax_ytd(t) - tax_ytd(t - 1);

}


//@@ END

//@@ START - tax_adj_ratio
// Tax Adjustment Ratio                                                                                             
// Column:TAX_ADJ_RATIO
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_adj_ratio(int t) {
//^^^



//^^^

#line 1 "tax_adj_ratio.ANN_PBA_PBA.for"
if (!tax_flag || t < start_period || t > final_period)
	return NO_AVG;

if (t == scen_greatest_pv_period)
	{
	if (this == ann_pba)
		{
		if (fabs(seg->sum_over_liabilities("policies_b", 1))
		    < rate_ratio_threshold)
			return 0.0;
					
		return seg->sum_over_liabilities("policies_inf", t) 
				/ seg->sum_over_liabilities("policies_b", 1);
		}

	#if defined(__FA_LIAB_H_)
	if (fabs(fa->policies_b(1)) < rate_ratio_threshold)
		return 0.0;

	return fa->policies_inf(t)
	       / fa->policies_b(1);
	#endif

	#if defined(__FIA_LIAB_H_)
	if (fabs(fia->policies_b(1)) < rate_ratio_threshold)
		return 0.0;

	return fia->policies_inf(t)
	       / fia->policies_b(1);
	#endif

	#if defined(__PA_LIAB_H_)
	if (fabs(pa->policies_b(1)) < rate_ratio_threshold)
		return 0.0;

	return pa->policies_inf(t)
	       / pa->policies_b(1);
	#endif
	}
	
return tax_adj_ratio(t + 1);

}


//@@ END

//@@ START - tax_capzd_prem
// Tax Capitalized Premium                                                                                             
// Column:TAX_CAPZD_PREM
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(52,"tax_capzd_prem",t);
}



//^^^

#line 1 "tax_capzd_prem.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->tax_capzd_prem(t);
	
#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return fa->tax_capzd_prem(t);
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return fia->tax_capzd_prem(t);
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return pa->tax_capzd_prem(t);
#endif

return NO_AVG;

}


//@@ END

//@@ START - tax_capzd_prem_amortzn
// Tax Capitalized Premium Amortization                                                                                             
// Column:TAX_CAPZD_PREM_AMORTZN
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem_amortzn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(53,"tax_capzd_prem_amortzn",t);
}



//^^^

#line 1 "tax_capzd_prem_amortzn.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return seg->tax_capzd_prem_amortzn(t);

int proj_mth_adj = get_mth_from_date(proj_date);
int proj_start_mth_adj = proj_mth_adj == 12 ? 1: proj_mth_adj + 1;
int cal_yr_relative_adj = 1 + floor((proj_start_mth_adj + (t + valn_period) - 2) / 12.0);

double from_current_capzd = 0.0;
double from_capzd_aft_proj_date = 0.0;

// First year amortization occurs in the month of capitalization
if (tax_capzd_prem_amortzn_yrs > 0)
	from_current_capzd 
	= tax_capzd_prem(t) 
	  / (2.0 * tax_capzd_prem_amortzn_yrs);

// Amounts capitalized during the projection are amortized using the temporary table schedule
#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	from_capzd_aft_proj_date 
	= fa->tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj) / 12.0;
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	from_capzd_aft_proj_date 
	= fia->tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj) / 12.0;
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	from_capzd_aft_proj_date 
	= pa->tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj) / 12.0;
#endif

return from_current_capzd
       + from_capzd_aft_proj_date;

}


//@@ END

//@@ START - tax_cash_flow
// Tax Cash Flow                                                                                             
// Column:TAX_CASH_FLOW
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_cash_flow(int t) {
//^^^



//^^^

#line 1 "tax_cash_flow.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (!seg->pba_tax_flag && !tax_flag)
	return 0.0;

if (t % 12 == 1)
	return tax_ytd(t);

return tax_ytd(t) - tax_ytd(t - 1);

}


//@@ END

//@@ START - tax_cash_flow_bef_sale
// Tax Cash Flow Before Sales                                                                                             
// Column:TAX_CASH_FLOW_BEF_SALE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_cash_flow_bef_sale(int t) {
//^^^



//^^^

#line 1 "tax_cash_flow_bef_sale.ANN_PBA_PBA.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (!seg->pba_tax_flag && !tax_flag)
	return 0.0;

if (t % 12 == 1)
	return tax_ytd_bef_sale(t);

return tax_ytd_bef_sale(t) - tax_ytd(t - 1);

}


//@@ END

//@@ START - tax_res
// Tax Res                                                                                             
// Column:TAX_RES
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_res(int t) {
//^^^



//^^^

#line 1 "tax_res.ANN_PBA_PBA.for"
if (!tax_flag || t < start_period || t > final_period)
	return NO_AVG;

if (tax_defn_stoch_cap == USE_WORKING_RESERVE)
	return working_res(t);
	
// if (tax_defn_stoch_cap == CALCULATE_TAX_RESERVE)
if (this == ann_pba)
	return seg->tax_res_mp(t);

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return fa->tax_res_mp(t);	
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return fia->tax_res_mp(t);	
#endif	

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return pa->tax_res_mp(t);	
#endif	

return NO_AVG;

}


//@@ END

//@@ START - tax_res_incr
// Tax Reserve Increase                                                                                             
// Column:TAX_RES_INCR
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"tax_res_incr",t);
}



//^^^

#line 1 "tax_res_incr.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_res(t)
	   - tax_res(t - 1);

}


//@@ END

//@@ START - tax_ytd
// Tax Year to Date                                                                                             
// Column:TAX_YTD
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_ytd(int t) {
//^^^



//^^^

#line 1 "tax_ytd.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return taxable_inc_ytd(t) * company->tax_rate;

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)	
	return taxable_inc_ytd(t) * fa->tax_rate;
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)	
	return taxable_inc_ytd(t) * fia->tax_rate;
#endif	

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)	
	return taxable_inc_ytd(t) * pa->tax_rate;
#endif	
	
return NO_AVG;

}


//@@ END

//@@ START - tax_ytd_bef_sale
// Tax Year to Date Before Sales                                                                                             
// Column:TAX_YTD_BEF_SALE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_tax_ytd_bef_sale(int t) {
//^^^



//^^^

#line 1 "tax_ytd_bef_sale.ANN_PBA_PBA.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	return taxable_inc_ytd_bef_sale(t) 
           * company->tax_rate;

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)	
	return taxable_inc_ytd_bef_sale(t) 
	       * fa->tax_rate;
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)	
	return taxable_inc_ytd_bef_sale(t) 
	       * fia->tax_rate;
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)	
	return taxable_inc_ytd_bef_sale(t) 
	       * pa->tax_rate;
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - taxable_inc
// Taxable Income                                                                                             
// Column:TAXABLE_INC
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc(int t) {
//^^^



//^^^

#line 1 "taxable_inc.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return cash_flow(t)
       + hedge_cash_flow(t)
       + cash_flow_int(t) 
       + inv_inc(t)
       + realzd_cap_gain(t)
       + tax_capzd_prem(t)
       - tax_capzd_prem_amortzn(t)  
       - tax_res_incr(t)
       + reins_tax_res_incr(t);

}


//@@ END

//@@ START - taxable_inc_bef_sale
// Taxable Income Before Sales                                                                                             
// Column:TAXABLE_INC_BEF_SALE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_bef_sale(int t) {
//^^^



//^^^

#line 1 "taxable_inc_bef_sale.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return cash_flow(t)
       + hedge_cash_flow(t)
       + cash_flow_int(t)
       + inv_inc(t)
       + realzd_cap_gain_bef_sale(t)
       + tax_capzd_prem(t)
       - tax_capzd_prem_amortzn(t)
       - tax_res_incr(t)
       + reins_tax_res_incr(t);

}


//@@ END

//@@ START - taxable_inc_ytd
// Taxable Income Year to Date                                                                                             
// Column:TAXABLE_INC_YTD
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_ytd(int t) {
//^^^



//^^^

#line 1 "taxable_inc_ytd.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (t % 12 == 1)
	return taxable_inc(t);
  
return taxable_inc_ytd(t - 1) 
	   + taxable_inc(t);

}


//@@ END

//@@ START - taxable_inc_ytd_bef_sale
// Taxable Income Year to Date Before Sales                                                                                             
// Column:TAXABLE_INC_YTD_BEF_SALE
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_ytd_bef_sale(int t) {
//^^^



//^^^

#line 1 "taxable_inc_ytd_bef_sale.ANN_PBA_PBA.for"
if (!tax_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (t % 12 == 1)
	return taxable_inc_bef_sale(t);
  
return taxable_inc_ytd(t - 1) 
	   + taxable_inc_bef_sale(t);

}


//@@ END

//@@ START - working_res
// Working Reserve                                                                                             
// Column:WORKING_RES
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_working_res(int t) {
//^^^



//^^^

#line 1 "working_res.ANN_PBA_PBA.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == ann_pba)
	{
	if (working_res_defn == ZERO)
		return 0.0;

	return sum_over_pba("working_res", t);
	}

#if defined(__FA_LIAB_H_)	
if (this == fa_ann_pba)
	{
	if (pricing_flag && working_res_defn == ZERO)
		return 0.0;

	return fa->cash_val(t);
	}
#endif

#if defined(__FIA_LIAB_H_)	
if (this == fia_ann_pba)
	{
	if (pricing_flag && working_res_defn == ZERO)
		return 0.0;

	return fia->cash_val(t);
	}
#endif

return 0.0;

}


//@@ END

//@@ START - cte_pct
// CTE Percentage                                                                                             
// Calculated Variable:CTE_PCT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_cte_pct() {
//^^^


#line 1 "cte_pct.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return 0.7;

if (pba_code == STOCH_CAP)
	return cte_pct_stoch_cap;

return 0.0;

}


//@@ END

//@@ START - disc_rate_mult_fixed
// Discount Scenario Rate Multiple                                                                                             
// Calculated Variable:DISC_RATE_MULT_FIXED
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_mult_fixed() {
//^^^


#line 1 "disc_rate_mult_fixed.ANN_PBA_PBA.for"
// Multiple is specified as 105% of the 1 year treasury
return 1.05;

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_final_period() {
//^^^


#line 1 "final_period.ANN_PBA_PBA.for"
#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return min(fa->maturity_period, last_proj_period);
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return min(fia->maturity_period, last_proj_period);
#endif	
	
#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return min(pa->maturity_period, last_proj_period);
#endif	
	
return last_proj_period;

}


//@@ END

//@@ START - hedging_flag
// Hedging Flag                                                                                             
// Calculated Variable:HEDGING_FLAG
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_hedging_flag() {
//^^^


#line 1 "hedging_flag.ANN_PBA_PBA.for"
if (hedging_defn == UNHEDGED)
	return 0;

xstring hedge_file;

if (hedging_cash_flow_defn == BEST_ESTIMATE)
	hedge_file = replaceWildcards(xstring(hedging_output_file_best_estimate));
else // hedging_cash_flow_defn == EXISTING
	hedge_file = replaceWildcards(xstring(hedging_output_file_existing_hedges));

// if hedge file is found, then hedging is processed.
struct stat buffer;
int stat_val;
stat_val = stat(hedge_file.c_str(), &buffer);

// Hedge file exists, return 1
if (stat_val == 0)
	return 1;

// else, no hedging processed
return 0;

}


//@@ END

//@@ START - hedging_output_file_best_estimate
// Hedging Output File Best Estimate                                                                                             
// Calculated Variable:HEDGING_OUTPUT_FILE_BEST_ESTIMATE
//========================================================
xstring ANN_PBA_PBA_UDF::ann_pba_pba_hedging_output_file_best_estimate() {
//^^^


#line 1 "hedging_output_file_best_estimate.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return hedging_output_file_best_estimate_stoch_res;

if (pba_code == STOCH_CAP)
	return hedging_output_file_best_estimate_stoch_cap;

return "NONE";

}


//@@ END

//@@ START - hedging_output_file_existing_hedges
// Hedging Output File Existing Hedges                                                                                             
// Calculated Variable:HEDGING_OUTPUT_FILE_EXISTING_HEDGES
//========================================================
xstring ANN_PBA_PBA_UDF::ann_pba_pba_hedging_output_file_existing_hedges() {
//^^^


#line 1 "hedging_output_file_existing_hedges.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return hedging_output_file_existing_hedges_stoch_res;

if (pba_code == STOCH_CAP)
	return hedging_output_file_existing_hedges_stoch_cap;

return "NONE";

}


//@@ END

//@@ START - hedging_stat_scale_factor_max
// Hedging Statutory Scale Factor Max                                                                                             
// Calculated Variable:HEDGING_STAT_SCALE_FACTOR_MAX
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_hedging_stat_scale_factor_max() {
//^^^


#line 1 "hedging_stat_scale_factor_max.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return hedging_stat_scale_factor_max_stoch_res;

if (pba_code == STOCH_CAP)
	return hedging_stat_scale_factor_max_stoch_cap;

return 1.0;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring ANN_PBA_PBA_UDF::ann_pba_pba_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.ANN_PBA_PBA.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_date() {
//^^^


#line 1 "proj_start_date.ANN_PBA_PBA.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.ANN_PBA_PBA.for"
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
int ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.ANN_PBA_PBA.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - reins_adj
// Reinsurance Adjustment                                                                                             
// Calculated Variable:REINS_ADJ
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_adj() {
//^^^


#line 1 "reins_adj.ANN_PBA_PBA.for"
if (reins_gross_up_defn == NO || reins_defn == NET 
	|| fabs(reins_pct) <= rate_ratio_threshold)
	return 1.0;
	
return 1.0 / (1.0 - reins_pct);

}


//@@ END

//@@ START - reins_flag
// Reinsurance Flag                                                                                             
// Calculated Variable:REINS_FLAG
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_reins_flag() {
//^^^


#line 1 "reins_flag.ANN_PBA_PBA.for"
if (reins_defn == GROSS)
	return 0;
	
if (this == ann_pba)
	{
	if (seg->reins_flag)
		return 1;
	}					

#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	{
	if (fa->reins_flag)
		return 1;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	{
	if (fia->reins_flag)
		return 1;
	}
#endif

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	{
	if (pa->reins_flag)
		return 1;
	}
#endif

return 0;

}


//@@ END

//@@ START - reins_pct
// Reinsurance Percent                                                                                             
// Calculated Variable:REINS_PCT
//========================================================
double ANN_PBA_PBA_UDF::ann_pba_pba_reins_pct() {
//^^^


#line 1 "reins_pct.ANN_PBA_PBA.for"
double num = 0.0;
double denom = 0.0;
	
if (this == ann_pba)
	{
	#if defined(__FA_LIAB_H_)
	num = seg->sum_over_liabilities("reins_dth_ben_inf", 0);
	denom = seg->sum_over_liabilities("dth_ben_inf", 0);
	#endif

	#if defined(__FIA_LIAB_H_)
	num = seg->sum_over_liabilities("reins_dth_ben_inf", 0);
	denom = seg->sum_over_liabilities("dth_ben_inf", 0);
	#endif

	#if defined(__PA_LIAB_H_)
	num = seg->sum_over_liabilities("reins_dth_ben_inf", 0);
	denom = seg->sum_over_liabilities("dth_ben_inf", 0);
	#endif

	if (denom > 0.0)
		return num / denom;
	}					

#if defined (__FA_LIAB_H_)
if (this == fa_ann_pba)
	{
	if (fa->reins_flag)
		return fa->reins_pct;
	}
#endif

#if defined (__FIA_LIAB_H_)
if (this == fia_ann_pba)
	{
	if (fia->reins_flag)
		return fia->reins_pct;
	}
#endif

#if defined (__PA_LIAB_H_)
if (this == pa_ann_pba)
	{
	if (pa->reins_flag)
		return pa->reins_pct;
	}
#endif

return 0;

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_start_period() {
//^^^


#line 1 "start_period.ANN_PBA_PBA.for"
return 0;

}


//@@ END

//@@ START - tax_capzd_prem_amortzn_yrs
// Tax Capitalized Premium Amortization Years                                                                                             
// Calculated Variable:TAX_CAPZD_PREM_AMORTZN_YRS
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem_amortzn_yrs() {
//^^^


#line 1 "tax_capzd_prem_amortzn_yrs.ANN_PBA_PBA.for"
if (this == ann_pba)
	return seg->tax_capzd_prem_amortzn_yrs;
	
#if defined(__FA_LIAB_H_)
if (this == fa_ann_pba)
	return fa->tax_capzd_prem_amortzn_yrs;
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_ann_pba)
	return fia->tax_capzd_prem_amortzn_yrs;
#endif	

#if defined(__PA_LIAB_H_)
if (this == pa_ann_pba)
	return pa->tax_capzd_prem_amortzn_yrs;
#endif

return 10;

}


//@@ END

//@@ START - tax_flag
// Tax Flag                                                                                             
// Calculated Variable:TAX_FLAG
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_tax_flag() {
//^^^


#line 1 "tax_flag.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return 0;
	
return 1;

}


//@@ END

//@@ START - valn_results_scen_amt
// Valuation Results Scenario Amounts                                                                                             
// Calculated Variable:VALN_RESULTS_SCEN_AMT
//========================================================
xstring ANN_PBA_PBA_UDF::ann_pba_pba_valn_results_scen_amt() {
//^^^


#line 1 "valn_results_scen_amt.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return valn_results_stoch_res;

if (pba_code == STOCH_CAP)
	return valn_results_stoch_cap;
	
return "NONE";

}


//@@ END

//@@ START - working_res_defn
// Working Reserve Definition                                                                                             
// Calculated Variable:WORKING_RES_DEFN
//========================================================
int ANN_PBA_PBA_UDF::ann_pba_pba_working_res_defn() {
//^^^


#line 1 "working_res_defn.ANN_PBA_PBA.for"
if (pba_code == STOCH_RES)
	return ZERO;

if (pba_code == STOCH_CAP)
	return CASH_VALUE;

return ZERO;

}


//@@ END


#line 1 "get_hedge_items.ANN_PBA_PBA.for"                                                                                   
void ANN_PBA_PBA::get_hedge_items(void)
{
if (hedge_cash_flow_array.size() < final_period + 1)
	{
	hedge_cash_flow_array.resize(final_period + 1);
	hedge_mkt_val_array.resize(final_period + 1);
	}

xstring hedge_file;
deptaskcols hedging_input_cols;
deptaskinput hedging_input;

if (hedging_cash_flow_defn == BEST_ESTIMATE)
	hedge_file = replaceWildcards(xstring(hedging_output_file_best_estimate));
else // hedging_cash_flow_defn == EXISTING
	hedge_file = replaceWildcards(xstring(hedging_output_file_existing_hedges));	

//string database_name = working_directory() + "ann_pba_get_hedge_items.db";//WTW - Gen2 - add ".getStdStr()"
xstring database_name = working_directory() + "ann_pba_get_hedge_items.db";//WTW - Gen2 - add ".getStdStr()"
openDatabase(database_name.getStdStr());//WTW - Gen2 - add ".getStdStr()"
string table_name = readCsvFile(hedge_file.getStdStr());

// Retrieve valuation results
xstring sql = (xstring)"SELECT _fund_val, _cash_flow, _mkt_val FROM '"
	          + table_name
	          + (xstring)"' WHERE _task_loop == " + proj_task_loop_num;

executeQuery(sql.getStdStr(), hedging_input_cols, hedging_input);
closeDatabase();
remove(database_name.c_str());

if (!hedging_input_cols.size())
	{
	throw FatalError("Could not read hedge valuation file: " 
		              + hedge_file + " "
		              + "Please check your data.");
	}

double scale_factor = 0.0;
double scale_factor_previous = 0.0;
double hedge_cash_flow_cumul = 0.0;

for (int i = 0; i <= final_period; i++)
	{
	double fund_val_hedge = atof(hedging_input[i][0].c_str());
	double fund_val = 0.0;

	if (this == ann_pba)
		fund_val = seg->sum_over_liabilities("fund_val_fixed", i);
	#if defined(__FA_LIAB_H_)
	else if (this == fa_ann_pba)
		fund_val = fa->fund_val_fixed(i);
	#endif
	#if defined(__FIA_LIAB_H_)
	else if (this == fia_ann_pba)
		fund_val = fia->fund_val_fixed(i);
	#endif

	if (fund_val_hedge < model_point_amount_threshold)
		scale_factor = 0.0;
	else
		scale_factor
		= fund_val / fund_val_hedge;
		
	scale_factor = min(scale_factor, hedging_stat_scale_factor_max);

	if (i == 0)
		hedge_mkt_val_array[i] = atof(hedging_input[i][2].c_str()) * scale_factor;
	else
		{
		hedge_cash_flow_array[i] = atof(hedging_input[i][1].c_str()) * scale_factor_previous;
		hedge_mkt_val_array[i] = atof(hedging_input[i][2].c_str()) * scale_factor;
		}

	scale_factor_previous = scale_factor;
	}

return;
}



#line 1 "sum_over_pba.ANN_PBA_PBA.for"                                                                                   
double ANN_PBA_PBA::sum_over_pba(const xstring &colname, int t)
{ 
double total = 0.0;
int mp = 0;
int colnum = 0;
map <int, long, less <int> >::iterator mp_map_iter;//Gen2 - 9/6/2024 - replace mpmap with full definition

#if defined(__FA_LIAB_H_)
if (seg->fa_mp_map.size())
	{
	FA_LIAB *current_fa_element;
	colnum = liab->sm_fa[0]->sm_fa_ann_pba[0]->Column(colname).Number();
	
	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->fa_mp_map.begin();
		     mp_map_iter != seg->fa_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_fa_element = liab->sm_fa[mp];

			if (t < current_fa_element->commencement_period
				|| t > current_fa_element->maturity_period)
				continue;

			// Skip new issue commencement period
			if (current_fa_element->elapsed_mths <= 0
				&& t == current_fa_element->commencement_period)
				continue;

			if (t != current_fa_element->commencement_period
				&& fabs(current_fa_element->policies_b(t)) < rate_ratio_threshold)
				continue;

			total += current_fa_element->sm_fa_ann_pba[0]->Column(colnum).Value(t);
			}
		}
	}
#endif

#if defined(__FIA_LIAB_H_)
if (seg->fia_mp_map.size())
	{
	FIA_LIAB *current_fia_element;
	colnum = liab->sm_fia[0]->sm_fia_ann_pba[0]->Column(colname).Number();
	
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

			total += current_fia_element->sm_fia_ann_pba[0]->Column(colnum).Value(t);
			}
		}
	}
#endif

#if defined(__PA_LIAB_H_)
if (seg->pa_mp_map.size())
	{
	PA_LIAB *current_pa_element;
	colnum = liab->sm_pa[0]->sm_pa_ann_pba[0]->Column(colname).Number();
	
	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->pa_mp_map.begin();
		     mp_map_iter != seg->pa_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_pa_element = liab->sm_pa[mp];

			if (t < current_pa_element->commencement_period
				|| t > current_pa_element->maturity_period)
				continue;

			// Skip new issue commencement period
			if (current_pa_element->elapsed_mths <= 0
				&& t == current_pa_element->commencement_period)
				continue;

			if (t != current_pa_element->commencement_period
				&& fabs(current_pa_element->policies_b(t)) < rate_ratio_threshold)
				continue;

			total += current_pa_element->sm_pa_ann_pba[0]->Column(colnum).Value(t);
			}
		}
	}
#endif

//for EPL file
#if defined(__EPL_LIAB_H_)
if (seg->epl_mp_map.size())
	{
	EPL_LIAB *current_epl_element;
	colnum = liab->sm_epl[0]->Column("ann_pba_" + colname).Number();
	
	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_pba' "
		                 "function of ann_pba/pba model class.");
		
	if (colnum >= 0)
		{ 
		for (mp_map_iter = seg->epl_mp_map.begin();
		     mp_map_iter != seg->epl_mp_map.end();
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			current_epl_element = liab->sm_epl[mp];

			if (t < current_epl_element->commencement_period
				|| t > current_epl_element->maturity_period)
				continue;

			total += current_epl_element->Column(colnum).Value(t);
			}
		}
	}
#endif

if (seg->seriatim_totals.size() > 0)
	{
	pair<xstring,seriatim_type> name_pair = make_pair(colname, prod_ann_pba);
	seriatim_map::iterator totals_it = seg->seriatim_totals.find(name_pair);

	if (totals_it != seg->seriatim_totals.end())
		total += totals_it->second[0][reins_flag][t];
	}	

return total;
}



	static ANN_PBA_PBA_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (ANN_PBA_PBA_UDF::*dPXi) (int);
typedef double (ANN_PBA_PBA_UDF::*dPXid) (int, double);
typedef double (ANN_PBA_PBA_UDF::*dPF) ();
typedef double (ANN_PBA_PBA_UDF::*dPFd) (double);
typedef int (ANN_PBA_PBA_UDF::*iPF) ();
typedef int (ANN_PBA_PBA_UDF::*iPFi) (int);
typedef xstring (ANN_PBA_PBA_UDF::*sPF) ();
typedef xstring (ANN_PBA_PBA_UDF::*sPFs) (xstring);

const CashFlowCommonData ANN_PBA_PBA::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "asset_yld_mthly", "ann_pba_pba_asset_yld_mthly",  "asset_yld_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_asset_yld_mthly, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_mthly),
	CashFlowCommonData(2, "assets_accum", "ann_pba_pba_assets_accum",  "assets_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_assets_accum, 'E','N', '3', 'P', (size_t)&modelOffset->assets_accum),
	CashFlowCommonData(3, "cal_mth", "ann_pba_pba_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(4, "cal_yr", "ann_pba_pba_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(5, "cal_yr_relative", "ann_pba_pba_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(6, "cap_gain", "ann_pba_pba_cap_gain",  "cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain),
	CashFlowCommonData(7, "cash_flow", "ann_pba_pba_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(8, "cash_flow_int", "ann_pba_pba_cash_flow_int",  "cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_int),
	CashFlowCommonData(9, "cash_flow_rate_mthly", "ann_pba_pba_cash_flow_rate_mthly",  "cash_flow_rate_mthly",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_cash_flow_rate_mthly, 'E','N', '3', 'C', (size_t)&modelOffset->cash_flow_rate_mthly),
	CashFlowCommonData(10, "date", "ann_pba_pba_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(11, "def_accum", "ann_pba_pba_def_accum",  "def_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_def_accum, 'E','N', '3', 'P', (size_t)&modelOffset->def_accum),
	CashFlowCommonData(12, "direct_cap_gain", "ann_pba_pba_direct_cap_gain",  "direct_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_cap_gain),
	CashFlowCommonData(13, "direct_cash_flow", "ann_pba_pba_direct_cash_flow",  "direct_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_cash_flow),
	CashFlowCommonData(14, "direct_cash_flow_int", "ann_pba_pba_direct_cash_flow_int",  "direct_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->direct_cash_flow_int),
	CashFlowCommonData(15, "direct_imr_incr", "ann_pba_pba_direct_imr_incr",  "direct_imr_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_imr_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->direct_imr_incr),
	CashFlowCommonData(16, "direct_inv_inc", "ann_pba_pba_direct_inv_inc",  "direct_inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_inv_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_inv_inc),
	CashFlowCommonData(17, "direct_prof", "ann_pba_pba_direct_prof",  "direct_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_prof),
	CashFlowCommonData(18, "direct_res_incr", "ann_pba_pba_direct_res_incr",  "direct_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_res_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_res_incr),
	CashFlowCommonData(19, "direct_tax", "ann_pba_pba_direct_tax",  "direct_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_direct_tax, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_tax),
	CashFlowCommonData(20, "disc_rate_accum", "ann_pba_pba_disc_rate_accum",  "disc_rate_accum",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_accum, 'E','N', '3', 'P', (size_t)&modelOffset->disc_rate_accum),
	CashFlowCommonData(21, "disc_rate_mthly", "ann_pba_pba_disc_rate_mthly",  "disc_rate_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_mthly, 'E','N', '3', 'P', (size_t)&modelOffset->disc_rate_mthly),
	CashFlowCommonData(22, "eff_cap_gains_rate", "ann_pba_pba_eff_cap_gains_rate",  "eff_cap_gains_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_eff_cap_gains_rate, 'E','N', '3', 'P', (size_t)&modelOffset->eff_cap_gains_rate),
	CashFlowCommonData(23, "hedge_cash_flow", "ann_pba_pba_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(24, "hedge_cost", "ann_pba_pba_hedge_cost",  "hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost),
	CashFlowCommonData(25, "hedge_mkt_val", "ann_pba_pba_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(26, "hedge_mkt_val_incr", "ann_pba_pba_hedge_mkt_val_incr",  "hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_incr),
	CashFlowCommonData(27, "hedging_e_factor", "ann_pba_pba_hedging_e_factor",  "hedging_e_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_hedging_e_factor, 'E','Y', '3', 'P', (size_t)&modelOffset->hedging_e_factor),
	CashFlowCommonData(28, "imr", "ann_pba_pba_imr",  "imr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_imr, 'E','N', '3', 'C', (size_t)&modelOffset->imr),
	CashFlowCommonData(29, "imr_incr", "ann_pba_pba_imr_incr",  "imr_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_imr_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_incr),
	CashFlowCommonData(30, "initialize", "ann_pba_pba_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(31, "inv_inc", "ann_pba_pba_inv_inc",  "inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_inv_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_inc),
	CashFlowCommonData(32, "pimr_adj_factor", "ann_pba_pba_pimr_adj_factor",  "pimr_adj_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_pimr_adj_factor, 'E','N', '3', 'C', (size_t)&modelOffset->pimr_adj_factor),
	CashFlowCommonData(33, "realzd_cap_gain", "ann_pba_pba_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_realzd_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(34, "realzd_cap_gain_bef_sale", "ann_pba_pba_realzd_cap_gain_bef_sale",  "realzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_realzd_cap_gain_bef_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_bef_sale),
	CashFlowCommonData(35, "reins_cap_gain", "ann_pba_pba_reins_cap_gain",  "reins_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_cap_gain),
	CashFlowCommonData(36, "reins_cash_flow", "ann_pba_pba_reins_cash_flow",  "reins_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_cash_flow),
	CashFlowCommonData(37, "reins_cash_flow_int", "ann_pba_pba_reins_cash_flow_int",  "reins_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_int),
	CashFlowCommonData(38, "reins_cost", "ann_pba_pba_reins_cost",  "reins_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_cost),
	CashFlowCommonData(39, "reins_imr_incr", "ann_pba_pba_reins_imr_incr",  "reins_imr_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_imr_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_imr_incr),
	CashFlowCommonData(40, "reins_inv_inc", "ann_pba_pba_reins_inv_inc",  "reins_inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_inv_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_inv_inc),
	CashFlowCommonData(41, "reins_res", "ann_pba_pba_reins_res",  "reins_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_res),
	CashFlowCommonData(42, "reins_res_incr", "ann_pba_pba_reins_res_incr",  "reins_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_res_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_res_incr),
	CashFlowCommonData(43, "reins_tax_res", "ann_pba_pba_reins_tax_res",  "reins_tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_tax_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_tax_res),
	CashFlowCommonData(44, "reins_tax_res_incr", "ann_pba_pba_reins_tax_res_incr",  "reins_tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_res_incr),
	CashFlowCommonData(45, "scen_amt", "ann_pba_pba_scen_amt",  "scen_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_scen_amt, 'E','N', '3', 'P', (size_t)&modelOffset->scen_amt),
	CashFlowCommonData(46, "scen_greatest_pv", "ann_pba_pba_scen_greatest_pv",  "scen_greatest_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_scen_greatest_pv, 'E','N', '3', 'P', (size_t)&modelOffset->scen_greatest_pv),
	CashFlowCommonData(47, "starting_assets", "ann_pba_pba_starting_assets",  "starting_assets",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_starting_assets, 'E','N', '3', 'P', (size_t)&modelOffset->starting_assets),
	CashFlowCommonData(48, "startup", "ann_pba_pba_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(49, "stoch_amt", "ann_pba_pba_stoch_amt",  "stoch_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_stoch_amt, 'E','N', '3', 'P', (size_t)&modelOffset->stoch_amt),
	CashFlowCommonData(50, "tax", "ann_pba_pba_tax",  "tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax, 'E','Y', '3', 'P', (size_t)&modelOffset->tax),
	CashFlowCommonData(51, "tax_adj_ratio", "ann_pba_pba_tax_adj_ratio",  "tax_adj_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_adj_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->tax_adj_ratio),
	CashFlowCommonData(52, "tax_capzd_prem", "ann_pba_pba_tax_capzd_prem",  "tax_capzd_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem),
	CashFlowCommonData(53, "tax_capzd_prem_amortzn", "ann_pba_pba_tax_capzd_prem_amortzn",  "tax_capzd_prem_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem_amortzn, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem_amortzn),
	CashFlowCommonData(54, "tax_cash_flow", "ann_pba_pba_tax_cash_flow",  "tax_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->tax_cash_flow),
	CashFlowCommonData(55, "tax_cash_flow_bef_sale", "ann_pba_pba_tax_cash_flow_bef_sale",  "tax_cash_flow_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_cash_flow_bef_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->tax_cash_flow_bef_sale),
	CashFlowCommonData(56, "tax_res", "ann_pba_pba_tax_res",  "tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_res),
	CashFlowCommonData(57, "tax_res_incr", "ann_pba_pba_tax_res_incr",  "tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_res_incr),
	CashFlowCommonData(58, "tax_ytd", "ann_pba_pba_tax_ytd",  "tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_ytd, 'E','N', '3', 'P', (size_t)&modelOffset->tax_ytd),
	CashFlowCommonData(59, "tax_ytd_bef_sale", "ann_pba_pba_tax_ytd_bef_sale",  "tax_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_ytd_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->tax_ytd_bef_sale),
	CashFlowCommonData(60, "taxable_inc", "ann_pba_pba_taxable_inc",  "taxable_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->taxable_inc),
	CashFlowCommonData(61, "taxable_inc_bef_sale", "ann_pba_pba_taxable_inc_bef_sale",  "taxable_inc_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_bef_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->taxable_inc_bef_sale),
	CashFlowCommonData(62, "taxable_inc_ytd", "ann_pba_pba_taxable_inc_ytd",  "taxable_inc_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_ytd, 'E','N', '3', 'P', (size_t)&modelOffset->taxable_inc_ytd),
	CashFlowCommonData(63, "taxable_inc_ytd_bef_sale", "ann_pba_pba_taxable_inc_ytd_bef_sale",  "taxable_inc_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_taxable_inc_ytd_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->taxable_inc_ytd_bef_sale),
	CashFlowCommonData(64, "working_res", "ann_pba_pba_working_res",  "working_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&ANN_PBA_PBA_UDF::ann_pba_pba_working_res, 'E','N', '3', 'P', (size_t)&modelOffset->working_res)
};
const CashFlowCommonData* ANN_PBA_PBA::mCFStaticData[] = {
	&ANN_PBA_PBA::mCFStaticData_0[0],
	&ANN_PBA_PBA::mCFStaticData_0[1],
	&ANN_PBA_PBA::mCFStaticData_0[2],
	&ANN_PBA_PBA::mCFStaticData_0[3],
	&ANN_PBA_PBA::mCFStaticData_0[4],
	&ANN_PBA_PBA::mCFStaticData_0[5],
	&ANN_PBA_PBA::mCFStaticData_0[6],
	&ANN_PBA_PBA::mCFStaticData_0[7],
	&ANN_PBA_PBA::mCFStaticData_0[8],
	&ANN_PBA_PBA::mCFStaticData_0[9],
	&ANN_PBA_PBA::mCFStaticData_0[10],
	&ANN_PBA_PBA::mCFStaticData_0[11],
	&ANN_PBA_PBA::mCFStaticData_0[12],
	&ANN_PBA_PBA::mCFStaticData_0[13],
	&ANN_PBA_PBA::mCFStaticData_0[14],
	&ANN_PBA_PBA::mCFStaticData_0[15],
	&ANN_PBA_PBA::mCFStaticData_0[16],
	&ANN_PBA_PBA::mCFStaticData_0[17],
	&ANN_PBA_PBA::mCFStaticData_0[18],
	&ANN_PBA_PBA::mCFStaticData_0[19],
	&ANN_PBA_PBA::mCFStaticData_0[20],
	&ANN_PBA_PBA::mCFStaticData_0[21],
	&ANN_PBA_PBA::mCFStaticData_0[22],
	&ANN_PBA_PBA::mCFStaticData_0[23],
	&ANN_PBA_PBA::mCFStaticData_0[24],
	&ANN_PBA_PBA::mCFStaticData_0[25],
	&ANN_PBA_PBA::mCFStaticData_0[26],
	&ANN_PBA_PBA::mCFStaticData_0[27],
	&ANN_PBA_PBA::mCFStaticData_0[28],
	&ANN_PBA_PBA::mCFStaticData_0[29],
	&ANN_PBA_PBA::mCFStaticData_0[30],
	&ANN_PBA_PBA::mCFStaticData_0[31],
	&ANN_PBA_PBA::mCFStaticData_0[32],
	&ANN_PBA_PBA::mCFStaticData_0[33],
	&ANN_PBA_PBA::mCFStaticData_0[34],
	&ANN_PBA_PBA::mCFStaticData_0[35],
	&ANN_PBA_PBA::mCFStaticData_0[36],
	&ANN_PBA_PBA::mCFStaticData_0[37],
	&ANN_PBA_PBA::mCFStaticData_0[38],
	&ANN_PBA_PBA::mCFStaticData_0[39],
	&ANN_PBA_PBA::mCFStaticData_0[40],
	&ANN_PBA_PBA::mCFStaticData_0[41],
	&ANN_PBA_PBA::mCFStaticData_0[42],
	&ANN_PBA_PBA::mCFStaticData_0[43],
	&ANN_PBA_PBA::mCFStaticData_0[44],
	&ANN_PBA_PBA::mCFStaticData_0[45],
	&ANN_PBA_PBA::mCFStaticData_0[46],
	&ANN_PBA_PBA::mCFStaticData_0[47],
	&ANN_PBA_PBA::mCFStaticData_0[48],
	&ANN_PBA_PBA::mCFStaticData_0[49],
	&ANN_PBA_PBA::mCFStaticData_0[50],
	&ANN_PBA_PBA::mCFStaticData_0[51],
	&ANN_PBA_PBA::mCFStaticData_0[52],
	&ANN_PBA_PBA::mCFStaticData_0[53],
	&ANN_PBA_PBA::mCFStaticData_0[54],
	&ANN_PBA_PBA::mCFStaticData_0[55],
	&ANN_PBA_PBA::mCFStaticData_0[56],
	&ANN_PBA_PBA::mCFStaticData_0[57],
	&ANN_PBA_PBA::mCFStaticData_0[58],
	&ANN_PBA_PBA::mCFStaticData_0[59],
	&ANN_PBA_PBA::mCFStaticData_0[60],
	&ANN_PBA_PBA::mCFStaticData_0[61],
	&ANN_PBA_PBA::mCFStaticData_0[62],
	&ANN_PBA_PBA::mCFStaticData_0[63],
	&ANN_PBA_PBA::mCFStaticData_0[64],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for hedging_cash_flow_defn                                                                                       
	const ChoicePair hedging_cash_flow_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEST_ESTIMATE, "Best Estimate")
		,ChoicePair(StrEnum::EXISTING, "Existing")
	};
	const EnumList hedging_cash_flow_defnEnumList(2, hedging_cash_flow_defnChoicePairs);

	// EnumList for hedging_defn                                                                                       
	const ChoicePair hedging_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::HEDGED, "Hedged")
		,ChoicePair(StrEnum::UNHEDGED, "Unhedged")
		,ChoicePair(StrEnum::BOTH, "Both")
	};
	const EnumList hedging_defnEnumList(3, hedging_defnChoicePairs);

	// EnumList for hedging_defn_input                                                                                       
	const ChoicePair hedging_defn_inputChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::HEDGED, "Hedged")
		,ChoicePair(StrEnum::UNHEDGED, "Unhedged")
		,ChoicePair(StrEnum::BOTH, "Both")
	};
	const EnumList hedging_defn_inputEnumList(3, hedging_defn_inputChoicePairs);

	// EnumList for pba_code                                                                                       
	const ChoicePair pba_codeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::STOCH_RES, "Stoch Res")
		,ChoicePair(StrEnum::STOCH_CAP, "Stoch Cap")
	};
	const EnumList pba_codeEnumList(2, pba_codeChoicePairs);

	// EnumList for reins_defn                                                                                       
	const ChoicePair reins_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GROSS, "Gross")
		,ChoicePair(StrEnum::NET, "Net")
		,ChoicePair(StrEnum::BOTH, "Both")
	};
	const EnumList reins_defnEnumList(3, reins_defnChoicePairs);

	// EnumList for reins_defn_input                                                                                       
	const ChoicePair reins_defn_inputChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GROSS, "Gross")
		,ChoicePair(StrEnum::NET, "Net")
		,ChoicePair(StrEnum::BOTH, "Both")
	};
	const EnumList reins_defn_inputEnumList(3, reins_defn_inputChoicePairs);

	// EnumList for reins_gross_up_defn                                                                                       
	const ChoicePair reins_gross_up_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList reins_gross_up_defnEnumList(2, reins_gross_up_defnChoicePairs);

	// EnumList for res_cap_calc_defn                                                                                       
	const ChoicePair res_cap_calc_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::RESERVES_AND_CAPITAL, "Reserves and Capital")
		,ChoicePair(StrEnum::CAPITAL, "Capital")
		,ChoicePair(StrEnum::RESERVES, "Reserves")
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
	};
	const EnumList res_cap_calc_defnEnumList(4, res_cap_calc_defnChoicePairs);

	// EnumList for res_cap_calc_defn_input                                                                                       
	const ChoicePair res_cap_calc_defn_inputChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::RESERVES_AND_CAPITAL, "Reserves and Capital")
		,ChoicePair(StrEnum::CAPITAL, "Capital")
		,ChoicePair(StrEnum::RESERVES, "Reserves")
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
	};
	const EnumList res_cap_calc_defn_inputEnumList(4, res_cap_calc_defn_inputChoicePairs);

	// EnumList for tax_defn_stoch_cap                                                                                       
	const ChoicePair tax_defn_stoch_capChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::USE_WORKING_RESERVE, "Use Working Reserve")
		,ChoicePair(StrEnum::CALCULATE_TAX_RESERVE, "Calculate Tax Reserve")
	};
	const EnumList tax_defn_stoch_capEnumList(2, tax_defn_stoch_capChoicePairs);

	// EnumList for working_res_defn_input                                                                                       
	const ChoicePair working_res_defn_inputChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CASH_VALUE, "Cash Value")
		,ChoicePair(StrEnum::ZERO, "Zero")
	};
	const EnumList working_res_defn_inputEnumList(2, working_res_defn_inputChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace ANN_PBA_PBA_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(ANN_PBA_PBA::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(ANN_PBA_PBA::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace ANN_PBA_PBA_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void ANN_PBA_PBA::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> ANN_PBA_PBA::mgr_;

	Attribute::Descriptor ANN_PBA_PBA::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"cte_pct_stoch_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cte_pct_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STR_ENUM,	"hedging_cash_flow_defn", -1, (size_t)&modelOffset->hedging_cash_flow_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedging_cash_flow_defnEnumList, Feature(true)),
	Descriptor(2, Attribute::STR_ENUM,	"hedging_defn", -1, (size_t)&modelOffset->hedging_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedging_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::STR_ENUM,	"hedging_defn_input", -1, (size_t)&modelOffset->hedging_defn_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedging_defn_inputEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"hedging_e_factor_stoch_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedging_e_factor_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"hedging_e_factor_stoch_res", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedging_e_factor_stoch_res,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"hedging_output_file_best_estimate_stoch_cap", -1, (size_t)&modelOffset->hedging_output_file_best_estimate_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"hedging_output_file_best_estimate_stoch_res", -1, (size_t)&modelOffset->hedging_output_file_best_estimate_stoch_res,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STRING,	"hedging_output_file_existing_hedges_stoch_cap", -1, (size_t)&modelOffset->hedging_output_file_existing_hedges_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"hedging_output_file_existing_hedges_stoch_res", -1, (size_t)&modelOffset->hedging_output_file_existing_hedges_stoch_res,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"hedging_stat_scale_factor_max_stoch_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedging_stat_scale_factor_max_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"hedging_stat_scale_factor_max_stoch_res", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedging_stat_scale_factor_max_stoch_res,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"init_asset_pct_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_asset_pct_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"init_assets_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_assets_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STR_ENUM,	"pba_code", -1, (size_t)&modelOffset->pba_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pba_codeEnumList, Feature(true)),
	Descriptor(15, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STR_ENUM,	"reins_defn", -1, (size_t)&modelOffset->reins_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_defnEnumList, Feature(true)),
	Descriptor(17, Attribute::STR_ENUM,	"reins_defn_input", -1, (size_t)&modelOffset->reins_defn_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_defn_inputEnumList, Feature(true)),
	Descriptor(18, Attribute::STR_ENUM,	"reins_gross_up_defn", -1, (size_t)&modelOffset->reins_gross_up_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_gross_up_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::STR_ENUM,	"res_cap_calc_defn", -1, (size_t)&modelOffset->res_cap_calc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &res_cap_calc_defnEnumList, Feature(true)),
	Descriptor(20, Attribute::STR_ENUM,	"res_cap_calc_defn_input", -1, (size_t)&modelOffset->res_cap_calc_defn_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &res_cap_calc_defn_inputEnumList, Feature(true)),
	Descriptor(21, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"tax_defn_stoch_cap", -1, (size_t)&modelOffset->tax_defn_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_defn_stoch_capEnumList, Feature(true)),
	Descriptor(23, Attribute::STRING,	"valn_results_stoch_cap", -1, (size_t)&modelOffset->valn_results_stoch_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STRING,	"valn_results_stoch_res", -1, (size_t)&modelOffset->valn_results_stoch_res,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STR_ENUM,	"working_res_defn_input", -1, (size_t)&modelOffset->working_res_defn_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &working_res_defn_inputEnumList, Feature(true)),
	Descriptor(26, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::SCALAR_DOUBLE,	"cte_pct", -1, (size_t)&modelOffset->cte_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&ANN_PBA_PBA_UDF::ann_pba_pba_cte_pct)),
	Descriptor(28, Attribute::SCALAR_DOUBLE,	"disc_rate_mult_fixed", -1, (size_t)&modelOffset->disc_rate_mult_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&ANN_PBA_PBA_UDF::ann_pba_pba_disc_rate_mult_fixed)),
	Descriptor(29, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_final_period)),
	Descriptor(30, Attribute::SCALAR_INT,	"hedging_flag", -1, (size_t)&modelOffset->hedging_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_hedging_flag)),
	Descriptor(31, Attribute::SCALAR_STRING,	"hedging_output_file_best_estimate", -1, (size_t)&modelOffset->hedging_output_file_best_estimate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ANN_PBA_PBA_UDF::ann_pba_pba_hedging_output_file_best_estimate)),
	Descriptor(32, Attribute::SCALAR_STRING,	"hedging_output_file_existing_hedges", -1, (size_t)&modelOffset->hedging_output_file_existing_hedges,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ANN_PBA_PBA_UDF::ann_pba_pba_hedging_output_file_existing_hedges)),
	Descriptor(33, Attribute::SCALAR_DOUBLE,	"hedging_stat_scale_factor_max", -1, (size_t)&modelOffset->hedging_stat_scale_factor_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&ANN_PBA_PBA_UDF::ann_pba_pba_hedging_stat_scale_factor_max)),
	Descriptor(34, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ANN_PBA_PBA_UDF::ann_pba_pba_proj_date_adj)),
	Descriptor(35, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_date)),
	Descriptor(36, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_mth)),
	Descriptor(37, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_proj_start_yr)),
	Descriptor(38, Attribute::SCALAR_DOUBLE,	"reins_adj", -1, (size_t)&modelOffset->reins_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_adj)),
	Descriptor(39, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_flag)),
	Descriptor(40, Attribute::SCALAR_DOUBLE,	"reins_pct", -1, (size_t)&modelOffset->reins_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&ANN_PBA_PBA_UDF::ann_pba_pba_reins_pct)),
	Descriptor(41, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_start_period)),
	Descriptor(42, Attribute::SCALAR_INT,	"tax_capzd_prem_amortzn_yrs", -1, (size_t)&modelOffset->tax_capzd_prem_amortzn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_capzd_prem_amortzn_yrs)),
	Descriptor(43, Attribute::SCALAR_INT,	"tax_flag", -1, (size_t)&modelOffset->tax_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_tax_flag)),
	Descriptor(44, Attribute::SCALAR_STRING,	"valn_results_scen_amt", -1, (size_t)&modelOffset->valn_results_scen_amt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&ANN_PBA_PBA_UDF::ann_pba_pba_valn_results_scen_amt)),
	Descriptor(45, Attribute::SCALAR_INT,	"working_res_defn", -1, (size_t)&modelOffset->working_res_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&ANN_PBA_PBA_UDF::ann_pba_pba_working_res_defn)),
	};

	Attribute::Descriptor* ANN_PBA_PBA::descriptorTable[] = {
	&ANN_PBA_PBA::descriptor_0[0],
	&ANN_PBA_PBA::descriptor_0[1],
	&ANN_PBA_PBA::descriptor_0[2],
	&ANN_PBA_PBA::descriptor_0[3],
	&ANN_PBA_PBA::descriptor_0[4],
	&ANN_PBA_PBA::descriptor_0[5],
	&ANN_PBA_PBA::descriptor_0[6],
	&ANN_PBA_PBA::descriptor_0[7],
	&ANN_PBA_PBA::descriptor_0[8],
	&ANN_PBA_PBA::descriptor_0[9],
	&ANN_PBA_PBA::descriptor_0[10],
	&ANN_PBA_PBA::descriptor_0[11],
	&ANN_PBA_PBA::descriptor_0[12],
	&ANN_PBA_PBA::descriptor_0[13],
	&ANN_PBA_PBA::descriptor_0[14],
	&ANN_PBA_PBA::descriptor_0[15],
	&ANN_PBA_PBA::descriptor_0[16],
	&ANN_PBA_PBA::descriptor_0[17],
	&ANN_PBA_PBA::descriptor_0[18],
	&ANN_PBA_PBA::descriptor_0[19],
	&ANN_PBA_PBA::descriptor_0[20],
	&ANN_PBA_PBA::descriptor_0[21],
	&ANN_PBA_PBA::descriptor_0[22],
	&ANN_PBA_PBA::descriptor_0[23],
	&ANN_PBA_PBA::descriptor_0[24],
	&ANN_PBA_PBA::descriptor_0[25],
	&ANN_PBA_PBA::descriptor_0[26],
	&ANN_PBA_PBA::descriptor_0[27],
	&ANN_PBA_PBA::descriptor_0[28],
	&ANN_PBA_PBA::descriptor_0[29],
	&ANN_PBA_PBA::descriptor_0[30],
	&ANN_PBA_PBA::descriptor_0[31],
	&ANN_PBA_PBA::descriptor_0[32],
	&ANN_PBA_PBA::descriptor_0[33],
	&ANN_PBA_PBA::descriptor_0[34],
	&ANN_PBA_PBA::descriptor_0[35],
	&ANN_PBA_PBA::descriptor_0[36],
	&ANN_PBA_PBA::descriptor_0[37],
	&ANN_PBA_PBA::descriptor_0[38],
	&ANN_PBA_PBA::descriptor_0[39],
	&ANN_PBA_PBA::descriptor_0[40],
	&ANN_PBA_PBA::descriptor_0[41],
	&ANN_PBA_PBA::descriptor_0[42],
	&ANN_PBA_PBA::descriptor_0[43],
	&ANN_PBA_PBA::descriptor_0[44],
	&ANN_PBA_PBA::descriptor_0[45],
	nullptr};
	const size_t ANN_PBA_PBA::sDescriptorCount = 46;

//factory
ANN_PBA_PBA* ANN_PBA_PBA::makeThis(int isSubmodel, ModelClass* owner, ANN_PBA_PBA* peer, 
						int mainRebase, const xstring &name, ANN_PBA_PBA_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ANN_PBA_PBA::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ANN_PBA_PBA");
#endif
	ANN_PBA_PBA* newP = (ANN_PBA_PBA*)new ANN_PBA_PBA_UDF
   	  ("ann_pba_pba", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
ANN_PBA_PBA_persistent_object* ANN_PBA_PBA_persistent_object::makeThis(int isSubmodel, ModelClass* owner, ANN_PBA_PBA* peer, 
							int mainRebase, const xstring &name, ANN_PBA_PBA_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("ANN_PBA_PBA_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor ANN_PBA_PBA_persistent_object");
#endif
	ANN_PBA_PBA_persistent_object* newP = (ANN_PBA_PBA_persistent_object*)new ANN_PBA_PBA_persistent_object
   	  ("ann_pba_pba", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			ANN_PBA_PBA_persistent_object* pd = dynamic_cast<ANN_PBA_PBA_persistent_object*>(product);
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

typedef double (ANN_PBA_PBA_UDF::*dPF) ();
typedef double (ANN_PBA_PBA_UDF::*dPFd) (double);
typedef int (ANN_PBA_PBA_UDF::*iPF) ();
typedef int (ANN_PBA_PBA_UDF::*iPFi) (int);
typedef xstring (ANN_PBA_PBA_UDF::*sPF) ();
typedef xstring (ANN_PBA_PBA_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
ANN_PBA_PBA::ANN_PBA_PBA(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ANN_PBA_PBA_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
ANN_PBA_PBA::ANN_PBA_PBA(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(64, ANN_PBA_PBA::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_rates(company_liab_fia_fia_rates)
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
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
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

	for (int cf_no = 1; cf_no <= 64; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (ANN_PBA_PBA_UDF::*dPXi2) (int, int);
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


 void ANN_PBA_PBA::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
		company_liab = (LIAB_LIAB*)(findUnique("company|liab"));
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
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


 void ANN_PBA_PBA::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int ANN_PBA_PBA_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& ANN_PBA_PBA_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double ANN_PBA_PBA_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int ANN_PBA_PBA_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double ANN_PBA_PBA_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double ANN_PBA_PBA_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void ANN_PBA_PBA_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ANN_PBA_PBA_persistent_object::write(long include_submodels) {
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

	void ANN_PBA_PBA_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ANN_PBA_PBA_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void ANN_PBA_PBA_persistent_object::write(const xstring& key, long include_submodels) {
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




	ANN_PBA_PBA_persistent_object::~ANN_PBA_PBA_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool ANN_PBA_PBA_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void ANN_PBA_PBA_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void ANN_PBA_PBA_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void ANN_PBA_PBA_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ANN_PBA_PBA_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void ANN_PBA_PBA_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* ANN_PBA_PBA_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* ANN_PBA_PBA_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* ANN_PBA_PBA_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char ANN_PBA_PBA_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void ANN_PBA_PBA_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
ANN_PBA_PBA_persistent_object::ANN_PBA_PBA_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			ANN_PBA_PBA(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(ANN_PBA_PBA::sm_bond_is)
	, sm_bond_pv(ANN_PBA_PBA::sm_bond_pv)
	, sm_bond_ym(ANN_PBA_PBA::sm_bond_ym)
	, sm_mtg_is(ANN_PBA_PBA::sm_mtg_is)
	, sm_mtg_pv(ANN_PBA_PBA::sm_mtg_pv)
	, sm_mtg_ym(ANN_PBA_PBA::sm_mtg_ym)

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
ANN_PBA_PBA::~ANN_PBA_PBA() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void ANN_PBA_PBA::findTargetColumns() {

}
//findTargetColumns END@2
void ANN_PBA_PBA::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void ANN_PBA_PBA::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void ANN_PBA_PBA::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void ANN_PBA_PBA::start_of_projection() {
}
//start_of_projection END@2

void ANN_PBA_PBA::end_of_projection() {
}
//end_of_projection END@2

void ANN_PBA_PBA::start_of_layer() {
}


void ANN_PBA_PBA::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void ANN_PBA_PBA::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void ANN_PBA_PBA::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void ANN_PBA_PBA::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> ANN_PBA_PBA::ddfVector;
BitArray ANN_PBA_PBA::dataVariables(46);
bool ANN_PBA_PBA::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool ANN_PBA_PBA::writeClassInfo = true;

void ANN_PBA_PBA::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, ANN_PBA_PBA::descriptor_0>::dT = ANN_PBA_PBA::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, ANN_PBA_PBA::descriptor_0>::dT = ANN_PBA_PBA::descriptor_0;

