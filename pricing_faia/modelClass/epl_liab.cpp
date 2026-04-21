
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
#include "ModelClass\epl_liab_udf.h"
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
#ifndef epl_liab_TableDefs
#define epl_liab_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection EPL_LIAB::TTHC;
void EPL_LIAB::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - acq_exp
// Acquisition Expenses                                                                                             
// Column:ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"acq_exp",t);
}



//^^^

#line 1 "acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ag48_npr_net
// AG48 Net Premium Reserve Net                                                                                             
// Column:AG48_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_ag48_npr_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"ag48_npr_net",t);
}



//^^^

#line 1 "ag48_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("ag48_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ag48_unearn_prem_res_npr_net
// AG48 Unearned Premium Reserve NPR Net                                                                                             
// Column:AG48_UNEARN_PREM_RES_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_ag48_unearn_prem_res_npr_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"ag48_unearn_prem_res_npr_net",t);
}



//^^^

#line 1 "ag48_unearn_prem_res_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("ag48_unearn_prem_res_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ann_benefits_bom
// Annuity Benefits Beginning of Month                                                                                             
// Column:ANN_BENEFITS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_ann_benefits_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"ann_benefits_bom",t);
}



//^^^

#line 1 "ann_benefits_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("ann_benefits_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ann_benefits_eom
// Annuity Benefits End of Month                                                                                             
// Column:ANN_BENEFITS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"ann_benefits_eom",t);
}



//^^^

#line 1 "ann_benefits_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("ann_benefits_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ann_pba_reins_res
// Annuity PBA Reinsurance Reserve                                                                                             
// Column:ANN_PBA_REINS_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_ann_pba_reins_res(int t) {
//^^^



//^^^

#line 1 "ann_pba_reins_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("ann_pba_reins_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - ann_pba_working_res
// Annuity PBA Working Reserve                                                                                             
// Column:ANN_PBA_WORKING_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_ann_pba_working_res(int t) {
//^^^



//^^^

#line 1 "ann_pba_working_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("ann_pba_working_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - annuitzn_consideration
// Annuitization Consideration                                                                                             
// Column:ANNUITZN_CONSIDERATION
//========================================================
double EPL_LIAB_UDF::epl_liab_annuitzn_consideration(int t) {
//^^^



//^^^

#line 1 "annuitzn_consideration.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("annuitzn_consideration", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - annuitzn_val_released
// Annuitization Value Released                                                                                             
// Column:ANNUITZN_VAL_RELEASED
//========================================================
double EPL_LIAB_UDF::epl_liab_annuitzn_val_released(int t) {
//^^^



//^^^

#line 1 "annuitzn_val_released.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("annuitzn_val_released", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - cash_val
// Cash Value                                                                                             
// Column:CASH_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"cash_val",t);
}



//^^^

#line 1 "cash_val.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("cash_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - claim_paid
// Claim Paid                                                                                             
// Column:CLAIM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_claim_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"claim_paid",t);
}



//^^^

#line 1 "claim_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("claim_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - comm_bom
// Commissions Beginning of Month                                                                                             
// Column:COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"comm_bom",t);
}



//^^^

#line 1 "comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - comm_chargeback
// Commission Chargeback                                                                                             
// Column:COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_comm_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"comm_chargeback",t);
}



//^^^

#line 1 "comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - comm_eom
// Commissions End of Month                                                                                             
// Column:COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"comm_eom",t);
}



//^^^

#line 1 "comm_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - conversion_cost
// Conversion Cost                                                                                             
// Column:CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_conversion_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"conversion_cost",t);
}



//^^^

#line 1 "conversion_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - deferred_gross_prem
// Deferred Gross Premium                                                                                             
// Column:DEFERRED_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_deferred_gross_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"deferred_gross_prem",t);
}



//^^^

#line 1 "deferred_gross_prem.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("deferred_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - deferred_net_prem
// Deferred Net Premium                                                                                             
// Column:DEFERRED_NET_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"deferred_net_prem",t);
}



//^^^

#line 1 "deferred_net_prem.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("deferred_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - deferred_net_prem_net
// Deferred Net Premium Net                                                                                             
// Column:DEFERRED_NET_PREM_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_deferred_net_prem_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"deferred_net_prem_net",t);
}



//^^^

#line 1 "deferred_net_prem_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("deferred_net_prem_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - deferred_net_prem_npr
// Deferred Net Premium NPR                                                                                             
// Column:DEFERRED_NET_PREM_NPR
//========================================================
double EPL_LIAB_UDF::epl_liab_deferred_net_prem_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"deferred_net_prem_npr",t);
}



//^^^

#line 1 "deferred_net_prem_npr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("deferred_net_prem_npr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - deferred_net_prem_npr_net
// Deferred Net Premium NPR Net                                                                                             
// Column:DEFERRED_NET_PREM_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_deferred_net_prem_npr_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"deferred_net_prem_npr_net",t);
}



//^^^

#line 1 "deferred_net_prem_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("deferred_net_prem_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - div_applied
// Dividend Applied                                                                                             
// Column:DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"div_applied",t);
}



//^^^

#line 1 "div_applied.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - div_liab
// Dividend Liability                                                                                             
// Column:DIV_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"div_liab",t);
}



//^^^

#line 1 "div_liab.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("div_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - div_paid
// Dividend Paid                                                                                             
// Column:DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"div_paid",t);
}



//^^^

#line 1 "div_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - dth_ben_inf
// Death Benefit In Force                                                                                             
// Column:DTH_BEN_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"dth_ben_inf",t);
}



//^^^

#line 1 "dth_ben_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("dth_ben_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - dth_benefits
// Death Benefits                                                                                             
// Column:DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"dth_benefits",t);
}



//^^^

#line 1 "dth_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - endow_benefits
// Endowment Benefits                                                                                             
// Column:ENDOW_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"endow_benefits",t);
}



//^^^

#line 1 "endow_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("endow_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - fund_val_fixed
// Fund Value Fixed Account                                                                                             
// Column:FUND_VAL_FIXED
//========================================================
double EPL_LIAB_UDF::epl_liab_fund_val_fixed(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"fund_val_fixed",t);
}



//^^^

#line 1 "fund_val_fixed.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("fund_val_fixed", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - fund_val_sa
// Fund Value Separate Account                                                                                             
// Column:FUND_VAL_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_fund_val_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"fund_val_sa",t);
}



//^^^

#line 1 "fund_val_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("fund_val_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - gross_prem_annualzd
// Gross Premium Annualized                                                                                             
// Column:GROSS_PREM_ANNUALZD
//========================================================
double EPL_LIAB_UDF::epl_liab_gross_prem_annualzd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"gross_prem_annualzd",t);
}



//^^^

#line 1 "gross_prem_annualzd.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("gross_prem_annualzd", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flows                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("hedge_cash_flow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - hedge_mkt_val
// Market Value of Hedges                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("hedge_mkt_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - hedge_mkt_val_growth
// Hedge Market Value Growth                                                                                             
// Column:HEDGE_MKT_VAL_GROWTH
//========================================================
double EPL_LIAB_UDF::epl_liab_hedge_mkt_val_growth(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_growth.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("hedge_mkt_val_growth", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - inv_fee_ref
// Investment Fee Refund                                                                                             
// Column:INV_FEE_REF
//========================================================
double EPL_LIAB_UDF::epl_liab_inv_fee_ref(int t) {
//^^^



//^^^

#line 1 "inv_fee_ref.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("inv_fee_ref", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_ag48_npr_net
// Life PBA AG48 Net Premium Reserve Net                                                                                             
// Column:LIFE_PBA_AG48_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_ag48_npr_net(int t) {
//^^^



//^^^

#line 1 "life_pba_ag48_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_ag48_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_ag48_unearn_prem_res_npr_net
// Life PBA AG48 Unearned Premium Reserve NPR Net                                                                                             
// Column:LIFE_PBA_AG48_UNEARN_PREM_RES_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_ag48_unearn_prem_res_npr_net(int t) {
//^^^



//^^^

#line 1 "life_pba_ag48_unearn_prem_res_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_ag48_unearn_prem_res_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_asset_sa
// Life PBA Asset Separate Account                                                                                             
// Column:LIFE_PBA_ASSET_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_asset_sa(int t) {
//^^^



//^^^

#line 1 "life_pba_asset_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_asset_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_direct_cash_flow_bom
// Life PBA Direct Cash Flow Beginning of Month                                                                                             
// Column:LIFE_PBA_DIRECT_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_direct_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "life_pba_direct_cash_flow_bom.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_direct_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_direct_cash_flow_eom
// Life PBA Direct Cash Flow End of Month                                                                                             
// Column:LIFE_PBA_DIRECT_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_direct_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "life_pba_direct_cash_flow_eom.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_direct_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_gpr_ceded
// Life PBA Gross Premium Reserve Ceded                                                                                             
// Column:LIFE_PBA_GPR_CEDED
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_gpr_ceded(int t) {
//^^^



//^^^

#line 1 "life_pba_gpr_ceded.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_gpr_ceded", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_gpr_gross
// Life PBA Gross Premium Reserve Gross                                                                                             
// Column:LIFE_PBA_GPR_GROSS
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_gpr_gross(int t) {
//^^^



//^^^

#line 1 "life_pba_gpr_gross.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_gpr_gross", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_gpr_units_inf
// Life PBA Gross Premium Reserve Units in Force                                                                                             
// Column:LIFE_PBA_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "life_pba_gpr_units_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_pol_loan
// Life PBA Policy Loan                                                                                             
// Column:LIFE_PBA_POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_pol_loan(int t) {
//^^^



//^^^

#line 1 "life_pba_pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_pol_loan_int
// Life PBA Policy Loan Interest                                                                                             
// Column:LIFE_PBA_POL_LOAN_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_pol_loan_int(int t) {
//^^^



//^^^

#line 1 "life_pba_pol_loan_int.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_pol_loan_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_reins_cash_flow_bom
// Life PBA Reinsurance Cash Flow Beginning of Month                                                                                             
// Column:LIFE_PBA_REINS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_reins_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "life_pba_reins_cash_flow_bom.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_reins_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_reins_cash_flow_eom
// Life PBA Reinsurance Cash Flow End of Month                                                                                             
// Column:LIFE_PBA_REINS_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_reins_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "life_pba_reins_cash_flow_eom.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_reins_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_reins_res
// Life PBA Reinsurance Reserve                                                                                             
// Column:LIFE_PBA_REINS_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_reins_res(int t) {
//^^^



//^^^

#line 1 "life_pba_reins_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("life_pba_reins_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_reins_res_sa
// Life PBA Reinsurance Reserve Separate Account                                                                                             
// Column:LIFE_PBA_REINS_RES_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_reins_res_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"life_pba_reins_res_sa",t);
}



//^^^

#line 1 "life_pba_reins_res_sa.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("life_pba_reins_res_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_stat_res_mp
// Life PBA Statutory Reserve Model Point                                                                                             
// Column:LIFE_PBA_STAT_RES_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_stat_res_mp(int t) {
//^^^



//^^^

#line 1 "life_pba_stat_res_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_stat_res_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_stat_res_net_mp
// Life PBA Statutory Reserve Net Model Point                                                                                             
// Column:LIFE_PBA_STAT_RES_NET_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_stat_res_net_mp(int t) {
//^^^



//^^^

#line 1 "life_pba_stat_res_net_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_stat_res_net_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_stat_unearn_prem_res
// Life PBA Statutory Unearned Premium Reserve                                                                                             
// Column:LIFE_PBA_STAT_UNEARN_PREM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res(int t) {
//^^^



//^^^

#line 1 "life_pba_stat_unearn_prem_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_stat_unearn_prem_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_stat_unearn_prem_res_net
// Life PBA Statutory Unearned Premium Reserve Net                                                                                             
// Column:LIFE_PBA_STAT_UNEARN_PREM_RES_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res_net(int t) {
//^^^



//^^^

#line 1 "life_pba_stat_unearn_prem_res_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_stat_unearn_prem_res_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_stat_unearn_prem_res_npr_net
// Life PBA Statutory Unearned Premium Reserve NPR Net                                                                                             
// Column:LIFE_PBA_STAT_UNEARN_PREM_RES_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res_npr_net(int t) {
//^^^



//^^^

#line 1 "life_pba_stat_unearn_prem_res_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("life_pba_stat_unearn_prem_res_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - life_pba_working_res
// Life PBA Working Reserve                                                                                             
// Column:LIFE_PBA_WORKING_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_life_pba_working_res(int t) {
//^^^



//^^^

#line 1 "life_pba_working_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

#if defined(__LIFE_PBA_PBA_H_)
if (seg->sm_life_pba[0]->res_cap_calc_defn == RESERVES)
	return 0.0;
	
return get_epl_value("life_pba_working_res", t)
	   * pct_to_use_mp;
#endif

return NO_AVG;

}


//@@ END

//@@ START - maint_exp_bom
// Maintenance Expenses Beginning of Month                                                                                             
// Column:MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(54,"maint_exp_bom",t);
}



//^^^

#line 1 "maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - maint_exp_eom
// Maintenance Expenses End of Month                                                                                             
// Column:MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"maint_exp_eom",t);
}



//^^^

#line 1 "maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - maturity_benefits
// Maturity Benefits                                                                                             
// Column:MATURITY_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"maturity_benefits",t);
}



//^^^

#line 1 "maturity_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("maturity_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - pba_rollforward_base
// PBA Rollforward Base                                                                                             
// Column:PBA_ROLLFORWARD_BASE
//========================================================
double EPL_LIAB_UDF::epl_liab_pba_rollforward_base(int t) {
//^^^



//^^^

#line 1 "pba_rollforward_base.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("pba_rollforward_base", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - pol_loan
// Policy Loan                                                                                             
// Column:POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_pol_loan(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"pol_loan",t);
}



//^^^

#line 1 "pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - pol_loan_exp
// Policy Loan Expense                                                                                             
// Column:POL_LOAN_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_pol_loan_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"pol_loan_exp",t);
}



//^^^

#line 1 "pol_loan_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("pol_loan_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - pol_loan_int
// Policy Loan Interest                                                                                             
// Column:POL_LOAN_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_pol_loan_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"pol_loan_int",t);
}



//^^^

#line 1 "pol_loan_int.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("pol_loan_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - pol_loan_proceeds
// Policy Loan Proceeds                                                                                             
// Column:POL_LOAN_PROCEEDS
//========================================================
double EPL_LIAB_UDF::epl_liab_pol_loan_proceeds(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"pol_loan_proceeds",t);
}



//^^^

#line 1 "pol_loan_proceeds.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("pol_loan_proceeds", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - policies_b
// Policies In Force Beginning of Month                                                                                             
// Column:POLICIES_B
//========================================================
double EPL_LIAB_UDF::epl_liab_policies_b(int t) {
//^^^



//^^^

#line 1 "policies_b.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("policies_b", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - policies_inf
// Policies In Force                                                                                             
// Column:POLICIES_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_policies_inf(int t) {
//^^^



//^^^

#line 1 "policies_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("policies_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - policies_issued
// Policies Issued                                                                                             
// Column:POLICIES_ISSUED
//========================================================
double EPL_LIAB_UDF::epl_liab_policies_issued(int t) {
//^^^



//^^^

#line 1 "policies_issued.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("policies_issued", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - prem_issued
// Premium Issued                                                                                             
// Column:PREM_ISSUED
//========================================================
double EPL_LIAB_UDF::epl_liab_prem_issued(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(65,"prem_issued",t);
}



//^^^

#line 1 "prem_issued.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("prem_issued", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - prem_paid
// Premiums Paid                                                                                             
// Column:PREM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_prem_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(66,"prem_paid",t);
}



//^^^

#line 1 "prem_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("prem_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - prem_paid_net
// Premium Paid Net                                                                                             
// Column:PREM_PAID_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_prem_paid_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(67,"prem_paid_net",t);
}



//^^^

#line 1 "prem_paid_net.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("prem_paid_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - prem_tax
// Premium Taxes                                                                                             
// Column:PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"prem_tax",t);
}



//^^^

#line 1 "prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - prem_waiver_benefits
// Premium Waiver Benefits                                                                                             
// Column:PREM_WAIVER_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_prem_waiver_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"prem_waiver_benefits",t);
}



//^^^

#line 1 "prem_waiver_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("prem_waiver_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c1_unearn_prem_res_def
// RBC C1 Unearned Premium Reserve Deficiency                                                                                             
// Column:RBC_C1_UNEARN_PREM_RES_DEF
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c1_unearn_prem_res_def(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(70,"rbc_c1_unearn_prem_res_def",t);
}



//^^^

#line 1 "rbc_c1_unearn_prem_res_def.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c1_unearn_prem_res_def", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c2_claim
// RBC C2 Incurred Claim                                                                                             
// Column:RBC_C2_CLAIM
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c2_claim(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(71,"rbc_c2_claim",t);
}



//^^^

#line 1 "rbc_c2_claim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c2_claim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c2_claim_prev_yr
// RBC C2 Incurred Claim Previous Year                                                                                             
// Column:RBC_C2_CLAIM_PREV_YR
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c2_claim_prev_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(72,"rbc_c2_claim_prev_yr",t);
}



//^^^

#line 1 "rbc_c2_claim_prev_yr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c2_claim_prev_yr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c2_prem
// RBC C2 Earned Premium                                                                                             
// Column:RBC_C2_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c2_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(73,"rbc_c2_prem",t);
}



//^^^

#line 1 "rbc_c2_prem.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c2_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c2_prem_prev_yr
// RBC C2 Earned Premium Previous Year                                                                                             
// Column:RBC_C2_PREM_PREV_YR
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c2_prem_prev_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(74,"rbc_c2_prem_prev_yr",t);
}



//^^^

#line 1 "rbc_c2_prem_prev_yr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c2_prem_prev_yr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c3_base_ann_high_risk
// RBC C3 Base Annuity High Risk                                                                                             
// Column:RBC_C3_BASE_ANN_HIGH_RISK
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_high_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(75,"rbc_c3_base_ann_high_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_high_risk.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c3_base_ann_high_risk", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c3_base_ann_low_risk
// RBC C3 Base Annuity Low Risk                                                                                             
// Column:RBC_C3_BASE_ANN_LOW_RISK
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_low_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"rbc_c3_base_ann_low_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_low_risk.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c3_base_ann_low_risk", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c3_base_ann_medium_risk
// RBC C3 Base Annuity Medium Risk                                                                                             
// Column:RBC_C3_BASE_ANN_MEDIUM_RISK
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_medium_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"rbc_c3_base_ann_medium_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_medium_risk.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c3_base_ann_medium_risk", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c3_base_life
// RBC C3 Base Life                                                                                             
// Column:RBC_C3_BASE_LIFE
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c3_base_life(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(78,"rbc_c3_base_life",t);
}



//^^^

#line 1 "rbc_c3_base_life.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c3_base_life", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c3_mp
// RBC C3 Policy Amount                                                                                             
// Column:RBC_C3_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c3_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(79,"rbc_c3_mp",t);
}



//^^^

#line 1 "rbc_c3_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c3_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - rbc_c4
// RBC C4                                                                                             
// Column:RBC_C4
//========================================================
double EPL_LIAB_UDF::epl_liab_rbc_c4(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(80,"rbc_c4",t);
}



//^^^

#line 1 "rbc_c4.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("rbc_c4", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_ann_benefits_bom
// Reinsurance Annuity Benefits BOM                                                                                             
// Column:REINS_ANN_BENEFITS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_ann_benefits_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(81,"reins_ann_benefits_bom",t);
}



//^^^

#line 1 "reins_ann_benefits_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_ann_benefits_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_ann_benefits_eom
// Reinsurance Annuity Benefits EOM                                                                                             
// Column:REINS_ANN_BENEFITS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(82,"reins_ann_benefits_eom",t);
}



//^^^

#line 1 "reins_ann_benefits_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_ann_benefits_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_cash_val
// Reinsurance Cash Value                                                                                             
// Column:REINS_CASH_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(83,"reins_cash_val",t);
}



//^^^

#line 1 "reins_cash_val.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_cash_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_claim_paid
// Reinsurance Claim Paid                                                                                             
// Column:REINS_CLAIM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_claim_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(84,"reins_claim_paid",t);
}



//^^^

#line 1 "reins_claim_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_claim_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_comm_chargeback_reimb
// Reinsurance Commission Chargeback Reimbursement                                                                                             
// Column:REINS_COMM_CHARGEBACK_REIMB
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_comm_chargeback_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(85,"reins_comm_chargeback_reimb",t);
}



//^^^

#line 1 "reins_comm_chargeback_reimb.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_comm_chargeback_reimb", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_comm_reimb_bom
// Reinsurance Commission Reimbursement Beginning of Month                                                                                             
// Column:REINS_COMM_REIMB_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_comm_reimb_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(86,"reins_comm_reimb_bom",t);
}



//^^^

#line 1 "reins_comm_reimb_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_comm_reimb_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_comm_reimb_eom
// Reinsurance Commission Reimbursement End of Month                                                                                             
// Column:REINS_COMM_REIMB_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_comm_reimb_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(87,"reins_comm_reimb_eom",t);
}



//^^^

#line 1 "reins_comm_reimb_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_comm_reimb_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_deferred_gross_prem
// Reinsurance Deferred Gross Premium                                                                                             
// Column:REINS_DEFERRED_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_deferred_gross_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(88,"reins_deferred_gross_prem",t);
}



//^^^

#line 1 "reins_deferred_gross_prem.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_deferred_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_deferred_net_prem
// Reinsurance Deferred Net Premium                                                                                             
// Column:REINS_DEFERRED_NET_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(89,"reins_deferred_net_prem",t);
}



//^^^

#line 1 "reins_deferred_net_prem.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_deferred_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_div_applied
// Reinsurance Dividend Applied                                                                                             
// Column:REINS_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(90,"reins_div_applied",t);
}



//^^^

#line 1 "reins_div_applied.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_div_liab
// Reinsurance Dividend Liability                                                                                             
// Column:REINS_DIV_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(91,"reins_div_liab",t);
}



//^^^

#line 1 "reins_div_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_div_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_div_paid
// Reinsurance Dividend Paid                                                                                             
// Column:REINS_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"reins_div_paid",t);
}



//^^^

#line 1 "reins_div_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_dth_ben_inf
// Reinsured Death Benefit In Force                                                                                             
// Column:REINS_DTH_BEN_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"reins_dth_ben_inf",t);
}



//^^^

#line 1 "reins_dth_ben_inf.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_dth_ben_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_dth_benefits
// Reinsurance Death Benefits                                                                                             
// Column:REINS_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"reins_dth_benefits",t);
}



//^^^

#line 1 "reins_dth_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_ea
// Reinsurance Expense Allowance                                                                                             
// Column:REINS_EA
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_ea(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"reins_ea",t);
}



//^^^

#line 1 "reins_ea.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_ea", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_ea_chargeback
// Reinsurance Expense Allowance Chargeback                                                                                             
// Column:REINS_EA_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_ea_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(96,"reins_ea_chargeback",t);
}



//^^^

#line 1 "reins_ea_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_ea_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_endow_benefits
// Reinsurance Endowment Benefits                                                                                             
// Column:REINS_ENDOW_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"reins_endow_benefits",t);
}



//^^^

#line 1 "reins_endow_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_endow_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_exp
// Reinsurance Expense                                                                                             
// Column:REINS_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"reins_exp",t);
}



//^^^

#line 1 "reins_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_exp_reimb_bom
// Reinsurance Expense Reimbursed Beginning of Month                                                                                             
// Column:REINS_EXP_REIMB_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_exp_reimb_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(99,"reins_exp_reimb_bom",t);
}



//^^^

#line 1 "reins_exp_reimb_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_exp_reimb_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_exp_reimb_eom
// Reinsurance Expense Reimbursed End of Month                                                                                             
// Column:REINS_EXP_REIMB_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_exp_reimb_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(100,"reins_exp_reimb_eom",t);
}



//^^^

#line 1 "reins_exp_reimb_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_exp_reimb_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_inv_fee_ref
// Reinsurance Investment Fee Refund                                                                                             
// Column:REINS_INV_FEE_REF
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_inv_fee_ref(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"reins_inv_fee_ref",t);
}



//^^^

#line 1 "reins_inv_fee_ref.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_inv_fee_ref", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_maturity_benefits
// Reinsurance Maturity Benefits                                                                                             
// Column:REINS_MATURITY_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(102,"reins_maturity_benefits",t);
}



//^^^

#line 1 "reins_maturity_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_maturity_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_modco_res_adj
// Modified Coinsurance Reserve Adjustment                                                                                             
// Column:REINS_MODCO_RES_ADJ
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_modco_res_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(103,"reins_modco_res_adj",t);
}



//^^^

#line 1 "reins_modco_res_adj.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_modco_res_adj", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_prem
// Reinsurance Premium                                                                                             
// Column:REINS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(104,"reins_prem",t);
}



//^^^

#line 1 "reins_prem.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_prem_tax
// Reinsurance Premium Tax                                                                                             
// Column:REINS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(105,"reins_prem_tax",t);
}



//^^^

#line 1 "reins_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_prem_waiver_benefits
// Reinsurance Premium Waiver Benefits                                                                                             
// Column:REINS_PREM_WAIVER_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_prem_waiver_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(106,"reins_prem_waiver_benefits",t);
}



//^^^

#line 1 "reins_prem_waiver_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_prem_waiver_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_ref
// Reinsurance Refund                                                                                             
// Column:REINS_REF
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_ref(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(107,"reins_ref",t);
}



//^^^

#line 1 "reins_ref.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_ref", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_claim_res
// Reinsurance Statutory Claim Reserve                                                                                             
// Column:REINS_STAT_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(108,"reins_stat_claim_res",t);
}



//^^^

#line 1 "reins_stat_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_loading
// Reinsurance Statutory Loading                                                                                             
// Column:REINS_STAT_LOADING
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(109,"reins_stat_loading",t);
}



//^^^

#line 1 "reins_stat_loading.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_loading", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_prem_waiver_res
// Reinsurance Statutory Premium Waiver Reserve                                                                                             
// Column:REINS_STAT_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "reins_stat_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_prem_waiver_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_res_mp
// Reinsurance Statutory Policy Reserve                                                                                             
// Column:REINS_STAT_RES_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(111,"reins_stat_res_mp",t);
}



//^^^

#line 1 "reins_stat_res_mp.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_res_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_res_npr
// Reinsurance Statutory Net Premium Reserve                                                                                             
// Column:REINS_STAT_RES_NPR
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_res_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"reins_stat_res_npr",t);
}



//^^^

#line 1 "reins_stat_res_npr.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_res_npr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_stat_unearn_prem_res
// Reinsurance Statutory Unearned Premium Reserve                                                                                             
// Column:REINS_STAT_UNEARN_PREM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_stat_unearn_prem_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"reins_stat_unearn_prem_res",t);
}



//^^^

#line 1 "reins_stat_unearn_prem_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_stat_unearn_prem_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_surr_benefits
// Reinsurance Surrender Benefits                                                                                             
// Column:REINS_SURR_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(114,"reins_surr_benefits",t);
}



//^^^

#line 1 "reins_surr_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_surr_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_claim_res
// Reinsurance Tax Claim Reserve                                                                                             
// Column:REINS_TAX_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(115,"reins_tax_claim_res",t);
}



//^^^

#line 1 "reins_tax_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_deferred_net_prem
// Reinsurance Tax Deferred Net Premium                                                                                             
// Column:REINS_TAX_DEFERRED_NET_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(116,"reins_tax_deferred_net_prem",t);
}



//^^^

#line 1 "reins_tax_deferred_net_prem.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_deferred_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_loading
// Reinsurance Tax Loading                                                                                             
// Column:REINS_TAX_LOADING
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(117,"reins_tax_loading",t);
}



//^^^

#line 1 "reins_tax_loading.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_loading", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_prem_waiver_res
// Reinsurance Tax Premium Waiver Reserve                                                                                             
// Column:REINS_TAX_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "reins_tax_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_prem_waiver_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_res_mp
// Reinsurance Tax Policy Reserve                                                                                             
// Column:REINS_TAX_RES_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(119,"reins_tax_res_mp",t);
}



//^^^

#line 1 "reins_tax_res_mp.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_res_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_tax_unearn_prem_res
// Reinsurance Tax Unearned Premium Reserve                                                                                             
// Column:REINS_TAX_UNEARN_PREM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_tax_unearn_prem_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"reins_tax_unearn_prem_res",t);
}



//^^^

#line 1 "reins_tax_unearn_prem_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_tax_unearn_prem_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_terminal_div
// Reinsurance Terminal Dividends                                                                                             
// Column:REINS_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_terminal_div(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(121,"reins_terminal_div",t);
}



//^^^

#line 1 "reins_terminal_div.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - reins_withdrl_benefits
// Reinsurance Withdrawal Benefits                                                                                             
// Column:REINS_WITHDRL_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_reins_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(122,"reins_withdrl_benefits",t);
}



//^^^

#line 1 "reins_withdrl_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("reins_withdrl_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_acq_exp
// SFAS120 Ceded Acquisition Expenses                                                                                             
// Column:SFAS120_CEDED_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_benefits
// SFAS120 Ceded Benefits                                                                                             
// Column:SFAS120_CEDED_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_benefits(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_benefits.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_capzd_acq_exp
// SFAS120 Ceded Capitalized Acquisition Expenses                                                                                             
// Column:SFAS120_CEDED_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_capzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_capzd_comm_bom
// SFAS120 Ceded Capitalized Commissions Beginning of Month                                                                                             
// Column:SFAS120_CEDED_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_capzd_comm_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_capzd_comm_chargeback
// SFAS120 Ceded Capitalized Commissions Chargeback                                                                                             
// Column:SFAS120_CEDED_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_capzd_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_capzd_comm_eom
// SFAS120 Ceded Capitalized Commissions End of Month                                                                                             
// Column:SFAS120_CEDED_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_capzd_comm_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_cash_flow_bom
// SFAS120 Ceded Cash Flow Beginning of Month                                                                                             
// Column:SFAS120_CEDED_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_chargeback
// SFAS120 Ceded Commission Chargeback                                                                                             
// Column:SFAS120_CEDED_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_excess_bom
// SFAS120 Ceded Commissions Excess BOM                                                                                             
// Column:SFAS120_CEDED_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_excess_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_excess_eom
// SFAS120 Ceded Commissions Excess EOM                                                                                             
// Column:SFAS120_CEDED_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_excess_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_trail_bom
// SFAS120 Ceded Commissions Trail BOM                                                                                             
// Column:SFAS120_CEDED_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_trail_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_trail_bom_base_plan
// SFAS120 Ceded Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS120_CEDED_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_trail_bom_base_plan.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_trail_bom_rider
// SFAS120 Ceded Commissions Trail BOM Rider                                                                                             
// Column:SFAS120_CEDED_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_trail_bom_rider.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_comm_trail_eom
// SFAS120 Ceded Commissions Trail EOM                                                                                             
// Column:SFAS120_CEDED_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_comm_trail_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_comm_trail_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_conversion_cost
// SFAS120 Ceded Conversion Cost                                                                                             
// Column:SFAS120_CEDED_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_conversion_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_div_applied
// SFAS120 Ceded Dividends Applied                                                                                             
// Column:SFAS120_CEDED_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_div_applied.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_div_liab
// SFAS120 Ceded Dividend Liability                                                                                             
// Column:SFAS120_CEDED_DIV_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(139,"sfas120_ceded_div_liab",t);
}



//^^^

#line 1 "sfas120_ceded_div_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_div_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_div_opt_res
// SFAS120 Ceded Dividend Option Reserve                                                                                             
// Column:SFAS120_CEDED_DIV_OPT_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_opt_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(140,"sfas120_ceded_div_opt_res",t);
}



//^^^

#line 1 "sfas120_ceded_div_opt_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_div_opt_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_div_paid
// SFAS120 Ceded Annual Dividends Paid                                                                                             
// Column:SFAS120_CEDED_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_div_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_dth_claim_cost
// SFAS120 Ceded Death Claim Cost                                                                                             
// Column:SFAS120_CEDED_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_dth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_acq_exp
// SFAS120 Ceded EGM Acquisition Expense                                                                                             
// Column:SFAS120_CEDED_EGM_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(143,"sfas120_ceded_egm_acq_exp",t);
}



//^^^

#line 1 "sfas120_ceded_egm_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_comm
// SFAS120 Ceded EGM Commissions                                                                                             
// Column:SFAS120_CEDED_EGM_COMM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_comm(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(144,"sfas120_ceded_egm_comm",t);
}



//^^^

#line 1 "sfas120_ceded_egm_comm.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_comm", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_div_applied
// SFAS120 Ceded EGM Dividend Applied                                                                                             
// Column:SFAS120_CEDED_EGM_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(145,"sfas120_ceded_egm_div_applied",t);
}



//^^^

#line 1 "sfas120_ceded_egm_div_applied.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_div_paid
// SFAS120 Ceded EGM Dividends Paid                                                                                             
// Column:SFAS120_CEDED_EGM_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(146,"sfas120_ceded_egm_div_paid",t);
}



//^^^

#line 1 "sfas120_ceded_egm_div_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_dth_benefits
// SFAS120 Ceded EGM Death Benefits                                                                                             
// Column:SFAS120_CEDED_EGM_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"sfas120_ceded_egm_dth_benefits",t);
}



//^^^

#line 1 "sfas120_ceded_egm_dth_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_endow_benefits
// SFAS120 Ceded EGM Endowment Benefits                                                                                             
// Column:SFAS120_CEDED_EGM_ENDOW_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(148,"sfas120_ceded_egm_endow_benefits",t);
}



//^^^

#line 1 "sfas120_ceded_egm_endow_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_endow_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_maint_exp
// SFAS120 Ceded EGM Maintenance Expense                                                                                             
// Column:SFAS120_CEDED_EGM_MAINT_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_maint_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(149,"sfas120_ceded_egm_maint_exp",t);
}



//^^^

#line 1 "sfas120_ceded_egm_maint_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_maint_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_maturity_benefits
// SFAS120 Ceded EGM Maturity Benefits                                                                                             
// Column:SFAS120_CEDED_EGM_MATURITY_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(150,"sfas120_ceded_egm_maturity_benefits",t);
}



//^^^

#line 1 "sfas120_ceded_egm_maturity_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_maturity_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_prem_paid
// SFAS120 Ceded EGM Premium Paid                                                                                             
// Column:SFAS120_CEDED_EGM_PREM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_prem_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(151,"sfas120_ceded_egm_prem_paid",t);
}



//^^^

#line 1 "sfas120_ceded_egm_prem_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_prem_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_prem_tax
// SFAS120 Ceded EGM Premium Tax                                                                                             
// Column:SFAS120_CEDED_EGM_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(152,"sfas120_ceded_egm_prem_tax",t);
}



//^^^

#line 1 "sfas120_ceded_egm_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_egm_surr_benefits
// SFAS120 Ceded EGM Surrender Benefits                                                                                             
// Column:SFAS120_CEDED_EGM_SURR_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(153,"sfas120_ceded_egm_surr_benefits",t);
}



//^^^

#line 1 "sfas120_ceded_egm_surr_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_egm_surr_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_endow_claim_cost
// SFAS120 Ceded Endowment Claim Cost                                                                                             
// Column:SFAS120_CEDED_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_endow_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_gpr
// SFAS120 Ceded Gross Premium Reserve                                                                                             
// Column:SFAS120_CEDED_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_gpr(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_gpr.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_gpr_units_inf
// SFAS120 Ceded Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS120_CEDED_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_gpr_units_inf.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_gross_prem
// SFAS120 Ceded Gross Premium                                                                                             
// Column:SFAS120_CEDED_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_gross_prem.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_loc_cost
// SFAS120 Ceded Letter of Credit Cost                                                                                             
// Column:SFAS120_CEDED_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_loc_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_maint_exp_bom
// SFAS120 Ceded Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS120_CEDED_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(159,"sfas120_ceded_maint_exp_bom",t);
}



//^^^

#line 1 "sfas120_ceded_maint_exp_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_maint_exp_eom
// SFAS120 Ceded Maintenance Expenses End of Month                                                                                             
// Column:SFAS120_CEDED_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_maint_exp_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_maturity_claim_cost
// SFAS120 Ceded Maturity Claim Cost                                                                                             
// Column:SFAS120_CEDED_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_maturity_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_modco_liab
// SFAS120 Ceded Modco Liability                                                                                             
// Column:SFAS120_CEDED_MODCO_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_modco_liab(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_modco_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_modco_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_modco_res_adj
// SFAS120 Ceded Modified Coinsurance Reserve Adjustment                                                                                             
// Column:SFAS120_CEDED_MODCO_RES_ADJ
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_modco_res_adj(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_modco_res_adj.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_modco_res_adj", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_nlp_res_net_prem2
// SFAS120 Ceded Net Level Premium Reserve Net Premium                                                                                             
// Column:SFAS120_CEDED_NLP_RES_NET_PREM2
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_nlp_res_net_prem2(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_nlp_res_net_prem2.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_nlp_res_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_nlp_res_prelim
// SFAS120 Ceded Net Level Premium Reserve Preliminary                                                                                             
// Column:SFAS120_CEDED_NLP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_nlp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_nlp_res_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_nlp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_prem_tax
// SFAS120 Ceded Premium Tax                                                                                             
// Column:SFAS120_CEDED_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_refund
// SFAS120 Ceded Reinsurance Refund                                                                                             
// Column:SFAS120_CEDED_REFUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_refund(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_refund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_refund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_reins_ea_excess
// SFAS120 Ceded Reinsurance EA Excess                                                                                             
// Column:SFAS120_CEDED_REINS_EA_EXCESS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_reins_ea_excess(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_reins_ea_excess.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_reins_ea_excess", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_reins_ea_trail
// SFAS120 Ceded Reinsurance EA Trail                                                                                             
// Column:SFAS120_CEDED_REINS_EA_TRAIL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_reins_ea_trail(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_reins_ea_trail.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_reins_ea_trail", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_surr_claim_cost
// SFAS120 Ceded Surrender Claim Cost                                                                                             
// Column:SFAS120_CEDED_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_surr_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_ceded_terminal_div
// SFAS120 Ceded Terminal Dividends                                                                                             
// Column:SFAS120_CEDED_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_ceded_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas120_ceded_terminal_div.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_ceded_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_acq_exp
// SFAS120 Gross Acquisition Expenses                                                                                             
// Column:SFAS120_GROSS_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_benefits
// SFAS120 Gross Benefits                                                                                             
// Column:SFAS120_GROSS_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_benefits(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_benefits.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_capzd_acq_exp
// SFAS120 Gross Capitalized Acquisition Expenses                                                                                             
// Column:SFAS120_GROSS_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_capzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_capzd_comm_bom
// SFAS120 Gross Capitalized Commissions Beginning of Month                                                                                             
// Column:SFAS120_GROSS_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_capzd_comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_capzd_comm_chargeback
// SFAS120 Gross Capitalized Commissions Chargeback                                                                                             
// Column:SFAS120_GROSS_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_capzd_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_capzd_comm_eom
// SFAS120 Gross Capitalized Commissions End of Month                                                                                             
// Column:SFAS120_GROSS_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_capzd_comm_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_capzd_reins_yrt_cost
// SFAS120 Gross Capitalized YRT Reinsurance Cost                                                                                             
// Column:SFAS120_GROSS_CAPZD_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_capzd_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_capzd_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_cash_flow_bom
// SFAS120 Gross Cash Flow Beginning of Month                                                                                             
// Column:SFAS120_GROSS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_chargeback
// SFAS120 Gross Commission Chargeback                                                                                             
// Column:SFAS120_GROSS_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_excess_bom
// SFAS120 Gross Commissions Excess BOM                                                                                             
// Column:SFAS120_GROSS_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_excess_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_excess_eom
// SFAS120 Gross Commissions Excess EOM                                                                                             
// Column:SFAS120_GROSS_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_excess_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_trail_bom
// SFAS120 Gross Commissions Trail BOM                                                                                             
// Column:SFAS120_GROSS_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_trail_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_trail_bom_base_plan
// SFAS120 Gross Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS120_GROSS_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_trail_bom_base_plan.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_trail_bom_rider
// SFAS120 Gross Commissions Trail BOM Rider                                                                                             
// Column:SFAS120_GROSS_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_trail_bom_rider.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_comm_trail_eom
// SFAS120 Gross Commissions Trail EOM                                                                                             
// Column:SFAS120_GROSS_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_comm_trail_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_comm_trail_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_conversion_cost
// SFAS120 Gross Conversion Cost                                                                                             
// Column:SFAS120_GROSS_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_conversion_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_div_applied
// SFAS120 Gross Dividends Applied                                                                                             
// Column:SFAS120_GROSS_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_div_applied.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_div_liab
// SFAS120 Gross Dividend Liability                                                                                             
// Column:SFAS120_GROSS_DIV_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_div_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(189,"sfas120_gross_div_liab",t);
}



//^^^

#line 1 "sfas120_gross_div_liab.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_div_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_div_opt_res
// SFAS120 Gross Dividend Option Reserve                                                                                             
// Column:SFAS120_GROSS_DIV_OPT_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_div_opt_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(190,"sfas120_gross_div_opt_res",t);
}



