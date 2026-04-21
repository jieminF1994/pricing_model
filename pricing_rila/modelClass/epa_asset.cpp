
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
#include "ModelClass\epa_asset_udf.h"
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

extern sowmpoutput epa_state_of_world_mp_output;
extern bool is_asset_initialize;
const int EPV_ACCR_INT = 0;
const int EPV_COST_BASIS = 1;
const int EPV_BK_VAL = 2;
const int EPV_NOTIONAL_AMT = 3;
const int EPV_OPT_INC = 4;
const int EPV_OPT_PMT = 5;
const int EPV_INT_PMT = 6;
const int EPV_MKT_VAL = 7;
const int EPV_EFF_DUR = 8;
const int EPV_REALZD_CAP_GAIN_OPT_PMT = 9;
const int EPV_SCHED_PRIN_PMT = 10;
const int EPV_YRS_TO_MATURITY = 11;
const int EPV_WEIGHTED_AVG_LIFE = 12;
const int EPV_NUM_VALUES = 13;
map <xstring, int, less <xstring> > tas_epa_fields;

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
#ifndef epa_asset_TableDefs
#define epa_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection EPA_ASSET::TTHC;
void EPA_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_sale(t)
	   - cost_basis_aft_dflt(t)
       + accr_int_bef_sale(t)
       - accr_int_aft_dflt(t)
       + int_pmt(t)
       + sched_prin_pmt(t)
       - realzd_cap_gain_opt_pmt(t);

}


//@@ END

//@@ START - accr_int
// Accrued Interest                                                                                             
// Column:ACCR_INT
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_int",t);
}



//^^^

#line 1 "accr_int.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Defaults                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"accr_int_aft_dflt",t);
}



//^^^

#line 1 "accr_int_aft_dflt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - accr_int_bef_fund_match_sale
// Accrued Interest Before Fund Value Matching Asset Sales                                                                                             
// Column:ACCR_INT_BEF_FUND_MATCH_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"accr_int_bef_fund_match_sale",t);
}



//^^^

#line 1 "accr_int_bef_fund_match_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - accr_int_bef_neg_cash_flow_sale
// Accrued Interest Before Negative Cash Flow Sales                                                                                             
// Column:ACCR_INT_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"accr_int_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "accr_int_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - accr_int_bef_rebal_sale
// Accrued Interest Before Rebalancing Sales                                                                                             
// Column:ACCR_INT_BEF_REBAL_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"accr_int_bef_rebal_sale",t);
}



//^^^

#line 1 "accr_int_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - accr_int_bef_sale
// Accrued Interest Before Sales                                                                                             
// Column:ACCR_INT_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_bef_sale(int t) {
//^^^



//^^^

#line 1 "accr_int_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period)
	return get_epa_value("accr_int", t)
	       * epa_pct_remaining(t);

return get_epa_value("accr_int", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - accr_int_dflt
// Accrued Interest Defaults                                                                                             
// Column:ACCR_INT_DFLT
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"accr_int_dflt",t);
}



//^^^

#line 1 "accr_int_dflt.EPA_ASSET.for"
if (t <= 0)
	return NO_AVG;

return dflt_amt(t)
    - cost_basis_dflt(t);

}


//@@ END

//@@ START - accr_int_rent
// Accrued Interest Rent                                                                                             
// Column:ACCR_INT_RENT
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_rent(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"accr_int_rent",t);
}



//^^^

#line 1 "accr_int_rent.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return accr_int(t);

}


//@@ END

//@@ START - accr_int_sold
// Accrued Interest Sold                                                                                             
// Column:ACCR_INT_SOLD
//========================================================
double EPA_ASSET_UDF::epa_asset_accr_int_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"accr_int_sold",t);
}



//^^^

#line 1 "accr_int_sold.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return accr_int_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - asset_min_size_sale_flag
// Asset Minimum Size Sale Flag                                                                                             
// Column:ASSET_MIN_SIZE_SALE_FLAG
//========================================================
double EPA_ASSET_UDF::epa_asset_asset_min_size_sale_flag(int t) {
//^^^



//^^^

#line 1 "asset_min_size_sale_flag.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period || isMainModel)
	return NO_AVG;

if (notional_amt_bef_sale(t) == 0.0)
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
double EPA_ASSET_UDF::epa_asset_avr_basic_contribn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"avr_basic_contribn",t);
}



//^^^

#line 1 "avr_basic_contribn.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_avr_basic_contribn_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"avr_basic_contribn_bef_sale",t);
}



//^^^

#line 1 "avr_basic_contribn_bef_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_avr_max(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"avr_max",t);
}



//^^^

#line 1 "avr_max.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return avr_max_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_max_bef_sale
// AVR Maximum Before Sales                                                                                             
// Column:AVR_MAX_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_avr_max_bef_sale(int t) {
//^^^



//^^^

#line 1 "avr_max_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_max_pct;

}


//@@ END

//@@ START - avr_obj
// AVR Objective                                                                                             
// Column:AVR_OBJ
//========================================================
double EPA_ASSET_UDF::epa_asset_avr_obj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"avr_obj",t);
}



//^^^

#line 1 "avr_obj.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return avr_obj_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - avr_obj_bef_sale
// AVR Objective Before Sales                                                                                             
// Column:AVR_OBJ_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_avr_obj_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"avr_obj_bef_sale",t);
}



//^^^

#line 1 "avr_obj_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * avr_obj_pct;

}


//@@ END

//@@ START - avr_realzd_cap_gain
// AVR Realized Capital Gain                                                                                             
// Column:AVR_REALZD_CAP_GAIN
//========================================================
double EPA_ASSET_UDF::epa_asset_avr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"avr_realzd_cap_gain",t);
}



//^^^

#line 1 "avr_realzd_cap_gain.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return - dflt_amt(t);

}


//@@ END

//@@ START - bk_val
// Book Value                                                                                             
// Column:BK_VAL
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"bk_val",t);
}



//^^^

#line 1 "bk_val.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_neg_cash_flow_sale(t)
	   * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - bk_val_bef_fund_match_sale
// Book Value Before Fund Value Matching Asset Sales                                                                                             
// Column:BK_VAL_BEF_FUND_MATCH_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"bk_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "bk_val_bef_fund_match_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - bk_val_bef_neg_cash_flow_sale
// Book Value Before Negative Cash Flow Sales                                                                                             
// Column:BK_VAL_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"bk_val_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "bk_val_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - bk_val_bef_rebal_sale
// Book Value Before Rebalancing Sales                                                                                             
// Column:BK_VAL_BEF_REBAL_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"bk_val_bef_rebal_sale",t);
}



//^^^

#line 1 "bk_val_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - bk_val_bef_sale
// Book Value Before Sales                                                                                             
// Column:BK_VAL_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period)
	return get_epa_value("bk_val", t)
	       * epa_pct_remaining(t);

return get_epa_value("bk_val", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - bk_val_plus_accr_int_bef_rebal_sale
// Book Value Plus Accrued Interest Before Rebalancing Sales                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT_BEF_REBAL_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_bk_val_plus_accr_int_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale (t)
	   + accr_int_bef_rebal_sale (t);

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double EPA_ASSET_UDF::epa_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.EPA_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double EPA_ASSET_UDF::epa_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.EPA_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"cap_gain_bef_sale",t);
}



//^^^

#line 1 "cap_gain_bef_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"cap_gain_from_sale",t);
}



//^^^

#line 1 "cap_gain_from_sale.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fabs(sold_pct(t)) < rate_ratio_threshold)
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
double EPA_ASSET_UDF::epa_asset_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"cash_flow",t);
}



//^^^

#line 1 "cash_flow.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return sched_prin_pmt(t)
	   + int_pmt(t)
	   + opt_pmt(t)
	   + opt_inc(t);

}


//@@ END

//@@ START - cost_basis
// Cost Basis                                                                                             
// Column:COST_BASIS
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"cost_basis",t);
}



//^^^

#line 1 "cost_basis.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - cost_basis_accrual
// Cost Basis Accrual                                                                                             
// Column:COST_BASIS_ACCRUAL
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis_accrual(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"cost_basis_accrual",t);
}



//^^^

#line 1 "cost_basis_accrual.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis_bef_sale(t)
       + sched_prin_pmt(t)
       - cost_basis_aft_dflt(t);

}


//@@ END

//@@ START - cost_basis_aft_dflt
// Cost Basis After Defaults                                                                                             
// Column:COST_BASIS_AFT_DFLT
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"cost_basis_aft_dflt",t);
}



//^^^

#line 1 "cost_basis_aft_dflt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cost_basis(t - 1)
	   * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - cost_basis_bef_sale
// Cost Basis Before Sales                                                                                             
// Column:COST_BASIS_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis_bef_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period)
	return get_epa_value("cost_basis", t)
           * epa_pct_remaining(t);

return get_epa_value("cost_basis", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - cost_basis_dflt
// Cost Basis Default                                                                                             
// Column:COST_BASIS_DFLT
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"cost_basis_dflt",t);
}



//^^^

#line 1 "cost_basis_dflt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return cost_basis(t - 1)
	   * dflt_pct(t);

}


//@@ END

//@@ START - cost_basis_sold
// Cost Basis Sold                                                                                             
// Column:COST_BASIS_SOLD
//========================================================
double EPA_ASSET_UDF::epa_asset_cost_basis_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"cost_basis_sold",t);
}



//^^^

#line 1 "cost_basis_sold.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_date(int t) {
//^^^



//^^^

#line 1 "date.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_dflt_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"dflt_amt",t);
}



//^^^

#line 1 "dflt_amt.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

if (t == 0 && !is_asset_initialize)
	return init_dflt_amt;

if (t == 0)
	return dflt_amt(t + 1);

return (cost_basis(t - 1) + accr_int(t - 1))
	   * dflt_pct(t);

}


//@@ END

//@@ START - dflt_pct
// Default Percent                                                                                             
// Column:DFLT_PCT
//========================================================
double EPA_ASSET_UDF::epa_asset_dflt_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"dflt_pct",t);
}



//^^^

#line 1 "dflt_pct.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

double annual_dflt_pct_prelim
= (rates->get_dflt_rate(t,
		    category_id,
			EFFECTIVE_ANNUAL)); 

double annual_dflt_pct
= (max(min(round_result(ROUND_NEAR, ROUND_NEGATIVE_TOZERO,
					  annual_dflt_pct_prelim,
					  DECIMALS_TO_ROUND), 1.0), 0.0));

return 1.0 - pow(1.0 - annual_dflt_pct, (1.0 / 12.0));

}


//@@ END

//@@ START - dur_val
// Duration Value                                                                                             
// Column:DUR_VAL
//========================================================
double EPA_ASSET_UDF::epa_asset_dur_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"dur_val",t);
}



//^^^

#line 1 "dur_val.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return eff_dur(t);

}


//@@ END

//@@ START - eff_dur
// Effective Duration                                                                                             
// Column:EFF_DUR
//========================================================
double EPA_ASSET_UDF::epa_asset_eff_dur(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"eff_dur",t);
}



