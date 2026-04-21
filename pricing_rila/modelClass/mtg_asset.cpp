
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
#include "ModelClass\mtg_asset_udf.h"
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
#include "ModelClass\fiaafund_liab.h"
#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fia_liab.h"
#include "ModelClass\hdg_grp_comp.h"
#include "ModelClass\intex_asset.h"
#include "ModelClass\invstrat_asset.h"
#include "ModelClass\liab_liab.h"
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

int num_mtgs_to_run;
int num_mtg = 0;
sowfinput mtg_mp_input;
sowfcols mtg_mp_input_cols;
sowfinput mtg_sch_input;
sowfcols mtg_sch_input_cols;
sowfoutput mtg_sch_output;
sowfmap mtg_sch_input_pos;
sowfmapiter mtg_sch_input_pos_iter;
sowfmap mtg_sch_input_size;
sowfmapiter mtg_sch_input_size_iter;

extern sowmpoutput mtg_state_of_world_mp_output;
static mtgivmap mtg_initial_values_map;
static mtgivmap::iterator mtg_initial_values_map_iter;
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern bool is_asset_initialize;

// present value calculation variables
#define YM_UPDATE 0
extern int pv_months;
extern int pv_last_cash_flow_month;
extern int pv_asset_defn;
extern int pv_model_point;
extern double pv_initial_years_to_payment;
extern double pv_initial_accrued_interest;
extern double pv_initial_par_value;
extern double pv_interest_savings_monthly_refinancing_rate;
extern bool pv_par_val_per_unit_of_par_calculation;
extern bool pv_initialize_interest_savings_table;
extern bool pv_initialize_yield_maintenance_table;
extern SmartArray <double>& pv_cash_flows;
extern SmartArray <double>& pv_interest_savings_after_prepayments;
extern SmartArray <double>& pv_yield_maintenance_cash_flows;
extern SmartArray <double>& pv_yield_maintenance_par_plus_accrued;

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

extern bool intex_fatal_error;
extern bool intex_detail_wanted;
extern bool adco_fatal_error;

extern int model_t_low;
extern int model_t_high;
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
#ifndef mtg_asset_TableDefs
#define mtg_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection MTG_ASSET::TTHC;
void MTG_ASSET::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_mtg_cf)
		sm_mtg_cf = 0;

}		

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return cost_basis_bef_sale(t) + accr_int_bef_sale(t)
		   - (cost_basis(t - 1) + accr_int(t - 1))
		   + int_pmt(t)
		   + opt_pmt(t)
		   + realzd_cap_loss_dflt(t)
		   + cost_basis_sched_prin_pmt(t)
		   - realzd_cap_gain_opt_pmt(t);

double accr_inc_bef_sched_pmt
= cost_basis_bef_prepmt(t)
  + accr_int_bef_prepmt(t)
  - cost_basis_aft_dflt(t)
  - accr_int_aft_dflt(t)
  + int_pmt(t)
  + cost_basis_sched_prin_pmt(t)
  - cap_gain_adj_foreclosure_prin_pmt(t)
  - cap_gain_adj_restructure_prin_pmt(t);

if (fabs(cost_basis_bef_sale(t)) < model_point_amount_threshold)
	return accr_inc_bef_sched_pmt
    	   - cost_basis_aft_prepmt(t)
		   - accr_int_aft_prepmt(t)
	       + accr_int_bef_sale(t)
	       + intex_accr_int_adj(t)
	       + cost_basis_bef_sale(t);

double accr_inc_aft_prepmt
= cost_basis_bef_sale(t)
  + accr_int_bef_sale(t)
  + intex_accr_int_adj(t)
  - cost_basis_aft_prepmt(t)
  - accr_int_aft_prepmt(t);

return accr_inc_bef_sched_pmt
       + accr_inc_aft_prepmt;

}


//@@ END

//@@ START - accr_int
// Accrued Interest                                                                                             
// Column:ACCR_INT
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_int",t);
}



//^^^

#line 1 "accr_int.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return 0.0;

if (intex_asset)
	return accr_int_bef_sale(t)
		   * (1.0 - sold_pct(t));

return mtg_cf->accr_int(t);

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Defaults                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"accr_int_aft_dflt",t);
}



//^^^

#line 1 "accr_int_aft_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

//force call
accr_int_dflt(t);

return mtg_cf->accr_int_aft_dflt(t);

}


//@@ END

//@@ START - accr_int_aft_prepmt
// Accrued Interest After Prepayments                                                                                             
// Column:ACCR_INT_AFT_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_aft_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"accr_int_aft_prepmt",t);
}



//^^^

#line 1 "accr_int_aft_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return mtg_cf->accr_int_aft_prepmt(t);

}


//@@ END

//@@ START - accr_int_bef_fund_match_sale
// Accrued Interest Before Fund Value Matching Asset Sales                                                                                             
// Column:ACCR_INT_BEF_FUND_MATCH_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"accr_int_bef_fund_match_sale",t);
}



//^^^

#line 1 "accr_int_bef_fund_match_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_accr_int_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"accr_int_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "accr_int_bef_neg_cash_flow_sale.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - accr_int_bef_prepmt
// Accrued Interest Before Prepayments                                                                                             
// Column:ACCR_INT_BEF_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"accr_int_bef_prepmt",t);
}



//^^^

#line 1 "accr_int_bef_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return mtg_cf->accr_int_bef_prepmt(t);

}


//@@ END

//@@ START - accr_int_bef_rebal_sale
// Accrued Interest Before Rebalancing Sales                                                                                             
// Column:ACCR_INT_BEF_REBAL_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"accr_int_bef_rebal_sale",t);
}



//^^^

#line 1 "accr_int_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_accr_int_bef_sale(int t) {
//^^^



//^^^

#line 1 "accr_int_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_accr_int[t]
	       * intex_pct_remaining(t - 1);

return mtg_cf->accr_int_bef_sale(t);

}


//@@ END

//@@ START - accr_int_dflt
// Accrued Interest Defaults                                                                                             
// Column:ACCR_INT_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"accr_int_dflt",t);
}



//^^^

#line 1 "accr_int_dflt.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_accr_int_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"accr_int_purch",t);
}



//^^^

#line 1 "accr_int_purch.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_accr_int_rent(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"accr_int_rent",t);
}



//^^^

#line 1 "accr_int_rent.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return accr_int(t);

}


//@@ END

//@@ START - accr_int_sold
// Accrued Interest Sold                                                                                             
// Column:ACCR_INT_SOLD
//========================================================
double MTG_ASSET_UDF::mtg_asset_accr_int_sold(int t) {
//^^^



//^^^

#line 1 "accr_int_sold.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return accr_int_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - asset_detail_pv_flag
// Detail Present Value Flag                                                                                             
// Column:ASSET_DETAIL_PV_FLAG
//========================================================
double MTG_ASSET_UDF::mtg_asset_asset_detail_pv_flag(int t) {
//^^^



//^^^

#line 1 "asset_detail_pv_flag.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_asset_min_size_sale_flag(int t) {
//^^^



//^^^

#line 1 "asset_min_size_sale_flag.MTG_ASSET.for"
// Refinance, Foreclosure and Restructure assets can be sold 
// in the period they are purchased
if ((t <= commencement_period && (purch_defn == INVESTMENT))
	|| t >= maturity_period || isMainModel)
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
double MTG_ASSET_UDF::mtg_asset_avr_basic_contribn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"avr_basic_contribn",t);
}



//^^^

#line 1 "avr_basic_contribn.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return avr_basic_contribn_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_basic_contribn_bef_sale
// AVR Basic Contribution Before Sales                                                                                             
// Column:AVR_BASIC_CONTRIBN_BEF_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_avr_basic_contribn_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"avr_basic_contribn_bef_sale",t);
}



//^^^

#line 1 "avr_basic_contribn_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_contribn_pct;

}


//@@ END

//@@ START - avr_max
// AVR Maximum                                                                                             
// Column:AVR_MAX
//========================================================
double MTG_ASSET_UDF::mtg_asset_avr_max(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"avr_max",t);
}



//^^^

#line 1 "avr_max.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_avr_max_bef_sale(int t) {
//^^^



//^^^

#line 1 "avr_max_bef_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_avr_obj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"avr_obj",t);
}



//^^^

#line 1 "avr_obj.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_avr_obj_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"avr_obj_bef_sale",t);
}



//^^^

#line 1 "avr_obj_bef_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_avr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"avr_realzd_cap_gain",t);
}



//^^^

#line 1 "avr_realzd_cap_gain.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return - dflt_amt(t)
	   - write_down(t);

}


//@@ END

//@@ START - balloon_sch_base
// Balloon Schedule Base                                                                                             
// Column:BALLOON_SCH_BASE
//========================================================
double MTG_ASSET_UDF::mtg_asset_balloon_sch_base(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"balloon_sch_base",t);
}



//^^^

#line 1 "balloon_sch_base.MTG_ASSET.for"
if (balloon_defn == NO || balloon_defn == YES_ON_SINGLE_PERIOD
	|| t < start_period || t >= maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	{
	double cumul_future_pct = 0.0;
		
	for (int month = 1; month <= maturity_period; month++)
		cumul_future_pct += balloon_sch[month];
	
	return cumul_future_pct;
	}

if (!existing_asset_indicator && t == commencement_period)
	return 1.0;

return max(0.0,
           balloon_sch_base(t - 1)
           - balloon_sch[t - start_period]);

}


//@@ END

//@@ START - base_inc_bef_prepmt
// Base Income Before Prepayments                                                                                             
// Column:BASE_INC_BEF_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_base_inc_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"base_inc_bef_prepmt",t);
}



//^^^

#line 1 "base_inc_bef_prepmt.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"bk_val",t);
}



//^^^

#line 1 "bk_val.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - bk_val_aft_dflt
// Book Value After Defaults                                                                                             
// Column:BK_VAL_AFT_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"bk_val_aft_dflt",t);
}



//^^^

#line 1 "bk_val_aft_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val(t - 1)
       * sm_mtg_cf->remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - bk_val_aft_prepmt
// Book Value After Prepayment                                                                                             
// Column:BK_VAL_AFT_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_aft_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"bk_val_aft_prepmt",t);
}



//^^^

#line 1 "bk_val_aft_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_prepmt(t)) < model_point_amount_threshold)
	return NO_AVG;

return bk_val_bef_prepmt(t)
	   * (1.0 - mtg_cf->prepmt_pct_mthly(t));

}


//@@ END

//@@ START - bk_val_bef_fund_match_sale
// Book Value Before Fund Value Matching Asset Sales                                                                                             
// Column:BK_VAL_BEF_FUND_MATCH_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"bk_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "bk_val_bef_fund_match_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_bk_val_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"bk_val_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "bk_val_bef_neg_cash_flow_sale.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale(t)
       * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - bk_val_bef_prepmt
// Book Value Before Prepayments                                                                                             
// Column:BK_VAL_BEF_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"bk_val_bef_prepmt",t);
}



//^^^

#line 1 "bk_val_bef_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_prepmt(t);

return NO_AVG;

}


//@@ END

//@@ START - bk_val_bef_rebal_sale
// Book Value Before Rebalancing Sales                                                                                             
// Column:BK_VAL_BEF_REBAL_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"bk_val_bef_rebal_sale",t);
}



//^^^

#line 1 "bk_val_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_bk_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
  return NO_AVG;

if (intex_asset)
	return intex_bk_val[t]
	       * intex_pct_remaining(t - 1);

if (t == 0 && existing_asset_indicator)
	{
	double local_book_value = init_bk_val * neg_asset_flag;

	//Perform accounting data consistency checks for book value
	if (bk_val_defn == COST_BASIS
		&& fabs(local_book_value - cost_basis_bef_sale(t)) > 0.5)
		{
		return cost_basis_bef_sale(t);
		}

	return local_book_value;
	}

if (!existing_asset_indicator && t == commencement_period)
	{
	if (purch_defn == INVESTMENT)
		return mkt_val_bef_sale(t);

	if (purch_defn == FORECLOSURE
		|| purch_defn == RESTRUCTURE
		|| purch_defn == REFINANCE)
		return company->sm_inv_strategy[seg_num]->refinance_foreclosure_restructure_bk_val
			   * neg_asset_flag;
	}

if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_sale(t);

return NO_AVG;

}


//@@ END

//@@ START - bk_val_plus_accr_int_bef_rebal_sale
// Book Value Plus Accrued Interest Before Rebalancing Sales                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT_BEF_REBAL_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_bk_val_plus_accr_int_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_bk_val_purch(int t) {
//^^^



//^^^

#line 1 "bk_val_purch.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.MTG_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double MTG_ASSET_UDF::mtg_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.MTG_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain_adj_foreclosure_prin_pmt
// Capital Gain Adjustment Foreclosure Principal Payment                                                                                             
// Column:CAP_GAIN_ADJ_FORECLOSURE_PRIN_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cap_gain_adj_foreclosure_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"cap_gain_adj_foreclosure_prin_pmt",t);
}



//^^^

#line 1 "cap_gain_adj_foreclosure_prin_pmt.MTG_ASSET.for"
if (purch_defn != FORECLOSURE)
	return NO_AVG;

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return mtg_cf->sched_prin_pmt(t) 
   	   * (mtg_cf->since_foreclosure_prin_pmt_mult(t) - 1.0);

}


//@@ END

//@@ START - cap_gain_adj_restructure_prin_pmt
// Capital Gain Adjustment Restructure Principal Payment                                                                                             
// Column:CAP_GAIN_ADJ_RESTRUCTURE_PRIN_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cap_gain_adj_restructure_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"cap_gain_adj_restructure_prin_pmt",t);
}



//^^^

#line 1 "cap_gain_adj_restructure_prin_pmt.MTG_ASSET.for"
if (mtg->purch_defn != RESTRUCTURE)
	return NO_AVG;

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return mtg_cf->sched_prin_pmt(t) 
	   * (mtg_cf->since_restructure_prin_pmt_mult(t) - 1.0);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"cap_gain_bef_sale",t);
}



//^^^

#line 1 "cap_gain_bef_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_cap_gain_from_sale(int t) {
//^^^



//^^^

#line 1 "cap_gain_from_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double MTG_ASSET_UDF::mtg_asset_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"cash_flow",t);
}



//^^^

#line 1 "cash_flow.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return sched_prin_pmt(t)
		   + int_pmt(t)
		   + opt_pmt(t);

if (balloon_pmt_period > t)
	return mtg_cf->sched_prin_pmt(t)
		   + mtg_cf->int_pmt(t)
		   + mtg_cf->prepmt_inc(t)
		   + mtg_cf->prepmt_amt(t);

return mtg_cf->sched_prin_pmt(t)
	   + mtg_cf->int_pmt(t)
	   + mtg_cf->balloon_pmt_inc(t)
	   + mtg_cf->prepmt_inc(t)
	   + mtg_cf->prepmt_amt(t);

}


//@@ END

//@@ START - cost_basis
// Cost Basis                                                                                             
// Column:COST_BASIS
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"cost_basis",t);
}



//^^^

#line 1 "cost_basis.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_cost_basis_accrual(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"cost_basis_accrual",t);
}



//^^^

#line 1 "cost_basis_accrual.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	{
	if (t > 0)
		return intex_amortzn_of_disc[t]
		       * intex_pct_remaining(t - 1);

	return NO_AVG;
	}

return cost_basis_bef_prepmt(t)
	   - cost_basis_aft_dflt(t)
	   + cost_basis_sched_prin_pmt(t)
	   + cost_basis_bef_sale(t)
	   - cost_basis_aft_prepmt(t)
	   - cap_gain_adj_foreclosure_prin_pmt(t)
	   - cap_gain_adj_restructure_prin_pmt(t);

}


//@@ END

//@@ START - cost_basis_aft_dflt
// Cost Basis After Defaults                                                                                             
// Column:COST_BASIS_AFT_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(45,"cost_basis_aft_dflt",t);
}



//^^^

#line 1 "cost_basis_aft_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis(t - 1)
       * mtg_cf->remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - cost_basis_aft_prepmt
// Cost Basis After Prepayments                                                                                             
// Column:COST_BASIS_AFT_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_aft_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"cost_basis_aft_prepmt",t);
}



//^^^

#line 1 "cost_basis_aft_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_prepmt(t)
	   * (1.0 - mtg_cf->prepmt_pct_mthly(t));

}


//@@ END

//@@ START - cost_basis_bef_prepmt
// Cost Basis Before Prepayments                                                                                             
// Column:COST_BASIS_BEF_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"cost_basis_bef_prepmt",t);
}



//^^^

#line 1 "cost_basis_bef_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn == AMORTIZED_COST)
	{
	if (t == maturity_period
		|| mtg_cf->par_val_aft_sched_pmt(t) < ASSET_ACTIVE_THRESHOLD)
		{
		// Cost never exactly amortizes to par. Cost must be set to zero
		// at maturity to keep the balance sheet in balance unless it is
		// really out of balance.
		double local_cost_basis
		= cost_basis_aft_dflt(t)
		  + accr_int_aft_dflt(t)
		  - accr_int_bef_prepmt(t)
		  + base_inc_bef_prepmt(t)
		  - int_pmt(t)
		  - sched_prin_pmt(t)
		  + cap_gain_adj_foreclosure_prin_pmt(t)
		  + cap_gain_adj_restructure_prin_pmt(t);

		if (fabs(local_cost_basis
				- mtg_cf->par_val_aft_sched_pmt(t))
		 	< (SOLVE_FOR_SPREAD_TOLERANCE * 2.0))
			return NO_AVG;
		else
			{
			makeRunLogYellow();
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << setprecision(6);
			log_screen << "Warning: Problem with mortgage amortization to "
					<< amortzd_cost_period_defn << " "
					<< "for "<< asset_id
					<< " at t=" << t
					<< MSG_ERROR;
			log_screen << " ... At maturity, cost basis " << local_cost_basis << " has not amortized "
					<< "to zero in iteration " << proj_task_loop_num << " "
					<< "for scenario set " << replaceWildcards(rates->scen_id) << " " 
					<< "Please contact client services." << MSG_ERROR;
			log_screen << setprecision(6);
			log_screen.unsetf(ios::fixed);

			return NO_AVG;
			}
		}

	return cost_basis_aft_dflt(t)
		   + accr_int_aft_dflt(t)
		   - accr_int_bef_prepmt(t)
		   + base_inc_bef_prepmt(t)
		   - int_pmt(t)
		   - sched_prin_pmt(t)
		   + cap_gain_adj_foreclosure_prin_pmt(t)
		   + cap_gain_adj_restructure_prin_pmt(t);
	}

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_bef_sale
// Cost Basis Before Sales                                                                                             
// Column:COST_BASIS_BEF_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_bef_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_cost_basis[t]
	       * intex_pct_remaining(t - 1);

if (existing_asset_indicator && t == 0)
	return init_cost_basis * neg_asset_flag;

if (!existing_asset_indicator && t == commencement_period)
	{
	if (purch_defn == INVESTMENT)
		return mtg_cf->par_val_bef_sale(t) * mkt_val_per_unit_par;

	else if (purch_defn == FORECLOSURE
			 || purch_defn == RESTRUCTURE
			 || purch_defn == REFINANCE)
		return company->sm_inv_strategy[seg_num]->refinance_foreclosure_restructure_cost_basis
			   * neg_asset_flag;
	}

if (cost_basis_defn == AMORTIZED_COST)
	return max(cost_basis_aft_prepmt(t)
		       + accr_int_aft_prepmt(t)
		       - accr_int_bef_sale(t)
		       - intex_accr_int_adj(t), 0.0);

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_dflt
// Cost Basis Default                                                                                             
// Column:COST_BASIS_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"cost_basis_dflt",t);
}



//^^^

#line 1 "cost_basis_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	{
	if (t > 0)
		return intex_cost_basis_dflt[t]
		       * intex_pct_remaining(t - 1);

	return NO_AVG;
	}

return cost_basis(t - 1)
   	   * dflt_pct(t);

}


//@@ END

//@@ START - cost_basis_incr_appreciation
// Cost Basis Increase from Appreciation                                                                                             
// Column:COST_BASIS_INCR_APPRECIATION
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_incr_appreciation(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"cost_basis_incr_appreciation",t);
}



//^^^

#line 1 "cost_basis_incr_appreciation.MTG_ASSET.for"
return NO_AVG;

}


//@@ END

//@@ START - cost_basis_purch
// Cost Basis Purchase                                                                                             
// Column:COST_BASIS_PURCH
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_purch(int t) {
//^^^



//^^^

#line 1 "cost_basis_purch.MTG_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
  return NO_AVG;

if (purch_defn == RESTRUCTURE
	|| purch_defn == REFINANCE
	|| purch_defn == FORECLOSURE)
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
double MTG_ASSET_UDF::mtg_asset_cost_basis_sched_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(52,"cost_basis_sched_prin_pmt",t);
}



//^^^

#line 1 "cost_basis_sched_prin_pmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn == AMORTIZED_COST)
	return sched_prin_pmt(t);

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_sold
// Cost Basis Sold                                                                                             
// Column:COST_BASIS_SOLD
//========================================================
double MTG_ASSET_UDF::mtg_asset_cost_basis_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(53,"cost_basis_sold",t);
}



//^^^

#line 1 "cost_basis_sold.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double MTG_ASSET_UDF::mtg_asset_date(int t) {
//^^^



//^^^

#line 1 "date.MTG_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - decr_pct
// Decrease Percent                                                                                             
// Column:DECR_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_decr_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"decr_pct",t);
}



//^^^

#line 1 "decr_pct.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decr_rate(t) == 0)
	return NO_AVG;

if (decr_rate(t) < 1.0 - rate_ratio_threshold)
	return 1.0 - pow(1.0 - decr_rate(t), (1.0 / 12.0));

return 1.0;

}


//@@ END

//@@ START - decr_rate
// Decrease Rate                                                                                             
// Column:DECR_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_decr_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"decr_rate",t);
}



//^^^

#line 1 "decr_rate.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

double decr_rate = dflt_rate(t);

// During asset initialize, no need to split decrements into pieces
if (!is_asset_initialize)
	{
	if (foreclosure_asset_id >= 0)
		decr_rate += foreclosure_rate(t);

	if (restructure_asset_id >= 0)
		decr_rate += restructure_rate(t);

	if (refinance_asset_id >= 0)
		decr_rate += refinance_rate(t);
	}

return decr_rate;

}


//@@ END

//@@ START - dflt_amt
// Default Amount                                                                                             
// Column:DFLT_AMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_dflt_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"dflt_amt",t);
}



//^^^

#line 1 "dflt_amt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->dflt_amt;

if (intex_asset)
	{
	if (t == 0)
		return intex_dflt_amt[t + 1];

	return intex_dflt_amt[t]
	       * intex_pct_remaining(t - 1);
	}

if (t > 0
	&& fabs(bk_val(t - 1) + accr_int(t - 1)) < model_point_amount_threshold)
	return NO_AVG;

if (t == 0 && !intex_proj_flag)
	return dflt_amt(t + 1);

return (cost_basis(t - 1) + accr_int(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - dflt_pct
// Default Percent                                                                                             
// Column:DFLT_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_dflt_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"dflt_pct",t);
}



//^^^

#line 1 "dflt_pct.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decr_rate(t) == 0)
	return NO_AVG;

return decr_pct(t)
	   * dflt_rate(t)
	   / decr_rate(t);

}


//@@ END

//@@ START - dflt_rate
// Default Rate                                                                                             
// Column:DFLT_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_dflt_rate(int t) {
//^^^



//^^^

#line 1 "dflt_rate.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

double annual_default_percentage = 0;

double annual_default_percentage_preliminary
	= rates->get_dflt_rate(t,
	                category_id,
					EFFECTIVE_ANNUAL)
	   * dflt_rate_scen_mult;

	annual_default_percentage
	= (max(min(round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
						annual_default_percentage_preliminary,
						DECIMALS_TO_ROUND), 1.0), 0.0));

	if (annual_default_percentage < rate_ratio_threshold)
		annual_default_percentage = 0;
	
// During asset initialize, no need to split decrements into pieces
if (is_asset_initialize)
	{
	annual_default_percentage
	+= foreclosure_rate(t)
	   + restructure_rate(t)
	   + refinance_rate(t);	
	}
else
	{
	if (foreclosure_asset_id < 0)
		annual_default_percentage
		+= foreclosure_rate(t);	

	if (restructure_asset_id < 0)
		annual_default_percentage
		+= restructure_rate(t);

	if (refinance_asset_id < 0)
		annual_default_percentage
		+= refinance_rate(t);
	}	

return annual_default_percentage;

}


//@@ END

//@@ START - dur_val
// Duration Value                                                                                             
// Column:DUR_VAL
//========================================================
double MTG_ASSET_UDF::mtg_asset_dur_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"dur_val",t);
}



//^^^

#line 1 "dur_val.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return eff_dur(t);

}


//@@ END

//@@ START - eff_dur
// Effective Duration                                                                                             
// Column:EFF_DUR
//========================================================
double MTG_ASSET_UDF::mtg_asset_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"eff_dur",t);
}



//^^^

#line 1 "eff_dur.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->eff_dur;

if (intex_asset)
	return intex_eff_dur[t];

double calculated_effective_duration = 0.0;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		// we will use the modified duration in order to reduce calculation time
		return intex->get_tranche_modified_dur(t, notional_amt_bef_sale(t) / sm_mtg_cf->tranche_portion_bef_sale(t), 
						mkt_val_bef_sale(t) / sm_mtg_cf->tranche_portion_bef_sale(t));
	}
#endif	

if (asset_detail_pv_flag(t))
  	{
	PVCounter++;
   	PVCText << PVCounter
   			<< "-->Begin Effective Duration Calculation"
   			<< " for " << asset_id
   			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
   			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	}

if (fabs((mkt_val_bef_sale(t) + accr_int_bef_sale(t))
		 * SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION)
	 > model_point_amount_threshold)
	calculated_effective_duration
	= (mkt_val_bef_sale(t) - mkt_val_shifted(t))
	  / ((mkt_val_bef_sale(t) + accr_int_bef_sale(t))
		 * SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION);

if (asset_detail_pv_flag(t))
  	{
    PVCText << PVCounter
    		<< "<--End Effective Duration Calculation ("
			<< write_string(calculated_effective_duration,PVCLen,PVCSigDig)
    		<< ") for " << asset_id
   			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t))
   			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	PVCounter--;
  	}	

return calculated_effective_duration;

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double MTG_ASSET_UDF::mtg_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.MTG_ASSET.for"
// 20240202 Temp fix for issue: Asset model points that mature on the same date as a future valuation 
//period are not correctly removed from the asset mapping
if (time_step_flag && !valn_flag && t < maturity_period
	&& fabs(notional_amt(t)) >= ASSET_ACTIVE_THRESHOLD //20240924 WTW bug fix
	&& proj_set_sub_loop_num < valn_periods.size())
	write_state_of_world_mp();

if (isMainModel && num_mtg == num_mtgs_to_run)
	{
	#if defined(__ADCO_ASSET_H_)
	if (adco)
		adco->finalize(t);
	#endif

	if (PVCFile != NULL)
		PVCFile.close();
	}	

return 1.0;

}


//@@ END

//@@ START - foreclosure_accr_int_net_write_down
// Foreclosure Accrued Interest Net Write Down                                                                                             
// Column:FORECLOSURE_ACCR_INT_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_accr_int_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(63,"foreclosure_accr_int_net_write_down",t);
}



//^^^

#line 1 "foreclosure_accr_int_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (accr_int(t - 1)
		* foreclosure_pct(t))
	   * (1.0 - foreclosure_write_down_pct_calc);

}


//@@ END

//@@ START - foreclosure_bk_val_net_write_down
// Foreclosure Book Value Net Write Down                                                                                             
// Column:FORECLOSURE_BK_VAL_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_bk_val_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(64,"foreclosure_bk_val_net_write_down",t);
}



//^^^

#line 1 "foreclosure_bk_val_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (bk_val(t - 1)
		* foreclosure_pct(t))
	   * (1.0 - foreclosure_write_down_pct_calc);

}


//@@ END

//@@ START - foreclosure_cost_basis_net_write_down
// Foreclosure Cost Basis Net Write Down                                                                                             
// Column:FORECLOSURE_COST_BASIS_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_cost_basis_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(65,"foreclosure_cost_basis_net_write_down",t);
}



//^^^

#line 1 "foreclosure_cost_basis_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (cost_basis(t - 1)
		* foreclosure_pct(t))
	   * (1.0 - foreclosure_write_down_pct_calc);

}


//@@ END

//@@ START - foreclosure_pct
// Foreclosure Percent                                                                                             
// Column:FORECLOSURE_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(66,"foreclosure_pct",t);
}



//^^^

#line 1 "foreclosure_pct.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (foreclosure_asset_id < 0
	|| decr_rate(t) == 0)
	return NO_AVG;

return decr_pct(t)
	   * foreclosure_rate(t)
	   / decr_rate(t);

}


//@@ END

//@@ START - foreclosure_prin_net_write_down
// Foreclosure Principal Net Write Down                                                                                             
// Column:FORECLOSURE_PRIN_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_prin_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(67,"foreclosure_prin_net_write_down",t);
}



//^^^

#line 1 "foreclosure_prin_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (mtg_cf->par_val(t - 1)
		* foreclosure_pct(t))
	   * (1.0 - foreclosure_write_down_pct_calc);

}


//@@ END

//@@ START - foreclosure_rate
// Foreclosure Rate                                                                                             
// Column:FORECLOSURE_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"foreclosure_rate",t);
}



//^^^

#line 1 "foreclosure_rate.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

double foreclosure_rate_prelim
= (rates->get_dflt_rate(t,
                        category_id,
                        EFFECTIVE_ANNUAL)
   * foreclosure_rate_scen_mult
   + foreclosure_rate_pct)
  * foreclosure_rate_mult_since_issue // Lookup key is mths_since_issue(t)
  * foreclosure_rate_mult_bef_maturity; // Lookup key is mths_bef_maturity(t)

double foreclosure_rate
= (max(min(round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
						foreclosure_rate_prelim,
						DECIMALS_TO_ROUND), 1.0), 0.0));

if (foreclosure_rate < rate_ratio_threshold)
	return NO_AVG;

return foreclosure_rate;

}


//@@ END

//@@ START - gaap_inc_bk_val
// GAAP Income Book Value                                                                                             
// Column:GAAP_INC_BK_VAL
//========================================================
double MTG_ASSET_UDF::mtg_asset_gaap_inc_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"gaap_inc_bk_val",t);
}



//^^^

#line 1 "gaap_inc_bk_val.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_inc_defn == COST_BASIS)
	return cost_basis(t);

//if (gaap_inc_defn == MARKET_VALUE)
return mkt_val(t);

}


//@@ END