//^^^

#line 1 "sfas120_gross_div_opt_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_div_opt_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_div_paid
// SFAS120 Gross Annual Dividends Paid                                                                                             
// Column:SFAS120_GROSS_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_div_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_dth_claim_cost
// SFAS120 Gross Death Claim Cost                                                                                             
// Column:SFAS120_GROSS_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_dth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_acq_exp
// SFAS120 Gross EGM Acquisition Expense                                                                                             
// Column:SFAS120_GROSS_EGM_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(193,"sfas120_gross_egm_acq_exp",t);
}



//^^^

#line 1 "sfas120_gross_egm_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_comm
// SFAS120 Gross EGM Commissions                                                                                             
// Column:SFAS120_GROSS_EGM_COMM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_comm(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(194,"sfas120_gross_egm_comm",t);
}



//^^^

#line 1 "sfas120_gross_egm_comm.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_comm", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_div_applied
// SFAS120 Gross EGM Dividend Applied                                                                                             
// Column:SFAS120_GROSS_EGM_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_div_applied(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(195,"sfas120_gross_egm_div_applied",t);
}



//^^^

#line 1 "sfas120_gross_egm_div_applied.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_div_paid
// SFAS120 Gross EGM Dividends Paid                                                                                             
// Column:SFAS120_GROSS_EGM_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_div_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(196,"sfas120_gross_egm_div_paid",t);
}



//^^^

#line 1 "sfas120_gross_egm_div_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_dth_benefits
// SFAS120 Gross EGM Death Benefits                                                                                             
// Column:SFAS120_GROSS_EGM_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(197,"sfas120_gross_egm_dth_benefits",t);
}



//^^^

#line 1 "sfas120_gross_egm_dth_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_endow_benefits
// SFAS120 Gross EGM Endowment Benefits                                                                                             
// Column:SFAS120_GROSS_EGM_ENDOW_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_endow_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(198,"sfas120_gross_egm_endow_benefits",t);
}



//^^^

#line 1 "sfas120_gross_egm_endow_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_endow_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_maint_exp
// SFAS120 Gross EGM Maintenance Expense                                                                                             
// Column:SFAS120_GROSS_EGM_MAINT_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_maint_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(199,"sfas120_gross_egm_maint_exp",t);
}



//^^^

#line 1 "sfas120_gross_egm_maint_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_maint_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_maturity_benefits
// SFAS120 Gross EGM Maturity Benefits                                                                                             
// Column:SFAS120_GROSS_EGM_MATURITY_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(200,"sfas120_gross_egm_maturity_benefits",t);
}



//^^^

#line 1 "sfas120_gross_egm_maturity_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_maturity_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_prem_paid
// SFAS120 Gross EGM Premium Paid                                                                                             
// Column:SFAS120_GROSS_EGM_PREM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_prem_paid(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(201,"sfas120_gross_egm_prem_paid",t);
}



//^^^

#line 1 "sfas120_gross_egm_prem_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_prem_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_prem_tax
// SFAS120 Gross EGM Premium Tax                                                                                             
// Column:SFAS120_GROSS_EGM_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(202,"sfas120_gross_egm_prem_tax",t);
}



//^^^

#line 1 "sfas120_gross_egm_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_reins_cost
// SFAS120 Gross EGM Reinsurance Cost                                                                                             
// Column:SFAS120_GROSS_EGM_REINS_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_reins_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(203,"sfas120_gross_egm_reins_cost",t);
}



//^^^

#line 1 "sfas120_gross_egm_reins_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_reins_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_egm_surr_benefits
// SFAS120 Gross EGM Surrender Benefits                                                                                             
// Column:SFAS120_GROSS_EGM_SURR_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(204,"sfas120_gross_egm_surr_benefits",t);
}



//^^^

#line 1 "sfas120_gross_egm_surr_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_egm_surr_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_endow_claim_cost
// SFAS120 Gross Endowment Claim Cost                                                                                             
// Column:SFAS120_GROSS_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_endow_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_gpr
// SFAS120 Gross Gross Premium Reserve                                                                                             
// Column:SFAS120_GROSS_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_gpr(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_gpr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_gpr_units_inf
// SFAS120 Gross Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS120_GROSS_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_gpr_units_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_gross_prem
// SFAS120 Gross Gross Premium                                                                                             
// Column:SFAS120_GROSS_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_gross_prem.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_loc_cost
// SFAS120 Gross Letter of Credit Cost                                                                                             
// Column:SFAS120_GROSS_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_loc_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_maint_exp_bom
// SFAS120 Gross Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS120_GROSS_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(210,"sfas120_gross_maint_exp_bom",t);
}



//^^^

#line 1 "sfas120_gross_maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_maint_exp_eom
// SFAS120 Gross Maintenance Expenses End of Month                                                                                             
// Column:SFAS120_GROSS_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_maturity_claim_cost
// SFAS120 Gross Maturity Claim Cost                                                                                             
// Column:SFAS120_GROSS_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_maturity_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_nlp_res_net_prem
// SFAS120 Gross Net Level Premium Reserve Net Premium                                                                                             
// Column:SFAS120_GROSS_NLP_RES_NET_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_nlp_res_net_prem(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_nlp_res_net_prem.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_nlp_res_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_nlp_res_prelim
// SFAS120 Gross Net Level Premium Reserve Preliminary                                                                                             
// Column:SFAS120_GROSS_NLP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_nlp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_nlp_res_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_nlp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_pol_loan
// SFAS120 Gross Policy Loan                                                                                             
// Column:SFAS120_GROSS_POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_pol_loan(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_pol_loan_inc
// SFAS120 Gross Policy Loan Income                                                                                             
// Column:SFAS120_GROSS_POL_LOAN_INC
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_pol_loan_inc(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_pol_loan_inc.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_pol_loan_inc", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_prem_tax
// SFAS120 Gross Premium Tax                                                                                             
// Column:SFAS120_GROSS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_reins_yrt_cost
// SFAS120 Gross YRT Reinsurance Cost                                                                                             
// Column:SFAS120_GROSS_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_stat_res_rider
// SFAS120 Statutory Reserve for Riders                                                                                             
// Column:SFAS120_GROSS_STAT_RES_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_stat_res_rider(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_stat_res_rider.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_stat_res_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_surr_claim_cost
// SFAS120 Gross Surrender Claim Cost                                                                                             
// Column:SFAS120_GROSS_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_surr_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas120_gross_terminal_div
// SFAS120 GrossTerminal Dividends                                                                                             
// Column:SFAS120_GROSS_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas120_gross_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas120_gross_terminal_div.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas120_gross_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_acq_exp
// SFAS60 Ceded Acquisition Expenses                                                                                             
// Column:SFAS60_CEDED_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_ben_res_accrual_valn_basis
// SFAS60 Ceded Benefit Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS60_CEDED_BEN_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_ben_res_accrual_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_ben_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_ben_res_int_valn_basis
// SFAS60 Ceded Benefit Reserve Interest Valuation Basis                                                                                             
// Column:SFAS60_CEDED_BEN_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_ben_res_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_ben_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_ben_res_prelim
// SFAS60 Ceded Benefit Reserve Preliminary                                                                                             
// Column:SFAS60_CEDED_BEN_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_ben_res_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_ben_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_benefits_valn_basis
// SFAS60 Ceded Benefits Valuation Basis                                                                                             
// Column:SFAS60_CEDED_BENEFITS_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_benefits_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_benefits_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_benefits_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_acq_exp
// SFAS60 Ceded Capitalized Acquisition Expenses                                                                                             
// Column:SFAS60_CEDED_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_acq_exp_valn_basis
// SFAS60 Ceded Capitalized Acquisition Expenses Valuation Basis                                                                                             
// Column:SFAS60_CEDED_CAPZD_ACQ_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_acq_exp_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_acq_exp_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_acq_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_comm_bom
// SFAS60 Ceded Capitalized Commission BOM                                                                                             
// Column:SFAS60_CEDED_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_comm_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_comm_chargeback
// SFAS60 Ceded Capitalized Commission Chargeback                                                                                             
// Column:SFAS60_CEDED_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_commission_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_comm_eom
// SFAS60 Ceded Capitalized Commission EOM                                                                                             
// Column:SFAS60_CEDED_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_comm_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_capzd_comm_valn_basis
// SFAS60 Ceded Capitalized Commission Valuation Basis                                                                                             
// Column:SFAS60_CEDED_CAPZD_COMM_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_capzd_comm_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_capzd_comm_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_cash_flow_bom
// SFAS60 Ceded Cash Flow BOM                                                                                             
// Column:SFAS60_CEDED_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_claim_res
// SFAS60 Ceded Claim Reserve                                                                                             
// Column:SFAS60_CEDED_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_claim_res(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_claim_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_chargeback
// SFAS60 Ceded Commission Chargeback                                                                                             
// Column:SFAS60_CEDED_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_excess_bom
// SFAS60 Ceded Commissions Excess BOM                                                                                             
// Column:SFAS60_CEDED_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_excess_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_excess_eom
// SFAS60 Ceded Commissions Excess EOM                                                                                             
// Column:SFAS60_CEDED_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_excess_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_trail_bom
// SFAS60 Ceded Commissions Trail BOM                                                                                             
// Column:SFAS60_CEDED_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_trail_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_trail_bom_base_plan
// SFAS60 Ceded Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS60_CEDED_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_trail_bom_base_plan.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_trail_bom_rider
// SFAS60 Ceded Commissions Trail BOM Rider                                                                                             
// Column:SFAS60_CEDED_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_trail_bom_rider.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_comm_trail_eom
// SFAS60 Ceded Commissions Trail EOM                                                                                             
// Column:SFAS60_CEDED_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_comm_trail_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_comm_trail_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_conversion_cost
// SFAS60 Ceded Conversion Cost                                                                                             
// Column:SFAS60_CEDED_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_conversion_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_dac_amortzn_valn_basis
// SFAS60 Ceded DAC Amortization Valuation Basis                                                                                             
// Column:SFAS60_CEDED_DAC_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_dac_amortzn_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_dac_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_dac_int_valn_basis
// SFAS60 Ceded DAC Interest Valuation Basis                                                                                             
// Column:SFAS60_CEDED_DAC_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_dac_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_dac_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_dac_prelim
// SFAS60 Ceded DAC Preliminary                                                                                             
// Column:SFAS60_CEDED_DAC_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_dac_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_dac_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_div_applied
// SFAS60 Ceded Dividends Applied                                                                                             
// Column:SFAS60_CEDED_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_div_applied.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_div_paid
// SFAS60 Ceded Annual Dividends Paid                                                                                             
// Column:SFAS60_CEDED_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_div_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_div_valn_basis
// SFAS60 Ceded Annual Dividends Valuation Basis                                                                                             
// Column:SFAS60_CEDED_DIV_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_div_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_div_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_dth_claim_cost
// SFAS60 Ceded Death Claim Cost                                                                                             
// Column:SFAS60_CEDED_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_dth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_endow_claim_cost
// SFAS60 Ceded Endowment Claim Cost                                                                                             
// Column:SFAS60_CEDED_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_endow_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_exp_valn_basis
// SFAS60 Ceded Expenses Valuation Basis                                                                                             
// Column:SFAS60_CEDED_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_exp_valn_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(251,"sfas60_ceded_exp_valn_basis",t);
}



//^^^

#line 1 "sfas60_ceded_exp_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_gpr
// SFAS60 Ceded Gross Premium Reserve                                                                                             
// Column:SFAS60_CEDED_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_gpr(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_gpr.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_gpr_units_inf
// SFAS60 Ceded Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS60_CEDED_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_gpr_units_inf.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_gross_prem
// SFAS60 Ceded Gross Premium                                                                                             
// Column:SFAS60_CEDED_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_gross_prem.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_hlth_claim_cost
// SFAS60 Ceded Health Claim Cost                                                                                             
// Column:SFAS60_CEDED_HLTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_hlth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_hlth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_hlth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_loc_cost
// SFAS60 Ceded Letter of Credit Cost                                                                                             
// Column:SFAS60_CEDED_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_loc_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maint_exp_bom
// SFAS60 Ceded Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS60_CEDED_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(257,"sfas60_ceded_maint_exp_bom",t);
}



//^^^

#line 1 "sfas60_ceded_maint_exp_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maint_exp_eom
// SFAS60 Ceded Maintenance Expenses End of Month                                                                                             
// Column:SFAS60_CEDED_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_maint_exp_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maint_exp_res_accrual_valn_basis
// SFAS60 Ceded Maintenance Expense Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS60_CEDED_MAINT_EXP_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_maint_exp_res_accrual_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maint_exp_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maint_exp_res_int_valn_basis
// SFAS60 Ceded Maintenance Expense Reserve Interest Valuation Basis                                                                                             
// Column:SFAS60_CEDED_MAINT_EXP_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_maint_exp_res_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maint_exp_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maint_exp_res_prelim
// SFAS60 Ceded Maintenance Expense Reserve Preliminary                                                                                             
// Column:SFAS60_CEDED_MAINT_EXP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_maint_exp_res_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maint_exp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_maturity_claim_cost
// SFAS60 Ceded Maturity Claim Cost                                                                                             
// Column:SFAS60_CEDED_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_maturity_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_modco_liab
// SFAS60 Ceded Modco Liability                                                                                             
// Column:SFAS60_CEDED_MODCO_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_modco_liab(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_modco_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_modco_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_modco_res_adj
// SFAS60 Ceded Modified Coinsurance Reserve Adjustment                                                                                             
// Column:SFAS60_CEDED_MODCO_RES_ADJ
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_modco_res_adj(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_modco_res_adj.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_modco_res_adj", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_prem_tax
// SFAS60 Ceded Premium Tax                                                                                             
// Column:SFAS60_CEDED_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_prem_waiver_res
// SFAS60 Ceded Premium Waiver Reserve                                                                                             
// Column:SFAS60_CEDED_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_prem_waiver_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_prem_waiver_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_refund
// SFAS60 Ceded Reinsurance Refund                                                                                             
// Column:SFAS60_CEDED_REFUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_refund(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_refund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_refund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_surr_ben_valn_basis
// SFAS60 Ceded Surrender Benefits Valuation Basis                                                                                             
// Column:SFAS60_CEDED_SURR_BEN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_surr_ben_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_surr_ben_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_surr_ben_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_surr_claim_cost
// SFAS60 Ceded Surrender Claim Cost                                                                                             
// Column:SFAS60_CEDED_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_surr_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_ceded_terminal_div
// SFAS60 Ceded Terminal Dividends                                                                                             
// Column:SFAS60_CEDED_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_ceded_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas60_ceded_terminal_div.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_ceded_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_acq_exp
// SFAS60 Gross Acquisition Expenses                                                                                             
// Column:SFAS60_GROSS_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_ben_res_accrual_valn_basis
// SFAS60 Gross Benefit Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS60_GROSS_BEN_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_ben_res_accrual_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_ben_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_ben_res_int_valn_basis
// SFAS60 Gross Benefit Reserve Interest Valuation Basis                                                                                             
// Column:SFAS60_GROSS_BEN_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_ben_res_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_ben_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_ben_res_prelim
// SFAS60 Gross Benefit Reserve Preliminary                                                                                             
// Column:SFAS60_GROSS_BEN_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_ben_res_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_ben_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_benefits_valn_basis
// SFAS60 Gross Benefits Valuation Basis                                                                                             
// Column:SFAS60_GROSS_BENEFITS_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_benefits_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_benefits_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_benefits_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_acq_exp
// SFAS60 Gross Capitalized Acquisition Expenses                                                                                             
// Column:SFAS60_GROSS_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_acq_exp_valn_basis
// SFAS60 Gross Capitalized Acquisition Expenses Valuation Basis                                                                                             
// Column:SFAS60_GROSS_CAPZD_ACQ_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_acq_exp_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_acq_exp_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_acq_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_comm_bom
// SFAS60 Gross Capitalized Commission BOM                                                                                             
// Column:SFAS60_GROSS_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_comm_chargeback
// SFAS60 Gross Capitalized Commission Chargeback                                                                                             
// Column:SFAS60_GROSS_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_commission_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_comm_eom
// SFAS60 Gross Capitalized Commission EOM                                                                                             
// Column:SFAS60_GROSS_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_comm_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_comm_valn_basis
// SFAS60 Gross Capitalized Commission Valuation Basis                                                                                             
// Column:SFAS60_GROSS_CAPZD_COMM_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_comm_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_comm_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_capzd_reins_yrt_cost
// SFAS60 Gross Capitalized YRT Reinsurance Cost                                                                                             
// Column:SFAS60_GROSS_CAPZD_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_capzd_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_capzd_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_cash_flow_bom
// SFAS60 Gross Cash Flow BOM                                                                                             
// Column:SFAS60_GROSS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_claim_res
// SFAS60 Gross Claim Reserve                                                                                             
// Column:SFAS60_GROSS_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_claim_res(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_chargeback
// SFAS60 Gross Commission Chargeback                                                                                             
// Column:SFAS60_GROSS_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_excess_bom
// SFAS60 Gross Commissions Excess BOM                                                                                             
// Column:SFAS60_GROSS_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_excess_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_excess_eom
// SFAS60 Gross Commissions Excess EOM                                                                                             
// Column:SFAS60_GROSS_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_excess_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_trail_bom
// SFAS60 Gross Commissions Trail BOM                                                                                             
// Column:SFAS60_GROSS_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_trail_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_trail_bom_base_plan
// SFAS60 Gross Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS60_GROSS_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_trail_bom_base_plan.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_trail_bom_rider
// SFAS60 Gross Commissions Trail BOM Rider                                                                                             
// Column:SFAS60_GROSS_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_trail_bom_rider.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_comm_trail_eom
// SFAS60 Gross Commissions Trail EOM                                                                                             
// Column:SFAS60_GROSS_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_comm_trail_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_conversion_cost
// SFAS60 Gross Conversion Cost                                                                                             
// Column:SFAS60_GROSS_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_conversion_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_amortzn_valn_basis
// SFAS60 Gross DAC Amortization Valuation Basis                                                                                             
// Column:SFAS60_GROSS_DAC_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_amortzn_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dac_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_int_valn_basis
// SFAS60 Gross DAC Interest Valuation Basis                                                                                             
// Column:SFAS60_GROSS_DAC_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dac_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_prelim
// SFAS60 Gross DAC Preliminary                                                                                             
// Column:SFAS60_GROSS_DAC_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dac_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis
// SFAS60 Gross Reinsurance YRT Asset Amortization Valuation Basis                                                                                             
// Column:SFAS60_GROSS_DAC_REINS_YRT_ASSET_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_reins_yrt_asset_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_reins_yrt_asset_int_valn_basis
// SFAS60 Gross Reinsurance YRT Asset Interest Valuation Basis                                                                                             
// Column:SFAS60_GROSS_DAC_REINS_YRT_ASSET_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_reins_yrt_asset_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_reins_yrt_asset_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dac_reins_yrt_asset_prelim
// SFAS60 Gross DAC Reinsurance YRT Asset Preliminary                                                                                             
// Column:SFAS60_GROSS_DAC_REINS_YRT_ASSET_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dac_reins_yrt_asset_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dac_reins_yrt_asset_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_div_applied
// SFAS60 Gross Dividends Applied                                                                                             
// Column:SFAS60_GROSS_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_div_applied.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_div_paid
// SFAS60 Gross Annual Dividends Paid                                                                                             
// Column:SFAS60_GROSS_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_div_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_div_valn_basis
// SFAS60 Gross Annual Dividends Valuation Basis                                                                                             
// Column:SFAS60_GROSS_DIV_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_div_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_div_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_div_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_dth_claim_cost
// SFAS60 Gross Death Claim Cost                                                                                             
// Column:SFAS60_GROSS_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_dth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_endow_claim_cost
// SFAS60 Gross Endowment Claim Cost                                                                                             
// Column:SFAS60_GROSS_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_endow_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_exp_valn_basis
// SFAS60 Gross Expenses Valuation Basis                                                                                             
// Column:SFAS60_GROSS_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_exp_valn_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(304,"sfas60_gross_exp_valn_basis",t);
}



//^^^

#line 1 "sfas60_gross_exp_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_gpr
// SFAS60 Gross Gross Premium Reserve                                                                                             
// Column:SFAS60_GROSS_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_gpr(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_gpr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_gpr_units_inf
// SFAS60 Gross Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS60_GROSS_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_gpr_units_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_gross_prem
// SFAS60 Gross Gross Premium                                                                                             
// Column:SFAS60_GROSS_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_gross_prem.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_hlth_claim_cost
// SFAS60 Gross Health Claim Cost                                                                                             
// Column:SFAS60_GROSS_HLTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_hlth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_hlth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_hlth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_loc_cost
// SFAS60 Gross Letter of Credit Cost                                                                                             
// Column:SFAS60_GROSS_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_loc_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maint_exp_bom
// SFAS60 Gross Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS60_GROSS_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(310,"sfas60_gross_maint_exp_bom",t);
}



//^^^

#line 1 "sfas60_gross_maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maint_exp_eom
// SFAS60 Gross Maintenance Expenses End of Month                                                                                             
// Column:SFAS60_GROSS_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maint_exp_res_accrual_valn_basis
// SFAS60 Gross Maintenance Expense Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS60_GROSS_MAINT_EXP_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_maint_exp_res_accrual_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maint_exp_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maint_exp_res_int_valn_basis
// SFAS60 Gross Maintenance Expense Reserve Interest Valuation Basis                                                                                             
// Column:SFAS60_GROSS_MAINT_EXP_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_maint_exp_res_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maint_exp_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maint_exp_res_prelim
// SFAS60 Gross Maintenance Reserve Preliminary                                                                                             
// Column:SFAS60_GROSS_MAINT_EXP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_maint_exp_res_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maint_exp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_maturity_claim_cost
// SFAS60 Gross Maturity Claim Cost                                                                                             
// Column:SFAS60_GROSS_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_maturity_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_pol_loan
// SFAS60 Gross Policy Loan                                                                                             
// Column:SFAS60_GROSS_POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_pol_loan(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_pol_loan_inc
// SFAS60 Gross Policy Loan Income                                                                                             
// Column:SFAS60_GROSS_POL_LOAN_INC
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_pol_loan_inc(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_pol_loan_inc.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_pol_loan_inc", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_prem_tax
// SFAS60 Gross Premium Tax                                                                                             
// Column:SFAS60_GROSS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_prem_waiver_res
// SFAS60 Gross Premium Waiver Reserve                                                                                             
// Column:SFAS60_GROSS_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_prem_waiver_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_reins_yrt_cost
// SFAS60 Gross YRT Reinsurance Cost                                                                                             
// Column:SFAS60_GROSS_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_reins_yrt_cost_valn_basis
// SFAS60 Gross Reinsurance YRT Cost Valuation Basis                                                                                             
// Column:SFAS60_GROSS_REINS_YRT_COST_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_reins_yrt_cost_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_reins_yrt_cost_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_reins_yrt_cost_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_stat_res_rider
// SFAS60 Statutory Reserve for Riders                                                                                             
// Column:SFAS60_GROSS_STAT_RES_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_stat_res_rider(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_stat_res_rider.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_stat_res_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_surr_ben_valn_basis
// SFAS60 Gross Surrender Benefits Valuation Basis                                                                                             
// Column:SFAS60_GROSS_SURR_BEN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_surr_ben_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_surr_ben_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_surr_ben_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_surr_claim_cost
// SFAS60 Gross Surrender Claim Cost                                                                                             
// Column:SFAS60_GROSS_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_surr_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas60_gross_terminal_div
// SFAS60 GrossTerminal Dividends                                                                                             
// Column:SFAS60_GROSS_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas60_gross_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas60_gross_terminal_div.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_acq_exp
// SFAS91 Ceded Acquisition Expenses                                                                                             
// Column:SFAS91_CEDED_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ann_benefits_bom
// SFAS91 Ceded Annuity Benefits Beginning of Month                                                                                             
// Column:SFAS91_CEDED_ANN_BENEFITS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ann_benefits_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ann_benefits_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ann_benefits_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ann_benefits_eom
// SFAS91 Ceded Annuity Benefits End of Month                                                                                             
// Column:SFAS91_CEDED_ANN_BENEFITS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ann_benefits_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ann_benefits_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ann_benefits_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ben_maint_exp_res_cash_flow_bom
// SFAS91 Ceded Benefit and Maintenance Expense Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_CEDED_BEN_MAINT_EXP_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ben_maint_exp_res_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ben_maint_exp_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ben_maint_exp_res_cash_flow_eom
// SFAS91 Ceded Benefit and Maintenance Expense Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_CEDED_BEN_MAINT_EXP_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ben_maint_exp_res_cash_flow_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ben_maint_exp_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ben_res_cash_flow_bom
// SFAS91 Ceded Benefit Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_CEDED_BEN_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_res_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ben_res_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ben_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_ben_res_cash_flow_eom
// SFAS91 Ceded Benefit Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_CEDED_BEN_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_res_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_ben_res_cash_flow_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_ben_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_capzd_acq_exp
// SFAS91 Ceded Capitalized Acquisition Expenses                                                                                             
// Column:SFAS91_CEDED_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_capzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_capzd_comm_bom
// SFAS91 Ceded Capitalized Commissions Beginning of Month                                                                                             
// Column:SFAS91_CEDED_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_capzd_comm_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_cash_flow_bom
// SFAS91 Ceded Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_CEDED_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_comm_excess_bom
// SFAS91 Ceded Commission Excess Beginning of Month                                                                                             
// Column:SFAS91_CEDED_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_comm_excess_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_deferred_maint_exp
// SFAS91 Ceded Deferred Maintenance Expenses                                                                                             
// Column:SFAS91_CEDED_DEFERRED_MAINT_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_deferred_maint_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_deferred_maint_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_deferred_maint_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_dth_benefits
// SFAS91 Ceded Death Benefits                                                                                             
// Column:SFAS91_CEDED_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_dth_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_dth_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_maint_exp_bom
// SFAS91 Ceded Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS91_CEDED_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(339,"sfas91_ceded_maint_exp_bom",t);
}



//^^^

#line 1 "sfas91_ceded_maint_exp_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_maint_exp_eom
// SFAS91 Ceded Maintenance Expenses End of Month                                                                                             
// Column:SFAS91_CEDED_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_maint_exp_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_maint_exp_res_cash_flow_bom
// SFAS91 Ceded Maintenance Expense Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_CEDED_MAINT_EXP_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_res_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(341,"sfas91_ceded_maint_exp_res_cash_flow_bom",t);
}



//^^^

#line 1 "sfas91_ceded_maint_exp_res_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_maint_exp_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_maint_exp_res_cash_flow_eom
// SFAS91 Ceded Maintenance Expense Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_CEDED_MAINT_EXP_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_res_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(342,"sfas91_ceded_maint_exp_res_cash_flow_eom",t);
}



//^^^

#line 1 "sfas91_ceded_maint_exp_res_cash_flow_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_maint_exp_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_net_res_cash_flow_bom
// SFAS91 Ceded Net Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_CEDED_NET_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_net_res_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(343,"sfas91_ceded_net_res_cash_flow_bom",t);
}



//^^^

#line 1 "sfas91_ceded_net_res_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_net_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_net_res_cash_flow_eom
// SFAS91 Ceded Net Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_CEDED_NET_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_net_res_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(344,"sfas91_ceded_net_res_cash_flow_eom",t);
}



//^^^

#line 1 "sfas91_ceded_net_res_cash_flow_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_net_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_noncapzd_acq_exp
// SFAS91 Ceded Non-Capitalized Acquisition Expenses                                                                                             
// Column:SFAS91_CEDED_NONCAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_noncapzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_noncapzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_noncapzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_policies_b
// SFAS91 Ceded Policies In Force Beginning of Month                                                                                             
// Column:SFAS91_CEDED_POLICIES_B
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_policies_b(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_policies_b.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_policies_b", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_prem_paid
// SFAS91 Ceded Premium Paid                                                                                             
// Column:SFAS91_CEDED_PREM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_prem_paid(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_prem_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_prem_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_prem_tax
// SFAS91 Ceded Premium Tax                                                                                             
// Column:SFAS91_CEDED_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_res_ann_benefits
// SFAS91 Ceded Annuity Benefits for Reserves                                                                                             
// Column:SFAS91_CEDED_RES_ANN_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_res_ann_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_res_ann_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_res_ann_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_ceded_res_dth_benefits
// SFAS91 Ceded Death Benefits for Reserves                                                                                             
// Column:SFAS91_CEDED_RES_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_ceded_res_dth_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_ceded_res_dth_benefits.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_ceded_res_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_acq_exp
// SFAS91 Gross Acquisition Expenses                                                                                             
// Column:SFAS91_GROSS_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ann_benefits_bom
// SFAS91 Gross Annuity Benefits Beginning of Month                                                                                             
// Column:SFAS91_GROSS_ANN_BENEFITS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ann_benefits_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ann_benefits_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ann_benefits_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ann_benefits_eom
// SFAS91 Gross Annuity Benefits End of Month                                                                                             
// Column:SFAS91_GROSS_ANN_BENEFITS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ann_benefits_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ann_benefits_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ann_benefits_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ben_maint_exp_res_cash_flow_bom
// SFAS91 Gross Benefit and Maintenance Expense Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_GROSS_BEN_MAINT_EXP_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ben_maint_exp_res_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ben_maint_exp_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ben_maint_exp_res_cash_flow_eom
// SFAS91 Gross Benefit and Maintenance Expense Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_GROSS_BEN_MAINT_EXP_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ben_maint_exp_res_cash_flow_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ben_maint_exp_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ben_res_cash_flow_bom
// SFAS91 Gross Benefit Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_GROSS_BEN_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_res_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ben_res_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ben_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_ben_res_cash_flow_eom
// SFAS91 Gross Benefit Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_GROSS_BEN_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_res_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_ben_res_cash_flow_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_ben_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_capzd_acq_exp
// SFAS91 Gross Capitalized Acquisition Expenses                                                                                             
// Column:SFAS91_GROSS_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_capzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_capzd_comm_bom
// SFAS91 Gross Capitalized Commissions Beginning of Month                                                                                             
// Column:SFAS91_GROSS_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_capzd_comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_cash_flow_bom
// SFAS91 Gross Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_GROSS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_comm_excess_bom
// SFAS91 Gross Commission Excess Beginning of Month                                                                                             
// Column:SFAS91_GROSS_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_comm_excess_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_deferred_maint_exp
// SFAS91 Gross Deferred Maintenance Expenses                                                                                             
// Column:SFAS91_GROSS_DEFERRED_MAINT_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_deferred_maint_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_deferred_maint_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_deferred_maint_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_dth_benefits
// SFAS91 Gross Death Benefits                                                                                             
// Column:SFAS91_GROSS_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_dth_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_dth_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_maint_exp_bom
// SFAS91 Gross Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS91_GROSS_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(364,"sfas91_gross_maint_exp_bom",t);
}



//^^^

#line 1 "sfas91_gross_maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_maint_exp_eom
// SFAS91 Gross Maintenance Expenses End of Month                                                                                             
// Column:SFAS91_GROSS_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_maint_exp_res_cash_flow_bom
// SFAS91 Gross Maintenance Expense Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_GROSS_MAINT_EXP_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_res_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(366,"sfas91_gross_maint_exp_res_cash_flow_bom",t);
}



//^^^

#line 1 "sfas91_gross_maint_exp_res_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_maint_exp_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_maint_exp_res_cash_flow_eom
// SFAS91 Gross Maintenance Expense Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_GROSS_MAINT_EXP_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_res_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(367,"sfas91_gross_maint_exp_res_cash_flow_eom",t);
}



//^^^

#line 1 "sfas91_gross_maint_exp_res_cash_flow_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_maint_exp_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_net_res_cash_flow_bom
// SFAS91 Gross Net Reserve Cash Flow Beginning of Month                                                                                             
// Column:SFAS91_GROSS_NET_RES_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_net_res_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(368,"sfas91_gross_net_res_cash_flow_bom",t);
}



//^^^

#line 1 "sfas91_gross_net_res_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_net_res_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_net_res_cash_flow_eom
// SFAS91 Gross Net Reserve Cash Flow End of Month                                                                                             
// Column:SFAS91_GROSS_NET_RES_CASH_FLOW_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_net_res_cash_flow_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(369,"sfas91_gross_net_res_cash_flow_eom",t);
}



//^^^

#line 1 "sfas91_gross_net_res_cash_flow_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_net_res_cash_flow_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_noncapzd_acq_exp
// SFAS91 Gross Non-Capitalized Acquisition Expenses                                                                                             
// Column:SFAS91_GROSS_NONCAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_noncapzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_noncapzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_noncapzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_policies_b
// SFAS91 Gross Policies In Force Beginning of Month                                                                                             
// Column:SFAS91_GROSS_POLICIES_B
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_policies_b(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_policies_b.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_policies_b", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_prem_paid
// SFAS91 Gross Premium Paid                                                                                             
// Column:SFAS91_GROSS_PREM_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_prem_paid(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_prem_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_prem_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_prem_tax
// SFAS91 Gross Premium Tax                                                                                             
// Column:SFAS91_GROSS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_res_ann_benefits
// SFAS91 Gross Annuity Benefits for Reserves                                                                                             
// Column:SFAS91_GROSS_RES_ANN_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_res_ann_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_res_ann_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_res_ann_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas91_gross_res_dth_benefits
// SFAS91 Gross Death Benefits for Reserves                                                                                             
// Column:SFAS91_GROSS_RES_DTH_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas91_gross_res_dth_benefits(int t) {
//^^^



//^^^

#line 1 "sfas91_gross_res_dth_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas91_gross_res_dth_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_acq_exp
// SFAS97 Limited Pay Ceded Acquisition Expenses                                                                                             
// Column:SFAS97LP_CEDED_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_ann_claim_cost
// SFAS97 Limited Pay Ceded Annuity Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_ANN_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ann_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_ann_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_ann_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_ben_res_accrual_valn_basis
// SFAS97LP Ceded Benefit Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_BEN_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_ben_res_accrual_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_ben_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_ben_res_int_valn_basis
// SFAS97LP Ceded Benefit Reserve Interest Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_BEN_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_ben_res_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_ben_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_ben_res_prelim
// SFAS97 Limited Pay Ceded Benefit Reserve Preliminary                                                                                             
// Column:SFAS97LP_CEDED_BEN_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_ben_res_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_ben_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_benefits_valn_basis
// SFAS97LP Ceded Benefits Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_BENEFITS_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_benefits_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_benefits_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_benefits_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_acq_exp
// SFAS97 Limited Pay Ceded Capitalized Acquisition Expenses                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_acq_exp_valn_basis
// SFAS97 Limited Pay Ceded Capitalized Acquisition Expenses Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_ACQ_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_acq_exp_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_acq_exp_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_acq_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_comm_bom
// SFAS97 Limited Pay Ceded Capitalized Commissions BOM                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_comm_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_comm_chargeback
// SFAS97 Limited Pay Ceded Capitalized Commission Chargeback                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_comm_eom
// SFAS97 Limited Pay Ceded Capitalized Commission EOM                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_comm_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_capzd_comm_valn_basis
// SFAS97LP Ceded Capitalized Commission Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_CAPZD_COMM_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_capzd_comm_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_capzd_comm_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_cash_flow_bom
// SFAS97 Limited Pay Ceded Cash Flow BOM                                                                                             
// Column:SFAS97LP_CEDED_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_claim_res
// SFAS97 Limited Pay Ceded Claim Reserve                                                                                             
// Column:SFAS97LP_CEDED_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_claim_res(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_claim_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_chargeback
// SFAS97 Limited Pay Ceded Commission Chargeback                                                                                             
// Column:SFAS97LP_CEDED_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_excess_bom
// SFAS97 Limited Pay Ceded Commissions Excess BOM                                                                                             
// Column:SFAS97LP_CEDED_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_excess_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_excess_eom
// SFAS97 Limited Pay Ceded Commissions Excess EOM                                                                                             
// Column:SFAS97LP_CEDED_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_excess_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_trail_bom
// SFAS97 Limited Pay Ceded Commissions Trail BOM                                                                                             
// Column:SFAS97LP_CEDED_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_trail_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_trail_bom_base_plan
// SFAS97 Limited Pay Ceded Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS97LP_CEDED_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_trail_bom_base_plan.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_trail_bom_rider
// SFAS97 Limited Pay Ceded Commissions Trail BOM Rider                                                                                             
// Column:SFAS97LP_CEDED_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_trail_bom_rider.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_comm_trail_eom
// SFAS97 Limited Pay Ceded Commissions Trail EOM                                                                                             
// Column:SFAS97LP_CEDED_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_comm_trail_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_comm_trail_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_conversion_cost
// SFAS97 Limited Pay Ceded Conversion Cost                                                                                             
// Column:SFAS97LP_CEDED_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_conversion_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_dac_amortzn_valn_basis
// SFAS97LP Ceded DAC Amortization Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DAC_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_dac_amortzn_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_dac_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_dac_int_valn_basis
// SFAS97LP Ceded DAC Interest Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DAC_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_dac_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_dac_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_dac_prelim
// SFAS97 Limited Pay Ceded DAC Preliminary                                                                                             
// Column:SFAS97LP_CEDED_DAC_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_dac_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_dac_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_deferred_prof_amortzn_valn_basis
// SFAS97LP Ceded Deferred Profit Amortization Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DEFERRED_PROF_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_deferred_prof_amortzn_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_deferred_prof_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_deferred_prof_int_valn_basis
// SFAS97LP Ceded Deferred Profit Interest Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DEFERRED_PROF_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_deferred_prof_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_deferred_prof_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_deferred_prof_liab_prelim
// SFAS97 Limited Pay Ceded Deferred Profit Liability Preliminary                                                                                             
// Column:SFAS97LP_CEDED_DEFERRED_PROF_LIAB_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_liab_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_deferred_prof_liab_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_deferred_prof_liab_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_deferred_prof_valn_basis
// SFAS97LP Ceded Deferred Profit Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DEFERRED_PROF_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_deferred_prof_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_deferred_prof_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_div_applied
// SFAS97 Limited Pay Ceded Dividends Applied                                                                                             
// Column:SFAS97LP_CEDED_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_div_applied.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_div_paid
// SFAS97 Limited Pay Ceded Annual Dividends Paid                                                                                             
// Column:SFAS97LP_CEDED_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_div_paid.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_div_valn_basis
// SFAS97LP Ceded Annual Dividends Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_DIV_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_div_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_div_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_dth_claim_cost
// SFAS97 Limited Pay Ceded Death Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_dth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_endow_claim_cost
// SFAS97 Limited Pay Ceded Endowment Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_endow_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_exp_valn_basis
// SFAS97LP Ceded Expenses Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_exp_valn_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(410,"sfas97lp_ceded_exp_valn_basis",t);
}