//^^^

#line 1 "eff_dur.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return get_epa_value("eff_dur", t);

}


//@@ END

//@@ START - epa_pct_remaining
// Externally Projected Assets Percent Remaining                                                                                             
// Column:EPA_PCT_REMAINING
//========================================================
double EPA_ASSET_UDF::epa_asset_epa_pct_remaining(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"epa_pct_remaining",t);
}



//^^^

#line 1 "epa_pct_remaining.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (t == commencement_period)
	return pct_to_use_mp;

return epa_pct_remaining(t - 1)
	   * remaining_pct_aft_dflt(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double EPA_ASSET_UDF::epa_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.EPA_ASSET.for"
if (time_step_flag && !valn_flag
	&& proj_set_sub_loop_num < valn_periods.size())
	write_state_of_world_mp();

return 1.0;

}


//@@ END

//@@ START - gaap_inc_bk_val
// GAAP Income Book Value                                                                                             
// Column:GAAP_INC_BK_VAL
//========================================================
double EPA_ASSET_UDF::epa_asset_gaap_inc_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"gaap_inc_bk_val",t);
}



//^^^

#line 1 "gaap_inc_bk_val.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_gaap_inc_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(45,"gaap_inc_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_inc_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - gaap_surp_bk_val
// GAAP Surplus Book Value                                                                                             
// Column:GAAP_SURP_BK_VAL
//========================================================
double EPA_ASSET_UDF::epa_asset_gaap_surp_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"gaap_surp_bk_val",t);
}



//^^^

#line 1 "gaap_surp_bk_val.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_unrealzd_cap_gain_incr.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_imr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(48,"imr_realzd_cap_gain",t);
}



//^^^

#line 1 "imr_realzd_cap_gain.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return realzd_cap_gain_opt_pmt(t);

}


//@@ END

//@@ START - imr_realzd_cap_gain_from_sale
// Interest Maintenance Reserve Realized Capital Gains from Sales                                                                                             
// Column:IMR_REALZD_CAP_GAIN_FROM_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_imr_realzd_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"imr_realzd_cap_gain_from_sale",t);
}



//^^^

#line 1 "imr_realzd_cap_gain_from_sale.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - imr_yrs_to_maturity
// Interest Maintenance Reserve Years to Maturity                                                                                             
// Column:IMR_YRS_TO_MATURITY
//========================================================
double EPA_ASSET_UDF::epa_asset_imr_yrs_to_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"imr_yrs_to_maturity",t);
}



//^^^

#line 1 "imr_yrs_to_maturity.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return get_epa_value("yrs_to_maturity", t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double EPA_ASSET_UDF::epa_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.EPA_ASSET.for"
if (isMainModel)
	{
	static int loaded_proj_task_loop = -999;

	if (loaded_proj_task_loop != proj_task_loop_num)
		{
		rates->initialize(t);
		
		loaded_proj_task_loop = proj_task_loop_num;
		}
	}

// capture initial yield numerator and defaults amount
if (is_first_proj_task_loop || num_of_proj_task_loops == 0)
	{
	is_asset_initialize = 1;

	init_yld_numer = yld_numer(0);
	init_dflt_amt = dflt_amt(0);
	
	is_asset_initialize = 0;
	}	

return 1.0;

}


//@@ END

//@@ START - int_div_and_rent
// Interest Dividend and Rent                                                                                             
// Column:INT_DIV_AND_RENT
//========================================================
double EPA_ASSET_UDF::epa_asset_int_div_and_rent(int t) {
//^^^



//^^^

#line 1 "int_div_and_rent.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_int_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(53,"int_pmt",t);
}



//^^^

#line 1 "int_pmt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("int_pmt", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - mkt_to_bk_ratio
// Market to Book Ratio                                                                                             
// Column:MKT_TO_BK_RATIO
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "mkt_to_bk_ratio.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_mkt_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"mkt_val",t);
}



//^^^

#line 1 "mkt_val.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return mkt_val_bef_neg_cash_flow_sale(t)
	   * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - mkt_val_bef_fund_match_sale
// Market Value Before Fund Value Matching Asset Sales                                                                                             
// Column:MKT_VAL_BEF_FUND_MATCH_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"mkt_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "mkt_val_bef_fund_match_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return mkt_val_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - mkt_val_bef_neg_cash_flow_sale
// Market Value Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return mkt_val_bef_rebal_sale(t)
       * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - mkt_val_bef_rebal_sale
// Market Value Before Rebalancing Sales                                                                                             
// Column:MKT_VAL_BEF_REBAL_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return mkt_val_bef_fund_match_sale(t)
       * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - mkt_val_bef_sale
// Market Value Before Sales                                                                                             
// Column:MKT_VAL_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period)
	return get_epa_value("mkt_val", t)
	       * epa_pct_remaining(t);

return get_epa_value("mkt_val", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - mkt_val_for_dur_bef_neg_cash_flow_sale
// Market Value for Duration Before Negative Cash Flow Sales                                                                                             
// Column:MKT_VAL_FOR_DUR_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"mkt_val_for_dur_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"mkt_val_for_dur_bef_rebal_sale",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(62,"mkt_val_for_dur_sold",t);
}



//^^^

#line 1 "mkt_val_for_dur_sold.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_mkt_val_for_eff_dur(int t) {
//^^^



//^^^

#line 1 "mkt_val_for_eff_dur.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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

//@@ START - mkt_val_sold
// Market Value Sold                                                                                             
// Column:MKT_VAL_SOLD
//========================================================
double EPA_ASSET_UDF::epa_asset_mkt_val_sold(int t) {
//^^^



//^^^

#line 1 "mkt_val_sold.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_mkt_val_times_dur_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double EPA_ASSET_UDF::epa_asset_mkt_val_times_dur_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_dur_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double EPA_ASSET_UDF::epa_asset_mkt_val_times_eff_dur(int t) {
//^^^



//^^^

#line 1 "mkt_val_times_eff_dur.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return mkt_val_for_eff_dur(t)
	   * eff_dur(t);

}


//@@ END

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double EPA_ASSET_UDF::epa_asset_notional_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"notional_amt",t);
}



//^^^

#line 1 "notional_amt.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return notional_amt_bef_neg_cash_flow_sale(t)
       * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - notional_amt_bef_fund_match_sale
// Notional Amount Before Fund Value Matching Asset Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_FUND_MATCH_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_notional_amt_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"notional_amt_bef_fund_match_sale",t);
}



//^^^

#line 1 "notional_amt_bef_fund_match_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_notional_amt_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_neg_cash_flow_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_notional_amt_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_rebal_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_notional_amt_bef_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period)
	return get_epa_value("notional_amt", t)
	       * epa_pct_remaining(t);

return get_epa_value("notional_amt", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - opt_inc
// Option Income                                                                                             
// Column:OPT_INC
//========================================================
double EPA_ASSET_UDF::epa_asset_opt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(73,"opt_inc",t);
}



//^^^

#line 1 "opt_inc.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("opt_inc", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double EPA_ASSET_UDF::epa_asset_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(74,"opt_pmt",t);
}



//^^^

#line 1 "opt_pmt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("opt_pmt", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - rbc_c1
// Risk Based Capital C1                                                                                             
// Column:RBC_C1
//========================================================
double EPA_ASSET_UDF::epa_asset_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(75,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_rbc_c1_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"rbc_c1_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_bef_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"realzd_cap_gain",t);
}



//^^^

#line 1 "realzd_cap_gain.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return + realzd_cap_gain_opt_pmt(t)
	   - realzd_cap_loss_dflt(t);

}


//@@ END

//@@ START - realzd_cap_gain_opt_pmt
// Realized Capital Gain from Option Payment                                                                                             
// Column:REALZD_CAP_GAIN_OPT_PMT
//========================================================
double EPA_ASSET_UDF::epa_asset_realzd_cap_gain_opt_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(78,"realzd_cap_gain_opt_pmt",t);
}



//^^^

#line 1 "realzd_cap_gain_opt_pmt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("realzd_cap_gain_opt_pmt", t)
       * epa_pct_remaining(t - 1)
       * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gain from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_realzd_cap_gain_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(79,"realzd_cap_gain_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_realzd_cap_loss_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(80,"realzd_cap_loss_dflt",t);
}



//^^^

#line 1 "realzd_cap_loss_dflt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return dflt_amt(t);

}


//@@ END

//@@ START - remaining_pct_aft_dflt
// Remaining Percent After Defaults                                                                                             
// Column:REMAINING_PCT_AFT_DFLT
//========================================================
double EPA_ASSET_UDF::epa_asset_remaining_pct_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(81,"remaining_pct_aft_dflt",t);
}



//^^^

#line 1 "remaining_pct_aft_dflt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return 1.0;

return 1.0 - dflt_pct(t);

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double EPA_ASSET_UDF::epa_asset_sched_prin_pmt(int t) {
//^^^



//^^^

#line 1 "sched_prin_pmt.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("sched_prin_pmt", t)
	   * epa_pct_remaining(t - 1)
	   * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - sold_pct
// Sold Percent                                                                                             
// Column:SOLD_PCT
//========================================================
double EPA_ASSET_UDF::epa_asset_sold_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(83,"sold_pct",t);
}



//^^^

#line 1 "sold_pct.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

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
double EPA_ASSET_UDF::epa_asset_sold_pct_fund_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(84,"sold_pct_fund_match",t);
}



//^^^

#line 1 "sold_pct_fund_match.EPA_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_neg_cash_flow
// Sold Percent Negative Cash Flow                                                                                             
// Column:SOLD_PCT_NEG_CASH_FLOW
//========================================================
double EPA_ASSET_UDF::epa_asset_sold_pct_neg_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(85,"sold_pct_neg_cash_flow",t);
}



//^^^

#line 1 "sold_pct_neg_cash_flow.EPA_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_planned
// Sold Percent Planned                                                                                             
// Column:SOLD_PCT_PLANNED
//========================================================
double EPA_ASSET_UDF::epa_asset_sold_pct_planned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(86,"sold_pct_planned",t);
}



//^^^

#line 1 "sold_pct_planned.EPA_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_rebal
// Sold Percent Rebalancing                                                                                             
// Column:SOLD_PCT_REBAL
//========================================================
double EPA_ASSET_UDF::epa_asset_sold_pct_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(87,"sold_pct_rebal",t);
}



//^^^

#line 1 "sold_pct_rebal.EPA_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double EPA_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.EPA_ASSET.for"
#if 0 // START_EXTERNS
extern sowmpoutput epa_state_of_world_mp_output;
extern bool is_asset_initialize;
const int EPV_ACCR_INT = 0;
const int EPV_COST_BASIS = 1;
const int EPV_BK_VAL = 2;
const int EPV_NOTIONAL_AMT = 3;
const int EPV_OPT_INC = 4;
const int EPV_OPT_PMT = 5;
const int EPV_INT_PMT = 6;
const int EPV_MKT_VAL = 7;
const int EPV_EFF_DUR = 8;
const int EPV_REALZD_CAP_GAIN_OPT_PMT = 9;
const int EPV_SCHED_PRIN_PMT = 10;
const int EPV_YRS_TO_MATURITY = 11;
const int EPV_WEIGHTED_AVG_LIFE = 12;
const int EPV_NUM_VALUES = 13;
map <xstring, int, less <xstring> > tas_epa_fields;
#endif // END_EXTERNS

