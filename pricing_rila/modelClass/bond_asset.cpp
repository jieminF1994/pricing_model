
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
#include "ModelClass\bond_asset_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_aig.h"
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

int num_bonds_to_run;
int num_bond = 0;
sowfinput bond_mp_input;
sowfcols bond_mp_input_cols;
sowfinput bond_sch_input;
sowfcols bond_sch_input_cols;
sowfoutput bond_sch_output;
sowfmap bond_sch_input_pos;
sowfmapiter bond_sch_input_pos_iter;
sowfmap bond_sch_input_size;
sowfmapiter bond_sch_input_size_iter;

extern sowmpoutput bond_state_of_world_mp_output;

static bondivmap bond_initial_values_map;
static bondivmap::iterator bond_initial_values_map_iter;
static int num_of_amortize_cost_selections = 5;

extern bool is_asset_initialize;

extern SmartArray <double>& stoch_credit_sprd_tbl;
extern SmartArray <double>& shifted_stoch_credit_sprd_tbl;

// Present value calculation variables
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern int pv_months;
extern int pv_last_cash_flow_month;
extern int pv_asset_defn;
extern int pv_model_point;
extern double pv_initial_years_to_payment;
extern double pv_initial_accrued_interest;
extern double pv_initial_par_value;
extern double pv_interest_savings_monthly_refinancing_rate;
extern bool pv_initialize_interest_savings_table;
extern bool pv_initialize_yield_maintenance_table;
extern SmartArray <double>& pv_cash_flows;
extern SmartArray <double>& pv_interest_savings_after_prepayments;
extern SmartArray <double>& pv_yield_maintenance_cash_flows;
extern SmartArray <double>& pv_yield_maintenance_par_plus_accrued;

// Bond option pricing tables and other bond tables
extern SmartArray <double>& pv_accumulated_cash_flows; 
extern SmartArray <double>& pv_discount_factors;
extern SmartArray <double>& pv_discounted_cash_flows;
extern SmartArray <double>& pv_time_weighted_discounted_cash_flows;
extern SmartArray <double>& pv_call_amount;
extern SmartArray <double>& pv_put_amount;
extern SmartArray <double>& pv_scheduled_principal_payments; // for WAL calculation

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

extern int maximum_t_high_value;
extern int minimum_t_low_value;

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
#ifndef bond_asset_TableDefs
#define bond_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection BOND_ASSET::TTHC;
void BOND_ASSET::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_bond_cf)
		sm_bond_cf = 0;

}		

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double accr_inc_bef_sched_pmt
= cost_basis_bef_call(t)
  + accr_int_bef_call(t)
  - cost_basis_aft_dflt(t)
  - accr_int_aft_dflt(t)
  + int_pmt(t)
  + cost_basis_sched_prin_pmt(t);

if (cost_basis_bef_sale(t) == 0.0) // Adjust Accrued if cost set to zero
	return accr_inc_bef_sched_pmt
		   - (cost_basis_aft_put(t)
			  + accr_int_aft_put(t)
			  - accr_int_bef_sale(t));

double accr_inc_aft_puts = 0;

if (t > commencement_period)
	accr_inc_aft_puts
	= cost_basis_bef_sale(t) 
	  + accr_int_bef_sale(t)
	  - cost_basis_aft_put(t)
	  - accr_int_aft_put(t);

return accr_inc_bef_sched_pmt
	   + accr_inc_aft_puts;

}


//@@ END

//@@ START - accr_int
// Accrued Interest                                                                                             
// Column:ACCR_INT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_int",t);
}



//^^^

#line 1 "accr_int.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Defaults                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"accr_int_aft_dflt",t);
}



//^^^

#line 1 "accr_int_aft_dflt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

//force call
accr_int_dflt(t);

return bond_cf->accr_int_aft_dflt(t);

}


//@@ END

//@@ START - accr_int_aft_put
// Accrued Interest After Puts                                                                                             
// Column:ACCR_INT_AFT_PUT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_aft_put(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"accr_int_aft_put",t);
}



//^^^

#line 1 "accr_int_aft_put.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->accr_int_aft_put(t);

}


//@@ END

//@@ START - accr_int_bef_call
// Accrued Interest Before Call                                                                                             
// Column:ACCR_INT_BEF_CALL
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_bef_call(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"accr_int_bef_call",t);
}



//^^^

#line 1 "accr_int_bef_call.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->accr_int_bef_call(t);

}


//@@ END

//@@ START - accr_int_bef_fund_match_sale
// Accrued Interest Before Fund Value Matching Asset Sales                                                                                             
// Column:ACCR_INT_BEF_FUND_MATCH_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"accr_int_bef_fund_match_sale",t);
}



//^^^

#line 1 "accr_int_bef_fund_match_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - accr_int_bef_neg_cash_flow_sale
// Accrued Interest Before Negative Cash Flow Sales                                                                                             
// Column:ACCR_INT_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"accr_int_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "accr_int_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - accr_int_bef_rebal_sale
// Accrued Interest Before Rebalancing Sales                                                                                             
// Column:ACCR_INT_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"accr_int_bef_rebal_sale",t);
}



//^^^

#line 1 "accr_int_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - accr_int_bef_sale
// Accrued Interest Before Sales                                                                                             
// Column:ACCR_INT_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_bef_sale(int t) {
//^^^



//^^^

#line 1 "accr_int_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bond_cf->accr_int_bef_sale(t);

}


//@@ END

//@@ START - accr_int_dflt
// Accrued Interest Defaults                                                                                             
// Column:ACCR_INT_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"accr_int_dflt",t);
}



//^^^

#line 1 "accr_int_dflt.BOND_ASSET.for"
if (t <= 0)
	return NO_AVG;

return dflt_amt(t)
    - cost_basis_dflt(t);

}


//@@ END

//@@ START - accr_int_purch
// Accrued Interest Purchase                                                                                             
// Column:ACCR_INT_PURCH
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"accr_int_purch",t);
}



//^^^

#line 1 "accr_int_purch.BOND_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (t == commencement_period)
	return accr_int(t);

return NO_AVG;

}


//@@ END

//@@ START - accr_int_rent
// Accrued Interest Rent                                                                                             
// Column:ACCR_INT_RENT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_rent(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"accr_int_rent",t);
}



//^^^

#line 1 "accr_int_rent.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int(t);

}


//@@ END

//@@ START - accr_int_sold
// Accrued Interest Sold                                                                                             
// Column:ACCR_INT_SOLD
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"accr_int_sold",t);
}



//^^^

#line 1 "accr_int_sold.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return accr_int_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - asset_detail_rpt_pv_flag
// Asset Detail Report Present Value Flag                                                                                             
// Column:ASSET_DETAIL_RPT_PV_FLAG
//========================================================
double BOND_ASSET_UDF::bond_asset_asset_detail_rpt_pv_flag(int t) {
//^^^



//^^^

#line 1 "asset_detail_rpt_pv_flag.BOND_ASSET.for"
if (asset_detail_rpt_pv_defn == NO 
	|| asset_detail_rpt_flag == NO)
	return 0.0;

if (t >= asset_detail_rpt_start_period
	&& t <= asset_detail_rpt_final_period)
	return 1;

return 0;

}


//@@ END

//@@ START - asset_min_size_sale_flag
// Asset Minimum Size Sale Flag                                                                                             
// Column:ASSET_MIN_SIZE_SALE_FLAG
//========================================================
double BOND_ASSET_UDF::bond_asset_asset_min_size_sale_flag(int t) {
//^^^



//^^^

#line 1 "asset_min_size_sale_flag.BOND_ASSET.for"
if (t <= commencement_period || t >= maturity_period || isMainModel)
	return NO_AVG;

if (bond_cf->par_val_bef_sale(t) == 0.0)
	return NO_AVG;

if ((company->sm_inv_strategy[seg_num]->mths_to_rebal(t) == 0
	 || asset->mths_to_asset_sale(t) == 0)
	&& (fabs(bk_val_bef_sale(t) * pct_to_use) > 0.0)
	&& (fabs(bk_val_bef_sale(t) * pct_to_use)
		 < asset->sm_asset_sub_port[seg_num][xint(sub_port_id(t))][0]->min_size_existing))
	// do not change order of && statements
	return 1;

return 0.0;

}


//@@ END

//@@ START - avr_basic_contribn
// AVR Basic Contribution                                                                                             
// Column:AVR_BASIC_CONTRIBN
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_basic_contribn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"avr_basic_contribn",t);
}



//^^^

#line 1 "avr_basic_contribn.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return avr_basic_contribn_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_basic_contribn_bef_sale
// AVR Basic Contribution Before Sales                                                                                             
// Column:AVR_BASIC_CONTRIBN_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_basic_contribn_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"avr_basic_contribn_bef_sale",t);
}



//^^^

#line 1 "avr_basic_contribn_bef_sale.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_contribn_pct;

}


//@@ END

//@@ START - avr_max
// AVR Maximum                                                                                             
// Column:AVR_MAX
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_max(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"avr_max",t);
}



//^^^

#line 1 "avr_max.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return avr_max_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_max_bef_sale
// AVR Maximum Before Sales                                                                                             
// Column:AVR_MAX_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_max_bef_sale(int t) {
//^^^



//^^^

#line 1 "avr_max_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_max_pct;

}


//@@ END

//@@ START - avr_obj
// AVR Objective                                                                                             
// Column:AVR_OBJ
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_obj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"avr_obj",t);
}



//^^^

#line 1 "avr_obj.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return avr_obj_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_obj_bef_sale
// AVR Objective Before Sales                                                                                             
// Column:AVR_OBJ_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_obj_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"avr_obj_bef_sale",t);
}



//^^^

#line 1 "avr_obj_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_obj_pct;

}


//@@ END

//@@ START - avr_realzd_cap_gain
// AVR Realized Capital Gain                                                                                             
// Column:AVR_REALZD_CAP_GAIN
//========================================================
double BOND_ASSET_UDF::bond_asset_avr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"avr_realzd_cap_gain",t);
}



//^^^

#line 1 "avr_realzd_cap_gain.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return - dflt_amt(t);

}


//@@ END

//@@ START - base_inc_bef_call
// Base Income Before Call                                                                                             
// Column:BASE_INC_BEF_CALL
//========================================================
double BOND_ASSET_UDF::bond_asset_base_inc_bef_call(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"base_inc_bef_call",t);
}



//^^^

#line 1 "base_inc_bef_call.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn == AMORTIZED_COST)
	return (cost_basis_aft_dflt(t)
			+ accr_int_aft_dflt(t))
		   * net_yld(t - 1) / 12.0;

return 0.0;

}


//@@ END

//@@ START - bk_val
// Book Value                                                                                             
// Column:BK_VAL
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"bk_val",t);
}



//^^^

#line 1 "bk_val.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period) 
        return NO_AVG;   

return bk_val_bef_neg_cash_flow_sale(t) 
           * (1.0 - sold_pct_neg_cash_flow(t));



}


//@@ END

//@@ START - bk_val_aft_dflt
// Book Value After Defaults                                                                                             
// Column:BK_VAL_AFT_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"bk_val_aft_dflt",t);
}



//^^^

#line 1 "bk_val_aft_dflt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val(t - 1)
	   * sm_bond_cf->remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - bk_val_aft_put
// Book Value After Puts                                                                                             
// Column:BK_VAL_AFT_PUT
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_aft_put(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"bk_val_aft_put",t);
}



//^^^

#line 1 "bk_val_aft_put.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_call(t)) < model_point_amount_threshold)
	return NO_AVG;

return bk_val_bef_call(t)
	   * (1.0 - bond_cf->call_pct_mthly(t))
	   * (1.0 - bond_cf->put_pct_mthly(t));

}


//@@ END

//@@ START - bk_val_bef_call
// Book Value Before Call                                                                                             
// Column:BK_VAL_BEF_CALL
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_bef_call(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"bk_val_bef_call",t);
}



//^^^

#line 1 "bk_val_bef_call.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_call(t);

return NO_AVG;

}


//@@ END

//@@ START - bk_val_bef_fund_match_sale
// Book Value Before Fund Value Matching Asset Sales                                                                                             
// Column:BK_VAL_BEF_FUND_MATCH_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"bk_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "bk_val_bef_fund_match_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - bk_val_bef_neg_cash_flow_sale
// Book Value Before Negative Cash Flow Sales                                                                                             
// Column:BK_VAL_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"bk_val_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "bk_val_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - bk_val_bef_rebal_sale
// Book Value Before Rebalancingt Sales                                                                                             
// Column:BK_VAL_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"bk_val_bef_rebal_sale",t);
}



//^^^

#line 1 "bk_val_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - bk_val_bef_sale
// Book Value Before Sales                                                                                             
// Column:BK_VAL_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator)
	{
	double local_book_value = init_bk_val * neg_asset_flag;

	//Perform accounting data consistency checks for book value
	if (bk_val_defn == COST_BASIS
		&& fabs(local_book_value - cost_basis_bef_sale(t)) > 0.5)
		return cost_basis_bef_sale(t);

	return local_book_value;
	}

if (!existing_asset_indicator && t == commencement_period)
	return mkt_val_bef_sale(t);

if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_sale(t);

return NO_AVG;

}


//@@ END

//@@ START - bk_val_plus_accr_int_bef_rebal_sale
// Book Value Plus Accrued Interest Before Rebalancing Sales                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_plus_accr_int_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int_bef_rebal_sale.BOND_ASSET.for"
// these bk_val_plus_accr_int... columns are used in sum_over_assets
//	to accumulate values for sales and rebalancing processing

if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale (t)
	   + accr_int_bef_rebal_sale (t);

}


//@@ END

//@@ START - bk_val_purch
// Book Value Purchase                                                                                             
// Column:BK_VAL_PURCH
//========================================================
double BOND_ASSET_UDF::bond_asset_bk_val_purch(int t) {
//^^^



//^^^

#line 1 "bk_val_purch.BOND_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (t == commencement_period)
	return bk_val(t);

return NO_AVG;

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double BOND_ASSET_UDF::bond_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.BOND_ASSET.for"
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
double BOND_ASSET_UDF::bond_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.BOND_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double BOND_ASSET_UDF::bond_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.BOND_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"cap_gain_bef_sale",t);
}



//^^^

#line 1 "cap_gain_bef_sale.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain(t)
	   + unrealzd_cap_gain_incr(t);

}


//@@ END

//@@ START - cap_gain_from_sale
// Capital Gains from Sales                                                                                             
// Column:CAP_GAIN_FROM_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"cap_gain_from_sale",t);
}



//^^^

#line 1 "cap_gain_from_sale.BOND_ASSET.for"
if (t < commencement_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return (mkt_val_bef_sale(t)
		- bk_val_bef_sale(t))
	   * sold_pct(t);

}


//@@ END

//@@ START - cash_flow
// Cash Flow                                                                                             
// Column:CASH_FLOW
//========================================================
double BOND_ASSET_UDF::bond_asset_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"cash_flow",t);
}



//^^^

#line 1 "cash_flow.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->sched_prin_pmt(t)
	   + bond_cf->int_pmt(t)
	   + bond_cf->sinking_fund_pmt_inc(t)
	   + opt_pmt(t)
	   + opt_inc(t);

}


//@@ END

//@@ START - cost_basis
// Cost Basis                                                                                             
// Column:COST_BASIS
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"cost_basis",t);
}



//^^^

#line 1 "cost_basis.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return cost_basis_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - cost_basis_accrual
// Cost Basis Accrual                                                                                             
// Column:COST_BASIS_ACCRUAL
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_accrual(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"cost_basis_accrual",t);
}



//^^^

#line 1 "cost_basis_accrual.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_call(t)
	   - cost_basis_aft_dflt(t)
	   + cost_basis_sched_prin_pmt(t)
	   + cost_basis_bef_sale(t)
	   - cost_basis_aft_put(t);

}


//@@ END

//@@ START - cost_basis_aft_dflt
// Cost Basis After Defaults                                                                                             
// Column:COST_BASIS_AFT_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"cost_basis_aft_dflt",t);
}



//^^^

#line 1 "cost_basis_aft_dflt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis(t - 1) * bond_cf->remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - cost_basis_aft_put
// Cost Basis After Puts                                                                                             
// Column:COST_BASIS_AFT_PUT
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_aft_put(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"cost_basis_aft_put",t);
}



//^^^

#line 1 "cost_basis_aft_put.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_call(t)
	   * (1.0 - bond_cf->call_pct_mthly(t))
	   * (1.0 - bond_cf->put_pct_mthly(t));

}


//@@ END

//@@ START - cost_basis_bef_call
// Cost Basis Before Call                                                                                             
// Column:COST_BASIS_BEF_CALL
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_bef_call(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"cost_basis_bef_call",t);
}



//^^^

#line 1 "cost_basis_bef_call.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if ((t == maturity_period
	 || bond_cf->par_val_aft_sched_pmt(t) < ASSET_ACTIVE_THRESHOLD)
	&& cost_basis_defn == AMORTIZED_COST)
	{
	// Cost never exactly amortizes to par. Cost must be set to zero
	// at maturity to keep the balance sheet in balance unless it is
	// really out of balance.
	double local_cost_basis = 0;

	local_cost_basis
	= cost_basis_aft_dflt(t)
	  + accr_int_aft_dflt(t)
	  - accr_int_bef_call(t)
	  + base_inc_bef_call(t)
	  - bond_cf->int_pmt(t)
	  - bond_cf->sinking_fund_pmt_inc(t)
	  - bond_cf->sched_prin_pmt(t);

	if (fabs(local_cost_basis
			 - bond_cf->par_val_aft_sched_pmt(t))
		 < (SOLVE_FOR_SPREAD_TOLERANCE * 2.0))
		return 0.0;
	else
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << setprecision(2);
		log_screen << "Warning. Problem with bond amortization to " << amortzd_cost_period_defn
				   << " for " << asset_id
				   << MSG_ERROR;
		log_screen << " ... At maturity, cost basis " << local_cost_basis
				   << " has not amortized to zero in projection task loop " << proj_task_loop_num
				   << " for scenario set " << replaceWildcards(rates->scen_id)				
				   << " Please contact client services."
				   << MSG_ERROR;
		log_screen << setprecision(6);
		log_screen.unsetf(ios::fixed);

		return 0.0;
		}
	}

if (bond_cf->par_val_aft_sched_pmt(t) < model_point_amount_threshold)
	return 0.0;

if (cost_basis_defn == AMORTIZED_COST)
	{
	return cost_basis_aft_dflt(t)
		   + accr_int_aft_dflt(t)
		   - accr_int_bef_call(t)
		   + base_inc_bef_call(t)
		   - bond_cf->int_pmt(t)
		   - bond_cf->sinking_fund_pmt_inc(t)
		   - sched_prin_pmt(t);
	}
return NO_AVG;

}


//@@ END

//@@ START - cost_basis_bef_sale
// Cost Basis Before Sales                                                                                             
// Column:COST_BASIS_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_bef_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return init_cost_basis * neg_asset_flag;

if (!existing_asset_indicator && t == commencement_period)
	return mkt_val_per_unit_par
		   * bond_cf->par_val_bef_sale(t);

if (cost_basis_defn == AMORTIZED_COST)
	return cost_basis_aft_put(t)
		   + accr_int_aft_put(t)
		   - accr_int_bef_sale(t);

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_dflt
// Cost Basis Default                                                                                             
// Column:COST_BASIS_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"cost_basis_dflt",t);
}



//^^^

#line 1 "cost_basis_dflt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis(t - 1)
	   * dflt_pct(t);

}


//@@ END

//@@ START - cost_basis_incr_appreciation
// Cost Basis Increase from Appreciation                                                                                             
// Column:COST_BASIS_INCR_APPRECIATION
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_incr_appreciation(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"cost_basis_incr_appreciation",t);
}



//^^^

#line 1 "cost_basis_incr_appreciation.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_purch
// Cost Basis Purchase                                                                                             
// Column:COST_BASIS_PURCH
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_purch(int t) {
//^^^



//^^^

#line 1 "cost_basis_purch.BOND_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (t == commencement_period)
	return cost_basis(t);

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_sched_prin_pmt
// Cost Basis Scheduled Principal Payment                                                                                             
// Column:COST_BASIS_SCHED_PRIN_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_sched_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"cost_basis_sched_prin_pmt",t);
}



//^^^

#line 1 "cost_basis_sched_prin_pmt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double cost_basis_bef_sched_prin_pmt = 0;

if (cost_basis_defn == AMORTIZED_COST)
	cost_basis_bef_sched_prin_pmt
	= cost_basis_aft_dflt(t)
	  + accr_int_aft_dflt(t)
	  - accr_int_bef_call(t)
	  + base_inc_bef_call(t)
	  - bond_cf->int_pmt(t)
	  - bond_cf->sinking_fund_pmt_inc(t);

return cost_basis_bef_sched_prin_pmt
       - cost_basis_bef_call(t);

}


//@@ END

//@@ START - cost_basis_sold
// Cost Basis Sold                                                                                             
// Column:COST_BASIS_SOLD
//========================================================
double BOND_ASSET_UDF::bond_asset_cost_basis_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"cost_basis_sold",t);
}



//^^^

#line 1 "cost_basis_sold.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return cost_basis_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double BOND_ASSET_UDF::bond_asset_date(int t) {
//^^^



//^^^

#line 1 "date.BOND_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month
int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - dflt_amt
// Default Amount                                                                                             
// Column:DFLT_AMT
//========================================================
double BOND_ASSET_UDF::bond_asset_dflt_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(52,"dflt_amt",t);
}



//^^^

#line 1 "dflt_amt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->dflt_amt;

if (t == 0)
	return dflt_amt(t + 1);

return (cost_basis(t - 1) +  accr_int(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - dflt_pct
// Default Percent                                                                                             
// Column:DFLT_PCT
//========================================================
double BOND_ASSET_UDF::bond_asset_dflt_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(53,"dflt_pct",t);
}



//^^^

#line 1 "dflt_pct.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double annual_dflt_pct_prelim
= rates->get_dflt_rate(t,
                       category_id,
                       EFFECTIVE_ANNUAL);

double annual_dflt_pct
= max(0.0,
      min(1.0,
          round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
                       annual_dflt_pct_prelim,
                       DECIMALS_TO_ROUND)));

if (annual_dflt_pct < 1.0 - rate_ratio_threshold)
	return 1.0 - pow(1.0 - annual_dflt_pct, (1.0 / 12.0));

return 1.0;

}


//@@ END

//@@ START - dur_val
// Duration Value                                                                                             
// Column:DUR_VAL
//========================================================
double BOND_ASSET_UDF::bond_asset_dur_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(54,"dur_val",t);
}



//^^^

#line 1 "dur_val.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return eff_dur(t);

}


//@@ END

//@@ START - eff_dur
// Effective Duration                                                                                             
// Column:EFF_DUR
//========================================================
double BOND_ASSET_UDF::bond_asset_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"eff_dur",t);
}



//^^^

#line 1 "eff_dur.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->eff_dur;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Effective Duration Calculation"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

double calculated_effective_duration;

if (fabs((mkt_val_bef_sale(t) + accr_int_bef_sale(t))
		 * SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION)
	 > model_point_amount_threshold)
	calculated_effective_duration
	= (mkt_val_bef_sale(t) - mkt_val_shifted(t))
	  / ((mkt_val_bef_sale(t) + accr_int_bef_sale(t))
		 * SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION);
else
	calculated_effective_duration = 0.0;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Effective Duration Calculation ("
			<< write_string(calculated_effective_duration,PVCLen,PVCSigDig)
			<< ") for" << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return calculated_effective_duration;

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double BOND_ASSET_UDF::bond_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.BOND_ASSET.for"
// 20240202 Temp fix for issue: Asset model points that mature on the same date as a future valuation 
//period are not correctly removed from the asset mapping
if (time_step_flag && !valn_flag && t < maturity_period 
	&& proj_set_sub_loop_num < valn_periods.size())
	write_state_of_world_mp();

if (isMainModel && num_bond == num_bonds_to_run)
	{
	if (PVCFile != NULL)
		PVCFile.close();
	}	
	
return 1.0;

}


//@@ END

//@@ START - gaap_inc_bk_val
// GAAP Income Book Value                                                                                             
// Column:GAAP_INC_BK_VAL
//========================================================
double BOND_ASSET_UDF::bond_asset_gaap_inc_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"gaap_inc_bk_val",t);
}



//^^^

#line 1 "gaap_inc_bk_val.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_inc_defn == COST_BASIS)
	return cost_basis(t);

if (gaap_inc_defn == MARKET_VALUE)
	return mkt_val(t);

return 0.0;

}


//@@ END

//@@ START - gaap_inc_unrealzd_cap_gain
// GAAP Income Unrealized Capital Gain                                                                                             
// Column:GAAP_INC_UNREALZD_CAP_GAIN
//========================================================
double BOND_ASSET_UDF::bond_asset_gaap_inc_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"gaap_inc_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_inc_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - gaap_surp_bk_val
// GAAP Surplus Book Value                                                                                             
// Column:GAAP_SURP_BK_VAL
//========================================================
double BOND_ASSET_UDF::bond_asset_gaap_surp_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"gaap_surp_bk_val",t);
}



//^^^

#line 1 "gaap_surp_bk_val.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_val_defn == COST_BASIS)
	return cost_basis(t);

if (gaap_val_defn == MARKET_VALUE)
	return mkt_val(t);

return 0.0;

}


//@@ END

//@@ START - gaap_unrealzd_cap_gain_incr
// GAAP Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_UNREALZD_CAP_GAIN_INCR
//========================================================
double BOND_ASSET_UDF::bond_asset_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_unrealzd_cap_gain_incr.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return 0.0;

return gaap_inc_unrealzd_cap_gain(t) 
	   - gaap_inc_unrealzd_cap_gain(t - 1);

}


//@@ END

//@@ START - imr_realzd_cap_gain
// Interest Maintenance Reserve Realized Capital Gain                                                                                             
// Column:IMR_REALZD_CAP_GAIN
//========================================================
double BOND_ASSET_UDF::bond_asset_imr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"imr_realzd_cap_gain",t);
}



//^^^

#line 1 "imr_realzd_cap_gain.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (bond_cf->call_amt(t)
		  - cost_basis_bef_call(t)
			* bond_cf->call_pct_mthly(t)
		  + bond_cf->put_amt(t)
		  - cost_basis_bef_call(t)
			* (1.0 - bond_cf->call_pct_mthly(t))
			* bond_cf->put_pct_mthly(t));

}


//@@ END

//@@ START - imr_realzd_cap_gain_from_sale
// Interest Maintenance Reserve Realized Capital Gains from Sales                                                                                             
// Column:IMR_REALZD_CAP_GAIN_FROM_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_imr_realzd_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(62,"imr_realzd_cap_gain_from_sale",t);
}



//^^^

#line 1 "imr_realzd_cap_gain_from_sale.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - imr_yrs_to_maturity
// Interest Maintenance Reserve Years to Maturity                                                                                             
// Column:IMR_YRS_TO_MATURITY
//========================================================
double BOND_ASSET_UDF::bond_asset_imr_yrs_to_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(63,"imr_yrs_to_maturity",t);
}



//^^^

#line 1 "imr_yrs_to_maturity.BOND_ASSET.for"
if (t <= start_period || t > maturity_period)
	return NO_AVG;

double imr_ytm = xint(cal_mth(t) - 1 + maturity_period - t) / 12.0;

if (sinking_fund_sch_base(t) > rate_ratio_threshold)
	return imr_ytm / 2.0;

return imr_ytm;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double BOND_ASSET_UDF::bond_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.BOND_ASSET.for"
if (!isMainModel)
	shrink_bond_clone(getElementNumber());

// create psa_base_rate
setup_psa_base_rate();

if (investing_flag)
	return 1;

if (is_asset_initialize)
	return 1;

if (isMainModel)
	{
	static int loaded_proj_task_loop = -999;

	if (loaded_proj_task_loop != proj_task_loop_num)
		{
		rates->initialize(t);

		loaded_proj_task_loop = proj_task_loop_num;

		// reinitialize num_bond
		num_bond = 0;
		}

	// increment the number of records
	num_bond++;

	static bool first_time = true;

	if (asset_detail_rpt_pv_defn == YES && first_time)
		{
		first_time = false;

		asset_detail_rpt_id
		= get_file_path(output_location())
		  + get_file_name(output_location())
		  + "~ASSET_PRESENT_VALUE_DETAIL.csv";
	
		PVCFile.open((xstring)asset_detail_rpt_id);
		PVCFile.setf(ios::fixed, ios::floatfield);
		PVCFile.precision(12);
	
		if (!PVCFile)
			throw FatalError("Error: Cannot open bond->asset_detail_rpt_id."
							 "Present value detail reporting has been cancelled."
							 "Check that the directory has been created and that you have permission to write it");
		else
			PVCFile << endl
					<<"Present Value Detail Report for "
					<< get_file_name(output_location()) << endl;
		}
	}

xstring index_val;

index_val = asset_id + data_grp_id + xstring(data_rec_num());

if ((bond_initial_values_map_iter = bond_initial_values_map.find(index_val))
	!= bond_initial_values_map.end())
	{
	// if values are in map, then read from map
	initial_values = bond_initial_values_map_iter->second;
	}
else
	{
	// otherwise, add values to map
	is_asset_initialize = 1;

	if (asset_detail_rpt_pv_flag(0))
		{
		PVCounter++;
		PVCText << PVCounter 
				<< "-->Begin Initialize" 
				<< " for " << asset_id 
				<< " (" << pmt_rate_defn_string << ")";
		asset_detail_rpt_pv_output();
		}

	initial_values = new struct bondInitialValuesData;

	double local_net_yield_at_issue = 0;

	double temp_dbl;

	// net yield at issue calculation
	if (net_yld_at_issue_flag == YES)
		{
		local_net_yield_at_issue = net_yld_at_issue;

		bond->resetValues();
		bond_cf->resetValues();
		bond_pv->resetValues();

		if (asset_detail_rpt_pv_flag(commencement_period))
			{
			asset_detail_log_rebase_reset(0,
					"bond->resetValues",
					"bond->initialize",
					asset_id, modelName);
			asset_detail_log_rebase_reset(0,
					"bond_cf->resetValues",
					"bond->initialize",
					asset_id, modelName);
			asset_detail_log_rebase_reset(0,
					"bond_pv->resetValues",
					"bond->initialize",
					asset_id, modelName);
			}

		if (commencement_period < 0)
			commencement_period = 0;
		}

	temp_dbl = refinancing_rate_opt_sprd;

	mkt_sprd(0);

	// initializations before anticipated yield calculation
	mkt_val(0);
	eff_dur(0);
	net_yld(0);

	initial_values->yld_numer = yld_numer(0);
	initial_values->dflt_amt = dflt_amt(0);
	initial_values->mkt_val_bef_sale = mkt_val_bef_sale(0);
	initial_values->eff_dur = eff_dur(0);
	initial_values->mkt_sprd = mkt_sprd(0);
	initial_values->net_yld = net_yld(0);
	initial_values->amortzn_cost_period = amortzn_cost_period;
	initial_values->net_yld_at_issue = local_net_yield_at_issue;
	initial_values->opt_sprd = opt_sprd(0);
	initial_values->refinancing_rate_opt_sprd = refinancing_rate_opt_sprd;
	initial_values->weighted_avg_life = weighted_avg_life(0);

	bond_initial_values_map[index_val] = initial_values;

	if (asset_detail_rpt_pv_flag(0))
		{
		PVCText << PVCounter 
				<< "<--End initialize"
				<< " for" << asset_id 
				<< " (" << pmt_rate_defn_string << ")";
		asset_detail_rpt_pv_output();
		PVCounter--;
		}

	is_asset_initialize = 0;

	resetValues();
	bond_cf->resetValues();

	if (asset_detail_rpt_pv_flag(commencement_period))
		{
		asset_detail_log_rebase_reset(0,
				"bond->resetValues",
				"bond->initialize",
				asset_id, modelName);
		asset_detail_log_rebase_reset(0,
				"bond_cf->resetValues",
				"bond->initialize",
				asset_id, modelName);
		}
	}

return 1.0;

}


//@@ END

//@@ START - int_div_and_rent
// Interest Dividend and Rent                                                                                             
// Column:INT_DIV_AND_RENT
//========================================================
double BOND_ASSET_UDF::bond_asset_int_div_and_rent(int t) {
//^^^



//^^^

#line 1 "int_div_and_rent.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return int_pmt(t)
	   + opt_inc(t)
	   + accr_int_sold(t);

}


//@@ END

//@@ START - int_pmt
// Interest Payment                                                                                             
// Column:INT_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_int_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(66,"int_pmt",t);
}



//^^^

#line 1 "int_pmt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->int_pmt(t)
	   + bond_cf->sinking_fund_pmt_inc(t);

}


//@@ END

//@@ START - mkt_risk_sprd
// Market Risk Spread                                                                                             
// Column:MKT_RISK_SPRD
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_risk_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(67,"mkt_risk_sprd",t);
}



//^^^

#line 1 "mkt_risk_sprd.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (bond_cf->par_val_bef_sale(t) > 0.0)
	{
	// force calculation order for /fp:fast compiler switch
	double spread_to_spot = risk_sprd(t);
	spread_to_spot += mkt_sprd(t);

	return spread_to_spot;
	}

return NO_AVG;

}


//@@ END

//@@ START - mkt_sprd
// Market Spread                                                                                             
// Column:MKT_SPRD
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"mkt_sprd",t);
}