//@@ START - gaap_inc_unrealzd_cap_gain
// GAAP Income Unrealized Capital Gain                                                                                             
// Column:GAAP_INC_UNREALZD_CAP_GAIN
//========================================================
double MTG_ASSET_UDF::mtg_asset_gaap_inc_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(70,"gaap_inc_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_inc_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - gaap_surp_bk_val
// GAAP Surplus Book Value                                                                                             
// Column:GAAP_SURP_BK_VAL
//========================================================
double MTG_ASSET_UDF::mtg_asset_gaap_surp_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(71,"gaap_surp_bk_val",t);
}



//^^^

#line 1 "gaap_surp_bk_val.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_val_defn == COST_BASIS)
	return cost_basis(t);

//if (gaap_val_defn == MARKET_VALUE)
return mkt_val(t);

}


//@@ END

//@@ START - gaap_unrealzd_cap_gain_incr
// GAAP Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_UNREALZD_CAP_GAIN_INCR
//========================================================
double MTG_ASSET_UDF::mtg_asset_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(72,"gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_unrealzd_cap_gain_incr.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_inc_unrealzd_cap_gain(t) 
		- gaap_inc_unrealzd_cap_gain(t - 1);

}


//@@ END

//@@ START - imr_realzd_cap_gain
// Interest Maintenance Reserve Realized Capital Gain                                                                                             
// Column:IMR_REALZD_CAP_GAIN
//========================================================
double MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(73,"imr_realzd_cap_gain",t);
}



//^^^

#line 1 "imr_realzd_cap_gain.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_prepmt(t);

}


//@@ END

//@@ START - imr_realzd_cap_gain_from_sale
// Interest Maintenance Reserve Realized Capital Gains from Sales                                                                                             
// Column:IMR_REALZD_CAP_GAIN_FROM_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(74,"imr_realzd_cap_gain_from_sale",t);
}



//^^^

#line 1 "imr_realzd_cap_gain_from_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - imr_realzd_cap_gain_rml
// Interest Maintenance Reserve Realized Capital Gain for Residential Mortgage                                                                                             
// Column:IMR_REALZD_CAP_GAIN_RML
//========================================================
double MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_rml(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(75,"imr_realzd_cap_gain_rml",t);
}



//^^^

#line 1 "imr_realzd_cap_gain_rml.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

// added by HYH 09/03/2021
if (category_id != "RML") 
	return 0.0;

return realzd_cap_gain_prepmt(t);

}


//@@ END

//@@ START - imr_realzd_cap_gain_rml_from_sale
// Interest Maintenance Reserve Realized Capital Gains from Sales for Residential Mortgage                                                                                             
// Column:IMR_REALZD_CAP_GAIN_RML_FROM_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_rml_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"imr_realzd_cap_gain_rml_from_sale",t);
}



//^^^

#line 1 "imr_realzd_cap_gain_rml_from_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// added by HYH 09/03/2021
if (category_id != "RML") 
	return 0.0;

return realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - imr_yrs_to_maturity
// Interest Maintenance Reserve Years to Maturity                                                                                             
// Column:IMR_YRS_TO_MATURITY
//========================================================
double MTG_ASSET_UDF::mtg_asset_imr_yrs_to_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"imr_yrs_to_maturity",t);
}



//^^^

#line 1 "imr_yrs_to_maturity.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_yrs_to_maturity[t];

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		return intex->get_tranche_maturity_period / 12.0;

	return NO_AVG;
	}
#endif

return xint(cal_mth(t) - 1 + maturity_period - t) / 12.0;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double MTG_ASSET_UDF::mtg_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.MTG_ASSET.for"
if (!isMainModel)
	shrink_mtg_clone(getElementNumber());

// Create psa_base_rate
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
				
		// reinitialize num_record
		num_mtg = 0;
		}

	// increment the number of records
	num_mtg++;

	#if defined(__ADCO_ASSET_H_)
	if (use_andrew_davidson)
		adco->initialize(t);
	#endif

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
			throw FatalError("Error: Cannot open mtg->asset_detail_rpt_id."	
							 "Present value detail reporting has been cancelled."
							 "Check that the directory has been created and that you have permission to write it");
		else
			PVCFile << endl
					<<"Present Value Detail Report for "
					<< get_file_name(output_location()) << endl;
		}
	}

#if defined(__INTEX_ASSET_H_)
if (use_intex_databases_for_mtg
	&& existing_asset_indicator)
	{
	if (intex)
		{
		intex->initialize(0);

		setup_intex_submodel_parameters(0);

		int pmt_rate_defn_saved = FIXED_RATE;
		int maturity_period_saved = calculated_t_high;
		if (intex->initialize_asset())
			{
			is_asset_initialize = 1;

			// Reset maturity period
			maturity_period = last_proj_period + 1;

			intex_proj_flag = true;
			
			for (int tt = 0; tt <= last_proj_period; tt++)
				intex_tgt(tt);

			intex_proj_flag = false;

			intex_asset = true;

			// Save the pmt_rate_defn based on intex value
			pmt_rate_defn_saved = pmt_rate_defn;
			maturity_period_saved = maturity_period;

			is_asset_initialize = 0;
			}
		
		resetValues();
		sm_mtg_cf->resetValues();

		// Set scalars to saved values
		maturity_period = maturity_period_saved;	
		pmt_rate_defn = pmt_rate_defn_saved;
		}
	}
#endif	

xstring index_val;

index_val = asset_id + data_grp_id + xstring(data_rec_num());

if ((mtg_initial_values_map_iter = mtg_initial_values_map.find(index_val))
	!= mtg_initial_values_map.end())
	// When values are in map, then read from map
	initial_values = mtg_initial_values_map_iter->second;	
else
	{
	// Otherwise, add values to map
	is_asset_initialize = 1;

	if (asset_detail_pv_flag(0))
		{
		PVCounter++;
		PVCText << PVCounter 
				<< "<--Begin initialize"
				<< " for " << asset_id
	   			<< " (" << pmt_rate_defn_string << ")";
		asset_detail_pv_output();
		}


	initial_values = new struct mtgInitialValuesData;

	// net_yld must be called first
	//   because the prepayment interest differenital may be set to Net Yield
	net_yld(0);
	mkt_val(0);
	eff_dur(0);

	initial_values->yld_numer = yld_numer(0);
	initial_values->dflt_amt = dflt_amt(0);
	initial_values->mkt_val_bef_sale = mkt_val_bef_sale(0);
	initial_values->eff_dur = eff_dur(0);
	initial_values->mkt_sprd = mkt_sprd(0);
	initial_values->mths_to_next_reset = mtg->mths_to_next_reset(0);
	initial_values->net_yld = net_yld(0);

	if (!intex_asset)
		initial_values->pmt_rate = mtg_cf->pmt_rate(0);
	else
		initial_values->pmt_rate = 0.0;

	initial_values->weighted_avg_life = weighted_avg_life(0);

	mtg_initial_values_map[index_val] = initial_values;

	if (asset_detail_pv_flag(0))
		{
		PVCText << PVCounter 
				<< "<-- End initialize" 
				<< " for " << asset_id
				<< " (" << pmt_rate_defn_string << ")";
 		asset_detail_pv_output();
		PVCounter--;
		}

	is_asset_initialize = 0;

	resetValues();
	mtg_cf->resetValues();
	}

return 1.0;

}


//@@ END

//@@ START - int_div_and_rent
// Interest Dividend and Rent                                                                                             
// Column:INT_DIV_AND_RENT
//========================================================
double MTG_ASSET_UDF::mtg_asset_int_div_and_rent(int t) {
//^^^



//^^^

#line 1 "int_div_and_rent.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_int_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(80,"int_pmt",t);
}



//^^^

#line 1 "int_pmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_int_pmt[t]
	       * intex_pct_remaining(t - 1);

if (balloon_pmt_period > t)
	return mtg_cf->int_pmt(t);

return mtg_cf->int_pmt(t)
	   + mtg_cf->balloon_pmt_inc(t);

}


//@@ END

//@@ START - intex_accr_int_adj
// Intex Accrued Interest Adjustment                                                                                             
// Column:INTEX_ACCR_INT_ADJ
//========================================================
double MTG_ASSET_UDF::mtg_asset_intex_accr_int_adj(int t) {
//^^^



//^^^

#line 1 "intex_accr_int_adj.MTG_ASSET.for"
if (!intex_asset)
	return NO_AVG;

if (fabs(mtg_cf->par_val_bef_sale(t)) < model_point_amount_threshold)
	return NO_AVG;

return -accr_int_bef_sale(t);

}


//@@ END

//@@ START - intex_pct_remaining
// Intex Percent Remaining                                                                                             
// Column:INTEX_PCT_REMAINING
//========================================================
double MTG_ASSET_UDF::mtg_asset_intex_pct_remaining(int t) {
//^^^



//^^^

#line 1 "intex_pct_remaining.MTG_ASSET.for"
if (!intex_asset || t <= 0)
	return 1.0;
	
return intex_pct_remaining(t - 1)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - intex_tgt
// Intex Target                                                                                             
// Column:INTEX_TGT
//========================================================
double MTG_ASSET_UDF::mtg_asset_intex_tgt(int t) {
//^^^



//^^^

#line 1 "intex_tgt.MTG_ASSET.for"
if (!intex_proj_flag)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (!intex)
	return 0;

if (t == 0)
	{
	int array_size = calculated_t_high + 1;
	if (intex_net_yld.size() < array_size)
		{
		intex_net_yld.resize(array_size);
		intex_accr_int.resize(array_size);
		intex_cost_basis.resize(array_size);
		intex_bk_val.resize(array_size);
		intex_mkt_val.resize(array_size);
		intex_eff_dur.resize(array_size);
		intex_notional_amt.resize(array_size);
		intex_weighted_avg_life.resize(array_size);
		intex_yrs_to_maturity.resize(array_size);
		intex_dflt_amt.resize(array_size);
		intex_int_pmt.resize(array_size);
		intex_sched_prin_pmt.resize(array_size);
		intex_opt_pmt.resize(array_size);
		intex_amortzn_of_disc.resize(array_size);
		intex_realzd_cap_gain_prepmt.resize(array_size);
		intex_realzd_cap_loss_dflt.resize(array_size);
		intex_unrealzd_cap_loss_from_dflt.resize(array_size);
		intex_cost_basis_dflt.resize(array_size);
		}

	// initialize array elements
	for (int i = 0; i < array_size; i++)
		{	
		intex_net_yld[i] = 0.0;
		intex_accr_int[i] = 0.0;
		intex_cost_basis[i] = 0.0;
		intex_bk_val[i] = 0.0;
		intex_mkt_val[i] = 0.0;
		intex_eff_dur[i] = 0.0;
		intex_notional_amt[i] = 0.0;
		intex_weighted_avg_life[i] = 0.0;
		intex_dflt_amt[i] = 0.0;
		intex_int_pmt[i] = 0.0;
		intex_sched_prin_pmt[i] = 0.0;
		intex_opt_pmt[i] = 0.0;
		intex_amortzn_of_disc[i] = 0.0;
		intex_realzd_cap_gain_prepmt[i] = 0.0;
		intex_realzd_cap_loss_dflt[i] = 0.0;
		intex_unrealzd_cap_loss_from_dflt[i] = 0.0;
		intex_cost_basis_dflt[i] = 0.0;
		}

	// reset, then force call scalars to have value set by intex parameters
	pmt_rate_defn.reset();
	int pmt_rate_defn = this->pmt_rate_defn;

	maturity_period.reset();
	int maturity_period = this->maturity_period;

	// force call market value projection to get balance array setup
	intex->resetValues();
	intex->shift_defn = "No Shift";
	intex->proj_defn = MARKET_VALUE;
	intex->mkt_val_cash_flow_proj(0, "Actual", 
		sm_mtg_cf->par_val_bef_sale(0) / sm_mtg_cf->tranche_portion_bef_sale(0));

	log_screen << "Intex Pre-Projection for Mortgage: ID = " << asset_id;

	if (intex->get_collateral_num_of_pools > 1
		|| intex->balloon_extension == YES
		|| intex->get_tranche_cdu_mths_offset != 0)
		{
		xstring lspace = "";
		log_screen << " (";
		if (intex->get_collateral_num_of_pools > 1)
			{
			log_screen << intex->get_collateral_num_of_pools
					<< " pools";
			lspace = " ";
			}
		if (intex->balloon_extension == YES)
			{
			log_screen << lspace << "balloon extension";
			lspace = " ";
			}
		if (intex->get_tranche_cdu_mths_offset != 0)
			log_screen << lspace << intex->get_tranche_cdu_mths_offset
					<< " cdu mths";
		log_screen << ")" << MSG_USER;
		}
	else
		log_screen << MSG_USER;			
	}

// run model
if (t == 0)
	{
	intex_net_yld[t] = net_yld(t);
	intex_accr_int[t] = accr_int_bef_sale(t);
	intex_cost_basis[t] = cost_basis_bef_sale(t);
	intex_bk_val[t] = bk_val_bef_sale(t);
	intex_mkt_val[t] = mkt_val_bef_sale(t);
	intex_eff_dur[t] = eff_dur(t);
	intex_notional_amt[t] = notional_amt_bef_sale(t);
	intex_weighted_avg_life[t] = weighted_avg_life(t);
	intex_yrs_to_maturity[t] = intex->get_tranche_maturity_period / 12.0;
	}
else
	{	
	if (notional_amt(t - 1) > 0)
		{
		intex_net_yld[t] = net_yld(t);
		intex_accr_int[t] = accr_int_bef_sale(t);
		intex_cost_basis[t] = cost_basis_bef_sale(t);
		intex_bk_val[t] = bk_val_bef_sale(t);

		if (fabs(notional_amt_bef_sale(t)) >= ASSET_ACTIVE_THRESHOLD)
			{
			intex_mkt_val[t] = mkt_val_bef_sale(t);
			intex_eff_dur[t] = eff_dur(t);
			intex_weighted_avg_life[t] = weighted_avg_life(t);
			}

		intex_notional_amt[t] = notional_amt_bef_sale(t);
		intex_dflt_amt[t] = dflt_amt(t);
		intex_int_pmt[t] = int_pmt(t);
		intex_sched_prin_pmt[t] = sched_prin_pmt(t);
		intex_opt_pmt[t] = opt_pmt(t);
		intex_amortzn_of_disc[t] = cost_basis_bef_prepmt(t)
		                           - cost_basis_aft_dflt(t)
		                           + cost_basis_sched_prin_pmt(t)
		                           + cost_basis_bef_sale(t)
		                           - cost_basis_aft_prepmt(t);
		intex_realzd_cap_gain_prepmt[t] = realzd_cap_gain_prepmt(t);
		intex_realzd_cap_loss_dflt[t] = realzd_cap_loss_dflt(t);
		intex_unrealzd_cap_loss_from_dflt[t] = unrealzd_cap_loss_from_dflt(t);
		intex_cost_basis_dflt[t] = cost_basis_dflt(t);
		intex_yrs_to_maturity[t] = (intex->get_tranche_maturity_period - t) / 12.0;
		}
	}

if (t == min(calculated_t_high, last_model_period))
	{
	intex->resetValues();
	intex->finalize(t);
	}
#endif

return 1;

}


//@@ END

//@@ START - mkt_risk_sprd
// Market Risk Spread                                                                                             
// Column:MKT_RISK_SPRD
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_risk_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(84,"mkt_risk_sprd",t);
}



//^^^

#line 1 "mkt_risk_sprd.MTG_ASSET.for"
if (intex_asset || t < commencement_period || t > maturity_period)
	return NO_AVG;

if (mtg_cf->par_val_bef_sale(t) <= 0.0)
	return NO_AVG;

double risk_sprd
= rates->get_int_rate(t,
                category_id,
				GET_SPOT_SPREAD,
				weighted_avg_life(t),
				0.0,
				NOMINAL_SEMIANNUAL,
				NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

return risk_sprd
		+ mkt_sprd(t);

}


//@@ END

//@@ START - mkt_sprd
// Market Spread                                                                                             
// Column:MKT_SPRD
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_sprd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(85,"mkt_sprd",t);
}



//^^^

#line 1 "mkt_sprd.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (intex_asset)
	return NO_AVG;

if (t == 0 && existing_asset_indicator)
	{
	if (!is_asset_initialize)
		return initial_values->mkt_sprd;

	double calculated_market_spread = 0.0;

	if (init_mkt_val == 0
		|| asset_mkt_sprd_use_defn == SET_TO_ZERO)
		return 0.0;
	else
		{
		if (asset_detail_pv_flag(t))
			{
			PVCounter++;
			PVCText << PVCounter
					<< "-->Begin Market Spread Calculation"
					<< " for " << asset_id
					<< " (" << pmt_rate_defn_string << ")"
					<< " t=" << t
					<< " CalYr=" << xint(cal_yr(t)) 
					<< " CalMth=" << xint(cal_mth(t));
			asset_detail_pv_output();
			}

		rebase_cash_flow(t,
				PRESENT_VALUE,
				"mtg->mkt_sprd",
				modelName);

		double risk_sprd
		= rates->get_int_rate(t,
		            category_id,
					GET_SPOT_SPREAD,
					weighted_avg_life(t),
					0.0,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

		if (asset_detail_pv_flag(t)
				&& asset_detail_rpt_pv_defn == YES)
			{
			PVCText << "RiskSprdUnshifted,"
					<< write_string(risk_sprd,PVCLen,PVCSigDig) << endl
					<< "WeightedAverageLife,"
					<< write_string(weighted_avg_life(t),PVCLen,PVCSigDig);
			asset_detail_pv_output();
			}	    			    											

		calculated_market_spread
		= mtg_pv->solve_for_sprd_newton_raphson(t, 
					risk_sprd, 
					init_mkt_val
					* neg_asset_flag);

		if (asset_detail_pv_flag(t))
			{
			PVCText << PVCounter
					<< "<--End Market Spread Calculation ("
					<< write_string(calculated_market_spread,PVCLen,PVCSigDig)
					<< ") for " << asset_id
					<< " (" << pmt_rate_defn_string << ")"
					<< " t=" << t
					<< " CalYr=" << xint(cal_yr(t)) 
					<< " CalMth=" << xint(cal_mth(t));
			asset_detail_pv_output();
			PVCounter--;
			}
		}

	return calculated_market_spread;
	}
	
if (!existing_asset_indicator && t == commencement_period)
	return 0.0;

if (asset_mkt_sprd_use_defn == HOLD_LEVEL)
	return mkt_sprd(t - 1);

if (asset_mkt_sprd_use_defn == GRADE_TO_ZERO)
	return mkt_sprd(t - 1) * (1.0 - 1.0 / (1.0 + maturity_period - t));

if (asset_mkt_sprd_use_defn == SET_TO_ZERO)
	return 0.0;

return 0.0;

}


//@@ END

//@@ START - mkt_to_bk_ratio
// Market to Book Ratio                                                                                             
// Column:MKT_TO_BK_RATIO
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "mkt_to_bk_ratio.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(87,"mkt_val",t);
}



//^^^

#line 1 "mkt_val.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - mkt_val_bef_fund_match_sale
// Market Value Before Fund Value Matching Asset Sales                                                                                             
// Column:MKT_VAL_BEF_FUND_MATCH_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(88,"mkt_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "mkt_val_bef_fund_match_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_neg_cash_flow_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(91,"mkt_val_bef_sale",t);
}



//^^^

#line 1 "mkt_val_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->mkt_val_bef_sale;

if (intex_asset)
	return intex_mkt_val[t]
	       * intex_pct_remaining(t - 1);

if (!existing_asset_indicator && t == commencement_period)
	{
	if (purch_defn == INVESTMENT)
		return cost_basis_bef_sale(t);

	return mtg_cf->par_val_bef_sale(t)
		   * mkt_val_per_unit_par;
	}

if (fabs(notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Before Sale"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	}

rebase_cash_flow(t,
			PRESENT_VALUE, "mtg->mkt_val_bef_sale", modelName);

if (mkt_val_defn == TO_NEXT_RATE_RESET)
	mtg_pv->pv_calc_parameters(t,
				MARKET_VALUE, mths_to_next_reset(t));
else // TO_MATURITY
	mtg_pv->pv_calc_parameters(t,
				MARKET_VALUE, xint(maturity_period - t));

if (mtg_pv->prepmt_appl == YES
	&& mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
	{
	// force recalulation of yield maintenance cash flow
	mtg_ym->rebase_period = mtg_pv->rebase_period - 1;
	}

if (mtg_pv->pv_tbl_defn == INITIALIZE_TABLES
		&& mtg_pv->prepmt_appl == YES)
	{
	pv_interest_savings_after_prepayments[0]
	= mtg_pv->pv_int_savings_pv_for_mkt_val_calc
	= mtg_pv->int_savings_pv_aft_prepmt(t);
	}

double spread_to_spot = mkt_sprd(t);

if (asset_detail_pv_flag(t)
	&& asset_detail_rpt_pv_defn == YES)
	{
	PVCText << "MktSprd,"
			<< write_string(mkt_sprd(t),PVCLen,PVCSigDig);
	asset_detail_pv_output();
	}

double temp1 = 0;
double temp2 = 0;

double calculated_market_value
= mtg_pv->pv_calc(t, 
			spread_to_spot,
			temp1, // calculated_derivative
			temp2  // calculated_modified_duration
			);

mtg_pv->pv_calc_parameters(t, CASH_FLOWS);

if (asset_detail_pv_flag(t))
	{
	if (asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << endl
				<< "MktVal," << write_string(calculated_market_value,PVCLen,PVCSigDig) << endl
				<< "WAL," << write_string(weighted_avg_life(t),PVCLen,PVCSigDig) << endl;
		PVCFile << "AdjSprd," << write_string(mkt_sprd(t),PVCLen,PVCSigDig) << endl;
		}
	PVCText << PVCounter
			<< "<--End Market Value Before Sale ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	PVCounter--;
	}

return calculated_market_value;

}


//@@ END

//@@ START - mkt_val_for_dur_bef_neg_cash_flow_sale
// Market Value for Duration Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_FOR_DUR_BEF_NEG_CASH_FLOW_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"mkt_val_for_dur_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_neg_cash_flow_sale.MTG_ASSET.for"
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
	return mkt_val_bef_neg_cash_flow_sale(t) + accr_int_bef_neg_cash_flow_sale(t); // added by HYH on 5/24/2021;
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"mkt_val_for_dur_bef_rebal_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"mkt_val_for_dur_sold",t);
}



//^^^

#line 1 "mkt_val_for_dur_sold.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_for_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"mkt_val_for_eff_dur",t);
}



//^^^

#line 1 "mkt_val_for_eff_dur.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_purch(int t) {
//^^^



//^^^

#line 1 "mkt_val_purch.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_shifted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"mkt_val_shifted",t);
}



//^^^

#line 1 "mkt_val_shifted.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (fabs(notional_amt_bef_sale(t)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Shifted"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	}

rebase_cash_flow(t,
			PRESENT_VALUE, "mtg->mkt_val_shifted", modelName);

if (mkt_val_defn == TO_NEXT_RATE_RESET)
	mtg_pv->pv_calc_parameters(t,
				MARKET_VALUE_SHIFTED, mths_to_next_reset(t));
else // TO_MATURITY
	mtg_pv->pv_calc_parameters(t,
				MARKET_VALUE_SHIFTED, xint(maturity_period - t));

double wal = 0;

// force recalulation of cash flow

if (mtg_pv->prepmt_appl == YES
	&& mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
	mtg_ym->rebase_period = mtg_pv->rebase_period - 1;

wal = mtg_pv->weighted_avg_life_calc(t);

double spread_to_spot = mkt_sprd(t);

if (asset_detail_pv_flag(t)
	&& asset_detail_rpt_pv_defn == YES)
	{
	PVCText << "MktSprd,"
			<< write_string(mkt_sprd(t),PVCLen,PVCSigDig);
	asset_detail_pv_output();
	}

double temp1=0;
double temp2=0;

double calculated_market_value
= mtg_pv->pv_calc(t,
			spread_to_spot,
			temp1, // calculated_derivative
			temp2  // calculated_modified_duration
			);

mtg_pv->pv_calc_parameters(t, CASH_FLOWS);

if (asset_detail_pv_flag(t))
	{
	if (asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << endl
				<< "MktVal," << write_string(calculated_market_value,PVCLen,PVCSigDig) << endl
				<< "WAL," << write_string(weighted_avg_life(t),PVCLen,PVCSigDig) << endl
				<< "AdjSprd," << write_string(mkt_sprd(t),PVCLen,PVCSigDig) << endl;
		}
	PVCText << PVCounter
			<< "<--End Market Value Shifted ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	PVCounter--;
	}

return calculated_market_value;

}


//@@ END

//@@ START - mkt_val_sold
// Market Value Sold                                                                                             
// Column:MKT_VAL_SOLD
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_val_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"mkt_val_sold",t);
}



//^^^

#line 1 "mkt_val_sold.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_neg_cash_flow_sale.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (neg_asset_flag < 0)
	return NO_AVG;

return mkt_val_for_dur_bef_neg_cash_flow_sale(t)
       * dur_val(t);

}


//@@ END

//@@ START - mkt_val_times_dur_bef_rebal_sale
// Market Value Times Duration Before Rebalancing Sales                                                                                             
// Column:MKT_VAL_TIMES_DUR_BEF_REBAL_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_mkt_val_times_dur_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_times_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"mkt_val_times_eff_dur",t);
}



//^^^

#line 1 "mkt_val_times_eff_dur.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

return mkt_val_for_eff_dur(t)
       * eff_dur(t);

}


//@@ END

//@@ START - mths_bef_maturity
// Months Before Maturity                                                                                             
// Column:MTHS_BEF_MATURITY
//========================================================
double MTG_ASSET_UDF::mtg_asset_mths_bef_maturity(int t) {
//^^^



//^^^

#line 1 "mths_bef_maturity.MTG_ASSET.for"
// This column can be used as a lookup key, such as for linking to an external source
if (dflt_rate_bef_maturity_defn == FIRST_BALLOON_PAYMENT_DATE)
	return min(balloon_pmt_period, maturity_period) - t;

return maturity_period - t;

}


//@@ END

//@@ START - mths_since_issue
// Months Since Issue                                                                                             
// Column:MTHS_SINCE_ISSUE
//========================================================
double MTG_ASSET_UDF::mtg_asset_mths_since_issue(int t) {
//^^^



//^^^

#line 1 "mths_since_issue.MTG_ASSET.for"
// This column can be used as a lookup key, such as for linking to an external source
return init_mths_since_issue + t;

}


//@@ END

//@@ START - mths_to_next_mkt_val_calc
// Months to Next Market Value Calculation                                                                                             
// Column:MTHS_TO_NEXT_MKT_VAL_CALC
//========================================================
double MTG_ASSET_UDF::mtg_asset_mths_to_next_mkt_val_calc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(104,"mths_to_next_mkt_val_calc",t);
}



//^^^

#line 1 "mths_to_next_mkt_val_calc.MTG_ASSET.for"
if (t < 0)
	return NO_AVG;

if (!isMainModel)
	return asset->mths_to_next_mkt_val_calc(t);

if (t == 0)
	{
	if (mkt_val_calc_freq == BEGINNING_AND_END_OF_PROJECTION)
		return 9999;

	else if (mkt_val_calc_freq == MONTHLY)
		return 1;

	else if (mkt_val_calc_freq == QUARTERLY_MAR_JUN_SEP_DEC_)
		return (3 - ((proj_start_mth - 1) % 3));

	else if (mkt_val_calc_freq == SEMIANNUALLY_JUN_DEC_)
		return (6 - ((proj_start_mth - 1) % 6));

	else if (mkt_val_calc_freq == ANNUALLY_DEC_)
		return (12 - ((proj_start_mth - 1) % 12));

	else
		return (12 * mkt_val_calc_freq_yrs 
				- proj_start_mth +  1);
	}

if (t == last_model_period)	
	return 0;  

if (mths_to_next_mkt_val_calc(t - 1) > 0)	
	return mths_to_next_mkt_val_calc(t - 1) - 1;

if (mths_to_next_mkt_val_calc(t - 1) == 0		
	&& mkt_val_calc_freq == MONTHLY)	
	return 0;

if (mths_to_next_mkt_val_calc(t - 1) == 0		
	&& mkt_val_calc_freq == QUARTERLY_MAR_JUN_SEP_DEC_)
	return 2;

if (mths_to_next_mkt_val_calc(t - 1) == 0
	&& mkt_val_calc_freq == SEMIANNUALLY_JUN_DEC_)
	return 5;

if (mths_to_next_mkt_val_calc(t - 1) == 0
	&& mkt_val_calc_freq == ANNUALLY_DEC_)
	return 11;

if (mths_to_next_mkt_val_calc(t - 1) == 0
	&& mkt_val_calc_freq == EVERY_NTH_YEAR_DEC_)
	return 12 * mkt_val_calc_freq_yrs - 1;

return NO_AVG;

}


//@@ END

//@@ START - net_yld
// Net Yield                                                                                             
// Column:NET_YLD
//========================================================
double MTG_ASSET_UDF::mtg_asset_net_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(105,"net_yld",t);
}



//^^^

#line 1 "net_yld.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn != AMORTIZED_COST)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->net_yld;

if (intex_asset)
	return intex_net_yld[t];

if (!intex_proj_flag && amortzn_cost_period - t <= 0)
	return convert_rate_basis(mtg_cf->pmt_rate(t),
                 pmt_freq, 12);

bool calculate_net_yield = false;
int amortzn_period = 0;
double target_value = 0;
double local_net_yield = 0;
double guess_yield = 0;

if ((existing_asset_indicator && t == 0)
    || (!existing_asset_indicator && t == commencement_period))
	{
	calculate_net_yield = true;
	target_value = cost_basis_bef_sale(t);
	amortzn_period = amortzn_cost_period - t;

	if (!existing_asset_indicator && t == commencement_period)
		{
		//rebase net yield model
		rebase_cash_flow(t,
					PRESENT_VALUE, "mtg->net_yld", modelName);

		mtg_pv->pv_calc_parameters(t,
					NET_YIELD, xint(amortzn_period));

		guess_yield = (mtg_cf->par_val_bef_sale(t)
		               * mtg_cf->pmt_rate(t)
		               + (mtg_cf->par_val_bef_sale(t)
		                  - cost_basis_bef_sale(t))
		                  / weighted_avg_life(t) )
		               / ((mtg_cf->par_val_bef_sale(t)
		                   + cost_basis_bef_sale(t)) / 2.0);
		}
	else
		{
		if (intex_proj_flag)
			guess_yield = 0.0;
		else
			guess_yield = mtg_cf->pmt_rate(t);
		}
	}
