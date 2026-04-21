
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
#include "ModelClass\eio_asset_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\comp_comp.h"
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

int num_eios_to_run;
int num_eio = 0;
sowfinput eio_mp_input;
sowfcols eio_mp_input_cols;
extern sowmpoutput eio_state_of_world_mp_output;
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;

static eioivmap eio_initial_values_map;
static eioivmap::iterator eio_initial_values_map_iter;
extern bool is_asset_initialize;

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
#ifndef eio_asset_TableDefs
#define eio_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection EIO_ASSET::TTHC;
void EIO_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - accr_inc
// Accrued Income                                                                                             
// Column:ACCR_INC
//========================================================
double EIO_ASSET_UDF::eio_asset_accr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_inc",t);
}



//^^^

#line 1 "accr_inc.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return cost_basis_bef_sale(t)
		   - cost_basis(t - 1);

return cost_basis_bef_expiry
	   - cost_basis(t - 1);

}


//@@ END

//@@ START - asset_detail_pv_flag
// Detail Present Value Flag                                                                                             
// Column:ASSET_DETAIL_PV_FLAG
//========================================================
double EIO_ASSET_UDF::eio_asset_asset_detail_pv_flag(int t) {
//^^^



//^^^

#line 1 "asset_detail_pv_flag.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_asset_min_size_sale_flag(int t) {
//^^^



//^^^

#line 1 "asset_min_size_sale_flag.EIO_ASSET.for"
if (t <= commencement_period || t >= maturity_period || isMainModel)
	return 0.0;

if ((company->sm_inv_strategy[seg_num]->mths_to_rebal(t) == 0
	 || asset->mths_to_asset_sale(t) == 0)
	&& (fabs(bk_val_bef_sale(t) * pct_to_use) > 0.0)
	&& (fabs(bk_val_bef_sale(t) * pct_to_use)
		 < asset->sm_asset_sub_port[seg_num][xint(sub_port_id(t))][0]->min_size_existing))
	// do not change order of && statements
	return 1.0;

return 0.0;

}


//@@ END

//@@ START - avr_basic_contribn
// AVR Basic Contribution                                                                                             
// Column:AVR_BASIC_CONTRIBN
//========================================================
double EIO_ASSET_UDF::eio_asset_avr_basic_contribn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"avr_basic_contribn",t);
}



//^^^

#line 1 "avr_basic_contribn.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_basic_contribn_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"avr_basic_contribn_bef_sale",t);
}



//^^^

#line 1 "avr_basic_contribn_bef_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_max(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"avr_max",t);
}



//^^^

#line 1 "avr_max.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_max_bef_sale(int t) {
//^^^



//^^^

#line 1 "avr_max_bef_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_obj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"avr_obj",t);
}



//^^^

#line 1 "avr_obj.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_obj_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"avr_obj_bef_sale",t);
}



//^^^

#line 1 "avr_obj_bef_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_avr_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"avr_realzd_cap_gain",t);
}



//^^^

#line 1 "avr_realzd_cap_gain.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain(t);

}


//@@ END

//@@ START - avr_realzd_cap_gain_from_sale
// AVR Realized Capital Gain from Sales                                                                                             
// Column:AVR_REALZD_CAP_GAIN_FROM_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_avr_realzd_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"avr_realzd_cap_gain_from_sale",t);
}



//^^^

#line 1 "avr_realzd_cap_gain_from_sale.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_sale(t);

}


//@@ END

//@@ START - avr_unrealzd_cap_gain
// AVR Unrealized Capital Gain                                                                                             
// Column:AVR_UNREALZD_CAP_GAIN
//========================================================
double EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"avr_unrealzd_cap_gain",t);
}



//^^^

#line 1 "avr_unrealzd_cap_gain.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain(t);

}


//@@ END

//@@ START - avr_unrealzd_cap_gain_bef_sale
// AVR Unrealized Capital Gain Before Sales                                                                                             
// Column:AVR_UNREALZD_CAP_GAIN_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "avr_unrealzd_cap_gain_bef_sale.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_bef_sale(t);

}


//@@ END

//@@ START - avr_unrealzd_cap_gain_released_on_sale
// AVR Unrealized Capital Gain Released on Sale                                                                                             
// Column:AVR_UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain_released_on_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"avr_unrealzd_cap_gain_released_on_sale",t);
}



//^^^

#line 1 "avr_unrealzd_cap_gain_released_on_sale.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return unrealzd_cap_gain_released_on_sale(t);

}


//@@ END

//@@ START - bk_val
// Book Value                                                                                             
// Column:BK_VAL
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"bk_val",t);
}



//^^^

#line 1 "bk_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return bk_val_bef_neg_cash_flow_sale(t)
		   * (1.0 - sold_pct_neg_cash_flow(t));

return 0.0;

}


//@@ END

//@@ START - bk_val_bef_fund_match_sale
// Book Value Before Fund Value Matching Asset Sales                                                                                             
// Column:BK_VAL_BEF_FUND_MATCH_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"bk_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "bk_val_bef_fund_match_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return bk_val_bef_sale(t)
		   * (1.0 - sold_pct_planned(t));
    	   
return 0.0;

}


//@@ END

//@@ START - bk_val_bef_neg_cash_flow_sale
// Book Value Before Negative Cash Flow Sales                                                                                             
// Column:BK_VAL_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"bk_val_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "bk_val_bef_neg_cash_flow_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return bk_val_bef_rebal_sale(t)
		   * (1.0 - sold_pct_rebal(t));
    	   
return 0.0;

}


//@@ END

//@@ START - bk_val_bef_rebal_sale
// Book Value Before Rebalancing Sales                                                                                             
// Column:BK_VAL_BEF_REBAL_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"bk_val_bef_rebal_sale",t);
}



//^^^

#line 1 "bk_val_bef_rebal_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return bk_val_bef_fund_match_sale(t)
		   * (1.0 - sold_pct_fund_match(t));
    	   
return 0.0;

}


//@@ END

//@@ START - bk_val_bef_sale
// Book Value Before Sales                                                                                             
// Column:BK_VAL_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && existing_asset_indicator)
	{
	double local_book_value = init_bk_val * neg_asset_flag;

	//Perform accounting data consistency checks for book value
	if (bk_val_defn == COST_BASIS
		&& fabs(local_book_value - cost_basis_bef_sale(t)) > 0.5)
		{
		if (cost_basis_defn != MARKET_VALUE)
			{
			makeRunLogYellow();
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "Warning: Inconsistent index option input for " << asset_id
					   << ". The book value accounting definition is Cost Basis."
					   << MSG_ERROR;
			log_screen << " Book value " << local_book_value
					   << " differs from Cost Basis " << cost_basis_bef_sale(t)
					   << "." << MSG_ERROR;
			log_screen << " Book value has been set to cost basis." << MSG_ERROR;
			log_screen.unsetf(ios::fixed);
			}

		return cost_basis_bef_sale(t);
		}

	if (bk_val_defn == MARKET_VALUE
		&& fabs(local_book_value - mkt_val_bef_sale(t)) > 0.5)
		{
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning: Inconsistent index option input"
				   << " for " << asset_id
				   << ". The book value accounting definition is Market Value."
				   << MSG_ERROR;
		log_screen << " Book value " << local_book_value
				   << " differs from Market Value " << mkt_val_bef_sale(t)
				   << "." << MSG_ERROR;
		log_screen << " Input market value is " << init_mkt_val
				   << ". Book value has been set to market value."
				   << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		return mkt_val_bef_sale(t);
		}

	if (bk_val_defn == LOWER_OF_COST_AND_MARKET
		&& fabs(local_book_value - min(cost_basis_bef_sale(t), mkt_val_bef_sale(t))) > 0.5)
		{
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Warning: Inconsistent index option input"
				   << " for " << asset_id
				   << ". The book value accounting definition is Lower of Cost and Market."
				   << MSG_ERROR;
		log_screen << " Book value " << local_book_value
				   << " differs from lower of Cost Basis " << cost_basis_bef_sale(t)
				   << " and market value " << mkt_val_bef_sale(t)
				   << "." << MSG_ERROR;
		log_screen << " Input market value is " << init_mkt_val
				   << " Book value has been set to lower of cost basis amd market value."
				   << MSG_ERROR;
		log_screen.unsetf(ios::fixed);

		return min(cost_basis_bef_sale(t), mkt_val_bef_sale(t));
		}

	return local_book_value;
	}

if (!existing_asset_indicator && t == commencement_period)
	return mkt_val_bef_sale(t);

if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_sale(t);

if (bk_val_defn == MARKET_VALUE)
	return mkt_val_bef_sale(t);

if (bk_val_defn == LOWER_OF_COST_AND_MARKET)
	return min(cost_basis_bef_sale(t), mkt_val_bef_sale(t));

if (bk_val_defn == HISTORIC_LOWEST_COST)
	return min(cost_basis_bef_sale(t), bk_val(t - 1));

if (bk_val_defn == HISTORIC_LOWEST_COST_AND_MARKET
	&& cal_mth(t) < 12)
	return bk_val(t - 1);

//if (bk_val_defn == HISTORIC_LOWEST_COST_AND_MARKET
//	&& cal_mth(t) == 12)
return min(bk_val(t - 1),
		   min(cost_basis_bef_sale(t), mkt_val_bef_sale(t)));

}


//@@ END

//@@ START - bk_val_plus_accr_int
// Book Value Plus Accrued Interest                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int.EIO_ASSET.for"
// these bk_val_plus_accr_int... columns are used in sum_over_assets
//	to accumulate values for sales and rebalancing processing

if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val(t);

}


//@@ END

//@@ START - bk_val_plus_accr_int_bef_neg_cash_flow_sale
// Book Value Plus Accrued Interest Before Negative Cash Flow Sales                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int_bef_neg_cash_flow_sale.EIO_ASSET.for"
// these bk_val_plus_accr_int... columns are used in sum_over_assets
//	to accumulate values for sales and rebalancing processing

if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return bk_val_bef_neg_cash_flow_sale (t);

}


//@@ END

//@@ START - bk_val_plus_accr_int_bef_rebal_sale
// Book Value Plus Accrued Interest Before Rebalancing Sales                                                                                             
// Column:BK_VAL_PLUS_ACCR_INT_BEF_REBAL_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "bk_val_plus_accr_int_bef_rebal_sale.EIO_ASSET.for"
// these bk_val_plus_accr_int... columns are used in sum_over_assets
//	to accumulate values for sales and rebalancing processing

if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return bk_val_bef_rebal_sale(t);

}


//@@ END

//@@ START - bk_val_purch
// Book Value Purchase                                                                                             
// Column:BK_VAL_PURCH
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"bk_val_purch",t);
}



//^^^

#line 1 "bk_val_purch.EIO_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (purchased_bom_flag && t == commencement_period + 1)
	return bk_val(t - 1);

if (t == commencement_period)
	return bk_val(t);

return NO_AVG;

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double EIO_ASSET_UDF::eio_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.EIO_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double EIO_ASSET_UDF::eio_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.EIO_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain_bef_sale
// Capital Gains Before Sales                                                                                             
// Column:CAP_GAIN_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_cap_gain_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"cap_gain_bef_sale",t);
}



//^^^

#line 1 "cap_gain_bef_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_cap_gain_from_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"cap_gain_from_sale",t);
}



//^^^

#line 1 "cap_gain_from_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_cash_flow(int t) {
//^^^



//^^^

#line 1 "cash_flow.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return opt_pmt(t);

}


//@@ END

//@@ START - cost_basis
// Cost Basis                                                                                             
// Column:COST_BASIS
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"cost_basis",t);
}



//^^^

#line 1 "cost_basis.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

//force call for reporting
cost_basis_incr_appreciation(t);

if (t < maturity_period)
	return cost_basis_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_accrual
// Cost Basis Accrual                                                                                             
// Column:COST_BASIS_ACCRUAL
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_accrual(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"cost_basis_accrual",t);
}



//^^^

#line 1 "cost_basis_accrual.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn != MARKET_VALUE)
	{
	if (t < maturity_period)
		return cost_basis_bef_sale(t) - cost_basis(t - 1);
	
	return cost_basis_bef_expiry - cost_basis(t - 1);
	}

return 0.0;

}


//@@ END

//@@ START - cost_basis_bef_sale
// Cost Basis Before Sales                                                                                             
// Column:COST_BASIS_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_bef_sale(int t) {
//^^^



//^^^

#line 1 "cost_basis_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	{
	double local_cost_basis = init_cost_basis * neg_asset_flag;

	if (cost_basis_defn == MARKET_VALUE
		&& fabs(local_cost_basis - mkt_val_bef_sale(t)) > 0.5)
		{
		if (data_validation_defn == YES)
			{
			makeRunLogYellow();
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "Warning: Inconsistent eio input"
					   << " for " << asset_id
					   << ". The cost basis accounting definition is market value."
					   << " Cost basis " << local_cost_basis 
					   << " differs from market value " << mkt_val_bef_sale(t) 
					   << "." << MSG_ERROR;
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << " Input market value is " << init_mkt_val
					   << ". Cost basis has been set to market value."
					   << MSG_ERROR;
			log_screen.unsetf(ios::fixed);
			}

		return mkt_val_bef_sale(0);
		}

	return local_cost_basis;
	}

if (!existing_asset_indicator && t == commencement_period)
	return mkt_val_bef_sale(t);

if (t == maturity_period)
	return 0.0;

if (cost_basis_defn == ACTUAL_COST)
	return cost_basis(t - 1);

if (cost_basis_defn == MARKET_VALUE)
	return mkt_val_bef_sale(t);

if (cost_basis_defn == STRAIGHT_LINE_AMORTIZATION
	&& t < maturity_period)
	return (cost_basis(t - 1)
			* (1 - 1.0 / (maturity_period - t + 1)));

//if (cost_basis_defn == STRAIGHT_LINE_AMORTIZATION
//	&& t == maturity_period)
return mkt_val_bef_expiry;

}


//@@ END

//@@ START - cost_basis_incr_appreciation
// Cost Basis Increase from Appreciation                                                                                             
// Column:COST_BASIS_INCR_APPRECIATION
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_incr_appreciation(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"cost_basis_incr_appreciation",t);
}



//^^^

#line 1 "cost_basis_incr_appreciation.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (cost_basis_defn == MARKET_VALUE)
	{
	if (t < maturity_period)
		return cost_basis_bef_sale(t) - cost_basis(t - 1);

	return cost_basis_bef_expiry - cost_basis(t - 1);
	}

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_purch
// Cost Basis Purchase                                                                                             
// Column:COST_BASIS_PURCH
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"cost_basis_purch",t);
}



//^^^

#line 1 "cost_basis_purch.EIO_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (purchased_bom_flag && t == commencement_period + 1)
	return cost_basis(t - 1);

if (t == commencement_period)
	return cost_basis(t);

return NO_AVG;

}


//@@ END

//@@ START - cost_basis_sold
// Cost Basis Sold                                                                                             
// Column:COST_BASIS_SOLD
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"cost_basis_sold",t);
}



//^^^

#line 1 "cost_basis_sold.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_date(int t) {
//^^^



//^^^

#line 1 "date.EIO_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - dur_val
// Duration Value                                                                                             
// Column:DUR_VAL
//========================================================
double EIO_ASSET_UDF::eio_asset_dur_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"dur_val",t);
}



//^^^

#line 1 "dur_val.EIO_ASSET.for"
return 0.0; //Index Options do not have a duration measure value

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double EIO_ASSET_UDF::eio_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.EIO_ASSET.for"
if (time_step_flag && !valn_flag
	&& proj_set_sub_loop_num < valn_periods.size())
	write_state_of_world_mp();

if (isMainModel && num_eio == num_eios_to_run)
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
double EIO_ASSET_UDF::eio_asset_gaap_inc_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"gaap_inc_bk_val",t);
}



//^^^

#line 1 "gaap_inc_bk_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_inc_defn == COST_BASIS)
	return cost_basis(t);

if (gaap_inc_defn == MARKET_VALUE)
	return mkt_val(t);

return NO_AVG;

}


//@@ END

//@@ START - gaap_inc_unrealzd_cap_gain
// GAAP Income Unrealized Capital Gain                                                                                             
// Column:GAAP_INC_UNREALZD_CAP_GAIN
//========================================================
double EIO_ASSET_UDF::eio_asset_gaap_inc_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"gaap_inc_unrealzd_cap_gain",t);
}



//^^^

#line 1 "gaap_inc_unrealzd_cap_gain.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_inc_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - gaap_surp_bk_val
// GAAP Surplus Book Value                                                                                             
// Column:GAAP_SURP_BK_VAL
//========================================================
double EIO_ASSET_UDF::eio_asset_gaap_surp_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"gaap_surp_bk_val",t);
}



//^^^

#line 1 "gaap_surp_bk_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gaap_val_defn == COST_BASIS)
	return cost_basis(t);

if (gaap_val_defn == MARKET_VALUE)
	return mkt_val(t);

return NO_AVG;

}


//@@ END

//@@ START - gaap_unrealzd_cap_gain_incr
// GAAP Unrealized Capital Gain Increase                                                                                             
// Column:GAAP_UNREALZD_CAP_GAIN_INCR
//========================================================
double EIO_ASSET_UDF::eio_asset_gaap_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"gaap_unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "gaap_unrealzd_cap_gain_incr.EIO_ASSET.for"
if (t <= commencement_period)
	return NO_AVG;

return gaap_inc_unrealzd_cap_gain(t)
       - gaap_inc_unrealzd_cap_gain(t - 1);

}


//@@ END

//@@ START - index_units_owned
// Index Units Owned                                                                                             
// Column:INDEX_UNITS_OWNED
//========================================================
double EIO_ASSET_UDF::eio_asset_index_units_owned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"index_units_owned",t);
}



//^^^

#line 1 "index_units_owned.EIO_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

return index_units_owned_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - index_units_owned_bef_sale
// Index Units Owned Before Sales                                                                                             
// Column:INDEX_UNITS_OWNED_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_index_units_owned_bef_sale(int t) {
//^^^



//^^^

#line 1 "index_units_owned_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return init_index_units_owned_mp;

if (!existing_asset_indicator && t == commencement_period)
	{
	if (port_defn == INVESTMENT)
		return purch_amt
			   * neg_asset_flag
			   / mkt_val_at_issue;

	// else if (port_defn == HEDGING)
	return purch_amt
		   * neg_asset_flag / index_val(t);
	}

return index_units_owned(t - 1);

}


//@@ END

//@@ START - index_val
// Index Value                                                                                             
// Column:INDEX_VAL
//========================================================
double EIO_ASSET_UDF::eio_asset_index_val(int t) {
//^^^



//^^^

#line 1 "index_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return init_index_val;

if (!existing_asset_indicator && t == commencement_period)
	{
	// Index value must be on same basis as treatment for FIA/IUL liabilities
	if (port_defn == HEDGING && purchased_bom_flag)
		return index_val_calc(t);
	
	// The code below sets the index value based on the value provided in the history
	// First, get original projection date index value
	double index_val = rates->get_index_val(- valn_period, asset_index);

	// Then, grow the index value to the commencement period
	for (int i = - valn_period + 1; i <= commencement_period; i++)
		{
		index_val 
		= index_val 
		  * pow(1.0 + rates->get_index_rate(i,
											asset_index,
											GET_GROWTH_RATE,
											EFFECTIVE_ANNUAL)
											* index_scen_mult + index_scen_addn,
										  (1.0 / 12.0)); 

		}
	return index_val;
	}

if (t > 0)
	return index_val(t - 1)
	       * pow(1.0 + rates->get_index_rate(t,
						asset_index,
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL)
						* index_scen_mult + index_scen_addn,
					  (1.0 / 12.0));

// else if t < 0, must base calculation on starting value
double hist_index_val = init_index_val;

for (int i = -1; i >= t; i--)
	{
	double rate = pow(1.0 + rates->get_index_rate(i + 1,
					asset_index,
					GET_GROWTH_RATE,
					EFFECTIVE_ANNUAL)
					* index_scen_mult + index_scen_addn,
				  (1.0 / 12.0));

	hist_index_val /= rate;
	}

return hist_index_val;

}


//@@ END