//^^^

#line 1 "mkt_sprd.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	{
	if (!is_asset_initialize)
		return initial_values->mkt_sprd;

	if (fabs(init_mkt_val) < model_point_amount_threshold
		|| asset_mkt_sprd_use_defn == SET_TO_ZERO
		|| refinancing_rate_opt_sprd_calc_flag)
		return 0;

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCounter++;
		PVCText << PVCounter << "-->Begin Market Spread Calculation"
				<< " for " << asset_id
				<< " (" << pmt_rate_defn_string << ")"
				<< " t=" << t
				<< " CalYr=" << xint(cal_yr(t))
				<< " CalMth=" << xint(cal_mth(t));
		asset_detail_rpt_pv_output();    
		}

	rebase_bond_cash_flow(t,
				PRESENT_VALUE, "bond->mkt_sprd", modelName);

	bond_pv->pv_calc_parameters(t,
				MARKET_VALUE, xint(maturity_period - t));

	// Force calculation order for /fp:fast compiler switch
	double spread_to_spot = risk_sprd(t);
	spread_to_spot = opt_sprd(t);

	double temp = 0.0;
	double calculated_modified_duration = 0.0;

	// Get modified duration
	double price
	= bond_pv->pv_calc(t, 
	                   spread_to_spot,
	                   temp, // Calculated_derivative
	                   calculated_modified_duration);

	double guess_spread
	= opt_sprd(t)
	  - (init_mkt_val * neg_asset_flag
	      - price)
		/ (price * calculated_modified_duration);   

	double calculated_market_spread
	= bond_pv->solve_for_sprd_newton_raphson(t,
	                                         guess_spread,
	                                         init_mkt_val * neg_asset_flag)
	  - opt_sprd(t);

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCText << PVCounter
				<< "<--End Market Spread Calculation ("
				<< write_string(calculated_market_spread,PVCLen,PVCSigDig)
				<< ") for " << asset_id
				<< " (" << pmt_rate_defn_string << ")"
				<< " t=" << t
				<< " CalYr=" << xint(cal_yr(t))
				<< " CalMth=" << xint(cal_mth(t));
		asset_detail_rpt_pv_output();
		PVCounter--;
		}

	return calculated_market_spread;
	}

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (asset_mkt_sprd_use_defn == HOLD_LEVEL)
	return mkt_sprd(t - 1);

if (asset_mkt_sprd_use_defn == GRADE_TO_ZERO)
	return mkt_sprd(t - 1) * (1.0 - 1.0 / (1.0 + maturity_period - t));

if (asset_mkt_sprd_use_defn == SET_TO_ZERO)
	return 0.0;

return NO_AVG;

}


//@@ END

//@@ START - mkt_to_bk_ratio
// Market to Book Ratio                                                                                             
// Column:MKT_TO_BK_RATIO
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "mkt_to_bk_ratio.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_sale(t)) < model_point_amount_threshold)
	{
	if (mkt_val_bef_sale(t) > model_point_amount_threshold)
		return USLIB_MAX_DOUBLE;

	return USLIB_MIN_DOUBLE;
	}

return mkt_val_bef_sale(t) / bk_val_bef_sale(t);

}


//@@ END

//@@ START - mkt_val
// Market Value                                                                                             
// Column:MKT_VAL
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(70,"mkt_val",t);
}



//^^^

#line 1 "mkt_val.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_bef_neg_cash_flow_sale(t)
	   * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - mkt_val_bef_fund_match_sale
// Market Value Before Fund Value Matching Asset Sales                                                                                             
// Column:MKT_VAL_BEF_FUND_MATCH_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(71,"mkt_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "mkt_val_bef_fund_match_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - mkt_val_bef_neg_cash_flow_sale
// Market Value Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_bef_rebal_sale(t)
       * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - mkt_val_bef_rebal_sale
// Market Value Before Rebalancing Sales                                                                                             
// Column:MKT_VAL_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_bef_fund_match_sale(t)
       * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - mkt_val_bef_sale
// Market Value Before Sales                                                                                             
// Column:MKT_VAL_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->mkt_val_bef_sale;

if (!existing_asset_indicator && t == commencement_period)
	return cost_basis_bef_sale(t);

if (fabs(notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Before Sale"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

rebase_bond_cash_flow(t,
			PRESENT_VALUE, "bond->mkt_val_bef_sale", modelName);

bond_pv->pv_calc_parameters(t,
			MARKET_VALUE, xint(maturity_period - t));

// force calculation order for /fp:fast compiler switch
// force calculation order for /fp:fast compiler switch
double spread_to_spot = opt_sprd(t);
spread_to_spot += mkt_sprd(t);

double temp = 0;

double calculated_market_value
= bond_pv->pv_calc(t, 
		spread_to_spot, 
		temp,  // calculated_derivative
		temp   // calculated_modified_duration
		);

if (asset_detail_rpt_pv_flag(t))
	{
	if (asset_detail_rpt_pv_defn == YES)
		PVCFile << endl
				<< "WAL," << write_string(weighted_avg_life(t),PVCLen,PVCSigDig) << endl
				<< "OptSprd," << write_string(opt_sprd(t),PVCLen,PVCSigDig) << endl
				<< "AdjSprd," << write_string(mkt_sprd(t),PVCLen,PVCSigDig) << endl;

	PVCText << PVCounter
			<< "<--End Market Value Before Sale ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return calculated_market_value;

}


//@@ END

//@@ START - mkt_val_for_dur_bef_neg_cash_flow_sale
// Market Value for Duration Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_FOR_DUR_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(75,"mkt_val_for_dur_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (neg_asset_flag < 0)
	return NO_AVG;

// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	return mkt_val_bef_neg_cash_flow_sale(t) + accr_int_bef_neg_cash_flow_sale(t); // added by HYH on 5/24/2021
}
else
{
	return mkt_val_bef_neg_cash_flow_sale(t);
}

}


//@@ END

//@@ START - mkt_val_for_dur_bef_rebal_sale
// Market Value for Duration Before Rebalancing Sales                                                                                             
// Column:MKT_VAL_FOR_DUR_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"mkt_val_for_dur_bef_rebal_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (neg_asset_flag < 0)
	return NO_AVG;

// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	return mkt_val_bef_rebal_sale(t) + accr_int_bef_rebal_sale(t); // added by HYH on 5/24/2021;
}
else
{
	return mkt_val_bef_rebal_sale(t);
}

}


//@@ END

//@@ START - mkt_val_for_dur_sold
// Market Value for Duration Sold                                                                                             
// Column:MKT_VAL_FOR_DUR_SOLD
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"mkt_val_for_dur_sold",t);
}



//^^^

#line 1 "mkt_val_for_dur_sold.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (sold_pct(t) == 0.0)
	return NO_AVG;

return mkt_val_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - mkt_val_for_eff_dur
// Market Value for Effective Duration                                                                                             
// Column:MKT_VAL_FOR_EFF_DUR
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_for_eff_dur(int t) {
//^^^



//^^^

#line 1 "mkt_val_for_eff_dur.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	return mkt_val(t) + accr_int(t); // added by HYH on 5/24/2021;
}
else
{
	return mkt_val(t);
}

}


//@@ END

//@@ START - mkt_val_purch
// Market Value Purchase                                                                                             
// Column:MKT_VAL_PURCH
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(79,"mkt_val_purch",t);
}



//^^^

#line 1 "mkt_val_purch.BOND_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (t == commencement_period)
	return mkt_val(t);

return NO_AVG;

}


//@@ END

//@@ START - mkt_val_shifted
// Market Value Shifted                                                                                             
// Column:MKT_VAL_SHIFTED
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_shifted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(80,"mkt_val_shifted",t);
}



//^^^

#line 1 "mkt_val_shifted.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (fabs(notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "--> Begin Market Value Shifted"
			<< " for" << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

rebase_bond_cash_flow(t,
			PRESENT_VALUE, "bond->mkt_val_shifted", modelName);

bond_pv->pv_calc_parameters(t,
			MARKET_VALUE_SHIFTED, xint(maturity_period - t));

//This category rate is using the shifted yield curve

//20220613 STW: model efficiency improvement
double risk_sprd_shifted = 0.0;

double option_spread_shifted = 0;
double temp = 0;

if (call_first_period - t < maturity_period
	|| put_first_period - t < maturity_period)
	{

	//20220613 STW: model efficiency improvement
	risk_sprd_shifted
	  = rates->get_int_rate(t,
							category_id, 
							GET_SPOT_SPREAD,
							weighted_avg_life(t),
							0.0,
							NOMINAL_SEMIANNUAL,
							SPOT_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	double base_modified_duration = 0;

	double base_price
	= bond_pv->pv_calc(t, 
			0.0, 
			temp,  // calculated_derivative
			base_modified_duration
			);

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCText << "BasePrice,"	<< write_string(base_price,PVCLen,PVCSigDig) << endl 
				<< "BaseModDur," << write_string(base_modified_duration,PVCLen,PVCSigDig);
		asset_detail_rpt_pv_output();
		}

	double put_option_price_shifted = 0;

	if (put_first_period < maturity_period)
		put_option_price_shifted
		= bond_pv->put_opt_price_calc(t, SPOT_SHIFT);

	double call_option_price_shifted = 0;

	if (call_first_period < maturity_period)
		call_option_price_shifted
		= bond_pv->call_opt_price_calc(t, SPOT_SHIFT);

	double price = base_price
				   - call_option_price_shifted
				   + put_option_price_shifted;

	double calculated_option_spread = 0;
	double guess_spread = 0;

	if (call_option_price_shifted != put_option_price_shifted)
		{
		guess_spread
		= risk_sprd_shifted
		  - (-call_option_price_shifted + put_option_price_shifted)
			/ (base_price * base_modified_duration);

		calculated_option_spread
		= bond_pv->solve_for_sprd_newton_raphson(t,
				guess_spread, price);
		}

	option_spread_shifted = calculated_option_spread;

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCText << "Option Spread Shifted in Market Value Shifted Calculation,"	
		        << write_string(calculated_option_spread,PVCLen,PVCSigDig);
		asset_detail_rpt_pv_output();
		}
	}

double spread_to_spot
= option_spread_shifted
  + mkt_sprd(t);

double calculated_market_value
= bond_pv->pv_calc(t,
		spread_to_spot, 
		temp,  // calculated_derivative
		temp   // calculated_modified_duration
		);

if (asset_detail_rpt_pv_flag(t))
	{
	if (asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << endl
				<< "WAL,"     << write_string(weighted_avg_life(t),PVCLen,PVCSigDig) << endl
				<< "CatSprd," << write_string(risk_sprd_shifted,PVCLen,PVCSigDig) << endl
				<< "OptSprd," << write_string(option_spread_shifted,PVCLen,PVCSigDig) << endl
				<< "AdjSprd," << write_string(mkt_sprd(t),PVCLen,PVCSigDig) << endl;
		}
	PVCText << PVCounter
			<< "<--End Market Value Shifted ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< ") for" << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return calculated_market_value;

}


//@@ END

//@@ START - mkt_val_sold
// Market Value Sold                                                                                             
// Column:MKT_VAL_SOLD
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_sold(int t) {
//^^^



//^^^

#line 1 "mkt_val_sold.BOND_ASSET.for"
if ( t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return NO_AVG;

return mkt_val_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - mkt_val_times_dur_bef_neg_cash_flow_sale
// Market Value Times Duration Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_TIMES_DUR_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (neg_asset_flag < 0)
	return NO_AVG;


// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	return mkt_val_for_dur_bef_neg_cash_flow_sale(t) //mkt_val_bef_neg_cash_flow_sale(t) //changed by HYH 5/24/2021
		   * dur_val(t);
}
else
{
	return mkt_val_bef_neg_cash_flow_sale(t)
		   * dur_val(t);
}

}


//@@ END

//@@ START - mkt_val_times_dur_bef_rebal_sale
// Market Value Times Duration Before Rebalancing Sales                                                                                             
// Column:MKT_VAL_TIMES_DUR_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_times_dur_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (neg_asset_flag < 0)
	return NO_AVG;

return mkt_val_for_dur_bef_rebal_sale(t)
	   * dur_val(t);

}


//@@ END

//@@ START - mkt_val_times_eff_dur
// Market Value Times Effective Duration                                                                                             
// Column:MKT_VAL_TIMES_EFF_DUR
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_times_eff_dur(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_eff_dur.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_for_eff_dur(t)
	   * eff_dur(t);

}


//@@ END

//@@ START - mths_to_next_mkt_val_calc
// Months to Next Market Value Calculation                                                                                             
// Column:MTHS_TO_NEXT_MKT_VAL_CALC
//========================================================
double BOND_ASSET_UDF::bond_asset_mths_to_next_mkt_val_calc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(85,"mths_to_next_mkt_val_calc",t);
}



//^^^

#line 1 "mths_to_next_mkt_val_calc.BOND_ASSET.for"
if (t < 0)
	return NO_AVG;

if (!isMainModel)
	return asset->mths_to_next_mkt_val_calc(t);

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

//@@ START - net_yld
// Net Yield                                                                                             
// Column:NET_YLD
//========================================================
double BOND_ASSET_UDF::bond_asset_net_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(86,"net_yld",t);
}



//^^^

#line 1 "net_yld.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn != AMORTIZED_COST)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->net_yld;

bool calculate_net_yield = false;

if (t == 0 || t == commencement_period)
	calculate_net_yield = true;
else 
	{
	if (amortzn_cost_period - t > 0
		&& pmt_rate_defn == FLOATING_RATE 
		&& mths_to_next_reset(t - 1) == 1
		&& bond_cf->par_val_bef_sale(t) > 0.0
		&& cost_basis_aft_put(t) > 0.0)
		calculate_net_yield = true;

	if (amortzn_cost_period - t == 0
		&& bond_cf->par_val_bef_sale(t) > 0.0
		&& cost_basis_aft_put(t) > 0.0
		&& fabs(cost_basis_aft_put(t)
				- bond_cf->par_val_bef_sale(t))
			> SOLVE_FOR_SPREAD_TOLERANCE)
		calculate_net_yield = true;
	}

if (!calculate_net_yield)
	{
	if (amortzn_cost_period - t > 0)
		return net_yld(t - 1);
	else
		return convert_rate_basis(bond_cf->pmt_rate(t), pmt_freq, NOMINAL_MONTHLY);
	}

// Calculate Net Yield
double target_value = 0;
int solve_timing;

if (existing_asset_indicator && t == commencement_period)
	{
	if (net_yld_at_issue_calc_flag)
		{
		target_value = par_val_at_issue;
		solve_timing = NET_YIELD_AT_ISSUE;
		}
	else
		{
		target_value = cost_basis_bef_sale(t);
		solve_timing = END_OF_MONTH;
		}
	}
else if ((existing_asset_indicator && t == 0)
		 || (!existing_asset_indicator && t == commencement_period))
	{
	target_value = cost_basis_bef_sale(t);
	solve_timing = END_OF_MONTH;
	}
else
	{
	target_value = cost_basis_aft_put(t);  
	solve_timing = AFTER_CALLS_AND_PUTS;
	}

if (existing_asset_indicator && t == 0)
	{
	if (target_value == 0.0 && bond_cf->par_val(t) != 0.0)
		{
		log_screen.setf(ios::fixed, ios:: floatfield);
		log_screen << "Error. Unable to calculate spread to amortize Target Value"
				<< " to Par Value because Target value is zero"
				<< " and Par Value " << bond_cf->par_val(t)
				<< " is not zero. Bond Id=" << asset_id
				<< " commencement_period=" << commencement_period
				<< MSG_ERROR;
		log_screen.unsetf(ios::fixed);
		log_screen << "ID = " << asset_id
				 << " |" << modelName
				 << " Year = " << xint(cal_yr_relative(t))
				 << " Month = " << xint(cal_mth(t))
				 << " Projection Task Loop = " << proj_task_loop_num
				 << MSG_ERROR;
		throw FatalError("");
		}
	}

// net yield equal payment rate
if (target_value == bond_cf->par_val_bef_sale(t))
	return convert_rate_basis(bond_cf->pmt_rate(t), pmt_freq, 12);

int selection_loop_start = 0;
int selection_loop_end = 0;
int local_months_to_amortize_cost_to_par = 0;
int selection = 0;
double local_net_yield = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;

if (amortzd_cost_period_defn == TO_YIELD_TO_WORST)
	{
	selection_loop_start = 1;
	selection_loop_end = num_of_amortize_cost_selections;
	}
else
	{
	selection_loop_start = amortzd_cost_period_defn.ord();
	selection_loop_end = amortzd_cost_period_defn.ord();
	}

for (selection = selection_loop_start;
	 selection <= selection_loop_end;
	 selection++)
	{
	if (selection == 1)
		amortzd_cost_period_defn_save = "To Maturity";
	else if (selection == 2)
		amortzd_cost_period_defn_save = "To First Call";
	else if (selection == 3)
		amortzd_cost_period_defn_save = "To First Par Call";
	else if (selection == 4)
		amortzd_cost_period_defn_save = "To First Put";
	else if (selection == 5)
		amortzd_cost_period_defn_save = "To First Par Put";
	else // selection == 6
		amortzd_cost_period_defn_save = "To Yield to Worst";

	if (amortzd_cost_period_defn == TO_YIELD_TO_WORST)
		{
		if ((amortzd_cost_period_defn_save == TO_FIRST_CALL
			 || amortzd_cost_period_defn_save == TO_FIRST_PAR_CALL)
			&& (call_first_period >= maturity_period
				|| call_first_period < 1))
			continue;
		if ((amortzd_cost_period_defn_save == TO_FIRST_PUT
			 || amortzd_cost_period_defn_save == TO_FIRST_PAR_PUT)
			&& (put_first_period >= maturity_period
				|| put_first_period < 1))
			continue;
		if (amortzd_cost_period_defn_save == TO_YIELD_TO_WORST)
			continue;
		}

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCounter++;
		PVCText << PVCounter
				<< "-->Begin Net Yield Calculation (" << amortzd_cost_period_defn_save << ")"
				<< " for " << asset_id
				<< " (" << pmt_rate_defn_string << ")"
				<< " t=" << t 
				<< " CalYr=" << xint(cal_yr(t))
				<< " CalMth=" << xint(cal_mth(t));
		asset_detail_rpt_pv_output();
		}

	if (amortzd_cost_period_defn_save == TO_MATURITY)
		cost_basis_amortzn_mths 
		= maturity_period - t;
	else if (amortzd_cost_period_defn_save == TO_FIRST_CALL
			 && solve_timing == NET_YIELD_AT_ISSUE)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t, call_first_period - t));
	else if (amortzd_cost_period_defn_save == TO_FIRST_CALL)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t, call_first_period - t));
	else if (amortzd_cost_period_defn_save == TO_FIRST_PAR_CALL)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t,
					 min(999, call_par_first_period - t)));
	else if (amortzd_cost_period_defn_save == TO_FIRST_PUT
			 && solve_timing == NET_YIELD_AT_ISSUE)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t, put_first_period - t));
	else if (amortzd_cost_period_defn_save == TO_FIRST_PUT)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t, put_first_period - t));
	else if (amortzd_cost_period_defn_save == TO_FIRST_PAR_PUT)
		cost_basis_amortzn_mths 
		= max(1, min(maturity_period - t, put_par_first_period - t));

	//rebase the net yield model
	rebase_bond_cash_flow(t, PRESENT_VALUE, "bond->net_yld", modelName);

	bond_pv->pv_calc_parameters(t, NET_YIELD, cost_basis_amortzn_mths);

	double selection_net_yield
	= convert_rate_basis(bond_pv->solve_for_sprd_newton_raphson(t, 
										bond_cf->pmt_rate(t), target_value),
			  NOMINAL_SEMIANNUAL,
			  12);

	if (asset_detail_rpt_pv_flag(t))
		{
		PVCText << PVCounter
				<< "Net Yields" << endl
				<< "Monthly," << write_string(selection_net_yield,PVCLen,PVCSigDig) << endl 
				<< "Semi-Annual," << write_string(convert_rate_basis( selection_net_yield, 12, 2),PVCLen,PVCSigDig) << endl 
				<< "Annual," << write_string(convert_rate_basis( selection_net_yield, 12, 1),PVCLen,PVCSigDig);
		asset_detail_rpt_pv_output();
		PVCounter--;
		}

	if (selection_net_yield < local_net_yield)
		{
		local_net_yield = selection_net_yield;
		local_months_to_amortize_cost_to_par = cost_basis_amortzn_mths;
		}
	}
	
if (solve_timing != NET_YIELD_AT_ISSUE)
	amortzn_cost_period = local_months_to_amortize_cost_to_par + t;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< " <--End Net Yield Calculation ("
			<< write_string(local_net_yield,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t 
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

return local_net_yield;

}


//@@ END

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double BOND_ASSET_UDF::bond_asset_notional_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(87,"notional_amt",t);
}



//^^^

#line 1 "notional_amt.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (t > max(0, commencement_period)
	&& fabs(notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

return bond_cf->par_val(t);

}


//@@ END

//@@ START - notional_amt_bef_fund_match_sale
// Notional Amount Before Fund Value Matching Asset Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_FUND_MATCH_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_notional_amt_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(88,"notional_amt_bef_fund_match_sale",t);
}



//^^^

#line 1 "notional_amt_bef_fund_match_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return notional_amt_bef_sale(t)
		* (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - notional_amt_bef_neg_cash_flow_sale
// Notional Amount Before Negative Cash Flow Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_notional_amt_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return notional_amt_bef_rebal_sale(t)
       * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - notional_amt_bef_rebal_sale
// Notional Amount Before Rebalancing Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_notional_amt_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return notional_amt_bef_fund_match_sale(t)
       * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - notional_amt_bef_sale
// Notional Amount Before Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_notional_amt_bef_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->par_val_bef_sale(t);

}


//@@ END

//@@ START - opt_inc
// Option Income                                                                                             
// Column:OPT_INC
//========================================================
double BOND_ASSET_UDF::bond_asset_opt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"opt_inc",t);
}



//^^^

#line 1 "opt_inc.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (bond_cf->par_val_aft_sched_pmt(t) == 0.0)
	return NO_AVG;

return bond_cf->call_inc(t) + bond_cf->put_inc(t);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"opt_pmt",t);
}



//^^^

#line 1 "opt_pmt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (bond_cf->par_val_aft_sched_pmt(t) == 0.0)
	return NO_AVG;

return bond_cf->call_amt(t) + bond_cf->put_amt(t);

}


//@@ END

//@@ START - opt_sprd
// Option Spread                                                                                             
// Column:OPT_SPRD
//========================================================
double BOND_ASSET_UDF::bond_asset_opt_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"opt_sprd",t);
}



//^^^

#line 1 "opt_sprd.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->opt_sprd; 

if (call_first_period >= maturity_period
	&& put_first_period >= maturity_period)
	return 0.0;    	 

double price = 0.0;
double base_price = 0.0;
double base_modified_duration = 0.0;
double temp = 0.0;
double calculated_option_spread = 0.0;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Option Spread Calculation"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

double weighted_average_life = bond_pv->weighted_avg_life_calc(t);

double risk_spread
= rates->get_int_rate(t,
                      category_id,
				      GET_SPOT_SPREAD,
				      weighted_average_life,
				      0.0,
				      NOMINAL_SEMIANNUAL,
				      NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

base_price
= bond_pv->pv_calc(t,
		0.0,
		temp,  // calculated_derivative
		base_modified_duration
		);

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << "BasePrice," << write_string(base_price,PVCLen,PVCSigDig) << endl 
			<< "BaseModDur," << write_string(base_modified_duration,PVCLen,PVCSigDig);
	asset_detail_rpt_pv_output();
	}

double put_option_price = 0;

if (t < maturity_period && put_first_period < maturity_period)
	put_option_price
	= bond_pv->put_opt_price_calc(t, NO_SHIFT);

double call_option_price = 0;

if (call_first_period < maturity_period)
	call_option_price = bond_pv->call_opt_price_calc(t, NO_SHIFT);

// Target price for new issue should be max(ONE_MILLION, fabs(purch_amt))
if (investing_flag)
	price = max(ONE_MILLION, fabs(purch_amt));
else
	price = base_price
			- call_option_price
			+ put_option_price;

if (call_option_price != put_option_price)
	{
	double guess_spread
	= - (-call_option_price + put_option_price)
		/ (base_price * base_modified_duration);
	
	calculated_option_spread
	= bond_pv->solve_for_sprd_newton_raphson(t,
			guess_spread, price);
	}

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Option Spread Calculation ("
			<< write_string(calculated_option_spread, PVCLen, PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}
	
return calculated_option_spread;

}


//@@ END

//@@ START - rbc_c1
// Risk Based Capital C1                                                                                             
// Column:RBC_C1
//========================================================
double BOND_ASSET_UDF::bond_asset_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return rbc_c1_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - rbc_c1_bef_sale
// Risk Based Capital C1 Before Sales                                                                                             
// Column:RBC_C1_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_rbc_c1_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(96,"rbc_c1_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return rbc_c1_pct
	   * bk_val_bef_sale(t);

}


//@@ END

//@@ START - realzd_cap_gain
// Realized Capital Gain                                                                                             
// Column:REALZD_CAP_GAIN
//========================================================
double BOND_ASSET_UDF::bond_asset_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"realzd_cap_gain",t);
}



//^^^

#line 1 "realzd_cap_gain.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return sched_prin_pmt(t)
	   - cost_basis_sched_prin_pmt(t)
	   + realzd_cap_gain_opt_pmt(t)
	   - realzd_cap_loss_dflt(t);

}


//@@ END

//@@ START - realzd_cap_gain_opt_pmt
// Realized Capital Gain from Option Payment                                                                                             
// Column:REALZD_CAP_GAIN_OPT_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_realzd_cap_gain_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"realzd_cap_gain_opt_pmt",t);
}



//^^^

#line 1 "realzd_cap_gain_opt_pmt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double realzd_cap_gain_call
= bond_cf->call_amt(t)
  - cost_basis_bef_call(t)
  * bond_cf->call_pct_mthly(t);

double realzd_cap_gain_put
= bond_cf->put_amt(t)
  - cost_basis_bef_call(t)
  * (1.0 - bond_cf->call_pct_mthly(t))
  * bond_cf->put_pct_mthly(t);

return realzd_cap_gain_call
	   + realzd_cap_gain_put;

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gain from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_realzd_cap_gain_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(99,"realzd_cap_gain_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_sale.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return cap_gain_from_sale(t)
	   + unrealzd_cap_gain_released_on_sale(t);

}


//@@ END

//@@ START - realzd_cap_loss_dflt
// Realized Capital Loss from Default                                                                                             
// Column:REALZD_CAP_LOSS_DFLT
//========================================================
double BOND_ASSET_UDF::bond_asset_realzd_cap_loss_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(100,"realzd_cap_loss_dflt",t);
}



//^^^

#line 1 "realzd_cap_loss_dflt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (cost_basis(t - 1) + accr_int(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - risk_sprd
// Risk Spread                                                                                             
// Column:RISK_SPRD
//========================================================
double BOND_ASSET_UDF::bond_asset_risk_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"risk_sprd",t);
}



//^^^

#line 1 "risk_sprd.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return rates->get_int_rate(t,
                           category_id,
				           GET_SPOT_SPREAD,
				           weighted_avg_life(t),
				           0.0,
				           NOMINAL_SEMIANNUAL,
				           NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END

//@@ START - risk_sprd_shifted
// Risk Spread Shifted                                                                                             
// Column:RISK_SPRD_SHIFTED
//========================================================
double BOND_ASSET_UDF::bond_asset_risk_sprd_shifted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(102,"risk_sprd_shifted",t);
}



//^^^

#line 1 "risk_sprd_shifted.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

//This category rate is using the shifted yield curve
return rates->get_int_rate(t,
                           category_id, 
				           GET_SPOT_SPREAD,
				           weighted_avg_life(t),
				           0.0,
				           NOMINAL_SEMIANNUAL,
				           SPOT_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_sched_prin_pmt(int t) {
//^^^



//^^^

#line 1 "sched_prin_pmt.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bond_cf->sched_prin_pmt(t);

}


//@@ END

//@@ START - sinking_fund_sch_base
// Sinking Fund Schedule Base                                                                                             
// Column:SINKING_FUND_SCH_BASE
//========================================================
double BOND_ASSET_UDF::bond_asset_sinking_fund_sch_base(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(104,"sinking_fund_sch_base",t);
}



//^^^

#line 1 "sinking_fund_sch_base.BOND_ASSET.for"
if (sinking_fund_defn == NO
	|| t < start_period || t >= maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	{
	double cumul_future_pct = 0.0;
		
	for (int month = 1; month <= maturity_period; month++)
		cumul_future_pct += sinking_fund_sch[month];
	
	return cumul_future_pct;
	}

if (!existing_asset_indicator && t == commencement_period)
	return 1.0;

return max(0.0,
           sinking_fund_sch_base(t - 1)
           - sinking_fund_sch[t - start_period]);

}


//@@ END

//@@ START - sold_pct
// Sold Percent                                                                                             
// Column:SOLD_PCT
//========================================================
double BOND_ASSET_UDF::bond_asset_sold_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(105,"sold_pct",t);
}



//^^^

#line 1 "sold_pct.BOND_ASSET.for"
return max(0, 1.0 - (1.0 - sold_pct_planned(t))
					* (1.0 - sold_pct_fund_match(t))
					* (1.0 - sold_pct_rebal(t))
					* (1.0 - sold_pct_neg_cash_flow(t)));

}


//@@ END

//@@ START - sold_pct_fund_match
// Sold Percent Fund Value Matching                                                                                             
// Column:SOLD_PCT_FUND_MATCH
//========================================================
double BOND_ASSET_UDF::bond_asset_sold_pct_fund_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(106,"sold_pct_fund_match",t);
}



//^^^

#line 1 "sold_pct_fund_match.BOND_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_neg_cash_flow
// Sold Percent Negative Cash Flow                                                                                             
// Column:SOLD_PCT_NEG_CASH_FLOW
//========================================================
double BOND_ASSET_UDF::bond_asset_sold_pct_neg_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(107,"sold_pct_neg_cash_flow",t);
}



//^^^

#line 1 "sold_pct_neg_cash_flow.BOND_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_planned
// Sold Percent Planned                                                                                             
// Column:SOLD_PCT_PLANNED
//========================================================
double BOND_ASSET_UDF::bond_asset_sold_pct_planned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(108,"sold_pct_planned",t);
}



//^^^

#line 1 "sold_pct_planned.BOND_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_rebal
// Sold Percent Rebalancing                                                                                             
// Column:SOLD_PCT_REBAL
//========================================================
double BOND_ASSET_UDF::bond_asset_sold_pct_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(109,"sold_pct_rebal",t);
}



//^^^

#line 1 "sold_pct_rebal.BOND_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double BOND_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.BOND_ASSET.for"
#if 0 // START_HEADER
struct bondInitialValuesData
	{
	double yld_numer;
	double dflt_amt;
	double mkt_val_bef_sale;
	double eff_dur;
	double mkt_sprd;
	double net_yld;
	double amortzn_cost_period;
	double net_yld_at_issue;
	double opt_sprd;
	double refinancing_rate_opt_sprd;
	double weighted_avg_life;
	};
typedef map <xstring, struct bondInitialValuesData*, less<xstring> > bondivmap;
#endif // END_HEADER

#if 0 // START_EXTERNS
int num_bonds_to_run;
int num_bond = 0;
sowfinput bond_mp_input;
sowfcols bond_mp_input_cols;
sowfinput bond_sch_input;
sowfcols bond_sch_input_cols;
sowfoutput bond_sch_output;
sowfmap bond_sch_input_pos;
sowfmapiter bond_sch_input_pos_iter;
sowfmap bond_sch_input_size;
sowfmapiter bond_sch_input_size_iter;

extern sowmpoutput bond_state_of_world_mp_output;

static bondivmap bond_initial_values_map;
static bondivmap::iterator bond_initial_values_map_iter;
static int num_of_amortize_cost_selections = 5;

extern bool is_asset_initialize;

extern SmartArray <double>& stoch_credit_sprd_tbl;
extern SmartArray <double>& shifted_stoch_credit_sprd_tbl;

// Present value calculation variables
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern int pv_months;
extern int pv_last_cash_flow_month;
extern int pv_asset_defn;
extern int pv_model_point;
extern double pv_initial_years_to_payment;
extern double pv_initial_accrued_interest;
extern double pv_initial_par_value;
extern double pv_interest_savings_monthly_refinancing_rate;
extern bool pv_initialize_interest_savings_table;
extern bool pv_initialize_yield_maintenance_table;
extern SmartArray <double>& pv_cash_flows;
extern SmartArray <double>& pv_interest_savings_after_prepayments;
extern SmartArray <double>& pv_yield_maintenance_cash_flows;
extern SmartArray <double>& pv_yield_maintenance_par_plus_accrued;

// Bond option pricing tables and other bond tables
extern SmartArray <double>& pv_accumulated_cash_flows; 
extern SmartArray <double>& pv_discount_factors;
extern SmartArray <double>& pv_discounted_cash_flows;
extern SmartArray <double>& pv_time_weighted_discounted_cash_flows;
extern SmartArray <double>& pv_call_amount;
extern SmartArray <double>& pv_put_amount;
extern SmartArray <double>& pv_scheduled_principal_payments; // for WAL calculation

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

extern int maximum_t_high_value;
extern int minimum_t_low_value;
#endif // END_EXTERNS