//^^^

#line 1 "sfas97lp_ceded_exp_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_gpr
// SFAS97 Limited Pay Ceded Gross Premium Reserve                                                                                             
// Column:SFAS97LP_CEDED_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gpr(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_gpr.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_gpr_units_inf
// SFAS97 Limited Pay Ceded Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS97LP_CEDED_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_gpr_units_inf.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_gross_prem
// SFAS97 Limited Pay Ceded Gross Premium                                                                                             
// Column:SFAS97LP_CEDED_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_gross_prem.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_hlth_claim_cost
// SFAS97 Limited Pay Ceded Health Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_HLTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_hlth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_hlth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_hlth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_loc_cost
// SFAS97 Limited Pay Ceded Letter of Credit Cost                                                                                             
// Column:SFAS97LP_CEDED_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_loc_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maint_exp_bom
// SFAS97 Limited Pay Ceded Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS97LP_CEDED_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(416,"sfas97lp_ceded_maint_exp_bom",t);
}



//^^^

#line 1 "sfas97lp_ceded_maint_exp_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maint_exp_eom
// SFAS97 Limited Pay Ceded Maintenance Expenses End of Month                                                                                             
// Column:SFAS97LP_CEDED_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_maint_exp_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maint_exp_res_accrual_valn_basis
// SFAS97LP Ceded Maintenance Expense Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_MAINT_EXP_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_maint_exp_res_accrual_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maint_exp_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maint_exp_res_int_valn_basis
// SFAS97LP Ceded Maintenance Expense Reserve Interest Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_MAINT_EXP_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_maint_exp_res_int_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maint_exp_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maint_exp_res_prelim
// SFAS97 Limited Pay Ceded Maintenance Expense Reserve Preliminary                                                                                             
// Column:SFAS97LP_CEDED_MAINT_EXP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_maint_exp_res_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maint_exp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_maturity_claim_cost
// SFAS97 Limited Pay Ceded Maturity Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_maturity_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_modco_liab
// SFAS97 Limited Pay Ceded Modco Liability                                                                                             
// Column:SFAS97LP_CEDED_MODCO_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_modco_liab(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_modco_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_modco_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_modco_res_adj
// SFAS97 Limited Pay Ceded Modified Coinsurance Reserve Adjustment                                                                                             
// Column:SFAS97LP_CEDED_MODCO_RES_ADJ
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_modco_res_adj(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_modco_res_adj.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_modco_res_adj", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_prem_tax
// SFAS97 Limited Pay Ceded Premium Tax                                                                                             
// Column:SFAS97LP_CEDED_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_prem_waiver_res
// SFAS97 Limited Pay Ceded Premium Waiver Reserve                                                                                             
// Column:SFAS97LP_CEDED_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_prem_waiver_res.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_prem_waiver_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_refund
// SFAS97 Limited Pay Ceded Reinsurance Refund                                                                                             
// Column:SFAS97LP_CEDED_REFUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_refund(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_refund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_refund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_surr_ben_valn_basis
// SFAS97LP Ceded Surrender Benefits Valuation Basis                                                                                             
// Column:SFAS97LP_CEDED_SURR_BEN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_surr_ben_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_surr_ben_valn_basis.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_surr_ben_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_surr_claim_cost
// SFAS97 Limited Pay Ceded Surrender Claim Cost                                                                                             
// Column:SFAS97LP_CEDED_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_surr_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_ceded_terminal_div
// SFAS97 Limited Pay Ceded Terminal Dividends                                                                                             
// Column:SFAS97LP_CEDED_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas97lp_ceded_terminal_div.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_ceded_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_acq_exp
// SFAS97 Limited Pay Gross Acquisition Expenses                                                                                             
// Column:SFAS97LP_GROSS_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_ann_claim_cost
// SFAS97 Limited Pay Gross Annuity Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_ANN_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ann_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_ann_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_ann_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_ben_res_accrual_valn_basis
// SFAS97LP Gross Benefit Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_BEN_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_ben_res_accrual_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_ben_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_ben_res_int_valn_basis
// SFAS97LP Gross Benefit Reserve Interest Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_BEN_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_ben_res_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_ben_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_ben_res_prelim
// SFAS97 Limited Pay Gross Benefit Reserve Preliminary                                                                                             
// Column:SFAS97LP_GROSS_BEN_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_ben_res_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_ben_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_benefits_valn_basis
// SFAS97LP Gross Benefits Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_BENEFITS_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_benefits_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_benefits_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_benefits_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_acq_exp
// SFAS97 Limited Pay Gross Capitalized Acquisition Expenses                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_acq_exp_valn_basis
// SFAS97LP Gross Capitalized Acquisition Expenses Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_ACQ_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_acq_exp_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_acq_exp_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_acq_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_comm_bom
// SFAS97 Limited Pay Gross Capitalized Commission BOM                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_comm_chargeback
// SFAS97 Limited Pay Gross Capitalized Commission Chargeback                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_comm_eom
// SFAS97 Limited Pay Gross Capitalized Commission EOM                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_comm_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_comm_valn_basis
// SFAS97LP Gross Capitalized Commission Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_COMM_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_comm_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_comm_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_capzd_reins_yrt_cost
// SFAS97 Limited Pay Gross Capitalized YRT Reinsurance Cost                                                                                             
// Column:SFAS97LP_GROSS_CAPZD_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_capzd_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_capzd_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_cash_flow_bom
// SFAS97 Limited Pay Gross Cash Flow BOM                                                                                             
// Column:SFAS97LP_GROSS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_claim_res
// SFAS97 Limited Pay Gross Claim Reserve                                                                                             
// Column:SFAS97LP_GROSS_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_claim_res(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_chargeback
// SFAS97 Limited Pay Gross Commission Chargeback                                                                                             
// Column:SFAS97LP_GROSS_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_excess_bom
// SFAS97 Limited Pay Gross Commissions Excess BOM                                                                                             
// Column:SFAS97LP_GROSS_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_excess_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_excess_eom
// SFAS97 Limited Pay Gross Commissions Excess EOM                                                                                             
// Column:SFAS97LP_GROSS_COMM_EXCESS_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_excess_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_excess_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_trail_bom
// SFAS97 Limited Pay Gross Commissions Trail BOM                                                                                             
// Column:SFAS97LP_GROSS_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_trail_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_trail_bom_base_plan
// SFAS97 Limited Pay Gross Commissions Trail BOM Base Plan                                                                                             
// Column:SFAS97LP_GROSS_COMM_TRAIL_BOM_BASE_PLAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom_base_plan(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_trail_bom_base_plan.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_trail_bom_base_plan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_trail_bom_rider
// SFAS97 Limited Pay Gross Commissions Trail BOM Rider                                                                                             
// Column:SFAS97LP_GROSS_COMM_TRAIL_BOM_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom_rider(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_trail_bom_rider.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_trail_bom_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_comm_trail_eom
// SFAS97 Limited Pay Gross Commissions Trail EOM                                                                                             
// Column:SFAS97LP_GROSS_COMM_TRAIL_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_comm_trail_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_comm_trail_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_conversion_cost
// SFAS97 Limited Pay Gross Conversion Cost                                                                                             
// Column:SFAS97LP_GROSS_CONVERSION_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_conversion_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_conversion_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_conversion_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_amortzn_valn_basis
// SFAS97LP Gross DAC Amortization Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DAC_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_amortzn_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas60_gross_dac_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_int_valn_basis
// SFAS97LP Gross DAC Interest Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DAC_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_dac_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_prelim
// SFAS97 Limited Pay Gross DAC Preliminary                                                                                             
// Column:SFAS97LP_GROSS_DAC_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_dac_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis
// SFAS97LP Gross Reinsurance YRT Asset Amortization Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DAC_REINS_YRT_ASSET_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_reins_yrt_asset_amortzn_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis
// SFAS97LP Gross Reinsurance YRT Asset Interest Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DAC_REINS_YRT_ASSET_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_reins_yrt_asset_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dac_reins_yrt_asset_prelim
// SFAS97 Limited Pay Gross DAC Reinsurance YRT Asset Preliminary                                                                                             
// Column:SFAS97LP_GROSS_DAC_REINS_YRT_ASSET_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dac_reins_yrt_asset_prelim.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_dac_reins_yrt_asset_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_deferred_prof_amortzn_valn_basis
// SFAS97LP Gross Deferred Profit Amortization Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DEFERRED_PROF_AMORTZN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_amortzn_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_deferred_prof_amortzn_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_deferred_prof_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_deferred_prof_int_valn_basis
// SFAS97LP Gross Deferred Profit Interest Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DEFERRED_PROF_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_deferred_prof_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_deferred_prof_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_deferred_prof_liab_prelim
// SFAS97 Limited Pay Gross Deferred Profit Liability Preliminary                                                                                             
// Column:SFAS97LP_GROSS_DEFERRED_PROF_LIAB_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_liab_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_deferred_prof_liab_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_deferred_prof_liab_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_deferred_prof_valn_basis
// SFAS97LP Gross Deferred Profit Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DEFERRED_PROF_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_deferred_prof_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_deferred_prof_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_div_applied
// SFAS97 Limited Pay Gross Dividends Applied                                                                                             
// Column:SFAS97LP_GROSS_DIV_APPLIED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_applied(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_div_applied.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_div_applied", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_div_paid
// SFAS97 Limited Pay Gross Annual Dividends Paid                                                                                             
// Column:SFAS97LP_GROSS_DIV_PAID
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_paid(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_div_paid.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_div_paid", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_div_valn_basis
// SFAS97LP Gross Annual Dividends Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_DIV_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_div_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_div_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_dth_claim_cost
// SFAS97 Limited Pay Gross Death Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_dth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_endow_claim_cost
// SFAS97 Limited Pay Gross Endowment Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_ENDOW_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_endow_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_endow_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_endow_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_exp_valn_basis
// SFAS97LP Gross Expenses Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_EXP_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_exp_valn_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(468,"sfas97lp_gross_exp_valn_basis",t);
}



//^^^

#line 1 "sfas97lp_gross_exp_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_exp_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_gpr
// SFAS97 Limited Pay Gross Gross Premium Reserve                                                                                             
// Column:SFAS97LP_GROSS_GPR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gpr(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_gpr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_gpr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_gpr_units_inf
// SFAS97 Limited Pay Gross Gross Premium Reserve Units in Force                                                                                             
// Column:SFAS97LP_GROSS_GPR_UNITS_INF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gpr_units_inf(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_gpr_units_inf.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_gpr_units_inf", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_gross_prem
// SFAS97 Limited Pay Gross Gross Premium                                                                                             
// Column:SFAS97LP_GROSS_GROSS_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gross_prem(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_gross_prem.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_gross_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_hlth_claim_cost
// SFAS97 Limited Pay Gross Health Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_HLTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_hlth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_hlth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_hlth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_loc_cost
// SFAS97 Limited Pay Gross Letter of Credit Cost                                                                                             
// Column:SFAS97LP_GROSS_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_loc_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maint_exp_bom
// SFAS97 Limited Pay Gross Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS97LP_GROSS_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(474,"sfas97lp_gross_maint_exp_bom",t);
}



//^^^

#line 1 "sfas97lp_gross_maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maint_exp_eom
// SFAS97 Limited Pay Gross Maintenance Expenses End of Month                                                                                             
// Column:SFAS97LP_GROSS_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maint_exp_res_accrual_valn_basis
// SFAS97LP Gross Maintenance Expense Reserve Accrual Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_MAINT_EXP_RES_ACCRUAL_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_accrual_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_maint_exp_res_accrual_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maint_exp_res_accrual_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maint_exp_res_int_valn_basis
// SFAS97LP Gross Maintenance Expense Reserve Interest Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_MAINT_EXP_RES_INT_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_int_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_maint_exp_res_int_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maint_exp_res_int_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maint_exp_res_prelim
// SFAS97 Limited Pay Gross Maintenance Expense Reserve Preliminary                                                                                             
// Column:SFAS97LP_GROSS_MAINT_EXP_RES_PRELIM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_prelim(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_maint_exp_res_prelim.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maint_exp_res_prelim", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_maturity_claim_cost
// SFAS97 Limited Pay Gross Maturity Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_MATURITY_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maturity_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_maturity_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_maturity_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_pol_loan
// SFAS97 Limited Pay Gross Policy Loan                                                                                             
// Column:SFAS97LP_GROSS_POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_pol_loan(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_pol_loan_inc
// SFAS97 Limited Pay Gross Policy Loan Income                                                                                             
// Column:SFAS97LP_GROSS_POL_LOAN_INC
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_pol_loan_inc(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_pol_loan_inc.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_pol_loan_inc", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_prem_tax
// SFAS97 Limited Pay Gross Premium Tax                                                                                             
// Column:SFAS97LP_GROSS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_prem_tax(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_prem_waiver_res
// SFAS97 Limited Pay Gross Premium Waiver Reserve                                                                                             
// Column:SFAS97LP_GROSS_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_prem_waiver_res(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_prem_waiver_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_reins_yrt_cost
// SFAS97 Limited Pay Gross YRT Reinsurance Cost                                                                                             
// Column:SFAS97LP_GROSS_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_reins_yrt_cost_valn_basis
// SFAS97LP Gross Reinsurance YRT Cost Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_REINS_YRT_COST_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_reins_yrt_cost_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_reins_yrt_cost_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_reins_yrt_cost_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_stat_res_rider
// SFAS97 Limited Pay Statutory Reserve for Riders                                                                                             
// Column:SFAS97LP_GROSS_STAT_RES_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_stat_res_rider(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_stat_res_rider.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_stat_res_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_surr_ben_valn_basis
// SFAS97LP Gross Surrender Benefits Valuation Basis                                                                                             
// Column:SFAS97LP_GROSS_SURR_BEN_VALN_BASIS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_surr_ben_valn_basis(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_surr_ben_valn_basis.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_surr_ben_valn_basis", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_surr_claim_cost
// SFAS97 Limited Pay Gross Surrender Claim Cost                                                                                             
// Column:SFAS97LP_GROSS_SURR_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_surr_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_surr_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_surr_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97lp_gross_terminal_div
// SFAS97 Limited Pay GrossTerminal Dividends                                                                                             
// Column:SFAS97LP_GROSS_TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97lp_gross_terminal_div(int t) {
//^^^



//^^^

#line 1 "sfas97lp_gross_terminal_div.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97lp_gross_terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_acq_exp
// SFAS97RD Ceded Acquisition Expenses                                                                                             
// Column:SFAS97RD_CEDED_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(490,"sfas97rd_ceded_acq_exp",t);
}



//^^^

#line 1 "sfas97rd_ceded_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("sfas97rd_ceded_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_cap_gain_fund
// SFAS97RD Ceded Capital Gain on Fund                                                                                             
// Column:SFAS97RD_CEDED_CAP_GAIN_FUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_cap_gain_fund(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_cap_gain_fund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_cap_gain_fund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_capzd_acq_exp
// SFAS97RD Ceded Capitalized Acquisition Expenses                                                                                             
// Column:SFAS97RD_CEDED_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_capzd_acq_exp.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_capzd_comm_bom
// SFAS97RD Ceded Capitalized Commissions BOM                                                                                             
// Column:SFAS97RD_CEDED_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_capzd_comm_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_capzd_comm_chargeback
// SFAS97RD Ceded Capitalized Commissions Chargeback                                                                                             
// Column:SFAS97RD_CEDED_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_capzd_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_capzd_comm_eom
// SFAS97RD Ceded Capitalized Commissions EOM                                                                                             
// Column:SFAS97RD_CEDED_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_capzd_comm_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_capzd_prem_bonus
// SFAS97RD Ceded Capitalized Premium Bonus                                                                                             
// Column:SFAS97RD_CEDED_CAPZD_PREM_BONUS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_prem_bonus(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_capzd_prem_bonus.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_capzd_prem_bonus", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_cash_flow_bom
// SFAS97RD Ceded Cash Flow BOM                                                                                             
// Column:SFAS97RD_CEDED_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_cash_flow_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_charges
// SFAS97RD Ceded Charges                                                                                             
// Column:SFAS97RD_CEDED_CHARGES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_charges(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_charges.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_charges", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_comm_chargeback
// SFAS97RD Ceded Commission Chargeback                                                                                             
// Column:SFAS97RD_CEDED_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(499,"sfas97rd_ceded_comm_chargeback",t);
}



//^^^

#line 1 "sfas97rd_ceded_comm_chargeback.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_comm_excess_bom
// SFAS97RD Ceded Commissions Excess BOM                                                                                             
// Column:SFAS97RD_CEDED_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_comm_excess_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_comm_trail_bom
// SFAS97RD Ceded Commissions Trail BOM                                                                                             
// Column:SFAS97RD_CEDED_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_comm_trail_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_credited_int
// SFAS97RD Ceded Credited Interest                                                                                             
// Column:SFAS97RD_CEDED_CREDITED_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(502,"sfas97rd_ceded_credited_int",t);
}



//^^^

#line 1 "sfas97rd_ceded_credited_int.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_credited_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_deferred_loads
// SFAS97RD Ceded Deferred Loads                                                                                             
// Column:SFAS97RD_CEDED_DEFERRED_LOADS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_deferred_loads(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_deferred_loads.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_deferred_loads", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_dth_claim_cost
// SFAS97RD Ceded Death Claim Cost                                                                                             
// Column:SFAS97RD_CEDED_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_dth_claim_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_egp_gain_inv
// SFAS97RD Ceded EGP Investment Gain                                                                                             
// Column:SFAS97RD_CEDED_EGP_GAIN_INV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_inv(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_egp_gain_inv.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_egp_gain_inv", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_egp_gain_mort
// SFAS97RD Ceded EGP Mortality Gain                                                                                             
// Column:SFAS97RD_CEDED_EGP_GAIN_MORT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_mort(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_egp_gain_mort.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_egp_gain_mort", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_egp_gain_surr
// SFAS97RD Ceded EGP Surrender Gain                                                                                             
// Column:SFAS97RD_CEDED_EGP_GAIN_SURR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_surr(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_egp_gain_surr.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_egp_gain_surr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_embed_deriv_cash_flow
// SFAS97RD Ceded Embedded derivative cash flow                                                                                             
// Column:SFAS97RD_CEDED_EMBED_DERIV_CASH_FLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_embed_deriv_cash_flow(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_embed_deriv_cash_flow.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_embed_deriv_cash_flow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_fund_val_aft_int
// SFAS97RD Ceded Fund Value After Interest                                                                                             
// Column:SFAS97RD_CEDED_FUND_VAL_AFT_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_aft_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_fund_val_aft_int.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_fund_val_aft_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_fund_val_bef_int
// SFAS97RD Ceded Fund Value Before Interest                                                                                             
// Column:SFAS97RD_CEDED_FUND_VAL_BEF_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_bef_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_fund_val_bef_int.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_fund_val_bef_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_fund_val_fixed
// SFAS97RD Ceded Fund Value Fixed Account                                                                                             
// Column:SFAS97RD_CEDED_FUND_VAL_FIXED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_fixed(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(511,"sfas97rd_ceded_fund_val_fixed",t);
}



//^^^

#line 1 "sfas97rd_ceded_fund_val_fixed.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_fund_val_fixed", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_fund_val_sa
// SFAS97RD Ceded Fund Value Separate Account                                                                                             
// Column:SFAS97RD_CEDED_FUND_VAL_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(512,"sfas97rd_ceded_fund_val_sa",t);
}



//^^^

#line 1 "sfas97rd_ceded_fund_val_sa.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_fund_val_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_gmab_ben
// SFAS97RD Ceded GMAB Benefits                                                                                             
// Column:SFAS97RD_CEDED_GMAB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmab_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_gmab_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_gmab_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_gmdb_ben
// SFAS97RD Ceded GMDB Benefits                                                                                             
// Column:SFAS97RD_CEDED_GMDB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmdb_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_gmdb_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_gmdb_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_gmib_ben
// SFAS97RD Ceded GMIB Benefits                                                                                             
// Column:SFAS97RD_CEDED_GMIB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmib_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_gmib_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_gmib_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_gmwb_ben
// SFAS97RD Ceded GMWB Benefits                                                                                             
// Column:SFAS97RD_CEDED_GMWB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmwb_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_gmwb_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_gmwb_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_hedge_cash_flow
// SFAS97RD Ceded Hedge Cash Flow                                                                                             
// Column:SFAS97RD_CEDED_HEDGE_CASH_FLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_hedge_cash_flow.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_hedge_cash_flow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_hedge_mkt_val
// SFAS97RD Ceded Hedge Market Value                                                                                             
// Column:SFAS97RD_CEDED_HEDGE_MKT_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_hedge_mkt_val.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_hedge_mkt_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_host_contract_cred_int
// SFAS97RD Ceded Host Contract Credited Interest                                                                                             
// Column:SFAS97RD_CEDED_HOST_CONTRACT_CRED_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_cred_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_host_contract_cred_int.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_host_contract_cred_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_host_contract_val
// SFAS97RD Ceded Host Contract Value                                                                                             
// Column:SFAS97RD_CEDED_HOST_CONTRACT_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_host_contract_val.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_host_contract_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_host_contract_val_bef
// SFAS97RD Ceded Host Contract Value - Before Decrements                                                                                             
// Column:SFAS97RD_CEDED_HOST_CONTRACT_VAL_BEF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_val_bef(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_host_contract_val_bef.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_host_contract_val_bef", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_inv_inc_fund
// SFAS97RD Ceded Investment Income on Fund                                                                                             
// Column:SFAS97RD_CEDED_INV_INC_FUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_inv_inc_fund(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_inv_inc_fund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_inv_inc_fund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_loads
// SFAS97RD Ceded Loads                                                                                             
// Column:SFAS97RD_CEDED_LOADS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_loads(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_loads.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_loads", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_loc_cost
// SFAS97RD Ceded Letter of Credit Cost                                                                                             
// Column:SFAS97RD_CEDED_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_loc_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_maint_exp_bom
// SFAS97RD Ceded Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS97RD_CEDED_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(525,"sfas97rd_ceded_maint_exp_bom",t);
}



//^^^

#line 1 "sfas97rd_ceded_maint_exp_bom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_maint_exp_eom
// SFAS97RD Ceded Maintenance Expenses End of Month                                                                                             
// Column:SFAS97RD_CEDED_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(526,"sfas97rd_ceded_maint_exp_eom",t);
}



//^^^

#line 1 "sfas97rd_ceded_maint_exp_eom.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_modco_liab
// SFAS97RD Ceded Modco Liability                                                                                             
// Column:SFAS97RD_CEDED_MODCO_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_modco_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(527,"sfas97rd_ceded_modco_liab",t);
}



//^^^

#line 1 "sfas97rd_ceded_modco_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_modco_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_modco_res_adj
// SFAS97RD Ceded Modco Reserve Adjustment                                                                                             
// Column:SFAS97RD_CEDED_MODCO_RES_ADJ
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_modco_res_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(528,"sfas97rd_ceded_modco_res_adj",t);
}



//^^^

#line 1 "sfas97rd_ceded_modco_res_adj.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_modco_res_adj", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_persist_bon_ref
// SFAS97RD Ceded Persistency Bonus/Refunds                                                                                             
// Column:SFAS97RD_CEDED_PERSIST_BON_REF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_persist_bon_ref(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_persist_bon_ref.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_persist_bon_ref", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_policies_b
// SFAS97RD Ceded Policies In Force Beginning of Month                                                                                             
// Column:SFAS97RD_CEDED_POLICIES_B
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_policies_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(530,"sfas97rd_ceded_policies_b",t);
}



//^^^

#line 1 "sfas97rd_ceded_policies_b.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_policies_b", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_prem_bonus
// SFAS97RD Ceded Premium Bonus                                                                                             
// Column:SFAS97RD_CEDED_PREM_BONUS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_prem_bonus(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_prem_bonus.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_prem_bonus", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_prem_tax
// SFAS97RD Ceded Premium Taxes                                                                                             
// Column:SFAS97RD_CEDED_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(532,"sfas97rd_ceded_prem_tax",t);
}



//^^^

#line 1 "sfas97rd_ceded_prem_tax.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_refund
// SFAS97RD Ceded Reinsurance Refund                                                                                             
// Column:SFAS97RD_CEDED_REFUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_refund(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(533,"sfas97rd_ceded_refund",t);
}



//^^^

#line 1 "sfas97rd_ceded_refund.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_refund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_rider_charges
// SFAS97RD Ceded Rider Charges                                                                                             
// Column:SFAS97RD_CEDED_RIDER_CHARGES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_rider_charges(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_rider_charges.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_rider_charges", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sfas133_gmab_liab
// SFAS97RD Ceded SFAS 133 GMAB Liability                                                                                             
// Column:SFAS97RD_CEDED_SFAS133_GMAB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmab_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sfas133_gmab_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sfas133_gmab_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sfas133_gmib_liab
// SFAS97RD Ceded SFAS 133 GMIB Liability                                                                                             
// Column:SFAS97RD_CEDED_SFAS133_GMIB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmib_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sfas133_gmib_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sfas133_gmib_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sfas133_gmwb_liab
// SFAS97RD Ceded SFAS 133 GMWB Liability                                                                                             
// Column:SFAS97RD_CEDED_SFAS133_GMWB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sfas133_gmwb_liab.EPL_LIAB.for"
if (!reins_flag || t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sfas133_gmwb_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sop031_assess
// SFAS97RD Ceded SOP 03-1 Assessments                                                                                             
// Column:SFAS97RD_CEDED_SOP031_ASSESS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_assess(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sop031_assess.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sop031_assess", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sop031_coi_assess
// SFAS97RD Ceded SOP 03-1 COI Assessments                                                                                             
// Column:SFAS97RD_CEDED_SOP031_COI_ASSESS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_coi_assess(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sop031_coi_assess.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sop031_coi_assess", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sop031_coi_ben
// SFAS97RD Ceded SOP 03-1 COI Benefit                                                                                             
// Column:SFAS97RD_CEDED_SOP031_COI_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_coi_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sop031_coi_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sop031_coi_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sop031_pbr
// SFAS97RD Ceded SOP 03-1 Persistency Bonus/Refunds                                                                                             
// Column:SFAS97RD_CEDED_SOP031_PBR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_pbr(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sop031_pbr.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sop031_pbr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_sop031_pbr_fund_val
// SFAS97RD Ceded SOP 03-1 Persistency Bonus/Refund Fund Value                                                                                             
// Column:SFAS97RD_CEDED_SOP031_PBR_FUND_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_pbr_fund_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_sop031_pbr_fund_val.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_sop031_pbr_fund_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_ceded_ulsg_ben
// SFAS97RD Ceded ULSG Benefits                                                                                             
// Column:SFAS97RD_CEDED_ULSG_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_ulsg_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_ceded_ulsg_ben.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_ceded_ulsg_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_acq_exp
// SFAS97RD Gross Acquisition Expenses                                                                                             
// Column:SFAS97RD_GROSS_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(544,"sfas97rd_gross_acq_exp",t);
}



//^^^

#line 1 "sfas97rd_gross_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("sfas97rd_gross_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_cap_gain_fund
// SFAS97RD Gross Capital Gain on Fund                                                                                             
// Column:SFAS97RD_GROSS_CAP_GAIN_FUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_cap_gain_fund(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_cap_gain_fund.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_cap_gain_fund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_acq_exp
// SFAS97RD Gross Capitalized Acquisition Expenses                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_ACQ_EXP
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_acq_exp.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_acq_exp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_comm_bom
// SFAS97RD Gross Capitalized Commissions BOM                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_COMM_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_comm_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_comm_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_comm_chargeback
// SFAS97RD Gross Capitalized Commissions Chargeback                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_comm_eom
// SFAS97RD Gross Capitalized Commissions EOM                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_COMM_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_comm_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_comm_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_prem_bonus
// SFAS97RD Gross Capitalized Premium Bonus                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_PREM_BONUS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_prem_bonus(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_prem_bonus.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_prem_bonus", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_capzd_reins_yrt_cost
// SFAS97RD Gross Capitalized YRT Reinsurance Cost                                                                                             
// Column:SFAS97RD_GROSS_CAPZD_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_capzd_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_capzd_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_cash_flow_bom
// SFAS97RD Gross Cash Flow BOM                                                                                             
// Column:SFAS97RD_GROSS_CASH_FLOW_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_cash_flow_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_cash_flow_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_charges
// SFAS97RD Gross Charges                                                                                             
// Column:SFAS97RD_GROSS_CHARGES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_charges(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_charges.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_charges", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_comm_chargeback
// SFAS97RD Gross Commission Chargeback                                                                                             
// Column:SFAS97RD_GROSS_COMM_CHARGEBACK
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(554,"sfas97rd_gross_comm_chargeback",t);
}



//^^^

#line 1 "sfas97rd_gross_comm_chargeback.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_comm_chargeback", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_comm_excess_bom
// SFAS97RD Gross Commissions Excess BOM                                                                                             
// Column:SFAS97RD_GROSS_COMM_EXCESS_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_comm_excess_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_comm_excess_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_comm_trail_bom
// SFAS97RD Gross Commissions Trail BOM                                                                                             
// Column:SFAS97RD_GROSS_COMM_TRAIL_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_comm_trail_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_comm_trail_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_credited_int
// SFAS97RD Gross Credited Interest                                                                                             
// Column:SFAS97RD_GROSS_CREDITED_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(557,"sfas97rd_gross_credited_int",t);
}



//^^^

#line 1 "sfas97rd_gross_credited_int.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_credited_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_deferred_loads
// SFAS97RD Gross Deferred Loads                                                                                             
// Column:SFAS97RD_GROSS_DEFERRED_LOADS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_deferred_loads(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_deferred_loads.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_deferred_loads", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_dth_claim_cost
// SFAS97RD Gross Death Claim Cost                                                                                             
// Column:SFAS97RD_GROSS_DTH_CLAIM_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_dth_claim_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_dth_claim_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_egp_gain_inv
// SFAS97RD Gross EGP Investment Gain                                                                                             
// Column:SFAS97RD_GROSS_EGP_GAIN_INV
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_inv(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_egp_gain_inv.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_egp_gain_inv", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_egp_gain_mort
// SFAS97RD Gross EGP Mortality Gain                                                                                             
// Column:SFAS97RD_GROSS_EGP_GAIN_MORT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_mort(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_egp_gain_mort.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_egp_gain_mort", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_egp_gain_surr
// SFAS97RD Gross EGP Surrender Gain                                                                                             
// Column:SFAS97RD_GROSS_EGP_GAIN_SURR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_surr(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_egp_gain_surr.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_egp_gain_surr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_embed_deriv_cash_flow
// SFAS97RD Gross Embedded derivative cash flow                                                                                             
// Column:SFAS97RD_GROSS_EMBED_DERIV_CASH_FLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_embed_deriv_cash_flow(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_embed_deriv_cash_flow.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_embed_deriv_cash_flow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_fund_val_aft_int
// SFAS97RD Gross Fund Value After Interest                                                                                             
// Column:SFAS97RD_GROSS_FUND_VAL_AFT_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_aft_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_fund_val_aft_int.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_fund_val_aft_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_fund_val_bef_int
// SFAS97RD Gross Fund Value Before Interest                                                                                             
// Column:SFAS97RD_GROSS_FUND_VAL_BEF_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_bef_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_fund_val_bef_int.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_fund_val_bef_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_fund_val_fixed
// SFAS97RD Gross Fund Value Fixed Account                                                                                             
// Column:SFAS97RD_GROSS_FUND_VAL_FIXED
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_fixed(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(566,"sfas97rd_gross_fund_val_fixed",t);
}



//^^^

#line 1 "sfas97rd_gross_fund_val_fixed.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_fund_val_fixed", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_fund_val_sa
// SFAS97RD Gross Fund Value Separate Account                                                                                             
// Column:SFAS97RD_GROSS_FUND_VAL_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(567,"sfas97rd_gross_fund_val_sa",t);
}



//^^^

#line 1 "sfas97rd_gross_fund_val_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_fund_val_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_gmab_ben
// SFAS97RD Gross GMAB Benefits                                                                                             
// Column:SFAS97RD_GROSS_GMAB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmab_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_gmab_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_gmab_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_gmdb_ben
// SFAS97RD Gross GMDB Benefits                                                                                             
// Column:SFAS97RD_GROSS_GMDB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmdb_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_gmdb_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_gmdb_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_gmib_ben
// SFAS97RD Gross GMIB Benefits                                                                                             
// Column:SFAS97RD_GROSS_GMIB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmib_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_gmib_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_gmib_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_gmwb_ben
// SFAS97RD Gross GMWB Benefits                                                                                             
// Column:SFAS97RD_GROSS_GMWB_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmwb_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_gmwb_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_gmwb_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_hedge_cash_flow
// SFAS97RD Gross Hedge Cash Flow                                                                                             
// Column:SFAS97RD_GROSS_HEDGE_CASH_FLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_hedge_cash_flow.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_hedge_cash_flow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_hedge_mkt_val
// SFAS97RD Gross Hedge Market Value                                                                                             
// Column:SFAS97RD_GROSS_HEDGE_MKT_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_hedge_mkt_val.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_hedge_mkt_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_host_contract_cred_int
// SFAS97RD Gross Host Contract Credited Interest                                                                                             
// Column:SFAS97RD_GROSS_HOST_CONTRACT_CRED_INT
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_cred_int(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_host_contract_cred_int.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_host_contract_cred_int", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_host_contract_val
// SFAS97RD Gross Host Contract Value                                                                                             
// Column:SFAS97RD_GROSS_HOST_CONTRACT_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_host_contract_val.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_host_contract_val", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_host_contract_val_bef
// SFAS97RD Gross Host Contract Value - Before Decrements                                                                                             
// Column:SFAS97RD_GROSS_HOST_CONTRACT_VAL_BEF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_val_bef(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_host_contract_val_bef.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_host_contract_val_bef", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_inv_inc_fund
// SFAS97RD Gross Investment Income on Fund                                                                                             
// Column:SFAS97RD_GROSS_INV_INC_FUND
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_inv_inc_fund(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_inv_inc_fund.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_inv_inc_fund", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_loads
// SFAS97RD Gross Loads                                                                                             
// Column:SFAS97RD_GROSS_LOADS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_loads(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_loads.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_loads", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_loc_cost
// SFAS97RD Gross Letter of Credit Cost                                                                                             
// Column:SFAS97RD_GROSS_LOC_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_loc_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_loc_cost.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_loc_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_maint_exp_bom
// SFAS97RD Gross Maintenance Expenses Beginning of Month                                                                                             
// Column:SFAS97RD_GROSS_MAINT_EXP_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(580,"sfas97rd_gross_maint_exp_bom",t);
}



//^^^

#line 1 "sfas97rd_gross_maint_exp_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_maint_exp_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_maint_exp_eom
// SFAS97RD Gross Maintenance Expenses End of Month                                                                                             
// Column:SFAS97RD_GROSS_MAINT_EXP_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(581,"sfas97rd_gross_maint_exp_eom",t);
}



//^^^

#line 1 "sfas97rd_gross_maint_exp_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_maint_exp_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_persist_bon_ref
// SFAS97RD Gross Persistency Bonus/Refunds                                                                                             
// Column:SFAS97RD_GROSS_PERSIST_BON_REF
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_persist_bon_ref(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_persist_bon_ref.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_persist_bon_ref", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_pol_loan
// SFAS97RD Gross Policy Loan                                                                                             
// Column:SFAS97RD_GROSS_POL_LOAN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_pol_loan(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_pol_loan.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_pol_loan", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_pol_loan_inc
// SFAS97RD Gross Policy Loan Income                                                                                             
// Column:SFAS97RD_GROSS_POL_LOAN_INC
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_pol_loan_inc(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_pol_loan_inc.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_pol_loan_inc", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_policies_b
// SFAS97RD Gross Policies In Force Beginning of Month                                                                                             
// Column:SFAS97RD_GROSS_POLICIES_B
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_policies_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(585,"sfas97rd_gross_policies_b",t);
}



//^^^

#line 1 "sfas97rd_gross_policies_b.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_policies_b", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_prem_bonus
// SFAS97RD Gross Premium Bonus                                                                                             
// Column:SFAS97RD_GROSS_PREM_BONUS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_prem_bonus(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_prem_bonus.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_prem_bonus", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_prem_tax
// SFAS97RD Gross Premium Taxes                                                                                             
// Column:SFAS97RD_GROSS_PREM_TAX
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(587,"sfas97rd_gross_prem_tax",t);
}



//^^^