else 
	{
	if (mtg_cf->par_val_aft_sched_pmt(t) < model_point_amount_threshold)
		return NO_AVG;

	target_value = cost_basis_aft_prepmt(t);  

	if (intex_proj_flag
		&& (amortzn_cost_period - t <= 0
			|| (pmt_rate_defn == FLOATING_RATE 
				&& mtg->mths_to_next_reset(t - 1) == 1)))
		{	
		guess_yield = convert_rate_basis(net_yld(t - 1), 
							  12,
							  NOMINAL_SEMIANNUAL);
		calculate_net_yield = true;
		amortzn_period = max(1, amortzn_cost_period - t);
		}

	else if (purch_defn == FORECLOSURE
			 && cost_basis_aft_prepmt(t) > 0.0
			 && mtg_cf->since_foreclosure_int_mult(t)
				!= mtg_cf->since_foreclosure_int_mult(t + 1))
		{
		guess_yield = mtg_cf->pmt_rate(t);
		calculate_net_yield = true;
		amortzn_period = maturity_period - t;
		}

	else if (purch_defn == RESTRUCTURE
			 && cost_basis_aft_prepmt(t) > 0.0
			 && mtg_cf->since_restructure_int_mult(t)
				!= mtg_cf->since_restructure_int_mult(t + 1))
		{
		guess_yield = mtg_cf->pmt_rate(t);
		calculate_net_yield = true;
		amortzn_period = maturity_period - t;
		}

	else if (amortzn_cost_period - t > 0
			 && pmt_rate_defn == FLOATING_RATE 
			 && mtg->mths_to_next_reset(t - 1) == 1
			 && cost_basis_aft_prepmt(t) > 0.0)
		{			
		guess_yield = mtg_cf->pmt_rate(t);
		calculate_net_yield = true;
		amortzn_period = amortzn_cost_period - t;
		}	    
	}

if (existing_asset_indicator && t == 0)
  	{
   	if (target_value == 0.0 && mtg_cf->par_val(t) != 0.0)
		{
		log_screen.setf(ios::fixed, ios:: floatfield);
		log_screen << "Error. Unable to calculate spread to amortize Target Value to "
				   << "Par Value because Target value is zero and Par Value "
				   << mtg_cf->par_val(t) << " is not zero."
				   << MSG_ERROR;
		log_screen.unsetf(ios::fixed);
		log_screen << "ID = " << asset_id
				   << " |" << modelName
				   << " Year = " << xint(cal_yr(t))
				   << " Month = " << xint(cal_mth(t))
				   << " Projection Task Loop = " << proj_task_loop_num
				   << MSG_ERROR;
		 throw FatalError("");
		}
	}

// net yield equal payment rate
if (!intex_proj_flag
	&& target_value == mtg_cf->par_val_bef_sale(t)
	&& servicing_fee == 0)
	return convert_rate_basis(mtg_cf->pmt_rate(t), pmt_freq, 12);

if (calculate_net_yield == false
	&& amortzn_cost_period - t > 0)
	return net_yld(t - 1);

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Net Yield Calculation"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	}

//rebase net yield model
rebase_cash_flow(t,
			PRESENT_VALUE, "mtg->net_yld", modelName);

mtg_pv->pv_calc_parameters(t,
			NET_YIELD, xint(amortzn_period));

local_net_yield
= convert_rate_basis(mtg_pv->solve_for_sprd_newton_raphson(t, 
								guess_yield,
								target_value),
			NOMINAL_SEMIANNUAL,
            12);

mtg_pv->pv_calc_parameters(t, CASH_FLOWS);

if (asset_detail_pv_flag(t))
	{
	PVCText << PVCounter
			<< "Net Yields" << endl
			<< "Monthly," << write_string(local_net_yield,PVCLen,PVCSigDig) << endl
			<< "Semi-Annual," << write_string(convert_rate_basis(local_net_yield, 12, 2),PVCLen,PVCSigDig) << endl
			<< "Annual," << write_string(convert_rate_basis(local_net_yield, 12, 1),PVCLen,PVCSigDig) << endl;
	asset_detail_pv_output();
	PVCText << PVCounter
			<< "<--End Net Yield Calculation ("
			<< write_string(local_net_yield,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(cal_yr(t)) 
			<< " CalMth=" << xint(cal_mth(t));
	asset_detail_pv_output();
	PVCounter--;
	}

return local_net_yield;

}


//@@ END

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_notional_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(106,"notional_amt",t);
}



//^^^

#line 1 "notional_amt.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (t > commencement_period
	&& fabs(notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

if (intex_asset)
	return notional_amt_bef_sale(t)
	       * (1.0 - sold_pct(t));

return mtg_cf->par_val(t);

}


//@@ END

//@@ START - notional_amt_bef_fund_match_sale
// Notional Amount Before Fund Value Matching Asset Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_FUND_MATCH_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_notional_amt_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(107,"notional_amt_bef_fund_match_sale",t);
}



//^^^

#line 1 "notional_amt_bef_fund_match_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_notional_amt_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_neg_cash_flow_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_notional_amt_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_rebal_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_notional_amt_bef_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_notional_amt[t]
	       * intex_pct_remaining(t - 1);

return mtg_cf->par_val_bef_sale(t);

}


//@@ END

//@@ START - opt_inc
// Option Income                                                                                             
// Column:OPT_INC
//========================================================
double MTG_ASSET_UDF::mtg_asset_opt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(111,"opt_inc",t);
}



//^^^

#line 1 "opt_inc.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return NO_AVG;

return mtg_cf->prepmt_inc(t);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"opt_pmt",t);
}



//^^^

#line 1 "opt_pmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_opt_pmt[t]
	       * intex_pct_remaining(t - 1);

return mtg_cf->prepmt_amt(t);

}


//@@ END

//@@ START - rbc_c1
// Risk Based Capital C1                                                                                             
// Column:RBC_C1
//========================================================
double MTG_ASSET_UDF::mtg_asset_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_rbc_c1_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(114,"rbc_c1_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_bef_sale.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(115,"realzd_cap_gain",t);
}



//^^^

#line 1 "realzd_cap_gain.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return sched_prin_pmt(t) 
	   - cost_basis_sched_prin_pmt(t) 
	   + realzd_cap_gain_opt_pmt(t) 
	   - realzd_cap_loss_dflt(t) 
	   - realzd_cap_loss_foreclosure(t) 
	   - realzd_cap_loss_restructure(t) 
	   - foreclosure_accr_int_net_write_down(t) 
	   - restructure_accr_int_net_write_down(t) 
	   - refinance_accr_int(t);

}


//@@ END

//@@ START - realzd_cap_gain_opt_pmt
// Realized Capital Gain from Option Payment                                                                                             
// Column:REALZD_CAP_GAIN_OPT_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(116,"realzd_cap_gain_opt_pmt",t);
}



//^^^

#line 1 "realzd_cap_gain_opt_pmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_prepmt(t) 
	   + cap_gain_adj_foreclosure_prin_pmt(t)
	   + cap_gain_adj_restructure_prin_pmt(t);

}


//@@ END

//@@ START - realzd_cap_gain_prepmt
// Realized Capital Gain from Prepayment                                                                                             
// Column:REALZD_CAP_GAIN_PREPMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(117,"realzd_cap_gain_prepmt",t);
}



//^^^

#line 1 "realzd_cap_gain_prepmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_realzd_cap_gain_prepmt[t]
	       * intex_pct_remaining(t - 1);

return mtg_cf->prepmt_amt(t) 
	   - cost_basis_bef_prepmt(t)
	     * mtg_cf->prepmt_pct_mthly(t);

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gain from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(118,"realzd_cap_gain_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return NO_AVG;

return cap_gain_from_sale(t)
	   + unrealzd_cap_gain_released_on_sale(t);

}


//@@ END

//@@ START - realzd_cap_loss_dflt
// Realized Capital Loss from Default                                                                                             
// Column:REALZD_CAP_LOSS_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(119,"realzd_cap_loss_dflt",t);
}



//^^^

#line 1 "realzd_cap_loss_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_realzd_cap_loss_dflt[t]
	       * intex_pct_remaining(t - 1);

return (cost_basis(t - 1) + accr_int(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - realzd_cap_loss_foreclosure
// Realized Capital Loss from Foreclosure                                                                                             
// Column:REALZD_CAP_LOSS_FORECLOSURE
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_foreclosure(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"realzd_cap_loss_foreclosure",t);
}



//^^^

#line 1 "realzd_cap_loss_foreclosure.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (cost_basis(t - 1) + accr_int(t - 1)) 
		* foreclosure_pct(t) 
		* foreclosure_write_down_pct_calc;

}


//@@ END

//@@ START - realzd_cap_loss_restructure
// Realized Capital Loss from Restructure                                                                                             
// Column:REALZD_CAP_LOSS_RESTRUCTURE
//========================================================
double MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_restructure(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(121,"realzd_cap_loss_restructure",t);
}



//^^^

#line 1 "realzd_cap_loss_restructure.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (cost_basis(t - 1) + accr_int(t - 1)) 
		* restructure_pct(t) 
		* restructure_write_down_pct_calc;

}


//@@ END

//@@ START - refinance_accr_int
// Refinance Accrued Interest                                                                                             
// Column:REFINANCE_ACCR_INT
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(122,"refinance_accr_int",t);
}



//^^^

#line 1 "refinance_accr_int.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;
  
return accr_int(t - 1) 
	  * refinance_pct(t);

}


//@@ END

//@@ START - refinance_bk_val
// Refinance Book Value                                                                                             
// Column:REFINANCE_BK_VAL
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(123,"refinance_bk_val",t);
}



//^^^

#line 1 "refinance_bk_val.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val(t - 1)
	  * refinance_pct(t);

}


//@@ END

//@@ START - refinance_cost_basis
// Refinance Cost Basis                                                                                             
// Column:REFINANCE_COST_BASIS
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(124,"refinance_cost_basis",t);
}



//^^^

#line 1 "refinance_cost_basis.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis(t - 1) 
	   * refinance_pct(t);

}


//@@ END

//@@ START - refinance_pct
// Refinance Percent                                                                                             
// Column:REFINANCE_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(125,"refinance_pct",t);
}



//^^^

#line 1 "refinance_pct.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (refinance_asset_id < 0
	|| decr_rate(t) == 0)
	return NO_AVG;

return decr_pct(t)
	   * refinance_rate(t)
	   / decr_rate(t);

}


//@@ END

//@@ START - refinance_prin
// Refinance Principal                                                                                             
// Column:REFINANCE_PRIN
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_prin(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(126,"refinance_prin",t);
}



//^^^

#line 1 "refinance_prin.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return mtg_cf->par_val(t - 1)
	   * refinance_pct(t);

}


//@@ END

//@@ START - refinance_rate
// Refinance Rate                                                                                             
// Column:REFINANCE_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_refinance_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(127,"refinance_rate",t);
}



//^^^

#line 1 "refinance_rate.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

double refinance_rate_prelim
= (rates->get_dflt_rate(t,
                        category_id,
                        EFFECTIVE_ANNUAL)
   * refinance_rate_scen_mult
   + refinance_rate_pct)
  * refinance_rate_mult_since_issue // Lookup key is mths_since_issue(t)
  * refinance_rate_mult_bef_maturity; // Lookup key is mths_bef_maturity(t)

double refinance_rate
= (max(min(round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
						refinance_rate_prelim,
						DECIMALS_TO_ROUND), 1.0), 0.0));

if (refinance_rate < rate_ratio_threshold)
	return NO_AVG;

return refinance_rate;

}


//@@ END

//@@ START - restructure_accr_int_net_write_down
// Restructure Accrued Interest Net Write Down                                                                                             
// Column:RESTRUCTURE_ACCR_INT_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_accr_int_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(128,"restructure_accr_int_net_write_down",t);
}



//^^^

#line 1 "restructure_accr_int_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;
  
return (accr_int(t - 1) 
		* restructure_pct(t)) 
	   * (1.0 - restructure_write_down_pct_calc);

}


//@@ END

//@@ START - restructure_bk_val_net_write_down
// Restructure Book Value Net Write Down                                                                                             
// Column:RESTRUCTURE_BK_VAL_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_bk_val_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(129,"restructure_bk_val_net_write_down",t);
}



//^^^

#line 1 "restructure_bk_val_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;
  
return (bk_val(t - 1) 
		* restructure_pct(t)) 
	   * (1.0 - restructure_write_down_pct_calc);

}


//@@ END

//@@ START - restructure_cost_basis_net_write_down
// Restructure Cost Basis Net Write Down                                                                                             
// Column:RESTRUCTURE_COST_BASIS_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_cost_basis_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(130,"restructure_cost_basis_net_write_down",t);
}



//^^^

#line 1 "restructure_cost_basis_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (cost_basis(t - 1)
		* restructure_pct(t))
	   * (1.0 - restructure_write_down_pct_calc);

}


//@@ END

//@@ START - restructure_pct
// Restructure Percent                                                                                             
// Column:RESTRUCTURE_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(131,"restructure_pct",t);
}



//^^^

#line 1 "restructure_pct.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (restructure_asset_id < 0
	|| decr_rate(t) == 0)
	return NO_AVG;

return decr_pct(t)
	   * restructure_rate(t)
	   / decr_rate(t);

}


//@@ END

//@@ START - restructure_prin_net_write_down
// Restructure Principal Net Write Down                                                                                             
// Column:RESTRUCTURE_PRIN_NET_WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_prin_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(132,"restructure_prin_net_write_down",t);
}



//^^^

#line 1 "restructure_prin_net_write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;
  
return (mtg_cf->par_val(t - 1) 
		* restructure_pct(t)) 
	   * (1.0 - restructure_write_down_pct_calc);

}


//@@ END

//@@ START - restructure_rate
// Restructure Rate                                                                                             
// Column:RESTRUCTURE_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_rate(int t) {
//^^^



//^^^

#line 1 "restructure_rate.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;

double restructure_pct_prelim
= (rates->get_dflt_rate(t,
                        category_id,
                        EFFECTIVE_ANNUAL)
   * restructure_rate_scen_mult
   + restructure_rate_pct)
  * restructure_rate_mult_since_issue // Lookup key is mths_since_issue(t)
  * restructure_rate_mult_bef_maturity; // Lookup key is mths_bef_maturity(t)

double restructure_pct
= (max(min(round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
						restructure_pct_prelim,
						DECIMALS_TO_ROUND), 1.0), 0.0));

if (restructure_pct < rate_ratio_threshold)
	return NO_AVG;

return restructure_pct;

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_sched_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(134,"sched_prin_pmt",t);
}



//^^^

#line 1 "sched_prin_pmt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_sched_prin_pmt[t]
	       * intex_pct_remaining(t - 1);

return mtg_cf->sched_prin_pmt(t);

}


//@@ END

//@@ START - sold_pct
// Sold Percent                                                                                             
// Column:SOLD_PCT
//========================================================
double MTG_ASSET_UDF::mtg_asset_sold_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(135,"sold_pct",t);
}



//^^^

#line 1 "sold_pct.MTG_ASSET.for"
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
double MTG_ASSET_UDF::mtg_asset_sold_pct_fund_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(136,"sold_pct_fund_match",t);
}



//^^^

#line 1 "sold_pct_fund_match.MTG_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_neg_cash_flow
// Sold Percent Negative Cash Flow                                                                                             
// Column:SOLD_PCT_NEG_CASH_FLOW
//========================================================
double MTG_ASSET_UDF::mtg_asset_sold_pct_neg_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(137,"sold_pct_neg_cash_flow",t);
}



//^^^

#line 1 "sold_pct_neg_cash_flow.MTG_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_planned
// Sold Percent Planned                                                                                             
// Column:SOLD_PCT_PLANNED
//========================================================
double MTG_ASSET_UDF::mtg_asset_sold_pct_planned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(138,"sold_pct_planned",t);
}



//^^^

#line 1 "sold_pct_planned.MTG_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_rebal
// Sold Percent Rebalancing                                                                                             
// Column:SOLD_PCT_REBAL
//========================================================
double MTG_ASSET_UDF::mtg_asset_sold_pct_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(139,"sold_pct_rebal",t);
}



//^^^

#line 1 "sold_pct_rebal.MTG_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double MTG_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.MTG_ASSET.for"
#if 0 // START_HEADER
struct mtgInitialValuesData
	{
	double yld_numer;
	double dflt_amt;
	double mkt_val_bef_sale;
	double eff_dur;
	double mkt_sprd;
	int mths_to_next_reset;
	double net_yld;
	double pmt_rate;
	double weighted_avg_life;
	};
typedef map <xstring, struct mtgInitialValuesData*, less<xstring> > mtgivmap;
#endif // END_HEADER

#if 0 // START_EXTERNS
int num_mtgs_to_run;
int num_mtg = 0;
sowfinput mtg_mp_input;
sowfcols mtg_mp_input_cols;
sowfinput mtg_sch_input;
sowfcols mtg_sch_input_cols;
sowfoutput mtg_sch_output;
sowfmap mtg_sch_input_pos;
sowfmapiter mtg_sch_input_pos_iter;
sowfmap mtg_sch_input_size;
sowfmapiter mtg_sch_input_size_iter;

extern sowmpoutput mtg_state_of_world_mp_output;
static mtgivmap mtg_initial_values_map;
static mtgivmap::iterator mtg_initial_values_map_iter;
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern bool is_asset_initialize;

// present value calculation variables
#define YM_UPDATE 0
extern int pv_months;
extern int pv_last_cash_flow_month;
extern int pv_asset_defn;
extern int pv_model_point;
extern double pv_initial_years_to_payment;
extern double pv_initial_accrued_interest;
extern double pv_initial_par_value;
extern double pv_interest_savings_monthly_refinancing_rate;
extern bool pv_par_val_per_unit_of_par_calculation;
extern bool pv_initialize_interest_savings_table;
extern bool pv_initialize_yield_maintenance_table;
extern SmartArray <double>& pv_cash_flows;
extern SmartArray <double>& pv_interest_savings_after_prepayments;
extern SmartArray <double>& pv_yield_maintenance_cash_flows;
extern SmartArray <double>& pv_yield_maintenance_par_plus_accrued;

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

extern bool intex_fatal_error;
extern bool intex_detail_wanted;
extern bool adco_fatal_error;

extern int model_t_low;
extern int model_t_high;
extern int maximum_t_high_value;
extern int minimum_t_low_value;
#endif // END_EXTERNS

#if 0 // START_CLASS
int sequence_id;
bool intex_asset;
int calculated_t_low;
int calculated_t_high;
struct mtgInitialValuesData* initial_values;
double purch_amt;
int purch_asset_mp_num;
bool read_sch_file_flag;
StrEnum::EnumValue use_eom_scen_rates;

// Model point variables
xstring seg_id;
StrEnum::EnumValue port_defn;
StrEnum::EnumValue sale_class;
xstring issue_date;
xstring maturity_date;
int amortzn_start_cy;
xstring planned_sale_date;
double init_par_val;
double init_cost_basis;
double init_bk_val;
double init_mkt_val;
StrEnum::EnumValue pmt_mode;
double init_pmt_rate;
double servicing_fee;
double prin_val_at_issue;
xstring prepmt_opt_first_date;
StrEnum::EnumValue prepmt_penalty_defn;
StrEnum::EnumValue balloon_defn;
xstring balloon_date;
double yld_maint_addn;
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

double prepmt_protect_yrs;
double first_par_prepmt_yr;
double prepmt_penalty_mult;
double prepmt_penalty_addn;
double adj_addn_init;

// Schedule variables
SmartArray <double> prepmt_penalty_sch;
SmartArray <double> balloon_sch;

SmartArray <double> intex_net_yld;
SmartArray <double> intex_accr_int;
SmartArray <double> intex_cost_basis;
SmartArray <double> intex_bk_val;
SmartArray <double> intex_mkt_val;
SmartArray <double> intex_eff_dur;
SmartArray <double> intex_notional_amt;
SmartArray <double> intex_weighted_avg_life;
SmartArray <double> intex_yrs_to_maturity;
SmartArray <double> intex_dflt_amt;
SmartArray <double> intex_int_pmt;
SmartArray <double> intex_sched_prin_pmt;
SmartArray <double> intex_opt_pmt;
SmartArray <double> intex_amortzn_of_disc;
SmartArray <double> intex_realzd_cap_gain_prepmt;
SmartArray <double> intex_realzd_cap_loss_dflt;
SmartArray <double> intex_unrealzd_cap_loss_from_dflt;
SmartArray <double> intex_cost_basis_dflt;

SmartArray <double> psa_base_rate;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
sequence_id = 0;
intex_asset = false;
calculated_t_low = 0;
calculated_t_high = 0;
initial_values = NULL;
purch_amt = 0.0;
purch_asset_mp_num = -1;
read_sch_file_flag = true;
use_eom_scen_rates = YES;

// Initialize model point variables
seg_id = "Seg";
port_defn = INVESTMENT;
sale_class = AVAILABLE_FOR_SALE; 
issue_date = "1900/01/01";
maturity_date = "1900/01/01";
amortzn_start_cy = 1900;
planned_sale_date = "9999/01/01"; 
init_par_val = 0.0;
init_cost_basis = 0.0;
init_bk_val = 0.0;
init_mkt_val = 0.0;
pmt_mode = MONTHLY;
init_pmt_rate = 0.0;
servicing_fee = 0.0;
prin_val_at_issue = 0.0;
prepmt_opt_first_date = "9999/01/01";
prepmt_penalty_defn = NOT_APPLICABLE;
balloon_defn = NO;
balloon_date = "9999/01/01"; 
yld_maint_addn = 0.0;
adj_reset_category_id = "Govt";
adj_reset_scen_yr = 0.25;
adj_reset_scen_mult = 1.0;
adj_reset_renewal_addn = 0.0;
adj_next_reset_date = "9999/01/01";
adj_reset_mths = 12;
adj_max_incr_per_reset = 1.0;
adj_max_decr_per_reset = 1.0;
adj_min_rate = 0.0;
adj_max_rate = 1.0;
avr_contribn_pct = 0.0;
avr_max_pct = 0.0;
avr_obj_pct = 0.0;
rbc_c1_pct = 0.0;

prepmt_protect_yrs = 999.0;
first_par_prepmt_yr = 999.0;
prepmt_penalty_mult = 1.0;
prepmt_penalty_addn = 0.0;
adj_addn_init = 0.0;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
if (PVCFile != NULL)
	PVCFile.close();
#endif // END_TERMINATOR

intex_asset = false;

if (use_mp == NO)
	{
	skipModelPoint();
	return 1.0;
	}

if (isMainModel)
	{
	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	// set stoch_flag for rates loading
	stoch_flag = true;

	static bool first_time = true;
	if (first_time)
		{
		first_time = false;
		num_mtgs_to_run = calc_num_records_to_run();
		}

	#if defined(ASSET_ONLY_MODEL)
	rates = sm_mtg_rates;

	sm_mtg_cf->rates = rates;
	last_proj_period = last_model_period;
	
	#if defined(__ADCO_ASSET_H_)
	if (sm_mtg_adco)
		{
		adco = sm_mtg_adco;
		sm_mtg_cf->adco = adco;
		adco->rates = rates;
		}
	#endif	

	#if defined(__INTEX_ASSET_H_)
	if (sm_mtg_intex)
		{
		intex = sm_mtg_intex;
		sm_mtg_cf->intex = intex;
		intex->rates = rates;

		#if defined(__ADCO_ASSET_H_)
		if (sm_mtg_adco)
			intex->adco = adco;
		#endif	
		}
	#endif
	#endif

	model_t_low = t_low;
	model_t_high = t_high;

	maximum_t_high_value = t_high;
	minimum_t_low_value = t_low;
	}
else
	{
	#if defined(ASSET_ONLY_MODEL)
	if (sm_mtg_rates && !sm_mtg_rates->isShrunk)
		sm_mtg_rates->shrink();

	#if defined(__ADCO_ASSET_H_)
	if (sm_mtg_adco && !sm_mtg_adco->isShrunk)
		sm_mtg_adco->shrink();
	#endif	

	#if defined(__INTEX_ASSET_H_)
	if (sm_mtg_intex && !sm_mtg_intex->isShrunk)
		sm_mtg_intex->shrink();
	#endif
	#endif

	rates = asset->rates;
	sm_mtg_cf->rates = rates;
	}

if (!isMainModel
	&& !investing_flag
	&& asset->num_mtgs_init > -1
	&& getElementNumber() >= asset->num_mtgs_init)
	{
	shrink_mtg_clone(getElementNumber());
	return 1;
	}

// Grow clones here so that their t_high and t_low values
// are set correctly before they are shrunk in initialize.
if (mtg_pv->isShrunk)
	mtg_pv->grow();
if (mtg_is->isShrunk)
	mtg_is->grow();
if (mtg_ym->isShrunk)
	mtg_ym->grow();

// initialize the calculated t_low and t_high
calculated_t_low = model_t_low;
calculated_t_high = model_t_high;

if (investing_flag)
	{
	purch_asset_mp_num = asset->purch_asset_mp_num;

	t_low = calculated_t_low = xint(commencement_period);
	t_high = calculated_t_high = xint(maturity_period);

	return 1;
	}

setup_existing_asset();

#if defined(__INTEX_ASSET_H_)
if (use_intex_databases_for_mtg
	&& existing_asset_indicator)
	{
	// because Intex cash flows may extend beyond the stated maturity date
	t_low = calculated_t_low = model_t_low;
	t_high = calculated_t_high = model_t_high;

	// check t_low, t_high
	if (!isMainModel)
		{
		if (!asset->valid_t_low_t_high(calculated_t_low, calculated_t_high))
			{
			skipModelPoint();
			return 1;
			}
		}

	return 1;
	}
#endif

calculated_t_low = model_t_low;
calculated_t_high = model_t_high;

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
double MTG_ASSET_UDF::mtg_asset_sub_port_id(int t) {
//^^^



//^^^

#line 1 "sub_port_id.MTG_ASSET.for"
if (isMainModel || t < commencement_period || (existing_asset_indicator && t < 0))
	return NO_AVG;

double dur_for_transfer = 0;

if (t <= maturity_period)
	{
	if (asset->asset_sub_port_assign_dur_defn == YEARS_TO_MATURITY)
		{
		dur_for_transfer = (maturity_period - t) / 12.0;
		}
	else if ((t > 0 && mths_to_next_mkt_val_calc(t) > 0)
			//20220613 STW: add a condition for model efficiency improvement
			|| fast_stat_calc_aig == YES)
		dur_for_transfer = 0; // don't want to force a market value calculation
	else if (asset->asset_sub_port_assign_dur_defn == EFFECTIVE_DURATION)
		dur_for_transfer = eff_dur(t);
	else // if (asset->grp_assign_dur == WEIGHTED_AVERAGE_LIFE)
		dur_for_transfer = weighted_avg_life(t);
	}

if (existing_asset_indicator && t == 0)
	return asset->asset_sub_port_assign(t, 1, "Mortgage",
					port_defn,
					category_id,
					existing_asset_indicator,
					dur_for_transfer,
					-1);

if (!existing_asset_indicator && t == commencement_period)
	return asset->asset_sub_port_assign(t, 1, "Mortgage",
					port_defn,
					category_id,
					existing_asset_indicator,
					dur_for_transfer,
					purch_asset_sub_port);

return asset->asset_sub_port_assign(t, 0, "Mortgage",
				port_defn,
				category_id,
				existing_asset_indicator,
				dur_for_transfer,
				sub_port_id(t - 1));

}


//@@ END

//@@ START - unrealzd_cap_gain
// Unrealized Capital Gain                                                                                             
// Column:UNREALZD_CAP_GAIN
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(142,"unrealzd_cap_gain",t);
}



//^^^

#line 1 "unrealzd_cap_gain.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_fund_match_sale
// Unrealized Capital Gain Before Fund Value Matching Asset Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_FUND_MATCH_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(143,"unrealzd_cap_gain_bef_fund_match_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_fund_match_sale.MTG_ASSET.for"
if (t <= commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t)
       * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_neg_cash_flow_sale
// Unrealized Capital Gain Before Negative Cash Flow Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_NEG_CASH_FLOW_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(144,"unrealzd_cap_gain_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_neg_cash_flow_sale.MTG_ASSET.for"
if (t <= commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_rebal_sale(t)
       * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_rebal_sale
// Unrealized Capital Gain Before Rebalancing Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_REBAL_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(145,"unrealzd_cap_gain_bef_rebal_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_rebal_sale.MTG_ASSET.for"
if (t <= commencement_period || t >= maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_fund_match_sale(t)
       * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_sale
// Unrealized Capital Gain Before Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(146,"unrealzd_cap_gain_bef_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_sale.MTG_ASSET.for"
if (t <= commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   - cost_basis_bef_sale(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_gaap_surp
// Unrealized Capital Gain GAAP Surplus                                                                                             
// Column:UNREALZD_CAP_GAIN_GAAP_SURP
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_gaap_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"unrealzd_cap_gain_gaap_surp",t);
}



//^^^

#line 1 "unrealzd_cap_gain_gaap_surp.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_surp_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(148,"unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return unrealzd_cap_gain_bef_sale(t)
		   - unrealzd_cap_gain(t - 1);

return (bk_val_bef_prepmt(t) - cost_basis_bef_prepmt(t))
	    * (1.0 - mtg_cf->prepmt_pct_mthly(t))
	   - bk_val_aft_dflt(t) 
	   + (cost_basis(t - 1) - bk_val(t - 1))
	      * (dflt_pct(t)
			 + foreclosure_pct(t) 
			   * foreclosure_write_down_pct_calc
			 + restructure_pct(t) 
			   * restructure_write_down_pct_calc)
	   - bk_val_aft_prepmt(t)
	   + bk_val_bef_sale(t)
	   - cost_basis_bef_sale(t)
	   + cost_basis_aft_dflt(t)
	   + cost_basis_aft_prepmt(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released on Sale                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_released_on_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_to_bk_ratio.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_sale(t) + accr_int_bef_sale(t)) < model_point_amount_threshold)
	return USLIB_MIN_DOUBLE;

return unrealzd_cap_gain_bef_sale(t)
	   / (bk_val_bef_sale(t) + accr_int_bef_sale(t));

}


//@@ END

//@@ START - unrealzd_cap_loss_from_dflt
// Unrealized Capital Loss From Default                                                                                             
// Column:UNREALZD_CAP_LOSS_FROM_DFLT
//========================================================
double MTG_ASSET_UDF::mtg_asset_unrealzd_cap_loss_from_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(151,"unrealzd_cap_loss_from_dflt",t);
}



//^^^

#line 1 "unrealzd_cap_loss_from_dflt.MTG_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (intex_asset)
	return intex_unrealzd_cap_loss_from_dflt[t]
	       * intex_pct_remaining(t - 1);