//@@ START - index_val_at_expiry_anniv
// Index Value at Expiry Anniversary                                                                                             
// Column:INDEX_VAL_AT_EXPIRY_ANNIV
//========================================================
double EIO_ASSET_UDF::eio_asset_index_val_at_expiry_anniv(int t) {
//^^^



//^^^

#line 1 "index_val_at_expiry_anniv.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return index_val(t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double EIO_ASSET_UDF::eio_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.EIO_ASSET.for"
if (isMainModel)
	{
	static int loaded_proj_task_loop = -999;

	if (loaded_proj_task_loop != proj_task_loop_num)
		{
		rates->initialize(t);
		
		loaded_proj_task_loop = proj_task_loop_num;

		// reinitialize num_eio
		num_eio = 0;
		}

	// increment the number of records
	num_eio++;

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
			throw FatalError("Error: Cannot open eio->asset_detail_rpt_id."
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

if ((eio_initial_values_map_iter = eio_initial_values_map.find(index_val))
	!= eio_initial_values_map.end())
	{
	// if values are in map, then read from map
	initial_values = eio_initial_values_map_iter->second;
	}
else
	{
	// otherwise, add values to map
	is_asset_initialize = 1;

	initial_values = new struct eioInitialValuesData;

	initial_values->spot_sprd_adj = spot_sprd_adj(0);
	initial_values->volatility_sprd_adj = volatility_sprd_adj(0);

	initial_values->yld_numer = yld_numer(0);
	initial_values->mkt_val_bef_sale = mkt_val_bef_sale(0);

	eio_initial_values_map[index_val] = initial_values;

	is_asset_initialize = 0;

	resetValues();
	}

return 1.0;

}


//@@ END

//@@ START - lookback_index_val
// Lookback Index Value                                                                                             
// Column:LOOKBACK_INDEX_VAL
//========================================================
double EIO_ASSET_UDF::eio_asset_lookback_index_val(int t) {
//^^^



//^^^

#line 1 "lookback_index_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (lookback_defn == NONE)
	return NO_AVG;

if (maturity_period - t > lookback_mths - lookback_sampling_mths)
	return NO_AVG;

// Description.  This function returns Asian and Highest Gain values
//	based on samples on expiry anniversary dates. (This is differs from TAS.)
//	For example, suppose that
//		i) the option matures on December 15th, 1994
//		ii) the averaging period is three years and 
//		iii) the sampling frequency is annual.
//	In this case, the final average is based on index values
//	on December 15th of 1992, 1993, and 1994.
//
//*************************************************************************/
//*************************************************************************
// Observed Asian average values and highest gain maximum (or minimum)
// values are always based on the final lookback period.
//
//  End of month sampling points are marked by x's.
//  x-------x-------x-------x-------x-------x-------x-------x-------x
//
//  |--------------------|------------------------------------------|
//  |<-----observed------|-----------$months_to_expiry------------->|
//  |<----------------------$Lookback_Months----------------------->|
//

if (t == commencement_period || t == 0)
 	lookback_index_value_data = SmartArray<double>(0);

int max_array_size = lookback_mths/lookback_sampling_mths;

if (lookback_index_value_data.size() < max_array_size)
	lookback_index_value_data.resize(max_array_size);

int months_to_expiry = maturity_period - t;

int current_array_index
= ((lookback_mths - months_to_expiry)
  / lookback_sampling_mths) - 1;

double lookback_index_value_local_final = 0;

if ((months_to_expiry % lookback_sampling_mths) == 0)
	{
	if (lookback_defn == ASIAN)
		lookback_index_value_data[current_array_index]
		= index_val_at_expiry_anniv(t);
	else if (lookback_defn == HIGHEST_GAIN
			 && opt_defn == CALL)
		lookback_index_value_data[current_array_index]
		= index_val_at_expiry_anniv(t);
	else if (lookback_defn == HIGHEST_GAIN
			 && opt_defn == PUT)
		lookback_index_value_data[current_array_index]
		= min(GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE, index_val_at_expiry_anniv(t));
	}

if (lookback_defn == HIGHEST_GAIN
	&& opt_defn == PUT)
	lookback_index_value_local_final = lookback_index_value_data[current_array_index];

int loop_array;

for (loop_array = 0;
	 loop_array <= current_array_index;
	 loop_array++)
	{
	if (lookback_defn == ASIAN)
		lookback_index_value_local_final
		+= lookback_index_value_data[loop_array];
	else if (lookback_defn == HIGHEST_GAIN
			 && opt_defn == CALL)
		lookback_index_value_local_final
		= max(lookback_index_value_data[loop_array], lookback_index_value_local_final);
	else if (lookback_defn == HIGHEST_GAIN
			 && opt_defn == PUT)
		lookback_index_value_local_final
		= min(lookback_index_value_data[loop_array], lookback_index_value_local_final);
	}

if (lookback_defn == ASIAN)
	{
	int num_of_sampling_points
	= 1 + (lookback_mths - lookback_sampling_mths - months_to_expiry)
		  / lookback_sampling_mths;

	lookback_index_value_local_final
	= lookback_index_value_local_final
	  / num_of_sampling_points;
	}

return lookback_index_value_local_final;

}


//@@ END

//@@ START - mkt_to_bk_ratio
// Market to Book Ratio                                                                                             
// Column:MKT_TO_BK_RATIO
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "mkt_to_bk_ratio.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_mkt_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"mkt_val",t);
}



//^^^

#line 1 "mkt_val.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t < maturity_period)
	return mkt_val_bef_neg_cash_flow_sale(t)
		   * (1 - sold_pct_neg_cash_flow(t));

return NO_AVG;

}


//@@ END

//@@ START - mkt_val_bef_fund_match_sale
// Market Value Before Fund Value Matching Asset Sales                                                                                             
// Column:MKT_VAL_BEF_FUND_MATCH_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_val_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(51,"mkt_val_bef_fund_match_sale",t);
}



//^^^

#line 1 "mkt_val_bef_fund_match_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_mkt_val_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_neg_cash_flow_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_mkt_val_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_rebal_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_mkt_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (isMainModel && t > 0
	&& mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;	

if (t == 0 && existing_asset_indicator
	&& !is_asset_initialize)
	return initial_values->mkt_val_bef_sale; 

if(!existing_asset_indicator && t == commencement_period)
	{
	if (port_defn == INVESTMENT)
		return notional_amt_at_issue;
	}

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - mkt_val_purch
// Market Value Purchase                                                                                             
// Column:MKT_VAL_PURCH
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_val_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(55,"mkt_val_purch",t);
}



//^^^

#line 1 "mkt_val_purch.EIO_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (purchased_bom_flag && t == commencement_period + 1)
	return mkt_val(t - 1);

if (t == commencement_period)
	return mkt_val(t);

return NO_AVG;

}


//@@ END

//@@ START - mkt_val_sold
// Market Value Sold                                                                                             
// Column:MKT_VAL_SOLD
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_val_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"mkt_val_sold",t);
}



//^^^

#line 1 "mkt_val_sold.EIO_ASSET.for"
if ( t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return mkt_val_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - mths_to_next_mkt_val_calc
// Months to Next Market Value Calculation                                                                                             
// Column:MTHS_TO_NEXT_MKT_VAL_CALC
//========================================================
double EIO_ASSET_UDF::eio_asset_mths_to_next_mkt_val_calc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"mths_to_next_mkt_val_calc",t);
}



//^^^

#line 1 "mths_to_next_mkt_val_calc.EIO_ASSET.for"
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

//@@ START - notional_amt
// Notional Amount                                                                                             
// Column:NOTIONAL_AMT
//========================================================
double EIO_ASSET_UDF::eio_asset_notional_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"notional_amt",t);
}



//^^^

#line 1 "notional_amt.EIO_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (t > max(0,commencement_period)
	&& fabs(notional_amt(t - 1)) < ASSET_ACTIVE_THRESHOLD)
	return NO_AVG;

// begin forced calculations
index_units_owned(t);
// end forced calculations

return notional_amt_bef_sale(t)
	   * (1.0 - sold_pct(t));

}


//@@ END

//@@ START - notional_amt_bef_fund_match_sale
// Notional Amount Before Fund Value Matching Asset Sales                                                                                             
// Column:NOTIONAL_AMT_BEF_FUND_MATCH_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_notional_amt_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"notional_amt_bef_fund_match_sale",t);
}



//^^^

#line 1 "notional_amt_bef_fund_match_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_notional_amt_bef_neg_cash_flow_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_neg_cash_flow_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_notional_amt_bef_rebal_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_rebal_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_notional_amt_bef_sale(int t) {
//^^^



//^^^

#line 1 "notional_amt_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return (index_val_at_issue
			* init_index_units_owned_mp);

if (!existing_asset_indicator && t == commencement_period)
	return index_units_owned_bef_sale(t) * index_val(t);

return notional_amt(t - 1);

}


//@@ END

//@@ START - notional_amt_purch
// Notional Amount Purchase                                                                                             
// Column:NOTIONAL_AMT_PURCH
//========================================================
double EIO_ASSET_UDF::eio_asset_notional_amt_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(63,"notional_amt_purch",t);
}



//^^^

#line 1 "notional_amt_purch.EIO_ASSET.for"
if (t < commencement_period || existing_asset_indicator)
	return NO_AVG;

if (purchased_bom_flag && t == commencement_period + 1)
	return notional_amt_at_issue;

if (t == commencement_period)
	return notional_amt_at_issue;

return NO_AVG;

}


//@@ END

//@@ START - notional_amt_sold
// Notional Amount Sold                                                                                             
// Column:NOTIONAL_AMT_SOLD
//========================================================
double EIO_ASSET_UDF::eio_asset_notional_amt_sold(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(64,"notional_amt_sold",t);
}



//^^^

#line 1 "notional_amt_sold.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return notional_amt_bef_sale(t)
	   * sold_pct(t);

}


//@@ END

//@@ START - opt_pmt
// Option Payment                                                                                             
// Column:OPT_PMT
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_pmt(int t) {
//^^^



//^^^

#line 1 "opt_pmt.EIO_ASSET.for"
if (t == maturity_period)
	{
	if (opt_defn == FUTURES)
		return (mkt_val_bef_expiry - index_units_owned(t) * opt_strike_price);

	return mkt_val_bef_expiry;
	}

return NO_AVG;

}


//@@ END

//@@ START - opt_val_asset_down_1
// Option Value Asset Down 1                                                                                             
// Column:OPT_VAL_ASSET_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_asset_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_asset_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_asset_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_asset_down_1_bef_sale
// Option Value Asset Down 1 Before Sales                                                                                             
// Column:OPT_VAL_ASSET_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_asset_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_asset_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_val_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				PRICE_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_asset_up_1
// Option Value Asset Up 1                                                                                             
// Column:OPT_VAL_ASSET_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_asset_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_asset_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_asset_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_asset_up_1_bef_sale
// Option Value Asset Up 1 Before Sales                                                                                             
// Column:OPT_VAL_ASSET_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_asset_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_asset_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_val_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				PRICE_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_baseline
// Option Value Baseline                                                                                             
// Column:OPT_VAL_BASELINE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_baseline(int t) {
//^^^



//^^^

#line 1 "opt_val_baseline.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_baseline_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_baseline_bef_sale
// Option Value Baseline Before Sale                                                                                             
// Column:OPT_VAL_BASELINE_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_baseline_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_baseline_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_down_1
// Option Value Interest Down 1                                                                                             
// Column:OPT_VAL_INT_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_down_1_bef_sale
// Option Value Interest Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_10_down_1
// Option Value Interest Key Rate 10 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_10_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_10_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_10_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_10_down_1_bef_sale
// Option Value Interest Key Rate 10 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_10_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_10_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_10_up_1
// Option Value Interest Key Rate 10 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_10_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_10_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_10_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_10_up_1_bef_sale
// Option Value Interest Key Rate 10 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_10_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_10_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_1_down_1
// Option Value Interest Key Rate 1 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_1_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_1_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_1_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_1_down_1_bef_sale
// Option Value Interest Key Rate 1 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_1_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_1_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_1_up_1
// Option Value Interest Key Rate 1 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_1_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_1_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_1_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_1_up_1_bef_sale
// Option Value Interest Key Rate 1 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_1_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_1_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_2_down_1
// Option Value Interest Key Rate 2 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_2_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_2_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_2_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_2_down_1_bef_sale
// Option Value Interest Key Rate 2 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_2_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_2_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_2_up_1
// Option Value Interest Key Rate 2 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_2_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_2_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_2_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_2_up_1_bef_sale
// Option Value Interest Key Rate 2 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_2_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_2_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_3_down_1
// Option Value Interest Key Rate 3 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_3_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_3_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_2_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_3_down_1_bef_sale
// Option Value Interest Key Rate 3 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_3_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_3_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_3_up_1
// Option Value Interest Key Rate 3 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_3_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_3_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_3_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_3_up_1_bef_sale
// Option Value Interest Key Rate 3 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_3_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_3_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_4_down_1
// Option Value Interest Key Rate 4 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_4_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_4_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_4_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_4_down_1_bef_sale
// Option Value Interest Key Rate 4 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_4_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_4_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_4_up_1
// Option Value Interest Key Rate 4 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_4_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_4_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_4_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_4_up_1_bef_sale
// Option Value Interest Key Rate 4 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_4_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_4_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_5_down_1
// Option Value Interest Key Rate 5 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_5_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_5_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_5_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_5_down_1_bef_sale
// Option Value Interest Key Rate 5 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_5_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_5_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_5_up_1
// Option Value Interest Key Rate 5 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_5_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_5_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_5_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_5_up_1_bef_sale
// Option Value Interest Key Rate 5 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_5_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_5_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_6_down_1
// Option Value Interest Key Rate 6 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_6_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_6_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_6_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_6_down_1_bef_sale
// Option Value Interest Key Rate 6 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_6_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_6_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_6_up_1
// Option Value Interest Key Rate 6 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_6_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_6_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_6_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_6_up_1_bef_sale
// Option Value Interest Key Rate 6 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_6_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_6_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_7_down_1
// Option Value Interest Key Rate 7 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_7_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_7_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_7_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_7_down_1_bef_sale
// Option Value Interest Key Rate 7 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_7_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_7_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_7_up_1
// Option Value Interest Key Rate 7 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_7_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_7_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_7_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_7_up_1_bef_sale
// Option Value Interest Key Rate 7 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_7_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_7_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_8_down_1
// Option Value Interest Key Rate 8 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_8_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_8_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_8_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_8_down_1_bef_sale
// Option Value Interest Key Rate 8 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_8_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_8_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_8_up_1
// Option Value Interest Key Rate 8 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_8_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_8_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_8_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_8_up_1_bef_sale
// Option Value Interest Key Rate 8 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_8_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_8_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_9_down_1
// Option Value Interest Key Rate 9 Down 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_9_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_9_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_9_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_9_down_1_bef_sale
// Option Value Interest Key Rate 9 Down 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_9_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_9_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_9_up_1
// Option Value Interest Key Rate 9 Up 1                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_9_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_9_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_key_rate_9_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_key_rate_9_up_1_bef_sale
// Option Value Interest Key Rate 9 Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_KEY_RATE_9_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_key_rate_9_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_up_1
// Option Value Interest Up 1                                                                                             
// Column:OPT_VAL_INT_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_int_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_int_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_int_up_1_bef_sale
// Option Value Interest Up 1 Before Sale                                                                                             
// Column:OPT_VAL_INT_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_int_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_int_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->yield_shifts map must be filled with up shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				YIELD_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_down_1
// Option Value Volatility Down 1                                                                                             
// Column:OPT_VAL_VOL_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_down_1_bef_sale
// Option Value Volatility Down 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_1_down_1
// Option Value Volatility Term 1 Down 1                                                                                             
// Column:OPT_VAL_VOL_TERM_1_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_1_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_1_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_1_down_1_bef_sale
// Option Value Volatility Term 1 Down 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_1_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_1_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_1_up_1
// Option Value Volatility Term 1 Up 1                                                                                             
// Column:OPT_VAL_VOL_TERM_1_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_1_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_1_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_1_up_1_bef_sale
// Option Value Volatility Term 1 Up 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_1_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_1_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_2_down_1
// Option Value Volatility Term 2 Down 1                                                                                             
// Column:OPT_VAL_VOL_TERM_2_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_2_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_2_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_2_down_1_bef_sale
// Option Value Volatility Term 2 Down 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_2_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_2_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_2_up_1
// Option Value Volatility Term 1 Up 1                                                                                             
// Column:OPT_VAL_VOL_TERM_2_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_2_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_2_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_2_up_1_bef_sale
// Option Value Volatility Term 2 Up 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_2_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_2_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_3_down_1
// Option Value Volatility Term 3 Down 1                                                                                             
// Column:OPT_VAL_VOL_TERM_3_DOWN_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_down_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_3_down_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_3_down_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_3_down_1_bef_sale
// Option Value Volatility Term 3 Down 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_3_DOWN_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_down_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_3_down_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_3_up_1
// Option Value Volatility Term 3 Up 1                                                                                             
// Column:OPT_VAL_VOL_TERM_3_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_3_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_term_3_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_term_3_up_1_bef_sale
// Option Value Volatility Term 3 Up 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_TERM_3_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_term_3_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_up_1
// Option Value Volatility Up 1                                                                                             
// Column:OPT_VAL_VOL_UP_1
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_up_1(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_up_1.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return opt_val_vol_up_1_bef_sale(t)
		   * (1.0 - sold_pct(t));

return NO_AVG;

}


//@@ END

//@@ START - opt_val_vol_up_1_bef_sale
// Option Value Volatility Up 1 Before Sales                                                                                             
// Column:OPT_VAL_VOL_UP_1_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_opt_val_vol_up_1_bef_sale(int t) {
//^^^



//^^^

#line 1 "opt_val_vol_up_1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// IMPORTANT: The rates->index_vols_shifts map must be filled with down shifts before this column is called.

if (t < maturity_period)
	return mkt_val_calc(t,
				xint(cal_yr_relative(t)),
				xint(cal_mth(t)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned_bef_sale(t),
				index_val(t),
				index_scen_mult,
				index_scen_addn,
				((maturity_period - t) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(t),
				volatility_sprd_adj(t),
				NO_SHIFT, /* index_val_shift_defn */
				VOL_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return NO_AVG;

}


//@@ END

//@@ START - rbc_c1
// Risk Based Capital C1                                                                                             
// Column:RBC_C1
//========================================================
double EIO_ASSET_UDF::eio_asset_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(132,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_rbc_c1_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(133,"rbc_c1_bef_sale",t);
}



//^^^

#line 1 "rbc_c1_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return rbc_c1_pct * bk_val_bef_sale(t);

}


//@@ END

//@@ START - realzd_cap_gain
// Realized Capital Gain                                                                                             
// Column:REALZD_CAP_GAIN
//========================================================
double EIO_ASSET_UDF::eio_asset_realzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(134,"realzd_cap_gain",t);
}



//^^^

#line 1 "realzd_cap_gain.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return realzd_cap_gain_opt_pmt(t);

}


//@@ END

//@@ START - realzd_cap_gain_opt_pmt
// Realized Capital Gain from Option Payment                                                                                             
// Column:REALZD_CAP_GAIN_OPT_PMT
//========================================================
double EIO_ASSET_UDF::eio_asset_realzd_cap_gain_opt_pmt(int t) {
//^^^



//^^^

#line 1 "realzd_cap_gain_opt_pmt.EIO_ASSET.for"
if (t == maturity_period)
	return opt_pmt(t)
		   - cost_basis_bef_expiry;

return NO_AVG;

}


//@@ END

//@@ START - realzd_cap_gain_sale
// Realized Capital Gain from Sales                                                                                             
// Column:REALZD_CAP_GAIN_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_realzd_cap_gain_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(136,"realzd_cap_gain_sale",t);
}



//^^^

#line 1 "realzd_cap_gain_sale.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (sold_pct(t) == 0.0)
	return 0.0;

return cap_gain_from_sale(t)
	   + unrealzd_cap_gain_released_on_sale(t);

}


//@@ END

//@@ START - sold_pct
// Sold Percent                                                                                             
// Column:SOLD_PCT
//========================================================
double EIO_ASSET_UDF::eio_asset_sold_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(137,"sold_pct",t);
}



//^^^

#line 1 "sold_pct.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_sold_pct_fund_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(138,"sold_pct_fund_match",t);
}



//^^^

#line 1 "sold_pct_fund_match.EIO_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_neg_cash_flow
// Sold Percent Negative Cash Flow                                                                                             
// Column:SOLD_PCT_NEG_CASH_FLOW
//========================================================
double EIO_ASSET_UDF::eio_asset_sold_pct_neg_cash_flow(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(139,"sold_pct_neg_cash_flow",t);
}



//^^^

#line 1 "sold_pct_neg_cash_flow.EIO_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_planned
// Sold Percent Planned                                                                                             
// Column:SOLD_PCT_PLANNED
//========================================================
double EIO_ASSET_UDF::eio_asset_sold_pct_planned(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(140,"sold_pct_planned",t);
}



//^^^

#line 1 "sold_pct_planned.EIO_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - sold_pct_rebal
// Sold Percent Rebalancing                                                                                             
// Column:SOLD_PCT_REBAL
//========================================================
double EIO_ASSET_UDF::eio_asset_sold_pct_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(141,"sold_pct_rebal",t);
}



//^^^

#line 1 "sold_pct_rebal.EIO_ASSET.for"
//this column value is set using SetValue from inside the asset sales routines
return NO_AVG;

}


//@@ END

//@@ START - spot_sprd_adj
// Spot Spread Adjustment                                                                                             
// Column:SPOT_SPRD_ADJ
//========================================================
double EIO_ASSET_UDF::eio_asset_spot_sprd_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(142,"spot_sprd_adj",t);
}



//^^^

#line 1 "spot_sprd_adj.EIO_ASSET.for"
if (t < max(0, commencement_period) || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator)
	return 0.0;

if (t == 0 
	&& !is_asset_initialize)
	return initial_values->spot_sprd_adj; 

if (asset_mkt_sprd_use_defn == SET_TO_ZERO)
	return 0.0;

if (t > 0)
	{
	if (asset_mkt_sprd_use_defn == HOLD_LEVEL)
		return spot_sprd_adj(t - 1);

	if (asset_mkt_sprd_use_defn == GRADE_TO_ZERO)
		return spot_sprd_adj(t - 1)
			   * (1.0 - 1.0 / (1.0 + (maturity_period - t)));

	log_screen << "Error. Unrecognized asset_mkt_sprd_use_defn (" << asset_mkt_sprd_use_defn
			   << ") in eio->spot_sprd_adj column."
			   << MSG_ERROR;

	throw FatalError(" Please correct your input assumptions.");
	}

if (fabs(init_mkt_val) < model_point_amount_threshold)
	return 0.0;

// Solve for spot spread at model start date

double target_value = init_mkt_val * neg_asset_flag;

if (init_mkt_val_calc == target_value)
	return 0.0;

if (init_mkt_val_calc < target_value
	&& (payout_index_max <= 0.0
		|| payout_index_max > GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE))
	return 0.0;