#line 1 "sfas97rd_gross_prem_tax.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_prem_tax", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_reins_yrt_cost
// SFAS97RD Gross YRT Reinsurance Cost                                                                                             
// Column:SFAS97RD_GROSS_REINS_YRT_COST
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_reins_yrt_cost.EPL_LIAB.for"
if (!reins_flag || t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_reins_yrt_cost", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_rider_charges
// SFAS97RD Gross Rider Charges                                                                                             
// Column:SFAS97RD_GROSS_RIDER_CHARGES
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_rider_charges(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_rider_charges.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_rider_charges", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sfas133_gmab_liab
// SFAS97RD Gross SFAS 133 GMAB Liability                                                                                             
// Column:SFAS97RD_GROSS_SFAS133_GMAB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmab_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sfas133_gmab_liab.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sfas133_gmab_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sfas133_gmib_liab
// SFAS97RD Gross SFAS 133 GMIB Liability                                                                                             
// Column:SFAS97RD_GROSS_SFAS133_GMIB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmib_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sfas133_gmib_liab.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sfas133_gmib_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sfas133_gmwb_liab
// SFAS97RD Gross SFAS 133 GMWB Liability                                                                                             
// Column:SFAS97RD_GROSS_SFAS133_GMWB_LIAB
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sfas133_gmwb_liab.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sfas133_gmwb_liab", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sop031_assess
// SFAS97RD Gross SOP 03-1 Assessments                                                                                             
// Column:SFAS97RD_GROSS_SOP031_ASSESS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_assess(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sop031_assess.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sop031_assess", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sop031_coi_assess
// SFAS97RD Gross SOP 03-1 COI Assessments                                                                                             
// Column:SFAS97RD_GROSS_SOP031_COI_ASSESS
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_coi_assess(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sop031_coi_assess.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sop031_coi_assess", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sop031_coi_ben
// SFAS97RD Gross SOP 03-1 COI Benefit                                                                                             
// Column:SFAS97RD_GROSS_SOP031_COI_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_coi_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sop031_coi_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sop031_coi_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sop031_pbr
// SFAS97RD Gross SOP 03-1 Persistency Bonus/Refunds                                                                                             
// Column:SFAS97RD_GROSS_SOP031_PBR
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_pbr(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sop031_pbr.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sop031_pbr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_sop031_pbr_fund_val
// SFAS97RD Gross SOP 03-1 Persistency Bonus/Refund Fund Value                                                                                             
// Column:SFAS97RD_GROSS_SOP031_PBR_FUND_VAL
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_pbr_fund_val(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_sop031_pbr_fund_val.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_sop031_pbr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_stat_res_rider
// SFAS97 Retrospective Deposit Statutory Reserve for Riders                                                                                             
// Column:SFAS97RD_GROSS_STAT_RES_RIDER
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_stat_res_rider(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_stat_res_rider.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_stat_res_rider", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - sfas97rd_gross_ulsg_ben
// SFAS97RD Gross ULSG Benefits                                                                                             
// Column:SFAS97RD_GROSS_ULSG_BEN
//========================================================
double EPL_LIAB_UDF::epl_liab_sfas97rd_gross_ulsg_ben(int t) {
//^^^



//^^^

#line 1 "sfas97rd_gross_ulsg_ben.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("sfas97rd_gross_ulsg_ben", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double EPL_LIAB_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.EPL_LIAB.for"
#if 0 // START_CLASS
Schedule * EPLData;
int epl_last_cash_flow_period;
map <xstring, long, less <xstring> > sched_byte_pos;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
epl_last_cash_flow_period = -1;
#endif // END_CONSTRUCTOR

if (use_mp == NO)
	{
	skipModelPoint();
	return 1.0;
	}

if (!read_epl_file(replaceWildcards(epl_file)))
	{
	if ((is_first_proj_task_loop || num_of_proj_task_loops == 0)
		&& data_validation_defn == YES)
		{
		makeRunLogYellow();
		log_screen << "Warning: Unable to process epl file " << epl_file << ". " 
				   << "EPL values will not be included. Please check your data." << MSG_ERROR;
		}
    }

if (fabs(pct_to_use_mp) < rate_ratio_threshold)
	{
	skipModelPoint();
	return 1.0;
	}

return 1.0;

}


//@@ END

//@@ START - stat_claim_exp_res
// Statutory Claim Expense Reserve                                                                                             
// Column:STAT_CLAIM_EXP_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_claim_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(601,"stat_claim_exp_res",t);
}



//^^^

#line 1 "stat_claim_exp_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_claim_exp_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_claim_res
// Statutory Claim Reserve                                                                                             
// Column:STAT_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(602,"stat_claim_res",t);
}



//^^^

#line 1 "stat_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_loading
// Statutory Loading                                                                                             
// Column:STAT_LOADING
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(603,"stat_loading",t);
}



//^^^

#line 1 "stat_loading.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_loading", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_prem_waiver_exp_res
// Statutory Premium Waiver Expense Reserve                                                                                             
// Column:STAT_PREM_WAIVER_EXP_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_prem_waiver_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(604,"stat_prem_waiver_exp_res",t);
}



//^^^

#line 1 "stat_prem_waiver_exp_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_prem_waiver_exp_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - stat_prem_waiver_res
// Statutory Premium Waiver Reserve                                                                                             
// Column:STAT_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_prem_waiver_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(605,"stat_prem_waiver_res",t);
}



//^^^

#line 1 "stat_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_prem_waiver_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_mp
// Statutory Policy Reserve                                                                                             
// Column:STAT_RES_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(606,"stat_res_mp",t);
}



//^^^

#line 1 "stat_res_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_mp_unhedged
// Statutory Policy Reserve Unhedged                                                                                             
// Column:STAT_RES_MP_UNHEDGED
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_mp_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(607,"stat_res_mp_unhedged",t);
}



//^^^

#line 1 "stat_res_mp_unhedged.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_mp_unhedged", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_net_mp
// Net Statutory Policy Reserve                                                                                             
// Column:STAT_RES_NET_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_net_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(608,"stat_res_net_mp",t);
}



//^^^

#line 1 "stat_res_net_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_net_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_net_mp_unhedged
// Net Statutory Policy Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_MP_UNHEDGED
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_net_mp_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(609,"stat_res_net_mp_unhedged",t);
}



//^^^

#line 1 "stat_res_net_mp_unhedged.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_net_mp_unhedged", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_net_npr
// Net Statutory Net Premium Reserve                                                                                             
// Column:STAT_RES_NET_NPR
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_net_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(610,"stat_res_net_npr",t);
}



//^^^

#line 1 "stat_res_net_npr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_net_npr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_net_npr_unhedged
// Net Statutory Net Premium Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_NPR_UNHEDGED
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_net_npr_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(611,"stat_res_net_npr_unhedged",t);
}



//^^^

#line 1 "stat_res_net_npr_unhedged.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_net_npr_unhedged", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_net_sa
// Net Statutory Reserve Separate Account                                                                                             
// Column:STAT_RES_NET_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_net_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(612,"stat_res_net_sa",t);
}



//^^^

#line 1 "stat_res_net_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_net_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_npr
// Statutory Net Premium Reserve                                                                                             
// Column:STAT_RES_NPR
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(613,"stat_res_npr",t);
}



//^^^

#line 1 "stat_res_npr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_npr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_npr_unhedged
// Statutory Net Premium Reserve Unhedged                                                                                             
// Column:STAT_RES_NPR_UNHEDGED
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_npr_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(614,"stat_res_npr_unhedged",t);
}



//^^^

#line 1 "stat_res_npr_unhedged.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_npr_unhedged", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_sa
// Statutory Reserve Separate Account                                                                                             
// Column:STAT_RES_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(615,"stat_res_sa",t);
}



//^^^

#line 1 "stat_res_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_res_sa_exp_allow
// Statutory Reserve Separate Account Expense Allowance                                                                                             
// Column:STAT_RES_SA_EXP_ALLOW
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_res_sa_exp_allow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(616,"stat_res_sa_exp_allow",t);
}



//^^^

#line 1 "stat_res_sa_exp_allow.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_res_sa_exp_allow", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_unearn_prem_res
// Statutory Unearned Premium Reserve                                                                                             
// Column:STAT_UNEARN_PREM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(617,"stat_unearn_prem_res",t);
}



//^^^

#line 1 "stat_unearn_prem_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_unearn_prem_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_unearn_prem_res_net
// Statutory Unearned Premium Reserve Net                                                                                             
// Column:STAT_UNEARN_PREM_RES_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(618,"stat_unearn_prem_res_net",t);
}



//^^^

#line 1 "stat_unearn_prem_res_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_unearn_prem_res_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_unearn_prem_res_npr
// Statutory Unearned Premium Reserve NPR                                                                                             
// Column:STAT_UNEARN_PREM_RES_NPR
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(619,"stat_unearn_prem_res_npr",t);
}



//^^^

#line 1 "stat_unearn_prem_res_npr.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_unearn_prem_res_npr", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - stat_unearn_prem_res_npr_net
// Statutory Unearned Premium Reserve NPR Net                                                                                             
// Column:STAT_UNEARN_PREM_RES_NPR_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_npr_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(620,"stat_unearn_prem_res_npr_net",t);
}



//^^^

#line 1 "stat_unearn_prem_res_npr_net.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("stat_unearn_prem_res_npr_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - surr_benefits
// Surrender Benefits                                                                                             
// Column:SURR_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(621,"surr_benefits",t);
}



//^^^

#line 1 "surr_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("surr_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_capzd_prem
// Tax Capitalized Premium                                                                                             
// Column:TAX_CAPZD_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_capzd_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(622,"tax_capzd_prem",t);
}



//^^^

#line 1 "tax_capzd_prem.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_capzd_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_claim_exp_res
// Tax Claim Expense Reserve                                                                                             
// Column:TAX_CLAIM_EXP_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_claim_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(623,"tax_claim_exp_res",t);
}



//^^^

#line 1 "tax_claim_exp_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_claim_exp_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_claim_res
// Tax Claim Reserve                                                                                             
// Column:TAX_CLAIM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_claim_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(624,"tax_claim_res",t);
}



//^^^

#line 1 "tax_claim_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_claim_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_deferred_net_prem
// Tax Deferred Net Premium                                                                                             
// Column:TAX_DEFERRED_NET_PREM
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_deferred_net_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(625,"tax_deferred_net_prem",t);
}



//^^^

#line 1 "tax_deferred_net_prem.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_deferred_net_prem", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_loading
// Tax Loading                                                                                             
// Column:TAX_LOADING
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_loading(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(626,"tax_loading",t);
}



//^^^

#line 1 "tax_loading.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_loading", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_prem_waiver_exp_res
// Tax Premium Waiver Expense Reserve                                                                                             
// Column:TAX_PREM_WAIVER_EXP_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_prem_waiver_exp_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(627,"tax_prem_waiver_exp_res",t);
}



//^^^

#line 1 "tax_prem_waiver_exp_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_prem_waiver_exp_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - tax_prem_waiver_res
// Tax Premium Waiver Reserve                                                                                             
// Column:TAX_PREM_WAIVER_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_prem_waiver_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(628,"tax_prem_waiver_res",t);
}



//^^^

#line 1 "tax_prem_waiver_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_prem_waiver_res", t) * pct_to_use_mp;

}


//@@ END

//@@ START - tax_res_mp
// Tax Policy Reserve                                                                                             
// Column:TAX_RES_MP
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(629,"tax_res_mp",t);
}



//^^^

#line 1 "tax_res_mp.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_res_mp", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_transfer_to_sa_net
// Tax Transfers to Separate Account Net                                                                                             
// Column:TAX_TRANSFER_TO_SA_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_transfer_to_sa_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(630,"tax_transfer_to_sa_net",t);
}



//^^^

#line 1 "tax_transfer_to_sa_net.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_transfer_to_sa_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - tax_unearn_prem_res
// Tax Unearned Premium Reserve                                                                                             
// Column:TAX_UNEARN_PREM_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_tax_unearn_prem_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(631,"tax_unearn_prem_res",t);
}



//^^^

#line 1 "tax_unearn_prem_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("tax_unearn_prem_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - terminal_div
// Terminal Dividends                                                                                             
// Column:TERMINAL_DIV
//========================================================
double EPL_LIAB_UDF::epl_liab_terminal_div(int t) {
//^^^



//^^^

#line 1 "terminal_div.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("terminal_div", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - transfer_cash_flow_sa_bom
// Transfer Cash Flow Separate Account Beginning of Month                                                                                             
// Column:TRANSFER_CASH_FLOW_SA_BOM
//========================================================
double EPL_LIAB_UDF::epl_liab_transfer_cash_flow_sa_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(633,"transfer_cash_flow_sa_bom",t);
}



//^^^

#line 1 "transfer_cash_flow_sa_bom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("transfer_cash_flow_sa_bom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - transfer_cash_flow_sa_eom
// Transfer Cash Flow Separate Account End of Month                                                                                             
// Column:TRANSFER_CASH_FLOW_SA_EOM
//========================================================
double EPL_LIAB_UDF::epl_liab_transfer_cash_flow_sa_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(634,"transfer_cash_flow_sa_eom",t);
}



//^^^

#line 1 "transfer_cash_flow_sa_eom.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("transfer_cash_flow_sa_eom", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - transfer_to_sa_net
// Transfers to Separate Account Net                                                                                             
// Column:TRANSFER_TO_SA_NET
//========================================================
double EPL_LIAB_UDF::epl_liab_transfer_to_sa_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(635,"transfer_to_sa_net",t);
}



//^^^

#line 1 "transfer_to_sa_net.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("transfer_to_sa_net", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_asset_sa
// VA PBA Assets Separate Account                                                                                             
// Column:VA_PBA_ASSET_SA
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_asset_sa(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(636,"va_pba_asset_sa",t);
}



//^^^