#if 0 // START_CLASS
int sequence_id;
int calculated_t_low;
int calculated_t_high;
struct bondInitialValuesData* initial_values;
int net_yld_at_issue_calc_flag;
double purch_amt;
double pmt_rate_init_guess;
int refinancing_rate_opt_sprd_calc_flag;
int cost_basis_amortzn_mths;
int purch_asset_mp_num;
bool read_sch_file_flag;
bool set_call_sch_flag;
bool set_put_sch_flag;

// Bond model point variables
xstring seg_id;
StrEnum::EnumValue port_defn;
StrEnum::EnumValue sale_class;
xstring issue_date;
xstring maturity_date;
xstring planned_sale_date;
double init_par_val;
double init_cost_basis;
double init_bk_val;
double init_mkt_val;
StrEnum::EnumValue pmt_mode;
double init_pmt_rate;
double par_val_at_issue;
double taxable_pct;
StrEnum::EnumValue call_defn;
xstring call_opt_first_date;
StrEnum::EnumValue call_price_defn;
double yld_maint_addn;
StrEnum::EnumValue put_price_defn;
StrEnum::EnumValue put_defn;
xstring put_opt_first_date;
StrEnum::EnumValue sinking_fund_defn;
xstring adj_reset_category_id;
double adj_reset_scen_yr;
double adj_reset_scen_mult;
double adj_reset_renewal_addn;
xstring adj_next_reset_date;
int adj_reset_mths;
double adj_max_incr_per_reset;
double adj_max_decr_per_reset;
double adj_min_rate;
double adj_max_rate;
double avr_contribn_pct;
double avr_max_pct;
double avr_obj_pct;
double rbc_c1_pct;

// Bond schedule variables
SmartArray <double> call_price_sch;
SmartArray <double> put_price_sch;
SmartArray <double> sinking_fund_sch;

SmartArray <double> psa_base_rate;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
sequence_id = 0;
initial_values = NULL;
net_yld_at_issue_calc_flag = 0;
purch_amt = 0.0;
pmt_rate_init_guess = 0.0;
refinancing_rate_opt_sprd_calc_flag = 0;
cost_basis_amortzn_mths = 0;
purch_asset_mp_num = -1;
read_sch_file_flag = true;
set_call_sch_flag = true;
set_put_sch_flag = true;

// Initialize bond model point variables
seg_id = "Seg";
port_defn = INVESTMENT;
sale_class = AVAILABLE_FOR_SALE; 
issue_date = "1900/01/01";
maturity_date = "1900/01/01";
planned_sale_date = "9999/01/01"; 
init_par_val = 0.0;
init_cost_basis = 0.0;
init_bk_val = 0.0;
init_mkt_val = 0.0;
pmt_mode = SEMI_ANNUAL;
init_pmt_rate = 0.0;
par_val_at_issue = 0.0;
taxable_pct = 0.0;
call_defn = NOT_APPLICABLE;
call_opt_first_date = "9999/01/01";
call_price_defn = PRICE_SCHEDULE; 
yld_maint_addn = 0.0;
put_defn = NOT_APPLICABLE;
put_opt_first_date = "9999/01/01";
sinking_fund_defn = NO;
adj_reset_category_id = "Govt";
adj_reset_scen_yr = 0.25;
adj_reset_scen_mult = 0.0;
adj_reset_renewal_addn = 0.0;
adj_next_reset_date = "9999/01/01";
adj_reset_mths = 12;
adj_max_incr_per_reset = 0.0;
adj_max_decr_per_reset = 0.0;
adj_min_rate = 0.0;
adj_max_rate = 0.0;
avr_contribn_pct = 0.0;
avr_max_pct = 0.0;
avr_obj_pct = 0.0;
rbc_c1_pct = 0.0;

#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
if (PVCFile != NULL)
	PVCFile.close();
#endif // END_TERMINATOR

if (use_mp == NO)
	{
	skipModelPoint();
	return 1;
	}

if (!investing_flag)
	setup_existing_asset();

if (isMainModel)
	{
	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	// Set stoch_flag for rates loading
	stoch_flag = true;

	static bool first_time = true;
	if (first_time)
		{
		first_time = false;
		num_bonds_to_run = calc_num_records_to_run();
		}

	#if defined(ASSET_ONLY_MODEL)
	rates = sm_bond_rates;
	#endif
	sm_bond_cf->rates = rates;	

	maximum_t_high_value = t_high;
	minimum_t_low_value = t_low;
	}
else
	{
	#if defined(ASSET_ONLY_MODEL)
	if (sm_bond_rates && !sm_bond_rates->isShrunk)
		sm_bond_rates->shrink();
	#endif

	rates = asset->rates;
	sm_bond_cf->rates = rates;
	}

if (!isMainModel
	&& !investing_flag
	&& asset->num_bonds_init > -1
	&& getElementNumber() >= asset->num_bonds_init)
	{
	shrink_bond_clone(getElementNumber());
	return 1;
	}

// Grow clones here so that their t_high and t_low values
//   are set correctly before they are shrunk in initialize.
if (bond_pv->isShrunk)
	bond_pv->grow();
if (bond_is->isShrunk)
	bond_is->grow();
if (bond_ym->isShrunk)
	bond_ym->grow();

if (investing_flag)
	purch_asset_mp_num = asset->purch_asset_mp_num;

bool net_yield_at_issue_must_be_calculated = false;

if (is_first_proj_task_loop && existing_asset_indicator )
	{
	if (net_yld_at_issue_flag == YES)
		{
		if (isMainModel)
			net_yield_at_issue_must_be_calculated = true;
		else
			{	
			xstring index_val;
	
			index_val = asset_id + data_grp_id + xstring(data_rec_num());
	
			if ((bond_initial_values_map_iter = bond_initial_values_map.find(index_val))
				== bond_initial_values_map.end())
				net_yield_at_issue_must_be_calculated = true;
			}
		}
	}

if (net_yield_at_issue_must_be_calculated
	|| investing_flag)
	t_low = calculated_t_low = xint(commencement_period);
else
	t_low = calculated_t_low = 0;

t_high = calculated_t_high = xint(maturity_period);

if (investing_flag)
	return 1;

// Check t_low, t_high
if (!isMainModel)
	{
	if (!asset->valid_t_low_t_high(calculated_t_low, calculated_t_high))
		{
		skipModelPoint();
		return 1;
		}
	}

// Data Validation
if (num_of_proj_task_loops == 0 
	|| is_first_proj_task_loop
	|| restore_variables_ind == 1)
	validate_data();

return 1;

}


//@@ END

//@@ START - sub_port_id
// Asset Sub Portfolio Identification                                                                                             
// Column:SUB_PORT_ID
//========================================================
double BOND_ASSET_UDF::bond_asset_sub_port_id(int t) {
//^^^



//^^^

#line 1 "sub_port_id.BOND_ASSET.for"
if (t < commencement_period || (existing_asset_indicator && t < 0) || isMainModel)
	return NO_AVG;

double dur_for_transfer = 0;

if (t <= maturity_period)
	{
	if (asset->asset_sub_port_assign_dur_defn == YEARS_TO_MATURITY)
		{
		dur_for_transfer = (maturity_period - t) / 12.0;
		}
	else if (t <= max(0, commencement_period)
			 || mths_to_next_mkt_val_calc(t) <= 0)
		// don't want to force market value calculation
		{

		//20220613 STW: model efficiency improvement
		if(fast_stat_calc_aig == YES)
		{
			dur_for_transfer = 0;
		}
		else if (asset->asset_sub_port_assign_dur_defn == EFFECTIVE_DURATION)
		{
			dur_for_transfer = eff_dur(t);
		}
		else //if (asset->asset_sub_port_assign_dur_defn == WEIGHTED_AVERAGE_LIFE)
		{
			dur_for_transfer = weighted_avg_life(t);
		}
		}
	}

if (existing_asset_indicator && t == 0)
	return asset->asset_sub_port_assign(t, 1, "Bond", 
		            port_defn,
					category_id,
					existing_asset_indicator,
					dur_for_transfer,
					-1);

if (!existing_asset_indicator && t == commencement_period)
	return asset->asset_sub_port_assign(t, 1, "Bond",
					port_defn,
					category_id,
					existing_asset_indicator,
					dur_for_transfer,
					purch_asset_sub_port);

return asset->asset_sub_port_assign(t, 0, "Bond",
					port_defn,
					category_id,
					existing_asset_indicator,
					dur_for_transfer,
					sub_port_id(t - 1));

}


//@@ END

//@@ START - tax_exempt_inc
// Tax Exempt Income                                                                                             
// Column:TAX_EXEMPT_INC
//========================================================
double BOND_ASSET_UDF::bond_asset_tax_exempt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"tax_exempt_inc",t);
}



//^^^

#line 1 "tax_exempt_inc.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period) 
        return NO_AVG;   

double increase_in_accrued_interest = 0.0;
increase_in_accrued_interest
= bond_cf->accr_int_bef_call(t)
  - bond_cf->accr_int_aft_dflt(t)
  + bond_cf->accr_int_bef_sale(t)
  - bond_cf->accr_int_aft_put(t);

//OID cost basis growth part
double oid_cost_basis_growth = 0.0;
oid_cost_basis_growth 
= max(0.0, cost_basis_bef_call(t) - cost_basis_aft_dflt(t)
           + cost_basis_bef_sale(t) - cost_basis_aft_put(t));

return (bond_cf->int_pmt(t)
		+ bond_cf->sinking_fund_pmt_inc(t)
		+ increase_in_accrued_interest
		+ oid_cost_basis_growth)
	   	* tax_exempt_pct;

}


//@@ END

//@@ START - unrealzd_cap_gain
// Unrealized Capital Gain                                                                                             
// Column:UNREALZD_CAP_GAIN
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"unrealzd_cap_gain",t);
}



//^^^

#line 1 "unrealzd_cap_gain.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_neg_cash_flow_sale(t)
       * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_fund_match_sale
// Unrealized Capital Gain Before Fund Value Matching Asset Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_FUND_MATCH_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(114,"unrealzd_cap_gain_bef_fund_match_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_fund_match_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_neg_cash_flow_sale
// Unrealized Capital Gain Before Negative Cash Flow Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_NEG_CASH_FLOW_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(115,"unrealzd_cap_gain_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_neg_cash_flow_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_rebal_sale
// Unrealized Capital Gain Before Rebalancing Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_REBAL_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(116,"unrealzd_cap_gain_bef_rebal_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_rebal_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_sale
// Unrealized Capital Gain Before Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_bef_sale.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t) - cost_basis_bef_sale(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_gaap_surp
// Unrealized Capital Gain GAAP Surplus                                                                                             
// Column:UNREALZD_CAP_GAIN_GAAP_SURP
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_gaap_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(118,"unrealzd_cap_gain_gaap_surp",t);
}



//^^^

#line 1 "unrealzd_cap_gain_gaap_surp.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_surp_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(119,"unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return 0.0;

double unrealzd_cap_gain_due_to_apprec
= (bk_val_bef_call(t) - cost_basis_bef_call(t))
   - (bk_val_aft_dflt(t) - cost_basis_aft_dflt(t))
   + (bk_val_bef_sale(t) - cost_basis_bef_sale(t))
   - (bk_val_aft_put(t) - cost_basis_aft_put(t));

double unrealzd_cap_gain_from_calls_puts
= (cost_basis_bef_call(t) - bk_val_bef_call(t))
   * bond_cf->call_pct_mthly(t)
  + (cost_basis_bef_call(t) - bk_val_bef_call(t))
     * (1.0 - bond_cf->call_pct_mthly(t))
     * bond_cf->put_pct_mthly(t);

double unrealzd_cap_loss_from_dflt
= (bk_val(t - 1) - cost_basis(t - 1))
   * dflt_pct(t);

return unrealzd_cap_gain_due_to_apprec
	   + unrealzd_cap_gain_from_calls_puts
	   - unrealzd_cap_loss_from_dflt;

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released on Sale                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_released_on_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"unrealzd_cap_gain_released_on_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.BOND_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return unrealzd_cap_gain_bef_sale(t)
       * sold_pct(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_to_bk_ratio
// Unrealized Capital Gain to Book Ratio                                                                                             
// Column:UNREALZD_CAP_GAIN_TO_BK_RATIO
//========================================================
double BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_to_bk_ratio.BOND_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_sale(t) + accr_int_bef_sale(t)) < model_point_amount_threshold)
	return USLIB_MIN_DOUBLE;

return unrealzd_cap_gain_bef_sale(t)
	   / (bk_val_bef_sale(t) + accr_int_bef_sale(t));

}


//@@ END

//@@ START - weighted_avg_life
// Weighted Average Life                                                                                             
// Column:WEIGHTED_AVG_LIFE
//========================================================
double BOND_ASSET_UDF::bond_asset_weighted_avg_life(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(122,"weighted_avg_life",t);
}



//^^^

#line 1 "weighted_avg_life.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->weighted_avg_life; 

if (bond_pv->isShrunk)
	{
	rebase_bond_cash_flow(t,
				PRESENT_VALUE, "bond->weighted_avg_life",
				modelName);

	bond_pv->pv_calc_parameters(t,
					MARKET_VALUE, xint(maturity_period - t));

	bond_pv->pv_tbl_defn = "No Tables";
	}
else
	{
	if (bond_pv->pv_defn != MARKET_VALUE_SHIFTED)
		{
		if (bond_pv->rebase_period < t)
			{
			rebase_bond_cash_flow(t,
						PRESENT_VALUE, "bond->weighted_avg_life",
						modelName);
			}

		bond_pv->pv_calc_parameters(t,
						MARKET_VALUE, xint(maturity_period - t));
		}
	}

return bond_pv->weighted_avg_life_calc(t);

}


//@@ END

//@@ START - weighted_avg_life_opt_sensitivity
// Weighted Average Life Option Sensitivity                                                                                             
// Column:WEIGHTED_AVG_LIFE_OPT_SENSITIVITY
//========================================================
double BOND_ASSET_UDF::bond_asset_weighted_avg_life_opt_sensitivity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(123,"weighted_avg_life_opt_sensitivity",t);
}



//^^^

#line 1 "weighted_avg_life_opt_sensitivity.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

rebase_bond_cash_flow(t,
		INTEREST_SAVINGS,
		"bond->weighted_avg_life_opt_sensitivity",
		modelName);

// save current pv parameters
bond_is->pv_calc_parameters(t, SAVE);

bond_is->pv_calc_parameters(t,
			INTEREST_SAVINGS_BEFORE_CALLS,
			xint(maturity_period - t));

double wal_for_ispv = bond_is->weighted_avg_life_calc(t);

// restore pv parameters
bond_is->pv_calc_parameters(t, RESTORE);

// rebase to reduce sliding windows sizes
// (may be able to handle this later)
rebase_bond_cash_flow(t,
			INTEREST_SAVINGS, "bond->weighted_avg_life_opt_sensitivity", modelName);

return wal_for_ispv;

}


//@@ END

//@@ START - yld_denom
// Yield Denominator                                                                                             
// Column:YLD_DENOM
//========================================================
double BOND_ASSET_UDF::bond_asset_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(124,"yld_denom",t);
}



//^^^

#line 1 "yld_denom.BOND_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return bk_val(t) + accr_int(t);

double asset_yld_denom_factor = 0;

if (bk_val(t - 1) > 0.0)
	{
	double accr_inc_bef_sched_pmt
	= cost_basis_bef_call(t)
	  + accr_int_bef_call(t)
	  - cost_basis_aft_dflt(t)
	  - accr_int_aft_dflt(t)
	  + int_pmt(t)
	  + cost_basis_sched_prin_pmt(t);

	if (bk_val_aft_put(t) + accr_int_aft_put(t) > 0.0)
		{
		double accr_inc_aft_put
		= cost_basis_bef_sale(t) 
		  + accr_int_bef_sale(t)
		  - cost_basis_aft_put(t)
		  - accr_int_aft_put(t);	
	
		asset_yld_denom_factor
		= (1.0 + (accr_inc_bef_sched_pmt)
				 / (bk_val(t - 1) + accr_int(t - 1)))
		  * (1.0 + (accr_inc_aft_put)
				   / (bk_val_aft_put(t)
					  + accr_int_aft_put(t)))
		  - 1.0;
		}
	else
		asset_yld_denom_factor
		= accr_inc_bef_sched_pmt
		  / (bk_val(t - 1) + accr_int(t - 1));
	}

if (asset_yld_denom_factor != 0.0)
	return (accr_inc(t))
		   / asset_yld_denom_factor;

if (bk_val_aft_put(t) + accr_int_aft_put(t) > 0.0)
	return bk_val(t - 1) +  accr_int(t - 1);

return (bk_val(t - 1) + accr_int(t - 1));

}


//@@ END

//@@ START - yld_numer
// Yield Numerator                                                                                             
// Column:YLD_NUMER
//========================================================
double BOND_ASSET_UDF::bond_asset_yld_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(125,"yld_numer",t);
}



//^^^

#line 1 "yld_numer.BOND_ASSET.for"
//20220519 STW: Restored to be original US library code without duration weighted adjustment
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->yld_numer;

if (existing_asset_indicator && t == 0)
	return yld_numer(t + 1);

return accr_inc(t);  


}


//@@ END

//@@ START - yld_numer_adj_aig
// Yield Numerator with duration weighted adjustment                                                                                             
// Column:YLD_NUMER_ADJ_AIG
//========================================================
double BOND_ASSET_UDF::bond_asset_yld_numer_adj_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(126,"yld_numer_adj_aig",t);
}



//^^^

#line 1 "yld_numer_adj_aig.BOND_ASSET.for"
//20220519 STW: Revised to be Yield Numerator with duration weighted adjustment
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->yld_numer;

if (existing_asset_indicator && t == 0)
	return yld_numer_adj_aig(t + 1);


// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	//HYH 5/26/2021, per email from Josh @ WTW on 5/26/2021
	double pmt_rate_adj = bond_cf->pmt_rate(t);

	double accr_inc_orig = bond_cf->accr_int_direct(t, 1.0, pmt_rate_adj);
	if (accr_inc_orig == 0) 
		accr_inc_orig = pmt_rate_adj / pmt_freq;
	 accr_inc_orig -= bond_cf->accr_int_direct(t - 1, 1.0, pmt_rate_adj);

	if (!valn_flag) //20240814 Apply dur_wtd_sprd_adj_aig in outer loop only
	{
		pmt_rate_adj += dur_wtd_sprd_adj_aig;
	}
	double accr_inc_adj = bond_cf->accr_int_direct(t, 1.0, pmt_rate_adj);
	if (accr_inc_adj == 0) 
		accr_inc_adj = pmt_rate_adj / pmt_freq;
	 accr_inc_adj -= bond_cf->accr_int_direct(t - 1, 1.0, pmt_rate_adj);
 
	double duration_weighted_sprd_mthly = accr_inc_adj - accr_inc_orig;

	return accr_inc(t)
		  + (duration_weighted_sprd_mthly * bond_cf->par_val(t-1)); //AIG - ADD SPREAD TO EARNED AMOUNT HERE WHICH FLOWS INTO TOTAL NER ON SEGMENT LEVEL
}
else
{
	double duration_weighted_sprd_mthly = convert_rate_basis(dur_wtd_sprd_adj_aig, NOMINAL_SEMIANNUAL, ACTUAL_MONTHLY);

	if(valn_flag) //20240814 Apply dur_wtd_sprd_adj_aig in outer loop only
	{
		duration_weighted_sprd_mthly = 0.;
	}

	return accr_inc(t)
		  + (duration_weighted_sprd_mthly * yld_denom(t)); //AIG - ADD SPREAD TO EARNED AMOUNT HERE WHICH FLOWS INTO TOTAL NER ON SEGMENT LEVEL
}

}


//@@ END

//@@ START - accr_int_per_par_unit
// Accrued Interest Per Par Value Unit                                                                                             
// Calculated Variable:ACCR_INT_PER_PAR_UNIT
//========================================================
double BOND_ASSET_UDF::bond_asset_accr_int_per_par_unit() {
//^^^


#line 1 "accr_int_per_par_unit.BOND_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

return (pow(1.0 + coupon_rate_at_issue / pmt_freq,
			yrs_since_last_pmt * pmt_freq)
		- 1.0);

}


//@@ END

//@@ START - amortzn_cost_period
// Amortization Cost Period                                                                                             
// Calculated Variable:AMORTZN_COST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_amortzn_cost_period() {
//^^^


#line 1 "amortzn_cost_period.BOND_ASSET.for"
if (existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->amortzn_cost_period;

if (amortzd_cost_period_defn == TO_MATURITY
	|| amortzd_cost_period_defn == TO_YIELD_TO_WORST)
	return maturity_period;

if (amortzd_cost_period_defn == TO_FIRST_CALL)
	return min(maturity_period, call_first_period);

if (amortzd_cost_period_defn == TO_FIRST_PAR_CALL)
	return min(maturity_period, call_par_first_period);

if (amortzd_cost_period_defn == TO_FIRST_PUT)
	return min(maturity_period, put_first_period);

if (amortzd_cost_period_defn == TO_FIRST_PAR_PUT)
	return min(maturity_period, put_par_first_period);

return maturity_period;

}


//@@ END

//@@ START - asset_detail_rpt_flag
// Asset Detail Report Flag                                                                                             
// Calculated Variable:ASSET_DETAIL_RPT_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_asset_detail_rpt_flag() {
//^^^


#line 1 "asset_detail_rpt_flag.BOND_ASSET.for"
if (eq(asset_detail_rpt_cusip_id, "ALL")
	|| inlist(asset_id, asset_detail_rpt_cusip_id))
	return YES;

return NO;

}


//@@ END

//@@ START - asset_fund_index
// Asset Fund Index                                                                                             
// Calculated Variable:ASSET_FUND_INDEX
//========================================================
int BOND_ASSET_UDF::bond_asset_asset_fund_index() {
//^^^


#line 1 "asset_fund_index.BOND_ASSET.for"
if (port_defn == INVESTMENT)
	return INVESTMENT_FUND_INDEX;

// else set to "Investment" default value
makeRunLogYellow();
log_screen << "Warning: Invalid portfolio definition (" << port_defn
		   <<") for bond ID = " << asset_id
		   << "." << MSG_ERROR;
log_screen << " ... Portfolio definition has been reset to Investment. " << MSG_ERROR;

port_defn = INVESTMENT;

return INVESTMENT_FUND_INDEX;

}


//@@ END

//@@ START - call_first_period
// Call First Period                                                                                             
// Calculated Variable:CALL_FIRST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_call_first_period() {
//^^^


#line 1 "call_first_period.BOND_ASSET.for"
if (call_defn == NOT_APPLICABLE)
	return 9999;

int initial_call_period = 0;
int first_call_schedule_period = 0;