return (bk_val(t - 1) - cost_basis(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - weighted_avg_life
// Weighted Average Life                                                                                             
// Column:WEIGHTED_AVG_LIFE
//========================================================
double MTG_ASSET_UDF::mtg_asset_weighted_avg_life(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(152,"weighted_avg_life",t);
}



//^^^

#line 1 "weighted_avg_life.MTG_ASSET.for"
if (t < commencement_period || t >= maturity_period || fabs(notional_amt_bef_sale(t)) < model_point_amount_threshold)
	return NO_AVG;

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->weighted_avg_life; 

if (intex_asset)
	return intex_weighted_avg_life[t];

if (mtg_pv->pv_defn != MARKET_VALUE_SHIFTED)
	{
	if (mtg_pv->isShrunk
		|| mtg_pv->rebase_period < t
		|| (!existing_asset_indicator && t == commencement_period))
		{
		rebase_cash_flow(t,
					PRESENT_VALUE,
					"mtg->weighted_avg_life",
					modelName);

		if (mtg_pv->prepmt_appl == YES
			&& mtg_pv->pv_defn != MARKET_VALUE_SHIFTED)
			pv_interest_savings_after_prepayments[0]
			= mtg_pv->int_savings_pv_aft_prepmt(t);
		}

	if (mtg_pv->pv_defn == MARKET_VALUE
		&& mkt_val_defn == TO_NEXT_RATE_RESET)
		mtg_pv->pv_calc_parameters(t,
					MARKET_VALUE, mths_to_next_reset(t));
	else // TO_MATURITY
		mtg_pv->pv_calc_parameters(t,
					MARKET_VALUE, xint(maturity_period - t));
	}

return mtg_pv->weighted_avg_life_calc(t);

}


//@@ END

//@@ START - write_down
// Write Down                                                                                             
// Column:WRITE_DOWN
//========================================================
double MTG_ASSET_UDF::mtg_asset_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(153,"write_down",t);
}



//^^^

#line 1 "write_down.MTG_ASSET.for"
if (intex_asset || t <= commencement_period || t > maturity_period)
	return NO_AVG;
  
return realzd_cap_loss_foreclosure(t)
	   + realzd_cap_loss_restructure(t)
	   + foreclosure_accr_int_net_write_down(t) 
	   + restructure_accr_int_net_write_down(t) 
	   + refinance_accr_int(t);

}


//@@ END

//@@ START - yld_denom
// Yield Denominator                                                                                             
// Column:YLD_DENOM
//========================================================
double MTG_ASSET_UDF::mtg_asset_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(154,"yld_denom",t);
}



//^^^

#line 1 "yld_denom.MTG_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (t == 0
	&& (existing_asset_indicator
		|| intex_proj_flag))
	return bk_val(t) + accr_int(t);

if (intex_asset)
	return bk_val(t - 1) + accr_int(t - 1);

double asset_yld_denom_factor = 0;

double accr_inc_bef_sched_pmt
= cost_basis_bef_prepmt(t)
  + accr_int_bef_prepmt(t)
  - cost_basis_aft_dflt(t)
  - accr_int_aft_dflt(t)
  + int_pmt(t)
  + cost_basis_sched_prin_pmt(t)
  - cap_gain_adj_foreclosure_prin_pmt(t)
  - cap_gain_adj_restructure_prin_pmt(t);

if (bk_val_aft_prepmt(t) 
	+ accr_int_aft_prepmt(t) > 0.0)
	{
	double accr_inc_aft_prepmt
	= cost_basis_bef_sale(t)
	  + accr_int_bef_sale(t)
	  + intex_accr_int_adj(t)
	  - cost_basis_aft_prepmt(t)
	  - accr_int_aft_prepmt(t);
	
	asset_yld_denom_factor 
	= (1.0 + (accr_inc_bef_sched_pmt)
			 / (bk_val(t - 1) + accr_int(t - 1)))
	  * (1.0 + (accr_inc_aft_prepmt)
			   / (bk_val_aft_prepmt(t)
			      + accr_int_aft_prepmt(t)))
	  - 1.0;
	}

if ((bk_val(t - 1) + accr_int(t - 1)) > 0.0)
	{
    asset_yld_denom_factor
    = accr_inc_bef_sched_pmt
      / (bk_val(t - 1) + accr_int(t - 1));
	}                       

if (asset_yld_denom_factor != 0.0)
	return accr_inc(t) / asset_yld_denom_factor;

if (bk_val_aft_prepmt(t) 
	+ accr_int_aft_prepmt(t) > 0.0)
	return bk_val(t - 1) +  accr_int(t - 1);

return bk_val(t - 1) + accr_int(t - 1);

}


//@@ END

//@@ START - yld_numer
// Yield Numerator                                                                                             
// Column:YLD_NUMER
//========================================================
double MTG_ASSET_UDF::mtg_asset_yld_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(155,"yld_numer",t);
}



//^^^

#line 1 "yld_numer.MTG_ASSET.for"
//20220519 STW: Restored to original US library code, with no duration weighted adj
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0
	&& !is_asset_initialize)
	return initial_values->yld_numer;

if (intex_proj_flag && t == 0)
	return ((cost_basis_bef_sale(t)
		     + accr_int_bef_sale(t))
		     * net_yld(t) / 12.0);

if (existing_asset_indicator && t == 0)
	return yld_numer(t + 1);

return accr_inc(t);  


}


//@@ END

//@@ START - yld_numer_adj_aig
// Yield Numerator Capital with duration weighted adjustment                                                                                             
// Column:YLD_NUMER_ADJ_AIG
//========================================================
double MTG_ASSET_UDF::mtg_asset_yld_numer_adj_aig(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(156,"yld_numer_adj_aig",t);
}



//^^^

#line 1 "yld_numer_adj_aig.MTG_ASSET.for"
//20220519 STW: Revised to be Yield Numerator Capital with duration weighted adjustment
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0
	&& !is_asset_initialize)
	return initial_values->yld_numer;

if (intex_proj_flag && t == 0)
	return ((cost_basis_bef_sale(t)
		     + accr_int_bef_sale(t))
		     * net_yld(t) / 12.0);

if (existing_asset_indicator && t == 0)
	return yld_numer_adj_aig(t + 1);

// 20210607 STW: import IA Prod v3.0 RSD v2 change and wrap it with a flag. The code has not been tested yet.
if(ia_prod_v3_rsd_2_aig == YES)
{
	//HYH 5/26/2021, per email from Josh @ WTW on 5/26/2021
	double pmt_rate_bey = convert_rate_basis(mtg_cf->pmt_rate(t), NOMINAL_MONTHLY, NOMINAL_SEMIANNUAL);
	double duration_weighted_sprd_mthly = convert_rate_basis(pmt_rate_bey + dur_wtd_sprd_adj_aig, NOMINAL_SEMIANNUAL, ACTUAL_MONTHLY) - mtg_cf->pmt_rate(t) / 12;

	if(valn_flag) //20240814 Apply dur_wtd_sprd_adj_aig in outer loop only
	{
		duration_weighted_sprd_mthly = 0.;
	}

	return accr_inc(t)
			+ (duration_weighted_sprd_mthly * mtg_cf->par_val(t-1)); //AIG - ADD SPREAD TO EARNED AMOUNT HERE WHICH FLOWS INTO TOTAL NER ON SEGMENT LEVEL
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
double MTG_ASSET_UDF::mtg_asset_accr_int_per_par_unit() {
//^^^


#line 1 "accr_int_per_par_unit.MTG_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

return (pow(1.0 + pmt_rate_at_issue / pmt_freq,
			yrs_since_last_pmt * pmt_freq) - 1.0);

}


//@@ END

//@@ START - amortzn_cost_period
// Amortization Cost Period                                                                                             
// Calculated Variable:AMORTZN_COST_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_amortzn_cost_period() {
//^^^


#line 1 "amortzn_cost_period.MTG_ASSET.for"
if (existing_asset_indicator)
	{
	if (amortzd_cost_period_defn == TO_NEXT_RATE_RESET)
		return min(mtg->mths_to_next_reset(0), maturity_period);

	// (amortzd_cost_period_defn == TO_MATURITY)
	return maturity_period;
	}

if (amortzd_cost_period_defn == TO_NEXT_RATE_RESET)
	return min(commencement_period + mtg->mths_to_next_reset(commencement_period),
	           maturity_period);

// (amortzd_cost_period_defn == TO_MATURITY)
return maturity_period;

}


//@@ END

//@@ START - amortzn_period
// Amortization Period                                                                                             
// Calculated Variable:AMORTZN_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_amortzn_period() {
//^^^


#line 1 "amortzn_period.MTG_ASSET.for"
int amortzn_period_prelim
= max(0, maturity_period - (get_yr_from_date(maturity_date) - amortzn_start_cy) * 12);

if (amortzn_period_prelim > 0)
	return amortzn_period_prelim
		   + ((maturity_period - amortzn_period_prelim) % (pmt_mths));

return 0;

}


//@@ END

//@@ START - asset_detail_rpt_flag
// Detail Report Flag                                                                                             
// Calculated Variable:ASSET_DETAIL_RPT_FLAG
//========================================================
int MTG_ASSET_UDF::mtg_asset_asset_detail_rpt_flag() {
//^^^


#line 1 "asset_detail_rpt_flag.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_asset_fund_index() {
//^^^


#line 1 "asset_fund_index.MTG_ASSET.for"
if (port_defn == INVESTMENT)
	return INVESTMENT_FUND_INDEX;

// else set to "Investment" default value
makeRunLogYellow();
log_screen << "Warning: Invalid portfolio definition (" << port_defn
		   <<") for mortgage ID = " << asset_id
		   << "." << MSG_ERROR;
log_screen << " ... Portfolio definition has been reset to Investment. " << MSG_ERROR;

port_defn = INVESTMENT;

return INVESTMENT_FUND_INDEX;

}


//@@ END

//@@ START - balloon_pmt_flag
// Balloon Payment Flag                                                                                             
// Calculated Variable:BALLOON_PMT_FLAG
//========================================================
int MTG_ASSET_UDF::mtg_asset_balloon_pmt_flag() {
//^^^


#line 1 "balloon_pmt_flag.MTG_ASSET.for"
if (balloon_defn == NO)
	return NO;

if (balloon_defn == YES_ON_SINGLE_PERIOD
	&& balloon_pmt_period > 0 
	&& balloon_pmt_period <= maturity_period)
	return YES;

if (balloon_defn == YES_PER_SCHEDULE)
	return YES;

return NO;

}


//@@ END

//@@ START - balloon_pmt_period
// Balloon Payment Period                                                                                             
// Calculated Variable:BALLOON_PMT_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_balloon_pmt_period() {
//^^^


#line 1 "balloon_pmt_period.MTG_ASSET.for"
return date_diff(balloon_date, proj_date_adj);

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_commencement_period() {
//^^^


#line 1 "commencement_period.MTG_ASSET.for"
if (investing_flag)
	return investment_period;

return 0;

}


//@@ END

//@@ START - data_grp_id
// Data Group Identification                                                                                             
// Calculated Variable:DATA_GRP_ID
//========================================================
xstring MTG_ASSET_UDF::mtg_asset_data_grp_id() {
//^^^


#line 1 "data_grp_id.MTG_ASSET.for"
return get_base_group_name(group, false);//WTW - Gen2 - Move Extern definitions to rates header

}


//@@ END

//@@ START - existing_asset_indicator
// Existing Asset Indicator                                                                                             
// Calculated Variable:EXISTING_ASSET_INDICATOR
//========================================================
int MTG_ASSET_UDF::mtg_asset_existing_asset_indicator() {
//^^^


#line 1 "existing_asset_indicator.MTG_ASSET.for"
if (purch_asset_mp_num == -1)
	{
	// Existing asset was purchased during a previous scenario time step
	if (time_step_flag && !valn_flag && valn_period != 0
		&& date_diff(issue_date, proj_date) > 0)
		return PRIOR_PURCH;	
	
	// Existing at original projection date
	return INIT_MP;
	}

// New purchase in current scenario time step
return NEW_PURCH;

}


//@@ END

//@@ START - foreclosure_asset_id
// Foreclosure Asset Identification                                                                                             
// Calculated Variable:FORECLOSURE_ASSET_ID
//========================================================
int MTG_ASSET_UDF::mtg_asset_foreclosure_asset_id() {
//^^^


#line 1 "foreclosure_asset_id.MTG_ASSET.for"
if (isMainModel)
	return 1;

return company->sm_inv_strategy[seg_num]->foreclosure_asset_id;

}


//@@ END

//@@ START - foreclosure_write_down_pct_calc
// Foreclosure Write Down Percentage Calculated                                                                                             
// Calculated Variable:FORECLOSURE_WRITE_DOWN_PCT_CALC
//========================================================
double MTG_ASSET_UDF::mtg_asset_foreclosure_write_down_pct_calc() {
//^^^


#line 1 "foreclosure_write_down_pct_calc.MTG_ASSET.for"
return max(0.0, min(1.0, foreclosure_write_down_pct));

}


//@@ END

