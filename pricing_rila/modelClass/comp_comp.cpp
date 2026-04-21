
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
#include "ModelClass\comp_comp_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_aig.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\bond_portfolio_aig.h"
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

sowfinput company_state_of_world_financial_input;
sowfcols company_state_of_world_financial_input_cols;
sowfoutput company_state_of_world_financial_output;
int PVCLen = 18;
int PVCSigDig = 15;
int model_t_low;
int model_t_high;
int maximum_t_high_value;
int minimum_t_low_value;

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
#ifndef comp_comp_TableDefs
#define comp_comp_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection COMP_COMP::TTHC;
void COMP_COMP::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_asset)
		sm_asset = 0;

	if(modelToRemove == sm_liab)
		sm_liab = 0;

	if(modelToRemove == sm_rates)
		sm_rates = 0;

}		

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double COMP_COMP_UDF::comp_comp_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

// force call for reporting
cost_basis_accrual(t);
cost_basis_incr_appreciation(t);

return sum_over_segments("accr_inc", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - accr_inc_inv
// Accrued Income Investment Assets                                                                                             
// Column:ACCR_INC_INV
//========================================================
double COMP_COMP_UDF::comp_comp_accr_inc_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_inc_inv",t);
}



//^^^

#line 1 "accr_inc_inv.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("accr_inc", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - accr_int
// Accrued Interest                                                                                             
// Column:ACCR_INT
//========================================================
double COMP_COMP_UDF::comp_comp_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"accr_int",t);
}



//^^^

#line 1 "accr_int.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call for reporting
accr_int_aft_dflt(t);

return sum_over_segments("accr_int", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Default                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double COMP_COMP_UDF::comp_comp_accr_int_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"accr_int_aft_dflt",t);
}



//^^^

#line 1 "accr_int_aft_dflt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("accr_int_aft_dflt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - accr_int_dflt
// Accrued Interest Default Amount                                                                                             
// Column:ACCR_INT_DFLT
//========================================================
double COMP_COMP_UDF::comp_comp_accr_int_dflt(int t) {
//^^^



//^^^

#line 1 "accr_int_dflt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("accr_int_dflt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - acq_exp
// Acquisition Expenses                                                                                             
// Column:ACQ_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"acq_exp",t);
}



//^^^

#line 1 "acq_exp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("acq_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - ann_benefits_bom
// Annuity Benefits Beginning of Month                                                                                             
// Column:ANN_BENEFITS_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_ann_benefits_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"ann_benefits_bom",t);
}



//^^^

#line 1 "ann_benefits_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("ann_benefits_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - ann_benefits_eom
// Annuity Benefits End of Month                                                                                             
// Column:ANN_BENEFITS_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"ann_benefits_eom",t);
}



//^^^

#line 1 "ann_benefits_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("ann_benefits_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - annuitzn_consideration
// Annuitization Consideration                                                                                             
// Column:ANNUITZN_CONSIDERATION
//========================================================
double COMP_COMP_UDF::comp_comp_annuitzn_consideration(int t) {
//^^^



//^^^

#line 1 "annuitzn_consideration.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("annuitzn_consideration", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - annuitzn_count_aig
// Annuitization Count Monthly                                                                                             
// Column:ANNUITZN_COUNT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_annuitzn_count_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"annuitzn_count_aig",t);
}



//^^^

#line 1 "annuitzn_count_aig.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("annuitzn_count_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - annuitzn_inc
// Annuitization Income                                                                                             
// Column:ANNUITZN_INC
//========================================================
double COMP_COMP_UDF::comp_comp_annuitzn_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"annuitzn_inc",t);
}



//^^^

#line 1 "annuitzn_inc.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return annuitzn_consideration(t)
	   - annuitzn_val_released(t);

}


//@@ END

//@@ START - annuitzn_val_released
// Annuitization Value Released                                                                                             
// Column:ANNUITZN_VAL_RELEASED
//========================================================
double COMP_COMP_UDF::comp_comp_annuitzn_val_released(int t) {
//^^^



//^^^

#line 1 "annuitzn_val_released.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("annuitzn_val_released", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - asset_cash_flow
// Asset Cash Flow                                                                                             
// Column:ASSET_CASH_FLOW
//========================================================
double COMP_COMP_UDF::comp_comp_asset_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"asset_cash_flow",t);
}



//^^^

#line 1 "asset_cash_flow.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return asset_cash_flow_bef_inv(t)
       - cash_flow_invested(t);

}


//@@ END

//@@ START - asset_cash_flow_bef_inv
// Asset Cash Flow Before Investment                                                                                             
// Column:ASSET_CASH_FLOW_BEF_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_cash_flow_bef_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"asset_cash_flow_bef_inv",t);
}



//^^^

#line 1 "asset_cash_flow_bef_inv.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return asset_cash_flow_bef_sale(t)
       + hedge_sale_amt(t)
	   - hedge_inv_amt_eom(t)
	   - hedge_exp(t)
       + invested_asset_sale(t);

}


//@@ END

//@@ START - asset_cash_flow_bef_sale
// Asset Cash Flow Before Sales                                                                                             
// Column:ASSET_CASH_FLOW_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_asset_cash_flow_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"asset_cash_flow_bef_sale",t);
}



//^^^

#line 1 "asset_cash_flow_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

double hedge_cashflow = hedge_cash_flow(t);

#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
hedge_cashflow = 0.0;
#endif

#if defined(__VA_LIAB_H_)
if (hedge_proj_stmt_flag)
	hedge_cashflow = 0.0;
#endif

return inv_cash_flow_int_div_and_rent(t)
	   + inv_cash_flow_prin_pmt(t)
	   //20210630 STW: opt_pmt in inv_cash_flow_prin_pmt takes value from asset model which is not currently turned on. 
	   // The option payoff value is obtained as a substitute.
	   + opt_payoff_aig(t)		
	   + hedge_cashflow
	   - hedge_inv_amt_bom(t)
	   - hedge_rila_trading_cost_aig(t) //20240529 MQ rila trading cost
	   + cash_int(t)
	   + borrowing_int(t)
	   + interim_cash_int(t)
	   + cash_flow_int(t);

}


//@@ END

//@@ START - asset_less_liab_and_surp
// Assets Less Liabilities And Surplus                                                                                             
// Column:ASSET_LESS_LIAB_AND_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_asset_less_liab_and_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"asset_less_liab_and_surp",t);
}



//^^^

#line 1 "asset_less_liab_and_surp.COMP_COMP.for"
if (!alm_flag || valn_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t > 0)
	asset_less_liab_and_surp(t - 1);

// force call to segments
sum_over_segments("assets_less_liab_and_surp", t, SUM_OVER_ALL);

// force call for reporting
liab_cash_flow(t);
tax(t);
shldr_div(t);
cash_flow_for_inv(t);
asset_cash_flow(t);
cost_basis_purch(t);

double asset_less_liab_and_surp
= fabs((pol_loan(t) 
		+ deferred_net_prem(t)
		- reins_deferred_net_prem(t)
		+ loc_asset(t) 
		+ inv_asset(t)
		+ hedge_mkt_val(t)) 
	   - (stat_unearn_prem_res(t)
	      - reins_stat_unearn_prem_res(t)
	      + stat_claim_res(t)
		  + stat_prem_waiver_res(t)
	      - reins_stat_claim_res(t)
		  - reins_stat_prem_waiver_res(t)
	      + stat_res(t)
	      - reins_stat_res(t)
		  + stat_res_sa_exp_allow(t)
		  + div_liab(t) 
		  - reins_div_liab(t)
		  + undistrib_earnings(t) 
		  + tgt_cap(t)	
	      + avr(t)
		  + imr(t)
		  + free_surp(t)));

if (asset_less_liab_and_surp > aggregate_amount_threshold)
	{
	makeRunLogYellow();
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "Warning. Assets less Liabilities does not equal Surplus"
			   << " for projection loop (" << proj_task_loop_num
			   << ") in period " << t  << " for the total company" 
			   << MSG_ERROR;
	log_screen << " ... with a difference of (" << asset_less_liab_and_surp
			   << "). Assets and Liabilities are inventoried every month."
			   << MSG_ERROR;
	log_screen << " ... Surplus is"
			   << " accumulated every month from the previous month plus increments from"
			   << " the earnings."
			   << MSG_ERROR;
	log_screen << " ... These two processes are producing different results."
			   << MSG_ERROR;
	}

/*if ((t > 0 && cal_mth(t) == 12) || t == last_proj_period)
	log_screen << "... Completed Period t = " << t
			   << " :: CalYr = " << xstring(cal_yr(t))
			   << " :: CalMth = " << xstring(cal_mth(t))
			   << MSG_USER;*/

// Clear rate maps
rates->spot_rates.clear();
rates->spot_rates_shifted.clear();
rates->yld_rates.clear();
rates->yld_rates_shifted.clear();
	
return asset_less_liab_and_surp;

}


//@@ END

//@@ START - asset_sa
// Assets Separate Account                                                                                             
// Column:ASSET_SA
//========================================================
double COMP_COMP_UDF::comp_comp_asset_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"asset_sa",t);
}



//^^^

#line 1 "asset_sa.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_sa", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - asset_yld
// Asset Yield                                                                                             
// Column:ASSET_YLD
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"asset_yld",t);
}



//^^^

#line 1 "asset_yld.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force calls for reporting
rates->yield_rate_90_day(t);
rates->yield_rate_10_year(t);
rates->equity_market_value_growth_us(t);
rates->equity_scenario_total_return_us(t);
rates->infl_rate_annual(t);

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force order
if (t > start_period)
	asset_yld(t - 1);

// force call
asset_yld_inv(t);

// Use weighted average asset yield from segments
if (!alm_flag)
	{
	double rate_denom = 0;
	double rate_numer = 0;	
	
	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		rate_denom += sm_seg[segment]->inv_asset(t);
		rate_numer += sm_seg[segment]->inv_asset(t) 
		                   * sm_seg[segment]->asset_yld(t);
		}
	
	if (fabs(rate_denom) < aggregate_amount_threshold)
		return sum_over_segments("asset_yld", t, SUM_OVER_ALL)
		       / sm_seg.size();
	
	return rate_numer / rate_denom;
	}

double asset_yld_calc = 0.0;

if (asset_yld_denom(t) < -aggregate_amount_threshold)
	asset_yld_calc = 0.0;

else if (asset_yld_denom(t) > aggregate_amount_threshold)
	{
	double asset_yld_numer = this->asset_yld_numer(t);
	double cash_int = this->cash_int(t);
	double borrowing_int = this->borrowing_int(t);
	double interim_cash_int = this->interim_cash_int(t);

	double asset_yld_numer_adj
	= asset_yld_numer
	  + cash_int
	  + borrowing_int
	  + interim_cash_int;

	double asset_yld_prelim
	= annual_yld(asset_yld_numer_adj,
				asset_yld_denom(t),
				EFFECTIVE_ANNUAL);

	asset_yld_calc = min(max(asset_yld_prelim, USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);
	}
else
	// use cash rate from corporate segment
	asset_yld_calc = min(max(sm_seg[0]->cash_rate(t), USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_asset_yld;
		
	return asset_yld_calc;	
	}

return asset_yld_calc;

}


//@@ END

//@@ START - asset_yld_denom
// Asset Yield Denominator                                                                                             
// Column:ASSET_YLD_DENOM
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"asset_yld_denom",t);
}



//^^^

#line 1 "asset_yld_denom.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_yld_denom", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_denom_inv
// Asset Yield Denominator for Investment Asset                                                                                             
// Column:ASSET_YLD_DENOM_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_denom_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"asset_yld_denom_inv",t);
}



//^^^

#line 1 "asset_yld_denom_inv.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_yld_denom_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_inv
// Asset Yield on Investment Assets                                                                                             
// Column:ASSET_YLD_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"asset_yld_inv",t);
}



//^^^

#line 1 "asset_yld_inv.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force order
if (t > start_period)
	asset_yld_inv(t - 1);

// Use weighted average asset yield inv from segments
if (!alm_flag)
	{
	double rate_denom = 0;
	double rate_numer = 0;	
	
	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		rate_denom += sm_seg[segment]->inv_asset(t);
		rate_numer += sm_seg[segment]->inv_asset(t) 
		                   * sm_seg[segment]->asset_yld_inv(t);
		}
	
	if (fabs(rate_denom) < aggregate_amount_threshold)
		return sum_over_segments("asset_yld_inv", t, SUM_OVER_ALL)
		       / sm_seg.size();
	
	return rate_numer / rate_denom;
	}

double asset_yld_calc = 0.0;

if (asset_yld_denom_inv(t) < -aggregate_amount_threshold)
	asset_yld_calc = 0.0;

else if (asset_yld_denom_inv(t) > aggregate_amount_threshold)
	{
	double asset_yld_numer = this->asset_yld_numer_inv(t);
	double cash_int = this->cash_int(t);			//20210517 STW: add WTW's suggested fix
	double borrowing_int = this->borrowing_int(t);
	double interim_cash_int = this->interim_cash_int(t);

	double asset_yld_numer_adj
	= asset_yld_numer
	  + cash_int
	  + borrowing_int
	  + interim_cash_int;

	double asset_yld_prelim
	= annual_yld(asset_yld_numer_adj,
				asset_yld_denom_inv(t),
				EFFECTIVE_ANNUAL);

	asset_yld_calc = min(max(asset_yld_prelim, USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);
	}
else
	// use cash rate from corporate segment
	asset_yld_calc = min(max(sm_seg[0]->cash_rate(t), USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_asset_yld;
		
	return asset_yld_calc;	
	}

return asset_yld_calc;

}


//@@ END

//@@ START - asset_yld_inv_adj_aig
// Asset Yield on Investment Assets, with Duration Weighted Adjustment                                                                                             
// Column:ASSET_YLD_INV_ADJ_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_inv_adj_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"asset_yld_inv_adj_aig",t);
}



//^^^

#line 1 "asset_yld_inv_adj_aig.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_yld_inv_adj_aig", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_less_dflt
// Asset Yield Less Default                                                                                             
// Column:ASSET_YLD_LESS_DFLT
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_less_dflt(int t) {
//^^^



//^^^

#line 1 "asset_yld_less_dflt.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!alm_flag)
	return asset_yld(t);

if (t > start_period)
	asset_yld_less_dflt(t - 1);

double asset_yld_less_dflt_calc = 0.0;

if (asset_yld_denom(t) < -aggregate_amount_threshold)
	asset_yld_less_dflt_calc = 0.0;

else if (asset_yld_denom(t) > aggregate_amount_threshold)
	{
	double total_asset_yld_less_dflt_numer
	  = asset_yld_less_dflt_numer(t)
	  + cash_int(t)
	  + borrowing_int(t)
	  + interim_cash_int(t);

	double asset_yld_less_dflt_prelim
	= annual_yld(total_asset_yld_less_dflt_numer,
				asset_yld_denom(t),
				EFFECTIVE_ANNUAL);

	asset_yld_less_dflt_calc = min(max(asset_yld_less_dflt_prelim, USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);
	}
else
	// use cash rate from corporate segment
	asset_yld_less_dflt_calc = max(sm_seg[0]->cash_rate(t), USLIB_MINIMUM_YIELD);

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_asset_yld_less_dflt;
		
	return asset_yld_less_dflt_calc;	
	}

return asset_yld_less_dflt_calc;

}


//@@ END

//@@ START - asset_yld_less_dflt_inv
// Asset Yield Less Default on Investment Assets                                                                                             
// Column:ASSET_YLD_LESS_DFLT_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_inv(int t) {
//^^^



//^^^

#line 1 "asset_yld_less_dflt_inv.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!alm_flag)
	return asset_yld_inv(t);

if (t > start_period)
	asset_yld_less_dflt_inv(t - 1);

double asset_yld_less_dflt_calc = 0.0;

if (asset_yld_denom_inv(t) < -aggregate_amount_threshold)
	asset_yld_less_dflt_calc = 0.0;

else if (asset_yld_denom_inv(t) > aggregate_amount_threshold)
	{
	double total_asset_yld_less_dflt_numer_inv
	  = asset_yld_less_dflt_numer_inv(t)
	  + cash_int(t)				//20210517 STW: add WTW's suggested fix
	  + borrowing_int(t)
	  + interim_cash_int(t);

	double asset_yld_less_dflt_prelim
	= annual_yld(total_asset_yld_less_dflt_numer_inv,
				asset_yld_denom_inv(t),
				EFFECTIVE_ANNUAL);

	asset_yld_less_dflt_calc = min(max(asset_yld_less_dflt_prelim, USLIB_MINIMUM_YIELD), USLIB_MAX_DOUBLE);
	}
else
	// use cash rate from corporate segment
	asset_yld_less_dflt_calc = max(sm_seg[0]->cash_rate(t), USLIB_MINIMUM_YIELD);

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_asset_yld_less_dflt;
		
	return asset_yld_less_dflt_calc;	
	}

return asset_yld_less_dflt_calc;

}


//@@ END

//@@ START - asset_yld_less_dflt_numer
// Asset Yield Less Default Numerator                                                                                             
// Column:ASSET_YLD_LESS_DFLT_NUMER
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"asset_yld_less_dflt_numer",t);
}



//^^^

#line 1 "asset_yld_less_dflt_numer.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("asset_yld_less_dflt_numer", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_less_dflt_numer_inv
// Asset Yield Less Default Numerator for Investment Assets                                                                                             
// Column:ASSET_YLD_LESS_DFLT_NUMER_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_numer_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"asset_yld_less_dflt_numer_inv",t);
}



//^^^

#line 1 "asset_yld_less_dflt_numer_inv.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_yld_less_dflt_numer_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_numer
// Asset Yield Numerator                                                                                             
// Column:ASSET_YLD_NUMER
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"asset_yld_numer",t);
}



//^^^

#line 1 "asset_yld_numer.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("asset_yld_numer", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_numer_inv
// Asset Yield Numerator for Investment Asset                                                                                             
// Column:ASSET_YLD_NUMER_INV
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_numer_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"asset_yld_numer_inv",t);
}



//^^^

#line 1 "asset_yld_numer_inv.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("asset_yld_numer_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - asset_yld_vm21_reinv_rate
// Asset Yld Vm21 Reinv Rate                                                                                             
// Column:ASSET_YLD_VM21_REINV_RATE
//========================================================
double COMP_COMP_UDF::comp_comp_asset_yld_vm21_reinv_rate(int t) {
//^^^



//^^^

#line 1 "asset_yld_vm21_reinv_rate.COMP_COMP.for"
if (t < start_period || t > final_period || !vm21_reinv_rate_flag)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

int vm21_segment = 0;

if (tcm_flag) //Includes corporate segment element
	vm21_segment = sm_seg.size() - 2; 
else
	vm21_segment = sm_seg.size() - 1;

return sm_seg[vm21_segment]->asset_yld_less_dflt_inv(t);

}


//@@ END

//@@ START - avr
// AVR                                                                                             
// Column:AVR
//========================================================
double COMP_COMP_UDF::comp_comp_avr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"avr",t);
}



//^^^

#line 1 "avr.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return avr_dflt(t)
	   + avr_eqt(t);

}


//@@ END

//@@ START - avr_bef_sale
// AVR Before Sales                                                                                             
// Column:AVR_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"avr_bef_sale",t);
}



//^^^

#line 1 "avr_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

return avr_dflt_bef_sale(t)
	   + avr_eqt_bef_sale(t);

}


//@@ END

//@@ START - avr_bond
// AVR Bond                                                                                             
// Column:AVR_BOND
//========================================================
double COMP_COMP_UDF::comp_comp_avr_bond(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"avr_bond",t);
}



//^^^

#line 1 "avr_bond.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_bond", t, SUM_OVER_ALL);

if (t == start_period)
	return sum_over_segments("avr_bond_bocy", t, SUM_OVER_ALL);
	
return avr_calc(t, "After Sales", "Bonds");

}


//@@ END

//@@ START - avr_bond_bef_sale
// AVR Bond Before Sales                                                                                             
// Column:AVR_BOND_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_bond_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"avr_bond_bef_sale",t);
}



//^^^

#line 1 "avr_bond_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_bond_bef_sale", t, SUM_OVER_ALL);

return avr_calc(t, "Before Sales", "Bonds");

}


//@@ END

//@@ START - avr_bond_bocy
// AVR Bond Beginning of Calendar Year                                                                                             
// Column:AVR_BOND_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_bond_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"avr_bond_bocy",t);
}



//^^^

#line 1 "avr_bond_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return sum_over_segments("avr_bond_bocy", t, SUM_OVER_ALL);

if (t != 1 && cal_mth(t) == 1)
	return avr_bond(t - 1);

return avr_bond_bocy(t - 1);

}


//@@ END

//@@ START - avr_dflt
// AVR Default                                                                                             
// Column:AVR_DFLT
//========================================================
double COMP_COMP_UDF::comp_comp_avr_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"avr_dflt",t);
}



//^^^

#line 1 "avr_dflt.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return avr_bond_bocy(t)
		   + avr_mtg_bocy(t);

return avr_bond(t)
       + avr_mtg(t);

}


//@@ END

//@@ START - avr_dflt_bef_sale
// AVR Default Before Sales                                                                                             
// Column:AVR_DFLT_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_dflt_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"avr_dflt_bef_sale",t);
}



//^^^

#line 1 "avr_dflt_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

return avr_bond_bef_sale(t)
       + avr_mtg_bef_sale(t);

}


//@@ END

//@@ START - avr_eqt
// AVR Equity                                                                                             
// Column:AVR_EQT
//========================================================
double COMP_COMP_UDF::comp_comp_avr_eqt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"avr_eqt",t);
}



//^^^

#line 1 "avr_eqt.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return avr_stock_bocy(t)
		   + avr_other_bocy(t);

return avr_stock(t)
       + avr_other(t);

}


//@@ END

//@@ START - avr_eqt_bef_sale
// AVR Equity Before Sales                                                                                             
// Column:AVR_EQT_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_eqt_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"avr_eqt_bef_sale",t);
}



//^^^

#line 1 "avr_eqt_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

return avr_stock_bef_sale(t)
       + avr_other_bef_sale(t);

}


//@@ END

//@@ START - avr_incr
// AVR Increase                                                                                             
// Column:AVR_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_avr_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"avr_incr",t);
}



//^^^

#line 1 "avr_incr.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

return avr(t) - avr(t - 1);

}


//@@ END

//@@ START - avr_mtg
// AVR Mortgage                                                                                             
// Column:AVR_MTG
//========================================================
double COMP_COMP_UDF::comp_comp_avr_mtg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"avr_mtg",t);
}



//^^^

#line 1 "avr_mtg.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_mtg", t, SUM_OVER_ALL);

if (t == start_period)
	return sum_over_segments("avr_mtg_bocy", t, SUM_OVER_ALL);

return avr_calc(t, "After Sales", "Mortgages");

}


//@@ END

//@@ START - avr_mtg_bef_sale
// AVR Mortgage Before Sales                                                                                             
// Column:AVR_MTG_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_mtg_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"avr_mtg_bef_sale",t);
}



//^^^

#line 1 "avr_mtg_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_mtg_bef_sale", t, SUM_OVER_ALL);

return avr_calc(t, "Before Sales", "Mortgages");

}


//@@ END

//@@ START - avr_mtg_bocy
// AVR Mortgage Beginning of Calendar Year                                                                                             
// Column:AVR_MTG_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_mtg_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"avr_mtg_bocy",t);
}



//^^^

#line 1 "avr_mtg_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return sum_over_segments("avr_mtg_bocy", t, SUM_OVER_ALL);

if (t != 1 && cal_mth(t) == 1)
	return avr_mtg(t - 1);

return avr_mtg_bocy(t - 1);

}


//@@ END

//@@ START - avr_other
// AVR Other                                                                                             
// Column:AVR_OTHER
//========================================================
double COMP_COMP_UDF::comp_comp_avr_other(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"avr_other",t);
}



//^^^

#line 1 "avr_other.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_other", t, SUM_OVER_ALL);

if (t == start_period)
	return sum_over_segments("avr_other_bocy", t, SUM_OVER_ALL);

return avr_calc(t, "After Sales", "Other");

}


//@@ END

//@@ START - avr_other_bef_sale
// AVR Other Before Sales                                                                                             
// Column:AVR_OTHER_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_other_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"avr_other_bef_sale",t);
}



//^^^

#line 1 "avr_other_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_other_bef_sale", t, SUM_OVER_ALL);

return avr_calc(t, "Before Sales", "Other");

}


//@@ END

//@@ START - avr_other_bocy
// AVR Other Beginning of Calendar Year                                                                                             
// Column:AVR_OTHER_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_other_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(45,"avr_other_bocy",t);
}



//^^^

#line 1 "avr_other_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return sum_over_segments("avr_other_bocy", t, SUM_OVER_ALL);

if (t != 1 && cal_mth(t) == 1)
	return avr_other(t - 1);
  
return avr_other_bocy(t - 1);

}


//@@ END

//@@ START - avr_stock
// AVR Stock                                                                                             
// Column:AVR_STOCK
//========================================================
double COMP_COMP_UDF::comp_comp_avr_stock(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"avr_stock",t);
}



//^^^

#line 1 "avr_stock.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_stock", t, SUM_OVER_ALL);

if (t == start_period)
	return sum_over_segments("avr_stock_bocy", t, SUM_OVER_ALL);

return avr_calc(t, "After Sales", "Stock");

}


//@@ END

//@@ START - avr_stock_bef_sale
// AVR Stock Before Sales                                                                                             
// Column:AVR_STOCK_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_avr_stock_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"avr_stock_bef_sale",t);
}



//^^^

#line 1 "avr_stock_bef_sale.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t <= start_period || t > final_period)
	return NO_AVG;

if (!tcm_flag)
	return sum_over_segments("avr_stock_bef_sale", t, SUM_OVER_ALL);

return avr_calc(t, "Before Sales", "Stock");

}


//@@ END

//@@ START - avr_stock_bocy
// AVR Stock Beginning of Calendar Year                                                                                             
// Column:AVR_STOCK_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_stock_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(48,"avr_stock_bocy",t);
}



//^^^

#line 1 "avr_stock_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return sum_over_segments("avr_stock_bocy", t, SUM_OVER_ALL);

if (t != 1 && cal_mth(t) == 1)
	return avr_stock(t - 1);

return avr_stock_bocy(t - 1);

}


//@@ END

//@@ START - avr_unrealzd_cap_gain_eqt_bocy
// AVR Unrealized Capital Gain Equity Beginning of Calendar Year                                                                                             
// Column:AVR_UNREALZD_CAP_GAIN_EQT_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_unrealzd_cap_gain_eqt_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"avr_unrealzd_cap_gain_eqt_bocy",t);
}



//^^^

#line 1 "avr_unrealzd_cap_gain_eqt_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return 0;

if (t != 1 && cal_mth(t) == 1)
	{
	double total = 0.0;
	for (int segment = 0; segment < sm_seg.size(); segment++)
		total += sm_seg[segment]->avr_components(t - 1, 16 /*avr_unrealized_capital_gains_stock*/);

	return total;
	}
  
return avr_unrealzd_cap_gain_eqt_bocy(t - 1);

}


//@@ END

//@@ START - avr_unrealzd_cap_gain_non_eqt_bocy
// AVR Unrealized Capital Gain Non Equity Beginning of Calendar Year                                                                                             
// Column:AVR_UNREALZD_CAP_GAIN_NON_EQT_BOCY
//========================================================
double COMP_COMP_UDF::comp_comp_avr_unrealzd_cap_gain_non_eqt_bocy(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"avr_unrealzd_cap_gain_non_eqt_bocy",t);
}



//^^^

#line 1 "avr_unrealzd_cap_gain_non_eqt_bocy.COMP_COMP.for"
if (!avr_flag || !alm_flag 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	return 0;

if (t != 1 && cal_mth(t) == 1)
	{
	double total = 0.0;
	for (int segment = 0; segment < sm_seg.size(); segment++)
		total += sm_seg[segment]->avr_components(t - 1, 17 /*unrealized_capital_gains_other*/);

	return total;
	}
  
return avr_unrealzd_cap_gain_non_eqt_bocy(t - 1);

}


//@@ END

//@@ START - bef_tax_yld
// Before Tax Yield                                                                                             
// Column:BEF_TAX_YLD
//========================================================
double COMP_COMP_UDF::comp_comp_bef_tax_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(51,"bef_tax_yld",t);
}



//^^^

#line 1 "bef_tax_yld.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return asset_yld(t);

}


//@@ END

//@@ START - bk_prof_aft_tax
// Book Profit After Tax                                                                                             
// Column:BK_PROF_AFT_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(52,"bk_prof_aft_tax",t);
}



//^^^

#line 1 "bk_prof_aft_tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call bk_prof_aft_tax from segments
sum_over_segments("bk_prof_aft_tax", t, SUM_OVER_ALL);

return bk_prof_bef_tax(t)
       - tax_bk_prof(t);

}


//@@ END

//@@ START - bk_prof_aft_tax_bef_sale
// Book Profit After Tax Before Sales                                                                                             
// Column:BK_PROF_AFT_TAX_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(53,"bk_prof_aft_tax_bef_sale",t);
}



//^^^

#line 1 "bk_prof_aft_tax_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return bk_prof_bef_tax_bef_sale(t)
       - tax_bk_prof_bef_sale(t);

}


//@@ END

//@@ START - bk_prof_aft_tax_for_pv
// Book Profit After Tax for Present Values                                                                                             
// Column:BK_PROF_AFT_TAX_FOR_PV
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(54,"bk_prof_aft_tax_for_pv",t);
}



//^^^

#line 1 "bk_prof_aft_tax_for_pv.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return bk_prof_aft_tax(t);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return bk_prof_aft_tax_qtd(t);	

if (prof_distribn_mode == ANNUAL
	&& (xint(cal_mth(t)) == 12
		|| t == final_period))
	return bk_prof_aft_tax_ytd(t);

return 0.0;

}


//@@ END

//@@ START - bk_prof_aft_tax_irr
// Book Profit After Tax for IRR                                                                                             
// Column:BK_PROF_AFT_TAX_IRR
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_irr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"bk_prof_aft_tax_irr",t);
}



//^^^

#line 1 "bk_prof_aft_tax_irr.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_irr;

	return NO_AVG;
	}

if (bk_prof_aft_tax_irr(t - 1) >= 0)
	return bk_prof_aft_tax_irr(t - 1)
		   * pow((1.0 + max(port_yld_aft_tax(t), -.99)), (1.0 / 12.0))
		   + bk_prof_aft_tax_for_pv(t);	

return bk_prof_aft_tax_irr(t - 1);

}


//@@ END

//@@ START - bk_prof_aft_tax_qtd
// Book Profit After Tax Calendar Quarter to Date                                                                                             
// Column:BK_PROF_AFT_TAX_QTD
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"bk_prof_aft_tax_qtd",t);
}



//^^^

#line 1 "bk_prof_aft_tax_qtd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_qtd;
		
	return NO_AVG;	
	}

if (xint(cal_mth(t)) % 3 == 1)
	return bk_prof_aft_tax(t);
	
return bk_prof_aft_tax_qtd(t - 1)
	   + bk_prof_aft_tax(t);

}


//@@ END

//@@ START - bk_prof_aft_tax_ytd
// Book Profit After Tax Calendar Year to Date                                                                                             
// Column:BK_PROF_AFT_TAX_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"bk_prof_aft_tax_ytd",t);
}



//^^^

#line 1 "bk_prof_aft_tax_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_ytd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) == 1)
	return bk_prof_aft_tax(t);
	
return bk_prof_aft_tax_ytd(t - 1)
       + bk_prof_aft_tax(t);

}


//@@ END

//@@ START - bk_prof_bef_tax
// Book Profit Before Tax                                                                                             
// Column:BK_PROF_BEF_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_bef_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"bk_prof_bef_tax",t);
}



//^^^

#line 1 "bk_prof_bef_tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call for reporting
direct_cash_flow_bom(t);
direct_cash_flow_eom(t);
bk_prof_by_source_bef_tax(t);

return prem_paid(t)
	   + div_applied(t)
	   + annuitzn_inc(t)
	   + deferred_gross_prem_incr(t)
	   - stat_unearn_prem_res_incr(t)
	   + inv_inc_bk_prof(t)
	   + inv_fee_ref(t)
	   - dth_benefits(t)
	   - ann_benefits_bom(t)
	   - ann_benefits_eom(t)
	   - endow_benefits(t)
	   - conversion_cost(t)
	   - maturity_benefits(t)
	   - surr_benefits(t)
	   - withdrl_benefits(t)
	   - claim_paid(t)
	   - prem_waiver_benefits(t)	
	   - div_paid(t)
	   - terminal_div(t)
	   - stat_loading_incr(t)
	   - stat_claim_res_incr(t)
	   - stat_prem_waiver_res_incr(t)
       - stat_res_incr(t)
	   + loc_asset_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
       - stat_claim_exp_res_incr(t)
	   - stat_prem_waiver_exp_res_incr(t)
	   - loc_cost(t)
	   - reins_stat_cost(t)
	   - hedge_cost(t)	
	   - div_liab_incr(t)
       - transfer_to_sa_net(t)
	   - xol_prem_aig(t); //20230127 SJ: For XOL Deal, deduct XOL premium from profits.

}


//@@ END

//@@ START - bk_prof_bef_tax_bef_sale
// Book Profit Before Tax Before Sales                                                                                             
// Column:BK_PROF_BEF_TAX_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"bk_prof_bef_tax_bef_sale",t);
}



//^^^

#line 1 "bk_prof_bef_tax_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return prem_paid(t)
	   + div_applied(t)
	   + annuitzn_inc(t)
	   + deferred_gross_prem_incr(t)
	   - stat_unearn_prem_res_incr(t)
	   + inv_inc_bk_prof_bef_sale(t)
	   + inv_fee_ref(t)
	   - dth_benefits(t)
	   - ann_benefits_bom(t)
	   - ann_benefits_eom(t)
	   - endow_benefits(t)
	   - conversion_cost(t)
	   - maturity_benefits(t)
	   - surr_benefits(t)	
       - withdrl_benefits(t)
       - claim_paid(t)
       - prem_waiver_benefits(t)
       - div_paid(t)
       - terminal_div(t)
	   - stat_loading_incr(t)
	   - stat_claim_res_incr(t)
	   - stat_prem_waiver_res_incr(t)
       - stat_res_incr(t)
	   + loc_asset_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
       - stat_claim_exp_res_incr(t)
	   - stat_prem_waiver_exp_res_incr(t)
	   - loc_cost(t)
	   - reins_stat_cost_bef_sale(t)
	   - hedge_cost_bef_sale(t)	
	   - div_liab_incr(t)
       - transfer_to_sa_net(t);

}


//@@ END

//@@ START - bk_prof_bef_tax_for_pv
// Book Profit Before Tax for Present Values                                                                                             
// Column:BK_PROF_BEF_TAX_FOR_PV
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"bk_prof_bef_tax_for_pv",t);
}



//^^^

#line 1 "bk_prof_bef_tax_for_pv.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return bk_prof_bef_tax(t);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return bk_prof_bef_tax_qtd(t);	

if (prof_distribn_mode == ANNUAL
	&& (xint(cal_mth(t)) == 12
		|| t == final_period))
	return bk_prof_bef_tax_ytd(t);

return 0.0;

}


//@@ END

//@@ START - bk_prof_bef_tax_qtd
// Book Profit Before Tax Calendar Quarter to Date                                                                                             
// Column:BK_PROF_BEF_TAX_QTD
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"bk_prof_bef_tax_qtd",t);
}



//^^^

#line 1 "bk_prof_bef_tax_qtd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_bef_tax_qtd;
		
	return NO_AVG;	
	}

if (xint(cal_mth(t)) % 3 == 1)
	return bk_prof_bef_tax(t);
	
return bk_prof_bef_tax_qtd(t - 1)
	   + bk_prof_bef_tax(t);

}


//@@ END

//@@ START - bk_prof_bef_tax_ytd
// Book Profit Before Tax Calendar Year to Date                                                                                             
// Column:BK_PROF_BEF_TAX_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(62,"bk_prof_bef_tax_ytd",t);
}



//^^^

#line 1 "bk_prof_bef_tax_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_bef_tax_ytd;
		
	return NO_AVG;	
	}

if (xint(cal_mth(t)) == 1)
	return bk_prof_bef_tax(t);
	
return bk_prof_bef_tax_ytd(t - 1)
       + bk_prof_bef_tax(t);

}


//@@ END

//@@ START - bk_prof_by_source_bef_tax
// Book Profit By Source Before Tax                                                                                             
// Column:BK_PROF_BY_SOURCE_BEF_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_bk_prof_by_source_bef_tax(int t) {
//^^^



//^^^

#line 1 "bk_prof_by_source_bef_tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("bk_prof_by_source_bef_tax", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - bk_val
// Book Value                                                                                             
// Column:BK_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(64,"bk_val",t);
}



//^^^

#line 1 "bk_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call for reporting
cost_basis_purch(t);

return sum_over_segments("bk_val", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - bk_val_inv
// Book Value Investment Assets                                                                                             
// Column:BK_VAL_INV
//========================================================
double COMP_COMP_UDF::comp_comp_bk_val_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(65,"bk_val_inv",t);
}



//^^^

#line 1 "bk_val_inv.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("bk_val_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - borrowing
// Borrowing                                                                                             
// Column:BORROWING
//========================================================
double COMP_COMP_UDF::comp_comp_borrowing(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(66,"borrowing",t);
}



//^^^

#line 1 "borrowing.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("borrowing", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - borrowing_int
// Borrowing Interest                                                                                             
// Column:BORROWING_INT
//========================================================
double COMP_COMP_UDF::comp_comp_borrowing_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(67,"borrowing_int",t);
}



//^^^

#line 1 "borrowing_int.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("borrowing_int", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double COMP_COMP_UDF::comp_comp_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.COMP_COMP.for"
if (t == start_period)
	return get_mth_from_date(proj_date_adj);

return proj_start_mth + t - 1
	   - 12 * floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double COMP_COMP_UDF::comp_comp_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.COMP_COMP.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double COMP_COMP_UDF::comp_comp_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(70,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.COMP_COMP.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain
// Capital Gains                                                                                             
// Column:CAP_GAIN
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(71,"cap_gain",t);
}



//^^^

#line 1 "cap_gain.COMP_COMP.for"
if (!alm_flag  || t <= start_period || t > final_period)
	return NO_AVG;

return cap_gain_bef_sale(t)
       + cap_gain_from_sale(t);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(72,"cap_gain_bef_sale",t);
}



//^^^

#line 1 "cap_gain_bef_sale.COMP_COMP.for"
if (!alm_flag  || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_free_surp
// Capital Gains on Free Surplus                                                                                             
// Column:CAP_GAIN_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(73,"cap_gain_free_surp",t);
}



//^^^

#line 1 "cap_gain_free_surp.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("cap_gain_free_surp", t, CORPORATE_SEGMENT);

return sum_over_segments("cap_gain_free_surp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_free_surp_bef_sale
// Capital Gains on Free Surplus Before Sales                                                                                             
// Column:CAP_GAIN_FREE_SURP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_free_surp_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(74,"cap_gain_free_surp_bef_sale",t);
}



//^^^

#line 1 "cap_gain_free_surp_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("cap_gain_free_surp_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("cap_gain_free_surp_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_from_sale
// Capital Gains from Sales                                                                                             
// Column:CAP_GAIN_FROM_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_from_sale(int t) {
//^^^



//^^^

#line 1 "cap_gain_from_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_from_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_res
// Capital Gains on Reserve                                                                                             
// Column:CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"cap_gain_res",t);
}



//^^^

#line 1 "cap_gain_res.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - cap_gain_res_bef_sale
// Capital Gains on Reserve Before Sales                                                                                             
// Column:CAP_GAIN_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"cap_gain_res_bef_sale",t);
}



//^^^

#line 1 "cap_gain_res_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - cap_gain_tgt_cap
// Capital Gains on Target Capital                                                                                             
// Column:CAP_GAIN_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(78,"cap_gain_tgt_cap",t);
}



//^^^

#line 1 "cap_gain_tgt_cap.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_tgt_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_tgt_cap_bef_sale
// Capital Gains on Target Capital Before Sales                                                                                             
// Column:CAP_GAIN_TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(79,"cap_gain_tgt_cap_bef_sale",t);
}



//^^^

#line 1 "cap_gain_tgt_cap_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cap_gain_tgt_cap_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_undistrib_earnings
// Capital Gains on Undistributed Earnings                                                                                             
// Column:CAP_GAIN_UNDISTRIB_EARNINGS
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(80,"cap_gain_undistrib_earnings",t);
}



//^^^

#line 1 "cap_gain_undistrib_earnings.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("cap_gain_undistrib_earnings", t, CORPORATE_SEGMENT);

return sum_over_segments("cap_gain_undistrib_earnings", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cap_gain_undistrib_earnings_bef_sale
// Capital Gains on Undistributed Earnings Before Sales                                                                                             
// Column:CAP_GAIN_UNDISTRIB_EARNINGS_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cap_gain_undistrib_earnings_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(81,"cap_gain_undistrib_earnings_bef_sale",t);
}



//^^^

#line 1 "cap_gain_undistrib_earnings_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("cap_gain_undistrib_earnings_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("cap_gain_undistrib_earnings_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash
// Cash                                                                                             
// Column:CASH
//========================================================
double COMP_COMP_UDF::comp_comp_cash(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(82,"cash",t);
}



//^^^

#line 1 "cash.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("cash", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash_flow_for_inv
// Cash Flow For Investment                                                                                             
// Column:CASH_FLOW_FOR_INV
//========================================================
double COMP_COMP_UDF::comp_comp_cash_flow_for_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(83,"cash_flow_for_inv",t);
}



//^^^

#line 1 "cash_flow_for_inv.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cash_flow_for_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash_flow_int
// Cash Flow Interest                                                                                             
// Column:CASH_FLOW_INT
//========================================================
double COMP_COMP_UDF::comp_comp_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(84,"cash_flow_int",t);
}



//^^^

#line 1 "cash_flow_int.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return direct_cash_flow_int(t)
	   - reins_cash_flow_int(t);

}


//@@ END

//@@ START - cash_flow_invested
// Cash Flow Invested                                                                                             
// Column:CASH_FLOW_INVESTED
//========================================================
double COMP_COMP_UDF::comp_comp_cash_flow_invested(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(85,"cash_flow_invested",t);
}



//^^^

#line 1 "cash_flow_invested.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cash_flow_invested", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash_int
// Cash Interest                                                                                             
// Column:CASH_INT
//========================================================
double COMP_COMP_UDF::comp_comp_cash_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(86,"cash_int",t);
}



//^^^

#line 1 "cash_int.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cash_int", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash_int_inv
// Cash Interest For Asset Yield Investment                                                                                             
// Column:CASH_INT_INV
//========================================================
double COMP_COMP_UDF::comp_comp_cash_int_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(87,"cash_int_inv",t);
}



//^^^

#line 1 "cash_int_inv.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cash_int_inv", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cash_val
// Cash Value                                                                                             
// Column:CASH_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(88,"cash_val",t);
}



//^^^

#line 1 "cash_val.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("cash_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - claim_paid
// Claim Paid                                                                                             
// Column:CLAIM_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_claim_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(89,"claim_paid",t);
}



//^^^

#line 1 "claim_paid.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("claim_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - comm_bom
// Commissions Beginning of Month                                                                                             
// Column:COMM_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(90,"comm_bom",t);
}



//^^^

#line 1 "comm_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("comm_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - comm_chargeback
// Commission Chargeback                                                                                             
// Column:COMM_CHARGEBACK
//========================================================
double COMP_COMP_UDF::comp_comp_comm_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(91,"comm_chargeback",t);
}



//^^^

#line 1 "comm_chargeback.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("comm_chargeback", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - comm_eom
// Commissions End of Month                                                                                             
// Column:COMM_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"comm_eom",t);
}



//^^^

#line 1 "comm_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("comm_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - conversion_cost
// Conversion Cost                                                                                             
// Column:CONVERSION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_conversion_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"conversion_cost",t);
}



//^^^

#line 1 "conversion_cost.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("conversion_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - cost_basis_accrual
// Cost Basis Accrual                                                                                             
// Column:COST_BASIS_ACCRUAL
//========================================================
double COMP_COMP_UDF::comp_comp_cost_basis_accrual(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"cost_basis_accrual",t);
}



//^^^

#line 1 "cost_basis_accrual.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cost_basis_accrual", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cost_basis_incr_appreciation
// Cost Basis Increase Appreciation                                                                                             
// Column:COST_BASIS_INCR_APPRECIATION
//========================================================
double COMP_COMP_UDF::comp_comp_cost_basis_incr_appreciation(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"cost_basis_incr_appreciation",t);
}



//^^^

#line 1 "cost_basis_incr_appreciation.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cost_basis_incr_appreciation", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cost_basis_purch
// Cost Basis Purchase                                                                                             
// Column:COST_BASIS_PURCH
//========================================================
double COMP_COMP_UDF::comp_comp_cost_basis_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(96,"cost_basis_purch",t);
}



//^^^

#line 1 "cost_basis_purch.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cost_basis_purch", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - cost_basis_sale
// Cost Basis Sale                                                                                             
// Column:COST_BASIS_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_cost_basis_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("cost_basis_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double COMP_COMP_UDF::comp_comp_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"credited_int",t);
}



//^^^

#line 1 "credited_int.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("credited_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double COMP_COMP_UDF::comp_comp_date(int t) {
//^^^



//^^^

#line 1 "date.COMP_COMP.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - deferred_gross_prem
// Deferred Gross Premium                                                                                             
// Column:DEFERRED_GROSS_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_deferred_gross_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(100,"deferred_gross_prem",t);
}



//^^^

#line 1 "deferred_gross_prem.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("deferred_gross_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - deferred_gross_prem_incr
// Deferred Gross Premium Increase                                                                                             
// Column:DEFERRED_GROSS_PREM_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_deferred_gross_prem_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"deferred_gross_prem_incr",t);
}



//^^^

#line 1 "deferred_gross_prem_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return deferred_gross_prem(t)
	   - deferred_gross_prem(t - 1);

}


//@@ END

//@@ START - deferred_net_prem
// Deferred Net Premium                                                                                             
// Column:DEFERRED_NET_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(102,"deferred_net_prem",t);
}



//^^^

#line 1 "deferred_net_prem.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("deferred_net_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_inv_amt
// Delta Hedge Investment Amount                                                                                             
// Column:DELTA_HEDGE_INV_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_inv_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_inv_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_mkt_val
// Delta Hedge Market Value of Assets                                                                                             
// Column:DELTA_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "delta_hedge_mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_mkt_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_mkt_val_incr
// Delta Hedge Market Value of Assets Increase                                                                                             
// Column:DELTA_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "delta_hedge_mkt_val_incr.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_mkt_val_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_pmt
// Delta Hedge Derivative Payment                                                                                             
// Column:DELTA_HEDGE_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_prof
// Delta Hedge Profit                                                                                             
// Column:DELTA_HEDGE_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_prof(int t) {
//^^^



//^^^

#line 1 "delta_hedge_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_sale_amt
// Delta Hedge Sale Amount                                                                                             
// Column:DELTA_HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "delta_hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_sale_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - delta_hedge_transaction_cost
// Delta Hedge Transaction Cost                                                                                             
// Column:DELTA_HEDGE_TRANSACTION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_delta_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "delta_hedge_transaction_cost.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("delta_hedge_transaction_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - dflt_amt
// Default Amount                                                                                             
// Column:DFLT_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_dflt_amt(int t) {
//^^^



//^^^

#line 1 "dflt_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

// force call for reporting
accr_int_dflt(t);

return sum_over_segments("dflt_amt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - direct_cash_flow_bom
// Direct Cash Flow Beginning of Month                                                                                             
// Column:DIRECT_CASH_FLOW_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_direct_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(111,"direct_cash_flow_bom",t);
}



//^^^

#line 1 "direct_cash_flow_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return prem_paid(t)
       - prem_waiver_benefits(t) 
	   - ann_benefits_bom(t) 
	   + div_applied(t)
       + inv_fee_ref(t)
	   - acq_exp(t) 
	   - maint_exp_bom(t)
	   - prem_tax(t) 
	   - comm_bom(t)
	   + transfer_cash_flow_sa_bom(t)
	   - div_paid(t);

return NO_AVG;

}


//@@ END

//@@ START - direct_cash_flow_eom
// Direct Cash Flow End of Month                                                                                             
// Column:DIRECT_CASH_FLOW_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_direct_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"direct_cash_flow_eom",t);
}



//^^^

#line 1 "direct_cash_flow_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return - dth_benefits(t)
       - maturity_benefits(t)
       - endow_benefits(t)
       - ann_benefits_eom(t)
       - claim_paid(t)
       - annuitzn_val_released(t)
       - surr_benefits(t)
       - withdrl_benefits(t)
       - terminal_div(t)
       - pol_loan_proceeds(t)
       - pol_loan_exp(t)
       - conversion_cost(t) 
	   - maint_exp_eom(t) 
	   - comm_eom(t)
       + comm_chargeback(t)
       - loc_cost(t)
       + annuitzn_consideration(t) 
       + transfer_cash_flow_sa_eom(t);

return NO_AVG;

}


//@@ END

//@@ START - direct_cash_flow_int
// Direct Cash Flow Interest                                                                                             
// Column:DIRECT_CASH_FLOW_INT
//========================================================
double COMP_COMP_UDF::comp_comp_direct_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"direct_cash_flow_int",t);
}



//^^^

#line 1 "direct_cash_flow_int.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("direct_cash_flow_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - disc_rate_1
// Discount Rate 1                                                                                             
// Column:DISC_RATE_1
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(114,"disc_rate_1",t);
}



//^^^

#line 1 "disc_rate_1.COMP_COMP.for"
// This column is calculated when column discount rates are requested
if (t < start_period || disc_rates.size() < 1)
	return NO_AVG;

// Set lookup key 
disc_rate_id = xstring(disc_rates[0]);

static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
                  * mult + addn), (1.0 / 12.0)) - 1.0;

}


//@@ END

//@@ START - disc_rate_2
// Discount Rate 2                                                                                             
// Column:DISC_RATE_2
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_2(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(115,"disc_rate_2",t);
}



//^^^

#line 1 "disc_rate_2.COMP_COMP.for"
// This column is calculated when column discount rates are requested
if (t < start_period || disc_rates.size() < 2)
	return NO_AVG;

// Set lookup key 
disc_rate_id = xstring(disc_rates[1]);

static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
                  * mult + addn), (1.0 / 12.0)) - 1.0;

}


//@@ END

//@@ START - disc_rate_3
// Discount Rate 3                                                                                             
// Column:DISC_RATE_3
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_3(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(116,"disc_rate_3",t);
}



//^^^

#line 1 "disc_rate_3.COMP_COMP.for"
// This column is calculated when column discount rates are requested
if (t < start_period || disc_rates.size() < 3)
	return NO_AVG;

// Set lookup key 
disc_rate_id = xstring(disc_rates[2]);

static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
                  * mult + addn), (1.0 / 12.0)) - 1.0;

}


//@@ END

//@@ START - disc_rate_aig_curve_ic_uel_aig
// Discount Rate for AIG discounting.  This is risk-free rate plus Internal Capital UEL spread.                                                                                             
// Column:DISC_RATE_AIG_CURVE_IC_UEL_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_ic_uel_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(117,"disc_rate_aig_curve_ic_uel_aig",t);
}



//^^^

#line 1 "disc_rate_aig_curve_ic_uel_aig.COMP_COMP.for"
// 20200228 MTC - Risk Free Rate with Internal Capital Spread
if (t < start_period)
	return NO_AVG;

return risk_free_rate_with_ic_uel_sprd_aig(t);

}


//@@ END

//@@ START - disc_rate_aig_curve_no_uel_aig
// Discount Rate for AIG discounting.  This is risk-free rate plus non-UEL spread.                                                                                             
// Column:DISC_RATE_AIG_CURVE_NO_UEL_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_no_uel_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(118,"disc_rate_aig_curve_no_uel_aig",t);
}



//^^^

#line 1 "disc_rate_aig_curve_no_uel_aig.COMP_COMP.for"
// 20190411 MTC - AIG Discount Curve no UEL
if (t < start_period)
	return NO_AVG;

return risk_free_rate_with_no_uel_sprd_aig(t);

}


//@@ END

//@@ START - disc_rate_aig_curve_uel_aig
// Discount Rate for AIG discounting.  This is risk-free rate plus UEL spread, or the "AIG curve".                                                                                             
// Column:DISC_RATE_AIG_CURVE_UEL_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_uel_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(119,"disc_rate_aig_curve_uel_aig",t);
}



//^^^

#line 1 "disc_rate_aig_curve_uel_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
if (t < start_period)
	return NO_AVG;

return risk_free_rate_with_uel_sprd_aig(t);

}


//@@ END

//@@ START - disc_rate_port_yld
// Discount Rate Portfolio Yield                                                                                             
// Column:DISC_RATE_PORT_YLD
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_port_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"disc_rate_port_yld",t);
}



//^^^

#line 1 "disc_rate_port_yld.COMP_COMP.for"
if ((time_step_flag && valn_flag) || t <= start_period || t > final_period)
	return NO_AVG; 

if (disc_rate_port_yld_defn == BEFORE_TAX)
	return pow(1.0 + max(bef_tax_yld(t), -.99), (1.0 / 12.0)) - 1.0;

if (disc_rate_port_yld_defn == AFTER_TAX)
	return pow(1.0 + max(port_yld_aft_tax(t), -.99), (1.0 / 12.0)) - 1.0;

return 0.0;

}


//@@ END

//@@ START - disc_rate_port_yld_defn_val
// Discount Rate Portfolio Ylield Definition Value                                                                                             
// Column:DISC_RATE_PORT_YLD_DEFN_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_port_yld_defn_val(int t) {
//^^^



//^^^

#line 1 "disc_rate_port_yld_defn_val.COMP_COMP.for"
// This column is required to send the value of disc_rate_port_yld_defn to the reporting tool
if (t != start_period + 1 || valn_period > 0)
	return NO_AVG;	

if (disc_rate_port_yld_defn == BEFORE_TAX)
	return 1;
	
// if (disc_rate_port_yld_defn == AFTER_TAX)	
return 2;

}


//@@ END

//@@ START - disc_rate_risk_free_aig
// Discount Rate for risk-free discounting.  This is risk-free rate without the spread.                                                                                             
// Column:DISC_RATE_RISK_FREE_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_disc_rate_risk_free_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(122,"disc_rate_risk_free_aig",t);
}



//^^^

#line 1 "disc_rate_risk_free_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
if (t < start_period)
	return NO_AVG;

return risk_free_rate_no_sprd_aig(t);

}


//@@ END

//@@ START - distrib_earnings
// Distributable Earnings                                                                                             
// Column:DISTRIB_EARNINGS
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(123,"distrib_earnings",t);
}



//^^^

#line 1 "distrib_earnings.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// these items must be calculated each period in order to determine 
// correct present values of profit measures
bk_prof_bef_tax_for_pv(t);
bk_prof_aft_tax_for_pv(t);

// force call accumulated earnings for reporting
earnings_accum(t); 

// force call distrib_earnings from segments
sum_over_segments("distrib_earnings", t, SUM_OVER_ALL);

double distrib_earnings
= undistrib_earnings(t - 1)
  + bk_prof_aft_tax(t)
  + tgt_cap_effect(t);
	       
if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY 
         && (xint(cal_mth(t)) % 3 == 0))
	|| prof_distribn_mode == MONTHLY)
	return distrib_earnings;

return NO_AVG;

}


//@@ END

//@@ START - distrib_earnings_be
// Distributable Earnings Break-Even                                                                                             
// Column:DISTRIB_EARNINGS_BE
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings_be(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(124,"distrib_earnings_be",t);
}



//^^^

#line 1 "distrib_earnings_be.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == 1)
	return 1;

if (distrib_earnings_be(t - 1) == 0)
	return 0;

if (distrib_earnings_cum(t) < 0)
	return 1;

return 0;

}


//@@ END

//@@ START - distrib_earnings_bef_sale
// Distributable Earnings Before Sales                                                                                             
// Column:DISTRIB_EARNINGS_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(125,"distrib_earnings_bef_sale",t);
}



//^^^

#line 1 "distrib_earnings_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY 
         && (xint(cal_mth(t)) % 3 == 0))
	|| prof_distribn_mode == MONTHLY)
	return undistrib_earnings(t - 1)
	       + bk_prof_aft_tax_bef_sale(t)
	       + tgt_cap_effect_bef_sale(t);

return NO_AVG;

}


//@@ END

//@@ START - distrib_earnings_cum
// Distributable Earnings Cumulative                                                                                             
// Column:DISTRIB_EARNINGS_CUM
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings_cum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(126,"distrib_earnings_cum",t);
}



//^^^

#line 1 "distrib_earnings_cum.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == 1)
	return distrib_earnings(t);
		   
return distrib_earnings_cum(t - 1) + distrib_earnings(t);

}


//@@ END

//@@ START - distrib_earnings_irr
// Distributable Earnings for IRR                                                                                             
// Column:DISTRIB_EARNINGS_IRR
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings_irr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(127,"distrib_earnings_irr",t);
}



//^^^

#line 1 "distrib_earnings_irr.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_distrib_earnings_irr;

	return NO_AVG;
	}

if (distrib_earnings_irr(t - 1) >= 0)
	return distrib_earnings_irr(t - 1)
		   * pow((1.0 + max(port_yld_aft_tax(t), -.99)), (1.0 / 12.0))
		   + distrib_earnings(t);	

return distrib_earnings_irr(t - 1);

}


//@@ END

//@@ START - distrib_earnings_strain
// Distributable Earnings for month 1 for strain                                                                                             
// Column:DISTRIB_EARNINGS_STRAIN
//========================================================
double COMP_COMP_UDF::comp_comp_distrib_earnings_strain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(128,"distrib_earnings_strain",t);
}



//^^^

#line 1 "distrib_earnings_strain.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == 1)
	return distrib_earnings(1);

return NO_AVG;

}


//@@ END

//@@ START - div_applied
// Dividend Applied                                                                                             
// Column:DIV_APPLIED
//========================================================
double COMP_COMP_UDF::comp_comp_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(129,"div_applied",t);
}



//^^^

#line 1 "div_applied.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("div_applied", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - div_liab
// Dividend Liability                                                                                             
// Column:DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(130,"div_liab",t);
}



//^^^

#line 1 "div_liab.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - div_liab_incr
// Dividend Liability Increase                                                                                             
// Column:DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(131,"div_liab_incr",t);
}



//^^^

#line 1 "div_liab_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return div_liab(t)
	   - div_liab(t - 1);

}


//@@ END

//@@ START - div_paid
// Dividend Paid                                                                                             
// Column:DIV_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(132,"div_paid",t);
}



//^^^

#line 1 "div_paid.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("div_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - dth_ben_inf
// Death Benefit In Force                                                                                             
// Column:DTH_BEN_INF
//========================================================
double COMP_COMP_UDF::comp_comp_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(133,"dth_ben_inf",t);
}



//^^^

#line 1 "dth_ben_inf.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("dth_ben_inf", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - dth_benefits
// Death Benefits                                                                                             
// Column:DTH_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(134,"dth_benefits",t);
}



//^^^

#line 1 "dth_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("dth_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - dth_count_aig
// Death Count Monthly                                                                                             
// Column:DTH_COUNT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_dth_count_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(135,"dth_count_aig",t);
}



//^^^

#line 1 "dth_count_aig.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("dth_count_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - earnings_accum
// Accumulated Earnings                                                                                             
// Column:EARNINGS_ACCUM
//========================================================
double COMP_COMP_UDF::comp_comp_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(136,"earnings_accum",t);
}



//^^^

#line 1 "earnings_accum.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_earnings_accum;

	return NO_AVG;
	}

double distrib_earnings = 0.0;
	       
if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY 
         && (xint(cal_mth(t)) % 3 == 0))
	|| prof_distribn_mode == MONTHLY)
	distrib_earnings = undistrib_earnings(t - 1)
					   + bk_prof_aft_tax(t)
					   + tgt_cap_effect(t);

return earnings_accum(t - 1)
       + distrib_earnings
       + inv_inc_earnings_accum(t)
       - tax_earnings_accum(t);

}


//@@ END

//@@ START - econ_cash
// Economic Cash Amount                                                                                             
// Column:ECON_CASH
//========================================================
double COMP_COMP_UDF::comp_comp_econ_cash(int t) {
//^^^



//^^^

#line 1 "econ_cash.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_cash", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_cash_int
// Interest Earned on Economic Cash Amount                                                                                             
// Column:ECON_CASH_INT
//========================================================
double COMP_COMP_UDF::comp_comp_econ_cash_int(int t) {
//^^^



//^^^

#line 1 "econ_cash_int.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_cash_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_prof
// Economic Profit                                                                                             
// Column:ECON_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_econ_prof(int t) {
//^^^



//^^^

#line 1 "econ_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_prof_unhedged
// Unhedged Economic Profit                                                                                             
// Column:ECON_PROF_UNHEDGED
//========================================================
double COMP_COMP_UDF::comp_comp_econ_prof_unhedged(int t) {
//^^^



//^^^

#line 1 "econ_prof_unhedged.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_prof_unhedged", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_res
// Economic Reserve: Present Value of Claims - Present Value of Charges                                                                                             
// Column:ECON_RES
//========================================================
double COMP_COMP_UDF::comp_comp_econ_res(int t) {
//^^^



//^^^

#line 1 "econ_res.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_res_incr
// Economic Reserve Increase                                                                                             
// Column:ECON_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_econ_res_incr(int t) {
//^^^



//^^^

#line 1 "econ_res_incr.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - econ_res_int
// Interest Earned on Economic Reserve                                                                                             
// Column:ECON_RES_INT
//========================================================
double COMP_COMP_UDF::comp_comp_econ_res_int(int t) {
//^^^



//^^^

#line 1 "econ_res_int.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("econ_res_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - endow_benefits
// Endowment Benefits                                                                                             
// Column:ENDOW_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(144,"endow_benefits",t);
}



//^^^

#line 1 "endow_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("endow_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double COMP_COMP_UDF::comp_comp_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.COMP_COMP.for"
// Code following this statement is not needed for proxy bond generation
if (proxy_bond_gen_flag) 
    {
    #if defined(__ASSET_ASSET_H_)
    sm_asset->finalize(final_period);
    #endif
    return 1;
    }

// force call asset_less_liab_and_surp
asset_less_liab_and_surp(final_period);

if (!valn_flag)
	{
	inv_asset(final_period);
	liab_and_surp(final_period);
	}

// force call to gaap capital and surplus columns
if (gaap_flag && !valn_flag)
	{
	gaap_req_cap(final_period);
	gaap_free_surp(final_period);
	}

if (time_step_flag && !valn_flag
	&& proj_set_sub_loop_num < valn_periods.size())
	write_state_of_world_financial();

#if defined(__SEG_COMP_H_)
if (!hedge_valn_flag)
	log_screen << "... Finalizing Segments" << MSG_USER;

for (int segment = 0; segment < sm_seg.size(); segment++)
	sm_seg[segment]->finalize(final_period);
#endif

#if defined(__ASSET_ASSET_H_)
if (alm_flag)
	{
	log_screen << "... Finalizing Assets" << MSG_USER;
	sm_asset->finalize(final_period);
	}
#endif

if (!hedge_valn_flag)
	{
	if (time_step_flag && (is_last_proj_task_loop || num_of_proj_task_loops == 0))
		{
		if (valn_flag)
			log_screen << "Completed Valuation For Outer Loop = " << proj_set_loop_num << " :: Period = " << valn_period << MSG_USER;
		else
			log_screen << "Completed Projection For Outer Loop = " << proj_set_loop_num << " :: Period = " << valn_period << MSG_USER;
		}		
	}

return 1.0;

}


//@@ END

//@@ START - free_surp
// Free Surplus                                                                                             
// Column:FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(146,"free_surp",t);
}



//^^^

#line 1 "free_surp.COMP_COMP.for"
if (nb_flag || t < start_period || t > final_period)
	return NO_AVG;

// force a call to unallocated_surplus_at_market
if (alm_flag)
	{
	free_surp_at_mkt(t);

	if (t == final_period)
		free_surp_at_mkt_ending(t);
	}

if (t == start_period)
	{
	if (!alm_flag)	
		return init_free_surp;		

	return inv_asset(t)
		   + pol_loan(t)
		   + deferred_net_prem(t)
		   - reins_deferred_net_prem(t)
		   + loc_asset(t)
		   + hedge_mkt_val(t)
		   - (stat_unearn_prem_res(t)
		      - reins_stat_unearn_prem_res(t)
		      + stat_claim_res(t)
			  + stat_prem_waiver_res(t)
		      - reins_stat_claim_res(t)
			  - reins_stat_prem_waiver_res(t)
		      + stat_res(t)
		      - reins_stat_res(t)
			  + stat_res_sa_exp_allow(t))
		   - imr(t)
		   - avr(t)
		   - tgt_cap(t)
		   - (div_liab(t)	
		      - reins_div_liab(t))
		   - undistrib_earnings(t);
	}  

return free_surp(t - 1) + free_surp_incr(t);

}


//@@ END

//@@ START - free_surp_at_mkt
// Free Surplus at Market                                                                                             
// Column:FREE_SURP_AT_MKT
//========================================================
double COMP_COMP_UDF::comp_comp_free_surp_at_mkt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"free_surp_at_mkt",t);
}



//^^^

#line 1 "free_surp_at_mkt.COMP_COMP.for"
if (nb_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (sm_seg[0]->mths_to_next_mkt_val_calc(t) != 0 && t != 0)
	return 0.0;

// Note: Internally projected hedge assets are included in mkt_val and bk_val
if (t == start_period)
	return inv_asset(t)
		   + pol_loan(t)
		   + deferred_net_prem(t)
		   + loc_asset(t)
		   - (stat_unearn_prem_res(t)
		      - reins_stat_unearn_prem_res(t)
		      + stat_claim_res(t)
			  + stat_prem_waiver_res(t)
		      - reins_stat_claim_res(t)
			  - reins_stat_prem_waiver_res(t)
		      + stat_res(t)
		      - reins_stat_res(t))
		   - imr(t)
		   - avr(t)
		   - tgt_cap(t)
		   - (div_liab(t)	
		      - reins_div_liab(t))
   	    + mkt_val(t)
  	     - bk_val(t);
  
return free_surp_bef_shldr_div(t)
       - shldr_div(t)
       + mkt_val(t)
       - bk_val(t);

}


//@@ END

//@@ START - free_surp_at_mkt_ending
// Free Surplus at Market Ending                                                                                             
// Column:FREE_SURP_AT_MKT_ENDING
//========================================================
double COMP_COMP_UDF::comp_comp_free_surp_at_mkt_ending(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(148,"free_surp_at_mkt_ending",t);
}



//^^^

#line 1 "free_surp_at_mkt_ending.COMP_COMP.for"
if (nb_flag || t != final_period)
	return NO_AVG;

return free_surp_at_mkt(t);

}


//@@ END

//@@ START - free_surp_bef_shldr_div
// Free Surplus Before Shareholder Dividend                                                                                             
// Column:FREE_SURP_BEF_SHLDR_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_free_surp_bef_shldr_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(149,"free_surp_bef_shldr_div",t);
}



//^^^

#line 1 "free_surp_bef_shldr_div.COMP_COMP.for"
if (nb_flag || t <= start_period || t > final_period)
	return NO_AVG;

return free_surp(t - 1)
       + distrib_earnings(t)
       + inv_inc_free_surp(t)
       + cap_gain_free_surp(t)
       - imr_impact_free_surp(t)
       - tax_free_surp(t);

}


//@@ END

//@@ START - free_surp_incr
// Free Surplus Increase                                                                                             
// Column:FREE_SURP_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_free_surp_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(150,"free_surp_incr",t);
}



//^^^

#line 1 "free_surp_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return free_surp_bef_shldr_div(t)
       - shldr_div(t)
       - free_surp(t - 1);

}


//@@ END

//@@ START - fund_released_ann
// Fund Value released on Annuitization                                                                                             
// Column:FUND_RELEASED_ANN
//========================================================
double COMP_COMP_UDF::comp_comp_fund_released_ann(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(151,"fund_released_ann",t);
}



//^^^

#line 1 "fund_released_ann.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_released_ann", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_released_dth
// Fund Value released on Death                                                                                             
// Column:FUND_RELEASED_DTH
//========================================================
double COMP_COMP_UDF::comp_comp_fund_released_dth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(152,"fund_released_dth",t);
}



//^^^

#line 1 "fund_released_dth.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_released_dth", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_released_maturity
// Fund Value released on Maturity                                                                                             
// Column:FUND_RELEASED_MATURITY
//========================================================
double COMP_COMP_UDF::comp_comp_fund_released_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(153,"fund_released_maturity",t);
}



//^^^

#line 1 "fund_released_maturity.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_released_maturity", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_released_surr
// Fund Value released on Surrender                                                                                             
// Column:FUND_RELEASED_SURR
//========================================================
double COMP_COMP_UDF::comp_comp_fund_released_surr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(154,"fund_released_surr",t);
}



//^^^

#line 1 "fund_released_surr.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_released_surr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_released_withdrl
// Fund Value released on Withdrawal                                                                                             
// Column:FUND_RELEASED_WITHDRL
//========================================================
double COMP_COMP_UDF::comp_comp_fund_released_withdrl(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(155,"fund_released_withdrl",t);
}



//^^^

#line 1 "fund_released_withdrl.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_released_withdrl", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_val_fixed
// Fund Value Fixed Account                                                                                             
// Column:FUND_VAL_FIXED
//========================================================
double COMP_COMP_UDF::comp_comp_fund_val_fixed(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(156,"fund_val_fixed",t);
}



//^^^

#line 1 "fund_val_fixed.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_val_fixed", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_val_sa
// Fund Value Separate Account                                                                                             
// Column:FUND_VAL_SA
//========================================================
double COMP_COMP_UDF::comp_comp_fund_val_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(157,"fund_val_sa",t);
}



//^^^

#line 1 "fund_val_sa.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("fund_val_sa", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - fund_weighted_cap_spread_fix_rt_aig
// Fund Weighted Cap Spread Rate Aig                                                                                             
// Column:FUND_WEIGHTED_CAP_SPREAD_FIX_RT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_fund_weighted_cap_spread_fix_rt_aig(int t) {
//^^^



//^^^

#line 1 "fund_weighted_cap_spread_fix_rt_aig.COMP_COMP.for"
//20220428 STW: new column requested by model owner for reporting purposes
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("fund_weighted_cap_spread_fix_rt_aig", t, SUM_OVER_ALL);


}


//@@ END

//@@ START - fund_weighted_par_rate_aig
// Fund Weighted Par Rate Aig                                                                                             
// Column:FUND_WEIGHTED_PAR_RATE_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_fund_weighted_par_rate_aig(int t) {
//^^^



//^^^

#line 1 "fund_weighted_par_rate_aig.COMP_COMP.for"
//20220428 STW: new column requested by model owner for reporting purposes
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("fund_weighted_par_rate_aig", t, SUM_OVER_ALL);


}


//@@ END

//@@ START - fund_weighted_pri_spread_aig
// Fund Weighted Pri Spread Aig                                                                                             
// Column:FUND_WEIGHTED_PRI_SPREAD_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_fund_weighted_pri_spread_aig(int t) {
//^^^



//^^^

#line 1 "fund_weighted_pri_spread_aig.COMP_COMP.for"
//20220428 STW: new column requested by model owner for reporting purposes
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("fund_weighted_pri_spread_aig", t, SUM_OVER_ALL);


}


//@@ END

//@@ START - gaap_accum_ben_claim_cost
// GAAP Accumulation Benefit Claim Cost                                                                                             
// Column:GAAP_ACCUM_BEN_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_accum_ben_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(161,"gaap_accum_ben_claim_cost",t);
}



//^^^

#line 1 "gaap_accum_ben_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_accum_ben_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_acq_exp
// GAAP Acquisition Expenses                                                                                             
// Column:GAAP_ACQ_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(162,"gaap_acq_exp",t);
}



//^^^

#line 1 "gaap_acq_exp.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_acq_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_ann_claim_cost
// GAAP Annuity Claim Cost                                                                                             
// Column:GAAP_ANN_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_ann_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(163,"gaap_ann_claim_cost",t);
}



//^^^

#line 1 "gaap_ann_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_ann_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_ben_res
// GAAP Benefit Reserve                                                                                             
// Column:GAAP_BEN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_ben_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(164,"gaap_ben_res",t);
}



//^^^

#line 1 "gaap_ben_res.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_ben_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_ben_res_incr
// GAAP Benefit Reserve Increase                                                                                             
// Column:GAAP_BEN_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_ben_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(165,"gaap_ben_res_incr",t);
}



//^^^

#line 1 "gaap_ben_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_ben_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_cap_gain_cap
// GAAP Capital Gains on Capital                                                                                             
// Column:GAAP_CAP_GAIN_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_cap_gain_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(166,"gaap_cap_gain_cap",t);
}



//^^^

#line 1 "gaap_cap_gain_cap.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_cap_gain_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_cap_gain_res
// GAAP Capital Gain on Reserves                                                                                             
// Column:GAAP_CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(167,"gaap_cap_gain_res",t);
}



//^^^

#line 1 "gaap_cap_gain_res.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_capzd_acq_exp
// GAAP Capitalized Acquisition Expenses                                                                                             
// Column:GAAP_CAPZD_ACQ_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_capzd_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(168,"gaap_capzd_acq_exp",t);
}



//^^^

#line 1 "gaap_capzd_acq_exp.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_capzd_acq_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_capzd_comm_bom
// GAAP Capitalized Commissions BOM                                                                                             
// Column:GAAP_CAPZD_COMM_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_capzd_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(169,"gaap_capzd_comm_bom",t);
}



//^^^

#line 1 "gaap_capzd_comm_bom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_capzd_comm_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_capzd_comm_eom
// GAAP Capitalized Commissions EOM                                                                                             
// Column:GAAP_CAPZD_COMM_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_capzd_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(170,"gaap_capzd_comm_eom",t);
}



//^^^

#line 1 "gaap_capzd_comm_eom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_capzd_comm_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_capzd_prem_bonus
// GAAP Capitalized Premium Bonus                                                                                             
// Column:GAAP_CAPZD_PREM_BONUS
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_capzd_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(171,"gaap_capzd_prem_bonus",t);
}



//^^^

#line 1 "gaap_capzd_prem_bonus.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_capzd_prem_bonus", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_capzd_reins_yrt_cost
// GAAP Capitalized Reinsurance YRT Cost                                                                                             
// Column:GAAP_CAPZD_REINS_YRT_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_capzd_reins_yrt_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(172,"gaap_capzd_reins_yrt_cost",t);
}



//^^^

#line 1 "gaap_capzd_reins_yrt_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_capzd_reins_yrt_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_cash_flow_int
// GAAP Cash Flow Interest                                                                                             
// Column:GAAP_CASH_FLOW_INT
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(173,"gaap_cash_flow_int",t);
}



//^^^

#line 1 "gaap_cash_flow_int.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_cash_flow_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_chg_inc
// GAAP Charges Income                                                                                             
// Column:GAAP_CHG_INC
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_chg_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(174,"gaap_chg_inc",t);
}



//^^^

#line 1 "gaap_chg_inc.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_chg_inc", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_claim_res
// GAAP Claim Reserve                                                                                             
// Column:GAAP_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(175,"gaap_claim_res",t);
}



//^^^

#line 1 "gaap_claim_res.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_claim_res_incr
// GAAP Claim Reserve Increase                                                                                             
// Column:GAAP_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(176,"gaap_claim_res_incr",t);
}



//^^^

#line 1 "gaap_claim_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_claim_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_comm_excess_bom
// GAAP Commission Excess BOM                                                                                             
// Column:GAAP_COMM_EXCESS_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_comm_excess_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(177,"gaap_comm_excess_bom",t);
}



//^^^

#line 1 "gaap_comm_excess_bom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_comm_excess_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_comm_excess_eom
// GAAP Commission Excess EOM                                                                                             
// Column:GAAP_COMM_EXCESS_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_comm_excess_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(178,"gaap_comm_excess_eom",t);
}



//^^^

#line 1 "gaap_comm_excess_eom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_comm_excess_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_comm_trail_bom
// GAAP Commission Trail BOM                                                                                             
// Column:GAAP_COMM_TRAIL_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_comm_trail_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(179,"gaap_comm_trail_bom",t);
}



//^^^

#line 1 "gaap_comm_trail_bom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_comm_trail_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_comm_trail_eom
// GAAP Commission Trail EOM                                                                                             
// Column:GAAP_COMM_TRAIL_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_comm_trail_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(180,"gaap_comm_trail_eom",t);
}



//^^^

#line 1 "gaap_comm_trail_eom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_comm_trail_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_conversion_cost
// GAAP Conersion Cost                                                                                             
// Column:GAAP_CONVERSION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_conversion_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(181,"gaap_conversion_cost",t);
}



//^^^

#line 1 "gaap_conversion_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_conversion_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_credited_int
// GAAP Credited Interest                                                                                             
// Column:GAAP_CREDITED_INT
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(182,"gaap_credited_int",t);
}



//^^^

#line 1 "gaap_credited_int.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_credited_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_dac
// GAAP DAC                                                                                             
// Column:GAAP_DAC
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_dac(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(183,"gaap_dac",t);
}



//^^^

#line 1 "gaap_dac.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_dac", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_dac_incr
// GAAP DAC Increase                                                                                             
// Column:GAAP_DAC_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_dac_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(184,"gaap_dac_incr",t);
}



//^^^

#line 1 "gaap_dac_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_dac_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_deferred_maint_exp
// GAAP Deferred Maintenance Expenses                                                                                             
// Column:GAAP_DEFERRED_MAINT_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_deferred_maint_exp(int t) {
//^^^



//^^^

#line 1 "gaap_deferred_maint_exp.COMP_COMP.for"
if (!gaap_flag ||  t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_deferred_maint_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_deferred_prof_liab
// GAAP Deferred Profit Liability                                                                                             
// Column:GAAP_DEFERRED_PROF_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_deferred_prof_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(186,"gaap_deferred_prof_liab",t);
}



//^^^

#line 1 "gaap_deferred_prof_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_deferred_prof_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_deferred_prof_liab_incr
// GAAP Deferred Profit Liability Increase                                                                                             
// Column:GAAP_DEFERRED_PROF_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_deferred_prof_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(187,"gaap_deferred_prof_liab_incr",t);
}



//^^^

#line 1 "gaap_deferred_prof_liab_incr.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_deferred_prof_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_deferred_tax_liab
// GAAP Deferred Tax Liability                                                                                             
// Column:GAAP_DEFERRED_TAX_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_deferred_tax_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(188,"gaap_deferred_tax_liab",t);
}



//^^^

#line 1 "gaap_deferred_tax_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return tax_rate
       * ((tax_res(t)
	        - reins_tax_res(t))
          - (tax_deferred_net_prem(t)
             - reins_tax_deferred_net_prem(t))
          + (tax_div_liab(t)
             - reins_tax_div_liab(t))
          - tax_capzd_prem_unamortzd(t)
          + taxable_inc_addn_unamortzd // Input variable is future amount at each date to be amortized into taxable income
          - (gaap_liab_net(t)
             - reins_gaap_liab_net(t))
          + gaap_surp_unrealzd_cap_gain(t));

}


//@@ END

//@@ START - gaap_deferred_tax_liab_incr
// GAAP Deferred Tax Liability Increase                                                                                             
// Column:GAAP_DEFERRED_TAX_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_deferred_tax_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(189,"gaap_deferred_tax_liab_incr",t);
}



//^^^

#line 1 "gaap_deferred_tax_liab_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return gaap_inc_deferred_tax_liab(t)
       - gaap_inc_deferred_tax_liab(t - 1);

}


//@@ END

//@@ START - gaap_div_applied
// GAAP Dividend Applied                                                                                             
// Column:GAAP_DIV_APPLIED
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(190,"gaap_div_applied",t);
}



//^^^

#line 1 "gaap_div_applied.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_div_applied", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_div_liab
// GAAP Dividend Liability                                                                                             
// Column:GAAP_DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(191,"gaap_div_liab",t);
}



//^^^

#line 1 "gaap_div_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return sum_over_segments("gaap_div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_div_liab_incr
// GAAP Dividend Liability Increase                                                                                             
// Column:GAAP_DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(192,"gaap_div_liab_incr",t);
}



//^^^

#line 1 "gaap_div_liab_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return gaap_div_liab(t)
	   - gaap_div_liab(t - 1);

}


//@@ END

//@@ START - gaap_div_paid
// GAAP Dividend Paid                                                                                             
// Column:GAAP_DIV_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(193,"gaap_div_paid",t);
}



//^^^

#line 1 "gaap_div_paid.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_div_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_dth_claim_cost
// GAAP Death Claim Cost                                                                                             
// Column:GAAP_DTH_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_dth_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(194,"gaap_dth_claim_cost",t);
}



//^^^

#line 1 "gaap_dth_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_dth_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_endow_claim_cost
// GAAP Endowment Claim Cost                                                                                             
// Column:GAAP_ENDOW_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_endow_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(195,"gaap_endow_claim_cost",t);
}



//^^^

#line 1 "gaap_endow_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_endow_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_free_surp
// GAAP Free Surplus                                                                                             
// Column:GAAP_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(196,"gaap_free_surp",t);
}



//^^^

#line 1 "gaap_free_surp.COMP_COMP.for"
if (!gaap_flag || nb_flag || t < start_period || t > final_period)
	return NO_AVG;
	
return free_surp(t);

}


//@@ END

//@@ START - gaap_gross_prem
// GAAP Gross Premium                                                                                             
// Column:GAAP_GROSS_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_gross_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(197,"gaap_gross_prem",t);
}



//^^^

#line 1 "gaap_gross_prem.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_gross_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_hedge_cost
// GAAP Hedge Cost                                                                                             
// Column:GAAP_HEDGE_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_hedge_cost(int t) {
//^^^



//^^^

#line 1 "gaap_hedge_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_hedge_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_hedge_mkt_val
// GAAP Hedge Market Value                                                                                             
// Column:GAAP_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "gaap_hedge_mkt_val.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_hedge_mkt_val", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_hedge_mkt_val_incr
// GAAP Hedge Market Value Increase                                                                                             
// Column:GAAP_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_hedge_mkt_val_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(200,"gaap_hedge_mkt_val_incr",t);
}



//^^^

#line 1 "gaap_hedge_mkt_val_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;
  
return gaap_hedge_mkt_val(t)
       - gaap_hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - gaap_hlth_claim_cost
// GAAP Health Claim Cost                                                                                             
// Column:GAAP_HLTH_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_hlth_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(201,"gaap_hlth_claim_cost",t);
}



//^^^

#line 1 "gaap_hlth_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_hlth_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_inc_aft_tax
// GAAP Income After Tax                                                                                             
// Column:GAAP_INC_AFT_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(202,"gaap_inc_aft_tax",t);
}



//^^^

#line 1 "gaap_inc_aft_tax.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

// Force call segment gaap_inc_aft_tax
sum_over_segments("gaap_inc_aft_tax", t, SUM_OVER_ALL);

return gaap_inc_bef_tax(t)
	   - (tax_bk_prof(t) + tax_tgt_cap(t))
       - gaap_deferred_tax_liab_incr(t);

}


//@@ END

//@@ START - gaap_inc_aft_tax_qtd
// GAAP Income After Tax Calendar Quarter to Date                                                                                             
// Column:GAAP_INC_AFT_TAX_QTD
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(203,"gaap_inc_aft_tax_qtd",t);
}



//^^^

#line 1 "gaap_inc_aft_tax_qtd.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;
	
if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_aft_tax_qtd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) % 3 == 1)
	return gaap_inc_aft_tax(t);

return gaap_inc_aft_tax_qtd(t - 1)
       + gaap_inc_aft_tax(t);

}


//@@ END

//@@ START - gaap_inc_aft_tax_ytd
// GAAP Income After Tax Calendar Year to Date                                                                                             
// Column:GAAP_INC_AFT_TAX_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(204,"gaap_inc_aft_tax_ytd",t);
}



//^^^

#line 1 "gaap_inc_aft_tax_ytd.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_aft_tax_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return gaap_inc_aft_tax(t);

return gaap_inc_aft_tax_ytd(t - 1)
       + gaap_inc_aft_tax(t);

}


//@@ END

//@@ START - gaap_inc_bef_tax
// GAAP Income Before Tax                                                                                             
// Column:GAAP_INC_BEF_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(205,"gaap_inc_bef_tax",t);
}



//^^^

#line 1 "gaap_inc_bef_tax.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

double gaap_inc_bef_tax = 0.0;

//force calls for reporting
gaap_capzd_acq_exp(t);
gaap_capzd_comm_bom(t);
gaap_capzd_comm_eom(t);
gaap_capzd_prem_bonus(t);
gaap_reins_yrt_cost(t);

gaap_inc_bef_tax
= gaap_gross_prem(t)
  + gaap_div_applied(t)
  + gaap_loads_deducted(t)
  - gaap_loads_deferred(t)
  + gaap_chg_inc(t)
  + gaap_surr_inc(t)
  + gaap_unearn_rev_released(t)
  + gaap_cash_flow_int(t)
  + gaap_inv_inc_res(t)
  + gaap_cap_gain_res(t)
  + gaap_inv_inc_cap(t)
  + gaap_cap_gain_cap(t)
  - gaap_prem_bonus(t)
  - gaap_credited_int(t)
  - gaap_dth_claim_cost(t)
  - gaap_ann_claim_cost(t)
  - gaap_hlth_claim_cost(t)
  - gaap_surr_claim_cost(t)
  - gaap_maturity_claim_cost(t)
  - gaap_endow_claim_cost(t)
  - gaap_inc_ben_claim_cost(t)
  - gaap_accum_ben_claim_cost(t)
  - gaap_withdrl_ben_claim_cost(t)
  - gaap_div_paid(t)
  - gaap_terminal_div(t)
  - gaap_ben_res_incr(t)
  - gaap_maint_exp_res_incr(t)
  - gaap_deferred_prof_liab_incr(t)
  - gaap_claim_res_incr(t)
  - gaap_prem_waiver_res_incr(t)
  - gaap_sfas133_liab_incr(t)
  - gaap_sop031_addl_liab_incr(t)
  - gaap_div_liab_incr(t)
  - gaap_acq_exp(t)
  - gaap_comm_excess_bom(t)
  - gaap_comm_excess_eom(t)
  - gaap_comm_trail_bom(t)
  - gaap_comm_trail_eom(t)
  + gaap_deferred_maint_exp(t)
  - gaap_maint_exp_bom(t)
  - gaap_maint_exp_eom(t)
  - gaap_prem_tax(t)
  - gaap_loc_cost(t)
  + gaap_dac_incr(t)
  - gaap_conversion_cost(t)
  - gaap_reins_yrt_cost(t) // Cost for the YRT treaties
  - reins_gaap_cost(t)
  - gaap_hedge_cost(t);

return gaap_inc_bef_tax;

}


//@@ END

//@@ START - gaap_inc_bef_tax_qtd
// GAAP Income Before Tax Calendar Quarter to Date                                                                                             
// Column:GAAP_INC_BEF_TAX_QTD
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(206,"gaap_inc_bef_tax_qtd",t);
}



//^^^

#line 1 "gaap_inc_bef_tax_qtd.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_bef_tax_qtd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) % 3 == 1)
	return gaap_inc_bef_tax(t);

return gaap_inc_bef_tax_qtd(t - 1)
       + gaap_inc_bef_tax(t);

}


//@@ END

//@@ START - gaap_inc_bef_tax_ytd
// GAAP Income Before Tax Calendar Year to Date                                                                                             
// Column:GAAP_INC_BEF_TAX_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(207,"gaap_inc_bef_tax_ytd",t);
}



//^^^

#line 1 "gaap_inc_bef_tax_ytd.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_bef_tax_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return gaap_inc_bef_tax(t);

return gaap_inc_bef_tax_ytd(t - 1)
       + gaap_inc_bef_tax(t);

}


//@@ END

//@@ START - gaap_inc_ben_claim_cost
// GAAP Income Benefit Claim Cost                                                                                             
// Column:GAAP_INC_BEN_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_ben_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(208,"gaap_inc_ben_claim_cost",t);
}



//^^^

#line 1 "gaap_inc_ben_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_inc_ben_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_inc_deferred_tax_liab
// GAAP Income Deferred Tax Liability                                                                                             
// Column:GAAP_INC_DEFERRED_TAX_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_deferred_tax_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(209,"gaap_inc_deferred_tax_liab",t);
}



//^^^

#line 1 "gaap_inc_deferred_tax_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return tax_rate
       * ((tax_res(t)
	        - reins_tax_res(t))
          - (tax_deferred_net_prem(t) 
             - reins_tax_deferred_net_prem(t))
          + (tax_div_liab(t)
             - reins_tax_div_liab(t))
          - tax_capzd_prem_unamortzd(t)
          + taxable_inc_addn_unamortzd // Input variable is future amount at each date to be amortized into taxable income
          - (gaap_liab_net(t)
             - reins_gaap_liab_net(t)) 
          +  gaap_inc_unrealzd_cap_gain(t));

}


//@@ END

//@@ START - gaap_inc_inv_asset
// GAAP Income Invested Assets                                                                                             
// Column:GAAP_INC_INV_ASSET
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_inv_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(210,"gaap_inc_inv_asset",t);
}



//^^^

#line 1 "gaap_inc_inv_asset.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_inc_inv_asset", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inc_unrealzd_cap_gain
// GAAP Income Unrealized Capital Gain                                                                                             
// Column:GAAP_INC_UNREALZD_CAP_GAIN
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(211,"gaap_inc_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_inc_unrealzd_cap_gain", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inc_unrealzd_cap_gain_incr
// GAAP Income Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_INC_UNREALZD_CAP_GAIN_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inc_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(212,"gaap_inc_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain_incr.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_inc_unrealzd_cap_gain_incr", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_asset
// GAAP Invested Assets                                                                                             
// Column:GAAP_INV_ASSET
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(213,"gaap_inv_asset",t);
}



//^^^

#line 1 "gaap_inv_asset.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
// force call gaap_inv_asset from segments
sum_over_segments("gaap_inv_asset", t, SUM_OVER_ALL);

if (alm_flag)
	return gaap_inv_asset_held(t)
	       + gaap_inv_asset_available(t)
	       + gaap_inv_asset_trading(t)
	       + gaap_inv_asset_not_assigned(t)
		   + accr_int(t) 
		   + cash(t)
		   + borrowing(t)
		   + interim_cash(t);

return inv_asset(t);

}


//@@ END

//@@ START - gaap_inv_asset_available
// GAAP Invested Assets - Available for Sale                                                                                             
// Column:GAAP_INV_ASSET_AVAILABLE
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_asset_available(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(214,"gaap_inv_asset_available",t);
}



//^^^

#line 1 "gaap_inv_asset_available.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_inv_asset_available", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_asset_held
// GAAP Invested Assets - Held to Maturity                                                                                             
// Column:GAAP_INV_ASSET_HELD
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_asset_held(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(215,"gaap_inv_asset_held",t);
}



//^^^

#line 1 "gaap_inv_asset_held.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_inv_asset_held", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_asset_not_assigned
// GAAP Invested Assets - Not Assigned                                                                                             
// Column:GAAP_INV_ASSET_NOT_ASSIGNED
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_asset_not_assigned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(216,"gaap_inv_asset_not_assigned",t);
}



//^^^

#line 1 "gaap_inv_asset_not_assigned.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_inv_asset_not_assigned", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_asset_trading
// GAAP Invested Assets - Trading                                                                                             
// Column:GAAP_INV_ASSET_TRADING
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_asset_trading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(217,"gaap_inv_asset_trading",t);
}



//^^^

#line 1 "gaap_inv_asset_trading.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return sum_over_segments("gaap_inv_asset_trading", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_inc_cap
// GAAP Investment Income on Capital                                                                                             
// Column:GAAP_INV_INC_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_inc_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(218,"gaap_inv_inc_cap",t);
}



//^^^

#line 1 "gaap_inv_inc_cap.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_inv_inc_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_inv_inc_res
// GAAP Investment Income on Reserves                                                                                             
// Column:GAAP_INV_INC_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(219,"gaap_inv_inc_res",t);
}



//^^^

#line 1 "gaap_inv_inc_res.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_inv_inc_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_liab_net
// GAAP Liability Net of DAC                                                                                             
// Column:GAAP_LIAB_NET
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_liab_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(220,"gaap_liab_net",t);
}



//^^^

#line 1 "gaap_liab_net.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call gaap_inv_asset for reporting
gaap_inv_asset(t);

// force call gaap_liab_net from business segments
sum_over_segments("gaap_liab_net", t, BUSINESS_SEGMENTS);

return gaap_ben_res(t)
       + gaap_maint_exp_res(t)
	   + gaap_deferred_prof_liab(t)
       + gaap_claim_res(t)
	   + gaap_prem_waiver_res(t)
	   + gaap_unearn_rev_liab(t)
	   + gaap_sfas133_liab(t)
	   + gaap_sop031_addl_liab(t)
	   + gaap_div_liab(t)
	   - gaap_dac(t);

}


//@@ END

//@@ START - gaap_liab_net_net
// GAAP Liability Net of DAC Net                                                                                             
// Column:GAAP_LIAB_NET_NET
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_liab_net_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(221,"gaap_liab_net_net",t);
}



//^^^

#line 1 "gaap_liab_net_net.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call segment value
sum_over_segments("gaap_liab_net_net", t, BUSINESS_SEGMENTS);

return gaap_liab_net(t) - reins_gaap_liab_net(t);

}


//@@ END

//@@ START - gaap_loads_deducted
// GAAP Loads Deducted                                                                                             
// Column:GAAP_LOADS_DEDUCTED
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_loads_deducted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(222,"gaap_loads_deducted",t);
}



//^^^

#line 1 "gaap_loads_deducted.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_loads_deducted", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_loads_deferred
// GAAP Loads Deferred                                                                                             
// Column:GAAP_LOADS_DEFERRED
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_loads_deferred(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(223,"gaap_loads_deferred",t);
}



//^^^

#line 1 "gaap_loads_deferred.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_loads_deferred", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_loc_cost
// GAAP Letter of Credit Cost                                                                                             
// Column:GAAP_LOC_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_loc_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(224,"gaap_loc_cost",t);
}



//^^^

#line 1 "gaap_loc_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("gaap_loc_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_maint_exp_bom
// GAAP Maintenance Expenses BOM                                                                                             
// Column:GAAP_MAINT_EXP_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(225,"gaap_maint_exp_bom",t);
}



//^^^

#line 1 "gaap_maint_exp_bom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_maint_exp_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_maint_exp_eom
// GAAP Maintenance Expenses EOM                                                                                             
// Column:GAAP_MAINT_EXP_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(226,"gaap_maint_exp_eom",t);
}



//^^^

#line 1 "gaap_maint_exp_eom.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_maint_exp_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_maint_exp_res
// GAAP Maintenance Expense Reserve                                                                                             
// Column:GAAP_MAINT_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_maint_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(227,"gaap_maint_exp_res",t);
}



//^^^

#line 1 "gaap_maint_exp_res.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_maint_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_maint_exp_res_incr
// GAAP Maintenance Expense Reserve Increase                                                                                             
// Column:GAAP_MAINT_EXP_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_maint_exp_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(228,"gaap_maint_exp_res_incr",t);
}



//^^^

#line 1 "gaap_maint_exp_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_maint_exp_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_maturity_claim_cost
// GAAP Maturity Claim Cost                                                                                             
// Column:GAAP_MATURITY_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_maturity_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(229,"gaap_maturity_claim_cost",t);
}



//^^^

#line 1 "gaap_maturity_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_maturity_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_prem_bonus
// GAAP Premium Bonus                                                                                             
// Column:GAAP_PREM_BONUS
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(230,"gaap_prem_bonus",t);
}



//^^^

#line 1 "gaap_prem_bonus.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_prem_bonus", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_prem_tax
// GAAP Premium Taxes                                                                                             
// Column:GAAP_PREM_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(231,"gaap_prem_tax",t);
}



//^^^

#line 1 "gaap_prem_tax.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_prem_tax", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_prem_waiver_res
// GAAP Premium Waiver Reserve                                                                                             
// Column:GAAP_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prem_waiver_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(232,"gaap_prem_waiver_res",t);
}



//^^^

#line 1 "gaap_prem_waiver_res.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_prem_waiver_res_incr
// GAAP Premium Waiver Reserve Increase                                                                                             
// Column:GAAP_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(233,"gaap_prem_waiver_res_incr",t);
}



//^^^

#line 1 "gaap_prem_waiver_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_prem_waiver_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_prof_aft_tax_for_pv
// GAAP Profit After Tax for Present Values                                                                                             
// Column:GAAP_PROF_AFT_TAX_FOR_PV
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prof_aft_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(234,"gaap_prof_aft_tax_for_pv",t);
}



//^^^

#line 1 "gaap_prof_aft_tax_for_pv.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (company->prof_distribn_mode == MONTHLY)
	return gaap_inc_aft_tax(t);
	
if (company->prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return gaap_inc_aft_tax_qtd(t);
	
if (company->prof_distribn_mode == ANNUAL
	&& (cal_mth(t) == 12
		|| t == final_period))
	return gaap_inc_aft_tax_ytd(t);				

return 0.0;

}


//@@ END

//@@ START - gaap_prof_bef_tax_for_pv
// GAAP Profit Before Tax for Present Values                                                                                             
// Column:GAAP_PROF_BEF_TAX_FOR_PV
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_prof_bef_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(235,"gaap_prof_bef_tax_for_pv",t);
}



//^^^

#line 1 "gaap_prof_bef_tax_for_pv.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (company->prof_distribn_mode == MONTHLY)
	return gaap_inc_bef_tax(t);
	
if (company->prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return gaap_inc_bef_tax_qtd(t);
	
if (company->prof_distribn_mode == ANNUAL
	&& (cal_mth(t) == 12
		|| t == final_period))
	return gaap_inc_bef_tax_ytd(t);				

return 0.0;

}


//@@ END

//@@ START - gaap_reins_yrt_cost
// GAAP Reinsurance YRT Cost                                                                                             
// Column:GAAP_REINS_YRT_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_reins_yrt_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(236,"gaap_reins_yrt_cost",t);
}



//^^^

#line 1 "gaap_reins_yrt_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_reins_yrt_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_req_cap
// GAAP Required Capital                                                                                             
// Column:GAAP_REQ_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_req_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(237,"gaap_req_cap",t);
}



//^^^

#line 1 "gaap_req_cap.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

// force call to segments
sum_over_segments("gaap_req_cap", t, SUM_OVER_ALL);

if (t == start_period)
	{
	return gaap_inv_asset(t)
	       + gaap_hedge_mkt_val(t)
	       + pol_loan(t)
           - (gaap_liab_net(t)
              - reins_gaap_liab_net(t))
           - gaap_deferred_tax_liab(t) 
           - gaap_free_surp(t);
	}

return gaap_req_cap(t - 1)
	   + gaap_surp_incr(t);

}


//@@ END

//@@ START - gaap_sfas133_liab
// GAAP SFAS 133 Liability                                                                                             
// Column:GAAP_SFAS133_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_sfas133_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(238,"gaap_sfas133_liab",t);
}



//^^^

#line 1 "gaap_sfas133_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_sfas133_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_sfas133_liab_incr
// GAAP SFAS 133 Liability Increase                                                                                             
// Column:GAAP_SFAS133_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_sfas133_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(239,"gaap_sfas133_liab_incr",t);
}



//^^^

#line 1 "gaap_sfas133_liab_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_sfas133_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_sop031_addl_liab
// GAAP SOP 03-1 Additional Liability                                                                                             
// Column:GAAP_SOP031_ADDL_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_sop031_addl_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(240,"gaap_sop031_addl_liab",t);
}



//^^^

#line 1 "gaap_sop031_addl_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_sop031_addl_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_sop031_addl_liab_incr
// GAAP SOP 03-1 Additional Liability Increase                                                                                             
// Column:GAAP_SOP031_ADDL_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_sop031_addl_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(241,"gaap_sop031_addl_liab_incr",t);
}



//^^^

#line 1 "gaap_sop031_addl_liab_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_sop031_addl_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_surp_incr
// GAAP Surplus Increase                                                                                             
// Column:GAAP_SURP_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_surp_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(242,"gaap_surp_incr",t);
}



//^^^

#line 1 "gaap_surp_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

// Force call to segments
sum_over_segments("gaap_surp_incr", t, SUM_OVER_ALL);

return (gaap_inv_asset(t)
        + gaap_hedge_mkt_val(t)
        + pol_loan(t)
        - (gaap_liab_net(t)
           - reins_gaap_liab_net(t))
        - gaap_deferred_tax_liab(t) 
        - gaap_free_surp(t))
        - gaap_req_cap(t - 1);

}


//@@ END

//@@ START - gaap_surp_unrealzd_cap_gain
// GAAP Surplus Unrealized Capital Gain                                                                                             
// Column:GAAP_SURP_UNREALZD_CAP_GAIN
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_surp_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(243,"gaap_surp_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_surp_unrealzd_cap_gain.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_surp_unrealzd_cap_gain", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_surp_unrealzd_cap_gain_incr
// GAAP Surplus Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_SURP_UNREALZD_CAP_GAIN_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_surp_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(244,"gaap_surp_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_surp_unrealzd_cap_gain_incr.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return gaap_surp_unrealzd_cap_gain(t)
	   - gaap_surp_unrealzd_cap_gain(t - 1);

}


//@@ END

//@@ START - gaap_surr_claim_cost
// GAAP Surrender Claim Cost                                                                                             
// Column:GAAP_SURR_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_surr_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(245,"gaap_surr_claim_cost",t);
}



//^^^

#line 1 "gaap_surr_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_surr_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_surr_inc
// GAAP Surrender Income                                                                                             
// Column:GAAP_SURR_INC
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_surr_inc(int t) {
//^^^



//^^^

#line 1 "gaap_surr_inc.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_surr_inc", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_terminal_div
// GAAP Terminal Dividends                                                                                             
// Column:GAAP_TERMINAL_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_terminal_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(247,"gaap_terminal_div",t);
}



//^^^

#line 1 "gaap_terminal_div.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_terminal_div", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_unearn_rev_liab
// GAAP Unearned Revenue Liability                                                                                             
// Column:GAAP_UNEARN_REV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_unearn_rev_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(248,"gaap_unearn_rev_liab",t);
}



//^^^

#line 1 "gaap_unearn_rev_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gaap_unearn_rev_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_unearn_rev_released
// GAAP Unearned Revenue Released                                                                                             
// Column:GAAP_UNEARN_REV_RELEASED
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_unearn_rev_released(int t) {
//^^^



//^^^

#line 1 "gaap_unearn_rev_released.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_unearn_rev_released", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gaap_unrealzd_cap_gain_incr
// GAAP Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_UNREALZD_CAP_GAIN_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(250,"gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_unrealzd_cap_gain_incr.COMP_COMP.for"
if (!gaap_flag || !alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_unrealzd_cap_gain_incr", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - gaap_withdrl_ben_claim_cost
// GAAP Withdrawal Benefit Claim Cost                                                                                             
// Column:GAAP_WITHDRL_BEN_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gaap_withdrl_ben_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(251,"gaap_withdrl_ben_claim_cost",t);
}



//^^^

#line 1 "gaap_withdrl_ben_claim_cost.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gaap_withdrl_ben_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_inv_amt
// Gamma Hedge Investment Amount                                                                                             
// Column:GAMMA_HEDGE_INV_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_inv_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_inv_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_mkt_val
// Gamma Hedge Market Value of Assets                                                                                             
// Column:GAMMA_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_mkt_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_mkt_val_incr
// Gamma Hedge Market Value of Assets Increase                                                                                             
// Column:GAMMA_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_mkt_val_incr.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_mkt_val_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_pmt
// Gamma Hedge Derivative Payment                                                                                             
// Column:GAMMA_HEDGE_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_prof
// Gamma Hedge Profit                                                                                             
// Column:GAMMA_HEDGE_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_prof(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_sale_amt
// Gamma Hedge Sale Amount                                                                                             
// Column:GAMMA_HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_sale_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gamma_hedge_transaction_cost
// Gamma Hedge Transaction Cost                                                                                             
// Column:GAMMA_HEDGE_TRANSACTION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_gamma_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "gamma_hedge_transaction_cost.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("gamma_hedge_transaction_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gmwb_chg
// GMWB Rider charge                                                                                             
// Column:GMWB_CHG
//========================================================
double COMP_COMP_UDF::comp_comp_gmwb_chg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(259,"gmwb_chg",t);
}



//^^^

#line 1 "gmwb_chg.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gmwb_chg", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gmwb_inf
// Annuity GMWB Base                                                                                             
// Column:GMWB_INF
//========================================================
double COMP_COMP_UDF::comp_comp_gmwb_inf(int t) {
//^^^



//^^^

#line 1 "gmwb_inf.COMP_COMP.for"
// 20221129 JYL: new column added for the New Business Subordination test
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gmwb_inf", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - gross_prem_annualzd
// Gross Premium Annualized                                                                                             
// Column:GROSS_PREM_ANNUALZD
//========================================================
double COMP_COMP_UDF::comp_comp_gross_prem_annualzd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(261,"gross_prem_annualzd",t);
}



//^^^

#line 1 "gross_prem_annualzd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("gross_prem_annualzd", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flow                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_cash_flow", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_cost
// Hedge Cost                                                                                             
// Column:HEDGE_COST
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_cost(int t) {
//^^^



//^^^

#line 1 "hedge_cost.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return - (hedge_cash_flow(t)
          + hedge_mkt_val_incr(t));

}


//@@ END

//@@ START - hedge_cost_bef_sale
// Hedge Cost Before Sale                                                                                             
// Column:HEDGE_COST_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_cost_bef_sale(int t) {
//^^^



//^^^

#line 1 "hedge_cost_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return - (hedge_cash_flow(t)
          + hedge_mkt_val_incr(t));

}


//@@ END

//@@ START - hedge_cost_charge
// Hedge Cost Charge                                                                                             
// Column:HEDGE_COST_CHARGE
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_cost_charge(int t) {
//^^^



//^^^

#line 1 "hedge_cost_charge.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_cost_charge", t, BUSINESS_SEGMENTS);


}


//@@ END

//@@ START - hedge_exp
// Hedge Expenses                                                                                             
// Column:HEDGE_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_exp(int t) {
//^^^



//^^^

#line 1 "hedge_exp.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_exp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_int_pmt
// Hedge Interest Payment                                                                                             
// Column:HEDGE_INT_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_int_pmt(int t) {
//^^^



//^^^

#line 1 "hedge_int_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_int_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - hedge_inv_amt_bom
// Hedge Investment Amount Beginning of Month                                                                                             
// Column:HEDGE_INV_AMT_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_inv_amt_bom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_bom.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_inv_amt_bom", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_inv_amt_eom
// Hedge Investment Amount End of Month                                                                                             
// Column:HEDGE_INV_AMT_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_inv_amt_eom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_eom.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_inv_amt_eom", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_liab_claims
// Hedged Liability GMXB Claims                                                                                             
// Column:HEDGE_LIAB_CLAIMS
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_liab_claims(int t) {
//^^^



//^^^

#line 1 "hedge_liab_claims.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_liab_claims", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - hedge_mkt_val
// Hedge Market Value                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
return sum_over_segments("hedge_mkt_val", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_mkt_val_incr
// Hedge Market Value Increase                                                                                             
// Column:HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_mkt_val_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(272,"hedge_mkt_val_incr",t);
}



//^^^

#line 1 "hedge_mkt_val_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
  
return hedge_mkt_val(t)
       - hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - hedge_opt_pmt
// Hedge Option Payment                                                                                             
// Column:HEDGE_OPT_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_opt_pmt(int t) {
//^^^



//^^^

#line 1 "hedge_opt_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_opt_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - hedge_rila_trading_cost_aig
// RILA trading cost                                                                                             
// Column:HEDGE_RILA_TRADING_COST_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_rila_trading_cost_aig(int t) {
//^^^



//^^^

#line 1 "hedge_rila_trading_cost_aig.COMP_COMP.for"
//20240529 MQ new column
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_rila_trading_cost_aig", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - hedge_sale_amt
// Hedge Sale Amount                                                                                             
// Column:HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("hedge_sale_amt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr
// IMR                                                                                             
// Column:IMR
//========================================================
double COMP_COMP_UDF::comp_comp_imr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(276,"imr",t);
}



//^^^

#line 1 "imr.COMP_COMP.for"
if (!imr_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("imr", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_bef_sale
// IMR Before Sales                                                                                             
// Column:IMR_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_imr_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(277,"imr_bef_sale",t);
}



//^^^

#line 1 "imr_bef_sale.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("imr_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_impact_free_surp
// IMR Impact on Free Surplus                                                                                             
// Column:IMR_IMPACT_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(278,"imr_impact_free_surp",t);
}



//^^^

#line 1 "imr_impact_free_surp.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("imr_impact_free_surp", t, CORPORATE_SEGMENT);

return sum_over_segments("imr_impact_free_surp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_impact_free_surp_bef_sale
// IMR Impact on Free Surplus Before Sales                                                                                             
// Column:IMR_IMPACT_FREE_SURP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_free_surp_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(279,"imr_impact_free_surp_bef_sale",t);
}



//^^^

#line 1 "imr_impact_free_surp_bef_sale.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("imr_impact_free_surp_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("imr_impact_free_surp_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_impact_res
// IMR Impact on Reserves                                                                                             
// Column:IMR_IMPACT_RES
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(280,"imr_impact_res",t);
}



//^^^

#line 1 "imr_impact_res.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("imr_impact_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - imr_impact_res_bef_sale
// IMR Impact on Reserve Before Sales                                                                                             
// Column:IMR_IMPACT_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(281,"imr_impact_res_bef_sale",t);
}



//^^^

#line 1 "imr_impact_res_bef_sale.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("imr_impact_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - imr_impact_tgt_cap
// IMR Impact on Target Capital                                                                                             
// Column:IMR_IMPACT_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(282,"imr_impact_tgt_cap",t);
}



//^^^

#line 1 "imr_impact_tgt_cap.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("imr_impact_tgt_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_impact_tgt_cap_bef_sale
// IMR Impact on Target Capital Before Sales                                                                                             
// Column:IMR_IMPACT_TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_imr_impact_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(283,"imr_impact_tgt_cap_bef_sale",t);
}



//^^^

#line 1 "imr_impact_tgt_cap_bef_sale.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("imr_impact_tgt_cap_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - imr_incr
// IMR Increase                                                                                             
// Column:IMR_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_imr_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(284,"imr_incr",t);
}



//^^^

#line 1 "imr_incr.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return imr(t)
       - imr(t - 1);

}


//@@ END

//@@ START - imr_incr_bef_sale
// IMR Increase Before Sales                                                                                             
// Column:IMR_INCR_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_imr_incr_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(285,"imr_incr_bef_sale",t);
}



//^^^

#line 1 "imr_incr_bef_sale.COMP_COMP.for"
if (!imr_flag || t <= start_period || t > final_period)
	return NO_AVG;

return imr_bef_sale(t)
       - imr(t - 1);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double COMP_COMP_UDF::comp_comp_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.COMP_COMP.for"
// force call to calculation prod_type_indicator
double force_scalar_calc = prod_type_indicator;

if (isMainModel)
	{
	if (!hedge_valn_flag)
		{
		if (time_step_flag && (is_first_proj_task_loop || num_of_proj_task_loops == 0))
			{
	 		if (valn_flag)
				log_screen << "Beginning Valuation For Outer Loop = " << proj_set_loop_num << " :: Period = " << valn_period << MSG_USER;
			else
				log_screen << "Beginning Projection For Outer Loop = " << proj_set_loop_num << " :: Period = " << valn_period << MSG_USER;
			}		

		if (num_of_proj_task_loops)
			log_screen << ".. Initializing Model for Projection Task Loop = " << proj_task_loop_num << MSG_USER;
		else
			log_screen << ".. Initializing Model" << MSG_USER;	

		log_screen << "... Initializing Rates" << MSG_USER;
		}

	comp_rates_map.clear();
	rates->initialize(0);

	// process asset initialize first to setup ADCO submodel	
	if (alm_flag)
		sm_asset->initialize(0);

	// process liab initialize first for IMP processing
	#if defined(__LIAB_LIAB_H_)
	sm_liab->initialize(0);
	#endif

	if (!hedge_valn_flag)
		log_screen << "... Initializing Segments" << MSG_USER;

	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		if (tcm_flag && segment == sm_seg.size() - 1)
			sm_seg[segment]->seg_id = "Corp";
		else if ((tcm_flag && vm21_reinv_rate_flag && segment == sm_seg.size() - 2)
				 ||(!tcm_flag && vm21_reinv_rate_flag && segment == sm_seg.size() - 1))
			sm_seg[segment]->seg_id = "VM21ReinvRate";
		else
			sm_seg[segment]->seg_id = xstring(segments[segment]);	

		sm_seg[segment]->initialize(0);
		}

    if (!proxy_bond_gen_flag)
		{
		if (time_step_flag && valn_period > 0 && !hedge_valn_flag)
			read_state_of_world_financial();
		}
	}

if (!hedge_valn_flag)
	log_screen << "... Processing Target Column" << MSG_USER;

// Add model class to output file list. MCHING 1-26-2022
// Bugfix to vGrid race condition. MCHING 2-15-2022
if (is_first_modelpoint && overall_is_first_proj_task_loop)
{
	fia_automation->append_to_file_manifest_aig(output_location());
}
		
return 0.0;

}


//@@ END

//@@ START - int_pmt
// Interest Payment                                                                                             
// Column:INT_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_int_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(287,"int_pmt",t);
}



//^^^

#line 1 "int_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("int_pmt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - interim_cash
// Interim Cash                                                                                             
// Column:INTERIM_CASH
//========================================================
double COMP_COMP_UDF::comp_comp_interim_cash(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(288,"interim_cash",t);
}



//^^^

#line 1 "interim_cash.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("interim_cash", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - interim_cash_int
// Interim Cash Interest                                                                                             
// Column:INTERIM_CASH_INT
//========================================================
double COMP_COMP_UDF::comp_comp_interim_cash_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(289,"interim_cash_int",t);
}



//^^^

#line 1 "interim_cash_int.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("interim_cash_int", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_asset
// Invested Assets                                                                                             
// Column:INV_ASSET
//========================================================
double COMP_COMP_UDF::comp_comp_inv_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(290,"inv_asset",t);
}



//^^^

#line 1 "inv_asset.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call separate account assets
asset_sa(t);

if (alm_flag)
	{
	double invested_assets = 0;

	invested_assets = cash(t);
	invested_assets += borrowing(t);
	invested_assets += interim_cash(t);
	invested_assets += bk_val_inv(t);
	invested_assets += accr_int(t);

	// force call for reporting
	notional_amt(t);

	return invested_assets;
	}


return liab_and_surp(t)
	   - pol_loan(t)
	   - (deferred_net_prem(t)
	      - reins_deferred_net_prem(t))
	   - loc_asset(t)
	   - hedge_mkt_val(t);

}


//@@ END

//@@ START - inv_cash_flow_int_div_and_rent
// Investment Cash Flow Interest Dividend and Rent                                                                                             
// Column:INV_CASH_FLOW_INT_DIV_AND_RENT
//========================================================
double COMP_COMP_UDF::comp_comp_inv_cash_flow_int_div_and_rent(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(291,"inv_cash_flow_int_div_and_rent",t);
}



//^^^

#line 1 "inv_cash_flow_int_div_and_rent.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return int_pmt(t) 
	   - inv_exp(t)
	   + opt_inc(t);

}


//@@ END

//@@ START - inv_cash_flow_prin_pmt
// Investment Cash Flow Principal Payment                                                                                             
// Column:INV_CASH_FLOW_PRIN_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_inv_cash_flow_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(292,"inv_cash_flow_prin_pmt",t);
}



//^^^

#line 1 "inv_cash_flow_prin_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return opt_pmt(t)
	   + sched_prin_pmt(t);

}


//@@ END

//@@ START - inv_exp
// Investment Expenses                                                                                             
// Column:INV_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_inv_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(293,"inv_exp",t);
}



//^^^

#line 1 "inv_exp.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_exp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_fee_ref
// Investment Fee Refund                                                                                             
// Column:INV_FEE_REF
//========================================================
double COMP_COMP_UDF::comp_comp_inv_fee_ref(int t) {
//^^^



//^^^

#line 1 "inv_fee_ref.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_fee_ref", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - inv_inc
// Investment Income                                                                                             
// Column:INV_INC
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(295,"inv_inc",t);
}



//^^^

#line 1 "inv_inc.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
  
return inv_inc_on_invested_assets(t)
       + direct_cash_flow_int(t)
       - reins_cash_flow_int(t)
	   + pol_loan_inc(t);

}


//@@ END

//@@ START - inv_inc_bk_prof
// Investment Income For Book Profit                                                                                             
// Column:INV_INC_BK_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(296,"inv_inc_bk_prof",t);
}



//^^^

#line 1 "inv_inc_bk_prof.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	       
return direct_cash_flow_int(t)
       + pol_loan_inc(t)
       + inv_inc_res(t)
       + cap_gain_res(t)
       + inv_inc_undistrib_earnings(t)
       + cap_gain_undistrib_earnings(t)
       - imr_impact_res(t);

}


//@@ END

//@@ START - inv_inc_bk_prof_bef_sale
// Investment Income For Book Profit Before Sales                                                                                             
// Column:INV_INC_BK_PROF_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_bk_prof_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(297,"inv_inc_bk_prof_bef_sale",t);
}



//^^^

#line 1 "inv_inc_bk_prof_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	       
return direct_cash_flow_int(t)
       + pol_loan_inc(t)
       + inv_inc_res(t)
       + cap_gain_res_bef_sale(t)
       + inv_inc_undistrib_earnings(t)
       + cap_gain_undistrib_earnings_bef_sale(t)
       - imr_impact_res_bef_sale(t);

}


//@@ END

//@@ START - inv_inc_earnings_accum
// Investment Income on Accumulated Earnings                                                                                             
// Column:INV_INC_EARNINGS_ACCUM
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(298,"inv_inc_earnings_accum",t);
}



//^^^

#line 1 "inv_inc_earnings_accum.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("inv_inc_earnings_accum", t, CORPORATE_SEGMENT);

return sum_over_segments("inv_inc_earnings_accum", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_inc_free_surp
// Investment Income on Free Surplus                                                                                             
// Column:INV_INC_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(299,"inv_inc_free_surp",t);
}



//^^^

#line 1 "inv_inc_free_surp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("inv_inc_free_surp", t, CORPORATE_SEGMENT);

return sum_over_segments("inv_inc_free_surp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_inc_fund
// Investment Income on Fixed Fund Value                                                                                             
// Column:INV_INC_FUND
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_fund(int t) {
//^^^



//^^^

#line 1 "inv_inc_fund.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_inc_fund", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - inv_inc_on_invested_assets
// Investment Income on Invested Assets                                                                                             
// Column:INV_INC_ON_INVESTED_ASSETS
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_on_invested_assets(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(301,"inv_inc_on_invested_assets",t);
}



//^^^

#line 1 "inv_inc_on_invested_assets.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_inc_on_invested_assets", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_inc_res
// Investment Income on Reserves                                                                                             
// Column:INV_INC_RES
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(302,"inv_inc_res",t);
}



//^^^

#line 1 "inv_inc_res.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_inc_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - inv_inc_tgt_cap
// Investment Income on Target Capital                                                                                             
// Column:INV_INC_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(303,"inv_inc_tgt_cap",t);
}



//^^^

#line 1 "inv_inc_tgt_cap.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("inv_inc_tgt_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - inv_inc_undistrib_earnings
// Investment Income on Undistributed Earnings                                                                                             
// Column:INV_INC_UNDISTRIB_EARNINGS
//========================================================
double COMP_COMP_UDF::comp_comp_inv_inc_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(304,"inv_inc_undistrib_earnings",t);
}



//^^^

#line 1 "inv_inc_undistrib_earnings.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)  
	return sum_over_segments("inv_inc_undistrib_earnings", t, CORPORATE_SEGMENT);

return sum_over_segments("inv_inc_undistrib_earnings", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - invested_asset_sale
// Invested Asset Sales                                                                                             
// Column:INVESTED_ASSET_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_invested_asset_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(305,"invested_asset_sale",t);
}



//^^^

#line 1 "invested_asset_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

// Hedge sales are included in mkt_val_sale
return mkt_val_sale(t);
// DB 11/24/20 liability hedge sales are not included in mkt_val_sale
//       - hedge_sale_amt(t);

}


//@@ END

//@@ START - irr
// Internal Rate of Return                                                                                             
// Column:IRR
//========================================================
double COMP_COMP_UDF::comp_comp_irr(int t) {
//^^^



//^^^

#line 1 "irr.COMP_COMP.for"
if (!nb_flag || t > 1)	//20210517 STW: add Dustin's code Change
	return NO_AVG;

if (t == 1)				//20210517 STW: add Dustin's code Change
	return irr(0);

// The reporting tool calculates IRR for scenario time-step projections
if (time_step_flag)
	{
	for (int tt = 1; tt <= final_period; tt++)
		{
		bk_prof_aft_tax_irr(tt);
		
		distrib_earnings_irr(tt);
		distrib_earnings(tt);
		}
	
	return NO_AVG;
	}

// Force call so this target formula produces all IRR results
irr_wo_tgt_cap(t);
irr2_aig(t);	//20210517 STW: add Dustin's code Change

return irr_calc("With Target Capital");

}


//@@ END

//@@ START - irr2_aig
// Internal Rate of Return                                                                                             
// Column:IRR2_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_irr2_aig(int t) {
//^^^



//^^^

#line 1 "irr2_aig.COMP_COMP.for"
//20210517 STW: new column: add Dustin's code Change
if (!nb_flag || t > 1)
	return NO_AVG;

if (t == 1)
	return irr2_aig(0);

// The reporting tool calculates IRR for scenario time-step projections
if (time_step_flag)
	{
	for (int tt = 1; tt <= final_period; tt++)
		{
		bk_prof_aft_tax_irr(tt);
		
		distrib_earnings_irr(tt);
		distrib_earnings(tt);
		}
	
	return NO_AVG;
	}

return irr_calc("Standard");

}


//@@ END

//@@ START - irr_wo_tgt_cap
// IRR Without Target Capital                                                                                             
// Column:IRR_WO_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_irr_wo_tgt_cap(int t) {
//^^^



//^^^

#line 1 "irr_wo_tgt_cap.COMP_COMP.for"
if (!nb_flag || t > 1)		//20210517 STW: add Dustin's code Change
	return NO_AVG;

if (t == 1)					//20210517 STW: add Dustin's code Change
	return irr_wo_tgt_cap(0);

// The reporting tool calculates IRR for scenario time-step projections
if (time_step_flag)
	{
	for (int tt = 1; tt <= final_period; tt++)
		{
		bk_prof_aft_tax_irr(tt);
		
		distrib_earnings_irr(tt);
		distrib_earnings(tt);
		}
	
	return NO_AVG;
	}

return irr_calc("Without Target Capital");

}


//@@ END

//@@ START - lapse_count_aig
// Lapse Count Monthly                                                                                             
// Column:LAPSE_COUNT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_lapse_count_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(309,"lapse_count_aig",t);
}



//^^^

#line 1 "lapse_count_aig.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("lapse_count_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - last_period_indicator
// Last Period Indicator                                                                                             
// Column:LAST_PERIOD_INDICATOR
//========================================================
double COMP_COMP_UDF::comp_comp_last_period_indicator(int t) {
//^^^



//^^^

#line 1 "last_period_indicator.COMP_COMP.for"
if (!time_step_flag && t == last_proj_period)
	return 1;

if (time_step_flag && proj_set_sub_loop_num == (valn_periods.size() - 1)
	&& t == last_proj_period)
	return 1;

return 0;

}


//@@ END

//@@ START - liab_and_surp
// Liabilities and Surplus Net of Reinsurance                                                                                             
// Column:LIAB_AND_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_liab_and_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(311,"liab_and_surp",t);
}



//^^^

#line 1 "liab_and_surp.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call reserves
fund_val_fixed(t);
stat_res_sa(t);
stat_res_mp(t);
sum_over_segments("stat_res_net_sa", t, BUSINESS_SEGMENTS);
sum_over_segments("stat_res_net", t, BUSINESS_SEGMENTS);

return stat_unearn_prem_res(t)
       - reins_stat_unearn_prem_res(t)
       + stat_claim_res(t)
	   + stat_prem_waiver_res(t)
       - reins_stat_claim_res(t)
	   - reins_stat_prem_waiver_res(t)
       + stat_claim_exp_res(t)
	   + stat_prem_waiver_exp_res(t)
       + stat_res(t)
       - reins_stat_res(t)
	   + stat_res_sa_exp_allow(t)
       + div_liab(t)
       - reins_div_liab(t)
       + tgt_cap(t)
	   + avr(t)
       + imr(t) 
       + undistrib_earnings(t)
       + free_surp(t);

}


//@@ END

//@@ START - liab_cash_flow
// Liability Cash Flow                                                                                             
// Column:LIAB_CASH_FLOW
//========================================================
double COMP_COMP_UDF::comp_comp_liab_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(312,"liab_cash_flow",t);
}



//^^^

#line 1 "liab_cash_flow.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call liab_cash_flow from business segments
return sum_over_segments("liab_cash_flow", t, BUSINESS_SEGMENTS);

return liab_cash_flow_bom(t)
       + liab_cash_flow_eom(t);

}


//@@ END

//@@ START - liab_cash_flow_bom
// Liability Cash Flow Beginning of Month                                                                                             
// Column:LIAB_CASH_FLOW_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_liab_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(313,"liab_cash_flow_bom",t);
}



//^^^

#line 1 "liab_cash_flow_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return direct_cash_flow_bom(t)
       - reins_cash_flow_bom(t);

}


//@@ END

//@@ START - liab_cash_flow_eom
// Liability Cash Flow End of Month                                                                                             
// Column:LIAB_CASH_FLOW_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_liab_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(314,"liab_cash_flow_eom",t);
}



//^^^

#line 1 "liab_cash_flow_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return direct_cash_flow_eom(t)
       - reins_cash_flow_eom(t);

}


//@@ END

//@@ START - loc_asset
// Letter of Credit Asset                                                                                             
// Column:LOC_ASSET
//========================================================
double COMP_COMP_UDF::comp_comp_loc_asset(int t) {
//^^^



//^^^

#line 1 "loc_asset.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("loc_asset", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - loc_asset_incr
// LOC Asset Increase                                                                                             
// Column:LOC_ASSET_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_loc_asset_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(316,"loc_asset_incr",t);
}



//^^^

#line 1 "loc_asset_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return loc_asset(t)
	   - loc_asset(t - 1);

}


//@@ END

//@@ START - loc_cost
// LOC Cost                                                                                             
// Column:LOC_COST
//========================================================
double COMP_COMP_UDF::comp_comp_loc_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(317,"loc_cost",t);
}



//^^^

#line 1 "loc_cost.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("loc_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - maint_exp_bom
// Maintenance Expenses Beginning of Month                                                                                             
// Column:MAINT_EXP_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(318,"maint_exp_bom",t);
}



//^^^

#line 1 "maint_exp_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("maint_exp_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - maint_exp_eom
// Maintenance Expenses End of Month                                                                                             
// Column:MAINT_EXP_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(319,"maint_exp_eom",t);
}



//^^^

#line 1 "maint_exp_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("maint_exp_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - maturity_benefits
// Maturity Benefits                                                                                             
// Column:MATURITY_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(320,"maturity_benefits",t);
}



//^^^

#line 1 "maturity_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("maturity_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - mkt_val
// Market Value                                                                                             
// Column:MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_mkt_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(321,"mkt_val",t);
}



//^^^

#line 1 "mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

asset_yld(t);

return sum_over_segments("mkt_val", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - mkt_val_sale
// Market Value Sale                                                                                             
// Column:MKT_VAL_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_mkt_val_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

double mkt_val_sale = sum_over_segments("mkt_val_sale", t, SUM_OVER_ALL);

// force call for reporting
cost_basis_sale(t);

return mkt_val_sale;

}


//@@ END

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_notional_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(323,"notional_amt",t);
}



//^^^

#line 1 "notional_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("notional_amt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - opt_budget_amt
// Option Budget Amount                                                                                             
// Column:OPT_BUDGET_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_opt_budget_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(324,"opt_budget_amt",t);
}



//^^^

#line 1 "opt_budget_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("opt_budget_amt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - opt_inc
// Option Income                                                                                             
// Column:OPT_INC
//========================================================
double COMP_COMP_UDF::comp_comp_opt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(325,"opt_inc",t);
}



//^^^

#line 1 "opt_inc.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("opt_inc", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - opt_payoff_aig
// Option Payoff AIG                                                                                             
// Column:OPT_PAYOFF_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_opt_payoff_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(326,"opt_payoff_aig",t);
}



//^^^

#line 1 "opt_payoff_aig.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("opt_payoff_aig", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_opt_pmt(int t) {
//^^^



//^^^

#line 1 "opt_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("opt_pmt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - pol_loan
// Policy Loan                                                                                             
// Column:POL_LOAN
//========================================================
double COMP_COMP_UDF::comp_comp_pol_loan(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(328,"pol_loan",t);
}



//^^^

#line 1 "pol_loan.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("pol_loan", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - pol_loan_exp
// Policy Loan Expense                                                                                             
// Column:POL_LOAN_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_pol_loan_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(329,"pol_loan_exp",t);
}



//^^^

#line 1 "pol_loan_exp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("pol_loan_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - pol_loan_inc
// Policy Loan Income                                                                                             
// Column:POL_LOAN_INC
//========================================================
double COMP_COMP_UDF::comp_comp_pol_loan_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(330,"pol_loan_inc",t);
}



//^^^

#line 1 "pol_loan_inc.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return pol_loan_int(t)
       - pol_loan_exp(t);

}


//@@ END

//@@ START - pol_loan_int
// Policy Loan Interest                                                                                             
// Column:POL_LOAN_INT
//========================================================
double COMP_COMP_UDF::comp_comp_pol_loan_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(331,"pol_loan_int",t);
}



//^^^

#line 1 "pol_loan_int.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("pol_loan_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - pol_loan_proceeds
// Policy Loan Proceeds                                                                                             
// Column:POL_LOAN_PROCEEDS
//========================================================
double COMP_COMP_UDF::comp_comp_pol_loan_proceeds(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(332,"pol_loan_proceeds",t);
}



//^^^

#line 1 "pol_loan_proceeds.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("pol_loan_proceeds", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - pol_mth_aig
// Policy Month                                                                                             
// Column:POL_MTH_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_pol_mth_aig(int t) {
//^^^



//^^^

#line 1 "pol_mth_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
if (t < start_period)
	return NO_AVG;

return int(t + elapsed_mths_aig - 1) % 12 + 1;

}


//@@ END

//@@ START - pol_yr_aig
// Policy Year                                                                                             
// Column:POL_YR_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_pol_yr_aig(int t) {
//^^^



//^^^

#line 1 "pol_yr_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve, clone of pol_yr from the fia level, using comp variables
if (t < start_period)
	return NO_AVG;
	
cal_yr_relative(t);
cal_mth(t);

if (t == start_period) 
	{
	if (elapsed_mths_aig <= 0)
		return NO_AVG;
	else
		return xint((elapsed_mths_aig - 1) / 12.0) + 1.0;
	}
 
if (xint(pol_mth_aig(t)) == 1)
	return pol_yr_aig(t - 1) + 1.0;
	
return pol_yr_aig(t - 1);

}


//@@ END

//@@ START - policies_inf
// Policies In Force                                                                                             
// Column:POLICIES_INF
//========================================================
double COMP_COMP_UDF::comp_comp_policies_inf(int t) {
//^^^



//^^^

#line 1 "policies_inf.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("policies_inf", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - policies_issued
// Policies Issued                                                                                             
// Column:POLICIES_ISSUED
//========================================================
double COMP_COMP_UDF::comp_comp_policies_issued(int t) {
//^^^



//^^^

#line 1 "policies_issued.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("policies_issued", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - port_yld
// Portfolio Yield                                                                                             
// Column:PORT_YLD
//========================================================
double COMP_COMP_UDF::comp_comp_port_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(337,"port_yld",t);
}



//^^^

#line 1 "port_yld.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return asset_yld(t);

}


//@@ END

//@@ START - port_yld_aft_tax
// Portfolio Yield After Tax                                                                                             
// Column:PORT_YLD_AFT_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_port_yld_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(338,"port_yld_aft_tax",t);
}



//^^^

#line 1 "port_yld_aft_tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return bef_tax_yld(t) * (1.0 - tax_rate);

}


//@@ END

//@@ START - port_yld_denom
// Portfolio Yield Denominator                                                                                             
// Column:PORT_YLD_DENOM
//========================================================
double COMP_COMP_UDF::comp_comp_port_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(339,"port_yld_denom",t);
}



//^^^

#line 1 "port_yld_denom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double yield_denominator
= inv_asset(t - 1)
  + liab_cash_flow_bom(t);

if (fabs(yield_denominator) > aggregate_amount_threshold)
	return yield_denominator;

return NO_AVG;

}


//@@ END

//@@ START - port_yld_less_dflt
// Portfolio Yield Less Default                                                                                             
// Column:PORT_YLD_LESS_DFLT
//========================================================
double COMP_COMP_UDF::comp_comp_port_yld_less_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(340,"port_yld_less_dflt",t);
}



//^^^

#line 1 "port_yld_less_dflt.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!alm_flag)
	return port_yld(t);

if (port_yld_denom(t) < 0.0 
	|| fabs(asset_yld(t)) < rate_ratio_threshold)
	return NO_AVG;

if (fabs(inv_asset(t - 1))
	 > aggregate_amount_threshold
	&& port_yld_denom(t) != 0.0)
	{
	double yield_ratio;
	double calculated_yield;

	yield_ratio
	= (inv_inc_on_invested_assets(t)
	   + cash_flow_int(t)
	   - dflt_amt(t))
	  / port_yld_denom(t);

	calculated_yield
	= max(pow(1.0 + yield_ratio, 12.0) - 1.0, USLIB_MINIMUM_YIELD);

	return min(calculated_yield, USLIB_MAX_DOUBLE);

	}

if (fabs(inv_asset(t - 1))
	 > aggregate_amount_threshold
	&& port_yld_denom(t) == 0.0)
	return port_yld_less_dflt(t - 1);

return NO_AVG;

}


//@@ END

//@@ START - prem_bonus
// Premium Bonus                                                                                             
// Column:PREM_BONUS
//========================================================
double COMP_COMP_UDF::comp_comp_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(341,"prem_bonus",t);
}



//^^^

#line 1 "prem_bonus.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("prem_bonus", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - prem_issued
// Premium Issued                                                                                             
// Column:PREM_ISSUED
//========================================================
double COMP_COMP_UDF::comp_comp_prem_issued(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(342,"prem_issued",t);
}



//^^^

#line 1 "prem_issued.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("prem_issued", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - prem_paid
// Premiums Paid                                                                                             
// Column:PREM_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_prem_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(343,"prem_paid",t);
}



//^^^

#line 1 "prem_paid.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call for reporting
prem_issued(t);

return sum_over_segments("prem_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - prem_tax
// Premium Taxes                                                                                             
// Column:PREM_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(344,"prem_tax",t);
}



//^^^

#line 1 "prem_tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("prem_tax", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - prem_waiver_benefits
// Premium Waiver Benefits                                                                                             
// Column:PREM_WAIVER_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_prem_waiver_benefits(int t) {
//^^^



//^^^

#line 1 "prem_waiver_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("prem_waiver_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - proj_tgt_hedge_stmt
// Projection Target - Hedging Statement Calculations                                                                                             
// Column:PROJ_TGT_HEDGE_STMT
//========================================================
double COMP_COMP_UDF::comp_comp_proj_tgt_hedge_stmt(int t) {
//^^^



//^^^

#line 1 "proj_tgt_hedge_stmt.COMP_COMP.for"
if (!hedge_proj_stmt_flag)
	return NO_AVG;

double proj_tgt_hedge_stmt_amt = sum_over_segments("proj_tgt_hedge_stmt", t, BUSINESS_SEGMENTS);

delta_hedge_inv_amt(t);
delta_hedge_mkt_val(t);
delta_hedge_pmt(t);
delta_hedge_prof(t);
delta_hedge_sale_amt(t);
delta_hedge_transaction_cost(t);
delta_hedge_mkt_val_incr(t);

gamma_hedge_inv_amt(t);
gamma_hedge_mkt_val(t);
gamma_hedge_pmt(t);
gamma_hedge_prof(t);
gamma_hedge_sale_amt(t);
gamma_hedge_transaction_cost(t);
gamma_hedge_mkt_val_incr(t);

rho_hedge_inv_amt(t);
rho_hedge_mkt_val(t);
rho_hedge_pmt(t);
rho_hedge_prof(t);
rho_hedge_sale_amt(t);
rho_hedge_transaction_cost(t);
rho_hedge_mkt_val_incr(t);

rho_convex_hedge_inv_amt(t);
rho_convex_hedge_mkt_val(t);
rho_convex_hedge_pmt(t);
rho_convex_hedge_prof(t);
rho_convex_hedge_sale_amt(t);
rho_convex_hedge_transaction_cost(t);
rho_convex_hedge_mkt_val_incr(t);

vega_hedge_inv_amt(t);
vega_hedge_mkt_val(t);
vega_hedge_pmt(t);
vega_hedge_prof(t);
vega_hedge_sale_amt(t);
vega_hedge_transaction_cost(t);
vega_hedge_mkt_val_incr(t);

econ_res(t);
econ_res_incr(t);
econ_res_int(t);
hedge_liab_claims(t);

econ_cash(t);
econ_cash_int(t);
hedge_int_pmt(t);
hedge_cost_charge(t);
hedge_exp(t);
hedge_inv_amt_eom(t);
hedge_mkt_val(t);
hedge_opt_pmt(t);
econ_prof(t);
hedge_sale_amt(t);

econ_prof_unhedged(t);

return proj_tgt_hedge_stmt_amt;

}


//@@ END

//@@ START - proxy_bond_generation
// Proxy Bond Generation                                                                                             
// Column:PROXY_BOND_GENERATION
//========================================================
double COMP_COMP_UDF::comp_comp_proxy_bond_generation(int t) {
//^^^



//^^^

#line 1 "proxy_bond_generation.COMP_COMP.for"
if (t != 0 || !proxy_bond_gen_flag)
   return NO_AVG;

#if defined(__ASSET_ASSET_H_)
if (sm_asset->proxy_bond_defn == NOT_APPLICABLE)
	throw FatalError("Proxy Bond generation task has been requested. However, Proxy Bond " 
					 "Definition is set to Not Applicable. Please correct the Proxy "
					 "Bond Definition.");

if (!alm_flag)
	throw FatalError("Proxy Bond generation generation task requires assets, but "
					 "assets_defn project variable run parameter is set to No. "
					 "Please correct the run parameter.");
           		
// Force Call write_proxy_bond function in the asset submodel: 
sm_asset->write_proxy_bond();

return 1;
#endif
return NO_AVG;

}


//@@ END

//@@ START - rbc
// RBC                                                                                             
// Column:RBC
//========================================================
double COMP_COMP_UDF::comp_comp_rbc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(348,"rbc",t);
}



//^^^

#line 1 "rbc.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

double rbc_c1 = this->rbc_c1(t);
double rbc_c1_eqt = this->rbc_c1_eqt(t);
double rbc_c2 = this->rbc_c2(t);
double rbc_c3 = this->rbc_c3(t);
double rbc_c4 = this->rbc_c4(t);

return pow((rbc_c1 + rbc_c3) * (rbc_c1 + rbc_c3)
           + rbc_c1_eqt * rbc_c1_eqt
           + rbc_c2 * rbc_c2, 0.5)
       + rbc_c4;

}


//@@ END

//@@ START - rbc_bef_sale
// RBC Before Sales                                                                                             
// Column:RBC_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(349,"rbc_bef_sale",t);
}



//^^^

#line 1 "rbc_bef_sale.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

double rbc_c1 = this->rbc_c1_bef_sale(t);
double rbc_c1_eqt = this->rbc_c1_eqt_bef_sale(t);
double rbc_c2 = this->rbc_c2(t);
double rbc_c3 = this->rbc_c3(t);
double rbc_c4 = this->rbc_c4(t);

return pow((rbc_c1 + rbc_c3) * (rbc_c1 + rbc_c3)
           + rbc_c1_eqt * rbc_c1_eqt
           + rbc_c2 * rbc_c2, 0.5)
       + rbc_c4;

}


//@@ END

//@@ START - rbc_c1
// RBC C1                                                                                             
// Column:RBC_C1
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(350,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c1", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - rbc_c1_bef_sale
// RBC C1 Before Sales                                                                                             
// Column:RBC_C1_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c1_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(351,"rbc_c1_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_bef_sale.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c1_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - rbc_c1_eqt
// RBC C1 Equity                                                                                             
// Column:RBC_C1_EQT
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c1_eqt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(352,"rbc_c1_eqt",t);
}



//^^^

#line 1 "rbc_c1_eqt.COMP_COMP.for"
if (!tgt_cap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c1_eqt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - rbc_c1_eqt_bef_sale
// RBC C1 Equity Before Sales                                                                                             
// Column:RBC_C1_EQT_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c1_eqt_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(353,"rbc_c1_eqt_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_eqt_bef_sale.COMP_COMP.for"
if (!tgt_cap_flag || !alm_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c1_eqt_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - rbc_c2
// RBC C2                                                                                             
// Column:RBC_C2
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c2(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(354,"rbc_c2",t);
}



//^^^

#line 1 "rbc_c2.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c2", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rbc_c3
// RBC C3                                                                                             
// Column:RBC_C3
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c3(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(355,"rbc_c3",t);
}



//^^^

#line 1 "rbc_c3.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c3", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rbc_c4
// RBC C4                                                                                             
// Column:RBC_C4
//========================================================
double COMP_COMP_UDF::comp_comp_rbc_c4(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(356,"rbc_c4",t);
}



//^^^

#line 1 "rbc_c4.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("rbc_c4", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain
// Realized Capital Gains                                                                                             
// Column:REALZD_CAP_GAIN
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(357,"realzd_cap_gain",t);
}



//^^^

#line 1 "realzd_cap_gain.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return realzd_cap_gain_bef_sale(t)
	   + realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - realzd_cap_gain_bef_sale
// Realized Capital Gains Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(358,"realzd_cap_gain_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_free_surp
// Realized Capital Gains on Free Surplus                                                                                             
// Column:REALZD_CAP_GAIN_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(359,"realzd_cap_gain_free_surp",t);
}



//^^^

#line 1 "realzd_cap_gain_free_surp.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_free_surp", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_free_surp", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_free_surp_bef_sale
// Realized Capital Gains on Free Surplus Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_FREE_SURP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(360,"realzd_cap_gain_free_surp_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_free_surp_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_free_surp_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_free_surp_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_free_surp_ytd
// Realized Capital Gains on Free Surplus Calendar Year to Date                                                                                             
// Column:REALZD_CAP_GAIN_FREE_SURP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(361,"realzd_cap_gain_free_surp_ytd",t);
}



//^^^

#line 1 "realzd_cap_gain_free_surp_ytd.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	 return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_free_surp_ytd", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_free_surp_ytd", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_free_surp_ytd_bef_sale
// Realized Capital Gains on Free Surplus Calendar Year to Date Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_FREE_SURP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(362,"realzd_cap_gain_free_surp_ytd_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_free_surp_ytd_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_free_surp_ytd_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_free_surp_ytd_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_fund
// Realized Capital Gains on Fixed Fund Value                                                                                             
// Column:REALZD_CAP_GAIN_FUND
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_fund(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(363,"realzd_cap_gain_fund",t);
}



//^^^

#line 1 "realzd_cap_gain_fund.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_fund", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain_res
// Realized Capital Gains on Reserve                                                                                             
// Column:REALZD_CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(364,"realzd_cap_gain_res",t);
}



//^^^

#line 1 "realzd_cap_gain_res.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain_res_bef_sale
// Realized Capital Gains on Reserve Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(365,"realzd_cap_gain_res_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_res_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain_res_ytd
// Realized Capital Gains on Reserves Calendar Year to Date                                                                                             
// Column:REALZD_CAP_GAIN_RES_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(366,"realzd_cap_gain_res_ytd",t);
}



//^^^

#line 1 "realzd_cap_gain_res_ytd.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	 return NO_AVG;

return sum_over_segments("realzd_cap_gain_res_ytd", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain_res_ytd_bef_sale
// Realized Capital Gains on Reserves Calendar Year to Date Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_RES_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(367,"realzd_cap_gain_res_ytd_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_res_ytd_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	 return NO_AVG;

return sum_over_segments("realzd_cap_gain_res_ytd_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gains from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_sale(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_tgt_cap
// Realized Capital Gains on Target Capital                                                                                             
// Column:REALZD_CAP_GAIN_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(369,"realzd_cap_gain_tgt_cap",t);
}



//^^^

#line 1 "realzd_cap_gain_tgt_cap.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_tgt_cap", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_tgt_cap_bef_sale
// Realized Capital Gains on Target Capital Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(370,"realzd_cap_gain_tgt_cap_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_tgt_cap_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_tgt_cap_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_tgt_cap_ytd
// Realized Capital Gains on Target Capital Calendar Year to Date                                                                                             
// Column:REALZD_CAP_GAIN_TGT_CAP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(371,"realzd_cap_gain_tgt_cap_ytd",t);
}



//^^^

#line 1 "realzd_cap_gain_tgt_cap_ytd.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	 return NO_AVG;

return sum_over_segments("realzd_cap_gain_tgt_cap_ytd", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_tgt_cap_ytd_bef_sale
// Realized Capital Gains Target Capital on Calendar Year to Date Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_TGT_CAP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(372,"realzd_cap_gain_tgt_cap_ytd_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_tgt_cap_ytd_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("realzd_cap_gain_tgt_cap_ytd_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_undistrib_earnings
// Realized Capital Gains on Undistributed Earnings                                                                                             
// Column:REALZD_CAP_GAIN_UNDISTRIB_EARNINGS
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(373,"realzd_cap_gain_undistrib_earnings",t);
}



//^^^

#line 1 "realzd_cap_gain_undistrib_earnings.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_undistrib_earnings", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_undistrib_earnings", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_undistrib_earnings_bef_sale
// Realized Capital Gains on Undistributed Earnings Before Sales                                                                                             
// Column:REALZD_CAP_GAIN_UNDISTRIB_EARNINGS_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(374,"realzd_cap_gain_undistrib_earnings_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_undistrib_earnings_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_undistrib_earnings_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_undistrib_earnings_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_undistrib_earnings_ytd
// Realized Capital Gains on Undistributed Earnings Calendar Year to Date                                                                                             
// Column:REALZD_CAP_GAIN_UNDISTRIB_EARNINGS_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(375,"realzd_cap_gain_undistrib_earnings_ytd",t);
}



//^^^

#line 1 "realzd_cap_gain_undistrib_earnings_ytd.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	 return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_undistrib_earnings_ytd", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_undistrib_earnings_ytd", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - realzd_cap_gain_undistrib_earnings_ytd_bef_sale
// Realized Capital Gains on Undistributed Earnings Calendar Year to Date Before Sale                                                                                             
// Column:REALZD_CAP_GAIN_UNDISTRIB_EARNINGS_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(376,"realzd_cap_gain_undistrib_earnings_ytd_bef_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_undistrib_earnings_ytd_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	 return NO_AVG;

if (tcm_flag)
	return sum_over_segments("realzd_cap_gain_undistrib_earnings_ytd_bef_sale", t, CORPORATE_SEGMENT);

return sum_over_segments("realzd_cap_gain_undistrib_earnings_ytd_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - reins_ann_benefits_bom
// Reinsurance Annuity Benefits Beginning of Month                                                                                             
// Column:REINS_ANN_BENEFITS_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_ann_benefits_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(377,"reins_ann_benefits_bom",t);
}



//^^^

#line 1 "reins_ann_benefits_bom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_ann_benefits_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_ann_benefits_eom
// Reinsurance Annuity Benefits End of Month                                                                                             
// Column:REINS_ANN_BENEFITS_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(378,"reins_ann_benefits_eom",t);
}



//^^^

#line 1 "reins_ann_benefits_eom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_ann_benefits_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_cap_gain_res
// Reinsurance Capital Gains on Reserve                                                                                             
// Column:REINS_CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(379,"reins_cap_gain_res",t);
}



//^^^

#line 1 "reins_cap_gain_res.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_cap_gain_res_bef_sale
// Reinsurance Capital Gains on Reserve Before Sales                                                                                             
// Column:REINS_CAP_GAIN_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cap_gain_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(380,"reins_cap_gain_res_bef_sale",t);
}



//^^^

#line 1 "reins_cap_gain_res_bef_sale.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_cap_gain_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_cash_flow_bom
// Reinsurance Cash Flow Beginning of Month                                                                                             
// Column:REINS_CASH_FLOW_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(381,"reins_cash_flow_bom",t);
}



//^^^

#line 1 "reins_cash_flow_bom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_prem(t)
       + reins_div_applied(t)
	   - reins_prem_tax(t)
	   - reins_ea(t)
	   - reins_prem_waiver_benefits(t)
       + reins_inv_fee_ref(t)
       - reins_comm_reimb_bom(t)
       - reins_exp_reimb_bom(t)
	   - reins_div_paid(t)
	   - reins_ann_benefits_bom(t);

}


//@@ END

//@@ START - reins_cash_flow_eom
// Reinsurance Cash Flow End of Month                                                                                             
// Column:REINS_CASH_FLOW_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(382,"reins_cash_flow_eom",t);
}



//^^^

#line 1 "reins_cash_flow_eom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return - reins_ref(t)
       - reins_modco_res_adj(t)
	   - reins_dth_benefits(t)
	   - reins_ann_benefits_eom(t)
	   - reins_endow_benefits(t)
	   - reins_maturity_benefits(t)
	   - reins_surr_benefits(t)
	   - reins_withdrl_benefits(t)
	   - reins_claim_paid(t)
	   - reins_comm_reimb_eom(t)
	   + reins_comm_chargeback_reimb(t)
	   + reins_ea_chargeback(t)
	   + reins_exp(t)
       - reins_exp_reimb_eom(t)
	   - reins_terminal_div(t);

}


//@@ END

//@@ START - reins_cash_flow_int
// Reinsurance Cash Flow Interest                                                                                             
// Column:REINS_CASH_FLOW_INT
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(383,"reins_cash_flow_int",t);
}



//^^^

#line 1 "reins_cash_flow_int.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_cash_flow_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_cash_val
// Reinsurance Cash Value                                                                                             
// Column:REINS_CASH_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_reins_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(384,"reins_cash_val",t);
}



//^^^

#line 1 "reins_cash_val.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_cash_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_claim_paid
// Reinsurance Claim Paid                                                                                             
// Column:REINS_CLAIM_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_reins_claim_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(385,"reins_claim_paid",t);
}



//^^^

#line 1 "reins_claim_paid.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
    return NO_AVG;
    
return sum_over_segments("reins_claim_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_comm_chargeback_reimb
// Reinsurance Commission Chargeback Reimbursement                                                                                             
// Column:REINS_COMM_CHARGEBACK_REIMB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_comm_chargeback_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(386,"reins_comm_chargeback_reimb",t);
}



//^^^

#line 1 "reins_comm_chargeback_reimb.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_comm_chargeback_reimb", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_comm_reimb
// Reinsurance Commission Reimbursed                                                                                             
// Column:REINS_COMM_REIMB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_comm_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(387,"reins_comm_reimb",t);
}



//^^^

#line 1 "reins_comm_reimb.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_comm_reimb_bom(t)
       + reins_comm_reimb_eom(t)
       - reins_comm_chargeback_reimb(t);

}


//@@ END

//@@ START - reins_comm_reimb_bom
// Reinsurance Commission Reimbursement Beginning of Month                                                                                             
// Column:REINS_COMM_REIMB_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_comm_reimb_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(388,"reins_comm_reimb_bom",t);
}



//^^^

#line 1 "reins_comm_reimb_bom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_comm_reimb_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_comm_reimb_eom
// Reinsurance Commission Reimbursement End of Month                                                                                             
// Column:REINS_COMM_REIMB_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_comm_reimb_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(389,"reins_comm_reimb_eom",t);
}



//^^^

#line 1 "reins_comm_reimb_eom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_comm_reimb_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_deferred_gross_prem
// Reinsurance Deferred Gross Premium                                                                                             
// Column:REINS_DEFERRED_GROSS_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_deferred_gross_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(390,"reins_deferred_gross_prem",t);
}



//^^^

#line 1 "reins_deferred_gross_prem.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_deferred_gross_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_deferred_gross_prem_incr
// Reinsurance Deferred Gross Premium Increase                                                                                             
// Column:REINS_DEFERRED_GROSS_PREM_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_deferred_gross_prem_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(391,"reins_deferred_gross_prem_incr",t);
}



//^^^

#line 1 "reins_deferred_gross_prem_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_deferred_gross_prem(t)
	   - reins_deferred_gross_prem(t - 1);

}


//@@ END

//@@ START - reins_deferred_net_prem
// Reinsurance Deferred Net Premium                                                                                             
// Column:REINS_DEFERRED_NET_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(392,"reins_deferred_net_prem",t);
}



//^^^

#line 1 "reins_deferred_net_prem.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_deferred_net_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_div_applied
// Reinsurance Dividend Applied                                                                                             
// Column:REINS_DIV_APPLIED
//========================================================
double COMP_COMP_UDF::comp_comp_reins_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(393,"reins_div_applied",t);
}



//^^^

#line 1 "reins_div_applied.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_div_applied", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_div_liab
// Reinsurance Dividend Liability                                                                                             
// Column:REINS_DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(394,"reins_div_liab",t);
}



//^^^

#line 1 "reins_div_liab.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;
	
if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_div_liab_incr
// Reinsurance Dividend Liability Increase                                                                                             
// Column:REINS_DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(395,"reins_div_liab_incr",t);
}



//^^^

#line 1 "reins_div_liab_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_div_liab(t)
	   - reins_div_liab(t - 1);

}


//@@ END

//@@ START - reins_div_paid
// Reinsurance Dividend Paid                                                                                             
// Column:REINS_DIV_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_reins_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(396,"reins_div_paid",t);
}



//^^^

#line 1 "reins_div_paid.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_div_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_dth_ben_inf
// Reinsured Death Benefit In Force                                                                                             
// Column:REINS_DTH_BEN_INF
//========================================================
double COMP_COMP_UDF::comp_comp_reins_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(397,"reins_dth_ben_inf",t);
}



//^^^

#line 1 "reins_dth_ben_inf.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_dth_ben_inf", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_dth_benefits
// Reinsurance Death Benefits                                                                                             
// Column:REINS_DTH_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(398,"reins_dth_benefits",t);
}



//^^^

#line 1 "reins_dth_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_dth_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_ea
// Reinsurance Expense Allowance                                                                                             
// Column:REINS_EA
//========================================================
double COMP_COMP_UDF::comp_comp_reins_ea(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(399,"reins_ea",t);
}



//^^^

#line 1 "reins_ea.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_ea", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_ea_chargeback
// Reinsurance Expense Allowance Chargeback                                                                                             
// Column:REINS_EA_CHARGEBACK
//========================================================
double COMP_COMP_UDF::comp_comp_reins_ea_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(400,"reins_ea_chargeback",t);
}



//^^^

#line 1 "reins_ea_chargeback.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_ea_chargeback", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_endow_benefits
// Reinsurance Endowment Benefits                                                                                             
// Column:REINS_ENDOW_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(401,"reins_endow_benefits",t);
}



//^^^

#line 1 "reins_endow_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_endow_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_exp
// Reinsurance Expense                                                                                             
// Column:REINS_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_reins_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(402,"reins_exp",t);
}



//^^^

#line 1 "reins_exp.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_exp_reimb
// Reinsurance Expense Reimbursed                                                                                             
// Column:REINS_EXP_REIMB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_exp_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(403,"reins_exp_reimb",t);
}



//^^^

#line 1 "reins_exp_reimb.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_exp_reimb_bom(t)
       + reins_exp_reimb_eom(t);

}


//@@ END

//@@ START - reins_exp_reimb_bom
// Reinsurance Expense Reimbursed Beginning of Month                                                                                             
// Column:REINS_EXP_REIMB_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_exp_reimb_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(404,"reins_exp_reimb_bom",t);
}



//^^^

#line 1 "reins_exp_reimb_bom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_exp_reimb_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_exp_reimb_eom
// Reinsurance Expense Reimbursed End of Month                                                                                             
// Column:REINS_EXP_REIMB_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_exp_reimb_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(405,"reins_exp_reimb_eom",t);
}



//^^^

#line 1 "reins_exp_reimb_eom.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_exp_reimb_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_ben_res
// Reinsurance GAAP Benefit Reserve                                                                                             
// Column:REINS_GAAP_BEN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_ben_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(406,"reins_gaap_ben_res",t);
}



//^^^

#line 1 "reins_gaap_ben_res.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_gaap_ben_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_ben_res_incr
// Reinsurance GAAP Benefit Reserve Increase                                                                                             
// Column:REINS_GAAP_BEN_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_ben_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(407,"reins_gaap_ben_res_incr",t);
}



//^^^

#line 1 "reins_gaap_ben_res_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_ben_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_cap_gain_res
// Reinsurance GAAP Capital Gain on Reserves                                                                                             
// Column:REINS_GAAP_CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(408,"reins_gaap_cap_gain_res",t);
}



//^^^

#line 1 "reins_gaap_cap_gain_res.COMP_COMP.for"
if (!gaap_flag || !alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_capzd_comm_bom
// Reinsurance GAAP Capitalized Commissions BOM                                                                                             
// Column:REINS_GAAP_CAPZD_COMM_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_capzd_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(409,"reins_gaap_capzd_comm_bom",t);
}



//^^^

#line 1 "reins_gaap_capzd_comm_bom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_capzd_comm_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_capzd_comm_eom
// Reinsurance GAAP Capitalized Commissions EOM                                                                                             
// Column:REINS_GAAP_CAPZD_COMM_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_capzd_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(410,"reins_gaap_capzd_comm_eom",t);
}



//^^^

#line 1 "reins_gaap_capzd_comm_eom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_capzd_comm_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_capzd_prem_bonus
// Reinsurance GAAP Capitalized Premium Bonus                                                                                             
// Column:REINS_GAAP_CAPZD_PREM_BONUS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_capzd_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(411,"reins_gaap_capzd_prem_bonus",t);
}



//^^^

#line 1 "reins_gaap_capzd_prem_bonus.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_capzd_prem_bonus", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_cash_flow_int
// Reinsurance GAAP Cash Flow Interest                                                                                             
// Column:REINS_GAAP_CASH_FLOW_INT
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(412,"reins_gaap_cash_flow_int",t);
}



//^^^

#line 1 "reins_gaap_cash_flow_int.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_cash_flow_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_chg_inc
// Reinsurance GAAP Charges Income                                                                                             
// Column:REINS_GAAP_CHG_INC
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_chg_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(413,"reins_gaap_chg_inc",t);
}



//^^^

#line 1 "reins_gaap_chg_inc.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_chg_inc", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_claim_res
// Reinsurance GAAP Claim Reserve                                                                                             
// Column:REINS_GAAP_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(414,"reins_gaap_claim_res",t);
}



//^^^

#line 1 "reins_gaap_claim_res.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_claim_res_incr
// Reinsurance GAAP Claim Reserve Increase                                                                                             
// Column:REINS_GAAP_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(415,"reins_gaap_claim_res_incr",t);
}



//^^^

#line 1 "reins_gaap_claim_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_claim_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_comm_excess_bom
// Reinsurance GAAP Commission Excess BOM                                                                                             
// Column:REINS_GAAP_COMM_EXCESS_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_comm_excess_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(416,"reins_gaap_comm_excess_bom",t);
}



//^^^

#line 1 "reins_gaap_comm_excess_bom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_comm_excess_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_comm_excess_eom
// Reinsurance GAAP Commission Excess EOM                                                                                             
// Column:REINS_GAAP_COMM_EXCESS_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_comm_excess_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(417,"reins_gaap_comm_excess_eom",t);
}



//^^^

#line 1 "reins_gaap_comm_excess_eom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_comm_excess_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_comm_trail_bom
// Reinsurance GAAP Commission Trail BOM                                                                                             
// Column:REINS_GAAP_COMM_TRAIL_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_comm_trail_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(418,"reins_gaap_comm_trail_bom",t);
}



//^^^

#line 1 "reins_gaap_comm_trail_bom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_comm_trail_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_comm_trail_eom
// Reinsurance GAAP Commission Trail EOM                                                                                             
// Column:REINS_GAAP_COMM_TRAIL_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_comm_trail_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(419,"reins_gaap_comm_trail_eom",t);
}



//^^^

#line 1 "reins_gaap_comm_trail_eom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_comm_trail_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_cost
// Reinsurance GAAP Cost                                                                                             
// Column:REINS_GAAP_COST
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(420,"reins_gaap_cost",t);
}



//^^^

#line 1 "reins_gaap_cost.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

double reins_gaap_cost = 0.0;

//force calls for reporting
reins_gaap_capzd_comm_bom(t);
reins_gaap_capzd_comm_eom(t);
reins_gaap_capzd_prem_bonus(t);

reins_gaap_cost
= reins_gaap_prem(t)
  + reins_gaap_div_applied(t)
  - reins_gaap_refund(t)
  - reins_gaap_modco_res_adj(t)
  + reins_gaap_modco_liab_incr(t)   
  + reins_gaap_loads_deducted(t)
  - reins_gaap_loads_deferred(t)
  + reins_gaap_chg_inc(t)
  + reins_gaap_surr_inc(t)
  + reins_gaap_unearn_rev_released(t)
  + reins_gaap_cash_flow_int(t)
  + reins_gaap_inv_inc_res(t)
  + reins_gaap_cap_gain_res(t)
  - reins_gaap_prem_bonus(t)
  - reins_gaap_credited_int(t)
  - reins_gaap_recoveries(t)
  - reins_gaap_ben_res_incr(t)
  - reins_gaap_maint_exp_res_incr(t)
  - reins_gaap_deferred_prof_liab_incr(t)
  - reins_gaap_claim_res_incr(t)
  - reins_gaap_prem_waiver_res_incr(t)
  - reins_gaap_sfas133_liab_incr(t)
  - reins_gaap_sop031_addl_liab_incr(t)
  - reins_gaap_div_liab_incr(t)
  - reins_gaap_div_paid(t)
  - reins_gaap_terminal_div(t)
  - reins_gaap_comm_trail_bom(t)
  - reins_gaap_comm_trail_eom(t)
  - reins_gaap_comm_excess_bom(t)
  - reins_gaap_comm_excess_eom(t)
  + reins_gaap_deferred_maint_exp(t)
  - reins_gaap_maint_exp_bom(t)
  - reins_gaap_maint_exp_eom(t)
  - reins_gaap_prem_tax(t)
  + reins_gaap_dac_incr(t);

return reins_gaap_cost;

}


//@@ END

//@@ START - reins_gaap_credited_int
// Reinsurance GAAP Credited Interest                                                                                             
// Column:REINS_GAAP_CREDITED_INT
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(421,"reins_gaap_credited_int",t);
}



//^^^

#line 1 "reins_gaap_credited_int.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_credited_int", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_dac
// Reinsurance GAAP DAC                                                                                             
// Column:REINS_GAAP_DAC
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_dac(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(422,"reins_gaap_dac",t);
}



//^^^

#line 1 "reins_gaap_dac.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_dac", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_dac_incr
// Reinsurance GAAP DAC Increase                                                                                             
// Column:REINS_GAAP_DAC_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_dac_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(423,"reins_gaap_dac_incr",t);
}



//^^^

#line 1 "reins_gaap_dac_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_dac_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_deferred_maint_exp
// Reinsurance GAAP Deferred Maintenance Expense                                                                                             
// Column:REINS_GAAP_DEFERRED_MAINT_EXP
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_deferred_maint_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(424,"reins_gaap_deferred_maint_exp",t);
}



//^^^

#line 1 "reins_gaap_deferred_maint_exp.COMP_COMP.for"
if (!gaap_flag || !reins_flag  || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_deferred_maint_exp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_deferred_prof_liab
// Reinsurance GAAP Deferred Profit Liability                                                                                             
// Column:REINS_GAAP_DEFERRED_PROF_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_deferred_prof_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(425,"reins_gaap_deferred_prof_liab",t);
}



//^^^

#line 1 "reins_gaap_deferred_prof_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_deferred_prof_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_deferred_prof_liab_incr
// Reinsurance GAAP Deferred Profit Liability Increase                                                                                             
// Column:REINS_GAAP_DEFERRED_PROF_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_deferred_prof_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(426,"reins_gaap_deferred_prof_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_deferred_prof_liab_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_deferred_prof_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_div_applied
// Reinsurance GAAP Dividend Applied                                                                                             
// Column:REINS_GAAP_DIV_APPLIED
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(427,"reins_gaap_div_applied",t);
}



//^^^

#line 1 "reins_gaap_div_applied.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_div_applied", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_div_liab
// Reinsurance GAAP Dividend Liability                                                                                             
// Column:REINS_GAAP_DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(428,"reins_gaap_div_liab",t);
}



//^^^

#line 1 "reins_gaap_div_liab.COMP_COMP.for"
if (!gaap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_div_liab_incr
// Reinsurance GAAP Dividend Liability Increase                                                                                             
// Column:REINS_GAAP_DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(429,"reins_gaap_div_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_div_liab_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_div_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_div_paid
// Reinsurance GAAP Dividend Paid                                                                                             
// Column:REINS_GAAP_DIV_PAID
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(430,"reins_gaap_div_paid",t);
}



//^^^

#line 1 "reins_gaap_div_paid.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_div_paid", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_dth_claim_cost
// Reinsurance GAAP Death Claim Cost                                                                                             
// Column:REINS_GAAP_DTH_CLAIM_COST
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_dth_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(431,"reins_gaap_dth_claim_cost",t);
}



//^^^

#line 1 "reins_gaap_dth_claim_cost.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_dth_claim_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_inv_inc_res
// Reinsurance GAAP Investment Income on Reserves                                                                                             
// Column:REINS_GAAP_INV_INC_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(432,"reins_gaap_inv_inc_res",t);
}



//^^^

#line 1 "reins_gaap_inv_inc_res.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_inv_inc_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_liab_net
// Reinsurance GAAP Recoverables Net of DAC                                                                                             
// Column:REINS_GAAP_LIAB_NET
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_liab_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(433,"reins_gaap_liab_net",t);
}



//^^^

#line 1 "reins_gaap_liab_net.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return reins_gaap_ben_res(t)
       + reins_gaap_maint_exp_res(t)
	   + reins_gaap_deferred_prof_liab(t)
       + reins_gaap_claim_res(t)
	   + reins_gaap_prem_waiver_res(t)
	   + reins_gaap_unearn_rev_liab(t)
	   + reins_gaap_sfas133_liab(t)
	   + reins_gaap_sop031_addl_liab(t)
	   + reins_gaap_div_liab(t)
	   - reins_gaap_dac(t)
	   - reins_gaap_modco_liab(t);

}


//@@ END

//@@ START - reins_gaap_loads_deducted
// Reinsurance GAAP Loads Deducted                                                                                             
// Column:REINS_GAAP_LOADS_DEDUCTED
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_loads_deducted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(434,"reins_gaap_loads_deducted",t);
}



//^^^

#line 1 "reins_gaap_loads_deducted.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_loads_deducted", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_loads_deferred
// Reinsurance GAAP Loads Deferred                                                                                             
// Column:REINS_GAAP_LOADS_DEFERRED
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_loads_deferred(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(435,"reins_gaap_loads_deferred",t);
}



//^^^

#line 1 "reins_gaap_loads_deferred.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_loads_deferred", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_maint_exp_bom
// Reinsurance GAAP Maintenance Expenses BOM                                                                                             
// Column:REINS_GAAP_MAINT_EXP_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(436,"reins_gaap_maint_exp_bom",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_bom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_maint_exp_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_maint_exp_eom
// Reinsurance GAAP Maintenance Expenses EOM                                                                                             
// Column:REINS_GAAP_MAINT_EXP_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(437,"reins_gaap_maint_exp_eom",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_eom.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_maint_exp_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_maint_exp_res
// Reinsurance GAAP Maintenance Expense Reserve                                                                                             
// Column:REINS_GAAP_MAINT_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(438,"reins_gaap_maint_exp_res",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_res.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_gaap_maint_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_maint_exp_res_incr
// Reinsurance GAAP Maintenance Expense Reserve Increase                                                                                             
// Column:REINS_GAAP_MAINT_EXP_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(439,"reins_gaap_maint_exp_res_incr",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_res_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_maint_exp_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_modco_liab
// Reinsurance GAAP Modco Liability                                                                                             
// Column:REINS_GAAP_MODCO_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_modco_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(440,"reins_gaap_modco_liab",t);
}



//^^^

#line 1 "reins_gaap_modco_liab.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_gaap_modco_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_modco_liab_incr
// Reinsurance GAAP Modco Liability Increase                                                                                             
// Column:REINS_GAAP_MODCO_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_modco_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(441,"reins_gaap_modco_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_modco_liab_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_gaap_modco_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_modco_res_adj
// Reinsurance GAAP Modco Reserve Adjustment                                                                                             
// Column:REINS_GAAP_MODCO_RES_ADJ
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_modco_res_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(442,"reins_gaap_modco_res_adj",t);
}



//^^^

#line 1 "reins_gaap_modco_res_adj.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_modco_res_adj", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_prem
// Reinsurance GAAP Premium                                                                                             
// Column:REINS_GAAP_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(443,"reins_gaap_prem",t);
}



//^^^

#line 1 "reins_gaap_prem.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_prem_bonus
// Reinsurance GAAP Premium Bonus                                                                                             
// Column:REINS_GAAP_PREM_BONUS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(444,"reins_gaap_prem_bonus",t);
}



//^^^

#line 1 "reins_gaap_prem_bonus.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_prem_bonus", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_prem_tax
// Reinsurance GAAP Premium Taxes                                                                                             
// Column:REINS_GAAP_PREM_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(445,"reins_gaap_prem_tax",t);
}



//^^^

#line 1 "reins_gaap_prem_tax.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_prem_tax", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_prem_waiver_res
// Reinsurance GAAP Premium Waiver Reserve                                                                                             
// Column:REINS_GAAP_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_prem_waiver_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(446,"reins_gaap_prem_waiver_res",t);
}



//^^^

#line 1 "reins_gaap_prem_waiver_res.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_prem_waiver_res_incr
// Reinsurance GAAP Premium Waiver Reserve Increase                                                                                             
// Column:REINS_GAAP_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(447,"reins_gaap_prem_waiver_res_incr",t);
}



//^^^

#line 1 "reins_gaap_prem_waiver_res_incr.COMP_COMP.for"
if (!gaap_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_prem_waiver_res_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_recoveries
// Reinsurance GAAP Recoveries                                                                                             
// Column:REINS_GAAP_RECOVERIES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_recoveries(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(448,"reins_gaap_recoveries",t);
}



//^^^

#line 1 "reins_gaap_recoveries.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_recoveries", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_refund
// Reinsurance GAAP Refund                                                                                             
// Column:REINS_GAAP_REFUND
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_refund(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(449,"reins_gaap_refund",t);
}



//^^^

#line 1 "reins_gaap_refund.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_refund", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_sfas133_liab
// Reinsurance GAAP SFAS 133 Liability                                                                                             
// Column:REINS_GAAP_SFAS133_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_sfas133_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(450,"reins_gaap_sfas133_liab",t);
}



//^^^

#line 1 "reins_gaap_sfas133_liab.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_sfas133_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_sfas133_liab_incr
// Reinsurance GAAP SFAS 133 Liability Increase                                                                                             
// Column:REINS_GAAP_SFAS133_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_sfas133_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(451,"reins_gaap_sfas133_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_sfas133_liab_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_sfas133_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_sop031_addl_liab
// Reinsurance GAAP SOP 03-1 Additional Liability                                                                                             
// Column:REINS_GAAP_SOP031_ADDL_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_sop031_addl_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(452,"reins_gaap_sop031_addl_liab",t);
}



//^^^

#line 1 "reins_gaap_sop031_addl_liab.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_gaap_sop031_addl_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_sop031_addl_liab_incr
// Reinsurance GAAP SOP 03-1 Additional Liability Increase                                                                                             
// Column:REINS_GAAP_SOP031_ADDL_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_sop031_addl_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(453,"reins_gaap_sop031_addl_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_sop031_addl_liab_incr.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_sop031_addl_liab_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_surr_inc
// Reinsurance GAAP Surrender Income                                                                                             
// Column:REINS_GAAP_SURR_INC
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_surr_inc(int t) {
//^^^



//^^^

#line 1 "reins_gaap_surr_inc.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_surr_inc", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_terminal_div
// Reinsurance GAAP Terminal Dividends                                                                                             
// Column:REINS_GAAP_TERMINAL_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_terminal_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(455,"reins_gaap_terminal_div",t);
}



//^^^

#line 1 "reins_gaap_terminal_div.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_terminal_div", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_unearn_rev_liab
// Reinsurance GAAP Unearned Revenue Liability                                                                                             
// Column:REINS_GAAP_UNEARN_REV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_unearn_rev_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(456,"reins_gaap_unearn_rev_liab",t);
}



//^^^

#line 1 "reins_gaap_unearn_rev_liab.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return sum_over_segments("reins_gaap_unearn_rev_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_unearn_rev_released
// Reinsurance GAAP Unearned Revenue Released                                                                                             
// Column:REINS_GAAP_UNEARN_REV_RELEASED
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_unearn_rev_released(int t) {
//^^^



//^^^

#line 1 "reins_gaap_unearn_rev_released.COMP_COMP.for"
if (!gaap_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_unearn_rev_released", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_gaap_unrealzd_cap_gain_incr
// Reinsurance GAAP Unrealized Cap Gain Increase                                                                                             
// Column:REINS_GAAP_UNREALZD_CAP_GAIN_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(458,"reins_gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "reins_gaap_unrealzd_cap_gain_incr.COMP_COMP.for"
if (!gaap_flag || !alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_gaap_unrealzd_cap_gain_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_imr_impact_res
// Reinsurance IMR Impact on Reserves                                                                                             
// Column:REINS_IMR_IMPACT_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_imr_impact_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(459,"reins_imr_impact_res",t);
}



//^^^

#line 1 "reins_imr_impact_res.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_imr_impact_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_imr_impact_res_bef_sale
// Reinsurance IMR Impact on Reserves Before Sales                                                                                             
// Column:REINS_IMR_IMPACT_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_reins_imr_impact_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(460,"reins_imr_impact_res_bef_sale",t);
}



//^^^

#line 1 "reins_imr_impact_res_bef_sale.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_imr_impact_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_inv_fee_ref
// Reinsurance Investment Fee Refund                                                                                             
// Column:REINS_INV_FEE_REF
//========================================================
double COMP_COMP_UDF::comp_comp_reins_inv_fee_ref(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(461,"reins_inv_fee_ref",t);
}



//^^^

#line 1 "reins_inv_fee_ref.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_inv_fee_ref", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_inv_inc_res
// Reinsurance Investment Income Reserve                                                                                             
// Column:REINS_INV_INC_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(462,"reins_inv_inc_res",t);
}



//^^^

#line 1 "reins_inv_inc_res.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_inv_inc_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_maturity_benefits
// Reinsurance Maturity Benefits                                                                                             
// Column:REINS_MATURITY_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(463,"reins_maturity_benefits",t);
}



//^^^

#line 1 "reins_maturity_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_maturity_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_modco_res_adj
// Modified Coinsurance Reserve Adjustment                                                                                             
// Column:REINS_MODCO_RES_ADJ
//========================================================
double COMP_COMP_UDF::comp_comp_reins_modco_res_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(464,"reins_modco_res_adj",t);
}



//^^^

#line 1 "reins_modco_res_adj.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_modco_res_adj", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_prem
// Reinsurance Premium                                                                                             
// Column:REINS_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(465,"reins_prem",t);
}



//^^^

#line 1 "reins_prem.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_prem_tax
// Reinsurance Premium Tax                                                                                             
// Column:REINS_PREM_TAX
//========================================================
double COMP_COMP_UDF::comp_comp_reins_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(466,"reins_prem_tax",t);
}



//^^^

#line 1 "reins_prem_tax.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_prem_tax", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_prem_waiver_benefits
// Reinsurance Premium Waiver Benefits                                                                                             
// Column:REINS_PREM_WAIVER_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_prem_waiver_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(467,"reins_prem_waiver_benefits",t);
}



//^^^

#line 1 "reins_prem_waiver_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
    return NO_AVG;
    
return sum_over_segments("reins_prem_waiver_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_realzd_cap_gain_res
// Reinsurance Realized Capital Gains on Reserve                                                                                             
// Column:REINS_REALZD_CAP_GAIN_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(468,"reins_realzd_cap_gain_res",t);
}



//^^^

#line 1 "reins_realzd_cap_gain_res.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_realzd_cap_gain_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_realzd_cap_gain_res_bef_sale
// Reinsurance Realized Capital Gains on Reserve Before Sales                                                                                             
// Column:REINS_REALZD_CAP_GAIN_RES_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(469,"reins_realzd_cap_gain_res_bef_sale",t);
}



//^^^

#line 1 "reins_realzd_cap_gain_res_bef_sale.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_realzd_cap_gain_res_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_realzd_cap_gain_res_ytd
// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date                                                                                             
// Column:REINS_REALZD_CAP_GAIN_RES_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(470,"reins_realzd_cap_gain_res_ytd",t);
}



//^^^

#line 1 "reins_realzd_cap_gain_res_ytd.COMP_COMP.for"
if (!alm_flag || !reins_flag || t < start_period || t > final_period)
	 return NO_AVG;

return sum_over_segments("reins_realzd_cap_gain_res_ytd", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_realzd_cap_gain_res_ytd_bef_sale
// Reinsurance Realized Capital Gain on Reserves Calendar Year to Date Before Sales                                                                                             
// Column:REINS_REALZD_CAP_GAIN_RES_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(471,"reins_realzd_cap_gain_res_ytd_bef_sale",t);
}



//^^^

#line 1 "reins_realzd_cap_gain_res_ytd_bef_sale.COMP_COMP.for"
if (!alm_flag || !reins_flag || t <= start_period || t > final_period)
	 return NO_AVG;

return sum_over_segments("reins_realzd_cap_gain_res_ytd_bef_sale", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_ref
// Reinsurance Refund                                                                                             
// Column:REINS_REF
//========================================================
double COMP_COMP_UDF::comp_comp_reins_ref(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(472,"reins_ref",t);
}



//^^^

#line 1 "reins_ref.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_ref", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_claim_res
// Reinsurance Statutory Claim Reserve                                                                                             
// Column:REINS_STAT_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_claim_res(int t) {
//^^^



//^^^

#line 1 "reins_stat_claim_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_stat_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_claim_res_incr
// Reinsurance Statutory Claim Reserve Increase                                                                                             
// Column:REINS_STAT_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(474,"reins_stat_claim_res_incr",t);
}



//^^^

#line 1 "reins_stat_claim_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_stat_claim_res(t)
	   - reins_stat_claim_res(t - 1);

}


//@@ END

//@@ START - reins_stat_cost
// Reinsurance Statutory Cost                                                                                             
// Column:REINS_STAT_COST
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(475,"reins_stat_cost",t);
}



//^^^

#line 1 "reins_stat_cost.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_prem(t)
       + reins_div_applied(t)
	   - reins_ea(t)
	   + reins_ea_chargeback(t) 
	   - reins_ref(t) 
	   - reins_modco_res_adj(t)
	   + reins_inv_fee_ref(t)
       + reins_deferred_gross_prem_incr(t)
	   - reins_stat_unearn_prem_res_incr(t)
       + reins_cash_flow_int(t)
       + reins_inv_inc_res(t)
       + reins_cap_gain_res(t) 
       - reins_imr_impact_res(t) 
       - reins_dth_benefits(t)
	   - reins_ann_benefits_bom(t)
	   - reins_ann_benefits_eom(t)
	   - reins_endow_benefits(t)
	   - reins_maturity_benefits(t)
	   - reins_surr_benefits(t)
	   - reins_withdrl_benefits(t)
	   - reins_claim_paid(t)
	   - reins_prem_waiver_benefits(t) 
       - reins_exp_reimb(t)
       - reins_comm_reimb(t)
       + reins_exp(t)
	   - reins_prem_tax(t)
	   - reins_stat_claim_res_incr(t)
	   - reins_stat_prem_waiver_res_incr(t)
       - reins_stat_res_incr(t)
       - reins_stat_loading_incr(t)
       - reins_div_liab_incr(t)
	   - reins_div_paid(t)
	   - reins_terminal_div(t);

}


//@@ END

//@@ START - reins_stat_cost_bef_sale
// Reinsurance Statutory Cost Before Sales                                                                                             
// Column:REINS_STAT_COST_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_cost_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(476,"reins_stat_cost_bef_sale",t);
}



//^^^

#line 1 "reins_stat_cost_bef_sale.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_prem(t)
       + reins_div_applied(t)
	   - reins_ea(t)
	   + reins_ea_chargeback(t) 
	   - reins_ref(t) 
	   - reins_modco_res_adj(t)
	   + reins_inv_fee_ref(t)
       + reins_deferred_gross_prem_incr(t)
	   - reins_stat_unearn_prem_res_incr(t)
       + reins_cash_flow_int(t)
       + reins_inv_inc_res(t)
       + reins_cap_gain_res_bef_sale(t) 
       - reins_imr_impact_res_bef_sale(t) 
       - reins_dth_benefits(t)
	   - reins_ann_benefits_bom(t)
	   - reins_ann_benefits_eom(t)
	   - reins_endow_benefits(t)
	   - reins_maturity_benefits(t)
	   - reins_surr_benefits(t)
	   - reins_withdrl_benefits(t)
	   - reins_claim_paid(t)
	   - reins_prem_waiver_benefits(t)
       - reins_exp_reimb(t)
       - reins_comm_reimb(t)
	   + reins_exp(t)
	   - reins_prem_tax(t)
	   - reins_stat_claim_res_incr(t)
	   - reins_stat_prem_waiver_res_incr(t)
       - reins_stat_res_incr(t)
       - reins_stat_loading_incr(t)
       - reins_div_liab_incr(t)
	   - reins_div_paid(t)
	   - reins_terminal_div(t);

}


//@@ END

//@@ START - reins_stat_loading
// Reinsurance Statutory Loading                                                                                             
// Column:REINS_STAT_LOADING
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(477,"reins_stat_loading",t);
}



//^^^

#line 1 "reins_stat_loading.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_stat_loading", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_loading_incr
// Reinsurance Statutory Loading Increase                                                                                             
// Column:REINS_STAT_LOADING_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_loading_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(478,"reins_stat_loading_incr",t);
}



//^^^

#line 1 "reins_stat_loading_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_stat_loading(t)
	   - reins_stat_loading(t - 1);

}


//@@ END

//@@ START - reins_stat_prem_waiver_res
// Reinsurance Statutory Premium Waiver Reserve                                                                                             
// Column:REINS_STAT_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "reins_stat_prem_waiver_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_stat_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_prem_waiver_res_incr
// Reinsurance Statutory Premium Waiver Reserve Increase                                                                                             
// Column:REINS_STAT_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(480,"reins_stat_prem_waiver_res_incr",t);
}



//^^^

#line 1 "reins_stat_prem_waiver_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_stat_prem_waiver_res(t) - reins_stat_prem_waiver_res(t - 1);

}


//@@ END

//@@ START - reins_stat_res
// Reinsurance Statutory Reserve                                                                                             
// Column:REINS_STAT_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(481,"reins_stat_res",t);
}



//^^^

#line 1 "reins_stat_res.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_stat_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_res_incr
// Reinsurance Statutory Reserve Increase                                                                                             
// Column:REINS_STAT_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(482,"reins_stat_res_incr",t);
}



//^^^

#line 1 "reins_stat_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_stat_res(t)
	   - reins_stat_res(t - 1);

}


//@@ END

//@@ START - reins_stat_unearn_prem_res
// Reinsurance Statutory Unearned Premium Reserve                                                                                             
// Column:REINS_STAT_UNEARN_PREM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_unearn_prem_res(int t) {
//^^^



//^^^

#line 1 "reins_stat_unearn_prem_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_stat_unearn_prem_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_stat_unearn_prem_res_incr
// Reinsurance Statutory Unearned Premium Reserve Increase                                                                                             
// Column:REINS_STAT_UNEARN_PREM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_stat_unearn_prem_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(484,"reins_stat_unearn_prem_res_incr",t);
}



//^^^

#line 1 "reins_stat_unearn_prem_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_stat_unearn_prem_res(t)
	   - reins_stat_unearn_prem_res(t - 1);

}


//@@ END

//@@ START - reins_surr_benefits
// Reinsurance Surrender Benefits                                                                                             
// Column:REINS_SURR_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(485,"reins_surr_benefits",t);
}



//^^^

#line 1 "reins_surr_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_surr_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_claim_res
// ReinsuranceTax Claim Reserve                                                                                             
// Column:REINS_TAX_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_claim_res(int t) {
//^^^



//^^^

#line 1 "reins_tax_claim_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_tax_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_claim_res_incr
// Reinsurance Tax Claim Reserve Increase                                                                                             
// Column:REINS_TAX_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(487,"reins_tax_claim_res_incr",t);
}



//^^^

#line 1 "reins_tax_claim_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_tax_claim_res(t)
	   - reins_tax_claim_res(t - 1);

}


//@@ END

//@@ START - reins_tax_deferred_net_prem
// Reinsurance Tax Deferred Net Premium                                                                                             
// Column:REINS_TAX_DEFERRED_NET_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(488,"reins_tax_deferred_net_prem",t);
}



//^^^

#line 1 "reins_tax_deferred_net_prem.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_tax_defered_net_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_div_liab
// Reinsurance Tax Dividend Liability                                                                                             
// Column:REINS_TAX_DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(489,"reins_tax_div_liab",t);
}



//^^^

#line 1 "reins_tax_div_liab.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return sum_over_segments("reins_tax_div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_div_liab_incr
// Reinsurance Tax Dividend Liability Increase                                                                                             
// Column:REINS_TAX_DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(490,"reins_tax_div_liab_incr",t);
}



//^^^

#line 1 "reins_tax_div_liab_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
    	
return reins_tax_div_liab(t) 
       - reins_tax_div_liab(t - 1);

}


//@@ END

//@@ START - reins_tax_loading
// Reinsurance Tax Loading                                                                                             
// Column:REINS_TAX_LOADING
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(491,"reins_tax_loading",t);
}



//^^^

#line 1 "reins_tax_loading.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("reins_tax_loading", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_loading_incr
// Reinsurance Tax Loading Increase                                                                                             
// Column:REINS_TAX_LOADING_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_loading_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(492,"reins_tax_loading_incr",t);
}



//^^^

#line 1 "reins_tax_loading_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_tax_loading(t)
	   - reins_tax_loading(t - 1);

}


//@@ END

//@@ START - reins_tax_prem_waiver_res
// Reinsurance Tax Premium Waiver Reserve                                                                                             
// Column:REINS_TAX_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "reins_tax_prem_waiver_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_tax_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_prem_waiver_res_incr
// Reinsurance Tax Premium Waiver Reserve Increase                                                                                             
// Column:REINS_TAX_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(494,"reins_tax_prem_waiver_res_incr",t);
}



//^^^

#line 1 "reins_tax_prem_waiver_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;
	
return reins_tax_prem_waiver_res(t) - reins_tax_prem_waiver_res(t - 1);

}


//@@ END

//@@ START - reins_tax_res
// Reinsurance Tax Reserve                                                                                             
// Column:REINS_TAX_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(495,"reins_tax_res",t);
}



//^^^

#line 1 "reins_tax_res.COMP_COMP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;
	
if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("reins_tax_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_res_incr
// Reinsurance Tax Reserve Increase                                                                                             
// Column:REINS_TAX_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(496,"reins_tax_res_incr",t);
}



//^^^

#line 1 "reins_tax_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_tax_res(t)
	   - reins_tax_res(t - 1);

}


//@@ END

//@@ START - reins_tax_unearn_prem_res
// Reinsurance Tax Unearned Premium Reserve                                                                                             
// Column:REINS_TAX_UNEARN_PREM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_unearn_prem_res(int t) {
//^^^



//^^^

#line 1 "reins_tax_unearn_prem_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_tax_unearn_prem_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_tax_unearn_prem_res_incr
// Reinsurance Tax Unearned Premium Reserve Increase                                                                                             
// Column:REINS_TAX_UNEARN_PREM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_reins_tax_unearn_prem_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(498,"reins_tax_unearn_prem_res_incr",t);
}



//^^^

#line 1 "reins_tax_unearn_prem_res_incr.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return reins_tax_unearn_prem_res(t)
	   - reins_tax_unearn_prem_res(t - 1);

}


//@@ END

//@@ START - reins_terminal_div
// Reinsurance Terminal Dividends                                                                                             
// Column:REINS_TERMINAL_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_reins_terminal_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(499,"reins_terminal_div",t);
}



//^^^

#line 1 "reins_terminal_div.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_terminal_div", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - reins_withdrl_benefits
// Reinsurance Withdrawal Benefits                                                                                             
// Column:REINS_WITHDRL_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_reins_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(500,"reins_withdrl_benefits",t);
}



//^^^

#line 1 "reins_withdrl_benefits.COMP_COMP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("reins_withdrl_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_inv_amt
// Rho Convexity Hedge Investment Amount                                                                                             
// Column:RHO_CONVEX_HEDGE_INV_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_inv_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_inv_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_mkt_val
// Rho Convexity Hedge Market Value of Assets                                                                                             
// Column:RHO_CONVEX_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_mkt_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_mkt_val_incr
// Rho Convexity Hedge Market Value of Assets                                                                                             
// Column:RHO_CONVEX_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_mkt_val_incr.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_mkt_val_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_pmt
// Rho Convexity Derivative Payment                                                                                             
// Column:RHO_CONVEX_HEDGE_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_prof
// Rho Convexity Hedge Profit                                                                                             
// Column:RHO_CONVEX_HEDGE_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_prof(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_sale_amt
// Rho Convexity Hedge Sale Amount                                                                                             
// Column:RHO_CONVEX_HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_sale_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_convex_hedge_transaction_cost
// Rho Convexity Hedge Transaction Cost                                                                                             
// Column:RHO_CONVEX_HEDGE_TRANSACTION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_rho_convex_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "rho_convex_hedge_transaction_cost.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_convex_hedge_transaction_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_inv_amt
// Rho Hedge Investment Amount                                                                                             
// Column:RHO_HEDGE_INV_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_inv_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_inv_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_mkt_val
// Rho Hedge Market Value of Assets                                                                                             
// Column:RHO_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "rho_hedge_mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_mkt_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_mkt_val_incr
// Rho Hedge Market Value of Assets Increase                                                                                             
// Column:RHO_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "rho_hedge_mkt_val_incr.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_mkt_val_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_pmt
// Rho Hedge Derivative Payment                                                                                             
// Column:RHO_HEDGE_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_prof
// Rho Hedge Profit                                                                                             
// Column:RHO_HEDGE_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_prof(int t) {
//^^^



//^^^

#line 1 "rho_hedge_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_sale_amt
// Rho Hedge Sale Amount                                                                                             
// Column:RHO_HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "rho_hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_sale_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - rho_hedge_transaction_cost
// Rho Hedge Transaction Cost                                                                                             
// Column:RHO_HEDGE_TRANSACTION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_rho_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "rho_hedge_transaction_cost.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("rho_hedge_transaction_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - risk_free_rate_no_sprd_aig
// Risk Free Rate with no AIG spread                                                                                             
// Column:RISK_FREE_RATE_NO_SPRD_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_risk_free_rate_no_sprd_aig(int t) {
//^^^



//^^^

#line 1 "risk_free_rate_no_sprd_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
if (t < start_period)
	return NO_AVG;

double risk_free_rate = rates->get_risk_free_rate_aig(t);

return risk_free_rate;

}


//@@ END

//@@ START - risk_free_rate_with_ic_uel_sprd_aig
// Risk Free Rate with Internal Capital UEL spread                                                                                             
// Column:RISK_FREE_RATE_WITH_IC_UEL_SPRD_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_risk_free_rate_with_ic_uel_sprd_aig(int t) {
//^^^



//^^^

#line 1 "risk_free_rate_with_ic_uel_sprd_aig.COMP_COMP.for"
// 20200228 MTC - Risk Free Rate with Internal Capital Spread
if (t < start_period)
	return NO_AVG;

double monthly_continuous_spread = disc_rate_sprd_ic_uel_aig / 12.0;

double monthly_continuous_risk_free_rate = log(1 + risk_free_rate_no_sprd_aig(t));

double risk_free_rate_with_spread = exp(monthly_continuous_risk_free_rate + monthly_continuous_spread) - 1.0;

return risk_free_rate_with_spread;

}


//@@ END

//@@ START - risk_free_rate_with_no_uel_sprd_aig
// Risk Free Rate with non-UEL AIG spread                                                                                             
// Column:RISK_FREE_RATE_WITH_NO_UEL_SPRD_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_risk_free_rate_with_no_uel_sprd_aig(int t) {
//^^^



//^^^

#line 1 "risk_free_rate_with_no_uel_sprd_aig.COMP_COMP.for"
// 20190411 MTC - AIG Discount Curve no UEL
if (t < start_period)
	return NO_AVG;

double monthly_continuous_spread = disc_rate_sprd_no_uel_aig / 12.0;

double monthly_continuous_risk_free_rate = log(1 + risk_free_rate_no_sprd_aig(t));

double risk_free_rate_with_spread = exp(monthly_continuous_risk_free_rate + monthly_continuous_spread) - 1.0;

return risk_free_rate_with_spread;

}


//@@ END

//@@ START - risk_free_rate_with_uel_sprd_aig
// Risk Free Rate with UEL AIG spread                                                                                             
// Column:RISK_FREE_RATE_WITH_UEL_SPRD_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_risk_free_rate_with_uel_sprd_aig(int t) {
//^^^



//^^^

#line 1 "risk_free_rate_with_uel_sprd_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
if (t < start_period)
	return NO_AVG;

double monthly_continuous_spread = disc_rate_sprd_uel_aig / 12.0;

double monthly_continuous_risk_free_rate = log(1 + risk_free_rate_no_sprd_aig(t));

double risk_free_rate_with_spread = exp(monthly_continuous_risk_free_rate + monthly_continuous_spread) - 1.0;

return risk_free_rate_with_spread;

}


//@@ END

//@@ START - sale_inc
// Sale Income                                                                                             
// Column:SALE_INC
//========================================================
double COMP_COMP_UDF::comp_comp_sale_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(519,"sale_inc",t);
}



//^^^

#line 1 "sale_inc.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("sale_inc", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_sched_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(520,"sched_prin_pmt",t);
}



//^^^

#line 1 "sched_prin_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("sched_prin_pmt", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - shldr_div
// Shareholder Dividend                                                                                             
// Column:SHLDR_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_shldr_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(521,"shldr_div",t);
}



//^^^

#line 1 "shldr_div.COMP_COMP.for"
if (pba_valn_flag || t <= start_period || t > final_period)
	return NO_AVG;

// force call distrib_earnings
distrib_earnings(t);

if (tcm_flag)
	return sum_over_segments("distribn", t, CORPORATE_SEGMENT);

return sum_over_segments("distribn", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double COMP_COMP_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.COMP_COMP.for"
#if 0 // START_EXTERNS
sowfinput company_state_of_world_financial_input;
sowfcols company_state_of_world_financial_input_cols;
sowfoutput company_state_of_world_financial_output;
int PVCLen = 18;
int PVCSigDig = 15;
int model_t_low;
int model_t_high;
int maximum_t_high_value;
int minimum_t_low_value;
#endif // END_EXTERNS

#if 0 // START_CLASS
// Financial state of world variables
double init_tax_bk_prof_ytd;
double init_tax_tgt_cap_ytd;
double init_tax_free_surp_ytd;
double init_taxable_inc_bk_prof_ytd;
double init_taxable_inc_tgt_cap_ytd;
double init_taxable_inc_free_surp_ytd;
double init_taxable_inc_carryfwd_avail;
double init_bk_prof_bef_tax_qtd;
double init_bk_prof_bef_tax_ytd;
double init_bk_prof_aft_tax_qtd;
double init_bk_prof_aft_tax_ytd;
double init_bk_prof_aft_tax_irr;
double init_distrib_earnings_irr;
double init_earnings_accum;
double init_tax_earnings_accum_ytd;
double init_taxable_inc_earnings_accum_ytd;
double init_undistrib_earnings;
double init_free_surp;
double init_gaap_inc_bef_tax_qtd;
double init_gaap_inc_bef_tax_ytd;
double init_gaap_inc_aft_tax_qtd;
double init_gaap_inc_aft_tax_ytd;
double init_asset_yld;
double init_asset_yld_less_dflt;
double init_asset_yld_less_dflt_inv;
typedef map <xstring, double, less<xstring> > crmap;
crmap comp_rates_map;
vector<string> disc_rates;
vector<string> segments;
vector <xstring> hedge_valn_shock_list;
vector <xstring> delta_gamma_hedge_shock_list;
vector <xstring> delta_gamma_hedge_index_list;
vector <xstring> rho_hedge_shock_list;
vector <xstring> rho_hedge_key_rate_list;
vector <xstring> vega_hedge_shock_list;
vector <xstring> vega_hedge_index_list;
vector <xstring> vega_hedge_index_term_list;
vector <xstring> vega_hedge_term_list;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
init_tax_bk_prof_ytd = 0.0;
init_tax_tgt_cap_ytd = 0.0;
init_tax_free_surp_ytd = 0.0;
init_taxable_inc_bk_prof_ytd = 0.0;
init_taxable_inc_tgt_cap_ytd = 0.0;
init_taxable_inc_free_surp_ytd = 0.0;
init_taxable_inc_carryfwd_avail = 0.0;
init_bk_prof_bef_tax_qtd = 0.0;
init_bk_prof_bef_tax_ytd = 0.0;
init_bk_prof_aft_tax_qtd = 0.0;
init_bk_prof_aft_tax_ytd = 0.0;
init_bk_prof_aft_tax_irr = 0.0;
init_distrib_earnings_irr = 0.0;
init_earnings_accum = 0.0;
init_tax_earnings_accum_ytd = 0.0;
init_taxable_inc_earnings_accum_ytd = 0.0;
init_undistrib_earnings = 0.0;
init_free_surp = 0.0;
init_gaap_inc_bef_tax_qtd = 0.0;
init_gaap_inc_bef_tax_ytd = 0.0;
init_gaap_inc_aft_tax_qtd = 0.0;
init_gaap_inc_aft_tax_ytd = 0.0;
init_asset_yld = 0.0;
init_asset_yld_less_dflt = 0.0;
init_asset_yld_less_dflt_inv = 0.0;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
company_state_of_world_financial_output.close();
#endif // END_TERMINATOR

model_t_low = t_low;
model_t_high = t_high;

// Input variables overwritten by read_state_of_world_financial
init_free_surp = init_free_surp_input;

if (isMainModel && independent_mp_defn == YES
	&& restore_variables_ind != 1)
	throw FatalError("The 'Assump Set Restore' property must be set equal to 'Yes' for independent model point processing.");

if (isMainModel 
	&& ((num_of_proj_task_loops == 0 || is_first_proj_task_loop)
	    || restore_variables_ind == 1))
	{
	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	log_screen.setf(ios::fixed);
	log_screen.precision(12);
	
	// Reinitialize string vectors for the case where restore_variables_ind == 1
	valn_periods.resize(0);
	disc_rates.resize(0);
	segments.resize(0);

	if (overall_num_of_proj_set_sub_loops > 0
		&& proj_set_sub_loop_num > 0
		&& time_step_defn == YES) // 20190208 WTW - Automation enhancement
		time_step_flag = true;

	// Initialize global calculation flags
	if (target_column.find("valn_tgt") < string::npos)
		{
		valn_flag = true;

		if (target_column.find("valn_tgt_gaap_sfas120") < string::npos
			|| target_column.find("valn_tgt_gaap_sfas91") < string::npos)
			last_proj_period = 1440; // must cater for projections to maturity for SFAS120 and SFAS91
		else if (target_column.find("valn_tgt_hedge_final") < string::npos)//hedge_valn_final_flag = true
			last_proj_period = last_model_period;//specific condition to allow for write_state_of_world_mp
		else
			last_proj_period = valn_yrs * 12;
		}
	else
		last_proj_period = last_model_period;

	if ((!valn_flag || time_step_flag) && pricing_defn == YES)
		nb_flag = true;

	if (assets_defn == YES)
		{
		alm_flag = true;
		stoch_flag = true;
		
		if (avr_defn == YES)
			avr_flag = true;
		
		if (imr_defn == YES)
			imr_flag = true;
		}

	if (tgt_cap_defn == YES)
		tgt_cap_flag = true;

	// Create segments vector
	if (segments_selected != "NONE")
		{
		split_string_usl(segments_selected.c_str(), segments, ",");//WTW - Gen2 - split_tring internal RAFM function

		// Create business segments
		sm_seg.resize(segments.size());

		// Add a corporate segment if required
		// Set lookup key
		sm_seg[0]->seg_id = segments[0];

		if (sm_seg.size() > 1
			|| fabs(sm_seg[0]->tgt_cap_pct_inv_in_seg - 1.0) > model_point_amount_threshold)
			{
			tcm_flag = true;

			sm_seg.resize(sm_seg.size() + 1);
			}
		
		#if defined(__FIA_LIAB_H_)
		if (alm_flag && target_column.find("valn_tgt_pba") < string::npos)
			{
			vm21_reinv_rate_flag = true;
			sm_seg.resize(sm_seg.size() + 1);
			}
		#endif

		if (alm_flag)
			sm_inv_strategy.resize(sm_seg.size());
		}

	// Initializing hedging valuation flags
	if (target_column.find("valn_tgt_hedge") < string::npos)
		{
		hedge_valn_flag = true;
		if (target_column.find("valn_tgt_hedge_shock") < string::npos)
			hedge_valn_shock_flag = true;
		else if (target_column.find("valn_tgt_hedge_final") < string::npos)
			hedge_valn_final_flag = true;

		// Setup the hedge valuation shock list
		setup_hedge_valn_shock_list();
		}

	// Initialize hedging projection flag
	if (target_column.find("proj_tgt_hedge_stmt") < string::npos)
		{
		hedge_proj_stmt_flag = true;
		
		// Setup the hedge projection shock list
		setup_hedge_proj_shock_lists();
		}

	// Initializing GAAP flags
	if (gaap_defn == YES
		|| target_column.find("valn_tgt_gaap") < string::npos)
		{
		gaap_flag = true;
		
		if (target_column.find("valn_tgt_gaap_sop031") < string::npos)
			sop031_valn_flag = true;	
		else if (target_column.find("valn_tgt_gaap_sfas97rd") < string::npos)
			sfas97rd_valn_flag = true;
		else if (target_column.find("valn_tgt_gaap_sfas91") < string::npos)
			sfas91_valn_flag = true;
		else if (target_column.find("valn_tgt_gaap_sfas120") < string::npos)
			sfas120_valn_flag = true;

		if (sfas97rd_valn_flag && num_of_proj_task_loops > 1)
			throw FatalError("SFAS97RD valuations are a single projection task loop process. Please correct your projection properties.");		
		}

    if (target_column.find("proxy_bond_generation") < string::npos)
    	{      					
         // Set Global Proxy Bond Generation flag
         proxy_bond_gen_flag = true;
         //Proxy Bond Process is a point in time valuation
         valn_flag = true;
         }             

	if (time_step_flag)
		{
		// Create inner loop valuation periods vector
		split_string_usl(valn_periods_selected.c_str(), valn_periods, ",", "-");//WTW - Gen2 - split_tring internal RAFM function
		
		if (valn_periods.size() < overall_num_of_proj_set_sub_loops)
			throw FatalError("Inner loop valuation period must be defined for each projection set sub loop.");
		
		valn_period = atoi(xstring(valn_periods[proj_set_sub_loop_num - 1]));

		if (!valn_flag || hedge_valn_final_flag)
			{
			// Run 1 period to ensure proj date balance sheet is produced
			if (proj_set_sub_loop_num == valn_periods.size())
				last_proj_period = 1;
			else
				last_proj_period = atoi(xstring(valn_periods[proj_set_sub_loop_num])) - valn_period;

			// throw error message if 'Proj Period To' setting is not long enough
			if (last_model_period < last_proj_period)
				{
				xstring message = xstring("'Proj Period To' projection task property must be set to be greater than ")
				                  + xstring(" or equal to ") + xstring(last_proj_period) + xstring(". Please correct your data.");		

				throw FatalError(message);
				}
			}
		}
	
	xstring force_scalar_calc_date = proj_date_adj;

	// Create discount rates vector
	if (disc_rates_selected != "NONE")
		split_string_usl(disc_rates_selected.c_str(), disc_rates, ",");//WTW - Gen2 - split_tring internal RAFM function

	// Determine whether the projection is stochastic or deterministic
	// Stochastic projection is always required for VA, FA, FIA, VUL, and IUL product types
	#if defined(__VA_LIAB_H_) || defined(__FA_LIAB_H_) || defined(__FIA_LIAB_H_) || defined(__VUL_LIAB_H_) || defined(__IUL_LIAB_H_)
	stoch_flag = true;
	#else 
	if (!alm_flag)
		{
		// Check for stochastic inflation rate
		if (rates->infl_defn == STOCHASTIC)
			stoch_flag = true;
		
		// Check for stochastic asset yield
		if (!stoch_flag)
			{
			for (int segment = 0; segment < sm_seg.size(); segment++)
				{
				if (segment < segments.size())
					sm_seg[segment]->seg_id = xstring(segments[segment]);
				else
					sm_seg[segment]->seg_id = "Corp";

				if (sm_seg[segment]->asset_yld_defn == STOCHASTIC || sm_seg[segment]->asset_yld_defn == AIG_BOND_PORTFOLIO) // 20190129 MTC - Refactor AIG Bond Portfolio
					{
					stoch_flag = true;
					break;
					}
				}
			}

		// Check for stochastic discount rates	
		if (!stoch_flag)
			{		
			for (int dr = 0; dr < disc_rates.size(); dr++)
				{
				// Set lookup key
				disc_rate_id = xstring(disc_rates[dr]);

				double scen_yr = disc_rate_scen_yr; 
				double mult = disc_rate_mult; 

				if (scen_yr > 0.0 && fabs(mult) > 0.0)
					{
					stoch_flag = true;
					break;	
					}
				}
			}
		} // if (!alm_flag)
	#endif
	} // if (first proj task loop)

return 1.0;

}


//@@ END

//@@ START - stat_claim_exp_res
// Statutory Claim Expense Reserve                                                                                             
// Column:STAT_CLAIM_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_claim_exp_res(int t) {
//^^^



//^^^

#line 1 "stat_claim_exp_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_claim_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_claim_exp_res_incr
// Statutory Claim Expense Reserve Increase                                                                                             
// Column:STAT_CLAIM_EXP_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_claim_exp_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(524,"stat_claim_exp_res_incr",t);
}



//^^^

#line 1 "stat_claim_exp_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_claim_exp_res(t)
       - stat_claim_exp_res(t - 1);

}


//@@ END

//@@ START - stat_claim_incurred
// Statutory Claim Incurred                                                                                             
// Column:STAT_CLAIM_INCURRED
//========================================================
double COMP_COMP_UDF::comp_comp_stat_claim_incurred(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(525,"stat_claim_incurred",t);
}



//^^^

#line 1 "stat_claim_incurred.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return claim_paid(t)
       + prem_waiver_benefits(t)
       + stat_claim_res(t)
	   + stat_prem_waiver_res(t)
       - stat_claim_res(t - 1)
	   - stat_prem_waiver_res(t - 1)
       + stat_claim_exp_res(t)
	   + stat_prem_waiver_exp_res(t)
       - stat_claim_exp_res(t - 1)
	   - stat_prem_waiver_exp_res(t - 1);

}


//@@ END

//@@ START - stat_claim_res
// Statutory Claim Reserve                                                                                             
// Column:STAT_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_claim_res(int t) {
//^^^



//^^^

#line 1 "stat_claim_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_claim_res_incr
// Statutory Claim Reserve Increase                                                                                             
// Column:STAT_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(527,"stat_claim_res_incr",t);
}



//^^^

#line 1 "stat_claim_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_claim_res(t)
       - stat_claim_res(t - 1);

}


//@@ END

//@@ START - stat_loading
// Statutory Loading                                                                                             
// Column:STAT_LOADING
//========================================================
double COMP_COMP_UDF::comp_comp_stat_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(528,"stat_loading",t);
}



//^^^

#line 1 "stat_loading.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("stat_loading", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_loading_incr
// Statutory Loading Increase                                                                                             
// Column:STAT_LOADING_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_loading_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(529,"stat_loading_incr",t);
}



//^^^

#line 1 "stat_loading_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return stat_loading(t)
	   - stat_loading(t - 1);

}


//@@ END

//@@ START - stat_prem_waiver_exp_res
// Statutory Premium Waiver Expense Reserve                                                                                             
// Column:STAT_PREM_WAIVER_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_prem_waiver_exp_res(int t) {
//^^^



//^^^

#line 1 "stat_prem_waiver_exp_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_prem_waiver_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_prem_waiver_exp_res_incr
// Statutory Premium Waiver Expense Reserve Increase                                                                                             
// Column:STAT_PREM_WAIVER_EXP_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_prem_waiver_exp_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(531,"stat_prem_waiver_exp_res_incr",t);
}



//^^^

#line 1 "stat_prem_waiver_exp_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_prem_waiver_exp_res(t) - stat_prem_waiver_exp_res(t - 1);

}


//@@ END

//@@ START - stat_prem_waiver_res
// Statutory Premium Waiver Reserve                                                                                             
// Column:STAT_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "stat_prem_waiver_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_prem_waiver_res_incr
// Statutory Premium Waiver Reserve Increase                                                                                             
// Column:STAT_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(533,"stat_prem_waiver_res_incr",t);
}



//^^^

#line 1 "stat_prem_waiver_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_prem_waiver_res(t) - stat_prem_waiver_res(t - 1);

}


//@@ END

//@@ START - stat_res
// Statutory Reserve                                                                                             
// Column:STAT_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(534,"stat_res",t);
}



//^^^

#line 1 "stat_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force call for reporting
double cash_val = this->cash_val(t);
double stat_res_mp = this->stat_res_mp(t);
double stat_res_excess = this->stat_res_excess(t);

return sum_over_segments("stat_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_carvm_base_aig
// Base Stat Res                                                                                             
// Column:STAT_RES_CARVM_BASE_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_carvm_base_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_carvm_base_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for Base Stat Res.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_carvm_base_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_carvm_wb_aig
// WB Stat Res                                                                                             
// Column:STAT_RES_CARVM_WB_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_carvm_wb_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_carvm_wb_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for WB Stat Res.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_carvm_wb_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_excess
// Statutory Excess Reserve                                                                                             
// Column:STAT_RES_EXCESS
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_excess(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(537,"stat_res_excess",t);
}



//^^^

#line 1 "stat_res_excess.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("stat_res_excess", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_incr
// Statutory Reserve Increase                                                                                             
// Column:STAT_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(538,"stat_res_incr",t);
}



//^^^

#line 1 "stat_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_res(t)
	   - stat_res(t - 1);

}


//@@ END

//@@ START - stat_res_mp
// Statutory Policy Reserve                                                                                             
// Column:STAT_RES_MP
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(539,"stat_res_mp",t);
}



//^^^

#line 1 "stat_res_mp.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("stat_res_mp", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_sa
// Statutory Reserve Separate Account                                                                                             
// Column:STAT_RES_SA
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(540,"stat_res_sa",t);
}



//^^^

#line 1 "stat_res_sa.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("stat_res_sa", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_sa_exp_allow
// Statutory Reserve Separate Account Expense Allowance                                                                                             
// Column:STAT_RES_SA_EXP_ALLOW
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_sa_exp_allow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(541,"stat_res_sa_exp_allow",t);
}



//^^^

#line 1 "stat_res_sa_exp_allow.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

// force calls
fund_val_sa(t);
stat_res_sa(t);

return sum_over_segments("stat_res_sa_exp_allow", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_xol_carvm_aig
// XOL Statutory Reserve                                                                                             
// Column:STAT_RES_XOL_CARVM_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_xol_carvm_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_xol_carvm_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for XOL statutory reserve.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_xol_carvm_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_xol_excess_res_aig
// XOL excess reserve                                                                                             
// Column:STAT_RES_XOL_EXCESS_RES_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_xol_excess_res_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_xol_excess_res_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for XOL excess reserve.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_xol_excess_res_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_xol_nb_eco_res_aig
// XOL new business economic reserve                                                                                             
// Column:STAT_RES_XOL_NB_ECO_RES_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_xol_nb_eco_res_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_xol_nb_eco_res_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for XOL new business economic reserve.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_xol_nb_eco_res_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_res_xol_pv_nb_ending_amount_aig
// PV of NB Ending XOL Amount                                                                                             
// Column:STAT_RES_XOL_PV_NB_ENDING_AMOUNT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_stat_res_xol_pv_nb_ending_amount_aig(int t) {
//^^^



//^^^

#line 1 "stat_res_xol_pv_nb_ending_amount_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for PV of NB Ending XOL Amount.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_res_xol_pv_nb_ending_amount_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_unearn_prem_res
// Statutory Unearned Premium Reserve                                                                                             
// Column:STAT_UNEARN_PREM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_stat_unearn_prem_res(int t) {
//^^^



//^^^

#line 1 "stat_unearn_prem_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("stat_unearn_prem_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - stat_unearn_prem_res_incr
// Statutory Unearned Premium Reserve Increase                                                                                             
// Column:STAT_UNEARN_PREM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_stat_unearn_prem_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(547,"stat_unearn_prem_res_incr",t);
}



//^^^

#line 1 "stat_unearn_prem_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_unearn_prem_res(t)
	   - stat_unearn_prem_res(t - 1);

}


//@@ END

//@@ START - surr_benefits
// Surrender Benefits                                                                                             
// Column:SURR_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(548,"surr_benefits",t);
}



//^^^

#line 1 "surr_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("surr_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax
// Tax                                                                                             
// Column:TAX
//========================================================
double COMP_COMP_UDF::comp_comp_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(549,"tax",t);
}



//^^^

#line 1 "tax.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_bk_prof(t)
       + tax_tgt_cap(t)
       + tax_free_surp(t);

}


//@@ END

//@@ START - tax_bef_sale
// Tax Before Sales                                                                                             
// Column:TAX_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(550,"tax_bef_sale",t);
}



//^^^

#line 1 "tax_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_bk_prof_bef_sale(t)
       + tax_tgt_cap_bef_sale(t)
       + tax_free_surp_bef_sale(t);

}


//@@ END

//@@ START - tax_bk_prof
// Tax on Book Profit                                                                                             
// Column:TAX_BK_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_tax_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(551,"tax_bk_prof",t);
}



//^^^

#line 1 "tax_bk_prof.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return tax_bk_prof_ytd(t);

return tax_bk_prof_ytd(t)
       - tax_bk_prof_ytd(t - 1);

}


//@@ END

//@@ START - tax_bk_prof_bef_sale
// Tax on Book Profit Before Sales                                                                                             
// Column:TAX_BK_PROF_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_bk_prof_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(552,"tax_bk_prof_bef_sale",t);
}



//^^^

#line 1 "tax_bk_prof_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return tax_bk_prof_ytd_bef_sale(t);

return tax_bk_prof_ytd_bef_sale(t)
       - tax_bk_prof_ytd(t - 1);

}


//@@ END

//@@ START - tax_bk_prof_ytd
// Tax on Book Profit Calendar Year to Date                                                                                             
// Column:TAX_BK_PROF_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_tax_bk_prof_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(553,"tax_bk_prof_ytd",t);
}



//^^^

#line 1 "tax_bk_prof_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_bk_prof_ytd;
		
	return NO_AVG;	
	}

if (!nb_flag || tax_loss_treatment == IMMEDIATE_LOSS_RECOGNITION)
	return taxable_inc_bk_prof_ytd(t) 
	       * tax_rate
	       + (realzd_cap_gain_res_ytd(t)
			  - reins_realzd_cap_gain_res_ytd(t)          
			  + realzd_cap_gain_undistrib_earnings_ytd(t))
	         * (tax_rate_cap_gain - tax_rate);

if (tax_loss_treatment == ZERO_TAX)
	return (taxable_inc_bk_prof_ytd(t)
	        - min(taxable_inc_bk_prof_ytd(t) + taxable_inc_tgt_cap_ytd(t), 0.0))
	       * tax_rate
	       + (realzd_cap_gain_res_ytd(t)
			  - reins_realzd_cap_gain_res_ytd(t)          
			  + realzd_cap_gain_undistrib_earnings_ytd(t))
	         * (tax_rate_cap_gain - tax_rate);

// tax_loss_treatment == TAX_LOSS_CARRYFORWARD	
return (taxable_inc_bk_prof_ytd(t) 
	    + taxable_inc_carryfwd_addn_ytd(t)
	    - taxable_inc_carryfwd_applied_ytd(t))
       * tax_rate
      + (realzd_cap_gain_res_ytd(t)
	     - reins_realzd_cap_gain_res_ytd(t)          
	     + realzd_cap_gain_undistrib_earnings_ytd(t))
 	   * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_bk_prof_ytd_bef_sale
// Tax on Book Profit Calendar Year to Date Before Sales                                                                                             
// Column:TAX_BK_PROF_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_bk_prof_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(554,"tax_bk_prof_ytd_bef_sale",t);
}



//^^^

#line 1 "tax_bk_prof_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return taxable_inc_bk_prof_ytd_bef_sale(t) 
       * tax_rate
       + (realzd_cap_gain_res_ytd_bef_sale(t)
          - reins_realzd_cap_gain_res_ytd_bef_sale(t)          
          + realzd_cap_gain_undistrib_earnings_ytd_bef_sale(t))
         * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_capzd_prem
// Tax Capitalized Premium                                                                                             
// Column:TAX_CAPZD_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_tax_capzd_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(555,"tax_capzd_prem",t);
}



//^^^

#line 1 "tax_capzd_prem.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_capzd_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_capzd_prem_amortzn
// Tax Capitalized Premium Amortization                                                                                             
// Column:TAX_CAPZD_PREM_AMORTZN
//========================================================
double COMP_COMP_UDF::comp_comp_tax_capzd_prem_amortzn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(556,"tax_capzd_prem_amortzn",t);
}



//^^^

#line 1 "tax_capzd_prem_amortzn.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_capzd_prem_amortzn", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_capzd_prem_unamortzd
// Tax Capitalized Premium Unamortized                                                                                             
// Column:TAX_CAPZD_PREM_UNAMORTZD
//========================================================
double COMP_COMP_UDF::comp_comp_tax_capzd_prem_unamortzd(int t) {
//^^^



//^^^

#line 1 "tax_capzd_prem_unamortzd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_capzd_prem_unamortzd", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_claim_exp_res
// Tax Claim Expense Reserve                                                                                             
// Column:TAX_CLAIM_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_claim_exp_res(int t) {
//^^^



//^^^

#line 1 "tax_claim_exp_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_claim_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_claim_res
// Tax Claim Reserve                                                                                             
// Column:TAX_CLAIM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_claim_res(int t) {
//^^^



//^^^

#line 1 "tax_claim_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_claim_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_claim_res_incr
// Tax Claim Reserve Increase                                                                                             
// Column:TAX_CLAIM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_claim_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(560,"tax_claim_res_incr",t);
}



//^^^

#line 1 "tax_claim_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_claim_res(t) - tax_claim_res(t - 1);

}


//@@ END

//@@ START - tax_deferred_net_prem
// Tax Deferred Net Premium                                                                                             
// Column:TAX_DEFERRED_NET_PREM
//========================================================
double COMP_COMP_UDF::comp_comp_tax_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(561,"tax_deferred_net_prem",t);
}



//^^^

#line 1 "tax_deferred_net_prem.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("tax_deferred_net_prem", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_div_liab
// Tax Dividend Liability                                                                                             
// Column:TAX_DIV_LIAB
//========================================================
double COMP_COMP_UDF::comp_comp_tax_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(562,"tax_div_liab",t);
}



//^^^

#line 1 "tax_div_liab.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;
	
return sum_over_segments("tax_div_liab", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_div_liab_incr
// Tax Dividend Liability Increase                                                                                             
// Column:TAX_DIV_LIAB_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_div_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(563,"tax_div_liab_incr",t);
}



//^^^

#line 1 "tax_div_liab_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
    	
return tax_div_liab(t) 
       - tax_div_liab(t - 1);

}


//@@ END

//@@ START - tax_earnings_accum
// Tax on Accumulated Earnings                                                                                             
// Column:TAX_EARNINGS_ACCUM
//========================================================
double COMP_COMP_UDF::comp_comp_tax_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(564,"tax_earnings_accum",t);
}



//^^^

#line 1 "tax_earnings_accum.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_earnings_accum_ytd(t);

return tax_earnings_accum_ytd(t)
       - tax_earnings_accum_ytd(t - 1);

}


//@@ END

//@@ START - tax_earnings_accum_ytd
// Tax on Accumulated Earnings Calendar Year to Date                                                                                             
// Column:TAX_EARNINGS_ACCUM_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_tax_earnings_accum_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(565,"tax_earnings_accum_ytd",t);
}



//^^^

#line 1 "tax_earnings_accum_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_earnings_accum_ytd;
		
	return NO_AVG;	
	}

return taxable_inc_earnings_accum_ytd(t) 
       * tax_rate;

}


//@@ END

//@@ START - tax_exempt_inc
// Tax Exempt Income                                                                                             
// Column:TAX_EXEMPT_INC
//========================================================
double COMP_COMP_UDF::comp_comp_tax_exempt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(566,"tax_exempt_inc",t);
}



//^^^

#line 1 "tax_exempt_inc.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_exempt_inc", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_exempt_inc_bk_prof
// Tax Exempt Income Book Profit                                                                                             
// Column:TAX_EXEMPT_INC_BK_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_tax_exempt_inc_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(567,"tax_exempt_inc_bk_prof",t);
}



//^^^

#line 1 "tax_exempt_inc_bk_prof.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_exempt_inc(t)
       - tax_exempt_inc_tgt_cap(t)
	   - tax_exempt_inc_free_surp(t);

}


//@@ END

//@@ START - tax_exempt_inc_free_surp
// Tax Exempt Income Free Surplus                                                                                             
// Column:TAX_EXEMPT_INC_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_tax_exempt_inc_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(568,"tax_exempt_inc_free_surp",t);
}



//^^^

#line 1 "tax_exempt_inc_free_surp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (fabs(inv_inc(t)) < rate_ratio_threshold)
	return NO_AVG;

return inv_inc_free_surp(t)
	   * tax_exempt_inc(t) / inv_inc(t);

}


//@@ END

//@@ START - tax_exempt_inc_tgt_cap
// Tax Exempt Income Target Capital                                                                                             
// Column:TAX_EXEMPT_INC_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_tax_exempt_inc_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(569,"tax_exempt_inc_tgt_cap",t);
}



//^^^

#line 1 "tax_exempt_inc_tgt_cap.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (fabs(inv_inc(t)) < rate_ratio_threshold)
	return NO_AVG;

return inv_inc_tgt_cap(t)
	   * tax_exempt_inc(t) / inv_inc(t);

}


//@@ END

//@@ START - tax_free_surp
// Tax on Free Surplus Income                                                                                             
// Column:TAX_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_tax_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(570,"tax_free_surp",t);
}



//^^^

#line 1 "tax_free_surp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_free_surp_ytd(t);

return tax_free_surp_ytd(t)
       - tax_free_surp_ytd(t - 1);

}


//@@ END

//@@ START - tax_free_surp_bef_sale
// Tax on Free Surplus Income Before Sales                                                                                             
// Column:TAX_FREE_SURP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_free_surp_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(571,"tax_free_surp_bef_sale",t);
}



//^^^

#line 1 "tax_free_surp_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_free_surp_ytd_bef_sale(t);

return tax_free_surp_ytd_bef_sale(t)
       - tax_free_surp_ytd(t - 1);

}


//@@ END

//@@ START - tax_free_surp_ytd
// Tax on Free Surplus Income Calendar Year to Date                                                                                             
// Column:TAX_FREE_SURP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_tax_free_surp_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(572,"tax_free_surp_ytd",t);
}



//^^^

#line 1 "tax_free_surp_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_free_surp_ytd;
		
	return NO_AVG;	
	}

return taxable_inc_free_surp_ytd(t) 
       * tax_rate
       + realzd_cap_gain_free_surp_ytd(t)
         * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_free_surp_ytd_bef_sale
// Tax on Free Surplus Income Calendar Year to Date Before Sales                                                                                             
// Column:TAX_FREE_SURP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_free_surp_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(573,"tax_free_surp_ytd_bef_sale",t);
}



//^^^

#line 1 "tax_free_surp_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return taxable_inc_free_surp_ytd_bef_sale(t) 
       * tax_rate
       + realzd_cap_gain_free_surp_ytd_bef_sale(t)
         * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_loading
// Tax Loading                                                                                             
// Column:TAX_LOADING
//========================================================
double COMP_COMP_UDF::comp_comp_tax_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(574,"tax_loading",t);
}



//^^^

#line 1 "tax_loading.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sum_over_segments("tax_loading", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_loading_incr
// Tax Loading Increase                                                                                             
// Column:TAX_LOADING_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_loading_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(575,"tax_loading_incr",t);
}



//^^^

#line 1 "tax_loading_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_loading(t) 
       - tax_loading(t - 1);

}


//@@ END

//@@ START - tax_prem_waiver_exp_res
// Tax Premium Waiver Expense Reserve                                                                                             
// Column:TAX_PREM_WAIVER_EXP_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_prem_waiver_exp_res(int t) {
//^^^



//^^^

#line 1 "tax_prem_waiver_exp_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_prem_waiver_exp_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_prem_waiver_res
// Tax Premium Waiver Reserve                                                                                             
// Column:TAX_PREM_WAIVER_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "tax_prem_waiver_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_prem_waiver_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_prem_waiver_res_incr
// Tax Premium Waiver Reserve Increase                                                                                             
// Column:TAX_PREM_WAIVER_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_prem_waiver_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(578,"tax_prem_waiver_res_incr",t);
}



//^^^

#line 1 "tax_prem_waiver_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_prem_waiver_res(t) - tax_prem_waiver_res(t - 1);

}


//@@ END

//@@ START - tax_res
// Tax Reserve                                                                                             
// Column:TAX_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(579,"tax_res",t);
}



//^^^

#line 1 "tax_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return sum_over_segments("tax_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_res_incr
// Tax Reserve Increase                                                                                             
// Column:TAX_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(580,"tax_res_incr",t);
}



//^^^

#line 1 "tax_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_res(t)
	   - tax_res(t - 1);

}


//@@ END

//@@ START - tax_tgt_cap
// Tax on Target Capital Income                                                                                             
// Column:TAX_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_tax_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(581,"tax_tgt_cap",t);
}



//^^^

#line 1 "tax_tgt_cap.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_tgt_cap_ytd(t);

return tax_tgt_cap_ytd(t)
       - tax_tgt_cap_ytd(t - 1);

}


//@@ END

//@@ START - tax_tgt_cap_bef_sale
// Tax on Target Capital Income Before Sale                                                                                             
// Column:TAX_TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(582,"tax_tgt_cap_bef_sale",t);
}



//^^^

#line 1 "tax_tgt_cap_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_tgt_cap_ytd_bef_sale(t);

return tax_tgt_cap_ytd_bef_sale(t)
       - tax_tgt_cap_ytd(t - 1);

}


//@@ END

//@@ START - tax_tgt_cap_ytd
// Tax on Target Capital Income Calendar Year to Date                                                                                             
// Column:TAX_TGT_CAP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_tax_tgt_cap_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(583,"tax_tgt_cap_ytd",t);
}



//^^^

#line 1 "tax_tgt_cap_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_tgt_cap_ytd;
		
	return NO_AVG;	
	}

return taxable_inc_tgt_cap_ytd(t) 
       * tax_rate
       + realzd_cap_gain_tgt_cap_ytd(t)
         * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_tgt_cap_ytd_bef_sale
// Tax on Target Capital Income Calendar Year to Date Before Sales                                                                                             
// Column:TAX_TGT_CAP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tax_tgt_cap_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(584,"tax_tgt_cap_ytd_bef_sale",t);
}



//^^^

#line 1 "tax_tgt_cap_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return taxable_inc_tgt_cap_ytd_bef_sale(t) 
       * tax_rate
       + realzd_cap_gain_tgt_cap_ytd_bef_sale(t)
         * (tax_rate_cap_gain - tax_rate);

}


//@@ END

//@@ START - tax_transfer_to_sa_net
// Tax Transfers to Separate Account Net                                                                                             
// Column:TAX_TRANSFER_TO_SA_NET
//========================================================
double COMP_COMP_UDF::comp_comp_tax_transfer_to_sa_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(585,"tax_transfer_to_sa_net",t);
}



//^^^

#line 1 "tax_transfer_to_sa_net.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_transfer_to_sa_net", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_unearn_prem_res
// Tax Unearned Premium Reserve                                                                                             
// Column:TAX_UNEARN_PREM_RES
//========================================================
double COMP_COMP_UDF::comp_comp_tax_unearn_prem_res(int t) {
//^^^



//^^^

#line 1 "tax_unearn_prem_res.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("tax_unearn_prem_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tax_unearn_prem_res_incr
// Tax Unearned Premium Reserve Increase                                                                                             
// Column:TAX_UNEARN_PREM_RES_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tax_unearn_prem_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(587,"tax_unearn_prem_res_incr",t);
}



//^^^

#line 1 "tax_unearn_prem_res_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return stat_unearn_prem_res(t)
	   - stat_unearn_prem_res(t - 1);

}


//@@ END

//@@ START - taxable_inc_addn
// Taxable Income Addition                                                                                             
// Column:TAXABLE_INC_ADDN
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_addn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(588,"taxable_inc_addn",t);
}



//^^^

#line 1 "taxable_inc_addn.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (tcm_flag)
	return taxable_inc_addn_unamortzd.AtTime(t - 1)
		   - taxable_inc_addn_unamortzd;

return sum_over_segments("taxable_inc_addn", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - taxable_inc_bk_prof
// Taxable Income Book Profit                                                                                             
// Column:TAXABLE_INC_BK_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(589,"taxable_inc_bk_prof",t);
}



//^^^

#line 1 "taxable_inc_bk_prof.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return prem_paid(t)
	   - reins_prem(t)
       + inv_fee_ref(t)
	   - reins_inv_fee_ref(t)
	   + div_applied(t)
	   - reins_div_applied(t)
	   + annuitzn_inc(t)
	   + reins_ea(t)
	   - reins_ea_chargeback(t) 
	   + reins_ref(t) 
	   + reins_modco_res_adj(t)
	   + deferred_gross_prem_incr(t)
	   - reins_deferred_gross_prem_incr(t)
       - tax_unearn_prem_res_incr(t)
	   + reins_tax_unearn_prem_res_incr(t)
	   + tax_capzd_prem(t) // This result is net of reinsurance
	   - tax_capzd_prem_amortzn(t) // This result is net of reinsurance
	   + direct_cash_flow_int(t)
       - reins_cash_flow_int(t)
       + pol_loan_inc(t)
       + inv_inc_res(t)
       - reins_inv_inc_res(t)
       + inv_inc_undistrib_earnings(t)
       + realzd_cap_gain_res(t)
       - reins_realzd_cap_gain_res(t) 
       + realzd_cap_gain_undistrib_earnings(t)
	   - dth_benefits(t)
       + reins_dth_benefits(t)
	   - ann_benefits_bom(t)
	   + reins_ann_benefits_bom(t)
	   - ann_benefits_eom(t)
	   + reins_ann_benefits_eom(t)
	   - endow_benefits(t)
	   + reins_endow_benefits(t)
	   - conversion_cost(t)
	   - maturity_benefits(t)
	   + reins_maturity_benefits(t)
	   - surr_benefits(t)	
	   + reins_surr_benefits(t)
       - withdrl_benefits(t)
	   + reins_withdrl_benefits(t)	
	   - claim_paid(t)
	   + reins_claim_paid(t)
	   - prem_waiver_benefits(t)
	   + reins_prem_waiver_benefits(t)
       - div_paid(t)
	   + reins_div_paid(t)
       - terminal_div(t)
	   + reins_terminal_div(t)
	   - tax_loading_incr(t)
	   + reins_tax_loading_incr(t)
       - tax_claim_res_incr(t)
	   - tax_prem_waiver_res_incr(t)
	   + reins_tax_claim_res_incr(t)
	   + reins_tax_prem_waiver_res_incr(t)
       - tax_res_incr(t)
       + reins_tax_res_incr(t)
	   + loc_asset_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   + reins_comm_reimb(t)	
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
	   + reins_prem_tax(t)
	   - loc_cost(t)
	   - tax_div_liab_incr(t)
	   + reins_tax_div_liab_incr(t)
       - reins_exp(t)
	   + reins_exp_reimb(t)
	   - hedge_cost(t)
       - tax_transfer_to_sa_net(t)
	   + taxable_inc_addn(t)
	   - tax_exempt_inc_bk_prof(t);

}


//@@ END

//@@ START - taxable_inc_bk_prof_bef_sale
// Taxable Income Book Profit Before Sales                                                                                             
// Column:TAXABLE_INC_BK_PROF_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(590,"taxable_inc_bk_prof_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_bk_prof_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return prem_paid(t)
	   - reins_prem(t)
       + inv_fee_ref(t)
	   - reins_inv_fee_ref(t)
	   + div_applied(t)
	   - reins_div_applied(t)
	   + annuitzn_inc(t)
	   + reins_ea(t)
	   - reins_ea_chargeback(t) 
	   + reins_ref(t) 
	   + reins_modco_res_adj(t)
	   + deferred_gross_prem_incr(t)
	   - reins_deferred_gross_prem_incr(t)
       - tax_unearn_prem_res_incr(t)
	   + reins_tax_unearn_prem_res_incr(t)
	   + tax_capzd_prem(t) // This result is net of reinsurance
	   - tax_capzd_prem_amortzn(t) // This result is net of reinsurance
	   + direct_cash_flow_int(t)
       - reins_cash_flow_int(t)
       + pol_loan_inc(t)
       + inv_inc_res(t)
       - reins_inv_inc_res(t)
       + inv_inc_undistrib_earnings(t)
       + realzd_cap_gain_res_bef_sale(t)
       - reins_realzd_cap_gain_res_bef_sale(t) 
       + realzd_cap_gain_undistrib_earnings_bef_sale(t)
	   - dth_benefits(t)
       + reins_dth_benefits(t)
	   - ann_benefits_bom(t)
	   + reins_ann_benefits_bom(t)
	   - ann_benefits_eom(t)
	   + reins_ann_benefits_eom(t)
	   - endow_benefits(t)
	   + reins_endow_benefits(t)
	   - conversion_cost(t)
	   - maturity_benefits(t)
	   + reins_maturity_benefits(t)
	   - surr_benefits(t)	
	   + reins_surr_benefits(t)
       - withdrl_benefits(t)
	   + reins_withdrl_benefits(t)
	   - claim_paid(t)
	   + reins_claim_paid(t)
	   - prem_waiver_benefits(t)
	   + reins_prem_waiver_benefits(t)
       - div_paid(t)
	   + reins_div_paid(t)
       - terminal_div(t)
	   + reins_terminal_div(t)
	   - tax_loading_incr(t)
	   + reins_tax_loading_incr(t)
       - tax_claim_res_incr(t)
	   - tax_prem_waiver_res_incr(t)
	   + reins_tax_claim_res_incr(t)
	   + reins_tax_prem_waiver_res_incr(t)
       - tax_res_incr(t)
       + reins_tax_res_incr(t)
	   + loc_asset_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   + reins_comm_reimb(t)
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
	   + reins_prem_tax(t)
   	   - loc_cost(t)
	   - tax_div_liab_incr(t)
	   + reins_tax_div_liab_incr(t)
       - reins_exp(t)
       + reins_exp_reimb(t)
       - hedge_cost_bef_sale(t)
       - transfer_to_sa_net(t)
	   + taxable_inc_addn(t)
	   - tax_exempt_inc_bk_prof(t);

}


//@@ END

//@@ START - taxable_inc_bk_prof_ytd
// Taxable Income Book Profit Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_BK_PROF_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(591,"taxable_inc_bk_prof_ytd",t);
}



//^^^

#line 1 "taxable_inc_bk_prof_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_bk_prof_ytd;
		
	return NO_AVG;	
	}

if (cal_mth(t) == 1)
	return taxable_inc_bk_prof(t);
  
return taxable_inc_bk_prof_ytd(t - 1) 
	   + taxable_inc_bk_prof(t);

}


//@@ END

//@@ START - taxable_inc_bk_prof_ytd_bef_sale
// Taxable Income Book Profit Calendar Year to Date Before Sales                                                                                             
// Column:TAXABLE_INC_BK_PROF_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(592,"taxable_inc_bk_prof_ytd_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_bk_prof_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return taxable_inc_bk_prof_bef_sale(t);
  
return taxable_inc_bk_prof_ytd(t - 1) 
	   + taxable_inc_bk_prof_bef_sale(t);

}


//@@ END

//@@ START - taxable_inc_carryfwd_addn_ytd
// Taxable Income Carry Forward Addition Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_CARRYFWD_ADDN_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_addn_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(593,"taxable_inc_carryfwd_addn_ytd",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_addn_ytd.COMP_COMP.for"
if (!nb_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD 
	|| t <= start_period || t > final_period)
	return NO_AVG;
	
return max(- taxable_inc_bk_prof_ytd(t) - taxable_inc_tgt_cap_ytd(t), 0.0);

}


//@@ END

//@@ START - taxable_inc_carryfwd_applied_ytd
// Taxable Income Carry Forward Applied Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_CARRYFWD_APPLIED_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_applied_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(594,"taxable_inc_carryfwd_applied_ytd",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_applied_ytd.COMP_COMP.for"
if (!nb_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD 
	|| t <= start_period || t > final_period)
	return NO_AVG;
	
return min(taxable_inc_carryfwd_avail(t - 1),
	       max(taxable_inc_bk_prof_ytd(t), 0.0));

}


//@@ END

//@@ START - taxable_inc_carryfwd_avail
// Taxable Income Carry Forward Available                                                                                             
// Column:TAXABLE_INC_CARRYFWD_AVAIL
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_avail(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(595,"taxable_inc_carryfwd_avail",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_avail.COMP_COMP.for"
if (!nb_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD 
	|| t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_carryfwd_avail;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 12)
	return taxable_inc_carryfwd_avail(t - 1)
	       - taxable_inc_carryfwd_applied_ytd(t)
	       + taxable_inc_carryfwd_addn_ytd(t);
  
return taxable_inc_carryfwd_avail(t - 1);

}


//@@ END

//@@ START - taxable_inc_earnings_accum
// Taxable Income Accumulated Earnings                                                                                             
// Column:TAXABLE_INC_EARNINGS_ACCUM
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(596,"taxable_inc_earnings_accum",t);
}



//^^^

#line 1 "taxable_inc_earnings_accum.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_earnings_accum(t);

}


//@@ END

//@@ START - taxable_inc_earnings_accum_ytd
// Taxable Income Accumulated Earnings Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_EARNINGS_ACCUM_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_earnings_accum_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(597,"taxable_inc_earnings_accum_ytd",t);
}



//^^^

#line 1 "taxable_inc_earnings_accum_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_earnings_accum_ytd;
		
	return NO_AVG;	
	}

if (cal_mth(t) == 1)
	return taxable_inc_earnings_accum(t);
  
return taxable_inc_earnings_accum_ytd(t - 1) 
	   + taxable_inc_earnings_accum(t);

}


//@@ END

//@@ START - taxable_inc_free_surp
// Taxable Income Free Surplus                                                                                             
// Column:TAXABLE_INC_FREE_SURP
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_free_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(598,"taxable_inc_free_surp",t);
}



//^^^

#line 1 "taxable_inc_free_surp.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_free_surp(t)
       - tax_exempt_inc_free_surp(t)
       + realzd_cap_gain_free_surp(t);

}


//@@ END

//@@ START - taxable_inc_free_surp_bef_sale
// Taxable Income Free Surplus Before Sales                                                                                             
// Column:TAXABLE_INC_FREE_SURP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(599,"taxable_inc_free_surp_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_free_surp_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_free_surp(t)
       - tax_exempt_inc_free_surp(t)
	   + realzd_cap_gain_free_surp_bef_sale(t);

}


//@@ END

//@@ START - taxable_inc_free_surp_ytd
// Taxable Income Free Surplus Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_FREE_SURP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(600,"taxable_inc_free_surp_ytd",t);
}



//^^^

#line 1 "taxable_inc_free_surp_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_free_surp_ytd;
		
	return NO_AVG;	
	}

if (cal_mth(t) == 1)
	return taxable_inc_free_surp(t);
  
return taxable_inc_free_surp_ytd(t - 1) 
	   + taxable_inc_free_surp(t);

}


//@@ END

//@@ START - taxable_inc_free_surp_ytd_bef_sale
// Taxable Income Free Surplus Calendar Year to Date Before Sales                                                                                             
// Column:TAXABLE_INC_FREE_SURP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(601,"taxable_inc_free_surp_ytd_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_free_surp_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return taxable_inc_free_surp_bef_sale(t);
  
return taxable_inc_free_surp_ytd(t - 1) 
	   + taxable_inc_free_surp_bef_sale(t);

}


//@@ END

//@@ START - taxable_inc_tgt_cap
// Taxable Income Target Capital                                                                                             
// Column:TAXABLE_INC_TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(602,"taxable_inc_tgt_cap",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_tgt_cap(t)
       - tax_exempt_inc_tgt_cap(t)
       + realzd_cap_gain_tgt_cap(t);

}


//@@ END

//@@ START - taxable_inc_tgt_cap_bef_sale
// Taxable Income Target Capital Before Sale                                                                                             
// Column:TAXABLE_INC_TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(603,"taxable_inc_tgt_cap_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_tgt_cap(t)
       - tax_exempt_inc_tgt_cap(t)
	   + realzd_cap_gain_tgt_cap_bef_sale(t);

}


//@@ END

//@@ START - taxable_inc_tgt_cap_ytd
// Taxable Income Target Capital Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_TGT_CAP_YTD
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(604,"taxable_inc_tgt_cap_ytd",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap_ytd.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_tgt_cap_ytd;
		
	return NO_AVG;	
	}

if (cal_mth(t) == 1)
	return taxable_inc_tgt_cap(t);
  
return taxable_inc_tgt_cap_ytd(t - 1) 
	   + taxable_inc_tgt_cap(t);

}


//@@ END

//@@ START - taxable_inc_tgt_cap_ytd_bef_sale
// Taxable Income Target Captial Calendar Year to Date Before Sales                                                                                             
// Column:TAXABLE_INC_TGT_CAP_YTD_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_ytd_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(605,"taxable_inc_tgt_cap_ytd_bef_sale",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap_ytd_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return taxable_inc_tgt_cap_bef_sale(t);
  
return taxable_inc_tgt_cap_ytd(t - 1) 
	   + taxable_inc_tgt_cap_bef_sale(t);

}


//@@ END

//@@ START - terminal_div
// Terminal Dividends                                                                                             
// Column:TERMINAL_DIV
//========================================================
double COMP_COMP_UDF::comp_comp_terminal_div(int t) {
//^^^



//^^^

#line 1 "terminal_div.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("terminal_div", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - tgt_cap
// Target Capital                                                                                             
// Column:TGT_CAP
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(607,"tgt_cap",t);
}



//^^^

#line 1 "tgt_cap.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return rbc(t) * tgt_cap_rbc_mult;

}


//@@ END

//@@ START - tgt_cap_bef_sale
// Target Capital Before Sales                                                                                             
// Column:TGT_CAP_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(608,"tgt_cap_bef_sale",t);
}



//^^^

#line 1 "tgt_cap_bef_sale.COMP_COMP.for"
if (!tgt_cap_flag || t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return rbc_bef_sale(t) * tgt_cap_rbc_mult;

}


//@@ END

//@@ START - tgt_cap_effect
// Target Capital Effect                                                                                             
// Column:TGT_CAP_EFFECT
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap_effect(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(609,"tgt_cap_effect",t);
}



//^^^

#line 1 "tgt_cap_effect.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return - tgt_cap_incr(t)
	   + inv_inc_tgt_cap(t)
	   + cap_gain_tgt_cap(t)
	   - imr_impact_tgt_cap(t)
	   - tax_tgt_cap(t);

}


//@@ END

//@@ START - tgt_cap_effect_bef_sale
// Target Capital Effect Before Sales                                                                                             
// Column:TGT_CAP_EFFECT_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap_effect_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(610,"tgt_cap_effect_bef_sale",t);
}



//^^^

#line 1 "tgt_cap_effect_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return - tgt_cap_incr_bef_sale(t)
	   + inv_inc_tgt_cap(t)
	   + cap_gain_tgt_cap_bef_sale(t)
	   - imr_impact_tgt_cap_bef_sale(t)
	   - tax_tgt_cap_bef_sale(t);

}


//@@ END

//@@ START - tgt_cap_incr
// Target Capital Increase                                                                                             
// Column:TGT_CAP_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(611,"tgt_cap_incr",t);
}



//^^^

#line 1 "tgt_cap_incr.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tgt_cap(t)
	   - tgt_cap(t - 1)
	   + avr_incr(t);

}


//@@ END

//@@ START - tgt_cap_incr_bef_sale
// Target Capital Increase Before Sales                                                                                             
// Column:TGT_CAP_INCR_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_tgt_cap_incr_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(612,"tgt_cap_incr_bef_sale",t);
}



//^^^

#line 1 "tgt_cap_incr_bef_sale.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tgt_cap_bef_sale(t) + avr_bef_sale(t)
       - (tgt_cap(t - 1) + avr(t - 1));

}


//@@ END

//@@ START - transfer_cash_flow_sa_bom
// Transfer Cash Flow Separate Account Beginning of Month                                                                                             
// Column:TRANSFER_CASH_FLOW_SA_BOM
//========================================================
double COMP_COMP_UDF::comp_comp_transfer_cash_flow_sa_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(613,"transfer_cash_flow_sa_bom",t);
}



//^^^

#line 1 "transfer_cash_flow_sa_bom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("transfer_cash_flow_sa_bom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - transfer_cash_flow_sa_eom
// Transfer Cash Flow Separate Account End of Month                                                                                             
// Column:TRANSFER_CASH_FLOW_SA_EOM
//========================================================
double COMP_COMP_UDF::comp_comp_transfer_cash_flow_sa_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(614,"transfer_cash_flow_sa_eom",t);
}



//^^^

#line 1 "transfer_cash_flow_sa_eom.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("transfer_cash_flow_sa_eom", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - transfer_to_sa_net
// Transfers to Separate Account Net                                                                                             
// Column:TRANSFER_TO_SA_NET
//========================================================
double COMP_COMP_UDF::comp_comp_transfer_to_sa_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(615,"transfer_to_sa_net",t);
}



//^^^

#line 1 "transfer_to_sa_net.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("transfer_to_sa_net", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - undistrib_earnings
// Undistributed Earnings                                                                                             
// Column:UNDISTRIB_EARNINGS
//========================================================
double COMP_COMP_UDF::comp_comp_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(616,"undistrib_earnings",t);
}



//^^^

#line 1 "undistrib_earnings.COMP_COMP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (nb_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		{
		return init_undistrib_earnings;
		}

	return NO_AVG;	
	}

if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY
        && xint(cal_mth(t)) % 3 == 0)
	|| prof_distribn_mode == MONTHLY)
	return NO_AVG;

return undistrib_earnings(t - 1)
	   + bk_prof_aft_tax(t)
	   - tgt_cap_incr(t)
	   + inv_inc_tgt_cap(t)
	   + cap_gain_tgt_cap(t)
	   - imr_impact_tgt_cap(t)
	   - tax_tgt_cap(t);
	
return NO_AVG;

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(617,"unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return unrealzd_cap_gain_incr_bef_sale(t)
       - unrealzd_cap_gain_released_on_sale(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr_bef_sale
// Unrealized Capital Gain Increase Before Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR_BEF_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_incr_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(618,"unrealzd_cap_gain_incr_bef_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr_bef_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("unrealzd_cap_gain_incr_bef_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released on Sale                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_released_on_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("unrealzd_cap_gain_released_on_sale", t, SUM_OVER_ALL);

}


//@@ END

//@@ START - valn_tgt_ag38_8d
// Valuation Target - Ag38 8D Reserve                                                                                             
// Column:VALN_TGT_AG38_8D
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_ag38_8d(int t) {
//^^^



//^^^

#line 1 "valn_tgt_ag38_8d.COMP_COMP.for"
if (!valn_flag)
	return NO_AVG;

if (t != 0)
	return NO_AVG;

return sum_over_segments("valn_tgt_ag38_8d", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_gaap_sfas120
// Valuation Target - GAAP SFAS 120                                                                                             
// Column:VALN_TGT_GAAP_SFAS120
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas120(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_sfas120.COMP_COMP.for"
if (!sfas120_valn_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_gaap_sfas120", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_gaap_sfas91
// Valuation Target - GAAP SFAS 91                                                                                             
// Column:VALN_TGT_GAAP_SFAS91
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas91(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_sfas91.COMP_COMP.for"
if (!sfas91_valn_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_gaap_sfas91", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_gaap_sfas97rd
// Valuation Target - GAAP SFAS 97 Retrospective Deposit                                                                                             
// Column:VALN_TGT_GAAP_SFAS97RD
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas97rd(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_sfas97rd.COMP_COMP.for"
if (!gaap_flag || !valn_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_gaap_sfas97rd", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_gaap_sop031
// Valuation Target - GAAP SOP 03-1                                                                                             
// Column:VALN_TGT_GAAP_SOP031
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sop031(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_sop031.COMP_COMP.for"
if (!gaap_flag || !valn_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_gaap_sop031", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_hedge_final
// Valuation Target - Hedging Final                                                                                             
// Column:VALN_TGT_HEDGE_FINAL
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_hedge_final(int t) {
//^^^



//^^^

#line 1 "valn_tgt_hedge_final.COMP_COMP.for"
if (!hedge_valn_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_hedge_final", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_hedge_shock
// Valuation Target - Hedging Shock                                                                                             
// Column:VALN_TGT_HEDGE_SHOCK
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_hedge_shock(int t) {
//^^^



//^^^

#line 1 "valn_tgt_hedge_shock.COMP_COMP.for"
if (!hedge_valn_flag && !hedge_valn_shock_flag)
	return NO_AVG;

if (t > start_period)
	return NO_AVG;

return sum_over_segments("valn_tgt_hedge_shock", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_pba_pol_res
// Valuation Target - PBA Policy Reserve                                                                                             
// Column:VALN_TGT_PBA_POL_RES
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_pba_pol_res(int t) {
//^^^



//^^^

#line 1 "valn_tgt_pba_pol_res.COMP_COMP.for"
if (!valn_flag)
	return NO_AVG;

if (t != 0)
	return NO_AVG;

return sum_over_segments("valn_tgt_pba_pol_res", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_pba_rbc_std_scen_step2
// Valuation Target - PBA RBC Standard Scenario Step 2                                                                                             
// Column:VALN_TGT_PBA_RBC_STD_SCEN_STEP2
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_pba_rbc_std_scen_step2(int t) {
//^^^



//^^^

#line 1 "valn_tgt_pba_rbc_std_scen_step2.COMP_COMP.for"
if (!valn_flag)
	return NO_AVG;

// a two step process is only available for point in time valuations
if (time_step_flag)
	return NO_AVG;

if (t != 0)
	return NO_AVG;

return sum_over_segments("valn_tgt_pba_rbc_std_scen_step2", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - valn_tgt_pba_scen_amt
// Valuation Target - PBA Scenario Amount                                                                                             
// Column:VALN_TGT_PBA_SCEN_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_valn_tgt_pba_scen_amt(int t) {
//^^^



//^^^

#line 1 "valn_tgt_pba_scen_amt.COMP_COMP.for"
if (!valn_flag)
	return NO_AVG;

if (t != 0)
	return NO_AVG;

return sum_over_segments("valn_tgt_pba_scen_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_inv_amt
// Vega Hedge Investment Amount                                                                                             
// Column:VEGA_HEDGE_INV_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_inv_amt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_inv_amt.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_inv_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_mkt_val
// Vega Hedge Market Value of Assets                                                                                             
// Column:VEGA_HEDGE_MKT_VAL
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "vega_hedge_mkt_val.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_mkt_val", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_mkt_val_incr
// Vega Hedge Market Value of Assets Increase                                                                                             
// Column:VEGA_HEDGE_MKT_VAL_INCR
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "vega_hedge_mkt_val_incr.COMP_COMP.for"
if (!alm_flag || t < start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_mkt_val_incr", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_pmt
// Vega Hedge Derivative Payment                                                                                             
// Column:VEGA_HEDGE_PMT
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_pmt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_pmt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_pmt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_prof
// Vega Hedge Profit                                                                                             
// Column:VEGA_HEDGE_PROF
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_prof(int t) {
//^^^



//^^^

#line 1 "vega_hedge_prof.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_prof", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_sale_amt
// Vega Hedge Sale Amount                                                                                             
// Column:VEGA_HEDGE_SALE_AMT
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "vega_hedge_sale_amt.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_sale_amt", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - vega_hedge_transaction_cost
// Vega Hedge Transaction Cost                                                                                             
// Column:VEGA_HEDGE_TRANSACTION_COST
//========================================================
double COMP_COMP_UDF::comp_comp_vega_hedge_transaction_cost(int t) {
//^^^



//^^^

#line 1 "vega_hedge_transaction_cost.COMP_COMP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("vega_hedge_transaction_cost", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - withdrl_benefits
// Withdrawal Benefits                                                                                             
// Column:WITHDRL_BENEFITS
//========================================================
double COMP_COMP_UDF::comp_comp_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(637,"withdrl_benefits",t);
}



//^^^

#line 1 "withdrl_benefits.COMP_COMP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("withdrl_benefits", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - xol_amount_aig
// XOL Amount                                                                                             
// Column:XOL_AMOUNT_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_xol_amount_aig(int t) {
//^^^



//^^^

#line 1 "xol_amount_aig.COMP_COMP.for"
//20230202 SJ: For XOL Deal, add a column for XOL Amount.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("xol_amount_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - xol_prem_aig
// XOL Prem Aig                                                                                             
// Column:XOL_PREM_AIG
//========================================================
double COMP_COMP_UDF::comp_comp_xol_prem_aig(int t) {
//^^^



//^^^

#line 1 "xol_prem_aig.COMP_COMP.for"
//20230127 SJ: For XOL Deal, add a column for XOL premium.
if (t <= start_period || t > final_period)
	return NO_AVG;

return sum_over_segments("xol_prem_aig", t, BUSINESS_SEGMENTS);

}


//@@ END

//@@ START - elapsed_mths_aig
// Months Since Projection Start At Projection Date                                                                                             
// Calculated Variable:ELAPSED_MTHS_AIG
//========================================================
int COMP_COMP_UDF::comp_comp_elapsed_mths_aig() {
//^^^


#line 1 "elapsed_mths_aig.COMP_COMP.for"
// 20180626 MTC - AIG Discount Curve
int proj_yr = get_yr_from_date(proj_date_adj);
int proj_mth = get_mth_from_date(proj_date_adj);

return xint(proj_yr - proj_start_yr) * 12 + (proj_mth - proj_start_mth + 1);

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int COMP_COMP_UDF::comp_comp_final_period() {
//^^^


#line 1 "final_period.COMP_COMP.for"
return last_proj_period;

}


//@@ END

//@@ START - prod_type_indicator
// Product Type Indicator                                                                                             
// Calculated Variable:PROD_TYPE_INDICATOR
//========================================================
int COMP_COMP_UDF::comp_comp_prod_type_indicator() {
//^^^


#line 1 "prod_type_indicator.COMP_COMP.for"
#if defined(__UL_LIAB_H_)
return 1;
#endif
#if defined(__VA_LIAB_H_)
return 2;
#endif
#if defined(__FA_LIAB_H_)
return 3;
#endif
#if defined(__FIA_LIAB_H_)
return 4;
#endif
#if defined(__TERM_LIAB_H_)
return 5;
#endif 
#if defined(__TRAD_LIAB_H_)
return 6;
#endif 
#if defined(__VUL_LIAB_H_)
return 7;
#endif 
#if defined(__IUL_LIAB_H_)
return 8;
#endif 
#if defined(__PA_LIAB_H_)
return 9;
#endif
#if defined(__LTC_LIAB_H_)
return 10;
#endif
#if defined(__DI_LIAB_H_)
return 11;
#endif

return 0;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring COMP_COMP_UDF::comp_comp_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.COMP_COMP.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int COMP_COMP_UDF::comp_comp_proj_start_date() {
//^^^


#line 1 "proj_start_date.COMP_COMP.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int COMP_COMP_UDF::comp_comp_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.COMP_COMP.for"
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
int COMP_COMP_UDF::comp_comp_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.COMP_COMP.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - reins_flag
// Reinsurance Flag                                                                                             
// Calculated Variable:REINS_FLAG
//========================================================
int COMP_COMP_UDF::comp_comp_reins_flag() {
//^^^


#line 1 "reins_flag.COMP_COMP.for"
for (int segment = 0; segment < sm_seg.size(); segment++)
	{	
	if (sm_seg[segment]->reins_flag)
		return 1;
	}	

return 0;

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int COMP_COMP_UDF::comp_comp_start_period() {
//^^^


#line 1 "start_period.COMP_COMP.for"
return 0;

}


//@@ END

//@@ START - state_of_world_financial_file_path
// State Of World Financial File Path                                                                                             
// Calculated Variable:STATE_OF_WORLD_FINANCIAL_FILE_PATH
//========================================================
xstring COMP_COMP_UDF::comp_comp_state_of_world_financial_file_path() {
//^^^


#line 1 "state_of_world_financial_file_path.COMP_COMP.for"
return "<*data*>";

}


//@@ END


#line 1 "avr_calc.COMP_COMP.for"                                                                                   
double COMP_COMP::avr_calc(int t, const xstring & sales_timing, const xstring & calc_type)
{
int cal_year_relative = cal_yr_relative(t);
double avr_curr_yr_realzd_cap_gains_bonds = 0;
double avr_curr_yr_realzd_cap_gains_mortgages = 0;
double avr_curr_yr_realzd_cap_gains_stock = 0;
double avr_curr_yr_realzd_cap_gains_other = 0;
double avr_max_res_bonds = 0;
double avr_max_res_mortgages = 0;
double avr_max_res_stock = 0;
double avr_max_res_other = 0;
double avr_basic_contribn_bonds = 0;
double avr_basic_contribn_mortgages = 0;
double avr_basic_contribn_stock = 0;
double avr_basic_contribn_other = 0;
double avr_res_obj_bonds = 0;
double avr_res_obj_mortgages = 0;
double avr_res_obj_stock = 0;
double avr_res_obj_other = 0;
double avr_unrealzd_cap_gains_stock = 0;
double avr_unrealzd_cap_gains_other = 0;
double effective_cap_gains_tax_rate = 0;

SEG_COMP *current_seg_element;
static double avr_bond = 0;
static double avr_mtg = 0;
static double avr_stock = 0;
static double avr_other = 0;
static int prior_t = -999;
static xstring prior_sales_timing = "None";

if (t == prior_t
	&& sales_timing == prior_sales_timing)
	{
	// If results already calculated for this time period and sales timing
	// return them, else initialize and perform avr calculations
	if (calc_type == "Bonds")
		return avr_bond;
	
	if (calc_type == "Mortgages")
		return avr_mtg;
		
	if (calc_type == "Stock")
		return avr_stock;
		
	if (calc_type == "Other")
		return avr_other;

	throw FatalError("Unrecognized calculation type passed to 'avr_calc'.");
	}		
else
	{
	avr_bond = 0;
	avr_mtg = 0;
	avr_stock = 0;
	avr_other = 0;

	prior_t = t;
	prior_sales_timing = sales_timing;
	}
	
if (sales_timing == "Before Sales")
	{
	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		current_seg_element = sm_seg[segment];

		avr_curr_yr_realzd_cap_gains_bonds
		+= current_seg_element->avr_components_bef_sale(t, 0);
	
		avr_curr_yr_realzd_cap_gains_mortgages
		+= current_seg_element->avr_components_bef_sale(t, 1);
	
		avr_curr_yr_realzd_cap_gains_stock
		+= current_seg_element->avr_components_bef_sale(t, 2);
	
		avr_curr_yr_realzd_cap_gains_other
		+= current_seg_element->avr_components_bef_sale(t, 3);
	
		avr_max_res_bonds
		+= current_seg_element->avr_components_bef_sale(t, 4);
	
		avr_max_res_mortgages
		+= current_seg_element->avr_components_bef_sale(t, 5);
	
		avr_max_res_stock
		+= current_seg_element->avr_components_bef_sale(t, 6);
	
		avr_max_res_other
		+= current_seg_element->avr_components_bef_sale(t, 7);
	
		avr_basic_contribn_bonds 
		+= current_seg_element->avr_components_bef_sale(t, 8);
	
		avr_basic_contribn_mortgages 
		+= current_seg_element->avr_components_bef_sale(t, 9);
	
		avr_basic_contribn_stock 
		+= current_seg_element->avr_components_bef_sale(t, 10);
	
		avr_basic_contribn_other 
		+= current_seg_element->avr_components_bef_sale(t, 11);
	
		avr_res_obj_bonds
		+= current_seg_element->avr_components_bef_sale(t, 12);
	
		avr_res_obj_mortgages
		+= current_seg_element->avr_components_bef_sale(t, 13);
	
		avr_res_obj_stock
		+= current_seg_element->avr_components_bef_sale(t, 14);
	
		avr_res_obj_other
		+= current_seg_element->avr_components_bef_sale(t, 15);
	
		avr_unrealzd_cap_gains_stock
		+= current_seg_element->avr_components_bef_sale(t, 16);
	
		avr_unrealzd_cap_gains_other
		+= current_seg_element->avr_components_bef_sale(t, 17);
		}

	effective_cap_gains_tax_rate
	= tax_rate_cap_gain;
	}
else
	{
	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		current_seg_element = sm_seg[segment];

		avr_curr_yr_realzd_cap_gains_bonds
		+= current_seg_element->avr_components(t, 0);
	
		avr_curr_yr_realzd_cap_gains_mortgages
		+= current_seg_element->avr_components(t, 1);
	
		avr_curr_yr_realzd_cap_gains_stock
		+= current_seg_element->avr_components(t, 2);
	
		avr_curr_yr_realzd_cap_gains_other
		+= current_seg_element->avr_components(t, 3);
	
		avr_max_res_bonds
		+= current_seg_element->avr_components(t, 4);
	
		avr_max_res_mortgages
		+= current_seg_element->avr_components(t, 5);
	
		avr_max_res_stock
		+= current_seg_element->avr_components(t, 6);
	
		avr_max_res_other
		+= current_seg_element->avr_components(t, 7);
	
		avr_basic_contribn_bonds 
		+= current_seg_element->avr_components(t, 8);
	
		avr_basic_contribn_mortgages 
		+= current_seg_element->avr_components(t, 9);
	
		avr_basic_contribn_stock 
		+= current_seg_element->avr_components(t, 10);
	
		avr_basic_contribn_other 
		+= current_seg_element->avr_components(t, 11);
	
		avr_res_obj_bonds
		+= current_seg_element->avr_components(t, 12);
	
		avr_res_obj_mortgages
		+= current_seg_element->avr_components(t, 13);
	
		avr_res_obj_stock
		+= current_seg_element->avr_components(t, 14);
	
		avr_res_obj_other
		+= current_seg_element->avr_components(t, 15);
	
		avr_unrealzd_cap_gains_stock
		+= current_seg_element->avr_components(t, 16);
	
		avr_unrealzd_cap_gains_other
		+= current_seg_element->avr_components(t, 17);
		}

	effective_cap_gains_tax_rate
	= tax_rate_cap_gain;
	}

// Calculate initial reserve
avr_bond
= avr_bond_bocy(t)
  + avr_curr_yr_realzd_cap_gains_bonds
    * (1.0 - effective_cap_gains_tax_rate)
  + avr_basic_contribn_bonds; 			     

avr_mtg
= avr_mtg_bocy(t)
   + avr_curr_yr_realzd_cap_gains_mortgages
     * (1.0 - effective_cap_gains_tax_rate)
   + avr_basic_contribn_mortgages; 			     

avr_stock
= avr_stock_bocy(t)
   + avr_curr_yr_realzd_cap_gains_stock
     * (1.0 - effective_cap_gains_tax_rate)
   + avr_unrealzd_cap_gains_stock
   - avr_unrealzd_cap_gain_eqt_bocy(t)
   + avr_basic_contribn_stock; 			     

avr_other
= avr_other_bocy(t)
   + avr_curr_yr_realzd_cap_gains_other
     * (1.0 - effective_cap_gains_tax_rate)
   + avr_unrealzd_cap_gains_other
   - avr_unrealzd_cap_gain_non_eqt_bocy(t)
   + avr_basic_contribn_other; 			     

// Calculate reserves before transfers.
// (Adjust initial reserve for reserve objective.)
double avr_res_bonds_contribn = 0;
double avr_res_mortgages_contribn = 0;
double avr_res_stock_contribn = 0;
double avr_res_other_contribn = 0;

avr_res_bonds_contribn
= avr_amortzn_sch
  * (avr_res_obj_bonds - avr_bond);

avr_res_mortgages_contribn
= avr_amortzn_sch
  * (avr_res_obj_mortgages - avr_mtg);

avr_res_stock_contribn
= avr_amortzn_sch
  * (avr_res_obj_stock - avr_stock);

avr_res_other_contribn
= avr_amortzn_sch
  * (avr_res_obj_other - avr_other);

avr_bond += avr_res_bonds_contribn;
avr_mtg += avr_res_mortgages_contribn;
avr_stock += avr_res_stock_contribn;
avr_other += avr_res_other_contribn;
	
// Handle sub-component reserve transfers.
// Handle transfers between bond and mortgage sub-components of default component.
// Handle transfers between stock and other sub-components of equity component.
double avr_res_excess_bonds = 0;
double avr_res_excess_mortgages = 0;
double avr_res_excess_stock = 0;
double avr_res_excess_other = 0;
double avr_trans_res_to_bonds = 0;
double avr_trans_res_to_mortgages = 0;
double avr_trans_res_to_stock = 0;
double avr_trans_res_to_other = 0;

avr_res_excess_bonds = max(0.0, avr_bond - avr_max_res_bonds);
avr_res_excess_mortgages = max(0.0, avr_mtg - avr_max_res_mortgages);
avr_res_excess_stock = max(0.0, avr_stock - avr_max_res_stock);
avr_res_excess_other = max(0.0, avr_other - avr_max_res_other);

if (avr_mtg > 0.0 && avr_bond < avr_max_res_bonds)
	avr_trans_res_to_bonds
	= min(avr_res_excess_mortgages,
	      avr_max_res_bonds - avr_bond); 

if (avr_bond > 0.0 && avr_mtg < avr_max_res_mortgages)
	avr_trans_res_to_mortgages
	= min(avr_res_excess_bonds,
	      avr_max_res_mortgages - avr_mtg); 

if (avr_other > 0.0 && avr_stock < avr_max_res_stock)
	avr_trans_res_to_stock
	= min(avr_res_excess_other,
	      avr_max_res_stock - avr_stock); 

if (avr_stock > 0.0 && avr_other < avr_max_res_other)
	avr_trans_res_to_other
	= min(avr_res_excess_stock,
	      avr_max_res_other - avr_other); 

// Update reserve
avr_bond += avr_trans_res_to_bonds - avr_trans_res_to_mortgages;
avr_mtg += avr_trans_res_to_mortgages - avr_trans_res_to_bonds;
avr_stock += avr_trans_res_to_stock - avr_trans_res_to_other;
avr_other += avr_trans_res_to_other - avr_trans_res_to_stock;

// Handle negative amount sub-component transfers
if (avr_neg_defn == NO)
	{
	avr_trans_res_to_bonds = 0;
	avr_trans_res_to_mortgages = 0;
	avr_trans_res_to_stock = 0;
	avr_trans_res_to_other = 0;
	double avr_bond_res_min = 0.5 * avr_bond;
	double avr_mtg_res_min = 0.5 * avr_mtg;
	double avr_stock_res_min = 0.5 * avr_stock;
	double avr_other_res_min = 0.5 * avr_other;

	if (avr_bond < 0.0 && avr_mtg > 0.0)
		avr_trans_res_to_mortgages
		= max(avr_bond, -avr_mtg_res_min);

	if (avr_mtg < 0.0 && avr_bond > 0.0)
		avr_trans_res_to_bonds
		= max(avr_mtg, -avr_bond_res_min);

	if (avr_stock < 0.0 && avr_other > 0.0)
		avr_trans_res_to_other
		= max(avr_stock, -avr_other_res_min);

	if (avr_other < 0.0 && avr_stock > 0.0)
		avr_trans_res_to_stock
		= max(avr_other, -avr_stock_res_min);

	// Update reserve
	avr_bond += avr_trans_res_to_bonds - avr_trans_res_to_mortgages;
	avr_mtg += avr_trans_res_to_mortgages - avr_trans_res_to_bonds;
	avr_stock += avr_trans_res_to_stock - avr_trans_res_to_other;
	avr_other += avr_trans_res_to_other - avr_trans_res_to_stock;
	}

// Recalc excess reserve
avr_res_excess_bonds = max(0.0, avr_bond - avr_max_res_bonds);
avr_res_excess_mortgages = max(0.0, avr_mtg - avr_max_res_mortgages);
avr_res_excess_stock = max(0.0, avr_stock - avr_max_res_stock);
avr_res_excess_other = max(0.0, avr_other - avr_max_res_other);

// Handle component reserve transfers.
// Handle transfers between default and equity components.
// Allocate Component Excess to the other Component up to its Maximum 
double avr_component_trans_res_to_bonds = 0;
double avr_component_trans_res_from_bonds = 0;
double avr_component_trans_res_to_mortgages = 0;
double avr_component_trans_res_from_mortgages = 0;
double avr_component_trans_res_to_stock = 0;
double avr_component_trans_res_from_stock = 0;
double avr_component_trans_res_to_other = 0;
double avr_component_trans_res_from_other = 0;

double avr_dflt_component_res_excess = avr_res_excess_bonds + avr_res_excess_mortgages;
double avr_eqt_component_res_excess = avr_res_excess_stock + avr_res_excess_other;
double avr_eqt_component_res_excess_ratio = 0.0;
double avr_dflt_component_res_excess_ratio = 0.0;

if (fabs(avr_max_res_bonds + avr_max_res_mortgages
    - avr_bond - avr_mtg) > aggregate_amount_threshold)
	avr_eqt_component_res_excess_ratio
	= (avr_max_res_bonds - avr_bond)
	  / (avr_max_res_bonds + avr_max_res_mortgages
	     - avr_bond - avr_mtg);

if (fabs(avr_max_res_stock + avr_max_res_other
         - avr_stock - avr_other) > aggregate_amount_threshold)
	avr_dflt_component_res_excess_ratio
	= (avr_max_res_stock - avr_stock)
	  / (avr_max_res_stock + avr_max_res_other
	     - avr_stock - avr_other);

if (avr_eqt_component_res_excess > 0.0)
	{
	avr_component_trans_res_to_bonds
	= max(0.0, min(avr_max_res_bonds - avr_bond,
				   avr_eqt_component_res_excess
				   * avr_eqt_component_res_excess_ratio));

	avr_component_trans_res_to_mortgages
	= max(0.0, min(avr_max_res_mortgages - avr_mtg,
				   avr_eqt_component_res_excess
		           * (1.0 - avr_eqt_component_res_excess_ratio)));

	avr_component_trans_res_from_stock
	= avr_res_excess_stock
	  * (avr_component_trans_res_to_bonds
	     + avr_component_trans_res_to_mortgages)
	  / avr_eqt_component_res_excess; 

	avr_component_trans_res_from_other
	= avr_res_excess_other
	  * (avr_component_trans_res_to_bonds
	     + avr_component_trans_res_to_mortgages)
	  / avr_eqt_component_res_excess; 
	}

if (avr_dflt_component_res_excess > 0.0)
	{
	avr_component_trans_res_to_stock 
	= max(0.0, min(avr_max_res_stock - avr_stock,
				   avr_dflt_component_res_excess
		           * avr_dflt_component_res_excess_ratio));

	avr_component_trans_res_to_other 
	= max(0.0, min(avr_max_res_other - avr_other,
	               avr_dflt_component_res_excess
		           * (1.0 - avr_dflt_component_res_excess_ratio)));

	avr_component_trans_res_from_bonds
	= avr_res_excess_bonds
	  * (avr_component_trans_res_to_stock
	     + avr_component_trans_res_to_other)
	  / avr_dflt_component_res_excess; 

	avr_component_trans_res_from_mortgages
	= avr_res_excess_mortgages
	  * (avr_component_trans_res_to_stock
	     + avr_component_trans_res_to_other)
	  / avr_dflt_component_res_excess; 
	}

// Update reserves
avr_bond += avr_component_trans_res_to_bonds - avr_component_trans_res_from_bonds;
avr_mtg += avr_component_trans_res_to_mortgages - avr_component_trans_res_from_mortgages;
avr_stock += avr_component_trans_res_to_stock - avr_component_trans_res_from_stock;
avr_other += avr_component_trans_res_to_other - avr_component_trans_res_from_other;

// Final reserves
double avr_res_min = -999999999.99;
if (avr_neg_defn == NO)
	avr_res_min = 0.0;

avr_bond = max(avr_res_min, min(avr_bond, avr_max_res_bonds));
avr_mtg = max(avr_res_min, min(avr_mtg, avr_max_res_mortgages));
avr_stock = max(avr_res_min, min(avr_stock, avr_max_res_stock));
avr_other = max(avr_res_min, min(avr_other, avr_max_res_other));

if (calc_type == "Bonds")
	return avr_bond;
	
if (calc_type == "Mortgages")
	return avr_mtg;
	
if (calc_type == "Stock")
	return avr_stock;
	
if (calc_type == "Other")
	return avr_other;
	
throw FatalError("Unrecognized calculation type passed to 'avr_calc'");
}



#line 1 "get_comp_rate.COMP_COMP.for"                                                                                   
double COMP_COMP::get_comp_rate(xstring cr_id, int t)
{
if (cr_id == "NONE" || t > final_period)
	return 0.0;

// Search for competitor rate and time in the map, if found, return
xstring map_index = cr_id + "_" + xstring(t);

if (comp_rates_map.find(map_index) != comp_rates_map.end())
	return comp_rates_map[map_index];

// else must develop competitor rate and store in the map

int counter = 0;
double comp_rate = 0.0;

// Set lookup key 
comp_rate_id = cr_id;

if (comp_rate_type == SINGLE)
	{
	// Lookup key is comp_rate_id, set by get_comp_rate function
	if (fabs(comp_rate_single_mult) < rate_ratio_threshold)
		comp_rate = comp_rate_single_addn;

	else if (comp_rate_single_scen_yr < rate_ratio_threshold)
		comp_rate = comp_rate_single_addn;

	if (!stoch_flag)
		{
		makeRunLogYellow();
		log_screen << "Warning. Competitor rate " << comp_rate_id
				   << " is linked to scenario rates which are not loaded for this deterministic projection;"
				   << " it has been set to zero." << MSG_ERROR;

		return 0.0;
		}

	if (comp_rate_single_avg_mths <= 1)
		comp_rate = rates->get_int_rate(t, "Govt", GET_YIELD_RATE, 
                                        comp_rate_single_scen_yr,
                                        0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	                * comp_rate_single_mult
	                + comp_rate_single_addn;
	else // if (comp_rate_single_avg_mths > 1)
		{
		comp_rate = 1.0;
			
		for (int counter = 0; counter < comp_rate_single_avg_mths; counter ++)
			{
			comp_rate *= (1.0 + rates->get_int_rate(t - counter, "Govt", GET_YIELD_RATE, 
			                                        comp_rate_single_scen_yr,
			                                        0, EFFECTIVE_ANNUAL, NO_SHIFT,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				                * comp_rate_single_mult
				                + comp_rate_single_addn);
			}

		comp_rate = pow(comp_rate, 1.0 / comp_rate_single_avg_mths) - 1.0;
		}
	}
else if (comp_rate_type == WEIGHTED)
	{
	// Must read all variables before comp_rate_id is overwritten by get_comp_rate
	double weight_1 = comp_rate_weighted_rate1_weight;
	double weight_2 = comp_rate_weighted_rate2_weight;
	double weight_3 = comp_rate_weighted_rate3_weight;
	xstring comp_rate_1_id = comp_rate_weighted_rate1_id;
	xstring comp_rate_2_id = comp_rate_weighted_rate2_id;
	xstring comp_rate_3_id = comp_rate_weighted_rate3_id;
	
	if (fabs(weight_1) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_1_id, t) * weight_1;
	
	if (fabs(weight_2) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_2_id, t) * weight_2;
	
	if (fabs(weight_3) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_3_id, t) * weight_3;
	}
else if (comp_rate_type == COMPARED)
	{
	// Must read all variables before comp_rate_id is overwritten by get_comp_rate
	StrEnum::EnumValue comparison_defn = comp_rate_compared_defn;
	xstring comp_rate_1_id = comp_rate_compared_rate1_id;
	xstring comp_rate_2_id = comp_rate_compared_rate2_id;
	xstring comp_rate_3_id = comp_rate_compared_rate3_id;

	if (comparison_defn == MAXIMUM_RATE)
		comp_rate = max(max(get_comp_rate(comp_rate_1_id, t), 
		                    get_comp_rate(comp_rate_2_id, t)),
                        get_comp_rate(comp_rate_3_id, t)); 			

	else // if (comparison_defn == MINIMUM_RATE)
		comp_rate = min(min(get_comp_rate(comp_rate_1_id, t),
		                    get_comp_rate(comp_rate_2_id, t)),
                        get_comp_rate(comp_rate_3_id, t));
	}
else // return an error code value
	return -999;

// store competitor rate and time in the map
comp_rates_map[map_index] = comp_rate;

return comp_rate;
}



#line 1 "irr_calc.COMP_COMP.for"                                                                                   
double COMP_COMP::irr_calc(const xstring &roi_type)
{

int period = 0;
int adj_begin = 1;
int ind_chk = 0;
double adj_pv_prof_1 = 0;
double adj_pv_prof_2 = 0;
double prof = 0;
double pv_prof = 0;
double pv_factor = 0;
double yld_factor = 0;
double roi_guess = 0.1;
double low_pv = 0;
double high_pv = 0;
double tgt_cap = 0.0;
double* bk_prof_aft_tax_for_pv = NULL;
double* bk_prof_aft_tax_irr = NULL;
double* distrib_earnings = NULL;
double* distrib_earnings_irr = NULL;
double* bef_tax_yld = NULL;
double* port_yld_aft_tax_irr = NULL;//WTW - Gen2 - conflicting name with model class column
double min_rate_mthly = -.318708; // Annual rate = -.99
double max_rate_mthly = .042086; // Annual rate = .64

bk_prof_aft_tax_for_pv = new double[last_proj_period + 1];
bk_prof_aft_tax_irr = new double[last_proj_period + 1];
distrib_earnings = new double[last_proj_period + 1];
distrib_earnings_irr = new double[last_proj_period + 1];
bef_tax_yld = new double[last_proj_period + 1];
port_yld_aft_tax_irr = new double[last_proj_period + 1];//WTW - Gen2 - conflicting name with model class column

// force call disc_rate_port_yld_defn_val
disc_rate_port_yld_defn_val(start_period + 1);

// initialize arrays
for (int i = 0; i < last_proj_period; i++)
	{
	bk_prof_aft_tax_for_pv[i] = 0.0;
	bk_prof_aft_tax_irr[i] = 0.0;
	distrib_earnings[i] = 0.0;
	distrib_earnings_irr[i] = 0.0;
	bef_tax_yld[i] = 0.0;
	port_yld_aft_tax_irr[i] = 0.0;//WTW - Gen2 - conflicting name with model class column
	}

// drive the calculations forward
tgt_cap = this->tgt_cap(0) + this->avr(0);

for (int tt = 1; tt <= last_proj_period; tt++)
	{
	bk_prof_aft_tax_for_pv[tt] = this->bk_prof_aft_tax_for_pv(tt);
	bk_prof_aft_tax_irr[tt] = this->bk_prof_aft_tax_irr(tt);
	distrib_earnings[tt] = this->distrib_earnings(tt);
	distrib_earnings_irr[tt] = this->distrib_earnings_irr(tt);
	bef_tax_yld[tt] = this->bef_tax_yld(tt);
	port_yld_aft_tax_irr[tt] = this->port_yld_aft_tax(tt);//WTW - Gen2 - conflicting name with model class column

	if (roi_type == "Without Target Capital")
		{
		if (bk_prof_aft_tax_irr[tt] >= 0.0
		    && tt < last_proj_period)	
			adj_begin++;
		}
	else
		{	
		if (distrib_earnings_irr[tt] >= 0.0
		    && tt < last_proj_period)	
			adj_begin++;
		}
	}

if (adj_begin == last_proj_period)
	return 0.0;

double low_roi = min_rate_mthly;
double high_roi = min_rate_mthly;
double last_roi_guess = min_rate_mthly;

for (period = last_proj_period; period > 0; period--)
	{
	if (roi_type == "Without Target Capital")
		{
		if (period > adj_begin)
			prof = bk_prof_aft_tax_for_pv[period];
	
		else if (period == adj_begin)
			prof = bk_prof_aft_tax_irr[period]; 
	
		else
			prof = 0.0;
		}
	else 
		{
		if (period > adj_begin)
			prof = distrib_earnings[period];
	
		else if (period == adj_begin)
			prof = distrib_earnings_irr[period]; 
	
		else
			prof = 0.0;
		}

	if (adj_pv_prof_1 + prof >= 0
		&& disc_rate_port_yld_defn == BEFORE_TAX)
		yld_factor
		= 1.0 / pow(1.0 + max(bef_tax_yld[period], -.99),
		           (1.0 / 12.0));

	else
		yld_factor
		= 1.0 / pow(1.0 + max(port_yld_aft_tax_irr[period], -.99),//WTW - Gen2 - conflicting name with model class column
		           (1.0 / 12.0));

	if (adj_pv_prof_2 + prof >= 0 || roi_type == "Standard")		//20210517 STW: add Dustin's code Change
		pv_factor 
		= 1.0 / (1.0 + roi_guess);

	else
		pv_factor
		= 1.0 / pow(1.0 + max(port_yld_aft_tax_irr[period], -.99),//WTW - Gen2 - conflicting name with model class column
		           (1.0 / 12.0));
		
	adj_pv_prof_1
	= (adj_pv_prof_1 + prof)
	  * yld_factor;			

	adj_pv_prof_2
	= (adj_pv_prof_2 + prof)
	  * pv_factor;
	  
	if (adj_pv_prof_2 > 0)
		ind_chk = 1;
		  
	} 
			
adj_pv_prof_2
-= max(tgt_cap, 0.0);			

if (adj_pv_prof_2 >= 0)
	{
	low_roi = roi_guess;
	low_pv = adj_pv_prof_2;
	}
else
	{			
	high_roi = roi_guess;
	high_pv = adj_pv_prof_2;
	}

last_roi_guess = roi_guess;
		
if (!ind_chk)
	roi_guess = last_roi_guess;

else if (ind_chk
         && low_roi > min_rate_mthly
         && high_roi > min_rate_mthly)
	roi_guess = max(min_rate_mthly,
	                high_roi 
	                - high_pv
	                  * (high_roi - low_roi)
	                  / (high_pv - low_pv)); 				

else if (ind_chk && low_roi == min_rate_mthly)
	roi_guess = (low_roi + high_roi) / 2.0;

else if (ind_chk && high_roi == min_rate_mthly)
	roi_guess = low_roi + max(max_rate_mthly, low_roi);			
						
while (fabs(roi_guess - last_roi_guess) > .00001
		&& (low_pv - high_pv) > .0000001)
	{		
	pv_prof = 0.0;

	for (period = last_proj_period; period >= adj_begin; period--)
		{
		if (roi_type == "Without Target Capital")
			{
			if (period > adj_begin)
				prof = bk_prof_aft_tax_for_pv[period];
		
			else if (period == adj_begin)
				prof = bk_prof_aft_tax_irr[period]; 
		
			else
				prof = 0.0;
			}
		else 
			{
			if (period > adj_begin)
				prof = distrib_earnings[period];
		
			else if (period == adj_begin)
				prof = distrib_earnings_irr[period]; 
		
			else
				prof = 0.0;
			}

		if (pv_prof + prof >= 0 || roi_type == "Standard")		//20210517 STW: add Dustin's code Change
			pv_factor
			= 1.0 / (1.0 + roi_guess);

		else
			pv_factor
			= 1.0 / pow(1.0 + max(port_yld_aft_tax_irr[period], - .99), (1.0 / 12.0));		//WTW - Gen2 - conflicting name with model class column	

		pv_prof
		= (pv_prof + prof) * pv_factor;		

		} 
	pv_prof
	-= max(tgt_cap, 0.0);

	if (1000000 * pv_prof > 0)
		{
		low_roi = roi_guess;
		low_pv = pv_prof;
		}
	else
		{	
		high_roi = roi_guess;
		high_pv = pv_prof;
		}

	last_roi_guess = roi_guess;
	
	if (low_roi > min_rate_mthly
	    && high_roi > min_rate_mthly
		&& (pow(1.0 + high_roi, 12.0) - pow(1.0 + low_roi, 12.0) < (0.1)))	
		roi_guess = max(min_rate_mthly,
		                high_roi 
		                - high_pv
		                  * (high_roi - low_roi)
		                  / (high_pv - low_pv)); 				

	else if (low_roi == min_rate_mthly
	         || (pow(1.0 + high_roi, 12.0) - pow(1.0 + low_roi, 12.0) > (0.1)))
		roi_guess = (low_roi + high_roi) / 2.0;

	else if (high_roi == min_rate_mthly)
		roi_guess = low_roi + max(max_rate_mthly, low_roi);			
	}

// delete arrays
delete [] bk_prof_aft_tax_for_pv;
delete [] bk_prof_aft_tax_irr;
delete [] distrib_earnings;
delete [] distrib_earnings_irr;
delete [] bef_tax_yld;
delete [] port_yld_aft_tax_irr;//WTW - Gen2 - conflicting name with model class column

bk_prof_aft_tax_for_pv = NULL;
bk_prof_aft_tax_irr = NULL;
distrib_earnings = NULL;
distrib_earnings_irr = NULL;
bef_tax_yld = NULL;
port_yld_aft_tax_irr = NULL;//WTW - Gen2 - conflicting name with model class column

if (ind_chk)
	return min(max(pow(1.0 + roi_guess, 12.0) - 1.0, -.9999), 99.9999);

return -.9999;
}



#line 1 "read_state_of_world_financial.COMP_COMP.for"                                                                                   
void COMP_COMP::read_state_of_world_financial(void)
{
// Create file_name
xstring state_of_world_financial_file
= replaceWildcards(state_of_world_financial_file_path
  + "company_state_of_world_financial_" + xstring(proj_set_loop_num)
  + "_" + xstring(proj_set_sub_loop_num) + ".csv");

string database_name = working_directory() + "comp_read_state_of_world_financial.db";
openDatabase(database_name);
string table_name = readCsvFile(state_of_world_financial_file.getStdStr());

xstring sql = (xstring)"SELECT * FROM " + table_name;

executeQuery(sql.getStdStr(), company_state_of_world_financial_input_cols, company_state_of_world_financial_input);
closeDatabase();
remove(database_name.c_str());

if (!company_state_of_world_financial_input_cols.size())
	{
	throw FatalError("Could not read Company State of World Financial File: " 
		              + state_of_world_financial_file + " "
		              + "Please check your data.");
	}

// Undistributed earnings and free surplus
if (!valn_flag)
	{
	init_undistrib_earnings = atof(company_state_of_world_financial_input[0][1].c_str());
	init_free_surp = atof(company_state_of_world_financial_input[0][2].c_str());
	}

// Year to date tax payments
if (!valn_flag)
	{
	init_tax_bk_prof_ytd = atof(company_state_of_world_financial_input[0][3].c_str());
	init_tax_tgt_cap_ytd = atof(company_state_of_world_financial_input[0][4].c_str());
	init_tax_free_surp_ytd = atof(company_state_of_world_financial_input[0][5].c_str());
	init_taxable_inc_bk_prof_ytd = atof(company_state_of_world_financial_input[0][6].c_str());
	init_taxable_inc_tgt_cap_ytd = atof(company_state_of_world_financial_input[0][7].c_str());
	init_taxable_inc_free_surp_ytd = atof(company_state_of_world_financial_input[0][8].c_str());
	init_taxable_inc_carryfwd_avail = atof(company_state_of_world_financial_input[0][9].c_str());
	}
	
// Cumulative Statutory Book Profits
if (!valn_flag)
	{
	init_bk_prof_bef_tax_qtd = atof(company_state_of_world_financial_input[0][10].c_str());
	init_bk_prof_bef_tax_ytd = atof(company_state_of_world_financial_input[0][11].c_str());
	init_bk_prof_aft_tax_qtd = atof(company_state_of_world_financial_input[0][12].c_str());
	init_bk_prof_aft_tax_ytd = atof(company_state_of_world_financial_input[0][13].c_str());
	init_bk_prof_aft_tax_irr = atof(company_state_of_world_financial_input[0][14].c_str());
	init_distrib_earnings_irr = atof(company_state_of_world_financial_input[0][15].c_str());
	init_earnings_accum = atof(company_state_of_world_financial_input[0][16].c_str());
	init_tax_earnings_accum_ytd = atof(company_state_of_world_financial_input[0][17].c_str());
	init_taxable_inc_earnings_accum_ytd = atof(company_state_of_world_financial_input[0][18].c_str());
	}


// Cumulative GAAP income items
if (gaap_flag && !valn_flag)
	{
	init_gaap_inc_bef_tax_qtd = atof(company_state_of_world_financial_input[0][19].c_str());
	init_gaap_inc_bef_tax_ytd = atof(company_state_of_world_financial_input[0][20].c_str());
	init_gaap_inc_aft_tax_qtd = atof(company_state_of_world_financial_input[0][21].c_str());
	init_gaap_inc_aft_tax_ytd = atof(company_state_of_world_financial_input[0][22].c_str());
	}

if (alm_flag)
	{
	init_asset_yld = atof(company_state_of_world_financial_input[0][23].c_str());
	init_asset_yld_less_dflt = atof(company_state_of_world_financial_input[0][24].c_str());
	init_asset_yld_less_dflt_inv = atof(company_state_of_world_financial_input[0][25].c_str());
	}

return;
}



#line 1 "setup_hedge_proj_shock_lists.COMP_COMP.for"                                                                                   
void COMP_COMP::setup_hedge_proj_shock_lists(void)
{
#if defined(__HDG_GRP_COMP_H_)
delta_gamma_hedge_shock_list.clear();
delta_gamma_hedge_index_list.clear();
rho_hedge_shock_list.clear();
rho_hedge_key_rate_list.clear();
vega_hedge_shock_list.clear();
vega_hedge_index_list.clear();
vega_hedge_term_list.clear();
vega_hedge_index_term_list.clear();

// This function needs to create 1 element of a hedge group for one segment in order
// to read the data for the hedging method and create the list of the shock calculations to run. 
HDG_GRP_COMP * current_hedge_grp;
sm_seg[0]->sm_hedge_grp.resize(1);
sm_seg[0]->sm_hedge_grp[0].resize(1);
current_hedge_grp = sm_seg[0]->sm_hedge_grp[0][0];

// Count the number of Shock IDs
double hedge_valn_control_count = 0.0;
ExtSrcValTable hedge_valn_control_tbl;
hedge_valn_control_count = GetRowKeyValuesCount(current_hedge_grp->eqt_price_shock_defn);
hedge_valn_control_tbl = GetRowKeyValues(current_hedge_grp->eqt_price_shock_defn);

// Start at row 1 since we have a blank row in the lookup grid
for (int row = 1; row < hedge_valn_control_count; row++)
	{
	xstring shock_string;
	
	// Set lookup key and perform lookups
	shock_string = hedge_valn_control_tbl[row][0].AsString();

	// Setup delta_hedge list via EqtPrice reference
	if (shock_string.find("EqtPrice") < string::npos)
		{
		delta_gamma_hedge_shock_list.push_back(shock_string);

		xstring index = shock_string(0, shock_string.find("EqtPrice"));
		if (find(delta_gamma_hedge_index_list.begin(), delta_gamma_hedge_index_list.end(), index) == delta_gamma_hedge_index_list.end())
			{
			if (index != "Parallel")
				delta_gamma_hedge_index_list.push_back(index);
			}
		}//End of Delta/Gamma Loop

	// Setup rho_hedge list via Int reference
	if (shock_string.find("IntRate") < string::npos)
		{
		rho_hedge_shock_list.push_back(shock_string);

		xstring key_rate = shock_string(0, shock_string.find("IntRate"));
		if (find(rho_hedge_key_rate_list.begin(), rho_hedge_key_rate_list.end(), key_rate) == rho_hedge_key_rate_list.end())
			{
			if (key_rate != "Parallel")
				rho_hedge_key_rate_list.push_back(key_rate);
			}
		}//End of Rho Loop

	// Setup vega_hedge list via EqtVol reference
	if (shock_string.find("EqtVol") < string::npos)
		{
		vega_hedge_shock_list.push_back(shock_string);

		xstring vol_index;
		xstring vol_term;
		xstring vol_index_term;
		
		if (shock_string.find("AllTerms") < string::npos)//AllTerms Shock
			{
			vol_index = shock_string(0, shock_string.find("EqtVol"));
			vol_index_term = vol_index + "EqtVolAllTerms";
			
			if (find(vega_hedge_index_list.begin(), vega_hedge_index_list.end(), vol_index) == vega_hedge_index_list.end())
				{
				if (vol_index != "Parallel")
					vega_hedge_index_list.push_back(vol_index);
				}
			if (find(vega_hedge_index_term_list.begin(), vega_hedge_index_term_list.end(), vol_index_term) == vega_hedge_index_term_list.end())
				vega_hedge_index_term_list.push_back(vol_index_term);		
			}
		else // Term Specific or Parallel Shock
			{
			vol_index = shock_string(0, shock_string.find("EqtVol"));

			int EqtVolPos = shock_string.find("EqtVol") + 6;
			
			if (shock_string.find("Up") < string::npos)//Up Shock
				{
				vol_term = shock_string(EqtVolPos,shock_string.find("Up")-EqtVolPos);
				vol_index_term = vol_index + "EqtVol" + vol_term;
				}
			else
				{
				vol_term = shock_string(EqtVolPos,shock_string.find("Down")-EqtVolPos);
				vol_index_term = vol_index + "EqtVol" + vol_term;
				}

			if (find(vega_hedge_term_list.begin(), vega_hedge_term_list.end(), vol_term) == vega_hedge_term_list.end())
				vega_hedge_term_list.push_back(vol_term);

			if (find(vega_hedge_index_list.begin(), vega_hedge_index_list.end(), vol_index) == vega_hedge_index_list.end())
				{
				if (vol_index != "Parallel")
					vega_hedge_index_list.push_back(vol_index);
				}

			if (find(vega_hedge_index_term_list.begin(), vega_hedge_index_term_list.end(), vol_index_term) == vega_hedge_index_term_list.end())
				vega_hedge_index_term_list.push_back(vol_index_term);					
			}
		}//End of Vega Loop
	}//End of hedge_valn_control_count loop

// Remove elements of hedge_grp which were created
sm_seg[0]->sm_hedge_grp[0].resize(0);
sm_seg[0]->sm_hedge_grp.resize(0);

#endif
return;
}



#line 1 "setup_hedge_valn_shock_list.COMP_COMP.for"                                                                                   
void COMP_COMP::setup_hedge_valn_shock_list(void)
{
#if defined(__HDG_GRP_COMP_H_)
hedge_valn_shock_list.clear();
double overall_proj_task_loops_to_run = overall_num_of_proj_task_loops;

// This function needs to create 1 element of a hedge group for one segment in order
// to read the data for the hedging method and create the list of the shock calculations to run. 
HDG_GRP_COMP * current_hedge_grp;
sm_seg[0]->sm_hedge_grp.resize(1);
sm_seg[0]->sm_hedge_grp[0].resize(1);
current_hedge_grp = sm_seg[0]->sm_hedge_grp[0][0];

// Count the number of Shock IDs
double hedge_valn_control_count = 0.0;
ExtSrcValTable hedge_valn_control_tbl;

hedge_valn_control_count = GetRowKeyValuesCount(current_hedge_grp->eqt_price_shock_defn);
hedge_valn_control_tbl = GetRowKeyValues(current_hedge_grp->eqt_price_shock_defn);

// Count the number of Scenarios
int scens_to_run = current_hedge_grp->valn_scens_to_run;

// Start at index 1 since we have a blank row in the lookup grid
for (int row = 1; row < hedge_valn_control_count; row++)
	{
	xstring shock_string;
	xstring shock_id;
	
	// Set lookup key and perform lookups
	shock_id = hedge_valn_control_tbl[row][0].AsString();
	shock_string = shock_id;
			
	if (hedge_valn_shock_flag)
		{
		//Build the list for each scenario
		for (int scen = 1; scen <= scens_to_run; scen++)
			{
			xstring shock_string_scen;
			shock_string_scen = shock_string + "|TaskLoopIncr-" + xstring(scen);

			hedge_valn_shock_list.push_back(shock_string_scen);
			}	
		}
	else
		hedge_valn_shock_list.push_back(shock_string);
	}

// Remove elements of hedge_grp which were created
sm_seg[0]->sm_hedge_grp[0].resize(0);
sm_seg[0]->sm_hedge_grp.resize(0);

if (hedge_valn_shock_flag)
	{
	if (hedge_valn_shock_list.size() < overall_proj_task_loops_to_run)
		{
		xstring message = xstring("Error: Number of specified projection task loops (") 
							+ xstring(overall_proj_task_loops_to_run) 
							+ xstring(") exceeds the requested shocks to run (")
							+ xstring(hedge_valn_shock_list.size())
							+ xstring("). Please correct your data.");

		throw FatalError(message);
		}
	}

// Setup the hedge_valn_shock_list in the rates submodel
rates->hedge_valn_shock_list.clear();
for (int i = 0; i < hedge_valn_shock_list.size(); i++)
	rates->hedge_valn_shock_list.push_back(hedge_valn_shock_list[i]);

#endif
return;
}



#line 1 "sum_over_segments.COMP_COMP.for"                                                                                   
double COMP_COMP::sum_over_segments(const xstring &colname, int t, int segment_type)
{ 
//  segment_type: SUM_OVER_ALL for all
//                CORPORATE_SEGMENT for corporate segment only
//                BUSINESS_SEGMENTS to exclude corporate segment

double total = 0.0;
int colnum = 0;

SEG_COMP *current_seg_element;
colnum = sm_seg[0]->Column(colname).Number();

if (t > 0)
	{
	asset_less_liab_and_surp(t - 1);

	if (!valn_flag)
		{
		inv_asset(t - 1);
		liab_and_surp(t - 1);
		}
	}

if (colnum >= 0)
	{ 
	for (int segment = 0; segment < sm_seg.size(); segment++)
		{
		current_seg_element = sm_seg[segment];
		
		if (current_seg_element->vm21_reinv_rate_seg_flag)
			continue;
		
		if (segment_type == CORPORATE_SEGMENT && current_seg_element->business_seg_flag)
			continue;
		
		if (segment_type == BUSINESS_SEGMENTS && current_seg_element->corp_seg_flag)
			continue;
		
		total += current_seg_element->Column(colnum).Value(t);
		}
	}

return total;
}



#line 1 "write_state_of_world_financial.COMP_COMP.for"                                                                                   
void COMP_COMP::write_state_of_world_financial(void)
{
if (proj_set_sub_loop_num == valn_periods.size())
	return;

// Create file_name
xstring state_of_world_financial_file
= replaceWildcards(state_of_world_financial_file_path
  + "company_state_of_world_financial_" + xstring(proj_set_loop_num)
  + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv");

static bool first_time = true;

if (first_time)
	{
	first_time = false;
	struct stat buffer;
	int stat_val;
	stat_val = stat(state_of_world_financial_file.c_str(), &buffer);

	// Delete existing file, to create fresh
	if (stat_val == 0)
		{
		xstring file_name 
		= state_of_world_financial_file_path
          + "company_state_of_world_financial_" + xstring(proj_set_loop_num)
          + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

		remove(file_name);
		}
	}
	
// Open state of world file and write header
if (!company_state_of_world_financial_output.is_open())
	{
	company_state_of_world_financial_output.open(state_of_world_financial_file);

	company_state_of_world_financial_output.setf(ios::fixed);
	company_state_of_world_financial_output.precision(12);

	// Write header
	company_state_of_world_financial_output // 22 columns
	<< "comp_id" << ","            
	<< "undistrib_earnings" << "," 
	<< "free_surp" << ","          
	<< "tax_bk_prof_ytd" << ","    
	<< "tax_tgt_cap_ytd" << ","    
	<< "tax_free_surp_ytd" << ","       
	<< "taxable_inc_bk_prof_ytd" << "," 
	<< "taxable_inc_tgt_cap_ytd" << "," 
	<< "taxable_inc_free_surp_ytd" << ","    
	<< "taxable_inc_carryfwd_avail" << ","   
	<< "bk_prof_bef_tax_qtd" << ","         
	<< "bk_prof_bef_tax_ytd" << ","         
	<< "bk_prof_aft_tax_qtd" << ","         
	<< "bk_prof_aft_tax_ytd" << ","         
	<< "bk_prof_aft_tax_irr" << ","         
	<< "distrib_earnings_irr" << ","
	<< "earnings_accum" << ","
	<< "tax_earnings_accum_ytd" << ","
	<< "taxable_inc_earnings_accum_ytd" << ","          
	<< "gaap_inc_bef_tax_qtd" << ","        
	<< "gaap_inc_bef_tax_ytd" << ","        
	<< "gaap_inc_aft_tax_qtd" << ","        
	<< "gaap_inc_aft_tax_ytd" << ","        
	<< "asset_yld" << ","           
	<< "asset_yld_less_dflt" << "," 
	<< "asset_yld_less_dflt_inv" << endl;  
	}

xstring comp_id = "company";
double undistrib_earnings = 0.0;
double free_surp = 0.0;
double tax_bk_prof_ytd = 0.0;
double tax_tgt_cap_ytd = 0.0;
double tax_free_surp_ytd = 0.0;
double taxable_inc_bk_prof_ytd = 0.0;
double taxable_inc_tgt_cap_ytd = 0.0;
double taxable_inc_free_surp_ytd = 0.0;
double taxable_inc_carryfwd_avail = 0.0;
double bk_prof_bef_tax_qtd = 0.0;
double bk_prof_bef_tax_ytd = 0.0;
double bk_prof_aft_tax_qtd = 0.0;
double bk_prof_aft_tax_ytd = 0.0;
double bk_prof_aft_tax_irr = 0.0;
double distrib_earnings_irr = 0.0;
double earnings_accum = 0.0;
double tax_earnings_accum_ytd = 0.0;
double taxable_inc_earnings_accum_ytd = 0.0;
double gaap_inc_bef_tax_qtd = 0.0;
double gaap_inc_aft_tax_qtd = 0.0;
double gaap_inc_bef_tax_ytd = 0.0;
double gaap_inc_aft_tax_ytd = 0.0;
double asset_yld = 0.0;
double asset_yld_less_dflt = 0.0;
double asset_yld_less_dflt_inv = 0.0;

if (cal_mth(final_period) != 12)
	{
	tax_bk_prof_ytd = this->tax_bk_prof_ytd(final_period);
	tax_tgt_cap_ytd = this->tax_tgt_cap_ytd(final_period);
	tax_free_surp_ytd = this->tax_free_surp_ytd(final_period);
	taxable_inc_bk_prof_ytd = this->taxable_inc_bk_prof_ytd(final_period);
	taxable_inc_tgt_cap_ytd = this->taxable_inc_tgt_cap_ytd(final_period);
	taxable_inc_free_surp_ytd = this->taxable_inc_free_surp_ytd(final_period);
	tax_earnings_accum_ytd = this->tax_earnings_accum_ytd(final_period);
	taxable_inc_earnings_accum_ytd = this->taxable_inc_earnings_accum_ytd(final_period);
	}	

free_surp = this->free_surp(final_period);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(final_period)) % 3 != 0))
	{
	bk_prof_bef_tax_qtd = this->bk_prof_bef_tax_qtd(final_period);
	bk_prof_aft_tax_qtd = this->bk_prof_aft_tax_qtd(final_period);
	undistrib_earnings = this->undistrib_earnings(final_period);

	if (gaap_flag)
		{
		gaap_inc_bef_tax_qtd = this->gaap_inc_bef_tax_qtd(final_period);
		gaap_inc_aft_tax_qtd = this->gaap_inc_aft_tax_qtd(final_period);
		}
	}	

if (prof_distribn_mode == ANNUAL
	&& (cal_mth(final_period) != 12))
	{
	bk_prof_bef_tax_ytd = this->bk_prof_bef_tax_ytd(final_period);
	bk_prof_aft_tax_ytd = this->bk_prof_aft_tax_ytd(final_period);
	undistrib_earnings = this->undistrib_earnings(final_period);

	if (gaap_flag)
		{
		gaap_inc_bef_tax_ytd = this->gaap_inc_bef_tax_ytd(final_period);
		gaap_inc_aft_tax_ytd = this->gaap_inc_aft_tax_ytd(final_period);
		}
	}

if (nb_flag)
	{
	bk_prof_aft_tax_irr = this->bk_prof_aft_tax_irr(final_period);
	distrib_earnings_irr = this->distrib_earnings_irr(final_period);
	earnings_accum = this->earnings_accum(final_period);

	if (tax_loss_treatment == TAX_LOSS_CARRYFORWARD)
		taxable_inc_carryfwd_avail = this->taxable_inc_carryfwd_avail(final_period);
	}

if (alm_flag)
	{
	asset_yld = this->asset_yld(final_period);
	asset_yld_less_dflt = this->asset_yld_less_dflt(final_period);
	asset_yld_less_dflt_inv = this->asset_yld_less_dflt_inv(final_period);
	}

// Write information to CSV file
company_state_of_world_financial_output 
<< comp_id << ","
<< undistrib_earnings << ","
<< free_surp << ","
<< tax_bk_prof_ytd << ","
<< tax_tgt_cap_ytd << ","
<< tax_free_surp_ytd << ","
<< taxable_inc_bk_prof_ytd << ","
<< taxable_inc_tgt_cap_ytd << ","
<< taxable_inc_free_surp_ytd << ","
<< taxable_inc_carryfwd_avail << ","
<< bk_prof_bef_tax_qtd << ","
<< bk_prof_bef_tax_ytd << ","
<< bk_prof_aft_tax_qtd << ","
<< bk_prof_aft_tax_ytd << ","
<< bk_prof_aft_tax_irr << ","
<< distrib_earnings_irr << ","
<< earnings_accum << ","
<< tax_earnings_accum_ytd << ","
<< taxable_inc_earnings_accum_ytd << ","
<< gaap_inc_bef_tax_qtd << ","
<< gaap_inc_bef_tax_ytd << ","
<< gaap_inc_aft_tax_qtd << ","
<< gaap_inc_aft_tax_ytd << ","
<< asset_yld << ","
<< asset_yld_less_dflt << ","
<< asset_yld_less_dflt_inv << endl;

return;
}



void COMP_COMP::Terminator()
{

company_state_of_world_financial_output.close();

}

FunctionPtr COMP_COMP::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static COMP_COMP_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (COMP_COMP_UDF::*dPXi) (int);
typedef double (COMP_COMP_UDF::*dPXid) (int, double);
typedef double (COMP_COMP_UDF::*dPF) ();
typedef double (COMP_COMP_UDF::*dPFd) (double);
typedef int (COMP_COMP_UDF::*iPF) ();
typedef int (COMP_COMP_UDF::*iPFi) (int);
typedef xstring (COMP_COMP_UDF::*sPF) ();
typedef xstring (COMP_COMP_UDF::*sPFs) (xstring);

const CashFlowCommonData COMP_COMP::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_inc", "comp_comp_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_accr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(2, "accr_inc_inv", "comp_comp_accr_inc_inv",  "accr_inc_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_accr_inc_inv, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc_inv),
	CashFlowCommonData(3, "accr_int", "comp_comp_accr_int",  "accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int),
	CashFlowCommonData(4, "accr_int_aft_dflt", "comp_comp_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_accr_int_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(5, "accr_int_dflt", "comp_comp_accr_int_dflt",  "accr_int_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_accr_int_dflt, 'E','Y', '3', 'P', (size_t)&modelOffset->accr_int_dflt),
	CashFlowCommonData(6, "acq_exp", "comp_comp_acq_exp",  "acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->acq_exp),
	CashFlowCommonData(7, "ann_benefits_bom", "comp_comp_ann_benefits_bom",  "ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_ann_benefits_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->ann_benefits_bom),
	CashFlowCommonData(8, "ann_benefits_eom", "comp_comp_ann_benefits_eom",  "ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->ann_benefits_eom),
	CashFlowCommonData(9, "annuitzn_consideration", "comp_comp_annuitzn_consideration",  "annuitzn_consideration",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_annuitzn_consideration, 'E','Y', '3', 'P', (size_t)&modelOffset->annuitzn_consideration),
	CashFlowCommonData(10, "annuitzn_count_aig", "comp_comp_annuitzn_count_aig",  "annuitzn_count_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_annuitzn_count_aig, 'E','N', '3', 'C', (size_t)&modelOffset->annuitzn_count_aig),
	CashFlowCommonData(11, "annuitzn_inc", "comp_comp_annuitzn_inc",  "annuitzn_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_annuitzn_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->annuitzn_inc),
	CashFlowCommonData(12, "annuitzn_val_released", "comp_comp_annuitzn_val_released",  "annuitzn_val_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_annuitzn_val_released, 'E','Y', '3', 'P', (size_t)&modelOffset->annuitzn_val_released),
	CashFlowCommonData(13, "asset_cash_flow", "comp_comp_asset_cash_flow",  "asset_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_cash_flow, 'M','Y', '3', 'C', (size_t)&modelOffset->asset_cash_flow),
	CashFlowCommonData(14, "asset_cash_flow_bef_inv", "comp_comp_asset_cash_flow_bef_inv",  "asset_cash_flow_bef_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_cash_flow_bef_inv, 'M','Y', '3', 'C', (size_t)&modelOffset->asset_cash_flow_bef_inv),
	CashFlowCommonData(15, "asset_cash_flow_bef_sale", "comp_comp_asset_cash_flow_bef_sale",  "asset_cash_flow_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_cash_flow_bef_sale, 'M','Y', '3', 'C', (size_t)&modelOffset->asset_cash_flow_bef_sale),
	CashFlowCommonData(16, "asset_less_liab_and_surp", "comp_comp_asset_less_liab_and_surp",  "asset_less_liab_and_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_less_liab_and_surp, 'E','N', '3', 'C', (size_t)&modelOffset->asset_less_liab_and_surp),
	CashFlowCommonData(17, "asset_sa", "comp_comp_asset_sa",  "asset_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_sa, 'E','N', '3', 'C', (size_t)&modelOffset->asset_sa),
	CashFlowCommonData(18, "asset_yld", "comp_comp_asset_yld",  "asset_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld),
	CashFlowCommonData(19, "asset_yld_denom", "comp_comp_asset_yld_denom",  "asset_yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_denom),
	CashFlowCommonData(20, "asset_yld_denom_inv", "comp_comp_asset_yld_denom_inv",  "asset_yld_denom_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_denom_inv, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_denom_inv),
	CashFlowCommonData(21, "asset_yld_inv", "comp_comp_asset_yld_inv",  "asset_yld_inv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_inv, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_inv),
	CashFlowCommonData(22, "asset_yld_inv_adj_aig", "comp_comp_asset_yld_inv_adj_aig",  "asset_yld_inv_adj_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_inv_adj_aig, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_inv_adj_aig),
	CashFlowCommonData(23, "asset_yld_less_dflt", "comp_comp_asset_yld_less_dflt",  "asset_yld_less_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_less_dflt, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_less_dflt),
	CashFlowCommonData(24, "asset_yld_less_dflt_inv", "comp_comp_asset_yld_less_dflt_inv",  "asset_yld_less_dflt_inv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_inv, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_less_dflt_inv),
	CashFlowCommonData(25, "asset_yld_less_dflt_numer", "comp_comp_asset_yld_less_dflt_numer",  "asset_yld_less_dflt_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_numer, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_less_dflt_numer),
	CashFlowCommonData(26, "asset_yld_less_dflt_numer_inv", "comp_comp_asset_yld_less_dflt_numer_inv",  "asset_yld_less_dflt_numer_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_less_dflt_numer_inv, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_less_dflt_numer_inv),
	CashFlowCommonData(27, "asset_yld_numer", "comp_comp_asset_yld_numer",  "asset_yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_numer, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_numer),
	CashFlowCommonData(28, "asset_yld_numer_inv", "comp_comp_asset_yld_numer_inv",  "asset_yld_numer_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_numer_inv, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_numer_inv),
	CashFlowCommonData(29, "asset_yld_vm21_reinv_rate", "comp_comp_asset_yld_vm21_reinv_rate",  "asset_yld_vm21_reinv_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_asset_yld_vm21_reinv_rate, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_yld_vm21_reinv_rate),
	CashFlowCommonData(30, "avr", "comp_comp_avr",  "avr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr, 'E','N', '3', 'C', (size_t)&modelOffset->avr),
	CashFlowCommonData(31, "avr_bef_sale", "comp_comp_avr_bef_sale",  "avr_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_bef_sale),
	CashFlowCommonData(32, "avr_bond", "comp_comp_avr_bond",  "avr_bond",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_bond, 'E','N', '3', 'C', (size_t)&modelOffset->avr_bond),
	CashFlowCommonData(33, "avr_bond_bef_sale", "comp_comp_avr_bond_bef_sale",  "avr_bond_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_bond_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_bond_bef_sale),
	CashFlowCommonData(34, "avr_bond_bocy", "comp_comp_avr_bond_bocy",  "avr_bond_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_bond_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_bond_bocy),
	CashFlowCommonData(35, "avr_dflt", "comp_comp_avr_dflt",  "avr_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->avr_dflt),
	CashFlowCommonData(36, "avr_dflt_bef_sale", "comp_comp_avr_dflt_bef_sale",  "avr_dflt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_dflt_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_dflt_bef_sale),
	CashFlowCommonData(37, "avr_eqt", "comp_comp_avr_eqt",  "avr_eqt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_eqt, 'E','N', '3', 'C', (size_t)&modelOffset->avr_eqt),
	CashFlowCommonData(38, "avr_eqt_bef_sale", "comp_comp_avr_eqt_bef_sale",  "avr_eqt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_eqt_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_eqt_bef_sale),
	CashFlowCommonData(39, "avr_incr", "comp_comp_avr_incr",  "avr_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_incr, 'E','N', '3', 'C', (size_t)&modelOffset->avr_incr),
	CashFlowCommonData(40, "avr_mtg", "comp_comp_avr_mtg",  "avr_mtg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_mtg, 'E','N', '3', 'C', (size_t)&modelOffset->avr_mtg),
	CashFlowCommonData(41, "avr_mtg_bef_sale", "comp_comp_avr_mtg_bef_sale",  "avr_mtg_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_mtg_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_mtg_bef_sale),
	CashFlowCommonData(42, "avr_mtg_bocy", "comp_comp_avr_mtg_bocy",  "avr_mtg_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_mtg_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_mtg_bocy),
	CashFlowCommonData(43, "avr_other", "comp_comp_avr_other",  "avr_other",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_other, 'E','N', '3', 'C', (size_t)&modelOffset->avr_other),
	CashFlowCommonData(44, "avr_other_bef_sale", "comp_comp_avr_other_bef_sale",  "avr_other_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_other_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_other_bef_sale),
	CashFlowCommonData(45, "avr_other_bocy", "comp_comp_avr_other_bocy",  "avr_other_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_other_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_other_bocy),
	CashFlowCommonData(46, "avr_stock", "comp_comp_avr_stock",  "avr_stock",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_stock, 'E','N', '3', 'C', (size_t)&modelOffset->avr_stock),
	CashFlowCommonData(47, "avr_stock_bef_sale", "comp_comp_avr_stock_bef_sale",  "avr_stock_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_stock_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_stock_bef_sale),
	CashFlowCommonData(48, "avr_stock_bocy", "comp_comp_avr_stock_bocy",  "avr_stock_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_stock_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_stock_bocy),
	CashFlowCommonData(49, "avr_unrealzd_cap_gain_eqt_bocy", "comp_comp_avr_unrealzd_cap_gain_eqt_bocy",  "avr_unrealzd_cap_gain_eqt_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_unrealzd_cap_gain_eqt_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_unrealzd_cap_gain_eqt_bocy),
	CashFlowCommonData(50, "avr_unrealzd_cap_gain_non_eqt_bocy", "comp_comp_avr_unrealzd_cap_gain_non_eqt_bocy",  "avr_unrealzd_cap_gain_non_eqt_bocy",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_avr_unrealzd_cap_gain_non_eqt_bocy, 'E','N', '3', 'C', (size_t)&modelOffset->avr_unrealzd_cap_gain_non_eqt_bocy),
	CashFlowCommonData(51, "bef_tax_yld", "comp_comp_bef_tax_yld",  "bef_tax_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bef_tax_yld, 'E','N', '3', 'C', (size_t)&modelOffset->bef_tax_yld),
	CashFlowCommonData(52, "bk_prof_aft_tax", "comp_comp_bk_prof_aft_tax",  "bk_prof_aft_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax),
	CashFlowCommonData(53, "bk_prof_aft_tax_bef_sale", "comp_comp_bk_prof_aft_tax_bef_sale",  "bk_prof_aft_tax_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_bef_sale),
	CashFlowCommonData(54, "bk_prof_aft_tax_for_pv", "comp_comp_bk_prof_aft_tax_for_pv",  "bk_prof_aft_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_for_pv),
	CashFlowCommonData(55, "bk_prof_aft_tax_irr", "comp_comp_bk_prof_aft_tax_irr",  "bk_prof_aft_tax_irr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_irr, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_irr),
	CashFlowCommonData(56, "bk_prof_aft_tax_qtd", "comp_comp_bk_prof_aft_tax_qtd",  "bk_prof_aft_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_qtd),
	CashFlowCommonData(57, "bk_prof_aft_tax_ytd", "comp_comp_bk_prof_aft_tax_ytd",  "bk_prof_aft_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_aft_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_ytd),
	CashFlowCommonData(58, "bk_prof_bef_tax", "comp_comp_bk_prof_bef_tax",  "bk_prof_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_bef_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax),
	CashFlowCommonData(59, "bk_prof_bef_tax_bef_sale", "comp_comp_bk_prof_bef_tax_bef_sale",  "bk_prof_bef_tax_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_bef_sale),
	CashFlowCommonData(60, "bk_prof_bef_tax_for_pv", "comp_comp_bk_prof_bef_tax_for_pv",  "bk_prof_bef_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_for_pv),
	CashFlowCommonData(61, "bk_prof_bef_tax_qtd", "comp_comp_bk_prof_bef_tax_qtd",  "bk_prof_bef_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_qtd),
	CashFlowCommonData(62, "bk_prof_bef_tax_ytd", "comp_comp_bk_prof_bef_tax_ytd",  "bk_prof_bef_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_bef_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_ytd),
	CashFlowCommonData(63, "bk_prof_by_source_bef_tax", "comp_comp_bk_prof_by_source_bef_tax",  "bk_prof_by_source_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_prof_by_source_bef_tax, 'E','N', '3', 'P', (size_t)&modelOffset->bk_prof_by_source_bef_tax),
	CashFlowCommonData(64, "bk_val", "comp_comp_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(65, "bk_val_inv", "comp_comp_bk_val_inv",  "bk_val_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_bk_val_inv, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_inv),
	CashFlowCommonData(66, "borrowing", "comp_comp_borrowing",  "borrowing",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_borrowing, 'E','N', '3', 'C', (size_t)&modelOffset->borrowing),
	CashFlowCommonData(67, "borrowing_int", "comp_comp_borrowing_int",  "borrowing_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_borrowing_int, 'E','Y', '3', 'C', (size_t)&modelOffset->borrowing_int),
	CashFlowCommonData(68, "cal_mth", "comp_comp_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(69, "cal_yr", "comp_comp_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(70, "cal_yr_relative", "comp_comp_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(71, "cap_gain", "comp_comp_cap_gain",  "cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain),
	CashFlowCommonData(72, "cap_gain_bef_sale", "comp_comp_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(73, "cap_gain_free_surp", "comp_comp_cap_gain_free_surp",  "cap_gain_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_free_surp),
	CashFlowCommonData(74, "cap_gain_free_surp_bef_sale", "comp_comp_cap_gain_free_surp_bef_sale",  "cap_gain_free_surp_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_free_surp_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_free_surp_bef_sale),
	CashFlowCommonData(75, "cap_gain_from_sale", "comp_comp_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_from_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(76, "cap_gain_res", "comp_comp_cap_gain_res",  "cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_res),
	CashFlowCommonData(77, "cap_gain_res_bef_sale", "comp_comp_cap_gain_res_bef_sale",  "cap_gain_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_res_bef_sale),
	CashFlowCommonData(78, "cap_gain_tgt_cap", "comp_comp_cap_gain_tgt_cap",  "cap_gain_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_tgt_cap),
	CashFlowCommonData(79, "cap_gain_tgt_cap_bef_sale", "comp_comp_cap_gain_tgt_cap_bef_sale",  "cap_gain_tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_tgt_cap_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_tgt_cap_bef_sale),
	CashFlowCommonData(80, "cap_gain_undistrib_earnings", "comp_comp_cap_gain_undistrib_earnings",  "cap_gain_undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_undistrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_undistrib_earnings),
	CashFlowCommonData(81, "cap_gain_undistrib_earnings_bef_sale", "comp_comp_cap_gain_undistrib_earnings_bef_sale",  "cap_gain_undistrib_earnings_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cap_gain_undistrib_earnings_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_undistrib_earnings_bef_sale),
	CashFlowCommonData(82, "cash", "comp_comp_cash",  "cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash, 'E','N', '3', 'C', (size_t)&modelOffset->cash),
	CashFlowCommonData(83, "cash_flow_for_inv", "comp_comp_cash_flow_for_inv",  "cash_flow_for_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_flow_for_inv, 'M','Y', '3', 'C', (size_t)&modelOffset->cash_flow_for_inv),
	CashFlowCommonData(84, "cash_flow_int", "comp_comp_cash_flow_int",  "cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_int),
	CashFlowCommonData(85, "cash_flow_invested", "comp_comp_cash_flow_invested",  "cash_flow_invested",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_flow_invested, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_invested),
	CashFlowCommonData(86, "cash_int", "comp_comp_cash_int",  "cash_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_int, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_int),
	CashFlowCommonData(87, "cash_int_inv", "comp_comp_cash_int_inv",  "cash_int_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_int_inv, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_int_inv),
	CashFlowCommonData(88, "cash_val", "comp_comp_cash_val",  "cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->cash_val),
	CashFlowCommonData(89, "claim_paid", "comp_comp_claim_paid",  "claim_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_claim_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->claim_paid),
	CashFlowCommonData(90, "comm_bom", "comp_comp_comm_bom",  "comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->comm_bom),
	CashFlowCommonData(91, "comm_chargeback", "comp_comp_comm_chargeback",  "comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_comm_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_chargeback),
	CashFlowCommonData(92, "comm_eom", "comp_comp_comm_eom",  "comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_eom),
	CashFlowCommonData(93, "conversion_cost", "comp_comp_conversion_cost",  "conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_conversion_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->conversion_cost),
	CashFlowCommonData(94, "cost_basis_accrual", "comp_comp_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cost_basis_accrual, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(95, "cost_basis_incr_appreciation", "comp_comp_cost_basis_incr_appreciation",  "cost_basis_incr_appreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cost_basis_incr_appreciation, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_incr_appreciation),
	CashFlowCommonData(96, "cost_basis_purch", "comp_comp_cost_basis_purch",  "cost_basis_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cost_basis_purch, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_purch),
	CashFlowCommonData(97, "cost_basis_sale", "comp_comp_cost_basis_sale",  "cost_basis_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_cost_basis_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_sale),
	CashFlowCommonData(98, "credited_int", "comp_comp_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_credited_int, 'E','N', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(99, "date", "comp_comp_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(100, "deferred_gross_prem", "comp_comp_deferred_gross_prem",  "deferred_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_deferred_gross_prem, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_gross_prem),
	CashFlowCommonData(101, "deferred_gross_prem_incr", "comp_comp_deferred_gross_prem_incr",  "deferred_gross_prem_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_deferred_gross_prem_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->deferred_gross_prem_incr),
	CashFlowCommonData(102, "deferred_net_prem", "comp_comp_deferred_net_prem",  "deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_net_prem),
	CashFlowCommonData(103, "delta_hedge_inv_amt", "comp_comp_delta_hedge_inv_amt",  "delta_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_inv_amt),
	CashFlowCommonData(104, "delta_hedge_mkt_val", "comp_comp_delta_hedge_mkt_val",  "delta_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->delta_hedge_mkt_val),
	CashFlowCommonData(105, "delta_hedge_mkt_val_incr", "comp_comp_delta_hedge_mkt_val_incr",  "delta_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_mkt_val_incr),
	CashFlowCommonData(106, "delta_hedge_pmt", "comp_comp_delta_hedge_pmt",  "delta_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_pmt),
	CashFlowCommonData(107, "delta_hedge_prof", "comp_comp_delta_hedge_prof",  "delta_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_prof),
	CashFlowCommonData(108, "delta_hedge_sale_amt", "comp_comp_delta_hedge_sale_amt",  "delta_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_sale_amt),
	CashFlowCommonData(109, "delta_hedge_transaction_cost", "comp_comp_delta_hedge_transaction_cost",  "delta_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_delta_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->delta_hedge_transaction_cost),
	CashFlowCommonData(110, "dflt_amt", "comp_comp_dflt_amt",  "dflt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_dflt_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->dflt_amt),
	CashFlowCommonData(111, "direct_cash_flow_bom", "comp_comp_direct_cash_flow_bom",  "direct_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_direct_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->direct_cash_flow_bom),
	CashFlowCommonData(112, "direct_cash_flow_eom", "comp_comp_direct_cash_flow_eom",  "direct_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_direct_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->direct_cash_flow_eom),
	CashFlowCommonData(113, "direct_cash_flow_int", "comp_comp_direct_cash_flow_int",  "direct_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_direct_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->direct_cash_flow_int),
	CashFlowCommonData(114, "disc_rate_1", "comp_comp_disc_rate_1",  "disc_rate_1",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_1, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_1),
	CashFlowCommonData(115, "disc_rate_2", "comp_comp_disc_rate_2",  "disc_rate_2",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_2, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_2),
	CashFlowCommonData(116, "disc_rate_3", "comp_comp_disc_rate_3",  "disc_rate_3",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_3, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_3),
	CashFlowCommonData(117, "disc_rate_aig_curve_ic_uel_aig", "comp_comp_disc_rate_aig_curve_ic_uel_aig",  "disc_rate_aig_curve_ic_uel_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_ic_uel_aig, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_aig_curve_ic_uel_aig),
	CashFlowCommonData(118, "disc_rate_aig_curve_no_uel_aig", "comp_comp_disc_rate_aig_curve_no_uel_aig",  "disc_rate_aig_curve_no_uel_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_no_uel_aig, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_aig_curve_no_uel_aig),
	CashFlowCommonData(119, "disc_rate_aig_curve_uel_aig", "comp_comp_disc_rate_aig_curve_uel_aig",  "disc_rate_aig_curve_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_aig_curve_uel_aig, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_aig_curve_uel_aig),
	CashFlowCommonData(120, "disc_rate_port_yld", "comp_comp_disc_rate_port_yld",  "disc_rate_port_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_port_yld, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_port_yld),
	CashFlowCommonData(121, "disc_rate_port_yld_defn_val", "comp_comp_disc_rate_port_yld_defn_val",  "disc_rate_port_yld_defn_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_port_yld_defn_val, 'E','N', '3', 'P', (size_t)&modelOffset->disc_rate_port_yld_defn_val),
	CashFlowCommonData(122, "disc_rate_risk_free_aig", "comp_comp_disc_rate_risk_free_aig",  "disc_rate_risk_free_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_disc_rate_risk_free_aig, 'E','N', '3', 'C', (size_t)&modelOffset->disc_rate_risk_free_aig),
	CashFlowCommonData(123, "distrib_earnings", "comp_comp_distrib_earnings",  "distrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings),
	CashFlowCommonData(124, "distrib_earnings_be", "comp_comp_distrib_earnings_be",  "distrib_earnings_be",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings_be, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings_be),
	CashFlowCommonData(125, "distrib_earnings_bef_sale", "comp_comp_distrib_earnings_bef_sale",  "distrib_earnings_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings_bef_sale),
	CashFlowCommonData(126, "distrib_earnings_cum", "comp_comp_distrib_earnings_cum",  "distrib_earnings_cum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings_cum, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings_cum),
	CashFlowCommonData(127, "distrib_earnings_irr", "comp_comp_distrib_earnings_irr",  "distrib_earnings_irr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings_irr, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings_irr),
	CashFlowCommonData(128, "distrib_earnings_strain", "comp_comp_distrib_earnings_strain",  "distrib_earnings_strain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_distrib_earnings_strain, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings_strain),
	CashFlowCommonData(129, "div_applied", "comp_comp_div_applied",  "div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_div_applied, 'B','Y', '3', 'C', (size_t)&modelOffset->div_applied),
	CashFlowCommonData(130, "div_liab", "comp_comp_div_liab",  "div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->div_liab),
	CashFlowCommonData(131, "div_liab_incr", "comp_comp_div_liab_incr",  "div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->div_liab_incr),
	CashFlowCommonData(132, "div_paid", "comp_comp_div_paid",  "div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->div_paid),
	CashFlowCommonData(133, "dth_ben_inf", "comp_comp_dth_ben_inf",  "dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->dth_ben_inf),
	CashFlowCommonData(134, "dth_benefits", "comp_comp_dth_benefits",  "dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->dth_benefits),
	CashFlowCommonData(135, "dth_count_aig", "comp_comp_dth_count_aig",  "dth_count_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_dth_count_aig, 'M','N', '3', 'C', (size_t)&modelOffset->dth_count_aig),
	CashFlowCommonData(136, "earnings_accum", "comp_comp_earnings_accum",  "earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->earnings_accum),
	CashFlowCommonData(137, "econ_cash", "comp_comp_econ_cash",  "econ_cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_cash, 'E','N', '3', 'P', (size_t)&modelOffset->econ_cash),
	CashFlowCommonData(138, "econ_cash_int", "comp_comp_econ_cash_int",  "econ_cash_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_cash_int, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_cash_int),
	CashFlowCommonData(139, "econ_prof", "comp_comp_econ_prof",  "econ_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_prof),
	CashFlowCommonData(140, "econ_prof_unhedged", "comp_comp_econ_prof_unhedged",  "econ_prof_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_prof_unhedged, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_prof_unhedged),
	CashFlowCommonData(141, "econ_res", "comp_comp_econ_res",  "econ_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_res, 'E','N', '3', 'P', (size_t)&modelOffset->econ_res),
	CashFlowCommonData(142, "econ_res_incr", "comp_comp_econ_res_incr",  "econ_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_res_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_res_incr),
	CashFlowCommonData(143, "econ_res_int", "comp_comp_econ_res_int",  "econ_res_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_econ_res_int, 'E','Y', '3', 'P', (size_t)&modelOffset->econ_res_int),
	CashFlowCommonData(144, "endow_benefits", "comp_comp_endow_benefits",  "endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->endow_benefits),
	CashFlowCommonData(145, "finalize", "comp_comp_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(146, "free_surp", "comp_comp_free_surp",  "free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_free_surp, 'E','N', '3', 'C', (size_t)&modelOffset->free_surp),
	CashFlowCommonData(147, "free_surp_at_mkt", "comp_comp_free_surp_at_mkt",  "free_surp_at_mkt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_free_surp_at_mkt, 'E','N', '3', 'C', (size_t)&modelOffset->free_surp_at_mkt),
	CashFlowCommonData(148, "free_surp_at_mkt_ending", "comp_comp_free_surp_at_mkt_ending",  "free_surp_at_mkt_ending",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_free_surp_at_mkt_ending, 'E','Y', '3', 'C', (size_t)&modelOffset->free_surp_at_mkt_ending),
	CashFlowCommonData(149, "free_surp_bef_shldr_div", "comp_comp_free_surp_bef_shldr_div",  "free_surp_bef_shldr_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_free_surp_bef_shldr_div, 'E','N', '3', 'C', (size_t)&modelOffset->free_surp_bef_shldr_div),
	CashFlowCommonData(150, "free_surp_incr", "comp_comp_free_surp_incr",  "free_surp_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_free_surp_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->free_surp_incr),
	CashFlowCommonData(151, "fund_released_ann", "comp_comp_fund_released_ann",  "fund_released_ann",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_released_ann, 'E','N', '3', 'C', (size_t)&modelOffset->fund_released_ann),
	CashFlowCommonData(152, "fund_released_dth", "comp_comp_fund_released_dth",  "fund_released_dth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_released_dth, 'E','N', '3', 'C', (size_t)&modelOffset->fund_released_dth),
	CashFlowCommonData(153, "fund_released_maturity", "comp_comp_fund_released_maturity",  "fund_released_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_released_maturity, 'E','N', '3', 'C', (size_t)&modelOffset->fund_released_maturity),
	CashFlowCommonData(154, "fund_released_surr", "comp_comp_fund_released_surr",  "fund_released_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_released_surr, 'E','N', '3', 'C', (size_t)&modelOffset->fund_released_surr),
	CashFlowCommonData(155, "fund_released_withdrl", "comp_comp_fund_released_withdrl",  "fund_released_withdrl",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_released_withdrl, 'E','N', '3', 'C', (size_t)&modelOffset->fund_released_withdrl),
	CashFlowCommonData(156, "fund_val_fixed", "comp_comp_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_val_fixed, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(157, "fund_val_sa", "comp_comp_fund_val_sa",  "fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_val_sa, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_sa),
	CashFlowCommonData(158, "fund_weighted_cap_spread_fix_rt_aig", "comp_comp_fund_weighted_cap_spread_fix_rt_aig",  "fund_weighted_cap_spread_fix_rt_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_weighted_cap_spread_fix_rt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_weighted_cap_spread_fix_rt_aig),
	CashFlowCommonData(159, "fund_weighted_par_rate_aig", "comp_comp_fund_weighted_par_rate_aig",  "fund_weighted_par_rate_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_weighted_par_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_weighted_par_rate_aig),
	CashFlowCommonData(160, "fund_weighted_pri_spread_aig", "comp_comp_fund_weighted_pri_spread_aig",  "fund_weighted_pri_spread_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_fund_weighted_pri_spread_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_weighted_pri_spread_aig),
	CashFlowCommonData(161, "gaap_accum_ben_claim_cost", "comp_comp_gaap_accum_ben_claim_cost",  "gaap_accum_ben_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_accum_ben_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_accum_ben_claim_cost),
	CashFlowCommonData(162, "gaap_acq_exp", "comp_comp_gaap_acq_exp",  "gaap_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_acq_exp),
	CashFlowCommonData(163, "gaap_ann_claim_cost", "comp_comp_gaap_ann_claim_cost",  "gaap_ann_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_ann_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_ann_claim_cost),
	CashFlowCommonData(164, "gaap_ben_res", "comp_comp_gaap_ben_res",  "gaap_ben_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_ben_res, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_ben_res),
	CashFlowCommonData(165, "gaap_ben_res_incr", "comp_comp_gaap_ben_res_incr",  "gaap_ben_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_ben_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_ben_res_incr),
	CashFlowCommonData(166, "gaap_cap_gain_cap", "comp_comp_gaap_cap_gain_cap",  "gaap_cap_gain_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_cap_gain_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_cap_gain_cap),
	CashFlowCommonData(167, "gaap_cap_gain_res", "comp_comp_gaap_cap_gain_res",  "gaap_cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_cap_gain_res),
	CashFlowCommonData(168, "gaap_capzd_acq_exp", "comp_comp_gaap_capzd_acq_exp",  "gaap_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_capzd_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_acq_exp),
	CashFlowCommonData(169, "gaap_capzd_comm_bom", "comp_comp_gaap_capzd_comm_bom",  "gaap_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_capzd_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_comm_bom),
	CashFlowCommonData(170, "gaap_capzd_comm_eom", "comp_comp_gaap_capzd_comm_eom",  "gaap_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_capzd_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_comm_eom),
	CashFlowCommonData(171, "gaap_capzd_prem_bonus", "comp_comp_gaap_capzd_prem_bonus",  "gaap_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_capzd_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_prem_bonus),
	CashFlowCommonData(172, "gaap_capzd_reins_yrt_cost", "comp_comp_gaap_capzd_reins_yrt_cost",  "gaap_capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_capzd_reins_yrt_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_reins_yrt_cost),
	CashFlowCommonData(173, "gaap_cash_flow_int", "comp_comp_gaap_cash_flow_int",  "gaap_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_cash_flow_int, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_cash_flow_int),
	CashFlowCommonData(174, "gaap_chg_inc", "comp_comp_gaap_chg_inc",  "gaap_chg_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_chg_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_chg_inc),
	CashFlowCommonData(175, "gaap_claim_res", "comp_comp_gaap_claim_res",  "gaap_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_claim_res),
	CashFlowCommonData(176, "gaap_claim_res_incr", "comp_comp_gaap_claim_res_incr",  "gaap_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_claim_res_incr),
	CashFlowCommonData(177, "gaap_comm_excess_bom", "comp_comp_gaap_comm_excess_bom",  "gaap_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_comm_excess_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_excess_bom),
	CashFlowCommonData(178, "gaap_comm_excess_eom", "comp_comp_gaap_comm_excess_eom",  "gaap_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_comm_excess_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_excess_eom),
	CashFlowCommonData(179, "gaap_comm_trail_bom", "comp_comp_gaap_comm_trail_bom",  "gaap_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_comm_trail_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_trail_bom),
	CashFlowCommonData(180, "gaap_comm_trail_eom", "comp_comp_gaap_comm_trail_eom",  "gaap_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_comm_trail_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_trail_eom),
	CashFlowCommonData(181, "gaap_conversion_cost", "comp_comp_gaap_conversion_cost",  "gaap_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_conversion_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_conversion_cost),
	CashFlowCommonData(182, "gaap_credited_int", "comp_comp_gaap_credited_int",  "gaap_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_credited_int),
	CashFlowCommonData(183, "gaap_dac", "comp_comp_gaap_dac",  "gaap_dac",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_dac, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_dac),
	CashFlowCommonData(184, "gaap_dac_incr", "comp_comp_gaap_dac_incr",  "gaap_dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_dac_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_dac_incr),
	CashFlowCommonData(185, "gaap_deferred_maint_exp", "comp_comp_gaap_deferred_maint_exp",  "gaap_deferred_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_deferred_maint_exp, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_deferred_maint_exp),
	CashFlowCommonData(186, "gaap_deferred_prof_liab", "comp_comp_gaap_deferred_prof_liab",  "gaap_deferred_prof_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_deferred_prof_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_deferred_prof_liab),
	CashFlowCommonData(187, "gaap_deferred_prof_liab_incr", "comp_comp_gaap_deferred_prof_liab_incr",  "gaap_deferred_prof_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_deferred_prof_liab_incr, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_deferred_prof_liab_incr),
	CashFlowCommonData(188, "gaap_deferred_tax_liab", "comp_comp_gaap_deferred_tax_liab",  "gaap_deferred_tax_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_deferred_tax_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_deferred_tax_liab),
	CashFlowCommonData(189, "gaap_deferred_tax_liab_incr", "comp_comp_gaap_deferred_tax_liab_incr",  "gaap_deferred_tax_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_deferred_tax_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_deferred_tax_liab_incr),
	CashFlowCommonData(190, "gaap_div_applied", "comp_comp_gaap_div_applied",  "gaap_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_div_applied, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_div_applied),
	CashFlowCommonData(191, "gaap_div_liab", "comp_comp_gaap_div_liab",  "gaap_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_div_liab),
	CashFlowCommonData(192, "gaap_div_liab_incr", "comp_comp_gaap_div_liab_incr",  "gaap_div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_div_liab_incr),
	CashFlowCommonData(193, "gaap_div_paid", "comp_comp_gaap_div_paid",  "gaap_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_div_paid, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_div_paid),
	CashFlowCommonData(194, "gaap_dth_claim_cost", "comp_comp_gaap_dth_claim_cost",  "gaap_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_dth_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_dth_claim_cost),
	CashFlowCommonData(195, "gaap_endow_claim_cost", "comp_comp_gaap_endow_claim_cost",  "gaap_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_endow_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_endow_claim_cost),
	CashFlowCommonData(196, "gaap_free_surp", "comp_comp_gaap_free_surp",  "gaap_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_free_surp, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_free_surp),
	CashFlowCommonData(197, "gaap_gross_prem", "comp_comp_gaap_gross_prem",  "gaap_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_gross_prem, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_gross_prem),
	CashFlowCommonData(198, "gaap_hedge_cost", "comp_comp_gaap_hedge_cost",  "gaap_hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_hedge_cost),
	CashFlowCommonData(199, "gaap_hedge_mkt_val", "comp_comp_gaap_hedge_mkt_val",  "gaap_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_hedge_mkt_val, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_hedge_mkt_val),
	CashFlowCommonData(200, "gaap_hedge_mkt_val_incr", "comp_comp_gaap_hedge_mkt_val_incr",  "gaap_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_hedge_mkt_val_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_hedge_mkt_val_incr),
	CashFlowCommonData(201, "gaap_hlth_claim_cost", "comp_comp_gaap_hlth_claim_cost",  "gaap_hlth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_hlth_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_hlth_claim_cost),
	CashFlowCommonData(202, "gaap_inc_aft_tax", "comp_comp_gaap_inc_aft_tax",  "gaap_inc_aft_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax),
	CashFlowCommonData(203, "gaap_inc_aft_tax_qtd", "comp_comp_gaap_inc_aft_tax_qtd",  "gaap_inc_aft_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax_qtd),
	CashFlowCommonData(204, "gaap_inc_aft_tax_ytd", "comp_comp_gaap_inc_aft_tax_ytd",  "gaap_inc_aft_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_aft_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax_ytd),
	CashFlowCommonData(205, "gaap_inc_bef_tax", "comp_comp_gaap_inc_bef_tax",  "gaap_inc_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax),
	CashFlowCommonData(206, "gaap_inc_bef_tax_qtd", "comp_comp_gaap_inc_bef_tax_qtd",  "gaap_inc_bef_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax_qtd),
	CashFlowCommonData(207, "gaap_inc_bef_tax_ytd", "comp_comp_gaap_inc_bef_tax_ytd",  "gaap_inc_bef_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_bef_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax_ytd),
	CashFlowCommonData(208, "gaap_inc_ben_claim_cost", "comp_comp_gaap_inc_ben_claim_cost",  "gaap_inc_ben_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_ben_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_ben_claim_cost),
	CashFlowCommonData(209, "gaap_inc_deferred_tax_liab", "comp_comp_gaap_inc_deferred_tax_liab",  "gaap_inc_deferred_tax_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_deferred_tax_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_deferred_tax_liab),
	CashFlowCommonData(210, "gaap_inc_inv_asset", "comp_comp_gaap_inc_inv_asset",  "gaap_inc_inv_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_inv_asset, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_inv_asset),
	CashFlowCommonData(211, "gaap_inc_unrealzd_cap_gain", "comp_comp_gaap_inc_unrealzd_cap_gain",  "gaap_inc_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain),
	CashFlowCommonData(212, "gaap_inc_unrealzd_cap_gain_incr", "comp_comp_gaap_inc_unrealzd_cap_gain_incr",  "gaap_inc_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inc_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain_incr),
	CashFlowCommonData(213, "gaap_inv_asset", "comp_comp_gaap_inv_asset",  "gaap_inv_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_asset, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset),
	CashFlowCommonData(214, "gaap_inv_asset_available", "comp_comp_gaap_inv_asset_available",  "gaap_inv_asset_available",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_asset_available, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset_available),
	CashFlowCommonData(215, "gaap_inv_asset_held", "comp_comp_gaap_inv_asset_held",  "gaap_inv_asset_held",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_asset_held, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset_held),
	CashFlowCommonData(216, "gaap_inv_asset_not_assigned", "comp_comp_gaap_inv_asset_not_assigned",  "gaap_inv_asset_not_assigned",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_asset_not_assigned, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset_not_assigned),
	CashFlowCommonData(217, "gaap_inv_asset_trading", "comp_comp_gaap_inv_asset_trading",  "gaap_inv_asset_trading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_asset_trading, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset_trading),
	CashFlowCommonData(218, "gaap_inv_inc_cap", "comp_comp_gaap_inv_inc_cap",  "gaap_inv_inc_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_inc_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inv_inc_cap),
	CashFlowCommonData(219, "gaap_inv_inc_res", "comp_comp_gaap_inv_inc_res",  "gaap_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inv_inc_res),
	CashFlowCommonData(220, "gaap_liab_net", "comp_comp_gaap_liab_net",  "gaap_liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_liab_net, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_liab_net),
	CashFlowCommonData(221, "gaap_liab_net_net", "comp_comp_gaap_liab_net_net",  "gaap_liab_net_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_liab_net_net, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_liab_net_net),
	CashFlowCommonData(222, "gaap_loads_deducted", "comp_comp_gaap_loads_deducted",  "gaap_loads_deducted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_loads_deducted, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_loads_deducted),
	CashFlowCommonData(223, "gaap_loads_deferred", "comp_comp_gaap_loads_deferred",  "gaap_loads_deferred",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_loads_deferred, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_loads_deferred),
	CashFlowCommonData(224, "gaap_loc_cost", "comp_comp_gaap_loc_cost",  "gaap_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_loc_cost, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_loc_cost),
	CashFlowCommonData(225, "gaap_maint_exp_bom", "comp_comp_gaap_maint_exp_bom",  "gaap_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_bom),
	CashFlowCommonData(226, "gaap_maint_exp_eom", "comp_comp_gaap_maint_exp_eom",  "gaap_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_eom),
	CashFlowCommonData(227, "gaap_maint_exp_res", "comp_comp_gaap_maint_exp_res",  "gaap_maint_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_maint_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_res),
	CashFlowCommonData(228, "gaap_maint_exp_res_incr", "comp_comp_gaap_maint_exp_res_incr",  "gaap_maint_exp_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_maint_exp_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_res_incr),
	CashFlowCommonData(229, "gaap_maturity_claim_cost", "comp_comp_gaap_maturity_claim_cost",  "gaap_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_maturity_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_maturity_claim_cost),
	CashFlowCommonData(230, "gaap_prem_bonus", "comp_comp_gaap_prem_bonus",  "gaap_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prem_bonus, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prem_bonus),
	CashFlowCommonData(231, "gaap_prem_tax", "comp_comp_gaap_prem_tax",  "gaap_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_prem_tax),
	CashFlowCommonData(232, "gaap_prem_waiver_res", "comp_comp_gaap_prem_waiver_res",  "gaap_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prem_waiver_res, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_prem_waiver_res),
	CashFlowCommonData(233, "gaap_prem_waiver_res_incr", "comp_comp_gaap_prem_waiver_res_incr",  "gaap_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prem_waiver_res_incr),
	CashFlowCommonData(234, "gaap_prof_aft_tax_for_pv", "comp_comp_gaap_prof_aft_tax_for_pv",  "gaap_prof_aft_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prof_aft_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prof_aft_tax_for_pv),
	CashFlowCommonData(235, "gaap_prof_bef_tax_for_pv", "comp_comp_gaap_prof_bef_tax_for_pv",  "gaap_prof_bef_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_prof_bef_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prof_bef_tax_for_pv),
	CashFlowCommonData(236, "gaap_reins_yrt_cost", "comp_comp_gaap_reins_yrt_cost",  "gaap_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_reins_yrt_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_reins_yrt_cost),
	CashFlowCommonData(237, "gaap_req_cap", "comp_comp_gaap_req_cap",  "gaap_req_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_req_cap, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_req_cap),
	CashFlowCommonData(238, "gaap_sfas133_liab", "comp_comp_gaap_sfas133_liab",  "gaap_sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_sfas133_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_sfas133_liab),
	CashFlowCommonData(239, "gaap_sfas133_liab_incr", "comp_comp_gaap_sfas133_liab_incr",  "gaap_sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_sfas133_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_sfas133_liab_incr),
	CashFlowCommonData(240, "gaap_sop031_addl_liab", "comp_comp_gaap_sop031_addl_liab",  "gaap_sop031_addl_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_sop031_addl_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_sop031_addl_liab),
	CashFlowCommonData(241, "gaap_sop031_addl_liab_incr", "comp_comp_gaap_sop031_addl_liab_incr",  "gaap_sop031_addl_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_sop031_addl_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_sop031_addl_liab_incr),
	CashFlowCommonData(242, "gaap_surp_incr", "comp_comp_gaap_surp_incr",  "gaap_surp_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_surp_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_surp_incr),
	CashFlowCommonData(243, "gaap_surp_unrealzd_cap_gain", "comp_comp_gaap_surp_unrealzd_cap_gain",  "gaap_surp_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_surp_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_surp_unrealzd_cap_gain),
	CashFlowCommonData(244, "gaap_surp_unrealzd_cap_gain_incr", "comp_comp_gaap_surp_unrealzd_cap_gain_incr",  "gaap_surp_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_surp_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_surp_unrealzd_cap_gain_incr),
	CashFlowCommonData(245, "gaap_surr_claim_cost", "comp_comp_gaap_surr_claim_cost",  "gaap_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_surr_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_surr_claim_cost),
	CashFlowCommonData(246, "gaap_surr_inc", "comp_comp_gaap_surr_inc",  "gaap_surr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_surr_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_surr_inc),
	CashFlowCommonData(247, "gaap_terminal_div", "comp_comp_gaap_terminal_div",  "gaap_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_terminal_div, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_terminal_div),
	CashFlowCommonData(248, "gaap_unearn_rev_liab", "comp_comp_gaap_unearn_rev_liab",  "gaap_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_unearn_rev_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_unearn_rev_liab),
	CashFlowCommonData(249, "gaap_unearn_rev_released", "comp_comp_gaap_unearn_rev_released",  "gaap_unearn_rev_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_unearn_rev_released, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_unearn_rev_released),
	CashFlowCommonData(250, "gaap_unrealzd_cap_gain_incr", "comp_comp_gaap_unrealzd_cap_gain_incr",  "gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(251, "gaap_withdrl_ben_claim_cost", "comp_comp_gaap_withdrl_ben_claim_cost",  "gaap_withdrl_ben_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gaap_withdrl_ben_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_withdrl_ben_claim_cost),
	CashFlowCommonData(252, "gamma_hedge_inv_amt", "comp_comp_gamma_hedge_inv_amt",  "gamma_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_inv_amt),
	CashFlowCommonData(253, "gamma_hedge_mkt_val", "comp_comp_gamma_hedge_mkt_val",  "gamma_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->gamma_hedge_mkt_val),
	CashFlowCommonData(254, "gamma_hedge_mkt_val_incr", "comp_comp_gamma_hedge_mkt_val_incr",  "gamma_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_mkt_val_incr),
	CashFlowCommonData(255, "gamma_hedge_pmt", "comp_comp_gamma_hedge_pmt",  "gamma_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_pmt)
};

const CashFlowCommonData COMP_COMP::mCFStaticData_256[] = 
{
	CashFlowCommonData(256, "gamma_hedge_prof", "comp_comp_gamma_hedge_prof",  "gamma_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_prof),
	CashFlowCommonData(257, "gamma_hedge_sale_amt", "comp_comp_gamma_hedge_sale_amt",  "gamma_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_sale_amt),
	CashFlowCommonData(258, "gamma_hedge_transaction_cost", "comp_comp_gamma_hedge_transaction_cost",  "gamma_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gamma_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->gamma_hedge_transaction_cost),
	CashFlowCommonData(259, "gmwb_chg", "comp_comp_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gmwb_chg, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(260, "gmwb_inf", "comp_comp_gmwb_inf",  "gmwb_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gmwb_inf, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_inf),
	CashFlowCommonData(261, "gross_prem_annualzd", "comp_comp_gross_prem_annualzd",  "gross_prem_annualzd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_gross_prem_annualzd, 'E','N', '3', 'C', (size_t)&modelOffset->gross_prem_annualzd),
	CashFlowCommonData(262, "hedge_cash_flow", "comp_comp_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(263, "hedge_cost", "comp_comp_hedge_cost",  "hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost),
	CashFlowCommonData(264, "hedge_cost_bef_sale", "comp_comp_hedge_cost_bef_sale",  "hedge_cost_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_cost_bef_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost_bef_sale),
	CashFlowCommonData(265, "hedge_cost_charge", "comp_comp_hedge_cost_charge",  "hedge_cost_charge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_cost_charge, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost_charge),
	CashFlowCommonData(266, "hedge_exp", "comp_comp_hedge_exp",  "hedge_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_exp),
	CashFlowCommonData(267, "hedge_int_pmt", "comp_comp_hedge_int_pmt",  "hedge_int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_int_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_int_pmt),
	CashFlowCommonData(268, "hedge_inv_amt_bom", "comp_comp_hedge_inv_amt_bom",  "hedge_inv_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_inv_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_bom),
	CashFlowCommonData(269, "hedge_inv_amt_eom", "comp_comp_hedge_inv_amt_eom",  "hedge_inv_amt_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_inv_amt_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_eom),
	CashFlowCommonData(270, "hedge_liab_claims", "comp_comp_hedge_liab_claims",  "hedge_liab_claims",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_liab_claims, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_liab_claims),
	CashFlowCommonData(271, "hedge_mkt_val", "comp_comp_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_mkt_val, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(272, "hedge_mkt_val_incr", "comp_comp_hedge_mkt_val_incr",  "hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_mkt_val_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->hedge_mkt_val_incr),
	CashFlowCommonData(273, "hedge_opt_pmt", "comp_comp_hedge_opt_pmt",  "hedge_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_opt_pmt),
	CashFlowCommonData(274, "hedge_rila_trading_cost_aig", "comp_comp_hedge_rila_trading_cost_aig",  "hedge_rila_trading_cost_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_rila_trading_cost_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_rila_trading_cost_aig),
	CashFlowCommonData(275, "hedge_sale_amt", "comp_comp_hedge_sale_amt",  "hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt),
	CashFlowCommonData(276, "imr", "comp_comp_imr",  "imr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr, 'E','N', '3', 'C', (size_t)&modelOffset->imr),
	CashFlowCommonData(277, "imr_bef_sale", "comp_comp_imr_bef_sale",  "imr_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->imr_bef_sale),
	CashFlowCommonData(278, "imr_impact_free_surp", "comp_comp_imr_impact_free_surp",  "imr_impact_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_free_surp),
	CashFlowCommonData(279, "imr_impact_free_surp_bef_sale", "comp_comp_imr_impact_free_surp_bef_sale",  "imr_impact_free_surp_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_free_surp_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_free_surp_bef_sale),
	CashFlowCommonData(280, "imr_impact_res", "comp_comp_imr_impact_res",  "imr_impact_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_res, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_res),
	CashFlowCommonData(281, "imr_impact_res_bef_sale", "comp_comp_imr_impact_res_bef_sale",  "imr_impact_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_res_bef_sale),
	CashFlowCommonData(282, "imr_impact_tgt_cap", "comp_comp_imr_impact_tgt_cap",  "imr_impact_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_tgt_cap),
	CashFlowCommonData(283, "imr_impact_tgt_cap_bef_sale", "comp_comp_imr_impact_tgt_cap_bef_sale",  "imr_impact_tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_impact_tgt_cap_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_impact_tgt_cap_bef_sale),
	CashFlowCommonData(284, "imr_incr", "comp_comp_imr_incr",  "imr_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_incr),
	CashFlowCommonData(285, "imr_incr_bef_sale", "comp_comp_imr_incr_bef_sale",  "imr_incr_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_imr_incr_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_incr_bef_sale),
	CashFlowCommonData(286, "initialize", "comp_comp_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(287, "int_pmt", "comp_comp_int_pmt",  "int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_int_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->int_pmt),
	CashFlowCommonData(288, "interim_cash", "comp_comp_interim_cash",  "interim_cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_interim_cash, 'E','N', '3', 'C', (size_t)&modelOffset->interim_cash),
	CashFlowCommonData(289, "interim_cash_int", "comp_comp_interim_cash_int",  "interim_cash_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_interim_cash_int, 'E','Y', '3', 'C', (size_t)&modelOffset->interim_cash_int),
	CashFlowCommonData(290, "inv_asset", "comp_comp_inv_asset",  "inv_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_asset, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_asset),
	CashFlowCommonData(291, "inv_cash_flow_int_div_and_rent", "comp_comp_inv_cash_flow_int_div_and_rent",  "inv_cash_flow_int_div_and_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_cash_flow_int_div_and_rent, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_cash_flow_int_div_and_rent),
	CashFlowCommonData(292, "inv_cash_flow_prin_pmt", "comp_comp_inv_cash_flow_prin_pmt",  "inv_cash_flow_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_cash_flow_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_cash_flow_prin_pmt),
	CashFlowCommonData(293, "inv_exp", "comp_comp_inv_exp",  "inv_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_exp),
	CashFlowCommonData(294, "inv_fee_ref", "comp_comp_inv_fee_ref",  "inv_fee_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_fee_ref, 'B','Y', '3', 'P', (size_t)&modelOffset->inv_fee_ref),
	CashFlowCommonData(295, "inv_inc", "comp_comp_inv_inc",  "inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc),
	CashFlowCommonData(296, "inv_inc_bk_prof", "comp_comp_inv_inc_bk_prof",  "inv_inc_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_bk_prof),
	CashFlowCommonData(297, "inv_inc_bk_prof_bef_sale", "comp_comp_inv_inc_bk_prof_bef_sale",  "inv_inc_bk_prof_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_bk_prof_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_bk_prof_bef_sale),
	CashFlowCommonData(298, "inv_inc_earnings_accum", "comp_comp_inv_inc_earnings_accum",  "inv_inc_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_earnings_accum),
	CashFlowCommonData(299, "inv_inc_free_surp", "comp_comp_inv_inc_free_surp",  "inv_inc_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_free_surp),
	CashFlowCommonData(300, "inv_inc_fund", "comp_comp_inv_inc_fund",  "inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_fund, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_inc_fund),
	CashFlowCommonData(301, "inv_inc_on_invested_assets", "comp_comp_inv_inc_on_invested_assets",  "inv_inc_on_invested_assets",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_on_invested_assets, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_on_invested_assets),
	CashFlowCommonData(302, "inv_inc_res", "comp_comp_inv_inc_res",  "inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_res),
	CashFlowCommonData(303, "inv_inc_tgt_cap", "comp_comp_inv_inc_tgt_cap",  "inv_inc_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_tgt_cap),
	CashFlowCommonData(304, "inv_inc_undistrib_earnings", "comp_comp_inv_inc_undistrib_earnings",  "inv_inc_undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_inv_inc_undistrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_undistrib_earnings),
	CashFlowCommonData(305, "invested_asset_sale", "comp_comp_invested_asset_sale",  "invested_asset_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_invested_asset_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->invested_asset_sale),
	CashFlowCommonData(306, "irr", "comp_comp_irr",  "irr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_irr, 'B','Y', '3', 'P', (size_t)&modelOffset->irr),
	CashFlowCommonData(307, "irr2_aig", "comp_comp_irr2_aig",  "irr2_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_irr2_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->irr2_aig),
	CashFlowCommonData(308, "irr_wo_tgt_cap", "comp_comp_irr_wo_tgt_cap",  "irr_wo_tgt_cap",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_irr_wo_tgt_cap, 'B','Y', '3', 'P', (size_t)&modelOffset->irr_wo_tgt_cap),
	CashFlowCommonData(309, "lapse_count_aig", "comp_comp_lapse_count_aig",  "lapse_count_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_lapse_count_aig, 'M','N', '3', 'C', (size_t)&modelOffset->lapse_count_aig),
	CashFlowCommonData(310, "last_period_indicator", "comp_comp_last_period_indicator",  "last_period_indicator",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_last_period_indicator, 'E','Y', '3', 'P', (size_t)&modelOffset->last_period_indicator),
	CashFlowCommonData(311, "liab_and_surp", "comp_comp_liab_and_surp",  "liab_and_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_liab_and_surp, 'E','N', '3', 'C', (size_t)&modelOffset->liab_and_surp),
	CashFlowCommonData(312, "liab_cash_flow", "comp_comp_liab_cash_flow",  "liab_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_liab_cash_flow, 'E','Y', '3', 'C', (size_t)&modelOffset->liab_cash_flow),
	CashFlowCommonData(313, "liab_cash_flow_bom", "comp_comp_liab_cash_flow_bom",  "liab_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_liab_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->liab_cash_flow_bom),
	CashFlowCommonData(314, "liab_cash_flow_eom", "comp_comp_liab_cash_flow_eom",  "liab_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_liab_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->liab_cash_flow_eom),
	CashFlowCommonData(315, "loc_asset", "comp_comp_loc_asset",  "loc_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_loc_asset, 'E','N', '3', 'P', (size_t)&modelOffset->loc_asset),
	CashFlowCommonData(316, "loc_asset_incr", "comp_comp_loc_asset_incr",  "loc_asset_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_loc_asset_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->loc_asset_incr),
	CashFlowCommonData(317, "loc_cost", "comp_comp_loc_cost",  "loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_loc_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->loc_cost),
	CashFlowCommonData(318, "maint_exp_bom", "comp_comp_maint_exp_bom",  "maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->maint_exp_bom),
	CashFlowCommonData(319, "maint_exp_eom", "comp_comp_maint_exp_eom",  "maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->maint_exp_eom),
	CashFlowCommonData(320, "maturity_benefits", "comp_comp_maturity_benefits",  "maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->maturity_benefits),
	CashFlowCommonData(321, "mkt_val", "comp_comp_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_mkt_val, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(322, "mkt_val_sale", "comp_comp_mkt_val_sale",  "mkt_val_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_mkt_val_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_sale),
	CashFlowCommonData(323, "notional_amt", "comp_comp_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_notional_amt, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(324, "opt_budget_amt", "comp_comp_opt_budget_amt",  "opt_budget_amt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_opt_budget_amt, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget_amt),
	CashFlowCommonData(325, "opt_inc", "comp_comp_opt_inc",  "opt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_opt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_inc),
	CashFlowCommonData(326, "opt_payoff_aig", "comp_comp_opt_payoff_aig",  "opt_payoff_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_opt_payoff_aig, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_payoff_aig),
	CashFlowCommonData(327, "opt_pmt", "comp_comp_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(328, "pol_loan", "comp_comp_pol_loan",  "pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_loan, 'E','N', '3', 'C', (size_t)&modelOffset->pol_loan),
	CashFlowCommonData(329, "pol_loan_exp", "comp_comp_pol_loan_exp",  "pol_loan_exp",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_loan_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_exp),
	CashFlowCommonData(330, "pol_loan_inc", "comp_comp_pol_loan_inc",  "pol_loan_inc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_loan_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_inc),
	CashFlowCommonData(331, "pol_loan_int", "comp_comp_pol_loan_int",  "pol_loan_int",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_loan_int, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_int),
	CashFlowCommonData(332, "pol_loan_proceeds", "comp_comp_pol_loan_proceeds",  "pol_loan_proceeds",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_loan_proceeds, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_proceeds),
	CashFlowCommonData(333, "pol_mth_aig", "comp_comp_pol_mth_aig",  "pol_mth_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_mth_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_mth_aig),
	CashFlowCommonData(334, "pol_yr_aig", "comp_comp_pol_yr_aig",  "pol_yr_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_pol_yr_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_yr_aig),
	CashFlowCommonData(335, "policies_inf", "comp_comp_policies_inf",  "policies_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_policies_inf, 'E','N', '3', 'P', (size_t)&modelOffset->policies_inf),
	CashFlowCommonData(336, "policies_issued", "comp_comp_policies_issued",  "policies_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_policies_issued, 'E','N', '3', 'P', (size_t)&modelOffset->policies_issued),
	CashFlowCommonData(337, "port_yld", "comp_comp_port_yld",  "port_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_port_yld, 'E','N', '3', 'C', (size_t)&modelOffset->port_yld),
	CashFlowCommonData(338, "port_yld_aft_tax", "comp_comp_port_yld_aft_tax",  "port_yld_aft_tax",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_port_yld_aft_tax, 'E','N', '3', 'C', (size_t)&modelOffset->port_yld_aft_tax),
	CashFlowCommonData(339, "port_yld_denom", "comp_comp_port_yld_denom",  "port_yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_port_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->port_yld_denom),
	CashFlowCommonData(340, "port_yld_less_dflt", "comp_comp_port_yld_less_dflt",  "port_yld_less_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_port_yld_less_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->port_yld_less_dflt),
	CashFlowCommonData(341, "prem_bonus", "comp_comp_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_prem_bonus, 'E','N', '3', 'C', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(342, "prem_issued", "comp_comp_prem_issued",  "prem_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_prem_issued, 'E','N', '3', 'C', (size_t)&modelOffset->prem_issued),
	CashFlowCommonData(343, "prem_paid", "comp_comp_prem_paid",  "prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_prem_paid, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_paid),
	CashFlowCommonData(344, "prem_tax", "comp_comp_prem_tax",  "prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_tax),
	CashFlowCommonData(345, "prem_waiver_benefits", "comp_comp_prem_waiver_benefits",  "prem_waiver_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_prem_waiver_benefits, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_waiver_benefits),
	CashFlowCommonData(346, "proj_tgt_hedge_stmt", "comp_comp_proj_tgt_hedge_stmt",  "proj_tgt_hedge_stmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_proj_tgt_hedge_stmt, 'E','Y', '3', 'P', (size_t)&modelOffset->proj_tgt_hedge_stmt),
	CashFlowCommonData(347, "proxy_bond_generation", "comp_comp_proxy_bond_generation",  "proxy_bond_generation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_proxy_bond_generation, 'E','N', '3', 'P', (size_t)&modelOffset->proxy_bond_generation),
	CashFlowCommonData(348, "rbc", "comp_comp_rbc",  "rbc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc, 'E','N', '3', 'C', (size_t)&modelOffset->rbc),
	CashFlowCommonData(349, "rbc_bef_sale", "comp_comp_rbc_bef_sale",  "rbc_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_bef_sale),
	CashFlowCommonData(350, "rbc_c1", "comp_comp_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(351, "rbc_c1_bef_sale", "comp_comp_rbc_c1_bef_sale",  "rbc_c1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c1_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_bef_sale),
	CashFlowCommonData(352, "rbc_c1_eqt", "comp_comp_rbc_c1_eqt",  "rbc_c1_eqt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c1_eqt, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_eqt),
	CashFlowCommonData(353, "rbc_c1_eqt_bef_sale", "comp_comp_rbc_c1_eqt_bef_sale",  "rbc_c1_eqt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c1_eqt_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_eqt_bef_sale),
	CashFlowCommonData(354, "rbc_c2", "comp_comp_rbc_c2",  "rbc_c2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c2, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2),
	CashFlowCommonData(355, "rbc_c3", "comp_comp_rbc_c3",  "rbc_c3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c3, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3),
	CashFlowCommonData(356, "rbc_c4", "comp_comp_rbc_c4",  "rbc_c4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rbc_c4, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c4),
	CashFlowCommonData(357, "realzd_cap_gain", "comp_comp_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(358, "realzd_cap_gain_bef_sale", "comp_comp_realzd_cap_gain_bef_sale",  "realzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_bef_sale),
	CashFlowCommonData(359, "realzd_cap_gain_free_surp", "comp_comp_realzd_cap_gain_free_surp",  "realzd_cap_gain_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_free_surp),
	CashFlowCommonData(360, "realzd_cap_gain_free_surp_bef_sale", "comp_comp_realzd_cap_gain_free_surp_bef_sale",  "realzd_cap_gain_free_surp_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_free_surp_bef_sale),
	CashFlowCommonData(361, "realzd_cap_gain_free_surp_ytd", "comp_comp_realzd_cap_gain_free_surp_ytd",  "realzd_cap_gain_free_surp_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_free_surp_ytd),
	CashFlowCommonData(362, "realzd_cap_gain_free_surp_ytd_bef_sale", "comp_comp_realzd_cap_gain_free_surp_ytd_bef_sale",  "realzd_cap_gain_free_surp_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_free_surp_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_free_surp_ytd_bef_sale),
	CashFlowCommonData(363, "realzd_cap_gain_fund", "comp_comp_realzd_cap_gain_fund",  "realzd_cap_gain_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_fund, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_fund),
	CashFlowCommonData(364, "realzd_cap_gain_res", "comp_comp_realzd_cap_gain_res",  "realzd_cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_res),
	CashFlowCommonData(365, "realzd_cap_gain_res_bef_sale", "comp_comp_realzd_cap_gain_res_bef_sale",  "realzd_cap_gain_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_res_bef_sale),
	CashFlowCommonData(366, "realzd_cap_gain_res_ytd", "comp_comp_realzd_cap_gain_res_ytd",  "realzd_cap_gain_res_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_res_ytd),
	CashFlowCommonData(367, "realzd_cap_gain_res_ytd_bef_sale", "comp_comp_realzd_cap_gain_res_ytd_bef_sale",  "realzd_cap_gain_res_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_res_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_res_ytd_bef_sale),
	CashFlowCommonData(368, "realzd_cap_gain_sale", "comp_comp_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(369, "realzd_cap_gain_tgt_cap", "comp_comp_realzd_cap_gain_tgt_cap",  "realzd_cap_gain_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_tgt_cap),
	CashFlowCommonData(370, "realzd_cap_gain_tgt_cap_bef_sale", "comp_comp_realzd_cap_gain_tgt_cap_bef_sale",  "realzd_cap_gain_tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_tgt_cap_bef_sale),
	CashFlowCommonData(371, "realzd_cap_gain_tgt_cap_ytd", "comp_comp_realzd_cap_gain_tgt_cap_ytd",  "realzd_cap_gain_tgt_cap_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_tgt_cap_ytd),
	CashFlowCommonData(372, "realzd_cap_gain_tgt_cap_ytd_bef_sale", "comp_comp_realzd_cap_gain_tgt_cap_ytd_bef_sale",  "realzd_cap_gain_tgt_cap_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_tgt_cap_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_tgt_cap_ytd_bef_sale),
	CashFlowCommonData(373, "realzd_cap_gain_undistrib_earnings", "comp_comp_realzd_cap_gain_undistrib_earnings",  "realzd_cap_gain_undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_undistrib_earnings),
	CashFlowCommonData(374, "realzd_cap_gain_undistrib_earnings_bef_sale", "comp_comp_realzd_cap_gain_undistrib_earnings_bef_sale",  "realzd_cap_gain_undistrib_earnings_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_undistrib_earnings_bef_sale),
	CashFlowCommonData(375, "realzd_cap_gain_undistrib_earnings_ytd", "comp_comp_realzd_cap_gain_undistrib_earnings_ytd",  "realzd_cap_gain_undistrib_earnings_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_undistrib_earnings_ytd),
	CashFlowCommonData(376, "realzd_cap_gain_undistrib_earnings_ytd_bef_sale", "comp_comp_realzd_cap_gain_undistrib_earnings_ytd_bef_sale",  "realzd_cap_gain_undistrib_earnings_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_realzd_cap_gain_undistrib_earnings_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_undistrib_earnings_ytd_bef_sale),
	CashFlowCommonData(377, "reins_ann_benefits_bom", "comp_comp_reins_ann_benefits_bom",  "reins_ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_ann_benefits_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_ann_benefits_bom),
	CashFlowCommonData(378, "reins_ann_benefits_eom", "comp_comp_reins_ann_benefits_eom",  "reins_ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ann_benefits_eom),
	CashFlowCommonData(379, "reins_cap_gain_res", "comp_comp_reins_cap_gain_res",  "reins_cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cap_gain_res),
	CashFlowCommonData(380, "reins_cap_gain_res_bef_sale", "comp_comp_reins_cap_gain_res_bef_sale",  "reins_cap_gain_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cap_gain_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cap_gain_res_bef_sale),
	CashFlowCommonData(381, "reins_cash_flow_bom", "comp_comp_reins_cash_flow_bom",  "reins_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_bom),
	CashFlowCommonData(382, "reins_cash_flow_eom", "comp_comp_reins_cash_flow_eom",  "reins_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_eom),
	CashFlowCommonData(383, "reins_cash_flow_int", "comp_comp_reins_cash_flow_int",  "reins_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_int),
	CashFlowCommonData(384, "reins_cash_val", "comp_comp_reins_cash_val",  "reins_cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->reins_cash_val),
	CashFlowCommonData(385, "reins_claim_paid", "comp_comp_reins_claim_paid",  "reins_claim_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_claim_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_claim_paid),
	CashFlowCommonData(386, "reins_comm_chargeback_reimb", "comp_comp_reins_comm_chargeback_reimb",  "reins_comm_chargeback_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_comm_chargeback_reimb, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_comm_chargeback_reimb),
	CashFlowCommonData(387, "reins_comm_reimb", "comp_comp_reins_comm_reimb",  "reins_comm_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_comm_reimb, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb),
	CashFlowCommonData(388, "reins_comm_reimb_bom", "comp_comp_reins_comm_reimb_bom",  "reins_comm_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_comm_reimb_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb_bom),
	CashFlowCommonData(389, "reins_comm_reimb_eom", "comp_comp_reins_comm_reimb_eom",  "reins_comm_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_comm_reimb_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb_eom),
	CashFlowCommonData(390, "reins_deferred_gross_prem", "comp_comp_reins_deferred_gross_prem",  "reins_deferred_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_deferred_gross_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_deferred_gross_prem),
	CashFlowCommonData(391, "reins_deferred_gross_prem_incr", "comp_comp_reins_deferred_gross_prem_incr",  "reins_deferred_gross_prem_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_deferred_gross_prem_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_deferred_gross_prem_incr),
	CashFlowCommonData(392, "reins_deferred_net_prem", "comp_comp_reins_deferred_net_prem",  "reins_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_deferred_net_prem),
	CashFlowCommonData(393, "reins_div_applied", "comp_comp_reins_div_applied",  "reins_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_div_applied, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_div_applied),
	CashFlowCommonData(394, "reins_div_liab", "comp_comp_reins_div_liab",  "reins_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_div_liab),
	CashFlowCommonData(395, "reins_div_liab_incr", "comp_comp_reins_div_liab_incr",  "reins_div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_div_liab_incr),
	CashFlowCommonData(396, "reins_div_paid", "comp_comp_reins_div_paid",  "reins_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_div_paid),
	CashFlowCommonData(397, "reins_dth_ben_inf", "comp_comp_reins_dth_ben_inf",  "reins_dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->reins_dth_ben_inf),
	CashFlowCommonData(398, "reins_dth_benefits", "comp_comp_reins_dth_benefits",  "reins_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_dth_benefits),
	CashFlowCommonData(399, "reins_ea", "comp_comp_reins_ea",  "reins_ea",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_ea, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_ea),
	CashFlowCommonData(400, "reins_ea_chargeback", "comp_comp_reins_ea_chargeback",  "reins_ea_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_ea_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ea_chargeback),
	CashFlowCommonData(401, "reins_endow_benefits", "comp_comp_reins_endow_benefits",  "reins_endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_endow_benefits),
	CashFlowCommonData(402, "reins_exp", "comp_comp_reins_exp",  "reins_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp),
	CashFlowCommonData(403, "reins_exp_reimb", "comp_comp_reins_exp_reimb",  "reins_exp_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_exp_reimb, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb),
	CashFlowCommonData(404, "reins_exp_reimb_bom", "comp_comp_reins_exp_reimb_bom",  "reins_exp_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_exp_reimb_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_bom),
	CashFlowCommonData(405, "reins_exp_reimb_eom", "comp_comp_reins_exp_reimb_eom",  "reins_exp_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_exp_reimb_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_eom),
	CashFlowCommonData(406, "reins_gaap_ben_res", "comp_comp_reins_gaap_ben_res",  "reins_gaap_ben_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_ben_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_ben_res),
	CashFlowCommonData(407, "reins_gaap_ben_res_incr", "comp_comp_reins_gaap_ben_res_incr",  "reins_gaap_ben_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_ben_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_ben_res_incr),
	CashFlowCommonData(408, "reins_gaap_cap_gain_res", "comp_comp_reins_gaap_cap_gain_res",  "reins_gaap_cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_cap_gain_res),
	CashFlowCommonData(409, "reins_gaap_capzd_comm_bom", "comp_comp_reins_gaap_capzd_comm_bom",  "reins_gaap_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_capzd_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_comm_bom),
	CashFlowCommonData(410, "reins_gaap_capzd_comm_eom", "comp_comp_reins_gaap_capzd_comm_eom",  "reins_gaap_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_capzd_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_comm_eom),
	CashFlowCommonData(411, "reins_gaap_capzd_prem_bonus", "comp_comp_reins_gaap_capzd_prem_bonus",  "reins_gaap_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_capzd_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_prem_bonus),
	CashFlowCommonData(412, "reins_gaap_cash_flow_int", "comp_comp_reins_gaap_cash_flow_int",  "reins_gaap_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_cash_flow_int),
	CashFlowCommonData(413, "reins_gaap_chg_inc", "comp_comp_reins_gaap_chg_inc",  "reins_gaap_chg_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_chg_inc, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_chg_inc),
	CashFlowCommonData(414, "reins_gaap_claim_res", "comp_comp_reins_gaap_claim_res",  "reins_gaap_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_claim_res),
	CashFlowCommonData(415, "reins_gaap_claim_res_incr", "comp_comp_reins_gaap_claim_res_incr",  "reins_gaap_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_claim_res_incr),
	CashFlowCommonData(416, "reins_gaap_comm_excess_bom", "comp_comp_reins_gaap_comm_excess_bom",  "reins_gaap_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_comm_excess_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_excess_bom),
	CashFlowCommonData(417, "reins_gaap_comm_excess_eom", "comp_comp_reins_gaap_comm_excess_eom",  "reins_gaap_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_comm_excess_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_excess_eom),
	CashFlowCommonData(418, "reins_gaap_comm_trail_bom", "comp_comp_reins_gaap_comm_trail_bom",  "reins_gaap_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_comm_trail_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_trail_bom),
	CashFlowCommonData(419, "reins_gaap_comm_trail_eom", "comp_comp_reins_gaap_comm_trail_eom",  "reins_gaap_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_comm_trail_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_trail_eom),
	CashFlowCommonData(420, "reins_gaap_cost", "comp_comp_reins_gaap_cost",  "reins_gaap_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_cost),
	CashFlowCommonData(421, "reins_gaap_credited_int", "comp_comp_reins_gaap_credited_int",  "reins_gaap_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_credited_int),
	CashFlowCommonData(422, "reins_gaap_dac", "comp_comp_reins_gaap_dac",  "reins_gaap_dac",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_dac, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_dac),
	CashFlowCommonData(423, "reins_gaap_dac_incr", "comp_comp_reins_gaap_dac_incr",  "reins_gaap_dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_dac_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_dac_incr),
	CashFlowCommonData(424, "reins_gaap_deferred_maint_exp", "comp_comp_reins_gaap_deferred_maint_exp",  "reins_gaap_deferred_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_deferred_maint_exp, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_deferred_maint_exp),
	CashFlowCommonData(425, "reins_gaap_deferred_prof_liab", "comp_comp_reins_gaap_deferred_prof_liab",  "reins_gaap_deferred_prof_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_deferred_prof_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_deferred_prof_liab),
	CashFlowCommonData(426, "reins_gaap_deferred_prof_liab_incr", "comp_comp_reins_gaap_deferred_prof_liab_incr",  "reins_gaap_deferred_prof_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_deferred_prof_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_deferred_prof_liab_incr),
	CashFlowCommonData(427, "reins_gaap_div_applied", "comp_comp_reins_gaap_div_applied",  "reins_gaap_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_div_applied, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_div_applied),
	CashFlowCommonData(428, "reins_gaap_div_liab", "comp_comp_reins_gaap_div_liab",  "reins_gaap_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_div_liab),
	CashFlowCommonData(429, "reins_gaap_div_liab_incr", "comp_comp_reins_gaap_div_liab_incr",  "reins_gaap_div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_div_liab_incr),
	CashFlowCommonData(430, "reins_gaap_div_paid", "comp_comp_reins_gaap_div_paid",  "reins_gaap_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_div_paid, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_div_paid),
	CashFlowCommonData(431, "reins_gaap_dth_claim_cost", "comp_comp_reins_gaap_dth_claim_cost",  "reins_gaap_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_dth_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_dth_claim_cost),
	CashFlowCommonData(432, "reins_gaap_inv_inc_res", "comp_comp_reins_gaap_inv_inc_res",  "reins_gaap_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_inv_inc_res),
	CashFlowCommonData(433, "reins_gaap_liab_net", "comp_comp_reins_gaap_liab_net",  "reins_gaap_liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_liab_net, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_liab_net),
	CashFlowCommonData(434, "reins_gaap_loads_deducted", "comp_comp_reins_gaap_loads_deducted",  "reins_gaap_loads_deducted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_loads_deducted, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_loads_deducted),
	CashFlowCommonData(435, "reins_gaap_loads_deferred", "comp_comp_reins_gaap_loads_deferred",  "reins_gaap_loads_deferred",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_loads_deferred, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_loads_deferred),
	CashFlowCommonData(436, "reins_gaap_maint_exp_bom", "comp_comp_reins_gaap_maint_exp_bom",  "reins_gaap_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_bom),
	CashFlowCommonData(437, "reins_gaap_maint_exp_eom", "comp_comp_reins_gaap_maint_exp_eom",  "reins_gaap_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_eom),
	CashFlowCommonData(438, "reins_gaap_maint_exp_res", "comp_comp_reins_gaap_maint_exp_res",  "reins_gaap_maint_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_res),
	CashFlowCommonData(439, "reins_gaap_maint_exp_res_incr", "comp_comp_reins_gaap_maint_exp_res_incr",  "reins_gaap_maint_exp_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_maint_exp_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_res_incr),
	CashFlowCommonData(440, "reins_gaap_modco_liab", "comp_comp_reins_gaap_modco_liab",  "reins_gaap_modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_modco_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_modco_liab),
	CashFlowCommonData(441, "reins_gaap_modco_liab_incr", "comp_comp_reins_gaap_modco_liab_incr",  "reins_gaap_modco_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_modco_liab_incr, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_modco_liab_incr),
	CashFlowCommonData(442, "reins_gaap_modco_res_adj", "comp_comp_reins_gaap_modco_res_adj",  "reins_gaap_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_modco_res_adj),
	CashFlowCommonData(443, "reins_gaap_prem", "comp_comp_reins_gaap_prem",  "reins_gaap_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_prem, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem),
	CashFlowCommonData(444, "reins_gaap_prem_bonus", "comp_comp_reins_gaap_prem_bonus",  "reins_gaap_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_bonus),
	CashFlowCommonData(445, "reins_gaap_prem_tax", "comp_comp_reins_gaap_prem_tax",  "reins_gaap_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_tax),
	CashFlowCommonData(446, "reins_gaap_prem_waiver_res", "comp_comp_reins_gaap_prem_waiver_res",  "reins_gaap_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_prem_waiver_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_waiver_res),
	CashFlowCommonData(447, "reins_gaap_prem_waiver_res_incr", "comp_comp_reins_gaap_prem_waiver_res_incr",  "reins_gaap_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_waiver_res_incr),
	CashFlowCommonData(448, "reins_gaap_recoveries", "comp_comp_reins_gaap_recoveries",  "reins_gaap_recoveries",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_recoveries, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_recoveries),
	CashFlowCommonData(449, "reins_gaap_refund", "comp_comp_reins_gaap_refund",  "reins_gaap_refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_refund, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_refund),
	CashFlowCommonData(450, "reins_gaap_sfas133_liab", "comp_comp_reins_gaap_sfas133_liab",  "reins_gaap_sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_sfas133_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_sfas133_liab),
	CashFlowCommonData(451, "reins_gaap_sfas133_liab_incr", "comp_comp_reins_gaap_sfas133_liab_incr",  "reins_gaap_sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_sfas133_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_sfas133_liab_incr),
	CashFlowCommonData(452, "reins_gaap_sop031_addl_liab", "comp_comp_reins_gaap_sop031_addl_liab",  "reins_gaap_sop031_addl_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_sop031_addl_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_sop031_addl_liab),
	CashFlowCommonData(453, "reins_gaap_sop031_addl_liab_incr", "comp_comp_reins_gaap_sop031_addl_liab_incr",  "reins_gaap_sop031_addl_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_sop031_addl_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_sop031_addl_liab_incr),
	CashFlowCommonData(454, "reins_gaap_surr_inc", "comp_comp_reins_gaap_surr_inc",  "reins_gaap_surr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_surr_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_gaap_surr_inc),
	CashFlowCommonData(455, "reins_gaap_terminal_div", "comp_comp_reins_gaap_terminal_div",  "reins_gaap_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_terminal_div, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_terminal_div),
	CashFlowCommonData(456, "reins_gaap_unearn_rev_liab", "comp_comp_reins_gaap_unearn_rev_liab",  "reins_gaap_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_unearn_rev_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_unearn_rev_liab),
	CashFlowCommonData(457, "reins_gaap_unearn_rev_released", "comp_comp_reins_gaap_unearn_rev_released",  "reins_gaap_unearn_rev_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_unearn_rev_released, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_gaap_unearn_rev_released),
	CashFlowCommonData(458, "reins_gaap_unrealzd_cap_gain_incr", "comp_comp_reins_gaap_unrealzd_cap_gain_incr",  "reins_gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(459, "reins_imr_impact_res", "comp_comp_reins_imr_impact_res",  "reins_imr_impact_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_imr_impact_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_imr_impact_res),
	CashFlowCommonData(460, "reins_imr_impact_res_bef_sale", "comp_comp_reins_imr_impact_res_bef_sale",  "reins_imr_impact_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_imr_impact_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_imr_impact_res_bef_sale),
	CashFlowCommonData(461, "reins_inv_fee_ref", "comp_comp_reins_inv_fee_ref",  "reins_inv_fee_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_inv_fee_ref, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_inv_fee_ref),
	CashFlowCommonData(462, "reins_inv_inc_res", "comp_comp_reins_inv_inc_res",  "reins_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_inv_inc_res),
	CashFlowCommonData(463, "reins_maturity_benefits", "comp_comp_reins_maturity_benefits",  "reins_maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_maturity_benefits),
	CashFlowCommonData(464, "reins_modco_res_adj", "comp_comp_reins_modco_res_adj",  "reins_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_modco_res_adj),
	CashFlowCommonData(465, "reins_prem", "comp_comp_reins_prem",  "reins_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_prem, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem),
	CashFlowCommonData(466, "reins_prem_tax", "comp_comp_reins_prem_tax",  "reins_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_tax),
	CashFlowCommonData(467, "reins_prem_waiver_benefits", "comp_comp_reins_prem_waiver_benefits",  "reins_prem_waiver_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_prem_waiver_benefits, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_waiver_benefits),
	CashFlowCommonData(468, "reins_realzd_cap_gain_res", "comp_comp_reins_realzd_cap_gain_res",  "reins_realzd_cap_gain_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_realzd_cap_gain_res),
	CashFlowCommonData(469, "reins_realzd_cap_gain_res_bef_sale", "comp_comp_reins_realzd_cap_gain_res_bef_sale",  "reins_realzd_cap_gain_res_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_realzd_cap_gain_res_bef_sale),
	CashFlowCommonData(470, "reins_realzd_cap_gain_res_ytd", "comp_comp_reins_realzd_cap_gain_res_ytd",  "reins_realzd_cap_gain_res_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->reins_realzd_cap_gain_res_ytd),
	CashFlowCommonData(471, "reins_realzd_cap_gain_res_ytd_bef_sale", "comp_comp_reins_realzd_cap_gain_res_ytd_bef_sale",  "reins_realzd_cap_gain_res_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_realzd_cap_gain_res_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->reins_realzd_cap_gain_res_ytd_bef_sale),
	CashFlowCommonData(472, "reins_ref", "comp_comp_reins_ref",  "reins_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_ref, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ref),
	CashFlowCommonData(473, "reins_stat_claim_res", "comp_comp_reins_stat_claim_res",  "reins_stat_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_stat_claim_res),
	CashFlowCommonData(474, "reins_stat_claim_res_incr", "comp_comp_reins_stat_claim_res_incr",  "reins_stat_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_claim_res_incr),
	CashFlowCommonData(475, "reins_stat_cost", "comp_comp_reins_stat_cost",  "reins_stat_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_cost),
	CashFlowCommonData(476, "reins_stat_cost_bef_sale", "comp_comp_reins_stat_cost_bef_sale",  "reins_stat_cost_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_cost_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_cost_bef_sale),
	CashFlowCommonData(477, "reins_stat_loading", "comp_comp_reins_stat_loading",  "reins_stat_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_loading, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_loading),
	CashFlowCommonData(478, "reins_stat_loading_incr", "comp_comp_reins_stat_loading_incr",  "reins_stat_loading_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_loading_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_loading_incr),
	CashFlowCommonData(479, "reins_stat_prem_waiver_res", "comp_comp_reins_stat_prem_waiver_res",  "reins_stat_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_stat_prem_waiver_res),
	CashFlowCommonData(480, "reins_stat_prem_waiver_res_incr", "comp_comp_reins_stat_prem_waiver_res_incr",  "reins_stat_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_prem_waiver_res_incr),
	CashFlowCommonData(481, "reins_stat_res", "comp_comp_reins_stat_res",  "reins_stat_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res),
	CashFlowCommonData(482, "reins_stat_res_incr", "comp_comp_reins_stat_res_incr",  "reins_stat_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_res_incr),
	CashFlowCommonData(483, "reins_stat_unearn_prem_res", "comp_comp_reins_stat_unearn_prem_res",  "reins_stat_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_unearn_prem_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_stat_unearn_prem_res),
	CashFlowCommonData(484, "reins_stat_unearn_prem_res_incr", "comp_comp_reins_stat_unearn_prem_res_incr",  "reins_stat_unearn_prem_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_stat_unearn_prem_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_unearn_prem_res_incr),
	CashFlowCommonData(485, "reins_surr_benefits", "comp_comp_reins_surr_benefits",  "reins_surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_surr_benefits),
	CashFlowCommonData(486, "reins_tax_claim_res", "comp_comp_reins_tax_claim_res",  "reins_tax_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_tax_claim_res),
	CashFlowCommonData(487, "reins_tax_claim_res_incr", "comp_comp_reins_tax_claim_res_incr",  "reins_tax_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_claim_res_incr),
	CashFlowCommonData(488, "reins_tax_deferred_net_prem", "comp_comp_reins_tax_deferred_net_prem",  "reins_tax_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_deferred_net_prem),
	CashFlowCommonData(489, "reins_tax_div_liab", "comp_comp_reins_tax_div_liab",  "reins_tax_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_div_liab),
	CashFlowCommonData(490, "reins_tax_div_liab_incr", "comp_comp_reins_tax_div_liab_incr",  "reins_tax_div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_div_liab_incr),
	CashFlowCommonData(491, "reins_tax_loading", "comp_comp_reins_tax_loading",  "reins_tax_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_loading, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_loading),
	CashFlowCommonData(492, "reins_tax_loading_incr", "comp_comp_reins_tax_loading_incr",  "reins_tax_loading_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_loading_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_loading_incr),
	CashFlowCommonData(493, "reins_tax_prem_waiver_res", "comp_comp_reins_tax_prem_waiver_res",  "reins_tax_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_tax_prem_waiver_res),
	CashFlowCommonData(494, "reins_tax_prem_waiver_res_incr", "comp_comp_reins_tax_prem_waiver_res_incr",  "reins_tax_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_prem_waiver_res_incr),
	CashFlowCommonData(495, "reins_tax_res", "comp_comp_reins_tax_res",  "reins_tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_res),
	CashFlowCommonData(496, "reins_tax_res_incr", "comp_comp_reins_tax_res_incr",  "reins_tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_res_incr),
	CashFlowCommonData(497, "reins_tax_unearn_prem_res", "comp_comp_reins_tax_unearn_prem_res",  "reins_tax_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_unearn_prem_res, 'E','N', '3', 'P', (size_t)&modelOffset->reins_tax_unearn_prem_res),
	CashFlowCommonData(498, "reins_tax_unearn_prem_res_incr", "comp_comp_reins_tax_unearn_prem_res_incr",  "reins_tax_unearn_prem_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_tax_unearn_prem_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_unearn_prem_res_incr),
	CashFlowCommonData(499, "reins_terminal_div", "comp_comp_reins_terminal_div",  "reins_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_terminal_div, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_terminal_div),
	CashFlowCommonData(500, "reins_withdrl_benefits", "comp_comp_reins_withdrl_benefits",  "reins_withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_reins_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_withdrl_benefits),
	CashFlowCommonData(501, "rho_convex_hedge_inv_amt", "comp_comp_rho_convex_hedge_inv_amt",  "rho_convex_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_inv_amt),
	CashFlowCommonData(502, "rho_convex_hedge_mkt_val", "comp_comp_rho_convex_hedge_mkt_val",  "rho_convex_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_mkt_val),
	CashFlowCommonData(503, "rho_convex_hedge_mkt_val_incr", "comp_comp_rho_convex_hedge_mkt_val_incr",  "rho_convex_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_mkt_val_incr),
	CashFlowCommonData(504, "rho_convex_hedge_pmt", "comp_comp_rho_convex_hedge_pmt",  "rho_convex_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_pmt),
	CashFlowCommonData(505, "rho_convex_hedge_prof", "comp_comp_rho_convex_hedge_prof",  "rho_convex_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_prof),
	CashFlowCommonData(506, "rho_convex_hedge_sale_amt", "comp_comp_rho_convex_hedge_sale_amt",  "rho_convex_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_sale_amt),
	CashFlowCommonData(507, "rho_convex_hedge_transaction_cost", "comp_comp_rho_convex_hedge_transaction_cost",  "rho_convex_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_convex_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_convex_hedge_transaction_cost),
	CashFlowCommonData(508, "rho_hedge_inv_amt", "comp_comp_rho_hedge_inv_amt",  "rho_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_inv_amt),
	CashFlowCommonData(509, "rho_hedge_mkt_val", "comp_comp_rho_hedge_mkt_val",  "rho_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->rho_hedge_mkt_val),
	CashFlowCommonData(510, "rho_hedge_mkt_val_incr", "comp_comp_rho_hedge_mkt_val_incr",  "rho_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_mkt_val_incr),
	CashFlowCommonData(511, "rho_hedge_pmt", "comp_comp_rho_hedge_pmt",  "rho_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_pmt)
};

const CashFlowCommonData COMP_COMP::mCFStaticData_512[] = 
{
	CashFlowCommonData(512, "rho_hedge_prof", "comp_comp_rho_hedge_prof",  "rho_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_prof),
	CashFlowCommonData(513, "rho_hedge_sale_amt", "comp_comp_rho_hedge_sale_amt",  "rho_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_sale_amt),
	CashFlowCommonData(514, "rho_hedge_transaction_cost", "comp_comp_rho_hedge_transaction_cost",  "rho_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_rho_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->rho_hedge_transaction_cost),
	CashFlowCommonData(515, "risk_free_rate_no_sprd_aig", "comp_comp_risk_free_rate_no_sprd_aig",  "risk_free_rate_no_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_risk_free_rate_no_sprd_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->risk_free_rate_no_sprd_aig),
	CashFlowCommonData(516, "risk_free_rate_with_ic_uel_sprd_aig", "comp_comp_risk_free_rate_with_ic_uel_sprd_aig",  "risk_free_rate_with_ic_uel_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_risk_free_rate_with_ic_uel_sprd_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->risk_free_rate_with_ic_uel_sprd_aig),
	CashFlowCommonData(517, "risk_free_rate_with_no_uel_sprd_aig", "comp_comp_risk_free_rate_with_no_uel_sprd_aig",  "risk_free_rate_with_no_uel_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_risk_free_rate_with_no_uel_sprd_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->risk_free_rate_with_no_uel_sprd_aig),
	CashFlowCommonData(518, "risk_free_rate_with_uel_sprd_aig", "comp_comp_risk_free_rate_with_uel_sprd_aig",  "risk_free_rate_with_uel_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_risk_free_rate_with_uel_sprd_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->risk_free_rate_with_uel_sprd_aig),
	CashFlowCommonData(519, "sale_inc", "comp_comp_sale_inc",  "sale_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_sale_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->sale_inc),
	CashFlowCommonData(520, "sched_prin_pmt", "comp_comp_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_sched_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(521, "shldr_div", "comp_comp_shldr_div",  "shldr_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_shldr_div, 'E','Y', '3', 'C', (size_t)&modelOffset->shldr_div),
	CashFlowCommonData(522, "startup", "comp_comp_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(523, "stat_claim_exp_res", "comp_comp_stat_claim_exp_res",  "stat_claim_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_claim_exp_res, 'E','N', '3', 'P', (size_t)&modelOffset->stat_claim_exp_res),
	CashFlowCommonData(524, "stat_claim_exp_res_incr", "comp_comp_stat_claim_exp_res_incr",  "stat_claim_exp_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_claim_exp_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_claim_exp_res_incr),
	CashFlowCommonData(525, "stat_claim_incurred", "comp_comp_stat_claim_incurred",  "stat_claim_incurred",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_claim_incurred, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_claim_incurred),
	CashFlowCommonData(526, "stat_claim_res", "comp_comp_stat_claim_res",  "stat_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->stat_claim_res),
	CashFlowCommonData(527, "stat_claim_res_incr", "comp_comp_stat_claim_res_incr",  "stat_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_claim_res_incr),
	CashFlowCommonData(528, "stat_loading", "comp_comp_stat_loading",  "stat_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_loading, 'E','N', '3', 'C', (size_t)&modelOffset->stat_loading),
	CashFlowCommonData(529, "stat_loading_incr", "comp_comp_stat_loading_incr",  "stat_loading_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_loading_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_loading_incr),
	CashFlowCommonData(530, "stat_prem_waiver_exp_res", "comp_comp_stat_prem_waiver_exp_res",  "stat_prem_waiver_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_prem_waiver_exp_res, 'E','N', '3', 'P', (size_t)&modelOffset->stat_prem_waiver_exp_res),
	CashFlowCommonData(531, "stat_prem_waiver_exp_res_incr", "comp_comp_stat_prem_waiver_exp_res_incr",  "stat_prem_waiver_exp_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_prem_waiver_exp_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_prem_waiver_exp_res_incr),
	CashFlowCommonData(532, "stat_prem_waiver_res", "comp_comp_stat_prem_waiver_res",  "stat_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->stat_prem_waiver_res),
	CashFlowCommonData(533, "stat_prem_waiver_res_incr", "comp_comp_stat_prem_waiver_res_incr",  "stat_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_prem_waiver_res_incr),
	CashFlowCommonData(534, "stat_res", "comp_comp_stat_res",  "stat_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res),
	CashFlowCommonData(535, "stat_res_carvm_base_aig", "comp_comp_stat_res_carvm_base_aig",  "stat_res_carvm_base_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_carvm_base_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_carvm_base_aig),
	CashFlowCommonData(536, "stat_res_carvm_wb_aig", "comp_comp_stat_res_carvm_wb_aig",  "stat_res_carvm_wb_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_carvm_wb_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_carvm_wb_aig),
	CashFlowCommonData(537, "stat_res_excess", "comp_comp_stat_res_excess",  "stat_res_excess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_excess, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_excess),
	CashFlowCommonData(538, "stat_res_incr", "comp_comp_stat_res_incr",  "stat_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_incr),
	CashFlowCommonData(539, "stat_res_mp", "comp_comp_stat_res_mp",  "stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_mp, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_mp),
	CashFlowCommonData(540, "stat_res_sa", "comp_comp_stat_res_sa",  "stat_res_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_sa, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_sa),
	CashFlowCommonData(541, "stat_res_sa_exp_allow", "comp_comp_stat_res_sa_exp_allow",  "stat_res_sa_exp_allow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_sa_exp_allow, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_sa_exp_allow),
	CashFlowCommonData(542, "stat_res_xol_carvm_aig", "comp_comp_stat_res_xol_carvm_aig",  "stat_res_xol_carvm_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_xol_carvm_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_xol_carvm_aig),
	CashFlowCommonData(543, "stat_res_xol_excess_res_aig", "comp_comp_stat_res_xol_excess_res_aig",  "stat_res_xol_excess_res_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_xol_excess_res_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_xol_excess_res_aig),
	CashFlowCommonData(544, "stat_res_xol_nb_eco_res_aig", "comp_comp_stat_res_xol_nb_eco_res_aig",  "stat_res_xol_nb_eco_res_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_xol_nb_eco_res_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_xol_nb_eco_res_aig),
	CashFlowCommonData(545, "stat_res_xol_pv_nb_ending_amount_aig", "comp_comp_stat_res_xol_pv_nb_ending_amount_aig",  "stat_res_xol_pv_nb_ending_amount_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_res_xol_pv_nb_ending_amount_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_res_xol_pv_nb_ending_amount_aig),
	CashFlowCommonData(546, "stat_unearn_prem_res", "comp_comp_stat_unearn_prem_res",  "stat_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_unearn_prem_res, 'E','Y', '3', 'P', (size_t)&modelOffset->stat_unearn_prem_res),
	CashFlowCommonData(547, "stat_unearn_prem_res_incr", "comp_comp_stat_unearn_prem_res_incr",  "stat_unearn_prem_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_stat_unearn_prem_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_unearn_prem_res_incr),
	CashFlowCommonData(548, "surr_benefits", "comp_comp_surr_benefits",  "surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->surr_benefits),
	CashFlowCommonData(549, "tax", "comp_comp_tax",  "tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->tax),
	CashFlowCommonData(550, "tax_bef_sale", "comp_comp_tax_bef_sale",  "tax_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_bef_sale),
	CashFlowCommonData(551, "tax_bk_prof", "comp_comp_tax_bk_prof",  "tax_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_bk_prof),
	CashFlowCommonData(552, "tax_bk_prof_bef_sale", "comp_comp_tax_bk_prof_bef_sale",  "tax_bk_prof_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_bk_prof_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_bk_prof_bef_sale),
	CashFlowCommonData(553, "tax_bk_prof_ytd", "comp_comp_tax_bk_prof_ytd",  "tax_bk_prof_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_bk_prof_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_bk_prof_ytd),
	CashFlowCommonData(554, "tax_bk_prof_ytd_bef_sale", "comp_comp_tax_bk_prof_ytd_bef_sale",  "tax_bk_prof_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_bk_prof_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->tax_bk_prof_ytd_bef_sale),
	CashFlowCommonData(555, "tax_capzd_prem", "comp_comp_tax_capzd_prem",  "tax_capzd_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_capzd_prem, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem),
	CashFlowCommonData(556, "tax_capzd_prem_amortzn", "comp_comp_tax_capzd_prem_amortzn",  "tax_capzd_prem_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_capzd_prem_amortzn, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem_amortzn),
	CashFlowCommonData(557, "tax_capzd_prem_unamortzd", "comp_comp_tax_capzd_prem_unamortzd",  "tax_capzd_prem_unamortzd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_capzd_prem_unamortzd, 'E','N', '3', 'P', (size_t)&modelOffset->tax_capzd_prem_unamortzd),
	CashFlowCommonData(558, "tax_claim_exp_res", "comp_comp_tax_claim_exp_res",  "tax_claim_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_claim_exp_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_claim_exp_res),
	CashFlowCommonData(559, "tax_claim_res", "comp_comp_tax_claim_res",  "tax_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_claim_res),
	CashFlowCommonData(560, "tax_claim_res_incr", "comp_comp_tax_claim_res_incr",  "tax_claim_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_claim_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_claim_res_incr),
	CashFlowCommonData(561, "tax_deferred_net_prem", "comp_comp_tax_deferred_net_prem",  "tax_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->tax_deferred_net_prem),
	CashFlowCommonData(562, "tax_div_liab", "comp_comp_tax_div_liab",  "tax_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->tax_div_liab),
	CashFlowCommonData(563, "tax_div_liab_incr", "comp_comp_tax_div_liab_incr",  "tax_div_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_div_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_div_liab_incr),
	CashFlowCommonData(564, "tax_earnings_accum", "comp_comp_tax_earnings_accum",  "tax_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_earnings_accum),
	CashFlowCommonData(565, "tax_earnings_accum_ytd", "comp_comp_tax_earnings_accum_ytd",  "tax_earnings_accum_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_earnings_accum_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_earnings_accum_ytd),
	CashFlowCommonData(566, "tax_exempt_inc", "comp_comp_tax_exempt_inc",  "tax_exempt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_exempt_inc, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc),
	CashFlowCommonData(567, "tax_exempt_inc_bk_prof", "comp_comp_tax_exempt_inc_bk_prof",  "tax_exempt_inc_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_exempt_inc_bk_prof, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc_bk_prof),
	CashFlowCommonData(568, "tax_exempt_inc_free_surp", "comp_comp_tax_exempt_inc_free_surp",  "tax_exempt_inc_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_exempt_inc_free_surp, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc_free_surp),
	CashFlowCommonData(569, "tax_exempt_inc_tgt_cap", "comp_comp_tax_exempt_inc_tgt_cap",  "tax_exempt_inc_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_exempt_inc_tgt_cap, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc_tgt_cap),
	CashFlowCommonData(570, "tax_free_surp", "comp_comp_tax_free_surp",  "tax_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_free_surp),
	CashFlowCommonData(571, "tax_free_surp_bef_sale", "comp_comp_tax_free_surp_bef_sale",  "tax_free_surp_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_free_surp_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_free_surp_bef_sale),
	CashFlowCommonData(572, "tax_free_surp_ytd", "comp_comp_tax_free_surp_ytd",  "tax_free_surp_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_free_surp_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_free_surp_ytd),
	CashFlowCommonData(573, "tax_free_surp_ytd_bef_sale", "comp_comp_tax_free_surp_ytd_bef_sale",  "tax_free_surp_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_free_surp_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->tax_free_surp_ytd_bef_sale),
	CashFlowCommonData(574, "tax_loading", "comp_comp_tax_loading",  "tax_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_loading, 'E','N', '3', 'C', (size_t)&modelOffset->tax_loading),
	CashFlowCommonData(575, "tax_loading_incr", "comp_comp_tax_loading_incr",  "tax_loading_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_loading_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_loading_incr),
	CashFlowCommonData(576, "tax_prem_waiver_exp_res", "comp_comp_tax_prem_waiver_exp_res",  "tax_prem_waiver_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_prem_waiver_exp_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_prem_waiver_exp_res),
	CashFlowCommonData(577, "tax_prem_waiver_res", "comp_comp_tax_prem_waiver_res",  "tax_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_prem_waiver_res),
	CashFlowCommonData(578, "tax_prem_waiver_res_incr", "comp_comp_tax_prem_waiver_res_incr",  "tax_prem_waiver_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_prem_waiver_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_prem_waiver_res_incr),
	CashFlowCommonData(579, "tax_res", "comp_comp_tax_res",  "tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_res),
	CashFlowCommonData(580, "tax_res_incr", "comp_comp_tax_res_incr",  "tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_res_incr),
	CashFlowCommonData(581, "tax_tgt_cap", "comp_comp_tax_tgt_cap",  "tax_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_tgt_cap),
	CashFlowCommonData(582, "tax_tgt_cap_bef_sale", "comp_comp_tax_tgt_cap_bef_sale",  "tax_tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_tgt_cap_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_tgt_cap_bef_sale),
	CashFlowCommonData(583, "tax_tgt_cap_ytd", "comp_comp_tax_tgt_cap_ytd",  "tax_tgt_cap_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_tgt_cap_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_tgt_cap_ytd),
	CashFlowCommonData(584, "tax_tgt_cap_ytd_bef_sale", "comp_comp_tax_tgt_cap_ytd_bef_sale",  "tax_tgt_cap_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_tgt_cap_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->tax_tgt_cap_ytd_bef_sale),
	CashFlowCommonData(585, "tax_transfer_to_sa_net", "comp_comp_tax_transfer_to_sa_net",  "tax_transfer_to_sa_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_transfer_to_sa_net, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_transfer_to_sa_net),
	CashFlowCommonData(586, "tax_unearn_prem_res", "comp_comp_tax_unearn_prem_res",  "tax_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_unearn_prem_res, 'E','N', '3', 'P', (size_t)&modelOffset->tax_unearn_prem_res),
	CashFlowCommonData(587, "tax_unearn_prem_res_incr", "comp_comp_tax_unearn_prem_res_incr",  "tax_unearn_prem_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tax_unearn_prem_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_unearn_prem_res_incr),
	CashFlowCommonData(588, "taxable_inc_addn", "comp_comp_taxable_inc_addn",  "taxable_inc_addn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_addn, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_addn),
	CashFlowCommonData(589, "taxable_inc_bk_prof", "comp_comp_taxable_inc_bk_prof",  "taxable_inc_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof),
	CashFlowCommonData(590, "taxable_inc_bk_prof_bef_sale", "comp_comp_taxable_inc_bk_prof_bef_sale",  "taxable_inc_bk_prof_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof_bef_sale),
	CashFlowCommonData(591, "taxable_inc_bk_prof_ytd", "comp_comp_taxable_inc_bk_prof_ytd",  "taxable_inc_bk_prof_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof_ytd),
	CashFlowCommonData(592, "taxable_inc_bk_prof_ytd_bef_sale", "comp_comp_taxable_inc_bk_prof_ytd_bef_sale",  "taxable_inc_bk_prof_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_bk_prof_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof_ytd_bef_sale),
	CashFlowCommonData(593, "taxable_inc_carryfwd_addn_ytd", "comp_comp_taxable_inc_carryfwd_addn_ytd",  "taxable_inc_carryfwd_addn_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_addn_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_addn_ytd),
	CashFlowCommonData(594, "taxable_inc_carryfwd_applied_ytd", "comp_comp_taxable_inc_carryfwd_applied_ytd",  "taxable_inc_carryfwd_applied_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_applied_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_applied_ytd),
	CashFlowCommonData(595, "taxable_inc_carryfwd_avail", "comp_comp_taxable_inc_carryfwd_avail",  "taxable_inc_carryfwd_avail",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_carryfwd_avail, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_avail),
	CashFlowCommonData(596, "taxable_inc_earnings_accum", "comp_comp_taxable_inc_earnings_accum",  "taxable_inc_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_earnings_accum),
	CashFlowCommonData(597, "taxable_inc_earnings_accum_ytd", "comp_comp_taxable_inc_earnings_accum_ytd",  "taxable_inc_earnings_accum_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_earnings_accum_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_earnings_accum_ytd),
	CashFlowCommonData(598, "taxable_inc_free_surp", "comp_comp_taxable_inc_free_surp",  "taxable_inc_free_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_free_surp, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_free_surp),
	CashFlowCommonData(599, "taxable_inc_free_surp_bef_sale", "comp_comp_taxable_inc_free_surp_bef_sale",  "taxable_inc_free_surp_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_free_surp_bef_sale),
	CashFlowCommonData(600, "taxable_inc_free_surp_ytd", "comp_comp_taxable_inc_free_surp_ytd",  "taxable_inc_free_surp_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_free_surp_ytd),
	CashFlowCommonData(601, "taxable_inc_free_surp_ytd_bef_sale", "comp_comp_taxable_inc_free_surp_ytd_bef_sale",  "taxable_inc_free_surp_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_free_surp_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_free_surp_ytd_bef_sale),
	CashFlowCommonData(602, "taxable_inc_tgt_cap", "comp_comp_taxable_inc_tgt_cap",  "taxable_inc_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap),
	CashFlowCommonData(603, "taxable_inc_tgt_cap_bef_sale", "comp_comp_taxable_inc_tgt_cap_bef_sale",  "taxable_inc_tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap_bef_sale),
	CashFlowCommonData(604, "taxable_inc_tgt_cap_ytd", "comp_comp_taxable_inc_tgt_cap_ytd",  "taxable_inc_tgt_cap_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap_ytd),
	CashFlowCommonData(605, "taxable_inc_tgt_cap_ytd_bef_sale", "comp_comp_taxable_inc_tgt_cap_ytd_bef_sale",  "taxable_inc_tgt_cap_ytd_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_taxable_inc_tgt_cap_ytd_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap_ytd_bef_sale),
	CashFlowCommonData(606, "terminal_div", "comp_comp_terminal_div",  "terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->terminal_div),
	CashFlowCommonData(607, "tgt_cap", "comp_comp_tgt_cap",  "tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap),
	CashFlowCommonData(608, "tgt_cap_bef_sale", "comp_comp_tgt_cap_bef_sale",  "tgt_cap_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->tgt_cap_bef_sale),
	CashFlowCommonData(609, "tgt_cap_effect", "comp_comp_tgt_cap_effect",  "tgt_cap_effect",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap_effect, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_effect),
	CashFlowCommonData(610, "tgt_cap_effect_bef_sale", "comp_comp_tgt_cap_effect_bef_sale",  "tgt_cap_effect_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap_effect_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_effect_bef_sale),
	CashFlowCommonData(611, "tgt_cap_incr", "comp_comp_tgt_cap_incr",  "tgt_cap_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_incr),
	CashFlowCommonData(612, "tgt_cap_incr_bef_sale", "comp_comp_tgt_cap_incr_bef_sale",  "tgt_cap_incr_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_tgt_cap_incr_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_incr_bef_sale),
	CashFlowCommonData(613, "transfer_cash_flow_sa_bom", "comp_comp_transfer_cash_flow_sa_bom",  "transfer_cash_flow_sa_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_transfer_cash_flow_sa_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->transfer_cash_flow_sa_bom),
	CashFlowCommonData(614, "transfer_cash_flow_sa_eom", "comp_comp_transfer_cash_flow_sa_eom",  "transfer_cash_flow_sa_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_transfer_cash_flow_sa_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->transfer_cash_flow_sa_eom),
	CashFlowCommonData(615, "transfer_to_sa_net", "comp_comp_transfer_to_sa_net",  "transfer_to_sa_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_transfer_to_sa_net, 'E','Y', '3', 'C', (size_t)&modelOffset->transfer_to_sa_net),
	CashFlowCommonData(616, "undistrib_earnings", "comp_comp_undistrib_earnings",  "undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_undistrib_earnings, 'E','N', '3', 'C', (size_t)&modelOffset->undistrib_earnings),
	CashFlowCommonData(617, "unrealzd_cap_gain_incr", "comp_comp_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(618, "unrealzd_cap_gain_incr_bef_sale", "comp_comp_unrealzd_cap_gain_incr_bef_sale",  "unrealzd_cap_gain_incr_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_incr_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr_bef_sale),
	CashFlowCommonData(619, "unrealzd_cap_gain_released_on_sale", "comp_comp_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(620, "valn_tgt_ag38_8d", "comp_comp_valn_tgt_ag38_8d",  "valn_tgt_ag38_8d",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_ag38_8d, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_ag38_8d),
	CashFlowCommonData(621, "valn_tgt_gaap_sfas120", "comp_comp_valn_tgt_gaap_sfas120",  "valn_tgt_gaap_sfas120",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas120, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_sfas120),
	CashFlowCommonData(622, "valn_tgt_gaap_sfas91", "comp_comp_valn_tgt_gaap_sfas91",  "valn_tgt_gaap_sfas91",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas91, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_sfas91),
	CashFlowCommonData(623, "valn_tgt_gaap_sfas97rd", "comp_comp_valn_tgt_gaap_sfas97rd",  "valn_tgt_gaap_sfas97rd",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sfas97rd, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_sfas97rd),
	CashFlowCommonData(624, "valn_tgt_gaap_sop031", "comp_comp_valn_tgt_gaap_sop031",  "valn_tgt_gaap_sop031",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_gaap_sop031, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_sop031),
	CashFlowCommonData(625, "valn_tgt_hedge_final", "comp_comp_valn_tgt_hedge_final",  "valn_tgt_hedge_final",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_hedge_final, 'E','Y', '3', 'P', (size_t)&modelOffset->valn_tgt_hedge_final),
	CashFlowCommonData(626, "valn_tgt_hedge_shock", "comp_comp_valn_tgt_hedge_shock",  "valn_tgt_hedge_shock",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_hedge_shock, 'E','Y', '3', 'P', (size_t)&modelOffset->valn_tgt_hedge_shock),
	CashFlowCommonData(627, "valn_tgt_pba_pol_res", "comp_comp_valn_tgt_pba_pol_res",  "valn_tgt_pba_pol_res",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_pba_pol_res, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_pba_pol_res),
	CashFlowCommonData(628, "valn_tgt_pba_rbc_std_scen_step2", "comp_comp_valn_tgt_pba_rbc_std_scen_step2",  "valn_tgt_pba_rbc_std_scen_step2",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_pba_rbc_std_scen_step2, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_pba_rbc_std_scen_step2),
	CashFlowCommonData(629, "valn_tgt_pba_scen_amt", "comp_comp_valn_tgt_pba_scen_amt",  "valn_tgt_pba_scen_amt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_valn_tgt_pba_scen_amt, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_pba_scen_amt),
	CashFlowCommonData(630, "vega_hedge_inv_amt", "comp_comp_vega_hedge_inv_amt",  "vega_hedge_inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_inv_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_inv_amt),
	CashFlowCommonData(631, "vega_hedge_mkt_val", "comp_comp_vega_hedge_mkt_val",  "vega_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->vega_hedge_mkt_val),
	CashFlowCommonData(632, "vega_hedge_mkt_val_incr", "comp_comp_vega_hedge_mkt_val_incr",  "vega_hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_mkt_val_incr),
	CashFlowCommonData(633, "vega_hedge_pmt", "comp_comp_vega_hedge_pmt",  "vega_hedge_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_pmt),
	CashFlowCommonData(634, "vega_hedge_prof", "comp_comp_vega_hedge_prof",  "vega_hedge_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_prof, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_prof),
	CashFlowCommonData(635, "vega_hedge_sale_amt", "comp_comp_vega_hedge_sale_amt",  "vega_hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_sale_amt),
	CashFlowCommonData(636, "vega_hedge_transaction_cost", "comp_comp_vega_hedge_transaction_cost",  "vega_hedge_transaction_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_vega_hedge_transaction_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->vega_hedge_transaction_cost),
	CashFlowCommonData(637, "withdrl_benefits", "comp_comp_withdrl_benefits",  "withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->withdrl_benefits),
	CashFlowCommonData(638, "xol_amount_aig", "comp_comp_xol_amount_aig",  "xol_amount_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_xol_amount_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->xol_amount_aig),
	CashFlowCommonData(639, "xol_prem_aig", "comp_comp_xol_prem_aig",  "xol_prem_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&COMP_COMP_UDF::comp_comp_xol_prem_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->xol_prem_aig)
};
const CashFlowCommonData* COMP_COMP::mCFStaticData[] = {
	&COMP_COMP::mCFStaticData_0[0],
	&COMP_COMP::mCFStaticData_0[1],
	&COMP_COMP::mCFStaticData_0[2],
	&COMP_COMP::mCFStaticData_0[3],
	&COMP_COMP::mCFStaticData_0[4],
	&COMP_COMP::mCFStaticData_0[5],
	&COMP_COMP::mCFStaticData_0[6],
	&COMP_COMP::mCFStaticData_0[7],
	&COMP_COMP::mCFStaticData_0[8],
	&COMP_COMP::mCFStaticData_0[9],
	&COMP_COMP::mCFStaticData_0[10],
	&COMP_COMP::mCFStaticData_0[11],
	&COMP_COMP::mCFStaticData_0[12],
	&COMP_COMP::mCFStaticData_0[13],
	&COMP_COMP::mCFStaticData_0[14],
	&COMP_COMP::mCFStaticData_0[15],
	&COMP_COMP::mCFStaticData_0[16],
	&COMP_COMP::mCFStaticData_0[17],
	&COMP_COMP::mCFStaticData_0[18],
	&COMP_COMP::mCFStaticData_0[19],
	&COMP_COMP::mCFStaticData_0[20],
	&COMP_COMP::mCFStaticData_0[21],
	&COMP_COMP::mCFStaticData_0[22],
	&COMP_COMP::mCFStaticData_0[23],
	&COMP_COMP::mCFStaticData_0[24],
	&COMP_COMP::mCFStaticData_0[25],
	&COMP_COMP::mCFStaticData_0[26],
	&COMP_COMP::mCFStaticData_0[27],
	&COMP_COMP::mCFStaticData_0[28],
	&COMP_COMP::mCFStaticData_0[29],
	&COMP_COMP::mCFStaticData_0[30],
	&COMP_COMP::mCFStaticData_0[31],
	&COMP_COMP::mCFStaticData_0[32],
	&COMP_COMP::mCFStaticData_0[33],
	&COMP_COMP::mCFStaticData_0[34],
	&COMP_COMP::mCFStaticData_0[35],
	&COMP_COMP::mCFStaticData_0[36],
	&COMP_COMP::mCFStaticData_0[37],
	&COMP_COMP::mCFStaticData_0[38],
	&COMP_COMP::mCFStaticData_0[39],
	&COMP_COMP::mCFStaticData_0[40],
	&COMP_COMP::mCFStaticData_0[41],
	&COMP_COMP::mCFStaticData_0[42],
	&COMP_COMP::mCFStaticData_0[43],
	&COMP_COMP::mCFStaticData_0[44],
	&COMP_COMP::mCFStaticData_0[45],
	&COMP_COMP::mCFStaticData_0[46],
	&COMP_COMP::mCFStaticData_0[47],
	&COMP_COMP::mCFStaticData_0[48],
	&COMP_COMP::mCFStaticData_0[49],
	&COMP_COMP::mCFStaticData_0[50],
	&COMP_COMP::mCFStaticData_0[51],
	&COMP_COMP::mCFStaticData_0[52],
	&COMP_COMP::mCFStaticData_0[53],
	&COMP_COMP::mCFStaticData_0[54],
	&COMP_COMP::mCFStaticData_0[55],
	&COMP_COMP::mCFStaticData_0[56],
	&COMP_COMP::mCFStaticData_0[57],
	&COMP_COMP::mCFStaticData_0[58],
	&COMP_COMP::mCFStaticData_0[59],
	&COMP_COMP::mCFStaticData_0[60],
	&COMP_COMP::mCFStaticData_0[61],
	&COMP_COMP::mCFStaticData_0[62],
	&COMP_COMP::mCFStaticData_0[63],
	&COMP_COMP::mCFStaticData_0[64],
	&COMP_COMP::mCFStaticData_0[65],
	&COMP_COMP::mCFStaticData_0[66],
	&COMP_COMP::mCFStaticData_0[67],
	&COMP_COMP::mCFStaticData_0[68],
	&COMP_COMP::mCFStaticData_0[69],
	&COMP_COMP::mCFStaticData_0[70],
	&COMP_COMP::mCFStaticData_0[71],
	&COMP_COMP::mCFStaticData_0[72],
	&COMP_COMP::mCFStaticData_0[73],
	&COMP_COMP::mCFStaticData_0[74],
	&COMP_COMP::mCFStaticData_0[75],
	&COMP_COMP::mCFStaticData_0[76],
	&COMP_COMP::mCFStaticData_0[77],
	&COMP_COMP::mCFStaticData_0[78],
	&COMP_COMP::mCFStaticData_0[79],
	&COMP_COMP::mCFStaticData_0[80],
	&COMP_COMP::mCFStaticData_0[81],
	&COMP_COMP::mCFStaticData_0[82],
	&COMP_COMP::mCFStaticData_0[83],
	&COMP_COMP::mCFStaticData_0[84],
	&COMP_COMP::mCFStaticData_0[85],
	&COMP_COMP::mCFStaticData_0[86],
	&COMP_COMP::mCFStaticData_0[87],
	&COMP_COMP::mCFStaticData_0[88],
	&COMP_COMP::mCFStaticData_0[89],
	&COMP_COMP::mCFStaticData_0[90],
	&COMP_COMP::mCFStaticData_0[91],
	&COMP_COMP::mCFStaticData_0[92],
	&COMP_COMP::mCFStaticData_0[93],
	&COMP_COMP::mCFStaticData_0[94],
	&COMP_COMP::mCFStaticData_0[95],
	&COMP_COMP::mCFStaticData_0[96],
	&COMP_COMP::mCFStaticData_0[97],
	&COMP_COMP::mCFStaticData_0[98],
	&COMP_COMP::mCFStaticData_0[99],
	&COMP_COMP::mCFStaticData_0[100],
	&COMP_COMP::mCFStaticData_0[101],
	&COMP_COMP::mCFStaticData_0[102],
	&COMP_COMP::mCFStaticData_0[103],
	&COMP_COMP::mCFStaticData_0[104],
	&COMP_COMP::mCFStaticData_0[105],
	&COMP_COMP::mCFStaticData_0[106],
	&COMP_COMP::mCFStaticData_0[107],
	&COMP_COMP::mCFStaticData_0[108],
	&COMP_COMP::mCFStaticData_0[109],
	&COMP_COMP::mCFStaticData_0[110],
	&COMP_COMP::mCFStaticData_0[111],
	&COMP_COMP::mCFStaticData_0[112],
	&COMP_COMP::mCFStaticData_0[113],
	&COMP_COMP::mCFStaticData_0[114],
	&COMP_COMP::mCFStaticData_0[115],
	&COMP_COMP::mCFStaticData_0[116],
	&COMP_COMP::mCFStaticData_0[117],
	&COMP_COMP::mCFStaticData_0[118],
	&COMP_COMP::mCFStaticData_0[119],
	&COMP_COMP::mCFStaticData_0[120],
	&COMP_COMP::mCFStaticData_0[121],
	&COMP_COMP::mCFStaticData_0[122],
	&COMP_COMP::mCFStaticData_0[123],
	&COMP_COMP::mCFStaticData_0[124],
	&COMP_COMP::mCFStaticData_0[125],
	&COMP_COMP::mCFStaticData_0[126],
	&COMP_COMP::mCFStaticData_0[127],
	&COMP_COMP::mCFStaticData_0[128],
	&COMP_COMP::mCFStaticData_0[129],
	&COMP_COMP::mCFStaticData_0[130],
	&COMP_COMP::mCFStaticData_0[131],
	&COMP_COMP::mCFStaticData_0[132],
	&COMP_COMP::mCFStaticData_0[133],
	&COMP_COMP::mCFStaticData_0[134],
	&COMP_COMP::mCFStaticData_0[135],
	&COMP_COMP::mCFStaticData_0[136],
	&COMP_COMP::mCFStaticData_0[137],
	&COMP_COMP::mCFStaticData_0[138],
	&COMP_COMP::mCFStaticData_0[139],
	&COMP_COMP::mCFStaticData_0[140],
	&COMP_COMP::mCFStaticData_0[141],
	&COMP_COMP::mCFStaticData_0[142],
	&COMP_COMP::mCFStaticData_0[143],
	&COMP_COMP::mCFStaticData_0[144],
	&COMP_COMP::mCFStaticData_0[145],
	&COMP_COMP::mCFStaticData_0[146],
	&COMP_COMP::mCFStaticData_0[147],
	&COMP_COMP::mCFStaticData_0[148],
	&COMP_COMP::mCFStaticData_0[149],
	&COMP_COMP::mCFStaticData_0[150],
	&COMP_COMP::mCFStaticData_0[151],
	&COMP_COMP::mCFStaticData_0[152],
	&COMP_COMP::mCFStaticData_0[153],
	&COMP_COMP::mCFStaticData_0[154],
	&COMP_COMP::mCFStaticData_0[155],
	&COMP_COMP::mCFStaticData_0[156],
	&COMP_COMP::mCFStaticData_0[157],
	&COMP_COMP::mCFStaticData_0[158],
	&COMP_COMP::mCFStaticData_0[159],
	&COMP_COMP::mCFStaticData_0[160],
	&COMP_COMP::mCFStaticData_0[161],
	&COMP_COMP::mCFStaticData_0[162],
	&COMP_COMP::mCFStaticData_0[163],
	&COMP_COMP::mCFStaticData_0[164],
	&COMP_COMP::mCFStaticData_0[165],
	&COMP_COMP::mCFStaticData_0[166],
	&COMP_COMP::mCFStaticData_0[167],
	&COMP_COMP::mCFStaticData_0[168],
	&COMP_COMP::mCFStaticData_0[169],
	&COMP_COMP::mCFStaticData_0[170],
	&COMP_COMP::mCFStaticData_0[171],
	&COMP_COMP::mCFStaticData_0[172],
	&COMP_COMP::mCFStaticData_0[173],
	&COMP_COMP::mCFStaticData_0[174],
	&COMP_COMP::mCFStaticData_0[175],
	&COMP_COMP::mCFStaticData_0[176],
	&COMP_COMP::mCFStaticData_0[177],
	&COMP_COMP::mCFStaticData_0[178],
	&COMP_COMP::mCFStaticData_0[179],
	&COMP_COMP::mCFStaticData_0[180],
	&COMP_COMP::mCFStaticData_0[181],
	&COMP_COMP::mCFStaticData_0[182],
	&COMP_COMP::mCFStaticData_0[183],
	&COMP_COMP::mCFStaticData_0[184],
	&COMP_COMP::mCFStaticData_0[185],
	&COMP_COMP::mCFStaticData_0[186],
	&COMP_COMP::mCFStaticData_0[187],
	&COMP_COMP::mCFStaticData_0[188],
	&COMP_COMP::mCFStaticData_0[189],
	&COMP_COMP::mCFStaticData_0[190],
	&COMP_COMP::mCFStaticData_0[191],
	&COMP_COMP::mCFStaticData_0[192],
	&COMP_COMP::mCFStaticData_0[193],
	&COMP_COMP::mCFStaticData_0[194],
	&COMP_COMP::mCFStaticData_0[195],
	&COMP_COMP::mCFStaticData_0[196],
	&COMP_COMP::mCFStaticData_0[197],
	&COMP_COMP::mCFStaticData_0[198],
	&COMP_COMP::mCFStaticData_0[199],
	&COMP_COMP::mCFStaticData_0[200],
	&COMP_COMP::mCFStaticData_0[201],
	&COMP_COMP::mCFStaticData_0[202],
	&COMP_COMP::mCFStaticData_0[203],
	&COMP_COMP::mCFStaticData_0[204],
	&COMP_COMP::mCFStaticData_0[205],
	&COMP_COMP::mCFStaticData_0[206],
	&COMP_COMP::mCFStaticData_0[207],
	&COMP_COMP::mCFStaticData_0[208],
	&COMP_COMP::mCFStaticData_0[209],
	&COMP_COMP::mCFStaticData_0[210],
	&COMP_COMP::mCFStaticData_0[211],
	&COMP_COMP::mCFStaticData_0[212],
	&COMP_COMP::mCFStaticData_0[213],
	&COMP_COMP::mCFStaticData_0[214],
	&COMP_COMP::mCFStaticData_0[215],
	&COMP_COMP::mCFStaticData_0[216],
	&COMP_COMP::mCFStaticData_0[217],
	&COMP_COMP::mCFStaticData_0[218],
	&COMP_COMP::mCFStaticData_0[219],
	&COMP_COMP::mCFStaticData_0[220],
	&COMP_COMP::mCFStaticData_0[221],
	&COMP_COMP::mCFStaticData_0[222],
	&COMP_COMP::mCFStaticData_0[223],
	&COMP_COMP::mCFStaticData_0[224],
	&COMP_COMP::mCFStaticData_0[225],
	&COMP_COMP::mCFStaticData_0[226],
	&COMP_COMP::mCFStaticData_0[227],
	&COMP_COMP::mCFStaticData_0[228],
	&COMP_COMP::mCFStaticData_0[229],
	&COMP_COMP::mCFStaticData_0[230],
	&COMP_COMP::mCFStaticData_0[231],
	&COMP_COMP::mCFStaticData_0[232],
	&COMP_COMP::mCFStaticData_0[233],
	&COMP_COMP::mCFStaticData_0[234],
	&COMP_COMP::mCFStaticData_0[235],
	&COMP_COMP::mCFStaticData_0[236],
	&COMP_COMP::mCFStaticData_0[237],
	&COMP_COMP::mCFStaticData_0[238],
	&COMP_COMP::mCFStaticData_0[239],
	&COMP_COMP::mCFStaticData_0[240],
	&COMP_COMP::mCFStaticData_0[241],
	&COMP_COMP::mCFStaticData_0[242],
	&COMP_COMP::mCFStaticData_0[243],
	&COMP_COMP::mCFStaticData_0[244],
	&COMP_COMP::mCFStaticData_0[245],
	&COMP_COMP::mCFStaticData_0[246],
	&COMP_COMP::mCFStaticData_0[247],
	&COMP_COMP::mCFStaticData_0[248],
	&COMP_COMP::mCFStaticData_0[249],
	&COMP_COMP::mCFStaticData_0[250],
	&COMP_COMP::mCFStaticData_0[251],
	&COMP_COMP::mCFStaticData_0[252],
	&COMP_COMP::mCFStaticData_0[253],
	&COMP_COMP::mCFStaticData_0[254],
	&COMP_COMP::mCFStaticData_0[255],
	&COMP_COMP::mCFStaticData_256[0],
	&COMP_COMP::mCFStaticData_256[1],
	&COMP_COMP::mCFStaticData_256[2],
	&COMP_COMP::mCFStaticData_256[3],
	&COMP_COMP::mCFStaticData_256[4],
	&COMP_COMP::mCFStaticData_256[5],
	&COMP_COMP::mCFStaticData_256[6],
	&COMP_COMP::mCFStaticData_256[7],
	&COMP_COMP::mCFStaticData_256[8],
	&COMP_COMP::mCFStaticData_256[9],
	&COMP_COMP::mCFStaticData_256[10],
	&COMP_COMP::mCFStaticData_256[11],
	&COMP_COMP::mCFStaticData_256[12],
	&COMP_COMP::mCFStaticData_256[13],
	&COMP_COMP::mCFStaticData_256[14],
	&COMP_COMP::mCFStaticData_256[15],
	&COMP_COMP::mCFStaticData_256[16],
	&COMP_COMP::mCFStaticData_256[17],
	&COMP_COMP::mCFStaticData_256[18],
	&COMP_COMP::mCFStaticData_256[19],
	&COMP_COMP::mCFStaticData_256[20],
	&COMP_COMP::mCFStaticData_256[21],
	&COMP_COMP::mCFStaticData_256[22],
	&COMP_COMP::mCFStaticData_256[23],
	&COMP_COMP::mCFStaticData_256[24],
	&COMP_COMP::mCFStaticData_256[25],
	&COMP_COMP::mCFStaticData_256[26],
	&COMP_COMP::mCFStaticData_256[27],
	&COMP_COMP::mCFStaticData_256[28],
	&COMP_COMP::mCFStaticData_256[29],
	&COMP_COMP::mCFStaticData_256[30],
	&COMP_COMP::mCFStaticData_256[31],
	&COMP_COMP::mCFStaticData_256[32],
	&COMP_COMP::mCFStaticData_256[33],
	&COMP_COMP::mCFStaticData_256[34],
	&COMP_COMP::mCFStaticData_256[35],
	&COMP_COMP::mCFStaticData_256[36],
	&COMP_COMP::mCFStaticData_256[37],
	&COMP_COMP::mCFStaticData_256[38],
	&COMP_COMP::mCFStaticData_256[39],
	&COMP_COMP::mCFStaticData_256[40],
	&COMP_COMP::mCFStaticData_256[41],
	&COMP_COMP::mCFStaticData_256[42],
	&COMP_COMP::mCFStaticData_256[43],
	&COMP_COMP::mCFStaticData_256[44],
	&COMP_COMP::mCFStaticData_256[45],
	&COMP_COMP::mCFStaticData_256[46],
	&COMP_COMP::mCFStaticData_256[47],
	&COMP_COMP::mCFStaticData_256[48],
	&COMP_COMP::mCFStaticData_256[49],
	&COMP_COMP::mCFStaticData_256[50],
	&COMP_COMP::mCFStaticData_256[51],
	&COMP_COMP::mCFStaticData_256[52],
	&COMP_COMP::mCFStaticData_256[53],
	&COMP_COMP::mCFStaticData_256[54],
	&COMP_COMP::mCFStaticData_256[55],
	&COMP_COMP::mCFStaticData_256[56],
	&COMP_COMP::mCFStaticData_256[57],
	&COMP_COMP::mCFStaticData_256[58],
	&COMP_COMP::mCFStaticData_256[59],
	&COMP_COMP::mCFStaticData_256[60],
	&COMP_COMP::mCFStaticData_256[61],
	&COMP_COMP::mCFStaticData_256[62],
	&COMP_COMP::mCFStaticData_256[63],
	&COMP_COMP::mCFStaticData_256[64],
	&COMP_COMP::mCFStaticData_256[65],
	&COMP_COMP::mCFStaticData_256[66],
	&COMP_COMP::mCFStaticData_256[67],
	&COMP_COMP::mCFStaticData_256[68],
	&COMP_COMP::mCFStaticData_256[69],
	&COMP_COMP::mCFStaticData_256[70],
	&COMP_COMP::mCFStaticData_256[71],
	&COMP_COMP::mCFStaticData_256[72],
	&COMP_COMP::mCFStaticData_256[73],
	&COMP_COMP::mCFStaticData_256[74],
	&COMP_COMP::mCFStaticData_256[75],
	&COMP_COMP::mCFStaticData_256[76],
	&COMP_COMP::mCFStaticData_256[77],
	&COMP_COMP::mCFStaticData_256[78],
	&COMP_COMP::mCFStaticData_256[79],
	&COMP_COMP::mCFStaticData_256[80],
	&COMP_COMP::mCFStaticData_256[81],
	&COMP_COMP::mCFStaticData_256[82],
	&COMP_COMP::mCFStaticData_256[83],
	&COMP_COMP::mCFStaticData_256[84],
	&COMP_COMP::mCFStaticData_256[85],
	&COMP_COMP::mCFStaticData_256[86],
	&COMP_COMP::mCFStaticData_256[87],
	&COMP_COMP::mCFStaticData_256[88],
	&COMP_COMP::mCFStaticData_256[89],
	&COMP_COMP::mCFStaticData_256[90],
	&COMP_COMP::mCFStaticData_256[91],
	&COMP_COMP::mCFStaticData_256[92],
	&COMP_COMP::mCFStaticData_256[93],
	&COMP_COMP::mCFStaticData_256[94],
	&COMP_COMP::mCFStaticData_256[95],
	&COMP_COMP::mCFStaticData_256[96],
	&COMP_COMP::mCFStaticData_256[97],
	&COMP_COMP::mCFStaticData_256[98],
	&COMP_COMP::mCFStaticData_256[99],
	&COMP_COMP::mCFStaticData_256[100],
	&COMP_COMP::mCFStaticData_256[101],
	&COMP_COMP::mCFStaticData_256[102],
	&COMP_COMP::mCFStaticData_256[103],
	&COMP_COMP::mCFStaticData_256[104],
	&COMP_COMP::mCFStaticData_256[105],
	&COMP_COMP::mCFStaticData_256[106],
	&COMP_COMP::mCFStaticData_256[107],
	&COMP_COMP::mCFStaticData_256[108],
	&COMP_COMP::mCFStaticData_256[109],
	&COMP_COMP::mCFStaticData_256[110],
	&COMP_COMP::mCFStaticData_256[111],
	&COMP_COMP::mCFStaticData_256[112],
	&COMP_COMP::mCFStaticData_256[113],
	&COMP_COMP::mCFStaticData_256[114],
	&COMP_COMP::mCFStaticData_256[115],
	&COMP_COMP::mCFStaticData_256[116],
	&COMP_COMP::mCFStaticData_256[117],
	&COMP_COMP::mCFStaticData_256[118],
	&COMP_COMP::mCFStaticData_256[119],
	&COMP_COMP::mCFStaticData_256[120],
	&COMP_COMP::mCFStaticData_256[121],
	&COMP_COMP::mCFStaticData_256[122],
	&COMP_COMP::mCFStaticData_256[123],
	&COMP_COMP::mCFStaticData_256[124],
	&COMP_COMP::mCFStaticData_256[125],
	&COMP_COMP::mCFStaticData_256[126],
	&COMP_COMP::mCFStaticData_256[127],
	&COMP_COMP::mCFStaticData_256[128],
	&COMP_COMP::mCFStaticData_256[129],
	&COMP_COMP::mCFStaticData_256[130],
	&COMP_COMP::mCFStaticData_256[131],
	&COMP_COMP::mCFStaticData_256[132],
	&COMP_COMP::mCFStaticData_256[133],
	&COMP_COMP::mCFStaticData_256[134],
	&COMP_COMP::mCFStaticData_256[135],
	&COMP_COMP::mCFStaticData_256[136],
	&COMP_COMP::mCFStaticData_256[137],
	&COMP_COMP::mCFStaticData_256[138],
	&COMP_COMP::mCFStaticData_256[139],
	&COMP_COMP::mCFStaticData_256[140],
	&COMP_COMP::mCFStaticData_256[141],
	&COMP_COMP::mCFStaticData_256[142],
	&COMP_COMP::mCFStaticData_256[143],
	&COMP_COMP::mCFStaticData_256[144],
	&COMP_COMP::mCFStaticData_256[145],
	&COMP_COMP::mCFStaticData_256[146],
	&COMP_COMP::mCFStaticData_256[147],
	&COMP_COMP::mCFStaticData_256[148],
	&COMP_COMP::mCFStaticData_256[149],
	&COMP_COMP::mCFStaticData_256[150],
	&COMP_COMP::mCFStaticData_256[151],
	&COMP_COMP::mCFStaticData_256[152],
	&COMP_COMP::mCFStaticData_256[153],
	&COMP_COMP::mCFStaticData_256[154],
	&COMP_COMP::mCFStaticData_256[155],
	&COMP_COMP::mCFStaticData_256[156],
	&COMP_COMP::mCFStaticData_256[157],
	&COMP_COMP::mCFStaticData_256[158],
	&COMP_COMP::mCFStaticData_256[159],
	&COMP_COMP::mCFStaticData_256[160],
	&COMP_COMP::mCFStaticData_256[161],
	&COMP_COMP::mCFStaticData_256[162],
	&COMP_COMP::mCFStaticData_256[163],
	&COMP_COMP::mCFStaticData_256[164],
	&COMP_COMP::mCFStaticData_256[165],
	&COMP_COMP::mCFStaticData_256[166],
	&COMP_COMP::mCFStaticData_256[167],
	&COMP_COMP::mCFStaticData_256[168],
	&COMP_COMP::mCFStaticData_256[169],
	&COMP_COMP::mCFStaticData_256[170],
	&COMP_COMP::mCFStaticData_256[171],
	&COMP_COMP::mCFStaticData_256[172],
	&COMP_COMP::mCFStaticData_256[173],
	&COMP_COMP::mCFStaticData_256[174],
	&COMP_COMP::mCFStaticData_256[175],
	&COMP_COMP::mCFStaticData_256[176],
	&COMP_COMP::mCFStaticData_256[177],
	&COMP_COMP::mCFStaticData_256[178],
	&COMP_COMP::mCFStaticData_256[179],
	&COMP_COMP::mCFStaticData_256[180],
	&COMP_COMP::mCFStaticData_256[181],
	&COMP_COMP::mCFStaticData_256[182],
	&COMP_COMP::mCFStaticData_256[183],
	&COMP_COMP::mCFStaticData_256[184],
	&COMP_COMP::mCFStaticData_256[185],
	&COMP_COMP::mCFStaticData_256[186],
	&COMP_COMP::mCFStaticData_256[187],
	&COMP_COMP::mCFStaticData_256[188],
	&COMP_COMP::mCFStaticData_256[189],
	&COMP_COMP::mCFStaticData_256[190],
	&COMP_COMP::mCFStaticData_256[191],
	&COMP_COMP::mCFStaticData_256[192],
	&COMP_COMP::mCFStaticData_256[193],
	&COMP_COMP::mCFStaticData_256[194],
	&COMP_COMP::mCFStaticData_256[195],
	&COMP_COMP::mCFStaticData_256[196],
	&COMP_COMP::mCFStaticData_256[197],
	&COMP_COMP::mCFStaticData_256[198],
	&COMP_COMP::mCFStaticData_256[199],
	&COMP_COMP::mCFStaticData_256[200],
	&COMP_COMP::mCFStaticData_256[201],
	&COMP_COMP::mCFStaticData_256[202],
	&COMP_COMP::mCFStaticData_256[203],
	&COMP_COMP::mCFStaticData_256[204],
	&COMP_COMP::mCFStaticData_256[205],
	&COMP_COMP::mCFStaticData_256[206],
	&COMP_COMP::mCFStaticData_256[207],
	&COMP_COMP::mCFStaticData_256[208],
	&COMP_COMP::mCFStaticData_256[209],
	&COMP_COMP::mCFStaticData_256[210],
	&COMP_COMP::mCFStaticData_256[211],
	&COMP_COMP::mCFStaticData_256[212],
	&COMP_COMP::mCFStaticData_256[213],
	&COMP_COMP::mCFStaticData_256[214],
	&COMP_COMP::mCFStaticData_256[215],
	&COMP_COMP::mCFStaticData_256[216],
	&COMP_COMP::mCFStaticData_256[217],
	&COMP_COMP::mCFStaticData_256[218],
	&COMP_COMP::mCFStaticData_256[219],
	&COMP_COMP::mCFStaticData_256[220],
	&COMP_COMP::mCFStaticData_256[221],
	&COMP_COMP::mCFStaticData_256[222],
	&COMP_COMP::mCFStaticData_256[223],
	&COMP_COMP::mCFStaticData_256[224],
	&COMP_COMP::mCFStaticData_256[225],
	&COMP_COMP::mCFStaticData_256[226],
	&COMP_COMP::mCFStaticData_256[227],
	&COMP_COMP::mCFStaticData_256[228],
	&COMP_COMP::mCFStaticData_256[229],
	&COMP_COMP::mCFStaticData_256[230],
	&COMP_COMP::mCFStaticData_256[231],
	&COMP_COMP::mCFStaticData_256[232],
	&COMP_COMP::mCFStaticData_256[233],
	&COMP_COMP::mCFStaticData_256[234],
	&COMP_COMP::mCFStaticData_256[235],
	&COMP_COMP::mCFStaticData_256[236],
	&COMP_COMP::mCFStaticData_256[237],
	&COMP_COMP::mCFStaticData_256[238],
	&COMP_COMP::mCFStaticData_256[239],
	&COMP_COMP::mCFStaticData_256[240],
	&COMP_COMP::mCFStaticData_256[241],
	&COMP_COMP::mCFStaticData_256[242],
	&COMP_COMP::mCFStaticData_256[243],
	&COMP_COMP::mCFStaticData_256[244],
	&COMP_COMP::mCFStaticData_256[245],
	&COMP_COMP::mCFStaticData_256[246],
	&COMP_COMP::mCFStaticData_256[247],
	&COMP_COMP::mCFStaticData_256[248],
	&COMP_COMP::mCFStaticData_256[249],
	&COMP_COMP::mCFStaticData_256[250],
	&COMP_COMP::mCFStaticData_256[251],
	&COMP_COMP::mCFStaticData_256[252],
	&COMP_COMP::mCFStaticData_256[253],
	&COMP_COMP::mCFStaticData_256[254],
	&COMP_COMP::mCFStaticData_256[255],
	&COMP_COMP::mCFStaticData_512[0],
	&COMP_COMP::mCFStaticData_512[1],
	&COMP_COMP::mCFStaticData_512[2],
	&COMP_COMP::mCFStaticData_512[3],
	&COMP_COMP::mCFStaticData_512[4],
	&COMP_COMP::mCFStaticData_512[5],
	&COMP_COMP::mCFStaticData_512[6],
	&COMP_COMP::mCFStaticData_512[7],
	&COMP_COMP::mCFStaticData_512[8],
	&COMP_COMP::mCFStaticData_512[9],
	&COMP_COMP::mCFStaticData_512[10],
	&COMP_COMP::mCFStaticData_512[11],
	&COMP_COMP::mCFStaticData_512[12],
	&COMP_COMP::mCFStaticData_512[13],
	&COMP_COMP::mCFStaticData_512[14],
	&COMP_COMP::mCFStaticData_512[15],
	&COMP_COMP::mCFStaticData_512[16],
	&COMP_COMP::mCFStaticData_512[17],
	&COMP_COMP::mCFStaticData_512[18],
	&COMP_COMP::mCFStaticData_512[19],
	&COMP_COMP::mCFStaticData_512[20],
	&COMP_COMP::mCFStaticData_512[21],
	&COMP_COMP::mCFStaticData_512[22],
	&COMP_COMP::mCFStaticData_512[23],
	&COMP_COMP::mCFStaticData_512[24],
	&COMP_COMP::mCFStaticData_512[25],
	&COMP_COMP::mCFStaticData_512[26],
	&COMP_COMP::mCFStaticData_512[27],
	&COMP_COMP::mCFStaticData_512[28],
	&COMP_COMP::mCFStaticData_512[29],
	&COMP_COMP::mCFStaticData_512[30],
	&COMP_COMP::mCFStaticData_512[31],
	&COMP_COMP::mCFStaticData_512[32],
	&COMP_COMP::mCFStaticData_512[33],
	&COMP_COMP::mCFStaticData_512[34],
	&COMP_COMP::mCFStaticData_512[35],
	&COMP_COMP::mCFStaticData_512[36],
	&COMP_COMP::mCFStaticData_512[37],
	&COMP_COMP::mCFStaticData_512[38],
	&COMP_COMP::mCFStaticData_512[39],
	&COMP_COMP::mCFStaticData_512[40],
	&COMP_COMP::mCFStaticData_512[41],
	&COMP_COMP::mCFStaticData_512[42],
	&COMP_COMP::mCFStaticData_512[43],
	&COMP_COMP::mCFStaticData_512[44],
	&COMP_COMP::mCFStaticData_512[45],
	&COMP_COMP::mCFStaticData_512[46],
	&COMP_COMP::mCFStaticData_512[47],
	&COMP_COMP::mCFStaticData_512[48],
	&COMP_COMP::mCFStaticData_512[49],
	&COMP_COMP::mCFStaticData_512[50],
	&COMP_COMP::mCFStaticData_512[51],
	&COMP_COMP::mCFStaticData_512[52],
	&COMP_COMP::mCFStaticData_512[53],
	&COMP_COMP::mCFStaticData_512[54],
	&COMP_COMP::mCFStaticData_512[55],
	&COMP_COMP::mCFStaticData_512[56],
	&COMP_COMP::mCFStaticData_512[57],
	&COMP_COMP::mCFStaticData_512[58],
	&COMP_COMP::mCFStaticData_512[59],
	&COMP_COMP::mCFStaticData_512[60],
	&COMP_COMP::mCFStaticData_512[61],
	&COMP_COMP::mCFStaticData_512[62],
	&COMP_COMP::mCFStaticData_512[63],
	&COMP_COMP::mCFStaticData_512[64],
	&COMP_COMP::mCFStaticData_512[65],
	&COMP_COMP::mCFStaticData_512[66],
	&COMP_COMP::mCFStaticData_512[67],
	&COMP_COMP::mCFStaticData_512[68],
	&COMP_COMP::mCFStaticData_512[69],
	&COMP_COMP::mCFStaticData_512[70],
	&COMP_COMP::mCFStaticData_512[71],
	&COMP_COMP::mCFStaticData_512[72],
	&COMP_COMP::mCFStaticData_512[73],
	&COMP_COMP::mCFStaticData_512[74],
	&COMP_COMP::mCFStaticData_512[75],
	&COMP_COMP::mCFStaticData_512[76],
	&COMP_COMP::mCFStaticData_512[77],
	&COMP_COMP::mCFStaticData_512[78],
	&COMP_COMP::mCFStaticData_512[79],
	&COMP_COMP::mCFStaticData_512[80],
	&COMP_COMP::mCFStaticData_512[81],
	&COMP_COMP::mCFStaticData_512[82],
	&COMP_COMP::mCFStaticData_512[83],
	&COMP_COMP::mCFStaticData_512[84],
	&COMP_COMP::mCFStaticData_512[85],
	&COMP_COMP::mCFStaticData_512[86],
	&COMP_COMP::mCFStaticData_512[87],
	&COMP_COMP::mCFStaticData_512[88],
	&COMP_COMP::mCFStaticData_512[89],
	&COMP_COMP::mCFStaticData_512[90],
	&COMP_COMP::mCFStaticData_512[91],
	&COMP_COMP::mCFStaticData_512[92],
	&COMP_COMP::mCFStaticData_512[93],
	&COMP_COMP::mCFStaticData_512[94],
	&COMP_COMP::mCFStaticData_512[95],
	&COMP_COMP::mCFStaticData_512[96],
	&COMP_COMP::mCFStaticData_512[97],
	&COMP_COMP::mCFStaticData_512[98],
	&COMP_COMP::mCFStaticData_512[99],
	&COMP_COMP::mCFStaticData_512[100],
	&COMP_COMP::mCFStaticData_512[101],
	&COMP_COMP::mCFStaticData_512[102],
	&COMP_COMP::mCFStaticData_512[103],
	&COMP_COMP::mCFStaticData_512[104],
	&COMP_COMP::mCFStaticData_512[105],
	&COMP_COMP::mCFStaticData_512[106],
	&COMP_COMP::mCFStaticData_512[107],
	&COMP_COMP::mCFStaticData_512[108],
	&COMP_COMP::mCFStaticData_512[109],
	&COMP_COMP::mCFStaticData_512[110],
	&COMP_COMP::mCFStaticData_512[111],
	&COMP_COMP::mCFStaticData_512[112],
	&COMP_COMP::mCFStaticData_512[113],
	&COMP_COMP::mCFStaticData_512[114],
	&COMP_COMP::mCFStaticData_512[115],
	&COMP_COMP::mCFStaticData_512[116],
	&COMP_COMP::mCFStaticData_512[117],
	&COMP_COMP::mCFStaticData_512[118],
	&COMP_COMP::mCFStaticData_512[119],
	&COMP_COMP::mCFStaticData_512[120],
	&COMP_COMP::mCFStaticData_512[121],
	&COMP_COMP::mCFStaticData_512[122],
	&COMP_COMP::mCFStaticData_512[123],
	&COMP_COMP::mCFStaticData_512[124],
	&COMP_COMP::mCFStaticData_512[125],
	&COMP_COMP::mCFStaticData_512[126],
	&COMP_COMP::mCFStaticData_512[127],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for assets_defn                                                                                       
	const ChoicePair assets_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList assets_defnEnumList(2, assets_defnChoicePairs);

	// EnumList for avr_defn                                                                                       
	const ChoicePair avr_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList avr_defnEnumList(2, avr_defnChoicePairs);

	// EnumList for avr_neg_defn                                                                                       
	const ChoicePair avr_neg_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList avr_neg_defnEnumList(2, avr_neg_defnChoicePairs);

	// EnumList for comp_rate_compared_defn                                                                                       
	const ChoicePair comp_rate_compared_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MAXIMUM_RATE, "Maximum Rate")
		,ChoicePair(StrEnum::MINIMUM_RATE, "Minimum Rate")
	};
	const EnumList comp_rate_compared_defnEnumList(2, comp_rate_compared_defnChoicePairs);

	// EnumList for comp_rate_type                                                                                       
	const ChoicePair comp_rate_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SINGLE, "Single")
		,ChoicePair(StrEnum::WEIGHTED, "Weighted")
		,ChoicePair(StrEnum::COMPARED, "Compared")
	};
	const EnumList comp_rate_typeEnumList(3, comp_rate_typeChoicePairs);

	// EnumList for disc_rate_port_yld_defn                                                                                       
	const ChoicePair disc_rate_port_yld_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_TAX, "Before Tax")
		,ChoicePair(StrEnum::AFTER_TAX, "After Tax")
	};
	const EnumList disc_rate_port_yld_defnEnumList(2, disc_rate_port_yld_defnChoicePairs);

	// EnumList for gaap_defn                                                                                       
	const ChoicePair gaap_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gaap_defnEnumList(2, gaap_defnChoicePairs);

	// EnumList for imr_defn                                                                                       
	const ChoicePair imr_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList imr_defnEnumList(2, imr_defnChoicePairs);

	// EnumList for independent_mp_defn                                                                                       
	const ChoicePair independent_mp_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList independent_mp_defnEnumList(2, independent_mp_defnChoicePairs);

	// EnumList for pricing_defn                                                                                       
	const ChoicePair pricing_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList pricing_defnEnumList(2, pricing_defnChoicePairs);

	// EnumList for prof_distribn_mode                                                                                       
	const ChoicePair prof_distribn_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList prof_distribn_modeEnumList(3, prof_distribn_modeChoicePairs);

	// EnumList for sa_res_defn                                                                                       
	const ChoicePair sa_res_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SA_FUND_VALUE, "SA Fund Value")
		,ChoicePair(StrEnum::MIN_SA_FUND_VALUE_AND_BASIC_RESERVE, "Min SA Fund Value And Basic Reserve")
		,ChoicePair(StrEnum::MIN_SA_FUND_VALUE_AND_ALLOCATED_BASIC_RESERVE, "Min SA Fund Value And Allocated Basic Reserve")
	};
	const EnumList sa_res_defnEnumList(3, sa_res_defnChoicePairs);

	// EnumList for tax_addl_res_ag38_8d_defn                                                                                       
	const ChoicePair tax_addl_res_ag38_8d_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NONDEDUCTIBLE, "Nondeductible")
		,ChoicePair(StrEnum::DEDUCTIBLE, "Deductible")
	};
	const EnumList tax_addl_res_ag38_8d_defnEnumList(2, tax_addl_res_ag38_8d_defnChoicePairs);

	// EnumList for tax_loss_treatment                                                                                       
	const ChoicePair tax_loss_treatmentChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::IMMEDIATE_LOSS_RECOGNITION, "Immediate Loss Recognition")
		,ChoicePair(StrEnum::TAX_LOSS_CARRYFORWARD, "Tax Loss Carryforward")
		,ChoicePair(StrEnum::ZERO_TAX, "Zero Tax")
	};
	const EnumList tax_loss_treatmentEnumList(3, tax_loss_treatmentChoicePairs);

	// EnumList for tgt_cap_defn                                                                                       
	const ChoicePair tgt_cap_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList tgt_cap_defnEnumList(2, tgt_cap_defnChoicePairs);

	// EnumList for time_step_defn                                                                                       
	const ChoicePair time_step_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList time_step_defnEnumList(2, time_step_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace COMP_COMP_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(COMP_COMP::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(COMP_COMP::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace COMP_COMP_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void COMP_COMP::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> COMP_COMP::mgr_;

	Attribute::Descriptor COMP_COMP::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"assets_defn", -1, (size_t)&modelOffset->assets_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &assets_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::DOUBLE,	"avr_amortzn_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_amortzn_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STR_ENUM,	"avr_defn", -1, (size_t)&modelOffset->avr_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &avr_defnEnumList, Feature(true)),
	Descriptor(3, Attribute::INT,	"avr_detail_log_final_period", -1, (size_t)&modelOffset->avr_detail_log_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::INT,	"avr_detail_log_start_period", -1, (size_t)&modelOffset->avr_detail_log_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STR_ENUM,	"avr_neg_defn", -1, (size_t)&modelOffset->avr_neg_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &avr_neg_defnEnumList, Feature(true)),
	Descriptor(6, Attribute::STR_ENUM,	"comp_rate_compared_defn", -1, (size_t)&modelOffset->comp_rate_compared_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &comp_rate_compared_defnEnumList, Feature(true)),
	Descriptor(7, Attribute::STRING,	"comp_rate_compared_rate1_id", -1, (size_t)&modelOffset->comp_rate_compared_rate1_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STRING,	"comp_rate_compared_rate2_id", -1, (size_t)&modelOffset->comp_rate_compared_rate2_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"comp_rate_compared_rate3_id", -1, (size_t)&modelOffset->comp_rate_compared_rate3_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::STRING,	"comp_rate_id", -1, (size_t)&modelOffset->comp_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"comp_rate_single_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::INT,	"comp_rate_single_avg_mths", -1, (size_t)&modelOffset->comp_rate_single_avg_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"comp_rate_single_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"comp_rate_single_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"comp_rate_type", -1, (size_t)&modelOffset->comp_rate_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &comp_rate_typeEnumList, Feature(true)),
	Descriptor(16, Attribute::STRING,	"comp_rate_weighted_rate1_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate1_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"comp_rate_weighted_rate1_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate1_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STRING,	"comp_rate_weighted_rate2_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate2_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"comp_rate_weighted_rate2_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate2_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::STRING,	"comp_rate_weighted_rate3_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate3_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"comp_rate_weighted_rate3_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate3_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STRING,	"company_assump_set_id", -1, (size_t)&modelOffset->company_assump_set_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"disc_rate_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STRING,	"disc_rate_id", -1, (size_t)&modelOffset->disc_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::DOUBLE,	"disc_rate_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STR_ENUM,	"disc_rate_port_yld_defn", -1, (size_t)&modelOffset->disc_rate_port_yld_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &disc_rate_port_yld_defnEnumList, Feature(true)),
	Descriptor(27, Attribute::DOUBLE,	"disc_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::DOUBLE,	"disc_rate_sprd_ic_uel_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_ic_uel_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"disc_rate_sprd_no_uel_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_no_uel_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::DOUBLE,	"disc_rate_sprd_uel_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_uel_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"disc_rates_selected", -1, (size_t)&modelOffset->disc_rates_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::DOUBLE,	"distribn_pct_distrib_earnings", Descriptor::NOT_INDEXED, (size_t)&modelOffset->distribn_pct_distrib_earnings,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::DOUBLE,	"distribn_pct_free_surp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->distribn_pct_free_surp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::STRING,	"gaap_assump_set_id", -1, (size_t)&modelOffset->gaap_assump_set_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STR_ENUM,	"gaap_defn", -1, (size_t)&modelOffset->gaap_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gaap_defnEnumList, Feature(true)),
	Descriptor(36, Attribute::DOUBLE,	"imr_amortzn_pct_bond", Descriptor::NOT_INDEXED, (size_t)&modelOffset->imr_amortzn_pct_bond,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::DOUBLE,	"imr_amortzn_pct_mtg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->imr_amortzn_pct_mtg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"imr_amortzn_pct_other", Descriptor::NOT_INDEXED, (size_t)&modelOffset->imr_amortzn_pct_other,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STR_ENUM,	"imr_defn", -1, (size_t)&modelOffset->imr_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &imr_defnEnumList, Feature(true)),
	Descriptor(40, Attribute::STR_ENUM,	"independent_mp_defn", -1, (size_t)&modelOffset->independent_mp_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &independent_mp_defnEnumList, Feature(true)),
	Descriptor(41, Attribute::DOUBLE,	"init_free_surp_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_free_surp_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::STRING,	"loc_assump_set_id", -1, (size_t)&modelOffset->loc_assump_set_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::STRING,	"pba_assump_set_id", -1, (size_t)&modelOffset->pba_assump_set_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::STR_ENUM,	"pricing_defn", -1, (size_t)&modelOffset->pricing_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pricing_defnEnumList, Feature(true)),
	Descriptor(45, Attribute::STR_ENUM,	"prof_distribn_mode", -1, (size_t)&modelOffset->prof_distribn_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prof_distribn_modeEnumList, Feature(true)),
	Descriptor(46, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::DOUBLE,	"rbc_c1_cash_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_cash_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::DOUBLE,	"rbc_c1_concentration_mult_eqt", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_concentration_mult_eqt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::DOUBLE,	"rbc_c1_concentration_mult_other", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_concentration_mult_other,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::DOUBLE,	"rbc_c1_liab_only_stat_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_liab_only_stat_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::DOUBLE,	"rbc_c1_port_size_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_port_size_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::DOUBLE,	"rbc_c1_reins_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_reins_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::DOUBLE,	"rbc_c2_morbid_claim_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c2_morbid_claim_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::DOUBLE,	"rbc_c2_morbid_prem_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c2_morbid_prem_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::DOUBLE,	"rbc_c2_morbid_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c2_morbid_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::DOUBLE,	"rbc_c2_mort_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c2_mort_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::DOUBLE,	"rbc_c3_ann_high_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_high_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::DOUBLE,	"rbc_c3_ann_low_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_low_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::DOUBLE,	"rbc_c3_ann_medium_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_medium_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::DOUBLE,	"rbc_c3_life_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_life_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::DOUBLE,	"rbc_c4_prem_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c4_prem_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::DOUBLE,	"rbc_c4_sa_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c4_sa_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::STR_ENUM,	"sa_res_defn", -1, (size_t)&modelOffset->sa_res_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sa_res_defnEnumList, Feature(true)),
	Descriptor(64, Attribute::STRING,	"segments_selected", -1, (size_t)&modelOffset->segments_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::STR_ENUM,	"tax_addl_res_ag38_8d_defn", -1, (size_t)&modelOffset->tax_addl_res_ag38_8d_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_addl_res_ag38_8d_defnEnumList, Feature(true)),
	Descriptor(66, Attribute::DOUBLE,	"tax_deductible_pct_of_stat_div_liab", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_deductible_pct_of_stat_div_liab,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(67, Attribute::STR_ENUM,	"tax_loss_treatment", -1, (size_t)&modelOffset->tax_loss_treatment,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_loss_treatmentEnumList, Feature(true)),
	Descriptor(68, Attribute::DOUBLE,	"tax_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(69, Attribute::DOUBLE,	"tax_rate_cap_gain", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_rate_cap_gain,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(70, Attribute::DOUBLE,	"taxable_inc_addn_unamortzd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->taxable_inc_addn_unamortzd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(71, Attribute::STR_ENUM,	"tgt_cap_defn", -1, (size_t)&modelOffset->tgt_cap_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tgt_cap_defnEnumList, Feature(true)),
	Descriptor(72, Attribute::DOUBLE,	"tgt_cap_rbc_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tgt_cap_rbc_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::STR_ENUM,	"time_step_defn", -1, (size_t)&modelOffset->time_step_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &time_step_defnEnumList, Feature(true)),
	Descriptor(74, Attribute::STRING,	"valn_periods_selected", -1, (size_t)&modelOffset->valn_periods_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::INT,	"valn_yrs", -1, (size_t)&modelOffset->valn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::INT,	"yrs_aft_sale", -1, (size_t)&modelOffset->yrs_aft_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::INT,	"yrs_to_maturity", -1, (size_t)&modelOffset->yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::SCALAR_INT,	"elapsed_mths_aig", -1, (size_t)&modelOffset->elapsed_mths_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_elapsed_mths_aig)),
	Descriptor(80, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_final_period)),
	Descriptor(81, Attribute::SCALAR_INT,	"prod_type_indicator", -1, (size_t)&modelOffset->prod_type_indicator,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_prod_type_indicator)),
	Descriptor(82, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&COMP_COMP_UDF::comp_comp_proj_date_adj)),
	Descriptor(83, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_proj_start_date)),
	Descriptor(84, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_proj_start_mth)),
	Descriptor(85, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_proj_start_yr)),
	Descriptor(86, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_reins_flag)),
	Descriptor(87, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&COMP_COMP_UDF::comp_comp_start_period)),
	Descriptor(88, Attribute::SCALAR_STRING,	"state_of_world_financial_file_path", -1, (size_t)&modelOffset->state_of_world_financial_file_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&COMP_COMP_UDF::comp_comp_state_of_world_financial_file_path)),
	};

	Attribute::Descriptor* COMP_COMP::descriptorTable[] = {
	&COMP_COMP::descriptor_0[0],
	&COMP_COMP::descriptor_0[1],
	&COMP_COMP::descriptor_0[2],
	&COMP_COMP::descriptor_0[3],
	&COMP_COMP::descriptor_0[4],
	&COMP_COMP::descriptor_0[5],
	&COMP_COMP::descriptor_0[6],
	&COMP_COMP::descriptor_0[7],
	&COMP_COMP::descriptor_0[8],
	&COMP_COMP::descriptor_0[9],
	&COMP_COMP::descriptor_0[10],
	&COMP_COMP::descriptor_0[11],
	&COMP_COMP::descriptor_0[12],
	&COMP_COMP::descriptor_0[13],
	&COMP_COMP::descriptor_0[14],
	&COMP_COMP::descriptor_0[15],
	&COMP_COMP::descriptor_0[16],
	&COMP_COMP::descriptor_0[17],
	&COMP_COMP::descriptor_0[18],
	&COMP_COMP::descriptor_0[19],
	&COMP_COMP::descriptor_0[20],
	&COMP_COMP::descriptor_0[21],
	&COMP_COMP::descriptor_0[22],
	&COMP_COMP::descriptor_0[23],
	&COMP_COMP::descriptor_0[24],
	&COMP_COMP::descriptor_0[25],
	&COMP_COMP::descriptor_0[26],
	&COMP_COMP::descriptor_0[27],
	&COMP_COMP::descriptor_0[28],
	&COMP_COMP::descriptor_0[29],
	&COMP_COMP::descriptor_0[30],
	&COMP_COMP::descriptor_0[31],
	&COMP_COMP::descriptor_0[32],
	&COMP_COMP::descriptor_0[33],
	&COMP_COMP::descriptor_0[34],
	&COMP_COMP::descriptor_0[35],
	&COMP_COMP::descriptor_0[36],
	&COMP_COMP::descriptor_0[37],
	&COMP_COMP::descriptor_0[38],
	&COMP_COMP::descriptor_0[39],
	&COMP_COMP::descriptor_0[40],
	&COMP_COMP::descriptor_0[41],
	&COMP_COMP::descriptor_0[42],
	&COMP_COMP::descriptor_0[43],
	&COMP_COMP::descriptor_0[44],
	&COMP_COMP::descriptor_0[45],
	&COMP_COMP::descriptor_0[46],
	&COMP_COMP::descriptor_0[47],
	&COMP_COMP::descriptor_0[48],
	&COMP_COMP::descriptor_0[49],
	&COMP_COMP::descriptor_0[50],
	&COMP_COMP::descriptor_0[51],
	&COMP_COMP::descriptor_0[52],
	&COMP_COMP::descriptor_0[53],
	&COMP_COMP::descriptor_0[54],
	&COMP_COMP::descriptor_0[55],
	&COMP_COMP::descriptor_0[56],
	&COMP_COMP::descriptor_0[57],
	&COMP_COMP::descriptor_0[58],
	&COMP_COMP::descriptor_0[59],
	&COMP_COMP::descriptor_0[60],
	&COMP_COMP::descriptor_0[61],
	&COMP_COMP::descriptor_0[62],
	&COMP_COMP::descriptor_0[63],
	&COMP_COMP::descriptor_0[64],
	&COMP_COMP::descriptor_0[65],
	&COMP_COMP::descriptor_0[66],
	&COMP_COMP::descriptor_0[67],
	&COMP_COMP::descriptor_0[68],
	&COMP_COMP::descriptor_0[69],
	&COMP_COMP::descriptor_0[70],
	&COMP_COMP::descriptor_0[71],
	&COMP_COMP::descriptor_0[72],
	&COMP_COMP::descriptor_0[73],
	&COMP_COMP::descriptor_0[74],
	&COMP_COMP::descriptor_0[75],
	&COMP_COMP::descriptor_0[76],
	&COMP_COMP::descriptor_0[77],
	&COMP_COMP::descriptor_0[78],
	&COMP_COMP::descriptor_0[79],
	&COMP_COMP::descriptor_0[80],
	&COMP_COMP::descriptor_0[81],
	&COMP_COMP::descriptor_0[82],
	&COMP_COMP::descriptor_0[83],
	&COMP_COMP::descriptor_0[84],
	&COMP_COMP::descriptor_0[85],
	&COMP_COMP::descriptor_0[86],
	&COMP_COMP::descriptor_0[87],
	&COMP_COMP::descriptor_0[88],
	nullptr};
	const size_t COMP_COMP::sDescriptorCount = 89;

//factory
COMP_COMP* COMP_COMP::makeThis(int isSubmodel, ModelClass* owner, COMP_COMP* peer, 
						int mainRebase, const xstring &name, COMP_COMP_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("COMP_COMP::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor COMP_COMP");
#endif
	COMP_COMP* newP = (COMP_COMP*)new COMP_COMP_UDF
   	  ("comp_comp", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|rates") == unusedModels.end()) {
	newP->sm_rates = RATES_ECONOMY::makeThis(1, newP, peer?peer->sm_rates:0, mainRebase, name + "|rates", (RATES_ECONOMY_persistent_object*)(arrayTemplate?arrayTemplate->sm_rates:0));
	newP->adopt(newP->sm_rates);
	}

	newP->sm_seg.setPersistentObject(SEG_COMP_persistent_object::makeThis(1, newP, (SEG_COMP*)(peer?peer->sm_seg.getPersistentObject():0), mainRebase, name + "|seg", arrayTemplate?arrayTemplate->sm_seg.getPersistentObject():0, false));

	newP->sm_inv_strategy.setPersistentObject(INVSTRAT_ASSET_persistent_object::makeThis(1, newP, (INVSTRAT_ASSET*)(peer?peer->sm_inv_strategy.getPersistentObject():0), mainRebase, name + "|inv_strategy", arrayTemplate?arrayTemplate->sm_inv_strategy.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|asset") == unusedModels.end()) {
	newP->sm_asset = ASSET_ASSET::makeThis(1, newP, peer?peer->sm_asset:0, mainRebase, name + "|asset", (ASSET_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_asset:0));
	newP->adopt(newP->sm_asset);
	}

	if (find(unusedModels.begin(), unusedModels.end(), name + "|liab") == unusedModels.end()) {
	newP->sm_liab = LIAB_LIAB::makeThis(1, newP, peer?peer->sm_liab:0, mainRebase, name + "|liab", (LIAB_LIAB_persistent_object*)(arrayTemplate?arrayTemplate->sm_liab:0));
	newP->adopt(newP->sm_liab);
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
COMP_COMP_persistent_object* COMP_COMP_persistent_object::makeThis(int isSubmodel, ModelClass* owner, COMP_COMP* peer, 
							int mainRebase, const xstring &name, COMP_COMP_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("COMP_COMP_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor COMP_COMP_persistent_object");
#endif
	COMP_COMP_persistent_object* newP = (COMP_COMP_persistent_object*)new COMP_COMP_persistent_object
   	  ("comp_comp", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			COMP_COMP_persistent_object* pd = dynamic_cast<COMP_COMP_persistent_object*>(product);
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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|rates") == unusedModels.end()) {
	newP->sm_rates = (RATES_ECONOMY*)RATES_ECONOMY_persistent_object::makeThis(1, newP, peer?peer->sm_rates:0, mainRebase, name + "|rates", (RATES_ECONOMY_persistent_object*)(arrayTemplate?arrayTemplate->sm_rates:0), fixedArray);
	newP->adopt(newP->sm_rates);
	}

	newP->sm_seg.setPersistentObject(SEG_COMP_persistent_object::makeThis(1, newP, (SEG_COMP*)(peer?peer->sm_seg.getPersistentObject():0), mainRebase, name + "|seg", arrayTemplate?arrayTemplate->sm_seg.getPersistentObject():0, false));

	newP->sm_inv_strategy.setPersistentObject(INVSTRAT_ASSET_persistent_object::makeThis(1, newP, (INVSTRAT_ASSET*)(peer?peer->sm_inv_strategy.getPersistentObject():0), mainRebase, name + "|inv_strategy", arrayTemplate?arrayTemplate->sm_inv_strategy.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|asset") == unusedModels.end()) {
	newP->sm_asset = (ASSET_ASSET*)ASSET_ASSET_persistent_object::makeThis(1, newP, peer?peer->sm_asset:0, mainRebase, name + "|asset", (ASSET_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_asset:0), fixedArray);
	newP->adopt(newP->sm_asset);
	}

	if (find(unusedModels.begin(), unusedModels.end(), name + "|liab") == unusedModels.end()) {
	newP->sm_liab = (LIAB_LIAB*)LIAB_LIAB_persistent_object::makeThis(1, newP, peer?peer->sm_liab:0, mainRebase, name + "|liab", (LIAB_LIAB_persistent_object*)(arrayTemplate?arrayTemplate->sm_liab:0), fixedArray);
	newP->adopt(newP->sm_liab);
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (COMP_COMP_UDF::*dPF) ();
typedef double (COMP_COMP_UDF::*dPFd) (double);
typedef int (COMP_COMP_UDF::*iPF) ();
typedef int (COMP_COMP_UDF::*iPFi) (int);
typedef xstring (COMP_COMP_UDF::*sPF) ();
typedef xstring (COMP_COMP_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
COMP_COMP::COMP_COMP(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_asset(0)
  , sm_inv_strategy(0, 0, 0)
  , sm_liab(0)
  , sm_rates(0)
  , sm_seg(0, 0, 0)
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
	, fia_bond_aig(company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
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
	typedef double (COMP_COMP_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
COMP_COMP::COMP_COMP(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(639, COMP_COMP::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_asset(0)
  , sm_inv_strategy(0, 0, 0)
  , sm_liab(0)
  , sm_rates(0)
  , sm_seg(0, 0, 0)
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
	, fia_bond_aig(company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
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

		adopt(&sm_inv_strategy);
		adopt(&sm_seg);

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
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
       company_liab_fia_fia_bond_portfolio_aig = 0;
#endif
#ifdef __CREATE_BOND_AIG_CLASS_
       company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig = 0;
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

	for (int cf_no = 1; cf_no <= 639; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (COMP_COMP_UDF::*dPXi2) (int, int);
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


 void COMP_COMP::copy_names() {

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
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
		company_liab_fia_fia_bond_portfolio_aig = (BOND_PORTFOLIO_AIG*)(findUnique("company|liab|fia|fia_bond_portfolio_aig"));
#endif
#ifdef __CREATE_BOND_AIG_CLASS_
		company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig = (BOND_AIG*)(findUnique("company|liab|fia|fia_bond_portfolio_aig|fia_bond_aig"));
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


 void COMP_COMP::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int COMP_COMP_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& COMP_COMP_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double COMP_COMP_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int COMP_COMP_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double COMP_COMP_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double COMP_COMP_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void COMP_COMP_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void COMP_COMP_persistent_object::write(long include_submodels) {
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

	void COMP_COMP_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void COMP_COMP_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void COMP_COMP_persistent_object::write(const xstring& key, long include_submodels) {
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




	COMP_COMP_persistent_object::~COMP_COMP_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool COMP_COMP_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void COMP_COMP_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void COMP_COMP_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void COMP_COMP_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void COMP_COMP_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void COMP_COMP_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* COMP_COMP_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* COMP_COMP_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* COMP_COMP_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char COMP_COMP_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void COMP_COMP_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
COMP_COMP_persistent_object::COMP_COMP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			COMP_COMP(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(COMP_COMP::sm_bond_is)
	, sm_bond_pv(COMP_COMP::sm_bond_pv)
	, sm_bond_ym(COMP_COMP::sm_bond_ym)
	, sm_mtg_is(COMP_COMP::sm_mtg_is)
	, sm_mtg_pv(COMP_COMP::sm_mtg_pv)
	, sm_mtg_ym(COMP_COMP::sm_mtg_ym)

	, sm_asset(COMP_COMP::sm_asset)
	, sm_inv_strategy(COMP_COMP::sm_inv_strategy)
	, sm_liab(COMP_COMP::sm_liab)
	, sm_rates(COMP_COMP::sm_rates)
	, sm_seg(COMP_COMP::sm_seg)
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
COMP_COMP::~COMP_COMP() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
//	ModelClass* inv_strategy_persObj = sm_inv_strategy.getPersistentObject();
//	doAdopt(inv_strategy_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_inv_strategy.IsValidSubModelOfBaseModelClass()){
		sm_inv_strategy.resize(0);
		delete sm_inv_strategy.getPersistentObject();
		sm_inv_strategy.mPersistentObj = 0;
	}

//	ModelClass* seg_persObj = sm_seg.getPersistentObject();
//	doAdopt(seg_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_seg.IsValidSubModelOfBaseModelClass()){
		sm_seg.resize(0);
		delete sm_seg.getPersistentObject();
		sm_seg.mPersistentObj = 0;
	}

}
//destructor END@2
void COMP_COMP::findTargetColumns() {

}
//findTargetColumns END@2
void COMP_COMP::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void COMP_COMP::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void COMP_COMP::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void COMP_COMP::start_of_projection() {
}
//start_of_projection END@2

void COMP_COMP::end_of_projection() {
}
//end_of_projection END@2

void COMP_COMP::start_of_layer() {
}


void COMP_COMP::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void COMP_COMP::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void COMP_COMP::after_startup(int decrement) {
// Call startup for submodels
  if(sm_rates)
   sm_rates->doBeforeStartupProcessing(decrement);

	   sm_seg.doBeforeStartupProcessing(decrement);

	   sm_inv_strategy.doBeforeStartupProcessing(decrement);

  if(sm_asset)
   sm_asset->doBeforeStartupProcessing(decrement);

  if(sm_liab)
   sm_liab->doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void COMP_COMP::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> COMP_COMP::ddfVector;
BitArray COMP_COMP::dataVariables(89);
bool COMP_COMP::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool COMP_COMP::writeClassInfo = true;

void COMP_COMP::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, COMP_COMP::descriptor_0>::dT = COMP_COMP::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, COMP_COMP::descriptor_0>::dT = COMP_COMP::descriptor_0;