#if 0 // START_CLASS
int sequence_id;
Schedule * EPAData;
int epa_last_cash_flow_period;
bool no_cash_flows_in_epa_file;
SmartArray <SmartArray <double> > epa_values;
double init_yld_numer;
double init_dflt_amt;
StrEnum::EnumValue port_defn;
map <xstring, long, less <xstring> > sched_byte_pos;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
sequence_id = 0;
epa_last_cash_flow_period = -1;
no_cash_flows_in_epa_file = false;
init_yld_numer = 0.0;
init_dflt_amt = 0.0;
port_defn = INVESTMENT;
#endif // END_CONSTRUCTOR

if (use_mp == NO)
	{
	skipModelPoint();
	return 1;
	}

if (fabs(pct_to_use_mp) < rate_ratio_threshold)
	{
	skipModelPoint();
	return 1;
	}

if (isMainModel)
	{
	// set stoch_flag for rates loading
	stoch_flag = true;

	#if defined(ASSET_ONLY_MODEL)
	rates = sm_epa_rates;
	#endif
	last_proj_period = last_model_period;
	}	
else	
	{
	#if defined(ASSET_ONLY_MODEL)
	if (sm_epa_rates && !sm_epa_rates->isShrunk)
		sm_epa_rates->shrink();
	#endif

	rates = asset->rates;
	}

// Data Validation
if (num_of_proj_task_loops == 0 
	|| is_first_proj_task_loop
	|| restore_variables_ind == 1)
	validate_data();

return 1.0;

}


//@@ END

//@@ START - sub_port_id
// Asset Sub Portfolio Identification                                                                                             
// Column:SUB_PORT_ID
//========================================================
double EPA_ASSET_UDF::epa_asset_sub_port_id(int t) {
//^^^



//^^^

#line 1 "sub_port_id.EPA_ASSET.for"
if (t < commencement_period || isMainModel)
	return NO_AVG;

double dur_for_transfer = 0;

if (t <= maturity_period)
	{
	if (asset->asset_sub_port_assign_dur_defn == YEARS_TO_MATURITY)
		dur_for_transfer = get_epa_value("yrs_to_maturity", t);

	else if (asset->asset_sub_port_assign_dur_defn == EFFECTIVE_DURATION)
		dur_for_transfer = eff_dur(t);

	else //if (asset->sub_port_assign_dur == WEIGHTED_AVERAGE_LIFE)
		dur_for_transfer = weighted_avg_life(t);
	}

if (t == 0)
	return asset->asset_sub_port_assign(t, 1, asset_defn,
					port_defn,
					category_id,
					1, // existing_asset_flag
					dur_for_transfer,
					-1);

return asset->asset_sub_port_assign(t, 0, asset_defn,
					port_defn,
					category_id,
					1, // existing_asset_flag
					dur_for_transfer,
					sub_port_id(t - 1));

}


//@@ END

//@@ START - tax_exempt_inc
// Tax Exempt Income                                                                                             
// Column:TAX_EXEMPT_INC
//========================================================
double EPA_ASSET_UDF::epa_asset_tax_exempt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(90,"tax_exempt_inc",t);
}



//^^^

#line 1 "tax_exempt_inc.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return get_epa_value("tax_exempt_inc", t);

}


//@@ END

//@@ START - unrealzd_cap_gain
// Unrealized Capital Gain                                                                                             
// Column:UNREALZD_CAP_GAIN
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(91,"unrealzd_cap_gain",t);
}



//^^^

#line 1 "unrealzd_cap_gain.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_neg_cash_flow_sale(t)
       * (1.0 - sold_pct_neg_cash_flow(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_fund_match_sale
// Unrealized Capital Gain Before Fund Value Matching Asset Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_FUND_MATCH_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"unrealzd_cap_gain_bef_fund_match_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_fund_match_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t)
	   * (1.0 - sold_pct_planned(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_neg_cash_flow_sale
// Unrealized Capital Gain Before Negative Cash Flow Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"unrealzd_cap_gain_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_neg_cash_flow_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_rebal_sale(t)
	   * (1.0 - sold_pct_rebal(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_rebal_sale
// Unrealized Capital Gain Before Rebalancing Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_REBAL_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"unrealzd_cap_gain_bef_rebal_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_rebal_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_fund_match_sale(t)
	   * (1.0 - sold_pct_fund_match(t));

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_sale
// Unrealized Capital Gain Before Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_bef_sale.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_sale(t) - cost_basis_bef_sale(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_gaap_surp
// Unrealized Capital Gain GAAP Surplus                                                                                             
// Column:UNREALZD_CAP_GAIN_GAAP_SURP
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_gaap_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(96,"unrealzd_cap_gain_gaap_surp",t);
}



//^^^

#line 1 "unrealzd_cap_gain_gaap_surp.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_surp_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr.EPA_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t)
	   - unrealzd_cap_gain(t - 1);

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released on Sale                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_released_on_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"unrealzd_cap_gain_released_on_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.EPA_ASSET.for"
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
double EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_to_bk_ratio.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
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
double EPA_ASSET_UDF::epa_asset_weighted_avg_life(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(100,"weighted_avg_life",t);
}



//^^^

#line 1 "weighted_avg_life.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (asset_defn == EQUITY)
	return NO_AVG;

return get_epa_value("weighted_avg_life", t);

}


//@@ END

//@@ START - yld_denom
// Yield Denominator                                                                                             
// Column:YLD_DENOM
//========================================================
double EPA_ASSET_UDF::epa_asset_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"yld_denom",t);
}



//^^^

#line 1 "yld_denom.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0)
	return bk_val(t) + accr_int(t);

return bk_val(t - 1) +  accr_int(t - 1);

}


//@@ END

//@@ START - yld_numer
// Yield Numerator                                                                                             
// Column:YLD_NUMER
//========================================================
double EPA_ASSET_UDF::epa_asset_yld_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(102,"yld_numer",t);
}



//^^^

#line 1 "yld_numer.EPA_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && !is_asset_initialize)
	return init_yld_numer;

if (t == 0)
	return accr_inc(t + 1);	

return accr_inc(t);

}


//@@ END