// Local Variables
int months_to_maturity = maturity_period - t;
int index_val_shift_defn = NO_SHIFT;
int index_vol_shift_defn = NO_SHIFT;
int int_rate_shift_defn = NO_SHIFT;
int maximum_iterations = 0;
double tolerance = 0.0;
double low_spread = 0.0;
double high_spread = 0.0;
double guess_spread = 0.0;
double guess_value = 0.0;
double adjustment_factor = 0.0;
double low_value = 0.0;
double high_value = 0.0;
double value_factor = 0.0;
int temploop = 0;
double spread_factor = 0.0;
int decrease_value = 0;
int increase_value = 0;
int decrease_spread = 0;
int increase_spread = 0;
int loop1 = 0;
int done_eio_1 = 0;
int loop2 = 0;
int loop3 = 0;
int loop4 = 0;
int done_eio_2 = 0;
int loop5 = 0;
int loop6 = 0;
double solve_for_spread_differences[2][2 + SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS];
double solve_for_spread_spreads[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double solve_for_spread_present_values[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double adjustment_spot_spread_local = 0;
double adjustment_volatility_spread_local = 0;

maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;
tolerance = SOLVE_FOR_SPREAD_TOLERANCE;
low_spread = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;
high_spread = SOLVE_FOR_SPREAD_LOWEST_SPREAD;

int cal_yr = xint(this->cal_yr(t));
int cal_mth = xint(this->cal_mth(t));

// reduce tolerance if target is too large
if (ceil(log10(fabs(target_value))) > 9)
	tolerance
	= tolerance * pow(10.0, ceil(log10(fabs(target_value))) - 9);

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Spot Spread Adjustment"
			<< " for " << asset_id
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	asset_detail_pv_output();

	if (asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << "InitialMktVal,"	<< write_string(init_mkt_val_calc,PVCLen,PVCSigDig) << endl
				<< "TargetVal," << write_string(target_value,PVCLen,PVCSigDig) << endl;
		}
	}

adjustment_volatility_spread_local = 0.0;
adjustment_factor = 0.9;

// Locate low value, high spread.

if (init_mkt_val_calc > target_value)
	{
	decrease_value = 1;
	increase_value = 0;
	low_spread = 0.0;
	high_value = init_mkt_val_calc;
	decrease_spread = 0;
	increase_spread = 1;
	}
else
	{
	decrease_value = 0;
	increase_value = 1;
	high_spread = 0.0;
	low_value = init_mkt_val_calc;
	decrease_spread = 1;
	increase_spread = 0;
	}

for (loop4 = 0;
	loop4 < maximum_iterations && (decrease_spread < 2 || increase_spread < 2);
	loop4++)
	{
	if (increase_spread == 1)
		guess_spread = (adjustment_factor + low_spread) / adjustment_factor;
	else
		{
		guess_spread
		= max(-rates->get_int_rate(t,
                        "Govt",
						GET_SPOT_RATE,
						(maturity_period - t),
						0.0 /* fwd term */,
						NOMINAL_SEMIANNUAL,
						int_rate_shift_defn,0),//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			  high_spread - (1.0 - (pow(adjustment_factor, loop4 + 1)))
							* (NOMINAL_SEMIANNUAL
							   + high_spread));
		} // endif

	guess_value = mkt_val_calc(t,
						cal_yr,
						cal_mth,
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned(t),
						index_val(t),
						index_scen_mult,
						index_scen_addn,
						((maturity_period - t) / 12.0),
						div_yld_scen_mult,
						div_yld_addn,
						opt_strike_price,
						payout_index_max,
						opt_defn,
						guess_spread,
						adjustment_volatility_spread_local,
						index_val_shift_defn,
						index_vol_shift_defn,
						int_rate_shift_defn);

	if (asset_detail_pv_flag(t))
		{
		PVCText << "Solve Loop: " << loop4
				<< " for " << asset_id
				<< " t=" << t
				<< " CalYr=" << cal_yr
				<< " CalMth=" << cal_mth;
		if (asset_detail_rpt_pv_defn == YES)
			PVCText << endl;
		else
			asset_detail_pv_output();
		PVCText	<< "GsSprd," << write_string(guess_spread,PVCLen,PVCSigDig) << endl
				<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
				<< "LowSprd," << write_string(low_spread,PVCLen,PVCSigDig) << endl
				<< "LowVal,"	<< write_string(low_value,PVCLen,PVCSigDig) << endl
				<< "HighSprd," << write_string(high_spread,PVCLen,PVCSigDig) << endl
				<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig);
		asset_detail_pv_output();
		}

	if (decrease_value == 1)
		{
		if (guess_value >= high_value)
			{ // If we are not getting closer,
			//   change direction of increment to spread.
			decrease_spread = decrease_spread + 1;
			increase_spread = increase_spread + 1;
			}
		else
			{
			if (guess_value > target_value)
				{ // Reset high value and corresponding spread.
				low_spread = guess_spread;
				high_value = guess_value;
				}
			else
				{ // Otherwise, exit for loop.
				loop4 = maximum_iterations;
				} // endif
			} // endif
		} // endif

	if (increase_value == 1)
		{
		if (guess_value <= low_value)
			{ // If we are not getting closer,
			//   change direction of increment to spread.
			decrease_spread = decrease_spread + 1;
			increase_spread = increase_spread + 1;
			}
		else
			{
			if (guess_value < target_value)
				{ // Reset low value and corresponding spread.
				high_spread = guess_spread;
				low_value = guess_value;
				}
			else
				{ // Otherwise, exit for loop.
				loop4 = maximum_iterations;
				} // endif
			} // endif
		} // endif
	} // end_for over loop4

if (decrease_spread > 1 && increase_spread > 1)
	{
	if (data_validation_defn == YES)
		{
		makeRunLogYellow();
		log_screen.setf(ios::fixed);
		log_screen << "Warning: Cannot solve for spot spread"
				 << " for index opton Id=" << asset_id
				 << ". Spot spread set to zero. "
				 << "Target value is " << target_value
				 << ". Value using zero spread is " << init_mkt_val_calc
				 << MSG_ERROR;
		log_screen.unsetf(ios::fixed);
		}

	PVCFile.setf(ios::fixed);
	PVCFile << PVCounter
			<< "<-- Warning: Cannot solve for spot spread"
			<< " for index opton Id=" << asset_id
			<< ". Spot spread set to zero. "
			<< "Target value is " << target_value
			<< ". Value using zero spread is " << init_mkt_val_calc
			<< endl;
	PVCFile.unsetf(ios::fixed);
	PVCounter--;

	return 0.0;
	} // endif

if (increase_value == 1)
	{
	low_spread = guess_spread;
	high_value = guess_value;
	}
else
	{
	high_spread = guess_spread;
	low_value = guess_value;
	} // endif

// Solve for spread.
done_eio_2 = 0;

while (!done_eio_2)
	{
	// Initialize $Solve_For_spread_spreads and $Solve_For_spread_Present_values
	solve_for_spread_present_values[0] = low_value;
	solve_for_spread_spreads[0] = high_spread;
	solve_for_spread_present_values[1] = high_value;
	solve_for_spread_spreads[1] = low_spread;
	solve_for_spread_differences[0][0] = solve_for_spread_spreads[0];

	for (loop5 = 2; loop5 < 2 + maximum_iterations; loop5++)
		{
		if (loop5 > 2)
			{ // Copy Diff[1][  * ] to Diff[0][  * ].
			for (temploop = 0; temploop < loop5 - 1; temploop++)
				{
				solve_for_spread_differences[0][temploop]
				= solve_for_spread_differences[1][temploop];
				}   // end_for
			} // endif

		solve_for_spread_differences[1][0] = solve_for_spread_spreads[loop5 - 1];

		for (temploop = 1; temploop < loop5; temploop++)
			{
			solve_for_spread_differences[1][temploop]
			= (solve_for_spread_differences[1][temploop - 1]
			   - solve_for_spread_differences[0][temploop - 1])
			  / (solve_for_spread_present_values[loop5 - 1]
				 - solve_for_spread_present_values[loop5 - temploop - 1]);
			}   // end_for

		if (loop5 > 2)
			spread_factor = solve_for_spread_differences[1][0];
		else
			spread_factor = solve_for_spread_spreads[0];

		// CALCULATE value_factor
		if (loop5 == 2)
			{
			value_factor
			= (target_value - solve_for_spread_present_values[loop5 - 2]);
			} // end_condition
		else
			{
			value_factor
			= value_factor * (target_value - solve_for_spread_present_values[loop5 - 2]);
			} // end_condition

		// Get new spread.
		guess_spread
        = spread_factor + value_factor * solve_for_spread_differences[1][loop5 - 1];

		// Start over, if we are not getting closer.
		if (guess_spread > high_spread || guess_spread < low_spread)
			loop5 = 2 + maximum_iterations;
		else
			{
			guess_value = mkt_val_calc(t,
								cal_yr,
								cal_mth,
								lookback_defn,
								lookback_mths,
								lookback_sampling_mths,
								index_units_owned(t),
								index_val(t),
								index_scen_mult,
								index_scen_addn,
								((maturity_period - t) / 12.0),
								div_yld_scen_mult,
								div_yld_addn,
								opt_strike_price,
								payout_index_max,
								opt_defn,
								guess_spread,
								adjustment_volatility_spread_local,
								index_val_shift_defn,
								index_vol_shift_defn,
								int_rate_shift_defn);

			if (asset_detail_pv_flag(t))
				{
				PVCText << "Interpolation Solve Loop: " << loop5 - 2
						<< " for " << asset_id
						<< " t=" << t
						<< " CalYr=" << cal_yr
						<< " CalMth=" << cal_mth;
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_pv_output();
				PVCText << "GsSprd," << write_string(guess_spread,PVCLen,PVCSigDig) << endl
						<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
						<< "LowSprd," << write_string(low_spread,PVCLen,PVCSigDig) << endl
						<< "LowVal,"	<< write_string(low_value,PVCLen,PVCSigDig) << endl
						<< "HighSprd," << write_string(high_spread,PVCLen,PVCSigDig) << endl
						<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig);
				asset_detail_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				{
				adjustment_spot_spread_local = guess_spread;
				done_eio_2 = 1;
				loop5 = 2 + maximum_iterations;
				}
			else
				{ // Otherwise, reset high and low yields.
				if (guess_value < target_value)
					{
					low_value = guess_value;
					high_spread = guess_spread;
					}
				else
					{
					high_value = guess_value;
					low_spread = guess_spread;
					} // endif
				} // endif

			if (!done_eio_2)
				{
				solve_for_spread_present_values[loop5] = guess_value;
				solve_for_spread_spreads[loop5] = guess_spread;
				} // endif
			} // endif
		} // end_for over loop5

	// If not done, reduce interval by factor of 4 (2 bisections) and start over.
	if (!done_eio_2)
		{
		for (loop6 = 0; loop6 < 2; loop6++)
			{
			guess_spread = (low_spread + high_spread) / 2.0;
			guess_value = mkt_val_calc(t,
								cal_yr,
								cal_mth,
								lookback_defn,
								lookback_mths,
								lookback_sampling_mths,
								index_units_owned(t),
								index_val(t),
								index_scen_mult,
								index_scen_addn,
								((maturity_period - t) / 12.0),
								div_yld_scen_mult,
								div_yld_addn,
								opt_strike_price,
								payout_index_max,
								opt_defn,
								guess_spread,
								adjustment_volatility_spread_local,
								index_val_shift_defn,
								index_vol_shift_defn,
								int_rate_shift_defn);

			if (asset_detail_pv_flag(t))
				{
				PVCText << "Bisection Solve Loop: " << loop6
						<< " for " << asset_id
						<< " t=" << t
						<< " CalYr=" << cal_yr
						<< " CalMth=" << cal_mth;
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_pv_output();
				PVCText	<< "GsSprd," << write_string(guess_spread,PVCLen,PVCSigDig) << endl
						<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
						<< "LowSprd," << write_string(low_spread,PVCLen,PVCSigDig) << endl
						<< "LowVal," << write_string(low_value,PVCLen,PVCSigDig) << endl
						<< "HighSprd," << write_string(high_spread,PVCLen,PVCSigDig) << endl
						<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig);
				asset_detail_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				{
				adjustment_spot_spread_local = guess_spread;
				done_eio_2 = 1;
				loop6 = 999;
				}
			else
				{ // Otherwise, reset high and low yields
				if (guess_value < target_value)
					{
					low_value = guess_value;
					high_spread = guess_spread;
					}
				else
					{
					high_value = guess_value;
					low_spread = guess_spread;
					} // endif
				} // endif
			} // end_for ($loop6=0; $loop6<2; $loop6++)
		} // endif !done_eio_2
	} // end_while !done_eio_2

if (asset_detail_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Spot Spread Adjustment ("
			<< write_string(adjustment_spot_spread_local,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	asset_detail_pv_output();
	PVCounter--;
	}

return adjustment_spot_spread_local;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double EIO_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.EIO_ASSET.for"
#if 0 // START_HEADER
struct eioInitialValuesData
	{
	double spot_sprd_adj;
	double volatility_sprd_adj;
	double yld_numer;
	double mkt_val_bef_sale;
	};
typedef map <xstring, struct eioInitialValuesData*, less<xstring> > eioivmap;
#endif // END_HEADER

#if 0 // START_EXTERNS
int num_eios_to_run;
int num_eio = 0;
sowfinput eio_mp_input;
sowfcols eio_mp_input_cols;
extern sowmpoutput eio_state_of_world_mp_output;
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;

static eioivmap eio_initial_values_map;
static eioivmap::iterator eio_initial_values_map_iter;
extern bool is_asset_initialize;
#endif // END_EXTERNS

#if 0 // START_CLASS
int sequence_id;
struct eioInitialValuesData* initial_values;
int calculated_t_low;
int calculated_t_high;
SmartArray <double> lookback_index_value_data;
bool purchased_bom_flag;
double purch_amt;
int purch_asset_mp_num;

// Model point variables
xstring seg_id;
xstring hdg_grp_code;
xstring asset_index;
StrEnum::EnumValue port_defn;
StrEnum::EnumValue sale_class;
xstring maturity_date;
xstring planned_sale_date;
double init_cost_basis;
double init_bk_val;
double init_mkt_val;
double init_index_units_owned;
double init_index_val;
double opt_strike_price;
double index_val_at_issue;
double payout_index_max;
StrEnum::EnumValue opt_defn;
double index_scen_mult;
double index_scen_addn;
double div_yld_scen_mult;
double div_yld_addn;
StrEnum::EnumValue lookback_defn;
StrEnum::EnumValue lookback_sampling_interval;
double lookback_yrs;
double avr_contribn_pct;
double avr_max_pct;
double avr_obj_pct;
double rbc_c1_pct;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
sequence_id = 0;
initial_values = NULL;
purchased_bom_flag = false;
purch_amt = 0.0;
purch_asset_mp_num = -1;

// Initialize model point variables
seg_id = "Seg";
hdg_grp_code = "DEFAULT";
asset_index = "Equity";
port_defn = INVESTMENT;
sale_class = AVAILABLE_FOR_SALE; 
maturity_date = "1900/01/01";
planned_sale_date = "9999/01/01"; 
init_cost_basis = 0.0;
init_bk_val = 0.0;
init_mkt_val = 0.0;
init_index_units_owned = 0.0;
init_index_val = 0.0;
opt_strike_price = 0.0;
index_val_at_issue = 0.0;
payout_index_max = 0.0;
opt_defn = CALL;
index_scen_mult = 1.0;
index_scen_addn = 0.0;
div_yld_scen_mult = 1.0;
div_yld_addn = 0.0;
lookback_defn = NONE;
lookback_sampling_interval = ANNUAL;
lookback_yrs = 0.0;
avr_contribn_pct = 0.0;
avr_max_pct = 0.0;
avr_obj_pct = 0.0;
rbc_c1_pct = 0.0;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
if (PVCFile != NULL)
	PVCFile.close();
#endif // END_TERMINATOR

purch_asset_id = "NONE";
purchased_bom_flag = false;

if (use_mp == NO)
	{
	skipModelPoint();
	return 1.0;
	}

// Setup submodel data
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
		num_eios_to_run = calc_num_records_to_run();
		}

	#if defined(ASSET_ONLY_MODEL)
	rates = sm_eio_rates;
	#endif
	}
else
	{
	#if defined(ASSET_ONLY_MODEL)
	if (sm_eio_rates && !sm_eio_rates->isShrunk)
		sm_eio_rates->shrink();
	#endif

	rates = asset->rates;
	}

if (!isMainModel
    && !investing_flag
	&& asset->num_eios_init > - 1
	&& getElementNumber() >= asset->num_eios_init)
	return 1.0;

if (investing_flag)
	{
	purch_asset_mp_num = asset->purch_asset_mp_num;

	t_low = calculated_t_low = xint(commencement_period);
	t_high = calculated_t_high = xint(maturity_period);

	return 1.0;
	}

setup_existing_asset();

t_low = calculated_t_low = xint(commencement_period);
t_high = calculated_t_high = xint(maturity_period);

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
double EIO_ASSET_UDF::eio_asset_sub_port_id(int t) {
//^^^



//^^^

#line 1 "sub_port_id.EIO_ASSET.for"
if (t < commencement_period || isMainModel)
	return NO_AVG;

double dur_for_transfer = 0;

if (t <= maturity_period)
	{
	if (asset->asset_sub_port_assign_dur_defn == EFFECTIVE_DURATION)
//		dur_for_transfer = 0.0001; // not calculated for index options, but should be calculated
		dur_for_transfer = (maturity_period - t) / 12.0;

	else if (asset->asset_sub_port_assign_dur_defn == WEIGHTED_AVERAGE_LIFE)
		dur_for_transfer = 0.0001; // not calculated for index options, but should be years to maturity
	
	else // if (asset->asset_port_assign_dur == YEARS_TO_MATURITY)
		dur_for_transfer
		= (maturity_period - t) / 12.;
	}

if (existing_asset_indicator && t == 0)
	return asset->asset_sub_port_assign(t, 1, "Index Option",
					port_defn,
					category_id,
					existing_asset_indicator,					
					dur_for_transfer,
					-1);

if (!existing_asset_indicator && t == commencement_period)
	return asset->asset_sub_port_assign(t, 1, "Index Option",
					port_defn,
					category_id,
					existing_asset_indicator,					
					dur_for_transfer,
					purch_asset_sub_port);

return sub_port_id(t - 1);

}


//@@ END

//@@ START - unrealzd_cap_gain
// Unrealized Capital Gain                                                                                             
// Column:UNREALZD_CAP_GAIN
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(145,"unrealzd_cap_gain",t);
}



//^^^

#line 1 "unrealzd_cap_gain.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return unrealzd_cap_gain_bef_neg_cash_flow_sale(t)
		   * (1.0 - sold_pct_neg_cash_flow(t));

return 0.0;

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_fund_match_sale
// Unrealized Capital Gain Before Fund Value Matching Asset Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_FUND_MATCH_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_fund_match_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(146,"unrealzd_cap_gain_bef_fund_match_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_fund_match_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return unrealzd_cap_gain_bef_sale(t)
    	   * (1.0 - sold_pct_planned(t));
    	   
return 0.0;

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_neg_cash_flow_sale
// Unrealized Capital Gain Before Negative Cash Flow Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_NEG_CASH_FLOW_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"unrealzd_cap_gain_bef_neg_cash_flow_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_neg_cash_flow_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return unrealzd_cap_gain_bef_rebal_sale(t)
    	   * (1.0 - sold_pct_rebal(t));
    	   
return 0.0;

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_rebal_sale
// Unrealized Capital Gain Before Rebalancing Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_REBAL_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_rebal_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(148,"unrealzd_cap_gain_bef_rebal_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_bef_rebal_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return unrealzd_cap_gain_bef_fund_match_sale(t)
    	   * (1.0 - sold_pct_fund_match(t));
    	   
return 0.0;

}


//@@ END

//@@ START - unrealzd_cap_gain_bef_sale
// Unrealized Capital Gain Before Sales                                                                                             
// Column:UNREALZD_CAP_GAIN_BEF_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_sale(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_bef_sale.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t < maturity_period)
	return bk_val_bef_sale(t) 
		   - cost_basis_bef_sale(t);

return bk_val_bef_expiry
	   - cost_basis_bef_expiry;

}


//@@ END

//@@ START - unrealzd_cap_gain_gaap_surp
// Unrealized Capital Gain GAAP Surplus                                                                                             
// Column:UNREALZD_CAP_GAIN_GAAP_SURP
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_gaap_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(150,"unrealzd_cap_gain_gaap_surp",t);
}



//^^^

#line 1 "unrealzd_cap_gain_gaap_surp.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return gaap_surp_bk_val(t) - cost_basis(t);

}


//@@ END

//@@ START - unrealzd_cap_gain_incr
// Unrealized Capital Gain Increase                                                                                             
// Column:UNREALZD_CAP_GAIN_INCR
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(151,"unrealzd_cap_gain_incr",t);
}



//^^^

#line 1 "unrealzd_cap_gain_incr.EIO_ASSET.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (bk_val_bef_sale(t) - cost_basis_bef_sale(t))
	   - (bk_val(t - 1) - cost_basis(t - 1));

}


//@@ END

//@@ START - unrealzd_cap_gain_released_on_sale
// Unrealized Capital Gain Released on Sale                                                                                             
// Column:UNREALZD_CAP_GAIN_RELEASED_ON_SALE
//========================================================
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_released_on_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(152,"unrealzd_cap_gain_released_on_sale",t);
}



//^^^

#line 1 "unrealzd_cap_gain_released_on_sale.EIO_ASSET.for"
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
double EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_to_bk_ratio(int t) {
//^^^



//^^^

#line 1 "unrealzd_cap_gain_to_bk_ratio.EIO_ASSET.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (fabs(bk_val_bef_sale(t)) < model_point_amount_threshold)
	return USLIB_MIN_DOUBLE;

return unrealzd_cap_gain_bef_sale(t)
       / bk_val_bef_sale(t);

}


//@@ END

//@@ START - volatility_sprd_adj
// Volatility Spread Adjustment                                                                                             
// Column:VOLATILITY_SPRD_ADJ
//========================================================
double EIO_ASSET_UDF::eio_asset_volatility_sprd_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(154,"volatility_sprd_adj",t);
}



//^^^

#line 1 "volatility_sprd_adj.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator)
	return 0.0;

if (t == 0 
	&& !is_asset_initialize)
	return initial_values->volatility_sprd_adj; 

if (asset_mkt_sprd_use_defn == SET_TO_ZERO)
	return 0.0;

if (t > 0)
	{
	if (asset_mkt_sprd_use_defn == HOLD_LEVEL)
		return volatility_sprd_adj(t - 1);

	if (asset_mkt_sprd_use_defn == GRADE_TO_ZERO)
		return volatility_sprd_adj(t - 1)
			   * (1.0 - 1.0 / (1.0 + (maturity_period - t)));

	log_screen << "Error. Unrecognized asset_mkt_sprd_use_defn (" << asset_mkt_sprd_use_defn
			   << ") in eio->volatility_sprd_adj column."
			   << MSG_ERROR;

	throw FatalError(" Please correct your input assumptions.");
	}

if (fabs(init_mkt_val) < model_point_amount_threshold)
	return 0.0;

// Solve for volatility spread at model start date
double target_value = init_mkt_val * neg_asset_flag;

if (init_mkt_val_calc == target_value)
	return 0.0;

if (init_mkt_val_calc >= target_value
	  || (payout_index_max > 0.0
		  && payout_index_max <= GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE))
	return 0.0;

