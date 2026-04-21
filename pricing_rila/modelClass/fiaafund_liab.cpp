
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
#include "ModelClass\fiaafund_liab_udf.h"
#include "ModelClass\adco_asset.h"
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

extern SmartArray <SmartArray <double> > fia_caps_array(0);

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
#ifndef fiaafund_liab_TableDefs
#define fiaafund_liab_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection FIAAFUND_LIAB::TTHC;
void FIAAFUND_LIAB::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - admin_fee
// Administration Fee                                                                                             
// Column:ADMIN_FEE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_admin_fee(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"admin_fee",t);
}



//^^^

#line 1 "admin_fee.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (fia->pol_mth(t) != 1) 
	return 0.0;

if (fia->pol_yr(t) == 1 && fia->pol_mth(t) == 1)
	return 0.0;

double fund_val_b_bef_total = fia->fund_val_b_bef(t);

if (fabs(fund_val_b_bef_total) < model_point_amount_threshold)
	return NO_AVG;
	
return fia->admin_fee_per_pol 
       * fia->policies_b(t)
	   * (fund_val_b_bef(t) / fund_val_b_bef_total);

}


//@@ END

//@@ START - combo_strat_ind_par_rate_crbg
// Indicator par rate for the combo strategy                                                                                             
// Column:COMBO_STRAT_IND_PAR_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_combo_strat_ind_par_rate_crbg(int t) {
//^^^



//^^^

#line 1 "combo_strat_ind_par_rate_crbg.FIAAFUND_LIAB.for"
//20250124 MQ New column for combo strategy
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
xstring crediting_rate_type = fia->crediting_rate_type_aig;
if (crediting_rate_type != "Dynamic Par with Cap") 
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = 1; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_strategy_term = strategy_term_duration_aig;

fia->pol_yr_lookup_gen2 = 1; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_index_term = index_term_duration_aig;

fia->pol_yr_lookup_gen2 = 1;   
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_buffer = fia->index_term_buffer_aig;

double init_cap = init_fia_cap;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_part_rate_aig(t);

if (mod(t + elapsed_mths, init_strategy_term * 12) == 1)
{
	double long_call_option_cost, long_put_option_cost, short_call_option_cost, short_put_option_cost;

	double init_budget;
	if(valn_period != 0)
		init_budget = fia->init_hedge_budget;
	else
		init_budget = opt_budget_renewal_aig(commencement_period + 1);

	double tgt_budget	= opt_budget_tgt_calc_aig(t, init_budget, init_strategy_term, init_strategy_term);
	double option_budget	= opt_budget_renewal_calc_aig(t, init_budget, tgt_budget, init_strategy_term, init_strategy_term);

	long_call_option_cost	= get_option_price_aig(t - 1, 1, CALL, init_strategy_term * 12., init_index_term * 12.);
	short_put_option_cost	= get_option_price_aig(t - 1, 1 - init_buffer, PUT, init_strategy_term * 12., init_index_term * 12.);

	//20250812 MQ Revised option formula
	double solved_par = part_rate_solver_with_cap_crbg(t, option_budget, short_put_option_cost, long_call_option_cost, 
				init_cap, init_strategy_term * 12.);
	 
	return solved_par;	
}

return NO_AVG;

}


//@@ END

//@@ START - combo_strat_renew_status_crbg
// Status tracker for combo strategy                                                                                             
// Column:COMBO_STRAT_RENEW_STATUS_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_combo_strat_renew_status_crbg(int t) {
//^^^



//^^^

#line 1 "combo_strat_renew_status_crbg.FIAAFUND_LIAB.for"
//20250127 MQ new column for tracking the status of combo strategy
if (t < commencement_period || t > final_period || fia->crediting_type_dyn_2nd_strat_aig == "NA" || fia->valn_deterministic_flag_crbg)
{
	return NO_AVG;
}

if (t == 0 && valn_period == 0)
	return 0;

if (t == 0 && valn_period != 0)
	return fia->combo_strat_renew_status;

fia->pol_yr_lookup_gen2 = 1; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_strategy_term = strategy_term_duration_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
xstring crediting_rate_type = fia->crediting_rate_type_aig;
if (crediting_rate_type != "Dynamic Par with Cap" || t + elapsed_mths <= crediting_rate_guar_mths || fia->pol_yr(t) <= init_strategy_term)
{
	return NO_AVG;
}

if (combo_strat_renew_status_crbg(t - 1) == 1)
{
	return 1.;
}	

if (combo_strat_ind_par_rate_crbg(t) > 0 && combo_strat_ind_par_rate_crbg(t) < 1.)
{
	return 1.;
}

return 0.;





}


//@@ END

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"credited_int",t);
}



//^^^

#line 1 "credited_int.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return fund_val_b(t) * crediting_rate(t);



}


//@@ END

//@@ START - crediting_2nd_strat_buffer_cap_aig
// Crediting Buffer Cap                                                                                             
// Column:CREDITING_2ND_STRAT_BUFFER_CAP_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_2nd_strat_buffer_cap_aig(int t) {
//^^^



//^^^

#line 1 "crediting_2nd_strat_buffer_cap_aig.FIAAFUND_LIAB.for"
//20241029 New column for buffer cap rate with 2nd strategy
if (t < commencement_period || t > final_period || fia->crediting_type_dyn_2nd_strat_aig == "NA")
	return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (crediting_dyn_lever_local != "Dynamic Cap")
	return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double index_term = index_term_duration_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double cap_rate = fia->init_cap_rate_index0;

double initial_cap_cv = cap_rate;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return initial_cap_cv;

if (t == 0 && valn_period != 0)
	return fia->inner_buffer_cap_2nd_strat;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double	strategy_term = strategy_term_duration_aig;

if (mod(t + elapsed_mths,  strategy_term * 12) == 1)
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double buffer_amt = fia->index_term_buffer_aig;

	double long_call_option_cost, long_put_option_cost, short_call_option_cost, short_put_option_cost;

	double option_budget  =  opt_budget_renewal_2nd_strat_aig(t);

	long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_term * 12., index_term * 12.);
	short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term * 12., index_term * 12.);
	short_call_option_cost		= long_call_option_cost - short_put_option_cost - option_budget;

	double solved_cap = get_option_strike_aig(t - 1, short_call_option_cost, CALL, strategy_term * 12., index_term * 12.) - 1.;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_cap_minimum_cv = index_term_cap_rate_min_aig;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_cap_maximum_cv = index_term_cap_rate_max_aig;

	if ( fia->option_strike_annualization_aig == ANNUALIZED )
	{
		crediting_cap_minimum_cv *= index_term;
		crediting_cap_maximum_cv *= index_term;
	}
	   	
	solved_cap = max(min(crediting_cap_maximum_cv, solved_cap), crediting_cap_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		solved_cap = max(solved_cap, initial_cap_cv - max_sc_rate_decrease);
	}

	//apply rate change threshold and rate collar
	double prior_cap_rate = crediting_2nd_strat_buffer_cap_aig(t - 1);

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_rt_chg_threshold_local = crediting_rt_chg_threshold_aig;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double max_annual_rate_change_up_local = max_annual_rate_chg_up_aig;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double max_annual_rate_change_down_local = max_annual_rate_chg_down_aig;

	if ( abs(solved_cap - prior_cap_rate) < crediting_rt_chg_threshold_local)
	{
		return prior_cap_rate;
	}
	else if( solved_cap - prior_cap_rate > max_annual_rate_change_up_local)
	{
		return prior_cap_rate + max_annual_rate_change_up_local; 
	}
	else if( solved_cap - prior_cap_rate < - max_annual_rate_change_down_local)
	{
		return prior_cap_rate - max_annual_rate_change_down_local; 
	}
	else
	{
		return solved_cap;
	}
}

return crediting_2nd_strat_buffer_cap_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_2nd_strat_dual_dir_cap_aig
// Crediting Dual Direction Cap                                                                                             
// Column:CREDITING_2ND_STRAT_DUAL_DIR_CAP_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_2nd_strat_dual_dir_cap_aig(int t) {
//^^^



//^^^

#line 1 "crediting_2nd_strat_dual_dir_cap_aig.FIAAFUND_LIAB.for"
//20241029 New column for RILA dual direction cap as 2nd strategy
if (t < commencement_period || t > final_period || fia->crediting_type_dyn_2nd_strat_aig == "NA")
	return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (crediting_dyn_lever_local != "Dynamic DualDir Cap")
	return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double index_term = index_term_duration_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double cap_rate = fia->init_cap_rate_index0;

double initial_cap_cv = cap_rate;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return initial_cap_cv;

if (t == 0 && valn_period != 0)
	return fia->inner_dual_dir_cap_2nd_strat;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double	strategy_term = strategy_term_duration_aig;

if (mod(t + elapsed_mths, strategy_term * 12) == 1)
{				
	double binary_opt_value = 0.0;
	double solved_cap, short_otm_call;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double buffer_amt = fia->index_term_buffer_aig;
	
	if(pba_valn_flag)
	{
		//20240229 MQ New Black Scholes vol and binary option cost
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		xstring crediting_eqt_index_local = crediting_eqt_index;
		
		double vol_param, dividend_yld;
		fia->bs_init_vol_type = "base";
		fia->index_id_lookup = crediting_eqt_index_local;
		vol_param = fia->bs_fwrd_vol_aig;	

		fia->index_id_lookup = crediting_eqt_index_local;
		dividend_yld = exp(fia->dividend_inner_aig) - 1.;

		double rf_rate_cv = 0.0;
		if (fia->gen2_defn == YES)
		{
			rf_rate_cv  = fia_rates->get_int_rate(t - 1, "Govt", GET_YIELD_RATE, strategy_term, 0., NOMINAL_SEMIANNUAL, NO_SHIFT);
		}
		else
		{
			rf_rate_cv	= rates->get_int_rate(t - 1, "Govt", GET_YIELD_RATE, strategy_term, 0., NOMINAL_SEMIANNUAL, NO_SHIFT);
		}

		double put_k_pos = bs_opt_val(1 - buffer_amt + fia->binary_strike_sprd_pos, strategy_term, 1.0, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
		double put_k_neg = bs_opt_val(1 - buffer_amt - fia->binary_strike_sprd_neg, strategy_term, 1.0, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
		
		binary_opt_value = (put_k_pos - put_k_neg) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
		
		double long_call_option_cost	= get_option_price_aig(t - 1, 1, CALL, strategy_term * 12., index_term * 12.);
		double long_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_term * 12., index_term * 12.);	
		double short_put_option_cost	= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term * 12., index_term * 12.);

		short_otm_call = long_call_option_cost + long_put_option_cost - 2 * short_put_option_cost
							- opt_budget_renewal_2nd_strat_aig(t) - buffer_amt * binary_opt_value;		
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term * 12));
		int buffer_key = (1 - buffer_amt) * 100;
		string buffer_str = "_K" + to_string(buffer_key);
		
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + buffer_str;
		
		if (fia->gen2_defn == YES)
			binary_opt_value = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			binary_opt_value = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_atm_call	= get_option_price_aig(t - 1, 1, CALL, strategy_term * 12., index_term * 12.);
		double short_otm_put	= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term * 12., index_term * 12.);	
		double short_itm_call	= get_option_price_aig(t - 1, 1 - buffer_amt, CALL, strategy_term * 12., index_term * 12.);	
		
		short_otm_call = 2 * long_atm_call  - short_otm_put - short_itm_call 
							+ binary_opt_value * buffer_amt - opt_budget_renewal_2nd_strat_aig(t);

	}

	solved_cap = get_option_strike_aig(t - 1, short_otm_call, CALL, strategy_term * 12., index_term * 12.) - 1.;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_cap_minimum_cv = index_term_cap_rate_min_aig;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_cap_maximum_cv = index_term_cap_rate_max_aig;

	if ( fia->option_strike_annualization_aig == ANNUALIZED )
	{
		crediting_cap_minimum_cv *= index_term;
		crediting_cap_maximum_cv *= index_term;
	}
	   	
	solved_cap = max(min(crediting_cap_maximum_cv, solved_cap), crediting_cap_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		solved_cap = max(solved_cap, initial_cap_cv - max_sc_rate_decrease);
	}

	//apply rate threshold and rate collar
	double prior_cap_rate = crediting_2nd_strat_dual_dir_cap_aig(t - 1);

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double crediting_rt_chg_threshold_local = crediting_rt_chg_threshold_aig;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double max_annual_rate_change_up_local = max_annual_rate_chg_up_aig;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	double max_annual_rate_change_down_local = max_annual_rate_chg_down_aig;

	if ( abs(solved_cap - prior_cap_rate) < crediting_rt_chg_threshold_local)
	{
		return prior_cap_rate;
	}
	else if( solved_cap - prior_cap_rate > max_annual_rate_change_up_local)
	{
		return prior_cap_rate + max_annual_rate_change_up_local; 
	}
	else if( solved_cap - prior_cap_rate < - max_annual_rate_change_down_local)
	{
		return prior_cap_rate - max_annual_rate_change_down_local; 
	}
	else
	{
		return solved_cap;
	}
}

return crediting_2nd_strat_dual_dir_cap_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_cap_rate
// Crediting Cap Rate (Solved from Call Spread)                                                                                             
// Column:CREDITING_CAP_RATE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_cap_rate(int t) {
//^^^



//^^^

#line 1 "crediting_cap_rate.FIAAFUND_LIAB.for"
//20240201 Refactored this column
if (t < commencement_period || t > final_period)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); 

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //Renewing into 2nd strategy
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;

	if (crediting_dyn_lever_local == "Dynamic Cap")
		return crediting_2nd_strat_buffer_cap_aig(t);
}

//20250612 MQ Dual Direction Trigger Cap strategy
if (crediting_dyn_lever_local == "Dynamic DualDir Tri") 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
	return cap_rate_dualdir_tricap_crbg;
}

//20250124 MQ hold cap rate for combo strategy
if (crediting_dyn_lever_local == "Dynamic Par with Cap") 
	return init_cap_rate_aig(t);

if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
	return crediting_dual_dir_cap_aig(t);

if (crediting_dyn_lever_local == "Dynamic Secure Cap") // 20240311 MQ 
	return crediting_secure_cap_aig(t);

if (crediting_dyn_lever_local != "Dynamic Cap" && crediting_dyn_lever_local != "Dynamic Buffer"
	&& crediting_dyn_lever_local != "Dynamic Cap with Par")	// 20250804 MQ 
	return payout_index_max;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_cap_rate_aig(t);

if (t == 0 && valn_period != 0)
	return fia->inner_cap_rate;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	double buffer_amt = rila_buffer_amt_aig(t);
	double par_rate = crediting_part_rate_aig(t);
	double strategy_months = strategy_term_mths_aig(t);
	double index_months = index_term_mths_aig(t);
	double option_budget = opt_budget(t);

	double long_call_option_cost, long_put_option_cost, short_call_option_cost, short_put_option_cost, solved_cap;

	if (crediting_dyn_lever_local == "Dynamic Cap with Par") // 20250804 MQ Enhanced par cap
	{
		double atm_call = get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		double otm_put  = get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		double otm_call = atm_call - (option_budget + otm_put) / par_rate;

		solved_cap = get_option_strike_aig(t - 1, otm_call, CALL, strategy_months, index_months) - 1.;
		solved_cap *= par_rate;
	}
	else if (buffer_amt != 0)
	{
		//RILA Buffer Cap Strategy
		long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		short_call_option_cost		= long_call_option_cost - short_put_option_cost - option_budget;

		solved_cap = get_option_strike_aig(t - 1, short_call_option_cost, CALL, strategy_months, index_months) - 1.;
	}
	else
	{
		//RILA Floor Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double floor_amt = index_term_floor_aig;

		long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		long_put_option_cost		= get_option_price_aig(t - 1, 1 + floor_amt, PUT, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
		short_call_option_cost		= long_call_option_cost + long_put_option_cost - short_put_option_cost - opt_budget(t);
		
		solved_cap = get_option_strike_aig(t - 1, short_call_option_cost, CALL, strategy_months, index_months) - 1.;
	}

    double crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);
	double crediting_cap_maximum_cv	= index_term_cap_rate_max_col_aig(t);
	   	
	solved_cap = max(min(crediting_cap_maximum_cv, solved_cap), crediting_cap_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		solved_cap = max(solved_cap, init_cap_rate_aig(t) - max_sc_rate_decrease);
	}

	//20240730 MQ Add condition for maximuam annual rate change
	double prior_cap_rate = crediting_cap_rate(t - 1);

	if ( abs(solved_cap - prior_cap_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return prior_cap_rate;
	}
	else if( solved_cap - prior_cap_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_cap_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( solved_cap - prior_cap_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_cap_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return solved_cap;
	}
}

return crediting_cap_rate(t - 1);

	

}


//@@ END

//@@ START - crediting_dual_dir_cap_aig
// Crediting Dual Direction Cap                                                                                             
// Column:CREDITING_DUAL_DIR_CAP_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_dual_dir_cap_aig(int t) {
//^^^



//^^^

#line 1 "crediting_dual_dir_cap_aig.FIAAFUND_LIAB.for"
//20240124 New column for RILA dual direction cap strategy
if (t < commencement_period || t > final_period)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); 

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //Renewing into 2nd strategy
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;

	if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
		return crediting_2nd_strat_dual_dir_cap_aig(t);
}

if (crediting_dyn_lever_local != "Dynamic DualDir Cap")
	return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_cap_rate_aig(t);

if (t == 0 && valn_period != 0)
	return fia->inner_cap_rate;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{				
	double binary_opt_value = 0.0;
	double solved_cap, short_otm_call;
	double buffer_amt = rila_buffer_amt_aig(t);
	
	if(pba_valn_flag)
	{
		//20240923 Updated binary option formula
		double put_k_pos = get_option_price_aig(t - 1, 1 - buffer_amt + fia->binary_strike_sprd_pos, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double put_k_neg = get_option_price_aig(t - 1, 1 - buffer_amt - fia->binary_strike_sprd_neg, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
		
		binary_opt_value = (put_k_pos - put_k_neg) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
		
		double long_call_option_cost	= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double long_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));	
		double short_put_option_cost	= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));

		short_otm_call = long_call_option_cost + long_put_option_cost - 2 * short_put_option_cost
							- opt_budget(t) - buffer_amt * binary_opt_value;		
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
		int buffer_key = (1 - buffer_amt) * 100;
		string buffer_str = "_K" + to_string(buffer_key);
		
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + buffer_str;
		
		if (fia->gen2_defn == YES)
			binary_opt_value = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			binary_opt_value = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_atm_call	= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double short_otm_put	= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));	
		double short_itm_call	= get_option_price_aig(t - 1, 1 - buffer_amt, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));	
		
		short_otm_call = 2 * long_atm_call  - short_otm_put - short_itm_call + binary_opt_value * buffer_amt - opt_budget(t);

	}

	solved_cap = get_option_strike_aig(t - 1, short_otm_call, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) - 1.;

    double crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);
	double crediting_cap_maximum_cv	= index_term_cap_rate_max_col_aig(t);
	   	
	solved_cap = max(min(crediting_cap_maximum_cv, solved_cap), crediting_cap_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		solved_cap = max(solved_cap, init_cap_rate_aig(t) - max_sc_rate_decrease);
	}

	//20240730 MQ Add condition for maximuam annual rate change
	double prior_cap_rate = crediting_dual_dir_cap_aig(t - 1);

	if ( abs(solved_cap - prior_cap_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return crediting_dual_dir_cap_aig(t - 1);
	}
	else if( solved_cap - prior_cap_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_cap_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( solved_cap - prior_cap_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_cap_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return solved_cap;
	}
}

return crediting_dual_dir_cap_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_dual_dir_trigger_crbg
// Crediting Dual Direction Trigger                                                                                             
// Column:CREDITING_DUAL_DIR_TRIGGER_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_dual_dir_trigger_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_dual_dir_trigger_crbg.FIAAFUND_LIAB.for"
//20250612 New column for RILA dual direction trigger cap strategy
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) 
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;
}

//This strategy will not be renewed into.
if (crediting_dyn_lever_local != "Dynamic DualDir Tri")
	return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_trigger_rate_aig;

if (t == 0 && valn_period != 0)
	return fia->inner_trigger_rate;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{				
	double calc_trigger_rate = 0.0;
	double buffer_amt = rila_buffer_amt_aig(t);
	double cap_rate = crediting_cap_rate(t);
	
	if(pba_valn_flag)
	{
		double binary_strike_sprd = 0.01;
		double itm_binary_call = get_option_price_aig(t - 1, 1 - buffer_amt - binary_strike_sprd, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		itm_binary_call -= get_option_price_aig(t - 1, 1 - buffer_amt, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));	
		itm_binary_call /= binary_strike_sprd;		
			
		double otm_binary_call = get_option_price_aig(t - 1, 1 + buffer_amt - binary_strike_sprd, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		otm_binary_call -= get_option_price_aig(t - 1, 1 + buffer_amt, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		otm_binary_call /= binary_strike_sprd;
		
		double long_otm_call	= get_option_price_aig(t - 1, 1 + buffer_amt, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double short_otm_call	= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));	
		double short_otm_put	= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));

		calc_trigger_rate = (opt_budget(t) - buffer_amt * otm_binary_call - (long_otm_call - short_otm_call - short_otm_put)) /
						(itm_binary_call - otm_binary_call);		
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string crediting_strat_str = index_id_str + "_D" + to_string(int(strategy_term_mths_aig(t)));
		int itm_binary_key = xint((1 - buffer_amt) * 100);
		int otm_binary_key = xint((1 + buffer_amt) * 100);
		
		string itm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(itm_binary_key);
		string otm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(otm_binary_key);
		
		double itm_binary_call, otm_binary_call;
		if (fia->gen2_defn == YES)
		{
			itm_binary_call = fia_rates->get_misc_rate(t - 1, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = fia_rates->get_misc_rate(t - 1, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}
		else
		{
			itm_binary_call = rates->get_misc_rate(t - 1, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = rates->get_misc_rate(t - 1, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}

		double long_otm_call = get_option_price_aig(t - 1, 1 + buffer_amt, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double short_otm_call = get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		double short_otm_put = get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));	

		calc_trigger_rate = (opt_budget(t) - buffer_amt * otm_binary_call - (long_otm_call - short_otm_call - short_otm_put)) /
						(itm_binary_call - otm_binary_call);
	}

	//Apply min/max rate
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double max_trigger = index_term_trigger_rate_max_aig;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double min_trigger = index_term_trigger_rate_min_aig;
	   	
	calc_trigger_rate = max(min(max_trigger, calc_trigger_rate), min_trigger);

	//Apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		calc_trigger_rate = max(calc_trigger_rate, init_trigger_rate_aig - max_sc_rate_decrease);
	}

	//Add condition for maximuam annual rate change
	double prior_trigger_rate = crediting_dual_dir_trigger_crbg(t - 1);
	if ( abs(calc_trigger_rate - prior_trigger_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return prior_trigger_rate;
	}
	else if( calc_trigger_rate - prior_trigger_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_trigger_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( calc_trigger_rate - prior_trigger_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_trigger_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return calc_trigger_rate;
	}
}

return crediting_dual_dir_trigger_crbg(t - 1);

	

}


//@@ END

//@@ START - crediting_part_rate_aig
// Apply renewal strategy to par rate                                                                                             
// Column:CREDITING_PART_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate_aig(int t) {
//^^^



//^^^

#line 1 "crediting_part_rate_aig.FIAAFUND_LIAB.for"
//20240201 Refactored this column
if ((t < commencement_period || t > final_period) && valn_period == 0)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); 

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if(tier_number_aig(t) == 0 || EPS_defn == NOT_ENHANCED) //if not EPRS
{
	return crediting_part_rate_base_aig(t);			
}

if (t <= 0 && valn_period != 0)
	return fia->inner_par_up;

// 20220701 STW: initialize EPRS additional par rate
double eprs_add_par_rate_aig;
double final_par_rate;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
eprs_add_par_rate_aig = eprs_par_rate_aig;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue crediting_dyn_lever_local = crediting_dyn_lever;

if (t + elapsed_mths <= crediting_rate_guar_mths)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double eprs_index_term_part_rate_max_aig_cv = eprs_index_term_part_rate_max_aig;

	return min(init_part_rate_aig(t) + eprs_add_par_rate_aig, eprs_index_term_part_rate_max_aig_cv); 
}

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	// 20220701 STW: add the participation rate enhancement to the intermediate rate
	double solved_add_par_rate = opt_budget_eprs_aig(t) / opt_cost_atm_aig(t);

	// rounding
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	solved_add_par_rate = round(solved_add_par_rate / eprs_rounding_multiple_aig, 0) * eprs_rounding_multiple_aig;

	// min par rate		
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	if (solved_add_par_rate <= eprs_add_part_rate_min_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		solved_add_par_rate = eprs_add_part_rate_min_aig;    
	}	

	final_par_rate = crediting_part_rate_base_aig(t) + solved_add_par_rate;

	//new min for EPR total par rate
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	if(eprs_add_par_rate_aig > SMALL_DOUBLE || solved_add_par_rate > SMALL_DOUBLE)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		if (final_par_rate >= eprs_index_term_part_rate_max_aig)
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			return eprs_index_term_part_rate_max_aig;	
		}
			
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		if (final_par_rate <= eprs_hedge_min_par_aig)
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			return eprs_hedge_min_par_aig;	
		}
	}


	return final_par_rate;

}

return crediting_part_rate_aig(t - 1);

}


//@@ END

//@@ START - crediting_part_rate_base_aig
// crediting par rate before addtional par rate from fee4rate/ fee plus                                                                                             
// Column:CREDITING_PART_RATE_BASE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate_base_aig(int t) {
//^^^



//^^^

#line 1 "crediting_part_rate_base_aig.FIAAFUND_LIAB.for"
//20240201 Refactored this column
if (t < commencement_period || t > final_period)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); 

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;
}

//20250804 MQ hold par rate for enhanced par cap strategy
if (crediting_dyn_lever_local == "Dynamic Cap with Par") 
{
	return init_part_rate_aig(t);
}

if (crediting_dyn_lever_local != "Dynamic Participation and Spread" && crediting_dyn_lever_local != "Dynamic Participation" 
		&& crediting_dyn_lever_local != "Dynamic Par with Cap") //ZL 20240516: update and refactor if statement logic
{
	return 1.0;
}

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_part_rate_aig(t);

if (t == 0 && valn_period != 0)
	return fia->inner_par_up;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	double buffer_amt = rila_buffer_amt_aig(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double par_down = fia->part_down_amt;;

	double part_rate;
	double strategy_months = strategy_term_mths_aig(t);
	double index_months = index_term_mths_aig(t);

	if ( crediting_dyn_lever_local == "Dynamic Participation and Spread" ) 
	{
		double spread_rate;
		joint_part_sprd_rate_solver_aig(t, part_rate, spread_rate);
	}
	else
	{
		double long_call_option_cost = get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		double short_put_option_cost, short_call_option_cost;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double rila_ind = fia->rila_ind;	

		if(long_call_option_cost > SMALL_DOUBLE)
		{
			if(buffer_amt != 0 && rila_ind)
			{
				short_put_option_cost = get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);

				if (crediting_dyn_lever_local == "Dynamic Par with Cap")
				{
					//20250812 MQ Revised option formula
					part_rate = part_rate_solver_with_cap_crbg(t, opt_budget(t), short_put_option_cost, long_call_option_cost,
								crediting_cap_rate(t), strategy_months);
				}
				else
				{
					part_rate = (opt_budget(t) + short_put_option_cost) / long_call_option_cost;
				}
			}
			else if(buffer_amt == 0 && rila_ind)
			{
				short_put_option_cost = par_down * get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
				part_rate = (opt_budget(t) + short_put_option_cost) / long_call_option_cost;	
			}
			else
			{
				part_rate = opt_budget(t) / long_call_option_cost;
			}
		}
		else
		{
			part_rate = index_term_part_rate_max_col_aig(t);
		}
	}

    double crediting_part_minimum_cv = index_term_part_rate_min_col_aig(t);
	double crediting_part_maximum_cv = index_term_part_rate_max_col_aig(t);
	   	
	part_rate = max(min(crediting_part_maximum_cv, part_rate), crediting_part_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		part_rate = max(part_rate, init_part_rate_aig(t - 1) - max_sc_rate_decrease);
	}

	//20240730 MQ Add condition for maximuam annual rate change
	double prior_part_rate = crediting_part_rate_base_aig(t - 1);

	if ( abs(part_rate - prior_part_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return prior_part_rate;
	}
	else if( part_rate - prior_part_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_part_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( part_rate - prior_part_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_part_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return part_rate;
	}
}

return crediting_part_rate_base_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_pri_sprd_aig
// Crediting Pricing Spread                                                                                             
// Column:CREDITING_PRI_SPRD_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_pri_sprd_aig(int t) {
//^^^



//^^^

#line 1 "crediting_pri_sprd_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (abs(strategy_term_elapsed_mths_eom_aig(t) - 1) < SMALL_DOUBLE)
{
	double option_cost_cv;
	
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if ( crediting_rate_defn == FIXED_RATE )
	{
		option_cost_cv = crediting_rate_fix(t);
	}
	else if (t + elapsed_mths == 1)
	{
		option_cost_cv = opt_budget(t);
	}
	else
	{
		option_cost_cv = opt_budget_cost_aig(t);
	}
	
	double ner_cv;
	if (t == commencement_period + 1)
	{
		ner_cv = fia->crediting_ner_aig / (1.0 + fia->crediting_ner_aig);
	}
	//20220519 STW：use asset yld including duration weighted adj for rate setting
	else if(!isMainModel && alm_flag)
	{
		ner_cv = fia->asset_yld_inv_adj_aig(t - 1) / (1 + fia->asset_yld_inv_adj_aig(t - 1));
	}
	else
	{
		ner_cv = fia->asset_yld_inv(t - 1) / (1 + fia->asset_yld_inv(t - 1));
	}			
	
	if (abs(strategy_term_aig(t)) < SMALL_DOUBLE)
	{
		xstring err_msg = "fiaafund_liab->crediting_pri_sprd_aig: division by zero!";
		throw FatalError(err_msg);
	}

	double annualized_option_cost_cv	= option_cost_cv / strategy_term_aig(t);
	double pri_sprd						= ner_cv - annualized_option_cost_cv;

	return pri_sprd;
}

double pri_sprd = crediting_pri_sprd_aig(t - 1);
return pri_sprd;
 


}


//@@ END

//@@ START - crediting_rate
// Monthly Crediting Rate                                                                                             
// Column:CREDITING_RATE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"crediting_rate",t);
}



//^^^

#line 1 "crediting_rate.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (sfas97rd_valn_flag)
{
	#if defined(__SEG_COMP_H_)
		return convert_rate_basis(fia->gaap_int_rate, EFFECTIVE_ANNUAL, - 12);
	#endif
		return convert_rate_basis(fia->gaap_int_rate_input, EFFECTIVE_ANNUAL, - 12);
}

//20250407 MQ deterministic
if (fia->valn_deterministic_flag_crbg)
{
	if ( strategy_term_elapsed_mths_eom_aig(t) == strategy_term_aig(t) * 12 )
		return opt_budget(t);
	else
		return 0.;
}


crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

index_val(t);

// MQIN 20220616: force call columns related to option cost and hedge cash flow
opt_budget_cost_aig(t);

if(t > commencement_period + 1 && !fia->valn_deterministic_flag_crbg) 
{
	hedge_cash_flow(t - 1);
}
// MQIN END 20220616

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

double crediting_rate = 0.0;
if (rila_ind)
{
	crediting_rate = rila_interim_value_growth_aig(t);

	return crediting_rate;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if ( crediting_rate_defn != FIXED_RATE )
{
	const int MONTHS_IN_YEAR = 12;
	if ( strategy_term_elapsed_mths_eom_aig(t) == strategy_term_aig(t) * MONTHS_IN_YEAR ) // 20190613 DTL: replacing `strategy_term_duration_aig` with `strategy_term_aig(t)`
	{
		crediting_rate = strategy_return_aig(t);
	}
	else
	{
		crediting_rate = 0.0;
	}
}
else
{
	//crediting_rate_defn == Fixed_Rate
	crediting_rate = strategy_return_aig(t);
}

return crediting_rate;


 

}


//@@ END

//@@ START - crediting_rate_chg_threshold_aig
// rate change threshold                                                                                             
// Column:CREDITING_RATE_CHG_THRESHOLD_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_chg_threshold_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_chg_threshold_aig.FIAAFUND_LIAB.for"
//20240215 Add new column as rate change threshold might change after strategy switching
if (t <= commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double crediting_rt_chg_threshold_local = crediting_rt_chg_threshold_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	crediting_rt_chg_threshold_local = crediting_rt_chg_threshold_aig;
}

return crediting_rt_chg_threshold_local;

}


//@@ END

//@@ START - crediting_rate_cumul_aig
// Cumulative crediting rate                                                                                             
// Column:CREDITING_RATE_CUMUL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_cumul_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_cumul_aig.FIAAFUND_LIAB.for"
/*
	Weighted sum refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if ((mod(t + elapsed_mths, strategy_term_mths_aig(t))) == 0)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (crediting_rate_defn == FIXED_RATE)
	{
		return crediting_rate_fix_cumul_aig(t);
	}
	else
	{
		return crediting_rate(t);
	}
}
else
{
	return 0.0;
}


}


//@@ END

//@@ START - crediting_rate_fix
// Fixed Crediting Rate For Fund Value                                                                                             
// Column:CREDITING_RATE_FIX
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_fix(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"crediting_rate_fix",t);
}



//^^^

#line 1 "crediting_rate_fix.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn != FIXED_RATE) // 20240311 MQ 
	return NO_AVG;

if (t == 0 && valn_period != 0)
	return fia->inner_fixed_rate;

double growth_rate = 0.0;

// 20180109 MTC - Added new option budget fixed account growth rate
fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double crediting_rate_fixed_local = fia->crediting_rate_fixed;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double crediting_rate_min_local = fia->crediting_rate_min;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (fia->crediting_fixed_defn_aig == DEFAULT)
{
	double book_rate = 0.0;
	double spread = fia->crediting_asset_yld_sprd;
	double maturity = fia->crediting_nb_yld_maturity;

	if ((!nb_flag && t + mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) - strategy_term_mths_aig(t) /*crediting_mths*/ <= 0) // 20190613 DTL: replaced `crediting_mths`
		 || (nb_flag && fia->crediting_nb_defn == USER_INPUT 
			 && t + mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) - strategy_term_mths_aig(t) /*crediting_mths*/ <= 0)) // 20190613 DTL: replaced `crediting_mths`
		{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		growth_rate = max(crediting_rate_min_local, crediting_rate_fixed_local);//WTW - Gen2 - Mutating Lookup Term used in expression

		return growth_rate;
		}
	else if (fia->crediting_nb_defn == PROXY_YIELD 
			 && t == commencement_period + 1)
		{
			if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
				book_rate = fia_rates->get_int_rate(t - 1, 
									  fia->crediting_nb_yld_rating, 
									  GET_YIELD_RATE,
									  maturity,
									  0.0,
									  EFFECTIVE_ANNUAL,
									  NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			else
				book_rate = rates->get_int_rate(t - 1, 
									  fia->crediting_nb_yld_rating, 
									  GET_YIELD_RATE,
									  maturity,
									  0.0,
									  EFFECTIVE_ANNUAL,
									  NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		growth_rate = max(fia->crediting_rate_min, max(book_rate - spread, 0.0)); 

		return growth_rate;		
		}
	
	 if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/ ) == 1  // 20190613 DTL: replacing `crediting_mths`
 		 && t + elapsed_mths > crediting_rate_guar_mths)
		{
		book_rate = fia->asset_yld_less_dflt_inv(t);
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		growth_rate = max(fia->crediting_rate_min, max(book_rate - spread, 0.0)); 
   
		return growth_rate;
		}
}
else //WTW - Gen2 - Mutating Lookup Term - rewrite else if{} to be else {if ()...}
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (fia->crediting_fixed_defn_aig == OPTION_BUDGET)
	{
		if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1) // 20190613 DTL: replacing `crediting_mths`
		{
			if (t + elapsed_mths <= crediting_rate_guar_mths)
			{
				// Use initial crediting rate during guarantee period
				growth_rate = fia->init_crediting_rate_fixed_aig;

				return growth_rate;
			}
			else
			{
				// Out of guarantee period, use option budget
				growth_rate = opt_budget(t);
			}

			// 20190307 MTC - Apply floor to growth rate
			double prior_fix_rate = crediting_rate_fix(t - 1);

			// 20190826 DTL (START): I took this code as is from the IA pricing team.
			//                       The change amounts to adding a switch between old and
			//                       new logic
			fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - crediting_rate_min cannot use time based lookup in an external formula
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			growth_rate = max(growth_rate, fia->crediting_rate_min);

			// Check if rate change exceeds threshold
			if ( abs(growth_rate - prior_fix_rate) < crediting_rate_chg_threshold_aig(t) )
			{
				return prior_fix_rate;
			}
			//20240730 MQ Add condition for maximuam annual rate change
			else if( growth_rate - prior_fix_rate > crediting_rate_max_annual_chg_up_aig(t))
			{
				return prior_fix_rate + crediting_rate_max_annual_chg_up_aig(t); 
			}
			else if( growth_rate - prior_fix_rate < - crediting_rate_max_annual_chg_down_aig(t))
			{
				return prior_fix_rate - crediting_rate_max_annual_chg_down_aig(t); 
			}
			else
			{
				return growth_rate;
			}
			// 20190826 DTL (END)
		}
	}
	else
	{
		throw FatalError("Unhandled fia->crediting_fixed_defn_aig requested in fiaafund_liab->crediting_rate_fix!");
	}
}
	
return crediting_rate_fix(t - 1);

}


//@@ END

//@@ START - crediting_rate_fix_cumul_aig
// Cumulative fixed crediting rate                                                                                             
// Column:CREDITING_RATE_FIX_CUMUL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_fix_cumul_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_fix_cumul_aig.FIAAFUND_LIAB.for"
// 20180109 MTC - Track cumulative fixed account growth rate
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue crediting_rate_defn_local = crediting_rate_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if ( (t <= commencement_period || t > maturity_period) || (crediting_rate_defn_local != FIXED_RATE) )//WTW - Gen2 - Mutating Lookup Term used in expression
{
	return NO_AVG;
}

double crediting_rate_fix_cumul;
double crediting_rate = pow(1.0 + crediting_rate_fix(t), 1.0 / 12.0) - 1.0;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1) // 20190613 DTL: replaced `crediting_mths`
{
	crediting_rate_fix_cumul = crediting_rate;
}
else
{
	double prior_cumul_fix_rate = crediting_rate_fix_cumul_aig(t - 1);
	crediting_rate_fix_cumul = (1.0 + prior_cumul_fix_rate) * (1.0 + crediting_rate) - 1.0;
}

return crediting_rate_fix_cumul;

}


//@@ END

//@@ START - crediting_rate_max_annual_chg_down_aig
// rate change maximum                                                                                             
// Column:CREDITING_RATE_MAX_ANNUAL_CHG_DOWN_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_max_annual_chg_down_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_max_annual_chg_down_aig.FIAAFUND_LIAB.for"
//20240808 MQ: New column for maximum annual change for renewal rate - rate goes down
if (t <= commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double max_annual_rate_change_local = max_annual_rate_chg_down_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	max_annual_rate_change_local = max_annual_rate_chg_down_aig;
}

return max_annual_rate_change_local;

}


//@@ END

//@@ START - crediting_rate_max_annual_chg_up_aig
// rate change maximum                                                                                             
// Column:CREDITING_RATE_MAX_ANNUAL_CHG_UP_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_max_annual_chg_up_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_max_annual_chg_up_aig.FIAAFUND_LIAB.for"
//20240730 MQ: New column for maximum annual change for renewal rate - rate goes up
if (t <= commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double max_annual_rate_change_local = max_annual_rate_chg_up_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	max_annual_rate_change_local = max_annual_rate_chg_up_aig;	
}

return max_annual_rate_change_local;

}


//@@ END

//@@ START - crediting_secure_cap_aig
// Crediting Secure Cap                                                                                             
// Column:CREDITING_SECURE_CAP_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_secure_cap_aig(int t) {
//^^^



//^^^

#line 1 "crediting_secure_cap_aig.FIAAFUND_LIAB.for"
//20240325 New column for RILA Secure cap strategy
if (t < commencement_period || t > final_period)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); 

double buffer_amt = rila_buffer_amt_aig(t);

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;
}

if (crediting_dyn_lever_local != "Dynamic Secure Cap")
	return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_cap_rate_aig(t);

if (t == 0 && valn_period != 0)
	return fia->inner_cap_rate;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	double solved_cap;
	if(pba_valn_flag)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		xstring crediting_eqt_index_local = crediting_eqt_index;
		
		double vol_param, dividend_yld;
		fia->bs_init_vol_type = "base";
		fia->index_id_lookup = crediting_eqt_index_local;
		vol_param = fia->bs_fwrd_vol_aig;

		fia->index_id_lookup = crediting_eqt_index_local;
		dividend_yld = exp(fia->dividend_inner_aig) - 1.;

		double rf_rate_cv = rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, strategy_term_aig(t), 0., NOMINAL_SEMIANNUAL, NO_SHIFT);	
		double price_zcb = 1 / pow(1 + rf_rate_cv / 2., strategy_term_aig(t) * 2.);

		solved_cap = get_secure_cap_rate_aig(buffer_amt, strategy_term_aig(t), price_zcb, vol_param, rf_rate_cv, dividend_yld, opt_budget(t));
	}
	else
	{
		double cliquet_opt_cost = opt_budget(t);

		solved_cap = get_option_strike_aig(t - 1, cliquet_opt_cost, CSEC, strategy_term_mths_aig(t), index_term_mths_aig(t)) - 1.;
	}

    double crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);
	double crediting_cap_maximum_cv	= index_term_cap_rate_max_col_aig(t);
	   	
	solved_cap = max(min(crediting_cap_maximum_cv, solved_cap), crediting_cap_minimum_cv);

	//apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		solved_cap = max(solved_cap, init_cap_rate_aig(t) - max_sc_rate_decrease);
	}

	//20240730 MQ Add condition for maximuam annual rate change
	double prior_cap_rate = crediting_secure_cap_aig(t - 1);

	if ( abs(solved_cap - prior_cap_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return crediting_secure_cap_aig(t - 1);
	}
	else if( solved_cap - prior_cap_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_cap_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( solved_cap - prior_cap_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_cap_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return solved_cap;
	}
}

return crediting_secure_cap_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_spread_rate_aig
// Crediting Spread Rate:                                                                                             
// Column:CREDITING_SPREAD_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_spread_rate_aig(int t) {
//^^^



//^^^

#line 1 "crediting_spread_rate_aig.FIAAFUND_LIAB.for"
// 20190918 DTL: adding a new column to hold the spread used in the index account credit

if (t < commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == FIXED_RATE)
{
    return NO_AVG;
}

if (t == 0 && valn_period != 0)
{
	return index_term_init_spread_rate_aig(t); // DTL 20200109: TFS 86561
}
if (t + mod(t + elapsed_mths, strategy_term_mths_aig(t)) - strategy_term_mths_aig(t) <= 0)
{
	return index_term_init_spread_rate_aig(t); // DTL 20200109: TFS 86561
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

if ( crediting_dyn_lever == DYNAMIC_SPREAD || crediting_dyn_lever == DYNAMIC_PARTICIPATION_AND_SPREAD )//WTW - Gen2 - character input that varies by time
{
	if (
			( mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1 && t + elapsed_mths > crediting_rate_guar_mths ) || 
			( fia->crediting_nb_defn == PROXY_YIELD && t == commencement_period + 1 )
	   )
	{	
		double prior_sprd_rate = crediting_spread_rate_aig(t - 1);
		double solved_sprd_rate;
		
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		if ( crediting_dyn_lever == DYNAMIC_SPREAD )//WTW - Gen2 - character input that varies by time
		{
			solved_sprd_rate = spread_solver_point_to_point_aig(t);
		}
		else if ( crediting_dyn_lever == DYNAMIC_PARTICIPATION_AND_SPREAD )//WTW - Gen2 - character input that varies by time
		{
			double solved_part_rate;
			joint_part_sprd_rate_solver_aig(t, solved_part_rate, solved_sprd_rate);
		} 

		if (
				fia->opt_budget_defn_aig == RENEWAL_2020 // 20200402 JYR
		   )
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			if ( abs(solved_sprd_rate - prior_sprd_rate) > crediting_rate_chg_threshold_aig(t) )
			{
				return solved_sprd_rate;
			}
			else
			{
				return prior_sprd_rate;
			}
		}
		else
		{
			if (fia->gen2_defn == NO)
				makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported
			log_screen << "Warning: opt_budget_defn_aig is not set to Renewal_2020. Please check product assumption workbook." << MSG_ERROR;
		}
	}	
}

return crediting_spread_rate_aig(t - 1);

}


//@@ END

//@@ START - crediting_trigger_rate_aig
// Crediting Trigger Rate Aig                                                                                             
// Column:CREDITING_TRIGGER_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_trigger_rate_aig(int t) {
//^^^



//^^^

#line 1 "crediting_trigger_rate_aig.FIAAFUND_LIAB.for"
//20230105 SJ: add new column to track crediting trigger rate.
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t); //Force call trigger eval to switch crediting_type_dyn_aig

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

//strategy switching doesn't apply to trigger strategy

if (crediting_dyn_lever_local == "Dynamic DualDir Tri")
	return crediting_dual_dir_trigger_crbg(t);

if (crediting_dyn_lever_local != "Dynamic Trigger")
	return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths)
	return init_trigger_rate_aig;

if (t == 0 && valn_period != 0)
	return fia->inner_trigger_rate;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
	string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
				
	string rate_lookup 
		= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
	double binary_opt_value = 0.0;
	if (fia->gen2_defn == YES)
		binary_opt_value = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
	else
		binary_opt_value = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		
	// 20240212 MQ New logic for RILA buffer/trigger strategy
	if(pba_valn_flag)
	{
		//20240229 MQ New Black Scholes vol and binary option cost
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		xstring crediting_eqt_index_local = crediting_eqt_index;
		
		double vol_param, dividend_yld;
		fia->bs_init_vol_type = "base";
		fia->index_id_lookup = crediting_eqt_index_local;
		vol_param = fia->bs_fwrd_vol_aig;

		fia->index_id_lookup = crediting_eqt_index_local;
		dividend_yld = exp(fia->dividend_inner_aig) - 1.;

		double rf_rate_cv = 0.0;
		if (fia->gen2_defn == YES)
		{
			rf_rate_cv  = fia_rates->get_int_rate(t - 1, "Govt", GET_YIELD_RATE, strategy_term_aig(t), 0., NOMINAL_SEMIANNUAL, NO_SHIFT);
		}
		else
		{
			rf_rate_cv	= rates->get_int_rate(t - 1, "Govt", GET_YIELD_RATE, strategy_term_aig(t), 0., NOMINAL_SEMIANNUAL, NO_SHIFT);
		}

		//20240923 Updated binary option formula
		double call_k_pos = bs_opt_val(1. + fia->binary_strike_sprd_pos, strategy_term_aig(t), 1.0, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		double call_k_neg = bs_opt_val(1. - fia->binary_strike_sprd_neg, strategy_term_aig(t), 1.0, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);

		binary_opt_value = (call_k_neg - call_k_pos) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
	}

	double calc_trigger_rate = 0.;
	
	if(binary_opt_value > SMALL_DOUBLE)
	{
		calc_trigger_rate =	opt_budget(t) / binary_opt_value;
	}

	double buffer_amt = rila_buffer_amt_aig(t);

	if (buffer_amt != 0)
	{
		double short_put_option_cost = 0.0;
		short_put_option_cost = get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));

		calc_trigger_rate = (opt_budget(t) + short_put_option_cost) / binary_opt_value;
	}

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double index_term_trigger_rate_max_cv = index_term_trigger_rate_max_aig;

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double index_term_trigger_rate_min_cv = index_term_trigger_rate_min_aig;
	   	
	double adj_trigger_rate = max(min(index_term_trigger_rate_max_cv, calc_trigger_rate), index_term_trigger_rate_min_cv);
	double prior_trigger_rate = crediting_trigger_rate_aig(t - 1);

	//20240212 MQ apply maximum decrease in rates over the surrender charge period
	if(fia->pol_yr(t) <= fia->surr_chg_period_aig)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double max_sc_rate_decrease = max_sc_rate_decrease_aig;
		adj_trigger_rate = max(adj_trigger_rate, init_trigger_rate_aig - max_sc_rate_decrease);
	}

	//20240730 MQ Add condition for maximuam annual rate change
	if ( abs(adj_trigger_rate - prior_trigger_rate) < crediting_rate_chg_threshold_aig(t) )
	{
		return prior_trigger_rate;
	}
	else if( adj_trigger_rate - prior_trigger_rate > crediting_rate_max_annual_chg_up_aig(t))
	{
		return prior_trigger_rate + crediting_rate_max_annual_chg_up_aig(t); 
	}
	else if( adj_trigger_rate - prior_trigger_rate < - crediting_rate_max_annual_chg_down_aig(t))
	{
		return prior_trigger_rate - crediting_rate_max_annual_chg_down_aig(t); 
	}
	else
	{
		return adj_trigger_rate;
	}
}

return crediting_trigger_rate_aig(t - 1);

	

}


//@@ END

//@@ START - crediting_type_dyn_trigger_aig
// Flag to indicate a dynamic change to the crediting type:                                                                                             
// Column:CREDITING_TYPE_DYN_TRIGGER_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_type_dyn_trigger_aig(int t) {
//^^^



//^^^

#line 1 "crediting_type_dyn_trigger_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 20190613 DTL.
 
 Adding this column.  Flag to indicate we have hit a dynamic strategy
 term switch and deviating from the scheduled strategy term.

 20220616 MQIN.
 Revised to allow more dynamic switching types.

 *****************************************************************************/
if (
	 t < commencement_period		|| 
	 t > final_period/*maturity_period*/			||
	 fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_OFF
   )
{
	return 0.0;
}
else if ( t <= commencement_period + 1 )
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	fia->crediting_type_dyn_aig = fia->crediting_type_aig;
	fia->set_fia_account_vars();

	return 0.0;
}
else
{
	double strategy_term_mth = strategy_term_aig(max(0, t - 1)) * 12;
	if ( strategy_term_elapsed_mths_eom_aig(max(0, t - 1)) == strategy_term_mth )
	{
		if ((t == strategy_term_mth + 1)
			&& (fia->crediting_type_dyn_2nd_strat_aig != "NA"))
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			fia->crediting_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
			fia->set_fia_account_vars();
			
			return crediting_type_dyn_trigger_aig(max(0, t - 1)) + 1.0;
		}

		else
		{
			return crediting_type_dyn_trigger_aig(max(0, t - 1));
		}
	
	}

	return crediting_type_dyn_trigger_aig(max(0, t - 1));

}

}


//@@ END

//@@ START - crediting_type_dyn_zero_threshold_flag_aig
// flag for first year after dynamic switch                                                                                             
// Column:CREDITING_TYPE_DYN_ZERO_THRESHOLD_FLAG_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_type_dyn_zero_threshold_flag_aig(int t) {
//^^^



//^^^

#line 1 "crediting_type_dyn_zero_threshold_flag_aig.FIAAFUND_LIAB.for"
//20220822 JYL: new column to flag the first year after dynamic switching
if (
	 t <= commencement_period + 1		|| 
	 t > final_period/*maturity_period*/			||
	 fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_OFF
   )
{
	return 0.0;
}
else
{
	if(crediting_type_dyn_trigger_aig(t) == crediting_type_dyn_trigger_aig(t - 12) + 1)//first year upon switching
	{
		return 1.0;
	}

	return 0.0;
}

}


//@@ END

//@@ START - eprs_cost_rate_aig
// cost percentage of EPRS features                                                                                             
// Column:EPRS_COST_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_cost_rate_aig(int t) {
//^^^



//^^^

#line 1 "eprs_cost_rate_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
if (t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - refined time guards
{
	return NO_AVG;
}

if(tier_number_aig(t) == 1)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	return eprs_cost_aig;
}
else if(tier_number_aig(t) == 0)
{
	return 0;
}
else
{
	throw FatalError("Tier number is other than 0 or 1. The model could not determine EPRS cost for other tiers at eprs_cost_rate_aig (fiaafund_liab).");
}


}


//@@ END

//@@ START - fund_released_ann
// Fund Released on Annuitization                                                                                             
// Column:FUND_RELEASED_ANN
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_ann(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"fund_released_ann",t);
}



//^^^

#line 1 "fund_released_ann.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return fund_val_e_bef(t)
       * (1.0 - fia->dth_claim_rate_mthly(t))
       * fia->annuitzn_rate_mthly(t);

}


//@@ END

//@@ START - fund_released_dth
// Fund Released on Death                                                                                             
// Column:FUND_RELEASED_DTH
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_dth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"fund_released_dth",t);
}



//^^^

#line 1 "fund_released_dth.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

// 20180919 MTC - Zero out death benefits in primary tail
if (fia->dth_ben_primary_tail_defn_aig == NO && t > fia->primary_tail_period_aig)
{
	return 0.0;
}
//20180919 MTC END

return fund_val_e_bef(t) * fia->dth_claim_rate_mthly(t);

}


//@@ END

//@@ START - fund_released_maturity
// Fund Released on Maturity                                                                                             
// Column:FUND_RELEASED_MATURITY
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"fund_released_maturity",t);
}



//^^^

#line 1 "fund_released_maturity.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (t != fia->maturity_benefits_period_aig) // 20180918 MTC - Fixed trigger to sync fund release and maturity benefit
{
	return 0.0;
}

double fund_val_e_bef_cv        = fund_val_e_bef(t);
double fund_released_dth_cv     = fund_released_dth(t);
double fund_released_surr_cv    = fund_released_surr(t);
double fund_released_ann_cv     = fund_released_ann(t);
double fund_released_withdrl_cv = fund_released_withdrl(t);

double fund_released_maturity_cv =	fund_val_e_bef_cv - fund_released_dth_cv
	- fund_released_surr_cv - fund_released_ann_cv - fund_released_withdrl_cv;

return fund_released_maturity_cv;


}


//@@ END

//@@ START - fund_released_surr
// Fund Released on Surrender                                                                                             
// Column:FUND_RELEASED_SURR
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_surr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"fund_released_surr",t);
}



//^^^

#line 1 "fund_released_surr.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

// 20180919 MTC - Zero out surrender benefits in primary tail
if (fia->surr_ben_primary_tail_defn_aig == NO && t > fia->primary_tail_period_aig)
{
	return 0.0;
}
//20180919 MTC END

return fund_val_e_bef(t) 
  	 * (1.0 - fia->dth_claim_rate_mthly(t))
       * fia->lapse_rate_mthly(t);

}


//@@ END

//@@ START - fund_released_withdrl
// Fund Released on Withdrawal                                                                                             
// Column:FUND_RELEASED_WITHDRL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_withdrl(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"fund_released_withdrl",t);
}



//^^^

#line 1 "fund_released_withdrl.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

// net withdrawal amt...
double fund_released_withdrls_cv;

if (fia->fund_val_b_bef(t) < model_point_amount_threshold)
{
	fund_released_withdrls_cv = 0.0;
}
else
{
	double total_fund_pct = fund_val_b_bef(t) / fia->fund_val_b_bef(t);
	fund_released_withdrls_cv 
		//20220701 STW: Withdrawal Benefit Adjustment 
		//= max(pfwd_surr_fund_val(t), fia->pfwd_surr_contract_val(t) * total_fund_pct);
		= pfwd_surr_fund_val(t);
}

// 20200603 DTL: NYIA
if (fia->fund_val_defn_aig == EIV)
{
	double mav_e_bef_cv      = min_accum_val_e_bef_aig(t);
	double fund_val_e_bef_cv = fund_val_e_bef(t);

	if (mav_e_bef_cv > fund_val_e_bef_cv)
	{
		double surv_period_cv     = fia->surv_period(t);
		double fund_val_e_cv      = fund_val_e_bef_cv * surv_period_cv;
		double fund_release_rate  = fia->pfwd_rate_mthly_min_accum_val_aig(t);

		fund_released_withdrls_cv = fund_val_e_cv * fund_release_rate;
	}
}
// 20200603 DTL: NYIA

return fund_released_withdrls_cv;

}


//@@ END

//@@ START - fund_val_b
// Fund Value After Outflow - BOM                                                                                             
// Column:FUND_VAL_B
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"fund_val_b",t);
}



//^^^

#line 1 "fund_val_b.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period + 1/*maturity_period*/)
	return NO_AVG;

// 20220701 STW: deduct strategy fee and add rop benefit
return fund_val_b_bef(t)
	   - admin_fee(t)
	   - gmwb_chg(t)
	   - fia->rop_chg_aig(t)
	   - tier_strat_fee_aig(t)	
	   + fia->sfc_ben_aig(t);

}


//@@ END

//@@ START - fund_val_b_bef
// Fund Value Before Outflow BOM                                                                                             
// Column:FUND_VAL_B_BEF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"fund_val_b_bef",t);
}



//^^^

#line 1 "fund_val_b_bef.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period + 1/*maturity_period*/)
{
	return NO_AVG;
}

double fund_val_e_prev   = fund_val_e(t - 1);
double fund_val_rebal_cv = fund_val_rebal(t);
double prem_alloc_cv     = prem_alloc(t);
double fund_val_b_bef_cv = fund_val_e_prev + fund_val_rebal_cv + prem_alloc_cv;

// 20200603 DTL: added NYIA logic
double pol_yr_cv  = fia->pol_yr(t);
double pol_mth_cv = fia->pol_mth(t);

if (  fia->fund_val_defn_aig == EIV && 
      fia->min_accum_val_activation_period_yrs_ny_aig < pol_yr_cv && 
	  fund_val_b_bef_cv > SMALL_DOUBLE &&
	  pol_mth_cv == 1.0
   )
{
	double mav_b_bef_cv = min_accum_val_e_aig(t - 1);
	fund_val_b_bef_cv = max(mav_b_bef_cv, fund_val_b_bef_cv);
}
// 20200603 DTL: added NYIA logic

return fund_val_b_bef_cv;

}


//@@ END

//@@ START - fund_val_decrem
// Fund Value Decrement Amount                                                                                             
// Column:FUND_VAL_DECREM
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_decrem(int t) {
//^^^



//^^^

#line 1 "fund_val_decrem.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression

return (fund_released_dth(t)
	    + fund_released_surr(t)
	    + fund_released_ann(t)
	    + fund_released_withdrl(t)
	    + fund_released_maturity(t)
	    + admin_fee(t)
	    + gmwb_chg(t))
	   * pct_to_hedge_local;//WTW - Gen2 - Mutating Lookup Term used in expression

}


//@@ END

//@@ START - fund_val_e
// Fund Value End of Month                                                                                             
// Column:FUND_VAL_E
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e(int t) {
//^^^



//^^^

#line 1 "fund_val_e.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

// Set Fund Value at start of projection to amount specified in data file.
if (t == commencement_period)
{
	if (elapsed_mths > 0)
	{
		return init_fund_val;
	}

	return 0.0;
}

//opt_value_net_numer(t);//force calling

double fund_released_dth_cv      = fund_released_dth(t);
double fund_released_surr_cv     = fund_released_surr(t);
double fund_released_ann_cv      = fund_released_ann(t);
double fund_released_withdrl_cv  = fund_released_withdrl(t);
double fund_released_maturity_cv = fund_released_maturity(t);

double fund_val_e_bef_cv         = fund_val_e_bef(t);

double claims_av = fund_released_dth_cv + fund_released_surr_cv
	+ fund_released_ann_cv + fund_released_withdrl_cv + fund_released_maturity_cv;

double fund_val_aft_claims = fund_val_e_bef_cv - claims_av;
if (fund_val_aft_claims < model_point_amount_threshold)
{
	return 0.0;
}

return fund_val_aft_claims;
// 20180910 MTC END

}


//@@ END

//@@ START - fund_val_e_bef
// Fund Value Before Outflow EOM                                                                                             
// Column:FUND_VAL_E_BEF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"fund_val_e_bef",t);
}



//^^^

#line 1 "fund_val_e_bef.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return fund_val_b(t) + credited_int(t);  

}


//@@ END

//@@ START - fund_val_e_bef_maturity_aig
// Fund Value End of Month, before maturity                                                                                             
// Column:FUND_VAL_E_BEF_MATURITY_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef_maturity_aig(int t) {
//^^^



//^^^

#line 1 "fund_val_e_bef_maturity_aig.FIAAFUND_LIAB.for"
// 20190411 MTC - Create time slice right before maturity
if (t != fia->maturity_benefits_period_aig)
	return NO_AVG;

// Set Fund Value at start of projection to amount specified in data file.
if (t == commencement_period)
	{
	if (elapsed_mths > 0)
		return init_fund_val;

	return 0.0;
	}

//opt_value_net_numer(t);//force calling

double claims_av = 0.0;
double claims_av_bef_maturity = 0.0;

claims_av_bef_maturity = fund_released_dth(t)
			+ fund_released_surr(t)
			+ fund_released_ann(t)
			+ fund_released_withdrl(t);

if (fund_val_e_bef(t) - claims_av_bef_maturity < model_point_amount_threshold)
	return 0.0;

return fund_val_e_bef(t) - claims_av_bef_maturity;
// 20180910 MTC END

}


//@@ END

//@@ START - fund_val_rebal
// Rebalancing Transfer to Account                                                                                             
// Column:FUND_VAL_REBAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"fund_val_rebal",t);
}



//^^^

#line 1 "fund_val_rebal.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (fia->fund_val_rebal_defn == DRIFT)
	return NO_AVG;

int rebal_mths = 12;//by default annually

if (fia->fund_val_rebal_freq_defn == SEMI_ANNUAL)
	rebal_mths = 6;

if (fia->fund_val_rebal_freq_defn == QUARTERLY)
	rebal_mths = 3;

if (fia->fund_val_rebal_freq_defn == MONTHLY)
	rebal_mths = 1;

// Only rebalance at intervals determined by the variable av_rebal_freq.
if (mod(xint(fia->pol_mth(t)) - 1, rebal_mths) != 0)
		return 0.0;

double fund_val_total = fia->fund_val_fixed(max(commencement_period, t - 1));

return (fund_val_split_prop * fund_val_total) - fund_val_e(max(commencement_period, t - 1));

}


//@@ END

//@@ START - fund_weighted_crediting_pri_sprd_aig
// Fund value * pricing spread:                                                                                             
// Column:FUND_WEIGHTED_CREDITING_PRI_SPRD_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_weighted_crediting_pri_sprd_aig(int t) {
//^^^



//^^^

#line 1 "fund_weighted_crediting_pri_sprd_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double fund_val_b_cv = fund_val_b(t);
double pricing_sprd  = crediting_pri_sprd_aig(t);
double weighted_sprd = fund_val_b_cv * pricing_sprd;

return weighted_sprd;

}


//@@ END

//@@ START - gmwb_chg
// GMWB Charge                                                                                             
// Column:GMWB_CHG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"gmwb_chg",t);
}



//^^^

#line 1 "gmwb_chg.FIAAFUND_LIAB.for"
/*
	Refactored to use xint. MCHING 9-6-2021
*/

if (/*!fia->gmwb_flag ||*/ t <= commencement_period || t > final_period + 1/*maturity_period*/)//WTW - Gen2 - move non-time guard below
{
	return NO_AVG;
}

if (!fia->gmwb_flag)
	return NO_AVG;

int pol_yr = xint(fia->pol_yr(t));
int pol_mth = xint(fia->pol_mth(t));

if (pol_yr == 1 && pol_mth == 1)
{ // charges are in arrears regardless of frequency
	return 0.0;
}
if (fund_val_b_bef(t) < model_point_amount_threshold)
{
	return 0.0;
}

double chg_base_mult	= 0.0;
if (fia->fund_val_defn_aig == EIV)
{ // we cannot reference `gmwb_inf_bef` when running NYIA: we have an issue with timing that needs to be fixed
	return 0.0;
}
double gmwb_inf_cv		= fia->gmwb_inf_bef(t);

if (fia->gmwb_chg_base == FUND_VALUE)
{
	chg_base_mult = 1.0;
}
else if (fia->gmwb_chg_base == GMWB_BASE)
{
	chg_base_mult = gmwb_inf_cv / fia->fund_val_b_bef(t);
}
else //"MAX"
{
	chg_base_mult = max(1.0, gmwb_inf_cv / fia->fund_val_b_bef(t));
}

double av_b_bef_gmwb_chg = fund_val_b_bef(t) - admin_fee(t);
double gmwb_chg_pct = fia->gmwb_chg_pct;

if ( xint(fia->gmwb_withdrl_rate_indexing_assessment_stepup_ind_b_aig(t)) &&
     pol_yr > fia->gmwb_req_yrs_wait + xint(fia->gmwb_exercise_yrs_aig(t) + 1))
{
	gmwb_chg_pct += fia->gmwb_withdrl_rate_indexing_assessment_chg_addn_aig;
}

// Refactored to use xint. MCHING 9-6-2021
double gmwb_chg_amt = 0.0;

if (fia->gmwb_chg_freq_aig == ANNUALLY)
{
	if (pol_mth == 1)
	{
		gmwb_chg_amt = ((fund_val_b_bef(t) - admin_fee(t)) * chg_base_mult) * (gmwb_chg_pct / fia->gmwb_chg_freq_per_yr_aig);
	}
}
else if (fia->gmwb_chg_freq_aig == QUARTERLY)
{
	if ( pol_mth == 1 || 
	     pol_mth == 4 || 
		 pol_mth == 7 || 
		 pol_mth == 10)
	{
		gmwb_chg_amt = ((fund_val_b_bef(t) - admin_fee(t)) * chg_base_mult) * (gmwb_chg_pct / fia->gmwb_chg_freq_per_yr_aig);
	}
}
else
{
	xstring err_msg = "fiaafund_liab->gmwb_chg(t): unhandled GLB charge frequency!  (See fia->gmwb_chg_freq_aig.)";
	throw FatalError(err_msg);
}
// END MCHING 9-6-2021

if (fia->pfwd_partial_interest_credited_aig == YES)
{
	double partial_interest_credit_rate = (1.0 + fia->weighted_strategy_return_aig(t - 1)) / (1.0 + fia->weighted_ending_strategy_return_aig(t - 1));
	gmwb_chg_amt /= partial_interest_credit_rate;
}

gmwb_chg_amt = min(max(av_b_bef_gmwb_chg, 0.0), gmwb_chg_amt);

return gmwb_chg_amt;

}


//@@ END

//@@ START - gmwb_chg_at_surr_aig
// GMWB Charge At Surrender For Inforce End of Month                                                                                             
// Column:GMWB_CHG_AT_SURR_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_at_surr_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"gmwb_chg_at_surr_aig",t);
}



//^^^

#line 1 "gmwb_chg_at_surr_aig.FIAAFUND_LIAB.for"
//20180831 LZ - GMWB fee at surrender for inforce end of month after claims
if (/*!fia->gmwb_flag || fia->gmwb_chg_at_surr_yn_aig == NO || */t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - move non-time guard below
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_chg_at_surr_yn_aig == NO)
	return NO_AVG;

if (fund_val_e(t) < model_point_amount_threshold)
	return 0.0;

double chg_base_mult = 0.0;
if (fia->gmwb_chg_base == FUND_VALUE)
{
	chg_base_mult = 1.0;
}
else if (fia->gmwb_chg_base == GMWB_BASE)
{
	chg_base_mult = fia->gmwb_inf(t) / fia->fund_val_fixed(t);
}
else if (fia->gmwb_chg_base == MAX_AMOUNT)
{
	chg_base_mult = max(1.0, fia->gmwb_inf(t) / fia->fund_val_fixed(t)); 
}
else
{	// 20210723 STW : Added error branch
	throw FatalError("fiaafund_liab->gmwb_chg_at_surr_aig : invalid `fia->gmwb_chg_base` value.");
}

return min(
		  max(fund_val_e(t) - admin_fee(t), 0.0),
          fia->gmwb_chg_pct * (fund_val_e(t) - admin_fee(t))* chg_base_mult * fia->pol_mth(t) / 12
		  );

}


//@@ END

//@@ START - gmwb_chg_at_surr_bef_aig
// GMWB Charge At Surrender For Inforce End of Month Before Claims                                                                                             
// Column:GMWB_CHG_AT_SURR_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_at_surr_bef_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"gmwb_chg_at_surr_bef_aig",t);
}



//^^^

#line 1 "gmwb_chg_at_surr_bef_aig.FIAAFUND_LIAB.for"
//20180831 LZ - GMWB fee at surrender for inforce end of month before claims
if (/*!fia->gmwb_flag || fia->gmwb_chg_at_surr_yn_aig == NO || */t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - move non-time guard below
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_chg_at_surr_yn_aig == NO)
	return NO_AVG;

if (fund_val_e_bef(t) < model_point_amount_threshold)
	return 0.0;

double chg_base_mult = 0.0;
if (fia->gmwb_chg_base == FUND_VALUE)
{
	chg_base_mult = 1.0;
}
else if (fia->gmwb_chg_base == GMWB_BASE)
{
	chg_base_mult = fia->gmwb_inf_bef(t) / fia->fund_val_e_bef(t);
}
else if (fia->gmwb_chg_base == MAX_AMOUNT)
{
	chg_base_mult = max(1.0, fia->gmwb_inf_bef(t) / fia->fund_val_e_bef(t)); 
}
else
{	// 20210723 STW : Added error branch
	throw FatalError("fiaafund_liab->gmwb_chg_at_surr_bef_aig : invalid `fia->gmwb_chg_base` value.");
}

return min(
		  max(fund_val_e_bef(t) - admin_fee(t), 0.0),
          fia->gmwb_chg_pct * (fund_val_e_bef(t) - admin_fee(t)) * chg_base_mult * fia->pol_mth(t) / 12
		  );

}


//@@ END

//@@ START - gmwb_income_base_credit_rate_protation_fct_at_wdl_aig
// A per account proration factor for use in mid-crediting period partial crediting:                                                                                             
// Column:GMWB_INCOME_BASE_CREDIT_RATE_PROTATION_FCT_AT_WDL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_at_wdl_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_credit_rate_protation_fct_at_wdl_aig.FIAAFUND_LIAB.for"
/******************************************************************************
 * 20190710 DTL
 *
 * A proration factor for use in adjusting mid- and end-term GMWB income 
 * credits.
 *
 * This should more or less be the percentage of the strategy term that has
 * already elapsed at the point in which the first GLB income withdrawal is
 * taken, and one minus that number else.
 *
 * (I more or less took this implementation from an IA pricing team  
 * research model provided by YH; it seems to work.)
 *****************************************************************************/
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

const int MONTHS_PER_YEAR = 12;
const int ONE_MONTH = 1;
int glb_income_start_month = (fia->gmwb_req_yrs_wait + xint(fia->gmwb_exercise_yrs_aig(t))) * MONTHS_PER_YEAR + ONE_MONTH;  // 20200303 MTC - Confinement rider, dynamic exercise

double proration_factor = 1.0;
if ( strategy_term_elapsed_mths_eom_aig(t) == 1 )
{
	proration_factor = 1.0;

	if ( t == glb_income_start_month )
	{
		proration_factor = strategy_term_elapsed_pct_eom_aig(t);
	}	
}
else
{
	if ( t == glb_income_start_month )
	{
		proration_factor = strategy_term_elapsed_pct_eom_aig(t);
	}
	else
	{
		proration_factor = gmwb_income_base_credit_rate_protation_fct_at_wdl_aig(t - 1);
	}
}

return proration_factor;

}


//@@ END

//@@ START - gmwb_income_base_credit_rate_protation_fct_e_aig
// Proration factor for GMWB partial income crediting, End of Month:                                                                                             
// Column:GMWB_INCOME_BASE_CREDIT_RATE_PROTATION_FCT_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_credit_rate_protation_fct_e_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return 1.0;
}

const int MONTHS_PER_YEAR = 12;
const int ONE_MONTH = 1;
int glb_income_start_month = (fia->gmwb_req_yrs_wait + xint(fia->gmwb_exercise_yrs_aig(t))) * MONTHS_PER_YEAR + ONE_MONTH;

// Daily Contract Return refactor.  MCHING 9-3-2021
double proration_factor;

if (t == glb_income_start_month)
{
	proration_factor = 1.0 - strategy_term_elapsed_pct_eom_aig(t);  // Set at start of income
}
else
{
	proration_factor = gmwb_income_base_credit_rate_protation_fct_e_bef_aig(t);
}
// END MCHING 9-3-2021

return proration_factor;


}


//@@ END

//@@ START - gmwb_income_base_credit_rate_protation_fct_e_bef_aig
// Proration factor for GMWB partial income crediting, End of Month Before Claims:                                                                                             
// Column:GMWB_INCOME_BASE_CREDIT_RATE_PROTATION_FCT_E_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_credit_rate_protation_fct_e_bef_aig.FIAAFUND_LIAB.for"
/*
	New column for Daily Contract Return refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return 1.0;
}

double proration_factor;

if (strategy_term_elapsed_mths_eom_aig(t) == 1)
{
	proration_factor = 1.0;  // Reset at start of new strategy term
}
else
{
	proration_factor = gmwb_income_base_credit_rate_protation_fct_e_aig(t - 1);  // Roll forward
}

return proration_factor;


}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flows                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

double hedge_inv = hedge_inv_amt_bom(t);
double trading_cost = hedge_rila_trading_cost_aig(t);
double hedge_payoff = opt_payoff_aig(t); // 20200622 STW: change to call another column

double hedge_sales = hedge_sale_amt_bom(t)
                     + hedge_sale_amt_eom(t);

return - hedge_inv
       - trading_cost
       + hedge_payoff
	   + hedge_sales;


}


//@@ END

//@@ START - hedge_inv_amt_bom
// Hedge Investment Amount BOM                                                                                             
// Column:HEDGE_INV_AMT_BOM
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_inv_amt_bom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_bom.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) != 1)// 20190613 DTL: replaced `crediting_mths`
	return NO_AVG;

// force calls to opt_budget and opt_budget_amt
opt_budget(t);
opt_budget_amt(t);

double yrs_to_expiry = strategy_term_aig(t); /*crediting_mths / 12.0;*/  // 20190613 DTL: replaced `crediting_mths`
double underlying_bom = index_val_bom(t);
double notional_to_purch = notional_to_hedge_net(t);
double index_units_owned = 1.0;
double long_strike = opt_strike_price(t);
double short_strike = index_val_bom(t) * (1.0 + crediting_cap_rate(t));
	
fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_dyn_lever != DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time	
	short_strike = payout_index_max;

double mkt_val_per_unit;
if (use_option_cost_tables_defn_aig == NO)
{
	if ( crediting_rate_defn == POINT_TO_POINT	||
		 crediting_rate_defn == MOVING_AVERAGE     )
	{
		index_units_owned = 1.0 / index_val_bom(t);
	}
		
	mkt_val_per_unit 
		= mkt_val_calc(t - 1,
			xint(fia->cal_yr_relative(t - 1)),
			xint(fia->cal_mth(t - 1)),
			lookback_defn,
			lookback_mths,
			lookback_sampling_mths,
			index_units_owned, 
			underlying_bom,
			index_scen_mult,
			index_scen_sprd_addn,
			yrs_to_expiry,
			div_yld_scen_mult,
			div_yld_sprd,
			long_strike,
			short_strike,
			crediting_cap_rate(t),
			CALL, //opt_defn
			0.0, // spot_sprd_adj,
			0.0, // volatility_sprd_adj,
			NO_SHIFT); // shift_defn 
}
else
{
	// 20200622 STW: use option cost for hedge investment calculation
	mkt_val_per_unit = opt_budget_cost_aig(t);
}


double inv_amt 
= notional_to_purch
  * mkt_val_per_unit;

return inv_amt;

}


//@@ END

//@@ START - hedge_mkt_val
// Market Value of Hedges                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0)// 20190613 DTL: replaced `crediting_mths`
	return 0.0;

if (rila_perf_lock_status_bom_aig(t) == 0 && rila_perf_lock_status_eom_aig(t) == 1) 
	return 0.0;

return notional_amt_required(t)
       * hedge_mkt_val_per_unit_notional(t);

}


//@@ END

//@@ START - hedge_mkt_val_aig
// Hedge Market Value:                                                                                             
// Column:HEDGE_MKT_VAL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_aig(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_aig.FIAAFUND_LIAB.for"
// 20181017 DTL : Added column
// 20240207 Comment: This column is not being used. 
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

else
{
	double hedge_cost = 0.0;
	if ( strategy_term_elapsed_mths_eom_aig(t) == 1 )
	{
		hedge_cost = notional_to_hedge_aig(t) * hedge_mkt_val_per_unit_notional_aig(t);
	}

	return hedge_cost;
}



}


//@@ END

//@@ START - hedge_mkt_val_growth
// Hedge Market Value Growth                                                                                             
// Column:HEDGE_MKT_VAL_GROWTH
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_growth(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_growth.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;


if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1)// 20190613 DTL: replaced `crediting_mths`
	return hedge_mkt_val_per_unit_notional(t)
	       * notional_to_hedge_net(t)
		   - hedge_inv_amt_bom(t)
		   - hedge_rila_trading_cost_aig(t); //20240529 MQ rila trading cost

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0)// 20190613 DTL: replaced `crediting_mths`
	return opt_payoff(t)
	       - hedge_mkt_val(t - 1);

if (rila_perf_lock_status_bom_aig(t) == 0 && rila_perf_lock_status_eom_aig(t) == 1) 
	return - hedge_mkt_val(t - 1);

return hedge_mkt_val_per_unit_notional(t)
       * notional_amt_required(t - 1)
	   - hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - hedge_mkt_val_per_unit_notional
// Hedge Market Value Per Unit Notional                                                                                             
// Column:HEDGE_MKT_VAL_PER_UNIT_NOTIONAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_per_unit_notional(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_per_unit_notional.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - time guards
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)//WTW - Gen2 - Mutating Lookup Term used in expression
{
	return NO_AVG;
}

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0) // 20190613 DTL: replaced `crediting_mths`
{
	return 0.0;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;
if (rila_ind) 
{
	if (t == 0 && valn_period != 0)
	{
		return fia->init_hedge_opt_cost;
	}
	else if(!valn_flag)
	{
			return rila_opt_cost_by_grid_e_aig(t);
	}			
	else
	{
		//rila_opt_cost_bs_e_aig is calculated before evaluating knockout_status_eom.
		if(rila_knockout_status_eom_aig(t) == 1)
			return 0.;
		else
			return rila_opt_cost_bs_e_aig(t);
	}
}

double mkt_val_per_unit_notional = 0.0;

int mths_since_crediting_start = xint(mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/));// 20190613 DTL: replaced `crediting_mths`
double yrs_to_expiry = (strategy_term_mths_aig(t) /*crediting_mths*/ - mths_since_crediting_start) / 12.0;// 20190613 DTL: replaced `crediting_mths`
double underlying = index_val(t);
double index_units_owned = 1.0;
double index_val_at_crediting_start = 0.0;
double long_strike = 0.0;
double short_strike = 0.0;

if (elapsed_mths > 0 && t <  mths_since_crediting_start)
{
	index_val_at_crediting_start = index_val_calc(t - mths_since_crediting_start);
	long_strike = index_val_at_crediting_start * pow(1.0 + strategy_term_floor_col_aig(t), strategy_term_aig(t) /*crediting_mths / 12.0*/); // DTL 20180919 : Replaced `crediting_floor` with `strategy_term_floor_aig` and replaced `crediting_mths`
}
else
{
	index_val_at_crediting_start = index_val_bom(t + 1 - mths_since_crediting_start);
	long_strike = opt_strike_price(t + 1 - mths_since_crediting_start);
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if ( crediting_rate_defn == POINT_TO_POINT	||
	 crediting_rate_defn == MOVING_AVERAGE    )
{
	index_units_owned /= index_val_at_crediting_start;
	short_strike = index_val_at_crediting_start * (1.0 + crediting_cap_rate(t));

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

	if (crediting_dyn_lever != DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time	
	{
		short_strike = payout_index_max;
	}
}

if (use_option_cost_tables_defn_aig == NO)
{
	mkt_val_per_unit_notional 
		= mkt_val_calc(t,
			xint(fia->cal_yr_relative(t)),
			xint(fia->cal_mth(t)),
			lookback_defn,
			lookback_mths,
			lookback_sampling_mths,
			index_units_owned, 
			underlying,
			index_scen_mult,
			index_scen_sprd_addn,
			yrs_to_expiry,
			div_yld_scen_mult,
			div_yld_sprd,
			long_strike,
			short_strike,
			crediting_cap_rate(t),
			CALL, //opt_defn
			0.0, // spot_sprd_adj,
			0.0, // volatility_sprd_adj,
			NO_SHIFT); // shift_defn 

			/*log_screen<<"t= "<<t
			<<" index_units_owned= "<<index_units_owned
			<<" underlying= "<<underlying
			<<" yrs_to_expiry= "<<yrs_to_expiry
			<<" long_strike= "<<long_strike
			<<" short_strike= "<<short_strike
			<<" crediting_cap_rate(t)= "<<crediting_cap_rate(t)
			<<" mkt_val_per_unit_notional= "<<mkt_val_per_unit_notional
			<<MSG_USER;*/
}
else
{
	// 20200622 STW: change option market value calculation
	// Refactored MRM market value estimate.  MCHING 9-2-2021
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; //WTW - Gen2  - Mutating Lookup Term
	if ( crediting_rate_defn == "Fixed Rate" )
	{
		return 0.0;
	}

	double strategy_term_elapsed_mths		= strategy_term_elapsed_mths_eom_aig(t);
	double strategy_term_start_mth			= t - strategy_term_elapsed_mths + 1.0;

	double strategy_term_length_mths		= strategy_term_mths_aig(t);
	double strategy_term_end_mth			= strategy_term_start_mth + strategy_term_length_mths - 1.0;

	mkt_val_per_unit_notional = opt_mkt_val_estimate_aig(
		t,
		max(strategy_return_index_aig(t), 0.0),
		opt_budget_cost_aig(t),
		strategy_term_start_mth,
		strategy_term_end_mth
	);

	// END MCHING 9-2-2021
}

return mkt_val_per_unit_notional;







}


//@@ END

//@@ START - hedge_mkt_val_per_unit_notional_aig
// Hedge Market Value Per Unit Notional:                                                                                             
// Column:HEDGE_MKT_VAL_PER_UNIT_NOTIONAL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_per_unit_notional_aig(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_per_unit_notional_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)// MQIN 20220616: changed to avoid returning value when t=0
	return NO_AVG;

// Added additional guards to prevent running under Gen2.  MCHING 2-9-2022
if (
	   !(
			strategy_term_elapsed_mths_eom_aig(t) == 1 || 
			(
				fia->lapse_dyn_base_prod_defn_aig == IA &&
				(
					( fia->lapse_dyn_surr_chg_period_defn_aig == NO && fia->pol_yr(t) > fia->surr_chg_period_aig ) ||
					( fia->lapse_dyn_surr_chg_period_defn_aig == YES )
				)
			)
		)
)
{
	return NO_AVG;
}

crediting_type_dyn_trigger_aig(t);

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue crediting_dyn_lever_local = crediting_dyn_lever;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue crediting_rate_defn_local = crediting_rate_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

if (rila_ind && !valn_flag)
{
	return rila_opt_cost_by_grid_b_aig(t);	
}

if(rila_ind && valn_flag)
{
	return rila_opt_cost_bs_b_aig(t);
}


if (hedge_defn_local == NO || t < commencement_period || t > maturity_period)//WTW - Gen2 - Mutating Lookup Term used in expression
{
	return NO_AVG;
}
else
{
	double declared_cap, declared_sprd, declared_part;
	double total_option_cost; 

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if ( crediting_rate_defn_local == POINT_TO_POINT && crediting_dyn_lever_local == DYNAMIC_CAP )//WTW - Gen2 - character input that varies by time - Mutating Lookup Term used in expression
	{ // dynamic cap
		declared_cap = max(crediting_cap_rate(t), index_term_cap_rate_min_col_aig(t));
		declared_part = max(init_part_rate, index_term_part_rate_min_col_aig(t));

		//20210409 STW: update the strike price for hedge cost per unit
		double crediting_rate_floor_cv	= strategy_term_floor_col_aig(t);
        double long_strike				= 1 + crediting_rate_floor_cv;
		total_option_cost = get_option_price_aig(t - 1, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) 
			- get_option_price_aig(t - 1, 1 + declared_cap, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));  
		
		const double FWD_TERM	= 0.0;
		double rf_rate_cv		= 0.0;

		if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
			rf_rate_cv		= fia_rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  
		else
			rf_rate_cv		= rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  
		
		double floor_cost_cv	= crediting_rate_floor_cv / (1 + rf_rate_cv);

		total_option_cost += floor_cost_cv; 
	}
	else if ( crediting_rate_defn_local == POINT_TO_POINT_SPREAD && crediting_dyn_lever_local == DYNAMIC_CAP )//WTW - Gen2 - character input that varies by time - Mutating Lookup Term used in expression
	{	// dynamic spread
		declared_sprd = min(crediting_cap_rate(t), index_term_sprd_rate_max_col_aig(t));
		declared_part = max(init_part_rate, index_term_part_rate_min_col_aig(t));

		double long_strike = 1.0 + declared_sprd / declared_part;
		total_option_cost = get_option_price_aig(t - 1, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));

		total_option_cost *= declared_part;
	}
	else if ( crediting_rate_defn_local == POINT_TO_POINT_SPREAD && crediting_dyn_lever_local == DYNAMIC_PARTICIPATION )//WTW - Gen2 - character input that varies by time - Mutating Lookup Term used in expression
	{	// fixed spread + dynamic cap
		declared_sprd = min(index_term_init_spread_rate_aig(t), index_term_sprd_rate_max_col_aig(t));
		declared_part = max(crediting_part_rate_aig(t), index_term_part_rate_min_col_aig(t));

		double long_strike = 1.0 + declared_sprd / declared_part;
		total_option_cost = get_option_price_aig(t - 1, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));

		total_option_cost *= declared_part;
	}
	else if ( crediting_dyn_lever_local == DYNAMIC_PARTICIPATION_AND_SPREAD )//WTW - Gen2 - character input that varies by time
	{
		declared_sprd = min(crediting_spread_rate_aig(t), index_term_sprd_rate_max_col_aig(t));
		declared_part = max(crediting_part_rate_aig(t), index_term_part_rate_min_col_aig(t));

		total_option_cost = get_option_price_aig(t - 1, 1 + declared_sprd / declared_part, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		total_option_cost *= declared_part;
	}
	//20230105 SJ: add dynamci trigger logic for trigger fund
	else if (crediting_dyn_lever_local == DYNAMIC_TRIGGER) 
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
				
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
		double option_cost_one_percent = 0.0;
		if (fia->gen2_defn == YES)
			option_cost_one_percent = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			option_cost_one_percent = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		total_option_cost = crediting_trigger_rate_aig(t) * option_cost_one_percent;
	}
	//20230105 SJ END
	else if ( crediting_rate_defn_local == FIXED_RATE )
	{
		total_option_cost = crediting_rate_fix(t);
	}
	else
	{
		throw FatalError("fia_account->hedge_mkt_val_per_unit_notional_amt_aig : unhandled combination of `crediting_rate_defn` and `crediting_dyn_lever`.");
	}

	return total_option_cost;
}

}


//@@ END

//@@ START - hedge_option_val_alpha_col_aig
// alpha value to calculate option values in hedging                                                                                             
// Column:HEDGE_OPTION_VAL_ALPHA_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_option_val_alpha_col_aig(int t) {
//^^^



//^^^

#line 1 "hedge_option_val_alpha_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the credit rate floor for the index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - time guards
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

return hedge_option_val_alpha_aig;

}


//@@ END

//@@ START - hedge_rila_trading_cost_aig
// trading cost at beginning of the term                                                                                             
// Column:HEDGE_RILA_TRADING_COST_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_rila_trading_cost_aig(int t) {
//^^^



//^^^

#line 1 "hedge_rila_trading_cost_aig.FIAAFUND_LIAB.for"
//20240528 MQ New column for rila trading cost
if (t <= commencement_period || t > final_period)
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
	{
		return rila_strat_base_b_aig(t) * fabs(rila_opt_cost_beg_strat_term_aig(t)) * rila_trading_cost_pct_bom_aig(t);
	}
	else
	{
		return 0.;
	}

}

}


//@@ END

//@@ START - hedge_sale_amt_bom
// Hedge Sale Amount Beginning of Month                                                                                             
// Column:HEDGE_SALE_AMT_BOM
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_bom(int t) {
//^^^



//^^^

#line 1 "hedge_sale_amt_bom.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1)// 20190613 DTL: replaced `crediting_mths`
	return 0.0;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression

// WG 01/24 RILA Strategy Base Implementation
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;
if(rila_ind)
{
	double total_bom_released = rila_strat_base_e_aig(t - 1) - rila_strat_base_b_aig(t);
	double hedge_sale_amt = total_bom_released * pct_to_hedge_local * hedge_mkt_val_per_unit_notional(t - 1);
	return hedge_sale_amt;
}

return (admin_fee(t)
		+ fia->rop_chg_aig(t)
        + gmwb_chg(t))
	   * pct_to_hedge_local//WTW - Gen2 - Mutating Lookup Term used in expression
	   //* crediting_part_rate(t) // 20200622 STW: discard part rate
       * hedge_mkt_val_per_unit_notional(t - 1);

}


//@@ END

//@@ START - hedge_sale_amt_eom
// Hedge Sale Amount End of Month                                                                                             
// Column:HEDGE_SALE_AMT_EOM
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_eom(int t) {
//^^^



//^^^

#line 1 "hedge_sale_amt_eom.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0)// 20190613 DTL: replaced `crediting_mths`
	return 0.0;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression

// WG 01/24 RILA Strategy Base Implementation
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;
if(rila_ind)
{
	if (rila_knockout_status_bom_aig(t) == 0 && rila_knockout_status_eom_aig(t) == 1)// 241108 ZL: Bug fix to ensure when lock happens, the option is paid out and the position is released, and no more hedge sale is calculated.
	{
		return 0.;
	}

	if (rila_perf_lock_status_bom_aig(t) == 0 && rila_perf_lock_status_eom_aig(t) == 1) 
	{
		return notional_amt_required_bef(t) * hedge_mkt_val_per_unit_notional(t);
	}
	
	double total_eom_released = rila_strat_base_b_aig(t) - rila_strat_base_e_aig(t);
	double hedge_sale_amt = total_eom_released * pct_to_hedge_local * hedge_mkt_val_per_unit_notional(t);

	return hedge_sale_amt;

}

return (fund_released_dth(t)
	    + fund_released_surr(t)
	    + fund_released_ann(t)
	    + fund_released_withdrl(t)
	    + fund_released_maturity(t))
       * pct_to_hedge_local//WTW - Gen2 - Mutating Lookup Term used in expression
	   //* crediting_part_rate(t) // 20200622 STW: discard part rate
       * hedge_mkt_val_per_unit_notional(t);

}


//@@ END

//@@ START - index_term_aig
// Index Term:                                                                                             
// Column:INDEX_TERM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_aig(int t) {
//^^^



//^^^

#line 1 "index_term_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t < commencement_period || t > maturity_period)//WTW - Gen2 - time guards
	return NO_AVG;

fia->pol_yr(t);   
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double index_term = index_term_duration_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	index_term = index_term_duration_aig;
}

return index_term;

}


//@@ END

//@@ START - index_term_beginning_index_val_bom_aig
// Index Term Beginning Index Value:                                                                                             
// Column:INDEX_TERM_BEGINNING_INDEX_VAL_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_beginning_index_val_bom_aig(int t) {
//^^^



//^^^

#line 1 "index_term_beginning_index_val_bom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t < commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{	
	if (t == 0 && valn_period != 0)
	{
		return fia->index_term_beg_index_val;
	}

	if ( abs(index_term_elapsed_mths_eom_aig(t) - 1.0) < SMALL_DOUBLE )
	{
		return index_val_bom(t);
	}
	else
	{
		return index_term_beginning_index_val_bom_aig(t - 1);
	}
}

}


//@@ END

//@@ START - index_term_cap_rate_max_col_aig
// Index term cap for crediting:                                                                                             
// Column:INDEX_TERM_CAP_RATE_MAX_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_cap_rate_max_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_cap_rate_max_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the maximum cap to be used in a single index
 * term.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   // force call look-up key //WTW - Gen2 - add working variable lookup instead of direct column
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double index_term_cap_rate_max_cv = index_term_cap_rate_max_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240529 MQ revised condition
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	index_term_cap_rate_max_cv = index_term_cap_rate_max_aig;
}

if ( fia->option_strike_annualization_aig == ANNUALIZED )
{
	index_term_cap_rate_max_cv *= index_term_aig(t); // 20200512 DTL
}

return index_term_cap_rate_max_cv;

}


//@@ END

//@@ START - index_term_cap_rate_min_col_aig
// Index term minimum cap for crediting:                                                                                             
// Column:INDEX_TERM_CAP_RATE_MIN_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_cap_rate_min_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_cap_rate_min_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the maximum cap to be used in a single index
 * term.
 *
 *****************************************************************************/
if (t <= commencement_period || t > final_period/*maturity_period*/)// MQIN 20220616: changed to avoid returning value when t=0
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   // force call look-up key //WTW - Gen2 - add working variable lookup instead of direct column
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double index_term_cap_rate_min_cv = index_term_cap_rate_min_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240529 MQ revised condition
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	index_term_cap_rate_min_cv = index_term_cap_rate_min_aig;
}

if ( fia->option_strike_annualization_aig == ANNUALIZED )
{
	index_term_cap_rate_min_cv *= index_term_aig(t); // 20200512 DTL
}

return index_term_cap_rate_min_cv;

}


//@@ END

//@@ START - index_term_elapsed_mths_eom_aig
// Index Term Elapsed Months:                                                                                             
// Column:INDEX_TERM_ELAPSED_MTHS_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_mths_eom_aig(int t) {
//^^^



//^^^

#line 1 "index_term_elapsed_mths_eom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	if ( t == commencement_period + 1 ) // 20180109 MTC - Fixed div0 bug
	{
		//WG 20231016: Updated code to reflect elapsed months for RILA policies
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double rila_ind = fia->rila_ind;
		if(rila_ind)
		{
			double mth_in_term = mod(t + elapsed_mths, index_term_aig(t) * 12.0);
			return mth_in_term;
		}
		else
		{
			return 1.;
		}
	}
	else
	{
		const double MONTHS_IN_YEAR = 12.0;
		if ( mod(index_term_elapsed_mths_eom_aig(t - 1), index_term_aig(t - 1) * MONTHS_IN_YEAR ) == 0 )
		{
			return 1;
		}
		if ((rila_knockout_status_bom_aig(t) == 2 || rila_perf_lock_status_bom_aig(t) == 2) && mod(t + elapsed_mths, 12) == 1) // 20240311 MQ new condition for knockout strat
		{
			return 1;
		}
		else
		{
			return index_term_elapsed_mths_eom_aig(t - 1) + 1;
		}
	}
}

}


//@@ END

//@@ START - index_term_elapsed_pct_eom_aig
// Index Term Elapsed Percent EOM:                                                                                             
// Column:INDEX_TERM_ELAPSED_PCT_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_pct_eom_aig(int t) {
//^^^



//^^^

#line 1 "index_term_elapsed_pct_eom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
// Added continuous / annual prorata factor.  MCHING 12-11-2021.
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	const double MONTHS_IN_YEAR = 12.0;
	double current_index_term_duration = index_term_aig(t) * MONTHS_IN_YEAR;
	double current_index_term_mths_completed = index_term_elapsed_mths_eom_aig(t);

	if ( current_index_term_duration < SMALL_DOUBLE )
	{
		throw FatalError("fia_account->index_term_elapsed_pct_eom_aig(t) : Division by zero!");
	}
	else
	{
		double index_term_elapsed_pct;

		if ( fia->crediting_rate_partial_sprd_defn_aig == DISCRETE_ANNUAL )
		{
			double index_term_elapsed_yrs = ceil( index_term_elapsed_mths_eom_aig(t) / MONTHS_IN_YEAR );

			index_term_elapsed_pct = index_term_elapsed_yrs / index_term_aig(t);
		}
		else if ( fia->crediting_rate_partial_sprd_defn_aig == CONTINUOUS )
		{
			index_term_elapsed_pct = current_index_term_mths_completed / current_index_term_duration;
		}
		else
		{
			throw FatalError("Unhandled crediting_rate_partial_sprd_defn_aig requested in fia_account->index_term_elapsed_pct_eom_aig!");
		}

		return index_term_elapsed_pct;
	}
}

}


//@@ END

//@@ START - index_term_end_duration_aig
// Index Term End Duration (Month):                                                                                             
// Column:INDEX_TERM_END_DURATION_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_end_duration_aig(int t) {
//^^^



//^^^

#line 1 "index_term_end_duration_aig.FIAAFUND_LIAB.for"
// DTL 20200229: new column
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double index_term_end_duration_cv = index_term_start_duration_aig(t) + index_term_mths_aig(t) - 1.0;
return index_term_end_duration_cv;

}


//@@ END

//@@ START - index_term_floor_col_aig
// Index term floor to crediting rate:                                                                                             
// Column:INDEX_TERM_FLOOR_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_floor_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_floor_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the credit rate floor for the index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

return index_term_floor_aig;

}


//@@ END

//@@ START - index_term_index_return_aig
// Index Term Index Return:                                                                                             
// Column:INDEX_TERM_INDEX_RETURN_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_index_return_aig(int t) {
//^^^



//^^^

#line 1 "index_term_index_return_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	double index_start_value = index_term_beginning_index_val_bom_aig(t);
	if ( index_start_value < SMALL_DOUBLE )
	{
		// 20191129 DTL (START): we'll allow for the index going to zero -- return 0 in this case
		//throw FatalError("fia_account->index_term_index_return_aig(t) : Division by zero!");
		
		const double INFTY = 999999.0;
		return -INFTY;
		// 20191129 DTL (END)
	}
	else
	{
		double index_eom_value = index_val(t);
		return index_eom_value / index_start_value - 1;
	}
}

}


//@@ END

//@@ START - index_term_init_spread_rate_aig
// Initial spread rate adjusted for index term period:                                                                                             
// Column:INDEX_TERM_INIT_SPREAD_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_init_spread_rate_aig(int t) {
//^^^



//^^^

#line 1 "index_term_init_spread_rate_aig.FIAAFUND_LIAB.for"
// DTL 20200109: adding to wrap underlying model rate
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double initial_spread_cv;

initial_spread_cv = init_spread_rate_aig * index_term_aig(t);

return initial_spread_cv;

}


//@@ END

//@@ START - index_term_mths_aig
// Months in an index term:                                                                                             
// Column:INDEX_TERM_MTHS_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_mths_aig(int t) {
//^^^



//^^^

#line 1 "index_term_mths_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * DTL 20200109
 * 
 * Description: strategy term is used in various places in the model.
 * Often the model needs the value in months; this column provides that.
 *
 *****************************************************************************/
if (t <= commencement_period || t > maturity_period)// MQIN 20220616: changed to avoid returning value when t=0
	return NO_AVG;

const double MONTHS_IN_YEAR = 12.0;
return index_term_aig(t) * MONTHS_IN_YEAR;

}


//@@ END

//@@ START - index_term_part_rate_max_col_aig
// Index term maximum participation rate:                                                                                             
// Column:INDEX_TERM_PART_RATE_MAX_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_part_rate_max_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_part_rate_max_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the maximum participation rate to be used in a 
 * single index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

return index_term_part_rate_max_aig;

}


//@@ END

//@@ START - index_term_part_rate_min_col_aig
// Index term minimum participation rate:                                                                                             
// Column:INDEX_TERM_PART_RATE_MIN_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_part_rate_min_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_part_rate_min_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the minimum participation rate to be used in a 
 * single index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   // 20230105 SJ: change from direct column to working variable lookup for index_term_part_rate_min_aig

return index_term_part_rate_min_aig;

}


//@@ END

//@@ START - index_term_sprd_rate_max_col_aig
// Index term maximum spread for crediting:                                                                                             
// Column:INDEX_TERM_SPRD_RATE_MAX_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_sprd_rate_max_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_sprd_rate_max_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the maximum spread rate to be used in a 
 * single index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double index_term_sprd_rate_max_cv = index_term_sprd_rate_max_aig;

if ( fia->option_strike_annualization_aig == ANNUALIZED )
{
	index_term_sprd_rate_max_cv *= index_term_aig(t); // 20200512 DTL
}

return index_term_sprd_rate_max_cv;

}


//@@ END

//@@ START - index_term_sprd_rate_min_col_aig
// Index term spread rate for crediting:                                                                                             
// Column:INDEX_TERM_SPRD_RATE_MIN_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_sprd_rate_min_col_aig(int t) {
//^^^



//^^^

#line 1 "index_term_sprd_rate_min_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the minimum spread rate to be used in a 
 * single index term.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double index_term_sprd_rate_min_cv = index_term_sprd_rate_min_aig;

if ( fia->option_strike_annualization_aig == ANNUALIZED )
{
	index_term_sprd_rate_min_cv *= index_term_aig(t); // 20200512 DTL
}

return index_term_sprd_rate_min_cv;

}


//@@ END

//@@ START - index_term_start_duration_aig
// Index Term Start Duration:                                                                                             
// Column:INDEX_TERM_START_DURATION_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_start_duration_aig(int t) {
//^^^



//^^^

#line 1 "index_term_start_duration_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	if ( t == 1 )
	{
		//WG 20231016: Updated code to reflect elapsed months for RILA policies
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double rila_ind = fia->rila_ind;
		if (rila_ind)
		{
			double strategy_mth = mod(t + elapsed_mths, index_term_aig(t));
			double start_time_absolute = t + elapsed_mths - strategy_mth;
			return start_time_absolute;
		}
		else
		{
			return 1.;
		}
	}
	else
	{
		const double MONTHS_IN_YEAR = 12.0;
		if ( mod(index_term_elapsed_mths_eom_aig(t - 1), index_term_aig(t - 1) * MONTHS_IN_YEAR ) == 0 )
		{
			return t;
		}
		if ((rila_knockout_status_bom_aig(t) == 2 || rila_perf_lock_status_bom_aig(t) == 2) && mod(t + elapsed_mths, 12) == 1) // 20240311 MQ new condition for knockout strat
		{
			return t;
		}
		else
		{
			return index_term_start_duration_aig(t - 1);
		}
	}
}

}


//@@ END

//@@ START - index_val
// Index Value                                                                                             
// Column:INDEX_VAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(72,"index_val",t);
}



//^^^

#line 1 "index_val.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn == FIXED_RATE)
	return NO_AVG;

if (t == commencement_period && valn_period == 0)
	return 1.;

if (t == commencement_period && valn_period != 0)
	return fia->inner_index_val;
	//return index_val_calc(t); Not working for Nasdaq

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression

double growth_rate = 0.0;
double dividend_yld = 0.0; 
double growth_rate_mthly = 0.0;

//20260122 MQ apply regression formula for all non-US return
if(crediting_eqt_index_local != "US" && pba_valn_flag) 
{
	double random_num = fia->uniform_rands_non_us_return_aig(t);
	double err_term_stdnorm = inv_cumul_normal_aig(random_num);
	double sp_return = rates->get_index_rate(t,
						"US",
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL);

	double sp_return_mthly = pow(1. + sp_return, 1. / 12.) - 1.; //Need to apply regression to monthly return

	fia->index_id_lookup = crediting_eqt_index_local;
	double beta = fia->non_us_return_beta_aig;
	fia->index_id_lookup = crediting_eqt_index_local;
	double sigma = fia->non_us_return_sigma_aig;

	growth_rate_mthly = sp_return_mthly * beta + err_term_stdnorm * sigma;
	log_screen << ".. debug for sp_return_mthly = " << sp_return_mthly << " :: beta = " << beta << " :: sigma = " << sigma  << " :: err = " << err_term_stdnorm << MSG_USER;
}
else if (fia->gen2_defn == YES)
{
	growth_rate = fia_rates->get_index_rate(t,
							crediting_eqt_index_local,
							GET_GROWTH_RATE,
							EFFECTIVE_ANNUAL);

	growth_rate_mthly = pow(1. + growth_rate, 1. / 12.) - 1.;
}
else
{
	growth_rate = rates->get_index_rate(t,
							crediting_eqt_index_local,
							GET_GROWTH_RATE,
							EFFECTIVE_ANNUAL);
	
	growth_rate_mthly = pow(1. + growth_rate, 1. / 12.) - 1.;
	log_screen << ".. debug for growth_rate_mthly = " << growth_rate_mthly << MSG_USER;
}

//Return from Academy generator is total return, need to subtract dividend yield to get growth rate
if(pba_valn_flag)
{		
	//Checking edge case: growth rate based on the regression formula might go out of bound
	if ( 1 + growth_rate_mthly < SMALL_DOUBLE) 
	{
		return index_val_bom(t) * 0.000001;
	}

	//Convert to continuous rate, apply dividend which is continuous, then convert back to annual effctive
	double continuous_growth_rate = log(1 + growth_rate_mthly) * 12.; 

	fia->index_id_lookup = crediting_eqt_index_local;
	dividend_yld = fia->dividend_inner_aig; 

	growth_rate = exp(continuous_growth_rate - dividend_yld) - 1.0; 

	//checking again as growth rate is further reduced
	if ( 1 + growth_rate < SMALL_DOUBLE)
	{
		return index_val_bom(t) * 0.000001;
	}
}

return index_val_bom(t) * pow(1.0 + growth_rate * index_scen_mult + index_scen_sprd_addn, 1.0 / 12.0);


}


//@@ END

//@@ START - index_val_bom
// Index Value Beginning of Month                                                                                             
// Column:INDEX_VAL_BOM
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_val_bom(int t) {
//^^^



//^^^

#line 1 "index_val_bom.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return index_val(t - 1);

}


//@@ END

//@@ START - init_cap_rate_aig
// Initial crediting cap for the current strategy:                                                                                             
// Column:INIT_CAP_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_init_cap_rate_aig(int t) {
//^^^



//^^^

#line 1 "init_cap_rate_aig.FIAAFUND_LIAB.for"
// DTL 20200109: adding to wrap underlying model rate
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double initial_cap_cv;

initial_cap_cv = init_fia_cap;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local == "Dynamic Buffer" || renew_into_2nd_strat_status_aig(t) == 1) // 20240311 MQ  special logic for knockout strategy
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	double cap_rate = fia->init_cap_rate_index0;

	initial_cap_cv = cap_rate;
}

if (crediting_rate_type_local == "Dynamic Cap with Par") //20250804 MQ Enhanced par cap
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
	initial_cap_cv = fia->cap_rate_enh_par_cap;
}

return initial_cap_cv;

}


//@@ END

//@@ START - init_part_rate_aig
// Initial participation rate                                                                                             
// Column:INIT_PART_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_init_part_rate_aig(int t) {
//^^^



//^^^

#line 1 "init_part_rate_aig.FIAAFUND_LIAB.for"
//20241018 MQ Revised logic for intial part rate
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double init_part_rate_cv = init_part_rate;

if (renew_into_2nd_strat_status_aig(t) == 1) 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	init_part_rate_cv = fia->init_part_rate_index0;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
xstring init_crediting_rate_type = fia->crediting_rate_type_aig;
if (init_crediting_rate_type == "Dynamic Par with Cap") //20250124 MQ combo strategy
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
	init_part_rate_cv = par_rate_combo_strat_crbg;
}

return init_part_rate_cv;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.FIAAFUND_LIAB.for"
//WTW - Gen2 - Move to parent startup()
/*xstring group_name = fund_id;
setGroup(group_name);*/

// Add model class to output file list. MCHING 1-26-2022
// Bugfix to vGrid race condition. MCHING 2-15-2022
if (is_first_modelpoint && overall_is_first_proj_task_loop)
{
	fia_automation->append_to_file_manifest_aig(output_location());
}

return 1.0;

}


//@@ END

//@@ START - lapse_dyn_base_prod_crediting_rt_aig
// Base Product Dynamic Lapse crediting rate                                                                                             
// Column:LAPSE_DYN_BASE_PROD_CREDITING_RT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_lapse_dyn_base_prod_crediting_rt_aig(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_base_prod_crediting_rt_aig.FIAAFUND_LIAB.for"
/*
	Weighted sum refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

double crediting_rate, annualize_divisor;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == FIXED_RATE)
{
	crediting_rate = crediting_rate_fix(t);
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double rila_ind = fia->rila_ind;
	if (rila_ind)
	{
		crediting_rate = opt_budget_cost_aig(t); //20220423 MQ Use option cost at beginning of the term
	}
	else
	{
		crediting_rate = hedge_mkt_val_per_unit_notional_aig(t);
	}	
}

//20240620 ZL: make changes for RILA dynamic lapse
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
annualize_divisor = fia->annualize_divisor_aig;

if (renew_into_2nd_strat_status_aig(t) == 1)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	annualize_divisor = fia->annualize_divisor_aig;
}

if( fia->lapse_dyn_base_prod_defn_aig == RILA || fia->lapse_dyn_base_prod_defn_aig == HYBRID)
{
	crediting_rate /= annualize_divisor;
}
else
{
	crediting_rate /= strategy_term_aig(t);
}

// 20220701 STW: formula change for base product with fee for rate feature
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if (t > fia->surr_chg_period_aig * 12 && !fia->gmwb_flag && EPS_defn != NOT_ENHANCED)
{
	crediting_rate = max(0 , crediting_rate - eprs_cost_rate_aig(t));
}

return crediting_rate;


}


//@@ END

//@@ START - min_accum_val_b_aig
// NYIA: minimum accumulation value                                                                                             
// Column:MIN_ACCUM_VAL_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_b_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_b_aig.FIAAFUND_LIAB.for"
// 20200603 DTL

if (t < 0 || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

double mav_b_cv = min_accum_val_b_bef_aig(t);
return mav_b_cv;

}


//@@ END

//@@ START - min_accum_val_b_bef_aig
// NYIA: minimum accumulation value                                                                                             
// Column:MIN_ACCUM_VAL_B_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_b_bef_aig.FIAAFUND_LIAB.for"
// 20200603 DTL

if (t < 0 || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

double mav_b_bef_cv;

if (t == 1)
{
	mav_b_bef_cv = prem_alloc(t);
}
else
{
	mav_b_bef_cv = min_accum_val_e_aig(t - 1);

	double pol_yr_cv  = fia->pol_yr(t);
	double pol_mth_cv = fia->pol_mth(t);

	if ( pol_yr_cv > fia->min_accum_val_activation_period_yrs_ny_aig &&
	     pol_mth_cv == 1.0  )
	{
		double fund_val_b_bef_cv = fund_val_e(t - 1);
		mav_b_bef_cv             = max(mav_b_bef_cv, fund_val_b_bef_cv);
	}
}

return mav_b_bef_cv;

}


//@@ END

//@@ START - min_accum_val_e_aig
// NYIA: minimum accumulation value                                                                                             
// Column:MIN_ACCUM_VAL_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_aig.FIAAFUND_LIAB.for"
// 20200603 DTL: NYIA

if (t < 0 || t >= fia->maturity_benefits_period_aig)
{
	return NO_AVG;
}

double mav_e_bef_cv   = min_accum_val_e_bef_aig(t);
if (mav_e_bef_cv < SMALL_DOUBLE)
{
	return 0.0;
}

double surv_period_cv     = fia->surv_period(t);
double mav_e_cv           = mav_e_bef_cv * surv_period_cv;
double fund_val_e_bef_cv  = fund_val_e_bef(t);

double mav_reduction_fct;
if (fund_val_e_bef_cv > mav_e_bef_cv)
{
	mav_reduction_fct = 1.0 - fia->pfwd_rate_mthly_fund_val(t);
}
else
{
	mav_reduction_fct = 1.0 - fia->pfwd_rate_mthly_min_accum_val_aig(t);	
}

mav_e_cv *= mav_reduction_fct;

return mav_e_cv;

}


//@@ END

//@@ START - min_accum_val_e_bef_aig
// NYIA: minimum accumulation value                                                                                             
// Column:MIN_ACCUM_VAL_E_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_bef_aig.FIAAFUND_LIAB.for"
// 20200603 DTL

if (t < 0 || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

double mav_b_cv     = min_accum_val_b_aig(t);
double mav_e_bef_cv = mav_b_cv * pow(1.0 + fia->min_accum_val_annualized_growth_rate_ny_aig, 1.0/12.0);

return mav_e_bef_cv;

}


//@@ END

//@@ START - min_accum_val_e_bef_maturity_aig
// Minimum accumulation value before maturity payment:                                                                                             
// Column:MIN_ACCUM_VAL_E_BEF_MATURITY_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_bef_maturity_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_bef_maturity_aig.FIAAFUND_LIAB.for"
// DTL 20200908
if (t != fia->maturity_benefits_period_aig)
{
	return NO_AVG;
}

double claims_av				= 0.0;
double claims_av_bef_maturity	= 0.0;

claims_av_bef_maturity = 
			  fund_released_dth(t)
			+ fund_released_surr(t)
			+ fund_released_ann(t);

double fund_val_e_bef_cv = fund_val_e_bef(t);
double mav_e_bef_cv      = min_accum_val_e_bef_aig(t);

double wdl_pct;
if (fund_val_e_bef_cv > mav_e_bef_cv)
{
	wdl_pct = fia->pfwd_rate_mthly_fund_val(t);
}
else
{
	wdl_pct = fia->pfwd_rate_mthly_min_accum_val_aig(t);	
}

double mav_e_bef_maturity_cv  = min_accum_val_e_bef_aig(t) - claims_av_bef_maturity;
double mav_released_withdrls  = mav_e_bef_maturity_cv * wdl_pct;
mav_e_bef_maturity_cv        -= mav_released_withdrls;

if (mav_e_bef_maturity_cv < model_point_amount_threshold)
{
	return 0.0;
}

return mav_e_bef_maturity_cv;

}


//@@ END

//@@ START - mwv_base_b_aig
// MWV base at BOM:                                                                                             
// Column:MWV_BASE_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_b_aig(int t) {
//^^^



//^^^

#line 1 "mwv_base_b_aig.FIAAFUND_LIAB.for"
// 20240322 MQ new column
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if (t + elapsed_mths == commencement_period + 1) 
{	
	return fia->prem_issued(t) * fia->min_wdl_val_prem_pct_aig;
}

double mwv_base = mwv_base_e_aig(t - 1);

if (mwv_interim_val_e_aig(t - 1) > SMALL_DOUBLE)
{
	mwv_base = mwv_base * mwv_interim_val_b_aig(t) / mwv_interim_val_e_aig(t - 1);
}

return mwv_base;



}


//@@ END

//@@ START - mwv_base_e_aig
// MWV base at EOM:                                                                                             
// Column:MWV_BASE_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_e_aig(int t) {
//^^^



//^^^

#line 1 "mwv_base_e_aig.FIAAFUND_LIAB.for"
// 20240322 MQ new column
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if(t == 0 && elapsed_mths > 0)
	return fia->inner_mwv_base_aig;

double mwv_base;
if (mwv_interim_val_e_bef_aig(t) > SMALL_DOUBLE) 
{
	mwv_base = mwv_base_e_bef_aig(t) * mwv_interim_val_e_aig(t) / mwv_interim_val_e_bef_aig(t);
}
else 
{
	mwv_base = 0.0;
}

return mwv_base;

}


//@@ END

//@@ START - mwv_base_e_bef_aig
// MWV base at EOM:                                                                                             
// Column:MWV_BASE_E_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "mwv_base_e_bef_aig.FIAAFUND_LIAB.for"
// 20240322 MQ new column
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if (fia->valn_deterministic_flag_crbg)
{
	if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0)
		return mwv_base_b_aig(t) * (1 + crediting_rate(t));

	else
		return mwv_base_b_aig(t);
}

double mwv_base;

if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0 ||
	(rila_knockout_status_bom_aig(t) == 0 && rila_knockout_status_eom_aig(t) == 1))
{
	mwv_base = mwv_base_b_aig(t) * (1 + strategy_return_index_aig(t));
}
else 
{
	mwv_base = mwv_base_b_aig(t);
}

return mwv_base;


}


//@@ END

//@@ START - mwv_interim_val_b_aig
// Minimum Withdrawal Value at BOM:                                                                                             
// Column:MWV_INTERIM_VAL_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_b_aig(int t) {
//^^^



//^^^

#line 1 "mwv_interim_val_b_aig.FIAAFUND_LIAB.for"
//20240125 new column RILA MWV interim val
if (t <= commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if (t + elapsed_mths == commencement_period + 1) 
	return mwv_base_b_aig(t);

double mwv_iv_b = mwv_interim_val_e_aig(t - 1) - fia->rop_chg_aig(t);

return mwv_iv_b;

}


//@@ END

//@@ START - mwv_interim_val_e_aig
// Minimum Withdrawal Value at EOM:                                                                                             
// Column:MWV_INTERIM_VAL_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_e_aig(int t) {
//^^^



//^^^

#line 1 "mwv_interim_val_e_aig.FIAAFUND_LIAB.for"
//20240125 new column RILA MWV interim val
if (t < commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if(t == 0 && elapsed_mths > 0)
	return fia->inner_min_wdl_val_aig;

double mwv_iv_e;

mwv_iv_e = max(0., mwv_interim_val_e_bef_aig(t) * fia->surv_period(t) 
		- fia->withdrl_benefits(t) - fia->fund_released_maturity(t));

return mwv_iv_e;

}


//@@ END

//@@ START - mwv_interim_val_e_bef_aig
// Minimum Withdrawal Value at EOM:                                                                                             
// Column:MWV_INTERIM_VAL_E_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "mwv_interim_val_e_bef_aig.FIAAFUND_LIAB.for"
//20240125 new column RILA MWV interim val
if (t <= commencement_period || t > final_period)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

//20250407
if (fia->valn_deterministic_flag_crbg)
{
	if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0)
		return mwv_base_b_aig(t) * (1 + crediting_rate(t));

	else
		return mwv_base_b_aig(t);
}

//20241018 MQ Revised logic for performance lock
if (rila_perf_lock_status_bom_aig(t) == 1) //after lock
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double perf_lock_fixed = perf_lock_fixed_rt_aig;

	if (renew_into_2nd_strat_status_aig(t) == 1) 
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
		perf_lock_fixed = perf_lock_fixed_rt_aig;
	}		
	
	return mwv_interim_val_b_aig(t) * pow(1 + perf_lock_fixed, 1. / 12.);
}

// 20240318 MQ Add logic for Knockout strategy
if (rila_knockout_status_bom_aig(t) == 1 )
{
	return mwv_interim_val_b_aig(t) * (1 + strategy_return_index_aig(t));
}

if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0 ||
	(rila_knockout_status_bom_aig(t) == 0 && rila_knockout_status_eom_aig(t) == 1))
{
	return mwv_base_b_aig(t) * (1 + strategy_return_index_aig(t));
}

double strategy_months = strategy_term_mths_aig(t);
double index_months = index_term_mths_aig(t);

double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
double portion_remaining_time = 1 - strategy_term_elapsed_pct_eom_aig(t);
double initial_option_price_time = current_strategy_period * strategy_months;

double initial_option_price = 0.0;
double option_portfolio_value_current = 0.0;

if (pba_valn_flag)
{
	option_portfolio_value_current = rila_opt_cost_bs_e_aig(t);
	initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
}
else
{
	option_portfolio_value_current = rila_opt_cost_by_grid_e_aig(t);
	initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
}

// 20240327 MQ Add logic for knockout strategy
fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local == "Dynamic Buffer" && rila_knockout_status_eom_aig(t) == 0)
{
	initial_option_price = rila_knockout_cost_interim_val_init_aig(t);
	option_portfolio_value_current = rila_knockout_cost_interim_val_e_aig(t);
}

double mwv_RILA_Base = mwv_base_b_aig(t);   

double mwv_DAPV_Initial = mwv_RILA_Base * initial_option_price; 
double mwv_DAPV_Current = mwv_RILA_Base * option_portfolio_value_current;
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double ETC = rila_trading_cost_pct_eom_aig(t);
double FVAF = 1;

double mwv_interim_val = mwv_DAPV_Current + (mwv_RILA_Base - mwv_DAPV_Initial * portion_remaining_time) * FVAF
							 - fabs(mwv_DAPV_Current) * ETC;

return mwv_interim_val;

}


//@@ END

//@@ START - net_crediting_rate_aig
// Net Crediting Rate Aig                                                                                             
// Column:NET_CREDITING_RATE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_net_crediting_rate_aig(int t) {
//^^^



//^^^

#line 1 "net_crediting_rate_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
if (t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - refined time guards
{
	return NO_AVG;
}

double net_crediting_rate = crediting_rate(t) - eprs_cost_rate_aig(t) * strategy_term_aig(t);

return net_crediting_rate;

}


//@@ END

//@@ START - notional_amt_required
// Notional Amount Required                                                                                             
// Column:NOTIONAL_AMT_REQUIRED
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required(int t) {
//^^^



//^^^

#line 1 "notional_amt_required.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - Mutating Lookup Term used in expression
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (t == commencement_period && valn_period == 0)
	return notional_to_hedge_net(t);

if (t == commencement_period && valn_period != 0)
	return fia->init_hedge_amt;

if (t == fia->maturity_benefits_period_aig) 
{
	return 0.0;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression

//20240212 MQ notional amount for RILA should be based on strategy base
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;

if(rila_ind)
		return rila_strat_base_e_aig(t) * pct_to_hedge_local; 

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1) // 20190613 DTL: replaced `crediting_mths`
	return notional_to_hedge_net(t) 
	       - (fund_released_dth(t)
		      + fund_released_surr(t)
			  + fund_released_ann(t)
		      + fund_released_maturity(t)
		      + fund_released_withdrl(t))
			 * pct_to_hedge_local;//WTW - Gen2 - Mutating Lookup Term used in expression
			 //* crediting_part_rate(t); 
			 // admin_fee and gmwb_chg already deducted in fund_val_b
			 // 20200622 STW: crediting_part_rate already handled in option price

return notional_amt_required(t - 1) 
       - fund_val_decrem(t);
	     //* crediting_part_rate(t);
			 // 20200622 STW: crediting_part_rate already handled in option price

}


//@@ END

//@@ START - notional_amt_required_bef
// Notional Amount Required Before Decrements                                                                                             
// Column:NOTIONAL_AMT_REQUIRED_BEF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required_bef(int t) {
//^^^



//^^^

#line 1 "notional_amt_required_bef.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - Mutating Lookup Term used in expression
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (t == commencement_period)
	return notional_to_hedge_net(t);

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1)// 20190613 DTL: replaced `crediting_mths`
	return notional_to_hedge_net(t);

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression

return notional_amt_required(t - 1)
       - (admin_fee(t)
	      + gmwb_chg(t))
		* pct_to_hedge_local;//WTW - Gen2 - Mutating Lookup Term used in expression
		 //* crediting_part_rate(t);
		 // 20200630 STW: crediting_part_rate already handled in option price

}


//@@ END

//@@ START - notional_to_hedge
// Notional  Amount to Hedge                                                                                             
// Column:NOTIONAL_TO_HEDGE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"notional_to_hedge",t);
}



//^^^

#line 1 "notional_to_hedge.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - Mutating Lookup Term used in expression
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double pct_to_hedge_local = pct_to_hedge;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;

// Needed for option budget ratio calculation
if (t == commencement_period)
	if(rila_ind)
		return fia->init_strat_base * pct_to_hedge_local;
	else
		return init_fund_val * pct_to_hedge_local;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 1) // 20190613 DTL: replaced `crediting_mths`
{
	if(rila_ind)
		return rila_strat_base_b_aig(t) * pct_to_hedge_local; //WTW change. Use strategy base for RILA
	else
		return fund_val_b(t) * pct_to_hedge_local;
}
return 0.0;

}


//@@ END

//@@ START - notional_to_hedge_aig
// Notional Amount To Hedge:                                                                                             
// Column:NOTIONAL_TO_HEDGE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_aig(int t) {
//^^^



//^^^

#line 1 "notional_to_hedge_aig.FIAAFUND_LIAB.for"
// 20181017 DTL : Added column
// 20240207 comment: This column is not currently used.
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - Mutating Lookup Term used in expression
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;
else
{
	double base_lapse_rate = fia->lapse_rate_base(t);
	double crediting_period_yrs = strategy_term_aig(t);
	double proj_lapse_factor = pow(1.0 - fia->lapse_rate_base(t), crediting_period_yrs);

	double notional_to_hedge;
	if ( strategy_term_elapsed_mths_eom_aig(t) == 1 )
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		double pct_to_hedge_local = pct_to_hedge;//WTW - Gen2 - Mutating Lookup Term used in expression
		notional_to_hedge = fund_val_b(t) * pct_to_hedge_local * proj_lapse_factor;//WTW - Gen2 - Mutating Lookup Term used in expression
	}
	else
	{
		notional_to_hedge =  notional_to_hedge_aig(t - 1);
	}

	return notional_to_hedge;
}


}


//@@ END

//@@ START - notional_to_hedge_cap
// Notional Amount to Hedge Cap                                                                                             
// Column:NOTIONAL_TO_HEDGE_CAP
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"notional_to_hedge_cap",t);
}



//^^^

#line 1 "notional_to_hedge_cap.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (fabs(crediting_part_rate_aig(t)) < rate_ratio_threshold)
	return 0.0;

return notional_to_hedge(t)
       * (1.0 + crediting_cap_rate(t) / crediting_part_rate_aig(t));

}


//@@ END

//@@ START - notional_to_hedge_index
// Notional Amount to Hedge Index                                                                                             
// Column:NOTIONAL_TO_HEDGE_INDEX
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_index(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"notional_to_hedge_index",t);
}



//^^^

#line 1 "notional_to_hedge_index.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return notional_to_hedge(t)
       * index_val(t - 1);

}


//@@ END

//@@ START - notional_to_hedge_long_strike
// Notional Amount to Hedge Long Strike                                                                                             
// Column:NOTIONAL_TO_HEDGE_LONG_STRIKE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_long_strike(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(96,"notional_to_hedge_long_strike",t);
}



//^^^

#line 1 "notional_to_hedge_long_strike.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return notional_to_hedge(t)
       * opt_strike_price(t);

}


//@@ END

//@@ START - notional_to_hedge_net
// Notional Amount to Hedge Net                                                                                             
// Column:NOTIONAL_TO_HEDGE_NET
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"notional_to_hedge_net",t);
}



//^^^

#line 1 "notional_to_hedge_net.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

return notional_to_hedge(t);
       // 20200622 STW: 
	   //* crediting_part_rate(t);

}


//@@ END

//@@ START - opt_budget
// Available Option Budget                                                                                             
// Column:OPT_BUDGET
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"opt_budget",t);
}



//^^^

#line 1 "opt_budget.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period) 
	return NO_AVG;	

double option_budget = 0.0;

crediting_type_dyn_trigger_aig(t);

if (t + elapsed_mths == commencement_period + 1)
{
	double option_strike;
	double strategy_to_index_term_ratio = strategy_term_aig(t) / index_term_aig(t);
	
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if (rila_ind)
	{
		if (valn_flag)
		{
			//Initial option prices for any strategy at time 0 of the inner loop are fed from the outer loop.
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			option_budget = fia->init_opt_cost_aig;
		}
		else
		{
			option_budget = rila_opt_cost_by_grid_b_aig(t);		
		}	
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		StrEnum::EnumValue crediting_rate_defn_local = this->crediting_rate_defn;
		if ( crediting_rate_defn_local == POINT_TO_POINT_SPREAD )
		{
			fia->pol_yr_lookup_gen2 =  fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			xstring crediting_dyn_lever_local = crediting_dyn_lever;//WTW - Gen2 - Mutating Lookup Term used in expression
		
			double init_part_rate_cv = min(init_part_rate, index_term_part_rate_max_col_aig(t)); // 20220701 AA - cap on initial part rate

			option_strike = index_term_init_spread_rate_aig(t) / init_part_rate_cv;
			option_budget = get_option_price_aig(0, 1 + option_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) * init_part_rate_cv;
		}
		else //WTW - Gen2 - Changed else if {} to else { if {}...} in order to set key_temp
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			if ( crediting_rate_defn_local == FIXED_RATE )
			{
				option_budget = fia->init_crediting_rate_fixed_aig;
			}
			else  
			{
				//20230105 SJ: Update the initial option budget for trigger fund
				fia->pol_yr_lookup_gen2 =  fia->pol_yr(t); 
				fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
				xstring crediting_dyn_lever_local = crediting_dyn_lever;

				if (crediting_dyn_lever_local == "Dynamic Trigger")
				{
					fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
					string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
					string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
				
					string rate_lookup 
						= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
					double binary_opt_cost = 0.0;
					if (fia->gen2_defn == YES)
						binary_opt_cost = fia_rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);
					else
						binary_opt_cost = rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);

					option_budget = init_trigger_rate_aig * binary_opt_cost;
				}//20230105 SJ END
				else // crediting_rate_defn_local == POINT_TO_POINT
				{

					option_strike					= 1 + init_cap_rate_aig(t);

					double crediting_rate_floor_cv	= strategy_term_floor_col_aig(t);
					double long_strike				= 1 + crediting_rate_floor_cv;

					const double FWD_TERM	= 0.0;
					double rf_rate_cv		= 0.0;
					if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
						rf_rate_cv		= fia_rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT); // 20201014 DTL: assumes that swaps are entered in the scenario file as "YieldRates"
					else
						rf_rate_cv		= rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT); // 20201014 DTL: assumes that swaps are entered in the scenario file as "YieldRates"
			
					double floor_cost_cv	= crediting_rate_floor_cv / (1 + rf_rate_cv);

					double long_option_cost		= get_option_price_aig(0, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
					double short_option_cost	= get_option_price_aig(0, option_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));

					option_budget  = long_option_cost;
					option_budget -= short_option_cost;
					option_budget += floor_cost_cv;
				}
			}
		}
	}
}

else
{
	if (fia->opt_budget_defn_aig == RENEWAL_2020) // MQIN 20220616: This is the only acceptable option.
	{			
		if ( fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_ON) // MQIN 20220616: Column refactored for dynamic switching
		{

			if ((t >= strategy_term_aig(max(0, t - 1)) * 12 + 1) 
				&& (fia->crediting_type_dyn_2nd_strat_aig != "NA"))
			{
				option_budget = opt_budget_renewal_2nd_strat_aig(t);
			}
			else
			{
				option_budget = opt_budget_renewal_aig(t);
			}
		}
		else
		{
			if (renew_into_2nd_strat_status_aig(t) == 1) //20240529 MQ revised condition
				option_budget = opt_budget_renewal_2nd_strat_aig(t);
			else
				option_budget = opt_budget_renewal_aig(t);
		}
	}	
	else
	{
		if (fia->gen2_defn == NO)
			makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported
		log_screen << "Warning: opt_budget_defn_aig is not set to Renewal_2020. Please check product assumption workbook." << MSG_ERROR;
	}
}
		
return option_budget;

}


//@@ END

//@@ START - opt_budget_amt
// Option Budget Amount                                                                                             
// Column:OPT_BUDGET_AMT
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(99,"opt_budget_amt",t);
}



//^^^

#line 1 "opt_budget_amt.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (t == commencement_period)
	return notional_to_hedge(t) * opt_budget(t);

if (fabs(notional_to_hedge(t)) <= model_point_amount_threshold)
	return NO_AVG;

//force call for reporting
opt_payoff(t);

return max(0.0, notional_to_hedge(t) * opt_budget(t));

}


//@@ END

//@@ START - opt_budget_cost_aig
// Opt Budget Cost Aig                                                                                             
// Column:OPT_BUDGET_COST_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_cost_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_cost_aig.FIAAFUND_LIAB.for"
// 20200622 STW: change to fit hedge logic
if (/*hedge_defn_local == NO ||*/ t < commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (t == 0 && valn_period != 0)
{
	return fia->inner_opt_cost_beg_term;
}

//20250407
if (fia->valn_deterministic_flag_crbg)
{
	return opt_budget(t);
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
{
	return NO_AVG;
}
else if ( strategy_term_elapsed_mths_eom_aig(t) == 1 )
{
	return hedge_mkt_val_per_unit_notional_aig(t);
}
else
{	
	return opt_budget_cost_aig(t-1);
}

}


//@@ END

//@@ START - opt_budget_eprs_aig
// Opt Budget for EPRS                                                                                             
// Column:OPT_BUDGET_EPRS_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_eprs_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_eprs_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue crediting_rate_defn_local = crediting_rate_defn;//WTW - Gen2 - Mutating Lookup Term used in expression
if (t <= commencement_period || crediting_rate_defn_local != POINT_TO_POINT_SPREAD || t > final_period/*maturity_period*/ //WTW - Gen2 - refined time guards
	|| tier_number_aig(t) == 0)
	return NO_AVG;	

double option_budget = 0.0;

if (t == commencement_period + 1)
{
	double option_strike;
	double strategy_to_index_term_ratio = strategy_term_aig(t) / index_term_aig(t);

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	if ( crediting_rate_defn == POINT_TO_POINT_SPREAD )
	{
		//use enhanced par rate for fee for rate phase 2.
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double initial_participation_rate = eprs_par_rate_aig;
		
		option_strike = index_term_init_spread_rate_aig(t) / initial_participation_rate;
		option_budget = get_option_price_aig(0, 1 + option_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) * initial_participation_rate;
	
	}
}
else
{
	option_budget = opt_budget_eprs_aig(t - 1);

	//add SFC(ROP) hedge cost to EPR (FFR) option budget
	if(t == fia->surr_chg_period_aig * 12 + 1)
	{
		option_budget += fia->sfc_annual_hedge_cost_col_aig(t);
	}
}
	
return option_budget;

}


//@@ END

//@@ START - opt_budget_renewal_2nd_strat_aig
// Option budget for the 2nd strategy                                                                                             
// Column:OPT_BUDGET_RENEWAL_2ND_STRAT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_renewal_2nd_strat_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_renewal_2nd_strat_aig.FIAAFUND_LIAB.for"
// MQIN 20220616: New column option budget for 2nd strategy
if (t <= commencement_period || t > final_period || fia->crediting_type_dyn_2nd_strat_aig == "NA")
{
	return NO_AVG;	
}

if (t + elapsed_mths == commencement_period + 1)
{
	double init_option_budget = 0.0;
	
	if (valn_flag)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		init_option_budget = fia->init_opt_cost_aig;
	}
	else
	{
		init_option_budget = rila_init_opt_cost_by_grid_2nd_strat_aig(t);
	}

	return init_option_budget;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double strategy_term = strategy_term_duration_aig;

if (mod(t + elapsed_mths, strategy_term * 12.) != 1 )
{
	if (t == 1)
		return fia->inner_renewal_budget_2nd_strat; //initial budget for inner loop & future timestep
	else
		return opt_budget_renewal_2nd_strat_aig(t - 1);
}

double init_budget;

if(valn_period != 0)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	init_budget = fia->init_opt_cost_aig;
}
else
{
	init_budget = opt_budget_renewal_2nd_strat_aig(commencement_period + 1);
}

double budget_holding_period_cv = (renewal_migration_beg_yr_aig - 1.) * 12.; 
if (t + elapsed_mths <= budget_holding_period_cv)
{
	return init_budget;
}

//20250127 MQ code refactoring
double tgt_budget = opt_budget_tgt_calc_aig(t, init_budget, strategy_term, strategy_term);

double opt_budget = opt_budget_renewal_calc_aig(t, init_budget, tgt_budget, strategy_term, strategy_term);

return opt_budget;

}


//@@ END

//@@ START - opt_budget_renewal_aig
// Option budget for the initial strategy                                                                                             
// Column:OPT_BUDGET_RENEWAL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_renewal_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_renewal_aig.FIAAFUND_LIAB.for"
// MQIN 20220616: Refactored column for renewal option budget
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;	
}
//WG 20231017: Updating code to reflect initial option budget even in future valuation periods
double init_opt_cost = 0.;

if (t + elapsed_mths == commencement_period + 1)
{
	return opt_budget(t);
}

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) != 1 )
{
	if (t == 1)
		return fia->inner_renewal_budget;
	else
		return opt_budget_renewal_aig(t - 1);
}
	
fia->pol_yr_lookup_gen2 = 1.; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double init_strategy_term = strategy_term_duration_aig;

double init_budget;
if(valn_period != 0)
	init_budget = fia->init_hedge_budget;
else
	init_budget = opt_budget_renewal_aig(commencement_period + 1);

double tgt_budget = opt_budget_tgt_aig(t);

double opt_budget = opt_budget_renewal_calc_aig(t, init_budget, tgt_budget, init_strategy_term, strategy_term_aig(t));

return opt_budget;

}


//@@ END

//@@ START - opt_budget_strategy_term_renewal_aig
// Available Option Budget at Strategy Term Renewal                                                                                             
// Column:OPT_BUDGET_STRATEGY_TERM_RENEWAL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_strategy_term_renewal_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_strategy_term_renewal_aig.FIAAFUND_LIAB.for"
/*
	Weighted sum refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
{
	return opt_budget(t);
}
else
{
	return 0.0;
}


}


//@@ END

//@@ START - opt_budget_tgt_aig
// Option budget:                                                                                             
// Column:OPT_BUDGET_TGT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_tgt_aig(int t) {
//^^^



//^^^

#line 1 "opt_budget_tgt_aig.FIAAFUND_LIAB.for"
// DTL 20200904
// MQIN 20220616: refactored column for dynamic switching
if (t <= commencement_period || t > final_period)
	return NO_AVG;	

//WG 20231031 Updated logic to avoid cirular reference when running nested stochastic
double option_cost_cv = 0.0;

if(valn_period == 0)
{
	option_cost_cv = opt_budget(commencement_period + 1);
}
else
{
	option_cost_cv = fia->init_hedge_budget;
}

//20250127 MQ code refactoring
fia->pol_yr_lookup_gen2 = 1.; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double init_strategy_term = strategy_term_duration_aig;

double tgt = opt_budget_tgt_calc_aig(t, option_cost_cv, init_strategy_term, strategy_term_aig(t));

return tgt;

}


//@@ END

//@@ START - opt_cost_atm_aig
// ATM Opt Cost. Created when Solving for Particiaption Rate for Fee4rate Phase 2                                                                                             
// Column:OPT_COST_ATM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_atm_aig(int t) {
//^^^



//^^^

#line 1 "opt_cost_atm_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column for reporting purposes
fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue crediting_dyn_lever_local = crediting_dyn_lever;//WTW - Gen2 - Mutating Lookup Term used in expression
if (t <= commencement_period || crediting_dyn_lever_local != DYNAMIC_PARTICIPATION
	|| t > final_period/*maturity_period*/ ) //WTW - Gen2 - refined time guards
	return NO_AVG;	

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn == FIXED_RATE)
	return 0;

const double TABLE_ATM_STRIKE = 1.0;

double option_cost = get_option_price_aig(t - 1, TABLE_ATM_STRIKE, CALL, strategy_term_mths_aig(t), strategy_term_mths_aig(t)); 

return option_cost;

}


//@@ END

//@@ START - opt_payoff
// Option Payoff                                                                                             
// Column:OPT_PAYOFF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_payoff(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(107,"opt_payoff",t);
}



//^^^

#line 1 "opt_payoff.FIAAFUND_LIAB.for"
if (/*hedge_defn_local == NO || */t > fia->final_period)//WTW - Gen2 - Mutating Lookup Term used in expression
	return NO_AVG;
	
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO)
	return NO_AVG;

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) != 0) // 20190613 DTL: replaced `crediting_mths`
	return NO_AVG;

return opt_payoff_aig(t); //20240422 MQ. index_val_calc used below doesn't work for the customized Nasdaq return
	
double payoff = 0.0;
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;
if (rila_ind)
{
	//This is a RILA
	//RILA Features
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double floor_amt = index_term_floor_aig;
	
	double buffer_amt = rila_buffer_amt_aig(t);
	
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double part_down_amt = fia->part_down_amt;
	
	double part_rate = crediting_part_rate_aig(t);

	//Market Value facts
	double underlying = index_val(t);
	double index_val_at_crediting_start = 0.0;
	double index_units_owned = 0.0;
	double notional_amt = 0.0;

	if (elapsed_mths > 0 && t < strategy_term_mths_aig(t) /*crediting_mths*/) // 20190613 DTL: replaced `crediting_mths`
	{
		index_val_at_crediting_start = index_val_calc(t - strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`
		index_units_owned = 1.0 / index_val_at_crediting_start;
		notional_amt = notional_amt_required_bef(t);
	}
	else
	{
		index_val_at_crediting_start = index_val_bom(t + 1 - strategy_term_mths_aig(t) /*crediting_mths*/); // 20190613 DTL: replaced `crediting_mths`
		index_units_owned = 1.0 / index_val_at_crediting_start;
		notional_amt = notional_amt_required_bef(t);
	}

	double long_call_strike = 0.0;
	double short_call_strike = 0.0;
	double long_put_strike = 0.0;
	double short_put_strike = 0.0;
	double initial_index_value = index_val(t - strategy_term_mths_aig(t));
	
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
	StrEnum::EnumValue crediting_rate_defn_local = this->crediting_rate_defn;
	
	if (crediting_rate_defn_local == POINT_TO_POINT)
	{
		if(buffer_amt != 0)
		{
			//Buffer Cap Strategy
			// long call ATM and short call at cap
			// short put at the buffer, no long put
			long_call_strike = initial_index_value * 1 ;
			short_call_strike = initial_index_value * (1 + fia_account->crediting_cap_rate(t));
			long_put_strike = -payout_index_max;
			short_put_strike = initial_index_value * (1 - buffer_amt);

			double mkt_val_per_unit_calls
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_call_strike,
						short_call_strike,
						crediting_cap_rate(t),
						CALL, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn 
			
			double mkt_val_per_unit_puts
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_put_strike,
						short_put_strike,
						crediting_cap_rate(t),
						PUT, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn

			payoff = notional_amt
					 * (mkt_val_per_unit_calls + mkt_val_per_unit_puts);

			return payoff;

		}
		else
		{
			//Floor Cap Strategy
			// long call ATM, short call at the cap
			// short put ATM, long put at the floor

			long_call_strike = initial_index_value * 1 ;
			short_call_strike = initial_index_value * fia_account->crediting_cap_rate(t);
			long_put_strike = initial_index_value * (1 + floor_amt);
			short_put_strike = initial_index_value * (1 - buffer_amt);

			double mkt_val_per_unit_calls
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_call_strike,
						short_call_strike,
						crediting_cap_rate(t),
						CALL, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn 
			
			double mkt_val_per_unit_puts
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_put_strike,
						short_put_strike,
						crediting_cap_rate(t),
						PUT, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn

			payoff = notional_amt
					 * (mkt_val_per_unit_calls + mkt_val_per_unit_puts);

			return payoff;

		}

	}
	else //if (crediting_rate_defn_local == POINT_TO_POINT_SPREAD)
	{
	//Dynamic Participation Strategy
		if(buffer_amt != 0)
		{
			//Buffer par strategy
			// long call ATM
			// short put at the buffer
			
			long_call_strike = initial_index_value * 1;
			short_call_strike = payout_index_max;
			long_put_strike = -payout_index_max;
			short_put_strike = initial_index_value * (1 - buffer_amt);
			double par_up = crediting_part_rate_aig(t);

			double mkt_val_per_unit_calls
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0.0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_call_strike,
						short_call_strike,
						crediting_cap_rate(t),
						CALL, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn 
			
			double mkt_val_per_unit_puts
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0.0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_put_strike,
						short_put_strike,
						crediting_cap_rate(t),
						PUT, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn

			payoff = notional_amt
					 * (par_up * mkt_val_per_unit_calls + mkt_val_per_unit_puts);

			return payoff;

		}
		else
		{
			//Par-up Par-down Strategy

			long_call_strike = initial_index_value * 1;
			short_call_strike = payout_index_max;
			long_put_strike = -payout_index_max;
			short_put_strike = initial_index_value * 1;
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
			double par_down = fia->part_down_amt;
			double par_up = crediting_part_rate_aig(t);

			double mkt_val_per_unit_calls
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0.0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_call_strike,
						short_call_strike,
						crediting_cap_rate(t),
						CALL, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn 
			
			double mkt_val_per_unit_puts
			= mkt_val_calc(t,
						xint(fia->cal_yr_relative(t)),
						xint(fia->cal_mth(t)),
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned,
						underlying,
						index_scen_mult,
						index_scen_sprd_addn,
						0.0, //yrs_to_expiry
						div_yld_scen_mult,
						div_yld_sprd,
						long_put_strike,
						short_put_strike,
						crediting_cap_rate(t),
						PUT, //opt_defn
						0.0, // spot_sprd_adj,
						0.0, // volatility_sprd_adj,
						NO_SHIFT); // shift_defn

			payoff = notional_amt
					 * (par_up * mkt_val_per_unit_calls + par_down * mkt_val_per_unit_puts);

			return payoff;
		}
	}

}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
StrEnum::EnumValue crediting_rate_defn_local = this->crediting_rate_defn;
if (crediting_rate_defn_local == POINT_TO_POINT
	|| crediting_rate_defn_local == MOVING_AVERAGE)
	{
	double underlying = index_val(t);
	double index_val_at_crediting_start = 0.0;
	double index_units_owned = 0.0;
	double long_strike = 0.0;
	double short_strike = 0.0;
	double notional_amt = 0.0;
	if (elapsed_mths > 0 && t < strategy_term_mths_aig(t) /*crediting_mths*/) // 20190613 DTL: replaced `crediting_mths`
		{
		index_val_at_crediting_start = index_val_calc(t - strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`
		index_units_owned = 1.0 / index_val_at_crediting_start;
		long_strike = index_val_at_crediting_start * pow(1.0 + strategy_term_floor_col_aig(t), strategy_term_aig(t) /*crediting_mths / 12.0*/);// 20190613 DTL: replaced `crediting_mths` // DTL 20180919 : Replaced `crediting_floor` with `strategy_term_floor_aig`
		short_strike = index_val_at_crediting_start * (1.0 + crediting_cap_rate(t));
		notional_amt = notional_amt_required_bef(t);
		}
	else
		{
		index_val_at_crediting_start = index_val_bom(t + 1 - strategy_term_mths_aig(t) /*crediting_mths*/); // 20190613 DTL: replaced `crediting_mths`

		index_units_owned = 1.0 / index_val_at_crediting_start;
		long_strike = opt_strike_price(t + 1 - strategy_term_mths_aig(t) /*crediting_mths*/); // 20190613 DTL: replaced `crediting_mths`
		short_strike = index_val_at_crediting_start * (1.0 + crediting_cap_rate(t));
		notional_amt = notional_amt_required_bef(t);
		}

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

	if (crediting_dyn_lever != DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time
		short_strike = payout_index_max;

	double mkt_val_per_unit
	= mkt_val_calc(t,
				xint(fia->cal_yr_relative(t)),
				xint(fia->cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned,
				underlying,
				index_scen_mult,
				index_scen_sprd_addn,
				0.0, //yrs_to_expiry
				div_yld_scen_mult,
				div_yld_sprd,
				long_strike,
				short_strike,
				crediting_cap_rate(t),
				CALL, //opt_defn
				0.0, // spot_sprd_adj,
				0.0, // volatility_sprd_adj,
				NO_SHIFT); // shift_defn 

	payoff = notional_amt
	         * mkt_val_per_unit;

	return payoff;
	}
else // if (crediting_rate_defn_local == MONTHLY_SUM_CAP) 
	{
/*
	double index_curr = 0;
	double index_prev = 0;
	double index_change_sum = 0;
	double notional_amt = notional_amt_required_bef(t);

	for (int i = 0; i < crediting_mths; i++)
		{
		index_curr = index_val_calc(t - i);
		index_prev = index_val_calc(t - i - 1);
		
		if (index_prev > 0) //need to set index_prev first			
			index_change_sum += min(crediting_cap_rate(t), (index_curr / index_prev) - 1.0);
		}	

	double mkt_val_per_unit = max(0.0, index_change_sum);
*/
	double underlying = index_val(t);
	double index_val_at_crediting_start = 0.0;
	double index_units_owned = 1.0;
	double long_strike = 0.0;
	double short_strike = 0.0;
	double notional_amt = 0.0;

	if (elapsed_mths > 0 && t < strategy_term_mths_aig(t) /*crediting_mths*/)  // 20190613 DTL: replaced `crediting_mths`
		{
		index_val_at_crediting_start = index_val_calc(t - strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`
		long_strike = index_val_at_crediting_start * pow(1.0 + strategy_term_floor_col_aig(t), strategy_term_aig(t) /*crediting_mths / 12.0*/); // 20190613 DTL: replaced `crediting_mths`		// DTL 20180919 : Replaced `crediting_floor` with `strategy_term_floor_aig`
		short_strike = index_val_at_crediting_start * (1.0 + crediting_cap_rate(t));
		notional_amt = notional_amt_required_bef(t);
		}
	else
		{
		index_val_at_crediting_start = index_val_bom(t + 1 - strategy_term_mths_aig(t) /*crediting_mths*/); // 20190613 DTL: replaced `crediting_mths`
		long_strike = opt_strike_price(t + 1 - strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`
		short_strike = index_val_at_crediting_start * (1.0 + crediting_cap_rate(t));
		notional_amt = notional_amt_required_bef(t);
		}

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

	if (crediting_dyn_lever != DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time
		short_strike = payout_index_max;

	double mkt_val_per_unit
	= mkt_val_calc(t,
				xint(fia->cal_yr_relative(t)),
				xint(fia->cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned,
				underlying,
				index_scen_mult,
				index_scen_sprd_addn,
				0.0, //yrs_to_expiry
				div_yld_scen_mult,
				div_yld_sprd,
				long_strike,
				short_strike,
				crediting_cap_rate(t),
				CALL, //opt_defn
				0.0, // spot_sprd_adj,
				0.0, // volatility_sprd_adj,
				NO_SHIFT); // shift_defn 

	payoff = notional_amt
	         * mkt_val_per_unit;

	return payoff;
	}
	
//return NO_AVG; //WTW - Gen2 - return will never get called

}


//@@ END

//@@ START - opt_payoff_aig
// Option Payoff:                                                                                             
// Column:OPT_PAYOFF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_payoff_aig(int t) {
//^^^



//^^^

#line 1 "opt_payoff_aig.FIAAFUND_LIAB.for"
// 20200622 STW: change to fix hedge logic
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - Mutating Lookup Term used in expression
{
	return NO_AVG;
}

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
StrEnum::EnumValue hedge_defn_local = hedge_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
xstring crediting_rate_defn_local = crediting_rate_defn;//WTW - Gen2 - Mutating Lookup Term used in expression

if (hedge_defn_local == NO || crediting_rate_defn_local == "Fixed Rate")//WTW - Gen2 - Mutating Lookup Term used in expression
{
	return NO_AVG;
}

double opt_payoff_cv;

//20240529 Special logic for Knockout strategy option payoff
if (rila_knockout_status_eom_aig(t) == 1 && rila_knockout_status_bom_aig(t) == 0) 
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double knockout_threshold = knockout_threshold_aig; 

	double payoff = knockout_threshold;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double add_rebate_per_yr = knockout_rebate_opt_bdgt_aig;

	if (pba_valn_flag)
	{
		double yr_elapsed	= ceil(strategy_term_elapsed_mths_eom_aig(t) / 12.);
		double yr_remaining = strategy_term_aig(t) - yr_elapsed; 

		payoff += add_rebate_per_yr * yr_remaining;
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "_D" + to_string(int(strategy_term_mths_aig(t)));
		int knockout_key = (1 + knockout_threshold) * 100;
		string knockout_str = "_K" + to_string(knockout_key);

		string rate_lookup = "DIGITAL_" + index_id_regex_str + option_duration_str + knockout_str;
		double digital_opt_cost;

		if (fia->gen2_defn == YES)
			digital_opt_cost = fia_rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			digital_opt_cost = rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);		

		payoff += add_rebate_per_yr * digital_opt_cost;
	}

	opt_payoff_cv = notional_amt_required_bef(t) * payoff;
}
else if (strategy_term_elapsed_mths_eom_aig(t) == strategy_term_aig(t) * 12 )
{
	opt_payoff_cv = notional_amt_required_bef(t) * strategy_return_index_aig(t);
}
else
{
	opt_payoff_cv = 0.;
}

if (opt_payoff_cv < 0 && valn_flag)
{
	return opt_payoff_cv * (1 + rila_opt_inefficiency);
}
else if (opt_payoff_cv >= 0 && valn_flag)
{
	return opt_payoff_cv * (1 - rila_opt_inefficiency);
}
else
{
	return opt_payoff_cv;
}


}


//@@ END

//@@ START - opt_strike_price
// Option Strike Price                                                                                             
// Column:OPT_STRIKE_PRICE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_strike_price(int t) {
//^^^



//^^^

#line 1 "opt_strike_price.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (fia->fund_val_b_bef(t) < model_point_amount_threshold)
    return NO_AVG;

double guar_av = fia->min_contract_val(t - 1) * (fund_val_b_bef(t) / fia->fund_val_b_bef(t));
double curr_av = fund_val_e(t - 1);
double ratio = 0.0;

if (guar_av > curr_av)
	ratio = (guar_av / curr_av) - 1.0;

return index_val(t - 1) * (1.0 + ratio);

}


//@@ END

//@@ START - opt_value_net_numer
// Net Option Value Numerator                                                                                             
// Column:OPT_VALUE_NET_NUMER
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_value_net_numer(int t) {
//^^^



//^^^

#line 1 "opt_value_net_numer.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

if (fia->fund_val_b_bef(t) < model_point_amount_threshold)
    return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn == FIXED_RATE) // 20241203 Fix Strategy
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

double cost_of_call_option_pct = 0.0;
double cost_of_call_option_cap_pct = 0.0;
double net_opt_value = 0.0;
double accum_option_pct = 0.0;
double cred_factor = 0.0;
double fixed_rate = 0.0;
double tte = 0.0;
double K = 0.0;
double K_cap = 0.0;
double S = 0.0;
double rf = 0.0;
double q = 0.0;
double sigma = 0.0;
double sigma_cap = 0.0;
double month = 0.0;
double Average = 0.0;
double fixed_rate_num = 0.0;
double option_rate_num = 0.0;
double part_rate = crediting_part_rate_aig(t);

double crediting_cap_minimum_cv;
// `crediting_cap_min` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_min_aig`
crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);

K = opt_strike_price(t);
K_cap = K * (max(crediting_cap_rate(t), crediting_cap_minimum_cv) + 1.0); // "K_cap = K * (max(crediting_cap_rate(t), crediting_cap_min) + 1.0);" DTL 20190415
S = index_val(t);
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression

if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
	q = fia_rates->get_index_rate(t, 
				crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL)
		* div_yld_scen_mult + div_yld_sprd;
else
	q = rates->get_index_rate(t, 
				crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL)
		* div_yld_scen_mult + div_yld_sprd;

if (fabs(strategy_term_mths_aig(t)) < rate_ratio_threshold)
	tte = 0.0;
else
	tte = double ( strategy_term_mths_aig(t) /*crediting_mths*/ - xint(mod(elapsed_mths + t, strategy_term_mths_aig(t) /*crediting_mths*/))) / strategy_term_mths_aig(t);/*double(crediting_mths);*/ // 20190613 DTL: replaced `crediting_mths`
	
if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	sigma = fia_rates->get_index_vol(t, 
									crediting_eqt_index,
									K / S,
									tte,
									EFFECTIVE_ANNUAL,
									NO_SHIFT);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	sigma_cap = fia_rates->get_index_vol(t, 
									crediting_eqt_index,
									K_cap / S,
									tte,
									EFFECTIVE_ANNUAL,
									NO_SHIFT);
	rf = fia_rates->get_int_rate(t,
								"Govt",
								GET_SPOT_RATE,
								tte,
								0.0,
								NOMINAL_SEMIANNUAL,
								NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	cost_of_call_option_pct = 0.0;
	cost_of_call_option_cap_pct = 0.0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	sigma = rates->get_index_vol(t, 
									crediting_eqt_index,
									K / S,
									tte,
									EFFECTIVE_ANNUAL,
									NO_SHIFT);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	sigma_cap = rates->get_index_vol(t, 
									crediting_eqt_index,
									K_cap / S,
									tte,
									EFFECTIVE_ANNUAL,
									NO_SHIFT);
	rf = rates->get_int_rate(t,
								"Govt",
								GET_SPOT_RATE,
								tte,
								0.0,
								NOMINAL_SEMIANNUAL,
								NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	cost_of_call_option_pct = 0.0;
	cost_of_call_option_cap_pct = 0.0;
}
	
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == POINT_TO_POINT)
	{
	cost_of_call_option_pct = bs_opt_val(K, tte, S, sigma, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K; 
	cost_of_call_option_cap_pct = bs_opt_val(K_cap, tte, S, sigma_cap, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K;
	
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		
	if (crediting_dyn_lever == DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct);
	else if (crediting_dyn_lever == DYNAMIC_PARTICIPATION)	//WTW - Gen2 - character input that varies by time			
		net_opt_value = cost_of_call_option_pct * part_rate;
	else //Both cap and participation
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct)
						* part_rate;
		
	option_rate_num = net_opt_value * fund_val_b_bef(t);
	}
else //WTW - Gen2 - Mutating Lookup Term - Change else if {} to else { if {}...}
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (crediting_rate_defn == MOVING_AVERAGE)
		{
		if (mod (t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0.0) // 20190613 DTL: replaced `crediting_mths`
			month = strategy_term_mths_aig(t); /*crediting_mths;*/ // 20190613 DTL: replaced `crediting_mths`
		else 
			month = mod (t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`
			
		Average = index_val_avg_calc(t, month);
		cost_of_call_option_pct = bs_opt_val_levy_asian(K, tte, S, Average,sigma, rf, q) / K; 
		cost_of_call_option_cap_pct = bs_opt_val_levy_asian(K_cap, tte, S, Average,sigma_cap, rf, q) / K;

		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		
		if (crediting_dyn_lever == DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time	
			net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct);
		else if (crediting_dyn_lever == DYNAMIC_PARTICIPATION)	//WTW - Gen2 - character input that varies by time				
			net_opt_value = cost_of_call_option_pct * part_rate;
		else //Both cap and participation
			net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct)
							* part_rate;
		
		option_rate_num = net_opt_value * fund_val_b_bef(t);
		}
	else //WTW - Gen2 - Mutating Lookup Term - Change else if {} to else { if {}...}
	{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (crediting_rate_defn == MONTHLY_SUM_CAP)
		{
		double cap = crediting_cap_rate(t);
		
		if (mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/) == 0.0) // 20190613 DTL: replaced `crediting_mths`
			month = strategy_term_mths_aig(t); /*crediting_mths;*/  // 20190613 DTL: replaced `crediting_mths`
		else 
			month = mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/);  // 20190613 DTL: replaced `crediting_mths`

		double index_curr = 0;
		double index_prev = 0;
		double index_change_sum = 0;
		for (int i = 0; i < month; i++)
			{
			index_curr = index_val_calc(t - i);
			index_prev = index_val_calc(t - i - 1);
			log_strm<<" i: "<<i<<" index_prev: "<<index_prev<<endl;

			if (index_prev > 0) //need to set index_prev first			
				index_change_sum += min(cap, (index_curr / index_prev) - 1.0);
			}	

		cost_of_call_option_pct 
		= bs_opt_val_mthly_sum_cap(strategy_term_mths_aig(t) /*crediting_mths*/,  // 20190613 DTL: replaced `crediting_mths`
								   month,
								   index_change_sum,
								   cap,
								   tte,
								   rf,
								   q,
								   sigma,
								   NOMINAL_SEMIANNUAL,
								   EFFECTIVE_ANNUAL);

		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

		if (crediting_dyn_lever == DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time	
			net_opt_value = cost_of_call_option_pct;
		else if (crediting_dyn_lever == DYNAMIC_PARTICIPATION)	//WTW - Gen2 - character input that varies by time				
			net_opt_value = cost_of_call_option_pct * part_rate;
		else //Both cap and participation
			net_opt_value = cost_of_call_option_pct
							* part_rate;
		
		option_rate_num = net_opt_value * fund_val_b_bef(t);
		}
	else //if (crediting_rate_defn == FIXED_RATE)
		{
		fixed_rate = crediting_rate_fix(t);

		option_rate_num += fixed_rate * fund_val_b_bef(t);
		}
	}
}
return option_rate_num;

}


//@@ END

//@@ START - pfwd_surr_fund_val
// Penalty Free Withdrawal Fund Value                                                                                             
// Column:PFWD_SURR_FUND_VAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_pfwd_surr_fund_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(111,"pfwd_surr_fund_val",t);
}



//^^^

#line 1 "pfwd_surr_fund_val.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

double fund_val_base = fund_val_e_bef(t) * fia->surv_period(t);

double pfwd_surr_fund_val_cv =
		max(0.0, min(fund_val_base * fia->pfwd_rate_mthly_fund_val(t), fund_val_base));

return pfwd_surr_fund_val_cv;

}


//@@ END

//@@ START - prem_alloc
// Premium Allocated to Account (incl. Premium Bonus)                                                                                             
// Column:PREM_ALLOC
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_prem_alloc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"prem_alloc",t);
}



//^^^

#line 1 "prem_alloc.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period + 1/*maturity_period*/)
	return NO_AVG;

return fia->prem_paid(t) * fund_val_split_prop + prem_bonus(t);

}


//@@ END

//@@ START - prem_bonus
// Premium Bonus                                                                                             
// Column:PREM_BONUS
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"prem_bonus",t);
}



//^^^

#line 1 "prem_bonus.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period + 1/*maturity_period*/)
	return NO_AVG;

return fia->prem_paid(t) 
	   * fund_val_split_prop
	   * fia->prem_credit_pct_aig;	// DTL 20181105 : making this value table-driven

}


//@@ END

//@@ START - renew_into_2nd_strat_status_aig
// Status tracker for renewal into 2nd strategy                                                                                             
// Column:RENEW_INTO_2ND_STRAT_STATUS_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_renew_into_2nd_strat_status_aig(int t) {
//^^^



//^^^

#line 1 "renew_into_2nd_strat_status_aig.FIAAFUND_LIAB.for"
//20240529 MQ new column for tracking the status of renewal strategy
if (t < commencement_period || t > final_period || fia->crediting_type_dyn_2nd_strat_aig == "NA")
{
	return NO_AVG;
}

if (t == 0 && valn_period == 0)
	return 0;

if (t == 0 && valn_period != 0)
	return fia->renew_into_2nd_strat_status;

if (renew_into_2nd_strat_status_aig(t - 1) == 1)
{
	return 1.;
}

if (rila_knockout_status_bom_aig(t) >= 2 || rila_perf_lock_status_bom_aig(t) == 2)
{
	return 1.;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
xstring crediting_rate_type = fia->crediting_rate_type_aig;
if (crediting_rate_type == "Dynamic Par with Cap")
{
	return combo_strat_renew_status_crbg(t);
}

fia->pol_yr_lookup_gen2 = 1; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_strategy_term = strategy_term_duration_aig;

if (fia->renew_into_2nd_strat_defn_aig == YES && fia->pol_yr(t) > init_strategy_term)
{
	return 1.;
}

return 0.;



}


//@@ END

//@@ START - rila_buffer_amt_aig
// buffer amt                                                                                             
// Column:RILA_BUFFER_AMT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_buffer_amt_aig(int t) {
//^^^



//^^^

#line 1 "rila_buffer_amt_aig.FIAAFUND_LIAB.for"
//20240205 Add new column as buffer amount might change after strategy switching
if (t <= commencement_period || t > final_period)
	return NO_AVG;

double buffer_amt;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240529 MQ revised condition
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
	buffer_amt = fia->index_term_buffer_aig;

	return buffer_amt;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;
if(crediting_dyn_lever_local == "Dynamic Buffer") //20240319 MQ Knockout strategy uses different buffer input
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	return knockout_buffer_aig;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
buffer_amt = fia->index_term_buffer_aig;

return buffer_amt;

}


//@@ END

//@@ START - rila_init_opt_cost_by_grid_2nd_strat_aig
// Rila Init Opt Cost By Grid 2Nd Strat Aig                                                                                             
// Column:RILA_INIT_OPT_COST_BY_GRID_2ND_STRAT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_init_opt_cost_by_grid_2nd_strat_aig(int t) {
//^^^



//^^^

#line 1 "rila_init_opt_cost_by_grid_2nd_strat_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period)
	return 0;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;

if( fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_OFF && crediting_rate_type_local != "Dynamic Buffer" &&
	(fia->renew_into_2nd_strat_defn_aig == NO || fia->crediting_type_dyn_2nd_strat_aig == "NA"))
{
	return NO_AVG;	
}

if (t + elapsed_mths != 1)
{
	return 0.0;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return 0.0;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
double buffer_amt = fia->index_term_buffer_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double floor_amt = index_term_floor_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double par_down = fia->part_down_amt;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double par_up = fia->init_part_rate_index0;

fia->pol_yr_lookup_gen2 =  fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double strategy_months = strategy_term_duration_aig * 12.;

fia->pol_yr_lookup_gen2 =  fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double index_months = index_term_duration_aig * 12.;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double cap_rate = fia->init_cap_rate_index0;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
double trigger = fia->init_trigger_rate_index0_aig;;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
xstring crediting_dyn_lever_local = fia->crediting_rate_type_aig;

double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
double initial_option_price_time = current_strategy_period * strategy_months;

const double FWD_TERM	= 0.0;
double rf_rate_cv = 0.0;
double long_call_option_cost = 0.0;
double long_put_option_cost = 0.0;
double short_call_option_cost = 0.0;
double short_put_option_cost = 0.0;
double option_cost = 0.0;

if (fia->gen2_defn == YES)
{
	rf_rate_cv	= fia_rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_months, FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  // 20201014 DTL
}
else
{
	rf_rate_cv	= rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_months, FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  // 20201014 DTL
}

if (buffer_amt != 0)
{
	if (crediting_dyn_lever_local == "Dynamic Cap")
	{
		//Buffer Cap Strategy
		long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_call_option_cost		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_call_option_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic Trigger")
	{
		//Buffer Trigger Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_months));
				
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
		double option_cost_one_percent = 0.0;
		if (fia->gen2_defn == YES)
			option_cost_one_percent = fia_rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			option_cost_one_percent = rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_binary_opt_cost	= trigger * option_cost_one_percent;
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_binary_opt_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
	{
		//Buffer Dual Direction Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_months));
		int buffer_key = (1 - buffer_amt) * 100;
		string buffer_str = "_K" + to_string(buffer_key);
		
		string rate_lookup = "BINY_" + index_id_regex_str + "_" + option_duration_str + buffer_str;
				
		double option_cost_1minusbuffer = 0.0;
		if (fia->gen2_defn == YES)
			option_cost_1minusbuffer = fia_rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			option_cost_1minusbuffer = rates->get_misc_rate(0, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_binary_opt_cost = buffer_amt * option_cost_1minusbuffer;

		double long_atm_call		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		double short_otm_call		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
		double short_otm_put		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);	
		double short_itm_call		= get_option_price_aig(t - 1, 1 - buffer_amt, CALL, strategy_months, index_months);
		
		option_cost					= 2 * long_atm_call - short_otm_call - short_otm_put - short_itm_call + long_binary_opt_cost;
	}
	else
	{
		//Buffer Par Up Strategy
		long_call_option_cost		= par_up * get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_put_option_cost;
	}
}
else if (crediting_dyn_lever_local == "Dynamic Cap")
{
	//Floor Cap Strategy
	long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
	short_call_option_cost		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
	long_put_option_cost		= get_option_price_aig(t - 1, 1 + floor_amt, PUT, strategy_months, index_months);
	short_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_call_option_cost + long_put_option_cost - short_put_option_cost;
}
else
{
	//Par up Par down strategy
	long_call_option_cost		= par_up * get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
	short_put_option_cost		= par_down * get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_put_option_cost;
}

return option_cost;

}


//@@ END

//@@ START - rila_int_val_beg_term_bom_aig
// Interim Value at beginning of the term                                                                                             
// Column:RILA_INT_VAL_BEG_TERM_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_int_val_beg_term_bom_aig(int t) {
//^^^



//^^^

#line 1 "rila_int_val_beg_term_bom_aig.FIAAFUND_LIAB.for"
//20240528 MQ New column
if (t <= commencement_period || t > final_period)
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
	{
		return rila_interim_value_b_aig(t);
	}
	else
	{
		return rila_int_val_beg_term_eom_aig(t - 1);
	}

}

}


//@@ END

//@@ START - rila_int_val_beg_term_eom_aig
// Interim Value at beginning of the term                                                                                             
// Column:RILA_INT_VAL_BEG_TERM_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_int_val_beg_term_eom_aig(int t) {
//^^^



//^^^

#line 1 "rila_int_val_beg_term_eom_aig.FIAAFUND_LIAB.for"
//20240528 MQ New column
if (t < commencement_period || t > final_period)
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	if(t == 0 && valn_period > 0)
	{
		return fia->inner_interim_val_beg_term;
	}
	else
	{
		return rila_int_val_beg_term_bom_aig(t) * fia->surv_period(t);
	}

}

}


//@@ END

//@@ START - rila_interim_value_b_aig
// Interim Value b after charge                                                                                             
// Column:RILA_INTERIM_VALUE_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_b_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_b_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period)
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 1)
	{
		//Reset interim value to BOP fund value after charge
		return fund_val_b(t);
	}
	else
	{
		double interim_value = rila_interim_value_e_aig(t - 1);

		double fees_and_charges = admin_fee(t) + gmwb_chg(t) + fia->rop_chg_aig(t) + tier_strat_fee_aig(t);

		if(interim_value < SMALL_DOUBLE)
			return 0.0;

		double portion_reduced_fee = fees_and_charges / interim_value;

		//This is the same as interim_value - fees_and_charges.
		interim_value = interim_value * (1 - portion_reduced_fee);

		return interim_value;

	}

}

}


//@@ END

//@@ START - rila_interim_value_dapv_e_aig
// Interim Value                                                                                             
// Column:RILA_INTERIM_VALUE_DAPV_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_dapv_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_dapv_e_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}
else
{
	//Calculate interim value based on changes in option price etc before crediting interest
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	double portion_remaining_time = 1 - strategy_term_elapsed_pct_eom_aig(t);

	double option_portfolio_value_current = 0.0;

	double interim_value = rila_interim_value_e_bef_aig(t) * fia->surv_period(t);

	if(interim_value < SMALL_DOUBLE)
		return 0.0;
		
	double portion_reduced = (fund_released_withdrl(t) + fund_released_maturity(t)) / interim_value;

	if ((t + valn_period) != 0 && valn_flag)
	{
		option_portfolio_value_current = rila_opt_cost_bs_e_aig(t);
	}
	else
	{
		option_portfolio_value_current = rila_opt_cost_by_grid_e_aig(t);
	}

	// 20240327 MQ Add logic for knockout strategy
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
	if(crediting_rate_type_local == "Dynamic Buffer" && rila_knockout_status_eom_aig(t) == 0)
	{
		option_portfolio_value_current = rila_knockout_cost_interim_val_e_aig(t);
	}

	if (rila_knockout_status_eom_aig(t) == 1 || portion_remaining_time < SMALL_DOUBLE) 
	{
		return rila_interim_value_fiapv_e_aig(t) * strategy_return_index_aig(t);
	}

	else
	{
		double RILA_Base = rila_strat_base_b_aig(t);

		double DAPV_Current = RILA_Base * option_portfolio_value_current;//current price of options

		return DAPV_Current * fia->surv_period(t) * (1 - portion_reduced);
	}	
	
}
	

}


//@@ END

//@@ START - rila_interim_value_e_aig
// Interim Value eom, after survivorship and wd                                                                                             
// Column:RILA_INTERIM_VALUE_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_e_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2.0- refined time guards
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	//RILA implementation
	if (t == 0 && valn_period == 0)
	{
		double interim_value = fia->single_prem;
		return interim_value;
	}
	else if (t == 0 && valn_period != 0)
	{
		double interim_value = fia->init_interim_value;
		return interim_value;
	}
	else
	{
		double interim_value = rila_interim_value_e_bef_aig(t) * fia->surv_period(t);

		if(interim_value < SMALL_DOUBLE)
			return 0.0;
		
		double portion_reduced = (fund_released_withdrl(t) + fund_released_maturity(t)) / interim_value; //20240212 MQ include maturity benefit

		//This is the same as interim_value - fund_released_withdrl.
		interim_value = max(0., interim_value * (1 - portion_reduced));

		return interim_value;

	}

}

}


//@@ END

//@@ START - rila_interim_value_e_bef_aig
// Interim Value                                                                                             
// Column:RILA_INTERIM_VALUE_E_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_e_bef_aig.FIAAFUND_LIAB.for"
//Interim value calculation
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}
else
{
	//Calculate interim value based on changes in option price etc before crediting interest
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	// 20241018 After performance lock
	if (rila_perf_lock_status_bom_aig(t) == 1) 
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double perf_lock_fixed = perf_lock_fixed_rt_aig;

		if (renew_into_2nd_strat_status_aig(t) == 1) 
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig; 
			perf_lock_fixed = perf_lock_fixed_rt_aig;
		}		
		
		return rila_interim_value_b_aig(t) * pow(1 + perf_lock_fixed, 1. / 12.);
	}

	double portion_remaining_time = 1 - strategy_term_elapsed_pct_eom_aig(t);
	double initial_option_price = 0.0;
	double option_portfolio_value_current = 0.0;

	if ((t + valn_period) != 0 && valn_flag)
	{
		option_portfolio_value_current = rila_opt_cost_bs_e_aig(t);
		initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
	}
	else
	{
		option_portfolio_value_current = rila_opt_cost_by_grid_e_aig(t);
		initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
	}

	// 20240327 MQ Add logic for knockout strategy
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
	if(crediting_rate_type_local == "Dynamic Buffer" && rila_knockout_status_eom_aig(t) == 0)
	{
		initial_option_price = rila_knockout_cost_interim_val_init_aig(t);
		option_portfolio_value_current = rila_knockout_cost_interim_val_e_aig(t);
	}

	if (rila_knockout_status_eom_aig(t) == 1 && rila_knockout_status_bom_aig(t) == 0) 
	{
		return rila_strat_base_b_aig(t) * (1 + strategy_return_index_aig(t));
	}
	else if (rila_knockout_status_eom_aig(t) == 1) 
	{
		return rila_interim_value_b_aig(t) * (1 + strategy_return_index_aig(t));
	}

	if (portion_remaining_time < SMALL_DOUBLE) 
	{
		// align with calculated strategy return 
		double target_fund_value = rila_strat_base_b_aig(t) * (1 + strategy_return_index_aig(t));
		return target_fund_value;
	}
	else
	{
		return interim_value_calc_aig(t, portion_remaining_time, initial_option_price, option_portfolio_value_current);
	}	
	
}
	

}


//@@ END

//@@ START - rila_interim_value_fiapv_e_aig
// Interim Value                                                                                             
// Column:RILA_INTERIM_VALUE_FIAPV_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_fiapv_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_fiapv_e_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}
else
{
	//Calculate interim value based on changes in option price etc before crediting interest
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		StrEnum::EnumValue crediting_rate_defn_local = this->crediting_rate_defn;
		if ( crediting_rate_defn_local == FIXED_RATE )
		{
			return fund_val_e(t);
		}
		else
		{
			return 0.0;
		}
	}

	double portion_remaining_time = 1 - strategy_term_elapsed_pct_eom_aig(t);

	double initial_option_price = 0.0;

	double interim_value = rila_interim_value_e_bef_aig(t) * fia->surv_period(t);

	if(interim_value < SMALL_DOUBLE)
		return 0.0;
		
	double portion_reduced = (fund_released_withdrl(t) + fund_released_maturity(t)) / interim_value;

	if ((t + valn_period) != 0 && valn_flag)
	{
		initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
	}
	else
	{
		initial_option_price = rila_opt_cost_beg_strat_term_aig(t);
	}

	// 20240327 MQ Add logic for knockout strategy
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
	if(crediting_rate_type_local == "Dynamic Buffer" && rila_knockout_status_eom_aig(t) == 0)
	{
		initial_option_price = rila_knockout_cost_interim_val_init_aig(t);
	}

	if (rila_knockout_status_eom_aig(t) == 1)
	{
		return max(0, rila_interim_value_b_aig(t) * fia->surv_period(t) * (1 - portion_reduced));
	}

	double RILA_Base = rila_strat_base_b_aig(t);

	double DAPV_Initial = RILA_Base * initial_option_price;

	return max(0, (RILA_Base - DAPV_Initial * portion_remaining_time) * fia->surv_period(t) * (1 - portion_reduced));
	
}
	

}


//@@ END

//@@ START - rila_interim_value_growth_aig
// Interim Value Growth                                                                                             
// Column:RILA_INTERIM_VALUE_GROWTH_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_growth_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_growth_aig.FIAAFUND_LIAB.for"
if(t < commencement_period || t > final_period)
{
	return 0.0;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return 0.0;

//Return the EOM interim value over the BOM interim value
if (rila_interim_value_e_bef_aig(t) < model_point_amount_threshold || rila_interim_value_b_aig(t) < model_point_amount_threshold)
{
	return 0.0;
}
else
{
	return rila_interim_value_e_bef_aig(t) / rila_interim_value_b_aig(t) - 1;
}

}


//@@ END

//@@ START - rila_interim_value_tc_e_aig
// Interim Value                                                                                             
// Column:RILA_INTERIM_VALUE_TC_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_tc_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_interim_value_tc_e_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}
else
{
	//Calculate interim value based on changes in option price etc before crediting interest
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	double portion_remaining_time = 1 - strategy_term_elapsed_pct_eom_aig(t);

	if (rila_knockout_status_eom_aig(t) == 1 || portion_remaining_time < SMALL_DOUBLE) 
	{
		return 0;
	}

	else
	{
		double trading_cost = rila_trading_cost_pct_eom_aig(t); //20240528 MQ update to trading cost

		return fabs(rila_interim_value_dapv_e_aig(t)) * trading_cost;
	}	
	
}
	

}


//@@ END

//@@ START - rila_knockout_cost_interim_val_e_aig
// Knockout strategy option cost for interim val                                                                                             
// Column:RILA_KNOCKOUT_COST_INTERIM_VAL_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_cost_interim_val_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_knockout_cost_interim_val_e_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column: For option cost used in interim val calculation, rebate = knockout rate
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer")
{
	return NO_AVG;
}

if(rila_knockout_status_eom_aig(t) != 0)
{
	return 0.;
}

double buffer_amt = rila_buffer_amt_aig(t);

double option_cost;

if(pba_valn_flag)
{
	double strategy_months = 12.0 * strategy_term_aig(t);
	double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
	double initial_option_price_time = current_strategy_period * strategy_months;
	double portion_remaining_time = 1 - (t + elapsed_mths - initial_option_price_time)/strategy_months;

	if(t == 0)
	{
		portion_remaining_time = 1.0;
		initial_option_price_time = t + elapsed_mths;
	}

	if (portion_remaining_time < SMALL_DOUBLE)
		return 0.;

	double rf_rate_cv = 0.0;
	const double FWD_TERM	= 0.0;

	double vol_param = 0.0; 
	double dividend_yld = 0.0; 

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_eqt_index_local = crediting_eqt_index;

	fia->bs_init_vol_type = "base";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_param = fia->bs_fwrd_vol_aig;

	fia->index_id_lookup = crediting_eqt_index_local;
	dividend_yld = exp(fia->dividend_inner_aig) - 1.;

	rf_rate_cv	= rates->get_int_rate(t, "Govt", GET_SPOT_RATE, strategy_term_aig(t), FWD_TERM, NOMINAL_SEMIANNUAL, NO_SHIFT);

	double spot_price = 0.0;
	spot_price = index_val(t) / index_term_beginning_index_val_bom_aig(t);  //20240422

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double knockout_threshold = knockout_threshold_aig;

	double rebate = knockout_threshold;

	double knockout_call = barrier_up_and_out_opt_val_aig(spot_price, 1, rebate, 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, CALL_CODE);
	double knockout_put  = barrier_up_and_out_opt_val_aig(spot_price, 1 - buffer_amt, 0., 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, PUT_CODE);
			
	option_cost	 = knockout_call - knockout_put;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double knockout_threshold = knockout_threshold_aig;

	int knockout_key = (1 + knockout_threshold) * 100;

	double rebate = knockout_threshold;
		
	double long_call_option_cost = get_option_price_aig(t, 1 + rebate, CALLK, strategy_term_mths_aig(t), index_term_mths_aig(t), knockout_key);
	double short_put_option_cost = get_option_price_aig(t, 1 - buffer_amt, PUTK, strategy_term_mths_aig(t), index_term_mths_aig(t), knockout_key);
	option_cost					 = long_call_option_cost - short_put_option_cost;
}

return option_cost;



}


//@@ END

//@@ START - rila_knockout_cost_interim_val_init_aig
// Knockout strategy option cost for interim val at the beginning                                                                                             
// Column:RILA_KNOCKOUT_COST_INTERIM_VAL_INIT_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_cost_interim_val_init_aig(int t) {
//^^^



//^^^

#line 1 "rila_knockout_cost_interim_val_init_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column: For option cost used in interim val calculation, rebate = knockout rate
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer")
{
	return NO_AVG;
}

if(rila_knockout_status_eom_aig(t) != 0)
{
	return 0.;
}

//Only the value at beginning of the term is needed.
if(valn_period != 0)
	return fia->knockout_cost_interim_val_init;

if(t + elapsed_mths != 1)
	return rila_knockout_cost_interim_val_init_aig(t - 1);

double buffer_amt = rila_buffer_amt_aig(t);

double option_cost;

if(pba_valn_flag)
{
	double vol_param = 0.0; 
	double dividend_yld = 0.0; 

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_eqt_index_local = crediting_eqt_index;

	fia->bs_init_vol_type = "base";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_param = fia->bs_fwrd_vol_aig;

	fia->index_id_lookup = crediting_eqt_index_local;
	dividend_yld = exp(fia->dividend_inner_aig) - 1.;

	double rf_rate_cv	= rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, strategy_term_aig(t), 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);

	double spot_price = 1.; 

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double knockout_threshold = knockout_threshold_aig;

	double rebate = knockout_threshold;

	double knockout_call = barrier_up_and_out_opt_val_aig(spot_price, 1, rebate, 1 + knockout_threshold, strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, CALL_CODE);
	double knockout_put  = barrier_up_and_out_opt_val_aig(spot_price, 1 - buffer_amt, 0., 1 + knockout_threshold, strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, PUT_CODE);
			
	option_cost	 = knockout_call - knockout_put;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double knockout_threshold = knockout_threshold_aig;

	int knockout_key = (1 + knockout_threshold) * 100;

	double rebate = knockout_threshold;
		
	double long_call_option_cost = get_option_price_aig(t - 1, 1 + rebate, CALLK, strategy_term_mths_aig(t), index_term_mths_aig(t), knockout_key);
	double short_put_option_cost = get_option_price_aig(t - 1, 1 - buffer_amt, PUTK, strategy_term_mths_aig(t), index_term_mths_aig(t), knockout_key);
	option_cost					 = long_call_option_cost - short_put_option_cost;
}

return option_cost;



}


//@@ END

//@@ START - rila_knockout_mth_aig
// policy month when knockout occurs                                                                                             
// Column:RILA_KNOCKOUT_MTH_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_mth_aig(int t) {
//^^^



//^^^

#line 1 "rila_knockout_mth_aig.FIAAFUND_LIAB.for"
//20240423 MQ new column 
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer")
{
	return NO_AVG;
}

if (t == 0 && valn_period != 0)
	return fia->knockout_mth;

if(t + elapsed_mths == 0)
	return 9999;
				
if (rila_knockout_status_eom_aig(t) == 1 && rila_knockout_status_eom_aig(t - 1) == 0) //hit knockout rate
{ 
	return t + elapsed_mths;
}

return rila_knockout_mth_aig(t - 1);



}


//@@ END

//@@ START - rila_knockout_status_bom_aig
// Status tracker for the knockout strategy                                                                                             
// Column:RILA_KNOCKOUT_STATUS_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_status_bom_aig(int t) {
//^^^



//^^^

#line 1 "rila_knockout_status_bom_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for tracking the status of Knockout strategy
if (t <= commencement_period || t > final_period || fia->valn_deterministic_flag_crbg)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer")
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;
if(crediting_dyn_lever_local != "Dynamic Buffer") //After renewing into second stratey
{
	return 3.;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double reallocation_anniversary = knockout_realloc_yr_aig;   
double yr_bef_realloc = floor(rila_knockout_mth_aig(t - 1) / 12) + reallocation_anniversary;

if(strategy_term_elapsed_mths_eom_aig(t - 1) >= yr_bef_realloc * 12 && rila_knockout_status_eom_aig(t - 1) == 1) //After reallocation
{
	return 2.;
}

return rila_knockout_status_eom_aig(t - 1);



}


//@@ END

//@@ START - rila_knockout_status_eom_aig
// Status tracker for the knockout strategy                                                                                             
// Column:RILA_KNOCKOUT_STATUS_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_status_eom_aig(int t) {
//^^^



//^^^

#line 1 "rila_knockout_status_eom_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for tracking the status of Knockout strategy
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer")
{
	return NO_AVG;
}

if (t == 0 && valn_period != 0)
	return fia->knockout_status_ind;

if(t + elapsed_mths == 0)
	return 0.;

if(rila_knockout_status_bom_aig(t) > 0)
	return rila_knockout_status_bom_aig(t);

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double knockout_threshold = knockout_threshold_aig;    

if (index_term_index_return_aig(t) >= knockout_threshold) //index return hits the barrier
{ 
	return 1.;
}

double option_value, barrier;

if(pba_valn_flag) //20240603 use brownian bridge for inner loop
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	barrier = knockout_rebate_aig;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double perf_lock_fixed = perf_lock_fixed_rt_aig;

	if (rila_smax_brownian_bridge_aig(t) > (1 + knockout_threshold) * index_term_beginning_index_val_bom_aig(t))
	{
		option_value = barrier * pow(1 + perf_lock_fixed, 1./24.); 
	}
	else
	{
		option_value = rila_opt_cost_bs_e_aig(t);
	}
}
else //outer loop
{
	barrier = knockout_threshold - 0.00001;
	option_value = rila_opt_cost_by_grid_e_aig(t);
}
				
if (option_value >= barrier) //option value hits the barrier
{ 
	return 1.;
}

return rila_knockout_status_bom_aig(t);



}


//@@ END

//@@ START - rila_opt_cost_beg_strat_term_aig
// Rila Opt Cost Beg Strat Term Aig                                                                                             
// Column:RILA_OPT_COST_BEG_STRAT_TERM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_beg_strat_term_aig(int t) {
//^^^



//^^^

#line 1 "rila_opt_cost_beg_strat_term_aig.FIAAFUND_LIAB.for"
//20240318 MQ new column
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}
else
{
	if (t == 0 && valn_period != 0)
	{
		return fia->inner_opt_cost_beg_term;
	}

	if ( abs(strategy_term_elapsed_mths_eom_aig(t) - 1.0) < SMALL_DOUBLE )
	{
		if(pba_valn_flag)
			return rila_opt_cost_bs_b_aig(t);
		else
			return rila_opt_cost_by_grid_b_aig(t);
	}
	else
	{
		return rila_opt_cost_beg_strat_term_aig(t - 1);
	}
}

}


//@@ END

//@@ START - rila_opt_cost_bs_b_aig
// Rila Opt Cost Bs B Aig                                                                                             
// Column:RILA_OPT_COST_BS_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_bs_b_aig(int t) {
//^^^



//^^^

#line 1 "rila_opt_cost_bs_b_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period || !valn_flag )
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

//20240918 MQ option sold after performance lock
if(rila_perf_lock_status_bom_aig(t) == 1) 
{
	return 0.;
}

if (rila_ind)
{
	double buffer_amt = rila_buffer_amt_aig(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double floor_amt = index_term_floor_aig;
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double par_down = fia->part_down_amt;
	double par_up = crediting_part_rate_aig(t);
	double cap_rate = crediting_cap_rate(t);
	double trigger = crediting_trigger_rate_aig(t);

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_dyn_lever_local = crediting_dyn_lever;

	if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		crediting_dyn_lever_local = crediting_dyn_lever;
	}

	double strategy_months = 12.0 * strategy_term_aig(t);
	int index_months = index_term_mths_aig(t);

	double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
	double initial_option_price_time = current_strategy_period * strategy_months;
	double portion_remaining_time = 1 - (t + elapsed_mths - initial_option_price_time - 1)/strategy_months;

	double beg_index_term_mth = t + elapsed_mths - index_term_elapsed_mths_eom_aig(t);
	double curr_price_index_term;

	if (portion_remaining_time < SMALL_DOUBLE)
		return 0.;

	double rf_rate_cv = 0.0;
	const double FWD_TERM	= 0.0;

	double vol_param = 0.0; 
	double dividend_yld = 0.0; 

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_eqt_index_local = crediting_eqt_index;

	fia->bs_init_vol_type = "base";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_param = fia->bs_fwrd_vol_aig;

	fia->index_id_lookup = crediting_eqt_index_local;
	dividend_yld = exp(fia->dividend_inner_aig) - 1.;

	if (fia->gen2_defn == YES) //20240321 MQ use spot rate
	{
		rf_rate_cv  = fia_rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, portion_remaining_time * strategy_term_aig(t), FWD_TERM, NOMINAL_SEMIANNUAL, NO_SHIFT);
	}
	else
	{
		rf_rate_cv	= rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, portion_remaining_time * strategy_term_aig(t), FWD_TERM, NOMINAL_SEMIANNUAL, NO_SHIFT);
	}

	double spot_price = index_val(t - 1) / index_term_beginning_index_val_bom_aig(t);  //20240422 MQ Simplify logic

	if (buffer_amt != 0)
	{
	//BufferStrategy
		if (crediting_dyn_lever_local == "Dynamic Cap") //Buffer Cap Strategy
		{
			double long_call_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_call_current_value - short_put_current_value;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Trigger") //Buffer Trigger Strategy
		{			
			//20240923 Updated binary option formula
			double call_k_pos = bs_opt_val(1. + fia->binary_strike_sprd_pos, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double call_k_neg = bs_opt_val(1. - fia->binary_strike_sprd_neg, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);			
			double binary_call_value = (call_k_neg - call_k_pos) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = trigger * binary_call_value - short_put_current_value;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic DualDir Tri") //Buffer Dual Direction Trigger Cap Strategy
		{

			double long_otm_call = bs_opt_val(1 + buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_otm_call = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_otm_put = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double binary_strike_sprd = 0.01;
			double itm_binary_call = bs_opt_val(1 - buffer_amt - binary_strike_sprd, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			itm_binary_call -= bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			itm_binary_call /= binary_strike_sprd;		
			
			double otm_binary_call = bs_opt_val(1 + buffer_amt - binary_strike_sprd, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			otm_binary_call -= bs_opt_val(1 + buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			otm_binary_call /= binary_strike_sprd;
	
			double option_cost	= trigger * itm_binary_call + (buffer_amt - trigger) * otm_binary_call + long_otm_call - short_otm_call - short_otm_put;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic DualDir Cap") //Buffer Dual Direction Cap Strategy
		{

			double long_call_current_value = bs_opt_val(1., portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);			
			double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);			
			double long_put_current_value = bs_opt_val(1., portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			//20240923 Updated binary option formula
			double put_k_pos = bs_opt_val(1 - buffer_amt + fia->binary_strike_sprd_pos, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			double put_k_neg = bs_opt_val(1 - buffer_amt - fia->binary_strike_sprd_neg, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);		
			double binary_put_value = (put_k_pos - put_k_neg) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
	
			double option_cost	= long_call_current_value - short_call_current_value + long_put_current_value - 2 * short_put_current_value
									 - buffer_amt  * binary_put_value;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Secure Cap") //20240422 MQ Secure Cap Strategy new formula
		{
			double price_zcb = 1 / pow(1 + rf_rate_cv / 2., portion_remaining_time * strategy_term_aig(t) * 2.);

			//The logic below is equivalent to G(t_0,t_(m-1)) as defined in the RSD	
			double cumulated_realized_return = 1 + strategy_return_prior_index_term_aig(t);
			
			double time_to_anniversary = (12. - mod(t + elapsed_mths - 1., 12.)) / 12.; 
			double curr_price_index_term = index_val(t - 1) / index_term_beginning_index_val_bom_aig(t);
			double current_term_return = 1 + secure_cap_base_opt_price_aig(curr_price_index_term, time_to_anniversary, vol_param, 
											rf_rate_cv, dividend_yld, 1, 1 + cap_rate, 1 - buffer_amt);

			if(mod(t + elapsed_mths, 12.) == 1)
			{
				time_to_anniversary = 0.;
				current_term_return = 0.;
			}

			double option_cost = secure_cap_final_opt_val_aig(cap_rate, buffer_amt, portion_remaining_time, strategy_term_aig(t),
							vol_param, rf_rate_cv, dividend_yld, price_zcb, cumulated_realized_return, current_term_return);
	
			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Buffer") //20240319 MQ Daily Knockout Strategy
		{			
			if(rila_knockout_status_bom_aig(t) == 1) 
			{
				return 0.;
			}

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double knockout_threshold = knockout_threshold_aig;

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double rebate = knockout_threshold_aig; //knockout_rebate_aig;

			double knockout_call = barrier_up_and_out_opt_val_aig(spot_price, 1, rebate, 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, CALL_CODE);
			double knockout_put  = barrier_up_and_out_opt_val_aig(spot_price, 1 - buffer_amt, 0., 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, PUT_CODE);
			
			double option_cost	 = knockout_call - knockout_put;

			int beg_term = ceil(strategy_term_elapsed_mths_eom_aig(t) / 12.);

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double add_rebate_per_yr = knockout_rebate_opt_bdgt_aig;

			for (int i = beg_term; i < strategy_months / 12; i++)
			{
				double digital_opt_cost;

				double yr_to_maturity = i - (1 - portion_remaining_time) * strategy_term_aig(t);

				digital_opt_cost = barrier_up_out_digital_opt_val_aig(spot_price, add_rebate_per_yr, 1 + knockout_threshold, yr_to_maturity, vol_param, rf_rate_cv, dividend_yld);

				option_cost += digital_opt_cost;
			}

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Par with Cap" || crediting_dyn_lever_local == "Dynamic Cap with Par") 
		{
			//20250812 Revised formula
			double long_call_current_value  = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_call_current_value = par_up * bs_opt_val(1 + cap_rate / par_up, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_put_current_value  = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_call_current_value - short_put_current_value;

			return option_cost;
		}		
		
		else
		{
			//Buffer Par Up Strategy
			double long_call_current_value = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_put_current_value;
				
			return option_cost;
		}
	}
	else if (crediting_dyn_lever_local == "Dynamic Cap")
	{
		//Floor Cap Strategy
		double long_call_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double long_put_current_value = bs_opt_val(1 + floor_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_put_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
				
		double option_cost = long_call_current_value - short_call_current_value + long_put_current_value - short_put_current_value;

		return option_cost;

	}
	else if (crediting_dyn_lever_local == "Dynamic Participation")
	{
		//Par up Par down strategy
		double long_call_current_value = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_put_current_value = par_down * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
				
		double option_cost = long_call_current_value - short_put_current_value;
		
		return option_cost;
	}

}

return 0.;

}


//@@ END

//@@ START - rila_opt_cost_bs_e_aig
// Rila Opt Cost Bs E Aig                                                                                             
// Column:RILA_OPT_COST_BS_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_bs_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_opt_cost_bs_e_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period || !valn_flag )
	return NO_AVG;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

//20240918 MQ option sold after performance lock
if(rila_perf_lock_status_bom_aig(t) == 1) 
{
	return 0.;
}

if (rila_ind)
{
	double buffer_amt = rila_buffer_amt_aig(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
	double floor_amt = index_term_floor_aig;
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double par_down = fia->part_down_amt;
	double par_up = crediting_part_rate_aig(t);
	double cap_rate = crediting_cap_rate(t);
	double trigger = crediting_trigger_rate_aig(t);

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_dyn_lever_local = crediting_dyn_lever;

	if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		crediting_dyn_lever_local = crediting_dyn_lever;
	}

	double strategy_months = 12.0 * strategy_term_aig(t);
	int index_months = index_term_mths_aig(t);

	double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
	double initial_option_price_time = current_strategy_period * strategy_months;
	double portion_remaining_time = 1 - (t + elapsed_mths - initial_option_price_time)/strategy_months;

	if(t == 0)
	{
		portion_remaining_time = 1.0;
		initial_option_price_time = t + elapsed_mths;
	}

	if (portion_remaining_time < SMALL_DOUBLE)
		return 0.;

	double rf_rate_cv = 0.0;
	const double FWD_TERM	= 0.0;

	double vol_param = 0.0; 
	double dividend_yld = 0.0; 

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_eqt_index_local = crediting_eqt_index;

	fia->bs_init_vol_type = "base";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_param = fia->bs_fwrd_vol_aig;

	fia->index_id_lookup = crediting_eqt_index_local;
	dividend_yld = exp(fia->dividend_inner_aig) - 1.;

	if (fia->gen2_defn == YES) //20240321 MQ use spot rate
	{
		rf_rate_cv  = fia_rates->get_int_rate(t, "Govt", GET_SPOT_RATE, portion_remaining_time * strategy_term_aig(t), FWD_TERM, NOMINAL_SEMIANNUAL, NO_SHIFT);
	}
	else
	{
		rf_rate_cv	= rates->get_int_rate(t, "Govt", GET_SPOT_RATE, portion_remaining_time * strategy_term_aig(t), FWD_TERM, NOMINAL_SEMIANNUAL, NO_SHIFT);
	}

	double spot_price = index_val(t) / index_term_beginning_index_val_bom_aig(t);  //20240422 MQ. Simpliy logic

	if (buffer_amt != 0)
	{
	//BufferStrategy
		if (crediting_dyn_lever_local == "Dynamic Cap")
		{
			//Buffer Cap Strategy
			double long_call_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_call_current_value - short_put_current_value;
				
			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Trigger") //Buffer Trigger Strategy
		{
			//20240923 Updated binary option formula
			double call_k_pos = bs_opt_val(1. + fia->binary_strike_sprd_pos, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double call_k_neg = bs_opt_val(1. - fia->binary_strike_sprd_neg, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);		
			double binary_call_value = (call_k_neg - call_k_pos) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = trigger * binary_call_value - short_put_current_value;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic DualDir Tri") //Buffer Dual Direction Trigger Cap Strategy
		{

			double long_otm_call = bs_opt_val(1 + buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_otm_call = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_otm_put = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double binary_strike_sprd = 0.01;
			double itm_binary_call = bs_opt_val(1 - buffer_amt - binary_strike_sprd, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			itm_binary_call -= bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			itm_binary_call /= binary_strike_sprd;		
			
			double otm_binary_call = bs_opt_val(1 + buffer_amt - binary_strike_sprd, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			otm_binary_call -= bs_opt_val(1 + buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);	
			otm_binary_call /= binary_strike_sprd;				
	
			double option_cost	= trigger * itm_binary_call + (buffer_amt - trigger) * otm_binary_call + long_otm_call - short_otm_call - short_otm_put;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic DualDir Cap") //Buffer Dual Direction Cap Strategy
		{

			double long_call_current_value = bs_opt_val(1., portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);			
			double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);			
			double long_put_current_value = bs_opt_val(1., portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			//20240923 Updated binary option formula
			double put_k_pos = bs_opt_val(1 - buffer_amt + fia->binary_strike_sprd_pos, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			double put_k_neg = bs_opt_val(1 - buffer_amt - fia->binary_strike_sprd_neg, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			double binary_put_value = (put_k_pos - put_k_neg) / (fia->binary_strike_sprd_pos + fia->binary_strike_sprd_neg);

			double option_cost	= long_call_current_value - short_call_current_value + long_put_current_value - 2 * short_put_current_value
									 - buffer_amt * binary_put_value;

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Secure Cap") //20240422 MQ Secure Cap Strategy new formula
		{
			double price_zcb = 1 / pow(1 + rf_rate_cv / 2., portion_remaining_time * strategy_term_aig(t) * 2.);

			//The logic below is equivalent to G(t_0,t_(m-1)) as defined in the RSD		
			double cumulated_realized_return = 1 + strategy_return_prior_index_term_eom_aig(t);

			double time_to_anniversary = (12. - mod(t + elapsed_mths, 12.)) / 12.; 
			double curr_price_index_term = index_val(t) / index_term_beginning_index_val_bom_aig(t);		
			double current_term_return = 1 + secure_cap_base_opt_price_aig(curr_price_index_term, time_to_anniversary, vol_param, 
											rf_rate_cv, dividend_yld, 1, 1 + cap_rate, 1 - buffer_amt);			

			if(mod(t + elapsed_mths, 12.) == 0)
			{
				time_to_anniversary = 0.;
				current_term_return = 0.;
			}

			if(mod(t + elapsed_mths, 12.) == 0)
			{
				current_term_return = 1.;
			}	

			double option_cost = secure_cap_final_opt_val_aig(cap_rate, buffer_amt, portion_remaining_time, strategy_term_aig(t),
							vol_param, rf_rate_cv, dividend_yld, price_zcb, cumulated_realized_return, current_term_return);

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Buffer") //20240319 MQ Daily Knockout Strategy
		{			
			if(rila_knockout_status_bom_aig(t) == 1) //The evaluation of knockout_status_eom now depends on rila_opt_cost_bs_e_aig.
			{
				return 0.;
			}

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double knockout_threshold = knockout_threshold_aig;

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double rebate = knockout_threshold_aig; //knockout_rebate_aig;

			double knockout_call = barrier_up_and_out_opt_val_aig(spot_price, 1, rebate, 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, CALL_CODE);
			double knockout_put  = barrier_up_and_out_opt_val_aig(spot_price, 1 - buffer_amt, 0., 1 + knockout_threshold, portion_remaining_time * strategy_term_aig(t), vol_param, rf_rate_cv, dividend_yld, PUT_CODE);
			
			double option_cost	 = knockout_call - knockout_put;

			int beg_term = ceil((strategy_term_elapsed_mths_eom_aig(t) + 1) / 12.);

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double add_rebate_per_yr = knockout_rebate_opt_bdgt_aig;

			for (int i = beg_term; i < strategy_months / 12; i++)
			{
				double digital_opt_cost;

				double yr_to_maturity = i - (1 - portion_remaining_time) * strategy_term_aig(t);

				digital_opt_cost = barrier_up_out_digital_opt_val_aig(spot_price, add_rebate_per_yr, 1 + knockout_threshold, yr_to_maturity, vol_param, rf_rate_cv, dividend_yld);

				option_cost += digital_opt_cost;
			}

			return option_cost;
		}
		else if (crediting_dyn_lever_local == "Dynamic Par with Cap" || crediting_dyn_lever_local == "Dynamic Cap with Par") 
		{
			//20250812 Revised formula
			double long_call_current_value  = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_call_current_value = par_up * bs_opt_val(1 + cap_rate / par_up, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			double short_put_current_value  = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_call_current_value - short_put_current_value;

			return option_cost;
		}
		else
		{
			//Buffer Par Up Strategy
			double long_call_current_value = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double short_put_current_value = bs_opt_val(1 - buffer_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
			
			double option_cost = long_call_current_value - short_put_current_value;
				
			return option_cost;
		}
	}
	else if (crediting_dyn_lever_local == "Dynamic Cap")
	{
		//Floor Cap Strategy
		double long_call_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_call_current_value = bs_opt_val(1 + cap_rate, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double long_put_current_value = bs_opt_val(1 + floor_amt, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_put_current_value = bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
				
		double option_cost = long_call_current_value - short_call_current_value + long_put_current_value - short_put_current_value;

		return option_cost;

	}
	else if (crediting_dyn_lever_local == "Dynamic Participation")
	{
		//Par up Par down strategy
		double long_call_current_value = par_up * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		
		double short_put_current_value = par_down * bs_opt_val(1.0, portion_remaining_time * strategy_term_aig(t), spot_price, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
				
		double option_cost = long_call_current_value - short_put_current_value;
		
		return option_cost;
	}

}

return 0.;

}


//@@ END

//@@ START - rila_opt_cost_by_grid_b_aig
// Rila option cost based on option grid, BOM                                                                                             
// Column:RILA_OPT_COST_BY_GRID_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_by_grid_b_aig(int t) {
//^^^



//^^^

#line 1 "rila_opt_cost_by_grid_b_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period)//WTW - Gen2.0- refined time guards
	return 0;

if (t == 0)
{
	return fia->init_hedge_budget;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return 0.0;

//20240918 MQ option sold after performance lock
if(rila_perf_lock_status_bom_aig(t) == 1) 
{
	return 0.;
}

double buffer_amt = rila_buffer_amt_aig(t);

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
double floor_amt = index_term_floor_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
double par_down = fia->part_down_amt;

double par_up = crediting_part_rate_aig(t);
double cap_rate = crediting_cap_rate(t);
double trigger = crediting_trigger_rate_aig(t);

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;
}

double strategy_months = strategy_term_mths_aig(t);
int index_months = index_term_mths_aig(t);

const double FWD_TERM	= 0.0;
double long_call_option_cost = 0.0;
double long_put_option_cost = 0.0;
double short_call_option_cost = 0.0;
double short_put_option_cost = 0.0;
double option_cost = 0.0;

if (buffer_amt != 0)
{
	if (crediting_dyn_lever_local == "Dynamic Cap")
	{
		//Buffer Cap Strategy
		long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_call_option_cost		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_call_option_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic Trigger")
	{
		//Buffer Trigger Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
				
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
		double binary_opt_cost = 0.0;
		if (fia->gen2_defn == YES)
			binary_opt_cost = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			binary_opt_cost = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= trigger * binary_opt_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic DualDir Tri")
	{
		//20250612 Buffer Dual Direction Trigger Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string crediting_strat_str = index_id_str + "_D" + to_string(int(strategy_term_mths_aig(t)));
		int itm_binary_key = xint((1 - buffer_amt) * 100);
		int otm_binary_key = xint((1 + buffer_amt) * 100);
		
		string itm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(itm_binary_key);
		string otm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(otm_binary_key);
		
		double itm_binary_call, otm_binary_call;
		if (fia->gen2_defn == YES)
		{
			itm_binary_call = fia_rates->get_misc_rate(t - 1, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = fia_rates->get_misc_rate(t - 1, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}
		else
		{
			itm_binary_call = rates->get_misc_rate(t - 1, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = rates->get_misc_rate(t - 1, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}

		double long_otm_call = get_option_price_aig(t - 1, 1 + buffer_amt, CALL, strategy_months, index_months);
		double short_otm_call = get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
		double short_otm_put = get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);

		option_cost	= trigger * itm_binary_call + (buffer_amt - trigger) * otm_binary_call 
									+ long_otm_call - short_otm_call - short_otm_put;
	}
	else if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
	{
		//Buffer Dual Direction Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
		int buffer_key = (1 - buffer_amt) * 100;
		string buffer_str = "_K" + to_string(buffer_key);
				
		string rate_lookup = "BINY_" + index_id_regex_str + "_" + option_duration_str + buffer_str;
				
		double option_cost_1minusbuffer = 0.0;
		if (fia->gen2_defn == YES)
			option_cost_1minusbuffer = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			option_cost_1minusbuffer = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_binary_opt_cost = buffer_amt * option_cost_1minusbuffer;

		double long_atm_call		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		double short_otm_call		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
		double short_otm_put		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);	
		double short_itm_call		= get_option_price_aig(t - 1, 1 - buffer_amt, CALL, strategy_months, index_months);
		
		option_cost					= 2 * long_atm_call - short_otm_call - short_otm_put - short_itm_call + long_binary_opt_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic Secure Cap")
	{
		//20240319 MQ Secure Cap Strategy
		option_cost		= get_option_price_aig(t - 1, 1 + cap_rate, CSEC, strategy_months, index_months);
	}
	else if (crediting_dyn_lever_local == "Dynamic Buffer")
	{
		//20240319 MQ Daily Knockout Strategy
		if(rila_knockout_status_bom_aig(t) == 1) 
		{
			return 0.;
		}

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double knockout_threshold = knockout_threshold_aig;

		int knockout_key = (1 + knockout_threshold) * 100;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double rebate = knockout_threshold_aig; //knockout_rebate_aig;

		long_call_option_cost		= get_option_price_aig(t - 1, 1 + rebate, CALLK, strategy_months, index_months, knockout_key);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUTK, strategy_months, index_months, knockout_key);			
		option_cost					= long_call_option_cost - short_put_option_cost;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "_D" + to_string(int(strategy_term_mths_aig(t)));
		string knockout_str = "_K" + to_string(knockout_key);

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double add_rebate_per_yr = knockout_rebate_opt_bdgt_aig;
	
		string rate_lookup = "DIGITAL_" + index_id_regex_str + option_duration_str + knockout_str;
		double digital_opt_cost;

		if (fia->gen2_defn == YES)
			digital_opt_cost = fia_rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			digital_opt_cost = rates->get_misc_rate(t - 1, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		option_cost += digital_opt_cost * add_rebate_per_yr;
	}
	else if (crediting_dyn_lever_local == "Dynamic Par with Cap" || crediting_dyn_lever_local == "Dynamic Cap with Par") 
	{
		//20250113 MQ Buffer Cap combo strategy
		long_call_option_cost		= par_up * get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_call_option_cost		= par_up * get_option_price_aig(t - 1, 1 + cap_rate / par_up, CALL, strategy_months, index_months);  //20250812 Revised formula
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);

		option_cost					= long_call_option_cost - short_call_option_cost - short_put_option_cost;
	}	
	
	else
	{
		//Buffer Par Up Strategy
		long_call_option_cost		= par_up * get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_put_option_cost;
	}
}
else if (crediting_dyn_lever_local == "Dynamic Cap")
{
	//Floor Cap Strategy
	long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
	short_call_option_cost		= get_option_price_aig(t - 1, 1 + cap_rate, CALL, strategy_months, index_months);
	long_put_option_cost		= get_option_price_aig(t - 1, 1 + floor_amt, PUT, strategy_months, index_months);
	short_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_call_option_cost + long_put_option_cost - short_put_option_cost;
}
else
{
	//Par up Par down strategy
	long_call_option_cost		= par_up * get_option_price_aig(t - 1, 1, CALL, strategy_months, index_months);
	short_put_option_cost		= par_down * get_option_price_aig(t - 1, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_put_option_cost;
}

return option_cost;

}


//@@ END

//@@ START - rila_opt_cost_by_grid_e_aig
// Rila option cost based on option grid, EOM                                                                                             
// Column:RILA_OPT_COST_BY_GRID_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_by_grid_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_opt_cost_by_grid_e_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period || t + elapsed_mths == 0)//WTW - Gen2.0- refined time guards
	return 0;

if (t == 0 && valn_period != 0)
{
	return fia->init_hedge_budget;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return 0.0;

//20240918 MQ option sold after performance lock
if(rila_perf_lock_status_bom_aig(t) == 1) 
{
	return 0.;
}

double buffer_amt = rila_buffer_amt_aig(t);

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
double floor_amt = index_term_floor_aig;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
double par_down = fia->part_down_amt;

double par_up = crediting_part_rate_aig(t);
double cap_rate = crediting_cap_rate(t);
double trigger = crediting_trigger_rate_aig(t);

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	crediting_dyn_lever_local = crediting_dyn_lever;
}

double strategy_months = strategy_term_mths_aig(t);
int index_months = index_term_mths_aig(t);

const double FWD_TERM	= 0.0;
double long_call_option_cost = 0.0;
double long_put_option_cost = 0.0;
double short_call_option_cost = 0.0;
double short_put_option_cost = 0.0;
double option_cost = 0.0;

if (buffer_amt != 0)
{
	if (crediting_dyn_lever_local == "Dynamic Cap")
	{
		//Buffer Cap Strategy
		long_call_option_cost		= get_option_price_aig(t, 1, CALL, strategy_months, index_months);
		short_call_option_cost		= get_option_price_aig(t, 1 + cap_rate, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_call_option_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic Trigger")
	{
		//Buffer Trigger Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
				
		string rate_lookup 
			= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
		double binary_opt_cost = 0.0;
		if (fia->gen2_defn == YES)
			binary_opt_cost = fia_rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			binary_opt_cost = rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		short_put_option_cost		= get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= trigger * binary_opt_cost - short_put_option_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic DualDir Tri")
	{
		//20250612 Buffer Dual Direction Trigger Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string crediting_strat_str = index_id_str + "_D" + to_string(int(strategy_term_mths_aig(t)));
		int itm_binary_key = xint((1 - buffer_amt) * 100);
		int otm_binary_key = xint((1 + buffer_amt) * 100);
		
		string itm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(itm_binary_key);
		string otm_binary_lookup = "BINY_" + crediting_strat_str + "_K" + to_string(otm_binary_key);
		
		double itm_binary_call, otm_binary_call;
		if (fia->gen2_defn == YES)
		{
			itm_binary_call = fia_rates->get_misc_rate(t, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = fia_rates->get_misc_rate(t, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}
		else
		{
			itm_binary_call = rates->get_misc_rate(t, xstring(itm_binary_lookup), EFFECTIVE_ANNUAL);
			otm_binary_call = rates->get_misc_rate(t, xstring(otm_binary_lookup), EFFECTIVE_ANNUAL);
		}

		double long_otm_call = get_option_price_aig(t, 1 + buffer_amt, CALL, strategy_months, index_months);
		double short_otm_call = get_option_price_aig(t, 1 + cap_rate, CALL, strategy_months, index_months);
		double short_otm_put = get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);

		option_cost	= trigger * itm_binary_call + (buffer_amt - trigger) * otm_binary_call 
									+ long_otm_call - short_otm_call - short_otm_put;
	}
	else if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
	{
		//Buffer Dual Direction Cap Strategy
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(int(strategy_term_mths_aig(t)));
		int buffer_key = (1 - buffer_amt) * 100;
		string buffer_str = "_K" + to_string(buffer_key);
		
		string rate_lookup = "BINY_" + index_id_regex_str + "_" + option_duration_str + buffer_str;
				
		double option_cost_1minusbuffer = 0.0;
		if (fia->gen2_defn == YES)
			option_cost_1minusbuffer = fia_rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);
		else
			option_cost_1minusbuffer = rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);

		double long_binary_opt_cost = buffer_amt * option_cost_1minusbuffer;

		double long_atm_call		= get_option_price_aig(t, 1, CALL, strategy_months, index_months);
		double short_otm_call		= get_option_price_aig(t, 1 + cap_rate, CALL, strategy_months, index_months);
		double short_otm_put		= get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);	
		double short_itm_call		= get_option_price_aig(t, 1 - buffer_amt, CALL, strategy_months, index_months);
		
		option_cost					= 2 * long_atm_call - short_otm_call - short_otm_put - short_itm_call + long_binary_opt_cost;
	}
	else if (crediting_dyn_lever_local == "Dynamic Secure Cap")
	{
		//20240319 MQ Secure Cap Strategy
		option_cost		= get_option_price_aig(t, 1 + cap_rate, CSEC, strategy_months, index_months);
	}
	else if (crediting_dyn_lever_local == "Dynamic Buffer")
	{
		//20240319 MQ Daily Knockout Strategy
		if(rila_knockout_status_bom_aig(t) == 1) 
		{
			option_cost = 0.;
		}
		else
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double knockout_threshold = knockout_threshold_aig;

			int knockout_key = (1 + knockout_threshold) * 100;

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double rebate = knockout_threshold_aig; //knockout_rebate_aig;
		
			long_call_option_cost		= get_option_price_aig(t, 1 + rebate, CALLK, strategy_months, index_months, knockout_key);
			short_put_option_cost		= get_option_price_aig(t, 1 - buffer_amt, PUTK, strategy_months, index_months, knockout_key);
			option_cost					= long_call_option_cost - short_put_option_cost;

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
			string option_duration_str = "_D" + to_string(int(strategy_term_mths_aig(t)));
			string knockout_str = "_K" + to_string(knockout_key);

			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double add_rebate_per_yr = knockout_rebate_opt_bdgt_aig;

			string rate_lookup = "DIGITAL_" + index_id_regex_str + option_duration_str + knockout_str;
			double digital_opt_cost;

			if (fia->gen2_defn == YES)
				digital_opt_cost = fia_rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);
			else
				digital_opt_cost = rates->get_misc_rate(t, xstring(rate_lookup), EFFECTIVE_ANNUAL);

			option_cost += digital_opt_cost * add_rebate_per_yr;
		}
	}
	else if (crediting_dyn_lever_local == "Dynamic Par with Cap" || crediting_dyn_lever_local == "Dynamic Cap with Par") 
	{
		long_call_option_cost		= par_up * get_option_price_aig(t, 1, CALL, strategy_months, index_months);
		short_call_option_cost		= par_up * get_option_price_aig(t, 1 + cap_rate / par_up, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);  //20250812 Revised formula
		option_cost					= long_call_option_cost - short_call_option_cost - short_put_option_cost;
	}	
	else
	{
		//Buffer Par Up Strategy
		long_call_option_cost		= par_up * get_option_price_aig(t, 1, CALL, strategy_months, index_months);
		short_put_option_cost		= get_option_price_aig(t, 1 - buffer_amt, PUT, strategy_months, index_months);
		option_cost					= long_call_option_cost - short_put_option_cost;
	}
}
else if (crediting_dyn_lever_local == "Dynamic Cap")
{
	//Floor Cap Strategy
	long_call_option_cost		= get_option_price_aig(t, 1, CALL, strategy_months, index_months);
	short_call_option_cost		= get_option_price_aig(t, 1 + cap_rate, CALL, strategy_months, index_months);
	long_put_option_cost		= get_option_price_aig(t, 1 + floor_amt, PUT, strategy_months, index_months);
	short_put_option_cost		= get_option_price_aig(t, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_call_option_cost + long_put_option_cost - short_put_option_cost;
}
else
{
	//Par up Par down strategy
	long_call_option_cost		= par_up * get_option_price_aig(t, 1, CALL, strategy_months, index_months);
	short_put_option_cost		= par_down * get_option_price_aig(t, 1, PUT, strategy_months, index_months);
	option_cost					= long_call_option_cost - short_put_option_cost;
}

return option_cost;

}


//@@ END

//@@ START - rila_perf_lock_hwm_aig
// Current value high water mark                                                                                             
// Column:RILA_PERF_LOCK_HWM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_hwm_aig(int t) {
//^^^



//^^^

#line 1 "rila_perf_lock_hwm_aig.FIAAFUND_LIAB.for"
//20240916 New column tracking high water mark of current value, used for performance lock calculation
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}

if (t + elapsed_mths == 0)
	return 0.;
	
if (t == 0 && valn_period != 0)
	return fia->init_perf_lock_hwm;

double high_water_mark;

double interim_val		= rila_interim_value_e_bef_aig(t);
double strategy_base	= rila_strat_base_b_aig(t);
double curr_value		= 0.;

if (strategy_base > SMALL_DOUBLE)
{
	curr_value = interim_val / strategy_base - 1.;
}

if (strategy_term_elapsed_mths_eom_aig(t) == 1 )
{
	high_water_mark = curr_value;
}
else
{		
	high_water_mark = max(rila_perf_lock_hwm_aig(t - 1), curr_value);
}

return high_water_mark;


}


//@@ END

//@@ START - rila_perf_lock_prob_aig
// Probability of performance lock                                                                                             
// Column:RILA_PERF_LOCK_PROB_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_prob_aig(int t) {
//^^^



//^^^

#line 1 "rila_perf_lock_prob_aig.FIAAFUND_LIAB.for"
//20240725 MQ New column for performance lock: probability of exercising lock
if(t <= commencement_period || t > final_period || fia->rila_perf_lock_calc_aig == NO)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;

if(!rila_ind || rila_perf_lock_status_bom_aig(t) == 1 
	|| (crediting_dyn_lever_local == "Dynamic Buffer" && renew_into_2nd_strat_status_aig(t) == 0)) 
{
	return NO_AVG;
}

if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0)
{
	return 0.;
}

double interim_val		= rila_interim_value_e_bef_aig(t);
double strategy_base	= rila_strat_base_b_aig(t);
double curr_value		= 0.;
double prior_hwm		= 0.;

if (strategy_base > SMALL_DOUBLE)
{
	curr_value = interim_val / strategy_base - 1.;
}

if (strategy_term_elapsed_mths_eom_aig(t) > 1 )
{
	prior_hwm = rila_perf_lock_hwm_aig(t - 1);
}

if (curr_value < prior_hwm)
{
	return 0.;
}

double par_up	= crediting_part_rate_aig(t);
double cap_rate = crediting_cap_rate(t);
double suff_val_rt = perf_lock_suff_val_rt_aig;
double max_val_rt = perf_lock_max_val_rt_aig;

double sufficient_value = suff_val_rt * par_up;
double maximum_value	= min(cap_rate, max_val_rt) * par_up;

double max_excess_return	= max(0, maximum_value - sufficient_value);
double curr_excess_return	= min(max(0, curr_value - sufficient_value), max_excess_return);
double hwm_excess_return	= min(max(0, prior_hwm - sufficient_value), max_excess_return);

double x = 0;
double y = 0;

if (max_excess_return > SMALL_DOUBLE)
{
	x = curr_excess_return / max_excess_return;
	y = hwm_excess_return / max_excess_return;
}


double alpha = perf_lock_gamma_param_alpha_aig;
double beta = perf_lock_gamma_param_beta_aig;

Gamma gamma_dist(alpha, beta);

double gamma_x = gamma_dist.cumulativeDensity(x);
double gamma_y = gamma_dist.cumulativeDensity(y);
double gamma_1 = gamma_dist.cumulativeDensity(1.);

double cumul_prob_lock_iv = gamma_x / gamma_1;
double cumul_prob_lock_hwm = gamma_y / gamma_1;

double auto_lock_election_rt = perf_lock_auto_lock_election_rt_aig;
double non_util_rt = perf_lock_non_util_rt_one_yr_aig; 

if (strategy_term_aig(t) > 1) //Different value for multi-yr
{
	non_util_rt = perf_lock_non_util_rt_multi_yr_aig;
}

double max_util_rt = (1 - non_util_rt) * (1 - auto_lock_election_rt) + auto_lock_election_rt;

cumul_prob_lock_iv *= max_util_rt;
cumul_prob_lock_hwm *= max_util_rt;

double per_lock_prob = (cumul_prob_lock_iv - cumul_prob_lock_hwm) / (1 - cumul_prob_lock_hwm);

return per_lock_prob;

}


//@@ END

//@@ START - rila_perf_lock_status_bom_aig
// Status tracker for performance lock                                                                                             
// Column:RILA_PERF_LOCK_STATUS_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_status_bom_aig(int t) {
//^^^



//^^^

#line 1 "rila_perf_lock_status_bom_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for tracking the status of performance lock
//Code 0: Performance lock has not been triggered
//Code 1: Performance lock has been triggered
//Code 2: Within the multi-year term, this is the first year after lock and past the anniversary, 
//the policy has switched into a 1-yr strategy and lock hasn't been triggered inside the new term.
if (t <= commencement_period || t > final_period || fia->rila_perf_lock_calc_aig == NO || fia->valn_deterministic_flag_crbg)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;
if (crediting_dyn_lever_local == "Dynamic Buffer" && renew_into_2nd_strat_status_aig(t - 1) == 0) //We have different tracker for the knockout strategy
{
	return NO_AVG;
}

//For multi-year strategy only, after lock, past the next anniversary
if (mod(t + elapsed_mths, 12) == 1 && rila_perf_lock_status_eom_aig(t - 1) == 1 
	&& strategy_term_aig(t - 1) > 1 && mod(fia->pol_yr(t), strategy_term_aig(t - 1)) != 1)
{
	return 2.;
}

if (mod(t + elapsed_mths, strategy_term_mths_aig(t - 1)) == 1)
{
	return 0.;
}

return rila_perf_lock_status_eom_aig(t - 1);



}


//@@ END

//@@ START - rila_perf_lock_status_eom_aig
// Status tracker for performance lock                                                                                             
// Column:RILA_PERF_LOCK_STATUS_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_status_eom_aig(int t) {
//^^^



//^^^

#line 1 "rila_perf_lock_status_eom_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for tracking the status of performance lock
if (t < commencement_period || t > final_period || fia->rila_perf_lock_calc_aig == NO)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
double rila_ind = fia->rila_ind;
if (!rila_ind)
{
	return 0.0;
}

fia->pol_yr_lookup_gen2 = 1; 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
double init_strategy_term = strategy_term_duration_aig;
if (fia->crediting_type_dyn_2nd_strat_aig == "NA" && init_strategy_term > 1)
{
	return 0.0;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_dyn_lever_local = crediting_dyn_lever;
if(crediting_dyn_lever_local == "Dynamic Buffer" && renew_into_2nd_strat_status_aig(t) == 0) 
{
	return NO_AVG;
}

if (t == 0 && valn_period != 0)
	return fia->perf_lock_status_ind;

if (t + elapsed_mths == 0)
	return 0.;

if (rila_perf_lock_status_bom_aig(t) == 1)
{
	return rila_perf_lock_status_bom_aig(t);
}

double random_num = fia->uniform_rands_perf_lock_aig(t);

if (rila_perf_lock_prob_aig(t) > random_num) //exercise
{
	return 1.;
}
else //not exercise, can be 0 or 2
{
	return rila_perf_lock_status_bom_aig(t);
}



}


//@@ END

//@@ START - rila_smax_brownian_bridge_aig
// SMAX for brownian bridge adjustment                                                                                             
// Column:RILA_SMAX_BROWNIAN_BRIDGE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_smax_brownian_bridge_aig(int t) {
//^^^



//^^^

#line 1 "rila_smax_brownian_bridge_aig.FIAAFUND_LIAB.for"
//20240603 MQ New column for brownian bridge (used for lock strategy)
if(t <= commencement_period || t > final_period || !valn_flag)
{
	return NO_AVG;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_rate_type_local = fia->crediting_rate_type_aig;
if(crediting_rate_type_local != "Dynamic Buffer") 
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
xstring crediting_eqt_index_local = crediting_eqt_index;

fia->bs_init_vol_type = "base";
fia->index_id_lookup = crediting_eqt_index_local;
double vol = fia->bs_fwrd_vol_aig;

double w, u, wmax, smax;

w		= (log(index_val(t)) - log(index_val(t - 1)) + 0.5 * vol * vol / 12.) / vol;
u		= fia->uniform_rands_brownian_bridge_aig(t);
wmax	= 0.5 * (w + pow(w * w - 2. / 12. * log(1 - u), 0.5));
smax	= index_val(t - 1) * exp(vol * wmax - 0.25 * vol * vol / 12.);

return smax;

}


//@@ END

//@@ START - rila_strat_base_b_aig
// RILA strategy base                                                                                             
// Column:RILA_STRAT_BASE_B_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_strat_base_b_aig(int t) {
//^^^



//^^^

#line 1 "rila_strat_base_b_aig.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2.0- refined time guards
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	if(mod(t + elapsed_mths - 1, strategy_term_mths_aig(t)) == 0)
	{
		//Reset interim value to BOP fund value at beginning of strategy term
		return fund_val_b(t);
	}
/*	else if(t == 1)
	{
		return rila_strat_base_e_aig(t - 1); //20240206 WTW code, 20240325 MQ Remove
	}*/
	else
	{
		double fees_and_charges = admin_fee(t) + gmwb_chg(t) + fia->rop_chg_aig(t) + tier_strat_fee_aig(t);
			
		double proportion_reduced = 0.0;
		if (rila_interim_value_e_aig(t - 1) > SMALL_DOUBLE)
			proportion_reduced = fees_and_charges / rila_interim_value_e_aig(t - 1);

		//During intermediate times within the strategy term, return the EOM interim value from prior period
		return rila_strat_base_e_aig(t - 1) * (1 - proportion_reduced);
	}	
}

}


//@@ END

//@@ START - rila_strat_base_e_aig
// Rila Strategy Base                                                                                             
// Column:RILA_STRAT_BASE_E_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_strat_base_e_aig(int t) {
//^^^



//^^^

#line 1 "rila_strat_base_e_aig.FIAAFUND_LIAB.for"
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2.0- refined time guards
{
	return 0;
}
else
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;

	if(!rila_ind)
		return 0.0;

	//RILA implementation
	if (t == 0 && valn_period == 0)
	{
		//Return initial premium at time 0
		double RILA_Base = fia->single_prem;
		return RILA_Base;
	}
	else if (t == 0 && valn_period != 0)
	{
		//Return initial premium at time 0
		double RILA_Base = fia->init_strat_base;
		return RILA_Base;
	}
	else
	{
		double interm_value = rila_interim_value_e_bef_aig(t) * fia->surv_period(t);
		if(interm_value < SMALL_DOUBLE)
			return 0.0;
		
		//During intermediate times within the strategy term, return the EOM interim value from prior period
		double RILA_strat_base = rila_strat_base_b_aig(t) * fia->surv_period(t);

		if(mod(t + elapsed_mths, strategy_term_mths_aig(t)) == 0 ||
			(rila_knockout_status_bom_aig(t) == 0 && rila_knockout_status_eom_aig(t) == 1)) //20240325 Add condition for Knockout
		{
			RILA_strat_base *= (1 + strategy_return_index_aig(t)); 
		}

		//20240212 include maturity benefit
		double portion_reduced = (fund_released_withdrl(t) + fund_released_maturity(t))/ interm_value;

		RILA_strat_base = max(0., RILA_strat_base * (1 - portion_reduced));

		return RILA_strat_base;
	}
}

}


//@@ END

//@@ START - rila_trading_cost_pct_bom_aig
// trading cost for rila at beginning of month                                                                                             
// Column:RILA_TRADING_COST_PCT_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_trading_cost_pct_bom_aig(int t) {
//^^^



//^^^

#line 1 "rila_trading_cost_pct_bom_aig.FIAAFUND_LIAB.for"
//20240528 MQ New column for rila trading cost
if(t <= commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if (pba_valn_flag)
{
	double trading_cost_pba;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	trading_cost_pba = fia->rila_trading_cost_pba;

	if (renew_into_2nd_strat_status_aig(t) == 1)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		trading_cost_pba = fia->rila_trading_cost_pba;
	}

	return trading_cost_pba;
}

double trading_cost_low_vol, trading_cost_high_vol, volatility;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
trading_cost_low_vol = fia->rila_trading_cost_low_vol;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
trading_cost_high_vol = fia->rila_trading_cost_high_vol;

if (renew_into_2nd_strat_status_aig(t) == 1)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	trading_cost_low_vol = fia->rila_trading_cost_low_vol;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	trading_cost_high_vol = fia->rila_trading_cost_high_vol;
}

if (fia->gen2_defn == YES)
{
	volatility = fia_rates->get_misc_rate(t - 1, "SP_Vol", EFFECTIVE_ANNUAL); 
}
else
{
	volatility = rates->get_misc_rate(t - 1, "SP_Vol", EFFECTIVE_ANNUAL); 
}

if (volatility <= 0.3)
{
	return trading_cost_low_vol;
}
else
{
	return trading_cost_high_vol;
}


}


//@@ END

//@@ START - rila_trading_cost_pct_eom_aig
// trading cost for rila at end of month                                                                                             
// Column:RILA_TRADING_COST_PCT_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_rila_trading_cost_pct_eom_aig(int t) {
//^^^



//^^^

#line 1 "rila_trading_cost_pct_eom_aig.FIAAFUND_LIAB.for"
//20240528 MQ New column for rila trading cost
if(t <= commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;

if(!rila_ind)
	return NO_AVG;

if (pba_valn_flag)
{
	double trading_cost_pba;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	trading_cost_pba = fia->rila_trading_cost_pba;

	if (renew_into_2nd_strat_status_aig(t) == 1)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		trading_cost_pba = fia->rila_trading_cost_pba;
	}

	return trading_cost_pba;
}

double trading_cost_low_vol, trading_cost_high_vol, volatility;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
trading_cost_low_vol = fia->rila_trading_cost_low_vol;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
trading_cost_high_vol = fia->rila_trading_cost_high_vol;

if (renew_into_2nd_strat_status_aig(t) == 1)
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	trading_cost_low_vol = fia->rila_trading_cost_low_vol;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	trading_cost_high_vol = fia->rila_trading_cost_high_vol;
}

if (fia->gen2_defn == YES)
{
	volatility = fia_rates->get_misc_rate(t, "SP_Vol", EFFECTIVE_ANNUAL); 
}
else
{
	volatility = rates->get_misc_rate(t, "SP_Vol", EFFECTIVE_ANNUAL); 
}

if (volatility <= 0.3)
{
	return trading_cost_low_vol;
}
else
{
	return trading_cost_high_vol;
}


}


//@@ END

//@@ START - sfas133_gmwb_chg
// SFAS133 GMWB Charge                                                                                             
// Column:SFAS133_GMWB_CHG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_sfas133_gmwb_chg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(145,"sfas133_gmwb_chg",t);
}



//^^^

#line 1 "sfas133_gmwb_chg.FIAAFUND_LIAB.for"
if (/*!fia->gmwb_flag ||*/ t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - move non-time guard below
	return NO_AVG;

if (!fia->gmwb_flag)
	return NO_AVG;

if (!fia->gmwb_flag
	|| t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fia->pol_yr(t) == 1 && fia->pol_mth(t) == 1)
	return 0.0;

if (fund_val_b_bef(t) < model_point_amount_threshold)
	return 0.0;

double chg_base_mult = 0.0;
if (fia->gmwb_chg_base == FUND_VALUE)
	chg_base_mult = 1.0;

else if (fia->gmwb_chg_base == GMWB_BASE)
	chg_base_mult 
	= fia->gmwb_inf_bef(t) / fia->fund_val_b_bef(t);

else //"MAX"
	chg_base_mult = max(1.0, fia->gmwb_inf_bef(t) / fia->fund_val_b_bef(t));

double av_b_bef_gmwb_chg
= fund_val_b_bef(t) - admin_fee(t);

return min(max(av_b_bef_gmwb_chg, 0.0),
           (fia->gmwb_sfas133_req_prof_chg / 12.0) 
           * (fund_val_b_bef(t) - admin_fee(t))
       	* chg_base_mult);

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double FIAAFUND_LIAB_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.FIAAFUND_LIAB.for"
#if 0 // START_HEADER
#include <regex> //DTL: 20180627
//#include "rates_economy.h" // 20191104 MTC //WTW - Gen2 - Move AIG structures to Externs

// 20181217 MTC - Refactored cubic spline
#ifndef CUBIC_SPLINE_AIG//WTW - Gen2
struct cubic_spline_params_aig
{
	cubic_spline_params_aig(): initialized(false),
						       n(0),
							   h(vector<double>()),
							   alpha(vector<double>()),
							   l(vector<double>()),
							   mu(vector<double>()),
							   z(vector<double>()),
							   c(vector<double>()),
							   b(vector<double>()),
							   d(vector<double>()) {}
	bool initialized;
	int n;
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;
};

const cubic_spline_params_aig default_cubic_spline_params_aig = cubic_spline_params_aig();
// 20181217 MTC END
#define CUBIC_SPLINE_AIG//WTW - Gen2
#endif//WTW - Gen2

#endif // END_HEADER

#if 0 // START_EXTERNS
extern SmartArray <SmartArray <double> > fia_caps_array(0);
#endif // END_EXTERNS

#if 0 // START_CLASS
// dynamic Lever variables
SmartArray <double> lookback_index_value_data;
int lookback_yrs;
double div_yld_scen_mult;
double div_yld_sprd;
double index_scen_mult;
double index_scen_sprd_addn;
double payout_index_max;

bool pricing_spread_migration_is_underway_aig;		//DTL: 20180914
int pricing_spread_migration_start_duration_aig;	//DTL: 20180914
int strategy_return_switch_start_duration_aig;      // 20180930 MTC

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
// dynamic Lever variables
lookback_yrs = 0;
div_yld_scen_mult = 1.0;
div_yld_sprd = 0.0;
index_scen_mult = 1.0;
index_scen_sprd_addn = 0.0;
payout_index_max = 999.99;

pricing_spread_migration_is_underway_aig = false;		//DTL: 20180914
pricing_spread_migration_start_duration_aig = 9999;		//DTL: 20180914
strategy_return_switch_start_duration_aig = t_high;     // 20180930 MTC
#endif // END_CONSTRUCTOR

//fia->pol_yr_lookup_gen2 = fia->pol_yr(0); //WTW - Gen2 - cannot use this code because cannot call a column from startup.
if (t == commencement_period) 
	{
	if (elapsed_mths <= 0)
		fia->pol_yr_lookup_gen2 = 0;//WTW - Gen2 - add working variable for lookups that vary by time for character input
	else
		fia->pol_yr_lookup_gen2 = xint((elapsed_mths - 1) / 12.0) + 1.0;//WTW - Gen2 - add working variable for lookups that vary by time for character input
	}

//set up variables value
if (crediting_dyn_lever == DYNAMIC_PARTICIPATION && crediting_rate_defn == MONTHLY_SUM_CAP)//WTW - Gen2 - character input that varies by time
	{
	xstring error_message = "Dynamic lever for model point[" + xstring(getElementNumber()) + "] with FA crediting method of Monthly Sum Cap should be set to Dynamic Cap";
	throw FatalError(error_message);
	}

div_yld_scen_mult = 1.0;
div_yld_sprd = 0.0;
index_scen_mult = 1.0;
index_scen_sprd_addn = 0.0;
payout_index_max = GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE + .999;

if (crediting_rate_defn == MOVING_AVERAGE)
	lookback_defn = ASIAN;
		
if (crediting_rate_defn == POINT_TO_POINT)	
	{
	lookback_defn = NONE;
		
	lookback_yrs = 0.0;
	}

return 1.0;

}


//@@ END

//@@ START - strategy_return_aig
// Monthly Strategy Return                                                                                             
// Column:STRATEGY_RETURN_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"strategy_return_aig",t);
}



//^^^

#line 1 "strategy_return_aig.FIAAFUND_LIAB.for"
// 20180815 MTC - Strategy return
if (t < commencement_period || t > final_period || t + elapsed_mths == 0)
{
	return NO_AVG;
}

if (t == 0 && valn_period != 0) // 20240311 MQ 
	return fia->inner_strat_return;

// Initialize
double strategy_return = 0.0;

// Base strategy return off of index
strategy_return = strategy_return_index_aig(t);

return strategy_return;


}


//@@ END

//@@ START - strategy_return_cumul_aig
// Cumulative Strategy Return                                                                                             
// Column:STRATEGY_RETURN_CUMUL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_cumul_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_cumul_aig.FIAAFUND_LIAB.for"
/*
	Weighted sum refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == FIXED_RATE)
{
	return crediting_rate_fix_cumul_aig(t);
}
else
{
	return strategy_return_aig(t);
}


}


//@@ END

//@@ START - strategy_return_index_aig
// Strategy Return based on Index Accounts                                                                                             
// Column:STRATEGY_RETURN_INDEX_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_index_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_index_aig.FIAAFUND_LIAB.for"
//20240124 Stripped out RILA return
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

if (sfas97rd_valn_flag)
{
	#if defined(__SEG_COMP_H_)
		return convert_rate_basis(fia->gaap_int_rate, EFFECTIVE_ANNUAL, - 12);
	#endif
		return convert_rate_basis(fia->gaap_int_rate_input, EFFECTIVE_ANNUAL, - 12);
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term
double rila_ind = fia->rila_ind;

if (rila_ind)
	return strategy_return_index_rila_aig(t);

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig

index_val(t);
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == POINT_TO_POINT || crediting_rate_defn == POINT_TO_POINT_SPREAD) 
{ 
	double index_return = 0.0;
	double part_rate, cap_rate, sprd_rate, init_sprd_rate, use_cap_as_sprd_rate;
	// 20211217 STW: remove min and max for the sprd rate in dyn par and all par rate
	if(remove_par_sprd_min_max_aig == YES)
	{
		cap_rate = crediting_cap_rate(t);
		sprd_rate = crediting_spread_rate_aig(t);
		init_sprd_rate = index_term_init_spread_rate_aig(t);												// this sprd is for dynamic participation only
		part_rate = crediting_part_rate_aig(t);
		use_cap_as_sprd_rate = crediting_cap_rate(t);
	}
	else
	{
		cap_rate = max(crediting_cap_rate(t), index_term_cap_rate_min_col_aig(t));
		sprd_rate = min(crediting_spread_rate_aig(t), index_term_sprd_rate_max_col_aig(t));
		init_sprd_rate = min(index_term_init_spread_rate_aig(t), index_term_sprd_rate_max_col_aig(t));	// this sprd is for dynamic participation only
		part_rate = max(crediting_part_rate_aig(t), index_term_part_rate_min_col_aig(t));
		use_cap_as_sprd_rate = min(crediting_cap_rate(t), index_term_sprd_rate_max_col_aig(t));		
	}
		
	if ( fabs(index_term_beginning_index_val_bom_aig(t)) <= rate_ratio_threshold )
	{
		index_return = 0.0;
	}
	else 
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		if ( crediting_dyn_lever == DYNAMIC_CAP )	//WTW - Gen2 - character input that varies by time
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			
			if ( crediting_rate_defn == POINT_TO_POINT_SPREAD ) //spread strategy
			{	
				index_return = part_rate * index_term_index_return_aig(t) - use_cap_as_sprd_rate * index_term_elapsed_pct_eom_aig(t);
			}
			else //cap strategy
			{
				index_return = min(part_rate * index_term_index_return_aig(t), cap_rate);
			}
		}
		else //WTW - Gen2 - Mutating Lookup Term - Break out else if {} to else{ if {}...} syntax
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
			if ( crediting_dyn_lever == DYNAMIC_PARTICIPATION )//WTW - Gen2 - character input that varies by time
			{ //No cap on growth, adjusted via particpation rate
				fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
				if (crediting_rate_defn == POINT_TO_POINT_SPREAD) //Fixed spread with dynamic par rate
				{
					index_return = part_rate * index_term_index_return_aig(t) - init_sprd_rate * index_term_elapsed_pct_eom_aig(t);
				}
				else
				{
					index_return = part_rate * index_term_index_return_aig(t);
				}
			}
			// 20190918 DTL (START): adding dynamic participation and dynamic spread together
			else 
			{
				fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
				fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
				if ( crediting_dyn_lever == DYNAMIC_PARTICIPATION_AND_SPREAD )//WTW - Gen2 - character input that varies by time
				{
					index_return = part_rate * index_term_index_return_aig(t) - sprd_rate * index_term_elapsed_pct_eom_aig(t);
				}
				else
				{
					//20230105 SJ: add the trigger rate as the crediting rate for trigger fund
					fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
					fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
					if ( crediting_dyn_lever == DYNAMIC_TRIGGER )
					{
						if (index_term_index_return_aig(t) > 0)
						{
							index_return = crediting_trigger_rate_aig(t);
						}
						else
						{
							index_return = 0;
						}
					}
					//20230105 SJ END

				// 20190918 DTL (END)
					else if ( NO_DYNAMICS )
					{
						part_rate = max(init_part_rate_aig(t), index_term_part_rate_min_col_aig(t)); // DTL 20200109: TFS 86561
						cap_rate = max(init_cap_rate_aig(t), index_term_cap_rate_min_col_aig(t)); // DTL 20200109: TFS 86561
						sprd_rate = min(index_term_init_spread_rate_aig(t), index_term_sprd_rate_max_col_aig(t)); // DTL 20200109: TFS 86561

						index_return = min(cap_rate, part_rate * index_term_index_return_aig(t) - sprd_rate * index_term_elapsed_pct_eom_aig(t));
					}
					else
					{
						throw FatalError("fia_account->strategy_return_aig(t) : unhandled `crediting_dyn_lever` value.");
					}
				}
			}
		}
	}

	index_return = max(index_return, index_term_floor_col_aig(t));  // 20190613 DTL: replaced code variable `index_term_floor_aig` with column of same name

	double strategy_return;
	if ( strategy_term_elapsed_mths_eom_aig(t) == index_term_elapsed_mths_eom_aig(t) )
	{
		strategy_return = index_return;
	}
	else
	{
		strategy_return = ( 1 + strategy_return_aig(index_term_start_duration_aig(t) -  1) );
		strategy_return *= (1 + index_return);
		strategy_return -= 1;	
	}

	const int MONTHS_IN_YEAR = 12;
	if ( strategy_term_elapsed_mths_eom_aig(t) == strategy_term_aig(t) * MONTHS_IN_YEAR ) // 20190613 DTL: replacing `strategy_term_duration_aig` with `strategy_term_aig(t)`
	{
		strategy_return = max(strategy_return, strategy_term_floor_col_aig(t));
	}

	return strategy_return;
}	

else //WTW - Gen2 - Mutating Lookup Term - Change else if {} to else{ if{}...} syntax
{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (crediting_rate_defn == MOVING_AVERAGE) 	// Begin MA logic
		throw FatalError("Moving average is unavailable in strategy return calculation!");	
	else if (crediting_rate_defn == MONTHLY_SUM_CAP) // Begin monthly sum cap logic
		throw FatalError("Monthly sum cap is unavailable in strategy return calculation!");
	// DTL 20180919 : Comment out here, leave in `crediting_rate` only
	// 20180109 MTC - Restore fixed account to strategy return
	else if (crediting_rate_defn == FIXED_RATE)// Begin fixed rate logic
		return pow(1.0 + crediting_rate_fix(t), 1.0 / 12.0) - 1.0;
	else 
		throw FatalError("Unhandled fia_liab->crediting_rate_defn in fiaafund_liab->strategy_return_aig!");
}

}


//@@ END

//@@ START - strategy_return_index_rila_aig
// Strategy Return based on Index Accounts                                                                                             
// Column:STRATEGY_RETURN_INDEX_RILA_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_index_rila_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_index_rila_aig.FIAAFUND_LIAB.for"
//20240124 MQ new column for RILA return
if (t <= commencement_period || t > final_period)
{
	return NO_AVG;
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double rila_ind = fia->rila_ind;
if(!rila_ind)
	return 0.;

if (rila_perf_lock_status_bom_aig(t) == 1) 
	return 0.;

index_val(t);

double index_return = 0.0;
double part_rate, cap_rate;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double floor_amt = index_term_floor_aig;
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
double part_down_amt = fia->part_down_amt;

double buffer_amt = rila_buffer_amt_aig(t);

if(remove_par_sprd_min_max_aig == YES)
{
	cap_rate = crediting_cap_rate(t);
	part_rate = crediting_part_rate_aig(t);
}
else
{
	cap_rate = max(crediting_cap_rate(t), index_term_cap_rate_min_col_aig(t));
	part_rate = max(crediting_part_rate_aig(t), index_term_part_rate_min_col_aig(t));
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if ( fabs(index_term_beginning_index_val_bom_aig(t)) <= rate_ratio_threshold )
{
	index_return = 0.0;
}
else 
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_dyn_lever_local = crediting_dyn_lever;

	if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
		crediting_dyn_lever_local = crediting_dyn_lever;
	}

	if (crediting_dyn_lever_local == "Dynamic Cap" || crediting_dyn_lever_local == "Dynamic Secure Cap") //20240319 MQ Add secure cap
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double floor_amt = index_term_floor_aig;

		if (buffer_amt == 0)// Floor/Cap Strategy
		{
			index_return = max(min(part_rate * index_term_index_return_aig(t), cap_rate), floor_amt);
		}
				
		else // (buffer_amt != 0)  Buffer/Cap Strategy or Buffer Secure Cap
		{
			if (index_term_index_return_aig(t) < -buffer_amt)
			{
				index_return =  index_term_index_return_aig(t) + buffer_amt;
			}
			else if (index_term_index_return_aig(t) > -buffer_amt && index_term_index_return_aig(t) <= 0) 
			{
				index_return = 0;
			}
			else //Return is greater than 0, subject to cap
			{
				index_return = min(index_term_index_return_aig(t), cap_rate);
			}					
		}
	}
		
	else if (crediting_dyn_lever_local == "Dynamic Participation")	
	{
		if (buffer_amt !=0) // Buffer/par Strategy
		{
			index_return =  min(0, index_term_index_return_aig(t) + buffer_amt) + max(0, part_rate * index_term_index_return_aig(t));
		}
		else if(part_down_amt != 0) // Par Up Par Down
		{
						
			index_return = max(0, part_rate * index_term_index_return_aig(t)) + min(0, part_down_amt * index_term_index_return_aig(t));
		}
		else
		{
			index_return = part_rate * index_term_index_return_aig(t);
		}
	}

	else if (crediting_dyn_lever_local == "Dynamic Trigger")
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double min_index_chg = trigger_strat_min_index_chg_aig;
				
		if (index_term_index_return_aig(t) >= min_index_chg) 
		{
			index_return = crediting_trigger_rate_aig(t);
		}
		else if (index_term_index_return_aig(t) >= -buffer_amt) 
		{
			index_return = 0;
		}
		else
		{
			index_return = index_term_index_return_aig(t) + buffer_amt;
		}
	}

	else if (crediting_dyn_lever_local == "Dynamic DualDir Tri") //20250612 buffer dual direction trigger cap
	{
		if (index_term_index_return_aig(t) > buffer_amt)
		{
			index_return = min(index_term_index_return_aig(t), crediting_cap_rate(t));
		}
		else if (index_term_index_return_aig(t) >= -buffer_amt && index_term_index_return_aig(t) <= buffer_amt)
		{
			index_return = crediting_trigger_rate_aig(t);
		}
		else 
		{
			index_return = index_term_index_return_aig(t) + buffer_amt;
		}
	}

	else if (crediting_dyn_lever_local == "Dynamic DualDir Cap")
	{
		if (index_term_index_return_aig(t) > 0)
		{
			index_return = min(index_term_index_return_aig(t), crediting_cap_rate(t));
		}
		else if (index_term_index_return_aig(t) >= -buffer_amt)
		{
			index_return = min(-index_term_index_return_aig(t), buffer_amt);
		}
		else
		{
			index_return = index_term_index_return_aig(t) + buffer_amt;
		}
	}

	else if (crediting_dyn_lever_local == "Dynamic Buffer") //20240319 MQ Daily Knockout Strategy
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double knockout_threshold = knockout_threshold_aig;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		double perf_lock_fixed = perf_lock_fixed_rt_aig;

		if (rila_knockout_status_eom_aig(t) == 1 && rila_knockout_status_bom_aig(t) == 0) //Immediately after knockout
		{
			index_return = knockout_threshold * pow(1 + perf_lock_fixed, 1./24.); //20240425
		}
		else if (rila_knockout_status_eom_aig(t) == 1) //After auto lock
		{
			index_return = pow(1 + perf_lock_fixed, 1./12.) - 1.;
		}
		else // Knockout not hit
		{
			if (index_term_index_return_aig(t) < -buffer_amt)
			{
				index_return =  index_term_index_return_aig(t) + buffer_amt;
			}
			else if (index_term_index_return_aig(t) > -buffer_amt && index_term_index_return_aig(t) <= 0) 
			{
				index_return = 0;
			}
			else //Return is greater than 0
			{
				index_return = min(index_term_index_return_aig(t), knockout_threshold);
			}	
		}
	}				
	else if (crediting_dyn_lever_local == "Dynamic Par with Cap" || crediting_dyn_lever_local == "Dynamic Cap with Par") //20250804 MQ Buffer Cap combo strategy
	{
		if (index_term_index_return_aig(t) >= 0)
		{
			index_return = min(part_rate * index_term_index_return_aig(t), cap_rate);
		}
		else 
		{
			index_return = min(0, index_term_index_return_aig(t) + buffer_amt);
		}	
	}

}

double strategy_return;

strategy_return_prior_index_term_aig(t);

if ( strategy_term_elapsed_mths_eom_aig(t) == index_term_elapsed_mths_eom_aig(t) )
{
	strategy_return = index_return;
}
else
{
	// Rewrote the code below as the model cannot look back more than 1 month under VM-21 run
	//strategy_return = ( 1 + strategy_return_aig(index_term_start_duration_aig(t) -  1) );
	strategy_return = 1 + strategy_return_prior_index_term_aig(t); 
	strategy_return *= (1 + index_return);
	strategy_return -= 1;	
}

const int MONTHS_IN_YEAR = 12;
if ( strategy_term_elapsed_mths_eom_aig(t) == strategy_term_aig(t) * MONTHS_IN_YEAR ) 
{
	strategy_return = max(strategy_return, strategy_term_floor_col_aig(t));
}

return strategy_return;
	



}


//@@ END

//@@ START - strategy_return_prior_index_term_aig
// Strategy Return from previous index term                                                                                             
// Column:STRATEGY_RETURN_PRIOR_INDEX_TERM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prior_index_term_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_prior_index_term_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for Secure strategy
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}

if ( strategy_term_elapsed_mths_eom_aig(t) == index_term_elapsed_mths_eom_aig(t) )
{
	return 0.;
}

if (index_term_elapsed_mths_eom_aig(t) == 1)
{
	return strategy_return_aig(t - 1);
}

return strategy_return_prior_index_term_aig(t - 1);

}


//@@ END

//@@ START - strategy_return_prior_index_term_eom_aig
// Strategy Return from previous index term                                                                                             
// Column:STRATEGY_RETURN_PRIOR_INDEX_TERM_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prior_index_term_eom_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_prior_index_term_eom_aig.FIAAFUND_LIAB.for"
//20240307 MQ new column for Secure strategy
if (t < commencement_period || t > final_period)
{
	return NO_AVG;
}

if (index_term_elapsed_mths_eom_aig(t) == index_term_mths_aig(t))
{
	return strategy_return_aig(t);
}

if ( strategy_term_elapsed_mths_eom_aig(t) == index_term_elapsed_mths_eom_aig(t) )
{
	return 0.;
}

return strategy_return_prior_index_term_eom_aig(t - 1);

}


//@@ END

//@@ START - strategy_return_prorated_aig
// Prorated strategy return:                                                                                             
// Column:STRATEGY_RETURN_PRORATED_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prorated_aig(int t) {
//^^^



//^^^

#line 1 "strategy_return_prorated_aig.FIAAFUND_LIAB.for"
/*
	Weighted sum refactor.  MCHING 9-3-2021
*/

if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}

double strategy_return = strategy_return_cumul_aig(t);
double proration_factor = strategy_term_elapsed_pct_eom_aig(t);

return strategy_return * proration_factor;


}


//@@ END

//@@ START - strategy_term_aig
// Strategy Term:                                                                                             
// Column:STRATEGY_TERM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - time guards
	return NO_AVG;

crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->pol_yr_lookup_gen2 = fia->pol_yr(t);   //WTW - Gen2 - updated for time based lookups 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

double strategy_term = strategy_term_duration_aig;

if (renew_into_2nd_strat_status_aig(t) == 1) //20240911 MQ
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	strategy_term = strategy_term_duration_aig;
}

return strategy_term;

}


//@@ END

//@@ START - strategy_term_beginning_index_val_bom_aig
// Strategy Term Beginning Index Value BOM:                                                                                             
// Column:STRATEGY_TERM_BEGINNING_INDEX_VAL_BOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_beginning_index_val_bom_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_beginning_index_val_bom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	if ( strategy_term_elapsed_mths_eom_aig(t) == 1 )
	{
		return index_val_bom(t);
	}
	else
	{
		return strategy_term_beginning_index_val_bom_aig(t - 1);
	}
}

}


//@@ END

//@@ START - strategy_term_elapsed_mths_eom_aig
// Strategy Term Elapsed Months EOM:                                                                                             
// Column:STRATEGY_TERM_ELAPSED_MTHS_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_elapsed_mths_eom_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_elapsed_mths_eom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t < commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	if ( t < commencement_period + 1 ) // 20180109 MTC - Fixed div0 bug
	{
		double mth_in_term = mod(t + elapsed_mths, strategy_term_aig(t) * 12.0);
		return mth_in_term;
	}
	else
	{
		const double MONTHS_IN_YEAR = 12.0;
		if ( mod(strategy_term_elapsed_mths_eom_aig(t - 1), strategy_term_aig(t - 1) * MONTHS_IN_YEAR ) == 0 )
		{
			return 1;
		}
		if ((rila_knockout_status_bom_aig(t) == 2 || rila_perf_lock_status_bom_aig(t) == 2) && mod(t + elapsed_mths, 12) == 1) // 20240311 MQ new condition for knockout strat
		{
			return 1;
		}
		else
		{
			return strategy_term_elapsed_mths_eom_aig(t - 1) + 1;
		}
	}
}

}


//@@ END

//@@ START - strategy_term_elapsed_pct_eom_aig
// Strategy Term Elapsed Percentage EOM:                                                                                             
// Column:STRATEGY_TERM_ELAPSED_PCT_EOM_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_elapsed_pct_eom_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_elapsed_pct_eom_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if ((t <= commencement_period || t > final_period/*maturity_period*/) && valn_period == 0)
{
	return NO_AVG;
}
else
{
	const double MONTHS_IN_YEAR = 12.0;
	double current_strategy_term_duration = strategy_term_aig(t) * MONTHS_IN_YEAR;
	double current_strategy_term_mths_completed = strategy_term_elapsed_mths_eom_aig(t);

	if ( current_strategy_term_duration < SMALL_DOUBLE )
	{
		throw FatalError("fia_account->strategy_term_elapsed_pct_eom_aig(t) : Division by zero!");
	}
	else
	{
		return current_strategy_term_mths_completed / current_strategy_term_duration;
	}
}

}


//@@ END

//@@ START - strategy_term_floor_col_aig
// Strategy term floor for crediting:                                                                                             
// Column:STRATEGY_TERM_FLOOR_COL_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_floor_col_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_floor_col_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: get and return the one-year strategy term floor. This is used
 * for the floor to the strategy term account credit rate when a contract is
 * forced to the 1x1 strategy term, index term configuration because of 
 * low contract value.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)
	return NO_AVG;

fia->pol_yr(t);   // force call look-up key
crediting_type_dyn_trigger_aig(t);  // 20191029 MTC - Force call trigger eval to switch crediting_type_dyn_aig
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

return strategy_term_floor_aig;

}


//@@ END

//@@ START - strategy_term_index_return_aig
// Strategy Term Index Return:                                                                                             
// Column:STRATEGY_TERM_INDEX_RETURN_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_index_return_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_index_return_aig.FIAAFUND_LIAB.for"
// DTL 20180919 -- Adding this column
if (t <= commencement_period || t > final_period/*maturity_period*/)
{
	return NO_AVG;
}
else
{
	double index_start_value = strategy_term_beginning_index_val_bom_aig(t);
	if ( index_start_value < SMALL_DOUBLE )
	{
		// 20191129 DTL (START): we'll allow for the index going to zero -- return 0 in this case
		//throw FatalError("fia_account->strategy_term_index_return_aig(t) : Division by zero!");

		const double INFTY = 999999.0;
		return -INFTY;
		// 20191129 DTL (END)
	}
	else
	{
		double index_eom_value = index_val(t);
		return index_eom_value / index_start_value - 1;
	}
}

}


//@@ END

//@@ START - strategy_term_mths_aig
// Months in the current strategy term:                                                                                             
// Column:STRATEGY_TERM_MTHS_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_mths_aig(int t) {
//^^^



//^^^

#line 1 "strategy_term_mths_aig.FIAAFUND_LIAB.for"
/*****************************************************************************
 * 20190613 DTL
 * 
 * Description: strategy term is used in various places in the model.
 * Often the model needs the value in months; this column provides that.
 *
 *****************************************************************************/
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - time guards
	return NO_AVG;

const double MONTHS_IN_YEAR = 12.0;
return strategy_term_aig(t) * MONTHS_IN_YEAR;

}


//@@ END

//@@ START - tier_number_aig
// Tier Number                                                                                             
// Column:TIER_NUMBER_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_tier_number_aig(int t) {
//^^^



//^^^

#line 1 "tier_number_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
if (t < commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - refined time guards
{
	return NO_AVG;
}

if(mod(t + elapsed_mths, 12 * strategy_term_aig(t)) != 1 && t != commencement_period)
{
	return tier_number_aig(t - 1);
}

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if(EPS_defn == NOT_ENHANCED 
	// simplify min av test
	|| (t > commencement_period 
		&& (fund_val_b(t) < SMALL_DOUBLE)
		)
	)
{
	return 0;
}
else if(EPS_defn == ENHANCED)
{
	return 1;
}
else 
{
	throw FatalError("part_enhancement_method_aig is not set to acceptable values. Please check the inputs. (tier_number_aig at fiaafund_liab)");
}

}


//@@ END

//@@ START - tier_strat_fee_aig
// Participation Rate Enhancement Strategy Fee                                                                                             
// Column:TIER_STRAT_FEE_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_aig(int t) {
//^^^



//^^^

#line 1 "tier_strat_fee_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if (t <= commencement_period || t > final_period/*maturity_period*/ //WTW - Gen2 - refined time guards
	|| EPS_defn == NOT_ENHANCED )
{
	return NO_AVG;
}

double fee_base = 0.0;
double strategy_fee = 0.0;

if (mod(t + elapsed_mths, strategy_term_aig(t) * 12 ) == 1 
	&& t > 12 * strategy_term_aig(t) && fund_val_b_bef(t) - admin_fee(t) - gmwb_chg(t) > SMALL_DOUBLE 
	&& fia->surv(t - 1) > SMALL_DOUBLE)
{
	fee_base = fund_val_b(t - 12 * strategy_term_aig(t)); //the beginning of Index Term Account Value
	
	fee_base = fee_base / fia->surv(t - 1 - 12 * strategy_term_aig(t)) * fia->surv(t - 1);
	
	// apply strategy term to tier fee
	strategy_fee = fee_base * eprs_cost_rate_aig(t - 1) * strategy_term_aig(t);
}

strategy_fee = min(fund_val_b_bef(t) - admin_fee(t) - gmwb_chg(t), strategy_fee);

return strategy_fee;

}


//@@ END

//@@ START - tier_strat_fee_at_surr_aig
// Tier Strat Fee  At Surrender For Inforce End of Month                                                                                             
// Column:TIER_STRAT_FEE_AT_SURR_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_at_surr_aig(int t) {
//^^^



//^^^

#line 1 "tier_strat_fee_at_surr_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if (EPS_defn == NOT_ENHANCED || t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - refined time guards
	return NO_AVG;
	
int month_passed = mod(t, strategy_term_aig(t) * 12);
if(xint(month_passed) == 0)
{
	month_passed = strategy_term_aig(t) * 12;
}

if (fund_val_e(t) < model_point_amount_threshold
	// fix divide by 0 issue for edge cases
	|| fia -> surv(t - month_passed) < SMALL_DOUBLE)
	return 0.0;

double strategy_fee_rate, fee_base;

if(t == fia->surr_chg_period_aig * 12 + 1)
{
	return 0;
}
else
{
	// apply strategy term to tier fee
	strategy_fee_rate = eprs_cost_rate_aig(t) * strategy_term_aig(t);
}

fee_base = fund_val_b(t - month_passed + 1); //the beginning of Index Term Account Value
	
// fix surv column timing issue
fee_base = fee_base / fia->surv(t - month_passed) * fia->surv(t);

return min(
		  max(fund_val_e(t) - admin_fee(t) - gmwb_chg_at_surr_aig(t), 0.0),
          strategy_fee_rate *  fee_base * month_passed / (strategy_term_aig(t) * 12)
		  );


}


//@@ END

//@@ START - tier_strat_fee_at_surr_bef_aig
// Tier Strat Fee At Surrender For Inforce End of Month Before Claims                                                                                             
// Column:TIER_STRAT_FEE_AT_SURR_BEF_AIG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_at_surr_bef_aig(int t) {
//^^^



//^^^

#line 1 "tier_strat_fee_at_surr_bef_aig.FIAAFUND_LIAB.for"
// 20220701 STW: new column
// the strategy fee is based on the fund value at the beginning of an index term
// thus the partial strategy fee before or after withdrawal is the same
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue EPS_defn = fia->part_enhancement_method_aig;
if (EPS_defn == NOT_ENHANCED || t <= commencement_period || t > final_period/*maturity_period*/)//WTW - Gen2 - refined time guards
	return NO_AVG;
	
int month_passed = mod(t, strategy_term_aig(t) * 12);
if(xint(month_passed) == 0)
{
	month_passed = strategy_term_aig(t) * 12;
}

if (fund_val_e_bef(t) < model_point_amount_threshold
	// fix divide by 0 issue for edge cases
	|| fia -> surv(t - month_passed) < SMALL_DOUBLE)
	return 0.0;

double strategy_fee_rate, fee_base;

if(t == fia->surr_chg_period_aig * 12 + 1)
{
	return 0;
}
else
{
	// apply strategy term to tier fee
	strategy_fee_rate = eprs_cost_rate_aig(t) * strategy_term_aig(t);
}

fee_base = fund_val_b(t - month_passed + 1); //the beginning of Index Term Account Value

// surv column timing issue
fee_base = fee_base / fia->surv(t - month_passed) * fia->surv(t - 1);

return min(
		  max(fund_val_e_bef(t) - admin_fee(t) - gmwb_chg_at_surr_bef_aig(t), 0.0),
          strategy_fee_rate *  fee_base * month_passed / (strategy_term_aig(t) * 12)
		  );


}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_commencement_period() {
//^^^


#line 1 "commencement_period.FIAAFUND_LIAB.for"
return fia->commencement_period;

}


//@@ END

//@@ START - elapsed_mths
// Months Since Issue                                                                                             
// Calculated Variable:ELAPSED_MTHS
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_elapsed_mths() {
//^^^


#line 1 "elapsed_mths.FIAAFUND_LIAB.for"
return fia->elapsed_mths;

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_final_period() {
//^^^


#line 1 "final_period.FIAAFUND_LIAB.for"
return fia->final_period;

}


//@@ END

//@@ START - lookback_mths
// Lookback Months                                                                                             
// Calculated Variable:LOOKBACK_MTHS
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_mths() {
//^^^


#line 1 "lookback_mths.FIAAFUND_LIAB.for"
fia->pol_yr_lookup_gen2 = fia->pol_yr(0); //WTW - Gen2 - add working variable for lookups that vary by time (not allowed in scalar)
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

if (crediting_rate_defn == MOVING_AVERAGE)
	{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(0); //WTW - Gen2 - add working variable for lookups that vary by time (not allowed in scalar)
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	int crediting_mths_local = crediting_mths;

	return crediting_mths_local//WTW - Gen2 - Mutating Lookup Term used in expression
		   - (crediting_mths_local % lookback_sampling_mths);
	}

return 0;

}


//@@ END

//@@ START - lookback_sampling_mths
// Lookback Sampling Months                                                                                             
// Calculated Variable:LOOKBACK_SAMPLING_MTHS
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_sampling_mths() {
//^^^


#line 1 "lookback_sampling_mths.FIAAFUND_LIAB.for"
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (lookback_sampling_interval == ANNUAL)
	return 12;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (lookback_sampling_interval == SEMIANNUAL)
	return 6;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (lookback_sampling_interval == QUARTERLY)
	return 3;

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (lookback_sampling_interval == MONTHLY)
	return 1;

return 1;

}


//@@ END

//@@ START - maturity_period
// Maturity Period                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_maturity_period() {
//^^^


#line 1 "maturity_period.FIAAFUND_LIAB.for"
return fia->maturity_period;

}


//@@ END

//@@ START - opt_budget_grading_period_aig
// Option Budget Grading Period                                                                                             
// Calculated Variable:OPT_BUDGET_GRADING_PERIOD_AIG
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_grading_period_aig() {
//^^^


#line 1 "opt_budget_grading_period_aig.FIAAFUND_LIAB.for"
// 20190103 MTC - Added Renewal 2019 renewal rate strategy
// DTL 20200401

const int MONTHS_PER_YEAR = 12;
int opt_budget_grading_months_cv = (fia->max_mva_surr_chg_period_aig + fia->opt_bgt_gr_sc_yrs_offset_aig) * MONTHS_PER_YEAR;

/*
int surr_chg_grading_months_cv
	= (fia->surr_chg_period_aig + fia->opt_budget_grading_surr_chg_yrs_offset_aig) * MONTHS_PER_YEARS;
int mva_grading_months_cv
	= fia->mva_period_aig * MONTHS_PER_YEARS;
int opt_budget_grading_months_cv = max(surr_chg_grading_months_cv, mva_grading_months_cv);
*/

return opt_budget_grading_months_cv;

}


//@@ END


#line 1 "barrier_up_and_out_opt_val_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::barrier_up_and_out_opt_val_aig( double underlying_price, double strike_price, double rebate, double barrier_rate, double yrs_to_expiry, double vol, double risk_free_rate, double payout_rate, int call_or_put)
{
	// 20240311 MQ: New function to calculate option price
	// formula provided by MRM

	double r = 2.0 * log(1.0 + risk_free_rate / 2.0);
	double q = log(1.0 + payout_rate);
	double b = r - q;
	double sigmat = vol * pow_legacy(yrs_to_expiry, .5);
	double mu = b / (vol * vol) - 0.5;
	double lamda = pow_legacy(mu * mu + 2 * r / (vol * vol), .5);
	double phi = 1.;
	double eta = -1;
	double opt_price;

	double x1 = log(underlying_price / strike_price) / sigmat + (1 + mu) * sigmat;
	double x2 = log(underlying_price / barrier_rate) / sigmat + (1 + mu) * sigmat;
	double y1 = log((barrier_rate * barrier_rate) / (underlying_price * strike_price)) / sigmat + (1 + mu) * sigmat;
	double y2 = log(barrier_rate / underlying_price) / sigmat + (1 + mu) * sigmat;
	double z  = log(barrier_rate / underlying_price) / sigmat + lamda * sigmat;
	double alpha = phi * underlying_price * exp((b - r) * yrs_to_expiry);
	double beta = phi * strike_price * exp(- r * yrs_to_expiry);

	if (call_or_put == CALL_CODE)
	{
		if(strike_price >= barrier_rate)
		{
			opt_price
			=  rebate * ( pow_legacy(barrier_rate / underlying_price, mu + lamda) * cumul_normal_distribn(eta * z) + 
				pow_legacy(barrier_rate / underlying_price, mu - lamda) * cumul_normal_distribn(eta * z - 2 * eta * lamda * sigmat));				
		}
		else
		{
			opt_price
			= alpha * cumul_normal_distribn(phi * x1) - beta * cumul_normal_distribn(phi * x1 - phi * sigmat) 
				- alpha * cumul_normal_distribn(phi * x2) + beta * cumul_normal_distribn(phi * x2 - phi * sigmat) 
				+ alpha * (pow_legacy(barrier_rate / underlying_price, 2 * mu + 2)) * cumul_normal_distribn(eta * y1) 
				- beta * (pow_legacy(barrier_rate / underlying_price, 2 * mu)) * cumul_normal_distribn(eta * y1 - eta * sigmat) 
				- alpha * (pow_legacy(barrier_rate / underlying_price, 2* mu + 2)) * cumul_normal_distribn(eta * y2) 
				+ beta * (pow_legacy(barrier_rate / underlying_price, 2 * mu)) * cumul_normal_distribn(eta * y2 - eta * sigmat) 
				+ rebate * (pow_legacy(barrier_rate / underlying_price, mu + lamda) * cumul_normal_distribn(eta * z)
				+ pow_legacy(barrier_rate / underlying_price, mu - lamda) * cumul_normal_distribn(eta * z - 2 * eta * lamda * sigmat));
		}
				
	}

	if (call_or_put == PUT_CODE)
	{
		phi = -1.;
		alpha = phi * underlying_price * exp((b - r) * yrs_to_expiry);
		beta = phi * strike_price * exp(- r * yrs_to_expiry);

		opt_price
		=  alpha * cumul_normal_distribn(phi * x1) - beta * cumul_normal_distribn(phi * x1 - phi * sigmat)
			- alpha * (pow_legacy(barrier_rate / underlying_price, 2 * mu + 2)) * cumul_normal_distribn(eta * y1) 
			+ beta * (pow_legacy(barrier_rate / underlying_price, 2 * mu)) * cumul_normal_distribn(eta * y1 - eta * sigmat) 
			+ rebate * (pow_legacy(barrier_rate / underlying_price, mu + lamda) * cumul_normal_distribn(eta * z)
			+ pow_legacy(barrier_rate / underlying_price, mu - lamda) * cumul_normal_distribn(eta * z - 2 * eta * lamda * sigmat));

		}

  return opt_price;
}



#line 1 "barrier_up_out_digital_opt_val_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::barrier_up_out_digital_opt_val_aig( double underlying_price, double rebate, double barrier_rate, double yrs_to_expiry, double vol, double risk_free_rate, double payout_rate)
{
	// 20240528 MQ: New function to calculate option price: Knockout Digital for Inner Loop

	double r = 2.0 * log(1.0 + risk_free_rate / 2.0);
	double q = log(1.0 + payout_rate);
	double b = r - q;
	double sigmat = vol * pow_legacy(yrs_to_expiry, .5);
	double mu = b / (vol * vol) - 0.5;
	double lamda = pow_legacy(mu * mu + 2 * r / (vol * vol), .5);
	double eta = -1;
	double opt_price;

	double z  = log(barrier_rate / underlying_price) / sigmat + lamda * sigmat;

	opt_price = rebate * (pow_legacy(barrier_rate / underlying_price, mu + lamda) * cumul_normal_distribn(eta * z)
			+ pow_legacy(barrier_rate / underlying_price, mu - lamda) * cumul_normal_distribn(eta * z - 2 * eta * lamda * sigmat));

	return opt_price;
}



#line 1 "cap_solver_mthly_sum_cap.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::cap_solver_mthly_sum_cap(int t) 
{
double long_option_cost = 0.0;
double cap = 0.0;
double option_budget = opt_budget(t);
	
// Variable declaration
double strike_curr = 0.0;
double long_opt_strike_price = 0.0;
double periods_to_expiry = strategy_term_aig(t); //crediting_mths / 12.0;  // 20190613 DTL : replaced `crediting_mths`

//Solve for call spread variables
int iteration = 0;
int maximum_iterations = 100;
double initial_guess_cap = 0.01;

double crediting_cap_minimum_cv;
// `crediting_cap_min` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_min_aig`
crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);

double low_cap = crediting_cap_minimum_cv; // = crediting_cap_min; DTL 2010415

double low_remainder = 0.0;

double crediting_cap_maximum_cv;
// `crediting_cap_max` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_max_aig`
crediting_cap_maximum_cv = index_term_cap_rate_max_col_aig(t);

double high_cap = crediting_cap_maximum_cv;  //  " = crediting_cap_max;"  DTL 20190415

double high_remainder = 0.0;
double guess_cap = 0.0;
double guess_remainder = 99999.0;
double solve_tolerance = rate_ratio_threshold;
double preliminary_guess_cap = 0.0;
double first_difference_1 = 0.0;
double first_difference_2 = 0.0;
double second_difference = 0.0;
double min_strike = 0.0;
double underlying_bom = index_val_bom(t); 
double at_the_money_strike = index_val_bom(t);
double direction_counter = 0;

if (option_budget < rate_ratio_threshold)
	{
	cap = crediting_cap_minimum_cv; // "cap = crediting_cap_min;" DTL 20190415
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		log_screen << "Warning: The option budget is 0 at t = " << t << " for account " << fund_id 
				   << ", The cap rate has been set to " << cap << MSG_STATUS;
	return cap;
	}

static bool first_header = true;

long_option_cost 
= 1.0 / underlying_bom 
  * mkt_val_calc(t - 1,
		xint(fia->cal_yr_relative(t - 1)),
		xint(fia->cal_mth(t - 1)),
		lookback_defn,
		lookback_mths,
		lookback_sampling_mths,
		1.0, // index_units_owned(t)
		underlying_bom,
		index_scen_mult,
		index_scen_sprd_addn,
		periods_to_expiry,
		div_yld_scen_mult,
		div_yld_sprd,
		opt_strike_price(t),
		payout_index_max,
		crediting_cap_maximum_cv,    // "crediting_cap_max," DTL 20190415
		CALL, //opt_defn
		0.0, // spot_sprd_adj,
		0.0, // volatility_sprd_adj,
		NO_SHIFT); // shift_defn 

// Only execute solver if option_budget < long_option_cost
if (option_budget < long_option_cost)
	{
	// Initial setup
	low_cap = crediting_cap_minimum_cv; // " = crediting_cap_min;" DTL 20190415
	low_remainder = - option_budget;
	high_cap = crediting_cap_maximum_cv;   // "high_cap = crediting_cap_max;" DTL 20190415

	// Determine initial high remainder
	double init_guess
	= 1.0 / underlying_bom
	  * mkt_val_calc(t - 1,
			xint(fia->cal_yr_relative(t - 1)),
			xint(fia->cal_mth(t - 1)),
			lookback_defn,
			lookback_mths,
			lookback_sampling_mths,
			1.0, // index_units_owned(commencement_period)
			underlying_bom,
			index_scen_mult,
			index_scen_sprd_addn,
			periods_to_expiry,
			div_yld_scen_mult,
			div_yld_sprd,
			opt_strike_price(t),
			payout_index_max,
			high_cap,
			CALL, //opt_defn
			0.0, // spot_sprd_adj,
			0.0, // volatility_sprd_adj,
			NO_SHIFT); // shift_defn

	high_remainder = init_guess
	                 - option_budget;

	preliminary_guess_cap = low_cap;

	while (fabs(guess_remainder) > solve_tolerance 
			&& iteration < maximum_iterations
			&& (high_remainder - low_remainder) > rate_ratio_threshold)
		{
		if (iteration > 0
			&& fabs(guess_remainder - low_remainder) > rate_ratio_threshold
			&& fabs(high_remainder - guess_remainder) > rate_ratio_threshold)
			{
			// Calculate final cap based on calculated low, guess, and high remainders
			// using the following difference table.
			//
			//   Remainder        Cap     1st Difference      2nd Difference
			//   ---------      -------   --------------     ---------------
			//   low               l   
			//                                  g - l
			//                            A = -----------
			//                                guess - low           B - A 
			//   guess             g                           C = ----------
  			//                                  h - g              high - low
  			//                            B = ---------
			//                                high - guess
			//   high              h 
			//
			//   guess = l + (-low) * A + (-low) * (-guess) * C
			//
			//   if guess is out of bounds, use bisection. For first and last
			//   pass use linear interpolation.
			//
			//   This adjustment is being made because of nonlinear dependence
			//   of the difference on the guess cap value.
			first_difference_1 = (guess_cap - low_cap)
		  						/ (guess_remainder - low_remainder);
		  
			first_difference_2 = (high_cap - guess_cap)
		  						/ (high_remainder - guess_remainder);
		  
			second_difference = (first_difference_2 - first_difference_1)
		  						/ (high_remainder - low_remainder);
		  
			preliminary_guess_cap = low_cap
								    - low_remainder * first_difference_1
									- low_remainder 
									   * (- guess_remainder)      
									   * second_difference;
									 
			if (guess_remainder < solve_tolerance)
				{
				low_cap = guess_cap;
				low_remainder = guess_remainder;
				}
			else
				{
				high_cap = guess_cap;
				high_remainder = guess_remainder;
				}	    
			}

		if ((low_cap < high_cap
			 && preliminary_guess_cap < high_cap
			 && preliminary_guess_cap > low_cap)
			|| (low_cap > high_cap
				&& preliminary_guess_cap > high_cap
				&& preliminary_guess_cap < low_cap))
			{
			guess_cap = preliminary_guess_cap;
			}
		else if (iteration > 0 && iteration < maximum_iterations)
			guess_cap = low_cap + (high_cap - low_cap) / 2.0;
		else
			guess_cap = low_cap 
						   + (high_cap - low_cap)
		  				   * (- low_remainder) / (high_remainder - low_remainder);
		
		// determine difference for guess_cap	
		double next_guess
		= 1.0 / underlying_bom
		  * mkt_val_calc(t - 1,
				xint(fia->cal_yr_relative(t - 1)),
				xint(fia->cal_mth(t - 1)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				1.0, // index_units_owned(commencement_period)
				underlying_bom,
				index_scen_mult,
				index_scen_sprd_addn,
				periods_to_expiry,
				div_yld_scen_mult,
				div_yld_sprd,
				opt_strike_price(t),
				payout_index_max,
				guess_cap,
				CALL, //opt_defn
				0.0, // spot_sprd_adj,
				0.0, // volatility_sprd_adj,
				NO_SHIFT); // shift_defn 

		guess_remainder = next_guess
		                  - option_budget;

		iteration++;			  
		}
	cap = guess_cap;
	}
else
	cap = crediting_cap_maximum_cv;   // "cap = crediting_cap_max;" DTL 20190415

if (cap < crediting_cap_minimum_cv)   // "if (cap < crediting_cap_min)"  DTL 20190415
	{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		{
		log_screen << "Warning: The solved for cap rate < minimum cap rate at t = " << t 
				   << " for account " << fund_id << "." << MSG_STATUS;
		log_screen << "The cap rate has been set to " << crediting_cap_minimum_cv << MSG_STATUS; // "<< crediting_cap_min << MSG_STATUS;" DTL 20190415
		}	
	cap = crediting_cap_minimum_cv;    // "cap = crediting_cap_min;" DTL 20190415
	}

if (cap >= crediting_cap_maximum_cv)  // "if (cap >= crediting_cap_max)" DTL 20190415
	{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		{
		log_screen << "Warning: The solved for cap rate > maximum cap rate at t = " << t 
				   << " for account " << fund_id <<  "." << MSG_STATUS;
		log_screen << "The cap rate has been set to " << crediting_cap_maximum_cv << MSG_STATUS;   // "<< crediting_cap_max << MSG_STATUS;" DTL 20190415
		}	
	cap = crediting_cap_maximum_cv;    // "cap = crediting_cap_max;"  DTL 20190415
	}
		
cap = round(cap * 400.0, 0) / 400.0;

return cap;
}



#line 1 "cap_solver_point_to_point_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::cap_solver_point_to_point_aig(int t, double buffer_amt, double floor_amt)
{
    double crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);
	double crediting_cap_maximum_cv	= index_term_cap_rate_max_col_aig(t);

	// 20201014 DTL
	double crediting_rate_floor_cv	= strategy_term_floor_col_aig(t);
	// 20201014 DTL

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double rila_ind = fia->rila_ind;
	
	double cap;
	double option_budget = 0.0;
/*	if(rila_ind)
	{
		if(t + elapsed_mths < strategy_term_mths_aig(t))
		{
			option_budget = opt_budget(t);
		}
		else
		{
			double strategy_months = 12.0 * strategy_term_aig(t);
			double current_strategy_period = floor((t + elapsed_mths - 1)/strategy_months);
			double initial_option_price_time = current_strategy_period * strategy_months + 1;
			option_budget = opt_budget_renewal_aig(max(initial_option_price_time - valn_period, 1));
		}
		
	}
	else
	{*/
		option_budget = opt_budget(t);
	//}
	
	if (rila_ind)
	{
		if (buffer_amt != 0)
		{
			//Buffer Cap
			double long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_call_option_cost		= get_option_price_aig(t - 1, 1 + crediting_cap_minimum_cv, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double benchmark_option_cost		= long_call_option_cost - short_call_option_cost - short_put_option_cost;
			
			if (option_budget < benchmark_option_cost)
			{
				cap = crediting_cap_minimum_cv;
				return cap;
			}
		}
		else
		{
			//Floor Cap
			double long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_call_option_cost		= get_option_price_aig(t - 1, 1 + crediting_cap_minimum_cv, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double long_put_option_cost			= get_option_price_aig(t - 1, 1 + floor_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double benchmark_option_cost		= long_call_option_cost - short_call_option_cost + long_put_option_cost - short_put_option_cost;
			if (option_budget < benchmark_option_cost)
			{
				cap = crediting_cap_minimum_cv;
				return cap;
			}
		}
	}
	else
	{
		if (option_budget < rate_ratio_threshold)
		{
			cap = crediting_cap_minimum_cv;
			return cap;
		}
	}
	const double TABLE_ATM_STRIKE	= 1.0;
	double long_strike				= TABLE_ATM_STRIKE + crediting_rate_floor_cv;  // 20201014 DTL

	/*  // 20201014 DTL
	if ( opt_strike_price(t) - index_val(t) > SMALL_DOUBLE &&
		 index_val(t - 1) > SMALL_DOUBLE                         )
	{
		//We guarantee some non-zero index credit
		long_strike = opt_strike_price(t) / index_val(t - 1) - 1.0;
	}
	*/
	double long_cost		= get_option_price_aig(t - 1, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
	const double FWD_TERM	= 0.0;
	double rf_rate_cv = 0.0;

	if (fia->gen2_defn == YES)
		rf_rate_cv		= fia_rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  // 20201014 DTL
	else
		rf_rate_cv		= rates->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, strategy_term_aig(t), FWD_TERM, EFFECTIVE_ANNUAL, NO_SHIFT);  // 20201014 DTL

	
	double cost_without_cap = 0.0;

	if (rila_ind && buffer_amt != 0) 
		{
			//Buffer Cap
			double long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_put_option_cost		= get_option_price_aig(t - 1, 1 - buffer_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			long_cost = long_call_option_cost;
			cost_without_cap = long_cost - short_put_option_cost;

		}
	else if (rila_ind && buffer_amt == 0)
		{
			//Floor Cap
			double long_call_option_cost		= get_option_price_aig(t - 1, 1, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double long_put_option_cost			= get_option_price_aig(t - 1, 1 + floor_amt, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			double short_put_option_cost		= get_option_price_aig(t - 1, 1, PUT, strategy_term_mths_aig(t), index_term_mths_aig(t));
			long_cost = long_call_option_cost + long_put_option_cost;
			cost_without_cap = long_cost - short_put_option_cost;

		}
	else if (rila_ind == 0)
	{
		long_cost			   += crediting_rate_floor_cv / (1 + rf_rate_cv);  // 20201014 DTL
	}
	double shortfall = 0.0;
	if (option_budget > long_cost || (option_budget > cost_without_cap && rila_ind))
	{
		cap = crediting_cap_maximum_cv;
	}
	else
	{
		//Original Cap Solve
		//Shortfall will change depending on the option strategy
		//If there is a buffer, a short put will lower the shortfall...

		//WTW: RILA Functionality
		if (rila_ind) 
		{
			//Buffer Cap || Floor Cap
			shortfall				= cost_without_cap - option_budget;
		}
		else
		{
			//Non RILA products
			shortfall				= long_cost - option_budget;
		}
		
		//double shortfall = 1;
		//Lower shortfall will yield a higher cap from this function
		double table_short_strike		= get_option_strike_aig(t - 1, shortfall, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));

		double proposed_earnings_cap	= table_short_strike - 1.0;

		if (proposed_earnings_cap > crediting_cap_maximum_cv)
		{
			cap = crediting_cap_maximum_cv;
		}
		else if (proposed_earnings_cap < crediting_cap_minimum_cv)
		{
			cap = crediting_cap_minimum_cv;
		}
		else
		{
			cap = proposed_earnings_cap;
		}
	}

	return cap;
}



#line 1 "cap_solver_point_to_point_moving_avg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::cap_solver_point_to_point_moving_avg(int t)
{

double crediting_cap_minimum_cv;
// `crediting_cap_min` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_min_aig`
crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);

double crediting_cap_maximum_cv;
// `crediting_cap_max` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_max_aig`
crediting_cap_maximum_cv = index_term_cap_rate_max_col_aig(t);

double long_option_cost = 0.0;
double cap = 0.0;
double option_budget = opt_budget(t);
	
// Variable declaration
double strike_curr = 0.0;
double long_opt_strike_price = 0.0;
double periods_to_expiry = strategy_term_aig(t);    // crediting_mths / 12.0;// 20190613 DTL : replaced `crediting_mths`

//Solve for call spread variables
int iteration = 0;
int maximum_iterations = 100;
double initial_guess_multiple = 2.0;
double low_strike = 0.0;
double low_remainder = 0.0;
double high_strike = 0.0;
double high_remainder = 0.0;
double guess_strike = 0.0;
double guess_remainder = 99999.0;
double solve_tolerance = rate_ratio_threshold;
double preliminary_guess_strike = 0.0;
double first_difference_1 = 0.0;
double first_difference_2 = 0.0;
double second_difference = 0.0;
double min_strike = 0.0;
double underlying_bom = index_val_bom(t); 
double at_the_money_strike = index_val_bom(t);
double direction_counter = 0;


if (option_budget < rate_ratio_threshold)
	{
	cap = crediting_cap_minimum_cv;   // "cap = crediting_cap_min;" DTL 20190415
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		log_screen << "Warning: The option budget is 0 at t = " << t << " for account " << fund_id 
				   << ", The cap rate has been set to " << cap << MSG_STATUS;
	return cap;
	}
	
static bool first_header = true;

long_option_cost 
= 1.0 / underlying_bom 
  * mkt_val_calc(t - 1,
		xint(fia->cal_yr_relative(t - 1)),
		xint(fia->cal_mth(t - 1)),
		lookback_defn,
		lookback_mths,
		lookback_sampling_mths,
		1.0, // index_units_owned(t)
		underlying_bom,
		index_scen_mult,
		index_scen_sprd_addn,
		periods_to_expiry,
		div_yld_scen_mult,
		div_yld_sprd,
		opt_strike_price(t),
		payout_index_max,
		cap,
		CALL, //opt_defn
		0.0, // spot_sprd_adj,
		0.0, // volatility_sprd_adj,
		NO_SHIFT); // shift_defn 



// Only execute solver if option_budget < long_option_cost
if (option_budget < long_option_cost)
	{
	// Initial setup
	low_strike = opt_strike_price(t);
	low_remainder = - option_budget;
	high_strike = low_strike * initial_guess_multiple;

	// Determine initial high remainder
	double init_guess
	= - 1.0 / underlying_bom
	  * mkt_val_calc(t - 1,
			xint(fia->cal_yr_relative(t - 1)),
			xint(fia->cal_mth(t - 1)),
			lookback_defn,
			lookback_mths,
			lookback_sampling_mths,
			1.0, // index_units_owned(commencement_period)
			underlying_bom,
			index_scen_mult,
			index_scen_sprd_addn,
			periods_to_expiry,
			div_yld_scen_mult,
			div_yld_sprd,
			high_strike,
			payout_index_max,
			cap,
			CALL, //opt_defn
			0.0, // spot_sprd_adj,
			0.0, // volatility_sprd_adj,
			NO_SHIFT); // shift_defn

	high_remainder = long_option_cost
					 - option_budget
					 + init_guess;

	preliminary_guess_strike = low_strike;

	while (fabs(guess_remainder) > solve_tolerance 
			&& iteration < maximum_iterations
			&& (high_remainder - low_remainder) > rate_ratio_threshold)
		{
		if (iteration > 0
			&& fabs(guess_remainder - low_remainder) > rate_ratio_threshold
			&& fabs(high_remainder - guess_remainder) > rate_ratio_threshold)
			{
			// Calculate final strike based on calculated low, guess, and high remainders
			// using the following difference table.
			//
			//   Remainder      Strike    1st Difference      2nd Difference
			//   ---------      -------   --------------     ---------------
			//   low               l   
			//                                  g - l
			//                            A = -----------
			//                                guess - low           B - A 
			//   guess             g                           C = ----------
  			//                                  h - g              high - low
  			//                            B = ---------
			//                                high - guess
			//   high              h 
			//
			//   guess = l + (-low) * A + (-low) * (-guess) * C
			//
			//   if guess is out of bounds, use bisection. For first and last
			//   pass use linear interpolation.
			//
			//   This adjustment is being made because of nonlinear dependence
			//   of the difference on the guess strike value.
			first_difference_1 = (guess_strike - low_strike)
		  						/ (guess_remainder - low_remainder);
		  
			first_difference_2 = (high_strike - guess_strike)
		  						/ (high_remainder - guess_remainder);
		  
			second_difference = (first_difference_2 - first_difference_1)
		  						/ (high_remainder - low_remainder);
		  
			preliminary_guess_strike = low_strike
									   - low_remainder * first_difference_1
									   - low_remainder 
										 * (- guess_remainder)      
										 * second_difference;
									 
			if (guess_remainder < solve_tolerance)
				{
				low_strike = guess_strike;
				low_remainder = guess_remainder;
				}
			else
				{
				high_strike = guess_strike;
				high_remainder = guess_remainder;
				}	    
			}

		if ((low_strike < high_strike
			 && preliminary_guess_strike < high_strike
			 && preliminary_guess_strike > low_strike)
			|| (low_strike > high_strike
				&& preliminary_guess_strike > high_strike
				&& preliminary_guess_strike < low_strike))
			{
			guess_strike = preliminary_guess_strike;
			}
		else if (iteration > 0 && iteration < maximum_iterations)
			guess_strike = low_strike + (high_strike - low_strike) / 2.0;
		else
			guess_strike = low_strike 
						   + (high_strike - low_strike)
		  				   * (- low_remainder) / (high_remainder - low_remainder);
		
		// determine difference for guess_strike	
		double next_guess
		= - 1.0 / underlying_bom
		  * mkt_val_calc(t - 1,
				xint(fia->cal_yr_relative(t - 1)),
				xint(fia->cal_mth(t - 1)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				1.0, // index_units_owned(commencement_period)
				underlying_bom,
				index_scen_mult,
				index_scen_sprd_addn,
				periods_to_expiry,
				div_yld_scen_mult,
				div_yld_sprd,
				guess_strike,
				payout_index_max,
				cap,
				CALL, //opt_defn
				0.0, // spot_sprd_adj,
				0.0, // volatility_sprd_adj,
				NO_SHIFT); // shift_defn 

		guess_remainder = long_option_cost
						  - option_budget
						  + next_guess;

		iteration++;	
				  
/*log_screen<<"t= "<<t
<<" option_budget= "<<opt_budget(t)
<<" opt_strike_price(t)= "<<opt_strike_price(t)
<<" long_option_cost= "<<long_option_cost
<<" next_guess= "<<next_guess
<<" guess_remainder= "<<guess_remainder
<<" solve_tolerance= "<<solve_tolerance
<<" guess_strike= "<<guess_strike
<<" at_the_money_strike= "<<at_the_money_strike
<<" underlying_bom= "<<underlying_bom
<<" index_val(t)= "<<index_val(t-1)
<<MSG_USER;*/

		if (option_budget < long_option_cost)
			cap = (guess_strike / at_the_money_strike ) - 1.0;
		else
			{		
			cap = crediting_cap_maximum_cv;  // "cap = crediting_cap_max;" DTL 20190415
			break;
			}
		
		if (cap < crediting_cap_minimum_cv)  // "if (cap < crediting_cap_min)" DTL 20190415
			{
			direction_counter++;
		
			if (direction_counter > 5)
				break;	
			}
		}
	}
else
	cap = crediting_cap_maximum_cv;  // "cap = crediting_cap_max;" DTL 20190415

if (cap < crediting_cap_minimum_cv)  // "if (cap < crediting_cap_min)" DTL 20190415
	{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		{
		log_screen << "Warning: The solved for cap rate < minimum cap rate at t = " << t 
				   << " for account " << fund_id << "." << MSG_STATUS;
		log_screen << "The cap rate has been set to " << crediting_cap_minimum_cv << MSG_STATUS;  // "<< crediting_cap_min << MSG_STATUS;" DTL 20190415
		}	
	cap = crediting_cap_minimum_cv;  // "cap = crediting_cap_min;" DTL 20190415
	
	// If cap below min need to reset shorted asset
	min_strike = underlying_bom * crediting_cap_minimum_cv;  // "min_strike = underlying_bom * crediting_cap_min;" DTL 20190415
	}

if (cap >= crediting_cap_maximum_cv)  // "if (cap >= crediting_cap_max)" DTL 20190415
	{
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	if (display_solver_warnings_defn == YES)
		{
		log_screen << "Warning: The solved for cap rate > maximum cap rate at t = " << t 
				   << " for account " << fund_id <<  "." << MSG_STATUS;
		log_screen << "The cap rate has been set to " << crediting_cap_maximum_cv << MSG_STATUS;  // "<< crediting_cap_max << MSG_STATUS;" DTL 20190415
		}	
	cap = crediting_cap_maximum_cv;  // "cap = crediting_cap_max;" DTL 20190415
	
	// reset short option
	guess_strike = ((crediting_cap_maximum_cv) + 1) * at_the_money_strike;  // "guess_strike = ((crediting_cap_max) + 1) * at_the_money_strike;" DTL 20190415
	}
		
//cap = round(cap * 400.0, 0) / 400.0;

return cap;
}



#line 1 "cast_xstring_to_string_aig.FIAAFUND_LIAB.for"                                                                                   
std::string FIAAFUND_LIAB::cast_xstring_to_string_aig(const xstring& input_xstring)
{
  std::string output_string = "";
  for (int i=0; i<input_xstring.length(); i++) {
       output_string += input_xstring[i];
  }
  return output_string;
}




#line 1 "current_opt_defn_func_aig.FIAAFUND_LIAB.for"                                                                                   
StrEnum::EnumValue FIAAFUND_LIAB::current_opt_defn_func_aig(int option_flag)
{
	// 20200622 STW: new function to identify the option defination
	// Added new cases for ITM option table. MCHING 9-6-2021

	StrEnum::EnumValue opt_defn;

	switch (option_flag)
	{
		case 0:
			opt_defn = RATCHET_PART;
			break;

		case 1:
			opt_defn = RATCHET_SPRD;
			break;

		case 2:
			opt_defn = CALL;
			break;

		case 3:
			opt_defn = ITMNESS_PART;  // MCHING 9-6-2021
			break;

		case 4:
			opt_defn = ITMNESS_SPRD;  // MCHING 9-6-2021
			break;

		case 5:
			opt_defn = CALLK;  // MQ 3-15-2024
			break;

		case 6:
			opt_defn = PUTK;  // MQ 3-15-2024
			break;

		case 7:
			opt_defn = CSEC;  // MQ 3-15-2024
			break;

		default:
			throw FatalError("Unhandled option_flag requested in current_opt_defn_func_aig!");
			break;
	}

	return opt_defn;

}



#line 1 "get_buffer_rate_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_buffer_rate_aig(double rebate, double barrier, double strategy_term, double vol, double rf_rate_cv, double dividend_yld, double cost)
{
	//20240311 MQ: New function to solve buffer rate.
	//Not used for now
	double final_strike = 0.0;
	double step = 0.0;
	double guess_a = 1.0;
	double guess_b = 1.0;
	int stop = 0;
	int first_time = 0;
	double option_cost_a = 0.0;
	double option_cost_b = 0.0;

	//Loop to find 6 digits of the unitized strike which equates the calculated option price to the input option cost
	for (int i = 1; i < 6; i++)
	{
		stop = 0;
		first_time = 1;

		guess_b = guess_a;

		for (int j = 1; stop != 1; j++)
		{
			step = pow(0.1, i);

			guess_a = guess_b;
			guess_b = guess_b + step;
				
			if(first_time == 1)
			{
				option_cost_a = barrier_up_and_out_opt_val_aig(1, guess_a, rebate, barrier, strategy_term, vol, rf_rate_cv, dividend_yld, PUT_CODE);
						
				option_cost_b = barrier_up_and_out_opt_val_aig(1, guess_b, rebate, barrier, strategy_term, vol, rf_rate_cv, dividend_yld, PUT_CODE);
			}
			else
			{
				option_cost_a = option_cost_b;
				option_cost_b = barrier_up_and_out_opt_val_aig(1, guess_b, rebate, barrier, strategy_term, vol, rf_rate_cv, dividend_yld, PUT_CODE);
			}
					

			first_time = 0;

			//Check to see if the option cost is between a and b strikes
			if ( ( (option_cost_a - cost) <= 0 && (option_cost_b - cost) >= 0 ) || ( (option_cost_a - cost) >= 0 && (option_cost_b - cost) <= 0 ) || j > 1000)
			{
				//inflection point found
				stop = 1;
			}
			else
			{
				stop = 0;
			}
		}
	}
		return (guess_a + guess_b) / 2.0;

}



#line 1 "get_option_price_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_option_price_aig(
	int projection_month, double strike, StrEnum::EnumValue opt_defn, int option_duration_mths, int input_strike_period_mths, int knockout )
{
	if(pba_valn_flag)
	{		
		strike = max(strike, 0.01);

		const double FWD_TERM	= 0.0;
		double rf_rate_cv = 0.0;
		if (fia->gen2_defn == YES) //20240321 MQ use spot rate
		{
			rf_rate_cv  = fia_rates->get_int_rate(projection_month, "Govt", GET_SPOT_RATE, option_duration_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		}
		else
		{
			rf_rate_cv	= rates->get_int_rate(projection_month, "Govt", GET_SPOT_RATE, option_duration_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		}

		double vol_param = 0.0;
		double dividend_yld = 0.0;
		double option_cost = 0.0;

		//20240229 MQ New BS vol lookup
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		xstring crediting_eqt_index_local = crediting_eqt_index;

		fia->index_id_lookup = crediting_eqt_index_local;
		dividend_yld = exp(fia->dividend_inner_aig) - 1.;

		if (opt_defn == CALL)
		{
			//vol_param = fia->bs_vol_param(1, 1 * strike, "call", option_duration_mths / 12.);
			fia->bs_init_vol_type = "base";
			fia->index_id_lookup = crediting_eqt_index_local;
			vol_param = fia->bs_fwrd_vol_aig;
			option_cost = bs_opt_val(1 * strike, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		}
		else
		{
			//vol_param = fia->bs_vol_param(1, 1 * strike, "put", option_duration_mths / 12.);
			fia->bs_init_vol_type = "base";
			fia->index_id_lookup = crediting_eqt_index_local;
			vol_param = fia->bs_fwrd_vol_aig;
			option_cost = bs_opt_val(1 * strike, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
		}
			
		return option_cost;
	}
	else
	{
		string option_type_string;
		if (opt_defn == CALL)
		{
			option_type_string = "CALL";
		}
		else if (opt_defn == PUT)
		{
			option_type_string = "PUT";
		}
		else if (opt_defn == CALLK)
		{
			option_type_string = "CALLK"; // 20240311 MQ: New option header
		}
		else if (opt_defn == PUTK)
		{
			option_type_string = "PUTK";
		}
		else if (opt_defn == CSEC)
		{
			option_type_string = "CSEC"; // 20240311 MQ: New option header
		}
		else
		{
			throw FatalError("'fia_account->get_option_price_aig(...)': undefined 'opt_defn'!");
		}

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	
	//20230105 SJ: replace the regex function to improve the runtime.
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(option_duration_mths);  // 20191212 DTL
		string option_duration_regex_str = option_duration_str + "\\D"; // 20191212 DTL
	
		vector<int> table_strikes;
		vector <xstring> misc_id_list;

		if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
			misc_id_list = fia_rates->misc_list;
		else
			misc_id_list = rates->misc_list;

		string complete_key = option_type_string+ "_" + index_id_regex_str + "_" + option_duration_str + "_K";

		if(knockout > SMALL_DOUBLE) // 20240311 MQ: Additional character for knockout strategy
		{
			string knockout_str = to_string(knockout);
			complete_key = complete_key + knockout_str +  "_K";
		}

		for (auto misc_id: misc_id_list) 
		{
			misc_id.to_upper();
			const int NOT_FOUND_CODE = -1;
			if (misc_id.find(complete_key) != NOT_FOUND_CODE) 
			{			
				string misc_id_string = cast_xstring_to_string_aig(misc_id);

				int K = atoi(misc_id_string.substr(complete_key.length()).c_str());
				table_strikes.push_back(K);			
			}

		}	
	//20230105 SJ END

		if (table_strikes.size() == 0)
		{
			// 20191015 MTC - Added more descriptive error message
			// Added even more descriptive error message.  MCHING 2-9-2022
			string projection_month_str = to_string(projection_month);
			xstring error_msg = "'fia_account->get_option_price_aig(...)': cannot locate option costs in scenario file! Field search: '" + option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K*' at t=" + projection_month_str + " for group='" + group + "'";
			throw FatalError(error_msg);
		}

		sort(table_strikes.begin(), table_strikes.end());

		int number_of_strikes = table_strikes.size();
		table_strikes.erase( unique( table_strikes.begin(), table_strikes.end() ), table_strikes.end());
		if (number_of_strikes != table_strikes.size())
		{
			throw FatalError("'fia_account->get_option_price_aig(...)': duplicate strike data found in scenario file!");
		}

		double interpolated_option_cost;
		const int FIRST_INDEX = 0;
		const int LAST_INDEX = table_strikes.size() - 1;
		const int ONE_INDEX = 1;
		const double ONE_HUNDRED = 100;

		// DTL 20200109 (START): TFS 86561
		double strike_lookup_adjustment = 1.0;
		if (!(opt_defn == CSEC))  // Bugfix to ITMNESS_PART option cost lookup consistency with RATCHET_PART.  MCHING 9-10-2021
		{
			if(fia->option_strike_annualization_aig != ANNUALIZED)
			{
				strike_lookup_adjustment = double(option_duration_mths) / double(input_strike_period_mths);
			}
			else
			{
				strike_lookup_adjustment = 12.0 / double(input_strike_period_mths);
			}

			if ( opt_defn == CALL || opt_defn == CALLK)
			{
				strike = (strike - 1.0) * strike_lookup_adjustment + 1.0;
			}
			else
			{
				strike *= strike_lookup_adjustment;
			}
		}
		// DTL 20200109 (END): TFS 86561


		strike *= ONE_HUNDRED;
		for (vector<int>::size_type i = 0; i != table_strikes.size(); i++)
		{
			double table_strike = table_strikes.at(i);
			string table_lookup 
				= option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K" + to_string((int)table_strike); // 20191212 DTL

			if(knockout > SMALL_DOUBLE)
			{
				table_lookup = option_type_string + "_" + index_id_regex_str + "_" + option_duration_str 
					+ "_K" + to_string(knockout) + "_K" + to_string((int)table_strike);
			}

			double table_option_cost = 0.0;
			if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
				table_option_cost = fia_rates->get_misc_rate(projection_month, table_lookup, EFFECTIVE_ANNUAL);
			else
				table_option_cost = rates->get_misc_rate(projection_month, table_lookup, EFFECTIVE_ANNUAL);

			if (i == FIRST_INDEX && strike <= table_strike)
			{
				interpolated_option_cost = table_option_cost;
				break;
			}
			else if (i == LAST_INDEX && strike >= table_strike)
			{
				interpolated_option_cost = table_option_cost;
				break;
			}
			else if (table_strike > strike)
			{
				double lower_strike = table_strikes.at(i - ONE_INDEX);
				double higher_strike = table_strike;
				double lower_strike_weight = (higher_strike - strike)/(higher_strike - lower_strike);
				double higher_strike_weight = (strike - lower_strike)/(higher_strike - lower_strike);

				string lower_strike_table_lookup 
					= option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K" + to_string((int)lower_strike); // 20191212 DTL

				if(knockout > SMALL_DOUBLE)
				{
					lower_strike_table_lookup = option_type_string + "_" + index_id_regex_str + "_" + option_duration_str 
						+ "_K" + to_string(knockout) + "_K" + to_string((int)lower_strike);
				}

				double price_below = 0.0;
				if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
					price_below = fia_rates->get_misc_rate(projection_month, lower_strike_table_lookup, EFFECTIVE_ANNUAL);
				else
					price_below = rates->get_misc_rate(projection_month, lower_strike_table_lookup, EFFECTIVE_ANNUAL);
			
				double price_above = table_option_cost;

				interpolated_option_cost = lower_strike_weight * price_below + higher_strike_weight * price_above;
				break;
			}
		}

		return interpolated_option_cost;
	}

 	
}



#line 1 "get_option_strike_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_option_strike_aig(
	int projection_month, double cost, StrEnum::EnumValue opt_defn, int option_duration_mths, int output_strike_period_mths)
{	
	string option_type_string;
	if (opt_defn == CALL)
	{
		option_type_string = "CALL";
	}
	else if (opt_defn == PUT)
	{
		option_type_string = "PUT";
	}
	else if (opt_defn == PUTK)
	{
		option_type_string = "PUTK"; //20240319 MQ new option
	}
	else if (opt_defn == CSEC) //20240319 MQ new option
	{
		option_type_string = "CSEC";
	}
	else
	{
		throw FatalError("'fia_account->get_option_strike_aig(...)': undefined 'opt_defn'!");
	}

	if(pba_valn_flag)
	{
		
		double rf_rate_cv = 0.0;
		if (fia->gen2_defn == YES) //20240321 MQ use spot rate
		{
			rf_rate_cv  = fia_rates->get_int_rate(projection_month, "Govt", GET_SPOT_RATE, option_duration_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		}
		else
		{
			rf_rate_cv	= rates->get_int_rate(projection_month, "Govt", GET_SPOT_RATE, option_duration_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		}

		//20240229 MQ Shortcut here. Assuming equity index wouldn't change.
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		xstring crediting_eqt_index_local = crediting_eqt_index;

		double final_strike = 0.0;
		double step = 0.0;
		double guess_a = 1.0;
		double guess_b = 1.0;
		int stop = 0;
		int first_time = 0;
		double option_cost_a = 0.0;
		double option_cost_b = 0.0;
		double vol_param = 0.0;
		double dividend_yld = 0.0;
		//Loop to find 6 digits of the unitized strike which equates the calculated option price to the input option cost
		for (int i = 1; i < 6; i++)
		{
			stop = 0;
			first_time = 1;

			guess_b = guess_a;

			for (int j = 1; stop != 1; j++)
			{
				step = pow(0.1, i);

				guess_a = guess_b;
				guess_b = guess_b + step;

				if (option_type_string == "CALL")
				{
					fia->bs_init_vol_type = "base";
					fia->index_id_lookup = crediting_eqt_index_local;
					vol_param = fia->bs_fwrd_vol_aig;

					fia->index_id_lookup = crediting_eqt_index_local;
					dividend_yld = exp(fia->dividend_inner_aig) - 1.;
					
					if(first_time == 1)
					{
						//vol_param = fia->bs_vol_param(1, 1 * guess_a, "call", option_duration_mths / 12.);
						option_cost_a = bs_opt_val(1 * guess_a, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
						
						//vol_param = fia->bs_vol_param(1, 1 * guess_b, "call", option_duration_mths / 12.);
						option_cost_b = bs_opt_val(1 * guess_b, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
					}
					else
					{
						option_cost_a = option_cost_b;
						//vol_param = fia->bs_vol_param(1, 1 * guess_b, "call", option_duration_mths / 12.);
						option_cost_b = bs_opt_val(1 * guess_b, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
					}
				}
				else if (option_type_string == "PUT")
				{
					fia->bs_init_vol_type = "base";
					fia->index_id_lookup = crediting_eqt_index_local;
					vol_param = fia->bs_fwrd_vol_aig;					
					
					fia->index_id_lookup = crediting_eqt_index_local;
					dividend_yld = exp(fia->dividend_inner_aig) - 1.;
					
					if(first_time == 1)
					{
						//vol_param = fia->bs_vol_param(1, 1 * guess_a, "put", option_duration_mths / 12.);
						option_cost_a = bs_opt_val(1 * guess_a, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
						
						//vol_param = fia->bs_vol_param(1, 1 * guess_b, "put", option_duration_mths / 12.);
						option_cost_b = bs_opt_val(1 * guess_b, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
					}
					else
					{
						option_cost_a = option_cost_b;
						//vol_param = fia->bs_vol_param(1, 1 * guess_b, "put", option_duration_mths / 12.);
						option_cost_b = bs_opt_val(1 * guess_b, option_duration_mths / 12., 1, vol_param, rf_rate_cv, dividend_yld, PUT_CODE, CONTINUOUS_PAYOUT_CODE);
					}
					
				}
				else
				{
					throw FatalError("Invalid Option Type used on inner loop.");
				}
				first_time = 0;

				/*if(projection_month==12)
				log_screen<<"i= "<<i
				<<" j= "<<j
				<<" guess_a= "<<guess_a
				<<" guess_b= "<<guess_b
				<<" option_cost_a= "<<option_cost_a
				<<" option_cost_b= "<<option_cost_b
				<<" cost= "<<cost
				<<MSG_USER;*/

				//Check to see if the option cost is between a and b strikes
				if ( ( (option_cost_a - cost) <= 0 && (option_cost_b - cost) >= 0 ) || ( (option_cost_a - cost) >= 0 && (option_cost_b - cost) <= 0 ) || j > 1000)
				{
					//inflection point found
					stop = 1;
				}
				else
				{
					stop = 0;
				}
			}
		}
		return (guess_a + guess_b) / 2.0;
	}
	else
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		string index_id_regex_str = cast_xstring_to_string_aig(crediting_eqt_index);
		string option_duration_str = "D" + to_string(option_duration_mths);  // 20191212 DTL
		string option_duration_regex_str = option_duration_str + "\\D"; // 20191212 DTL
	
		vector<int> table_strikes;
		vector <xstring> misc_id_list;

		if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
			misc_id_list = fia_rates->misc_list;
		else
			misc_id_list = rates->misc_list;

		//20240319 MQ updated logic to be the same as get_option_price_aig
		string complete_key = option_type_string+ "_" + index_id_regex_str + "_" + option_duration_str + "_K";

		for (auto misc_id: misc_id_list) 
		{
			misc_id.to_upper();
			const int NOT_FOUND_CODE = -1;
			if (misc_id.find(complete_key) != NOT_FOUND_CODE) 
			{			
				string misc_id_string = cast_xstring_to_string_aig(misc_id);

				int K = atoi(misc_id_string.substr(complete_key.length()).c_str());
				table_strikes.push_back(K);			
			}

		}

		if (table_strikes.size() == 0)
		{
			// 20191015 MTC - Added more descriptive error message
			xstring error_msg = "'fia_account->get_option_strike_aig(...)': cannot locate option costs in scenario file! Field search: '" + option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K*'";
			throw FatalError(error_msg);
		}

		sort(table_strikes.begin(), table_strikes.end());
		if (opt_defn == CALL || opt_defn == RATCHET_SPRD)  // 20190918 DTL
		{
			reverse(table_strikes.begin(), table_strikes.end());
		}
	

		int number_of_strikes = table_strikes.size();
		table_strikes.erase( unique( table_strikes.begin(), table_strikes.end() ), table_strikes.end());
		if (number_of_strikes != table_strikes.size())
		{
			throw FatalError("'fia_account->get_option_strike_aig(...)': duplicate strike data found in scenario file!");
		}

		double interpolated_option_strike;
		const int FIRST_INDEX = 0;
		const int LAST_INDEX = table_strikes.size() - 1;
		const int ONE_INDEX = 1;
		for (vector<int>::size_type i = 0; i != table_strikes.size(); i++)
		{
			int table_strike = table_strikes.at(i);
			string table_lookup 
				= option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K" + to_string(table_strike); // 20190918 DTL
			double table_option_cost = 0.0;
			if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
				table_option_cost = fia_rates->get_misc_rate(projection_month, xstring(table_lookup), EFFECTIVE_ANNUAL);
			else
				table_option_cost = rates->get_misc_rate(projection_month, xstring(table_lookup), EFFECTIVE_ANNUAL);

			if (i == FIRST_INDEX && cost <= table_option_cost)
			{
				interpolated_option_strike = table_strike;
				break;
			}
			else if (i == LAST_INDEX && cost >= table_option_cost)
			{
				interpolated_option_strike = table_strike;
				break;
			}
			else if (table_option_cost > cost)
			{
				int prior_strike = table_strikes.at(i - ONE_INDEX);
				string lower_option_price_lookup 
					= option_type_string + "_" + index_id_regex_str + "_" + option_duration_str + "_K" + to_string((int)prior_strike); // 20190918 DTL
				transform(lower_option_price_lookup.begin(), lower_option_price_lookup.end(), lower_option_price_lookup.begin(), ::toupper);

				double lower_option_price = 0.0;
				if (fia->gen2_defn == YES)//WTW - Gen2 - cannot reference out of scope 'rates'	
					lower_option_price = fia_rates->get_misc_rate(projection_month, lower_option_price_lookup, EFFECTIVE_ANNUAL);
				else
					lower_option_price = rates->get_misc_rate(projection_month, lower_option_price_lookup, EFFECTIVE_ANNUAL);
			
				double higher_option_price = table_option_cost;
				double lower_option_price_weight = (higher_option_price - cost)/(higher_option_price - lower_option_price);
				double higher_option_price_weight = (cost - lower_option_price)/(higher_option_price - lower_option_price);

				double strike_below = table_strikes.at(i - ONE_INDEX);
				double strike_above = table_strike;

				interpolated_option_strike = lower_option_price_weight * strike_below + higher_option_price_weight * strike_above;
				break;
			}
		}

		const double ONE_HUNDRED = 100.0;
		interpolated_option_strike /= ONE_HUNDRED;

		// DTL 20200109 (START): TFS 86561
		double final_strike;
		double output_strike_period_yrs = output_strike_period_mths / 12.0;
		double option_duration_yrs = option_duration_mths / 12.0;
		if (opt_defn == CALL || opt_defn == PUT || opt_defn == PUTK)
		{
			final_strike = (interpolated_option_strike - 1.0);

			if(fia->option_strike_annualization_aig != ANNUALIZED)
			{
				final_strike /= option_duration_yrs;
			}

			final_strike *= output_strike_period_yrs;
			final_strike += 1.0;
		}
		else
		{
			final_strike = interpolated_option_strike;
		}
		// DTL 20200109 (END): TFS 86561

		return final_strike;
	}
}



#line 1 "get_secure_cap_rate_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_secure_cap_rate_aig(double buffer, double strategy_term, double price_zcb, double vol_param, double rf_rate_cv, double dividend_yld, double cost)
{ 
	// 20240311 MQ: New function to solve secure cap rate
	double final_strike = 0.0;
	double step = 0.0;
	double guess_a = 0.0;
	double guess_b = 0.0;
	int stop = 0;
	int first_time = 0;
	double option_cost_a = 0.0;
	double option_cost_b = 0.0;

	//Loop to find 6 digits of the unitized strike which equates the calculated option price to the input option cost
	for (int i = 1; i < 6; i++)
	{
		stop = 0;
		first_time = 1;

		guess_b = guess_a;

		for (int j = 1; stop != 1; j++)
		{
			step = pow(0.1, i);

			guess_a = guess_b;
			guess_b = guess_b + step;
				
			if(first_time == 1)
			{
				option_cost_a = secure_cap_final_opt_val_aig(guess_a, buffer, 1, strategy_term, vol_param, rf_rate_cv, dividend_yld, price_zcb, 1, 1);
						
				option_cost_b = secure_cap_final_opt_val_aig(guess_b, buffer, 1, strategy_term, vol_param, rf_rate_cv, dividend_yld, price_zcb, 1, 1);
			}
			else
			{
				option_cost_a = option_cost_b;
				option_cost_b = secure_cap_final_opt_val_aig(guess_b, buffer, 1, strategy_term, vol_param, rf_rate_cv, dividend_yld, price_zcb, 1, 1);
			}
					

			first_time = 0;

			//Check to see if the option cost is between a and b strikes
			if ( ( (option_cost_a - cost) <= 0 && (option_cost_b - cost) >= 0 ) || ( (option_cost_a - cost) >= 0 && (option_cost_b - cost) <= 0 ) || j > 1000)
			{
				//inflection point found
				stop = 1;
			}
			else
			{
				stop = 0;
			}
		}
	}
		return (guess_a + guess_b) / 2.0;

}



#line 1 "index_val_avg_calc.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::index_val_avg_calc(int time, int month)
{
if (month == 0)
	return 0;

double indexSum = 0;	
double Average = 0;
	
for (int i = 0; i < month; i = i + lookback_sampling_mths)
	indexSum += index_val_calc(time - i);
	
Average = indexSum / (month / double(lookback_sampling_mths));

return Average;
}



#line 1 "index_val_calc.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::index_val_calc(int t)
{
if (t > commencement_period)
	return index_val(t);

double index_val = 1.0;
double rate = 1.0;

double growth_rate = 0.0;
double dividend_yld = 0.0; 
	
if (time_step_flag && valn_period != 0)
	{
	for (int i = 1; i <= valn_period; i++)
		{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression

		growth_rate = rates->get_index_rate(i - valn_period,
						crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL);

		rate = pow(1.0 + growth_rate * index_scen_mult + index_scen_sprd_addn, 1.0 / 12.0);

		index_val *= rate;	
		}
	}
	
if (t == 0)
	return index_val;	

if (t > 0)
	{
	for (int i = 1; i <= t; i++)
		{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression

		growth_rate = rates->get_index_rate(i,
						crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL);
		}
	}
	
// else if t < 0, must base calculation on prior value
for (int i = -1; i >= t; i--)
	{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression
		growth_rate = rates->get_index_rate(i + 1,
						crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL);

		rate = pow(1.0 + growth_rate * index_scen_mult + index_scen_sprd_addn, 1.0 / 12.0);
		index_val /= rate;
	}
		
return index_val;		
}



#line 1 "index_val_calc_absolute.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::index_val_calc_absolute(int t)
{
double index_val = 1.0;
double rate = 1.0;
double growth_rate = 0.0;
double dividend_yld = 0.0;
	
if (t > 0)
	{
	for (int i = 1; i <= t; i++)
		{
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		xstring crediting_eqt_index_local = crediting_eqt_index;//WTW - Gen2 - Mutating Lookup Term used in expression

		growth_rate = rates->get_index_rate(i - valn_period,
							crediting_eqt_index_local,//WTW - Gen2 - Mutating Lookup Term used in expression
							GET_GROWTH_RATE,
							EFFECTIVE_ANNUAL);

		rate = pow(1.0 + growth_rate * index_scen_mult + index_scen_sprd_addn, 1.0 / 12.0);

		index_val *= rate;	
		}
	}
	
if (t == 0)
	return index_val;	
		
return index_val;		
}



#line 1 "interim_value_calc_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::interim_value_calc_aig(int t, double portion_remaining_time, double initial_option_price, double option_portfolio_value_current)
{
    //Based off of the G/L of the DAPV added to the initial AV
	//Intermediate periods - option prices are interpolated
	double RILA_Base = rila_strat_base_b_aig(t);

	// 20230606 MCHING - Replaced "alternative" minimum value with the one actually declared in the spec
	double DAPV_Initial = RILA_Base * initial_option_price;
	double DAPV_Current = RILA_Base * option_portfolio_value_current;//current price of options
		
	double trading_cost = rila_trading_cost_pct_eom_aig(t); //20240528 MQ update to trading cost
	double FVAF = 1;

	double interim_value = DAPV_Current + 
								(RILA_Base - DAPV_Initial * portion_remaining_time) * FVAF - 
								fabs(DAPV_Current) * trading_cost; //20240212 MQ Replaced RILA_Base

	return interim_value;
}



#line 1 "inv_cumul_normal_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::inv_cumul_normal_aig(double p)
{
//algorithm copied from https://www.johndcook.com/blog/cpp_phi_inverse/

	double c0 = 2.515517;
	double c1 = 0.802853;
	double c2 = 0.010328;
	double d0 = 1.432788;
	double d1 = 0.189269;
	double d2 = 0.001308;

	double rational_approx;

	if(p < 0.5)
	{
		double x = pow_legacy(-2 * log(p), .5);
		rational_approx = x - ((c2 * x + c1) * x + c0) / (((d2 * x + d1) * x + d0) * x + 1);

		return -rational_approx;
	}
	else
	{
		double x = pow_legacy(-2 * log(1 - p), .5);
		rational_approx = x - ((c2 * x + c1) * x + c0) / (((d2 * x + d1) * x + d0) * x + 1);

		return rational_approx;
	}

}



#line 1 "inverse_gamma_call_price.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::inverse_gamma_call_price(double S0, double K, double r, double T, double q, double k, double theta, double lamb, double rho, double v_0, double xi)
{
	
//def inverse_gamma_option_price(S0, K, r, T, k, theta, lamb, xi, rho, v_0, q):
    
	double pi = 3.1415926535897932;

    v_0 = v_0 * xi;
    theta = theta * xi;
    
    double x0 = log(S0);
    
    // Define Omega(a,T) = integral from 0 to T exp(at)*v_{0,t}^2 dt, h(k,T) = integral from 0 to T t*exp(kt)*v_{0,t}^2 dt
    double Omega_0 = pow((v_0 - theta),2) / (-2 * k) * (exp(-2 * k * T) - 1) + 2 * theta * (v_0 - theta) / (-k) * (exp(-k * T) - 1) + pow(theta ,2) * T;
    double Omega_k = pow((v_0 - theta), 2) / (-k) * (exp(-k * T) - 1) + 2 * theta * (v_0 - theta) * T + pow(theta ,2) / k * (exp(k * T) - 1);
    double Omega_2k = pow((v_0 - theta), 2) * T + 2 * theta * (v_0 - theta) / k * (exp(k * T) - 1) + pow(theta , 2) / (2 * k) * (exp(2 * k * T) - 1);
    double Omega_neg_k = pow((v_0 - theta), 2) / (-3 * k) * (exp(-3 * k * T) - 1) + theta * (v_0 - theta) / (-k) * (exp(-2 * k * T) - 1) + pow(theta ,2) / (-k) * (exp(-k * T) - 1);
    double Omega_neg_2k = pow((v_0 - theta), 2) / (-4 * k) * (exp(-4 * k * T) - 1) + 2 * theta * (v_0 - theta) / (-3 * k) * (exp(-3 * k * T) - 1) + pow(theta ,2) / (-2 * k) * (exp(-2 * k * T) - 1);
    
    double h_k = pow((v_0 - theta), 2)/(-k)*(exp(-k*T)*T + exp(-k*T)/k - 1/k) + theta*(v_0 - theta)*pow(T,2) + pow(theta,2)/k*(exp(k*T)*T - exp(k*T)/k + 1/k);

    double phi = Omega_0;

    double a_0 = pow(lamb,2)/(-2*k)*(exp(-2*k*T)*Omega_2k - Omega_0);
    double a_1 = 2*rho*lamb*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + 2*rho*lamb*theta/(-k)*(exp(-k*T)*Omega_k - Omega_0);
    double X_1 = pow((2*rho*lamb),2)*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*((v_0 - theta)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + theta*(T*Omega_k - h_k)) - ((v_0 - theta)/(-3*k)*(exp(-3*k*T)*Omega_k - Omega_neg_2k) + theta/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k))) + pow((2*rho*lamb),2)*theta/(-k)*(exp(-k*T)*((v_0 - theta)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + theta*(T*Omega_k - h_k)) - ((v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + theta/(-k)*(exp(-k*T)*Omega_k - Omega_0)));
    double X_2 = 2*pow((rho*lamb),2)/(-2*k)*(exp(-2*k*T)*(pow((v_0 - theta),2)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + 2*theta*(v_0 - theta)*(T*Omega_k - h_k) + pow(theta,2)/k*(exp(k*T)*Omega_k - Omega_2k)) - (pow((v_0 - theta),2)/(-3*k)*(exp(-3*k*T)*Omega_k - Omega_neg_2k) + 2*theta*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + pow(theta,2)/(-k)*(exp(-k*T)*Omega_k - Omega_0)));
    double a_2 = X_1 + X_2;
    
    double b_0 = 4 * pow(lamb , 2)  * (v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * ((v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0) + theta / (-k) * (exp(-k * T) * Omega_2k - Omega_k)) - ((v_0 - theta) / (-4 * k) * (exp(-4 * k * T) * Omega_2k - Omega_neg_2k) + theta / (-3 * k) * (exp(-3 * k * T) * Omega_2k - Omega_neg_k))) + 4 * pow(lamb , 2) * theta / (-k) * (exp(-k * T) * ((v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0) + theta / (-k) * (exp(-k * T) * Omega_2k - Omega_k)) - ((v_0 - theta) / (-3 * k) * (exp(-3 * k * T) * Omega_2k - Omega_neg_k) + theta / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0)));
    double b_2 = pow(a_1 , 2) / 2;

    // Derivatives Part ##


    double x = x0;
    double y = phi;
    double S = exp(x);

    double C = log(S / K) + (r-q) * T;
    double d1 = C / pow(y, 0.5) + pow(y,0.5) / 2;
    double d2 = d1 - pow(y, 0.5);
    double sigma = pow(y/T, 0.5);

	double local_x = 0.0;

	local_x = d1 / pow(2.0, 0.5);
    double N_d1 = (1+erf(local_x)) / 2;
    
	local_x = d2 / pow(2.0, 0.5);
	double N_d2 = (1+erf(local_x)) / 2;
    
	local_x = -d1 / pow(2.0, 0.5);
	double N_neg_d1 = (1+erf(local_x)) / 2;
    
	local_x = -d2 / pow(2.0, 0.5);
	double N_neg_d2 = (1+erf(local_x)) / 2;

    double N_p1_d1 = exp(-1.0 * pow(d1 , 2) / 2) / pow(2 * pi, 0.5);
    double N_p2_d1 = N_p1_d1 * (-d1);
    double N_p3_d1 = N_p1_d1 * (pow(d1 , 2) - 1);


    double P_ss = N_p1_d1 * exp(-q * T) / (S * sigma * pow(T, 0.5));

    double P_sigma = S * exp(-q * T) * N_p1_d1 * pow(T, 0.5);

    double P_sy = N_p1_d1 * exp(-q * T) * (-C * pow(y , (-1.5)) / 2 + 0.25 * pow(y , (-0.5)));
    double P_ssy = N_p2_d1 * exp(-q * T) * (-C * pow(y , (-2)) / (2 * S) + 0.25 * pow(y , (-1)) / S) + N_p1_d1 * exp(-q * T) * (-(0.5) * pow(y , (-1.5)) / S);
    double P_syy = N_p2_d1 * exp(-q * T) * pow((-C * 0.5 * pow(y , (-1.5)) + 0.25 * pow(y , (-0.5))) , 2) + N_p1_d1 * exp(-q * T) * (3 * C * 0.25 * pow(y , (-2.5)) - 0.125 * pow(y , (-1.5)));
    double P_ssyy = N_p3_d1 * exp(-q * T) * (-C * 0.5 * pow(y , (-1.5)) + 0.25 * pow(y , (-0.5))) * (-C * 0.5 * pow(y , (-2)) / S + 0.25 * pow(y , (-1)) / S) + N_p2_d1 * exp(-q * T) * (C * pow(y , (-3)) / S - 0.25 * pow(y , (-2)) / S) + N_p2_d1 * exp(-q * T) * (-C * pow(y , (-1.5)) * 0.5 + 0.25 * pow(y , (-0.5))) * (-0.5 * pow(y , (-1.5)) / S) + N_p1_d1 * exp(-q * T) * (0.75 * pow(y , (-2.5)) / S);


    double P = K * exp(-r * T) * N_neg_d2 - S * exp(-q * T) * N_neg_d1;
    double P_y = S * exp(-q * T) * N_p1_d1 * 0.5 / pow(y, 0.5);
    double P_xy = P_sy * exp(x);
    double P_xxy = P_ssy * exp(2 * x) + P_sy * exp(x);
    double P_yy = S * exp(-q * T) * N_p2_d1 * (-C * 0.25 * pow(y , (-2)) + 0.125 * pow(y , (-1))) + S * exp(-q * T) * N_p1_d1 * (-0.25 * pow(y , (-1.5)));
    double P_xxyy = P_ssyy * exp(2 * x) + P_syy * exp(x);

    // inverse gamma put option price
    double result = P + a_0 * P_y + a_1 * P_xy + a_2 * P_xxy + b_0 * P_yy + b_2 * P_xxyy;

	//convert put price to call price using Put Call Parity
	double call_result = result + S0 * exp(-q * T) - K * exp(-r * T);

    return call_result;
}



#line 1 "inverse_gamma_put_price.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::inverse_gamma_put_price(double S0, double K, double r, double T, double q, double k, double theta, double lamb, double rho, double v_0, double xi)
{
	
//def inverse_gamma_option_price(S0, K, r, T, k, theta, lamb, xi, rho, v_0, q):
    
	double pi = 3.1415926535897932;

    v_0 = v_0 * xi;
    theta = theta * xi;
    
    double x0 = log(S0);
    
    // Define Omega(a,T) = integral from 0 to T exp(at)*v_{0,t}^2 dt, h(k,T) = integral from 0 to T t*exp(kt)*v_{0,t}^2 dt
    double Omega_0 = pow((v_0 - theta),2) / (-2 * k) * (exp(-2 * k * T) - 1) + 2 * theta * (v_0 - theta) / (-k) * (exp(-k * T) - 1) + pow(theta ,2) * T;
    double Omega_k = pow((v_0 - theta), 2) / (-k) * (exp(-k * T) - 1) + 2 * theta * (v_0 - theta) * T + pow(theta ,2) / k * (exp(k * T) - 1);
    double Omega_2k = pow((v_0 - theta), 2) * T + 2 * theta * (v_0 - theta) / k * (exp(k * T) - 1) + pow(theta , 2) / (2 * k) * (exp(2 * k * T) - 1);
    double Omega_neg_k = pow((v_0 - theta), 2) / (-3 * k) * (exp(-3 * k * T) - 1) + theta * (v_0 - theta) / (-k) * (exp(-2 * k * T) - 1) + pow(theta ,2) / (-k) * (exp(-k * T) - 1);
    double Omega_neg_2k = pow((v_0 - theta), 2) / (-4 * k) * (exp(-4 * k * T) - 1) + 2 * theta * (v_0 - theta) / (-3 * k) * (exp(-3 * k * T) - 1) + pow(theta ,2) / (-2 * k) * (exp(-2 * k * T) - 1);
    
    double h_k = pow((v_0 - theta), 2)/(-k)*(exp(-k*T)*T + exp(-k*T)/k - 1/k) + theta*(v_0 - theta)*pow(T,2) + pow(theta,2)/k*(exp(k*T)*T - exp(k*T)/k + 1/k);

    double phi = Omega_0;

    double a_0 = pow(lamb,2)/(-2*k)*(exp(-2*k*T)*Omega_2k - Omega_0);
    double a_1 = 2*rho*lamb*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + 2*rho*lamb*theta/(-k)*(exp(-k*T)*Omega_k - Omega_0);
    double X_1 = pow((2*rho*lamb),2)*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*((v_0 - theta)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + theta*(T*Omega_k - h_k)) - ((v_0 - theta)/(-3*k)*(exp(-3*k*T)*Omega_k - Omega_neg_2k) + theta/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k))) + pow((2*rho*lamb),2)*theta/(-k)*(exp(-k*T)*((v_0 - theta)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + theta*(T*Omega_k - h_k)) - ((v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + theta/(-k)*(exp(-k*T)*Omega_k - Omega_0)));
    double X_2 = 2*pow((rho*lamb),2)/(-2*k)*(exp(-2*k*T)*(pow((v_0 - theta),2)/(-k)*(exp(-k*T)*Omega_k - Omega_0) + 2*theta*(v_0 - theta)*(T*Omega_k - h_k) + pow(theta,2)/k*(exp(k*T)*Omega_k - Omega_2k)) - (pow((v_0 - theta),2)/(-3*k)*(exp(-3*k*T)*Omega_k - Omega_neg_2k) + 2*theta*(v_0 - theta)/(-2*k)*(exp(-2*k*T)*Omega_k - Omega_neg_k) + pow(theta,2)/(-k)*(exp(-k*T)*Omega_k - Omega_0)));
    double a_2 = X_1 + X_2;
    
    double b_0 = 4 * pow(lamb , 2)  * (v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * ((v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0) + theta / (-k) * (exp(-k * T) * Omega_2k - Omega_k)) - ((v_0 - theta) / (-4 * k) * (exp(-4 * k * T) * Omega_2k - Omega_neg_2k) + theta / (-3 * k) * (exp(-3 * k * T) * Omega_2k - Omega_neg_k))) + 4 * pow(lamb , 2) * theta / (-k) * (exp(-k * T) * ((v_0 - theta) / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0) + theta / (-k) * (exp(-k * T) * Omega_2k - Omega_k)) - ((v_0 - theta) / (-3 * k) * (exp(-3 * k * T) * Omega_2k - Omega_neg_k) + theta / (-2 * k) * (exp(-2 * k * T) * Omega_2k - Omega_0)));
    double b_2 = pow(a_1 , 2) / 2;

    // Derivatives Part ##


    double x = x0;
    double y = phi;
    double S = exp(x);

    double C = log(S / K) + (r-q) * T;
    double d1 = C / pow(y, 0.5) + pow(y,0.5) / 2;
    double d2 = d1 - pow(y, 0.5);
    double sigma = pow(y/T, 0.5);

	double local_x = 0.0;

	local_x = d1 / pow(2.0, 0.5);
    double N_d1 = (1+erf(local_x)) / 2;
    
	local_x = d2 / pow(2.0, 0.5);
	double N_d2 = (1+erf(local_x)) / 2;
    
	local_x = -d1 / pow(2.0, 0.5);
	double N_neg_d1 = (1+erf(local_x)) / 2;
    
	local_x = -d2 / pow(2.0, 0.5);
	double N_neg_d2 = (1+erf(local_x)) / 2;

    double N_p1_d1 = exp(-1.0 * pow(d1 , 2) / 2) / pow(2 * pi, 0.5);
    double N_p2_d1 = N_p1_d1 * (-d1);
    double N_p3_d1 = N_p1_d1 * (pow(d1 , 2) - 1);


    double P_ss = N_p1_d1 * exp(-q * T) / (S * sigma * pow(T, 0.5));

    double P_sigma = S * exp(-q * T) * N_p1_d1 * pow(T, 0.5);

    double P_sy = N_p1_d1 * exp(-q * T) * (-C * pow(y , (-1.5)) / 2 + 0.25 * pow(y , (-0.5)));
    double P_ssy = N_p2_d1 * exp(-q * T) * (-C * pow(y , (-2)) / (2 * S) + 0.25 * pow(y , (-1)) / S) + N_p1_d1 * exp(-q * T) * (-(0.5) * pow(y , (-1.5)) / S);
    double P_syy = N_p2_d1 * exp(-q * T) * pow((-C * 0.5 * pow(y , (-1.5)) + 0.25 * pow(y , (-0.5))) , 2) + N_p1_d1 * exp(-q * T) * (3 * C * 0.25 * pow(y , (-2.5)) - 0.125 * pow(y , (-1.5)));
    double P_ssyy = N_p3_d1 * exp(-q * T) * (-C * 0.5 * pow(y , (-1.5)) + 0.25 * pow(y , (-0.5))) * (-C * 0.5 * pow(y , (-2)) / S + 0.25 * pow(y , (-1)) / S) + N_p2_d1 * exp(-q * T) * (C * pow(y , (-3)) / S - 0.25 * pow(y , (-2)) / S) + N_p2_d1 * exp(-q * T) * (-C * pow(y , (-1.5)) * 0.5 + 0.25 * pow(y , (-0.5))) * (-0.5 * pow(y , (-1.5)) / S) + N_p1_d1 * exp(-q * T) * (0.75 * pow(y , (-2.5)) / S);


    double P = K * exp(-r * T) * N_neg_d2 - S * exp(-q * T) * N_neg_d1;
    double P_y = S * exp(-q * T) * N_p1_d1 * 0.5 / pow(y, 0.5);
    double P_xy = P_sy * exp(x);
    double P_xxy = P_ssy * exp(2 * x) + P_sy * exp(x);
    double P_yy = S * exp(-q * T) * N_p2_d1 * (-C * 0.25 * pow(y , (-2)) + 0.125 * pow(y , (-1))) + S * exp(-q * T) * N_p1_d1 * (-0.25 * pow(y , (-1.5)));
    double P_xxyy = P_ssyy * exp(2 * x) + P_syy * exp(x);

    // inverse gamma put option price
    double result = P + a_0 * P_y + a_1 * P_xy + a_2 * P_xxy + b_0 * P_yy + b_2 * P_xxyy;

    return result;
}



#line 1 "joint_part_sprd_rate_solver_aig.FIAAFUND_LIAB.for"                                                                                   
void FIAAFUND_LIAB::joint_part_sprd_rate_solver_aig(int t, double& part_rate, double& sprd_rate)
{
	// 20190918 DTL: adding new solver to get the SPREAD + PARTICIPATION associated to one
	//    of our cliquet options

	double initial_spread = index_term_init_spread_rate_aig(t); // DTL 20200109: TFS 86561	

	double minimum_participation_rate = index_term_part_rate_min_col_aig(t);
	
	double option_budget = 0.0;
	double option_cost = 0.0;

	if (strategy_term_mths_aig(t) == index_term_mths_aig(t))
	{
		double zero_spread_strike = 1;
		option_budget = opt_budget(t);// 20201125 HYH, opt_budget_alt_model_renewal_strategy_beta_aig(t);
		// 20200415 HYH change for AQR
		option_cost = minimum_participation_rate * get_option_price_aig(t - 1, 1.0 + initial_spread / minimum_participation_rate, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));
		//option_cost = minimum_participation_rate * get_option_price_v2_aig(t - 1, zero_spread_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561
		if (option_cost < option_budget)
		{
			// 20200415 HYH change for AQR
			if (initial_spread == 0)
			{
				part_rate = option_budget / get_option_price_aig(t - 1, zero_spread_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561
				sprd_rate = initial_spread;

				current_opt_defn_aig = CALL;
			}
			else
			{
                // 20201125 HYH
                if (option_budget 
                    >= index_term_part_rate_max_col_aig(t) 
					* (get_option_strike_aig(t - 1, option_budget / index_term_part_rate_max_col_aig(t), CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) - 1))
                {
					part_rate = index_term_part_rate_max_col_aig(t);
                }
                else
                // end of 20201125 HYH
                {
					part_rate = part_rate_solver_aig(t, index_term_part_rate_min_col_aig(t), index_term_part_rate_max_col_aig(t));
                }

				sprd_rate = initial_spread;

				current_opt_defn_aig = CALL;
			}

		}
		else
		{
			part_rate = minimum_participation_rate;
			double new_budget = option_budget / minimum_participation_rate;

			//  20201125 HYH, 
			if (option_budget <= 0)
				sprd_rate = index_term_sprd_rate_max_col_aig(t);
			else
			// end of 20201125 HYH, 
				sprd_rate = minimum_participation_rate * (get_option_strike_aig(t - 1, new_budget, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) - 1);// DTL 20200109 (START): TFS 86561

			current_opt_defn_aig = CALL;
		}
	}
	else
	{
		throw FatalError("fiaafund_liab->joint_part_sprd_rate_solver_aig: unhandled value of `strategy_term_mths_aig(t)`, the strategy term year is less than one year.");
	}
	// 20191121 STW (END) 

	 part_rate = max(part_rate, minimum_participation_rate);
	 sprd_rate = min(sprd_rate, index_term_sprd_rate_max_col_aig(t));
	 sprd_rate = max(sprd_rate, index_term_sprd_rate_min_col_aig(t));  // 20191031 MTC - Added floor consideration
}



#line 1 "mkt_val_calc.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::mkt_val_calc(int t, int cal_yr, int cal_mth, int lookback_defn, int lookback_mths, int lookback_sampling_mths, double index_units_owned, double index_val, double index_scen_mult, double index_scen_sprd_addn, double term_to_expiry, double div_yld_scen_mult, double div_yld_sprd, double opt_strike_price, double payout_index_max, double mthly_cap_rate, StrEnum::EnumValue opt_defn, double extra_spot_spread, double extra_vol_spread, int shift_defn)
{
// Local Variables
double calculated_market_value = 0;
int sampling_frequency = 0;
double init_div_yld = 0;	
double index_vol_opt_strike_price  = 0;
double index_vol_payout_index_max  = 0;
double index_vol_atm = 0;
double index_vol_otm = 0;
double risk_free_rate = 0;
double market_value_of_base_option = 0;
double market_value_of_maximum_payout_strike_option = 0;
double volatility_skew = 0;
xstring category_id = "Govt";

int call_or_put_option_code
= (opt_defn == CALL ? CALL_CODE : PUT_CODE);

if (term_to_expiry > 0.0)
	{
	// Reduce lookback months by one to sample ends of sample months only.
	lookback_mths = lookback_mths - lookback_sampling_mths;

	sampling_frequency = 12 / lookback_sampling_mths;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	init_div_yld
	= rates->get_index_rate(t, 
				crediting_eqt_index,
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL)
	  * div_yld_scen_mult + div_yld_sprd;
	 // init_div_yld=0.0;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	index_vol_atm
	= rates->get_index_vol(t, 
				crediting_eqt_index,
				1.0,/*moneyness */
				term_to_expiry,
				EFFECTIVE_ANNUAL,
				NO_SHIFT) 
	  + extra_vol_spread;
	
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	index_vol_otm
	= rates->get_index_vol(t, 
				crediting_eqt_index,
				1.05,// /*moneyness */
				term_to_expiry,
				EFFECTIVE_ANNUAL,
				NO_SHIFT) 
	  + extra_vol_spread;
	
	volatility_skew = (index_vol_atm - index_vol_otm) / (1.05 - 1.00)/ 100.;
	
	index_vol_opt_strike_price = max(0.05, index_vol_atm 
										   - volatility_skew 
										     * (opt_strike_price - index_val) / index_val  * 100.0);
	
    index_vol_payout_index_max = max(0.05, index_vol_atm 
										   - volatility_skew 
											 * (payout_index_max - index_val) 
											 / index_val  * 100.0);

	risk_free_rate
	= rates->get_int_rate(t,
				category_id,
				GET_SPOT_RATE,
				term_to_expiry,
				0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	  + extra_spot_spread;

	} 

fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
if (crediting_rate_defn == POINT_TO_POINT
	|| crediting_rate_defn == MOVING_AVERAGE)
	{		
	if (term_to_expiry > 0.0 && lookback_defn == NONE)
		{market_value_of_base_option
		= index_units_owned
		  * bs_opt_val(opt_strike_price,
					term_to_expiry,
					index_val,
					index_vol_opt_strike_price,
					risk_free_rate,
					init_div_yld,
					call_or_put_option_code,
					CONTINUOUS_PAYOUT_CODE);

	/*log_screen<<"t= "<<t
	<<" index_vol_opt_strike_price= "<<index_vol_opt_strike_price
	<<" risk_free_rate= "<<risk_free_rate
	<<" index_val= "<<index_val
	<<MSG_USER;*/}

	else if (term_to_expiry > 0.0 && lookback_defn == ASIAN)
		market_value_of_base_option
		= index_units_owned
		  * bs_opt_val_asian(call_or_put_option_code,
					index_val,
					index_val_avg_calc(t, xint(mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/))),  // 20190613 DTL: replaced `crediting_mths`
					opt_strike_price,
					lookback_mths / 12.0,
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_opt_strike_price,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (opt_defn == CALL && lookback_defn == ASIAN)
		market_value_of_base_option
		= index_units_owned
		  * max(index_val_avg_calc(t, lookback_mths) - opt_strike_price, 0.0);

	else if (opt_defn == CALL && lookback_defn == NONE)
		market_value_of_base_option
		= index_units_owned * max(index_val - opt_strike_price, 0.0);

	else if (opt_defn == PUT && lookback_defn == ASIAN)
		market_value_of_base_option
		= index_units_owned * max(opt_strike_price - index_val_avg_calc(t, lookback_mths), 0.0);

	else if (opt_defn == PUT && lookback_defn == NONE)
		market_value_of_base_option
		= index_units_owned * max(opt_strike_price - index_val, 0.0);

	if (payout_index_max <= 0.0
		|| payout_index_max > GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE)
		market_value_of_maximum_payout_strike_option = 0.0;

	else if (term_to_expiry > 0.0 && lookback_defn == NONE)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * bs_opt_val(payout_index_max,
					term_to_expiry,
					index_val,
					index_vol_payout_index_max,
					risk_free_rate,
					init_div_yld,
					call_or_put_option_code,
					CONTINUOUS_PAYOUT_CODE);

	else if (term_to_expiry > 0.0 && lookback_defn == ASIAN)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * bs_opt_val_asian(call_or_put_option_code,
					index_val,
					index_val_avg_calc(t, xint(mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/))),// 20190613 DTL: replaced `crediting_mths`
					payout_index_max,
					lookback_mths / 12.0,
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_payout_index_max,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (opt_defn == CALL && lookback_defn == ASIAN)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(index_val_avg_calc(t, lookback_mths) - payout_index_max, 0.0);

	else if (opt_defn == CALL && lookback_defn == NONE)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(index_val - payout_index_max, 0.0);

	else if (opt_defn == PUT && lookback_defn == ASIAN)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(payout_index_max - index_val_avg_calc(t, lookback_mths), 0.0);

	else if (opt_defn == PUT && lookback_defn == NONE)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(payout_index_max - index_val, 0.0);

/*log_screen<<"t= "<<t
	<<" index_units_owned= "<<index_units_owned
	<<" market_value_of_base_option= "<<market_value_of_base_option
	<<" market_value_of_maximum_payout_strike_option= "<<market_value_of_maximum_payout_strike_option
	<<" opt_strike_price= "<<opt_strike_price
	<<" payout_index_max= "<<payout_index_max
	<<MSG_USER;*/

	calculated_market_value
	= market_value_of_base_option - market_value_of_maximum_payout_strike_option;
	}
else // if (crediting_rate_defn == MONTHLY_SUM_CAP)
	{
	double index_curr = 0;
	double index_prev = 0;
	double sum_capped_amts = 0;

	if (term_to_expiry == 0)
		{
		for (int i = 0; i < strategy_term_mths_aig(t) /*crediting_mths*/; i++)// 20190613 DTL: replaced `crediting_mths`
			{
			index_curr = index_val_calc(t - i);
			index_prev = index_val_calc(t - i - 1);
		
			if (index_prev > 0) //need to set index_prev first			
				sum_capped_amts += min(mthly_cap_rate, (index_curr / index_prev) - 1.0);
			}	

		return index_units_owned
		       * max(0.0, sum_capped_amts);
		}

	for (int i = 0; i < xint(mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/)); i++)// 20190613 DTL: replaced `crediting_mths`
		{
		index_curr = index_val_calc(t - i);
		index_prev = index_val_calc(t - i - 1);
		
		if (index_prev > 0) //need to set index_prev first			
			sum_capped_amts += min(mthly_cap_rate, (index_curr / index_prev) - 1.0);
		}	

	calculated_market_value
	= index_units_owned
	  * bs_opt_val_mthly_sum_cap(strategy_term_mths_aig(t) /*crediting_mths*/,  // 20190613 DTL: replaced `crediting_mths`
	                   xint(mod(t + elapsed_mths, strategy_term_mths_aig(t) /*crediting_mths*/)),  // 20190613 DTL: replaced `crediting_mths`
					   sum_capped_amts,
					   mthly_cap_rate,
					   term_to_expiry,
					   risk_free_rate,
					   init_div_yld,
					   index_vol_opt_strike_price,
					   NOMINAL_SEMIANNUAL,
					   EFFECTIVE_ANNUAL);
	}

return calculated_market_value;
}



#line 1 "opt_budget_migration_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_budget_migration_aig(
	double opt_budget_base, double ner_init, double ner_cv,
	double beta, double crediting_period_yrs, 
	double opt_budget_tgt , double grading_progress_input )
{
	double total_migration_amount_cv	= opt_budget_tgt - opt_budget_base;
	double migration_increment_cv		= total_migration_amount_cv * grading_progress_input;

	double opt_budget_cv				= opt_budget_base + migration_increment_cv;
	opt_budget_cv					   += beta * (ner_cv - ner_init) * crediting_period_yrs;
	
	return opt_budget_cv;
}



#line 1 "opt_budget_renewal_calc_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_budget_renewal_calc_aig(int t, double init_opt_cost, double opt_budget_tgt, double init_annuity_factor, double curr_annuity_factor)
{
	double opt_budget_base = init_opt_cost;

	const double ONE_MTH			= 1.0;
	const double ONE_YR				= 1.0;
	const double MTHS_PER_YR		= 12.0;

	double budget_holding_period_cv = (renewal_migration_beg_yr_aig - ONE_YR) * MTHS_PER_YR; 
	if (t + elapsed_mths <= budget_holding_period_cv) //WG 20231026: Updating to consider elapsed months
	{
		return opt_budget_base;
	}

	double ner_init					= fia->crediting_ner_aig;
	double ner_prev					= fia->asset_yld_inv(t - 1);

	//20220519 STW：use asset yld including duration weighted adj for rate setting
	if(!isMainModel && alm_flag)
	{
		ner_prev = fia->asset_yld_inv_adj_aig(t - 1);
	}

	double ner_cv;

	ner_cv  = ner_prev / (1 + ner_prev);
	ner_init = ner_init / (1 + ner_init);

	double beta = 0.0;
	if (ner_cv > ner_init)
	{
		beta += renewal_beta_up_aig; 
		if (fia->gmwb_flag)
		{
			beta += renewal_glb_beta_up_aig;
		}
	}
	else
	{
		beta += renewal_beta_down_aig; 
		if (fia->gmwb_flag)
		{
			beta += renewal_glb_beta_down_aig; 
		}
	}

	double crediting_period_yrs		= 1.; 

	double grading_progress_input;
	double opt_budget_grading_period_aig = fia->surr_chg_period_aig + renewal_surr_chg_offest_aig + 1; 
	if (t + elapsed_mths <=  (opt_budget_grading_period_aig - ONE_YR) * MTHS_PER_YR + ONE_MTH) //WG 20231026: Updating to consider elapsed months
	{
		double grading_progress_numerator	= fia->pol_yr(t) - renewal_migration_beg_yr_aig + 1.0; 
		double grading_progress_denominator = opt_budget_grading_period_aig - renewal_migration_beg_yr_aig + 1.0;
    
		if (abs(grading_progress_denominator) < SMALL_DOUBLE)
		{
			xstring err_msg = "fiaafund_liab->opt_budget_renewal_2020_aig: division by zero.";
			throw FatalError(err_msg);
		}

		grading_progress_input	= grading_progress_numerator / grading_progress_denominator;
		opt_budget_base			= init_opt_cost / init_annuity_factor; 
	}
	else
	{
		opt_budget_base			= opt_budget_tgt; 
		opt_budget_tgt			= 0.0;
		grading_progress_input	= 0.0;
	}

	double option_budget = opt_budget_migration_aig(opt_budget_base, ner_init, ner_cv,
		beta, crediting_period_yrs, opt_budget_tgt, grading_progress_input);

	option_budget *= curr_annuity_factor;//strategy_term_aig(t); 

	return option_budget;
}



#line 1 "opt_budget_tgt_calc_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_budget_tgt_calc_aig(int t, double init_opt_cost, double init_strat_term, double curr_strat_term)
{
	double init_ner = fia->crediting_ner_aig / (1.0 + fia->crediting_ner_aig); 
	double annualized_option_cost_cv = init_opt_cost / init_strat_term;
	double init_pri_sprd = init_ner - annualized_option_cost_cv;
	double baseline_budget = init_ner - renewal_pri_sprd_tgt_aig; 

	double opt_budget_tgt_alpha_aig_local;

	//20220822 JYL: Update values for liquidity spread and alpha
	if (fund_id == "Index1")
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - Mutating Lookup Term
		fia->strategy_term_dyn_aig = curr_strat_term;//20220822 JYL: mutating lookup
		opt_budget_tgt_alpha_aig_local = fia->opt_budget_tgt_alpha_idx1_aig;

		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		fia->strategy_term_dyn_aig = curr_strat_term;//20220822 JYL: mutating lookup
		renewal_budget_reduction_aig = fia->opt_budget_tgt_reduction_idx1_aig;
	}
	else
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - Mutating Lookup Term
		fia->strategy_term_dyn_aig = curr_strat_term;//20220822 JYL: mutating lookup
		opt_budget_tgt_alpha_aig_local = fia->opt_budget_tgt_alpha_aig;

		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		fia->strategy_term_dyn_aig = curr_strat_term;//20220822 JYL: mutating lookup
		renewal_budget_reduction_aig = fia->opt_budget_tgt_reduction_aig;
	}

	double opt_budget_tgt = (baseline_budget - renewal_budget_reduction_aig + opt_budget_tgt_alpha_aig_local * (renewal_pri_sprd_tgt_aig - init_pri_sprd));	

	return opt_budget_tgt;
}



#line 1 "opt_mkt_val_estimate_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_mkt_val_estimate_aig(
	int t,
	double intrinsic_value,
	double option_cost,
	double option_term_start_month,
	double option_term_end_month
)
{
	/*
		This formula was provided by MRM to estimate the market value of an option.
		At the time of initial implementation, the alpha parameter varies by whether 
		or not the option is a cliquet or call option:

		https://en.wikipedia.org/wiki/Cliquet_option

		MCHING 9-2-2021
	*/

	double option_term										= option_term_end_month - option_term_start_month + 1.0;

	if (option_term > SMALL_DOUBLE)
	{

		double alpha											= hedge_option_val_alpha_col_aig(t);  

		double option_mkt_val_estimate						= intrinsic_value + 
																option_cost *
																pow(
																		(option_term_end_month - t) / 
																		option_term
																	, 
																	alpha
																);

		return option_mkt_val_estimate;
	}
	else
	{
		throw FatalError("Option term end month is before option term start month in opt_mkt_val_estimate_aig!");
	}
}




#line 1 "part_rate_solver_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::part_rate_solver_aig(int t, double guess_low_bound, double guess_high_bound)
{
	// 20181029 MTC - New par rate solve mechanism

	/*! Participation Rate Solver
		=========================
		@author Michael Ching
		@date 20181029
		
		We need to solve for the participation rate because participation rate is a function
		of the option budget and option budget is a function of the participation rate (if
		the spread is non-zero).

		Participation rate is a function of the option budget because we use the option budget
		to buy options that satisfy our guarantee to the policyholder. For example, if we have
		an index floor of 0%, we would need to buy an at-the-money call option. If we don't have
		enough money to buy the option, we would need to adjust the participation rate downward
		in order to afford an option that satisfies our guarantee.

		Option budget is a function of participation rate because the participation rate
		"amplifies" the effect of the market. If the participation rate goes down, our option
		budget effectively grows since we are able to afford more options (holding all other
		things constant). The converse of this is true as well.

		The participation rate solve is done through a <a href="https://en.wikipedia.org/wiki/Forward_rate">simple bisection method</a>.

		-# Get the option budget from fiaafund_liab_opt_budget().
		-# Get the initial guess bounds. These are the minimum and maximum participation rates for the low bound and high bound.
		-# Calculate the guess participation rate:

		   \f[
		   guess\,participation\,rate = (low\,bound + high\,bound) \times 0.5
		   \f]
		
		-# Calculate the participation rate adjusted option budget based on the guessed participation rate:

		   \f[
		   guess\,option\,budget = \frac{option\,budget_{t}}{guess\,participation\,rate}
		   \f]

		-# Use the participation rate adjusted option budget to look up a strike on the option cost table using get_option_strike_aig()
		-# Calculate a solved participation rate:

		   \f[
		   solved\,participation\,rate = \frac{initial\,spread}{strike}
		   \f]

		-# Check the difference between the solved participation rate and the guess participation rate. If they are within a certain
		   tolerance, the solve was successful and the solved participation rate is returned.

		-# If the solve was not successful, the next guess is set. If the solved rate was higher than the guessed rate, the guessed
		   rate becomes the new lower bound. If the solved rate is lower than the guessed rate, the guessed rate becomes the new
		   upper bound.  The process then loops back to step 3 until a solution is achieved or a certain timeout threshold is reached.
		.

		@param[in] t The time period to use to look up economic conditions (i.e. option prices, option budget, etc...).
		@param[in] guess_low_bound The initial lower bound for the guess range.
		@param[in] guess_high_bound The initial upper bound for the guess range.

		Related Inputs:
		---------------
		-# **UI** `part_rate_solve_tolerance_aig` - The absolute difference between the solved and guessed participation rates must 
		   be less than this number to be considered a successful solve.
		-# **UI** `part_rate_solve_max_iter_aig` - The maximum number of solve loops before a timeout. This will result in a Fatal Error.
		-# **MP** `init_spread_rate_aig` - Initial spread, from the model point file.
		-# **UI** `index_term_part_rate_min_aig` - Minimum participation rate for the index term.
		-# **UI** `index_term_part_rate_max_aig` - Maximum participation rate for the index term.
 
		@return Participation rate.
	*/

	// Initialize
	int solve_iteration = 1;
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
	double solve_tolerance = max(part_rate_solve_tolerance_aig, SMALL_DOUBLE);
	double option_budget = opt_budget(t);
	double guess_part_rate, solved_part_rate, part_rate_adj_option_budget, long_strike, current_guess_diff;

	// Main solve loop
	while (true)
	{
		// 20181119 MTC - Update to bisection solve mechanism
		// Calculate guess
		guess_part_rate = (guess_low_bound + guess_high_bound) * 0.5;

		// Get participation-rate-adjusted option budget
		if (guess_part_rate > SMALL_DOUBLE)
		{
			part_rate_adj_option_budget = option_budget / guess_part_rate;
		}
		else
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			if (display_solver_warnings_defn == YES)
			{
				log_screen << "Warning: Guessed participation rate is less than zero at t = " << t << " for account "<< fund_id 
						   << ", The participation rate has been set to " << index_term_part_rate_min_col_aig(t) <<  MSG_STATUS;
			}

			return index_term_part_rate_min_col_aig(t);
		}

		// Get strike from participation-rate-adjusted option budget

		long_strike = get_option_strike_aig(t - 1, part_rate_adj_option_budget, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t)) - 1.0;// DTL 20200109 // 20190613 DTL: replaced `crediting_mths`

		// Get solved participation rate
		if (long_strike > SMALL_DOUBLE)
		{
			// DTL 20200109 (START): TFS 86561
			solved_part_rate =  index_term_init_spread_rate_aig(t) / long_strike;
			// DTL 20200109 (START): TFS 86561
		}
		else
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			if (display_solver_warnings_defn == YES)
			{
				log_screen << "Warning: Option cost strike is less than zero at t = " << t << " for account "<< fund_id 
						   << ", The participation rate has been set to " << index_term_part_rate_max_col_aig(t) <<  MSG_STATUS;
			}

			//return index_term_part_rate_max_col_aig(t);
			solved_part_rate =  index_term_part_rate_max_col_aig(t);
		}

		// Calculate guess difference
		current_guess_diff = solved_part_rate - guess_part_rate;

		// Check solution
		if (fabs(current_guess_diff) <= solve_tolerance)
		{
			return solved_part_rate;
		}

		// Set next guess if not acceptable solution - simple bisection
		// 20181119 MTC - Update to bisection solve mechanism
		if (solved_part_rate > guess_part_rate)
		{
			guess_low_bound = guess_part_rate;
		}
		else
		{
			guess_high_bound = guess_part_rate;
		}
		// 20181119 MTC END

		// Increase solve iteration counter
		solve_iteration++;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
		// Throw error if we can't find a solution in time
		if (solve_iteration > part_rate_solve_max_iter_aig)
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 
			xstring max_iter_str = xstring(part_rate_solve_max_iter_aig);
			xstring t_str = xstring(t);
			throw FatalError("Unable to achieve solved participation rate within " + max_iter_str + 
							 " iterations at t = " + t_str + " for account " + fund_id + " ! Increase part_rate_solve_max_iter_aig or part_rate_solve_tolerance_aig!");
		}
	}
}



#line 1 "part_rate_solver_alt_model_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::part_rate_solver_alt_model_aig(int t)
{ // 20190820 DTL: adding new solve based on table lookups

	double participation_rate;
	double option_budget = opt_budget(t);

	if (option_budget < rate_ratio_threshold)
	{
		participation_rate = index_term_part_rate_min_col_aig(t);
		return participation_rate;
	}

	const double TABLE_ATM_STRIKE = 1.0;
	double long_strike = TABLE_ATM_STRIKE;

	if ( opt_strike_price(t) - index_val(t) > SMALL_DOUBLE &&
		 index_val(t - 1) > SMALL_DOUBLE                         )
	{
		//We guarantee some non-zero index credit
		long_strike = opt_strike_price(t) / index_val(t - 1);
	}
	
	double long_cost = get_option_price_aig(t - 1, long_strike, RATCHET_PART, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561  // 20190918 DTL: table lookup solves are cliquets, not calls

	if (option_budget > long_cost)
	{
		participation_rate = index_term_part_rate_max_col_aig(t);
	}
	else
	{
		double solved_strike = get_option_strike_aig(t - 1, option_budget, RATCHET_PART, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561 // 20190918 DTL: table lookup solves are cliquets, not calls
		double proposed_participation_rate = solved_strike;

		if (proposed_participation_rate > index_term_part_rate_max_col_aig(t))
		{
			participation_rate = index_term_part_rate_max_col_aig(t);
		}
		else if (proposed_participation_rate < index_term_part_rate_min_col_aig(t))
		{
			participation_rate = index_term_part_rate_min_col_aig(t);
		}
		else
		{
			participation_rate = proposed_participation_rate;
		}
	}

	return participation_rate;
}



#line 1 "part_rate_solver_with_cap_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::part_rate_solver_with_cap_crbg(int t, double option_budget, double short_put, double long_call, double cap_rate , double strat_term_mths )
{	
	//20250811 MQ New external function adapted from the FIA par rate solver
	
	// Initialize
	int solve_iteration = 1;
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
	double solve_tolerance = max(part_rate_solve_tolerance_aig, SMALL_DOUBLE);
	double guess_low_bound = index_term_part_rate_min_col_aig(t);
	double guess_high_bound = index_term_part_rate_max_col_aig(t); 
	double guess_part_rate, solved_part_rate, adj_option_budget, long_strike, current_guess_diff;

	// Main solve loop
	while (true)
	{
		// Calculate guess
		guess_part_rate = (guess_low_bound + guess_high_bound) / 2.;

		// Get participation-rate-adjusted option budget
		adj_option_budget = long_call - (option_budget + short_put) / guess_part_rate;

		// Get strike from participation-rate-adjusted option budget
		long_strike = get_option_strike_aig(t - 1, adj_option_budget, CALL, strat_term_mths, strat_term_mths) - 1.0;

		// Get solved participation rate
		solved_part_rate = cap_rate / long_strike;

		// Calculate guess difference
		current_guess_diff = solved_part_rate - guess_part_rate;

		// Check solution
		if (fabs(current_guess_diff) <= solve_tolerance)
		{
			return solved_part_rate;
		}

		// Set next guess if not acceptable solution - simple bisection
		if (solved_part_rate > guess_part_rate)
		{
			guess_high_bound = guess_part_rate;
		}
		else
		{
			guess_low_bound = guess_part_rate;
		}

		if (guess_high_bound - guess_low_bound <= SMALL_DOUBLE) 
		{
			return guess_high_bound;
		}

		// Increase solve iteration counter
		solve_iteration++;

		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
		// Throw error if we can't find a solution in time
		if (solve_iteration > part_rate_solve_max_iter_aig)
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig; 
			xstring max_iter_str = xstring(part_rate_solve_max_iter_aig);
			xstring t_str = xstring(t);
			throw FatalError("Unable to achieve solved participation rate within " + max_iter_str + 
							 " iterations at t = " + t_str + " for account " + fund_id + " ! Increase part_rate_solve_max_iter_aig or part_rate_solve_tolerance_aig!");
		}
	}
}



#line 1 "secure_cap_base_opt_price_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::secure_cap_base_opt_price_aig(double x, double yrs_to_expiry, double vol, double risk_free_rate, double payout_rate, double k, double k_c, double k_b)
{
	// 20240422 MQ: New function to calculate option prce
	//Formula provided by MRM

	double divisor, d_plus, d_minus, d_c_plus, d_c_minus, d_b_plus, d_b_minus, opt_price, vol_x, vol_y, divisor_x, divisor_y;
	double r = 2.0 * log(1.0 + risk_free_rate / 2.0);
	double q = log(1.0 + payout_rate);
	divisor = vol * pow_legacy(yrs_to_expiry, .5);

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	xstring crediting_eqt_index_local = crediting_eqt_index;

	fia->bs_init_vol_type = "secure_cap_x";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_x = vol - fia->bs_fwrd_vol_aig;
	divisor_x = vol_x * pow_legacy(yrs_to_expiry, .5);

	fia->bs_init_vol_type = "secure_cap_y";
	fia->index_id_lookup = crediting_eqt_index_local;
	vol_y = vol + fia->bs_fwrd_vol_aig;
	divisor_y = vol_y * pow_legacy(yrs_to_expiry, .5);

	d_plus = (log(x / k) + (r - q + (vol * vol) / 2.0) * yrs_to_expiry) / divisor;		
	d_minus = (log(x / k) + (r - q - (vol * vol) / 2.0) * yrs_to_expiry) / divisor;
	d_c_plus = (log(x / k_c) + (r - q + (vol_x * vol_x) / 2.0) * yrs_to_expiry) / divisor_x;		
	d_c_minus = (log(x / k_c) + (r - q - (vol_x * vol_x) / 2.0) * yrs_to_expiry) / divisor_x;
	d_b_plus = (log(x / k_b) + (r - q + (vol_y * vol_y) / 2.0) * yrs_to_expiry) / divisor_y;		
	d_b_minus = (log(x / k_b) + (r - q - (vol_y * vol_y) / 2.0) * yrs_to_expiry) / divisor_y;

	opt_price = x * exp((r - q) * yrs_to_expiry) * (cumul_normal_distribn(d_plus) - cumul_normal_distribn(d_c_plus) + cumul_normal_distribn(-d_b_plus))
				- ( k * cumul_normal_distribn(d_minus) - k_c * cumul_normal_distribn(d_c_minus) + k_b * cumul_normal_distribn(-d_b_minus));

  return opt_price;
}



#line 1 "secure_cap_final_opt_val_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::secure_cap_final_opt_val_aig(double cap, double buffer, double portion_remaining_time, double strat_term, 
								double vol_param, double rf_rate, double dividend_yld, double price_zcb,
								double cumulated_realized_return, double current_term_return)
{
	// 20240422 MQ: New function to calculate option price for secure cap 
	// Formula provided by MRM

	double opt_price, cumul_future_return;

	int remaining_yrs = floor(round(portion_remaining_time * strat_term, 12));

	cumul_future_return = pow(1 + secure_cap_base_opt_price_aig(1, 1, vol_param, 
							rf_rate, dividend_yld, 1, 1 + cap, 1 - buffer), remaining_yrs);

	if(portion_remaining_time == 1)
		opt_price = price_zcb * (cumul_future_return - 1);
	else
		opt_price = price_zcb * (cumulated_realized_return * current_term_return * cumul_future_return - 1);

	return opt_price;
}



#line 1 "spread_solver_point_to_point_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::spread_solver_point_to_point_aig(int t)
{ 
	double spread;
	double option_budget = opt_budget(t);

	if (option_budget < rate_ratio_threshold)
	{
		spread = index_term_sprd_rate_max_col_aig(t);	// DTL 20181016 : fixed limiting value
		return spread;
	}

	const double TABLE_ATM_STRIKE = 1.0;
	double long_strike = TABLE_ATM_STRIKE;

	if ( opt_strike_price(t) - index_val(t) > SMALL_DOUBLE &&
		 index_val(t-1) > SMALL_DOUBLE                         )
	{
		//We guarantee some non-zero index credit
		long_strike = opt_strike_price(t) / index_val(t-1);
	}

	double long_cost = get_option_price_aig(t - 1, long_strike, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561 // 20190613 DTL: replaced `crediting_mths`


	if (option_budget > long_cost)
	{
		spread = index_term_sprd_rate_min_col_aig(t);	// DTL 20181016 : fixed limiting value
	}
	else
	{
		double solved_strike = get_option_strike_aig(t - 1, option_budget, CALL, strategy_term_mths_aig(t), index_term_mths_aig(t));// DTL 20200109 (START): TFS 86561 // 20190613 DTL: replaced `crediting_mths`

		double proposed_spread = solved_strike - 1.0;

		if (proposed_spread > index_term_sprd_rate_max_col_aig(t))	// DTL 20181016 : fixed limiting value
		{
			spread = index_term_sprd_rate_max_col_aig(t);	// DTL 20181016 : fixed limiting value
		}
		else if (proposed_spread < index_term_sprd_rate_min_col_aig(t))	// DTL 20181005 : fixed limiting value
		{
			spread = index_term_sprd_rate_min_col_aig(t);	// DTL 20181016 : fixed limiting value
		}
		else
		{
			spread = proposed_spread;
		}
	}

	return spread;
}



#line 1 "strike.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::strike(int t, int reserve_period, int mths_in_first_period)
{
if (t < 0)
	return 0.0;

// If first year projection, grab index at last policy anniversary
// Otherwise use 1 (arbitrary) since future options are assumed to be purchased at the money	
if (t == 1)
	{
	int per = reserve_period - (strategy_term_mths_aig(t) /*crediting_mths*/ - mths_in_first_period);// 20190613 DTL: replaced `crediting_mths`
	
	return index_val_calc(per);
	}

return 1.0;
}



#line 1 "strike_cap.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::strike_cap(int t, int reserve_period, int mths_in_first_period)
{
if (t < 0)
	return 0.0;

double rate = 1.0;

// If first year of reserve projection, grab index at last policy anniversary
// Otherwise use 1 (arbitrary) since future options are assumed to be purchased at the money

double crediting_cap_minimum_cv;
// `crediting_cap_min` Code Variable is not correctly connected
// and is also replaceable by `index_term_cap_rate_min_aig`
crediting_cap_minimum_cv = index_term_cap_rate_min_col_aig(t);
		
if (t == 1)	  		 
	return strike(t, reserve_period, mths_in_first_period) 
		   * (max(crediting_cap_rate(reserve_period), crediting_cap_minimum_cv) + 1.0); // "* (max(crediting_cap_rate(reserve_period), crediting_cap_min) + 1.0);" DTL 20190415
	
rate = 1.0 + crediting_cap_minimum_cv;  // "rate = 1.0 + crediting_cap_min;" DTL 20190415
		
return 1.0 * rate;
}



#line 1 "time_to_expiry_aig.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::time_to_expiry_aig(int policy_month, int reserve_period)
{
	if (policy_month < 0)
	{
		return 0.0;
	}

	double init_remaining_mths = 
		index_term_mths_aig(reserve_period) - index_term_elapsed_mths_eom_aig(reserve_period);
	double init_crediting_mth  = init_remaining_mths + reserve_period;

	double yrs_to_expiration;
	if (policy_month < init_crediting_mth)
	{
		yrs_to_expiration = init_remaining_mths / 12.0;
	}
	else if (policy_month == init_crediting_mth)
	{
		yrs_to_expiration = index_term_aig(policy_month + 1);
	}
	else
	{
		yrs_to_expiration = index_term_aig(policy_month);
	}

	return yrs_to_expiration;
}



#line 1 "underlying_price.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::underlying_price(int t, int reserve_period)
{
if (t < 0 )
	return 0.0;

// If first year of reserve projection, grab current index
// Otherwise use 1000 (arbitrary) since future options are assumed to be purchased at the money
if (t == 1)
	return index_val_calc(reserve_period);  

return 1;
}



	static FIAAFUND_LIAB_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (FIAAFUND_LIAB_UDF::*dPXi) (int);
typedef double (FIAAFUND_LIAB_UDF::*dPXid) (int, double);
typedef double (FIAAFUND_LIAB_UDF::*dPF) ();
typedef double (FIAAFUND_LIAB_UDF::*dPFd) (double);
typedef int (FIAAFUND_LIAB_UDF::*iPF) ();
typedef int (FIAAFUND_LIAB_UDF::*iPFi) (int);
typedef xstring (FIAAFUND_LIAB_UDF::*sPF) ();
typedef xstring (FIAAFUND_LIAB_UDF::*sPFs) (xstring);

const CashFlowCommonData FIAAFUND_LIAB::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "admin_fee", "fiaafund_liab_admin_fee",  "admin_fee",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_admin_fee, 'B','Y', '3', 'C', (size_t)&modelOffset->admin_fee),
	CashFlowCommonData(2, "combo_strat_ind_par_rate_crbg", "fiaafund_liab_combo_strat_ind_par_rate_crbg",  "combo_strat_ind_par_rate_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_combo_strat_ind_par_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->combo_strat_ind_par_rate_crbg),
	CashFlowCommonData(3, "combo_strat_renew_status_crbg", "fiaafund_liab_combo_strat_renew_status_crbg",  "combo_strat_renew_status_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_combo_strat_renew_status_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->combo_strat_renew_status_crbg),
	CashFlowCommonData(4, "credited_int", "fiaafund_liab_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(5, "crediting_2nd_strat_buffer_cap_aig", "fiaafund_liab_crediting_2nd_strat_buffer_cap_aig",  "crediting_2nd_strat_buffer_cap_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_2nd_strat_buffer_cap_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_2nd_strat_buffer_cap_aig),
	CashFlowCommonData(6, "crediting_2nd_strat_dual_dir_cap_aig", "fiaafund_liab_crediting_2nd_strat_dual_dir_cap_aig",  "crediting_2nd_strat_dual_dir_cap_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_2nd_strat_dual_dir_cap_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_2nd_strat_dual_dir_cap_aig),
	CashFlowCommonData(7, "crediting_cap_rate", "fiaafund_liab_crediting_cap_rate",  "crediting_cap_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_cap_rate, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_cap_rate),
	CashFlowCommonData(8, "crediting_dual_dir_cap_aig", "fiaafund_liab_crediting_dual_dir_cap_aig",  "crediting_dual_dir_cap_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_dual_dir_cap_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_dual_dir_cap_aig),
	CashFlowCommonData(9, "crediting_dual_dir_trigger_crbg", "fiaafund_liab_crediting_dual_dir_trigger_crbg",  "crediting_dual_dir_trigger_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_dual_dir_trigger_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_dual_dir_trigger_crbg),
	CashFlowCommonData(10, "crediting_part_rate_aig", "fiaafund_liab_crediting_part_rate_aig",  "crediting_part_rate_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_part_rate_aig),
	CashFlowCommonData(11, "crediting_part_rate_base_aig", "fiaafund_liab_crediting_part_rate_base_aig",  "crediting_part_rate_base_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate_base_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_part_rate_base_aig),
	CashFlowCommonData(12, "crediting_pri_sprd_aig", "fiaafund_liab_crediting_pri_sprd_aig",  "crediting_pri_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_pri_sprd_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_pri_sprd_aig),
	CashFlowCommonData(13, "crediting_rate", "fiaafund_liab_crediting_rate",  "crediting_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate),
	CashFlowCommonData(14, "crediting_rate_chg_threshold_aig", "fiaafund_liab_crediting_rate_chg_threshold_aig",  "crediting_rate_chg_threshold_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_chg_threshold_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_chg_threshold_aig),
	CashFlowCommonData(15, "crediting_rate_cumul_aig", "fiaafund_liab_crediting_rate_cumul_aig",  "crediting_rate_cumul_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_cumul_aig, 'E','N', '3', 'P', (size_t)&modelOffset->crediting_rate_cumul_aig),
	CashFlowCommonData(16, "crediting_rate_fix", "fiaafund_liab_crediting_rate_fix",  "crediting_rate_fix",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_fix, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate_fix),
	CashFlowCommonData(17, "crediting_rate_fix_cumul_aig", "fiaafund_liab_crediting_rate_fix_cumul_aig",  "crediting_rate_fix_cumul_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_fix_cumul_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_fix_cumul_aig),
	CashFlowCommonData(18, "crediting_rate_max_annual_chg_down_aig", "fiaafund_liab_crediting_rate_max_annual_chg_down_aig",  "crediting_rate_max_annual_chg_down_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_max_annual_chg_down_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_max_annual_chg_down_aig),
	CashFlowCommonData(19, "crediting_rate_max_annual_chg_up_aig", "fiaafund_liab_crediting_rate_max_annual_chg_up_aig",  "crediting_rate_max_annual_chg_up_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_max_annual_chg_up_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_max_annual_chg_up_aig),
	CashFlowCommonData(20, "crediting_secure_cap_aig", "fiaafund_liab_crediting_secure_cap_aig",  "crediting_secure_cap_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_secure_cap_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_secure_cap_aig),
	CashFlowCommonData(21, "crediting_spread_rate_aig", "fiaafund_liab_crediting_spread_rate_aig",  "crediting_spread_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_spread_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_spread_rate_aig),
	CashFlowCommonData(22, "crediting_trigger_rate_aig", "fiaafund_liab_crediting_trigger_rate_aig",  "crediting_trigger_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_trigger_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_trigger_rate_aig),
	CashFlowCommonData(23, "crediting_type_dyn_trigger_aig", "fiaafund_liab_crediting_type_dyn_trigger_aig",  "crediting_type_dyn_trigger_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_type_dyn_trigger_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_type_dyn_trigger_aig),
	CashFlowCommonData(24, "crediting_type_dyn_zero_threshold_flag_aig", "fiaafund_liab_crediting_type_dyn_zero_threshold_flag_aig",  "crediting_type_dyn_zero_threshold_flag_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_type_dyn_zero_threshold_flag_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_type_dyn_zero_threshold_flag_aig),
	CashFlowCommonData(25, "eprs_cost_rate_aig", "fiaafund_liab_eprs_cost_rate_aig",  "eprs_cost_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_cost_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_cost_rate_aig),
	CashFlowCommonData(26, "fund_released_ann", "fiaafund_liab_fund_released_ann",  "fund_released_ann",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_ann, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_ann),
	CashFlowCommonData(27, "fund_released_dth", "fiaafund_liab_fund_released_dth",  "fund_released_dth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_dth, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_dth),
	CashFlowCommonData(28, "fund_released_maturity", "fiaafund_liab_fund_released_maturity",  "fund_released_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_maturity, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_maturity),
	CashFlowCommonData(29, "fund_released_surr", "fiaafund_liab_fund_released_surr",  "fund_released_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_surr, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_surr),
	CashFlowCommonData(30, "fund_released_withdrl", "fiaafund_liab_fund_released_withdrl",  "fund_released_withdrl",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_withdrl, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_withdrl),
	CashFlowCommonData(31, "fund_val_b", "fiaafund_liab_fund_val_b",  "fund_val_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b),
	CashFlowCommonData(32, "fund_val_b_bef", "fiaafund_liab_fund_val_b_bef",  "fund_val_b_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b_bef, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b_bef),
	CashFlowCommonData(33, "fund_val_decrem", "fiaafund_liab_fund_val_decrem",  "fund_val_decrem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_decrem, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_decrem),
	CashFlowCommonData(34, "fund_val_e", "fiaafund_liab_fund_val_e",  "fund_val_e",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_e),
	CashFlowCommonData(35, "fund_val_e_bef", "fiaafund_liab_fund_val_e_bef",  "fund_val_e_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_e_bef),
	CashFlowCommonData(36, "fund_val_e_bef_maturity_aig", "fiaafund_liab_fund_val_e_bef_maturity_aig",  "fund_val_e_bef_maturity_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef_maturity_aig, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_e_bef_maturity_aig),
	CashFlowCommonData(37, "fund_val_rebal", "fiaafund_liab_fund_val_rebal",  "fund_val_rebal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_rebal, 'B','Y', '3', 'C', (size_t)&modelOffset->fund_val_rebal),
	CashFlowCommonData(38, "fund_weighted_crediting_pri_sprd_aig", "fiaafund_liab_fund_weighted_crediting_pri_sprd_aig",  "fund_weighted_crediting_pri_sprd_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_weighted_crediting_pri_sprd_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->fund_weighted_crediting_pri_sprd_aig),
	CashFlowCommonData(39, "gmwb_chg", "fiaafund_liab_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(40, "gmwb_chg_at_surr_aig", "fiaafund_liab_gmwb_chg_at_surr_aig",  "gmwb_chg_at_surr_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_at_surr_aig, 'E','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_at_surr_aig),
	CashFlowCommonData(41, "gmwb_chg_at_surr_bef_aig", "fiaafund_liab_gmwb_chg_at_surr_bef_aig",  "gmwb_chg_at_surr_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_at_surr_bef_aig, 'E','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_at_surr_bef_aig),
	CashFlowCommonData(42, "gmwb_income_base_credit_rate_protation_fct_at_wdl_aig", "fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_at_wdl_aig",  "gmwb_income_base_credit_rate_protation_fct_at_wdl_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_at_wdl_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_base_credit_rate_protation_fct_at_wdl_aig),
	CashFlowCommonData(43, "gmwb_income_base_credit_rate_protation_fct_e_aig", "fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_aig",  "gmwb_income_base_credit_rate_protation_fct_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_base_credit_rate_protation_fct_e_aig),
	CashFlowCommonData(44, "gmwb_income_base_credit_rate_protation_fct_e_bef_aig", "fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_bef_aig",  "gmwb_income_base_credit_rate_protation_fct_e_bef_wdl_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_income_base_credit_rate_protation_fct_e_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_base_credit_rate_protation_fct_e_bef_aig),
	CashFlowCommonData(45, "hedge_cash_flow", "fiaafund_liab_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(46, "hedge_inv_amt_bom", "fiaafund_liab_hedge_inv_amt_bom",  "hedge_inv_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_inv_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_bom),
	CashFlowCommonData(47, "hedge_mkt_val", "fiaafund_liab_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(48, "hedge_mkt_val_aig", "fiaafund_liab_hedge_mkt_val_aig",  "hedge_mkt_val_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_aig),
	CashFlowCommonData(49, "hedge_mkt_val_growth", "fiaafund_liab_hedge_mkt_val_growth",  "hedge_mkt_val_growth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_growth, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_growth),
	CashFlowCommonData(50, "hedge_mkt_val_per_unit_notional", "fiaafund_liab_hedge_mkt_val_per_unit_notional",  "hedge_mkt_val_per_unit_notional",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_per_unit_notional, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_per_unit_notional),
	CashFlowCommonData(51, "hedge_mkt_val_per_unit_notional_aig", "fiaafund_liab_hedge_mkt_val_per_unit_notional_aig",  "hedge_mkt_val_per_unit_notional_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_per_unit_notional_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_per_unit_notional_aig),
	CashFlowCommonData(52, "hedge_option_val_alpha_col_aig", "fiaafund_liab_hedge_option_val_alpha_col_aig",  "hedge_option_val_alpha_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_option_val_alpha_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_option_val_alpha_col_aig),
	CashFlowCommonData(53, "hedge_rila_trading_cost_aig", "fiaafund_liab_hedge_rila_trading_cost_aig",  "hedge_rila_trading_cost_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_rila_trading_cost_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_rila_trading_cost_aig),
	CashFlowCommonData(54, "hedge_sale_amt_bom", "fiaafund_liab_hedge_sale_amt_bom",  "hedge_sale_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt_bom),
	CashFlowCommonData(55, "hedge_sale_amt_eom", "fiaafund_liab_hedge_sale_amt_eom",  "hedge_sale_amt_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt_eom),
	CashFlowCommonData(56, "index_term_aig", "fiaafund_liab_index_term_aig",  "index_term_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_aig),
	CashFlowCommonData(57, "index_term_beginning_index_val_bom_aig", "fiaafund_liab_index_term_beginning_index_val_bom_aig",  "index_term_beginning_index_val_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_beginning_index_val_bom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_beginning_index_val_bom_aig),
	CashFlowCommonData(58, "index_term_cap_rate_max_col_aig", "fiaafund_liab_index_term_cap_rate_max_col_aig",  "index_term_cap_rate_max_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_cap_rate_max_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_cap_rate_max_col_aig),
	CashFlowCommonData(59, "index_term_cap_rate_min_col_aig", "fiaafund_liab_index_term_cap_rate_min_col_aig",  "index_term_cap_rate_min_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_cap_rate_min_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_cap_rate_min_col_aig),
	CashFlowCommonData(60, "index_term_elapsed_mths_eom_aig", "fiaafund_liab_index_term_elapsed_mths_eom_aig",  "index_term_elapsed_mths_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_mths_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_elapsed_mths_eom_aig),
	CashFlowCommonData(61, "index_term_elapsed_pct_eom_aig", "fiaafund_liab_index_term_elapsed_pct_eom_aig",  "index_term_elapsed_pct_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_pct_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_elapsed_pct_eom_aig),
	CashFlowCommonData(62, "index_term_end_duration_aig", "fiaafund_liab_index_term_end_duration_aig",  "index_term_end_duration_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_end_duration_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_end_duration_aig),
	CashFlowCommonData(63, "index_term_floor_col_aig", "fiaafund_liab_index_term_floor_col_aig",  "index_term_floor_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_floor_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_floor_col_aig),
	CashFlowCommonData(64, "index_term_index_return_aig", "fiaafund_liab_index_term_index_return_aig",  "index_term_index_return_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_index_return_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_index_return_aig),
	CashFlowCommonData(65, "index_term_init_spread_rate_aig", "fiaafund_liab_index_term_init_spread_rate_aig",  "index_term_init_spread_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_init_spread_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_init_spread_rate_aig),
	CashFlowCommonData(66, "index_term_mths_aig", "fiaafund_liab_index_term_mths_aig",  "index_term_mths_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_mths_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_mths_aig),
	CashFlowCommonData(67, "index_term_part_rate_max_col_aig", "fiaafund_liab_index_term_part_rate_max_col_aig",  "index_term_part_rate_max_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_part_rate_max_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_part_rate_max_col_aig),
	CashFlowCommonData(68, "index_term_part_rate_min_col_aig", "fiaafund_liab_index_term_part_rate_min_col_aig",  "index_term_part_rate_min_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_part_rate_min_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_part_rate_min_col_aig),
	CashFlowCommonData(69, "index_term_sprd_rate_max_col_aig", "fiaafund_liab_index_term_sprd_rate_max_col_aig",  "index_term_sprd_rate_max_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_sprd_rate_max_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_sprd_rate_max_col_aig),
	CashFlowCommonData(70, "index_term_sprd_rate_min_col_aig", "fiaafund_liab_index_term_sprd_rate_min_col_aig",  "index_term_sprd_rate_min_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_sprd_rate_min_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_sprd_rate_min_col_aig),
	CashFlowCommonData(71, "index_term_start_duration_aig", "fiaafund_liab_index_term_start_duration_aig",  "index_term_start_duration_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_start_duration_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_start_duration_aig),
	CashFlowCommonData(72, "index_val", "fiaafund_liab_index_val",  "index_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_val, 'E','Y', '3', 'C', (size_t)&modelOffset->index_val),
	CashFlowCommonData(73, "index_val_bom", "fiaafund_liab_index_val_bom",  "index_val_bom",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_val_bom, 'E','Y', '3', 'P', (size_t)&modelOffset->index_val_bom),
	CashFlowCommonData(74, "init_cap_rate_aig", "fiaafund_liab_init_cap_rate_aig",  "init_cap_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_init_cap_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->init_cap_rate_aig),
	CashFlowCommonData(75, "init_part_rate_aig", "fiaafund_liab_init_part_rate_aig",  "init_part_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_init_part_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->init_part_rate_aig),
	CashFlowCommonData(76, "initialize", "fiaafund_liab_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(77, "lapse_dyn_base_prod_crediting_rt_aig", "fiaafund_liab_lapse_dyn_base_prod_crediting_rt_aig",  "lapse_dyn_base_prod_crediting_rt_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_lapse_dyn_base_prod_crediting_rt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_base_prod_crediting_rt_aig),
	CashFlowCommonData(78, "min_accum_val_b_aig", "fiaafund_liab_min_accum_val_b_aig",  "min_accum_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_b_aig),
	CashFlowCommonData(79, "min_accum_val_b_bef_aig", "fiaafund_liab_min_accum_val_b_bef_aig",  "min_accum_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_b_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_b_bef_aig),
	CashFlowCommonData(80, "min_accum_val_e_aig", "fiaafund_liab_min_accum_val_e_aig",  "min_accum_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_e_aig),
	CashFlowCommonData(81, "min_accum_val_e_bef_aig", "fiaafund_liab_min_accum_val_e_bef_aig",  "min_accum_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_e_bef_aig),
	CashFlowCommonData(82, "min_accum_val_e_bef_maturity_aig", "fiaafund_liab_min_accum_val_e_bef_maturity_aig",  "min_accum_val_e_bef_maturity_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_min_accum_val_e_bef_maturity_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_e_bef_maturity_aig),
	CashFlowCommonData(83, "mwv_base_b_aig", "fiaafund_liab_mwv_base_b_aig",  "mwv_base_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_base_b_aig),
	CashFlowCommonData(84, "mwv_base_e_aig", "fiaafund_liab_mwv_base_e_aig",  "mwv_base_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_base_e_aig),
	CashFlowCommonData(85, "mwv_base_e_bef_aig", "fiaafund_liab_mwv_base_e_bef_aig",  "mwv_base_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_base_e_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_base_e_bef_aig),
	CashFlowCommonData(86, "mwv_interim_val_b_aig", "fiaafund_liab_mwv_interim_val_b_aig",  "mwv_interim_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_interim_val_b_aig),
	CashFlowCommonData(87, "mwv_interim_val_e_aig", "fiaafund_liab_mwv_interim_val_e_aig",  "mwv_interim_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_interim_val_e_aig),
	CashFlowCommonData(88, "mwv_interim_val_e_bef_aig", "fiaafund_liab_mwv_interim_val_e_bef_aig",  "mwv_interim_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_mwv_interim_val_e_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->mwv_interim_val_e_bef_aig),
	CashFlowCommonData(89, "net_crediting_rate_aig", "fiaafund_liab_net_crediting_rate_aig",  "net_crediting_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_net_crediting_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->net_crediting_rate_aig),
	CashFlowCommonData(90, "notional_amt_required", "fiaafund_liab_notional_amt_required",  "notional_amt_required",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_required),
	CashFlowCommonData(91, "notional_amt_required_bef", "fiaafund_liab_notional_amt_required_bef",  "notional_amt_required_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required_bef, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_required_bef),
	CashFlowCommonData(92, "notional_to_hedge", "fiaafund_liab_notional_to_hedge",  "notional_to_hedge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge),
	CashFlowCommonData(93, "notional_to_hedge_aig", "fiaafund_liab_notional_to_hedge_aig",  "notional_to_hedge_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_to_hedge_aig),
	CashFlowCommonData(94, "notional_to_hedge_cap", "fiaafund_liab_notional_to_hedge_cap",  "notional_to_hedge_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_cap, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_cap),
	CashFlowCommonData(95, "notional_to_hedge_index", "fiaafund_liab_notional_to_hedge_index",  "notional_to_hedge_index",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_index, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_index),
	CashFlowCommonData(96, "notional_to_hedge_long_strike", "fiaafund_liab_notional_to_hedge_long_strike",  "notional_to_hedge_long_strike",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_long_strike, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_long_strike),
	CashFlowCommonData(97, "notional_to_hedge_net", "fiaafund_liab_notional_to_hedge_net",  "notional_to_hedge_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_net, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_net),
	CashFlowCommonData(98, "opt_budget", "fiaafund_liab_opt_budget",  "opt_budget",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget),
	CashFlowCommonData(99, "opt_budget_amt", "fiaafund_liab_opt_budget_amt",  "opt_budget_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_amt, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget_amt),
	CashFlowCommonData(100, "opt_budget_cost_aig", "fiaafund_liab_opt_budget_cost_aig",  "opt_budget_cost_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_cost_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->opt_budget_cost_aig),
	CashFlowCommonData(101, "opt_budget_eprs_aig", "fiaafund_liab_opt_budget_eprs_aig",  "opt_budget_eprs_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_eprs_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_eprs_aig),
	CashFlowCommonData(102, "opt_budget_renewal_2nd_strat_aig", "fiaafund_liab_opt_budget_renewal_2nd_strat_aig",  "opt_budget_renewal_2nd_strat_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_renewal_2nd_strat_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_renewal_2nd_strat_aig),
	CashFlowCommonData(103, "opt_budget_renewal_aig", "fiaafund_liab_opt_budget_renewal_aig",  "opt_budget_renewal_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_renewal_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_renewal_aig),
	CashFlowCommonData(104, "opt_budget_strategy_term_renewal_aig", "fiaafund_liab_opt_budget_strategy_term_renewal_aig",  "opt_budget_strategy_term_renewal_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_strategy_term_renewal_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_strategy_term_renewal_aig),
	CashFlowCommonData(105, "opt_budget_tgt_aig", "fiaafund_liab_opt_budget_tgt_aig",  "opt_budget_tgt_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_tgt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_tgt_aig),
	CashFlowCommonData(106, "opt_cost_atm_aig", "fiaafund_liab_opt_cost_atm_aig",  "opt_cost_atm_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_atm_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_atm_aig),
	CashFlowCommonData(107, "opt_payoff", "fiaafund_liab_opt_payoff",  "opt_payoff",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_payoff, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_payoff),
	CashFlowCommonData(108, "opt_payoff_aig", "fiaafund_liab_opt_payoff_aig",  "opt_payoff_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_payoff_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_payoff_aig),
	CashFlowCommonData(109, "opt_strike_price", "fiaafund_liab_opt_strike_price",  "opt_strike_price",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_strike_price, 'E','N', '3', 'P', (size_t)&modelOffset->opt_strike_price),
	CashFlowCommonData(110, "opt_value_net_numer", "fiaafund_liab_opt_value_net_numer",  "opt_value_net_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_value_net_numer, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_value_net_numer),
	CashFlowCommonData(111, "pfwd_surr_fund_val", "fiaafund_liab_pfwd_surr_fund_val",  "pfwd_surr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_pfwd_surr_fund_val, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_fund_val),
	CashFlowCommonData(112, "prem_alloc", "fiaafund_liab_prem_alloc",  "prem_alloc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_prem_alloc, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_alloc),
	CashFlowCommonData(113, "prem_bonus", "fiaafund_liab_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(114, "renew_into_2nd_strat_status_aig", "fiaafund_liab_renew_into_2nd_strat_status_aig",  "renew_into_2nd_strat_status_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_renew_into_2nd_strat_status_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->renew_into_2nd_strat_status_aig),
	CashFlowCommonData(115, "rila_buffer_amt_aig", "fiaafund_liab_rila_buffer_amt_aig",  "rila_buffer_amt_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_buffer_amt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_buffer_amt_aig),
	CashFlowCommonData(116, "rila_init_opt_cost_by_grid_2nd_strat_aig", "fiaafund_liab_rila_init_opt_cost_by_grid_2nd_strat_aig",  "rila_init_opt_cost_by_grid_2nd_strat_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_init_opt_cost_by_grid_2nd_strat_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_init_opt_cost_by_grid_2nd_strat_aig),
	CashFlowCommonData(117, "rila_int_val_beg_term_bom_aig", "fiaafund_liab_rila_int_val_beg_term_bom_aig",  "rila_int_val_beg_term_bom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_int_val_beg_term_bom_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->rila_int_val_beg_term_bom_aig),
	CashFlowCommonData(118, "rila_int_val_beg_term_eom_aig", "fiaafund_liab_rila_int_val_beg_term_eom_aig",  "rila_int_val_beg_term_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_int_val_beg_term_eom_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->rila_int_val_beg_term_eom_aig),
	CashFlowCommonData(119, "rila_interim_value_b_aig", "fiaafund_liab_rila_interim_value_b_aig",  "rila_interim_value_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_b_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_b_aig),
	CashFlowCommonData(120, "rila_interim_value_dapv_e_aig", "fiaafund_liab_rila_interim_value_dapv_e_aig",  "rila_interim_value_dapv_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_dapv_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_dapv_e_aig),
	CashFlowCommonData(121, "rila_interim_value_e_aig", "fiaafund_liab_rila_interim_value_e_aig",  "rila_interim_value_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_e_aig),
	CashFlowCommonData(122, "rila_interim_value_e_bef_aig", "fiaafund_liab_rila_interim_value_e_bef_aig",  "rila_interim_value_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_e_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_e_bef_aig),
	CashFlowCommonData(123, "rila_interim_value_fiapv_e_aig", "fiaafund_liab_rila_interim_value_fiapv_e_aig",  "rila_interim_value_fiapv_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_fiapv_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_fiapv_e_aig),
	CashFlowCommonData(124, "rila_interim_value_growth_aig", "fiaafund_liab_rila_interim_value_growth_aig",  "rila_interim_value_growth_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_growth_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_growth_aig),
	CashFlowCommonData(125, "rila_interim_value_tc_e_aig", "fiaafund_liab_rila_interim_value_tc_e_aig",  "rila_interim_value_tc_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_interim_value_tc_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_interim_value_tc_e_aig),
	CashFlowCommonData(126, "rila_knockout_cost_interim_val_e_aig", "fiaafund_liab_rila_knockout_cost_interim_val_e_aig",  "rila_knockout_cost_interim_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_cost_interim_val_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_knockout_cost_interim_val_e_aig),
	CashFlowCommonData(127, "rila_knockout_cost_interim_val_init_aig", "fiaafund_liab_rila_knockout_cost_interim_val_init_aig",  "rila_knockout_cost_interim_val_init_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_cost_interim_val_init_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_knockout_cost_interim_val_init_aig),
	CashFlowCommonData(128, "rila_knockout_mth_aig", "fiaafund_liab_rila_knockout_mth_aig",  "rila_knockout_mth_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_mth_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_knockout_mth_aig),
	CashFlowCommonData(129, "rila_knockout_status_bom_aig", "fiaafund_liab_rila_knockout_status_bom_aig",  "rila_knockout_status_bom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_status_bom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_knockout_status_bom_aig),
	CashFlowCommonData(130, "rila_knockout_status_eom_aig", "fiaafund_liab_rila_knockout_status_eom_aig",  "rila_knockout_status_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_knockout_status_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_knockout_status_eom_aig),
	CashFlowCommonData(131, "rila_opt_cost_beg_strat_term_aig", "fiaafund_liab_rila_opt_cost_beg_strat_term_aig",  "rila_opt_cost_beg_strat_term_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_beg_strat_term_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_opt_cost_beg_strat_term_aig),
	CashFlowCommonData(132, "rila_opt_cost_bs_b_aig", "fiaafund_liab_rila_opt_cost_bs_b_aig",  "rila_opt_cost_bs_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_bs_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_opt_cost_bs_b_aig),
	CashFlowCommonData(133, "rila_opt_cost_bs_e_aig", "fiaafund_liab_rila_opt_cost_bs_e_aig",  "rila_opt_cost_bs_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_bs_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_opt_cost_bs_e_aig),
	CashFlowCommonData(134, "rila_opt_cost_by_grid_b_aig", "fiaafund_liab_rila_opt_cost_by_grid_b_aig",  "rila_opt_cost_by_grid_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_by_grid_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_opt_cost_by_grid_b_aig),
	CashFlowCommonData(135, "rila_opt_cost_by_grid_e_aig", "fiaafund_liab_rila_opt_cost_by_grid_e_aig",  "rila_opt_cost_by_grid_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_opt_cost_by_grid_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_opt_cost_by_grid_e_aig),
	CashFlowCommonData(136, "rila_perf_lock_hwm_aig", "fiaafund_liab_rila_perf_lock_hwm_aig",  "rila_perf_lock_hwm_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_hwm_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_perf_lock_hwm_aig),
	CashFlowCommonData(137, "rila_perf_lock_prob_aig", "fiaafund_liab_rila_perf_lock_prob_aig",  "rila_perf_lock_prob_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_prob_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_perf_lock_prob_aig),
	CashFlowCommonData(138, "rila_perf_lock_status_bom_aig", "fiaafund_liab_rila_perf_lock_status_bom_aig",  "rila_perf_lock_status_bom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_status_bom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_perf_lock_status_bom_aig),
	CashFlowCommonData(139, "rila_perf_lock_status_eom_aig", "fiaafund_liab_rila_perf_lock_status_eom_aig",  "rila_perf_lock_status_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_perf_lock_status_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_perf_lock_status_eom_aig),
	CashFlowCommonData(140, "rila_smax_brownian_bridge_aig", "fiaafund_liab_rila_smax_brownian_bridge_aig",  "rila_smax_brownian_bridge_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_smax_brownian_bridge_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_smax_brownian_bridge_aig),
	CashFlowCommonData(141, "rila_strat_base_b_aig", "fiaafund_liab_rila_strat_base_b_aig",  "rila_strat_base_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_strat_base_b_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->rila_strat_base_b_aig),
	CashFlowCommonData(142, "rila_strat_base_e_aig", "fiaafund_liab_rila_strat_base_e_aig",  "rila_strat_base_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_strat_base_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_strat_base_e_aig),
	CashFlowCommonData(143, "rila_trading_cost_pct_bom_aig", "fiaafund_liab_rila_trading_cost_pct_bom_aig",  "rila_trading_cost_pct_bom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_trading_cost_pct_bom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_trading_cost_pct_bom_aig),
	CashFlowCommonData(144, "rila_trading_cost_pct_eom_aig", "fiaafund_liab_rila_trading_cost_pct_eom_aig",  "rila_trading_cost_pct_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_rila_trading_cost_pct_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->rila_trading_cost_pct_eom_aig),
	CashFlowCommonData(145, "sfas133_gmwb_chg", "fiaafund_liab_sfas133_gmwb_chg",  "sfas133_gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_sfas133_gmwb_chg, 'B','Y', '3', 'C', (size_t)&modelOffset->sfas133_gmwb_chg),
	CashFlowCommonData(146, "startup", "fiaafund_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(147, "strategy_return_aig", "fiaafund_liab_strategy_return_aig",  "strategy_return_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_aig, 'E','N', '3', 'C', (size_t)&modelOffset->strategy_return_aig),
	CashFlowCommonData(148, "strategy_return_cumul_aig", "fiaafund_liab_strategy_return_cumul_aig",  "strategy_return_cumul_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_cumul_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_cumul_aig),
	CashFlowCommonData(149, "strategy_return_index_aig", "fiaafund_liab_strategy_return_index_aig",  "strategy_return_index_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_index_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_index_aig),
	CashFlowCommonData(150, "strategy_return_index_rila_aig", "fiaafund_liab_strategy_return_index_rila_aig",  "strategy_return_index_rila_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_index_rila_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_index_rila_aig),
	CashFlowCommonData(151, "strategy_return_prior_index_term_aig", "fiaafund_liab_strategy_return_prior_index_term_aig",  "strategy_return_prior_index_term_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prior_index_term_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_prior_index_term_aig),
	CashFlowCommonData(152, "strategy_return_prior_index_term_eom_aig", "fiaafund_liab_strategy_return_prior_index_term_eom_aig",  "strategy_return_prior_index_term_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prior_index_term_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_prior_index_term_eom_aig),
	CashFlowCommonData(153, "strategy_return_prorated_aig", "fiaafund_liab_strategy_return_prorated_aig",  "strategy_return_prorated_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_prorated_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_prorated_aig),
	CashFlowCommonData(154, "strategy_term_aig", "fiaafund_liab_strategy_term_aig",  "strategy_term_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_aig),
	CashFlowCommonData(155, "strategy_term_beginning_index_val_bom_aig", "fiaafund_liab_strategy_term_beginning_index_val_bom_aig",  "strategy_term_beginning_index_val_bom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_beginning_index_val_bom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_beginning_index_val_bom_aig),
	CashFlowCommonData(156, "strategy_term_elapsed_mths_eom_aig", "fiaafund_liab_strategy_term_elapsed_mths_eom_aig",  "strategy_term_elapsed_mths_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_elapsed_mths_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_elapsed_mths_eom_aig),
	CashFlowCommonData(157, "strategy_term_elapsed_pct_eom_aig", "fiaafund_liab_strategy_term_elapsed_pct_eom_aig",  "strategy_term_elapsed_pct_eom_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_elapsed_pct_eom_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_elapsed_pct_eom_aig),
	CashFlowCommonData(158, "strategy_term_floor_col_aig", "fiaafund_liab_strategy_term_floor_col_aig",  "strategy_term_floor_col_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_floor_col_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_floor_col_aig),
	CashFlowCommonData(159, "strategy_term_index_return_aig", "fiaafund_liab_strategy_term_index_return_aig",  "strategy_term_index_return_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_index_return_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_index_return_aig),
	CashFlowCommonData(160, "strategy_term_mths_aig", "fiaafund_liab_strategy_term_mths_aig",  "strategy_term_mths_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_term_mths_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_term_mths_aig),
	CashFlowCommonData(161, "tier_number_aig", "fiaafund_liab_tier_number_aig",  "tier_number_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_tier_number_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->tier_number_aig),
	CashFlowCommonData(162, "tier_strat_fee_aig", "fiaafund_liab_tier_strat_fee_aig",  "tier_strat_fee_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_aig, 'B','Y', '3', 'P', (size_t)&modelOffset->tier_strat_fee_aig),
	CashFlowCommonData(163, "tier_strat_fee_at_surr_aig", "fiaafund_liab_tier_strat_fee_at_surr_aig",  "tier_strat_fee_at_surr_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_at_surr_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->tier_strat_fee_at_surr_aig),
	CashFlowCommonData(164, "tier_strat_fee_at_surr_bef_aig", "fiaafund_liab_tier_strat_fee_at_surr_bef_aig",  "tier_strat_fee_at_surr_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_tier_strat_fee_at_surr_bef_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->tier_strat_fee_at_surr_bef_aig)
};
const CashFlowCommonData* FIAAFUND_LIAB::mCFStaticData[] = {
	&FIAAFUND_LIAB::mCFStaticData_0[0],
	&FIAAFUND_LIAB::mCFStaticData_0[1],
	&FIAAFUND_LIAB::mCFStaticData_0[2],
	&FIAAFUND_LIAB::mCFStaticData_0[3],
	&FIAAFUND_LIAB::mCFStaticData_0[4],
	&FIAAFUND_LIAB::mCFStaticData_0[5],
	&FIAAFUND_LIAB::mCFStaticData_0[6],
	&FIAAFUND_LIAB::mCFStaticData_0[7],
	&FIAAFUND_LIAB::mCFStaticData_0[8],
	&FIAAFUND_LIAB::mCFStaticData_0[9],
	&FIAAFUND_LIAB::mCFStaticData_0[10],
	&FIAAFUND_LIAB::mCFStaticData_0[11],
	&FIAAFUND_LIAB::mCFStaticData_0[12],
	&FIAAFUND_LIAB::mCFStaticData_0[13],
	&FIAAFUND_LIAB::mCFStaticData_0[14],
	&FIAAFUND_LIAB::mCFStaticData_0[15],
	&FIAAFUND_LIAB::mCFStaticData_0[16],
	&FIAAFUND_LIAB::mCFStaticData_0[17],
	&FIAAFUND_LIAB::mCFStaticData_0[18],
	&FIAAFUND_LIAB::mCFStaticData_0[19],
	&FIAAFUND_LIAB::mCFStaticData_0[20],
	&FIAAFUND_LIAB::mCFStaticData_0[21],
	&FIAAFUND_LIAB::mCFStaticData_0[22],
	&FIAAFUND_LIAB::mCFStaticData_0[23],
	&FIAAFUND_LIAB::mCFStaticData_0[24],
	&FIAAFUND_LIAB::mCFStaticData_0[25],
	&FIAAFUND_LIAB::mCFStaticData_0[26],
	&FIAAFUND_LIAB::mCFStaticData_0[27],
	&FIAAFUND_LIAB::mCFStaticData_0[28],
	&FIAAFUND_LIAB::mCFStaticData_0[29],
	&FIAAFUND_LIAB::mCFStaticData_0[30],
	&FIAAFUND_LIAB::mCFStaticData_0[31],
	&FIAAFUND_LIAB::mCFStaticData_0[32],
	&FIAAFUND_LIAB::mCFStaticData_0[33],
	&FIAAFUND_LIAB::mCFStaticData_0[34],
	&FIAAFUND_LIAB::mCFStaticData_0[35],
	&FIAAFUND_LIAB::mCFStaticData_0[36],
	&FIAAFUND_LIAB::mCFStaticData_0[37],
	&FIAAFUND_LIAB::mCFStaticData_0[38],
	&FIAAFUND_LIAB::mCFStaticData_0[39],
	&FIAAFUND_LIAB::mCFStaticData_0[40],
	&FIAAFUND_LIAB::mCFStaticData_0[41],
	&FIAAFUND_LIAB::mCFStaticData_0[42],
	&FIAAFUND_LIAB::mCFStaticData_0[43],
	&FIAAFUND_LIAB::mCFStaticData_0[44],
	&FIAAFUND_LIAB::mCFStaticData_0[45],
	&FIAAFUND_LIAB::mCFStaticData_0[46],
	&FIAAFUND_LIAB::mCFStaticData_0[47],
	&FIAAFUND_LIAB::mCFStaticData_0[48],
	&FIAAFUND_LIAB::mCFStaticData_0[49],
	&FIAAFUND_LIAB::mCFStaticData_0[50],
	&FIAAFUND_LIAB::mCFStaticData_0[51],
	&FIAAFUND_LIAB::mCFStaticData_0[52],
	&FIAAFUND_LIAB::mCFStaticData_0[53],
	&FIAAFUND_LIAB::mCFStaticData_0[54],
	&FIAAFUND_LIAB::mCFStaticData_0[55],
	&FIAAFUND_LIAB::mCFStaticData_0[56],
	&FIAAFUND_LIAB::mCFStaticData_0[57],
	&FIAAFUND_LIAB::mCFStaticData_0[58],
	&FIAAFUND_LIAB::mCFStaticData_0[59],
	&FIAAFUND_LIAB::mCFStaticData_0[60],
	&FIAAFUND_LIAB::mCFStaticData_0[61],
	&FIAAFUND_LIAB::mCFStaticData_0[62],
	&FIAAFUND_LIAB::mCFStaticData_0[63],
	&FIAAFUND_LIAB::mCFStaticData_0[64],
	&FIAAFUND_LIAB::mCFStaticData_0[65],
	&FIAAFUND_LIAB::mCFStaticData_0[66],
	&FIAAFUND_LIAB::mCFStaticData_0[67],
	&FIAAFUND_LIAB::mCFStaticData_0[68],
	&FIAAFUND_LIAB::mCFStaticData_0[69],
	&FIAAFUND_LIAB::mCFStaticData_0[70],
	&FIAAFUND_LIAB::mCFStaticData_0[71],
	&FIAAFUND_LIAB::mCFStaticData_0[72],
	&FIAAFUND_LIAB::mCFStaticData_0[73],
	&FIAAFUND_LIAB::mCFStaticData_0[74],
	&FIAAFUND_LIAB::mCFStaticData_0[75],
	&FIAAFUND_LIAB::mCFStaticData_0[76],
	&FIAAFUND_LIAB::mCFStaticData_0[77],
	&FIAAFUND_LIAB::mCFStaticData_0[78],
	&FIAAFUND_LIAB::mCFStaticData_0[79],
	&FIAAFUND_LIAB::mCFStaticData_0[80],
	&FIAAFUND_LIAB::mCFStaticData_0[81],
	&FIAAFUND_LIAB::mCFStaticData_0[82],
	&FIAAFUND_LIAB::mCFStaticData_0[83],
	&FIAAFUND_LIAB::mCFStaticData_0[84],
	&FIAAFUND_LIAB::mCFStaticData_0[85],
	&FIAAFUND_LIAB::mCFStaticData_0[86],
	&FIAAFUND_LIAB::mCFStaticData_0[87],
	&FIAAFUND_LIAB::mCFStaticData_0[88],
	&FIAAFUND_LIAB::mCFStaticData_0[89],
	&FIAAFUND_LIAB::mCFStaticData_0[90],
	&FIAAFUND_LIAB::mCFStaticData_0[91],
	&FIAAFUND_LIAB::mCFStaticData_0[92],
	&FIAAFUND_LIAB::mCFStaticData_0[93],
	&FIAAFUND_LIAB::mCFStaticData_0[94],
	&FIAAFUND_LIAB::mCFStaticData_0[95],
	&FIAAFUND_LIAB::mCFStaticData_0[96],
	&FIAAFUND_LIAB::mCFStaticData_0[97],
	&FIAAFUND_LIAB::mCFStaticData_0[98],
	&FIAAFUND_LIAB::mCFStaticData_0[99],
	&FIAAFUND_LIAB::mCFStaticData_0[100],
	&FIAAFUND_LIAB::mCFStaticData_0[101],
	&FIAAFUND_LIAB::mCFStaticData_0[102],
	&FIAAFUND_LIAB::mCFStaticData_0[103],
	&FIAAFUND_LIAB::mCFStaticData_0[104],
	&FIAAFUND_LIAB::mCFStaticData_0[105],
	&FIAAFUND_LIAB::mCFStaticData_0[106],
	&FIAAFUND_LIAB::mCFStaticData_0[107],
	&FIAAFUND_LIAB::mCFStaticData_0[108],
	&FIAAFUND_LIAB::mCFStaticData_0[109],
	&FIAAFUND_LIAB::mCFStaticData_0[110],
	&FIAAFUND_LIAB::mCFStaticData_0[111],
	&FIAAFUND_LIAB::mCFStaticData_0[112],
	&FIAAFUND_LIAB::mCFStaticData_0[113],
	&FIAAFUND_LIAB::mCFStaticData_0[114],
	&FIAAFUND_LIAB::mCFStaticData_0[115],
	&FIAAFUND_LIAB::mCFStaticData_0[116],
	&FIAAFUND_LIAB::mCFStaticData_0[117],
	&FIAAFUND_LIAB::mCFStaticData_0[118],
	&FIAAFUND_LIAB::mCFStaticData_0[119],
	&FIAAFUND_LIAB::mCFStaticData_0[120],
	&FIAAFUND_LIAB::mCFStaticData_0[121],
	&FIAAFUND_LIAB::mCFStaticData_0[122],
	&FIAAFUND_LIAB::mCFStaticData_0[123],
	&FIAAFUND_LIAB::mCFStaticData_0[124],
	&FIAAFUND_LIAB::mCFStaticData_0[125],
	&FIAAFUND_LIAB::mCFStaticData_0[126],
	&FIAAFUND_LIAB::mCFStaticData_0[127],
	&FIAAFUND_LIAB::mCFStaticData_0[128],
	&FIAAFUND_LIAB::mCFStaticData_0[129],
	&FIAAFUND_LIAB::mCFStaticData_0[130],
	&FIAAFUND_LIAB::mCFStaticData_0[131],
	&FIAAFUND_LIAB::mCFStaticData_0[132],
	&FIAAFUND_LIAB::mCFStaticData_0[133],
	&FIAAFUND_LIAB::mCFStaticData_0[134],
	&FIAAFUND_LIAB::mCFStaticData_0[135],
	&FIAAFUND_LIAB::mCFStaticData_0[136],
	&FIAAFUND_LIAB::mCFStaticData_0[137],
	&FIAAFUND_LIAB::mCFStaticData_0[138],
	&FIAAFUND_LIAB::mCFStaticData_0[139],
	&FIAAFUND_LIAB::mCFStaticData_0[140],
	&FIAAFUND_LIAB::mCFStaticData_0[141],
	&FIAAFUND_LIAB::mCFStaticData_0[142],
	&FIAAFUND_LIAB::mCFStaticData_0[143],
	&FIAAFUND_LIAB::mCFStaticData_0[144],
	&FIAAFUND_LIAB::mCFStaticData_0[145],
	&FIAAFUND_LIAB::mCFStaticData_0[146],
	&FIAAFUND_LIAB::mCFStaticData_0[147],
	&FIAAFUND_LIAB::mCFStaticData_0[148],
	&FIAAFUND_LIAB::mCFStaticData_0[149],
	&FIAAFUND_LIAB::mCFStaticData_0[150],
	&FIAAFUND_LIAB::mCFStaticData_0[151],
	&FIAAFUND_LIAB::mCFStaticData_0[152],
	&FIAAFUND_LIAB::mCFStaticData_0[153],
	&FIAAFUND_LIAB::mCFStaticData_0[154],
	&FIAAFUND_LIAB::mCFStaticData_0[155],
	&FIAAFUND_LIAB::mCFStaticData_0[156],
	&FIAAFUND_LIAB::mCFStaticData_0[157],
	&FIAAFUND_LIAB::mCFStaticData_0[158],
	&FIAAFUND_LIAB::mCFStaticData_0[159],
	&FIAAFUND_LIAB::mCFStaticData_0[160],
	&FIAAFUND_LIAB::mCFStaticData_0[161],
	&FIAAFUND_LIAB::mCFStaticData_0[162],
	&FIAAFUND_LIAB::mCFStaticData_0[163],
	&FIAAFUND_LIAB::mCFStaticData_0[164],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for crediting_dyn_lever                                                                                       
	const ChoicePair crediting_dyn_leverChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_DYNAMICS, "No Dynamics")
		,ChoicePair(StrEnum::DYNAMIC_CAP, "Dynamic Cap")
		,ChoicePair(StrEnum::DYNAMIC_PARTICIPATION, "Dynamic Participation")
		,ChoicePair(StrEnum::DYNAMIC_SPREAD, "Dynamic Spread")
		,ChoicePair(StrEnum::DYNAMIC_PARTICIPATION_AND_SPREAD, "Dynamic Participation and Spread")
		,ChoicePair(StrEnum::DYNAMIC_TRIGGER, "Dynamic Trigger")
		,ChoicePair(StrEnum::DYNAMIC_DUALDIR_CAP, "Dynamic DualDir Cap")
		,ChoicePair(StrEnum::DYNAMIC_SECURE_CAP, "Dynamic Secure Cap")
		,ChoicePair(StrEnum::DYNAMIC_BUFFER, "Dynamic Buffer")
		,ChoicePair(StrEnum::DYNAMIC_PAR_WITH_CAP, "Dynamic Par with Cap")
		,ChoicePair(StrEnum::DYNAMIC_DUALDIR_TRI, "Dynamic DualDir Tri")
		,ChoicePair(StrEnum::DYNAMIC_CAP_WITH_PAR, "Dynamic Cap with Par")
	};
	const EnumList crediting_dyn_leverEnumList(12, crediting_dyn_leverChoicePairs);

	// EnumList for crediting_rate_defn                                                                                       
	const ChoicePair crediting_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::POINT_TO_POINT, "Point to Point")
		,ChoicePair(StrEnum::MOVING_AVERAGE, "Moving Average")
		,ChoicePair(StrEnum::MONTHLY_SUM_CAP, "Monthly Sum Cap")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::POINT_TO_POINT_SPREAD, "Point to Point Spread")
	};
	const EnumList crediting_rate_defnEnumList(5, crediting_rate_defnChoicePairs);

	// EnumList for current_opt_defn_aig                                                                                       
	const ChoicePair current_opt_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "CALL")
		,ChoicePair(StrEnum::PUT, "PUT")
		,ChoicePair(StrEnum::RATCHET_PART, "RATCHET_PART")
		,ChoicePair(StrEnum::RATCHET_SPRD, "RATCHET_SPRD")
		,ChoicePair(StrEnum::NONE, "NONE")
		,ChoicePair(StrEnum::CALLK, "CALLK")
		,ChoicePair(StrEnum::PUTK, "PUTK")
		,ChoicePair(StrEnum::CSEC, "CSEC")
	};
	const EnumList current_opt_defn_aigEnumList(8, current_opt_defn_aigChoicePairs);

	// EnumList for display_solver_warnings_defn                                                                                       
	const ChoicePair display_solver_warnings_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList display_solver_warnings_defnEnumList(2, display_solver_warnings_defnChoicePairs);

	// EnumList for fund_type                                                                                       
	const ChoicePair fund_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED, "Fixed")
		,ChoicePair(StrEnum::INDEXED, "Indexed")
	};
	const EnumList fund_typeEnumList(2, fund_typeChoicePairs);

	// EnumList for hedge_defn                                                                                       
	const ChoicePair hedge_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList hedge_defnEnumList(2, hedge_defnChoicePairs);

	// EnumList for lookback_defn                                                                                       
	const ChoicePair lookback_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NONE, "None")
		,ChoicePair(StrEnum::ASIAN, "Asian")
		,ChoicePair(StrEnum::HIGHEST_GAIN, "Highest Gain")
	};
	const EnumList lookback_defnEnumList(3, lookback_defnChoicePairs);

	// EnumList for lookback_sampling_interval                                                                                       
	const ChoicePair lookback_sampling_intervalChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::SEMIANNUAL, "Semiannual")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList lookback_sampling_intervalEnumList(4, lookback_sampling_intervalChoicePairs);

	// EnumList for remove_par_sprd_min_max_aig                                                                                       
	const ChoicePair remove_par_sprd_min_max_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList remove_par_sprd_min_max_aigEnumList(2, remove_par_sprd_min_max_aigChoicePairs);

	// EnumList for use_option_cost_tables_defn_aig                                                                                       
	const ChoicePair use_option_cost_tables_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "YES")
		,ChoicePair(StrEnum::NO, "NO")
	};
	const EnumList use_option_cost_tables_defn_aigEnumList(2, use_option_cost_tables_defn_aigChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace FIAAFUND_LIAB_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(FIAAFUND_LIAB::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(FIAAFUND_LIAB::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace FIAAFUND_LIAB_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void FIAAFUND_LIAB::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> FIAAFUND_LIAB::mgr_;

	Attribute::Descriptor FIAAFUND_LIAB::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"cap_rate_dualdir_tricap_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cap_rate_dualdir_tricap_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::DOUBLE,	"crediting_cap_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_cap_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"crediting_cap_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_cap_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STR_ENUM,	"crediting_dyn_lever", -1, (size_t)&modelOffset->crediting_dyn_lever,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &crediting_dyn_leverEnumList, Feature(true)),
	Descriptor(4, Attribute::STRING,	"crediting_eqt_index", -1, (size_t)&modelOffset->crediting_eqt_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"crediting_eqt_vol_misc_rate_aig", -1, (size_t)&modelOffset->crediting_eqt_vol_misc_rate_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"crediting_mths", -1, (size_t)&modelOffset->crediting_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"crediting_part_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_part_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"crediting_rate_defn", -1, (size_t)&modelOffset->crediting_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &crediting_rate_defnEnumList, Feature(true)),
	Descriptor(9, Attribute::INT,	"crediting_rate_guar_mths", -1, (size_t)&modelOffset->crediting_rate_guar_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"crediting_rt_chg_threshold_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_rt_chg_threshold_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STR_ENUM,	"current_opt_defn_aig", -1, (size_t)&modelOffset->current_opt_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &current_opt_defn_aigEnumList, Feature(true)),
	Descriptor(12, Attribute::STR_ENUM,	"display_solver_warnings_defn", -1, (size_t)&modelOffset->display_solver_warnings_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &display_solver_warnings_defnEnumList, Feature(false)),
	Descriptor(13, Attribute::DOUBLE,	"eprs_add_par_rate_threshold_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_add_par_rate_threshold_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"eprs_add_part_rate_min_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_add_part_rate_min_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::DOUBLE,	"eprs_cost_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_cost_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::INT,	"eprs_cost_level_aig", -1, (size_t)&modelOffset->eprs_cost_level_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"eprs_hedge_min_par_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_hedge_min_par_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::DOUBLE,	"eprs_index_term_part_rate_max_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_index_term_part_rate_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"eprs_par_rate_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_par_rate_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"eprs_rounding_multiple_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_rounding_multiple_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::STRING,	"fund_id", -1, (size_t)&modelOffset->fund_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"fund_type", -1, (size_t)&modelOffset->fund_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fund_typeEnumList, Feature(true)),
	Descriptor(23, Attribute::DOUBLE,	"fund_val_split_prop", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fund_val_split_prop,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STR_ENUM,	"hedge_defn", -1, (size_t)&modelOffset->hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_defnEnumList, Feature(true)),
	Descriptor(25, Attribute::STRING,	"hedge_grp_code", -1, (size_t)&modelOffset->hedge_grp_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"hedge_option_val_alpha_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->hedge_option_val_alpha_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::DOUBLE,	"index_term_cap_rate_max_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_cap_rate_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::DOUBLE,	"index_term_cap_rate_min_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_cap_rate_min_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::STRING,	"index_term_cap_rate_min_table_aig", -1, (size_t)&modelOffset->index_term_cap_rate_min_table_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::INT,	"index_term_duration_aig", -1, (size_t)&modelOffset->index_term_duration_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::DOUBLE,	"index_term_floor_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_floor_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::DOUBLE,	"index_term_part_rate_max_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_part_rate_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::DOUBLE,	"index_term_part_rate_min_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_part_rate_min_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::DOUBLE,	"index_term_sprd_rate_max_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_sprd_rate_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::DOUBLE,	"index_term_sprd_rate_min_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_sprd_rate_min_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::DOUBLE,	"index_term_trigger_rate_max_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_trigger_rate_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::DOUBLE,	"index_term_trigger_rate_min_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_term_trigger_rate_min_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"init_fia_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fia_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::DOUBLE,	"init_fund_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"init_part_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"init_spread_rate_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_spread_rate_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::DOUBLE,	"init_trigger_rate_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_trigger_rate_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::INT,	"inverse_gamma_param_t_aig", -1, (size_t)&modelOffset->inverse_gamma_param_t_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::DOUBLE,	"knockout_buffer_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->knockout_buffer_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::DOUBLE,	"knockout_realloc_yr_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->knockout_realloc_yr_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::DOUBLE,	"knockout_rebate_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->knockout_rebate_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::DOUBLE,	"knockout_rebate_opt_bdgt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->knockout_rebate_opt_bdgt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::DOUBLE,	"knockout_threshold_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->knockout_threshold_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::STR_ENUM,	"lookback_defn", -1, (size_t)&modelOffset->lookback_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_defnEnumList, Feature(true)),
	Descriptor(50, Attribute::STR_ENUM,	"lookback_sampling_interval", -1, (size_t)&modelOffset->lookback_sampling_interval,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_sampling_intervalEnumList, Feature(true)),
	Descriptor(51, Attribute::DOUBLE,	"max_annual_rate_chg_down_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->max_annual_rate_chg_down_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::DOUBLE,	"max_annual_rate_chg_up_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->max_annual_rate_chg_up_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::DOUBLE,	"max_sc_rate_decrease_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->max_sc_rate_decrease_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::DOUBLE,	"par_rate_combo_strat_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->par_rate_combo_strat_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::INT,	"part_rate_solve_max_iter_aig", -1, (size_t)&modelOffset->part_rate_solve_max_iter_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::DOUBLE,	"part_rate_solve_tolerance_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->part_rate_solve_tolerance_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::DOUBLE,	"pct_to_hedge", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pct_to_hedge,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::DOUBLE,	"perf_lock_auto_lock_election_rt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_auto_lock_election_rt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::DOUBLE,	"perf_lock_fixed_rt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_fixed_rt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::DOUBLE,	"perf_lock_gamma_param_alpha_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_gamma_param_alpha_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::DOUBLE,	"perf_lock_gamma_param_beta_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_gamma_param_beta_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::DOUBLE,	"perf_lock_max_val_rt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_max_val_rt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::DOUBLE,	"perf_lock_non_util_rt_multi_yr_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_non_util_rt_multi_yr_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(64, Attribute::DOUBLE,	"perf_lock_non_util_rt_one_yr_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_non_util_rt_one_yr_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::DOUBLE,	"perf_lock_suff_val_rt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->perf_lock_suff_val_rt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::STR_ENUM,	"remove_par_sprd_min_max_aig", -1, (size_t)&modelOffset->remove_par_sprd_min_max_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &remove_par_sprd_min_max_aigEnumList, Feature(true)),
	Descriptor(67, Attribute::DOUBLE,	"renewal_beta_down_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_beta_down_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(68, Attribute::DOUBLE,	"renewal_beta_up_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_beta_up_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(69, Attribute::DOUBLE,	"renewal_budget_reduction_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_budget_reduction_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(70, Attribute::DOUBLE,	"renewal_glb_beta_down_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_glb_beta_down_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(71, Attribute::DOUBLE,	"renewal_glb_beta_up_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_glb_beta_up_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(72, Attribute::DOUBLE,	"renewal_migration_beg_yr_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_migration_beg_yr_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::DOUBLE,	"renewal_pri_sprd_tgt_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_pri_sprd_tgt_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(74, Attribute::DOUBLE,	"renewal_surr_chg_offest_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_surr_chg_offest_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::DOUBLE,	"rila_opt_inefficiency", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rila_opt_inefficiency,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::INT,	"strategy_term_duration_aig", -1, (size_t)&modelOffset->strategy_term_duration_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::DOUBLE,	"strategy_term_floor_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->strategy_term_floor_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::DOUBLE,	"trigger_strat_min_index_chg_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->trigger_strat_min_index_chg_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::STR_ENUM,	"use_option_cost_tables_defn_aig", -1, (size_t)&modelOffset->use_option_cost_tables_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_option_cost_tables_defn_aigEnumList, Feature(true)),
	Descriptor(80, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(81, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_commencement_period)),
	Descriptor(82, Attribute::SCALAR_INT,	"elapsed_mths", -1, (size_t)&modelOffset->elapsed_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_elapsed_mths)),
	Descriptor(83, Attribute::SCALAR_DOUBLE,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIAAFUND_LIAB_UDF::fiaafund_liab_final_period)),
	Descriptor(84, Attribute::SCALAR_INT,	"lookback_mths", -1, (size_t)&modelOffset->lookback_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_mths)),
	Descriptor(85, Attribute::SCALAR_INT,	"lookback_sampling_mths", -1, (size_t)&modelOffset->lookback_sampling_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_sampling_mths)),
	Descriptor(86, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_maturity_period)),
	Descriptor(87, Attribute::SCALAR_INT,	"opt_budget_grading_period_aig", -1, (size_t)&modelOffset->opt_budget_grading_period_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_grading_period_aig)),
	};

	Attribute::Descriptor* FIAAFUND_LIAB::descriptorTable[] = {
	&FIAAFUND_LIAB::descriptor_0[0],
	&FIAAFUND_LIAB::descriptor_0[1],
	&FIAAFUND_LIAB::descriptor_0[2],
	&FIAAFUND_LIAB::descriptor_0[3],
	&FIAAFUND_LIAB::descriptor_0[4],
	&FIAAFUND_LIAB::descriptor_0[5],
	&FIAAFUND_LIAB::descriptor_0[6],
	&FIAAFUND_LIAB::descriptor_0[7],
	&FIAAFUND_LIAB::descriptor_0[8],
	&FIAAFUND_LIAB::descriptor_0[9],
	&FIAAFUND_LIAB::descriptor_0[10],
	&FIAAFUND_LIAB::descriptor_0[11],
	&FIAAFUND_LIAB::descriptor_0[12],
	&FIAAFUND_LIAB::descriptor_0[13],
	&FIAAFUND_LIAB::descriptor_0[14],
	&FIAAFUND_LIAB::descriptor_0[15],
	&FIAAFUND_LIAB::descriptor_0[16],
	&FIAAFUND_LIAB::descriptor_0[17],
	&FIAAFUND_LIAB::descriptor_0[18],
	&FIAAFUND_LIAB::descriptor_0[19],
	&FIAAFUND_LIAB::descriptor_0[20],
	&FIAAFUND_LIAB::descriptor_0[21],
	&FIAAFUND_LIAB::descriptor_0[22],
	&FIAAFUND_LIAB::descriptor_0[23],
	&FIAAFUND_LIAB::descriptor_0[24],
	&FIAAFUND_LIAB::descriptor_0[25],
	&FIAAFUND_LIAB::descriptor_0[26],
	&FIAAFUND_LIAB::descriptor_0[27],
	&FIAAFUND_LIAB::descriptor_0[28],
	&FIAAFUND_LIAB::descriptor_0[29],
	&FIAAFUND_LIAB::descriptor_0[30],
	&FIAAFUND_LIAB::descriptor_0[31],
	&FIAAFUND_LIAB::descriptor_0[32],
	&FIAAFUND_LIAB::descriptor_0[33],
	&FIAAFUND_LIAB::descriptor_0[34],
	&FIAAFUND_LIAB::descriptor_0[35],
	&FIAAFUND_LIAB::descriptor_0[36],
	&FIAAFUND_LIAB::descriptor_0[37],
	&FIAAFUND_LIAB::descriptor_0[38],
	&FIAAFUND_LIAB::descriptor_0[39],
	&FIAAFUND_LIAB::descriptor_0[40],
	&FIAAFUND_LIAB::descriptor_0[41],
	&FIAAFUND_LIAB::descriptor_0[42],
	&FIAAFUND_LIAB::descriptor_0[43],
	&FIAAFUND_LIAB::descriptor_0[44],
	&FIAAFUND_LIAB::descriptor_0[45],
	&FIAAFUND_LIAB::descriptor_0[46],
	&FIAAFUND_LIAB::descriptor_0[47],
	&FIAAFUND_LIAB::descriptor_0[48],
	&FIAAFUND_LIAB::descriptor_0[49],
	&FIAAFUND_LIAB::descriptor_0[50],
	&FIAAFUND_LIAB::descriptor_0[51],
	&FIAAFUND_LIAB::descriptor_0[52],
	&FIAAFUND_LIAB::descriptor_0[53],
	&FIAAFUND_LIAB::descriptor_0[54],
	&FIAAFUND_LIAB::descriptor_0[55],
	&FIAAFUND_LIAB::descriptor_0[56],
	&FIAAFUND_LIAB::descriptor_0[57],
	&FIAAFUND_LIAB::descriptor_0[58],
	&FIAAFUND_LIAB::descriptor_0[59],
	&FIAAFUND_LIAB::descriptor_0[60],
	&FIAAFUND_LIAB::descriptor_0[61],
	&FIAAFUND_LIAB::descriptor_0[62],
	&FIAAFUND_LIAB::descriptor_0[63],
	&FIAAFUND_LIAB::descriptor_0[64],
	&FIAAFUND_LIAB::descriptor_0[65],
	&FIAAFUND_LIAB::descriptor_0[66],
	&FIAAFUND_LIAB::descriptor_0[67],
	&FIAAFUND_LIAB::descriptor_0[68],
	&FIAAFUND_LIAB::descriptor_0[69],
	&FIAAFUND_LIAB::descriptor_0[70],
	&FIAAFUND_LIAB::descriptor_0[71],
	&FIAAFUND_LIAB::descriptor_0[72],
	&FIAAFUND_LIAB::descriptor_0[73],
	&FIAAFUND_LIAB::descriptor_0[74],
	&FIAAFUND_LIAB::descriptor_0[75],
	&FIAAFUND_LIAB::descriptor_0[76],
	&FIAAFUND_LIAB::descriptor_0[77],
	&FIAAFUND_LIAB::descriptor_0[78],
	&FIAAFUND_LIAB::descriptor_0[79],
	&FIAAFUND_LIAB::descriptor_0[80],
	&FIAAFUND_LIAB::descriptor_0[81],
	&FIAAFUND_LIAB::descriptor_0[82],
	&FIAAFUND_LIAB::descriptor_0[83],
	&FIAAFUND_LIAB::descriptor_0[84],
	&FIAAFUND_LIAB::descriptor_0[85],
	&FIAAFUND_LIAB::descriptor_0[86],
	&FIAAFUND_LIAB::descriptor_0[87],
	nullptr};
	const size_t FIAAFUND_LIAB::sDescriptorCount = 88;

//factory
FIAAFUND_LIAB* FIAAFUND_LIAB::makeThis(int isSubmodel, ModelClass* owner, FIAAFUND_LIAB* peer, 
						int mainRebase, const xstring &name, FIAAFUND_LIAB_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIAAFUND_LIAB::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIAAFUND_LIAB");
#endif
	FIAAFUND_LIAB* newP = (FIAAFUND_LIAB*)new FIAAFUND_LIAB_UDF
   	  ("fiaafund_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
FIAAFUND_LIAB_persistent_object* FIAAFUND_LIAB_persistent_object::makeThis(int isSubmodel, ModelClass* owner, FIAAFUND_LIAB* peer, 
							int mainRebase, const xstring &name, FIAAFUND_LIAB_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIAAFUND_LIAB_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIAAFUND_LIAB_persistent_object");
#endif
	FIAAFUND_LIAB_persistent_object* newP = (FIAAFUND_LIAB_persistent_object*)new FIAAFUND_LIAB_persistent_object
   	  ("fiaafund_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			FIAAFUND_LIAB_persistent_object* pd = dynamic_cast<FIAAFUND_LIAB_persistent_object*>(product);
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

typedef double (FIAAFUND_LIAB_UDF::*dPF) ();
typedef double (FIAAFUND_LIAB_UDF::*dPFd) (double);
typedef int (FIAAFUND_LIAB_UDF::*iPF) ();
typedef int (FIAAFUND_LIAB_UDF::*iPFi) (int);
typedef xstring (FIAAFUND_LIAB_UDF::*sPF) ();
typedef xstring (FIAAFUND_LIAB_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
FIAAFUND_LIAB::FIAAFUND_LIAB(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, intex(company_asset_intex)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (FIAAFUND_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
FIAAFUND_LIAB::FIAAFUND_LIAB(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(164, FIAAFUND_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, intex(company_asset_intex)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_is(company_asset_mtg_mtg_cf_mtg_is)
	, mtg_pv(company_asset_mtg_mtg_cf_mtg_pv)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
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
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
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
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
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

	for (int cf_no = 1; cf_no <= 164; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (FIAAFUND_LIAB_UDF::*dPXi2) (int, int);
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


 void FIAAFUND_LIAB::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
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
#ifdef __CREATE_LIAB_LIAB_CLASS_
		company_liab = (LIAB_LIAB*)(findUnique("company|liab"));
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
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
 }
//copy_names END@2


 void FIAAFUND_LIAB::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int FIAAFUND_LIAB_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& FIAAFUND_LIAB_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double FIAAFUND_LIAB_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int FIAAFUND_LIAB_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double FIAAFUND_LIAB_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double FIAAFUND_LIAB_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void FIAAFUND_LIAB_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIAAFUND_LIAB_persistent_object::write(long include_submodels) {
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

	void FIAAFUND_LIAB_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIAAFUND_LIAB_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIAAFUND_LIAB_persistent_object::write(const xstring& key, long include_submodels) {
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




	FIAAFUND_LIAB_persistent_object::~FIAAFUND_LIAB_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool FIAAFUND_LIAB_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void FIAAFUND_LIAB_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void FIAAFUND_LIAB_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void FIAAFUND_LIAB_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIAAFUND_LIAB_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIAAFUND_LIAB_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* FIAAFUND_LIAB_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* FIAAFUND_LIAB_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* FIAAFUND_LIAB_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char FIAAFUND_LIAB_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void FIAAFUND_LIAB_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
FIAAFUND_LIAB_persistent_object::FIAAFUND_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			FIAAFUND_LIAB(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(FIAAFUND_LIAB::sm_bond_is)
	, sm_bond_pv(FIAAFUND_LIAB::sm_bond_pv)
	, sm_bond_ym(FIAAFUND_LIAB::sm_bond_ym)
	, sm_mtg_is(FIAAFUND_LIAB::sm_mtg_is)
	, sm_mtg_pv(FIAAFUND_LIAB::sm_mtg_pv)
	, sm_mtg_ym(FIAAFUND_LIAB::sm_mtg_ym)

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
FIAAFUND_LIAB::~FIAAFUND_LIAB() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void FIAAFUND_LIAB::findTargetColumns() {

}
//findTargetColumns END@2
void FIAAFUND_LIAB::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void FIAAFUND_LIAB::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void FIAAFUND_LIAB::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void FIAAFUND_LIAB::start_of_projection() {
}
//start_of_projection END@2

void FIAAFUND_LIAB::end_of_projection() {
}
//end_of_projection END@2

void FIAAFUND_LIAB::start_of_layer() {
}


void FIAAFUND_LIAB::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void FIAAFUND_LIAB::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void FIAAFUND_LIAB::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void FIAAFUND_LIAB::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> FIAAFUND_LIAB::ddfVector;
BitArray FIAAFUND_LIAB::dataVariables(88);
bool FIAAFUND_LIAB::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool FIAAFUND_LIAB::writeClassInfo = true;

void FIAAFUND_LIAB::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, FIAAFUND_LIAB::descriptor_0>::dT = FIAAFUND_LIAB::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, FIAAFUND_LIAB::descriptor_0>::dT = FIAAFUND_LIAB::descriptor_0;