//@@ START - asset_fund_index
// Asset Fund Index                                                                                             
// Calculated Variable:ASSET_FUND_INDEX
//========================================================
int EPA_ASSET_UDF::epa_asset_asset_fund_index() {
//^^^


#line 1 "asset_fund_index.EPA_ASSET.for"
if (port_defn == INVESTMENT)
	return INVESTMENT_FUND_INDEX;

// else set to "Investment" default value
makeRunLogYellow();
log_screen << "Warning: Invalid portfolio definition (" << port_defn
		   <<") for EPA ID = " << asset_id
		   << "." << MSG_ERROR;
log_screen << " ... Portfolio definition has been reset to Investment. " << MSG_ERROR;

port_defn = INVESTMENT;

return INVESTMENT_FUND_INDEX;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int EPA_ASSET_UDF::epa_asset_commencement_period() {
//^^^


#line 1 "commencement_period.EPA_ASSET.for"
return 0;

}


//@@ END

//@@ START - data_grp_id
// Data Group Identification                                                                                             
// Calculated Variable:DATA_GRP_ID
//========================================================
xstring EPA_ASSET_UDF::epa_asset_data_grp_id() {
//^^^


#line 1 "data_grp_id.EPA_ASSET.for"
return get_base_group_name(group, true);//WTW - Gen2 - Move Extern definitions to rates header

}


//@@ END

//@@ START - gaap_inc_defn
// GAAP Income Definition                                                                                             
// Calculated Variable:GAAP_INC_DEFN
//========================================================
int EPA_ASSET_UDF::epa_asset_gaap_inc_defn() {
//^^^


#line 1 "gaap_inc_defn.EPA_ASSET.for"
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
int EPA_ASSET_UDF::epa_asset_gaap_val_defn() {
//^^^


#line 1 "gaap_val_defn.EPA_ASSET.for"
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

//@@ START - maturity_period
// Maturity Period                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int EPA_ASSET_UDF::epa_asset_maturity_period() {
//^^^


#line 1 "maturity_period.EPA_ASSET.for"
return epa_last_cash_flow_period - proj_date_offset;

}


//@@ END

//@@ START - neg_asset_flag
// Negative Asset Flag                                                                                             
// Calculated Variable:NEG_ASSET_FLAG
//========================================================
int EPA_ASSET_UDF::epa_asset_neg_asset_flag() {
//^^^


#line 1 "neg_asset_flag.EPA_ASSET.for"
if (notional_amt_bef_sale(0) < 0.0)
	return -1;

return 1;

}


//@@ END

//@@ START - pct_to_use
// Percent to Use                                                                                             
// Calculated Variable:PCT_TO_USE
//========================================================
double EPA_ASSET_UDF::epa_asset_pct_to_use() {
//^^^


#line 1 "pct_to_use.EPA_ASSET.for"
if (!isMainModel)
	return seg->existing_asset_pct_to_use;

return pct_to_use_mp;

}


//@@ END

//@@ START - planned_sale_period
// Planned Sale Period                                                                                             
// Calculated Variable:PLANNED_SALE_PERIOD
//========================================================
int EPA_ASSET_UDF::epa_asset_planned_sale_period() {
//^^^


#line 1 "planned_sale_period.EPA_ASSET.for"
return min(get_yr_from_date(planned_sale_date) - proj_start_yr,
		       MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
	       + get_mth_from_date(planned_sale_date) - proj_start_mth + 1;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring EPA_ASSET_UDF::epa_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.EPA_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_date_offset
// Projection Date Offset                                                                                             
// Calculated Variable:PROJ_DATE_OFFSET
//========================================================
int EPA_ASSET_UDF::epa_asset_proj_date_offset() {
//^^^


#line 1 "proj_date_offset.EPA_ASSET.for"
if ((time_step_flag && valn_flag)
	|| proj_set_loop_num == 0)
	return 0;

return valn_period;

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int EPA_ASSET_UDF::epa_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.EPA_ASSET.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int EPA_ASSET_UDF::epa_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.EPA_ASSET.for"
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
int EPA_ASSET_UDF::epa_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.EPA_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - sale_class_id
// Sale Class Identification                                                                                             
// Calculated Variable:SALE_CLASS_ID
//========================================================
int EPA_ASSET_UDF::epa_asset_sale_class_id() {
//^^^


#line 1 "sale_class_id.EPA_ASSET.for"
return sale_class.ord();

}


//@@ END

//@@ START - seg_num
// Segment Number                                                                                             
// Calculated Variable:SEG_NUM
//========================================================
int EPA_ASSET_UDF::epa_asset_seg_num() {
//^^^


#line 1 "seg_num.EPA_ASSET.for"
if (isMainModel)
	return 0;

return seg->getElementNumber();

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int EPA_ASSET_UDF::epa_asset_start_period() {
//^^^


#line 1 "start_period.EPA_ASSET.for"
return max(0, commencement_period);

}


//@@ END


#line 1 "get_epa_value.EPA_ASSET.for"                                                                                   
double EPA_ASSET::get_epa_value(const xstring &col_name, int t)
{
if (epa_file_defn == SCHEDULE_FILE)
	return EPAData->getvalue(t + proj_date_offset, col_name, 1);

return epa_values[t + proj_date_offset][tas_epa_fields[col_name]];
}



#line 1 "read_epa_file.EPA_ASSET.for"                                                                                   
bool EPA_ASSET::read_epa_file(const xstring &epa_file)
{
bool read_ok;

if (epa_file_defn == SCHEDULE_FILE)
	read_ok = read_epa_schedule(epa_file);

else
	read_ok = read_tas_epa_file(epa_file);

return read_ok;
}



#line 1 "read_epa_schedule.EPA_ASSET.for"                                                                                   
bool EPA_ASSET::read_epa_schedule(const xstring &epa_file)
{
xstring sched_val;

if (!time_step_flag 
	|| (time_step_flag && valn_flag))
 	sched_val = xstring(proj_task_loop_num);
else
	sched_val = proj_set_loop_num;

if (is_first_proj_task_loop || num_of_proj_task_loops == 0)
	{
	EPAData = new Schedule;
	set_sched_byte_markers(epa_file);
	}

if (!EPAData->is_open())
	EPAData->open(epa_file, ',', true);

int byte_pos = sched_byte_pos[sched_val];
EPAData->read(sched_val, byte_pos, 1);		

if (LOOKUP_FAILED > 0 && LOOKUP_FAILED < 6)
	return false; 

epa_last_cash_flow_period = EPAData->numrows - 1;

// Check for expired EPA file
if (epa_last_cash_flow_period < last_proj_period)
	{
	double epa_data_notional_amt 
	= EPAData->getvalue(epa_last_cash_flow_period, "notional_amt", 1);
	
	if (fabs(epa_data_notional_amt) > model_point_amount_threshold)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed);
		log_screen << "Warning. EPA Cash Flows for "
				   << epa_file
				   << MSG_ERROR;
		log_screen << " ... have terminated at t=" << epa_last_cash_flow_period
				   << " before the EPA asset has matured." << MSG_ERROR;
		log_screen << " ... The statutory balance sheet may be out of balance"
				   << " or cash flows and cost basis growth may be incorrect."
				   << MSG_ERROR;
		log_screen << " ... These problems can be corrected by regenerating"
				   << " this EPA file."
				   << MSG_ERROR;
		log_screen.unsetf(ios::fixed);
	
		return false;
		}
	}

return true;
}



#line 1 "read_tas_epa_file.EPA_ASSET.for"                                                                                   
bool EPA_ASSET::read_tas_epa_file(const xstring &epa_file)
{
int epa_asset_defn;
int epa_model_start_year;
int epa_model_start_month;
int fieldno = 0;
int t = 0;
int epa_inv_calc;
int epa_dflts_calc;
int epa_rbc_calc;
int epa_sales_class;
int epa_alt_acct;
char core_version[6];
char app_version[6];
char ctry_version[6];
char client_version[6];
char description[255];
char epa_scen_file_name[100];
char epa_category[100];
ifstream epa_data_file;
bool issue_warning = true;
																//
// EPA input data   											//	   proj msd
double epa_data_temp = 0;										// temporary storage location
double epa_data_accr_int = 0;  									// field  3   1
double epa_data_cost_basis = 0; 								// field  4   8
double epa_data_bk_val = 0; 									// field  6   2
double epa_data_notional_amt = 0;   							// field  7   6
double epa_data_opt_inc = 0;		  							// field  8
double epa_data_opt_pmt = 0;									// field  9
double epa_data_int_pmt = 0; 			  						// field 13
double epa_data_mkt_val = 0;									// field 14   4
double epa_data_eff_dur = 0;									// field 15   5
double epa_data_realzd_cap_gain_opt_pmt = 0;					// field 16
double epa_data_sch_prin_pmt = 0;								// field 18
double epa_data_yrs_to_mat = 0; 								// field 25  10
double epa_data_weighted_avg_life = 0;  						// field 27   9

no_cash_flows_in_epa_file = false;
epa_last_cash_flow_period = -1;

static bool first_time = true;
if (first_time)
	{
	tas_epa_fields["accr_int"] = EPV_ACCR_INT;
	tas_epa_fields["cost_basis"] = EPV_COST_BASIS;
	tas_epa_fields["bk_val"] = EPV_BK_VAL;
	tas_epa_fields["notional_amt"] = EPV_NOTIONAL_AMT;
	tas_epa_fields["opt_inc"] = EPV_OPT_INC;
	tas_epa_fields["opt_pmt"] = EPV_OPT_PMT;
	tas_epa_fields["int_pmt"] = EPV_INT_PMT;
	tas_epa_fields["mkt_val"] = EPV_MKT_VAL;
	tas_epa_fields["eff_dur"] = EPV_EFF_DUR;
	tas_epa_fields["realzd_cap_gain_opt_pmt"] = EPV_REALZD_CAP_GAIN_OPT_PMT;
	tas_epa_fields["sched_prin_pmt"] = EPV_SCHED_PRIN_PMT;
	tas_epa_fields["yrs_to_maturity"] = EPV_YRS_TO_MATURITY;
	tas_epa_fields["weighted_avg_life"] = EPV_WEIGHTED_AVG_LIFE;
	}

// create epa file name
char temp_epa_ext[4];
xstring epa_id = "";
xstring epa_ext = "";
int iteration;

if (!time_step_flag 
	|| (time_step_flag && valn_flag))
	iteration = proj_task_loop_num;
else
	iteration = proj_set_loop_num;	

for (int loop = 0; loop < 3; loop++)
	{
	if (iteration < 1000)
		{
		switch (loop)
			{
			case 0:
				sprintf(temp_epa_ext, "%03d", iteration);
				epa_ext = (const char *) temp_epa_ext;
				break;
			case 1:
				sprintf(temp_epa_ext, "%d", iteration);
				epa_ext = (const char *) temp_epa_ext;
				break;
			case 2:
				epa_ext = "ALL";
				break;
			}
		}
	else
		epa_ext = xstring(iteration);

	epa_id = epa_file(0, epa_file.find_last_of(".")) + "." + epa_ext;

	// Adjust file extension of the EPA file as required
	if (!access(epa_id, 0)) // file with iteration number extension exists so use it
		break;
	}

// Open and read file
epa_data_file.open(epa_id); 

if (!epa_data_file.is_open())
	{
	makeRunLogYellow();
	log_screen << "Error. Could not open EPA File " << epa_id
			<< MSG_ERROR;

	return false;
	}

// version nums etc.
epa_data_file >> core_version >> app_version >> ctry_version >> client_version;

// description
epa_data_file.getline(description,255).getline(description,255);

// file characteristics
epa_data_file >> epa_asset_defn;
epa_data_file >> epa_scen_file_name;
epa_data_file >> epa_model_start_year;
epa_data_file >> epa_model_start_month;
epa_data_file >> epa_category;
epa_data_file >> epa_inv_calc;
epa_data_file >> epa_dflts_calc;
epa_data_file >> epa_rbc_calc;
epa_data_file >> epa_sales_class;
epa_data_file >> epa_alt_acct;

if (epa_asset_defn != BOND_CODE
	&& epa_asset_defn != MORTGAGE_CODE
	&& epa_asset_defn != SEC_CODE
	&& epa_asset_defn != IRD_CODE
	&& epa_asset_defn != EQUITY_CODE)
	{
	makeRunLogYellow();
	log_screen.setf(ios::fixed);
	log_screen << "Warning: The US Library only supports Bond, Mortgage, Securitized asset, "
			   << "Interest rate derivative, and Equity EPA files. "
			   << "EPA file " << epa_id << " has been discarded." << MSG_ERROR;
	log_screen.unsetf(ios::fixed);

	epa_data_file.close(); 
	return false;
	}


if (epa_alt_acct == 999)
	{
	makeRunLogYellow();
	log_screen.setf(ios::fixed);
	log_screen << "Warning: The US Library does not support the alternate accounting EPA format. "
			   << "EPA file " << epa_id << " has been discarded." << MSG_ERROR;
	log_screen.unsetf(ios::fixed);

	epa_data_file.close(); 
	return false;
	}

// reading the epa monthly data for t periods 0 to last_proj_period
// when EOF, fill data array and columns with zeros
if (is_first_proj_task_loop || num_of_proj_task_loops == 0
	|| restore_variables_ind == 1)
	{
	if (epa_values.size() < valn_period + last_proj_period + 1)
		epa_values.resize(valn_period + last_proj_period + 1);

	for (int row = 0; row <= valn_period + last_proj_period; row++)
		{
		if (epa_values[row].size() < EPV_NUM_VALUES)
			epa_values[row].resize(EPV_NUM_VALUES);		
		}
	}

// initialize values to zero
for (int row = 0; row <= valn_period + last_proj_period; row++)
	{
	for (int col = 0; col < EPV_NUM_VALUES; col++)
		epa_values[row][col] = 0.0;
	}

while (t <= valn_period + last_proj_period)
	{
	if (t == 0)
		{
		if (!epa_data_file.eof())
			{
			// EPA model start  date values 					//	   proj msd
			epa_data_file >> epa_data_accr_int;		 			 // field  3   1
			epa_data_file >> epa_data_bk_val;						// field  6   2
			epa_data_file >> epa_data_temp; 		  			   // field  2   3
			epa_data_file >> epa_data_mkt_val;   					// field 14   4
			epa_data_file >> epa_data_eff_dur;   					// field 15   5
			epa_data_file >> epa_data_notional_amt;  				// field  7   6
			epa_data_file >> epa_data_temp;				          // field  1	  7
			epa_data_file >> epa_data_cost_basis;					// field  4   8
			epa_data_file >> epa_data_weighted_avg_life; 			// field 27   9
			epa_data_file >> epa_data_yrs_to_mat;					// field 25  10
			epa_data_file >> epa_data_temp;					 	 // field 24  11

			if (!epa_data_file.eof())
				epa_last_cash_flow_period = t;

			if (atof(app_version) >= 3.0)
				{
				// may have to reset version to 2.0 for BondEdge EPA files
				int pos = 0;
				double temp = 0;
				char cchar;
				pos = epa_data_file.tellg();	// save current file position
				for (fieldno = 0; fieldno < 27; fieldno++)
					epa_data_file >> temp;
				cchar = epa_data_file.get();
				if (cchar != ' ' && cchar != '\t') // there are 27 fields
					strcpy(app_version,"2.00");
				epa_data_file.seekg(pos);	// restore file position
				}
			}
		else // eof
			{
			no_cash_flows_in_epa_file = true;

			makeRunLogYellow();
			log_screen.setf(ios::fixed);
			log_screen << "Warning: No cash flows in EPA file " << epa_id
					   << ". This EPA file has been discarded." << MSG_ERROR;
			log_screen.unsetf(ios::fixed);

			epa_data_file.close(); 
			return false;
			}

		// accr_int
		epa_values[t][EPV_ACCR_INT]
		= epa_data_accr_int;

		// cost_basis
		if (epa_data_cost_basis > 0)
			epa_values[t][EPV_COST_BASIS]
			= epa_data_cost_basis;
		else
			epa_values[t][EPV_COST_BASIS]
			= epa_data_bk_val;

		// bk_val
		epa_values[t][EPV_BK_VAL]
		= epa_data_bk_val;

		// mkt_val
		epa_values[t][EPV_MKT_VAL]
		= epa_data_mkt_val;

		// eff_dur
		epa_values[t][EPV_EFF_DUR]
		= epa_data_eff_dur;

		// notional_amt
		epa_values[t][EPV_NOTIONAL_AMT]
		= epa_data_notional_amt;

		if (epa_asset_defn == IRD_CODE
			&& fabs(epa_values[t][EPV_NOTIONAL_AMT]) < model_point_amount_threshold
			&& fabs(epa_values[t][EPV_BK_VAL]) >= model_point_amount_threshold)
			{
			epa_values[t][EPV_NOTIONAL_AMT] = epa_values[t][EPV_BK_VAL];

			makeRunLogYellow();
			log_screen.setf(ios::fixed);
			log_screen << "Warning: EPA interest rate derivative notional_amt"
					   << " at projection date is zero in the EPA file " << epa_id
					   << ". Initial notional_amt has been set to"
					   << " initial bk_val (" << epa_values[t][EPV_BK_VAL]
					   << "." << MSG_ERROR;
			log_screen.unsetf(ios::fixed);
			}

		// weighted_avg_life
		epa_values[t][EPV_WEIGHTED_AVG_LIFE]
		= epa_data_weighted_avg_life;

		// yrs_to_maturity
		epa_values[t][EPV_YRS_TO_MATURITY]
		= epa_data_yrs_to_mat;
		}
	else // t > 0
		{
		// must read first field to get to eof
		// EPA projected values 												//	   proj msd
		epa_data_file >> epa_data_temp; 							    		  	// field  1   7

		if (!epa_data_file.eof())
			{
			epa_data_file >> epa_data_temp;		   								// field  2   3
			epa_data_file >> epa_data_accr_int;			 					  	// field  3   1
			epa_data_file >> epa_data_cost_basis;								 	// field  4   8
			epa_data_file >> epa_data_temp;									   	// field  5
			epa_data_file >> epa_data_bk_val;									 	// field  6   2
			epa_data_file >> epa_data_notional_amt;  							 	// field  7   6
			epa_data_file >> epa_data_opt_inc;		 						   	// field  8
			epa_data_file >> epa_data_opt_pmt;				   				 	// field  9
			epa_data_file >> epa_data_temp;									   	// field 10
			epa_data_file >> epa_data_temp;				 					  	// field 11
			epa_data_file >> epa_data_temp;			 						  	// field 12
			epa_data_file >> epa_data_int_pmt; 			 					  	// field 13
			epa_data_file >> epa_data_mkt_val;   								 	// field 14   4
			epa_data_file >> epa_data_eff_dur;   								 	// field 15   5
			epa_data_file >> epa_data_realzd_cap_gain_opt_pmt;						// field 16
			epa_data_file >> epa_data_temp;					 				  	// field 17
			epa_data_file >> epa_data_sch_prin_pmt;			   			        // field 18
			epa_data_file >> epa_data_temp;										   // field 19
			epa_data_file >> epa_data_temp;										   // field 20
			epa_data_file >> epa_data_temp;										   // field 21
			epa_data_file >> epa_data_temp;		   								// field 22
			epa_data_file >> epa_data_temp;				  						 // field 23
			epa_data_file >> epa_data_temp;					 					  // field 24  11
			epa_data_file >> epa_data_yrs_to_mat;									 // field 25  10
			epa_data_file >> epa_data_temp;							   			// field 26
			epa_data_file >> epa_data_weighted_avg_life; 							 // field 27   9

			if (!epa_data_file.eof())
				epa_last_cash_flow_period = t;

			// get the index asset income reinvestment if app version >= 3.0
			if (atof(app_version) >= 3.0)
				epa_data_file >> epa_data_temp;
			}
		else // at end of file
			{
			if (t == 1)
				{
				no_cash_flows_in_epa_file = true;

				makeRunLogYellow();
				log_screen.setf(ios::fixed);
				log_screen << "Warning: No cash flows in EPA file " << epa_id
						   << ". This EPA file has been discarded." << MSG_ERROR;
				log_screen.unsetf(ios::fixed);

				epa_data_file.close(); 
				return false;
				}
			else
				{
				if (fabs(epa_data_notional_amt) > model_point_amount_threshold)
					{
					makeRunLogYellow();
					log_screen.setf(ios::fixed);
					log_screen << "Warning: EPA Cash Flows for "
							<< epa_id
							<< MSG_ERROR;
					log_screen << " ... have terminated at t=" << t - 1
							<< " before the EPA asset has matured." << MSG_ERROR;
					log_screen << " ... The statutory balance sheet may be out of balance"
							<< " or cash flows and cost basis growth may be incorrect."
							<< MSG_ERROR;
					log_screen << " ... These problems can be corrected by regenerating"
							<< " this EPA file."
							<< MSG_ERROR;
					log_screen.unsetf(ios::fixed);

					epa_data_file.close(); 
	
					return false;
					}
				}

			// else initialize array values to zero
			while (t <= valn_period + last_proj_period)
				{
				for (int loop = 0; loop < EPV_NUM_VALUES; loop++)
					epa_values[t][loop] = 0;

				t++;
				}

			epa_data_file.close();

			return true;
			}

		// accr_int
		epa_values[t][EPV_ACCR_INT]
		= epa_data_accr_int;

		// cost_basis
		if (epa_data_cost_basis > 0)
			epa_values[t][EPV_COST_BASIS]
			= epa_data_cost_basis;
		else
			epa_values[t][EPV_COST_BASIS]
			= epa_data_bk_val;

		// bk_val
		epa_values[t][EPV_BK_VAL]
		= epa_data_bk_val;

		// notional_amt
		epa_values[t][EPV_NOTIONAL_AMT]
		= epa_data_notional_amt;

		// opt_inc
		epa_values[t][EPV_OPT_INC]
		= epa_data_opt_inc;

		// opt_pmt
		epa_values[t][EPV_OPT_PMT]
		= epa_data_opt_pmt;

		// int_pmt
		epa_values[t][EPV_INT_PMT]
		= epa_data_int_pmt;

		// mkt_val
		epa_values[t][EPV_MKT_VAL]
		= epa_data_mkt_val;

		// eff_dur
		epa_values[t][EPV_EFF_DUR]
		= epa_data_eff_dur;

		// realzd_cap_gain_opt_pmt
		epa_values[t][EPV_REALZD_CAP_GAIN_OPT_PMT]
		= epa_data_realzd_cap_gain_opt_pmt;

		// sched_prin_pmt
		epa_values[t][EPV_SCHED_PRIN_PMT]
		= epa_data_sch_prin_pmt;

		// yrs_to_maturity
		epa_values[t][EPV_YRS_TO_MATURITY]
		= epa_data_yrs_to_mat;

		// weighted_avg_life
		epa_values[t][EPV_WEIGHTED_AVG_LIFE]
		= epa_data_weighted_avg_life;

		if (issue_warning)
			{
			if (!epa_data_file.eof()
				&& epa_values[t][EPV_MKT_VAL] == 0
				&& epa_values[t][EPV_NOTIONAL_AMT] == 0
				&& (epa_values[t][EPV_BK_VAL]
					+ epa_values[t][EPV_INT_PMT]
					+ epa_values[t][EPV_OPT_INC]
					+ epa_values[t][EPV_OPT_PMT]) == 0)
				{
				issue_warning = false;
				makeRunLogYellow();
				log_screen << "Warning: EPA cash flow data values in the " << epa_id
						   << MSG_ERROR;
				log_screen << " ... file have gone to zero in period " << t
						   << ". The statutory balance sheet may be out of balance."
						   << MSG_ERROR;
				}
			}
		}
		
	t++;
	} // while loop

epa_data_file.close();

return true;
}



#line 1 "set_sched_byte_markers.EPA_ASSET.for"                                                                                   
void EPA_ASSET::set_sched_byte_markers(const xstring &sched_file)
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



#line 1 "validate_data.EPA_ASSET.for"                                                                                   
void EPA_ASSET::validate_data(void) 
{
if (!read_epa_file(replaceWildcards(epa_file)) && data_validation_defn == YES)
	{
	makeRunLogYellow();
	log_strm << "Warning: Unable to process epa file " << epa_file << "." 
	         << "EPA record " << asset_id << " will be skipped. Please check your data." << endl;

	skipModelPoint();
	return;
	}

return;
}



#line 1 "write_state_of_world_mp.EPA_ASSET.for"                                                                                   
void EPA_ASSET::write_state_of_world_mp(void)
{
static bool first_time = true;

xstring data_file_name = replaceWildcards(data_location());

xstring epa_state_of_world_file
= xstring(data_file_name(0, data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (first_time)
	{
	first_time = false;

	struct stat buffer;
	int stat_val = stat(epa_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(epa_state_of_world_file);
	}
 
if (!epa_state_of_world_mp_output.is_open())
	{
   	epa_state_of_world_mp_output.setf(ios::fixed);
	epa_state_of_world_mp_output.precision(12);
	epa_state_of_world_mp_output.open(epa_state_of_world_file);

	// Write header
	epa_state_of_world_mp_output	// Values from inforce mp
	<< "group" << ","				// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","			// col 1 = seg_id
	<< "asset_id_mp" << ","			// col 2 = asset_id
	<< "use_mp" << ","				// col 3 = use_mp
	<< "epa_file_defn" << ","		// col 4 = get_string_of_enum_val(epa_file_defn)
	<< "epa_file" << ","			// col 5 = epa_file
	<< "asset_defn" << ","			// col 6 = get_string_of_enum_val(asset_defn)
	<< "category_id" << ","			// col 7 = category_id
	<< "sale_class" << ","			// col 8 = get_string_of_enum_val(sale_class)
	<< "planned_sale_date" << ","	// col 9 = planned_sale_date
	<< "pct_to_use_mp" << ","		// col 10 = epa_pct_remaining(last_proj_period)
	<< "avr_contribn_pct_mp" << ","	// col 11 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","		// col 12 = avr_max_pct
	<< "avr_obj_pct_mp" << ","		// col 13 = avr_obj_pct
	<< "rbc_c1_pct_mp" << endl;		// col 14 = rbc_c1_pct
	}

static int counter = 1;
xstring group_mp = get_base_group_name(group, false);//WTW - Gen2 - Move Extern definitions to rates header
xstring epa_file_defn = get_string_of_enum_val(this->epa_file_defn);
xstring asset_defn = get_string_of_enum_val(this->asset_defn);
xstring sale_class = get_string_of_enum_val(this->sale_class);
double epa_pct_remaining = this->epa_pct_remaining(last_proj_period);

epa_state_of_world_mp_output
<< group_mp << ","
<< seg_id << ","
<< asset_id << ","
<< use_mp << ","
<< epa_file_defn << ","
<< epa_file << ","
<< asset_defn << ","
<< category_id << ","
<< sale_class << ","
<< planned_sale_date << ","
<< epa_pct_remaining << ","
<< avr_contribn_pct << ","
<< avr_max_pct << ","
<< avr_obj_pct << ","
<< rbc_c1_pct << endl;

counter++;

return;
}



	static EPA_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (EPA_ASSET_UDF::*dPXi) (int);
typedef double (EPA_ASSET_UDF::*dPXid) (int, double);
typedef double (EPA_ASSET_UDF::*dPF) ();
typedef double (EPA_ASSET_UDF::*dPFd) (double);
typedef int (EPA_ASSET_UDF::*iPF) ();
typedef int (EPA_ASSET_UDF::*iPFi) (int);
typedef xstring (EPA_ASSET_UDF::*sPF) ();
typedef xstring (EPA_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData EPA_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_inc", "epa_asset_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(2, "accr_int", "epa_asset_accr_int",  "accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int),
	CashFlowCommonData(3, "accr_int_aft_dflt", "epa_asset_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(4, "accr_int_bef_fund_match_sale", "epa_asset_accr_int_bef_fund_match_sale",  "accr_int_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_fund_match_sale),
	CashFlowCommonData(5, "accr_int_bef_neg_cash_flow_sale", "epa_asset_accr_int_bef_neg_cash_flow_sale",  "accr_int_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_neg_cash_flow_sale),
	CashFlowCommonData(6, "accr_int_bef_rebal_sale", "epa_asset_accr_int_bef_rebal_sale",  "accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_rebal_sale),
	CashFlowCommonData(7, "accr_int_bef_sale", "epa_asset_accr_int_bef_sale",  "accr_int_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_bef_sale),
	CashFlowCommonData(8, "accr_int_dflt", "epa_asset_accr_int_dflt",  "accr_int_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_dflt),
	CashFlowCommonData(9, "accr_int_rent", "epa_asset_accr_int_rent",  "accr_int_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_rent, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_rent),
	CashFlowCommonData(10, "accr_int_sold", "epa_asset_accr_int_sold",  "accr_int_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_accr_int_sold, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_sold),
	CashFlowCommonData(11, "asset_min_size_sale_flag", "epa_asset_asset_min_size_sale_flag",  "asset_min_size_sale_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_asset_min_size_sale_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_min_size_sale_flag),
	CashFlowCommonData(12, "avr_basic_contribn", "epa_asset_avr_basic_contribn",  "avr_basic_contribn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_basic_contribn, 'E','N', '3', 'C', (size_t)&modelOffset->avr_basic_contribn),
	CashFlowCommonData(13, "avr_basic_contribn_bef_sale", "epa_asset_avr_basic_contribn_bef_sale",  "avr_basic_contribn_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_basic_contribn_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_basic_contribn_bef_sale),
	CashFlowCommonData(14, "avr_max", "epa_asset_avr_max",  "avr_max",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_max, 'E','N', '3', 'C', (size_t)&modelOffset->avr_max),
	CashFlowCommonData(15, "avr_max_bef_sale", "epa_asset_avr_max_bef_sale",  "avr_max_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_max_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->avr_max_bef_sale),
	CashFlowCommonData(16, "avr_obj", "epa_asset_avr_obj",  "avr_obj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_obj, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj),
	CashFlowCommonData(17, "avr_obj_bef_sale", "epa_asset_avr_obj_bef_sale",  "avr_obj_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_obj_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj_bef_sale),
	CashFlowCommonData(18, "avr_realzd_cap_gain", "epa_asset_avr_realzd_cap_gain",  "avr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_avr_realzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->avr_realzd_cap_gain),
	CashFlowCommonData(19, "bk_val", "epa_asset_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(20, "bk_val_bef_fund_match_sale", "epa_asset_bk_val_bef_fund_match_sale",  "bk_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_fund_match_sale),
	CashFlowCommonData(21, "bk_val_bef_neg_cash_flow_sale", "epa_asset_bk_val_bef_neg_cash_flow_sale",  "bk_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(22, "bk_val_bef_rebal_sale", "epa_asset_bk_val_bef_rebal_sale",  "bk_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_rebal_sale),
	CashFlowCommonData(23, "bk_val_bef_sale", "epa_asset_bk_val_bef_sale",  "bk_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_bef_sale),
	CashFlowCommonData(24, "bk_val_plus_accr_int_bef_rebal_sale", "epa_asset_bk_val_plus_accr_int_bef_rebal_sale",  "bk_val_plus_accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_bk_val_plus_accr_int_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int_bef_rebal_sale),
	CashFlowCommonData(25, "cal_mth", "epa_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(26, "cal_yr", "epa_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(27, "cal_yr_relative", "epa_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(28, "cap_gain_bef_sale", "epa_asset_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(29, "cap_gain_from_sale", "epa_asset_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(30, "cash_flow", "epa_asset_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cash_flow, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(31, "cost_basis", "epa_asset_cost_basis",  "cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis),
	CashFlowCommonData(32, "cost_basis_accrual", "epa_asset_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis_accrual, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(33, "cost_basis_aft_dflt", "epa_asset_cost_basis_aft_dflt",  "cost_basis_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_aft_dflt),
	CashFlowCommonData(34, "cost_basis_bef_sale", "epa_asset_cost_basis_bef_sale",  "cost_basis_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis_bef_sale),
	CashFlowCommonData(35, "cost_basis_dflt", "epa_asset_cost_basis_dflt",  "cost_basis_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_dflt),
	CashFlowCommonData(36, "cost_basis_sold", "epa_asset_cost_basis_sold",  "cost_basis_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_cost_basis_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_sold),
	CashFlowCommonData(37, "date", "epa_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(38, "dflt_amt", "epa_asset_dflt_amt",  "dflt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_dflt_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->dflt_amt),
	CashFlowCommonData(39, "dflt_pct", "epa_asset_dflt_pct",  "dflt_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_dflt_pct, 'E','N', '3', 'C', (size_t)&modelOffset->dflt_pct),
	CashFlowCommonData(40, "dur_val", "epa_asset_dur_val",  "dur_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_dur_val, 'E','N', '3', 'C', (size_t)&modelOffset->dur_val),
	CashFlowCommonData(41, "eff_dur", "epa_asset_eff_dur",  "eff_dur",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_eff_dur, 'E','N', '3', 'C', (size_t)&modelOffset->eff_dur),
	CashFlowCommonData(42, "epa_pct_remaining", "epa_asset_epa_pct_remaining",  "epa_pct_remaining",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_epa_pct_remaining, 'E','N', '3', 'C', (size_t)&modelOffset->epa_pct_remaining),
	CashFlowCommonData(43, "finalize", "epa_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(44, "gaap_inc_bk_val", "epa_asset_gaap_inc_bk_val",  "gaap_inc_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_gaap_inc_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bk_val),
	CashFlowCommonData(45, "gaap_inc_unrealzd_cap_gain", "epa_asset_gaap_inc_unrealzd_cap_gain",  "gaap_inc_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_gaap_inc_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain),
	CashFlowCommonData(46, "gaap_surp_bk_val", "epa_asset_gaap_surp_bk_val",  "gaap_surp_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_gaap_surp_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_surp_bk_val),
	CashFlowCommonData(47, "gaap_unrealzd_cap_gain_incr", "epa_asset_gaap_unrealzd_cap_gain_incr",  "gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(48, "imr_realzd_cap_gain", "epa_asset_imr_realzd_cap_gain",  "imr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_imr_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain),
	CashFlowCommonData(49, "imr_realzd_cap_gain_from_sale", "epa_asset_imr_realzd_cap_gain_from_sale",  "imr_realzd_cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_imr_realzd_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->imr_realzd_cap_gain_from_sale),
	CashFlowCommonData(50, "imr_yrs_to_maturity", "epa_asset_imr_yrs_to_maturity",  "imr_yrs_to_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_imr_yrs_to_maturity, 'E','N', '3', 'C', (size_t)&modelOffset->imr_yrs_to_maturity),
	CashFlowCommonData(51, "initialize", "epa_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(52, "int_div_and_rent", "epa_asset_int_div_and_rent",  "int_div_and_rent",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_int_div_and_rent, 'E','Y', '3', 'P', (size_t)&modelOffset->int_div_and_rent),
	CashFlowCommonData(53, "int_pmt", "epa_asset_int_pmt",  "int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_int_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->int_pmt),
	CashFlowCommonData(54, "mkt_to_bk_ratio", "epa_asset_mkt_to_bk_ratio",  "mkt_to_bk_ratio",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_to_bk_ratio),
	CashFlowCommonData(55, "mkt_val", "epa_asset_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(56, "mkt_val_bef_fund_match_sale", "epa_asset_mkt_val_bef_fund_match_sale",  "mkt_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_bef_fund_match_sale),
	CashFlowCommonData(57, "mkt_val_bef_neg_cash_flow_sale", "epa_asset_mkt_val_bef_neg_cash_flow_sale",  "mkt_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(58, "mkt_val_bef_rebal_sale", "epa_asset_mkt_val_bef_rebal_sale",  "mkt_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_rebal_sale),
	CashFlowCommonData(59, "mkt_val_bef_sale", "epa_asset_mkt_val_bef_sale",  "mkt_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_sale),
	CashFlowCommonData(60, "mkt_val_for_dur_bef_neg_cash_flow_sale", "epa_asset_mkt_val_for_dur_bef_neg_cash_flow_sale",  "mkt_val_for_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(61, "mkt_val_for_dur_bef_rebal_sale", "epa_asset_mkt_val_for_dur_bef_rebal_sale",  "mkt_val_for_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_rebal_sale),
	CashFlowCommonData(62, "mkt_val_for_dur_sold", "epa_asset_mkt_val_for_dur_sold",  "mkt_val_for_dur_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_for_dur_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_sold),
	CashFlowCommonData(63, "mkt_val_for_eff_dur", "epa_asset_mkt_val_for_eff_dur",  "mkt_val_for_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_for_eff_dur, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_for_eff_dur),
	CashFlowCommonData(64, "mkt_val_sold", "epa_asset_mkt_val_sold",  "mkt_val_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_sold, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_sold),
	CashFlowCommonData(65, "mkt_val_times_dur_bef_neg_cash_flow_sale", "epa_asset_mkt_val_times_dur_bef_neg_cash_flow_sale",  "mkt_val_times_dur_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_times_dur_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_neg_cash_flow_sale),
	CashFlowCommonData(66, "mkt_val_times_dur_bef_rebal_sale", "epa_asset_mkt_val_times_dur_bef_rebal_sale",  "mkt_val_times_dur_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_times_dur_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_dur_bef_rebal_sale),
	CashFlowCommonData(67, "mkt_val_times_eff_dur", "epa_asset_mkt_val_times_eff_dur",  "mkt_val_times_eff_dur",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_mkt_val_times_eff_dur, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_times_eff_dur),
	CashFlowCommonData(68, "notional_amt", "epa_asset_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_notional_amt, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(69, "notional_amt_bef_fund_match_sale", "epa_asset_notional_amt_bef_fund_match_sale",  "notional_amt_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_notional_amt_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt_bef_fund_match_sale),
	CashFlowCommonData(70, "notional_amt_bef_neg_cash_flow_sale", "epa_asset_notional_amt_bef_neg_cash_flow_sale",  "notional_amt_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_notional_amt_bef_neg_cash_flow_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_neg_cash_flow_sale),
	CashFlowCommonData(71, "notional_amt_bef_rebal_sale", "epa_asset_notional_amt_bef_rebal_sale",  "notional_amt_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_notional_amt_bef_rebal_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_rebal_sale),
	CashFlowCommonData(72, "notional_amt_bef_sale", "epa_asset_notional_amt_bef_sale",  "notional_amt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_notional_amt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_sale),
	CashFlowCommonData(73, "opt_inc", "epa_asset_opt_inc",  "opt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_opt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_inc),
	CashFlowCommonData(74, "opt_pmt", "epa_asset_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(75, "rbc_c1", "epa_asset_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(76, "rbc_c1_bef_sale", "epa_asset_rbc_c1_bef_sale",  "rbc_c1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_rbc_c1_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_bef_sale),
	CashFlowCommonData(77, "realzd_cap_gain", "epa_asset_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(78, "realzd_cap_gain_opt_pmt", "epa_asset_realzd_cap_gain_opt_pmt",  "realzd_cap_gain_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_realzd_cap_gain_opt_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_opt_pmt),
	CashFlowCommonData(79, "realzd_cap_gain_sale", "epa_asset_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_realzd_cap_gain_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(80, "realzd_cap_loss_dflt", "epa_asset_realzd_cap_loss_dflt",  "realzd_cap_loss_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_realzd_cap_loss_dflt, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_loss_dflt),
	CashFlowCommonData(81, "remaining_pct_aft_dflt", "epa_asset_remaining_pct_aft_dflt",  "remaining_pct_aft_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_remaining_pct_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->remaining_pct_aft_dflt),
	CashFlowCommonData(82, "sched_prin_pmt", "epa_asset_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sched_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(83, "sold_pct", "epa_asset_sold_pct",  "sold_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sold_pct, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct),
	CashFlowCommonData(84, "sold_pct_fund_match", "epa_asset_sold_pct_fund_match",  "sold_pct_fund_match",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sold_pct_fund_match, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_fund_match),
	CashFlowCommonData(85, "sold_pct_neg_cash_flow", "epa_asset_sold_pct_neg_cash_flow",  "sold_pct_neg_cash_flow",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sold_pct_neg_cash_flow, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_neg_cash_flow),
	CashFlowCommonData(86, "sold_pct_planned", "epa_asset_sold_pct_planned",  "sold_pct_planned",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sold_pct_planned, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_planned),
	CashFlowCommonData(87, "sold_pct_rebal", "epa_asset_sold_pct_rebal",  "sold_pct_rebal",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sold_pct_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_rebal),
	CashFlowCommonData(88, "startup", "epa_asset_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(89, "sub_port_id", "epa_asset_sub_port_id",  "sub_port_id",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_sub_port_id, 'E','N', '3', 'P', (size_t)&modelOffset->sub_port_id),
	CashFlowCommonData(90, "tax_exempt_inc", "epa_asset_tax_exempt_inc",  "tax_exempt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_tax_exempt_inc, 'E','N', '3', 'C', (size_t)&modelOffset->tax_exempt_inc),
	CashFlowCommonData(91, "unrealzd_cap_gain", "epa_asset_unrealzd_cap_gain",  "unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain),
	CashFlowCommonData(92, "unrealzd_cap_gain_bef_fund_match_sale", "epa_asset_unrealzd_cap_gain_bef_fund_match_sale",  "unrealzd_cap_gain_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_fund_match_sale),
	CashFlowCommonData(93, "unrealzd_cap_gain_bef_neg_cash_flow_sale", "epa_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale",  "unrealzd_cap_gain_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_neg_cash_flow_sale),
	CashFlowCommonData(94, "unrealzd_cap_gain_bef_rebal_sale", "epa_asset_unrealzd_cap_gain_bef_rebal_sale",  "unrealzd_cap_gain_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_rebal_sale),
	CashFlowCommonData(95, "unrealzd_cap_gain_bef_sale", "epa_asset_unrealzd_cap_gain_bef_sale",  "unrealzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_bef_sale),
	CashFlowCommonData(96, "unrealzd_cap_gain_gaap_surp", "epa_asset_unrealzd_cap_gain_gaap_surp",  "unrealzd_cap_gain_gaap_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_gaap_surp, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_gaap_surp),
	CashFlowCommonData(97, "unrealzd_cap_gain_incr", "epa_asset_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(98, "unrealzd_cap_gain_released_on_sale", "epa_asset_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(99, "unrealzd_cap_gain_to_bk_ratio", "epa_asset_unrealzd_cap_gain_to_bk_ratio",  "unrealzd_cap_gain_to_bk_ratio",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_unrealzd_cap_gain_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_to_bk_ratio),
	CashFlowCommonData(100, "weighted_avg_life", "epa_asset_weighted_avg_life",  "weighted_avg_life",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_weighted_avg_life, 'E','N', '3', 'C', (size_t)&modelOffset->weighted_avg_life),
	CashFlowCommonData(101, "yld_denom", "epa_asset_yld_denom",  "yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->yld_denom),
	CashFlowCommonData(102, "yld_numer", "epa_asset_yld_numer",  "yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EPA_ASSET_UDF::epa_asset_yld_numer, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer)
};
const CashFlowCommonData* EPA_ASSET::mCFStaticData[] = {
	&EPA_ASSET::mCFStaticData_0[0],
	&EPA_ASSET::mCFStaticData_0[1],
	&EPA_ASSET::mCFStaticData_0[2],
	&EPA_ASSET::mCFStaticData_0[3],
	&EPA_ASSET::mCFStaticData_0[4],
	&EPA_ASSET::mCFStaticData_0[5],
	&EPA_ASSET::mCFStaticData_0[6],
	&EPA_ASSET::mCFStaticData_0[7],
	&EPA_ASSET::mCFStaticData_0[8],
	&EPA_ASSET::mCFStaticData_0[9],
	&EPA_ASSET::mCFStaticData_0[10],
	&EPA_ASSET::mCFStaticData_0[11],
	&EPA_ASSET::mCFStaticData_0[12],
	&EPA_ASSET::mCFStaticData_0[13],
	&EPA_ASSET::mCFStaticData_0[14],
	&EPA_ASSET::mCFStaticData_0[15],
	&EPA_ASSET::mCFStaticData_0[16],
	&EPA_ASSET::mCFStaticData_0[17],
	&EPA_ASSET::mCFStaticData_0[18],
	&EPA_ASSET::mCFStaticData_0[19],
	&EPA_ASSET::mCFStaticData_0[20],
	&EPA_ASSET::mCFStaticData_0[21],
	&EPA_ASSET::mCFStaticData_0[22],
	&EPA_ASSET::mCFStaticData_0[23],
	&EPA_ASSET::mCFStaticData_0[24],
	&EPA_ASSET::mCFStaticData_0[25],
	&EPA_ASSET::mCFStaticData_0[26],
	&EPA_ASSET::mCFStaticData_0[27],
	&EPA_ASSET::mCFStaticData_0[28],
	&EPA_ASSET::mCFStaticData_0[29],
	&EPA_ASSET::mCFStaticData_0[30],
	&EPA_ASSET::mCFStaticData_0[31],
	&EPA_ASSET::mCFStaticData_0[32],
	&EPA_ASSET::mCFStaticData_0[33],
	&EPA_ASSET::mCFStaticData_0[34],
	&EPA_ASSET::mCFStaticData_0[35],
	&EPA_ASSET::mCFStaticData_0[36],
	&EPA_ASSET::mCFStaticData_0[37],
	&EPA_ASSET::mCFStaticData_0[38],
	&EPA_ASSET::mCFStaticData_0[39],
	&EPA_ASSET::mCFStaticData_0[40],
	&EPA_ASSET::mCFStaticData_0[41],
	&EPA_ASSET::mCFStaticData_0[42],
	&EPA_ASSET::mCFStaticData_0[43],
	&EPA_ASSET::mCFStaticData_0[44],
	&EPA_ASSET::mCFStaticData_0[45],
	&EPA_ASSET::mCFStaticData_0[46],
	&EPA_ASSET::mCFStaticData_0[47],
	&EPA_ASSET::mCFStaticData_0[48],
	&EPA_ASSET::mCFStaticData_0[49],
	&EPA_ASSET::mCFStaticData_0[50],
	&EPA_ASSET::mCFStaticData_0[51],
	&EPA_ASSET::mCFStaticData_0[52],
	&EPA_ASSET::mCFStaticData_0[53],
	&EPA_ASSET::mCFStaticData_0[54],
	&EPA_ASSET::mCFStaticData_0[55],
	&EPA_ASSET::mCFStaticData_0[56],
	&EPA_ASSET::mCFStaticData_0[57],
	&EPA_ASSET::mCFStaticData_0[58],
	&EPA_ASSET::mCFStaticData_0[59],
	&EPA_ASSET::mCFStaticData_0[60],
	&EPA_ASSET::mCFStaticData_0[61],
	&EPA_ASSET::mCFStaticData_0[62],
	&EPA_ASSET::mCFStaticData_0[63],
	&EPA_ASSET::mCFStaticData_0[64],
	&EPA_ASSET::mCFStaticData_0[65],
	&EPA_ASSET::mCFStaticData_0[66],
	&EPA_ASSET::mCFStaticData_0[67],
	&EPA_ASSET::mCFStaticData_0[68],
	&EPA_ASSET::mCFStaticData_0[69],
	&EPA_ASSET::mCFStaticData_0[70],
	&EPA_ASSET::mCFStaticData_0[71],
	&EPA_ASSET::mCFStaticData_0[72],
	&EPA_ASSET::mCFStaticData_0[73],
	&EPA_ASSET::mCFStaticData_0[74],
	&EPA_ASSET::mCFStaticData_0[75],
	&EPA_ASSET::mCFStaticData_0[76],
	&EPA_ASSET::mCFStaticData_0[77],
	&EPA_ASSET::mCFStaticData_0[78],
	&EPA_ASSET::mCFStaticData_0[79],
	&EPA_ASSET::mCFStaticData_0[80],
	&EPA_ASSET::mCFStaticData_0[81],
	&EPA_ASSET::mCFStaticData_0[82],
	&EPA_ASSET::mCFStaticData_0[83],
	&EPA_ASSET::mCFStaticData_0[84],
	&EPA_ASSET::mCFStaticData_0[85],
	&EPA_ASSET::mCFStaticData_0[86],
	&EPA_ASSET::mCFStaticData_0[87],
	&EPA_ASSET::mCFStaticData_0[88],
	&EPA_ASSET::mCFStaticData_0[89],
	&EPA_ASSET::mCFStaticData_0[90],
	&EPA_ASSET::mCFStaticData_0[91],
	&EPA_ASSET::mCFStaticData_0[92],
	&EPA_ASSET::mCFStaticData_0[93],
	&EPA_ASSET::mCFStaticData_0[94],
	&EPA_ASSET::mCFStaticData_0[95],
	&EPA_ASSET::mCFStaticData_0[96],
	&EPA_ASSET::mCFStaticData_0[97],
	&EPA_ASSET::mCFStaticData_0[98],
	&EPA_ASSET::mCFStaticData_0[99],
	&EPA_ASSET::mCFStaticData_0[100],
	&EPA_ASSET::mCFStaticData_0[101],
	&EPA_ASSET::mCFStaticData_0[102],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for asset_defn                                                                                       
	const ChoicePair asset_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BOND, "Bond")
		,ChoicePair(StrEnum::MORTGAGE, "Mortgage")
		,ChoicePair(StrEnum::SECURITIZED_ASSET, "Securitized Asset")
		,ChoicePair(StrEnum::INTEREST_RATE_DERIVATIVE, "Interest Rate Derivative")
		,ChoicePair(StrEnum::EQUITY, "Equity")
	};
	const EnumList asset_defnEnumList(5, asset_defnChoicePairs);

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for epa_file_defn                                                                                       
	const ChoicePair epa_file_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SCHEDULE_FILE, "Schedule File")
		,ChoicePair(StrEnum::TAS_EPA_FILE, "TAS EPA File")
	};
	const EnumList epa_file_defnEnumList(2, epa_file_defnChoicePairs);

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

	// EnumList for sale_class                                                                                       
	const ChoicePair sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList sale_classEnumList(4, sale_classChoicePairs);

	// EnumList for use_mp                                                                                       
	const ChoicePair use_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_mpEnumList(2, use_mpChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace EPA_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(EPA_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(EPA_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace EPA_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void EPA_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> EPA_ASSET::mgr_;

	Attribute::Descriptor EPA_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"asset_defn", -1, (size_t)&modelOffset->asset_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::DOUBLE,	"avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(7, Attribute::STRING,	"epa_file", -1, (size_t)&modelOffset->epa_file,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"epa_file_defn", -1, (size_t)&modelOffset->epa_file_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &epa_file_defnEnumList, Feature(true)),
	Descriptor(9, Attribute::STR_ENUM,	"gaap_acctng_defn", -1, (size_t)&modelOffset->gaap_acctng_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gaap_acctng_defnEnumList, Feature(true)),
	Descriptor(10, Attribute::STR_ENUM,	"ia_prod_v3_rsd_2_aig", -1, (size_t)&modelOffset->ia_prod_v3_rsd_2_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ia_prod_v3_rsd_2_aigEnumList, Feature(true)),
	Descriptor(11, Attribute::DOUBLE,	"pct_to_use_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pct_to_use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STRING,	"planned_sale_date", -1, (size_t)&modelOffset->planned_sale_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"sale_class", -1, (size_t)&modelOffset->sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sale_classEnumList, Feature(true)),
	Descriptor(16, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(18, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::SCALAR_INT,	"asset_fund_index", -1, (size_t)&modelOffset->asset_fund_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_asset_fund_index)),
	Descriptor(20, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_commencement_period)),
	Descriptor(21, Attribute::SCALAR_STRING,	"data_grp_id", -1, (size_t)&modelOffset->data_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&EPA_ASSET_UDF::epa_asset_data_grp_id)),
	Descriptor(22, Attribute::SCALAR_INT,	"gaap_inc_defn", -1, (size_t)&modelOffset->gaap_inc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_gaap_inc_defn)),
	Descriptor(23, Attribute::SCALAR_INT,	"gaap_val_defn", -1, (size_t)&modelOffset->gaap_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_gaap_val_defn)),
	Descriptor(24, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_maturity_period)),
	Descriptor(25, Attribute::SCALAR_INT,	"neg_asset_flag", -1, (size_t)&modelOffset->neg_asset_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_neg_asset_flag)),
	Descriptor(26, Attribute::SCALAR_DOUBLE,	"pct_to_use", -1, (size_t)&modelOffset->pct_to_use,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EPA_ASSET_UDF::epa_asset_pct_to_use)),
	Descriptor(27, Attribute::SCALAR_INT,	"planned_sale_period", -1, (size_t)&modelOffset->planned_sale_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_planned_sale_period)),
	Descriptor(28, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&EPA_ASSET_UDF::epa_asset_proj_date_adj)),
	Descriptor(29, Attribute::SCALAR_INT,	"proj_date_offset", -1, (size_t)&modelOffset->proj_date_offset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_proj_date_offset)),
	Descriptor(30, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_proj_start_date)),
	Descriptor(31, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_proj_start_mth)),
	Descriptor(32, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_proj_start_yr)),
	Descriptor(33, Attribute::SCALAR_INT,	"sale_class_id", -1, (size_t)&modelOffset->sale_class_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_sale_class_id)),
	Descriptor(34, Attribute::SCALAR_INT,	"seg_num", -1, (size_t)&modelOffset->seg_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_seg_num)),
	Descriptor(35, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EPA_ASSET_UDF::epa_asset_start_period)),
	};

	Attribute::Descriptor* EPA_ASSET::descriptorTable[] = {
	&EPA_ASSET::descriptor_0[0],
	&EPA_ASSET::descriptor_0[1],
	&EPA_ASSET::descriptor_0[2],
	&EPA_ASSET::descriptor_0[3],
	&EPA_ASSET::descriptor_0[4],
	&EPA_ASSET::descriptor_0[5],
	&EPA_ASSET::descriptor_0[6],
	&EPA_ASSET::descriptor_0[7],
	&EPA_ASSET::descriptor_0[8],
	&EPA_ASSET::descriptor_0[9],
	&EPA_ASSET::descriptor_0[10],
	&EPA_ASSET::descriptor_0[11],
	&EPA_ASSET::descriptor_0[12],
	&EPA_ASSET::descriptor_0[13],
	&EPA_ASSET::descriptor_0[14],
	&EPA_ASSET::descriptor_0[15],
	&EPA_ASSET::descriptor_0[16],
	&EPA_ASSET::descriptor_0[17],
	&EPA_ASSET::descriptor_0[18],
	&EPA_ASSET::descriptor_0[19],
	&EPA_ASSET::descriptor_0[20],
	&EPA_ASSET::descriptor_0[21],
	&EPA_ASSET::descriptor_0[22],
	&EPA_ASSET::descriptor_0[23],
	&EPA_ASSET::descriptor_0[24],
	&EPA_ASSET::descriptor_0[25],
	&EPA_ASSET::descriptor_0[26],
	&EPA_ASSET::descriptor_0[27],
	&EPA_ASSET::descriptor_0[28],
	&EPA_ASSET::descriptor_0[29],
	&EPA_ASSET::descriptor_0[30],
	&EPA_ASSET::descriptor_0[31],
	&EPA_ASSET::descriptor_0[32],
	&EPA_ASSET::descriptor_0[33],
	&EPA_ASSET::descriptor_0[34],
	&EPA_ASSET::descriptor_0[35],
	nullptr};
	const size_t EPA_ASSET::sDescriptorCount = 36;

//factory
EPA_ASSET* EPA_ASSET::makeThis(int isSubmodel, ModelClass* owner, EPA_ASSET* peer, 
						int mainRebase, const xstring &name, EPA_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EPA_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EPA_ASSET");
#endif
	EPA_ASSET* newP = (EPA_ASSET*)new EPA_ASSET_UDF
   	  ("epa_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
EPA_ASSET_persistent_object* EPA_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, EPA_ASSET* peer, 
							int mainRebase, const xstring &name, EPA_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EPA_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EPA_ASSET_persistent_object");
#endif
	EPA_ASSET_persistent_object* newP = (EPA_ASSET_persistent_object*)new EPA_ASSET_persistent_object
   	  ("epa_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			EPA_ASSET_persistent_object* pd = dynamic_cast<EPA_ASSET_persistent_object*>(product);
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

typedef double (EPA_ASSET_UDF::*dPF) ();
typedef double (EPA_ASSET_UDF::*dPFd) (double);
typedef int (EPA_ASSET_UDF::*iPF) ();
typedef int (EPA_ASSET_UDF::*iPFi) (int);
typedef xstring (EPA_ASSET_UDF::*sPF) ();
typedef xstring (EPA_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
EPA_ASSET::EPA_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EPA_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
EPA_ASSET::EPA_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(102, EPA_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
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
#ifdef __CREATE_EPA_ASSET_CLASS_
       company_asset_epa = 0;
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

	for (int cf_no = 1; cf_no <= 102; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EPA_ASSET_UDF::*dPXi2) (int, int);
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


 void EPA_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
		company_asset_epa = (EPA_ASSET*)(findUnique("company|asset|epa"));
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
 }
//copy_names END@2


 void EPA_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int EPA_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& EPA_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double EPA_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int EPA_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double EPA_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double EPA_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void EPA_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPA_ASSET_persistent_object::write(long include_submodels) {
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

	void EPA_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPA_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EPA_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	EPA_ASSET_persistent_object::~EPA_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool EPA_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void EPA_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void EPA_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void EPA_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EPA_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EPA_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* EPA_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* EPA_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* EPA_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char EPA_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void EPA_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
EPA_ASSET_persistent_object::EPA_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			EPA_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(EPA_ASSET::sm_bond_is)
	, sm_bond_pv(EPA_ASSET::sm_bond_pv)
	, sm_bond_ym(EPA_ASSET::sm_bond_ym)
	, sm_mtg_is(EPA_ASSET::sm_mtg_is)
	, sm_mtg_pv(EPA_ASSET::sm_mtg_pv)
	, sm_mtg_ym(EPA_ASSET::sm_mtg_ym)

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
EPA_ASSET::~EPA_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void EPA_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void EPA_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void EPA_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void EPA_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void EPA_ASSET::start_of_projection() {
}
//start_of_projection END@2

void EPA_ASSET::end_of_projection() {
}
//end_of_projection END@2

void EPA_ASSET::start_of_layer() {
}


void EPA_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void EPA_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void EPA_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void EPA_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> EPA_ASSET::ddfVector;
BitArray EPA_ASSET::dataVariables(36);
bool EPA_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool EPA_ASSET::writeClassInfo = true;

void EPA_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, EPA_ASSET::descriptor_0>::dT = EPA_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, EPA_ASSET::descriptor_0>::dT = EPA_ASSET::descriptor_0;