// Local Variables
int months_to_maturity = maturity_period - t;
int index_val_shift_defn = NO_SHIFT;
int index_vol_shift_defn = NO_SHIFT;
int int_rate_shift_defn = NO_SHIFT;
double adjustment_volatility_spread_local=0;
int maximum_iterations = 0;
double tolerance = 0.0;
double low_spread = 0.0;
double high_spread = 0.0;
double guess_spread = 0.0;
double guess_value = 0.0;
double adjustment_factor = 0.0;
double low_value = 0.0;
double high_value = 0.0;
double value_factor = 0.0;
int temploop = 0;
double spread_factor = 0.0;
int decrease_value = 0;
int increase_value = 0;
int decrease_spread = 0;
int increase_spread = 0;
int loop1 = 0;
int done_eio_1 = 0;
int loop2 = 0;
int loop3 = 0;
int loop4 = 0;
int done_eio_2 = 0;
int loop5 = 0;
int loop6 = 0;
double solve_for_spread_differences[2][2 + SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS];
double solve_for_spread_spreads[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double solve_for_spread_present_values[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double adjustment_spot_spread_local = 0.0;

maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;
tolerance = SOLVE_FOR_SPREAD_TOLERANCE;
low_spread = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;
high_spread = SOLVE_FOR_SPREAD_LOWEST_SPREAD;

int cal_yr = xint(this->cal_yr(t));
int cal_mth = xint(this->cal_mth(t));

// Reduce tolerance if target is too large
if (ceil(log10(fabs(target_value))) > 9)
	tolerance = tolerance * pow(10.0, ceil(log10(fabs(target_value))) - 9);

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Volatility Spread Adjustment"
			<< " for " << asset_id
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	asset_detail_pv_output();

	if (asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << "InitialMktVal,"	<< write_string(init_mkt_val_calc,PVCLen,PVCSigDig) << endl
				<< "TargetVal," << write_string(target_value,PVCLen,PVCSigDig) << endl;
		}
	}

adjustment_spot_spread_local = 0.0;

// Locate high value, high spread.
guess_spread = 0.0;
guess_value = init_mkt_val_calc;
adjustment_factor = 0.9;

for (loop1 = 0; loop1 < maximum_iterations && guess_value < target_value; loop1++)
	{
	low_spread = guess_spread;
	low_value = guess_value;
	guess_spread = (adjustment_factor + low_spread) / adjustment_factor;
	guess_value = mkt_val_calc(t,
						cal_yr,
						cal_mth,
						lookback_defn,
						lookback_mths,
						lookback_sampling_mths,
						index_units_owned(t),
						index_val(t),
						index_scen_mult,
						index_scen_addn,
						((maturity_period - t) / 12.0),
						div_yld_scen_mult,
						div_yld_addn,
						opt_strike_price,
						payout_index_max,
						opt_defn,
						adjustment_spot_spread_local,
						guess_spread,
						index_val_shift_defn,
						index_vol_shift_defn,
						int_rate_shift_defn);
	} // end_for

if (guess_value < target_value)
	{
	makeRunLogYellow();
	log_screen.setf(ios::fixed);
	log_screen << "Warning: Cannot solve for volatility spread"
			 << " for index opton Id=" << asset_id
			 << ". Volatility spread set to zero. "
			 << "Target value is " << target_value
			 << ". Value using zero spread is " << init_mkt_val_calc
			 << MSG_ERROR;
	log_screen.unsetf(ios::fixed);

	PVCFile.setf(ios::fixed);
	PVCFile << PVCounter
			<< "<-- Warning: Cannot solve for volatility spread"
			<< " for index opton Id=" << asset_id
			<< ". Volatility spread set to zero. "
			<< "Target value is " << target_value
			<< ". Value using zero spread is " << init_mkt_val_calc
			<< endl;
	PVCFile.unsetf(ios::fixed);
	PVCounter--;

	return 0.0;
	} // endif

high_spread = guess_spread;
high_value = guess_value;
done_eio_1 = 0;

// Now solve for spread.
while (!done_eio_1)
	{
	// Initialize $Solve_For_spread_spreads and $Solve_For_spread_Present_values
	solve_for_spread_present_values[0] = low_value;
	solve_for_spread_spreads[0] = low_spread;
	solve_for_spread_present_values[1] = high_value;
	solve_for_spread_spreads[1] = high_spread;
	solve_for_spread_differences[0][0] = solve_for_spread_spreads[0];

	for (loop2 = 2; loop2 < 2 + maximum_iterations; loop2++)
		{
		if (loop2 > 2)
			{
			// Copy Diff[1][  * ] to Diff[0][  * ].
			for (temploop = 0; temploop < loop2 - 1; temploop++)
				{
				solve_for_spread_differences[0][temploop]
				= solve_for_spread_differences[1][temploop];
				}   // end_for
			} // endif

		solve_for_spread_differences[1][0] = solve_for_spread_spreads[loop2 - 1];

		for (temploop = 1; temploop < loop2; temploop++)
			{
			solve_for_spread_differences[1][temploop]
			= (solve_for_spread_differences[1][temploop - 1]
			   - solve_for_spread_differences[0][temploop - 1])
			  / (solve_for_spread_present_values[loop2 - 1]
				 - solve_for_spread_present_values[loop2 - temploop - 1]);
			}   // end_for

		if (loop2 > 2)
			spread_factor = solve_for_spread_differences[1][0];
		else
			spread_factor = solve_for_spread_spreads[0];

		// CALCULATE value_factor
        if (loop2 == 2)
			value_factor
			= (target_value - solve_for_spread_present_values[loop2 - 2]);
		else
			value_factor
			= value_factor * (target_value - solve_for_spread_present_values[loop2 - 2]);

		// Get new spread.
		guess_spread = spread_factor + value_factor * solve_for_spread_differences[1][loop2 - 1];

		// Start over, if we are not getting closer.
		if (guess_spread > high_spread || guess_spread < low_spread)
			loop2 = 2 + maximum_iterations;
		else
			{
			guess_value = mkt_val_calc(t,
								cal_yr,
								cal_mth,
								lookback_defn,
								lookback_mths,
								lookback_sampling_mths,
								index_units_owned(t),
								index_val(t),
								index_scen_mult,
								index_scen_addn,
								((maturity_period - t) / 12.0),
								div_yld_scen_mult,
								div_yld_addn,
								opt_strike_price,
								payout_index_max,
								opt_defn,
								adjustment_spot_spread_local,
								guess_spread,
								index_val_shift_defn,
								index_vol_shift_defn,
								int_rate_shift_defn);

			if (asset_detail_pv_flag(t))
				{
				PVCText << "Iterpolation Solve Loop: " << loop2 - 2
						<< " for " << asset_id
						<< " t=" << t
						<< " CalYr=" << cal_yr
						<< " CalMth=" << cal_mth;
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_pv_output();

				PVCText	<< "GsSprd," << write_string(guess_spread,PVCLen,PVCSigDig) << endl
						<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
						<< "LowSprd," << write_string(low_spread,PVCLen,PVCSigDig) << endl
						<< "LowVal,"	<< write_string(low_value,PVCLen,PVCSigDig) << endl
						<< "HighSprd," << write_string(high_spread,PVCLen,PVCSigDig) << endl
						<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig);
				asset_detail_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				{
				adjustment_volatility_spread_local = guess_spread;
				done_eio_1 = 1;
				loop2 = 2 + maximum_iterations;
				}
			else
				{ // Otherwise, reset high and low yields.
				if (guess_value < target_value)
					{
					low_value = guess_value;
					low_spread = guess_spread;
					}
				else
					{
					high_value = guess_value;
					high_spread = guess_spread;
					} // endif
				} // endif

			if (!done_eio_1)
				{
				solve_for_spread_present_values[loop2] = guess_value;
				solve_for_spread_spreads[loop2] = guess_spread;
				} // endif
			} // endif
		} // end_for

	// If not done, reduce interval by factor of 4 (2 bisections) and start over.
	if (!done_eio_1)
		{
		for (loop3 = 0; loop3 < 2; loop3++)
			{
			guess_spread = (low_spread + high_spread) / 2.0;
			guess_value = mkt_val_calc(t,
								cal_yr,
								cal_mth,
								lookback_defn,
								lookback_mths,
								lookback_sampling_mths,
								index_units_owned(t),
								index_val(t),
								index_scen_mult,
								index_scen_addn,
								((maturity_period - t) / 12.0),
								div_yld_scen_mult,
								div_yld_addn,
								opt_strike_price,
								payout_index_max,
								opt_defn,
								adjustment_spot_spread_local,
								guess_spread,
								index_val_shift_defn,
								index_vol_shift_defn,
								int_rate_shift_defn);

			if (asset_detail_pv_flag(t))
				{
				PVCText << "Bisection Solve Loop: " << loop3
						<< " for " << asset_id
						<< " t=" << t
						<< " CalYr=" << cal_yr
						<< " CalMth=" << cal_mth;
				if (asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					asset_detail_pv_output();

				PVCText	<< "GsSprd," << write_string(guess_spread,PVCLen,PVCSigDig) << endl
						<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
						<< "LowSprd," << write_string(low_spread,PVCLen,PVCSigDig) << endl
						<< "LowVal,"	<< write_string(low_value,PVCLen,PVCSigDig) << endl
						<< "HighSprd," << write_string(high_spread,PVCLen,PVCSigDig) << endl
						<< "HighVal," << write_string(high_value,PVCLen,PVCSigDig);
				asset_detail_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
				{
				adjustment_volatility_spread_local = guess_spread;
				done_eio_1 = 1;
				loop3 = 999;
				}
			else
				{ // Otherwise, reset high and low yields
				if (guess_value < target_value)
					{
					low_value = guess_value;
					low_spread = guess_spread;
					}
				else
					{
					high_value = guess_value;
					high_spread = guess_spread;
					} // endif
				} // endif
			} // end_for ($loop3=0; $loop3<2; $loop3++)
		} // endif !done_eio_1
	} // end_while !done_eio_1

if (asset_detail_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Volatility Spread Adjustment ("
			<< write_string(adjustment_volatility_spread_local,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	asset_detail_pv_output();
	PVCounter--;
	}

return adjustment_volatility_spread_local;

}


//@@ END

//@@ START - yld_denom
// Yield Denominator                                                                                             
// Column:YLD_DENOM
//========================================================
double EIO_ASSET_UDF::eio_asset_yld_denom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(155,"yld_denom",t);
}



//^^^

#line 1 "yld_denom.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0)
	return bk_val(t);

if (t < maturity_period)
	return bk_val(t - 1);

return bk_val(t - 1);

}


//@@ END

//@@ START - yld_numer
// Yield Numerator                                                                                             
// Column:YLD_NUMER
//========================================================
double EIO_ASSET_UDF::eio_asset_yld_numer(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(156,"yld_numer",t);
}



//^^^

#line 1 "yld_numer.EIO_ASSET.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!existing_asset_indicator && t == commencement_period)
	return NO_AVG;

if (existing_asset_indicator && t == 0
	&& !is_asset_initialize)
	return initial_values->yld_numer; 

if (existing_asset_indicator && t == 0)
	return yld_numer(t + 1);

return accr_inc(t);

}


//@@ END

//@@ START - asset_detail_rpt_flag
// Detail Report Flag                                                                                             
// Calculated Variable:ASSET_DETAIL_RPT_FLAG
//========================================================
int EIO_ASSET_UDF::eio_asset_asset_detail_rpt_flag() {
//^^^


#line 1 "asset_detail_rpt_flag.EIO_ASSET.for"
if (asset_detail_rpt_cusip_id == "ALL"
	|| inlist(asset_id, asset_detail_rpt_cusip_id)) 
	return YES;

return NO;

}


//@@ END

//@@ START - asset_fund_index
// Asset Fund Index                                                                                             
// Calculated Variable:ASSET_FUND_INDEX
//========================================================
int EIO_ASSET_UDF::eio_asset_asset_fund_index() {
//^^^


#line 1 "asset_fund_index.EIO_ASSET.for"
if (port_defn == INVESTMENT)
	return INVESTMENT_FUND_INDEX;

if (port_defn == HEDGING)
	return HEDGING_FUND_INDEX;

// else set to "Investment" default value
makeRunLogYellow();
log_screen << "Warning: Invalid portfolio definition (" << port_defn
		   <<") for index option ID = " << asset_id
		   << "." << MSG_ERROR;
log_screen << " ... Portfolio definition has been reset to Investment. " << MSG_ERROR;

port_defn = INVESTMENT;

return INVESTMENT_FUND_INDEX;

}


//@@ END

//@@ START - bk_val_bef_expiry
// Book Value Before Expiry                                                                                             
// Calculated Variable:BK_VAL_BEF_EXPIRY
//========================================================
double EIO_ASSET_UDF::eio_asset_bk_val_bef_expiry() {
//^^^


#line 1 "bk_val_bef_expiry.EIO_ASSET.for"
if (bk_val_defn == COST_BASIS)
	return cost_basis_bef_expiry;

if (bk_val_defn == MARKET_VALUE)
	return mkt_val_bef_expiry;

if (bk_val_defn == LOWER_OF_COST_AND_MARKET)
	return min(cost_basis_bef_expiry, mkt_val_bef_expiry);

if (bk_val_defn == HISTORIC_LOWEST_COST)
	return min(cost_basis_bef_expiry, bk_val(maturity_period - 1));

if (bk_val_defn == HISTORIC_LOWEST_COST_AND_MARKET
	&& cal_mth(maturity_period) < 12)
	return bk_val(maturity_period - 1);

if (bk_val_defn == HISTORIC_LOWEST_COST_AND_MARKET
	&& cal_mth(maturity_period) == 12)
	{
	double val; // ?? compile errors with double min's
	val = min(cost_basis_bef_expiry, mkt_val_bef_expiry);
	return min(bk_val(maturity_period - 1), val);
	}

return NO_AVG;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int EIO_ASSET_UDF::eio_asset_commencement_period() {
//^^^


#line 1 "commencement_period.EIO_ASSET.for"
if (investing_flag)
	return investment_period;

if (existing_asset_indicator)
	return 0;

return 0;

}


//@@ END

//@@ START - cost_basis_bef_expiry
// Cost Basis Before Expiry                                                                                             
// Calculated Variable:COST_BASIS_BEF_EXPIRY
//========================================================
double EIO_ASSET_UDF::eio_asset_cost_basis_bef_expiry() {
//^^^


#line 1 "cost_basis_bef_expiry.EIO_ASSET.for"
if (cost_basis_defn == ACTUAL_COST)
	return cost_basis(maturity_period - 1);

if (cost_basis_defn == MARKET_VALUE
	|| cost_basis_defn == STRAIGHT_LINE_AMORTIZATION)
	return mkt_val_bef_expiry;

return NO_AVG;

}


//@@ END

//@@ START - data_grp_id
// Data Group Identification                                                                                             
// Calculated Variable:DATA_GRP_ID
//========================================================
xstring EIO_ASSET_UDF::eio_asset_data_grp_id() {
//^^^


#line 1 "data_grp_id.EIO_ASSET.for"
return get_base_group_name(group, false);//WTW - Gen2 - Move Extern definitions to rates header

}


//@@ END

//@@ START - existing_asset_indicator
// Existing Asset Indicator                                                                                             
// Calculated Variable:EXISTING_ASSET_INDICATOR
//========================================================
int EIO_ASSET_UDF::eio_asset_existing_asset_indicator() {
//^^^


#line 1 "existing_asset_indicator.EIO_ASSET.for"
if (purch_asset_mp_num == -1)
	{
	// Existing asset was purchased during a previous scenario time step
	if (time_step_flag && !valn_flag && valn_period != 0)
		return PRIOR_PURCH;	
	
	// Existing at original projection date
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
int EIO_ASSET_UDF::eio_asset_gaap_inc_defn() {
//^^^


#line 1 "gaap_inc_defn.EIO_ASSET.for"
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
int EIO_ASSET_UDF::eio_asset_gaap_val_defn() {
//^^^


#line 1 "gaap_val_defn.EIO_ASSET.for"
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

//@@ START - init_mkt_val_calc
// Initial Market Value Calculated                                                                                             
// Calculated Variable:INIT_MKT_VAL_CALC
//========================================================
double EIO_ASSET_UDF::eio_asset_init_mkt_val_calc() {
//^^^


#line 1 "init_mkt_val_calc.EIO_ASSET.for"
// This value is used at the model start date to solve for an adjustment spread (spot or volatility).
if (existing_asset_indicator)
	return mkt_val_calc(0,
				xint(cal_yr_relative(0)),
				xint(cal_mth(0)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned(0),
				index_val(0),
				index_scen_mult,
				index_scen_addn,
				(maturity_period / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				0.0 /* spot_sprd_adj */,
				0.0 /* volatility_sprd_adj */,
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

return 0.0;

}


//@@ END

//@@ START - lookback_mths
// Lookback Months                                                                                             
// Calculated Variable:LOOKBACK_MTHS
//========================================================
int EIO_ASSET_UDF::eio_asset_lookback_mths() {
//^^^


#line 1 "lookback_mths.EIO_ASSET.for"
int preliminary_lookback_months
= min(lookback_yrs,
	  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

return preliminary_lookback_months
	   - (preliminary_lookback_months % lookback_sampling_mths);

}


//@@ END

//@@ START - lookback_sampling_mths
// Lookback Sampling Months                                                                                             
// Calculated Variable:LOOKBACK_SAMPLING_MTHS
//========================================================
int EIO_ASSET_UDF::eio_asset_lookback_sampling_mths() {
//^^^


#line 1 "lookback_sampling_mths.EIO_ASSET.for"
if (lookback_sampling_interval == ANNUAL)
	return 12;

if (lookback_sampling_interval == SEMIANNUAL)
	return 6;

if (lookback_sampling_interval == QUARTERLY)
	return 3;

if (lookback_sampling_interval == MONTHLY)
	return 1;

return 1;

}


//@@ END

//@@ START - maturity_period
// Maturity Period                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int EIO_ASSET_UDF::eio_asset_maturity_period() {
//^^^


#line 1 "maturity_period.EIO_ASSET.for"
if (existing_asset_indicator)
	{
	int maturity_yr = get_yr_from_date(maturity_date);
	int maturity_mth = get_mth_from_date(maturity_date);
	
	return (maturity_yr - proj_start_yr) * 12
			+ maturity_mth
			- proj_start_mth + 1;
	}

double ytm = asset->purch_asset_yrs_to_maturity;

if (((double) ((int) (12 * ytm)) == (12 * ytm)))
	return commencement_period
	       + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

return commencement_period
	   + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1;

}


//@@ END

//@@ START - mkt_val_at_issue
// Market Value at Issue                                                                                             
// Calculated Variable:MKT_VAL_AT_ISSUE
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_val_at_issue() {
//^^^


#line 1 "mkt_val_at_issue.EIO_ASSET.for"
if (existing_asset_indicator)
	return 0.0;

if (asset_detail_pv_flag(commencement_period))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value At Issue"
			<< " for " << asset_id
			<< " t=" << commencement_period
			<< " CalYr=" << xint(this->cal_yr(commencement_period))
			<< " CalMth=" << xint(this->cal_mth(commencement_period));
	asset_detail_pv_output();
	}

double calculated_market_value
= mkt_val_calc(commencement_period,
				xint(cal_yr_relative(commencement_period)),
				xint(cal_mth(commencement_period)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				1.0 /* index_units_owned(commencement_period) */,
				1.0 /* index_val(commencement_period) */,
				index_scen_mult,
				index_scen_addn,
				((maturity_period - commencement_period) / 12.0),
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				0.0 /* spot_sprd_adj */,
				0.0 /* volatility_sprd_adj */,
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);   

if (asset_detail_pv_flag(commencement_period))
	{
	PVCText << PVCounter
			<< "<--End Market Value At Issue ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< ") for " << asset_id
			<< " t=" << commencement_period
			<< " CalYr=" << xint(this->cal_yr(commencement_period))
			<< " CalMth=" << xint(this->cal_mth(commencement_period));
	asset_detail_pv_output();
	PVCounter--;
	}

return calculated_market_value;

}


//@@ END

//@@ START - mkt_val_bef_expiry
// Market Value Before Expiry                                                                                             
// Calculated Variable:MKT_VAL_BEF_EXPIRY
//========================================================
double EIO_ASSET_UDF::eio_asset_mkt_val_bef_expiry() {
//^^^


#line 1 "mkt_val_bef_expiry.EIO_ASSET.for"
return mkt_val_calc(maturity_period,
				xint(cal_yr_relative(maturity_period)),
				xint(cal_mth(maturity_period)),
				lookback_defn,
				lookback_mths,
				lookback_sampling_mths,
				index_units_owned(maturity_period - 1),
				index_val_at_expiry_anniv(maturity_period),
				index_scen_mult,
				index_scen_addn,
				0.0 /* years_to_expiry */,
				div_yld_scen_mult,
				div_yld_addn,
				opt_strike_price,
				payout_index_max,
				opt_defn,
				spot_sprd_adj(maturity_period),
				volatility_sprd_adj(maturity_period),
				NO_SHIFT, /* index_val_shift_defn */
				NO_SHIFT, /* index_vol_shift_defn */
				NO_SHIFT /* int_rate_shift_defn */);

}


//@@ END

//@@ START - neg_asset_flag
// Negative Asset Flag                                                                                             
// Calculated Variable:NEG_ASSET_FLAG
//========================================================
double EIO_ASSET_UDF::eio_asset_neg_asset_flag() {
//^^^


#line 1 "neg_asset_flag.EIO_ASSET.for"
if(existing_asset_indicator)
	{
	if (init_mkt_val >= 0.0)
		return 1;
	else
		return -1;
	}

if (purch_amt >= 0.0)
	return 1;

return -1;

}


//@@ END

//@@ START - notional_amt_at_issue
// Notional Amount at Issue                                                                                             
// Calculated Variable:NOTIONAL_AMT_AT_ISSUE
//========================================================
double EIO_ASSET_UDF::eio_asset_notional_amt_at_issue() {
//^^^


#line 1 "notional_amt_at_issue.EIO_ASSET.for"
if (existing_asset_indicator)
	return NO_AVG;

return purch_amt * neg_asset_flag;

}


//@@ END

//@@ START - pct_to_use
// Percent to Use                                                                                             
// Calculated Variable:PCT_TO_USE
//========================================================
double EIO_ASSET_UDF::eio_asset_pct_to_use() {
//^^^


#line 1 "pct_to_use.EIO_ASSET.for"
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
int EIO_ASSET_UDF::eio_asset_planned_sale_period() {
//^^^


#line 1 "planned_sale_period.EIO_ASSET.for"
if (existing_asset_indicator)
	return min(get_yr_from_date(planned_sale_date) - proj_start_yr,
			   MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
		   + get_mth_from_date(planned_sale_date) - proj_start_mth + 1;

return MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS * 12;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring EIO_ASSET_UDF::eio_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.EIO_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int EIO_ASSET_UDF::eio_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.EIO_ASSET.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int EIO_ASSET_UDF::eio_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.EIO_ASSET.for"
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
int EIO_ASSET_UDF::eio_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.EIO_ASSET.for"
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
int EIO_ASSET_UDF::eio_asset_sale_class_id() {
//^^^


#line 1 "sale_class_id.EIO_ASSET.for"
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

//@@ START - seg_num
// Segment Number                                                                                             
// Calculated Variable:SEG_NUM
//========================================================
int EIO_ASSET_UDF::eio_asset_seg_num() {
//^^^


#line 1 "seg_num.EIO_ASSET.for"
if (isMainModel)
	return 0;

return seg->getElementNumber();

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int EIO_ASSET_UDF::eio_asset_start_period() {
//^^^


#line 1 "start_period.EIO_ASSET.for"
return max(0, commencement_period);

}


//@@ END


#line 1 "asset_detail_pv_output.EIO_ASSET.for"                                                                                   
void EIO_ASSET::asset_detail_pv_output()
{
if (asset_detail_rpt_pv_defn == YES)
	PVCFile << endl << PVCText.str() << endl;
else // "Summary to Run Log"
	log_screen << "PVSum: " << PVCText.str() << MSG_USER;

PVCText.str("");

return;
}



#line 1 "calc_num_records_to_run.EIO_ASSET.for"                                                                                   
int EIO_ASSET::calc_num_records_to_run(void)
{
xstring data_file_name = replaceWildcards(data_location());
string table_name = readCsvFile(data_file_name.getStdStr());
xstring sql = (xstring)"SELECT * FROM " + table_name;
executeQuery(sql.getStdStr(), eio_mp_input_cols, eio_mp_input);
closeDatabase();

if (!eio_mp_input_cols.size())
	return 0;

int num_records_to_run = 0;
for (int row = 0; row < eio_mp_input.size(); row++)
	{
	if (eio_mp_input[row][3] == "Yes")
		num_records_to_run++;
	}

return num_records_to_run;
}



#line 1 "index_val_calc.EIO_ASSET.for"                                                                                   
double EIO_ASSET::index_val_calc(int t)
{
double index_val = 1.0;
double rate = 1.0;
	
if (time_step_flag && valn_period != 0)
	{
	for (int i = 1; i <= valn_period; i++)
		{
		rate = pow(1.0 + rates->get_index_rate(i - valn_period,
						asset_index,
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL)
						* index_scen_mult + index_scen_addn,
					  (1.0 / 12.0));
		index_val *= rate;	
		}
	}
	
if (t == 0)
	return index_val;	

if (t > 0)
	{
	for (int i = 1; i <= t; i++)
		{
		rate = pow(1.0 + rates->get_index_rate(i,
						asset_index,
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL)
						* index_scen_mult + index_scen_addn,
					  (1.0 / 12.0));
		index_val *= rate;			
		}
	}

// else if t < 0, must base calculation on prior value
for (int i = -1; i >= t; i--)
	{
	rate = pow(1.0 + rates->get_index_rate(i + 1,
					asset_index,
					GET_GROWTH_RATE,
					EFFECTIVE_ANNUAL)
					* index_scen_mult + index_scen_addn,
				  (1.0 / 12.0));
	index_val /= rate;
	}
		
return index_val;		
}



#line 1 "mkt_val_calc.EIO_ASSET.for"                                                                                   
double EIO_ASSET::mkt_val_calc(int t, int cal_yr, int cal_mth, int lookback_defn, int lookback_mths, int lookback_sampling_mths, double index_units_owned, double index_val, double index_scen_mult, double index_scen_addn, double term_to_expiry, double div_yld_scen_mult, double div_yld_addn, double opt_strike_price, double payout_index_max, StrEnum::EnumValue opt_defn, double extra_spot_spread, double extra_vol_spread, int index_val_shift_defn, int index_vol_shift_defn, int int_rate_shift_defn)
{
// Local Variables
double calculated_market_value = 0;
int sampling_frequency = 0;
double init_div_yld = 0;
double index_val_shift = 0.0;
double index_vol_opt_strike_price  = 0;
double index_vol_payout_index_max  = 0;
double index_vol_atm = 0;
double index_vol_otm = 0;
double risk_free_rate = 0;
double market_value_of_base_option = 0;
double market_value_of_maximum_payout_strike_option = 0;
double volatility_skew = 0;

if (opt_defn == FUTURES)
	{
	init_div_yld
	= rates->get_index_rate(t, 
							asset_index,
							GET_DIVIDEND_YIELD,
							EFFECTIVE_ANNUAL)
		* div_yld_scen_mult + div_yld_addn;

	risk_free_rate
	= rates->get_int_rate(t,
						  category_id,
						  GET_SPOT_RATE,
						  term_to_expiry,
						  0.0,
						  NOMINAL_SEMIANNUAL,
						  int_rate_shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		+ extra_spot_spread;

	if (index_val_shift_defn == PRICE_SHIFT)
		index_val_shift = rates->index_val_shifts[asset_index];

	calculated_market_value
	= index_units_owned
	  * index_val
	  * (1.0 + index_val_shift)
	  * exp((risk_free_rate - init_div_yld)	* term_to_expiry);
	}
else
	{
	int call_or_put_option_code
	= (opt_defn == CALL ? CALL_CODE : PUT_CODE);

	// Apply the shifts
	if (index_val_shift_defn == PRICE_SHIFT)
		index_val_shift = rates->index_val_shifts[asset_index];

	index_val *= (1.0 + index_val_shift);

	// This formula set samples beginnings and ends of sample months.
	// Reduce lookback months by one to sample ends of sample months only.

	if (term_to_expiry > 0.0)
		{
		lookback_mths = lookback_mths - lookback_sampling_mths;

		sampling_frequency = 12 / lookback_sampling_mths;

		init_div_yld
		= rates->get_index_rate(t, 
					asset_index,
					GET_DIVIDEND_YIELD,
					EFFECTIVE_ANNUAL)
		  * div_yld_scen_mult + div_yld_addn;

		index_vol_atm
		= rates->get_index_vol(t, 
					asset_index,
					1.0, /*moneyness */
					term_to_expiry,
					EFFECTIVE_ANNUAL,
					index_vol_shift_defn) 
		  + extra_vol_spread;
	
		index_vol_otm
		= rates->get_index_vol(t, 
					asset_index,
					1.05,/*moneyness */
					term_to_expiry,
					EFFECTIVE_ANNUAL,
					index_vol_shift_defn) 
		  + extra_vol_spread;
	
		volatility_skew = (index_vol_atm - index_vol_otm) / (1.05 - 1.00)/ 100.;
	
		index_vol_opt_strike_price = max(0.05, index_vol_atm - volatility_skew * (opt_strike_price - index_val) / index_val  * 100.0);
	
		index_vol_payout_index_max = max(0.05, index_vol_atm - volatility_skew * (payout_index_max - index_val) / index_val  * 100.0);
	
		index_vol_payout_index_max = min( 9.9, index_vol_payout_index_max);
	
		if (index_vol_opt_strike_price < model_point_amount_threshold)
			{
			if (existing_asset_indicator)
				throw FatalError( " The volatility of the existing index option with identifier '" + asset_id
								  + "' is zero."
								  + "\n ... Please update the volatilty assumptions for this index.");
			else
				throw FatalError( " The volatility of the investment index option with identifier '" + asset_id
								  + "' is zero."
								  + "\n ... Please update the volatilty assumptions for this index.");
			}

		risk_free_rate
		= rates->get_int_rate(t,
					category_id,
					GET_SPOT_RATE,
					term_to_expiry,
					0.0,
					NOMINAL_SEMIANNUAL,
					int_rate_shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		  + extra_spot_spread;
		} 
/*if (term_to_expiry > 0.0) log_screen<<"t= "<<t
<<" index_units_owned= "<<index_units_owned
<<" bs_opt_val= "<<bs_opt_val(opt_strike_price,
					term_to_expiry,
					index_val,
					index_vol_opt_strike_price,
					risk_free_rate,
					init_div_yld,
					call_or_put_option_code,
					CONTINUOUS_PAYOUT_CODE)
<<" index_val-payout_index_max= "<<index_val - payout_index_max
<<MSG_USER;*/
	if (term_to_expiry > 0.0 && lookback_defn == NONE)
		market_value_of_base_option
		= index_units_owned
		  * bs_opt_val(opt_strike_price,
					term_to_expiry,
					index_val,
					index_vol_opt_strike_price,
					risk_free_rate,
					init_div_yld,
					call_or_put_option_code,
					CONTINUOUS_PAYOUT_CODE);

	else if (term_to_expiry > 0.0 && lookback_defn == ASIAN)
		market_value_of_base_option
		= index_units_owned
		  * bs_opt_val_asian(call_or_put_option_code,
					index_val,
					lookback_index_val(t),
					opt_strike_price,
					lookback_mths / 12.0,
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_opt_strike_price,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (term_to_expiry > 0.0 && lookback_defn == HIGHEST_GAIN)
		market_value_of_base_option
		= index_units_owned
		  * bs_opt_val_highest_gain(call_or_put_option_code,
					index_val,
					lookback_index_val(t),
					lookback_index_val(t) /* Minimum for put */,
					opt_strike_price,
					lookback_mths / 12.0,
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_opt_strike_price,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (opt_defn == CALL
			 && (lookback_defn == ASIAN || lookback_defn == HIGHEST_GAIN))
		market_value_of_base_option
		= index_units_owned
		  * max(lookback_index_val(t) - opt_strike_price, 0.0);

	else if (opt_defn == CALL && lookback_defn == NONE)
		market_value_of_base_option
		= index_units_owned * max(index_val - opt_strike_price, 0.0);

	else if (opt_defn == PUT
			 && (lookback_defn == ASIAN || lookback_defn == HIGHEST_GAIN))
		market_value_of_base_option
		= index_units_owned * max(opt_strike_price - lookback_index_val(t), 0.0);

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
					lookback_index_val(t),
					payout_index_max /* Strike index */,
					lookback_mths / 12.0,
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_payout_index_max,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (term_to_expiry > 0.0 && lookback_defn == HIGHEST_GAIN)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * bs_opt_val_highest_gain(call_or_put_option_code, index_val,
					lookback_index_val(t) /* Maximum for call */,
					lookback_index_val(t) /* Minimum for put */,
					payout_index_max /* Strike index */,
					lookback_mths / 12.0, 
					sampling_frequency,
					term_to_expiry,
					risk_free_rate,
					init_div_yld,
					index_vol_payout_index_max,
					NOMINAL_SEMIANNUAL,
					EFFECTIVE_ANNUAL);

	else if (opt_defn == CALL
			 && (lookback_defn == ASIAN || lookback_defn == HIGHEST_GAIN))
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(lookback_index_val(t) - payout_index_max, 0.0);

	else if (opt_defn == CALL && lookback_defn == NONE)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(index_val - payout_index_max, 0.0);

	else if (opt_defn == PUT
			 && (lookback_defn == ASIAN || lookback_defn == HIGHEST_GAIN))
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(payout_index_max - lookback_index_val(t), 0.0);

	else if (opt_defn == PUT && lookback_defn == NONE)
		market_value_of_maximum_payout_strike_option
		= index_units_owned
		  * max(payout_index_max - index_val, 0.0);

	calculated_market_value
	= market_value_of_base_option - market_value_of_maximum_payout_strike_option;
	}

if (asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Market Value Calculation"
			<< " for " << asset_id
			<< " t=" << t
			<< " CalYr=" << xint(this->cal_yr(t))
			<< " CalMth=" << xint(this->cal_mth(t));
	asset_detail_pv_output();

	if (asset_detail_rpt_pv_defn == YES)
		{
		if (opt_defn == FUTURES)
			{
			PVCFile << "OptDefn," << get_string_of_enum_val(opt_defn) << endl
					<< "UnitsOwned," << index_units_owned << endl
					<< "YrsToMat," << term_to_expiry << endl
					<< "SpotSpread," << extra_spot_spread << endl
					<< "Index," << index_val << endl
					<< "StrikeIndex," << opt_strike_price << endl
					<< "RiskFreeRate," << risk_free_rate << endl
					<< "DivYld," << init_div_yld << endl
					<< "DivMult," << div_yld_scen_mult << endl
					<< "DivSprd," << div_yld_addn << endl
					<< "IndexValShift," << index_val_shift << endl
					<< "MVCalc," << calculated_market_value << endl;
			}
		else
			{
			xstring lookback_option_string;
			if (lookback_defn == NONE)
				lookback_option_string = "None";
			else if (lookback_defn == ASIAN)
				lookback_option_string = "Asian";
			else // lookback_defn == HIGHEST_GAIN
				lookback_option_string = "Highest Gain";

			PVCFile << "Type," << lookback_option_string << endl
					<< "OptDefn," << get_string_of_enum_val(opt_defn) << endl
					<< "UnitsOwned," << index_units_owned << endl
					<< "YrsToMat," << term_to_expiry << endl
					<< "SpotSpread," << extra_spot_spread << endl
					<< "VolSpread," << extra_vol_spread << endl
					<< "Index," << index_val << endl
					<< "StrikeIndex," << opt_strike_price << endl
					<< "MaxIndex," << payout_index_max << endl
					<< "IndexVol," << index_vol_opt_strike_price << endl
					<< "RiskFreeRate," << risk_free_rate << endl
					<< "ContRiskFreeRate," << log(1.0 + risk_free_rate
											   / NOMINAL_SEMIANNUAL)
									 * NOMINAL_SEMIANNUAL << endl
					<< "DivYld," << init_div_yld << endl
					<< "ContDivYld," << log(1.0 + init_div_yld
											   / EFFECTIVE_ANNUAL)
									 * EFFECTIVE_ANNUAL << endl
					<< "IndexGrwthMult," << index_scen_mult << endl
					<< "IndexGrwthSprd," << index_scen_addn << endl
					<< "DivMult," << div_yld_scen_mult << endl
					<< "DivSprd," << div_yld_addn << endl
					<< "LookbackMths," << lookback_mths << endl
					<< "SamplingFreq," << sampling_frequency << endl
					<< "LookbackIndexValue," << lookback_index_val(t) << endl
					<< "MVBaseOption," << market_value_of_base_option << endl
					<< "MVMaxPayoutStrikeOption," << market_value_of_maximum_payout_strike_option << endl;
			}
		}

	PVCText << PVCounter
			<< "<-- End Market Value Calculation ("
			<< write_string(calculated_market_value,PVCLen,PVCSigDig)
			<< " for " << asset_id
			<< " t=" << t
			<< " CalYr=" << xint(this->cal_yr(t))
			<< " CalMth=" << xint(this->cal_mth(t));
	asset_detail_pv_output();
	PVCounter--;
	}

return calculated_market_value;
}



#line 1 "setup_existing_asset.EIO_ASSET.for"                                                                                   
void EIO_ASSET::setup_existing_asset(void)
{
// Set value for model point variables
if (num_of_proj_task_loops == 0 
	|| is_first_proj_task_loop
	|| restore_variables_ind == 1)
	{
	asset_id = asset_id_mp;
	seg_id = seg_id_mp;
	hdg_grp_code = hdg_grp_code_mp;
	asset_index = asset_index_mp;
	category_id = category_id_mp;
	port_defn = port_defn_mp;
	sale_class = sale_class_mp;
	maturity_date = maturity_date_mp;
	planned_sale_date = planned_sale_date_mp;
	init_cost_basis = init_cost_basis_mp;
	init_bk_val = init_bk_val_mp;
	init_mkt_val = init_mkt_val_mp;
	init_index_units_owned = init_index_units_owned_mp;
	init_index_val = init_index_val_mp;
	opt_strike_price = opt_strike_price_mp;
	index_val_at_issue = index_val_at_issue_mp;
	payout_index_max = payout_index_max_mp;
	opt_defn = opt_defn_mp;
	index_scen_mult = index_scen_mult_mp;
	index_scen_addn = index_scen_addn_mp;
	div_yld_scen_mult = div_yld_scen_mult_mp;
	div_yld_addn = div_yld_addn_mp;
	lookback_defn = lookback_defn_mp;
	lookback_sampling_interval = lookback_sampling_interval_mp;
	lookback_yrs = lookback_yrs_mp;
	avr_contribn_pct = avr_contribn_pct_mp;
	avr_max_pct = avr_max_pct_mp;
	avr_obj_pct = avr_obj_pct_mp;
	rbc_c1_pct = rbc_c1_pct_mp;

	if (port_defn != INVESTMENT && port_defn != HEDGING)
		{
		log_screen << " Warning: Invalid portfolio definition " << port_defn
				 << " in index option id = " << asset_id
				 << " Portfolio definition has been set to Investment"
				 << MSG_ERROR;

		port_defn = INVESTMENT;
		}
	}

return;
}



#line 1 "setup_purch_hedge_asset.EIO_ASSET.for"                                                                                   
void EIO_ASSET::setup_purch_hedge_asset(int t, int save_assets, int panum, int new_mp_num, int inv_purchase_sub_port, const xstring &hedge_group_code, double purch_asset_amt, int &asset_mp_sequence_num, double long_strike, double short_strike)
{
purch_asset_id = company->sm_inv_strategy[seg_num]->purch_assets_id[panum];
company->sm_inv_strategy[seg_num]->purch_asset_id = purch_asset_id;

if (save_assets == YES)
	{
	sequence_id = asset_mp_sequence_num++;

	xstring asset_class_tag
	= asset->set_mp_grp(t, new_mp_num, seg_id,
	                    company->sm_inv_strategy[seg_num]->purch_assets_mp_grp_tag[panum],
	                    company->sm_inv_strategy[seg_num]->purch_assets_id[panum],
	                    sequence_id, company->sm_inv_strategy[seg_num]->inv_purch_timing);

	setGroup(asset_class_tag);
	}
else
	sequence_id = 0;

purch_asset_sub_port = inv_purchase_sub_port;
purch_amt = purch_asset_amt;

category_id = company->sm_inv_strategy[seg_num]->purch_eio_category_id;

// read the grid for asset category data
ms_rereadGrid();

// Setup port_defn
port_defn = company->sm_inv_strategy[seg_num]->purch_eio_port_defn;

if (port_defn != INVESTMENT
	&& port_defn != HEDGING)
	{
	log_screen << " Warning: Invalid asset portfolio definition " << port_defn
			 << " in index option id = " << asset_id
			 << " Asset portfolio definition has been set to Investment"
			 << MSG_ERROR;

	port_defn = INVESTMENT;
	}

if (investing_bom_flag)
	purchased_bom_flag = true;
else
	purchased_bom_flag = false;

// Setup asset_id
asset_id = company->sm_inv_strategy[seg_num]->purch_asset_id;

// Setup maturity_date
double ytm = company->sm_inv_strategy[seg_num]->purch_eio_yrs_to_maturity;
int mat_period;

if (((double) ((int) (12 * ytm)) == (12 * ytm)))
	mat_period
	= (commencement_period
	   + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12);
else
	mat_period
	= (commencement_period
		+ min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1);

maturity_date = add_mths_to_date(proj_date_adj, mat_period); 

hdg_grp_code = hedge_group_code;
sale_class = company->sm_inv_strategy[seg_num]->purch_eio_sale_class;
asset_index = company->sm_inv_strategy[seg_num]->purch_eio_asset_index;
opt_defn = company->sm_inv_strategy[seg_num]->purch_eio_opt_defn;
div_yld_scen_mult = company->sm_inv_strategy[seg_num]->purch_eio_div_yld_scen_mult;
div_yld_addn = company->sm_inv_strategy[seg_num]->purch_eio_div_yld_addn;
index_scen_mult = company->sm_inv_strategy[seg_num]->purch_eio_index_scen_mult;
index_scen_addn = company->sm_inv_strategy[seg_num]->purch_eio_index_scen_addn;
lookback_defn = company->sm_inv_strategy[seg_num]->purch_eio_lookback_defn;
lookback_yrs = company->sm_inv_strategy[seg_num]->purch_eio_lookback_yrs;
lookback_sampling_interval = company->sm_inv_strategy[seg_num]->purch_eio_lookback_sampling_interval;

if (opt_defn == FUTURES)
	{
	payout_index_max = GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE + .999; 

	double term_to_expiry = (mat_period - commencement_period) / 12.0;

	double init_div_yld
	= rates->get_index_rate(t, 
							asset_index,
							GET_DIVIDEND_YIELD,
							EFFECTIVE_ANNUAL)
	  * div_yld_scen_mult + div_yld_addn;

	double risk_free_rate
	= rates->get_int_rate(t,
						  category_id,
						  GET_SPOT_RATE,
						  term_to_expiry,
						  0.0,
						  NOMINAL_SEMIANNUAL,
						  NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	opt_strike_price = index_val(commencement_period) * exp((risk_free_rate - init_div_yld) * term_to_expiry);
	}
else
	{
	if (long_strike < 0) // calculate long strike from index value and strike multiple
		{
		opt_strike_price = index_val(commencement_period) 
		                   * company->sm_inv_strategy[seg_num]->purch_eio_opt_strike_price;

		if (company->sm_inv_strategy[seg_num]->purch_eio_payout_index_max == 999.99)
			payout_index_max = GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE + .999;
		else
			payout_index_max = index_val(commencement_period)
							   * company->sm_inv_strategy[seg_num]->purch_eio_payout_index_max;
		}
	else // strikes provided through hedge group
		{
		payout_index_max = short_strike;
		opt_strike_price = long_strike;
		}
	}

avr_contribn_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_contribn_pct;
avr_max_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_max_pct;
avr_obj_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_obj_pct;
rbc_c1_pct = company->sm_inv_strategy[seg_num]->purch_eio_rbc_c1_pct;

// Setup index val at issue
index_val_at_issue = index_val(commencement_period);

return;
}



#line 1 "setup_purch_inv_asset.EIO_ASSET.for"                                                                                   
void EIO_ASSET::setup_purch_inv_asset(int t, int save_assets, int panum, int new_mp_num, int inv_purchase_sub_port, double purch_asset_amt, int &asset_mp_sequence_num)
{
if (existing_asset_indicator)
	return;

purch_asset_id = company->sm_inv_strategy[seg_num]->purch_assets_id[panum];
company->sm_inv_strategy[seg_num]->purch_asset_id = purch_asset_id;

if (save_assets == YES)
	{
	sequence_id = asset_mp_sequence_num++;

	xstring asset_class_tag
	= asset->set_mp_grp(t, new_mp_num, seg_id,
	                    company->sm_inv_strategy[seg_num]->purch_assets_mp_grp_tag[panum],
	                    purch_asset_id,
	                    sequence_id, company->sm_inv_strategy[seg_num]->inv_purch_timing);

	setGroup(asset_class_tag);
	}
else
	sequence_id = 0;

purch_asset_sub_port = company->sm_inv_strategy[seg_num]->purch_assets_asset_sub_port_num[panum];
purch_amt = purch_asset_amt;

category_id = company->sm_inv_strategy[seg_num]->purch_eio_category_id;

// read the grid for asset category data
ms_rereadGrid();

// Setup port_defn
port_defn = company->sm_inv_strategy[seg_num]->purch_eio_port_defn;

if (port_defn != INVESTMENT
	&& port_defn != HEDGING)
	{
	log_screen << " Warning: Invalid asset portfolio definition " << port_defn
			 << " in index option id = " << asset_id
			 << " Asset portfolio definition has been set to Investment"
			 << MSG_ERROR;

	port_defn = INVESTMENT;
	}

// Setup asset_id
asset_id = purch_asset_id;

// Setup maturity_date
double ytm = company->sm_inv_strategy[seg_num]->purch_eio_yrs_to_maturity;
int mat_period;

if (((double) ((int) (12 * ytm)) == (12 * ytm)))
	mat_period
	= (commencement_period
	   + min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12);
else
	mat_period
	= (commencement_period
		+ min(ytm, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12 + 1);

maturity_date = add_mths_to_date(proj_date_adj, mat_period); 

sale_class = company->sm_inv_strategy[seg_num]->purch_eio_sale_class;
asset_index = company->sm_inv_strategy[seg_num]->purch_eio_asset_index;
opt_defn = company->sm_inv_strategy[seg_num]->purch_eio_opt_defn;
div_yld_scen_mult = company->sm_inv_strategy[seg_num]->purch_eio_div_yld_scen_mult;
div_yld_addn = company->sm_inv_strategy[seg_num]->purch_eio_div_yld_addn;
index_scen_mult = company->sm_inv_strategy[seg_num]->purch_eio_index_scen_mult;
index_scen_addn = company->sm_inv_strategy[seg_num]->purch_eio_index_scen_addn;
lookback_defn = company->sm_inv_strategy[seg_num]->purch_eio_lookback_defn;
lookback_yrs = company->sm_inv_strategy[seg_num]->purch_eio_lookback_yrs;
lookback_sampling_interval = company->sm_inv_strategy[seg_num]->purch_eio_lookback_sampling_interval;

if (opt_defn == FUTURES)
	{
	payout_index_max = GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE + .999; 

	double term_to_expiry = (mat_period - commencement_period) / 12.0;

	double init_div_yld
	= rates->get_index_rate(t, 
							asset_index,
							GET_DIVIDEND_YIELD,
							EFFECTIVE_ANNUAL)
	  * div_yld_scen_mult + div_yld_addn;

	double risk_free_rate
	= rates->get_int_rate(t,
						  category_id,
						  GET_SPOT_RATE,
						  term_to_expiry,
						  0.0,
						  NOMINAL_SEMIANNUAL,
						  NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	opt_strike_price = index_val(commencement_period)
	                   * exp((risk_free_rate - init_div_yld) * term_to_expiry);
	}
else
	{
	if (company->sm_inv_strategy[seg_num]->purch_eio_payout_index_max == 999.99)
		payout_index_max = GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE + .999;
	else
		payout_index_max = index_val(commencement_period)
		                   * company->sm_inv_strategy[seg_num]->purch_eio_payout_index_max;

	opt_strike_price = index_val(commencement_period)
	                   * company->sm_inv_strategy[seg_num]->purch_eio_opt_strike_price;
	}

avr_contribn_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_contribn_pct;
avr_max_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_max_pct;
avr_obj_pct = company->sm_inv_strategy[seg_num]->purch_eio_avr_obj_pct;
rbc_c1_pct = company->sm_inv_strategy[seg_num]->purch_eio_rbc_c1_pct;

// Setup index val at issue
index_val_at_issue = index_val(commencement_period);

return;
}



#line 1 "validate_data.EIO_ASSET.for"                                                                                   
void EIO_ASSET::validate_data(void) 
{
if (existing_asset_indicator)
	{
	if (calculated_t_high < 1 && !isMainModel)
		{
		xstring index_val = seg_id + "_eio" + asset_id + data_grp_id + xstring(data_rec_num());

		if ((asset->init_cash_bal_map_iter
			 = asset->init_cash_bal_map.find(index_val))
			== asset->init_cash_bal_map.end())
			{
			if (data_validation_defn == YES)
				{
				makeRunLogYellow();
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "Warning: Existing eio " << asset_id
						   << " has matured before model start date."
						   << " Asset book value (" << setprecision(2) << init_bk_val
						   << ") has been added to the cash account."
						   << MSG_ERROR;
				}

			asset->init_cash_bal_map[index_val] = init_bk_val;
			}
	
		skipModelPoint();
		return;
		}

	double init_notional_amt
	= index_val_at_issue * init_index_units_owned;

	if (init_bk_val < rate_ratio_threshold 
		&& init_notional_amt < rate_ratio_threshold 
		&& data_validation_defn == YES)
		{
		makeRunLogYellow();
	
		log_screen << "Warning: Existing index option has no value."
				   << " Asset has been discarded."
				   << " Id = " << asset_id
				   << MSG_USER;                     
	
		skipModelPoint();
		return;
		}

	if (init_cost_basis < rate_ratio_threshold)
		throw FatalError("Cost Basis is zero for existing index option " + asset_id_mp
						 + ". Please correct your data.");
	}

return;
}



#line 1 "write_state_of_world_mp.EIO_ASSET.for"                                                                                   
void EIO_ASSET::write_state_of_world_mp(void)
{
static bool first_time = true;

xstring data_file_name = replaceWildcards(data_location());

xstring eio_state_of_world_file
= xstring(data_file_name(0, data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (first_time)
	{
	first_time = false;

	struct stat buffer;
	int stat_val = stat(eio_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(eio_state_of_world_file);
	}
 
if (!eio_state_of_world_mp_output.is_open())
	{
   	eio_state_of_world_mp_output.setf(ios::fixed);
	eio_state_of_world_mp_output.precision(12);
	eio_state_of_world_mp_output.open(eio_state_of_world_file);

	// Write header
	eio_state_of_world_mp_output				// Values from inforce mp
	<< "group" << ","							// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","						// col 1 = seg_id
	<< "asset_id_mp" << ","						// col 2 = asset_id
	<< "use_mp" << ","							// col 3 = use_mp
	<< "hdg_grp_code_mp" << ","					// col 4 = hdg_grp_code
	<< "asset_index_mp" << ","					// col 5 = asset_index
	<< "category_id_mp" << ","					// col 6 = category_id
	<< "port_defn_mp" << ","					// col 7 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","					// col 8 = get_string_of_enum_val(sale_class)
	<< "maturity_date_mp" << ","				// col 9 = maturity_date
	<< "planned_sale_date_mp" << ","			// col 10 = planned_sale_date
	<< "init_cost_basis_mp" << ","				// col 11 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","					// col 12 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","					// col 13 = mkt_val(last_proj_period)
	<< "init_index_units_owned_mp" << ","		// col 14 = index_units_owned(last_proj_period)
	<< "init_index_val_mp" << ","				// col 15 = index_val(last_proj_period)
	<< "opt_strike_price_mp" << ","				// col 16 = opt_strike_price
	<< "index_val_at_issue_mp" << ","			// col 17 = index_val_at_issue
	<< "payout_index_max_mp" << ","				// col 18 = payout_index_max
	<< "opt_defn_mp" << ","						// col 19 = get_string_of_enum_val(opt_defn)
	<< "index_scen_mult_mp" << ","				// col 20 = index_scen_mult
	<< "index_scen_addn_mp" << ","				// col 21 = index_scen_addn
	<< "div_yld_scen_mult_mp" << ","			// col 22 = div_yld_scen_mult
	<< "div_yld_addn_mp" << ","					// col 23 = div_yld_addn
	<< "lookback_defn_mp" << ","				// col 24 = get_string_of_enum_val(lookback_defn)
	<< "lookback_sampling_interval_mp" << ","	// col 25 = get_string_of_enum_val(lookback_sampling_interval)
	<< "lookback_yrs_mp" << ","					// col 26 = lookback_yrs
	<< "avr_contribn_pct_mp" << ","				// col 27 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","					// col 28 = avr_max_pct
	<< "avr_obj_pct_mp" << ","					// col 29 = avr_obj_pct
	<< "rbc_c1_pct_mp" << endl;					// col 30 = rbc_c1_pct
	}

static int counter = 1;
xstring group_mp = get_base_group_name(group, false);//WTW - Gen2 - Move Extern definitions to rates header
xstring port_defn = get_string_of_enum_val(this->port_defn);
xstring sale_class = get_string_of_enum_val(this->sale_class);
double cost_basis = this->cost_basis(last_proj_period);
double bk_val = this->bk_val(last_proj_period);
double mkt_val = this->mkt_val(last_proj_period);
double index_units_owned = this->index_units_owned(last_proj_period);
double index_val = this->index_val(last_proj_period);
xstring opt_defn = get_string_of_enum_val(this->opt_defn);
xstring lookback_defn = get_string_of_enum_val(this->lookback_defn);
xstring lookback_sampling_interval = get_string_of_enum_val(this->lookback_sampling_interval);

eio_state_of_world_mp_output
<< group_mp << ","
<< seg_id << ","
<< asset_id << ","
<< use_mp << ","
<< hdg_grp_code << ","
<< asset_index << ","
<< category_id << ","
<< port_defn << ","
<< sale_class << ","
<< maturity_date << ","
<< planned_sale_date << ","
<< cost_basis << ","
<< bk_val << ","
<< mkt_val << ","
<< index_units_owned << ","
<< index_val << ","
<< opt_strike_price << ","
<< index_val_at_issue << ","
<< payout_index_max << ","
<< opt_defn << ","
<< index_scen_mult << ","
<< index_scen_addn << ","
<< div_yld_scen_mult << ","
<< div_yld_addn << ","
<< lookback_defn << ","
<< lookback_sampling_interval << ","
<< lookback_yrs << ","
<< avr_contribn_pct << ","
<< avr_max_pct << ","
<< avr_obj_pct << ","
<< rbc_c1_pct << endl;

counter++;

return;
}



void EIO_ASSET::Terminator()
{

if (PVCFile != NULL)
	PVCFile.close();

}

FunctionPtr EIO_ASSET::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static EIO_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (EIO_ASSET_UDF::*dPXi) (int);
typedef double (EIO_ASSET_UDF::*dPXid) (int, double);
typedef double (EIO_ASSET_UDF::*dPF) ();
typedef double (EIO_ASSET_UDF::*dPFd) (double);
typedef int (EIO_ASSET_UDF::*iPF) ();
typedef int (EIO_ASSET_UDF::*iPFi) (int);
typedef xstring (EIO_ASSET_UDF::*sPF) ();
typedef xstring (EIO_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData EIO_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_inc", "eio_asset_accr_inc",  "accr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_accr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->accr_inc),
	CashFlowCommonData(2, "asset_detail_pv_flag", "eio_asset_asset_detail_pv_flag",  "asset_detail_pv_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_asset_detail_pv_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_detail_pv_flag),
	CashFlowCommonData(3, "asset_min_size_sale_flag", "eio_asset_asset_min_size_sale_flag",  "asset_min_size_sale_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_asset_min_size_sale_flag, 'E','N', '3', 'P', (size_t)&modelOffset->asset_min_size_sale_flag),
	CashFlowCommonData(4, "avr_basic_contribn", "eio_asset_avr_basic_contribn",  "avr_basic_contribn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_basic_contribn, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_basic_contribn),
	CashFlowCommonData(5, "avr_basic_contribn_bef_sale", "eio_asset_avr_basic_contribn_bef_sale",  "avr_basic_contribn_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_basic_contribn_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_basic_contribn_bef_sale),
	CashFlowCommonData(6, "avr_max", "eio_asset_avr_max",  "avr_max",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_max, 'E','N', '3', 'C', (size_t)&modelOffset->avr_max),
	CashFlowCommonData(7, "avr_max_bef_sale", "eio_asset_avr_max_bef_sale",  "avr_max_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_max_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->avr_max_bef_sale),
	CashFlowCommonData(8, "avr_obj", "eio_asset_avr_obj",  "avr_obj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_obj, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj),
	CashFlowCommonData(9, "avr_obj_bef_sale", "eio_asset_avr_obj_bef_sale",  "avr_obj_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_obj_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_obj_bef_sale),
	CashFlowCommonData(10, "avr_realzd_cap_gain", "eio_asset_avr_realzd_cap_gain",  "avr_realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_realzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->avr_realzd_cap_gain),
	CashFlowCommonData(11, "avr_realzd_cap_gain_from_sale", "eio_asset_avr_realzd_cap_gain_from_sale",  "avr_realzd_cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_realzd_cap_gain_from_sale, 'E','N', '3', 'C', (size_t)&modelOffset->avr_realzd_cap_gain_from_sale),
	CashFlowCommonData(12, "avr_unrealzd_cap_gain", "eio_asset_avr_unrealzd_cap_gain",  "avr_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->avr_unrealzd_cap_gain),
	CashFlowCommonData(13, "avr_unrealzd_cap_gain_bef_sale", "eio_asset_avr_unrealzd_cap_gain_bef_sale",  "avr_unrealzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->avr_unrealzd_cap_gain_bef_sale),
	CashFlowCommonData(14, "avr_unrealzd_cap_gain_released_on_sale", "eio_asset_avr_unrealzd_cap_gain_released_on_sale",  "avr_unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_avr_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->avr_unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(15, "bk_val", "eio_asset_bk_val",  "bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val),
	CashFlowCommonData(16, "bk_val_bef_fund_match_sale", "eio_asset_bk_val_bef_fund_match_sale",  "bk_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_fund_match_sale),
	CashFlowCommonData(17, "bk_val_bef_neg_cash_flow_sale", "eio_asset_bk_val_bef_neg_cash_flow_sale",  "bk_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(18, "bk_val_bef_rebal_sale", "eio_asset_bk_val_bef_rebal_sale",  "bk_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->bk_val_bef_rebal_sale),
	CashFlowCommonData(19, "bk_val_bef_sale", "eio_asset_bk_val_bef_sale",  "bk_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_bef_sale),
	CashFlowCommonData(20, "bk_val_plus_accr_int", "eio_asset_bk_val_plus_accr_int",  "bk_val_plus_accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int),
	CashFlowCommonData(21, "bk_val_plus_accr_int_bef_neg_cash_flow_sale", "eio_asset_bk_val_plus_accr_int_bef_neg_cash_flow_sale",  "bk_val_plus_accr_int_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int_bef_neg_cash_flow_sale),
	CashFlowCommonData(22, "bk_val_plus_accr_int_bef_rebal_sale", "eio_asset_bk_val_plus_accr_int_bef_rebal_sale",  "bk_val_plus_accr_int_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_plus_accr_int_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->bk_val_plus_accr_int_bef_rebal_sale),
	CashFlowCommonData(23, "bk_val_purch", "eio_asset_bk_val_purch",  "bk_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_bk_val_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_val_purch),
	CashFlowCommonData(24, "cal_mth", "eio_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(25, "cal_yr", "eio_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(26, "cal_yr_relative", "eio_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(27, "cap_gain_bef_sale", "eio_asset_cap_gain_bef_sale",  "cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cap_gain_bef_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_bef_sale),
	CashFlowCommonData(28, "cap_gain_from_sale", "eio_asset_cap_gain_from_sale",  "cap_gain_from_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cap_gain_from_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cap_gain_from_sale),
	CashFlowCommonData(29, "cash_flow", "eio_asset_cash_flow",  "cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->cash_flow),
	CashFlowCommonData(30, "cost_basis", "eio_asset_cost_basis",  "cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis),
	CashFlowCommonData(31, "cost_basis_accrual", "eio_asset_cost_basis_accrual",  "cost_basis_accrual",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis_accrual, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_accrual),
	CashFlowCommonData(32, "cost_basis_bef_sale", "eio_asset_cost_basis_bef_sale",  "cost_basis_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->cost_basis_bef_sale),
	CashFlowCommonData(33, "cost_basis_incr_appreciation", "eio_asset_cost_basis_incr_appreciation",  "cost_basis_incr_appreciation",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis_incr_appreciation, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_incr_appreciation),
	CashFlowCommonData(34, "cost_basis_purch", "eio_asset_cost_basis_purch",  "cost_basis_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->cost_basis_purch),
	CashFlowCommonData(35, "cost_basis_sold", "eio_asset_cost_basis_sold",  "cost_basis_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_cost_basis_sold, 'E','N', '3', 'C', (size_t)&modelOffset->cost_basis_sold),
	CashFlowCommonData(36, "date", "eio_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(37, "dur_val", "eio_asset_dur_val",  "dur_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_dur_val, 'E','N', '3', 'C', (size_t)&modelOffset->dur_val),
	CashFlowCommonData(38, "finalize", "eio_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(39, "gaap_inc_bk_val", "eio_asset_gaap_inc_bk_val",  "gaap_inc_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_gaap_inc_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bk_val),
	CashFlowCommonData(40, "gaap_inc_unrealzd_cap_gain", "eio_asset_gaap_inc_unrealzd_cap_gain",  "gaap_inc_unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_gaap_inc_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_unrealzd_cap_gain),
	CashFlowCommonData(41, "gaap_surp_bk_val", "eio_asset_gaap_surp_bk_val",  "gaap_surp_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_gaap_surp_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_surp_bk_val),
	CashFlowCommonData(42, "gaap_unrealzd_cap_gain_incr", "eio_asset_gaap_unrealzd_cap_gain_incr",  "gaap_unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_gaap_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_unrealzd_cap_gain_incr),
	CashFlowCommonData(43, "index_units_owned", "eio_asset_index_units_owned",  "index_units_owned",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_index_units_owned, 'E','N', '3', 'C', (size_t)&modelOffset->index_units_owned),
	CashFlowCommonData(44, "index_units_owned_bef_sale", "eio_asset_index_units_owned_bef_sale",  "index_units_owned_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_index_units_owned_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->index_units_owned_bef_sale),
	CashFlowCommonData(45, "index_val", "eio_asset_index_val",  "index_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_index_val, 'E','N', '3', 'P', (size_t)&modelOffset->index_val),
	CashFlowCommonData(46, "index_val_at_expiry_anniv", "eio_asset_index_val_at_expiry_anniv",  "index_val_at_expiry_anniv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_index_val_at_expiry_anniv, 'E','N', '3', 'P', (size_t)&modelOffset->index_val_at_expiry_anniv),
	CashFlowCommonData(47, "initialize", "eio_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(48, "lookback_index_val", "eio_asset_lookback_index_val",  "lookback_index_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_lookback_index_val, 'E','N', '3', 'P', (size_t)&modelOffset->lookback_index_val),
	CashFlowCommonData(49, "mkt_to_bk_ratio", "eio_asset_mkt_to_bk_ratio",  "mkt_to_bk_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_to_bk_ratio),
	CashFlowCommonData(50, "mkt_val", "eio_asset_mkt_val",  "mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val),
	CashFlowCommonData(51, "mkt_val_bef_fund_match_sale", "eio_asset_mkt_val_bef_fund_match_sale",  "mkt_val_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_bef_fund_match_sale),
	CashFlowCommonData(52, "mkt_val_bef_neg_cash_flow_sale", "eio_asset_mkt_val_bef_neg_cash_flow_sale",  "mkt_val_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_bef_neg_cash_flow_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_neg_cash_flow_sale),
	CashFlowCommonData(53, "mkt_val_bef_rebal_sale", "eio_asset_mkt_val_bef_rebal_sale",  "mkt_val_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_bef_rebal_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_rebal_sale),
	CashFlowCommonData(54, "mkt_val_bef_sale", "eio_asset_mkt_val_bef_sale",  "mkt_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->mkt_val_bef_sale),
	CashFlowCommonData(55, "mkt_val_purch", "eio_asset_mkt_val_purch",  "mkt_val_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_purch),
	CashFlowCommonData(56, "mkt_val_sold", "eio_asset_mkt_val_sold",  "mkt_val_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mkt_val_sold, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_sold),
	CashFlowCommonData(57, "mths_to_next_mkt_val_calc", "eio_asset_mths_to_next_mkt_val_calc",  "mths_to_next_mkt_val_calc",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_mths_to_next_mkt_val_calc, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_next_mkt_val_calc),
	CashFlowCommonData(58, "notional_amt", "eio_asset_notional_amt",  "notional_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt),
	CashFlowCommonData(59, "notional_amt_bef_fund_match_sale", "eio_asset_notional_amt_bef_fund_match_sale",  "notional_amt_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt_bef_fund_match_sale),
	CashFlowCommonData(60, "notional_amt_bef_neg_cash_flow_sale", "eio_asset_notional_amt_bef_neg_cash_flow_sale",  "notional_amt_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_bef_neg_cash_flow_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_neg_cash_flow_sale),
	CashFlowCommonData(61, "notional_amt_bef_rebal_sale", "eio_asset_notional_amt_bef_rebal_sale",  "notional_amt_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_bef_rebal_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->notional_amt_bef_rebal_sale),
	CashFlowCommonData(62, "notional_amt_bef_sale", "eio_asset_notional_amt_bef_sale",  "notional_amt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_bef_sale),
	CashFlowCommonData(63, "notional_amt_purch", "eio_asset_notional_amt_purch",  "notional_amt_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_amt_purch),
	CashFlowCommonData(64, "notional_amt_sold", "eio_asset_notional_amt_sold",  "notional_amt_sold",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_notional_amt_sold, 'E','N', '3', 'C', (size_t)&modelOffset->notional_amt_sold),
	CashFlowCommonData(65, "opt_pmt", "eio_asset_opt_pmt",  "opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_pmt),
	CashFlowCommonData(66, "opt_val_asset_down_1", "eio_asset_opt_val_asset_down_1",  "opt_val_asset_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_asset_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_asset_down_1),
	CashFlowCommonData(67, "opt_val_asset_down_1_bef_sale", "eio_asset_opt_val_asset_down_1_bef_sale",  "opt_val_asset_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_asset_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_asset_down_1_bef_sale),
	CashFlowCommonData(68, "opt_val_asset_up_1", "eio_asset_opt_val_asset_up_1",  "opt_val_asset_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_asset_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_asset_up_1),
	CashFlowCommonData(69, "opt_val_asset_up_1_bef_sale", "eio_asset_opt_val_asset_up_1_bef_sale",  "opt_val_asset_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_asset_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_asset_up_1_bef_sale),
	CashFlowCommonData(70, "opt_val_baseline", "eio_asset_opt_val_baseline",  "opt_val_baseline",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_baseline, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_baseline),
	CashFlowCommonData(71, "opt_val_baseline_bef_sale", "eio_asset_opt_val_baseline_bef_sale",  "opt_val_baseline_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_baseline_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_baseline_bef_sale),
	CashFlowCommonData(72, "opt_val_int_down_1", "eio_asset_opt_val_int_down_1",  "opt_val_int_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_down_1),
	CashFlowCommonData(73, "opt_val_int_down_1_bef_sale", "eio_asset_opt_val_int_down_1_bef_sale",  "opt_val_int_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_down_1_bef_sale),
	CashFlowCommonData(74, "opt_val_int_key_rate_10_down_1", "eio_asset_opt_val_int_key_rate_10_down_1",  "opt_val_int_key_rate_10_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_10_down_1),
	CashFlowCommonData(75, "opt_val_int_key_rate_10_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_10_down_1_bef_sale",  "opt_val_int_key_rate_10_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_10_down_1_bef_sale),
	CashFlowCommonData(76, "opt_val_int_key_rate_10_up_1", "eio_asset_opt_val_int_key_rate_10_up_1",  "opt_val_int_key_rate_10_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_10_up_1),
	CashFlowCommonData(77, "opt_val_int_key_rate_10_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_10_up_1_bef_sale",  "opt_val_int_key_rate_10_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_10_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_10_up_1_bef_sale),
	CashFlowCommonData(78, "opt_val_int_key_rate_1_down_1", "eio_asset_opt_val_int_key_rate_1_down_1",  "opt_val_int_key_rate_1_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_1_down_1),
	CashFlowCommonData(79, "opt_val_int_key_rate_1_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_1_down_1_bef_sale",  "opt_val_int_key_rate_1_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_1_down_1_bef_sale),
	CashFlowCommonData(80, "opt_val_int_key_rate_1_up_1", "eio_asset_opt_val_int_key_rate_1_up_1",  "opt_val_int_key_rate_1_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_1_up_1),
	CashFlowCommonData(81, "opt_val_int_key_rate_1_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_1_up_1_bef_sale",  "opt_val_int_key_rate_1_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_1_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_1_up_1_bef_sale),
	CashFlowCommonData(82, "opt_val_int_key_rate_2_down_1", "eio_asset_opt_val_int_key_rate_2_down_1",  "opt_val_int_key_rate_2_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_2_down_1),
	CashFlowCommonData(83, "opt_val_int_key_rate_2_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_2_down_1_bef_sale",  "opt_val_int_key_rate_2_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_2_down_1_bef_sale),
	CashFlowCommonData(84, "opt_val_int_key_rate_2_up_1", "eio_asset_opt_val_int_key_rate_2_up_1",  "opt_val_int_key_rate_2_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_2_up_1),
	CashFlowCommonData(85, "opt_val_int_key_rate_2_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_2_up_1_bef_sale",  "opt_val_int_key_rate_2_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_2_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_2_up_1_bef_sale),
	CashFlowCommonData(86, "opt_val_int_key_rate_3_down_1", "eio_asset_opt_val_int_key_rate_3_down_1",  "opt_val_int_key_rate_3_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_3_down_1),
	CashFlowCommonData(87, "opt_val_int_key_rate_3_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_3_down_1_bef_sale",  "opt_val_int_key_rate_3_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_3_down_1_bef_sale),
	CashFlowCommonData(88, "opt_val_int_key_rate_3_up_1", "eio_asset_opt_val_int_key_rate_3_up_1",  "opt_val_int_key_rate_3_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_3_up_1),
	CashFlowCommonData(89, "opt_val_int_key_rate_3_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_3_up_1_bef_sale",  "opt_val_int_key_rate_3_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_3_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_3_up_1_bef_sale),
	CashFlowCommonData(90, "opt_val_int_key_rate_4_down_1", "eio_asset_opt_val_int_key_rate_4_down_1",  "opt_val_int_key_rate_4_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_4_down_1),
	CashFlowCommonData(91, "opt_val_int_key_rate_4_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_4_down_1_bef_sale",  "opt_val_int_key_rate_4_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_4_down_1_bef_sale),
	CashFlowCommonData(92, "opt_val_int_key_rate_4_up_1", "eio_asset_opt_val_int_key_rate_4_up_1",  "opt_val_int_key_rate_4_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_4_up_1),
	CashFlowCommonData(93, "opt_val_int_key_rate_4_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_4_up_1_bef_sale",  "opt_val_int_key_rate_4_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_4_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_4_up_1_bef_sale),
	CashFlowCommonData(94, "opt_val_int_key_rate_5_down_1", "eio_asset_opt_val_int_key_rate_5_down_1",  "opt_val_int_key_rate_5_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_5_down_1),
	CashFlowCommonData(95, "opt_val_int_key_rate_5_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_5_down_1_bef_sale",  "opt_val_int_key_rate_5_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_5_down_1_bef_sale),
	CashFlowCommonData(96, "opt_val_int_key_rate_5_up_1", "eio_asset_opt_val_int_key_rate_5_up_1",  "opt_val_int_key_rate_5_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_5_up_1),
	CashFlowCommonData(97, "opt_val_int_key_rate_5_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_5_up_1_bef_sale",  "opt_val_int_key_rate_5_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_5_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_5_up_1_bef_sale),
	CashFlowCommonData(98, "opt_val_int_key_rate_6_down_1", "eio_asset_opt_val_int_key_rate_6_down_1",  "opt_val_int_key_rate_6_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_6_down_1),
	CashFlowCommonData(99, "opt_val_int_key_rate_6_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_6_down_1_bef_sale",  "opt_val_int_key_rate_6_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_6_down_1_bef_sale),
	CashFlowCommonData(100, "opt_val_int_key_rate_6_up_1", "eio_asset_opt_val_int_key_rate_6_up_1",  "opt_val_int_key_rate_6_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_6_up_1),
	CashFlowCommonData(101, "opt_val_int_key_rate_6_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_6_up_1_bef_sale",  "opt_val_int_key_rate_6_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_6_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_6_up_1_bef_sale),
	CashFlowCommonData(102, "opt_val_int_key_rate_7_down_1", "eio_asset_opt_val_int_key_rate_7_down_1",  "opt_val_int_key_rate_7_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_7_down_1),
	CashFlowCommonData(103, "opt_val_int_key_rate_7_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_7_down_1_bef_sale",  "opt_val_int_key_rate_7_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_7_down_1_bef_sale),
	CashFlowCommonData(104, "opt_val_int_key_rate_7_up_1", "eio_asset_opt_val_int_key_rate_7_up_1",  "opt_val_int_key_rate_7_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_7_up_1),
	CashFlowCommonData(105, "opt_val_int_key_rate_7_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_7_up_1_bef_sale",  "opt_val_int_key_rate_7_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_7_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_7_up_1_bef_sale),
	CashFlowCommonData(106, "opt_val_int_key_rate_8_down_1", "eio_asset_opt_val_int_key_rate_8_down_1",  "opt_val_int_key_rate_8_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_8_down_1),
	CashFlowCommonData(107, "opt_val_int_key_rate_8_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_8_down_1_bef_sale",  "opt_val_int_key_rate_8_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_8_down_1_bef_sale),
	CashFlowCommonData(108, "opt_val_int_key_rate_8_up_1", "eio_asset_opt_val_int_key_rate_8_up_1",  "opt_val_int_key_rate_8_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_8_up_1),
	CashFlowCommonData(109, "opt_val_int_key_rate_8_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_8_up_1_bef_sale",  "opt_val_int_key_rate_8_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_8_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_8_up_1_bef_sale),
	CashFlowCommonData(110, "opt_val_int_key_rate_9_down_1", "eio_asset_opt_val_int_key_rate_9_down_1",  "opt_val_int_key_rate_9_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_9_down_1),
	CashFlowCommonData(111, "opt_val_int_key_rate_9_down_1_bef_sale", "eio_asset_opt_val_int_key_rate_9_down_1_bef_sale",  "opt_val_int_key_rate_9_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_9_down_1_bef_sale),
	CashFlowCommonData(112, "opt_val_int_key_rate_9_up_1", "eio_asset_opt_val_int_key_rate_9_up_1",  "opt_val_int_key_rate_9_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_9_up_1),
	CashFlowCommonData(113, "opt_val_int_key_rate_9_up_1_bef_sale", "eio_asset_opt_val_int_key_rate_9_up_1_bef_sale",  "opt_val_int_key_rate_9_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_key_rate_9_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_key_rate_9_up_1_bef_sale),
	CashFlowCommonData(114, "opt_val_int_up_1", "eio_asset_opt_val_int_up_1",  "opt_val_int_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_up_1),
	CashFlowCommonData(115, "opt_val_int_up_1_bef_sale", "eio_asset_opt_val_int_up_1_bef_sale",  "opt_val_int_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_int_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_int_up_1_bef_sale),
	CashFlowCommonData(116, "opt_val_vol_down_1", "eio_asset_opt_val_vol_down_1",  "opt_val_vol_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_down_1),
	CashFlowCommonData(117, "opt_val_vol_down_1_bef_sale", "eio_asset_opt_val_vol_down_1_bef_sale",  "opt_val_vol_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_down_1_bef_sale),
	CashFlowCommonData(118, "opt_val_vol_term_1_down_1", "eio_asset_opt_val_vol_term_1_down_1",  "opt_val_vol_term_1_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_1_down_1),
	CashFlowCommonData(119, "opt_val_vol_term_1_down_1_bef_sale", "eio_asset_opt_val_vol_term_1_down_1_bef_sale",  "opt_val_vol_term_1_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_1_down_1_bef_sale),
	CashFlowCommonData(120, "opt_val_vol_term_1_up_1", "eio_asset_opt_val_vol_term_1_up_1",  "opt_val_vol_term_1_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_1_up_1),
	CashFlowCommonData(121, "opt_val_vol_term_1_up_1_bef_sale", "eio_asset_opt_val_vol_term_1_up_1_bef_sale",  "opt_val_vol_term_1_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_1_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_1_up_1_bef_sale),
	CashFlowCommonData(122, "opt_val_vol_term_2_down_1", "eio_asset_opt_val_vol_term_2_down_1",  "opt_val_vol_term_2_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_2_down_1),
	CashFlowCommonData(123, "opt_val_vol_term_2_down_1_bef_sale", "eio_asset_opt_val_vol_term_2_down_1_bef_sale",  "opt_val_vol_term_2_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_2_down_1_bef_sale),
	CashFlowCommonData(124, "opt_val_vol_term_2_up_1", "eio_asset_opt_val_vol_term_2_up_1",  "opt_val_vol_term_2_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_2_up_1),
	CashFlowCommonData(125, "opt_val_vol_term_2_up_1_bef_sale", "eio_asset_opt_val_vol_term_2_up_1_bef_sale",  "opt_val_vol_term_2_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_2_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_2_up_1_bef_sale),
	CashFlowCommonData(126, "opt_val_vol_term_3_down_1", "eio_asset_opt_val_vol_term_3_down_1",  "opt_val_vol_term_3_down_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_down_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_3_down_1),
	CashFlowCommonData(127, "opt_val_vol_term_3_down_1_bef_sale", "eio_asset_opt_val_vol_term_3_down_1_bef_sale",  "opt_val_vol_term_3_down_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_down_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_3_down_1_bef_sale),
	CashFlowCommonData(128, "opt_val_vol_term_3_up_1", "eio_asset_opt_val_vol_term_3_up_1",  "opt_val_vol_term_3_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_3_up_1),
	CashFlowCommonData(129, "opt_val_vol_term_3_up_1_bef_sale", "eio_asset_opt_val_vol_term_3_up_1_bef_sale",  "opt_val_vol_term_3_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_term_3_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_term_3_up_1_bef_sale),
	CashFlowCommonData(130, "opt_val_vol_up_1", "eio_asset_opt_val_vol_up_1",  "opt_val_vol_up_1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_up_1, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_up_1),
	CashFlowCommonData(131, "opt_val_vol_up_1_bef_sale", "eio_asset_opt_val_vol_up_1_bef_sale",  "opt_val_vol_up_1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_opt_val_vol_up_1_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->opt_val_vol_up_1_bef_sale),
	CashFlowCommonData(132, "rbc_c1", "eio_asset_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(133, "rbc_c1_bef_sale", "eio_asset_rbc_c1_bef_sale",  "rbc_c1_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_rbc_c1_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1_bef_sale),
	CashFlowCommonData(134, "realzd_cap_gain", "eio_asset_realzd_cap_gain",  "realzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_realzd_cap_gain, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain),
	CashFlowCommonData(135, "realzd_cap_gain_opt_pmt", "eio_asset_realzd_cap_gain_opt_pmt",  "realzd_cap_gain_opt_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_realzd_cap_gain_opt_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->realzd_cap_gain_opt_pmt),
	CashFlowCommonData(136, "realzd_cap_gain_sale", "eio_asset_realzd_cap_gain_sale",  "realzd_cap_gain_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_realzd_cap_gain_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->realzd_cap_gain_sale),
	CashFlowCommonData(137, "sold_pct", "eio_asset_sold_pct",  "sold_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sold_pct, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct),
	CashFlowCommonData(138, "sold_pct_fund_match", "eio_asset_sold_pct_fund_match",  "sold_pct_fund_match",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sold_pct_fund_match, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_fund_match),
	CashFlowCommonData(139, "sold_pct_neg_cash_flow", "eio_asset_sold_pct_neg_cash_flow",  "sold_pct_neg_cash_flow",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sold_pct_neg_cash_flow, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_neg_cash_flow),
	CashFlowCommonData(140, "sold_pct_planned", "eio_asset_sold_pct_planned",  "sold_pct_planned",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sold_pct_planned, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_planned),
	CashFlowCommonData(141, "sold_pct_rebal", "eio_asset_sold_pct_rebal",  "sold_pct_rebal",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sold_pct_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->sold_pct_rebal),
	CashFlowCommonData(142, "spot_sprd_adj", "eio_asset_spot_sprd_adj",  "spot_sprd_adj",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_spot_sprd_adj, 'E','N', '3', 'C', (size_t)&modelOffset->spot_sprd_adj),
	CashFlowCommonData(143, "startup", "eio_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(144, "sub_port_id", "eio_asset_sub_port_id",  "sub_port_id",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_sub_port_id, 'E','N', '3', 'P', (size_t)&modelOffset->sub_port_id),
	CashFlowCommonData(145, "unrealzd_cap_gain", "eio_asset_unrealzd_cap_gain",  "unrealzd_cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain),
	CashFlowCommonData(146, "unrealzd_cap_gain_bef_fund_match_sale", "eio_asset_unrealzd_cap_gain_bef_fund_match_sale",  "unrealzd_cap_gain_bef_fund_match_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_fund_match_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_fund_match_sale),
	CashFlowCommonData(147, "unrealzd_cap_gain_bef_neg_cash_flow_sale", "eio_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale",  "unrealzd_cap_gain_bef_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_neg_cash_flow_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_neg_cash_flow_sale),
	CashFlowCommonData(148, "unrealzd_cap_gain_bef_rebal_sale", "eio_asset_unrealzd_cap_gain_bef_rebal_sale",  "unrealzd_cap_gain_bef_rebal_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_rebal_sale, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_bef_rebal_sale),
	CashFlowCommonData(149, "unrealzd_cap_gain_bef_sale", "eio_asset_unrealzd_cap_gain_bef_sale",  "unrealzd_cap_gain_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_bef_sale),
	CashFlowCommonData(150, "unrealzd_cap_gain_gaap_surp", "eio_asset_unrealzd_cap_gain_gaap_surp",  "unrealzd_cap_gain_gaap_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_gaap_surp, 'E','N', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_gaap_surp),
	CashFlowCommonData(151, "unrealzd_cap_gain_incr", "eio_asset_unrealzd_cap_gain_incr",  "unrealzd_cap_gain_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_incr),
	CashFlowCommonData(152, "unrealzd_cap_gain_released_on_sale", "eio_asset_unrealzd_cap_gain_released_on_sale",  "unrealzd_cap_gain_released_on_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_released_on_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->unrealzd_cap_gain_released_on_sale),
	CashFlowCommonData(153, "unrealzd_cap_gain_to_bk_ratio", "eio_asset_unrealzd_cap_gain_to_bk_ratio",  "unrealzd_cap_gain_to_bk_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_unrealzd_cap_gain_to_bk_ratio, 'E','N', '3', 'P', (size_t)&modelOffset->unrealzd_cap_gain_to_bk_ratio),
	CashFlowCommonData(154, "volatility_sprd_adj", "eio_asset_volatility_sprd_adj",  "volatility_sprd_adj",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_volatility_sprd_adj, 'E','N', '3', 'C', (size_t)&modelOffset->volatility_sprd_adj),
	CashFlowCommonData(155, "yld_denom", "eio_asset_yld_denom",  "yld_denom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_yld_denom, 'E','N', '3', 'C', (size_t)&modelOffset->yld_denom),
	CashFlowCommonData(156, "yld_numer", "eio_asset_yld_numer",  "yld_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&EIO_ASSET_UDF::eio_asset_yld_numer, 'E','N', '3', 'C', (size_t)&modelOffset->yld_numer)
};
const CashFlowCommonData* EIO_ASSET::mCFStaticData[] = {
	&EIO_ASSET::mCFStaticData_0[0],
	&EIO_ASSET::mCFStaticData_0[1],
	&EIO_ASSET::mCFStaticData_0[2],
	&EIO_ASSET::mCFStaticData_0[3],
	&EIO_ASSET::mCFStaticData_0[4],
	&EIO_ASSET::mCFStaticData_0[5],
	&EIO_ASSET::mCFStaticData_0[6],
	&EIO_ASSET::mCFStaticData_0[7],
	&EIO_ASSET::mCFStaticData_0[8],
	&EIO_ASSET::mCFStaticData_0[9],
	&EIO_ASSET::mCFStaticData_0[10],
	&EIO_ASSET::mCFStaticData_0[11],
	&EIO_ASSET::mCFStaticData_0[12],
	&EIO_ASSET::mCFStaticData_0[13],
	&EIO_ASSET::mCFStaticData_0[14],
	&EIO_ASSET::mCFStaticData_0[15],
	&EIO_ASSET::mCFStaticData_0[16],
	&EIO_ASSET::mCFStaticData_0[17],
	&EIO_ASSET::mCFStaticData_0[18],
	&EIO_ASSET::mCFStaticData_0[19],
	&EIO_ASSET::mCFStaticData_0[20],
	&EIO_ASSET::mCFStaticData_0[21],
	&EIO_ASSET::mCFStaticData_0[22],
	&EIO_ASSET::mCFStaticData_0[23],
	&EIO_ASSET::mCFStaticData_0[24],
	&EIO_ASSET::mCFStaticData_0[25],
	&EIO_ASSET::mCFStaticData_0[26],
	&EIO_ASSET::mCFStaticData_0[27],
	&EIO_ASSET::mCFStaticData_0[28],
	&EIO_ASSET::mCFStaticData_0[29],
	&EIO_ASSET::mCFStaticData_0[30],
	&EIO_ASSET::mCFStaticData_0[31],
	&EIO_ASSET::mCFStaticData_0[32],
	&EIO_ASSET::mCFStaticData_0[33],
	&EIO_ASSET::mCFStaticData_0[34],
	&EIO_ASSET::mCFStaticData_0[35],
	&EIO_ASSET::mCFStaticData_0[36],
	&EIO_ASSET::mCFStaticData_0[37],
	&EIO_ASSET::mCFStaticData_0[38],
	&EIO_ASSET::mCFStaticData_0[39],
	&EIO_ASSET::mCFStaticData_0[40],
	&EIO_ASSET::mCFStaticData_0[41],
	&EIO_ASSET::mCFStaticData_0[42],
	&EIO_ASSET::mCFStaticData_0[43],
	&EIO_ASSET::mCFStaticData_0[44],
	&EIO_ASSET::mCFStaticData_0[45],
	&EIO_ASSET::mCFStaticData_0[46],
	&EIO_ASSET::mCFStaticData_0[47],
	&EIO_ASSET::mCFStaticData_0[48],
	&EIO_ASSET::mCFStaticData_0[49],
	&EIO_ASSET::mCFStaticData_0[50],
	&EIO_ASSET::mCFStaticData_0[51],
	&EIO_ASSET::mCFStaticData_0[52],
	&EIO_ASSET::mCFStaticData_0[53],
	&EIO_ASSET::mCFStaticData_0[54],
	&EIO_ASSET::mCFStaticData_0[55],
	&EIO_ASSET::mCFStaticData_0[56],
	&EIO_ASSET::mCFStaticData_0[57],
	&EIO_ASSET::mCFStaticData_0[58],
	&EIO_ASSET::mCFStaticData_0[59],
	&EIO_ASSET::mCFStaticData_0[60],
	&EIO_ASSET::mCFStaticData_0[61],
	&EIO_ASSET::mCFStaticData_0[62],
	&EIO_ASSET::mCFStaticData_0[63],
	&EIO_ASSET::mCFStaticData_0[64],
	&EIO_ASSET::mCFStaticData_0[65],
	&EIO_ASSET::mCFStaticData_0[66],
	&EIO_ASSET::mCFStaticData_0[67],
	&EIO_ASSET::mCFStaticData_0[68],
	&EIO_ASSET::mCFStaticData_0[69],
	&EIO_ASSET::mCFStaticData_0[70],
	&EIO_ASSET::mCFStaticData_0[71],
	&EIO_ASSET::mCFStaticData_0[72],
	&EIO_ASSET::mCFStaticData_0[73],
	&EIO_ASSET::mCFStaticData_0[74],
	&EIO_ASSET::mCFStaticData_0[75],
	&EIO_ASSET::mCFStaticData_0[76],
	&EIO_ASSET::mCFStaticData_0[77],
	&EIO_ASSET::mCFStaticData_0[78],
	&EIO_ASSET::mCFStaticData_0[79],
	&EIO_ASSET::mCFStaticData_0[80],
	&EIO_ASSET::mCFStaticData_0[81],
	&EIO_ASSET::mCFStaticData_0[82],
	&EIO_ASSET::mCFStaticData_0[83],
	&EIO_ASSET::mCFStaticData_0[84],
	&EIO_ASSET::mCFStaticData_0[85],
	&EIO_ASSET::mCFStaticData_0[86],
	&EIO_ASSET::mCFStaticData_0[87],
	&EIO_ASSET::mCFStaticData_0[88],
	&EIO_ASSET::mCFStaticData_0[89],
	&EIO_ASSET::mCFStaticData_0[90],
	&EIO_ASSET::mCFStaticData_0[91],
	&EIO_ASSET::mCFStaticData_0[92],
	&EIO_ASSET::mCFStaticData_0[93],
	&EIO_ASSET::mCFStaticData_0[94],
	&EIO_ASSET::mCFStaticData_0[95],
	&EIO_ASSET::mCFStaticData_0[96],
	&EIO_ASSET::mCFStaticData_0[97],
	&EIO_ASSET::mCFStaticData_0[98],
	&EIO_ASSET::mCFStaticData_0[99],
	&EIO_ASSET::mCFStaticData_0[100],
	&EIO_ASSET::mCFStaticData_0[101],
	&EIO_ASSET::mCFStaticData_0[102],
	&EIO_ASSET::mCFStaticData_0[103],
	&EIO_ASSET::mCFStaticData_0[104],
	&EIO_ASSET::mCFStaticData_0[105],
	&EIO_ASSET::mCFStaticData_0[106],
	&EIO_ASSET::mCFStaticData_0[107],
	&EIO_ASSET::mCFStaticData_0[108],
	&EIO_ASSET::mCFStaticData_0[109],
	&EIO_ASSET::mCFStaticData_0[110],
	&EIO_ASSET::mCFStaticData_0[111],
	&EIO_ASSET::mCFStaticData_0[112],
	&EIO_ASSET::mCFStaticData_0[113],
	&EIO_ASSET::mCFStaticData_0[114],
	&EIO_ASSET::mCFStaticData_0[115],
	&EIO_ASSET::mCFStaticData_0[116],
	&EIO_ASSET::mCFStaticData_0[117],
	&EIO_ASSET::mCFStaticData_0[118],
	&EIO_ASSET::mCFStaticData_0[119],
	&EIO_ASSET::mCFStaticData_0[120],
	&EIO_ASSET::mCFStaticData_0[121],
	&EIO_ASSET::mCFStaticData_0[122],
	&EIO_ASSET::mCFStaticData_0[123],
	&EIO_ASSET::mCFStaticData_0[124],
	&EIO_ASSET::mCFStaticData_0[125],
	&EIO_ASSET::mCFStaticData_0[126],
	&EIO_ASSET::mCFStaticData_0[127],
	&EIO_ASSET::mCFStaticData_0[128],
	&EIO_ASSET::mCFStaticData_0[129],
	&EIO_ASSET::mCFStaticData_0[130],
	&EIO_ASSET::mCFStaticData_0[131],
	&EIO_ASSET::mCFStaticData_0[132],
	&EIO_ASSET::mCFStaticData_0[133],
	&EIO_ASSET::mCFStaticData_0[134],
	&EIO_ASSET::mCFStaticData_0[135],
	&EIO_ASSET::mCFStaticData_0[136],
	&EIO_ASSET::mCFStaticData_0[137],
	&EIO_ASSET::mCFStaticData_0[138],
	&EIO_ASSET::mCFStaticData_0[139],
	&EIO_ASSET::mCFStaticData_0[140],
	&EIO_ASSET::mCFStaticData_0[141],
	&EIO_ASSET::mCFStaticData_0[142],
	&EIO_ASSET::mCFStaticData_0[143],
	&EIO_ASSET::mCFStaticData_0[144],
	&EIO_ASSET::mCFStaticData_0[145],
	&EIO_ASSET::mCFStaticData_0[146],
	&EIO_ASSET::mCFStaticData_0[147],
	&EIO_ASSET::mCFStaticData_0[148],
	&EIO_ASSET::mCFStaticData_0[149],
	&EIO_ASSET::mCFStaticData_0[150],
	&EIO_ASSET::mCFStaticData_0[151],
	&EIO_ASSET::mCFStaticData_0[152],
	&EIO_ASSET::mCFStaticData_0[153],
	&EIO_ASSET::mCFStaticData_0[154],
	&EIO_ASSET::mCFStaticData_0[155],
	&EIO_ASSET::mCFStaticData_0[156],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

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
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
		,ChoicePair(StrEnum::LOWER_OF_COST_AND_MARKET, "Lower of Cost and Market")
		,ChoicePair(StrEnum::HISTORIC_LOWEST_COST, "Historic Lowest Cost")
		,ChoicePair(StrEnum::HISTORIC_LOWEST_COST_AND_MARKET, "Historic Lowest Cost and Market")
	};
	const EnumList bk_val_defnEnumList(5, bk_val_defnChoicePairs);

	// EnumList for cost_basis_defn                                                                                       
	const ChoicePair cost_basis_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ACTUAL_COST, "Actual Cost")
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
		,ChoicePair(StrEnum::STRAIGHT_LINE_AMORTIZATION, "Straight-Line Amortization")
	};
	const EnumList cost_basis_defnEnumList(3, cost_basis_defnChoicePairs);

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for lookback_defn_mp                                                                                       
	const ChoicePair lookback_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NONE, "None")
		,ChoicePair(StrEnum::ASIAN, "Asian")
		,ChoicePair(StrEnum::HIGHEST_GAIN, "Highest Gain")
	};
	const EnumList lookback_defn_mpEnumList(3, lookback_defn_mpChoicePairs);

	// EnumList for lookback_sampling_interval_mp                                                                                       
	const ChoicePair lookback_sampling_interval_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::SEMIANNUAL, "Semiannual")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList lookback_sampling_interval_mpEnumList(4, lookback_sampling_interval_mpChoicePairs);

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

	// EnumList for opt_defn_mp                                                                                       
	const ChoicePair opt_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "Call")
		,ChoicePair(StrEnum::PUT, "Put")
		,ChoicePair(StrEnum::FUTURES, "Futures")
	};
	const EnumList opt_defn_mpEnumList(3, opt_defn_mpChoicePairs);

	// EnumList for port_defn_mp                                                                                       
	const ChoicePair port_defn_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList port_defn_mpEnumList(2, port_defn_mpChoicePairs);

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

	namespace EIO_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(EIO_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(EIO_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace EIO_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void EIO_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> EIO_ASSET::mgr_;

	Attribute::Descriptor EIO_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STRING,	"asset_detail_rpt_cusip_id", -1, (size_t)&modelOffset->asset_detail_rpt_cusip_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STRING,	"asset_detail_rpt_id", -1, (size_t)&modelOffset->asset_detail_rpt_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STR_ENUM,	"asset_detail_rpt_pv_defn", -1, (size_t)&modelOffset->asset_detail_rpt_pv_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_pv_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"asset_id_mp", -1, (size_t)&modelOffset->asset_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"asset_index_mp", -1, (size_t)&modelOffset->asset_index_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"asset_mkt_sprd_use_defn", -1, (size_t)&modelOffset->asset_mkt_sprd_use_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_mkt_sprd_use_defnEnumList, Feature(true)),
	Descriptor(9, Attribute::DOUBLE,	"avr_contribn_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_contribn_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"avr_max_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_max_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"avr_obj_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->avr_obj_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STR_ENUM,	"bk_val_defn", -1, (size_t)&modelOffset->bk_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &bk_val_defnEnumList, Feature(true)),
	Descriptor(13, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STRING,	"category_id_mp", -1, (size_t)&modelOffset->category_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"cost_basis_defn", -1, (size_t)&modelOffset->cost_basis_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cost_basis_defnEnumList, Feature(true)),
	Descriptor(16, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(17, Attribute::DOUBLE,	"div_yld_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->div_yld_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::DOUBLE,	"div_yld_scen_mult_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->div_yld_scen_mult_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::STRING,	"hdg_grp_code_mp", -1, (size_t)&modelOffset->hdg_grp_code_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"index_scen_addn_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_scen_addn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"index_scen_mult_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_scen_mult_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"index_val_at_issue_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_val_at_issue_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"init_bk_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_bk_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::DOUBLE,	"init_cost_basis_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cost_basis_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::DOUBLE,	"init_index_units_owned_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_index_units_owned_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"init_index_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_index_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::DOUBLE,	"init_mkt_val_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_mkt_val_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::STR_ENUM,	"lookback_defn_mp", -1, (size_t)&modelOffset->lookback_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_defn_mpEnumList, Feature(true)),
	Descriptor(29, Attribute::STR_ENUM,	"lookback_sampling_interval_mp", -1, (size_t)&modelOffset->lookback_sampling_interval_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_sampling_interval_mpEnumList, Feature(true)),
	Descriptor(30, Attribute::DOUBLE,	"lookback_yrs_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lookback_yrs_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"maturity_date_mp", -1, (size_t)&modelOffset->maturity_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STR_ENUM,	"mkt_val_calc_freq", -1, (size_t)&modelOffset->mkt_val_calc_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mkt_val_calc_freqEnumList, Feature(true)),
	Descriptor(33, Attribute::INT,	"mkt_val_calc_freq_yrs", -1, (size_t)&modelOffset->mkt_val_calc_freq_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::STR_ENUM,	"opt_defn_mp", -1, (size_t)&modelOffset->opt_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &opt_defn_mpEnumList, Feature(true)),
	Descriptor(35, Attribute::DOUBLE,	"opt_strike_price_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->opt_strike_price_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::DOUBLE,	"payout_index_max_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->payout_index_max_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::STRING,	"planned_sale_date_mp", -1, (size_t)&modelOffset->planned_sale_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::STR_ENUM,	"port_defn_mp", -1, (size_t)&modelOffset->port_defn_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &port_defn_mpEnumList, Feature(true)),
	Descriptor(39, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::STRING,	"purch_asset_id", -1, (size_t)&modelOffset->purch_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::INT,	"purch_asset_sub_port", -1, (size_t)&modelOffset->purch_asset_sub_port,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::DOUBLE,	"rbc_c1_pct_mp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_pct_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::STR_ENUM,	"sale_class_mp", -1, (size_t)&modelOffset->sale_class_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sale_class_mpEnumList, Feature(true)),
	Descriptor(44, Attribute::STRING,	"seg_id_mp", -1, (size_t)&modelOffset->seg_id_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(46, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::SCALAR_INT,	"asset_detail_rpt_flag", -1, (size_t)&modelOffset->asset_detail_rpt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_asset_detail_rpt_flag)),
	Descriptor(48, Attribute::SCALAR_INT,	"asset_fund_index", -1, (size_t)&modelOffset->asset_fund_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_asset_fund_index)),
	Descriptor(49, Attribute::SCALAR_DOUBLE,	"bk_val_bef_expiry", -1, (size_t)&modelOffset->bk_val_bef_expiry,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_bk_val_bef_expiry)),
	Descriptor(50, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_commencement_period)),
	Descriptor(51, Attribute::SCALAR_DOUBLE,	"cost_basis_bef_expiry", -1, (size_t)&modelOffset->cost_basis_bef_expiry,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_cost_basis_bef_expiry)),
	Descriptor(52, Attribute::SCALAR_STRING,	"data_grp_id", -1, (size_t)&modelOffset->data_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&EIO_ASSET_UDF::eio_asset_data_grp_id)),
	Descriptor(53, Attribute::SCALAR_INT,	"existing_asset_indicator", -1, (size_t)&modelOffset->existing_asset_indicator,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_existing_asset_indicator)),
	Descriptor(54, Attribute::SCALAR_INT,	"gaap_inc_defn", -1, (size_t)&modelOffset->gaap_inc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_gaap_inc_defn)),
	Descriptor(55, Attribute::SCALAR_INT,	"gaap_val_defn", -1, (size_t)&modelOffset->gaap_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_gaap_val_defn)),
	Descriptor(56, Attribute::SCALAR_DOUBLE,	"init_mkt_val_calc", -1, (size_t)&modelOffset->init_mkt_val_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_init_mkt_val_calc)),
	Descriptor(57, Attribute::SCALAR_INT,	"lookback_mths", -1, (size_t)&modelOffset->lookback_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_lookback_mths)),
	Descriptor(58, Attribute::SCALAR_INT,	"lookback_sampling_mths", -1, (size_t)&modelOffset->lookback_sampling_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_lookback_sampling_mths)),
	Descriptor(59, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_maturity_period)),
	Descriptor(60, Attribute::SCALAR_DOUBLE,	"mkt_val_at_issue", -1, (size_t)&modelOffset->mkt_val_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_mkt_val_at_issue)),
	Descriptor(61, Attribute::SCALAR_DOUBLE,	"mkt_val_bef_expiry", -1, (size_t)&modelOffset->mkt_val_bef_expiry,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_mkt_val_bef_expiry)),
	Descriptor(62, Attribute::SCALAR_DOUBLE,	"neg_asset_flag", -1, (size_t)&modelOffset->neg_asset_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_neg_asset_flag)),
	Descriptor(63, Attribute::SCALAR_DOUBLE,	"notional_amt_at_issue", -1, (size_t)&modelOffset->notional_amt_at_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_notional_amt_at_issue)),
	Descriptor(64, Attribute::SCALAR_DOUBLE,	"pct_to_use", -1, (size_t)&modelOffset->pct_to_use,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&EIO_ASSET_UDF::eio_asset_pct_to_use)),
	Descriptor(65, Attribute::SCALAR_INT,	"planned_sale_period", -1, (size_t)&modelOffset->planned_sale_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_planned_sale_period)),
	Descriptor(66, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&EIO_ASSET_UDF::eio_asset_proj_date_adj)),
	Descriptor(67, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_proj_start_date)),
	Descriptor(68, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_proj_start_mth)),
	Descriptor(69, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_proj_start_yr)),
	Descriptor(70, Attribute::SCALAR_INT,	"sale_class_id", -1, (size_t)&modelOffset->sale_class_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_sale_class_id)),
	Descriptor(71, Attribute::SCALAR_INT,	"seg_num", -1, (size_t)&modelOffset->seg_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_seg_num)),
	Descriptor(72, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&EIO_ASSET_UDF::eio_asset_start_period)),
	};

	Attribute::Descriptor* EIO_ASSET::descriptorTable[] = {
	&EIO_ASSET::descriptor_0[0],
	&EIO_ASSET::descriptor_0[1],
	&EIO_ASSET::descriptor_0[2],
	&EIO_ASSET::descriptor_0[3],
	&EIO_ASSET::descriptor_0[4],
	&EIO_ASSET::descriptor_0[5],
	&EIO_ASSET::descriptor_0[6],
	&EIO_ASSET::descriptor_0[7],
	&EIO_ASSET::descriptor_0[8],
	&EIO_ASSET::descriptor_0[9],
	&EIO_ASSET::descriptor_0[10],
	&EIO_ASSET::descriptor_0[11],
	&EIO_ASSET::descriptor_0[12],
	&EIO_ASSET::descriptor_0[13],
	&EIO_ASSET::descriptor_0[14],
	&EIO_ASSET::descriptor_0[15],
	&EIO_ASSET::descriptor_0[16],
	&EIO_ASSET::descriptor_0[17],
	&EIO_ASSET::descriptor_0[18],
	&EIO_ASSET::descriptor_0[19],
	&EIO_ASSET::descriptor_0[20],
	&EIO_ASSET::descriptor_0[21],
	&EIO_ASSET::descriptor_0[22],
	&EIO_ASSET::descriptor_0[23],
	&EIO_ASSET::descriptor_0[24],
	&EIO_ASSET::descriptor_0[25],
	&EIO_ASSET::descriptor_0[26],
	&EIO_ASSET::descriptor_0[27],
	&EIO_ASSET::descriptor_0[28],
	&EIO_ASSET::descriptor_0[29],
	&EIO_ASSET::descriptor_0[30],
	&EIO_ASSET::descriptor_0[31],
	&EIO_ASSET::descriptor_0[32],
	&EIO_ASSET::descriptor_0[33],
	&EIO_ASSET::descriptor_0[34],
	&EIO_ASSET::descriptor_0[35],
	&EIO_ASSET::descriptor_0[36],
	&EIO_ASSET::descriptor_0[37],
	&EIO_ASSET::descriptor_0[38],
	&EIO_ASSET::descriptor_0[39],
	&EIO_ASSET::descriptor_0[40],
	&EIO_ASSET::descriptor_0[41],
	&EIO_ASSET::descriptor_0[42],
	&EIO_ASSET::descriptor_0[43],
	&EIO_ASSET::descriptor_0[44],
	&EIO_ASSET::descriptor_0[45],
	&EIO_ASSET::descriptor_0[46],
	&EIO_ASSET::descriptor_0[47],
	&EIO_ASSET::descriptor_0[48],
	&EIO_ASSET::descriptor_0[49],
	&EIO_ASSET::descriptor_0[50],
	&EIO_ASSET::descriptor_0[51],
	&EIO_ASSET::descriptor_0[52],
	&EIO_ASSET::descriptor_0[53],
	&EIO_ASSET::descriptor_0[54],
	&EIO_ASSET::descriptor_0[55],
	&EIO_ASSET::descriptor_0[56],
	&EIO_ASSET::descriptor_0[57],
	&EIO_ASSET::descriptor_0[58],
	&EIO_ASSET::descriptor_0[59],
	&EIO_ASSET::descriptor_0[60],
	&EIO_ASSET::descriptor_0[61],
	&EIO_ASSET::descriptor_0[62],
	&EIO_ASSET::descriptor_0[63],
	&EIO_ASSET::descriptor_0[64],
	&EIO_ASSET::descriptor_0[65],
	&EIO_ASSET::descriptor_0[66],
	&EIO_ASSET::descriptor_0[67],
	&EIO_ASSET::descriptor_0[68],
	&EIO_ASSET::descriptor_0[69],
	&EIO_ASSET::descriptor_0[70],
	&EIO_ASSET::descriptor_0[71],
	&EIO_ASSET::descriptor_0[72],
	nullptr};
	const size_t EIO_ASSET::sDescriptorCount = 73;

//factory
EIO_ASSET* EIO_ASSET::makeThis(int isSubmodel, ModelClass* owner, EIO_ASSET* peer, 
						int mainRebase, const xstring &name, EIO_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EIO_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EIO_ASSET");
#endif
	EIO_ASSET* newP = (EIO_ASSET*)new EIO_ASSET_UDF
   	  ("eio_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
EIO_ASSET_persistent_object* EIO_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, EIO_ASSET* peer, 
							int mainRebase, const xstring &name, EIO_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("EIO_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor EIO_ASSET_persistent_object");
#endif
	EIO_ASSET_persistent_object* newP = (EIO_ASSET_persistent_object*)new EIO_ASSET_persistent_object
   	  ("eio_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			EIO_ASSET_persistent_object* pd = dynamic_cast<EIO_ASSET_persistent_object*>(product);
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

typedef double (EIO_ASSET_UDF::*dPF) ();
typedef double (EIO_ASSET_UDF::*dPFd) (double);
typedef int (EIO_ASSET_UDF::*iPF) ();
typedef int (EIO_ASSET_UDF::*iPFi) (int);
typedef xstring (EIO_ASSET_UDF::*sPF) ();
typedef xstring (EIO_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
EIO_ASSET::EIO_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, eio(company_asset_eio)
	, epl(company_liab_epl)
	, mtg_ym(company_asset_mtg_mtg_cf_mtg_ym)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EIO_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
EIO_ASSET::EIO_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(156, EIO_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, asset(company_asset)
	, eio(company_asset_eio)
	, epl(company_liab_epl)
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
#ifdef __CREATE_EIO_ASSET_CLASS_
       company_asset_eio = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_mtg_ym = 0;
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

	for (int cf_no = 1; cf_no <= 156; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (EIO_ASSET_UDF::*dPXi2) (int, int);
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


 void EIO_ASSET::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_EIO_ASSET_CLASS_
		company_asset_eio = (EIO_ASSET*)(findUnique("company|asset|eio"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_mtg_ym = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf|mtg_ym"));
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


 void EIO_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int EIO_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& EIO_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double EIO_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int EIO_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double EIO_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double EIO_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void EIO_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EIO_ASSET_persistent_object::write(long include_submodels) {
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

	void EIO_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EIO_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void EIO_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	EIO_ASSET_persistent_object::~EIO_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool EIO_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void EIO_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void EIO_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void EIO_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EIO_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void EIO_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* EIO_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* EIO_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* EIO_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char EIO_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void EIO_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
EIO_ASSET_persistent_object::EIO_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			EIO_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(EIO_ASSET::sm_bond_is)
	, sm_bond_pv(EIO_ASSET::sm_bond_pv)
	, sm_bond_ym(EIO_ASSET::sm_bond_ym)
	, sm_mtg_is(EIO_ASSET::sm_mtg_is)
	, sm_mtg_pv(EIO_ASSET::sm_mtg_pv)
	, sm_mtg_ym(EIO_ASSET::sm_mtg_ym)

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
EIO_ASSET::~EIO_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void EIO_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void EIO_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void EIO_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void EIO_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void EIO_ASSET::start_of_projection() {
}
//start_of_projection END@2

void EIO_ASSET::end_of_projection() {
}
//end_of_projection END@2

void EIO_ASSET::start_of_layer() {
}


void EIO_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void EIO_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void EIO_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void EIO_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> EIO_ASSET::ddfVector;
BitArray EIO_ASSET::dataVariables(73);
bool EIO_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool EIO_ASSET::writeClassInfo = true;

void EIO_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, EIO_ASSET::descriptor_0>::dT = EIO_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, EIO_ASSET::descriptor_0>::dT = EIO_ASSET::descriptor_0;