//@@ START - gaap_inc_defn
// GAAP Income Definition                                                                                             
// Calculated Variable:GAAP_INC_DEFN
//========================================================
int MTG_ASSET_UDF::mtg_asset_gaap_inc_defn() {
//^^^


#line 1 "gaap_inc_defn.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_gaap_val_defn() {
//^^^


#line 1 "gaap_val_defn.MTG_ASSET.for"
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

//@@ START - init_mths_since_issue
// Initial Months Since Issue                                                                                             
// Calculated Variable:INIT_MTHS_SINCE_ISSUE
//========================================================
int MTG_ASSET_UDF::mtg_asset_init_mths_since_issue() {
//^^^


#line 1 "init_mths_since_issue.MTG_ASSET.for"
if (existing_asset_indicator)
	{
	int mths_since_issue
	= min(proj_start_yr - get_yr_from_date(issue_date),
		  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
	  + proj_start_mth
	  - get_mth_from_date(issue_date) - 1;

  	if ((mths_since_issue < 0)
		  || (maturity_period + mths_since_issue) 
			 % pmt_mths != 0)
		mths_since_issue
		= max(0, mths_since_issue) 
		  + (((((maturity_period
				 + max(0, mths_since_issue)) 
				 / pmt_mths) + 1) 
				 * pmt_mths) 
				 - (maturity_period
     				+ max(0, mths_since_issue))) 
     		% pmt_mths;

	return mths_since_issue;
	}

// not existing asset
return - commencement_period;

}


//@@ END

//@@ START - maturity_mths_from_next_reset
// Maturity Months from Next Reset                                                                                             
// Calculated Variable:MATURITY_MTHS_FROM_NEXT_RESET
//========================================================
int MTG_ASSET_UDF::mtg_asset_maturity_mths_from_next_reset() {
//^^^


#line 1 "maturity_mths_from_next_reset.MTG_ASSET.for"
if (!existing_asset_indicator)
	return 0;	

return min(get_yr_from_date(maturity_date) - get_yr_from_date(adj_next_reset_date),
		   MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
		   + get_mth_from_date(maturity_date) - get_mth_from_date(adj_next_reset_date);

}


//@@ END

//@@ START - maturity_period
// Maturity Period                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_maturity_period() {
//^^^


#line 1 "maturity_period.MTG_ASSET.for"
if (existing_asset_indicator && init_par_val == 0.0)
	return 0;

if (existing_asset_indicator)
	{
	if (intex_asset)
		return last_proj_period + 1;
	
	#if defined(__INTEX_ASSET_H_)
	if (intex_proj_flag)
		{
		if (intex)
			// because Intex cash flows may extend beyond the stated maturity date
			return calculated_t_high;
		}
	#endif		
	
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
double MTG_ASSET_UDF::mtg_asset_mkt_val_per_unit_par() {
//^^^


#line 1 "mkt_val_per_unit_par.MTG_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

if (asset_detail_pv_flag(commencement_period))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Per Unit Par"
			<< " for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period)) 
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_pv_output();
	}

pv_par_val_per_unit_of_par_calculation = true;

double par_value_local = max(ONE_MILLION, fabs(purch_amt));

rebase_cash_flow(commencement_period,
		PRESENT_VALUE, "mtg->mkt_val_per_unit_par", modelName);

if (mkt_val_defn == TO_NEXT_RATE_RESET)
	mtg_pv->pv_calc_parameters(commencement_period,
				MARKET_VALUE, mths_to_next_reset(commencement_period));
else // TO_MATURITY
	mtg_pv->pv_calc_parameters(commencement_period,
				MARKET_VALUE, xint(maturity_period - commencement_period));

if (mtg_pv->prepmt_appl == YES
	&& mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
	{
	// force recalulation of yield maintenance cash flow
	mtg_ym->rebase_period = mtg_pv->rebase_period - 1;
	}

if (mtg_pv->pv_tbl_defn == INITIALIZE_TABLES
	&& mtg_pv->prepmt_appl == YES
	&& mtg_pv->pv_defn != MARKET_VALUE_SHIFTED)
	pv_interest_savings_after_prepayments[0]
	= mtg_pv->int_savings_pv_aft_prepmt(commencement_period);

// don't replace wal with weighted_avg_life(commencement_period) in call to get_category_rate
double wal = mtg_pv->weighted_avg_life_calc(commencement_period);

double category_risk_spread_unshifted
= rates->get_int_rate(commencement_period,
            category_id,
			GET_SPOT_SPREAD,
			wal,
			0.0,
			NOMINAL_SEMIANNUAL,
			NO_SHIFT,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

if (asset_detail_pv_flag(commencement_period)
	&& asset_detail_rpt_pv_defn == YES)
	{
	PVCText << "CatRiskSprdUnshifted,"
			<< write_string(category_risk_spread_unshifted,PVCLen,PVCSigDig);
	asset_detail_pv_output();
	}

double temp1 = 0;
double temp2 = 0;

double base_price
= mtg_pv->pv_calc(commencement_period, 
			0.0,
			temp1, // calculated_derivative
			temp2  // calculated_modified_duration
			);

// do not replace with call to mtg_pv->pv_calc_parameters
mtg_pv->pv_tbl_defn = "No Tables";
pv_months = 0;

if (asset_detail_pv_flag(commencement_period))
	{
	PVCText << "BasePrice,"	<< write_string(base_price,PVCLen,PVCSigDig) << endl;
	asset_detail_pv_output();
	}

double price_per_unit_of_par = base_price / par_value_local;

pv_par_val_per_unit_of_par_calculation = false;

if (asset_detail_pv_flag(commencement_period))
	{
	PVCText << PVCounter
			<< "<--End Market Value Per Unit Par ("
			<< write_string(price_per_unit_of_par,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " (" << pmt_rate_defn_string << ")"
			<< " t=" << commencement_period
			<< " CalYr=" << xint(cal_yr(commencement_period)) 
			<< " CalMth=" << xint(cal_mth(commencement_period));
	asset_detail_pv_output();
	PVCounter--;
	}

return price_per_unit_of_par;

}


//@@ END

//@@ START - neg_asset_flag
// Negative Asset Flag                                                                                             
// Calculated Variable:NEG_ASSET_FLAG
//========================================================
double MTG_ASSET_UDF::mtg_asset_neg_asset_flag() {
//^^^


#line 1 "neg_asset_flag.MTG_ASSET.for"
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

//@@ START - par_val_at_issue
// Par Value at Issue                                                                                             
// Calculated Variable:PAR_VAL_AT_ISSUE
//========================================================
double MTG_ASSET_UDF::mtg_asset_par_val_at_issue() {
//^^^


#line 1 "par_val_at_issue.MTG_ASSET.for"
if (existing_asset_indicator)
	{
	double local_par_val_at_issue
	= prin_val_at_issue * neg_asset_flag;

	if (local_par_val_at_issue > 0
		&& local_par_val_at_issue < mtg_cf->par_val_bef_sale(0))
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning: Par value at issue (" << setprecision(6) << local_par_val_at_issue
				<< ") is less than the par value at the projection start"
				<< " date (" << setprecision(6) << mtg_cf->par_val_bef_sale(0)
				<< ")"
				<< MSG_ERROR;
		log_screen << " ... for existing asset " << asset_id
				<< ". Par value at issue has been reset to"
				<< " par value at the projection start date."
				<< MSG_ERROR;

		local_par_val_at_issue = mtg_cf->par_val_bef_sale(0);
		}

	return local_par_val_at_issue;
	}

return mtg_cf->par_val_bef_sale(commencement_period);

}


//@@ END

//@@ START - pct_to_use
// Percent to Use                                                                                             
// Calculated Variable:PCT_TO_USE
//========================================================
double MTG_ASSET_UDF::mtg_asset_pct_to_use() {
//^^^


#line 1 "pct_to_use.MTG_ASSET.for"
if (!isMainModel)
	{
	// Existing at original projection date
	if (existing_asset_indicator == INIT_MP)
		return seg->existing_asset_pct_to_use * neg_asset_flag;
	
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
double MTG_ASSET_UDF::mtg_asset_planned_sale_period() {
//^^^


#line 1 "planned_sale_period.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_pmt_freq() {
//^^^


#line 1 "pmt_freq.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_pmt_mths() {
//^^^


#line 1 "pmt_mths.MTG_ASSET.for"
return 12 / pmt_freq;

}


//@@ END

//@@ START - pmt_rate_at_issue
// Payment Rate at Issue                                                                                             
// Calculated Variable:PMT_RATE_AT_ISSUE
//========================================================
double MTG_ASSET_UDF::mtg_asset_pmt_rate_at_issue() {
//^^^


#line 1 "pmt_rate_at_issue.MTG_ASSET.for"
if (existing_asset_indicator)
	return 0.0;

double pmt_rate_local = 0.0;

if (pmt_rate_defn == REFINANCING_RATE)
	{
	double refinancing_rate
	= category_refinancing_rate(commencement_period,
								xint(cal_yr_relative(commencement_period)),
								xint(cal_mth(commencement_period)),
								maturity_period - commencement_period,
								NOMINAL_SEMIANNUAL,
								NO_SHIFT, //shift_defn
								0);

	pmt_rate_local 
	= max(0.0, 
		  convert_rate_basis(refinancing_rate,
							 NOMINAL_SEMIANNUAL,
							 pmt_freq)
		  - company->sm_inv_strategy[seg_num]->purch_mtg_rate_diff)
	  - servicing_fee;
		
	if (pmt_rate_local < - rate_ratio_threshold)
		{
		log_screen << "Payment rate at issue for new purchased mortgage "
					+ asset_id 
					+ " is negative. Please review asset->purch_mtg_rate_diff variable" 
					<< MSG_ERROR;
		throw FatalError("MESSAGE");
		}
	else
		return pmt_rate_local;
	}

// else if (pmt_rate_defn == FIXED_RATE or FLOATING_RATE)

pmt_rate_local 
= max(0.0, 
	  rates->get_int_rate(commencement_period,
						  adj_reset_category_id,
						  GET_YIELD_RATE,
						  adj_reset_scen_yr,
						  0.0,
						  pmt_freq,
						  NO_SHIFT,portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	  * adj_reset_scen_mult
	  + adj_addn_init)
  - servicing_fee;

if (pmt_rate_local < - rate_ratio_threshold)
	{
	log_screen << "Payment rate at issue for new purchased mortgage "
				+ asset_id 
				+ " is negative. Please review purchase mortgage variables" 
				<< MSG_ERROR;
	throw FatalError("MESSAGE");
	}

return pmt_rate_local;

}


//@@ END

//@@ START - pmt_rate_defn
// Payment Rate Definition                                                                                             
// Calculated Variable:PMT_RATE_DEFN
//========================================================
int MTG_ASSET_UDF::mtg_asset_pmt_rate_defn() {
//^^^


#line 1 "pmt_rate_defn.MTG_ASSET.for"
if (existing_asset_indicator)	
	{	
	#if defined(__INTEX_ASSET_H_)
	if (intex_proj_flag)
		{	
		if (intex)
			return intex->tranche_rate_defn;
		}	
	#endif

	int mths_to_next_reset_prelim = 0;

	if (maturity_mths_from_next_reset <= 0)
		mths_to_next_reset_prelim = maturity_period;
  	else if (maturity_mths_from_next_reset < maturity_period)
		mths_to_next_reset_prelim = maturity_period - maturity_mths_from_next_reset;
	else
		mths_to_next_reset_prelim = 1;

	if (mths_to_next_reset_prelim >= maturity_period)
		return FIXED_RATE;

	return FLOATING_RATE;
	}

if (pmt_rate_defn_purch == FLOATING_RATE)
	return FLOATING_RATE;

if (pmt_rate_defn_purch == REFINANCING_RATE)
	return REFINANCING_RATE;

return FIXED_RATE;

}


//@@ END

//@@ START - pmt_rate_defn_string
// Payment Rate Definition                                                                                             
// Calculated Variable:PMT_RATE_DEFN_STRING
//========================================================
xstring MTG_ASSET_UDF::mtg_asset_pmt_rate_defn_string() {
//^^^


#line 1 "pmt_rate_defn_string.MTG_ASSET.for"
if (pmt_rate_defn == FLOATING_RATE)
	return get_string_of_enum_val(FLOATING_RATE);

return get_string_of_enum_val(FIXED_RATE);


}


//@@ END

//@@ START - pmt_reset_first_period
// Payment Reset First Period                                                                                             
// Calculated Variable:PMT_RESET_FIRST_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_pmt_reset_first_period() {
//^^^


#line 1 "pmt_reset_first_period.MTG_ASSET.for"
if (existing_asset_indicator)
	{
	#if defined(__INTEX_ASSET_H_)
	if (intex_asset)
		{
		if (intex)
			{
			if (pmt_rate_defn == FLOATING_RATE)
				return intex->get_tranche_mths_to_reset(0);

			return MAXIMUM_NUMBER_OF_MONTHS;
			}
		}
	#endif

	if (maturity_mths_from_next_reset <= 0)
		return maturity_period;
 
	int mths_to_next_reset_prelim;

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
if (pmt_rate_defn == FLOATING_RATE
		&& pmt_mths < maturity_period - commencement_period)
		return commencement_period  + adj_reset_mths;

return maturity_period;

}


//@@ END

//@@ START - prepmt_first_period
// Prepayment First Period                                                                                             
// Calculated Variable:PREPMT_FIRST_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_prepmt_first_period() {
//^^^


#line 1 "prepmt_first_period.MTG_ASSET.for"
int initial_prepayment_period
= min(get_yr_from_date(prepmt_opt_first_date) - proj_start_yr,
	  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 
  + get_mth_from_date(prepmt_opt_first_date)
  - proj_start_mth + 1;

if (prepmt_penalty_defn == PENALTY_PERCENT)
	return max(initial_prepayment_period, 0);

return initial_prepayment_period;

}


//@@ END

//@@ START - prepmt_par_first_period
// Prepayment at Par Value First Period                                                                                             
// Calculated Variable:PREPMT_PAR_FIRST_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_prepmt_par_first_period() {
//^^^


#line 1 "prepmt_par_first_period.MTG_ASSET.for"
if (prepmt_penalty_defn == NOT_APPLICABLE)
	return 0;

int initial_prepayment_period = 0;

if (existing_asset_indicator)
	{
	if (prepmt_penalty_defn == PENALTY_PERCENT)
		{
		// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
		int preliminary_first_par_prepayment_period;
		for(preliminary_first_par_prepayment_period = 0;
			preliminary_first_par_prepayment_period + 1 < maturity_period
			&& prepmt_penalty_sch[preliminary_first_par_prepayment_period] > 0.0;
			preliminary_first_par_prepayment_period++){}	

		return preliminary_first_par_prepayment_period;
		}

	return maturity_period;
	}

// else if (!existing_asset_indicator)
if ((double)(int)(12 * prepmt_protect_yrs)
	== (12 * prepmt_protect_yrs))
	initial_prepayment_period	
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
else
	initial_prepayment_period
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;

if (prepmt_penalty_defn == PENALTY_PERCENT)
	{
	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int preliminary_first_par_prepayment_period;
	for(preliminary_first_par_prepayment_period = commencement_period + 1;
		preliminary_first_par_prepayment_period + 1 < maturity_period
		&& prepmt_penalty_sch[preliminary_first_par_prepayment_period - commencement_period] > 0.0;
		preliminary_first_par_prepayment_period++){}

	return max(initial_prepayment_period, preliminary_first_par_prepayment_period);
	}

if (prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE)
	{	
	if ((double)(int)(12 * first_par_prepmt_yr)
		== (12 * first_par_prepmt_yr))
		return max(commencement_period
				   + min(first_par_prepmt_yr,
						 MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
				   initial_prepayment_period);

	return max(commencement_period
			   + min(first_par_prepmt_yr,
					 MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1,
			   initial_prepayment_period);
	}

return maturity_period;

}


//@@ END

//@@ START - prepmt_penalty_grading_mths
// Prepayment Penalty Grading Months                                                                                             
// Calculated Variable:PREPMT_PENALTY_GRADING_MTHS
//========================================================
int MTG_ASSET_UDF::mtg_asset_prepmt_penalty_grading_mths() {
//^^^


#line 1 "prepmt_penalty_grading_mths.MTG_ASSET.for"
if (existing_asset_indicator)
	return 0;

if (prepmt_penalty_defn == NOT_APPLICABLE)
	return 0;

int initial_prepayment_period = 0;
int first_zero_prepayment_premium_related_to_payment_rate_period = 0;

if ((double)(int)(12 * prepmt_protect_yrs)
	== (12 * prepmt_protect_yrs))
	initial_prepayment_period
	= commencement_period
	  + min(prepmt_protect_yrs,
		    MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
else
	initial_prepayment_period
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;
	
if ((double)(int)(12 * first_par_prepmt_yr)
	== (12 * first_par_prepmt_yr))
	first_zero_prepayment_premium_related_to_payment_rate_period
	= max(commencement_period
		  + min(first_par_prepmt_yr,
				MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
		  initial_prepayment_period);
else
	first_zero_prepayment_premium_related_to_payment_rate_period
	= max(commencement_period
		  + min(first_par_prepmt_yr,
				MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1,
		  initial_prepayment_period);

return max(first_zero_prepayment_premium_related_to_payment_rate_period
		   - initial_prepayment_period, 1);

}


//@@ END

//@@ START - prepmt_penalty_related_to_pmt_rate
// Prepayment Penalty Related to Payment Rate                                                                                             
// Calculated Variable:PREPMT_PENALTY_RELATED_TO_PMT_RATE
//========================================================
double MTG_ASSET_UDF::mtg_asset_prepmt_penalty_related_to_pmt_rate() {
//^^^


#line 1 "prepmt_penalty_related_to_pmt_rate.MTG_ASSET.for"
if (existing_asset_indicator)
	return 0.0;

int initial_prepayment_period;
int first_zero_prepayment_premium_related_to_payment_rate_period = 0;

if ((double)(int)(12 * prepmt_protect_yrs)
	 == (12 * prepmt_protect_yrs))
	initial_prepayment_period	
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS ) * 12;
else
	initial_prepayment_period
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS ) * 12 + 1;	

if ((double)(int)(12 * first_par_prepmt_yr)
	 == (12 * first_par_prepmt_yr))
	first_zero_prepayment_premium_related_to_payment_rate_period
	= max(commencement_period
		  + min(first_par_prepmt_yr,
				MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12,
		  initial_prepayment_period);
else
	first_zero_prepayment_premium_related_to_payment_rate_period
	= max(commencement_period
		  + min(first_par_prepmt_yr,
				MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1,
		  initial_prepayment_period);

if (first_zero_prepayment_premium_related_to_payment_rate_period
	 > initial_prepayment_period)
	return mtg_cf->pmt_rate(commencement_period)
		   * prepmt_penalty_mult
		   + prepmt_penalty_addn;

return 0.0;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring MTG_ASSET_UDF::mtg_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.MTG_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int MTG_ASSET_UDF::mtg_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.MTG_ASSET.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int MTG_ASSET_UDF::mtg_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.MTG_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - refinance_asset_id
// Refinance Asset Identification                                                                                             
// Calculated Variable:REFINANCE_ASSET_ID
//========================================================
int MTG_ASSET_UDF::mtg_asset_refinance_asset_id() {
//^^^


#line 1 "refinance_asset_id.MTG_ASSET.for"
if (isMainModel)
	return 1;

return company->sm_inv_strategy[seg_num]->refinance_asset_id;

}


//@@ END

//@@ START - refinancing_rate_defn_calc
// Refinancing Rate Definition Calculated                                                                                             
// Calculated Variable:REFINANCING_RATE_DEFN_CALC
//========================================================
int MTG_ASSET_UDF::mtg_asset_refinancing_rate_defn_calc() {
//^^^


#line 1 "refinancing_rate_defn_calc.MTG_ASSET.for"
return refinancing_rate_defn;

}


//@@ END

//@@ START - restructure_asset_id
// Restructure Asset Identification                                                                                             
// Calculated Variable:RESTRUCTURE_ASSET_ID
//========================================================
int MTG_ASSET_UDF::mtg_asset_restructure_asset_id() {
//^^^


#line 1 "restructure_asset_id.MTG_ASSET.for"
if (isMainModel)
	return 1;

return company->sm_inv_strategy[seg_num]->restructure_asset_id;

}


//@@ END

//@@ START - restructure_write_down_pct_calc
// Restructure Write Down Percentage Calculated                                                                                             
// Calculated Variable:RESTRUCTURE_WRITE_DOWN_PCT_CALC
//========================================================
double MTG_ASSET_UDF::mtg_asset_restructure_write_down_pct_calc() {
//^^^


#line 1 "restructure_write_down_pct_calc.MTG_ASSET.for"
return max(0.0, min(1.0, restructure_write_down_pct));

}


//@@ END

//@@ START - sale_class_id
// Sale Class Identification                                                                                             
// Calculated Variable:SALE_CLASS_ID
//========================================================
int MTG_ASSET_UDF::mtg_asset_sale_class_id() {
//^^^


#line 1 "sale_class_id.MTG_ASSET.for"
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
int MTG_ASSET_UDF::mtg_asset_sch_array_size() {
//^^^


#line 1 "sch_array_size.MTG_ASSET.for"
return maturity_period - start_period + 1;

}


//@@ END

//@@ START - seg_num
// Segment Number                                                                                             
// Calculated Variable:SEG_NUM
//========================================================
int MTG_ASSET_UDF::mtg_asset_seg_num() {
//^^^


#line 1 "seg_num.MTG_ASSET.for"
if (isMainModel)
	return 0;

return seg->getElementNumber();

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int MTG_ASSET_UDF::mtg_asset_start_period() {
//^^^


#line 1 "start_period.MTG_ASSET.for"
return max(0, commencement_period);

}


//@@ END

//@@ START - use_andrew_davidson
// Use Andrew Davidson                                                                                             
// Calculated Variable:USE_ANDREW_DAVIDSON
//========================================================
int MTG_ASSET_UDF::mtg_asset_use_andrew_davidson() {
//^^^


#line 1 "use_andrew_davidson.MTG_ASSET.for"
#if defined(__ADCO_ASSET_H_)
if (!adco) // Test for adco submodel included in current model tree
	return 0;

if (prepmt_model_defn == ANDREW_DAVIDSON)
	{
	if (use_intex_databases_for_mtg) 
		return 1;

	int loan_type = 0;

	if (existing_asset_indicator)
		{
		int issyr = 0;
		int issmth = 0;
		int matyr = 0;
		int matmth = 0;
		
		// Check that the mortgage is included in run
		matyr = get_yr_from_date(maturity_date);
		matmth = get_mth_from_date(maturity_date);
		if (matyr < proj_start_yr
			|| (matyr == proj_start_yr
				&& matmth < proj_start_mth))
			return 0;

		if (fabs(init_par_val) < aggregate_amount_threshold)
			return 0;
			
		// If months since issue is not valid then error out
		issyr  = get_yr_from_date(issue_date);
		issmth = get_mth_from_date(issue_date);

		if (issyr == 1900 && issmth == 1) // Default values
			{
			log_strm << "Error. A valid issue date is required for mortgages which use the Andrew Davidson prepayment model. ";
			log_strm << "Existing Asset ID = " << asset_id << endl;
			adco_fatal_error = true;
			}
		}

	adco->resetValues();
	
	// For existing asset testing, lookup key is asset_id
	// For purchase asset testing, lookup key is purch_asset_id
	adco->asset_id = asset_id;
	adco->category_id = category_id;
	adco->mbs_collateral_defn = xstring(adco_collateral_defn);
	adco->adjustable_rate_defn = xstring(adco_adj_rate_defn);
	
	adco->age = mths_since_issue(0);
	adco->original_term = maturity_period + mths_since_issue(0);
	adco->remaining_term = maturity_period;
		
	if (balloon_pmt_flag == YES)
		adco->balloon_term = balloon_pmt_period;
	else
		adco->balloon_term = 0;
	
	if (pmt_rate_defn == FLOATING_RATE /* ARM collateral type */)
		{
		adco->mbs_prepmt_defn = "ARM";
		adco->arm_reset_period = adj_reset_mths;
		}
	else
		{
		adco->mbs_prepmt_defn = "Fixed Rate";
		adco->arm_reset_period = 0;
		}
	
	loan_type = adco->loan_type;
	
	if (loan_type == -1)
		adco_fatal_error = true;

	if (adco_fatal_error)
		{
		if (isMainModel)
			throw NonFatalError("");
		
		return 0;
		}

	return 1;
	}

return 0;
#else
return 0;
#endif

}


//@@ END

//@@ START - use_intex_databases_for_mtg
// Use Intex Databases?                                                                                             
// Calculated Variable:USE_INTEX_DATABASES_FOR_MTG
//========================================================
int MTG_ASSET_UDF::mtg_asset_use_intex_databases_for_mtg() {
//^^^


#line 1 "use_intex_databases_for_mtg.MTG_ASSET.for"
if (intex_defn == YES && port_defn == INVESTMENT)
	return 1;

return 0;

}


//@@ END

//@@ START - write_sch_file_flag
// Write Schedule File Flag                                                                                             
// Calculated Variable:WRITE_SCH_FILE_FLAG
//========================================================
int MTG_ASSET_UDF::mtg_asset_write_sch_file_flag() {
//^^^


#line 1 "write_sch_file_flag.MTG_ASSET.for"
// Initial bonds will get values from Excel file, no need to write csv schedule file
if (existing_asset_indicator == INIT_MP) 
	return 0;

if (prepmt_penalty_defn == PENALTY_PERCENT
	|| prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE)
	return 1;

if (balloon_defn == YES_PER_SCHEDULE)
	return 1;

return 0;

}


//@@ END

//@@ START - yrs_since_last_pmt
// Years Since Last Payment                                                                                             
// Calculated Variable:YRS_SINCE_LAST_PMT
//========================================================
double MTG_ASSET_UDF::mtg_asset_yrs_since_last_pmt() {
//^^^


#line 1 "yrs_since_last_pmt.MTG_ASSET.for"
if (existing_asset_indicator)
	return (1.0 / pmt_freq)
		   - ((1 + (maturity_period - 1) % pmt_mths) / 12.0);

return (1.0 / pmt_freq)
	   - ((1 + (maturity_period - commencement_period - 1)
			   % pmt_mths) / 12.0);

}


//@@ END


#line 1 "asset_detail_log_rebase_reset.MTG_ASSET.for"                                                                                   
void MTG_ASSET::asset_detail_log_rebase_reset(int t, const xstring &rebase_model, const xstring &caller, const xstring &identifier, const xstring &id_submodel_name)
{
PVCText << " rebase model=" << rebase_model
		<< " at t=" << t
		<< " in " << caller
		<< " for " << identifier
		<< " |" << id_submodel_name;
asset_detail_pv_output();

return;
}



#line 1 "asset_detail_pv_output.MTG_ASSET.for"                                                                                   
void MTG_ASSET::asset_detail_pv_output()
{
if (asset_detail_rpt_pv_defn == YES)
	PVCFile << endl << PVCText.str() << endl;
else // "Summary to Run Log"
	log_screen << "PVSum: " << PVCText.str() << MSG_USER;

PVCText.str("");

return;
}



#line 1 "calc_num_records_to_run.MTG_ASSET.for"                                                                                   
int MTG_ASSET::calc_num_records_to_run(void)
{
xstring data_file_name = replaceWildcards(data_location());
string table_name = readCsvFile(data_file_name.getStdStr());
xstring sql = (xstring)"SELECT * FROM " + table_name;
executeQuery(sql.getStdStr(), mtg_mp_input_cols, mtg_mp_input);
closeDatabase();

if (!mtg_mp_input_cols.size())
	return 0;

int num_records_to_run = 0;
for (int row = 0; row < mtg_mp_input.size(); row++)
	{
	if (mtg_mp_input[row][3] == "Yes")
		num_records_to_run++;
	}

return num_records_to_run;
}



#line 1 "category_refinancing_rate.MTG_ASSET.for"                                                                                   
double MTG_ASSET::category_refinancing_rate(int t, int cal_yr, int cal_mth, int months_to_maturity, int return_rate_basis, int shift_defn, double years_from_payment_to_end_of_payment_month_passed)
{
double local_refinancing_rate = 0.0;

if (refinancing_rate_defn_calc == REFINANCING_RATE)
	local_refinancing_rate
	= max(rates->get_int_rate(t,
	            "Govt",
				GET_YIELD_RATE,
				refinancing_rate_scen_yr,
				0.0,
				NOMINAL_SEMIANNUAL, 
				shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		  * refinancing_rate_scen_mult
		  + refinancing_rate_scen_addn,
		  0.0);

if (refinancing_rate_defn_calc == CATEGORY_YIELD_TO_MATURITY)
	local_refinancing_rate
	= rates->get_int_rate(t,
	            category_id,
				GET_YIELD_RATE,
				months_to_maturity / 12.0
					- years_from_payment_to_end_of_payment_month_passed,
                0.0,
				NOMINAL_SEMIANNUAL, 
				shift_defn,portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

if (return_rate_basis != NOMINAL_SEMIANNUAL)
	local_refinancing_rate
	= convert_rate_basis(local_refinancing_rate, 
			  NOMINAL_SEMIANNUAL,
			  return_rate_basis);

return local_refinancing_rate;
}



#line 1 "create_state_of_world_schedule.MTG_ASSET.for"                                                                                   
xstring MTG_ASSET::create_state_of_world_schedule(xstring &sch_type, SmartArray <double> &sched_data)
{
ofstream& SCHEDFile = *new ofstream;

// create file name using asset_id, scenario_pass_num, commencement_period, and sched_type since must be unique
xstring sched_file_name
= "<*mtg_tables*>" + asset_id + "_sp" + xstring(proj_set_loop_num)
  + "_cp" + xstring(commencement_period) + "_" + sch_type + ".msv"; 

// create and write file
xstring file_name = replaceWildcards(sched_file_name);
xstring use_file_name = file_name.strip();
use_file_name.to_lower();

if (sch_type == "PPAY")
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
		full_sch_date = add_mths_to_date(proj_date_adj, commencement_period + i);
		sch_date = full_sch_date(0, 7); // stripping day off
	
		SCHEDFile << "<value row=\"" << sch_date << "\">" << sched_data[i] << "</value>" << endl;
		}
	
	SCHEDFile << "</column>" << endl;
	SCHEDFile << "</table>" << endl;
	}
else // sch_type == "BALLOON"
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

		full_sch_date = add_mths_to_date(proj_date_adj, commencement_period + i);
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



#line 1 "mths_to_next_pmt.MTG_ASSET.for"                                                                                   
int MTG_ASSET::mths_to_next_pmt(int t)
{
int local_pmt_mths = pmt_mths;

if (local_pmt_mths == 1)
	return 1;

return 1 + (maturity_period - t - 1) % local_pmt_mths;
}



#line 1 "mths_to_next_reset.MTG_ASSET.for"                                                                                   
int MTG_ASSET::mths_to_next_reset(int t)
{
if (intex_asset)
	return 0;

if (t < pmt_reset_first_period)
	return pmt_reset_first_period - t;

return adj_reset_mths
	   - (t - pmt_reset_first_period) % adj_reset_mths;
}



#line 1 "pmt_amt.MTG_ASSET.for"                                                                                   
double MTG_ASSET::pmt_amt(int t, double principal_value, int months_to_maturity, int pmt_freq, double int_rate, int amortzn_period)
{
if (pmt_freq == 0)
	return 0.0;

if (t < amortzn_period)
	return principal_value * int_rate / pmt_freq;

int num_of_months = 12 / pmt_freq;
int num_of_payments = 0;

if (num_of_months != 0)
	num_of_payments
	= (months_to_maturity + num_of_months - 1.0) / num_of_months;

double angle_n = 0;

if (int_rate > 0)
	angle_n
	= (1.0 - pow(1.0 / (1.0 + int_rate / pmt_freq),
				 (double) num_of_payments))
	  / (int_rate / pmt_freq);
else
	angle_n = (double) num_of_payments;

if (angle_n != 0)
	return principal_value / angle_n;

return 0;
}



#line 1 "read_sch_file.MTG_ASSET.for"                                                                                   
void MTG_ASSET::read_sch_file(void)
{
read_sch_file_flag = false; // This function should only be called once per model point

if (existing_asset_indicator == NEW_PURCH
	|| existing_asset_indicator == INIT_MP)
	return;

// existing_asset_indicator == PRIOR_PURCH
static bool first_time = true;

if (first_time)
	{
	first_time = false;

	// Create file_name
	xstring data_file_name = replaceWildcards(data_location());

	xstring sch_file = xstring(data_file_name(0, data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
					   + "_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv";

	string table_name = readCsvFile(sch_file.getStdStr());
	xstring sql = (xstring)"SELECT * FROM " + table_name;
	executeQuery(sql.getStdStr(), mtg_sch_input_cols, mtg_sch_input);
	closeDatabase();

	if (!mtg_sch_input_cols.size())
		throw FatalError("Could not read Mortgage Schedule File: " 
			              + sch_file + " "
			              + "Please check your data.");
	
	// Create map of mp start positions and mp input sizes
	mtg_sch_input_pos[xstring(mtg_sch_input[0][0])] = 0;
	int mp_first_row = 0;

	for (int row = 1; row < mtg_sch_input.size(); row++)
		{
		if (!eq(mtg_sch_input[row][0], mtg_sch_input[row - 1][0])) // Found a new MP
			{
			mtg_sch_input_pos[mtg_sch_input[row][0]] = row;
			mtg_sch_input_size[mtg_sch_input[row - 1][0]] = row - mp_first_row;
			mp_first_row = row;
			}

		if (row == mtg_sch_input.size() - 1)
			mtg_sch_input_size[mtg_sch_input[row][0]] = row - mp_first_row + 1;
		}
	}

int sch_start_row = 0;
if ((mtg_sch_input_pos_iter 
     = mtg_sch_input_pos.find(asset_id)) != mtg_sch_input_pos.end())
	sch_start_row = mtg_sch_input_pos_iter->second;

// Check to make sure schedule file starts with right date
xstring sch_start_date = mtg_sch_input[sch_start_row][1].c_str();
if (date_diff(get_string_of_date(date(start_period)), sch_start_date) != 0)
	throw FatalError("Mortgage Schedule File: start date for model point " 
		              + asset_id + " does not equal current projection start date. "
		              + "Please check your data.");

int sch_size = 0;
if ((mtg_sch_input_size_iter 
     = mtg_sch_input_size.find(asset_id)) != mtg_sch_input_size.end())
	sch_size = mtg_sch_input_size_iter->second;

bool prepmt_penalty_sch_flag = false;
if (prepmt_penalty_defn == PENALTY_PERCENT)
	prepmt_penalty_sch_flag = true;

bool balloon_sch_flag = false;
if (balloon_defn == YES_PER_SCHEDULE)
	balloon_sch_flag = true;

if (prepmt_penalty_sch_flag)
	{
	if (prepmt_penalty_sch.size() < sch_array_size)
		prepmt_penalty_sch.resize(sch_array_size);
	}

if (balloon_sch_flag)
	{
	if (balloon_sch.size() < sch_array_size)
		balloon_sch.resize(sch_array_size);
	}

double prepmt_penalty_pct = 0.0;
double balloon_prin_pmt_pct = 0.0;
int sch_row = sch_start_row;
xstring sch_date = sch_start_date;

for (int month = start_period; month <= maturity_period; month++)
	{
	xstring curr_date = get_string_of_date(date(month));

	// Read data only if it has changed
	if (date_diff(curr_date, sch_date) == 0 && sch_row < sch_size)
		{
		if (prepmt_penalty_sch_flag)
			prepmt_penalty_pct = atof(mtg_sch_input[sch_row][2].c_str());

		if (balloon_sch_flag)
			balloon_prin_pmt_pct = atof(mtg_sch_input[sch_row][3].c_str());
		
		sch_row++;
		if (sch_row < sch_size)
			sch_date = mtg_sch_input[sch_row][1].c_str();
		}

	if (prepmt_penalty_sch_flag)
		prepmt_penalty_sch[month - start_period] = prepmt_penalty_pct;

	if (balloon_sch_flag)
		balloon_sch[month - start_period] = balloon_prin_pmt_pct;
	}

return;
}



#line 1 "rebase_cash_flow.MTG_ASSET.for"                                                                                   
void MTG_ASSET::rebase_cash_flow(int t, int command, const xstring &caller, const xstring &model_name)
{
// Only shrink and grow for portfolio runs.
if (!isMainModel)
	{
	if (pv_model_point != getElementNumber()
		|| pv_asset_defn != MORTGAGE_CODE)
		{
		if (pv_asset_defn == MORTGAGE_CODE)
			shrink_mtg_clone(pv_model_point);
	
		else if (pv_asset_defn == BOND_CODE)
			{
			#ifdef __BOND_ASSET_H_
			if (asset->sm_bond.size() > 0)
				asset->sm_bond[0]->shrink_bond_clone(pv_model_point);
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
	
	pv_asset_defn = MORTGAGE_CODE;
	pv_model_point = getElementNumber();
	}

if (command == PRESENT_VALUE)
	{
	if (mtg_pv->isShrunk)
		mtg_pv->grow();

	mtg_pv->rebaseModel(t);
	if (mtg->asset_detail_pv_flag(t))
		asset_detail_log_rebase_reset(t,
				"mtg_pv->rebaseModel",
				caller, mtg->asset_id, model_name);
	}

else if (command == INTEREST_SAVINGS)
	{
	if (mtg_is->isShrunk)
		mtg_is->grow();

	mtg_is->rebaseModel(t);
	if (mtg->asset_detail_pv_flag(t))
		asset_detail_log_rebase_reset(t,
				"mtg_is->rebaseModel",
				caller, mtg->asset_id, model_name);
	}

else if (command == YIELD_MAINTENANCE)
	{
	if (mtg_ym->isShrunk)
		mtg_ym->grow();

	mtg_ym->rebaseModel(t);
	if (mtg->asset_detail_pv_flag(t))
		asset_detail_log_rebase_reset(t,
				"mtg_ym->rebaseModel",
				caller, mtg->asset_id, model_name);
	}

return;
}



#line 1 "setup_balloon_sch.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_balloon_sch()
{
if (existing_asset_indicator == PRIOR_PURCH 
	|| existing_asset_indicator == PROXY_BOND)
	{
	if (read_sch_file_flag)
		read_sch_file();

	return;
	}

if (balloon_sch.size() < sch_array_size)
	balloon_sch.resize(sch_array_size);

double cumul_future_pct = 0.0;

for (int month = start_period; month <= maturity_period; month++)
	{
	double balloon_pct = 0.0;
	if (existing_asset_indicator == INIT_MP)
		balloon_pct = balloon_prin_pmt_pct.AtTime(month);
	else // existing_asset_indicator == NEW_PURCH
		{
		company->sm_inv_strategy[seg_num]->mths_since_issue = month - start_period;
		balloon_pct = company->sm_inv_strategy[seg_num]->purch_mtg_balloon_prin_pmt_pct;
		}
		
	if (balloon_pct < 0.0 - rate_ratio_threshold)
		throw FatalError("Balloon mortgage, " + asset_id
                 + ", has negative future principal payment; Please correct balloon schedule input.");

	cumul_future_pct += balloon_pct;
	balloon_sch[month - start_period] = balloon_pct;
	}

if (cumul_future_pct < rate_ratio_threshold)
	throw FatalError("Balloon mortgage, " + asset_id
					 + ", principal payments add to 0%; Please correct balloon schedule input.");

// For new purchase, balloon schedule must add to 1. For existing model points, it does not have to.
// As long as it's not 0, balloon_sch_base column will normalize it.
if (existing_asset_indicator == NEW_PURCH 
	&& abs(cumul_future_pct - 1.0) > rate_ratio_threshold)
	throw FatalError("New purchase balloon mortgage, " + asset_id
					 + ", principal payments do not add to 100%; Please correct balloon schedule input.");

return;
}



#line 1 "setup_existing_asset.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_existing_asset(void)
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
	amortzn_start_cy = amortzn_start_cy_mp;
	planned_sale_date = planned_sale_date_mp;
	init_par_val = init_par_val_mp;
	init_cost_basis = init_cost_basis_mp;
	init_bk_val = init_bk_val_mp;
	init_mkt_val = init_mkt_val_mp;
	pmt_mode = pmt_mode_mp;
	init_pmt_rate = init_pmt_rate_mp;
	servicing_fee = servicing_fee_mp;
	prin_val_at_issue = prin_val_at_issue_mp;
	prepmt_opt_first_date = prepmt_opt_first_date_mp;
	prepmt_penalty_defn = prepmt_penalty_defn_mp;

	// Change selection to specified period 
	if (balloon_defn_mp == YES_ON_SINGLE_DATE)
		balloon_defn = YES_ON_SINGLE_PERIOD;
	else
		balloon_defn = balloon_defn_mp;

	balloon_date = balloon_date_mp;
	yld_maint_addn = yld_maint_addn_mp;
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

if (prepmt_penalty_defn == PENALTY_PERCENT)
	setup_prepmt_penalty_sch();

if (balloon_defn == YES_PER_SCHEDULE)
	setup_balloon_sch();

// adjust adj_reset_mths
int adj_reset_mths_input = adj_reset_mths;

if (adj_reset_mths <= 0)
	adj_reset_mths = pmt_mths;
else
	{
	int local_maturity_period = date_diff(maturity_date, proj_date_adj);

	if (local_maturity_period <= 0)
		adj_reset_mths = pmt_mths;
	else if (adj_reset_mths <= xint(xint(local_maturity_period / pmt_mths) * pmt_mths))
		adj_reset_mths
		= adj_reset_mths 
		  + (xint(xint(local_maturity_period / pmt_mths) * pmt_mths)
			 - adj_reset_mths) % pmt_mths;
	else
		adj_reset_mths
		= local_maturity_period;
	}

if (is_first_proj_task_loop
	&& !intex_proj_flag
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
		log_screen << "Warning. ARM Reset Months for at least one existing mortgage"
				   << " is incompatible with its payment frequency."
				   << MSG_ERROR;
		log_screen << " ... For example, ARM Reset Months (" << adj_reset_mths_input
				   << ") for existing mortgage '" << asset_id
				   << "' is incompatible with its"
				   << MSG_ERROR;
		log_screen << " ... payment frequency (" << pmt_mode
				   << ") and has been reset to " << adj_reset_mths
				   << "." << MSG_ERROR;
		}

	// issue warning if months to next reset date has been adjusted
	int mths_to_next_reset_prelim = 0;

	if (maturity_mths_from_next_reset <= 0)
		mths_to_next_reset_prelim = maturity_period;
	else if (maturity_mths_from_next_reset < maturity_period)
		mths_to_next_reset_prelim = maturity_period - maturity_mths_from_next_reset;
	else
		mths_to_next_reset_prelim
		= adj_reset_mths
		  - ((maturity_mths_from_next_reset - maturity_period) % adj_reset_mths);

	if (pmt_reset_first_period != mths_to_next_reset_prelim)
		{
		makeRunLogYellow();
		log_screen << "Warning. ARM Next Reset Date (" << adj_next_reset_date
				   << ") for existing mortgage '" << asset_id
				   << "' does not fall"
				   << MSG_ERROR;
		log_screen << " ... on a payment date and has been reset to "
				   << 1 + ((proj_start_mth + pmt_reset_first_period - 2) % 12)
				   << "/"
				   << proj_start_yr + xint((proj_start_mth + pmt_reset_first_period - 2) / 12)
				   << "." << MSG_ERROR;
		}
	} 

#if defined(__ADCO_ASSET_H_)
if (use_andrew_davidson)
	adco->initialize(0);
#endif

return;
}



#line 1 "setup_intex_submodel_parameters.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_intex_submodel_parameters(int t)
{
#if defined(__INTEX_ASSET_H_)
intex->is_intex_projection = 1;
intex->asset_defn = "MBS";
intex->asset_id = asset_id;
intex->category_id = category_id;
intex->balloon_extension = "No";
intex->proj_defn = "Experience";

// intex->bk_val_defn = bk_val_defn;
intex->bk_val_defn = "Cost Basis";

// intex->cost_basis_defn = cost_basis_defn;
intex->cost_basis_defn = "Amortized Cost";

intex->refinancing_cost_pct = refinancing_cost_pct;

// intex->refinancing_rate_defn = refinancing_rate_defn;
if (refinancing_rate_defn == REFINANCING_RATE)
	intex->refinancing_rate_defn = "Refinancing Rate";
else if (refinancing_rate_defn == CATEGORY_YIELD_TO_MATURITY)
	intex->refinancing_rate_defn = "Category Yield to Maturity";

intex->refinancing_rate_scen_yr = refinancing_rate_scen_yr;
intex->refinancing_rate_scen_mult = refinancing_rate_scen_mult;
intex->refinancing_rate_scen_addn = refinancing_rate_scen_addn;

//intex->prepmt_model_defn = prepmt_model_defn;
if (prepmt_model_defn == ANDREW_DAVIDSON)
	intex->prepmt_model_defn = "Andrew Davidson";
else // prepmt_model_defn == SPLINE
	intex->prepmt_model_defn = "Spline";


if (prepmt_model_defn == SPLINE)
	{
	// intex->prepmt_defn = prepmt_defn;
	if (prepmt_defn == ABSOLUTE_PERCENTAGE)
		intex->prepmt_defn = "Absolute Percentage";
	else // prepmt_defn == PERCENT_OF_PSA
		intex->prepmt_defn = "Percent of PSA";

	// intex->int_diff_defn = prepmt_int_diff_defn;
	if (prepmt_int_diff_defn == GROSS_INTEREST_RATE)
		intex->int_diff_defn = "Gross Interest Rate";
	else if (prepmt_int_diff_defn == INTEREST_RATE)
		intex->int_diff_defn = "Interest Rate";
	else // prepmt_int_diff_defn == NET_YIELD
		intex->int_diff_defn = "Net Yield";

	// Several arrays in intex submodel need to get values here. 
	// Use inputs in intex submodel to decide the size, lower and 
	// upper bound of arrays, then get values from mtg input variables.
	int int_rate_diff_array_size = intex->int_rate_diff_array_size;
	
	if (intex->prepmt_exercise_pct.size() < int_rate_diff_array_size + 1)
		intex->prepmt_exercise_pct.resize(int_rate_diff_array_size + 1);
	
	if (intex->prepmt_nonfinancial_adj.size() < int_rate_diff_array_size + 1)
		intex->prepmt_nonfinancial_adj.resize(int_rate_diff_array_size + 1);

	for (int i = 0; i <= int_rate_diff_array_size; i++)
		{
		int_rate_diff 
		= intex->int_rate_diff_min 
		  + double(i) / double(int_rate_diff_array_size)
		  * (intex->int_rate_diff_max - intex->int_rate_diff_min);

		nonfinancial_int_rate_diff = int_rate_diff;
			
		intex->prepmt_exercise_pct[i] = prepmt_exercise_pct_input; 
		intex->prepmt_nonfinancial_adj[i] = prepmt_nonfinancial_adj; 
		}

	intex->prepmt_nonfinancial_pct = prepmt_nonfinancial_pct;

	if (intex->prepmt_seasoning_since_issue_mult.size() < init_mths_since_issue + calculated_t_high + 1)
		intex->prepmt_seasoning_since_issue_mult.resize(init_mths_since_issue + calculated_t_high + 1);

	for (int i = 0; i <= calculated_t_high; i++)
		{
		int mths_since_issue_local = mths_since_issue(i);

		intex->prepmt_seasoning_since_issue_mult[mths_since_issue_local] = prepmt_seasoning_since_issue_mult.AtTime(i);
		}

	if (intex->prepmt_nonfinancial_seasonality_addn.size() < 13)
		intex->prepmt_nonfinancial_seasonality_addn.resize(13);

	for (int i = 1; i < 13; i++)
		{
		int cm = cal_mth(i);

		intex->prepmt_nonfinancial_seasonality_addn[cm] = prepmt_nonfinancial_seasonality_addn.AtTime(i);
		}
	}
else // ADCO prepayments
	intex->adco_category_id = adco_category_id;
#endif

return;
}



#line 1 "setup_prepmt_penalty_sch.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_prepmt_penalty_sch()
{
if (existing_asset_indicator == PRIOR_PURCH)
	{
	if (read_sch_file_flag)
		read_sch_file();

	return;
	}

if (prepmt_penalty_sch.size() < sch_array_size)
	prepmt_penalty_sch.resize(sch_array_size);
	
for (int month = start_period + 1; month <= maturity_period; month++)
	{
	if (existing_asset_indicator == INIT_MP) 
		prepmt_penalty_sch[month - start_period] = prepmt_penalty_pct.AtTime(month);
	else // existing_asset_indicator == NEW_PURCH
		{
		company->sm_inv_strategy[seg_num]->mths_since_issue = month - start_period;							
		prepmt_penalty_sch[month - start_period] = company->sm_inv_strategy[seg_num]->purch_mtg_prepmt_penalty_pct;
		}
	}
	
return;
}



#line 1 "setup_psa_base_rate.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_psa_base_rate()
{
psa_base_rate.resize(31);

psa_base_rate[0] = 0.0;

for (int month = 1; month <= 30; month++)
	psa_base_rate[month]
	= psa_base_rate[month - 1] + .002;

return;
}



#line 1 "setup_purch_inv_asset.MTG_ASSET.for"                                                                                   
void MTG_ASSET::setup_purch_inv_asset(int t, int save_assets, int panum, int new_mp_num, StrEnum::EnumValue investment_purpose, int inv_purchase_sub_port, double purch_asset_amt, int &asset_mp_sequence_num)
{
if (existing_asset_indicator)
	return;
	
initialize(t);

purch_asset_id = company->sm_inv_strategy[seg_num]->purch_assets_id[panum];
company->sm_inv_strategy[seg_num]->purch_asset_id = purch_asset_id;
asset_id = purch_asset_id;

// Get values from input table first in case they are used inside this function
category_id = company->sm_inv_strategy[seg_num]->purch_mtg_category_id;
portfolio_sprd_adj_aig = company->sm_inv_strategy[seg_num]->portfolio_sprd_adj_aig; //AIG - portfolio spread adjustment
dur_wtd_sprd_adj_aig = company->sm_inv_strategy[seg_num]->dur_wtd_sprd_adj_aig; //AIG - duration weighted spread adjustment
sale_class = company->sm_inv_strategy[seg_num]->purch_mtg_sale_class;
double ytm = company->sm_inv_strategy[seg_num]->purch_mtg_yrs_to_maturity;
double ytb = company->sm_inv_strategy[seg_num]->purch_mtg_yrs_to_balloon;
pmt_mode = company->sm_inv_strategy[seg_num]->purch_mtg_pmt_mode;
servicing_fee = company->sm_inv_strategy[seg_num]->purch_mtg_servicing_fee;
prepmt_penalty_defn = company->sm_inv_strategy[seg_num]->purch_mtg_prepmt_penalty_defn;
prepmt_protect_yrs = company->sm_inv_strategy[seg_num]->purch_mtg_prepmt_protect_yrs;
first_par_prepmt_yr = company->sm_inv_strategy[seg_num]->purch_mtg_first_par_prepmt_yr;
adj_addn_init = company->sm_inv_strategy[seg_num]->purch_mtg_adj_addn_init;
prepmt_penalty_mult = company->sm_inv_strategy[seg_num]->purch_mtg_prepmt_penalty_mult;
prepmt_penalty_addn = company->sm_inv_strategy[seg_num]->purch_mtg_prepmt_penalty_addn;
pmt_rate_defn_purch = xstring(company->sm_inv_strategy[seg_num]->purch_mtg_rate_defn);
balloon_defn = company->sm_inv_strategy[seg_num]->purch_mtg_balloon_defn;
adj_reset_scen_mult = company->sm_inv_strategy[seg_num]->purch_mtg_adj_scen_mult;
adj_reset_category_id = company->sm_inv_strategy[seg_num]->purch_mtg_adj_category_id;
adj_reset_scen_yr = company->sm_inv_strategy[seg_num]->purch_mtg_adj_scen_yr;
avr_contribn_pct = company->sm_inv_strategy[seg_num]->purch_mtg_avr_contribn_pct;
avr_max_pct = company->sm_inv_strategy[seg_num]->purch_mtg_avr_max_pct;
avr_obj_pct = company->sm_inv_strategy[seg_num]->purch_mtg_avr_obj_pct;
rbc_c1_pct = company->sm_inv_strategy[seg_num]->purch_mtg_rbc_c1_pct;
yld_maint_addn = company->sm_inv_strategy[seg_num]->purch_mtg_yld_maint_addn;

// Set up aset model point sequence number and model point group
if (save_assets == YES)
	{
	sequence_id = asset_mp_sequence_num + 1;
	asset_mp_sequence_num = asset_mp_sequence_num + 1;

	xstring asset_mp_group_tag
	= asset->set_mp_grp(t,
	                    new_mp_num, seg_id,
	                    company->sm_inv_strategy[seg_num]->purch_assets_mp_grp_tag[panum],
	                    purch_asset_id,
	                    sequence_id,
	                    company->sm_inv_strategy[seg_num]->inv_purch_timing);
	
	setGroup(asset_mp_group_tag);
	}
else
	sequence_id = 0;

if (investment_purpose == FORECLOSURE)
	purch_defn = FORECLOSURE;
else if (investment_purpose == RESTRUCTURE)
	purch_defn = RESTRUCTURE;
else if (investment_purpose == REFINANCE)
	purch_defn = REFINANCE;
else
	purch_defn = company->sm_inv_strategy[seg_num]->purch_mtg_port_defn;

purch_amt = purch_asset_amt;
purch_asset_sub_port = company->sm_inv_strategy[seg_num]->purch_assets_asset_sub_port_num[panum];

// Read the variables varying by asset category
ms_rereadGrid();

if (company->sm_inv_strategy[seg_num]->purch_assets_port_defn[panum] == INVESTMENT)
	port_defn = INVESTMENT;

issue_date = add_mths_to_date(proj_date_adj, commencement_period);

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

// Setup amortization start yr
add_mths = t + min(MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS,
                   company->sm_inv_strategy[seg_num]->purch_mtg_amortzn_yrs)* 12;

amortzn_start_cy = get_yr_from_date(add_mths_to_date(proj_date_adj, add_mths));

if ((double)(int)(12 * prepmt_protect_yrs) == (12 * prepmt_protect_yrs))
	add_mths
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
else
	add_mths
	= commencement_period
	  + min(prepmt_protect_yrs,
			MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;
			
if (prepmt_penalty_defn == PENALTY_PERCENT)
	add_mths = max(add_mths, commencement_period);

if (prepmt_protect_yrs >= 999)
	prepmt_opt_first_date = xstring("9999/01/01"); 
else	
	prepmt_opt_first_date = add_mths_to_date(proj_date_adj, add_mths);

if (prepmt_penalty_defn == PENALTY_PERCENT)
	setup_prepmt_penalty_sch();

if (((double)((int)(12 * ytb))) == (12 * ytb))
	add_mths
	= commencement_period
	  + min(ytb, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
else
	add_mths
	= commencement_period
	  + min(ytb, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;

balloon_date = add_mths_to_date(proj_date_adj, add_mths);

if (balloon_defn == YES_PER_SCHEDULE)
	setup_balloon_sch();

// Adjustable rate variables
if (pmt_rate_defn == FLOATING_RATE)
	{
	int adj_reset_mths_input = company->sm_inv_strategy[seg_num]->purch_mtg_adj_reset_mths;

	if (adj_reset_mths_input <= 0)
		adj_reset_mths = pmt_mths;
	else if (adj_reset_mths_input < maturity_period - commencement_period)
		adj_reset_mths
		= adj_reset_mths_input
			   + (xint((maturity_period - commencement_period) / pmt_mths)
				  * pmt_mths - adj_reset_mths_input) % pmt_mths;
	else
		adj_reset_mths
		= maturity_period - commencement_period;

	// issue warning if ARM reset months has been adjusted
	if (is_first_proj_task_loop
		&& pmt_rate_defn == FLOATING_RATE
		&& pmt_reset_first_period < maturity_period)
		{
		static bool issue_adj_reset_mths_warning = true;

		if (issue_adj_reset_mths_warning
			&& adj_reset_mths != adj_reset_mths_input
			&& (pmt_reset_first_period + adj_reset_mths) < maturity_period)
			{
			issue_adj_reset_mths_warning = false;
			makeRunLogYellow();
			log_screen << "Warning: adjustable rate reset months for at least one investment mortgage"
					<< " is incompatible with its payment frequency."
					<< MSG_ERROR;
			log_screen << " ... For example, adjustable rate reset months (" << adj_reset_mths_input
					<< ") for investment mortgage '" << asset_id
					<< "' is incompatible with its"
					<< MSG_ERROR;
			log_screen << " ... payment frequency (" << pmt_mode
					<< ") and has been reset to " << adj_reset_mths
					<< "." << MSG_ERROR;
			}
		}

	adj_next_reset_date = add_mths_to_date(proj_date_adj, pmt_reset_first_period); //20240806 WTW bug fix
	adj_reset_renewal_addn = company->sm_inv_strategy[seg_num]->purch_mtg_adj_addn_renewal;

	// Setup adj_max_rate
	double mortgage_interest_rate = pmt_rate_at_issue + servicing_fee;
	
	adj_max_rate
	= mortgage_interest_rate
	  + company->sm_inv_strategy[seg_num]->purch_mtg_adj_max_above_init;

	adj_max_decr_per_reset = company->sm_inv_strategy[seg_num]->purch_mtg_adj_max_reset_decr;
	adj_max_incr_per_reset = company->sm_inv_strategy[seg_num]->purch_mtg_adj_max_reset_incr;
	
	adj_min_rate
	= mortgage_interest_rate
	  - company->sm_inv_strategy[seg_num]->purch_mtg_adj_max_below_init;
	}

init_pmt_rate = pmt_rate_at_issue;

#if defined(__ADCO_ASSET_H_)
if (use_andrew_davidson)
	adco->initialize(0);
#endif

// Setup prin_val_at_issue
prin_val_at_issue = par_val_at_issue;

return;
}



#line 1 "shrink_mtg_clone.MTG_ASSET.for"                                                                                   
void MTG_ASSET::shrink_mtg_clone(int mp)
{
// Only shrink clones for portfolio runs.
if (isMainModel)
	return;

if (mp >= 0)
	{
	if (mp < asset->sm_mtg.size())
		{
		MTG_ASSET *prior_mtg_element = asset->sm_mtg[mp];

		if(!prior_mtg_element->mtg_pv->isShrunk)
			prior_mtg_element->mtg_pv->shrink();
		if(!prior_mtg_element->mtg_is->isShrunk)
			prior_mtg_element->mtg_is->shrink();
		if(!prior_mtg_element->mtg_ym->isShrunk)
			prior_mtg_element->mtg_ym->shrink();
		}
	else
		// this should never occur
		throw FatalError("mp (" + xstring(mp)
						 + ") >= mtg.size (" + xstring(asset->sm_mtg.size())
						 + " in mtg->shrink_mtg_clone.");
	}

return;
}



#line 1 "validate_data.MTG_ASSET.for"                                                                                   
void MTG_ASSET::validate_data(void) 
{
if (!cloning_wanted)
	throw FatalError("You must select 'Yes' for the 'Cloning Wanted' projection task property "
	                 "in order to include mortgages in the projection.");

if (existing_asset_indicator)
	{
	if (maturity_period > 0)
		{
		t_low = calculated_t_low = xint(commencement_period);
		t_high = calculated_t_high = xint(maturity_period);

		// check t_low, t_high
		if (!isMainModel)
			{
			if (!asset->valid_t_low_t_high(calculated_t_low, calculated_t_high))
				{
				skipModelPoint();
				return;
				}
			}

		return;
		}

	// else maturity_period <= 0 so add par value to cash account
	if (!isMainModel)
		{
		xstring index_val = seg_id + "_mtg" + asset_id + data_grp_id + xstring(data_rec_num());
	
		if ((asset->init_cash_bal_map_iter
				= asset->init_cash_bal_map.find(index_val))
			== asset->init_cash_bal_map.end())
			{
			if (data_validation_defn == YES)
				makeRunLogYellow();
				
			log_screen.setf(ios::fixed, ios::floatfield);
	
			if (init_par_val == 0 && data_validation_defn == YES)
				log_screen << "Warning: Existing mortgage has no value."
							<< " Asset has been discarded."
							<< " Id= " << asset_id
							<< MSG_USER;
			else
				{
				if (data_validation_defn == YES)
					log_screen << "Warning: Existing mtg " << asset_id
								<< " has matured before model start date."
								<< " Asset par value (" << setprecision(2) << init_par_val
								<< ") has been added to the cash account."
								<< MSG_ERROR;
	
				asset->init_cash_bal_map[index_val] = init_par_val;
				}
	
			skipModelPoint();
			return;
			}
		}
	}

return;
}



#line 1 "write_sch_file.MTG_ASSET.for"                                                                                   
void MTG_ASSET::write_sch_file(xstring sch_file)
{
// Initial mortgage will get values from external source data, no need to write csv schedule file
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
if (!mtg_sch_output.is_open())
	{
	mtg_sch_output.open(sch_file);
	mtg_sch_output.setf(ios::fixed);
	mtg_sch_output.precision(12);

	// Write header
	mtg_sch_output 
	<< "asset_id" << ","				// col 0 = asset_id
	<< "date" << ","					// col 1 = date
	<< "prepmt_penalty_pct" << ","	    // col 2 = prepmt_penalty_pct
	<< "balloon_prin_pmt_pct" << endl;  // col 3 = balloon_prin_pmt_pct
	}

bool prepmt_penalty_sch_flag = false;
if (prepmt_penalty_defn == PENALTY_PERCENT || prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE)
	prepmt_penalty_sch_flag = true;

bool balloon_sch_flag = false;
if (balloon_defn == YES_PER_SCHEDULE)
	balloon_sch_flag = true;

if (prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE)
	{
	// fill schedule array so same process is used to create new schedule file
	if (prepmt_penalty_sch.size() < sch_array_size)
		prepmt_penalty_sch.resize(sch_array_size);

	for (int month = 1; month <= maturity_period - start_period; month++)
		{
		double prepmt_penalty_pct = 0.0;
		if (month <= prepmt_par_first_period - start_period)
			prepmt_penalty_pct
			= prepmt_penalty_related_to_pmt_rate
			  * (prepmt_par_first_period - start_period - month)
			  / prepmt_penalty_grading_mths;

		prepmt_penalty_sch[month] = prepmt_penalty_pct;
		}
	}

double curr_prepmt_penalty_pct = 0.0;
double curr_balloon_prin_pmt_pct = 0.0;
double prev_prepmt_penalty_pct = 0.0;
double prev_balloon_prin_pmt_pct = 0.0;
bool new_data_flag = true;

for (int month = last_proj_period; month <= maturity_period; month++)
	{
	xstring curr_date = get_string_of_date(date(month));

	if (prepmt_penalty_sch_flag)
		{
		curr_prepmt_penalty_pct = prepmt_penalty_sch[month - start_period];
		if (abs(curr_prepmt_penalty_pct - prev_prepmt_penalty_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_prepmt_penalty_pct = curr_prepmt_penalty_pct;
		}

	if (balloon_sch_flag)
		{
		curr_balloon_prin_pmt_pct = balloon_sch[month - start_period];
		if (curr_balloon_prin_pmt_pct > rate_ratio_threshold
			|| abs(curr_balloon_prin_pmt_pct - prev_balloon_prin_pmt_pct) > rate_ratio_threshold)
			new_data_flag = true;

		prev_balloon_prin_pmt_pct = curr_balloon_prin_pmt_pct;
		}

	// Only write out if data changed except the first record
	if (new_data_flag)
		mtg_sch_output
		<< asset_id << ","
		<< curr_date << ","
		<< curr_prepmt_penalty_pct << ","
		<< curr_balloon_prin_pmt_pct << endl;

	// By updating this flag at end instead of beginning of loop,
	// We make sure the first record always gets written
	new_data_flag = false;
	}

return;
}



#line 1 "write_state_of_world_mp.MTG_ASSET.for"                                                                                   
void MTG_ASSET::write_state_of_world_mp(void)
{
static bool first_time = true;

xstring data_file_name = replaceWildcards(data_location());

xstring mtg_state_of_world_file
= xstring(data_file_name(0, data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

xstring sch_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_sch_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (first_time)
	{
	first_time = false;

	struct stat buffer;
	int stat_val = stat(mtg_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(mtg_state_of_world_file);
	}
 
if (!mtg_state_of_world_mp_output.is_open())
	{
   	mtg_state_of_world_mp_output.setf(ios::fixed);
	mtg_state_of_world_mp_output.precision(12);
	mtg_state_of_world_mp_output.open(mtg_state_of_world_file);

	// Write header
	mtg_state_of_world_mp_output			// Values from inforce mp
	<< "group" << ","						// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","					// col 1 = seg_id
	<< "asset_id_mp" << ","					// col 2 = asset_id
	<< "use_mp" << ","						// col 3 = use_mp
	<< "category_id_mp" << ","				// col 4 = category_id
	<< "port_defn_mp" << ","				// col 5 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","				// col 6 = get_string_of_enum_val(sale_class)
	<< "issue_date_mp" << ","				// col 7 = issue_date
	<< "maturity_date_mp" << ","			// col 8 = maturity_date
	<< "amortzn_start_cy_mp" << ","			// col 9 = amortzn_start_cy
	<< "planned_sale_date_mp" << ","		// col 10 = planned_sale_date
	<< "init_par_val_mp" << ","				// col 11 = notional_amt(last_proj_period)
	<< "init_cost_basis_mp" << ","			// col 12 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","				// col 13 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","				// col 14 = mkt_val(last_proj_period)
	<< "pmt_mode_mp" << ","					// col 15 = get_string_of_enum_val(pmt_mode)
	<< "init_pmt_rate_mp" << ","			// col 16 = sm_mtg_cf->pmt_rate(last_proj_period)
	<< "servicing_fee_mp" << ","			// col 17 = servicing_fee
	<< "prin_val_at_issue_mp" << ","		// col 18 = prin_val_at_issue
	<< "prepmt_opt_first_date_mp" << ","	// col 19 = prepmt_opt_first_date
	<< "prepmt_penalty_defn_mp" << ","		// col 20 = get_string_of_enum_val(prepmt_penalty_defn)
	<< "balloon_defn_mp" << ","				// col 21 = balloon_pmt_defn
	<< "balloon_date_mp" << ","				// col 22 = balloon_date
	<< "yld_maint_addn_mp" << ","			// col 23 = yld_maint_addn
	<< "adj_reset_category_id_mp" << ","    // col 24 = adj_reset_category_id
	<< "adj_reset_scen_yr_mp" << ","		// col 25 = adj_reset_scen_yr
	<< "adj_reset_scen_mult_mp" << ","		// col 26 = adj_reset_scen_mult
	<< "adj_reset_renewal_addn_mp" << ","	// col 27 = adj_reset_renewal_addn
	<< "adj_next_reset_date_mp" << ","		// col 28 = adj_next_reset_date
	<< "adj_reset_mths_mp" << ","			// col 29 = adj_reset_mths
	<< "adj_max_incr_per_reset_mp" << ","	// col 30 = adj_max_incr_per_reset
	<< "adj_max_decr_per_reset_mp" << ","	// col 31 = adj_max_decr_per_reset
	<< "adj_min_rate_mp" << ","				// col 32 = adj_min_rate
	<< "adj_max_rate_mp" << ","				// col 33 = adj_max_rate
	<< "avr_contribn_pct_mp" << ","			// col 34 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","				// col 35 = avr_max_pct
	<< "avr_obj_pct_mp" << ","				// col 36 = avr_obj_pct
	<< "rbc_c1_pct_mp" << ","				// col 37 = rbc_c1_pct
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
double pmt_rate = sm_mtg_cf->pmt_rate(last_proj_period);

xstring prepmt_penalty_defn = "";
if (this->prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE)
	prepmt_penalty_defn = "Penalty Percent";
else
	prepmt_penalty_defn = get_string_of_enum_val(this->prepmt_penalty_defn);

xstring balloon_defn = "";
if (this->balloon_defn == YES_ON_SINGLE_PERIOD)
	balloon_defn = "Yes On Single Date";
else
	balloon_defn = get_string_of_enum_val(this->balloon_defn);

mtg_state_of_world_mp_output
<< group_mp << ","
<< seg_id << ","
<< asset_id << ","
<< use_mp << ","
<< category_id << ","
<< port_defn << ","
<< sale_class << ","
<< issue_date << ","
<< maturity_date << ","
<< amortzn_start_cy << ","
<< planned_sale_date << ","
<< notional_amt << ","
<< cost_basis << ","
<< bk_val << ","
<< mkt_val << ","
<< pmt_mode << ","
<< pmt_rate << ","
<< servicing_fee << ","
<< prin_val_at_issue << ","
<< prepmt_opt_first_date << ","
<< prepmt_penalty_defn << ","
<< balloon_defn << ","
<< balloon_date << ","
<< yld_maint_addn << ","
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
<< dur_wtd_sprd_adj_aig << endl; //08/12/2024

counter++;

if (write_sch_file_flag)
	write_sch_file(sch_file);

return;
}



void MTG_ASSET::Terminator()
{

if (PVCFile != NULL)
	PVCFile.close();

}

FunctionPtr MTG_ASSET::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static MTG_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (MTG_ASSET_UDF::*dPXi) (int);
typedef double (MTG_ASSET_UDF::*dPXid) (int, double);
typedef double (MTG_ASSET_UDF::*dPF) ();
typedef double (MTG_ASSET_UDF::*dPFd) (double);
typedef int (MTG_ASSET_UDF::*iPF) ();
typedef int (MTG_ASSET_UDF::*iPFi) (int);
typedef xstring (MTG_ASSET_UDF::*sPF) ();
typedef xstring (MTG_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData MTG_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_inc", "mtg_asset_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(2, "accr_int", "mtg_asset_accr_int",  "accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int),
	CashFlowCommonData(3, "accr_int_aft_dflt", "mtg_asset_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(4, "accr_int_aft_prepmt", "mtg_asset_accr_int_aft_prepmt",  "accr_int_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_aft_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_prepmt),
	CashFlowCommonData(5, "accr_int_bef_fund_match_sale", "mtg_asset_accr_int_bef_fund_match_sale",  "accr_int_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_fund_match_sale),
	CashFlowCommonData(6, "accr_int_bef_neg_cash_flow_sale", "mtg_asset_accr_int_bef_neg_cash_flow_sale",  "accr_int_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_neg_cash_flow_sale),
	CashFlowCommonData(7, "accr_int_bef_prepmt", "mtg_asset_accr_int_bef_prepmt",  "accr_int_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_bef_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_prepmt),
	CashFlowCommonData(8, "accr_int_bef_rebal_sale", "mtg_asset_accr_int_bef_rebal_sale",  "accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_rebal_sale),
	CashFlowCommonData(9, "accr_int_bef_sale", "mtg_asset_accr_int_bef_sale",  "accr_int_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_bef_sale),
	CashFlowCommonData(10, "accr_int_dflt", "mtg_asset_accr_int_dflt",  "accr_int_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_dflt),
	CashFlowCommonData(11, "accr_int_purch", "mtg_asset_accr_int_purch",  "accr_int_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_int_purch),
	CashFlowCommonData(12, "accr_int_rent", "mtg_asset_accr_int_rent",  "accr_int_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_rent, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_rent),
	CashFlowCommonData(13, "accr_int_sold", "mtg_asset_accr_int_sold",  "accr_int_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_accr_int_sold, 'E','Y', '3', 'P', (size_t)&modelOffset->accr_int_sold),
	CashFlowCommonData(14, "asset_detail_pv_flag", "mtg_asset_asset_detail_pv_flag",  "asset_detail_pv_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_asset_detail_pv_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_detail_pv_flag),
	CashFlowCommonData(15, "asset_min_size_sale_flag", "mtg_asset_asset_min_size_sale_flag",  "asset_min_size_sale_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_asset_min_size_sale_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_min_size_sale_flag),
	CashFlowCommonData(16, "avr_basic_contribn", "mtg_asset_avr_basic_contribn",  "avr_basic_contribn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_basic_contribn, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_basic_contribn),
	CashFlowCommonData(17, "avr_basic_contribn_bef_sale", "mtg_asset_avr_basic_contribn_bef_sale",  "avr_basic_contribn_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_basic_contribn_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_basic_contribn_bef_sale),
	CashFlowCommonData(18, "avr_max", "mtg_asset_avr_max",  "avr_max",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_max, 'E','N', '3', 'C', (size_t)&modelOffset->avr_max),
	CashFlowCommonData(19, "avr_max_bef_sale", "mtg_asset_avr_max_bef_sale",  "avr_max_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_max_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->avr_max_bef_sale),
	CashFlowCommonData(20, "avr_obj", "mtg_asset_avr_obj",  "avr_obj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_obj, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj),
	CashFlowCommonData(21, "avr_obj_bef_sale", "mtg_asset_avr_obj_bef_sale",  "avr_obj_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_obj_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj_bef_sale),
	CashFlowCommonData(22, "avr_realzd_cap_gain", "mtg_asset_avr_realzd_cap_gain",  "avr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_avr_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_realzd_cap_gain),
	CashFlowCommonData(23, "balloon_sch_base", "mtg_asset_balloon_sch_base",  "balloon_sch_base",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_balloon_sch_base, 'E','N', '3', 'C', (size_t)&modelOffset->balloon_sch_base),
	CashFlowCommonData(24, "base_inc_bef_prepmt", "mtg_asset_base_inc_bef_prepmt",  "base_inc_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_base_inc_bef_prepmt, 'E','Y', '3', 'C', (size_t)&modelOffset->base_inc_bef_prepmt),
	CashFlowCommonData(25, "bk_val", "mtg_asset_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(26, "bk_val_aft_dflt", "mtg_asset_bk_val_aft_dflt",  "bk_val_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_aft_dflt),
	CashFlowCommonData(27, "bk_val_aft_prepmt", "mtg_asset_bk_val_aft_prepmt",  "bk_val_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_aft_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_aft_prepmt),
	CashFlowCommonData(28, "bk_val_bef_fund_match_sale", "mtg_asset_bk_val_bef_fund_match_sale",  "bk_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_fund_match_sale),
	CashFlowCommonData(29, "bk_val_bef_neg_cash_flow_sale", "mtg_asset_bk_val_bef_neg_cash_flow_sale",  "bk_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(30, "bk_val_bef_prepmt", "mtg_asset_bk_val_bef_prepmt",  "bk_val_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_bef_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_prepmt),
	CashFlowCommonData(31, "bk_val_bef_rebal_sale", "mtg_asset_bk_val_bef_rebal_sale",  "bk_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_rebal_sale),
	CashFlowCommonData(32, "bk_val_bef_sale", "mtg_asset_bk_val_bef_sale",  "bk_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_bef_sale),
	CashFlowCommonData(33, "bk_val_plus_accr_int_bef_rebal_sale", "mtg_asset_bk_val_plus_accr_int_bef_rebal_sale",  "bk_val_plus_accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_plus_accr_int_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int_bef_rebal_sale),
	CashFlowCommonData(34, "bk_val_purch", "mtg_asset_bk_val_purch",  "bk_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_bk_val_purch, 'E','Y', '3', 'P', (size_t)&modelOffset->bk_val_purch),
	CashFlowCommonData(35, "cal_mth", "mtg_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(36, "cal_yr", "mtg_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(37, "cal_yr_relative", "mtg_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(38, "cap_gain_adj_foreclosure_prin_pmt", "mtg_asset_cap_gain_adj_foreclosure_prin_pmt",  "cap_gain_adj_foreclosure_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cap_gain_adj_foreclosure_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_adj_foreclosure_prin_pmt),
	CashFlowCommonData(39, "cap_gain_adj_restructure_prin_pmt", "mtg_asset_cap_gain_adj_restructure_prin_pmt",  "cap_gain_adj_restructure_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cap_gain_adj_restructure_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_adj_restructure_prin_pmt),
	CashFlowCommonData(40, "cap_gain_bef_sale", "mtg_asset_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(41, "cap_gain_from_sale", "mtg_asset_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cap_gain_from_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(42, "cash_flow", "mtg_asset_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cash_flow, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(43, "cost_basis", "mtg_asset_cost_basis",  "cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis),
	CashFlowCommonData(44, "cost_basis_accrual", "mtg_asset_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_accrual, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(45, "cost_basis_aft_dflt", "mtg_asset_cost_basis_aft_dflt",  "cost_basis_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_aft_dflt),
	CashFlowCommonData(46, "cost_basis_aft_prepmt", "mtg_asset_cost_basis_aft_prepmt",  "cost_basis_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_aft_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_aft_prepmt),
	CashFlowCommonData(47, "cost_basis_bef_prepmt", "mtg_asset_cost_basis_bef_prepmt",  "cost_basis_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_bef_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_bef_prepmt),
	CashFlowCommonData(48, "cost_basis_bef_sale", "mtg_asset_cost_basis_bef_sale",  "cost_basis_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis_bef_sale),
	CashFlowCommonData(49, "cost_basis_dflt", "mtg_asset_cost_basis_dflt",  "cost_basis_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_dflt),
	CashFlowCommonData(50, "cost_basis_incr_appreciation", "mtg_asset_cost_basis_incr_appreciation",  "cost_basis_incr_appreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_incr_appreciation, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_incr_appreciation),
	CashFlowCommonData(51, "cost_basis_purch", "mtg_asset_cost_basis_purch",  "cost_basis_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_purch, 'E','Y', '3', 'P', (size_t)&modelOffset->cost_basis_purch),
	CashFlowCommonData(52, "cost_basis_sched_prin_pmt", "mtg_asset_cost_basis_sched_prin_pmt",  "cost_basis_sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_sched_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_sched_prin_pmt),
	CashFlowCommonData(53, "cost_basis_sold", "mtg_asset_cost_basis_sold",  "cost_basis_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_cost_basis_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_sold),
	CashFlowCommonData(54, "date", "mtg_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(55, "decr_pct", "mtg_asset_decr_pct",  "decr_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_decr_pct, 'E','N', '3', 'C', (size_t)&modelOffset->decr_pct),
	CashFlowCommonData(56, "decr_rate", "mtg_asset_decr_rate",  "decr_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_decr_rate, 'E','N', '3', 'C', (size_t)&modelOffset->decr_rate),
	CashFlowCommonData(57, "dflt_amt", "mtg_asset_dflt_amt",  "dflt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_dflt_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->dflt_amt),
	CashFlowCommonData(58, "dflt_pct", "mtg_asset_dflt_pct",  "dflt_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_dflt_pct, 'E','N', '3', 'C', (size_t)&modelOffset->dflt_pct),
	CashFlowCommonData(59, "dflt_rate", "mtg_asset_dflt_rate",  "dflt_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_dflt_rate, 'E','N', '3', 'P', (size_t)&modelOffset->dflt_rate),
	CashFlowCommonData(60, "dur_val", "mtg_asset_dur_val",  "dur_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_dur_val, 'E','N', '3', 'C', (size_t)&modelOffset->dur_val),
	CashFlowCommonData(61, "eff_dur", "mtg_asset_eff_dur",  "eff_dur",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->eff_dur),
	CashFlowCommonData(62, "finalize", "mtg_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(63, "foreclosure_accr_int_net_write_down", "mtg_asset_foreclosure_accr_int_net_write_down",  "foreclosure_accr_int_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_accr_int_net_write_down, 'E','Y', '3', 'C', (size_t)&modelOffset->foreclosure_accr_int_net_write_down),
	CashFlowCommonData(64, "foreclosure_bk_val_net_write_down", "mtg_asset_foreclosure_bk_val_net_write_down",  "foreclosure_bk_val_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_bk_val_net_write_down, 'E','Y', '3', 'C', (size_t)&modelOffset->foreclosure_bk_val_net_write_down),
	CashFlowCommonData(65, "foreclosure_cost_basis_net_write_down", "mtg_asset_foreclosure_cost_basis_net_write_down",  "foreclosure_cost_basis_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_cost_basis_net_write_down, 'E','Y', '3', 'C', (size_t)&modelOffset->foreclosure_cost_basis_net_write_down),
	CashFlowCommonData(66, "foreclosure_pct", "mtg_asset_foreclosure_pct",  "foreclosure_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_pct, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_pct),
	CashFlowCommonData(67, "foreclosure_prin_net_write_down", "mtg_asset_foreclosure_prin_net_write_down",  "foreclosure_prin_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_prin_net_write_down, 'E','Y', '3', 'C', (size_t)&modelOffset->foreclosure_prin_net_write_down),
	CashFlowCommonData(68, "foreclosure_rate", "mtg_asset_foreclosure_rate",  "foreclosure_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_foreclosure_rate, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_rate),
	CashFlowCommonData(69, "gaap_inc_bk_val", "mtg_asset_gaap_inc_bk_val",  "gaap_inc_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_gaap_inc_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bk_val),
	CashFlowCommonData(70, "gaap_inc_unrealzd_cap_gain", "mtg_asset_gaap_inc_unrealzd_cap_gain",  "gaap_inc_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_gaap_inc_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain),
	CashFlowCommonData(71, "gaap_surp_bk_val", "mtg_asset_gaap_surp_bk_val",  "gaap_surp_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_gaap_surp_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_surp_bk_val),
	CashFlowCommonData(72, "gaap_unrealzd_cap_gain_incr", "mtg_asset_gaap_unrealzd_cap_gain_incr",  "gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(73, "imr_realzd_cap_gain", "mtg_asset_imr_realzd_cap_gain",  "imr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain),
	CashFlowCommonData(74, "imr_realzd_cap_gain_from_sale", "mtg_asset_imr_realzd_cap_gain_from_sale",  "imr_realzd_cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain_from_sale),
	CashFlowCommonData(75, "imr_realzd_cap_gain_rml", "mtg_asset_imr_realzd_cap_gain_rml",  "imr_realzd_cap_gain_rml",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_rml, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain_rml),
	CashFlowCommonData(76, "imr_realzd_cap_gain_rml_from_sale", "mtg_asset_imr_realzd_cap_gain_rml_from_sale",  "imr_realzd_cap_gain_rml_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_imr_realzd_cap_gain_rml_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain_rml_from_sale),
	CashFlowCommonData(77, "imr_yrs_to_maturity", "mtg_asset_imr_yrs_to_maturity",  "imr_yrs_to_maturity",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_imr_yrs_to_maturity, 'E','N', '3', 'C', (size_t)&modelOffset->imr_yrs_to_maturity),
	CashFlowCommonData(78, "initialize", "mtg_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(79, "int_div_and_rent", "mtg_asset_int_div_and_rent",  "int_div_and_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_int_div_and_rent, 'E','Y', '3', 'P', (size_t)&modelOffset->int_div_and_rent),
	CashFlowCommonData(80, "int_pmt", "mtg_asset_int_pmt",  "int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_int_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->int_pmt),
	CashFlowCommonData(81, "intex_accr_int_adj", "mtg_asset_intex_accr_int_adj",  "intex_accr_int_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_intex_accr_int_adj, 'E','N', '3', 'P', (size_t)&modelOffset->intex_accr_int_adj),
	CashFlowCommonData(82, "intex_pct_remaining", "mtg_asset_intex_pct_remaining",  "intex_pct_remaining",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_intex_pct_remaining, 'E','N', '3', 'P', (size_t)&modelOffset->intex_pct_remaining),
	CashFlowCommonData(83, "intex_tgt", "mtg_asset_intex_tgt",  "intex_tgt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_intex_tgt, 'E','Y', '3', 'P', (size_t)&modelOffset->intex_tgt),
	CashFlowCommonData(84, "mkt_risk_sprd", "mtg_asset_mkt_risk_sprd",  "mkt_risk_sprd",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_risk_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_risk_sprd),
	CashFlowCommonData(85, "mkt_sprd", "mtg_asset_mkt_sprd",  "mkt_sprd",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_sprd, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_sprd),
	CashFlowCommonData(86, "mkt_to_bk_ratio", "mtg_asset_mkt_to_bk_ratio",  "mkt_to_bk_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_to_bk_ratio),
	CashFlowCommonData(87, "mkt_val", "mtg_asset_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(88, "mkt_val_bef_fund_match_sale", "mtg_asset_mkt_val_bef_fund_match_sale",  "mkt_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_bef_fund_match_sale),
	CashFlowCommonData(89, "mkt_val_bef_neg_cash_flow_sale", "mtg_asset_mkt_val_bef_neg_cash_flow_sale",  "mkt_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(90, "mkt_val_bef_rebal_sale", "mtg_asset_mkt_val_bef_rebal_sale",  "mkt_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_rebal_sale),
	CashFlowCommonData(91, "mkt_val_bef_sale", "mtg_asset_mkt_val_bef_sale",  "mkt_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_bef_sale),
	CashFlowCommonData(92, "mkt_val_for_dur_bef_neg_cash_flow_sale", "mtg_asset_mkt_val_for_dur_bef_neg_cash_flow_sale",  "mkt_val_for_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(93, "mkt_val_for_dur_bef_rebal_sale", "mtg_asset_mkt_val_for_dur_bef_rebal_sale",  "mkt_val_for_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_rebal_sale),
	CashFlowCommonData(94, "mkt_val_for_dur_sold", "mtg_asset_mkt_val_for_dur_sold",  "mkt_val_for_dur_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_for_dur_sold, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_sold),
	CashFlowCommonData(95, "mkt_val_for_eff_dur", "mtg_asset_mkt_val_for_eff_dur",  "mkt_val_for_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_for_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_eff_dur),
	CashFlowCommonData(96, "mkt_val_purch", "mtg_asset_mkt_val_purch",  "mkt_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_purch, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_purch),
	CashFlowCommonData(97, "mkt_val_shifted", "mtg_asset_mkt_val_shifted",  "mkt_val_shifted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_shifted, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_shifted),
	CashFlowCommonData(98, "mkt_val_sold", "mtg_asset_mkt_val_sold",  "mkt_val_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_sold),
	CashFlowCommonData(99, "mkt_val_times_dur_bef_neg_cash_flow_sale", "mtg_asset_mkt_val_times_dur_bef_neg_cash_flow_sale",  "mkt_val_times_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_times_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(100, "mkt_val_times_dur_bef_rebal_sale", "mtg_asset_mkt_val_times_dur_bef_rebal_sale",  "mkt_val_times_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_times_dur_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_rebal_sale),
	CashFlowCommonData(101, "mkt_val_times_eff_dur", "mtg_asset_mkt_val_times_eff_dur",  "mkt_val_times_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mkt_val_times_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_times_eff_dur),
	CashFlowCommonData(102, "mths_bef_maturity", "mtg_asset_mths_bef_maturity",  "mths_bef_maturity",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mths_bef_maturity, 'E','N', '3', 'P', (size_t)&modelOffset->mths_bef_maturity),
	CashFlowCommonData(103, "mths_since_issue", "mtg_asset_mths_since_issue",  "mths_since_issue",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mths_since_issue, 'E','N', '3', 'P', (size_t)&modelOffset->mths_since_issue),
	CashFlowCommonData(104, "mths_to_next_mkt_val_calc", "mtg_asset_mths_to_next_mkt_val_calc",  "mths_to_next_mkt_val_calc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_mths_to_next_mkt_val_calc, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_next_mkt_val_calc),
	CashFlowCommonData(105, "net_yld", "mtg_asset_net_yld",  "net_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_net_yld, 'E','N', '3', 'C', (size_t)&modelOffset->net_yld),
	CashFlowCommonData(106, "notional_amt", "mtg_asset_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_notional_amt, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(107, "notional_amt_bef_fund_match_sale", "mtg_asset_notional_amt_bef_fund_match_sale",  "notional_amt_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_notional_amt_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt_bef_fund_match_sale),
	CashFlowCommonData(108, "notional_amt_bef_neg_cash_flow_sale", "mtg_asset_notional_amt_bef_neg_cash_flow_sale",  "notional_amt_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_notional_amt_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_neg_cash_flow_sale),
	CashFlowCommonData(109, "notional_amt_bef_rebal_sale", "mtg_asset_notional_amt_bef_rebal_sale",  "notional_amt_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_notional_amt_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_rebal_sale),
	CashFlowCommonData(110, "notional_amt_bef_sale", "mtg_asset_notional_amt_bef_sale",  "notional_amt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_notional_amt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_sale),
	CashFlowCommonData(111, "opt_inc", "mtg_asset_opt_inc",  "opt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_opt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_inc),
	CashFlowCommonData(112, "opt_pmt", "mtg_asset_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(113, "rbc_c1", "mtg_asset_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(114, "rbc_c1_bef_sale", "mtg_asset_rbc_c1_bef_sale",  "rbc_c1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_rbc_c1_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_bef_sale),
	CashFlowCommonData(115, "realzd_cap_gain", "mtg_asset_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(116, "realzd_cap_gain_opt_pmt", "mtg_asset_realzd_cap_gain_opt_pmt",  "realzd_cap_gain_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_opt_pmt),
	CashFlowCommonData(117, "realzd_cap_gain_prepmt", "mtg_asset_realzd_cap_gain_prepmt",  "realzd_cap_gain_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_prepmt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_prepmt),
	CashFlowCommonData(118, "realzd_cap_gain_sale", "mtg_asset_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_gain_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(119, "realzd_cap_loss_dflt", "mtg_asset_realzd_cap_loss_dflt",  "realzd_cap_loss_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_loss_dflt),
	CashFlowCommonData(120, "realzd_cap_loss_foreclosure", "mtg_asset_realzd_cap_loss_foreclosure",  "realzd_cap_loss_foreclosure",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_foreclosure, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_loss_foreclosure),
	CashFlowCommonData(121, "realzd_cap_loss_restructure", "mtg_asset_realzd_cap_loss_restructure",  "realzd_cap_loss_restructure",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_realzd_cap_loss_restructure, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_loss_restructure),
	CashFlowCommonData(122, "refinance_accr_int", "mtg_asset_refinance_accr_int",  "refinance_accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_accr_int),
	CashFlowCommonData(123, "refinance_bk_val", "mtg_asset_refinance_bk_val",  "refinance_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_bk_val),
	CashFlowCommonData(124, "refinance_cost_basis", "mtg_asset_refinance_cost_basis",  "refinance_cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_cost_basis),
	CashFlowCommonData(125, "refinance_pct", "mtg_asset_refinance_pct",  "refinance_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_pct, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_pct),
	CashFlowCommonData(126, "refinance_prin", "mtg_asset_refinance_prin",  "refinance_prin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_prin, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_prin),
	CashFlowCommonData(127, "refinance_rate", "mtg_asset_refinance_rate",  "refinance_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_refinance_rate, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_rate),
	CashFlowCommonData(128, "restructure_accr_int_net_write_down", "mtg_asset_restructure_accr_int_net_write_down",  "restructure_accr_int_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_accr_int_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_accr_int_net_write_down),
	CashFlowCommonData(129, "restructure_bk_val_net_write_down", "mtg_asset_restructure_bk_val_net_write_down",  "restructure_bk_val_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_bk_val_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_bk_val_net_write_down),
	CashFlowCommonData(130, "restructure_cost_basis_net_write_down", "mtg_asset_restructure_cost_basis_net_write_down",  "restructure_cost_basis_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_cost_basis_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_cost_basis_net_write_down),
	CashFlowCommonData(131, "restructure_pct", "mtg_asset_restructure_pct",  "restructure_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_pct, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_pct),
	CashFlowCommonData(132, "restructure_prin_net_write_down", "mtg_asset_restructure_prin_net_write_down",  "restructure_prin_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_prin_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_prin_net_write_down),
	CashFlowCommonData(133, "restructure_rate", "mtg_asset_restructure_rate",  "restructure_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_restructure_rate, 'E','N', '3', 'P', (size_t)&modelOffset->restructure_rate),
	CashFlowCommonData(134, "sched_prin_pmt", "mtg_asset_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sched_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(135, "sold_pct", "mtg_asset_sold_pct",  "sold_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sold_pct, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct),
	CashFlowCommonData(136, "sold_pct_fund_match", "mtg_asset_sold_pct_fund_match",  "sold_pct_fund_match",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sold_pct_fund_match, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_fund_match),
	CashFlowCommonData(137, "sold_pct_neg_cash_flow", "mtg_asset_sold_pct_neg_cash_flow",  "sold_pct_neg_cash_flow",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sold_pct_neg_cash_flow, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_neg_cash_flow),
	CashFlowCommonData(138, "sold_pct_planned", "mtg_asset_sold_pct_planned",  "sold_pct_planned",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sold_pct_planned, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_planned),
	CashFlowCommonData(139, "sold_pct_rebal", "mtg_asset_sold_pct_rebal",  "sold_pct_rebal",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sold_pct_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_rebal),
	CashFlowCommonData(140, "startup", "mtg_asset_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(141, "sub_port_id", "mtg_asset_sub_port_id",  "sub_port_id",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_sub_port_id, 'E','N', '3', 'P', (size_t)&modelOffset->sub_port_id),
	CashFlowCommonData(142, "unrealzd_cap_gain", "mtg_asset_unrealzd_cap_gain",  "unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain),
	CashFlowCommonData(143, "unrealzd_cap_gain_bef_fund_match_sale", "mtg_asset_unrealzd_cap_gain_bef_fund_match_sale",  "unrealzd_cap_gain_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_fund_match_sale),
	CashFlowCommonData(144, "unrealzd_cap_gain_bef_neg_cash_flow_sale", "mtg_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale",  "unrealzd_cap_gain_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_neg_cash_flow_sale),
	CashFlowCommonData(145, "unrealzd_cap_gain_bef_rebal_sale", "mtg_asset_unrealzd_cap_gain_bef_rebal_sale",  "unrealzd_cap_gain_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_rebal_sale),
	CashFlowCommonData(146, "unrealzd_cap_gain_bef_sale", "mtg_asset_unrealzd_cap_gain_bef_sale",  "unrealzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_sale),
	CashFlowCommonData(147, "unrealzd_cap_gain_gaap_surp", "mtg_asset_unrealzd_cap_gain_gaap_surp",  "unrealzd_cap_gain_gaap_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_gaap_surp, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_gaap_surp),
	CashFlowCommonData(148, "unrealzd_cap_gain_incr", "mtg_asset_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(149, "unrealzd_cap_gain_released_on_sale", "mtg_asset_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(150, "unrealzd_cap_gain_to_bk_ratio", "mtg_asset_unrealzd_cap_gain_to_bk_ratio",  "unrealzd_cap_gain_to_bk_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_gain_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_to_bk_ratio),
	CashFlowCommonData(151, "unrealzd_cap_loss_from_dflt", "mtg_asset_unrealzd_cap_loss_from_dflt",  "unrealzd_cap_loss_from_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_unrealzd_cap_loss_from_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_loss_from_dflt),
	CashFlowCommonData(152, "weighted_avg_life", "mtg_asset_weighted_avg_life",  "weighted_avg_life",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_weighted_avg_life, 'E','N', '3', 'C', (size_t)&modelOffset->weighted_avg_life),
	CashFlowCommonData(153, "write_down", "mtg_asset_write_down",  "write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_write_down, 'E','Y', '3', 'C', (size_t)&modelOffset->write_down),
	CashFlowCommonData(154, "yld_denom", "mtg_asset_yld_denom",  "yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->yld_denom),
	CashFlowCommonData(155, "yld_numer", "mtg_asset_yld_numer",  "yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_yld_numer, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer),
	CashFlowCommonData(156, "yld_numer_adj_aig", "mtg_asset_yld_numer_adj_aig",  "yld_numer_adj_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_ASSET_UDF::mtg_asset_yld_numer_adj_aig, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer_adj_aig)
};
const CashFlowCommonData* MTG_ASSET::mCFStaticData[] = {
	&MTG_ASSET::mCFStaticData_0[0],
	&MTG_ASSET::mCFStaticData_0[1],
	&MTG_ASSET::mCFStaticData_0[2],
	&MTG_ASSET::mCFStaticData_0[3],
	&MTG_ASSET::mCFStaticData_0[4],
	&MTG_ASSET::mCFStaticData_0[5],
	&MTG_ASSET::mCFStaticData_0[6],
	&MTG_ASSET::mCFStaticData_0[7],
	&MTG_ASSET::mCFStaticData_0[8],
	&MTG_ASSET::mCFStaticData_0[9],
	&MTG_ASSET::mCFStaticData_0[10],
	&MTG_ASSET::mCFStaticData_0[11],
	&MTG_ASSET::mCFStaticData_0[12],
	&MTG_ASSET::mCFStaticData_0[13],
	&MTG_ASSET::mCFStaticData_0[14],
	&MTG_ASSET::mCFStaticData_0[15],
	&MTG_ASSET::mCFStaticData_0[16],
	&MTG_ASSET::mCFStaticData_0[17],
	&MTG_ASSET::mCFStaticData_0[18],
	&MTG_ASSET::mCFStaticData_0[19],
	&MTG_ASSET::mCFStaticData_0[20],
	&MTG_ASSET::mCFStaticData_0[21],
	&MTG_ASSET::mCFStaticData_0[22],
	&MTG_ASSET::mCFStaticData_0[23],
	&MTG_ASSET::mCFStaticData_0[24],
	&MTG_ASSET::mCFStaticData_0[25],
	&MTG_ASSET::mCFStaticData_0[26],
	&MTG_ASSET::mCFStaticData_0[27],
	&MTG_ASSET::mCFStaticData_0[28],
	&MTG_ASSET::mCFStaticData_0[29],
	&MTG_ASSET::mCFStaticData_0[30],
	&MTG_ASSET::mCFStaticData_0[31],
	&MTG_ASSET::mCFStaticData_0[32],
	&MTG_ASSET::mCFStaticData_0[33],
	&MTG_ASSET::mCFStaticData_0[34],
	&MTG_ASSET::mCFStaticData_0[35],
	&MTG_ASSET::mCFStaticData_0[36],
	&MTG_ASSET::mCFStaticData_0[37],
	&MTG_ASSET::mCFStaticData_0[38],
	&MTG_ASSET::mCFStaticData_0[39],
	&MTG_ASSET::mCFStaticData_0[40],
	&MTG_ASSET::mCFStaticData_0[41],
	&MTG_ASSET::mCFStaticData_0[42],
	&MTG_ASSET::mCFStaticData_0[43],
	&MTG_ASSET::mCFStaticData_0[44],
	&MTG_ASSET::mCFStaticData_0[45],
	&MTG_ASSET::mCFStaticData_0[46],
	&MTG_ASSET::mCFStaticData_0[47],
	&MTG_ASSET::mCFStaticData_0[48],
	&MTG_ASSET::mCFStaticData_0[49],
	&MTG_ASSET::mCFStaticData_0[50],
	&MTG_ASSET::mCFStaticData_0[51],
	&MTG_ASSET::mCFStaticData_0[52],
	&MTG_ASSET::mCFStaticData_0[53],
	&MTG_ASSET::mCFStaticData_0[54],
	&MTG_ASSET::mCFStaticData_0[55],
	&MTG_ASSET::mCFStaticData_0[56],
	&MTG_ASSET::mCFStaticData_0[57],
	&MTG_ASSET::mCFStaticData_0[58],
	&MTG_ASSET::mCFStaticData_0[59],
	&MTG_ASSET::mCFStaticData_0[60],
	&MTG_ASSET::mCFStaticData_0[61],
	&MTG_ASSET::mCFStaticData_0[62],
	&MTG_ASSET::mCFStaticData_0[63],
	&MTG_ASSET::mCFStaticData_0[64],
	&MTG_ASSET::mCFStaticData_0[65],
	&MTG_ASSET::mCFStaticData_0[66],
	&MTG_ASSET::mCFStaticData_0[67],
	&MTG_ASSET::mCFStaticData_0[68],
	&MTG_ASSET::mCFStaticData_0[69],
	&MTG_ASSET::mCFStaticData_0[70],
	&MTG_ASSET::mCFStaticData_0[71],
	&MTG_ASSET::mCFStaticData_0[72],
	&MTG_ASSET::mCFStaticData_0[73],
	&MTG_ASSET::mCFStaticData_0[74],
	&MTG_ASSET::mCFStaticData_0[75],
	&MTG_ASSET::mCFStaticData_0[76],
	&MTG_ASSET::mCFStaticData_0[77],
	&MTG_ASSET::mCFStaticData_0[78],
	&MTG_ASSET::mCFStaticData_0[79],
	&MTG_ASSET::mCFStaticData_0[80],
	&MTG_ASSET::mCFStaticData_0[81],
	&MTG_ASSET::mCFStaticData_0[82],
	&MTG_ASSET::mCFStaticData_0[83],
	&MTG_ASSET::mCFStaticData_0[84],
	&MTG_ASSET::mCFStaticData_0[85],
	&MTG_ASSET::mCFStaticData_0[86],
	&MTG_ASSET::mCFStaticData_0[87],
	&MTG_ASSET::mCFStaticData_0[88],
	&MTG_ASSET::mCFStaticData_0[89],
	&MTG_ASSET::mCFStaticData_0[90],
	&MTG_ASSET::mCFStaticData_0[91],
	&MTG_ASSET::mCFStaticData_0[92],
	&MTG_ASSET::mCFStaticData_0[93],
	&MTG_ASSET::mCFStaticData_0[94],
	&MTG_ASSET::mCFStaticData_0[95],
	&MTG_ASSET::mCFStaticData_0[96],
	&MTG_ASSET::mCFStaticData_0[97],
	&MTG_ASSET::mCFStaticData_0[98],
	&MTG_ASSET::mCFStaticData_0[99],
	&MTG_ASSET::mCFStaticData_0[100],
	&MTG_ASSET::mCFStaticData_0[101],
	&MTG_ASSET::mCFStaticData_0[102],
	&MTG_ASSET::mCFStaticData_0[103],
	&MTG_ASSET::mCFStaticData_0[104],
	&MTG_ASSET::mCFStaticData_0[105],
	&MTG_ASSET::mCFStaticData_0[106],
	&MTG_ASSET::mCFStaticData_0[107],
	&MTG_ASSET::mCFStaticData_0[108],
	&MTG_ASSET::mCFStaticData_0[109],
	&MTG_ASSET::mCFStaticData_0[110],
	&MTG_ASSET::mCFStaticData_0[111],
	&MTG_ASSET::mCFStaticData_0[112],
	&MTG_ASSET::mCFStaticData_0[113],
	&MTG_ASSET::mCFStaticData_0[114],
	&MTG_ASSET::mCFStaticData_0[115],
	&MTG_ASSET::mCFStaticData_0[116],
	&MTG_ASSET::mCFStaticData_0[117],
	&MTG_ASSET::mCFStaticData_0[118],
	&MTG_ASSET::mCFStaticData_0[119],
	&MTG_ASSET::mCFStaticData_0[120],
	&MTG_ASSET::mCFStaticData_0[121],
	&MTG_ASSET::mCFStaticData_0[122],
	&MTG_ASSET::mCFStaticData_0[123],
	&MTG_ASSET::mCFStaticData_0[124],
	&MTG_ASSET::mCFStaticData_0[125],
	&MTG_ASSET::mCFStaticData_0[126],
	&MTG_ASSET::mCFStaticData_0[127],
	&MTG_ASSET::mCFStaticData_0[128],
	&MTG_ASSET::mCFStaticData_0[129],
	&MTG_ASSET::mCFStaticData_0[130],
	&MTG_ASSET::mCFStaticData_0[131],
	&MTG_ASSET::mCFStaticData_0[132],
	&MTG_ASSET::mCFStaticData_0[133],
	&MTG_ASSET::mCFStaticData_0[134],
	&MTG_ASSET::mCFStaticData_0[135],
	&MTG_ASSET::mCFStaticData_0[136],
	&MTG_ASSET::mCFStaticData_0[137],
	&MTG_ASSET::mCFStaticData_0[138],
	&MTG_ASSET::mCFStaticData_0[139],
	&MTG_ASSET::mCFStaticData_0[140],
	&MTG_ASSET::mCFStaticData_0[141],
	&MTG_ASSET::mCFStaticData_0[142],
	&MTG_ASSET::mCFStaticData_0[143],
	&MTG_ASSET::mCFStaticData_0[144],
	&MTG_ASSET::mCFStaticData_0[145],
	&MTG_ASSET::mCFStaticData_0[146],
	&MTG_ASSET::mCFStaticData_0[147],
	&MTG_ASSET::mCFStaticData_0[148],
	&MTG_ASSET::mCFStaticData_0[149],
	&MTG_ASSET::mCFStaticData_0[150],
	&MTG_ASSET::mCFStaticData_0[151],
	&MTG_ASSET::mCFStaticData_0[152],
	&MTG_ASSET::mCFStaticData_0[153],
	&MTG_ASSET::mCFStaticData_0[154],
	&MTG_ASSET::mCFStaticData_0[155],
	&MTG_ASSET::mCFStaticData_0[156],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for adco_adj_rate_defn                                                                                       
	const ChoicePair adco_adj_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NON_CONVERTIBLE, "Non Convertible")
		,ChoicePair(StrEnum::CONVERTIBLE, "Convertible")
	};
	const EnumList adco_adj_rate_defnEnumList(2, adco_adj_rate_defnChoicePairs);

	// EnumList for adco_subprime_defn                                                                                       
	const ChoicePair adco_subprime_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SUBPRIME_COLLATERAL, "Subprime Collateral")
		,ChoicePair(StrEnum::PRIME_COLLATERAL, "Prime Collateral")
	};
	const EnumList adco_subprime_defnEnumList(2, adco_subprime_defnChoicePairs);

	// EnumList for amortzd_cost_period_defn                                                                                       
	const ChoicePair amortzd_cost_period_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TO_NEXT_RATE_RESET, "To Next Rate Reset")
		,ChoicePair(StrEnum::TO_MATURITY, "To Maturity")
	};
	const EnumList amortzd_cost_period_defnEnumList(2, amortzd_cost_period_defnChoicePairs);

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

	// EnumList for balloon_defn_mp                                                                                       
	const ChoicePair balloon_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES_ON_SINGLE_DATE, "Yes On Single Date")
		,ChoicePair(StrEnum::YES_PER_SCHEDULE, "Yes Per Schedule")
	};
	const EnumList balloon_defn_mpEnumList(3, balloon_defn_mpChoicePairs);

	// EnumList for bk_val_defn                                                                                       
	const ChoicePair bk_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::COST_BASIS, "Cost Basis")
	};
	const EnumList bk_val_defnEnumList(1, bk_val_defnChoicePairs);

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

	// EnumList for dflt_rate_bef_maturity_defn                                                                                       
	const ChoicePair dflt_rate_bef_maturity_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MATURITY_DATE, "Maturity Date")
		,ChoicePair(StrEnum::FIRST_BALLOON_PAYMENT_DATE, "First Balloon Payment Date")
	};
	const EnumList dflt_rate_bef_maturity_defnEnumList(2, dflt_rate_bef_maturity_defnChoicePairs);

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

	// EnumList for mkt_val_defn                                                                                       
	const ChoicePair mkt_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TO_MATURITY, "To Maturity")
		,ChoicePair(StrEnum::TO_NEXT_RATE_RESET, "To Next Rate Reset")
	};
	const EnumList mkt_val_defnEnumList(2, mkt_val_defnChoicePairs);

	// EnumList for pmt_mode_mp                                                                                       
	const ChoicePair pmt_mode_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList pmt_mode_mpEnumList(4, pmt_mode_mpChoicePairs);

	// EnumList for pmt_rate_defn_purch                                                                                       
	const ChoicePair pmt_rate_defn_purchChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList pmt_rate_defn_purchEnumList(3, pmt_rate_defn_purchChoicePairs);

	// EnumList for port_defn_mp                                                                                       
	const ChoicePair port_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
	};
	const EnumList port_defn_mpEnumList(1, port_defn_mpChoicePairs);

	// EnumList for prepmt_defn                                                                                       
	const ChoicePair prepmt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ABSOLUTE_PERCENTAGE, "Absolute Percentage")
		,ChoicePair(StrEnum::PERCENT_OF_PSA, "Percent of PSA")
	};
	const EnumList prepmt_defnEnumList(2, prepmt_defnChoicePairs);

	// EnumList for prepmt_int_diff_defn                                                                                       
	const ChoicePair prepmt_int_diff_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GROSS_INTEREST_RATE, "Gross Interest Rate")
		,ChoicePair(StrEnum::INTEREST_RATE, "Interest Rate")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
	};
	const EnumList prepmt_int_diff_defnEnumList(3, prepmt_int_diff_defnChoicePairs);

	// EnumList for prepmt_model_defn                                                                                       
	const ChoicePair prepmt_model_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SPLINE, "Spline")
		,ChoicePair(StrEnum::ANDREW_DAVIDSON, "Andrew Davidson")
	};
	const EnumList prepmt_model_defnEnumList(2, prepmt_model_defnChoicePairs);

	// EnumList for prepmt_penalty_defn_mp                                                                                       
	const ChoicePair prepmt_penalty_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::PENALTY_PERCENT, "Penalty Percent")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::CASH_FLOW_MAINTENANCE, "Cash Flow Maintenance")
	};
	const EnumList prepmt_penalty_defn_mpEnumList(4, prepmt_penalty_defn_mpChoicePairs);

	// EnumList for purch_defn                                                                                       
	const ChoicePair purch_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::COLLATERAL_POOL, "Collateral Pool")
		,ChoicePair(StrEnum::RESTRUCTURE, "Restructure")
		,ChoicePair(StrEnum::FORECLOSURE, "Foreclosure")
		,ChoicePair(StrEnum::REFINANCE, "Refinance")
		,ChoicePair(StrEnum::UNRESTRICTED, "Unrestricted")
	};
	const EnumList purch_defnEnumList(6, purch_defnChoicePairs);

	// EnumList for refinancing_rate_defn                                                                                       
	const ChoicePair refinancing_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::CATEGORY_YIELD_TO_MATURITY, "Category Yield to Maturity")
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

	// EnumList for use_mp                                                                                       
	const ChoicePair use_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_mpEnumList(2, use_mpChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace MTG_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(MTG_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(MTG_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace MTG_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void MTG_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> MTG_ASSET::mgr_;

	Attribute::Descriptor MTG_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"adco_adj_rate_defn", -1, (size_t)&modelOffset->adco_adj_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &adco_adj_rate_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STRING,	"adco_category_id", -1, (size_t)&modelOffset->adco_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STRING,	"adco_collateral_defn", -1, (size_t)&modelOffset->adco_collateral_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STR_ENUM,	"adco_subprime_defn", -1, (size_t)&modelOffset->adco_subprime_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &adco_subprime_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"adj_max_decr_per_reset_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_decr_per_reset_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"adj_max_incr_per_reset_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_incr_per_reset_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"adj_max_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_max_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"adj_min_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_min_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STRING,	"adj_next_reset_date_mp", -1, (size_t)&modelOffset->adj_next_reset_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"adj_reset_category_id_mp", -1, (size_t)&modelOffset->adj_reset_category_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::INT,	"adj_reset_mths_mp", -1, (size_t)&modelOffset->adj_reset_mths_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"adj_reset_renewal_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_renewal_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"adj_reset_scen_mult_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_scen_mult_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"adj_reset_scen_yr_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->adj_reset_scen_yr_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STR_ENUM,	"amortzd_cost_period_defn", -1, (size_t)&modelOffset->amortzd_cost_period_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &amortzd_cost_period_defnEnumList, Feature(true)),
	Descriptor(15, Attribute::INT,	"amortzn_start_cy_mp", -1, (size_t)&modelOffset->amortzn_start_cy_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STRING,	"asset_detail_rpt_cusip_id", -1, (size_t)&modelOffset->asset_detail_rpt_cusip_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STRING,	"asset_detail_rpt_id", -1, (size_t)&modelOffset->asset_detail_rpt_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::STR_ENUM,	"asset_detail_rpt_pv_defn", -1, (size_t)&modelOffset->asset_detail_rpt_pv_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_pv_defnEnumList, Feature(true)),
	Descriptor(20, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STRING,	"asset_id_mp", -1, (size_t)&modelOffset->asset_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::STR_ENUM,	"asset_mkt_sprd_use_defn", -1, (size_t)&modelOffset->asset_mkt_sprd_use_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_mkt_sprd_use_defnEnumList, Feature(true)),
	Descriptor(24, Attribute::DOUBLE,	"avr_contribn_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_contribn_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::DOUBLE,	"avr_max_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_max_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"avr_obj_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_obj_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STRING,	"balloon_date_mp", -1, (size_t)&modelOffset->balloon_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::STR_ENUM,	"balloon_defn_mp", -1, (size_t)&modelOffset->balloon_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &balloon_defn_mpEnumList, Feature(true)),
	Descriptor(29, Attribute::DOUBLE,	"balloon_prin_pmt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->balloon_prin_pmt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STR_ENUM,	"bk_val_defn", -1, (size_t)&modelOffset->bk_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &bk_val_defnEnumList, Feature(true)),
	Descriptor(31, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STRING,	"category_id_mp", -1, (size_t)&modelOffset->category_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::STR_ENUM,	"cost_basis_defn", -1, (size_t)&modelOffset->cost_basis_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cost_basis_defnEnumList, Feature(true)),
	Descriptor(34, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(35, Attribute::STR_ENUM,	"dflt_rate_bef_maturity_defn", -1, (size_t)&modelOffset->dflt_rate_bef_maturity_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &dflt_rate_bef_maturity_defnEnumList, Feature(true)),
	Descriptor(36, Attribute::DOUBLE,	"dflt_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dflt_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::DOUBLE,	"dur_wtd_sprd_adj_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_wtd_sprd_adj_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"dur_wtd_sprd_adj_aig_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_wtd_sprd_adj_aig_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STR_ENUM,	"fast_stat_calc_aig", -1, (size_t)&modelOffset->fast_stat_calc_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fast_stat_calc_aigEnumList, Feature(true)),
	Descriptor(40, Attribute::DOUBLE,	"foreclosure_rate_mult_bef_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_rate_mult_bef_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"foreclosure_rate_mult_since_issue", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_rate_mult_since_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::DOUBLE,	"foreclosure_rate_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_rate_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::DOUBLE,	"foreclosure_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::DOUBLE,	"foreclosure_write_down_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_write_down_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::STR_ENUM,	"gaap_acctng_defn", -1, (size_t)&modelOffset->gaap_acctng_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gaap_acctng_defnEnumList, Feature(true)),
	Descriptor(46, Attribute::STR_ENUM,	"ia_prod_v3_rsd_2_aig", -1, (size_t)&modelOffset->ia_prod_v3_rsd_2_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ia_prod_v3_rsd_2_aigEnumList, Feature(true)),
	Descriptor(47, Attribute::DOUBLE,	"init_bk_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_bk_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::DOUBLE,	"init_cost_basis_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cost_basis_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::DOUBLE,	"init_mkt_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_mkt_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::DOUBLE,	"init_par_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_par_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::DOUBLE,	"init_pmt_rate_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_pmt_rate_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::DOUBLE,	"int_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::STR_ENUM,	"intex_defn", -1, (size_t)&modelOffset->intex_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &intex_defnEnumList, Feature(true)),
	Descriptor(54, Attribute::STRING,	"issue_date_mp", -1, (size_t)&modelOffset->issue_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::STRING,	"maturity_date_mp", -1, (size_t)&modelOffset->maturity_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::STR_ENUM,	"mkt_val_calc_freq", -1, (size_t)&modelOffset->mkt_val_calc_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freqEnumList, Feature(true)),
	Descriptor(57, Attribute::INT,	"mkt_val_calc_freq_yrs", -1, (size_t)&modelOffset->mkt_val_calc_freq_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STR_ENUM,	"mkt_val_defn", -1, (size_t)&modelOffset->mkt_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_defnEnumList, Feature(true)),
	Descriptor(59, Attribute::DOUBLE,	"nonfinancial_int_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nonfinancial_int_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::STRING,	"planned_sale_date_mp", -1, (size_t)&modelOffset->planned_sale_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::STR_ENUM,	"pmt_mode_mp", -1, (size_t)&modelOffset->pmt_mode_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pmt_mode_mpEnumList, Feature(true)),
	Descriptor(62, Attribute::STR_ENUM,	"pmt_rate_defn_purch", -1, (size_t)&modelOffset->pmt_rate_defn_purch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pmt_rate_defn_purchEnumList, Feature(true)),
	Descriptor(63, Attribute::STR_ENUM,	"port_defn_mp", -1, (size_t)&modelOffset->port_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &port_defn_mpEnumList, Feature(true)),
	Descriptor(64, Attribute::DOUBLE,	"portfolio_sprd_adj_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->portfolio_sprd_adj_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::DOUBLE,	"portfolio_sprd_adj_aig_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->portfolio_sprd_adj_aig_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::STR_ENUM,	"prepmt_defn", -1, (size_t)&modelOffset->prepmt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_defnEnumList, Feature(true)),
	Descriptor(67, Attribute::DOUBLE,	"prepmt_exercise_pct_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_exercise_pct_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(68, Attribute::STR_ENUM,	"prepmt_int_diff_defn", -1, (size_t)&modelOffset->prepmt_int_diff_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_int_diff_defnEnumList, Feature(true)),
	Descriptor(69, Attribute::STR_ENUM,	"prepmt_model_defn", -1, (size_t)&modelOffset->prepmt_model_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_model_defnEnumList, Feature(true)),
	Descriptor(70, Attribute::DOUBLE,	"prepmt_nonfinancial_adj", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_nonfinancial_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(71, Attribute::DOUBLE,	"prepmt_nonfinancial_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_nonfinancial_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(72, Attribute::DOUBLE,	"prepmt_nonfinancial_seasonality_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_nonfinancial_seasonality_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::STRING,	"prepmt_opt_first_date_mp", -1, (size_t)&modelOffset->prepmt_opt_first_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(74, Attribute::STR_ENUM,	"prepmt_penalty_defn_mp", -1, (size_t)&modelOffset->prepmt_penalty_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_penalty_defn_mpEnumList, Feature(true)),
	Descriptor(75, Attribute::DOUBLE,	"prepmt_penalty_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_penalty_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::DOUBLE,	"prepmt_seasoning_since_issue_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_seasoning_since_issue_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::DOUBLE,	"prin_val_at_issue_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prin_val_at_issue_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::STRING,	"purch_asset_id", -1, (size_t)&modelOffset->purch_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(80, Attribute::INT,	"purch_asset_sub_port", -1, (size_t)&modelOffset->purch_asset_sub_port,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(81, Attribute::STR_ENUM,	"purch_defn", -1, (size_t)&modelOffset->purch_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_defnEnumList, Feature(true)),
	Descriptor(82, Attribute::DOUBLE,	"rbc_c1_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(83, Attribute::DOUBLE,	"refinance_rate_mult_bef_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinance_rate_mult_bef_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(84, Attribute::DOUBLE,	"refinance_rate_mult_since_issue", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinance_rate_mult_since_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(85, Attribute::DOUBLE,	"refinance_rate_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinance_rate_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(86, Attribute::DOUBLE,	"refinance_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinance_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(87, Attribute::DOUBLE,	"refinancing_cost_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_cost_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(88, Attribute::STR_ENUM,	"refinancing_rate_defn", -1, (size_t)&modelOffset->refinancing_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &refinancing_rate_defnEnumList, Feature(true)),
	Descriptor(89, Attribute::DOUBLE,	"refinancing_rate_scen_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(90, Attribute::DOUBLE,	"refinancing_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(91, Attribute::DOUBLE,	"refinancing_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(92, Attribute::DOUBLE,	"restructure_rate_mult_bef_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_rate_mult_bef_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(93, Attribute::DOUBLE,	"restructure_rate_mult_since_issue", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_rate_mult_since_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(94, Attribute::DOUBLE,	"restructure_rate_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_rate_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(95, Attribute::DOUBLE,	"restructure_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(96, Attribute::DOUBLE,	"restructure_write_down_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_write_down_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(97, Attribute::STR_ENUM,	"sale_class_mp", -1, (size_t)&modelOffset->sale_class_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sale_class_mpEnumList, Feature(true)),
	Descriptor(98, Attribute::STRING,	"seg_id_mp", -1, (size_t)&modelOffset->seg_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(99, Attribute::DOUBLE,	"servicing_fee_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->servicing_fee_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(100, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(101, Attribute::DOUBLE,	"yld_maint_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->yld_maint_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(102, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(103, Attribute::SCALAR_DOUBLE,	"accr_int_per_par_unit", -1, (size_t)&modelOffset->accr_int_per_par_unit,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_accr_int_per_par_unit)),
	Descriptor(104, Attribute::SCALAR_INT,	"amortzn_cost_period", -1, (size_t)&modelOffset->amortzn_cost_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_amortzn_cost_period)),
	Descriptor(105, Attribute::SCALAR_INT,	"amortzn_period", -1, (size_t)&modelOffset->amortzn_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_amortzn_period)),
	Descriptor(106, Attribute::SCALAR_INT,	"asset_detail_rpt_flag", -1, (size_t)&modelOffset->asset_detail_rpt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_asset_detail_rpt_flag)),
	Descriptor(107, Attribute::SCALAR_INT,	"asset_fund_index", -1, (size_t)&modelOffset->asset_fund_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_asset_fund_index)),
	Descriptor(108, Attribute::SCALAR_INT,	"balloon_pmt_flag", -1, (size_t)&modelOffset->balloon_pmt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_balloon_pmt_flag)),
	Descriptor(109, Attribute::SCALAR_INT,	"balloon_pmt_period", -1, (size_t)&modelOffset->balloon_pmt_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_balloon_pmt_period)),
	Descriptor(110, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_commencement_period)),
	Descriptor(111, Attribute::SCALAR_STRING,	"data_grp_id", -1, (size_t)&modelOffset->data_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&MTG_ASSET_UDF::mtg_asset_data_grp_id)),
	Descriptor(112, Attribute::SCALAR_INT,	"existing_asset_indicator", -1, (size_t)&modelOffset->existing_asset_indicator,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_existing_asset_indicator)),
	Descriptor(113, Attribute::SCALAR_INT,	"foreclosure_asset_id", -1, (size_t)&modelOffset->foreclosure_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_foreclosure_asset_id)),
	Descriptor(114, Attribute::SCALAR_DOUBLE,	"foreclosure_write_down_pct_calc", -1, (size_t)&modelOffset->foreclosure_write_down_pct_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_foreclosure_write_down_pct_calc)),
	Descriptor(115, Attribute::SCALAR_INT,	"gaap_inc_defn", -1, (size_t)&modelOffset->gaap_inc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_gaap_inc_defn)),
	Descriptor(116, Attribute::SCALAR_INT,	"gaap_val_defn", -1, (size_t)&modelOffset->gaap_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_gaap_val_defn)),
	Descriptor(117, Attribute::SCALAR_INT,	"init_mths_since_issue", -1, (size_t)&modelOffset->init_mths_since_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_init_mths_since_issue)),
	Descriptor(118, Attribute::SCALAR_INT,	"maturity_mths_from_next_reset", -1, (size_t)&modelOffset->maturity_mths_from_next_reset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_maturity_mths_from_next_reset)),
	Descriptor(119, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_maturity_period)),
	Descriptor(120, Attribute::SCALAR_DOUBLE,	"mkt_val_per_unit_par", -1, (size_t)&modelOffset->mkt_val_per_unit_par,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_mkt_val_per_unit_par)),
	Descriptor(121, Attribute::SCALAR_DOUBLE,	"neg_asset_flag", -1, (size_t)&modelOffset->neg_asset_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_neg_asset_flag)),
	Descriptor(122, Attribute::SCALAR_DOUBLE,	"par_val_at_issue", -1, (size_t)&modelOffset->par_val_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_par_val_at_issue)),
	Descriptor(123, Attribute::SCALAR_DOUBLE,	"pct_to_use", -1, (size_t)&modelOffset->pct_to_use,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_pct_to_use)),
	Descriptor(124, Attribute::SCALAR_DOUBLE,	"planned_sale_period", -1, (size_t)&modelOffset->planned_sale_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_planned_sale_period)),
	Descriptor(125, Attribute::SCALAR_INT,	"pmt_freq", -1, (size_t)&modelOffset->pmt_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_pmt_freq)),
	Descriptor(126, Attribute::SCALAR_INT,	"pmt_mths", -1, (size_t)&modelOffset->pmt_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_pmt_mths)),
	Descriptor(127, Attribute::SCALAR_DOUBLE,	"pmt_rate_at_issue", -1, (size_t)&modelOffset->pmt_rate_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_pmt_rate_at_issue)),
	Descriptor(128, Attribute::SCALAR_INT,	"pmt_rate_defn", -1, (size_t)&modelOffset->pmt_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_pmt_rate_defn)),
	Descriptor(129, Attribute::SCALAR_STRING,	"pmt_rate_defn_string", -1, (size_t)&modelOffset->pmt_rate_defn_string,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&MTG_ASSET_UDF::mtg_asset_pmt_rate_defn_string)),
	Descriptor(130, Attribute::SCALAR_INT,	"pmt_reset_first_period", -1, (size_t)&modelOffset->pmt_reset_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_pmt_reset_first_period)),
	Descriptor(131, Attribute::SCALAR_INT,	"prepmt_first_period", -1, (size_t)&modelOffset->prepmt_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_prepmt_first_period)),
	Descriptor(132, Attribute::SCALAR_INT,	"prepmt_par_first_period", -1, (size_t)&modelOffset->prepmt_par_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_prepmt_par_first_period)),
	Descriptor(133, Attribute::SCALAR_INT,	"prepmt_penalty_grading_mths", -1, (size_t)&modelOffset->prepmt_penalty_grading_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_prepmt_penalty_grading_mths)),
	Descriptor(134, Attribute::SCALAR_DOUBLE,	"prepmt_penalty_related_to_pmt_rate", -1, (size_t)&modelOffset->prepmt_penalty_related_to_pmt_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_prepmt_penalty_related_to_pmt_rate)),
	Descriptor(135, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&MTG_ASSET_UDF::mtg_asset_proj_date_adj)),
	Descriptor(136, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_proj_start_date)),
	Descriptor(137, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_proj_start_mth)),
	Descriptor(138, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_proj_start_yr)),
	Descriptor(139, Attribute::SCALAR_INT,	"refinance_asset_id", -1, (size_t)&modelOffset->refinance_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_refinance_asset_id)),
	Descriptor(140, Attribute::SCALAR_INT,	"refinancing_rate_defn_calc", -1, (size_t)&modelOffset->refinancing_rate_defn_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_refinancing_rate_defn_calc)),
	Descriptor(141, Attribute::SCALAR_INT,	"restructure_asset_id", -1, (size_t)&modelOffset->restructure_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_restructure_asset_id)),
	Descriptor(142, Attribute::SCALAR_DOUBLE,	"restructure_write_down_pct_calc", -1, (size_t)&modelOffset->restructure_write_down_pct_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_restructure_write_down_pct_calc)),
	Descriptor(143, Attribute::SCALAR_INT,	"sale_class_id", -1, (size_t)&modelOffset->sale_class_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_sale_class_id)),
	Descriptor(144, Attribute::SCALAR_INT,	"sch_array_size", -1, (size_t)&modelOffset->sch_array_size,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_sch_array_size)),
	Descriptor(145, Attribute::SCALAR_INT,	"seg_num", -1, (size_t)&modelOffset->seg_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_seg_num)),
	Descriptor(146, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_start_period)),
	Descriptor(147, Attribute::SCALAR_INT,	"use_andrew_davidson", -1, (size_t)&modelOffset->use_andrew_davidson,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_use_andrew_davidson)),
	Descriptor(148, Attribute::SCALAR_INT,	"use_intex_databases_for_mtg", -1, (size_t)&modelOffset->use_intex_databases_for_mtg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_use_intex_databases_for_mtg)),
	Descriptor(149, Attribute::SCALAR_INT,	"write_sch_file_flag", -1, (size_t)&modelOffset->write_sch_file_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MTG_ASSET_UDF::mtg_asset_write_sch_file_flag)),
	Descriptor(150, Attribute::SCALAR_DOUBLE,	"yrs_since_last_pmt", -1, (size_t)&modelOffset->yrs_since_last_pmt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&MTG_ASSET_UDF::mtg_asset_yrs_since_last_pmt)),
	};

	Attribute::Descriptor* MTG_ASSET::descriptorTable[] = {
	&MTG_ASSET::descriptor_0[0],
	&MTG_ASSET::descriptor_0[1],
	&MTG_ASSET::descriptor_0[2],
	&MTG_ASSET::descriptor_0[3],
	&MTG_ASSET::descriptor_0[4],
	&MTG_ASSET::descriptor_0[5],
	&MTG_ASSET::descriptor_0[6],
	&MTG_ASSET::descriptor_0[7],
	&MTG_ASSET::descriptor_0[8],
	&MTG_ASSET::descriptor_0[9],
	&MTG_ASSET::descriptor_0[10],
	&MTG_ASSET::descriptor_0[11],
	&MTG_ASSET::descriptor_0[12],
	&MTG_ASSET::descriptor_0[13],
	&MTG_ASSET::descriptor_0[14],
	&MTG_ASSET::descriptor_0[15],
	&MTG_ASSET::descriptor_0[16],
	&MTG_ASSET::descriptor_0[17],
	&MTG_ASSET::descriptor_0[18],
	&MTG_ASSET::descriptor_0[19],
	&MTG_ASSET::descriptor_0[20],
	&MTG_ASSET::descriptor_0[21],
	&MTG_ASSET::descriptor_0[22],
	&MTG_ASSET::descriptor_0[23],
	&MTG_ASSET::descriptor_0[24],
	&MTG_ASSET::descriptor_0[25],
	&MTG_ASSET::descriptor_0[26],
	&MTG_ASSET::descriptor_0[27],
	&MTG_ASSET::descriptor_0[28],
	&MTG_ASSET::descriptor_0[29],
	&MTG_ASSET::descriptor_0[30],
	&MTG_ASSET::descriptor_0[31],
	&MTG_ASSET::descriptor_0[32],
	&MTG_ASSET::descriptor_0[33],
	&MTG_ASSET::descriptor_0[34],
	&MTG_ASSET::descriptor_0[35],
	&MTG_ASSET::descriptor_0[36],
	&MTG_ASSET::descriptor_0[37],
	&MTG_ASSET::descriptor_0[38],
	&MTG_ASSET::descriptor_0[39],
	&MTG_ASSET::descriptor_0[40],
	&MTG_ASSET::descriptor_0[41],
	&MTG_ASSET::descriptor_0[42],
	&MTG_ASSET::descriptor_0[43],
	&MTG_ASSET::descriptor_0[44],
	&MTG_ASSET::descriptor_0[45],
	&MTG_ASSET::descriptor_0[46],
	&MTG_ASSET::descriptor_0[47],
	&MTG_ASSET::descriptor_0[48],
	&MTG_ASSET::descriptor_0[49],
	&MTG_ASSET::descriptor_0[50],
	&MTG_ASSET::descriptor_0[51],
	&MTG_ASSET::descriptor_0[52],
	&MTG_ASSET::descriptor_0[53],
	&MTG_ASSET::descriptor_0[54],
	&MTG_ASSET::descriptor_0[55],
	&MTG_ASSET::descriptor_0[56],
	&MTG_ASSET::descriptor_0[57],
	&MTG_ASSET::descriptor_0[58],
	&MTG_ASSET::descriptor_0[59],
	&MTG_ASSET::descriptor_0[60],
	&MTG_ASSET::descriptor_0[61],
	&MTG_ASSET::descriptor_0[62],
	&MTG_ASSET::descriptor_0[63],
	&MTG_ASSET::descriptor_0[64],
	&MTG_ASSET::descriptor_0[65],
	&MTG_ASSET::descriptor_0[66],
	&MTG_ASSET::descriptor_0[67],
	&MTG_ASSET::descriptor_0[68],
	&MTG_ASSET::descriptor_0[69],
	&MTG_ASSET::descriptor_0[70],
	&MTG_ASSET::descriptor_0[71],
	&MTG_ASSET::descriptor_0[72],
	&MTG_ASSET::descriptor_0[73],
	&MTG_ASSET::descriptor_0[74],
	&MTG_ASSET::descriptor_0[75],
	&MTG_ASSET::descriptor_0[76],
	&MTG_ASSET::descriptor_0[77],
	&MTG_ASSET::descriptor_0[78],
	&MTG_ASSET::descriptor_0[79],
	&MTG_ASSET::descriptor_0[80],
	&MTG_ASSET::descriptor_0[81],
	&MTG_ASSET::descriptor_0[82],
	&MTG_ASSET::descriptor_0[83],
	&MTG_ASSET::descriptor_0[84],
	&MTG_ASSET::descriptor_0[85],
	&MTG_ASSET::descriptor_0[86],
	&MTG_ASSET::descriptor_0[87],
	&MTG_ASSET::descriptor_0[88],
	&MTG_ASSET::descriptor_0[89],
	&MTG_ASSET::descriptor_0[90],
	&MTG_ASSET::descriptor_0[91],
	&MTG_ASSET::descriptor_0[92],
	&MTG_ASSET::descriptor_0[93],
	&MTG_ASSET::descriptor_0[94],
	&MTG_ASSET::descriptor_0[95],
	&MTG_ASSET::descriptor_0[96],
	&MTG_ASSET::descriptor_0[97],
	&MTG_ASSET::descriptor_0[98],
	&MTG_ASSET::descriptor_0[99],
	&MTG_ASSET::descriptor_0[100],
	&MTG_ASSET::descriptor_0[101],
	&MTG_ASSET::descriptor_0[102],
	&MTG_ASSET::descriptor_0[103],
	&MTG_ASSET::descriptor_0[104],
	&MTG_ASSET::descriptor_0[105],
	&MTG_ASSET::descriptor_0[106],
	&MTG_ASSET::descriptor_0[107],
	&MTG_ASSET::descriptor_0[108],
	&MTG_ASSET::descriptor_0[109],
	&MTG_ASSET::descriptor_0[110],
	&MTG_ASSET::descriptor_0[111],
	&MTG_ASSET::descriptor_0[112],
	&MTG_ASSET::descriptor_0[113],
	&MTG_ASSET::descriptor_0[114],
	&MTG_ASSET::descriptor_0[115],
	&MTG_ASSET::descriptor_0[116],
	&MTG_ASSET::descriptor_0[117],
	&MTG_ASSET::descriptor_0[118],
	&MTG_ASSET::descriptor_0[119],
	&MTG_ASSET::descriptor_0[120],
	&MTG_ASSET::descriptor_0[121],
	&MTG_ASSET::descriptor_0[122],
	&MTG_ASSET::descriptor_0[123],
	&MTG_ASSET::descriptor_0[124],
	&MTG_ASSET::descriptor_0[125],
	&MTG_ASSET::descriptor_0[126],
	&MTG_ASSET::descriptor_0[127],
	&MTG_ASSET::descriptor_0[128],
	&MTG_ASSET::descriptor_0[129],
	&MTG_ASSET::descriptor_0[130],
	&MTG_ASSET::descriptor_0[131],
	&MTG_ASSET::descriptor_0[132],
	&MTG_ASSET::descriptor_0[133],
	&MTG_ASSET::descriptor_0[134],
	&MTG_ASSET::descriptor_0[135],
	&MTG_ASSET::descriptor_0[136],
	&MTG_ASSET::descriptor_0[137],
	&MTG_ASSET::descriptor_0[138],
	&MTG_ASSET::descriptor_0[139],
	&MTG_ASSET::descriptor_0[140],
	&MTG_ASSET::descriptor_0[141],
	&MTG_ASSET::descriptor_0[142],
	&MTG_ASSET::descriptor_0[143],
	&MTG_ASSET::descriptor_0[144],
	&MTG_ASSET::descriptor_0[145],
	&MTG_ASSET::descriptor_0[146],
	&MTG_ASSET::descriptor_0[147],
	&MTG_ASSET::descriptor_0[148],
	&MTG_ASSET::descriptor_0[149],
	&MTG_ASSET::descriptor_0[150],
	nullptr};
	const size_t MTG_ASSET::sDescriptorCount = 151;

//factory
MTG_ASSET* MTG_ASSET::makeThis(int isSubmodel, ModelClass* owner, MTG_ASSET* peer, 
						int mainRebase, const xstring &name, MTG_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MTG_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MTG_ASSET");
#endif
	MTG_ASSET* newP = (MTG_ASSET*)new MTG_ASSET_UDF
   	  ("mtg_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_cf") == unusedModels.end()) {
	newP->sm_mtg_cf = MTG_CF_ASSET::makeThis(1, newP, peer?peer->sm_mtg_cf:0, mainRebase, name + "|mtg_cf", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_cf:0));
	newP->adopt(newP->sm_mtg_cf);
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
MTG_ASSET_persistent_object* MTG_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, MTG_ASSET* peer, 
							int mainRebase, const xstring &name, MTG_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MTG_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MTG_ASSET_persistent_object");
#endif
	MTG_ASSET_persistent_object* newP = (MTG_ASSET_persistent_object*)new MTG_ASSET_persistent_object
   	  ("mtg_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			MTG_ASSET_persistent_object* pd = dynamic_cast<MTG_ASSET_persistent_object*>(product);
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
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_cf") == unusedModels.end()) {
	newP->sm_mtg_cf = (MTG_CF_ASSET*)MTG_CF_ASSET_persistent_object::makeThis(1, newP, peer?peer->sm_mtg_cf:0, mainRebase, name + "|mtg_cf", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_cf:0), fixedArray);
	newP->adopt(newP->sm_mtg_cf);
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (MTG_ASSET_UDF::*dPF) ();
typedef double (MTG_ASSET_UDF::*dPFd) (double);
typedef int (MTG_ASSET_UDF::*iPF) ();
typedef int (MTG_ASSET_UDF::*iPFi) (int);
typedef xstring (MTG_ASSET_UDF::*sPF) ();
typedef xstring (MTG_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
MTG_ASSET::MTG_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_mtg_cf(0)
	, adco(company_asset_adco)
	, asset(company_asset)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
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

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MTG_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
MTG_ASSET::MTG_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(156, MTG_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_mtg_cf(0)
	, adco(company_asset_adco)
	, asset(company_asset)
	, bond_pv(company_asset_bond_bond_cf_bond_pv)
	, bond_ym(company_asset_bond_bond_cf_bond_ym)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
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
#ifdef __CREATE_ADCO_ASSET_CLASS_
       company_asset_adco = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_pv = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_bond_ym = 0;
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
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
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

	for (int cf_no = 1; cf_no <= 156; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MTG_ASSET_UDF::*dPXi2) (int, int);
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


 void MTG_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_pv = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_pv"));
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_bond_ym = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf|bond_ym"));
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
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
 }
//copy_names END@2


 void MTG_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int MTG_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& MTG_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double MTG_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int MTG_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double MTG_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double MTG_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void MTG_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_ASSET_persistent_object::write(long include_submodels) {
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

	void MTG_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	MTG_ASSET_persistent_object::~MTG_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool MTG_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void MTG_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void MTG_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void MTG_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MTG_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MTG_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* MTG_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* MTG_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* MTG_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char MTG_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void MTG_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
MTG_ASSET_persistent_object::MTG_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			MTG_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(MTG_ASSET::sm_bond_is)
	, sm_bond_pv(MTG_ASSET::sm_bond_pv)
	, sm_bond_ym(MTG_ASSET::sm_bond_ym)
	, sm_mtg_is(MTG_ASSET::sm_mtg_is)
	, sm_mtg_pv(MTG_ASSET::sm_mtg_pv)
	, sm_mtg_ym(MTG_ASSET::sm_mtg_ym)

	, sm_mtg_cf(MTG_ASSET::sm_mtg_cf)
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
MTG_ASSET::~MTG_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void MTG_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void MTG_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void MTG_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void MTG_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void MTG_ASSET::start_of_projection() {
}
//start_of_projection END@2

void MTG_ASSET::end_of_projection() {
}
//end_of_projection END@2

void MTG_ASSET::start_of_layer() {
}


void MTG_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void MTG_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void MTG_ASSET::after_startup(int decrement) {
// Call startup for submodels
  if(sm_mtg_cf)
   sm_mtg_cf->doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void MTG_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> MTG_ASSET::ddfVector;
BitArray MTG_ASSET::dataVariables(151);
bool MTG_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool MTG_ASSET::writeClassInfo = true;

void MTG_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, MTG_ASSET::descriptor_0>::dT = MTG_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, MTG_ASSET::descriptor_0>::dT = MTG_ASSET::descriptor_0;