if (existing_asset_indicator)
	{
	initial_call_period
	= min(get_yr_from_date(call_opt_first_date) - proj_start_yr,
		  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
		  + get_mth_from_date(call_opt_first_date) - proj_start_mth + 1;

	if (call_price_sch_flag)
		{
		for(first_call_schedule_period = 0;
			first_call_schedule_period < maturity_period
			&& (call_price_sch[first_call_schedule_period] < rate_ratio_threshold);
			first_call_schedule_period++){}
		}

	int local_first_call_period = max(initial_call_period, first_call_schedule_period);

	if (local_first_call_period > 0	|| call_defn == AMERICAN)
		return local_first_call_period;

	return maturity_period;
	}

double local_call_protect_yrs = company->sm_inv_strategy[seg_num]->purch_bond_call_protect_yrs;

if (((double)((int)(12 * local_call_protect_yrs)))
	 == (12 * local_call_protect_yrs))
	initial_call_period
	= commencement_period
	  + min(local_call_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12;
else
	initial_call_period
	= commencement_period
	  + min(local_call_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12
	  + 1;

if (call_price_sch_flag)
	{
	for (first_call_schedule_period = commencement_period;
		 first_call_schedule_period < maturity_period
		 && (call_price_sch[first_call_schedule_period - start_period] < rate_ratio_threshold);
		 first_call_schedule_period++){}
	
	return max(initial_call_period, first_call_schedule_period);
	}

return initial_call_period;

}


//@@ END

//@@ START - call_par_first_period
// Call at Par Value First Period                                                                                             
// Calculated Variable:CALL_PAR_FIRST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_call_par_first_period() {
//^^^


#line 1 "call_par_first_period.BOND_ASSET.for"
if (call_defn == NOT_APPLICABLE)
	return 0;

int first_scheduled_par_call_period = 0;

if (existing_asset_indicator)
	{
	if (call_price_defn == PRICE_SCHEDULE)
		{
		for (first_scheduled_par_call_period = 0;
			 first_scheduled_par_call_period < maturity_period
			 && (call_price_sch[first_scheduled_par_call_period] < rate_ratio_threshold
				 || (fabs(call_price_sch[first_scheduled_par_call_period] - 1.0)
					 > rate_ratio_threshold));
			first_scheduled_par_call_period++){}

		return max(call_first_period, first_scheduled_par_call_period);
		}

	return maturity_period;
	}

// new purchase
double local_call_protect_yrs = company->sm_inv_strategy[seg_num]->purch_bond_call_protect_yrs;
double local_yrs_to_first_par_call = company->sm_inv_strategy[seg_num]->purch_bond_first_par_call_yr;

int initial_call_period = 0;

if (((double)((int)(12 * local_call_protect_yrs)))
	 == (12 * local_call_protect_yrs))
	initial_call_period
	= commencement_period
	  + min(local_call_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12;
else
	initial_call_period
	= commencement_period
	  + min(local_call_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12
	  + 1;

if (call_price_defn == PRICE_SCHEDULE)
	{
	for (first_scheduled_par_call_period = commencement_period;
		 first_scheduled_par_call_period < maturity_period
		 && (call_price_sch[first_scheduled_par_call_period - commencement_period] < rate_ratio_threshold
			 || (fabs(call_price_sch[first_scheduled_par_call_period - commencement_period] - 1.0)
				 > rate_ratio_threshold));
		first_scheduled_par_call_period++){}
	
	return max(call_first_period, first_scheduled_par_call_period);
	}

if (call_price_defn == RELATED_TO_COUPON)
	{
	int months_to_first_zero_call_premium_related_to_coupon;

	if (((double)((int)(12 * local_yrs_to_first_par_call)))
		 == (12 * local_yrs_to_first_par_call))
		months_to_first_zero_call_premium_related_to_coupon
		= min(local_yrs_to_first_par_call,
		      MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
		  * 12;
	else
		months_to_first_zero_call_premium_related_to_coupon
		= min(local_yrs_to_first_par_call,
		      MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
		  * 12
		  + 1;

	return max(initial_call_period,
	           commencement_period + months_to_first_zero_call_premium_related_to_coupon);
	}

return maturity_period;

}


//@@ END

//@@ START - call_prem_grading_mths
// Call Premium Grading Months                                                                                             
// Calculated Variable:CALL_PREM_GRADING_MTHS
//========================================================
int BOND_ASSET_UDF::bond_asset_call_prem_grading_mths() {
//^^^


#line 1 "call_prem_grading_mths.BOND_ASSET.for"
if (existing_asset_indicator)
	return 0;

// Lookup key is purch_asset_id

int initial_call_period
= commencement_period 
  + min(company->sm_inv_strategy[seg_num]->purch_bond_call_protect_yrs,
		MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

int first_zero_call_premium_related_to_coupon_period 
= max(commencement_period 
	  + min(company->sm_inv_strategy[seg_num]->purch_bond_first_par_call_yr,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
	  initial_call_period);

return max(1,
           first_zero_call_premium_related_to_coupon_period - initial_call_period);

}


//@@ END

//@@ START - call_prem_related_to_coupon_rate
// Call Premium Related to Coupon Rate                                                                                             
// Calculated Variable:CALL_PREM_RELATED_TO_COUPON_RATE
//========================================================
double BOND_ASSET_UDF::bond_asset_call_prem_related_to_coupon_rate() {
//^^^


#line 1 "call_prem_related_to_coupon_rate.BOND_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

// Lookup key is purch_asset_id

int initial_call_period
= commencement_period
  + min(company->sm_inv_strategy[seg_num]->purch_bond_call_protect_yrs,
		MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

int first_zero_call_premium_related_to_coupon_period
= max(commencement_period
	  + min(company->sm_inv_strategy[seg_num]->purch_bond_first_par_call_yr,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
	  initial_call_period);

if (first_zero_call_premium_related_to_coupon_period > initial_call_period)
	{
	if (bond_pv->isShrunk
		|| bond_pv->rebase_period < commencement_period)
		{
		rebase_bond_cash_flow(commencement_period,
				PRESENT_VALUE,
				"bond->mkt_val_bef_sale",
				modelName);
		}

	double weighted_average_life_local
	= bond_pv->weighted_avg_life_calc(commencement_period);

	double local_refinancing_rate
	= category_refinancing_rate(commencement_period, 
			maturity_period - commencement_period,  
			weighted_average_life_local,
			0.0, // opt_sprd
			NOMINAL_SEMIANNUAL,
			NO_SHIFT); // shift_defn
 
	double preliminary_coupon_rate_at_issue;
	if (company->sm_inv_strategy[seg_num]->purch_bond_rate_defn != REFINANCING_RATE)
		preliminary_coupon_rate_at_issue
		= max(0.0, rates->get_int_rate(commencement_period,
		                  adj_reset_category_id,
		                  GET_YIELD_RATE,
		                  adj_reset_scen_yr,
		                  0.0,
		                  pmt_freq,
		                  NO_SHIFT,portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		           * adj_reset_scen_mult
		           + company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_addn_init);
	else
		preliminary_coupon_rate_at_issue
		= max(0.0, convert_rate_basis(local_refinancing_rate,
						NOMINAL_SEMIANNUAL,
						pmt_freq)
				   - company->sm_inv_strategy[seg_num]->purch_bond_rate_diff);	 	

	return preliminary_coupon_rate_at_issue
		   * company->sm_inv_strategy[seg_num]->purch_bond_call_prem_mult
		   + company->sm_inv_strategy[seg_num]->purch_bond_call_prem_addn;
	}

return 0.0;

}


//@@ END

//@@ START - call_price_sch_flag
// Call Price Schedule Flag                                                                                             
// Calculated Variable:CALL_PRICE_SCH_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_call_price_sch_flag() {
//^^^


#line 1 "call_price_sch_flag.BOND_ASSET.for"
if (call_defn == NOT_APPLICABLE
	|| call_price_defn != PRICE_SCHEDULE)
	return 0;

if (!set_call_sch_flag) // already set the schedule, no need to set it again
	return 1;
	
set_call_sch_flag = false;

if (existing_asset_indicator == PRIOR_PURCH 
	|| existing_asset_indicator == PROXY_BOND)
	{
	if (read_sch_file_flag)
		read_sch_file();

	return 1;
	}

if (call_price_sch.size() < sch_array_size)
	call_price_sch.resize(sch_array_size);

for (int month = start_period; month <= maturity_period; month++)
	{
	if (existing_asset_indicator == INIT_MP)
		call_price_sch[month - start_period] = call_price_pct.AtTime(month);
	else // existing_asset_indicator == NEW_PURCH
		{
		company->sm_inv_strategy[seg_num]->mths_since_issue = month - start_period;							
		call_price_sch[month - start_period] = company->sm_inv_strategy[seg_num]->purch_bond_call_price_pct;
		}
	}

return 1;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_commencement_period() {
//^^^


#line 1 "commencement_period.BOND_ASSET.for"
if (investing_flag)
	return investment_period;

int adjusted_bond_issue_year = 0;
int adjusted_bond_issue_month = 0;
int mths_since_issue = 0;

if (existing_asset_indicator)
	{
	int issue_yr = get_yr_from_date(issue_date);
	int issue_mth = get_mth_from_date(issue_date);

	if ((issue_yr <= 1900 && issue_mth == 1)
		|| par_val_at_issue == 0.0
		|| opt_int_diff_defn != NET_YIELD_AT_ISSUE)
		return 0;

	mths_since_issue
	= min(proj_start_yr - issue_yr,
		  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
	  + proj_start_mth
	  - issue_mth - 1;

	if ((mths_since_issue < 0)
		|| ((maturity_period + mths_since_issue) 
			% pmt_mths) != 0)
		{
		// Align issue date with payment period.
		mths_since_issue
		= max(0, mths_since_issue) 
				 + (((((maturity_period
						+ max(0, mths_since_issue)) 
					   / pmt_mths) + 1) 
					 * pmt_mths) 
					- (maturity_period
					   + max(0, mths_since_issue))) 
		  % pmt_mths;

		if (((mths_since_issue % 12) + 1) < proj_start_mth)
			{
			adjusted_bond_issue_year
			= proj_start_yr - (mths_since_issue / 12);

			adjusted_bond_issue_month
			= proj_start_mth - (mths_since_issue % 12) - 1;
			}
		else
			{
			adjusted_bond_issue_year
			= proj_start_yr - (mths_since_issue / 12) - 1;

			adjusted_bond_issue_month
			= proj_start_mth + 12 - (mths_since_issue % 12) - 1;
			}

		if (issue_yr > 1900 && issue_mth > 1)
			{
			makeRunLogYellow();
			log_screen << "Warning. Issue date is inconsistent with maturity date and "
					   << "payment frequency or model start date. "
					   << "Issue date has been reset to " << adjusted_bond_issue_month
					   << "/" << adjusted_bond_issue_year
					   << "Existing bond identifier = " << asset_id
					   << MSG_ERROR;
			}
		}
	else
		{
		adjusted_bond_issue_year = issue_yr;
		adjusted_bond_issue_month = issue_mth; 
		}

	return (adjusted_bond_issue_year - proj_start_yr) * 12
		   + adjusted_bond_issue_month - proj_start_mth + 1;
	}

return 0;

}


//@@ END

//@@ START - coupon_rate_at_issue
// Coupon Rate at Issue                                                                                             
// Calculated Variable:COUPON_RATE_AT_ISSUE
//========================================================
double BOND_ASSET_UDF::bond_asset_coupon_rate_at_issue() {
//^^^


#line 1 "coupon_rate_at_issue.BOND_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

bond_pv->resetValues();

if (asset_detail_rpt_pv_flag(commencement_period))
	asset_detail_log_rebase_reset(commencement_period,
	                              "bond_pv->resetValues",
	                              "bond->coupon_rate_at_issue",
	                              asset_id, modelName);

rebase_bond_cash_flow(commencement_period,
		PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

bond_pv->pv_calc_parameters(commencement_period,
			MARKET_VALUE, xint(maturity_period - commencement_period));

// Lookup key is purch_asset_id

if (company->sm_inv_strategy[seg_num]->purch_bond_rate_defn != REFINANCING_RATE)
	{
	pmt_rate_init_guess
	= max(0.0,
	     rates->get_int_rate(commencement_period,
	            company->sm_inv_strategy[seg_num]->purch_bond_adj_category_id,
	            GET_YIELD_RATE,
	            company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_yr,
	            0.0,
	            pmt_freq,
	            NO_SHIFT,portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	     * company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_mult
	     + company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_addn_init);\

	return pmt_rate_init_guess;
	}

if (refinancing_rate_defn_calc != CATEGORY_YIELD_TO_WAL_OPTION_SPREAD
	|| (call_first_period >= maturity_period
		&& put_first_period >= maturity_period))
	{
	bond_pv->pv_tbl_defn = "No Tables";
	bond_pv->opt_pricing_defn = "No";
	bond_pv->pv_init_accr_int_wanted = "No"; // Cannot calculate accrued interest until pmt_rate is available

	double weighted_avg_life
	= bond_pv->weighted_avg_life_calc(commencement_period);

	double local_refinancing_rate
	= category_refinancing_rate(commencement_period,
	                   maturity_period - commencement_period,
	                   weighted_avg_life,
	                   0.0, // Option spread
	                   NOMINAL_SEMIANNUAL,
	                   NO_SHIFT); // Shift_defn
 
	pmt_rate_init_guess
	= max(0.0,
	      convert_rate_basis(local_refinancing_rate,
	                         NOMINAL_SEMIANNUAL,
	                         pmt_freq)
	      - company->sm_inv_strategy[seg_num]->purch_bond_rate_diff);

	return pmt_rate_init_guess;
	}

// Else is an option bond so must solve for coupon rate
// Begin calculation of option spread used to adjust payment rate
refinancing_rate_opt_sprd_calc_flag = 1;

double target_value = 0.0;
double initial_payment_rate = 0;
double initial_value = 0;
double final_pmt_rate = 0;
int maximum_iterations = 0;
double tolerance = 0;
double low_rate = 0;
double high_rate = 0;
double adjustment_factor = 0;
int decrease_value = 0;
int increase_value = 0;
double low_value = 0;
int decrease_rate = 0;
int increase_rate = 0;
double high_value = 0;
int loop = 0;
double guess_rate = 0;
double guess_value = 0;
int done = 0;
double value_factor = 0;
double spread_factor = 0;
double first_difference_1 = 0;
double first_difference_2 = 0;
double second_difference = 0;
double preliminary_guess_rate = 0;
xstring interpolation_code = "";

#define MAX_Iterations 10

bond_pv->pv_tbl_defn = "No Tables";
bond_pv->opt_pricing_defn = "Yes";

double weighted_avg_life
= bond_pv->weighted_avg_life_calc(commencement_period);

bond_pv->resetValues();

if (asset_detail_rpt_pv_flag(commencement_period))
	asset_detail_log_rebase_reset(commencement_period,
	                              "bond_pv->resetValues",
	                              "bond->coupon_rate_at_issue",
	                              asset_id, modelName);

rebase_bond_cash_flow(commencement_period,
		PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

bond_pv->pv_calc_parameters(commencement_period,
			MARKET_VALUE, xint(maturity_period - commencement_period));

double local_refinancing_rate
= category_refinancing_rate(commencement_period,
                   maturity_period - commencement_period,
                   weighted_avg_life,
                   0.0, // Option spread
                   NOMINAL_SEMIANNUAL,
                   NO_SHIFT); // shift_defn
		
pmt_rate_init_guess
= max(0.0,
      convert_rate_basis(local_refinancing_rate,
                         NOMINAL_SEMIANNUAL,
                         pmt_freq)
	  - company->sm_inv_strategy[seg_num]->purch_bond_rate_diff);
 
adj_max_rate
= pmt_rate_init_guess
  + company->sm_inv_strategy[seg_num]->purch_bond_adj_max_above_init;

adj_min_rate
= pmt_rate_init_guess
  - company->sm_inv_strategy[seg_num]->purch_bond_adj_max_below_init;

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCounter++;
	PVCText << PVCounter 
			<< "-->Begin Coupon Rate At Issue"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " Cal yr=" << xint(cal_yr(commencement_period))
			<< " Cal mth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	}

double spread_to_spot
= rates->get_int_rate(commencement_period,
                      category_id,
                      GET_SPOT_SPREAD,
                      weighted_avg_life,
                      0.0,
                      NOMINAL_SEMIANNUAL,
                      NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

// Check size is big enough
if (pv_accumulated_cash_flows.size() < maturity_period - commencement_period + 1)
	{
	pv_accumulated_cash_flows.resize(maturity_period - commencement_period + 1);
	pv_discount_factors.resize(maturity_period - commencement_period + 1);
	pv_discounted_cash_flows.resize(maturity_period - commencement_period + 1);
	pv_time_weighted_discounted_cash_flows.resize(maturity_period - commencement_period + 1);
	}

double base_modified_duration = 0;
double temp = 0;
double base_price
= bond_pv->pv_calc(commencement_period,
                   0.0,
                   temp, // Calculated derivative
                   base_modified_duration);

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCText << "BasePrice," << write_string(base_price, PVCLen, PVCSigDig) << endl 
			<< "BaseModDur," << write_string(base_modified_duration, PVCLen, PVCSigDig);
	asset_detail_rpt_pv_output();
	}

// Calculate call and put option prices
double call_price = 0;
double put_price = 0;

if (call_first_period < maturity_period)
	call_price
	= bond_pv->call_opt_price_calc(commencement_period, NO_SHIFT);

if (put_first_period < maturity_period)
	put_price
	= bond_pv->put_opt_price_calc(commencement_period, NO_SHIFT);
   
double price = base_price - call_price + put_price;
double calculated_option_spread = 0;
double guess_spread = 0;

initial_payment_rate = pmt_rate_init_guess;
initial_value = base_price - call_price + put_price;

if (initial_value == target_value)
	final_pmt_rate = pmt_rate_init_guess;
else // must solve for the correct coupon rate at issue
	{
	maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;
	tolerance = model_point_amount_threshold;
	low_rate = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;
	high_rate = SOLVE_FOR_SPREAD_LOWEST_SPREAD;
	target_value = base_price;

	if (asset_detail_rpt_pv_flag(commencement_period))
		{
		PVCounter++;
		PVCText << PVCounter
				<< "--> Begin Solving for Coupon At Issue"
				<< " for " << asset_id
				<< " |" << modelName
				<< " T=" <<xint(cal_yr(commencement_period))
				<< " M=" << xint(cal_mth(commencement_period));
		asset_detail_rpt_pv_output();
	
		if (asset_detail_rpt_pv_defn == YES)
			PVCFile << "Initial_Value,"	<< write_string(initial_value, PVCLen, PVCSigDig) << endl
					<< "Target_Value," << write_string(target_value, PVCLen, PVCSigDig) << endl;
		}

	// reduce tolerance if target is too large
	if (ceil(log10(fabs(target_value))) > 9)
		tolerance = tolerance * pow(10.0, ceil(log10(fabs(target_value))) - 9);

	adjustment_factor = 0.9;

	if (initial_value < target_value)
		{
		decrease_value = 0;
		increase_value = 1;
		low_rate = initial_payment_rate;
		low_value = initial_value;
		decrease_rate = 0;
		increase_rate = 1;
		}
	else
		{
		decrease_value = 1;
		increase_value = 0;
		high_rate = initial_payment_rate;
		high_value = initial_value;
		decrease_rate = 1;
		increase_rate = 0;
		}

	for (loop = 0;
		loop < maximum_iterations
			&& (decrease_rate < 2 || increase_rate < 2);
		loop++)
		{
		if (increase_rate == 1)
			guess_rate = min(.9999, (adjustment_factor + low_rate) 
						             / adjustment_factor);
		else
			guess_rate
				= max(0.0, high_rate
						   - (1 - pow(adjustment_factor, loop + 1))
							 * (NOMINAL_SEMIANNUAL 
								+ high_rate));

		// need to reset both models so new values will be calculated
		bond_pv->pv_tbl_defn = "Initialize Tables";
		bond_pv->opt_pricing_defn = "Yes";

		bond_pv->resetValues();
		if (asset_detail_rpt_pv_flag(commencement_period))
			asset_detail_log_rebase_reset(commencement_period,
					"bond_pv->resetValues",
					"bond->coupon_rate_at_issue",
					bond->asset_id, modelName);

		bond_pv->rebase_period = -1;
		rebase_bond_cash_flow(commencement_period,
				PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

		pmt_rate_init_guess = guess_rate;
		
		adj_max_rate
		= pmt_rate_init_guess
		  + company->sm_inv_strategy[seg_num]->purch_bond_adj_max_above_init;

		adj_min_rate
		= pmt_rate_init_guess
		  - company->sm_inv_strategy[seg_num]->purch_bond_adj_max_below_init;
		
		base_price
		= bond_pv->pv_calc(commencement_period, 
						0.0,
						temp,  // calculated_derivative
						base_modified_duration
						);
		
		//calculate call and put option prices
		if (call_first_period < maturity_period)
			call_price
			= bond_pv->call_opt_price_calc(commencement_period, NO_SHIFT);
		
		if (put_first_period < maturity_period)
			put_price
			= bond_pv->put_opt_price_calc(commencement_period, NO_SHIFT);
		   
		guess_value = base_price - call_price + put_price;

		if (guess_rate == 0.0)
			{
			if (guess_value > target_value)
				{
				makeRunLogYellow();
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "Warning. Cannot solve for payment rate such that the price"
						 << " of " << asset_id
						 << " |" << modelName
						 << " equals " << target_value
						 << " at issue." 
						 << " Price at payment rate 0.0 is " << guess_value
						 << " Payment rate has been set to zero. Please check your input."
						 << MSG_ERROR;
				log_screen.unsetf(ios::fixed);

				final_pmt_rate = 0.0;
				goto reset_parameters;
				}
			}

		if (decrease_value == 1)
			{
			if (guess_value >= high_value)
				{
				// If we are not getting closer,
				// change direction of increment to spread.
				decrease_rate++;
				increase_rate++;
				}
			else
				{
				if (guess_value > target_value)
					{
					// Reset high value and corresponding spread.
					high_rate = guess_rate;
					high_value = guess_value;
					}
				else
					// Otherwise, exit for loop.
					loop = maximum_iterations;
				}
			}

		if (increase_value == 1)
			{
			if (guess_value <= low_value)
				{
				// If we are not getting closer,
				// change direction of increment to spread.
				decrease_rate++;
				increase_rate++;
				}
			else
				{
				if (guess_value < target_value)
					{
					// Reset low value and corresponding spread.
					low_rate = guess_rate;
					low_value = guess_value;
					}
				else
					// Otherwise, exit for loop. 
					loop = maximum_iterations;
				}
			}
		}

	if (decrease_value > 1 && increase_value > 1)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning. Cannot solve for payment rate"
				 << " of " << asset_id
				 << " |" << modelName
				 << " at issue."
				 << " Using guess rate " << convert_rate_basis(guess_rate, NOMINAL_SEMIANNUAL, EFFECTIVE_ANNUAL)
				 << " Target value " << target_value
				 << " is less than guess value " << guess_value 
				 << " Payment rate has been set to zero. Please check your input."
				 << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		final_pmt_rate = 0.0;
		goto reset_parameters;
		}

	if (increase_value == 1)
		{
		high_rate = guess_rate;
		high_value = guess_value;
		}
	else
		{
		low_rate = guess_rate;
		low_value = guess_value;
		}
	   
	if (high_value == low_value)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning. Cannot solve for payment rate such that the price"
				 << " of " << asset_id
				 << " |" << modelName
				 << " equals " << target_value
				 << " at issue." 
				 << " Price at payment rate 0.0 is " << guess_value
				 << " Payment rate has been set to zero. Please check your input."
				 << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		final_pmt_rate = 0.0;
		goto reset_parameters;
		}

	for (loop = 0; loop < maximum_iterations + 1; loop++)
		{
		if (loop > 0)
			{
			// Calculate final payment rate based on calculated low,
			// merge and high payment rates using the following difference table.  
			// PV Rate 1st Difference 2nd Difference  
			// --------- ------ ------------------------------  
			// LowVal l  
			// prem_pattern_ratio - l  
			// A = ---------------
			// GueVal - LowVal B - A  
			// GueVal prem_pattern_ratio C = ---------------
			// h - prem_pattern_ratio HghVal - LowVal  
			// B = ---------------
			// HghVal - GueVal  
			// HghVal h
			// NewRate = l + (TargVal - LowVal)  * A
			// + (TargVal - LowVal)  * (TargVal - GueVal)  * C  
			// If NewRate is out of bounds, use bisection. For first and
			// last pass use linear interpolation.  
			// This adjustment is being made because of nonlinear
			// dependence of the duration on the planned factor.  

			first_difference_1
			= (guess_rate - low_rate) / (guess_value - low_value);

			first_difference_2
			= (high_rate - guess_rate) / (high_value - guess_value);

			second_difference
			= (first_difference_2 - first_difference_1)
			  / (high_value - low_value);

			preliminary_guess_rate
			= low_rate + (target_value - low_value) * first_difference_1
			  + (target_value - low_value)
			    * (target_value - guess_value)
				* second_difference;

			if (guess_value < target_value)
				{
				low_value = guess_value;
				low_rate = guess_rate;
				}
			else
				{
				high_value = guess_value;
				high_rate = guess_rate;
				}
			}

		if (loop > 0
			&& ((low_rate < high_rate 
				 && preliminary_guess_rate < high_rate
				 && preliminary_guess_rate > low_rate)
				|| (low_rate > high_rate
					&& preliminary_guess_rate > high_rate
					&& preliminary_guess_rate < low_rate)))
			{
			// quadratic interpolation
			guess_rate = preliminary_guess_rate;
			if (asset_detail_rpt_pv_flag(commencement_period))
				interpolation_code = "QI";
			}
		else if (loop > 0 && loop < maximum_iterations)
			{
			//  bisection
			guess_rate = low_rate + (high_rate - low_rate) / 2.0;
			if (asset_detail_rpt_pv_flag(commencement_period))
				interpolation_code = "BI";
			}
		else
			{
			//  linear interpolation
			guess_rate
			= low_rate
			  + (high_rate - low_rate)
				* (target_value - low_value)
				  / (high_value - low_value);
			if (asset_detail_rpt_pv_flag(commencement_period))
				interpolation_code = "LI";
			}

		if (loop < maximum_iterations)
			{
			if (asset_detail_rpt_pv_flag(commencement_period))
				{
				PVCText << " ::: " << interpolation_code
						<< " Loop=" << loop
						<< " for " << asset_id
						<< " |" << modelName
						<< " T=" << xint(cal_yr(commencement_period))
						<< " M=" << xint(cal_mth(commencement_period));
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_rpt_pv_output();
				PVCText << "Low_Rate," << write_string(low_rate, PVCLen, PVCSigDig) << endl
						<< "High_Value," << write_string(high_rate, PVCLen, PVCSigDig) << endl
						<< "High_Rate,"	<< write_string(high_rate, PVCLen, PVCSigDig) << endl
						<< "Low_Value,"	<< write_string(low_value, PVCLen, PVCSigDig) << endl
						<< "Guess_Rate," << write_string(guess_rate, PVCLen, PVCSigDig) << endl;
				asset_detail_rpt_pv_output();
				}

			pmt_rate_init_guess = guess_rate;

			adj_max_rate
			= pmt_rate_init_guess
			  + company->sm_inv_strategy[seg_num]->purch_bond_adj_max_above_init;

			adj_min_rate
			= pmt_rate_init_guess
			  - company->sm_inv_strategy[seg_num]->purch_bond_adj_max_below_init;

			// need to reset both models so new values will be calculated
			bond_pv->pv_tbl_defn = "Initialize Tables";
			bond_pv->opt_pricing_defn = "Yes";

			bond_pv->resetValues();
			if (asset_detail_rpt_pv_flag(commencement_period))
				asset_detail_log_rebase_reset(commencement_period,
						"bond_pv->resetValues",
						"bond->coupon_rate_at_issue",
						bond->asset_id, modelName);

			bond_pv->rebase_period = -1;
			rebase_bond_cash_flow(commencement_period,
					PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

			base_price
			= bond_pv->pv_calc(commencement_period, 
							0.0,
							temp,  // calculated_derivative
							base_modified_duration
							);
			
			//calculate call and put option prices
			if (call_first_period < maturity_period)
				call_price
				= bond_pv->call_opt_price_calc(commencement_period, NO_SHIFT);
			
			if (put_first_period < maturity_period)
				put_price
				= bond_pv->put_opt_price_calc(commencement_period, NO_SHIFT);
			   
			guess_value = base_price - call_price + put_price;

			if (asset_detail_rpt_pv_flag(commencement_period))
				{
				PVCText << " ::: " << interpolation_code
						<< " Loop=" << loop
						<< " for " << asset_id
						<< " |" << modelName
						<< " T=" << xint(cal_yr(commencement_period))
						<< " M=" << xint(cal_mth(commencement_period)) << endl
						<< "GsRate," << write_string(guess_rate, PVCLen, PVCSigDig) << endl
						<< "GsValue," << write_string(guess_value, PVCLen, PVCSigDig) << endl;
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_rpt_pv_output();
				PVCText << "Low_Rate," << write_string(low_rate, PVCLen, PVCSigDig) << endl
						<< "High_Value," << write_string(high_value, PVCLen, PVCSigDig) << endl
						<< "High_Rate," << write_string(high_rate, PVCLen, PVCSigDig) << endl
						<< "Low_Value," << write_string(low_value,PVCLen,PVCSigDig) << endl;
				asset_detail_rpt_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				loop = 999;
			}	// endif
		}	// end_for

	// Restore asset variables.
	reset_parameters:
	bond_pv->resetValues();
	if (asset_detail_rpt_pv_flag(commencement_period))
		asset_detail_log_rebase_reset(commencement_period,
				"bond_pv->resetValues",
				"bond->coupon_rate_at_issue",
				bond->asset_id, modelName);

	bond_pv->rebase_period = -1;
	rebase_bond_cash_flow(commencement_period,
			PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

	final_pmt_rate = guess_rate;

	if (asset_detail_rpt_pv_flag(commencement_period))
		{
		PVCText << PVCounter
				<< "--> End Solving for Coupon Rate At Issue ("
				<< write_string(final_pmt_rate, PVCLen, PVCSigDig)
				<< ") for " << asset_id
				<< " |" << modelName
				<< " T=" <<xint(cal_yr(commencement_period))
				<< " M=" << xint(cal_mth(commencement_period));
		asset_detail_rpt_pv_output();
		PVCounter--;
		}
	}	// endif

refinancing_rate_opt_sprd_calc_flag = 0;

//reset bond_pv model
bond_pv->resetValues();
if (asset_detail_rpt_pv_flag(commencement_period))
	asset_detail_log_rebase_reset(commencement_period,
	                              "bond_pv->resetValues",
	                              "bond->coupon_rate_at_issue",
	                              asset_id,
	                              modelName);

bond_pv->rebase_period = -1;
rebase_bond_cash_flow(commencement_period,
		PRESENT_VALUE, "bond->coupon_rate_at_issue", modelName);

adj_max_rate
= pmt_rate_init_guess
	+ company->sm_inv_strategy[seg_num]->purch_bond_adj_max_above_init;

adj_min_rate
= pmt_rate_init_guess
	- company->sm_inv_strategy[seg_num]->purch_bond_adj_max_below_init;

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCText << PVCounter 
			<< "<--End Coupon Rate At Issue " << write_string(final_pmt_rate, PVCLen, PVCSigDig) << endl 
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " Cal yr=" << xint(cal_yr(commencement_period))
			<< " Cal mth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return final_pmt_rate;

}


//@@ END

//@@ START - data_file_name
// Data File Name                                                                                             
// Calculated Variable:DATA_FILE_NAME
//========================================================
xstring BOND_ASSET_UDF::bond_asset_data_file_name() {
//^^^


#line 1 "data_file_name.BOND_ASSET.for"
return replaceWildcards(data_location());

}


//@@ END

//@@ START - data_grp_id
// Data Group Identification                                                                                             
// Calculated Variable:DATA_GRP_ID
//========================================================
xstring BOND_ASSET_UDF::bond_asset_data_grp_id() {
//^^^


#line 1 "data_grp_id.BOND_ASSET.for"
return get_base_group_name(group, true);//WTW - Gen2 - Move Extern definitions to rates header

}


//@@ END

//@@ START - existing_asset_indicator
// Existing Asset Indicator                                                                                             
// Calculated Variable:EXISTING_ASSET_INDICATOR
//========================================================
int BOND_ASSET_UDF::bond_asset_existing_asset_indicator() {
//^^^


#line 1 "existing_asset_indicator.BOND_ASSET.for"
if (purch_asset_mp_num == -1)
	{
	// Existing asset was purchased during a previous scenario time step
	if (time_step_flag && !valn_flag && valn_period != 0
		&& date_diff(issue_date, proj_date) > 0)
		return PRIOR_PURCH;	
	
	// Existing at original projection date
	xstring search_str = "Proxy";
	int insert_pos = asset_id.find(search_str);			
	if (insert_pos != string::npos) // This is a proxy bond
		return PROXY_BOND;

	// Existing at original projection date and non-proxy bond
	return INIT_MP;
	}

// New purchase in current scenario time step
return NEW_PURCH;

}


//@@ END

//@@ START - gaap_inc_defn
// GAAP Income Definition                                                                                             
// Calculated Variable:GAAP_INC_DEFN
//========================================================
int BOND_ASSET_UDF::bond_asset_gaap_inc_defn() {
//^^^


#line 1 "gaap_inc_defn.BOND_ASSET.for"
if (sale_class == AVAILABLE_FOR_SALE)
	return COST_BASIS;

if (sale_class == TRADING)
	return MARKET_VALUE;

if (sale_class == HELD_TO_MATURITY)
	return COST_BASIS;

//if (sale_class == NOT_ASSIGNED)
return COST_BASIS;

}


//@@ END

//@@ START - gaap_val_defn
// GAAP Value Definition                                                                                             
// Calculated Variable:GAAP_VAL_DEFN
//========================================================
int BOND_ASSET_UDF::bond_asset_gaap_val_defn() {
//^^^


#line 1 "gaap_val_defn.BOND_ASSET.for"
if (sale_class == AVAILABLE_FOR_SALE)
	return MARKET_VALUE;

if (sale_class == TRADING)
	return MARKET_VALUE;

if (sale_class == HELD_TO_MATURITY)
	return COST_BASIS;

//if (sale_class == NOT_ASSIGNED)
return COST_BASIS;

}


//@@ END

//@@ START - maturity_mths_from_next_reset
// Maturity Months from Next Reset                                                                                             
// Calculated Variable:MATURITY_MTHS_FROM_NEXT_RESET
//========================================================
int BOND_ASSET_UDF::bond_asset_maturity_mths_from_next_reset() {
//^^^


#line 1 "maturity_mths_from_next_reset.BOND_ASSET.for"
if (!existing_asset_indicator)
	return 0;

if (refinancing_rate_opt_sprd_calc_flag)
	return -1; // to force FIXED_RATE coupon rate

return min(get_yr_from_date(maturity_date) - get_yr_from_date(adj_next_reset_date),
		   MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
	   + get_mth_from_date(maturity_date) - get_mth_from_date(adj_next_reset_date);

}


//@@ END

//@@ START - maturity_period
// Maturity Period                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_maturity_period() {
//^^^


#line 1 "maturity_period.BOND_ASSET.for"
if (existing_asset_indicator)
	{
	int maturity_yr = get_yr_from_date(maturity_date);
	int maturity_mth = get_mth_from_date(maturity_date);

	return (maturity_yr - proj_start_yr) * 12
			+ maturity_mth - proj_start_mth + 1;
	}

if (purch_asset_mp_num < 0)
	return 0;

double local_ytm = asset->purch_asset_yrs_to_maturity;

if (((double)((int)(12 * local_ytm)))
	 == (12 * local_ytm))
	return commencement_period
		   + min(local_ytm,
		   		 MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

return commencement_period
	   + min(local_ytm,
	   		 MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;

}


//@@ END

//@@ START - mkt_val_per_unit_par
// Market Value Per Unit of Par Value                                                                                             
// Calculated Variable:MKT_VAL_PER_UNIT_PAR
//========================================================
double BOND_ASSET_UDF::bond_asset_mkt_val_per_unit_par() {
//^^^


#line 1 "mkt_val_per_unit_par.BOND_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

double par_value_local = max(ONE_MILLION, fabs(purch_amt));
double pmt_rate = coupon_rate_at_issue;

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Per Unit Par"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period))
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	}

rebase_bond_cash_flow(commencement_period,
			PRESENT_VALUE, "bond->mkt_val_per_unit_par", modelName);

bond_pv->pv_calc_parameters(commencement_period,
			MARKET_VALUE, xint(maturity_period - commencement_period));

double weighted_average_life = bond_pv->weighted_avg_life_calc(commencement_period);

double risk_spread
= rates->get_int_rate(commencement_period,
                      category_id, 
		              GET_SPOT_SPREAD,
		              weighted_average_life,
		              0.0,
		              NOMINAL_SEMIANNUAL,
		              NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

double temp = 0;

double base_price
= bond_pv->pv_calc(commencement_period, 
		0.0, 
		temp,  // calculated_derivative
		temp   //calculated_modified_duration
		);

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCText << "BasePrice,"	<< write_string(base_price,PVCLen,PVCSigDig);
	asset_detail_rpt_pv_output();
	}

double call_price = 0;
double put_price = 0;

if (call_first_period < maturity_period)
	call_price
	= bond_pv->call_opt_price_calc(commencement_period, NO_SHIFT);

if (put_first_period < maturity_period)
	put_price
	= bond_pv->put_opt_price_calc(commencement_period, NO_SHIFT);

double price_per_unit_of_par
= (base_price - call_price + put_price) / par_value_local;

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCText << PVCounter
			<< "<--End Market Value Per Unit Par ("
			<< write_string(price_per_unit_of_par,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period))
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return price_per_unit_of_par;

}


//@@ END

//@@ START - neg_asset_flag
// Negative Asset Flag                                                                                             
// Calculated Variable:NEG_ASSET_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_neg_asset_flag() {
//^^^


#line 1 "neg_asset_flag.BOND_ASSET.for"
if (existing_asset_indicator)
	{
	if (init_par_val >= 0.0)
		return 1;

	return -1;
	}

if (purch_amt >= 0.0)
	return 1;

return -1;

}


//@@ END

//@@ START - net_yld_at_issue
// Net Yield at Issue                                                                                             
// Calculated Variable:NET_YLD_AT_ISSUE
//========================================================
double BOND_ASSET_UDF::bond_asset_net_yld_at_issue() {
//^^^


#line 1 "net_yld_at_issue.BOND_ASSET.for"
if (net_yld_at_issue_flag == NO)
	return 0.0;

if (existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->net_yld_at_issue;

net_yld_at_issue_calc_flag = 1;

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Net Yield At Issue"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period))
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	}

double local_net_yield_at_issue
= convert_rate_basis(net_yld(commencement_period), 
		  12, NOMINAL_SEMIANNUAL);

if (asset_detail_rpt_pv_flag(commencement_period))
	{
	PVCText << PVCounter
			<< "<--End Net Yield At Issue ("
			<< write_string(local_net_yield_at_issue,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period))
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

net_yld_at_issue_calc_flag = 0;

return local_net_yield_at_issue;

}


//@@ END

//@@ START - net_yld_at_issue_flag
// Net Yield at Issue Flag                                                                                             
// Calculated Variable:NET_YLD_AT_ISSUE_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_net_yld_at_issue_flag() {
//^^^


#line 1 "net_yld_at_issue_flag.BOND_ASSET.for"
if (existing_asset_indicator)
	{	
	if (par_val_at_issue != 0.0
		&& opt_int_diff_defn == NET_YIELD_AT_ISSUE
		&& pmt_rate_defn == FIXED_RATE 
		&& sinking_fund_defn == NO)
		return YES;

	return NO;
	}

if ((opt_int_diff_defn == NET_YIELD
	 || opt_int_diff_defn == NET_YIELD_AT_ISSUE)
	&& pmt_rate_defn == FIXED_RATE
	&& sinking_fund_defn == NO)
	return YES;

return NO;

}


//@@ END

//@@ START - pct_to_use
// Percent to Use                                                                                             
// Calculated Variable:PCT_TO_USE
//========================================================
double BOND_ASSET_UDF::bond_asset_pct_to_use() {
//^^^


#line 1 "pct_to_use.BOND_ASSET.for"
if (!isMainModel)
	{
	// Existing at original projection date
	if (existing_asset_indicator == INIT_MP)
		return seg->existing_asset_pct_to_use  * neg_asset_flag;
	
	// Existing asset was purchased during previous scenario time step
	if (existing_asset_indicator == PRIOR_PURCH)
		return neg_asset_flag;
	}

return neg_asset_flag;

}


//@@ END

//@@ START - planned_sale_period
// Planned Sale Period                                                                                             
// Calculated Variable:PLANNED_SALE_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_planned_sale_period() {
//^^^


#line 1 "planned_sale_period.BOND_ASSET.for"
if (existing_asset_indicator)
	return min(get_yr_from_date(planned_sale_date) - proj_start_yr,
		       MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
	       + get_mth_from_date(planned_sale_date) - proj_start_mth + 1;

return MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS * 12;

}


//@@ END

//@@ START - pmt_freq
// Payment Frequency                                                                                             
// Calculated Variable:PMT_FREQ
//========================================================
int BOND_ASSET_UDF::bond_asset_pmt_freq() {
//^^^


#line 1 "pmt_freq.BOND_ASSET.for"
if (pmt_mode == MONTHLY)
	return 12;

if (pmt_mode == QUARTERLY)
	return 4;

if (pmt_mode == SEMI_ANNUAL)
	return 2;

//if (pmt_mode == ANNUAL)
return 1;

}


//@@ END

//@@ START - pmt_mths
// Payment Period Months                                                                                             
// Calculated Variable:PMT_MTHS
//========================================================
int BOND_ASSET_UDF::bond_asset_pmt_mths() {
//^^^


#line 1 "pmt_mths.BOND_ASSET.for"
return 12 / pmt_freq;

}


//@@ END

//@@ START - pmt_rate_defn
// Payment Rate Definition                                                                                             
// Calculated Variable:PMT_RATE_DEFN
//========================================================
int BOND_ASSET_UDF::bond_asset_pmt_rate_defn() {
//^^^


#line 1 "pmt_rate_defn.BOND_ASSET.for"
if (existing_asset_indicator)
	{
	if (mths_to_next_reset(0) >= maturity_period)
		return FIXED_RATE;

	return FLOATING_RATE;
	}

// Lookup key is purch_asset_id
if (company->sm_inv_strategy[seg_num]->purch_bond_rate_defn == FLOATING_RATE)
	return FLOATING_RATE;

return FIXED_RATE;

}


//@@ END

//@@ START - pmt_rate_defn_string
// Payment Rate Definition                                                                                             
// Calculated Variable:PMT_RATE_DEFN_STRING
//========================================================
xstring BOND_ASSET_UDF::bond_asset_pmt_rate_defn_string() {
//^^^


#line 1 "pmt_rate_defn_string.BOND_ASSET.for"
if (pmt_rate_defn == FLOATING_RATE)
	return get_string_of_enum_val(FLOATING_RATE);

return get_string_of_enum_val(FIXED_RATE);


}


//@@ END

//@@ START - pmt_reset_first_period
// Payment Reset first_Period                                                                                             
// Calculated Variable:PMT_RESET_FIRST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_pmt_reset_first_period() {
//^^^


#line 1 "pmt_reset_first_period.BOND_ASSET.for"
if (existing_asset_indicator)
	{
	if (maturity_mths_from_next_reset <= 0)
		return maturity_period;

	int mths_to_next_reset_prelim = 0;

	if (maturity_mths_from_next_reset < maturity_period)
		mths_to_next_reset_prelim
		= maturity_period - maturity_mths_from_next_reset;
	else
		mths_to_next_reset_prelim
		= adj_reset_mths
		  - ((maturity_mths_from_next_reset - maturity_period) % adj_reset_mths);

	return mths_to_next_reset_prelim
		   + (maturity_period - mths_to_next_reset_prelim) % pmt_mths;
	}

// else if purchase asset
int t = commencement_period;

if (adj_reset_mths < maturity_period - t)
	return t + 1 + (maturity_period - t - 1) % adj_reset_mths;

return maturity_period;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring BOND_ASSET_UDF::bond_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.BOND_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int BOND_ASSET_UDF::bond_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.BOND_ASSET.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int BOND_ASSET_UDF::bond_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.BOND_ASSET.for"
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
int BOND_ASSET_UDF::bond_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.BOND_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - put_first_period
// Put First Period                                                                                             
// Calculated Variable:PUT_FIRST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_put_first_period() {
//^^^


#line 1 "put_first_period.BOND_ASSET.for"
if (put_defn == NOT_APPLICABLE)
	return 9999;

int initial_put_period = 0;
int first_scheduled_put_period = 0;

if (existing_asset_indicator)
	{
	initial_put_period
	= min(get_yr_from_date(put_opt_first_date) - proj_start_yr,
		  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
		  + get_mth_from_date(put_opt_first_date) - proj_start_mth + 1;

	if (put_price_sch_flag)
		{
		// Find first scheduled put period
		for (first_scheduled_put_period = 0;
			 first_scheduled_put_period < maturity_period
			 && (put_price_sch[first_scheduled_put_period] < rate_ratio_threshold);
			 first_scheduled_put_period++){}
		}

	int local_first_put_period = max(initial_put_period, first_scheduled_put_period);

	if (local_first_put_period > 0 || put_defn == AMERICAN)
		return local_first_put_period;

	return maturity_period;
	}

double local_put_protect_yrs = company->sm_inv_strategy[seg_num]->purch_bond_put_protect_yrs;

if (((double)((int)(12 * local_put_protect_yrs)))
	 == (12 * local_put_protect_yrs))
	initial_put_period
	= commencement_period
	  + min(local_put_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12;
else
	initial_put_period
	= commencement_period
	  + min(local_put_protect_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12
	  + 1;

if (put_defn != NOT_APPLICABLE && put_price_sch_flag)
	{
	// Find first scheduled put period
	for (first_scheduled_put_period = commencement_period;
		 first_scheduled_put_period < maturity_period
		 && (put_price_sch[first_scheduled_put_period - commencement_period] < rate_ratio_threshold);
		 first_scheduled_put_period++){}

	return max(initial_put_period, first_scheduled_put_period);
	}

return initial_put_period;

}


//@@ END

//@@ START - put_par_first_period
// Put at Par Value First Period                                                                                             
// Calculated Variable:PUT_PAR_FIRST_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_put_par_first_period() {
//^^^


#line 1 "put_par_first_period.BOND_ASSET.for"
if (put_defn == NOT_APPLICABLE)
	return 0;

if (existing_asset_indicator)
	{
	if (!put_price_sch_flag)
		return put_first_period;
		
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int first_scheduled_par_put_period;
	for (first_scheduled_par_put_period = 0;
		 first_scheduled_par_put_period < maturity_period
		 && (put_price_sch[first_scheduled_par_put_period] < rate_ratio_threshold
			 || (fabs(put_price_sch[first_scheduled_par_put_period] - 1.0)
				 > rate_ratio_threshold));
		first_scheduled_par_put_period++){}

	return max(put_first_period, first_scheduled_par_put_period);
	}

double local_put_protec_yrs = company->sm_inv_strategy[seg_num]->purch_bond_put_protect_yrs;
double local_yrs_to_first_par_put = company->sm_inv_strategy[seg_num]->purch_bond_first_par_put_yr;

int initial_put_period = 0;

if (((double)((int)(12 * local_put_protec_yrs)))
	 == (12 * local_put_protec_yrs))
	initial_put_period
	= commencement_period
	  + min(local_put_protec_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12;
else
	initial_put_period
	= commencement_period
	  + min(local_put_protec_yrs,
	        MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	    * 12
	  + 1;

if (put_price_defn == PRICE_SCHEDULE)
	{
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int first_scheduled_par_put_period = commencement_period;
	for (first_scheduled_par_put_period = commencement_period;
		 first_scheduled_par_put_period < maturity_period
		   && (put_price_sch[first_scheduled_par_put_period - commencement_period] < rate_ratio_threshold
		  	 || (fabs(put_price_sch[first_scheduled_par_put_period - commencement_period] - 1.0)
		  		 > rate_ratio_threshold));
		 first_scheduled_par_put_period++){}
		return max(put_first_period, first_scheduled_par_put_period);
	}

// purch_bond_put_price_defn == RELATED_TO_COUPON
int months_to_first_zero_put_premium_related_to_coupon;

if (((double)((int)(12 * local_yrs_to_first_par_put)))
	 == (12 * local_yrs_to_first_par_put))
	months_to_first_zero_put_premium_related_to_coupon
	= min(local_yrs_to_first_par_put,
	      MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	  * 12;
else
	months_to_first_zero_put_premium_related_to_coupon
	= min(local_yrs_to_first_par_put,
	      MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS)
	  * 12
	  + 1;

return max(initial_put_period,
           commencement_period + months_to_first_zero_put_premium_related_to_coupon);

}


//@@ END

//@@ START - put_prem_grading_mths
// Put Premium Grading Months                                                                                             
// Calculated Variable:PUT_PREM_GRADING_MTHS
//========================================================
int BOND_ASSET_UDF::bond_asset_put_prem_grading_mths() {
//^^^


#line 1 "put_prem_grading_mths.BOND_ASSET.for"
if (existing_asset_indicator)
	return 0;

// Lookup key is purch_asset_id

int initial_put_period 
= commencement_period 
+ min(company->sm_inv_strategy[seg_num]->purch_bond_put_protect_yrs,
	  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

int first_zero_put_premium_related_to_coupon_period
= max(commencement_period 
      + min(company->sm_inv_strategy[seg_num]->purch_bond_first_par_put_yr,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
	  initial_put_period);

return max(first_zero_put_premium_related_to_coupon_period 
           - initial_put_period, 1);

}


//@@ END

//@@ START - put_prem_related_to_coupon_rate
// Put Premium Related to Coupon Rate                                                                                             
// Calculated Variable:PUT_PREM_RELATED_TO_COUPON_RATE
//========================================================
double BOND_ASSET_UDF::bond_asset_put_prem_related_to_coupon_rate() {
//^^^


#line 1 "put_prem_related_to_coupon_rate.BOND_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

// Lookup key is purch_asset_id

int initial_put_period 
= commencement_period 
  + min(company->sm_inv_strategy[seg_num]->purch_bond_put_protect_yrs,
		MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

int first_zero_put_premium_related_to_coupon_period
= max(commencement_period 
      + min(company->sm_inv_strategy[seg_num]->purch_bond_first_par_put_yr,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
	  initial_put_period);

if (first_zero_put_premium_related_to_coupon_period > initial_put_period)
	{
	if (bond_pv->isShrunk
		|| bond_pv->rebase_period < commencement_period)
		rebase_bond_cash_flow(commencement_period,
		                      PRESENT_VALUE,
		                      "bond->mkt_val_bef_sale",
		                      modelName);

	double weighted_average_life_local
	= bond_pv->weighted_avg_life_calc(commencement_period);

	double local_refinancing_rate
	= category_refinancing_rate(commencement_period, 
			maturity_period - commencement_period,  
			weighted_average_life_local,
			0.0, // opt_sprd
			NOMINAL_SEMIANNUAL,
			NO_SHIFT // shift_defn
			);
 
	double preliminary_coupon_rate_at_issue;
	if (company->sm_inv_strategy[seg_num]->purch_bond_rate_defn != REFINANCING_RATE)
		preliminary_coupon_rate_at_issue
		= max(0.0, (rates->get_int_rate(commencement_period,
							adj_reset_category_id,
							GET_YIELD_RATE,
							adj_reset_scen_yr,
							0.0,
							pmt_freq,
							NO_SHIFT,portfolio_sprd_adj_aig))//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				   * adj_reset_scen_mult
					+ company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_addn_init);
	else		
		preliminary_coupon_rate_at_issue
		= max(0.0, convert_rate_basis(local_refinancing_rate,
						   NOMINAL_SEMIANNUAL,
						   pmt_freq)
				   - company->sm_inv_strategy[seg_num]->purch_bond_rate_diff);

	return preliminary_coupon_rate_at_issue
		   * company->sm_inv_strategy[seg_num]->purch_bond_put_prem_mult
		   + company->sm_inv_strategy[seg_num]->purch_bond_put_prem_addn;
	}

return 0.0;

}


//@@ END

//@@ START - put_price_sch_flag
// Put Price Schedule Flag                                                                                             
// Calculated Variable:PUT_PRICE_SCH_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_put_price_sch_flag() {
//^^^


#line 1 "put_price_sch_flag.BOND_ASSET.for"
if (put_defn == NOT_APPLICABLE
	|| put_price_defn != PRICE_SCHEDULE)
	return 0;

if (!set_put_sch_flag) // already set the schedule, no need to set it again
	return 1;
	
set_put_sch_flag = false;

if (existing_asset_indicator == PRIOR_PURCH 
	|| existing_asset_indicator == PROXY_BOND)
	{
	if (read_sch_file_flag)
		read_sch_file();

	return 1;
	}

if (put_price_sch.size() < sch_array_size)
	put_price_sch.resize(sch_array_size);

for (int month = start_period; month <= maturity_period; month++)
	{
	if (existing_asset_indicator == INIT_MP)
		put_price_sch[month - start_period] = put_price_pct.AtTime(month);
	else // existing_asset_indicator == NEW_PURCH
		{
		company->sm_inv_strategy[seg_num]->mths_since_issue = month - start_period;							
		put_price_sch[month - start_period] = company->sm_inv_strategy[seg_num]->purch_bond_put_price_pct;
		}
	}

return 1;

}


//@@ END

//@@ START - refinancing_rate_defn_calc
// Refinancing Rate Definition Calculated                                                                                             
// Calculated Variable:REFINANCING_RATE_DEFN_CALC
//========================================================
int BOND_ASSET_UDF::bond_asset_refinancing_rate_defn_calc() {
//^^^


#line 1 "refinancing_rate_defn_calc.BOND_ASSET.for"
return refinancing_rate_defn;

}


//@@ END

//@@ START - refinancing_rate_opt_sprd
// Refinancing Rate Option Spread                                                                                             
// Calculated Variable:REFINANCING_RATE_OPT_SPRD
//========================================================
double BOND_ASSET_UDF::bond_asset_refinancing_rate_opt_sprd() {
//^^^


#line 1 "refinancing_rate_opt_sprd.BOND_ASSET.for"
if (existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->refinancing_rate_opt_sprd; 

if (refinancing_rate_defn == CATEGORY_YIELD_TO_WAL_OPTION_SPREAD)
	{
	if (call_first_period < maturity_period
		|| put_first_period < maturity_period)
		{
		if (existing_asset_indicator)
			{
			if (asset_detail_rpt_pv_flag(0))
				{
				PVCounter++;
				PVCText << PVCounter
						<< "-->Begin Refinancing Rate Option Spread"
						<< " for " << asset_id
						<< " (" << pmt_rate_defn_string << ")"
						<< " t=" << 0
						<< " CalYr=" << xint(cal_yr(0))
						<< " CalMth=" << xint(cal_mth(0));
				asset_detail_rpt_pv_output();
				}

			double local_option_spread_for_refinancing_rate
			= opt_sprd_refinancing(0);

			if (asset_detail_rpt_pv_flag(0))
				{
				PVCText << PVCounter
						<< "<--End Refinancing Rate Option Spread ("
						<< write_string(local_option_spread_for_refinancing_rate,PVCLen,PVCSigDig)
						<< ") for " << asset_id
						<< " (" << pmt_rate_defn_string << ")"
						<< " t=" << 0
						<< " CalYr=" << xint(cal_yr(0))
						<< " CalMth=" << xint(cal_mth(0));
				asset_detail_rpt_pv_output();
				PVCounter--;
				}

			return local_option_spread_for_refinancing_rate;
			}

		// else !existing_asset_flag
		if (asset_detail_rpt_pv_flag(commencement_period))
			{
			PVCounter++;
			PVCText << PVCounter
					<< "-->Begin Refinancing Rate Option Spread"
					<< " for " << asset_id
					<< " (" << pmt_rate_defn_string << ")"
					<< " CalYr=" << xint(cal_yr(commencement_period))
					<< " CalMth=" << xint(cal_mth(commencement_period));
			asset_detail_rpt_pv_output();
			}

		rebase_bond_cash_flow(commencement_period,
					PRESENT_VALUE, "bond->refinancing_rate_opt_sprd",
					modelName);

		bond_pv->pv_calc_parameters(commencement_period,
					MARKET_VALUE, xint(maturity_period - commencement_period));

		double local_option_spread = opt_sprd(commencement_period);

		if (asset_detail_rpt_pv_flag(commencement_period))
			{
			PVCText << PVCounter
					<< "<--End Refinancing Rate Option Spread ("
					<< write_string(local_option_spread,PVCLen,PVCSigDig)
					<< ") for " << asset_id
					<< " (" << pmt_rate_defn_string << ")"
					<< " CalYr=" << xint(cal_yr(commencement_period))
					<< " CalMth=" << xint(cal_mth(commencement_period));
			asset_detail_rpt_pv_output();
			PVCounter--;
			}

		return local_option_spread;
		}
	}

return 0.0;

}


//@@ END

//@@ START - sale_class_id
// Sale Class Identification                                                                                             
// Calculated Variable:SALE_CLASS_ID
//========================================================
int BOND_ASSET_UDF::bond_asset_sale_class_id() {
//^^^


#line 1 "sale_class_id.BOND_ASSET.for"
//TWR??? Investigate this scalar use
if (sale_class == NOT_ASSIGNED)
	return 1;

if (sale_class == AVAILABLE_FOR_SALE)
	return 2;

if (sale_class == TRADING)
	return 3;

if (sale_class == HELD_TO_MATURITY)
	return 4;

return 0;

}


//@@ END

//@@ START - sch_array_size
// Schedule Array Size                                                                                             
// Calculated Variable:SCH_ARRAY_SIZE
//========================================================
int BOND_ASSET_UDF::bond_asset_sch_array_size() {
//^^^


#line 1 "sch_array_size.BOND_ASSET.for"
return maturity_period - start_period + 1;

}


//@@ END

//@@ START - sch_start_period
// Schedule Start Period                                                                                             
// Calculated Variable:SCH_START_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_sch_start_period() {
//^^^


#line 1 "sch_start_period.BOND_ASSET.for"
if (existing_asset_indicator)
	return 0;

return commencement_period;

}


//@@ END

//@@ START - seg_num
// Segment Number                                                                                             
// Calculated Variable:SEG_NUM
//========================================================
int BOND_ASSET_UDF::bond_asset_seg_num() {
//^^^


#line 1 "seg_num.BOND_ASSET.for"
if (isMainModel)
	return 0;

return seg->getElementNumber();

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int BOND_ASSET_UDF::bond_asset_start_period() {
//^^^


#line 1 "start_period.BOND_ASSET.for"
return max(0, commencement_period);

}


//@@ END

//@@ START - tax_exempt_pct
// Tax Exempt Percent                                                                                             
// Calculated Variable:TAX_EXEMPT_PCT
//========================================================
double BOND_ASSET_UDF::bond_asset_tax_exempt_pct() {
//^^^


#line 1 "tax_exempt_pct.BOND_ASSET.for"
return 1.0 - max(0.0, min(1.0, taxable_pct));

}


//@@ END

//@@ START - use_eom_scen_rates
// Use End of Month Scenario Rates?                                                                                             
// Calculated Variable:USE_EOM_SCEN_RATES
//========================================================
int BOND_ASSET_UDF::bond_asset_use_eom_scen_rates() {
//^^^


#line 1 "use_eom_scen_rates.BOND_ASSET.for"
return YES;

}


//@@ END

//@@ START - write_sch_file_flag
// Write Schedule File Flag                                                                                             
// Calculated Variable:WRITE_SCH_FILE_FLAG
//========================================================
int BOND_ASSET_UDF::bond_asset_write_sch_file_flag() {
//^^^


#line 1 "write_sch_file_flag.BOND_ASSET.for"
// Initial bonds will get values from external source data, no need to write csv schedule file
if (existing_asset_indicator == INIT_MP) 
	return 0;

if (call_defn != NOT_APPLICABLE 
	&& (call_price_defn == PRICE_SCHEDULE 
		|| call_price_defn == RELATED_TO_COUPON))
	return 1;

if (put_defn != NOT_APPLICABLE 
	&& (put_price_defn == PRICE_SCHEDULE 
		|| put_price_defn == RELATED_TO_COUPON))
	return 1;

if (sinking_fund_defn == YES)
	return 1;

return 0;

}


//@@ END

//@@ START - yrs_since_last_pmt
// Years Since Last Payment                                                                                             
// Calculated Variable:YRS_SINCE_LAST_PMT
//========================================================
double BOND_ASSET_UDF::bond_asset_yrs_since_last_pmt() {
//^^^


#line 1 "yrs_since_last_pmt.BOND_ASSET.for"
if (existing_asset_indicator)
	return (1.0 / pmt_freq) 
		   - ((1 + (maturity_period - 1)
				   % pmt_mths) / 12.0);

return (1.0 / pmt_freq)
	   - ((1 + (maturity_period - commencement_period - 1)
			   % pmt_mths) / 12.0);

}


//@@ END


#line 1 "asset_detail_log_rebase_reset.BOND_ASSET.for"                                                                                   
void BOND_ASSET::asset_detail_log_rebase_reset(int t, const xstring &rebase_model, const xstring &caller, const xstring &identifier, const xstring &id_submodel_name)
{
PVCText << " rebase model=" << rebase_model
		<< " at t=" << t
		<< " in " << caller
		<< " for " << identifier
		<< " |" << id_submodel_name;
asset_detail_rpt_pv_output();

return;
}



#line 1 "asset_detail_rpt_pv_output.BOND_ASSET.for"                                                                                   
void BOND_ASSET::asset_detail_rpt_pv_output()
{
if (asset_detail_rpt_pv_defn == YES)
	PVCFile << endl << PVCText.str() << endl;
else // "Summary to Run Log"
	log_screen << "PVSum: " << PVCText.str() << MSG_USER;

PVCText.str("");

return;
}



#line 1 "calc_num_records_to_run.BOND_ASSET.for"                                                                                   
int BOND_ASSET::calc_num_records_to_run(void)
{
xstring data_file_name = replaceWildcards(data_location());
string table_name = readCsvFile(data_file_name.getStdStr());
xstring sql = (xstring)"SELECT * FROM " + table_name;
executeQuery(sql.getStdStr(), bond_mp_input_cols, bond_mp_input);
closeDatabase();

if (!bond_mp_input_cols.size())
	return 0;

int num_records_to_run = 0;
for (int row = 0; row < bond_mp_input.size(); row++)
	{
	if (bond_mp_input[row][3] == "Yes")
		num_records_to_run++;
	}

return num_records_to_run;
}



#line 1 "category_refinancing_rate.BOND_ASSET.for"                                                                                   
double BOND_ASSET::category_refinancing_rate(int t, int local_months_to_maturity, double local_weighted_average_life, double local_option_spread, int return_rate_basis, int shift_defn)
{
double local_refinancing_rate = 0.0;

if (refinancing_rate_defn_calc == REFINANCING_RATE)
	local_refinancing_rate
	= max(0.0,
	      rates->get_int_rate(t,
	                          "Govt",
					          GET_YIELD_RATE,
					          refinancing_rate_scen_yr,
					          0.0,
					          NOMINAL_SEMIANNUAL, 
					          shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		  * refinancing_rate_scen_mult
		  + refinancing_rate_scen_addn);


if (refinancing_rate_defn_calc == CATEGORY_YIELD_TO_WAL_OPTION_SPREAD)
	{
	double local_category_rate;

	local_category_rate
	= rates->get_int_rate(t,
	                      category_id,
				          GET_YIELD_RATE, 
				          local_weighted_average_life,
				          0.0,
				          NOMINAL_SEMIANNUAL,
				          shift_defn,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	local_refinancing_rate
	= local_category_rate
	  + local_option_spread;
	}

if (return_rate_basis != NOMINAL_SEMIANNUAL)
	local_refinancing_rate
		= convert_rate_basis(local_refinancing_rate, 
					NOMINAL_SEMIANNUAL,
					return_rate_basis);

return local_refinancing_rate;
}



#line 1 "create_state_of_world_schedule.BOND_ASSET.for"                                                                                   
xstring BOND_ASSET::create_state_of_world_schedule(xstring &sch_type, SmartArray <double> &sched_data)
{
//TWR??? Delete this function; can this be transformed to create some other way to pass this information?
ofstream& SCHEDFile = *new ofstream;

// Create file name using asset_id, loop numbers, commencement_period, and sched_type since must be unique
xstring sched_file_name
= "<*bond_tables*>" + asset_id + "_sp" + xstring(proj_set_loop_num) 
  + "_cp" + xstring(commencement_period) + "_" + sch_type + ".msv"; 

// create and write file
xstring file_name = replaceWildcards(sched_file_name);
xstring use_file_name = file_name.strip();
use_file_name.to_lower();

if (sch_type == "CALL" || sch_type == "PUT")
	{
	SCHEDFile.open(use_file_name);
	SCHEDFile.setf(ios::fixed, ios::floatfield);
	SCHEDFile << "<?xml version=\"1.0\" encoding=\"utf-16\" standalone=\"yes\"?>" << endl;
	SCHEDFile << "<!DOCTYPE table>" << endl;
	SCHEDFile << "<table type=\"Standard\" style=\"Date\">" << endl;
	SCHEDFile << "<tablename></tablename>" << endl;
	SCHEDFile << "<comment></comment>" << endl;
	SCHEDFile << "<rowindex missing=\"Previous\" type=\"Date\" mask=\"YYYY/MM\" offset=\"proj_start_date\" adjust=\"-1\" afterlast=\"Last\" beforefirst=\"First\"/>" << endl;
	SCHEDFile << "<colindex>0</colindex>" << endl;
	SCHEDFile << "<healthinfo/>" << endl;
	SCHEDFile << "<column index=\"VALUE\">" << endl;
	
	// Include loop here over all dates for the schedule
	xstring full_sch_date, sch_date;
	
	for (int i = 1; i < sched_data.size(); i++)
		{
		full_sch_date = add_mths_to_date(proj_date, commencement_period + i);
		sch_date = full_sch_date(0, 7); // stripping day off
	
		SCHEDFile << "<value row=\"" << sch_date << "\">" << sched_data[i] << "</value>" << endl;
		}
	
	SCHEDFile << "</column>" << endl;
	SCHEDFile << "</table>" << endl;
	}
else // sch_type == "SINK"
	{
	SCHEDFile.open(use_file_name);
	SCHEDFile.setf(ios::fixed, ios::floatfield);
	SCHEDFile << "<?xml version=\"1.0\" encoding=\"utf-16\" standalone=\"yes\"?>" << endl;
	SCHEDFile << "<!DOCTYPE table>" << endl;
	SCHEDFile << "<table type=\"Standard\" style=\"Specific Date\">" << endl;
	SCHEDFile << "<tablename></tablename>" << endl;
	SCHEDFile << "<comment></comment>" << endl;
	SCHEDFile << "<rowindex missing=\"Zero\" type=\"Date\" mask=\"YYYY/MM\" offset=\"proj_start_date\" adjust=\"-1\" afterlast=\"Zero\" beforefirst=\"Zero\"/>" << endl;
	SCHEDFile << "<colindex>0</colindex>" << endl;
	SCHEDFile << "<healthinfo/>" << endl;
	SCHEDFile << "<column index=\"VALUE\">" << endl;
	
	// Include loop here over all dates for the schedule
	xstring full_sch_date, sch_date;
	
	for (int i = 1; i < sched_data.size(); i++)
		{
		if (fabs(sched_data[i]) < aggregate_amount_threshold)
			continue;

		full_sch_date = add_mths_to_date(proj_date, commencement_period + i);
		sch_date = full_sch_date(0, 7); // stripping day off
	
		SCHEDFile << "<value row=\"" << sch_date << "\">" << sched_data[i] << "</value>" << endl;
		}
	
	SCHEDFile << "</column>" << endl;
	SCHEDFile << "</table>" << endl;
	}

if (SCHEDFile != NULL)
	SCHEDFile.close();

// return file name
return sched_file_name;
}



#line 1 "mths_to_next_pmt.BOND_ASSET.for"                                                                                   
int BOND_ASSET::mths_to_next_pmt(int t)
{
return 1 + (maturity_period - t - 1) % pmt_mths;
}



#line 1 "mths_to_next_reset.BOND_ASSET.for"                                                                                   
int BOND_ASSET::mths_to_next_reset(int t)
{
if (t < pmt_reset_first_period)
	return pmt_reset_first_period - t;

return adj_reset_mths
	   - (t - pmt_reset_first_period) % adj_reset_mths;
}



#line 1 "opt_sprd_refinancing.BOND_ASSET.for"                                                                                   
double BOND_ASSET::opt_sprd_refinancing(int t)
{
double final_option_spread = 0;
double payment_rate_for_final_option_spread = 0;

// turn on calculation flag
refinancing_rate_opt_sprd_calc_flag = 1;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Option Spread Refinancing"
			<< " for " << asset_id
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));

	asset_detail_rpt_pv_output();
	}

// Solve for par yield.
payment_rate_for_final_option_spread
= solve_for_coupon_rate(t, bond_cf->par_val(t));

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << " Payment Rate For Final Option Spread = "
			<< write_string(payment_rate_for_final_option_spread,PVCLen,PVCSigDig)
			<< " for " << asset_id
			<< " t=" << t
			<< " Cal yr=" << xint(cal_yr(t))
			<< " Cal mth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

// target value
double category_rate_local;

category_rate_local
= rates->get_int_rate(t,
                      category_id,
				      GET_YIELD_RATE,
				      weighted_avg_life(t),
				      0.0,
				      NOMINAL_SEMIANNUAL,
				      NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

final_option_spread
= payment_rate_for_final_option_spread
  - category_rate_local;

//reset models 
resetValues();
bond_cf->resetValues();
bond_pv->resetValues();
if (asset_detail_rpt_pv_flag(t))
	{
	asset_detail_log_rebase_reset(t,
	                              "bond->resetValues",
	                              "bond->opt_sprd_refinancing",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_cf->resetValues",
	                              "bond->opt_sprd_refinancing",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_pv->resetValues",
	                              "bond->opt_sprd_refinancing",
	                              asset_id,
	                              modelName);
	}

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Option Spread Refinancing ("
			<< write_string(final_option_spread,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
			<< " CalMth=" << xint(cal_mth(t));	
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

refinancing_rate_opt_sprd_calc_flag = 0;

return final_option_spread;
}



#line 1 "read_sch_file.BOND_ASSET.for"                                                                                   
void BOND_ASSET::read_sch_file(void)
{
read_sch_file_flag = false; // This function should only be called once per model point

if (existing_asset_indicator == NEW_PURCH || existing_asset_indicator == INIT_MP)
	return;

// existing_asset_indicator == PRIOR_PURCH || existing_asset_indicator == PROXY_BOND
static bool first_time = true;

if (first_time)
	{
	first_time = false;

	// Create file_name
	xstring data_file_name = replaceWildcards(data_location());

	xstring sch_file = "";
	if (time_step_flag)
		sch_file = xstring(data_file_name(0, data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
				   + "_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";
	else // This should only happen when existing_asset_indicator == PROXY_BOND
		sch_file = xstring(data_file_name(0, data_file_name.find(".csv"))) + "_sch.csv";

	string table_name = readCsvFile(sch_file.getStdStr());
	xstring sql = (xstring)"SELECT * FROM " + table_name;
	executeQuery(sql.getStdStr(), bond_sch_input_cols, bond_sch_input);
	closeDatabase();

	if (!bond_sch_input_cols.size())
		throw FatalError("Could not read Bond Schedule File: " 
			              + sch_file + " "
			              + "Please check your data.");
	
	// Create map of mp start positions and mp input sizes
	bond_sch_input_pos[xstring(bond_sch_input[0][0])] = 0;
	int mp_first_row = 0;

	for (int row = 1; row < bond_sch_input.size(); row++)
		{
		if (!eq(bond_sch_input[row][0], bond_sch_input[row - 1][0])) // Found a new MP
			{
			bond_sch_input_pos[bond_sch_input[row][0]] = row;
			bond_sch_input_size[bond_sch_input[row - 1][0]] = row - mp_first_row;
			mp_first_row = row;
			}

		if (row == bond_sch_input.size() - 1)
			bond_sch_input_size[bond_sch_input[row][0]] = row - mp_first_row + 1;
		}
	}

int sch_start_row = 0;
if ((bond_sch_input_pos_iter 
     = bond_sch_input_pos.find(asset_id)) != bond_sch_input_pos.end())
	sch_start_row = bond_sch_input_pos_iter->second;

// Check to make sure schedule file starts with right date
xstring sch_start_date = bond_sch_input[sch_start_row][1].c_str();
if (date_diff(get_string_of_date(date(start_period)), sch_start_date) != 0)
	throw FatalError("Bond Schedule File: start date for model point " 
		              + asset_id + " does not equal current projection start date. "
		              + "Please check your data.");

int sch_size = 0;
if ((bond_sch_input_size_iter 
     = bond_sch_input_size.find(asset_id)) != bond_sch_input_size.end())
	sch_size = bond_sch_input_size_iter->second;

bool call_sch_flag = false;
if (call_defn != NOT_APPLICABLE && call_price_defn == PRICE_SCHEDULE)
	call_sch_flag = true;

bool put_sch_flag = false;
if (put_defn != NOT_APPLICABLE && put_price_defn == PRICE_SCHEDULE)
	put_sch_flag = true;

bool sinking_fund_sch_flag = false;
if (sinking_fund_defn == YES)
	sinking_fund_sch_flag = true;

if (call_sch_flag)
	{
	if (call_price_sch.size() < sch_array_size)
		call_price_sch.resize(sch_array_size);
	}
if (put_sch_flag)
	{
	if (put_price_sch.size() < sch_array_size)
		put_price_sch.resize(sch_array_size);
	}
if (sinking_fund_sch_flag)
	{
	if (sinking_fund_sch.size() < sch_array_size)
		sinking_fund_sch.resize(sch_array_size);
	}

double call_price_pct = 1.0;
double put_price_pct = 1.0;
double sinking_fund_prin_pmt_pct = 0.0;
int sch_row = sch_start_row;
xstring sch_date = sch_start_date;

for (int month = start_period; month <= maturity_period; month++)
	{
	xstring curr_date = get_string_of_date(date(month));

	// Read data only if it has changed
	if (date_diff(curr_date, sch_date) == 0 && sch_row < sch_size)
		{
		if (call_sch_flag)
			call_price_pct = atof(bond_sch_input[sch_row][2].c_str());
		if (put_sch_flag)
			put_price_pct = atof(bond_sch_input[sch_row][3].c_str());
		if (sinking_fund_sch_flag)
			sinking_fund_prin_pmt_pct = atof(bond_sch_input[sch_row][4].c_str());
		
		sch_row++;
		if (sch_row < sch_size)
			sch_date = bond_sch_input[sch_row][1].c_str();
		}

	// Update schedules
	if (call_sch_flag)
		call_price_sch[month - start_period] = call_price_pct;
	if (put_sch_flag)
		put_price_sch[month - start_period] = put_price_pct;
	if (sinking_fund_sch_flag)
		sinking_fund_sch[month - start_period] = sinking_fund_prin_pmt_pct;
	}

return;
}



#line 1 "rebase_bond_cash_flow.BOND_ASSET.for"                                                                                   
void BOND_ASSET::rebase_bond_cash_flow(int t, int command, const xstring &caller, const xstring &model_name)
{
// Only shrink and grow in portfolio model
if (!isMainModel)
	{
	if (pv_model_point != getElementNumber()
		|| pv_asset_defn != BOND_CODE)
		{
		if (pv_asset_defn == BOND_CODE)
			shrink_bond_clone(pv_model_point);
	
		else if (pv_asset_defn == MORTGAGE_CODE)
			{
			#ifdef __MTG_ASSET_H_
			if (asset->sm_mtg.size() > 0)
				asset->sm_mtg[0]->shrink_mtg_clone(pv_model_point);
			#else
		; // Place-holder
			#endif
			}
	
		else if (pv_asset_defn == SEC_CODE)
			{
			#ifdef __SEC_ASSET_H_
			if (asset->sm_sec.size() > 0)
				asset->sm_sec[0]->shrink_sec_clone(pv_model_point);
			#else
		; // Place-holder
			#endif
			}
		}
	
	pv_asset_defn = BOND_CODE;
	pv_model_point = getElementNumber();
	}

if (command == PRESENT_VALUE)
	{
	if (bond_pv->isShrunk)
		bond_pv->grow();

	bond_pv->rebaseModel(t);
	if (asset_detail_rpt_pv_flag(t))
		asset_detail_log_rebase_reset(t,
		                              "bond_pv->rebaseModel",
		                              caller,
		                              asset_id,
		                              model_name);
	}

else if (command == INTEREST_SAVINGS)
	{
	if (bond_is->isShrunk)
		bond_is->grow();

	bond_is->rebaseModel(t);
	if (asset_detail_rpt_pv_flag(t))
		asset_detail_log_rebase_reset(t,
		                              "bond_is->rebaseModel",
		                              caller,
		                              asset_id,
		                              model_name);
	}

else if (command == YIELD_MAINTENANCE)
	{
	if (bond_ym->isShrunk)
		bond_ym->grow();

	bond_ym->rebaseModel(t);
	if (asset_detail_rpt_pv_flag(t))
		asset_detail_log_rebase_reset(t,
		                              "bond_ym->rebaseModel",
		                              caller,
		                              asset_id,
		                              model_name);
	}

return;
}



#line 1 "setup_existing_asset.BOND_ASSET.for"                                                                                   
void BOND_ASSET::setup_existing_asset(void)
{
// Set value for model point variables
if (num_of_proj_task_loops == 0 
	|| is_first_proj_task_loop
	|| restore_variables_ind == 1)
	{
	asset_id = asset_id_mp;
	seg_id = seg_id_mp;
	category_id = category_id_mp;
	port_defn = port_defn_mp;
	sale_class = sale_class_mp; 
	issue_date = issue_date_mp;
	maturity_date = maturity_date_mp;
	planned_sale_date = planned_sale_date_mp; 
	init_par_val = init_par_val_mp;
	init_cost_basis = init_cost_basis_mp;
	init_bk_val = init_bk_val_mp;
	init_mkt_val = init_mkt_val_mp;
	pmt_mode = pmt_mode_mp;
	init_pmt_rate = init_pmt_rate_mp;
	par_val_at_issue = par_val_at_issue_mp;
	taxable_pct = taxable_pct_mp;
	call_defn = call_defn_mp;
	call_opt_first_date = call_opt_first_date_mp;
	call_price_defn = call_price_defn_mp; 
	yld_maint_addn = yld_maint_addn_mp;
	put_price_defn = PRICE_SCHEDULE;
	put_defn = put_defn_mp;
	put_opt_first_date = put_opt_first_date_mp;
	sinking_fund_defn = sinking_fund_defn_mp;
	adj_reset_category_id = adj_reset_category_id_mp;
	adj_reset_scen_yr = adj_reset_scen_yr_mp;
	adj_reset_scen_mult = adj_reset_scen_mult_mp;
	adj_reset_renewal_addn = adj_reset_renewal_addn_mp;
	adj_next_reset_date = adj_next_reset_date_mp;
	adj_reset_mths = adj_reset_mths_mp;
	adj_max_incr_per_reset = adj_max_incr_per_reset_mp;
	adj_max_decr_per_reset = adj_max_decr_per_reset_mp;
	adj_min_rate = adj_min_rate_mp;
	adj_max_rate = adj_max_rate_mp;
	avr_contribn_pct = avr_contribn_pct_mp;
	avr_max_pct = avr_max_pct_mp;
	avr_obj_pct = avr_obj_pct_mp;
	rbc_c1_pct = rbc_c1_pct_mp;

	portfolio_sprd_adj_aig = portfolio_sprd_adj_aig_mp;  //08/12/2024
	dur_wtd_sprd_adj_aig = dur_wtd_sprd_adj_aig_mp;  //08/12/2024
	}

if (sinking_fund_defn == YES)
	setup_sinking_fund_sch();

// Setup adjustable rate reset months
int adj_reset_mths_input = adj_reset_mths;

if (adj_reset_mths <= 0)
	adj_reset_mths = pmt_mths;
else if (adj_reset_mths
		 <= xint(xint(maturity_period / pmt_mths) * pmt_mths))
	adj_reset_mths
	= adj_reset_mths 
	  + (xint(xint(maturity_period / pmt_mths) * pmt_mths)
		 - adj_reset_mths) % pmt_mths;
else
	adj_reset_mths = maturity_period;

if (is_first_proj_task_loop
	&& pmt_rate_defn == FLOATING_RATE
	&& pmt_reset_first_period < maturity_period)
	{
	// Issue warning if ARB reset months has been adjusted
	static bool issue_adj_reset_mths_warning = true;

	if (issue_adj_reset_mths_warning
		&& adj_reset_mths != adj_reset_mths_input
		&& (pmt_reset_first_period + adj_reset_mths) < maturity_period)
		{
		issue_adj_reset_mths_warning = false;
		makeRunLogYellow();
		log_screen << "Warning. ARB Reset Months for at least one existing bond"
				<< " is incompatible with its payment frequency."
				<< MSG_ERROR;
		log_screen << " ... For example, ARB Reset Months (" << adj_reset_mths_input
				<< ") for existing bond '" << asset_id
				<< "' is incompatible with its"
				<< MSG_ERROR;
		log_screen << " ... payment frequency (" << pmt_mode
				<< ") and has been reset to " << adj_reset_mths
				<< "." << MSG_ERROR;
		}

	// Issue warning if months to next reset date has been adjusted
	int mths_to_next_reset_prelim = 0;

	if (maturity_mths_from_next_reset <= 0)
		mths_to_next_reset_prelim = maturity_period;
	else if (maturity_mths_from_next_reset < maturity_period)
		mths_to_next_reset_prelim = maturity_period - maturity_mths_from_next_reset;
	else
		mths_to_next_reset_prelim
		= adj_reset_mths
		  - ((maturity_mths_from_next_reset - maturity_period) % pmt_mths);

	if (pmt_reset_first_period != mths_to_next_reset_prelim)
		{
		makeRunLogYellow();
		log_screen << "Warning. ARB Next Reset Date (" << adj_next_reset_date
				<< ") for existing bond '" << asset_id
				<< "' does not fall"
				<< MSG_ERROR;
		log_screen << " ... on a payment date and has been reset to "
				<< 1 + ((proj_start_mth + pmt_reset_first_period - 2) % 12)
				<< "/"
				<< proj_start_yr
				  + xint((proj_start_mth + pmt_reset_first_period - 2) / 12)
				<< "." << MSG_ERROR;
		}
	} 

// Set up par_val_at_issue
par_val_at_issue = par_val_at_issue_mp * neg_asset_flag;

return;
}



#line 1 "setup_psa_base_rate.BOND_ASSET.for"                                                                                   
void BOND_ASSET::setup_psa_base_rate()
{
psa_base_rate.resize(31);

psa_base_rate[0] = 0.0;

for (int month = 1; month <= 30; month++)
	psa_base_rate[month]
	= psa_base_rate[month - 1] + .002;

return;
}



#line 1 "setup_purch_inv_asset.BOND_ASSET.for"                                                                                   
void BOND_ASSET::setup_purch_inv_asset(int t, int save_assets, int panum, int new_mp_num, double purch_asset_amt, int &asset_mp_sequence_num)
{
if (existing_asset_indicator)
	return;

initialize(t);

purch_asset_id = company->sm_inv_strategy[seg_num]->purch_assets_id[panum];
company->sm_inv_strategy[seg_num]->purch_asset_id = purch_asset_id;
asset_id = purch_asset_id;

// Set up aset model point sequence number and model point group
if (save_assets == YES)
	{
	sequence_id = asset_mp_sequence_num + 1;
	asset_mp_sequence_num = asset_mp_sequence_num + 1;

	xstring asset_mp_group_tag
	= asset->set_mp_grp(t,
	                    new_mp_num,
	                    seg_id,
						company->sm_inv_strategy[seg_num]->purch_assets_mp_grp_tag[panum],
	                    purch_asset_id,
	                    sequence_id,
	                    company->sm_inv_strategy[seg_num]->inv_purch_timing);
	
	setGroup(asset_mp_group_tag);
	}
else
	sequence_id = 0;

purch_amt = purch_asset_amt;
purch_asset_sub_port = company->sm_inv_strategy[seg_num]->purch_assets_asset_sub_port_num[panum];

// use_mp = YES; (default)
category_id = company->sm_inv_strategy[seg_num]->purch_bond_category_id;
adj_reset_category_id = company->sm_inv_strategy[seg_num]->purch_bond_adj_category_id;
portfolio_sprd_adj_aig = company->sm_inv_strategy[seg_num]->portfolio_sprd_adj_aig; //AIG - portfolio spread adjustment
dur_wtd_sprd_adj_aig = company->sm_inv_strategy[seg_num]->dur_wtd_sprd_adj_aig; //AIG - duration weighted spread adjustment

// Read the variables varying by asset category
ms_rereadGrid();

if (company->sm_inv_strategy[seg_num]->purch_assets_port_defn[panum] == INVESTMENT)
	port_defn = INVESTMENT;

sale_class = company->sm_inv_strategy[seg_num]->purch_bond_sale_class;
issue_date = add_mths_to_date(proj_date_adj, commencement_period);
pmt_mode = company->sm_inv_strategy[seg_num]->purch_bond_pmt_mode;
taxable_pct = company->sm_inv_strategy[seg_num]->purch_bond_taxable_pct;
call_defn = company->sm_inv_strategy[seg_num]->purch_bond_call_defn;
put_defn = company->sm_inv_strategy[seg_num]->purch_bond_put_defn;

// Maturity date
double ytm = company->sm_inv_strategy[seg_num]->purch_bond_yrs_to_maturity;

int add_mths;
if (((double)((int)(12 * ytm))) == (12 * ytm))
	add_mths
	= commencement_period
	  + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
else
	add_mths
	= commencement_period
	  + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;

maturity_date = add_mths_to_date(proj_date_adj, add_mths);

double force_scalar_calc = maturity_period;
force_scalar_calc = pmt_freq;
force_scalar_calc = pmt_mths;

// Call option variables
call_price_sch.resize(0);

if (call_defn != NOT_APPLICABLE)
	{
	call_price_defn = company->sm_inv_strategy[seg_num]->purch_bond_call_price_defn;

	if (company->sm_inv_strategy[seg_num]->purch_bond_call_protect_yrs == 9999)
		call_opt_first_date = xstring("9999/01/01");
	else	
		call_opt_first_date = add_mths_to_date(proj_date, call_first_period);
	
	// Setup yld_maint_addn
	yld_maint_addn = company->sm_inv_strategy[seg_num]->purch_bond_yld_maint_addn;

	force_scalar_calc = call_prem_grading_mths;
	force_scalar_calc = call_prem_related_to_coupon_rate;
	}

// Put option variables
put_price_sch.resize(0);

if (put_defn != NOT_APPLICABLE)
	{
	put_price_defn = company->sm_inv_strategy[seg_num]->purch_bond_put_price_defn;

	if (company->sm_inv_strategy[seg_num]->purch_bond_put_protect_yrs == 9999)
		put_opt_first_date = xstring("9999/01/01"); 
	else	
		put_opt_first_date = add_mths_to_date(proj_date, put_first_period);

	force_scalar_calc = put_prem_grading_mths;
	}

// Setup sinking fund variable and schedule
sinking_fund_defn = company->sm_inv_strategy[seg_num]->purch_bond_sinking_fund_defn;
if (sinking_fund_defn == YES)
	setup_sinking_fund_sch();

// Adjustable rate variables
if (pmt_rate_defn == FLOATING_RATE)
	{
	adj_reset_scen_yr = company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_yr;

	adj_reset_scen_mult = company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_mult;
	
	adj_reset_renewal_addn = company->sm_inv_strategy[seg_num]->purch_bond_adj_scen_addn_renewal;
	
	// Reset months
	int adj_reset_mths_input
	= company->sm_inv_strategy[seg_num]->purch_bond_adj_reset_mths;
	
	if (adj_reset_mths_input <= 0)
		adj_reset_mths = pmt_mths;
	else if (adj_reset_mths_input
			 < (maturity_period - commencement_period))
		adj_reset_mths
		= adj_reset_mths_input
		  + (((maturity_period - commencement_period) / pmt_mths)
			 * pmt_mths - adj_reset_mths_input) % pmt_mths;
	else
		adj_reset_mths
		= maturity_period - commencement_period;
	
	// Issue warning when ARB reset months has been adjusted
	if (is_first_proj_task_loop
		&& pmt_rate_defn == FLOATING_RATE // Forces scalar calc
		&& pmt_reset_first_period < maturity_period)  // Forces scalar calc
		{
		static bool issue_adj_reset_mths_warning = true;

		if (issue_adj_reset_mths_warning
			&& adj_reset_mths != adj_reset_mths_input
			&& (pmt_reset_first_period + adj_reset_mths) < maturity_period)
			{
			issue_adj_reset_mths_warning = false;
			makeRunLogYellow();
			log_screen << "Warning. ARB Reset Months for at least one investment bond"
					<< " is incompatible with its payment frequency."
					<< MSG_ERROR;
			log_screen << " ... For example, ARB Reset Months (" << adj_reset_mths_input
					<< ") for investment bond '" << asset_id
					<< "' is incompatible with its"
					<< MSG_ERROR;
			log_screen << " ... payment frequency (" << pmt_mode
					<< ") and has been reset to " << adj_reset_mths
					<< "." << MSG_ERROR;
			}
		}

	// Out of record order since must calculate after adj_reset_mths has been set
	adj_next_reset_date = add_mths_to_date(proj_date_adj, pmt_reset_first_period); //20240806 WTW bug fix

	adj_max_incr_per_reset = company->sm_inv_strategy[seg_num]->purch_bond_adj_max_reset_incr;
	
	adj_max_decr_per_reset = company->sm_inv_strategy[seg_num]->purch_bond_adj_max_reset_decr;
	
	adj_min_rate
	= max(0.0, coupon_rate_at_issue
	           - company->sm_inv_strategy[seg_num]->purch_bond_adj_max_below_init);
	
	adj_max_rate
	= coupon_rate_at_issue
	  + company->sm_inv_strategy[seg_num]->purch_bond_adj_max_above_init;
	}

// Initial payment rate
init_pmt_rate = coupon_rate_at_issue; // Forces scalar calc

// Par value at issue is actually the price at issue
par_val_at_issue = mkt_val_bef_sale(commencement_period);

avr_contribn_pct = company->sm_inv_strategy[seg_num]->purch_bond_avr_contribn_pct;
avr_max_pct = company->sm_inv_strategy[seg_num]->purch_bond_avr_max_pct;
avr_obj_pct = company->sm_inv_strategy[seg_num]->purch_bond_avr_obj_pct;	
rbc_c1_pct = company->sm_inv_strategy[seg_num]->purch_bond_rbc_c1_pct;
	
// Force calculation of refinancing_rate_opt_sprd to avoid resetting model later
force_scalar_calc = refinancing_rate_opt_sprd;
	
// Force calculation of net_yld_at_issue to reduce sliding windows size
if (net_yld_at_issue_flag == YES)
	force_scalar_calc = net_yld_at_issue;
	
return;
}



#line 1 "setup_sinking_fund_sch.BOND_ASSET.for"                                                                                   
void BOND_ASSET::setup_sinking_fund_sch()
{
if (existing_asset_indicator == PRIOR_PURCH 
	|| existing_asset_indicator == PROXY_BOND)
	{
	if (read_sch_file_flag)
		read_sch_file();

	return;
	}

if (sinking_fund_sch.size() < sch_array_size)
	sinking_fund_sch.resize(sch_array_size);

double cumul_future_pct = 0.0;

for (int month = start_period; month <= maturity_period; month++)
	{
	double sinking_fund_pct = 0.0;
	if (existing_asset_indicator == INIT_MP)
		sinking_fund_pct = sinking_fund_prin_pmt_pct.AtTime(month);
	else // existing_asset_indicator == NEW_PURCH
		{
		company->sm_inv_strategy[seg_num]->mths_since_issue = month - start_period;
		sinking_fund_pct = company->sm_inv_strategy[seg_num]->purch_bond_sinking_fund_prin_pmt_pct;
		}
		
	if (sinking_fund_pct < 0.0 - rate_ratio_threshold)
		throw FatalError("Sinking fund bond, " + asset_id
                 + ", has negative future principal payment; Please correct sinking fund schedule input.");

	cumul_future_pct += sinking_fund_pct;
	sinking_fund_sch[month - start_period] = sinking_fund_pct;
	}

if (cumul_future_pct < rate_ratio_threshold)
	throw FatalError("Sinking fund bond, " + asset_id
					 + ", principal payments add to 0%; Please correct sinking fund schedule input.");

// For new purchase, sinking fund schedule must add to 1. For existing model points, it does not have to.
// As long as it's not 0, sinking_fund_sch_base column will normalize it.
if (existing_asset_indicator == NEW_PURCH 
	&& abs(cumul_future_pct - 1.0) > rate_ratio_threshold)
	throw FatalError("New purchase sinking fund bond, " + asset_id
					 + ", principal payments do not add to 100%; Please correct sinking fund schedule input.");

return;
}



#line 1 "shrink_bond_clone.BOND_ASSET.for"                                                                                   
void BOND_ASSET::shrink_bond_clone(int mp)
{
// Only shrink in portfolio model
if (isMainModel)
	return;

if (mp >= 0)
	{
	if (mp < asset->sm_bond.size())
		{
		BOND_ASSET *prior_bond_element = asset->sm_bond[mp];

		if(!prior_bond_element->bond_pv->isShrunk)
			prior_bond_element->bond_pv->shrink();
		if(!prior_bond_element->bond_is->isShrunk)
			prior_bond_element->bond_is->shrink();
		if(!prior_bond_element->bond_ym->isShrunk)
			prior_bond_element->bond_ym->shrink();
		}
	else
		// this should never occur
		throw FatalError("mp (" + xstring(mp)
						 + ") >= bond.size (" + xstring(asset->sm_bond.size())
						 + " in bond->shrink_bond_clone.");
	}

return;
}



#line 1 "solve_for_coupon_rate.BOND_ASSET.for"                                                                                   
double BOND_ASSET::solve_for_coupon_rate(int t, double target_value) 
{
double initial_payment_rate = 0.0;
double initial_value = 0.0;
double final_payment_rate = 0.0;
int maximum_iterations = 0;
double tolerance = 0.0;
double low_rate = 0.0;
double high_rate = 0.0;
double adjustment_factor = 0.0;
int decrease_value = 0;
int increase_value = 0;
double low_value = 0.0;
int decrease_rate = 0;
int increase_rate = 0;
double high_value = 0.0;
int loop = 0;
double guess_rate = 0.0;
double guess_value = 0.0;
int done = 0;
double value_factor = 0.0;
double spread_factor = 0.0;
double first_difference_1 = 0.0;
double first_difference_2 = 0.0;
double second_difference = 0.0;
double preliminary_guess_rate = 0.0;
xstring interpolation_code = "";

#define MAX_Iterations 10

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Solve For Coupon Rate"
			<< " for " << asset_id
			<< " t=" << t
			<< " Cal yr=" << xint(cal_yr(t))
			<< " Cal mth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	}

pmt_rate_init_guess
= category_refinancing_rate(t, 
		maturity_period,
		weighted_avg_life_opt_sensitivity(t),
		0.0, // opt_sprd 
		NOMINAL_SEMIANNUAL,
		NO_SHIFT /* shift_defn */); 

// Reset models
bond->resetValues();
bond_cf->resetValues();
bond_pv->resetValues();
bond_ym->resetValues();
if (asset_detail_rpt_pv_flag(t))
	{
	asset_detail_log_rebase_reset(t,
	                              "bond->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_cf->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_pv->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	}

initial_payment_rate = bond_pv->pmt_rate(t);
initial_value = mkt_val_bef_sale(t);

if (asset_detail_rpt_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Solving Process in Solve For Coupon Rate"
			<< " for " << asset_id
			<< " t=" << t
			<< " Cal yr=" << xint(cal_yr(t))
			<< " Cal mth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();

	if (asset_detail_rpt_pv_defn == YES)
		PVCFile << "NotionalAmt," << write_string(notional_amt(t),PVCLen,PVCSigDig) << endl
				<< "InitVal," << write_string(initial_value,PVCLen,PVCSigDig) << endl
				<< "TgtVal," << write_string(target_value,PVCLen,PVCSigDig) << endl
				<< "MthsToMat," << maturity_period - t << endl; 
	}

if (initial_value == target_value)
	final_payment_rate = pmt_rate_init_guess;
else
	{
	maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;
	tolerance = SOLVE_FOR_SPREAD_TOLERANCE;
	low_rate = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;
	high_rate = SOLVE_FOR_SPREAD_LOWEST_SPREAD;

	// Reduce tolerance if target is too large
	if (ceil(log10(fabs(target_value))) > 9)
		tolerance = tolerance * pow(10.0, ceil(log10(fabs(target_value))) - 9);

	adjustment_factor = 0.9;

	if (initial_value < target_value)
		{
		decrease_value = 0;
		increase_value = 1;
		low_rate = initial_payment_rate;
		low_value = initial_value;
		decrease_rate = 0;
		increase_rate = 1;
		}
	else
		{
		decrease_value = 1;
		increase_value = 0;
		high_rate = initial_payment_rate;
		high_value = initial_value;
		decrease_rate = 1;
		increase_rate = 0;
		}

	for (loop = 0;
		loop < maximum_iterations
			&& (decrease_rate < 2 || increase_rate < 2);
		loop++)
		{
		if (increase_rate == 1)
			guess_rate = (adjustment_factor + low_rate) 
						 / adjustment_factor;
		else
			guess_rate
				= max(0.0, high_rate
						   - (1 - pow(adjustment_factor, loop + 1))
							 * (NOMINAL_SEMIANNUAL 
								+ high_rate));

		// Reset both models so new values will be calculated
		bond->resetValues();
		bond_cf->resetValues();
		bond_pv->resetValues();
		bond_ym->resetValues();
		if (asset_detail_rpt_pv_flag(t))
			{
			asset_detail_log_rebase_reset(t,
			                              "bond->resetValues",
			                              "bond->solve_for_coupon_rate",
			                              asset_id,
			                              modelName);
			asset_detail_log_rebase_reset(t,
			                              "bond_cf->resetValues",
			                              "bond->solve_for_coupon_rate",
			                              asset_id,
			                              modelName);
			asset_detail_log_rebase_reset(t,
			                              "bond_pv->resetValues",
			                              "bond->solve_for_coupon_rate",
			                              asset_id,
			                              modelName);
			}

		pmt_rate_init_guess = guess_rate;
		guess_value = mkt_val_bef_sale(t);

		if (guess_rate == 0.0)
			{
			if (guess_value > target_value)
				{
				makeRunLogYellow();
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "Warning. Cannot solve for payment rate such that the price"
						 << " of " << asset_id
						 << " |" << modelName
						 << " equals " << target_value
						 << " in year " << xint(cal_yr(t))
						 << " month " << xint(cal_mth(t))
						 << " Price at payment rate 0.0 is " << guess_value
						 << " Payment rate has been set to zero. Please check your input."
						 << MSG_ERROR;
				log_screen.unsetf(ios::fixed);

				final_payment_rate = 0.0;
				goto reset_parameters;
				}
			}

		if (decrease_value == 1)
			{
			if (guess_value >= high_value)
				{
				// If not getting closer, change direction of increment to spread
				decrease_rate++;
				increase_rate++;
				}
			else
				{
				if (guess_value > target_value)
					{
					// Reset high value and corresponding spread.
					high_rate = guess_rate;
					high_value = guess_value;
					}
				else // Otherwise, exit for loop.
					loop = maximum_iterations;
				}
			}

		if (increase_value == 1)
			{
			if (guess_value <= low_value)
				{
				// If not getting closer, change direction of increment to spread
				decrease_rate++;
				increase_rate++;
				}
			else
				{
				if (guess_value < target_value)
					{
					// Reset low value and corresponding spread.
					low_rate = guess_rate;
					low_value = guess_value;
					}
				else
					// Otherwise, exit for loop. 
					loop = maximum_iterations;
				}
			}
		}

	if (decrease_value > 1 && increase_value > 1)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning. Cannot solve for payment rate"
				 << " of " << asset_id
				 << " |" << modelName
				 << " in year " << xint(cal_yr(t))
				 << " month " << xint(cal_mth(t))
				 << " Using guess rate " << convert_rate_basis(guess_rate, NOMINAL_SEMIANNUAL, 1)
				 << " Target value " << target_value
				 << " is less than guess value " << guess_value 
				 << " Payment rate has been set to zero. Please check your input."
				 << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		final_payment_rate = 0.0;
		goto reset_parameters;
		}

	if (increase_value == 1)
		{
		high_rate = guess_rate;
		high_value = guess_value;
		}
	else
		{
		low_rate = guess_rate;
		low_value = guess_value;
		}
	   
	if (high_value == low_value)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning. Cannot solve for payment rate such that the price"
				 << " of " << asset_id
				 << " |" << modelName
				 << " equals " << target_value
				 << " in year " << xint(cal_yr(t))
				 << " month " << xint(cal_mth(t))
				 << " Price at payment rate 0.0 is " << guess_value
				 << " Payment rate has been set to zero. Please check your input."
				 << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		final_payment_rate = 0.0;
		goto reset_parameters;
		}

	for (loop = 0; loop < maximum_iterations + 1; loop++)
		{
		if (loop > 0)
			{
			// Calculate final payment rate based on calculated low,
			// merge and high payment rates using the following difference table.  
			// PV Rate 1st Difference 2nd Difference  
			// --------- ------ ------------------------------  
			// LowVal l  
			// prem_pattern_ratio - l  
			// A = ---------------
			// GueVal - LowVal B - A  
			// GueVal prem_pattern_ratio C = ---------------
			// h - prem_pattern_ratio HghVal - LowVal  
			// B = ---------------
			// HghVal - GueVal  
			// HghVal h
			// NewRate = l + (TargVal - LowVal)  * A
			// + (TargVal - LowVal)  * (TargVal - GueVal)  * C  
			// If NewRate is out of bounds, use bisection. For first and
			// last pass use linear interpolation.  
			// This adjustment is being made because of nonlinear
			// dependence of the duration on the planned factor.  

			first_difference_1
			= (guess_rate - low_rate) / (guess_value - low_value);

			first_difference_2
			= (high_rate - guess_rate) / (high_value - guess_value);

			second_difference
			= (first_difference_2 - first_difference_1)
			  / (high_value - low_value);

			preliminary_guess_rate
			= low_rate + (target_value - low_value) * first_difference_1
			  + (target_value - low_value)
			    * (target_value - guess_value)
				* second_difference;

			if (guess_value < target_value)
				{
				low_value = guess_value;
				low_rate = guess_rate;
				}
			else
				{
				high_value = guess_value;
				high_rate = guess_rate;
				}
			}

		if (loop > 0
			&& ((low_rate < high_rate 
				 && preliminary_guess_rate < high_rate
				 && preliminary_guess_rate > low_rate)
				|| (low_rate > high_rate
					&& preliminary_guess_rate > high_rate
					&& preliminary_guess_rate < low_rate)))
			{
			// quadratic interpolation
			guess_rate = preliminary_guess_rate;
			if (asset_detail_rpt_pv_flag(t))
				interpolation_code = "QI";
			}
		else if (loop > 0 && loop < maximum_iterations)
			{
			//  bisection
			guess_rate = low_rate + (high_rate - low_rate) / 2.0;
			if (asset_detail_rpt_pv_flag(t))
				interpolation_code = "BI";
			}
		else
			{
			//  linear interpolation
			guess_rate
			= low_rate
			  + (high_rate - low_rate)
				* (target_value - low_value)
				  / (high_value - low_value);
			if (asset_detail_rpt_pv_flag(t))
				interpolation_code = "LI";
			}

		if (loop < maximum_iterations)
			{
			pmt_rate_init_guess = guess_rate;

			// need to reset both models so new values will be calculated
			bond->resetValues();
			bond_cf->resetValues();
			bond_pv->resetValues();
			if (asset_detail_rpt_pv_flag(t))
				{
				asset_detail_log_rebase_reset(t,
				                              "bond->resetValues",
				                              "bond->solve_for_coupon_rate",
				                              asset_id,
				                              modelName);
				asset_detail_log_rebase_reset(t,
				                              "bond_cf->resetValues",
				                              "bond->solve_for_coupon_rate",
				                              asset_id,
				                              modelName);
				asset_detail_log_rebase_reset(t,
				                              "bond_pv->resetValues",
				                              "bond->solve_for_coupon_rate",
				                              asset_id,
				                              modelName);
				}

			guess_value = mkt_val_bef_sale(t);

			if (asset_detail_rpt_pv_flag(t))
				{
				PVCText << "Interpolation Code: " << interpolation_code 
					    << " Loop=" << loop 
						<< " for " << asset_id
						<< " t= " << t
						<< " CalYr=" << xint(cal_yr(t)) 
						<< " CalMth=" << xint(cal_mth(t));
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_rpt_pv_output();
				PVCText	<< "TgtVal," << write_string(target_value,PVCLen,PVCSigDig) << endl
						<< "Tol,"    << write_string(tolerance,PVCLen,PVCSigDig) << endl
						<< "LowRate," << write_string(low_rate,PVCLen,PVCSigDig) << endl
						<< "LowVal," << write_string(low_value,PVCLen,PVCSigDig) << endl
						<< "HighRate," << write_string(high_rate,PVCLen,PVCSigDig) << endl
						<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig) << endl
						<< "GsRate," << write_string(guess_rate,PVCLen,PVCSigDig) << endl
						<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig);
				asset_detail_rpt_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				loop = 999;
			}	// endif
		}	// end_for
	}	// endif

final_payment_rate = guess_rate;

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Solving Process in Solve For Coupon Rate ("
			<< write_string(final_payment_rate,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << t
			<< " Cal yr=" << xint(cal_yr(t))
			<< " Cal mth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

// Restore asset variables.
reset_parameters:
bond->resetValues();
bond_cf->resetValues();
bond_pv->resetValues();
if (asset_detail_rpt_pv_flag(t))
	{
	asset_detail_log_rebase_reset(t,
	                              "bond->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_cf->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	asset_detail_log_rebase_reset(t,
	                              "bond_pv->resetValues",
	                              "bond->solve_for_coupon_rate",
	                              asset_id,
	                              modelName);
	}

if (asset_detail_rpt_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Solve For Coupon Rate ("
			<< write_string(final_payment_rate,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << t
			<< " Cal yr=" << xint(cal_yr(t))
			<< " Cal mth=" << xint(cal_mth(t));
	asset_detail_rpt_pv_output();
	PVCounter--;
	}

return final_payment_rate;
}



#line 1 "validate_data.BOND_ASSET.for"                                                                                   
void BOND_ASSET::validate_data(void) 
{
if (!cloning_wanted)
	throw FatalError("You must select 'Yes' for the 'Cloning Wanted' projection task property "
	                 "in order to include bonds in the projection.");

if (existing_asset_indicator)
	{
	if (init_par_val == 0)
		{
		if (is_first_proj_task_loop && data_validation_defn == YES)
			{
			makeRunLogYellow();
		
			log_screen << "Warning. Existing bond has no value."
					   << " Asset has been discarded."
					   << " Id= " << asset_id
					   << MSG_USER;                     
			}
	
		skipModelPoint();
		return;
		}

	if (init_cost_basis == 0)
		throw FatalError("Cost Basis is zero for existing bond " + asset_id
						 + ". Please correct data before running.");

	if (calculated_t_high < 1 && !isMainModel)
		{
		xstring index_val = seg_id + "_bond" + asset_id + data_grp_id + xstring(data_rec_num());
	
		if ((asset->init_cash_bal_map_iter
				= asset->init_cash_bal_map.find(index_val))
			== asset->init_cash_bal_map.end())
			{
			if (data_validation_defn == YES)
				{
				makeRunLogYellow();
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "Warning. Existing bond " << asset_id
							<< " has matured before model start date."
							<< " Asset par value (" << setprecision(2) << init_par_val
							<< ") has been added to the cash account."
							<< MSG_ERROR;
				}
		
			asset->init_cash_bal_map[index_val] = init_par_val;
			}
	
		skipModelPoint();
		return;
		}
	}

return;
}



#line 1 "write_sch_file.BOND_ASSET.for"                                                                                   
void BOND_ASSET::write_sch_file(xstring sch_file)
{
// Initial bonds will get values from external source data, no need to write csv schedule file
if (existing_asset_indicator == INIT_MP) 
	return;

if (proj_set_sub_loop_num == valn_periods.size())
	return;

static bool first_time = true;

if (first_time)
	{
	first_time = false;
	struct stat buffer;
	int stat_val = stat(sch_file.c_str(), &buffer);

	// Delete existing file, to create fresh
	if (stat_val == 0)
		remove(sch_file);
	}

// Open state of world file and write header
if (!bond_sch_output.is_open())
	{
	bond_sch_output.open(sch_file);
	bond_sch_output.setf(ios::fixed);
	bond_sch_output.precision(12);

	// Write header
	bond_sch_output 
	<< "asset_id" << ","					// col 0 = asset_id
	<< "date" << ","						// col 1 = date
    << "call_price_pct" << ","              // col 2 = call_price_pct
    << "put_price_pct" << ","               // col 3 = put_price_pct
	<< "sinking_fund_prin_pmt_pct" << endl; // col 4 = sinking_fund_prin_pmt_pct
	}

bool call_sch_flag = false;
if (call_defn != NOT_APPLICABLE && call_price_defn == PRICE_SCHEDULE)
	call_sch_flag = true;

bool put_sch_flag = false;
if (put_defn != NOT_APPLICABLE && put_price_defn == PRICE_SCHEDULE)
	put_sch_flag = true;

bool sinking_fund_sch_flag = false;
if (sinking_fund_defn == YES)
	sinking_fund_sch_flag = true;

if (call_defn != NOT_APPLICABLE && call_price_defn == RELATED_TO_COUPON)
	{
	call_sch_flag = true;

	// fill schedule array so same process is used to create new schedule file
	if (call_price_sch.size() < sch_array_size)
		call_price_sch.resize(sch_array_size);

	for (int month = 1; month <= maturity_period - start_period; month++)
		{
		double call_price_pct = 1.0;
		if (month <= call_par_first_period - start_period)
			call_price_pct
			= 1.0 
			  + call_prem_related_to_coupon_rate
				* (call_par_first_period - start_period - month)
				/ call_prem_grading_mths;

		call_price_sch[month] = call_price_pct;
		}
	}

if (put_defn != NOT_APPLICABLE && put_price_defn == RELATED_TO_COUPON)
	{
	put_sch_flag = true;

	// fill schedule array so same process is used to create new schedule file
	if (put_price_sch.size() < sch_array_size)
		put_price_sch.resize(sch_array_size);

	for (int month = 1; month <= maturity_period - start_period; month++)
		{
		double put_price_pct = 1.0;
		if (month <= put_par_first_period - start_period)
			put_price_pct
			= 1.0 
			  + put_prem_related_to_coupon_rate
				* (put_par_first_period - start_period - month)
				/ put_prem_grading_mths;

		put_price_sch[month] = put_price_pct;
		}
	}

double curr_call_price_pct = 1.0;
double curr_put_price_pct = 1.0;
double curr_sinking_fund_prin_pmt_pct = 0.0;
double prev_call_price_pct = 1.0;
double prev_put_price_pct = 1.0;
double prev_sinking_fund_prin_pmt_pct = 0.0;
bool new_data_flag = true;

for (int month = last_proj_period; month <= maturity_period; month++)
	{
	xstring curr_date = get_string_of_date(date(month));

	if (call_sch_flag)
		{
		curr_call_price_pct = call_price_sch[month - start_period];
		if (abs(curr_call_price_pct - prev_call_price_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_call_price_pct = curr_call_price_pct;
		}

	if (put_sch_flag)
		{
		curr_put_price_pct = put_price_sch[month - start_period];
		if (abs(curr_put_price_pct - prev_put_price_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_put_price_pct = curr_put_price_pct;
		}

	if (sinking_fund_sch_flag)
		{
		curr_sinking_fund_prin_pmt_pct = sinking_fund_sch[month - start_period];
		if (curr_sinking_fund_prin_pmt_pct > rate_ratio_threshold
			|| abs(curr_sinking_fund_prin_pmt_pct - prev_sinking_fund_prin_pmt_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_sinking_fund_prin_pmt_pct = curr_sinking_fund_prin_pmt_pct;
		}

	// Only write out if data changed except the first record
	if (new_data_flag)
		bond_sch_output
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



#line 1 "write_state_of_world_mp.BOND_ASSET.for"                                                                                   
void BOND_ASSET::write_state_of_world_mp(void)
{
static bool first_time = true;

xstring data_file_name = replaceWildcards(data_location());

xstring bond_state_of_world_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

xstring sch_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (first_time)
	{
	first_time = false;

	struct stat buffer;
	int stat_val = stat(bond_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(bond_state_of_world_file);
	}
 
if (!bond_state_of_world_mp_output.is_open())
	{
   	bond_state_of_world_mp_output.setf(ios::fixed);
	bond_state_of_world_mp_output.precision(12);
	bond_state_of_world_mp_output.open(bond_state_of_world_file);

	// Write header
	bond_state_of_world_mp_output			// Values from inforce mp
	<< "group" << ","						// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","					// col 1 = seg_id
	<< "asset_id_mp" << ","					// col 2 = asset_id
	<< "use_mp" << ","						// col 3 = use_mp
	<< "category_id_mp" << ","				// col 4 = category_id
	<< "port_defn_mp" << ","				// col 5 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","				// col 6 = get_string_of_enum_val(sale_class)
	<< "issue_date_mp" << ","				// col 7 = issue_date
	<< "maturity_date_mp" << ","			// col 8 = maturity_date
	<< "planned_sale_date_mp" << ","		// col 9 = planned_sale_date
	<< "init_par_val_mp" << ","				// col 10 = notional_amt(last_proj_period)
	<< "init_cost_basis_mp" << ","			// col 11 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","				// col 12 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","				// col 13 = mkt_val(last_proj_period)
	<< "pmt_mode_mp" << ","					// col 14 = get_string_of_enum_val(pmt_mode)
	<< "init_pmt_rate_mp" << ","			// col 15 = sm_bond_cf->pmt_rate(last_proj_period)
	<< "par_val_at_issue_mp" << ","			// col 16 = par_val_at_issue
	<< "taxable_pct_mp" << ","				// col 17 = taxable_pct
	<< "call_opt_first_date_mp" << ","		// col 18 = call_opt_first_date
	<< "call_price_defn_mp" << ","			// col 19 = get_string_of_enum_val(call_price_defn)
	<< "call_defn_mp" << ","				// col 20 = get_string_of_enum_val(call_defn)
	<< "yld_maint_addn_mp" << ","			// col 21 = yld_maint_addn
	<< "put_opt_first_date_mp" << ","		// col 22 = put_opt_first_date
	<< "put_defn_mp" << ","					// col 23 = get_string_of_enum_val(put_defn)
	<< "sinking_fund_defn_mp" << ","		// col 24 = get_string_of_enum_val(sinking_fund_defn)
	<< "adj_reset_category_id_mp" << ","	// col 25 = adj_reset_category_id
	<< "adj_reset_scen_yr_mp" << ","		// col 26 = adj_reset_scen_yr
	<< "adj_reset_scen_mult_mp" << ","		// col 27 = adj_reset_scen_mult
	<< "adj_reset_renewal_addn_mp" << ","	// col 28 = adj_reset_renewal_addn
	<< "adj_next_reset_date_mp" << ","		// col 29 = adj_next_reset_date
	<< "adj_reset_mths_mp" << ","			// col 30 = adj_reset_mths
	<< "adj_max_incr_per_reset_mp" << ","	// col 31 = adj_max_incr_per_reset
	<< "adj_max_decr_per_reset_mp" << ","	// col 32 = adj_max_decr_per_reset
	<< "adj_min_rate_mp" << ","				// col 33 = adj_min_rate
	<< "adj_max_rate_mp" << ","				// col 34 = adj_max_rate
	<< "avr_contribn_pct_mp" << ","			// col 35 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","				// col 36 = avr_max_pct
	<< "avr_obj_pct_mp" << ","				// col 37 = avr_obj_pct
	<< "rbc_c1_pct_mp" << ","				// col 38 = rbc_c1_pct
	<< "portfolio_sprd_adj_aig_mp" << ","				 //08/12/2024
	<< "dur_wtd_sprd_adj_aig_mp" << endl;				 //08/12/2024
	}

static int counter = 1;
xstring group_mp = get_base_group_name(group, true);//WTW - Gen2 - Move Extern definitions to rates header
xstring port_defn = get_string_of_enum_val(this->port_defn);
xstring sale_class = get_string_of_enum_val(this->sale_class);
double notional_amt = this->notional_amt(last_proj_period);
double cost_basis = this->cost_basis(last_proj_period);
double bk_val = this->bk_val(last_proj_period);
double mkt_val = this->mkt_val(last_proj_period);
xstring pmt_mode = get_string_of_enum_val(this->pmt_mode);
double pmt_rate = sm_bond_cf->pmt_rate(last_proj_period);

xstring call_price_defn = "";
if (this->call_price_defn == RELATED_TO_COUPON)
	call_price_defn = "Price Schedule";
else
	call_price_defn = get_string_of_enum_val(this->call_price_defn);

xstring call_defn = get_string_of_enum_val(this->call_defn);
xstring put_defn = get_string_of_enum_val(this->put_defn);
xstring sinking_fund_defn = get_string_of_enum_val(this->sinking_fund_defn);

bond_state_of_world_mp_output
<< group_mp << ","
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
<< rbc_c1_pct << ","
<< portfolio_sprd_adj_aig << "," //08/12/2024
<< dur_wtd_sprd_adj_aig << endl;//08/12/2024

counter++;

if (write_sch_file_flag)
	write_sch_file(sch_file);

return;
}



void BOND_ASSET::Terminator()
{

if (PVCFile != NULL)
	PVCFile.close();

}

FunctionPtr BOND_ASSET::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static BOND_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (BOND_ASSET_UDF::*dPXi) (int);
typedef double (BOND_ASSET_UDF::*dPXid) (int, double);
typedef double (BOND_ASSET_UDF::*dPF) ();
typedef double (BOND_ASSET_UDF::*dPFd) (double);
typedef int (BOND_ASSET_UDF::*iPF) ();
typedef int (BOND_ASSET_UDF::*iPFi) (int);
typedef xstring (BOND_ASSET_UDF::*sPF) ();
typedef xstring (BOND_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData BOND_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_inc", "bond_asset_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(2, "accr_int", "bond_asset_accr_int",  "accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int),
	CashFlowCommonData(3, "accr_int_aft_dflt", "bond_asset_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(4, "accr_int_aft_put", "bond_asset_accr_int_aft_put",  "accr_int_aft_put",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_aft_put, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_put),
	CashFlowCommonData(5, "accr_int_bef_call", "bond_asset_accr_int_bef_call",  "accr_int_bef_call",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_bef_call, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_call),
	CashFlowCommonData(6, "accr_int_bef_fund_match_sale", "bond_asset_accr_int_bef_fund_match_sale",  "accr_int_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_fund_match_sale),
	CashFlowCommonData(7, "accr_int_bef_neg_cash_flow_sale", "bond_asset_accr_int_bef_neg_cash_flow_sale",  "accr_int_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_neg_cash_flow_sale),
	CashFlowCommonData(8, "accr_int_bef_rebal_sale", "bond_asset_accr_int_bef_rebal_sale",  "accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_rebal_sale),
	CashFlowCommonData(9, "accr_int_bef_sale", "bond_asset_accr_int_bef_sale",  "accr_int_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_bef_sale),
	CashFlowCommonData(10, "accr_int_dflt", "bond_asset_accr_int_dflt",  "accr_int_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_dflt),
	CashFlowCommonData(11, "accr_int_purch", "bond_asset_accr_int_purch",  "accr_int_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_purch, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_purch),
	CashFlowCommonData(12, "accr_int_rent", "bond_asset_accr_int_rent",  "accr_int_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_rent, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_rent),
	CashFlowCommonData(13, "accr_int_sold", "bond_asset_accr_int_sold",  "accr_int_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_accr_int_sold, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_sold),
	CashFlowCommonData(14, "asset_detail_rpt_pv_flag", "bond_asset_asset_detail_rpt_pv_flag",  "asset_detail_rpt_pv_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_asset_detail_rpt_pv_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_detail_rpt_pv_flag),
	CashFlowCommonData(15, "asset_min_size_sale_flag", "bond_asset_asset_min_size_sale_flag",  "asset_min_size_sale_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_asset_min_size_sale_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_min_size_sale_flag),
	CashFlowCommonData(16, "avr_basic_contribn", "bond_asset_avr_basic_contribn",  "avr_basic_contribn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_basic_contribn, 'E','N', '3', 'C', (size_t)&modelOffset->avr_basic_contribn),
	CashFlowCommonData(17, "avr_basic_contribn_bef_sale", "bond_asset_avr_basic_contribn_bef_sale",  "avr_basic_contribn_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_basic_contribn_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_basic_contribn_bef_sale),
	CashFlowCommonData(18, "avr_max", "bond_asset_avr_max",  "avr_max",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_max, 'E','N', '3', 'C', (size_t)&modelOffset->avr_max),
	CashFlowCommonData(19, "avr_max_bef_sale", "bond_asset_avr_max_bef_sale",  "avr_max_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_max_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->avr_max_bef_sale),
	CashFlowCommonData(20, "avr_obj", "bond_asset_avr_obj",  "avr_obj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_obj, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj),
	CashFlowCommonData(21, "avr_obj_bef_sale", "bond_asset_avr_obj_bef_sale",  "avr_obj_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_obj_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj_bef_sale),
	CashFlowCommonData(22, "avr_realzd_cap_gain", "bond_asset_avr_realzd_cap_gain",  "avr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_avr_realzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->avr_realzd_cap_gain),
	CashFlowCommonData(23, "base_inc_bef_call", "bond_asset_base_inc_bef_call",  "base_inc_bef_call",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_base_inc_bef_call, 'E','Y', '3', 'C', (size_t)&modelOffset->base_inc_bef_call),
	CashFlowCommonData(24, "bk_val", "bond_asset_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(25, "bk_val_aft_dflt", "bond_asset_bk_val_aft_dflt",  "bk_val_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_aft_dflt),
	CashFlowCommonData(26, "bk_val_aft_put", "bond_asset_bk_val_aft_put",  "bk_val_aft_put",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_aft_put, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_aft_put),
	CashFlowCommonData(27, "bk_val_bef_call", "bond_asset_bk_val_bef_call",  "bk_val_bef_call",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_bef_call, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_call),
	CashFlowCommonData(28, "bk_val_bef_fund_match_sale", "bond_asset_bk_val_bef_fund_match_sale",  "bk_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_fund_match_sale),
	CashFlowCommonData(29, "bk_val_bef_neg_cash_flow_sale", "bond_asset_bk_val_bef_neg_cash_flow_sale",  "bk_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(30, "bk_val_bef_rebal_sale", "bond_asset_bk_val_bef_rebal_sale",  "bk_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_rebal_sale),
	CashFlowCommonData(31, "bk_val_bef_sale", "bond_asset_bk_val_bef_sale",  "bk_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_bef_sale),
	CashFlowCommonData(32, "bk_val_plus_accr_int_bef_rebal_sale", "bond_asset_bk_val_plus_accr_int_bef_rebal_sale",  "bk_val_plus_accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_plus_accr_int_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int_bef_rebal_sale),
	CashFlowCommonData(33, "bk_val_purch", "bond_asset_bk_val_purch",  "bk_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_bk_val_purch, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_purch),
	CashFlowCommonData(34, "cal_mth", "bond_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(35, "cal_yr", "bond_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(36, "cal_yr_relative", "bond_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(37, "cap_gain_bef_sale", "bond_asset_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(38, "cap_gain_from_sale", "bond_asset_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(39, "cash_flow", "bond_asset_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cash_flow, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(40, "cost_basis", "bond_asset_cost_basis",  "cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis),
	CashFlowCommonData(41, "cost_basis_accrual", "bond_asset_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_accrual, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(42, "cost_basis_aft_dflt", "bond_asset_cost_basis_aft_dflt",  "cost_basis_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_aft_dflt),
	CashFlowCommonData(43, "cost_basis_aft_put", "bond_asset_cost_basis_aft_put",  "cost_basis_aft_put",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_aft_put, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_aft_put),
	CashFlowCommonData(44, "cost_basis_bef_call", "bond_asset_cost_basis_bef_call",  "cost_basis_bef_call",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_bef_call, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_bef_call),
	CashFlowCommonData(45, "cost_basis_bef_sale", "bond_asset_cost_basis_bef_sale",  "cost_basis_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis_bef_sale),
	CashFlowCommonData(46, "cost_basis_dflt", "bond_asset_cost_basis_dflt",  "cost_basis_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_dflt),
	CashFlowCommonData(47, "cost_basis_incr_appreciation", "bond_asset_cost_basis_incr_appreciation",  "cost_basis_incr_appreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_incr_appreciation, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_incr_appreciation),
	CashFlowCommonData(48, "cost_basis_purch", "bond_asset_cost_basis_purch",  "cost_basis_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_purch, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis_purch),
	CashFlowCommonData(49, "cost_basis_sched_prin_pmt", "bond_asset_cost_basis_sched_prin_pmt",  "cost_basis_sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_sched_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_sched_prin_pmt),
	CashFlowCommonData(50, "cost_basis_sold", "bond_asset_cost_basis_sold",  "cost_basis_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_cost_basis_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_sold),
	CashFlowCommonData(51, "date", "bond_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(52, "dflt_amt", "bond_asset_dflt_amt",  "dflt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_dflt_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->dflt_amt),
	CashFlowCommonData(53, "dflt_pct", "bond_asset_dflt_pct",  "dflt_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_dflt_pct, 'E','N', '3', 'C', (size_t)&modelOffset->dflt_pct),
	CashFlowCommonData(54, "dur_val", "bond_asset_dur_val",  "dur_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_dur_val, 'E','N', '3', 'C', (size_t)&modelOffset->dur_val),
	CashFlowCommonData(55, "eff_dur", "bond_asset_eff_dur",  "eff_dur",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->eff_dur),
	CashFlowCommonData(56, "finalize", "bond_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(57, "gaap_inc_bk_val", "bond_asset_gaap_inc_bk_val",  "gaap_inc_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_gaap_inc_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bk_val),
	CashFlowCommonData(58, "gaap_inc_unrealzd_cap_gain", "bond_asset_gaap_inc_unrealzd_cap_gain",  "gaap_inc_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_gaap_inc_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain),
	CashFlowCommonData(59, "gaap_surp_bk_val", "bond_asset_gaap_surp_bk_val",  "gaap_surp_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_gaap_surp_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_surp_bk_val),
	CashFlowCommonData(60, "gaap_unrealzd_cap_gain_incr", "bond_asset_gaap_unrealzd_cap_gain_incr",  "gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(61, "imr_realzd_cap_gain", "bond_asset_imr_realzd_cap_gain",  "imr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_imr_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain),
	CashFlowCommonData(62, "imr_realzd_cap_gain_from_sale", "bond_asset_imr_realzd_cap_gain_from_sale",  "imr_realzd_cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_imr_realzd_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain_from_sale),
	CashFlowCommonData(63, "imr_yrs_to_maturity", "bond_asset_imr_yrs_to_maturity",  "imr_yrs_to_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_imr_yrs_to_maturity, 'E','N', '3', 'C', (size_t)&modelOffset->imr_yrs_to_maturity),
	CashFlowCommonData(64, "initialize", "bond_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(65, "int_div_and_rent", "bond_asset_int_div_and_rent",  "int_div_and_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_int_div_and_rent, 'E','Y', '3', 'P', (size_t)&modelOffset->int_div_and_rent),
	CashFlowCommonData(66, "int_pmt", "bond_asset_int_pmt",  "int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_int_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->int_pmt),
	CashFlowCommonData(67, "mkt_risk_sprd", "bond_asset_mkt_risk_sprd",  "mkt_risk_sprd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_risk_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_risk_sprd),
	CashFlowCommonData(68, "mkt_sprd", "bond_asset_mkt_sprd",  "mkt_sprd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_sprd),
	CashFlowCommonData(69, "mkt_to_bk_ratio", "bond_asset_mkt_to_bk_ratio",  "mkt_to_bk_ratio",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_to_bk_ratio),
	CashFlowCommonData(70, "mkt_val", "bond_asset_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(71, "mkt_val_bef_fund_match_sale", "bond_asset_mkt_val_bef_fund_match_sale",  "mkt_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_bef_fund_match_sale),
	CashFlowCommonData(72, "mkt_val_bef_neg_cash_flow_sale", "bond_asset_mkt_val_bef_neg_cash_flow_sale",  "mkt_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(73, "mkt_val_bef_rebal_sale", "bond_asset_mkt_val_bef_rebal_sale",  "mkt_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_rebal_sale),
	CashFlowCommonData(74, "mkt_val_bef_sale", "bond_asset_mkt_val_bef_sale",  "mkt_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_sale),
	CashFlowCommonData(75, "mkt_val_for_dur_bef_neg_cash_flow_sale", "bond_asset_mkt_val_for_dur_bef_neg_cash_flow_sale",  "mkt_val_for_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(76, "mkt_val_for_dur_bef_rebal_sale", "bond_asset_mkt_val_for_dur_bef_rebal_sale",  "mkt_val_for_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_rebal_sale),
	CashFlowCommonData(77, "mkt_val_for_dur_sold", "bond_asset_mkt_val_for_dur_sold",  "mkt_val_for_dur_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_for_dur_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_sold),
	CashFlowCommonData(78, "mkt_val_for_eff_dur", "bond_asset_mkt_val_for_eff_dur",  "mkt_val_for_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_for_eff_dur, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_for_eff_dur),
	CashFlowCommonData(79, "mkt_val_purch", "bond_asset_mkt_val_purch",  "mkt_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_purch),
	CashFlowCommonData(80, "mkt_val_shifted", "bond_asset_mkt_val_shifted",  "mkt_val_shifted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_shifted, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_shifted),
	CashFlowCommonData(81, "mkt_val_sold", "bond_asset_mkt_val_sold",  "mkt_val_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_sold, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_sold),
	CashFlowCommonData(82, "mkt_val_times_dur_bef_neg_cash_flow_sale", "bond_asset_mkt_val_times_dur_bef_neg_cash_flow_sale",  "mkt_val_times_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_times_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(83, "mkt_val_times_dur_bef_rebal_sale", "bond_asset_mkt_val_times_dur_bef_rebal_sale",  "mkt_val_times_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_times_dur_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_rebal_sale),
	CashFlowCommonData(84, "mkt_val_times_eff_dur", "bond_asset_mkt_val_times_eff_dur",  "mkt_val_times_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mkt_val_times_eff_dur, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_eff_dur),
	CashFlowCommonData(85, "mths_to_next_mkt_val_calc", "bond_asset_mths_to_next_mkt_val_calc",  "mths_to_next_mkt_val_calc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_mths_to_next_mkt_val_calc, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_next_mkt_val_calc),
	CashFlowCommonData(86, "net_yld", "bond_asset_net_yld",  "net_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_net_yld, 'E','N', '3', 'C', (size_t)&modelOffset->net_yld),
	CashFlowCommonData(87, "notional_amt", "bond_asset_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_notional_amt, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(88, "notional_amt_bef_fund_match_sale", "bond_asset_notional_amt_bef_fund_match_sale",  "notional_amt_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_notional_amt_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt_bef_fund_match_sale),
	CashFlowCommonData(89, "notional_amt_bef_neg_cash_flow_sale", "bond_asset_notional_amt_bef_neg_cash_flow_sale",  "notional_amt_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_notional_amt_bef_neg_cash_flow_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_neg_cash_flow_sale),
	CashFlowCommonData(90, "notional_amt_bef_rebal_sale", "bond_asset_notional_amt_bef_rebal_sale",  "notional_amt_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_notional_amt_bef_rebal_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_rebal_sale),
	CashFlowCommonData(91, "notional_amt_bef_sale", "bond_asset_notional_amt_bef_sale",  "notional_amt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_notional_amt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_sale),
	CashFlowCommonData(92, "opt_inc", "bond_asset_opt_inc",  "opt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_opt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_inc),
	CashFlowCommonData(93, "opt_pmt", "bond_asset_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(94, "opt_sprd", "bond_asset_opt_sprd",  "opt_sprd",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_opt_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->opt_sprd),
	CashFlowCommonData(95, "rbc_c1", "bond_asset_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(96, "rbc_c1_bef_sale", "bond_asset_rbc_c1_bef_sale",  "rbc_c1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_rbc_c1_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_bef_sale),
	CashFlowCommonData(97, "realzd_cap_gain", "bond_asset_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(98, "realzd_cap_gain_opt_pmt", "bond_asset_realzd_cap_gain_opt_pmt",  "realzd_cap_gain_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_realzd_cap_gain_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_opt_pmt),
	CashFlowCommonData(99, "realzd_cap_gain_sale", "bond_asset_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_realzd_cap_gain_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(100, "realzd_cap_loss_dflt", "bond_asset_realzd_cap_loss_dflt",  "realzd_cap_loss_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_realzd_cap_loss_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_loss_dflt),
	CashFlowCommonData(101, "risk_sprd", "bond_asset_risk_sprd",  "risk_sprd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_risk_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->risk_sprd),
	CashFlowCommonData(102, "risk_sprd_shifted", "bond_asset_risk_sprd_shifted",  "risk_sprd_shifted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_risk_sprd_shifted, 'E','N', '3', 'C', (size_t)&modelOffset->risk_sprd_shifted),
	CashFlowCommonData(103, "sched_prin_pmt", "bond_asset_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sched_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(104, "sinking_fund_sch_base", "bond_asset_sinking_fund_sch_base",  "sinking_fund_sch_base",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sinking_fund_sch_base, 'E','N', '3', 'C', (size_t)&modelOffset->sinking_fund_sch_base),
	CashFlowCommonData(105, "sold_pct", "bond_asset_sold_pct",  "sold_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sold_pct, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct),
	CashFlowCommonData(106, "sold_pct_fund_match", "bond_asset_sold_pct_fund_match",  "sold_pct_fund_match",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sold_pct_fund_match, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_fund_match),
	CashFlowCommonData(107, "sold_pct_neg_cash_flow", "bond_asset_sold_pct_neg_cash_flow",  "sold_pct_neg_cash_flow",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sold_pct_neg_cash_flow, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_neg_cash_flow),
	CashFlowCommonData(108, "sold_pct_planned", "bond_asset_sold_pct_planned",  "sold_pct_planned",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sold_pct_planned, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_planned),
	CashFlowCommonData(109, "sold_pct_rebal", "bond_asset_sold_pct_rebal",  "sold_pct_rebal",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sold_pct_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_rebal),
	CashFlowCommonData(110, "startup", "bond_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(111, "sub_port_id", "bond_asset_sub_port_id",  "sub_port_id",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_sub_port_id, 'E','N', '3', 'P', (size_t)&modelOffset->sub_port_id),
	CashFlowCommonData(112, "tax_exempt_inc", "bond_asset_tax_exempt_inc",  "tax_exempt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_tax_exempt_inc, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc),
	CashFlowCommonData(113, "unrealzd_cap_gain", "bond_asset_unrealzd_cap_gain",  "unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain),
	CashFlowCommonData(114, "unrealzd_cap_gain_bef_fund_match_sale", "bond_asset_unrealzd_cap_gain_bef_fund_match_sale",  "unrealzd_cap_gain_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_fund_match_sale),
	CashFlowCommonData(115, "unrealzd_cap_gain_bef_neg_cash_flow_sale", "bond_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale",  "unrealzd_cap_gain_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_neg_cash_flow_sale),
	CashFlowCommonData(116, "unrealzd_cap_gain_bef_rebal_sale", "bond_asset_unrealzd_cap_gain_bef_rebal_sale",  "unrealzd_cap_gain_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_rebal_sale),
	CashFlowCommonData(117, "unrealzd_cap_gain_bef_sale", "bond_asset_unrealzd_cap_gain_bef_sale",  "unrealzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_bef_sale),
	CashFlowCommonData(118, "unrealzd_cap_gain_gaap_surp", "bond_asset_unrealzd_cap_gain_gaap_surp",  "unrealzd_cap_gain_gaap_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_gaap_surp, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_gaap_surp),
	CashFlowCommonData(119, "unrealzd_cap_gain_incr", "bond_asset_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(120, "unrealzd_cap_gain_released_on_sale", "bond_asset_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(121, "unrealzd_cap_gain_to_bk_ratio", "bond_asset_unrealzd_cap_gain_to_bk_ratio",  "unrealzd_cap_gain_to_bk_ratio",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_unrealzd_cap_gain_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_to_bk_ratio),
	CashFlowCommonData(122, "weighted_avg_life", "bond_asset_weighted_avg_life",  "weighted_avg_life",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_weighted_avg_life, 'E','N', '3', 'C', (size_t)&modelOffset->weighted_avg_life),
	CashFlowCommonData(123, "weighted_avg_life_opt_sensitivity", "bond_asset_weighted_avg_life_opt_sensitivity",  "weighted_avg_life_opt_sensitivity",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_weighted_avg_life_opt_sensitivity, 'E','N', '3', 'C', (size_t)&modelOffset->weighted_avg_life_opt_sensitivity),
	CashFlowCommonData(124, "yld_denom", "bond_asset_yld_denom",  "yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->yld_denom),
	CashFlowCommonData(125, "yld_numer", "bond_asset_yld_numer",  "yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_yld_numer, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer),
	CashFlowCommonData(126, "yld_numer_adj_aig", "bond_asset_yld_numer_adj_aig",  "yld_numer_adj_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_ASSET_UDF::bond_asset_yld_numer_adj_aig, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer_adj_aig)
};
const CashFlowCommonData* BOND_ASSET::mCFStaticData[] = {
	&BOND_ASSET::mCFStaticData_0[0],
	&BOND_ASSET::mCFStaticData_0[1],
	&BOND_ASSET::mCFStaticData_0[2],
	&BOND_ASSET::mCFStaticData_0[3],
	&BOND_ASSET::mCFStaticData_0[4],
	&BOND_ASSET::mCFStaticData_0[5],
	&BOND_ASSET::mCFStaticData_0[6],
	&BOND_ASSET::mCFStaticData_0[7],
	&BOND_ASSET::mCFStaticData_0[8],
	&BOND_ASSET::mCFStaticData_0[9],
	&BOND_ASSET::mCFStaticData_0[10],
	&BOND_ASSET::mCFStaticData_0[11],
	&BOND_ASSET::mCFStaticData_0[12],
	&BOND_ASSET::mCFStaticData_0[13],
	&BOND_ASSET::mCFStaticData_0[14],
	&BOND_ASSET::mCFStaticData_0[15],
	&BOND_ASSET::mCFStaticData_0[16],
	&BOND_ASSET::mCFStaticData_0[17],
	&BOND_ASSET::mCFStaticData_0[18],
	&BOND_ASSET::mCFStaticData_0[19],
	&BOND_ASSET::mCFStaticData_0[20],
	&BOND_ASSET::mCFStaticData_0[21],
	&BOND_ASSET::mCFStaticData_0[22],
	&BOND_ASSET::mCFStaticData_0[23],
	&BOND_ASSET::mCFStaticData_0[24],
	&BOND_ASSET::mCFStaticData_0[25],
	&BOND_ASSET::mCFStaticData_0[26],
	&BOND_ASSET::mCFStaticData_0[27],
	&BOND_ASSET::mCFStaticData_0[28],
	&BOND_ASSET::mCFStaticData_0[29],
	&BOND_ASSET::mCFStaticData_0[30],
	&BOND_ASSET::mCFStaticData_0[31],
	&BOND_ASSET::mCFStaticData_0[32],
	&BOND_ASSET::mCFStaticData_0[33],
	&BOND_ASSET::mCFStaticData_0[34],
	&BOND_ASSET::mCFStaticData_0[35],
	&BOND_ASSET::mCFStaticData_0[36],
	&BOND_ASSET::mCFStaticData_0[37],
	&BOND_ASSET::mCFStaticData_0[38],
	&BOND_ASSET::mCFStaticData_0[39],
	&BOND_ASSET::mCFStaticData_0[40],
	&BOND_ASSET::mCFStaticData_0[41],
	&BOND_ASSET::mCFStaticData_0[42],
	&BOND_ASSET::mCFStaticData_0[43],
	&BOND_ASSET::mCFStaticData_0[44],
	&BOND_ASSET::mCFStaticData_0[45],
	&BOND_ASSET::mCFStaticData_0[46],
	&BOND_ASSET::mCFStaticData_0[47],
	&BOND_ASSET::mCFStaticData_0[48],
	&BOND_ASSET::mCFStaticData_0[49],
	&BOND_ASSET::mCFStaticData_0[50],
	&BOND_ASSET::mCFStaticData_0[51],
	&BOND_ASSET::mCFStaticData_0[52],
	&BOND_ASSET::mCFStaticData_0[53],
	&BOND_ASSET::mCFStaticData_0[54],
	&BOND_ASSET::mCFStaticData_0[55],
	&BOND_ASSET::mCFStaticData_0[56],
	&BOND_ASSET::mCFStaticData_0[57],
	&BOND_ASSET::mCFStaticData_0[58],
	&BOND_ASSET::mCFStaticData_0[59],
	&BOND_ASSET::mCFStaticData_0[60],
	&BOND_ASSET::mCFStaticData_0[61],
	&BOND_ASSET::mCFStaticData_0[62],
	&BOND_ASSET::mCFStaticData_0[63],
	&BOND_ASSET::mCFStaticData_0[64],
	&BOND_ASSET::mCFStaticData_0[65],
	&BOND_ASSET::mCFStaticData_0[66],
	&BOND_ASSET::mCFStaticData_0[67],
	&BOND_ASSET::mCFStaticData_0[68],
	&BOND_ASSET::mCFStaticData_0[69],
	&BOND_ASSET::mCFStaticData_0[70],
	&BOND_ASSET::mCFStaticData_0[71],
	&BOND_ASSET::mCFStaticData_0[72],
	&BOND_ASSET::mCFStaticData_0[73],
	&BOND_ASSET::mCFStaticData_0[74],
	&BOND_ASSET::mCFStaticData_0[75],
	&BOND_ASSET::mCFStaticData_0[76],
	&BOND_ASSET::mCFStaticData_0[77],
	&BOND_ASSET::mCFStaticData_0[78],
	&BOND_ASSET::mCFStaticData_0[79],
	&BOND_ASSET::mCFStaticData_0[80],
	&BOND_ASSET::mCFStaticData_0[81],
	&BOND_ASSET::mCFStaticData_0[82],
	&BOND_ASSET::mCFStaticData_0[83],
	&BOND_ASSET::mCFStaticData_0[84],
	&BOND_ASSET::mCFStaticData_0[85],
	&BOND_ASSET::mCFStaticData_0[86],
	&BOND_ASSET::mCFStaticData_0[87],
	&BOND_ASSET::mCFStaticData_0[88],
	&BOND_ASSET::mCFStaticData_0[89],
	&BOND_ASSET::mCFStaticData_0[90],
	&BOND_ASSET::mCFStaticData_0[91],
	&BOND_ASSET::mCFStaticData_0[92],
	&BOND_ASSET::mCFStaticData_0[93],
	&BOND_ASSET::mCFStaticData_0[94],
	&BOND_ASSET::mCFStaticData_0[95],
	&BOND_ASSET::mCFStaticData_0[96],
	&BOND_ASSET::mCFStaticData_0[97],
	&BOND_ASSET::mCFStaticData_0[98],
	&BOND_ASSET::mCFStaticData_0[99],
	&BOND_ASSET::mCFStaticData_0[100],
	&BOND_ASSET::mCFStaticData_0[101],
	&BOND_ASSET::mCFStaticData_0[102],
	&BOND_ASSET::mCFStaticData_0[103],
	&BOND_ASSET::mCFStaticData_0[104],
	&BOND_ASSET::mCFStaticData_0[105],
	&BOND_ASSET::mCFStaticData_0[106],
	&BOND_ASSET::mCFStaticData_0[107],
	&BOND_ASSET::mCFStaticData_0[108],
	&BOND_ASSET::mCFStaticData_0[109],
	&BOND_ASSET::mCFStaticData_0[110],
	&BOND_ASSET::mCFStaticData_0[111],
	&BOND_ASSET::mCFStaticData_0[112],
	&BOND_ASSET::mCFStaticData_0[113],
	&BOND_ASSET::mCFStaticData_0[114],
	&BOND_ASSET::mCFStaticData_0[115],
	&BOND_ASSET::mCFStaticData_0[116],
	&BOND_ASSET::mCFStaticData_0[117],
	&BOND_ASSET::mCFStaticData_0[118],
	&BOND_ASSET::mCFStaticData_0[119],
	&BOND_ASSET::mCFStaticData_0[120],
	&BOND_ASSET::mCFStaticData_0[121],
	&BOND_ASSET::mCFStaticData_0[122],
	&BOND_ASSET::mCFStaticData_0[123],
	&BOND_ASSET::mCFStaticData_0[124],
	&BOND_ASSET::mCFStaticData_0[125],
	&BOND_ASSET::mCFStaticData_0[126],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for amortzd_cost_period_defn                                                                                       
	const ChoicePair amortzd_cost_period_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TO_MATURITY, "To Maturity")
		,ChoicePair(StrEnum::TO_FIRST_CALL, "To First Call")
		,ChoicePair(StrEnum::TO_FIRST_PAR_CALL, "To First Par Call")
		,ChoicePair(StrEnum::TO_FIRST_PUT, "To First Put")
		,ChoicePair(StrEnum::TO_FIRST_PAR_PUT, "To First Par Put")
		,ChoicePair(StrEnum::TO_YIELD_TO_WORST, "To Yield to Worst")
	};
	const EnumList amortzd_cost_period_defnEnumList(6, amortzd_cost_period_defnChoicePairs);

	// EnumList for amortzd_cost_period_defn_save                                                                                       
	const ChoicePair amortzd_cost_period_defn_saveChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TO_MATURITY, "To Maturity")
		,ChoicePair(StrEnum::TO_FIRST_CALL, "To First Call")
		,ChoicePair(StrEnum::TO_FIRST_PAR_CALL, "To First Par Call")
		,ChoicePair(StrEnum::TO_FIRST_PUT, "To First Put")
		,ChoicePair(StrEnum::TO_FIRST_PAR_PUT, "To First Par Put")
		,ChoicePair(StrEnum::TO_YIELD_TO_WORST, "To Yield to Worst")
	};
	const EnumList amortzd_cost_period_defn_saveEnumList(6, amortzd_cost_period_defn_saveChoicePairs);

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

	// EnumList for bk_val_defn                                                                                       
	const ChoicePair bk_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::COST_BASIS, "Cost Basis")
	};
	const EnumList bk_val_defnEnumList(1, bk_val_defnChoicePairs);

	// EnumList for call_defn_mp                                                                                       
	const ChoicePair call_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::AMERICAN, "American")
		,ChoicePair(StrEnum::EUROPEAN, "European")
	};
	const EnumList call_defn_mpEnumList(3, call_defn_mpChoicePairs);

	// EnumList for call_price_defn_mp                                                                                       
	const ChoicePair call_price_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRICE_SCHEDULE, "Price Schedule")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::CASH_FLOW_MAINTENANCE, "Cash Flow Maintenance")
	};
	const EnumList call_price_defn_mpEnumList(3, call_price_defn_mpChoicePairs);

	// EnumList for cost_basis_defn                                                                                       
	const ChoicePair cost_basis_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AMORTIZED_COST, "Amortized Cost")
	};
	const EnumList cost_basis_defnEnumList(1, cost_basis_defnChoicePairs);

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for fast_stat_calc_aig                                                                                       
	const ChoicePair fast_stat_calc_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList fast_stat_calc_aigEnumList(2, fast_stat_calc_aigChoicePairs);

	// EnumList for gaap_acctng_defn                                                                                       
	const ChoicePair gaap_acctng_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::COST_BASIS, "Cost Basis")
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
	};
	const EnumList gaap_acctng_defnEnumList(2, gaap_acctng_defnChoicePairs);

	// EnumList for ia_prod_v3_rsd_2_aig                                                                                       
	const ChoicePair ia_prod_v3_rsd_2_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList ia_prod_v3_rsd_2_aigEnumList(2, ia_prod_v3_rsd_2_aigChoicePairs);

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

	// EnumList for opt_int_diff_defn                                                                                       
	const ChoicePair opt_int_diff_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::COUPON_RATE, "Coupon Rate")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
		,ChoicePair(StrEnum::NET_YIELD_AT_ISSUE, "Net Yield at Issue")
	};
	const EnumList opt_int_diff_defnEnumList(3, opt_int_diff_defnChoicePairs);

	// EnumList for pmt_mode_mp                                                                                       
	const ChoicePair pmt_mode_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
	};
	const EnumList pmt_mode_mpEnumList(5, pmt_mode_mpChoicePairs);

	// EnumList for port_defn_mp                                                                                       
	const ChoicePair port_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList port_defn_mpEnumList(2, port_defn_mpChoicePairs);

	// EnumList for put_defn_mp                                                                                       
	const ChoicePair put_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::AMERICAN, "American")
		,ChoicePair(StrEnum::EUROPEAN, "European")
	};
	const EnumList put_defn_mpEnumList(3, put_defn_mpChoicePairs);

	// EnumList for refinancing_rate_defn                                                                                       
	const ChoicePair refinancing_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::CATEGORY_YIELD_TO_WAL_OPTION_SPREAD, "Category Yield to WAL + Option Spread")
	};
	const EnumList refinancing_rate_defnEnumList(2, refinancing_rate_defnChoicePairs);

	// EnumList for sale_class_mp                                                                                       
	const ChoicePair sale_class_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList sale_class_mpEnumList(4, sale_class_mpChoicePairs);

	// EnumList for sinking_fund_defn_mp                                                                                       
	const ChoicePair sinking_fund_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList sinking_fund_defn_mpEnumList(2, sinking_fund_defn_mpChoicePairs);

	// EnumList for use_mp                                                                                       
	const ChoicePair use_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_mpEnumList(2, use_mpChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace BOND_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(BOND_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(BOND_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace BOND_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void BOND_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> BOND_ASSET::mgr_;

	Attribute::Descriptor BOND_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"adj_max_decr_per_reset_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_decr_per_reset_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::DOUBLE,	"adj_max_incr_per_reset_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_incr_per_reset_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"adj_max_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"adj_min_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_min_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STRING,	"adj_next_reset_date_mp", -1, (size_t)&modelOffset->adj_next_reset_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"adj_reset_category_id_mp", -1, (size_t)&modelOffset->adj_reset_category_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"adj_reset_mths_mp", -1, (size_t)&modelOffset->adj_reset_mths_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"adj_reset_renewal_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_renewal_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"adj_reset_scen_mult_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_scen_mult_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"adj_reset_scen_yr_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_scen_yr_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::STR_ENUM,	"amortzd_cost_period_defn", -1, (size_t)&modelOffset->amortzd_cost_period_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &amortzd_cost_period_defnEnumList, Feature(true)),
	Descriptor(11, Attribute::STR_ENUM,	"amortzd_cost_period_defn_save", -1, (size_t)&modelOffset->amortzd_cost_period_defn_save,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &amortzd_cost_period_defn_saveEnumList, Feature(true)),
	Descriptor(12, Attribute::STRING,	"asset_detail_rpt_cusip_id", -1, (size_t)&modelOffset->asset_detail_rpt_cusip_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STRING,	"asset_detail_rpt_id", -1, (size_t)&modelOffset->asset_detail_rpt_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"asset_detail_rpt_pv_defn", -1, (size_t)&modelOffset->asset_detail_rpt_pv_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_pv_defnEnumList, Feature(true)),
	Descriptor(16, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STRING,	"asset_id_mp", -1, (size_t)&modelOffset->asset_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::STR_ENUM,	"asset_mkt_sprd_use_defn", -1, (size_t)&modelOffset->asset_mkt_sprd_use_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_mkt_sprd_use_defnEnumList, Feature(true)),
	Descriptor(20, Attribute::DOUBLE,	"avr_contribn_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_contribn_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"avr_max_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_max_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"avr_obj_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_obj_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::STR_ENUM,	"bk_val_defn", -1, (size_t)&modelOffset->bk_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &bk_val_defnEnumList, Feature(true)),
	Descriptor(24, Attribute::STR_ENUM,	"call_defn_mp", -1, (size_t)&modelOffset->call_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &call_defn_mpEnumList, Feature(true)),
	Descriptor(25, Attribute::DOUBLE,	"call_opt_exercise_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->call_opt_exercise_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STRING,	"call_opt_first_date_mp", -1, (size_t)&modelOffset->call_opt_first_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STR_ENUM,	"call_price_defn_mp", -1, (size_t)&modelOffset->call_price_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &call_price_defn_mpEnumList, Feature(true)),
	Descriptor(28, Attribute::DOUBLE,	"call_price_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->call_price_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STRING,	"category_id_mp", -1, (size_t)&modelOffset->category_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STR_ENUM,	"cost_basis_defn", -1, (size_t)&modelOffset->cost_basis_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cost_basis_defnEnumList, Feature(true)),
	Descriptor(32, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(33, Attribute::DOUBLE,	"dur_wtd_sprd_adj_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_wtd_sprd_adj_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::DOUBLE,	"dur_wtd_sprd_adj_aig_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_wtd_sprd_adj_aig_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STR_ENUM,	"fast_stat_calc_aig", -1, (size_t)&modelOffset->fast_stat_calc_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fast_stat_calc_aigEnumList, Feature(true)),
	Descriptor(36, Attribute::STR_ENUM,	"gaap_acctng_defn", -1, (size_t)&modelOffset->gaap_acctng_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gaap_acctng_defnEnumList, Feature(true)),
	Descriptor(37, Attribute::STR_ENUM,	"ia_prod_v3_rsd_2_aig", -1, (size_t)&modelOffset->ia_prod_v3_rsd_2_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ia_prod_v3_rsd_2_aigEnumList, Feature(true)),
	Descriptor(38, Attribute::DOUBLE,	"init_bk_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_bk_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::DOUBLE,	"init_cost_basis_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cost_basis_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"init_mkt_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_mkt_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"init_par_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_par_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::DOUBLE,	"init_pmt_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_pmt_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::DOUBLE,	"int_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::STRING,	"issue_date_mp", -1, (size_t)&modelOffset->issue_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::STRING,	"maturity_date_mp", -1, (size_t)&modelOffset->maturity_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STR_ENUM,	"mkt_val_calc_freq", -1, (size_t)&modelOffset->mkt_val_calc_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freqEnumList, Feature(true)),
	Descriptor(47, Attribute::INT,	"mkt_val_calc_freq_yrs", -1, (size_t)&modelOffset->mkt_val_calc_freq_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::STR_ENUM,	"opt_int_diff_defn", -1, (size_t)&modelOffset->opt_int_diff_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &opt_int_diff_defnEnumList, Feature(true)),
	Descriptor(49, Attribute::DOUBLE,	"par_val_at_issue_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->par_val_at_issue_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::STRING,	"planned_sale_date_mp", -1, (size_t)&modelOffset->planned_sale_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::STR_ENUM,	"pmt_mode_mp", -1, (size_t)&modelOffset->pmt_mode_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pmt_mode_mpEnumList, Feature(true)),
	Descriptor(52, Attribute::STR_ENUM,	"port_defn_mp", -1, (size_t)&modelOffset->port_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &port_defn_mpEnumList, Feature(true)),
	Descriptor(53, Attribute::DOUBLE,	"portfolio_sprd_adj_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->portfolio_sprd_adj_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::DOUBLE,	"portfolio_sprd_adj_aig_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->portfolio_sprd_adj_aig_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::STRING,	"purch_asset_id", -1, (size_t)&modelOffset->purch_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::INT,	"purch_asset_sub_port", -1, (size_t)&modelOffset->purch_asset_sub_port,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STR_ENUM,	"put_defn_mp", -1, (size_t)&modelOffset->put_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &put_defn_mpEnumList, Feature(true)),
	Descriptor(59, Attribute::DOUBLE,	"put_opt_exercise_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->put_opt_exercise_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::STRING,	"put_opt_first_date_mp", -1, (size_t)&modelOffset->put_opt_first_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::DOUBLE,	"put_price_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->put_price_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::DOUBLE,	"rbc_c1_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::DOUBLE,	"refinancing_cost_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_cost_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(64, Attribute::STR_ENUM,	"refinancing_rate_defn", -1, (size_t)&modelOffset->refinancing_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &refinancing_rate_defnEnumList, Feature(true)),
	Descriptor(65, Attribute::DOUBLE,	"refinancing_rate_scen_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::DOUBLE,	"refinancing_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(67, Attribute::DOUBLE,	"refinancing_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(68, Attribute::STR_ENUM,	"sale_class_mp", -1, (size_t)&modelOffset->sale_class_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sale_class_mpEnumList, Feature(true)),
	Descriptor(69, Attribute::STRING,	"seg_id_mp", -1, (size_t)&modelOffset->seg_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(70, Attribute::STR_ENUM,	"sinking_fund_defn_mp", -1, (size_t)&modelOffset->sinking_fund_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sinking_fund_defn_mpEnumList, Feature(true)),
	Descriptor(71, Attribute::DOUBLE,	"sinking_fund_prin_pmt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->sinking_fund_prin_pmt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(72, Attribute::DOUBLE,	"taxable_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->taxable_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(74, Attribute::DOUBLE,	"yld_maint_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->yld_maint_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::SCALAR_DOUBLE,	"accr_int_per_par_unit", -1, (size_t)&modelOffset->accr_int_per_par_unit,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_accr_int_per_par_unit)),
	Descriptor(77, Attribute::SCALAR_INT,	"amortzn_cost_period", -1, (size_t)&modelOffset->amortzn_cost_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_amortzn_cost_period)),
	Descriptor(78, Attribute::SCALAR_INT,	"asset_detail_rpt_flag", -1, (size_t)&modelOffset->asset_detail_rpt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_asset_detail_rpt_flag)),
	Descriptor(79, Attribute::SCALAR_INT,	"asset_fund_index", -1, (size_t)&modelOffset->asset_fund_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_asset_fund_index)),
	Descriptor(80, Attribute::SCALAR_INT,	"call_first_period", -1, (size_t)&modelOffset->call_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_call_first_period)),
	Descriptor(81, Attribute::SCALAR_INT,	"call_par_first_period", -1, (size_t)&modelOffset->call_par_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_call_par_first_period)),
	Descriptor(82, Attribute::SCALAR_INT,	"call_prem_grading_mths", -1, (size_t)&modelOffset->call_prem_grading_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_call_prem_grading_mths)),
	Descriptor(83, Attribute::SCALAR_DOUBLE,	"call_prem_related_to_coupon_rate", -1, (size_t)&modelOffset->call_prem_related_to_coupon_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_call_prem_related_to_coupon_rate)),
	Descriptor(84, Attribute::SCALAR_INT,	"call_price_sch_flag", -1, (size_t)&modelOffset->call_price_sch_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_call_price_sch_flag)),
	Descriptor(85, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_commencement_period)),
	Descriptor(86, Attribute::SCALAR_DOUBLE,	"coupon_rate_at_issue", -1, (size_t)&modelOffset->coupon_rate_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_coupon_rate_at_issue)),
	Descriptor(87, Attribute::SCALAR_STRING,	"data_file_name", -1, (size_t)&modelOffset->data_file_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&BOND_ASSET_UDF::bond_asset_data_file_name)),
	Descriptor(88, Attribute::SCALAR_STRING,	"data_grp_id", -1, (size_t)&modelOffset->data_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&BOND_ASSET_UDF::bond_asset_data_grp_id)),
	Descriptor(89, Attribute::SCALAR_INT,	"existing_asset_indicator", -1, (size_t)&modelOffset->existing_asset_indicator,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_existing_asset_indicator)),
	Descriptor(90, Attribute::SCALAR_INT,	"gaap_inc_defn", -1, (size_t)&modelOffset->gaap_inc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_gaap_inc_defn)),
	Descriptor(91, Attribute::SCALAR_INT,	"gaap_val_defn", -1, (size_t)&modelOffset->gaap_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_gaap_val_defn)),
	Descriptor(92, Attribute::SCALAR_INT,	"maturity_mths_from_next_reset", -1, (size_t)&modelOffset->maturity_mths_from_next_reset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_maturity_mths_from_next_reset)),
	Descriptor(93, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_maturity_period)),
	Descriptor(94, Attribute::SCALAR_DOUBLE,	"mkt_val_per_unit_par", -1, (size_t)&modelOffset->mkt_val_per_unit_par,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_mkt_val_per_unit_par)),
	Descriptor(95, Attribute::SCALAR_INT,	"neg_asset_flag", -1, (size_t)&modelOffset->neg_asset_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_neg_asset_flag)),
	Descriptor(96, Attribute::SCALAR_DOUBLE,	"net_yld_at_issue", -1, (size_t)&modelOffset->net_yld_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_net_yld_at_issue)),
	Descriptor(97, Attribute::SCALAR_INT,	"net_yld_at_issue_flag", -1, (size_t)&modelOffset->net_yld_at_issue_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_net_yld_at_issue_flag)),
	Descriptor(98, Attribute::SCALAR_DOUBLE,	"pct_to_use", -1, (size_t)&modelOffset->pct_to_use,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_pct_to_use)),
	Descriptor(99, Attribute::SCALAR_INT,	"planned_sale_period", -1, (size_t)&modelOffset->planned_sale_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_planned_sale_period)),
	Descriptor(100, Attribute::SCALAR_INT,	"pmt_freq", -1, (size_t)&modelOffset->pmt_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_pmt_freq)),
	Descriptor(101, Attribute::SCALAR_INT,	"pmt_mths", -1, (size_t)&modelOffset->pmt_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_pmt_mths)),
	Descriptor(102, Attribute::SCALAR_INT,	"pmt_rate_defn", -1, (size_t)&modelOffset->pmt_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_pmt_rate_defn)),
	Descriptor(103, Attribute::SCALAR_STRING,	"pmt_rate_defn_string", -1, (size_t)&modelOffset->pmt_rate_defn_string,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&BOND_ASSET_UDF::bond_asset_pmt_rate_defn_string)),
	Descriptor(104, Attribute::SCALAR_INT,	"pmt_reset_first_period", -1, (size_t)&modelOffset->pmt_reset_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_pmt_reset_first_period)),
	Descriptor(105, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&BOND_ASSET_UDF::bond_asset_proj_date_adj)),
	Descriptor(106, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_proj_start_date)),
	Descriptor(107, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_proj_start_mth)),
	Descriptor(108, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_proj_start_yr)),
	Descriptor(109, Attribute::SCALAR_INT,	"put_first_period", -1, (size_t)&modelOffset->put_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_put_first_period)),
	Descriptor(110, Attribute::SCALAR_INT,	"put_par_first_period", -1, (size_t)&modelOffset->put_par_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_put_par_first_period)),
	Descriptor(111, Attribute::SCALAR_INT,	"put_prem_grading_mths", -1, (size_t)&modelOffset->put_prem_grading_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_put_prem_grading_mths)),
	Descriptor(112, Attribute::SCALAR_DOUBLE,	"put_prem_related_to_coupon_rate", -1, (size_t)&modelOffset->put_prem_related_to_coupon_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_put_prem_related_to_coupon_rate)),
	Descriptor(113, Attribute::SCALAR_INT,	"put_price_sch_flag", -1, (size_t)&modelOffset->put_price_sch_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_put_price_sch_flag)),
	Descriptor(114, Attribute::SCALAR_INT,	"refinancing_rate_defn_calc", -1, (size_t)&modelOffset->refinancing_rate_defn_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_refinancing_rate_defn_calc)),
	Descriptor(115, Attribute::SCALAR_DOUBLE,	"refinancing_rate_opt_sprd", -1, (size_t)&modelOffset->refinancing_rate_opt_sprd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_refinancing_rate_opt_sprd)),
	Descriptor(116, Attribute::SCALAR_INT,	"sale_class_id", -1, (size_t)&modelOffset->sale_class_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_sale_class_id)),
	Descriptor(117, Attribute::SCALAR_INT,	"sch_array_size", -1, (size_t)&modelOffset->sch_array_size,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_sch_array_size)),
	Descriptor(118, Attribute::SCALAR_INT,	"sch_start_period", -1, (size_t)&modelOffset->sch_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_sch_start_period)),
	Descriptor(119, Attribute::SCALAR_INT,	"seg_num", -1, (size_t)&modelOffset->seg_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_seg_num)),
	Descriptor(120, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_start_period)),
	Descriptor(121, Attribute::SCALAR_DOUBLE,	"tax_exempt_pct", -1, (size_t)&modelOffset->tax_exempt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_tax_exempt_pct)),
	Descriptor(122, Attribute::SCALAR_INT,	"use_eom_scen_rates", -1, (size_t)&modelOffset->use_eom_scen_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_use_eom_scen_rates)),
	Descriptor(123, Attribute::SCALAR_INT,	"write_sch_file_flag", -1, (size_t)&modelOffset->write_sch_file_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_ASSET_UDF::bond_asset_write_sch_file_flag)),
	Descriptor(124, Attribute::SCALAR_DOUBLE,	"yrs_since_last_pmt", -1, (size_t)&modelOffset->yrs_since_last_pmt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&BOND_ASSET_UDF::bond_asset_yrs_since_last_pmt)),
	};

	Attribute::Descriptor* BOND_ASSET::descriptorTable[] = {
	&BOND_ASSET::descriptor_0[0],
	&BOND_ASSET::descriptor_0[1],
	&BOND_ASSET::descriptor_0[2],
	&BOND_ASSET::descriptor_0[3],
	&BOND_ASSET::descriptor_0[4],
	&BOND_ASSET::descriptor_0[5],
	&BOND_ASSET::descriptor_0[6],
	&BOND_ASSET::descriptor_0[7],
	&BOND_ASSET::descriptor_0[8],
	&BOND_ASSET::descriptor_0[9],
	&BOND_ASSET::descriptor_0[10],
	&BOND_ASSET::descriptor_0[11],
	&BOND_ASSET::descriptor_0[12],
	&BOND_ASSET::descriptor_0[13],
	&BOND_ASSET::descriptor_0[14],
	&BOND_ASSET::descriptor_0[15],
	&BOND_ASSET::descriptor_0[16],
	&BOND_ASSET::descriptor_0[17],
	&BOND_ASSET::descriptor_0[18],
	&BOND_ASSET::descriptor_0[19],
	&BOND_ASSET::descriptor_0[20],
	&BOND_ASSET::descriptor_0[21],
	&BOND_ASSET::descriptor_0[22],
	&BOND_ASSET::descriptor_0[23],
	&BOND_ASSET::descriptor_0[24],
	&BOND_ASSET::descriptor_0[25],
	&BOND_ASSET::descriptor_0[26],
	&BOND_ASSET::descriptor_0[27],
	&BOND_ASSET::descriptor_0[28],
	&BOND_ASSET::descriptor_0[29],
	&BOND_ASSET::descriptor_0[30],
	&BOND_ASSET::descriptor_0[31],
	&BOND_ASSET::descriptor_0[32],
	&BOND_ASSET::descriptor_0[33],
	&BOND_ASSET::descriptor_0[34],
	&BOND_ASSET::descriptor_0[35],
	&BOND_ASSET::descriptor_0[36],
	&BOND_ASSET::descriptor_0[37],
	&BOND_ASSET::descriptor_0[38],
	&BOND_ASSET::descriptor_0[39],
	&BOND_ASSET::descriptor_0[40],
	&BOND_ASSET::descriptor_0[41],
	&BOND_ASSET::descriptor_0[42],
	&BOND_ASSET::descriptor_0[43],
	&BOND_ASSET::descriptor_0[44],
	&BOND_ASSET::descriptor_0[45],
	&BOND_ASSET::descriptor_0[46],
	&BOND_ASSET::descriptor_0[47],
	&BOND_ASSET::descriptor_0[48],
	&BOND_ASSET::descriptor_0[49],
	&BOND_ASSET::descriptor_0[50],
	&BOND_ASSET::descriptor_0[51],
	&BOND_ASSET::descriptor_0[52],
	&BOND_ASSET::descriptor_0[53],
	&BOND_ASSET::descriptor_0[54],
	&BOND_ASSET::descriptor_0[55],
	&BOND_ASSET::descriptor_0[56],
	&BOND_ASSET::descriptor_0[57],
	&BOND_ASSET::descriptor_0[58],
	&BOND_ASSET::descriptor_0[59],
	&BOND_ASSET::descriptor_0[60],
	&BOND_ASSET::descriptor_0[61],
	&BOND_ASSET::descriptor_0[62],
	&BOND_ASSET::descriptor_0[63],
	&BOND_ASSET::descriptor_0[64],
	&BOND_ASSET::descriptor_0[65],
	&BOND_ASSET::descriptor_0[66],
	&BOND_ASSET::descriptor_0[67],
	&BOND_ASSET::descriptor_0[68],
	&BOND_ASSET::descriptor_0[69],
	&BOND_ASSET::descriptor_0[70],
	&BOND_ASSET::descriptor_0[71],
	&BOND_ASSET::descriptor_0[72],
	&BOND_ASSET::descriptor_0[73],
	&BOND_ASSET::descriptor_0[74],
	&BOND_ASSET::descriptor_0[75],
	&BOND_ASSET::descriptor_0[76],
	&BOND_ASSET::descriptor_0[77],
	&BOND_ASSET::descriptor_0[78],
	&BOND_ASSET::descriptor_0[79],
	&BOND_ASSET::descriptor_0[80],
	&BOND_ASSET::descriptor_0[81],
	&BOND_ASSET::descriptor_0[82],
	&BOND_ASSET::descriptor_0[83],
	&BOND_ASSET::descriptor_0[84],
	&BOND_ASSET::descriptor_0[85],
	&BOND_ASSET::descriptor_0[86],
	&BOND_ASSET::descriptor_0[87],
	&BOND_ASSET::descriptor_0[88],
	&BOND_ASSET::descriptor_0[89],
	&BOND_ASSET::descriptor_0[90],
	&BOND_ASSET::descriptor_0[91],
	&BOND_ASSET::descriptor_0[92],
	&BOND_ASSET::descriptor_0[93],
	&BOND_ASSET::descriptor_0[94],
	&BOND_ASSET::descriptor_0[95],
	&BOND_ASSET::descriptor_0[96],
	&BOND_ASSET::descriptor_0[97],
	&BOND_ASSET::descriptor_0[98],
	&BOND_ASSET::descriptor_0[99],
	&BOND_ASSET::descriptor_0[100],
	&BOND_ASSET::descriptor_0[101],
	&BOND_ASSET::descriptor_0[102],
	&BOND_ASSET::descriptor_0[103],
	&BOND_ASSET::descriptor_0[104],
	&BOND_ASSET::descriptor_0[105],
	&BOND_ASSET::descriptor_0[106],
	&BOND_ASSET::descriptor_0[107],
	&BOND_ASSET::descriptor_0[108],
	&BOND_ASSET::descriptor_0[109],
	&BOND_ASSET::descriptor_0[110],
	&BOND_ASSET::descriptor_0[111],
	&BOND_ASSET::descriptor_0[112],
	&BOND_ASSET::descriptor_0[113],
	&BOND_ASSET::descriptor_0[114],
	&BOND_ASSET::descriptor_0[115],
	&BOND_ASSET::descriptor_0[116],
	&BOND_ASSET::descriptor_0[117],
	&BOND_ASSET::descriptor_0[118],
	&BOND_ASSET::descriptor_0[119],
	&BOND_ASSET::descriptor_0[120],
	&BOND_ASSET::descriptor_0[121],
	&BOND_ASSET::descriptor_0[122],
	&BOND_ASSET::descriptor_0[123],
	&BOND_ASSET::descriptor_0[124],
	nullptr};
	const size_t BOND_ASSET::sDescriptorCount = 125;

//factory
BOND_ASSET* BOND_ASSET::makeThis(int isSubmodel, ModelClass* owner, BOND_ASSET* peer, 
						int mainRebase, const xstring &name, BOND_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_ASSET");
#endif
	BOND_ASSET* newP = (BOND_ASSET*)new BOND_ASSET_UDF
   	  ("bond_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|bond_cf") == unusedModels.end()) {
	newP->sm_bond_cf = BOND_CF_ASSET::makeThis(1, newP, peer?peer->sm_bond_cf:0, mainRebase, name + "|bond_cf", (BOND_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_bond_cf:0));
	newP->adopt(newP->sm_bond_cf);
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
BOND_ASSET_persistent_object* BOND_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, BOND_ASSET* peer, 
							int mainRebase, const xstring &name, BOND_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_ASSET_persistent_object");
#endif
	BOND_ASSET_persistent_object* newP = (BOND_ASSET_persistent_object*)new BOND_ASSET_persistent_object
   	  ("bond_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			BOND_ASSET_persistent_object* pd = dynamic_cast<BOND_ASSET_persistent_object*>(product);
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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|bond_cf") == unusedModels.end()) {
	newP->sm_bond_cf = (BOND_CF_ASSET*)BOND_CF_ASSET_persistent_object::makeThis(1, newP, peer?peer->sm_bond_cf:0, mainRebase, name + "|bond_cf", (BOND_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_bond_cf:0), fixedArray);
	newP->adopt(newP->sm_bond_cf);
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (BOND_ASSET_UDF::*dPF) ();
typedef double (BOND_ASSET_UDF::*dPFd) (double);
typedef int (BOND_ASSET_UDF::*iPF) ();
typedef int (BOND_ASSET_UDF::*iPFi) (int);
typedef xstring (BOND_ASSET_UDF::*sPF) ();
typedef xstring (BOND_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
BOND_ASSET::BOND_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_bond_cf(0)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, epl(company_liab_epl)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, rates(company_rates)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
BOND_ASSET::BOND_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(126, BOND_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_bond_cf(0)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_is(company_asset_bond_bond_cf_bond_is)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, epl(company_liab_epl)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg_cf(company_asset_mtg_mtg_cf)
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
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf = 0;
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_seg_ann_pba = 0;
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

	for (int cf_no = 1; cf_no <= 126; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_ASSET_UDF::*dPXi2) (int, int);
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


 void BOND_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
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
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf"));
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_seg_ann_pba = (ANN_PBA_PBA*)(findUnique("company|seg|ann_pba"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
 }
//copy_names END@2


 void BOND_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int BOND_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& BOND_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double BOND_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int BOND_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double BOND_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double BOND_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void BOND_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_ASSET_persistent_object::write(long include_submodels) {
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

	void BOND_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	BOND_ASSET_persistent_object::~BOND_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool BOND_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void BOND_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void BOND_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void BOND_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* BOND_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* BOND_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* BOND_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char BOND_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void BOND_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
BOND_ASSET_persistent_object::BOND_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			BOND_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(BOND_ASSET::sm_bond_is)
	, sm_bond_pv(BOND_ASSET::sm_bond_pv)
	, sm_bond_ym(BOND_ASSET::sm_bond_ym)
	, sm_mtg_is(BOND_ASSET::sm_mtg_is)
	, sm_mtg_pv(BOND_ASSET::sm_mtg_pv)
	, sm_mtg_ym(BOND_ASSET::sm_mtg_ym)

	, sm_bond_cf(BOND_ASSET::sm_bond_cf)
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
BOND_ASSET::~BOND_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void BOND_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void BOND_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void BOND_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void BOND_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void BOND_ASSET::start_of_projection() {
}
//start_of_projection END@2

void BOND_ASSET::end_of_projection() {
}
//end_of_projection END@2

void BOND_ASSET::start_of_layer() {
}


void BOND_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void BOND_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void BOND_ASSET::after_startup(int decrement) {
// Call startup for submodels
  if(sm_bond_cf)
   sm_bond_cf->doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void BOND_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> BOND_ASSET::ddfVector;
BitArray BOND_ASSET::dataVariables(125);
bool BOND_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool BOND_ASSET::writeClassInfo = true;

void BOND_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, BOND_ASSET::descriptor_0>::dT = BOND_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, BOND_ASSET::descriptor_0>::dT = BOND_ASSET::descriptor_0;