#line 1 "va_pba_asset_sa.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_asset_sa", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_ceded_cap_std_scen_ben_costs
// VA PBA Standard Scenario Benefit Costs - Ceded Capital                                                                                             
// Column:VA_PBA_CEDED_CAP_STD_SCEN_BEN_COSTS
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_ceded_cap_std_scen_ben_costs(int t) {
//^^^



//^^^

#line 1 "va_pba_ceded_cap_std_scen_ben_costs.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_std_scen_ben_costs", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_ceded_cap_std_scen_margin
// VA PBA Standard Scenario Margin - Ceded Capital                                                                                             
// Column:VA_PBA_CEDED_CAP_STD_SCEN_MARGIN
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_ceded_cap_std_scen_margin(int t) {
//^^^



//^^^

#line 1 "va_pba_ceded_cap_std_scen_margin.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_gross_res_std_scen_margin", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_ceded_res_std_scen_ben_costs
// VA PBA Standard Scenario Benefit Costs - Ceded Reserve                                                                                             
// Column:VA_PBA_CEDED_RES_STD_SCEN_BEN_COSTS
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_ceded_res_std_scen_ben_costs(int t) {
//^^^



//^^^

#line 1 "va_pba_ceded_res_std_scen_ben_costs.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_std_scen_ben_costs", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_ceded_res_std_scen_margin
// VA PBA Standard Scenario Margin - Ceded Reserve                                                                                             
// Column:VA_PBA_CEDED_RES_STD_SCEN_MARGIN
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_ceded_res_std_scen_margin(int t) {
//^^^



//^^^

#line 1 "va_pba_ceded_res_std_scen_margin.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_gross_res_std_scen_margin", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_gross_cap_std_scen_ben_costs
// VA PBA Standard Scenario Benefit Costs - Gross Capital                                                                                             
// Column:VA_PBA_GROSS_CAP_STD_SCEN_BEN_COSTS
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_gross_cap_std_scen_ben_costs(int t) {
//^^^



//^^^

#line 1 "va_pba_gross_cap_std_scen_ben_costs.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_std_scen_ben_costs", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_gross_cap_std_scen_margin
// VA PBA Standard Scenario Margin - Gross Capital                                                                                             
// Column:VA_PBA_GROSS_CAP_STD_SCEN_MARGIN
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_gross_cap_std_scen_margin(int t) {
//^^^



//^^^

#line 1 "va_pba_gross_cap_std_scen_margin.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_gross_cap_std_scen_margin", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_gross_res_std_scen_ben_costs
// VA PBA Standard Scenario Benefit Costs - Gross Reserve                                                                                             
// Column:VA_PBA_GROSS_RES_STD_SCEN_BEN_COSTS
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_gross_res_std_scen_ben_costs(int t) {
//^^^



//^^^

#line 1 "va_pba_gross_res_std_scen_ben_costs.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_std_scen_ben_costs", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_gross_res_std_scen_margin
// VA PBA Standard Scenario Margin - Gross Reserve                                                                                             
// Column:VA_PBA_GROSS_RES_STD_SCEN_MARGIN
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_gross_res_std_scen_margin(int t) {
//^^^



//^^^

#line 1 "va_pba_gross_res_std_scen_margin.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("va_pba_gross_res_std_scen_margin", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - va_pba_working_res
// VA PBA Working Reserve                                                                                             
// Column:VA_PBA_WORKING_RES
//========================================================
double EPL_LIAB_UDF::epl_liab_va_pba_working_res(int t) {
//^^^



//^^^

#line 1 "va_pba_working_res.EPL_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return get_epl_value("va_pba_working_res", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - withdrl_benefits
// Withdrawal Benefits                                                                                             
// Column:WITHDRL_BENEFITS
//========================================================
double EPL_LIAB_UDF::epl_liab_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(646,"withdrl_benefits",t);
}



//^^^

#line 1 "withdrl_benefits.EPL_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return get_epl_value("withdrl_benefits", t)
	   * pct_to_use_mp;

}


//@@ END

//@@ START - commencement_period
// Period t in which Policy Commences                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int EPL_LIAB_UDF::epl_liab_commencement_period() {
//^^^


#line 1 "commencement_period.EPL_LIAB.for"
return 0;

}


//@@ END

//@@ START - maturity_period
// Period t in which Policy Matures                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int EPL_LIAB_UDF::epl_liab_maturity_period() {
//^^^


#line 1 "maturity_period.EPL_LIAB.for"
return epl_last_cash_flow_period;

}


//@@ END

//@@ START - proj_date_offset
// Projection Date Offset                                                                                             
// Calculated Variable:PROJ_DATE_OFFSET
//========================================================
int EPL_LIAB_UDF::epl_liab_proj_date_offset() {
//^^^


#line 1 "proj_date_offset.EPL_LIAB.for"
if ((time_step_flag && valn_flag)
	|| !time_step_flag)
	return 0;

return valn_period;

}


//@@ END

//@@ START - reins_flag
// Reinsurance Flag                                                                                             
// Calculated Variable:REINS_FLAG
//========================================================
int EPL_LIAB_UDF::epl_liab_reins_flag() {
//^^^


#line 1 "reins_flag.EPL_LIAB.for"
if (reins_defn == NO)
	return 0;

return 1;

}


//@@ END


#line 1 "get_epl_value.EPL_LIAB.for"                                                                                   
double EPL_LIAB::get_epl_value(const xstring &col_name, int t)
{
return EPLData->getvalue(t + proj_date_offset, col_name, 1);
}



#line 1 "read_epl_file.EPL_LIAB.for"                                                                                   
bool EPL_LIAB::read_epl_file(const xstring &epl_file)
{
xstring sched_val;

if (!time_step_flag 
	|| (time_step_flag && valn_flag))
 	sched_val = xstring(proj_task_loop_num);
else
	sched_val = proj_set_loop_num;

if (is_first_proj_task_loop || num_of_proj_task_loops == 0)
	{
	EPLData = new Schedule;
	set_sched_byte_markers(epl_file);
	}

if (!EPLData->is_open())
	EPLData->open(epl_file, ',', true);

int byte_pos = sched_byte_pos[sched_val];
EPLData->read(sched_val, byte_pos, 1);		

if (LOOKUP_FAILED > 0 && LOOKUP_FAILED < 6)
	return false; 

epl_last_cash_flow_period = EPLData->numrows - 1;

return true;
}



#line 1 "set_sched_byte_markers.EPL_LIAB.for"                                                                                   
void EPL_LIAB::set_sched_byte_markers(const xstring &sched_file)
{
using namespace std;

int comma_pos = 0;
xstring sched_val_prior = "0";
long byte_pos = 0;
bool found_diff = false;
int diff = 0;
string buffer;
xstring sched_val;
ifstream schedfile;

sched_byte_pos.clear();

//NOTE: using text mode here in order to count bytes consistent 
//      with other read routine.
schedfile.open(sched_file);

if (schedfile.eof())
	throw FatalError("Could not open Schedule file " + sched_file);

while (!schedfile.eof() && getline(schedfile, buffer))
	{
	// Find the first comma
	comma_pos = buffer.find_first_of(",");

	if (comma_pos !=std::string::npos)
		{
		// not a continuation line
		sched_val = buffer.substr(0, comma_pos);
		
	    if (sched_val != sched_val_prior)
			{
	    	sched_byte_pos[sched_val] = byte_pos;		
		    sched_val_prior = sched_val;
			}

		// optimized tellg() process for grid processing
		if (!found_diff)
			{
			int size = schedfile.tellg();
			diff = size - buffer.size();
			found_diff = true;
			}

		byte_pos += buffer.size() + diff;
		}
	}

schedfile.close();

return;
}



	static EPL_LIAB_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (EPL_LIAB_UDF::*dPXi) (int);
typedef double (EPL_LIAB_UDF::*dPXid) (int, double);
typedef double (EPL_LIAB_UDF::*dPF) ();
typedef double (EPL_LIAB_UDF::*dPFd) (double);
typedef int (EPL_LIAB_UDF::*iPF) ();
typedef int (EPL_LIAB_UDF::*iPFi) (int);
typedef xstring (EPL_LIAB_UDF::*sPF) ();
typedef xstring (EPL_LIAB_UDF::*sPFs) (xstring);

const CashFlowCommonData EPL_LIAB::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "acq_exp", "epl_liab_acq_exp",  "acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->acq_exp),
	CashFlowCommonData(2, "ag48_npr_net", "epl_liab_ag48_npr_net",  "ag48_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ag48_npr_net, 'E','N', '3', 'C', (size_t)&modelOffset->ag48_npr_net),
	CashFlowCommonData(3, "ag48_unearn_prem_res_npr_net", "epl_liab_ag48_unearn_prem_res_npr_net",  "ag48_unearn_prem_res_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ag48_unearn_prem_res_npr_net, 'E','N', '3', 'C', (size_t)&modelOffset->ag48_unearn_prem_res_npr_net),
	CashFlowCommonData(4, "ann_benefits_bom", "epl_liab_ann_benefits_bom",  "ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ann_benefits_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->ann_benefits_bom),
	CashFlowCommonData(5, "ann_benefits_eom", "epl_liab_ann_benefits_eom",  "ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->ann_benefits_eom),
	CashFlowCommonData(6, "ann_pba_reins_res", "epl_liab_ann_pba_reins_res",  "ann_pba_reins_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ann_pba_reins_res, 'E','N', '3', 'P', (size_t)&modelOffset->ann_pba_reins_res),
	CashFlowCommonData(7, "ann_pba_working_res", "epl_liab_ann_pba_working_res",  "ann_pba_working_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_ann_pba_working_res, 'E','N', '3', 'P', (size_t)&modelOffset->ann_pba_working_res),
	CashFlowCommonData(8, "annuitzn_consideration", "epl_liab_annuitzn_consideration",  "annuitzn_consideration",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_annuitzn_consideration, 'E','Y', '3', 'P', (size_t)&modelOffset->annuitzn_consideration),
	CashFlowCommonData(9, "annuitzn_val_released", "epl_liab_annuitzn_val_released",  "annuitzn_val_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_annuitzn_val_released, 'E','Y', '3', 'P', (size_t)&modelOffset->annuitzn_val_released),
	CashFlowCommonData(10, "cash_val", "epl_liab_cash_val",  "cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->cash_val),
	CashFlowCommonData(11, "claim_paid", "epl_liab_claim_paid",  "claim_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_claim_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->claim_paid),
	CashFlowCommonData(12, "comm_bom", "epl_liab_comm_bom",  "comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->comm_bom),
	CashFlowCommonData(13, "comm_chargeback", "epl_liab_comm_chargeback",  "comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_comm_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_chargeback),
	CashFlowCommonData(14, "comm_eom", "epl_liab_comm_eom",  "comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_eom),
	CashFlowCommonData(15, "conversion_cost", "epl_liab_conversion_cost",  "conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_conversion_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->conversion_cost),
	CashFlowCommonData(16, "deferred_gross_prem", "epl_liab_deferred_gross_prem",  "deferred_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_deferred_gross_prem, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_gross_prem),
	CashFlowCommonData(17, "deferred_net_prem", "epl_liab_deferred_net_prem",  "deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_net_prem),
	CashFlowCommonData(18, "deferred_net_prem_net", "epl_liab_deferred_net_prem_net",  "deferred_net_prem_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_deferred_net_prem_net, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_net_prem_net),
	CashFlowCommonData(19, "deferred_net_prem_npr", "epl_liab_deferred_net_prem_npr",  "deferred_net_prem_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_deferred_net_prem_npr, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_net_prem_npr),
	CashFlowCommonData(20, "deferred_net_prem_npr_net", "epl_liab_deferred_net_prem_npr_net",  "deferred_net_prem_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_deferred_net_prem_npr_net, 'E','N', '3', 'C', (size_t)&modelOffset->deferred_net_prem_npr_net),
	CashFlowCommonData(21, "div_applied", "epl_liab_div_applied",  "div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_div_applied, 'B','Y', '3', 'C', (size_t)&modelOffset->div_applied),
	CashFlowCommonData(22, "div_liab", "epl_liab_div_liab",  "div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->div_liab),
	CashFlowCommonData(23, "div_paid", "epl_liab_div_paid",  "div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->div_paid),
	CashFlowCommonData(24, "dth_ben_inf", "epl_liab_dth_ben_inf",  "dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->dth_ben_inf),
	CashFlowCommonData(25, "dth_benefits", "epl_liab_dth_benefits",  "dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->dth_benefits),
	CashFlowCommonData(26, "endow_benefits", "epl_liab_endow_benefits",  "endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->endow_benefits),
	CashFlowCommonData(27, "fund_val_fixed", "epl_liab_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_fund_val_fixed, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(28, "fund_val_sa", "epl_liab_fund_val_sa",  "fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_fund_val_sa, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_sa),
	CashFlowCommonData(29, "gross_prem_annualzd", "epl_liab_gross_prem_annualzd",  "gross_prem_annualzd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_gross_prem_annualzd, 'E','N', '3', 'C', (size_t)&modelOffset->gross_prem_annualzd),
	CashFlowCommonData(30, "hedge_cash_flow", "epl_liab_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(31, "hedge_mkt_val", "epl_liab_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(32, "hedge_mkt_val_growth", "epl_liab_hedge_mkt_val_growth",  "hedge_mkt_val_growth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_hedge_mkt_val_growth, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_growth),
	CashFlowCommonData(33, "inv_fee_ref", "epl_liab_inv_fee_ref",  "inv_fee_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_inv_fee_ref, 'B','Y', '3', 'P', (size_t)&modelOffset->inv_fee_ref),
	CashFlowCommonData(34, "life_pba_ag48_npr_net", "epl_liab_life_pba_ag48_npr_net",  "life_pba_ag48_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_ag48_npr_net, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_ag48_npr_net),
	CashFlowCommonData(35, "life_pba_ag48_unearn_prem_res_npr_net", "epl_liab_life_pba_ag48_unearn_prem_res_npr_net",  "life_pba_ag48_unearn_prem_res_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_ag48_unearn_prem_res_npr_net, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_ag48_unearn_prem_res_npr_net),
	CashFlowCommonData(36, "life_pba_asset_sa", "epl_liab_life_pba_asset_sa",  "life_pba_asset_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_asset_sa, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_asset_sa),
	CashFlowCommonData(37, "life_pba_direct_cash_flow_bom", "epl_liab_life_pba_direct_cash_flow_bom",  "life_pba_direct_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_direct_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->life_pba_direct_cash_flow_bom),
	CashFlowCommonData(38, "life_pba_direct_cash_flow_eom", "epl_liab_life_pba_direct_cash_flow_eom",  "life_pba_direct_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_direct_cash_flow_eom, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_direct_cash_flow_eom),
	CashFlowCommonData(39, "life_pba_gpr_ceded", "epl_liab_life_pba_gpr_ceded",  "life_pba_gpr_ceded",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_gpr_ceded, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_gpr_ceded),
	CashFlowCommonData(40, "life_pba_gpr_gross", "epl_liab_life_pba_gpr_gross",  "life_pba_gpr_gross",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_gpr_gross, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_gpr_gross),
	CashFlowCommonData(41, "life_pba_gpr_units_inf", "epl_liab_life_pba_gpr_units_inf",  "life_pba_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_gpr_units_inf),
	CashFlowCommonData(42, "life_pba_pol_loan", "epl_liab_life_pba_pol_loan",  "life_pba_pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_pol_loan, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_pol_loan),
	CashFlowCommonData(43, "life_pba_pol_loan_int", "epl_liab_life_pba_pol_loan_int",  "life_pba_pol_loan_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_pol_loan_int, 'E','Y', '3', 'P', (size_t)&modelOffset->life_pba_pol_loan_int),
	CashFlowCommonData(44, "life_pba_reins_cash_flow_bom", "epl_liab_life_pba_reins_cash_flow_bom",  "life_pba_reins_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_reins_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->life_pba_reins_cash_flow_bom),
	CashFlowCommonData(45, "life_pba_reins_cash_flow_eom", "epl_liab_life_pba_reins_cash_flow_eom",  "life_pba_reins_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_reins_cash_flow_eom, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_reins_cash_flow_eom),
	CashFlowCommonData(46, "life_pba_reins_res", "epl_liab_life_pba_reins_res",  "life_pba_reins_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_reins_res, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_reins_res),
	CashFlowCommonData(47, "life_pba_reins_res_sa", "epl_liab_life_pba_reins_res_sa",  "life_pba_reins_res_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_reins_res_sa, 'E','N', '3', 'C', (size_t)&modelOffset->life_pba_reins_res_sa),
	CashFlowCommonData(48, "life_pba_stat_res_mp", "epl_liab_life_pba_stat_res_mp",  "life_pba_stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_stat_res_mp, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_stat_res_mp),
	CashFlowCommonData(49, "life_pba_stat_res_net_mp", "epl_liab_life_pba_stat_res_net_mp",  "life_pba_stat_res_net_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_stat_res_net_mp, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_stat_res_net_mp),
	CashFlowCommonData(50, "life_pba_stat_unearn_prem_res", "epl_liab_life_pba_stat_unearn_prem_res",  "life_pba_stat_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_stat_unearn_prem_res),
	CashFlowCommonData(51, "life_pba_stat_unearn_prem_res_net", "epl_liab_life_pba_stat_unearn_prem_res_net",  "life_pba_stat_unearn_prem_res_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res_net, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_stat_unearn_prem_res_net),
	CashFlowCommonData(52, "life_pba_stat_unearn_prem_res_npr_net", "epl_liab_life_pba_stat_unearn_prem_res_npr_net",  "life_pba_stat_unearn_prem_res_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_stat_unearn_prem_res_npr_net, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_stat_unearn_prem_res_npr_net),
	CashFlowCommonData(53, "life_pba_working_res", "epl_liab_life_pba_working_res",  "life_pba_working_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_life_pba_working_res, 'E','N', '3', 'P', (size_t)&modelOffset->life_pba_working_res),
	CashFlowCommonData(54, "maint_exp_bom", "epl_liab_maint_exp_bom",  "maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->maint_exp_bom),
	CashFlowCommonData(55, "maint_exp_eom", "epl_liab_maint_exp_eom",  "maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->maint_exp_eom),
	CashFlowCommonData(56, "maturity_benefits", "epl_liab_maturity_benefits",  "maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->maturity_benefits),
	CashFlowCommonData(57, "pba_rollforward_base", "epl_liab_pba_rollforward_base",  "pba_rollforward_base",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_pba_rollforward_base, 'E','Y', '3', 'P', (size_t)&modelOffset->pba_rollforward_base),
	CashFlowCommonData(58, "pol_loan", "epl_liab_pol_loan",  "pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_pol_loan, 'E','N', '3', 'C', (size_t)&modelOffset->pol_loan),
	CashFlowCommonData(59, "pol_loan_exp", "epl_liab_pol_loan_exp",  "pol_loan_exp",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_pol_loan_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_exp),
	CashFlowCommonData(60, "pol_loan_int", "epl_liab_pol_loan_int",  "pol_loan_int",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_pol_loan_int, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_int),
	CashFlowCommonData(61, "pol_loan_proceeds", "epl_liab_pol_loan_proceeds",  "pol_loan_proceeds",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_pol_loan_proceeds, 'E','Y', '3', 'C', (size_t)&modelOffset->pol_loan_proceeds),
	CashFlowCommonData(62, "policies_b", "epl_liab_policies_b",  "policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_policies_b, 'E','N', '3', 'P', (size_t)&modelOffset->policies_b),
	CashFlowCommonData(63, "policies_inf", "epl_liab_policies_inf",  "policies_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_policies_inf, 'E','N', '3', 'P', (size_t)&modelOffset->policies_inf),
	CashFlowCommonData(64, "policies_issued", "epl_liab_policies_issued",  "policies_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_policies_issued, 'E','N', '3', 'P', (size_t)&modelOffset->policies_issued),
	CashFlowCommonData(65, "prem_issued", "epl_liab_prem_issued",  "prem_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_prem_issued, 'E','N', '3', 'C', (size_t)&modelOffset->prem_issued),
	CashFlowCommonData(66, "prem_paid", "epl_liab_prem_paid",  "prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_prem_paid, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_paid),
	CashFlowCommonData(67, "prem_paid_net", "epl_liab_prem_paid_net",  "prem_paid_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_prem_paid_net, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_paid_net),
	CashFlowCommonData(68, "prem_tax", "epl_liab_prem_tax",  "prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_tax),
	CashFlowCommonData(69, "prem_waiver_benefits", "epl_liab_prem_waiver_benefits",  "prem_waiver_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_prem_waiver_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->prem_waiver_benefits),
	CashFlowCommonData(70, "rbc_c1_unearn_prem_res_def", "epl_liab_rbc_c1_unearn_prem_res_def",  "rbc_c1_unearn_prem_res_def",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c1_unearn_prem_res_def, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_unearn_prem_res_def),
	CashFlowCommonData(71, "rbc_c2_claim", "epl_liab_rbc_c2_claim",  "rbc_c2_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c2_claim, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2_claim),
	CashFlowCommonData(72, "rbc_c2_claim_prev_yr", "epl_liab_rbc_c2_claim_prev_yr",  "rbc_c2_claim_prev_yr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c2_claim_prev_yr, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2_claim_prev_yr),
	CashFlowCommonData(73, "rbc_c2_prem", "epl_liab_rbc_c2_prem",  "rbc_c2_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c2_prem, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2_prem),
	CashFlowCommonData(74, "rbc_c2_prem_prev_yr", "epl_liab_rbc_c2_prem_prev_yr",  "rbc_c2_prem_prev_yr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c2_prem_prev_yr, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2_prem_prev_yr),
	CashFlowCommonData(75, "rbc_c3_base_ann_high_risk", "epl_liab_rbc_c3_base_ann_high_risk",  "rbc_c3_base_ann_high_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_high_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_high_risk),
	CashFlowCommonData(76, "rbc_c3_base_ann_low_risk", "epl_liab_rbc_c3_base_ann_low_risk",  "rbc_c3_base_ann_low_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_low_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_low_risk),
	CashFlowCommonData(77, "rbc_c3_base_ann_medium_risk", "epl_liab_rbc_c3_base_ann_medium_risk",  "rbc_c3_base_ann_medium_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c3_base_ann_medium_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_medium_risk),
	CashFlowCommonData(78, "rbc_c3_base_life", "epl_liab_rbc_c3_base_life",  "rbc_c3_base_life",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c3_base_life, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_life),
	CashFlowCommonData(79, "rbc_c3_mp", "epl_liab_rbc_c3_mp",  "rbc_c3_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c3_mp, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_mp),
	CashFlowCommonData(80, "rbc_c4", "epl_liab_rbc_c4",  "rbc_c4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_rbc_c4, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c4),
	CashFlowCommonData(81, "reins_ann_benefits_bom", "epl_liab_reins_ann_benefits_bom",  "reins_ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_ann_benefits_bom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ann_benefits_bom),
	CashFlowCommonData(82, "reins_ann_benefits_eom", "epl_liab_reins_ann_benefits_eom",  "reins_ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ann_benefits_eom),
	CashFlowCommonData(83, "reins_cash_val", "epl_liab_reins_cash_val",  "reins_cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->reins_cash_val),
	CashFlowCommonData(84, "reins_claim_paid", "epl_liab_reins_claim_paid",  "reins_claim_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_claim_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_claim_paid),
	CashFlowCommonData(85, "reins_comm_chargeback_reimb", "epl_liab_reins_comm_chargeback_reimb",  "reins_comm_chargeback_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_comm_chargeback_reimb, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_comm_chargeback_reimb),
	CashFlowCommonData(86, "reins_comm_reimb_bom", "epl_liab_reins_comm_reimb_bom",  "reins_comm_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_comm_reimb_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb_bom),
	CashFlowCommonData(87, "reins_comm_reimb_eom", "epl_liab_reins_comm_reimb_eom",  "reins_comm_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_comm_reimb_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb_eom),
	CashFlowCommonData(88, "reins_deferred_gross_prem", "epl_liab_reins_deferred_gross_prem",  "reins_deferred_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_deferred_gross_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_deferred_gross_prem),
	CashFlowCommonData(89, "reins_deferred_net_prem", "epl_liab_reins_deferred_net_prem",  "reins_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_deferred_net_prem),
	CashFlowCommonData(90, "reins_div_applied", "epl_liab_reins_div_applied",  "reins_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_div_applied, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_div_applied),
	CashFlowCommonData(91, "reins_div_liab", "epl_liab_reins_div_liab",  "reins_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_div_liab),
	CashFlowCommonData(92, "reins_div_paid", "epl_liab_reins_div_paid",  "reins_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_div_paid),
	CashFlowCommonData(93, "reins_dth_ben_inf", "epl_liab_reins_dth_ben_inf",  "reins_dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->reins_dth_ben_inf),
	CashFlowCommonData(94, "reins_dth_benefits", "epl_liab_reins_dth_benefits",  "reins_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_dth_benefits),
	CashFlowCommonData(95, "reins_ea", "epl_liab_reins_ea",  "reins_ea",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_ea, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_ea),
	CashFlowCommonData(96, "reins_ea_chargeback", "epl_liab_reins_ea_chargeback",  "reins_ea_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_ea_chargeback, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_ea_chargeback),
	CashFlowCommonData(97, "reins_endow_benefits", "epl_liab_reins_endow_benefits",  "reins_endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_endow_benefits),
	CashFlowCommonData(98, "reins_exp", "epl_liab_reins_exp",  "reins_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp),
	CashFlowCommonData(99, "reins_exp_reimb_bom", "epl_liab_reins_exp_reimb_bom",  "reins_exp_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_exp_reimb_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_bom),
	CashFlowCommonData(100, "reins_exp_reimb_eom", "epl_liab_reins_exp_reimb_eom",  "reins_exp_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_exp_reimb_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_eom),
	CashFlowCommonData(101, "reins_inv_fee_ref", "epl_liab_reins_inv_fee_ref",  "reins_inv_fee_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_inv_fee_ref, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_inv_fee_ref),
	CashFlowCommonData(102, "reins_maturity_benefits", "epl_liab_reins_maturity_benefits",  "reins_maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_maturity_benefits),
	CashFlowCommonData(103, "reins_modco_res_adj", "epl_liab_reins_modco_res_adj",  "reins_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_modco_res_adj),
	CashFlowCommonData(104, "reins_prem", "epl_liab_reins_prem",  "reins_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_prem, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem),
	CashFlowCommonData(105, "reins_prem_tax", "epl_liab_reins_prem_tax",  "reins_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_tax),
	CashFlowCommonData(106, "reins_prem_waiver_benefits", "epl_liab_reins_prem_waiver_benefits",  "reins_prem_waiver_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_prem_waiver_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_prem_waiver_benefits),
	CashFlowCommonData(107, "reins_ref", "epl_liab_reins_ref",  "reins_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_ref, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ref),
	CashFlowCommonData(108, "reins_stat_claim_res", "epl_liab_reins_stat_claim_res",  "reins_stat_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_claim_res),
	CashFlowCommonData(109, "reins_stat_loading", "epl_liab_reins_stat_loading",  "reins_stat_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_loading, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_loading),
	CashFlowCommonData(110, "reins_stat_prem_waiver_res", "epl_liab_reins_stat_prem_waiver_res",  "reins_stat_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_prem_waiver_res, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_stat_prem_waiver_res),
	CashFlowCommonData(111, "reins_stat_res_mp", "epl_liab_reins_stat_res_mp",  "reins_stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res_mp),
	CashFlowCommonData(112, "reins_stat_res_npr", "epl_liab_reins_stat_res_npr",  "reins_stat_res_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_res_npr, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res_npr),
	CashFlowCommonData(113, "reins_stat_unearn_prem_res", "epl_liab_reins_stat_unearn_prem_res",  "reins_stat_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_stat_unearn_prem_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_unearn_prem_res),
	CashFlowCommonData(114, "reins_surr_benefits", "epl_liab_reins_surr_benefits",  "reins_surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_surr_benefits),
	CashFlowCommonData(115, "reins_tax_claim_res", "epl_liab_reins_tax_claim_res",  "reins_tax_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_claim_res),
	CashFlowCommonData(116, "reins_tax_deferred_net_prem", "epl_liab_reins_tax_deferred_net_prem",  "reins_tax_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_deferred_net_prem),
	CashFlowCommonData(117, "reins_tax_loading", "epl_liab_reins_tax_loading",  "reins_tax_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_loading, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_loading),
	CashFlowCommonData(118, "reins_tax_prem_waiver_res", "epl_liab_reins_tax_prem_waiver_res",  "reins_tax_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_prem_waiver_res, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_tax_prem_waiver_res),
	CashFlowCommonData(119, "reins_tax_res_mp", "epl_liab_reins_tax_res_mp",  "reins_tax_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_res_mp),
	CashFlowCommonData(120, "reins_tax_unearn_prem_res", "epl_liab_reins_tax_unearn_prem_res",  "reins_tax_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_tax_unearn_prem_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_unearn_prem_res),
	CashFlowCommonData(121, "reins_terminal_div", "epl_liab_reins_terminal_div",  "reins_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_terminal_div, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_terminal_div),
	CashFlowCommonData(122, "reins_withdrl_benefits", "epl_liab_reins_withdrl_benefits",  "reins_withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_reins_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_withdrl_benefits),
	CashFlowCommonData(123, "sfas120_ceded_acq_exp", "epl_liab_sfas120_ceded_acq_exp",  "sfas120_ceded_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_acq_exp),
	CashFlowCommonData(124, "sfas120_ceded_benefits", "epl_liab_sfas120_ceded_benefits",  "sfas120_ceded_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_benefits, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_benefits),
	CashFlowCommonData(125, "sfas120_ceded_capzd_acq_exp", "epl_liab_sfas120_ceded_capzd_acq_exp",  "sfas120_ceded_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_capzd_acq_exp),
	CashFlowCommonData(126, "sfas120_ceded_capzd_comm_bom", "epl_liab_sfas120_ceded_capzd_comm_bom",  "sfas120_ceded_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_capzd_comm_bom),
	CashFlowCommonData(127, "sfas120_ceded_capzd_comm_chargeback", "epl_liab_sfas120_ceded_capzd_comm_chargeback",  "sfas120_ceded_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_capzd_comm_chargeback),
	CashFlowCommonData(128, "sfas120_ceded_capzd_comm_eom", "epl_liab_sfas120_ceded_capzd_comm_eom",  "sfas120_ceded_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_capzd_comm_eom),
	CashFlowCommonData(129, "sfas120_ceded_cash_flow_bom", "epl_liab_sfas120_ceded_cash_flow_bom",  "sfas120_ceded_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_cash_flow_bom),
	CashFlowCommonData(130, "sfas120_ceded_comm_chargeback", "epl_liab_sfas120_ceded_comm_chargeback",  "sfas120_ceded_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_chargeback),
	CashFlowCommonData(131, "sfas120_ceded_comm_excess_bom", "epl_liab_sfas120_ceded_comm_excess_bom",  "sfas120_ceded_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_excess_bom),
	CashFlowCommonData(132, "sfas120_ceded_comm_excess_eom", "epl_liab_sfas120_ceded_comm_excess_eom",  "sfas120_ceded_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_excess_eom),
	CashFlowCommonData(133, "sfas120_ceded_comm_trail_bom", "epl_liab_sfas120_ceded_comm_trail_bom",  "sfas120_ceded_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_trail_bom),
	CashFlowCommonData(134, "sfas120_ceded_comm_trail_bom_base_plan", "epl_liab_sfas120_ceded_comm_trail_bom_base_plan",  "sfas120_ceded_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_trail_bom_base_plan),
	CashFlowCommonData(135, "sfas120_ceded_comm_trail_bom_rider", "epl_liab_sfas120_ceded_comm_trail_bom_rider",  "sfas120_ceded_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_trail_bom_rider),
	CashFlowCommonData(136, "sfas120_ceded_comm_trail_eom", "epl_liab_sfas120_ceded_comm_trail_eom",  "sfas120_ceded_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_comm_trail_eom),
	CashFlowCommonData(137, "sfas120_ceded_conversion_cost", "epl_liab_sfas120_ceded_conversion_cost",  "sfas120_ceded_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_conversion_cost),
	CashFlowCommonData(138, "sfas120_ceded_div_applied", "epl_liab_sfas120_ceded_div_applied",  "sfas120_ceded_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_div_applied),
	CashFlowCommonData(139, "sfas120_ceded_div_liab", "epl_liab_sfas120_ceded_div_liab",  "sfas120_ceded_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->sfas120_ceded_div_liab),
	CashFlowCommonData(140, "sfas120_ceded_div_opt_res", "epl_liab_sfas120_ceded_div_opt_res",  "sfas120_ceded_div_opt_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_opt_res, 'E','N', '3', 'C', (size_t)&modelOffset->sfas120_ceded_div_opt_res),
	CashFlowCommonData(141, "sfas120_ceded_div_paid", "epl_liab_sfas120_ceded_div_paid",  "sfas120_ceded_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_div_paid),
	CashFlowCommonData(142, "sfas120_ceded_dth_claim_cost", "epl_liab_sfas120_ceded_dth_claim_cost",  "sfas120_ceded_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_dth_claim_cost),
	CashFlowCommonData(143, "sfas120_ceded_egm_acq_exp", "epl_liab_sfas120_ceded_egm_acq_exp",  "sfas120_ceded_egm_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_acq_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_acq_exp),
	CashFlowCommonData(144, "sfas120_ceded_egm_comm", "epl_liab_sfas120_ceded_egm_comm",  "sfas120_ceded_egm_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_comm, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_comm),
	CashFlowCommonData(145, "sfas120_ceded_egm_div_applied", "epl_liab_sfas120_ceded_egm_div_applied",  "sfas120_ceded_egm_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_div_applied, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_div_applied),
	CashFlowCommonData(146, "sfas120_ceded_egm_div_paid", "epl_liab_sfas120_ceded_egm_div_paid",  "sfas120_ceded_egm_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_div_paid),
	CashFlowCommonData(147, "sfas120_ceded_egm_dth_benefits", "epl_liab_sfas120_ceded_egm_dth_benefits",  "sfas120_ceded_egm_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_dth_benefits),
	CashFlowCommonData(148, "sfas120_ceded_egm_endow_benefits", "epl_liab_sfas120_ceded_egm_endow_benefits",  "sfas120_ceded_egm_endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_endow_benefits),
	CashFlowCommonData(149, "sfas120_ceded_egm_maint_exp", "epl_liab_sfas120_ceded_egm_maint_exp",  "sfas120_ceded_egm_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_maint_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_maint_exp),
	CashFlowCommonData(150, "sfas120_ceded_egm_maturity_benefits", "epl_liab_sfas120_ceded_egm_maturity_benefits",  "sfas120_ceded_egm_maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_maturity_benefits),
	CashFlowCommonData(151, "sfas120_ceded_egm_prem_paid", "epl_liab_sfas120_ceded_egm_prem_paid",  "sfas120_ceded_egm_prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_prem_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_prem_paid),
	CashFlowCommonData(152, "sfas120_ceded_egm_prem_tax", "epl_liab_sfas120_ceded_egm_prem_tax",  "sfas120_ceded_egm_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_prem_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_prem_tax),
	CashFlowCommonData(153, "sfas120_ceded_egm_surr_benefits", "epl_liab_sfas120_ceded_egm_surr_benefits",  "sfas120_ceded_egm_surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_egm_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_egm_surr_benefits),
	CashFlowCommonData(154, "sfas120_ceded_endow_claim_cost", "epl_liab_sfas120_ceded_endow_claim_cost",  "sfas120_ceded_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_endow_claim_cost),
	CashFlowCommonData(155, "sfas120_ceded_gpr", "epl_liab_sfas120_ceded_gpr",  "sfas120_ceded_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_gpr),
	CashFlowCommonData(156, "sfas120_ceded_gpr_units_inf", "epl_liab_sfas120_ceded_gpr_units_inf",  "sfas120_ceded_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_gpr_units_inf),
	CashFlowCommonData(157, "sfas120_ceded_gross_prem", "epl_liab_sfas120_ceded_gross_prem",  "sfas120_ceded_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_gross_prem),
	CashFlowCommonData(158, "sfas120_ceded_loc_cost", "epl_liab_sfas120_ceded_loc_cost",  "sfas120_ceded_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_loc_cost),
	CashFlowCommonData(159, "sfas120_ceded_maint_exp_bom", "epl_liab_sfas120_ceded_maint_exp_bom",  "sfas120_ceded_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas120_ceded_maint_exp_bom),
	CashFlowCommonData(160, "sfas120_ceded_maint_exp_eom", "epl_liab_sfas120_ceded_maint_exp_eom",  "sfas120_ceded_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_maint_exp_eom),
	CashFlowCommonData(161, "sfas120_ceded_maturity_claim_cost", "epl_liab_sfas120_ceded_maturity_claim_cost",  "sfas120_ceded_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_maturity_claim_cost),
	CashFlowCommonData(162, "sfas120_ceded_modco_liab", "epl_liab_sfas120_ceded_modco_liab",  "sfas120_ceded_modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_modco_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_modco_liab),
	CashFlowCommonData(163, "sfas120_ceded_modco_res_adj", "epl_liab_sfas120_ceded_modco_res_adj",  "sfas120_ceded_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_modco_res_adj, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_modco_res_adj),
	CashFlowCommonData(164, "sfas120_ceded_nlp_res_net_prem2", "epl_liab_sfas120_ceded_nlp_res_net_prem2",  "sfas120_ceded_nlp_res_net_prem2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_nlp_res_net_prem2, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_nlp_res_net_prem2),
	CashFlowCommonData(165, "sfas120_ceded_nlp_res_prelim", "epl_liab_sfas120_ceded_nlp_res_prelim",  "sfas120_ceded_nlp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_nlp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_nlp_res_prelim),
	CashFlowCommonData(166, "sfas120_ceded_prem_tax", "epl_liab_sfas120_ceded_prem_tax",  "sfas120_ceded_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_prem_tax),
	CashFlowCommonData(167, "sfas120_ceded_refund", "epl_liab_sfas120_ceded_refund",  "sfas120_ceded_refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_refund, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_ceded_refund),
	CashFlowCommonData(168, "sfas120_ceded_reins_ea_excess", "epl_liab_sfas120_ceded_reins_ea_excess",  "sfas120_ceded_reins_ea_excess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_reins_ea_excess, 'B','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_reins_ea_excess),
	CashFlowCommonData(169, "sfas120_ceded_reins_ea_trail", "epl_liab_sfas120_ceded_reins_ea_trail",  "sfas120_ceded_reins_ea_trail",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_reins_ea_trail, 'B','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_reins_ea_trail),
	CashFlowCommonData(170, "sfas120_ceded_surr_claim_cost", "epl_liab_sfas120_ceded_surr_claim_cost",  "sfas120_ceded_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_surr_claim_cost),
	CashFlowCommonData(171, "sfas120_ceded_terminal_div", "epl_liab_sfas120_ceded_terminal_div",  "sfas120_ceded_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_ceded_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_ceded_terminal_div),
	CashFlowCommonData(172, "sfas120_gross_acq_exp", "epl_liab_sfas120_gross_acq_exp",  "sfas120_gross_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_acq_exp),
	CashFlowCommonData(173, "sfas120_gross_benefits", "epl_liab_sfas120_gross_benefits",  "sfas120_gross_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_benefits, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_benefits),
	CashFlowCommonData(174, "sfas120_gross_capzd_acq_exp", "epl_liab_sfas120_gross_capzd_acq_exp",  "sfas120_gross_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_capzd_acq_exp),
	CashFlowCommonData(175, "sfas120_gross_capzd_comm_bom", "epl_liab_sfas120_gross_capzd_comm_bom",  "sfas120_gross_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_capzd_comm_bom),
	CashFlowCommonData(176, "sfas120_gross_capzd_comm_chargeback", "epl_liab_sfas120_gross_capzd_comm_chargeback",  "sfas120_gross_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_capzd_comm_chargeback),
	CashFlowCommonData(177, "sfas120_gross_capzd_comm_eom", "epl_liab_sfas120_gross_capzd_comm_eom",  "sfas120_gross_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_capzd_comm_eom),
	CashFlowCommonData(178, "sfas120_gross_capzd_reins_yrt_cost", "epl_liab_sfas120_gross_capzd_reins_yrt_cost",  "sfas120_gross_capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_capzd_reins_yrt_cost),
	CashFlowCommonData(179, "sfas120_gross_cash_flow_bom", "epl_liab_sfas120_gross_cash_flow_bom",  "sfas120_gross_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_cash_flow_bom),
	CashFlowCommonData(180, "sfas120_gross_comm_chargeback", "epl_liab_sfas120_gross_comm_chargeback",  "sfas120_gross_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_chargeback),
	CashFlowCommonData(181, "sfas120_gross_comm_excess_bom", "epl_liab_sfas120_gross_comm_excess_bom",  "sfas120_gross_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_excess_bom),
	CashFlowCommonData(182, "sfas120_gross_comm_excess_eom", "epl_liab_sfas120_gross_comm_excess_eom",  "sfas120_gross_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_excess_eom),
	CashFlowCommonData(183, "sfas120_gross_comm_trail_bom", "epl_liab_sfas120_gross_comm_trail_bom",  "sfas120_gross_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_trail_bom),
	CashFlowCommonData(184, "sfas120_gross_comm_trail_bom_base_plan", "epl_liab_sfas120_gross_comm_trail_bom_base_plan",  "sfas120_gross_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_trail_bom_base_plan),
	CashFlowCommonData(185, "sfas120_gross_comm_trail_bom_rider", "epl_liab_sfas120_gross_comm_trail_bom_rider",  "sfas120_gross_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_trail_bom_rider),
	CashFlowCommonData(186, "sfas120_gross_comm_trail_eom", "epl_liab_sfas120_gross_comm_trail_eom",  "sfas120_gross_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_comm_trail_eom),
	CashFlowCommonData(187, "sfas120_gross_conversion_cost", "epl_liab_sfas120_gross_conversion_cost",  "sfas120_gross_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_conversion_cost),
	CashFlowCommonData(188, "sfas120_gross_div_applied", "epl_liab_sfas120_gross_div_applied",  "sfas120_gross_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_div_applied),
	CashFlowCommonData(189, "sfas120_gross_div_liab", "epl_liab_sfas120_gross_div_liab",  "sfas120_gross_div_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_div_liab, 'E','N', '3', 'C', (size_t)&modelOffset->sfas120_gross_div_liab),
	CashFlowCommonData(190, "sfas120_gross_div_opt_res", "epl_liab_sfas120_gross_div_opt_res",  "sfas120_gross_div_opt_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_div_opt_res, 'E','N', '3', 'C', (size_t)&modelOffset->sfas120_gross_div_opt_res),
	CashFlowCommonData(191, "sfas120_gross_div_paid", "epl_liab_sfas120_gross_div_paid",  "sfas120_gross_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_div_paid),
	CashFlowCommonData(192, "sfas120_gross_dth_claim_cost", "epl_liab_sfas120_gross_dth_claim_cost",  "sfas120_gross_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_dth_claim_cost),
	CashFlowCommonData(193, "sfas120_gross_egm_acq_exp", "epl_liab_sfas120_gross_egm_acq_exp",  "sfas120_gross_egm_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_acq_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_acq_exp),
	CashFlowCommonData(194, "sfas120_gross_egm_comm", "epl_liab_sfas120_gross_egm_comm",  "sfas120_gross_egm_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_comm, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_comm),
	CashFlowCommonData(195, "sfas120_gross_egm_div_applied", "epl_liab_sfas120_gross_egm_div_applied",  "sfas120_gross_egm_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_div_applied, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_div_applied),
	CashFlowCommonData(196, "sfas120_gross_egm_div_paid", "epl_liab_sfas120_gross_egm_div_paid",  "sfas120_gross_egm_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_div_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_div_paid),
	CashFlowCommonData(197, "sfas120_gross_egm_dth_benefits", "epl_liab_sfas120_gross_egm_dth_benefits",  "sfas120_gross_egm_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_dth_benefits),
	CashFlowCommonData(198, "sfas120_gross_egm_endow_benefits", "epl_liab_sfas120_gross_egm_endow_benefits",  "sfas120_gross_egm_endow_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_endow_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_endow_benefits),
	CashFlowCommonData(199, "sfas120_gross_egm_maint_exp", "epl_liab_sfas120_gross_egm_maint_exp",  "sfas120_gross_egm_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_maint_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_maint_exp),
	CashFlowCommonData(200, "sfas120_gross_egm_maturity_benefits", "epl_liab_sfas120_gross_egm_maturity_benefits",  "sfas120_gross_egm_maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_maturity_benefits),
	CashFlowCommonData(201, "sfas120_gross_egm_prem_paid", "epl_liab_sfas120_gross_egm_prem_paid",  "sfas120_gross_egm_prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_prem_paid, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_prem_paid),
	CashFlowCommonData(202, "sfas120_gross_egm_prem_tax", "epl_liab_sfas120_gross_egm_prem_tax",  "sfas120_gross_egm_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_prem_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_prem_tax),
	CashFlowCommonData(203, "sfas120_gross_egm_reins_cost", "epl_liab_sfas120_gross_egm_reins_cost",  "sfas120_gross_egm_reins_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_reins_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_reins_cost),
	CashFlowCommonData(204, "sfas120_gross_egm_surr_benefits", "epl_liab_sfas120_gross_egm_surr_benefits",  "sfas120_gross_egm_surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_egm_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_egm_surr_benefits),
	CashFlowCommonData(205, "sfas120_gross_endow_claim_cost", "epl_liab_sfas120_gross_endow_claim_cost",  "sfas120_gross_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_endow_claim_cost),
	CashFlowCommonData(206, "sfas120_gross_gpr", "epl_liab_sfas120_gross_gpr",  "sfas120_gross_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_gpr),
	CashFlowCommonData(207, "sfas120_gross_gpr_units_inf", "epl_liab_sfas120_gross_gpr_units_inf",  "sfas120_gross_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_gpr_units_inf),
	CashFlowCommonData(208, "sfas120_gross_gross_prem", "epl_liab_sfas120_gross_gross_prem",  "sfas120_gross_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_gross_prem),
	CashFlowCommonData(209, "sfas120_gross_loc_cost", "epl_liab_sfas120_gross_loc_cost",  "sfas120_gross_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_loc_cost),
	CashFlowCommonData(210, "sfas120_gross_maint_exp_bom", "epl_liab_sfas120_gross_maint_exp_bom",  "sfas120_gross_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas120_gross_maint_exp_bom),
	CashFlowCommonData(211, "sfas120_gross_maint_exp_eom", "epl_liab_sfas120_gross_maint_exp_eom",  "sfas120_gross_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_maint_exp_eom),
	CashFlowCommonData(212, "sfas120_gross_maturity_claim_cost", "epl_liab_sfas120_gross_maturity_claim_cost",  "sfas120_gross_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_maturity_claim_cost),
	CashFlowCommonData(213, "sfas120_gross_nlp_res_net_prem", "epl_liab_sfas120_gross_nlp_res_net_prem",  "sfas120_gross_nlp_res_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_nlp_res_net_prem, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_nlp_res_net_prem),
	CashFlowCommonData(214, "sfas120_gross_nlp_res_prelim", "epl_liab_sfas120_gross_nlp_res_prelim",  "sfas120_gross_nlp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_nlp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_nlp_res_prelim),
	CashFlowCommonData(215, "sfas120_gross_pol_loan", "epl_liab_sfas120_gross_pol_loan",  "sfas120_gross_pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_pol_loan, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_pol_loan),
	CashFlowCommonData(216, "sfas120_gross_pol_loan_inc", "epl_liab_sfas120_gross_pol_loan_inc",  "sfas120_gross_pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_pol_loan_inc, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_pol_loan_inc),
	CashFlowCommonData(217, "sfas120_gross_prem_tax", "epl_liab_sfas120_gross_prem_tax",  "sfas120_gross_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas120_gross_prem_tax),
	CashFlowCommonData(218, "sfas120_gross_reins_yrt_cost", "epl_liab_sfas120_gross_reins_yrt_cost",  "sfas120_gross_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_reins_yrt_cost),
	CashFlowCommonData(219, "sfas120_gross_stat_res_rider", "epl_liab_sfas120_gross_stat_res_rider",  "sfas120_gross_stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_stat_res_rider),
	CashFlowCommonData(220, "sfas120_gross_surr_claim_cost", "epl_liab_sfas120_gross_surr_claim_cost",  "sfas120_gross_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_surr_claim_cost),
	CashFlowCommonData(221, "sfas120_gross_terminal_div", "epl_liab_sfas120_gross_terminal_div",  "sfas120_gross_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas120_gross_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas120_gross_terminal_div),
	CashFlowCommonData(222, "sfas60_ceded_acq_exp", "epl_liab_sfas60_ceded_acq_exp",  "sfas60_ceded_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_acq_exp),
	CashFlowCommonData(223, "sfas60_ceded_ben_res_accrual_valn_basis", "epl_liab_sfas60_ceded_ben_res_accrual_valn_basis",  "sfas60_ceded_ben_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_ben_res_accrual_valn_basis),
	CashFlowCommonData(224, "sfas60_ceded_ben_res_int_valn_basis", "epl_liab_sfas60_ceded_ben_res_int_valn_basis",  "sfas60_ceded_ben_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_ben_res_int_valn_basis),
	CashFlowCommonData(225, "sfas60_ceded_ben_res_prelim", "epl_liab_sfas60_ceded_ben_res_prelim",  "sfas60_ceded_ben_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_ben_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_ben_res_prelim),
	CashFlowCommonData(226, "sfas60_ceded_benefits_valn_basis", "epl_liab_sfas60_ceded_benefits_valn_basis",  "sfas60_ceded_benefits_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_benefits_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_benefits_valn_basis),
	CashFlowCommonData(227, "sfas60_ceded_capzd_acq_exp", "epl_liab_sfas60_ceded_capzd_acq_exp",  "sfas60_ceded_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_acq_exp),
	CashFlowCommonData(228, "sfas60_ceded_capzd_acq_exp_valn_basis", "epl_liab_sfas60_ceded_capzd_acq_exp_valn_basis",  "sfas60_ceded_capzd_acq_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_acq_exp_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_acq_exp_valn_basis),
	CashFlowCommonData(229, "sfas60_ceded_capzd_comm_bom", "epl_liab_sfas60_ceded_capzd_comm_bom",  "sfas60_ceded_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_comm_bom),
	CashFlowCommonData(230, "sfas60_ceded_capzd_comm_chargeback", "epl_liab_sfas60_ceded_capzd_comm_chargeback",  "sfas60_ceded_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_comm_chargeback),
	CashFlowCommonData(231, "sfas60_ceded_capzd_comm_eom", "epl_liab_sfas60_ceded_capzd_comm_eom",  "sfas60_ceded_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_eom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_comm_eom),
	CashFlowCommonData(232, "sfas60_ceded_capzd_comm_valn_basis", "epl_liab_sfas60_ceded_capzd_comm_valn_basis",  "sfas60_ceded_capzd_comm_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_capzd_comm_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_capzd_comm_valn_basis),
	CashFlowCommonData(233, "sfas60_ceded_cash_flow_bom", "epl_liab_sfas60_ceded_cash_flow_bom",  "sfas60_ceded_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_cash_flow_bom),
	CashFlowCommonData(234, "sfas60_ceded_claim_res", "epl_liab_sfas60_ceded_claim_res",  "sfas60_ceded_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_claim_res),
	CashFlowCommonData(235, "sfas60_ceded_comm_chargeback", "epl_liab_sfas60_ceded_comm_chargeback",  "sfas60_ceded_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_chargeback),
	CashFlowCommonData(236, "sfas60_ceded_comm_excess_bom", "epl_liab_sfas60_ceded_comm_excess_bom",  "sfas60_ceded_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_excess_bom),
	CashFlowCommonData(237, "sfas60_ceded_comm_excess_eom", "epl_liab_sfas60_ceded_comm_excess_eom",  "sfas60_ceded_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_excess_eom),
	CashFlowCommonData(238, "sfas60_ceded_comm_trail_bom", "epl_liab_sfas60_ceded_comm_trail_bom",  "sfas60_ceded_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_trail_bom),
	CashFlowCommonData(239, "sfas60_ceded_comm_trail_bom_base_plan", "epl_liab_sfas60_ceded_comm_trail_bom_base_plan",  "sfas60_ceded_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_trail_bom_base_plan),
	CashFlowCommonData(240, "sfas60_ceded_comm_trail_bom_rider", "epl_liab_sfas60_ceded_comm_trail_bom_rider",  "sfas60_ceded_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_trail_bom_rider),
	CashFlowCommonData(241, "sfas60_ceded_comm_trail_eom", "epl_liab_sfas60_ceded_comm_trail_eom",  "sfas60_ceded_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_comm_trail_eom),
	CashFlowCommonData(242, "sfas60_ceded_conversion_cost", "epl_liab_sfas60_ceded_conversion_cost",  "sfas60_ceded_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_conversion_cost),
	CashFlowCommonData(243, "sfas60_ceded_dac_amortzn_valn_basis", "epl_liab_sfas60_ceded_dac_amortzn_valn_basis",  "sfas60_ceded_dac_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_dac_amortzn_valn_basis),
	CashFlowCommonData(244, "sfas60_ceded_dac_int_valn_basis", "epl_liab_sfas60_ceded_dac_int_valn_basis",  "sfas60_ceded_dac_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_dac_int_valn_basis),
	CashFlowCommonData(245, "sfas60_ceded_dac_prelim", "epl_liab_sfas60_ceded_dac_prelim",  "sfas60_ceded_dac_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_dac_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_dac_prelim),
	CashFlowCommonData(246, "sfas60_ceded_div_applied", "epl_liab_sfas60_ceded_div_applied",  "sfas60_ceded_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_div_applied),
	CashFlowCommonData(247, "sfas60_ceded_div_paid", "epl_liab_sfas60_ceded_div_paid",  "sfas60_ceded_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_div_paid),
	CashFlowCommonData(248, "sfas60_ceded_div_valn_basis", "epl_liab_sfas60_ceded_div_valn_basis",  "sfas60_ceded_div_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_div_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_div_valn_basis),
	CashFlowCommonData(249, "sfas60_ceded_dth_claim_cost", "epl_liab_sfas60_ceded_dth_claim_cost",  "sfas60_ceded_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_dth_claim_cost),
	CashFlowCommonData(250, "sfas60_ceded_endow_claim_cost", "epl_liab_sfas60_ceded_endow_claim_cost",  "sfas60_ceded_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_endow_claim_cost),
	CashFlowCommonData(251, "sfas60_ceded_exp_valn_basis", "epl_liab_sfas60_ceded_exp_valn_basis",  "sfas60_ceded_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_exp_valn_basis, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas60_ceded_exp_valn_basis),
	CashFlowCommonData(252, "sfas60_ceded_gpr", "epl_liab_sfas60_ceded_gpr",  "sfas60_ceded_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_gpr),
	CashFlowCommonData(253, "sfas60_ceded_gpr_units_inf", "epl_liab_sfas60_ceded_gpr_units_inf",  "sfas60_ceded_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_gpr_units_inf),
	CashFlowCommonData(254, "sfas60_ceded_gross_prem", "epl_liab_sfas60_ceded_gross_prem",  "sfas60_ceded_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_gross_prem),
	CashFlowCommonData(255, "sfas60_ceded_hlth_claim_cost", "epl_liab_sfas60_ceded_hlth_claim_cost",  "sfas60_ceded_hlth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_hlth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_hlth_claim_cost)
};

const CashFlowCommonData EPL_LIAB::mCFStaticData_256[] = 
{
	CashFlowCommonData(256, "sfas60_ceded_loc_cost", "epl_liab_sfas60_ceded_loc_cost",  "sfas60_ceded_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_loc_cost),
	CashFlowCommonData(257, "sfas60_ceded_maint_exp_bom", "epl_liab_sfas60_ceded_maint_exp_bom",  "sfas60_ceded_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas60_ceded_maint_exp_bom),
	CashFlowCommonData(258, "sfas60_ceded_maint_exp_eom", "epl_liab_sfas60_ceded_maint_exp_eom",  "sfas60_ceded_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_maint_exp_eom),
	CashFlowCommonData(259, "sfas60_ceded_maint_exp_res_accrual_valn_basis", "epl_liab_sfas60_ceded_maint_exp_res_accrual_valn_basis",  "sfas60_ceded_maint_exp_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_maint_exp_res_accrual_valn_basis),
	CashFlowCommonData(260, "sfas60_ceded_maint_exp_res_int_valn_basis", "epl_liab_sfas60_ceded_maint_exp_res_int_valn_basis",  "sfas60_ceded_maint_exp_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_maint_exp_res_int_valn_basis),
	CashFlowCommonData(261, "sfas60_ceded_maint_exp_res_prelim", "epl_liab_sfas60_ceded_maint_exp_res_prelim",  "sfas60_ceded_maint_exp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maint_exp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_maint_exp_res_prelim),
	CashFlowCommonData(262, "sfas60_ceded_maturity_claim_cost", "epl_liab_sfas60_ceded_maturity_claim_cost",  "sfas60_ceded_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_maturity_claim_cost),
	CashFlowCommonData(263, "sfas60_ceded_modco_liab", "epl_liab_sfas60_ceded_modco_liab",  "sfas60_ceded_modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_modco_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_modco_liab),
	CashFlowCommonData(264, "sfas60_ceded_modco_res_adj", "epl_liab_sfas60_ceded_modco_res_adj",  "sfas60_ceded_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_modco_res_adj, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_modco_res_adj),
	CashFlowCommonData(265, "sfas60_ceded_prem_tax", "epl_liab_sfas60_ceded_prem_tax",  "sfas60_ceded_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_prem_tax),
	CashFlowCommonData(266, "sfas60_ceded_prem_waiver_res", "epl_liab_sfas60_ceded_prem_waiver_res",  "sfas60_ceded_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_prem_waiver_res),
	CashFlowCommonData(267, "sfas60_ceded_refund", "epl_liab_sfas60_ceded_refund",  "sfas60_ceded_refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_refund, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_ceded_refund),
	CashFlowCommonData(268, "sfas60_ceded_surr_ben_valn_basis", "epl_liab_sfas60_ceded_surr_ben_valn_basis",  "sfas60_ceded_surr_ben_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_surr_ben_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_surr_ben_valn_basis),
	CashFlowCommonData(269, "sfas60_ceded_surr_claim_cost", "epl_liab_sfas60_ceded_surr_claim_cost",  "sfas60_ceded_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_surr_claim_cost),
	CashFlowCommonData(270, "sfas60_ceded_terminal_div", "epl_liab_sfas60_ceded_terminal_div",  "sfas60_ceded_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_ceded_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_ceded_terminal_div),
	CashFlowCommonData(271, "sfas60_gross_acq_exp", "epl_liab_sfas60_gross_acq_exp",  "sfas60_gross_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_acq_exp),
	CashFlowCommonData(272, "sfas60_gross_ben_res_accrual_valn_basis", "epl_liab_sfas60_gross_ben_res_accrual_valn_basis",  "sfas60_gross_ben_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_ben_res_accrual_valn_basis),
	CashFlowCommonData(273, "sfas60_gross_ben_res_int_valn_basis", "epl_liab_sfas60_gross_ben_res_int_valn_basis",  "sfas60_gross_ben_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_ben_res_int_valn_basis),
	CashFlowCommonData(274, "sfas60_gross_ben_res_prelim", "epl_liab_sfas60_gross_ben_res_prelim",  "sfas60_gross_ben_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_ben_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_ben_res_prelim),
	CashFlowCommonData(275, "sfas60_gross_benefits_valn_basis", "epl_liab_sfas60_gross_benefits_valn_basis",  "sfas60_gross_benefits_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_benefits_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_benefits_valn_basis),
	CashFlowCommonData(276, "sfas60_gross_capzd_acq_exp", "epl_liab_sfas60_gross_capzd_acq_exp",  "sfas60_gross_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_acq_exp),
	CashFlowCommonData(277, "sfas60_gross_capzd_acq_exp_valn_basis", "epl_liab_sfas60_gross_capzd_acq_exp_valn_basis",  "sfas60_gross_capzd_acq_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_acq_exp_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_acq_exp_valn_basis),
	CashFlowCommonData(278, "sfas60_gross_capzd_comm_bom", "epl_liab_sfas60_gross_capzd_comm_bom",  "sfas60_gross_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_comm_bom),
	CashFlowCommonData(279, "sfas60_gross_capzd_comm_chargeback", "epl_liab_sfas60_gross_capzd_comm_chargeback",  "sfas60_gross_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_comm_chargeback),
	CashFlowCommonData(280, "sfas60_gross_capzd_comm_eom", "epl_liab_sfas60_gross_capzd_comm_eom",  "sfas60_gross_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_eom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_comm_eom),
	CashFlowCommonData(281, "sfas60_gross_capzd_comm_valn_basis", "epl_liab_sfas60_gross_capzd_comm_valn_basis",  "sfas60_gross_capzd_comm_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_comm_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_comm_valn_basis),
	CashFlowCommonData(282, "sfas60_gross_capzd_reins_yrt_cost", "epl_liab_sfas60_gross_capzd_reins_yrt_cost",  "sfas60_gross_capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_capzd_reins_yrt_cost),
	CashFlowCommonData(283, "sfas60_gross_cash_flow_bom", "epl_liab_sfas60_gross_cash_flow_bom",  "sfas60_gross_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_cash_flow_bom),
	CashFlowCommonData(284, "sfas60_gross_claim_res", "epl_liab_sfas60_gross_claim_res",  "sfas60_gross_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_claim_res),
	CashFlowCommonData(285, "sfas60_gross_comm_chargeback", "epl_liab_sfas60_gross_comm_chargeback",  "sfas60_gross_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_chargeback),
	CashFlowCommonData(286, "sfas60_gross_comm_excess_bom", "epl_liab_sfas60_gross_comm_excess_bom",  "sfas60_gross_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_excess_bom),
	CashFlowCommonData(287, "sfas60_gross_comm_excess_eom", "epl_liab_sfas60_gross_comm_excess_eom",  "sfas60_gross_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_excess_eom),
	CashFlowCommonData(288, "sfas60_gross_comm_trail_bom", "epl_liab_sfas60_gross_comm_trail_bom",  "sfas60_gross_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_trail_bom),
	CashFlowCommonData(289, "sfas60_gross_comm_trail_bom_base_plan", "epl_liab_sfas60_gross_comm_trail_bom_base_plan",  "sfas60_gross_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_trail_bom_base_plan),
	CashFlowCommonData(290, "sfas60_gross_comm_trail_bom_rider", "epl_liab_sfas60_gross_comm_trail_bom_rider",  "sfas60_gross_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_trail_bom_rider),
	CashFlowCommonData(291, "sfas60_gross_comm_trail_eom", "epl_liab_sfas60_gross_comm_trail_eom",  "sfas60_gross_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_comm_trail_eom),
	CashFlowCommonData(292, "sfas60_gross_conversion_cost", "epl_liab_sfas60_gross_conversion_cost",  "sfas60_gross_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_conversion_cost),
	CashFlowCommonData(293, "sfas60_gross_dac_amortzn_valn_basis", "epl_liab_sfas60_gross_dac_amortzn_valn_basis",  "sfas60_gross_dac_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_amortzn_valn_basis),
	CashFlowCommonData(294, "sfas60_gross_dac_int_valn_basis", "epl_liab_sfas60_gross_dac_int_valn_basis",  "sfas60_gross_dac_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_int_valn_basis),
	CashFlowCommonData(295, "sfas60_gross_dac_prelim", "epl_liab_sfas60_gross_dac_prelim",  "sfas60_gross_dac_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_prelim),
	CashFlowCommonData(296, "sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis", "epl_liab_sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis",  "sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis),
	CashFlowCommonData(297, "sfas60_gross_dac_reins_yrt_asset_int_valn_basis", "epl_liab_sfas60_gross_dac_reins_yrt_asset_int_valn_basis",  "sfas60_gross_dac_reins_yrt_asset_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_reins_yrt_asset_int_valn_basis),
	CashFlowCommonData(298, "sfas60_gross_dac_reins_yrt_asset_prelim", "epl_liab_sfas60_gross_dac_reins_yrt_asset_prelim",  "sfas60_gross_dac_reins_yrt_asset_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dac_reins_yrt_asset_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dac_reins_yrt_asset_prelim),
	CashFlowCommonData(299, "sfas60_gross_div_applied", "epl_liab_sfas60_gross_div_applied",  "sfas60_gross_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_div_applied),
	CashFlowCommonData(300, "sfas60_gross_div_paid", "epl_liab_sfas60_gross_div_paid",  "sfas60_gross_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_div_paid),
	CashFlowCommonData(301, "sfas60_gross_div_valn_basis", "epl_liab_sfas60_gross_div_valn_basis",  "sfas60_gross_div_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_div_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_div_valn_basis),
	CashFlowCommonData(302, "sfas60_gross_dth_claim_cost", "epl_liab_sfas60_gross_dth_claim_cost",  "sfas60_gross_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_dth_claim_cost),
	CashFlowCommonData(303, "sfas60_gross_endow_claim_cost", "epl_liab_sfas60_gross_endow_claim_cost",  "sfas60_gross_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_endow_claim_cost),
	CashFlowCommonData(304, "sfas60_gross_exp_valn_basis", "epl_liab_sfas60_gross_exp_valn_basis",  "sfas60_gross_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_exp_valn_basis, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas60_gross_exp_valn_basis),
	CashFlowCommonData(305, "sfas60_gross_gpr", "epl_liab_sfas60_gross_gpr",  "sfas60_gross_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_gpr),
	CashFlowCommonData(306, "sfas60_gross_gpr_units_inf", "epl_liab_sfas60_gross_gpr_units_inf",  "sfas60_gross_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_gpr_units_inf),
	CashFlowCommonData(307, "sfas60_gross_gross_prem", "epl_liab_sfas60_gross_gross_prem",  "sfas60_gross_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_gross_prem),
	CashFlowCommonData(308, "sfas60_gross_hlth_claim_cost", "epl_liab_sfas60_gross_hlth_claim_cost",  "sfas60_gross_hlth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_hlth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_hlth_claim_cost),
	CashFlowCommonData(309, "sfas60_gross_loc_cost", "epl_liab_sfas60_gross_loc_cost",  "sfas60_gross_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_loc_cost),
	CashFlowCommonData(310, "sfas60_gross_maint_exp_bom", "epl_liab_sfas60_gross_maint_exp_bom",  "sfas60_gross_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas60_gross_maint_exp_bom),
	CashFlowCommonData(311, "sfas60_gross_maint_exp_eom", "epl_liab_sfas60_gross_maint_exp_eom",  "sfas60_gross_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_maint_exp_eom),
	CashFlowCommonData(312, "sfas60_gross_maint_exp_res_accrual_valn_basis", "epl_liab_sfas60_gross_maint_exp_res_accrual_valn_basis",  "sfas60_gross_maint_exp_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_maint_exp_res_accrual_valn_basis),
	CashFlowCommonData(313, "sfas60_gross_maint_exp_res_int_valn_basis", "epl_liab_sfas60_gross_maint_exp_res_int_valn_basis",  "sfas60_gross_maint_exp_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_maint_exp_res_int_valn_basis),
	CashFlowCommonData(314, "sfas60_gross_maint_exp_res_prelim", "epl_liab_sfas60_gross_maint_exp_res_prelim",  "sfas60_gross_maint_exp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maint_exp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_maint_exp_res_prelim),
	CashFlowCommonData(315, "sfas60_gross_maturity_claim_cost", "epl_liab_sfas60_gross_maturity_claim_cost",  "sfas60_gross_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_maturity_claim_cost),
	CashFlowCommonData(316, "sfas60_gross_pol_loan", "epl_liab_sfas60_gross_pol_loan",  "sfas60_gross_pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_pol_loan, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_pol_loan),
	CashFlowCommonData(317, "sfas60_gross_pol_loan_inc", "epl_liab_sfas60_gross_pol_loan_inc",  "sfas60_gross_pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_pol_loan_inc, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_pol_loan_inc),
	CashFlowCommonData(318, "sfas60_gross_prem_tax", "epl_liab_sfas60_gross_prem_tax",  "sfas60_gross_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas60_gross_prem_tax),
	CashFlowCommonData(319, "sfas60_gross_prem_waiver_res", "epl_liab_sfas60_gross_prem_waiver_res",  "sfas60_gross_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_prem_waiver_res),
	CashFlowCommonData(320, "sfas60_gross_reins_yrt_cost", "epl_liab_sfas60_gross_reins_yrt_cost",  "sfas60_gross_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_reins_yrt_cost),
	CashFlowCommonData(321, "sfas60_gross_reins_yrt_cost_valn_basis", "epl_liab_sfas60_gross_reins_yrt_cost_valn_basis",  "sfas60_gross_reins_yrt_cost_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_reins_yrt_cost_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_reins_yrt_cost_valn_basis),
	CashFlowCommonData(322, "sfas60_gross_stat_res_rider", "epl_liab_sfas60_gross_stat_res_rider",  "sfas60_gross_stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_stat_res_rider),
	CashFlowCommonData(323, "sfas60_gross_surr_ben_valn_basis", "epl_liab_sfas60_gross_surr_ben_valn_basis",  "sfas60_gross_surr_ben_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_surr_ben_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_surr_ben_valn_basis),
	CashFlowCommonData(324, "sfas60_gross_surr_claim_cost", "epl_liab_sfas60_gross_surr_claim_cost",  "sfas60_gross_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_surr_claim_cost),
	CashFlowCommonData(325, "sfas60_gross_terminal_div", "epl_liab_sfas60_gross_terminal_div",  "sfas60_gross_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas60_gross_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas60_gross_terminal_div),
	CashFlowCommonData(326, "sfas91_ceded_acq_exp", "epl_liab_sfas91_ceded_acq_exp",  "sfas91_ceded_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_acq_exp),
	CashFlowCommonData(327, "sfas91_ceded_ann_benefits_bom", "epl_liab_sfas91_ceded_ann_benefits_bom",  "sfas91_ceded_ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ann_benefits_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ann_benefits_bom),
	CashFlowCommonData(328, "sfas91_ceded_ann_benefits_eom", "epl_liab_sfas91_ceded_ann_benefits_eom",  "sfas91_ceded_ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ann_benefits_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ann_benefits_eom),
	CashFlowCommonData(329, "sfas91_ceded_ben_maint_exp_res_cash_flow_bom", "epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_bom",  "sfas91_ceded_ben_maint_exp_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ben_maint_exp_res_cash_flow_bom),
	CashFlowCommonData(330, "sfas91_ceded_ben_maint_exp_res_cash_flow_eom", "epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_eom",  "sfas91_ceded_ben_maint_exp_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_maint_exp_res_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ben_maint_exp_res_cash_flow_eom),
	CashFlowCommonData(331, "sfas91_ceded_ben_res_cash_flow_bom", "epl_liab_sfas91_ceded_ben_res_cash_flow_bom",  "sfas91_ceded_ben_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_res_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ben_res_cash_flow_bom),
	CashFlowCommonData(332, "sfas91_ceded_ben_res_cash_flow_eom", "epl_liab_sfas91_ceded_ben_res_cash_flow_eom",  "sfas91_ceded_ben_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_ben_res_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_ben_res_cash_flow_eom),
	CashFlowCommonData(333, "sfas91_ceded_capzd_acq_exp", "epl_liab_sfas91_ceded_capzd_acq_exp",  "sfas91_ceded_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_capzd_acq_exp),
	CashFlowCommonData(334, "sfas91_ceded_capzd_comm_bom", "epl_liab_sfas91_ceded_capzd_comm_bom",  "sfas91_ceded_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_capzd_comm_bom),
	CashFlowCommonData(335, "sfas91_ceded_cash_flow_bom", "epl_liab_sfas91_ceded_cash_flow_bom",  "sfas91_ceded_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_cash_flow_bom),
	CashFlowCommonData(336, "sfas91_ceded_comm_excess_bom", "epl_liab_sfas91_ceded_comm_excess_bom",  "sfas91_ceded_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_comm_excess_bom),
	CashFlowCommonData(337, "sfas91_ceded_deferred_maint_exp", "epl_liab_sfas91_ceded_deferred_maint_exp",  "sfas91_ceded_deferred_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_deferred_maint_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_deferred_maint_exp),
	CashFlowCommonData(338, "sfas91_ceded_dth_benefits", "epl_liab_sfas91_ceded_dth_benefits",  "sfas91_ceded_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_dth_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_dth_benefits),
	CashFlowCommonData(339, "sfas91_ceded_maint_exp_bom", "epl_liab_sfas91_ceded_maint_exp_bom",  "sfas91_ceded_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_ceded_maint_exp_bom),
	CashFlowCommonData(340, "sfas91_ceded_maint_exp_eom", "epl_liab_sfas91_ceded_maint_exp_eom",  "sfas91_ceded_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_maint_exp_eom),
	CashFlowCommonData(341, "sfas91_ceded_maint_exp_res_cash_flow_bom", "epl_liab_sfas91_ceded_maint_exp_res_cash_flow_bom",  "sfas91_ceded_maint_exp_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_res_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_ceded_maint_exp_res_cash_flow_bom),
	CashFlowCommonData(342, "sfas91_ceded_maint_exp_res_cash_flow_eom", "epl_liab_sfas91_ceded_maint_exp_res_cash_flow_eom",  "sfas91_ceded_maint_exp_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_maint_exp_res_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas91_ceded_maint_exp_res_cash_flow_eom),
	CashFlowCommonData(343, "sfas91_ceded_net_res_cash_flow_bom", "epl_liab_sfas91_ceded_net_res_cash_flow_bom",  "sfas91_ceded_net_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_net_res_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_ceded_net_res_cash_flow_bom),
	CashFlowCommonData(344, "sfas91_ceded_net_res_cash_flow_eom", "epl_liab_sfas91_ceded_net_res_cash_flow_eom",  "sfas91_ceded_net_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_net_res_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas91_ceded_net_res_cash_flow_eom),
	CashFlowCommonData(345, "sfas91_ceded_noncapzd_acq_exp", "epl_liab_sfas91_ceded_noncapzd_acq_exp",  "sfas91_ceded_noncapzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_noncapzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_noncapzd_acq_exp),
	CashFlowCommonData(346, "sfas91_ceded_policies_b", "epl_liab_sfas91_ceded_policies_b",  "sfas91_ceded_policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_policies_b, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_policies_b),
	CashFlowCommonData(347, "sfas91_ceded_prem_paid", "epl_liab_sfas91_ceded_prem_paid",  "sfas91_ceded_prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_prem_paid, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_prem_paid),
	CashFlowCommonData(348, "sfas91_ceded_prem_tax", "epl_liab_sfas91_ceded_prem_tax",  "sfas91_ceded_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_prem_tax),
	CashFlowCommonData(349, "sfas91_ceded_res_ann_benefits", "epl_liab_sfas91_ceded_res_ann_benefits",  "sfas91_ceded_res_ann_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_res_ann_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_res_ann_benefits),
	CashFlowCommonData(350, "sfas91_ceded_res_dth_benefits", "epl_liab_sfas91_ceded_res_dth_benefits",  "sfas91_ceded_res_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_ceded_res_dth_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_ceded_res_dth_benefits),
	CashFlowCommonData(351, "sfas91_gross_acq_exp", "epl_liab_sfas91_gross_acq_exp",  "sfas91_gross_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_acq_exp),
	CashFlowCommonData(352, "sfas91_gross_ann_benefits_bom", "epl_liab_sfas91_gross_ann_benefits_bom",  "sfas91_gross_ann_benefits_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ann_benefits_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ann_benefits_bom),
	CashFlowCommonData(353, "sfas91_gross_ann_benefits_eom", "epl_liab_sfas91_gross_ann_benefits_eom",  "sfas91_gross_ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ann_benefits_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ann_benefits_eom),
	CashFlowCommonData(354, "sfas91_gross_ben_maint_exp_res_cash_flow_bom", "epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_bom",  "sfas91_gross_ben_maint_exp_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ben_maint_exp_res_cash_flow_bom),
	CashFlowCommonData(355, "sfas91_gross_ben_maint_exp_res_cash_flow_eom", "epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_eom",  "sfas91_gross_ben_maint_exp_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_maint_exp_res_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ben_maint_exp_res_cash_flow_eom),
	CashFlowCommonData(356, "sfas91_gross_ben_res_cash_flow_bom", "epl_liab_sfas91_gross_ben_res_cash_flow_bom",  "sfas91_gross_ben_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_res_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ben_res_cash_flow_bom),
	CashFlowCommonData(357, "sfas91_gross_ben_res_cash_flow_eom", "epl_liab_sfas91_gross_ben_res_cash_flow_eom",  "sfas91_gross_ben_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_ben_res_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_ben_res_cash_flow_eom),
	CashFlowCommonData(358, "sfas91_gross_capzd_acq_exp", "epl_liab_sfas91_gross_capzd_acq_exp",  "sfas91_gross_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_capzd_acq_exp),
	CashFlowCommonData(359, "sfas91_gross_capzd_comm_bom", "epl_liab_sfas91_gross_capzd_comm_bom",  "sfas91_gross_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_capzd_comm_bom),
	CashFlowCommonData(360, "sfas91_gross_cash_flow_bom", "epl_liab_sfas91_gross_cash_flow_bom",  "sfas91_gross_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_cash_flow_bom),
	CashFlowCommonData(361, "sfas91_gross_comm_excess_bom", "epl_liab_sfas91_gross_comm_excess_bom",  "sfas91_gross_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_comm_excess_bom),
	CashFlowCommonData(362, "sfas91_gross_deferred_maint_exp", "epl_liab_sfas91_gross_deferred_maint_exp",  "sfas91_gross_deferred_maint_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_deferred_maint_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_deferred_maint_exp),
	CashFlowCommonData(363, "sfas91_gross_dth_benefits", "epl_liab_sfas91_gross_dth_benefits",  "sfas91_gross_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_dth_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_dth_benefits),
	CashFlowCommonData(364, "sfas91_gross_maint_exp_bom", "epl_liab_sfas91_gross_maint_exp_bom",  "sfas91_gross_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_gross_maint_exp_bom),
	CashFlowCommonData(365, "sfas91_gross_maint_exp_eom", "epl_liab_sfas91_gross_maint_exp_eom",  "sfas91_gross_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_maint_exp_eom),
	CashFlowCommonData(366, "sfas91_gross_maint_exp_res_cash_flow_bom", "epl_liab_sfas91_gross_maint_exp_res_cash_flow_bom",  "sfas91_gross_maint_exp_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_res_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_gross_maint_exp_res_cash_flow_bom),
	CashFlowCommonData(367, "sfas91_gross_maint_exp_res_cash_flow_eom", "epl_liab_sfas91_gross_maint_exp_res_cash_flow_eom",  "sfas91_gross_maint_exp_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_maint_exp_res_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas91_gross_maint_exp_res_cash_flow_eom),
	CashFlowCommonData(368, "sfas91_gross_net_res_cash_flow_bom", "epl_liab_sfas91_gross_net_res_cash_flow_bom",  "sfas91_gross_net_res_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_net_res_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas91_gross_net_res_cash_flow_bom),
	CashFlowCommonData(369, "sfas91_gross_net_res_cash_flow_eom", "epl_liab_sfas91_gross_net_res_cash_flow_eom",  "sfas91_gross_net_res_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_net_res_cash_flow_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas91_gross_net_res_cash_flow_eom),
	CashFlowCommonData(370, "sfas91_gross_noncapzd_acq_exp", "epl_liab_sfas91_gross_noncapzd_acq_exp",  "sfas91_gross_noncapzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_noncapzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_noncapzd_acq_exp),
	CashFlowCommonData(371, "sfas91_gross_policies_b", "epl_liab_sfas91_gross_policies_b",  "sfas91_gross_policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_policies_b, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_policies_b),
	CashFlowCommonData(372, "sfas91_gross_prem_paid", "epl_liab_sfas91_gross_prem_paid",  "sfas91_gross_prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_prem_paid, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_prem_paid),
	CashFlowCommonData(373, "sfas91_gross_prem_tax", "epl_liab_sfas91_gross_prem_tax",  "sfas91_gross_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_prem_tax),
	CashFlowCommonData(374, "sfas91_gross_res_ann_benefits", "epl_liab_sfas91_gross_res_ann_benefits",  "sfas91_gross_res_ann_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_res_ann_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_res_ann_benefits),
	CashFlowCommonData(375, "sfas91_gross_res_dth_benefits", "epl_liab_sfas91_gross_res_dth_benefits",  "sfas91_gross_res_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas91_gross_res_dth_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas91_gross_res_dth_benefits),
	CashFlowCommonData(376, "sfas97lp_ceded_acq_exp", "epl_liab_sfas97lp_ceded_acq_exp",  "sfas97lp_ceded_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_acq_exp),
	CashFlowCommonData(377, "sfas97lp_ceded_ann_claim_cost", "epl_liab_sfas97lp_ceded_ann_claim_cost",  "sfas97lp_ceded_ann_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ann_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_ann_claim_cost),
	CashFlowCommonData(378, "sfas97lp_ceded_ben_res_accrual_valn_basis", "epl_liab_sfas97lp_ceded_ben_res_accrual_valn_basis",  "sfas97lp_ceded_ben_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_ben_res_accrual_valn_basis),
	CashFlowCommonData(379, "sfas97lp_ceded_ben_res_int_valn_basis", "epl_liab_sfas97lp_ceded_ben_res_int_valn_basis",  "sfas97lp_ceded_ben_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_ben_res_int_valn_basis),
	CashFlowCommonData(380, "sfas97lp_ceded_ben_res_prelim", "epl_liab_sfas97lp_ceded_ben_res_prelim",  "sfas97lp_ceded_ben_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_ben_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_ben_res_prelim),
	CashFlowCommonData(381, "sfas97lp_ceded_benefits_valn_basis", "epl_liab_sfas97lp_ceded_benefits_valn_basis",  "sfas97lp_ceded_benefits_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_benefits_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_benefits_valn_basis),
	CashFlowCommonData(382, "sfas97lp_ceded_capzd_acq_exp", "epl_liab_sfas97lp_ceded_capzd_acq_exp",  "sfas97lp_ceded_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_acq_exp),
	CashFlowCommonData(383, "sfas97lp_ceded_capzd_acq_exp_valn_basis", "epl_liab_sfas97lp_ceded_capzd_acq_exp_valn_basis",  "sfas97lp_ceded_capzd_acq_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_acq_exp_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_acq_exp_valn_basis),
	CashFlowCommonData(384, "sfas97lp_ceded_capzd_comm_bom", "epl_liab_sfas97lp_ceded_capzd_comm_bom",  "sfas97lp_ceded_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_comm_bom),
	CashFlowCommonData(385, "sfas97lp_ceded_capzd_comm_chargeback", "epl_liab_sfas97lp_ceded_capzd_comm_chargeback",  "sfas97lp_ceded_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_comm_chargeback),
	CashFlowCommonData(386, "sfas97lp_ceded_capzd_comm_eom", "epl_liab_sfas97lp_ceded_capzd_comm_eom",  "sfas97lp_ceded_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_comm_eom),
	CashFlowCommonData(387, "sfas97lp_ceded_capzd_comm_valn_basis", "epl_liab_sfas97lp_ceded_capzd_comm_valn_basis",  "sfas97lp_ceded_capzd_comm_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_capzd_comm_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_capzd_comm_valn_basis),
	CashFlowCommonData(388, "sfas97lp_ceded_cash_flow_bom", "epl_liab_sfas97lp_ceded_cash_flow_bom",  "sfas97lp_ceded_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_cash_flow_bom),
	CashFlowCommonData(389, "sfas97lp_ceded_claim_res", "epl_liab_sfas97lp_ceded_claim_res",  "sfas97lp_ceded_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_claim_res),
	CashFlowCommonData(390, "sfas97lp_ceded_comm_chargeback", "epl_liab_sfas97lp_ceded_comm_chargeback",  "sfas97lp_ceded_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_chargeback),
	CashFlowCommonData(391, "sfas97lp_ceded_comm_excess_bom", "epl_liab_sfas97lp_ceded_comm_excess_bom",  "sfas97lp_ceded_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_excess_bom),
	CashFlowCommonData(392, "sfas97lp_ceded_comm_excess_eom", "epl_liab_sfas97lp_ceded_comm_excess_eom",  "sfas97lp_ceded_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_excess_eom),
	CashFlowCommonData(393, "sfas97lp_ceded_comm_trail_bom", "epl_liab_sfas97lp_ceded_comm_trail_bom",  "sfas97lp_ceded_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_trail_bom),
	CashFlowCommonData(394, "sfas97lp_ceded_comm_trail_bom_base_plan", "epl_liab_sfas97lp_ceded_comm_trail_bom_base_plan",  "sfas97lp_ceded_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_trail_bom_base_plan),
	CashFlowCommonData(395, "sfas97lp_ceded_comm_trail_bom_rider", "epl_liab_sfas97lp_ceded_comm_trail_bom_rider",  "sfas97lp_ceded_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_trail_bom_rider),
	CashFlowCommonData(396, "sfas97lp_ceded_comm_trail_eom", "epl_liab_sfas97lp_ceded_comm_trail_eom",  "sfas97lp_ceded_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_comm_trail_eom),
	CashFlowCommonData(397, "sfas97lp_ceded_conversion_cost", "epl_liab_sfas97lp_ceded_conversion_cost",  "sfas97lp_ceded_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_conversion_cost),
	CashFlowCommonData(398, "sfas97lp_ceded_dac_amortzn_valn_basis", "epl_liab_sfas97lp_ceded_dac_amortzn_valn_basis",  "sfas97lp_ceded_dac_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_dac_amortzn_valn_basis),
	CashFlowCommonData(399, "sfas97lp_ceded_dac_int_valn_basis", "epl_liab_sfas97lp_ceded_dac_int_valn_basis",  "sfas97lp_ceded_dac_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_dac_int_valn_basis),
	CashFlowCommonData(400, "sfas97lp_ceded_dac_prelim", "epl_liab_sfas97lp_ceded_dac_prelim",  "sfas97lp_ceded_dac_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dac_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_dac_prelim),
	CashFlowCommonData(401, "sfas97lp_ceded_deferred_prof_amortzn_valn_basis", "epl_liab_sfas97lp_ceded_deferred_prof_amortzn_valn_basis",  "sfas97lp_ceded_deferred_prof_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_deferred_prof_amortzn_valn_basis),
	CashFlowCommonData(402, "sfas97lp_ceded_deferred_prof_int_valn_basis", "epl_liab_sfas97lp_ceded_deferred_prof_int_valn_basis",  "sfas97lp_ceded_deferred_prof_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_deferred_prof_int_valn_basis),
	CashFlowCommonData(403, "sfas97lp_ceded_deferred_prof_liab_prelim", "epl_liab_sfas97lp_ceded_deferred_prof_liab_prelim",  "sfas97lp_ceded_deferred_prof_liab_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_liab_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_deferred_prof_liab_prelim),
	CashFlowCommonData(404, "sfas97lp_ceded_deferred_prof_valn_basis", "epl_liab_sfas97lp_ceded_deferred_prof_valn_basis",  "sfas97lp_ceded_deferred_prof_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_deferred_prof_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_deferred_prof_valn_basis),
	CashFlowCommonData(405, "sfas97lp_ceded_div_applied", "epl_liab_sfas97lp_ceded_div_applied",  "sfas97lp_ceded_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_div_applied),
	CashFlowCommonData(406, "sfas97lp_ceded_div_paid", "epl_liab_sfas97lp_ceded_div_paid",  "sfas97lp_ceded_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_div_paid),
	CashFlowCommonData(407, "sfas97lp_ceded_div_valn_basis", "epl_liab_sfas97lp_ceded_div_valn_basis",  "sfas97lp_ceded_div_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_div_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_div_valn_basis),
	CashFlowCommonData(408, "sfas97lp_ceded_dth_claim_cost", "epl_liab_sfas97lp_ceded_dth_claim_cost",  "sfas97lp_ceded_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_dth_claim_cost),
	CashFlowCommonData(409, "sfas97lp_ceded_endow_claim_cost", "epl_liab_sfas97lp_ceded_endow_claim_cost",  "sfas97lp_ceded_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_endow_claim_cost),
	CashFlowCommonData(410, "sfas97lp_ceded_exp_valn_basis", "epl_liab_sfas97lp_ceded_exp_valn_basis",  "sfas97lp_ceded_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_exp_valn_basis, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97lp_ceded_exp_valn_basis),
	CashFlowCommonData(411, "sfas97lp_ceded_gpr", "epl_liab_sfas97lp_ceded_gpr",  "sfas97lp_ceded_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_gpr),
	CashFlowCommonData(412, "sfas97lp_ceded_gpr_units_inf", "epl_liab_sfas97lp_ceded_gpr_units_inf",  "sfas97lp_ceded_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_gpr_units_inf),
	CashFlowCommonData(413, "sfas97lp_ceded_gross_prem", "epl_liab_sfas97lp_ceded_gross_prem",  "sfas97lp_ceded_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_gross_prem),
	CashFlowCommonData(414, "sfas97lp_ceded_hlth_claim_cost", "epl_liab_sfas97lp_ceded_hlth_claim_cost",  "sfas97lp_ceded_hlth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_hlth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_hlth_claim_cost),
	CashFlowCommonData(415, "sfas97lp_ceded_loc_cost", "epl_liab_sfas97lp_ceded_loc_cost",  "sfas97lp_ceded_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_loc_cost),
	CashFlowCommonData(416, "sfas97lp_ceded_maint_exp_bom", "epl_liab_sfas97lp_ceded_maint_exp_bom",  "sfas97lp_ceded_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97lp_ceded_maint_exp_bom),
	CashFlowCommonData(417, "sfas97lp_ceded_maint_exp_eom", "epl_liab_sfas97lp_ceded_maint_exp_eom",  "sfas97lp_ceded_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_maint_exp_eom),
	CashFlowCommonData(418, "sfas97lp_ceded_maint_exp_res_accrual_valn_basis", "epl_liab_sfas97lp_ceded_maint_exp_res_accrual_valn_basis",  "sfas97lp_ceded_maint_exp_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_maint_exp_res_accrual_valn_basis),
	CashFlowCommonData(419, "sfas97lp_ceded_maint_exp_res_int_valn_basis", "epl_liab_sfas97lp_ceded_maint_exp_res_int_valn_basis",  "sfas97lp_ceded_maint_exp_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_maint_exp_res_int_valn_basis),
	CashFlowCommonData(420, "sfas97lp_ceded_maint_exp_res_prelim", "epl_liab_sfas97lp_ceded_maint_exp_res_prelim",  "sfas97lp_ceded_maint_exp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maint_exp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_maint_exp_res_prelim),
	CashFlowCommonData(421, "sfas97lp_ceded_maturity_claim_cost", "epl_liab_sfas97lp_ceded_maturity_claim_cost",  "sfas97lp_ceded_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_maturity_claim_cost),
	CashFlowCommonData(422, "sfas97lp_ceded_modco_liab", "epl_liab_sfas97lp_ceded_modco_liab",  "sfas97lp_ceded_modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_modco_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_modco_liab),
	CashFlowCommonData(423, "sfas97lp_ceded_modco_res_adj", "epl_liab_sfas97lp_ceded_modco_res_adj",  "sfas97lp_ceded_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_modco_res_adj, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_modco_res_adj),
	CashFlowCommonData(424, "sfas97lp_ceded_prem_tax", "epl_liab_sfas97lp_ceded_prem_tax",  "sfas97lp_ceded_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_prem_tax),
	CashFlowCommonData(425, "sfas97lp_ceded_prem_waiver_res", "epl_liab_sfas97lp_ceded_prem_waiver_res",  "sfas97lp_ceded_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_prem_waiver_res),
	CashFlowCommonData(426, "sfas97lp_ceded_refund", "epl_liab_sfas97lp_ceded_refund",  "sfas97lp_ceded_refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_refund, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_refund),
	CashFlowCommonData(427, "sfas97lp_ceded_surr_ben_valn_basis", "epl_liab_sfas97lp_ceded_surr_ben_valn_basis",  "sfas97lp_ceded_surr_ben_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_surr_ben_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_surr_ben_valn_basis),
	CashFlowCommonData(428, "sfas97lp_ceded_surr_claim_cost", "epl_liab_sfas97lp_ceded_surr_claim_cost",  "sfas97lp_ceded_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_surr_claim_cost),
	CashFlowCommonData(429, "sfas97lp_ceded_terminal_div", "epl_liab_sfas97lp_ceded_terminal_div",  "sfas97lp_ceded_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_ceded_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_ceded_terminal_div),
	CashFlowCommonData(430, "sfas97lp_gross_acq_exp", "epl_liab_sfas97lp_gross_acq_exp",  "sfas97lp_gross_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_acq_exp),
	CashFlowCommonData(431, "sfas97lp_gross_ann_claim_cost", "epl_liab_sfas97lp_gross_ann_claim_cost",  "sfas97lp_gross_ann_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ann_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_ann_claim_cost),
	CashFlowCommonData(432, "sfas97lp_gross_ben_res_accrual_valn_basis", "epl_liab_sfas97lp_gross_ben_res_accrual_valn_basis",  "sfas97lp_gross_ben_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_ben_res_accrual_valn_basis),
	CashFlowCommonData(433, "sfas97lp_gross_ben_res_int_valn_basis", "epl_liab_sfas97lp_gross_ben_res_int_valn_basis",  "sfas97lp_gross_ben_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_ben_res_int_valn_basis),
	CashFlowCommonData(434, "sfas97lp_gross_ben_res_prelim", "epl_liab_sfas97lp_gross_ben_res_prelim",  "sfas97lp_gross_ben_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_ben_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_ben_res_prelim),
	CashFlowCommonData(435, "sfas97lp_gross_benefits_valn_basis", "epl_liab_sfas97lp_gross_benefits_valn_basis",  "sfas97lp_gross_benefits_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_benefits_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_benefits_valn_basis),
	CashFlowCommonData(436, "sfas97lp_gross_capzd_acq_exp", "epl_liab_sfas97lp_gross_capzd_acq_exp",  "sfas97lp_gross_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_acq_exp),
	CashFlowCommonData(437, "sfas97lp_gross_capzd_acq_exp_valn_basis", "epl_liab_sfas97lp_gross_capzd_acq_exp_valn_basis",  "sfas97lp_gross_capzd_acq_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_acq_exp_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_acq_exp_valn_basis),
	CashFlowCommonData(438, "sfas97lp_gross_capzd_comm_bom", "epl_liab_sfas97lp_gross_capzd_comm_bom",  "sfas97lp_gross_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_comm_bom),
	CashFlowCommonData(439, "sfas97lp_gross_capzd_comm_chargeback", "epl_liab_sfas97lp_gross_capzd_comm_chargeback",  "sfas97lp_gross_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_comm_chargeback),
	CashFlowCommonData(440, "sfas97lp_gross_capzd_comm_eom", "epl_liab_sfas97lp_gross_capzd_comm_eom",  "sfas97lp_gross_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_comm_eom),
	CashFlowCommonData(441, "sfas97lp_gross_capzd_comm_valn_basis", "epl_liab_sfas97lp_gross_capzd_comm_valn_basis",  "sfas97lp_gross_capzd_comm_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_comm_valn_basis, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_comm_valn_basis),
	CashFlowCommonData(442, "sfas97lp_gross_capzd_reins_yrt_cost", "epl_liab_sfas97lp_gross_capzd_reins_yrt_cost",  "sfas97lp_gross_capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_capzd_reins_yrt_cost),
	CashFlowCommonData(443, "sfas97lp_gross_cash_flow_bom", "epl_liab_sfas97lp_gross_cash_flow_bom",  "sfas97lp_gross_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_cash_flow_bom),
	CashFlowCommonData(444, "sfas97lp_gross_claim_res", "epl_liab_sfas97lp_gross_claim_res",  "sfas97lp_gross_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_claim_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_claim_res),
	CashFlowCommonData(445, "sfas97lp_gross_comm_chargeback", "epl_liab_sfas97lp_gross_comm_chargeback",  "sfas97lp_gross_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_chargeback),
	CashFlowCommonData(446, "sfas97lp_gross_comm_excess_bom", "epl_liab_sfas97lp_gross_comm_excess_bom",  "sfas97lp_gross_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_excess_bom),
	CashFlowCommonData(447, "sfas97lp_gross_comm_excess_eom", "epl_liab_sfas97lp_gross_comm_excess_eom",  "sfas97lp_gross_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_excess_eom),
	CashFlowCommonData(448, "sfas97lp_gross_comm_trail_bom", "epl_liab_sfas97lp_gross_comm_trail_bom",  "sfas97lp_gross_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_trail_bom),
	CashFlowCommonData(449, "sfas97lp_gross_comm_trail_bom_base_plan", "epl_liab_sfas97lp_gross_comm_trail_bom_base_plan",  "sfas97lp_gross_comm_trail_bom_base_plan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom_base_plan, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_trail_bom_base_plan),
	CashFlowCommonData(450, "sfas97lp_gross_comm_trail_bom_rider", "epl_liab_sfas97lp_gross_comm_trail_bom_rider",  "sfas97lp_gross_comm_trail_bom_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_bom_rider, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_trail_bom_rider),
	CashFlowCommonData(451, "sfas97lp_gross_comm_trail_eom", "epl_liab_sfas97lp_gross_comm_trail_eom",  "sfas97lp_gross_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_comm_trail_eom),
	CashFlowCommonData(452, "sfas97lp_gross_conversion_cost", "epl_liab_sfas97lp_gross_conversion_cost",  "sfas97lp_gross_conversion_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_conversion_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_conversion_cost),
	CashFlowCommonData(453, "sfas97lp_gross_dac_amortzn_valn_basis", "epl_liab_sfas97lp_gross_dac_amortzn_valn_basis",  "sfas97lp_gross_dac_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_amortzn_valn_basis),
	CashFlowCommonData(454, "sfas97lp_gross_dac_int_valn_basis", "epl_liab_sfas97lp_gross_dac_int_valn_basis",  "sfas97lp_gross_dac_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_int_valn_basis),
	CashFlowCommonData(455, "sfas97lp_gross_dac_prelim", "epl_liab_sfas97lp_gross_dac_prelim",  "sfas97lp_gross_dac_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_prelim),
	CashFlowCommonData(456, "sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis", "epl_liab_sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis",  "sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis),
	CashFlowCommonData(457, "sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis", "epl_liab_sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis",  "sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis),
	CashFlowCommonData(458, "sfas97lp_gross_dac_reins_yrt_asset_prelim", "epl_liab_sfas97lp_gross_dac_reins_yrt_asset_prelim",  "sfas97lp_gross_dac_reins_yrt_asset_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dac_reins_yrt_asset_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dac_reins_yrt_asset_prelim),
	CashFlowCommonData(459, "sfas97lp_gross_deferred_prof_amortzn_valn_basis", "epl_liab_sfas97lp_gross_deferred_prof_amortzn_valn_basis",  "sfas97lp_gross_deferred_prof_amortzn_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_amortzn_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_deferred_prof_amortzn_valn_basis),
	CashFlowCommonData(460, "sfas97lp_gross_deferred_prof_int_valn_basis", "epl_liab_sfas97lp_gross_deferred_prof_int_valn_basis",  "sfas97lp_gross_deferred_prof_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_deferred_prof_int_valn_basis),
	CashFlowCommonData(461, "sfas97lp_gross_deferred_prof_liab_prelim", "epl_liab_sfas97lp_gross_deferred_prof_liab_prelim",  "sfas97lp_gross_deferred_prof_liab_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_liab_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_deferred_prof_liab_prelim),
	CashFlowCommonData(462, "sfas97lp_gross_deferred_prof_valn_basis", "epl_liab_sfas97lp_gross_deferred_prof_valn_basis",  "sfas97lp_gross_deferred_prof_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_deferred_prof_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_deferred_prof_valn_basis),
	CashFlowCommonData(463, "sfas97lp_gross_div_applied", "epl_liab_sfas97lp_gross_div_applied",  "sfas97lp_gross_div_applied",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_applied, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_div_applied),
	CashFlowCommonData(464, "sfas97lp_gross_div_paid", "epl_liab_sfas97lp_gross_div_paid",  "sfas97lp_gross_div_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_paid, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_div_paid),
	CashFlowCommonData(465, "sfas97lp_gross_div_valn_basis", "epl_liab_sfas97lp_gross_div_valn_basis",  "sfas97lp_gross_div_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_div_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_div_valn_basis),
	CashFlowCommonData(466, "sfas97lp_gross_dth_claim_cost", "epl_liab_sfas97lp_gross_dth_claim_cost",  "sfas97lp_gross_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_dth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_dth_claim_cost),
	CashFlowCommonData(467, "sfas97lp_gross_endow_claim_cost", "epl_liab_sfas97lp_gross_endow_claim_cost",  "sfas97lp_gross_endow_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_endow_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_endow_claim_cost),
	CashFlowCommonData(468, "sfas97lp_gross_exp_valn_basis", "epl_liab_sfas97lp_gross_exp_valn_basis",  "sfas97lp_gross_exp_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_exp_valn_basis, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97lp_gross_exp_valn_basis),
	CashFlowCommonData(469, "sfas97lp_gross_gpr", "epl_liab_sfas97lp_gross_gpr",  "sfas97lp_gross_gpr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gpr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_gpr),
	CashFlowCommonData(470, "sfas97lp_gross_gpr_units_inf", "epl_liab_sfas97lp_gross_gpr_units_inf",  "sfas97lp_gross_gpr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gpr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_gpr_units_inf),
	CashFlowCommonData(471, "sfas97lp_gross_gross_prem", "epl_liab_sfas97lp_gross_gross_prem",  "sfas97lp_gross_gross_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_gross_prem, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_gross_prem),
	CashFlowCommonData(472, "sfas97lp_gross_hlth_claim_cost", "epl_liab_sfas97lp_gross_hlth_claim_cost",  "sfas97lp_gross_hlth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_hlth_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_hlth_claim_cost),
	CashFlowCommonData(473, "sfas97lp_gross_loc_cost", "epl_liab_sfas97lp_gross_loc_cost",  "sfas97lp_gross_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_loc_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_loc_cost),
	CashFlowCommonData(474, "sfas97lp_gross_maint_exp_bom", "epl_liab_sfas97lp_gross_maint_exp_bom",  "sfas97lp_gross_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97lp_gross_maint_exp_bom),
	CashFlowCommonData(475, "sfas97lp_gross_maint_exp_eom", "epl_liab_sfas97lp_gross_maint_exp_eom",  "sfas97lp_gross_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_maint_exp_eom),
	CashFlowCommonData(476, "sfas97lp_gross_maint_exp_res_accrual_valn_basis", "epl_liab_sfas97lp_gross_maint_exp_res_accrual_valn_basis",  "sfas97lp_gross_maint_exp_res_accrual_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_accrual_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_maint_exp_res_accrual_valn_basis),
	CashFlowCommonData(477, "sfas97lp_gross_maint_exp_res_int_valn_basis", "epl_liab_sfas97lp_gross_maint_exp_res_int_valn_basis",  "sfas97lp_gross_maint_exp_res_int_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_int_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_maint_exp_res_int_valn_basis),
	CashFlowCommonData(478, "sfas97lp_gross_maint_exp_res_prelim", "epl_liab_sfas97lp_gross_maint_exp_res_prelim",  "sfas97lp_gross_maint_exp_res_prelim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maint_exp_res_prelim, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_maint_exp_res_prelim),
	CashFlowCommonData(479, "sfas97lp_gross_maturity_claim_cost", "epl_liab_sfas97lp_gross_maturity_claim_cost",  "sfas97lp_gross_maturity_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_maturity_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_maturity_claim_cost),
	CashFlowCommonData(480, "sfas97lp_gross_pol_loan", "epl_liab_sfas97lp_gross_pol_loan",  "sfas97lp_gross_pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_pol_loan, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_pol_loan),
	CashFlowCommonData(481, "sfas97lp_gross_pol_loan_inc", "epl_liab_sfas97lp_gross_pol_loan_inc",  "sfas97lp_gross_pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_pol_loan_inc, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_pol_loan_inc),
	CashFlowCommonData(482, "sfas97lp_gross_prem_tax", "epl_liab_sfas97lp_gross_prem_tax",  "sfas97lp_gross_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_prem_tax),
	CashFlowCommonData(483, "sfas97lp_gross_prem_waiver_res", "epl_liab_sfas97lp_gross_prem_waiver_res",  "sfas97lp_gross_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_prem_waiver_res, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_prem_waiver_res),
	CashFlowCommonData(484, "sfas97lp_gross_reins_yrt_cost", "epl_liab_sfas97lp_gross_reins_yrt_cost",  "sfas97lp_gross_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_reins_yrt_cost),
	CashFlowCommonData(485, "sfas97lp_gross_reins_yrt_cost_valn_basis", "epl_liab_sfas97lp_gross_reins_yrt_cost_valn_basis",  "sfas97lp_gross_reins_yrt_cost_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_reins_yrt_cost_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_reins_yrt_cost_valn_basis),
	CashFlowCommonData(486, "sfas97lp_gross_stat_res_rider", "epl_liab_sfas97lp_gross_stat_res_rider",  "sfas97lp_gross_stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_stat_res_rider),
	CashFlowCommonData(487, "sfas97lp_gross_surr_ben_valn_basis", "epl_liab_sfas97lp_gross_surr_ben_valn_basis",  "sfas97lp_gross_surr_ben_valn_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_surr_ben_valn_basis, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_surr_ben_valn_basis),
	CashFlowCommonData(488, "sfas97lp_gross_surr_claim_cost", "epl_liab_sfas97lp_gross_surr_claim_cost",  "sfas97lp_gross_surr_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_surr_claim_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_surr_claim_cost),
	CashFlowCommonData(489, "sfas97lp_gross_terminal_div", "epl_liab_sfas97lp_gross_terminal_div",  "sfas97lp_gross_terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97lp_gross_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97lp_gross_terminal_div),
	CashFlowCommonData(490, "sfas97rd_ceded_acq_exp", "epl_liab_sfas97rd_ceded_acq_exp",  "sfas97rd_ceded_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_acq_exp),
	CashFlowCommonData(491, "sfas97rd_ceded_cap_gain_fund", "epl_liab_sfas97rd_ceded_cap_gain_fund",  "sfas97rd_ceded_cap_gain_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_cap_gain_fund, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_cap_gain_fund),
	CashFlowCommonData(492, "sfas97rd_ceded_capzd_acq_exp", "epl_liab_sfas97rd_ceded_capzd_acq_exp",  "sfas97rd_ceded_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_capzd_acq_exp),
	CashFlowCommonData(493, "sfas97rd_ceded_capzd_comm_bom", "epl_liab_sfas97rd_ceded_capzd_comm_bom",  "sfas97rd_ceded_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_capzd_comm_bom),
	CashFlowCommonData(494, "sfas97rd_ceded_capzd_comm_chargeback", "epl_liab_sfas97rd_ceded_capzd_comm_chargeback",  "sfas97rd_ceded_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_capzd_comm_chargeback),
	CashFlowCommonData(495, "sfas97rd_ceded_capzd_comm_eom", "epl_liab_sfas97rd_ceded_capzd_comm_eom",  "sfas97rd_ceded_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_capzd_comm_eom),
	CashFlowCommonData(496, "sfas97rd_ceded_capzd_prem_bonus", "epl_liab_sfas97rd_ceded_capzd_prem_bonus",  "sfas97rd_ceded_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_capzd_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_capzd_prem_bonus),
	CashFlowCommonData(497, "sfas97rd_ceded_cash_flow_bom", "epl_liab_sfas97rd_ceded_cash_flow_bom",  "sfas97rd_ceded_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_cash_flow_bom),
	CashFlowCommonData(498, "sfas97rd_ceded_charges", "epl_liab_sfas97rd_ceded_charges",  "sfas97rd_ceded_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_charges),
	CashFlowCommonData(499, "sfas97rd_ceded_comm_chargeback", "epl_liab_sfas97rd_ceded_comm_chargeback",  "sfas97rd_ceded_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_comm_chargeback),
	CashFlowCommonData(500, "sfas97rd_ceded_comm_excess_bom", "epl_liab_sfas97rd_ceded_comm_excess_bom",  "sfas97rd_ceded_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_comm_excess_bom),
	CashFlowCommonData(501, "sfas97rd_ceded_comm_trail_bom", "epl_liab_sfas97rd_ceded_comm_trail_bom",  "sfas97rd_ceded_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_comm_trail_bom),
	CashFlowCommonData(502, "sfas97rd_ceded_credited_int", "epl_liab_sfas97rd_ceded_credited_int",  "sfas97rd_ceded_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_credited_int),
	CashFlowCommonData(503, "sfas97rd_ceded_deferred_loads", "epl_liab_sfas97rd_ceded_deferred_loads",  "sfas97rd_ceded_deferred_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_deferred_loads, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_deferred_loads),
	CashFlowCommonData(504, "sfas97rd_ceded_dth_claim_cost", "epl_liab_sfas97rd_ceded_dth_claim_cost",  "sfas97rd_ceded_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_dth_claim_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_dth_claim_cost),
	CashFlowCommonData(505, "sfas97rd_ceded_egp_gain_inv", "epl_liab_sfas97rd_ceded_egp_gain_inv",  "sfas97rd_ceded_egp_gain_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_inv, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_egp_gain_inv),
	CashFlowCommonData(506, "sfas97rd_ceded_egp_gain_mort", "epl_liab_sfas97rd_ceded_egp_gain_mort",  "sfas97rd_ceded_egp_gain_mort",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_mort, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_egp_gain_mort),
	CashFlowCommonData(507, "sfas97rd_ceded_egp_gain_surr", "epl_liab_sfas97rd_ceded_egp_gain_surr",  "sfas97rd_ceded_egp_gain_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_egp_gain_surr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_egp_gain_surr),
	CashFlowCommonData(508, "sfas97rd_ceded_embed_deriv_cash_flow", "epl_liab_sfas97rd_ceded_embed_deriv_cash_flow",  "sfas97rd_ceded_embed_deriv_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_embed_deriv_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_embed_deriv_cash_flow),
	CashFlowCommonData(509, "sfas97rd_ceded_fund_val_aft_int", "epl_liab_sfas97rd_ceded_fund_val_aft_int",  "sfas97rd_ceded_fund_val_aft_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_aft_int, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_fund_val_aft_int),
	CashFlowCommonData(510, "sfas97rd_ceded_fund_val_bef_int", "epl_liab_sfas97rd_ceded_fund_val_bef_int",  "sfas97rd_ceded_fund_val_bef_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_bef_int, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_fund_val_bef_int),
	CashFlowCommonData(511, "sfas97rd_ceded_fund_val_fixed", "epl_liab_sfas97rd_ceded_fund_val_fixed",  "sfas97rd_ceded_fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_fixed, 'E','N', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_fund_val_fixed)
};

const CashFlowCommonData EPL_LIAB::mCFStaticData_512[] = 
{
	CashFlowCommonData(512, "sfas97rd_ceded_fund_val_sa", "epl_liab_sfas97rd_ceded_fund_val_sa",  "sfas97rd_ceded_fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_fund_val_sa, 'E','N', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_fund_val_sa),
	CashFlowCommonData(513, "sfas97rd_ceded_gmab_ben", "epl_liab_sfas97rd_ceded_gmab_ben",  "sfas97rd_ceded_gmab_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmab_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_gmab_ben),
	CashFlowCommonData(514, "sfas97rd_ceded_gmdb_ben", "epl_liab_sfas97rd_ceded_gmdb_ben",  "sfas97rd_ceded_gmdb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmdb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_gmdb_ben),
	CashFlowCommonData(515, "sfas97rd_ceded_gmib_ben", "epl_liab_sfas97rd_ceded_gmib_ben",  "sfas97rd_ceded_gmib_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmib_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_gmib_ben),
	CashFlowCommonData(516, "sfas97rd_ceded_gmwb_ben", "epl_liab_sfas97rd_ceded_gmwb_ben",  "sfas97rd_ceded_gmwb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_gmwb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_gmwb_ben),
	CashFlowCommonData(517, "sfas97rd_ceded_hedge_cash_flow", "epl_liab_sfas97rd_ceded_hedge_cash_flow",  "sfas97rd_ceded_hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_hedge_cash_flow),
	CashFlowCommonData(518, "sfas97rd_ceded_hedge_mkt_val", "epl_liab_sfas97rd_ceded_hedge_mkt_val",  "sfas97rd_ceded_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_hedge_mkt_val),
	CashFlowCommonData(519, "sfas97rd_ceded_host_contract_cred_int", "epl_liab_sfas97rd_ceded_host_contract_cred_int",  "sfas97rd_ceded_host_contract_cred_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_cred_int, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_host_contract_cred_int),
	CashFlowCommonData(520, "sfas97rd_ceded_host_contract_val", "epl_liab_sfas97rd_ceded_host_contract_val",  "sfas97rd_ceded_host_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_val, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_host_contract_val),
	CashFlowCommonData(521, "sfas97rd_ceded_host_contract_val_bef", "epl_liab_sfas97rd_ceded_host_contract_val_bef",  "sfas97rd_ceded_host_contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_host_contract_val_bef, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_host_contract_val_bef),
	CashFlowCommonData(522, "sfas97rd_ceded_inv_inc_fund", "epl_liab_sfas97rd_ceded_inv_inc_fund",  "sfas97rd_ceded_inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_inv_inc_fund, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_inv_inc_fund),
	CashFlowCommonData(523, "sfas97rd_ceded_loads", "epl_liab_sfas97rd_ceded_loads",  "sfas97rd_ceded_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_loads, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_loads),
	CashFlowCommonData(524, "sfas97rd_ceded_loc_cost", "epl_liab_sfas97rd_ceded_loc_cost",  "sfas97rd_ceded_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_loc_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_loc_cost),
	CashFlowCommonData(525, "sfas97rd_ceded_maint_exp_bom", "epl_liab_sfas97rd_ceded_maint_exp_bom",  "sfas97rd_ceded_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_maint_exp_bom),
	CashFlowCommonData(526, "sfas97rd_ceded_maint_exp_eom", "epl_liab_sfas97rd_ceded_maint_exp_eom",  "sfas97rd_ceded_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_maint_exp_eom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_maint_exp_eom),
	CashFlowCommonData(527, "sfas97rd_ceded_modco_liab", "epl_liab_sfas97rd_ceded_modco_liab",  "sfas97rd_ceded_modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_modco_liab, 'E','N', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_modco_liab),
	CashFlowCommonData(528, "sfas97rd_ceded_modco_res_adj", "epl_liab_sfas97rd_ceded_modco_res_adj",  "sfas97rd_ceded_modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_modco_res_adj),
	CashFlowCommonData(529, "sfas97rd_ceded_persist_bon_ref", "epl_liab_sfas97rd_ceded_persist_bon_ref",  "sfas97rd_ceded_persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_persist_bon_ref, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_persist_bon_ref),
	CashFlowCommonData(530, "sfas97rd_ceded_policies_b", "epl_liab_sfas97rd_ceded_policies_b",  "sfas97rd_ceded_policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_policies_b, 'B','N', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_policies_b),
	CashFlowCommonData(531, "sfas97rd_ceded_prem_bonus", "epl_liab_sfas97rd_ceded_prem_bonus",  "sfas97rd_ceded_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_prem_bonus),
	CashFlowCommonData(532, "sfas97rd_ceded_prem_tax", "epl_liab_sfas97rd_ceded_prem_tax",  "sfas97rd_ceded_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_prem_tax),
	CashFlowCommonData(533, "sfas97rd_ceded_refund", "epl_liab_sfas97rd_ceded_refund",  "sfas97rd_ceded_refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_refund, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_ceded_refund),
	CashFlowCommonData(534, "sfas97rd_ceded_rider_charges", "epl_liab_sfas97rd_ceded_rider_charges",  "sfas97rd_ceded_rider_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_rider_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_rider_charges),
	CashFlowCommonData(535, "sfas97rd_ceded_sfas133_gmab_liab", "epl_liab_sfas97rd_ceded_sfas133_gmab_liab",  "sfas97rd_ceded_sfas133_gmab_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmab_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sfas133_gmab_liab),
	CashFlowCommonData(536, "sfas97rd_ceded_sfas133_gmib_liab", "epl_liab_sfas97rd_ceded_sfas133_gmib_liab",  "sfas97rd_ceded_sfas133_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sfas133_gmib_liab),
	CashFlowCommonData(537, "sfas97rd_ceded_sfas133_gmwb_liab", "epl_liab_sfas97rd_ceded_sfas133_gmwb_liab",  "sfas97rd_ceded_sfas133_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sfas133_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sfas133_gmwb_liab),
	CashFlowCommonData(538, "sfas97rd_ceded_sop031_assess", "epl_liab_sfas97rd_ceded_sop031_assess",  "sfas97rd_ceded_sop031_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sop031_assess),
	CashFlowCommonData(539, "sfas97rd_ceded_sop031_coi_assess", "epl_liab_sfas97rd_ceded_sop031_coi_assess",  "sfas97rd_ceded_sop031_coi_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_coi_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sop031_coi_assess),
	CashFlowCommonData(540, "sfas97rd_ceded_sop031_coi_ben", "epl_liab_sfas97rd_ceded_sop031_coi_ben",  "sfas97rd_ceded_sop031_coi_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_coi_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sop031_coi_ben),
	CashFlowCommonData(541, "sfas97rd_ceded_sop031_pbr", "epl_liab_sfas97rd_ceded_sop031_pbr",  "sfas97rd_ceded_sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sop031_pbr),
	CashFlowCommonData(542, "sfas97rd_ceded_sop031_pbr_fund_val", "epl_liab_sfas97rd_ceded_sop031_pbr_fund_val",  "sfas97rd_ceded_sop031_pbr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_sop031_pbr_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_sop031_pbr_fund_val),
	CashFlowCommonData(543, "sfas97rd_ceded_ulsg_ben", "epl_liab_sfas97rd_ceded_ulsg_ben",  "sfas97rd_ceded_ulsg_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_ceded_ulsg_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_ceded_ulsg_ben),
	CashFlowCommonData(544, "sfas97rd_gross_acq_exp", "epl_liab_sfas97rd_gross_acq_exp",  "sfas97rd_gross_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_acq_exp),
	CashFlowCommonData(545, "sfas97rd_gross_cap_gain_fund", "epl_liab_sfas97rd_gross_cap_gain_fund",  "sfas97rd_gross_cap_gain_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_cap_gain_fund, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_cap_gain_fund),
	CashFlowCommonData(546, "sfas97rd_gross_capzd_acq_exp", "epl_liab_sfas97rd_gross_capzd_acq_exp",  "sfas97rd_gross_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_acq_exp),
	CashFlowCommonData(547, "sfas97rd_gross_capzd_comm_bom", "epl_liab_sfas97rd_gross_capzd_comm_bom",  "sfas97rd_gross_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_comm_bom),
	CashFlowCommonData(548, "sfas97rd_gross_capzd_comm_chargeback", "epl_liab_sfas97rd_gross_capzd_comm_chargeback",  "sfas97rd_gross_capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_comm_chargeback),
	CashFlowCommonData(549, "sfas97rd_gross_capzd_comm_eom", "epl_liab_sfas97rd_gross_capzd_comm_eom",  "sfas97rd_gross_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_comm_eom),
	CashFlowCommonData(550, "sfas97rd_gross_capzd_prem_bonus", "epl_liab_sfas97rd_gross_capzd_prem_bonus",  "sfas97rd_gross_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_prem_bonus),
	CashFlowCommonData(551, "sfas97rd_gross_capzd_reins_yrt_cost", "epl_liab_sfas97rd_gross_capzd_reins_yrt_cost",  "sfas97rd_gross_capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_capzd_reins_yrt_cost),
	CashFlowCommonData(552, "sfas97rd_gross_cash_flow_bom", "epl_liab_sfas97rd_gross_cash_flow_bom",  "sfas97rd_gross_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_cash_flow_bom),
	CashFlowCommonData(553, "sfas97rd_gross_charges", "epl_liab_sfas97rd_gross_charges",  "sfas97rd_gross_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_charges),
	CashFlowCommonData(554, "sfas97rd_gross_comm_chargeback", "epl_liab_sfas97rd_gross_comm_chargeback",  "sfas97rd_gross_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_comm_chargeback),
	CashFlowCommonData(555, "sfas97rd_gross_comm_excess_bom", "epl_liab_sfas97rd_gross_comm_excess_bom",  "sfas97rd_gross_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_comm_excess_bom),
	CashFlowCommonData(556, "sfas97rd_gross_comm_trail_bom", "epl_liab_sfas97rd_gross_comm_trail_bom",  "sfas97rd_gross_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_comm_trail_bom),
	CashFlowCommonData(557, "sfas97rd_gross_credited_int", "epl_liab_sfas97rd_gross_credited_int",  "sfas97rd_gross_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_credited_int),
	CashFlowCommonData(558, "sfas97rd_gross_deferred_loads", "epl_liab_sfas97rd_gross_deferred_loads",  "sfas97rd_gross_deferred_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_deferred_loads, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_deferred_loads),
	CashFlowCommonData(559, "sfas97rd_gross_dth_claim_cost", "epl_liab_sfas97rd_gross_dth_claim_cost",  "sfas97rd_gross_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_dth_claim_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_dth_claim_cost),
	CashFlowCommonData(560, "sfas97rd_gross_egp_gain_inv", "epl_liab_sfas97rd_gross_egp_gain_inv",  "sfas97rd_gross_egp_gain_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_inv, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_egp_gain_inv),
	CashFlowCommonData(561, "sfas97rd_gross_egp_gain_mort", "epl_liab_sfas97rd_gross_egp_gain_mort",  "sfas97rd_gross_egp_gain_mort",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_mort, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_egp_gain_mort),
	CashFlowCommonData(562, "sfas97rd_gross_egp_gain_surr", "epl_liab_sfas97rd_gross_egp_gain_surr",  "sfas97rd_gross_egp_gain_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_egp_gain_surr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_egp_gain_surr),
	CashFlowCommonData(563, "sfas97rd_gross_embed_deriv_cash_flow", "epl_liab_sfas97rd_gross_embed_deriv_cash_flow",  "sfas97rd_gross_embed_deriv_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_embed_deriv_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_embed_deriv_cash_flow),
	CashFlowCommonData(564, "sfas97rd_gross_fund_val_aft_int", "epl_liab_sfas97rd_gross_fund_val_aft_int",  "sfas97rd_gross_fund_val_aft_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_aft_int, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_fund_val_aft_int),
	CashFlowCommonData(565, "sfas97rd_gross_fund_val_bef_int", "epl_liab_sfas97rd_gross_fund_val_bef_int",  "sfas97rd_gross_fund_val_bef_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_bef_int, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_fund_val_bef_int),
	CashFlowCommonData(566, "sfas97rd_gross_fund_val_fixed", "epl_liab_sfas97rd_gross_fund_val_fixed",  "sfas97rd_gross_fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_fixed, 'E','N', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_fund_val_fixed),
	CashFlowCommonData(567, "sfas97rd_gross_fund_val_sa", "epl_liab_sfas97rd_gross_fund_val_sa",  "sfas97rd_gross_fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_fund_val_sa, 'E','N', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_fund_val_sa),
	CashFlowCommonData(568, "sfas97rd_gross_gmab_ben", "epl_liab_sfas97rd_gross_gmab_ben",  "sfas97rd_gross_gmab_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmab_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_gmab_ben),
	CashFlowCommonData(569, "sfas97rd_gross_gmdb_ben", "epl_liab_sfas97rd_gross_gmdb_ben",  "sfas97rd_gross_gmdb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmdb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_gmdb_ben),
	CashFlowCommonData(570, "sfas97rd_gross_gmib_ben", "epl_liab_sfas97rd_gross_gmib_ben",  "sfas97rd_gross_gmib_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmib_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_gmib_ben),
	CashFlowCommonData(571, "sfas97rd_gross_gmwb_ben", "epl_liab_sfas97rd_gross_gmwb_ben",  "sfas97rd_gross_gmwb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_gmwb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_gmwb_ben),
	CashFlowCommonData(572, "sfas97rd_gross_hedge_cash_flow", "epl_liab_sfas97rd_gross_hedge_cash_flow",  "sfas97rd_gross_hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_hedge_cash_flow),
	CashFlowCommonData(573, "sfas97rd_gross_hedge_mkt_val", "epl_liab_sfas97rd_gross_hedge_mkt_val",  "sfas97rd_gross_hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_hedge_mkt_val),
	CashFlowCommonData(574, "sfas97rd_gross_host_contract_cred_int", "epl_liab_sfas97rd_gross_host_contract_cred_int",  "sfas97rd_gross_host_contract_cred_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_cred_int, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_host_contract_cred_int),
	CashFlowCommonData(575, "sfas97rd_gross_host_contract_val", "epl_liab_sfas97rd_gross_host_contract_val",  "sfas97rd_gross_host_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_val, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_host_contract_val),
	CashFlowCommonData(576, "sfas97rd_gross_host_contract_val_bef", "epl_liab_sfas97rd_gross_host_contract_val_bef",  "sfas97rd_gross_host_contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_host_contract_val_bef, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_host_contract_val_bef),
	CashFlowCommonData(577, "sfas97rd_gross_inv_inc_fund", "epl_liab_sfas97rd_gross_inv_inc_fund",  "sfas97rd_gross_inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_inv_inc_fund, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_inv_inc_fund),
	CashFlowCommonData(578, "sfas97rd_gross_loads", "epl_liab_sfas97rd_gross_loads",  "sfas97rd_gross_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_loads, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_loads),
	CashFlowCommonData(579, "sfas97rd_gross_loc_cost", "epl_liab_sfas97rd_gross_loc_cost",  "sfas97rd_gross_loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_loc_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_loc_cost),
	CashFlowCommonData(580, "sfas97rd_gross_maint_exp_bom", "epl_liab_sfas97rd_gross_maint_exp_bom",  "sfas97rd_gross_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_maint_exp_bom),
	CashFlowCommonData(581, "sfas97rd_gross_maint_exp_eom", "epl_liab_sfas97rd_gross_maint_exp_eom",  "sfas97rd_gross_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_maint_exp_eom, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_maint_exp_eom),
	CashFlowCommonData(582, "sfas97rd_gross_persist_bon_ref", "epl_liab_sfas97rd_gross_persist_bon_ref",  "sfas97rd_gross_persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_persist_bon_ref, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_persist_bon_ref),
	CashFlowCommonData(583, "sfas97rd_gross_pol_loan", "epl_liab_sfas97rd_gross_pol_loan",  "sfas97rd_gross_pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_pol_loan, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_pol_loan),
	CashFlowCommonData(584, "sfas97rd_gross_pol_loan_inc", "epl_liab_sfas97rd_gross_pol_loan_inc",  "sfas97rd_gross_pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_pol_loan_inc, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_pol_loan_inc),
	CashFlowCommonData(585, "sfas97rd_gross_policies_b", "epl_liab_sfas97rd_gross_policies_b",  "sfas97rd_gross_policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_policies_b, 'B','N', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_policies_b),
	CashFlowCommonData(586, "sfas97rd_gross_prem_bonus", "epl_liab_sfas97rd_gross_prem_bonus",  "sfas97rd_gross_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_prem_bonus),
	CashFlowCommonData(587, "sfas97rd_gross_prem_tax", "epl_liab_sfas97rd_gross_prem_tax",  "sfas97rd_gross_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas97rd_gross_prem_tax),
	CashFlowCommonData(588, "sfas97rd_gross_reins_yrt_cost", "epl_liab_sfas97rd_gross_reins_yrt_cost",  "sfas97rd_gross_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_reins_yrt_cost),
	CashFlowCommonData(589, "sfas97rd_gross_rider_charges", "epl_liab_sfas97rd_gross_rider_charges",  "sfas97rd_gross_rider_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_rider_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_rider_charges),
	CashFlowCommonData(590, "sfas97rd_gross_sfas133_gmab_liab", "epl_liab_sfas97rd_gross_sfas133_gmab_liab",  "sfas97rd_gross_sfas133_gmab_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmab_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sfas133_gmab_liab),
	CashFlowCommonData(591, "sfas97rd_gross_sfas133_gmib_liab", "epl_liab_sfas97rd_gross_sfas133_gmib_liab",  "sfas97rd_gross_sfas133_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sfas133_gmib_liab),
	CashFlowCommonData(592, "sfas97rd_gross_sfas133_gmwb_liab", "epl_liab_sfas97rd_gross_sfas133_gmwb_liab",  "sfas97rd_gross_sfas133_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sfas133_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sfas133_gmwb_liab),
	CashFlowCommonData(593, "sfas97rd_gross_sop031_assess", "epl_liab_sfas97rd_gross_sop031_assess",  "sfas97rd_gross_sop031_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sop031_assess),
	CashFlowCommonData(594, "sfas97rd_gross_sop031_coi_assess", "epl_liab_sfas97rd_gross_sop031_coi_assess",  "sfas97rd_gross_sop031_coi_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_coi_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sop031_coi_assess),
	CashFlowCommonData(595, "sfas97rd_gross_sop031_coi_ben", "epl_liab_sfas97rd_gross_sop031_coi_ben",  "sfas97rd_gross_sop031_coi_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_coi_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sop031_coi_ben),
	CashFlowCommonData(596, "sfas97rd_gross_sop031_pbr", "epl_liab_sfas97rd_gross_sop031_pbr",  "sfas97rd_gross_sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sop031_pbr),
	CashFlowCommonData(597, "sfas97rd_gross_sop031_pbr_fund_val", "epl_liab_sfas97rd_gross_sop031_pbr_fund_val",  "sfas97rd_gross_sop031_pbr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_sop031_pbr_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_sop031_pbr_fund_val),
	CashFlowCommonData(598, "sfas97rd_gross_stat_res_rider", "epl_liab_sfas97rd_gross_stat_res_rider",  "sfas97rd_gross_stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_stat_res_rider),
	CashFlowCommonData(599, "sfas97rd_gross_ulsg_ben", "epl_liab_sfas97rd_gross_ulsg_ben",  "sfas97rd_gross_ulsg_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_sfas97rd_gross_ulsg_ben, 'E','N', '3', 'P', (size_t)&modelOffset->sfas97rd_gross_ulsg_ben),
	CashFlowCommonData(600, "startup", "epl_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(601, "stat_claim_exp_res", "epl_liab_stat_claim_exp_res",  "stat_claim_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_claim_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_claim_exp_res),
	CashFlowCommonData(602, "stat_claim_res", "epl_liab_stat_claim_res",  "stat_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_claim_res),
	CashFlowCommonData(603, "stat_loading", "epl_liab_stat_loading",  "stat_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_loading, 'E','N', '3', 'C', (size_t)&modelOffset->stat_loading),
	CashFlowCommonData(604, "stat_prem_waiver_exp_res", "epl_liab_stat_prem_waiver_exp_res",  "stat_prem_waiver_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_prem_waiver_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_prem_waiver_exp_res),
	CashFlowCommonData(605, "stat_prem_waiver_res", "epl_liab_stat_prem_waiver_res",  "stat_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_prem_waiver_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_prem_waiver_res),
	CashFlowCommonData(606, "stat_res_mp", "epl_liab_stat_res_mp",  "stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_mp),
	CashFlowCommonData(607, "stat_res_mp_unhedged", "epl_liab_stat_res_mp_unhedged",  "stat_res_mp_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_mp_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_mp_unhedged),
	CashFlowCommonData(608, "stat_res_net_mp", "epl_liab_stat_res_net_mp",  "stat_res_net_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_net_mp, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_mp),
	CashFlowCommonData(609, "stat_res_net_mp_unhedged", "epl_liab_stat_res_net_mp_unhedged",  "stat_res_net_mp_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_net_mp_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_mp_unhedged),
	CashFlowCommonData(610, "stat_res_net_npr", "epl_liab_stat_res_net_npr",  "stat_res_net_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_net_npr, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_npr),
	CashFlowCommonData(611, "stat_res_net_npr_unhedged", "epl_liab_stat_res_net_npr_unhedged",  "stat_res_net_npr_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_net_npr_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_npr_unhedged),
	CashFlowCommonData(612, "stat_res_net_sa", "epl_liab_stat_res_net_sa",  "stat_res_net_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_net_sa, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_sa),
	CashFlowCommonData(613, "stat_res_npr", "epl_liab_stat_res_npr",  "stat_res_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_npr, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_npr),
	CashFlowCommonData(614, "stat_res_npr_unhedged", "epl_liab_stat_res_npr_unhedged",  "stat_res_npr_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_npr_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_npr_unhedged),
	CashFlowCommonData(615, "stat_res_sa", "epl_liab_stat_res_sa",  "stat_res_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_sa, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_sa),
	CashFlowCommonData(616, "stat_res_sa_exp_allow", "epl_liab_stat_res_sa_exp_allow",  "stat_res_sa_exp_allow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_res_sa_exp_allow, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_sa_exp_allow),
	CashFlowCommonData(617, "stat_unearn_prem_res", "epl_liab_stat_unearn_prem_res",  "stat_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_unearn_prem_res),
	CashFlowCommonData(618, "stat_unearn_prem_res_net", "epl_liab_stat_unearn_prem_res_net",  "stat_unearn_prem_res_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_net, 'E','N', '3', 'C', (size_t)&modelOffset->stat_unearn_prem_res_net),
	CashFlowCommonData(619, "stat_unearn_prem_res_npr", "epl_liab_stat_unearn_prem_res_npr",  "stat_unearn_prem_res_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_npr, 'E','N', '3', 'C', (size_t)&modelOffset->stat_unearn_prem_res_npr),
	CashFlowCommonData(620, "stat_unearn_prem_res_npr_net", "epl_liab_stat_unearn_prem_res_npr_net",  "stat_unearn_prem_res_npr_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_stat_unearn_prem_res_npr_net, 'E','N', '3', 'C', (size_t)&modelOffset->stat_unearn_prem_res_npr_net),
	CashFlowCommonData(621, "surr_benefits", "epl_liab_surr_benefits",  "surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->surr_benefits),
	CashFlowCommonData(622, "tax_capzd_prem", "epl_liab_tax_capzd_prem",  "tax_capzd_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_capzd_prem, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem),
	CashFlowCommonData(623, "tax_claim_exp_res", "epl_liab_tax_claim_exp_res",  "tax_claim_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_claim_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_claim_exp_res),
	CashFlowCommonData(624, "tax_claim_res", "epl_liab_tax_claim_res",  "tax_claim_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_claim_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_claim_res),
	CashFlowCommonData(625, "tax_deferred_net_prem", "epl_liab_tax_deferred_net_prem",  "tax_deferred_net_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_deferred_net_prem, 'E','N', '3', 'C', (size_t)&modelOffset->tax_deferred_net_prem),
	CashFlowCommonData(626, "tax_loading", "epl_liab_tax_loading",  "tax_loading",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_loading, 'E','N', '3', 'C', (size_t)&modelOffset->tax_loading),
	CashFlowCommonData(627, "tax_prem_waiver_exp_res", "epl_liab_tax_prem_waiver_exp_res",  "tax_prem_waiver_exp_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_prem_waiver_exp_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_prem_waiver_exp_res),
	CashFlowCommonData(628, "tax_prem_waiver_res", "epl_liab_tax_prem_waiver_res",  "tax_prem_waiver_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_prem_waiver_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_prem_waiver_res),
	CashFlowCommonData(629, "tax_res_mp", "epl_liab_tax_res_mp",  "tax_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->tax_res_mp),
	CashFlowCommonData(630, "tax_transfer_to_sa_net", "epl_liab_tax_transfer_to_sa_net",  "tax_transfer_to_sa_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_transfer_to_sa_net, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_transfer_to_sa_net),
	CashFlowCommonData(631, "tax_unearn_prem_res", "epl_liab_tax_unearn_prem_res",  "tax_unearn_prem_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_tax_unearn_prem_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_unearn_prem_res),
	CashFlowCommonData(632, "terminal_div", "epl_liab_terminal_div",  "terminal_div",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_terminal_div, 'E','N', '3', 'P', (size_t)&modelOffset->terminal_div),
	CashFlowCommonData(633, "transfer_cash_flow_sa_bom", "epl_liab_transfer_cash_flow_sa_bom",  "transfer_cash_flow_sa_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_transfer_cash_flow_sa_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->transfer_cash_flow_sa_bom),
	CashFlowCommonData(634, "transfer_cash_flow_sa_eom", "epl_liab_transfer_cash_flow_sa_eom",  "transfer_cash_flow_sa_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_transfer_cash_flow_sa_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->transfer_cash_flow_sa_eom),
	CashFlowCommonData(635, "transfer_to_sa_net", "epl_liab_transfer_to_sa_net",  "transfer_to_sa_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_transfer_to_sa_net, 'E','Y', '3', 'C', (size_t)&modelOffset->transfer_to_sa_net),
	CashFlowCommonData(636, "va_pba_asset_sa", "epl_liab_va_pba_asset_sa",  "va_pba_asset_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_asset_sa, 'E','N', '3', 'C', (size_t)&modelOffset->va_pba_asset_sa),
	CashFlowCommonData(637, "va_pba_ceded_cap_std_scen_ben_costs", "epl_liab_va_pba_ceded_cap_std_scen_ben_costs",  "va_pba_ceded_cap_std_scen_ben_costs",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_ceded_cap_std_scen_ben_costs, 'E','N', '3', 'P', (size_t)&modelOffset->va_pba_ceded_cap_std_scen_ben_costs),
	CashFlowCommonData(638, "va_pba_ceded_cap_std_scen_margin", "epl_liab_va_pba_ceded_cap_std_scen_margin",  "va_pba_ceded_cap_std_scen_margin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_ceded_cap_std_scen_margin, 'E','Y', '3', 'P', (size_t)&modelOffset->va_pba_ceded_cap_std_scen_margin),
	CashFlowCommonData(639, "va_pba_ceded_res_std_scen_ben_costs", "epl_liab_va_pba_ceded_res_std_scen_ben_costs",  "va_pba_ceded_res_std_scen_ben_costs",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_ceded_res_std_scen_ben_costs, 'E','N', '3', 'P', (size_t)&modelOffset->va_pba_ceded_res_std_scen_ben_costs),
	CashFlowCommonData(640, "va_pba_ceded_res_std_scen_margin", "epl_liab_va_pba_ceded_res_std_scen_margin",  "va_pba_ceded_res_std_scen_margin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_ceded_res_std_scen_margin, 'E','Y', '3', 'P', (size_t)&modelOffset->va_pba_ceded_res_std_scen_margin),
	CashFlowCommonData(641, "va_pba_gross_cap_std_scen_ben_costs", "epl_liab_va_pba_gross_cap_std_scen_ben_costs",  "va_pba_gross_cap_std_scen_ben_costs",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_gross_cap_std_scen_ben_costs, 'E','N', '3', 'P', (size_t)&modelOffset->va_pba_gross_cap_std_scen_ben_costs),
	CashFlowCommonData(642, "va_pba_gross_cap_std_scen_margin", "epl_liab_va_pba_gross_cap_std_scen_margin",  "va_pba_gross_cap_std_scen_margin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_gross_cap_std_scen_margin, 'E','Y', '3', 'P', (size_t)&modelOffset->va_pba_gross_cap_std_scen_margin),
	CashFlowCommonData(643, "va_pba_gross_res_std_scen_ben_costs", "epl_liab_va_pba_gross_res_std_scen_ben_costs",  "va_pba_gross_res_std_scen_ben_costs",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_gross_res_std_scen_ben_costs, 'E','N', '3', 'P', (size_t)&modelOffset->va_pba_gross_res_std_scen_ben_costs),
	CashFlowCommonData(644, "va_pba_gross_res_std_scen_margin", "epl_liab_va_pba_gross_res_std_scen_margin",  "va_pba_gross_res_std_scen_margin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_gross_res_std_scen_margin, 'E','Y', '3', 'P', (size_t)&modelOffset->va_pba_gross_res_std_scen_margin),
	CashFlowCommonData(645, "va_pba_working_res", "epl_liab_va_pba_working_res",  "va_pba_working_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_va_pba_working_res, 'E','N', '3', 'P', (size_t)&modelOffset->va_pba_working_res),
	CashFlowCommonData(646, "withdrl_benefits", "epl_liab_withdrl_benefits",  "withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPL_LIAB_UDF::epl_liab_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->withdrl_benefits)
};
const CashFlowCommonData* EPL_LIAB::mCFStaticData[] = {
	&EPL_LIAB::mCFStaticData_0[0],
	&EPL_LIAB::mCFStaticData_0[1],
	&EPL_LIAB::mCFStaticData_0[2],
	&EPL_LIAB::mCFStaticData_0[3],
	&EPL_LIAB::mCFStaticData_0[4],
	&EPL_LIAB::mCFStaticData_0[5],
	&EPL_LIAB::mCFStaticData_0[6],
	&EPL_LIAB::mCFStaticData_0[7],
	&EPL_LIAB::mCFStaticData_0[8],
	&EPL_LIAB::mCFStaticData_0[9],
	&EPL_LIAB::mCFStaticData_0[10],
	&EPL_LIAB::mCFStaticData_0[11],
	&EPL_LIAB::mCFStaticData_0[12],
	&EPL_LIAB::mCFStaticData_0[13],
	&EPL_LIAB::mCFStaticData_0[14],
	&EPL_LIAB::mCFStaticData_0[15],
	&EPL_LIAB::mCFStaticData_0[16],
	&EPL_LIAB::mCFStaticData_0[17],
	&EPL_LIAB::mCFStaticData_0[18],
	&EPL_LIAB::mCFStaticData_0[19],
	&EPL_LIAB::mCFStaticData_0[20],
	&EPL_LIAB::mCFStaticData_0[21],
	&EPL_LIAB::mCFStaticData_0[22],
	&EPL_LIAB::mCFStaticData_0[23],
	&EPL_LIAB::mCFStaticData_0[24],
	&EPL_LIAB::mCFStaticData_0[25],
	&EPL_LIAB::mCFStaticData_0[26],
	&EPL_LIAB::mCFStaticData_0[27],
	&EPL_LIAB::mCFStaticData_0[28],
	&EPL_LIAB::mCFStaticData_0[29],
	&EPL_LIAB::mCFStaticData_0[30],
	&EPL_LIAB::mCFStaticData_0[31],
	&EPL_LIAB::mCFStaticData_0[32],
	&EPL_LIAB::mCFStaticData_0[33],
	&EPL_LIAB::mCFStaticData_0[34],
	&EPL_LIAB::mCFStaticData_0[35],
	&EPL_LIAB::mCFStaticData_0[36],
	&EPL_LIAB::mCFStaticData_0[37],
	&EPL_LIAB::mCFStaticData_0[38],
	&EPL_LIAB::mCFStaticData_0[39],
	&EPL_LIAB::mCFStaticData_0[40],
	&EPL_LIAB::mCFStaticData_0[41],
	&EPL_LIAB::mCFStaticData_0[42],
	&EPL_LIAB::mCFStaticData_0[43],
	&EPL_LIAB::mCFStaticData_0[44],
	&EPL_LIAB::mCFStaticData_0[45],
	&EPL_LIAB::mCFStaticData_0[46],
	&EPL_LIAB::mCFStaticData_0[47],
	&EPL_LIAB::mCFStaticData_0[48],
	&EPL_LIAB::mCFStaticData_0[49],
	&EPL_LIAB::mCFStaticData_0[50],
	&EPL_LIAB::mCFStaticData_0[51],
	&EPL_LIAB::mCFStaticData_0[52],
	&EPL_LIAB::mCFStaticData_0[53],
	&EPL_LIAB::mCFStaticData_0[54],
	&EPL_LIAB::mCFStaticData_0[55],
	&EPL_LIAB::mCFStaticData_0[56],
	&EPL_LIAB::mCFStaticData_0[57],
	&EPL_LIAB::mCFStaticData_0[58],
	&EPL_LIAB::mCFStaticData_0[59],
	&EPL_LIAB::mCFStaticData_0[60],
	&EPL_LIAB::mCFStaticData_0[61],
	&EPL_LIAB::mCFStaticData_0[62],
	&EPL_LIAB::mCFStaticData_0[63],
	&EPL_LIAB::mCFStaticData_0[64],
	&EPL_LIAB::mCFStaticData_0[65],
	&EPL_LIAB::mCFStaticData_0[66],
	&EPL_LIAB::mCFStaticData_0[67],
	&EPL_LIAB::mCFStaticData_0[68],
	&EPL_LIAB::mCFStaticData_0[69],
	&EPL_LIAB::mCFStaticData_0[70],
	&EPL_LIAB::mCFStaticData_0[71],
	&EPL_LIAB::mCFStaticData_0[72],
	&EPL_LIAB::mCFStaticData_0[73],
	&EPL_LIAB::mCFStaticData_0[74],
	&EPL_LIAB::mCFStaticData_0[75],
	&EPL_LIAB::mCFStaticData_0[76],
	&EPL_LIAB::mCFStaticData_0[77],
	&EPL_LIAB::mCFStaticData_0[78],
	&EPL_LIAB::mCFStaticData_0[79],
	&EPL_LIAB::mCFStaticData_0[80],
	&EPL_LIAB::mCFStaticData_0[81],
	&EPL_LIAB::mCFStaticData_0[82],
	&EPL_LIAB::mCFStaticData_0[83],
	&EPL_LIAB::mCFStaticData_0[84],
	&EPL_LIAB::mCFStaticData_0[85],
	&EPL_LIAB::mCFStaticData_0[86],
	&EPL_LIAB::mCFStaticData_0[87],
	&EPL_LIAB::mCFStaticData_0[88],
	&EPL_LIAB::mCFStaticData_0[89],
	&EPL_LIAB::mCFStaticData_0[90],
	&EPL_LIAB::mCFStaticData_0[91],
	&EPL_LIAB::mCFStaticData_0[92],
	&EPL_LIAB::mCFStaticData_0[93],
	&EPL_LIAB::mCFStaticData_0[94],
	&EPL_LIAB::mCFStaticData_0[95],
	&EPL_LIAB::mCFStaticData_0[96],
	&EPL_LIAB::mCFStaticData_0[97],
	&EPL_LIAB::mCFStaticData_0[98],
	&EPL_LIAB::mCFStaticData_0[99],
	&EPL_LIAB::mCFStaticData_0[100],
	&EPL_LIAB::mCFStaticData_0[101],
	&EPL_LIAB::mCFStaticData_0[102],
	&EPL_LIAB::mCFStaticData_0[103],
	&EPL_LIAB::mCFStaticData_0[104],
	&EPL_LIAB::mCFStaticData_0[105],
	&EPL_LIAB::mCFStaticData_0[106],
	&EPL_LIAB::mCFStaticData_0[107],
	&EPL_LIAB::mCFStaticData_0[108],
	&EPL_LIAB::mCFStaticData_0[109],
	&EPL_LIAB::mCFStaticData_0[110],
	&EPL_LIAB::mCFStaticData_0[111],
	&EPL_LIAB::mCFStaticData_0[112],
	&EPL_LIAB::mCFStaticData_0[113],
	&EPL_LIAB::mCFStaticData_0[114],
	&EPL_LIAB::mCFStaticData_0[115],
	&EPL_LIAB::mCFStaticData_0[116],
	&EPL_LIAB::mCFStaticData_0[117],
	&EPL_LIAB::mCFStaticData_0[118],
	&EPL_LIAB::mCFStaticData_0[119],
	&EPL_LIAB::mCFStaticData_0[120],
	&EPL_LIAB::mCFStaticData_0[121],
	&EPL_LIAB::mCFStaticData_0[122],
	&EPL_LIAB::mCFStaticData_0[123],
	&EPL_LIAB::mCFStaticData_0[124],
	&EPL_LIAB::mCFStaticData_0[125],
	&EPL_LIAB::mCFStaticData_0[126],
	&EPL_LIAB::mCFStaticData_0[127],
	&EPL_LIAB::mCFStaticData_0[128],
	&EPL_LIAB::mCFStaticData_0[129],
	&EPL_LIAB::mCFStaticData_0[130],
	&EPL_LIAB::mCFStaticData_0[131],
	&EPL_LIAB::mCFStaticData_0[132],
	&EPL_LIAB::mCFStaticData_0[133],
	&EPL_LIAB::mCFStaticData_0[134],
	&EPL_LIAB::mCFStaticData_0[135],
	&EPL_LIAB::mCFStaticData_0[136],
	&EPL_LIAB::mCFStaticData_0[137],
	&EPL_LIAB::mCFStaticData_0[138],
	&EPL_LIAB::mCFStaticData_0[139],
	&EPL_LIAB::mCFStaticData_0[140],
	&EPL_LIAB::mCFStaticData_0[141],
	&EPL_LIAB::mCFStaticData_0[142],
	&EPL_LIAB::mCFStaticData_0[143],
	&EPL_LIAB::mCFStaticData_0[144],
	&EPL_LIAB::mCFStaticData_0[145],
	&EPL_LIAB::mCFStaticData_0[146],
	&EPL_LIAB::mCFStaticData_0[147],
	&EPL_LIAB::mCFStaticData_0[148],
	&EPL_LIAB::mCFStaticData_0[149],
	&EPL_LIAB::mCFStaticData_0[150],
	&EPL_LIAB::mCFStaticData_0[151],
	&EPL_LIAB::mCFStaticData_0[152],
	&EPL_LIAB::mCFStaticData_0[153],
	&EPL_LIAB::mCFStaticData_0[154],
	&EPL_LIAB::mCFStaticData_0[155],
	&EPL_LIAB::mCFStaticData_0[156],
	&EPL_LIAB::mCFStaticData_0[157],
	&EPL_LIAB::mCFStaticData_0[158],
	&EPL_LIAB::mCFStaticData_0[159],
	&EPL_LIAB::mCFStaticData_0[160],
	&EPL_LIAB::mCFStaticData_0[161],
	&EPL_LIAB::mCFStaticData_0[162],
	&EPL_LIAB::mCFStaticData_0[163],
	&EPL_LIAB::mCFStaticData_0[164],
	&EPL_LIAB::mCFStaticData_0[165],
	&EPL_LIAB::mCFStaticData_0[166],
	&EPL_LIAB::mCFStaticData_0[167],
	&EPL_LIAB::mCFStaticData_0[168],
	&EPL_LIAB::mCFStaticData_0[169],
	&EPL_LIAB::mCFStaticData_0[170],
	&EPL_LIAB::mCFStaticData_0[171],
	&EPL_LIAB::mCFStaticData_0[172],
	&EPL_LIAB::mCFStaticData_0[173],
	&EPL_LIAB::mCFStaticData_0[174],
	&EPL_LIAB::mCFStaticData_0[175],
	&EPL_LIAB::mCFStaticData_0[176],
	&EPL_LIAB::mCFStaticData_0[177],
	&EPL_LIAB::mCFStaticData_0[178],
	&EPL_LIAB::mCFStaticData_0[179],
	&EPL_LIAB::mCFStaticData_0[180],
	&EPL_LIAB::mCFStaticData_0[181],
	&EPL_LIAB::mCFStaticData_0[182],
	&EPL_LIAB::mCFStaticData_0[183],
	&EPL_LIAB::mCFStaticData_0[184],
	&EPL_LIAB::mCFStaticData_0[185],
	&EPL_LIAB::mCFStaticData_0[186],
	&EPL_LIAB::mCFStaticData_0[187],
	&EPL_LIAB::mCFStaticData_0[188],
	&EPL_LIAB::mCFStaticData_0[189],
	&EPL_LIAB::mCFStaticData_0[190],
	&EPL_LIAB::mCFStaticData_0[191],
	&EPL_LIAB::mCFStaticData_0[192],
	&EPL_LIAB::mCFStaticData_0[193],
	&EPL_LIAB::mCFStaticData_0[194],
	&EPL_LIAB::mCFStaticData_0[195],
	&EPL_LIAB::mCFStaticData_0[196],
	&EPL_LIAB::mCFStaticData_0[197],
	&EPL_LIAB::mCFStaticData_0[198],
	&EPL_LIAB::mCFStaticData_0[199],
	&EPL_LIAB::mCFStaticData_0[200],
	&EPL_LIAB::mCFStaticData_0[201],
	&EPL_LIAB::mCFStaticData_0[202],
	&EPL_LIAB::mCFStaticData_0[203],
	&EPL_LIAB::mCFStaticData_0[204],
	&EPL_LIAB::mCFStaticData_0[205],
	&EPL_LIAB::mCFStaticData_0[206],
	&EPL_LIAB::mCFStaticData_0[207],
	&EPL_LIAB::mCFStaticData_0[208],
	&EPL_LIAB::mCFStaticData_0[209],
	&EPL_LIAB::mCFStaticData_0[210],
	&EPL_LIAB::mCFStaticData_0[211],
	&EPL_LIAB::mCFStaticData_0[212],
	&EPL_LIAB::mCFStaticData_0[213],
	&EPL_LIAB::mCFStaticData_0[214],
	&EPL_LIAB::mCFStaticData_0[215],
	&EPL_LIAB::mCFStaticData_0[216],
	&EPL_LIAB::mCFStaticData_0[217],
	&EPL_LIAB::mCFStaticData_0[218],
	&EPL_LIAB::mCFStaticData_0[219],
	&EPL_LIAB::mCFStaticData_0[220],
	&EPL_LIAB::mCFStaticData_0[221],
	&EPL_LIAB::mCFStaticData_0[222],
	&EPL_LIAB::mCFStaticData_0[223],
	&EPL_LIAB::mCFStaticData_0[224],
	&EPL_LIAB::mCFStaticData_0[225],
	&EPL_LIAB::mCFStaticData_0[226],
	&EPL_LIAB::mCFStaticData_0[227],
	&EPL_LIAB::mCFStaticData_0[228],
	&EPL_LIAB::mCFStaticData_0[229],
	&EPL_LIAB::mCFStaticData_0[230],
	&EPL_LIAB::mCFStaticData_0[231],
	&EPL_LIAB::mCFStaticData_0[232],
	&EPL_LIAB::mCFStaticData_0[233],
	&EPL_LIAB::mCFStaticData_0[234],
	&EPL_LIAB::mCFStaticData_0[235],
	&EPL_LIAB::mCFStaticData_0[236],
	&EPL_LIAB::mCFStaticData_0[237],
	&EPL_LIAB::mCFStaticData_0[238],
	&EPL_LIAB::mCFStaticData_0[239],
	&EPL_LIAB::mCFStaticData_0[240],
	&EPL_LIAB::mCFStaticData_0[241],
	&EPL_LIAB::mCFStaticData_0[242],
	&EPL_LIAB::mCFStaticData_0[243],
	&EPL_LIAB::mCFStaticData_0[244],
	&EPL_LIAB::mCFStaticData_0[245],
	&EPL_LIAB::mCFStaticData_0[246],
	&EPL_LIAB::mCFStaticData_0[247],
	&EPL_LIAB::mCFStaticData_0[248],
	&EPL_LIAB::mCFStaticData_0[249],
	&EPL_LIAB::mCFStaticData_0[250],
	&EPL_LIAB::mCFStaticData_0[251],
	&EPL_LIAB::mCFStaticData_0[252],
	&EPL_LIAB::mCFStaticData_0[253],
	&EPL_LIAB::mCFStaticData_0[254],
	&EPL_LIAB::mCFStaticData_0[255],
	&EPL_LIAB::mCFStaticData_256[0],
	&EPL_LIAB::mCFStaticData_256[1],
	&EPL_LIAB::mCFStaticData_256[2],
	&EPL_LIAB::mCFStaticData_256[3],
	&EPL_LIAB::mCFStaticData_256[4],
	&EPL_LIAB::mCFStaticData_256[5],
	&EPL_LIAB::mCFStaticData_256[6],
	&EPL_LIAB::mCFStaticData_256[7],
	&EPL_LIAB::mCFStaticData_256[8],
	&EPL_LIAB::mCFStaticData_256[9],
	&EPL_LIAB::mCFStaticData_256[10],
	&EPL_LIAB::mCFStaticData_256[11],
	&EPL_LIAB::mCFStaticData_256[12],
	&EPL_LIAB::mCFStaticData_256[13],
	&EPL_LIAB::mCFStaticData_256[14],
	&EPL_LIAB::mCFStaticData_256[15],
	&EPL_LIAB::mCFStaticData_256[16],
	&EPL_LIAB::mCFStaticData_256[17],
	&EPL_LIAB::mCFStaticData_256[18],
	&EPL_LIAB::mCFStaticData_256[19],
	&EPL_LIAB::mCFStaticData_256[20],
	&EPL_LIAB::mCFStaticData_256[21],
	&EPL_LIAB::mCFStaticData_256[22],
	&EPL_LIAB::mCFStaticData_256[23],
	&EPL_LIAB::mCFStaticData_256[24],
	&EPL_LIAB::mCFStaticData_256[25],
	&EPL_LIAB::mCFStaticData_256[26],
	&EPL_LIAB::mCFStaticData_256[27],
	&EPL_LIAB::mCFStaticData_256[28],
	&EPL_LIAB::mCFStaticData_256[29],
	&EPL_LIAB::mCFStaticData_256[30],
	&EPL_LIAB::mCFStaticData_256[31],
	&EPL_LIAB::mCFStaticData_256[32],
	&EPL_LIAB::mCFStaticData_256[33],
	&EPL_LIAB::mCFStaticData_256[34],
	&EPL_LIAB::mCFStaticData_256[35],
	&EPL_LIAB::mCFStaticData_256[36],
	&EPL_LIAB::mCFStaticData_256[37],
	&EPL_LIAB::mCFStaticData_256[38],
	&EPL_LIAB::mCFStaticData_256[39],
	&EPL_LIAB::mCFStaticData_256[40],
	&EPL_LIAB::mCFStaticData_256[41],
	&EPL_LIAB::mCFStaticData_256[42],
	&EPL_LIAB::mCFStaticData_256[43],
	&EPL_LIAB::mCFStaticData_256[44],
	&EPL_LIAB::mCFStaticData_256[45],
	&EPL_LIAB::mCFStaticData_256[46],
	&EPL_LIAB::mCFStaticData_256[47],
	&EPL_LIAB::mCFStaticData_256[48],
	&EPL_LIAB::mCFStaticData_256[49],
	&EPL_LIAB::mCFStaticData_256[50],
	&EPL_LIAB::mCFStaticData_256[51],
	&EPL_LIAB::mCFStaticData_256[52],
	&EPL_LIAB::mCFStaticData_256[53],
	&EPL_LIAB::mCFStaticData_256[54],
	&EPL_LIAB::mCFStaticData_256[55],
	&EPL_LIAB::mCFStaticData_256[56],
	&EPL_LIAB::mCFStaticData_256[57],
	&EPL_LIAB::mCFStaticData_256[58],
	&EPL_LIAB::mCFStaticData_256[59],
	&EPL_LIAB::mCFStaticData_256[60],
	&EPL_LIAB::mCFStaticData_256[61],
	&EPL_LIAB::mCFStaticData_256[62],
	&EPL_LIAB::mCFStaticData_256[63],
	&EPL_LIAB::mCFStaticData_256[64],
	&EPL_LIAB::mCFStaticData_256[65],
	&EPL_LIAB::mCFStaticData_256[66],
	&EPL_LIAB::mCFStaticData_256[67],
	&EPL_LIAB::mCFStaticData_256[68],
	&EPL_LIAB::mCFStaticData_256[69],
	&EPL_LIAB::mCFStaticData_256[70],
	&EPL_LIAB::mCFStaticData_256[71],
	&EPL_LIAB::mCFStaticData_256[72],
	&EPL_LIAB::mCFStaticData_256[73],
	&EPL_LIAB::mCFStaticData_256[74],
	&EPL_LIAB::mCFStaticData_256[75],
	&EPL_LIAB::mCFStaticData_256[76],
	&EPL_LIAB::mCFStaticData_256[77],
	&EPL_LIAB::mCFStaticData_256[78],
	&EPL_LIAB::mCFStaticData_256[79],
	&EPL_LIAB::mCFStaticData_256[80],
	&EPL_LIAB::mCFStaticData_256[81],
	&EPL_LIAB::mCFStaticData_256[82],
	&EPL_LIAB::mCFStaticData_256[83],
	&EPL_LIAB::mCFStaticData_256[84],
	&EPL_LIAB::mCFStaticData_256[85],
	&EPL_LIAB::mCFStaticData_256[86],
	&EPL_LIAB::mCFStaticData_256[87],
	&EPL_LIAB::mCFStaticData_256[88],
	&EPL_LIAB::mCFStaticData_256[89],
	&EPL_LIAB::mCFStaticData_256[90],
	&EPL_LIAB::mCFStaticData_256[91],
	&EPL_LIAB::mCFStaticData_256[92],
	&EPL_LIAB::mCFStaticData_256[93],
	&EPL_LIAB::mCFStaticData_256[94],
	&EPL_LIAB::mCFStaticData_256[95],
	&EPL_LIAB::mCFStaticData_256[96],
	&EPL_LIAB::mCFStaticData_256[97],
	&EPL_LIAB::mCFStaticData_256[98],
	&EPL_LIAB::mCFStaticData_256[99],
	&EPL_LIAB::mCFStaticData_256[100],
	&EPL_LIAB::mCFStaticData_256[101],
	&EPL_LIAB::mCFStaticData_256[102],
	&EPL_LIAB::mCFStaticData_256[103],
	&EPL_LIAB::mCFStaticData_256[104],
	&EPL_LIAB::mCFStaticData_256[105],
	&EPL_LIAB::mCFStaticData_256[106],
	&EPL_LIAB::mCFStaticData_256[107],
	&EPL_LIAB::mCFStaticData_256[108],
	&EPL_LIAB::mCFStaticData_256[109],
	&EPL_LIAB::mCFStaticData_256[110],
	&EPL_LIAB::mCFStaticData_256[111],
	&EPL_LIAB::mCFStaticData_256[112],
	&EPL_LIAB::mCFStaticData_256[113],
	&EPL_LIAB::mCFStaticData_256[114],
	&EPL_LIAB::mCFStaticData_256[115],
	&EPL_LIAB::mCFStaticData_256[116],
	&EPL_LIAB::mCFStaticData_256[117],
	&EPL_LIAB::mCFStaticData_256[118],
	&EPL_LIAB::mCFStaticData_256[119],
	&EPL_LIAB::mCFStaticData_256[120],
	&EPL_LIAB::mCFStaticData_256[121],
	&EPL_LIAB::mCFStaticData_256[122],
	&EPL_LIAB::mCFStaticData_256[123],
	&EPL_LIAB::mCFStaticData_256[124],
	&EPL_LIAB::mCFStaticData_256[125],
	&EPL_LIAB::mCFStaticData_256[126],
	&EPL_LIAB::mCFStaticData_256[127],
	&EPL_LIAB::mCFStaticData_256[128],
	&EPL_LIAB::mCFStaticData_256[129],
	&EPL_LIAB::mCFStaticData_256[130],
	&EPL_LIAB::mCFStaticData_256[131],
	&EPL_LIAB::mCFStaticData_256[132],
	&EPL_LIAB::mCFStaticData_256[133],
	&EPL_LIAB::mCFStaticData_256[134],
	&EPL_LIAB::mCFStaticData_256[135],
	&EPL_LIAB::mCFStaticData_256[136],
	&EPL_LIAB::mCFStaticData_256[137],
	&EPL_LIAB::mCFStaticData_256[138],
	&EPL_LIAB::mCFStaticData_256[139],
	&EPL_LIAB::mCFStaticData_256[140],
	&EPL_LIAB::mCFStaticData_256[141],
	&EPL_LIAB::mCFStaticData_256[142],
	&EPL_LIAB::mCFStaticData_256[143],
	&EPL_LIAB::mCFStaticData_256[144],
	&EPL_LIAB::mCFStaticData_256[145],
	&EPL_LIAB::mCFStaticData_256[146],
	&EPL_LIAB::mCFStaticData_256[147],
	&EPL_LIAB::mCFStaticData_256[148],
	&EPL_LIAB::mCFStaticData_256[149],
	&EPL_LIAB::mCFStaticData_256[150],
	&EPL_LIAB::mCFStaticData_256[151],
	&EPL_LIAB::mCFStaticData_256[152],
	&EPL_LIAB::mCFStaticData_256[153],
	&EPL_LIAB::mCFStaticData_256[154],
	&EPL_LIAB::mCFStaticData_256[155],
	&EPL_LIAB::mCFStaticData_256[156],
	&EPL_LIAB::mCFStaticData_256[157],
	&EPL_LIAB::mCFStaticData_256[158],
	&EPL_LIAB::mCFStaticData_256[159],
	&EPL_LIAB::mCFStaticData_256[160],
	&EPL_LIAB::mCFStaticData_256[161],
	&EPL_LIAB::mCFStaticData_256[162],
	&EPL_LIAB::mCFStaticData_256[163],
	&EPL_LIAB::mCFStaticData_256[164],
	&EPL_LIAB::mCFStaticData_256[165],
	&EPL_LIAB::mCFStaticData_256[166],
	&EPL_LIAB::mCFStaticData_256[167],
	&EPL_LIAB::mCFStaticData_256[168],
	&EPL_LIAB::mCFStaticData_256[169],
	&EPL_LIAB::mCFStaticData_256[170],
	&EPL_LIAB::mCFStaticData_256[171],
	&EPL_LIAB::mCFStaticData_256[172],
	&EPL_LIAB::mCFStaticData_256[173],
	&EPL_LIAB::mCFStaticData_256[174],
	&EPL_LIAB::mCFStaticData_256[175],
	&EPL_LIAB::mCFStaticData_256[176],
	&EPL_LIAB::mCFStaticData_256[177],
	&EPL_LIAB::mCFStaticData_256[178],
	&EPL_LIAB::mCFStaticData_256[179],
	&EPL_LIAB::mCFStaticData_256[180],
	&EPL_LIAB::mCFStaticData_256[181],
	&EPL_LIAB::mCFStaticData_256[182],
	&EPL_LIAB::mCFStaticData_256[183],
	&EPL_LIAB::mCFStaticData_256[184],
	&EPL_LIAB::mCFStaticData_256[185],
	&EPL_LIAB::mCFStaticData_256[186],
	&EPL_LIAB::mCFStaticData_256[187],
	&EPL_LIAB::mCFStaticData_256[188],
	&EPL_LIAB::mCFStaticData_256[189],
	&EPL_LIAB::mCFStaticData_256[190],
	&EPL_LIAB::mCFStaticData_256[191],
	&EPL_LIAB::mCFStaticData_256[192],
	&EPL_LIAB::mCFStaticData_256[193],
	&EPL_LIAB::mCFStaticData_256[194],
	&EPL_LIAB::mCFStaticData_256[195],
	&EPL_LIAB::mCFStaticData_256[196],
	&EPL_LIAB::mCFStaticData_256[197],
	&EPL_LIAB::mCFStaticData_256[198],
	&EPL_LIAB::mCFStaticData_256[199],
	&EPL_LIAB::mCFStaticData_256[200],
	&EPL_LIAB::mCFStaticData_256[201],
	&EPL_LIAB::mCFStaticData_256[202],
	&EPL_LIAB::mCFStaticData_256[203],
	&EPL_LIAB::mCFStaticData_256[204],
	&EPL_LIAB::mCFStaticData_256[205],
	&EPL_LIAB::mCFStaticData_256[206],
	&EPL_LIAB::mCFStaticData_256[207],
	&EPL_LIAB::mCFStaticData_256[208],
	&EPL_LIAB::mCFStaticData_256[209],
	&EPL_LIAB::mCFStaticData_256[210],
	&EPL_LIAB::mCFStaticData_256[211],
	&EPL_LIAB::mCFStaticData_256[212],
	&EPL_LIAB::mCFStaticData_256[213],
	&EPL_LIAB::mCFStaticData_256[214],
	&EPL_LIAB::mCFStaticData_256[215],
	&EPL_LIAB::mCFStaticData_256[216],
	&EPL_LIAB::mCFStaticData_256[217],
	&EPL_LIAB::mCFStaticData_256[218],
	&EPL_LIAB::mCFStaticData_256[219],
	&EPL_LIAB::mCFStaticData_256[220],
	&EPL_LIAB::mCFStaticData_256[221],
	&EPL_LIAB::mCFStaticData_256[222],
	&EPL_LIAB::mCFStaticData_256[223],
	&EPL_LIAB::mCFStaticData_256[224],
	&EPL_LIAB::mCFStaticData_256[225],
	&EPL_LIAB::mCFStaticData_256[226],
	&EPL_LIAB::mCFStaticData_256[227],
	&EPL_LIAB::mCFStaticData_256[228],
	&EPL_LIAB::mCFStaticData_256[229],
	&EPL_LIAB::mCFStaticData_256[230],
	&EPL_LIAB::mCFStaticData_256[231],
	&EPL_LIAB::mCFStaticData_256[232],
	&EPL_LIAB::mCFStaticData_256[233],
	&EPL_LIAB::mCFStaticData_256[234],
	&EPL_LIAB::mCFStaticData_256[235],
	&EPL_LIAB::mCFStaticData_256[236],
	&EPL_LIAB::mCFStaticData_256[237],
	&EPL_LIAB::mCFStaticData_256[238],
	&EPL_LIAB::mCFStaticData_256[239],
	&EPL_LIAB::mCFStaticData_256[240],
	&EPL_LIAB::mCFStaticData_256[241],
	&EPL_LIAB::mCFStaticData_256[242],
	&EPL_LIAB::mCFStaticData_256[243],
	&EPL_LIAB::mCFStaticData_256[244],
	&EPL_LIAB::mCFStaticData_256[245],
	&EPL_LIAB::mCFStaticData_256[246],
	&EPL_LIAB::mCFStaticData_256[247],
	&EPL_LIAB::mCFStaticData_256[248],
	&EPL_LIAB::mCFStaticData_256[249],
	&EPL_LIAB::mCFStaticData_256[250],
	&EPL_LIAB::mCFStaticData_256[251],
	&EPL_LIAB::mCFStaticData_256[252],
	&EPL_LIAB::mCFStaticData_256[253],
	&EPL_LIAB::mCFStaticData_256[254],
	&EPL_LIAB::mCFStaticData_256[255],
	&EPL_LIAB::mCFStaticData_512[0],
	&EPL_LIAB::mCFStaticData_512[1],
	&EPL_LIAB::mCFStaticData_512[2],
	&EPL_LIAB::mCFStaticData_512[3],
	&EPL_LIAB::mCFStaticData_512[4],
	&EPL_LIAB::mCFStaticData_512[5],
	&EPL_LIAB::mCFStaticData_512[6],
	&EPL_LIAB::mCFStaticData_512[7],
	&EPL_LIAB::mCFStaticData_512[8],
	&EPL_LIAB::mCFStaticData_512[9],
	&EPL_LIAB::mCFStaticData_512[10],
	&EPL_LIAB::mCFStaticData_512[11],
	&EPL_LIAB::mCFStaticData_512[12],
	&EPL_LIAB::mCFStaticData_512[13],
	&EPL_LIAB::mCFStaticData_512[14],
	&EPL_LIAB::mCFStaticData_512[15],
	&EPL_LIAB::mCFStaticData_512[16],
	&EPL_LIAB::mCFStaticData_512[17],
	&EPL_LIAB::mCFStaticData_512[18],
	&EPL_LIAB::mCFStaticData_512[19],
	&EPL_LIAB::mCFStaticData_512[20],
	&EPL_LIAB::mCFStaticData_512[21],
	&EPL_LIAB::mCFStaticData_512[22],
	&EPL_LIAB::mCFStaticData_512[23],
	&EPL_LIAB::mCFStaticData_512[24],
	&EPL_LIAB::mCFStaticData_512[25],
	&EPL_LIAB::mCFStaticData_512[26],
	&EPL_LIAB::mCFStaticData_512[27],
	&EPL_LIAB::mCFStaticData_512[28],
	&EPL_LIAB::mCFStaticData_512[29],
	&EPL_LIAB::mCFStaticData_512[30],
	&EPL_LIAB::mCFStaticData_512[31],
	&EPL_LIAB::mCFStaticData_512[32],
	&EPL_LIAB::mCFStaticData_512[33],
	&EPL_LIAB::mCFStaticData_512[34],
	&EPL_LIAB::mCFStaticData_512[35],
	&EPL_LIAB::mCFStaticData_512[36],
	&EPL_LIAB::mCFStaticData_512[37],
	&EPL_LIAB::mCFStaticData_512[38],
	&EPL_LIAB::mCFStaticData_512[39],
	&EPL_LIAB::mCFStaticData_512[40],
	&EPL_LIAB::mCFStaticData_512[41],
	&EPL_LIAB::mCFStaticData_512[42],
	&EPL_LIAB::mCFStaticData_512[43],
	&EPL_LIAB::mCFStaticData_512[44],
	&EPL_LIAB::mCFStaticData_512[45],
	&EPL_LIAB::mCFStaticData_512[46],
	&EPL_LIAB::mCFStaticData_512[47],
	&EPL_LIAB::mCFStaticData_512[48],
	&EPL_LIAB::mCFStaticData_512[49],
	&EPL_LIAB::mCFStaticData_512[50],
	&EPL_LIAB::mCFStaticData_512[51],
	&EPL_LIAB::mCFStaticData_512[52],
	&EPL_LIAB::mCFStaticData_512[53],
	&EPL_LIAB::mCFStaticData_512[54],
	&EPL_LIAB::mCFStaticData_512[55],
	&EPL_LIAB::mCFStaticData_512[56],
	&EPL_LIAB::mCFStaticData_512[57],
	&EPL_LIAB::mCFStaticData_512[58],
	&EPL_LIAB::mCFStaticData_512[59],
	&EPL_LIAB::mCFStaticData_512[60],
	&EPL_LIAB::mCFStaticData_512[61],
	&EPL_LIAB::mCFStaticData_512[62],
	&EPL_LIAB::mCFStaticData_512[63],
	&EPL_LIAB::mCFStaticData_512[64],
	&EPL_LIAB::mCFStaticData_512[65],
	&EPL_LIAB::mCFStaticData_512[66],
	&EPL_LIAB::mCFStaticData_512[67],
	&EPL_LIAB::mCFStaticData_512[68],
	&EPL_LIAB::mCFStaticData_512[69],
	&EPL_LIAB::mCFStaticData_512[70],
	&EPL_LIAB::mCFStaticData_512[71],
	&EPL_LIAB::mCFStaticData_512[72],
	&EPL_LIAB::mCFStaticData_512[73],
	&EPL_LIAB::mCFStaticData_512[74],
	&EPL_LIAB::mCFStaticData_512[75],
	&EPL_LIAB::mCFStaticData_512[76],
	&EPL_LIAB::mCFStaticData_512[77],
	&EPL_LIAB::mCFStaticData_512[78],
	&EPL_LIAB::mCFStaticData_512[79],
	&EPL_LIAB::mCFStaticData_512[80],
	&EPL_LIAB::mCFStaticData_512[81],
	&EPL_LIAB::mCFStaticData_512[82],
	&EPL_LIAB::mCFStaticData_512[83],
	&EPL_LIAB::mCFStaticData_512[84],
	&EPL_LIAB::mCFStaticData_512[85],
	&EPL_LIAB::mCFStaticData_512[86],
	&EPL_LIAB::mCFStaticData_512[87],
	&EPL_LIAB::mCFStaticData_512[88],
	&EPL_LIAB::mCFStaticData_512[89],
	&EPL_LIAB::mCFStaticData_512[90],
	&EPL_LIAB::mCFStaticData_512[91],
	&EPL_LIAB::mCFStaticData_512[92],
	&EPL_LIAB::mCFStaticData_512[93],
	&EPL_LIAB::mCFStaticData_512[94],
	&EPL_LIAB::mCFStaticData_512[95],
	&EPL_LIAB::mCFStaticData_512[96],
	&EPL_LIAB::mCFStaticData_512[97],
	&EPL_LIAB::mCFStaticData_512[98],
	&EPL_LIAB::mCFStaticData_512[99],
	&EPL_LIAB::mCFStaticData_512[100],
	&EPL_LIAB::mCFStaticData_512[101],
	&EPL_LIAB::mCFStaticData_512[102],
	&EPL_LIAB::mCFStaticData_512[103],
	&EPL_LIAB::mCFStaticData_512[104],
	&EPL_LIAB::mCFStaticData_512[105],
	&EPL_LIAB::mCFStaticData_512[106],
	&EPL_LIAB::mCFStaticData_512[107],
	&EPL_LIAB::mCFStaticData_512[108],
	&EPL_LIAB::mCFStaticData_512[109],
	&EPL_LIAB::mCFStaticData_512[110],
	&EPL_LIAB::mCFStaticData_512[111],
	&EPL_LIAB::mCFStaticData_512[112],
	&EPL_LIAB::mCFStaticData_512[113],
	&EPL_LIAB::mCFStaticData_512[114],
	&EPL_LIAB::mCFStaticData_512[115],
	&EPL_LIAB::mCFStaticData_512[116],
	&EPL_LIAB::mCFStaticData_512[117],
	&EPL_LIAB::mCFStaticData_512[118],
	&EPL_LIAB::mCFStaticData_512[119],
	&EPL_LIAB::mCFStaticData_512[120],
	&EPL_LIAB::mCFStaticData_512[121],
	&EPL_LIAB::mCFStaticData_512[122],
	&EPL_LIAB::mCFStaticData_512[123],
	&EPL_LIAB::mCFStaticData_512[124],
	&EPL_LIAB::mCFStaticData_512[125],
	&EPL_LIAB::mCFStaticData_512[126],
	&EPL_LIAB::mCFStaticData_512[127],
	&EPL_LIAB::mCFStaticData_512[128],
	&EPL_LIAB::mCFStaticData_512[129],
	&EPL_LIAB::mCFStaticData_512[130],
	&EPL_LIAB::mCFStaticData_512[131],
	&EPL_LIAB::mCFStaticData_512[132],
	&EPL_LIAB::mCFStaticData_512[133],
	&EPL_LIAB::mCFStaticData_512[134],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for reins_defn                                                                                       
	const ChoicePair reins_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList reins_defnEnumList(2, reins_defnChoicePairs);

	// EnumList for use_mp                                                                                       
	const ChoicePair use_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_mpEnumList(2, use_mpChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace EPL_LIAB_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(EPL_LIAB::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(EPL_LIAB::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace EPL_LIAB_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void EPL_LIAB::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> EPL_LIAB::mgr_;

	Attribute::Descriptor EPL_LIAB::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STRING,	"epl_file", -1, (size_t)&modelOffset->epl_file,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STRING,	"gaap_cohort", -1, (size_t)&modelOffset->gaap_cohort,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STRING,	"loc_cohort", -1, (size_t)&modelOffset->loc_cohort,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::DOUBLE,	"pct_to_use_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pct_to_use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STR_ENUM,	"reins_defn", -1, (size_t)&modelOffset->reins_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_defnEnumList, Feature(true)),
	Descriptor(7, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(9, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPL_LIAB_UDF::epl_liab_commencement_period)),
	Descriptor(11, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPL_LIAB_UDF::epl_liab_maturity_period)),
	Descriptor(12, Attribute::SCALAR_INT,	"proj_date_offset", -1, (size_t)&modelOffset->proj_date_offset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPL_LIAB_UDF::epl_liab_proj_date_offset)),
	Descriptor(13, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPL_LIAB_UDF::epl_liab_reins_flag)),
	};

	Attribute::Descriptor* EPL_LIAB::descriptorTable[] = {
	&EPL_LIAB::descriptor_0[0],
	&EPL_LIAB::descriptor_0[1],
	&EPL_LIAB::descriptor_0[2],
	&EPL_LIAB::descriptor_0[3],
	&EPL_LIAB::descriptor_0[4],
	&EPL_LIAB::descriptor_0[5],
	&EPL_LIAB::descriptor_0[6],
	&EPL_LIAB::descriptor_0[7],
	&EPL_LIAB::descriptor_0[8],
	&EPL_LIAB::descriptor_0[9],
	&EPL_LIAB::descriptor_0[10],
	&EPL_LIAB::descriptor_0[11],
	&EPL_LIAB::descriptor_0[12],
	&EPL_LIAB::descriptor_0[13],
	nullptr};
	const size_t EPL_LIAB::sDescriptorCount = 14;

//factory
EPL_LIAB* EPL_LIAB::makeThis(int isSubmodel, ModelClass* owner, EPL_LIAB* peer, 
						int mainRebase, const xstring &name, EPL_LIAB_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EPL_LIAB::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EPL_LIAB");
#endif
	EPL_LIAB* newP = (EPL_LIAB*)new EPL_LIAB_UDF
   	  ("epl_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
EPL_LIAB_persistent_object* EPL_LIAB_persistent_object::makeThis(int isSubmodel, ModelClass* owner, EPL_LIAB* peer, 
							int mainRebase, const xstring &name, EPL_LIAB_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EPL_LIAB_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EPL_LIAB_persistent_object");
#endif
	EPL_LIAB_persistent_object* newP = (EPL_LIAB_persistent_object*)new EPL_LIAB_persistent_object
   	  ("epl_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			EPL_LIAB_persistent_object* pd = dynamic_cast<EPL_LIAB_persistent_object*>(product);
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

typedef double (EPL_LIAB_UDF::*dPF) ();
typedef double (EPL_LIAB_UDF::*dPFd) (double);
typedef int (EPL_LIAB_UDF::*iPF) ();
typedef int (EPL_LIAB_UDF::*iPFi) (int);
typedef xstring (EPL_LIAB_UDF::*sPF) ();
typedef xstring (EPL_LIAB_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
EPL_LIAB::EPL_LIAB(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, hedge_grp(company_seg_hedge_grp)
	, intex(company_asset_intex)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EPL_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
EPL_LIAB::EPL_LIAB(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(646, EPL_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, hedge_grp(company_seg_hedge_grp)
	, intex(company_asset_intex)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
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
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
       company_seg_hedge_grp = 0;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
       company_seg_sfas97rd = 0;
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

	for (int cf_no = 1; cf_no <= 646; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EPL_LIAB_UDF::*dPXi2) (int, int);
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


 void EPL_LIAB::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
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
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
		company_seg_hedge_grp = (HDG_GRP_COMP*)(findUnique("company|seg|hedge_grp"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
 }
//copy_names END@2


 void EPL_LIAB::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int EPL_LIAB_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& EPL_LIAB_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double EPL_LIAB_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int EPL_LIAB_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double EPL_LIAB_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double EPL_LIAB_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void EPL_LIAB_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPL_LIAB_persistent_object::write(long include_submodels) {
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

	void EPL_LIAB_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPL_LIAB_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPL_LIAB_persistent_object::write(const xstring& key, long include_submodels) {
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




	EPL_LIAB_persistent_object::~EPL_LIAB_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool EPL_LIAB_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void EPL_LIAB_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void EPL_LIAB_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void EPL_LIAB_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EPL_LIAB_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EPL_LIAB_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* EPL_LIAB_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* EPL_LIAB_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* EPL_LIAB_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char EPL_LIAB_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void EPL_LIAB_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
EPL_LIAB_persistent_object::EPL_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			EPL_LIAB(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(EPL_LIAB::sm_bond_is)
	, sm_bond_pv(EPL_LIAB::sm_bond_pv)
	, sm_bond_ym(EPL_LIAB::sm_bond_ym)
	, sm_mtg_is(EPL_LIAB::sm_mtg_is)
	, sm_mtg_pv(EPL_LIAB::sm_mtg_pv)
	, sm_mtg_ym(EPL_LIAB::sm_mtg_ym)

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
EPL_LIAB::~EPL_LIAB() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void EPL_LIAB::findTargetColumns() {

}
//findTargetColumns END@2
void EPL_LIAB::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void EPL_LIAB::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void EPL_LIAB::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void EPL_LIAB::start_of_projection() {
}
//start_of_projection END@2

void EPL_LIAB::end_of_projection() {
}
//end_of_projection END@2

void EPL_LIAB::start_of_layer() {
}


void EPL_LIAB::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void EPL_LIAB::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void EPL_LIAB::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void EPL_LIAB::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> EPL_LIAB::ddfVector;
BitArray EPL_LIAB::dataVariables(14);
bool EPL_LIAB::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool EPL_LIAB::writeClassInfo = true;

void EPL_LIAB::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, EPL_LIAB::descriptor_0>::dT = EPL_LIAB::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, EPL_LIAB::descriptor_0>::dT = EPL_LIAB::descriptor_0;

